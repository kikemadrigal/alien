
1 'Main'
10 screen 5,2:color 1,15,15
1 'escribimos los sprites'
20 gosub 15000
1 'Inicializamos variables sprite'
30 'gosub 10000
1 'Main loop
    1 'Sistema de física / input'
    100 'gosub 5000
    1 'Sistema de render'
    110 'put sprite pp,(px,py),1,ps
120 goto 100




1 ' Rutina de física / input'
    5000 on stick(0) gosub 5200,5400,5600,5800,6000,6200,6400,6600
    1 'Rutina de salto (2 parte)'
    5100 if pa=1 then py=py-pj
    1 '12 es la distancia máxima a la que puede saltar'
    5120 if py<po-20 then pj=-pj
    5130 if py>po then py=po:pj=0:pj=-pj:pa=0'strig(0)on
    1 '1 Arriba'
    1 'Saltamos y reproducimos un sonido'
    1 '2700 if pa<>1 then po=py:pj=2:pa=1:re=10: gosub 2300:'strig(0)off
    5200 if pa<>1 then pa=1
5290 return
1 'Rutina mover 2-arriba-derecha'
    5400 if pa<>1 then pa=1
    5410 px=px+pv
5490 return
1 'Rutina mover 3 derecha'
    5600 px=px+pv
5690 return
1 'Rutina mover 4-abajo derecha'
    5800 'nada'
5890 return
1 'Rutina mover 5 abajo'
    6000 'nada'
6090 return
1 'Rutina mover 6-abajo-izquierda'
    6200 'nada'
6290 return
1 'Rutina mover 7 izquierda'
    6400 px=px-pv:'gosub 9000
6490 return
1 'Rutina mover 8 arriba izquierda'
    6600 if pa<>1 then pa=1
    6610 px=px-pv:'gosub 9000
6690 return



1 ' Player'
1 ' Inicialización variables'
    1 ' Componente físicia'
    1 'px=posicion x,pw= ancho player,ph=alto player, pv=velocidad eje x, pl=velocidad eje y, po=posición y vieja, pa=salto activado player'
    10000 px=15*8:py=18*8:pw=16:ph=16:pv=8:pl=8:pj=0:po=py:pa=0
    1 ' Componente render'
    10030 pp=0:ps=0
10090 return


1 'Rutina cargar sprites con datas basic'
    15000 restore 15120
    15000 FOR I=0 TO 1:SP$=""
        15010 FOR J=1 TO 32:READ A$
            15020 SP$=SP$+CHR$(VAL(A$))
        15030 NEXT J
        15040 SPRITE$(I)=SP$
    15050 NEXT I
    15060 return 





    1 '0-Personaje parte superior 1 derecha'
    15120 DATA 3,7,6,7,1,7,29,57
    15130 DATA 60,31,7,1,12,14,6,6
    15140 DATA 192,64,0,0,128,160,160,128
    15150 DATA 0,0,128,204,0,192,224,224