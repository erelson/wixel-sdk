                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:55 2012
                              5 ;--------------------------------------------------------
                              6 	.module io_repeater
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_P2_1_link
                             13 	.globl _param_P1_7_link
                             14 	.globl _param_P1_6_link
                             15 	.globl _param_P1_5_link
                             16 	.globl _param_P1_4_link
                             17 	.globl _param_P1_3_link
                             18 	.globl _param_P1_2_link
                             19 	.globl _param_P1_1_link
                             20 	.globl _param_P1_0_link
                             21 	.globl _param_P0_5_link
                             22 	.globl _param_P0_4_link
                             23 	.globl _param_P0_3_link
                             24 	.globl _param_P0_2_link
                             25 	.globl _param_P0_1_link
                             26 	.globl _param_P0_0_link
                             27 	.globl _main
                             28 	.globl _setPins
                             29 	.globl _readPins
                             30 	.globl _configurePins
                             31 	.globl _pinLink
                             32 	.globl _updateLeds
                             33 	.globl _adcRead
                             34 	.globl _radioQueueRxDoneWithPacket
                             35 	.globl _radioQueueRxCurrentPacket
                             36 	.globl _radioQueueTxSendPacket
                             37 	.globl _radioQueueTxCurrentPacket
                             38 	.globl _radioQueueInit
                             39 	.globl _setPort1PullType
                             40 	.globl _setPort0PullType
                             41 	.globl _isPinHigh
                             42 	.globl _setDigitalOutput
                             43 	.globl _usbComService
                             44 	.globl _getMs
                             45 	.globl _usbShowStatusWithGreenLed
                             46 	.globl _usbInit
                             47 	.globl _vinPowerPresent
                             48 	.globl _boardService
                             49 	.globl _systemInit
                             50 	.globl _setPins_PARM_2
                             51 ;--------------------------------------------------------
                             52 ; special function registers
                             53 ;--------------------------------------------------------
                             54 	.area RSEG    (ABS,DATA)
   0000                      55 	.org 0x0000
                    0080     56 Fio_repeater$P0$0$0 == 0x0080
                    0080     57 _P0	=	0x0080
                    0081     58 Fio_repeater$SP$0$0 == 0x0081
                    0081     59 _SP	=	0x0081
                    0082     60 Fio_repeater$DPL0$0$0 == 0x0082
                    0082     61 _DPL0	=	0x0082
                    0083     62 Fio_repeater$DPH0$0$0 == 0x0083
                    0083     63 _DPH0	=	0x0083
                    0084     64 Fio_repeater$DPL1$0$0 == 0x0084
                    0084     65 _DPL1	=	0x0084
                    0085     66 Fio_repeater$DPH1$0$0 == 0x0085
                    0085     67 _DPH1	=	0x0085
                    0086     68 Fio_repeater$U0CSR$0$0 == 0x0086
                    0086     69 _U0CSR	=	0x0086
                    0087     70 Fio_repeater$PCON$0$0 == 0x0087
                    0087     71 _PCON	=	0x0087
                    0088     72 Fio_repeater$TCON$0$0 == 0x0088
                    0088     73 _TCON	=	0x0088
                    0089     74 Fio_repeater$P0IFG$0$0 == 0x0089
                    0089     75 _P0IFG	=	0x0089
                    008A     76 Fio_repeater$P1IFG$0$0 == 0x008a
                    008A     77 _P1IFG	=	0x008a
                    008B     78 Fio_repeater$P2IFG$0$0 == 0x008b
                    008B     79 _P2IFG	=	0x008b
                    008C     80 Fio_repeater$PICTL$0$0 == 0x008c
                    008C     81 _PICTL	=	0x008c
                    008D     82 Fio_repeater$P1IEN$0$0 == 0x008d
                    008D     83 _P1IEN	=	0x008d
                    008F     84 Fio_repeater$P0INP$0$0 == 0x008f
                    008F     85 _P0INP	=	0x008f
                    0090     86 Fio_repeater$P1$0$0 == 0x0090
                    0090     87 _P1	=	0x0090
                    0091     88 Fio_repeater$RFIM$0$0 == 0x0091
                    0091     89 _RFIM	=	0x0091
                    0092     90 Fio_repeater$DPS$0$0 == 0x0092
                    0092     91 _DPS	=	0x0092
                    0093     92 Fio_repeater$MPAGE$0$0 == 0x0093
                    0093     93 _MPAGE	=	0x0093
                    0095     94 Fio_repeater$ENDIAN$0$0 == 0x0095
                    0095     95 _ENDIAN	=	0x0095
                    0098     96 Fio_repeater$S0CON$0$0 == 0x0098
                    0098     97 _S0CON	=	0x0098
                    009A     98 Fio_repeater$IEN2$0$0 == 0x009a
                    009A     99 _IEN2	=	0x009a
                    009B    100 Fio_repeater$S1CON$0$0 == 0x009b
                    009B    101 _S1CON	=	0x009b
                    009C    102 Fio_repeater$T2CT$0$0 == 0x009c
                    009C    103 _T2CT	=	0x009c
                    009D    104 Fio_repeater$T2PR$0$0 == 0x009d
                    009D    105 _T2PR	=	0x009d
                    009E    106 Fio_repeater$T2CTL$0$0 == 0x009e
                    009E    107 _T2CTL	=	0x009e
                    00A0    108 Fio_repeater$P2$0$0 == 0x00a0
                    00A0    109 _P2	=	0x00a0
                    00A1    110 Fio_repeater$WORIRQ$0$0 == 0x00a1
                    00A1    111 _WORIRQ	=	0x00a1
                    00A2    112 Fio_repeater$WORCTRL$0$0 == 0x00a2
                    00A2    113 _WORCTRL	=	0x00a2
                    00A3    114 Fio_repeater$WOREVT0$0$0 == 0x00a3
                    00A3    115 _WOREVT0	=	0x00a3
                    00A4    116 Fio_repeater$WOREVT1$0$0 == 0x00a4
                    00A4    117 _WOREVT1	=	0x00a4
                    00A5    118 Fio_repeater$WORTIME0$0$0 == 0x00a5
                    00A5    119 _WORTIME0	=	0x00a5
                    00A6    120 Fio_repeater$WORTIME1$0$0 == 0x00a6
                    00A6    121 _WORTIME1	=	0x00a6
                    00A8    122 Fio_repeater$IEN0$0$0 == 0x00a8
                    00A8    123 _IEN0	=	0x00a8
                    00A9    124 Fio_repeater$IP0$0$0 == 0x00a9
                    00A9    125 _IP0	=	0x00a9
                    00AB    126 Fio_repeater$FWT$0$0 == 0x00ab
                    00AB    127 _FWT	=	0x00ab
                    00AC    128 Fio_repeater$FADDRL$0$0 == 0x00ac
                    00AC    129 _FADDRL	=	0x00ac
                    00AD    130 Fio_repeater$FADDRH$0$0 == 0x00ad
                    00AD    131 _FADDRH	=	0x00ad
                    00AE    132 Fio_repeater$FCTL$0$0 == 0x00ae
                    00AE    133 _FCTL	=	0x00ae
                    00AF    134 Fio_repeater$FWDATA$0$0 == 0x00af
                    00AF    135 _FWDATA	=	0x00af
                    00B1    136 Fio_repeater$ENCDI$0$0 == 0x00b1
                    00B1    137 _ENCDI	=	0x00b1
                    00B2    138 Fio_repeater$ENCDO$0$0 == 0x00b2
                    00B2    139 _ENCDO	=	0x00b2
                    00B3    140 Fio_repeater$ENCCS$0$0 == 0x00b3
                    00B3    141 _ENCCS	=	0x00b3
                    00B4    142 Fio_repeater$ADCCON1$0$0 == 0x00b4
                    00B4    143 _ADCCON1	=	0x00b4
                    00B5    144 Fio_repeater$ADCCON2$0$0 == 0x00b5
                    00B5    145 _ADCCON2	=	0x00b5
                    00B6    146 Fio_repeater$ADCCON3$0$0 == 0x00b6
                    00B6    147 _ADCCON3	=	0x00b6
                    00B8    148 Fio_repeater$IEN1$0$0 == 0x00b8
                    00B8    149 _IEN1	=	0x00b8
                    00B9    150 Fio_repeater$IP1$0$0 == 0x00b9
                    00B9    151 _IP1	=	0x00b9
                    00BA    152 Fio_repeater$ADCL$0$0 == 0x00ba
                    00BA    153 _ADCL	=	0x00ba
                    00BB    154 Fio_repeater$ADCH$0$0 == 0x00bb
                    00BB    155 _ADCH	=	0x00bb
                    00BC    156 Fio_repeater$RNDL$0$0 == 0x00bc
                    00BC    157 _RNDL	=	0x00bc
                    00BD    158 Fio_repeater$RNDH$0$0 == 0x00bd
                    00BD    159 _RNDH	=	0x00bd
                    00BE    160 Fio_repeater$SLEEP$0$0 == 0x00be
                    00BE    161 _SLEEP	=	0x00be
                    00C0    162 Fio_repeater$IRCON$0$0 == 0x00c0
                    00C0    163 _IRCON	=	0x00c0
                    00C1    164 Fio_repeater$U0DBUF$0$0 == 0x00c1
                    00C1    165 _U0DBUF	=	0x00c1
                    00C2    166 Fio_repeater$U0BAUD$0$0 == 0x00c2
                    00C2    167 _U0BAUD	=	0x00c2
                    00C4    168 Fio_repeater$U0UCR$0$0 == 0x00c4
                    00C4    169 _U0UCR	=	0x00c4
                    00C5    170 Fio_repeater$U0GCR$0$0 == 0x00c5
                    00C5    171 _U0GCR	=	0x00c5
                    00C6    172 Fio_repeater$CLKCON$0$0 == 0x00c6
                    00C6    173 _CLKCON	=	0x00c6
                    00C7    174 Fio_repeater$MEMCTR$0$0 == 0x00c7
                    00C7    175 _MEMCTR	=	0x00c7
                    00C9    176 Fio_repeater$WDCTL$0$0 == 0x00c9
                    00C9    177 _WDCTL	=	0x00c9
                    00CA    178 Fio_repeater$T3CNT$0$0 == 0x00ca
                    00CA    179 _T3CNT	=	0x00ca
                    00CB    180 Fio_repeater$T3CTL$0$0 == 0x00cb
                    00CB    181 _T3CTL	=	0x00cb
                    00CC    182 Fio_repeater$T3CCTL0$0$0 == 0x00cc
                    00CC    183 _T3CCTL0	=	0x00cc
                    00CD    184 Fio_repeater$T3CC0$0$0 == 0x00cd
                    00CD    185 _T3CC0	=	0x00cd
                    00CE    186 Fio_repeater$T3CCTL1$0$0 == 0x00ce
                    00CE    187 _T3CCTL1	=	0x00ce
                    00CF    188 Fio_repeater$T3CC1$0$0 == 0x00cf
                    00CF    189 _T3CC1	=	0x00cf
                    00D0    190 Fio_repeater$PSW$0$0 == 0x00d0
                    00D0    191 _PSW	=	0x00d0
                    00D1    192 Fio_repeater$DMAIRQ$0$0 == 0x00d1
                    00D1    193 _DMAIRQ	=	0x00d1
                    00D2    194 Fio_repeater$DMA1CFGL$0$0 == 0x00d2
                    00D2    195 _DMA1CFGL	=	0x00d2
                    00D3    196 Fio_repeater$DMA1CFGH$0$0 == 0x00d3
                    00D3    197 _DMA1CFGH	=	0x00d3
                    00D4    198 Fio_repeater$DMA0CFGL$0$0 == 0x00d4
                    00D4    199 _DMA0CFGL	=	0x00d4
                    00D5    200 Fio_repeater$DMA0CFGH$0$0 == 0x00d5
                    00D5    201 _DMA0CFGH	=	0x00d5
                    00D6    202 Fio_repeater$DMAARM$0$0 == 0x00d6
                    00D6    203 _DMAARM	=	0x00d6
                    00D7    204 Fio_repeater$DMAREQ$0$0 == 0x00d7
                    00D7    205 _DMAREQ	=	0x00d7
                    00D8    206 Fio_repeater$TIMIF$0$0 == 0x00d8
                    00D8    207 _TIMIF	=	0x00d8
                    00D9    208 Fio_repeater$RFD$0$0 == 0x00d9
                    00D9    209 _RFD	=	0x00d9
                    00DA    210 Fio_repeater$T1CC0L$0$0 == 0x00da
                    00DA    211 _T1CC0L	=	0x00da
                    00DB    212 Fio_repeater$T1CC0H$0$0 == 0x00db
                    00DB    213 _T1CC0H	=	0x00db
                    00DC    214 Fio_repeater$T1CC1L$0$0 == 0x00dc
                    00DC    215 _T1CC1L	=	0x00dc
                    00DD    216 Fio_repeater$T1CC1H$0$0 == 0x00dd
                    00DD    217 _T1CC1H	=	0x00dd
                    00DE    218 Fio_repeater$T1CC2L$0$0 == 0x00de
                    00DE    219 _T1CC2L	=	0x00de
                    00DF    220 Fio_repeater$T1CC2H$0$0 == 0x00df
                    00DF    221 _T1CC2H	=	0x00df
                    00E0    222 Fio_repeater$ACC$0$0 == 0x00e0
                    00E0    223 _ACC	=	0x00e0
                    00E1    224 Fio_repeater$RFST$0$0 == 0x00e1
                    00E1    225 _RFST	=	0x00e1
                    00E2    226 Fio_repeater$T1CNTL$0$0 == 0x00e2
                    00E2    227 _T1CNTL	=	0x00e2
                    00E3    228 Fio_repeater$T1CNTH$0$0 == 0x00e3
                    00E3    229 _T1CNTH	=	0x00e3
                    00E4    230 Fio_repeater$T1CTL$0$0 == 0x00e4
                    00E4    231 _T1CTL	=	0x00e4
                    00E5    232 Fio_repeater$T1CCTL0$0$0 == 0x00e5
                    00E5    233 _T1CCTL0	=	0x00e5
                    00E6    234 Fio_repeater$T1CCTL1$0$0 == 0x00e6
                    00E6    235 _T1CCTL1	=	0x00e6
                    00E7    236 Fio_repeater$T1CCTL2$0$0 == 0x00e7
                    00E7    237 _T1CCTL2	=	0x00e7
                    00E8    238 Fio_repeater$IRCON2$0$0 == 0x00e8
                    00E8    239 _IRCON2	=	0x00e8
                    00E9    240 Fio_repeater$RFIF$0$0 == 0x00e9
                    00E9    241 _RFIF	=	0x00e9
                    00EA    242 Fio_repeater$T4CNT$0$0 == 0x00ea
                    00EA    243 _T4CNT	=	0x00ea
                    00EB    244 Fio_repeater$T4CTL$0$0 == 0x00eb
                    00EB    245 _T4CTL	=	0x00eb
                    00EC    246 Fio_repeater$T4CCTL0$0$0 == 0x00ec
                    00EC    247 _T4CCTL0	=	0x00ec
                    00ED    248 Fio_repeater$T4CC0$0$0 == 0x00ed
                    00ED    249 _T4CC0	=	0x00ed
                    00EE    250 Fio_repeater$T4CCTL1$0$0 == 0x00ee
                    00EE    251 _T4CCTL1	=	0x00ee
                    00EF    252 Fio_repeater$T4CC1$0$0 == 0x00ef
                    00EF    253 _T4CC1	=	0x00ef
                    00F0    254 Fio_repeater$B$0$0 == 0x00f0
                    00F0    255 _B	=	0x00f0
                    00F1    256 Fio_repeater$PERCFG$0$0 == 0x00f1
                    00F1    257 _PERCFG	=	0x00f1
                    00F2    258 Fio_repeater$ADCCFG$0$0 == 0x00f2
                    00F2    259 _ADCCFG	=	0x00f2
                    00F3    260 Fio_repeater$P0SEL$0$0 == 0x00f3
                    00F3    261 _P0SEL	=	0x00f3
                    00F4    262 Fio_repeater$P1SEL$0$0 == 0x00f4
                    00F4    263 _P1SEL	=	0x00f4
                    00F5    264 Fio_repeater$P2SEL$0$0 == 0x00f5
                    00F5    265 _P2SEL	=	0x00f5
                    00F6    266 Fio_repeater$P1INP$0$0 == 0x00f6
                    00F6    267 _P1INP	=	0x00f6
                    00F7    268 Fio_repeater$P2INP$0$0 == 0x00f7
                    00F7    269 _P2INP	=	0x00f7
                    00F8    270 Fio_repeater$U1CSR$0$0 == 0x00f8
                    00F8    271 _U1CSR	=	0x00f8
                    00F9    272 Fio_repeater$U1DBUF$0$0 == 0x00f9
                    00F9    273 _U1DBUF	=	0x00f9
                    00FA    274 Fio_repeater$U1BAUD$0$0 == 0x00fa
                    00FA    275 _U1BAUD	=	0x00fa
                    00FB    276 Fio_repeater$U1UCR$0$0 == 0x00fb
                    00FB    277 _U1UCR	=	0x00fb
                    00FC    278 Fio_repeater$U1GCR$0$0 == 0x00fc
                    00FC    279 _U1GCR	=	0x00fc
                    00FD    280 Fio_repeater$P0DIR$0$0 == 0x00fd
                    00FD    281 _P0DIR	=	0x00fd
                    00FE    282 Fio_repeater$P1DIR$0$0 == 0x00fe
                    00FE    283 _P1DIR	=	0x00fe
                    00FF    284 Fio_repeater$P2DIR$0$0 == 0x00ff
                    00FF    285 _P2DIR	=	0x00ff
                    FFFFD5D4    286 Fio_repeater$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    287 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    288 Fio_repeater$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    289 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    290 Fio_repeater$FADDR$0$0 == 0xffffadac
                    FFFFADAC    291 _FADDR	=	0xffffadac
                    FFFFBBBA    292 Fio_repeater$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    293 _ADC	=	0xffffbbba
                    FFFFDBDA    294 Fio_repeater$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    295 _T1CC0	=	0xffffdbda
                    FFFFDDDC    296 Fio_repeater$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    297 _T1CC1	=	0xffffdddc
                    FFFFDFDE    298 Fio_repeater$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    299 _T1CC2	=	0xffffdfde
                            300 ;--------------------------------------------------------
                            301 ; special function bits
                            302 ;--------------------------------------------------------
                            303 	.area RSEG    (ABS,DATA)
   0000                     304 	.org 0x0000
                    0080    305 Fio_repeater$P0_0$0$0 == 0x0080
                    0080    306 _P0_0	=	0x0080
                    0081    307 Fio_repeater$P0_1$0$0 == 0x0081
                    0081    308 _P0_1	=	0x0081
                    0082    309 Fio_repeater$P0_2$0$0 == 0x0082
                    0082    310 _P0_2	=	0x0082
                    0083    311 Fio_repeater$P0_3$0$0 == 0x0083
                    0083    312 _P0_3	=	0x0083
                    0084    313 Fio_repeater$P0_4$0$0 == 0x0084
                    0084    314 _P0_4	=	0x0084
                    0085    315 Fio_repeater$P0_5$0$0 == 0x0085
                    0085    316 _P0_5	=	0x0085
                    0086    317 Fio_repeater$P0_6$0$0 == 0x0086
                    0086    318 _P0_6	=	0x0086
                    0087    319 Fio_repeater$P0_7$0$0 == 0x0087
                    0087    320 _P0_7	=	0x0087
                    0088    321 Fio_repeater$_TCON_0$0$0 == 0x0088
                    0088    322 __TCON_0	=	0x0088
                    0089    323 Fio_repeater$RFTXRXIF$0$0 == 0x0089
                    0089    324 _RFTXRXIF	=	0x0089
                    008A    325 Fio_repeater$_TCON_2$0$0 == 0x008a
                    008A    326 __TCON_2	=	0x008a
                    008B    327 Fio_repeater$URX0IF$0$0 == 0x008b
                    008B    328 _URX0IF	=	0x008b
                    008C    329 Fio_repeater$_TCON_4$0$0 == 0x008c
                    008C    330 __TCON_4	=	0x008c
                    008D    331 Fio_repeater$ADCIF$0$0 == 0x008d
                    008D    332 _ADCIF	=	0x008d
                    008E    333 Fio_repeater$_TCON_6$0$0 == 0x008e
                    008E    334 __TCON_6	=	0x008e
                    008F    335 Fio_repeater$URX1IF$0$0 == 0x008f
                    008F    336 _URX1IF	=	0x008f
                    0090    337 Fio_repeater$P1_0$0$0 == 0x0090
                    0090    338 _P1_0	=	0x0090
                    0091    339 Fio_repeater$P1_1$0$0 == 0x0091
                    0091    340 _P1_1	=	0x0091
                    0092    341 Fio_repeater$P1_2$0$0 == 0x0092
                    0092    342 _P1_2	=	0x0092
                    0093    343 Fio_repeater$P1_3$0$0 == 0x0093
                    0093    344 _P1_3	=	0x0093
                    0094    345 Fio_repeater$P1_4$0$0 == 0x0094
                    0094    346 _P1_4	=	0x0094
                    0095    347 Fio_repeater$P1_5$0$0 == 0x0095
                    0095    348 _P1_5	=	0x0095
                    0096    349 Fio_repeater$P1_6$0$0 == 0x0096
                    0096    350 _P1_6	=	0x0096
                    0097    351 Fio_repeater$P1_7$0$0 == 0x0097
                    0097    352 _P1_7	=	0x0097
                    0098    353 Fio_repeater$ENCIF_0$0$0 == 0x0098
                    0098    354 _ENCIF_0	=	0x0098
                    0099    355 Fio_repeater$ENCIF_1$0$0 == 0x0099
                    0099    356 _ENCIF_1	=	0x0099
                    009A    357 Fio_repeater$_SOCON2$0$0 == 0x009a
                    009A    358 __SOCON2	=	0x009a
                    009B    359 Fio_repeater$_SOCON3$0$0 == 0x009b
                    009B    360 __SOCON3	=	0x009b
                    009C    361 Fio_repeater$_SOCON4$0$0 == 0x009c
                    009C    362 __SOCON4	=	0x009c
                    009D    363 Fio_repeater$_SOCON5$0$0 == 0x009d
                    009D    364 __SOCON5	=	0x009d
                    009E    365 Fio_repeater$_SOCON6$0$0 == 0x009e
                    009E    366 __SOCON6	=	0x009e
                    009F    367 Fio_repeater$_SOCON7$0$0 == 0x009f
                    009F    368 __SOCON7	=	0x009f
                    00A0    369 Fio_repeater$P2_0$0$0 == 0x00a0
                    00A0    370 _P2_0	=	0x00a0
                    00A1    371 Fio_repeater$P2_1$0$0 == 0x00a1
                    00A1    372 _P2_1	=	0x00a1
                    00A2    373 Fio_repeater$P2_2$0$0 == 0x00a2
                    00A2    374 _P2_2	=	0x00a2
                    00A3    375 Fio_repeater$P2_3$0$0 == 0x00a3
                    00A3    376 _P2_3	=	0x00a3
                    00A4    377 Fio_repeater$P2_4$0$0 == 0x00a4
                    00A4    378 _P2_4	=	0x00a4
                    00A5    379 Fio_repeater$P2_5$0$0 == 0x00a5
                    00A5    380 _P2_5	=	0x00a5
                    00A6    381 Fio_repeater$P2_6$0$0 == 0x00a6
                    00A6    382 _P2_6	=	0x00a6
                    00A7    383 Fio_repeater$P2_7$0$0 == 0x00a7
                    00A7    384 _P2_7	=	0x00a7
                    00A8    385 Fio_repeater$RFTXRXIE$0$0 == 0x00a8
                    00A8    386 _RFTXRXIE	=	0x00a8
                    00A9    387 Fio_repeater$ADCIE$0$0 == 0x00a9
                    00A9    388 _ADCIE	=	0x00a9
                    00AA    389 Fio_repeater$URX0IE$0$0 == 0x00aa
                    00AA    390 _URX0IE	=	0x00aa
                    00AB    391 Fio_repeater$URX1IE$0$0 == 0x00ab
                    00AB    392 _URX1IE	=	0x00ab
                    00AC    393 Fio_repeater$ENCIE$0$0 == 0x00ac
                    00AC    394 _ENCIE	=	0x00ac
                    00AD    395 Fio_repeater$STIE$0$0 == 0x00ad
                    00AD    396 _STIE	=	0x00ad
                    00AE    397 Fio_repeater$_IEN06$0$0 == 0x00ae
                    00AE    398 __IEN06	=	0x00ae
                    00AF    399 Fio_repeater$EA$0$0 == 0x00af
                    00AF    400 _EA	=	0x00af
                    00B8    401 Fio_repeater$DMAIE$0$0 == 0x00b8
                    00B8    402 _DMAIE	=	0x00b8
                    00B9    403 Fio_repeater$T1IE$0$0 == 0x00b9
                    00B9    404 _T1IE	=	0x00b9
                    00BA    405 Fio_repeater$T2IE$0$0 == 0x00ba
                    00BA    406 _T2IE	=	0x00ba
                    00BB    407 Fio_repeater$T3IE$0$0 == 0x00bb
                    00BB    408 _T3IE	=	0x00bb
                    00BC    409 Fio_repeater$T4IE$0$0 == 0x00bc
                    00BC    410 _T4IE	=	0x00bc
                    00BD    411 Fio_repeater$P0IE$0$0 == 0x00bd
                    00BD    412 _P0IE	=	0x00bd
                    00BE    413 Fio_repeater$_IEN16$0$0 == 0x00be
                    00BE    414 __IEN16	=	0x00be
                    00BF    415 Fio_repeater$_IEN17$0$0 == 0x00bf
                    00BF    416 __IEN17	=	0x00bf
                    00C0    417 Fio_repeater$DMAIF$0$0 == 0x00c0
                    00C0    418 _DMAIF	=	0x00c0
                    00C1    419 Fio_repeater$T1IF$0$0 == 0x00c1
                    00C1    420 _T1IF	=	0x00c1
                    00C2    421 Fio_repeater$T2IF$0$0 == 0x00c2
                    00C2    422 _T2IF	=	0x00c2
                    00C3    423 Fio_repeater$T3IF$0$0 == 0x00c3
                    00C3    424 _T3IF	=	0x00c3
                    00C4    425 Fio_repeater$T4IF$0$0 == 0x00c4
                    00C4    426 _T4IF	=	0x00c4
                    00C5    427 Fio_repeater$P0IF$0$0 == 0x00c5
                    00C5    428 _P0IF	=	0x00c5
                    00C6    429 Fio_repeater$_IRCON6$0$0 == 0x00c6
                    00C6    430 __IRCON6	=	0x00c6
                    00C7    431 Fio_repeater$STIF$0$0 == 0x00c7
                    00C7    432 _STIF	=	0x00c7
                    00D0    433 Fio_repeater$P$0$0 == 0x00d0
                    00D0    434 _P	=	0x00d0
                    00D1    435 Fio_repeater$F1$0$0 == 0x00d1
                    00D1    436 _F1	=	0x00d1
                    00D2    437 Fio_repeater$OV$0$0 == 0x00d2
                    00D2    438 _OV	=	0x00d2
                    00D3    439 Fio_repeater$RS0$0$0 == 0x00d3
                    00D3    440 _RS0	=	0x00d3
                    00D4    441 Fio_repeater$RS1$0$0 == 0x00d4
                    00D4    442 _RS1	=	0x00d4
                    00D5    443 Fio_repeater$F0$0$0 == 0x00d5
                    00D5    444 _F0	=	0x00d5
                    00D6    445 Fio_repeater$AC$0$0 == 0x00d6
                    00D6    446 _AC	=	0x00d6
                    00D7    447 Fio_repeater$CY$0$0 == 0x00d7
                    00D7    448 _CY	=	0x00d7
                    00D8    449 Fio_repeater$T3OVFIF$0$0 == 0x00d8
                    00D8    450 _T3OVFIF	=	0x00d8
                    00D9    451 Fio_repeater$T3CH0IF$0$0 == 0x00d9
                    00D9    452 _T3CH0IF	=	0x00d9
                    00DA    453 Fio_repeater$T3CH1IF$0$0 == 0x00da
                    00DA    454 _T3CH1IF	=	0x00da
                    00DB    455 Fio_repeater$T4OVFIF$0$0 == 0x00db
                    00DB    456 _T4OVFIF	=	0x00db
                    00DC    457 Fio_repeater$T4CH0IF$0$0 == 0x00dc
                    00DC    458 _T4CH0IF	=	0x00dc
                    00DD    459 Fio_repeater$T4CH1IF$0$0 == 0x00dd
                    00DD    460 _T4CH1IF	=	0x00dd
                    00DE    461 Fio_repeater$OVFIM$0$0 == 0x00de
                    00DE    462 _OVFIM	=	0x00de
                    00DF    463 Fio_repeater$_TIMIF7$0$0 == 0x00df
                    00DF    464 __TIMIF7	=	0x00df
                    00E0    465 Fio_repeater$ACC_0$0$0 == 0x00e0
                    00E0    466 _ACC_0	=	0x00e0
                    00E1    467 Fio_repeater$ACC_1$0$0 == 0x00e1
                    00E1    468 _ACC_1	=	0x00e1
                    00E2    469 Fio_repeater$ACC_2$0$0 == 0x00e2
                    00E2    470 _ACC_2	=	0x00e2
                    00E3    471 Fio_repeater$ACC_3$0$0 == 0x00e3
                    00E3    472 _ACC_3	=	0x00e3
                    00E4    473 Fio_repeater$ACC_4$0$0 == 0x00e4
                    00E4    474 _ACC_4	=	0x00e4
                    00E5    475 Fio_repeater$ACC_5$0$0 == 0x00e5
                    00E5    476 _ACC_5	=	0x00e5
                    00E6    477 Fio_repeater$ACC_6$0$0 == 0x00e6
                    00E6    478 _ACC_6	=	0x00e6
                    00E7    479 Fio_repeater$ACC_7$0$0 == 0x00e7
                    00E7    480 _ACC_7	=	0x00e7
                    00E8    481 Fio_repeater$P2IF$0$0 == 0x00e8
                    00E8    482 _P2IF	=	0x00e8
                    00E9    483 Fio_repeater$UTX0IF$0$0 == 0x00e9
                    00E9    484 _UTX0IF	=	0x00e9
                    00EA    485 Fio_repeater$UTX1IF$0$0 == 0x00ea
                    00EA    486 _UTX1IF	=	0x00ea
                    00EB    487 Fio_repeater$P1IF$0$0 == 0x00eb
                    00EB    488 _P1IF	=	0x00eb
                    00EC    489 Fio_repeater$WDTIF$0$0 == 0x00ec
                    00EC    490 _WDTIF	=	0x00ec
                    00ED    491 Fio_repeater$_IRCON25$0$0 == 0x00ed
                    00ED    492 __IRCON25	=	0x00ed
                    00EE    493 Fio_repeater$_IRCON26$0$0 == 0x00ee
                    00EE    494 __IRCON26	=	0x00ee
                    00EF    495 Fio_repeater$_IRCON27$0$0 == 0x00ef
                    00EF    496 __IRCON27	=	0x00ef
                    00F0    497 Fio_repeater$B_0$0$0 == 0x00f0
                    00F0    498 _B_0	=	0x00f0
                    00F1    499 Fio_repeater$B_1$0$0 == 0x00f1
                    00F1    500 _B_1	=	0x00f1
                    00F2    501 Fio_repeater$B_2$0$0 == 0x00f2
                    00F2    502 _B_2	=	0x00f2
                    00F3    503 Fio_repeater$B_3$0$0 == 0x00f3
                    00F3    504 _B_3	=	0x00f3
                    00F4    505 Fio_repeater$B_4$0$0 == 0x00f4
                    00F4    506 _B_4	=	0x00f4
                    00F5    507 Fio_repeater$B_5$0$0 == 0x00f5
                    00F5    508 _B_5	=	0x00f5
                    00F6    509 Fio_repeater$B_6$0$0 == 0x00f6
                    00F6    510 _B_6	=	0x00f6
                    00F7    511 Fio_repeater$B_7$0$0 == 0x00f7
                    00F7    512 _B_7	=	0x00f7
                    00F8    513 Fio_repeater$U1ACTIVE$0$0 == 0x00f8
                    00F8    514 _U1ACTIVE	=	0x00f8
                    00F9    515 Fio_repeater$U1TX_BYTE$0$0 == 0x00f9
                    00F9    516 _U1TX_BYTE	=	0x00f9
                    00FA    517 Fio_repeater$U1RX_BYTE$0$0 == 0x00fa
                    00FA    518 _U1RX_BYTE	=	0x00fa
                    00FB    519 Fio_repeater$U1ERR$0$0 == 0x00fb
                    00FB    520 _U1ERR	=	0x00fb
                    00FC    521 Fio_repeater$U1FE$0$0 == 0x00fc
                    00FC    522 _U1FE	=	0x00fc
                    00FD    523 Fio_repeater$U1SLAVE$0$0 == 0x00fd
                    00FD    524 _U1SLAVE	=	0x00fd
                    00FE    525 Fio_repeater$U1RE$0$0 == 0x00fe
                    00FE    526 _U1RE	=	0x00fe
                    00FF    527 Fio_repeater$U1MODE$0$0 == 0x00ff
                    00FF    528 _U1MODE	=	0x00ff
                            529 ;--------------------------------------------------------
                            530 ; overlayable register banks
                            531 ;--------------------------------------------------------
                            532 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     533 	.ds 8
                            534 ;--------------------------------------------------------
                            535 ; overlayable bit register bank
                            536 ;--------------------------------------------------------
                            537 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     538 bits:
   0023                     539 	.ds 1
                    8000    540 	b0 = bits[0]
                    8100    541 	b1 = bits[1]
                    8200    542 	b2 = bits[2]
                    8300    543 	b3 = bits[3]
                    8400    544 	b4 = bits[4]
                    8500    545 	b5 = bits[5]
                    8600    546 	b6 = bits[6]
                    8700    547 	b7 = bits[7]
                            548 ;--------------------------------------------------------
                            549 ; internal ram data
                            550 ;--------------------------------------------------------
                            551 	.area DSEG    (DATA)
                    0000    552 Lio_repeater.setPins$sloc0$1$0==.
   0008                     553 _setPins_sloc0_1_0:
   0008                     554 	.ds 1
                            555 ;--------------------------------------------------------
                            556 ; overlayable items in internal ram 
                            557 ;--------------------------------------------------------
                            558 	.area OSEG    (OVR,DATA)
                            559 ;--------------------------------------------------------
                            560 ; Stack segment in internal ram 
                            561 ;--------------------------------------------------------
                            562 	.area	SSEG	(DATA)
   0024                     563 __start__stack:
   0024                     564 	.ds	1
                            565 
                            566 ;--------------------------------------------------------
                            567 ; indirectly addressable internal ram data
                            568 ;--------------------------------------------------------
                            569 	.area ISEG    (DATA)
                            570 ;--------------------------------------------------------
                            571 ; absolute internal ram data
                            572 ;--------------------------------------------------------
                            573 	.area IABS    (ABS,DATA)
                            574 	.area IABS    (ABS,DATA)
                            575 ;--------------------------------------------------------
                            576 ; bit data
                            577 ;--------------------------------------------------------
                            578 	.area BSEG    (BIT)
                    0000    579 Fio_repeater$txEnabled$0$0==.
   0000                     580 _txEnabled:
   0000                     581 	.ds 1
                    0001    582 Fio_repeater$rxEnabled$0$0==.
   0001                     583 _rxEnabled:
   0001                     584 	.ds 1
                    0002    585 Lio_repeater.readPins$sloc0$1$0==.
   0002                     586 _readPins_sloc0_1_0:
   0002                     587 	.ds 1
                    0003    588 Lio_repeater.setPins$sloc1$1$0==.
   0003                     589 _setPins_sloc1_1_0:
   0003                     590 	.ds 1
                            591 ;--------------------------------------------------------
                            592 ; paged external ram data
                            593 ;--------------------------------------------------------
                            594 	.area PSEG    (PAG,XDATA)
                    0000    595 Fio_repeater$inPinCount$0$0==.
   F000                     596 _inPinCount:
   F000                     597 	.ds 1
                    0001    598 Fio_repeater$outPinCount$0$0==.
   F001                     599 _outPinCount:
   F001                     600 	.ds 1
                    0002    601 Lio_repeater.setPins$byteCount$1$1==.
   F002                     602 _setPins_PARM_2:
   F002                     603 	.ds 1
                            604 ;--------------------------------------------------------
                            605 ; external ram data
                            606 ;--------------------------------------------------------
                            607 	.area XSEG    (XDATA)
                    DF00    608 Fio_repeater$SYNC1$0$0 == 0xdf00
                    DF00    609 _SYNC1	=	0xdf00
                    DF01    610 Fio_repeater$SYNC0$0$0 == 0xdf01
                    DF01    611 _SYNC0	=	0xdf01
                    DF02    612 Fio_repeater$PKTLEN$0$0 == 0xdf02
                    DF02    613 _PKTLEN	=	0xdf02
                    DF03    614 Fio_repeater$PKTCTRL1$0$0 == 0xdf03
                    DF03    615 _PKTCTRL1	=	0xdf03
                    DF04    616 Fio_repeater$PKTCTRL0$0$0 == 0xdf04
                    DF04    617 _PKTCTRL0	=	0xdf04
                    DF05    618 Fio_repeater$ADDR$0$0 == 0xdf05
                    DF05    619 _ADDR	=	0xdf05
                    DF06    620 Fio_repeater$CHANNR$0$0 == 0xdf06
                    DF06    621 _CHANNR	=	0xdf06
                    DF07    622 Fio_repeater$FSCTRL1$0$0 == 0xdf07
                    DF07    623 _FSCTRL1	=	0xdf07
                    DF08    624 Fio_repeater$FSCTRL0$0$0 == 0xdf08
                    DF08    625 _FSCTRL0	=	0xdf08
                    DF09    626 Fio_repeater$FREQ2$0$0 == 0xdf09
                    DF09    627 _FREQ2	=	0xdf09
                    DF0A    628 Fio_repeater$FREQ1$0$0 == 0xdf0a
                    DF0A    629 _FREQ1	=	0xdf0a
                    DF0B    630 Fio_repeater$FREQ0$0$0 == 0xdf0b
                    DF0B    631 _FREQ0	=	0xdf0b
                    DF0C    632 Fio_repeater$MDMCFG4$0$0 == 0xdf0c
                    DF0C    633 _MDMCFG4	=	0xdf0c
                    DF0D    634 Fio_repeater$MDMCFG3$0$0 == 0xdf0d
                    DF0D    635 _MDMCFG3	=	0xdf0d
                    DF0E    636 Fio_repeater$MDMCFG2$0$0 == 0xdf0e
                    DF0E    637 _MDMCFG2	=	0xdf0e
                    DF0F    638 Fio_repeater$MDMCFG1$0$0 == 0xdf0f
                    DF0F    639 _MDMCFG1	=	0xdf0f
                    DF10    640 Fio_repeater$MDMCFG0$0$0 == 0xdf10
                    DF10    641 _MDMCFG0	=	0xdf10
                    DF11    642 Fio_repeater$DEVIATN$0$0 == 0xdf11
                    DF11    643 _DEVIATN	=	0xdf11
                    DF12    644 Fio_repeater$MCSM2$0$0 == 0xdf12
                    DF12    645 _MCSM2	=	0xdf12
                    DF13    646 Fio_repeater$MCSM1$0$0 == 0xdf13
                    DF13    647 _MCSM1	=	0xdf13
                    DF14    648 Fio_repeater$MCSM0$0$0 == 0xdf14
                    DF14    649 _MCSM0	=	0xdf14
                    DF15    650 Fio_repeater$FOCCFG$0$0 == 0xdf15
                    DF15    651 _FOCCFG	=	0xdf15
                    DF16    652 Fio_repeater$BSCFG$0$0 == 0xdf16
                    DF16    653 _BSCFG	=	0xdf16
                    DF17    654 Fio_repeater$AGCCTRL2$0$0 == 0xdf17
                    DF17    655 _AGCCTRL2	=	0xdf17
                    DF18    656 Fio_repeater$AGCCTRL1$0$0 == 0xdf18
                    DF18    657 _AGCCTRL1	=	0xdf18
                    DF19    658 Fio_repeater$AGCCTRL0$0$0 == 0xdf19
                    DF19    659 _AGCCTRL0	=	0xdf19
                    DF1A    660 Fio_repeater$FREND1$0$0 == 0xdf1a
                    DF1A    661 _FREND1	=	0xdf1a
                    DF1B    662 Fio_repeater$FREND0$0$0 == 0xdf1b
                    DF1B    663 _FREND0	=	0xdf1b
                    DF1C    664 Fio_repeater$FSCAL3$0$0 == 0xdf1c
                    DF1C    665 _FSCAL3	=	0xdf1c
                    DF1D    666 Fio_repeater$FSCAL2$0$0 == 0xdf1d
                    DF1D    667 _FSCAL2	=	0xdf1d
                    DF1E    668 Fio_repeater$FSCAL1$0$0 == 0xdf1e
                    DF1E    669 _FSCAL1	=	0xdf1e
                    DF1F    670 Fio_repeater$FSCAL0$0$0 == 0xdf1f
                    DF1F    671 _FSCAL0	=	0xdf1f
                    DF23    672 Fio_repeater$TEST2$0$0 == 0xdf23
                    DF23    673 _TEST2	=	0xdf23
                    DF24    674 Fio_repeater$TEST1$0$0 == 0xdf24
                    DF24    675 _TEST1	=	0xdf24
                    DF25    676 Fio_repeater$TEST0$0$0 == 0xdf25
                    DF25    677 _TEST0	=	0xdf25
                    DF2E    678 Fio_repeater$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    679 _PA_TABLE0	=	0xdf2e
                    DF2F    680 Fio_repeater$IOCFG2$0$0 == 0xdf2f
                    DF2F    681 _IOCFG2	=	0xdf2f
                    DF30    682 Fio_repeater$IOCFG1$0$0 == 0xdf30
                    DF30    683 _IOCFG1	=	0xdf30
                    DF31    684 Fio_repeater$IOCFG0$0$0 == 0xdf31
                    DF31    685 _IOCFG0	=	0xdf31
                    DF36    686 Fio_repeater$PARTNUM$0$0 == 0xdf36
                    DF36    687 _PARTNUM	=	0xdf36
                    DF37    688 Fio_repeater$VERSION$0$0 == 0xdf37
                    DF37    689 _VERSION	=	0xdf37
                    DF38    690 Fio_repeater$FREQEST$0$0 == 0xdf38
                    DF38    691 _FREQEST	=	0xdf38
                    DF39    692 Fio_repeater$LQI$0$0 == 0xdf39
                    DF39    693 _LQI	=	0xdf39
                    DF3A    694 Fio_repeater$RSSI$0$0 == 0xdf3a
                    DF3A    695 _RSSI	=	0xdf3a
                    DF3B    696 Fio_repeater$MARCSTATE$0$0 == 0xdf3b
                    DF3B    697 _MARCSTATE	=	0xdf3b
                    DF3C    698 Fio_repeater$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    699 _PKTSTATUS	=	0xdf3c
                    DF3D    700 Fio_repeater$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    701 _VCO_VC_DAC	=	0xdf3d
                    DF40    702 Fio_repeater$I2SCFG0$0$0 == 0xdf40
                    DF40    703 _I2SCFG0	=	0xdf40
                    DF41    704 Fio_repeater$I2SCFG1$0$0 == 0xdf41
                    DF41    705 _I2SCFG1	=	0xdf41
                    DF42    706 Fio_repeater$I2SDATL$0$0 == 0xdf42
                    DF42    707 _I2SDATL	=	0xdf42
                    DF43    708 Fio_repeater$I2SDATH$0$0 == 0xdf43
                    DF43    709 _I2SDATH	=	0xdf43
                    DF44    710 Fio_repeater$I2SWCNT$0$0 == 0xdf44
                    DF44    711 _I2SWCNT	=	0xdf44
                    DF45    712 Fio_repeater$I2SSTAT$0$0 == 0xdf45
                    DF45    713 _I2SSTAT	=	0xdf45
                    DF46    714 Fio_repeater$I2SCLKF0$0$0 == 0xdf46
                    DF46    715 _I2SCLKF0	=	0xdf46
                    DF47    716 Fio_repeater$I2SCLKF1$0$0 == 0xdf47
                    DF47    717 _I2SCLKF1	=	0xdf47
                    DF48    718 Fio_repeater$I2SCLKF2$0$0 == 0xdf48
                    DF48    719 _I2SCLKF2	=	0xdf48
                    DE00    720 Fio_repeater$USBADDR$0$0 == 0xde00
                    DE00    721 _USBADDR	=	0xde00
                    DE01    722 Fio_repeater$USBPOW$0$0 == 0xde01
                    DE01    723 _USBPOW	=	0xde01
                    DE02    724 Fio_repeater$USBIIF$0$0 == 0xde02
                    DE02    725 _USBIIF	=	0xde02
                    DE04    726 Fio_repeater$USBOIF$0$0 == 0xde04
                    DE04    727 _USBOIF	=	0xde04
                    DE06    728 Fio_repeater$USBCIF$0$0 == 0xde06
                    DE06    729 _USBCIF	=	0xde06
                    DE07    730 Fio_repeater$USBIIE$0$0 == 0xde07
                    DE07    731 _USBIIE	=	0xde07
                    DE09    732 Fio_repeater$USBOIE$0$0 == 0xde09
                    DE09    733 _USBOIE	=	0xde09
                    DE0B    734 Fio_repeater$USBCIE$0$0 == 0xde0b
                    DE0B    735 _USBCIE	=	0xde0b
                    DE0C    736 Fio_repeater$USBFRML$0$0 == 0xde0c
                    DE0C    737 _USBFRML	=	0xde0c
                    DE0D    738 Fio_repeater$USBFRMH$0$0 == 0xde0d
                    DE0D    739 _USBFRMH	=	0xde0d
                    DE0E    740 Fio_repeater$USBINDEX$0$0 == 0xde0e
                    DE0E    741 _USBINDEX	=	0xde0e
                    DE10    742 Fio_repeater$USBMAXI$0$0 == 0xde10
                    DE10    743 _USBMAXI	=	0xde10
                    DE11    744 Fio_repeater$USBCSIL$0$0 == 0xde11
                    DE11    745 _USBCSIL	=	0xde11
                    DE12    746 Fio_repeater$USBCSIH$0$0 == 0xde12
                    DE12    747 _USBCSIH	=	0xde12
                    DE13    748 Fio_repeater$USBMAXO$0$0 == 0xde13
                    DE13    749 _USBMAXO	=	0xde13
                    DE14    750 Fio_repeater$USBCSOL$0$0 == 0xde14
                    DE14    751 _USBCSOL	=	0xde14
                    DE15    752 Fio_repeater$USBCSOH$0$0 == 0xde15
                    DE15    753 _USBCSOH	=	0xde15
                    DE16    754 Fio_repeater$USBCNTL$0$0 == 0xde16
                    DE16    755 _USBCNTL	=	0xde16
                    DE17    756 Fio_repeater$USBCNTH$0$0 == 0xde17
                    DE17    757 _USBCNTH	=	0xde17
                    DE20    758 Fio_repeater$USBF0$0$0 == 0xde20
                    DE20    759 _USBF0	=	0xde20
                    DE22    760 Fio_repeater$USBF1$0$0 == 0xde22
                    DE22    761 _USBF1	=	0xde22
                    DE24    762 Fio_repeater$USBF2$0$0 == 0xde24
                    DE24    763 _USBF2	=	0xde24
                    DE26    764 Fio_repeater$USBF3$0$0 == 0xde26
                    DE26    765 _USBF3	=	0xde26
                    DE28    766 Fio_repeater$USBF4$0$0 == 0xde28
                    DE28    767 _USBF4	=	0xde28
                    DE2A    768 Fio_repeater$USBF5$0$0 == 0xde2a
                    DE2A    769 _USBF5	=	0xde2a
                    0000    770 Fio_repeater$inPins$0$0==.
   F021                     771 _inPins:
   F021                     772 	.ds 15
                    000F    773 Fio_repeater$outPins$0$0==.
   F030                     774 _outPins:
   F030                     775 	.ds 15
                            776 ;--------------------------------------------------------
                            777 ; absolute external ram data
                            778 ;--------------------------------------------------------
                            779 	.area XABS    (ABS,XDATA)
                            780 ;--------------------------------------------------------
                            781 ; external initialized ram data
                            782 ;--------------------------------------------------------
                            783 	.area XISEG   (XDATA)
                            784 	.area HOME    (CODE)
                            785 	.area GSINIT0 (CODE)
                            786 	.area GSINIT1 (CODE)
                            787 	.area GSINIT2 (CODE)
                            788 	.area GSINIT3 (CODE)
                            789 	.area GSINIT4 (CODE)
                            790 	.area GSINIT5 (CODE)
                            791 	.area GSINIT  (CODE)
                            792 	.area GSFINAL (CODE)
                            793 	.area CSEG    (CODE)
                            794 ;--------------------------------------------------------
                            795 ; interrupt vector 
                            796 ;--------------------------------------------------------
                            797 	.area HOME    (CODE)
   0400                     798 __interrupt_vect:
   0400 02 04 8D            799 	ljmp	__sdcc_gsinit_startup
   0403 32                  800 	reti
   0404                     801 	.ds	7
   040B 32                  802 	reti
   040C                     803 	.ds	7
   0413 32                  804 	reti
   0414                     805 	.ds	7
   041B 32                  806 	reti
   041C                     807 	.ds	7
   0423 32                  808 	reti
   0424                     809 	.ds	7
   042B 32                  810 	reti
   042C                     811 	.ds	7
   0433 32                  812 	reti
   0434                     813 	.ds	7
   043B 32                  814 	reti
   043C                     815 	.ds	7
   0443 32                  816 	reti
   0444                     817 	.ds	7
   044B 32                  818 	reti
   044C                     819 	.ds	7
   0453 32                  820 	reti
   0454                     821 	.ds	7
   045B 32                  822 	reti
   045C                     823 	.ds	7
   0463 02 15 06            824 	ljmp	_ISR_T4
   0466                     825 	.ds	5
   046B 32                  826 	reti
   046C                     827 	.ds	7
   0473 32                  828 	reti
   0474                     829 	.ds	7
   047B 32                  830 	reti
   047C                     831 	.ds	7
   0483 02 0D CA            832 	ljmp	_ISR_RF
                            833 ;--------------------------------------------------------
                            834 ; global & static initialisations
                            835 ;--------------------------------------------------------
                            836 	.area HOME    (CODE)
                            837 	.area GSINIT  (CODE)
                            838 	.area GSFINAL (CODE)
                            839 	.area GSINIT  (CODE)
                            840 	.globl __sdcc_gsinit_startup
                            841 	.globl __sdcc_program_startup
                            842 	.globl __start__stack
                            843 	.globl __mcs51_genXINIT
                            844 	.globl __mcs51_genXRAMCLEAR
                            845 	.globl __mcs51_genRAMCLEAR
                    0000    846 	G$main$0$0 ==.
                    0000    847 	C$io_repeater.c$38$1$1 ==.
                            848 ;	apps/io_repeater/io_repeater.c:38: static BIT txEnabled = 0;
   04E6 C2 00               849 	clr	_txEnabled
                    0002    850 	G$main$0$0 ==.
                    0002    851 	C$io_repeater.c$39$1$1 ==.
                            852 ;	apps/io_repeater/io_repeater.c:39: static BIT rxEnabled = 0;
   04E8 C2 01               853 	clr	_rxEnabled
                    0004    854 	G$main$0$0 ==.
                    0004    855 	C$io_repeater.c$31$1$1 ==.
                            856 ;	apps/io_repeater/io_repeater.c:31: static uint8 inPinCount = 0;
   04EA 78 00               857 	mov	r0,#_inPinCount
   04EC E4                  858 	clr	a
   04ED F2                  859 	movx	@r0,a
                    0008    860 	G$main$0$0 ==.
                    0008    861 	C$io_repeater.c$35$1$1 ==.
                            862 ;	apps/io_repeater/io_repeater.c:35: static uint8 outPinCount = 0;
   04EE 78 01               863 	mov	r0,#_outPinCount
   04F0 E4                  864 	clr	a
   04F1 F2                  865 	movx	@r0,a
                            866 	.area GSFINAL (CODE)
   0533 02 04 86            867 	ljmp	__sdcc_program_startup
                            868 ;--------------------------------------------------------
                            869 ; Home
                            870 ;--------------------------------------------------------
                            871 	.area HOME    (CODE)
                            872 	.area HOME    (CODE)
   0486                     873 __sdcc_program_startup:
   0486 12 08 B5            874 	lcall	_main
                            875 ;	return from main will lock up
   0489 80 FE               876 	sjmp .
                            877 ;--------------------------------------------------------
                            878 ; code
                            879 ;--------------------------------------------------------
                            880 	.area CSEG    (CODE)
                            881 ;------------------------------------------------------------
                            882 ;Allocation info for local variables in function 'updateLeds'
                            883 ;------------------------------------------------------------
                    0000    884 	G$updateLeds$0$0 ==.
                    0000    885 	C$io_repeater.c$66$0$0 ==.
                            886 ;	apps/io_repeater/io_repeater.c:66: void updateLeds()
                            887 ;	-----------------------------------------
                            888 ;	 function updateLeds
                            889 ;	-----------------------------------------
   0536                     890 _updateLeds:
                    0007    891 	ar7 = 0x07
                    0006    892 	ar6 = 0x06
                    0005    893 	ar5 = 0x05
                    0004    894 	ar4 = 0x04
                    0003    895 	ar3 = 0x03
                    0002    896 	ar2 = 0x02
                    0001    897 	ar1 = 0x01
                    0000    898 	ar0 = 0x00
                    0000    899 	C$io_repeater.c$68$1$1 ==.
                            900 ;	apps/io_repeater/io_repeater.c:68: usbShowStatusWithGreenLed();
   0536 12 1C C9            901 	lcall	_usbShowStatusWithGreenLed
                    0003    902 	C$io_repeater.c$70$2$2 ==.
                            903 ;	apps/io_repeater/io_repeater.c:70: LED_YELLOW(vinPowerPresent());
   0539 12 12 3D            904 	lcall	_vinPowerPresent
   053C 50 05               905 	jnc	00103$
   053E 43 FF 04            906 	orl	_P2DIR,#0x04
   0541 80 07               907 	sjmp	00101$
   0543                     908 00103$:
   0543 AF FF               909 	mov	r7,_P2DIR
   0545 53 07 FB            910 	anl	ar7,#0xFB
   0548 8F FF               911 	mov	_P2DIR,r7
   054A                     912 00101$:
                    0014    913 	C$io_repeater.c$71$2$2 ==.
                    0014    914 	XG$updateLeds$0$0 ==.
   054A 22                  915 	ret
                            916 ;------------------------------------------------------------
                            917 ;Allocation info for local variables in function 'pinLink'
                            918 ;------------------------------------------------------------
                    0015    919 	G$pinLink$0$0 ==.
                    0015    920 	C$io_repeater.c$73$2$2 ==.
                            921 ;	apps/io_repeater/io_repeater.c:73: int8 pinLink(uint8 pin)
                            922 ;	-----------------------------------------
                            923 ;	 function pinLink
                            924 ;	-----------------------------------------
   054B                     925 _pinLink:
                    0015    926 	C$io_repeater.c$75$1$1 ==.
                            927 ;	apps/io_repeater/io_repeater.c:75: switch(pin)
   054B E5 82               928 	mov	a,dpl
   054D FF                  929 	mov	r7,a
   054E 24 EA               930 	add	a,#0xff - 0x15
   0550 50 03               931 	jnc	00120$
   0552 02 06 E1            932 	ljmp	00116$
   0555                     933 00120$:
   0555 EF                  934 	mov	a,r7
   0556 24 09               935 	add	a,#(00121$-3-.)
   0558 83                  936 	movc	a,@a+pc
   0559 C0 E0               937 	push	acc
   055B EF                  938 	mov	a,r7
   055C 24 19               939 	add	a,#(00122$-3-.)
   055E 83                  940 	movc	a,@a+pc
   055F C0 E0               941 	push	acc
   0561 22                  942 	ret
   0562                     943 00121$:
   0562 8E                  944 	.db	00101$
   0563 A5                  945 	.db	00102$
   0564 BC                  946 	.db	00103$
   0565 D3                  947 	.db	00104$
   0566 EA                  948 	.db	00105$
   0567 01                  949 	.db	00106$
   0568 E1                  950 	.db	00116$
   0569 E1                  951 	.db	00116$
   056A E1                  952 	.db	00116$
   056B E1                  953 	.db	00116$
   056C 18                  954 	.db	00107$
   056D 2F                  955 	.db	00108$
   056E 46                  956 	.db	00109$
   056F 5D                  957 	.db	00110$
   0570 73                  958 	.db	00111$
   0571 89                  959 	.db	00112$
   0572 9F                  960 	.db	00113$
   0573 B5                  961 	.db	00114$
   0574 E1                  962 	.db	00116$
   0575 E1                  963 	.db	00116$
   0576 E1                  964 	.db	00116$
   0577 CB                  965 	.db	00115$
   0578                     966 00122$:
   0578 05                  967 	.db	00101$>>8
   0579 05                  968 	.db	00102$>>8
   057A 05                  969 	.db	00103$>>8
   057B 05                  970 	.db	00104$>>8
   057C 05                  971 	.db	00105$>>8
   057D 06                  972 	.db	00106$>>8
   057E 06                  973 	.db	00116$>>8
   057F 06                  974 	.db	00116$>>8
   0580 06                  975 	.db	00116$>>8
   0581 06                  976 	.db	00116$>>8
   0582 06                  977 	.db	00107$>>8
   0583 06                  978 	.db	00108$>>8
   0584 06                  979 	.db	00109$>>8
   0585 06                  980 	.db	00110$>>8
   0586 06                  981 	.db	00111$>>8
   0587 06                  982 	.db	00112$>>8
   0588 06                  983 	.db	00113$>>8
   0589 06                  984 	.db	00114$>>8
   058A 06                  985 	.db	00116$>>8
   058B 06                  986 	.db	00116$>>8
   058C 06                  987 	.db	00116$>>8
   058D 06                  988 	.db	00115$>>8
                    0058    989 	C$io_repeater.c$77$2$2 ==.
                            990 ;	apps/io_repeater/io_repeater.c:77: case 0:  return param_P0_0_link;
   058E                     991 00101$:
   058E 90 1D 95            992 	mov	dptr,#_param_P0_0_link
   0591 E4                  993 	clr	a
   0592 93                  994 	movc	a,@a+dptr
   0593 FC                  995 	mov	r4,a
   0594 74 01               996 	mov	a,#0x01
   0596 93                  997 	movc	a,@a+dptr
   0597 FD                  998 	mov	r5,a
   0598 74 02               999 	mov	a,#0x02
   059A 93                 1000 	movc	a,@a+dptr
   059B FE                 1001 	mov	r6,a
   059C 74 03              1002 	mov	a,#0x03
   059E 93                 1003 	movc	a,@a+dptr
   059F FF                 1004 	mov	r7,a
   05A0 8C 82              1005 	mov	dpl,r4
   05A2 02 06 E4           1006 	ljmp	00117$
                    006F   1007 	C$io_repeater.c$78$2$2 ==.
                           1008 ;	apps/io_repeater/io_repeater.c:78: case 1:  return param_P0_1_link;
   05A5                    1009 00102$:
   05A5 90 1D 99           1010 	mov	dptr,#_param_P0_1_link
   05A8 E4                 1011 	clr	a
   05A9 93                 1012 	movc	a,@a+dptr
   05AA FC                 1013 	mov	r4,a
   05AB 74 01              1014 	mov	a,#0x01
   05AD 93                 1015 	movc	a,@a+dptr
   05AE FD                 1016 	mov	r5,a
   05AF 74 02              1017 	mov	a,#0x02
   05B1 93                 1018 	movc	a,@a+dptr
   05B2 FE                 1019 	mov	r6,a
   05B3 74 03              1020 	mov	a,#0x03
   05B5 93                 1021 	movc	a,@a+dptr
   05B6 FF                 1022 	mov	r7,a
   05B7 8C 82              1023 	mov	dpl,r4
   05B9 02 06 E4           1024 	ljmp	00117$
                    0086   1025 	C$io_repeater.c$79$2$2 ==.
                           1026 ;	apps/io_repeater/io_repeater.c:79: case 2:  return param_P0_2_link;
   05BC                    1027 00103$:
   05BC 90 1D 9D           1028 	mov	dptr,#_param_P0_2_link
   05BF E4                 1029 	clr	a
   05C0 93                 1030 	movc	a,@a+dptr
   05C1 FC                 1031 	mov	r4,a
   05C2 74 01              1032 	mov	a,#0x01
   05C4 93                 1033 	movc	a,@a+dptr
   05C5 FD                 1034 	mov	r5,a
   05C6 74 02              1035 	mov	a,#0x02
   05C8 93                 1036 	movc	a,@a+dptr
   05C9 FE                 1037 	mov	r6,a
   05CA 74 03              1038 	mov	a,#0x03
   05CC 93                 1039 	movc	a,@a+dptr
   05CD FF                 1040 	mov	r7,a
   05CE 8C 82              1041 	mov	dpl,r4
   05D0 02 06 E4           1042 	ljmp	00117$
                    009D   1043 	C$io_repeater.c$80$2$2 ==.
                           1044 ;	apps/io_repeater/io_repeater.c:80: case 3:  return param_P0_3_link;
   05D3                    1045 00104$:
   05D3 90 1D A1           1046 	mov	dptr,#_param_P0_3_link
   05D6 E4                 1047 	clr	a
   05D7 93                 1048 	movc	a,@a+dptr
   05D8 FC                 1049 	mov	r4,a
   05D9 74 01              1050 	mov	a,#0x01
   05DB 93                 1051 	movc	a,@a+dptr
   05DC FD                 1052 	mov	r5,a
   05DD 74 02              1053 	mov	a,#0x02
   05DF 93                 1054 	movc	a,@a+dptr
   05E0 FE                 1055 	mov	r6,a
   05E1 74 03              1056 	mov	a,#0x03
   05E3 93                 1057 	movc	a,@a+dptr
   05E4 FF                 1058 	mov	r7,a
   05E5 8C 82              1059 	mov	dpl,r4
   05E7 02 06 E4           1060 	ljmp	00117$
                    00B4   1061 	C$io_repeater.c$81$2$2 ==.
                           1062 ;	apps/io_repeater/io_repeater.c:81: case 4:  return param_P0_4_link;
   05EA                    1063 00105$:
   05EA 90 1D A5           1064 	mov	dptr,#_param_P0_4_link
   05ED E4                 1065 	clr	a
   05EE 93                 1066 	movc	a,@a+dptr
   05EF FC                 1067 	mov	r4,a
   05F0 74 01              1068 	mov	a,#0x01
   05F2 93                 1069 	movc	a,@a+dptr
   05F3 FD                 1070 	mov	r5,a
   05F4 74 02              1071 	mov	a,#0x02
   05F6 93                 1072 	movc	a,@a+dptr
   05F7 FE                 1073 	mov	r6,a
   05F8 74 03              1074 	mov	a,#0x03
   05FA 93                 1075 	movc	a,@a+dptr
   05FB FF                 1076 	mov	r7,a
   05FC 8C 82              1077 	mov	dpl,r4
   05FE 02 06 E4           1078 	ljmp	00117$
                    00CB   1079 	C$io_repeater.c$82$2$2 ==.
                           1080 ;	apps/io_repeater/io_repeater.c:82: case 5:  return param_P0_5_link;
   0601                    1081 00106$:
   0601 90 1D A9           1082 	mov	dptr,#_param_P0_5_link
   0604 E4                 1083 	clr	a
   0605 93                 1084 	movc	a,@a+dptr
   0606 FC                 1085 	mov	r4,a
   0607 74 01              1086 	mov	a,#0x01
   0609 93                 1087 	movc	a,@a+dptr
   060A FD                 1088 	mov	r5,a
   060B 74 02              1089 	mov	a,#0x02
   060D 93                 1090 	movc	a,@a+dptr
   060E FE                 1091 	mov	r6,a
   060F 74 03              1092 	mov	a,#0x03
   0611 93                 1093 	movc	a,@a+dptr
   0612 FF                 1094 	mov	r7,a
   0613 8C 82              1095 	mov	dpl,r4
   0615 02 06 E4           1096 	ljmp	00117$
                    00E2   1097 	C$io_repeater.c$83$2$2 ==.
                           1098 ;	apps/io_repeater/io_repeater.c:83: case 10: return param_P1_0_link;
   0618                    1099 00107$:
   0618 90 1D AD           1100 	mov	dptr,#_param_P1_0_link
   061B E4                 1101 	clr	a
   061C 93                 1102 	movc	a,@a+dptr
   061D FC                 1103 	mov	r4,a
   061E 74 01              1104 	mov	a,#0x01
   0620 93                 1105 	movc	a,@a+dptr
   0621 FD                 1106 	mov	r5,a
   0622 74 02              1107 	mov	a,#0x02
   0624 93                 1108 	movc	a,@a+dptr
   0625 FE                 1109 	mov	r6,a
   0626 74 03              1110 	mov	a,#0x03
   0628 93                 1111 	movc	a,@a+dptr
   0629 FF                 1112 	mov	r7,a
   062A 8C 82              1113 	mov	dpl,r4
   062C 02 06 E4           1114 	ljmp	00117$
                    00F9   1115 	C$io_repeater.c$84$2$2 ==.
                           1116 ;	apps/io_repeater/io_repeater.c:84: case 11: return param_P1_1_link;
   062F                    1117 00108$:
   062F 90 1D B1           1118 	mov	dptr,#_param_P1_1_link
   0632 E4                 1119 	clr	a
   0633 93                 1120 	movc	a,@a+dptr
   0634 FC                 1121 	mov	r4,a
   0635 74 01              1122 	mov	a,#0x01
   0637 93                 1123 	movc	a,@a+dptr
   0638 FD                 1124 	mov	r5,a
   0639 74 02              1125 	mov	a,#0x02
   063B 93                 1126 	movc	a,@a+dptr
   063C FE                 1127 	mov	r6,a
   063D 74 03              1128 	mov	a,#0x03
   063F 93                 1129 	movc	a,@a+dptr
   0640 FF                 1130 	mov	r7,a
   0641 8C 82              1131 	mov	dpl,r4
   0643 02 06 E4           1132 	ljmp	00117$
                    0110   1133 	C$io_repeater.c$85$2$2 ==.
                           1134 ;	apps/io_repeater/io_repeater.c:85: case 12: return param_P1_2_link;
   0646                    1135 00109$:
   0646 90 1D B5           1136 	mov	dptr,#_param_P1_2_link
   0649 E4                 1137 	clr	a
   064A 93                 1138 	movc	a,@a+dptr
   064B FC                 1139 	mov	r4,a
   064C 74 01              1140 	mov	a,#0x01
   064E 93                 1141 	movc	a,@a+dptr
   064F FD                 1142 	mov	r5,a
   0650 74 02              1143 	mov	a,#0x02
   0652 93                 1144 	movc	a,@a+dptr
   0653 FE                 1145 	mov	r6,a
   0654 74 03              1146 	mov	a,#0x03
   0656 93                 1147 	movc	a,@a+dptr
   0657 FF                 1148 	mov	r7,a
   0658 8C 82              1149 	mov	dpl,r4
   065A 02 06 E4           1150 	ljmp	00117$
                    0127   1151 	C$io_repeater.c$86$2$2 ==.
                           1152 ;	apps/io_repeater/io_repeater.c:86: case 13: return param_P1_3_link;
   065D                    1153 00110$:
   065D 90 1D B9           1154 	mov	dptr,#_param_P1_3_link
   0660 E4                 1155 	clr	a
   0661 93                 1156 	movc	a,@a+dptr
   0662 FC                 1157 	mov	r4,a
   0663 74 01              1158 	mov	a,#0x01
   0665 93                 1159 	movc	a,@a+dptr
   0666 FD                 1160 	mov	r5,a
   0667 74 02              1161 	mov	a,#0x02
   0669 93                 1162 	movc	a,@a+dptr
   066A FE                 1163 	mov	r6,a
   066B 74 03              1164 	mov	a,#0x03
   066D 93                 1165 	movc	a,@a+dptr
   066E FF                 1166 	mov	r7,a
   066F 8C 82              1167 	mov	dpl,r4
                    013B   1168 	C$io_repeater.c$87$2$2 ==.
                           1169 ;	apps/io_repeater/io_repeater.c:87: case 14: return param_P1_4_link;
   0671 80 71              1170 	sjmp	00117$
   0673                    1171 00111$:
   0673 90 1D BD           1172 	mov	dptr,#_param_P1_4_link
   0676 E4                 1173 	clr	a
   0677 93                 1174 	movc	a,@a+dptr
   0678 FC                 1175 	mov	r4,a
   0679 74 01              1176 	mov	a,#0x01
   067B 93                 1177 	movc	a,@a+dptr
   067C FD                 1178 	mov	r5,a
   067D 74 02              1179 	mov	a,#0x02
   067F 93                 1180 	movc	a,@a+dptr
   0680 FE                 1181 	mov	r6,a
   0681 74 03              1182 	mov	a,#0x03
   0683 93                 1183 	movc	a,@a+dptr
   0684 FF                 1184 	mov	r7,a
   0685 8C 82              1185 	mov	dpl,r4
                    0151   1186 	C$io_repeater.c$88$2$2 ==.
                           1187 ;	apps/io_repeater/io_repeater.c:88: case 15: return param_P1_5_link;
   0687 80 5B              1188 	sjmp	00117$
   0689                    1189 00112$:
   0689 90 1D C1           1190 	mov	dptr,#_param_P1_5_link
   068C E4                 1191 	clr	a
   068D 93                 1192 	movc	a,@a+dptr
   068E FC                 1193 	mov	r4,a
   068F 74 01              1194 	mov	a,#0x01
   0691 93                 1195 	movc	a,@a+dptr
   0692 FD                 1196 	mov	r5,a
   0693 74 02              1197 	mov	a,#0x02
   0695 93                 1198 	movc	a,@a+dptr
   0696 FE                 1199 	mov	r6,a
   0697 74 03              1200 	mov	a,#0x03
   0699 93                 1201 	movc	a,@a+dptr
   069A FF                 1202 	mov	r7,a
   069B 8C 82              1203 	mov	dpl,r4
                    0167   1204 	C$io_repeater.c$89$2$2 ==.
                           1205 ;	apps/io_repeater/io_repeater.c:89: case 16: return param_P1_6_link;
   069D 80 45              1206 	sjmp	00117$
   069F                    1207 00113$:
   069F 90 1D C5           1208 	mov	dptr,#_param_P1_6_link
   06A2 E4                 1209 	clr	a
   06A3 93                 1210 	movc	a,@a+dptr
   06A4 FC                 1211 	mov	r4,a
   06A5 74 01              1212 	mov	a,#0x01
   06A7 93                 1213 	movc	a,@a+dptr
   06A8 FD                 1214 	mov	r5,a
   06A9 74 02              1215 	mov	a,#0x02
   06AB 93                 1216 	movc	a,@a+dptr
   06AC FE                 1217 	mov	r6,a
   06AD 74 03              1218 	mov	a,#0x03
   06AF 93                 1219 	movc	a,@a+dptr
   06B0 FF                 1220 	mov	r7,a
   06B1 8C 82              1221 	mov	dpl,r4
                    017D   1222 	C$io_repeater.c$90$2$2 ==.
                           1223 ;	apps/io_repeater/io_repeater.c:90: case 17: return param_P1_7_link;
   06B3 80 2F              1224 	sjmp	00117$
   06B5                    1225 00114$:
   06B5 90 1D C9           1226 	mov	dptr,#_param_P1_7_link
   06B8 E4                 1227 	clr	a
   06B9 93                 1228 	movc	a,@a+dptr
   06BA FC                 1229 	mov	r4,a
   06BB 74 01              1230 	mov	a,#0x01
   06BD 93                 1231 	movc	a,@a+dptr
   06BE FD                 1232 	mov	r5,a
   06BF 74 02              1233 	mov	a,#0x02
   06C1 93                 1234 	movc	a,@a+dptr
   06C2 FE                 1235 	mov	r6,a
   06C3 74 03              1236 	mov	a,#0x03
   06C5 93                 1237 	movc	a,@a+dptr
   06C6 FF                 1238 	mov	r7,a
   06C7 8C 82              1239 	mov	dpl,r4
                    0193   1240 	C$io_repeater.c$91$2$2 ==.
                           1241 ;	apps/io_repeater/io_repeater.c:91: case 21: return param_P2_1_link;
   06C9 80 19              1242 	sjmp	00117$
   06CB                    1243 00115$:
   06CB 90 1D CD           1244 	mov	dptr,#_param_P2_1_link
   06CE E4                 1245 	clr	a
   06CF 93                 1246 	movc	a,@a+dptr
   06D0 FC                 1247 	mov	r4,a
   06D1 74 01              1248 	mov	a,#0x01
   06D3 93                 1249 	movc	a,@a+dptr
   06D4 FD                 1250 	mov	r5,a
   06D5 74 02              1251 	mov	a,#0x02
   06D7 93                 1252 	movc	a,@a+dptr
   06D8 FE                 1253 	mov	r6,a
   06D9 74 03              1254 	mov	a,#0x03
   06DB 93                 1255 	movc	a,@a+dptr
   06DC FF                 1256 	mov	r7,a
   06DD 8C 82              1257 	mov	dpl,r4
                    01A9   1258 	C$io_repeater.c$92$1$1 ==.
                           1259 ;	apps/io_repeater/io_repeater.c:92: }
   06DF 80 03              1260 	sjmp	00117$
   06E1                    1261 00116$:
                    01AB   1262 	C$io_repeater.c$93$1$1 ==.
                           1263 ;	apps/io_repeater/io_repeater.c:93: return 0;
   06E1 75 82 00           1264 	mov	dpl,#0x00
   06E4                    1265 00117$:
                    01AE   1266 	C$io_repeater.c$94$1$1 ==.
                    01AE   1267 	XG$pinLink$0$0 ==.
   06E4 22                 1268 	ret
                           1269 ;------------------------------------------------------------
                           1270 ;Allocation info for local variables in function 'configurePins'
                           1271 ;------------------------------------------------------------
                    01AF   1272 	G$configurePins$0$0 ==.
                    01AF   1273 	C$io_repeater.c$96$1$1 ==.
                           1274 ;	apps/io_repeater/io_repeater.c:96: void configurePins(void)
                           1275 ;	-----------------------------------------
                           1276 ;	 function configurePins
                           1277 ;	-----------------------------------------
   06E5                    1278 _configurePins:
                    01AF   1279 	C$io_repeater.c$102$1$1 ==.
                           1280 ;	apps/io_repeater/io_repeater.c:102: setPort0PullType(HIGH);
   06E5 D2 F0              1281 	setb	b[0]
   06E7 85 F0 23           1282 	mov	bits,b
   06EA 12 0D 3D           1283 	lcall	_setPort0PullType
                    01B7   1284 	C$io_repeater.c$103$1$1 ==.
                           1285 ;	apps/io_repeater/io_repeater.c:103: setPort1PullType(HIGH);
   06ED D2 F0              1286 	setb	b[0]
   06EF 85 F0 23           1287 	mov	bits,b
   06F2 12 0D 4D           1288 	lcall	_setPort1PullType
                    01BF   1289 	C$io_repeater.c$106$3$4 ==.
                           1290 ;	apps/io_repeater/io_repeater.c:106: for(pin = 0; pin < PIN_COUNT; pin++)
   06F5 7F 00              1291 	mov	r7,#0x00
   06F7                    1292 00106$:
   06F7 BF 0F 00           1293 	cjne	r7,#0x0F,00117$
   06FA                    1294 00117$:
   06FA 50 78              1295 	jnc	00110$
                    01C6   1296 	C$io_repeater.c$108$2$2 ==.
                           1297 ;	apps/io_repeater/io_repeater.c:108: tmp = pins[pin];
   06FC EF                 1298 	mov	a,r7
   06FD 90 1D 86           1299 	mov	dptr,#_pins
   0700 93                 1300 	movc	a,@a+dptr
                    01CB   1301 	C$io_repeater.c$110$2$2 ==.
                           1302 ;	apps/io_repeater/io_repeater.c:110: if (IS_OUTPUT(tmp))
   0701 FE                 1303 	mov	r6,a
   0702 F5 82              1304 	mov	dpl,a
   0704 C0 07              1305 	push	ar7
   0706 C0 06              1306 	push	ar6
   0708 12 05 4B           1307 	lcall	_pinLink
   070B AD 82              1308 	mov	r5,dpl
   070D D0 06              1309 	pop	ar6
   070F D0 07              1310 	pop	ar7
   0711 C3                 1311 	clr	c
   0712 E4                 1312 	clr	a
   0713 64 80              1313 	xrl	a,#0x80
   0715 8D F0              1314 	mov	b,r5
   0717 63 F0 80           1315 	xrl	b,#0x80
   071A 95 F0              1316 	subb	a,b
   071C 50 2A              1317 	jnc	00104$
                    01E8   1318 	C$io_repeater.c$114$3$3 ==.
                           1319 ;	apps/io_repeater/io_repeater.c:114: setDigitalOutput(tmp, LOW);
   071E C2 F0              1320 	clr	b[0]
   0720 C0 07              1321 	push	ar7
   0722 C0 06              1322 	push	ar6
   0724 85 F0 23           1323 	mov	bits,b
   0727 8E 82              1324 	mov	dpl,r6
   0729 12 09 8F           1325 	lcall	_setDigitalOutput
   072C D0 06              1326 	pop	ar6
   072E D0 07              1327 	pop	ar7
                    01FA   1328 	C$io_repeater.c$115$3$3 ==.
                           1329 ;	apps/io_repeater/io_repeater.c:115: outPins[outPinCount++] = tmp;
   0730 78 01              1330 	mov	r0,#_outPinCount
   0732 E2                 1331 	movx	a,@r0
   0733 FD                 1332 	mov	r5,a
   0734 78 01              1333 	mov	r0,#_outPinCount
   0736 04                 1334 	inc	a
   0737 F2                 1335 	movx	@r0,a
   0738 ED                 1336 	mov	a,r5
   0739 24 30              1337 	add	a,#_outPins
   073B F5 82              1338 	mov	dpl,a
   073D E4                 1339 	clr	a
   073E 34 F0              1340 	addc	a,#(_outPins >> 8)
   0740 F5 83              1341 	mov	dph,a
   0742 EE                 1342 	mov	a,r6
   0743 F0                 1343 	movx	@dptr,a
                    020E   1344 	C$io_repeater.c$116$3$3 ==.
                           1345 ;	apps/io_repeater/io_repeater.c:116: rxEnabled = 1;
   0744 D2 01              1346 	setb	_rxEnabled
   0746 80 29              1347 	sjmp	00108$
   0748                    1348 00104$:
                    0212   1349 	C$io_repeater.c$118$2$2 ==.
                           1350 ;	apps/io_repeater/io_repeater.c:118: else if (IS_INPUT(tmp))
   0748 8E 82              1351 	mov	dpl,r6
   074A C0 07              1352 	push	ar7
   074C C0 06              1353 	push	ar6
   074E 12 05 4B           1354 	lcall	_pinLink
   0751 AD 82              1355 	mov	r5,dpl
   0753 D0 06              1356 	pop	ar6
   0755 D0 07              1357 	pop	ar7
   0757 ED                 1358 	mov	a,r5
   0758 30 E7 16           1359 	jnb	acc.7,00108$
                    0225   1360 	C$io_repeater.c$122$3$4 ==.
                           1361 ;	apps/io_repeater/io_repeater.c:122: inPins[inPinCount++] = tmp;
   075B 78 00              1362 	mov	r0,#_inPinCount
   075D E2                 1363 	movx	a,@r0
   075E FD                 1364 	mov	r5,a
   075F 78 00              1365 	mov	r0,#_inPinCount
   0761 04                 1366 	inc	a
   0762 F2                 1367 	movx	@r0,a
   0763 ED                 1368 	mov	a,r5
   0764 24 21              1369 	add	a,#_inPins
   0766 F5 82              1370 	mov	dpl,a
   0768 E4                 1371 	clr	a
   0769 34 F0              1372 	addc	a,#(_inPins >> 8)
   076B F5 83              1373 	mov	dph,a
   076D EE                 1374 	mov	a,r6
   076E F0                 1375 	movx	@dptr,a
                    0239   1376 	C$io_repeater.c$123$3$4 ==.
                           1377 ;	apps/io_repeater/io_repeater.c:123: txEnabled = 1;
   076F D2 00              1378 	setb	_txEnabled
   0771                    1379 00108$:
                    023B   1380 	C$io_repeater.c$106$1$1 ==.
                           1381 ;	apps/io_repeater/io_repeater.c:106: for(pin = 0; pin < PIN_COUNT; pin++)
   0771 0F                 1382 	inc	r7
   0772 80 83              1383 	sjmp	00106$
   0774                    1384 00110$:
                    023E   1385 	C$io_repeater.c$126$1$1 ==.
                    023E   1386 	XG$configurePins$0$0 ==.
   0774 22                 1387 	ret
                           1388 ;------------------------------------------------------------
                           1389 ;Allocation info for local variables in function 'readPins'
                           1390 ;------------------------------------------------------------
                    023F   1391 	G$readPins$0$0 ==.
                    023F   1392 	C$io_repeater.c$129$1$1 ==.
                           1393 ;	apps/io_repeater/io_repeater.c:129: void readPins(uint8 XDATA * buf)
                           1394 ;	-----------------------------------------
                           1395 ;	 function readPins
                           1396 ;	-----------------------------------------
   0775                    1397 _readPins:
   0775 AE 82              1398 	mov	r6,dpl
   0777 AF 83              1399 	mov	r7,dph
                    0243   1400 	C$io_repeater.c$133$1$1 ==.
                           1401 ;	apps/io_repeater/io_repeater.c:133: for (pin = 0; pin < inPinCount; pin++)
   0779 7D 00              1402 	mov	r5,#0x00
   077B                    1403 00101$:
   077B 78 00              1404 	mov	r0,#_inPinCount
   077D C3                 1405 	clr	c
   077E E2                 1406 	movx	a,@r0
   077F F5 F0              1407 	mov	b,a
   0781 ED                 1408 	mov	a,r5
   0782 95 F0              1409 	subb	a,b
   0784 50 74              1410 	jnc	00105$
                    0250   1411 	C$io_repeater.c$136$2$2 ==.
                           1412 ;	apps/io_repeater/io_repeater.c:136: buf[pin] = (-pinLink(inPins[pin]) << PIN_LINK_OFFSET) | (isPinHigh(inPins[pin]) << PIN_VAL_OFFSET);
   0786 ED                 1413 	mov	a,r5
   0787 2E                 1414 	add	a,r6
   0788 FB                 1415 	mov	r3,a
   0789 E4                 1416 	clr	a
   078A 3F                 1417 	addc	a,r7
   078B FC                 1418 	mov	r4,a
   078C ED                 1419 	mov	a,r5
   078D 24 21              1420 	add	a,#_inPins
   078F F5 82              1421 	mov	dpl,a
   0791 E4                 1422 	clr	a
   0792 34 F0              1423 	addc	a,#(_inPins >> 8)
   0794 F5 83              1424 	mov	dph,a
   0796 E0                 1425 	movx	a,@dptr
   0797 F5 82              1426 	mov	dpl,a
   0799 C0 07              1427 	push	ar7
   079B C0 06              1428 	push	ar6
   079D C0 05              1429 	push	ar5
   079F C0 04              1430 	push	ar4
   07A1 C0 03              1431 	push	ar3
   07A3 12 05 4B           1432 	lcall	_pinLink
   07A6 AA 82              1433 	mov	r2,dpl
   07A8 D0 03              1434 	pop	ar3
   07AA D0 04              1435 	pop	ar4
   07AC D0 05              1436 	pop	ar5
   07AE D0 06              1437 	pop	ar6
   07B0 D0 07              1438 	pop	ar7
   07B2 C3                 1439 	clr	c
   07B3 E4                 1440 	clr	a
   07B4 9A                 1441 	subb	a,r2
   07B5 FA                 1442 	mov	r2,a
   07B6 ED                 1443 	mov	a,r5
   07B7 24 21              1444 	add	a,#_inPins
   07B9 F5 82              1445 	mov	dpl,a
   07BB E4                 1446 	clr	a
   07BC 34 F0              1447 	addc	a,#(_inPins >> 8)
   07BE F5 83              1448 	mov	dph,a
   07C0 C0 06              1449 	push	ar6
   07C2 C0 07              1450 	push	ar7
   07C4 E0                 1451 	movx	a,@dptr
   07C5 FF                 1452 	mov	r7,a
   07C6 F5 82              1453 	mov	dpl,a
   07C8 C0 07              1454 	push	ar7
   07CA C0 06              1455 	push	ar6
   07CC C0 05              1456 	push	ar5
   07CE C0 04              1457 	push	ar4
   07D0 C0 03              1458 	push	ar3
   07D2 C0 02              1459 	push	ar2
   07D4 12 0C A6           1460 	lcall	_isPinHigh
   07D7 D0 02              1461 	pop	ar2
   07D9 D0 03              1462 	pop	ar3
   07DB D0 04              1463 	pop	ar4
   07DD D0 05              1464 	pop	ar5
   07DF D0 06              1465 	pop	ar6
   07E1 D0 07              1466 	pop	ar7
   07E3 92 02              1467 	mov  _readPins_sloc0_1_0,c
   07E5 E4                 1468 	clr	a
   07E6 33                 1469 	rlc	a
   07E7 03                 1470 	rr	a
   07E8 54 80              1471 	anl	a,#0x80
   07EA 42 02              1472 	orl	ar2,a
   07EC 8B 82              1473 	mov	dpl,r3
   07EE 8C 83              1474 	mov	dph,r4
   07F0 EA                 1475 	mov	a,r2
   07F1 F0                 1476 	movx	@dptr,a
                    02BC   1477 	C$io_repeater.c$133$1$1 ==.
                           1478 ;	apps/io_repeater/io_repeater.c:133: for (pin = 0; pin < inPinCount; pin++)
   07F2 0D                 1479 	inc	r5
   07F3 D0 07              1480 	pop	ar7
   07F5 D0 06              1481 	pop	ar6
   07F7 02 07 7B           1482 	ljmp	00101$
   07FA                    1483 00105$:
                    02C4   1484 	C$io_repeater.c$138$1$1 ==.
                    02C4   1485 	XG$readPins$0$0 ==.
   07FA 22                 1486 	ret
                           1487 ;------------------------------------------------------------
                           1488 ;Allocation info for local variables in function 'setPins'
                           1489 ;------------------------------------------------------------
                           1490 ;sloc0                     Allocated with name '_setPins_sloc0_1_0'
                           1491 ;------------------------------------------------------------
                    02C5   1492 	G$setPins$0$0 ==.
                    02C5   1493 	C$io_repeater.c$141$1$1 ==.
                           1494 ;	apps/io_repeater/io_repeater.c:141: void setPins(uint8 XDATA * buf, uint8 byteCount)
                           1495 ;	-----------------------------------------
                           1496 ;	 function setPins
                           1497 ;	-----------------------------------------
   07FB                    1498 _setPins:
   07FB AE 82              1499 	mov	r6,dpl
   07FD AF 83              1500 	mov	r7,dph
                    02C9   1501 	C$io_repeater.c$146$1$1 ==.
                           1502 ;	apps/io_repeater/io_repeater.c:146: for (byte = 0; byte < byteCount; byte++)
   07FF 7D 00              1503 	mov	r5,#0x00
   0801                    1504 00107$:
   0801 78 02              1505 	mov	r0,#_setPins_PARM_2
   0803 C3                 1506 	clr	c
   0804 E2                 1507 	movx	a,@r0
   0805 F5 F0              1508 	mov	b,a
   0807 ED                 1509 	mov	a,r5
   0808 95 F0              1510 	subb	a,b
   080A 40 03              1511 	jc	00120$
   080C 02 08 B4           1512 	ljmp	00111$
   080F                    1513 00120$:
                    02D9   1514 	C$io_repeater.c$148$3$3 ==.
                           1515 ;	apps/io_repeater/io_repeater.c:148: for (pin = 0; pin < outPinCount; pin++)
   080F ED                 1516 	mov	a,r5
   0810 2E                 1517 	add	a,r6
   0811 FB                 1518 	mov	r3,a
   0812 E4                 1519 	clr	a
   0813 3F                 1520 	addc	a,r7
   0814 FC                 1521 	mov	r4,a
   0815 7A 00              1522 	mov	r2,#0x00
   0817                    1523 00103$:
   0817 78 01              1524 	mov	r0,#_outPinCount
   0819 C3                 1525 	clr	c
   081A E2                 1526 	movx	a,@r0
   081B F5 F0              1527 	mov	b,a
   081D EA                 1528 	mov	a,r2
   081E 95 F0              1529 	subb	a,b
   0820 40 03              1530 	jc	00121$
   0822 02 08 B0           1531 	ljmp	00109$
   0825                    1532 00121$:
                    02EF   1533 	C$io_repeater.c$151$1$1 ==.
                           1534 ;	apps/io_repeater/io_repeater.c:151: if ((uint8)pinLink(outPins[pin]) == ((buf[byte] >> PIN_LINK_OFFSET) & PIN_LINK_MASK))
   0825 C0 06              1535 	push	ar6
   0827 C0 07              1536 	push	ar7
   0829 EA                 1537 	mov	a,r2
   082A 24 30              1538 	add	a,#_outPins
   082C F5 82              1539 	mov	dpl,a
   082E E4                 1540 	clr	a
   082F 34 F0              1541 	addc	a,#(_outPins >> 8)
   0831 F5 83              1542 	mov	dph,a
   0833 E0                 1543 	movx	a,@dptr
   0834 F5 82              1544 	mov	dpl,a
   0836 C0 06              1545 	push	ar6
   0838 C0 05              1546 	push	ar5
   083A C0 04              1547 	push	ar4
   083C C0 03              1548 	push	ar3
   083E C0 02              1549 	push	ar2
   0840 12 05 4B           1550 	lcall	_pinLink
   0843 AF 82              1551 	mov	r7,dpl
   0845 D0 02              1552 	pop	ar2
   0847 D0 03              1553 	pop	ar3
   0849 D0 04              1554 	pop	ar4
   084B D0 05              1555 	pop	ar5
   084D D0 06              1556 	pop	ar6
   084F 8B 82              1557 	mov	dpl,r3
   0851 8C 83              1558 	mov	dph,r4
   0853 E0                 1559 	movx	a,@dptr
   0854 F5 08              1560 	mov	_setPins_sloc0_1_0,a
   0856 AE 08              1561 	mov	r6,_setPins_sloc0_1_0
   0858 53 06 7F           1562 	anl	ar6,#0x7F
   085B EF                 1563 	mov	a,r7
   085C B5 06 02           1564 	cjne	a,ar6,00122$
   085F 80 06              1565 	sjmp	00123$
   0861                    1566 00122$:
   0861 D0 07              1567 	pop	ar7
   0863 D0 06              1568 	pop	ar6
   0865 80 45              1569 	sjmp	00105$
   0867                    1570 00123$:
   0867 D0 07              1571 	pop	ar7
   0869 D0 06              1572 	pop	ar6
                    0335   1573 	C$io_repeater.c$154$1$1 ==.
                           1574 ;	apps/io_repeater/io_repeater.c:154: setDigitalOutput(outPins[pin], (buf[byte] >> PIN_VAL_OFFSET) & 1);
   086B C0 06              1575 	push	ar6
   086D C0 07              1576 	push	ar7
   086F E5 08              1577 	mov	a,_setPins_sloc0_1_0
   0871 23                 1578 	rl	a
   0872 54 01              1579 	anl	a,#0x01
   0874 24 FF              1580 	add	a,#0xff
   0876 92 03              1581 	mov	_setPins_sloc1_1_0,c
   0878 EA                 1582 	mov	a,r2
   0879 24 30              1583 	add	a,#_outPins
   087B F5 82              1584 	mov	dpl,a
   087D E4                 1585 	clr	a
   087E 34 F0              1586 	addc	a,#(_outPins >> 8)
   0880 F5 83              1587 	mov	dph,a
   0882 E0                 1588 	movx	a,@dptr
   0883 FF                 1589 	mov	r7,a
   0884 A2 03              1590 	mov	c,_setPins_sloc1_1_0
   0886 92 F0              1591 	mov	b[0],c
   0888 C0 07              1592 	push	ar7
   088A C0 06              1593 	push	ar6
   088C C0 05              1594 	push	ar5
   088E C0 04              1595 	push	ar4
   0890 C0 03              1596 	push	ar3
   0892 C0 02              1597 	push	ar2
   0894 85 F0 23           1598 	mov	bits,b
   0897 8F 82              1599 	mov	dpl,r7
   0899 12 09 8F           1600 	lcall	_setDigitalOutput
   089C D0 02              1601 	pop	ar2
   089E D0 03              1602 	pop	ar3
   08A0 D0 04              1603 	pop	ar4
   08A2 D0 05              1604 	pop	ar5
   08A4 D0 06              1605 	pop	ar6
   08A6 D0 07              1606 	pop	ar7
                    0372   1607 	C$io_repeater.c$146$1$1 ==.
                           1608 ;	apps/io_repeater/io_repeater.c:146: for (byte = 0; byte < byteCount; byte++)
   08A8 D0 07              1609 	pop	ar7
   08AA D0 06              1610 	pop	ar6
                    0376   1611 	C$io_repeater.c$154$2$3 ==.
                           1612 ;	apps/io_repeater/io_repeater.c:154: setDigitalOutput(outPins[pin], (buf[byte] >> PIN_VAL_OFFSET) & 1);
   08AC                    1613 00105$:
                    0376   1614 	C$io_repeater.c$148$2$2 ==.
                           1615 ;	apps/io_repeater/io_repeater.c:148: for (pin = 0; pin < outPinCount; pin++)
   08AC 0A                 1616 	inc	r2
   08AD 02 08 17           1617 	ljmp	00103$
   08B0                    1618 00109$:
                    037A   1619 	C$io_repeater.c$146$1$1 ==.
                           1620 ;	apps/io_repeater/io_repeater.c:146: for (byte = 0; byte < byteCount; byte++)
   08B0 0D                 1621 	inc	r5
   08B1 02 08 01           1622 	ljmp	00107$
   08B4                    1623 00111$:
                    037E   1624 	C$io_repeater.c$158$1$1 ==.
                    037E   1625 	XG$setPins$0$0 ==.
   08B4 22                 1626 	ret
                           1627 ;------------------------------------------------------------
                           1628 ;Allocation info for local variables in function 'main'
                           1629 ;------------------------------------------------------------
                    037F   1630 	G$main$0$0 ==.
                    037F   1631 	C$io_repeater.c$160$1$1 ==.
                           1632 ;	apps/io_repeater/io_repeater.c:160: void main(void)
                           1633 ;	-----------------------------------------
                           1634 ;	 function main
                           1635 ;	-----------------------------------------
   08B5                    1636 _main:
                    037F   1637 	C$io_repeater.c$166$1$1 ==.
                           1638 ;	apps/io_repeater/io_repeater.c:166: uint8 lastTx = 0;
   08B5 7F 00              1639 	mov	r7,#0x00
                    0381   1640 	C$io_repeater.c$167$1$1 ==.
                           1641 ;	apps/io_repeater/io_repeater.c:167: uint8 txInterval = 0;
   08B7 7E 00              1642 	mov	r6,#0x00
                    0383   1643 	C$io_repeater.c$169$1$1 ==.
                           1644 ;	apps/io_repeater/io_repeater.c:169: systemInit();
   08B9 C0 07              1645 	push	ar7
   08BB C0 06              1646 	push	ar6
   08BD 12 11 73           1647 	lcall	_systemInit
                    038A   1648 	C$io_repeater.c$170$1$1 ==.
                           1649 ;	apps/io_repeater/io_repeater.c:170: usbInit();
   08C0 12 15 92           1650 	lcall	_usbInit
                    038D   1651 	C$io_repeater.c$172$1$1 ==.
                           1652 ;	apps/io_repeater/io_repeater.c:172: radioQueueInit();
   08C3 12 0F B2           1653 	lcall	_radioQueueInit
                    0390   1654 	C$io_repeater.c$174$1$1 ==.
                           1655 ;	apps/io_repeater/io_repeater.c:174: configurePins();
   08C6 12 06 E5           1656 	lcall	_configurePins
   08C9 D0 06              1657 	pop	ar6
   08CB D0 07              1658 	pop	ar7
                    0397   1659 	C$io_repeater.c$176$1$1 ==.
                           1660 ;	apps/io_repeater/io_repeater.c:176: while(1)
   08CD                    1661 00109$:
                    0397   1662 	C$io_repeater.c$178$2$2 ==.
                           1663 ;	apps/io_repeater/io_repeater.c:178: updateLeds();
   08CD C0 07              1664 	push	ar7
   08CF C0 06              1665 	push	ar6
   08D1 12 05 36           1666 	lcall	_updateLeds
                    039E   1667 	C$io_repeater.c$179$2$2 ==.
                           1668 ;	apps/io_repeater/io_repeater.c:179: boardService();
   08D4 12 11 80           1669 	lcall	_boardService
                    03A1   1670 	C$io_repeater.c$180$2$2 ==.
                           1671 ;	apps/io_repeater/io_repeater.c:180: usbComService();
   08D7 12 13 A4           1672 	lcall	_usbComService
   08DA D0 06              1673 	pop	ar6
   08DC D0 07              1674 	pop	ar7
                    03A8   1675 	C$io_repeater.c$183$2$2 ==.
                           1676 ;	apps/io_repeater/io_repeater.c:183: if (rxEnabled && (rxBuf = radioQueueRxCurrentPacket()))
   08DE 30 01 38           1677 	jnb	_rxEnabled,00102$
   08E1 C0 07              1678 	push	ar7
   08E3 C0 06              1679 	push	ar6
   08E5 12 10 24           1680 	lcall	_radioQueueRxCurrentPacket
   08E8 AC 82              1681 	mov	r4,dpl
   08EA AD 83              1682 	mov	r5,dph
   08EC D0 06              1683 	pop	ar6
   08EE D0 07              1684 	pop	ar7
   08F0 8C 02              1685 	mov	ar2,r4
   08F2 8D 03              1686 	mov	ar3,r5
   08F4 EC                 1687 	mov	a,r4
   08F5 4D                 1688 	orl	a,r5
   08F6 60 21              1689 	jz	00102$
                    03C2   1690 	C$io_repeater.c$185$3$3 ==.
                           1691 ;	apps/io_repeater/io_repeater.c:185: setPins(rxBuf + 1, *rxBuf);
   08F8 74 01              1692 	mov	a,#0x01
   08FA 2A                 1693 	add	a,r2
   08FB FC                 1694 	mov	r4,a
   08FC E4                 1695 	clr	a
   08FD 3B                 1696 	addc	a,r3
   08FE FD                 1697 	mov	r5,a
   08FF 8A 82              1698 	mov	dpl,r2
   0901 8B 83              1699 	mov	dph,r3
   0903 E0                 1700 	movx	a,@dptr
   0904 78 02              1701 	mov	r0,#_setPins_PARM_2
   0906 F2                 1702 	movx	@r0,a
   0907 8C 82              1703 	mov	dpl,r4
   0909 8D 83              1704 	mov	dph,r5
   090B C0 07              1705 	push	ar7
   090D C0 06              1706 	push	ar6
   090F 12 07 FB           1707 	lcall	_setPins
                    03DC   1708 	C$io_repeater.c$186$3$3 ==.
                           1709 ;	apps/io_repeater/io_repeater.c:186: radioQueueRxDoneWithPacket();
   0912 12 10 3F           1710 	lcall	_radioQueueRxDoneWithPacket
   0915 D0 06              1711 	pop	ar6
   0917 D0 07              1712 	pop	ar7
   0919                    1713 00102$:
                    03E3   1714 	C$io_repeater.c$190$2$2 ==.
                           1715 ;	apps/io_repeater/io_repeater.c:190: if (txEnabled && (uint8)(getMs() - lastTx) > txInterval && (txBuf = radioQueueTxCurrentPacket()))
   0919 30 00 B1           1716 	jnb	_txEnabled,00109$
   091C C0 07              1717 	push	ar7
   091E C0 06              1718 	push	ar6
   0920 12 15 2B           1719 	lcall	_getMs
   0923 AA 82              1720 	mov	r2,dpl
   0925 AB 83              1721 	mov	r3,dph
   0927 AC F0              1722 	mov	r4,b
   0929 FD                 1723 	mov	r5,a
   092A D0 06              1724 	pop	ar6
   092C D0 07              1725 	pop	ar7
   092E EA                 1726 	mov	a,r2
   092F C3                 1727 	clr	c
   0930 9F                 1728 	subb	a,r7
   0931 FA                 1729 	mov	r2,a
   0932 C3                 1730 	clr	c
   0933 EE                 1731 	mov	a,r6
   0934 9A                 1732 	subb	a,r2
   0935 50 96              1733 	jnc	00109$
   0937 C0 07              1734 	push	ar7
   0939 C0 06              1735 	push	ar6
   093B 12 0F F6           1736 	lcall	_radioQueueTxCurrentPacket
   093E AC 82              1737 	mov	r4,dpl
   0940 AD 83              1738 	mov	r5,dph
   0942 D0 06              1739 	pop	ar6
   0944 D0 07              1740 	pop	ar7
   0946 8C 02              1741 	mov	ar2,r4
   0948 8D 03              1742 	mov	ar3,r5
   094A EC                 1743 	mov	a,r4
   094B 4D                 1744 	orl	a,r5
   094C 70 03              1745 	jnz	00123$
   094E 02 08 CD           1746 	ljmp	00109$
   0951                    1747 00123$:
                    041B   1748 	C$io_repeater.c$192$3$4 ==.
                           1749 ;	apps/io_repeater/io_repeater.c:192: readPins(txBuf + 1);
   0951 8A 82              1750 	mov	dpl,r2
   0953 8B 83              1751 	mov	dph,r3
   0955 A3                 1752 	inc	dptr
   0956 C0 03              1753 	push	ar3
   0958 C0 02              1754 	push	ar2
   095A 12 07 75           1755 	lcall	_readPins
   095D D0 02              1756 	pop	ar2
   095F D0 03              1757 	pop	ar3
                    042B   1758 	C$io_repeater.c$193$3$4 ==.
                           1759 ;	apps/io_repeater/io_repeater.c:193: *txBuf = inPinCount; // set packet length byte
   0961 8A 82              1760 	mov	dpl,r2
   0963 8B 83              1761 	mov	dph,r3
   0965 78 00              1762 	mov	r0,#_inPinCount
   0967 E2                 1763 	movx	a,@r0
   0968 F0                 1764 	movx	@dptr,a
                    0433   1765 	C$io_repeater.c$194$3$4 ==.
                           1766 ;	apps/io_repeater/io_repeater.c:194: radioQueueTxSendPacket();
   0969 12 10 14           1767 	lcall	_radioQueueTxSendPacket
                    0436   1768 	C$io_repeater.c$196$3$4 ==.
                           1769 ;	apps/io_repeater/io_repeater.c:196: lastTx = getMs();
   096C 12 15 2B           1770 	lcall	_getMs
   096F AA 82              1771 	mov	r2,dpl
   0971 8A 07              1772 	mov	ar7,r2
                    043D   1773 	C$io_repeater.c$201$3$4 ==.
                           1774 ;	apps/io_repeater/io_repeater.c:201: txInterval = 7 + (adcRead(14 | ADC_BITS_7) & 3);
   0973 75 82 3E           1775 	mov	dpl,#0x3E
   0976 C0 07              1776 	push	ar7
   0978 12 0D 6D           1777 	lcall	_adcRead
   097B E5 82              1778 	mov	a,dpl
   097D 85 83 F0           1779 	mov	b,dph
   0980 D0 07              1780 	pop	ar7
   0982 54 03              1781 	anl	a,#0x03
   0984 FC                 1782 	mov	r4,a
   0985 7D 00              1783 	mov	r5,#0x00
   0987 74 07              1784 	mov	a,#0x07
   0989 2C                 1785 	add	a,r4
   098A FE                 1786 	mov	r6,a
   098B 02 08 CD           1787 	ljmp	00109$
                    0458   1788 	C$io_repeater.c$204$1$1 ==.
                    0458   1789 	XG$main$0$0 ==.
   098E 22                 1790 	ret
                           1791 	.area CSEG    (CODE)
                           1792 	.area CONST   (CODE)
                    0000   1793 Fio_repeater$pins$0$0 == .
   1D86                    1794 _pins:
   1D86 00                 1795 	.db #0x00	; 0
   1D87 01                 1796 	.db #0x01	; 1
   1D88 02                 1797 	.db #0x02	; 2
   1D89 03                 1798 	.db #0x03	; 3
   1D8A 04                 1799 	.db #0x04	; 4
   1D8B 05                 1800 	.db #0x05	; 5
   1D8C 0A                 1801 	.db #0x0A	; 10
   1D8D 0B                 1802 	.db #0x0B	; 11
   1D8E 0C                 1803 	.db #0x0C	; 12
   1D8F 0D                 1804 	.db #0x0D	; 13
   1D90 0E                 1805 	.db #0x0E	; 14
   1D91 0F                 1806 	.db #0x0F	; 15
   1D92 10                 1807 	.db #0x10	; 16
   1D93 11                 1808 	.db #0x11	; 17
   1D94 15                 1809 	.db #0x15	; 21
                    000F   1810 G$param_P0_0_link$0$0 == .
   1D95                    1811 _param_P0_0_link:
   1D95 FF FF FF FF        1812 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0013   1813 G$param_P0_1_link$0$0 == .
   1D99                    1814 _param_P0_1_link:
   1D99 00 00 00 00        1815 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0017   1816 G$param_P0_2_link$0$0 == .
   1D9D                    1817 _param_P0_2_link:
   1D9D 00 00 00 00        1818 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    001B   1819 G$param_P0_3_link$0$0 == .
   1DA1                    1820 _param_P0_3_link:
   1DA1 00 00 00 00        1821 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    001F   1822 G$param_P0_4_link$0$0 == .
   1DA5                    1823 _param_P0_4_link:
   1DA5 00 00 00 00        1824 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0023   1825 G$param_P0_5_link$0$0 == .
   1DA9                    1826 _param_P0_5_link:
   1DA9 00 00 00 00        1827 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0027   1828 G$param_P1_0_link$0$0 == .
   1DAD                    1829 _param_P1_0_link:
   1DAD 00 00 00 00        1830 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002B   1831 G$param_P1_1_link$0$0 == .
   1DB1                    1832 _param_P1_1_link:
   1DB1 00 00 00 00        1833 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002F   1834 G$param_P1_2_link$0$0 == .
   1DB5                    1835 _param_P1_2_link:
   1DB5 00 00 00 00        1836 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0033   1837 G$param_P1_3_link$0$0 == .
   1DB9                    1838 _param_P1_3_link:
   1DB9 00 00 00 00        1839 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0037   1840 G$param_P1_4_link$0$0 == .
   1DBD                    1841 _param_P1_4_link:
   1DBD 00 00 00 00        1842 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    003B   1843 G$param_P1_5_link$0$0 == .
   1DC1                    1844 _param_P1_5_link:
   1DC1 00 00 00 00        1845 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    003F   1846 G$param_P1_6_link$0$0 == .
   1DC5                    1847 _param_P1_6_link:
   1DC5 00 00 00 00        1848 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0043   1849 G$param_P1_7_link$0$0 == .
   1DC9                    1850 _param_P1_7_link:
   1DC9 00 00 00 00        1851 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0047   1852 G$param_P2_1_link$0$0 == .
   1DCD                    1853 _param_P2_1_link:
   1DCD 01 00 00 00        1854 	.byte #0x01,#0x00,#0x00,#0x00	;  1
                           1855 	.area XINIT   (CODE)
                           1856 	.area CABS    (ABS,CODE)
