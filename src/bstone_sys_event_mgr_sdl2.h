/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2024 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#ifndef BSTONE_SYS_EVENT_MGR_SDL2_INCLUDED
#define BSTONE_SYS_EVENT_MGR_SDL2_INCLUDED

#include "bstone_sys_event_mgr.h"
#include "bstone_sys_logger.h"

namespace bstone {
namespace sys {

EventMgrUPtr make_sdl2_event_mgr(Logger& logger);

} // namespace sys
} // namespace bstone

#endif // BSTONE_SYS_EVENT_MGR_SDL2_INCLUDED
