#pragma once

#include "c_MultiScaleManager.h"
#include "c_MultiScalePlanner.h"

#include <map>

namespace CLASSIC {

	class c_MultiScale
	{
	public:

		c_MultiScale();

		bool CreatePlan();
		bool DelegateTasks();

	private:

		std::map<c_ManagerType, c_MultiScaleManager*> m_managers;
		c_MultiScalePlanner* m_planner;
		/* Current State */

	};

}