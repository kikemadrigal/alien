        output "main.bin"   ; debemos de poner esta instrucción o nos generaría un archivo.out, ponle espacios al principio
        
    db   0FEh              
    dw   INICIO          
    dw   FINAL     
    dw   MAIN               
    org 33280               ;&h8200
INICIO:
 

MAIN:
    call inicializar_pantalla
    call cargar_tiles_colores_y_mapa_en_VRAM
    call inicializar_entidades
    call cargar_sprites
    
.loop
[3] halt
    call input_system
    call poner_sprite_player_atributos_en_VRAM
    jr .loop ; se queda en un bucle infinito
  
     

cargar_sprites:
    call poner_sprites_player_en_VRAM
    ret
inicializar_entidades:
    call inicializacion_variables_player_sprite
    call poner_sprite_player_atributos_en_VRAM
    ret   


input_system:
    di
    ld a,0
    call GTSTCK
    
    ;cp 1
    ;jp z, saltar_player
    cp 3
    jp z, mover_player_derecha
    cp 7
    jp z, mover_player_izquierda
    ei

    ret

	  
include "bios.as"
include "screen.as"
include "player.as"


FINAL: