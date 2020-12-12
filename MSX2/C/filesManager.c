#include "fusion-c/header/msx_fusion.h"


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
 
void FT_errorHandler(char n, char *name)            // Gère les erreurs
{
  Screen(0);
  SetColors(15,6,6);
  switch (n)
  {
      case 1:
          Print("\n\rFAILED: fcb_open(): ");
          Print(name);
      break;
 
      case 2:
          Print("\n\rFAILED: fcb_close():");
          Print(name);
      break;  
 
      case 3:
          Print("\n\rStop Kidding, run me on MSX2 !");
      break; 
  }
Exit(0);
}
 
int FT_LoadSc5Image(char *file_name, unsigned int start_Y, char *buffer)        // Charge les données d'un fichiers
    {

        int rd=2560;

        FT_SetName( &file, file_name );
        if(fcb_open( &file ) != FCB_SUCCESS) 
        {
              FT_errorHandler(1, file_name);
              return (0);
        }

        fcb_read( &file, buffer, 7 );  // Skip 7 first bytes of the file  
        while (rd!=0)
        {
             rd = fcb_read( &file, buffer, 2560 );  // Read 20 lines of image data (128bytes per line in screen5)
             HMMC(buffer, 0,start_Y,256,20 ); // Move the buffer to VRAM. 
             start_Y=start_Y+20;
         }

return(1);
}