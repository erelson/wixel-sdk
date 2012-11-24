                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:04 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_hid
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _keyboardService_greeting_1_1
                             13 	.globl _param_move_joystick
                             14 	.globl _param_move_mouse_wheel
                             15 	.globl _param_move_cursor
                             16 	.globl _main
                             17 	.globl _keyboardService
                             18 	.globl _buttonGetSingleDebouncedPress
                             19 	.globl _sendKeyCode
                             20 	.globl _joystickService
                             21 	.globl _updateMouseState
                             22 	.globl _updateLeds
                             23 	.globl _usbHidKeyCodeFromAsciiChar
                             24 	.globl _usbHidService
                             25 	.globl _usbShowStatusWithGreenLed
                             26 	.globl _usbInit
                             27 	.globl _isPinHigh
                             28 	.globl _getMs
                             29 	.globl _boardService
                             30 	.globl _systemInit
                             31 	.globl _lastKeyCodeSent
                             32 ;--------------------------------------------------------
                             33 ; special function registers
                             34 ;--------------------------------------------------------
                             35 	.area RSEG    (ABS,DATA)
   0000                      36 	.org 0x0000
                    0080     37 Ftest_hid$P0$0$0 == 0x0080
                    0080     38 _P0	=	0x0080
                    0081     39 Ftest_hid$SP$0$0 == 0x0081
                    0081     40 _SP	=	0x0081
                    0082     41 Ftest_hid$DPL0$0$0 == 0x0082
                    0082     42 _DPL0	=	0x0082
                    0083     43 Ftest_hid$DPH0$0$0 == 0x0083
                    0083     44 _DPH0	=	0x0083
                    0084     45 Ftest_hid$DPL1$0$0 == 0x0084
                    0084     46 _DPL1	=	0x0084
                    0085     47 Ftest_hid$DPH1$0$0 == 0x0085
                    0085     48 _DPH1	=	0x0085
                    0086     49 Ftest_hid$U0CSR$0$0 == 0x0086
                    0086     50 _U0CSR	=	0x0086
                    0087     51 Ftest_hid$PCON$0$0 == 0x0087
                    0087     52 _PCON	=	0x0087
                    0088     53 Ftest_hid$TCON$0$0 == 0x0088
                    0088     54 _TCON	=	0x0088
                    0089     55 Ftest_hid$P0IFG$0$0 == 0x0089
                    0089     56 _P0IFG	=	0x0089
                    008A     57 Ftest_hid$P1IFG$0$0 == 0x008a
                    008A     58 _P1IFG	=	0x008a
                    008B     59 Ftest_hid$P2IFG$0$0 == 0x008b
                    008B     60 _P2IFG	=	0x008b
                    008C     61 Ftest_hid$PICTL$0$0 == 0x008c
                    008C     62 _PICTL	=	0x008c
                    008D     63 Ftest_hid$P1IEN$0$0 == 0x008d
                    008D     64 _P1IEN	=	0x008d
                    008F     65 Ftest_hid$P0INP$0$0 == 0x008f
                    008F     66 _P0INP	=	0x008f
                    0090     67 Ftest_hid$P1$0$0 == 0x0090
                    0090     68 _P1	=	0x0090
                    0091     69 Ftest_hid$RFIM$0$0 == 0x0091
                    0091     70 _RFIM	=	0x0091
                    0092     71 Ftest_hid$DPS$0$0 == 0x0092
                    0092     72 _DPS	=	0x0092
                    0093     73 Ftest_hid$MPAGE$0$0 == 0x0093
                    0093     74 _MPAGE	=	0x0093
                    0095     75 Ftest_hid$ENDIAN$0$0 == 0x0095
                    0095     76 _ENDIAN	=	0x0095
                    0098     77 Ftest_hid$S0CON$0$0 == 0x0098
                    0098     78 _S0CON	=	0x0098
                    009A     79 Ftest_hid$IEN2$0$0 == 0x009a
                    009A     80 _IEN2	=	0x009a
                    009B     81 Ftest_hid$S1CON$0$0 == 0x009b
                    009B     82 _S1CON	=	0x009b
                    009C     83 Ftest_hid$T2CT$0$0 == 0x009c
                    009C     84 _T2CT	=	0x009c
                    009D     85 Ftest_hid$T2PR$0$0 == 0x009d
                    009D     86 _T2PR	=	0x009d
                    009E     87 Ftest_hid$T2CTL$0$0 == 0x009e
                    009E     88 _T2CTL	=	0x009e
                    00A0     89 Ftest_hid$P2$0$0 == 0x00a0
                    00A0     90 _P2	=	0x00a0
                    00A1     91 Ftest_hid$WORIRQ$0$0 == 0x00a1
                    00A1     92 _WORIRQ	=	0x00a1
                    00A2     93 Ftest_hid$WORCTRL$0$0 == 0x00a2
                    00A2     94 _WORCTRL	=	0x00a2
                    00A3     95 Ftest_hid$WOREVT0$0$0 == 0x00a3
                    00A3     96 _WOREVT0	=	0x00a3
                    00A4     97 Ftest_hid$WOREVT1$0$0 == 0x00a4
                    00A4     98 _WOREVT1	=	0x00a4
                    00A5     99 Ftest_hid$WORTIME0$0$0 == 0x00a5
                    00A5    100 _WORTIME0	=	0x00a5
                    00A6    101 Ftest_hid$WORTIME1$0$0 == 0x00a6
                    00A6    102 _WORTIME1	=	0x00a6
                    00A8    103 Ftest_hid$IEN0$0$0 == 0x00a8
                    00A8    104 _IEN0	=	0x00a8
                    00A9    105 Ftest_hid$IP0$0$0 == 0x00a9
                    00A9    106 _IP0	=	0x00a9
                    00AB    107 Ftest_hid$FWT$0$0 == 0x00ab
                    00AB    108 _FWT	=	0x00ab
                    00AC    109 Ftest_hid$FADDRL$0$0 == 0x00ac
                    00AC    110 _FADDRL	=	0x00ac
                    00AD    111 Ftest_hid$FADDRH$0$0 == 0x00ad
                    00AD    112 _FADDRH	=	0x00ad
                    00AE    113 Ftest_hid$FCTL$0$0 == 0x00ae
                    00AE    114 _FCTL	=	0x00ae
                    00AF    115 Ftest_hid$FWDATA$0$0 == 0x00af
                    00AF    116 _FWDATA	=	0x00af
                    00B1    117 Ftest_hid$ENCDI$0$0 == 0x00b1
                    00B1    118 _ENCDI	=	0x00b1
                    00B2    119 Ftest_hid$ENCDO$0$0 == 0x00b2
                    00B2    120 _ENCDO	=	0x00b2
                    00B3    121 Ftest_hid$ENCCS$0$0 == 0x00b3
                    00B3    122 _ENCCS	=	0x00b3
                    00B4    123 Ftest_hid$ADCCON1$0$0 == 0x00b4
                    00B4    124 _ADCCON1	=	0x00b4
                    00B5    125 Ftest_hid$ADCCON2$0$0 == 0x00b5
                    00B5    126 _ADCCON2	=	0x00b5
                    00B6    127 Ftest_hid$ADCCON3$0$0 == 0x00b6
                    00B6    128 _ADCCON3	=	0x00b6
                    00B8    129 Ftest_hid$IEN1$0$0 == 0x00b8
                    00B8    130 _IEN1	=	0x00b8
                    00B9    131 Ftest_hid$IP1$0$0 == 0x00b9
                    00B9    132 _IP1	=	0x00b9
                    00BA    133 Ftest_hid$ADCL$0$0 == 0x00ba
                    00BA    134 _ADCL	=	0x00ba
                    00BB    135 Ftest_hid$ADCH$0$0 == 0x00bb
                    00BB    136 _ADCH	=	0x00bb
                    00BC    137 Ftest_hid$RNDL$0$0 == 0x00bc
                    00BC    138 _RNDL	=	0x00bc
                    00BD    139 Ftest_hid$RNDH$0$0 == 0x00bd
                    00BD    140 _RNDH	=	0x00bd
                    00BE    141 Ftest_hid$SLEEP$0$0 == 0x00be
                    00BE    142 _SLEEP	=	0x00be
                    00C0    143 Ftest_hid$IRCON$0$0 == 0x00c0
                    00C0    144 _IRCON	=	0x00c0
                    00C1    145 Ftest_hid$U0DBUF$0$0 == 0x00c1
                    00C1    146 _U0DBUF	=	0x00c1
                    00C2    147 Ftest_hid$U0BAUD$0$0 == 0x00c2
                    00C2    148 _U0BAUD	=	0x00c2
                    00C4    149 Ftest_hid$U0UCR$0$0 == 0x00c4
                    00C4    150 _U0UCR	=	0x00c4
                    00C5    151 Ftest_hid$U0GCR$0$0 == 0x00c5
                    00C5    152 _U0GCR	=	0x00c5
                    00C6    153 Ftest_hid$CLKCON$0$0 == 0x00c6
                    00C6    154 _CLKCON	=	0x00c6
                    00C7    155 Ftest_hid$MEMCTR$0$0 == 0x00c7
                    00C7    156 _MEMCTR	=	0x00c7
                    00C9    157 Ftest_hid$WDCTL$0$0 == 0x00c9
                    00C9    158 _WDCTL	=	0x00c9
                    00CA    159 Ftest_hid$T3CNT$0$0 == 0x00ca
                    00CA    160 _T3CNT	=	0x00ca
                    00CB    161 Ftest_hid$T3CTL$0$0 == 0x00cb
                    00CB    162 _T3CTL	=	0x00cb
                    00CC    163 Ftest_hid$T3CCTL0$0$0 == 0x00cc
                    00CC    164 _T3CCTL0	=	0x00cc
                    00CD    165 Ftest_hid$T3CC0$0$0 == 0x00cd
                    00CD    166 _T3CC0	=	0x00cd
                    00CE    167 Ftest_hid$T3CCTL1$0$0 == 0x00ce
                    00CE    168 _T3CCTL1	=	0x00ce
                    00CF    169 Ftest_hid$T3CC1$0$0 == 0x00cf
                    00CF    170 _T3CC1	=	0x00cf
                    00D0    171 Ftest_hid$PSW$0$0 == 0x00d0
                    00D0    172 _PSW	=	0x00d0
                    00D1    173 Ftest_hid$DMAIRQ$0$0 == 0x00d1
                    00D1    174 _DMAIRQ	=	0x00d1
                    00D2    175 Ftest_hid$DMA1CFGL$0$0 == 0x00d2
                    00D2    176 _DMA1CFGL	=	0x00d2
                    00D3    177 Ftest_hid$DMA1CFGH$0$0 == 0x00d3
                    00D3    178 _DMA1CFGH	=	0x00d3
                    00D4    179 Ftest_hid$DMA0CFGL$0$0 == 0x00d4
                    00D4    180 _DMA0CFGL	=	0x00d4
                    00D5    181 Ftest_hid$DMA0CFGH$0$0 == 0x00d5
                    00D5    182 _DMA0CFGH	=	0x00d5
                    00D6    183 Ftest_hid$DMAARM$0$0 == 0x00d6
                    00D6    184 _DMAARM	=	0x00d6
                    00D7    185 Ftest_hid$DMAREQ$0$0 == 0x00d7
                    00D7    186 _DMAREQ	=	0x00d7
                    00D8    187 Ftest_hid$TIMIF$0$0 == 0x00d8
                    00D8    188 _TIMIF	=	0x00d8
                    00D9    189 Ftest_hid$RFD$0$0 == 0x00d9
                    00D9    190 _RFD	=	0x00d9
                    00DA    191 Ftest_hid$T1CC0L$0$0 == 0x00da
                    00DA    192 _T1CC0L	=	0x00da
                    00DB    193 Ftest_hid$T1CC0H$0$0 == 0x00db
                    00DB    194 _T1CC0H	=	0x00db
                    00DC    195 Ftest_hid$T1CC1L$0$0 == 0x00dc
                    00DC    196 _T1CC1L	=	0x00dc
                    00DD    197 Ftest_hid$T1CC1H$0$0 == 0x00dd
                    00DD    198 _T1CC1H	=	0x00dd
                    00DE    199 Ftest_hid$T1CC2L$0$0 == 0x00de
                    00DE    200 _T1CC2L	=	0x00de
                    00DF    201 Ftest_hid$T1CC2H$0$0 == 0x00df
                    00DF    202 _T1CC2H	=	0x00df
                    00E0    203 Ftest_hid$ACC$0$0 == 0x00e0
                    00E0    204 _ACC	=	0x00e0
                    00E1    205 Ftest_hid$RFST$0$0 == 0x00e1
                    00E1    206 _RFST	=	0x00e1
                    00E2    207 Ftest_hid$T1CNTL$0$0 == 0x00e2
                    00E2    208 _T1CNTL	=	0x00e2
                    00E3    209 Ftest_hid$T1CNTH$0$0 == 0x00e3
                    00E3    210 _T1CNTH	=	0x00e3
                    00E4    211 Ftest_hid$T1CTL$0$0 == 0x00e4
                    00E4    212 _T1CTL	=	0x00e4
                    00E5    213 Ftest_hid$T1CCTL0$0$0 == 0x00e5
                    00E5    214 _T1CCTL0	=	0x00e5
                    00E6    215 Ftest_hid$T1CCTL1$0$0 == 0x00e6
                    00E6    216 _T1CCTL1	=	0x00e6
                    00E7    217 Ftest_hid$T1CCTL2$0$0 == 0x00e7
                    00E7    218 _T1CCTL2	=	0x00e7
                    00E8    219 Ftest_hid$IRCON2$0$0 == 0x00e8
                    00E8    220 _IRCON2	=	0x00e8
                    00E9    221 Ftest_hid$RFIF$0$0 == 0x00e9
                    00E9    222 _RFIF	=	0x00e9
                    00EA    223 Ftest_hid$T4CNT$0$0 == 0x00ea
                    00EA    224 _T4CNT	=	0x00ea
                    00EB    225 Ftest_hid$T4CTL$0$0 == 0x00eb
                    00EB    226 _T4CTL	=	0x00eb
                    00EC    227 Ftest_hid$T4CCTL0$0$0 == 0x00ec
                    00EC    228 _T4CCTL0	=	0x00ec
                    00ED    229 Ftest_hid$T4CC0$0$0 == 0x00ed
                    00ED    230 _T4CC0	=	0x00ed
                    00EE    231 Ftest_hid$T4CCTL1$0$0 == 0x00ee
                    00EE    232 _T4CCTL1	=	0x00ee
                    00EF    233 Ftest_hid$T4CC1$0$0 == 0x00ef
                    00EF    234 _T4CC1	=	0x00ef
                    00F0    235 Ftest_hid$B$0$0 == 0x00f0
                    00F0    236 _B	=	0x00f0
                    00F1    237 Ftest_hid$PERCFG$0$0 == 0x00f1
                    00F1    238 _PERCFG	=	0x00f1
                    00F2    239 Ftest_hid$ADCCFG$0$0 == 0x00f2
                    00F2    240 _ADCCFG	=	0x00f2
                    00F3    241 Ftest_hid$P0SEL$0$0 == 0x00f3
                    00F3    242 _P0SEL	=	0x00f3
                    00F4    243 Ftest_hid$P1SEL$0$0 == 0x00f4
                    00F4    244 _P1SEL	=	0x00f4
                    00F5    245 Ftest_hid$P2SEL$0$0 == 0x00f5
                    00F5    246 _P2SEL	=	0x00f5
                    00F6    247 Ftest_hid$P1INP$0$0 == 0x00f6
                    00F6    248 _P1INP	=	0x00f6
                    00F7    249 Ftest_hid$P2INP$0$0 == 0x00f7
                    00F7    250 _P2INP	=	0x00f7
                    00F8    251 Ftest_hid$U1CSR$0$0 == 0x00f8
                    00F8    252 _U1CSR	=	0x00f8
                    00F9    253 Ftest_hid$U1DBUF$0$0 == 0x00f9
                    00F9    254 _U1DBUF	=	0x00f9
                    00FA    255 Ftest_hid$U1BAUD$0$0 == 0x00fa
                    00FA    256 _U1BAUD	=	0x00fa
                    00FB    257 Ftest_hid$U1UCR$0$0 == 0x00fb
                    00FB    258 _U1UCR	=	0x00fb
                    00FC    259 Ftest_hid$U1GCR$0$0 == 0x00fc
                    00FC    260 _U1GCR	=	0x00fc
                    00FD    261 Ftest_hid$P0DIR$0$0 == 0x00fd
                    00FD    262 _P0DIR	=	0x00fd
                    00FE    263 Ftest_hid$P1DIR$0$0 == 0x00fe
                    00FE    264 _P1DIR	=	0x00fe
                    00FF    265 Ftest_hid$P2DIR$0$0 == 0x00ff
                    00FF    266 _P2DIR	=	0x00ff
                    FFFFD5D4    267 Ftest_hid$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    268 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    269 Ftest_hid$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    270 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    271 Ftest_hid$FADDR$0$0 == 0xffffadac
                    FFFFADAC    272 _FADDR	=	0xffffadac
                    FFFFBBBA    273 Ftest_hid$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    274 _ADC	=	0xffffbbba
                    FFFFDBDA    275 Ftest_hid$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    276 _T1CC0	=	0xffffdbda
                    FFFFDDDC    277 Ftest_hid$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    278 _T1CC1	=	0xffffdddc
                    FFFFDFDE    279 Ftest_hid$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    280 _T1CC2	=	0xffffdfde
                            281 ;--------------------------------------------------------
                            282 ; special function bits
                            283 ;--------------------------------------------------------
                            284 	.area RSEG    (ABS,DATA)
   0000                     285 	.org 0x0000
                    0080    286 Ftest_hid$P0_0$0$0 == 0x0080
                    0080    287 _P0_0	=	0x0080
                    0081    288 Ftest_hid$P0_1$0$0 == 0x0081
                    0081    289 _P0_1	=	0x0081
                    0082    290 Ftest_hid$P0_2$0$0 == 0x0082
                    0082    291 _P0_2	=	0x0082
                    0083    292 Ftest_hid$P0_3$0$0 == 0x0083
                    0083    293 _P0_3	=	0x0083
                    0084    294 Ftest_hid$P0_4$0$0 == 0x0084
                    0084    295 _P0_4	=	0x0084
                    0085    296 Ftest_hid$P0_5$0$0 == 0x0085
                    0085    297 _P0_5	=	0x0085
                    0086    298 Ftest_hid$P0_6$0$0 == 0x0086
                    0086    299 _P0_6	=	0x0086
                    0087    300 Ftest_hid$P0_7$0$0 == 0x0087
                    0087    301 _P0_7	=	0x0087
                    0088    302 Ftest_hid$_TCON_0$0$0 == 0x0088
                    0088    303 __TCON_0	=	0x0088
                    0089    304 Ftest_hid$RFTXRXIF$0$0 == 0x0089
                    0089    305 _RFTXRXIF	=	0x0089
                    008A    306 Ftest_hid$_TCON_2$0$0 == 0x008a
                    008A    307 __TCON_2	=	0x008a
                    008B    308 Ftest_hid$URX0IF$0$0 == 0x008b
                    008B    309 _URX0IF	=	0x008b
                    008C    310 Ftest_hid$_TCON_4$0$0 == 0x008c
                    008C    311 __TCON_4	=	0x008c
                    008D    312 Ftest_hid$ADCIF$0$0 == 0x008d
                    008D    313 _ADCIF	=	0x008d
                    008E    314 Ftest_hid$_TCON_6$0$0 == 0x008e
                    008E    315 __TCON_6	=	0x008e
                    008F    316 Ftest_hid$URX1IF$0$0 == 0x008f
                    008F    317 _URX1IF	=	0x008f
                    0090    318 Ftest_hid$P1_0$0$0 == 0x0090
                    0090    319 _P1_0	=	0x0090
                    0091    320 Ftest_hid$P1_1$0$0 == 0x0091
                    0091    321 _P1_1	=	0x0091
                    0092    322 Ftest_hid$P1_2$0$0 == 0x0092
                    0092    323 _P1_2	=	0x0092
                    0093    324 Ftest_hid$P1_3$0$0 == 0x0093
                    0093    325 _P1_3	=	0x0093
                    0094    326 Ftest_hid$P1_4$0$0 == 0x0094
                    0094    327 _P1_4	=	0x0094
                    0095    328 Ftest_hid$P1_5$0$0 == 0x0095
                    0095    329 _P1_5	=	0x0095
                    0096    330 Ftest_hid$P1_6$0$0 == 0x0096
                    0096    331 _P1_6	=	0x0096
                    0097    332 Ftest_hid$P1_7$0$0 == 0x0097
                    0097    333 _P1_7	=	0x0097
                    0098    334 Ftest_hid$ENCIF_0$0$0 == 0x0098
                    0098    335 _ENCIF_0	=	0x0098
                    0099    336 Ftest_hid$ENCIF_1$0$0 == 0x0099
                    0099    337 _ENCIF_1	=	0x0099
                    009A    338 Ftest_hid$_SOCON2$0$0 == 0x009a
                    009A    339 __SOCON2	=	0x009a
                    009B    340 Ftest_hid$_SOCON3$0$0 == 0x009b
                    009B    341 __SOCON3	=	0x009b
                    009C    342 Ftest_hid$_SOCON4$0$0 == 0x009c
                    009C    343 __SOCON4	=	0x009c
                    009D    344 Ftest_hid$_SOCON5$0$0 == 0x009d
                    009D    345 __SOCON5	=	0x009d
                    009E    346 Ftest_hid$_SOCON6$0$0 == 0x009e
                    009E    347 __SOCON6	=	0x009e
                    009F    348 Ftest_hid$_SOCON7$0$0 == 0x009f
                    009F    349 __SOCON7	=	0x009f
                    00A0    350 Ftest_hid$P2_0$0$0 == 0x00a0
                    00A0    351 _P2_0	=	0x00a0
                    00A1    352 Ftest_hid$P2_1$0$0 == 0x00a1
                    00A1    353 _P2_1	=	0x00a1
                    00A2    354 Ftest_hid$P2_2$0$0 == 0x00a2
                    00A2    355 _P2_2	=	0x00a2
                    00A3    356 Ftest_hid$P2_3$0$0 == 0x00a3
                    00A3    357 _P2_3	=	0x00a3
                    00A4    358 Ftest_hid$P2_4$0$0 == 0x00a4
                    00A4    359 _P2_4	=	0x00a4
                    00A5    360 Ftest_hid$P2_5$0$0 == 0x00a5
                    00A5    361 _P2_5	=	0x00a5
                    00A6    362 Ftest_hid$P2_6$0$0 == 0x00a6
                    00A6    363 _P2_6	=	0x00a6
                    00A7    364 Ftest_hid$P2_7$0$0 == 0x00a7
                    00A7    365 _P2_7	=	0x00a7
                    00A8    366 Ftest_hid$RFTXRXIE$0$0 == 0x00a8
                    00A8    367 _RFTXRXIE	=	0x00a8
                    00A9    368 Ftest_hid$ADCIE$0$0 == 0x00a9
                    00A9    369 _ADCIE	=	0x00a9
                    00AA    370 Ftest_hid$URX0IE$0$0 == 0x00aa
                    00AA    371 _URX0IE	=	0x00aa
                    00AB    372 Ftest_hid$URX1IE$0$0 == 0x00ab
                    00AB    373 _URX1IE	=	0x00ab
                    00AC    374 Ftest_hid$ENCIE$0$0 == 0x00ac
                    00AC    375 _ENCIE	=	0x00ac
                    00AD    376 Ftest_hid$STIE$0$0 == 0x00ad
                    00AD    377 _STIE	=	0x00ad
                    00AE    378 Ftest_hid$_IEN06$0$0 == 0x00ae
                    00AE    379 __IEN06	=	0x00ae
                    00AF    380 Ftest_hid$EA$0$0 == 0x00af
                    00AF    381 _EA	=	0x00af
                    00B8    382 Ftest_hid$DMAIE$0$0 == 0x00b8
                    00B8    383 _DMAIE	=	0x00b8
                    00B9    384 Ftest_hid$T1IE$0$0 == 0x00b9
                    00B9    385 _T1IE	=	0x00b9
                    00BA    386 Ftest_hid$T2IE$0$0 == 0x00ba
                    00BA    387 _T2IE	=	0x00ba
                    00BB    388 Ftest_hid$T3IE$0$0 == 0x00bb
                    00BB    389 _T3IE	=	0x00bb
                    00BC    390 Ftest_hid$T4IE$0$0 == 0x00bc
                    00BC    391 _T4IE	=	0x00bc
                    00BD    392 Ftest_hid$P0IE$0$0 == 0x00bd
                    00BD    393 _P0IE	=	0x00bd
                    00BE    394 Ftest_hid$_IEN16$0$0 == 0x00be
                    00BE    395 __IEN16	=	0x00be
                    00BF    396 Ftest_hid$_IEN17$0$0 == 0x00bf
                    00BF    397 __IEN17	=	0x00bf
                    00C0    398 Ftest_hid$DMAIF$0$0 == 0x00c0
                    00C0    399 _DMAIF	=	0x00c0
                    00C1    400 Ftest_hid$T1IF$0$0 == 0x00c1
                    00C1    401 _T1IF	=	0x00c1
                    00C2    402 Ftest_hid$T2IF$0$0 == 0x00c2
                    00C2    403 _T2IF	=	0x00c2
                    00C3    404 Ftest_hid$T3IF$0$0 == 0x00c3
                    00C3    405 _T3IF	=	0x00c3
                    00C4    406 Ftest_hid$T4IF$0$0 == 0x00c4
                    00C4    407 _T4IF	=	0x00c4
                    00C5    408 Ftest_hid$P0IF$0$0 == 0x00c5
                    00C5    409 _P0IF	=	0x00c5
                    00C6    410 Ftest_hid$_IRCON6$0$0 == 0x00c6
                    00C6    411 __IRCON6	=	0x00c6
                    00C7    412 Ftest_hid$STIF$0$0 == 0x00c7
                    00C7    413 _STIF	=	0x00c7
                    00D0    414 Ftest_hid$P$0$0 == 0x00d0
                    00D0    415 _P	=	0x00d0
                    00D1    416 Ftest_hid$F1$0$0 == 0x00d1
                    00D1    417 _F1	=	0x00d1
                    00D2    418 Ftest_hid$OV$0$0 == 0x00d2
                    00D2    419 _OV	=	0x00d2
                    00D3    420 Ftest_hid$RS0$0$0 == 0x00d3
                    00D3    421 _RS0	=	0x00d3
                    00D4    422 Ftest_hid$RS1$0$0 == 0x00d4
                    00D4    423 _RS1	=	0x00d4
                    00D5    424 Ftest_hid$F0$0$0 == 0x00d5
                    00D5    425 _F0	=	0x00d5
                    00D6    426 Ftest_hid$AC$0$0 == 0x00d6
                    00D6    427 _AC	=	0x00d6
                    00D7    428 Ftest_hid$CY$0$0 == 0x00d7
                    00D7    429 _CY	=	0x00d7
                    00D8    430 Ftest_hid$T3OVFIF$0$0 == 0x00d8
                    00D8    431 _T3OVFIF	=	0x00d8
                    00D9    432 Ftest_hid$T3CH0IF$0$0 == 0x00d9
                    00D9    433 _T3CH0IF	=	0x00d9
                    00DA    434 Ftest_hid$T3CH1IF$0$0 == 0x00da
                    00DA    435 _T3CH1IF	=	0x00da
                    00DB    436 Ftest_hid$T4OVFIF$0$0 == 0x00db
                    00DB    437 _T4OVFIF	=	0x00db
                    00DC    438 Ftest_hid$T4CH0IF$0$0 == 0x00dc
                    00DC    439 _T4CH0IF	=	0x00dc
                    00DD    440 Ftest_hid$T4CH1IF$0$0 == 0x00dd
                    00DD    441 _T4CH1IF	=	0x00dd
                    00DE    442 Ftest_hid$OVFIM$0$0 == 0x00de
                    00DE    443 _OVFIM	=	0x00de
                    00DF    444 Ftest_hid$_TIMIF7$0$0 == 0x00df
                    00DF    445 __TIMIF7	=	0x00df
                    00E0    446 Ftest_hid$ACC_0$0$0 == 0x00e0
                    00E0    447 _ACC_0	=	0x00e0
                    00E1    448 Ftest_hid$ACC_1$0$0 == 0x00e1
                    00E1    449 _ACC_1	=	0x00e1
                    00E2    450 Ftest_hid$ACC_2$0$0 == 0x00e2
                    00E2    451 _ACC_2	=	0x00e2
                    00E3    452 Ftest_hid$ACC_3$0$0 == 0x00e3
                    00E3    453 _ACC_3	=	0x00e3
                    00E4    454 Ftest_hid$ACC_4$0$0 == 0x00e4
                    00E4    455 _ACC_4	=	0x00e4
                    00E5    456 Ftest_hid$ACC_5$0$0 == 0x00e5
                    00E5    457 _ACC_5	=	0x00e5
                    00E6    458 Ftest_hid$ACC_6$0$0 == 0x00e6
                    00E6    459 _ACC_6	=	0x00e6
                    00E7    460 Ftest_hid$ACC_7$0$0 == 0x00e7
                    00E7    461 _ACC_7	=	0x00e7
                    00E8    462 Ftest_hid$P2IF$0$0 == 0x00e8
                    00E8    463 _P2IF	=	0x00e8
                    00E9    464 Ftest_hid$UTX0IF$0$0 == 0x00e9
                    00E9    465 _UTX0IF	=	0x00e9
                    00EA    466 Ftest_hid$UTX1IF$0$0 == 0x00ea
                    00EA    467 _UTX1IF	=	0x00ea
                    00EB    468 Ftest_hid$P1IF$0$0 == 0x00eb
                    00EB    469 _P1IF	=	0x00eb
                    00EC    470 Ftest_hid$WDTIF$0$0 == 0x00ec
                    00EC    471 _WDTIF	=	0x00ec
                    00ED    472 Ftest_hid$_IRCON25$0$0 == 0x00ed
                    00ED    473 __IRCON25	=	0x00ed
                    00EE    474 Ftest_hid$_IRCON26$0$0 == 0x00ee
                    00EE    475 __IRCON26	=	0x00ee
                    00EF    476 Ftest_hid$_IRCON27$0$0 == 0x00ef
                    00EF    477 __IRCON27	=	0x00ef
                    00F0    478 Ftest_hid$B_0$0$0 == 0x00f0
                    00F0    479 _B_0	=	0x00f0
                    00F1    480 Ftest_hid$B_1$0$0 == 0x00f1
                    00F1    481 _B_1	=	0x00f1
                    00F2    482 Ftest_hid$B_2$0$0 == 0x00f2
                    00F2    483 _B_2	=	0x00f2
                    00F3    484 Ftest_hid$B_3$0$0 == 0x00f3
                    00F3    485 _B_3	=	0x00f3
                    00F4    486 Ftest_hid$B_4$0$0 == 0x00f4
                    00F4    487 _B_4	=	0x00f4
                    00F5    488 Ftest_hid$B_5$0$0 == 0x00f5
                    00F5    489 _B_5	=	0x00f5
                    00F6    490 Ftest_hid$B_6$0$0 == 0x00f6
                    00F6    491 _B_6	=	0x00f6
                    00F7    492 Ftest_hid$B_7$0$0 == 0x00f7
                    00F7    493 _B_7	=	0x00f7
                    00F8    494 Ftest_hid$U1ACTIVE$0$0 == 0x00f8
                    00F8    495 _U1ACTIVE	=	0x00f8
                    00F9    496 Ftest_hid$U1TX_BYTE$0$0 == 0x00f9
                    00F9    497 _U1TX_BYTE	=	0x00f9
                    00FA    498 Ftest_hid$U1RX_BYTE$0$0 == 0x00fa
                    00FA    499 _U1RX_BYTE	=	0x00fa
                    00FB    500 Ftest_hid$U1ERR$0$0 == 0x00fb
                    00FB    501 _U1ERR	=	0x00fb
                    00FC    502 Ftest_hid$U1FE$0$0 == 0x00fc
                    00FC    503 _U1FE	=	0x00fc
                    00FD    504 Ftest_hid$U1SLAVE$0$0 == 0x00fd
                    00FD    505 _U1SLAVE	=	0x00fd
                    00FE    506 Ftest_hid$U1RE$0$0 == 0x00fe
                    00FE    507 _U1RE	=	0x00fe
                    00FF    508 Ftest_hid$U1MODE$0$0 == 0x00ff
                    00FF    509 _U1MODE	=	0x00ff
                            510 ;--------------------------------------------------------
                            511 ; overlayable register banks
                            512 ;--------------------------------------------------------
                            513 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     514 	.ds 8
                            515 ;--------------------------------------------------------
                            516 ; internal ram data
                            517 ;--------------------------------------------------------
                            518 	.area DSEG    (DATA)
                            519 ;--------------------------------------------------------
                            520 ; overlayable items in internal ram 
                            521 ;--------------------------------------------------------
                            522 	.area OSEG    (OVR,DATA)
                            523 ;--------------------------------------------------------
                            524 ; Stack segment in internal ram 
                            525 ;--------------------------------------------------------
                            526 	.area	SSEG	(DATA)
   0023                     527 __start__stack:
   0023                     528 	.ds	1
                            529 
                            530 ;--------------------------------------------------------
                            531 ; indirectly addressable internal ram data
                            532 ;--------------------------------------------------------
                            533 	.area ISEG    (DATA)
                            534 ;--------------------------------------------------------
                            535 ; absolute internal ram data
                            536 ;--------------------------------------------------------
                            537 	.area IABS    (ABS,DATA)
                            538 	.area IABS    (ABS,DATA)
                            539 ;--------------------------------------------------------
                            540 ; bit data
                            541 ;--------------------------------------------------------
                            542 	.area BSEG    (BIT)
                    0000    543 Ltest_hid.buttonGetSingleDebouncedPress$reportedThisButtonPress$1$1==.
   0000                     544 _buttonGetSingleDebouncedPress_reportedThisButtonPress_1_1:
   0000                     545 	.ds 1
                            546 ;--------------------------------------------------------
                            547 ; paged external ram data
                            548 ;--------------------------------------------------------
                            549 	.area PSEG    (PAG,XDATA)
                    0000    550 G$lastKeyCodeSent$0$0==.
   F000                     551 _lastKeyCodeSent::
   F000                     552 	.ds 1
                    0001    553 Ltest_hid.buttonGetSingleDebouncedPress$lastTimeButtonWasNotPressed$1$1==.
   F001                     554 _buttonGetSingleDebouncedPress_lastTimeButtonWasNotPressed_1_1:
   F001                     555 	.ds 1
                    0002    556 Ltest_hid.keyboardService$charsLeftToSend$1$1==.
   F002                     557 _keyboardService_charsLeftToSend_1_1:
   F002                     558 	.ds 1
                    0003    559 Ltest_hid.keyboardService$nextCharToSend$1$1==.
   F003                     560 _keyboardService_nextCharToSend_1_1:
   F003                     561 	.ds 2
                            562 ;--------------------------------------------------------
                            563 ; external ram data
                            564 ;--------------------------------------------------------
                            565 	.area XSEG    (XDATA)
                    DF00    566 Ftest_hid$SYNC1$0$0 == 0xdf00
                    DF00    567 _SYNC1	=	0xdf00
                    DF01    568 Ftest_hid$SYNC0$0$0 == 0xdf01
                    DF01    569 _SYNC0	=	0xdf01
                    DF02    570 Ftest_hid$PKTLEN$0$0 == 0xdf02
                    DF02    571 _PKTLEN	=	0xdf02
                    DF03    572 Ftest_hid$PKTCTRL1$0$0 == 0xdf03
                    DF03    573 _PKTCTRL1	=	0xdf03
                    DF04    574 Ftest_hid$PKTCTRL0$0$0 == 0xdf04
                    DF04    575 _PKTCTRL0	=	0xdf04
                    DF05    576 Ftest_hid$ADDR$0$0 == 0xdf05
                    DF05    577 _ADDR	=	0xdf05
                    DF06    578 Ftest_hid$CHANNR$0$0 == 0xdf06
                    DF06    579 _CHANNR	=	0xdf06
                    DF07    580 Ftest_hid$FSCTRL1$0$0 == 0xdf07
                    DF07    581 _FSCTRL1	=	0xdf07
                    DF08    582 Ftest_hid$FSCTRL0$0$0 == 0xdf08
                    DF08    583 _FSCTRL0	=	0xdf08
                    DF09    584 Ftest_hid$FREQ2$0$0 == 0xdf09
                    DF09    585 _FREQ2	=	0xdf09
                    DF0A    586 Ftest_hid$FREQ1$0$0 == 0xdf0a
                    DF0A    587 _FREQ1	=	0xdf0a
                    DF0B    588 Ftest_hid$FREQ0$0$0 == 0xdf0b
                    DF0B    589 _FREQ0	=	0xdf0b
                    DF0C    590 Ftest_hid$MDMCFG4$0$0 == 0xdf0c
                    DF0C    591 _MDMCFG4	=	0xdf0c
                    DF0D    592 Ftest_hid$MDMCFG3$0$0 == 0xdf0d
                    DF0D    593 _MDMCFG3	=	0xdf0d
                    DF0E    594 Ftest_hid$MDMCFG2$0$0 == 0xdf0e
                    DF0E    595 _MDMCFG2	=	0xdf0e
                    DF0F    596 Ftest_hid$MDMCFG1$0$0 == 0xdf0f
                    DF0F    597 _MDMCFG1	=	0xdf0f
                    DF10    598 Ftest_hid$MDMCFG0$0$0 == 0xdf10
                    DF10    599 _MDMCFG0	=	0xdf10
                    DF11    600 Ftest_hid$DEVIATN$0$0 == 0xdf11
                    DF11    601 _DEVIATN	=	0xdf11
                    DF12    602 Ftest_hid$MCSM2$0$0 == 0xdf12
                    DF12    603 _MCSM2	=	0xdf12
                    DF13    604 Ftest_hid$MCSM1$0$0 == 0xdf13
                    DF13    605 _MCSM1	=	0xdf13
                    DF14    606 Ftest_hid$MCSM0$0$0 == 0xdf14
                    DF14    607 _MCSM0	=	0xdf14
                    DF15    608 Ftest_hid$FOCCFG$0$0 == 0xdf15
                    DF15    609 _FOCCFG	=	0xdf15
                    DF16    610 Ftest_hid$BSCFG$0$0 == 0xdf16
                    DF16    611 _BSCFG	=	0xdf16
                    DF17    612 Ftest_hid$AGCCTRL2$0$0 == 0xdf17
                    DF17    613 _AGCCTRL2	=	0xdf17
                    DF18    614 Ftest_hid$AGCCTRL1$0$0 == 0xdf18
                    DF18    615 _AGCCTRL1	=	0xdf18
                    DF19    616 Ftest_hid$AGCCTRL0$0$0 == 0xdf19
                    DF19    617 _AGCCTRL0	=	0xdf19
                    DF1A    618 Ftest_hid$FREND1$0$0 == 0xdf1a
                    DF1A    619 _FREND1	=	0xdf1a
                    DF1B    620 Ftest_hid$FREND0$0$0 == 0xdf1b
                    DF1B    621 _FREND0	=	0xdf1b
                    DF1C    622 Ftest_hid$FSCAL3$0$0 == 0xdf1c
                    DF1C    623 _FSCAL3	=	0xdf1c
                    DF1D    624 Ftest_hid$FSCAL2$0$0 == 0xdf1d
                    DF1D    625 _FSCAL2	=	0xdf1d
                    DF1E    626 Ftest_hid$FSCAL1$0$0 == 0xdf1e
                    DF1E    627 _FSCAL1	=	0xdf1e
                    DF1F    628 Ftest_hid$FSCAL0$0$0 == 0xdf1f
                    DF1F    629 _FSCAL0	=	0xdf1f
                    DF23    630 Ftest_hid$TEST2$0$0 == 0xdf23
                    DF23    631 _TEST2	=	0xdf23
                    DF24    632 Ftest_hid$TEST1$0$0 == 0xdf24
                    DF24    633 _TEST1	=	0xdf24
                    DF25    634 Ftest_hid$TEST0$0$0 == 0xdf25
                    DF25    635 _TEST0	=	0xdf25
                    DF2E    636 Ftest_hid$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    637 _PA_TABLE0	=	0xdf2e
                    DF2F    638 Ftest_hid$IOCFG2$0$0 == 0xdf2f
                    DF2F    639 _IOCFG2	=	0xdf2f
                    DF30    640 Ftest_hid$IOCFG1$0$0 == 0xdf30
                    DF30    641 _IOCFG1	=	0xdf30
                    DF31    642 Ftest_hid$IOCFG0$0$0 == 0xdf31
                    DF31    643 _IOCFG0	=	0xdf31
                    DF36    644 Ftest_hid$PARTNUM$0$0 == 0xdf36
                    DF36    645 _PARTNUM	=	0xdf36
                    DF37    646 Ftest_hid$VERSION$0$0 == 0xdf37
                    DF37    647 _VERSION	=	0xdf37
                    DF38    648 Ftest_hid$FREQEST$0$0 == 0xdf38
                    DF38    649 _FREQEST	=	0xdf38
                    DF39    650 Ftest_hid$LQI$0$0 == 0xdf39
                    DF39    651 _LQI	=	0xdf39
                    DF3A    652 Ftest_hid$RSSI$0$0 == 0xdf3a
                    DF3A    653 _RSSI	=	0xdf3a
                    DF3B    654 Ftest_hid$MARCSTATE$0$0 == 0xdf3b
                    DF3B    655 _MARCSTATE	=	0xdf3b
                    DF3C    656 Ftest_hid$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    657 _PKTSTATUS	=	0xdf3c
                    DF3D    658 Ftest_hid$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    659 _VCO_VC_DAC	=	0xdf3d
                    DF40    660 Ftest_hid$I2SCFG0$0$0 == 0xdf40
                    DF40    661 _I2SCFG0	=	0xdf40
                    DF41    662 Ftest_hid$I2SCFG1$0$0 == 0xdf41
                    DF41    663 _I2SCFG1	=	0xdf41
                    DF42    664 Ftest_hid$I2SDATL$0$0 == 0xdf42
                    DF42    665 _I2SDATL	=	0xdf42
                    DF43    666 Ftest_hid$I2SDATH$0$0 == 0xdf43
                    DF43    667 _I2SDATH	=	0xdf43
                    DF44    668 Ftest_hid$I2SWCNT$0$0 == 0xdf44
                    DF44    669 _I2SWCNT	=	0xdf44
                    DF45    670 Ftest_hid$I2SSTAT$0$0 == 0xdf45
                    DF45    671 _I2SSTAT	=	0xdf45
                    DF46    672 Ftest_hid$I2SCLKF0$0$0 == 0xdf46
                    DF46    673 _I2SCLKF0	=	0xdf46
                    DF47    674 Ftest_hid$I2SCLKF1$0$0 == 0xdf47
                    DF47    675 _I2SCLKF1	=	0xdf47
                    DF48    676 Ftest_hid$I2SCLKF2$0$0 == 0xdf48
                    DF48    677 _I2SCLKF2	=	0xdf48
                    DE00    678 Ftest_hid$USBADDR$0$0 == 0xde00
                    DE00    679 _USBADDR	=	0xde00
                    DE01    680 Ftest_hid$USBPOW$0$0 == 0xde01
                    DE01    681 _USBPOW	=	0xde01
                    DE02    682 Ftest_hid$USBIIF$0$0 == 0xde02
                    DE02    683 _USBIIF	=	0xde02
                    DE04    684 Ftest_hid$USBOIF$0$0 == 0xde04
                    DE04    685 _USBOIF	=	0xde04
                    DE06    686 Ftest_hid$USBCIF$0$0 == 0xde06
                    DE06    687 _USBCIF	=	0xde06
                    DE07    688 Ftest_hid$USBIIE$0$0 == 0xde07
                    DE07    689 _USBIIE	=	0xde07
                    DE09    690 Ftest_hid$USBOIE$0$0 == 0xde09
                    DE09    691 _USBOIE	=	0xde09
                    DE0B    692 Ftest_hid$USBCIE$0$0 == 0xde0b
                    DE0B    693 _USBCIE	=	0xde0b
                    DE0C    694 Ftest_hid$USBFRML$0$0 == 0xde0c
                    DE0C    695 _USBFRML	=	0xde0c
                    DE0D    696 Ftest_hid$USBFRMH$0$0 == 0xde0d
                    DE0D    697 _USBFRMH	=	0xde0d
                    DE0E    698 Ftest_hid$USBINDEX$0$0 == 0xde0e
                    DE0E    699 _USBINDEX	=	0xde0e
                    DE10    700 Ftest_hid$USBMAXI$0$0 == 0xde10
                    DE10    701 _USBMAXI	=	0xde10
                    DE11    702 Ftest_hid$USBCSIL$0$0 == 0xde11
                    DE11    703 _USBCSIL	=	0xde11
                    DE12    704 Ftest_hid$USBCSIH$0$0 == 0xde12
                    DE12    705 _USBCSIH	=	0xde12
                    DE13    706 Ftest_hid$USBMAXO$0$0 == 0xde13
                    DE13    707 _USBMAXO	=	0xde13
                    DE14    708 Ftest_hid$USBCSOL$0$0 == 0xde14
                    DE14    709 _USBCSOL	=	0xde14
                    DE15    710 Ftest_hid$USBCSOH$0$0 == 0xde15
                    DE15    711 _USBCSOH	=	0xde15
                    DE16    712 Ftest_hid$USBCNTL$0$0 == 0xde16
                    DE16    713 _USBCNTL	=	0xde16
                    DE17    714 Ftest_hid$USBCNTH$0$0 == 0xde17
                    DE17    715 _USBCNTH	=	0xde17
                    DE20    716 Ftest_hid$USBF0$0$0 == 0xde20
                    DE20    717 _USBF0	=	0xde20
                    DE22    718 Ftest_hid$USBF1$0$0 == 0xde22
                    DE22    719 _USBF1	=	0xde22
                    DE24    720 Ftest_hid$USBF2$0$0 == 0xde24
                    DE24    721 _USBF2	=	0xde24
                    DE26    722 Ftest_hid$USBF3$0$0 == 0xde26
                    DE26    723 _USBF3	=	0xde26
                    DE28    724 Ftest_hid$USBF4$0$0 == 0xde28
                    DE28    725 _USBF4	=	0xde28
                    DE2A    726 Ftest_hid$USBF5$0$0 == 0xde2a
                    DE2A    727 _USBF5	=	0xde2a
                            728 ;--------------------------------------------------------
                            729 ; absolute external ram data
                            730 ;--------------------------------------------------------
                            731 	.area XABS    (ABS,XDATA)
                            732 ;--------------------------------------------------------
                            733 ; external initialized ram data
                            734 ;--------------------------------------------------------
                            735 	.area XISEG   (XDATA)
                            736 	.area HOME    (CODE)
                            737 	.area GSINIT0 (CODE)
                            738 	.area GSINIT1 (CODE)
                            739 	.area GSINIT2 (CODE)
                            740 	.area GSINIT3 (CODE)
                            741 	.area GSINIT4 (CODE)
                            742 	.area GSINIT5 (CODE)
                            743 	.area GSINIT  (CODE)
                            744 	.area GSFINAL (CODE)
                            745 	.area CSEG    (CODE)
                            746 ;--------------------------------------------------------
                            747 ; interrupt vector 
                            748 ;--------------------------------------------------------
                            749 	.area HOME    (CODE)
   0400                     750 __interrupt_vect:
   0400 02 04 6B            751 	ljmp	__sdcc_gsinit_startup
   0403 32                  752 	reti
   0404                     753 	.ds	7
   040B 32                  754 	reti
   040C                     755 	.ds	7
   0413 32                  756 	reti
   0414                     757 	.ds	7
   041B 32                  758 	reti
   041C                     759 	.ds	7
   0423 32                  760 	reti
   0424                     761 	.ds	7
   042B 32                  762 	reti
   042C                     763 	.ds	7
   0433 32                  764 	reti
   0434                     765 	.ds	7
   043B 32                  766 	reti
   043C                     767 	.ds	7
   0443 32                  768 	reti
   0444                     769 	.ds	7
   044B 32                  770 	reti
   044C                     771 	.ds	7
   0453 32                  772 	reti
   0454                     773 	.ds	7
   045B 32                  774 	reti
   045C                     775 	.ds	7
   0463 02 12 64            776 	ljmp	_ISR_T4
                            777 ;--------------------------------------------------------
                            778 ; global & static initialisations
                            779 ;--------------------------------------------------------
                            780 	.area HOME    (CODE)
                            781 	.area GSINIT  (CODE)
                            782 	.area GSFINAL (CODE)
                            783 	.area GSINIT  (CODE)
                            784 	.globl __sdcc_gsinit_startup
                            785 	.globl __sdcc_program_startup
                            786 	.globl __start__stack
                            787 	.globl __mcs51_genXINIT
                            788 	.globl __mcs51_genXRAMCLEAR
                            789 	.globl __mcs51_genRAMCLEAR
                            790 ;------------------------------------------------------------
                            791 ;Allocation info for local variables in function 'buttonGetSingleDebouncedPress'
                            792 ;------------------------------------------------------------
                    0000    793 	G$buttonGetSingleDebouncedPress$0$0 ==.
                    0000    794 	C$test_hid.c$153$1$1 ==.
                            795 ;	apps/test_hid/test_hid.c:153: static BIT reportedThisButtonPress = 0;
   04C4 C2 00               796 	clr	_buttonGetSingleDebouncedPress_reportedThisButtonPress_1_1
                    0002    797 	C$test_hid.c$154$1$1 ==.
                            798 ;	apps/test_hid/test_hid.c:154: static uint8 lastTimeButtonWasNotPressed = 0;
   04C6 78 01               799 	mov	r0,#_buttonGetSingleDebouncedPress_lastTimeButtonWasNotPressed_1_1
   04C8 E4                  800 	clr	a
   04C9 F2                  801 	movx	@r0,a
                            802 ;------------------------------------------------------------
                            803 ;Allocation info for local variables in function 'keyboardService'
                            804 ;------------------------------------------------------------
                    0006    805 	G$keyboardService$0$0 ==.
                    0006    806 	C$test_hid.c$182$2$1 ==.
                            807 ;	apps/test_hid/test_hid.c:182: static uint8 charsLeftToSend = 0;
   04CA 78 02               808 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   04CC E4                  809 	clr	a
   04CD F2                  810 	movx	@r0,a
                    000A    811 	G$main$0$0 ==.
                    000A    812 	C$test_hid.c$40$1$1 ==.
                            813 ;	apps/test_hid/test_hid.c:40: uint8 lastKeyCodeSent = 0;
   04CE 78 00               814 	mov	r0,#_lastKeyCodeSent
   04D0 E4                  815 	clr	a
   04D1 F2                  816 	movx	@r0,a
                            817 	.area GSFINAL (CODE)
   04EE 02 04 66            818 	ljmp	__sdcc_program_startup
                            819 ;--------------------------------------------------------
                            820 ; Home
                            821 ;--------------------------------------------------------
                            822 	.area HOME    (CODE)
                            823 	.area HOME    (CODE)
   0466                     824 __sdcc_program_startup:
   0466 12 07 63            825 	lcall	_main
                            826 ;	return from main will lock up
   0469 80 FE               827 	sjmp .
                            828 ;--------------------------------------------------------
                            829 ; code
                            830 ;--------------------------------------------------------
                            831 	.area CSEG    (CODE)
                            832 ;------------------------------------------------------------
                            833 ;Allocation info for local variables in function 'updateLeds'
                            834 ;------------------------------------------------------------
                    0000    835 	G$updateLeds$0$0 ==.
                    0000    836 	C$test_hid.c$42$0$0 ==.
                            837 ;	apps/test_hid/test_hid.c:42: void updateLeds()
                            838 ;	-----------------------------------------
                            839 ;	 function updateLeds
                            840 ;	-----------------------------------------
   04F1                     841 _updateLeds:
                    0007    842 	ar7 = 0x07
                    0006    843 	ar6 = 0x06
                    0005    844 	ar5 = 0x05
                    0004    845 	ar4 = 0x04
                    0003    846 	ar3 = 0x03
                    0002    847 	ar2 = 0x02
                    0001    848 	ar1 = 0x01
                    0000    849 	ar0 = 0x00
                    0000    850 	C$test_hid.c$44$1$1 ==.
                            851 ;	apps/test_hid/test_hid.c:44: usbShowStatusWithGreenLed();
   04F1 12 16 CE            852 	lcall	_usbShowStatusWithGreenLed
                    0003    853 	C$test_hid.c$46$2$2 ==.
                            854 ;	apps/test_hid/test_hid.c:46: LED_YELLOW(usbHidKeyboardOutput.leds & (1 << LED_CAPS_LOCK));
   04F4 90 F0 49            855 	mov	dptr,#_usbHidKeyboardOutput
   04F7 E0                  856 	movx	a,@dptr
   04F8 FF                  857 	mov	r7,a
   04F9 30 E1 05            858 	jnb	acc.1,00103$
   04FC 43 FF 04            859 	orl	_P2DIR,#0x04
   04FF 80 07               860 	sjmp	00101$
   0501                     861 00103$:
   0501 AF FF               862 	mov	r7,_P2DIR
   0503 53 07 FB            863 	anl	ar7,#0xFB
   0506 8F FF               864 	mov	_P2DIR,r7
   0508                     865 00101$:
                    0017    866 	C$test_hid.c$54$2$2 ==.
                    0017    867 	XG$updateLeds$0$0 ==.
   0508 22                  868 	ret
                            869 ;------------------------------------------------------------
                            870 ;Allocation info for local variables in function 'updateMouseState'
                            871 ;------------------------------------------------------------
                    0018    872 	G$updateMouseState$0$0 ==.
                    0018    873 	C$test_hid.c$56$2$2 ==.
                            874 ;	apps/test_hid/test_hid.c:56: void updateMouseState()
                            875 ;	-----------------------------------------
                            876 ;	 function updateMouseState
                            877 ;	-----------------------------------------
   0509                     878 _updateMouseState:
                    0018    879 	C$test_hid.c$58$1$1 ==.
                            880 ;	apps/test_hid/test_hid.c:58: usbHidMouseInput.x = 0;
   0509 90 F0 53            881 	mov	dptr,#(_usbHidMouseInput + 0x0001)
                    001B    882 	C$test_hid.c$59$1$1 ==.
                            883 ;	apps/test_hid/test_hid.c:59: usbHidMouseInput.y = 0;
   050C E4                  884 	clr	a
   050D F0                  885 	movx	@dptr,a
   050E 90 F0 54            886 	mov	dptr,#(_usbHidMouseInput + 0x0002)
   0511 F0                  887 	movx	@dptr,a
                    0021    888 	C$test_hid.c$61$1$1 ==.
                            889 ;	apps/test_hid/test_hid.c:61: if (param_move_cursor)
   0512 90 17 77            890 	mov	dptr,#_param_move_cursor
   0515 E4                  891 	clr	a
   0516 93                  892 	movc	a,@a+dptr
   0517 FC                  893 	mov	r4,a
   0518 74 01               894 	mov	a,#0x01
   051A 93                  895 	movc	a,@a+dptr
   051B FD                  896 	mov	r5,a
   051C 74 02               897 	mov	a,#0x02
   051E 93                  898 	movc	a,@a+dptr
   051F FE                  899 	mov	r6,a
   0520 74 03               900 	mov	a,#0x03
   0522 93                  901 	movc	a,@a+dptr
   0523 FF                  902 	mov	r7,a
   0524 EC                  903 	mov	a,r4
   0525 4D                  904 	orl	a,r5
   0526 4E                  905 	orl	a,r6
   0527 4F                  906 	orl	a,r7
   0528 60 4D               907 	jz	00107$
                    0039    908 	C$test_hid.c$63$2$2 ==.
                            909 ;	apps/test_hid/test_hid.c:63: uint8 direction = getMs() >> 9 & 3;
   052A 12 12 89            910 	lcall	_getMs
   052D AD 83               911 	mov	r5,dph
   052F AE F0               912 	mov	r6,b
   0531 C3                  913 	clr	c
   0532 13                  914 	rrc	a
   0533 CE                  915 	xch	a,r6
   0534 13                  916 	rrc	a
   0535 CD                  917 	xch	a,r5
   0536 13                  918 	rrc	a
   0537 FC                  919 	mov	r4,a
   0538 53 04 03            920 	anl	ar4,#0x03
   053B 7D 00               921 	mov	r5,#0x00
   053D 7E 00               922 	mov	r6,#0x00
   053F 7F 00               923 	mov	r7,#0x00
                    0050    924 	C$test_hid.c$64$2$2 ==.
                            925 ;	apps/test_hid/test_hid.c:64: switch(direction)
   0541 EC                  926 	mov	a,r4
   0542 24 FC               927 	add	a,#0xff - 0x03
   0544 40 31               928 	jc	00107$
   0546 EC                  929 	mov	a,r4
   0547 2C                  930 	add	a,r4
   0548 2C                  931 	add	a,r4
   0549 90 05 4D            932 	mov	dptr,#00127$
   054C 73                  933 	jmp	@a+dptr
   054D                     934 00127$:
   054D 02 05 59            935 	ljmp	00101$
   0550 02 05 61            936 	ljmp	00102$
   0553 02 05 69            937 	ljmp	00103$
   0556 02 05 71            938 	ljmp	00104$
                    0068    939 	C$test_hid.c$66$3$3 ==.
                            940 ;	apps/test_hid/test_hid.c:66: case 0: usbHidMouseInput.x = 3; break;
   0559                     941 00101$:
   0559 90 F0 53            942 	mov	dptr,#(_usbHidMouseInput + 0x0001)
   055C 74 03               943 	mov	a,#0x03
   055E F0                  944 	movx	@dptr,a
                    006E    945 	C$test_hid.c$67$3$3 ==.
                            946 ;	apps/test_hid/test_hid.c:67: case 1: usbHidMouseInput.y = 3; break;
   055F 80 16               947 	sjmp	00107$
   0561                     948 00102$:
   0561 90 F0 54            949 	mov	dptr,#(_usbHidMouseInput + 0x0002)
   0564 74 03               950 	mov	a,#0x03
   0566 F0                  951 	movx	@dptr,a
                    0076    952 	C$test_hid.c$68$3$3 ==.
                            953 ;	apps/test_hid/test_hid.c:68: case 2: usbHidMouseInput.x = -3; break;
   0567 80 0E               954 	sjmp	00107$
   0569                     955 00103$:
   0569 90 F0 53            956 	mov	dptr,#(_usbHidMouseInput + 0x0001)
   056C 74 FD               957 	mov	a,#0xFD
   056E F0                  958 	movx	@dptr,a
                    007E    959 	C$test_hid.c$69$3$3 ==.
                            960 ;	apps/test_hid/test_hid.c:69: case 3: usbHidMouseInput.y = -3; break;
   056F 80 06               961 	sjmp	00107$
   0571                     962 00104$:
   0571 90 F0 54            963 	mov	dptr,#(_usbHidMouseInput + 0x0002)
   0574 74 FD               964 	mov	a,#0xFD
   0576 F0                  965 	movx	@dptr,a
                    0086    966 	C$test_hid.c$70$1$1 ==.
                            967 ;	apps/test_hid/test_hid.c:70: }
   0577                     968 00107$:
                    0086    969 	C$test_hid.c$73$1$1 ==.
                            970 ;	apps/test_hid/test_hid.c:73: if (param_move_mouse_wheel)
   0577 90 17 7B            971 	mov	dptr,#_param_move_mouse_wheel
   057A E4                  972 	clr	a
   057B 93                  973 	movc	a,@a+dptr
   057C FC                  974 	mov	r4,a
   057D 74 01               975 	mov	a,#0x01
   057F 93                  976 	movc	a,@a+dptr
   0580 FD                  977 	mov	r5,a
   0581 74 02               978 	mov	a,#0x02
   0583 93                  979 	movc	a,@a+dptr
   0584 FE                  980 	mov	r6,a
   0585 74 03               981 	mov	a,#0x03
   0587 93                  982 	movc	a,@a+dptr
   0588 FF                  983 	mov	r7,a
   0589 EC                  984 	mov	a,r4
   058A 4D                  985 	orl	a,r5
   058B 4E                  986 	orl	a,r6
   058C 4F                  987 	orl	a,r7
   058D 60 1E               988 	jz	00112$
                    009E    989 	C$test_hid.c$75$2$4 ==.
                            990 ;	apps/test_hid/test_hid.c:75: uint8 direction = getMs() >> 10 & 1;
   058F 12 12 89            991 	lcall	_getMs
   0592 AD 83               992 	mov	r5,dph
   0594 AE F0               993 	mov	r6,b
   0596 FF                  994 	mov	r7,a
   0597 ED                  995 	mov	a,r5
   0598 03                  996 	rr	a
   0599 03                  997 	rr	a
   059A 54 01               998 	anl	a,#0x01
                    00AB    999 	C$test_hid.c$76$2$4 ==.
                           1000 ;	apps/test_hid/test_hid.c:76: if (direction)
   059C FC                 1001 	mov	r4,a
   059D 60 08              1002 	jz	00109$
                    00AE   1003 	C$test_hid.c$78$3$5 ==.
                           1004 ;	apps/test_hid/test_hid.c:78: usbHidMouseInput.wheel = -1;
   059F 90 F0 55           1005 	mov	dptr,#(_usbHidMouseInput + 0x0003)
   05A2 74 FF              1006 	mov	a,#0xFF
   05A4 F0                 1007 	movx	@dptr,a
   05A5 80 06              1008 	sjmp	00112$
   05A7                    1009 00109$:
                    00B6   1010 	C$test_hid.c$82$3$6 ==.
                           1011 ;	apps/test_hid/test_hid.c:82: usbHidMouseInput.wheel = 1;
   05A7 90 F0 55           1012 	mov	dptr,#(_usbHidMouseInput + 0x0003)
   05AA 74 01              1013 	mov	a,#0x01
   05AC F0                 1014 	movx	@dptr,a
   05AD                    1015 00112$:
                    00BC   1016 	C$test_hid.c$86$1$1 ==.
                           1017 ;	apps/test_hid/test_hid.c:86: usbHidMouseInput.buttons = 0;
   05AD 90 F0 52           1018 	mov	dptr,#_usbHidMouseInput
   05B0 E4                 1019 	clr	a
   05B1 F0                 1020 	movx	@dptr,a
                    00C1   1021 	C$test_hid.c$87$1$1 ==.
                           1022 ;	apps/test_hid/test_hid.c:87: if (!isPinHigh(0))
   05B2 75 82 00           1023 	mov	dpl,#0x00
   05B5 12 16 00           1024 	lcall	_isPinHigh
   05B8 40 08              1025 	jc	00114$
                    00C9   1026 	C$test_hid.c$90$2$7 ==.
                           1027 ;	apps/test_hid/test_hid.c:90: usbHidMouseInput.buttons |= (1<<MOUSE_BUTTON_LEFT);
   05BA 90 F0 52           1028 	mov	dptr,#_usbHidMouseInput
   05BD E0                 1029 	movx	a,@dptr
   05BE 44 01              1030 	orl	a,#0x01
   05C0 FF                 1031 	mov	r7,a
   05C1 F0                 1032 	movx	@dptr,a
   05C2                    1033 00114$:
                    00D1   1034 	C$test_hid.c$92$1$1 ==.
                           1035 ;	apps/test_hid/test_hid.c:92: if (!isPinHigh(1))
   05C2 75 82 01           1036 	mov	dpl,#0x01
   05C5 12 16 00           1037 	lcall	_isPinHigh
   05C8 40 08              1038 	jc	00116$
                    00D9   1039 	C$test_hid.c$95$2$8 ==.
                           1040 ;	apps/test_hid/test_hid.c:95: usbHidMouseInput.buttons |= (1<<MOUSE_BUTTON_RIGHT);
   05CA 90 F0 52           1041 	mov	dptr,#_usbHidMouseInput
   05CD E0                 1042 	movx	a,@dptr
   05CE 44 02              1043 	orl	a,#0x02
   05D0 FF                 1044 	mov	r7,a
   05D1 F0                 1045 	movx	@dptr,a
   05D2                    1046 00116$:
                    00E1   1047 	C$test_hid.c$98$1$1 ==.
                           1048 ;	apps/test_hid/test_hid.c:98: usbHidMouseInputUpdated = 1;
   05D2 D2 02              1049 	setb	_usbHidMouseInputUpdated
                    00E3   1050 	C$test_hid.c$99$1$1 ==.
                    00E3   1051 	XG$updateMouseState$0$0 ==.
   05D4 22                 1052 	ret
                           1053 ;------------------------------------------------------------
                           1054 ;Allocation info for local variables in function 'joystickService'
                           1055 ;------------------------------------------------------------
                    00E4   1056 	G$joystickService$0$0 ==.
                    00E4   1057 	C$test_hid.c$101$1$1 ==.
                           1058 ;	apps/test_hid/test_hid.c:101: void joystickService()
                           1059 ;	-----------------------------------------
                           1060 ;	 function joystickService
                           1061 ;	-----------------------------------------
   05D5                    1062 _joystickService:
                    00E4   1063 	C$test_hid.c$106$1$1 ==.
                           1064 ;	apps/test_hid/test_hid.c:106: if (!param_move_joystick){ return; }
   05D5 90 17 7F           1065 	mov	dptr,#_param_move_joystick
   05D8 E4                 1066 	clr	a
   05D9 93                 1067 	movc	a,@a+dptr
   05DA FC                 1068 	mov	r4,a
   05DB 74 01              1069 	mov	a,#0x01
   05DD 93                 1070 	movc	a,@a+dptr
   05DE FD                 1071 	mov	r5,a
   05DF 74 02              1072 	mov	a,#0x02
   05E1 93                 1073 	movc	a,@a+dptr
   05E2 FE                 1074 	mov	r6,a
   05E3 74 03              1075 	mov	a,#0x03
   05E5 93                 1076 	movc	a,@a+dptr
   05E6 FF                 1077 	mov	r7,a
   05E7 EC                 1078 	mov	a,r4
   05E8 4D                 1079 	orl	a,r5
   05E9 4E                 1080 	orl	a,r6
   05EA 4F                 1081 	orl	a,r7
   05EB 70 03              1082 	jnz	00102$
   05ED 02 06 A3           1083 	ljmp	00110$
   05F0                    1084 00102$:
                    00FF   1085 	C$test_hid.c$108$1$1 ==.
                           1086 ;	apps/test_hid/test_hid.c:108: time = (uint16)getMs();
   05F0 12 12 89           1087 	lcall	_getMs
   05F3 AC 82              1088 	mov	r4,dpl
   05F5 AD 83              1089 	mov	r5,dph
                    0106   1090 	C$test_hid.c$109$1$1 ==.
                           1091 ;	apps/test_hid/test_hid.c:109: tmp = (uint8)(time >> 3);
   05F7 8C 06              1092 	mov	ar6,r4
   05F9 ED                 1093 	mov	a,r5
   05FA C4                 1094 	swap	a
   05FB 23                 1095 	rl	a
   05FC CE                 1096 	xch	a,r6
   05FD C4                 1097 	swap	a
   05FE 23                 1098 	rl	a
   05FF 54 1F              1099 	anl	a,#0x1F
   0601 6E                 1100 	xrl	a,r6
   0602 CE                 1101 	xch	a,r6
   0603 54 1F              1102 	anl	a,#0x1F
   0605 CE                 1103 	xch	a,r6
   0606 6E                 1104 	xrl	a,r6
   0607 CE                 1105 	xch	a,r6
                    0117   1106 	C$test_hid.c$111$1$1 ==.
                           1107 ;	apps/test_hid/test_hid.c:111: usbHidJoystickInput.buttons = 1 << (time >> 8 & 0xF);
   0608 8D 03              1108 	mov	ar3,r5
   060A 53 03 0F           1109 	anl	ar3,#0x0F
   060D 8B F0              1110 	mov	b,r3
   060F 05 F0              1111 	inc	b
   0611 7B 01              1112 	mov	r3,#0x01
   0613 7F 00              1113 	mov	r7,#0x00
   0615 80 06              1114 	sjmp	00116$
   0617                    1115 00115$:
   0617 EB                 1116 	mov	a,r3
   0618 2B                 1117 	add	a,r3
   0619 FB                 1118 	mov	r3,a
   061A EF                 1119 	mov	a,r7
   061B 33                 1120 	rlc	a
   061C FF                 1121 	mov	r7,a
   061D                    1122 00116$:
   061D D5 F0 F7           1123 	djnz	b,00115$
   0620 90 F0 5C           1124 	mov	dptr,#(_usbHidJoystickInput + 0x0006)
   0623 EB                 1125 	mov	a,r3
   0624 F0                 1126 	movx	@dptr,a
   0625 A3                 1127 	inc	dptr
   0626 EF                 1128 	mov	a,r7
   0627 F0                 1129 	movx	@dptr,a
                    0137   1130 	C$test_hid.c$113$1$1 ==.
                           1131 ;	apps/test_hid/test_hid.c:113: usbHidJoystickInput.x = 0;
   0628 90 F0 56           1132 	mov	dptr,#_usbHidJoystickInput
                    013A   1133 	C$test_hid.c$114$1$1 ==.
                           1134 ;	apps/test_hid/test_hid.c:114: usbHidJoystickInput.y = 0;
                    013A   1135 	C$test_hid.c$115$1$1 ==.
                           1136 ;	apps/test_hid/test_hid.c:115: usbHidJoystickInput.z = 0;
                    013A   1137 	C$test_hid.c$116$1$1 ==.
                           1138 ;	apps/test_hid/test_hid.c:116: usbHidJoystickInput.rx = 0;
   062B E4                 1139 	clr	a
   062C F0                 1140 	movx	@dptr,a
   062D 90 F0 57           1141 	mov	dptr,#(_usbHidJoystickInput + 0x0001)
   0630 F0                 1142 	movx	@dptr,a
   0631 90 F0 58           1143 	mov	dptr,#(_usbHidJoystickInput + 0x0002)
   0634 F0                 1144 	movx	@dptr,a
   0635 90 F0 59           1145 	mov	dptr,#(_usbHidJoystickInput + 0x0003)
   0638 F0                 1146 	movx	@dptr,a
                    0148   1147 	C$test_hid.c$117$1$1 ==.
                           1148 ;	apps/test_hid/test_hid.c:117: usbHidJoystickInput.ry = 0;
   0639 90 F0 5A           1149 	mov	dptr,#(_usbHidJoystickInput + 0x0004)
                    014B   1150 	C$test_hid.c$118$1$1 ==.
                           1151 ;	apps/test_hid/test_hid.c:118: usbHidJoystickInput.rz = 0;
   063C E4                 1152 	clr	a
   063D F0                 1153 	movx	@dptr,a
   063E 90 F0 5B           1154 	mov	dptr,#(_usbHidJoystickInput + 0x0005)
   0641 F0                 1155 	movx	@dptr,a
                    0151   1156 	C$test_hid.c$120$1$1 ==.
                           1157 ;	apps/test_hid/test_hid.c:120: switch(time >> 11 & 7)
   0642 ED                 1158 	mov	a,r5
   0643 C4                 1159 	swap	a
   0644 23                 1160 	rl	a
   0645 54 1F              1161 	anl	a,#0x1F
   0647 FC                 1162 	mov	r4,a
   0648 74 07              1163 	mov	a,#0x07
   064A 5C                 1164 	anl	a,r4
   064B FF                 1165 	mov	r7,a
   064C 7D 00              1166 	mov	r5,#0x00
   064E C3                 1167 	clr	c
   064F 74 05              1168 	mov	a,#0x05
   0651 9F                 1169 	subb	a,r7
   0652 E4                 1170 	clr	a
   0653 9D                 1171 	subb	a,r5
   0654 40 4B              1172 	jc	00109$
   0656 EF                 1173 	mov	a,r7
   0657 2F                 1174 	add	a,r7
   0658 2F                 1175 	add	a,r7
   0659 90 06 5D           1176 	mov	dptr,#00118$
   065C 73                 1177 	jmp	@a+dptr
   065D                    1178 00118$:
   065D 02 06 6F           1179 	ljmp	00103$
   0660 02 06 78           1180 	ljmp	00104$
   0663 02 06 81           1181 	ljmp	00105$
   0666 02 06 8A           1182 	ljmp	00106$
   0669 02 06 93           1183 	ljmp	00107$
   066C 02 06 9C           1184 	ljmp	00108$
                    017E   1185 	C$test_hid.c$122$2$3 ==.
                           1186 ;	apps/test_hid/test_hid.c:122: case 0: usbHidJoystickInput.x = tmp; break;
   066F                    1187 00103$:
   066F 8E 07              1188 	mov	ar7,r6
   0671 90 F0 56           1189 	mov	dptr,#_usbHidJoystickInput
   0674 EF                 1190 	mov	a,r7
   0675 F0                 1191 	movx	@dptr,a
                    0185   1192 	C$test_hid.c$123$2$3 ==.
                           1193 ;	apps/test_hid/test_hid.c:123: case 1: usbHidJoystickInput.y = tmp; break;
   0676 80 29              1194 	sjmp	00109$
   0678                    1195 00104$:
   0678 8E 07              1196 	mov	ar7,r6
   067A 90 F0 57           1197 	mov	dptr,#(_usbHidJoystickInput + 0x0001)
   067D EF                 1198 	mov	a,r7
   067E F0                 1199 	movx	@dptr,a
                    018E   1200 	C$test_hid.c$124$2$3 ==.
                           1201 ;	apps/test_hid/test_hid.c:124: case 2: usbHidJoystickInput.z = tmp; break;
   067F 80 20              1202 	sjmp	00109$
   0681                    1203 00105$:
   0681 8E 07              1204 	mov	ar7,r6
   0683 90 F0 58           1205 	mov	dptr,#(_usbHidJoystickInput + 0x0002)
   0686 EF                 1206 	mov	a,r7
   0687 F0                 1207 	movx	@dptr,a
                    0197   1208 	C$test_hid.c$125$2$3 ==.
                           1209 ;	apps/test_hid/test_hid.c:125: case 3: usbHidJoystickInput.rx = tmp; break;
   0688 80 17              1210 	sjmp	00109$
   068A                    1211 00106$:
   068A 8E 07              1212 	mov	ar7,r6
   068C 90 F0 59           1213 	mov	dptr,#(_usbHidJoystickInput + 0x0003)
   068F EF                 1214 	mov	a,r7
   0690 F0                 1215 	movx	@dptr,a
                    01A0   1216 	C$test_hid.c$126$2$3 ==.
                           1217 ;	apps/test_hid/test_hid.c:126: case 4: usbHidJoystickInput.ry = tmp; break;
   0691 80 0E              1218 	sjmp	00109$
   0693                    1219 00107$:
   0693 8E 07              1220 	mov	ar7,r6
   0695 90 F0 5A           1221 	mov	dptr,#(_usbHidJoystickInput + 0x0004)
   0698 EF                 1222 	mov	a,r7
   0699 F0                 1223 	movx	@dptr,a
                    01A9   1224 	C$test_hid.c$127$2$3 ==.
                           1225 ;	apps/test_hid/test_hid.c:127: case 5: usbHidJoystickInput.rz = tmp; break;
   069A 80 05              1226 	sjmp	00109$
   069C                    1227 00108$:
   069C 90 F0 5B           1228 	mov	dptr,#(_usbHidJoystickInput + 0x0005)
   069F EE                 1229 	mov	a,r6
   06A0 F0                 1230 	movx	@dptr,a
                    01B0   1231 	C$test_hid.c$128$1$1 ==.
                           1232 ;	apps/test_hid/test_hid.c:128: }
   06A1                    1233 00109$:
                    01B0   1234 	C$test_hid.c$130$1$1 ==.
                           1235 ;	apps/test_hid/test_hid.c:130: usbHidJoystickInputUpdated = 1;
   06A1 D2 03              1236 	setb	_usbHidJoystickInputUpdated
   06A3                    1237 00110$:
                    01B2   1238 	C$test_hid.c$131$1$1 ==.
                    01B2   1239 	XG$joystickService$0$0 ==.
   06A3 22                 1240 	ret
                           1241 ;------------------------------------------------------------
                           1242 ;Allocation info for local variables in function 'sendKeyCode'
                           1243 ;------------------------------------------------------------
                    01B3   1244 	G$sendKeyCode$0$0 ==.
                    01B3   1245 	C$test_hid.c$140$1$1 ==.
                           1246 ;	apps/test_hid/test_hid.c:140: void sendKeyCode(uint8 keyCode)
                           1247 ;	-----------------------------------------
                           1248 ;	 function sendKeyCode
                           1249 ;	-----------------------------------------
   06A4                    1250 _sendKeyCode:
   06A4 AF 82              1251 	mov	r7,dpl
                    01B5   1252 	C$test_hid.c$142$1$1 ==.
                           1253 ;	apps/test_hid/test_hid.c:142: lastKeyCodeSent = keyCode;
   06A6 78 00              1254 	mov	r0,#_lastKeyCodeSent
   06A8 EF                 1255 	mov	a,r7
   06A9 F2                 1256 	movx	@r0,a
                    01B9   1257 	C$test_hid.c$143$1$1 ==.
                           1258 ;	apps/test_hid/test_hid.c:143: usbHidKeyboardInput.keyCodes[0] = keyCode;
   06AA 90 F0 4C           1259 	mov	dptr,#(_usbHidKeyboardInput + 0x0002)
   06AD EF                 1260 	mov	a,r7
   06AE F0                 1261 	movx	@dptr,a
                    01BE   1262 	C$test_hid.c$146$1$1 ==.
                           1263 ;	apps/test_hid/test_hid.c:146: usbHidKeyboardInputUpdated = 1;
   06AF D2 01              1264 	setb	_usbHidKeyboardInputUpdated
                    01C0   1265 	C$test_hid.c$147$1$1 ==.
                    01C0   1266 	XG$sendKeyCode$0$0 ==.
   06B1 22                 1267 	ret
                           1268 ;------------------------------------------------------------
                           1269 ;Allocation info for local variables in function 'buttonGetSingleDebouncedPress'
                           1270 ;------------------------------------------------------------
                    01C1   1271 	G$buttonGetSingleDebouncedPress$0$0 ==.
                    01C1   1272 	C$test_hid.c$151$1$1 ==.
                           1273 ;	apps/test_hid/test_hid.c:151: BIT buttonGetSingleDebouncedPress()
                           1274 ;	-----------------------------------------
                           1275 ;	 function buttonGetSingleDebouncedPress
                           1276 ;	-----------------------------------------
   06B2                    1277 _buttonGetSingleDebouncedPress:
                    01C1   1278 	C$test_hid.c$156$1$1 ==.
                           1279 ;	apps/test_hid/test_hid.c:156: if (isPinHigh(2))
   06B2 75 82 02           1280 	mov	dpl,#0x02
   06B5 12 16 00           1281 	lcall	_isPinHigh
   06B8 50 12              1282 	jnc	00106$
                    01C9   1283 	C$test_hid.c$159$2$2 ==.
                           1284 ;	apps/test_hid/test_hid.c:159: reportedThisButtonPress = 0;
   06BA C2 00              1285 	clr	_buttonGetSingleDebouncedPress_reportedThisButtonPress_1_1
                    01CB   1286 	C$test_hid.c$160$2$2 ==.
                           1287 ;	apps/test_hid/test_hid.c:160: lastTimeButtonWasNotPressed = (uint8)getMs();
   06BC 12 12 89           1288 	lcall	_getMs
   06BF AC 82              1289 	mov	r4,dpl
   06C1 AD 83              1290 	mov	r5,dph
   06C3 AE F0              1291 	mov	r6,b
   06C5 FF                 1292 	mov	r7,a
   06C6 78 01              1293 	mov	r0,#_buttonGetSingleDebouncedPress_lastTimeButtonWasNotPressed_1_1
   06C8 EC                 1294 	mov	a,r4
   06C9 F2                 1295 	movx	@r0,a
   06CA 80 1D              1296 	sjmp	00107$
   06CC                    1297 00106$:
                    01DB   1298 	C$test_hid.c$162$1$1 ==.
                           1299 ;	apps/test_hid/test_hid.c:162: else if ((uint8)(getMs() - lastTimeButtonWasNotPressed) > 15)
   06CC 12 12 89           1300 	lcall	_getMs
   06CF AC 82              1301 	mov	r4,dpl
   06D1 AD 83              1302 	mov	r5,dph
   06D3 AE F0              1303 	mov	r6,b
   06D5 FF                 1304 	mov	r7,a
   06D6 78 01              1305 	mov	r0,#_buttonGetSingleDebouncedPress_lastTimeButtonWasNotPressed_1_1
   06D8 D3                 1306 	setb	c
   06D9 E2                 1307 	movx	a,@r0
   06DA 9C                 1308 	subb	a,r4
   06DB F4                 1309 	cpl	a
   06DC FC                 1310 	mov  r4,a
   06DD 24 F0              1311 	add	a,#0xff - 0x0F
   06DF 50 08              1312 	jnc	00107$
                    01F0   1313 	C$test_hid.c$167$2$3 ==.
                           1314 ;	apps/test_hid/test_hid.c:167: if (!reportedThisButtonPress)
   06E1 20 00 05           1315 	jb	_buttonGetSingleDebouncedPress_reportedThisButtonPress_1_1,00107$
                    01F3   1316 	C$test_hid.c$169$3$4 ==.
                           1317 ;	apps/test_hid/test_hid.c:169: reportedThisButtonPress = 1;
   06E4 D2 00              1318 	setb	_buttonGetSingleDebouncedPress_reportedThisButtonPress_1_1
                    01F5   1319 	C$test_hid.c$170$3$4 ==.
                           1320 ;	apps/test_hid/test_hid.c:170: return 1;
   06E6 D3                 1321 	setb	c
   06E7 80 01              1322 	sjmp	00108$
   06E9                    1323 00107$:
                    01F8   1324 	C$test_hid.c$173$1$1 ==.
                           1325 ;	apps/test_hid/test_hid.c:173: return 0;
   06E9 C3                 1326 	clr	c
   06EA                    1327 00108$:
                    01F9   1328 	C$test_hid.c$174$1$1 ==.
                    01F9   1329 	XG$buttonGetSingleDebouncedPress$0$0 ==.
   06EA 22                 1330 	ret
                           1331 ;------------------------------------------------------------
                           1332 ;Allocation info for local variables in function 'keyboardService'
                           1333 ;------------------------------------------------------------
                    01FA   1334 	G$keyboardService$0$0 ==.
                    01FA   1335 	C$test_hid.c$176$1$1 ==.
                           1336 ;	apps/test_hid/test_hid.c:176: void keyboardService()
                           1337 ;	-----------------------------------------
                           1338 ;	 function keyboardService
                           1339 ;	-----------------------------------------
   06EB                    1340 _keyboardService:
                    01FA   1341 	C$test_hid.c$185$1$1 ==.
                           1342 ;	apps/test_hid/test_hid.c:185: if (buttonGetSingleDebouncedPress() && charsLeftToSend == 0)
   06EB 12 06 B2           1343 	lcall	_buttonGetSingleDebouncedPress
   06EE 50 13              1344 	jnc	00102$
   06F0 78 02              1345 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   06F2 E2                 1346 	movx	a,@r0
   06F3 70 0E              1347 	jnz	00102$
                    0204   1348 	C$test_hid.c$187$2$2 ==.
                           1349 ;	apps/test_hid/test_hid.c:187: nextCharToSend = (char XDATA *)greeting;
   06F5 78 03              1350 	mov	r0,#_keyboardService_nextCharToSend_1_1
   06F7 74 83              1351 	mov	a,#_keyboardService_greeting_1_1
   06F9 F2                 1352 	movx	@r0,a
   06FA 08                 1353 	inc	r0
   06FB 74 17              1354 	mov	a,#(_keyboardService_greeting_1_1 >> 8)
   06FD F2                 1355 	movx	@r0,a
                    020D   1356 	C$test_hid.c$188$2$2 ==.
                           1357 ;	apps/test_hid/test_hid.c:188: charsLeftToSend = sizeof(greeting)-1;
   06FE 78 02              1358 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   0700 74 0C              1359 	mov	a,#0x0C
   0702 F2                 1360 	movx	@r0,a
   0703                    1361 00102$:
                    0212   1362 	C$test_hid.c$194$2$3 ==.
                           1363 ;	apps/test_hid/test_hid.c:194: LED_RED(charsLeftToSend > 0);
   0703 78 02              1364 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   0705 E2                 1365 	movx	a,@r0
   0706 60 05              1366 	jz	00117$
   0708 43 FF 02           1367 	orl	_P2DIR,#0x02
   070B 80 07              1368 	sjmp	00118$
   070D                    1369 00117$:
   070D AF FF              1370 	mov	r7,_P2DIR
   070F 53 07 FD           1371 	anl	ar7,#0xFD
   0712 8F FF              1372 	mov	_P2DIR,r7
   0714                    1373 00118$:
                    0223   1374 	C$test_hid.c$197$1$1 ==.
                           1375 ;	apps/test_hid/test_hid.c:197: if (charsLeftToSend && !usbHidKeyboardInputUpdated)
   0714 78 02              1376 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   0716 E2                 1377 	movx	a,@r0
   0717 60 36              1378 	jz	00109$
   0719 20 01 33           1379 	jb	_usbHidKeyboardInputUpdated,00109$
                    022B   1380 	C$test_hid.c$199$2$4 ==.
                           1381 ;	apps/test_hid/test_hid.c:199: uint8 keyCode = usbHidKeyCodeFromAsciiChar(*nextCharToSend);
   071C 78 03              1382 	mov	r0,#_keyboardService_nextCharToSend_1_1
   071E E2                 1383 	movx	a,@r0
   071F F5 82              1384 	mov	dpl,a
   0721 08                 1385 	inc	r0
   0722 E2                 1386 	movx	a,@r0
   0723 F5 83              1387 	mov	dph,a
   0725 E0                 1388 	movx	a,@dptr
   0726 F5 82              1389 	mov	dpl,a
   0728 12 0B 10           1390 	lcall	_usbHidKeyCodeFromAsciiChar
                    023A   1391 	C$test_hid.c$201$2$4 ==.
                           1392 ;	apps/test_hid/test_hid.c:201: if (keyCode != 0 && keyCode == lastKeyCodeSent)
   072B E5 82              1393 	mov	a,dpl
   072D FF                 1394 	mov	r7,a
   072E 60 0A              1395 	jz	00105$
   0730 78 00              1396 	mov	r0,#_lastKeyCodeSent
   0732 E2                 1397 	movx	a,@r0
   0733 B5 07 04           1398 	cjne	a,ar7,00105$
                    0245   1399 	C$test_hid.c$206$3$5 ==.
                           1400 ;	apps/test_hid/test_hid.c:206: keyCode = 0;
   0736 7F 00              1401 	mov	r7,#0x00
   0738 80 10              1402 	sjmp	00106$
   073A                    1403 00105$:
                    0249   1404 	C$test_hid.c$210$3$6 ==.
                           1405 ;	apps/test_hid/test_hid.c:210: nextCharToSend++;
   073A 78 03              1406 	mov	r0,#_keyboardService_nextCharToSend_1_1
   073C E2                 1407 	movx	a,@r0
   073D 24 01              1408 	add	a,#0x01
   073F F2                 1409 	movx	@r0,a
   0740 08                 1410 	inc	r0
   0741 E2                 1411 	movx	a,@r0
   0742 34 00              1412 	addc	a,#0x00
   0744 F2                 1413 	movx	@r0,a
                    0254   1414 	C$test_hid.c$211$3$6 ==.
                           1415 ;	apps/test_hid/test_hid.c:211: charsLeftToSend--;
   0745 78 02              1416 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   0747 E2                 1417 	movx	a,@r0
   0748 14                 1418 	dec	a
   0749 F2                 1419 	movx	@r0,a
   074A                    1420 00106$:
                    0259   1421 	C$test_hid.c$214$2$4 ==.
                           1422 ;	apps/test_hid/test_hid.c:214: sendKeyCode(keyCode);
   074A 8F 82              1423 	mov	dpl,r7
   074C 12 06 A4           1424 	lcall	_sendKeyCode
   074F                    1425 00109$:
                    025E   1426 	C$test_hid.c$218$1$1 ==.
                           1427 ;	apps/test_hid/test_hid.c:218: if (charsLeftToSend == 0 && lastKeyCodeSent != 0 && !usbHidKeyboardInputUpdated)
   074F 78 02              1428 	mov	r0,#_keyboardService_charsLeftToSend_1_1
   0751 E2                 1429 	movx	a,@r0
   0752 70 0E              1430 	jnz	00115$
   0754 78 00              1431 	mov	r0,#_lastKeyCodeSent
   0756 E2                 1432 	movx	a,@r0
   0757 60 09              1433 	jz	00115$
   0759 20 01 06           1434 	jb	_usbHidKeyboardInputUpdated,00115$
                    026B   1435 	C$test_hid.c$220$2$7 ==.
                           1436 ;	apps/test_hid/test_hid.c:220: sendKeyCode(0);
   075C 75 82 00           1437 	mov	dpl,#0x00
   075F 12 06 A4           1438 	lcall	_sendKeyCode
   0762                    1439 00115$:
                    0271   1440 	C$test_hid.c$222$2$1 ==.
                    0271   1441 	XG$keyboardService$0$0 ==.
   0762 22                 1442 	ret
                           1443 ;------------------------------------------------------------
                           1444 ;Allocation info for local variables in function 'main'
                           1445 ;------------------------------------------------------------
                    0272   1446 	G$main$0$0 ==.
                    0272   1447 	C$test_hid.c$224$2$1 ==.
                           1448 ;	apps/test_hid/test_hid.c:224: void main()
                           1449 ;	-----------------------------------------
                           1450 ;	 function main
                           1451 ;	-----------------------------------------
   0763                    1452 _main:
                    0272   1453 	C$test_hid.c$226$1$1 ==.
                           1454 ;	apps/test_hid/test_hid.c:226: systemInit();
   0763 12 11 89           1455 	lcall	_systemInit
                    0275   1456 	C$test_hid.c$227$1$1 ==.
                           1457 ;	apps/test_hid/test_hid.c:227: usbInit();
   0766 12 0B 23           1458 	lcall	_usbInit
                    0278   1459 	C$test_hid.c$229$1$1 ==.
                           1460 ;	apps/test_hid/test_hid.c:229: while(1)
   0769                    1461 00102$:
                    0278   1462 	C$test_hid.c$231$2$2 ==.
                           1463 ;	apps/test_hid/test_hid.c:231: updateLeds();
   0769 12 04 F1           1464 	lcall	_updateLeds
                    027B   1465 	C$test_hid.c$232$2$2 ==.
                           1466 ;	apps/test_hid/test_hid.c:232: boardService();
   076C 12 11 96           1467 	lcall	_boardService
                    027E   1468 	C$test_hid.c$233$2$2 ==.
                           1469 ;	apps/test_hid/test_hid.c:233: usbHidService();
   076F 12 0A 1F           1470 	lcall	_usbHidService
                    0281   1471 	C$test_hid.c$234$2$2 ==.
                           1472 ;	apps/test_hid/test_hid.c:234: updateMouseState();
   0772 12 05 09           1473 	lcall	_updateMouseState
                    0284   1474 	C$test_hid.c$235$2$2 ==.
                           1475 ;	apps/test_hid/test_hid.c:235: keyboardService();
   0775 12 06 EB           1476 	lcall	_keyboardService
                    0287   1477 	C$test_hid.c$236$2$2 ==.
                           1478 ;	apps/test_hid/test_hid.c:236: joystickService();
   0778 12 05 D5           1479 	lcall	_joystickService
   077B 80 EC              1480 	sjmp	00102$
                    028C   1481 	C$test_hid.c$238$1$1 ==.
                    028C   1482 	XG$main$0$0 ==.
   077D 22                 1483 	ret
                           1484 	.area CSEG    (CODE)
                           1485 	.area CONST   (CODE)
                    0000   1486 G$param_move_cursor$0$0 == .
   1777                    1487 _param_move_cursor:
   1777 00 00 00 00        1488 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   1489 G$param_move_mouse_wheel$0$0 == .
   177B                    1490 _param_move_mouse_wheel:
   177B 00 00 00 00        1491 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0008   1492 G$param_move_joystick$0$0 == .
   177F                    1493 _param_move_joystick:
   177F 00 00 00 00        1494 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    000C   1495 Ltest_hid.keyboardService$greeting$1$1 == .
   1783                    1496 _keyboardService_greeting_1_1:
   1783 68 65 6C 6C 6F 20  1497 	.ascii "hello world "
        77 6F 72 6C 64 20
   178F 00                 1498 	.db 0x00
                           1499 	.area XINIT   (CODE)
                           1500 	.area CABS    (ABS,CODE)
