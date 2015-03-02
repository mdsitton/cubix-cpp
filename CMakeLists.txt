cmake_minimum_required(VERSION 3.0)
project(cubix)

# Get git information from the .git folder
# we do this because not every system has git in the path.

#string(CONCAT GIT_FOLDER_PATH $CMAKE_SOURCE_DIR "")
#set(GIT_FOLDER_PATH "")

#set(CUBIX_VERSION "")


set(PLATFORM_WINDOWS 0)
set(PLATFORM_LINUX 0)
set(PLATFORM_OSX 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Building for Windows.")
    set(ENV{SDL2DIR} "${PROJECT_SOURCE_DIR}/extern/sdl2")
    set(PLATFORM_WINDOWS 1)

elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Building for Linux.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    set(PLATFORM_LINUX 1)

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Building for Mac OS X.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
    set(PLATFORM_OSX 1)

endif()


find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Freetype REQUIRED)
find_package(GLM REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${FREETYPE_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})

configure_file (
  "${PROJECT_SOURCE_DIR}/src/core/config.hpp.in"
  "${PROJECT_SOURCE_DIR}/src/core/config.hpp"
)

set(CORE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/context.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/keycode.hpp)

set(CORE_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/context.cpp)
source_group("src\\core" FILES ${CORE_SOURCE} ${CORE_HEADERS})

set(GAME_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/game/main.cpp)
source_group("src\\game" FILES ${GAME_SOURCE})

set( SOURCE ${CORE_HEADERS} ${CORE_SOURCE} ${GAME_SOURCE})

include_directories(${PROJECT_SOURCE_DIR}/src/core)
include_directories(${PROJECT_SOURCE_DIR}/src/engine)
include_directories(${PROJECT_SOURCE_DIR}/src/game)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(cubix ${SOURCE})

target_link_libraries(cubix ${SDL2_LIBRARY} ${FREETYPE_LIBRARIES} ${GLEW_LIBRARIES})
