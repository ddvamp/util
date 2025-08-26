cmake_minimum_required(VERSION 4.1)

project(
  util
  VERSION 0.1.0
  DESCRIPTION "Library of common utilities"
  HOMEPAGE_URL "https://github.com/ddvamp/util.git"
  LANGUAGES CXX
)

set(name ${PROJECT_NAME})
set(dir ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE sources ${dir}/src/*.cpp)
if(NOT sources)
  message(FATAL_ERROR "Incorrect GLOB search pattern for sources!")
endif()

add_library(${name} STATIC)
target_sources(${name} PRIVATE ${sources})

target_include_directories(
  ${name} PUBLIC ${dir}/include
  ${name} PRIVATE ${dir}/src
)

target_compile_features(${name} PUBLIC cxx_std_23)
