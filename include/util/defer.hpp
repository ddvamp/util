//
// defer.hpp
// ~~~~~~~~~
//
// Copyright (C) 2023-2025 Artyom Kolpakov <ddvamp007@gmail.com>
//
// Licensed under GNU GPL-3.0-or-later.
// See file LICENSE or <https://www.gnu.org/licenses/> for details.
//

#ifndef DDVAMP_UTIL_DEFER_HPP_INCLUDED_
#define DDVAMP_UTIL_DEFER_HPP_INCLUDED_ 1

#include <util/macro.hpp>
#include <util/type_traits.hpp>

#include <utility>

namespace util {

template <typename T>
concept suitable_for_defer =
    ::std::is_object_v<T> && !is_qualified_v<T> &&
    ::std::is_nothrow_move_constructible_v<T> &&
    ::std::is_nothrow_destructible_v<T> &&
    ::std::is_invocable_v<T &&> &&
    ::std::is_void_v<::std::invoke_result_t<T &&>>;

// RAII class for performing an action at the end of a scope
template <suitable_for_defer T>
class [[nodiscard]] defer final {
 private:
  UTIL_NO_UNIQUE_ADDRESS T action_;

 public:
  constexpr ~defer() noexcept (::std::is_nothrow_invocable_v<T &&>) {
    ::std::move(action_)();
  }

  defer(defer const &) = delete;
  void operator= (defer const &) = delete;

  defer(defer &&) = delete;
  void operator= (defer &&) = delete;

 public:
  constexpr explicit defer(T action) noexcept : action_(::std::move(action)) {}
};

} // namespace util

#endif /* DDVAMP_UTIL_DEFER_HPP_INCLUDED_ */
