#pragma once

#include <vector>

#include "flux_cpp.h"
#include "action_types.h"
#include "unit.h"
#include "archer_factory.h"
#include "farmer_factory.h"
#include "miner_factory.h"
#include "slinger_factory.h"
#include "spearman_factory.h"
#include "swordsman_factory.h"
#include "unit_type.h"
#include "player_store.h"

class UnitStore final : public flux_cpp::Store {
public:
	UnitStore(){
        delete unitFactory;
        unitFactory = new FarmerFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), {6,3}));

        delete unitFactory;
        unitFactory =new SwordsmanFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), { 1,1 }));

        delete unitFactory;
        unitFactory = new MinerFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), { 2,2 }));

        delete unitFactory;
        unitFactory = new ArcherFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), { 3,3 }));

        delete unitFactory;
        unitFactory = new SlingerFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), { 4,4 }));

        delete unitFactory;
        unitFactory = new SpearmanFactory;
        units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), { 5,5 }));
	}

	static UnitStore* instance() {

		static UnitStore* self = new UnitStore();
		return self;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;

    const std::vector<Unit*>& getUnits() const { 
        return units; 
    }
    
    const UnitFactory* getUnitFactory() const { 
        return unitFactory; 
    }

    bool isUnitSelectionActive() { 
        return _unitSelectionActive; 
    }
    
    bool isUnitMovementActive() { 
        return _unitMovementActive; 
    }

    const Unit* getSelectedUnit() const { 
        return units[_unitSelectionIndex]; 
    }
private:
    UnitFactory* unitFactory = new FarmerFactory;
    std::vector<Unit*> units;
    bool _unitSelectionActive = false;
    int _unitSelectionIndex = 0;
    bool _unitMovementActive = false;
    Position unitMovementPosition;

};