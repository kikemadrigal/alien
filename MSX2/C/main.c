//
// MSX Murcia 2020
//

#include "fusion-c/header/msx_fusion.h"
//Para los sprites de todas las entidades
#include "fusion-c/header/vdp_sprites.h"
//Para el HMMC de pantalla.c
#include "fusion-c/header/vdp_graph2.h"
//Para el sprintf
#include <stdio.h>
// Para el memset de pantalla.c
#include <string.h>
//itoa
#include <stdlib.h>
#include "src/entities/pantalla.c"
#include "src/entities/player.c"
//#include "fire.h"
//#include "enemies.h"


#include "fusion-c/header/io.h"


//información del juego
void gui(void);
void inicializar_sprites();

void inicializar_enemigos();
void crear_enemigos();
void actualizar_enemigos();
void eliminar_enemigos();

void procesar_entrada();
void verArray();

//#define  HALT __asm halt __endasm 

void main(void){
  
  SetColors(15,1,1);
  Screen(5);
  SetColors(15,1,1);

  cargarTileSetEnRAM();
  deRamAVramPage1();

  cargarTileMapEnRAM();
  cargarArrayFilasTileMap();

  inicializar_sprites();
  //Vamos aver la fila 4
  //verArray();

  /*******Pantalla de biendenida y salón de la fama****/
  //PutText(0,0,Itoa(ReadSP(),"  ",10),8);
  PutText(0,100,"Alien, pulse una tecla para jugar",8);
  WaitForKey();
  Cls();
  /*************Fin pantalla de bienvenida**************/


  inicializar_player(); 
 //Vamos a pintar arriba a la derecha el tile con el diibujo del 4 que es el tile 52 


  gui();
  repetir:
  //Inkey()!=27 si no has pulsado la tecla escape
  while(contador<100 && Inkey()!=27){
    //contador++;
    //HALT;
    /*
    __asm 
      halt 
      halt 
    __endasm;
    */
    recorrerBufferTileMapYPintarPage1EnPage0();
    procesar_entrada();
    actualizar_personaje();
    //actualizar_disparos();
    //gui();
  }
  PutText(100,100,"Mision cumplida, desea repetir",8);
  char c=InputChar();
  if (c='s'){
    Cls();
    contador=0;
    goto repetir;
  }
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
 





/*************ENEMIGOS******************/
void inicilizar_enemigos(){
  //SetSpritePattern( enemigo2_Sprite, sprite_enemigo2, 32);
  //SC5SpriteColors(enemigo2_Plano, color_sprite_enemigo2);
}
void crear_enemigos(){

}
void actualizar_enemigos(){

}
void eliminar_enemigos(){

}
/***********FINAL DE ENEMIGOS*************/

//Sistema de input
void procesar_entrada(){
  //Screen(0);
	// 0 son cursores teclado
  // 0=inactive  1=up 2=up & right 3=right 4=down & right 5=down 6=down & left 7=left 8=up & left 
	char joy = JoystickRead(0);
  switch (joy)
  {
    case 1:
        //py-=pvelocidad;
        player.y-=player.velocidad;
        //Hay que multiplizar por 4 el sprite porque fusionc es así
        //psprite=2*4;
        break;
    case 3:
        //px+=pvelocidad;
        player.x+=player.velocidad;
        //psprite=0;
        break;
    case 5:
        //py+=pvelocidad;
        player.y+=player.velocidad;
        //psprite=4*4;
        break;
    case 7:
        //px-=pvelocidad;
        player.x-=player.velocidad;
        //psprite=0;
        break;
    default:
        break;
  }
  //Leemos el disparo
  char trigger = TriggerRead(0);
  if (trigger!=0) {
    //crear_disparos();
    Beep();
  }
}


//HUD
void gui(){
  //BoxLine(0,0,255,16,6,8);
  //PutText(2,0,"Alien:",8);
  //PutText(8*8,0,Itoa(obtener_colision_x(),"  ",10),8);
  //PutText(120,0,Itoa(fireSprite,"  ",10),8);
  //PutText(150,0,Itoa(devuelve_entero(),"  ",10),8);
}





























































