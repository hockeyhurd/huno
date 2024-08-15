cmake_minimum_required(VERSION 3.16.2)
project(huno)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -fPIC -Wall -Wextra -Wcast-qual -Wfloat-equal -Wno-unused-parameter -pedantic -fstack-protector-strong -fstack-clash-protection")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG_BUILD")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

if (NOT CMAKE_BUILD_TYPE)
    message("-- CMAKE_BUILD_TYPE variable not set. Defaulting to \"Release\"")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

include_directories(include /opt/app/raylib/include)
link_directories(libs /opt/app/raylib/lib)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES src/Board.cpp src/Card.cpp src/Enums.cpp src/Game.cpp src/Main.cpp src/Mouse.cpp src/Player.cpp)
add_executable(huno ${SOURCE_FILES})
target_link_libraries(huno HCLib)
target_link_libraries(huno Threads::Threads)
target_link_libraries(huno raylib)

