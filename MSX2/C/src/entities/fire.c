/**************DECLARACIONES************/
#ifndef __FIRE_H__
#define __FIRE_H__
//INCLUDES

//VARIABLES Y ARRAYS
//char fireX=100, fireY=100, fireVelocidad=4, firePlano=6, fireSprite=4*6, fireColor=15;
typedef struct {
    int x;
    int y;
    int velocidad;
    unsigned char plano;
    unsigned char sprite;
}TFire;
unsigned char fireSprite[]={
    255,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    255,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

//FUNCIONES
void inicializar_disparos();
TFire* crear_disparos();
void actualizar_disparos();
void eliminar_disparos(int i);



#endif
/***********FINAL DE DECLARACIONES*********/

/**************DEFINICIONES************/
//TFire fire_prueba={100,100,4,6,4*6,15};
TFire array_structs_fires[10];
char numero_disparo;

void inicializar_disparos(){
    SetSpritePattern( 4*10, fireSprite, 32);
    numero_disparo=0;
}
TFire* crear_disparos(){
  TFire* fire=&array_structs_fires[numero_disparo];
  ++numero_disparo;
  return fire;
}
void actualizar_disparos(){
  for (int i=0; i<numero_disparo; i++){
    array_structs_fires[i].x+=array_structs_fires[i].velocidad;
    if(array_structs_fires[i].x>256+2) eliminar_disparos(i);
    PutSprite( array_structs_fires[i].plano, array_structs_fires[i].sprite, array_structs_fires[i].x,array_structs_fires[i].y, 15 );
  }
}
void eliminar_disparos(int i){
   --numero_disparo;
  array_structs_fires[i]=array_structs_fires[numero_disparo];
}