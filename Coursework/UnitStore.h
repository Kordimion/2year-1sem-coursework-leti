#pragma once

#include "flux_cpp.h"
#include "ActionTypes.h"
#include <vector>
#include "Unit.h"
#include "ArcherFactory.h"
#include "FarmerFactory.h"
#include "MinerFactory.h"
#include "SlingerFactory.h"
#include "SpearmanFactory.h"
#include "SwordsmanFactory.h"
#include "UnitType.h"

class UnitStore final : public flux_cpp::Store {
private:
	
	UnitStore() = default;
	UnitFactory* sko_unit;
public:
	std::vector<Unit*> units;
	static UnitStore* instance() {

		static UnitStore* self = new UnitStore();
		return self;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;

	const std::vector<Unit*>& getUnits() const { return units; }
};