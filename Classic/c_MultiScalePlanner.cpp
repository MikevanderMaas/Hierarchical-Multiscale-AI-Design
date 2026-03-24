#include "c_MultiScalePlanner.h"

CLASSIC::c_MultiScalePlanner::c_MultiScalePlanner()
{

	// Define and connect your planning algorithm here.
	
}

void CLASSIC::c_MultiScalePlanner::Init()
{

	// Initiate the planning algorithm, the actions and goals, here.

}

bool CLASSIC::c_MultiScalePlanner::Plan(/* Current State */)
{
    bool returning = true;

	// Insert the call to the planner here, 
	// For example:

	// m_plan = GOAPPlanner.Plan(state, goal, actionset);

	return returning;
}

void CLASSIC::c_MultiScalePlanner::UpdateGoals(/* Current State */)
{
	// Update the goal scoring here.
}

const int CLASSIC::c_MultiScalePlanner::getGoal(/* Current State */)
{
	int goalIDX = 0;

	// Return the index of the goal, to have something to properly assign priority in the DelegateTask function.

	return goalIDX;
}
