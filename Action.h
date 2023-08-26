#pragma once
#include <vector>

class Avatar;
class Resource;
class Action
{
public:
	Action(const std::string name, int cost);
	~Action();

	Action(const Action& other) = delete;
	Action& operator=(const Action& rhs) = delete;
	Action(Action&& other) = delete;
	Action& operator=(Action&& rhs) = delete;

	void AddPrecondition(const std::string& precondition, bool value);
	void AddEffect(const std::string& effect, bool value);

	void ExecuteAction(Avatar* pAvatar, std::vector<Resource*>& pResources, float elapsedSec);

	bool IsCompleted();

	const std::string& GetName() const;
	const std::vector<std::pair<std::string, bool>>& GetPreconditions() const;
	const std::vector<std::pair<std::string, bool>>& GetEffects() const;
	int GetCost() const;

private:
	std::string m_Name;
	std::vector<std::pair<std::string, bool>> m_Preconditions;
	std::vector<std::pair<std::string, bool>> m_Effects;
	int m_Cost;

	bool m_ExecutionFinished{};
};

