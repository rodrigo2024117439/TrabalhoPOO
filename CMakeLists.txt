cmake_minimum_required(VERSION 4.0)
project(Trabalho_Pratico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Trabalho_Pratico src/main.cpp
        src/comando.cpp
        src/comando.h
        src/interface.cpp
        src/interface.h
        src/jardim.cpp
        src/jardim.h
        src/solo.cpp
        src/solo.h
        src/planta.cpp
        src/planta.h
        src/jardineiro.cpp
        src/jardineiro.h
        src/ferramenta.cpp
        src/ferramenta.h)
