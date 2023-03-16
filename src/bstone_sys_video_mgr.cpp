/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#include "bstone_exception.h"
#include "bstone_sys_video_mgr.h"

namespace bstone {
namespace sys {

MouseMgrUPtr VideoMgr::make_mouse_mgr()
try
{
	return do_make_mouse_mgr();
}
BSTONE_FUNC_STATIC_THROW_NESTED

} // namespace sys
} // namespace bstone