#pragma once

#include <vector>

namespace Hierarchical {

	class h_MultiScale;

	enum class h_ManagerType
	{
		hMT_Combat,
		hMT_Expansion,
		hMT_Vision,
		hMT_Resources,
		hMT_Research
	};

	class h_MultiScaleManager
	{
	public:
		h_MultiScaleManager(h_MultiScale* a_algorithm);
		~h_MultiScaleManager();

		virtual bool ExecuteTask();

		void AddToIndex(int a_ActionIndexToAdd) { m_ActionIndex.push_back(a_ActionIndexToAdd); }

		void ClearIndex() { m_ActionIndex.clear(); }

		

	protected:
		std::vector<int> m_ActionIndex;

		h_MultiScale* m_Algorithm;
	};

	class h_CombatManager : public h_MultiScaleManager
	{
	public:
		h_CombatManager(h_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:
		bool MoveFleet();								// Action Index 0
		bool Attack();									// Action Index 1
		bool AddTroops();								// Action Index 2

	};

	class h_ExpansionManager : public h_MultiScaleManager
	{
	public:
		h_ExpansionManager(h_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:
		bool BuildCity();								// Action Index 0

	};

	class h_ResearchManager : public h_MultiScaleManager
	{
	public:
		h_ResearchManager(h_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:
		bool SelectResearchFocus();						// Action Index 0
		bool Research();								// Action Index 1

	};

	class h_ResourceManager : public h_MultiScaleManager
	{
	public:
		h_ResourceManager(h_MultiScale* a_algorithm);

		virtual bool ExecuteTask() override;

	private:
		bool BuildBuilding();							// Action Index 0
		bool HaltExpenditures();						// Action Index 1

	};

}
