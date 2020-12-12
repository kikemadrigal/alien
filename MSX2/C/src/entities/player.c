/**************DECLARACIONES************/
#ifndef __PLAYER_H__
#define __PLAYER_H__
//INCLUDES

//FUNCIONES
void inicializar_player();
void actualizar_personaje();
//VARIABLES (los arrays y primitos deben de ser ya inicializados)
unsigned char px=10,py=212/2,pplano=0,psprite=0,pcolor=6,pvelocidad=4,penergia=100;
typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char plano;
    unsigned char sprite;
    unsigned char color;
    unsigned char velocidad;
    unsigned char energia;
} TPlayer;

unsigned char personaje_tronco_superior_derecha1[]={
    3,7,6,7,1,7,29,57,
    60,31,7,1,12,14,6,6,
    192,64,0,0,128,160,160,128,
    0,0,128,204,0,192,224,224
};
unsigned char personaje_tronco_superior_derecha2[]={
    0,0,1,1,0,0,1,1,
    0,0,0,0,0,0,0,0,
    0,192,224,192,0,64,224,240,
    216,0,3,0,0,0,0,0
};
unsigned char personaje_piernas_derecha1[]={
    7,14,14,14,14,28,28,2,
    30,28,60,56,48,112,120,252,
    224,112,120,56,56,56,48,56,
    56,8,56,48,56,24,60,63
};
unsigned char personaje_piernas_derecha2[]={
    7,14,15,15,7,7,7,7,
    7,7,7,95,127,97,51,7,
    192,112,112,48,176,176,240,224,
    192,192,128,128,128,128,128,224
};
unsigned char arma_derecha[]={
    15,112,255,127,31,4,28,16,
    16,0,0,0,0,0,0,0,
    128,224,255,247,128,0,0,0,
    0,0,0,0,0,0,0,0
};
unsigned char personaje_tronco_superior_izquieda1[]={
    3,2,0,0,1,5,5,1,
    0,0,1,51,0,3,7,7,
    192,224,96,224,128,224,184,156,
    60,248,224,128,48,112,96,96
};
unsigned char personaje_tronco_superior_izquierda2[]={
    0,3,7,3,0,2,7,15,
    27,0,192,0,0,0,0,0,
    0,0,128,128,0,0,128,128,
    0,0,0,0,0,0,0,0
};
unsigned char personaje_piernas_izquierda1[]={
    7,14,30,28,28,28,12,28,
    28,16,28,12,28,24,60,252,
    224,112,112,112,112,56,56,64,
    120,56,60,28,12,14,30,63
};
unsigned char personaje_piernas_izquierda2[]={
    3,14,14,12,13,13,15,7,
    3,3,1,1,1,1,1,7,
    224,112,240,240,224,224,224,224,
    224,224,224,250,254,134,204,224
};
unsigned char arma_izquierda[]={
    1,7,255,239,1,0,0,0,
    0,0,0,0,0,0,0,0,
    240,14,255,254,248,32,56,8,
    8,0,0,0,0,0,0,0
};

#endif
/***********FINAL DE DECLARACIONES************/



/**************DEFINICIONES************/
TPlayer player={10,18*8,0,0,6,4,100};

void inicializar_player(){
    //py=212/2;
    // px= player posición eje x, py= player posición eje y
    // pv player velocidad, pm= player movimiento (se obtiene del teclado)
    // lo metemos en la tabla de dEfinición de patrones
    // el 1 argumento es la posición en la poisión en la tabla de definición de sprites (sprite pattern),tenemos que ir sumando 4 porque fusion c es asi
    // el 2 argumentos son los datos del sprite
    // el 3 argumento es el numero de bytes del patron
    SetSpritePattern( 0, personaje_tronco_superior_derecha1, 32);
    SetSpritePattern( 4, personaje_tronco_superior_derecha2, 32);
    SetSpritePattern( 4*2, personaje_piernas_derecha1, 32);
    SetSpritePattern( 4*3, personaje_piernas_derecha2, 32);
    SetSpritePattern( 4*4, arma_derecha, 32);
    SetSpritePattern( 4*5, personaje_tronco_superior_izquieda1, 32);
    SetSpritePattern( 4*6, personaje_tronco_superior_izquierda2, 32);
    SetSpritePattern( 4*7, personaje_piernas_izquierda1, 32);
    SetSpritePattern( 4*8, personaje_piernas_izquierda2, 32);
    SetSpritePattern( 4*9, arma_izquierda, 32);

    //Le ponemos el color al sprite
    //SC5SpriteColors(pplano, color_sprite_nave_derecha1);
    //SC5SpriteColors(pplano+1, color_sprite_nave_derecha2);
    // Sobre PutSprite, si queremos podemos hacer que se vea ya el sprite del personaje con
    // 1 El plano o su definición en la tabla de atributos, es donde alamcenará la posición x e y, y su sprite
    // 2 la definición en sprite pattern que va de 4 en 4
    // 3 posición eje x
    // 4 posición eje y
    // 5 color  
    // PutSprite( pplano,psprite,px,py, pcolor );
    // PutSprite( pplano+1,psprite+4,px,py, pcolor+1 );
    
}
void actualizar_personaje(){
    //Plano, ptron, x, y, color
    //PutSprite( pplano, psprite, px,py, pcolor );
    //PutSprite( pplano+1, psprite+4, px,py, pcolor+1 );
    //Pintamos el tronco superior, color 9 rosa
    PutSprite( player.plano, player.sprite, player.x,player.y, 9 );
    //Pintamos el tronco superior 2, color amarillo 10
    PutSprite( player.plano+1, player.sprite+4, player.x,player.y, 10 );
    //Pintamos las piernas
    PutSprite( player.plano+2, player.sprite+8, player.x,player.y+16, 9 );
    //Pintamos el arma
    PutSprite( player.plano+3, player.sprite+16, player.x,player.y+8, 15 );
}
