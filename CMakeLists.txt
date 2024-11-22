cmake_minimum_required(VERSION 3.28)
project(progetto_finale_tnv_xiv C)

set(CMAKE_C_STANDARD 90)

add_executable(progetto_finale_tnv_xiv main.c
        libreriaGenerazioneRandom.c
        libreriaGenerazioneRandom.h
        libreriaInserimentoControllo.c
        libreriaInserimentoControllo.h
        libreriaMacroComuni.c
        libreriaMacroComuni.h
        libreriaStampa.c
        libreriaStampa.h
        libreriaFileData.c
        libreriaFileData.h)
