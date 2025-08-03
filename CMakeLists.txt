cmake_minimum_required(VERSION 3.10)
project(mon_projet C)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 99)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(LUA REQUIRED lua5.3)

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIRS}
    ${SRC_DIR}
)

link_directories(
    ${GLFW_LIBRARY_DIRS}
    ${LUA_LIBRARY_DIRS}
)

add_executable(mon_projet
    ${SRC_DIR}/main.c
)

target_link_libraries(mon_projet
    ${OPENGL_gl_LIBRARY}
    ${GLFW_LIBRARIES}
    ${LUA_LIBRARIES}
)
