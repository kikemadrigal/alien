#pragma once
#include "fusion-c/header/msx_fusion.h"
#include "src/man/entity.c"
char sys_collider_entity1_collider_entity2(TEntity *entity1, TEntity *entity2);
char sys_collider_collision_enemy_with_shot(TEntity *shot);
TEntity *array_enemies;

void sys_collider_init(){
    array_enemies=sys_entity_get_array_structs_enemies();
}

char sys_collider_entity1_collider_entity2(TEntity *entity1, TEntity *entity2){
    //if (enemiX < player.x + 16 &&  enemiX + 16 > player.x && enemiY < player.y + 32 && 16 + enemiY > player.y){
    if (entity2->x < entity1->x + 16 &&  entity2->x + 16 > entity1->x && entity2->y < entity1->y + 16 && 16 + entity2->y > entity1->y){
        return 1;
    }else{
        return 0;
    }
}
char sys_collider_collision_enemy_with_shot(TEntity *shot){       
    for (int i=0; i<sys_entity_get_num_enemies();i++){
        TEntity *enemy=&array_enemies[i];
         if (enemy->x < shot->x + 16 &&  enemy->x + 16 > shot->x && enemy->y < shot->y + 16 && 16 + enemy->y > shot->y){
            return 1;
        }else{
            return 0;
        }
    }  
}