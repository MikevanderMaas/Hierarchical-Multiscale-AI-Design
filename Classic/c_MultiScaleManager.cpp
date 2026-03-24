#include "c_MultiScaleManager.h"
#include "c_MultiScale.h"

CLASSIC::c_MultiScaleManager::c_MultiScaleManager(CLASSIC::c_MultiScale* a_Algorithm)
{
	m_Algorithm = a_Algorithm;
}

CLASSIC::c_MultiScaleManager::~c_MultiScaleManager()
{
	m_Algorithm = nullptr;
}

bool CLASSIC::c_MultiScaleManager::ExecuteTask()
{
	return true;
}

CLASSIC::c_CombatManager::c_CombatManager(c_MultiScale* a_algorithm) : c_MultiScaleManager(a_algorithm)
{

}

bool CLASSIC::c_CombatManager::ExecuteTask()
{
	// Each manager runs trought the actions stored.

	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		if (!returning)
		{
			break;
		}
		switch (iter)
		{
		case 0:
			returning = MoveFleet();
			break;
		case 1:
			returning = Attack();
			break;
		case 2:
			returning = AddTroops();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool CLASSIC::c_CombatManager::MoveFleet()
{
	// In each action you implement the connection between the Multiscale design and the gameplay elements.

	return true;
}

bool CLASSIC::c_CombatManager::Attack()
{
	return true;
}

bool CLASSIC::c_CombatManager::AddTroops()
{
	return true;
}

CLASSIC::c_ExpansionManager::c_ExpansionManager(c_MultiScale* a_algorithm) : c_MultiScaleManager(a_algorithm)
{
}

bool CLASSIC::c_ExpansionManager::ExecuteTask()
{
	bool returning = true;
	for (const auto iter : m_ActionIndex)
	{
		switch (iter)
		{
		case 0:
			returning = BuildCity();
			break;
		case 1:
			returning = BuildScoutTower();
			break;
		default:
			break;
		}
	}
	return returning;
}

bool CLASSIC::c_ExpansionManager::BuildCity()
{
	return true;
}

bool CLASSIC::c_ExpansionManager::BuildScoutTower()
{
	return true;
}

CLASSIC::c_ResearchManager::c_ResearchManager(c_MultiScale* a_algorithm) : c_MultiScaleManager(a_algorithm)
{
}

bool CLASSIC::c_ResearchManager::ExecuteTask()
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

bool CLASSIC::c_ResearchManager::SelectResearchFocus()
{
	return true;
}

bool CLASSIC::c_ResearchManager::Research()
{
	return true;
}

CLASSIC::c_ResourceManager::c_ResourceManager(c_MultiScale* a_algorithm) : c_MultiScaleManager(a_algorithm)
{
}

bool CLASSIC::c_ResourceManager::ExecuteTask()
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

bool CLASSIC::c_ResourceManager::BuildBuilding()
{
	return true;
}

bool CLASSIC::c_ResourceManager::HaltExpenditures()
{
	return true;
}
