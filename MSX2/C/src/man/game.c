#pragma once
#include "src/man/entity.c"
#include "src/man/sprites.c"
#include "src/man/graphics.c"
#include "src/sys/render.c"
#include "src/sys/physics.c"
#include "src/sys/ai.c"

//=================Declarations
//Members

//Functions
//Functions
void man_game_init();
void man_game_play();
void man_game_update();
void man_game_desplazar_entidades_a_la_izquierda();
void man_game_crear_disparo();
void scoreboard();
void wait();

TEntity* array_entities;
TEntity* player;
char world;
char world_change;
char screen;
char number_shot;
void man_game_init(){
  world=0;
  world_change=0;
  screen=0;
  number_shot=0;
  //Ponemos la pantalla en screen 5
  sys_render_init();
  sys_physics_init();
  cargarLoaderEnRAM();
  deRamAVramPage0();
  sys_entity_init();
  man_sprites_init();
  man_sprites_load();
  player=sys_entity_create_template(&player_template);  
  SetRealTimer(0);	
  KeySound(0);

  array_entities=sys_entity_get_array_structs_entities();

  inicializarPantalla();
  cargarTileSetEnRAM();
  deRamAVramPage1();

  cargarTileMapEnRAM();
  pintarPantallaInicio();
  man_game_update();
  scoreboard();
}

void man_game_play(){
  //El contador de columna se actualizará en el graphics update
  int contador_columna=man_graphics_get_column_counter();
  int numero_columnas=man_graphics_get_num_columns();
  while(contador_columna<numero_columnas){
    if(man_graphics_get_column_counter()==33) world_change=1;


    for (char i=0;i<sys_entity_get_num_entities();++i){
        TEntity *entity=&array_entities[i];
        //Le ponemos el comportamiento a los enemigos
        sys_ai_update(entity);
        sys_physics_update(entity);
        scoreboard();
        //Movemos la pantalla si el player1/2 está en el centro
        if (entity->type==entity_type_player && entity->x/8>14){
          man_game_desplazar_entidades_a_la_izquierda();
          recorrerBufferTileMapYPintarPage1EnPage0();
          //Le tenemos que restar la x a todas las entidades

        }

        sys_render_update(entity);
        //chequeamos la creación de enemigos por mundos
        //man_game_update();
        wait();
    }
  }
}

void man_game_update(){
   if(world==0){
      //Si es la primaera pantalla del mundo 1
       TEntity *enemy1=sys_entity_create_template(&enemy1_template);
       enemy1->y=20*8;
       enemy1->x=26*8;
      //world_change=0;
   }
}

void man_game_desplazar_entidades_a_la_izquierda(){
  for (char i=0;i<sys_entity_get_num_entities();++i){
    TEntity *entity=&array_entities[i];
    if (entity->type==entity_type_player) entity->x-=entity->vx;
    if (entity->type==entity_type_enemy1) {
      //
    }
  }
}

void man_game_crear_disparo(){
  TEntity *entity=&array_entities[0];
  Beep();
  if (number_shot<10){
    TEntity* fire=sys_entity_create_template(&fire_template);
    fire->x=entity->x;
    fire->y=entity->y+8;
    fire->dir=entity->dir;
    fire->vx=20+number_shot;   
    ++number_shot;
  }
}



void scoreboard(){
    //void Rect ( int X1, int Y1, int X2, int Y2, int color, int OP )
    //void BoxFill (int X1, int Y1, int X2, int yY22, char color, char OP )

    BoxFill (0, 23*8, 256, 210, 6, LOGICAL_IMP );
    TEntity *entity=&array_entities[0];

    //PutText(0,180,Itoa(man_graphics_get_column_entity(entity),"  ",10),8);
    //PutText(60,180,Itoa(get_fila_entity(entity),"  ",10),8);

    //PutText(150,180,Itoa(man_graphics_get_tile_left_array(entity),"  ",10),8);
    //PutText(190,180,Itoa(man_graphics_get_tile_right_array(entity),"  ",10),8);
    //PutText(230,180,Itoa(get_tile_down_array(entity),"  ",10),8);

    PutText(0,190,Itoa(entity->x,"  ",10),8);
    PutText(50,190,Itoa(entity->y,"  ",10),8);
    PutText(100,190,Itoa(entity->vx,"  ",10),8);
    PutText(150,190,Itoa(entity->dir,"  ",10),8);

    PutText(10,200, Itoa(man_graphics_get_column_counter(),"   ",10),0);
    PutText(50,200, Itoa(sys_entity_get_num_entities(),"   ",10),0);
    PutText(100,200, Itoa(man_graphics_get_column_entity(entity),"   ",10),0);


    
    

}

void wait(){
    __asm
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

