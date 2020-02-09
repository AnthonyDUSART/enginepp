cmake_minimum_required(VERSION 3.0)

set(NAME_PROJECT engine)
set(SRC_DIR src)
set(BIN_DIR bin)
set(INCLUDE_DIR include)

project(${NAME_PROJECT})

FILE(GLOB FILES_CPP_H 
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.c
    ${SRC_DIR}/*.h
    ${SRC_DIR}/*.hpp
)

# OpenGL
find_package(OpenGL REQUIRED)

# SDL2
find_package(SDL2 REQUIRED)
message(STATUS "SDL included at ${SDL2_INCLUDE_DIR}")

# GLM
find_package(glm REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${NAME_PROJECT} ${FILES_CPP_H})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

#Include(FindPkgConfig)
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR}) #<--- Changed this from ${OpenGL_INCLUDE_DIRS} to ${OPENGL_INCLUDE_DIRS} (Again not sure I need that variable)
set(LIBS ${LIBS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2IMAGE_LIBRARIES}) #<---(Changed this from ${OpenGL_LIBRARIES} to ${OPENGL_LIBRARY}
include_directories(${INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${LIBS})
#target_link_libraries(${NAME_PROJECT} ${SDL2_DIR} ${OPENGL_DIR} ${GLEW_DIR})

# add_library(test src/main.cpp)