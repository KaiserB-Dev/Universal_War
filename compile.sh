#!/bin/bash

echo "Compilando..."

cd Clases/

g++ -Wall -o test  windowScene.cc main.cc Player.cc enemy.cc bullet.cc lifes.cc menu.cc score.cc -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

echo "Compilacion finalizada"

if [ -f test  ]; 
	then
echo "Ejecutando"

./test

rm test

cd ..

else

    echo  "Compilacion con errores"
	cd ..
fi

echo "fin"


