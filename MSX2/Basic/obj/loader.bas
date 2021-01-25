1 'MSX 2'
1 'Inicilizamos dispositivo: 003B, inicilizamos teclado: 003E'
10 defusr=&h003B:a=usr(0):defusr1=&h003E:a=usr1(0):defusr2=&H90:a=usr2(0)
20 defusr3=&H41:defusr4=&H44
1 ' color letra negro, fondo letra: azul claro, borde blanco, quitamos las letras que aparecen abajo'
30 color 15,1,1:key off:defint a-z
40 screen 5,2,0
1 'ponemos la pantalla de carga'
45 bload"loader.sc5",s
50 open "grp:" as #1
60 print #1,"Loading xbasic"
70 bload"xbasic.bin",r
80 print #1,"Loading sprites"
1 'Cargamos los sprites'
90 gosub 10000
100 'print #1,"Loading tilemap word 0"
110 'dim mf(512,9):gosub 11100
120 print #1,"Cargando tileset"
130 bload"tileset.sc5",s,32768
500 print #1,"Loading game"
510 load"game.bas",r




1 '---------------------------------------------------------'
1 '------------------------Carga de srites------------------'
1 '---------------------------------------------------------'


1 ' Patrones:'
1 'Plano 0. Player--sprites del 1 al 7'
1 'Rutina cargar sprites con datas basic'
    10000 RESTORE
    1 ' vamos a meter 5 definiciones de sprites nuevos que serán 4 para el personaje y uno para la bola'
    10010 FOR I=0 TO 18:SP$=""
        10020 FOR J=1 TO 32:READ A$
            10025 SP$=SP$+CHR$(VAL(A$))
        10030 NEXT J
        10040 SPRITE$(I)=SP$
    10050 NEXT I
    10060 return 





    1 '0-Personaje parte superior 1 derecha'
    10120 DATA 3,7,6,7,1,7,29,57
    10130 DATA 60,31,7,1,12,14,6,6
    10140 DATA 192,64,0,0,128,160,160,128
    10150 DATA 0,0,128,204,0,192,224,224
    1 '1-Personaje parte superior 2 derecha'
    10160 DATA 0,0,1,1,0,0,1,1
    10170 DATA 0,0,0,0,0,0,0,0
    10180 DATA 0,192,224,192,0,64,224,240
    10190 DATA 216,0,3,0,0,0,0,0
     1 '2-Personaje piernas 1 derecha'
    10200 DATA 7,14,14,14,14,28,28,2
    10210 DATA 30,28,60,56,48,112,120,252
    10220 DATA 224,112,120,56,56,56,48,56
    10230 DATA 56,8,56,48,56,24,60,63
    1 '3-Personaje piernas 2 derecha'
    10240 DATA 7,14,15,15,7,7,7,7
    10250 DATA 7,7,7,95,127,97,51,7
    10260 DATA 192,112,112,48,176,176,240,224
    10270 DATA 192,192,128,128,128,128,128,224
    1 '4-Arma derecha'
    10280 DATA 15,112,255,127,31,4,28,16
    10290 DATA 16,0,0,0,0,0,0,0
    10300 DATA 128,224,255,247,128,0,0,0
    10310 DATA 0,0,0,0,0,0,0,0

    1 '5-Personaje parte superior 1 izquierda'
    10320 DATA 3,2,0,0,1,5,5,1
    10330 DATA 0,0,1,51,0,3,7,7
    10340 DATA 192,224,96,224,128,224,184,156
    10350 DATA 60,248,224,128,48,112,96,96
    1 '6-Personaje parte superior 2 izquierda'
    10360 DATA 0,3,7,3,0,2,7,15
    10370 DATA 27,0,192,0,0,0,0,0
    10380 DATA 0,0,128,128,0,0,128,128
    10390 DATA 0,0,0,0,0,0,0,0
    1 '7-Personaje piernas 1 izquierda'
    10400 DATA 7,14,30,28,28,28,12,28
    10410 DATA 28,16,28,12,28,24,60,252
    10420 DATA 224,112,112,112,112,56,56,64
    10430 DATA 120,56,60,28,12,14,30,63
    1 '8-Personaje piernas 2 izquierda'
    10440 DATA 3,14,14,12,13,13,15,7
    10450 DATA 3,3,1,1,1,1,1,7
    10460 DATA 224,112,240,240,224,224,224,224
    10470 DATA 224,224,224,250,254,134,204,224
    1 '9-Arma izquierda'
    10480 DATA 1,7,255,239,1,0,0,0
    10490 DATA 0,0,0,0,0,0,0,0
    10500 DATA 240,14,255,254,248,32,56,8
    10510 DATA 8,0,0,0,0,0,0,0
    1 '10-Disparo'
    10520 DATA 255,0,0,0,0,0,0,0
    10530 DATA 0,0,0,0,0,0,0,0
    10540 DATA 255,0,0,0,0,0,0,0
    10550 DATA 0,0,0,0,0,0,0,0
    1 '-11 enemigo1-1'
    10560 DATA 7,4,4,7,3,1,31,50
    10570 DATA 38,36,40,104,72,72,0,127
    10580 DATA 192,64,64,192,128,0,248,76
    10590 DATA 100,36,54,18,18,18,0,254
    1 '12- enemeigo1-2'
    10600 DATA 7,4,4,7,3,1,15,10
    10610 DATA 26,18,18,18,18,0,0,31
    10620 DATA 192,64,64,192,128,0,240,80
    10630 DATA 88,72,72,72,72,0,0,248
    1 '13-nemigo 2-1'
    10640 DATA 4,4,4,7,7,63,34,2
    10650 DATA 63,34,98,66,0,127,0,0
    10660 DATA 32,32,32,224,224,252,68,64
    10670 DATA 252,68,70,66,0,254,0,0
    1 '14-enemigo 2-2'
    10680 DATA 4,4,4,7,7,7,14,10
    10690 DATA 7,6,14,10,0,0,15,0
    10700 DATA 32,32,32,224,224,224,112,80
    10710 DATA 224,96,112,80,0,0,240,0
    1 '15-enemigo 3-1'
    10720 DATA 124,68,68,124,8,12,2,1
    10730 DATA 1,1,63,33,99,98,0,127
    10740 DATA 62,34,34,62,32,96,64,128
    10750 DATA 128,128,252,132,196,68,0,252
    1 '16-enemigo 3-2'
    10760 DATA 124,68,68,124,2,1,1,1
    10770 DATA 1,1,7,10,10,10,0,15
    10780 DATA 62,34,34,126,64,128,128,128
    10790 DATA 128,128,224,80,80,80,0,240
    1 '17-enemigo 4-1'
    10800 DATA 2,2,3,65,97,63,1,63
    10810 DATA 97,65,3,61,33,33,0,61
    10820 DATA 64,64,192,130,134,252,128,248
    10830 DATA 140,132,192,188,132,132,0,188
    1 '18-enemigo 4-2'
    10840 DATA 2,2,3,1,1,7,5,15
    10850 DATA 9,9,7,9,9,9,0,15
    10860 DATA 64,64,192,128,128,224,160,240
    10870 DATA 144,144,224,144,144,144,0,240







10900 return



1 'Cargar mundo con los mapas de los niveles en el buffer o array'
    11100 bload"world0.bin",r
    11110 md=&hd001
    11120 for f=0 to 24-1
        11130 for c=0 to 100-1
            11140 tn=peek(md):md=md+1
            11150 m(c,f)=tn
        11170 next c
    11180 next f
11190 return



1 '1 'Cargar mapa de disco y meterlo en la VRAM
1 '    11400 'md=&hd001
1 '    11410 md=6144: 'Hasta 6912'
1 '    11450 for f=0 to 24-1
1 '        11460 for c=0 to 32-1
1 '            1 'Como los tiles los habíamos cargado previamente en RAM ahora solo los pasamos a VRAM'
1 '            11470 vpoke md,m(c,f)
1 '            11480 md=md+1
1 '        11490 next c
1 '    11500 next f  
1 '11510 return
