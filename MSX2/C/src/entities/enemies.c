
/**************DECLARACIONES************/
#ifndef __ENEMIES_H__
#define __ENEMIES_H__
//INCLUDES

//VARIABLES Y ARRAYS
typedef struct {
    //Vamos a permitir los signos para que se salga de la pantalla
    int x;
    int y;
    //char es olo 1 byte de 0 a 255 posibles valores
    unsigned char velocidad;
    unsigned char direccion;
    unsigned char plano;
    unsigned char sprite;
    unsigned char color;
    unsigned char tipo;
}TEnemy;

unsigned char enemie1[]={
    0,7,4,4,7,3,1,31,
    50,38,36,40,104,72,72,72,
    0,192,64,64,192,128,0,248,
    76,100,36,54,18,18,18,18
};
unsigned char enemie2[]={
    0,7,4,4,7,3,1,15,
    10,26,18,18,18,18,18,18,
    0,192,64,64,192,128,0,240,
    80,88,72,72,72,72,72,72
};

//FUNCIONES
void inicializar_enemigos();
//Como nostros vamos a gestionar la memoria 1 definimos el espacio y despues devolvemos un puntero a
// la posición del array donde está el struct
TEnemy* crear_enemigos();
void actualizar_enemigos();
void eliminar_enemigos();
#endif
/***********FINAL DE DECLARACIONES************/

/**************DEFINICIONES****************/
//TEnemy enemigo_prueba={256,160,4,8,8*4,3,0};
TEnemy array_structs_enemigos[10];
char numero_de_enemigo;

void inicilizar_enemigos(){
    SetSpritePattern( 4*11, enemie1, 32);
    SetSpritePattern( 4*12, enemie2, 32);
    //Las variables globales tienen que ser inicializadas dentro de un método
    numero_de_enemigo=0;
}
TEnemy* crear_enemigos(){
    TEnemy* enemy=&array_structs_enemigos[numero_de_enemigo];
    ++numero_de_enemigo;
    return enemy;
}
void actualizar_enemigos(){
   for (int i=0; i<numero_de_enemigo;i++){
    array_structs_enemigos[i].x-=1;
    if(array_structs_enemigos[i].x<0) array_structs_enemigos[i].x=255;
    if(array_structs_enemigos[i].x % 2){
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }else{
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite+4,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }
   
   }
}
void eliminar_enemigos(){

}