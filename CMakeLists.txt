cmake_minimum_required(VERSION 4.0)
project(tresEnRaya)

set(CMAKE_CXX_STANDARD 20)

add_executable(tresEnRaya main.cpp
        globales.h
        dosJugadores.h
        dosJugadores.cpp
        unJugador.cpp
        unJugador.h)
