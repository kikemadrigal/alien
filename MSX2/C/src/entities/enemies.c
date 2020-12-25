
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

unsigned char enemigo1[]={
    7,4,4,7,3,1,31,50,
    38,36,40,104,72,72,0,127,
    192,64,64,192,128,0,248,76,
    100,36,54,18,18,18,0,254
};
unsigned char enemigo1andando[]={
    7,4,4,7,3,1,15,10,
    26,18,18,18,18,0,0,31,
    192,64,64,192,128,0,240,80,
    88,72,72,72,72,0,0,248
};
unsigned char enemigo2[]={
    4,4,4,7,7,63,34,2,
    63,34,98,66,0,127,0,0,
    32,32,32,224,224,252,68,64,
    252,68,70,66,0,254,0,0
};

unsigned char enemigo2andando[]={
    4,4,4,7,7,7,14,10,
    7,6,14,10,0,15,0,0,
    32,32,32,224,224,224,112,80
};
unsigned char enemigo3[]={
  124,68,68,124,8,12,2,1,
    1,1,63,33,99,98,0,127,
    62,34,34,62,32,96,64,128,
    128,128,252,132,196,68,0,252
};

unsigned char enemigo3andando[]={
  124,68,68,124,2,1,1,1,
    1,1,7,10,10,10,0,15,
    62,34,34,126,64,128,128,128,
    128,128,224,80,80,80,0,240
};
unsigned char enemigo4[]={
    2,2,3,65,97,63,1,63,
    97,65,3,61,33,33,0,61,
    64,64,192,130,134,252,128,248,
    140,132,192,188,132,132,0,188
};

unsigned char enemigo4andando[]={
   2,2,3,1,1,7,5,15,    
    9,9,7,9,9,9,0,15,
    64,64,192,128,128,224,160,240,
    144,144,224,144,144,144,0,240
};





// SPRITE COLORS
unsigned char colorEnemigo1[]={
    8,8,8,8,8,8,8,8,
    8,8,8,10,10,10,10,1
};
unsigned char colorEnemigo1Andando[]={
    8,8,8,8,8,8,8,8,
    8,10,10,10,10,10,10,1
};
unsigned char colorEnemigo2[]={
    8,8,8,8,8,8,8,8,
    10,10,10,10,15,0,15,15
};
unsigned char colorEnemigo2Andando[]={
    8,8,8,8,8,8,8,8,
    8,8,10,10,15,1,15,15
};
unsigned char colorEnemigo3[]={
    8,8,8,8,8,8,8,8,
    8,8,8,8,8,10,10,1
};
unsigned char colorEnemigo3Andando[]={
    8,8,8,8,8,8,8,8,
    8,8,8,10,10,10,15,1
};
unsigned char colorEnemigo4[]={
    8,8,8,8,8,8,8,8,
    8,8,8,10,10,10,10,1
};
unsigned char colorEnemigo4Andando[]={
    8,8,8,8,8,8,8,10,
    10,10,8,10,10,10,10,1
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
    SetSpritePattern( 4*20, enemigo1, 32);
    SetSpritePattern( 4*21, enemigo1andando, 32);
    SetSpritePattern( 4*22, enemigo2, 32);
    SetSpritePattern( 4*23, enemigo2andando, 32);
    SetSpritePattern( 4*24, enemigo3, 32);
    SetSpritePattern( 4*25, enemigo3andando, 32);
    SetSpritePattern( 4*26, enemigo4, 32);
    SetSpritePattern( 4*27, enemigo4andando, 32);

    SC5SpriteColors( 20, colorEnemigo1);
    SC5SpriteColors( 21, colorEnemigo1Andando);
    SC5SpriteColors( 22, colorEnemigo2);
    SC5SpriteColors( 23, colorEnemigo2Andando);
    SC5SpriteColors( 24, colorEnemigo3);
    SC5SpriteColors( 25, colorEnemigo3Andando);
    SC5SpriteColors( 26, colorEnemigo4);
    SC5SpriteColors( 27, colorEnemigo4Andando);

    //Las variables globales tienen que ser inicializadas dentro de un método
    numero_de_enemigo=0;
    colisionFire=0;
}
TEnemy* crear_enemigos(){
    TEnemy* enemy=&array_structs_enemigos[numero_de_enemigo];
    ++numero_de_enemigo;
    return enemy;
}



