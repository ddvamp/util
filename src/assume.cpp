// Copyright (C) 2023-2025 Artyom Kolpakov <ddvamp007@gmail.com>
//
// Licensed under GNU GPL-3.0-or-later.
// See file LICENSE or <https://www.gnu.org/licenses/> for details.

#include "util/debug/assume.hpp"

#include <cstdlib>
#include <format>
#include <iostream>

namespace util::detail {

void do_assume(::std::string_view const expr, ::std::string_view const msg,
               ::std::source_location const loc) noexcept {
  auto const output = ::std::format("Debug error! Assumption '{}' is wrong at "
                                    "{}:{}: {} with message '{}'. Abort!\n",
                                    expr, loc.file_name(), loc.line(),
                                    loc.function_name(), msg);
  ::std::cerr << output << ::std::flush;
  ::std::abort();
}

} // namespace util::detail
