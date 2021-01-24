
10 defint a-z
1 'Inicilizamos dispositivo: 003B, inicilizamos teclado: 003E, incializamos y preparamos el sonido:&H90'
20 defusr=&h003B:a=usr(0):defusr1=&h003E:a=usr1(0):defusr2=&H90:a=usr2(0)
1 'Enlazamos con las rutinas de la bios para aparagar y encender la pantalla'
20 defusr3=&H41:defusr4=&H44
1 'Inicializar mapa, cargamos mapas en array y lo pintamos'
100 print #1, "!Cargando mapa en array (en RAM)"
110 gosub 13000: gosub 13100
1 'Inicializamos el personaje'
130 gosub 10000
1 'Rutina barra espaciadora pulsada
520 strig(0) on:on strig gosub 10500
1 'cada 5 segundos creamos un enemigo'
530 'interval on:on interval=500 gosub 12500:beep
1 'Mostrar pantalla de información / bienvenida'
550 gosub 14000
1 'Copiando mundo en page 0'
560 gosub 13300
1 'Mostrar scoreboard'
570 gosub 9000


1 'Solo se saldrá de este bucle si se ha llegado al final de la pantalla'
1 ' ----------------------'
1 '      MAIN LOOP
1 ' ----------------------' 
    1 'bluce principal'
    1 'Capturamos las teclas'
    2000 gosub 5000
    1 'Chequeamos la física'
    2020 gosub 3100
    1 'render player, el update lo hacemos en el sistema de input'
    2030 gosub 10300
    1 'Render / update enemy'
    2040 gosub 12700
    2060 'gosub 9000
2090 goto 2000
1 ' ----------------------'
1 '    FINAL MAIN LOOP
1 ' ----------------------'



1 ' ----------------------'
1 '    Sound manager'
1 ' ----------------------'
1 'Reproductor de efectos d sonido'
    2300 a=usr2(0)
    2310 if re=1 then PLAY"O5 L8 V4 M8000 A A D F G2 A A A A r60 G E F D C D G R8 A2 A2 A8","o1 v4 c r8 o2 c r8 o1 v6 c r8 o2 v4 c r8 o1 c r8 o2 v6 c r8"
    1 'Tirando el paquete'
    2350 if re=5 then play "l10 o4 v4 g c"
    1 'Paquete cogido'
    2360 if re=6 then play"t250 o5 v12 d v9 e" 
    1 'Pitido normal'
    2370 if re=7 then play "O5 L8 V4 M8000 A A D F G2 A A A A"
    1 'Toque fino'
    2380 if re=8 then PLAY"S1M2000T150O7C32"
    1 'Pasos'
    2390 if re=9 then PLAY"o2 l64 t255 v10 m6500 c"
    2400 if re=10 then sound 6,5:sound 8,16:sound 12,6:sound 13,9
2420 return






1 ' ----------------------'
1 '    Physics system'
1 ' ----------------------'
1'chequeando contorno sprite personaje
    3100 'nada'
    1 'Chekeo de llegar al final del mundo, mc=mapa contador'
    3110 if mc>=200-32 then print #1,"!FINAL": return
    1 'Chekeo pantalla'
    3120 if px<0 then px=0
    1 'Si la posición y es mayor que 180 es que te has caido y vuelves a empezar'
    3130 if py>180 then goto 10400
    1 'Si la posición x del player ha llegado al final, sacamos al personaje de la pantalla 10300, lo pintamos y movemos la pantalla 13600'
    3140 if px>256-16 then px=-32:gosub 10300: gosub 13600:py=18*8:px=0

    1 'Obtenemos el tile actual del player'
    3150 tx=px/8+mc:ty=py/8 
    1 'nuestro sprite son 2 sprites de alto'
    1 'Queremos saber el tile que hay en la derecha del sprite,como son de 8px es +2'
    1 'Colision bloque derecha, hay que sumarle 3 bloques de 8px de los sprites'
    1 'tf=tile floor, o tile suelo o sólido, a partir de las posición 160 empiezan a definirse los tiles que no se pueden pasar'
    3160 t3=m(tx+1,ty+3)
    1 'Tile de abajo' 
    3170 t5=m(tx,ty+4)    
    1 'tile de la izquierda'
    3180 t7=m(tx,ty+3) 
    1 ' tf=160: ts=192'
    1 'Si el tile de la derecha es mayor que 192' 
    3190 if t3>=tf then px=px-pv
    3200 if t7>=tf then px=px+pv

    1 ' Control del salto'
    1' Si el tile del suelo es mayor que el del suelo guardado y estamos cayendo reiniciamos
    3210 if pa=1 and t5>=tf and pl<0 then pa=0:pl=-pl
    3220 if pa=1 then py=py-pl 
    3230 if pa=1 and py<po-20 then pl=-pl
    3240 if pa=1 and py>po then py=po:pl=-pl:pa=0

    1 'Sin saltar '
    1 'Gravedad: si el tile de debajo es menor que el definido de tipo suelo le sumamos la velocidad y'
    1 'Asi solo parará de bajar al player cuando p5 sea mayor 160'
    3250 if pa=0 and t5<tf then py=py+pl
   
