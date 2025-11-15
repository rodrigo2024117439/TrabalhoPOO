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
        src/Comandos/Comandos_Jardineiro/ComandoEntra.cpp
        src/Comandos/Comandos_Jardineiro/ComandoEntra.h
        src/Comandos/Comandos_Jardineiro/ComandoSai.cpp
        src/Comandos/Comandos_Jardineiro/ComandoSai.h
        src/Comandos/Comandos_Plantas/ComandoLPlantas.cpp
        src/Comandos/Comandos_Plantas/ComandoLPlantas.h
        src/Comandos/Comandos_Jardineiro/ComandoColhe.cpp
        src/Comandos/Comandos_Jardineiro/ComandoColhe.h
        src/Comandos/Comandos_mover/ComandoCima.cpp
        src/Comandos/Comandos_mover/ComandoCima.h
        src/Comandos/Comandos_mover/ComandoBaixo.cpp
        src/Comandos/Comandos_mover/ComandoBaixo.h
        src/Comandos/Comandos_mover/ComandoEsq.cpp
        src/Comandos/Comandos_mover/ComandoEsq.h
        src/Comandos/Comandos_mover/ComandoDir.cpp
        src/Comandos/Comandos_mover/ComandoDir.h
        src/Comandos/Comandos_Plantas/ComandoPlantar.cpp
        src/Comandos/Comandos_Plantas/ComandoPlantar.h
        src/Comandos/Comandos_Plantas/ComandoLPlantaEsp.cpp
        src/Comandos/Comandos_Plantas/ComandoLPlantaEsp.h
        src/Comandos/ComandoAvanca.cpp
        src/Comandos/ComandoAvanca.h
)