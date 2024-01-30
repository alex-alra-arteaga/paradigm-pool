cmake_minimum_required(VERSION 3.20)
project(merengue)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_subdirectory(library/infoware)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

if(APPLE)
  find_library(IOKIT_FW IOKit)
endif()

find_package(Curses REQUIRED)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system audio)

file(GLOB SHARED_SOURCES sources/shared/*.cpp sources/shared/components/*.cpp)
add_library(merengue SHARED ${SHARED_SOURCES})

option(ENABLE_BATTERY "Enable battery support" ON)
if(ENABLE_BATTERY)
  add_definitions(-DENABLE_BATTERY)
endif()

option(ENABLE_SYSTEM "Enable system support" ON)
if(ENABLE_SYSTEM)
  add_definitions(-DENABLE_SYSTEM)
endif()

option(ENABLE_CPU "Enable CPU support" ON)
if(ENABLE_CPU)
  add_definitions(-DENABLE_CPU)
endif()

option(ENABLE_RAM "Enable RAM support" ON)
if(ENABLE_RAM)
  add_definitions(-DENABLE_RAM)
endif()

option(ENABLE_PROCESS "Enable process support" ON)
if(ENABLE_PROCESS)
  add_definitions(-DENABLE_PROCESS)
endif()

set(THEME
    "DEFAULT"
    CACHE STRING "Select the theme to use")
set_property(CACHE THEME PROPERTY STRINGS "DEFAULT" "DARK" "LIGHT")
if(THEME STREQUAL "DEFAULT")
  add_definitions(-DTHEME=0)
elseif(THEME STREQUAL "DARK")
  add_definitions(-DTHEME=1)
elseif(THEME STREQUAL "LIGHT")
  add_definitions(-DTHEME=2)
endif()

file(GLOB CONSOLE_SOURCES sources/App.cpp sources/console/*.cpp)
file(GLOB GRAPHICAL_SOURCES sources/App.cpp sources/graphical/*.cpp
     sources/graphical/components/*.cpp)
add_executable(MyGKrellm ${CONSOLE_SOURCES} ${GRAPHICAL_SOURCES})
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})
if(APPLE)
  target_link_libraries(
    MyGKrellm
    PRIVATE ${CURSES_LIBRARIES}
            m
            iware::infoware
            ${IOKIT_FW}
            merengue
            sfml-graphics
            sfml-window
            sfml-system
            sfml-audio)
else()
  target_link_libraries(
    MyGKrellm
    PRIVATE ${CURSES_LIBRARIES}
            m
            iware::infoware
            merengue
            sfml-graphics
            sfml-window
            sfml-system
            sfml-audio)
endif()
