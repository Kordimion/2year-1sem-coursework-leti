#pragma once

#include "flux_cpp.h"
#include "action_types.h"
#include "field.h"

#include <vector>

class FieldStore final : public flux_cpp::Store {
public:
	static FieldStore* instance() {
		static FieldStore* self = new FieldStore();
		return self;
	}

	const Field const *  getField() const {
		return _field;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;
private:
	Field* _field = nullptr;
};