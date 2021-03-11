#pragma once
#include "fusion-c/header/msx_fusion.h"
#include "src/man/entity.c"
#include "src/sys/physics.c"
//Declarations
void sys_ai_init();
void sys_ai_update(TEntity *entity);
void sys_ai_update_enemy_behavior_1(TEntity *enemy);



//Definitions
void sys_ai_init(){

}


void sys_ai_update(TEntity *entity){
    if (entity->type==entity_type_enemy1)sys_ai_update_enemy_behavior_1(entity);
}

void sys_ai_update_enemy_behavior_1(TEntity *enemy){
    //Cuando haya un choque con algún objeto pared se cambiará su velocidad para que reste y la dirección
    if (man_graphics_get_tile_left_array(enemy)>man_graphics_get_tile_suelo() || man_graphics_get_tile_right_array(enemy)>man_graphics_get_tile_suelo() ){
        if(enemy->dir==7) enemy->dir=3;
        else if(enemy->dir==3) enemy->dir=7;
        //Beep();
    }
    if (get_tile_down_array(enemy)<man_graphics_get_tile_suelo()) enemy->y+=enemy->vy;
    if(enemy->dir==7){
        enemy->x-=enemy->vx;
    }else if(enemy->dir==3){
        enemy->x+=enemy->vx;
    }
    

}


