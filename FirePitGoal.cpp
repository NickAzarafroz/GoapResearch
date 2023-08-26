#include "pch.h"
#include "FirePitGoal.h"
#include "Avatar.h"
#include "Action.h"

FirePitGoal::FirePitGoal(const std::string& name)
	: m_DesiredWorldState{ name, true }
{

}

bool FirePitGoal::IsGoalAchieved(Avatar* pAvatar)
{
	for(const auto& state : pAvatar->GetCurrentStates())
	{
		if(state == m_DesiredWorldState)
		{
			return true;
		}
	}

	return false;
}

const std::pair<std::string, bool>& FirePitGoal::GetDesiredWorldState() const
{
	return m_DesiredWorldState;
}
