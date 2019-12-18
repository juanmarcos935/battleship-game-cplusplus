/*
  Archivo: JugadorComputador.cpp
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
#include"JugadorComputador.h"
#include"Jugador.h"

JugadorComputador::JugadorComputador() : Jugador()
{

}

void JugadorComputador::dimeTuJugada(int &jugadaenX, int &jugadaenY)
{
  jugadaenX = (rand() % 10);
  jugadaenY = (rand() % 10);
  Jugador::dimeTuJugada(jugadaenX,jugadaenY);
}

