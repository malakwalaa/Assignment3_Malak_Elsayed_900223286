# cmake_minimum_required(VERSION 3.24)
# project(Fall2025_assignment3)

# set(CMAKE_CXX_STANDARD 17)

# set(SOURCE_FILES main.cpp)
# add_executable(Code_library_run ${SOURCE_FILES})

# include_directories(Code_library)
# add_subdirectory(Code_library)

# target_link_libraries(Code_library_run Code_library)

# add_subdirectory(Google_tests)

cmake_minimum_required(VERSION 3.24)
project(Fall2025_assignment3)

#  Set BEFORE any add_subdirectory calls so all targets inherit it
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # ← hard-require it, don't silently downgrade
set(CMAKE_CXX_EXTENSIONS OFF)         # ← use -std=c++17 not -std=gnu++17

set(SOURCE_FILES main.cpp)
add_executable(Code_library_run ${SOURCE_FILES})
include_directories(Code_library)
add_subdirectory(Code_library)
target_link_libraries(Code_library_run Code_library)
add_subdirectory(Google_tests)         # ← now inherits C++17