#pragma once
#include "src/man/entity.c"
//para obtener el man_graphics_get_column_counter()
#include "src/man/graphics.c"
//Para el Beep()
#include "fusion-c/header/msx_fusion.h"

//Declarations
void sys_collider_init();
void sys_collider_update(TEntity *entity);
void sys_collider_player_with_solid();
void sys_collider_player_with_enemy();
void sys_collider_apply_gravity();
void sys_collider_bounding_screen(TEntity *entitiy);
TEntity* array_entities;
TEntity* player;
//char *bufferTileSetYMap[];

//Definitions
void sys_collider_init(){
    //El player siempre es la posición 0
    array_entities=sys_entity_get_array_structs_entities();
    player=&array_entities[0];
    //bufferTileSetYMap=man_graphics_get_buffer_tile_map();
}
void sys_collider_update(TEntity *entity){
     sys_collider_bounding_screen(entity);
    sys_collider_player_with_solid();
}
void sys_collider_player_with_solid(){
    int tileX_player_right, tileX_player_left, tileX_player_down, tileY_player;
    int tile3,tile7;
    int numero_columnas;

    tileX_player_left=(player->x/8)+((man_graphics_get_column_counter()-32));
    tileX_player_right=(player->x/8)+(man_graphics_get_column_counter()-32)+1;
    tileX_player_down=bufferTileSetYMap[tileY_player+1*numero_columnas+tileX_player_left];
    tileY_player=(player->y/8)+3;
    tile3=bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_right];
    tile7=bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_left];
    numero_columnas=man_graphics_get_num_columns();
    if (player->dir==3){
        //if (bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_right]>=195){
        if (bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_right]>=195){
            //Beep();
            player->x=player->old_x;
            /*
            if (player->jump==1){
                 player->y-=8;
            }*/     
        }
    }
    if (player->dir==7){
        if (bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_left]>=195){
            //Beep(); 
            player->x=player->old_x;
            /*
            if(player->jump==1){
                 player->y+=8;
            }*/
        }
    }
    //bufferTileSetYMap[tileY_mapa*ancho_fila+tileX_player_left];
    if (bufferTileSetYMap[tileY_player*numero_columnas+tileX_player_left]>=195){
        Beep();
        player->y-=8;
    }
    sys_collider_apply_gravity();

    //Colisión suelo y objetos solidos
    /*if (bufferTileSetYMap[(tileY_player+1)*numero_columnas+tileX_player_left]>=195){
        Beep();
        player->y+=8;
    }*/        
}


void sys_collider_bounding_screen(TEntity *entity){
    //Colision con los bordes de la pantalla
    if (entity->x<16) entity->x=16;
    if (entity->x>240) entity->x=240;
    //Colsión márgenes camino
    //if (entity->y<80) entity->y=80;
    //if (entity->y>140) entity->y=140;

}



void sys_collider_apply_gravity(){
    int tileX_player_left=(player->x/8)+((man_graphics_get_column_counter()-32));
    int tileY_player=(player->y/8)+3;
    int tileX_player_down=bufferTileSetYMap[tileY_player+1*man_graphics_get_num_columns()+tileX_player_left];
    if (tileX_player_down >=160 && tileX_player_down <=165 && player->jump==0 ){
        player->y+=8;
    }else{
        player->y-=0;
    }
}


void sys_collider_player_with_enemy(){
    /*if (enemiX < player.x + 16 &&  enemiX + 16 > player.x && enemiY < player.y + 32 && 16 + enemiY > player.y){
    return 1;
    }else{
        return 0;
    }*/
}