                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 23:16:07 2012
                              5 ;--------------------------------------------------------
                              6 	.module wireless_tilt_mouse_receiver
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _rxMouseState
                             14 	.globl _updateLeds
                             15 	.globl _radioQueueRxDoneWithPacket
                             16 	.globl _radioQueueRxCurrentPacket
                             17 	.globl _radioQueueInit
                             18 	.globl _usbHidService
                             19 	.globl _usbShowStatusWithGreenLed
                             20 	.globl _usbInit
                             21 	.globl _boardService
                             22 	.globl _systemInit
                             23 ;--------------------------------------------------------
                             24 ; special function registers
                             25 ;--------------------------------------------------------
                             26 	.area RSEG    (ABS,DATA)
   0000                      27 	.org 0x0000
                    0080     28 Fwireless_tilt_mouse_receiver$P0$0$0 == 0x0080
                    0080     29 _P0	=	0x0080
                    0081     30 Fwireless_tilt_mouse_receiver$SP$0$0 == 0x0081
                    0081     31 _SP	=	0x0081
                    0082     32 Fwireless_tilt_mouse_receiver$DPL0$0$0 == 0x0082
                    0082     33 _DPL0	=	0x0082
                    0083     34 Fwireless_tilt_mouse_receiver$DPH0$0$0 == 0x0083
                    0083     35 _DPH0	=	0x0083
                    0084     36 Fwireless_tilt_mouse_receiver$DPL1$0$0 == 0x0084
                    0084     37 _DPL1	=	0x0084
                    0085     38 Fwireless_tilt_mouse_receiver$DPH1$0$0 == 0x0085
                    0085     39 _DPH1	=	0x0085
                    0086     40 Fwireless_tilt_mouse_receiver$U0CSR$0$0 == 0x0086
                    0086     41 _U0CSR	=	0x0086
                    0087     42 Fwireless_tilt_mouse_receiver$PCON$0$0 == 0x0087
                    0087     43 _PCON	=	0x0087
                    0088     44 Fwireless_tilt_mouse_receiver$TCON$0$0 == 0x0088
                    0088     45 _TCON	=	0x0088
                    0089     46 Fwireless_tilt_mouse_receiver$P0IFG$0$0 == 0x0089
                    0089     47 _P0IFG	=	0x0089
                    008A     48 Fwireless_tilt_mouse_receiver$P1IFG$0$0 == 0x008a
                    008A     49 _P1IFG	=	0x008a
                    008B     50 Fwireless_tilt_mouse_receiver$P2IFG$0$0 == 0x008b
                    008B     51 _P2IFG	=	0x008b
                    008C     52 Fwireless_tilt_mouse_receiver$PICTL$0$0 == 0x008c
                    008C     53 _PICTL	=	0x008c
                    008D     54 Fwireless_tilt_mouse_receiver$P1IEN$0$0 == 0x008d
                    008D     55 _P1IEN	=	0x008d
                    008F     56 Fwireless_tilt_mouse_receiver$P0INP$0$0 == 0x008f
                    008F     57 _P0INP	=	0x008f
                    0090     58 Fwireless_tilt_mouse_receiver$P1$0$0 == 0x0090
                    0090     59 _P1	=	0x0090
                    0091     60 Fwireless_tilt_mouse_receiver$RFIM$0$0 == 0x0091
                    0091     61 _RFIM	=	0x0091
                    0092     62 Fwireless_tilt_mouse_receiver$DPS$0$0 == 0x0092
                    0092     63 _DPS	=	0x0092
                    0093     64 Fwireless_tilt_mouse_receiver$MPAGE$0$0 == 0x0093
                    0093     65 _MPAGE	=	0x0093
                    0095     66 Fwireless_tilt_mouse_receiver$ENDIAN$0$0 == 0x0095
                    0095     67 _ENDIAN	=	0x0095
                    0098     68 Fwireless_tilt_mouse_receiver$S0CON$0$0 == 0x0098
                    0098     69 _S0CON	=	0x0098
                    009A     70 Fwireless_tilt_mouse_receiver$IEN2$0$0 == 0x009a
                    009A     71 _IEN2	=	0x009a
                    009B     72 Fwireless_tilt_mouse_receiver$S1CON$0$0 == 0x009b
                    009B     73 _S1CON	=	0x009b
                    009C     74 Fwireless_tilt_mouse_receiver$T2CT$0$0 == 0x009c
                    009C     75 _T2CT	=	0x009c
                    009D     76 Fwireless_tilt_mouse_receiver$T2PR$0$0 == 0x009d
                    009D     77 _T2PR	=	0x009d
                    009E     78 Fwireless_tilt_mouse_receiver$T2CTL$0$0 == 0x009e
                    009E     79 _T2CTL	=	0x009e
                    00A0     80 Fwireless_tilt_mouse_receiver$P2$0$0 == 0x00a0
                    00A0     81 _P2	=	0x00a0
                    00A1     82 Fwireless_tilt_mouse_receiver$WORIRQ$0$0 == 0x00a1
                    00A1     83 _WORIRQ	=	0x00a1
                    00A2     84 Fwireless_tilt_mouse_receiver$WORCTRL$0$0 == 0x00a2
                    00A2     85 _WORCTRL	=	0x00a2
                    00A3     86 Fwireless_tilt_mouse_receiver$WOREVT0$0$0 == 0x00a3
                    00A3     87 _WOREVT0	=	0x00a3
                    00A4     88 Fwireless_tilt_mouse_receiver$WOREVT1$0$0 == 0x00a4
                    00A4     89 _WOREVT1	=	0x00a4
                    00A5     90 Fwireless_tilt_mouse_receiver$WORTIME0$0$0 == 0x00a5
                    00A5     91 _WORTIME0	=	0x00a5
                    00A6     92 Fwireless_tilt_mouse_receiver$WORTIME1$0$0 == 0x00a6
                    00A6     93 _WORTIME1	=	0x00a6
                    00A8     94 Fwireless_tilt_mouse_receiver$IEN0$0$0 == 0x00a8
                    00A8     95 _IEN0	=	0x00a8
                    00A9     96 Fwireless_tilt_mouse_receiver$IP0$0$0 == 0x00a9
                    00A9     97 _IP0	=	0x00a9
                    00AB     98 Fwireless_tilt_mouse_receiver$FWT$0$0 == 0x00ab
                    00AB     99 _FWT	=	0x00ab
                    00AC    100 Fwireless_tilt_mouse_receiver$FADDRL$0$0 == 0x00ac
                    00AC    101 _FADDRL	=	0x00ac
                    00AD    102 Fwireless_tilt_mouse_receiver$FADDRH$0$0 == 0x00ad
                    00AD    103 _FADDRH	=	0x00ad
                    00AE    104 Fwireless_tilt_mouse_receiver$FCTL$0$0 == 0x00ae
                    00AE    105 _FCTL	=	0x00ae
                    00AF    106 Fwireless_tilt_mouse_receiver$FWDATA$0$0 == 0x00af
                    00AF    107 _FWDATA	=	0x00af
                    00B1    108 Fwireless_tilt_mouse_receiver$ENCDI$0$0 == 0x00b1
                    00B1    109 _ENCDI	=	0x00b1
                    00B2    110 Fwireless_tilt_mouse_receiver$ENCDO$0$0 == 0x00b2
                    00B2    111 _ENCDO	=	0x00b2
                    00B3    112 Fwireless_tilt_mouse_receiver$ENCCS$0$0 == 0x00b3
                    00B3    113 _ENCCS	=	0x00b3
                    00B4    114 Fwireless_tilt_mouse_receiver$ADCCON1$0$0 == 0x00b4
                    00B4    115 _ADCCON1	=	0x00b4
                    00B5    116 Fwireless_tilt_mouse_receiver$ADCCON2$0$0 == 0x00b5
                    00B5    117 _ADCCON2	=	0x00b5
                    00B6    118 Fwireless_tilt_mouse_receiver$ADCCON3$0$0 == 0x00b6
                    00B6    119 _ADCCON3	=	0x00b6
                    00B8    120 Fwireless_tilt_mouse_receiver$IEN1$0$0 == 0x00b8
                    00B8    121 _IEN1	=	0x00b8
                    00B9    122 Fwireless_tilt_mouse_receiver$IP1$0$0 == 0x00b9
                    00B9    123 _IP1	=	0x00b9
                    00BA    124 Fwireless_tilt_mouse_receiver$ADCL$0$0 == 0x00ba
                    00BA    125 _ADCL	=	0x00ba
                    00BB    126 Fwireless_tilt_mouse_receiver$ADCH$0$0 == 0x00bb
                    00BB    127 _ADCH	=	0x00bb
                    00BC    128 Fwireless_tilt_mouse_receiver$RNDL$0$0 == 0x00bc
                    00BC    129 _RNDL	=	0x00bc
                    00BD    130 Fwireless_tilt_mouse_receiver$RNDH$0$0 == 0x00bd
                    00BD    131 _RNDH	=	0x00bd
                    00BE    132 Fwireless_tilt_mouse_receiver$SLEEP$0$0 == 0x00be
                    00BE    133 _SLEEP	=	0x00be
                    00C0    134 Fwireless_tilt_mouse_receiver$IRCON$0$0 == 0x00c0
                    00C0    135 _IRCON	=	0x00c0
                    00C1    136 Fwireless_tilt_mouse_receiver$U0DBUF$0$0 == 0x00c1
                    00C1    137 _U0DBUF	=	0x00c1
                    00C2    138 Fwireless_tilt_mouse_receiver$U0BAUD$0$0 == 0x00c2
                    00C2    139 _U0BAUD	=	0x00c2
                    00C4    140 Fwireless_tilt_mouse_receiver$U0UCR$0$0 == 0x00c4
                    00C4    141 _U0UCR	=	0x00c4
                    00C5    142 Fwireless_tilt_mouse_receiver$U0GCR$0$0 == 0x00c5
                    00C5    143 _U0GCR	=	0x00c5
                    00C6    144 Fwireless_tilt_mouse_receiver$CLKCON$0$0 == 0x00c6
                    00C6    145 _CLKCON	=	0x00c6
                    00C7    146 Fwireless_tilt_mouse_receiver$MEMCTR$0$0 == 0x00c7
                    00C7    147 _MEMCTR	=	0x00c7
                    00C9    148 Fwireless_tilt_mouse_receiver$WDCTL$0$0 == 0x00c9
                    00C9    149 _WDCTL	=	0x00c9
                    00CA    150 Fwireless_tilt_mouse_receiver$T3CNT$0$0 == 0x00ca
                    00CA    151 _T3CNT	=	0x00ca
                    00CB    152 Fwireless_tilt_mouse_receiver$T3CTL$0$0 == 0x00cb
                    00CB    153 _T3CTL	=	0x00cb
                    00CC    154 Fwireless_tilt_mouse_receiver$T3CCTL0$0$0 == 0x00cc
                    00CC    155 _T3CCTL0	=	0x00cc
                    00CD    156 Fwireless_tilt_mouse_receiver$T3CC0$0$0 == 0x00cd
                    00CD    157 _T3CC0	=	0x00cd
                    00CE    158 Fwireless_tilt_mouse_receiver$T3CCTL1$0$0 == 0x00ce
                    00CE    159 _T3CCTL1	=	0x00ce
                    00CF    160 Fwireless_tilt_mouse_receiver$T3CC1$0$0 == 0x00cf
                    00CF    161 _T3CC1	=	0x00cf
                    00D0    162 Fwireless_tilt_mouse_receiver$PSW$0$0 == 0x00d0
                    00D0    163 _PSW	=	0x00d0
                    00D1    164 Fwireless_tilt_mouse_receiver$DMAIRQ$0$0 == 0x00d1
                    00D1    165 _DMAIRQ	=	0x00d1
                    00D2    166 Fwireless_tilt_mouse_receiver$DMA1CFGL$0$0 == 0x00d2
                    00D2    167 _DMA1CFGL	=	0x00d2
                    00D3    168 Fwireless_tilt_mouse_receiver$DMA1CFGH$0$0 == 0x00d3
                    00D3    169 _DMA1CFGH	=	0x00d3
                    00D4    170 Fwireless_tilt_mouse_receiver$DMA0CFGL$0$0 == 0x00d4
                    00D4    171 _DMA0CFGL	=	0x00d4
                    00D5    172 Fwireless_tilt_mouse_receiver$DMA0CFGH$0$0 == 0x00d5
                    00D5    173 _DMA0CFGH	=	0x00d5
                    00D6    174 Fwireless_tilt_mouse_receiver$DMAARM$0$0 == 0x00d6
                    00D6    175 _DMAARM	=	0x00d6
                    00D7    176 Fwireless_tilt_mouse_receiver$DMAREQ$0$0 == 0x00d7
                    00D7    177 _DMAREQ	=	0x00d7
                    00D8    178 Fwireless_tilt_mouse_receiver$TIMIF$0$0 == 0x00d8
                    00D8    179 _TIMIF	=	0x00d8
                    00D9    180 Fwireless_tilt_mouse_receiver$RFD$0$0 == 0x00d9
                    00D9    181 _RFD	=	0x00d9
                    00DA    182 Fwireless_tilt_mouse_receiver$T1CC0L$0$0 == 0x00da
                    00DA    183 _T1CC0L	=	0x00da
                    00DB    184 Fwireless_tilt_mouse_receiver$T1CC0H$0$0 == 0x00db
                    00DB    185 _T1CC0H	=	0x00db
                    00DC    186 Fwireless_tilt_mouse_receiver$T1CC1L$0$0 == 0x00dc
                    00DC    187 _T1CC1L	=	0x00dc
                    00DD    188 Fwireless_tilt_mouse_receiver$T1CC1H$0$0 == 0x00dd
                    00DD    189 _T1CC1H	=	0x00dd
                    00DE    190 Fwireless_tilt_mouse_receiver$T1CC2L$0$0 == 0x00de
                    00DE    191 _T1CC2L	=	0x00de
                    00DF    192 Fwireless_tilt_mouse_receiver$T1CC2H$0$0 == 0x00df
                    00DF    193 _T1CC2H	=	0x00df
                    00E0    194 Fwireless_tilt_mouse_receiver$ACC$0$0 == 0x00e0
                    00E0    195 _ACC	=	0x00e0
                    00E1    196 Fwireless_tilt_mouse_receiver$RFST$0$0 == 0x00e1
                    00E1    197 _RFST	=	0x00e1
                    00E2    198 Fwireless_tilt_mouse_receiver$T1CNTL$0$0 == 0x00e2
                    00E2    199 _T1CNTL	=	0x00e2
                    00E3    200 Fwireless_tilt_mouse_receiver$T1CNTH$0$0 == 0x00e3
                    00E3    201 _T1CNTH	=	0x00e3
                    00E4    202 Fwireless_tilt_mouse_receiver$T1CTL$0$0 == 0x00e4
                    00E4    203 _T1CTL	=	0x00e4
                    00E5    204 Fwireless_tilt_mouse_receiver$T1CCTL0$0$0 == 0x00e5
                    00E5    205 _T1CCTL0	=	0x00e5
                    00E6    206 Fwireless_tilt_mouse_receiver$T1CCTL1$0$0 == 0x00e6
                    00E6    207 _T1CCTL1	=	0x00e6
                    00E7    208 Fwireless_tilt_mouse_receiver$T1CCTL2$0$0 == 0x00e7
                    00E7    209 _T1CCTL2	=	0x00e7
                    00E8    210 Fwireless_tilt_mouse_receiver$IRCON2$0$0 == 0x00e8
                    00E8    211 _IRCON2	=	0x00e8
                    00E9    212 Fwireless_tilt_mouse_receiver$RFIF$0$0 == 0x00e9
                    00E9    213 _RFIF	=	0x00e9
                    00EA    214 Fwireless_tilt_mouse_receiver$T4CNT$0$0 == 0x00ea
                    00EA    215 _T4CNT	=	0x00ea
                    00EB    216 Fwireless_tilt_mouse_receiver$T4CTL$0$0 == 0x00eb
                    00EB    217 _T4CTL	=	0x00eb
                    00EC    218 Fwireless_tilt_mouse_receiver$T4CCTL0$0$0 == 0x00ec
                    00EC    219 _T4CCTL0	=	0x00ec
                    00ED    220 Fwireless_tilt_mouse_receiver$T4CC0$0$0 == 0x00ed
                    00ED    221 _T4CC0	=	0x00ed
                    00EE    222 Fwireless_tilt_mouse_receiver$T4CCTL1$0$0 == 0x00ee
                    00EE    223 _T4CCTL1	=	0x00ee
                    00EF    224 Fwireless_tilt_mouse_receiver$T4CC1$0$0 == 0x00ef
                    00EF    225 _T4CC1	=	0x00ef
                    00F0    226 Fwireless_tilt_mouse_receiver$B$0$0 == 0x00f0
                    00F0    227 _B	=	0x00f0
                    00F1    228 Fwireless_tilt_mouse_receiver$PERCFG$0$0 == 0x00f1
                    00F1    229 _PERCFG	=	0x00f1
                    00F2    230 Fwireless_tilt_mouse_receiver$ADCCFG$0$0 == 0x00f2
                    00F2    231 _ADCCFG	=	0x00f2
                    00F3    232 Fwireless_tilt_mouse_receiver$P0SEL$0$0 == 0x00f3
                    00F3    233 _P0SEL	=	0x00f3
                    00F4    234 Fwireless_tilt_mouse_receiver$P1SEL$0$0 == 0x00f4
                    00F4    235 _P1SEL	=	0x00f4
                    00F5    236 Fwireless_tilt_mouse_receiver$P2SEL$0$0 == 0x00f5
                    00F5    237 _P2SEL	=	0x00f5
                    00F6    238 Fwireless_tilt_mouse_receiver$P1INP$0$0 == 0x00f6
                    00F6    239 _P1INP	=	0x00f6
                    00F7    240 Fwireless_tilt_mouse_receiver$P2INP$0$0 == 0x00f7
                    00F7    241 _P2INP	=	0x00f7
                    00F8    242 Fwireless_tilt_mouse_receiver$U1CSR$0$0 == 0x00f8
                    00F8    243 _U1CSR	=	0x00f8
                    00F9    244 Fwireless_tilt_mouse_receiver$U1DBUF$0$0 == 0x00f9
                    00F9    245 _U1DBUF	=	0x00f9
                    00FA    246 Fwireless_tilt_mouse_receiver$U1BAUD$0$0 == 0x00fa
                    00FA    247 _U1BAUD	=	0x00fa
                    00FB    248 Fwireless_tilt_mouse_receiver$U1UCR$0$0 == 0x00fb
                    00FB    249 _U1UCR	=	0x00fb
                    00FC    250 Fwireless_tilt_mouse_receiver$U1GCR$0$0 == 0x00fc
                    00FC    251 _U1GCR	=	0x00fc
                    00FD    252 Fwireless_tilt_mouse_receiver$P0DIR$0$0 == 0x00fd
                    00FD    253 _P0DIR	=	0x00fd
                    00FE    254 Fwireless_tilt_mouse_receiver$P1DIR$0$0 == 0x00fe
                    00FE    255 _P1DIR	=	0x00fe
                    00FF    256 Fwireless_tilt_mouse_receiver$P2DIR$0$0 == 0x00ff
                    00FF    257 _P2DIR	=	0x00ff
                    FFFFD5D4    258 Fwireless_tilt_mouse_receiver$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    259 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    260 Fwireless_tilt_mouse_receiver$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    261 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    262 Fwireless_tilt_mouse_receiver$FADDR$0$0 == 0xffffadac
                    FFFFADAC    263 _FADDR	=	0xffffadac
                    FFFFBBBA    264 Fwireless_tilt_mouse_receiver$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    265 _ADC	=	0xffffbbba
                    FFFFDBDA    266 Fwireless_tilt_mouse_receiver$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    267 _T1CC0	=	0xffffdbda
                    FFFFDDDC    268 Fwireless_tilt_mouse_receiver$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    269 _T1CC1	=	0xffffdddc
                    FFFFDFDE    270 Fwireless_tilt_mouse_receiver$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    271 _T1CC2	=	0xffffdfde
                            272 ;--------------------------------------------------------
                            273 ; special function bits
                            274 ;--------------------------------------------------------
                            275 	.area RSEG    (ABS,DATA)
   0000                     276 	.org 0x0000
                    0080    277 Fwireless_tilt_mouse_receiver$P0_0$0$0 == 0x0080
                    0080    278 _P0_0	=	0x0080
                    0081    279 Fwireless_tilt_mouse_receiver$P0_1$0$0 == 0x0081
                    0081    280 _P0_1	=	0x0081
                    0082    281 Fwireless_tilt_mouse_receiver$P0_2$0$0 == 0x0082
                    0082    282 _P0_2	=	0x0082
                    0083    283 Fwireless_tilt_mouse_receiver$P0_3$0$0 == 0x0083
                    0083    284 _P0_3	=	0x0083
                    0084    285 Fwireless_tilt_mouse_receiver$P0_4$0$0 == 0x0084
                    0084    286 _P0_4	=	0x0084
                    0085    287 Fwireless_tilt_mouse_receiver$P0_5$0$0 == 0x0085
                    0085    288 _P0_5	=	0x0085
                    0086    289 Fwireless_tilt_mouse_receiver$P0_6$0$0 == 0x0086
                    0086    290 _P0_6	=	0x0086
                    0087    291 Fwireless_tilt_mouse_receiver$P0_7$0$0 == 0x0087
                    0087    292 _P0_7	=	0x0087
                    0088    293 Fwireless_tilt_mouse_receiver$_TCON_0$0$0 == 0x0088
                    0088    294 __TCON_0	=	0x0088
                    0089    295 Fwireless_tilt_mouse_receiver$RFTXRXIF$0$0 == 0x0089
                    0089    296 _RFTXRXIF	=	0x0089
                    008A    297 Fwireless_tilt_mouse_receiver$_TCON_2$0$0 == 0x008a
                    008A    298 __TCON_2	=	0x008a
                    008B    299 Fwireless_tilt_mouse_receiver$URX0IF$0$0 == 0x008b
                    008B    300 _URX0IF	=	0x008b
                    008C    301 Fwireless_tilt_mouse_receiver$_TCON_4$0$0 == 0x008c
                    008C    302 __TCON_4	=	0x008c
                    008D    303 Fwireless_tilt_mouse_receiver$ADCIF$0$0 == 0x008d
                    008D    304 _ADCIF	=	0x008d
                    008E    305 Fwireless_tilt_mouse_receiver$_TCON_6$0$0 == 0x008e
                    008E    306 __TCON_6	=	0x008e
                    008F    307 Fwireless_tilt_mouse_receiver$URX1IF$0$0 == 0x008f
                    008F    308 _URX1IF	=	0x008f
                    0090    309 Fwireless_tilt_mouse_receiver$P1_0$0$0 == 0x0090
                    0090    310 _P1_0	=	0x0090
                    0091    311 Fwireless_tilt_mouse_receiver$P1_1$0$0 == 0x0091
                    0091    312 _P1_1	=	0x0091
                    0092    313 Fwireless_tilt_mouse_receiver$P1_2$0$0 == 0x0092
                    0092    314 _P1_2	=	0x0092
                    0093    315 Fwireless_tilt_mouse_receiver$P1_3$0$0 == 0x0093
                    0093    316 _P1_3	=	0x0093
                    0094    317 Fwireless_tilt_mouse_receiver$P1_4$0$0 == 0x0094
                    0094    318 _P1_4	=	0x0094
                    0095    319 Fwireless_tilt_mouse_receiver$P1_5$0$0 == 0x0095
                    0095    320 _P1_5	=	0x0095
                    0096    321 Fwireless_tilt_mouse_receiver$P1_6$0$0 == 0x0096
                    0096    322 _P1_6	=	0x0096
                    0097    323 Fwireless_tilt_mouse_receiver$P1_7$0$0 == 0x0097
                    0097    324 _P1_7	=	0x0097
                    0098    325 Fwireless_tilt_mouse_receiver$ENCIF_0$0$0 == 0x0098
                    0098    326 _ENCIF_0	=	0x0098
                    0099    327 Fwireless_tilt_mouse_receiver$ENCIF_1$0$0 == 0x0099
                    0099    328 _ENCIF_1	=	0x0099
                    009A    329 Fwireless_tilt_mouse_receiver$_SOCON2$0$0 == 0x009a
                    009A    330 __SOCON2	=	0x009a
                    009B    331 Fwireless_tilt_mouse_receiver$_SOCON3$0$0 == 0x009b
                    009B    332 __SOCON3	=	0x009b
                    009C    333 Fwireless_tilt_mouse_receiver$_SOCON4$0$0 == 0x009c
                    009C    334 __SOCON4	=	0x009c
                    009D    335 Fwireless_tilt_mouse_receiver$_SOCON5$0$0 == 0x009d
                    009D    336 __SOCON5	=	0x009d
                    009E    337 Fwireless_tilt_mouse_receiver$_SOCON6$0$0 == 0x009e
                    009E    338 __SOCON6	=	0x009e
                    009F    339 Fwireless_tilt_mouse_receiver$_SOCON7$0$0 == 0x009f
                    009F    340 __SOCON7	=	0x009f
                    00A0    341 Fwireless_tilt_mouse_receiver$P2_0$0$0 == 0x00a0
                    00A0    342 _P2_0	=	0x00a0
                    00A1    343 Fwireless_tilt_mouse_receiver$P2_1$0$0 == 0x00a1
                    00A1    344 _P2_1	=	0x00a1
                    00A2    345 Fwireless_tilt_mouse_receiver$P2_2$0$0 == 0x00a2
                    00A2    346 _P2_2	=	0x00a2
                    00A3    347 Fwireless_tilt_mouse_receiver$P2_3$0$0 == 0x00a3
                    00A3    348 _P2_3	=	0x00a3
                    00A4    349 Fwireless_tilt_mouse_receiver$P2_4$0$0 == 0x00a4
                    00A4    350 _P2_4	=	0x00a4
                    00A5    351 Fwireless_tilt_mouse_receiver$P2_5$0$0 == 0x00a5
                    00A5    352 _P2_5	=	0x00a5
                    00A6    353 Fwireless_tilt_mouse_receiver$P2_6$0$0 == 0x00a6
                    00A6    354 _P2_6	=	0x00a6
                    00A7    355 Fwireless_tilt_mouse_receiver$P2_7$0$0 == 0x00a7
                    00A7    356 _P2_7	=	0x00a7
                    00A8    357 Fwireless_tilt_mouse_receiver$RFTXRXIE$0$0 == 0x00a8
                    00A8    358 _RFTXRXIE	=	0x00a8
                    00A9    359 Fwireless_tilt_mouse_receiver$ADCIE$0$0 == 0x00a9
                    00A9    360 _ADCIE	=	0x00a9
                    00AA    361 Fwireless_tilt_mouse_receiver$URX0IE$0$0 == 0x00aa
                    00AA    362 _URX0IE	=	0x00aa
                    00AB    363 Fwireless_tilt_mouse_receiver$URX1IE$0$0 == 0x00ab
                    00AB    364 _URX1IE	=	0x00ab
                    00AC    365 Fwireless_tilt_mouse_receiver$ENCIE$0$0 == 0x00ac
                    00AC    366 _ENCIE	=	0x00ac
                    00AD    367 Fwireless_tilt_mouse_receiver$STIE$0$0 == 0x00ad
                    00AD    368 _STIE	=	0x00ad
                    00AE    369 Fwireless_tilt_mouse_receiver$_IEN06$0$0 == 0x00ae
                    00AE    370 __IEN06	=	0x00ae
                    00AF    371 Fwireless_tilt_mouse_receiver$EA$0$0 == 0x00af
                    00AF    372 _EA	=	0x00af
                    00B8    373 Fwireless_tilt_mouse_receiver$DMAIE$0$0 == 0x00b8
                    00B8    374 _DMAIE	=	0x00b8
                    00B9    375 Fwireless_tilt_mouse_receiver$T1IE$0$0 == 0x00b9
                    00B9    376 _T1IE	=	0x00b9
                    00BA    377 Fwireless_tilt_mouse_receiver$T2IE$0$0 == 0x00ba
                    00BA    378 _T2IE	=	0x00ba
                    00BB    379 Fwireless_tilt_mouse_receiver$T3IE$0$0 == 0x00bb
                    00BB    380 _T3IE	=	0x00bb
                    00BC    381 Fwireless_tilt_mouse_receiver$T4IE$0$0 == 0x00bc
                    00BC    382 _T4IE	=	0x00bc
                    00BD    383 Fwireless_tilt_mouse_receiver$P0IE$0$0 == 0x00bd
                    00BD    384 _P0IE	=	0x00bd
                    00BE    385 Fwireless_tilt_mouse_receiver$_IEN16$0$0 == 0x00be
                    00BE    386 __IEN16	=	0x00be
                    00BF    387 Fwireless_tilt_mouse_receiver$_IEN17$0$0 == 0x00bf
                    00BF    388 __IEN17	=	0x00bf
                    00C0    389 Fwireless_tilt_mouse_receiver$DMAIF$0$0 == 0x00c0
                    00C0    390 _DMAIF	=	0x00c0
                    00C1    391 Fwireless_tilt_mouse_receiver$T1IF$0$0 == 0x00c1
                    00C1    392 _T1IF	=	0x00c1
                    00C2    393 Fwireless_tilt_mouse_receiver$T2IF$0$0 == 0x00c2
                    00C2    394 _T2IF	=	0x00c2
                    00C3    395 Fwireless_tilt_mouse_receiver$T3IF$0$0 == 0x00c3
                    00C3    396 _T3IF	=	0x00c3
                    00C4    397 Fwireless_tilt_mouse_receiver$T4IF$0$0 == 0x00c4
                    00C4    398 _T4IF	=	0x00c4
                    00C5    399 Fwireless_tilt_mouse_receiver$P0IF$0$0 == 0x00c5
                    00C5    400 _P0IF	=	0x00c5
                    00C6    401 Fwireless_tilt_mouse_receiver$_IRCON6$0$0 == 0x00c6
                    00C6    402 __IRCON6	=	0x00c6
                    00C7    403 Fwireless_tilt_mouse_receiver$STIF$0$0 == 0x00c7
                    00C7    404 _STIF	=	0x00c7
                    00D0    405 Fwireless_tilt_mouse_receiver$P$0$0 == 0x00d0
                    00D0    406 _P	=	0x00d0
                    00D1    407 Fwireless_tilt_mouse_receiver$F1$0$0 == 0x00d1
                    00D1    408 _F1	=	0x00d1
                    00D2    409 Fwireless_tilt_mouse_receiver$OV$0$0 == 0x00d2
                    00D2    410 _OV	=	0x00d2
                    00D3    411 Fwireless_tilt_mouse_receiver$RS0$0$0 == 0x00d3
                    00D3    412 _RS0	=	0x00d3
                    00D4    413 Fwireless_tilt_mouse_receiver$RS1$0$0 == 0x00d4
                    00D4    414 _RS1	=	0x00d4
                    00D5    415 Fwireless_tilt_mouse_receiver$F0$0$0 == 0x00d5
                    00D5    416 _F0	=	0x00d5
                    00D6    417 Fwireless_tilt_mouse_receiver$AC$0$0 == 0x00d6
                    00D6    418 _AC	=	0x00d6
                    00D7    419 Fwireless_tilt_mouse_receiver$CY$0$0 == 0x00d7
                    00D7    420 _CY	=	0x00d7
                    00D8    421 Fwireless_tilt_mouse_receiver$T3OVFIF$0$0 == 0x00d8
                    00D8    422 _T3OVFIF	=	0x00d8
                    00D9    423 Fwireless_tilt_mouse_receiver$T3CH0IF$0$0 == 0x00d9
                    00D9    424 _T3CH0IF	=	0x00d9
                    00DA    425 Fwireless_tilt_mouse_receiver$T3CH1IF$0$0 == 0x00da
                    00DA    426 _T3CH1IF	=	0x00da
                    00DB    427 Fwireless_tilt_mouse_receiver$T4OVFIF$0$0 == 0x00db
                    00DB    428 _T4OVFIF	=	0x00db
                    00DC    429 Fwireless_tilt_mouse_receiver$T4CH0IF$0$0 == 0x00dc
                    00DC    430 _T4CH0IF	=	0x00dc
                    00DD    431 Fwireless_tilt_mouse_receiver$T4CH1IF$0$0 == 0x00dd
                    00DD    432 _T4CH1IF	=	0x00dd
                    00DE    433 Fwireless_tilt_mouse_receiver$OVFIM$0$0 == 0x00de
                    00DE    434 _OVFIM	=	0x00de
                    00DF    435 Fwireless_tilt_mouse_receiver$_TIMIF7$0$0 == 0x00df
                    00DF    436 __TIMIF7	=	0x00df
                    00E0    437 Fwireless_tilt_mouse_receiver$ACC_0$0$0 == 0x00e0
                    00E0    438 _ACC_0	=	0x00e0
                    00E1    439 Fwireless_tilt_mouse_receiver$ACC_1$0$0 == 0x00e1
                    00E1    440 _ACC_1	=	0x00e1
                    00E2    441 Fwireless_tilt_mouse_receiver$ACC_2$0$0 == 0x00e2
                    00E2    442 _ACC_2	=	0x00e2
                    00E3    443 Fwireless_tilt_mouse_receiver$ACC_3$0$0 == 0x00e3
                    00E3    444 _ACC_3	=	0x00e3
                    00E4    445 Fwireless_tilt_mouse_receiver$ACC_4$0$0 == 0x00e4
                    00E4    446 _ACC_4	=	0x00e4
                    00E5    447 Fwireless_tilt_mouse_receiver$ACC_5$0$0 == 0x00e5
                    00E5    448 _ACC_5	=	0x00e5
                    00E6    449 Fwireless_tilt_mouse_receiver$ACC_6$0$0 == 0x00e6
                    00E6    450 _ACC_6	=	0x00e6
                    00E7    451 Fwireless_tilt_mouse_receiver$ACC_7$0$0 == 0x00e7
                    00E7    452 _ACC_7	=	0x00e7
                    00E8    453 Fwireless_tilt_mouse_receiver$P2IF$0$0 == 0x00e8
                    00E8    454 _P2IF	=	0x00e8
                    00E9    455 Fwireless_tilt_mouse_receiver$UTX0IF$0$0 == 0x00e9
                    00E9    456 _UTX0IF	=	0x00e9
                    00EA    457 Fwireless_tilt_mouse_receiver$UTX1IF$0$0 == 0x00ea
                    00EA    458 _UTX1IF	=	0x00ea
                    00EB    459 Fwireless_tilt_mouse_receiver$P1IF$0$0 == 0x00eb
                    00EB    460 _P1IF	=	0x00eb
                    00EC    461 Fwireless_tilt_mouse_receiver$WDTIF$0$0 == 0x00ec
                    00EC    462 _WDTIF	=	0x00ec
                    00ED    463 Fwireless_tilt_mouse_receiver$_IRCON25$0$0 == 0x00ed
                    00ED    464 __IRCON25	=	0x00ed
                    00EE    465 Fwireless_tilt_mouse_receiver$_IRCON26$0$0 == 0x00ee
                    00EE    466 __IRCON26	=	0x00ee
                    00EF    467 Fwireless_tilt_mouse_receiver$_IRCON27$0$0 == 0x00ef
                    00EF    468 __IRCON27	=	0x00ef
                    00F0    469 Fwireless_tilt_mouse_receiver$B_0$0$0 == 0x00f0
                    00F0    470 _B_0	=	0x00f0
                    00F1    471 Fwireless_tilt_mouse_receiver$B_1$0$0 == 0x00f1
                    00F1    472 _B_1	=	0x00f1
                    00F2    473 Fwireless_tilt_mouse_receiver$B_2$0$0 == 0x00f2
                    00F2    474 _B_2	=	0x00f2
                    00F3    475 Fwireless_tilt_mouse_receiver$B_3$0$0 == 0x00f3
                    00F3    476 _B_3	=	0x00f3
                    00F4    477 Fwireless_tilt_mouse_receiver$B_4$0$0 == 0x00f4
                    00F4    478 _B_4	=	0x00f4
                    00F5    479 Fwireless_tilt_mouse_receiver$B_5$0$0 == 0x00f5
                    00F5    480 _B_5	=	0x00f5
                    00F6    481 Fwireless_tilt_mouse_receiver$B_6$0$0 == 0x00f6
                    00F6    482 _B_6	=	0x00f6
                    00F7    483 Fwireless_tilt_mouse_receiver$B_7$0$0 == 0x00f7
                    00F7    484 _B_7	=	0x00f7
                    00F8    485 Fwireless_tilt_mouse_receiver$U1ACTIVE$0$0 == 0x00f8
                    00F8    486 _U1ACTIVE	=	0x00f8
                    00F9    487 Fwireless_tilt_mouse_receiver$U1TX_BYTE$0$0 == 0x00f9
                    00F9    488 _U1TX_BYTE	=	0x00f9
                    00FA    489 Fwireless_tilt_mouse_receiver$U1RX_BYTE$0$0 == 0x00fa
                    00FA    490 _U1RX_BYTE	=	0x00fa
                    00FB    491 Fwireless_tilt_mouse_receiver$U1ERR$0$0 == 0x00fb
                    00FB    492 _U1ERR	=	0x00fb
                    00FC    493 Fwireless_tilt_mouse_receiver$U1FE$0$0 == 0x00fc
                    00FC    494 _U1FE	=	0x00fc
                    00FD    495 Fwireless_tilt_mouse_receiver$U1SLAVE$0$0 == 0x00fd
                    00FD    496 _U1SLAVE	=	0x00fd
                    00FE    497 Fwireless_tilt_mouse_receiver$U1RE$0$0 == 0x00fe
                    00FE    498 _U1RE	=	0x00fe
                    00FF    499 Fwireless_tilt_mouse_receiver$U1MODE$0$0 == 0x00ff
                    00FF    500 _U1MODE	=	0x00ff
                            501 ;--------------------------------------------------------
                            502 ; overlayable register banks
                            503 ;--------------------------------------------------------
                            504 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     505 	.ds 8
                            506 ;--------------------------------------------------------
                            507 ; internal ram data
                            508 ;--------------------------------------------------------
                            509 	.area DSEG    (DATA)
                            510 ;--------------------------------------------------------
                            511 ; overlayable items in internal ram 
                            512 ;--------------------------------------------------------
                            513 	.area OSEG    (OVR,DATA)
                            514 ;--------------------------------------------------------
                            515 ; Stack segment in internal ram 
                            516 ;--------------------------------------------------------
                            517 	.area	SSEG	(DATA)
   0023                     518 __start__stack:
   0023                     519 	.ds	1
                            520 
                            521 ;--------------------------------------------------------
                            522 ; indirectly addressable internal ram data
                            523 ;--------------------------------------------------------
                            524 	.area ISEG    (DATA)
                            525 ;--------------------------------------------------------
                            526 ; absolute internal ram data
                            527 ;--------------------------------------------------------
                            528 	.area IABS    (ABS,DATA)
                            529 	.area IABS    (ABS,DATA)
                            530 ;--------------------------------------------------------
                            531 ; bit data
                            532 ;--------------------------------------------------------
                            533 	.area BSEG    (BIT)
                            534 ;--------------------------------------------------------
                            535 ; paged external ram data
                            536 ;--------------------------------------------------------
                            537 	.area PSEG    (PAG,XDATA)
                            538 ;--------------------------------------------------------
                            539 ; external ram data
                            540 ;--------------------------------------------------------
                            541 	.area XSEG    (XDATA)
                    DF00    542 Fwireless_tilt_mouse_receiver$SYNC1$0$0 == 0xdf00
                    DF00    543 _SYNC1	=	0xdf00
                    DF01    544 Fwireless_tilt_mouse_receiver$SYNC0$0$0 == 0xdf01
                    DF01    545 _SYNC0	=	0xdf01
                    DF02    546 Fwireless_tilt_mouse_receiver$PKTLEN$0$0 == 0xdf02
                    DF02    547 _PKTLEN	=	0xdf02
                    DF03    548 Fwireless_tilt_mouse_receiver$PKTCTRL1$0$0 == 0xdf03
                    DF03    549 _PKTCTRL1	=	0xdf03
                    DF04    550 Fwireless_tilt_mouse_receiver$PKTCTRL0$0$0 == 0xdf04
                    DF04    551 _PKTCTRL0	=	0xdf04
                    DF05    552 Fwireless_tilt_mouse_receiver$ADDR$0$0 == 0xdf05
                    DF05    553 _ADDR	=	0xdf05
                    DF06    554 Fwireless_tilt_mouse_receiver$CHANNR$0$0 == 0xdf06
                    DF06    555 _CHANNR	=	0xdf06
                    DF07    556 Fwireless_tilt_mouse_receiver$FSCTRL1$0$0 == 0xdf07
                    DF07    557 _FSCTRL1	=	0xdf07
                    DF08    558 Fwireless_tilt_mouse_receiver$FSCTRL0$0$0 == 0xdf08
                    DF08    559 _FSCTRL0	=	0xdf08
                    DF09    560 Fwireless_tilt_mouse_receiver$FREQ2$0$0 == 0xdf09
                    DF09    561 _FREQ2	=	0xdf09
                    DF0A    562 Fwireless_tilt_mouse_receiver$FREQ1$0$0 == 0xdf0a
                    DF0A    563 _FREQ1	=	0xdf0a
                    DF0B    564 Fwireless_tilt_mouse_receiver$FREQ0$0$0 == 0xdf0b
                    DF0B    565 _FREQ0	=	0xdf0b
                    DF0C    566 Fwireless_tilt_mouse_receiver$MDMCFG4$0$0 == 0xdf0c
                    DF0C    567 _MDMCFG4	=	0xdf0c
                    DF0D    568 Fwireless_tilt_mouse_receiver$MDMCFG3$0$0 == 0xdf0d
                    DF0D    569 _MDMCFG3	=	0xdf0d
                    DF0E    570 Fwireless_tilt_mouse_receiver$MDMCFG2$0$0 == 0xdf0e
                    DF0E    571 _MDMCFG2	=	0xdf0e
                    DF0F    572 Fwireless_tilt_mouse_receiver$MDMCFG1$0$0 == 0xdf0f
                    DF0F    573 _MDMCFG1	=	0xdf0f
                    DF10    574 Fwireless_tilt_mouse_receiver$MDMCFG0$0$0 == 0xdf10
                    DF10    575 _MDMCFG0	=	0xdf10
                    DF11    576 Fwireless_tilt_mouse_receiver$DEVIATN$0$0 == 0xdf11
                    DF11    577 _DEVIATN	=	0xdf11
                    DF12    578 Fwireless_tilt_mouse_receiver$MCSM2$0$0 == 0xdf12
                    DF12    579 _MCSM2	=	0xdf12
                    DF13    580 Fwireless_tilt_mouse_receiver$MCSM1$0$0 == 0xdf13
                    DF13    581 _MCSM1	=	0xdf13
                    DF14    582 Fwireless_tilt_mouse_receiver$MCSM0$0$0 == 0xdf14
                    DF14    583 _MCSM0	=	0xdf14
                    DF15    584 Fwireless_tilt_mouse_receiver$FOCCFG$0$0 == 0xdf15
                    DF15    585 _FOCCFG	=	0xdf15
                    DF16    586 Fwireless_tilt_mouse_receiver$BSCFG$0$0 == 0xdf16
                    DF16    587 _BSCFG	=	0xdf16
                    DF17    588 Fwireless_tilt_mouse_receiver$AGCCTRL2$0$0 == 0xdf17
                    DF17    589 _AGCCTRL2	=	0xdf17
                    DF18    590 Fwireless_tilt_mouse_receiver$AGCCTRL1$0$0 == 0xdf18
                    DF18    591 _AGCCTRL1	=	0xdf18
                    DF19    592 Fwireless_tilt_mouse_receiver$AGCCTRL0$0$0 == 0xdf19
                    DF19    593 _AGCCTRL0	=	0xdf19
                    DF1A    594 Fwireless_tilt_mouse_receiver$FREND1$0$0 == 0xdf1a
                    DF1A    595 _FREND1	=	0xdf1a
                    DF1B    596 Fwireless_tilt_mouse_receiver$FREND0$0$0 == 0xdf1b
                    DF1B    597 _FREND0	=	0xdf1b
                    DF1C    598 Fwireless_tilt_mouse_receiver$FSCAL3$0$0 == 0xdf1c
                    DF1C    599 _FSCAL3	=	0xdf1c
                    DF1D    600 Fwireless_tilt_mouse_receiver$FSCAL2$0$0 == 0xdf1d
                    DF1D    601 _FSCAL2	=	0xdf1d
                    DF1E    602 Fwireless_tilt_mouse_receiver$FSCAL1$0$0 == 0xdf1e
                    DF1E    603 _FSCAL1	=	0xdf1e
                    DF1F    604 Fwireless_tilt_mouse_receiver$FSCAL0$0$0 == 0xdf1f
                    DF1F    605 _FSCAL0	=	0xdf1f
                    DF23    606 Fwireless_tilt_mouse_receiver$TEST2$0$0 == 0xdf23
                    DF23    607 _TEST2	=	0xdf23
                    DF24    608 Fwireless_tilt_mouse_receiver$TEST1$0$0 == 0xdf24
                    DF24    609 _TEST1	=	0xdf24
                    DF25    610 Fwireless_tilt_mouse_receiver$TEST0$0$0 == 0xdf25
                    DF25    611 _TEST0	=	0xdf25
                    DF2E    612 Fwireless_tilt_mouse_receiver$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    613 _PA_TABLE0	=	0xdf2e
                    DF2F    614 Fwireless_tilt_mouse_receiver$IOCFG2$0$0 == 0xdf2f
                    DF2F    615 _IOCFG2	=	0xdf2f
                    DF30    616 Fwireless_tilt_mouse_receiver$IOCFG1$0$0 == 0xdf30
                    DF30    617 _IOCFG1	=	0xdf30
                    DF31    618 Fwireless_tilt_mouse_receiver$IOCFG0$0$0 == 0xdf31
                    DF31    619 _IOCFG0	=	0xdf31
                    DF36    620 Fwireless_tilt_mouse_receiver$PARTNUM$0$0 == 0xdf36
                    DF36    621 _PARTNUM	=	0xdf36
                    DF37    622 Fwireless_tilt_mouse_receiver$VERSION$0$0 == 0xdf37
                    DF37    623 _VERSION	=	0xdf37
                    DF38    624 Fwireless_tilt_mouse_receiver$FREQEST$0$0 == 0xdf38
                    DF38    625 _FREQEST	=	0xdf38
                    DF39    626 Fwireless_tilt_mouse_receiver$LQI$0$0 == 0xdf39
                    DF39    627 _LQI	=	0xdf39
                    DF3A    628 Fwireless_tilt_mouse_receiver$RSSI$0$0 == 0xdf3a
                    DF3A    629 _RSSI	=	0xdf3a
                    DF3B    630 Fwireless_tilt_mouse_receiver$MARCSTATE$0$0 == 0xdf3b
                    DF3B    631 _MARCSTATE	=	0xdf3b
                    DF3C    632 Fwireless_tilt_mouse_receiver$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    633 _PKTSTATUS	=	0xdf3c
                    DF3D    634 Fwireless_tilt_mouse_receiver$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    635 _VCO_VC_DAC	=	0xdf3d
                    DF40    636 Fwireless_tilt_mouse_receiver$I2SCFG0$0$0 == 0xdf40
                    DF40    637 _I2SCFG0	=	0xdf40
                    DF41    638 Fwireless_tilt_mouse_receiver$I2SCFG1$0$0 == 0xdf41
                    DF41    639 _I2SCFG1	=	0xdf41
                    DF42    640 Fwireless_tilt_mouse_receiver$I2SDATL$0$0 == 0xdf42
                    DF42    641 _I2SDATL	=	0xdf42
                    DF43    642 Fwireless_tilt_mouse_receiver$I2SDATH$0$0 == 0xdf43
                    DF43    643 _I2SDATH	=	0xdf43
                    DF44    644 Fwireless_tilt_mouse_receiver$I2SWCNT$0$0 == 0xdf44
                    DF44    645 _I2SWCNT	=	0xdf44
                    DF45    646 Fwireless_tilt_mouse_receiver$I2SSTAT$0$0 == 0xdf45
                    DF45    647 _I2SSTAT	=	0xdf45
                    DF46    648 Fwireless_tilt_mouse_receiver$I2SCLKF0$0$0 == 0xdf46
                    DF46    649 _I2SCLKF0	=	0xdf46
                    DF47    650 Fwireless_tilt_mouse_receiver$I2SCLKF1$0$0 == 0xdf47
                    DF47    651 _I2SCLKF1	=	0xdf47
                    DF48    652 Fwireless_tilt_mouse_receiver$I2SCLKF2$0$0 == 0xdf48
                    DF48    653 _I2SCLKF2	=	0xdf48
                    DE00    654 Fwireless_tilt_mouse_receiver$USBADDR$0$0 == 0xde00
                    DE00    655 _USBADDR	=	0xde00
                    DE01    656 Fwireless_tilt_mouse_receiver$USBPOW$0$0 == 0xde01
                    DE01    657 _USBPOW	=	0xde01
                    DE02    658 Fwireless_tilt_mouse_receiver$USBIIF$0$0 == 0xde02
                    DE02    659 _USBIIF	=	0xde02
                    DE04    660 Fwireless_tilt_mouse_receiver$USBOIF$0$0 == 0xde04
                    DE04    661 _USBOIF	=	0xde04
                    DE06    662 Fwireless_tilt_mouse_receiver$USBCIF$0$0 == 0xde06
                    DE06    663 _USBCIF	=	0xde06
                    DE07    664 Fwireless_tilt_mouse_receiver$USBIIE$0$0 == 0xde07
                    DE07    665 _USBIIE	=	0xde07
                    DE09    666 Fwireless_tilt_mouse_receiver$USBOIE$0$0 == 0xde09
                    DE09    667 _USBOIE	=	0xde09
                    DE0B    668 Fwireless_tilt_mouse_receiver$USBCIE$0$0 == 0xde0b
                    DE0B    669 _USBCIE	=	0xde0b
                    DE0C    670 Fwireless_tilt_mouse_receiver$USBFRML$0$0 == 0xde0c
                    DE0C    671 _USBFRML	=	0xde0c
                    DE0D    672 Fwireless_tilt_mouse_receiver$USBFRMH$0$0 == 0xde0d
                    DE0D    673 _USBFRMH	=	0xde0d
                    DE0E    674 Fwireless_tilt_mouse_receiver$USBINDEX$0$0 == 0xde0e
                    DE0E    675 _USBINDEX	=	0xde0e
                    DE10    676 Fwireless_tilt_mouse_receiver$USBMAXI$0$0 == 0xde10
                    DE10    677 _USBMAXI	=	0xde10
                    DE11    678 Fwireless_tilt_mouse_receiver$USBCSIL$0$0 == 0xde11
                    DE11    679 _USBCSIL	=	0xde11
                    DE12    680 Fwireless_tilt_mouse_receiver$USBCSIH$0$0 == 0xde12
                    DE12    681 _USBCSIH	=	0xde12
                    DE13    682 Fwireless_tilt_mouse_receiver$USBMAXO$0$0 == 0xde13
                    DE13    683 _USBMAXO	=	0xde13
                    DE14    684 Fwireless_tilt_mouse_receiver$USBCSOL$0$0 == 0xde14
                    DE14    685 _USBCSOL	=	0xde14
                    DE15    686 Fwireless_tilt_mouse_receiver$USBCSOH$0$0 == 0xde15
                    DE15    687 _USBCSOH	=	0xde15
                    DE16    688 Fwireless_tilt_mouse_receiver$USBCNTL$0$0 == 0xde16
                    DE16    689 _USBCNTL	=	0xde16
                    DE17    690 Fwireless_tilt_mouse_receiver$USBCNTH$0$0 == 0xde17
                    DE17    691 _USBCNTH	=	0xde17
                    DE20    692 Fwireless_tilt_mouse_receiver$USBF0$0$0 == 0xde20
                    DE20    693 _USBF0	=	0xde20
                    DE22    694 Fwireless_tilt_mouse_receiver$USBF1$0$0 == 0xde22
                    DE22    695 _USBF1	=	0xde22
                    DE24    696 Fwireless_tilt_mouse_receiver$USBF2$0$0 == 0xde24
                    DE24    697 _USBF2	=	0xde24
                    DE26    698 Fwireless_tilt_mouse_receiver$USBF3$0$0 == 0xde26
                    DE26    699 _USBF3	=	0xde26
                    DE28    700 Fwireless_tilt_mouse_receiver$USBF4$0$0 == 0xde28
                    DE28    701 _USBF4	=	0xde28
                    DE2A    702 Fwireless_tilt_mouse_receiver$USBF5$0$0 == 0xde2a
                    DE2A    703 _USBF5	=	0xde2a
                            704 ;--------------------------------------------------------
                            705 ; absolute external ram data
                            706 ;--------------------------------------------------------
                            707 	.area XABS    (ABS,XDATA)
                            708 ;--------------------------------------------------------
                            709 ; external initialized ram data
                            710 ;--------------------------------------------------------
                            711 	.area XISEG   (XDATA)
                            712 	.area HOME    (CODE)
                            713 	.area GSINIT0 (CODE)
                            714 	.area GSINIT1 (CODE)
                            715 	.area GSINIT2 (CODE)
                            716 	.area GSINIT3 (CODE)
                            717 	.area GSINIT4 (CODE)
                            718 	.area GSINIT5 (CODE)
                            719 	.area GSINIT  (CODE)
                            720 	.area GSFINAL (CODE)
                            721 	.area CSEG    (CODE)
                            722 ;--------------------------------------------------------
                            723 ; interrupt vector 
                            724 ;--------------------------------------------------------
                            725 	.area HOME    (CODE)
   0400                     726 __interrupt_vect:
   0400 02 04 8B            727 	ljmp	__sdcc_gsinit_startup
   0403 32                  728 	reti
   0404                     729 	.ds	7
   040B 32                  730 	reti
   040C                     731 	.ds	7
   0413 32                  732 	reti
   0414                     733 	.ds	7
   041B 32                  734 	reti
   041C                     735 	.ds	7
   0423 32                  736 	reti
   0424                     737 	.ds	7
   042B 32                  738 	reti
   042C                     739 	.ds	7
   0433 32                  740 	reti
   0434                     741 	.ds	7
   043B 32                  742 	reti
   043C                     743 	.ds	7
   0443 32                  744 	reti
   0444                     745 	.ds	7
   044B 32                  746 	reti
   044C                     747 	.ds	7
   0453 32                  748 	reti
   0454                     749 	.ds	7
   045B 32                  750 	reti
   045C                     751 	.ds	7
   0463 02 13 FB            752 	ljmp	_ISR_T4
   0466                     753 	.ds	5
   046B 32                  754 	reti
   046C                     755 	.ds	7
   0473 32                  756 	reti
   0474                     757 	.ds	7
   047B 32                  758 	reti
   047C                     759 	.ds	7
   0483 02 05 6C            760 	ljmp	_ISR_RF
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
   0517 02 04 86            775 	ljmp	__sdcc_program_startup
                            776 ;--------------------------------------------------------
                            777 ; Home
                            778 ;--------------------------------------------------------
                            779 	.area HOME    (CODE)
                            780 	.area HOME    (CODE)
   0486                     781 __sdcc_program_startup:
   0486 12 05 54            782 	lcall	_main
                            783 ;	return from main will lock up
   0489 80 FE               784 	sjmp .
                            785 ;--------------------------------------------------------
                            786 ; code
                            787 ;--------------------------------------------------------
                            788 	.area CSEG    (CODE)
                            789 ;------------------------------------------------------------
                            790 ;Allocation info for local variables in function 'updateLeds'
                            791 ;------------------------------------------------------------
                    0000    792 	G$updateLeds$0$0 ==.
                    0000    793 	C$wireless_tilt_mouse_receiver.c$14$0$0 ==.
                            794 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:14: void updateLeds()
                            795 ;	-----------------------------------------
                            796 ;	 function updateLeds
                            797 ;	-----------------------------------------
   051A                     798 _updateLeds:
                    0007    799 	ar7 = 0x07
                    0006    800 	ar6 = 0x06
                    0005    801 	ar5 = 0x05
                    0004    802 	ar4 = 0x04
                    0003    803 	ar3 = 0x03
                    0002    804 	ar2 = 0x02
                    0001    805 	ar1 = 0x01
                    0000    806 	ar0 = 0x00
                    0000    807 	C$wireless_tilt_mouse_receiver.c$16$1$1 ==.
                            808 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:16: usbShowStatusWithGreenLed();
   051A 12 15 58            809 	lcall	_usbShowStatusWithGreenLed
                    0003    810 	C$wireless_tilt_mouse_receiver.c$17$1$1 ==.
                    0003    811 	XG$updateLeds$0$0 ==.
   051D 22                  812 	ret
                            813 ;------------------------------------------------------------
                            814 ;Allocation info for local variables in function 'rxMouseState'
                            815 ;------------------------------------------------------------
                    0004    816 	G$rxMouseState$0$0 ==.
                    0004    817 	C$wireless_tilt_mouse_receiver.c$19$1$1 ==.
                            818 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:19: void rxMouseState(void)
                            819 ;	-----------------------------------------
                            820 ;	 function rxMouseState
                            821 ;	-----------------------------------------
   051E                     822 _rxMouseState:
                    0004    823 	C$wireless_tilt_mouse_receiver.c$23$1$1 ==.
                            824 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:23: if (rxBuf = radioQueueRxCurrentPacket())
   051E 12 07 C6            825 	lcall	_radioQueueRxCurrentPacket
   0521 AE 82               826 	mov	r6,dpl
   0523 AF 83               827 	mov	r7,dph
   0525 8E 04               828 	mov	ar4,r6
   0527 8F 05               829 	mov	ar5,r7
   0529 EE                  830 	mov	a,r6
   052A 4F                  831 	orl	a,r7
   052B 60 26               832 	jz	00103$
                    0013    833 	C$wireless_tilt_mouse_receiver.c$25$2$2 ==.
                            834 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:25: usbHidMouseInput.x = rxBuf[1];
   052D 8C 82               835 	mov	dpl,r4
   052F 8D 83               836 	mov	dph,r5
   0531 A3                  837 	inc	dptr
   0532 E0                  838 	movx	a,@dptr
   0533 90 F1 D2            839 	mov	dptr,#(_usbHidMouseInput + 0x0001)
   0536 F0                  840 	movx	@dptr,a
                    001D    841 	C$wireless_tilt_mouse_receiver.c$26$2$2 ==.
                            842 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:26: usbHidMouseInput.y =  rxBuf[2];
   0537 8C 82               843 	mov	dpl,r4
   0539 8D 83               844 	mov	dph,r5
   053B A3                  845 	inc	dptr
   053C A3                  846 	inc	dptr
   053D E0                  847 	movx	a,@dptr
   053E 90 F1 D3            848 	mov	dptr,#(_usbHidMouseInput + 0x0002)
   0541 F0                  849 	movx	@dptr,a
                    0028    850 	C$wireless_tilt_mouse_receiver.c$27$2$2 ==.
                            851 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:27: usbHidMouseInput.buttons = rxBuf[3];
   0542 8C 82               852 	mov	dpl,r4
   0544 8D 83               853 	mov	dph,r5
   0546 A3                  854 	inc	dptr
   0547 A3                  855 	inc	dptr
   0548 A3                  856 	inc	dptr
   0549 E0                  857 	movx	a,@dptr
   054A 90 F1 D1            858 	mov	dptr,#_usbHidMouseInput
   054D F0                  859 	movx	@dptr,a
                    0034    860 	C$wireless_tilt_mouse_receiver.c$28$2$2 ==.
                            861 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:28: usbHidMouseInputUpdated = 1;
   054E D2 05               862 	setb	_usbHidMouseInputUpdated
                    0036    863 	C$wireless_tilt_mouse_receiver.c$29$2$2 ==.
                            864 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:29: radioQueueRxDoneWithPacket();
   0550 12 07 E1            865 	lcall	_radioQueueRxDoneWithPacket
   0553                     866 00103$:
                    0039    867 	C$wireless_tilt_mouse_receiver.c$31$2$1 ==.
                    0039    868 	XG$rxMouseState$0$0 ==.
   0553 22                  869 	ret
                            870 ;------------------------------------------------------------
                            871 ;Allocation info for local variables in function 'main'
                            872 ;------------------------------------------------------------
                    003A    873 	G$main$0$0 ==.
                    003A    874 	C$wireless_tilt_mouse_receiver.c$33$2$1 ==.
                            875 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:33: void main()
                            876 ;	-----------------------------------------
                            877 ;	 function main
                            878 ;	-----------------------------------------
   0554                     879 _main:
                    003A    880 	C$wireless_tilt_mouse_receiver.c$35$1$1 ==.
                            881 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:35: systemInit();
   0554 12 13 20            882 	lcall	_systemInit
                    003D    883 	C$wireless_tilt_mouse_receiver.c$36$1$1 ==.
                            884 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:36: usbInit();
   0557 12 0C BA            885 	lcall	_usbInit
                    0040    886 	C$wireless_tilt_mouse_receiver.c$38$1$1 ==.
                            887 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:38: radioQueueInit();
   055A 12 07 54            888 	lcall	_radioQueueInit
                    0043    889 	C$wireless_tilt_mouse_receiver.c$40$1$1 ==.
                            890 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:40: while(1)
   055D                     891 00102$:
                    0043    892 	C$wireless_tilt_mouse_receiver.c$42$2$2 ==.
                            893 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:42: updateLeds();
   055D 12 05 1A            894 	lcall	_updateLeds
                    0046    895 	C$wireless_tilt_mouse_receiver.c$43$2$2 ==.
                            896 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:43: boardService();
   0560 12 13 2D            897 	lcall	_boardService
                    0049    898 	C$wireless_tilt_mouse_receiver.c$44$2$2 ==.
                            899 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:44: usbHidService();
   0563 12 0B B6            900 	lcall	_usbHidService
                    004C    901 	C$wireless_tilt_mouse_receiver.c$46$2$2 ==.
                            902 ;	apps/wireless_tilt_mouse_receiver/wireless_tilt_mouse_receiver.c:46: rxMouseState();
   0566 12 05 1E            903 	lcall	_rxMouseState
   0569 80 F2               904 	sjmp	00102$
                    0051    905 	C$wireless_tilt_mouse_receiver.c$48$1$1 ==.
                    0051    906 	XG$main$0$0 ==.
   056B 22                  907 	ret
                            908 	.area CSEG    (CODE)
                            909 	.area CONST   (CODE)
                            910 	.area XINIT   (CODE)
                            911 	.area CABS    (ABS,CODE)
