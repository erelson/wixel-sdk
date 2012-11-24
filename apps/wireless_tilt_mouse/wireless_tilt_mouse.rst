                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 23:16:04 2012
                              5 ;--------------------------------------------------------
                              6 	.module wireless_tilt_mouse
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_speed
                             13 	.globl _param_invert_y
                             14 	.globl _param_invert_x
                             15 	.globl _main
                             16 	.globl _txMouseState
                             17 	.globl _updateLeds
                             18 	.globl _sqrtf
                             19 	.globl _radioQueueTxSendPacket
                             20 	.globl _radioQueueTxCurrentPacket
                             21 	.globl _radioQueueInit
                             22 	.globl _usbComService
                             23 	.globl _usbShowStatusWithGreenLed
                             24 	.globl _usbInit
                             25 	.globl _isPinHigh
                             26 	.globl _setDigitalInput
                             27 	.globl _adcRead
                             28 	.globl _getMs
                             29 	.globl _vinPowerPresent
                             30 	.globl _boardService
                             31 	.globl _systemInit
                             32 ;--------------------------------------------------------
                             33 ; special function registers
                             34 ;--------------------------------------------------------
                             35 	.area RSEG    (ABS,DATA)
   0000                      36 	.org 0x0000
                    0080     37 Fwireless_tilt_mouse$P0$0$0 == 0x0080
                    0080     38 _P0	=	0x0080
                    0081     39 Fwireless_tilt_mouse$SP$0$0 == 0x0081
                    0081     40 _SP	=	0x0081
                    0082     41 Fwireless_tilt_mouse$DPL0$0$0 == 0x0082
                    0082     42 _DPL0	=	0x0082
                    0083     43 Fwireless_tilt_mouse$DPH0$0$0 == 0x0083
                    0083     44 _DPH0	=	0x0083
                    0084     45 Fwireless_tilt_mouse$DPL1$0$0 == 0x0084
                    0084     46 _DPL1	=	0x0084
                    0085     47 Fwireless_tilt_mouse$DPH1$0$0 == 0x0085
                    0085     48 _DPH1	=	0x0085
                    0086     49 Fwireless_tilt_mouse$U0CSR$0$0 == 0x0086
                    0086     50 _U0CSR	=	0x0086
                    0087     51 Fwireless_tilt_mouse$PCON$0$0 == 0x0087
                    0087     52 _PCON	=	0x0087
                    0088     53 Fwireless_tilt_mouse$TCON$0$0 == 0x0088
                    0088     54 _TCON	=	0x0088
                    0089     55 Fwireless_tilt_mouse$P0IFG$0$0 == 0x0089
                    0089     56 _P0IFG	=	0x0089
                    008A     57 Fwireless_tilt_mouse$P1IFG$0$0 == 0x008a
                    008A     58 _P1IFG	=	0x008a
                    008B     59 Fwireless_tilt_mouse$P2IFG$0$0 == 0x008b
                    008B     60 _P2IFG	=	0x008b
                    008C     61 Fwireless_tilt_mouse$PICTL$0$0 == 0x008c
                    008C     62 _PICTL	=	0x008c
                    008D     63 Fwireless_tilt_mouse$P1IEN$0$0 == 0x008d
                    008D     64 _P1IEN	=	0x008d
                    008F     65 Fwireless_tilt_mouse$P0INP$0$0 == 0x008f
                    008F     66 _P0INP	=	0x008f
                    0090     67 Fwireless_tilt_mouse$P1$0$0 == 0x0090
                    0090     68 _P1	=	0x0090
                    0091     69 Fwireless_tilt_mouse$RFIM$0$0 == 0x0091
                    0091     70 _RFIM	=	0x0091
                    0092     71 Fwireless_tilt_mouse$DPS$0$0 == 0x0092
                    0092     72 _DPS	=	0x0092
                    0093     73 Fwireless_tilt_mouse$MPAGE$0$0 == 0x0093
                    0093     74 _MPAGE	=	0x0093
                    0095     75 Fwireless_tilt_mouse$ENDIAN$0$0 == 0x0095
                    0095     76 _ENDIAN	=	0x0095
                    0098     77 Fwireless_tilt_mouse$S0CON$0$0 == 0x0098
                    0098     78 _S0CON	=	0x0098
                    009A     79 Fwireless_tilt_mouse$IEN2$0$0 == 0x009a
                    009A     80 _IEN2	=	0x009a
                    009B     81 Fwireless_tilt_mouse$S1CON$0$0 == 0x009b
                    009B     82 _S1CON	=	0x009b
                    009C     83 Fwireless_tilt_mouse$T2CT$0$0 == 0x009c
                    009C     84 _T2CT	=	0x009c
                    009D     85 Fwireless_tilt_mouse$T2PR$0$0 == 0x009d
                    009D     86 _T2PR	=	0x009d
                    009E     87 Fwireless_tilt_mouse$T2CTL$0$0 == 0x009e
                    009E     88 _T2CTL	=	0x009e
                    00A0     89 Fwireless_tilt_mouse$P2$0$0 == 0x00a0
                    00A0     90 _P2	=	0x00a0
                    00A1     91 Fwireless_tilt_mouse$WORIRQ$0$0 == 0x00a1
                    00A1     92 _WORIRQ	=	0x00a1
                    00A2     93 Fwireless_tilt_mouse$WORCTRL$0$0 == 0x00a2
                    00A2     94 _WORCTRL	=	0x00a2
                    00A3     95 Fwireless_tilt_mouse$WOREVT0$0$0 == 0x00a3
                    00A3     96 _WOREVT0	=	0x00a3
                    00A4     97 Fwireless_tilt_mouse$WOREVT1$0$0 == 0x00a4
                    00A4     98 _WOREVT1	=	0x00a4
                    00A5     99 Fwireless_tilt_mouse$WORTIME0$0$0 == 0x00a5
                    00A5    100 _WORTIME0	=	0x00a5
                    00A6    101 Fwireless_tilt_mouse$WORTIME1$0$0 == 0x00a6
                    00A6    102 _WORTIME1	=	0x00a6
                    00A8    103 Fwireless_tilt_mouse$IEN0$0$0 == 0x00a8
                    00A8    104 _IEN0	=	0x00a8
                    00A9    105 Fwireless_tilt_mouse$IP0$0$0 == 0x00a9
                    00A9    106 _IP0	=	0x00a9
                    00AB    107 Fwireless_tilt_mouse$FWT$0$0 == 0x00ab
                    00AB    108 _FWT	=	0x00ab
                    00AC    109 Fwireless_tilt_mouse$FADDRL$0$0 == 0x00ac
                    00AC    110 _FADDRL	=	0x00ac
                    00AD    111 Fwireless_tilt_mouse$FADDRH$0$0 == 0x00ad
                    00AD    112 _FADDRH	=	0x00ad
                    00AE    113 Fwireless_tilt_mouse$FCTL$0$0 == 0x00ae
                    00AE    114 _FCTL	=	0x00ae
                    00AF    115 Fwireless_tilt_mouse$FWDATA$0$0 == 0x00af
                    00AF    116 _FWDATA	=	0x00af
                    00B1    117 Fwireless_tilt_mouse$ENCDI$0$0 == 0x00b1
                    00B1    118 _ENCDI	=	0x00b1
                    00B2    119 Fwireless_tilt_mouse$ENCDO$0$0 == 0x00b2
                    00B2    120 _ENCDO	=	0x00b2
                    00B3    121 Fwireless_tilt_mouse$ENCCS$0$0 == 0x00b3
                    00B3    122 _ENCCS	=	0x00b3
                    00B4    123 Fwireless_tilt_mouse$ADCCON1$0$0 == 0x00b4
                    00B4    124 _ADCCON1	=	0x00b4
                    00B5    125 Fwireless_tilt_mouse$ADCCON2$0$0 == 0x00b5
                    00B5    126 _ADCCON2	=	0x00b5
                    00B6    127 Fwireless_tilt_mouse$ADCCON3$0$0 == 0x00b6
                    00B6    128 _ADCCON3	=	0x00b6
                    00B8    129 Fwireless_tilt_mouse$IEN1$0$0 == 0x00b8
                    00B8    130 _IEN1	=	0x00b8
                    00B9    131 Fwireless_tilt_mouse$IP1$0$0 == 0x00b9
                    00B9    132 _IP1	=	0x00b9
                    00BA    133 Fwireless_tilt_mouse$ADCL$0$0 == 0x00ba
                    00BA    134 _ADCL	=	0x00ba
                    00BB    135 Fwireless_tilt_mouse$ADCH$0$0 == 0x00bb
                    00BB    136 _ADCH	=	0x00bb
                    00BC    137 Fwireless_tilt_mouse$RNDL$0$0 == 0x00bc
                    00BC    138 _RNDL	=	0x00bc
                    00BD    139 Fwireless_tilt_mouse$RNDH$0$0 == 0x00bd
                    00BD    140 _RNDH	=	0x00bd
                    00BE    141 Fwireless_tilt_mouse$SLEEP$0$0 == 0x00be
                    00BE    142 _SLEEP	=	0x00be
                    00C0    143 Fwireless_tilt_mouse$IRCON$0$0 == 0x00c0
                    00C0    144 _IRCON	=	0x00c0
                    00C1    145 Fwireless_tilt_mouse$U0DBUF$0$0 == 0x00c1
                    00C1    146 _U0DBUF	=	0x00c1
                    00C2    147 Fwireless_tilt_mouse$U0BAUD$0$0 == 0x00c2
                    00C2    148 _U0BAUD	=	0x00c2
                    00C4    149 Fwireless_tilt_mouse$U0UCR$0$0 == 0x00c4
                    00C4    150 _U0UCR	=	0x00c4
                    00C5    151 Fwireless_tilt_mouse$U0GCR$0$0 == 0x00c5
                    00C5    152 _U0GCR	=	0x00c5
                    00C6    153 Fwireless_tilt_mouse$CLKCON$0$0 == 0x00c6
                    00C6    154 _CLKCON	=	0x00c6
                    00C7    155 Fwireless_tilt_mouse$MEMCTR$0$0 == 0x00c7
                    00C7    156 _MEMCTR	=	0x00c7
                    00C9    157 Fwireless_tilt_mouse$WDCTL$0$0 == 0x00c9
                    00C9    158 _WDCTL	=	0x00c9
                    00CA    159 Fwireless_tilt_mouse$T3CNT$0$0 == 0x00ca
                    00CA    160 _T3CNT	=	0x00ca
                    00CB    161 Fwireless_tilt_mouse$T3CTL$0$0 == 0x00cb
                    00CB    162 _T3CTL	=	0x00cb
                    00CC    163 Fwireless_tilt_mouse$T3CCTL0$0$0 == 0x00cc
                    00CC    164 _T3CCTL0	=	0x00cc
                    00CD    165 Fwireless_tilt_mouse$T3CC0$0$0 == 0x00cd
                    00CD    166 _T3CC0	=	0x00cd
                    00CE    167 Fwireless_tilt_mouse$T3CCTL1$0$0 == 0x00ce
                    00CE    168 _T3CCTL1	=	0x00ce
                    00CF    169 Fwireless_tilt_mouse$T3CC1$0$0 == 0x00cf
                    00CF    170 _T3CC1	=	0x00cf
                    00D0    171 Fwireless_tilt_mouse$PSW$0$0 == 0x00d0
                    00D0    172 _PSW	=	0x00d0
                    00D1    173 Fwireless_tilt_mouse$DMAIRQ$0$0 == 0x00d1
                    00D1    174 _DMAIRQ	=	0x00d1
                    00D2    175 Fwireless_tilt_mouse$DMA1CFGL$0$0 == 0x00d2
                    00D2    176 _DMA1CFGL	=	0x00d2
                    00D3    177 Fwireless_tilt_mouse$DMA1CFGH$0$0 == 0x00d3
                    00D3    178 _DMA1CFGH	=	0x00d3
                    00D4    179 Fwireless_tilt_mouse$DMA0CFGL$0$0 == 0x00d4
                    00D4    180 _DMA0CFGL	=	0x00d4
                    00D5    181 Fwireless_tilt_mouse$DMA0CFGH$0$0 == 0x00d5
                    00D5    182 _DMA0CFGH	=	0x00d5
                    00D6    183 Fwireless_tilt_mouse$DMAARM$0$0 == 0x00d6
                    00D6    184 _DMAARM	=	0x00d6
                    00D7    185 Fwireless_tilt_mouse$DMAREQ$0$0 == 0x00d7
                    00D7    186 _DMAREQ	=	0x00d7
                    00D8    187 Fwireless_tilt_mouse$TIMIF$0$0 == 0x00d8
                    00D8    188 _TIMIF	=	0x00d8
                    00D9    189 Fwireless_tilt_mouse$RFD$0$0 == 0x00d9
                    00D9    190 _RFD	=	0x00d9
                    00DA    191 Fwireless_tilt_mouse$T1CC0L$0$0 == 0x00da
                    00DA    192 _T1CC0L	=	0x00da
                    00DB    193 Fwireless_tilt_mouse$T1CC0H$0$0 == 0x00db
                    00DB    194 _T1CC0H	=	0x00db
                    00DC    195 Fwireless_tilt_mouse$T1CC1L$0$0 == 0x00dc
                    00DC    196 _T1CC1L	=	0x00dc
                    00DD    197 Fwireless_tilt_mouse$T1CC1H$0$0 == 0x00dd
                    00DD    198 _T1CC1H	=	0x00dd
                    00DE    199 Fwireless_tilt_mouse$T1CC2L$0$0 == 0x00de
                    00DE    200 _T1CC2L	=	0x00de
                    00DF    201 Fwireless_tilt_mouse$T1CC2H$0$0 == 0x00df
                    00DF    202 _T1CC2H	=	0x00df
                    00E0    203 Fwireless_tilt_mouse$ACC$0$0 == 0x00e0
                    00E0    204 _ACC	=	0x00e0
                    00E1    205 Fwireless_tilt_mouse$RFST$0$0 == 0x00e1
                    00E1    206 _RFST	=	0x00e1
                    00E2    207 Fwireless_tilt_mouse$T1CNTL$0$0 == 0x00e2
                    00E2    208 _T1CNTL	=	0x00e2
                    00E3    209 Fwireless_tilt_mouse$T1CNTH$0$0 == 0x00e3
                    00E3    210 _T1CNTH	=	0x00e3
                    00E4    211 Fwireless_tilt_mouse$T1CTL$0$0 == 0x00e4
                    00E4    212 _T1CTL	=	0x00e4
                    00E5    213 Fwireless_tilt_mouse$T1CCTL0$0$0 == 0x00e5
                    00E5    214 _T1CCTL0	=	0x00e5
                    00E6    215 Fwireless_tilt_mouse$T1CCTL1$0$0 == 0x00e6
                    00E6    216 _T1CCTL1	=	0x00e6
                    00E7    217 Fwireless_tilt_mouse$T1CCTL2$0$0 == 0x00e7
                    00E7    218 _T1CCTL2	=	0x00e7
                    00E8    219 Fwireless_tilt_mouse$IRCON2$0$0 == 0x00e8
                    00E8    220 _IRCON2	=	0x00e8
                    00E9    221 Fwireless_tilt_mouse$RFIF$0$0 == 0x00e9
                    00E9    222 _RFIF	=	0x00e9
                    00EA    223 Fwireless_tilt_mouse$T4CNT$0$0 == 0x00ea
                    00EA    224 _T4CNT	=	0x00ea
                    00EB    225 Fwireless_tilt_mouse$T4CTL$0$0 == 0x00eb
                    00EB    226 _T4CTL	=	0x00eb
                    00EC    227 Fwireless_tilt_mouse$T4CCTL0$0$0 == 0x00ec
                    00EC    228 _T4CCTL0	=	0x00ec
                    00ED    229 Fwireless_tilt_mouse$T4CC0$0$0 == 0x00ed
                    00ED    230 _T4CC0	=	0x00ed
                    00EE    231 Fwireless_tilt_mouse$T4CCTL1$0$0 == 0x00ee
                    00EE    232 _T4CCTL1	=	0x00ee
                    00EF    233 Fwireless_tilt_mouse$T4CC1$0$0 == 0x00ef
                    00EF    234 _T4CC1	=	0x00ef
                    00F0    235 Fwireless_tilt_mouse$B$0$0 == 0x00f0
                    00F0    236 _B	=	0x00f0
                    00F1    237 Fwireless_tilt_mouse$PERCFG$0$0 == 0x00f1
                    00F1    238 _PERCFG	=	0x00f1
                    00F2    239 Fwireless_tilt_mouse$ADCCFG$0$0 == 0x00f2
                    00F2    240 _ADCCFG	=	0x00f2
                    00F3    241 Fwireless_tilt_mouse$P0SEL$0$0 == 0x00f3
                    00F3    242 _P0SEL	=	0x00f3
                    00F4    243 Fwireless_tilt_mouse$P1SEL$0$0 == 0x00f4
                    00F4    244 _P1SEL	=	0x00f4
                    00F5    245 Fwireless_tilt_mouse$P2SEL$0$0 == 0x00f5
                    00F5    246 _P2SEL	=	0x00f5
                    00F6    247 Fwireless_tilt_mouse$P1INP$0$0 == 0x00f6
                    00F6    248 _P1INP	=	0x00f6
                    00F7    249 Fwireless_tilt_mouse$P2INP$0$0 == 0x00f7
                    00F7    250 _P2INP	=	0x00f7
                    00F8    251 Fwireless_tilt_mouse$U1CSR$0$0 == 0x00f8
                    00F8    252 _U1CSR	=	0x00f8
                    00F9    253 Fwireless_tilt_mouse$U1DBUF$0$0 == 0x00f9
                    00F9    254 _U1DBUF	=	0x00f9
                    00FA    255 Fwireless_tilt_mouse$U1BAUD$0$0 == 0x00fa
                    00FA    256 _U1BAUD	=	0x00fa
                    00FB    257 Fwireless_tilt_mouse$U1UCR$0$0 == 0x00fb
                    00FB    258 _U1UCR	=	0x00fb
                    00FC    259 Fwireless_tilt_mouse$U1GCR$0$0 == 0x00fc
                    00FC    260 _U1GCR	=	0x00fc
                    00FD    261 Fwireless_tilt_mouse$P0DIR$0$0 == 0x00fd
                    00FD    262 _P0DIR	=	0x00fd
                    00FE    263 Fwireless_tilt_mouse$P1DIR$0$0 == 0x00fe
                    00FE    264 _P1DIR	=	0x00fe
                    00FF    265 Fwireless_tilt_mouse$P2DIR$0$0 == 0x00ff
                    00FF    266 _P2DIR	=	0x00ff
                    FFFFD5D4    267 Fwireless_tilt_mouse$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    268 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    269 Fwireless_tilt_mouse$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    270 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    271 Fwireless_tilt_mouse$FADDR$0$0 == 0xffffadac
                    FFFFADAC    272 _FADDR	=	0xffffadac
                    FFFFBBBA    273 Fwireless_tilt_mouse$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    274 _ADC	=	0xffffbbba
                    FFFFDBDA    275 Fwireless_tilt_mouse$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    276 _T1CC0	=	0xffffdbda
                    FFFFDDDC    277 Fwireless_tilt_mouse$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    278 _T1CC1	=	0xffffdddc
                    FFFFDFDE    279 Fwireless_tilt_mouse$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    280 _T1CC2	=	0xffffdfde
                            281 ;--------------------------------------------------------
                            282 ; special function bits
                            283 ;--------------------------------------------------------
                            284 	.area RSEG    (ABS,DATA)
   0000                     285 	.org 0x0000
                    0080    286 Fwireless_tilt_mouse$P0_0$0$0 == 0x0080
                    0080    287 _P0_0	=	0x0080
                    0081    288 Fwireless_tilt_mouse$P0_1$0$0 == 0x0081
                    0081    289 _P0_1	=	0x0081
                    0082    290 Fwireless_tilt_mouse$P0_2$0$0 == 0x0082
                    0082    291 _P0_2	=	0x0082
                    0083    292 Fwireless_tilt_mouse$P0_3$0$0 == 0x0083
                    0083    293 _P0_3	=	0x0083
                    0084    294 Fwireless_tilt_mouse$P0_4$0$0 == 0x0084
                    0084    295 _P0_4	=	0x0084
                    0085    296 Fwireless_tilt_mouse$P0_5$0$0 == 0x0085
                    0085    297 _P0_5	=	0x0085
                    0086    298 Fwireless_tilt_mouse$P0_6$0$0 == 0x0086
                    0086    299 _P0_6	=	0x0086
                    0087    300 Fwireless_tilt_mouse$P0_7$0$0 == 0x0087
                    0087    301 _P0_7	=	0x0087
                    0088    302 Fwireless_tilt_mouse$_TCON_0$0$0 == 0x0088
                    0088    303 __TCON_0	=	0x0088
                    0089    304 Fwireless_tilt_mouse$RFTXRXIF$0$0 == 0x0089
                    0089    305 _RFTXRXIF	=	0x0089
                    008A    306 Fwireless_tilt_mouse$_TCON_2$0$0 == 0x008a
                    008A    307 __TCON_2	=	0x008a
                    008B    308 Fwireless_tilt_mouse$URX0IF$0$0 == 0x008b
                    008B    309 _URX0IF	=	0x008b
                    008C    310 Fwireless_tilt_mouse$_TCON_4$0$0 == 0x008c
                    008C    311 __TCON_4	=	0x008c
                    008D    312 Fwireless_tilt_mouse$ADCIF$0$0 == 0x008d
                    008D    313 _ADCIF	=	0x008d
                    008E    314 Fwireless_tilt_mouse$_TCON_6$0$0 == 0x008e
                    008E    315 __TCON_6	=	0x008e
                    008F    316 Fwireless_tilt_mouse$URX1IF$0$0 == 0x008f
                    008F    317 _URX1IF	=	0x008f
                    0090    318 Fwireless_tilt_mouse$P1_0$0$0 == 0x0090
                    0090    319 _P1_0	=	0x0090
                    0091    320 Fwireless_tilt_mouse$P1_1$0$0 == 0x0091
                    0091    321 _P1_1	=	0x0091
                    0092    322 Fwireless_tilt_mouse$P1_2$0$0 == 0x0092
                    0092    323 _P1_2	=	0x0092
                    0093    324 Fwireless_tilt_mouse$P1_3$0$0 == 0x0093
                    0093    325 _P1_3	=	0x0093
                    0094    326 Fwireless_tilt_mouse$P1_4$0$0 == 0x0094
                    0094    327 _P1_4	=	0x0094
                    0095    328 Fwireless_tilt_mouse$P1_5$0$0 == 0x0095
                    0095    329 _P1_5	=	0x0095
                    0096    330 Fwireless_tilt_mouse$P1_6$0$0 == 0x0096
                    0096    331 _P1_6	=	0x0096
                    0097    332 Fwireless_tilt_mouse$P1_7$0$0 == 0x0097
                    0097    333 _P1_7	=	0x0097
                    0098    334 Fwireless_tilt_mouse$ENCIF_0$0$0 == 0x0098
                    0098    335 _ENCIF_0	=	0x0098
                    0099    336 Fwireless_tilt_mouse$ENCIF_1$0$0 == 0x0099
                    0099    337 _ENCIF_1	=	0x0099
                    009A    338 Fwireless_tilt_mouse$_SOCON2$0$0 == 0x009a
                    009A    339 __SOCON2	=	0x009a
                    009B    340 Fwireless_tilt_mouse$_SOCON3$0$0 == 0x009b
                    009B    341 __SOCON3	=	0x009b
                    009C    342 Fwireless_tilt_mouse$_SOCON4$0$0 == 0x009c
                    009C    343 __SOCON4	=	0x009c
                    009D    344 Fwireless_tilt_mouse$_SOCON5$0$0 == 0x009d
                    009D    345 __SOCON5	=	0x009d
                    009E    346 Fwireless_tilt_mouse$_SOCON6$0$0 == 0x009e
                    009E    347 __SOCON6	=	0x009e
                    009F    348 Fwireless_tilt_mouse$_SOCON7$0$0 == 0x009f
                    009F    349 __SOCON7	=	0x009f
                    00A0    350 Fwireless_tilt_mouse$P2_0$0$0 == 0x00a0
                    00A0    351 _P2_0	=	0x00a0
                    00A1    352 Fwireless_tilt_mouse$P2_1$0$0 == 0x00a1
                    00A1    353 _P2_1	=	0x00a1
                    00A2    354 Fwireless_tilt_mouse$P2_2$0$0 == 0x00a2
                    00A2    355 _P2_2	=	0x00a2
                    00A3    356 Fwireless_tilt_mouse$P2_3$0$0 == 0x00a3
                    00A3    357 _P2_3	=	0x00a3
                    00A4    358 Fwireless_tilt_mouse$P2_4$0$0 == 0x00a4
                    00A4    359 _P2_4	=	0x00a4
                    00A5    360 Fwireless_tilt_mouse$P2_5$0$0 == 0x00a5
                    00A5    361 _P2_5	=	0x00a5
                    00A6    362 Fwireless_tilt_mouse$P2_6$0$0 == 0x00a6
                    00A6    363 _P2_6	=	0x00a6
                    00A7    364 Fwireless_tilt_mouse$P2_7$0$0 == 0x00a7
                    00A7    365 _P2_7	=	0x00a7
                    00A8    366 Fwireless_tilt_mouse$RFTXRXIE$0$0 == 0x00a8
                    00A8    367 _RFTXRXIE	=	0x00a8
                    00A9    368 Fwireless_tilt_mouse$ADCIE$0$0 == 0x00a9
                    00A9    369 _ADCIE	=	0x00a9
                    00AA    370 Fwireless_tilt_mouse$URX0IE$0$0 == 0x00aa
                    00AA    371 _URX0IE	=	0x00aa
                    00AB    372 Fwireless_tilt_mouse$URX1IE$0$0 == 0x00ab
                    00AB    373 _URX1IE	=	0x00ab
                    00AC    374 Fwireless_tilt_mouse$ENCIE$0$0 == 0x00ac
                    00AC    375 _ENCIE	=	0x00ac
                    00AD    376 Fwireless_tilt_mouse$STIE$0$0 == 0x00ad
                    00AD    377 _STIE	=	0x00ad
                    00AE    378 Fwireless_tilt_mouse$_IEN06$0$0 == 0x00ae
                    00AE    379 __IEN06	=	0x00ae
                    00AF    380 Fwireless_tilt_mouse$EA$0$0 == 0x00af
                    00AF    381 _EA	=	0x00af
                    00B8    382 Fwireless_tilt_mouse$DMAIE$0$0 == 0x00b8
                    00B8    383 _DMAIE	=	0x00b8
                    00B9    384 Fwireless_tilt_mouse$T1IE$0$0 == 0x00b9
                    00B9    385 _T1IE	=	0x00b9
                    00BA    386 Fwireless_tilt_mouse$T2IE$0$0 == 0x00ba
                    00BA    387 _T2IE	=	0x00ba
                    00BB    388 Fwireless_tilt_mouse$T3IE$0$0 == 0x00bb
                    00BB    389 _T3IE	=	0x00bb
                    00BC    390 Fwireless_tilt_mouse$T4IE$0$0 == 0x00bc
                    00BC    391 _T4IE	=	0x00bc
                    00BD    392 Fwireless_tilt_mouse$P0IE$0$0 == 0x00bd
                    00BD    393 _P0IE	=	0x00bd
                    00BE    394 Fwireless_tilt_mouse$_IEN16$0$0 == 0x00be
                    00BE    395 __IEN16	=	0x00be
                    00BF    396 Fwireless_tilt_mouse$_IEN17$0$0 == 0x00bf
                    00BF    397 __IEN17	=	0x00bf
                    00C0    398 Fwireless_tilt_mouse$DMAIF$0$0 == 0x00c0
                    00C0    399 _DMAIF	=	0x00c0
                    00C1    400 Fwireless_tilt_mouse$T1IF$0$0 == 0x00c1
                    00C1    401 _T1IF	=	0x00c1
                    00C2    402 Fwireless_tilt_mouse$T2IF$0$0 == 0x00c2
                    00C2    403 _T2IF	=	0x00c2
                    00C3    404 Fwireless_tilt_mouse$T3IF$0$0 == 0x00c3
                    00C3    405 _T3IF	=	0x00c3
                    00C4    406 Fwireless_tilt_mouse$T4IF$0$0 == 0x00c4
                    00C4    407 _T4IF	=	0x00c4
                    00C5    408 Fwireless_tilt_mouse$P0IF$0$0 == 0x00c5
                    00C5    409 _P0IF	=	0x00c5
                    00C6    410 Fwireless_tilt_mouse$_IRCON6$0$0 == 0x00c6
                    00C6    411 __IRCON6	=	0x00c6
                    00C7    412 Fwireless_tilt_mouse$STIF$0$0 == 0x00c7
                    00C7    413 _STIF	=	0x00c7
                    00D0    414 Fwireless_tilt_mouse$P$0$0 == 0x00d0
                    00D0    415 _P	=	0x00d0
                    00D1    416 Fwireless_tilt_mouse$F1$0$0 == 0x00d1
                    00D1    417 _F1	=	0x00d1
                    00D2    418 Fwireless_tilt_mouse$OV$0$0 == 0x00d2
                    00D2    419 _OV	=	0x00d2
                    00D3    420 Fwireless_tilt_mouse$RS0$0$0 == 0x00d3
                    00D3    421 _RS0	=	0x00d3
                    00D4    422 Fwireless_tilt_mouse$RS1$0$0 == 0x00d4
                    00D4    423 _RS1	=	0x00d4
                    00D5    424 Fwireless_tilt_mouse$F0$0$0 == 0x00d5
                    00D5    425 _F0	=	0x00d5
                    00D6    426 Fwireless_tilt_mouse$AC$0$0 == 0x00d6
                    00D6    427 _AC	=	0x00d6
                    00D7    428 Fwireless_tilt_mouse$CY$0$0 == 0x00d7
                    00D7    429 _CY	=	0x00d7
                    00D8    430 Fwireless_tilt_mouse$T3OVFIF$0$0 == 0x00d8
                    00D8    431 _T3OVFIF	=	0x00d8
                    00D9    432 Fwireless_tilt_mouse$T3CH0IF$0$0 == 0x00d9
                    00D9    433 _T3CH0IF	=	0x00d9
                    00DA    434 Fwireless_tilt_mouse$T3CH1IF$0$0 == 0x00da
                    00DA    435 _T3CH1IF	=	0x00da
                    00DB    436 Fwireless_tilt_mouse$T4OVFIF$0$0 == 0x00db
                    00DB    437 _T4OVFIF	=	0x00db
                    00DC    438 Fwireless_tilt_mouse$T4CH0IF$0$0 == 0x00dc
                    00DC    439 _T4CH0IF	=	0x00dc
                    00DD    440 Fwireless_tilt_mouse$T4CH1IF$0$0 == 0x00dd
                    00DD    441 _T4CH1IF	=	0x00dd
                    00DE    442 Fwireless_tilt_mouse$OVFIM$0$0 == 0x00de
                    00DE    443 _OVFIM	=	0x00de
                    00DF    444 Fwireless_tilt_mouse$_TIMIF7$0$0 == 0x00df
                    00DF    445 __TIMIF7	=	0x00df
                    00E0    446 Fwireless_tilt_mouse$ACC_0$0$0 == 0x00e0
                    00E0    447 _ACC_0	=	0x00e0
                    00E1    448 Fwireless_tilt_mouse$ACC_1$0$0 == 0x00e1
                    00E1    449 _ACC_1	=	0x00e1
                    00E2    450 Fwireless_tilt_mouse$ACC_2$0$0 == 0x00e2
                    00E2    451 _ACC_2	=	0x00e2
                    00E3    452 Fwireless_tilt_mouse$ACC_3$0$0 == 0x00e3
                    00E3    453 _ACC_3	=	0x00e3
                    00E4    454 Fwireless_tilt_mouse$ACC_4$0$0 == 0x00e4
                    00E4    455 _ACC_4	=	0x00e4
                    00E5    456 Fwireless_tilt_mouse$ACC_5$0$0 == 0x00e5
                    00E5    457 _ACC_5	=	0x00e5
                    00E6    458 Fwireless_tilt_mouse$ACC_6$0$0 == 0x00e6
                    00E6    459 _ACC_6	=	0x00e6
                    00E7    460 Fwireless_tilt_mouse$ACC_7$0$0 == 0x00e7
                    00E7    461 _ACC_7	=	0x00e7
                    00E8    462 Fwireless_tilt_mouse$P2IF$0$0 == 0x00e8
                    00E8    463 _P2IF	=	0x00e8
                    00E9    464 Fwireless_tilt_mouse$UTX0IF$0$0 == 0x00e9
                    00E9    465 _UTX0IF	=	0x00e9
                    00EA    466 Fwireless_tilt_mouse$UTX1IF$0$0 == 0x00ea
                    00EA    467 _UTX1IF	=	0x00ea
                    00EB    468 Fwireless_tilt_mouse$P1IF$0$0 == 0x00eb
                    00EB    469 _P1IF	=	0x00eb
                    00EC    470 Fwireless_tilt_mouse$WDTIF$0$0 == 0x00ec
                    00EC    471 _WDTIF	=	0x00ec
                    00ED    472 Fwireless_tilt_mouse$_IRCON25$0$0 == 0x00ed
                    00ED    473 __IRCON25	=	0x00ed
                    00EE    474 Fwireless_tilt_mouse$_IRCON26$0$0 == 0x00ee
                    00EE    475 __IRCON26	=	0x00ee
                    00EF    476 Fwireless_tilt_mouse$_IRCON27$0$0 == 0x00ef
                    00EF    477 __IRCON27	=	0x00ef
                    00F0    478 Fwireless_tilt_mouse$B_0$0$0 == 0x00f0
                    00F0    479 _B_0	=	0x00f0
                    00F1    480 Fwireless_tilt_mouse$B_1$0$0 == 0x00f1
                    00F1    481 _B_1	=	0x00f1
                    00F2    482 Fwireless_tilt_mouse$B_2$0$0 == 0x00f2
                    00F2    483 _B_2	=	0x00f2
                    00F3    484 Fwireless_tilt_mouse$B_3$0$0 == 0x00f3
                    00F3    485 _B_3	=	0x00f3
                    00F4    486 Fwireless_tilt_mouse$B_4$0$0 == 0x00f4
                    00F4    487 _B_4	=	0x00f4
                    00F5    488 Fwireless_tilt_mouse$B_5$0$0 == 0x00f5
                    00F5    489 _B_5	=	0x00f5
                    00F6    490 Fwireless_tilt_mouse$B_6$0$0 == 0x00f6
                    00F6    491 _B_6	=	0x00f6
                    00F7    492 Fwireless_tilt_mouse$B_7$0$0 == 0x00f7
                    00F7    493 _B_7	=	0x00f7
                    00F8    494 Fwireless_tilt_mouse$U1ACTIVE$0$0 == 0x00f8
                    00F8    495 _U1ACTIVE	=	0x00f8
                    00F9    496 Fwireless_tilt_mouse$U1TX_BYTE$0$0 == 0x00f9
                    00F9    497 _U1TX_BYTE	=	0x00f9
                    00FA    498 Fwireless_tilt_mouse$U1RX_BYTE$0$0 == 0x00fa
                    00FA    499 _U1RX_BYTE	=	0x00fa
                    00FB    500 Fwireless_tilt_mouse$U1ERR$0$0 == 0x00fb
                    00FB    501 _U1ERR	=	0x00fb
                    00FC    502 Fwireless_tilt_mouse$U1FE$0$0 == 0x00fc
                    00FC    503 _U1FE	=	0x00fc
                    00FD    504 Fwireless_tilt_mouse$U1SLAVE$0$0 == 0x00fd
                    00FD    505 _U1SLAVE	=	0x00fd
                    00FE    506 Fwireless_tilt_mouse$U1RE$0$0 == 0x00fe
                    00FE    507 _U1RE	=	0x00fe
                    00FF    508 Fwireless_tilt_mouse$U1MODE$0$0 == 0x00ff
                    00FF    509 _U1MODE	=	0x00ff
                            510 ;--------------------------------------------------------
                            511 ; overlayable register banks
                            512 ;--------------------------------------------------------
                            513 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     514 	.ds 8
                            515 ;--------------------------------------------------------
                            516 ; overlayable bit register bank
                            517 ;--------------------------------------------------------
                            518 	.area BIT_BANK	(REL,OVR,DATA)
   0022                     519 bits:
   0022                     520 	.ds 1
                    8000    521 	b0 = bits[0]
                    8100    522 	b1 = bits[1]
                    8200    523 	b2 = bits[2]
                    8300    524 	b3 = bits[3]
                    8400    525 	b4 = bits[4]
                    8500    526 	b5 = bits[5]
                    8600    527 	b6 = bits[6]
                    8700    528 	b7 = bits[7]
                            529 ;--------------------------------------------------------
                            530 ; internal ram data
                            531 ;--------------------------------------------------------
                            532 	.area DSEG    (DATA)
                    0000    533 Lwireless_tilt_mouse.txMouseState$sloc0$1$0==.
   0008                     534 _txMouseState_sloc0_1_0:
   0008                     535 	.ds 4
                            536 ;--------------------------------------------------------
                            537 ; overlayable items in internal ram 
                            538 ;--------------------------------------------------------
                            539 	.area OSEG    (OVR,DATA)
                            540 ;--------------------------------------------------------
                            541 ; Stack segment in internal ram 
                            542 ;--------------------------------------------------------
                            543 	.area	SSEG	(DATA)
   0023                     544 __start__stack:
   0023                     545 	.ds	1
                            546 
                            547 ;--------------------------------------------------------
                            548 ; indirectly addressable internal ram data
                            549 ;--------------------------------------------------------
                            550 	.area ISEG    (DATA)
                            551 ;--------------------------------------------------------
                            552 ; absolute internal ram data
                            553 ;--------------------------------------------------------
                            554 	.area IABS    (ABS,DATA)
                            555 	.area IABS    (ABS,DATA)
                            556 ;--------------------------------------------------------
                            557 ; bit data
                            558 ;--------------------------------------------------------
                            559 	.area BSEG    (BIT)
                    0000    560 Lwireless_tilt_mouse.txMouseState$sloc1$1$0==.
   0000                     561 _txMouseState_sloc1_1_0:
   0000                     562 	.ds 1
                            563 ;--------------------------------------------------------
                            564 ; paged external ram data
                            565 ;--------------------------------------------------------
                            566 	.area PSEG    (PAG,XDATA)
                    0000    567 Lwireless_tilt_mouse.txMouseState$lastTx$1$1==.
   F000                     568 _txMouseState_lastTx_1_1:
   F000                     569 	.ds 1
                    0001    570 Lwireless_tilt_mouse.txMouseState$fx$2$2==.
   F001                     571 _txMouseState_fx_2_2:
   F001                     572 	.ds 4
                    0005    573 Lwireless_tilt_mouse.txMouseState$fy$2$2==.
   F005                     574 _txMouseState_fy_2_2:
   F005                     575 	.ds 4
                    0009    576 Lwireless_tilt_mouse.txMouseState$multiplier$2$2==.
   F009                     577 _txMouseState_multiplier_2_2:
   F009                     578 	.ds 4
                    000D    579 Lwireless_tilt_mouse.txMouseState$x$2$2==.
   F00D                     580 _txMouseState_x_2_2:
   F00D                     581 	.ds 1
                    000E    582 Lwireless_tilt_mouse.txMouseState$y$2$2==.
   F00E                     583 _txMouseState_y_2_2:
   F00E                     584 	.ds 1
                            585 ;--------------------------------------------------------
                            586 ; external ram data
                            587 ;--------------------------------------------------------
                            588 	.area XSEG    (XDATA)
                    DF00    589 Fwireless_tilt_mouse$SYNC1$0$0 == 0xdf00
                    DF00    590 _SYNC1	=	0xdf00
                    DF01    591 Fwireless_tilt_mouse$SYNC0$0$0 == 0xdf01
                    DF01    592 _SYNC0	=	0xdf01
                    DF02    593 Fwireless_tilt_mouse$PKTLEN$0$0 == 0xdf02
                    DF02    594 _PKTLEN	=	0xdf02
                    DF03    595 Fwireless_tilt_mouse$PKTCTRL1$0$0 == 0xdf03
                    DF03    596 _PKTCTRL1	=	0xdf03
                    DF04    597 Fwireless_tilt_mouse$PKTCTRL0$0$0 == 0xdf04
                    DF04    598 _PKTCTRL0	=	0xdf04
                    DF05    599 Fwireless_tilt_mouse$ADDR$0$0 == 0xdf05
                    DF05    600 _ADDR	=	0xdf05
                    DF06    601 Fwireless_tilt_mouse$CHANNR$0$0 == 0xdf06
                    DF06    602 _CHANNR	=	0xdf06
                    DF07    603 Fwireless_tilt_mouse$FSCTRL1$0$0 == 0xdf07
                    DF07    604 _FSCTRL1	=	0xdf07
                    DF08    605 Fwireless_tilt_mouse$FSCTRL0$0$0 == 0xdf08
                    DF08    606 _FSCTRL0	=	0xdf08
                    DF09    607 Fwireless_tilt_mouse$FREQ2$0$0 == 0xdf09
                    DF09    608 _FREQ2	=	0xdf09
                    DF0A    609 Fwireless_tilt_mouse$FREQ1$0$0 == 0xdf0a
                    DF0A    610 _FREQ1	=	0xdf0a
                    DF0B    611 Fwireless_tilt_mouse$FREQ0$0$0 == 0xdf0b
                    DF0B    612 _FREQ0	=	0xdf0b
                    DF0C    613 Fwireless_tilt_mouse$MDMCFG4$0$0 == 0xdf0c
                    DF0C    614 _MDMCFG4	=	0xdf0c
                    DF0D    615 Fwireless_tilt_mouse$MDMCFG3$0$0 == 0xdf0d
                    DF0D    616 _MDMCFG3	=	0xdf0d
                    DF0E    617 Fwireless_tilt_mouse$MDMCFG2$0$0 == 0xdf0e
                    DF0E    618 _MDMCFG2	=	0xdf0e
                    DF0F    619 Fwireless_tilt_mouse$MDMCFG1$0$0 == 0xdf0f
                    DF0F    620 _MDMCFG1	=	0xdf0f
                    DF10    621 Fwireless_tilt_mouse$MDMCFG0$0$0 == 0xdf10
                    DF10    622 _MDMCFG0	=	0xdf10
                    DF11    623 Fwireless_tilt_mouse$DEVIATN$0$0 == 0xdf11
                    DF11    624 _DEVIATN	=	0xdf11
                    DF12    625 Fwireless_tilt_mouse$MCSM2$0$0 == 0xdf12
                    DF12    626 _MCSM2	=	0xdf12
                    DF13    627 Fwireless_tilt_mouse$MCSM1$0$0 == 0xdf13
                    DF13    628 _MCSM1	=	0xdf13
                    DF14    629 Fwireless_tilt_mouse$MCSM0$0$0 == 0xdf14
                    DF14    630 _MCSM0	=	0xdf14
                    DF15    631 Fwireless_tilt_mouse$FOCCFG$0$0 == 0xdf15
                    DF15    632 _FOCCFG	=	0xdf15
                    DF16    633 Fwireless_tilt_mouse$BSCFG$0$0 == 0xdf16
                    DF16    634 _BSCFG	=	0xdf16
                    DF17    635 Fwireless_tilt_mouse$AGCCTRL2$0$0 == 0xdf17
                    DF17    636 _AGCCTRL2	=	0xdf17
                    DF18    637 Fwireless_tilt_mouse$AGCCTRL1$0$0 == 0xdf18
                    DF18    638 _AGCCTRL1	=	0xdf18
                    DF19    639 Fwireless_tilt_mouse$AGCCTRL0$0$0 == 0xdf19
                    DF19    640 _AGCCTRL0	=	0xdf19
                    DF1A    641 Fwireless_tilt_mouse$FREND1$0$0 == 0xdf1a
                    DF1A    642 _FREND1	=	0xdf1a
                    DF1B    643 Fwireless_tilt_mouse$FREND0$0$0 == 0xdf1b
                    DF1B    644 _FREND0	=	0xdf1b
                    DF1C    645 Fwireless_tilt_mouse$FSCAL3$0$0 == 0xdf1c
                    DF1C    646 _FSCAL3	=	0xdf1c
                    DF1D    647 Fwireless_tilt_mouse$FSCAL2$0$0 == 0xdf1d
                    DF1D    648 _FSCAL2	=	0xdf1d
                    DF1E    649 Fwireless_tilt_mouse$FSCAL1$0$0 == 0xdf1e
                    DF1E    650 _FSCAL1	=	0xdf1e
                    DF1F    651 Fwireless_tilt_mouse$FSCAL0$0$0 == 0xdf1f
                    DF1F    652 _FSCAL0	=	0xdf1f
                    DF23    653 Fwireless_tilt_mouse$TEST2$0$0 == 0xdf23
                    DF23    654 _TEST2	=	0xdf23
                    DF24    655 Fwireless_tilt_mouse$TEST1$0$0 == 0xdf24
                    DF24    656 _TEST1	=	0xdf24
                    DF25    657 Fwireless_tilt_mouse$TEST0$0$0 == 0xdf25
                    DF25    658 _TEST0	=	0xdf25
                    DF2E    659 Fwireless_tilt_mouse$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    660 _PA_TABLE0	=	0xdf2e
                    DF2F    661 Fwireless_tilt_mouse$IOCFG2$0$0 == 0xdf2f
                    DF2F    662 _IOCFG2	=	0xdf2f
                    DF30    663 Fwireless_tilt_mouse$IOCFG1$0$0 == 0xdf30
                    DF30    664 _IOCFG1	=	0xdf30
                    DF31    665 Fwireless_tilt_mouse$IOCFG0$0$0 == 0xdf31
                    DF31    666 _IOCFG0	=	0xdf31
                    DF36    667 Fwireless_tilt_mouse$PARTNUM$0$0 == 0xdf36
                    DF36    668 _PARTNUM	=	0xdf36
                    DF37    669 Fwireless_tilt_mouse$VERSION$0$0 == 0xdf37
                    DF37    670 _VERSION	=	0xdf37
                    DF38    671 Fwireless_tilt_mouse$FREQEST$0$0 == 0xdf38
                    DF38    672 _FREQEST	=	0xdf38
                    DF39    673 Fwireless_tilt_mouse$LQI$0$0 == 0xdf39
                    DF39    674 _LQI	=	0xdf39
                    DF3A    675 Fwireless_tilt_mouse$RSSI$0$0 == 0xdf3a
                    DF3A    676 _RSSI	=	0xdf3a
                    DF3B    677 Fwireless_tilt_mouse$MARCSTATE$0$0 == 0xdf3b
                    DF3B    678 _MARCSTATE	=	0xdf3b
                    DF3C    679 Fwireless_tilt_mouse$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    680 _PKTSTATUS	=	0xdf3c
                    DF3D    681 Fwireless_tilt_mouse$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    682 _VCO_VC_DAC	=	0xdf3d
                    DF40    683 Fwireless_tilt_mouse$I2SCFG0$0$0 == 0xdf40
                    DF40    684 _I2SCFG0	=	0xdf40
                    DF41    685 Fwireless_tilt_mouse$I2SCFG1$0$0 == 0xdf41
                    DF41    686 _I2SCFG1	=	0xdf41
                    DF42    687 Fwireless_tilt_mouse$I2SDATL$0$0 == 0xdf42
                    DF42    688 _I2SDATL	=	0xdf42
                    DF43    689 Fwireless_tilt_mouse$I2SDATH$0$0 == 0xdf43
                    DF43    690 _I2SDATH	=	0xdf43
                    DF44    691 Fwireless_tilt_mouse$I2SWCNT$0$0 == 0xdf44
                    DF44    692 _I2SWCNT	=	0xdf44
                    DF45    693 Fwireless_tilt_mouse$I2SSTAT$0$0 == 0xdf45
                    DF45    694 _I2SSTAT	=	0xdf45
                    DF46    695 Fwireless_tilt_mouse$I2SCLKF0$0$0 == 0xdf46
                    DF46    696 _I2SCLKF0	=	0xdf46
                    DF47    697 Fwireless_tilt_mouse$I2SCLKF1$0$0 == 0xdf47
                    DF47    698 _I2SCLKF1	=	0xdf47
                    DF48    699 Fwireless_tilt_mouse$I2SCLKF2$0$0 == 0xdf48
                    DF48    700 _I2SCLKF2	=	0xdf48
                    DE00    701 Fwireless_tilt_mouse$USBADDR$0$0 == 0xde00
                    DE00    702 _USBADDR	=	0xde00
                    DE01    703 Fwireless_tilt_mouse$USBPOW$0$0 == 0xde01
                    DE01    704 _USBPOW	=	0xde01
                    DE02    705 Fwireless_tilt_mouse$USBIIF$0$0 == 0xde02
                    DE02    706 _USBIIF	=	0xde02
                    DE04    707 Fwireless_tilt_mouse$USBOIF$0$0 == 0xde04
                    DE04    708 _USBOIF	=	0xde04
                    DE06    709 Fwireless_tilt_mouse$USBCIF$0$0 == 0xde06
                    DE06    710 _USBCIF	=	0xde06
                    DE07    711 Fwireless_tilt_mouse$USBIIE$0$0 == 0xde07
                    DE07    712 _USBIIE	=	0xde07
                    DE09    713 Fwireless_tilt_mouse$USBOIE$0$0 == 0xde09
                    DE09    714 _USBOIE	=	0xde09
                    DE0B    715 Fwireless_tilt_mouse$USBCIE$0$0 == 0xde0b
                    DE0B    716 _USBCIE	=	0xde0b
                    DE0C    717 Fwireless_tilt_mouse$USBFRML$0$0 == 0xde0c
                    DE0C    718 _USBFRML	=	0xde0c
                    DE0D    719 Fwireless_tilt_mouse$USBFRMH$0$0 == 0xde0d
                    DE0D    720 _USBFRMH	=	0xde0d
                    DE0E    721 Fwireless_tilt_mouse$USBINDEX$0$0 == 0xde0e
                    DE0E    722 _USBINDEX	=	0xde0e
                    DE10    723 Fwireless_tilt_mouse$USBMAXI$0$0 == 0xde10
                    DE10    724 _USBMAXI	=	0xde10
                    DE11    725 Fwireless_tilt_mouse$USBCSIL$0$0 == 0xde11
                    DE11    726 _USBCSIL	=	0xde11
                    DE12    727 Fwireless_tilt_mouse$USBCSIH$0$0 == 0xde12
                    DE12    728 _USBCSIH	=	0xde12
                    DE13    729 Fwireless_tilt_mouse$USBMAXO$0$0 == 0xde13
                    DE13    730 _USBMAXO	=	0xde13
                    DE14    731 Fwireless_tilt_mouse$USBCSOL$0$0 == 0xde14
                    DE14    732 _USBCSOL	=	0xde14
                    DE15    733 Fwireless_tilt_mouse$USBCSOH$0$0 == 0xde15
                    DE15    734 _USBCSOH	=	0xde15
                    DE16    735 Fwireless_tilt_mouse$USBCNTL$0$0 == 0xde16
                    DE16    736 _USBCNTL	=	0xde16
                    DE17    737 Fwireless_tilt_mouse$USBCNTH$0$0 == 0xde17
                    DE17    738 _USBCNTH	=	0xde17
                    DE20    739 Fwireless_tilt_mouse$USBF0$0$0 == 0xde20
                    DE20    740 _USBF0	=	0xde20
                    DE22    741 Fwireless_tilt_mouse$USBF1$0$0 == 0xde22
                    DE22    742 _USBF1	=	0xde22
                    DE24    743 Fwireless_tilt_mouse$USBF2$0$0 == 0xde24
                    DE24    744 _USBF2	=	0xde24
                    DE26    745 Fwireless_tilt_mouse$USBF3$0$0 == 0xde26
                    DE26    746 _USBF3	=	0xde26
                    DE28    747 Fwireless_tilt_mouse$USBF4$0$0 == 0xde28
                    DE28    748 _USBF4	=	0xde28
                    DE2A    749 Fwireless_tilt_mouse$USBF5$0$0 == 0xde2a
                    DE2A    750 _USBF5	=	0xde2a
                            751 ;--------------------------------------------------------
                            752 ; absolute external ram data
                            753 ;--------------------------------------------------------
                            754 	.area XABS    (ABS,XDATA)
                            755 ;--------------------------------------------------------
                            756 ; external initialized ram data
                            757 ;--------------------------------------------------------
                            758 	.area XISEG   (XDATA)
                            759 	.area HOME    (CODE)
                            760 	.area GSINIT0 (CODE)
                            761 	.area GSINIT1 (CODE)
                            762 	.area GSINIT2 (CODE)
                            763 	.area GSINIT3 (CODE)
                            764 	.area GSINIT4 (CODE)
                            765 	.area GSINIT5 (CODE)
                            766 	.area GSINIT  (CODE)
                            767 	.area GSFINAL (CODE)
                            768 	.area CSEG    (CODE)
                            769 ;--------------------------------------------------------
                            770 ; interrupt vector 
                            771 ;--------------------------------------------------------
                            772 	.area HOME    (CODE)
   0400                     773 __interrupt_vect:
   0400 02 04 8D            774 	ljmp	__sdcc_gsinit_startup
   0403 32                  775 	reti
   0404                     776 	.ds	7
   040B 32                  777 	reti
   040C                     778 	.ds	7
   0413 32                  779 	reti
   0414                     780 	.ds	7
   041B 32                  781 	reti
   041C                     782 	.ds	7
   0423 32                  783 	reti
   0424                     784 	.ds	7
   042B 32                  785 	reti
   042C                     786 	.ds	7
   0433 32                  787 	reti
   0434                     788 	.ds	7
   043B 32                  789 	reti
   043C                     790 	.ds	7
   0443 32                  791 	reti
   0444                     792 	.ds	7
   044B 32                  793 	reti
   044C                     794 	.ds	7
   0453 32                  795 	reti
   0454                     796 	.ds	7
   045B 32                  797 	reti
   045C                     798 	.ds	7
   0463 02 14 E8            799 	ljmp	_ISR_T4
   0466                     800 	.ds	5
   046B 32                  801 	reti
   046C                     802 	.ds	7
   0473 32                  803 	reti
   0474                     804 	.ds	7
   047B 32                  805 	reti
   047C                     806 	.ds	7
   0483 02 09 31            807 	ljmp	_ISR_RF
                            808 ;--------------------------------------------------------
                            809 ; global & static initialisations
                            810 ;--------------------------------------------------------
                            811 	.area HOME    (CODE)
                            812 	.area GSINIT  (CODE)
                            813 	.area GSFINAL (CODE)
                            814 	.area GSINIT  (CODE)
                            815 	.globl __sdcc_gsinit_startup
                            816 	.globl __sdcc_program_startup
                            817 	.globl __start__stack
                            818 	.globl __mcs51_genXINIT
                            819 	.globl __mcs51_genXRAMCLEAR
                            820 	.globl __mcs51_genRAMCLEAR
                            821 ;------------------------------------------------------------
                            822 ;Allocation info for local variables in function 'txMouseState'
                            823 ;------------------------------------------------------------
                            824 ;sloc0                     Allocated with name '_txMouseState_sloc0_1_0'
                            825 ;------------------------------------------------------------
                    0000    826 	G$txMouseState$0$0 ==.
                    0000    827 	C$wireless_tilt_mouse.c$52$2$1 ==.
                            828 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:52: static uint8 lastTx = 0;
   04E6 78 00               829 	mov	r0,#_txMouseState_lastTx_1_1
   04E8 E4                  830 	clr	a
   04E9 F2                  831 	movx	@r0,a
                            832 	.area GSFINAL (CODE)
   052B 02 04 86            833 	ljmp	__sdcc_program_startup
                            834 ;--------------------------------------------------------
                            835 ; Home
                            836 ;--------------------------------------------------------
                            837 	.area HOME    (CODE)
                            838 	.area HOME    (CODE)
   0486                     839 __sdcc_program_startup:
   0486 12 08 9B            840 	lcall	_main
                            841 ;	return from main will lock up
   0489 80 FE               842 	sjmp .
                            843 ;--------------------------------------------------------
                            844 ; code
                            845 ;--------------------------------------------------------
                            846 	.area CSEG    (CODE)
                            847 ;------------------------------------------------------------
                            848 ;Allocation info for local variables in function 'updateLeds'
                            849 ;------------------------------------------------------------
                    0000    850 	G$updateLeds$0$0 ==.
                    0000    851 	C$wireless_tilt_mouse.c$43$0$0 ==.
                            852 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:43: void updateLeds()
                            853 ;	-----------------------------------------
                            854 ;	 function updateLeds
                            855 ;	-----------------------------------------
   052E                     856 _updateLeds:
                    0007    857 	ar7 = 0x07
                    0006    858 	ar6 = 0x06
                    0005    859 	ar5 = 0x05
                    0004    860 	ar4 = 0x04
                    0003    861 	ar3 = 0x03
                    0002    862 	ar2 = 0x02
                    0001    863 	ar1 = 0x01
                    0000    864 	ar0 = 0x00
                    0000    865 	C$wireless_tilt_mouse.c$45$1$1 ==.
                            866 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:45: usbShowStatusWithGreenLed();
   052E 12 23 1C            867 	lcall	_usbShowStatusWithGreenLed
                    0003    868 	C$wireless_tilt_mouse.c$46$2$2 ==.
                            869 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:46: LED_YELLOW(vinPowerPresent());
   0531 12 11 BA            870 	lcall	_vinPowerPresent
   0534 50 05               871 	jnc	00103$
   0536 43 FF 04            872 	orl	_P2DIR,#0x04
   0539 80 07               873 	sjmp	00101$
   053B                     874 00103$:
   053B AF FF               875 	mov	r7,_P2DIR
   053D 53 07 FB            876 	anl	ar7,#0xFB
   0540 8F FF               877 	mov	_P2DIR,r7
   0542                     878 00101$:
                    0014    879 	C$wireless_tilt_mouse.c$47$2$2 ==.
                    0014    880 	XG$updateLeds$0$0 ==.
   0542 22                  881 	ret
                            882 ;------------------------------------------------------------
                            883 ;Allocation info for local variables in function 'txMouseState'
                            884 ;------------------------------------------------------------
                            885 ;sloc0                     Allocated with name '_txMouseState_sloc0_1_0'
                            886 ;------------------------------------------------------------
                    0015    887 	G$txMouseState$0$0 ==.
                    0015    888 	C$wireless_tilt_mouse.c$49$2$2 ==.
                            889 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:49: void txMouseState()
                            890 ;	-----------------------------------------
                            891 ;	 function txMouseState
                            892 ;	-----------------------------------------
   0543                     893 _txMouseState:
                    0015    894 	C$wireless_tilt_mouse.c$54$1$1 ==.
                            895 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:54: if ((uint8)(getMs() - lastTx) > TX_INTERVAL && (txBuf = radioQueueTxCurrentPacket()))
   0543 12 15 0D            896 	lcall	_getMs
   0546 AC 82               897 	mov	r4,dpl
   0548 AD 83               898 	mov	r5,dph
   054A AE F0               899 	mov	r6,b
   054C FF                  900 	mov	r7,a
   054D 78 00               901 	mov	r0,#_txMouseState_lastTx_1_1
   054F D3                  902 	setb	c
   0550 E2                  903 	movx	a,@r0
   0551 9C                  904 	subb	a,r4
   0552 F4                  905 	cpl	a
   0553 FC                  906 	mov  r4,a
   0554 24 F5               907 	add	a,#0xff - 0x0A
   0556 40 03               908 	jc	00114$
   0558 02 08 9A            909 	ljmp	00108$
   055B                     910 00114$:
   055B 12 0C 2E            911 	lcall	_radioQueueTxCurrentPacket
   055E AE 82               912 	mov	r6,dpl
   0560 AF 83               913 	mov	r7,dph
   0562 8E 04               914 	mov	ar4,r6
   0564 8F 05               915 	mov	ar5,r7
   0566 EE                  916 	mov	a,r6
   0567 4F                  917 	orl	a,r7
   0568 70 03               918 	jnz	00115$
   056A 02 08 9A            919 	ljmp	00108$
   056D                     920 00115$:
                    003F    921 	C$wireless_tilt_mouse.c$59$2$1 ==.
                            922 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:59: fx = -((float)adcRead(2 | ADC_BITS_12) - 1024) / 128;  // fx = Acceleration in X direction (floating point)
   056D C0 04               923 	push	ar4
   056F C0 05               924 	push	ar5
   0571 75 82 02            925 	mov	dpl,#0x02
   0574 C0 05               926 	push	ar5
   0576 C0 04               927 	push	ar4
   0578 12 08 D4            928 	lcall	_adcRead
   057B 12 22 4D            929 	lcall	___uint2fs
   057E AA 82               930 	mov	r2,dpl
   0580 AB 83               931 	mov	r3,dph
   0582 AE F0               932 	mov	r6,b
   0584 FF                  933 	mov	r7,a
   0585 E4                  934 	clr	a
   0586 C0 E0               935 	push	acc
   0588 C0 E0               936 	push	acc
   058A 74 80               937 	mov	a,#0x80
   058C C0 E0               938 	push	acc
   058E 74 44               939 	mov	a,#0x44
   0590 C0 E0               940 	push	acc
   0592 8A 82               941 	mov	dpl,r2
   0594 8B 83               942 	mov	dph,r3
   0596 8E F0               943 	mov	b,r6
   0598 EF                  944 	mov	a,r7
   0599 12 08 C9            945 	lcall	___fssub
   059C AA 82               946 	mov	r2,dpl
   059E AB 83               947 	mov	r3,dph
   05A0 AE F0               948 	mov	r6,b
   05A2 FF                  949 	mov	r7,a
   05A3 E5 81               950 	mov	a,sp
   05A5 24 FC               951 	add	a,#0xfc
   05A7 F5 81               952 	mov	sp,a
   05A9 EF                  953 	mov	a,r7
   05AA B2 E7               954 	cpl	acc.7
   05AC FF                  955 	mov	r7,a
   05AD E4                  956 	clr	a
   05AE C0 E0               957 	push	acc
   05B0 C0 E0               958 	push	acc
   05B2 C0 E0               959 	push	acc
   05B4 74 43               960 	mov	a,#0x43
   05B6 C0 E0               961 	push	acc
   05B8 8A 82               962 	mov	dpl,r2
   05BA 8B 83               963 	mov	dph,r3
   05BC 8E F0               964 	mov	b,r6
   05BE EF                  965 	mov	a,r7
   05BF 12 24 13            966 	lcall	___fsdiv
   05C2 78 01               967 	mov	r0,#_txMouseState_fx_2_2
   05C4 C0 E0               968 	push	acc
   05C6 E5 82               969 	mov	a,dpl
   05C8 F2                  970 	movx	@r0,a
   05C9 08                  971 	inc	r0
   05CA E5 83               972 	mov	a,dph
   05CC F2                  973 	movx	@r0,a
   05CD 08                  974 	inc	r0
   05CE E5 F0               975 	mov	a,b
   05D0 F2                  976 	movx	@r0,a
   05D1 D0 E0               977 	pop	acc
   05D3 08                  978 	inc	r0
   05D4 F2                  979 	movx	@r0,a
   05D5 E5 81               980 	mov	a,sp
   05D7 24 FC               981 	add	a,#0xfc
   05D9 F5 81               982 	mov	sp,a
                    00AD    983 	C$wireless_tilt_mouse.c$60$2$2 ==.
                            984 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:60: fy =  ((float)adcRead(1 | ADC_BITS_12) - 1024) / 128;  // fy = Acceleration in Y direction
   05DB 75 82 01            985 	mov	dpl,#0x01
   05DE 12 08 D4            986 	lcall	_adcRead
   05E1 D0 04               987 	pop	ar4
   05E3 D0 05               988 	pop	ar5
   05E5 12 22 4D            989 	lcall	___uint2fs
   05E8 AC 82               990 	mov	r4,dpl
   05EA AD 83               991 	mov	r5,dph
   05EC AE F0               992 	mov	r6,b
   05EE FF                  993 	mov	r7,a
   05EF E4                  994 	clr	a
   05F0 C0 E0               995 	push	acc
   05F2 C0 E0               996 	push	acc
   05F4 74 80               997 	mov	a,#0x80
   05F6 C0 E0               998 	push	acc
   05F8 74 44               999 	mov	a,#0x44
   05FA C0 E0              1000 	push	acc
   05FC 8C 82              1001 	mov	dpl,r4
   05FE 8D 83              1002 	mov	dph,r5
   0600 8E F0              1003 	mov	b,r6
   0602 EF                 1004 	mov	a,r7
   0603 12 08 C9           1005 	lcall	___fssub
   0606 AC 82              1006 	mov	r4,dpl
   0608 AD 83              1007 	mov	r5,dph
   060A AE F0              1008 	mov	r6,b
   060C FF                 1009 	mov	r7,a
   060D E5 81              1010 	mov	a,sp
   060F 24 FC              1011 	add	a,#0xfc
   0611 F5 81              1012 	mov	sp,a
   0613 C0 05              1013 	push	ar5
   0615 C0 04              1014 	push	ar4
   0617 E4                 1015 	clr	a
   0618 C0 E0              1016 	push	acc
   061A C0 E0              1017 	push	acc
   061C C0 E0              1018 	push	acc
   061E 74 43              1019 	mov	a,#0x43
   0620 C0 E0              1020 	push	acc
   0622 8C 82              1021 	mov	dpl,r4
   0624 8D 83              1022 	mov	dph,r5
   0626 8E F0              1023 	mov	b,r6
   0628 EF                 1024 	mov	a,r7
   0629 12 24 13           1025 	lcall	___fsdiv
   062C 78 05              1026 	mov	r0,#_txMouseState_fy_2_2
   062E C0 E0              1027 	push	acc
   0630 E5 82              1028 	mov	a,dpl
   0632 F2                 1029 	movx	@r0,a
   0633 08                 1030 	inc	r0
   0634 E5 83              1031 	mov	a,dph
   0636 F2                 1032 	movx	@r0,a
   0637 08                 1033 	inc	r0
   0638 E5 F0              1034 	mov	a,b
   063A F2                 1035 	movx	@r0,a
   063B D0 E0              1036 	pop	acc
   063D 08                 1037 	inc	r0
   063E F2                 1038 	movx	@r0,a
   063F E5 81              1039 	mov	a,sp
   0641 24 FC              1040 	add	a,#0xfc
   0643 F5 81              1041 	mov	sp,a
                    0117   1042 	C$wireless_tilt_mouse.c$61$2$1 ==.
                           1043 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:61: multiplier = sqrtf(fx * fx + fy * fy) * param_speed/100;
   0645 78 01              1044 	mov	r0,#_txMouseState_fx_2_2
   0647 E2                 1045 	movx	a,@r0
   0648 C0 E0              1046 	push	acc
   064A 08                 1047 	inc	r0
   064B E2                 1048 	movx	a,@r0
   064C C0 E0              1049 	push	acc
   064E 08                 1050 	inc	r0
   064F E2                 1051 	movx	a,@r0
   0650 C0 E0              1052 	push	acc
   0652 08                 1053 	inc	r0
   0653 E2                 1054 	movx	a,@r0
   0654 C0 E0              1055 	push	acc
   0656 78 01              1056 	mov	r0,#_txMouseState_fx_2_2
   0658 E2                 1057 	movx	a,@r0
   0659 F5 82              1058 	mov	dpl,a
   065B 08                 1059 	inc	r0
   065C E2                 1060 	movx	a,@r0
   065D F5 83              1061 	mov	dph,a
   065F 08                 1062 	inc	r0
   0660 E2                 1063 	movx	a,@r0
   0661 F5 F0              1064 	mov	b,a
   0663 08                 1065 	inc	r0
   0664 E2                 1066 	movx	a,@r0
   0665 12 0B 19           1067 	lcall	___fsmul
   0668 85 82 08           1068 	mov	_txMouseState_sloc0_1_0,dpl
   066B 85 83 09           1069 	mov	(_txMouseState_sloc0_1_0 + 1),dph
   066E 85 F0 0A           1070 	mov	(_txMouseState_sloc0_1_0 + 2),b
   0671 F5 0B              1071 	mov	(_txMouseState_sloc0_1_0 + 3),a
   0673 E5 81              1072 	mov	a,sp
   0675 24 FC              1073 	add	a,#0xfc
   0677 F5 81              1074 	mov	sp,a
   0679 D0 04              1075 	pop	ar4
   067B D0 05              1076 	pop	ar5
   067D 78 05              1077 	mov	r0,#_txMouseState_fy_2_2
   067F E2                 1078 	movx	a,@r0
   0680 C0 E0              1079 	push	acc
   0682 08                 1080 	inc	r0
   0683 E2                 1081 	movx	a,@r0
   0684 C0 E0              1082 	push	acc
   0686 08                 1083 	inc	r0
   0687 E2                 1084 	movx	a,@r0
   0688 C0 E0              1085 	push	acc
   068A 08                 1086 	inc	r0
   068B E2                 1087 	movx	a,@r0
   068C C0 E0              1088 	push	acc
   068E 78 05              1089 	mov	r0,#_txMouseState_fy_2_2
   0690 E2                 1090 	movx	a,@r0
   0691 F5 82              1091 	mov	dpl,a
   0693 08                 1092 	inc	r0
   0694 E2                 1093 	movx	a,@r0
   0695 F5 83              1094 	mov	dph,a
   0697 08                 1095 	inc	r0
   0698 E2                 1096 	movx	a,@r0
   0699 F5 F0              1097 	mov	b,a
   069B 08                 1098 	inc	r0
   069C E2                 1099 	movx	a,@r0
   069D 12 0B 19           1100 	lcall	___fsmul
   06A0 AC 82              1101 	mov	r4,dpl
   06A2 AD 83              1102 	mov	r5,dph
   06A4 AE F0              1103 	mov	r6,b
   06A6 FF                 1104 	mov	r7,a
   06A7 E5 81              1105 	mov	a,sp
   06A9 24 FC              1106 	add	a,#0xfc
   06AB F5 81              1107 	mov	sp,a
   06AD C0 04              1108 	push	ar4
   06AF C0 05              1109 	push	ar5
   06B1 C0 06              1110 	push	ar6
   06B3 C0 07              1111 	push	ar7
   06B5 85 08 82           1112 	mov	dpl,_txMouseState_sloc0_1_0
   06B8 85 09 83           1113 	mov	dph,(_txMouseState_sloc0_1_0 + 1)
   06BB 85 0A F0           1114 	mov	b,(_txMouseState_sloc0_1_0 + 2)
   06BE E5 0B              1115 	mov	a,(_txMouseState_sloc0_1_0 + 3)
   06C0 12 15 6D           1116 	lcall	___fsadd
   06C3 AC 82              1117 	mov	r4,dpl
   06C5 AD 83              1118 	mov	r5,dph
   06C7 AE F0              1119 	mov	r6,b
   06C9 FF                 1120 	mov	r7,a
   06CA E5 81              1121 	mov	a,sp
   06CC 24 FC              1122 	add	a,#0xfc
   06CE F5 81              1123 	mov	sp,a
   06D0 8C 82              1124 	mov	dpl,r4
   06D2 8D 83              1125 	mov	dph,r5
   06D4 8E F0              1126 	mov	b,r6
   06D6 EF                 1127 	mov	a,r7
   06D7 C0 05              1128 	push	ar5
   06D9 C0 04              1129 	push	ar4
   06DB 12 0E 01           1130 	lcall	_sqrtf
   06DE 85 82 08           1131 	mov	_txMouseState_sloc0_1_0,dpl
   06E1 85 83 09           1132 	mov	(_txMouseState_sloc0_1_0 + 1),dph
   06E4 85 F0 0A           1133 	mov	(_txMouseState_sloc0_1_0 + 2),b
   06E7 F5 0B              1134 	mov	(_txMouseState_sloc0_1_0 + 3),a
   06E9 D0 04              1135 	pop	ar4
   06EB D0 05              1136 	pop	ar5
   06ED 90 26 37           1137 	mov	dptr,#_param_speed
   06F0 E4                 1138 	clr	a
   06F1 93                 1139 	movc	a,@a+dptr
   06F2 FA                 1140 	mov	r2,a
   06F3 74 01              1141 	mov	a,#0x01
   06F5 93                 1142 	movc	a,@a+dptr
   06F6 FB                 1143 	mov	r3,a
   06F7 74 02              1144 	mov	a,#0x02
   06F9 93                 1145 	movc	a,@a+dptr
   06FA FE                 1146 	mov	r6,a
   06FB 74 03              1147 	mov	a,#0x03
   06FD 93                 1148 	movc	a,@a+dptr
   06FE 8A 82              1149 	mov	dpl,r2
   0700 8B 83              1150 	mov	dph,r3
   0702 8E F0              1151 	mov	b,r6
   0704 12 0D D4           1152 	lcall	___slong2fs
   0707 AC 82              1153 	mov	r4,dpl
   0709 AD 83              1154 	mov	r5,dph
   070B AE F0              1155 	mov	r6,b
   070D FF                 1156 	mov	r7,a
   070E C0 04              1157 	push	ar4
   0710 C0 05              1158 	push	ar5
   0712 C0 06              1159 	push	ar6
   0714 C0 07              1160 	push	ar7
   0716 85 08 82           1161 	mov	dpl,_txMouseState_sloc0_1_0
   0719 85 09 83           1162 	mov	dph,(_txMouseState_sloc0_1_0 + 1)
   071C 85 0A F0           1163 	mov	b,(_txMouseState_sloc0_1_0 + 2)
   071F E5 0B              1164 	mov	a,(_txMouseState_sloc0_1_0 + 3)
   0721 12 0B 19           1165 	lcall	___fsmul
   0724 AC 82              1166 	mov	r4,dpl
   0726 AD 83              1167 	mov	r5,dph
   0728 AE F0              1168 	mov	r6,b
   072A FF                 1169 	mov	r7,a
   072B E5 81              1170 	mov	a,sp
   072D 24 FC              1171 	add	a,#0xfc
   072F F5 81              1172 	mov	sp,a
   0731 C0 05              1173 	push	ar5
   0733 C0 04              1174 	push	ar4
   0735 E4                 1175 	clr	a
   0736 C0 E0              1176 	push	acc
   0738 C0 E0              1177 	push	acc
   073A 74 C8              1178 	mov	a,#0xC8
   073C C0 E0              1179 	push	acc
   073E 74 42              1180 	mov	a,#0x42
   0740 C0 E0              1181 	push	acc
   0742 8C 82              1182 	mov	dpl,r4
   0744 8D 83              1183 	mov	dph,r5
   0746 8E F0              1184 	mov	b,r6
   0748 EF                 1185 	mov	a,r7
   0749 12 24 13           1186 	lcall	___fsdiv
   074C 78 09              1187 	mov	r0,#_txMouseState_multiplier_2_2
   074E C0 E0              1188 	push	acc
   0750 E5 82              1189 	mov	a,dpl
   0752 F2                 1190 	movx	@r0,a
   0753 08                 1191 	inc	r0
   0754 E5 83              1192 	mov	a,dph
   0756 F2                 1193 	movx	@r0,a
   0757 08                 1194 	inc	r0
   0758 E5 F0              1195 	mov	a,b
   075A F2                 1196 	movx	@r0,a
   075B D0 E0              1197 	pop	acc
   075D 08                 1198 	inc	r0
   075E F2                 1199 	movx	@r0,a
   075F E5 81              1200 	mov	a,sp
   0761 24 FC              1201 	add	a,#0xfc
   0763 F5 81              1202 	mov	sp,a
                    0237   1203 	C$wireless_tilt_mouse.c$64$2$1 ==.
                           1204 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:64: x = (int8)(fx * multiplier);
   0765 78 09              1205 	mov	r0,#_txMouseState_multiplier_2_2
   0767 E2                 1206 	movx	a,@r0
   0768 C0 E0              1207 	push	acc
   076A 08                 1208 	inc	r0
   076B E2                 1209 	movx	a,@r0
   076C C0 E0              1210 	push	acc
   076E 08                 1211 	inc	r0
   076F E2                 1212 	movx	a,@r0
   0770 C0 E0              1213 	push	acc
   0772 08                 1214 	inc	r0
   0773 E2                 1215 	movx	a,@r0
   0774 C0 E0              1216 	push	acc
   0776 78 01              1217 	mov	r0,#_txMouseState_fx_2_2
   0778 E2                 1218 	movx	a,@r0
   0779 F5 82              1219 	mov	dpl,a
   077B 08                 1220 	inc	r0
   077C E2                 1221 	movx	a,@r0
   077D F5 83              1222 	mov	dph,a
   077F 08                 1223 	inc	r0
   0780 E2                 1224 	movx	a,@r0
   0781 F5 F0              1225 	mov	b,a
   0783 08                 1226 	inc	r0
   0784 E2                 1227 	movx	a,@r0
   0785 12 0B 19           1228 	lcall	___fsmul
   0788 AA 82              1229 	mov	r2,dpl
   078A AB 83              1230 	mov	r3,dph
   078C AE F0              1231 	mov	r6,b
   078E FF                 1232 	mov	r7,a
   078F E5 81              1233 	mov	a,sp
   0791 24 FC              1234 	add	a,#0xfc
   0793 F5 81              1235 	mov	sp,a
   0795 8A 82              1236 	mov	dpl,r2
   0797 8B 83              1237 	mov	dph,r3
   0799 8E F0              1238 	mov	b,r6
   079B EF                 1239 	mov	a,r7
   079C 12 24 D6           1240 	lcall	___fs2schar
   079F 78 0D              1241 	mov	r0,#_txMouseState_x_2_2
   07A1 E5 82              1242 	mov	a,dpl
   07A3 F2                 1243 	movx	@r0,a
   07A4 D0 04              1244 	pop	ar4
   07A6 D0 05              1245 	pop	ar5
                    027A   1246 	C$wireless_tilt_mouse.c$65$2$1 ==.
                           1247 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:65: y = (int8)(fy * multiplier);
   07A8 78 09              1248 	mov	r0,#_txMouseState_multiplier_2_2
   07AA E2                 1249 	movx	a,@r0
   07AB C0 E0              1250 	push	acc
   07AD 08                 1251 	inc	r0
   07AE E2                 1252 	movx	a,@r0
   07AF C0 E0              1253 	push	acc
   07B1 08                 1254 	inc	r0
   07B2 E2                 1255 	movx	a,@r0
   07B3 C0 E0              1256 	push	acc
   07B5 08                 1257 	inc	r0
   07B6 E2                 1258 	movx	a,@r0
   07B7 C0 E0              1259 	push	acc
   07B9 78 05              1260 	mov	r0,#_txMouseState_fy_2_2
   07BB E2                 1261 	movx	a,@r0
   07BC F5 82              1262 	mov	dpl,a
   07BE 08                 1263 	inc	r0
   07BF E2                 1264 	movx	a,@r0
   07C0 F5 83              1265 	mov	dph,a
   07C2 08                 1266 	inc	r0
   07C3 E2                 1267 	movx	a,@r0
   07C4 F5 F0              1268 	mov	b,a
   07C6 08                 1269 	inc	r0
   07C7 E2                 1270 	movx	a,@r0
   07C8 12 0B 19           1271 	lcall	___fsmul
   07CB AC 82              1272 	mov	r4,dpl
   07CD AD 83              1273 	mov	r5,dph
   07CF AE F0              1274 	mov	r6,b
   07D1 FF                 1275 	mov	r7,a
   07D2 E5 81              1276 	mov	a,sp
   07D4 24 FC              1277 	add	a,#0xfc
   07D6 F5 81              1278 	mov	sp,a
   07D8 8C 82              1279 	mov	dpl,r4
   07DA 8D 83              1280 	mov	dph,r5
   07DC 8E F0              1281 	mov	b,r6
   07DE EF                 1282 	mov	a,r7
   07DF C0 05              1283 	push	ar5
   07E1 C0 04              1284 	push	ar4
   07E3 12 24 D6           1285 	lcall	___fs2schar
   07E6 78 0E              1286 	mov	r0,#_txMouseState_y_2_2
   07E8 E5 82              1287 	mov	a,dpl
   07EA F2                 1288 	movx	@r0,a
   07EB D0 04              1289 	pop	ar4
   07ED D0 05              1290 	pop	ar5
                    02C1   1291 	C$wireless_tilt_mouse.c$66$2$2 ==.
                           1292 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:66: if (param_invert_x){ x = -x; }
   07EF 90 26 2F           1293 	mov	dptr,#_param_invert_x
   07F2 E4                 1294 	clr	a
   07F3 93                 1295 	movc	a,@a+dptr
   07F4 FC                 1296 	mov	r4,a
   07F5 74 01              1297 	mov	a,#0x01
   07F7 93                 1298 	movc	a,@a+dptr
   07F8 FD                 1299 	mov	r5,a
   07F9 74 02              1300 	mov	a,#0x02
   07FB 93                 1301 	movc	a,@a+dptr
   07FC FE                 1302 	mov	r6,a
   07FD 74 03              1303 	mov	a,#0x03
   07FF 93                 1304 	movc	a,@a+dptr
   0800 FF                 1305 	mov	r7,a
   0801 EC                 1306 	mov	a,r4
   0802 4D                 1307 	orl	a,r5
   0803 4E                 1308 	orl	a,r6
   0804 4F                 1309 	orl	a,r7
   0805 D0 05              1310 	pop	ar5
   0807 D0 04              1311 	pop	ar4
   0809 60 08              1312 	jz	00102$
   080B 78 0D              1313 	mov	r0,#_txMouseState_x_2_2
   080D E2                 1314 	movx	a,@r0
   080E D3                 1315 	setb	c
   080F F4                 1316 	cpl	a
   0810 34 00              1317 	addc	a,#0x00
   0812 F2                 1318 	movx	@r0,a
   0813                    1319 00102$:
                    02E5   1320 	C$wireless_tilt_mouse.c$67$2$2 ==.
                           1321 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:67: if (param_invert_y){ y = -y; }
   0813 90 26 33           1322 	mov	dptr,#_param_invert_y
   0816 E4                 1323 	clr	a
   0817 93                 1324 	movc	a,@a+dptr
   0818 FA                 1325 	mov	r2,a
   0819 74 01              1326 	mov	a,#0x01
   081B 93                 1327 	movc	a,@a+dptr
   081C FB                 1328 	mov	r3,a
   081D 74 02              1329 	mov	a,#0x02
   081F 93                 1330 	movc	a,@a+dptr
   0820 FE                 1331 	mov	r6,a
   0821 74 03              1332 	mov	a,#0x03
   0823 93                 1333 	movc	a,@a+dptr
   0824 FF                 1334 	mov	r7,a
   0825 EA                 1335 	mov	a,r2
   0826 4B                 1336 	orl	a,r3
   0827 4E                 1337 	orl	a,r6
   0828 4F                 1338 	orl	a,r7
   0829 60 08              1339 	jz	00104$
   082B 78 0E              1340 	mov	r0,#_txMouseState_y_2_2
   082D E2                 1341 	movx	a,@r0
   082E D3                 1342 	setb	c
   082F F4                 1343 	cpl	a
   0830 34 00              1344 	addc	a,#0x00
   0832 F2                 1345 	movx	@r0,a
   0833                    1346 00104$:
                    0305   1347 	C$wireless_tilt_mouse.c$70$2$2 ==.
                           1348 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:70: txBuf[0] = 3;  // Packet length in bytes.
   0833 8C 82              1349 	mov	dpl,r4
   0835 8D 83              1350 	mov	dph,r5
   0837 74 03              1351 	mov	a,#0x03
   0839 F0                 1352 	movx	@dptr,a
                    030C   1353 	C$wireless_tilt_mouse.c$71$2$2 ==.
                           1354 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:71: txBuf[1] = x;
   083A 8C 82              1355 	mov	dpl,r4
   083C 8D 83              1356 	mov	dph,r5
   083E A3                 1357 	inc	dptr
   083F 78 0D              1358 	mov	r0,#_txMouseState_x_2_2
   0841 E2                 1359 	movx	a,@r0
   0842 F0                 1360 	movx	@dptr,a
                    0315   1361 	C$wireless_tilt_mouse.c$72$2$2 ==.
                           1362 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:72: txBuf[2] = y;
   0843 8C 82              1363 	mov	dpl,r4
   0845 8D 83              1364 	mov	dph,r5
   0847 A3                 1365 	inc	dptr
   0848 A3                 1366 	inc	dptr
   0849 78 0E              1367 	mov	r0,#_txMouseState_y_2_2
   084B E2                 1368 	movx	a,@r0
   084C F0                 1369 	movx	@dptr,a
                    031F   1370 	C$wireless_tilt_mouse.c$73$2$2 ==.
                           1371 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:73: txBuf[3] = (!isPinHigh(12) << MOUSE_BUTTON_LEFT) | (!isPinHigh(17) << MOUSE_BUTTON_RIGHT);
   084D 74 03              1372 	mov	a,#0x03
   084F 2C                 1373 	add	a,r4
   0850 FC                 1374 	mov	r4,a
   0851 E4                 1375 	clr	a
   0852 3D                 1376 	addc	a,r5
   0853 FD                 1377 	mov	r5,a
   0854 75 82 0C           1378 	mov	dpl,#0x0C
   0857 C0 05              1379 	push	ar5
   0859 C0 04              1380 	push	ar4
   085B 12 19 FF           1381 	lcall	_isPinHigh
   085E D0 04              1382 	pop	ar4
   0860 D0 05              1383 	pop	ar5
   0862 B3                 1384 	cpl	c
   0863 92 00              1385 	mov	_txMouseState_sloc1_1_0,c
   0865 E4                 1386 	clr	a
   0866 33                 1387 	rlc	a
   0867 FF                 1388 	mov	r7,a
   0868 75 82 11           1389 	mov	dpl,#0x11
   086B C0 07              1390 	push	ar7
   086D C0 05              1391 	push	ar5
   086F C0 04              1392 	push	ar4
   0871 12 19 FF           1393 	lcall	_isPinHigh
   0874 D0 04              1394 	pop	ar4
   0876 D0 05              1395 	pop	ar5
   0878 D0 07              1396 	pop	ar7
   087A B3                 1397 	cpl	c
   087B 92 00              1398 	mov	_txMouseState_sloc1_1_0,c
   087D E4                 1399 	clr	a
   087E 33                 1400 	rlc	a
   087F 25 E0              1401 	add	a,acc
   0881 42 07              1402 	orl	ar7,a
   0883 8C 82              1403 	mov	dpl,r4
   0885 8D 83              1404 	mov	dph,r5
   0887 EF                 1405 	mov	a,r7
   0888 F0                 1406 	movx	@dptr,a
                    035B   1407 	C$wireless_tilt_mouse.c$74$2$2 ==.
                           1408 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:74: radioQueueTxSendPacket();
   0889 12 0C 4C           1409 	lcall	_radioQueueTxSendPacket
                    035E   1410 	C$wireless_tilt_mouse.c$76$2$2 ==.
                           1411 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:76: lastTx = getMs();
   088C 12 15 0D           1412 	lcall	_getMs
   088F AC 82              1413 	mov	r4,dpl
   0891 AD 83              1414 	mov	r5,dph
   0893 AE F0              1415 	mov	r6,b
   0895 FF                 1416 	mov	r7,a
   0896 78 00              1417 	mov	r0,#_txMouseState_lastTx_1_1
   0898 EC                 1418 	mov	a,r4
   0899 F2                 1419 	movx	@r0,a
   089A                    1420 00108$:
                    036C   1421 	C$wireless_tilt_mouse.c$78$2$1 ==.
                    036C   1422 	XG$txMouseState$0$0 ==.
   089A 22                 1423 	ret
                           1424 ;------------------------------------------------------------
                           1425 ;Allocation info for local variables in function 'main'
                           1426 ;------------------------------------------------------------
                    036D   1427 	G$main$0$0 ==.
                    036D   1428 	C$wireless_tilt_mouse.c$80$2$1 ==.
                           1429 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:80: void main()
                           1430 ;	-----------------------------------------
                           1431 ;	 function main
                           1432 ;	-----------------------------------------
   089B                    1433 _main:
                    036D   1434 	C$wireless_tilt_mouse.c$82$1$1 ==.
                           1435 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:82: systemInit();
   089B 12 10 F0           1436 	lcall	_systemInit
                    0370   1437 	C$wireless_tilt_mouse.c$83$1$1 ==.
                           1438 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:83: usbInit();
   089E 12 1B 16           1439 	lcall	_usbInit
                    0373   1440 	C$wireless_tilt_mouse.c$85$1$1 ==.
                           1441 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:85: radioQueueInit();
   08A1 12 0B EA           1442 	lcall	_radioQueueInit
                    0376   1443 	C$wireless_tilt_mouse.c$88$1$1 ==.
                           1444 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:88: setDigitalInput(1, HIGH_IMPEDANCE);
   08A4 C2 F0              1445 	clr	b[0]
   08A6 85 F0 22           1446 	mov	bits,b
   08A9 75 82 01           1447 	mov	dpl,#0x01
   08AC 12 17 E1           1448 	lcall	_setDigitalInput
                    0381   1449 	C$wireless_tilt_mouse.c$89$1$1 ==.
                           1450 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:89: setDigitalInput(2, HIGH_IMPEDANCE);
   08AF C2 F0              1451 	clr	b[0]
   08B1 85 F0 22           1452 	mov	bits,b
   08B4 75 82 02           1453 	mov	dpl,#0x02
   08B7 12 17 E1           1454 	lcall	_setDigitalInput
                    038C   1455 	C$wireless_tilt_mouse.c$91$1$1 ==.
                           1456 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:91: while(1)
   08BA                    1457 00102$:
                    038C   1458 	C$wireless_tilt_mouse.c$93$2$2 ==.
                           1459 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:93: updateLeds();
   08BA 12 05 2E           1460 	lcall	_updateLeds
                    038F   1461 	C$wireless_tilt_mouse.c$94$2$2 ==.
                           1462 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:94: boardService();
   08BD 12 10 FD           1463 	lcall	_boardService
                    0392   1464 	C$wireless_tilt_mouse.c$95$2$2 ==.
                           1465 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:95: usbComService();
   08C0 12 13 21           1466 	lcall	_usbComService
                    0395   1467 	C$wireless_tilt_mouse.c$97$2$2 ==.
                           1468 ;	apps/wireless_tilt_mouse/wireless_tilt_mouse.c:97: txMouseState();
   08C3 12 05 43           1469 	lcall	_txMouseState
   08C6 80 F2              1470 	sjmp	00102$
                    039A   1471 	C$wireless_tilt_mouse.c$99$1$1 ==.
                    039A   1472 	XG$main$0$0 ==.
   08C8 22                 1473 	ret
                           1474 	.area CSEG    (CODE)
                           1475 	.area CONST   (CODE)
                    0000   1476 G$param_invert_x$0$0 == .
   262F                    1477 _param_invert_x:
   262F 00 00 00 00        1478 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   1479 G$param_invert_y$0$0 == .
   2633                    1480 _param_invert_y:
   2633 00 00 00 00        1481 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0008   1482 G$param_speed$0$0 == .
   2637                    1483 _param_speed:
   2637 64 00 00 00        1484 	.byte #0x64,#0x00,#0x00,#0x00	;  100
                           1485 	.area XINIT   (CODE)
                           1486 	.area CABS    (ABS,CODE)
