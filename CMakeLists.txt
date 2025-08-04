cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME SilvEngine)
project(${PROJECT_NAME} C)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 99)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(LUA REQUIRED lua5.3)

include_directories(
    ${INCLUDE_DIR} 
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIRS}
)

link_directories(
    ${GLFW_LIBRARY_DIRS}
    ${LUA_LIBRARY_DIRS}
)

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OPENGL_gl_LIBRARY}
    ${GLFW_LIBRARIES}
    ${LUA_LIBRARIES}
)
