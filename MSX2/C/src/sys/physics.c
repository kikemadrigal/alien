#pragma once
#include "./src/man/entity.c"

//Declarations
void sys_physics_init();
void sys_physics_update(TEntity *entity);
void sys_physics_check_keyboard(TEntity *entity);
void realizar_salto(TEntity *entity, char posicion_inicial);
//Members
//char posicion_inicial_jump;
char contador_jump;
char array_jump[5];
//Definitions
void sys_physics_init(){
    //posicion_inicial_jump=0;
    contador_jump=0;

    array_jump[0]=14;
    array_jump[1]=8;
    array_jump[2]=0;
    array_jump[3]=-8;
    array_jump[4]=-14;

}
void sys_physics_update(TEntity *entity){
    if (entity->type==entity_type_player)
        sys_physics_check_keyboard(entity);
    entity->old_x=entity->x;
    entity->old_y=entity->y;
    entity->x+=entity->vx;
    entity->y+=entity->vy;
}



void sys_physics_check_keyboard(TEntity *entity){
    //movement
    entity->vx=0;
    entity->vy=0;
    // 0=inactive  1=up 2=up & right 3=right 4=down & right 5=down 6=down & left 7=left 8=up & left 
    char joy = JoystickRead(0);
    if(joy !=0){
        if (entity->andando==0){
          entity->andando=1;
        }else{
          entity->andando=0;
        }
    }
    if(joy==3){
        entity->dir=3;
        if ((entity->x/8)>14){
            recorrerBufferTileMapYPintarPage1EnPage0();
            entity->vx=0;
        }else{
            entity->vx=8;
        }
    }
    if(joy==7) {
        entity->dir=7;
        entity->vx=-8; 
    }
    if(joy==1){
        //entity->vy=-8;
        if (entity->jump!=1){
          entity->jump=1;
        }
 
    }
    if(joy==5){
        entity->vy=8;
    }  

    //shot
    

    
    //jump
    if (entity->jump==1){
        if(contador_jump<sizeof(array_jump)){
            entity->y-=array_jump[contador_jump];
            ++contador_jump;
        }else{
            entity->jump=0;
            contador_jump=0;
        }
    }
}
