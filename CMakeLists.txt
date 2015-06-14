cmake_minimum_required (VERSION 2.8)


project (tactics_ogre2)


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
link_directories("/usr/lib/SFML")
include_directories("/usr/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory("${PROJECT_SOURCE_DIR}/src")


add_executable (${PROJECT_NAME} ${SOURCE} ${HEADERS} )

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-system sfml-window)


