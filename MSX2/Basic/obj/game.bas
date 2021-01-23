10 defint a-z
20 defusr=&h003B:a=usr(0):defusr1=&h003E:a=usr1(0):defusr2=&H90:a=usr2(0)
20 defusr3=&H41:defusr4=&H44
100 print #1, "Cargando mapa en array (en RAM)"
110 gosub 13000: gosub 13100
130 gosub 10000
520 strig(0) on:on strig gosub 10500
530 on interval=500 gosub 12500:interval on
540 'gosub 9000
550 gosub 14000
560 gosub 13300
570 gosub 4000
    2000 gosub 2500
    2020 gosub 3100
    2030 gosub 10300
    2040 gosub 12700
    2050 gosub 4000
    2060 'gosub 9000
2090 goto 2000
    2300 a=usr2(0)
    2310 if re=1 then PLAY"O5 L8 V4 M8000 A A D F G2 A A A A r60 G E F D C D G R8 A2 A2 A8","o1 v4 c r8 o2 c r8 o1 v6 c r8 o2 v4 c r8 o1 c r8 o2 v6 c r8"
    2350 if re=5 then play "l10 o4 v4 g c"
    2360 if re=6 then play"t250 o5 v12 d v9 e" 
    2370 if re=7 then play "O5 L8 V4 M8000 A A D F G2 A A A A"
    2380 if re=8 then PLAY"S1M2000T150O7C32"
    2390 if re=9 then PLAY"o2 l64 t255 v10 m6500 c"
    2400 if re=10 then sound 6,5:sound 8,16:sound 12,6:sound 13,9
2420 return
    2500 on stick(0) gosub 2700,2500,2600,2500,2800,2500,2640
    2520 if pa=1 and pc<7 then py=py+s(pc):pc=pc+1
    2530 if pa=1 and pc>=5 then pc=0:pa=0
2545 return
    2600 px=px+pv
    2610 p1=0:p2=1:p4=4
    2620 swap p(0),p(1):p3=p(1)
2630 return
    2640 px=px-pv:'gosub 9000
    2650 p1=5:p2=6:p4=9
    2660 swap p(2),p(3):p3=p(3)
2670 return
    2700 if pa<>1 then pa=1
2750 return
    2800 'nada'
2850 return
    3100 if mc>=200-32 then print #1,"FINAL": return
    3101 if px<0 then px=0
    3105 if py>180 then goto 10400
    3106 if px>256-16 then px=-32:gosub 10300: gosub 13600:py=18*8:px=0
    3110 tx=px/8+mc:ty=py/8
    3130 t3=m(tx+1,ty+3)
    3131 t5=m(tx,ty+4)
    3135 t7=m(tx,ty+3)
    3140 if t3>=ts then px=px-pv
    3150 if t7>=ts then px=px+pv
    3160 if pa=1 and t5>ts then py=py-pv
    3170 if pa=0 and t5<tf then py=py+pv 
3190 return
    4000 'if px mod 80=0 and px<>0 then gosub 12500
4090 return
    9000 line (0,180)-(256,212),1,bf
    9050 preset (0,180):print #1,"mc: "mc"  en: "en
    9055 preset (0,190):print #1,"ep: "ep(0)" es: "es(0)"  ex: "ex(0)" ey: "ey(0) 
    9060 preset (0,200):print #1,"px: "px
9090 return
    10000 px=0:py=18*8:pw=16:ph=16:pv=8:pj=0:po=py:pa=0:pc=0:dim s(7)
    10010 s(0)=-8:s(1)=-8:s(2)=-8:s(3)=0:s(4)=8:s(5)=8:s(6)=8
    10020 dim p(3):p(0)=2:p(1)=3:p(2)=7:p(3)=8:p1=0:p2=1:p3=2:p4=4
    10030 pp=0:ps=0
    10040 pe=100
10050 return
    10300 put sprite pp,(px,py),9,p1
    10310 put sprite pp+1,(px,py),10,p2
    10320 put sprite pp+2,(px,py+16),9,p3
    10330 put sprite pp+3,(px,py+8),15,p4
10390 return
    10400 py=18*8:px=0
    10410 'restar 1 vida'
10490 return
    10500 re=5: gosub 2300
    10510 'po=py:pj=2:strig(0)off
10590 return
    11000 dn=0:dd=0
11060 return
    12000 em=3
    12010 DIM ex(em),ey(em),ev(em),el(em),es(em),ep(em),ec(em),ee(em)
    12020 en=0
12030 return
    12500 if en>2 then return
    12505 en=en+1
    12510 ex(en)=256:ey(en)=20*8
    12530 ev(en)=8:el(en)=8
    12540 es(en)=11+en*2:ep(en)=4+en:ec(en)=6
    12550 'if ec(en)<2 then goto 11540
    12560 ee(en)=100
    12570 'en=en+1
12580 return
    12600 ex(ed)=ex(en):ey(ed)=ey(en):ev(ed)=ev(en):el(ed)=el(en):es(ed)=es(en):ep(ed)=ep(en):ec(ed)=ec(en):ee(ed)=ee(en)
    12610 put sprite ep(en),(-16,-16),ec(en),es(en)
    12650 en=en-1
12660 return
    12700 if en<=0 then return
    12710 for i=0 to en-1
        12720 ex(i)=ex(i)-ev(i)        
        12730 'if ex(i)<0 then ex(i)=255
        12770 put sprite ep(i),(ex(i),ey(i)),ec(ei),es(i)
        12780 'preset (0,150+i*10):print #1,"es: "es(i)", ep: "ep(i)", ex: "ex(i)
        12790 if ex(i)<=0 then ed=i:gosub 12600
    12800 next i
12810 return
    13000 print #1, "Definiendo array del mapa y pintando mapa"
    13010 dim m(200,26):mc=0
13020 return
    13100 'esto almacenará el array a partir de la posición 8dc8 de la RAM'
    13110 bload"world0.bin",r:gosub 20000
    13120 md=&hc001
    13130 for f=0 to 23-1
        13140 for c=0 to 200-1
            13150 tn=peek(md):md=md+1
            13160 m(c,f)=tn
        13170 next c
    13180 next f
13190 return
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
            13510 next c
    13520 next f 
    13540 _turbo off
13570 return
    13600 if mc=200-32 then return
    13601 _turbo on (m(),mc)
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
13740 return
    14000 cls:preset (10,30):  print #1,"@@@@  @  @@@@  @ @@@@@ @  @   @"
    14010 preset (10,40):      print #1,"@    @ @ @@@@  @   @  @ @ @ @ @"
    14020 preset (10,50):      print #1,"@@@@@   @@     @   @ @   @@  @@"
    14030 preset (10,70):      print #1,"10540,capita Kik, debes ir a recoger las muestras fabricadas en otros entornos planetarios."
    14040 preset (10,110):     print #1,"Pero ten cuidado los esbirros de worst que te obstaculizan."
    14050 preset (10,160): print #1, "Cursores para mover, pulsa una tecla para continuar"
    14060 preset (10,180): print #1, "libre: "fre(0)
    14070 if inkey$="" then goto 14070
14090 return
    20000 wg=8
    20010 tf=160: ts=192
20090 return
