/**************DECLARACIONES************/

//FUNCIONES
//Cargar archivos en memoria RAM y VRAM
void cargarTileSetEnRAM();
void cargarTileMapEnRAM();
//Esto es para asociar un archivo al struct de archivos
void FT_SetName( FCB *p_fcb, const char *p_name );
//Esto me lo he inventado, :)
void cargarArrayFilasTileMap();
void recorrerBufferTileMapYPintarPage1EnPage0();
void deRamAVramPage1(void);
void SetAdjust(signed char x, signed char y);
//VARIABLES Y ARRAYS
char fileNameTilseSet[]="tileset.sc5";
char fileNameTileMap[]="world0.bin";
FCB TFileTileSet;
FCB TFileTileMap;
//En screen5 cada byte define 2 colores, entonces 256px de ancho/2=128 bytes*212 filas=27136 bytes para definir una page
//En el ejemplo de fusion c cada 20 líneas son 2560 bytes
#define tamanobufferTileSet 27136
unsigned char bufferTileSet[tamanobufferTileSet];
//El tile map solo son bytes que identifican un valor correpondiente a cada fila y cada columna
//Son 24 filas * 100 columnas
#define tamanoBufferTileMap 2400
unsigned char bufferTileMap[tamanoBufferTileMap];
//unsigned int filas[24][100];
unsigned int fila1[100];
unsigned int fila2[100];
unsigned int fila3[100];
unsigned int fila4[100];
unsigned int fila5[100];
unsigned int fila6[100];
unsigned int fila7[100];
unsigned int fila8[100];
unsigned int fila9[100];
unsigned int fila10[100];
unsigned int fila11[100];
unsigned int fila12[100];
unsigned int fila13[100];
unsigned int fila14[100];
unsigned int fila15[100];
unsigned int fila16[100];
unsigned int fila17[100];
unsigned int fila18[100];
unsigned int fila19[100];
unsigned int fila20[100];
unsigned int fila21[100];
unsigned int fila22[100];
unsigned int fila23[100];
unsigned int fila24[100];

unsigned int contador=0;

/********FINAL DE DECLARAIONES***********/




/**************DEFINICIONES************/
void cargarTileSetEnRAM(){
    //Cargamos el archivo en la estructura
    FT_SetName( &TFileTileSet, &fileNameTilseSet[0] );
    fcb_open( &TFileTileSet );
    //Sino omitimos los 7 primeros bytes (los que defininen la estructura del binario) aparecen  unas marcas arriba a la derecha
    fcb_read( &TFileTileSet, &bufferTileSet[0], 7 ); 
    //Cargamos el archivo definido en la estructura y lo ponemos en la RAM (buffer)
    fcb_read( &TFileTileSet, &bufferTileSet[0], tamanobufferTileSet );  
    fcb_close( &TFileTileSet );
}

void cargarTileMapEnRAM(){
    FT_SetName( &TFileTileMap, &fileNameTileMap[0] );
    fcb_open( &TFileTileMap );
    //Analizando el archivo word0.bin con un editor hexadecimal vemos que hay que saltar 8 bytes que definen al .bin
    fcb_read( &TFileTileMap, &bufferTileMap[0], 8 );  // Skip 7 first bytes of the file  
    fcb_read( &TFileTileMap, &bufferTileMap[0], tamanoBufferTileMap );  // Read 20 lines of image data (128bytes per line in screen5)
    fcb_close( &TFileTileMap);
}

void deRamAVramPage1(void){
  //HMMC transfiere bloques de RAM a VRAM rápidamente en un area rectangular, ver www.tipolisto.es/files/v9938 página 66
  //HMMM(buffer en RAM, posición_x, posición_Y (256 será la page 1), ancho copia, alto copia)
  HMMC(&bufferTileSet[0], 0,256,256,212 ); 
}



void FT_SetName( FCB *p_fcb, const char *p_name )  // Routine servant à vérifier le format du nom de fichier
{
  char i, j;
  memset( p_fcb, 0, sizeof(FCB) );
  for( i = 0; i < 11; i++ ) {
    p_fcb->name[i] = ' ';
  }
  for( i = 0; (i < 8) && (p_name[i] != 0) && (p_name[i] != '.'); i++ ) {
    p_fcb->name[i] =  p_name[i];
  }
  if( p_name[i] == '.' ) {
    i++;
    for( j = 0; (j < 3) && (p_name[i + j] != 0) && (p_name[i + j] != '.'); j++ ) {
      p_fcb->ext[j] =  p_name[i + j] ;
    }
  }
}