void fabricaDeEnemigos(){
    TEnemy* enemy1=crear_enemigos();
    enemy1->x=255;
    enemy1->y=19*8;
    enemy1->velocidad=13;
    enemy1->direccion=7;
    enemy1->plano=20;
    enemy1->sprite=20*4;
    enemy1->color=9;
    enemy1->tipo=0;

    TEnemy* enemy2=crear_enemigos();
    enemy2->x=1;
    enemy2->y=135;
    enemy2->velocidad=13;
    enemy2->direccion=3;
    enemy2->plano=21;
    enemy2->sprite=21*4;
    enemy2->color=2;
    enemy2->tipo=0;

    TEnemy* enemy3=crear_enemigos();
    enemy3->x=255;
    enemy3->y=120;
    enemy3->velocidad=13;
    enemy3->direccion=7;
    enemy3->plano=22;
    enemy3->sprite=22*4;
    enemy3->color=6;
    enemy3->tipo=0;

    TEnemy* enemy4=crear_enemigos();
    enemy4->x=1;
    enemy4->y=130;
    enemy4->velocidad=13;
    enemy4->direccion=3;
    enemy4->plano=23;
    enemy4->sprite=23*4;
    enemy4->color=3;
    enemy4->tipo=0;
}

void actualizar_enemigos(){
   for (int i=0; i<numero_de_enemigo;i++){
       //Si se mueve a la derecha
    if(array_structs_enemigos[i].direccion==3){
        array_structs_enemigos[i].x-=array_structs_enemigos[i].velocidad;
        if(array_structs_enemigos[i].x<0){
            array_structs_enemigos[i].x=255;
            array_structs_enemigos[i].y=generar_numero_aleatorio (100,150);
            array_structs_enemigos[i].color=generar_numero_aleatorio (0, 14);
        } 
    }
   if(array_structs_enemigos[i].direccion==7){
        array_structs_enemigos[i].x+=array_structs_enemigos[i].velocidad;
        if(array_structs_enemigos[i].x>240){
            array_structs_enemigos[i].x=0;
            array_structs_enemigos[i].y=generar_numero_aleatorio (100,150);
            array_structs_enemigos[i].color=generar_numero_aleatorio (0, 14);
        } 
    }
    
    if(array_structs_enemigos[i].x % 2){
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }else{
         PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite+4,array_structs_enemigos[i].x,array_structs_enemigos[i].y,array_structs_enemigos[i].color);
    }
   
   }
}
void eliminar_enemigos(int i){
   --numero_de_enemigo;
   PutSprite(array_structs_enemigos[i].plano,array_structs_enemigos[i].sprite,1,215,array_structs_enemigos[i].color);
  //array_structs_enemigos[i].x=array_structs_enemigos[numero_de_enemigo].x;
  //array_structs_enemigos[i].y=array_structs_enemigos[numero_de_enemigo].y;
  //array_structs_enemigos[i].velocidad=array_structs_enemigos[numero_de_enemigo].velocidad;
  //array_structs_enemigos[i].direccion=array_structs_enemigos[numero_de_enemigo].direccion;
  //array_structs_enemigos[i].plano=array_structs_enemigos[numero_de_enemigo].plano;
  //array_structs_enemigos[i].color=array_structs_enemigos[numero_de_enemigo].color;
  //array_structs_enemigos[i].tipo=array_structs_enemigos[numero_de_enemigo].tipo;
  array_structs_enemigos[i]=array_structs_enemigos[numero_de_enemigo];
  if (numero_de_enemigo==0) fabricaDeEnemigos();
}


char collision_enemigos(char fireX, char fireiY){
    for (int i=0; i<numero_de_enemigo;i++){
         if (fireX < array_structs_enemigos[i].x + 16 &&  fireX + 16 > array_structs_enemigos[i].x && fireiY < array_structs_enemigos[i].y + 16 && 16 + fireiY > array_structs_enemigos[i].y){
            colisionFire=1;
            eliminar_enemigos(i);
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