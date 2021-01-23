#pragma once
//para el memset
#include <string.h>
//#include "src/man/entity-templates.c"


//================================Declarations
#define entity_type_invalid      0x00  
#define entity_type_player       0x01  
#define entity_type_enemy        0x02  
#define entity_type_mothership   0x04  
#define entity_type_shot         0x08  
#define entity_type_boxFill      0x10  
#define entity_type_dead         0x80  
#define entity_type_default      entity_type_enemy

#define entity_cmp_render    0x01  //en binario=0000 0001- Renderable entity, entidad dibujable 
#define entity_cmp_movable   0x02  //en binario=0000 0010- Movable entidad, entidad movible (podemos hacerla no moverla para las vidas) 
#define entity_cmp_input     0x04  //en binario=0000 0100- Entity controllable by input
#define entity_cmp_ai        0x08  //en binario=0000 0100- Entity controllable by ai
#define entity_cmp_animated  0x10  //Animated entity
#define entity_cmp_default   0x00  //DEfault components(all bits =0)



//VARIABLES Y ARRAYS
//Members
typedef struct TEntity TEntity;
struct TEntity{
    unsigned char type;
    unsigned char cmp;
    unsigned char x,y;
    unsigned char old_x,old_y;
    unsigned char w,h;
    unsigned char vx,vy;
    unsigned char dir;
    unsigned char andando;
    unsigned char jump;
    unsigned char collision;
    unsigned char plano;
    unsigned char sprite;
    unsigned char color;
    unsigned char energy;
};
#define MAX_ENTITIES 10
TEntity array_structs_entities[10];
char num_entities;
//Functions
void sys_entity_init();
TEntity* sys_entity_create();
TEntity* sys_entity_create_template(TEntity *template);
//void sys_create_enemy();
TEntity* sys_entity_get_array_structs_entities();
char sys_entity_get_num_entities();
char sys_entity_get_max_entities();
//===================================End declarations






//=======================================Definitions
const TEntity player_template={
    entity_type_player, // Type
    entity_cmp_movable | entity_cmp_render | entity_cmp_input, //Components 0b=11=0000 1011
    8*1,8*18,            //x,y  
    8*1,8*18,           //old position
    16, 16,             //width, heigh
    0,0,                //speed X,speed Y 
    3,                  //direction
    0,                  //is it jumpimg?
    0,                  //is it colliding?
    0,                  //patrón/plano
    0,                  //Sprite
    10,                 //Color
    100                 //Enenrgy
};
//Life cicle
void sys_entity_init(){
    //Ponemos a 0 todos los valores del array de estructuras
    //void * memset ( void * ptr, int value, size_t num );
    memset(array_structs_entities,0,sizeof(array_structs_entities) );
    num_entities=0;
}
TEntity* sys_entity_create(){
    TEntity* entity=&array_structs_entities[num_entities];
    ++num_entities;
    return entity;
}
void sys_entity_erase(int i){
   --num_entities;
   //PutSprite(array_structs_entity[i].plano,array_structs_entity[i].sprite,1,215,array_structs_entity[i].color);
  array_structs_entities[i]=array_structs_entities[num_entities];
  //if (num_entities==0) fabricaDeEnemigos();
}
//End life cicle

//Geters & setters
TEntity* sys_entity_get_array_structs_entities(){
    return array_structs_entities;
}
char sys_entity_get_num_entities(){
    return num_entities;
}

char sys_entity_get_max_entities(){
    return MAX_ENTITIES;
}
//End getters & setters




TEntity* sys_entity_create_template(TEntity *template){
    TEntity* entity=sys_entity_create();
    memcpy(entity,template,sizeof(TEntity));
    return entity;
}





