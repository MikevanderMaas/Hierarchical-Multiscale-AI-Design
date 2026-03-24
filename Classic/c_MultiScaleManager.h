#pragma once

#include <vector>

namespace CLASSIC {

	class c_MultiScale;

	enum class c_ManagerType
	{
		cMT_Combat,
		cMT_Expansion,
		cMT_Resources,
		cMT_Research
	};

	class c_MultiScaleManager
	{
	public:
		c_MultiScaleManager(c_MultiScale* a_algorithm);
		~c_MultiScaleManager();

		virtual bool ExecuteTask();

		void AddToIndex(int a_ActionIndexToAdd) { m_ActionIndex.push_back(a_ActionIndexToAdd); }

		void ClearIndex() { m_ActionIndex.clear(); }

	protected:

		std::vector<int> m_ActionIndex;

		c_MultiScale* m_Algorithm;
	};

	// Below are examples of managers used.
	// Each manager has some actions assigned to it currently.
	// They connect each specific action to it's gameplay counterparts.

	class c_CombatManager : public c_MultiScaleManager
	{
	public:
		c_CombatManager(c_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:

		bool MoveFleet();								// Action Index 0
		bool Attack();									// Action Index 1
		bool AddTroops();								// Action Index 2

	};

	class c_ExpansionManager : public c_MultiScaleManager
	{
	public:
		c_ExpansionManager(c_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:

		bool BuildCity();								// Action Index 0
		bool BuildScoutTower();							// Action Index 1

	};

	class c_ResearchManager : public c_MultiScaleManager
	{
	public:
		c_ResearchManager(c_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:

		bool SelectResearchFocus();						// Action Index 0
		bool Research();								// Action Index 1


	};

	class c_ResourceManager : public c_MultiScaleManager
	{
	public:
		c_ResourceManager(c_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:

		bool BuildBuilding();							// Action Index 0
		bool HaltExpenditures();						// Action Index 1

	};

}
