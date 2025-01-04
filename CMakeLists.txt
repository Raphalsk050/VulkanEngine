cmake_minimum_required(VERSION 3.10)

project(VulkanEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR src)
set(INCLUDE_DIR include)

set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/vulkan_instance.cpp
        ${SRC_DIR}/window.cpp
        ${SRC_DIR}/engine.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/engine.h
        ${INCLUDE_DIR}/vulkan_instance.h
        ${INCLUDE_DIR}/window.h
)

add_executable(VulkanEngine
        ${SOURCES}
        ${HEADERS}
)

target_include_directories(VulkanEngine PUBLIC ${CMAKE_SOURCE_DIR}/${INCLUDE_DIR})

# vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(VulkanEngine Vulkan::Vulkan)

# glfw
find_package(glfw3 REQUIRED)
target_link_libraries(VulkanEngine glfw)