;Rutinas bios http://map.grauw.nl/resources/msxbios.php
;Console routines
CHPUT equ #00A2  ; Escribe un caracter en la pantalla
CHGET equ #009F    ; Se queda esperando que se pulse una tecla   
;VDP routines
DISSCR equ #0041   ; deshabilita la pantalla
ENASCR equ #0044   ; Habilita la pantalla
WRTVDP equ #0047   ; Escribe los datos en los registros del VDP, necesita b=datos, c= numero de registro a modificar   
WRTVRM equ #004D   ; Escribe datos en VRAM, necesita en HL=la dirección VRAM, a=valor       
CHGMOD equ #005F   ; Cambia el modo de screen pero previamente necesita que se le asigne el modo en el registro a
LDIRVM equ #005C   ; Tansfiere bloques de la RAM a la VRAM, es la más importante, necesita previamente asignar valor al registro bc con la longitud, dc con la dirección de inicio de la VRAM y hl con la dirección de inicio de la RAM:
CHGCLR equ #0062   ; esta rutina necesita que se acceda 1a las constanes de FORCLR,BAKCLR y BDRCLR con un ld,hl(FORCLR) obtenemos su posición
;Constantes bios
FORCLR equ 0xF3E9 ; Contiene el color de tinta (+1=color del fondo, +1 color del borde)
BAKCLR equ 0xF3EA ; Contiene el color de fondo o de la página
BDRCLR equ 0xF3EB ; Contiene el colot del borde

GTSTCK equ #00D5   ;si le pasas al registro a un 0 detectará los cursores,un 1 para el joystick 1 y 2 para el joystick 2
                   ;devuelve en a 1 arriba, 2 diagonal arriba derecha,3 derecha, asi hasta 7
GTTRIG equ #00D8 ;necesita en a el boton a comprobar 0 espacio,1 boton A joystick 1, 3 boton b joystick 1, devuelve en a #00 si ha sido pulsado o #FF si no ha sido pulsado
     
RDVDP equ #013E ;   lee  registro de lectura del VDP y lo pone en el registro a


CLIKSW  equ 0xF3DB; para que no se oiga el click que hace al pulsar las teclas
; registros VDP MSX 1
RG0SAV equ	#F3DF   ; Registor 0
RG1SAV equ	#F3E0	; Registro 1
RG2SAV equ	#F3E1	; Registor 2
RG3SAV equ	#F3E2	; Registro 3
RG4SAV equ	#F3E3	; Registro 4
RG5SAV equ	#F3E4	; Registro 5
RG6SAV equ	#F3E5	; Registro 6
RG7SAV equ	#F3E6	; Registro 7
STATFL equ	#F3E7	; Registro de estado VSP MSX 1 


;Constantes del programa
MAXDELAY equ 10