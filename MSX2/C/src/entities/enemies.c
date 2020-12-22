
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
void eliminar_enemigos(int i);
char collision_enemigos(char fireX, char fireiY);
char generar_numero_aleatorio (char a, char b);
#endif
/***********FINAL DE DECLARACIONES************/

/**************DEFINICIONES****************/
//TEnemy enemigo_prueba={256,160,4,8,8*4,3,0};
TEnemy array_structs_enemigos[10];
char numero_de_enemigo;
char colisionFire;
void inicilizar_enemigos(){
    SetSpritePattern( 4*11, enemie1, 32);
    SetSpritePattern( 4*12, enemie2, 32);
    //Las variables globales tienen que ser inicializadas dentro de un método
    numero_de_enemigo=0;
    colisionFire=0;
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
void eliminar_enemigos(int i){
   --numero_de_enemigo;
  array_structs_enemigos[i]=array_structs_enemigos[numero_de_enemigo];
  PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite,1,215,array_structs_enemigos[i].color);
}

char collision_enemigos(char fireX, char fireiY){
    for (int i=0; i<numero_de_enemigo;i++){
         if (fireX < array_structs_enemigos[i].x + 16 &&  fireX + 16 > array_structs_enemigos[i].x && fireiY < array_structs_enemigos[i].y + 16 && 16 + fireiY > array_structs_enemigos[i].y){
            colisionFire=1;
            eliminar_enemigos(i);
            TEnemy* enemy1=crear_enemigos();
            enemy1->x=255;
            enemy1->y=generar_numero_aleatorio (120,150);
            enemy1->velocidad=4;
            enemy1->direccion=7;
            enemy1->plano=20;
            enemy1->sprite=11*4;
            enemy1->color=6;
            enemy1->tipo=0;
        }else{
            colisionFire=0;
        }
    }  
    return colisionFire;
}


char generar_numero_aleatorio (char a, char b){
  //Time es un struct + typedef con 3 enteros para las horas, minutos y segundos
    //TIME tm;
    char random; 
    //GetTime obtiene la hora del MSDOS y se la asigna al struct TIME
    //GetTime(&tm); 
    //srand utiliza los segundos como semilla para generar un número aleatorio  
    //srand y rand forman parte de la librería stdlib.h normalmente utilizada para castear strings y manejar memoria dinámica         
    //srand(tm.sec);
    random = rand()%(b-a)+a;  
    return(random);
}