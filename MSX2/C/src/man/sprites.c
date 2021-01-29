#pragma once 
#include "fusion-c/header/vdp_sprites.h"
#include "src/sprites/player.c"
#include "src/sprites/enemy.c"
#include "src/sprites/fire.c"
//Declaration
//#ifndef __SPRITES_H__
//#define __SPRITES_H__
  //Data
  #define player_left_pattern 0
  #define player_left_walking_pattern 4
  #define player_right_pattern 8
  #define player_right_walking_pattern 12

  #define player_jump_right_pattern 16
  #define player_Jump_left_pattern 20

  #define fire_pattern 24

  #define enemy1_pattern 28
  #define enemy1_walking_pattern 32
  #define enemy2_pattern 36
  #define enemy2_walking_pattern 40



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
    SetSpritePattern( player_right_pattern, player_right, 32);
    SetSpritePattern( player_right_walking_pattern, player_right_walking, 32);
    SetSpritePattern( player_left_pattern, player_left, 32);
    SetSpritePattern( player_left_walking_pattern, player_left_walking, 32);
    SetSpritePattern( player_jump_right_pattern, player_jump_right, 32);
    SetSpritePattern( player_Jump_left_pattern, player_jump_left, 32);
    SetSpritePattern( fire_pattern, fire, 32);
    SetSpritePattern( enemy1_pattern, enemy1, 32);
    SetSpritePattern( enemy1_walking_pattern, enemy1_walking, 32);
    SetSpritePattern( enemy2_pattern, enemy2, 32);
    SetSpritePattern( enemy2_walking_pattern, enemy2_walking, 32);

    //Le ponemos el color al sprite
    SC5SpriteColors(0, color_player_left);
    SC5SpriteColors(1, color_player_left_walking);
    SC5SpriteColors(2, color_player_right);
    SC5SpriteColors(3, color_player_right_walking);
    SC5SpriteColors(4, color_player_jump_right);
    SC5SpriteColors(5, color_player_jump_right);
    SC5SpriteColors(6, color_enemy1);
    SC5SpriteColors(7, color_enemy1_walking);
    SC5SpriteColors(8, color_enemy2);
    SC5SpriteColors(9, color_enemy2_walking);


}