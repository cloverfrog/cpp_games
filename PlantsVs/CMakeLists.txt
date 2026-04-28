cmake_minimum_required(VERSION 3.10)
project(PlantsVs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wconversion -Wpedantic)

add_library(easyx STATIC IMPORTED)
set_target_properties(easyx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/third_party/easyx/lib64/libeasyx.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/third_party/easyx/include
)

include_directories(src)

add_executable(PlantsVs
    src/main.cpp
    src/core/timer.cpp
    src/camera.cpp
    src/atlas.cpp
    src/animation.cpp
    src/resource_manager.cpp
    src/scene/menu_scene.cpp
    src/scene/game_scene.cpp
    src/scene/selector_scene.cpp
    src/scene_manager.cpp
)

target_link_libraries(PlantsVs 
    PRIVATE 
        easyx
        winmm
        msimg32
)

# Copy resources to the output directory after building
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/resources"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
)