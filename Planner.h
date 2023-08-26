#pragma once
#include <vector>

class Avatar;
class Action;
class Goal;
class Planner
{
public:
	Planner() = default;
	~Planner() = default;

	Planner(const Planner& other) = delete;
	Planner& operator=(const Planner& rhs) = delete;
	Planner(Planner&& other) = delete;
	Planner& operator=(Planner&& rhs) = delete;

	std::vector<Action*> Plan(Avatar* pAvatar, const Goal* pGoal);

private:
	std::vector<Action*> m_Plan{};
	std::vector<Action*> m_Plan2{};
};

