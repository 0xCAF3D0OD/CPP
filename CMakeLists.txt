cmake_minimum_required(VERSION 3.22)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex03/ex01)

add_executable(CPP
        ex03/ex01/ClapTrap.cpp
        ex03/ex01/ClapTrap.hpp
        ex03/ex01/main.cpp
        ex03/ex01/ScavTrap.cpp
        ex03/ex01/ScavTrap.hpp)
