#include "h_MultiScale.h"


Hierarchical::h_MultiScale::h_MultiScale()
{
	m_planner = new h_MultiScalePlanner();
	m_planner->Init(a_ActionSet);

	m_managers.emplace(h_ManagerType::eMT_Combat, new h_CombatManager(this));
	m_managers.emplace(h_ManagerType::eMT_Expansion, new h_ExpansionManager(this));
	m_managers.emplace(h_ManagerType::eMT_Research, new h_ResearchManager(this));
	m_managers.emplace(h_ManagerType::eMT_Resources, new h_ResourceManager(this));

}

bool Hierarchical::h_MultiScale::CreatePlan()
{
	auto returning = false;

	if (HighLevelPlan(/* Current State */)) // First you output the high level planner.
	{
		for (int i = 0; i < m_managers.size(); i++)
		{
			returning = ManagerPlan(/* Current State,  */i);
		}
	}

	// That will get the output of the plan in the planner, which you can the delegate in the correct funtion.

	return returning;
}

bool Hierarchical::h_MultiScale::HighLevelPlan()
{
	return m_planner->Plan(/* Current State */);
}

bool Hierarchical::h_MultiScale::ManagerPlan(int a_managerID)
{
	return m_planner->PlanManager(/* Current State, */ a_managerID);
}

bool Hierarchical::h_MultiScale::DelegateTasks()
{
	bool returning = false;

	// You obtain the plan from the planner->GetPlan(), that is then sent to each manager according to their task.
	
	// Then the following part can be used to execute the tasks.
	// Since the associated research was on a turn-based game, there was no need to complicate the execution.

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


