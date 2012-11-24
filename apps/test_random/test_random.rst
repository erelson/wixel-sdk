                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:14 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_random
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _receiveCommands
                             14 	.globl _nibbleToAscii
                             15 	.globl _updateLeds
                             16 	.globl _usbComTxSend
                             17 	.globl _usbComTxAvailable
                             18 	.globl _usbComRxReceiveByte
                             19 	.globl _usbComRxAvailable
                             20 	.globl _usbComService
                             21 	.globl _usbShowStatusWithGreenLed
                             22 	.globl _usbInit
                             23 	.globl _randomSeed
                             24 	.globl _randomNumber
                             25 	.globl _randomSeedFromSerialNumber
                             26 	.globl _randomSeedFromAdc
                             27 	.globl _adcRead
                             28 	.globl _getMs
                             29 	.globl _boardService
                             30 	.globl _systemInit
                             31 	.globl _nextToggle
                             32 	.globl _blinkYellow
                             33 ;--------------------------------------------------------
                             34 ; special function registers
                             35 ;--------------------------------------------------------
                             36 	.area RSEG    (ABS,DATA)
   0000                      37 	.org 0x0000
                    0080     38 Ftest_random$P0$0$0 == 0x0080
                    0080     39 _P0	=	0x0080
                    0081     40 Ftest_random$SP$0$0 == 0x0081
                    0081     41 _SP	=	0x0081
                    0082     42 Ftest_random$DPL0$0$0 == 0x0082
                    0082     43 _DPL0	=	0x0082
                    0083     44 Ftest_random$DPH0$0$0 == 0x0083
                    0083     45 _DPH0	=	0x0083
                    0084     46 Ftest_random$DPL1$0$0 == 0x0084
                    0084     47 _DPL1	=	0x0084
                    0085     48 Ftest_random$DPH1$0$0 == 0x0085
                    0085     49 _DPH1	=	0x0085
                    0086     50 Ftest_random$U0CSR$0$0 == 0x0086
                    0086     51 _U0CSR	=	0x0086
                    0087     52 Ftest_random$PCON$0$0 == 0x0087
                    0087     53 _PCON	=	0x0087
                    0088     54 Ftest_random$TCON$0$0 == 0x0088
                    0088     55 _TCON	=	0x0088
                    0089     56 Ftest_random$P0IFG$0$0 == 0x0089
                    0089     57 _P0IFG	=	0x0089
                    008A     58 Ftest_random$P1IFG$0$0 == 0x008a
                    008A     59 _P1IFG	=	0x008a
                    008B     60 Ftest_random$P2IFG$0$0 == 0x008b
                    008B     61 _P2IFG	=	0x008b
                    008C     62 Ftest_random$PICTL$0$0 == 0x008c
                    008C     63 _PICTL	=	0x008c
                    008D     64 Ftest_random$P1IEN$0$0 == 0x008d
                    008D     65 _P1IEN	=	0x008d
                    008F     66 Ftest_random$P0INP$0$0 == 0x008f
                    008F     67 _P0INP	=	0x008f
                    0090     68 Ftest_random$P1$0$0 == 0x0090
                    0090     69 _P1	=	0x0090
                    0091     70 Ftest_random$RFIM$0$0 == 0x0091
                    0091     71 _RFIM	=	0x0091
                    0092     72 Ftest_random$DPS$0$0 == 0x0092
                    0092     73 _DPS	=	0x0092
                    0093     74 Ftest_random$MPAGE$0$0 == 0x0093
                    0093     75 _MPAGE	=	0x0093
                    0095     76 Ftest_random$ENDIAN$0$0 == 0x0095
                    0095     77 _ENDIAN	=	0x0095
                    0098     78 Ftest_random$S0CON$0$0 == 0x0098
                    0098     79 _S0CON	=	0x0098
                    009A     80 Ftest_random$IEN2$0$0 == 0x009a
                    009A     81 _IEN2	=	0x009a
                    009B     82 Ftest_random$S1CON$0$0 == 0x009b
                    009B     83 _S1CON	=	0x009b
                    009C     84 Ftest_random$T2CT$0$0 == 0x009c
                    009C     85 _T2CT	=	0x009c
                    009D     86 Ftest_random$T2PR$0$0 == 0x009d
                    009D     87 _T2PR	=	0x009d
                    009E     88 Ftest_random$T2CTL$0$0 == 0x009e
                    009E     89 _T2CTL	=	0x009e
                    00A0     90 Ftest_random$P2$0$0 == 0x00a0
                    00A0     91 _P2	=	0x00a0
                    00A1     92 Ftest_random$WORIRQ$0$0 == 0x00a1
                    00A1     93 _WORIRQ	=	0x00a1
                    00A2     94 Ftest_random$WORCTRL$0$0 == 0x00a2
                    00A2     95 _WORCTRL	=	0x00a2
                    00A3     96 Ftest_random$WOREVT0$0$0 == 0x00a3
                    00A3     97 _WOREVT0	=	0x00a3
                    00A4     98 Ftest_random$WOREVT1$0$0 == 0x00a4
                    00A4     99 _WOREVT1	=	0x00a4
                    00A5    100 Ftest_random$WORTIME0$0$0 == 0x00a5
                    00A5    101 _WORTIME0	=	0x00a5
                    00A6    102 Ftest_random$WORTIME1$0$0 == 0x00a6
                    00A6    103 _WORTIME1	=	0x00a6
                    00A8    104 Ftest_random$IEN0$0$0 == 0x00a8
                    00A8    105 _IEN0	=	0x00a8
                    00A9    106 Ftest_random$IP0$0$0 == 0x00a9
                    00A9    107 _IP0	=	0x00a9
                    00AB    108 Ftest_random$FWT$0$0 == 0x00ab
                    00AB    109 _FWT	=	0x00ab
                    00AC    110 Ftest_random$FADDRL$0$0 == 0x00ac
                    00AC    111 _FADDRL	=	0x00ac
                    00AD    112 Ftest_random$FADDRH$0$0 == 0x00ad
                    00AD    113 _FADDRH	=	0x00ad
                    00AE    114 Ftest_random$FCTL$0$0 == 0x00ae
                    00AE    115 _FCTL	=	0x00ae
                    00AF    116 Ftest_random$FWDATA$0$0 == 0x00af
                    00AF    117 _FWDATA	=	0x00af
                    00B1    118 Ftest_random$ENCDI$0$0 == 0x00b1
                    00B1    119 _ENCDI	=	0x00b1
                    00B2    120 Ftest_random$ENCDO$0$0 == 0x00b2
                    00B2    121 _ENCDO	=	0x00b2
                    00B3    122 Ftest_random$ENCCS$0$0 == 0x00b3
                    00B3    123 _ENCCS	=	0x00b3
                    00B4    124 Ftest_random$ADCCON1$0$0 == 0x00b4
                    00B4    125 _ADCCON1	=	0x00b4
                    00B5    126 Ftest_random$ADCCON2$0$0 == 0x00b5
                    00B5    127 _ADCCON2	=	0x00b5
                    00B6    128 Ftest_random$ADCCON3$0$0 == 0x00b6
                    00B6    129 _ADCCON3	=	0x00b6
                    00B8    130 Ftest_random$IEN1$0$0 == 0x00b8
                    00B8    131 _IEN1	=	0x00b8
                    00B9    132 Ftest_random$IP1$0$0 == 0x00b9
                    00B9    133 _IP1	=	0x00b9
                    00BA    134 Ftest_random$ADCL$0$0 == 0x00ba
                    00BA    135 _ADCL	=	0x00ba
                    00BB    136 Ftest_random$ADCH$0$0 == 0x00bb
                    00BB    137 _ADCH	=	0x00bb
                    00BC    138 Ftest_random$RNDL$0$0 == 0x00bc
                    00BC    139 _RNDL	=	0x00bc
                    00BD    140 Ftest_random$RNDH$0$0 == 0x00bd
                    00BD    141 _RNDH	=	0x00bd
                    00BE    142 Ftest_random$SLEEP$0$0 == 0x00be
                    00BE    143 _SLEEP	=	0x00be
                    00C0    144 Ftest_random$IRCON$0$0 == 0x00c0
                    00C0    145 _IRCON	=	0x00c0
                    00C1    146 Ftest_random$U0DBUF$0$0 == 0x00c1
                    00C1    147 _U0DBUF	=	0x00c1
                    00C2    148 Ftest_random$U0BAUD$0$0 == 0x00c2
                    00C2    149 _U0BAUD	=	0x00c2
                    00C4    150 Ftest_random$U0UCR$0$0 == 0x00c4
                    00C4    151 _U0UCR	=	0x00c4
                    00C5    152 Ftest_random$U0GCR$0$0 == 0x00c5
                    00C5    153 _U0GCR	=	0x00c5
                    00C6    154 Ftest_random$CLKCON$0$0 == 0x00c6
                    00C6    155 _CLKCON	=	0x00c6
                    00C7    156 Ftest_random$MEMCTR$0$0 == 0x00c7
                    00C7    157 _MEMCTR	=	0x00c7
                    00C9    158 Ftest_random$WDCTL$0$0 == 0x00c9
                    00C9    159 _WDCTL	=	0x00c9
                    00CA    160 Ftest_random$T3CNT$0$0 == 0x00ca
                    00CA    161 _T3CNT	=	0x00ca
                    00CB    162 Ftest_random$T3CTL$0$0 == 0x00cb
                    00CB    163 _T3CTL	=	0x00cb
                    00CC    164 Ftest_random$T3CCTL0$0$0 == 0x00cc
                    00CC    165 _T3CCTL0	=	0x00cc
                    00CD    166 Ftest_random$T3CC0$0$0 == 0x00cd
                    00CD    167 _T3CC0	=	0x00cd
                    00CE    168 Ftest_random$T3CCTL1$0$0 == 0x00ce
                    00CE    169 _T3CCTL1	=	0x00ce
                    00CF    170 Ftest_random$T3CC1$0$0 == 0x00cf
                    00CF    171 _T3CC1	=	0x00cf
                    00D0    172 Ftest_random$PSW$0$0 == 0x00d0
                    00D0    173 _PSW	=	0x00d0
                    00D1    174 Ftest_random$DMAIRQ$0$0 == 0x00d1
                    00D1    175 _DMAIRQ	=	0x00d1
                    00D2    176 Ftest_random$DMA1CFGL$0$0 == 0x00d2
                    00D2    177 _DMA1CFGL	=	0x00d2
                    00D3    178 Ftest_random$DMA1CFGH$0$0 == 0x00d3
                    00D3    179 _DMA1CFGH	=	0x00d3
                    00D4    180 Ftest_random$DMA0CFGL$0$0 == 0x00d4
                    00D4    181 _DMA0CFGL	=	0x00d4
                    00D5    182 Ftest_random$DMA0CFGH$0$0 == 0x00d5
                    00D5    183 _DMA0CFGH	=	0x00d5
                    00D6    184 Ftest_random$DMAARM$0$0 == 0x00d6
                    00D6    185 _DMAARM	=	0x00d6
                    00D7    186 Ftest_random$DMAREQ$0$0 == 0x00d7
                    00D7    187 _DMAREQ	=	0x00d7
                    00D8    188 Ftest_random$TIMIF$0$0 == 0x00d8
                    00D8    189 _TIMIF	=	0x00d8
                    00D9    190 Ftest_random$RFD$0$0 == 0x00d9
                    00D9    191 _RFD	=	0x00d9
                    00DA    192 Ftest_random$T1CC0L$0$0 == 0x00da
                    00DA    193 _T1CC0L	=	0x00da
                    00DB    194 Ftest_random$T1CC0H$0$0 == 0x00db
                    00DB    195 _T1CC0H	=	0x00db
                    00DC    196 Ftest_random$T1CC1L$0$0 == 0x00dc
                    00DC    197 _T1CC1L	=	0x00dc
                    00DD    198 Ftest_random$T1CC1H$0$0 == 0x00dd
                    00DD    199 _T1CC1H	=	0x00dd
                    00DE    200 Ftest_random$T1CC2L$0$0 == 0x00de
                    00DE    201 _T1CC2L	=	0x00de
                    00DF    202 Ftest_random$T1CC2H$0$0 == 0x00df
                    00DF    203 _T1CC2H	=	0x00df
                    00E0    204 Ftest_random$ACC$0$0 == 0x00e0
                    00E0    205 _ACC	=	0x00e0
                    00E1    206 Ftest_random$RFST$0$0 == 0x00e1
                    00E1    207 _RFST	=	0x00e1
                    00E2    208 Ftest_random$T1CNTL$0$0 == 0x00e2
                    00E2    209 _T1CNTL	=	0x00e2
                    00E3    210 Ftest_random$T1CNTH$0$0 == 0x00e3
                    00E3    211 _T1CNTH	=	0x00e3
                    00E4    212 Ftest_random$T1CTL$0$0 == 0x00e4
                    00E4    213 _T1CTL	=	0x00e4
                    00E5    214 Ftest_random$T1CCTL0$0$0 == 0x00e5
                    00E5    215 _T1CCTL0	=	0x00e5
                    00E6    216 Ftest_random$T1CCTL1$0$0 == 0x00e6
                    00E6    217 _T1CCTL1	=	0x00e6
                    00E7    218 Ftest_random$T1CCTL2$0$0 == 0x00e7
                    00E7    219 _T1CCTL2	=	0x00e7
                    00E8    220 Ftest_random$IRCON2$0$0 == 0x00e8
                    00E8    221 _IRCON2	=	0x00e8
                    00E9    222 Ftest_random$RFIF$0$0 == 0x00e9
                    00E9    223 _RFIF	=	0x00e9
                    00EA    224 Ftest_random$T4CNT$0$0 == 0x00ea
                    00EA    225 _T4CNT	=	0x00ea
                    00EB    226 Ftest_random$T4CTL$0$0 == 0x00eb
                    00EB    227 _T4CTL	=	0x00eb
                    00EC    228 Ftest_random$T4CCTL0$0$0 == 0x00ec
                    00EC    229 _T4CCTL0	=	0x00ec
                    00ED    230 Ftest_random$T4CC0$0$0 == 0x00ed
                    00ED    231 _T4CC0	=	0x00ed
                    00EE    232 Ftest_random$T4CCTL1$0$0 == 0x00ee
                    00EE    233 _T4CCTL1	=	0x00ee
                    00EF    234 Ftest_random$T4CC1$0$0 == 0x00ef
                    00EF    235 _T4CC1	=	0x00ef
                    00F0    236 Ftest_random$B$0$0 == 0x00f0
                    00F0    237 _B	=	0x00f0
                    00F1    238 Ftest_random$PERCFG$0$0 == 0x00f1
                    00F1    239 _PERCFG	=	0x00f1
                    00F2    240 Ftest_random$ADCCFG$0$0 == 0x00f2
                    00F2    241 _ADCCFG	=	0x00f2
                    00F3    242 Ftest_random$P0SEL$0$0 == 0x00f3
                    00F3    243 _P0SEL	=	0x00f3
                    00F4    244 Ftest_random$P1SEL$0$0 == 0x00f4
                    00F4    245 _P1SEL	=	0x00f4
                    00F5    246 Ftest_random$P2SEL$0$0 == 0x00f5
                    00F5    247 _P2SEL	=	0x00f5
                    00F6    248 Ftest_random$P1INP$0$0 == 0x00f6
                    00F6    249 _P1INP	=	0x00f6
                    00F7    250 Ftest_random$P2INP$0$0 == 0x00f7
                    00F7    251 _P2INP	=	0x00f7
                    00F8    252 Ftest_random$U1CSR$0$0 == 0x00f8
                    00F8    253 _U1CSR	=	0x00f8
                    00F9    254 Ftest_random$U1DBUF$0$0 == 0x00f9
                    00F9    255 _U1DBUF	=	0x00f9
                    00FA    256 Ftest_random$U1BAUD$0$0 == 0x00fa
                    00FA    257 _U1BAUD	=	0x00fa
                    00FB    258 Ftest_random$U1UCR$0$0 == 0x00fb
                    00FB    259 _U1UCR	=	0x00fb
                    00FC    260 Ftest_random$U1GCR$0$0 == 0x00fc
                    00FC    261 _U1GCR	=	0x00fc
                    00FD    262 Ftest_random$P0DIR$0$0 == 0x00fd
                    00FD    263 _P0DIR	=	0x00fd
                    00FE    264 Ftest_random$P1DIR$0$0 == 0x00fe
                    00FE    265 _P1DIR	=	0x00fe
                    00FF    266 Ftest_random$P2DIR$0$0 == 0x00ff
                    00FF    267 _P2DIR	=	0x00ff
                    FFFFD5D4    268 Ftest_random$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    269 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    270 Ftest_random$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    271 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    272 Ftest_random$FADDR$0$0 == 0xffffadac
                    FFFFADAC    273 _FADDR	=	0xffffadac
                    FFFFBBBA    274 Ftest_random$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    275 _ADC	=	0xffffbbba
                    FFFFDBDA    276 Ftest_random$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    277 _T1CC0	=	0xffffdbda
                    FFFFDDDC    278 Ftest_random$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    279 _T1CC1	=	0xffffdddc
                    FFFFDFDE    280 Ftest_random$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    281 _T1CC2	=	0xffffdfde
                            282 ;--------------------------------------------------------
                            283 ; special function bits
                            284 ;--------------------------------------------------------
                            285 	.area RSEG    (ABS,DATA)
   0000                     286 	.org 0x0000
                    0080    287 Ftest_random$P0_0$0$0 == 0x0080
                    0080    288 _P0_0	=	0x0080
                    0081    289 Ftest_random$P0_1$0$0 == 0x0081
                    0081    290 _P0_1	=	0x0081
                    0082    291 Ftest_random$P0_2$0$0 == 0x0082
                    0082    292 _P0_2	=	0x0082
                    0083    293 Ftest_random$P0_3$0$0 == 0x0083
                    0083    294 _P0_3	=	0x0083
                    0084    295 Ftest_random$P0_4$0$0 == 0x0084
                    0084    296 _P0_4	=	0x0084
                    0085    297 Ftest_random$P0_5$0$0 == 0x0085
                    0085    298 _P0_5	=	0x0085
                    0086    299 Ftest_random$P0_6$0$0 == 0x0086
                    0086    300 _P0_6	=	0x0086
                    0087    301 Ftest_random$P0_7$0$0 == 0x0087
                    0087    302 _P0_7	=	0x0087
                    0088    303 Ftest_random$_TCON_0$0$0 == 0x0088
                    0088    304 __TCON_0	=	0x0088
                    0089    305 Ftest_random$RFTXRXIF$0$0 == 0x0089
                    0089    306 _RFTXRXIF	=	0x0089
                    008A    307 Ftest_random$_TCON_2$0$0 == 0x008a
                    008A    308 __TCON_2	=	0x008a
                    008B    309 Ftest_random$URX0IF$0$0 == 0x008b
                    008B    310 _URX0IF	=	0x008b
                    008C    311 Ftest_random$_TCON_4$0$0 == 0x008c
                    008C    312 __TCON_4	=	0x008c
                    008D    313 Ftest_random$ADCIF$0$0 == 0x008d
                    008D    314 _ADCIF	=	0x008d
                    008E    315 Ftest_random$_TCON_6$0$0 == 0x008e
                    008E    316 __TCON_6	=	0x008e
                    008F    317 Ftest_random$URX1IF$0$0 == 0x008f
                    008F    318 _URX1IF	=	0x008f
                    0090    319 Ftest_random$P1_0$0$0 == 0x0090
                    0090    320 _P1_0	=	0x0090
                    0091    321 Ftest_random$P1_1$0$0 == 0x0091
                    0091    322 _P1_1	=	0x0091
                    0092    323 Ftest_random$P1_2$0$0 == 0x0092
                    0092    324 _P1_2	=	0x0092
                    0093    325 Ftest_random$P1_3$0$0 == 0x0093
                    0093    326 _P1_3	=	0x0093
                    0094    327 Ftest_random$P1_4$0$0 == 0x0094
                    0094    328 _P1_4	=	0x0094
                    0095    329 Ftest_random$P1_5$0$0 == 0x0095
                    0095    330 _P1_5	=	0x0095
                    0096    331 Ftest_random$P1_6$0$0 == 0x0096
                    0096    332 _P1_6	=	0x0096
                    0097    333 Ftest_random$P1_7$0$0 == 0x0097
                    0097    334 _P1_7	=	0x0097
                    0098    335 Ftest_random$ENCIF_0$0$0 == 0x0098
                    0098    336 _ENCIF_0	=	0x0098
                    0099    337 Ftest_random$ENCIF_1$0$0 == 0x0099
                    0099    338 _ENCIF_1	=	0x0099
                    009A    339 Ftest_random$_SOCON2$0$0 == 0x009a
                    009A    340 __SOCON2	=	0x009a
                    009B    341 Ftest_random$_SOCON3$0$0 == 0x009b
                    009B    342 __SOCON3	=	0x009b
                    009C    343 Ftest_random$_SOCON4$0$0 == 0x009c
                    009C    344 __SOCON4	=	0x009c
                    009D    345 Ftest_random$_SOCON5$0$0 == 0x009d
                    009D    346 __SOCON5	=	0x009d
                    009E    347 Ftest_random$_SOCON6$0$0 == 0x009e
                    009E    348 __SOCON6	=	0x009e
                    009F    349 Ftest_random$_SOCON7$0$0 == 0x009f
                    009F    350 __SOCON7	=	0x009f
                    00A0    351 Ftest_random$P2_0$0$0 == 0x00a0
                    00A0    352 _P2_0	=	0x00a0
                    00A1    353 Ftest_random$P2_1$0$0 == 0x00a1
                    00A1    354 _P2_1	=	0x00a1
                    00A2    355 Ftest_random$P2_2$0$0 == 0x00a2
                    00A2    356 _P2_2	=	0x00a2
                    00A3    357 Ftest_random$P2_3$0$0 == 0x00a3
                    00A3    358 _P2_3	=	0x00a3
                    00A4    359 Ftest_random$P2_4$0$0 == 0x00a4
                    00A4    360 _P2_4	=	0x00a4
                    00A5    361 Ftest_random$P2_5$0$0 == 0x00a5
                    00A5    362 _P2_5	=	0x00a5
                    00A6    363 Ftest_random$P2_6$0$0 == 0x00a6
                    00A6    364 _P2_6	=	0x00a6
                    00A7    365 Ftest_random$P2_7$0$0 == 0x00a7
                    00A7    366 _P2_7	=	0x00a7
                    00A8    367 Ftest_random$RFTXRXIE$0$0 == 0x00a8
                    00A8    368 _RFTXRXIE	=	0x00a8
                    00A9    369 Ftest_random$ADCIE$0$0 == 0x00a9
                    00A9    370 _ADCIE	=	0x00a9
                    00AA    371 Ftest_random$URX0IE$0$0 == 0x00aa
                    00AA    372 _URX0IE	=	0x00aa
                    00AB    373 Ftest_random$URX1IE$0$0 == 0x00ab
                    00AB    374 _URX1IE	=	0x00ab
                    00AC    375 Ftest_random$ENCIE$0$0 == 0x00ac
                    00AC    376 _ENCIE	=	0x00ac
                    00AD    377 Ftest_random$STIE$0$0 == 0x00ad
                    00AD    378 _STIE	=	0x00ad
                    00AE    379 Ftest_random$_IEN06$0$0 == 0x00ae
                    00AE    380 __IEN06	=	0x00ae
                    00AF    381 Ftest_random$EA$0$0 == 0x00af
                    00AF    382 _EA	=	0x00af
                    00B8    383 Ftest_random$DMAIE$0$0 == 0x00b8
                    00B8    384 _DMAIE	=	0x00b8
                    00B9    385 Ftest_random$T1IE$0$0 == 0x00b9
                    00B9    386 _T1IE	=	0x00b9
                    00BA    387 Ftest_random$T2IE$0$0 == 0x00ba
                    00BA    388 _T2IE	=	0x00ba
                    00BB    389 Ftest_random$T3IE$0$0 == 0x00bb
                    00BB    390 _T3IE	=	0x00bb
                    00BC    391 Ftest_random$T4IE$0$0 == 0x00bc
                    00BC    392 _T4IE	=	0x00bc
                    00BD    393 Ftest_random$P0IE$0$0 == 0x00bd
                    00BD    394 _P0IE	=	0x00bd
                    00BE    395 Ftest_random$_IEN16$0$0 == 0x00be
                    00BE    396 __IEN16	=	0x00be
                    00BF    397 Ftest_random$_IEN17$0$0 == 0x00bf
                    00BF    398 __IEN17	=	0x00bf
                    00C0    399 Ftest_random$DMAIF$0$0 == 0x00c0
                    00C0    400 _DMAIF	=	0x00c0
                    00C1    401 Ftest_random$T1IF$0$0 == 0x00c1
                    00C1    402 _T1IF	=	0x00c1
                    00C2    403 Ftest_random$T2IF$0$0 == 0x00c2
                    00C2    404 _T2IF	=	0x00c2
                    00C3    405 Ftest_random$T3IF$0$0 == 0x00c3
                    00C3    406 _T3IF	=	0x00c3
                    00C4    407 Ftest_random$T4IF$0$0 == 0x00c4
                    00C4    408 _T4IF	=	0x00c4
                    00C5    409 Ftest_random$P0IF$0$0 == 0x00c5
                    00C5    410 _P0IF	=	0x00c5
                    00C6    411 Ftest_random$_IRCON6$0$0 == 0x00c6
                    00C6    412 __IRCON6	=	0x00c6
                    00C7    413 Ftest_random$STIF$0$0 == 0x00c7
                    00C7    414 _STIF	=	0x00c7
                    00D0    415 Ftest_random$P$0$0 == 0x00d0
                    00D0    416 _P	=	0x00d0
                    00D1    417 Ftest_random$F1$0$0 == 0x00d1
                    00D1    418 _F1	=	0x00d1
                    00D2    419 Ftest_random$OV$0$0 == 0x00d2
                    00D2    420 _OV	=	0x00d2
                    00D3    421 Ftest_random$RS0$0$0 == 0x00d3
                    00D3    422 _RS0	=	0x00d3
                    00D4    423 Ftest_random$RS1$0$0 == 0x00d4
                    00D4    424 _RS1	=	0x00d4
                    00D5    425 Ftest_random$F0$0$0 == 0x00d5
                    00D5    426 _F0	=	0x00d5
                    00D6    427 Ftest_random$AC$0$0 == 0x00d6
                    00D6    428 _AC	=	0x00d6
                    00D7    429 Ftest_random$CY$0$0 == 0x00d7
                    00D7    430 _CY	=	0x00d7
                    00D8    431 Ftest_random$T3OVFIF$0$0 == 0x00d8
                    00D8    432 _T3OVFIF	=	0x00d8
                    00D9    433 Ftest_random$T3CH0IF$0$0 == 0x00d9
                    00D9    434 _T3CH0IF	=	0x00d9
                    00DA    435 Ftest_random$T3CH1IF$0$0 == 0x00da
                    00DA    436 _T3CH1IF	=	0x00da
                    00DB    437 Ftest_random$T4OVFIF$0$0 == 0x00db
                    00DB    438 _T4OVFIF	=	0x00db
                    00DC    439 Ftest_random$T4CH0IF$0$0 == 0x00dc
                    00DC    440 _T4CH0IF	=	0x00dc
                    00DD    441 Ftest_random$T4CH1IF$0$0 == 0x00dd
                    00DD    442 _T4CH1IF	=	0x00dd
                    00DE    443 Ftest_random$OVFIM$0$0 == 0x00de
                    00DE    444 _OVFIM	=	0x00de
                    00DF    445 Ftest_random$_TIMIF7$0$0 == 0x00df
                    00DF    446 __TIMIF7	=	0x00df
                    00E0    447 Ftest_random$ACC_0$0$0 == 0x00e0
                    00E0    448 _ACC_0	=	0x00e0
                    00E1    449 Ftest_random$ACC_1$0$0 == 0x00e1
                    00E1    450 _ACC_1	=	0x00e1
                    00E2    451 Ftest_random$ACC_2$0$0 == 0x00e2
                    00E2    452 _ACC_2	=	0x00e2
                    00E3    453 Ftest_random$ACC_3$0$0 == 0x00e3
                    00E3    454 _ACC_3	=	0x00e3
                    00E4    455 Ftest_random$ACC_4$0$0 == 0x00e4
                    00E4    456 _ACC_4	=	0x00e4
                    00E5    457 Ftest_random$ACC_5$0$0 == 0x00e5
                    00E5    458 _ACC_5	=	0x00e5
                    00E6    459 Ftest_random$ACC_6$0$0 == 0x00e6
                    00E6    460 _ACC_6	=	0x00e6
                    00E7    461 Ftest_random$ACC_7$0$0 == 0x00e7
                    00E7    462 _ACC_7	=	0x00e7
                    00E8    463 Ftest_random$P2IF$0$0 == 0x00e8
                    00E8    464 _P2IF	=	0x00e8
                    00E9    465 Ftest_random$UTX0IF$0$0 == 0x00e9
                    00E9    466 _UTX0IF	=	0x00e9
                    00EA    467 Ftest_random$UTX1IF$0$0 == 0x00ea
                    00EA    468 _UTX1IF	=	0x00ea
                    00EB    469 Ftest_random$P1IF$0$0 == 0x00eb
                    00EB    470 _P1IF	=	0x00eb
                    00EC    471 Ftest_random$WDTIF$0$0 == 0x00ec
                    00EC    472 _WDTIF	=	0x00ec
                    00ED    473 Ftest_random$_IRCON25$0$0 == 0x00ed
                    00ED    474 __IRCON25	=	0x00ed
                    00EE    475 Ftest_random$_IRCON26$0$0 == 0x00ee
                    00EE    476 __IRCON26	=	0x00ee
                    00EF    477 Ftest_random$_IRCON27$0$0 == 0x00ef
                    00EF    478 __IRCON27	=	0x00ef
                    00F0    479 Ftest_random$B_0$0$0 == 0x00f0
                    00F0    480 _B_0	=	0x00f0
                    00F1    481 Ftest_random$B_1$0$0 == 0x00f1
                    00F1    482 _B_1	=	0x00f1
                    00F2    483 Ftest_random$B_2$0$0 == 0x00f2
                    00F2    484 _B_2	=	0x00f2
                    00F3    485 Ftest_random$B_3$0$0 == 0x00f3
                    00F3    486 _B_3	=	0x00f3
                    00F4    487 Ftest_random$B_4$0$0 == 0x00f4
                    00F4    488 _B_4	=	0x00f4
                    00F5    489 Ftest_random$B_5$0$0 == 0x00f5
                    00F5    490 _B_5	=	0x00f5
                    00F6    491 Ftest_random$B_6$0$0 == 0x00f6
                    00F6    492 _B_6	=	0x00f6
                    00F7    493 Ftest_random$B_7$0$0 == 0x00f7
                    00F7    494 _B_7	=	0x00f7
                    00F8    495 Ftest_random$U1ACTIVE$0$0 == 0x00f8
                    00F8    496 _U1ACTIVE	=	0x00f8
                    00F9    497 Ftest_random$U1TX_BYTE$0$0 == 0x00f9
                    00F9    498 _U1TX_BYTE	=	0x00f9
                    00FA    499 Ftest_random$U1RX_BYTE$0$0 == 0x00fa
                    00FA    500 _U1RX_BYTE	=	0x00fa
                    00FB    501 Ftest_random$U1ERR$0$0 == 0x00fb
                    00FB    502 _U1ERR	=	0x00fb
                    00FC    503 Ftest_random$U1FE$0$0 == 0x00fc
                    00FC    504 _U1FE	=	0x00fc
                    00FD    505 Ftest_random$U1SLAVE$0$0 == 0x00fd
                    00FD    506 _U1SLAVE	=	0x00fd
                    00FE    507 Ftest_random$U1RE$0$0 == 0x00fe
                    00FE    508 _U1RE	=	0x00fe
                    00FF    509 Ftest_random$U1MODE$0$0 == 0x00ff
                    00FF    510 _U1MODE	=	0x00ff
                            511 ;--------------------------------------------------------
                            512 ; overlayable register banks
                            513 ;--------------------------------------------------------
                            514 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     515 	.ds 8
                            516 ;--------------------------------------------------------
                            517 ; internal ram data
                            518 ;--------------------------------------------------------
                            519 	.area DSEG    (DATA)
                            520 ;--------------------------------------------------------
                            521 ; overlayable items in internal ram 
                            522 ;--------------------------------------------------------
                            523 	.area OSEG    (OVR,DATA)
                            524 ;--------------------------------------------------------
                            525 ; Stack segment in internal ram 
                            526 ;--------------------------------------------------------
                            527 	.area	SSEG	(DATA)
   0022                     528 __start__stack:
   0022                     529 	.ds	1
                            530 
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
                    0000    544 G$blinkYellow$0$0==.
   0000                     545 _blinkYellow::
   0000                     546 	.ds 1
                            547 ;--------------------------------------------------------
                            548 ; paged external ram data
                            549 ;--------------------------------------------------------
                            550 	.area PSEG    (PAG,XDATA)
                    0000    551 G$nextToggle$0$0==.
   F000                     552 _nextToggle::
   F000                     553 	.ds 4
                    0004    554 Ltest_random.updateLeds$time$2$2==.
   F004                     555 _updateLeds_time_2_2:
   F004                     556 	.ds 4
                            557 ;--------------------------------------------------------
                            558 ; external ram data
                            559 ;--------------------------------------------------------
                            560 	.area XSEG    (XDATA)
                    DF00    561 Ftest_random$SYNC1$0$0 == 0xdf00
                    DF00    562 _SYNC1	=	0xdf00
                    DF01    563 Ftest_random$SYNC0$0$0 == 0xdf01
                    DF01    564 _SYNC0	=	0xdf01
                    DF02    565 Ftest_random$PKTLEN$0$0 == 0xdf02
                    DF02    566 _PKTLEN	=	0xdf02
                    DF03    567 Ftest_random$PKTCTRL1$0$0 == 0xdf03
                    DF03    568 _PKTCTRL1	=	0xdf03
                    DF04    569 Ftest_random$PKTCTRL0$0$0 == 0xdf04
                    DF04    570 _PKTCTRL0	=	0xdf04
                    DF05    571 Ftest_random$ADDR$0$0 == 0xdf05
                    DF05    572 _ADDR	=	0xdf05
                    DF06    573 Ftest_random$CHANNR$0$0 == 0xdf06
                    DF06    574 _CHANNR	=	0xdf06
                    DF07    575 Ftest_random$FSCTRL1$0$0 == 0xdf07
                    DF07    576 _FSCTRL1	=	0xdf07
                    DF08    577 Ftest_random$FSCTRL0$0$0 == 0xdf08
                    DF08    578 _FSCTRL0	=	0xdf08
                    DF09    579 Ftest_random$FREQ2$0$0 == 0xdf09
                    DF09    580 _FREQ2	=	0xdf09
                    DF0A    581 Ftest_random$FREQ1$0$0 == 0xdf0a
                    DF0A    582 _FREQ1	=	0xdf0a
                    DF0B    583 Ftest_random$FREQ0$0$0 == 0xdf0b
                    DF0B    584 _FREQ0	=	0xdf0b
                    DF0C    585 Ftest_random$MDMCFG4$0$0 == 0xdf0c
                    DF0C    586 _MDMCFG4	=	0xdf0c
                    DF0D    587 Ftest_random$MDMCFG3$0$0 == 0xdf0d
                    DF0D    588 _MDMCFG3	=	0xdf0d
                    DF0E    589 Ftest_random$MDMCFG2$0$0 == 0xdf0e
                    DF0E    590 _MDMCFG2	=	0xdf0e
                    DF0F    591 Ftest_random$MDMCFG1$0$0 == 0xdf0f
                    DF0F    592 _MDMCFG1	=	0xdf0f
                    DF10    593 Ftest_random$MDMCFG0$0$0 == 0xdf10
                    DF10    594 _MDMCFG0	=	0xdf10
                    DF11    595 Ftest_random$DEVIATN$0$0 == 0xdf11
                    DF11    596 _DEVIATN	=	0xdf11
                    DF12    597 Ftest_random$MCSM2$0$0 == 0xdf12
                    DF12    598 _MCSM2	=	0xdf12
                    DF13    599 Ftest_random$MCSM1$0$0 == 0xdf13
                    DF13    600 _MCSM1	=	0xdf13
                    DF14    601 Ftest_random$MCSM0$0$0 == 0xdf14
                    DF14    602 _MCSM0	=	0xdf14
                    DF15    603 Ftest_random$FOCCFG$0$0 == 0xdf15
                    DF15    604 _FOCCFG	=	0xdf15
                    DF16    605 Ftest_random$BSCFG$0$0 == 0xdf16
                    DF16    606 _BSCFG	=	0xdf16
                    DF17    607 Ftest_random$AGCCTRL2$0$0 == 0xdf17
                    DF17    608 _AGCCTRL2	=	0xdf17
                    DF18    609 Ftest_random$AGCCTRL1$0$0 == 0xdf18
                    DF18    610 _AGCCTRL1	=	0xdf18
                    DF19    611 Ftest_random$AGCCTRL0$0$0 == 0xdf19
                    DF19    612 _AGCCTRL0	=	0xdf19
                    DF1A    613 Ftest_random$FREND1$0$0 == 0xdf1a
                    DF1A    614 _FREND1	=	0xdf1a
                    DF1B    615 Ftest_random$FREND0$0$0 == 0xdf1b
                    DF1B    616 _FREND0	=	0xdf1b
                    DF1C    617 Ftest_random$FSCAL3$0$0 == 0xdf1c
                    DF1C    618 _FSCAL3	=	0xdf1c
                    DF1D    619 Ftest_random$FSCAL2$0$0 == 0xdf1d
                    DF1D    620 _FSCAL2	=	0xdf1d
                    DF1E    621 Ftest_random$FSCAL1$0$0 == 0xdf1e
                    DF1E    622 _FSCAL1	=	0xdf1e
                    DF1F    623 Ftest_random$FSCAL0$0$0 == 0xdf1f
                    DF1F    624 _FSCAL0	=	0xdf1f
                    DF23    625 Ftest_random$TEST2$0$0 == 0xdf23
                    DF23    626 _TEST2	=	0xdf23
                    DF24    627 Ftest_random$TEST1$0$0 == 0xdf24
                    DF24    628 _TEST1	=	0xdf24
                    DF25    629 Ftest_random$TEST0$0$0 == 0xdf25
                    DF25    630 _TEST0	=	0xdf25
                    DF2E    631 Ftest_random$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    632 _PA_TABLE0	=	0xdf2e
                    DF2F    633 Ftest_random$IOCFG2$0$0 == 0xdf2f
                    DF2F    634 _IOCFG2	=	0xdf2f
                    DF30    635 Ftest_random$IOCFG1$0$0 == 0xdf30
                    DF30    636 _IOCFG1	=	0xdf30
                    DF31    637 Ftest_random$IOCFG0$0$0 == 0xdf31
                    DF31    638 _IOCFG0	=	0xdf31
                    DF36    639 Ftest_random$PARTNUM$0$0 == 0xdf36
                    DF36    640 _PARTNUM	=	0xdf36
                    DF37    641 Ftest_random$VERSION$0$0 == 0xdf37
                    DF37    642 _VERSION	=	0xdf37
                    DF38    643 Ftest_random$FREQEST$0$0 == 0xdf38
                    DF38    644 _FREQEST	=	0xdf38
                    DF39    645 Ftest_random$LQI$0$0 == 0xdf39
                    DF39    646 _LQI	=	0xdf39
                    DF3A    647 Ftest_random$RSSI$0$0 == 0xdf3a
                    DF3A    648 _RSSI	=	0xdf3a
                    DF3B    649 Ftest_random$MARCSTATE$0$0 == 0xdf3b
                    DF3B    650 _MARCSTATE	=	0xdf3b
                    DF3C    651 Ftest_random$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    652 _PKTSTATUS	=	0xdf3c
                    DF3D    653 Ftest_random$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    654 _VCO_VC_DAC	=	0xdf3d
                    DF40    655 Ftest_random$I2SCFG0$0$0 == 0xdf40
                    DF40    656 _I2SCFG0	=	0xdf40
                    DF41    657 Ftest_random$I2SCFG1$0$0 == 0xdf41
                    DF41    658 _I2SCFG1	=	0xdf41
                    DF42    659 Ftest_random$I2SDATL$0$0 == 0xdf42
                    DF42    660 _I2SDATL	=	0xdf42
                    DF43    661 Ftest_random$I2SDATH$0$0 == 0xdf43
                    DF43    662 _I2SDATH	=	0xdf43
                    DF44    663 Ftest_random$I2SWCNT$0$0 == 0xdf44
                    DF44    664 _I2SWCNT	=	0xdf44
                    DF45    665 Ftest_random$I2SSTAT$0$0 == 0xdf45
                    DF45    666 _I2SSTAT	=	0xdf45
                    DF46    667 Ftest_random$I2SCLKF0$0$0 == 0xdf46
                    DF46    668 _I2SCLKF0	=	0xdf46
                    DF47    669 Ftest_random$I2SCLKF1$0$0 == 0xdf47
                    DF47    670 _I2SCLKF1	=	0xdf47
                    DF48    671 Ftest_random$I2SCLKF2$0$0 == 0xdf48
                    DF48    672 _I2SCLKF2	=	0xdf48
                    DE00    673 Ftest_random$USBADDR$0$0 == 0xde00
                    DE00    674 _USBADDR	=	0xde00
                    DE01    675 Ftest_random$USBPOW$0$0 == 0xde01
                    DE01    676 _USBPOW	=	0xde01
                    DE02    677 Ftest_random$USBIIF$0$0 == 0xde02
                    DE02    678 _USBIIF	=	0xde02
                    DE04    679 Ftest_random$USBOIF$0$0 == 0xde04
                    DE04    680 _USBOIF	=	0xde04
                    DE06    681 Ftest_random$USBCIF$0$0 == 0xde06
                    DE06    682 _USBCIF	=	0xde06
                    DE07    683 Ftest_random$USBIIE$0$0 == 0xde07
                    DE07    684 _USBIIE	=	0xde07
                    DE09    685 Ftest_random$USBOIE$0$0 == 0xde09
                    DE09    686 _USBOIE	=	0xde09
                    DE0B    687 Ftest_random$USBCIE$0$0 == 0xde0b
                    DE0B    688 _USBCIE	=	0xde0b
                    DE0C    689 Ftest_random$USBFRML$0$0 == 0xde0c
                    DE0C    690 _USBFRML	=	0xde0c
                    DE0D    691 Ftest_random$USBFRMH$0$0 == 0xde0d
                    DE0D    692 _USBFRMH	=	0xde0d
                    DE0E    693 Ftest_random$USBINDEX$0$0 == 0xde0e
                    DE0E    694 _USBINDEX	=	0xde0e
                    DE10    695 Ftest_random$USBMAXI$0$0 == 0xde10
                    DE10    696 _USBMAXI	=	0xde10
                    DE11    697 Ftest_random$USBCSIL$0$0 == 0xde11
                    DE11    698 _USBCSIL	=	0xde11
                    DE12    699 Ftest_random$USBCSIH$0$0 == 0xde12
                    DE12    700 _USBCSIH	=	0xde12
                    DE13    701 Ftest_random$USBMAXO$0$0 == 0xde13
                    DE13    702 _USBMAXO	=	0xde13
                    DE14    703 Ftest_random$USBCSOL$0$0 == 0xde14
                    DE14    704 _USBCSOL	=	0xde14
                    DE15    705 Ftest_random$USBCSOH$0$0 == 0xde15
                    DE15    706 _USBCSOH	=	0xde15
                    DE16    707 Ftest_random$USBCNTL$0$0 == 0xde16
                    DE16    708 _USBCNTL	=	0xde16
                    DE17    709 Ftest_random$USBCNTH$0$0 == 0xde17
                    DE17    710 _USBCNTH	=	0xde17
                    DE20    711 Ftest_random$USBF0$0$0 == 0xde20
                    DE20    712 _USBF0	=	0xde20
                    DE22    713 Ftest_random$USBF1$0$0 == 0xde22
                    DE22    714 _USBF1	=	0xde22
                    DE24    715 Ftest_random$USBF2$0$0 == 0xde24
                    DE24    716 _USBF2	=	0xde24
                    DE26    717 Ftest_random$USBF3$0$0 == 0xde26
                    DE26    718 _USBF3	=	0xde26
                    DE28    719 Ftest_random$USBF4$0$0 == 0xde28
                    DE28    720 _USBF4	=	0xde28
                    DE2A    721 Ftest_random$USBF5$0$0 == 0xde2a
                    DE2A    722 _USBF5	=	0xde2a
                    0000    723 Ltest_random.receiveCommands$response$2$2==.
   F025                     724 _receiveCommands_response_2_2:
   F025                     725 	.ds 64
                            726 ;--------------------------------------------------------
                            727 ; absolute external ram data
                            728 ;--------------------------------------------------------
                            729 	.area XABS    (ABS,XDATA)
                            730 ;--------------------------------------------------------
                            731 ; external initialized ram data
                            732 ;--------------------------------------------------------
                            733 	.area XISEG   (XDATA)
                            734 	.area HOME    (CODE)
                            735 	.area GSINIT0 (CODE)
                            736 	.area GSINIT1 (CODE)
                            737 	.area GSINIT2 (CODE)
                            738 	.area GSINIT3 (CODE)
                            739 	.area GSINIT4 (CODE)
                            740 	.area GSINIT5 (CODE)
                            741 	.area GSINIT  (CODE)
                            742 	.area GSFINAL (CODE)
                            743 	.area CSEG    (CODE)
                            744 ;--------------------------------------------------------
                            745 ; interrupt vector 
                            746 ;--------------------------------------------------------
                            747 	.area HOME    (CODE)
   0400                     748 __interrupt_vect:
   0400 02 04 6D            749 	ljmp	__sdcc_gsinit_startup
   0403 32                  750 	reti
   0404                     751 	.ds	7
   040B 32                  752 	reti
   040C                     753 	.ds	7
   0413 32                  754 	reti
   0414                     755 	.ds	7
   041B 32                  756 	reti
   041C                     757 	.ds	7
   0423 32                  758 	reti
   0424                     759 	.ds	7
   042B 32                  760 	reti
   042C                     761 	.ds	7
   0433 32                  762 	reti
   0434                     763 	.ds	7
   043B 32                  764 	reti
   043C                     765 	.ds	7
   0443 32                  766 	reti
   0444                     767 	.ds	7
   044B 32                  768 	reti
   044C                     769 	.ds	7
   0453 32                  770 	reti
   0454                     771 	.ds	7
   045B 32                  772 	reti
   045C                     773 	.ds	7
   0463 02 13 99            774 	ljmp	_ISR_T4
                            775 ;--------------------------------------------------------
                            776 ; global & static initialisations
                            777 ;--------------------------------------------------------
                            778 	.area HOME    (CODE)
                            779 	.area GSINIT  (CODE)
                            780 	.area GSFINAL (CODE)
                            781 	.area GSINIT  (CODE)
                            782 	.globl __sdcc_gsinit_startup
                            783 	.globl __sdcc_program_startup
                            784 	.globl __start__stack
                            785 	.globl __mcs51_genXINIT
                            786 	.globl __mcs51_genXRAMCLEAR
                            787 	.globl __mcs51_genRAMCLEAR
                    0000    788 	G$main$0$0 ==.
                    0000    789 	C$test_random.c$29$1$1 ==.
                            790 ;	apps/test_random/test_random.c:29: BIT blinkYellow = 1;
   04C6 D2 00               791 	setb	_blinkYellow
                    0002    792 	G$main$0$0 ==.
                    0002    793 	C$test_random.c$27$1$1 ==.
                            794 ;	apps/test_random/test_random.c:27: uint32 nextToggle = 0;
   04C8 78 00               795 	mov	r0,#_nextToggle
   04CA E4                  796 	clr	a
   04CB F2                  797 	movx	@r0,a
   04CC 08                  798 	inc	r0
   04CD F2                  799 	movx	@r0,a
   04CE 08                  800 	inc	r0
   04CF F2                  801 	movx	@r0,a
   04D0 08                  802 	inc	r0
   04D1 F2                  803 	movx	@r0,a
                            804 	.area GSFINAL (CODE)
   04FC 02 04 66            805 	ljmp	__sdcc_program_startup
                            806 ;--------------------------------------------------------
                            807 ; Home
                            808 ;--------------------------------------------------------
                            809 	.area HOME    (CODE)
                            810 	.area HOME    (CODE)
   0466                     811 __sdcc_program_startup:
   0466 12 08 EE            812 	lcall	_main
                            813 ;	return from main will lock up
   0469 80 FE               814 	sjmp .
                            815 ;--------------------------------------------------------
                            816 ; code
                            817 ;--------------------------------------------------------
                            818 	.area CSEG    (CODE)
                            819 ;------------------------------------------------------------
                            820 ;Allocation info for local variables in function 'updateLeds'
                            821 ;------------------------------------------------------------
                    0000    822 	G$updateLeds$0$0 ==.
                    0000    823 	C$test_random.c$31$0$0 ==.
                            824 ;	apps/test_random/test_random.c:31: void updateLeds()
                            825 ;	-----------------------------------------
                            826 ;	 function updateLeds
                            827 ;	-----------------------------------------
   04FF                     828 _updateLeds:
                    0007    829 	ar7 = 0x07
                    0006    830 	ar6 = 0x06
                    0005    831 	ar5 = 0x05
                    0004    832 	ar4 = 0x04
                    0003    833 	ar3 = 0x03
                    0002    834 	ar2 = 0x02
                    0001    835 	ar1 = 0x01
                    0000    836 	ar0 = 0x00
                    0000    837 	C$test_random.c$33$1$1 ==.
                            838 ;	apps/test_random/test_random.c:33: usbShowStatusWithGreenLed();
   04FF 12 14 25            839 	lcall	_usbShowStatusWithGreenLed
                    0003    840 	C$test_random.c$37$1$1 ==.
                            841 ;	apps/test_random/test_random.c:37: if (blinkYellow)
   0502 30 00 69            842 	jnb	_blinkYellow,00104$
                    0006    843 	C$test_random.c$39$2$2 ==.
                            844 ;	apps/test_random/test_random.c:39: uint32 time = getMs();
   0505 12 13 BE            845 	lcall	_getMs
   0508 78 04               846 	mov	r0,#_updateLeds_time_2_2
   050A C0 E0               847 	push	acc
   050C E5 82               848 	mov	a,dpl
   050E F2                  849 	movx	@r0,a
   050F 08                  850 	inc	r0
   0510 E5 83               851 	mov	a,dph
   0512 F2                  852 	movx	@r0,a
   0513 08                  853 	inc	r0
   0514 E5 F0               854 	mov	a,b
   0516 F2                  855 	movx	@r0,a
   0517 D0 E0               856 	pop	acc
   0519 08                  857 	inc	r0
   051A F2                  858 	movx	@r0,a
                    001C    859 	C$test_random.c$40$2$2 ==.
                            860 ;	apps/test_random/test_random.c:40: if (time >= nextToggle)
   051B 78 04               861 	mov	r0,#_updateLeds_time_2_2
   051D 79 00               862 	mov	r1,#_nextToggle
   051F C3                  863 	clr	c
   0520 E3                  864 	movx	a,@r1
   0521 F5 F0               865 	mov	b,a
   0523 E2                  866 	movx	a,@r0
   0524 95 F0               867 	subb	a,b
   0526 09                  868 	inc	r1
   0527 E3                  869 	movx	a,@r1
   0528 F5 F0               870 	mov	b,a
   052A 08                  871 	inc	r0
   052B E2                  872 	movx	a,@r0
   052C 95 F0               873 	subb	a,b
   052E 09                  874 	inc	r1
   052F E3                  875 	movx	a,@r1
   0530 F5 F0               876 	mov	b,a
   0532 08                  877 	inc	r0
   0533 E2                  878 	movx	a,@r0
   0534 95 F0               879 	subb	a,b
   0536 09                  880 	inc	r1
   0537 E3                  881 	movx	a,@r1
   0538 F5 F0               882 	mov	b,a
   053A 08                  883 	inc	r0
   053B E2                  884 	movx	a,@r0
   053C 95 F0               885 	subb	a,b
   053E 40 31               886 	jc	00105$
                    0041    887 	C$test_random.c$42$4$4 ==.
                            888 ;	apps/test_random/test_random.c:42: LED_YELLOW_TOGGLE();
   0540 63 FF 04            889 	xrl	_P2DIR,#0x04
                    0044    890 	C$test_random.c$43$3$3 ==.
                            891 ;	apps/test_random/test_random.c:43: nextToggle = time + randomNumber();
   0543 12 09 06            892 	lcall	_randomNumber
   0546 AA 82               893 	mov	r2,dpl
   0548 7B 00               894 	mov	r3,#0x00
   054A 7E 00               895 	mov	r6,#0x00
   054C 7F 00               896 	mov	r7,#0x00
   054E 78 04               897 	mov	r0,#_updateLeds_time_2_2
   0550 E2                  898 	movx	a,@r0
   0551 2A                  899 	add	a,r2
   0552 FA                  900 	mov	r2,a
   0553 08                  901 	inc	r0
   0554 E2                  902 	movx	a,@r0
   0555 3B                  903 	addc	a,r3
   0556 FB                  904 	mov	r3,a
   0557 08                  905 	inc	r0
   0558 E2                  906 	movx	a,@r0
   0559 3E                  907 	addc	a,r6
   055A FE                  908 	mov	r6,a
   055B 08                  909 	inc	r0
   055C E2                  910 	movx	a,@r0
   055D 3F                  911 	addc	a,r7
   055E FF                  912 	mov	r7,a
   055F 78 00               913 	mov	r0,#_nextToggle
   0561 EA                  914 	mov	a,r2
   0562 F2                  915 	movx	@r0,a
   0563 08                  916 	inc	r0
   0564 EB                  917 	mov	a,r3
   0565 F2                  918 	movx	@r0,a
   0566 08                  919 	inc	r0
   0567 EE                  920 	mov	a,r6
   0568 F2                  921 	movx	@r0,a
   0569 08                  922 	inc	r0
   056A EF                  923 	mov	a,r7
   056B F2                  924 	movx	@r0,a
   056C 80 03               925 	sjmp	00105$
   056E                     926 00104$:
                    006F    927 	C$test_random.c$48$3$6 ==.
                            928 ;	apps/test_random/test_random.c:48: LED_YELLOW(1);
   056E 43 FF 04            929 	orl	_P2DIR,#0x04
   0571                     930 00105$:
                    0072    931 	C$test_random.c$51$2$7 ==.
                            932 ;	apps/test_random/test_random.c:51: LED_RED(0);
   0571 AF FF               933 	mov	r7,_P2DIR
   0573 53 07 FD            934 	anl	ar7,#0xFD
   0576 8F FF               935 	mov	_P2DIR,r7
                    0079    936 	C$test_random.c$52$2$7 ==.
                    0079    937 	XG$updateLeds$0$0 ==.
   0578 22                  938 	ret
                            939 ;------------------------------------------------------------
                            940 ;Allocation info for local variables in function 'nibbleToAscii'
                            941 ;------------------------------------------------------------
                    007A    942 	G$nibbleToAscii$0$0 ==.
                    007A    943 	C$test_random.c$54$2$7 ==.
                            944 ;	apps/test_random/test_random.c:54: uint8 nibbleToAscii(uint8 nibble)
                            945 ;	-----------------------------------------
                            946 ;	 function nibbleToAscii
                            947 ;	-----------------------------------------
   0579                     948 _nibbleToAscii:
                    007A    949 	C$test_random.c$56$1$1 ==.
                            950 ;	apps/test_random/test_random.c:56: nibble &= 0xF;
                    007A    951 	C$test_random.c$57$1$1 ==.
                            952 ;	apps/test_random/test_random.c:57: if (nibble <= 0x9){ return '0' + nibble; }
   0579 E5 82               953 	mov	a,dpl
   057B 54 0F               954 	anl	a,#0x0F
   057D FF                  955 	mov	r7,a
   057E 24 F6               956 	add	a,#0xff - 0x09
   0580 40 0A               957 	jc	00102$
   0582 8F 06               958 	mov	ar6,r7
   0584 74 30               959 	mov	a,#0x30
   0586 2E                  960 	add	a,r6
   0587 FE                  961 	mov	r6,a
   0588 F5 82               962 	mov	dpl,a
   058A 80 05               963 	sjmp	00104$
   058C                     964 00102$:
                    008D    965 	C$test_random.c$58$2$3 ==.
                            966 ;	apps/test_random/test_random.c:58: else{ return 'A' + (nibble - 0xA); }
   058C 74 37               967 	mov	a,#0x37
   058E 2F                  968 	add	a,r7
                    0090    969 	C$test_random.c$59$1$1 ==.
                    0090    970 	XG$nibbleToAscii$0$0 ==.
   058F F5 82               971 	mov	dpl,a
   0591                     972 00104$:
   0591 22                  973 	ret
                            974 ;------------------------------------------------------------
                            975 ;Allocation info for local variables in function 'receiveCommands'
                            976 ;------------------------------------------------------------
                            977 ;response                  Allocated with name '_receiveCommands_response_2_2'
                            978 ;------------------------------------------------------------
                    0093    979 	G$receiveCommands$0$0 ==.
                    0093    980 	C$test_random.c$61$1$1 ==.
                            981 ;	apps/test_random/test_random.c:61: void receiveCommands()
                            982 ;	-----------------------------------------
                            983 ;	 function receiveCommands
                            984 ;	-----------------------------------------
   0592                     985 _receiveCommands:
                    0093    986 	C$test_random.c$63$1$1 ==.
                            987 ;	apps/test_random/test_random.c:63: if (usbComRxAvailable() && usbComTxAvailable() >= 64)
   0592 12 0A 65            988 	lcall	_usbComRxAvailable
   0595 E5 82               989 	mov	a,dpl
   0597 70 03               990 	jnz	00179$
   0599 02 08 ED            991 	ljmp	00117$
   059C                     992 00179$:
   059C 12 0B 9B            993 	lcall	_usbComTxAvailable
   059F AF 82               994 	mov	r7,dpl
   05A1 BF 40 00            995 	cjne	r7,#0x40,00180$
   05A4                     996 00180$:
   05A4 50 03               997 	jnc	00181$
   05A6 02 08 ED            998 	ljmp	00117$
   05A9                     999 00181$:
                    00AA   1000 	C$test_random.c$68$2$2 ==.
                           1001 ;	apps/test_random/test_random.c:68: byte = usbComRxReceiveByte();
   05A9 12 0A 8F           1002 	lcall	_usbComRxReceiveByte
   05AC AF 82              1003 	mov	r7,dpl
                    00AF   1004 	C$test_random.c$71$2$2 ==.
                           1005 ;	apps/test_random/test_random.c:71: response[0] = byte;
   05AE 90 F0 25           1006 	mov	dptr,#_receiveCommands_response_2_2
   05B1 EF                 1007 	mov	a,r7
   05B2 F0                 1008 	movx	@dptr,a
                    00B4   1009 	C$test_random.c$72$2$2 ==.
                           1010 ;	apps/test_random/test_random.c:72: responseLength = 1;
   05B3 7E 01              1011 	mov	r6,#0x01
                    00B6   1012 	C$test_random.c$76$2$2 ==.
                           1013 ;	apps/test_random/test_random.c:76: blinkYellow = 0;
   05B5 C2 00              1014 	clr	_blinkYellow
                    00B8   1015 	C$test_random.c$77$2$2 ==.
                           1016 ;	apps/test_random/test_random.c:77: switch(byte)
   05B7 BF 30 02           1017 	cjne	r7,#0x30,00182$
   05BA 80 40              1018 	sjmp	00104$
   05BC                    1019 00182$:
   05BC BF 31 02           1020 	cjne	r7,#0x31,00183$
   05BF 80 4C              1021 	sjmp	00105$
   05C1                    1022 00183$:
   05C1 BF 38 02           1023 	cjne	r7,#0x38,00184$
   05C4 80 59              1024 	sjmp	00106$
   05C6                    1025 00184$:
   05C6 BF 59 02           1026 	cjne	r7,#0x59,00185$
   05C9 80 18              1027 	sjmp	00101$
   05CB                    1028 00185$:
   05CB BF 61 02           1029 	cjne	r7,#0x61,00186$
   05CE 80 22              1030 	sjmp	00103$
   05D0                    1031 00186$:
   05D0 BF 72 02           1032 	cjne	r7,#0x72,00187$
   05D3 80 5C              1033 	sjmp	00107$
   05D5                    1034 00187$:
   05D5 BF 73 02           1035 	cjne	r7,#0x73,00188$
   05D8 80 0E              1036 	sjmp	00102$
   05DA                    1037 00188$:
   05DA BF 74 03           1038 	cjne	r7,#0x74,00189$
   05DD 02 07 F3           1039 	ljmp	00111$
   05E0                    1040 00189$:
   05E0 02 08 DD           1041 	ljmp	00112$
                    00E4   1042 	C$test_random.c$79$3$3 ==.
                           1043 ;	apps/test_random/test_random.c:79: case 'Y': blinkYellow = 1; break;
   05E3                    1044 00101$:
   05E3 D2 00              1045 	setb	_blinkYellow
   05E5 02 08 E3           1046 	ljmp	00113$
                    00E9   1047 	C$test_random.c$80$3$3 ==.
                           1048 ;	apps/test_random/test_random.c:80: case 's': randomSeedFromSerialNumber(); break;
   05E8                    1049 00102$:
   05E8 C0 06              1050 	push	ar6
   05EA 12 14 D7           1051 	lcall	_randomSeedFromSerialNumber
   05ED D0 06              1052 	pop	ar6
   05EF 02 08 E3           1053 	ljmp	00113$
                    00F3   1054 	C$test_random.c$81$3$3 ==.
                           1055 ;	apps/test_random/test_random.c:81: case 'a': randomSeedFromAdc(); break;
   05F2                    1056 00103$:
   05F2 C0 06              1057 	push	ar6
   05F4 12 14 BF           1058 	lcall	_randomSeedFromAdc
   05F7 D0 06              1059 	pop	ar6
   05F9 02 08 E3           1060 	ljmp	00113$
                    00FD   1061 	C$test_random.c$82$3$3 ==.
                           1062 ;	apps/test_random/test_random.c:82: case '0': randomSeed(0,0); break;
   05FC                    1063 00104$:
   05FC 78 08              1064 	mov	r0,#_randomSeed_PARM_2
   05FE E4                 1065 	clr	a
   05FF F2                 1066 	movx	@r0,a
   0600 75 82 00           1067 	mov	dpl,#0x00
   0603 C0 06              1068 	push	ar6
   0605 12 09 1A           1069 	lcall	_randomSeed
   0608 D0 06              1070 	pop	ar6
   060A 02 08 E3           1071 	ljmp	00113$
                    010E   1072 	C$test_random.c$83$3$3 ==.
                           1073 ;	apps/test_random/test_random.c:83: case '1': randomSeed(0xFF, 0xFF); break;
   060D                    1074 00105$:
   060D 78 08              1075 	mov	r0,#_randomSeed_PARM_2
   060F 74 FF              1076 	mov	a,#0xFF
   0611 F2                 1077 	movx	@r0,a
   0612 75 82 FF           1078 	mov	dpl,#0xFF
   0615 C0 06              1079 	push	ar6
   0617 12 09 1A           1080 	lcall	_randomSeed
   061A D0 06              1081 	pop	ar6
   061C 02 08 E3           1082 	ljmp	00113$
                    0120   1083 	C$test_random.c$84$3$3 ==.
                           1084 ;	apps/test_random/test_random.c:84: case '8': randomSeed(0x80, 0x03); break;
   061F                    1085 00106$:
   061F 78 08              1086 	mov	r0,#_randomSeed_PARM_2
   0621 74 03              1087 	mov	a,#0x03
   0623 F2                 1088 	movx	@r0,a
   0624 75 82 80           1089 	mov	dpl,#0x80
   0627 C0 06              1090 	push	ar6
   0629 12 09 1A           1091 	lcall	_randomSeed
   062C D0 06              1092 	pop	ar6
   062E 02 08 E3           1093 	ljmp	00113$
                    0132   1094 	C$test_random.c$85$3$3 ==.
                           1095 ;	apps/test_random/test_random.c:85: case 'r':
   0631                    1096 00107$:
                    0132   1097 	C$test_random.c$86$3$3 ==.
                           1098 ;	apps/test_random/test_random.c:86: rand = randomNumber();
   0631 12 09 06           1099 	lcall	_randomNumber
   0634 AF 82              1100 	mov	r7,dpl
                    0137   1101 	C$test_random.c$89$3$3 ==.
                           1102 ;	apps/test_random/test_random.c:89: while(ADCCON1 & 0x0C);
   0636                    1103 00108$:
   0636 E5 B4              1104 	mov	a,_ADCCON1
   0638 54 0C              1105 	anl	a,#0x0C
   063A 60 02              1106 	jz	00191$
   063C 80 F8              1107 	sjmp	00108$
   063E                    1108 00191$:
                    013F   1109 	C$test_random.c$91$3$3 ==.
                           1110 ;	apps/test_random/test_random.c:91: response[responseLength++] = ',';
   063E 90 F0 26           1111 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0001)
   0641 74 2C              1112 	mov	a,#0x2C
   0643 F0                 1113 	movx	@dptr,a
                    0145   1114 	C$test_random.c$92$3$3 ==.
                           1115 ;	apps/test_random/test_random.c:92: response[responseLength++] = nibbleToAscii(rand >> 4);
   0644 EF                 1116 	mov	a,r7
   0645 C4                 1117 	swap	a
   0646 54 0F              1118 	anl	a,#0x0F
   0648 F5 82              1119 	mov	dpl,a
   064A C0 07              1120 	push	ar7
   064C 12 05 79           1121 	lcall	_nibbleToAscii
   064F AD 82              1122 	mov	r5,dpl
   0651 D0 07              1123 	pop	ar7
   0653 90 F0 27           1124 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0002)
   0656 ED                 1125 	mov	a,r5
   0657 F0                 1126 	movx	@dptr,a
                    0159   1127 	C$test_random.c$93$3$3 ==.
                           1128 ;	apps/test_random/test_random.c:93: response[responseLength++] = nibbleToAscii(rand);
   0658 8F 82              1129 	mov	dpl,r7
   065A C0 07              1130 	push	ar7
   065C 12 05 79           1131 	lcall	_nibbleToAscii
   065F AD 82              1132 	mov	r5,dpl
   0661 D0 07              1133 	pop	ar7
   0663 90 F0 28           1134 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0003)
   0666 ED                 1135 	mov	a,r5
   0667 F0                 1136 	movx	@dptr,a
                    0169   1137 	C$test_random.c$94$3$3 ==.
                           1138 ;	apps/test_random/test_random.c:94: response[responseLength++] = ',';
   0668 90 F0 29           1139 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0004)
   066B 74 2C              1140 	mov	a,#0x2C
   066D F0                 1141 	movx	@dptr,a
                    016F   1142 	C$test_random.c$95$3$3 ==.
                           1143 ;	apps/test_random/test_random.c:95: response[responseLength++] = (rand & 0x80) ? '1' : '0';
   066E EF                 1144 	mov	a,r7
   066F 30 E7 04           1145 	jnb	acc.7,00119$
   0672 7D 31              1146 	mov	r5,#0x31
   0674 80 02              1147 	sjmp	00120$
   0676                    1148 00119$:
   0676 7D 30              1149 	mov	r5,#0x30
   0678                    1150 00120$:
   0678 90 F0 2A           1151 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0005)
   067B ED                 1152 	mov	a,r5
   067C F0                 1153 	movx	@dptr,a
                    017E   1154 	C$test_random.c$96$3$3 ==.
                           1155 ;	apps/test_random/test_random.c:96: response[responseLength++] = (rand & 0x40) ? '1' : '0';
   067D EF                 1156 	mov	a,r7
   067E 30 E6 04           1157 	jnb	acc.6,00121$
   0681 7D 31              1158 	mov	r5,#0x31
   0683 80 02              1159 	sjmp	00122$
   0685                    1160 00121$:
   0685 7D 30              1161 	mov	r5,#0x30
   0687                    1162 00122$:
   0687 90 F0 2B           1163 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0006)
   068A ED                 1164 	mov	a,r5
   068B F0                 1165 	movx	@dptr,a
                    018D   1166 	C$test_random.c$97$3$3 ==.
                           1167 ;	apps/test_random/test_random.c:97: response[responseLength++] = (rand & 0x20) ? '1' : '0';
   068C 7E 08              1168 	mov	r6,#0x08
   068E EF                 1169 	mov	a,r7
   068F 30 E5 04           1170 	jnb	acc.5,00123$
   0692 7D 31              1171 	mov	r5,#0x31
   0694 80 02              1172 	sjmp	00124$
   0696                    1173 00123$:
   0696 7D 30              1174 	mov	r5,#0x30
   0698                    1175 00124$:
   0698 90 F0 2C           1176 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0007)
   069B ED                 1177 	mov	a,r5
   069C F0                 1178 	movx	@dptr,a
                    019E   1179 	C$test_random.c$98$3$3 ==.
                           1180 ;	apps/test_random/test_random.c:98: response[responseLength++] = (rand & 0x10) ? '1' : '0';
   069D 8E 05              1181 	mov	ar5,r6
   069F 0E                 1182 	inc	r6
   06A0 ED                 1183 	mov	a,r5
   06A1 24 25              1184 	add	a,#_receiveCommands_response_2_2
   06A3 FC                 1185 	mov	r4,a
   06A4 E4                 1186 	clr	a
   06A5 34 F0              1187 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   06A7 FD                 1188 	mov	r5,a
   06A8 EF                 1189 	mov	a,r7
   06A9 30 E4 04           1190 	jnb	acc.4,00125$
   06AC 7B 31              1191 	mov	r3,#0x31
   06AE 80 02              1192 	sjmp	00126$
   06B0                    1193 00125$:
   06B0 7B 30              1194 	mov	r3,#0x30
   06B2                    1195 00126$:
   06B2 8C 82              1196 	mov	dpl,r4
   06B4 8D 83              1197 	mov	dph,r5
   06B6 EB                 1198 	mov	a,r3
   06B7 F0                 1199 	movx	@dptr,a
                    01B9   1200 	C$test_random.c$99$3$3 ==.
                           1201 ;	apps/test_random/test_random.c:99: response[responseLength++] = (rand & 0x08) ? '1' : '0';
   06B8 8E 05              1202 	mov	ar5,r6
   06BA 0E                 1203 	inc	r6
   06BB ED                 1204 	mov	a,r5
   06BC 24 25              1205 	add	a,#_receiveCommands_response_2_2
   06BE FC                 1206 	mov	r4,a
   06BF E4                 1207 	clr	a
   06C0 34 F0              1208 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   06C2 FD                 1209 	mov	r5,a
   06C3 EF                 1210 	mov	a,r7
   06C4 30 E3 04           1211 	jnb	acc.3,00127$
   06C7 7B 31              1212 	mov	r3,#0x31
   06C9 80 02              1213 	sjmp	00128$
   06CB                    1214 00127$:
   06CB 7B 30              1215 	mov	r3,#0x30
   06CD                    1216 00128$:
   06CD 8C 82              1217 	mov	dpl,r4
   06CF 8D 83              1218 	mov	dph,r5
   06D1 EB                 1219 	mov	a,r3
   06D2 F0                 1220 	movx	@dptr,a
                    01D4   1221 	C$test_random.c$100$3$3 ==.
                           1222 ;	apps/test_random/test_random.c:100: response[responseLength++] = (rand & 0x04) ? '1' : '0';
   06D3 8E 05              1223 	mov	ar5,r6
   06D5 0E                 1224 	inc	r6
   06D6 ED                 1225 	mov	a,r5
   06D7 24 25              1226 	add	a,#_receiveCommands_response_2_2
   06D9 FC                 1227 	mov	r4,a
   06DA E4                 1228 	clr	a
   06DB 34 F0              1229 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   06DD FD                 1230 	mov	r5,a
   06DE EF                 1231 	mov	a,r7
   06DF 30 E2 04           1232 	jnb	acc.2,00129$
   06E2 7B 31              1233 	mov	r3,#0x31
   06E4 80 02              1234 	sjmp	00130$
   06E6                    1235 00129$:
   06E6 7B 30              1236 	mov	r3,#0x30
   06E8                    1237 00130$:
   06E8 8C 82              1238 	mov	dpl,r4
   06EA 8D 83              1239 	mov	dph,r5
   06EC EB                 1240 	mov	a,r3
   06ED F0                 1241 	movx	@dptr,a
                    01EF   1242 	C$test_random.c$101$3$3 ==.
                           1243 ;	apps/test_random/test_random.c:101: response[responseLength++] = (rand & 0x02) ? '1' : '0';
   06EE 8E 05              1244 	mov	ar5,r6
   06F0 0E                 1245 	inc	r6
   06F1 ED                 1246 	mov	a,r5
   06F2 24 25              1247 	add	a,#_receiveCommands_response_2_2
   06F4 FC                 1248 	mov	r4,a
   06F5 E4                 1249 	clr	a
   06F6 34 F0              1250 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   06F8 FD                 1251 	mov	r5,a
   06F9 EF                 1252 	mov	a,r7
   06FA 30 E1 04           1253 	jnb	acc.1,00131$
   06FD 7B 31              1254 	mov	r3,#0x31
   06FF 80 02              1255 	sjmp	00132$
   0701                    1256 00131$:
   0701 7B 30              1257 	mov	r3,#0x30
   0703                    1258 00132$:
   0703 8C 82              1259 	mov	dpl,r4
   0705 8D 83              1260 	mov	dph,r5
   0707 EB                 1261 	mov	a,r3
   0708 F0                 1262 	movx	@dptr,a
                    020A   1263 	C$test_random.c$102$3$3 ==.
                           1264 ;	apps/test_random/test_random.c:102: response[responseLength++] = (rand & 0x01) ? '1' : '0';
   0709 8E 05              1265 	mov	ar5,r6
   070B 0E                 1266 	inc	r6
   070C ED                 1267 	mov	a,r5
   070D 24 25              1268 	add	a,#_receiveCommands_response_2_2
   070F FC                 1269 	mov	r4,a
   0710 E4                 1270 	clr	a
   0711 34 F0              1271 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   0713 FD                 1272 	mov	r5,a
   0714 EF                 1273 	mov	a,r7
   0715 30 E0 04           1274 	jnb	acc.0,00133$
   0718 7B 31              1275 	mov	r3,#0x31
   071A 80 02              1276 	sjmp	00134$
   071C                    1277 00133$:
   071C 7B 30              1278 	mov	r3,#0x30
   071E                    1279 00134$:
   071E 8C 82              1280 	mov	dpl,r4
   0720 8D 83              1281 	mov	dph,r5
   0722 EB                 1282 	mov	a,r3
   0723 F0                 1283 	movx	@dptr,a
                    0225   1284 	C$test_random.c$103$3$3 ==.
                           1285 ;	apps/test_random/test_random.c:103: response[responseLength++] = ',';
   0724 8E 05              1286 	mov	ar5,r6
   0726 0E                 1287 	inc	r6
   0727 ED                 1288 	mov	a,r5
   0728 24 25              1289 	add	a,#_receiveCommands_response_2_2
   072A F5 82              1290 	mov	dpl,a
   072C E4                 1291 	clr	a
   072D 34 F0              1292 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   072F F5 83              1293 	mov	dph,a
   0731 74 2C              1294 	mov	a,#0x2C
   0733 F0                 1295 	movx	@dptr,a
                    0235   1296 	C$test_random.c$104$3$3 ==.
                           1297 ;	apps/test_random/test_random.c:104: response[responseLength++] = nibbleToAscii(RNDH >> 4);
   0734 8E 05              1298 	mov	ar5,r6
   0736 0E                 1299 	inc	r6
   0737 ED                 1300 	mov	a,r5
   0738 24 25              1301 	add	a,#_receiveCommands_response_2_2
   073A FD                 1302 	mov	r5,a
   073B E4                 1303 	clr	a
   073C 34 F0              1304 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   073E FC                 1305 	mov	r4,a
   073F E5 BD              1306 	mov	a,_RNDH
   0741 C4                 1307 	swap	a
   0742 54 0F              1308 	anl	a,#0x0F
   0744 F5 82              1309 	mov	dpl,a
   0746 C0 06              1310 	push	ar6
   0748 C0 05              1311 	push	ar5
   074A C0 04              1312 	push	ar4
   074C 12 05 79           1313 	lcall	_nibbleToAscii
   074F AB 82              1314 	mov	r3,dpl
   0751 D0 04              1315 	pop	ar4
   0753 D0 05              1316 	pop	ar5
   0755 D0 06              1317 	pop	ar6
   0757 8D 82              1318 	mov	dpl,r5
   0759 8C 83              1319 	mov	dph,r4
   075B EB                 1320 	mov	a,r3
   075C F0                 1321 	movx	@dptr,a
                    025E   1322 	C$test_random.c$105$3$3 ==.
                           1323 ;	apps/test_random/test_random.c:105: response[responseLength++] = nibbleToAscii(RNDH);
   075D 8E 05              1324 	mov	ar5,r6
   075F 0E                 1325 	inc	r6
   0760 ED                 1326 	mov	a,r5
   0761 24 25              1327 	add	a,#_receiveCommands_response_2_2
   0763 FD                 1328 	mov	r5,a
   0764 E4                 1329 	clr	a
   0765 34 F0              1330 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   0767 FC                 1331 	mov	r4,a
   0768 85 BD 82           1332 	mov	dpl,_RNDH
   076B C0 06              1333 	push	ar6
   076D C0 05              1334 	push	ar5
   076F C0 04              1335 	push	ar4
   0771 12 05 79           1336 	lcall	_nibbleToAscii
   0774 AB 82              1337 	mov	r3,dpl
   0776 D0 04              1338 	pop	ar4
   0778 D0 05              1339 	pop	ar5
   077A D0 06              1340 	pop	ar6
   077C 8D 82              1341 	mov	dpl,r5
   077E 8C 83              1342 	mov	dph,r4
   0780 EB                 1343 	mov	a,r3
   0781 F0                 1344 	movx	@dptr,a
                    0283   1345 	C$test_random.c$106$3$3 ==.
                           1346 ;	apps/test_random/test_random.c:106: response[responseLength++] = nibbleToAscii(RNDL >> 4);
   0782 8E 05              1347 	mov	ar5,r6
   0784 0E                 1348 	inc	r6
   0785 ED                 1349 	mov	a,r5
   0786 24 25              1350 	add	a,#_receiveCommands_response_2_2
   0788 FD                 1351 	mov	r5,a
   0789 E4                 1352 	clr	a
   078A 34 F0              1353 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   078C FC                 1354 	mov	r4,a
   078D E5 BC              1355 	mov	a,_RNDL
   078F C4                 1356 	swap	a
   0790 54 0F              1357 	anl	a,#0x0F
   0792 F5 82              1358 	mov	dpl,a
   0794 C0 06              1359 	push	ar6
   0796 C0 05              1360 	push	ar5
   0798 C0 04              1361 	push	ar4
   079A 12 05 79           1362 	lcall	_nibbleToAscii
   079D AB 82              1363 	mov	r3,dpl
   079F D0 04              1364 	pop	ar4
   07A1 D0 05              1365 	pop	ar5
   07A3 D0 06              1366 	pop	ar6
   07A5 8D 82              1367 	mov	dpl,r5
   07A7 8C 83              1368 	mov	dph,r4
   07A9 EB                 1369 	mov	a,r3
   07AA F0                 1370 	movx	@dptr,a
                    02AC   1371 	C$test_random.c$107$3$3 ==.
                           1372 ;	apps/test_random/test_random.c:107: response[responseLength++] = nibbleToAscii(RNDL);
   07AB 8E 05              1373 	mov	ar5,r6
   07AD 0E                 1374 	inc	r6
   07AE ED                 1375 	mov	a,r5
   07AF 24 25              1376 	add	a,#_receiveCommands_response_2_2
   07B1 FD                 1377 	mov	r5,a
   07B2 E4                 1378 	clr	a
   07B3 34 F0              1379 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   07B5 FC                 1380 	mov	r4,a
   07B6 85 BC 82           1381 	mov	dpl,_RNDL
   07B9 C0 06              1382 	push	ar6
   07BB C0 05              1383 	push	ar5
   07BD C0 04              1384 	push	ar4
   07BF 12 05 79           1385 	lcall	_nibbleToAscii
   07C2 AB 82              1386 	mov	r3,dpl
   07C4 D0 04              1387 	pop	ar4
   07C6 D0 05              1388 	pop	ar5
   07C8 D0 06              1389 	pop	ar6
   07CA 8D 82              1390 	mov	dpl,r5
   07CC 8C 83              1391 	mov	dph,r4
   07CE EB                 1392 	mov	a,r3
   07CF F0                 1393 	movx	@dptr,a
                    02D1   1394 	C$test_random.c$108$3$3 ==.
                           1395 ;	apps/test_random/test_random.c:108: response[responseLength++] = '\r';
   07D0 8E 05              1396 	mov	ar5,r6
   07D2 0E                 1397 	inc	r6
   07D3 ED                 1398 	mov	a,r5
   07D4 24 25              1399 	add	a,#_receiveCommands_response_2_2
   07D6 F5 82              1400 	mov	dpl,a
   07D8 E4                 1401 	clr	a
   07D9 34 F0              1402 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   07DB F5 83              1403 	mov	dph,a
   07DD 74 0D              1404 	mov	a,#0x0D
   07DF F0                 1405 	movx	@dptr,a
                    02E1   1406 	C$test_random.c$109$3$3 ==.
                           1407 ;	apps/test_random/test_random.c:109: response[responseLength++] = '\n';
   07E0 8E 05              1408 	mov	ar5,r6
   07E2 0E                 1409 	inc	r6
   07E3 ED                 1410 	mov	a,r5
   07E4 24 25              1411 	add	a,#_receiveCommands_response_2_2
   07E6 F5 82              1412 	mov	dpl,a
   07E8 E4                 1413 	clr	a
   07E9 34 F0              1414 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   07EB F5 83              1415 	mov	dph,a
   07ED 74 0A              1416 	mov	a,#0x0A
   07EF F0                 1417 	movx	@dptr,a
                    02F1   1418 	C$test_random.c$110$3$3 ==.
                           1419 ;	apps/test_random/test_random.c:110: break;
   07F0 02 08 E3           1420 	ljmp	00113$
                    02F4   1421 	C$test_random.c$112$3$3 ==.
                           1422 ;	apps/test_random/test_random.c:112: case 't':
   07F3                    1423 00111$:
                    02F4   1424 	C$test_random.c$115$3$3 ==.
                           1425 ;	apps/test_random/test_random.c:115: rand = adcRead(14 | ADC_BITS_7);
   07F3 75 82 3E           1426 	mov	dpl,#0x3E
   07F6 12 09 43           1427 	lcall	_adcRead
   07F9 AC 82              1428 	mov	r4,dpl
   07FB AD 83              1429 	mov	r5,dph
   07FD 8C 07              1430 	mov	ar7,r4
                    0300   1431 	C$test_random.c$116$3$3 ==.
                           1432 ;	apps/test_random/test_random.c:116: response[responseLength++] = ',';
   07FF 90 F0 26           1433 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0001)
   0802 74 2C              1434 	mov	a,#0x2C
   0804 F0                 1435 	movx	@dptr,a
                    0306   1436 	C$test_random.c$117$3$3 ==.
                           1437 ;	apps/test_random/test_random.c:117: response[responseLength++] = (rand & 0x80) ? '1' : '0';
   0805 EF                 1438 	mov	a,r7
   0806 30 E7 04           1439 	jnb	acc.7,00135$
   0809 7D 31              1440 	mov	r5,#0x31
   080B 80 02              1441 	sjmp	00136$
   080D                    1442 00135$:
   080D 7D 30              1443 	mov	r5,#0x30
   080F                    1444 00136$:
   080F 90 F0 27           1445 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0002)
   0812 ED                 1446 	mov	a,r5
   0813 F0                 1447 	movx	@dptr,a
                    0315   1448 	C$test_random.c$118$3$3 ==.
                           1449 ;	apps/test_random/test_random.c:118: response[responseLength++] = (rand & 0x40) ? '1' : '0';
   0814 EF                 1450 	mov	a,r7
   0815 30 E6 04           1451 	jnb	acc.6,00137$
   0818 7D 31              1452 	mov	r5,#0x31
   081A 80 02              1453 	sjmp	00138$
   081C                    1454 00137$:
   081C 7D 30              1455 	mov	r5,#0x30
   081E                    1456 00138$:
   081E 90 F0 28           1457 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0003)
   0821 ED                 1458 	mov	a,r5
   0822 F0                 1459 	movx	@dptr,a
                    0324   1460 	C$test_random.c$119$3$3 ==.
                           1461 ;	apps/test_random/test_random.c:119: response[responseLength++] = (rand & 0x20) ? '1' : '0';
   0823 7E 05              1462 	mov	r6,#0x05
   0825 EF                 1463 	mov	a,r7
   0826 30 E5 04           1464 	jnb	acc.5,00139$
   0829 7D 31              1465 	mov	r5,#0x31
   082B 80 02              1466 	sjmp	00140$
   082D                    1467 00139$:
   082D 7D 30              1468 	mov	r5,#0x30
   082F                    1469 00140$:
   082F 90 F0 29           1470 	mov	dptr,#(_receiveCommands_response_2_2 + 0x0004)
   0832 ED                 1471 	mov	a,r5
   0833 F0                 1472 	movx	@dptr,a
                    0335   1473 	C$test_random.c$120$3$3 ==.
                           1474 ;	apps/test_random/test_random.c:120: response[responseLength++] = (rand & 0x10) ? '1' : '0';
   0834 8E 05              1475 	mov	ar5,r6
   0836 0E                 1476 	inc	r6
   0837 ED                 1477 	mov	a,r5
   0838 24 25              1478 	add	a,#_receiveCommands_response_2_2
   083A FC                 1479 	mov	r4,a
   083B E4                 1480 	clr	a
   083C 34 F0              1481 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   083E FD                 1482 	mov	r5,a
   083F EF                 1483 	mov	a,r7
   0840 30 E4 04           1484 	jnb	acc.4,00141$
   0843 7B 31              1485 	mov	r3,#0x31
   0845 80 02              1486 	sjmp	00142$
   0847                    1487 00141$:
   0847 7B 30              1488 	mov	r3,#0x30
   0849                    1489 00142$:
   0849 8C 82              1490 	mov	dpl,r4
   084B 8D 83              1491 	mov	dph,r5
   084D EB                 1492 	mov	a,r3
   084E F0                 1493 	movx	@dptr,a
                    0350   1494 	C$test_random.c$121$3$3 ==.
                           1495 ;	apps/test_random/test_random.c:121: response[responseLength++] = (rand & 0x08) ? '1' : '0';
   084F 8E 05              1496 	mov	ar5,r6
   0851 0E                 1497 	inc	r6
   0852 ED                 1498 	mov	a,r5
   0853 24 25              1499 	add	a,#_receiveCommands_response_2_2
   0855 FC                 1500 	mov	r4,a
   0856 E4                 1501 	clr	a
   0857 34 F0              1502 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   0859 FD                 1503 	mov	r5,a
   085A EF                 1504 	mov	a,r7
   085B 30 E3 04           1505 	jnb	acc.3,00143$
   085E 7B 31              1506 	mov	r3,#0x31
   0860 80 02              1507 	sjmp	00144$
   0862                    1508 00143$:
   0862 7B 30              1509 	mov	r3,#0x30
   0864                    1510 00144$:
   0864 8C 82              1511 	mov	dpl,r4
   0866 8D 83              1512 	mov	dph,r5
   0868 EB                 1513 	mov	a,r3
   0869 F0                 1514 	movx	@dptr,a
                    036B   1515 	C$test_random.c$122$3$3 ==.
                           1516 ;	apps/test_random/test_random.c:122: response[responseLength++] = (rand & 0x04) ? '1' : '0';
   086A 8E 05              1517 	mov	ar5,r6
   086C 0E                 1518 	inc	r6
   086D ED                 1519 	mov	a,r5
   086E 24 25              1520 	add	a,#_receiveCommands_response_2_2
   0870 FC                 1521 	mov	r4,a
   0871 E4                 1522 	clr	a
   0872 34 F0              1523 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   0874 FD                 1524 	mov	r5,a
   0875 EF                 1525 	mov	a,r7
   0876 30 E2 04           1526 	jnb	acc.2,00145$
   0879 7B 31              1527 	mov	r3,#0x31
   087B 80 02              1528 	sjmp	00146$
   087D                    1529 00145$:
   087D 7B 30              1530 	mov	r3,#0x30
   087F                    1531 00146$:
   087F 8C 82              1532 	mov	dpl,r4
   0881 8D 83              1533 	mov	dph,r5
   0883 EB                 1534 	mov	a,r3
   0884 F0                 1535 	movx	@dptr,a
                    0386   1536 	C$test_random.c$123$3$3 ==.
                           1537 ;	apps/test_random/test_random.c:123: response[responseLength++] = (rand & 0x02) ? '1' : '0';
   0885 8E 05              1538 	mov	ar5,r6
   0887 0E                 1539 	inc	r6
   0888 ED                 1540 	mov	a,r5
   0889 24 25              1541 	add	a,#_receiveCommands_response_2_2
   088B FC                 1542 	mov	r4,a
   088C E4                 1543 	clr	a
   088D 34 F0              1544 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   088F FD                 1545 	mov	r5,a
   0890 EF                 1546 	mov	a,r7
   0891 30 E1 04           1547 	jnb	acc.1,00147$
   0894 7B 31              1548 	mov	r3,#0x31
   0896 80 02              1549 	sjmp	00148$
   0898                    1550 00147$:
   0898 7B 30              1551 	mov	r3,#0x30
   089A                    1552 00148$:
   089A 8C 82              1553 	mov	dpl,r4
   089C 8D 83              1554 	mov	dph,r5
   089E EB                 1555 	mov	a,r3
   089F F0                 1556 	movx	@dptr,a
                    03A1   1557 	C$test_random.c$124$3$3 ==.
                           1558 ;	apps/test_random/test_random.c:124: response[responseLength++] = (rand & 0x01) ? '1' : '0';
   08A0 8E 05              1559 	mov	ar5,r6
   08A2 0E                 1560 	inc	r6
   08A3 ED                 1561 	mov	a,r5
   08A4 24 25              1562 	add	a,#_receiveCommands_response_2_2
   08A6 FC                 1563 	mov	r4,a
   08A7 E4                 1564 	clr	a
   08A8 34 F0              1565 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   08AA FD                 1566 	mov	r5,a
   08AB EF                 1567 	mov	a,r7
   08AC 30 E0 04           1568 	jnb	acc.0,00149$
   08AF 7F 31              1569 	mov	r7,#0x31
   08B1 80 02              1570 	sjmp	00150$
   08B3                    1571 00149$:
   08B3 7F 30              1572 	mov	r7,#0x30
   08B5                    1573 00150$:
   08B5 8C 82              1574 	mov	dpl,r4
   08B7 8D 83              1575 	mov	dph,r5
   08B9 EF                 1576 	mov	a,r7
   08BA F0                 1577 	movx	@dptr,a
                    03BC   1578 	C$test_random.c$125$3$3 ==.
                           1579 ;	apps/test_random/test_random.c:125: response[responseLength++] = '\r';
   08BB 8E 07              1580 	mov	ar7,r6
   08BD 0E                 1581 	inc	r6
   08BE EF                 1582 	mov	a,r7
   08BF 24 25              1583 	add	a,#_receiveCommands_response_2_2
   08C1 F5 82              1584 	mov	dpl,a
   08C3 E4                 1585 	clr	a
   08C4 34 F0              1586 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   08C6 F5 83              1587 	mov	dph,a
   08C8 74 0D              1588 	mov	a,#0x0D
   08CA F0                 1589 	movx	@dptr,a
                    03CC   1590 	C$test_random.c$126$3$3 ==.
                           1591 ;	apps/test_random/test_random.c:126: response[responseLength++] = '\n';
   08CB 8E 07              1592 	mov	ar7,r6
   08CD 0E                 1593 	inc	r6
   08CE EF                 1594 	mov	a,r7
   08CF 24 25              1595 	add	a,#_receiveCommands_response_2_2
   08D1 F5 82              1596 	mov	dpl,a
   08D3 E4                 1597 	clr	a
   08D4 34 F0              1598 	addc	a,#(_receiveCommands_response_2_2 >> 8)
   08D6 F5 83              1599 	mov	dph,a
   08D8 74 0A              1600 	mov	a,#0x0A
   08DA F0                 1601 	movx	@dptr,a
                    03DC   1602 	C$test_random.c$127$3$3 ==.
                           1603 ;	apps/test_random/test_random.c:127: break;
                    03DC   1604 	C$test_random.c$129$3$3 ==.
                           1605 ;	apps/test_random/test_random.c:129: default: response[0] = '?'; break;
   08DB 80 06              1606 	sjmp	00113$
   08DD                    1607 00112$:
   08DD 90 F0 25           1608 	mov	dptr,#_receiveCommands_response_2_2
   08E0 74 3F              1609 	mov	a,#0x3F
   08E2 F0                 1610 	movx	@dptr,a
                    03E4   1611 	C$test_random.c$130$2$2 ==.
                           1612 ;	apps/test_random/test_random.c:130: }
   08E3                    1613 00113$:
                    03E4   1614 	C$test_random.c$131$2$2 ==.
                           1615 ;	apps/test_random/test_random.c:131: usbComTxSend(response, responseLength);
   08E3 78 0F              1616 	mov	r0,#_usbComTxSend_PARM_2
   08E5 EE                 1617 	mov	a,r6
   08E6 F2                 1618 	movx	@r0,a
   08E7 90 F0 25           1619 	mov	dptr,#_receiveCommands_response_2_2
   08EA 12 0B D2           1620 	lcall	_usbComTxSend
   08ED                    1621 00117$:
                    03EE   1622 	C$test_random.c$133$2$1 ==.
                    03EE   1623 	XG$receiveCommands$0$0 ==.
   08ED 22                 1624 	ret
                           1625 ;------------------------------------------------------------
                           1626 ;Allocation info for local variables in function 'main'
                           1627 ;------------------------------------------------------------
                    03EF   1628 	G$main$0$0 ==.
                    03EF   1629 	C$test_random.c$135$2$1 ==.
                           1630 ;	apps/test_random/test_random.c:135: void main()
                           1631 ;	-----------------------------------------
                           1632 ;	 function main
                           1633 ;	-----------------------------------------
   08EE                    1634 _main:
                    03EF   1635 	C$test_random.c$137$1$1 ==.
                           1636 ;	apps/test_random/test_random.c:137: systemInit();
   08EE 12 12 BE           1637 	lcall	_systemInit
                    03F2   1638 	C$test_random.c$139$1$1 ==.
                           1639 ;	apps/test_random/test_random.c:139: usbInit();
   08F1 12 0C 58           1640 	lcall	_usbInit
                    03F5   1641 	C$test_random.c$140$1$1 ==.
                           1642 ;	apps/test_random/test_random.c:140: randomSeedFromSerialNumber();
   08F4 12 14 D7           1643 	lcall	_randomSeedFromSerialNumber
                    03F8   1644 	C$test_random.c$141$1$1 ==.
                           1645 ;	apps/test_random/test_random.c:141: while(1)
   08F7                    1646 00102$:
                    03F8   1647 	C$test_random.c$143$2$2 ==.
                           1648 ;	apps/test_random/test_random.c:143: boardService();
   08F7 12 12 CB           1649 	lcall	_boardService
                    03FB   1650 	C$test_random.c$144$2$2 ==.
                           1651 ;	apps/test_random/test_random.c:144: updateLeds();
   08FA 12 04 FF           1652 	lcall	_updateLeds
                    03FE   1653 	C$test_random.c$145$2$2 ==.
                           1654 ;	apps/test_random/test_random.c:145: usbComService();
   08FD 12 0A F6           1655 	lcall	_usbComService
                    0401   1656 	C$test_random.c$146$2$2 ==.
                           1657 ;	apps/test_random/test_random.c:146: receiveCommands();
   0900 12 05 92           1658 	lcall	_receiveCommands
   0903 80 F2              1659 	sjmp	00102$
                    0406   1660 	C$test_random.c$148$1$1 ==.
                    0406   1661 	XG$main$0$0 ==.
   0905 22                 1662 	ret
                           1663 	.area CSEG    (CODE)
                           1664 	.area CONST   (CODE)
                           1665 	.area XINIT   (CODE)
                           1666 	.area CABS    (ABS,CODE)
