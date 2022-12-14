cmake_minimum_required(VERSION 3.24.2)
project(Task_32_2)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(Boost_INCLUDE_DIR "c:\\boost_1_80_0")
set(Boost_LIBRARY_DIR "c:\\boost_1_80_0\\stage\\lib")

find_package(Boost COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}//base//film.json     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}//src)