3290 return





1 ' ----------------------'
1 '     INPUT SYSTEM'
1 ' ----------------------'
1 '2 Sistema de input'
    1 'Nos guardamos las posiciones del player antes de cambiarlas'
    5000 'nada'
    5010 on stick(0) gosub 5200,5400,5600,5800,6000,6200,6400,6600
5190 return
1 '1 Arriba'
    1 'Saltamos y reproducimos un sonido'
    5200 if pa<>1 then po=py:pa=1
5290 return
1 '2-arriba-derecha'
    5400 if pa<>1 then po=py:pa=1
    5410 px=px+pv
    5420 p1=0:p2=1:p4=4
    5430 swap p(0),p(1):p3=p(1)
5490 return
1 '3 derecha'
    5600 px=px+pv
    5610 p1=0:p2=1:p4=4
    5620 swap p(0),p(1):p3=p(1)
5690 return
1 '4-abajo derecha'
    5800 'nada'
5890 return
1 '5 abajo'
    6000 'nada'
6090 return
1 '6-abajo-izquierda'
    6200 'nada'
6290 return
1 '7 izquierda'
    6400 px=px-pv
    6420 p1=5:p2=6:p4=9
    6440 swap p(2),p(3):p3=p(3)
6490 return
1 '8 arriba izquierda'
    6600 if pa<>1 then po=py:pa=1
    6610 px=px-pv
    6620 p1=5:p2=6:p4=9
    6630 swap p(2),p(3):p3=p(3)
6690 return





1 ' ----------------------'
1 '     HUD'
1 ' ----------------------'
    9000 line (0,180)-(256,212),1,bf 
    1' 9040 preset (0,170):print #1,"px: "px"  py: "py
    1 '9050 preset (0,180):print #1,"mc: "mc"  energy: "pe
    1 '9055 preset (0,190):print #1,"pa: "pa" tx: "tx"  ty: "ty 
    1 '9060 preset (0,200):print #1,"t7: "t7" t3 "t3" t5 "t5
    1 '9050 preset (0,180):print #1,"!mc: "mc"  en: "en" ec: "ec(1)
    1 '9055 preset (0,190):print #1,"!ep: "ep(1)" es: "es(1)"  ex: "ex(1)" ey: "ey(1)  
    1 '9060 preset (0,200):print #1,"px: "px
    1 '9050 preset (0,180):print #1,"pa: "pa"  en: "pc" tf: "tf" ts: "ts
    1 '9060 preset (0,190):print #1,"t5: "t5" tf: "tf" ts: "ts
    9050 preset (10,180):print #1,"Muestras: 0 / Oxigeno: 100 %"
    9060 preset (10,190):print #1,"Vidas: 10"
9090 return






















1 '-----------------------------------'
1 '-------------PLAYER------------------'
1 '-----------------------------------'


