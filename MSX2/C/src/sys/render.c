#pragma once
#include "fusion-c/header/msx_fusion.h"
#include "fusion-c/header/vdp_graph2.h"
#include "src/man/entity.c"
#include "src/man/sprites.c"
#include "src/sys/anim.c"
//Declarations
void sys_render_init();
void sys_render_update(TEntity *entity);
void sys_render_update_player(TEntity *player);
void sys_render_update_enemy(TEntity *enemy);
void sys_render_update_fire(TEntity *fire);

//Definitions
void sys_render_init(){
  SetColors(15,1,1);
  SetBorderColor(0x01);
  Screen(5);
}

void sys_render_update(TEntity *entity){
    if (entity->type==entity_type_player)sys_render_update_player(entity);
    if (entity->type==entity_type_enemy1)sys_render_update_enemy(entity);
    if (entity->type==entity_type_shot)sys_render_update_fire(entity);
}
void sys_render_update_player(TEntity *player){
    //void PutSprite( char sprite_n, char pattern_n, char x, char y, char color)
    // 1 El plano o su definición en la tabla de atributos, es donde alamcenará la posición x e y, y su sprite
    // 2 la definición en sprite pattern que va de 4 en 4
    // 3 posición eje x
    // 4 posición eje y
    // 5 color  
    //PutSprite( pplano, psprite, px,py, pcolor );
    //Si se mueve a la derecha
    if (player->dir==3){
        if (player->jump==1){
            PutSprite( player->plano, player_jump_right_pattern, player->x,player->y,0 );
        }else{
            if(player->andando ==0 ){
                PutSprite( player->plano, player_right_pattern, player->x,player->y,0 );
            } else {
                PutSprite( player->plano, player_right_walking_pattern, player->x,player->y,  0);
            }
        }
    //Si se mueve a la izquierda
    }else if(player->dir==7){
        if (player->jump==1){
            PutSprite( player->plano, player_Jump_left_pattern, player->x,player->y,0 );
        }else{
            if(player->andando ==0){
                PutSprite( player->plano, player_left_pattern, player->x,player->y, 0 );
            } else {
                PutSprite( player->plano, player_left_walking_pattern, player->x,player->y,  0 );
            }
        } 
    }
}



void sys_render_update_enemy(TEntity *enemy){
    sys_anim_update(enemy);
    if (enemy->dir==3){
        if (enemy->andando){
            PutSprite(7,enemy1_pattern,enemy->x,enemy->y,0);
        }else{
            PutSprite(7,enemy1_walking_pattern,enemy->x,enemy->y,0);
        } 
    }else if (enemy->dir==7){
        //Falta sprite 
    }
}

void sys_render_update_fire(TEntity *fire){
    PutSprite(6,fire_pattern,fire->x,fire->y,0);
}
 