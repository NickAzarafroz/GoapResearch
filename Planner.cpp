#include "pch.h"
#include "Planner.h"
#include "Goal.h"
#include "Avatar.h"
#include "Action.h"
#include <iostream>

std::vector<Action*> Planner::Plan(Avatar* pAvatar, const Goal* pGoal)
{
	m_Plan.clear();
	m_Plan2.clear();

	std::cout << "Goal: " << pGoal->GetDesiredWorldState().first << ", " << std::boolalpha << pGoal->GetDesiredWorldState().second << '\n';
	std::cout << "Current State: " << pAvatar->GetCurrentStates()[0].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[0].second << ", " <<
		pAvatar->GetCurrentStates()[1].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[1].second << ", " << 
		pAvatar->GetCurrentStates()[2].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[2].second << ", " << 
		pAvatar->GetCurrentStates()[3].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[3].second <<'\n';

	bool satisfyingActionFound1{};

	while(pAvatar->GetCurrentStates()[0] != pGoal->GetDesiredWorldState())
	{
		satisfyingActionFound1 = false;

		for (const auto& action : pAvatar->GetAvailableActions())
		{
			std::cout << "Can action " << action->GetName() << " run?\n";

			if (action->GetPreconditions()[0] == pAvatar->GetCurrentStates()[0]
				&& action->GetPreconditions()[1] == pAvatar->GetCurrentStates()[1])
			{

				std::cout << "Yes\n";

				m_Plan.push_back(action);
				std::pair<std::string, bool> effect0 = action->GetEffects()[0];
				std::pair<std::string, bool> effect1 = action->GetEffects()[1];

				pAvatar->ModifyCurrentState(effect0, 0);
				pAvatar->ModifyCurrentState(effect1, 1);

				std::cout << "New State: " << pAvatar->GetCurrentStates()[0].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[0].second << ", " <<
					pAvatar->GetCurrentStates()[1].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[1].second << ", " <<
					pAvatar->GetCurrentStates()[2].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[2].second << ", " <<
					pAvatar->GetCurrentStates()[3].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[3].second << '\n';

				satisfyingActionFound1 = true;
				break;
			}
			else std::cout << "No\n";
		}

		if (!satisfyingActionFound1)
		{
			std::cout << "No satisfying action found. Exiting loop.\n";
			break;
		}
	}

	std::cout << "First Plan done! Another plan possible?\n";
	pAvatar->ResetStates();

	bool satisfyingActionFound{};

	while (pAvatar->GetCurrentStates()[2] != pGoal->GetDesiredWorldState())
	{
		satisfyingActionFound = false;

		for (const auto& action : pAvatar->GetAvailableActions())
		{
			std::cout << "Can action " << action->GetName() << " run?\n";

			if (action->GetPreconditions()[0] == pAvatar->GetCurrentStates()[2]
				&& action->GetPreconditions()[1] == pAvatar->GetCurrentStates()[3])
			{

				std::cout << "Yes\n";

				m_Plan2.push_back(action);
				std::pair<std::string, bool> effect0 = action->GetEffects()[0];
				std::pair<std::string, bool> effect1 = action->GetEffects()[1];

				pAvatar->ModifyCurrentState(effect0, 2);
				pAvatar->ModifyCurrentState(effect1, 3);

				std::cout << "New State: " << pAvatar->GetCurrentStates()[0].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[0].second << ", " <<
					pAvatar->GetCurrentStates()[1].first << ", " << std::boolalpha << pAvatar->GetCurrentStates()[1].second << '\n';

				satisfyingActionFound = true;
				break;
			}
			else std::cout << "No\n";
		}

		if (!satisfyingActionFound) 
		{
			std::cout << "No satisfying action found. Exiting loop.\n";
			break;
		}
		else
		{
			std::cout << "Second Plan done! Another plan possible?\n";
		}
	}

	pAvatar->ResetStates();

	if(!satisfyingActionFound)
	{
		return m_Plan;
	}

	if(!satisfyingActionFound1)
	{
		return m_Plan2;
	}

	int costPlan1{};
	int costPlan2{};

	for(const auto& action : m_Plan)
	{
		costPlan1 += action->GetCost();
	}
	
	for (const auto& action : m_Plan2)
	{
		costPlan2 += action->GetCost();
	}

	if (costPlan1 < costPlan2)
	{
		std::cout << "Execute Plan1! Its cheaper!\n";
		return m_Plan;
	}
	else 
	{
		std::cout << "Execute Plan2! Its cheaper!\n";
		return m_Plan2;
	} 
}