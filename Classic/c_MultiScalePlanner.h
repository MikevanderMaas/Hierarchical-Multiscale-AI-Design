#pragma once

#include <vector>

namespace CLASSIC {

	class c_MultiScalePlanner
	{
	public:
		c_MultiScalePlanner();

		void Init();

		bool Plan(/* Current State */);

		std::vector<int> GetPlan() { return m_plan; }

		void UpdateGoals(/* Current State */);

	private:
		const int getGoal(/* Current State */);

		std::vector<int> m_plan
	};

}
