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

	const FieldObject* getSelectedFieldObject() const {
		return _fieldObjects[_selectedFieldObjectIndex % _fieldObjects.size()];
	}

	const bool isFieldObjectSelectionActive() const {
		return _fieldObjectSelectionActive;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;
private:
	std::vector<FieldObject*> _fieldObjects = {};
	bool _fieldObjectSelectionActive = false;
	int _selectedFieldObjectIndex = 0;
};