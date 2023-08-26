#pragma once
#include "Goal.h"

class FirePitGoal : public Goal
{
public:
	FirePitGoal(const std::string& name);
	virtual ~FirePitGoal() = default;

	FirePitGoal(const FirePitGoal& other) = delete;
	FirePitGoal& operator=(const FirePitGoal& rhs) = delete;
	FirePitGoal(FirePitGoal&& other) = delete;
	FirePitGoal& operator=(FirePitGoal&& rhs) = delete;

	virtual bool IsGoalAchieved(Avatar* pAvatar) override;
	virtual const std::pair<std::string, bool>& GetDesiredWorldState() const override;

private:
	std::pair<std::string, bool> m_DesiredWorldState;
};

