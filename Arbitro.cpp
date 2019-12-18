/*
  Archivo: Arbitro.cpp
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

#include<stdlib.h>
#include<iostream>
#include"Jugador.h"
#include"JugadorHumano.h"
#include"JugadorComputador.h"
#include"Tablero.h"
#include"Arbitro.h"

Arbitro::Arbitro(Tablero &tableroHumano,Tablero &tableroComputador,JugadorHumano &jugadorHumano,JugadorComputador &jugadorComputador)
{
  this->tableroHumano = tableroHumano;
  this->tableroComputador = tableroComputador;
  this->jugadorHumano = jugadorHumano;
  this->jugadorComputador = jugadorComputador;
}

void Arbitro::comenzarAJugar()
{
  tableroHumano.limpiarCuatros();
  tableroComputador.limpiarCuatros();
  
  int x1, y1, x2, y2;
    
  bool booleano1, booleano2, booleano3, booleano4;
    
  cout << "----- TABLERO HUMANO: -----" << endl;
  tableroHumano.imprimir();
  cout << "----- TABLERO COMPUTADOR: -----" << endl;
  tableroComputador.imprimir();
      
  jugadorHumano.dimeTuJugada(x1, y1);
  booleano1 = tableroComputador.haHabidoImpacto(x1, y1);
  if(booleano1 == true)
  {
    tableroComputador.marcarImpacto(x1, y1);
  }
  booleano2 = tableroComputador.estaElBarcoHundido(x1, y1);
  if(booleano2 == true)
  {
    tableroComputador.marcarHundimiento(x1, y1);
  }


      
    
  cout << "----- TABLERO HUMANO: -----" << endl;
  tableroHumano.imprimir();
  cout << "----- TABLERO COMPUTADOR: -----" << endl;
  tableroComputador.imprimir();
      
  jugadorComputador.dimeTuJugada(x2, y2);
  booleano3 = tableroHumano.haHabidoImpacto(x2, y2);
  if(booleano3 == true)
  {
    tableroHumano.marcarImpacto(x2, y2);
  }
  booleano4 = tableroHumano.estaElBarcoHundido(x2, y2);
  if(booleano4 == true)
  {
    tableroHumano.marcarHundimiento(x2, y2);
  }
  
      
  
}


bool Arbitro::gameOver()
{
  bool booleano5, booleano6;
  
  booleano5 = tableroComputador.todosImpactados();
  booleano6 = tableroHumano.todosImpactados();
  
  if((booleano5 == true) or (booleano6 == true))
  {
    return true;
  }
  else
  {
    return false;
  }
}

