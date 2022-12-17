cmake_minimum_required(VERSION 3.25.1)
project(Task_32_2)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}//base//film.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR}//src)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(JSON_BuildTests OFF CACHE INTERNAL "")

#set(Boost_INCLUDE_DIR "c:\\boost_1_81_0")
#set(Boost_LIBRARY_DIR "c:\\boost_1_81_0\\stage\\lib")
#find_package(Boost COMPONENTS REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#link_directories(${Boost_LIBRARY_DIR})
add_subdirectory(src)
add_subdirectory(nlohmann_json)
#add_library(${PROJECT_NAME})
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)


