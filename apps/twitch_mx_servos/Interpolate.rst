                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:19 2012
                              5 ;--------------------------------------------------------
                              6 	.module Interpolate
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _interpolateU_PARM_5
                             13 	.globl _interpolateU_PARM_4
                             14 	.globl _interpolateU_PARM_3
                             15 	.globl _interpolateU_PARM_2
                             16 	.globl _interpolate_PARM_5
                             17 	.globl _interpolate_PARM_4
                             18 	.globl _interpolate_PARM_3
                             19 	.globl _interpolate_PARM_2
                             20 	.globl _interpolate
                             21 	.globl _interpolateU
                             22 ;--------------------------------------------------------
                             23 ; special function registers
                             24 ;--------------------------------------------------------
                             25 	.area RSEG    (ABS,DATA)
   0000                      26 	.org 0x0000
                    0080     27 FInterpolate$P0$0$0 == 0x0080
                    0080     28 _P0	=	0x0080
                    0081     29 FInterpolate$SP$0$0 == 0x0081
                    0081     30 _SP	=	0x0081
                    0082     31 FInterpolate$DPL0$0$0 == 0x0082
                    0082     32 _DPL0	=	0x0082
                    0083     33 FInterpolate$DPH0$0$0 == 0x0083
                    0083     34 _DPH0	=	0x0083
                    0084     35 FInterpolate$DPL1$0$0 == 0x0084
                    0084     36 _DPL1	=	0x0084
                    0085     37 FInterpolate$DPH1$0$0 == 0x0085
                    0085     38 _DPH1	=	0x0085
                    0086     39 FInterpolate$U0CSR$0$0 == 0x0086
                    0086     40 _U0CSR	=	0x0086
                    0087     41 FInterpolate$PCON$0$0 == 0x0087
                    0087     42 _PCON	=	0x0087
                    0088     43 FInterpolate$TCON$0$0 == 0x0088
                    0088     44 _TCON	=	0x0088
                    0089     45 FInterpolate$P0IFG$0$0 == 0x0089
                    0089     46 _P0IFG	=	0x0089
                    008A     47 FInterpolate$P1IFG$0$0 == 0x008a
                    008A     48 _P1IFG	=	0x008a
                    008B     49 FInterpolate$P2IFG$0$0 == 0x008b
                    008B     50 _P2IFG	=	0x008b
                    008C     51 FInterpolate$PICTL$0$0 == 0x008c
                    008C     52 _PICTL	=	0x008c
                    008D     53 FInterpolate$P1IEN$0$0 == 0x008d
                    008D     54 _P1IEN	=	0x008d
                    008F     55 FInterpolate$P0INP$0$0 == 0x008f
                    008F     56 _P0INP	=	0x008f
                    0090     57 FInterpolate$P1$0$0 == 0x0090
                    0090     58 _P1	=	0x0090
                    0091     59 FInterpolate$RFIM$0$0 == 0x0091
                    0091     60 _RFIM	=	0x0091
                    0092     61 FInterpolate$DPS$0$0 == 0x0092
                    0092     62 _DPS	=	0x0092
                    0093     63 FInterpolate$MPAGE$0$0 == 0x0093
                    0093     64 _MPAGE	=	0x0093
                    0095     65 FInterpolate$ENDIAN$0$0 == 0x0095
                    0095     66 _ENDIAN	=	0x0095
                    0098     67 FInterpolate$S0CON$0$0 == 0x0098
                    0098     68 _S0CON	=	0x0098
                    009A     69 FInterpolate$IEN2$0$0 == 0x009a
                    009A     70 _IEN2	=	0x009a
                    009B     71 FInterpolate$S1CON$0$0 == 0x009b
                    009B     72 _S1CON	=	0x009b
                    009C     73 FInterpolate$T2CT$0$0 == 0x009c
                    009C     74 _T2CT	=	0x009c
                    009D     75 FInterpolate$T2PR$0$0 == 0x009d
                    009D     76 _T2PR	=	0x009d
                    009E     77 FInterpolate$T2CTL$0$0 == 0x009e
                    009E     78 _T2CTL	=	0x009e
                    00A0     79 FInterpolate$P2$0$0 == 0x00a0
                    00A0     80 _P2	=	0x00a0
                    00A1     81 FInterpolate$WORIRQ$0$0 == 0x00a1
                    00A1     82 _WORIRQ	=	0x00a1
                    00A2     83 FInterpolate$WORCTRL$0$0 == 0x00a2
                    00A2     84 _WORCTRL	=	0x00a2
                    00A3     85 FInterpolate$WOREVT0$0$0 == 0x00a3
                    00A3     86 _WOREVT0	=	0x00a3
                    00A4     87 FInterpolate$WOREVT1$0$0 == 0x00a4
                    00A4     88 _WOREVT1	=	0x00a4
                    00A5     89 FInterpolate$WORTIME0$0$0 == 0x00a5
                    00A5     90 _WORTIME0	=	0x00a5
                    00A6     91 FInterpolate$WORTIME1$0$0 == 0x00a6
                    00A6     92 _WORTIME1	=	0x00a6
                    00A8     93 FInterpolate$IEN0$0$0 == 0x00a8
                    00A8     94 _IEN0	=	0x00a8
                    00A9     95 FInterpolate$IP0$0$0 == 0x00a9
                    00A9     96 _IP0	=	0x00a9
                    00AB     97 FInterpolate$FWT$0$0 == 0x00ab
                    00AB     98 _FWT	=	0x00ab
                    00AC     99 FInterpolate$FADDRL$0$0 == 0x00ac
                    00AC    100 _FADDRL	=	0x00ac
                    00AD    101 FInterpolate$FADDRH$0$0 == 0x00ad
                    00AD    102 _FADDRH	=	0x00ad
                    00AE    103 FInterpolate$FCTL$0$0 == 0x00ae
                    00AE    104 _FCTL	=	0x00ae
                    00AF    105 FInterpolate$FWDATA$0$0 == 0x00af
                    00AF    106 _FWDATA	=	0x00af
                    00B1    107 FInterpolate$ENCDI$0$0 == 0x00b1
                    00B1    108 _ENCDI	=	0x00b1
                    00B2    109 FInterpolate$ENCDO$0$0 == 0x00b2
                    00B2    110 _ENCDO	=	0x00b2
                    00B3    111 FInterpolate$ENCCS$0$0 == 0x00b3
                    00B3    112 _ENCCS	=	0x00b3
                    00B4    113 FInterpolate$ADCCON1$0$0 == 0x00b4
                    00B4    114 _ADCCON1	=	0x00b4
                    00B5    115 FInterpolate$ADCCON2$0$0 == 0x00b5
                    00B5    116 _ADCCON2	=	0x00b5
                    00B6    117 FInterpolate$ADCCON3$0$0 == 0x00b6
                    00B6    118 _ADCCON3	=	0x00b6
                    00B8    119 FInterpolate$IEN1$0$0 == 0x00b8
                    00B8    120 _IEN1	=	0x00b8
                    00B9    121 FInterpolate$IP1$0$0 == 0x00b9
                    00B9    122 _IP1	=	0x00b9
                    00BA    123 FInterpolate$ADCL$0$0 == 0x00ba
                    00BA    124 _ADCL	=	0x00ba
                    00BB    125 FInterpolate$ADCH$0$0 == 0x00bb
                    00BB    126 _ADCH	=	0x00bb
                    00BC    127 FInterpolate$RNDL$0$0 == 0x00bc
                    00BC    128 _RNDL	=	0x00bc
                    00BD    129 FInterpolate$RNDH$0$0 == 0x00bd
                    00BD    130 _RNDH	=	0x00bd
                    00BE    131 FInterpolate$SLEEP$0$0 == 0x00be
                    00BE    132 _SLEEP	=	0x00be
                    00C0    133 FInterpolate$IRCON$0$0 == 0x00c0
                    00C0    134 _IRCON	=	0x00c0
                    00C1    135 FInterpolate$U0DBUF$0$0 == 0x00c1
                    00C1    136 _U0DBUF	=	0x00c1
                    00C2    137 FInterpolate$U0BAUD$0$0 == 0x00c2
                    00C2    138 _U0BAUD	=	0x00c2
                    00C4    139 FInterpolate$U0UCR$0$0 == 0x00c4
                    00C4    140 _U0UCR	=	0x00c4
                    00C5    141 FInterpolate$U0GCR$0$0 == 0x00c5
                    00C5    142 _U0GCR	=	0x00c5
                    00C6    143 FInterpolate$CLKCON$0$0 == 0x00c6
                    00C6    144 _CLKCON	=	0x00c6
                    00C7    145 FInterpolate$MEMCTR$0$0 == 0x00c7
                    00C7    146 _MEMCTR	=	0x00c7
                    00C9    147 FInterpolate$WDCTL$0$0 == 0x00c9
                    00C9    148 _WDCTL	=	0x00c9
                    00CA    149 FInterpolate$T3CNT$0$0 == 0x00ca
                    00CA    150 _T3CNT	=	0x00ca
                    00CB    151 FInterpolate$T3CTL$0$0 == 0x00cb
                    00CB    152 _T3CTL	=	0x00cb
                    00CC    153 FInterpolate$T3CCTL0$0$0 == 0x00cc
                    00CC    154 _T3CCTL0	=	0x00cc
                    00CD    155 FInterpolate$T3CC0$0$0 == 0x00cd
                    00CD    156 _T3CC0	=	0x00cd
                    00CE    157 FInterpolate$T3CCTL1$0$0 == 0x00ce
                    00CE    158 _T3CCTL1	=	0x00ce
                    00CF    159 FInterpolate$T3CC1$0$0 == 0x00cf
                    00CF    160 _T3CC1	=	0x00cf
                    00D0    161 FInterpolate$PSW$0$0 == 0x00d0
                    00D0    162 _PSW	=	0x00d0
                    00D1    163 FInterpolate$DMAIRQ$0$0 == 0x00d1
                    00D1    164 _DMAIRQ	=	0x00d1
                    00D2    165 FInterpolate$DMA1CFGL$0$0 == 0x00d2
                    00D2    166 _DMA1CFGL	=	0x00d2
                    00D3    167 FInterpolate$DMA1CFGH$0$0 == 0x00d3
                    00D3    168 _DMA1CFGH	=	0x00d3
                    00D4    169 FInterpolate$DMA0CFGL$0$0 == 0x00d4
                    00D4    170 _DMA0CFGL	=	0x00d4
                    00D5    171 FInterpolate$DMA0CFGH$0$0 == 0x00d5
                    00D5    172 _DMA0CFGH	=	0x00d5
                    00D6    173 FInterpolate$DMAARM$0$0 == 0x00d6
                    00D6    174 _DMAARM	=	0x00d6
                    00D7    175 FInterpolate$DMAREQ$0$0 == 0x00d7
                    00D7    176 _DMAREQ	=	0x00d7
                    00D8    177 FInterpolate$TIMIF$0$0 == 0x00d8
                    00D8    178 _TIMIF	=	0x00d8
                    00D9    179 FInterpolate$RFD$0$0 == 0x00d9
                    00D9    180 _RFD	=	0x00d9
                    00DA    181 FInterpolate$T1CC0L$0$0 == 0x00da
                    00DA    182 _T1CC0L	=	0x00da
                    00DB    183 FInterpolate$T1CC0H$0$0 == 0x00db
                    00DB    184 _T1CC0H	=	0x00db
                    00DC    185 FInterpolate$T1CC1L$0$0 == 0x00dc
                    00DC    186 _T1CC1L	=	0x00dc
                    00DD    187 FInterpolate$T1CC1H$0$0 == 0x00dd
                    00DD    188 _T1CC1H	=	0x00dd
                    00DE    189 FInterpolate$T1CC2L$0$0 == 0x00de
                    00DE    190 _T1CC2L	=	0x00de
                    00DF    191 FInterpolate$T1CC2H$0$0 == 0x00df
                    00DF    192 _T1CC2H	=	0x00df
                    00E0    193 FInterpolate$ACC$0$0 == 0x00e0
                    00E0    194 _ACC	=	0x00e0
                    00E1    195 FInterpolate$RFST$0$0 == 0x00e1
                    00E1    196 _RFST	=	0x00e1
                    00E2    197 FInterpolate$T1CNTL$0$0 == 0x00e2
                    00E2    198 _T1CNTL	=	0x00e2
                    00E3    199 FInterpolate$T1CNTH$0$0 == 0x00e3
                    00E3    200 _T1CNTH	=	0x00e3
                    00E4    201 FInterpolate$T1CTL$0$0 == 0x00e4
                    00E4    202 _T1CTL	=	0x00e4
                    00E5    203 FInterpolate$T1CCTL0$0$0 == 0x00e5
                    00E5    204 _T1CCTL0	=	0x00e5
                    00E6    205 FInterpolate$T1CCTL1$0$0 == 0x00e6
                    00E6    206 _T1CCTL1	=	0x00e6
                    00E7    207 FInterpolate$T1CCTL2$0$0 == 0x00e7
                    00E7    208 _T1CCTL2	=	0x00e7
                    00E8    209 FInterpolate$IRCON2$0$0 == 0x00e8
                    00E8    210 _IRCON2	=	0x00e8
                    00E9    211 FInterpolate$RFIF$0$0 == 0x00e9
                    00E9    212 _RFIF	=	0x00e9
                    00EA    213 FInterpolate$T4CNT$0$0 == 0x00ea
                    00EA    214 _T4CNT	=	0x00ea
                    00EB    215 FInterpolate$T4CTL$0$0 == 0x00eb
                    00EB    216 _T4CTL	=	0x00eb
                    00EC    217 FInterpolate$T4CCTL0$0$0 == 0x00ec
                    00EC    218 _T4CCTL0	=	0x00ec
                    00ED    219 FInterpolate$T4CC0$0$0 == 0x00ed
                    00ED    220 _T4CC0	=	0x00ed
                    00EE    221 FInterpolate$T4CCTL1$0$0 == 0x00ee
                    00EE    222 _T4CCTL1	=	0x00ee
                    00EF    223 FInterpolate$T4CC1$0$0 == 0x00ef
                    00EF    224 _T4CC1	=	0x00ef
                    00F0    225 FInterpolate$B$0$0 == 0x00f0
                    00F0    226 _B	=	0x00f0
                    00F1    227 FInterpolate$PERCFG$0$0 == 0x00f1
                    00F1    228 _PERCFG	=	0x00f1
                    00F2    229 FInterpolate$ADCCFG$0$0 == 0x00f2
                    00F2    230 _ADCCFG	=	0x00f2
                    00F3    231 FInterpolate$P0SEL$0$0 == 0x00f3
                    00F3    232 _P0SEL	=	0x00f3
                    00F4    233 FInterpolate$P1SEL$0$0 == 0x00f4
                    00F4    234 _P1SEL	=	0x00f4
                    00F5    235 FInterpolate$P2SEL$0$0 == 0x00f5
                    00F5    236 _P2SEL	=	0x00f5
                    00F6    237 FInterpolate$P1INP$0$0 == 0x00f6
                    00F6    238 _P1INP	=	0x00f6
                    00F7    239 FInterpolate$P2INP$0$0 == 0x00f7
                    00F7    240 _P2INP	=	0x00f7
                    00F8    241 FInterpolate$U1CSR$0$0 == 0x00f8
                    00F8    242 _U1CSR	=	0x00f8
                    00F9    243 FInterpolate$U1DBUF$0$0 == 0x00f9
                    00F9    244 _U1DBUF	=	0x00f9
                    00FA    245 FInterpolate$U1BAUD$0$0 == 0x00fa
                    00FA    246 _U1BAUD	=	0x00fa
                    00FB    247 FInterpolate$U1UCR$0$0 == 0x00fb
                    00FB    248 _U1UCR	=	0x00fb
                    00FC    249 FInterpolate$U1GCR$0$0 == 0x00fc
                    00FC    250 _U1GCR	=	0x00fc
                    00FD    251 FInterpolate$P0DIR$0$0 == 0x00fd
                    00FD    252 _P0DIR	=	0x00fd
                    00FE    253 FInterpolate$P1DIR$0$0 == 0x00fe
                    00FE    254 _P1DIR	=	0x00fe
                    00FF    255 FInterpolate$P2DIR$0$0 == 0x00ff
                    00FF    256 _P2DIR	=	0x00ff
                    FFFFD5D4    257 FInterpolate$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    258 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    259 FInterpolate$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    260 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    261 FInterpolate$FADDR$0$0 == 0xffffadac
                    FFFFADAC    262 _FADDR	=	0xffffadac
                    FFFFBBBA    263 FInterpolate$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    264 _ADC	=	0xffffbbba
                    FFFFDBDA    265 FInterpolate$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    266 _T1CC0	=	0xffffdbda
                    FFFFDDDC    267 FInterpolate$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    268 _T1CC1	=	0xffffdddc
                    FFFFDFDE    269 FInterpolate$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    270 _T1CC2	=	0xffffdfde
                            271 ;--------------------------------------------------------
                            272 ; special function bits
                            273 ;--------------------------------------------------------
                            274 	.area RSEG    (ABS,DATA)
   0000                     275 	.org 0x0000
                    0080    276 FInterpolate$P0_0$0$0 == 0x0080
                    0080    277 _P0_0	=	0x0080
                    0081    278 FInterpolate$P0_1$0$0 == 0x0081
                    0081    279 _P0_1	=	0x0081
                    0082    280 FInterpolate$P0_2$0$0 == 0x0082
                    0082    281 _P0_2	=	0x0082
                    0083    282 FInterpolate$P0_3$0$0 == 0x0083
                    0083    283 _P0_3	=	0x0083
                    0084    284 FInterpolate$P0_4$0$0 == 0x0084
                    0084    285 _P0_4	=	0x0084
                    0085    286 FInterpolate$P0_5$0$0 == 0x0085
                    0085    287 _P0_5	=	0x0085
                    0086    288 FInterpolate$P0_6$0$0 == 0x0086
                    0086    289 _P0_6	=	0x0086
                    0087    290 FInterpolate$P0_7$0$0 == 0x0087
                    0087    291 _P0_7	=	0x0087
                    0088    292 FInterpolate$_TCON_0$0$0 == 0x0088
                    0088    293 __TCON_0	=	0x0088
                    0089    294 FInterpolate$RFTXRXIF$0$0 == 0x0089
                    0089    295 _RFTXRXIF	=	0x0089
                    008A    296 FInterpolate$_TCON_2$0$0 == 0x008a
                    008A    297 __TCON_2	=	0x008a
                    008B    298 FInterpolate$URX0IF$0$0 == 0x008b
                    008B    299 _URX0IF	=	0x008b
                    008C    300 FInterpolate$_TCON_4$0$0 == 0x008c
                    008C    301 __TCON_4	=	0x008c
                    008D    302 FInterpolate$ADCIF$0$0 == 0x008d
                    008D    303 _ADCIF	=	0x008d
                    008E    304 FInterpolate$_TCON_6$0$0 == 0x008e
                    008E    305 __TCON_6	=	0x008e
                    008F    306 FInterpolate$URX1IF$0$0 == 0x008f
                    008F    307 _URX1IF	=	0x008f
                    0090    308 FInterpolate$P1_0$0$0 == 0x0090
                    0090    309 _P1_0	=	0x0090
                    0091    310 FInterpolate$P1_1$0$0 == 0x0091
                    0091    311 _P1_1	=	0x0091
                    0092    312 FInterpolate$P1_2$0$0 == 0x0092
                    0092    313 _P1_2	=	0x0092
                    0093    314 FInterpolate$P1_3$0$0 == 0x0093
                    0093    315 _P1_3	=	0x0093
                    0094    316 FInterpolate$P1_4$0$0 == 0x0094
                    0094    317 _P1_4	=	0x0094
                    0095    318 FInterpolate$P1_5$0$0 == 0x0095
                    0095    319 _P1_5	=	0x0095
                    0096    320 FInterpolate$P1_6$0$0 == 0x0096
                    0096    321 _P1_6	=	0x0096
                    0097    322 FInterpolate$P1_7$0$0 == 0x0097
                    0097    323 _P1_7	=	0x0097
                    0098    324 FInterpolate$ENCIF_0$0$0 == 0x0098
                    0098    325 _ENCIF_0	=	0x0098
                    0099    326 FInterpolate$ENCIF_1$0$0 == 0x0099
                    0099    327 _ENCIF_1	=	0x0099
                    009A    328 FInterpolate$_SOCON2$0$0 == 0x009a
                    009A    329 __SOCON2	=	0x009a
                    009B    330 FInterpolate$_SOCON3$0$0 == 0x009b
                    009B    331 __SOCON3	=	0x009b
                    009C    332 FInterpolate$_SOCON4$0$0 == 0x009c
                    009C    333 __SOCON4	=	0x009c
                    009D    334 FInterpolate$_SOCON5$0$0 == 0x009d
                    009D    335 __SOCON5	=	0x009d
                    009E    336 FInterpolate$_SOCON6$0$0 == 0x009e
                    009E    337 __SOCON6	=	0x009e
                    009F    338 FInterpolate$_SOCON7$0$0 == 0x009f
                    009F    339 __SOCON7	=	0x009f
                    00A0    340 FInterpolate$P2_0$0$0 == 0x00a0
                    00A0    341 _P2_0	=	0x00a0
                    00A1    342 FInterpolate$P2_1$0$0 == 0x00a1
                    00A1    343 _P2_1	=	0x00a1
                    00A2    344 FInterpolate$P2_2$0$0 == 0x00a2
                    00A2    345 _P2_2	=	0x00a2
                    00A3    346 FInterpolate$P2_3$0$0 == 0x00a3
                    00A3    347 _P2_3	=	0x00a3
                    00A4    348 FInterpolate$P2_4$0$0 == 0x00a4
                    00A4    349 _P2_4	=	0x00a4
                    00A5    350 FInterpolate$P2_5$0$0 == 0x00a5
                    00A5    351 _P2_5	=	0x00a5
                    00A6    352 FInterpolate$P2_6$0$0 == 0x00a6
                    00A6    353 _P2_6	=	0x00a6
                    00A7    354 FInterpolate$P2_7$0$0 == 0x00a7
                    00A7    355 _P2_7	=	0x00a7
                    00A8    356 FInterpolate$RFTXRXIE$0$0 == 0x00a8
                    00A8    357 _RFTXRXIE	=	0x00a8
                    00A9    358 FInterpolate$ADCIE$0$0 == 0x00a9
                    00A9    359 _ADCIE	=	0x00a9
                    00AA    360 FInterpolate$URX0IE$0$0 == 0x00aa
                    00AA    361 _URX0IE	=	0x00aa
                    00AB    362 FInterpolate$URX1IE$0$0 == 0x00ab
                    00AB    363 _URX1IE	=	0x00ab
                    00AC    364 FInterpolate$ENCIE$0$0 == 0x00ac
                    00AC    365 _ENCIE	=	0x00ac
                    00AD    366 FInterpolate$STIE$0$0 == 0x00ad
                    00AD    367 _STIE	=	0x00ad
                    00AE    368 FInterpolate$_IEN06$0$0 == 0x00ae
                    00AE    369 __IEN06	=	0x00ae
                    00AF    370 FInterpolate$EA$0$0 == 0x00af
                    00AF    371 _EA	=	0x00af
                    00B8    372 FInterpolate$DMAIE$0$0 == 0x00b8
                    00B8    373 _DMAIE	=	0x00b8
                    00B9    374 FInterpolate$T1IE$0$0 == 0x00b9
                    00B9    375 _T1IE	=	0x00b9
                    00BA    376 FInterpolate$T2IE$0$0 == 0x00ba
                    00BA    377 _T2IE	=	0x00ba
                    00BB    378 FInterpolate$T3IE$0$0 == 0x00bb
                    00BB    379 _T3IE	=	0x00bb
                    00BC    380 FInterpolate$T4IE$0$0 == 0x00bc
                    00BC    381 _T4IE	=	0x00bc
                    00BD    382 FInterpolate$P0IE$0$0 == 0x00bd
                    00BD    383 _P0IE	=	0x00bd
                    00BE    384 FInterpolate$_IEN16$0$0 == 0x00be
                    00BE    385 __IEN16	=	0x00be
                    00BF    386 FInterpolate$_IEN17$0$0 == 0x00bf
                    00BF    387 __IEN17	=	0x00bf
                    00C0    388 FInterpolate$DMAIF$0$0 == 0x00c0
                    00C0    389 _DMAIF	=	0x00c0
                    00C1    390 FInterpolate$T1IF$0$0 == 0x00c1
                    00C1    391 _T1IF	=	0x00c1
                    00C2    392 FInterpolate$T2IF$0$0 == 0x00c2
                    00C2    393 _T2IF	=	0x00c2
                    00C3    394 FInterpolate$T3IF$0$0 == 0x00c3
                    00C3    395 _T3IF	=	0x00c3
                    00C4    396 FInterpolate$T4IF$0$0 == 0x00c4
                    00C4    397 _T4IF	=	0x00c4
                    00C5    398 FInterpolate$P0IF$0$0 == 0x00c5
                    00C5    399 _P0IF	=	0x00c5
                    00C6    400 FInterpolate$_IRCON6$0$0 == 0x00c6
                    00C6    401 __IRCON6	=	0x00c6
                    00C7    402 FInterpolate$STIF$0$0 == 0x00c7
                    00C7    403 _STIF	=	0x00c7
                    00D0    404 FInterpolate$P$0$0 == 0x00d0
                    00D0    405 _P	=	0x00d0
                    00D1    406 FInterpolate$F1$0$0 == 0x00d1
                    00D1    407 _F1	=	0x00d1
                    00D2    408 FInterpolate$OV$0$0 == 0x00d2
                    00D2    409 _OV	=	0x00d2
                    00D3    410 FInterpolate$RS0$0$0 == 0x00d3
                    00D3    411 _RS0	=	0x00d3
                    00D4    412 FInterpolate$RS1$0$0 == 0x00d4
                    00D4    413 _RS1	=	0x00d4
                    00D5    414 FInterpolate$F0$0$0 == 0x00d5
                    00D5    415 _F0	=	0x00d5
                    00D6    416 FInterpolate$AC$0$0 == 0x00d6
                    00D6    417 _AC	=	0x00d6
                    00D7    418 FInterpolate$CY$0$0 == 0x00d7
                    00D7    419 _CY	=	0x00d7
                    00D8    420 FInterpolate$T3OVFIF$0$0 == 0x00d8
                    00D8    421 _T3OVFIF	=	0x00d8
                    00D9    422 FInterpolate$T3CH0IF$0$0 == 0x00d9
                    00D9    423 _T3CH0IF	=	0x00d9
                    00DA    424 FInterpolate$T3CH1IF$0$0 == 0x00da
                    00DA    425 _T3CH1IF	=	0x00da
                    00DB    426 FInterpolate$T4OVFIF$0$0 == 0x00db
                    00DB    427 _T4OVFIF	=	0x00db
                    00DC    428 FInterpolate$T4CH0IF$0$0 == 0x00dc
                    00DC    429 _T4CH0IF	=	0x00dc
                    00DD    430 FInterpolate$T4CH1IF$0$0 == 0x00dd
                    00DD    431 _T4CH1IF	=	0x00dd
                    00DE    432 FInterpolate$OVFIM$0$0 == 0x00de
                    00DE    433 _OVFIM	=	0x00de
                    00DF    434 FInterpolate$_TIMIF7$0$0 == 0x00df
                    00DF    435 __TIMIF7	=	0x00df
                    00E0    436 FInterpolate$ACC_0$0$0 == 0x00e0
                    00E0    437 _ACC_0	=	0x00e0
                    00E1    438 FInterpolate$ACC_1$0$0 == 0x00e1
                    00E1    439 _ACC_1	=	0x00e1
                    00E2    440 FInterpolate$ACC_2$0$0 == 0x00e2
                    00E2    441 _ACC_2	=	0x00e2
                    00E3    442 FInterpolate$ACC_3$0$0 == 0x00e3
                    00E3    443 _ACC_3	=	0x00e3
                    00E4    444 FInterpolate$ACC_4$0$0 == 0x00e4
                    00E4    445 _ACC_4	=	0x00e4
                    00E5    446 FInterpolate$ACC_5$0$0 == 0x00e5
                    00E5    447 _ACC_5	=	0x00e5
                    00E6    448 FInterpolate$ACC_6$0$0 == 0x00e6
                    00E6    449 _ACC_6	=	0x00e6
                    00E7    450 FInterpolate$ACC_7$0$0 == 0x00e7
                    00E7    451 _ACC_7	=	0x00e7
                    00E8    452 FInterpolate$P2IF$0$0 == 0x00e8
                    00E8    453 _P2IF	=	0x00e8
                    00E9    454 FInterpolate$UTX0IF$0$0 == 0x00e9
                    00E9    455 _UTX0IF	=	0x00e9
                    00EA    456 FInterpolate$UTX1IF$0$0 == 0x00ea
                    00EA    457 _UTX1IF	=	0x00ea
                    00EB    458 FInterpolate$P1IF$0$0 == 0x00eb
                    00EB    459 _P1IF	=	0x00eb
                    00EC    460 FInterpolate$WDTIF$0$0 == 0x00ec
                    00EC    461 _WDTIF	=	0x00ec
                    00ED    462 FInterpolate$_IRCON25$0$0 == 0x00ed
                    00ED    463 __IRCON25	=	0x00ed
                    00EE    464 FInterpolate$_IRCON26$0$0 == 0x00ee
                    00EE    465 __IRCON26	=	0x00ee
                    00EF    466 FInterpolate$_IRCON27$0$0 == 0x00ef
                    00EF    467 __IRCON27	=	0x00ef
                    00F0    468 FInterpolate$B_0$0$0 == 0x00f0
                    00F0    469 _B_0	=	0x00f0
                    00F1    470 FInterpolate$B_1$0$0 == 0x00f1
                    00F1    471 _B_1	=	0x00f1
                    00F2    472 FInterpolate$B_2$0$0 == 0x00f2
                    00F2    473 _B_2	=	0x00f2
                    00F3    474 FInterpolate$B_3$0$0 == 0x00f3
                    00F3    475 _B_3	=	0x00f3
                    00F4    476 FInterpolate$B_4$0$0 == 0x00f4
                    00F4    477 _B_4	=	0x00f4
                    00F5    478 FInterpolate$B_5$0$0 == 0x00f5
                    00F5    479 _B_5	=	0x00f5
                    00F6    480 FInterpolate$B_6$0$0 == 0x00f6
                    00F6    481 _B_6	=	0x00f6
                    00F7    482 FInterpolate$B_7$0$0 == 0x00f7
                    00F7    483 _B_7	=	0x00f7
                    00F8    484 FInterpolate$U1ACTIVE$0$0 == 0x00f8
                    00F8    485 _U1ACTIVE	=	0x00f8
                    00F9    486 FInterpolate$U1TX_BYTE$0$0 == 0x00f9
                    00F9    487 _U1TX_BYTE	=	0x00f9
                    00FA    488 FInterpolate$U1RX_BYTE$0$0 == 0x00fa
                    00FA    489 _U1RX_BYTE	=	0x00fa
                    00FB    490 FInterpolate$U1ERR$0$0 == 0x00fb
                    00FB    491 _U1ERR	=	0x00fb
                    00FC    492 FInterpolate$U1FE$0$0 == 0x00fc
                    00FC    493 _U1FE	=	0x00fc
                    00FD    494 FInterpolate$U1SLAVE$0$0 == 0x00fd
                    00FD    495 _U1SLAVE	=	0x00fd
                    00FE    496 FInterpolate$U1RE$0$0 == 0x00fe
                    00FE    497 _U1RE	=	0x00fe
                    00FF    498 FInterpolate$U1MODE$0$0 == 0x00ff
                    00FF    499 _U1MODE	=	0x00ff
                            500 ;--------------------------------------------------------
                            501 ; overlayable register banks
                            502 ;--------------------------------------------------------
                            503 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     504 	.ds 8
                            505 ;--------------------------------------------------------
                            506 ; internal ram data
                            507 ;--------------------------------------------------------
                            508 	.area DSEG    (DATA)
                    0000    509 LInterpolate.interpolate$lRtnRange$1$1==.
   0024                     510 _interpolate_lRtnRange_1_1:
   0024                     511 	.ds 4
                    0004    512 LInterpolate.interpolate$lValRange$1$1==.
   0028                     513 _interpolate_lValRange_1_1:
   0028                     514 	.ds 4
                    0008    515 LInterpolate.interpolate$sloc0$1$0==.
   002C                     516 _interpolate_sloc0_1_0:
   002C                     517 	.ds 4
                    000C    518 LInterpolate.interpolateU$lRtnRange$1$1==.
   0030                     519 _interpolateU_lRtnRange_1_1:
   0030                     520 	.ds 4
                    0010    521 LInterpolate.interpolateU$lValRange$1$1==.
   0034                     522 _interpolateU_lValRange_1_1:
   0034                     523 	.ds 4
                    0014    524 LInterpolate.interpolateU$lRelVal$1$1==.
   0038                     525 _interpolateU_lRelVal_1_1:
   0038                     526 	.ds 4
                            527 ;--------------------------------------------------------
                            528 ; overlayable items in internal ram 
                            529 ;--------------------------------------------------------
                            530 	.area OSEG    (OVR,DATA)
                            531 ;--------------------------------------------------------
                            532 ; indirectly addressable internal ram data
                            533 ;--------------------------------------------------------
                            534 	.area ISEG    (DATA)
                            535 ;--------------------------------------------------------
                            536 ; absolute internal ram data
                            537 ;--------------------------------------------------------
                            538 	.area IABS    (ABS,DATA)
                            539 	.area IABS    (ABS,DATA)
                            540 ;--------------------------------------------------------
                            541 ; bit data
                            542 ;--------------------------------------------------------
                            543 	.area BSEG    (BIT)
                            544 ;--------------------------------------------------------
                            545 ; paged external ram data
                            546 ;--------------------------------------------------------
                            547 	.area PSEG    (PAG,XDATA)
                    0000    548 LInterpolate.interpolate$minVal$1$1==.
   F023                     549 _interpolate_PARM_2:
   F023                     550 	.ds 2
                    0002    551 LInterpolate.interpolate$maxVal$1$1==.
   F025                     552 _interpolate_PARM_3:
   F025                     553 	.ds 2
                    0004    554 LInterpolate.interpolate$minRtn$1$1==.
   F027                     555 _interpolate_PARM_4:
   F027                     556 	.ds 2
                    0006    557 LInterpolate.interpolate$maxRtn$1$1==.
   F029                     558 _interpolate_PARM_5:
   F029                     559 	.ds 2
                    0008    560 LInterpolate.interpolateU$minVal$1$1==.
   F02B                     561 _interpolateU_PARM_2:
   F02B                     562 	.ds 2
                    000A    563 LInterpolate.interpolateU$maxVal$1$1==.
   F02D                     564 _interpolateU_PARM_3:
   F02D                     565 	.ds 2
                    000C    566 LInterpolate.interpolateU$minRtn$1$1==.
   F02F                     567 _interpolateU_PARM_4:
   F02F                     568 	.ds 2
                    000E    569 LInterpolate.interpolateU$maxRtn$1$1==.
   F031                     570 _interpolateU_PARM_5:
   F031                     571 	.ds 2
                            572 ;--------------------------------------------------------
                            573 ; external ram data
                            574 ;--------------------------------------------------------
                            575 	.area XSEG    (XDATA)
                    DF00    576 FInterpolate$SYNC1$0$0 == 0xdf00
                    DF00    577 _SYNC1	=	0xdf00
                    DF01    578 FInterpolate$SYNC0$0$0 == 0xdf01
                    DF01    579 _SYNC0	=	0xdf01
                    DF02    580 FInterpolate$PKTLEN$0$0 == 0xdf02
                    DF02    581 _PKTLEN	=	0xdf02
                    DF03    582 FInterpolate$PKTCTRL1$0$0 == 0xdf03
                    DF03    583 _PKTCTRL1	=	0xdf03
                    DF04    584 FInterpolate$PKTCTRL0$0$0 == 0xdf04
                    DF04    585 _PKTCTRL0	=	0xdf04
                    DF05    586 FInterpolate$ADDR$0$0 == 0xdf05
                    DF05    587 _ADDR	=	0xdf05
                    DF06    588 FInterpolate$CHANNR$0$0 == 0xdf06
                    DF06    589 _CHANNR	=	0xdf06
                    DF07    590 FInterpolate$FSCTRL1$0$0 == 0xdf07
                    DF07    591 _FSCTRL1	=	0xdf07
                    DF08    592 FInterpolate$FSCTRL0$0$0 == 0xdf08
                    DF08    593 _FSCTRL0	=	0xdf08
                    DF09    594 FInterpolate$FREQ2$0$0 == 0xdf09
                    DF09    595 _FREQ2	=	0xdf09
                    DF0A    596 FInterpolate$FREQ1$0$0 == 0xdf0a
                    DF0A    597 _FREQ1	=	0xdf0a
                    DF0B    598 FInterpolate$FREQ0$0$0 == 0xdf0b
                    DF0B    599 _FREQ0	=	0xdf0b
                    DF0C    600 FInterpolate$MDMCFG4$0$0 == 0xdf0c
                    DF0C    601 _MDMCFG4	=	0xdf0c
                    DF0D    602 FInterpolate$MDMCFG3$0$0 == 0xdf0d
                    DF0D    603 _MDMCFG3	=	0xdf0d
                    DF0E    604 FInterpolate$MDMCFG2$0$0 == 0xdf0e
                    DF0E    605 _MDMCFG2	=	0xdf0e
                    DF0F    606 FInterpolate$MDMCFG1$0$0 == 0xdf0f
                    DF0F    607 _MDMCFG1	=	0xdf0f
                    DF10    608 FInterpolate$MDMCFG0$0$0 == 0xdf10
                    DF10    609 _MDMCFG0	=	0xdf10
                    DF11    610 FInterpolate$DEVIATN$0$0 == 0xdf11
                    DF11    611 _DEVIATN	=	0xdf11
                    DF12    612 FInterpolate$MCSM2$0$0 == 0xdf12
                    DF12    613 _MCSM2	=	0xdf12
                    DF13    614 FInterpolate$MCSM1$0$0 == 0xdf13
                    DF13    615 _MCSM1	=	0xdf13
                    DF14    616 FInterpolate$MCSM0$0$0 == 0xdf14
                    DF14    617 _MCSM0	=	0xdf14
                    DF15    618 FInterpolate$FOCCFG$0$0 == 0xdf15
                    DF15    619 _FOCCFG	=	0xdf15
                    DF16    620 FInterpolate$BSCFG$0$0 == 0xdf16
                    DF16    621 _BSCFG	=	0xdf16
                    DF17    622 FInterpolate$AGCCTRL2$0$0 == 0xdf17
                    DF17    623 _AGCCTRL2	=	0xdf17
                    DF18    624 FInterpolate$AGCCTRL1$0$0 == 0xdf18
                    DF18    625 _AGCCTRL1	=	0xdf18
                    DF19    626 FInterpolate$AGCCTRL0$0$0 == 0xdf19
                    DF19    627 _AGCCTRL0	=	0xdf19
                    DF1A    628 FInterpolate$FREND1$0$0 == 0xdf1a
                    DF1A    629 _FREND1	=	0xdf1a
                    DF1B    630 FInterpolate$FREND0$0$0 == 0xdf1b
                    DF1B    631 _FREND0	=	0xdf1b
                    DF1C    632 FInterpolate$FSCAL3$0$0 == 0xdf1c
                    DF1C    633 _FSCAL3	=	0xdf1c
                    DF1D    634 FInterpolate$FSCAL2$0$0 == 0xdf1d
                    DF1D    635 _FSCAL2	=	0xdf1d
                    DF1E    636 FInterpolate$FSCAL1$0$0 == 0xdf1e
                    DF1E    637 _FSCAL1	=	0xdf1e
                    DF1F    638 FInterpolate$FSCAL0$0$0 == 0xdf1f
                    DF1F    639 _FSCAL0	=	0xdf1f
                    DF23    640 FInterpolate$TEST2$0$0 == 0xdf23
                    DF23    641 _TEST2	=	0xdf23
                    DF24    642 FInterpolate$TEST1$0$0 == 0xdf24
                    DF24    643 _TEST1	=	0xdf24
                    DF25    644 FInterpolate$TEST0$0$0 == 0xdf25
                    DF25    645 _TEST0	=	0xdf25
                    DF2E    646 FInterpolate$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    647 _PA_TABLE0	=	0xdf2e
                    DF2F    648 FInterpolate$IOCFG2$0$0 == 0xdf2f
                    DF2F    649 _IOCFG2	=	0xdf2f
                    DF30    650 FInterpolate$IOCFG1$0$0 == 0xdf30
                    DF30    651 _IOCFG1	=	0xdf30
                    DF31    652 FInterpolate$IOCFG0$0$0 == 0xdf31
                    DF31    653 _IOCFG0	=	0xdf31
                    DF36    654 FInterpolate$PARTNUM$0$0 == 0xdf36
                    DF36    655 _PARTNUM	=	0xdf36
                    DF37    656 FInterpolate$VERSION$0$0 == 0xdf37
                    DF37    657 _VERSION	=	0xdf37
                    DF38    658 FInterpolate$FREQEST$0$0 == 0xdf38
                    DF38    659 _FREQEST	=	0xdf38
                    DF39    660 FInterpolate$LQI$0$0 == 0xdf39
                    DF39    661 _LQI	=	0xdf39
                    DF3A    662 FInterpolate$RSSI$0$0 == 0xdf3a
                    DF3A    663 _RSSI	=	0xdf3a
                    DF3B    664 FInterpolate$MARCSTATE$0$0 == 0xdf3b
                    DF3B    665 _MARCSTATE	=	0xdf3b
                    DF3C    666 FInterpolate$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    667 _PKTSTATUS	=	0xdf3c
                    DF3D    668 FInterpolate$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    669 _VCO_VC_DAC	=	0xdf3d
                    DF40    670 FInterpolate$I2SCFG0$0$0 == 0xdf40
                    DF40    671 _I2SCFG0	=	0xdf40
                    DF41    672 FInterpolate$I2SCFG1$0$0 == 0xdf41
                    DF41    673 _I2SCFG1	=	0xdf41
                    DF42    674 FInterpolate$I2SDATL$0$0 == 0xdf42
                    DF42    675 _I2SDATL	=	0xdf42
                    DF43    676 FInterpolate$I2SDATH$0$0 == 0xdf43
                    DF43    677 _I2SDATH	=	0xdf43
                    DF44    678 FInterpolate$I2SWCNT$0$0 == 0xdf44
                    DF44    679 _I2SWCNT	=	0xdf44
                    DF45    680 FInterpolate$I2SSTAT$0$0 == 0xdf45
                    DF45    681 _I2SSTAT	=	0xdf45
                    DF46    682 FInterpolate$I2SCLKF0$0$0 == 0xdf46
                    DF46    683 _I2SCLKF0	=	0xdf46
                    DF47    684 FInterpolate$I2SCLKF1$0$0 == 0xdf47
                    DF47    685 _I2SCLKF1	=	0xdf47
                    DF48    686 FInterpolate$I2SCLKF2$0$0 == 0xdf48
                    DF48    687 _I2SCLKF2	=	0xdf48
                    DE00    688 FInterpolate$USBADDR$0$0 == 0xde00
                    DE00    689 _USBADDR	=	0xde00
                    DE01    690 FInterpolate$USBPOW$0$0 == 0xde01
                    DE01    691 _USBPOW	=	0xde01
                    DE02    692 FInterpolate$USBIIF$0$0 == 0xde02
                    DE02    693 _USBIIF	=	0xde02
                    DE04    694 FInterpolate$USBOIF$0$0 == 0xde04
                    DE04    695 _USBOIF	=	0xde04
                    DE06    696 FInterpolate$USBCIF$0$0 == 0xde06
                    DE06    697 _USBCIF	=	0xde06
                    DE07    698 FInterpolate$USBIIE$0$0 == 0xde07
                    DE07    699 _USBIIE	=	0xde07
                    DE09    700 FInterpolate$USBOIE$0$0 == 0xde09
                    DE09    701 _USBOIE	=	0xde09
                    DE0B    702 FInterpolate$USBCIE$0$0 == 0xde0b
                    DE0B    703 _USBCIE	=	0xde0b
                    DE0C    704 FInterpolate$USBFRML$0$0 == 0xde0c
                    DE0C    705 _USBFRML	=	0xde0c
                    DE0D    706 FInterpolate$USBFRMH$0$0 == 0xde0d
                    DE0D    707 _USBFRMH	=	0xde0d
                    DE0E    708 FInterpolate$USBINDEX$0$0 == 0xde0e
                    DE0E    709 _USBINDEX	=	0xde0e
                    DE10    710 FInterpolate$USBMAXI$0$0 == 0xde10
                    DE10    711 _USBMAXI	=	0xde10
                    DE11    712 FInterpolate$USBCSIL$0$0 == 0xde11
                    DE11    713 _USBCSIL	=	0xde11
                    DE12    714 FInterpolate$USBCSIH$0$0 == 0xde12
                    DE12    715 _USBCSIH	=	0xde12
                    DE13    716 FInterpolate$USBMAXO$0$0 == 0xde13
                    DE13    717 _USBMAXO	=	0xde13
                    DE14    718 FInterpolate$USBCSOL$0$0 == 0xde14
                    DE14    719 _USBCSOL	=	0xde14
                    DE15    720 FInterpolate$USBCSOH$0$0 == 0xde15
                    DE15    721 _USBCSOH	=	0xde15
                    DE16    722 FInterpolate$USBCNTL$0$0 == 0xde16
                    DE16    723 _USBCNTL	=	0xde16
                    DE17    724 FInterpolate$USBCNTH$0$0 == 0xde17
                    DE17    725 _USBCNTH	=	0xde17
                    DE20    726 FInterpolate$USBF0$0$0 == 0xde20
                    DE20    727 _USBF0	=	0xde20
                    DE22    728 FInterpolate$USBF1$0$0 == 0xde22
                    DE22    729 _USBF1	=	0xde22
                    DE24    730 FInterpolate$USBF2$0$0 == 0xde24
                    DE24    731 _USBF2	=	0xde24
                    DE26    732 FInterpolate$USBF3$0$0 == 0xde26
                    DE26    733 _USBF3	=	0xde26
                    DE28    734 FInterpolate$USBF4$0$0 == 0xde28
                    DE28    735 _USBF4	=	0xde28
                    DE2A    736 FInterpolate$USBF5$0$0 == 0xde2a
                    DE2A    737 _USBF5	=	0xde2a
                            738 ;--------------------------------------------------------
                            739 ; absolute external ram data
                            740 ;--------------------------------------------------------
                            741 	.area XABS    (ABS,XDATA)
                            742 ;--------------------------------------------------------
                            743 ; external initialized ram data
                            744 ;--------------------------------------------------------
                            745 	.area XISEG   (XDATA)
                            746 	.area HOME    (CODE)
                            747 	.area GSINIT0 (CODE)
                            748 	.area GSINIT1 (CODE)
                            749 	.area GSINIT2 (CODE)
                            750 	.area GSINIT3 (CODE)
                            751 	.area GSINIT4 (CODE)
                            752 	.area GSINIT5 (CODE)
                            753 	.area GSINIT  (CODE)
                            754 	.area GSFINAL (CODE)
                            755 	.area CSEG    (CODE)
                            756 ;--------------------------------------------------------
                            757 ; global & static initialisations
                            758 ;--------------------------------------------------------
                            759 	.area HOME    (CODE)
                            760 	.area GSINIT  (CODE)
                            761 	.area GSFINAL (CODE)
                            762 	.area GSINIT  (CODE)
                            763 ;--------------------------------------------------------
                            764 ; Home
                            765 ;--------------------------------------------------------
                            766 	.area HOME    (CODE)
                            767 	.area HOME    (CODE)
                            768 ;--------------------------------------------------------
                            769 ; code
                            770 ;--------------------------------------------------------
                            771 	.area CSEG    (CODE)
                            772 ;------------------------------------------------------------
                            773 ;Allocation info for local variables in function 'interpolate'
                            774 ;------------------------------------------------------------
                            775 ;lRtnRange                 Allocated with name '_interpolate_lRtnRange_1_1'
                            776 ;lValRange                 Allocated with name '_interpolate_lValRange_1_1'
                            777 ;lRelVal                   Allocated to registers 
                            778 ;sloc0                     Allocated with name '_interpolate_sloc0_1_0'
                            779 ;------------------------------------------------------------
                    0000    780 	G$interpolate$0$0 ==.
                    0000    781 	C$Interpolate.c$16$0$0 ==.
                            782 ;	apps/twitch_mx_servos/Interpolate.c:16: int16 interpolate(int16 value, int16 minVal, int16 maxVal, int16 minRtn, int16 maxRtn){
                            783 ;	-----------------------------------------
                            784 ;	 function interpolate
                            785 ;	-----------------------------------------
   0A16                     786 _interpolate:
                    0007    787 	ar7 = 0x07
                    0006    788 	ar6 = 0x06
                    0005    789 	ar5 = 0x05
                    0004    790 	ar4 = 0x04
                    0003    791 	ar3 = 0x03
                    0002    792 	ar2 = 0x02
                    0001    793 	ar1 = 0x01
                    0000    794 	ar0 = 0x00
   0A16 AE 82               795 	mov	r6,dpl
   0A18 AF 83               796 	mov	r7,dph
                    0004    797 	C$Interpolate.c$21$1$1 ==.
                            798 ;	apps/twitch_mx_servos/Interpolate.c:21: lRtnRange = maxRtn - minRtn;
   0A1A 78 29               799 	mov	r0,#_interpolate_PARM_5
   0A1C 79 27               800 	mov	r1,#_interpolate_PARM_4
   0A1E E3                  801 	movx	a,@r1
   0A1F F5 F0               802 	mov	b,a
   0A21 C3                  803 	clr	c
   0A22 E2                  804 	movx	a,@r0
   0A23 95 F0               805 	subb	a,b
   0A25 FC                  806 	mov	r4,a
   0A26 09                  807 	inc	r1
   0A27 E3                  808 	movx	a,@r1
   0A28 F5 F0               809 	mov	b,a
   0A2A 08                  810 	inc	r0
   0A2B E2                  811 	movx	a,@r0
   0A2C 95 F0               812 	subb	a,b
   0A2E FD                  813 	mov	r5,a
   0A2F 8C 24               814 	mov	_interpolate_lRtnRange_1_1,r4
   0A31 ED                  815 	mov	a,r5
   0A32 F5 25               816 	mov	(_interpolate_lRtnRange_1_1 + 1),a
   0A34 33                  817 	rlc	a
   0A35 95 E0               818 	subb	a,acc
   0A37 F5 26               819 	mov	(_interpolate_lRtnRange_1_1 + 2),a
   0A39 F5 27               820 	mov	(_interpolate_lRtnRange_1_1 + 3),a
                    0025    821 	C$Interpolate.c$22$1$1 ==.
                            822 ;	apps/twitch_mx_servos/Interpolate.c:22: lValRange = maxVal - minVal;
   0A3B 78 25               823 	mov	r0,#_interpolate_PARM_3
   0A3D 79 23               824 	mov	r1,#_interpolate_PARM_2
   0A3F E3                  825 	movx	a,@r1
   0A40 F5 F0               826 	mov	b,a
   0A42 C3                  827 	clr	c
   0A43 E2                  828 	movx	a,@r0
   0A44 95 F0               829 	subb	a,b
   0A46 FC                  830 	mov	r4,a
   0A47 09                  831 	inc	r1
   0A48 E3                  832 	movx	a,@r1
   0A49 F5 F0               833 	mov	b,a
   0A4B 08                  834 	inc	r0
   0A4C E2                  835 	movx	a,@r0
   0A4D 95 F0               836 	subb	a,b
   0A4F FD                  837 	mov	r5,a
   0A50 8C 28               838 	mov	_interpolate_lValRange_1_1,r4
   0A52 ED                  839 	mov	a,r5
   0A53 F5 29               840 	mov	(_interpolate_lValRange_1_1 + 1),a
   0A55 33                  841 	rlc	a
   0A56 95 E0               842 	subb	a,acc
   0A58 F5 2A               843 	mov	(_interpolate_lValRange_1_1 + 2),a
   0A5A F5 2B               844 	mov	(_interpolate_lValRange_1_1 + 3),a
                    0046    845 	C$Interpolate.c$23$1$1 ==.
                            846 ;	apps/twitch_mx_servos/Interpolate.c:23: lRelVal = value - minVal;
   0A5C 78 23               847 	mov	r0,#_interpolate_PARM_2
   0A5E D3                  848 	setb	c
   0A5F E2                  849 	movx	a,@r0
   0A60 9E                  850 	subb	a,r6
   0A61 F4                  851 	cpl	a
   0A62 B3                  852 	cpl	c
   0A63 FE                  853 	mov	r6,a
   0A64 B3                  854 	cpl	c
   0A65 08                  855 	inc	r0
   0A66 E2                  856 	movx	a,@r0
   0A67 9F                  857 	subb	a,r7
   0A68 F4                  858 	cpl	a
   0A69 FF                  859 	mov	r7,a
   0A6A 78 ED               860 	mov	r0,#__mullong_PARM_2
   0A6C EE                  861 	mov	a,r6
   0A6D F2                  862 	movx	@r0,a
   0A6E 08                  863 	inc	r0
   0A6F EF                  864 	mov	a,r7
   0A70 F2                  865 	movx	@r0,a
   0A71 EF                  866 	mov	a,r7
   0A72 33                  867 	rlc	a
   0A73 95 E0               868 	subb	a,acc
   0A75 08                  869 	inc	r0
   0A76 F2                  870 	movx	@r0,a
   0A77 08                  871 	inc	r0
   0A78 F2                  872 	movx	@r0,a
                    0063    873 	C$Interpolate.c$24$1$1 ==.
                            874 ;	apps/twitch_mx_servos/Interpolate.c:24: lRtnRange =  minRtn + ( lRtnRange * lRelVal / lValRange );
   0A79 85 24 82            875 	mov	dpl,_interpolate_lRtnRange_1_1
   0A7C 85 25 83            876 	mov	dph,(_interpolate_lRtnRange_1_1 + 1)
   0A7F 85 26 F0            877 	mov	b,(_interpolate_lRtnRange_1_1 + 2)
   0A82 E5 27               878 	mov	a,(_interpolate_lRtnRange_1_1 + 3)
   0A84 12 39 5F            879 	lcall	__mullong
   0A87 AC 82               880 	mov	r4,dpl
   0A89 AD 83               881 	mov	r5,dph
   0A8B AE F0               882 	mov	r6,b
   0A8D FF                  883 	mov	r7,a
   0A8E 78 CD               884 	mov	r0,#__divslong_PARM_2
   0A90 E5 28               885 	mov	a,_interpolate_lValRange_1_1
   0A92 F2                  886 	movx	@r0,a
   0A93 08                  887 	inc	r0
   0A94 E5 29               888 	mov	a,(_interpolate_lValRange_1_1 + 1)
   0A96 F2                  889 	movx	@r0,a
   0A97 08                  890 	inc	r0
   0A98 E5 2A               891 	mov	a,(_interpolate_lValRange_1_1 + 2)
   0A9A F2                  892 	movx	@r0,a
   0A9B 08                  893 	inc	r0
   0A9C E5 2B               894 	mov	a,(_interpolate_lValRange_1_1 + 3)
   0A9E F2                  895 	movx	@r0,a
   0A9F 8C 82               896 	mov	dpl,r4
   0AA1 8D 83               897 	mov	dph,r5
   0AA3 8E F0               898 	mov	b,r6
   0AA5 EF                  899 	mov	a,r7
   0AA6 12 32 F3            900 	lcall	__divslong
   0AA9 85 82 2C            901 	mov	_interpolate_sloc0_1_0,dpl
   0AAC 85 83 2D            902 	mov	(_interpolate_sloc0_1_0 + 1),dph
   0AAF 85 F0 2E            903 	mov	(_interpolate_sloc0_1_0 + 2),b
   0AB2 F5 2F               904 	mov	(_interpolate_sloc0_1_0 + 3),a
   0AB4 78 27               905 	mov	r0,#_interpolate_PARM_4
   0AB6 E2                  906 	movx	a,@r0
   0AB7 FA                  907 	mov	r2,a
   0AB8 08                  908 	inc	r0
   0AB9 E2                  909 	movx	a,@r0
   0ABA FB                  910 	mov	r3,a
   0ABB E2                  911 	movx	a,@r0
   0ABC 33                  912 	rlc	a
   0ABD 95 E0               913 	subb	a,acc
   0ABF FE                  914 	mov	r6,a
   0AC0 FF                  915 	mov	r7,a
   0AC1 E5 2C               916 	mov	a,_interpolate_sloc0_1_0
   0AC3 2A                  917 	add	a,r2
   0AC4 F5 24               918 	mov	_interpolate_lRtnRange_1_1,a
   0AC6 E5 2D               919 	mov	a,(_interpolate_sloc0_1_0 + 1)
   0AC8 3B                  920 	addc	a,r3
   0AC9 F5 25               921 	mov	(_interpolate_lRtnRange_1_1 + 1),a
   0ACB E5 2E               922 	mov	a,(_interpolate_sloc0_1_0 + 2)
   0ACD 3E                  923 	addc	a,r6
   0ACE F5 26               924 	mov	(_interpolate_lRtnRange_1_1 + 2),a
   0AD0 E5 2F               925 	mov	a,(_interpolate_sloc0_1_0 + 3)
   0AD2 3F                  926 	addc	a,r7
   0AD3 F5 27               927 	mov	(_interpolate_lRtnRange_1_1 + 3),a
                    00BF    928 	C$Interpolate.c$25$1$1 ==.
                            929 ;	apps/twitch_mx_servos/Interpolate.c:25: return (int16)lRtnRange;
   0AD5 85 24 82            930 	mov	dpl,_interpolate_lRtnRange_1_1
   0AD8 85 25 83            931 	mov	dph,(_interpolate_lRtnRange_1_1 + 1)
                    00C5    932 	C$Interpolate.c$26$1$1 ==.
                    00C5    933 	XG$interpolate$0$0 ==.
   0ADB 22                  934 	ret
                            935 ;------------------------------------------------------------
                            936 ;Allocation info for local variables in function 'interpolateU'
                            937 ;------------------------------------------------------------
                            938 ;lRtnRange                 Allocated with name '_interpolateU_lRtnRange_1_1'
                            939 ;lValRange                 Allocated with name '_interpolateU_lValRange_1_1'
                            940 ;lRelVal                   Allocated with name '_interpolateU_lRelVal_1_1'
                            941 ;------------------------------------------------------------
                    00C6    942 	G$interpolateU$0$0 ==.
                    00C6    943 	C$Interpolate.c$37$1$1 ==.
                            944 ;	apps/twitch_mx_servos/Interpolate.c:37: uint16 interpolateU(int16 value, int16 minVal, int16 maxVal, uint16 minRtn, uint16 maxRtn){
                            945 ;	-----------------------------------------
                            946 ;	 function interpolateU
                            947 ;	-----------------------------------------
   0ADC                     948 _interpolateU:
   0ADC AE 82               949 	mov	r6,dpl
   0ADE AF 83               950 	mov	r7,dph
                    00CA    951 	C$Interpolate.c$42$1$1 ==.
                            952 ;	apps/twitch_mx_servos/Interpolate.c:42: lRtnRange = maxRtn - minRtn;
   0AE0 78 31               953 	mov	r0,#_interpolateU_PARM_5
   0AE2 79 2F               954 	mov	r1,#_interpolateU_PARM_4
   0AE4 E3                  955 	movx	a,@r1
   0AE5 F5 F0               956 	mov	b,a
   0AE7 C3                  957 	clr	c
   0AE8 E2                  958 	movx	a,@r0
   0AE9 95 F0               959 	subb	a,b
   0AEB FC                  960 	mov	r4,a
   0AEC 09                  961 	inc	r1
   0AED E3                  962 	movx	a,@r1
   0AEE F5 F0               963 	mov	b,a
   0AF0 08                  964 	inc	r0
   0AF1 E2                  965 	movx	a,@r0
   0AF2 95 F0               966 	subb	a,b
   0AF4 FD                  967 	mov	r5,a
   0AF5 8C 30               968 	mov	_interpolateU_lRtnRange_1_1,r4
   0AF7 8D 31               969 	mov	(_interpolateU_lRtnRange_1_1 + 1),r5
   0AF9 75 32 00            970 	mov	(_interpolateU_lRtnRange_1_1 + 2),#0x00
   0AFC 75 33 00            971 	mov	(_interpolateU_lRtnRange_1_1 + 3),#0x00
                    00E9    972 	C$Interpolate.c$43$1$1 ==.
                            973 ;	apps/twitch_mx_servos/Interpolate.c:43: lValRange = maxVal - minVal;
   0AFF 78 2D               974 	mov	r0,#_interpolateU_PARM_3
   0B01 79 2B               975 	mov	r1,#_interpolateU_PARM_2
   0B03 E3                  976 	movx	a,@r1
   0B04 F5 F0               977 	mov	b,a
   0B06 C3                  978 	clr	c
   0B07 E2                  979 	movx	a,@r0
   0B08 95 F0               980 	subb	a,b
   0B0A FC                  981 	mov	r4,a
   0B0B 09                  982 	inc	r1
   0B0C E3                  983 	movx	a,@r1
   0B0D F5 F0               984 	mov	b,a
   0B0F 08                  985 	inc	r0
   0B10 E2                  986 	movx	a,@r0
   0B11 95 F0               987 	subb	a,b
   0B13 8C 34               988 	mov	_interpolateU_lValRange_1_1,r4
   0B15 F5 35               989 	mov	(_interpolateU_lValRange_1_1 + 1),a
   0B17 33                  990 	rlc	a
   0B18 95 E0               991 	subb	a,acc
   0B1A F5 36               992 	mov	(_interpolateU_lValRange_1_1 + 2),a
   0B1C F5 37               993 	mov	(_interpolateU_lValRange_1_1 + 3),a
                    0108    994 	C$Interpolate.c$44$1$1 ==.
                            995 ;	apps/twitch_mx_servos/Interpolate.c:44: lRelVal = value - minVal;
   0B1E 78 2B               996 	mov	r0,#_interpolateU_PARM_2
   0B20 D3                  997 	setb	c
   0B21 E2                  998 	movx	a,@r0
   0B22 9E                  999 	subb	a,r6
   0B23 F4                 1000 	cpl	a
   0B24 B3                 1001 	cpl	c
   0B25 FE                 1002 	mov	r6,a
   0B26 B3                 1003 	cpl	c
   0B27 08                 1004 	inc	r0
   0B28 E2                 1005 	movx	a,@r0
   0B29 9F                 1006 	subb	a,r7
   0B2A F4                 1007 	cpl	a
   0B2B 8E 38              1008 	mov	_interpolateU_lRelVal_1_1,r6
   0B2D F5 39              1009 	mov	(_interpolateU_lRelVal_1_1 + 1),a
   0B2F 33                 1010 	rlc	a
   0B30 95 E0              1011 	subb	a,acc
   0B32 F5 3A              1012 	mov	(_interpolateU_lRelVal_1_1 + 2),a
   0B34 F5 3B              1013 	mov	(_interpolateU_lRelVal_1_1 + 3),a
                    0120   1014 	C$Interpolate.c$47$1$1 ==.
                           1015 ;	apps/twitch_mx_servos/Interpolate.c:47: lRelVal *= lRtnRange;
   0B36 AA 38              1016 	mov	r2,_interpolateU_lRelVal_1_1
   0B38 AB 39              1017 	mov	r3,(_interpolateU_lRelVal_1_1 + 1)
   0B3A AE 3A              1018 	mov	r6,(_interpolateU_lRelVal_1_1 + 2)
   0B3C AF 3B              1019 	mov	r7,(_interpolateU_lRelVal_1_1 + 3)
   0B3E 78 ED              1020 	mov	r0,#__mullong_PARM_2
   0B40 E5 30              1021 	mov	a,_interpolateU_lRtnRange_1_1
   0B42 F2                 1022 	movx	@r0,a
   0B43 08                 1023 	inc	r0
   0B44 E5 31              1024 	mov	a,(_interpolateU_lRtnRange_1_1 + 1)
   0B46 F2                 1025 	movx	@r0,a
   0B47 08                 1026 	inc	r0
   0B48 E5 32              1027 	mov	a,(_interpolateU_lRtnRange_1_1 + 2)
   0B4A F2                 1028 	movx	@r0,a
   0B4B 08                 1029 	inc	r0
   0B4C E5 33              1030 	mov	a,(_interpolateU_lRtnRange_1_1 + 3)
   0B4E F2                 1031 	movx	@r0,a
   0B4F 8A 82              1032 	mov	dpl,r2
   0B51 8B 83              1033 	mov	dph,r3
   0B53 8E F0              1034 	mov	b,r6
   0B55 EF                 1035 	mov	a,r7
   0B56 12 39 5F           1036 	lcall	__mullong
   0B59 AC 82              1037 	mov	r4,dpl
   0B5B AD 83              1038 	mov	r5,dph
   0B5D AE F0              1039 	mov	r6,b
   0B5F FF                 1040 	mov	r7,a
   0B60 8C 38              1041 	mov	_interpolateU_lRelVal_1_1,r4
   0B62 8D 39              1042 	mov	(_interpolateU_lRelVal_1_1 + 1),r5
   0B64 8E 3A              1043 	mov	(_interpolateU_lRelVal_1_1 + 2),r6
   0B66 8F 3B              1044 	mov	(_interpolateU_lRelVal_1_1 + 3),r7
                    0152   1045 	C$Interpolate.c$48$1$1 ==.
                           1046 ;	apps/twitch_mx_servos/Interpolate.c:48: lRelVal /= lValRange;
   0B68 78 CD              1047 	mov	r0,#__divslong_PARM_2
   0B6A E5 34              1048 	mov	a,_interpolateU_lValRange_1_1
   0B6C F2                 1049 	movx	@r0,a
   0B6D 08                 1050 	inc	r0
   0B6E E5 35              1051 	mov	a,(_interpolateU_lValRange_1_1 + 1)
   0B70 F2                 1052 	movx	@r0,a
   0B71 08                 1053 	inc	r0
   0B72 E5 36              1054 	mov	a,(_interpolateU_lValRange_1_1 + 2)
   0B74 F2                 1055 	movx	@r0,a
   0B75 08                 1056 	inc	r0
   0B76 E5 37              1057 	mov	a,(_interpolateU_lValRange_1_1 + 3)
   0B78 F2                 1058 	movx	@r0,a
   0B79 85 38 82           1059 	mov	dpl,_interpolateU_lRelVal_1_1
   0B7C 85 39 83           1060 	mov	dph,(_interpolateU_lRelVal_1_1 + 1)
   0B7F 85 3A F0           1061 	mov	b,(_interpolateU_lRelVal_1_1 + 2)
   0B82 E5 3B              1062 	mov	a,(_interpolateU_lRelVal_1_1 + 3)
   0B84 12 32 F3           1063 	lcall	__divslong
   0B87 85 82 38           1064 	mov	_interpolateU_lRelVal_1_1,dpl
   0B8A 85 83 39           1065 	mov	(_interpolateU_lRelVal_1_1 + 1),dph
   0B8D 85 F0 3A           1066 	mov	(_interpolateU_lRelVal_1_1 + 2),b
   0B90 F5 3B              1067 	mov	(_interpolateU_lRelVal_1_1 + 3),a
                    017C   1068 	C$Interpolate.c$50$1$1 ==.
                           1069 ;	apps/twitch_mx_servos/Interpolate.c:50: lRtnRange =  minRtn + lRelVal;
   0B92 78 2F              1070 	mov	r0,#_interpolateU_PARM_4
   0B94 E2                 1071 	movx	a,@r0
   0B95 FC                 1072 	mov	r4,a
   0B96 08                 1073 	inc	r0
   0B97 E2                 1074 	movx	a,@r0
   0B98 FD                 1075 	mov	r5,a
   0B99 E4                 1076 	clr	a
   0B9A FE                 1077 	mov	r6,a
   0B9B FF                 1078 	mov	r7,a
   0B9C E5 38              1079 	mov	a,_interpolateU_lRelVal_1_1
   0B9E 2C                 1080 	add	a,r4
   0B9F FC                 1081 	mov	r4,a
   0BA0 E5 39              1082 	mov	a,(_interpolateU_lRelVal_1_1 + 1)
   0BA2 3D                 1083 	addc	a,r5
   0BA3 FD                 1084 	mov	r5,a
   0BA4 E5 3A              1085 	mov	a,(_interpolateU_lRelVal_1_1 + 2)
   0BA6 3E                 1086 	addc	a,r6
   0BA7 FE                 1087 	mov	r6,a
   0BA8 E5 3B              1088 	mov	a,(_interpolateU_lRelVal_1_1 + 3)
   0BAA 3F                 1089 	addc	a,r7
   0BAB FF                 1090 	mov	r7,a
   0BAC 8C 30              1091 	mov	_interpolateU_lRtnRange_1_1,r4
   0BAE 8D 31              1092 	mov	(_interpolateU_lRtnRange_1_1 + 1),r5
   0BB0 8E 32              1093 	mov	(_interpolateU_lRtnRange_1_1 + 2),r6
   0BB2 8F 33              1094 	mov	(_interpolateU_lRtnRange_1_1 + 3),r7
                    019E   1095 	C$Interpolate.c$52$1$1 ==.
                           1096 ;	apps/twitch_mx_servos/Interpolate.c:52: return (uint16)lRtnRange;
   0BB4 85 30 82           1097 	mov	dpl,_interpolateU_lRtnRange_1_1
   0BB7 85 31 83           1098 	mov	dph,(_interpolateU_lRtnRange_1_1 + 1)
                    01A4   1099 	C$Interpolate.c$53$1$1 ==.
                    01A4   1100 	XG$interpolateU$0$0 ==.
   0BBA 22                 1101 	ret
                           1102 	.area CSEG    (CODE)
                           1103 	.area CONST   (CODE)
                           1104 	.area XINIT   (CODE)
                           1105 	.area CABS    (ABS,CODE)
