#include "h_MultiScaleManager.h"
#include "h_MultiScale.h"
#include "../../Empire.h"
#include "../../MapNode.h"
#include "../../Unit.h"

#ifdef GOAPAlgorithm
#include "../../GOAP/GOAPAgentState.h"
#endif // GOAPAlgorithm

Hierarchical::h_MultiScaleManager::h_MultiScaleManager(h_MultiScale* a_algorithm)
{
	m_Algorithm = a_algorithm;
}

Hierarchical::h_MultiScaleManager::~h_MultiScaleManager()
{
	m_Algorithm = nullptr;
}

bool Hierarchical::h_MultiScaleManager::ExecuteTask()
{
	return true;
}

Hierarchical::h_CombatManager::h_CombatManager(h_MultiScale* a_algorithm) : h_MultiScaleManager(a_algorithm)
{
	
}

bool Hierarchical::h_CombatManager::ExecuteTask()
{
	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		switch (iter)
		{
		case 0:
			returning = MoveFleet();
			break;
		case 2:
			returning = Attack();
			break;
		case 3:
			returning = AddTroops();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool Hierarchical::h_CombatManager::MoveFleet()
{
	return true;
}

bool Hierarchical::h_CombatManager::Attack()
{
	return true;
}

bool Hierarchical::h_CombatManager::AddTroops()
{
	return true;
}

Hierarchical::h_ExpansionManager::h_ExpansionManager(h_MultiScale* a_algorithm) : h_MultiScaleManager(a_algorithm)
{
}

bool Hierarchical::h_ExpansionManager::ExecuteTask()
{
	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		switch (iter)
		{
		case 0:
			returning = BuildCity();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool Hierarchical::h_ExpansionManager::BuildCity()
{
	return true;
}

Hierarchical::h_ResearchManager::h_ResearchManager(h_MultiScale* a_algorithm) : h_MultiScaleManager(a_algorithm)
{
	
}

bool Hierarchical::h_ResearchManager::ExecuteTask()
{
	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		switch (iter)
		{
		case 0:
			returning = SelectResearchFocus();
			break;
		case 1:
			returning = Research();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool Hierarchical::h_ResearchManager::SelectResearchFocus()
{
	return true;
}

bool Hierarchical::h_ResearchManager::Research()
{
	return true;
}

Hierarchical::h_ResourceManager::h_ResourceManager(h_MultiScale* a_algorithm) : h_MultiScaleManager(a_algorithm)
{
}

bool Hierarchical::h_ResourceManager::ExecuteTask()
{
	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		switch (iter)
		{
		case 0:
			returning = BuildBuilding();
			break;
		case 1:
			returning = HaltExpenditures();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool Hierarchical::h_ResourceManager::BuildBuilding()
{
	return true;
}

bool Hierarchical::h_ResourceManager::HaltExpenditures()
{
	return true;
}
