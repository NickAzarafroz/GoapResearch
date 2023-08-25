#include "pch.h"
#include "Action.h"
#include "Avatar.h"

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