                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:45 2012
                              5 ;--------------------------------------------------------
                              6 	.module blocking
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _frequentTasks
                             13 	.globl _servosMoving
                             14 	.globl _usbComRxReceiveByte
                             15 	.globl _usbComRxAvailable
                             16 	.globl _getMs
                             17 	.globl _waitMs
                             18 	.globl _servosWaitWhileMoving
                             19 	.globl _usbComRxReceiveByteBlocking
                             20 ;--------------------------------------------------------
                             21 ; special function registers
                             22 ;--------------------------------------------------------
                             23 	.area RSEG    (ABS,DATA)
   0000                      24 	.org 0x0000
                    0080     25 Fblocking$P0$0$0 == 0x0080
                    0080     26 _P0	=	0x0080
                    0081     27 Fblocking$SP$0$0 == 0x0081
                    0081     28 _SP	=	0x0081
                    0082     29 Fblocking$DPL0$0$0 == 0x0082
                    0082     30 _DPL0	=	0x0082
                    0083     31 Fblocking$DPH0$0$0 == 0x0083
                    0083     32 _DPH0	=	0x0083
                    0084     33 Fblocking$DPL1$0$0 == 0x0084
                    0084     34 _DPL1	=	0x0084
                    0085     35 Fblocking$DPH1$0$0 == 0x0085
                    0085     36 _DPH1	=	0x0085
                    0086     37 Fblocking$U0CSR$0$0 == 0x0086
                    0086     38 _U0CSR	=	0x0086
                    0087     39 Fblocking$PCON$0$0 == 0x0087
                    0087     40 _PCON	=	0x0087
                    0088     41 Fblocking$TCON$0$0 == 0x0088
                    0088     42 _TCON	=	0x0088
                    0089     43 Fblocking$P0IFG$0$0 == 0x0089
                    0089     44 _P0IFG	=	0x0089
                    008A     45 Fblocking$P1IFG$0$0 == 0x008a
                    008A     46 _P1IFG	=	0x008a
                    008B     47 Fblocking$P2IFG$0$0 == 0x008b
                    008B     48 _P2IFG	=	0x008b
                    008C     49 Fblocking$PICTL$0$0 == 0x008c
                    008C     50 _PICTL	=	0x008c
                    008D     51 Fblocking$P1IEN$0$0 == 0x008d
                    008D     52 _P1IEN	=	0x008d
                    008F     53 Fblocking$P0INP$0$0 == 0x008f
                    008F     54 _P0INP	=	0x008f
                    0090     55 Fblocking$P1$0$0 == 0x0090
                    0090     56 _P1	=	0x0090
                    0091     57 Fblocking$RFIM$0$0 == 0x0091
                    0091     58 _RFIM	=	0x0091
                    0092     59 Fblocking$DPS$0$0 == 0x0092
                    0092     60 _DPS	=	0x0092
                    0093     61 Fblocking$MPAGE$0$0 == 0x0093
                    0093     62 _MPAGE	=	0x0093
                    0095     63 Fblocking$ENDIAN$0$0 == 0x0095
                    0095     64 _ENDIAN	=	0x0095
                    0098     65 Fblocking$S0CON$0$0 == 0x0098
                    0098     66 _S0CON	=	0x0098
                    009A     67 Fblocking$IEN2$0$0 == 0x009a
                    009A     68 _IEN2	=	0x009a
                    009B     69 Fblocking$S1CON$0$0 == 0x009b
                    009B     70 _S1CON	=	0x009b
                    009C     71 Fblocking$T2CT$0$0 == 0x009c
                    009C     72 _T2CT	=	0x009c
                    009D     73 Fblocking$T2PR$0$0 == 0x009d
                    009D     74 _T2PR	=	0x009d
                    009E     75 Fblocking$T2CTL$0$0 == 0x009e
                    009E     76 _T2CTL	=	0x009e
                    00A0     77 Fblocking$P2$0$0 == 0x00a0
                    00A0     78 _P2	=	0x00a0
                    00A1     79 Fblocking$WORIRQ$0$0 == 0x00a1
                    00A1     80 _WORIRQ	=	0x00a1
                    00A2     81 Fblocking$WORCTRL$0$0 == 0x00a2
                    00A2     82 _WORCTRL	=	0x00a2
                    00A3     83 Fblocking$WOREVT0$0$0 == 0x00a3
                    00A3     84 _WOREVT0	=	0x00a3
                    00A4     85 Fblocking$WOREVT1$0$0 == 0x00a4
                    00A4     86 _WOREVT1	=	0x00a4
                    00A5     87 Fblocking$WORTIME0$0$0 == 0x00a5
                    00A5     88 _WORTIME0	=	0x00a5
                    00A6     89 Fblocking$WORTIME1$0$0 == 0x00a6
                    00A6     90 _WORTIME1	=	0x00a6
                    00A8     91 Fblocking$IEN0$0$0 == 0x00a8
                    00A8     92 _IEN0	=	0x00a8
                    00A9     93 Fblocking$IP0$0$0 == 0x00a9
                    00A9     94 _IP0	=	0x00a9
                    00AB     95 Fblocking$FWT$0$0 == 0x00ab
                    00AB     96 _FWT	=	0x00ab
                    00AC     97 Fblocking$FADDRL$0$0 == 0x00ac
                    00AC     98 _FADDRL	=	0x00ac
                    00AD     99 Fblocking$FADDRH$0$0 == 0x00ad
                    00AD    100 _FADDRH	=	0x00ad
                    00AE    101 Fblocking$FCTL$0$0 == 0x00ae
                    00AE    102 _FCTL	=	0x00ae
                    00AF    103 Fblocking$FWDATA$0$0 == 0x00af
                    00AF    104 _FWDATA	=	0x00af
                    00B1    105 Fblocking$ENCDI$0$0 == 0x00b1
                    00B1    106 _ENCDI	=	0x00b1
                    00B2    107 Fblocking$ENCDO$0$0 == 0x00b2
                    00B2    108 _ENCDO	=	0x00b2
                    00B3    109 Fblocking$ENCCS$0$0 == 0x00b3
                    00B3    110 _ENCCS	=	0x00b3
                    00B4    111 Fblocking$ADCCON1$0$0 == 0x00b4
                    00B4    112 _ADCCON1	=	0x00b4
                    00B5    113 Fblocking$ADCCON2$0$0 == 0x00b5
                    00B5    114 _ADCCON2	=	0x00b5
                    00B6    115 Fblocking$ADCCON3$0$0 == 0x00b6
                    00B6    116 _ADCCON3	=	0x00b6
                    00B8    117 Fblocking$IEN1$0$0 == 0x00b8
                    00B8    118 _IEN1	=	0x00b8
                    00B9    119 Fblocking$IP1$0$0 == 0x00b9
                    00B9    120 _IP1	=	0x00b9
                    00BA    121 Fblocking$ADCL$0$0 == 0x00ba
                    00BA    122 _ADCL	=	0x00ba
                    00BB    123 Fblocking$ADCH$0$0 == 0x00bb
                    00BB    124 _ADCH	=	0x00bb
                    00BC    125 Fblocking$RNDL$0$0 == 0x00bc
                    00BC    126 _RNDL	=	0x00bc
                    00BD    127 Fblocking$RNDH$0$0 == 0x00bd
                    00BD    128 _RNDH	=	0x00bd
                    00BE    129 Fblocking$SLEEP$0$0 == 0x00be
                    00BE    130 _SLEEP	=	0x00be
                    00C0    131 Fblocking$IRCON$0$0 == 0x00c0
                    00C0    132 _IRCON	=	0x00c0
                    00C1    133 Fblocking$U0DBUF$0$0 == 0x00c1
                    00C1    134 _U0DBUF	=	0x00c1
                    00C2    135 Fblocking$U0BAUD$0$0 == 0x00c2
                    00C2    136 _U0BAUD	=	0x00c2
                    00C4    137 Fblocking$U0UCR$0$0 == 0x00c4
                    00C4    138 _U0UCR	=	0x00c4
                    00C5    139 Fblocking$U0GCR$0$0 == 0x00c5
                    00C5    140 _U0GCR	=	0x00c5
                    00C6    141 Fblocking$CLKCON$0$0 == 0x00c6
                    00C6    142 _CLKCON	=	0x00c6
                    00C7    143 Fblocking$MEMCTR$0$0 == 0x00c7
                    00C7    144 _MEMCTR	=	0x00c7
                    00C9    145 Fblocking$WDCTL$0$0 == 0x00c9
                    00C9    146 _WDCTL	=	0x00c9
                    00CA    147 Fblocking$T3CNT$0$0 == 0x00ca
                    00CA    148 _T3CNT	=	0x00ca
                    00CB    149 Fblocking$T3CTL$0$0 == 0x00cb
                    00CB    150 _T3CTL	=	0x00cb
                    00CC    151 Fblocking$T3CCTL0$0$0 == 0x00cc
                    00CC    152 _T3CCTL0	=	0x00cc
                    00CD    153 Fblocking$T3CC0$0$0 == 0x00cd
                    00CD    154 _T3CC0	=	0x00cd
                    00CE    155 Fblocking$T3CCTL1$0$0 == 0x00ce
                    00CE    156 _T3CCTL1	=	0x00ce
                    00CF    157 Fblocking$T3CC1$0$0 == 0x00cf
                    00CF    158 _T3CC1	=	0x00cf
                    00D0    159 Fblocking$PSW$0$0 == 0x00d0
                    00D0    160 _PSW	=	0x00d0
                    00D1    161 Fblocking$DMAIRQ$0$0 == 0x00d1
                    00D1    162 _DMAIRQ	=	0x00d1
                    00D2    163 Fblocking$DMA1CFGL$0$0 == 0x00d2
                    00D2    164 _DMA1CFGL	=	0x00d2
                    00D3    165 Fblocking$DMA1CFGH$0$0 == 0x00d3
                    00D3    166 _DMA1CFGH	=	0x00d3
                    00D4    167 Fblocking$DMA0CFGL$0$0 == 0x00d4
                    00D4    168 _DMA0CFGL	=	0x00d4
                    00D5    169 Fblocking$DMA0CFGH$0$0 == 0x00d5
                    00D5    170 _DMA0CFGH	=	0x00d5
                    00D6    171 Fblocking$DMAARM$0$0 == 0x00d6
                    00D6    172 _DMAARM	=	0x00d6
                    00D7    173 Fblocking$DMAREQ$0$0 == 0x00d7
                    00D7    174 _DMAREQ	=	0x00d7
                    00D8    175 Fblocking$TIMIF$0$0 == 0x00d8
                    00D8    176 _TIMIF	=	0x00d8
                    00D9    177 Fblocking$RFD$0$0 == 0x00d9
                    00D9    178 _RFD	=	0x00d9
                    00DA    179 Fblocking$T1CC0L$0$0 == 0x00da
                    00DA    180 _T1CC0L	=	0x00da
                    00DB    181 Fblocking$T1CC0H$0$0 == 0x00db
                    00DB    182 _T1CC0H	=	0x00db
                    00DC    183 Fblocking$T1CC1L$0$0 == 0x00dc
                    00DC    184 _T1CC1L	=	0x00dc
                    00DD    185 Fblocking$T1CC1H$0$0 == 0x00dd
                    00DD    186 _T1CC1H	=	0x00dd
                    00DE    187 Fblocking$T1CC2L$0$0 == 0x00de
                    00DE    188 _T1CC2L	=	0x00de
                    00DF    189 Fblocking$T1CC2H$0$0 == 0x00df
                    00DF    190 _T1CC2H	=	0x00df
                    00E0    191 Fblocking$ACC$0$0 == 0x00e0
                    00E0    192 _ACC	=	0x00e0
                    00E1    193 Fblocking$RFST$0$0 == 0x00e1
                    00E1    194 _RFST	=	0x00e1
                    00E2    195 Fblocking$T1CNTL$0$0 == 0x00e2
                    00E2    196 _T1CNTL	=	0x00e2
                    00E3    197 Fblocking$T1CNTH$0$0 == 0x00e3
                    00E3    198 _T1CNTH	=	0x00e3
                    00E4    199 Fblocking$T1CTL$0$0 == 0x00e4
                    00E4    200 _T1CTL	=	0x00e4
                    00E5    201 Fblocking$T1CCTL0$0$0 == 0x00e5
                    00E5    202 _T1CCTL0	=	0x00e5
                    00E6    203 Fblocking$T1CCTL1$0$0 == 0x00e6
                    00E6    204 _T1CCTL1	=	0x00e6
                    00E7    205 Fblocking$T1CCTL2$0$0 == 0x00e7
                    00E7    206 _T1CCTL2	=	0x00e7
                    00E8    207 Fblocking$IRCON2$0$0 == 0x00e8
                    00E8    208 _IRCON2	=	0x00e8
                    00E9    209 Fblocking$RFIF$0$0 == 0x00e9
                    00E9    210 _RFIF	=	0x00e9
                    00EA    211 Fblocking$T4CNT$0$0 == 0x00ea
                    00EA    212 _T4CNT	=	0x00ea
                    00EB    213 Fblocking$T4CTL$0$0 == 0x00eb
                    00EB    214 _T4CTL	=	0x00eb
                    00EC    215 Fblocking$T4CCTL0$0$0 == 0x00ec
                    00EC    216 _T4CCTL0	=	0x00ec
                    00ED    217 Fblocking$T4CC0$0$0 == 0x00ed
                    00ED    218 _T4CC0	=	0x00ed
                    00EE    219 Fblocking$T4CCTL1$0$0 == 0x00ee
                    00EE    220 _T4CCTL1	=	0x00ee
                    00EF    221 Fblocking$T4CC1$0$0 == 0x00ef
                    00EF    222 _T4CC1	=	0x00ef
                    00F0    223 Fblocking$B$0$0 == 0x00f0
                    00F0    224 _B	=	0x00f0
                    00F1    225 Fblocking$PERCFG$0$0 == 0x00f1
                    00F1    226 _PERCFG	=	0x00f1
                    00F2    227 Fblocking$ADCCFG$0$0 == 0x00f2
                    00F2    228 _ADCCFG	=	0x00f2
                    00F3    229 Fblocking$P0SEL$0$0 == 0x00f3
                    00F3    230 _P0SEL	=	0x00f3
                    00F4    231 Fblocking$P1SEL$0$0 == 0x00f4
                    00F4    232 _P1SEL	=	0x00f4
                    00F5    233 Fblocking$P2SEL$0$0 == 0x00f5
                    00F5    234 _P2SEL	=	0x00f5
                    00F6    235 Fblocking$P1INP$0$0 == 0x00f6
                    00F6    236 _P1INP	=	0x00f6
                    00F7    237 Fblocking$P2INP$0$0 == 0x00f7
                    00F7    238 _P2INP	=	0x00f7
                    00F8    239 Fblocking$U1CSR$0$0 == 0x00f8
                    00F8    240 _U1CSR	=	0x00f8
                    00F9    241 Fblocking$U1DBUF$0$0 == 0x00f9
                    00F9    242 _U1DBUF	=	0x00f9
                    00FA    243 Fblocking$U1BAUD$0$0 == 0x00fa
                    00FA    244 _U1BAUD	=	0x00fa
                    00FB    245 Fblocking$U1UCR$0$0 == 0x00fb
                    00FB    246 _U1UCR	=	0x00fb
                    00FC    247 Fblocking$U1GCR$0$0 == 0x00fc
                    00FC    248 _U1GCR	=	0x00fc
                    00FD    249 Fblocking$P0DIR$0$0 == 0x00fd
                    00FD    250 _P0DIR	=	0x00fd
                    00FE    251 Fblocking$P1DIR$0$0 == 0x00fe
                    00FE    252 _P1DIR	=	0x00fe
                    00FF    253 Fblocking$P2DIR$0$0 == 0x00ff
                    00FF    254 _P2DIR	=	0x00ff
                    FFFFD5D4    255 Fblocking$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    256 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    257 Fblocking$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    258 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    259 Fblocking$FADDR$0$0 == 0xffffadac
                    FFFFADAC    260 _FADDR	=	0xffffadac
                    FFFFBBBA    261 Fblocking$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    262 _ADC	=	0xffffbbba
                    FFFFDBDA    263 Fblocking$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    264 _T1CC0	=	0xffffdbda
                    FFFFDDDC    265 Fblocking$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    266 _T1CC1	=	0xffffdddc
                    FFFFDFDE    267 Fblocking$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    268 _T1CC2	=	0xffffdfde
                            269 ;--------------------------------------------------------
                            270 ; special function bits
                            271 ;--------------------------------------------------------
                            272 	.area RSEG    (ABS,DATA)
   0000                     273 	.org 0x0000
                    0080    274 Fblocking$P0_0$0$0 == 0x0080
                    0080    275 _P0_0	=	0x0080
                    0081    276 Fblocking$P0_1$0$0 == 0x0081
                    0081    277 _P0_1	=	0x0081
                    0082    278 Fblocking$P0_2$0$0 == 0x0082
                    0082    279 _P0_2	=	0x0082
                    0083    280 Fblocking$P0_3$0$0 == 0x0083
                    0083    281 _P0_3	=	0x0083
                    0084    282 Fblocking$P0_4$0$0 == 0x0084
                    0084    283 _P0_4	=	0x0084
                    0085    284 Fblocking$P0_5$0$0 == 0x0085
                    0085    285 _P0_5	=	0x0085
                    0086    286 Fblocking$P0_6$0$0 == 0x0086
                    0086    287 _P0_6	=	0x0086
                    0087    288 Fblocking$P0_7$0$0 == 0x0087
                    0087    289 _P0_7	=	0x0087
                    0088    290 Fblocking$_TCON_0$0$0 == 0x0088
                    0088    291 __TCON_0	=	0x0088
                    0089    292 Fblocking$RFTXRXIF$0$0 == 0x0089
                    0089    293 _RFTXRXIF	=	0x0089
                    008A    294 Fblocking$_TCON_2$0$0 == 0x008a
                    008A    295 __TCON_2	=	0x008a
                    008B    296 Fblocking$URX0IF$0$0 == 0x008b
                    008B    297 _URX0IF	=	0x008b
                    008C    298 Fblocking$_TCON_4$0$0 == 0x008c
                    008C    299 __TCON_4	=	0x008c
                    008D    300 Fblocking$ADCIF$0$0 == 0x008d
                    008D    301 _ADCIF	=	0x008d
                    008E    302 Fblocking$_TCON_6$0$0 == 0x008e
                    008E    303 __TCON_6	=	0x008e
                    008F    304 Fblocking$URX1IF$0$0 == 0x008f
                    008F    305 _URX1IF	=	0x008f
                    0090    306 Fblocking$P1_0$0$0 == 0x0090
                    0090    307 _P1_0	=	0x0090
                    0091    308 Fblocking$P1_1$0$0 == 0x0091
                    0091    309 _P1_1	=	0x0091
                    0092    310 Fblocking$P1_2$0$0 == 0x0092
                    0092    311 _P1_2	=	0x0092
                    0093    312 Fblocking$P1_3$0$0 == 0x0093
                    0093    313 _P1_3	=	0x0093
                    0094    314 Fblocking$P1_4$0$0 == 0x0094
                    0094    315 _P1_4	=	0x0094
                    0095    316 Fblocking$P1_5$0$0 == 0x0095
                    0095    317 _P1_5	=	0x0095
                    0096    318 Fblocking$P1_6$0$0 == 0x0096
                    0096    319 _P1_6	=	0x0096
                    0097    320 Fblocking$P1_7$0$0 == 0x0097
                    0097    321 _P1_7	=	0x0097
                    0098    322 Fblocking$ENCIF_0$0$0 == 0x0098
                    0098    323 _ENCIF_0	=	0x0098
                    0099    324 Fblocking$ENCIF_1$0$0 == 0x0099
                    0099    325 _ENCIF_1	=	0x0099
                    009A    326 Fblocking$_SOCON2$0$0 == 0x009a
                    009A    327 __SOCON2	=	0x009a
                    009B    328 Fblocking$_SOCON3$0$0 == 0x009b
                    009B    329 __SOCON3	=	0x009b
                    009C    330 Fblocking$_SOCON4$0$0 == 0x009c
                    009C    331 __SOCON4	=	0x009c
                    009D    332 Fblocking$_SOCON5$0$0 == 0x009d
                    009D    333 __SOCON5	=	0x009d
                    009E    334 Fblocking$_SOCON6$0$0 == 0x009e
                    009E    335 __SOCON6	=	0x009e
                    009F    336 Fblocking$_SOCON7$0$0 == 0x009f
                    009F    337 __SOCON7	=	0x009f
                    00A0    338 Fblocking$P2_0$0$0 == 0x00a0
                    00A0    339 _P2_0	=	0x00a0
                    00A1    340 Fblocking$P2_1$0$0 == 0x00a1
                    00A1    341 _P2_1	=	0x00a1
                    00A2    342 Fblocking$P2_2$0$0 == 0x00a2
                    00A2    343 _P2_2	=	0x00a2
                    00A3    344 Fblocking$P2_3$0$0 == 0x00a3
                    00A3    345 _P2_3	=	0x00a3
                    00A4    346 Fblocking$P2_4$0$0 == 0x00a4
                    00A4    347 _P2_4	=	0x00a4
                    00A5    348 Fblocking$P2_5$0$0 == 0x00a5
                    00A5    349 _P2_5	=	0x00a5
                    00A6    350 Fblocking$P2_6$0$0 == 0x00a6
                    00A6    351 _P2_6	=	0x00a6
                    00A7    352 Fblocking$P2_7$0$0 == 0x00a7
                    00A7    353 _P2_7	=	0x00a7
                    00A8    354 Fblocking$RFTXRXIE$0$0 == 0x00a8
                    00A8    355 _RFTXRXIE	=	0x00a8
                    00A9    356 Fblocking$ADCIE$0$0 == 0x00a9
                    00A9    357 _ADCIE	=	0x00a9
                    00AA    358 Fblocking$URX0IE$0$0 == 0x00aa
                    00AA    359 _URX0IE	=	0x00aa
                    00AB    360 Fblocking$URX1IE$0$0 == 0x00ab
                    00AB    361 _URX1IE	=	0x00ab
                    00AC    362 Fblocking$ENCIE$0$0 == 0x00ac
                    00AC    363 _ENCIE	=	0x00ac
                    00AD    364 Fblocking$STIE$0$0 == 0x00ad
                    00AD    365 _STIE	=	0x00ad
                    00AE    366 Fblocking$_IEN06$0$0 == 0x00ae
                    00AE    367 __IEN06	=	0x00ae
                    00AF    368 Fblocking$EA$0$0 == 0x00af
                    00AF    369 _EA	=	0x00af
                    00B8    370 Fblocking$DMAIE$0$0 == 0x00b8
                    00B8    371 _DMAIE	=	0x00b8
                    00B9    372 Fblocking$T1IE$0$0 == 0x00b9
                    00B9    373 _T1IE	=	0x00b9
                    00BA    374 Fblocking$T2IE$0$0 == 0x00ba
                    00BA    375 _T2IE	=	0x00ba
                    00BB    376 Fblocking$T3IE$0$0 == 0x00bb
                    00BB    377 _T3IE	=	0x00bb
                    00BC    378 Fblocking$T4IE$0$0 == 0x00bc
                    00BC    379 _T4IE	=	0x00bc
                    00BD    380 Fblocking$P0IE$0$0 == 0x00bd
                    00BD    381 _P0IE	=	0x00bd
                    00BE    382 Fblocking$_IEN16$0$0 == 0x00be
                    00BE    383 __IEN16	=	0x00be
                    00BF    384 Fblocking$_IEN17$0$0 == 0x00bf
                    00BF    385 __IEN17	=	0x00bf
                    00C0    386 Fblocking$DMAIF$0$0 == 0x00c0
                    00C0    387 _DMAIF	=	0x00c0
                    00C1    388 Fblocking$T1IF$0$0 == 0x00c1
                    00C1    389 _T1IF	=	0x00c1
                    00C2    390 Fblocking$T2IF$0$0 == 0x00c2
                    00C2    391 _T2IF	=	0x00c2
                    00C3    392 Fblocking$T3IF$0$0 == 0x00c3
                    00C3    393 _T3IF	=	0x00c3
                    00C4    394 Fblocking$T4IF$0$0 == 0x00c4
                    00C4    395 _T4IF	=	0x00c4
                    00C5    396 Fblocking$P0IF$0$0 == 0x00c5
                    00C5    397 _P0IF	=	0x00c5
                    00C6    398 Fblocking$_IRCON6$0$0 == 0x00c6
                    00C6    399 __IRCON6	=	0x00c6
                    00C7    400 Fblocking$STIF$0$0 == 0x00c7
                    00C7    401 _STIF	=	0x00c7
                    00D0    402 Fblocking$P$0$0 == 0x00d0
                    00D0    403 _P	=	0x00d0
                    00D1    404 Fblocking$F1$0$0 == 0x00d1
                    00D1    405 _F1	=	0x00d1
                    00D2    406 Fblocking$OV$0$0 == 0x00d2
                    00D2    407 _OV	=	0x00d2
                    00D3    408 Fblocking$RS0$0$0 == 0x00d3
                    00D3    409 _RS0	=	0x00d3
                    00D4    410 Fblocking$RS1$0$0 == 0x00d4
                    00D4    411 _RS1	=	0x00d4
                    00D5    412 Fblocking$F0$0$0 == 0x00d5
                    00D5    413 _F0	=	0x00d5
                    00D6    414 Fblocking$AC$0$0 == 0x00d6
                    00D6    415 _AC	=	0x00d6
                    00D7    416 Fblocking$CY$0$0 == 0x00d7
                    00D7    417 _CY	=	0x00d7
                    00D8    418 Fblocking$T3OVFIF$0$0 == 0x00d8
                    00D8    419 _T3OVFIF	=	0x00d8
                    00D9    420 Fblocking$T3CH0IF$0$0 == 0x00d9
                    00D9    421 _T3CH0IF	=	0x00d9
                    00DA    422 Fblocking$T3CH1IF$0$0 == 0x00da
                    00DA    423 _T3CH1IF	=	0x00da
                    00DB    424 Fblocking$T4OVFIF$0$0 == 0x00db
                    00DB    425 _T4OVFIF	=	0x00db
                    00DC    426 Fblocking$T4CH0IF$0$0 == 0x00dc
                    00DC    427 _T4CH0IF	=	0x00dc
                    00DD    428 Fblocking$T4CH1IF$0$0 == 0x00dd
                    00DD    429 _T4CH1IF	=	0x00dd
                    00DE    430 Fblocking$OVFIM$0$0 == 0x00de
                    00DE    431 _OVFIM	=	0x00de
                    00DF    432 Fblocking$_TIMIF7$0$0 == 0x00df
                    00DF    433 __TIMIF7	=	0x00df
                    00E0    434 Fblocking$ACC_0$0$0 == 0x00e0
                    00E0    435 _ACC_0	=	0x00e0
                    00E1    436 Fblocking$ACC_1$0$0 == 0x00e1
                    00E1    437 _ACC_1	=	0x00e1
                    00E2    438 Fblocking$ACC_2$0$0 == 0x00e2
                    00E2    439 _ACC_2	=	0x00e2
                    00E3    440 Fblocking$ACC_3$0$0 == 0x00e3
                    00E3    441 _ACC_3	=	0x00e3
                    00E4    442 Fblocking$ACC_4$0$0 == 0x00e4
                    00E4    443 _ACC_4	=	0x00e4
                    00E5    444 Fblocking$ACC_5$0$0 == 0x00e5
                    00E5    445 _ACC_5	=	0x00e5
                    00E6    446 Fblocking$ACC_6$0$0 == 0x00e6
                    00E6    447 _ACC_6	=	0x00e6
                    00E7    448 Fblocking$ACC_7$0$0 == 0x00e7
                    00E7    449 _ACC_7	=	0x00e7
                    00E8    450 Fblocking$P2IF$0$0 == 0x00e8
                    00E8    451 _P2IF	=	0x00e8
                    00E9    452 Fblocking$UTX0IF$0$0 == 0x00e9
                    00E9    453 _UTX0IF	=	0x00e9
                    00EA    454 Fblocking$UTX1IF$0$0 == 0x00ea
                    00EA    455 _UTX1IF	=	0x00ea
                    00EB    456 Fblocking$P1IF$0$0 == 0x00eb
                    00EB    457 _P1IF	=	0x00eb
                    00EC    458 Fblocking$WDTIF$0$0 == 0x00ec
                    00EC    459 _WDTIF	=	0x00ec
                    00ED    460 Fblocking$_IRCON25$0$0 == 0x00ed
                    00ED    461 __IRCON25	=	0x00ed
                    00EE    462 Fblocking$_IRCON26$0$0 == 0x00ee
                    00EE    463 __IRCON26	=	0x00ee
                    00EF    464 Fblocking$_IRCON27$0$0 == 0x00ef
                    00EF    465 __IRCON27	=	0x00ef
                    00F0    466 Fblocking$B_0$0$0 == 0x00f0
                    00F0    467 _B_0	=	0x00f0
                    00F1    468 Fblocking$B_1$0$0 == 0x00f1
                    00F1    469 _B_1	=	0x00f1
                    00F2    470 Fblocking$B_2$0$0 == 0x00f2
                    00F2    471 _B_2	=	0x00f2
                    00F3    472 Fblocking$B_3$0$0 == 0x00f3
                    00F3    473 _B_3	=	0x00f3
                    00F4    474 Fblocking$B_4$0$0 == 0x00f4
                    00F4    475 _B_4	=	0x00f4
                    00F5    476 Fblocking$B_5$0$0 == 0x00f5
                    00F5    477 _B_5	=	0x00f5
                    00F6    478 Fblocking$B_6$0$0 == 0x00f6
                    00F6    479 _B_6	=	0x00f6
                    00F7    480 Fblocking$B_7$0$0 == 0x00f7
                    00F7    481 _B_7	=	0x00f7
                    00F8    482 Fblocking$U1ACTIVE$0$0 == 0x00f8
                    00F8    483 _U1ACTIVE	=	0x00f8
                    00F9    484 Fblocking$U1TX_BYTE$0$0 == 0x00f9
                    00F9    485 _U1TX_BYTE	=	0x00f9
                    00FA    486 Fblocking$U1RX_BYTE$0$0 == 0x00fa
                    00FA    487 _U1RX_BYTE	=	0x00fa
                    00FB    488 Fblocking$U1ERR$0$0 == 0x00fb
                    00FB    489 _U1ERR	=	0x00fb
                    00FC    490 Fblocking$U1FE$0$0 == 0x00fc
                    00FC    491 _U1FE	=	0x00fc
                    00FD    492 Fblocking$U1SLAVE$0$0 == 0x00fd
                    00FD    493 _U1SLAVE	=	0x00fd
                    00FE    494 Fblocking$U1RE$0$0 == 0x00fe
                    00FE    495 _U1RE	=	0x00fe
                    00FF    496 Fblocking$U1MODE$0$0 == 0x00ff
                    00FF    497 _U1MODE	=	0x00ff
                            498 ;--------------------------------------------------------
                            499 ; overlayable register banks
                            500 ;--------------------------------------------------------
                            501 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     502 	.ds 8
                            503 ;--------------------------------------------------------
                            504 ; internal ram data
                            505 ;--------------------------------------------------------
                            506 	.area DSEG    (DATA)
                            507 ;--------------------------------------------------------
                            508 ; overlayable items in internal ram 
                            509 ;--------------------------------------------------------
                            510 	.area OSEG    (OVR,DATA)
                            511 ;--------------------------------------------------------
                            512 ; indirectly addressable internal ram data
                            513 ;--------------------------------------------------------
                            514 	.area ISEG    (DATA)
                            515 ;--------------------------------------------------------
                            516 ; absolute internal ram data
                            517 ;--------------------------------------------------------
                            518 	.area IABS    (ABS,DATA)
                            519 	.area IABS    (ABS,DATA)
                            520 ;--------------------------------------------------------
                            521 ; bit data
                            522 ;--------------------------------------------------------
                            523 	.area BSEG    (BIT)
                            524 ;--------------------------------------------------------
                            525 ; paged external ram data
                            526 ;--------------------------------------------------------
                            527 	.area PSEG    (PAG,XDATA)
                    0000    528 Lblocking.waitMs$milliseconds$1$1==.
   F000                     529 _waitMs_milliseconds_1_1:
   F000                     530 	.ds 4
                    0004    531 Lblocking.waitMs$start$1$1==.
   F004                     532 _waitMs_start_1_1:
   F004                     533 	.ds 4
                            534 ;--------------------------------------------------------
                            535 ; external ram data
                            536 ;--------------------------------------------------------
                            537 	.area XSEG    (XDATA)
                    DF00    538 Fblocking$SYNC1$0$0 == 0xdf00
                    DF00    539 _SYNC1	=	0xdf00
                    DF01    540 Fblocking$SYNC0$0$0 == 0xdf01
                    DF01    541 _SYNC0	=	0xdf01
                    DF02    542 Fblocking$PKTLEN$0$0 == 0xdf02
                    DF02    543 _PKTLEN	=	0xdf02
                    DF03    544 Fblocking$PKTCTRL1$0$0 == 0xdf03
                    DF03    545 _PKTCTRL1	=	0xdf03
                    DF04    546 Fblocking$PKTCTRL0$0$0 == 0xdf04
                    DF04    547 _PKTCTRL0	=	0xdf04
                    DF05    548 Fblocking$ADDR$0$0 == 0xdf05
                    DF05    549 _ADDR	=	0xdf05
                    DF06    550 Fblocking$CHANNR$0$0 == 0xdf06
                    DF06    551 _CHANNR	=	0xdf06
                    DF07    552 Fblocking$FSCTRL1$0$0 == 0xdf07
                    DF07    553 _FSCTRL1	=	0xdf07
                    DF08    554 Fblocking$FSCTRL0$0$0 == 0xdf08
                    DF08    555 _FSCTRL0	=	0xdf08
                    DF09    556 Fblocking$FREQ2$0$0 == 0xdf09
                    DF09    557 _FREQ2	=	0xdf09
                    DF0A    558 Fblocking$FREQ1$0$0 == 0xdf0a
                    DF0A    559 _FREQ1	=	0xdf0a
                    DF0B    560 Fblocking$FREQ0$0$0 == 0xdf0b
                    DF0B    561 _FREQ0	=	0xdf0b
                    DF0C    562 Fblocking$MDMCFG4$0$0 == 0xdf0c
                    DF0C    563 _MDMCFG4	=	0xdf0c
                    DF0D    564 Fblocking$MDMCFG3$0$0 == 0xdf0d
                    DF0D    565 _MDMCFG3	=	0xdf0d
                    DF0E    566 Fblocking$MDMCFG2$0$0 == 0xdf0e
                    DF0E    567 _MDMCFG2	=	0xdf0e
                    DF0F    568 Fblocking$MDMCFG1$0$0 == 0xdf0f
                    DF0F    569 _MDMCFG1	=	0xdf0f
                    DF10    570 Fblocking$MDMCFG0$0$0 == 0xdf10
                    DF10    571 _MDMCFG0	=	0xdf10
                    DF11    572 Fblocking$DEVIATN$0$0 == 0xdf11
                    DF11    573 _DEVIATN	=	0xdf11
                    DF12    574 Fblocking$MCSM2$0$0 == 0xdf12
                    DF12    575 _MCSM2	=	0xdf12
                    DF13    576 Fblocking$MCSM1$0$0 == 0xdf13
                    DF13    577 _MCSM1	=	0xdf13
                    DF14    578 Fblocking$MCSM0$0$0 == 0xdf14
                    DF14    579 _MCSM0	=	0xdf14
                    DF15    580 Fblocking$FOCCFG$0$0 == 0xdf15
                    DF15    581 _FOCCFG	=	0xdf15
                    DF16    582 Fblocking$BSCFG$0$0 == 0xdf16
                    DF16    583 _BSCFG	=	0xdf16
                    DF17    584 Fblocking$AGCCTRL2$0$0 == 0xdf17
                    DF17    585 _AGCCTRL2	=	0xdf17
                    DF18    586 Fblocking$AGCCTRL1$0$0 == 0xdf18
                    DF18    587 _AGCCTRL1	=	0xdf18
                    DF19    588 Fblocking$AGCCTRL0$0$0 == 0xdf19
                    DF19    589 _AGCCTRL0	=	0xdf19
                    DF1A    590 Fblocking$FREND1$0$0 == 0xdf1a
                    DF1A    591 _FREND1	=	0xdf1a
                    DF1B    592 Fblocking$FREND0$0$0 == 0xdf1b
                    DF1B    593 _FREND0	=	0xdf1b
                    DF1C    594 Fblocking$FSCAL3$0$0 == 0xdf1c
                    DF1C    595 _FSCAL3	=	0xdf1c
                    DF1D    596 Fblocking$FSCAL2$0$0 == 0xdf1d
                    DF1D    597 _FSCAL2	=	0xdf1d
                    DF1E    598 Fblocking$FSCAL1$0$0 == 0xdf1e
                    DF1E    599 _FSCAL1	=	0xdf1e
                    DF1F    600 Fblocking$FSCAL0$0$0 == 0xdf1f
                    DF1F    601 _FSCAL0	=	0xdf1f
                    DF23    602 Fblocking$TEST2$0$0 == 0xdf23
                    DF23    603 _TEST2	=	0xdf23
                    DF24    604 Fblocking$TEST1$0$0 == 0xdf24
                    DF24    605 _TEST1	=	0xdf24
                    DF25    606 Fblocking$TEST0$0$0 == 0xdf25
                    DF25    607 _TEST0	=	0xdf25
                    DF2E    608 Fblocking$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    609 _PA_TABLE0	=	0xdf2e
                    DF2F    610 Fblocking$IOCFG2$0$0 == 0xdf2f
                    DF2F    611 _IOCFG2	=	0xdf2f
                    DF30    612 Fblocking$IOCFG1$0$0 == 0xdf30
                    DF30    613 _IOCFG1	=	0xdf30
                    DF31    614 Fblocking$IOCFG0$0$0 == 0xdf31
                    DF31    615 _IOCFG0	=	0xdf31
                    DF36    616 Fblocking$PARTNUM$0$0 == 0xdf36
                    DF36    617 _PARTNUM	=	0xdf36
                    DF37    618 Fblocking$VERSION$0$0 == 0xdf37
                    DF37    619 _VERSION	=	0xdf37
                    DF38    620 Fblocking$FREQEST$0$0 == 0xdf38
                    DF38    621 _FREQEST	=	0xdf38
                    DF39    622 Fblocking$LQI$0$0 == 0xdf39
                    DF39    623 _LQI	=	0xdf39
                    DF3A    624 Fblocking$RSSI$0$0 == 0xdf3a
                    DF3A    625 _RSSI	=	0xdf3a
                    DF3B    626 Fblocking$MARCSTATE$0$0 == 0xdf3b
                    DF3B    627 _MARCSTATE	=	0xdf3b
                    DF3C    628 Fblocking$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    629 _PKTSTATUS	=	0xdf3c
                    DF3D    630 Fblocking$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    631 _VCO_VC_DAC	=	0xdf3d
                    DF40    632 Fblocking$I2SCFG0$0$0 == 0xdf40
                    DF40    633 _I2SCFG0	=	0xdf40
                    DF41    634 Fblocking$I2SCFG1$0$0 == 0xdf41
                    DF41    635 _I2SCFG1	=	0xdf41
                    DF42    636 Fblocking$I2SDATL$0$0 == 0xdf42
                    DF42    637 _I2SDATL	=	0xdf42
                    DF43    638 Fblocking$I2SDATH$0$0 == 0xdf43
                    DF43    639 _I2SDATH	=	0xdf43
                    DF44    640 Fblocking$I2SWCNT$0$0 == 0xdf44
                    DF44    641 _I2SWCNT	=	0xdf44
                    DF45    642 Fblocking$I2SSTAT$0$0 == 0xdf45
                    DF45    643 _I2SSTAT	=	0xdf45
                    DF46    644 Fblocking$I2SCLKF0$0$0 == 0xdf46
                    DF46    645 _I2SCLKF0	=	0xdf46
                    DF47    646 Fblocking$I2SCLKF1$0$0 == 0xdf47
                    DF47    647 _I2SCLKF1	=	0xdf47
                    DF48    648 Fblocking$I2SCLKF2$0$0 == 0xdf48
                    DF48    649 _I2SCLKF2	=	0xdf48
                    DE00    650 Fblocking$USBADDR$0$0 == 0xde00
                    DE00    651 _USBADDR	=	0xde00
                    DE01    652 Fblocking$USBPOW$0$0 == 0xde01
                    DE01    653 _USBPOW	=	0xde01
                    DE02    654 Fblocking$USBIIF$0$0 == 0xde02
                    DE02    655 _USBIIF	=	0xde02
                    DE04    656 Fblocking$USBOIF$0$0 == 0xde04
                    DE04    657 _USBOIF	=	0xde04
                    DE06    658 Fblocking$USBCIF$0$0 == 0xde06
                    DE06    659 _USBCIF	=	0xde06
                    DE07    660 Fblocking$USBIIE$0$0 == 0xde07
                    DE07    661 _USBIIE	=	0xde07
                    DE09    662 Fblocking$USBOIE$0$0 == 0xde09
                    DE09    663 _USBOIE	=	0xde09
                    DE0B    664 Fblocking$USBCIE$0$0 == 0xde0b
                    DE0B    665 _USBCIE	=	0xde0b
                    DE0C    666 Fblocking$USBFRML$0$0 == 0xde0c
                    DE0C    667 _USBFRML	=	0xde0c
                    DE0D    668 Fblocking$USBFRMH$0$0 == 0xde0d
                    DE0D    669 _USBFRMH	=	0xde0d
                    DE0E    670 Fblocking$USBINDEX$0$0 == 0xde0e
                    DE0E    671 _USBINDEX	=	0xde0e
                    DE10    672 Fblocking$USBMAXI$0$0 == 0xde10
                    DE10    673 _USBMAXI	=	0xde10
                    DE11    674 Fblocking$USBCSIL$0$0 == 0xde11
                    DE11    675 _USBCSIL	=	0xde11
                    DE12    676 Fblocking$USBCSIH$0$0 == 0xde12
                    DE12    677 _USBCSIH	=	0xde12
                    DE13    678 Fblocking$USBMAXO$0$0 == 0xde13
                    DE13    679 _USBMAXO	=	0xde13
                    DE14    680 Fblocking$USBCSOL$0$0 == 0xde14
                    DE14    681 _USBCSOL	=	0xde14
                    DE15    682 Fblocking$USBCSOH$0$0 == 0xde15
                    DE15    683 _USBCSOH	=	0xde15
                    DE16    684 Fblocking$USBCNTL$0$0 == 0xde16
                    DE16    685 _USBCNTL	=	0xde16
                    DE17    686 Fblocking$USBCNTH$0$0 == 0xde17
                    DE17    687 _USBCNTH	=	0xde17
                    DE20    688 Fblocking$USBF0$0$0 == 0xde20
                    DE20    689 _USBF0	=	0xde20
                    DE22    690 Fblocking$USBF1$0$0 == 0xde22
                    DE22    691 _USBF1	=	0xde22
                    DE24    692 Fblocking$USBF2$0$0 == 0xde24
                    DE24    693 _USBF2	=	0xde24
                    DE26    694 Fblocking$USBF3$0$0 == 0xde26
                    DE26    695 _USBF3	=	0xde26
                    DE28    696 Fblocking$USBF4$0$0 == 0xde28
                    DE28    697 _USBF4	=	0xde28
                    DE2A    698 Fblocking$USBF5$0$0 == 0xde2a
                    DE2A    699 _USBF5	=	0xde2a
                            700 ;--------------------------------------------------------
                            701 ; absolute external ram data
                            702 ;--------------------------------------------------------
                            703 	.area XABS    (ABS,XDATA)
                            704 ;--------------------------------------------------------
                            705 ; external initialized ram data
                            706 ;--------------------------------------------------------
                            707 	.area XISEG   (XDATA)
                            708 	.area HOME    (CODE)
                            709 	.area GSINIT0 (CODE)
                            710 	.area GSINIT1 (CODE)
                            711 	.area GSINIT2 (CODE)
                            712 	.area GSINIT3 (CODE)
                            713 	.area GSINIT4 (CODE)
                            714 	.area GSINIT5 (CODE)
                            715 	.area GSINIT  (CODE)
                            716 	.area GSFINAL (CODE)
                            717 	.area CSEG    (CODE)
                            718 ;--------------------------------------------------------
                            719 ; global & static initialisations
                            720 ;--------------------------------------------------------
                            721 	.area HOME    (CODE)
                            722 	.area GSINIT  (CODE)
                            723 	.area GSFINAL (CODE)
                            724 	.area GSINIT  (CODE)
                            725 ;--------------------------------------------------------
                            726 ; Home
                            727 ;--------------------------------------------------------
                            728 	.area HOME    (CODE)
                            729 	.area HOME    (CODE)
                            730 ;--------------------------------------------------------
                            731 ; code
                            732 ;--------------------------------------------------------
                            733 	.area CSEG    (CODE)
                            734 ;------------------------------------------------------------
                            735 ;Allocation info for local variables in function 'waitMs'
                            736 ;------------------------------------------------------------
                    0000    737 	G$waitMs$0$0 ==.
                    0000    738 	C$blocking.c$20$0$0 ==.
                            739 ;	apps/example_servo_sequence/blocking.c:20: void waitMs(uint32 milliseconds)
                            740 ;	-----------------------------------------
                            741 ;	 function waitMs
                            742 ;	-----------------------------------------
   04FA                     743 _waitMs:
                    0007    744 	ar7 = 0x07
                    0006    745 	ar6 = 0x06
                    0005    746 	ar5 = 0x05
                    0004    747 	ar4 = 0x04
                    0003    748 	ar3 = 0x03
                    0002    749 	ar2 = 0x02
                    0001    750 	ar1 = 0x01
                    0000    751 	ar0 = 0x00
   04FA AF 82               752 	mov	r7,dpl
   04FC AE 83               753 	mov	r6,dph
   04FE AD F0               754 	mov	r5,b
   0500 FC                  755 	mov	r4,a
   0501 78 00               756 	mov	r0,#_waitMs_milliseconds_1_1
   0503 EF                  757 	mov	a,r7
   0504 F2                  758 	movx	@r0,a
   0505 08                  759 	inc	r0
   0506 EE                  760 	mov	a,r6
   0507 F2                  761 	movx	@r0,a
   0508 08                  762 	inc	r0
   0509 ED                  763 	mov	a,r5
   050A F2                  764 	movx	@r0,a
   050B 08                  765 	inc	r0
   050C EC                  766 	mov	a,r4
   050D F2                  767 	movx	@r0,a
                    0014    768 	C$blocking.c$24$1$1 ==.
                            769 ;	apps/example_servo_sequence/blocking.c:24: if (milliseconds == 0){ return; }
   050E 78 00               770 	mov	r0,#_waitMs_milliseconds_1_1
   0510 E2                  771 	movx	a,@r0
   0511 F5 F0               772 	mov	b,a
   0513 08                  773 	inc	r0
   0514 E2                  774 	movx	a,@r0
   0515 42 F0               775 	orl	b,a
   0517 08                  776 	inc	r0
   0518 E2                  777 	movx	a,@r0
   0519 42 F0               778 	orl	b,a
   051B 08                  779 	inc	r0
   051C E2                  780 	movx	a,@r0
   051D 45 F0               781 	orl	a,b
   051F 70 02               782 	jnz	00102$
   0521 80 51               783 	sjmp	00106$
   0523                     784 00102$:
                    0029    785 	C$blocking.c$26$1$1 ==.
                            786 ;	apps/example_servo_sequence/blocking.c:26: start = getMs();
   0523 12 16 71            787 	lcall	_getMs
   0526 78 04               788 	mov	r0,#_waitMs_start_1_1
   0528 C0 E0               789 	push	acc
   052A E5 82               790 	mov	a,dpl
   052C F2                  791 	movx	@r0,a
   052D 08                  792 	inc	r0
   052E E5 83               793 	mov	a,dph
   0530 F2                  794 	movx	@r0,a
   0531 08                  795 	inc	r0
   0532 E5 F0               796 	mov	a,b
   0534 F2                  797 	movx	@r0,a
   0535 D0 E0               798 	pop	acc
   0537 08                  799 	inc	r0
   0538 F2                  800 	movx	@r0,a
                    003F    801 	C$blocking.c$27$1$1 ==.
                            802 ;	apps/example_servo_sequence/blocking.c:27: while(getMs() - start <= milliseconds){ frequentTasks(); }
   0539                     803 00103$:
   0539 12 16 71            804 	lcall	_getMs
   053C AA 82               805 	mov	r2,dpl
   053E AB 83               806 	mov	r3,dph
   0540 AE F0               807 	mov	r6,b
   0542 FF                  808 	mov	r7,a
   0543 78 04               809 	mov	r0,#_waitMs_start_1_1
   0545 D3                  810 	setb	c
   0546 E2                  811 	movx	a,@r0
   0547 9A                  812 	subb	a,r2
   0548 F4                  813 	cpl	a
   0549 B3                  814 	cpl	c
   054A FA                  815 	mov	r2,a
   054B B3                  816 	cpl	c
   054C 08                  817 	inc	r0
   054D E2                  818 	movx	a,@r0
   054E 9B                  819 	subb	a,r3
   054F F4                  820 	cpl	a
   0550 B3                  821 	cpl	c
   0551 FB                  822 	mov	r3,a
   0552 B3                  823 	cpl	c
   0553 08                  824 	inc	r0
   0554 E2                  825 	movx	a,@r0
   0555 9E                  826 	subb	a,r6
   0556 F4                  827 	cpl	a
   0557 B3                  828 	cpl	c
   0558 FE                  829 	mov	r6,a
   0559 B3                  830 	cpl	c
   055A 08                  831 	inc	r0
   055B E2                  832 	movx	a,@r0
   055C 9F                  833 	subb	a,r7
   055D F4                  834 	cpl	a
   055E FF                  835 	mov	r7,a
   055F 78 00               836 	mov	r0,#_waitMs_milliseconds_1_1
   0561 C3                  837 	clr	c
   0562 E2                  838 	movx	a,@r0
   0563 9A                  839 	subb	a,r2
   0564 08                  840 	inc	r0
   0565 E2                  841 	movx	a,@r0
   0566 9B                  842 	subb	a,r3
   0567 08                  843 	inc	r0
   0568 E2                  844 	movx	a,@r0
   0569 9E                  845 	subb	a,r6
   056A 08                  846 	inc	r0
   056B E2                  847 	movx	a,@r0
   056C 9F                  848 	subb	a,r7
   056D 40 05               849 	jc	00106$
   056F 12 05 90            850 	lcall	_frequentTasks
   0572 80 C5               851 	sjmp	00103$
   0574                     852 00106$:
                    007A    853 	C$blocking.c$28$1$1 ==.
                    007A    854 	XG$waitMs$0$0 ==.
   0574 22                  855 	ret
                            856 ;------------------------------------------------------------
                            857 ;Allocation info for local variables in function 'servosWaitWhileMoving'
                            858 ;------------------------------------------------------------
                    007B    859 	G$servosWaitWhileMoving$0$0 ==.
                    007B    860 	C$blocking.c$30$1$1 ==.
                            861 ;	apps/example_servo_sequence/blocking.c:30: void servosWaitWhileMoving()
                            862 ;	-----------------------------------------
                            863 ;	 function servosWaitWhileMoving
                            864 ;	-----------------------------------------
   0575                     865 _servosWaitWhileMoving:
                    007B    866 	C$blocking.c$32$1$1 ==.
                            867 ;	apps/example_servo_sequence/blocking.c:32: while(servosMoving()){ frequentTasks(); }
   0575                     868 00101$:
   0575 12 0A 7F            869 	lcall	_servosMoving
   0578 50 05               870 	jnc	00104$
   057A 12 05 90            871 	lcall	_frequentTasks
   057D 80 F6               872 	sjmp	00101$
   057F                     873 00104$:
                    0085    874 	C$blocking.c$33$1$1 ==.
                    0085    875 	XG$servosWaitWhileMoving$0$0 ==.
   057F 22                  876 	ret
                            877 ;------------------------------------------------------------
                            878 ;Allocation info for local variables in function 'usbComRxReceiveByteBlocking'
                            879 ;------------------------------------------------------------
                    0086    880 	G$usbComRxReceiveByteBlocking$0$0 ==.
                    0086    881 	C$blocking.c$35$1$1 ==.
                            882 ;	apps/example_servo_sequence/blocking.c:35: uint8 usbComRxReceiveByteBlocking()
                            883 ;	-----------------------------------------
                            884 ;	 function usbComRxReceiveByteBlocking
                            885 ;	-----------------------------------------
   0580                     886 _usbComRxReceiveByteBlocking:
                    0086    887 	C$blocking.c$37$1$1 ==.
                            888 ;	apps/example_servo_sequence/blocking.c:37: while(usbComRxAvailable() == 0){ frequentTasks(); }
   0580                     889 00101$:
   0580 12 0C F8            890 	lcall	_usbComRxAvailable
   0583 E5 82               891 	mov	a,dpl
   0585 70 05               892 	jnz	00103$
   0587 12 05 90            893 	lcall	_frequentTasks
   058A 80 F4               894 	sjmp	00101$
   058C                     895 00103$:
                    0092    896 	C$blocking.c$38$1$1 ==.
                            897 ;	apps/example_servo_sequence/blocking.c:38: return usbComRxReceiveByte();
   058C 12 0D 22            898 	lcall	_usbComRxReceiveByte
                    0095    899 	C$blocking.c$39$1$1 ==.
                    0095    900 	XG$usbComRxReceiveByteBlocking$0$0 ==.
   058F 22                  901 	ret
                            902 	.area CSEG    (CODE)
                            903 	.area CONST   (CODE)
                            904 	.area XINIT   (CODE)
                            905 	.area CABS    (ABS,CODE)
