#pragma once
#include "flux_cpp.h"

#define DISPATCH(action) (flux_cpp::Dispatcher::instance().dispatch(action))

#include "error_action_types.h"
#include "field_action_types.h"
#include "field_object_action_types.h"
#include "game_flow_action_types.h"
#include "unit_action_types.h"