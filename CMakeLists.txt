cmake_minimum_required(VERSION 3.10)
project(HFTSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(HFTSimulator ${SOURCES})

# Set Boost directory explicitly
set(BOOST_ROOT "C:/Program Files/Boost/boost_1_82_0/boost_1_82_0")
set(BOOST_INCLUDEDIR "C:/Program Files/Boost/boost_1_82_0/boost_1_82_0")
set(BOOST_LIBRARYDIR "C:/Program Files/Boost/boost_1_82_0/boost_1_82_0/stage/lib")

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(HFTSimulator ${Boost_LIBRARIES})
endif()