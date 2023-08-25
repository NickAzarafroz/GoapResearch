#pragma once
#include <string>

class Avatar;
class Goal
{
public:
	Goal() = default;
	virtual ~Goal() = default;

	Goal(const Goal& other) = delete;
	Goal& operator=(const Goal& rhs) = delete;
	Goal(Goal&& other) = delete;
	Goal& operator=(Goal&& rhs) = delete;

	virtual bool IsGoalAchieved(Avatar* pAvatar) = 0;
	virtual const std::pair<std::string, bool>& GetDesiredWorldState() const = 0;
};

