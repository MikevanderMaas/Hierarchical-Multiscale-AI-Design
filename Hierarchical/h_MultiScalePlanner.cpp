#include "h_MultiScalePlanner.h"

Hierarchical::h_MultiScalePlanner::h_MultiScalePlanner()
{
	// Assign and Connect the planning algorithm here.
}

void Hierarchical::h_MultiScalePlanner::Init()
{
	// Initiate the planning algorithm, the actions and goals, here.
}

ool Hierarchical::h_MultiScalePlanner::Plan(/* Current State */)
{
	bool returning = true;

	// Make the reference to the planner here, asking it to plan with the high-level planner action subset.

	if (m_plan.empty())
	{
		returning = false;
	}

	return returning;
}

bool Hierarchical::h_MultiScalePlanner::PlanManager(/* Current State, */ int a_managerID)
{
	bool returning = true;

	// First we need to figure out the goal for each manager, which is something that is done based on what is currently placed in m_plan.

	switch (a_managerID) // For each case, plan with the subset of that specifc manager.
	{
	case 0: 
		// tempPlan = m_planner.Plan(/* Current State */, /* Combat Manager Action Subset */, /* Goal */)
		break;
	case 1:
		// tempPlan = m_planner.Plan(/* Current State */, /* Expansion Manager Action Subset */, /* Goal */)
		break;
	case 2:
		// tempPlan = m_planner.Plan(/* Current State */, /* Research Manager Action Subset */, /* Goal */)
		break;
	case 3:
		// tempPlan = m_planner.Plan(/* Current State */, /* Resource Manager Action Subset */, /* Goal */)
		break;
	default:
		break;
	}

	// After that is all done, you can order it based on the priority of the actions in m_plan.
	// And before leaving this function you can then add to m_planManager with the finalized plan for each manager.

	if (m_planManager.empty())
	{
		returning = false;
	}

	return returning;

}

void Hierarchical::h_MultiScalePlanner::UpdateGoals(/* Current State */)
{
	// Update the scoring of the goals based on the current state.
}

const int Hierarchical::h_MultiScalePlanner::getGoal(/* Current State */)
{
	int goalIDX = 0;

	// Return the index of the goal, to have something to properly assign priority in the DelegateTask function.

	return goalIDX;
}

