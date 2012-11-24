                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:16 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_servos
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _pins
                             13 	.globl _main
                             14 	.globl _receiveCommands
                             15 	.globl _updateServos
                             16 	.globl _myServosInit
                             17 	.globl _usbComRxReceiveByte
                             18 	.globl _usbComRxAvailable
                             19 	.globl _usbComService
                             20 	.globl _usbShowStatusWithGreenLed
                             21 	.globl _usbInit
                             22 	.globl _getMs
                             23 	.globl _boardService
                             24 	.globl _systemInit
                             25 	.globl _servoSetSpeed
                             26 	.globl _servoSetTarget
                             27 	.globl _servosMoving
                             28 	.globl _servosStarted
                             29 	.globl _servosStop
                             30 	.globl _servosStart
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 	.area RSEG    (ABS,DATA)
   0000                      35 	.org 0x0000
                    0080     36 Ftest_servos$P0$0$0 == 0x0080
                    0080     37 _P0	=	0x0080
                    0081     38 Ftest_servos$SP$0$0 == 0x0081
                    0081     39 _SP	=	0x0081
                    0082     40 Ftest_servos$DPL0$0$0 == 0x0082
                    0082     41 _DPL0	=	0x0082
                    0083     42 Ftest_servos$DPH0$0$0 == 0x0083
                    0083     43 _DPH0	=	0x0083
                    0084     44 Ftest_servos$DPL1$0$0 == 0x0084
                    0084     45 _DPL1	=	0x0084
                    0085     46 Ftest_servos$DPH1$0$0 == 0x0085
                    0085     47 _DPH1	=	0x0085
                    0086     48 Ftest_servos$U0CSR$0$0 == 0x0086
                    0086     49 _U0CSR	=	0x0086
                    0087     50 Ftest_servos$PCON$0$0 == 0x0087
                    0087     51 _PCON	=	0x0087
                    0088     52 Ftest_servos$TCON$0$0 == 0x0088
                    0088     53 _TCON	=	0x0088
                    0089     54 Ftest_servos$P0IFG$0$0 == 0x0089
                    0089     55 _P0IFG	=	0x0089
                    008A     56 Ftest_servos$P1IFG$0$0 == 0x008a
                    008A     57 _P1IFG	=	0x008a
                    008B     58 Ftest_servos$P2IFG$0$0 == 0x008b
                    008B     59 _P2IFG	=	0x008b
                    008C     60 Ftest_servos$PICTL$0$0 == 0x008c
                    008C     61 _PICTL	=	0x008c
                    008D     62 Ftest_servos$P1IEN$0$0 == 0x008d
                    008D     63 _P1IEN	=	0x008d
                    008F     64 Ftest_servos$P0INP$0$0 == 0x008f
                    008F     65 _P0INP	=	0x008f
                    0090     66 Ftest_servos$P1$0$0 == 0x0090
                    0090     67 _P1	=	0x0090
                    0091     68 Ftest_servos$RFIM$0$0 == 0x0091
                    0091     69 _RFIM	=	0x0091
                    0092     70 Ftest_servos$DPS$0$0 == 0x0092
                    0092     71 _DPS	=	0x0092
                    0093     72 Ftest_servos$MPAGE$0$0 == 0x0093
                    0093     73 _MPAGE	=	0x0093
                    0095     74 Ftest_servos$ENDIAN$0$0 == 0x0095
                    0095     75 _ENDIAN	=	0x0095
                    0098     76 Ftest_servos$S0CON$0$0 == 0x0098
                    0098     77 _S0CON	=	0x0098
                    009A     78 Ftest_servos$IEN2$0$0 == 0x009a
                    009A     79 _IEN2	=	0x009a
                    009B     80 Ftest_servos$S1CON$0$0 == 0x009b
                    009B     81 _S1CON	=	0x009b
                    009C     82 Ftest_servos$T2CT$0$0 == 0x009c
                    009C     83 _T2CT	=	0x009c
                    009D     84 Ftest_servos$T2PR$0$0 == 0x009d
                    009D     85 _T2PR	=	0x009d
                    009E     86 Ftest_servos$T2CTL$0$0 == 0x009e
                    009E     87 _T2CTL	=	0x009e
                    00A0     88 Ftest_servos$P2$0$0 == 0x00a0
                    00A0     89 _P2	=	0x00a0
                    00A1     90 Ftest_servos$WORIRQ$0$0 == 0x00a1
                    00A1     91 _WORIRQ	=	0x00a1
                    00A2     92 Ftest_servos$WORCTRL$0$0 == 0x00a2
                    00A2     93 _WORCTRL	=	0x00a2
                    00A3     94 Ftest_servos$WOREVT0$0$0 == 0x00a3
                    00A3     95 _WOREVT0	=	0x00a3
                    00A4     96 Ftest_servos$WOREVT1$0$0 == 0x00a4
                    00A4     97 _WOREVT1	=	0x00a4
                    00A5     98 Ftest_servos$WORTIME0$0$0 == 0x00a5
                    00A5     99 _WORTIME0	=	0x00a5
                    00A6    100 Ftest_servos$WORTIME1$0$0 == 0x00a6
                    00A6    101 _WORTIME1	=	0x00a6
                    00A8    102 Ftest_servos$IEN0$0$0 == 0x00a8
                    00A8    103 _IEN0	=	0x00a8
                    00A9    104 Ftest_servos$IP0$0$0 == 0x00a9
                    00A9    105 _IP0	=	0x00a9
                    00AB    106 Ftest_servos$FWT$0$0 == 0x00ab
                    00AB    107 _FWT	=	0x00ab
                    00AC    108 Ftest_servos$FADDRL$0$0 == 0x00ac
                    00AC    109 _FADDRL	=	0x00ac
                    00AD    110 Ftest_servos$FADDRH$0$0 == 0x00ad
                    00AD    111 _FADDRH	=	0x00ad
                    00AE    112 Ftest_servos$FCTL$0$0 == 0x00ae
                    00AE    113 _FCTL	=	0x00ae
                    00AF    114 Ftest_servos$FWDATA$0$0 == 0x00af
                    00AF    115 _FWDATA	=	0x00af
                    00B1    116 Ftest_servos$ENCDI$0$0 == 0x00b1
                    00B1    117 _ENCDI	=	0x00b1
                    00B2    118 Ftest_servos$ENCDO$0$0 == 0x00b2
                    00B2    119 _ENCDO	=	0x00b2
                    00B3    120 Ftest_servos$ENCCS$0$0 == 0x00b3
                    00B3    121 _ENCCS	=	0x00b3
                    00B4    122 Ftest_servos$ADCCON1$0$0 == 0x00b4
                    00B4    123 _ADCCON1	=	0x00b4
                    00B5    124 Ftest_servos$ADCCON2$0$0 == 0x00b5
                    00B5    125 _ADCCON2	=	0x00b5
                    00B6    126 Ftest_servos$ADCCON3$0$0 == 0x00b6
                    00B6    127 _ADCCON3	=	0x00b6
                    00B8    128 Ftest_servos$IEN1$0$0 == 0x00b8
                    00B8    129 _IEN1	=	0x00b8
                    00B9    130 Ftest_servos$IP1$0$0 == 0x00b9
                    00B9    131 _IP1	=	0x00b9
                    00BA    132 Ftest_servos$ADCL$0$0 == 0x00ba
                    00BA    133 _ADCL	=	0x00ba
                    00BB    134 Ftest_servos$ADCH$0$0 == 0x00bb
                    00BB    135 _ADCH	=	0x00bb
                    00BC    136 Ftest_servos$RNDL$0$0 == 0x00bc
                    00BC    137 _RNDL	=	0x00bc
                    00BD    138 Ftest_servos$RNDH$0$0 == 0x00bd
                    00BD    139 _RNDH	=	0x00bd
                    00BE    140 Ftest_servos$SLEEP$0$0 == 0x00be
                    00BE    141 _SLEEP	=	0x00be
                    00C0    142 Ftest_servos$IRCON$0$0 == 0x00c0
                    00C0    143 _IRCON	=	0x00c0
                    00C1    144 Ftest_servos$U0DBUF$0$0 == 0x00c1
                    00C1    145 _U0DBUF	=	0x00c1
                    00C2    146 Ftest_servos$U0BAUD$0$0 == 0x00c2
                    00C2    147 _U0BAUD	=	0x00c2
                    00C4    148 Ftest_servos$U0UCR$0$0 == 0x00c4
                    00C4    149 _U0UCR	=	0x00c4
                    00C5    150 Ftest_servos$U0GCR$0$0 == 0x00c5
                    00C5    151 _U0GCR	=	0x00c5
                    00C6    152 Ftest_servos$CLKCON$0$0 == 0x00c6
                    00C6    153 _CLKCON	=	0x00c6
                    00C7    154 Ftest_servos$MEMCTR$0$0 == 0x00c7
                    00C7    155 _MEMCTR	=	0x00c7
                    00C9    156 Ftest_servos$WDCTL$0$0 == 0x00c9
                    00C9    157 _WDCTL	=	0x00c9
                    00CA    158 Ftest_servos$T3CNT$0$0 == 0x00ca
                    00CA    159 _T3CNT	=	0x00ca
                    00CB    160 Ftest_servos$T3CTL$0$0 == 0x00cb
                    00CB    161 _T3CTL	=	0x00cb
                    00CC    162 Ftest_servos$T3CCTL0$0$0 == 0x00cc
                    00CC    163 _T3CCTL0	=	0x00cc
                    00CD    164 Ftest_servos$T3CC0$0$0 == 0x00cd
                    00CD    165 _T3CC0	=	0x00cd
                    00CE    166 Ftest_servos$T3CCTL1$0$0 == 0x00ce
                    00CE    167 _T3CCTL1	=	0x00ce
                    00CF    168 Ftest_servos$T3CC1$0$0 == 0x00cf
                    00CF    169 _T3CC1	=	0x00cf
                    00D0    170 Ftest_servos$PSW$0$0 == 0x00d0
                    00D0    171 _PSW	=	0x00d0
                    00D1    172 Ftest_servos$DMAIRQ$0$0 == 0x00d1
                    00D1    173 _DMAIRQ	=	0x00d1
                    00D2    174 Ftest_servos$DMA1CFGL$0$0 == 0x00d2
                    00D2    175 _DMA1CFGL	=	0x00d2
                    00D3    176 Ftest_servos$DMA1CFGH$0$0 == 0x00d3
                    00D3    177 _DMA1CFGH	=	0x00d3
                    00D4    178 Ftest_servos$DMA0CFGL$0$0 == 0x00d4
                    00D4    179 _DMA0CFGL	=	0x00d4
                    00D5    180 Ftest_servos$DMA0CFGH$0$0 == 0x00d5
                    00D5    181 _DMA0CFGH	=	0x00d5
                    00D6    182 Ftest_servos$DMAARM$0$0 == 0x00d6
                    00D6    183 _DMAARM	=	0x00d6
                    00D7    184 Ftest_servos$DMAREQ$0$0 == 0x00d7
                    00D7    185 _DMAREQ	=	0x00d7
                    00D8    186 Ftest_servos$TIMIF$0$0 == 0x00d8
                    00D8    187 _TIMIF	=	0x00d8
                    00D9    188 Ftest_servos$RFD$0$0 == 0x00d9
                    00D9    189 _RFD	=	0x00d9
                    00DA    190 Ftest_servos$T1CC0L$0$0 == 0x00da
                    00DA    191 _T1CC0L	=	0x00da
                    00DB    192 Ftest_servos$T1CC0H$0$0 == 0x00db
                    00DB    193 _T1CC0H	=	0x00db
                    00DC    194 Ftest_servos$T1CC1L$0$0 == 0x00dc
                    00DC    195 _T1CC1L	=	0x00dc
                    00DD    196 Ftest_servos$T1CC1H$0$0 == 0x00dd
                    00DD    197 _T1CC1H	=	0x00dd
                    00DE    198 Ftest_servos$T1CC2L$0$0 == 0x00de
                    00DE    199 _T1CC2L	=	0x00de
                    00DF    200 Ftest_servos$T1CC2H$0$0 == 0x00df
                    00DF    201 _T1CC2H	=	0x00df
                    00E0    202 Ftest_servos$ACC$0$0 == 0x00e0
                    00E0    203 _ACC	=	0x00e0
                    00E1    204 Ftest_servos$RFST$0$0 == 0x00e1
                    00E1    205 _RFST	=	0x00e1
                    00E2    206 Ftest_servos$T1CNTL$0$0 == 0x00e2
                    00E2    207 _T1CNTL	=	0x00e2
                    00E3    208 Ftest_servos$T1CNTH$0$0 == 0x00e3
                    00E3    209 _T1CNTH	=	0x00e3
                    00E4    210 Ftest_servos$T1CTL$0$0 == 0x00e4
                    00E4    211 _T1CTL	=	0x00e4
                    00E5    212 Ftest_servos$T1CCTL0$0$0 == 0x00e5
                    00E5    213 _T1CCTL0	=	0x00e5
                    00E6    214 Ftest_servos$T1CCTL1$0$0 == 0x00e6
                    00E6    215 _T1CCTL1	=	0x00e6
                    00E7    216 Ftest_servos$T1CCTL2$0$0 == 0x00e7
                    00E7    217 _T1CCTL2	=	0x00e7
                    00E8    218 Ftest_servos$IRCON2$0$0 == 0x00e8
                    00E8    219 _IRCON2	=	0x00e8
                    00E9    220 Ftest_servos$RFIF$0$0 == 0x00e9
                    00E9    221 _RFIF	=	0x00e9
                    00EA    222 Ftest_servos$T4CNT$0$0 == 0x00ea
                    00EA    223 _T4CNT	=	0x00ea
                    00EB    224 Ftest_servos$T4CTL$0$0 == 0x00eb
                    00EB    225 _T4CTL	=	0x00eb
                    00EC    226 Ftest_servos$T4CCTL0$0$0 == 0x00ec
                    00EC    227 _T4CCTL0	=	0x00ec
                    00ED    228 Ftest_servos$T4CC0$0$0 == 0x00ed
                    00ED    229 _T4CC0	=	0x00ed
                    00EE    230 Ftest_servos$T4CCTL1$0$0 == 0x00ee
                    00EE    231 _T4CCTL1	=	0x00ee
                    00EF    232 Ftest_servos$T4CC1$0$0 == 0x00ef
                    00EF    233 _T4CC1	=	0x00ef
                    00F0    234 Ftest_servos$B$0$0 == 0x00f0
                    00F0    235 _B	=	0x00f0
                    00F1    236 Ftest_servos$PERCFG$0$0 == 0x00f1
                    00F1    237 _PERCFG	=	0x00f1
                    00F2    238 Ftest_servos$ADCCFG$0$0 == 0x00f2
                    00F2    239 _ADCCFG	=	0x00f2
                    00F3    240 Ftest_servos$P0SEL$0$0 == 0x00f3
                    00F3    241 _P0SEL	=	0x00f3
                    00F4    242 Ftest_servos$P1SEL$0$0 == 0x00f4
                    00F4    243 _P1SEL	=	0x00f4
                    00F5    244 Ftest_servos$P2SEL$0$0 == 0x00f5
                    00F5    245 _P2SEL	=	0x00f5
                    00F6    246 Ftest_servos$P1INP$0$0 == 0x00f6
                    00F6    247 _P1INP	=	0x00f6
                    00F7    248 Ftest_servos$P2INP$0$0 == 0x00f7
                    00F7    249 _P2INP	=	0x00f7
                    00F8    250 Ftest_servos$U1CSR$0$0 == 0x00f8
                    00F8    251 _U1CSR	=	0x00f8
                    00F9    252 Ftest_servos$U1DBUF$0$0 == 0x00f9
                    00F9    253 _U1DBUF	=	0x00f9
                    00FA    254 Ftest_servos$U1BAUD$0$0 == 0x00fa
                    00FA    255 _U1BAUD	=	0x00fa
                    00FB    256 Ftest_servos$U1UCR$0$0 == 0x00fb
                    00FB    257 _U1UCR	=	0x00fb
                    00FC    258 Ftest_servos$U1GCR$0$0 == 0x00fc
                    00FC    259 _U1GCR	=	0x00fc
                    00FD    260 Ftest_servos$P0DIR$0$0 == 0x00fd
                    00FD    261 _P0DIR	=	0x00fd
                    00FE    262 Ftest_servos$P1DIR$0$0 == 0x00fe
                    00FE    263 _P1DIR	=	0x00fe
                    00FF    264 Ftest_servos$P2DIR$0$0 == 0x00ff
                    00FF    265 _P2DIR	=	0x00ff
                    FFFFD5D4    266 Ftest_servos$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    267 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    268 Ftest_servos$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    269 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    270 Ftest_servos$FADDR$0$0 == 0xffffadac
                    FFFFADAC    271 _FADDR	=	0xffffadac
                    FFFFBBBA    272 Ftest_servos$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    273 _ADC	=	0xffffbbba
                    FFFFDBDA    274 Ftest_servos$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    275 _T1CC0	=	0xffffdbda
                    FFFFDDDC    276 Ftest_servos$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    277 _T1CC1	=	0xffffdddc
                    FFFFDFDE    278 Ftest_servos$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    279 _T1CC2	=	0xffffdfde
                            280 ;--------------------------------------------------------
                            281 ; special function bits
                            282 ;--------------------------------------------------------
                            283 	.area RSEG    (ABS,DATA)
   0000                     284 	.org 0x0000
                    0080    285 Ftest_servos$P0_0$0$0 == 0x0080
                    0080    286 _P0_0	=	0x0080
                    0081    287 Ftest_servos$P0_1$0$0 == 0x0081
                    0081    288 _P0_1	=	0x0081
                    0082    289 Ftest_servos$P0_2$0$0 == 0x0082
                    0082    290 _P0_2	=	0x0082
                    0083    291 Ftest_servos$P0_3$0$0 == 0x0083
                    0083    292 _P0_3	=	0x0083
                    0084    293 Ftest_servos$P0_4$0$0 == 0x0084
                    0084    294 _P0_4	=	0x0084
                    0085    295 Ftest_servos$P0_5$0$0 == 0x0085
                    0085    296 _P0_5	=	0x0085
                    0086    297 Ftest_servos$P0_6$0$0 == 0x0086
                    0086    298 _P0_6	=	0x0086
                    0087    299 Ftest_servos$P0_7$0$0 == 0x0087
                    0087    300 _P0_7	=	0x0087
                    0088    301 Ftest_servos$_TCON_0$0$0 == 0x0088
                    0088    302 __TCON_0	=	0x0088
                    0089    303 Ftest_servos$RFTXRXIF$0$0 == 0x0089
                    0089    304 _RFTXRXIF	=	0x0089
                    008A    305 Ftest_servos$_TCON_2$0$0 == 0x008a
                    008A    306 __TCON_2	=	0x008a
                    008B    307 Ftest_servos$URX0IF$0$0 == 0x008b
                    008B    308 _URX0IF	=	0x008b
                    008C    309 Ftest_servos$_TCON_4$0$0 == 0x008c
                    008C    310 __TCON_4	=	0x008c
                    008D    311 Ftest_servos$ADCIF$0$0 == 0x008d
                    008D    312 _ADCIF	=	0x008d
                    008E    313 Ftest_servos$_TCON_6$0$0 == 0x008e
                    008E    314 __TCON_6	=	0x008e
                    008F    315 Ftest_servos$URX1IF$0$0 == 0x008f
                    008F    316 _URX1IF	=	0x008f
                    0090    317 Ftest_servos$P1_0$0$0 == 0x0090
                    0090    318 _P1_0	=	0x0090
                    0091    319 Ftest_servos$P1_1$0$0 == 0x0091
                    0091    320 _P1_1	=	0x0091
                    0092    321 Ftest_servos$P1_2$0$0 == 0x0092
                    0092    322 _P1_2	=	0x0092
                    0093    323 Ftest_servos$P1_3$0$0 == 0x0093
                    0093    324 _P1_3	=	0x0093
                    0094    325 Ftest_servos$P1_4$0$0 == 0x0094
                    0094    326 _P1_4	=	0x0094
                    0095    327 Ftest_servos$P1_5$0$0 == 0x0095
                    0095    328 _P1_5	=	0x0095
                    0096    329 Ftest_servos$P1_6$0$0 == 0x0096
                    0096    330 _P1_6	=	0x0096
                    0097    331 Ftest_servos$P1_7$0$0 == 0x0097
                    0097    332 _P1_7	=	0x0097
                    0098    333 Ftest_servos$ENCIF_0$0$0 == 0x0098
                    0098    334 _ENCIF_0	=	0x0098
                    0099    335 Ftest_servos$ENCIF_1$0$0 == 0x0099
                    0099    336 _ENCIF_1	=	0x0099
                    009A    337 Ftest_servos$_SOCON2$0$0 == 0x009a
                    009A    338 __SOCON2	=	0x009a
                    009B    339 Ftest_servos$_SOCON3$0$0 == 0x009b
                    009B    340 __SOCON3	=	0x009b
                    009C    341 Ftest_servos$_SOCON4$0$0 == 0x009c
                    009C    342 __SOCON4	=	0x009c
                    009D    343 Ftest_servos$_SOCON5$0$0 == 0x009d
                    009D    344 __SOCON5	=	0x009d
                    009E    345 Ftest_servos$_SOCON6$0$0 == 0x009e
                    009E    346 __SOCON6	=	0x009e
                    009F    347 Ftest_servos$_SOCON7$0$0 == 0x009f
                    009F    348 __SOCON7	=	0x009f
                    00A0    349 Ftest_servos$P2_0$0$0 == 0x00a0
                    00A0    350 _P2_0	=	0x00a0
                    00A1    351 Ftest_servos$P2_1$0$0 == 0x00a1
                    00A1    352 _P2_1	=	0x00a1
                    00A2    353 Ftest_servos$P2_2$0$0 == 0x00a2
                    00A2    354 _P2_2	=	0x00a2
                    00A3    355 Ftest_servos$P2_3$0$0 == 0x00a3
                    00A3    356 _P2_3	=	0x00a3
                    00A4    357 Ftest_servos$P2_4$0$0 == 0x00a4
                    00A4    358 _P2_4	=	0x00a4
                    00A5    359 Ftest_servos$P2_5$0$0 == 0x00a5
                    00A5    360 _P2_5	=	0x00a5
                    00A6    361 Ftest_servos$P2_6$0$0 == 0x00a6
                    00A6    362 _P2_6	=	0x00a6
                    00A7    363 Ftest_servos$P2_7$0$0 == 0x00a7
                    00A7    364 _P2_7	=	0x00a7
                    00A8    365 Ftest_servos$RFTXRXIE$0$0 == 0x00a8
                    00A8    366 _RFTXRXIE	=	0x00a8
                    00A9    367 Ftest_servos$ADCIE$0$0 == 0x00a9
                    00A9    368 _ADCIE	=	0x00a9
                    00AA    369 Ftest_servos$URX0IE$0$0 == 0x00aa
                    00AA    370 _URX0IE	=	0x00aa
                    00AB    371 Ftest_servos$URX1IE$0$0 == 0x00ab
                    00AB    372 _URX1IE	=	0x00ab
                    00AC    373 Ftest_servos$ENCIE$0$0 == 0x00ac
                    00AC    374 _ENCIE	=	0x00ac
                    00AD    375 Ftest_servos$STIE$0$0 == 0x00ad
                    00AD    376 _STIE	=	0x00ad
                    00AE    377 Ftest_servos$_IEN06$0$0 == 0x00ae
                    00AE    378 __IEN06	=	0x00ae
                    00AF    379 Ftest_servos$EA$0$0 == 0x00af
                    00AF    380 _EA	=	0x00af
                    00B8    381 Ftest_servos$DMAIE$0$0 == 0x00b8
                    00B8    382 _DMAIE	=	0x00b8
                    00B9    383 Ftest_servos$T1IE$0$0 == 0x00b9
                    00B9    384 _T1IE	=	0x00b9
                    00BA    385 Ftest_servos$T2IE$0$0 == 0x00ba
                    00BA    386 _T2IE	=	0x00ba
                    00BB    387 Ftest_servos$T3IE$0$0 == 0x00bb
                    00BB    388 _T3IE	=	0x00bb
                    00BC    389 Ftest_servos$T4IE$0$0 == 0x00bc
                    00BC    390 _T4IE	=	0x00bc
                    00BD    391 Ftest_servos$P0IE$0$0 == 0x00bd
                    00BD    392 _P0IE	=	0x00bd
                    00BE    393 Ftest_servos$_IEN16$0$0 == 0x00be
                    00BE    394 __IEN16	=	0x00be
                    00BF    395 Ftest_servos$_IEN17$0$0 == 0x00bf
                    00BF    396 __IEN17	=	0x00bf
                    00C0    397 Ftest_servos$DMAIF$0$0 == 0x00c0
                    00C0    398 _DMAIF	=	0x00c0
                    00C1    399 Ftest_servos$T1IF$0$0 == 0x00c1
                    00C1    400 _T1IF	=	0x00c1
                    00C2    401 Ftest_servos$T2IF$0$0 == 0x00c2
                    00C2    402 _T2IF	=	0x00c2
                    00C3    403 Ftest_servos$T3IF$0$0 == 0x00c3
                    00C3    404 _T3IF	=	0x00c3
                    00C4    405 Ftest_servos$T4IF$0$0 == 0x00c4
                    00C4    406 _T4IF	=	0x00c4
                    00C5    407 Ftest_servos$P0IF$0$0 == 0x00c5
                    00C5    408 _P0IF	=	0x00c5
                    00C6    409 Ftest_servos$_IRCON6$0$0 == 0x00c6
                    00C6    410 __IRCON6	=	0x00c6
                    00C7    411 Ftest_servos$STIF$0$0 == 0x00c7
                    00C7    412 _STIF	=	0x00c7
                    00D0    413 Ftest_servos$P$0$0 == 0x00d0
                    00D0    414 _P	=	0x00d0
                    00D1    415 Ftest_servos$F1$0$0 == 0x00d1
                    00D1    416 _F1	=	0x00d1
                    00D2    417 Ftest_servos$OV$0$0 == 0x00d2
                    00D2    418 _OV	=	0x00d2
                    00D3    419 Ftest_servos$RS0$0$0 == 0x00d3
                    00D3    420 _RS0	=	0x00d3
                    00D4    421 Ftest_servos$RS1$0$0 == 0x00d4
                    00D4    422 _RS1	=	0x00d4
                    00D5    423 Ftest_servos$F0$0$0 == 0x00d5
                    00D5    424 _F0	=	0x00d5
                    00D6    425 Ftest_servos$AC$0$0 == 0x00d6
                    00D6    426 _AC	=	0x00d6
                    00D7    427 Ftest_servos$CY$0$0 == 0x00d7
                    00D7    428 _CY	=	0x00d7
                    00D8    429 Ftest_servos$T3OVFIF$0$0 == 0x00d8
                    00D8    430 _T3OVFIF	=	0x00d8
                    00D9    431 Ftest_servos$T3CH0IF$0$0 == 0x00d9
                    00D9    432 _T3CH0IF	=	0x00d9
                    00DA    433 Ftest_servos$T3CH1IF$0$0 == 0x00da
                    00DA    434 _T3CH1IF	=	0x00da
                    00DB    435 Ftest_servos$T4OVFIF$0$0 == 0x00db
                    00DB    436 _T4OVFIF	=	0x00db
                    00DC    437 Ftest_servos$T4CH0IF$0$0 == 0x00dc
                    00DC    438 _T4CH0IF	=	0x00dc
                    00DD    439 Ftest_servos$T4CH1IF$0$0 == 0x00dd
                    00DD    440 _T4CH1IF	=	0x00dd
                    00DE    441 Ftest_servos$OVFIM$0$0 == 0x00de
                    00DE    442 _OVFIM	=	0x00de
                    00DF    443 Ftest_servos$_TIMIF7$0$0 == 0x00df
                    00DF    444 __TIMIF7	=	0x00df
                    00E0    445 Ftest_servos$ACC_0$0$0 == 0x00e0
                    00E0    446 _ACC_0	=	0x00e0
                    00E1    447 Ftest_servos$ACC_1$0$0 == 0x00e1
                    00E1    448 _ACC_1	=	0x00e1
                    00E2    449 Ftest_servos$ACC_2$0$0 == 0x00e2
                    00E2    450 _ACC_2	=	0x00e2
                    00E3    451 Ftest_servos$ACC_3$0$0 == 0x00e3
                    00E3    452 _ACC_3	=	0x00e3
                    00E4    453 Ftest_servos$ACC_4$0$0 == 0x00e4
                    00E4    454 _ACC_4	=	0x00e4
                    00E5    455 Ftest_servos$ACC_5$0$0 == 0x00e5
                    00E5    456 _ACC_5	=	0x00e5
                    00E6    457 Ftest_servos$ACC_6$0$0 == 0x00e6
                    00E6    458 _ACC_6	=	0x00e6
                    00E7    459 Ftest_servos$ACC_7$0$0 == 0x00e7
                    00E7    460 _ACC_7	=	0x00e7
                    00E8    461 Ftest_servos$P2IF$0$0 == 0x00e8
                    00E8    462 _P2IF	=	0x00e8
                    00E9    463 Ftest_servos$UTX0IF$0$0 == 0x00e9
                    00E9    464 _UTX0IF	=	0x00e9
                    00EA    465 Ftest_servos$UTX1IF$0$0 == 0x00ea
                    00EA    466 _UTX1IF	=	0x00ea
                    00EB    467 Ftest_servos$P1IF$0$0 == 0x00eb
                    00EB    468 _P1IF	=	0x00eb
                    00EC    469 Ftest_servos$WDTIF$0$0 == 0x00ec
                    00EC    470 _WDTIF	=	0x00ec
                    00ED    471 Ftest_servos$_IRCON25$0$0 == 0x00ed
                    00ED    472 __IRCON25	=	0x00ed
                    00EE    473 Ftest_servos$_IRCON26$0$0 == 0x00ee
                    00EE    474 __IRCON26	=	0x00ee
                    00EF    475 Ftest_servos$_IRCON27$0$0 == 0x00ef
                    00EF    476 __IRCON27	=	0x00ef
                    00F0    477 Ftest_servos$B_0$0$0 == 0x00f0
                    00F0    478 _B_0	=	0x00f0
                    00F1    479 Ftest_servos$B_1$0$0 == 0x00f1
                    00F1    480 _B_1	=	0x00f1
                    00F2    481 Ftest_servos$B_2$0$0 == 0x00f2
                    00F2    482 _B_2	=	0x00f2
                    00F3    483 Ftest_servos$B_3$0$0 == 0x00f3
                    00F3    484 _B_3	=	0x00f3
                    00F4    485 Ftest_servos$B_4$0$0 == 0x00f4
                    00F4    486 _B_4	=	0x00f4
                    00F5    487 Ftest_servos$B_5$0$0 == 0x00f5
                    00F5    488 _B_5	=	0x00f5
                    00F6    489 Ftest_servos$B_6$0$0 == 0x00f6
                    00F6    490 _B_6	=	0x00f6
                    00F7    491 Ftest_servos$B_7$0$0 == 0x00f7
                    00F7    492 _B_7	=	0x00f7
                    00F8    493 Ftest_servos$U1ACTIVE$0$0 == 0x00f8
                    00F8    494 _U1ACTIVE	=	0x00f8
                    00F9    495 Ftest_servos$U1TX_BYTE$0$0 == 0x00f9
                    00F9    496 _U1TX_BYTE	=	0x00f9
                    00FA    497 Ftest_servos$U1RX_BYTE$0$0 == 0x00fa
                    00FA    498 _U1RX_BYTE	=	0x00fa
                    00FB    499 Ftest_servos$U1ERR$0$0 == 0x00fb
                    00FB    500 _U1ERR	=	0x00fb
                    00FC    501 Ftest_servos$U1FE$0$0 == 0x00fc
                    00FC    502 _U1FE	=	0x00fc
                    00FD    503 Ftest_servos$U1SLAVE$0$0 == 0x00fd
                    00FD    504 _U1SLAVE	=	0x00fd
                    00FE    505 Ftest_servos$U1RE$0$0 == 0x00fe
                    00FE    506 _U1RE	=	0x00fe
                    00FF    507 Ftest_servos$U1MODE$0$0 == 0x00ff
                    00FF    508 _U1MODE	=	0x00ff
                            509 ;--------------------------------------------------------
                            510 ; overlayable register banks
                            511 ;--------------------------------------------------------
                            512 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     513 	.ds 8
                            514 ;--------------------------------------------------------
                            515 ; internal ram data
                            516 ;--------------------------------------------------------
                            517 	.area DSEG    (DATA)
                            518 ;--------------------------------------------------------
                            519 ; overlayable items in internal ram 
                            520 ;--------------------------------------------------------
                            521 	.area OSEG    (OVR,DATA)
                            522 ;--------------------------------------------------------
                            523 ; Stack segment in internal ram 
                            524 ;--------------------------------------------------------
                            525 	.area	SSEG	(DATA)
   0022                     526 __start__stack:
   0022                     527 	.ds	1
                            528 
                            529 ;--------------------------------------------------------
                            530 ; indirectly addressable internal ram data
                            531 ;--------------------------------------------------------
                            532 	.area ISEG    (DATA)
                            533 ;--------------------------------------------------------
                            534 ; absolute internal ram data
                            535 ;--------------------------------------------------------
                            536 	.area IABS    (ABS,DATA)
                            537 	.area IABS    (ABS,DATA)
                            538 ;--------------------------------------------------------
                            539 ; bit data
                            540 ;--------------------------------------------------------
                            541 	.area BSEG    (BIT)
                            542 ;--------------------------------------------------------
                            543 ; paged external ram data
                            544 ;--------------------------------------------------------
                            545 	.area PSEG    (PAG,XDATA)
                            546 ;--------------------------------------------------------
                            547 ; external ram data
                            548 ;--------------------------------------------------------
                            549 	.area XSEG    (XDATA)
                    DF00    550 Ftest_servos$SYNC1$0$0 == 0xdf00
                    DF00    551 _SYNC1	=	0xdf00
                    DF01    552 Ftest_servos$SYNC0$0$0 == 0xdf01
                    DF01    553 _SYNC0	=	0xdf01
                    DF02    554 Ftest_servos$PKTLEN$0$0 == 0xdf02
                    DF02    555 _PKTLEN	=	0xdf02
                    DF03    556 Ftest_servos$PKTCTRL1$0$0 == 0xdf03
                    DF03    557 _PKTCTRL1	=	0xdf03
                    DF04    558 Ftest_servos$PKTCTRL0$0$0 == 0xdf04
                    DF04    559 _PKTCTRL0	=	0xdf04
                    DF05    560 Ftest_servos$ADDR$0$0 == 0xdf05
                    DF05    561 _ADDR	=	0xdf05
                    DF06    562 Ftest_servos$CHANNR$0$0 == 0xdf06
                    DF06    563 _CHANNR	=	0xdf06
                    DF07    564 Ftest_servos$FSCTRL1$0$0 == 0xdf07
                    DF07    565 _FSCTRL1	=	0xdf07
                    DF08    566 Ftest_servos$FSCTRL0$0$0 == 0xdf08
                    DF08    567 _FSCTRL0	=	0xdf08
                    DF09    568 Ftest_servos$FREQ2$0$0 == 0xdf09
                    DF09    569 _FREQ2	=	0xdf09
                    DF0A    570 Ftest_servos$FREQ1$0$0 == 0xdf0a
                    DF0A    571 _FREQ1	=	0xdf0a
                    DF0B    572 Ftest_servos$FREQ0$0$0 == 0xdf0b
                    DF0B    573 _FREQ0	=	0xdf0b
                    DF0C    574 Ftest_servos$MDMCFG4$0$0 == 0xdf0c
                    DF0C    575 _MDMCFG4	=	0xdf0c
                    DF0D    576 Ftest_servos$MDMCFG3$0$0 == 0xdf0d
                    DF0D    577 _MDMCFG3	=	0xdf0d
                    DF0E    578 Ftest_servos$MDMCFG2$0$0 == 0xdf0e
                    DF0E    579 _MDMCFG2	=	0xdf0e
                    DF0F    580 Ftest_servos$MDMCFG1$0$0 == 0xdf0f
                    DF0F    581 _MDMCFG1	=	0xdf0f
                    DF10    582 Ftest_servos$MDMCFG0$0$0 == 0xdf10
                    DF10    583 _MDMCFG0	=	0xdf10
                    DF11    584 Ftest_servos$DEVIATN$0$0 == 0xdf11
                    DF11    585 _DEVIATN	=	0xdf11
                    DF12    586 Ftest_servos$MCSM2$0$0 == 0xdf12
                    DF12    587 _MCSM2	=	0xdf12
                    DF13    588 Ftest_servos$MCSM1$0$0 == 0xdf13
                    DF13    589 _MCSM1	=	0xdf13
                    DF14    590 Ftest_servos$MCSM0$0$0 == 0xdf14
                    DF14    591 _MCSM0	=	0xdf14
                    DF15    592 Ftest_servos$FOCCFG$0$0 == 0xdf15
                    DF15    593 _FOCCFG	=	0xdf15
                    DF16    594 Ftest_servos$BSCFG$0$0 == 0xdf16
                    DF16    595 _BSCFG	=	0xdf16
                    DF17    596 Ftest_servos$AGCCTRL2$0$0 == 0xdf17
                    DF17    597 _AGCCTRL2	=	0xdf17
                    DF18    598 Ftest_servos$AGCCTRL1$0$0 == 0xdf18
                    DF18    599 _AGCCTRL1	=	0xdf18
                    DF19    600 Ftest_servos$AGCCTRL0$0$0 == 0xdf19
                    DF19    601 _AGCCTRL0	=	0xdf19
                    DF1A    602 Ftest_servos$FREND1$0$0 == 0xdf1a
                    DF1A    603 _FREND1	=	0xdf1a
                    DF1B    604 Ftest_servos$FREND0$0$0 == 0xdf1b
                    DF1B    605 _FREND0	=	0xdf1b
                    DF1C    606 Ftest_servos$FSCAL3$0$0 == 0xdf1c
                    DF1C    607 _FSCAL3	=	0xdf1c
                    DF1D    608 Ftest_servos$FSCAL2$0$0 == 0xdf1d
                    DF1D    609 _FSCAL2	=	0xdf1d
                    DF1E    610 Ftest_servos$FSCAL1$0$0 == 0xdf1e
                    DF1E    611 _FSCAL1	=	0xdf1e
                    DF1F    612 Ftest_servos$FSCAL0$0$0 == 0xdf1f
                    DF1F    613 _FSCAL0	=	0xdf1f
                    DF23    614 Ftest_servos$TEST2$0$0 == 0xdf23
                    DF23    615 _TEST2	=	0xdf23
                    DF24    616 Ftest_servos$TEST1$0$0 == 0xdf24
                    DF24    617 _TEST1	=	0xdf24
                    DF25    618 Ftest_servos$TEST0$0$0 == 0xdf25
                    DF25    619 _TEST0	=	0xdf25
                    DF2E    620 Ftest_servos$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    621 _PA_TABLE0	=	0xdf2e
                    DF2F    622 Ftest_servos$IOCFG2$0$0 == 0xdf2f
                    DF2F    623 _IOCFG2	=	0xdf2f
                    DF30    624 Ftest_servos$IOCFG1$0$0 == 0xdf30
                    DF30    625 _IOCFG1	=	0xdf30
                    DF31    626 Ftest_servos$IOCFG0$0$0 == 0xdf31
                    DF31    627 _IOCFG0	=	0xdf31
                    DF36    628 Ftest_servos$PARTNUM$0$0 == 0xdf36
                    DF36    629 _PARTNUM	=	0xdf36
                    DF37    630 Ftest_servos$VERSION$0$0 == 0xdf37
                    DF37    631 _VERSION	=	0xdf37
                    DF38    632 Ftest_servos$FREQEST$0$0 == 0xdf38
                    DF38    633 _FREQEST	=	0xdf38
                    DF39    634 Ftest_servos$LQI$0$0 == 0xdf39
                    DF39    635 _LQI	=	0xdf39
                    DF3A    636 Ftest_servos$RSSI$0$0 == 0xdf3a
                    DF3A    637 _RSSI	=	0xdf3a
                    DF3B    638 Ftest_servos$MARCSTATE$0$0 == 0xdf3b
                    DF3B    639 _MARCSTATE	=	0xdf3b
                    DF3C    640 Ftest_servos$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    641 _PKTSTATUS	=	0xdf3c
                    DF3D    642 Ftest_servos$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    643 _VCO_VC_DAC	=	0xdf3d
                    DF40    644 Ftest_servos$I2SCFG0$0$0 == 0xdf40
                    DF40    645 _I2SCFG0	=	0xdf40
                    DF41    646 Ftest_servos$I2SCFG1$0$0 == 0xdf41
                    DF41    647 _I2SCFG1	=	0xdf41
                    DF42    648 Ftest_servos$I2SDATL$0$0 == 0xdf42
                    DF42    649 _I2SDATL	=	0xdf42
                    DF43    650 Ftest_servos$I2SDATH$0$0 == 0xdf43
                    DF43    651 _I2SDATH	=	0xdf43
                    DF44    652 Ftest_servos$I2SWCNT$0$0 == 0xdf44
                    DF44    653 _I2SWCNT	=	0xdf44
                    DF45    654 Ftest_servos$I2SSTAT$0$0 == 0xdf45
                    DF45    655 _I2SSTAT	=	0xdf45
                    DF46    656 Ftest_servos$I2SCLKF0$0$0 == 0xdf46
                    DF46    657 _I2SCLKF0	=	0xdf46
                    DF47    658 Ftest_servos$I2SCLKF1$0$0 == 0xdf47
                    DF47    659 _I2SCLKF1	=	0xdf47
                    DF48    660 Ftest_servos$I2SCLKF2$0$0 == 0xdf48
                    DF48    661 _I2SCLKF2	=	0xdf48
                    DE00    662 Ftest_servos$USBADDR$0$0 == 0xde00
                    DE00    663 _USBADDR	=	0xde00
                    DE01    664 Ftest_servos$USBPOW$0$0 == 0xde01
                    DE01    665 _USBPOW	=	0xde01
                    DE02    666 Ftest_servos$USBIIF$0$0 == 0xde02
                    DE02    667 _USBIIF	=	0xde02
                    DE04    668 Ftest_servos$USBOIF$0$0 == 0xde04
                    DE04    669 _USBOIF	=	0xde04
                    DE06    670 Ftest_servos$USBCIF$0$0 == 0xde06
                    DE06    671 _USBCIF	=	0xde06
                    DE07    672 Ftest_servos$USBIIE$0$0 == 0xde07
                    DE07    673 _USBIIE	=	0xde07
                    DE09    674 Ftest_servos$USBOIE$0$0 == 0xde09
                    DE09    675 _USBOIE	=	0xde09
                    DE0B    676 Ftest_servos$USBCIE$0$0 == 0xde0b
                    DE0B    677 _USBCIE	=	0xde0b
                    DE0C    678 Ftest_servos$USBFRML$0$0 == 0xde0c
                    DE0C    679 _USBFRML	=	0xde0c
                    DE0D    680 Ftest_servos$USBFRMH$0$0 == 0xde0d
                    DE0D    681 _USBFRMH	=	0xde0d
                    DE0E    682 Ftest_servos$USBINDEX$0$0 == 0xde0e
                    DE0E    683 _USBINDEX	=	0xde0e
                    DE10    684 Ftest_servos$USBMAXI$0$0 == 0xde10
                    DE10    685 _USBMAXI	=	0xde10
                    DE11    686 Ftest_servos$USBCSIL$0$0 == 0xde11
                    DE11    687 _USBCSIL	=	0xde11
                    DE12    688 Ftest_servos$USBCSIH$0$0 == 0xde12
                    DE12    689 _USBCSIH	=	0xde12
                    DE13    690 Ftest_servos$USBMAXO$0$0 == 0xde13
                    DE13    691 _USBMAXO	=	0xde13
                    DE14    692 Ftest_servos$USBCSOL$0$0 == 0xde14
                    DE14    693 _USBCSOL	=	0xde14
                    DE15    694 Ftest_servos$USBCSOH$0$0 == 0xde15
                    DE15    695 _USBCSOH	=	0xde15
                    DE16    696 Ftest_servos$USBCNTL$0$0 == 0xde16
                    DE16    697 _USBCNTL	=	0xde16
                    DE17    698 Ftest_servos$USBCNTH$0$0 == 0xde17
                    DE17    699 _USBCNTH	=	0xde17
                    DE20    700 Ftest_servos$USBF0$0$0 == 0xde20
                    DE20    701 _USBF0	=	0xde20
                    DE22    702 Ftest_servos$USBF1$0$0 == 0xde22
                    DE22    703 _USBF1	=	0xde22
                    DE24    704 Ftest_servos$USBF2$0$0 == 0xde24
                    DE24    705 _USBF2	=	0xde24
                    DE26    706 Ftest_servos$USBF3$0$0 == 0xde26
                    DE26    707 _USBF3	=	0xde26
                    DE28    708 Ftest_servos$USBF4$0$0 == 0xde28
                    DE28    709 _USBF4	=	0xde28
                    DE2A    710 Ftest_servos$USBF5$0$0 == 0xde2a
                    DE2A    711 _USBF5	=	0xde2a
                            712 ;--------------------------------------------------------
                            713 ; absolute external ram data
                            714 ;--------------------------------------------------------
                            715 	.area XABS    (ABS,XDATA)
                            716 ;--------------------------------------------------------
                            717 ; external initialized ram data
                            718 ;--------------------------------------------------------
                            719 	.area XISEG   (XDATA)
                            720 	.area HOME    (CODE)
                            721 	.area GSINIT0 (CODE)
                            722 	.area GSINIT1 (CODE)
                            723 	.area GSINIT2 (CODE)
                            724 	.area GSINIT3 (CODE)
                            725 	.area GSINIT4 (CODE)
                            726 	.area GSINIT5 (CODE)
                            727 	.area GSINIT  (CODE)
                            728 	.area GSFINAL (CODE)
                            729 	.area CSEG    (CODE)
                            730 ;--------------------------------------------------------
                            731 ; interrupt vector 
                            732 ;--------------------------------------------------------
                            733 	.area HOME    (CODE)
   0400                     734 __interrupt_vect:
   0400 02 04 6D            735 	ljmp	__sdcc_gsinit_startup
   0403 32                  736 	reti
   0404                     737 	.ds	7
   040B 32                  738 	reti
   040C                     739 	.ds	7
   0413 32                  740 	reti
   0414                     741 	.ds	7
   041B 32                  742 	reti
   041C                     743 	.ds	7
   0423 32                  744 	reti
   0424                     745 	.ds	7
   042B 32                  746 	reti
   042C                     747 	.ds	7
   0433 32                  748 	reti
   0434                     749 	.ds	7
   043B 32                  750 	reti
   043C                     751 	.ds	7
   0443 32                  752 	reti
   0444                     753 	.ds	7
   044B 02 06 88            754 	ljmp	_ISR_T1
   044E                     755 	.ds	5
   0453 32                  756 	reti
   0454                     757 	.ds	7
   045B 32                  758 	reti
   045C                     759 	.ds	7
   0463 02 15 DD            760 	ljmp	_ISR_T4
                            761 ;--------------------------------------------------------
                            762 ; global & static initialisations
                            763 ;--------------------------------------------------------
                            764 	.area HOME    (CODE)
                            765 	.area GSINIT  (CODE)
                            766 	.area GSFINAL (CODE)
                            767 	.area GSINIT  (CODE)
                            768 	.globl __sdcc_gsinit_startup
                            769 	.globl __sdcc_program_startup
                            770 	.globl __start__stack
                            771 	.globl __mcs51_genXINIT
                            772 	.globl __mcs51_genXRAMCLEAR
                            773 	.globl __mcs51_genRAMCLEAR
                            774 	.area GSFINAL (CODE)
   04F7 02 04 66            775 	ljmp	__sdcc_program_startup
                            776 ;--------------------------------------------------------
                            777 ; Home
                            778 ;--------------------------------------------------------
                            779 	.area HOME    (CODE)
                            780 	.area HOME    (CODE)
   0466                     781 __sdcc_program_startup:
   0466 12 06 5C            782 	lcall	_main
                            783 ;	return from main will lock up
   0469 80 FE               784 	sjmp .
                            785 ;--------------------------------------------------------
                            786 ; code
                            787 ;--------------------------------------------------------
                            788 	.area CSEG    (CODE)
                            789 ;------------------------------------------------------------
                            790 ;Allocation info for local variables in function 'myServosInit'
                            791 ;------------------------------------------------------------
                    0000    792 	G$myServosInit$0$0 ==.
                    0000    793 	C$test_servos.c$26$0$0 ==.
                            794 ;	apps/test_servos/test_servos.c:26: void myServosInit()
                            795 ;	-----------------------------------------
                            796 ;	 function myServosInit
                            797 ;	-----------------------------------------
   04FA                     798 _myServosInit:
                    0007    799 	ar7 = 0x07
                    0006    800 	ar6 = 0x06
                    0005    801 	ar5 = 0x05
                    0004    802 	ar4 = 0x04
                    0003    803 	ar3 = 0x03
                    0002    804 	ar2 = 0x02
                    0001    805 	ar1 = 0x01
                    0000    806 	ar0 = 0x00
                    0000    807 	C$test_servos.c$29$1$1 ==.
                            808 ;	apps/test_servos/test_servos.c:29: servosStart((uint8 XDATA *)pins, sizeof(pins));
   04FA 90 17 63            809 	mov	dptr,#_pins
   04FD 78 04               810 	mov	r0,#_servosStart_PARM_2
   04FF 74 06               811 	mov	a,#0x06
   0501 F2                  812 	movx	@r0,a
   0502 12 08 8E            813 	lcall	_servosStart
                    000B    814 	C$test_servos.c$32$1$1 ==.
                            815 ;	apps/test_servos/test_servos.c:32: servoSetSpeed(0, 300);
   0505 78 0B               816 	mov	r0,#_servoSetSpeed_PARM_2
   0507 74 2C               817 	mov	a,#0x2C
   0509 F2                  818 	movx	@r0,a
   050A 08                  819 	inc	r0
   050B 74 01               820 	mov	a,#0x01
   050D F2                  821 	movx	@r0,a
   050E 75 82 00            822 	mov	dpl,#0x00
   0511 12 0B 6B            823 	lcall	_servoSetSpeed
                    001A    824 	C$test_servos.c$33$1$1 ==.
                            825 ;	apps/test_servos/test_servos.c:33: servoSetSpeed(1, 300);
   0514 78 0B               826 	mov	r0,#_servoSetSpeed_PARM_2
   0516 74 2C               827 	mov	a,#0x2C
   0518 F2                  828 	movx	@r0,a
   0519 08                  829 	inc	r0
   051A 74 01               830 	mov	a,#0x01
   051C F2                  831 	movx	@r0,a
   051D 75 82 01            832 	mov	dpl,#0x01
   0520 12 0B 6B            833 	lcall	_servoSetSpeed
                    0029    834 	C$test_servos.c$34$1$1 ==.
                            835 ;	apps/test_servos/test_servos.c:34: servoSetSpeed(2, 300);
   0523 78 0B               836 	mov	r0,#_servoSetSpeed_PARM_2
   0525 74 2C               837 	mov	a,#0x2C
   0527 F2                  838 	movx	@r0,a
   0528 08                  839 	inc	r0
   0529 74 01               840 	mov	a,#0x01
   052B F2                  841 	movx	@r0,a
   052C 75 82 02            842 	mov	dpl,#0x02
   052F 12 0B 6B            843 	lcall	_servoSetSpeed
                    0038    844 	C$test_servos.c$35$1$1 ==.
                            845 ;	apps/test_servos/test_servos.c:35: servoSetSpeed(3, 300);
   0532 78 0B               846 	mov	r0,#_servoSetSpeed_PARM_2
   0534 74 2C               847 	mov	a,#0x2C
   0536 F2                  848 	movx	@r0,a
   0537 08                  849 	inc	r0
   0538 74 01               850 	mov	a,#0x01
   053A F2                  851 	movx	@r0,a
   053B 75 82 03            852 	mov	dpl,#0x03
   053E 12 0B 6B            853 	lcall	_servoSetSpeed
                    0047    854 	C$test_servos.c$36$1$1 ==.
                            855 ;	apps/test_servos/test_servos.c:36: servoSetSpeed(4, 0);      // Not actually necessary because default speed is 0 (no speed limit).
   0541 78 0B               856 	mov	r0,#_servoSetSpeed_PARM_2
   0543 E4                  857 	clr	a
   0544 F2                  858 	movx	@r0,a
   0545 08                  859 	inc	r0
   0546 F2                  860 	movx	@r0,a
   0547 75 82 04            861 	mov	dpl,#0x04
   054A 12 0B 6B            862 	lcall	_servoSetSpeed
                    0053    863 	C$test_servos.c$40$1$1 ==.
                            864 ;	apps/test_servos/test_servos.c:40: servoSetSpeed(5, 0);      // Not actually necessary because default speed is 0 (no speed limit).
   054D 78 0B               865 	mov	r0,#_servoSetSpeed_PARM_2
   054F E4                  866 	clr	a
   0550 F2                  867 	movx	@r0,a
   0551 08                  868 	inc	r0
   0552 F2                  869 	movx	@r0,a
   0553 75 82 05            870 	mov	dpl,#0x05
   0556 12 0B 6B            871 	lcall	_servoSetSpeed
                    005F    872 	C$test_servos.c$41$1$1 ==.
                            873 ;	apps/test_servos/test_servos.c:41: servoSetTarget(5, 1000);
   0559 78 05               874 	mov	r0,#_servoSetTarget_PARM_2
   055B 74 E8               875 	mov	a,#0xE8
   055D F2                  876 	movx	@r0,a
   055E 08                  877 	inc	r0
   055F 74 03               878 	mov	a,#0x03
   0561 F2                  879 	movx	@r0,a
   0562 75 82 05            880 	mov	dpl,#0x05
   0565 12 0A 13            881 	lcall	_servoSetTarget
                    006E    882 	C$test_servos.c$42$1$1 ==.
                            883 ;	apps/test_servos/test_servos.c:42: servoSetSpeed(5, 1);
   0568 78 0B               884 	mov	r0,#_servoSetSpeed_PARM_2
   056A 74 01               885 	mov	a,#0x01
   056C F2                  886 	movx	@r0,a
   056D 08                  887 	inc	r0
   056E E4                  888 	clr	a
   056F F2                  889 	movx	@r0,a
   0570 75 82 05            890 	mov	dpl,#0x05
   0573 12 0B 6B            891 	lcall	_servoSetSpeed
                    007C    892 	C$test_servos.c$43$1$1 ==.
                            893 ;	apps/test_servos/test_servos.c:43: servoSetTarget(5, 2000);
   0576 78 05               894 	mov	r0,#_servoSetTarget_PARM_2
   0578 74 D0               895 	mov	a,#0xD0
   057A F2                  896 	movx	@r0,a
   057B 08                  897 	inc	r0
   057C 74 07               898 	mov	a,#0x07
   057E F2                  899 	movx	@r0,a
   057F 75 82 05            900 	mov	dpl,#0x05
   0582 12 0A 13            901 	lcall	_servoSetTarget
                    008B    902 	C$test_servos.c$44$1$1 ==.
                    008B    903 	XG$myServosInit$0$0 ==.
   0585 22                  904 	ret
                            905 ;------------------------------------------------------------
                            906 ;Allocation info for local variables in function 'updateServos'
                            907 ;------------------------------------------------------------
                    008C    908 	G$updateServos$0$0 ==.
                    008C    909 	C$test_servos.c$46$1$1 ==.
                            910 ;	apps/test_servos/test_servos.c:46: void updateServos()
                            911 ;	-----------------------------------------
                            912 ;	 function updateServos
                            913 ;	-----------------------------------------
   0586                     914 _updateServos:
                    008C    915 	C$test_servos.c$48$1$1 ==.
                            916 ;	apps/test_servos/test_servos.c:48: if (getMs() >> 11 & 1)
   0586 12 16 02            917 	lcall	_getMs
   0589 AD 83               918 	mov	r5,dph
   058B AE F0               919 	mov	r6,b
   058D FF                  920 	mov	r7,a
   058E ED                  921 	mov	a,r5
   058F A2 E3               922 	mov	c,acc[3]
   0591 E4                  923 	clr	a
   0592 33                  924 	rlc	a
   0593 FC                  925 	mov	r4,a
   0594 60 51               926 	jz	00102$
                    009C    927 	C$test_servos.c$54$2$2 ==.
                            928 ;	apps/test_servos/test_servos.c:54: servoSetTarget(0, 1000);  // Send servo 0 to position 1000 us.
   0596 78 05               929 	mov	r0,#_servoSetTarget_PARM_2
   0598 74 E8               930 	mov	a,#0xE8
   059A F2                  931 	movx	@r0,a
   059B 08                  932 	inc	r0
   059C 74 03               933 	mov	a,#0x03
   059E F2                  934 	movx	@r0,a
   059F 75 82 00            935 	mov	dpl,#0x00
   05A2 12 0A 13            936 	lcall	_servoSetTarget
                    00AB    937 	C$test_servos.c$55$2$2 ==.
                            938 ;	apps/test_servos/test_servos.c:55: servoSetTarget(1, 1500);
   05A5 78 05               939 	mov	r0,#_servoSetTarget_PARM_2
   05A7 74 DC               940 	mov	a,#0xDC
   05A9 F2                  941 	movx	@r0,a
   05AA 08                  942 	inc	r0
   05AB 74 05               943 	mov	a,#0x05
   05AD F2                  944 	movx	@r0,a
   05AE 75 82 01            945 	mov	dpl,#0x01
   05B1 12 0A 13            946 	lcall	_servoSetTarget
                    00BA    947 	C$test_servos.c$56$2$2 ==.
                            948 ;	apps/test_servos/test_servos.c:56: servoSetTarget(2, 1500);
   05B4 78 05               949 	mov	r0,#_servoSetTarget_PARM_2
   05B6 74 DC               950 	mov	a,#0xDC
   05B8 F2                  951 	movx	@r0,a
   05B9 08                  952 	inc	r0
   05BA 74 05               953 	mov	a,#0x05
   05BC F2                  954 	movx	@r0,a
   05BD 75 82 02            955 	mov	dpl,#0x02
   05C0 12 0A 13            956 	lcall	_servoSetTarget
                    00C9    957 	C$test_servos.c$57$2$2 ==.
                            958 ;	apps/test_servos/test_servos.c:57: servoSetTarget(3, 0);
   05C3 78 05               959 	mov	r0,#_servoSetTarget_PARM_2
   05C5 E4                  960 	clr	a
   05C6 F2                  961 	movx	@r0,a
   05C7 08                  962 	inc	r0
   05C8 F2                  963 	movx	@r0,a
   05C9 75 82 03            964 	mov	dpl,#0x03
   05CC 12 0A 13            965 	lcall	_servoSetTarget
                    00D5    966 	C$test_servos.c$58$2$2 ==.
                            967 ;	apps/test_servos/test_servos.c:58: servoSetTarget(4, 1900);
   05CF 78 05               968 	mov	r0,#_servoSetTarget_PARM_2
   05D1 74 6C               969 	mov	a,#0x6C
   05D3 F2                  970 	movx	@r0,a
   05D4 08                  971 	inc	r0
   05D5 74 07               972 	mov	a,#0x07
   05D7 F2                  973 	movx	@r0,a
   05D8 75 82 04            974 	mov	dpl,#0x04
   05DB 12 0A 13            975 	lcall	_servoSetTarget
                    00E4    976 	C$test_servos.c$60$3$3 ==.
                            977 ;	apps/test_servos/test_servos.c:60: LED_YELLOW(0);
   05DE AF FF               978 	mov	r7,_P2DIR
   05E0 53 07 FB            979 	anl	ar7,#0xFB
   05E3 8F FF               980 	mov	_P2DIR,r7
   05E5 80 4E               981 	sjmp	00104$
   05E7                     982 00102$:
                    00ED    983 	C$test_servos.c$64$2$4 ==.
                            984 ;	apps/test_servos/test_servos.c:64: servoSetTarget(0, 2000);
   05E7 78 05               985 	mov	r0,#_servoSetTarget_PARM_2
   05E9 74 D0               986 	mov	a,#0xD0
   05EB F2                  987 	movx	@r0,a
   05EC 08                  988 	inc	r0
   05ED 74 07               989 	mov	a,#0x07
   05EF F2                  990 	movx	@r0,a
   05F0 75 82 00            991 	mov	dpl,#0x00
   05F3 12 0A 13            992 	lcall	_servoSetTarget
                    00FC    993 	C$test_servos.c$65$2$4 ==.
                            994 ;	apps/test_servos/test_servos.c:65: servoSetTarget(1, 2000);
   05F6 78 05               995 	mov	r0,#_servoSetTarget_PARM_2
   05F8 74 D0               996 	mov	a,#0xD0
   05FA F2                  997 	movx	@r0,a
   05FB 08                  998 	inc	r0
   05FC 74 07               999 	mov	a,#0x07
   05FE F2                 1000 	movx	@r0,a
   05FF 75 82 01           1001 	mov	dpl,#0x01
   0602 12 0A 13           1002 	lcall	_servoSetTarget
                    010B   1003 	C$test_servos.c$66$2$4 ==.
                           1004 ;	apps/test_servos/test_servos.c:66: servoSetTarget(2, 1000);
   0605 78 05              1005 	mov	r0,#_servoSetTarget_PARM_2
   0607 74 E8              1006 	mov	a,#0xE8
   0609 F2                 1007 	movx	@r0,a
   060A 08                 1008 	inc	r0
   060B 74 03              1009 	mov	a,#0x03
   060D F2                 1010 	movx	@r0,a
   060E 75 82 02           1011 	mov	dpl,#0x02
   0611 12 0A 13           1012 	lcall	_servoSetTarget
                    011A   1013 	C$test_servos.c$67$2$4 ==.
                           1014 ;	apps/test_servos/test_servos.c:67: servoSetTarget(3, 1700);
   0614 78 05              1015 	mov	r0,#_servoSetTarget_PARM_2
   0616 74 A4              1016 	mov	a,#0xA4
   0618 F2                 1017 	movx	@r0,a
   0619 08                 1018 	inc	r0
   061A 74 06              1019 	mov	a,#0x06
   061C F2                 1020 	movx	@r0,a
   061D 75 82 03           1021 	mov	dpl,#0x03
   0620 12 0A 13           1022 	lcall	_servoSetTarget
                    0129   1023 	C$test_servos.c$68$2$4 ==.
                           1024 ;	apps/test_servos/test_servos.c:68: servoSetTarget(4, 1100);
   0623 78 05              1025 	mov	r0,#_servoSetTarget_PARM_2
   0625 74 4C              1026 	mov	a,#0x4C
   0627 F2                 1027 	movx	@r0,a
   0628 08                 1028 	inc	r0
   0629 74 04              1029 	mov	a,#0x04
   062B F2                 1030 	movx	@r0,a
   062C 75 82 04           1031 	mov	dpl,#0x04
   062F 12 0A 13           1032 	lcall	_servoSetTarget
                    0138   1033 	C$test_servos.c$70$3$5 ==.
                           1034 ;	apps/test_servos/test_servos.c:70: LED_YELLOW(1);
   0632 43 FF 04           1035 	orl	_P2DIR,#0x04
   0635                    1036 00104$:
                    013B   1037 	C$test_servos.c$72$1$1 ==.
                    013B   1038 	XG$updateServos$0$0 ==.
   0635 22                 1039 	ret
                           1040 ;------------------------------------------------------------
                           1041 ;Allocation info for local variables in function 'receiveCommands'
                           1042 ;------------------------------------------------------------
                    013C   1043 	G$receiveCommands$0$0 ==.
                    013C   1044 	C$test_servos.c$75$1$1 ==.
                           1045 ;	apps/test_servos/test_servos.c:75: void receiveCommands()
                           1046 ;	-----------------------------------------
                           1047 ;	 function receiveCommands
                           1048 ;	-----------------------------------------
   0636                    1049 _receiveCommands:
                    013C   1050 	C$test_servos.c$77$1$1 ==.
                           1051 ;	apps/test_servos/test_servos.c:77: if (usbComRxAvailable() == 0){ return; }
   0636 12 0C 89           1052 	lcall	_usbComRxAvailable
   0639 E5 82              1053 	mov	a,dpl
   063B 70 02              1054 	jnz	00102$
   063D 80 1C              1055 	sjmp	00108$
   063F                    1056 00102$:
                    0145   1057 	C$test_servos.c$78$1$1 ==.
                           1058 ;	apps/test_servos/test_servos.c:78: switch(usbComRxReceiveByte())
   063F 12 0C B3           1059 	lcall	_usbComRxReceiveByte
   0642 AF 82              1060 	mov	r7,dpl
   0644 BF 73 14           1061 	cjne	r7,#0x73,00108$
                    014D   1062 	C$test_servos.c$81$2$3 ==.
                           1063 ;	apps/test_servos/test_servos.c:81: if (servosStarted())
   0647 12 0A 0D           1064 	lcall	_servosStarted
   064A 50 05              1065 	jnc	00105$
                    0152   1066 	C$test_servos.c$83$3$4 ==.
                           1067 ;	apps/test_servos/test_servos.c:83: servosStop();
   064C 12 09 F0           1068 	lcall	_servosStop
   064F 80 0A              1069 	sjmp	00108$
   0651                    1070 00105$:
                    0157   1071 	C$test_servos.c$87$3$5 ==.
                           1072 ;	apps/test_servos/test_servos.c:87: servosStart(0, 0);
   0651 78 04              1073 	mov	r0,#_servosStart_PARM_2
   0653 E4                 1074 	clr	a
   0654 F2                 1075 	movx	@r0,a
   0655 90 00 00           1076 	mov	dptr,#0x0000
   0658 12 08 8E           1077 	lcall	_servosStart
                    0161   1078 	C$test_servos.c$90$1$1 ==.
                           1079 ;	apps/test_servos/test_servos.c:90: }
   065B                    1080 00108$:
                    0161   1081 	C$test_servos.c$91$1$1 ==.
                    0161   1082 	XG$receiveCommands$0$0 ==.
   065B 22                 1083 	ret
                           1084 ;------------------------------------------------------------
                           1085 ;Allocation info for local variables in function 'main'
                           1086 ;------------------------------------------------------------
                    0162   1087 	G$main$0$0 ==.
                    0162   1088 	C$test_servos.c$93$1$1 ==.
                           1089 ;	apps/test_servos/test_servos.c:93: void main()
                           1090 ;	-----------------------------------------
                           1091 ;	 function main
                           1092 ;	-----------------------------------------
   065C                    1093 _main:
                    0162   1094 	C$test_servos.c$95$1$1 ==.
                           1095 ;	apps/test_servos/test_servos.c:95: systemInit();
   065C 12 14 E2           1096 	lcall	_systemInit
                    0165   1097 	C$test_servos.c$96$1$1 ==.
                           1098 ;	apps/test_servos/test_servos.c:96: usbInit();
   065F 12 0E 7C           1099 	lcall	_usbInit
                    0168   1100 	C$test_servos.c$97$1$1 ==.
                           1101 ;	apps/test_servos/test_servos.c:97: myServosInit();
   0662 12 04 FA           1102 	lcall	_myServosInit
                    016B   1103 	C$test_servos.c$99$1$1 ==.
                           1104 ;	apps/test_servos/test_servos.c:99: while(1)
   0665                    1105 00102$:
                    016B   1106 	C$test_servos.c$101$2$2 ==.
                           1107 ;	apps/test_servos/test_servos.c:101: boardService();
   0665 12 14 EF           1108 	lcall	_boardService
                    016E   1109 	C$test_servos.c$102$2$2 ==.
                           1110 ;	apps/test_servos/test_servos.c:102: usbComService();
   0668 12 0D 1A           1111 	lcall	_usbComService
                    0171   1112 	C$test_servos.c$103$2$2 ==.
                           1113 ;	apps/test_servos/test_servos.c:103: usbShowStatusWithGreenLed();
   066B 12 16 BA           1114 	lcall	_usbShowStatusWithGreenLed
                    0174   1115 	C$test_servos.c$104$2$2 ==.
                           1116 ;	apps/test_servos/test_servos.c:104: updateServos();
   066E 12 05 86           1117 	lcall	_updateServos
                    0177   1118 	C$test_servos.c$105$2$2 ==.
                           1119 ;	apps/test_servos/test_servos.c:105: receiveCommands();
   0671 12 06 36           1120 	lcall	_receiveCommands
                    017A   1121 	C$test_servos.c$108$3$3 ==.
                           1122 ;	apps/test_servos/test_servos.c:108: LED_RED(servosMoving());
   0674 12 0A 10           1123 	lcall	_servosMoving
   0677 50 05              1124 	jnc	00106$
   0679 43 FF 02           1125 	orl	_P2DIR,#0x02
   067C 80 E7              1126 	sjmp	00102$
   067E                    1127 00106$:
   067E AF FF              1128 	mov	r7,_P2DIR
   0680 53 07 FD           1129 	anl	ar7,#0xFD
   0683 8F FF              1130 	mov	_P2DIR,r7
   0685 80 DE              1131 	sjmp	00102$
                    018D   1132 	C$test_servos.c$110$1$1 ==.
                    018D   1133 	XG$main$0$0 ==.
   0687 22                 1134 	ret
                           1135 	.area CSEG    (CODE)
                           1136 	.area CONST   (CODE)
                    0000   1137 G$pins$0$0 == .
   1763                    1138 _pins:
   1763 02                 1139 	.db #0x02	; 2
   1764 03                 1140 	.db #0x03	; 3
   1765 04                 1141 	.db #0x04	; 4
   1766 0C                 1142 	.db #0x0C	; 12
   1767 0B                 1143 	.db #0x0B	; 11
   1768 0A                 1144 	.db #0x0A	; 10
                           1145 	.area XINIT   (CODE)
                           1146 	.area CABS    (ABS,CODE)
