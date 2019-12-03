#!/bin/bash

echo "Compilando..."

cd Clases/

g++ -Wall -o Universal_War  windowScene.cc main.cc Player.cc enemy.cc bullet.cc lifes.cc menu.cc score.cc -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

echo "Compilacion finalizada"

if [ -f Universal_War  ]; 
	then
echo "Ejecutando"

./Universal_War

cd ..


else

    echo  "Compilacion con errores"
	cd ..
fi

echo "fin"