1 'Init player'
    1 'Componente position'
    1 'la posición se define en las pantallas, pw=ancho, ph=alto, pv=velocidad, capturas, etc'
    1 'pj=indica si el salto está activado para desactivar la comprobación del teclado'
    1 'po=player y old'
    1 'pa=player salto activado'
    1 'pj=distancia que recorre cuando el salto está activado'
    1 'pj=variable utilizada para el contador de salto y así recorrer el array de salto j()'
    1 'Variables player para la física'
    10000 px=0:py=13*8:pw=16:ph=16:pv=8:pl=8:pj=0:pa=0:dim j(7):po=0
    1 'Array de salto'
    10010 j(0)=-8:j(1)=-8:j(2)=-8:j(3)=0:j(4)=8:j(5)=8:j(6)=8
    1 'variables player para detectar colisiones
    10020 t1=0:t3=0:t5=0:t7=0
    1 'Apartir del 5 sprite es la izquierda'
    1 'p1 tronco superior'
    1 'p2 tronco superior color 2'
    1 'p3 tono inferior'
    1' p4 arma
    10020 dim p(3):p(0)=2:p(1)=3:p(2)=7:p(3)=8:p1=0:p2=1:p3=2:p4=4
    1 'Componente render:'
    10030 pp=0:ps=0:pc=0
    1 'Componente RPG pe= energía o vida'
    10040 pe=100
10050 return


1 'Update player'

1 'pasado al sistema de input'

1 'render player'
    1 'Parte de arriba 1'
    10300 put sprite pp,(px,py),9,p1
    1 'Parte de arriba 2'
    10310 put sprite pp+1,(px,py),10,p2
    1 'Piernas 1'
    10320 put sprite pp+2,(px,py+16),9,p3
    1 'Arma '
    10330 put sprite pp+3,(px,py+8),15,p4
10390 return


1 'Rutina delete 1 live'
    10400 py=18*8:px=0
    10410 'restar 1 vida'
10490 return

1 ' Rutina barra espaciadora pulsada'
    1 'Ponemos un sonido de disparo'
    10500 re=5: gosub 2300
    1 'Guardamos la posición vieja de y en po'
    1 'pj=2 distancia en pixeles que se le va a sumar o restar en el input system'
    10510 'po=py:pj=2:strig(0)off
10590 return

1' ------------------------------------------------------------------------------'
1' -------------------------Rutinas disparos / fires ----------------------------'
1' ------------------------------------------------------------------------------'
1 'Rutina inicializar disparos'
1 'Recuerda que reservaste el espacio para X variables disparo en un array en el loader'
1 'Los disparos se irán creando dinámicamente según vayamos pulsando la barra espaciadora'
1 'Los parámteros se los metemos a ojo, la posición e y, son las del player'
1 'dn= disparo número, sirve para ir creando disparos ya que despues se incrementa'
1 'dd=disparo destruido, variable utilizada para eliminar enemigos (ver linea 11330 y 11200)'
    11000 dn=0:dd=0
11060 return























1 '---------------------------------------------------------'
1 '------------------------ENEMIES -------------------------'
1 '---------------------------------------------------------'
1 'Init
    1 'Definiendo el espacio para los arrays con los valores de los enemigos' 
    1 'em=enemigos maximos'
    12000 em=3
    1 'Reservamos el espacio en RAM para 5 enemigos'
    12010 DIM ex(em),ey(em),ev(em),el(em),es(em),ep(em),ec(em),ee(em)
    1 'Componente de posicion'
    1 'ex=coordenada x, ey=coordenada y', e1=coordenada previa x, e2=coordenada previa y
    1 'Componente de fisica'
    1 'ev=velocidad enemigo eje x, el=velocidad eje y'
    1 'Componente de render'
    1 'es=enemigo sprite, ep=enemigo plano'
    1 'Componente RPG'
    1 'ee=enemigo energia '
    1 'en=enemigo numero, variable utilizar para gestionar la creación y destrucción de enemigos'
    12020 en=0
12030 return

1 ' Crear enemigo'
    1 ' si el numero de enemigos creados es mayor que 5 volvemos para no crear más'
    12500 if en>5 then return
    12505 'en=en+1
    1 'Establecemos las posiciones del enemigo'
    12510 ex(en)=0:ey(en)=0
    12530 ev(en)=8:el(en)=8
    1 'Los enemigos son los sprites 7,8,9'
    12540 es(en)=11+en*2:ep(en)=4+en:ec(en)=6
    12550 'if ec(en)<2 then goto 11540
    12560 ee(en)=100
    12570 en=en+1
12580 return

