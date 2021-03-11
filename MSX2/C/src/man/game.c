#pragma once
#include "src/man/entity.c"
#include "src/man/sprites.c"
#include "src/man/graphics.c"
#include "src/sys/render.c"
#include "src/sys/physics.c"
#include "src/sys/collider.c"
#include "src/sys/ai.c"

//=================Declarations
//Functions
void man_game_init();
void man_game_play();
void man_game_update();
void man_game_desplazar_entidades_a_la_izquierda();
void man_el_mapa_ha_cambiado();
void man_game_crear_disparo();
void man_han_matado_al_player();
void scoreboard();
void wait();
//Members
TEntity* player;
TEntity* array_enemies;
TEntity* array_shots;
TEntity* array_objects;
#define numero_mundos 2
#define enemigos_por_mundo 10  
//typedef struct TCoordinate TCoordinate;
//struct TCoordinate{
//    unsigned char x;
//    unsigned char y;
//    unsigned char world;
//    unsigned char type;
//};
//TCoordinate array_structs_objects[10];
char world_enemies[numero_mundos][enemigos_por_mundo]={
  {32,35,37,70,80,132,135,137,170,172},
  {35,45,55,60,65,135,145,155,160,165}
};

char actual_world;

char world_change;
char screen;
char number_shot;
signed int contador_columna;
int numero_columnas;
signed int old_contador_columna;
//=============End declarations



void man_game_init(){
  //Ponemos la pantalla en screen 5
  sys_render_init();
  //Pantalla de carga
  cargarLoaderEnRAM();
  deRamAVramPage0();
  //reservamos 10*21bytes en la RAM para trabajar en ese espacio de memoria
  sys_entities_init();
  //Inicializamos las colisiones
  sys_collider_init();
  //Tamaño y cosas de MSX para los sprites
  man_sprites_init();
  //Los sprites están definidos en la RAM en unos archivos.c los cargamos en la VRAM
  man_sprites_load();

  inicializarPantalla();
  cargarTileSetEnRAM();
  deRamAVramPage1();

  cargarTileMapEnRAM();
  pintarPantallaInicio();


  SetRealTimer(0);	
  KeySound(0);
  actual_world=0;
  //Le ponemos que aplique que el mapa ha cambiado para que ponga los objetos y el player
  world_change=1;
  screen=0;
  number_shot=0;
  old_contador_columna=0;
  //memset(array_structs_objects,0,sizeof(array_structs_objects));
  player=sys_entity_create_player();  
  //El contador de columna se actualizará en el graphics update
  contador_columna=man_graphics_get_column_counter();
  numero_columnas=man_graphics_get_num_columns();
  //Según el mundo que cargemos tendremos unos enemigos y unos objetos que coger
  man_game_update();

  array_enemies=sys_entity_get_array_structs_enemies();
  array_shots=sys_entity_get_array_structs_shots();
  array_objects=sys_entity_get_array_structs_objects();
  TEntity *object_oxigen1=sys_entity_create_object();
  object_oxigen1->y=14*8;
  object_oxigen1->x=8*8;
  TEntity *object_batery1=sys_entity_create_object();
  object_batery1->y=20*8;
  object_batery1->x=25*8;
  object_batery1->type=entity_type_object_batery;
  PutText(150,200,"creado objeto",0);
  scoreboard();
}

void man_game_play(){
  //Game loop
  while(contador_columna<numero_columnas){
    sys_physics_update(player);
    if (player->x/8>14){
          man_game_desplazar_entidades_a_la_izquierda();
          recorrerBufferTileMapYPintarPage1EnPage0();
    }
    //Dibujamos al player
    sys_render_update(player);
    //Dibujamos los enemigos
    for (char i=0;i<sys_entity_get_num_enemies();++i){
        TEntity *enemy=&array_enemies[i];
        sys_physics_update(enemy);
        if (sys_collider_entity1_collider_entity2(player, enemy)){
          man_han_matado_al_player();
          Beep();
        }
        //Le aplicamos un comportamiento a los enemigos según el tipo de enemigo que sea
        sys_ai_update(enemy);
        //Si el enemigo se sale de la pantalla lo matamos
        if (enemy->x<0) sys_entity_erase_enemy(i);
        else if (enemy->x>255) sys_entity_erase_enemy(i);
        else if (enemy->y>180) sys_entity_erase_enemy(i);
        sys_render_update(enemy);
    }
    //Dibujamos los objetos
    for (char i=0;i<sys_entity_get_num_objects();++i){
      TEntity *object=&array_objects[i];
      if (sys_collider_entity1_collider_entity2(player, object)){
        sys_entity_erase_object(i);
        Beep();
      }
      //Si el objecto se sale de la pantalla lo matamos
      if (object->x<0) sys_entity_erase_object(i);
      else if (object->y>180) sys_entity_erase_object(i);
      sys_render_update(object);
    }
    //Dibujamos los disparos
    for (char i=0;i<sys_entity_get_num_shots();++i){
      TEntity *shot=&array_shots[i];
      sys_physics_update(shot);
      if(sys_collider_collision_enemy_with_shot(shot))Beep;
      //Si el objecto se sale de la pantalla lo matamos
      if (shot->x<0) sys_entity_erase_shot(i);
      else if (shot->x>255) sys_entity_erase_shot(i);
      else if (shot->y>180) sys_entity_erase_shot(i);
      sys_render_update(shot);
    }
    man_game_update();
    //scoreboard();
    wait();
  }
}


