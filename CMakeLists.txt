#
# CMakeLists.txt
# ~~~~~~~~~~~~~~~~~~~
#
# Copyright (C) 2025 Artyom Kolpakov <ddvamp007@gmail.com>
#
# Licensed under GNU GPL-3.0-or-later.
# See file LICENSE or <https://www.gnu.org/licenses/> for details.
#

cmake_minimum_required(VERSION 4.1)

project(
  util
  VERSION 0.1.0
  DESCRIPTION "Library of common utilities"
  HOMEPAGE_URL "https://github.com/ddvamp/util.git"
  LANGUAGES CXX
)

set(
  util_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/src/abort.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/assert.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/assume.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/page_allocation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unreachable.cpp
)

add_library(util STATIC)
target_sources(util PRIVATE ${util_sources})

target_include_directories(
  util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  util PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(util PUBLIC cxx_std_23)
