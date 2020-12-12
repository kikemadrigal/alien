//#include "fusion-c/header/msx_fusion.h"
//#include "fusion-c/header/vdp_sprites.h"

#include "fire.h"

//fireX=100; fireY=100; fireVelocidad=4; firePlano=6; fireSprite=4*6; fireColor=15;
//t_fire fire={100,100,4,6,4*6,15};

sprite_disparo[]={
    0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

color_sprite_disparo[]={
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F
};

void inicializar_disparos(){
  //SetSpritePattern( fire.sprite, disparo, 32);
  //PutSprite( fire.plano, fire.sprite, fire.x,fire.y, fire.color );   
  SetSpritePattern( fireSprite, sprite_disparo, 32);
  SC5SpriteColors(firePlano, color_sprite_disparo);
}
void crear_disparos(){
  //fire.x=px;
  //fire.y=py;
}
void actualizar_disparos(){
  //fire.x+=fire.velocidad;
  //PutSprite( fire.plano, fire.sprite, fire.x,fire.y, fire.color );
  fireX+=fireVelocidad;
  PutSprite( firePlano, fireSprite, fireX,fireY, fireColor );
}
void eliminar_disparos(){

}
