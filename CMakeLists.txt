cmake_minimum_required(VERSION 3.5)

project(MyProject)

set(CMAKE_CXX_STANDARD 23)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")

find_package(SFML 2.5.1 COMPONENTS audio graphics window REQUIRED)
find_package(Boost 1.79 COMPONENTS json unit_test_framework PATHS ${CMAKE_SOURCE_DIR}/libs/ REQUIRED)

# Add library include directory
include_directories(${SFML_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Find all cpp files
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp") # Find all game source files
list(FILTER SRC_FILES EXCLUDE REGEX ".*/main.cpp") # Exclude main.cpp from list

file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp") # Find all test source files

add_executable(island-game ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${SRC_FILES}) # Define island-game executable
add_executable(test ${SRC_FILES} ${TEST_FILES}) # Define test executable

# Link the library to the target
## SFML
target_link_libraries(island-game sfml-graphics sfml-window)
target_link_libraries(test sfml-graphics sfml-window)
## Boost
target_link_libraries(island-game ${Boost_LIBRARIES})
target_link_libraries(test ${Boost_LIBRARIES})
