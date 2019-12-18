/*
  Archivo: Tablero.cpp
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// 

#include "Tablero.h"
#include<stdlib.h>
#include<iostream>
using namespace std;


Tablero::Tablero()
{
  for(int vertical=0; vertical<10; vertical++)
    for(int horizontal=0; horizontal<10; horizontal++)
      tablero[vertical][horizontal] = 0; // AGUA
      
  for(int cantidadBarcos=1; cantidadBarcos<=3; cantidadBarcos++)
    for(int veces=0; veces<cantidadBarcos; veces++)
      ponerBarcoAlAzar(5-cantidadBarcos);
}





void Tablero::ponerBarcoAlAzar(int tamano)
{
  int vertical;
  int horizontal;
  int orientacion;
  do
  {
    int larguraMaximaVertical = 10;
    int larguraMaximaHorizontal = 10;
    orientacion = rand() % 2;  // 0=el barco es horizontal, 1=el barco es vertical
    if(orientacion==1)
      larguraMaximaVertical -= tamano;
    else
      larguraMaximaHorizontal -= tamano;
    
    vertical = rand() % larguraMaximaVertical;
    horizontal = rand() % larguraMaximaHorizontal;
  }
  while(not intentarPonerBarco(vertical,horizontal,orientacion,tamano));
}


bool Tablero::intentarPonerBarco(int vertical, int horizontal, int orientacion,int tamano)
{
  if(revisarSiEstaLibre(vertical,horizontal,orientacion,tamano))
  {
    ponerBarco(vertical,horizontal,orientacion,tamano);
    return true;
  }
  else
    return false;
}


bool Tablero::revisarSiEstaLibre(int vertical, int horizontal, int orientacion, int tamano)
{
  for(int desplazamiento=0; desplazamiento<tamano; desplazamiento++)
    if(tablero[vertical+desplazamiento*orientacion][horizontal+desplazamiento*(1-orientacion)] != 0) //0=AGUA
      return false;

  return true;
}


void Tablero::ponerBarco(int vertical, int horizontal, int orientacion, int tamano)
{
  for(int desplazamiento=-1; desplazamiento<tamano+1; desplazamiento++)
  {
    for(int z=-1; z<=1; z++)
    {
      int y=vertical+desplazamiento*orientacion+z*(1-orientacion);
      int x=horizontal+desplazamiento*(1-orientacion)+z*orientacion;
      if(y>=0 and y<10 and x>=0 and x<10)
      {
        if(z==0 and desplazamiento != -1 and desplazamiento != tamano)
          tablero[y][x] = 1; //1=BARCO
        else
          tablero[y][x] = 4; //4=ALREDEDORES
      }
    }
  }
}

void Tablero::imprimir()
{
  for(int vertical=0; vertical<10; vertical++)
  {
    for(int horizontal=0; horizontal<10; horizontal++)
      cout << tablero[vertical][horizontal];
    cout << endl;
  }
}

void Tablero::limpiarCuatros()
{
    for(int vertical=0; vertical<10; vertical++)
    {
        for(int horizontal=0; horizontal<10; horizontal++)
        {
            if(tablero[vertical][horizontal] == 4)
            {
                tablero[vertical][horizontal] = 0;
            }
        }
    }
}


bool Tablero::haHabidoImpacto(int x, int y)
{
  if(tablero[x][y] == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Tablero::marcarImpacto(int x, int y)
{
  if(haHabidoImpacto(x,y) == true)
  {
    tablero[x][y] = 2;
  }
}

bool Tablero::estaElBarcoHundido(int x, int y)
{
  bool yaLlegueAlLimiteDelBarco = true;
    
  for(int incrementadorEnY_Arriba=y;((incrementadorEnY_Arriba < 10) and yaLlegueAlLimiteDelBarco);incrementadorEnY_Arriba++)
  {
        
        
      if(tablero[x][incrementadorEnY_Arriba] == 0)
      {
          yaLlegueAlLimiteDelBarco = false;
      }
        
      if(tablero[x][incrementadorEnY_Arriba] == 1)
      {
          return false;    
      }
  }
   
    
  yaLlegueAlLimiteDelBarco = true;
  
  for(int incrementadorEnY_Abajo=y;((incrementadorEnY_Abajo >= 0) and yaLlegueAlLimiteDelBarco);incrementadorEnY_Abajo--)
  {
      if(tablero[x][incrementadorEnY_Abajo] == 0)
      {
          yaLlegueAlLimiteDelBarco = false;
      }
        
      if(tablero[x][incrementadorEnY_Abajo] == 1)
      {
          return false;    
      }
  }
   
    
  yaLlegueAlLimiteDelBarco = true;
  
  for(int incrementadorEnX_Izquierda=x;((incrementadorEnX_Izquierda >= 0) and yaLlegueAlLimiteDelBarco);incrementadorEnX_Izquierda--)
  {
      if(tablero[incrementadorEnX_Izquierda][y] == 0)
      {
          yaLlegueAlLimiteDelBarco = false;
      }
        
      if(tablero[incrementadorEnX_Izquierda][y] == 1)
      {
          return false;    
      }   
  }
    
  yaLlegueAlLimiteDelBarco = true;
  
  for(int incrementadorEnX_Derecha=x;((incrementadorEnX_Derecha <10) and yaLlegueAlLimiteDelBarco);incrementadorEnX_Derecha++)
  {
      if(tablero[incrementadorEnX_Derecha][y] == 0)
      {
          yaLlegueAlLimiteDelBarco = false;
      }
        
      if(tablero[incrementadorEnX_Derecha][y] == 1)
      {
          return false;    
      }  
  }
    
    return true;
}

void Tablero::marcarHundimiento(int x, int y)
{
        
      if(estaElBarcoHundido(x,y) == true)
      {
        
          bool yaLlegueAlLimiteDelBarco = true;
          
          for(int incrementadorEnY_Arriba=y;((incrementadorEnY_Arriba < 10) and yaLlegueAlLimiteDelBarco);incrementadorEnY_Arriba++)
          {
                
              if(tablero[x][incrementadorEnY_Arriba] == 0)
              {
                    
                  yaLlegueAlLimiteDelBarco = false;
              }
                
              if(tablero[x][incrementadorEnY_Arriba] == 2)
              {
                    
                  tablero[x][incrementadorEnY_Arriba] = 3;    
              }
          }
            
          yaLlegueAlLimiteDelBarco = true;
          
          for(int incrementadorEnY_Abajo=y;((incrementadorEnY_Abajo >= 0) and yaLlegueAlLimiteDelBarco);incrementadorEnY_Abajo--)
          {
              if(tablero[x][incrementadorEnY_Abajo] == 0)
              {
                  yaLlegueAlLimiteDelBarco = false;
              }
                
              if(tablero[x][incrementadorEnY_Abajo] == 2)
              {
                  tablero[x][incrementadorEnY_Abajo] = 3;   
              }
          }
            
          yaLlegueAlLimiteDelBarco = true;
          
          for(int incrementadorEnX_Izquierda=x;((incrementadorEnX_Izquierda >= 0) and yaLlegueAlLimiteDelBarco);incrementadorEnX_Izquierda--)
          {
              if(tablero[incrementadorEnX_Izquierda][y] == 0)
              {
                  yaLlegueAlLimiteDelBarco = false;
              }
                
              if(tablero[incrementadorEnX_Izquierda][y] == 2)
              {
                tablero[incrementadorEnX_Izquierda][y] = 3;
              }   
          }
            
          yaLlegueAlLimiteDelBarco = true;
          
          for(int incrementadorEnX_Derecha=x;((incrementadorEnX_Derecha < 10) and yaLlegueAlLimiteDelBarco);incrementadorEnX_Derecha++)
          {
              if(tablero[incrementadorEnX_Derecha][y] == 0)
              {
                  yaLlegueAlLimiteDelBarco = false;
              }
                
              if(tablero[incrementadorEnX_Derecha][y] == 2)
              {
                  tablero[incrementadorEnX_Derecha][y] = 3;
              }
          }

      }    
}



bool Tablero::todosImpactados()
{
  for(int vertical=0; vertical<10; vertical++)
    {
        for(int horizontal=0; horizontal<10; horizontal++)
        {
            if(tablero[vertical][horizontal] == 1)
            {
               return false;
            }
            
        }
    }
    return true;
}

