/*
  Archivo: JugadorHumano.cpp
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

#include<stdlib.h>
#include<iostream>
#include"JugadorHumano.h"
#include"Jugador.h"
using namespace std;

JugadorHumano::JugadorHumano() : Jugador()
{

}

void JugadorHumano::dimeTuJugada(int &jugadaenX, int &jugadaenY)
{
  cout << "Digite la coordenada FILA (de arriba a abajo, 0 para la fila más alta, 9 para la fila inferior): " << endl;
  cin>>jugadaenX;
  cout << "Digite la coordenada COLUMNA (de izquierda a derecha, 0 para la columna del borde izquierdo, 9 para la columna del borde derecho): " << endl;
  cin>>jugadaenY;
  Jugador::dimeTuJugada(jugadaenX,jugadaenY);
}

