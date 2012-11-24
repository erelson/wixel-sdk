                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Aug 17 17:32:48 2012
                              5 ;--------------------------------------------------------
                              6 	.module usb_serial
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _lineCodingChanged
                             14 	.globl _usbToUartService
                             15 	.globl _updateLeds
                             16 	.globl _uart1RxReceiveByte
                             17 	.globl _uart1RxAvailable
                             18 	.globl _uart1TxSendByte
                             19 	.globl _uart1TxAvailable
                             20 	.globl _uart1SetStopBits
                             21 	.globl _uart1SetParity
                             22 	.globl _uart1SetBaudRate
                             23 	.globl _uart1Init
                             24 	.globl _usbComTxSendByte
                             25 	.globl _usbComTxAvailable
                             26 	.globl _usbComRxReceiveByte
                             27 	.globl _usbComRxAvailable
                             28 	.globl _usbComService
                             29 	.globl _usbComTxControlSignals
                             30 	.globl _usbComRxControlSignals
                             31 	.globl _usbShowStatusWithGreenLed
                             32 	.globl _usbInit
                             33 	.globl _boardService
                             34 	.globl _systemInit
                             35 ;--------------------------------------------------------
                             36 ; special function registers
                             37 ;--------------------------------------------------------
                             38 	.area RSEG    (ABS,DATA)
   0000                      39 	.org 0x0000
                    0080     40 Fusb_serial$P0$0$0 == 0x0080
                    0080     41 _P0	=	0x0080
                    0081     42 Fusb_serial$SP$0$0 == 0x0081
                    0081     43 _SP	=	0x0081
                    0082     44 Fusb_serial$DPL0$0$0 == 0x0082
                    0082     45 _DPL0	=	0x0082
                    0083     46 Fusb_serial$DPH0$0$0 == 0x0083
                    0083     47 _DPH0	=	0x0083
                    0084     48 Fusb_serial$DPL1$0$0 == 0x0084
                    0084     49 _DPL1	=	0x0084
                    0085     50 Fusb_serial$DPH1$0$0 == 0x0085
                    0085     51 _DPH1	=	0x0085
                    0086     52 Fusb_serial$U0CSR$0$0 == 0x0086
                    0086     53 _U0CSR	=	0x0086
                    0087     54 Fusb_serial$PCON$0$0 == 0x0087
                    0087     55 _PCON	=	0x0087
                    0088     56 Fusb_serial$TCON$0$0 == 0x0088
                    0088     57 _TCON	=	0x0088
                    0089     58 Fusb_serial$P0IFG$0$0 == 0x0089
                    0089     59 _P0IFG	=	0x0089
                    008A     60 Fusb_serial$P1IFG$0$0 == 0x008a
                    008A     61 _P1IFG	=	0x008a
                    008B     62 Fusb_serial$P2IFG$0$0 == 0x008b
                    008B     63 _P2IFG	=	0x008b
                    008C     64 Fusb_serial$PICTL$0$0 == 0x008c
                    008C     65 _PICTL	=	0x008c
                    008D     66 Fusb_serial$P1IEN$0$0 == 0x008d
                    008D     67 _P1IEN	=	0x008d
                    008F     68 Fusb_serial$P0INP$0$0 == 0x008f
                    008F     69 _P0INP	=	0x008f
                    0090     70 Fusb_serial$P1$0$0 == 0x0090
                    0090     71 _P1	=	0x0090
                    0091     72 Fusb_serial$RFIM$0$0 == 0x0091
                    0091     73 _RFIM	=	0x0091
                    0092     74 Fusb_serial$DPS$0$0 == 0x0092
                    0092     75 _DPS	=	0x0092
                    0093     76 Fusb_serial$MPAGE$0$0 == 0x0093
                    0093     77 _MPAGE	=	0x0093
                    0095     78 Fusb_serial$ENDIAN$0$0 == 0x0095
                    0095     79 _ENDIAN	=	0x0095
                    0098     80 Fusb_serial$S0CON$0$0 == 0x0098
                    0098     81 _S0CON	=	0x0098
                    009A     82 Fusb_serial$IEN2$0$0 == 0x009a
                    009A     83 _IEN2	=	0x009a
                    009B     84 Fusb_serial$S1CON$0$0 == 0x009b
                    009B     85 _S1CON	=	0x009b
                    009C     86 Fusb_serial$T2CT$0$0 == 0x009c
                    009C     87 _T2CT	=	0x009c
                    009D     88 Fusb_serial$T2PR$0$0 == 0x009d
                    009D     89 _T2PR	=	0x009d
                    009E     90 Fusb_serial$T2CTL$0$0 == 0x009e
                    009E     91 _T2CTL	=	0x009e
                    00A0     92 Fusb_serial$P2$0$0 == 0x00a0
                    00A0     93 _P2	=	0x00a0
                    00A1     94 Fusb_serial$WORIRQ$0$0 == 0x00a1
                    00A1     95 _WORIRQ	=	0x00a1
                    00A2     96 Fusb_serial$WORCTRL$0$0 == 0x00a2
                    00A2     97 _WORCTRL	=	0x00a2
                    00A3     98 Fusb_serial$WOREVT0$0$0 == 0x00a3
                    00A3     99 _WOREVT0	=	0x00a3
                    00A4    100 Fusb_serial$WOREVT1$0$0 == 0x00a4
                    00A4    101 _WOREVT1	=	0x00a4
                    00A5    102 Fusb_serial$WORTIME0$0$0 == 0x00a5
                    00A5    103 _WORTIME0	=	0x00a5
                    00A6    104 Fusb_serial$WORTIME1$0$0 == 0x00a6
                    00A6    105 _WORTIME1	=	0x00a6
                    00A8    106 Fusb_serial$IEN0$0$0 == 0x00a8
                    00A8    107 _IEN0	=	0x00a8
                    00A9    108 Fusb_serial$IP0$0$0 == 0x00a9
                    00A9    109 _IP0	=	0x00a9
                    00AB    110 Fusb_serial$FWT$0$0 == 0x00ab
                    00AB    111 _FWT	=	0x00ab
                    00AC    112 Fusb_serial$FADDRL$0$0 == 0x00ac
                    00AC    113 _FADDRL	=	0x00ac
                    00AD    114 Fusb_serial$FADDRH$0$0 == 0x00ad
                    00AD    115 _FADDRH	=	0x00ad
                    00AE    116 Fusb_serial$FCTL$0$0 == 0x00ae
                    00AE    117 _FCTL	=	0x00ae
                    00AF    118 Fusb_serial$FWDATA$0$0 == 0x00af
                    00AF    119 _FWDATA	=	0x00af
                    00B1    120 Fusb_serial$ENCDI$0$0 == 0x00b1
                    00B1    121 _ENCDI	=	0x00b1
                    00B2    122 Fusb_serial$ENCDO$0$0 == 0x00b2
                    00B2    123 _ENCDO	=	0x00b2
                    00B3    124 Fusb_serial$ENCCS$0$0 == 0x00b3
                    00B3    125 _ENCCS	=	0x00b3
                    00B4    126 Fusb_serial$ADCCON1$0$0 == 0x00b4
                    00B4    127 _ADCCON1	=	0x00b4
                    00B5    128 Fusb_serial$ADCCON2$0$0 == 0x00b5
                    00B5    129 _ADCCON2	=	0x00b5
                    00B6    130 Fusb_serial$ADCCON3$0$0 == 0x00b6
                    00B6    131 _ADCCON3	=	0x00b6
                    00B8    132 Fusb_serial$IEN1$0$0 == 0x00b8
                    00B8    133 _IEN1	=	0x00b8
                    00B9    134 Fusb_serial$IP1$0$0 == 0x00b9
                    00B9    135 _IP1	=	0x00b9
                    00BA    136 Fusb_serial$ADCL$0$0 == 0x00ba
                    00BA    137 _ADCL	=	0x00ba
                    00BB    138 Fusb_serial$ADCH$0$0 == 0x00bb
                    00BB    139 _ADCH	=	0x00bb
                    00BC    140 Fusb_serial$RNDL$0$0 == 0x00bc
                    00BC    141 _RNDL	=	0x00bc
                    00BD    142 Fusb_serial$RNDH$0$0 == 0x00bd
                    00BD    143 _RNDH	=	0x00bd
                    00BE    144 Fusb_serial$SLEEP$0$0 == 0x00be
                    00BE    145 _SLEEP	=	0x00be
                    00C0    146 Fusb_serial$IRCON$0$0 == 0x00c0
                    00C0    147 _IRCON	=	0x00c0
                    00C1    148 Fusb_serial$U0DBUF$0$0 == 0x00c1
                    00C1    149 _U0DBUF	=	0x00c1
                    00C2    150 Fusb_serial$U0BAUD$0$0 == 0x00c2
                    00C2    151 _U0BAUD	=	0x00c2
                    00C4    152 Fusb_serial$U0UCR$0$0 == 0x00c4
                    00C4    153 _U0UCR	=	0x00c4
                    00C5    154 Fusb_serial$U0GCR$0$0 == 0x00c5
                    00C5    155 _U0GCR	=	0x00c5
                    00C6    156 Fusb_serial$CLKCON$0$0 == 0x00c6
                    00C6    157 _CLKCON	=	0x00c6
                    00C7    158 Fusb_serial$MEMCTR$0$0 == 0x00c7
                    00C7    159 _MEMCTR	=	0x00c7
                    00C9    160 Fusb_serial$WDCTL$0$0 == 0x00c9
                    00C9    161 _WDCTL	=	0x00c9
                    00CA    162 Fusb_serial$T3CNT$0$0 == 0x00ca
                    00CA    163 _T3CNT	=	0x00ca
                    00CB    164 Fusb_serial$T3CTL$0$0 == 0x00cb
                    00CB    165 _T3CTL	=	0x00cb
                    00CC    166 Fusb_serial$T3CCTL0$0$0 == 0x00cc
                    00CC    167 _T3CCTL0	=	0x00cc
                    00CD    168 Fusb_serial$T3CC0$0$0 == 0x00cd
                    00CD    169 _T3CC0	=	0x00cd
                    00CE    170 Fusb_serial$T3CCTL1$0$0 == 0x00ce
                    00CE    171 _T3CCTL1	=	0x00ce
                    00CF    172 Fusb_serial$T3CC1$0$0 == 0x00cf
                    00CF    173 _T3CC1	=	0x00cf
                    00D0    174 Fusb_serial$PSW$0$0 == 0x00d0
                    00D0    175 _PSW	=	0x00d0
                    00D1    176 Fusb_serial$DMAIRQ$0$0 == 0x00d1
                    00D1    177 _DMAIRQ	=	0x00d1
                    00D2    178 Fusb_serial$DMA1CFGL$0$0 == 0x00d2
                    00D2    179 _DMA1CFGL	=	0x00d2
                    00D3    180 Fusb_serial$DMA1CFGH$0$0 == 0x00d3
                    00D3    181 _DMA1CFGH	=	0x00d3
                    00D4    182 Fusb_serial$DMA0CFGL$0$0 == 0x00d4
                    00D4    183 _DMA0CFGL	=	0x00d4
                    00D5    184 Fusb_serial$DMA0CFGH$0$0 == 0x00d5
                    00D5    185 _DMA0CFGH	=	0x00d5
                    00D6    186 Fusb_serial$DMAARM$0$0 == 0x00d6
                    00D6    187 _DMAARM	=	0x00d6
                    00D7    188 Fusb_serial$DMAREQ$0$0 == 0x00d7
                    00D7    189 _DMAREQ	=	0x00d7
                    00D8    190 Fusb_serial$TIMIF$0$0 == 0x00d8
                    00D8    191 _TIMIF	=	0x00d8
                    00D9    192 Fusb_serial$RFD$0$0 == 0x00d9
                    00D9    193 _RFD	=	0x00d9
                    00DA    194 Fusb_serial$T1CC0L$0$0 == 0x00da
                    00DA    195 _T1CC0L	=	0x00da
                    00DB    196 Fusb_serial$T1CC0H$0$0 == 0x00db
                    00DB    197 _T1CC0H	=	0x00db
                    00DC    198 Fusb_serial$T1CC1L$0$0 == 0x00dc
                    00DC    199 _T1CC1L	=	0x00dc
                    00DD    200 Fusb_serial$T1CC1H$0$0 == 0x00dd
                    00DD    201 _T1CC1H	=	0x00dd
                    00DE    202 Fusb_serial$T1CC2L$0$0 == 0x00de
                    00DE    203 _T1CC2L	=	0x00de
                    00DF    204 Fusb_serial$T1CC2H$0$0 == 0x00df
                    00DF    205 _T1CC2H	=	0x00df
                    00E0    206 Fusb_serial$ACC$0$0 == 0x00e0
                    00E0    207 _ACC	=	0x00e0
                    00E1    208 Fusb_serial$RFST$0$0 == 0x00e1
                    00E1    209 _RFST	=	0x00e1
                    00E2    210 Fusb_serial$T1CNTL$0$0 == 0x00e2
                    00E2    211 _T1CNTL	=	0x00e2
                    00E3    212 Fusb_serial$T1CNTH$0$0 == 0x00e3
                    00E3    213 _T1CNTH	=	0x00e3
                    00E4    214 Fusb_serial$T1CTL$0$0 == 0x00e4
                    00E4    215 _T1CTL	=	0x00e4
                    00E5    216 Fusb_serial$T1CCTL0$0$0 == 0x00e5
                    00E5    217 _T1CCTL0	=	0x00e5
                    00E6    218 Fusb_serial$T1CCTL1$0$0 == 0x00e6
                    00E6    219 _T1CCTL1	=	0x00e6
                    00E7    220 Fusb_serial$T1CCTL2$0$0 == 0x00e7
                    00E7    221 _T1CCTL2	=	0x00e7
                    00E8    222 Fusb_serial$IRCON2$0$0 == 0x00e8
                    00E8    223 _IRCON2	=	0x00e8
                    00E9    224 Fusb_serial$RFIF$0$0 == 0x00e9
                    00E9    225 _RFIF	=	0x00e9
                    00EA    226 Fusb_serial$T4CNT$0$0 == 0x00ea
                    00EA    227 _T4CNT	=	0x00ea
                    00EB    228 Fusb_serial$T4CTL$0$0 == 0x00eb
                    00EB    229 _T4CTL	=	0x00eb
                    00EC    230 Fusb_serial$T4CCTL0$0$0 == 0x00ec
                    00EC    231 _T4CCTL0	=	0x00ec
                    00ED    232 Fusb_serial$T4CC0$0$0 == 0x00ed
                    00ED    233 _T4CC0	=	0x00ed
                    00EE    234 Fusb_serial$T4CCTL1$0$0 == 0x00ee
                    00EE    235 _T4CCTL1	=	0x00ee
                    00EF    236 Fusb_serial$T4CC1$0$0 == 0x00ef
                    00EF    237 _T4CC1	=	0x00ef
                    00F0    238 Fusb_serial$B$0$0 == 0x00f0
                    00F0    239 _B	=	0x00f0
                    00F1    240 Fusb_serial$PERCFG$0$0 == 0x00f1
                    00F1    241 _PERCFG	=	0x00f1
                    00F2    242 Fusb_serial$ADCCFG$0$0 == 0x00f2
                    00F2    243 _ADCCFG	=	0x00f2
                    00F3    244 Fusb_serial$P0SEL$0$0 == 0x00f3
                    00F3    245 _P0SEL	=	0x00f3
                    00F4    246 Fusb_serial$P1SEL$0$0 == 0x00f4
                    00F4    247 _P1SEL	=	0x00f4
                    00F5    248 Fusb_serial$P2SEL$0$0 == 0x00f5
                    00F5    249 _P2SEL	=	0x00f5
                    00F6    250 Fusb_serial$P1INP$0$0 == 0x00f6
                    00F6    251 _P1INP	=	0x00f6
                    00F7    252 Fusb_serial$P2INP$0$0 == 0x00f7
                    00F7    253 _P2INP	=	0x00f7
                    00F8    254 Fusb_serial$U1CSR$0$0 == 0x00f8
                    00F8    255 _U1CSR	=	0x00f8
                    00F9    256 Fusb_serial$U1DBUF$0$0 == 0x00f9
                    00F9    257 _U1DBUF	=	0x00f9
                    00FA    258 Fusb_serial$U1BAUD$0$0 == 0x00fa
                    00FA    259 _U1BAUD	=	0x00fa
                    00FB    260 Fusb_serial$U1UCR$0$0 == 0x00fb
                    00FB    261 _U1UCR	=	0x00fb
                    00FC    262 Fusb_serial$U1GCR$0$0 == 0x00fc
                    00FC    263 _U1GCR	=	0x00fc
                    00FD    264 Fusb_serial$P0DIR$0$0 == 0x00fd
                    00FD    265 _P0DIR	=	0x00fd
                    00FE    266 Fusb_serial$P1DIR$0$0 == 0x00fe
                    00FE    267 _P1DIR	=	0x00fe
                    00FF    268 Fusb_serial$P2DIR$0$0 == 0x00ff
                    00FF    269 _P2DIR	=	0x00ff
                    FFFFD5D4    270 Fusb_serial$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    271 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    272 Fusb_serial$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    273 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    274 Fusb_serial$FADDR$0$0 == 0xffffadac
                    FFFFADAC    275 _FADDR	=	0xffffadac
                    FFFFBBBA    276 Fusb_serial$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    277 _ADC	=	0xffffbbba
                    FFFFDBDA    278 Fusb_serial$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    279 _T1CC0	=	0xffffdbda
                    FFFFDDDC    280 Fusb_serial$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    281 _T1CC1	=	0xffffdddc
                    FFFFDFDE    282 Fusb_serial$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    283 _T1CC2	=	0xffffdfde
                            284 ;--------------------------------------------------------
                            285 ; special function bits
                            286 ;--------------------------------------------------------
                            287 	.area RSEG    (ABS,DATA)
   0000                     288 	.org 0x0000
                    0080    289 Fusb_serial$P0_0$0$0 == 0x0080
                    0080    290 _P0_0	=	0x0080
                    0081    291 Fusb_serial$P0_1$0$0 == 0x0081
                    0081    292 _P0_1	=	0x0081
                    0082    293 Fusb_serial$P0_2$0$0 == 0x0082
                    0082    294 _P0_2	=	0x0082
                    0083    295 Fusb_serial$P0_3$0$0 == 0x0083
                    0083    296 _P0_3	=	0x0083
                    0084    297 Fusb_serial$P0_4$0$0 == 0x0084
                    0084    298 _P0_4	=	0x0084
                    0085    299 Fusb_serial$P0_5$0$0 == 0x0085
                    0085    300 _P0_5	=	0x0085
                    0086    301 Fusb_serial$P0_6$0$0 == 0x0086
                    0086    302 _P0_6	=	0x0086
                    0087    303 Fusb_serial$P0_7$0$0 == 0x0087
                    0087    304 _P0_7	=	0x0087
                    0088    305 Fusb_serial$_TCON_0$0$0 == 0x0088
                    0088    306 __TCON_0	=	0x0088
                    0089    307 Fusb_serial$RFTXRXIF$0$0 == 0x0089
                    0089    308 _RFTXRXIF	=	0x0089
                    008A    309 Fusb_serial$_TCON_2$0$0 == 0x008a
                    008A    310 __TCON_2	=	0x008a
                    008B    311 Fusb_serial$URX0IF$0$0 == 0x008b
                    008B    312 _URX0IF	=	0x008b
                    008C    313 Fusb_serial$_TCON_4$0$0 == 0x008c
                    008C    314 __TCON_4	=	0x008c
                    008D    315 Fusb_serial$ADCIF$0$0 == 0x008d
                    008D    316 _ADCIF	=	0x008d
                    008E    317 Fusb_serial$_TCON_6$0$0 == 0x008e
                    008E    318 __TCON_6	=	0x008e
                    008F    319 Fusb_serial$URX1IF$0$0 == 0x008f
                    008F    320 _URX1IF	=	0x008f
                    0090    321 Fusb_serial$P1_0$0$0 == 0x0090
                    0090    322 _P1_0	=	0x0090
                    0091    323 Fusb_serial$P1_1$0$0 == 0x0091
                    0091    324 _P1_1	=	0x0091
                    0092    325 Fusb_serial$P1_2$0$0 == 0x0092
                    0092    326 _P1_2	=	0x0092
                    0093    327 Fusb_serial$P1_3$0$0 == 0x0093
                    0093    328 _P1_3	=	0x0093
                    0094    329 Fusb_serial$P1_4$0$0 == 0x0094
                    0094    330 _P1_4	=	0x0094
                    0095    331 Fusb_serial$P1_5$0$0 == 0x0095
                    0095    332 _P1_5	=	0x0095
                    0096    333 Fusb_serial$P1_6$0$0 == 0x0096
                    0096    334 _P1_6	=	0x0096
                    0097    335 Fusb_serial$P1_7$0$0 == 0x0097
                    0097    336 _P1_7	=	0x0097
                    0098    337 Fusb_serial$ENCIF_0$0$0 == 0x0098
                    0098    338 _ENCIF_0	=	0x0098
                    0099    339 Fusb_serial$ENCIF_1$0$0 == 0x0099
                    0099    340 _ENCIF_1	=	0x0099
                    009A    341 Fusb_serial$_SOCON2$0$0 == 0x009a
                    009A    342 __SOCON2	=	0x009a
                    009B    343 Fusb_serial$_SOCON3$0$0 == 0x009b
                    009B    344 __SOCON3	=	0x009b
                    009C    345 Fusb_serial$_SOCON4$0$0 == 0x009c
                    009C    346 __SOCON4	=	0x009c
                    009D    347 Fusb_serial$_SOCON5$0$0 == 0x009d
                    009D    348 __SOCON5	=	0x009d
                    009E    349 Fusb_serial$_SOCON6$0$0 == 0x009e
                    009E    350 __SOCON6	=	0x009e
                    009F    351 Fusb_serial$_SOCON7$0$0 == 0x009f
                    009F    352 __SOCON7	=	0x009f
                    00A0    353 Fusb_serial$P2_0$0$0 == 0x00a0
                    00A0    354 _P2_0	=	0x00a0
                    00A1    355 Fusb_serial$P2_1$0$0 == 0x00a1
                    00A1    356 _P2_1	=	0x00a1
                    00A2    357 Fusb_serial$P2_2$0$0 == 0x00a2
                    00A2    358 _P2_2	=	0x00a2
                    00A3    359 Fusb_serial$P2_3$0$0 == 0x00a3
                    00A3    360 _P2_3	=	0x00a3
                    00A4    361 Fusb_serial$P2_4$0$0 == 0x00a4
                    00A4    362 _P2_4	=	0x00a4
                    00A5    363 Fusb_serial$P2_5$0$0 == 0x00a5
                    00A5    364 _P2_5	=	0x00a5
                    00A6    365 Fusb_serial$P2_6$0$0 == 0x00a6
                    00A6    366 _P2_6	=	0x00a6
                    00A7    367 Fusb_serial$P2_7$0$0 == 0x00a7
                    00A7    368 _P2_7	=	0x00a7
                    00A8    369 Fusb_serial$RFTXRXIE$0$0 == 0x00a8
                    00A8    370 _RFTXRXIE	=	0x00a8
                    00A9    371 Fusb_serial$ADCIE$0$0 == 0x00a9
                    00A9    372 _ADCIE	=	0x00a9
                    00AA    373 Fusb_serial$URX0IE$0$0 == 0x00aa
                    00AA    374 _URX0IE	=	0x00aa
                    00AB    375 Fusb_serial$URX1IE$0$0 == 0x00ab
                    00AB    376 _URX1IE	=	0x00ab
                    00AC    377 Fusb_serial$ENCIE$0$0 == 0x00ac
                    00AC    378 _ENCIE	=	0x00ac
                    00AD    379 Fusb_serial$STIE$0$0 == 0x00ad
                    00AD    380 _STIE	=	0x00ad
                    00AE    381 Fusb_serial$_IEN06$0$0 == 0x00ae
                    00AE    382 __IEN06	=	0x00ae
                    00AF    383 Fusb_serial$EA$0$0 == 0x00af
                    00AF    384 _EA	=	0x00af
                    00B8    385 Fusb_serial$DMAIE$0$0 == 0x00b8
                    00B8    386 _DMAIE	=	0x00b8
                    00B9    387 Fusb_serial$T1IE$0$0 == 0x00b9
                    00B9    388 _T1IE	=	0x00b9
                    00BA    389 Fusb_serial$T2IE$0$0 == 0x00ba
                    00BA    390 _T2IE	=	0x00ba
                    00BB    391 Fusb_serial$T3IE$0$0 == 0x00bb
                    00BB    392 _T3IE	=	0x00bb
                    00BC    393 Fusb_serial$T4IE$0$0 == 0x00bc
                    00BC    394 _T4IE	=	0x00bc
                    00BD    395 Fusb_serial$P0IE$0$0 == 0x00bd
                    00BD    396 _P0IE	=	0x00bd
                    00BE    397 Fusb_serial$_IEN16$0$0 == 0x00be
                    00BE    398 __IEN16	=	0x00be
                    00BF    399 Fusb_serial$_IEN17$0$0 == 0x00bf
                    00BF    400 __IEN17	=	0x00bf
                    00C0    401 Fusb_serial$DMAIF$0$0 == 0x00c0
                    00C0    402 _DMAIF	=	0x00c0
                    00C1    403 Fusb_serial$T1IF$0$0 == 0x00c1
                    00C1    404 _T1IF	=	0x00c1
                    00C2    405 Fusb_serial$T2IF$0$0 == 0x00c2
                    00C2    406 _T2IF	=	0x00c2
                    00C3    407 Fusb_serial$T3IF$0$0 == 0x00c3
                    00C3    408 _T3IF	=	0x00c3
                    00C4    409 Fusb_serial$T4IF$0$0 == 0x00c4
                    00C4    410 _T4IF	=	0x00c4
                    00C5    411 Fusb_serial$P0IF$0$0 == 0x00c5
                    00C5    412 _P0IF	=	0x00c5
                    00C6    413 Fusb_serial$_IRCON6$0$0 == 0x00c6
                    00C6    414 __IRCON6	=	0x00c6
                    00C7    415 Fusb_serial$STIF$0$0 == 0x00c7
                    00C7    416 _STIF	=	0x00c7
                    00D0    417 Fusb_serial$P$0$0 == 0x00d0
                    00D0    418 _P	=	0x00d0
                    00D1    419 Fusb_serial$F1$0$0 == 0x00d1
                    00D1    420 _F1	=	0x00d1
                    00D2    421 Fusb_serial$OV$0$0 == 0x00d2
                    00D2    422 _OV	=	0x00d2
                    00D3    423 Fusb_serial$RS0$0$0 == 0x00d3
                    00D3    424 _RS0	=	0x00d3
                    00D4    425 Fusb_serial$RS1$0$0 == 0x00d4
                    00D4    426 _RS1	=	0x00d4
                    00D5    427 Fusb_serial$F0$0$0 == 0x00d5
                    00D5    428 _F0	=	0x00d5
                    00D6    429 Fusb_serial$AC$0$0 == 0x00d6
                    00D6    430 _AC	=	0x00d6
                    00D7    431 Fusb_serial$CY$0$0 == 0x00d7
                    00D7    432 _CY	=	0x00d7
                    00D8    433 Fusb_serial$T3OVFIF$0$0 == 0x00d8
                    00D8    434 _T3OVFIF	=	0x00d8
                    00D9    435 Fusb_serial$T3CH0IF$0$0 == 0x00d9
                    00D9    436 _T3CH0IF	=	0x00d9
                    00DA    437 Fusb_serial$T3CH1IF$0$0 == 0x00da
                    00DA    438 _T3CH1IF	=	0x00da
                    00DB    439 Fusb_serial$T4OVFIF$0$0 == 0x00db
                    00DB    440 _T4OVFIF	=	0x00db
                    00DC    441 Fusb_serial$T4CH0IF$0$0 == 0x00dc
                    00DC    442 _T4CH0IF	=	0x00dc
                    00DD    443 Fusb_serial$T4CH1IF$0$0 == 0x00dd
                    00DD    444 _T4CH1IF	=	0x00dd
                    00DE    445 Fusb_serial$OVFIM$0$0 == 0x00de
                    00DE    446 _OVFIM	=	0x00de
                    00DF    447 Fusb_serial$_TIMIF7$0$0 == 0x00df
                    00DF    448 __TIMIF7	=	0x00df
                    00E0    449 Fusb_serial$ACC_0$0$0 == 0x00e0
                    00E0    450 _ACC_0	=	0x00e0
                    00E1    451 Fusb_serial$ACC_1$0$0 == 0x00e1
                    00E1    452 _ACC_1	=	0x00e1
                    00E2    453 Fusb_serial$ACC_2$0$0 == 0x00e2
                    00E2    454 _ACC_2	=	0x00e2
                    00E3    455 Fusb_serial$ACC_3$0$0 == 0x00e3
                    00E3    456 _ACC_3	=	0x00e3
                    00E4    457 Fusb_serial$ACC_4$0$0 == 0x00e4
                    00E4    458 _ACC_4	=	0x00e4
                    00E5    459 Fusb_serial$ACC_5$0$0 == 0x00e5
                    00E5    460 _ACC_5	=	0x00e5
                    00E6    461 Fusb_serial$ACC_6$0$0 == 0x00e6
                    00E6    462 _ACC_6	=	0x00e6
                    00E7    463 Fusb_serial$ACC_7$0$0 == 0x00e7
                    00E7    464 _ACC_7	=	0x00e7
                    00E8    465 Fusb_serial$P2IF$0$0 == 0x00e8
                    00E8    466 _P2IF	=	0x00e8
                    00E9    467 Fusb_serial$UTX0IF$0$0 == 0x00e9
                    00E9    468 _UTX0IF	=	0x00e9
                    00EA    469 Fusb_serial$UTX1IF$0$0 == 0x00ea
                    00EA    470 _UTX1IF	=	0x00ea
                    00EB    471 Fusb_serial$P1IF$0$0 == 0x00eb
                    00EB    472 _P1IF	=	0x00eb
                    00EC    473 Fusb_serial$WDTIF$0$0 == 0x00ec
                    00EC    474 _WDTIF	=	0x00ec
                    00ED    475 Fusb_serial$_IRCON25$0$0 == 0x00ed
                    00ED    476 __IRCON25	=	0x00ed
                    00EE    477 Fusb_serial$_IRCON26$0$0 == 0x00ee
                    00EE    478 __IRCON26	=	0x00ee
                    00EF    479 Fusb_serial$_IRCON27$0$0 == 0x00ef
                    00EF    480 __IRCON27	=	0x00ef
                    00F0    481 Fusb_serial$B_0$0$0 == 0x00f0
                    00F0    482 _B_0	=	0x00f0
                    00F1    483 Fusb_serial$B_1$0$0 == 0x00f1
                    00F1    484 _B_1	=	0x00f1
                    00F2    485 Fusb_serial$B_2$0$0 == 0x00f2
                    00F2    486 _B_2	=	0x00f2
                    00F3    487 Fusb_serial$B_3$0$0 == 0x00f3
                    00F3    488 _B_3	=	0x00f3
                    00F4    489 Fusb_serial$B_4$0$0 == 0x00f4
                    00F4    490 _B_4	=	0x00f4
                    00F5    491 Fusb_serial$B_5$0$0 == 0x00f5
                    00F5    492 _B_5	=	0x00f5
                    00F6    493 Fusb_serial$B_6$0$0 == 0x00f6
                    00F6    494 _B_6	=	0x00f6
                    00F7    495 Fusb_serial$B_7$0$0 == 0x00f7
                    00F7    496 _B_7	=	0x00f7
                    00F8    497 Fusb_serial$U1ACTIVE$0$0 == 0x00f8
                    00F8    498 _U1ACTIVE	=	0x00f8
                    00F9    499 Fusb_serial$U1TX_BYTE$0$0 == 0x00f9
                    00F9    500 _U1TX_BYTE	=	0x00f9
                    00FA    501 Fusb_serial$U1RX_BYTE$0$0 == 0x00fa
                    00FA    502 _U1RX_BYTE	=	0x00fa
                    00FB    503 Fusb_serial$U1ERR$0$0 == 0x00fb
                    00FB    504 _U1ERR	=	0x00fb
                    00FC    505 Fusb_serial$U1FE$0$0 == 0x00fc
                    00FC    506 _U1FE	=	0x00fc
                    00FD    507 Fusb_serial$U1SLAVE$0$0 == 0x00fd
                    00FD    508 _U1SLAVE	=	0x00fd
                    00FE    509 Fusb_serial$U1RE$0$0 == 0x00fe
                    00FE    510 _U1RE	=	0x00fe
                    00FF    511 Fusb_serial$U1MODE$0$0 == 0x00ff
                    00FF    512 _U1MODE	=	0x00ff
                            513 ;--------------------------------------------------------
                            514 ; overlayable register banks
                            515 ;--------------------------------------------------------
                            516 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     517 	.ds 8
                            518 ;--------------------------------------------------------
                            519 ; internal ram data
                            520 ;--------------------------------------------------------
                            521 	.area DSEG    (DATA)
                            522 ;--------------------------------------------------------
                            523 ; overlayable items in internal ram 
                            524 ;--------------------------------------------------------
                            525 	.area OSEG    (OVR,DATA)
                            526 ;--------------------------------------------------------
                            527 ; Stack segment in internal ram 
                            528 ;--------------------------------------------------------
                            529 	.area	SSEG	(DATA)
   0022                     530 __start__stack:
   0022                     531 	.ds	1
                            532 
                            533 ;--------------------------------------------------------
                            534 ; indirectly addressable internal ram data
                            535 ;--------------------------------------------------------
                            536 	.area ISEG    (DATA)
                            537 ;--------------------------------------------------------
                            538 ; absolute internal ram data
                            539 ;--------------------------------------------------------
                            540 	.area IABS    (ABS,DATA)
                            541 	.area IABS    (ABS,DATA)
                            542 ;--------------------------------------------------------
                            543 ; bit data
                            544 ;--------------------------------------------------------
                            545 	.area BSEG    (BIT)
                            546 ;--------------------------------------------------------
                            547 ; paged external ram data
                            548 ;--------------------------------------------------------
                            549 	.area PSEG    (PAG,XDATA)
                            550 ;--------------------------------------------------------
                            551 ; external ram data
                            552 ;--------------------------------------------------------
                            553 	.area XSEG    (XDATA)
                    DF00    554 Fusb_serial$SYNC1$0$0 == 0xdf00
                    DF00    555 _SYNC1	=	0xdf00
                    DF01    556 Fusb_serial$SYNC0$0$0 == 0xdf01
                    DF01    557 _SYNC0	=	0xdf01
                    DF02    558 Fusb_serial$PKTLEN$0$0 == 0xdf02
                    DF02    559 _PKTLEN	=	0xdf02
                    DF03    560 Fusb_serial$PKTCTRL1$0$0 == 0xdf03
                    DF03    561 _PKTCTRL1	=	0xdf03
                    DF04    562 Fusb_serial$PKTCTRL0$0$0 == 0xdf04
                    DF04    563 _PKTCTRL0	=	0xdf04
                    DF05    564 Fusb_serial$ADDR$0$0 == 0xdf05
                    DF05    565 _ADDR	=	0xdf05
                    DF06    566 Fusb_serial$CHANNR$0$0 == 0xdf06
                    DF06    567 _CHANNR	=	0xdf06
                    DF07    568 Fusb_serial$FSCTRL1$0$0 == 0xdf07
                    DF07    569 _FSCTRL1	=	0xdf07
                    DF08    570 Fusb_serial$FSCTRL0$0$0 == 0xdf08
                    DF08    571 _FSCTRL0	=	0xdf08
                    DF09    572 Fusb_serial$FREQ2$0$0 == 0xdf09
                    DF09    573 _FREQ2	=	0xdf09
                    DF0A    574 Fusb_serial$FREQ1$0$0 == 0xdf0a
                    DF0A    575 _FREQ1	=	0xdf0a
                    DF0B    576 Fusb_serial$FREQ0$0$0 == 0xdf0b
                    DF0B    577 _FREQ0	=	0xdf0b
                    DF0C    578 Fusb_serial$MDMCFG4$0$0 == 0xdf0c
                    DF0C    579 _MDMCFG4	=	0xdf0c
                    DF0D    580 Fusb_serial$MDMCFG3$0$0 == 0xdf0d
                    DF0D    581 _MDMCFG3	=	0xdf0d
                    DF0E    582 Fusb_serial$MDMCFG2$0$0 == 0xdf0e
                    DF0E    583 _MDMCFG2	=	0xdf0e
                    DF0F    584 Fusb_serial$MDMCFG1$0$0 == 0xdf0f
                    DF0F    585 _MDMCFG1	=	0xdf0f
                    DF10    586 Fusb_serial$MDMCFG0$0$0 == 0xdf10
                    DF10    587 _MDMCFG0	=	0xdf10
                    DF11    588 Fusb_serial$DEVIATN$0$0 == 0xdf11
                    DF11    589 _DEVIATN	=	0xdf11
                    DF12    590 Fusb_serial$MCSM2$0$0 == 0xdf12
                    DF12    591 _MCSM2	=	0xdf12
                    DF13    592 Fusb_serial$MCSM1$0$0 == 0xdf13
                    DF13    593 _MCSM1	=	0xdf13
                    DF14    594 Fusb_serial$MCSM0$0$0 == 0xdf14
                    DF14    595 _MCSM0	=	0xdf14
                    DF15    596 Fusb_serial$FOCCFG$0$0 == 0xdf15
                    DF15    597 _FOCCFG	=	0xdf15
                    DF16    598 Fusb_serial$BSCFG$0$0 == 0xdf16
                    DF16    599 _BSCFG	=	0xdf16
                    DF17    600 Fusb_serial$AGCCTRL2$0$0 == 0xdf17
                    DF17    601 _AGCCTRL2	=	0xdf17
                    DF18    602 Fusb_serial$AGCCTRL1$0$0 == 0xdf18
                    DF18    603 _AGCCTRL1	=	0xdf18
                    DF19    604 Fusb_serial$AGCCTRL0$0$0 == 0xdf19
                    DF19    605 _AGCCTRL0	=	0xdf19
                    DF1A    606 Fusb_serial$FREND1$0$0 == 0xdf1a
                    DF1A    607 _FREND1	=	0xdf1a
                    DF1B    608 Fusb_serial$FREND0$0$0 == 0xdf1b
                    DF1B    609 _FREND0	=	0xdf1b
                    DF1C    610 Fusb_serial$FSCAL3$0$0 == 0xdf1c
                    DF1C    611 _FSCAL3	=	0xdf1c
                    DF1D    612 Fusb_serial$FSCAL2$0$0 == 0xdf1d
                    DF1D    613 _FSCAL2	=	0xdf1d
                    DF1E    614 Fusb_serial$FSCAL1$0$0 == 0xdf1e
                    DF1E    615 _FSCAL1	=	0xdf1e
                    DF1F    616 Fusb_serial$FSCAL0$0$0 == 0xdf1f
                    DF1F    617 _FSCAL0	=	0xdf1f
                    DF23    618 Fusb_serial$TEST2$0$0 == 0xdf23
                    DF23    619 _TEST2	=	0xdf23
                    DF24    620 Fusb_serial$TEST1$0$0 == 0xdf24
                    DF24    621 _TEST1	=	0xdf24
                    DF25    622 Fusb_serial$TEST0$0$0 == 0xdf25
                    DF25    623 _TEST0	=	0xdf25
                    DF2E    624 Fusb_serial$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    625 _PA_TABLE0	=	0xdf2e
                    DF2F    626 Fusb_serial$IOCFG2$0$0 == 0xdf2f
                    DF2F    627 _IOCFG2	=	0xdf2f
                    DF30    628 Fusb_serial$IOCFG1$0$0 == 0xdf30
                    DF30    629 _IOCFG1	=	0xdf30
                    DF31    630 Fusb_serial$IOCFG0$0$0 == 0xdf31
                    DF31    631 _IOCFG0	=	0xdf31
                    DF36    632 Fusb_serial$PARTNUM$0$0 == 0xdf36
                    DF36    633 _PARTNUM	=	0xdf36
                    DF37    634 Fusb_serial$VERSION$0$0 == 0xdf37
                    DF37    635 _VERSION	=	0xdf37
                    DF38    636 Fusb_serial$FREQEST$0$0 == 0xdf38
                    DF38    637 _FREQEST	=	0xdf38
                    DF39    638 Fusb_serial$LQI$0$0 == 0xdf39
                    DF39    639 _LQI	=	0xdf39
                    DF3A    640 Fusb_serial$RSSI$0$0 == 0xdf3a
                    DF3A    641 _RSSI	=	0xdf3a
                    DF3B    642 Fusb_serial$MARCSTATE$0$0 == 0xdf3b
                    DF3B    643 _MARCSTATE	=	0xdf3b
                    DF3C    644 Fusb_serial$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    645 _PKTSTATUS	=	0xdf3c
                    DF3D    646 Fusb_serial$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    647 _VCO_VC_DAC	=	0xdf3d
                    DF40    648 Fusb_serial$I2SCFG0$0$0 == 0xdf40
                    DF40    649 _I2SCFG0	=	0xdf40
                    DF41    650 Fusb_serial$I2SCFG1$0$0 == 0xdf41
                    DF41    651 _I2SCFG1	=	0xdf41
                    DF42    652 Fusb_serial$I2SDATL$0$0 == 0xdf42
                    DF42    653 _I2SDATL	=	0xdf42
                    DF43    654 Fusb_serial$I2SDATH$0$0 == 0xdf43
                    DF43    655 _I2SDATH	=	0xdf43
                    DF44    656 Fusb_serial$I2SWCNT$0$0 == 0xdf44
                    DF44    657 _I2SWCNT	=	0xdf44
                    DF45    658 Fusb_serial$I2SSTAT$0$0 == 0xdf45
                    DF45    659 _I2SSTAT	=	0xdf45
                    DF46    660 Fusb_serial$I2SCLKF0$0$0 == 0xdf46
                    DF46    661 _I2SCLKF0	=	0xdf46
                    DF47    662 Fusb_serial$I2SCLKF1$0$0 == 0xdf47
                    DF47    663 _I2SCLKF1	=	0xdf47
                    DF48    664 Fusb_serial$I2SCLKF2$0$0 == 0xdf48
                    DF48    665 _I2SCLKF2	=	0xdf48
                    DE00    666 Fusb_serial$USBADDR$0$0 == 0xde00
                    DE00    667 _USBADDR	=	0xde00
                    DE01    668 Fusb_serial$USBPOW$0$0 == 0xde01
                    DE01    669 _USBPOW	=	0xde01
                    DE02    670 Fusb_serial$USBIIF$0$0 == 0xde02
                    DE02    671 _USBIIF	=	0xde02
                    DE04    672 Fusb_serial$USBOIF$0$0 == 0xde04
                    DE04    673 _USBOIF	=	0xde04
                    DE06    674 Fusb_serial$USBCIF$0$0 == 0xde06
                    DE06    675 _USBCIF	=	0xde06
                    DE07    676 Fusb_serial$USBIIE$0$0 == 0xde07
                    DE07    677 _USBIIE	=	0xde07
                    DE09    678 Fusb_serial$USBOIE$0$0 == 0xde09
                    DE09    679 _USBOIE	=	0xde09
                    DE0B    680 Fusb_serial$USBCIE$0$0 == 0xde0b
                    DE0B    681 _USBCIE	=	0xde0b
                    DE0C    682 Fusb_serial$USBFRML$0$0 == 0xde0c
                    DE0C    683 _USBFRML	=	0xde0c
                    DE0D    684 Fusb_serial$USBFRMH$0$0 == 0xde0d
                    DE0D    685 _USBFRMH	=	0xde0d
                    DE0E    686 Fusb_serial$USBINDEX$0$0 == 0xde0e
                    DE0E    687 _USBINDEX	=	0xde0e
                    DE10    688 Fusb_serial$USBMAXI$0$0 == 0xde10
                    DE10    689 _USBMAXI	=	0xde10
                    DE11    690 Fusb_serial$USBCSIL$0$0 == 0xde11
                    DE11    691 _USBCSIL	=	0xde11
                    DE12    692 Fusb_serial$USBCSIH$0$0 == 0xde12
                    DE12    693 _USBCSIH	=	0xde12
                    DE13    694 Fusb_serial$USBMAXO$0$0 == 0xde13
                    DE13    695 _USBMAXO	=	0xde13
                    DE14    696 Fusb_serial$USBCSOL$0$0 == 0xde14
                    DE14    697 _USBCSOL	=	0xde14
                    DE15    698 Fusb_serial$USBCSOH$0$0 == 0xde15
                    DE15    699 _USBCSOH	=	0xde15
                    DE16    700 Fusb_serial$USBCNTL$0$0 == 0xde16
                    DE16    701 _USBCNTL	=	0xde16
                    DE17    702 Fusb_serial$USBCNTH$0$0 == 0xde17
                    DE17    703 _USBCNTH	=	0xde17
                    DE20    704 Fusb_serial$USBF0$0$0 == 0xde20
                    DE20    705 _USBF0	=	0xde20
                    DE22    706 Fusb_serial$USBF1$0$0 == 0xde22
                    DE22    707 _USBF1	=	0xde22
                    DE24    708 Fusb_serial$USBF2$0$0 == 0xde24
                    DE24    709 _USBF2	=	0xde24
                    DE26    710 Fusb_serial$USBF3$0$0 == 0xde26
                    DE26    711 _USBF3	=	0xde26
                    DE28    712 Fusb_serial$USBF4$0$0 == 0xde28
                    DE28    713 _USBF4	=	0xde28
                    DE2A    714 Fusb_serial$USBF5$0$0 == 0xde2a
                    DE2A    715 _USBF5	=	0xde2a
                            716 ;--------------------------------------------------------
                            717 ; absolute external ram data
                            718 ;--------------------------------------------------------
                            719 	.area XABS    (ABS,XDATA)
                            720 ;--------------------------------------------------------
                            721 ; external initialized ram data
                            722 ;--------------------------------------------------------
                            723 	.area XISEG   (XDATA)
                            724 	.area HOME    (CODE)
                            725 	.area GSINIT0 (CODE)
                            726 	.area GSINIT1 (CODE)
                            727 	.area GSINIT2 (CODE)
                            728 	.area GSINIT3 (CODE)
                            729 	.area GSINIT4 (CODE)
                            730 	.area GSINIT5 (CODE)
                            731 	.area GSINIT  (CODE)
                            732 	.area GSFINAL (CODE)
                            733 	.area CSEG    (CODE)
                            734 ;--------------------------------------------------------
                            735 ; interrupt vector 
                            736 ;--------------------------------------------------------
                            737 	.area HOME    (CODE)
   0400                     738 __interrupt_vect:
   0400 02 04 7D            739 	ljmp	__sdcc_gsinit_startup
   0403 32                  740 	reti
   0404                     741 	.ds	7
   040B 32                  742 	reti
   040C                     743 	.ds	7
   0413 32                  744 	reti
   0414                     745 	.ds	7
   041B 02 07 E5            746 	ljmp	_ISR_URX1
   041E                     747 	.ds	5
   0423 32                  748 	reti
   0424                     749 	.ds	7
   042B 32                  750 	reti
   042C                     751 	.ds	7
   0433 32                  752 	reti
   0434                     753 	.ds	7
   043B 32                  754 	reti
   043C                     755 	.ds	7
   0443 32                  756 	reti
   0444                     757 	.ds	7
   044B 32                  758 	reti
   044C                     759 	.ds	7
   0453 32                  760 	reti
   0454                     761 	.ds	7
   045B 32                  762 	reti
   045C                     763 	.ds	7
   0463 02 14 6A            764 	ljmp	_ISR_T4
   0466                     765 	.ds	5
   046B 32                  766 	reti
   046C                     767 	.ds	7
   0473 02 07 A7            768 	ljmp	_ISR_UTX1
                            769 ;--------------------------------------------------------
                            770 ; global & static initialisations
                            771 ;--------------------------------------------------------
                            772 	.area HOME    (CODE)
                            773 	.area GSINIT  (CODE)
                            774 	.area GSFINAL (CODE)
                            775 	.area GSINIT  (CODE)
                            776 	.globl __sdcc_gsinit_startup
                            777 	.globl __sdcc_program_startup
                            778 	.globl __start__stack
                            779 	.globl __mcs51_genXINIT
                            780 	.globl __mcs51_genXRAMCLEAR
                            781 	.globl __mcs51_genRAMCLEAR
                            782 	.area GSFINAL (CODE)
   0500 02 04 76            783 	ljmp	__sdcc_program_startup
                            784 ;--------------------------------------------------------
                            785 ; Home
                            786 ;--------------------------------------------------------
                            787 	.area HOME    (CODE)
                            788 	.area HOME    (CODE)
   0476                     789 __sdcc_program_startup:
   0476 12 05 B0            790 	lcall	_main
                            791 ;	return from main will lock up
   0479 80 FE               792 	sjmp .
                            793 ;--------------------------------------------------------
                            794 ; code
                            795 ;--------------------------------------------------------
                            796 	.area CSEG    (CODE)
                            797 ;------------------------------------------------------------
                            798 ;Allocation info for local variables in function 'updateLeds'
                            799 ;------------------------------------------------------------
                    0000    800 	G$updateLeds$0$0 ==.
                    0000    801 	C$usb_serial.c$48$0$0 ==.
                            802 ;	apps/usb_serial/usb_serial.c:48: void updateLeds()
                            803 ;	-----------------------------------------
                            804 ;	 function updateLeds
                            805 ;	-----------------------------------------
   0503                     806 _updateLeds:
                    0007    807 	ar7 = 0x07
                    0006    808 	ar6 = 0x06
                    0005    809 	ar5 = 0x05
                    0004    810 	ar4 = 0x04
                    0003    811 	ar3 = 0x03
                    0002    812 	ar2 = 0x02
                    0001    813 	ar1 = 0x01
                    0000    814 	ar0 = 0x00
                    0000    815 	C$usb_serial.c$50$1$1 ==.
                            816 ;	apps/usb_serial/usb_serial.c:50: usbShowStatusWithGreenLed();
   0503 12 14 F6            817 	lcall	_usbShowStatusWithGreenLed
                    0003    818 	C$usb_serial.c$51$2$2 ==.
                            819 ;	apps/usb_serial/usb_serial.c:51: LED_YELLOW(usbComRxControlSignals() & ACM_CONTROL_LINE_DTR);
   0506 12 0A F3            820 	lcall	_usbComRxControlSignals
   0509 E5 82               821 	mov	a,dpl
   050B 30 E0 05            822 	jnb	acc.0,00103$
   050E 43 FF 04            823 	orl	_P2DIR,#0x04
   0511 80 07               824 	sjmp	00104$
   0513                     825 00103$:
   0513 AF FF               826 	mov	r7,_P2DIR
   0515 53 07 FB            827 	anl	ar7,#0xFB
   0518 8F FF               828 	mov	_P2DIR,r7
   051A                     829 00104$:
                    0017    830 	C$usb_serial.c$52$2$3 ==.
                            831 ;	apps/usb_serial/usb_serial.c:52: LED_RED(0);
   051A AF FF               832 	mov	r7,_P2DIR
   051C 53 07 FD            833 	anl	ar7,#0xFD
   051F 8F FF               834 	mov	_P2DIR,r7
                    001E    835 	C$usb_serial.c$53$2$3 ==.
                    001E    836 	XG$updateLeds$0$0 ==.
   0521 22                  837 	ret
                            838 ;------------------------------------------------------------
                            839 ;Allocation info for local variables in function 'usbToUartService'
                            840 ;------------------------------------------------------------
                    001F    841 	G$usbToUartService$0$0 ==.
                    001F    842 	C$usb_serial.c$55$2$3 ==.
                            843 ;	apps/usb_serial/usb_serial.c:55: void usbToUartService()
                            844 ;	-----------------------------------------
                            845 ;	 function usbToUartService
                            846 ;	-----------------------------------------
   0522                     847 _usbToUartService:
                    001F    848 	C$usb_serial.c$60$1$1 ==.
                            849 ;	apps/usb_serial/usb_serial.c:60: while(usbComRxAvailable() && uart1TxAvailable())
   0522                     850 00102$:
   0522 12 09 1A            851 	lcall	_usbComRxAvailable
   0525 E5 82               852 	mov	a,dpl
   0527 60 0F               853 	jz	00106$
   0529 12 07 35            854 	lcall	_uart1TxAvailable
   052C E5 82               855 	mov	a,dpl
   052E 60 08               856 	jz	00106$
                    002D    857 	C$usb_serial.c$62$2$2 ==.
                            858 ;	apps/usb_serial/usb_serial.c:62: uart1TxSendByte(usbComRxReceiveByte());
   0530 12 09 44            859 	lcall	_usbComRxReceiveByte
   0533 12 07 70            860 	lcall	_uart1TxSendByte
                    0033    861 	C$usb_serial.c$65$1$1 ==.
                            862 ;	apps/usb_serial/usb_serial.c:65: while(uart1RxAvailable() && usbComTxAvailable())
   0536 80 EA               863 	sjmp	00102$
   0538                     864 00106$:
   0538 12 07 89            865 	lcall	_uart1RxAvailable
   053B E5 82               866 	mov	a,dpl
   053D 60 0F               867 	jz	00108$
   053F 12 0A 50            868 	lcall	_usbComTxAvailable
   0542 E5 82               869 	mov	a,dpl
   0544 60 08               870 	jz	00108$
                    0043    871 	C$usb_serial.c$67$2$3 ==.
                            872 ;	apps/usb_serial/usb_serial.c:67: usbComTxSendByte(uart1RxReceiveByte());
   0546 12 07 91            873 	lcall	_uart1RxReceiveByte
   0549 12 0A E2            874 	lcall	_usbComTxSendByte
   054C 80 EA               875 	sjmp	00106$
   054E                     876 00108$:
                    004B    877 	C$usb_serial.c$71$1$1 ==.
                            878 ;	apps/usb_serial/usb_serial.c:71: P1_0 = !(usbComRxControlSignals() & ACM_CONTROL_LINE_DTR);
   054E 12 0A F3            879 	lcall	_usbComRxControlSignals
   0551 E5 82               880 	mov	a,dpl
   0553 54 01               881 	anl	a,#0x01
   0555 FF                  882 	mov	r7,a
   0556 B4 01 00            883 	cjne	a,#0x01,00127$
   0559                     884 00127$:
   0559 E4                  885 	clr	a
   055A 33                  886 	rlc	a
   055B 24 FF               887 	add	a,#0xff
   055D 92 90               888 	mov	_P1_0,c
                    005C    889 	C$usb_serial.c$72$1$1 ==.
                            890 ;	apps/usb_serial/usb_serial.c:72: P1_1 = !(usbComRxControlSignals() & ACM_CONTROL_LINE_RTS);
   055F 12 0A F3            891 	lcall	_usbComRxControlSignals
   0562 E5 82               892 	mov	a,dpl
   0564 03                  893 	rr	a
   0565 54 01               894 	anl	a,#0x01
   0567 FF                  895 	mov	r7,a
   0568 B4 01 00            896 	cjne	a,#0x01,00128$
   056B                     897 00128$:
   056B E4                  898 	clr	a
   056C 33                  899 	rlc	a
   056D 24 FF               900 	add	a,#0xff
   056F 92 91               901 	mov	_P1_1,c
                    006E    902 	C$usb_serial.c$73$1$1 ==.
                            903 ;	apps/usb_serial/usb_serial.c:73: P1DIR |= (1<<0) | (1<<1);
   0571 43 FE 03            904 	orl	_P1DIR,#0x03
                    0071    905 	C$usb_serial.c$77$1$1 ==.
                            906 ;	apps/usb_serial/usb_serial.c:77: signals = 0;
   0574 7F 00               907 	mov	r7,#0x00
                    0073    908 	C$usb_serial.c$78$1$1 ==.
                            909 ;	apps/usb_serial/usb_serial.c:78: if (!P1_2){ signals |= ACM_SERIAL_STATE_TX_CARRIER; } // TX Carrier = DSR
   0576 20 92 02            910 	jb	_P1_2,00110$
   0579 7F 02               911 	mov	r7,#0x02
   057B                     912 00110$:
                    0078    913 	C$usb_serial.c$79$1$1 ==.
                            914 ;	apps/usb_serial/usb_serial.c:79: if (!P1_3){ signals |= ACM_SERIAL_STATE_RX_CARRIER; } // RX Carrier = CD
   057B 20 93 03            915 	jb	_P1_3,00112$
   057E 43 07 01            916 	orl	ar7,#0x01
   0581                     917 00112$:
                    007E    918 	C$usb_serial.c$80$1$1 ==.
                            919 ;	apps/usb_serial/usb_serial.c:80: usbComTxControlSignals(signals);
   0581 8F 82               920 	mov	dpl,r7
   0583 12 0A F9            921 	lcall	_usbComTxControlSignals
                    0083    922 	C$usb_serial.c$81$1$1 ==.
                    0083    923 	XG$usbToUartService$0$0 ==.
   0586 22                  924 	ret
                            925 ;------------------------------------------------------------
                            926 ;Allocation info for local variables in function 'lineCodingChanged'
                            927 ;------------------------------------------------------------
                    0084    928 	G$lineCodingChanged$0$0 ==.
                    0084    929 	C$usb_serial.c$83$1$1 ==.
                            930 ;	apps/usb_serial/usb_serial.c:83: void lineCodingChanged()
                            931 ;	-----------------------------------------
                            932 ;	 function lineCodingChanged
                            933 ;	-----------------------------------------
   0587                     934 _lineCodingChanged:
                    0084    935 	C$usb_serial.c$85$1$1 ==.
                            936 ;	apps/usb_serial/usb_serial.c:85: uart1SetBaudRate(usbComLineCoding.dwDTERate);
   0587 90 F2 5E            937 	mov	dptr,#_usbComLineCoding
   058A E0                  938 	movx	a,@dptr
   058B FC                  939 	mov	r4,a
   058C A3                  940 	inc	dptr
   058D E0                  941 	movx	a,@dptr
   058E FD                  942 	mov	r5,a
   058F A3                  943 	inc	dptr
   0590 E0                  944 	movx	a,@dptr
   0591 FE                  945 	mov	r6,a
   0592 A3                  946 	inc	dptr
   0593 E0                  947 	movx	a,@dptr
   0594 8C 82               948 	mov	dpl,r4
   0596 8D 83               949 	mov	dph,r5
   0598 8E F0               950 	mov	b,r6
   059A 12 06 0A            951 	lcall	_uart1SetBaudRate
                    009A    952 	C$usb_serial.c$86$1$1 ==.
                            953 ;	apps/usb_serial/usb_serial.c:86: uart1SetParity(usbComLineCoding.bParityType);
   059D 90 F2 63            954 	mov	dptr,#(_usbComLineCoding + 0x0005)
   05A0 E0                  955 	movx	a,@dptr
   05A1 F5 82               956 	mov	dpl,a
   05A3 12 06 F5            957 	lcall	_uart1SetParity
                    00A3    958 	C$usb_serial.c$87$1$1 ==.
                            959 ;	apps/usb_serial/usb_serial.c:87: uart1SetStopBits(usbComLineCoding.bCharFormat);
   05A6 90 F2 62            960 	mov	dptr,#(_usbComLineCoding + 0x0004)
   05A9 E0                  961 	movx	a,@dptr
   05AA F5 82               962 	mov	dpl,a
   05AC 12 07 23            963 	lcall	_uart1SetStopBits
                    00AC    964 	C$usb_serial.c$88$1$1 ==.
                    00AC    965 	XG$lineCodingChanged$0$0 ==.
   05AF 22                  966 	ret
                            967 ;------------------------------------------------------------
                            968 ;Allocation info for local variables in function 'main'
                            969 ;------------------------------------------------------------
                    00AD    970 	G$main$0$0 ==.
                    00AD    971 	C$usb_serial.c$90$1$1 ==.
                            972 ;	apps/usb_serial/usb_serial.c:90: void main()
                            973 ;	-----------------------------------------
                            974 ;	 function main
                            975 ;	-----------------------------------------
   05B0                     976 _main:
                    00AD    977 	C$usb_serial.c$92$1$1 ==.
                            978 ;	apps/usb_serial/usb_serial.c:92: systemInit();
   05B0 12 12 14            979 	lcall	_systemInit
                    00B0    980 	C$usb_serial.c$93$1$1 ==.
                            981 ;	apps/usb_serial/usb_serial.c:93: usbInit();
   05B3 12 0B 0D            982 	lcall	_usbInit
                    00B3    983 	C$usb_serial.c$94$1$1 ==.
                            984 ;	apps/usb_serial/usb_serial.c:94: usbComLineCodingChangeHandler = &lineCodingChanged;
   05B6 7E 87               985 	mov	r6,#_lineCodingChanged
   05B8 7F 05               986 	mov	r7,#(_lineCodingChanged >> 8)
   05BA 78 04               987 	mov	r0,#_usbComLineCodingChangeHandler
   05BC EE                  988 	mov	a,r6
   05BD F2                  989 	movx	@r0,a
   05BE 08                  990 	inc	r0
   05BF EF                  991 	mov	a,r7
   05C0 F2                  992 	movx	@r0,a
                    00BE    993 	C$usb_serial.c$96$1$1 ==.
                            994 ;	apps/usb_serial/usb_serial.c:96: uart1Init();
   05C1 12 05 D6            995 	lcall	_uart1Init
                    00C1    996 	C$usb_serial.c$97$1$1 ==.
                            997 ;	apps/usb_serial/usb_serial.c:97: lineCodingChanged();
   05C4 12 05 87            998 	lcall	_lineCodingChanged
                    00C4    999 	C$usb_serial.c$99$1$1 ==.
                           1000 ;	apps/usb_serial/usb_serial.c:99: while(1)
   05C7                    1001 00102$:
                    00C4   1002 	C$usb_serial.c$101$2$2 ==.
                           1003 ;	apps/usb_serial/usb_serial.c:101: boardService();
   05C7 12 12 21           1004 	lcall	_boardService
                    00C7   1005 	C$usb_serial.c$102$2$2 ==.
                           1006 ;	apps/usb_serial/usb_serial.c:102: updateLeds();
   05CA 12 05 03           1007 	lcall	_updateLeds
                    00CA   1008 	C$usb_serial.c$103$2$2 ==.
                           1009 ;	apps/usb_serial/usb_serial.c:103: usbComService();
   05CD 12 09 AB           1010 	lcall	_usbComService
                    00CD   1011 	C$usb_serial.c$104$2$2 ==.
                           1012 ;	apps/usb_serial/usb_serial.c:104: usbToUartService();
   05D0 12 05 22           1013 	lcall	_usbToUartService
   05D3 80 F2              1014 	sjmp	00102$
                    00D2   1015 	C$usb_serial.c$106$1$1 ==.
                    00D2   1016 	XG$main$0$0 ==.
   05D5 22                 1017 	ret
                           1018 	.area CSEG    (CODE)
                           1019 	.area CONST   (CODE)
                           1020 	.area XINIT   (CODE)
                           1021 	.area CABS    (ABS,CODE)
