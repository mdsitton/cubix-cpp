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
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
	set(PLATFORM_LINUX 1)

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
	message(STATUS "Building for Mac OS X.")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
	set(PLATFORM_OSX 1)

endif()


find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/core/config.hpp.in"
  "${PROJECT_SOURCE_DIR}/src/core/config.hpp"
)

set( SOURCE ${PROJECT_SOURCE_DIR}/src/game/main.cpp )
set( HEADERS ${PROJECT_SOURCE_DIR}/src/core/config.hpp )

include_directories(${PROJECT_SOURCE_DIR}/src/core)
include_directories(${PROJECT_SOURCE_DIR}/src/engine)
include_directories(${PROJECT_SOURCE_DIR}/src/game)

add_executable(cubix ${SOURCE} ${HEADERS})

target_link_libraries(cubix ${SDL2_LIBRARY})