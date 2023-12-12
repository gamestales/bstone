/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#include "bstone_exception.h"
#include "bstone_sys_system_mgr.h"

namespace bstone {
namespace sys {

AudioMgr& SystemMgr::get_audio_mgr()
try {
	return do_get_audio_mgr();
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

EventMgr& SystemMgr::get_event_mgr()
try {
	return do_get_event_mgr();
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

VideoMgr& SystemMgr::get_video_mgr()
try {
	return do_get_video_mgr();
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

} // namespace sys
} // namespace bstone
