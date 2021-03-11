#pragma once 
#include "fusion-c/header/vdp_sprites.h"
#include "src/sprites/player.c"
#include "src/sprites/enemy.c"
#include "src/sprites/fire.c"
#include "src/sprites/object.c"
//Declaration
//#ifndef __SPRITES_H__
//#define __SPRITES_H__
  //Data

  //Definiendo patrones
  #define player_left_pattern 0
  #define player_left_walking_pattern 4
  #define player_right_pattern 8
  #define player_right_walking_pattern 12

  #define player_jump_right_pattern 16
  #define player_Jump_left_pattern 20

  #define shot_pattern 24

  #define enemy1_right_pattern 28
  #define enemy1_right_walking_pattern 32
  #define enemy1_left_pattern 36
  #define enemy1_left_walking_pattern 40
  #define enemy2_pattern 44
  #define enemy2_walking_pattern 48

  #define object_oxigen_pattern 52
  #define object_batery_pattern 56


  //Definiendo colores

  //Definiendo planos
  #define player_plane 0
  #define enemy1_plane 6
  #define enemy2_plane 12
  #define object1_oxigen_plane 22
  #define object2_plane_plane 24
  #define shot_plane 30

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
    SetSpritePattern( shot_pattern, fire, 32);
    SetSpritePattern( enemy1_right_pattern, enemy1_left, 32);
    SetSpritePattern( enemy1_right_walking_pattern, enemy1_walking_left, 32);
    SetSpritePattern( enemy1_left_pattern, enemy1_right, 32);
    SetSpritePattern( enemy1_left_walking_pattern, enemy1_walking_right, 32);
    SetSpritePattern( enemy2_pattern, enemy2, 32);
    SetSpritePattern( enemy2_walking_pattern, enemy2_walking, 32);
    SetSpritePattern( object_oxigen_pattern, object_oxigen, 32);
    SetSpritePattern( object_batery_pattern, object_batery, 32);


    //Le ponemos el color al sprite
    SC5SpriteColors(0, color_player_left);
    SC5SpriteColors(1, color_player_left_walking);
    SC5SpriteColors(2, color_player_right);
    SC5SpriteColors(3, color_player_right_walking);
    SC5SpriteColors(4, color_player_jump_right);
    SC5SpriteColors(5, color_player_jump_right);
    //De los sprites 6 al 16 tendrán el color de enemy1
    SC5SpriteColors(6, color_enemy1_left);
    SC5SpriteColors(7, color_enemy1_left);
    SC5SpriteColors(8, color_enemy1_left);
    SC5SpriteColors(9, color_enemy1_left);
    SC5SpriteColors(10, color_enemy1_left);
    SC5SpriteColors(11, color_enemy1_left);
    SC5SpriteColors(12, color_enemy1_left);
    SC5SpriteColors(13, color_enemy1_left);
    SC5SpriteColors(14, color_enemy1_left);
    SC5SpriteColors(15, color_enemy1_left);
    SC5SpriteColors(16, color_enemy1_left);

    SC5SpriteColors(17, color_enemy1_walking_left);
    SC5SpriteColors(18, color_enemy1_right);
    SC5SpriteColors(19, color_enemy1_walking_right);
    SC5SpriteColors(20, color_enemy2);

    
    SC5SpriteColors(21, color_enemy2_walking);
    SC5SpriteColors(22, color_object_oxigen);
    SC5SpriteColors(23, color_object_oxigen);
    SC5SpriteColors(24, color_object_oxigen);
    SC5SpriteColors(25, color_object_oxigen);
    SC5SpriteColors(26, color_object_oxigen);
    SC5SpriteColors(27, color_object_oxigen);
    SC5SpriteColors(29, color_object_oxigen);
    SC5SpriteColors(30, color_fire);
}