1 ' Rutina eliminar enemigos'
    12600 ex(ed)=ex(en):ey(ed)=ey(en):ev(ed)=ev(en):el(ed)=el(en):es(ed)=es(en):ep(ed)=ep(en):ec(ed)=ec(en):ee(ed)=ee(en)
    12610 put sprite ep(en),(-16,-16),ec(en),es(en)
    12650 en=en-1
12660 return

1 'Render y Update enemigo'
    12700 'if en<=0 then return 
    12710 for i=0 to en-1
        1 ' A cada uno le restamos la velocidad'
        12720 ex(i)=ex(i)-ev(i) :ec(i)=ec(i)+1
        1 'Si recorre 20 pasos le cambiamos la velocidad'
        12730 if ex(i) mod 5=0 then ev(i)=-ev(i)       
        1 '12730 if ex(i)<0 then ex(i)=255
        12770 put sprite ep(i),(ex(i),ey(i)),6,es(i)
        12780 'preset (0,150+i*10):print #1,"es: "es(i)", ep: "ep(i)", ex: "ex(i)
        12790 'if ex(i)<=0 then ed=i:gosub 12600
    12800 next i
12810 return






















1 '-----------------------------------'
1 '-------------MAP-------------------'
1 '-----------------------------------'

1 'Init map'
    13000 print #1, "!Definiendo array del mapa y pintando mapa"
    13010 dim m(200,26):mc=0
13020 return

1 'Cargar mundo con los mapas de los niveles en el buffer o array'
    13100 'esto almacenará el array a partir de la posición 8dc8 de la RAM'
    1 '12000 rutina de inicialización mundo 0
    13110 bload"world0.bin",r:gosub 20000
    13120 md=&hc001
    13130 for f=0 to 23-1
        13140 for c=0 to 200-1
            13150 tn=peek(md):md=md+1
            13160 m(c,f)=tn
        13170 next c
    13180 next f
13190 return

1 'Pintamos en la VRAM page 0, los valores definidos en el array hasta la columna 32
    13300 _turbo on (m())
    13310 for f=0 to 23-1
        13360 for c=0 to 32-1
            13370 tn=m(c,f)
            13380 if tn >=0 and tn <32 then copy (tn*8,0*8)-((tn*8)+8,(0*8)+8),1 to (c*8,f*8),0,tpset
            13390 if tn >=32 and tn <64 then copy ((tn-32)*8,1*8)-(((tn-32)*8)+8,(1*8)+8),1 to (c*8,f*8),0,tpset
            13400 if tn >=64 and tn <96 then copy ((tn-64)*8,2*8)-(((tn-64)*8)+8,(2*8)+8),1 to (c*8,f*8),0,tpset
            13410 if tn>=96 and tn <128 then copy ((tn-96)*8,3*8)-(((tn-96)*8)+8,(3*8)+8),1 to (c*8,f*8),0,tpset
            13420 if tn>=128 and tn <160 then copy ((tn-128)*8,4*8)-(((tn-128)*8)+8,(4*8)+8),1 to (c*8,f*8),0,tpset
            13430 if tn>=160 and tn <192 then copy ((tn-160)*8,5*8)-(((tn-160)*8)+8,(5*8)+8),1 to (c*8,f*8),0,tpset
            13440 if tn>=192 and tn <224 then copy ((tn-192)*8,6*8)-(((tn-192)*8)+8,(6*8)+8),1 to (c*8,f*8),0,tpset
            13450 if tn>=224 and tn <256 then copy ((tn-224)*8,7*8)-(((tn-224)*8)+8,(7*8)+8),1 to (c*8,f*8),0,tpset
            1 '11460 if tn>=128 and tn <144 then copy ((tn-128)*16,8*16)-(((tn-128)*16)+16,(8*16)+16),1 to (c*16,f*16),0,tpset
            1 '11470 if tn>=144 and tn <160 then copy ((tn-144)*16,9*16)-(((tn-144)*16)+16,(9*16)+16),1 to (c*16,f*16),0,tpset
            1 '11480 if tn>=160 and tn <176 then copy ((tn-160)*16,10*16)-(((tn-160)*16)+16,(10*16)+16),1 to (c*16,f*16),0,tpset
            1 '11490 if tn>=176 and tn <192 then copy ((tn-176)*16,11*16)-(((tn-176)*16)+16,(11*16)+16),1 to (c*16,f*16),0,tpset
            1 '11500 if tn>=192 and tn <208 then copy ((tn-192)*16,12*16)-(((tn-192)*16)+16,(12*16)+16),1 to (c*16,f*16),0,tpset
            13510 next c
    13520 next f 
    13540 _turbo off
