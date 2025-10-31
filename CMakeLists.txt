cmake_minimum_required(VERSION 3.30)
project(Trabalho_Pratico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Trabalho_Pratico
        src/main.cpp

        #BABE LÊ LÁ EM BAIXO

        #Classes Principais
        src/Comando.cpp
        src/Comando.h
        src/Interface.cpp
        src/Interface.h
        src/Jardim.cpp
        src/Jardim.h
        src/Solo.cpp
        src/Solo.h
        src/Jardineiro.cpp
        src/Jardineiro.h
        src/Settings.h

        #Classes Base
        src/Plantas/Planta.cpp
        src/Plantas/Planta.h
        src/Ferramentas/Ferramenta.cpp
        src/Ferramentas/Ferramenta.h

        #Classes Derivadas (Plantas)
        src/Plantas/Cacto.cpp
        src/Plantas/Cacto.h
        src/Plantas/Roseira.cpp
        src/Plantas/Roseira.h
        src/Plantas/PlantaExotica.cpp
        src/Plantas/PlantaExotica.h
        src/Plantas/ErvaDaninha.cpp
        src/Plantas/ErvaDaninha.h
        # Cravo adiciona aqui os .cpp e .h da roseira, ervadaninha, plantaexotica aka temos de escolher uma merda qlqr

        #Classes Derivadas (Ferramentas)
        src/Ferramentas/Regador.cpp
        src/Ferramentas/Regador.h
        src/Ferramentas/Adubo.cpp
        src/Ferramentas/Adubo.h
        src/Ferramentas/Tesoura.cpp
        src/Ferramentas/Tesoura.h
        src/Ferramentas/FerramentaZ.cpp
        src/Ferramentas/FerramentaZ.h
        #adiciona aqui os .cpp e .h do adubo, tesoura, ferramentaz aka temos de escolher uma merda qlqr
        #FALTA MUDAR O INTERFACE.CPP!!!!!!!!!!
)