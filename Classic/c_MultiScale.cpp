#include "c_MultiScale.h"

CLASSIC::c_MultiScale::c_MultiScale()
{
	// Creating and initiating the planner
	m_planner = new c_MultiScalePlanner();
	m_planner->Init();

	// Creating and assigning the managers in this Multiscale design.
	m_managers.emplace(c_ManagerType::cMT_Combat, new c_CombatManager(this));
	m_managers.emplace(c_ManagerType::cMT_Expansion, new c_ExpansionManager(this));
	m_managers.emplace(c_ManagerType::cMT_Research, new c_ResearchManager(this));
	m_managers.emplace(c_ManagerType::cMT_Resources, new c_ResourceManager(this));

}

bool CLASSIC::c_MultiScale::CreatePlan()
{
	return m_planner->Plan();
}

bool CLASSIC::c_MultiScale::DelegateTasks()
{

	bool returning = true;

	std::vector<int> plan = m_planner->GetPlan();

	if (plan.empty()) // This should already be checked after the CreatePlan function, but is safety backup.
	{
		return returning;
	}

	// Here you can place the division of tasks based on the plan created.
	// An example can be seen below.

	for (size_t i = 0; i < plan.size(); i++)
	{
		switch (plan[i])
		{
		case 0: // This can be an attack action.
			m_managers.at(c_ManagerType::cMT_Combat)->AddToIndex(1);
			break;
		case 1: // This can be a moving action.
			m_managers.at(c_ManagerType::cMT_Combat)->AddToIndex(0);
			break;
		default: // And so on for each action.
			break;
		}
	}

	// The intial application of this example was for turn based gameplay.
	// Therefore, the below manner of executing the tasks in order of manager was sufficient.

	for (auto& iter : m_managers)
	{
		bool temp = iter.second->ExecuteTask();
		if (!temp)
		{
			returning = false; // This means that some of the tasks that have been planned have yet to finish.
		}
	}

	return returning;
}