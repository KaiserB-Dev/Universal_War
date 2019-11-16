#!/bin/bash

echo "Compilando..."

cd Clases/

g++ -Wall -o test  windowScene.cc main.cc Player.cc bullet.cc -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

echo "Compilacion finalizada"

echo "Ejecutando"

./test

cd ..

echo "fin"


