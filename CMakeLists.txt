cmake_minimum_required(VERSION 3.22)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(module_03/ex01)

add_executable(CPP
        module_03/ex01/ClapTrap.cpp
        module_03/ex01/ClapTrap.hpp
        module_03/ex01/main.cpp
        module_03/ex01/ScavTrap.cpp
        module_03/ex01/ScavTrap.hpp)
