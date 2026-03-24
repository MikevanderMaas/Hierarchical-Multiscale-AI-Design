#pragma once

#include <vector>

namespace Hierarchical
{
	class h_MultiScalePlanner
	{
	public:
		h_MultiScalePlanner();

		void Init();

		bool Plan(/* Current State */);
		bool PlanManager(/* Current State, */int managerID);

		std::vector<int> GetPlan() { return m_plan; }

		void UpdateGoals(/* Current State */);

	private:

		const int getGoal(/* Current State */);

		std::vector<int> m_plan;
		std::vector<int> m_planManager;

	};

}