void man_game_update(){
  //PutText(150,200, Itoa(sys_entity_get_num_objects(),"   ",10),0);
  //if (world_change==1){
  //  man_el_mapa_ha_cambiado();
  //  if(actual_world==0){
  //    TEntity *object_oxigen1=sys_entity_create_object();
  //    object_oxigen1->y=16*8;
  //    object_oxigen1->x=5*8;
  //    PutText(150,200,"creado objeto",0);
  //  }
  //  world_change=0;
  //} 
  if(actual_world==0){
    // {32,35,40,70,80}
    //el old_contador_columna espara que no se repita si estas en la misma columna
    if (old_contador_columna!=man_graphics_get_column_counter()){
      for (int i=0;i<enemigos_por_mundo;i++ ){
        if ( man_graphics_get_column_counter()==world_enemies[actual_world][i]) {
          TEntity *enemy=sys_entity_create_enemy1();
          enemy->y=20*8;
          enemy->x=248;
          enemy->dir=7;
          PutText(150,200, Itoa(world_enemies[actual_world][i],"   ",10),0);
        }
      }

      old_contador_columna=man_graphics_get_column_counter();
    }

  }
}

void man_el_mapa_ha_cambiado(){

}

void man_game_desplazar_entidades_a_la_izquierda(){
  player->x-=player->vx;
  for (char i=0;i<sys_entity_get_num_enemies();++i){
    TEntity *enemy=&array_enemies[i];
    if (enemy->type==entity_type_enemy1 && enemy->dir==3) {
       enemy->x-=enemy->vx*3;
    }
  }
  for (char i=0;i<sys_entity_get_num_objects();++i){
    TEntity *object=&array_objects[i];
       object->x-=object->vx;
  }
}

void man_game_crear_disparo(){
  TEntity *shot=sys_entity_create_shot();
    shot->x=player->x+8;
    shot->y=player->y+4;
    shot->dir=player->dir;
}
 void man_han_matado_al_player(){
    player->x=0;
    player->y=0;
 }



void scoreboard(){
    //void Rect ( int X1, int Y1, int X2, int Y2, int color, int OP )
    //void BoxFill (int X1, int Y1, int X2, int yY22, char color, char OP )

    BoxFill (0, 23*8, 256, 210, 6, LOGICAL_IMP );
    //TEntity *enemy=&array_enemies[0];

    //PutText(0,190,Itoa(enemy->x,"  ",10),8);
    //PutText(50,190,Itoa(old_contador_columna,"  ",10),8);
    //PutText(100,190,Itoa(enemy->vx,"  ",10),8);
    //PutText(150,190,Itoa(enemy->plane,"  ",10),8);
    TEntity *shot=&array_shots[0];
    PutText(0,190,Itoa(shot->x,"  ",10),8);
    PutText(50,190,Itoa(shot->y,"  ",10),8);
    PutText(100,190,Itoa(sys_entity_get_num_shots(),"  ",10),8);
    //PutText(150,190,Itoa(object->plane,"  ",10),8);

    //PutText(10,200, Itoa(man_graphics_get_column_counter(),"   ",10),0);
    //PutText(50,200, Itoa(sys_entity_get_num_enemies(),"   ",10),0);
    //PutText(100,200, Itoa(player->x/8,"   ",10),0);
    //PutText(150,200, Itoa(man_graphics_get_num_columns(),"   ",10),0);
    PutText(10,200, Itoa(get_tile_down_array(player),"   ",10),0);
    PutText(50,200, Itoa(player->x,"   ",10),0);
    PutText(100,200, Itoa((player->x)/8,"   ",10),0);
    
    

}

void wait(){
    __asm
      halt
      halt
      halt
      halt
      halt
      halt
  __endasm;
}


//char generar_numero_aleatorio (char a, char b){
//    char random; 
//    random = rand()%(b-a)+a;  
//    return(random);
//}