void cargarArrayFilasTileMap(){
  //int contador_tiles=0;
  int contador_fila2,contador_fila3,contador_fila4,contador_fila5,contador_fila6,contador_fila7,contador_fila8,contador_fila9;
  int contador_fila10,contador_fila11,contador_fila12,contador_fila13,contador_fila14,contador_fila15,contador_fila16,contador_fila17,contador_fila18,contador_fila19;
  int contador_fila20,contador_fila21,contador_fila22,contador_fila23,contador_fila24;
  contador_fila2=0;contador_fila3=0;contador_fila4=0;contador_fila5=0;contador_fila6=0;contador_fila7=0;contador_fila8=0;contador_fila9=0;
  contador_fila10=0;contador_fila11=0;contador_fila12=0;contador_fila13=0;contador_fila14=0;contador_fila15=0;contador_fila16=0;contador_fila17=0;contador_fila18=0;contador_fila19=0;
  contador_fila20=0;contador_fila21=0;contador_fila22=0;contador_fila23=0;contador_fila24=0;

  //for (int f=0; f<25;f++){
  //  contador_tiles++;
  //  for (int c=0; c<100;c++){
  //    filas[f][c]=bufferTileMap[contador_tiles];
  //  }
  //}


  for (int i=0; i<100;i++){
    fila1[i]=bufferTileMap[i];
  }
  for (int i=100; i<200;i++){
    contador_fila2++;
    fila2[contador_fila2]=bufferTileMap[i];
  }
  for (int i=200; i<300;i++){
    contador_fila3++;
    fila3[contador_fila3]=bufferTileMap[i];
  }
  for (int i=100*3; i<100*4;i++){
    contador_fila4++;
    fila4[contador_fila4]=bufferTileMap[i];
  }
  for (int i=100*4; i<100*5;i++){
    contador_fila5++;
    fila5[contador_fila5]=bufferTileMap[i];
  }
  for (int i=100*5; i<100*6;i++){
    contador_fila6++;
    fila6[contador_fila6]=bufferTileMap[i];
  }
  for (int i=100*6; i<100*7;i++){
    contador_fila7++;
    fila7[contador_fila7]=bufferTileMap[i];
  }
  for (int i=100*7; i<100*8;i++){
    contador_fila8++;
    fila8[contador_fila8]=bufferTileMap[i];
  }
  for (int i=100*8; i<100*9;i++){
    contador_fila9++;
    fila9[contador_fila9]=bufferTileMap[i];
  }
  for (int i=100*9; i<100*10;i++){
    contador_fila10++;
    fila10[contador_fila10]=bufferTileMap[i];
  }
  for (int i=100*10; i<100*11;i++){
    contador_fila11++;
    fila11[contador_fila11]=bufferTileMap[i];
  }
  for (int i=100*11; i<100*12;i++){
    contador_fila12++;
    fila12[contador_fila12]=bufferTileMap[i];
  }
  for (int i=100*12; i<100*13;i++){
    contador_fila13++;
    fila13[contador_fila13]=bufferTileMap[i];
  }
  for (int i=100*13; i<100*14;i++){
    contador_fila14++;
    fila14[contador_fila14]=bufferTileMap[i];
  }
  for (int i=100*14; i<100*15;i++){
    contador_fila15++;
    fila15[contador_fila15]=bufferTileMap[i];
  }
  for (int i=100*15; i<100*16;i++){
    contador_fila16++;
    fila16[contador_fila16]=bufferTileMap[i];
  }
    for (int i=100*16; i<100*17;i++){
    contador_fila17++;
    fila17[contador_fila17]=bufferTileMap[i];
  }
    for (int i=100*17; i<100*18;i++){
    contador_fila18++;
    fila18[contador_fila18]=bufferTileMap[i];
  }
    for (int i=100*18; i<100*19;i++){
    contador_fila19++;
    fila19[contador_fila19]=bufferTileMap[i];
  }
    for (int i=100*19; i<100*20;i++){
    contador_fila20++;
    fila20[contador_fila20]=bufferTileMap[i];
  }
    for (int i=100*20; i<100*21;i++){
    contador_fila21++;
    fila21[contador_fila21]=bufferTileMap[i];
  }
  for (int i=100*21; i<100*22;i++){
    contador_fila22++;
    fila22[contador_fila22]=bufferTileMap[i];
  }
  for (int i=100*22; i<100*23;i++){
    contador_fila23++;
    fila23[contador_fila23]=bufferTileMap[i];
  }
  for (int i=100*23; i<100*24;i++){
    contador_fila24++;
    fila24[contador_fila24]=bufferTileMap[i];
  }
}





