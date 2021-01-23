#pragma once
#include "src/man/entity.c"
#include "src/man/sprites.c"
#include "src/man/graphics.c"
#include "src/sys/render.c"
#include "src/sys/physics.c"
#include "src/sys/scroll.c"
#include "src/sys/collider.c"
//=================Declarations
//Members

//Functions
//Functions
void man_game_init();
void man_game_play();
void scoreboard();
void wait();

TEntity* array_entities;
TEntity* player;

void man_game_init(){


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

  //sys_scroll_init();
}

void man_game_play(){
  //El contador de columna se actualizará en el graphics update
  int contador_columna=man_graphics_get_column_counter();
  int numero_columnas=man_graphics_get_num_columns();
  while(contador_columna<numero_columnas){
    for (char i=0;i<sys_entity_get_num_entities();++i){
        TEntity *entity=&array_entities[i];

        sys_physics_update(entity);
        //Si hay colision con el mapa se vuelve a la posición anterior
        sys_collider_update(0x000);
        scoreboard();


        sys_render_update(entity);
        //El scroll se realiza en el physics
        //sys_scroll_update(entity);

        //wait();

    }
  }
}







void scoreboard(){
    //void Rect ( int X1, int Y1, int X2, int Y2, int color, int OP )
    //void BoxFill (int X1, int Y1, int X2, int yY22, char color, char OP )
    //Rect ( 0, 180, 256, 212, 6, LOGICAL_IMP );
    BoxFill (0, 180, 256, 210, 6, LOGICAL_IMP );
    TEntity *entity=&array_entities[0];
    int tileY=(player->y/8)+3;
    int tileY_mapa=(player->y/8)+3;
    int ancho_fila=man_graphics_get_num_columns();
    int tileX_player_left=(player->x/8)+((man_graphics_get_column_counter()-32)-1);
    int tileX_player_right=(player->x/8)+(man_graphics_get_column_counter()-32)+1;
    int tileX_player_down=bufferTileSetYMap[tileY_mapa*ancho_fila+tileX_player_left];
    int tile7=bufferTileSetYMap[tileY*ancho_fila+tileX_player_left];
    int tile3=bufferTileSetYMap[tileY*ancho_fila+tileX_player_right];
    //int tileX_player_down=(player->x/8)+((man_graphics_get_column_counter()-32));
 
    PutText(0,180, "Tiles ",0);
    PutText(50,180, Itoa(tileX_player_left,"   ",10),0);
    PutText(80,180, Itoa(tileX_player_right,"   ",10),0);
    //PutText(130,180, Itoa(tileX_player_down,"   ",10),0);
    PutText(150,180,Itoa(bufferTileSetYMap[tileY*ancho_fila+tileX_player_left],"  ",10),8);
    PutText(190,180,Itoa(bufferTileSetYMap[tileY*ancho_fila+tileX_player_right],"  ",10),8);
    PutText(230,180,Itoa(bufferTileSetYMap[(tileY-1)*ancho_fila+tileX_player_left],"  ",10),8);

    PutText(0,190, "array ",0);
    PutText(100,190, Itoa(sizeof(array_jump),"   ",10),0);
    
    
    PutText(0,200, Itoa(entity->dir,"   ",10),0);
    PutText(50,200, Itoa(man_graphics_get_column_counter(),"   ",10),0);
    PutText(100,200, Itoa(tile7,"   ",10),0);
    PutText(150,200, Itoa(tile3,"   ",10),0);
    PutText(180,200,Itoa(tileX_player_down,"  ",10),0);
}

void wait(){
    __asm
      halt
      halt
  __endasm;
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