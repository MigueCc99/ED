#!/bin/bash
make clean ; make
echo "Ejecutamos los Programas"
echo 
echo "Autor: Miguel Ángel Campos Cubillas 2ºB"
echo
echo "Programa test_ingredientes"
echo
./bin/test_ingredientes datos/ingredientes.txt
echo
echo "Programa tipo_ingredientes"
echo
./bin/tipos_ingredientes datos/ingredientes.txt Molusco

    