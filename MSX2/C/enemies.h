#ifndef __ENEMIES_H__
#define __ENEMIES_H__


typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char plano;
    unsigned char sprite;
    unsigned char tipo;
}t_enemy;
t_enemy enemigo1={256,212/2, 8,8*4,0};
*/





unsigned char sprite_enemigo1[]={
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
    0x01,0x01,0x07,0x3F,0x3F,0x3F,0x3C,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x80,0x80,0xF0,0xFC,0xFC,0xFC,0x3C,0x3C
};
unsigned char sprite_enemigo2_derecha[]={
    0x00,0x00,0x07,0x1F,0x3F,0x7E,0xFC,0xF0,
    0xFC,0xF0,0x7C,0x3F,0x1F,0x07,0x00,0x00,
    0x00,0x00,0x80,0xE0,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0x80,0xE0,0x80,0x00,0x00
};
unsigned char sprite_enemigo2_izquierda[]={
    0x00,0x00,0x01,0x07,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x01,0x07,0x01,0x00,0x00,
    0x00,0x00,0xE0,0xF8,0xFC,0x7E,0x3F,0x0F,
    0x3F,0x0F,0x3E,0xFC,0xF8,0xE0,0x00,0x00
};



unsigned char color_sprite_enemigo1[]={
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F
};
unsigned char color_sprite_enemigo2_derecha[]={
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F
};
unsigned char color_sprite_enemigo2_izquierda[]={
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
    0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F
};






#endif