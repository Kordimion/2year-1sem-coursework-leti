#pragma once

#include "flux_cpp.h"
#include "action_types.h"
#include "field_object.h"

#include <vector>

class FieldObjectsStore final : public flux_cpp::Store {
public:
	static FieldObjectsStore* instance() {
		static FieldObjectsStore* self = new FieldObjectsStore();
		return self;
	}

	const std::vector<FieldObject*>& getFieldObjects() const {
		return _fieldObjects;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;
private:
	std::vector<FieldObject*> _fieldObjects = {};
};