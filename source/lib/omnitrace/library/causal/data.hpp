// MIT License
//
// Copyright (c) 2022 Advanced Micro Devices, Inc. All Rights Reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "library/binary/analysis.hpp"
#include "library/binary/fwd.hpp"
#include "library/causal/fwd.hpp"
#include "library/containers/c_array.hpp"
#include "library/containers/static_vector.hpp"
#include "library/defines.hpp"
#include "library/thread_data.hpp"
#include "library/utility.hpp"

#include <timemory/hash/types.hpp>
#include <timemory/tpls/cereal/cereal/cereal.hpp>
#include <timemory/utility/procfs/maps.hpp>
#include <timemory/utility/unwind.hpp>

#include <deque>
#include <dlfcn.h>
#include <map>

namespace omnitrace
{
namespace causal
{
void
save_line_info(const settings::compose_filename_config&, int _verbose);

std::deque<binary::symbol>
get_line_info(uintptr_t _addr, bool include_discarded = true);

bool is_eligible_address(uintptr_t);

void set_current_selection(unwind_addr_t);

selected_entry
sample_selection(size_t _nitr = 1000, size_t _wait_ns = 10000);

void push_progress_point(std::string_view);

void pop_progress_point(std::string_view);

void
mark_progress_point(std::string_view, bool force = false);

uint16_t
sample_virtual_speedup();

void
start_experimenting();

void
finish_experimenting();
}  // namespace causal
}  // namespace omnitrace