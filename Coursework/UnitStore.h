#pragma once

#include "flux_cpp.h"
#include "ActionTypes.h"
#include <vector>
#include "Unit.h"
#include "Farmer.h"
#include "Swordsman.h"
#include "Miner.h"
#include "Spearman.h"
#include "Archer.h"
#include "Slinger.h"

class UnitStore final : public flux_cpp::Store {
private:
	std::vector<Unit*> units;
	UnitStore() {
		Farmer* f = new Farmer();
		f->pos.x = 3;
		f->pos.y = 6;

		Swordsman* s = new Swordsman();
		s->pos.x = 1;
		s->pos.y = 1;

		Miner* a = new Miner();
		a->pos.x = 2;
		a->pos.y = 2;

		Archer* b = new Archer();
		b->pos.x = 3;
		b->pos.y = 3;

		Slinger* c = new Slinger();
		c->pos.x = 4;
		c->pos.y = 4;

		Spearman* d = new Spearman();
		d->pos.x = 5;
		d->pos.y = 5;

		units.push_back(f);
		units.push_back(s);
		units.push_back(a);
		units.push_back(b);
		units.push_back(c);
		units.push_back(d);
	}

public:
	static UnitStore* instance() {

		static UnitStore* self = new UnitStore();
		return self;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;

	const std::vector<Unit*>& getUnits() const { return units; }
};