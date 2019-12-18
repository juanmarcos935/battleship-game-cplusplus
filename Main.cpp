/*
  Archivo: Main.cpp
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// 


#include"Tablero.h"
#include"Arbitro.h"
#include"Jugador.h"
#include"JugadorHumano.h"
#include"JugadorComputador.h"
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;


int main()
{
  srand((int) time(0));

  Tablero tableroHumano;
  Tablero tableroComputador;
  JugadorHumano jugadorHumano;
  JugadorComputador jugadorComputador;

  
  Arbitro arbitro(tableroHumano, tableroComputador, jugadorHumano, jugadorComputador);
  
  bool acaboJuego;

  while(true)
  {
    arbitro.comenzarAJugar();
    
    acaboJuego = arbitro.gameOver();
    
    if(acaboJuego == true)
    {
      break;
    }
    else
    {
      continue;
    }
  }

  
  
  return 0;
  

}