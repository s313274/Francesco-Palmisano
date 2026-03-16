cmake_minimum_required(VERSION 3.20) #Versione minima Cmake

project(esercitazione1) #nome progetto

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #imposto versione minima di C++ e la rendo un requisito

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow") #aggiungiamo warning (in particolare quelli di shadowing)

add_executable(mediatemp mediatemp.cpp) #crea l'eseguibile mediatemp da mediatemp.cpp