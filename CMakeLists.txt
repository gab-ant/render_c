cmake_minimum_required(VERSION 3.16)

project(render_c C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL_X11_XSCRNSAVER OFF CACHE BOOL "" FORCE)
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(render_c src/main.c)

target_link_libraries(render_c PRIVATE SDL3::SDL3)
