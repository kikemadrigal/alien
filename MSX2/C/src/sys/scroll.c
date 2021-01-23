#pragma once
#include "src/man/entity.c"
#include "src/man/graphics.c"


//Declarations
void sys_scroll_init();
void sys_scroll_update(TEntity *entity);


//Definitions
void sys_scroll_init(){

}
void sys_scroll_update(TEntity *entity){
    if ((entity->x/8)>14 && JoystickRead(0)==3){
        recorrerBufferTileMapYPintarPage1EnPage0();
        //Ponemos al player una posición menos
        //entity->x-=8;
    } 
}


