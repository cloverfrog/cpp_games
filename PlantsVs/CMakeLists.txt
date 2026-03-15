cmake_minimum_required(VERSION 3.10)
project(PlantsVs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(easyx STATIC IMPORTED)
set_target_properties(easyx PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/third_party/easyx/lib64/libeasyx.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/third_party/easyx/include
)

include_directories(src)

add_executable(PlantsVs
    src/main.cpp
    src/test1/test1.cpp
    src/test2/test2.cpp
)

target_link_libraries(PlantsVs 
    PRIVATE 
        easyx
)