13570 return

1 'Mover mapa a la izquierda y pintar ultima columna
    1 'Si llegamos al final salimos'
    13600 if mc=200-32 then return
    13601 _turbo on (m(),mc)
    1 'Repetimos la copia del ultimo tile y desplazamiento de la pantalla 32 veces'
    13602 for i=0 to 32
        13605 mc=mc+1
        13610 copy (8,0)-(256,212),0 to (0,0),0,pset  
        13620 for f=3 to 23-1 
            13630 tn=m(31+mc,f)
            13640 if tn >=0 and tn <32 then copy (tn*8,0*8)-((tn*8)+8,(0*8)+8),1 to (31*8,f*8),0
            13650 if tn >=32 and tn <64 then copy ((tn-32)*8,1*8)-(((tn-32)*8)+8,(1*8)+8),1 to (31*8,f*8),0
            13660 if tn >=64 and tn <96 then copy ((tn-64)*8,2*8)-(((tn-64)*8)+8,(2*8)+8),1 to (31*8,f*8),0
            13670 if tn>=96 and tn <128 then copy ((tn-96)*8,3*8)-(((tn-96)*8)+8,(3*8)+8),1 to (31*8,f*8),0
            13680 if tn>=128 and tn <160 then copy ((tn-128)*8,4*8)-(((tn-128)*8)+8,(4*8)+8),1 to (31*8,f*8),0
            13690 if tn>=160 and tn <192 then copy ((tn-160)*8,5*8)-(((tn-160)*8)+8,(5*8)+8),1 to (31*8,f*8),0
            13700 if tn>=192 and tn <224 then copy ((tn-192)*8,6*8)-(((tn-192)*8)+8,(6*8)+8),1 to (31*8,f*8),0
            13710 if tn>=224 and tn <256 then copy ((tn-224)*8,7*8)-(((tn-224)*8)+8,(7*8)+8),1 to (31*8,f*8),0
        13720 next f
    13730 next i
    13735 _turbo off
    1 ' Pintamos el marcador'
    13736 gosub 9000
13740 return

1 '---------------------------------------'
1 '-------------SCREENS-------------------'
1 '---------------------------------------'
1'------------------------------------'
1'  Pantalla de Bienvenida y records 
1'------------------------------------'
    14000 cls:preset (10,30):  print #1,"!@@@@  @  @@@@  @ @@@@@ @  @   @"
    14010 preset (10,40):      print #1,"!@    @ @ @@@@  @   @  @ @ @ @ @"
    14020 preset (10,50):      print #1,"!@@@@@   @@     @   @ @   @@  @@"
    14030 preset (10,70):      print #1,"!10540,capita Kik, debes ir a recoger las muestras fabricadas en otros entornos planetarios."
    14040 preset (10,110):     print #1,"!Pero ten cuidado los esbirros de worst que te obstaculizan."
    1 ' Con inverse ponemos el fondo de los carcacteres en el frente y el frente en el fondo'
    14050 preset (10,160): print #1, "!Cursores para mover, pulsa una tecla para continuar"
    14060 preset (10,180): print #1, "!libre: "fre(0)
    1 'Si no se pulsa una tecla se queda en blucle infinito reproduciebdo una música, si se pulsa se para la música'
    1 '11870 re=1:gosub 2300
    14070 if inkey$="" then goto 14070
14090 return

1'------------------------------------'
1'          screen 0
1'------------------------------------'
    1 'Fuerza de la gravedad'
    20000 wg=8
    1 'Tiles'
    1 'tf=tile floor, tile suelo, corresponde al tile 160 hasta el 160+32'
    1 'tf=tile suelo'
    20010 tf=160
    1 'creamos 2 enemigos'
    1 'ex(em),ey(em),ev(em),el(em),es(em),ep(em),ec(em),ee(em) / y=21*8=168
    20020 gosub 12500: ex(en-1)=4*8:ey(en-1)=20*8
    20030 gosub 12500: ex(en-1)=26*8:ey(en-1)=20*8
20090 return