void recorrerBufferTileMapYPintarPage1EnPage0(){
  contador++;
    //Esto dará la fila en el caso de 148 la fila 4
    //for (int f=0; f<25;f++){
    //  HMMM(-( ( ( (filas[f][contador]/32 ) )*32 )-filas[f][contador] )*8,(filas[f][contador]/32)*8+256, 256-8,8*f,8,8);
    //}
    HMMM(-( ( ( (fila1[contador]/32 ) )*32 )-fila1[contador] )*8,(fila1[contador]/32)*8+256, 256-8,8*1,8,8);
    HMMM(-( ( ( (fila2[contador]/32 ) )*32 )-fila2[contador] )*8,(fila2[contador]/32)*8+256, 256-8,8*2,8,8);
    HMMM(-( ( ( (fila3[contador]/32 ) )*32 )-fila3[contador] )*8,(fila3[contador]/32)*8+256, 256-8,8*3,8,8);
    HMMM(-( ( ( (fila4[contador]/32 ) )*32 )-fila4[contador] )*8,(fila4[contador]/32)*8+256, 256-8,8*4,8,8);
    HMMM(-( ( ( (fila5[contador]/32 ) )*32 )-fila5[contador] )*8,(fila5[contador]/32)*8+256, 256-8,8*5,8,8);
    HMMM(-( ( ( (fila6[contador]/32 ) )*32 )-fila6[contador] )*8,(fila6[contador]/32)*8+256, 256-8,8*6,8,8);
    HMMM(-( ( ( (fila7[contador]/32 ) )*32 )-fila7[contador] )*8,(fila7[contador]/32)*8+256, 256-8,8*7,8,8);
    HMMM(-( ( ( (fila8[contador]/32 ) )*32 )-fila8[contador] )*8,(fila8[contador]/32)*8+256, 256-8,8*8,8,8);
    HMMM(-( ( ( (fila9[contador]/32 ) )*32 )-fila9[contador] )*8,(fila9[contador]/32)*8+256, 256-8,8*9,8,8);
    HMMM(-( ( ( (fila10[contador]/32 ) )*32 )-fila10[contador] )*8,(fila10[contador]/32)*8+256, 256-8,8*10,8,8);
    HMMM(-( ( ( (fila11[contador]/32 ) )*32 )-fila11[contador] )*8,(fila11[contador]/32)*8+256, 256-8,8*11,8,8);
    HMMM(-( ( ( (fila12[contador]/32 ) )*32 )-fila12[contador] )*8,(fila12[contador]/32)*8+256, 256-8,8*12,8,8);
    HMMM(-( ( ( (fila13[contador]/32 ) )*32 )-fila13[contador] )*8,(fila13[contador]/32)*8+256, 256-8,8*13,8,8);
    HMMM(-( ( ( (fila14[contador]/32 ) )*32 )-fila14[contador] )*8,(fila14[contador]/32)*8+256, 256-8,8*14,8,8);
    HMMM(-( ( ( (fila15[contador]/32 ) )*32 )-fila15[contador] )*8,(fila15[contador]/32)*8+256, 256-8,8*15,8,8);
    HMMM(-( ( ( (fila16[contador]/32 ) )*32 )-fila16[contador] )*8,(fila16[contador]/32)*8+256, 256-8,8*16,8,8);
    HMMM(-( ( ( (fila17[contador]/32 ) )*32 )-fila17[contador] )*8,(fila17[contador]/32)*8+256, 256-8,8*17,8,8);
    HMMM(-( ( ( (fila18[contador]/32 ) )*32 )-fila18[contador] )*8,(fila18[contador]/32)*8+256, 256-8,8*18,8,8);
    HMMM(-( ( ( (fila19[contador]/32 ) )*32 )-fila19[contador] )*8,(fila19[contador]/32)*8+256, 256-8,8*19,8,8);
    HMMM(-( ( ( (fila20[contador]/32 ) )*32 )-fila20[contador] )*8,(fila20[contador]/32)*8+256, 256-8,8*20,8,8);
    HMMM(-( ( ( (fila21[contador]/32 ) )*32 )-fila21[contador] )*8,(fila21[contador]/32)*8+256, 256-8,8*21,8,8);
    HMMM(-( ( ( (fila22[contador]/32 ) )*32 )-fila22[contador] )*8,(fila22[contador]/32)*8+256, 256-8,8*22,8,8);
    HMMM(-( ( ( (fila23[contador]/32 ) )*32 )-fila23[contador] )*8,(fila23[contador]/32)*8+256, 256-8,8*23,8,8);
    HMMM(-( ( ( (fila24[contador]/32 ) )*32 )-fila24[contador] )*8,(fila24[contador]/32)*8+256, 256-8,8*24,8,8);

  //}
  //desplazamiento+=2;
  //if (desplazamiento>16) desplazamiento=0; 
  //HMMM(2,16, 0,16,256,64);
  //HMMM(2,212-64, 0,212-64,256,64);
  //if (i%8==0){
    HMMM(8,0, 0,0,256,212);
  //} 
}








void SetAdjust(signed char x, signed char y) // x and y must be between -7 and +6
{
    char vx,vy,value;
      vx=x;
      if (x<0)
        vx=16+x;
      vy=y;
      if (y<0)
        vy=16+y;
      value = (vy<<4) | vx ;
      Poke(0xFFF1,value);     // Reg 18 Save
      VDPwrite(18,value);
}
void verArray(){
  int columna=0;
  int fila=0;
  for (int i=0; i<0x20; i++){
    //PutText(i*8,0,Itoa(bufferTileMap[i],"  ",10),8);
    //PutText(columna*24,fila,Itoa(fila24[i],"  ",10),8);
    columna++;
    if (columna==10){
      columna=0;
      fila+=8;
    } 
  }
}