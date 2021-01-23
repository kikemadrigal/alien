#pragma once 
#include "fusion-c/header/vdp_sprites.h"
#include "src/sprites/player.c"
#include "src/sprites/enemy.c"
#include "src/sprites/fire.c"
//Declaration
//#ifndef __SPRITES_H__
//#define __SPRITES_H__
  //Data
  #define player_right_head1_pattern 0
  #define player_right_head2_pattern 4
  #define player_right_legs1_pattern 8
  #define player_right_legs2_pattern 12
  #define player_right_weapon 16
 
  #define player_left_head1_pattern 20
  #define player_left_head2_pattern 24
  #define player_left_legs1_pattern 28
  #define player_left_legs2_pattern 32
  #define player_left_weapon 36

  #define enemy1_pattern 40
  #define enemy1_walking_pattern 44
  #define enemy2_pattern 48
  #define enemy2_walking_pattern 52
  #define enemy3_pattern 56
  #define enemy3_walking_pattern 60
  #define enemy4_pattern 64
  #define enemy4_walking_pattern 68
  
  #define fire_pattern 72

  //Funtions
  void man_sprites_init();
  void man_sprites_load();
//#endif

//Definitions
void man_sprites_init(){
  //Ponemos a 0 todos los sprites
  SpriteReset(); 
  // tamaño de sprites 16x16
  Sprite16(); 
  //// tamaño de sprites sin ampliar   
  SpriteSmall(); 
}


//Definition
void man_sprites_load(){
    //Player
    // px= player posición eje x, py= player posición eje y
    // pv player velocidad, pm= player movimiento (se obtiene del teclado)
    // lo metemos en la tabla de dEfinición de patrones
    // el 1 argumento es la posición en la poisión en la tabla de definición de sprites (sprite pattern),tenemos que ir sumando 4 porque fusion c es asi
    // el 2 argumentos son los datos del sprite
    // el 3 argumento es el numero de bytes del patron
    SetSpritePattern( player_right_head1_pattern, personaje_tronco_superior_derecha1, 32);
    SetSpritePattern( player_right_head2_pattern, personaje_tronco_superior_derecha2, 32);
    SetSpritePattern( player_right_legs1_pattern, personaje_piernas_derecha1, 32);
    SetSpritePattern( player_right_legs2_pattern, personaje_piernas_derecha2, 32);
    SetSpritePattern( player_right_weapon, arma_derecha, 32);
    SetSpritePattern( player_left_head1_pattern, personaje_tronco_superior_izquieda1, 32);
    SetSpritePattern( player_left_head2_pattern, personaje_tronco_superior_izquierda2, 32);
    SetSpritePattern( player_left_legs1_pattern, personaje_piernas_izquierda1, 32);
    SetSpritePattern( player_left_legs2_pattern, personaje_piernas_izquierda2, 32);
    SetSpritePattern( player_left_weapon, arma_izquierda, 32);
    //Le ponemos el color al sprite
    SC5SpriteColors(0, color_personaje_tronco_superior1);
    SC5SpriteColors(1, color_personaje_tronco_superior2);
    SC5SpriteColors(2, color_personaje_piernas1);
    SC5SpriteColors(3, color_personaje_piernas2);
    SC5SpriteColors(4, color_arma);



    //Enemy
    SetSpritePattern( enemy1_pattern, enemigo1, 32);
    SetSpritePattern( enemy1_walking_pattern, enemigo1andando, 32);
    SetSpritePattern( enemy2_pattern, enemigo2, 32);
    SetSpritePattern( enemy2_walking_pattern, enemigo2andando, 32);
    SetSpritePattern( enemy3_pattern, enemigo3, 32);
    SetSpritePattern( enemy3_walking_pattern, enemigo3andando, 32);
    SetSpritePattern( enemy4_pattern, enemigo4, 32);
    SetSpritePattern( enemy4_walking_pattern, enemigo4andando, 32);

    SC5SpriteColors( 5, colorEnemigo1);
    SC5SpriteColors( 6, colorEnemigo1Andando);
    SC5SpriteColors( 7, colorEnemigo2);
    SC5SpriteColors( 8, colorEnemigo2Andando);
    SC5SpriteColors( 9, colorEnemigo3);
    SC5SpriteColors( 10, colorEnemigo3Andando);
    SC5SpriteColors( 11, colorEnemigo4);
    SC5SpriteColors( 12, colorEnemigo4Andando);

    //fire
    SetSpritePattern( fire_pattern, fireSprite, 32);
}