# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RomanNumerals")

# Include sub-projects.

# Add source to this project's executable.
add_library(RomanNumeralsLib STATIC "RomanNumerals/RomanNumerals.cpp" "RomanNumerals/RomanNumerals.h")

target_include_directories(RomanNumeralsLib INTERFACE ${PROJECT_SOURCE_DIR}/RomanNumerals)

add_executable (RomanNumerals "RomanNumerals/main.cpp")

target_link_libraries(RomanNumerals RomanNumeralsLib )

add_executable(tests "tests/tests.cpp" "tests/catch_amalgamated.cpp")

target_link_libraries(tests PUBLIC RomanNumeralsLib )

add_subdirectory ("RomanNumerals")

add_subdirectory("tests")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RomanNumerals PROPERTY CXX_STANDARD 20)
endif()




#Include(FetchContent)
#
#FetchContent_Declare(
#  Catch2
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG        v3.8.1 # or a later release
#)

#FetchContent_MakeAvailable(Catch2)

#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
#include(CTest)
#include(Catch)
#catch_discover_tests(tests)


