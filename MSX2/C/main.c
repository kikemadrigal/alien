//
// MSX Murcia 2020
//

#include "fusion-c/header/msx_fusion.h"
//Para los sprites de todas las entidades
#include "fusion-c/header/vdp_sprites.h"
//Para el HMMC de pantalla.c
#include "fusion-c/header/vdp_graph2.h"
//Para el boolean
#include "fusion-c/header/newTypes.h"
//Para el sprintf
#include <stdio.h>
// Para el memset de pantalla.c
#include <string.h>
//itoa
#include <stdlib.h>
#include "src/entities/pantalla.c"
#include "src/entities/player.c"
#include "src/entities/fire.c"
#include "src/entities/enemies.c"


#include "fusion-c/header/io.h"


//información del juego
void gui(void);
void inicializar_sprites();

void fabricaDeEnemigos();

void procesar_entrada();

//#define  HALT __asm halt __endasm 
//boolean repetir=true;
int posicionPlayerInicial;
TFire* fire;
void main(void){
  SetColors(15,1,1);
  Screen(5);

  inicializar_sprites();
  inicializar_player(); 

  cargarTileSetEnRAM();
  deRamAVramPage1();

  cargarTileMapEnRAM();
  cargarArrayFilasTileMap();
  pintarPantallaInicio();
 
  inicializar_disparos();
  inicilizar_enemigos();
  fabricaDeEnemigos();
  
  gui();
  //verArray();

  /*******Pantalla de biendenida y salón de la fama****/
  //PutText(0,0,Itoa(ReadSP(),"  ",10),8);
  //PutText(0,100,"Alien, pulse una tecla para jugar",8);
  //WaitForKey();
  //Cls();
  /*************Fin pantalla de bienvenida**************/
 
  repetir:
  contador=32;
  while(contador<100 && Inkey()!=27){
    __asm 
      halt 
      halt 
      halt 
    __endasm;
    //El movimiento de la pantalla o scroll está en el input system
    procesar_entrada();
    update_player(posicionPlayerInicial);
    render_player();
    actualizar_disparos();
    actualizar_enemigos();
    //gui();
  }
  PutText(100,100,"Mision cumplida, desea repetir",8);
  goto repetir;
}

void inicializar_sprites(){
  //Ponemos a 0 todos los sprites
  SpriteReset(); 
  // tamaño de sprites 16x16
  Sprite16(); 
  // tamaño de sprites sin ampliar   
  SpriteSmall(); 
  // Los datas del sprites los cargamos con SetSpritePattern, SC5SpriteColors y PutSprite que debería estar en el update
}
 







//Sistema de input
void procesar_entrada(){
  //Screen(0);
	// 0 son cursores teclado
  // 0=inactive  1=up 2=up & right 3=right 4=down & right 5=down 6=down & left 7=left 8=up & left 
	char joy = JoystickRead(0);
  switch (joy)
  {
    case 1:
        //Salto
        if (player.saltando!=1){
          posicionPlayerInicial=player.y;
          player.saltando=1;
        }
        break;
    case 3:
        player.x+=player.velocidad;
        player.direccion=3;
        if (player.andando==0){
          player.andando=1;
        }else{
          player.andando=0;
        }
        recorrerBufferTileMapYPintarPage1EnPage0();
        break;
    case 5:
        //player.y+=player.velocidad;
        break;
    case 7:
        player.x-=player.velocidad;
        player.direccion=7;
        if (player.andando==0){
          player.andando=1;
        }else{
          player.andando=0;
        }
        break;
    default:
        break;
  }
  
  //Leemos el disparo
  char trigger = TriggerRead(0);
  if (trigger!=0) {
    Beep();
    if (numero_disparo<10){
      TFire* fire=crear_disparos();
      fire->x=player.x;
      fire->y=player.y+12;
      fire->velocidad=20;
      fire->plano=10+numero_disparo;
      fire->sprite=10*4;
    }
  }
}




void fabricaDeEnemigos(){
    TEnemy* enemy1=crear_enemigos();
    enemy1->x=255;
    enemy1->y=19*8;
    enemy1->velocidad=4;
    enemy1->direccion=7;
    enemy1->plano=20;
    enemy1->sprite=11*4;
    enemy1->color=6;
    enemy1->tipo=0;
}




//HUD
void gui(){
  BoxLine(0,184,255,210,6,8);
  BoxFill(0,184,255,210,1,8);
  /*
  //Colision derecha con bloque
  int fila=(player.y/8)+3;
  int columna=((player.x/8)+2)+(contador-32);
  PutText(0,185,Itoa(fila,"  ",10),8);
  PutText(0,195,Itoa(columna,"  ",10),8);
  PutText(0,203,Itoa(filas[fila][columna],"  ",10),8);
  */

  PutText(0,185,Itoa(array_structs_enemigos[0].plano,"  ",10),8);
  PutText(0,195,Itoa(array_structs_enemigos[0].sprite,"  ",10),8);
  PutText(0,203,Itoa(array_structs_enemigos[0].x,"  ",10),8);
  PutText(100,185,Itoa(numero_disparo,"  ",10),8);
  PutText(100,195,Itoa(numero_de_enemigo,"  ",10),8);
  PutText(180,185,Itoa(contador,"  ",10),8);
}


char generar_numero_aleatorio (char a, char b){
  //Time es un struct + typedef con 3 enteros para las horas, minutos y segundos
    //TIME tm;
    char random; 
    //GetTime obtiene la hora del MSDOS y se la asigna al struct TIME
    //GetTime(&tm); 
    //srand utiliza los segundos como semilla para generar un número aleatorio  
    //srand y rand forman parte de la librería stdlib.h normalmente utilizada para castear strings y manejar memoria dinámica         
    //srand(tm.sec);
    random = rand()%(b-a)+a;  
    return(random);
}

























































