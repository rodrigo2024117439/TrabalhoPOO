cmake_minimum_required(VERSION 3.30)
project(Trabalho_Pratico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Trabalho_Pratico
        src/main.cpp


        #Classes Principais
        src/Parser.cpp
        src/Parser.h
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

        #Classes Derivadas (Ferramentas)
        src/Ferramentas/Regador.cpp
        src/Ferramentas/Regador.h
        src/Ferramentas/Adubo.cpp
        src/Ferramentas/Adubo.h
        src/Ferramentas/Tesoura.cpp
        src/Ferramentas/Tesoura.h
        src/Ferramentas/FerramentaZ.cpp
        src/Ferramentas/FerramentaZ.h

        #Classes para os comandos
        src/Comandos/Comando.cpp
        src/Comandos/Comando.h
        src/Comandos/comandoEntra.cpp
        src/Comandos/comandoEntra.h
        src/Comandos/ComandoSai.cpp
        src/Comandos/ComandoSai.h
        src/Comandos/ComandoLPlantas.cpp
        src/Comandos/ComandoLPlantas.h
        src/Comandos/ComandoColhe.cpp
        src/Comandos/ComandoColhe.h
        src/Comandos/ComandoCima.cpp
        src/Comandos/ComandoCima.h
        src/Comandos/ComandoBaixo.cpp
        src/Comandos/ComandoBaixo.h
        src/Comandos/ComandoEsq.cpp
        src/Comandos/ComandoEsq.h
        src/Comandos/ComandoDir.cpp
        src/Comandos/ComandoDir.h
)