#pragma once

#include "h_MultiScalePlanner.h"
#include "h_MultiScaleManager.h"

#include <map>

class Empire;
enum class OwningTeam;

namespace Hierarchical {
	class h_MultiScale
	{
	public:

		h_MultiScale();

		bool CreatePlan();
		bool HighLevelPlan();
		bool ManagerPlan(int a_managerID);

		bool DelegateTasks();

	private:

		std::map<h_ManagerType, h_MultiScaleManager*> m_managers;
		h_MultiScalePlanner* m_planner;
		/* Current State */
	};

}