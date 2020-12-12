10 defint a-z
110 gosub 11000: gosub 11100: gosub 11300
130 gosub 10000
520 strig(0) on:on strig gosub 10200
530 on interval=50 gosub 11600:interval on
540 gosub 9000
    2000 gosub 2500
    2020 gosub 10100
    2030 gosub 3100
    2040 'gosub 9000
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
    2520 if pa=1 then py=py-pj
    2530 if py<po-20 then pj=-pj
    2540 if py>po then py=po:pj=0:pj=-pj:pa=0'strig(0)on
2545 return
    2600 px=px+pv
    2610 p1=0:p2=1:p4=4
    2620 swap p(0),p(1):p3=p(1)
2630 return
    2640 px=px-pv:'gosub 9000
    2650 p1=5:p2=6:p4=9
    2660 swap p(2),p(3):p3=p(3)
2670 return
    2700 if pa<>1 then po=py:pj=2:pa=1:re=10: gosub 2300:'strig(0)off
2750 return
    2800 'nada'
2850 return
    3100 'Colsion bloque derecha'
    3110 tx=px/8:ty=py/8
    3130 t3=m(tx+mc+2,ty+2)
    3140 if t3>95 then beep:px=px-pv
    3150 t5=m(tx+mc,ty+4)
    3160 if t5>95 then beep:py=py-pv
3190 return
    9000 'preset (0,0):print #1,"Alien, fre "fre(0)
    9050 preset (0,0):print #1,"mc: "mc"  energy: "pe
    9060 preset (0,8):print #1,"px: "px"  py: "py" t3: "t3
    9070 preset (0,16):print #1,"tx: "tx"  ty: "ty" "m(62,23)
9090 return
    10000 px=32:py=18*8:pw=16:ph=16:pv=2:pj=0:po=py:pa=0
    10010 dim p(3):p(0)=2:p(1)=3:p(2)=7:p(3)=8:p1=0:p2=1:p3=2:p4=4
    10020 pp=0:ps=0
    10030 pc=0:pe=100
10040 return
    10100 put sprite pp,(px,py),9,p1
    10110 put sprite pp+1,(px,py),10,p2
    10120 put sprite pp+2,(px,py+16),9,p3
    10130 put sprite pp+3,(px,py+8),15,p4
10190 return
    10200 re=5: gosub 2300
    10210 'po=py:pj=2:strig(0)off
10290 return
    11000 print #1, "Definiendo array del mapa"
    11010 dim m(100,24):mc=0
11020 return
    11100 print #1, "Cargando mapa en array y dibujando"
    11110 bload"world0.bin",r
    11120 md=&hd001
    11130 for f=0 to 24-1
        11140 for c=0 to 100-1
            11150 tn=peek(md):md=md+1
            11160 m(c,f)=tn
        11170 next c
    11180 next f
11190 return
    11300 _turbo on (m()):cls
    11310 for f=3 to 24-1
        11360 for c=0 to 32-1
            11370 tn=m(c,f)
            11380 if tn >=0 and tn <32 then copy (tn*8,0*8)-((tn*8)+8,(0*8)+8),1 to (c*8,f*8),0,tpset
            11390 if tn >=32 and tn <64 then copy ((tn-32)*8,1*8)-(((tn-32)*8)+8,(1*8)+8),1 to (c*8,f*8),0,tpset
            11400 if tn >=64 and tn <96 then copy ((tn-64)*8,2*8)-(((tn-64)*8)+8,(2*8)+8),1 to (c*8,f*8),0,tpset
            11410 if tn>=96 and tn <128 then copy ((tn-96)*8,3*8)-(((tn-96)*8)+8,(3*8)+8),1 to (c*8,f*8),0,tpset
            11420 if tn>=128 and tn <160 then copy ((tn-128)*8,4*8)-(((tn-128)*8)+8,(4*8)+8),1 to (c*8,f*8),0,tpset
            11430 if tn>=160 and tn <192 then copy ((tn-160)*8,5*8)-(((tn-160)*8)+8,(5*8)+8),1 to (c*8,f*8),0,tpset
            11440 if tn>=192 and tn <224 then copy ((tn-192)*8,6*8)-(((tn-192)*8)+8,(6*8)+8),1 to (c*8,f*8),0,tpset
            11450 if tn>=224 and tn <256 then copy ((tn-224)*8,7*8)-(((tn-224)*8)+8,(7*8)+8),1 to (c*8,f*8),0,tpset
            11510 next c
    11520 next f 
    11540 _turbo off
11570 return
    11600 if mc=100-32 then return
    11601 _turbo on (m(),mc)
    11602 'if mc=100-32 then return
    11605 mc=mc+1
    11610 copy (8,8*3)-(256,212),0 to (0,8*3),0,pset  
    11620 for f=3 to 24-1 
        11630 tn=m(31+mc,f)
        11640 if tn >=0 and tn <32 then copy (tn*8,0*8)-((tn*8)+8,(0*8)+8),1 to (31*8,f*8),0
        11650 if tn >=32 and tn <64 then copy ((tn-32)*8,1*8)-(((tn-32)*8)+8,(1*8)+8),1 to (31*8,f*8),0
        11660 if tn >=64 and tn <96 then copy ((tn-64)*8,2*8)-(((tn-64)*8)+8,(2*8)+8),1 to (31*8,f*8),0
        11670 if tn>=96 and tn <128 then copy ((tn-96)*8,3*8)-(((tn-96)*8)+8,(3*8)+8),1 to (31*8,f*8),0
        11680 if tn>=128 and tn <160 then copy ((tn-128)*8,4*8)-(((tn-128)*8)+8,(4*8)+8),1 to (31*8,f*8),0
        11690 if tn>=160 and tn <192 then copy ((tn-160)*8,5*8)-(((tn-160)*8)+8,(5*8)+8),1 to (31*8,f*8),0
        11700 if tn>=192 and tn <224 then copy ((tn-192)*8,6*8)-(((tn-192)*8)+8,(6*8)+8),1 to (31*8,f*8),0
        11710 if tn>=224 and tn <256 then copy ((tn-224)*8,7*8)-(((tn-224)*8)+8,(7*8)+8),1 to (31*8,f*8),0
    11720 next f
    11730 _turbo off
11740 return
