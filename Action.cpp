#include "pch.h"
#include "Action.h"
#include "Avatar.h"
#include "Vector2f.h"
#include "Resource.h"
#include "utils.h"

Action::Action(const std::string name, int cost) 
	: m_Name{name}, m_Cost{cost}
{

}

Action::~Action()
{

}

void Action::AddPrecondition(const std::string& precondition, bool value)
{
	m_Preconditions.emplace_back(precondition, value);
}

void Action::AddEffect(const std::string& effect, bool value)
{
	m_Effects.emplace_back(effect, value);
}

void Action::ExecuteAction(Avatar* pAvatar, std::vector<Resource*>& pResources, float elapsedSec)
{
	Resource* closestResource{};
	float shortestLength{ std::numeric_limits<float>::max() };

	for (const auto& resource : pResources)
	{
		float length = (Vector2f{ resource->GetShape().left, resource->GetShape().bottom } - pAvatar->GetPosition()).SquaredLength();

		if (length < shortestLength)
		{
			shortestLength = length;
			closestResource = resource;
		}
	}

	if (!utils::IsOverlapping(pAvatar->GetShape(), closestResource->GetShape()))
	{
		Vector2f direction = (Vector2f{ closestResource->GetShape().left, closestResource->GetShape().bottom } - pAvatar->GetPosition()).Normalized();

		pAvatar->SetPosition(pAvatar->GetPosition() + direction * 100.f * elapsedSec);

		m_ExecutionFinished = false;
	}
	else
	{
		m_ExecutionFinished = true;

		if (m_Name == "BuildFirePit")
		{
			closestResource->PutIntoGame();
		}
		else
		{
			auto it = std::find(pResources.begin(), pResources.end(), closestResource);
			if (it != pResources.end())
			{
				delete* it;
				pResources.erase(it);
			}
		}
	}
}

const std::string& Action::GetName() const
{
	return m_Name;
}

const std::vector<std::pair<std::string, bool>>& Action::GetPreconditions() const
{
	return m_Preconditions;
}

const std::vector<std::pair<std::string, bool>>& Action::GetEffects() const
{
	return m_Effects;
}

int Action::GetCost() const
{
	return m_Cost;
}

bool Action::IsCompleted()
{
	return m_ExecutionFinished;
}