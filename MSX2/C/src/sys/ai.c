#pragma once
#include "fusion-c/header/msx_fusion.h"
#include "src/man/entity.c"
#include "src/sys/physics.c"
//Declarations
void sys_ai_init();
void sys_ai_update(TEntity *entity);
void sys_ai_update_enemy_behavior_1(TEntity *enemy);
void sys_ai_update_fire(TEntity *fire);

//Definitions
void sys_ai_init(){

}


void sys_ai_update(TEntity *entity){
     if (entity->type==entity_type_enemy1)sys_ai_update_enemy_behavior_1(entity);
    if (entity->type==entity_type_shot)sys_ai_update_fire(entity);
}

void sys_ai_update_enemy_behavior_1(TEntity *enemy){
    //Si se mueve a la derecha
    //if(enemy->dir==3){
        if (man_graphics_get_tile_left_array(enemy)>man_graphics_get_tile_suelo() || man_graphics_get_tile_right_array(enemy)>man_graphics_get_tile_suelo() ){
            enemy->vx*=-1;
        }
        enemy->x+=enemy->vx;
    //}
    //if(enemy->dir==7){
    //    if(man_graphics_get_tile_right_array(enemy)>man_graphics_get_tile_suelo())enemy->vx*=-1;
    //    enemy->x+=enemy->vx; 
    //}
}
void sys_ai_update_fire(TEntity *fire){
    if(fire->dir==3){
        if (fire->x<8){
            //sys_entity_eliminar_entity(fire);
        }
        fire->x+=fire->vx;
    }

}

