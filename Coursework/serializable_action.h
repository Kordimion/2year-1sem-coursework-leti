#pragma once
#include <type_traits>
#include "flux_cpp.h"

// Later there will be serialization logic, but it is needed for logging.
// Right now this name is meaningless, but later it will be useful
template<typename E>
using is_scoped_enum = std::integral_constant<bool, std::is_enum<E>::value && !std::is_convertible<E, int>::value>;
class SerializableAction : public flux_cpp::Action {
public:
	template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
	SerializableAction(ScopedEnum type) : flux_cpp::Action(type) {};

	template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
	SerializableAction(ScopedEnum type, std::any payload) : flux_cpp::Action(type, payload) {};

	virtual const std::string Serialize() const = 0;
};