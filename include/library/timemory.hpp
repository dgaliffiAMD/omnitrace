// Copyright (c) 2018 Advanced Micro Devices, Inc. All Rights Reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// with the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimers.
//
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimers in the
// documentation and/or other materials provided with the distribution.
//
// * Neither the names of Advanced Micro Devices, Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this Software without specific prior written permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH
// THE SOFTWARE.

#pragma once

#include <timemory/api.hpp>
#include <timemory/backends/mpi.hpp>
#include <timemory/backends/process.hpp>
#include <timemory/backends/threading.hpp>
#include <timemory/components.hpp>
#include <timemory/components/gotcha/mpip.hpp>
#include <timemory/components/papi/papi_tuple.hpp>
#include <timemory/config.hpp>
#include <timemory/environment.hpp>
#include <timemory/manager.hpp>
#include <timemory/mpl/apply.hpp>
#include <timemory/operations.hpp>
#include <timemory/runtime.hpp>
#include <timemory/settings.hpp>
#include <timemory/storage.hpp>
#include <timemory/variadic.hpp>

namespace audit     = tim::audit;
namespace comp      = tim::component;
namespace quirk     = tim::quirk;
namespace threading = tim::threading;
namespace scope     = tim::scope;
namespace dmp       = tim::dmp;
namespace process   = tim::process;
namespace units     = tim::units;
namespace trait     = tim::trait;

// same sort of functionality as python's " ".join([...])
#if !defined(JOIN)
#    define JOIN(...) tim::mpl::apply<std::string>::join(__VA_ARGS__)
#endif

using papi_tot_ins = comp::papi_tuple<PAPI_TOT_INS>;
