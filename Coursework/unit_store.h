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
#include "field_store.h"
#include "field.h"
#include <memory>

class UnitStore final : public flux_cpp::Store {
public:
    UnitStore() = default;

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

    const Unit getSelectedAffectedUnit() const {
        auto unit = getSelectedUnit();
        auto field = FieldStore::instance()->getField();
        auto newUnit = field->getLands()[field->getWidth() * unit->pos.y + unit->pos.x]->affectUnit(unit);
        return Unit(&newUnit);
    }

    const Unit* getSelectedUnit() const {
        return units[_unitSelectionIndex % units.size()];
    }
    
private:
    UnitFactory* unitFactory = new FarmerFactory;
    std::vector<Unit*> units;
    bool _unitSelectionActive = false;
    int _unitSelectionIndex = 0;
    bool _unitMovementActive = false;
    Position unitMovementPosition;

};