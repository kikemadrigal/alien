#pragma once
#include "fusion-c/header/msx_fusion.h"
#include "fusion-c/header/vdp_graph2.h"
#include "src/man/entity.c"

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
    sys_render_update_player(entity);

}
void sys_render_update_player(TEntity *player){
    //void PutSprite( char sprite_n, char pattern_n, char x, char y, char color)
    // 1 El plano o su definición en la tabla de atributos, es donde alamcenará la posición x e y, y su sprite
    // 2 la definición en sprite pattern que va de 4 en 4
    // 3 posición eje x
    // 4 posición eje y
    // 5 color  
    //PutSprite( pplano, psprite, px,py, pcolor );

    if (player->dir==3){
        //Pintamos el tronco superior, color 9 rosa
        PutSprite( player->plano, player_right_head1_pattern, player->x,player->y,0 );
        //Se ha creado un 2 sprite para el tronco superior, porque en MSX1 son 1 solo color por sprite
        //Pintamos el tronco superior 2, color amarillo 10
        PutSprite( player->plano+1, player_right_head2_pattern, player->x,player->y,  0);
        //Pintamos las piernas
        if(player->andando ==0){
            PutSprite( player->plano+2, player_right_legs1_pattern, player->x,player->y+16, 0 );
        } else {
            PutSprite( player->plano+2, player_right_legs2_pattern, player->x,player->y+16,  0 );
        }
        //Pintamos el arma
        PutSprite( player->plano+3, player_right_weapon, player->x,player->y+8, 0 );
    }else if(player->dir==7){
        //Pintamos el tronco superior, color 9 rosa
        PutSprite( player->plano, player_left_head1_pattern, player->x,player->y, 0 );
        //Pintamos el tronco superior 2, color amarillo 10
        PutSprite( player->plano+1, player_left_head2_pattern, player->x,player->y,  0 );
        //Pintamos las piernas
        if(player->andando ==0){
            PutSprite( player->plano+2, player_left_legs1_pattern, player->x,player->y+16,  0 );
        } else {
            PutSprite( player->plano+2, player_left_legs2_pattern, player->x,player->y+16,  0 );
        }
        //Pintamos el arma
        PutSprite( player->plano+3, player_left_weapon, player->x,player->y+8, 0 );
    }
    

   

}







void sys_render_update_enemy(TEntity *enemy){
  /*
     for (int i=0; i<numero_de_enemigo;i++){
       //Si se mueve a la derecha
    if(array_structs_enemigos[i].direccion==3){
        array_structs_enemigos[i].x-=array_structs_enemigos[i].velocidad;
        if(array_structs_enemigos[i].x<0){
            array_structs_enemigos[i].x=255;
            array_structs_enemigos[i].y=generar_numero_aleatorio (100,150);
            array_structs_enemigos[i].color=generar_numero_aleatorio (0, 14);
        } 
    }
   if(array_structs_enemigos[i].direccion==7){
        array_structs_enemigos[i].x+=array_structs_enemigos[i].velocidad;
        if(array_structs_enemigos[i].x>240){
            array_structs_enemigos[i].x=0;
            array_structs_enemigos[i].y=generar_numero_aleatorio (100,150);
            array_structs_enemigos[i].color=generar_numero_aleatorio (0, 14);
        } 
    }
    
    if(array_structs_enemigos[i].x % 2){
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }else{
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite+4,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }
   
   }
   */
}

void sys_render_update_fire(TEntity *fire){
  /*
    for (int i=0; i<numero_disparo; i++){
    if (array_structs_fires[i].direccion==3) array_structs_fires[i].x+=array_structs_fires[i].velocidad;
    if (array_structs_fires[i].direccion==7) array_structs_fires[i].x-=array_structs_fires[i].velocidad;
    if(array_structs_fires[i].x>240 || array_structs_fires[i].x<0){
      PutSprite( array_structs_fires[i].plano, array_structs_fires[i].sprite, 1,215, 15 );
      eliminar_disparos(i);
    } else{
       PutSprite( array_structs_fires[i].plano, array_structs_fires[i].sprite, array_structs_fires[i].x,array_structs_fires[i].y, 15 );
    }
    */
  
}
 