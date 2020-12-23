//
// MSX Murcia 2020
//

#include "fusion-c/header/msx_fusion.h"
//Para los sprites de todas las entidades
#include "fusion-c/header/vdp_sprites.h"
//Para el HMMC de pantalla.c
#include "fusion-c/header/vdp_graph2.h"
//Para el boolean
//#include "fusion-c/header/newTypes.h"
//Para el sprintf
//#include <stdio.h>
// Para el memset de pantalla.c
#include <string.h>
//itoa
#include <stdlib.h>
#include "src/entities/pantalla.c"
#include "src/entities/player.c"
#include "src/entities/fire.c"
#include "src/entities/enemies.c"


//#include "fusion-c/header/io.h"


//información del juego
void gui(void);
void inicializar_sprites();

void fabricaDeEnemigos();

void procesar_entrada();
void update_collision_system();
//#define  HALT __asm halt __endasm 
//boolean repetir=true;
int posicionPlayerInicial;
unsigned int espacioLibre;
TFire* fire;
void main(void){
  espacioLibre=0;

  SetColors(15,1,1);
  Screen(5);

  inicializar_sprites();
  SpriteOn();
  inicializar_player(); 

  inicializarPantalla();
  cargarTileSetEnRAM();
  deRamAVramPage1();

  cargarTileMapEnRAM();
  pintarPantallaInicio();
 
  inicializar_disparos();
  inicilizar_enemigos();
  fabricaDeEnemigos();

  SetRealTimer(0);	
  KeySound(0);
  
  gui();
  //verArray();

  /*******Pantalla de biendenida y salón de la fama****/
  //PutText(0,0,Itoa(ReadSP(),"  ",10),8);
  //PutText(0,100,"Alien, pulse una tecla para jugar",8);
  //WaitForKey();
  //Cls();
  /*************Fin pantalla de bienvenida**************/
 
  repetir:
  //El scroll empezará en la columna 32
  contadorColumna=32;
  while(contadorColumna<numeroColumnas && Inkey()!=27){
    __asm 
      halt 
      halt 
      halt 
    __endasm;
    
    //El movimiento de la pantalla o scroll está en el input system
    procesar_entrada();
    update_player();
    actualizar_disparos();
    actualizar_enemigos();

    render_player();
    update_collision_system();
    //recorrerBufferTileMapYPintarPage1EnPage0();
    gui();
  }
  PutText(0,100,"Mision cumplida, desea repetir?",8);
  char letra=WaitKey();
  PutText(0,120,Itoa(letra,"  ",10),8);
  if (letra==27){
    PutText(0,130,"Has presionado escape",8);
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
 







//Sistema de input
void procesar_entrada(){
  //Screen(0);
	// 0 son cursores teclado
  // 0=inactive  1=up 2=up & right 3=right 4=down & right 5=down 6=down & left 7=left 8=up & left 
	char joy = JoystickRead(0);
  switch (joy)
  {
    case 1:
      player.y-=player.velocidadY;

        /*
        //Salto
        if (player.saltando!=1){
          player.saltando=1;
          player.y-=48;
        }*/
        break;
    case 3:
        if (player.colision==0) {
          player.oldX=player.x;
          player.oldY=player.y;
          if ((player.x/8)>14) recorrerBufferTileMapYPintarPage1EnPage0();
          else{
              player.x+=player.velocidadX;
          }

          player.direccion=3;
          if (player.andando==0){
            player.andando=1;
          }else{
            player.andando=0;
          }
        }
        break;
    case 5:
        player.y+=player.velocidadY;
        break;
    case 7:
      if(player.colision==0){
        player.x-=player.velocidadX;
        player.direccion=7;
        if (player.andando==0){
          player.andando=1;
        }else{
          player.andando=0;
        }
      } 
        //recorrerBufferTileMapYPintarPage1EnPage0Inversa();
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
      fire->direccion=player.direccion;
      fire->velocidad=20;
      fire->plano=10+numero_disparo;
      fire->sprite=10*4;
    }
  }
}

void update_collision_system(){
  //Colisiond l player con el enemigo
  for (int i=0; i<numero_de_enemigo;i++){
    if(collisionPlayer(array_structs_enemigos[i].x,array_structs_enemigos[i].y)) Beep();
  }
  //Colision del disparo con el enemigo
  for (int i=0; i<numero_disparo;i++){
    if (collision_enemigos(array_structs_fires[i].x,array_structs_fires[i].y)) {
      eliminar_disparos(i);
      //eliminar_enemigos(collision_enemigos(array_structs_fires[i].x,array_structs_fires[i].y));
    }
  }
}




//HUD
void gui(){
  BoxLine(0,184,255,210,6,8);
  BoxFill(0,184,255,210,1,8);

  tileY=(player.y/8)+4;
  tileX=(player.x/8)+(contadorColumna-32);
  PutText(100,185,Itoa(tileY,"  ",10),8);
  PutText(100,195,Itoa(tileX,"  ",10),8);
  PutText(100,203,Itoa(bufferTileSetYMap[tileY*numeroColumnas+tileX],"  ",10),8);
  PutText(120,185,"Enemigos:",8);
  PutText(120,195,"Tiempo:",8);
  PutText(120,203,"Conatdor: ",8);
  PutText(200,185,Itoa(numero_de_enemigo,"  ",10),8);
  PutText(200,195,Itoa(RealTimer()/60,"  ",10),8);
  PutText(200,203,Itoa(contadorColumna,"  ",10),8);
  /*
  PutText(0,185,Itoa(array_structs_enemigos[0].plano,"  ",10),8);
  PutText(0,195,Itoa(array_structs_enemigos[0].sprite,"  ",10),8);
  PutText(0,203,Itoa(array_structs_enemigos[0].x,"  ",10),8);
  PutText(100,185,Itoa(numero_disparo,"  ",10),8);
  PutText(100,195,Itoa(numero_de_enemigo,"  ",10),8);
  PutText(180,185,Itoa(contador,"  ",10),8);
  */
}




























































