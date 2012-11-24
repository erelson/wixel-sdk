                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:07 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_radio_link
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _handleCommands
                             14 	.globl _radioToUsb
                             15 	.globl _nibbleToAscii
                             16 	.globl _updateLeds
                             17 	.globl _sprintf
                             18 	.globl _radioLinkConnected
                             19 	.globl _radioLinkRxDoneWithPacket
                             20 	.globl _radioLinkRxCurrentPayloadType
                             21 	.globl _radioLinkRxCurrentPacket
                             22 	.globl _radioLinkTxSendPacket
                             23 	.globl _radioLinkTxCurrentPacket
                             24 	.globl _radioLinkInit
                             25 	.globl _usbComTxSend
                             26 	.globl _usbComTxAvailable
                             27 	.globl _usbComRxReceiveByte
                             28 	.globl _usbComRxAvailable
                             29 	.globl _usbComService
                             30 	.globl _usbShowStatusWithGreenLed
                             31 	.globl _usbInit
                             32 	.globl _randomSeedFromAdc
                             33 	.globl _boardService
                             34 	.globl _systemInit
                             35 ;--------------------------------------------------------
                             36 ; special function registers
                             37 ;--------------------------------------------------------
                             38 	.area RSEG    (ABS,DATA)
   0000                      39 	.org 0x0000
                    0080     40 Ftest_radio_link$P0$0$0 == 0x0080
                    0080     41 _P0	=	0x0080
                    0081     42 Ftest_radio_link$SP$0$0 == 0x0081
                    0081     43 _SP	=	0x0081
                    0082     44 Ftest_radio_link$DPL0$0$0 == 0x0082
                    0082     45 _DPL0	=	0x0082
                    0083     46 Ftest_radio_link$DPH0$0$0 == 0x0083
                    0083     47 _DPH0	=	0x0083
                    0084     48 Ftest_radio_link$DPL1$0$0 == 0x0084
                    0084     49 _DPL1	=	0x0084
                    0085     50 Ftest_radio_link$DPH1$0$0 == 0x0085
                    0085     51 _DPH1	=	0x0085
                    0086     52 Ftest_radio_link$U0CSR$0$0 == 0x0086
                    0086     53 _U0CSR	=	0x0086
                    0087     54 Ftest_radio_link$PCON$0$0 == 0x0087
                    0087     55 _PCON	=	0x0087
                    0088     56 Ftest_radio_link$TCON$0$0 == 0x0088
                    0088     57 _TCON	=	0x0088
                    0089     58 Ftest_radio_link$P0IFG$0$0 == 0x0089
                    0089     59 _P0IFG	=	0x0089
                    008A     60 Ftest_radio_link$P1IFG$0$0 == 0x008a
                    008A     61 _P1IFG	=	0x008a
                    008B     62 Ftest_radio_link$P2IFG$0$0 == 0x008b
                    008B     63 _P2IFG	=	0x008b
                    008C     64 Ftest_radio_link$PICTL$0$0 == 0x008c
                    008C     65 _PICTL	=	0x008c
                    008D     66 Ftest_radio_link$P1IEN$0$0 == 0x008d
                    008D     67 _P1IEN	=	0x008d
                    008F     68 Ftest_radio_link$P0INP$0$0 == 0x008f
                    008F     69 _P0INP	=	0x008f
                    0090     70 Ftest_radio_link$P1$0$0 == 0x0090
                    0090     71 _P1	=	0x0090
                    0091     72 Ftest_radio_link$RFIM$0$0 == 0x0091
                    0091     73 _RFIM	=	0x0091
                    0092     74 Ftest_radio_link$DPS$0$0 == 0x0092
                    0092     75 _DPS	=	0x0092
                    0093     76 Ftest_radio_link$MPAGE$0$0 == 0x0093
                    0093     77 _MPAGE	=	0x0093
                    0095     78 Ftest_radio_link$ENDIAN$0$0 == 0x0095
                    0095     79 _ENDIAN	=	0x0095
                    0098     80 Ftest_radio_link$S0CON$0$0 == 0x0098
                    0098     81 _S0CON	=	0x0098
                    009A     82 Ftest_radio_link$IEN2$0$0 == 0x009a
                    009A     83 _IEN2	=	0x009a
                    009B     84 Ftest_radio_link$S1CON$0$0 == 0x009b
                    009B     85 _S1CON	=	0x009b
                    009C     86 Ftest_radio_link$T2CT$0$0 == 0x009c
                    009C     87 _T2CT	=	0x009c
                    009D     88 Ftest_radio_link$T2PR$0$0 == 0x009d
                    009D     89 _T2PR	=	0x009d
                    009E     90 Ftest_radio_link$T2CTL$0$0 == 0x009e
                    009E     91 _T2CTL	=	0x009e
                    00A0     92 Ftest_radio_link$P2$0$0 == 0x00a0
                    00A0     93 _P2	=	0x00a0
                    00A1     94 Ftest_radio_link$WORIRQ$0$0 == 0x00a1
                    00A1     95 _WORIRQ	=	0x00a1
                    00A2     96 Ftest_radio_link$WORCTRL$0$0 == 0x00a2
                    00A2     97 _WORCTRL	=	0x00a2
                    00A3     98 Ftest_radio_link$WOREVT0$0$0 == 0x00a3
                    00A3     99 _WOREVT0	=	0x00a3
                    00A4    100 Ftest_radio_link$WOREVT1$0$0 == 0x00a4
                    00A4    101 _WOREVT1	=	0x00a4
                    00A5    102 Ftest_radio_link$WORTIME0$0$0 == 0x00a5
                    00A5    103 _WORTIME0	=	0x00a5
                    00A6    104 Ftest_radio_link$WORTIME1$0$0 == 0x00a6
                    00A6    105 _WORTIME1	=	0x00a6
                    00A8    106 Ftest_radio_link$IEN0$0$0 == 0x00a8
                    00A8    107 _IEN0	=	0x00a8
                    00A9    108 Ftest_radio_link$IP0$0$0 == 0x00a9
                    00A9    109 _IP0	=	0x00a9
                    00AB    110 Ftest_radio_link$FWT$0$0 == 0x00ab
                    00AB    111 _FWT	=	0x00ab
                    00AC    112 Ftest_radio_link$FADDRL$0$0 == 0x00ac
                    00AC    113 _FADDRL	=	0x00ac
                    00AD    114 Ftest_radio_link$FADDRH$0$0 == 0x00ad
                    00AD    115 _FADDRH	=	0x00ad
                    00AE    116 Ftest_radio_link$FCTL$0$0 == 0x00ae
                    00AE    117 _FCTL	=	0x00ae
                    00AF    118 Ftest_radio_link$FWDATA$0$0 == 0x00af
                    00AF    119 _FWDATA	=	0x00af
                    00B1    120 Ftest_radio_link$ENCDI$0$0 == 0x00b1
                    00B1    121 _ENCDI	=	0x00b1
                    00B2    122 Ftest_radio_link$ENCDO$0$0 == 0x00b2
                    00B2    123 _ENCDO	=	0x00b2
                    00B3    124 Ftest_radio_link$ENCCS$0$0 == 0x00b3
                    00B3    125 _ENCCS	=	0x00b3
                    00B4    126 Ftest_radio_link$ADCCON1$0$0 == 0x00b4
                    00B4    127 _ADCCON1	=	0x00b4
                    00B5    128 Ftest_radio_link$ADCCON2$0$0 == 0x00b5
                    00B5    129 _ADCCON2	=	0x00b5
                    00B6    130 Ftest_radio_link$ADCCON3$0$0 == 0x00b6
                    00B6    131 _ADCCON3	=	0x00b6
                    00B8    132 Ftest_radio_link$IEN1$0$0 == 0x00b8
                    00B8    133 _IEN1	=	0x00b8
                    00B9    134 Ftest_radio_link$IP1$0$0 == 0x00b9
                    00B9    135 _IP1	=	0x00b9
                    00BA    136 Ftest_radio_link$ADCL$0$0 == 0x00ba
                    00BA    137 _ADCL	=	0x00ba
                    00BB    138 Ftest_radio_link$ADCH$0$0 == 0x00bb
                    00BB    139 _ADCH	=	0x00bb
                    00BC    140 Ftest_radio_link$RNDL$0$0 == 0x00bc
                    00BC    141 _RNDL	=	0x00bc
                    00BD    142 Ftest_radio_link$RNDH$0$0 == 0x00bd
                    00BD    143 _RNDH	=	0x00bd
                    00BE    144 Ftest_radio_link$SLEEP$0$0 == 0x00be
                    00BE    145 _SLEEP	=	0x00be
                    00C0    146 Ftest_radio_link$IRCON$0$0 == 0x00c0
                    00C0    147 _IRCON	=	0x00c0
                    00C1    148 Ftest_radio_link$U0DBUF$0$0 == 0x00c1
                    00C1    149 _U0DBUF	=	0x00c1
                    00C2    150 Ftest_radio_link$U0BAUD$0$0 == 0x00c2
                    00C2    151 _U0BAUD	=	0x00c2
                    00C4    152 Ftest_radio_link$U0UCR$0$0 == 0x00c4
                    00C4    153 _U0UCR	=	0x00c4
                    00C5    154 Ftest_radio_link$U0GCR$0$0 == 0x00c5
                    00C5    155 _U0GCR	=	0x00c5
                    00C6    156 Ftest_radio_link$CLKCON$0$0 == 0x00c6
                    00C6    157 _CLKCON	=	0x00c6
                    00C7    158 Ftest_radio_link$MEMCTR$0$0 == 0x00c7
                    00C7    159 _MEMCTR	=	0x00c7
                    00C9    160 Ftest_radio_link$WDCTL$0$0 == 0x00c9
                    00C9    161 _WDCTL	=	0x00c9
                    00CA    162 Ftest_radio_link$T3CNT$0$0 == 0x00ca
                    00CA    163 _T3CNT	=	0x00ca
                    00CB    164 Ftest_radio_link$T3CTL$0$0 == 0x00cb
                    00CB    165 _T3CTL	=	0x00cb
                    00CC    166 Ftest_radio_link$T3CCTL0$0$0 == 0x00cc
                    00CC    167 _T3CCTL0	=	0x00cc
                    00CD    168 Ftest_radio_link$T3CC0$0$0 == 0x00cd
                    00CD    169 _T3CC0	=	0x00cd
                    00CE    170 Ftest_radio_link$T3CCTL1$0$0 == 0x00ce
                    00CE    171 _T3CCTL1	=	0x00ce
                    00CF    172 Ftest_radio_link$T3CC1$0$0 == 0x00cf
                    00CF    173 _T3CC1	=	0x00cf
                    00D0    174 Ftest_radio_link$PSW$0$0 == 0x00d0
                    00D0    175 _PSW	=	0x00d0
                    00D1    176 Ftest_radio_link$DMAIRQ$0$0 == 0x00d1
                    00D1    177 _DMAIRQ	=	0x00d1
                    00D2    178 Ftest_radio_link$DMA1CFGL$0$0 == 0x00d2
                    00D2    179 _DMA1CFGL	=	0x00d2
                    00D3    180 Ftest_radio_link$DMA1CFGH$0$0 == 0x00d3
                    00D3    181 _DMA1CFGH	=	0x00d3
                    00D4    182 Ftest_radio_link$DMA0CFGL$0$0 == 0x00d4
                    00D4    183 _DMA0CFGL	=	0x00d4
                    00D5    184 Ftest_radio_link$DMA0CFGH$0$0 == 0x00d5
                    00D5    185 _DMA0CFGH	=	0x00d5
                    00D6    186 Ftest_radio_link$DMAARM$0$0 == 0x00d6
                    00D6    187 _DMAARM	=	0x00d6
                    00D7    188 Ftest_radio_link$DMAREQ$0$0 == 0x00d7
                    00D7    189 _DMAREQ	=	0x00d7
                    00D8    190 Ftest_radio_link$TIMIF$0$0 == 0x00d8
                    00D8    191 _TIMIF	=	0x00d8
                    00D9    192 Ftest_radio_link$RFD$0$0 == 0x00d9
                    00D9    193 _RFD	=	0x00d9
                    00DA    194 Ftest_radio_link$T1CC0L$0$0 == 0x00da
                    00DA    195 _T1CC0L	=	0x00da
                    00DB    196 Ftest_radio_link$T1CC0H$0$0 == 0x00db
                    00DB    197 _T1CC0H	=	0x00db
                    00DC    198 Ftest_radio_link$T1CC1L$0$0 == 0x00dc
                    00DC    199 _T1CC1L	=	0x00dc
                    00DD    200 Ftest_radio_link$T1CC1H$0$0 == 0x00dd
                    00DD    201 _T1CC1H	=	0x00dd
                    00DE    202 Ftest_radio_link$T1CC2L$0$0 == 0x00de
                    00DE    203 _T1CC2L	=	0x00de
                    00DF    204 Ftest_radio_link$T1CC2H$0$0 == 0x00df
                    00DF    205 _T1CC2H	=	0x00df
                    00E0    206 Ftest_radio_link$ACC$0$0 == 0x00e0
                    00E0    207 _ACC	=	0x00e0
                    00E1    208 Ftest_radio_link$RFST$0$0 == 0x00e1
                    00E1    209 _RFST	=	0x00e1
                    00E2    210 Ftest_radio_link$T1CNTL$0$0 == 0x00e2
                    00E2    211 _T1CNTL	=	0x00e2
                    00E3    212 Ftest_radio_link$T1CNTH$0$0 == 0x00e3
                    00E3    213 _T1CNTH	=	0x00e3
                    00E4    214 Ftest_radio_link$T1CTL$0$0 == 0x00e4
                    00E4    215 _T1CTL	=	0x00e4
                    00E5    216 Ftest_radio_link$T1CCTL0$0$0 == 0x00e5
                    00E5    217 _T1CCTL0	=	0x00e5
                    00E6    218 Ftest_radio_link$T1CCTL1$0$0 == 0x00e6
                    00E6    219 _T1CCTL1	=	0x00e6
                    00E7    220 Ftest_radio_link$T1CCTL2$0$0 == 0x00e7
                    00E7    221 _T1CCTL2	=	0x00e7
                    00E8    222 Ftest_radio_link$IRCON2$0$0 == 0x00e8
                    00E8    223 _IRCON2	=	0x00e8
                    00E9    224 Ftest_radio_link$RFIF$0$0 == 0x00e9
                    00E9    225 _RFIF	=	0x00e9
                    00EA    226 Ftest_radio_link$T4CNT$0$0 == 0x00ea
                    00EA    227 _T4CNT	=	0x00ea
                    00EB    228 Ftest_radio_link$T4CTL$0$0 == 0x00eb
                    00EB    229 _T4CTL	=	0x00eb
                    00EC    230 Ftest_radio_link$T4CCTL0$0$0 == 0x00ec
                    00EC    231 _T4CCTL0	=	0x00ec
                    00ED    232 Ftest_radio_link$T4CC0$0$0 == 0x00ed
                    00ED    233 _T4CC0	=	0x00ed
                    00EE    234 Ftest_radio_link$T4CCTL1$0$0 == 0x00ee
                    00EE    235 _T4CCTL1	=	0x00ee
                    00EF    236 Ftest_radio_link$T4CC1$0$0 == 0x00ef
                    00EF    237 _T4CC1	=	0x00ef
                    00F0    238 Ftest_radio_link$B$0$0 == 0x00f0
                    00F0    239 _B	=	0x00f0
                    00F1    240 Ftest_radio_link$PERCFG$0$0 == 0x00f1
                    00F1    241 _PERCFG	=	0x00f1
                    00F2    242 Ftest_radio_link$ADCCFG$0$0 == 0x00f2
                    00F2    243 _ADCCFG	=	0x00f2
                    00F3    244 Ftest_radio_link$P0SEL$0$0 == 0x00f3
                    00F3    245 _P0SEL	=	0x00f3
                    00F4    246 Ftest_radio_link$P1SEL$0$0 == 0x00f4
                    00F4    247 _P1SEL	=	0x00f4
                    00F5    248 Ftest_radio_link$P2SEL$0$0 == 0x00f5
                    00F5    249 _P2SEL	=	0x00f5
                    00F6    250 Ftest_radio_link$P1INP$0$0 == 0x00f6
                    00F6    251 _P1INP	=	0x00f6
                    00F7    252 Ftest_radio_link$P2INP$0$0 == 0x00f7
                    00F7    253 _P2INP	=	0x00f7
                    00F8    254 Ftest_radio_link$U1CSR$0$0 == 0x00f8
                    00F8    255 _U1CSR	=	0x00f8
                    00F9    256 Ftest_radio_link$U1DBUF$0$0 == 0x00f9
                    00F9    257 _U1DBUF	=	0x00f9
                    00FA    258 Ftest_radio_link$U1BAUD$0$0 == 0x00fa
                    00FA    259 _U1BAUD	=	0x00fa
                    00FB    260 Ftest_radio_link$U1UCR$0$0 == 0x00fb
                    00FB    261 _U1UCR	=	0x00fb
                    00FC    262 Ftest_radio_link$U1GCR$0$0 == 0x00fc
                    00FC    263 _U1GCR	=	0x00fc
                    00FD    264 Ftest_radio_link$P0DIR$0$0 == 0x00fd
                    00FD    265 _P0DIR	=	0x00fd
                    00FE    266 Ftest_radio_link$P1DIR$0$0 == 0x00fe
                    00FE    267 _P1DIR	=	0x00fe
                    00FF    268 Ftest_radio_link$P2DIR$0$0 == 0x00ff
                    00FF    269 _P2DIR	=	0x00ff
                    FFFFD5D4    270 Ftest_radio_link$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    271 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    272 Ftest_radio_link$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    273 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    274 Ftest_radio_link$FADDR$0$0 == 0xffffadac
                    FFFFADAC    275 _FADDR	=	0xffffadac
                    FFFFBBBA    276 Ftest_radio_link$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    277 _ADC	=	0xffffbbba
                    FFFFDBDA    278 Ftest_radio_link$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    279 _T1CC0	=	0xffffdbda
                    FFFFDDDC    280 Ftest_radio_link$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    281 _T1CC1	=	0xffffdddc
                    FFFFDFDE    282 Ftest_radio_link$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    283 _T1CC2	=	0xffffdfde
                            284 ;--------------------------------------------------------
                            285 ; special function bits
                            286 ;--------------------------------------------------------
                            287 	.area RSEG    (ABS,DATA)
   0000                     288 	.org 0x0000
                    0080    289 Ftest_radio_link$P0_0$0$0 == 0x0080
                    0080    290 _P0_0	=	0x0080
                    0081    291 Ftest_radio_link$P0_1$0$0 == 0x0081
                    0081    292 _P0_1	=	0x0081
                    0082    293 Ftest_radio_link$P0_2$0$0 == 0x0082
                    0082    294 _P0_2	=	0x0082
                    0083    295 Ftest_radio_link$P0_3$0$0 == 0x0083
                    0083    296 _P0_3	=	0x0083
                    0084    297 Ftest_radio_link$P0_4$0$0 == 0x0084
                    0084    298 _P0_4	=	0x0084
                    0085    299 Ftest_radio_link$P0_5$0$0 == 0x0085
                    0085    300 _P0_5	=	0x0085
                    0086    301 Ftest_radio_link$P0_6$0$0 == 0x0086
                    0086    302 _P0_6	=	0x0086
                    0087    303 Ftest_radio_link$P0_7$0$0 == 0x0087
                    0087    304 _P0_7	=	0x0087
                    0088    305 Ftest_radio_link$_TCON_0$0$0 == 0x0088
                    0088    306 __TCON_0	=	0x0088
                    0089    307 Ftest_radio_link$RFTXRXIF$0$0 == 0x0089
                    0089    308 _RFTXRXIF	=	0x0089
                    008A    309 Ftest_radio_link$_TCON_2$0$0 == 0x008a
                    008A    310 __TCON_2	=	0x008a
                    008B    311 Ftest_radio_link$URX0IF$0$0 == 0x008b
                    008B    312 _URX0IF	=	0x008b
                    008C    313 Ftest_radio_link$_TCON_4$0$0 == 0x008c
                    008C    314 __TCON_4	=	0x008c
                    008D    315 Ftest_radio_link$ADCIF$0$0 == 0x008d
                    008D    316 _ADCIF	=	0x008d
                    008E    317 Ftest_radio_link$_TCON_6$0$0 == 0x008e
                    008E    318 __TCON_6	=	0x008e
                    008F    319 Ftest_radio_link$URX1IF$0$0 == 0x008f
                    008F    320 _URX1IF	=	0x008f
                    0090    321 Ftest_radio_link$P1_0$0$0 == 0x0090
                    0090    322 _P1_0	=	0x0090
                    0091    323 Ftest_radio_link$P1_1$0$0 == 0x0091
                    0091    324 _P1_1	=	0x0091
                    0092    325 Ftest_radio_link$P1_2$0$0 == 0x0092
                    0092    326 _P1_2	=	0x0092
                    0093    327 Ftest_radio_link$P1_3$0$0 == 0x0093
                    0093    328 _P1_3	=	0x0093
                    0094    329 Ftest_radio_link$P1_4$0$0 == 0x0094
                    0094    330 _P1_4	=	0x0094
                    0095    331 Ftest_radio_link$P1_5$0$0 == 0x0095
                    0095    332 _P1_5	=	0x0095
                    0096    333 Ftest_radio_link$P1_6$0$0 == 0x0096
                    0096    334 _P1_6	=	0x0096
                    0097    335 Ftest_radio_link$P1_7$0$0 == 0x0097
                    0097    336 _P1_7	=	0x0097
                    0098    337 Ftest_radio_link$ENCIF_0$0$0 == 0x0098
                    0098    338 _ENCIF_0	=	0x0098
                    0099    339 Ftest_radio_link$ENCIF_1$0$0 == 0x0099
                    0099    340 _ENCIF_1	=	0x0099
                    009A    341 Ftest_radio_link$_SOCON2$0$0 == 0x009a
                    009A    342 __SOCON2	=	0x009a
                    009B    343 Ftest_radio_link$_SOCON3$0$0 == 0x009b
                    009B    344 __SOCON3	=	0x009b
                    009C    345 Ftest_radio_link$_SOCON4$0$0 == 0x009c
                    009C    346 __SOCON4	=	0x009c
                    009D    347 Ftest_radio_link$_SOCON5$0$0 == 0x009d
                    009D    348 __SOCON5	=	0x009d
                    009E    349 Ftest_radio_link$_SOCON6$0$0 == 0x009e
                    009E    350 __SOCON6	=	0x009e
                    009F    351 Ftest_radio_link$_SOCON7$0$0 == 0x009f
                    009F    352 __SOCON7	=	0x009f
                    00A0    353 Ftest_radio_link$P2_0$0$0 == 0x00a0
                    00A0    354 _P2_0	=	0x00a0
                    00A1    355 Ftest_radio_link$P2_1$0$0 == 0x00a1
                    00A1    356 _P2_1	=	0x00a1
                    00A2    357 Ftest_radio_link$P2_2$0$0 == 0x00a2
                    00A2    358 _P2_2	=	0x00a2
                    00A3    359 Ftest_radio_link$P2_3$0$0 == 0x00a3
                    00A3    360 _P2_3	=	0x00a3
                    00A4    361 Ftest_radio_link$P2_4$0$0 == 0x00a4
                    00A4    362 _P2_4	=	0x00a4
                    00A5    363 Ftest_radio_link$P2_5$0$0 == 0x00a5
                    00A5    364 _P2_5	=	0x00a5
                    00A6    365 Ftest_radio_link$P2_6$0$0 == 0x00a6
                    00A6    366 _P2_6	=	0x00a6
                    00A7    367 Ftest_radio_link$P2_7$0$0 == 0x00a7
                    00A7    368 _P2_7	=	0x00a7
                    00A8    369 Ftest_radio_link$RFTXRXIE$0$0 == 0x00a8
                    00A8    370 _RFTXRXIE	=	0x00a8
                    00A9    371 Ftest_radio_link$ADCIE$0$0 == 0x00a9
                    00A9    372 _ADCIE	=	0x00a9
                    00AA    373 Ftest_radio_link$URX0IE$0$0 == 0x00aa
                    00AA    374 _URX0IE	=	0x00aa
                    00AB    375 Ftest_radio_link$URX1IE$0$0 == 0x00ab
                    00AB    376 _URX1IE	=	0x00ab
                    00AC    377 Ftest_radio_link$ENCIE$0$0 == 0x00ac
                    00AC    378 _ENCIE	=	0x00ac
                    00AD    379 Ftest_radio_link$STIE$0$0 == 0x00ad
                    00AD    380 _STIE	=	0x00ad
                    00AE    381 Ftest_radio_link$_IEN06$0$0 == 0x00ae
                    00AE    382 __IEN06	=	0x00ae
                    00AF    383 Ftest_radio_link$EA$0$0 == 0x00af
                    00AF    384 _EA	=	0x00af
                    00B8    385 Ftest_radio_link$DMAIE$0$0 == 0x00b8
                    00B8    386 _DMAIE	=	0x00b8
                    00B9    387 Ftest_radio_link$T1IE$0$0 == 0x00b9
                    00B9    388 _T1IE	=	0x00b9
                    00BA    389 Ftest_radio_link$T2IE$0$0 == 0x00ba
                    00BA    390 _T2IE	=	0x00ba
                    00BB    391 Ftest_radio_link$T3IE$0$0 == 0x00bb
                    00BB    392 _T3IE	=	0x00bb
                    00BC    393 Ftest_radio_link$T4IE$0$0 == 0x00bc
                    00BC    394 _T4IE	=	0x00bc
                    00BD    395 Ftest_radio_link$P0IE$0$0 == 0x00bd
                    00BD    396 _P0IE	=	0x00bd
                    00BE    397 Ftest_radio_link$_IEN16$0$0 == 0x00be
                    00BE    398 __IEN16	=	0x00be
                    00BF    399 Ftest_radio_link$_IEN17$0$0 == 0x00bf
                    00BF    400 __IEN17	=	0x00bf
                    00C0    401 Ftest_radio_link$DMAIF$0$0 == 0x00c0
                    00C0    402 _DMAIF	=	0x00c0
                    00C1    403 Ftest_radio_link$T1IF$0$0 == 0x00c1
                    00C1    404 _T1IF	=	0x00c1
                    00C2    405 Ftest_radio_link$T2IF$0$0 == 0x00c2
                    00C2    406 _T2IF	=	0x00c2
                    00C3    407 Ftest_radio_link$T3IF$0$0 == 0x00c3
                    00C3    408 _T3IF	=	0x00c3
                    00C4    409 Ftest_radio_link$T4IF$0$0 == 0x00c4
                    00C4    410 _T4IF	=	0x00c4
                    00C5    411 Ftest_radio_link$P0IF$0$0 == 0x00c5
                    00C5    412 _P0IF	=	0x00c5
                    00C6    413 Ftest_radio_link$_IRCON6$0$0 == 0x00c6
                    00C6    414 __IRCON6	=	0x00c6
                    00C7    415 Ftest_radio_link$STIF$0$0 == 0x00c7
                    00C7    416 _STIF	=	0x00c7
                    00D0    417 Ftest_radio_link$P$0$0 == 0x00d0
                    00D0    418 _P	=	0x00d0
                    00D1    419 Ftest_radio_link$F1$0$0 == 0x00d1
                    00D1    420 _F1	=	0x00d1
                    00D2    421 Ftest_radio_link$OV$0$0 == 0x00d2
                    00D2    422 _OV	=	0x00d2
                    00D3    423 Ftest_radio_link$RS0$0$0 == 0x00d3
                    00D3    424 _RS0	=	0x00d3
                    00D4    425 Ftest_radio_link$RS1$0$0 == 0x00d4
                    00D4    426 _RS1	=	0x00d4
                    00D5    427 Ftest_radio_link$F0$0$0 == 0x00d5
                    00D5    428 _F0	=	0x00d5
                    00D6    429 Ftest_radio_link$AC$0$0 == 0x00d6
                    00D6    430 _AC	=	0x00d6
                    00D7    431 Ftest_radio_link$CY$0$0 == 0x00d7
                    00D7    432 _CY	=	0x00d7
                    00D8    433 Ftest_radio_link$T3OVFIF$0$0 == 0x00d8
                    00D8    434 _T3OVFIF	=	0x00d8
                    00D9    435 Ftest_radio_link$T3CH0IF$0$0 == 0x00d9
                    00D9    436 _T3CH0IF	=	0x00d9
                    00DA    437 Ftest_radio_link$T3CH1IF$0$0 == 0x00da
                    00DA    438 _T3CH1IF	=	0x00da
                    00DB    439 Ftest_radio_link$T4OVFIF$0$0 == 0x00db
                    00DB    440 _T4OVFIF	=	0x00db
                    00DC    441 Ftest_radio_link$T4CH0IF$0$0 == 0x00dc
                    00DC    442 _T4CH0IF	=	0x00dc
                    00DD    443 Ftest_radio_link$T4CH1IF$0$0 == 0x00dd
                    00DD    444 _T4CH1IF	=	0x00dd
                    00DE    445 Ftest_radio_link$OVFIM$0$0 == 0x00de
                    00DE    446 _OVFIM	=	0x00de
                    00DF    447 Ftest_radio_link$_TIMIF7$0$0 == 0x00df
                    00DF    448 __TIMIF7	=	0x00df
                    00E0    449 Ftest_radio_link$ACC_0$0$0 == 0x00e0
                    00E0    450 _ACC_0	=	0x00e0
                    00E1    451 Ftest_radio_link$ACC_1$0$0 == 0x00e1
                    00E1    452 _ACC_1	=	0x00e1
                    00E2    453 Ftest_radio_link$ACC_2$0$0 == 0x00e2
                    00E2    454 _ACC_2	=	0x00e2
                    00E3    455 Ftest_radio_link$ACC_3$0$0 == 0x00e3
                    00E3    456 _ACC_3	=	0x00e3
                    00E4    457 Ftest_radio_link$ACC_4$0$0 == 0x00e4
                    00E4    458 _ACC_4	=	0x00e4
                    00E5    459 Ftest_radio_link$ACC_5$0$0 == 0x00e5
                    00E5    460 _ACC_5	=	0x00e5
                    00E6    461 Ftest_radio_link$ACC_6$0$0 == 0x00e6
                    00E6    462 _ACC_6	=	0x00e6
                    00E7    463 Ftest_radio_link$ACC_7$0$0 == 0x00e7
                    00E7    464 _ACC_7	=	0x00e7
                    00E8    465 Ftest_radio_link$P2IF$0$0 == 0x00e8
                    00E8    466 _P2IF	=	0x00e8
                    00E9    467 Ftest_radio_link$UTX0IF$0$0 == 0x00e9
                    00E9    468 _UTX0IF	=	0x00e9
                    00EA    469 Ftest_radio_link$UTX1IF$0$0 == 0x00ea
                    00EA    470 _UTX1IF	=	0x00ea
                    00EB    471 Ftest_radio_link$P1IF$0$0 == 0x00eb
                    00EB    472 _P1IF	=	0x00eb
                    00EC    473 Ftest_radio_link$WDTIF$0$0 == 0x00ec
                    00EC    474 _WDTIF	=	0x00ec
                    00ED    475 Ftest_radio_link$_IRCON25$0$0 == 0x00ed
                    00ED    476 __IRCON25	=	0x00ed
                    00EE    477 Ftest_radio_link$_IRCON26$0$0 == 0x00ee
                    00EE    478 __IRCON26	=	0x00ee
                    00EF    479 Ftest_radio_link$_IRCON27$0$0 == 0x00ef
                    00EF    480 __IRCON27	=	0x00ef
                    00F0    481 Ftest_radio_link$B_0$0$0 == 0x00f0
                    00F0    482 _B_0	=	0x00f0
                    00F1    483 Ftest_radio_link$B_1$0$0 == 0x00f1
                    00F1    484 _B_1	=	0x00f1
                    00F2    485 Ftest_radio_link$B_2$0$0 == 0x00f2
                    00F2    486 _B_2	=	0x00f2
                    00F3    487 Ftest_radio_link$B_3$0$0 == 0x00f3
                    00F3    488 _B_3	=	0x00f3
                    00F4    489 Ftest_radio_link$B_4$0$0 == 0x00f4
                    00F4    490 _B_4	=	0x00f4
                    00F5    491 Ftest_radio_link$B_5$0$0 == 0x00f5
                    00F5    492 _B_5	=	0x00f5
                    00F6    493 Ftest_radio_link$B_6$0$0 == 0x00f6
                    00F6    494 _B_6	=	0x00f6
                    00F7    495 Ftest_radio_link$B_7$0$0 == 0x00f7
                    00F7    496 _B_7	=	0x00f7
                    00F8    497 Ftest_radio_link$U1ACTIVE$0$0 == 0x00f8
                    00F8    498 _U1ACTIVE	=	0x00f8
                    00F9    499 Ftest_radio_link$U1TX_BYTE$0$0 == 0x00f9
                    00F9    500 _U1TX_BYTE	=	0x00f9
                    00FA    501 Ftest_radio_link$U1RX_BYTE$0$0 == 0x00fa
                    00FA    502 _U1RX_BYTE	=	0x00fa
                    00FB    503 Ftest_radio_link$U1ERR$0$0 == 0x00fb
                    00FB    504 _U1ERR	=	0x00fb
                    00FC    505 Ftest_radio_link$U1FE$0$0 == 0x00fc
                    00FC    506 _U1FE	=	0x00fc
                    00FD    507 Ftest_radio_link$U1SLAVE$0$0 == 0x00fd
                    00FD    508 _U1SLAVE	=	0x00fd
                    00FE    509 Ftest_radio_link$U1RE$0$0 == 0x00fe
                    00FE    510 _U1RE	=	0x00fe
                    00FF    511 Ftest_radio_link$U1MODE$0$0 == 0x00ff
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
                    0000    522 Ltest_radio_link.handleCommands$sloc0$1$0==.
   0008                     523 _handleCommands_sloc0_1_0:
   0008                     524 	.ds 2
                    0002    525 Ltest_radio_link.handleCommands$sloc1$1$0==.
   000A                     526 _handleCommands_sloc1_1_0:
   000A                     527 	.ds 2
                    0004    528 Ltest_radio_link.handleCommands$sloc2$1$0==.
   000C                     529 _handleCommands_sloc2_1_0:
   000C                     530 	.ds 2
                            531 ;--------------------------------------------------------
                            532 ; overlayable items in internal ram 
                            533 ;--------------------------------------------------------
                            534 	.area OSEG    (OVR,DATA)
                            535 ;--------------------------------------------------------
                            536 ; Stack segment in internal ram 
                            537 ;--------------------------------------------------------
                            538 	.area	SSEG	(DATA)
   0025                     539 __start__stack:
   0025                     540 	.ds	1
                            541 
                            542 ;--------------------------------------------------------
                            543 ; indirectly addressable internal ram data
                            544 ;--------------------------------------------------------
                            545 	.area ISEG    (DATA)
                            546 ;--------------------------------------------------------
                            547 ; absolute internal ram data
                            548 ;--------------------------------------------------------
                            549 	.area IABS    (ABS,DATA)
                            550 	.area IABS    (ABS,DATA)
                            551 ;--------------------------------------------------------
                            552 ; bit data
                            553 ;--------------------------------------------------------
                            554 	.area BSEG    (BIT)
                            555 ;--------------------------------------------------------
                            556 ; paged external ram data
                            557 ;--------------------------------------------------------
                            558 	.area PSEG    (PAG,XDATA)
                    0000    559 Ltest_radio_link.radioToUsb$length$1$1==.
   F000                     560 _radioToUsb_length_1_1:
   F000                     561 	.ds 1
                    0001    562 Ltest_radio_link.radioToUsb$i$1$1==.
   F001                     563 _radioToUsb_i_1_1:
   F001                     564 	.ds 1
                    0002    565 Ltest_radio_link.handleCommands$payloadType$1$1==.
   F002                     566 _handleCommands_payloadType_1_1:
   F002                     567 	.ds 1
                    0003    568 Ltest_radio_link.handleCommands$packet$3$4==.
   F003                     569 _handleCommands_packet_3_4:
   F003                     570 	.ds 2
                            571 ;--------------------------------------------------------
                            572 ; external ram data
                            573 ;--------------------------------------------------------
                            574 	.area XSEG    (XDATA)
                    DF00    575 Ftest_radio_link$SYNC1$0$0 == 0xdf00
                    DF00    576 _SYNC1	=	0xdf00
                    DF01    577 Ftest_radio_link$SYNC0$0$0 == 0xdf01
                    DF01    578 _SYNC0	=	0xdf01
                    DF02    579 Ftest_radio_link$PKTLEN$0$0 == 0xdf02
                    DF02    580 _PKTLEN	=	0xdf02
                    DF03    581 Ftest_radio_link$PKTCTRL1$0$0 == 0xdf03
                    DF03    582 _PKTCTRL1	=	0xdf03
                    DF04    583 Ftest_radio_link$PKTCTRL0$0$0 == 0xdf04
                    DF04    584 _PKTCTRL0	=	0xdf04
                    DF05    585 Ftest_radio_link$ADDR$0$0 == 0xdf05
                    DF05    586 _ADDR	=	0xdf05
                    DF06    587 Ftest_radio_link$CHANNR$0$0 == 0xdf06
                    DF06    588 _CHANNR	=	0xdf06
                    DF07    589 Ftest_radio_link$FSCTRL1$0$0 == 0xdf07
                    DF07    590 _FSCTRL1	=	0xdf07
                    DF08    591 Ftest_radio_link$FSCTRL0$0$0 == 0xdf08
                    DF08    592 _FSCTRL0	=	0xdf08
                    DF09    593 Ftest_radio_link$FREQ2$0$0 == 0xdf09
                    DF09    594 _FREQ2	=	0xdf09
                    DF0A    595 Ftest_radio_link$FREQ1$0$0 == 0xdf0a
                    DF0A    596 _FREQ1	=	0xdf0a
                    DF0B    597 Ftest_radio_link$FREQ0$0$0 == 0xdf0b
                    DF0B    598 _FREQ0	=	0xdf0b
                    DF0C    599 Ftest_radio_link$MDMCFG4$0$0 == 0xdf0c
                    DF0C    600 _MDMCFG4	=	0xdf0c
                    DF0D    601 Ftest_radio_link$MDMCFG3$0$0 == 0xdf0d
                    DF0D    602 _MDMCFG3	=	0xdf0d
                    DF0E    603 Ftest_radio_link$MDMCFG2$0$0 == 0xdf0e
                    DF0E    604 _MDMCFG2	=	0xdf0e
                    DF0F    605 Ftest_radio_link$MDMCFG1$0$0 == 0xdf0f
                    DF0F    606 _MDMCFG1	=	0xdf0f
                    DF10    607 Ftest_radio_link$MDMCFG0$0$0 == 0xdf10
                    DF10    608 _MDMCFG0	=	0xdf10
                    DF11    609 Ftest_radio_link$DEVIATN$0$0 == 0xdf11
                    DF11    610 _DEVIATN	=	0xdf11
                    DF12    611 Ftest_radio_link$MCSM2$0$0 == 0xdf12
                    DF12    612 _MCSM2	=	0xdf12
                    DF13    613 Ftest_radio_link$MCSM1$0$0 == 0xdf13
                    DF13    614 _MCSM1	=	0xdf13
                    DF14    615 Ftest_radio_link$MCSM0$0$0 == 0xdf14
                    DF14    616 _MCSM0	=	0xdf14
                    DF15    617 Ftest_radio_link$FOCCFG$0$0 == 0xdf15
                    DF15    618 _FOCCFG	=	0xdf15
                    DF16    619 Ftest_radio_link$BSCFG$0$0 == 0xdf16
                    DF16    620 _BSCFG	=	0xdf16
                    DF17    621 Ftest_radio_link$AGCCTRL2$0$0 == 0xdf17
                    DF17    622 _AGCCTRL2	=	0xdf17
                    DF18    623 Ftest_radio_link$AGCCTRL1$0$0 == 0xdf18
                    DF18    624 _AGCCTRL1	=	0xdf18
                    DF19    625 Ftest_radio_link$AGCCTRL0$0$0 == 0xdf19
                    DF19    626 _AGCCTRL0	=	0xdf19
                    DF1A    627 Ftest_radio_link$FREND1$0$0 == 0xdf1a
                    DF1A    628 _FREND1	=	0xdf1a
                    DF1B    629 Ftest_radio_link$FREND0$0$0 == 0xdf1b
                    DF1B    630 _FREND0	=	0xdf1b
                    DF1C    631 Ftest_radio_link$FSCAL3$0$0 == 0xdf1c
                    DF1C    632 _FSCAL3	=	0xdf1c
                    DF1D    633 Ftest_radio_link$FSCAL2$0$0 == 0xdf1d
                    DF1D    634 _FSCAL2	=	0xdf1d
                    DF1E    635 Ftest_radio_link$FSCAL1$0$0 == 0xdf1e
                    DF1E    636 _FSCAL1	=	0xdf1e
                    DF1F    637 Ftest_radio_link$FSCAL0$0$0 == 0xdf1f
                    DF1F    638 _FSCAL0	=	0xdf1f
                    DF23    639 Ftest_radio_link$TEST2$0$0 == 0xdf23
                    DF23    640 _TEST2	=	0xdf23
                    DF24    641 Ftest_radio_link$TEST1$0$0 == 0xdf24
                    DF24    642 _TEST1	=	0xdf24
                    DF25    643 Ftest_radio_link$TEST0$0$0 == 0xdf25
                    DF25    644 _TEST0	=	0xdf25
                    DF2E    645 Ftest_radio_link$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    646 _PA_TABLE0	=	0xdf2e
                    DF2F    647 Ftest_radio_link$IOCFG2$0$0 == 0xdf2f
                    DF2F    648 _IOCFG2	=	0xdf2f
                    DF30    649 Ftest_radio_link$IOCFG1$0$0 == 0xdf30
                    DF30    650 _IOCFG1	=	0xdf30
                    DF31    651 Ftest_radio_link$IOCFG0$0$0 == 0xdf31
                    DF31    652 _IOCFG0	=	0xdf31
                    DF36    653 Ftest_radio_link$PARTNUM$0$0 == 0xdf36
                    DF36    654 _PARTNUM	=	0xdf36
                    DF37    655 Ftest_radio_link$VERSION$0$0 == 0xdf37
                    DF37    656 _VERSION	=	0xdf37
                    DF38    657 Ftest_radio_link$FREQEST$0$0 == 0xdf38
                    DF38    658 _FREQEST	=	0xdf38
                    DF39    659 Ftest_radio_link$LQI$0$0 == 0xdf39
                    DF39    660 _LQI	=	0xdf39
                    DF3A    661 Ftest_radio_link$RSSI$0$0 == 0xdf3a
                    DF3A    662 _RSSI	=	0xdf3a
                    DF3B    663 Ftest_radio_link$MARCSTATE$0$0 == 0xdf3b
                    DF3B    664 _MARCSTATE	=	0xdf3b
                    DF3C    665 Ftest_radio_link$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    666 _PKTSTATUS	=	0xdf3c
                    DF3D    667 Ftest_radio_link$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    668 _VCO_VC_DAC	=	0xdf3d
                    DF40    669 Ftest_radio_link$I2SCFG0$0$0 == 0xdf40
                    DF40    670 _I2SCFG0	=	0xdf40
                    DF41    671 Ftest_radio_link$I2SCFG1$0$0 == 0xdf41
                    DF41    672 _I2SCFG1	=	0xdf41
                    DF42    673 Ftest_radio_link$I2SDATL$0$0 == 0xdf42
                    DF42    674 _I2SDATL	=	0xdf42
                    DF43    675 Ftest_radio_link$I2SDATH$0$0 == 0xdf43
                    DF43    676 _I2SDATH	=	0xdf43
                    DF44    677 Ftest_radio_link$I2SWCNT$0$0 == 0xdf44
                    DF44    678 _I2SWCNT	=	0xdf44
                    DF45    679 Ftest_radio_link$I2SSTAT$0$0 == 0xdf45
                    DF45    680 _I2SSTAT	=	0xdf45
                    DF46    681 Ftest_radio_link$I2SCLKF0$0$0 == 0xdf46
                    DF46    682 _I2SCLKF0	=	0xdf46
                    DF47    683 Ftest_radio_link$I2SCLKF1$0$0 == 0xdf47
                    DF47    684 _I2SCLKF1	=	0xdf47
                    DF48    685 Ftest_radio_link$I2SCLKF2$0$0 == 0xdf48
                    DF48    686 _I2SCLKF2	=	0xdf48
                    DE00    687 Ftest_radio_link$USBADDR$0$0 == 0xde00
                    DE00    688 _USBADDR	=	0xde00
                    DE01    689 Ftest_radio_link$USBPOW$0$0 == 0xde01
                    DE01    690 _USBPOW	=	0xde01
                    DE02    691 Ftest_radio_link$USBIIF$0$0 == 0xde02
                    DE02    692 _USBIIF	=	0xde02
                    DE04    693 Ftest_radio_link$USBOIF$0$0 == 0xde04
                    DE04    694 _USBOIF	=	0xde04
                    DE06    695 Ftest_radio_link$USBCIF$0$0 == 0xde06
                    DE06    696 _USBCIF	=	0xde06
                    DE07    697 Ftest_radio_link$USBIIE$0$0 == 0xde07
                    DE07    698 _USBIIE	=	0xde07
                    DE09    699 Ftest_radio_link$USBOIE$0$0 == 0xde09
                    DE09    700 _USBOIE	=	0xde09
                    DE0B    701 Ftest_radio_link$USBCIE$0$0 == 0xde0b
                    DE0B    702 _USBCIE	=	0xde0b
                    DE0C    703 Ftest_radio_link$USBFRML$0$0 == 0xde0c
                    DE0C    704 _USBFRML	=	0xde0c
                    DE0D    705 Ftest_radio_link$USBFRMH$0$0 == 0xde0d
                    DE0D    706 _USBFRMH	=	0xde0d
                    DE0E    707 Ftest_radio_link$USBINDEX$0$0 == 0xde0e
                    DE0E    708 _USBINDEX	=	0xde0e
                    DE10    709 Ftest_radio_link$USBMAXI$0$0 == 0xde10
                    DE10    710 _USBMAXI	=	0xde10
                    DE11    711 Ftest_radio_link$USBCSIL$0$0 == 0xde11
                    DE11    712 _USBCSIL	=	0xde11
                    DE12    713 Ftest_radio_link$USBCSIH$0$0 == 0xde12
                    DE12    714 _USBCSIH	=	0xde12
                    DE13    715 Ftest_radio_link$USBMAXO$0$0 == 0xde13
                    DE13    716 _USBMAXO	=	0xde13
                    DE14    717 Ftest_radio_link$USBCSOL$0$0 == 0xde14
                    DE14    718 _USBCSOL	=	0xde14
                    DE15    719 Ftest_radio_link$USBCSOH$0$0 == 0xde15
                    DE15    720 _USBCSOH	=	0xde15
                    DE16    721 Ftest_radio_link$USBCNTL$0$0 == 0xde16
                    DE16    722 _USBCNTL	=	0xde16
                    DE17    723 Ftest_radio_link$USBCNTH$0$0 == 0xde17
                    DE17    724 _USBCNTH	=	0xde17
                    DE20    725 Ftest_radio_link$USBF0$0$0 == 0xde20
                    DE20    726 _USBF0	=	0xde20
                    DE22    727 Ftest_radio_link$USBF1$0$0 == 0xde22
                    DE22    728 _USBF1	=	0xde22
                    DE24    729 Ftest_radio_link$USBF2$0$0 == 0xde24
                    DE24    730 _USBF2	=	0xde24
                    DE26    731 Ftest_radio_link$USBF3$0$0 == 0xde26
                    DE26    732 _USBF3	=	0xde26
                    DE28    733 Ftest_radio_link$USBF4$0$0 == 0xde28
                    DE28    734 _USBF4	=	0xde28
                    DE2A    735 Ftest_radio_link$USBF5$0$0 == 0xde2a
                    DE2A    736 _USBF5	=	0xde2a
                    0000    737 Ltest_radio_link.radioToUsb$buffer$1$1==.
   F049                     738 _radioToUsb_buffer_1_1:
   F049                     739 	.ds 128
                    0080    740 Ltest_radio_link.handleCommands$txNotAvailable$1$1==.
   F0C9                     741 _handleCommands_txNotAvailable_1_1:
   F0C9                     742 	.ds 20
                    0094    743 Ltest_radio_link.handleCommands$response$1$1==.
   F0DD                     744 _handleCommands_response_1_1:
   F0DD                     745 	.ds 128
                            746 ;--------------------------------------------------------
                            747 ; absolute external ram data
                            748 ;--------------------------------------------------------
                            749 	.area XABS    (ABS,XDATA)
                            750 ;--------------------------------------------------------
                            751 ; external initialized ram data
                            752 ;--------------------------------------------------------
                            753 	.area XISEG   (XDATA)
                            754 	.area HOME    (CODE)
                            755 	.area GSINIT0 (CODE)
                            756 	.area GSINIT1 (CODE)
                            757 	.area GSINIT2 (CODE)
                            758 	.area GSINIT3 (CODE)
                            759 	.area GSINIT4 (CODE)
                            760 	.area GSINIT5 (CODE)
                            761 	.area GSINIT  (CODE)
                            762 	.area GSFINAL (CODE)
                            763 	.area CSEG    (CODE)
                            764 ;--------------------------------------------------------
                            765 ; interrupt vector 
                            766 ;--------------------------------------------------------
                            767 	.area HOME    (CODE)
   0400                     768 __interrupt_vect:
   0400 02 04 8D            769 	ljmp	__sdcc_gsinit_startup
   0403 32                  770 	reti
   0404                     771 	.ds	7
   040B 32                  772 	reti
   040C                     773 	.ds	7
   0413 32                  774 	reti
   0414                     775 	.ds	7
   041B 32                  776 	reti
   041C                     777 	.ds	7
   0423 32                  778 	reti
   0424                     779 	.ds	7
   042B 32                  780 	reti
   042C                     781 	.ds	7
   0433 32                  782 	reti
   0434                     783 	.ds	7
   043B 32                  784 	reti
   043C                     785 	.ds	7
   0443 32                  786 	reti
   0444                     787 	.ds	7
   044B 32                  788 	reti
   044C                     789 	.ds	7
   0453 32                  790 	reti
   0454                     791 	.ds	7
   045B 32                  792 	reti
   045C                     793 	.ds	7
   0463 02 18 86            794 	ljmp	_ISR_T4
   0466                     795 	.ds	5
   046B 32                  796 	reti
   046C                     797 	.ds	7
   0473 32                  798 	reti
   0474                     799 	.ds	7
   047B 32                  800 	reti
   047C                     801 	.ds	7
   0483 02 0C 68            802 	ljmp	_ISR_RF
                            803 ;--------------------------------------------------------
                            804 ; global & static initialisations
                            805 ;--------------------------------------------------------
                            806 	.area HOME    (CODE)
                            807 	.area GSINIT  (CODE)
                            808 	.area GSFINAL (CODE)
                            809 	.area GSINIT  (CODE)
                            810 	.globl __sdcc_gsinit_startup
                            811 	.globl __sdcc_program_startup
                            812 	.globl __start__stack
                            813 	.globl __mcs51_genXINIT
                            814 	.globl __mcs51_genXRAMCLEAR
                            815 	.globl __mcs51_genRAMCLEAR
                            816 ;------------------------------------------------------------
                            817 ;Allocation info for local variables in function 'handleCommands'
                            818 ;------------------------------------------------------------
                            819 ;sloc0                     Allocated with name '_handleCommands_sloc0_1_0'
                            820 ;sloc1                     Allocated with name '_handleCommands_sloc1_1_0'
                            821 ;sloc2                     Allocated with name '_handleCommands_sloc2_1_0'
                            822 ;txNotAvailable            Allocated with name '_handleCommands_txNotAvailable_1_1'
                            823 ;response                  Allocated with name '_handleCommands_response_1_1'
                            824 ;------------------------------------------------------------
                    0000    825 	G$handleCommands$0$0 ==.
                    0000    826 	C$test_radio_link.c$84$1$1 ==.
                            827 ;	apps/test_radio_link/test_radio_link.c:84: static uint8 payloadType = 0;
   04E6 78 02               828 	mov	r0,#_handleCommands_payloadType_1_1
   04E8 E4                  829 	clr	a
   04E9 F2                  830 	movx	@r0,a
                            831 	.area GSFINAL (CODE)
   0530 02 04 86            832 	ljmp	__sdcc_program_startup
                            833 ;--------------------------------------------------------
                            834 ; Home
                            835 ;--------------------------------------------------------
                            836 	.area HOME    (CODE)
                            837 	.area HOME    (CODE)
   0486                     838 __sdcc_program_startup:
   0486 12 08 E7            839 	lcall	_main
                            840 ;	return from main will lock up
   0489 80 FE               841 	sjmp .
                            842 ;--------------------------------------------------------
                            843 ; code
                            844 ;--------------------------------------------------------
                            845 	.area CSEG    (CODE)
                            846 ;------------------------------------------------------------
                            847 ;Allocation info for local variables in function 'updateLeds'
                            848 ;------------------------------------------------------------
                    0000    849 	G$updateLeds$0$0 ==.
                    0000    850 	C$test_radio_link.c$21$0$0 ==.
                            851 ;	apps/test_radio_link/test_radio_link.c:21: void updateLeds()
                            852 ;	-----------------------------------------
                            853 ;	 function updateLeds
                            854 ;	-----------------------------------------
   0533                     855 _updateLeds:
                    0007    856 	ar7 = 0x07
                    0006    857 	ar6 = 0x06
                    0005    858 	ar5 = 0x05
                    0004    859 	ar4 = 0x04
                    0003    860 	ar3 = 0x03
                    0002    861 	ar2 = 0x02
                    0001    862 	ar1 = 0x01
                    0000    863 	ar0 = 0x00
                    0000    864 	C$test_radio_link.c$23$1$1 ==.
                            865 ;	apps/test_radio_link/test_radio_link.c:23: usbShowStatusWithGreenLed();
   0533 12 1A F8            866 	lcall	_usbShowStatusWithGreenLed
                    0003    867 	C$test_radio_link.c$25$1$1 ==.
                            868 ;	apps/test_radio_link/test_radio_link.c:25: if (MARCSTATE == 0x11)
   0536 90 DF 3B            869 	mov	dptr,#_MARCSTATE
   0539 E0                  870 	movx	a,@dptr
   053A FF                  871 	mov	r7,a
   053B BF 11 05            872 	cjne	r7,#0x11,00102$
                    000B    873 	C$test_radio_link.c$27$3$3 ==.
                            874 ;	apps/test_radio_link/test_radio_link.c:27: LED_RED(1);
   053E 43 FF 02            875 	orl	_P2DIR,#0x02
   0541 80 07               876 	sjmp	00103$
   0543                     877 00102$:
                    0010    878 	C$test_radio_link.c$31$3$5 ==.
                            879 ;	apps/test_radio_link/test_radio_link.c:31: LED_RED(0);
   0543 AF FF               880 	mov	r7,_P2DIR
   0545 53 07 FD            881 	anl	ar7,#0xFD
   0548 8F FF               882 	mov	_P2DIR,r7
   054A                     883 00103$:
                    0017    884 	C$test_radio_link.c$34$2$6 ==.
                            885 ;	apps/test_radio_link/test_radio_link.c:34: LED_YELLOW(radioLinkConnected());
   054A 12 09 5B            886 	lcall	_radioLinkConnected
   054D 50 05               887 	jnc	00106$
   054F 43 FF 04            888 	orl	_P2DIR,#0x04
   0552 80 07               889 	sjmp	00104$
   0554                     890 00106$:
   0554 AF FF               891 	mov	r7,_P2DIR
   0556 53 07 FB            892 	anl	ar7,#0xFB
   0559 8F FF               893 	mov	_P2DIR,r7
   055B                     894 00104$:
                    0028    895 	C$test_radio_link.c$35$2$6 ==.
                    0028    896 	XG$updateLeds$0$0 ==.
   055B 22                  897 	ret
                            898 ;------------------------------------------------------------
                            899 ;Allocation info for local variables in function 'nibbleToAscii'
                            900 ;------------------------------------------------------------
                    0029    901 	G$nibbleToAscii$0$0 ==.
                    0029    902 	C$test_radio_link.c$37$2$6 ==.
                            903 ;	apps/test_radio_link/test_radio_link.c:37: uint8 nibbleToAscii(uint8 nibble)
                            904 ;	-----------------------------------------
                            905 ;	 function nibbleToAscii
                            906 ;	-----------------------------------------
   055C                     907 _nibbleToAscii:
                    0029    908 	C$test_radio_link.c$39$1$1 ==.
                            909 ;	apps/test_radio_link/test_radio_link.c:39: nibble &= 0xF;
                    0029    910 	C$test_radio_link.c$40$1$1 ==.
                            911 ;	apps/test_radio_link/test_radio_link.c:40: if (nibble <= 0x9){ return '0' + nibble; }
   055C E5 82               912 	mov	a,dpl
   055E 54 0F               913 	anl	a,#0x0F
   0560 FF                  914 	mov	r7,a
   0561 24 F6               915 	add	a,#0xff - 0x09
   0563 40 0A               916 	jc	00102$
   0565 8F 06               917 	mov	ar6,r7
   0567 74 30               918 	mov	a,#0x30
   0569 2E                  919 	add	a,r6
   056A FE                  920 	mov	r6,a
   056B F5 82               921 	mov	dpl,a
   056D 80 05               922 	sjmp	00104$
   056F                     923 00102$:
                    003C    924 	C$test_radio_link.c$41$2$3 ==.
                            925 ;	apps/test_radio_link/test_radio_link.c:41: else{ return 'A' + (nibble - 0xA); }
   056F 74 37               926 	mov	a,#0x37
   0571 2F                  927 	add	a,r7
                    003F    928 	C$test_radio_link.c$42$1$1 ==.
                    003F    929 	XG$nibbleToAscii$0$0 ==.
   0572 F5 82               930 	mov	dpl,a
   0574                     931 00104$:
   0574 22                  932 	ret
                            933 ;------------------------------------------------------------
                            934 ;Allocation info for local variables in function 'radioToUsb'
                            935 ;------------------------------------------------------------
                            936 ;buffer                    Allocated with name '_radioToUsb_buffer_1_1'
                            937 ;------------------------------------------------------------
                    0042    938 	G$radioToUsb$0$0 ==.
                    0042    939 	C$test_radio_link.c$44$1$1 ==.
                            940 ;	apps/test_radio_link/test_radio_link.c:44: void radioToUsb()
                            941 ;	-----------------------------------------
                            942 ;	 function radioToUsb
                            943 ;	-----------------------------------------
   0575                     944 _radioToUsb:
                    0042    945 	C$test_radio_link.c$52$1$1 ==.
                            946 ;	apps/test_radio_link/test_radio_link.c:52: if ((packet = radioLinkRxCurrentPacket()) && usbComTxAvailable() >= packet[0]*2 + 30)
   0575 12 09 EB            947 	lcall	_radioLinkRxCurrentPacket
   0578 AE 82               948 	mov	r6,dpl
   057A AF 83               949 	mov	r7,dph
   057C 8E 04               950 	mov	ar4,r6
   057E 8F 05               951 	mov	ar5,r7
   0580 EE                  952 	mov	a,r6
   0581 4F                  953 	orl	a,r7
   0582 70 03               954 	jnz	00120$
   0584 02 06 CD            955 	ljmp	00102$
   0587                     956 00120$:
   0587 C0 05               957 	push	ar5
   0589 C0 04               958 	push	ar4
   058B 12 10 88            959 	lcall	_usbComTxAvailable
   058E AF 82               960 	mov	r7,dpl
   0590 D0 04               961 	pop	ar4
   0592 D0 05               962 	pop	ar5
   0594 8C 82               963 	mov	dpl,r4
   0596 8D 83               964 	mov	dph,r5
   0598 E0                  965 	movx	a,@dptr
   0599 75 F0 02            966 	mov	b,#0x02
   059C A4                  967 	mul	ab
   059D 24 1E               968 	add	a,#0x1E
   059F FB                  969 	mov	r3,a
   05A0 E4                  970 	clr	a
   05A1 35 F0               971 	addc	a,b
   05A3 FE                  972 	mov	r6,a
   05A4 7A 00               973 	mov	r2,#0x00
   05A6 C3                  974 	clr	c
   05A7 EF                  975 	mov	a,r7
   05A8 9B                  976 	subb	a,r3
   05A9 EA                  977 	mov	a,r2
   05AA 64 80               978 	xrl	a,#0x80
   05AC 8E F0               979 	mov	b,r6
   05AE 63 F0 80            980 	xrl	b,#0x80
   05B1 95 F0               981 	subb	a,b
   05B3 50 03               982 	jnc	00121$
   05B5 02 06 CD            983 	ljmp	00102$
   05B8                     984 00121$:
                    0085    985 	C$test_radio_link.c$54$2$2 ==.
                            986 ;	apps/test_radio_link/test_radio_link.c:54: length = sprintf(buffer, "RX: %2d ", radioLinkRxCurrentPayloadType());
   05B8 C0 05               987 	push	ar5
   05BA C0 04               988 	push	ar4
   05BC 12 0A 0C            989 	lcall	_radioLinkRxCurrentPayloadType
   05BF AF 82               990 	mov	r7,dpl
   05C1 7E 00               991 	mov	r6,#0x00
   05C3 C0 07               992 	push	ar7
   05C5 C0 06               993 	push	ar6
   05C7 74 43               994 	mov	a,#__str_1
   05C9 C0 E0               995 	push	acc
   05CB 74 23               996 	mov	a,#(__str_1 >> 8)
   05CD C0 E0               997 	push	acc
   05CF 74 80               998 	mov	a,#0x80
   05D1 C0 E0               999 	push	acc
   05D3 74 49              1000 	mov	a,#_radioToUsb_buffer_1_1
   05D5 C0 E0              1001 	push	acc
   05D7 74 F0              1002 	mov	a,#(_radioToUsb_buffer_1_1 >> 8)
   05D9 C0 E0              1003 	push	acc
   05DB E4                 1004 	clr	a
   05DC C0 E0              1005 	push	acc
   05DE 12 19 D4           1006 	lcall	_sprintf
   05E1 AE 82              1007 	mov	r6,dpl
   05E3 AF 83              1008 	mov	r7,dph
   05E5 E5 81              1009 	mov	a,sp
   05E7 24 F8              1010 	add	a,#0xf8
   05E9 F5 81              1011 	mov	sp,a
   05EB D0 04              1012 	pop	ar4
   05ED D0 05              1013 	pop	ar5
   05EF 78 00              1014 	mov	r0,#_radioToUsb_length_1_1
   05F1 EE                 1015 	mov	a,r6
   05F2 F2                 1016 	movx	@r0,a
                    00C0   1017 	C$test_radio_link.c$55$2$1 ==.
                           1018 ;	apps/test_radio_link/test_radio_link.c:55: for (i = 0; i < packet[0]; i++)
   05F3 78 01              1019 	mov	r0,#_radioToUsb_i_1_1
   05F5 E4                 1020 	clr	a
   05F6 F2                 1021 	movx	@r0,a
   05F7                    1022 00107$:
   05F7 8C 82              1023 	mov	dpl,r4
   05F9 8D 83              1024 	mov	dph,r5
   05FB E0                 1025 	movx	a,@dptr
   05FC FB                 1026 	mov	r3,a
   05FD 78 01              1027 	mov	r0,#_radioToUsb_i_1_1
   05FF C3                 1028 	clr	c
   0600 E2                 1029 	movx	a,@r0
   0601 9B                 1030 	subb	a,r3
   0602 40 03              1031 	jc	00122$
   0604 02 06 90           1032 	ljmp	00110$
   0607                    1033 00122$:
                    00D4   1034 	C$test_radio_link.c$57$3$3 ==.
                           1035 ;	apps/test_radio_link/test_radio_link.c:57: buffer[length++] = nibbleToAscii(packet[1+i] >> 4);
   0607 78 00              1036 	mov	r0,#_radioToUsb_length_1_1
   0609 E2                 1037 	movx	a,@r0
   060A FB                 1038 	mov	r3,a
   060B 78 00              1039 	mov	r0,#_radioToUsb_length_1_1
   060D E2                 1040 	movx	a,@r0
   060E 24 01              1041 	add	a,#0x01
   0610 F2                 1042 	movx	@r0,a
   0611 EB                 1043 	mov	a,r3
   0612 24 49              1044 	add	a,#_radioToUsb_buffer_1_1
   0614 FB                 1045 	mov	r3,a
   0615 E4                 1046 	clr	a
   0616 34 F0              1047 	addc	a,#(_radioToUsb_buffer_1_1 >> 8)
   0618 FA                 1048 	mov	r2,a
   0619 78 01              1049 	mov	r0,#_radioToUsb_i_1_1
   061B E2                 1050 	movx	a,@r0
   061C FE                 1051 	mov	r6,a
   061D 7F 00              1052 	mov	r7,#0x00
   061F 0E                 1053 	inc	r6
   0620 BE 00 01           1054 	cjne	r6,#0x00,00123$
   0623 0F                 1055 	inc	r7
   0624                    1056 00123$:
   0624 EE                 1057 	mov	a,r6
   0625 2C                 1058 	add	a,r4
   0626 FE                 1059 	mov	r6,a
   0627 EF                 1060 	mov	a,r7
   0628 3D                 1061 	addc	a,r5
   0629 FF                 1062 	mov	r7,a
   062A C0 04              1063 	push	ar4
   062C C0 05              1064 	push	ar5
   062E 8E 82              1065 	mov	dpl,r6
   0630 8F 83              1066 	mov	dph,r7
   0632 E0                 1067 	movx	a,@dptr
   0633 C4                 1068 	swap	a
   0634 54 0F              1069 	anl	a,#0x0F
   0636 F5 82              1070 	mov	dpl,a
   0638 C0 07              1071 	push	ar7
   063A C0 06              1072 	push	ar6
   063C C0 04              1073 	push	ar4
   063E C0 03              1074 	push	ar3
   0640 C0 02              1075 	push	ar2
   0642 12 05 5C           1076 	lcall	_nibbleToAscii
   0645 AD 82              1077 	mov	r5,dpl
   0647 D0 02              1078 	pop	ar2
   0649 D0 03              1079 	pop	ar3
   064B D0 04              1080 	pop	ar4
   064D D0 06              1081 	pop	ar6
   064F D0 07              1082 	pop	ar7
   0651 8B 82              1083 	mov	dpl,r3
   0653 8A 83              1084 	mov	dph,r2
   0655 ED                 1085 	mov	a,r5
   0656 F0                 1086 	movx	@dptr,a
                    0124   1087 	C$test_radio_link.c$58$3$3 ==.
                           1088 ;	apps/test_radio_link/test_radio_link.c:58: buffer[length++] = nibbleToAscii(packet[1+i]);
   0657 78 00              1089 	mov	r0,#_radioToUsb_length_1_1
   0659 E2                 1090 	movx	a,@r0
   065A FD                 1091 	mov	r5,a
   065B 78 00              1092 	mov	r0,#_radioToUsb_length_1_1
   065D E2                 1093 	movx	a,@r0
   065E 24 01              1094 	add	a,#0x01
   0660 F2                 1095 	movx	@r0,a
   0661 ED                 1096 	mov	a,r5
   0662 24 49              1097 	add	a,#_radioToUsb_buffer_1_1
   0664 FD                 1098 	mov	r5,a
   0665 E4                 1099 	clr	a
   0666 34 F0              1100 	addc	a,#(_radioToUsb_buffer_1_1 >> 8)
   0668 FC                 1101 	mov	r4,a
   0669 8E 82              1102 	mov	dpl,r6
   066B 8F 83              1103 	mov	dph,r7
   066D E0                 1104 	movx	a,@dptr
   066E F5 82              1105 	mov	dpl,a
   0670 C0 05              1106 	push	ar5
   0672 C0 04              1107 	push	ar4
   0674 12 05 5C           1108 	lcall	_nibbleToAscii
   0677 AF 82              1109 	mov	r7,dpl
   0679 D0 04              1110 	pop	ar4
   067B D0 05              1111 	pop	ar5
   067D 8D 82              1112 	mov	dpl,r5
   067F 8C 83              1113 	mov	dph,r4
   0681 EF                 1114 	mov	a,r7
   0682 F0                 1115 	movx	@dptr,a
                    0150   1116 	C$test_radio_link.c$55$2$2 ==.
                           1117 ;	apps/test_radio_link/test_radio_link.c:55: for (i = 0; i < packet[0]; i++)
   0683 78 01              1118 	mov	r0,#_radioToUsb_i_1_1
   0685 E2                 1119 	movx	a,@r0
   0686 24 01              1120 	add	a,#0x01
   0688 F2                 1121 	movx	@r0,a
   0689 D0 05              1122 	pop	ar5
   068B D0 04              1123 	pop	ar4
   068D 02 05 F7           1124 	ljmp	00107$
   0690                    1125 00110$:
                    015D   1126 	C$test_radio_link.c$61$2$2 ==.
                           1127 ;	apps/test_radio_link/test_radio_link.c:61: buffer[length++] = '\r';
   0690 78 00              1128 	mov	r0,#_radioToUsb_length_1_1
   0692 E2                 1129 	movx	a,@r0
   0693 FF                 1130 	mov	r7,a
   0694 78 00              1131 	mov	r0,#_radioToUsb_length_1_1
   0696 E2                 1132 	movx	a,@r0
   0697 24 01              1133 	add	a,#0x01
   0699 F2                 1134 	movx	@r0,a
   069A EF                 1135 	mov	a,r7
   069B 24 49              1136 	add	a,#_radioToUsb_buffer_1_1
   069D F5 82              1137 	mov	dpl,a
   069F E4                 1138 	clr	a
   06A0 34 F0              1139 	addc	a,#(_radioToUsb_buffer_1_1 >> 8)
   06A2 F5 83              1140 	mov	dph,a
   06A4 74 0D              1141 	mov	a,#0x0D
   06A6 F0                 1142 	movx	@dptr,a
                    0174   1143 	C$test_radio_link.c$62$2$2 ==.
                           1144 ;	apps/test_radio_link/test_radio_link.c:62: buffer[length++] = '\n';
   06A7 78 00              1145 	mov	r0,#_radioToUsb_length_1_1
   06A9 E2                 1146 	movx	a,@r0
   06AA FF                 1147 	mov	r7,a
   06AB 78 00              1148 	mov	r0,#_radioToUsb_length_1_1
   06AD E2                 1149 	movx	a,@r0
   06AE 24 01              1150 	add	a,#0x01
   06B0 F2                 1151 	movx	@r0,a
   06B1 EF                 1152 	mov	a,r7
   06B2 24 49              1153 	add	a,#_radioToUsb_buffer_1_1
   06B4 F5 82              1154 	mov	dpl,a
   06B6 E4                 1155 	clr	a
   06B7 34 F0              1156 	addc	a,#(_radioToUsb_buffer_1_1 >> 8)
   06B9 F5 83              1157 	mov	dph,a
   06BB 74 0A              1158 	mov	a,#0x0A
   06BD F0                 1159 	movx	@dptr,a
                    018B   1160 	C$test_radio_link.c$64$2$2 ==.
                           1161 ;	apps/test_radio_link/test_radio_link.c:64: radioLinkRxDoneWithPacket();
   06BE 12 0A 1F           1162 	lcall	_radioLinkRxDoneWithPacket
                    018E   1163 	C$test_radio_link.c$65$2$2 ==.
                           1164 ;	apps/test_radio_link/test_radio_link.c:65: usbComTxSend(buffer, length);
   06C1 78 00              1165 	mov	r0,#_radioToUsb_length_1_1
   06C3 79 0F              1166 	mov	r1,#_usbComTxSend_PARM_2
   06C5 E2                 1167 	movx	a,@r0
   06C6 F3                 1168 	movx	@r1,a
   06C7 90 F0 49           1169 	mov	dptr,#_radioToUsb_buffer_1_1
   06CA 12 10 BF           1170 	lcall	_usbComTxSend
   06CD                    1171 00102$:
                    019A   1172 	C$test_radio_link.c$71$1$1 ==.
                           1173 ;	apps/test_radio_link/test_radio_link.c:71: if (radioLinkResetPacketReceived && usbComTxAvailable() >= sizeof(resetString)-1)
   06CD 30 02 17           1174 	jnb	_radioLinkResetPacketReceived,00111$
   06D0 12 10 88           1175 	lcall	_usbComTxAvailable
   06D3 AF 82              1176 	mov	r7,dpl
   06D5 BF 0B 00           1177 	cjne	r7,#0x0B,00125$
   06D8                    1178 00125$:
   06D8 40 0D              1179 	jc	00111$
                    01A7   1180 	C$test_radio_link.c$73$2$4 ==.
                           1181 ;	apps/test_radio_link/test_radio_link.c:73: radioLinkResetPacketReceived = 0;
   06DA C2 02              1182 	clr	_radioLinkResetPacketReceived
                    01A9   1183 	C$test_radio_link.c$74$2$4 ==.
                           1184 ;	apps/test_radio_link/test_radio_link.c:74: usbComTxSend((uint8 XDATA *)resetString, sizeof(resetString)-1);
   06DC 90 23 37           1185 	mov	dptr,#_radioToUsb_resetString_1_1
   06DF 78 0F              1186 	mov	r0,#_usbComTxSend_PARM_2
   06E1 74 0B              1187 	mov	a,#0x0B
   06E3 F2                 1188 	movx	@r0,a
   06E4 12 10 BF           1189 	lcall	_usbComTxSend
   06E7                    1190 00111$:
                    01B4   1191 	C$test_radio_link.c$77$2$1 ==.
                    01B4   1192 	XG$radioToUsb$0$0 ==.
   06E7 22                 1193 	ret
                           1194 ;------------------------------------------------------------
                           1195 ;Allocation info for local variables in function 'handleCommands'
                           1196 ;------------------------------------------------------------
                           1197 ;sloc0                     Allocated with name '_handleCommands_sloc0_1_0'
                           1198 ;sloc1                     Allocated with name '_handleCommands_sloc1_1_0'
                           1199 ;sloc2                     Allocated with name '_handleCommands_sloc2_1_0'
                           1200 ;txNotAvailable            Allocated with name '_handleCommands_txNotAvailable_1_1'
                           1201 ;response                  Allocated with name '_handleCommands_response_1_1'
                           1202 ;------------------------------------------------------------
                    01B5   1203 	G$handleCommands$0$0 ==.
                    01B5   1204 	C$test_radio_link.c$79$2$1 ==.
                           1205 ;	apps/test_radio_link/test_radio_link.c:79: void handleCommands()
                           1206 ;	-----------------------------------------
                           1207 ;	 function handleCommands
                           1208 ;	-----------------------------------------
   06E8                    1209 _handleCommands:
                    01B5   1210 	C$test_radio_link.c$81$1$1 ==.
                           1211 ;	apps/test_radio_link/test_radio_link.c:81: uint8 XDATA txNotAvailable[] = "TX not available!\r\n";
   06E8 90 F0 C9           1212 	mov	dptr,#_handleCommands_txNotAvailable_1_1
   06EB 74 54              1213 	mov	a,#0x54
   06ED F0                 1214 	movx	@dptr,a
   06EE 90 F0 CA           1215 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0001)
   06F1 74 58              1216 	mov	a,#0x58
   06F3 F0                 1217 	movx	@dptr,a
   06F4 90 F0 CB           1218 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0002)
   06F7 74 20              1219 	mov	a,#0x20
   06F9 F0                 1220 	movx	@dptr,a
   06FA 90 F0 CC           1221 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0003)
   06FD 74 6E              1222 	mov	a,#0x6E
   06FF F0                 1223 	movx	@dptr,a
   0700 90 F0 CD           1224 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0004)
   0703 74 6F              1225 	mov	a,#0x6F
   0705 F0                 1226 	movx	@dptr,a
   0706 90 F0 CE           1227 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0005)
   0709 74 74              1228 	mov	a,#0x74
   070B F0                 1229 	movx	@dptr,a
   070C 90 F0 CF           1230 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0006)
   070F 74 20              1231 	mov	a,#0x20
   0711 F0                 1232 	movx	@dptr,a
   0712 90 F0 D0           1233 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0007)
   0715 74 61              1234 	mov	a,#0x61
   0717 F0                 1235 	movx	@dptr,a
   0718 90 F0 D1           1236 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0008)
   071B 74 76              1237 	mov	a,#0x76
   071D F0                 1238 	movx	@dptr,a
   071E 90 F0 D2           1239 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0009)
   0721 74 61              1240 	mov	a,#0x61
   0723 F0                 1241 	movx	@dptr,a
   0724 90 F0 D3           1242 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000a)
   0727 74 69              1243 	mov	a,#0x69
   0729 F0                 1244 	movx	@dptr,a
   072A 90 F0 D4           1245 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000b)
   072D 74 6C              1246 	mov	a,#0x6C
   072F F0                 1247 	movx	@dptr,a
   0730 90 F0 D5           1248 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000c)
   0733 74 61              1249 	mov	a,#0x61
   0735 F0                 1250 	movx	@dptr,a
   0736 90 F0 D6           1251 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000d)
   0739 74 62              1252 	mov	a,#0x62
   073B F0                 1253 	movx	@dptr,a
   073C 90 F0 D7           1254 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000e)
   073F 74 6C              1255 	mov	a,#0x6C
   0741 F0                 1256 	movx	@dptr,a
   0742 90 F0 D8           1257 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x000f)
   0745 74 65              1258 	mov	a,#0x65
   0747 F0                 1259 	movx	@dptr,a
   0748 90 F0 D9           1260 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0010)
   074B 74 21              1261 	mov	a,#0x21
   074D F0                 1262 	movx	@dptr,a
   074E 90 F0 DA           1263 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0011)
   0751 74 0D              1264 	mov	a,#0x0D
   0753 F0                 1265 	movx	@dptr,a
   0754 90 F0 DB           1266 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0012)
   0757 74 0A              1267 	mov	a,#0x0A
   0759 F0                 1268 	movx	@dptr,a
   075A 90 F0 DC           1269 	mov	dptr,#(_handleCommands_txNotAvailable_1_1 + 0x0013)
   075D E4                 1270 	clr	a
   075E F0                 1271 	movx	@dptr,a
                    022C   1272 	C$test_radio_link.c$86$1$1 ==.
                           1273 ;	apps/test_radio_link/test_radio_link.c:86: if (usbComRxAvailable() && usbComTxAvailable() >= 50)
   075F 12 0F 52           1274 	lcall	_usbComRxAvailable
   0762 E5 82              1275 	mov	a,dpl
   0764 70 03              1276 	jnz	00125$
   0766 02 08 E6           1277 	ljmp	00116$
   0769                    1278 00125$:
   0769 12 10 88           1279 	lcall	_usbComTxAvailable
   076C AF 82              1280 	mov	r7,dpl
   076E BF 32 00           1281 	cjne	r7,#0x32,00126$
   0771                    1282 00126$:
   0771 50 03              1283 	jnc	00127$
   0773 02 08 E6           1284 	ljmp	00116$
   0776                    1285 00127$:
                    0243   1286 	C$test_radio_link.c$88$2$2 ==.
                           1287 ;	apps/test_radio_link/test_radio_link.c:88: uint8 byte = usbComRxReceiveByte();
   0776 12 0F 7C           1288 	lcall	_usbComRxReceiveByte
   0779 AD 82              1289 	mov	r5,dpl
                    0248   1290 	C$test_radio_link.c$89$2$2 ==.
                           1291 ;	apps/test_radio_link/test_radio_link.c:89: if (byte == (uint8)'?')
   077B BD 3F 60           1292 	cjne	r5,#0x3F,00111$
                    024B   1293 	C$test_radio_link.c$93$3$3 ==.
                           1294 ;	apps/test_radio_link/test_radio_link.c:93: radioLinkTxMainLoopIndex, radioLinkTxInterruptIndex, MARCSTATE);
   077E 90 DF 3B           1295 	mov	dptr,#_MARCSTATE
   0781 E0                 1296 	movx	a,@dptr
   0782 FE                 1297 	mov	r6,a
   0783 7D 00              1298 	mov	r5,#0x00
   0785 85 11 08           1299 	mov	_handleCommands_sloc0_1_0,_radioLinkTxInterruptIndex
   0788 75 09 00           1300 	mov	(_handleCommands_sloc0_1_0 + 1),#0x00
   078B 85 10 0A           1301 	mov	_handleCommands_sloc1_1_0,_radioLinkTxMainLoopIndex
   078E 75 0B 00           1302 	mov	(_handleCommands_sloc1_1_0 + 1),#0x00
                    025E   1303 	C$test_radio_link.c$92$3$3 ==.
                           1304 ;	apps/test_radio_link/test_radio_link.c:92: radioLinkRxMainLoopIndex, radioLinkRxInterruptIndex,
   0791 85 0F 0C           1305 	mov	_handleCommands_sloc2_1_0,_radioLinkRxInterruptIndex
   0794 75 0D 00           1306 	mov	(_handleCommands_sloc2_1_0 + 1),#0x00
   0797 AA 0E              1307 	mov	r2,_radioLinkRxMainLoopIndex
   0799 7C 00              1308 	mov	r4,#0x00
                    0268   1309 	C$test_radio_link.c$91$3$3 ==.
                           1310 ;	apps/test_radio_link/test_radio_link.c:91: responseLength = sprintf(response, "? RX=%d/%d, TX=%d/%d, M=%02x\r\n",
   079B C0 06              1311 	push	ar6
   079D C0 05              1312 	push	ar5
   079F C0 08              1313 	push	_handleCommands_sloc0_1_0
   07A1 C0 09              1314 	push	(_handleCommands_sloc0_1_0 + 1)
   07A3 C0 0A              1315 	push	_handleCommands_sloc1_1_0
   07A5 C0 0B              1316 	push	(_handleCommands_sloc1_1_0 + 1)
   07A7 C0 0C              1317 	push	_handleCommands_sloc2_1_0
   07A9 C0 0D              1318 	push	(_handleCommands_sloc2_1_0 + 1)
   07AB C0 02              1319 	push	ar2
   07AD C0 04              1320 	push	ar4
   07AF 74 4C              1321 	mov	a,#__str_3
   07B1 C0 E0              1322 	push	acc
   07B3 74 23              1323 	mov	a,#(__str_3 >> 8)
   07B5 C0 E0              1324 	push	acc
   07B7 74 80              1325 	mov	a,#0x80
   07B9 C0 E0              1326 	push	acc
   07BB 74 DD              1327 	mov	a,#_handleCommands_response_1_1
   07BD C0 E0              1328 	push	acc
   07BF 74 F0              1329 	mov	a,#(_handleCommands_response_1_1 >> 8)
   07C1 C0 E0              1330 	push	acc
   07C3 E4                 1331 	clr	a
   07C4 C0 E0              1332 	push	acc
   07C6 12 19 D4           1333 	lcall	_sprintf
   07C9 AD 82              1334 	mov	r5,dpl
   07CB E5 81              1335 	mov	a,sp
   07CD 24 F0              1336 	add	a,#0xf0
   07CF F5 81              1337 	mov	sp,a
                    029E   1338 	C$test_radio_link.c$94$3$3 ==.
                           1339 ;	apps/test_radio_link/test_radio_link.c:94: usbComTxSend(response, responseLength);
   07D1 78 0F              1340 	mov	r0,#_usbComTxSend_PARM_2
   07D3 ED                 1341 	mov	a,r5
   07D4 F2                 1342 	movx	@r0,a
   07D5 90 F0 DD           1343 	mov	dptr,#_handleCommands_response_1_1
   07D8 12 10 BF           1344 	lcall	_usbComTxSend
   07DB 02 08 E6           1345 	ljmp	00116$
   07DE                    1346 00111$:
                    02AB   1347 	C$test_radio_link.c$96$2$2 ==.
                           1348 ;	apps/test_radio_link/test_radio_link.c:96: else if (byte >= (uint8)'a' && byte <= (uint8)'g')
   07DE BD 61 00           1349 	cjne	r5,#0x61,00130$
   07E1                    1350 00130$:
   07E1 50 03              1351 	jnc	00131$
   07E3 02 08 E6           1352 	ljmp	00116$
   07E6                    1353 00131$:
   07E6 ED                 1354 	mov	a,r5
   07E7 24 98              1355 	add	a,#0xff - 0x67
   07E9 50 03              1356 	jnc	00132$
   07EB 02 08 E6           1357 	ljmp	00116$
   07EE                    1358 00132$:
                    02BB   1359 	C$test_radio_link.c$98$3$4 ==.
                           1360 ;	apps/test_radio_link/test_radio_link.c:98: uint8 XDATA * packet = radioLinkTxCurrentPacket();
   07EE C0 05              1361 	push	ar5
   07F0 12 09 74           1362 	lcall	_radioLinkTxCurrentPacket
   07F3 78 03              1363 	mov	r0,#_handleCommands_packet_3_4
   07F5 E5 82              1364 	mov	a,dpl
   07F7 F2                 1365 	movx	@r0,a
   07F8 08                 1366 	inc	r0
   07F9 E5 83              1367 	mov	a,dph
   07FB F2                 1368 	movx	@r0,a
   07FC D0 05              1369 	pop	ar5
                    02CB   1370 	C$test_radio_link.c$99$3$4 ==.
                           1371 ;	apps/test_radio_link/test_radio_link.c:99: if (packet == 0)
   07FE 78 03              1372 	mov	r0,#_handleCommands_packet_3_4
   0800 E2                 1373 	movx	a,@r0
   0801 F5 F0              1374 	mov	b,a
   0803 08                 1375 	inc	r0
   0804 E2                 1376 	movx	a,@r0
   0805 45 F0              1377 	orl	a,b
   0807 70 0E              1378 	jnz	00105$
                    02D6   1379 	C$test_radio_link.c$101$4$5 ==.
                           1380 ;	apps/test_radio_link/test_radio_link.c:101: usbComTxSend(txNotAvailable, sizeof(txNotAvailable));
   0809 78 0F              1381 	mov	r0,#_usbComTxSend_PARM_2
   080B 74 14              1382 	mov	a,#0x14
   080D F2                 1383 	movx	@r0,a
   080E 90 F0 C9           1384 	mov	dptr,#_handleCommands_txNotAvailable_1_1
   0811 12 10 BF           1385 	lcall	_usbComTxSend
   0814 02 08 E6           1386 	ljmp	00116$
   0817                    1387 00105$:
                    02E4   1388 	C$test_radio_link.c$105$4$6 ==.
                           1389 ;	apps/test_radio_link/test_radio_link.c:105: packet[0] = 3; // Packet length
   0817 78 03              1390 	mov	r0,#_handleCommands_packet_3_4
   0819 E2                 1391 	movx	a,@r0
   081A F5 82              1392 	mov	dpl,a
   081C 08                 1393 	inc	r0
   081D E2                 1394 	movx	a,@r0
   081E F5 83              1395 	mov	dph,a
   0820 74 03              1396 	mov	a,#0x03
   0822 F0                 1397 	movx	@dptr,a
                    02F0   1398 	C$test_radio_link.c$106$4$6 ==.
                           1399 ;	apps/test_radio_link/test_radio_link.c:106: packet[1] = byte;
   0823 78 03              1400 	mov	r0,#_handleCommands_packet_3_4
   0825 E2                 1401 	movx	a,@r0
   0826 24 01              1402 	add	a,#0x01
   0828 FB                 1403 	mov	r3,a
   0829 08                 1404 	inc	r0
   082A E2                 1405 	movx	a,@r0
   082B 34 00              1406 	addc	a,#0x00
   082D FC                 1407 	mov	r4,a
   082E 8B 82              1408 	mov	dpl,r3
   0830 8C 83              1409 	mov	dph,r4
   0832 ED                 1410 	mov	a,r5
   0833 F0                 1411 	movx	@dptr,a
                    0301   1412 	C$test_radio_link.c$107$4$6 ==.
                           1413 ;	apps/test_radio_link/test_radio_link.c:107: packet[2] = byte + 1;
   0834 78 03              1414 	mov	r0,#_handleCommands_packet_3_4
   0836 E2                 1415 	movx	a,@r0
   0837 24 02              1416 	add	a,#0x02
   0839 FA                 1417 	mov	r2,a
   083A 08                 1418 	inc	r0
   083B E2                 1419 	movx	a,@r0
   083C 34 00              1420 	addc	a,#0x00
   083E FF                 1421 	mov	r7,a
   083F ED                 1422 	mov	a,r5
   0840 04                 1423 	inc	a
   0841 8A 82              1424 	mov	dpl,r2
   0843 8F 83              1425 	mov	dph,r7
   0845 F0                 1426 	movx	@dptr,a
                    0313   1427 	C$test_radio_link.c$108$4$6 ==.
                           1428 ;	apps/test_radio_link/test_radio_link.c:108: packet[3] = byte + 2;
   0846 78 03              1429 	mov	r0,#_handleCommands_packet_3_4
   0848 E2                 1430 	movx	a,@r0
   0849 24 03              1431 	add	a,#0x03
   084B F5 0C              1432 	mov	_handleCommands_sloc2_1_0,a
   084D 08                 1433 	inc	r0
   084E E2                 1434 	movx	a,@r0
   084F 34 00              1435 	addc	a,#0x00
   0851 F5 0D              1436 	mov	(_handleCommands_sloc2_1_0 + 1),a
   0853 74 02              1437 	mov	a,#0x02
   0855 2D                 1438 	add	a,r5
   0856 85 0C 82           1439 	mov	dpl,_handleCommands_sloc2_1_0
   0859 85 0D 83           1440 	mov	dph,(_handleCommands_sloc2_1_0 + 1)
   085C F0                 1441 	movx	@dptr,a
                    032A   1442 	C$test_radio_link.c$109$4$6 ==.
                           1443 ;	apps/test_radio_link/test_radio_link.c:109: radioLinkTxSendPacket(payloadType);
   085D 78 02              1444 	mov	r0,#_handleCommands_payloadType_1_1
   085F E2                 1445 	movx	a,@r0
   0860 F5 82              1446 	mov	dpl,a
   0862 C0 07              1447 	push	ar7
   0864 C0 04              1448 	push	ar4
   0866 C0 03              1449 	push	ar3
   0868 C0 02              1450 	push	ar2
   086A 12 09 98           1451 	lcall	_radioLinkTxSendPacket
   086D D0 02              1452 	pop	ar2
   086F D0 03              1453 	pop	ar3
   0871 D0 04              1454 	pop	ar4
   0873 D0 07              1455 	pop	ar7
                    0342   1456 	C$test_radio_link.c$110$4$6 ==.
                           1457 ;	apps/test_radio_link/test_radio_link.c:110: responseLength = sprintf(response, "TX: %2d %02x%02x%02x\r\n", payloadType, packet[1], packet[2], packet[3]);
   0875 85 0C 82           1458 	mov	dpl,_handleCommands_sloc2_1_0
   0878 85 0D 83           1459 	mov	dph,(_handleCommands_sloc2_1_0 + 1)
   087B E0                 1460 	movx	a,@dptr
   087C FE                 1461 	mov	r6,a
   087D 7D 00              1462 	mov	r5,#0x00
   087F 8A 82              1463 	mov	dpl,r2
   0881 8F 83              1464 	mov	dph,r7
   0883 E0                 1465 	movx	a,@dptr
   0884 FA                 1466 	mov	r2,a
   0885 7F 00              1467 	mov	r7,#0x00
   0887 8B 82              1468 	mov	dpl,r3
   0889 8C 83              1469 	mov	dph,r4
   088B E0                 1470 	movx	a,@dptr
   088C FB                 1471 	mov	r3,a
   088D 8B 0C              1472 	mov	_handleCommands_sloc2_1_0,r3
   088F 75 0D 00           1473 	mov	(_handleCommands_sloc2_1_0 + 1),#0x00
   0892 78 02              1474 	mov	r0,#_handleCommands_payloadType_1_1
   0894 E2                 1475 	movx	a,@r0
   0895 FB                 1476 	mov	r3,a
   0896 7C 00              1477 	mov	r4,#0x00
   0898 C0 06              1478 	push	ar6
   089A C0 05              1479 	push	ar5
   089C C0 02              1480 	push	ar2
   089E C0 07              1481 	push	ar7
   08A0 C0 0C              1482 	push	_handleCommands_sloc2_1_0
   08A2 C0 0D              1483 	push	(_handleCommands_sloc2_1_0 + 1)
   08A4 C0 03              1484 	push	ar3
   08A6 C0 04              1485 	push	ar4
   08A8 74 6B              1486 	mov	a,#__str_4
   08AA C0 E0              1487 	push	acc
   08AC 74 23              1488 	mov	a,#(__str_4 >> 8)
   08AE C0 E0              1489 	push	acc
   08B0 74 80              1490 	mov	a,#0x80
   08B2 C0 E0              1491 	push	acc
   08B4 74 DD              1492 	mov	a,#_handleCommands_response_1_1
   08B6 C0 E0              1493 	push	acc
   08B8 74 F0              1494 	mov	a,#(_handleCommands_response_1_1 >> 8)
   08BA C0 E0              1495 	push	acc
   08BC E4                 1496 	clr	a
   08BD C0 E0              1497 	push	acc
   08BF 12 19 D4           1498 	lcall	_sprintf
   08C2 AE 82              1499 	mov	r6,dpl
   08C4 E5 81              1500 	mov	a,sp
   08C6 24 F2              1501 	add	a,#0xf2
   08C8 F5 81              1502 	mov	sp,a
   08CA 78 0F              1503 	mov	r0,#_usbComTxSend_PARM_2
   08CC EE                 1504 	mov	a,r6
   08CD F2                 1505 	movx	@r0,a
                    039B   1506 	C$test_radio_link.c$111$4$6 ==.
                           1507 ;	apps/test_radio_link/test_radio_link.c:111: usbComTxSend(response, responseLength);
   08CE 90 F0 DD           1508 	mov	dptr,#_handleCommands_response_1_1
   08D1 12 10 BF           1509 	lcall	_usbComTxSend
                    03A1   1510 	C$test_radio_link.c$112$4$6 ==.
                           1511 ;	apps/test_radio_link/test_radio_link.c:112: if (payloadType == RADIO_LINK_MAX_PAYLOAD_TYPE)
   08D4 78 02              1512 	mov	r0,#_handleCommands_payloadType_1_1
   08D6 E2                 1513 	movx	a,@r0
   08D7 B4 0F 06           1514 	cjne	a,#0x0F,00102$
                    03A7   1515 	C$test_radio_link.c$114$5$7 ==.
                           1516 ;	apps/test_radio_link/test_radio_link.c:114: payloadType = 0;
   08DA 78 02              1517 	mov	r0,#_handleCommands_payloadType_1_1
   08DC E4                 1518 	clr	a
   08DD F2                 1519 	movx	@r0,a
   08DE 80 06              1520 	sjmp	00116$
   08E0                    1521 00102$:
                    03AD   1522 	C$test_radio_link.c$118$5$8 ==.
                           1523 ;	apps/test_radio_link/test_radio_link.c:118: payloadType++;
   08E0 78 02              1524 	mov	r0,#_handleCommands_payloadType_1_1
   08E2 E2                 1525 	movx	a,@r0
   08E3 24 01              1526 	add	a,#0x01
   08E5 F2                 1527 	movx	@r0,a
   08E6                    1528 00116$:
                    03B3   1529 	C$test_radio_link.c$123$1$1 ==.
                    03B3   1530 	XG$handleCommands$0$0 ==.
   08E6 22                 1531 	ret
                           1532 ;------------------------------------------------------------
                           1533 ;Allocation info for local variables in function 'main'
                           1534 ;------------------------------------------------------------
                    03B4   1535 	G$main$0$0 ==.
                    03B4   1536 	C$test_radio_link.c$125$1$1 ==.
                           1537 ;	apps/test_radio_link/test_radio_link.c:125: void main()
                           1538 ;	-----------------------------------------
                           1539 ;	 function main
                           1540 ;	-----------------------------------------
   08E7                    1541 _main:
                    03B4   1542 	C$test_radio_link.c$127$1$1 ==.
                           1543 ;	apps/test_radio_link/test_radio_link.c:127: systemInit();
   08E7 12 17 AB           1544 	lcall	_systemInit
                    03B7   1545 	C$test_radio_link.c$128$1$1 ==.
                           1546 ;	apps/test_radio_link/test_radio_link.c:128: usbInit();
   08EA 12 11 45           1547 	lcall	_usbInit
                    03BA   1548 	C$test_radio_link.c$130$1$1 ==.
                           1549 ;	apps/test_radio_link/test_radio_link.c:130: radioLinkInit();
   08ED 12 09 14           1550 	lcall	_radioLinkInit
                    03BD   1551 	C$test_radio_link.c$131$1$1 ==.
                           1552 ;	apps/test_radio_link/test_radio_link.c:131: randomSeedFromAdc();
   08F0 12 22 D7           1553 	lcall	_randomSeedFromAdc
                    03C0   1554 	C$test_radio_link.c$134$1$1 ==.
                           1555 ;	apps/test_radio_link/test_radio_link.c:134: P1DIR |= (1<<6) | (1<<7);
   08F3 43 FE C0           1556 	orl	_P1DIR,#0xC0
                    03C3   1557 	C$test_radio_link.c$135$1$1 ==.
                           1558 ;	apps/test_radio_link/test_radio_link.c:135: IOCFG1 = 0b001000; // P1_6 = Preamble Quality Reached
   08F6 90 DF 30           1559 	mov	dptr,#_IOCFG1
   08F9 74 08              1560 	mov	a,#0x08
   08FB F0                 1561 	movx	@dptr,a
                    03C9   1562 	C$test_radio_link.c$136$1$1 ==.
                           1563 ;	apps/test_radio_link/test_radio_link.c:136: IOCFG2 = 0b011011; // P1_7 = PA_PD (TX mode)
   08FC 90 DF 2F           1564 	mov	dptr,#_IOCFG2
   08FF 74 1B              1565 	mov	a,#0x1B
   0901 F0                 1566 	movx	@dptr,a
                    03CF   1567 	C$test_radio_link.c$138$1$1 ==.
                           1568 ;	apps/test_radio_link/test_radio_link.c:138: while(1)
   0902                    1569 00102$:
                    03CF   1570 	C$test_radio_link.c$140$2$2 ==.
                           1571 ;	apps/test_radio_link/test_radio_link.c:140: boardService();
   0902 12 17 B8           1572 	lcall	_boardService
                    03D2   1573 	C$test_radio_link.c$141$2$2 ==.
                           1574 ;	apps/test_radio_link/test_radio_link.c:141: updateLeds();
   0905 12 05 33           1575 	lcall	_updateLeds
                    03D5   1576 	C$test_radio_link.c$142$2$2 ==.
                           1577 ;	apps/test_radio_link/test_radio_link.c:142: radioToUsb();
   0908 12 05 75           1578 	lcall	_radioToUsb
                    03D8   1579 	C$test_radio_link.c$143$2$2 ==.
                           1580 ;	apps/test_radio_link/test_radio_link.c:143: handleCommands();
   090B 12 06 E8           1581 	lcall	_handleCommands
                    03DB   1582 	C$test_radio_link.c$144$2$2 ==.
                           1583 ;	apps/test_radio_link/test_radio_link.c:144: usbComService();
   090E 12 0F E3           1584 	lcall	_usbComService
   0911 80 EF              1585 	sjmp	00102$
                    03E0   1586 	C$test_radio_link.c$146$1$1 ==.
                    03E0   1587 	XG$main$0$0 ==.
   0913 22                 1588 	ret
                           1589 	.area CSEG    (CODE)
                           1590 	.area CONST   (CODE)
                    0000   1591 Ltest_radio_link.radioToUsb$resetString$1$1 == .
   2337                    1592 _radioToUsb_resetString_1_1:
   2337 52 58 3A 20 52 45  1593 	.ascii "RX: RESET"
        53 45 54
   2340 0D                 1594 	.db 0x0D
   2341 0A                 1595 	.db 0x0A
   2342 00                 1596 	.db 0x00
                    000C   1597 Ftest_radio_link$_str_1$0$0 == .
   2343                    1598 __str_1:
   2343 52 58 3A 20 25 32  1599 	.ascii "RX: %2d "
        64 20
   234B 00                 1600 	.db 0x00
                    0015   1601 Ftest_radio_link$_str_3$0$0 == .
   234C                    1602 __str_3:
   234C 3F 20 52 58 3D 25  1603 	.ascii "? RX=%d/%d, TX=%d/%d, M=%02x"
        64 2F 25 64 2C 20
        54 58 3D 25 64 2F
        25 64 2C 20 4D 3D
        25 30 32 78
   2368 0D                 1604 	.db 0x0D
   2369 0A                 1605 	.db 0x0A
   236A 00                 1606 	.db 0x00
                    0034   1607 Ftest_radio_link$_str_4$0$0 == .
   236B                    1608 __str_4:
   236B 54 58 3A 20 25 32  1609 	.ascii "TX: %2d %02x%02x%02x"
        64 20 25 30 32 78
        25 30 32 78 25 30
        32 78
   237F 0D                 1610 	.db 0x0D
   2380 0A                 1611 	.db 0x0A
   2381 00                 1612 	.db 0x00
                           1613 	.area XINIT   (CODE)
                           1614 	.area CABS    (ABS,CODE)
