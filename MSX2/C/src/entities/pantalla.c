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
void pintarPantallaInicio();
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
//Son 23 filas * 500 columnas

#define numeroFilas 23
#define numeroColumnas 250
#define tamanoBufferTileMap 5750 // numeroFilas*numeroColumnas
//unsigned char bufferTileMap[tamanoBufferTileMap];
unsigned int filas[numeroFilas][numeroColumnas];
int contador_tiles;
unsigned int contador;

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

/*void cargarTileMapEnRAM(){
    FT_SetName( &TFileTileMap, &fileNameTileMap[0] );
    fcb_open( &TFileTileMap );
    //Analizando el archivo word0.bin con un editor hexadecimal vemos que hay que saltar 8 bytes que definen al .bin
    fcb_read( &TFileTileMap, &bufferTileMap[0], 7 );  // Skip 7 first bytes of the file  
    fcb_read( &TFileTileMap, &bufferTileMap[0], tamanoBufferTileMap );  // Read 20 lines of image data (128bytes per line in screen5)
    fcb_close( &TFileTileMap);
}*/
void cargarTileMapEnRAM(){
    FT_SetName( &TFileTileMap, &fileNameTileMap[0] );
    fcb_open( &TFileTileMap );
    //Analizando el archivo word0.bin con un editor hexadecimal vemos que hay que saltar 8 bytes que definen al .bin
    fcb_read( &TFileTileMap, &bufferTileSet[0], 7 );  // Skip 7 first bytes of the file  
    fcb_read( &TFileTileMap, &bufferTileSet[0], tamanoBufferTileMap );  // Read 20 lines of image data (128bytes per line in screen5)
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
  for (int fila=0;fila<numeroFilas;fila++){
    for (int columna=0; columna<numeroColumnas;columna++){
      contador_tiles++;
      //filas[fila][columna]=bufferTileMap[contador_tiles];
      filas[fila][columna]=bufferTileSet[contador_tiles];
    }
  }
}


void recorrerBufferTileMapYPintarPage1EnPage0(){
  contador++;
  for (int f=0; f<numeroFilas;f++){
    HMMM(((filas[f][contador]-(filas[f][contador]/32)*32 ) )*8,(filas[f][contador]/32)*8+256, 256-8,8*f,8,8);
  }
  HMMM(8,0, 0,0,256,184);
}
/*void recorrerBufferTileMapYPintarPage1EnPage0Inversa(){
  contador--;
  for (int f=0; f<numeroFilas;f++){
    HMMM(((filas[f][contador]-(filas[f][contador]/32)*32 ) )*8,(filas[f][contador]/32)*8+256, 0,8*f,8,8);
  }
  HMMM(0,0, 8,0,256,184);
}*/

void pintarPantallaInicio(){
  for (int f=0; f<numeroFilas;f++){
    for (int c=0; c<32;c++){
      HMMM(((filas[f][c]-(filas[f][c]/32)*32))*8,(filas[f][c]/32)*8+256, c*8,f*8,8,8);
    }
  }
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
    //PutText(columna*24,fila,Itoa(fila1[i],"  ",10),8);
    PutText(columna*24,fila,Itoa(filas[22][i],"  ",10),8);
    columna++;
    if (columna==10){
      columna=0;
      fila+=8;
    } 
  }
}