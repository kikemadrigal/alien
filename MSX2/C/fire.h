#ifndef __FIRE_H__
#define __FIRE_H__

#include "fusion-c/header/msx_fusion.h"
#include "fusion-c/header/vdp_sprites.h"




void inicializar_disparos();
void crear_disparos();
void actualizar_disparos();
void eliminar_disparos();
//char fireX=100, fireY=100, fireVelocidad=4, firePlano=6, fireSprite=4*6, fireColor=15;
//char fireX, fireY, fireVelocidad, firePlano, fireSprite, fireColor;

/*typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char velocidad;
    unsigned char plano;
    //Recuerda siempre multiplizar por 4, como en la línea que hay para la inicilización del struct
    unsigned char sprite;
    unsigned char color;
}t_fire;

*/

unsigned char sprite_disparo[32];

unsigned char color_sprite_disparo[16];




#endif