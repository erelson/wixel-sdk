                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:46 2012
                              5 ;--------------------------------------------------------
                              6 	.module example_servo_sequence
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _pins
                             13 	.globl _main
                             14 	.globl _usbComRxReceiveByteBlocking
                             15 	.globl _servosWaitWhileMoving
                             16 	.globl _waitMs
                             17 	.globl _usbComService
                             18 	.globl _usbShowStatusWithGreenLed
                             19 	.globl _usbInit
                             20 	.globl _isPinHigh
                             21 	.globl _boardService
                             22 	.globl _systemInit
                             23 	.globl _servoSetSpeed
                             24 	.globl _servoSetTarget
                             25 	.globl _servosStart
                             26 	.globl _frequentTasks
                             27 	.globl _loop
                             28 	.globl _loop_sequence_triggered_by_usb
                             29 	.globl _loop_sequence_triggered_by_digital_input
                             30 ;--------------------------------------------------------
                             31 ; special function registers
                             32 ;--------------------------------------------------------
                             33 	.area RSEG    (ABS,DATA)
   0000                      34 	.org 0x0000
                    0080     35 Fexample_servo_sequence$P0$0$0 == 0x0080
                    0080     36 _P0	=	0x0080
                    0081     37 Fexample_servo_sequence$SP$0$0 == 0x0081
                    0081     38 _SP	=	0x0081
                    0082     39 Fexample_servo_sequence$DPL0$0$0 == 0x0082
                    0082     40 _DPL0	=	0x0082
                    0083     41 Fexample_servo_sequence$DPH0$0$0 == 0x0083
                    0083     42 _DPH0	=	0x0083
                    0084     43 Fexample_servo_sequence$DPL1$0$0 == 0x0084
                    0084     44 _DPL1	=	0x0084
                    0085     45 Fexample_servo_sequence$DPH1$0$0 == 0x0085
                    0085     46 _DPH1	=	0x0085
                    0086     47 Fexample_servo_sequence$U0CSR$0$0 == 0x0086
                    0086     48 _U0CSR	=	0x0086
                    0087     49 Fexample_servo_sequence$PCON$0$0 == 0x0087
                    0087     50 _PCON	=	0x0087
                    0088     51 Fexample_servo_sequence$TCON$0$0 == 0x0088
                    0088     52 _TCON	=	0x0088
                    0089     53 Fexample_servo_sequence$P0IFG$0$0 == 0x0089
                    0089     54 _P0IFG	=	0x0089
                    008A     55 Fexample_servo_sequence$P1IFG$0$0 == 0x008a
                    008A     56 _P1IFG	=	0x008a
                    008B     57 Fexample_servo_sequence$P2IFG$0$0 == 0x008b
                    008B     58 _P2IFG	=	0x008b
                    008C     59 Fexample_servo_sequence$PICTL$0$0 == 0x008c
                    008C     60 _PICTL	=	0x008c
                    008D     61 Fexample_servo_sequence$P1IEN$0$0 == 0x008d
                    008D     62 _P1IEN	=	0x008d
                    008F     63 Fexample_servo_sequence$P0INP$0$0 == 0x008f
                    008F     64 _P0INP	=	0x008f
                    0090     65 Fexample_servo_sequence$P1$0$0 == 0x0090
                    0090     66 _P1	=	0x0090
                    0091     67 Fexample_servo_sequence$RFIM$0$0 == 0x0091
                    0091     68 _RFIM	=	0x0091
                    0092     69 Fexample_servo_sequence$DPS$0$0 == 0x0092
                    0092     70 _DPS	=	0x0092
                    0093     71 Fexample_servo_sequence$MPAGE$0$0 == 0x0093
                    0093     72 _MPAGE	=	0x0093
                    0095     73 Fexample_servo_sequence$ENDIAN$0$0 == 0x0095
                    0095     74 _ENDIAN	=	0x0095
                    0098     75 Fexample_servo_sequence$S0CON$0$0 == 0x0098
                    0098     76 _S0CON	=	0x0098
                    009A     77 Fexample_servo_sequence$IEN2$0$0 == 0x009a
                    009A     78 _IEN2	=	0x009a
                    009B     79 Fexample_servo_sequence$S1CON$0$0 == 0x009b
                    009B     80 _S1CON	=	0x009b
                    009C     81 Fexample_servo_sequence$T2CT$0$0 == 0x009c
                    009C     82 _T2CT	=	0x009c
                    009D     83 Fexample_servo_sequence$T2PR$0$0 == 0x009d
                    009D     84 _T2PR	=	0x009d
                    009E     85 Fexample_servo_sequence$T2CTL$0$0 == 0x009e
                    009E     86 _T2CTL	=	0x009e
                    00A0     87 Fexample_servo_sequence$P2$0$0 == 0x00a0
                    00A0     88 _P2	=	0x00a0
                    00A1     89 Fexample_servo_sequence$WORIRQ$0$0 == 0x00a1
                    00A1     90 _WORIRQ	=	0x00a1
                    00A2     91 Fexample_servo_sequence$WORCTRL$0$0 == 0x00a2
                    00A2     92 _WORCTRL	=	0x00a2
                    00A3     93 Fexample_servo_sequence$WOREVT0$0$0 == 0x00a3
                    00A3     94 _WOREVT0	=	0x00a3
                    00A4     95 Fexample_servo_sequence$WOREVT1$0$0 == 0x00a4
                    00A4     96 _WOREVT1	=	0x00a4
                    00A5     97 Fexample_servo_sequence$WORTIME0$0$0 == 0x00a5
                    00A5     98 _WORTIME0	=	0x00a5
                    00A6     99 Fexample_servo_sequence$WORTIME1$0$0 == 0x00a6
                    00A6    100 _WORTIME1	=	0x00a6
                    00A8    101 Fexample_servo_sequence$IEN0$0$0 == 0x00a8
                    00A8    102 _IEN0	=	0x00a8
                    00A9    103 Fexample_servo_sequence$IP0$0$0 == 0x00a9
                    00A9    104 _IP0	=	0x00a9
                    00AB    105 Fexample_servo_sequence$FWT$0$0 == 0x00ab
                    00AB    106 _FWT	=	0x00ab
                    00AC    107 Fexample_servo_sequence$FADDRL$0$0 == 0x00ac
                    00AC    108 _FADDRL	=	0x00ac
                    00AD    109 Fexample_servo_sequence$FADDRH$0$0 == 0x00ad
                    00AD    110 _FADDRH	=	0x00ad
                    00AE    111 Fexample_servo_sequence$FCTL$0$0 == 0x00ae
                    00AE    112 _FCTL	=	0x00ae
                    00AF    113 Fexample_servo_sequence$FWDATA$0$0 == 0x00af
                    00AF    114 _FWDATA	=	0x00af
                    00B1    115 Fexample_servo_sequence$ENCDI$0$0 == 0x00b1
                    00B1    116 _ENCDI	=	0x00b1
                    00B2    117 Fexample_servo_sequence$ENCDO$0$0 == 0x00b2
                    00B2    118 _ENCDO	=	0x00b2
                    00B3    119 Fexample_servo_sequence$ENCCS$0$0 == 0x00b3
                    00B3    120 _ENCCS	=	0x00b3
                    00B4    121 Fexample_servo_sequence$ADCCON1$0$0 == 0x00b4
                    00B4    122 _ADCCON1	=	0x00b4
                    00B5    123 Fexample_servo_sequence$ADCCON2$0$0 == 0x00b5
                    00B5    124 _ADCCON2	=	0x00b5
                    00B6    125 Fexample_servo_sequence$ADCCON3$0$0 == 0x00b6
                    00B6    126 _ADCCON3	=	0x00b6
                    00B8    127 Fexample_servo_sequence$IEN1$0$0 == 0x00b8
                    00B8    128 _IEN1	=	0x00b8
                    00B9    129 Fexample_servo_sequence$IP1$0$0 == 0x00b9
                    00B9    130 _IP1	=	0x00b9
                    00BA    131 Fexample_servo_sequence$ADCL$0$0 == 0x00ba
                    00BA    132 _ADCL	=	0x00ba
                    00BB    133 Fexample_servo_sequence$ADCH$0$0 == 0x00bb
                    00BB    134 _ADCH	=	0x00bb
                    00BC    135 Fexample_servo_sequence$RNDL$0$0 == 0x00bc
                    00BC    136 _RNDL	=	0x00bc
                    00BD    137 Fexample_servo_sequence$RNDH$0$0 == 0x00bd
                    00BD    138 _RNDH	=	0x00bd
                    00BE    139 Fexample_servo_sequence$SLEEP$0$0 == 0x00be
                    00BE    140 _SLEEP	=	0x00be
                    00C0    141 Fexample_servo_sequence$IRCON$0$0 == 0x00c0
                    00C0    142 _IRCON	=	0x00c0
                    00C1    143 Fexample_servo_sequence$U0DBUF$0$0 == 0x00c1
                    00C1    144 _U0DBUF	=	0x00c1
                    00C2    145 Fexample_servo_sequence$U0BAUD$0$0 == 0x00c2
                    00C2    146 _U0BAUD	=	0x00c2
                    00C4    147 Fexample_servo_sequence$U0UCR$0$0 == 0x00c4
                    00C4    148 _U0UCR	=	0x00c4
                    00C5    149 Fexample_servo_sequence$U0GCR$0$0 == 0x00c5
                    00C5    150 _U0GCR	=	0x00c5
                    00C6    151 Fexample_servo_sequence$CLKCON$0$0 == 0x00c6
                    00C6    152 _CLKCON	=	0x00c6
                    00C7    153 Fexample_servo_sequence$MEMCTR$0$0 == 0x00c7
                    00C7    154 _MEMCTR	=	0x00c7
                    00C9    155 Fexample_servo_sequence$WDCTL$0$0 == 0x00c9
                    00C9    156 _WDCTL	=	0x00c9
                    00CA    157 Fexample_servo_sequence$T3CNT$0$0 == 0x00ca
                    00CA    158 _T3CNT	=	0x00ca
                    00CB    159 Fexample_servo_sequence$T3CTL$0$0 == 0x00cb
                    00CB    160 _T3CTL	=	0x00cb
                    00CC    161 Fexample_servo_sequence$T3CCTL0$0$0 == 0x00cc
                    00CC    162 _T3CCTL0	=	0x00cc
                    00CD    163 Fexample_servo_sequence$T3CC0$0$0 == 0x00cd
                    00CD    164 _T3CC0	=	0x00cd
                    00CE    165 Fexample_servo_sequence$T3CCTL1$0$0 == 0x00ce
                    00CE    166 _T3CCTL1	=	0x00ce
                    00CF    167 Fexample_servo_sequence$T3CC1$0$0 == 0x00cf
                    00CF    168 _T3CC1	=	0x00cf
                    00D0    169 Fexample_servo_sequence$PSW$0$0 == 0x00d0
                    00D0    170 _PSW	=	0x00d0
                    00D1    171 Fexample_servo_sequence$DMAIRQ$0$0 == 0x00d1
                    00D1    172 _DMAIRQ	=	0x00d1
                    00D2    173 Fexample_servo_sequence$DMA1CFGL$0$0 == 0x00d2
                    00D2    174 _DMA1CFGL	=	0x00d2
                    00D3    175 Fexample_servo_sequence$DMA1CFGH$0$0 == 0x00d3
                    00D3    176 _DMA1CFGH	=	0x00d3
                    00D4    177 Fexample_servo_sequence$DMA0CFGL$0$0 == 0x00d4
                    00D4    178 _DMA0CFGL	=	0x00d4
                    00D5    179 Fexample_servo_sequence$DMA0CFGH$0$0 == 0x00d5
                    00D5    180 _DMA0CFGH	=	0x00d5
                    00D6    181 Fexample_servo_sequence$DMAARM$0$0 == 0x00d6
                    00D6    182 _DMAARM	=	0x00d6
                    00D7    183 Fexample_servo_sequence$DMAREQ$0$0 == 0x00d7
                    00D7    184 _DMAREQ	=	0x00d7
                    00D8    185 Fexample_servo_sequence$TIMIF$0$0 == 0x00d8
                    00D8    186 _TIMIF	=	0x00d8
                    00D9    187 Fexample_servo_sequence$RFD$0$0 == 0x00d9
                    00D9    188 _RFD	=	0x00d9
                    00DA    189 Fexample_servo_sequence$T1CC0L$0$0 == 0x00da
                    00DA    190 _T1CC0L	=	0x00da
                    00DB    191 Fexample_servo_sequence$T1CC0H$0$0 == 0x00db
                    00DB    192 _T1CC0H	=	0x00db
                    00DC    193 Fexample_servo_sequence$T1CC1L$0$0 == 0x00dc
                    00DC    194 _T1CC1L	=	0x00dc
                    00DD    195 Fexample_servo_sequence$T1CC1H$0$0 == 0x00dd
                    00DD    196 _T1CC1H	=	0x00dd
                    00DE    197 Fexample_servo_sequence$T1CC2L$0$0 == 0x00de
                    00DE    198 _T1CC2L	=	0x00de
                    00DF    199 Fexample_servo_sequence$T1CC2H$0$0 == 0x00df
                    00DF    200 _T1CC2H	=	0x00df
                    00E0    201 Fexample_servo_sequence$ACC$0$0 == 0x00e0
                    00E0    202 _ACC	=	0x00e0
                    00E1    203 Fexample_servo_sequence$RFST$0$0 == 0x00e1
                    00E1    204 _RFST	=	0x00e1
                    00E2    205 Fexample_servo_sequence$T1CNTL$0$0 == 0x00e2
                    00E2    206 _T1CNTL	=	0x00e2
                    00E3    207 Fexample_servo_sequence$T1CNTH$0$0 == 0x00e3
                    00E3    208 _T1CNTH	=	0x00e3
                    00E4    209 Fexample_servo_sequence$T1CTL$0$0 == 0x00e4
                    00E4    210 _T1CTL	=	0x00e4
                    00E5    211 Fexample_servo_sequence$T1CCTL0$0$0 == 0x00e5
                    00E5    212 _T1CCTL0	=	0x00e5
                    00E6    213 Fexample_servo_sequence$T1CCTL1$0$0 == 0x00e6
                    00E6    214 _T1CCTL1	=	0x00e6
                    00E7    215 Fexample_servo_sequence$T1CCTL2$0$0 == 0x00e7
                    00E7    216 _T1CCTL2	=	0x00e7
                    00E8    217 Fexample_servo_sequence$IRCON2$0$0 == 0x00e8
                    00E8    218 _IRCON2	=	0x00e8
                    00E9    219 Fexample_servo_sequence$RFIF$0$0 == 0x00e9
                    00E9    220 _RFIF	=	0x00e9
                    00EA    221 Fexample_servo_sequence$T4CNT$0$0 == 0x00ea
                    00EA    222 _T4CNT	=	0x00ea
                    00EB    223 Fexample_servo_sequence$T4CTL$0$0 == 0x00eb
                    00EB    224 _T4CTL	=	0x00eb
                    00EC    225 Fexample_servo_sequence$T4CCTL0$0$0 == 0x00ec
                    00EC    226 _T4CCTL0	=	0x00ec
                    00ED    227 Fexample_servo_sequence$T4CC0$0$0 == 0x00ed
                    00ED    228 _T4CC0	=	0x00ed
                    00EE    229 Fexample_servo_sequence$T4CCTL1$0$0 == 0x00ee
                    00EE    230 _T4CCTL1	=	0x00ee
                    00EF    231 Fexample_servo_sequence$T4CC1$0$0 == 0x00ef
                    00EF    232 _T4CC1	=	0x00ef
                    00F0    233 Fexample_servo_sequence$B$0$0 == 0x00f0
                    00F0    234 _B	=	0x00f0
                    00F1    235 Fexample_servo_sequence$PERCFG$0$0 == 0x00f1
                    00F1    236 _PERCFG	=	0x00f1
                    00F2    237 Fexample_servo_sequence$ADCCFG$0$0 == 0x00f2
                    00F2    238 _ADCCFG	=	0x00f2
                    00F3    239 Fexample_servo_sequence$P0SEL$0$0 == 0x00f3
                    00F3    240 _P0SEL	=	0x00f3
                    00F4    241 Fexample_servo_sequence$P1SEL$0$0 == 0x00f4
                    00F4    242 _P1SEL	=	0x00f4
                    00F5    243 Fexample_servo_sequence$P2SEL$0$0 == 0x00f5
                    00F5    244 _P2SEL	=	0x00f5
                    00F6    245 Fexample_servo_sequence$P1INP$0$0 == 0x00f6
                    00F6    246 _P1INP	=	0x00f6
                    00F7    247 Fexample_servo_sequence$P2INP$0$0 == 0x00f7
                    00F7    248 _P2INP	=	0x00f7
                    00F8    249 Fexample_servo_sequence$U1CSR$0$0 == 0x00f8
                    00F8    250 _U1CSR	=	0x00f8
                    00F9    251 Fexample_servo_sequence$U1DBUF$0$0 == 0x00f9
                    00F9    252 _U1DBUF	=	0x00f9
                    00FA    253 Fexample_servo_sequence$U1BAUD$0$0 == 0x00fa
                    00FA    254 _U1BAUD	=	0x00fa
                    00FB    255 Fexample_servo_sequence$U1UCR$0$0 == 0x00fb
                    00FB    256 _U1UCR	=	0x00fb
                    00FC    257 Fexample_servo_sequence$U1GCR$0$0 == 0x00fc
                    00FC    258 _U1GCR	=	0x00fc
                    00FD    259 Fexample_servo_sequence$P0DIR$0$0 == 0x00fd
                    00FD    260 _P0DIR	=	0x00fd
                    00FE    261 Fexample_servo_sequence$P1DIR$0$0 == 0x00fe
                    00FE    262 _P1DIR	=	0x00fe
                    00FF    263 Fexample_servo_sequence$P2DIR$0$0 == 0x00ff
                    00FF    264 _P2DIR	=	0x00ff
                    FFFFD5D4    265 Fexample_servo_sequence$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    266 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    267 Fexample_servo_sequence$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    268 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    269 Fexample_servo_sequence$FADDR$0$0 == 0xffffadac
                    FFFFADAC    270 _FADDR	=	0xffffadac
                    FFFFBBBA    271 Fexample_servo_sequence$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    272 _ADC	=	0xffffbbba
                    FFFFDBDA    273 Fexample_servo_sequence$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    274 _T1CC0	=	0xffffdbda
                    FFFFDDDC    275 Fexample_servo_sequence$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    276 _T1CC1	=	0xffffdddc
                    FFFFDFDE    277 Fexample_servo_sequence$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    278 _T1CC2	=	0xffffdfde
                            279 ;--------------------------------------------------------
                            280 ; special function bits
                            281 ;--------------------------------------------------------
                            282 	.area RSEG    (ABS,DATA)
   0000                     283 	.org 0x0000
                    0080    284 Fexample_servo_sequence$P0_0$0$0 == 0x0080
                    0080    285 _P0_0	=	0x0080
                    0081    286 Fexample_servo_sequence$P0_1$0$0 == 0x0081
                    0081    287 _P0_1	=	0x0081
                    0082    288 Fexample_servo_sequence$P0_2$0$0 == 0x0082
                    0082    289 _P0_2	=	0x0082
                    0083    290 Fexample_servo_sequence$P0_3$0$0 == 0x0083
                    0083    291 _P0_3	=	0x0083
                    0084    292 Fexample_servo_sequence$P0_4$0$0 == 0x0084
                    0084    293 _P0_4	=	0x0084
                    0085    294 Fexample_servo_sequence$P0_5$0$0 == 0x0085
                    0085    295 _P0_5	=	0x0085
                    0086    296 Fexample_servo_sequence$P0_6$0$0 == 0x0086
                    0086    297 _P0_6	=	0x0086
                    0087    298 Fexample_servo_sequence$P0_7$0$0 == 0x0087
                    0087    299 _P0_7	=	0x0087
                    0088    300 Fexample_servo_sequence$_TCON_0$0$0 == 0x0088
                    0088    301 __TCON_0	=	0x0088
                    0089    302 Fexample_servo_sequence$RFTXRXIF$0$0 == 0x0089
                    0089    303 _RFTXRXIF	=	0x0089
                    008A    304 Fexample_servo_sequence$_TCON_2$0$0 == 0x008a
                    008A    305 __TCON_2	=	0x008a
                    008B    306 Fexample_servo_sequence$URX0IF$0$0 == 0x008b
                    008B    307 _URX0IF	=	0x008b
                    008C    308 Fexample_servo_sequence$_TCON_4$0$0 == 0x008c
                    008C    309 __TCON_4	=	0x008c
                    008D    310 Fexample_servo_sequence$ADCIF$0$0 == 0x008d
                    008D    311 _ADCIF	=	0x008d
                    008E    312 Fexample_servo_sequence$_TCON_6$0$0 == 0x008e
                    008E    313 __TCON_6	=	0x008e
                    008F    314 Fexample_servo_sequence$URX1IF$0$0 == 0x008f
                    008F    315 _URX1IF	=	0x008f
                    0090    316 Fexample_servo_sequence$P1_0$0$0 == 0x0090
                    0090    317 _P1_0	=	0x0090
                    0091    318 Fexample_servo_sequence$P1_1$0$0 == 0x0091
                    0091    319 _P1_1	=	0x0091
                    0092    320 Fexample_servo_sequence$P1_2$0$0 == 0x0092
                    0092    321 _P1_2	=	0x0092
                    0093    322 Fexample_servo_sequence$P1_3$0$0 == 0x0093
                    0093    323 _P1_3	=	0x0093
                    0094    324 Fexample_servo_sequence$P1_4$0$0 == 0x0094
                    0094    325 _P1_4	=	0x0094
                    0095    326 Fexample_servo_sequence$P1_5$0$0 == 0x0095
                    0095    327 _P1_5	=	0x0095
                    0096    328 Fexample_servo_sequence$P1_6$0$0 == 0x0096
                    0096    329 _P1_6	=	0x0096
                    0097    330 Fexample_servo_sequence$P1_7$0$0 == 0x0097
                    0097    331 _P1_7	=	0x0097
                    0098    332 Fexample_servo_sequence$ENCIF_0$0$0 == 0x0098
                    0098    333 _ENCIF_0	=	0x0098
                    0099    334 Fexample_servo_sequence$ENCIF_1$0$0 == 0x0099
                    0099    335 _ENCIF_1	=	0x0099
                    009A    336 Fexample_servo_sequence$_SOCON2$0$0 == 0x009a
                    009A    337 __SOCON2	=	0x009a
                    009B    338 Fexample_servo_sequence$_SOCON3$0$0 == 0x009b
                    009B    339 __SOCON3	=	0x009b
                    009C    340 Fexample_servo_sequence$_SOCON4$0$0 == 0x009c
                    009C    341 __SOCON4	=	0x009c
                    009D    342 Fexample_servo_sequence$_SOCON5$0$0 == 0x009d
                    009D    343 __SOCON5	=	0x009d
                    009E    344 Fexample_servo_sequence$_SOCON6$0$0 == 0x009e
                    009E    345 __SOCON6	=	0x009e
                    009F    346 Fexample_servo_sequence$_SOCON7$0$0 == 0x009f
                    009F    347 __SOCON7	=	0x009f
                    00A0    348 Fexample_servo_sequence$P2_0$0$0 == 0x00a0
                    00A0    349 _P2_0	=	0x00a0
                    00A1    350 Fexample_servo_sequence$P2_1$0$0 == 0x00a1
                    00A1    351 _P2_1	=	0x00a1
                    00A2    352 Fexample_servo_sequence$P2_2$0$0 == 0x00a2
                    00A2    353 _P2_2	=	0x00a2
                    00A3    354 Fexample_servo_sequence$P2_3$0$0 == 0x00a3
                    00A3    355 _P2_3	=	0x00a3
                    00A4    356 Fexample_servo_sequence$P2_4$0$0 == 0x00a4
                    00A4    357 _P2_4	=	0x00a4
                    00A5    358 Fexample_servo_sequence$P2_5$0$0 == 0x00a5
                    00A5    359 _P2_5	=	0x00a5
                    00A6    360 Fexample_servo_sequence$P2_6$0$0 == 0x00a6
                    00A6    361 _P2_6	=	0x00a6
                    00A7    362 Fexample_servo_sequence$P2_7$0$0 == 0x00a7
                    00A7    363 _P2_7	=	0x00a7
                    00A8    364 Fexample_servo_sequence$RFTXRXIE$0$0 == 0x00a8
                    00A8    365 _RFTXRXIE	=	0x00a8
                    00A9    366 Fexample_servo_sequence$ADCIE$0$0 == 0x00a9
                    00A9    367 _ADCIE	=	0x00a9
                    00AA    368 Fexample_servo_sequence$URX0IE$0$0 == 0x00aa
                    00AA    369 _URX0IE	=	0x00aa
                    00AB    370 Fexample_servo_sequence$URX1IE$0$0 == 0x00ab
                    00AB    371 _URX1IE	=	0x00ab
                    00AC    372 Fexample_servo_sequence$ENCIE$0$0 == 0x00ac
                    00AC    373 _ENCIE	=	0x00ac
                    00AD    374 Fexample_servo_sequence$STIE$0$0 == 0x00ad
                    00AD    375 _STIE	=	0x00ad
                    00AE    376 Fexample_servo_sequence$_IEN06$0$0 == 0x00ae
                    00AE    377 __IEN06	=	0x00ae
                    00AF    378 Fexample_servo_sequence$EA$0$0 == 0x00af
                    00AF    379 _EA	=	0x00af
                    00B8    380 Fexample_servo_sequence$DMAIE$0$0 == 0x00b8
                    00B8    381 _DMAIE	=	0x00b8
                    00B9    382 Fexample_servo_sequence$T1IE$0$0 == 0x00b9
                    00B9    383 _T1IE	=	0x00b9
                    00BA    384 Fexample_servo_sequence$T2IE$0$0 == 0x00ba
                    00BA    385 _T2IE	=	0x00ba
                    00BB    386 Fexample_servo_sequence$T3IE$0$0 == 0x00bb
                    00BB    387 _T3IE	=	0x00bb
                    00BC    388 Fexample_servo_sequence$T4IE$0$0 == 0x00bc
                    00BC    389 _T4IE	=	0x00bc
                    00BD    390 Fexample_servo_sequence$P0IE$0$0 == 0x00bd
                    00BD    391 _P0IE	=	0x00bd
                    00BE    392 Fexample_servo_sequence$_IEN16$0$0 == 0x00be
                    00BE    393 __IEN16	=	0x00be
                    00BF    394 Fexample_servo_sequence$_IEN17$0$0 == 0x00bf
                    00BF    395 __IEN17	=	0x00bf
                    00C0    396 Fexample_servo_sequence$DMAIF$0$0 == 0x00c0
                    00C0    397 _DMAIF	=	0x00c0
                    00C1    398 Fexample_servo_sequence$T1IF$0$0 == 0x00c1
                    00C1    399 _T1IF	=	0x00c1
                    00C2    400 Fexample_servo_sequence$T2IF$0$0 == 0x00c2
                    00C2    401 _T2IF	=	0x00c2
                    00C3    402 Fexample_servo_sequence$T3IF$0$0 == 0x00c3
                    00C3    403 _T3IF	=	0x00c3
                    00C4    404 Fexample_servo_sequence$T4IF$0$0 == 0x00c4
                    00C4    405 _T4IF	=	0x00c4
                    00C5    406 Fexample_servo_sequence$P0IF$0$0 == 0x00c5
                    00C5    407 _P0IF	=	0x00c5
                    00C6    408 Fexample_servo_sequence$_IRCON6$0$0 == 0x00c6
                    00C6    409 __IRCON6	=	0x00c6
                    00C7    410 Fexample_servo_sequence$STIF$0$0 == 0x00c7
                    00C7    411 _STIF	=	0x00c7
                    00D0    412 Fexample_servo_sequence$P$0$0 == 0x00d0
                    00D0    413 _P	=	0x00d0
                    00D1    414 Fexample_servo_sequence$F1$0$0 == 0x00d1
                    00D1    415 _F1	=	0x00d1
                    00D2    416 Fexample_servo_sequence$OV$0$0 == 0x00d2
                    00D2    417 _OV	=	0x00d2
                    00D3    418 Fexample_servo_sequence$RS0$0$0 == 0x00d3
                    00D3    419 _RS0	=	0x00d3
                    00D4    420 Fexample_servo_sequence$RS1$0$0 == 0x00d4
                    00D4    421 _RS1	=	0x00d4
                    00D5    422 Fexample_servo_sequence$F0$0$0 == 0x00d5
                    00D5    423 _F0	=	0x00d5
                    00D6    424 Fexample_servo_sequence$AC$0$0 == 0x00d6
                    00D6    425 _AC	=	0x00d6
                    00D7    426 Fexample_servo_sequence$CY$0$0 == 0x00d7
                    00D7    427 _CY	=	0x00d7
                    00D8    428 Fexample_servo_sequence$T3OVFIF$0$0 == 0x00d8
                    00D8    429 _T3OVFIF	=	0x00d8
                    00D9    430 Fexample_servo_sequence$T3CH0IF$0$0 == 0x00d9
                    00D9    431 _T3CH0IF	=	0x00d9
                    00DA    432 Fexample_servo_sequence$T3CH1IF$0$0 == 0x00da
                    00DA    433 _T3CH1IF	=	0x00da
                    00DB    434 Fexample_servo_sequence$T4OVFIF$0$0 == 0x00db
                    00DB    435 _T4OVFIF	=	0x00db
                    00DC    436 Fexample_servo_sequence$T4CH0IF$0$0 == 0x00dc
                    00DC    437 _T4CH0IF	=	0x00dc
                    00DD    438 Fexample_servo_sequence$T4CH1IF$0$0 == 0x00dd
                    00DD    439 _T4CH1IF	=	0x00dd
                    00DE    440 Fexample_servo_sequence$OVFIM$0$0 == 0x00de
                    00DE    441 _OVFIM	=	0x00de
                    00DF    442 Fexample_servo_sequence$_TIMIF7$0$0 == 0x00df
                    00DF    443 __TIMIF7	=	0x00df
                    00E0    444 Fexample_servo_sequence$ACC_0$0$0 == 0x00e0
                    00E0    445 _ACC_0	=	0x00e0
                    00E1    446 Fexample_servo_sequence$ACC_1$0$0 == 0x00e1
                    00E1    447 _ACC_1	=	0x00e1
                    00E2    448 Fexample_servo_sequence$ACC_2$0$0 == 0x00e2
                    00E2    449 _ACC_2	=	0x00e2
                    00E3    450 Fexample_servo_sequence$ACC_3$0$0 == 0x00e3
                    00E3    451 _ACC_3	=	0x00e3
                    00E4    452 Fexample_servo_sequence$ACC_4$0$0 == 0x00e4
                    00E4    453 _ACC_4	=	0x00e4
                    00E5    454 Fexample_servo_sequence$ACC_5$0$0 == 0x00e5
                    00E5    455 _ACC_5	=	0x00e5
                    00E6    456 Fexample_servo_sequence$ACC_6$0$0 == 0x00e6
                    00E6    457 _ACC_6	=	0x00e6
                    00E7    458 Fexample_servo_sequence$ACC_7$0$0 == 0x00e7
                    00E7    459 _ACC_7	=	0x00e7
                    00E8    460 Fexample_servo_sequence$P2IF$0$0 == 0x00e8
                    00E8    461 _P2IF	=	0x00e8
                    00E9    462 Fexample_servo_sequence$UTX0IF$0$0 == 0x00e9
                    00E9    463 _UTX0IF	=	0x00e9
                    00EA    464 Fexample_servo_sequence$UTX1IF$0$0 == 0x00ea
                    00EA    465 _UTX1IF	=	0x00ea
                    00EB    466 Fexample_servo_sequence$P1IF$0$0 == 0x00eb
                    00EB    467 _P1IF	=	0x00eb
                    00EC    468 Fexample_servo_sequence$WDTIF$0$0 == 0x00ec
                    00EC    469 _WDTIF	=	0x00ec
                    00ED    470 Fexample_servo_sequence$_IRCON25$0$0 == 0x00ed
                    00ED    471 __IRCON25	=	0x00ed
                    00EE    472 Fexample_servo_sequence$_IRCON26$0$0 == 0x00ee
                    00EE    473 __IRCON26	=	0x00ee
                    00EF    474 Fexample_servo_sequence$_IRCON27$0$0 == 0x00ef
                    00EF    475 __IRCON27	=	0x00ef
                    00F0    476 Fexample_servo_sequence$B_0$0$0 == 0x00f0
                    00F0    477 _B_0	=	0x00f0
                    00F1    478 Fexample_servo_sequence$B_1$0$0 == 0x00f1
                    00F1    479 _B_1	=	0x00f1
                    00F2    480 Fexample_servo_sequence$B_2$0$0 == 0x00f2
                    00F2    481 _B_2	=	0x00f2
                    00F3    482 Fexample_servo_sequence$B_3$0$0 == 0x00f3
                    00F3    483 _B_3	=	0x00f3
                    00F4    484 Fexample_servo_sequence$B_4$0$0 == 0x00f4
                    00F4    485 _B_4	=	0x00f4
                    00F5    486 Fexample_servo_sequence$B_5$0$0 == 0x00f5
                    00F5    487 _B_5	=	0x00f5
                    00F6    488 Fexample_servo_sequence$B_6$0$0 == 0x00f6
                    00F6    489 _B_6	=	0x00f6
                    00F7    490 Fexample_servo_sequence$B_7$0$0 == 0x00f7
                    00F7    491 _B_7	=	0x00f7
                    00F8    492 Fexample_servo_sequence$U1ACTIVE$0$0 == 0x00f8
                    00F8    493 _U1ACTIVE	=	0x00f8
                    00F9    494 Fexample_servo_sequence$U1TX_BYTE$0$0 == 0x00f9
                    00F9    495 _U1TX_BYTE	=	0x00f9
                    00FA    496 Fexample_servo_sequence$U1RX_BYTE$0$0 == 0x00fa
                    00FA    497 _U1RX_BYTE	=	0x00fa
                    00FB    498 Fexample_servo_sequence$U1ERR$0$0 == 0x00fb
                    00FB    499 _U1ERR	=	0x00fb
                    00FC    500 Fexample_servo_sequence$U1FE$0$0 == 0x00fc
                    00FC    501 _U1FE	=	0x00fc
                    00FD    502 Fexample_servo_sequence$U1SLAVE$0$0 == 0x00fd
                    00FD    503 _U1SLAVE	=	0x00fd
                    00FE    504 Fexample_servo_sequence$U1RE$0$0 == 0x00fe
                    00FE    505 _U1RE	=	0x00fe
                    00FF    506 Fexample_servo_sequence$U1MODE$0$0 == 0x00ff
                    00FF    507 _U1MODE	=	0x00ff
                            508 ;--------------------------------------------------------
                            509 ; overlayable register banks
                            510 ;--------------------------------------------------------
                            511 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     512 	.ds 8
                            513 ;--------------------------------------------------------
                            514 ; internal ram data
                            515 ;--------------------------------------------------------
                            516 	.area DSEG    (DATA)
                            517 ;--------------------------------------------------------
                            518 ; overlayable items in internal ram 
                            519 ;--------------------------------------------------------
                            520 	.area OSEG    (OVR,DATA)
                            521 ;--------------------------------------------------------
                            522 ; Stack segment in internal ram 
                            523 ;--------------------------------------------------------
                            524 	.area	SSEG	(DATA)
   0023                     525 __start__stack:
   0023                     526 	.ds	1
                            527 
                            528 ;--------------------------------------------------------
                            529 ; indirectly addressable internal ram data
                            530 ;--------------------------------------------------------
                            531 	.area ISEG    (DATA)
                            532 ;--------------------------------------------------------
                            533 ; absolute internal ram data
                            534 ;--------------------------------------------------------
                            535 	.area IABS    (ABS,DATA)
                            536 	.area IABS    (ABS,DATA)
                            537 ;--------------------------------------------------------
                            538 ; bit data
                            539 ;--------------------------------------------------------
                            540 	.area BSEG    (BIT)
                            541 ;--------------------------------------------------------
                            542 ; paged external ram data
                            543 ;--------------------------------------------------------
                            544 	.area PSEG    (PAG,XDATA)
                            545 ;--------------------------------------------------------
                            546 ; external ram data
                            547 ;--------------------------------------------------------
                            548 	.area XSEG    (XDATA)
                    DF00    549 Fexample_servo_sequence$SYNC1$0$0 == 0xdf00
                    DF00    550 _SYNC1	=	0xdf00
                    DF01    551 Fexample_servo_sequence$SYNC0$0$0 == 0xdf01
                    DF01    552 _SYNC0	=	0xdf01
                    DF02    553 Fexample_servo_sequence$PKTLEN$0$0 == 0xdf02
                    DF02    554 _PKTLEN	=	0xdf02
                    DF03    555 Fexample_servo_sequence$PKTCTRL1$0$0 == 0xdf03
                    DF03    556 _PKTCTRL1	=	0xdf03
                    DF04    557 Fexample_servo_sequence$PKTCTRL0$0$0 == 0xdf04
                    DF04    558 _PKTCTRL0	=	0xdf04
                    DF05    559 Fexample_servo_sequence$ADDR$0$0 == 0xdf05
                    DF05    560 _ADDR	=	0xdf05
                    DF06    561 Fexample_servo_sequence$CHANNR$0$0 == 0xdf06
                    DF06    562 _CHANNR	=	0xdf06
                    DF07    563 Fexample_servo_sequence$FSCTRL1$0$0 == 0xdf07
                    DF07    564 _FSCTRL1	=	0xdf07
                    DF08    565 Fexample_servo_sequence$FSCTRL0$0$0 == 0xdf08
                    DF08    566 _FSCTRL0	=	0xdf08
                    DF09    567 Fexample_servo_sequence$FREQ2$0$0 == 0xdf09
                    DF09    568 _FREQ2	=	0xdf09
                    DF0A    569 Fexample_servo_sequence$FREQ1$0$0 == 0xdf0a
                    DF0A    570 _FREQ1	=	0xdf0a
                    DF0B    571 Fexample_servo_sequence$FREQ0$0$0 == 0xdf0b
                    DF0B    572 _FREQ0	=	0xdf0b
                    DF0C    573 Fexample_servo_sequence$MDMCFG4$0$0 == 0xdf0c
                    DF0C    574 _MDMCFG4	=	0xdf0c
                    DF0D    575 Fexample_servo_sequence$MDMCFG3$0$0 == 0xdf0d
                    DF0D    576 _MDMCFG3	=	0xdf0d
                    DF0E    577 Fexample_servo_sequence$MDMCFG2$0$0 == 0xdf0e
                    DF0E    578 _MDMCFG2	=	0xdf0e
                    DF0F    579 Fexample_servo_sequence$MDMCFG1$0$0 == 0xdf0f
                    DF0F    580 _MDMCFG1	=	0xdf0f
                    DF10    581 Fexample_servo_sequence$MDMCFG0$0$0 == 0xdf10
                    DF10    582 _MDMCFG0	=	0xdf10
                    DF11    583 Fexample_servo_sequence$DEVIATN$0$0 == 0xdf11
                    DF11    584 _DEVIATN	=	0xdf11
                    DF12    585 Fexample_servo_sequence$MCSM2$0$0 == 0xdf12
                    DF12    586 _MCSM2	=	0xdf12
                    DF13    587 Fexample_servo_sequence$MCSM1$0$0 == 0xdf13
                    DF13    588 _MCSM1	=	0xdf13
                    DF14    589 Fexample_servo_sequence$MCSM0$0$0 == 0xdf14
                    DF14    590 _MCSM0	=	0xdf14
                    DF15    591 Fexample_servo_sequence$FOCCFG$0$0 == 0xdf15
                    DF15    592 _FOCCFG	=	0xdf15
                    DF16    593 Fexample_servo_sequence$BSCFG$0$0 == 0xdf16
                    DF16    594 _BSCFG	=	0xdf16
                    DF17    595 Fexample_servo_sequence$AGCCTRL2$0$0 == 0xdf17
                    DF17    596 _AGCCTRL2	=	0xdf17
                    DF18    597 Fexample_servo_sequence$AGCCTRL1$0$0 == 0xdf18
                    DF18    598 _AGCCTRL1	=	0xdf18
                    DF19    599 Fexample_servo_sequence$AGCCTRL0$0$0 == 0xdf19
                    DF19    600 _AGCCTRL0	=	0xdf19
                    DF1A    601 Fexample_servo_sequence$FREND1$0$0 == 0xdf1a
                    DF1A    602 _FREND1	=	0xdf1a
                    DF1B    603 Fexample_servo_sequence$FREND0$0$0 == 0xdf1b
                    DF1B    604 _FREND0	=	0xdf1b
                    DF1C    605 Fexample_servo_sequence$FSCAL3$0$0 == 0xdf1c
                    DF1C    606 _FSCAL3	=	0xdf1c
                    DF1D    607 Fexample_servo_sequence$FSCAL2$0$0 == 0xdf1d
                    DF1D    608 _FSCAL2	=	0xdf1d
                    DF1E    609 Fexample_servo_sequence$FSCAL1$0$0 == 0xdf1e
                    DF1E    610 _FSCAL1	=	0xdf1e
                    DF1F    611 Fexample_servo_sequence$FSCAL0$0$0 == 0xdf1f
                    DF1F    612 _FSCAL0	=	0xdf1f
                    DF23    613 Fexample_servo_sequence$TEST2$0$0 == 0xdf23
                    DF23    614 _TEST2	=	0xdf23
                    DF24    615 Fexample_servo_sequence$TEST1$0$0 == 0xdf24
                    DF24    616 _TEST1	=	0xdf24
                    DF25    617 Fexample_servo_sequence$TEST0$0$0 == 0xdf25
                    DF25    618 _TEST0	=	0xdf25
                    DF2E    619 Fexample_servo_sequence$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    620 _PA_TABLE0	=	0xdf2e
                    DF2F    621 Fexample_servo_sequence$IOCFG2$0$0 == 0xdf2f
                    DF2F    622 _IOCFG2	=	0xdf2f
                    DF30    623 Fexample_servo_sequence$IOCFG1$0$0 == 0xdf30
                    DF30    624 _IOCFG1	=	0xdf30
                    DF31    625 Fexample_servo_sequence$IOCFG0$0$0 == 0xdf31
                    DF31    626 _IOCFG0	=	0xdf31
                    DF36    627 Fexample_servo_sequence$PARTNUM$0$0 == 0xdf36
                    DF36    628 _PARTNUM	=	0xdf36
                    DF37    629 Fexample_servo_sequence$VERSION$0$0 == 0xdf37
                    DF37    630 _VERSION	=	0xdf37
                    DF38    631 Fexample_servo_sequence$FREQEST$0$0 == 0xdf38
                    DF38    632 _FREQEST	=	0xdf38
                    DF39    633 Fexample_servo_sequence$LQI$0$0 == 0xdf39
                    DF39    634 _LQI	=	0xdf39
                    DF3A    635 Fexample_servo_sequence$RSSI$0$0 == 0xdf3a
                    DF3A    636 _RSSI	=	0xdf3a
                    DF3B    637 Fexample_servo_sequence$MARCSTATE$0$0 == 0xdf3b
                    DF3B    638 _MARCSTATE	=	0xdf3b
                    DF3C    639 Fexample_servo_sequence$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    640 _PKTSTATUS	=	0xdf3c
                    DF3D    641 Fexample_servo_sequence$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    642 _VCO_VC_DAC	=	0xdf3d
                    DF40    643 Fexample_servo_sequence$I2SCFG0$0$0 == 0xdf40
                    DF40    644 _I2SCFG0	=	0xdf40
                    DF41    645 Fexample_servo_sequence$I2SCFG1$0$0 == 0xdf41
                    DF41    646 _I2SCFG1	=	0xdf41
                    DF42    647 Fexample_servo_sequence$I2SDATL$0$0 == 0xdf42
                    DF42    648 _I2SDATL	=	0xdf42
                    DF43    649 Fexample_servo_sequence$I2SDATH$0$0 == 0xdf43
                    DF43    650 _I2SDATH	=	0xdf43
                    DF44    651 Fexample_servo_sequence$I2SWCNT$0$0 == 0xdf44
                    DF44    652 _I2SWCNT	=	0xdf44
                    DF45    653 Fexample_servo_sequence$I2SSTAT$0$0 == 0xdf45
                    DF45    654 _I2SSTAT	=	0xdf45
                    DF46    655 Fexample_servo_sequence$I2SCLKF0$0$0 == 0xdf46
                    DF46    656 _I2SCLKF0	=	0xdf46
                    DF47    657 Fexample_servo_sequence$I2SCLKF1$0$0 == 0xdf47
                    DF47    658 _I2SCLKF1	=	0xdf47
                    DF48    659 Fexample_servo_sequence$I2SCLKF2$0$0 == 0xdf48
                    DF48    660 _I2SCLKF2	=	0xdf48
                    DE00    661 Fexample_servo_sequence$USBADDR$0$0 == 0xde00
                    DE00    662 _USBADDR	=	0xde00
                    DE01    663 Fexample_servo_sequence$USBPOW$0$0 == 0xde01
                    DE01    664 _USBPOW	=	0xde01
                    DE02    665 Fexample_servo_sequence$USBIIF$0$0 == 0xde02
                    DE02    666 _USBIIF	=	0xde02
                    DE04    667 Fexample_servo_sequence$USBOIF$0$0 == 0xde04
                    DE04    668 _USBOIF	=	0xde04
                    DE06    669 Fexample_servo_sequence$USBCIF$0$0 == 0xde06
                    DE06    670 _USBCIF	=	0xde06
                    DE07    671 Fexample_servo_sequence$USBIIE$0$0 == 0xde07
                    DE07    672 _USBIIE	=	0xde07
                    DE09    673 Fexample_servo_sequence$USBOIE$0$0 == 0xde09
                    DE09    674 _USBOIE	=	0xde09
                    DE0B    675 Fexample_servo_sequence$USBCIE$0$0 == 0xde0b
                    DE0B    676 _USBCIE	=	0xde0b
                    DE0C    677 Fexample_servo_sequence$USBFRML$0$0 == 0xde0c
                    DE0C    678 _USBFRML	=	0xde0c
                    DE0D    679 Fexample_servo_sequence$USBFRMH$0$0 == 0xde0d
                    DE0D    680 _USBFRMH	=	0xde0d
                    DE0E    681 Fexample_servo_sequence$USBINDEX$0$0 == 0xde0e
                    DE0E    682 _USBINDEX	=	0xde0e
                    DE10    683 Fexample_servo_sequence$USBMAXI$0$0 == 0xde10
                    DE10    684 _USBMAXI	=	0xde10
                    DE11    685 Fexample_servo_sequence$USBCSIL$0$0 == 0xde11
                    DE11    686 _USBCSIL	=	0xde11
                    DE12    687 Fexample_servo_sequence$USBCSIH$0$0 == 0xde12
                    DE12    688 _USBCSIH	=	0xde12
                    DE13    689 Fexample_servo_sequence$USBMAXO$0$0 == 0xde13
                    DE13    690 _USBMAXO	=	0xde13
                    DE14    691 Fexample_servo_sequence$USBCSOL$0$0 == 0xde14
                    DE14    692 _USBCSOL	=	0xde14
                    DE15    693 Fexample_servo_sequence$USBCSOH$0$0 == 0xde15
                    DE15    694 _USBCSOH	=	0xde15
                    DE16    695 Fexample_servo_sequence$USBCNTL$0$0 == 0xde16
                    DE16    696 _USBCNTL	=	0xde16
                    DE17    697 Fexample_servo_sequence$USBCNTH$0$0 == 0xde17
                    DE17    698 _USBCNTH	=	0xde17
                    DE20    699 Fexample_servo_sequence$USBF0$0$0 == 0xde20
                    DE20    700 _USBF0	=	0xde20
                    DE22    701 Fexample_servo_sequence$USBF1$0$0 == 0xde22
                    DE22    702 _USBF1	=	0xde22
                    DE24    703 Fexample_servo_sequence$USBF2$0$0 == 0xde24
                    DE24    704 _USBF2	=	0xde24
                    DE26    705 Fexample_servo_sequence$USBF3$0$0 == 0xde26
                    DE26    706 _USBF3	=	0xde26
                    DE28    707 Fexample_servo_sequence$USBF4$0$0 == 0xde28
                    DE28    708 _USBF4	=	0xde28
                    DE2A    709 Fexample_servo_sequence$USBF5$0$0 == 0xde2a
                    DE2A    710 _USBF5	=	0xde2a
                            711 ;--------------------------------------------------------
                            712 ; absolute external ram data
                            713 ;--------------------------------------------------------
                            714 	.area XABS    (ABS,XDATA)
                            715 ;--------------------------------------------------------
                            716 ; external initialized ram data
                            717 ;--------------------------------------------------------
                            718 	.area XISEG   (XDATA)
                            719 	.area HOME    (CODE)
                            720 	.area GSINIT0 (CODE)
                            721 	.area GSINIT1 (CODE)
                            722 	.area GSINIT2 (CODE)
                            723 	.area GSINIT3 (CODE)
                            724 	.area GSINIT4 (CODE)
                            725 	.area GSINIT5 (CODE)
                            726 	.area GSINIT  (CODE)
                            727 	.area GSFINAL (CODE)
                            728 	.area CSEG    (CODE)
                            729 ;--------------------------------------------------------
                            730 ; interrupt vector 
                            731 ;--------------------------------------------------------
                            732 	.area HOME    (CODE)
   0400                     733 __interrupt_vect:
   0400 02 04 6D            734 	ljmp	__sdcc_gsinit_startup
   0403 32                  735 	reti
   0404                     736 	.ds	7
   040B 32                  737 	reti
   040C                     738 	.ds	7
   0413 32                  739 	reti
   0414                     740 	.ds	7
   041B 32                  741 	reti
   041C                     742 	.ds	7
   0423 32                  743 	reti
   0424                     744 	.ds	7
   042B 32                  745 	reti
   042C                     746 	.ds	7
   0433 32                  747 	reti
   0434                     748 	.ds	7
   043B 32                  749 	reti
   043C                     750 	.ds	7
   0443 32                  751 	reti
   0444                     752 	.ds	7
   044B 02 06 F7            753 	ljmp	_ISR_T1
   044E                     754 	.ds	5
   0453 32                  755 	reti
   0454                     756 	.ds	7
   045B 32                  757 	reti
   045C                     758 	.ds	7
   0463 02 16 4C            759 	ljmp	_ISR_T4
                            760 ;--------------------------------------------------------
                            761 ; global & static initialisations
                            762 ;--------------------------------------------------------
                            763 	.area HOME    (CODE)
                            764 	.area GSINIT  (CODE)
                            765 	.area GSFINAL (CODE)
                            766 	.area GSINIT  (CODE)
                            767 	.globl __sdcc_gsinit_startup
                            768 	.globl __sdcc_program_startup
                            769 	.globl __start__stack
                            770 	.globl __mcs51_genXINIT
                            771 	.globl __mcs51_genXRAMCLEAR
                            772 	.globl __mcs51_genRAMCLEAR
                            773 	.area GSFINAL (CODE)
   04F7 02 04 66            774 	ljmp	__sdcc_program_startup
                            775 ;--------------------------------------------------------
                            776 ; Home
                            777 ;--------------------------------------------------------
                            778 	.area HOME    (CODE)
                            779 	.area HOME    (CODE)
   0466                     780 __sdcc_program_startup:
   0466 12 05 9A            781 	lcall	_main
                            782 ;	return from main will lock up
   0469 80 FE               783 	sjmp .
                            784 ;--------------------------------------------------------
                            785 ; code
                            786 ;--------------------------------------------------------
                            787 	.area CSEG    (CODE)
                            788 ;------------------------------------------------------------
                            789 ;Allocation info for local variables in function 'frequentTasks'
                            790 ;------------------------------------------------------------
                    0000    791 	G$frequentTasks$0$0 ==.
                    0000    792 	C$example_servo_sequence.c$56$0$0 ==.
                            793 ;	apps/example_servo_sequence/example_servo_sequence.c:56: void frequentTasks()
                            794 ;	-----------------------------------------
                            795 ;	 function frequentTasks
                            796 ;	-----------------------------------------
   0590                     797 _frequentTasks:
                    0007    798 	ar7 = 0x07
                    0006    799 	ar6 = 0x06
                    0005    800 	ar5 = 0x05
                    0004    801 	ar4 = 0x04
                    0003    802 	ar3 = 0x03
                    0002    803 	ar2 = 0x02
                    0001    804 	ar1 = 0x01
                    0000    805 	ar0 = 0x00
                    0000    806 	C$example_servo_sequence.c$58$1$1 ==.
                            807 ;	apps/example_servo_sequence/example_servo_sequence.c:58: boardService();
   0590 12 15 5E            808 	lcall	_boardService
                    0003    809 	C$example_servo_sequence.c$59$1$1 ==.
                            810 ;	apps/example_servo_sequence/example_servo_sequence.c:59: usbComService();
   0593 12 0D 89            811 	lcall	_usbComService
                    0006    812 	C$example_servo_sequence.c$60$1$1 ==.
                            813 ;	apps/example_servo_sequence/example_servo_sequence.c:60: usbShowStatusWithGreenLed();
   0596 12 1B 07            814 	lcall	_usbShowStatusWithGreenLed
                    0009    815 	C$example_servo_sequence.c$61$1$1 ==.
                    0009    816 	XG$frequentTasks$0$0 ==.
   0599 22                  817 	ret
                            818 ;------------------------------------------------------------
                            819 ;Allocation info for local variables in function 'main'
                            820 ;------------------------------------------------------------
                    000A    821 	G$main$0$0 ==.
                    000A    822 	C$example_servo_sequence.c$64$1$1 ==.
                            823 ;	apps/example_servo_sequence/example_servo_sequence.c:64: void main()
                            824 ;	-----------------------------------------
                            825 ;	 function main
                            826 ;	-----------------------------------------
   059A                     827 _main:
                    000A    828 	C$example_servo_sequence.c$66$1$1 ==.
                            829 ;	apps/example_servo_sequence/example_servo_sequence.c:66: systemInit();
   059A 12 15 51            830 	lcall	_systemInit
                    000D    831 	C$example_servo_sequence.c$67$1$1 ==.
                            832 ;	apps/example_servo_sequence/example_servo_sequence.c:67: usbInit();
   059D 12 0E EB            833 	lcall	_usbInit
                    0010    834 	C$example_servo_sequence.c$68$1$1 ==.
                            835 ;	apps/example_servo_sequence/example_servo_sequence.c:68: servosStart((uint8 XDATA *)pins, sizeof(pins));
   05A0 90 1B B0            836 	mov	dptr,#_pins
   05A3 78 0C               837 	mov	r0,#_servosStart_PARM_2
   05A5 74 01               838 	mov	a,#0x01
   05A7 F2                  839 	movx	@r0,a
   05A8 12 08 FD            840 	lcall	_servosStart
                    001B    841 	C$example_servo_sequence.c$70$1$1 ==.
                            842 ;	apps/example_servo_sequence/example_servo_sequence.c:70: while(1)
   05AB                     843 00102$:
                    001B    844 	C$example_servo_sequence.c$72$2$2 ==.
                            845 ;	apps/example_servo_sequence/example_servo_sequence.c:72: frequentTasks();
   05AB 12 05 90            846 	lcall	_frequentTasks
                    001E    847 	C$example_servo_sequence.c$73$2$2 ==.
                            848 ;	apps/example_servo_sequence/example_servo_sequence.c:73: loop();
   05AE 12 05 B4            849 	lcall	_loop
   05B1 80 F8               850 	sjmp	00102$
                    0023    851 	C$example_servo_sequence.c$75$1$1 ==.
                    0023    852 	XG$main$0$0 ==.
   05B3 22                  853 	ret
                            854 ;------------------------------------------------------------
                            855 ;Allocation info for local variables in function 'loop'
                            856 ;------------------------------------------------------------
                    0024    857 	G$loop$0$0 ==.
                    0024    858 	C$example_servo_sequence.c$84$1$1 ==.
                            859 ;	apps/example_servo_sequence/example_servo_sequence.c:84: void loop()
                            860 ;	-----------------------------------------
                            861 ;	 function loop
                            862 ;	-----------------------------------------
   05B4                     863 _loop:
                    0024    864 	C$example_servo_sequence.c$86$1$1 ==.
                            865 ;	apps/example_servo_sequence/example_servo_sequence.c:86: servoSetSpeed(0, 130);     // Set the speed of servo 0.
   05B4 78 13               866 	mov	r0,#_servoSetSpeed_PARM_2
   05B6 74 82               867 	mov	a,#0x82
   05B8 F2                  868 	movx	@r0,a
   05B9 08                  869 	inc	r0
   05BA E4                  870 	clr	a
   05BB F2                  871 	movx	@r0,a
   05BC 75 82 00            872 	mov	dpl,#0x00
   05BF 12 0B DA            873 	lcall	_servoSetSpeed
                    0032    874 	C$example_servo_sequence.c$87$1$1 ==.
                            875 ;	apps/example_servo_sequence/example_servo_sequence.c:87: servoSetTarget(0, 1000);   // Send servo 0 to position 1000 us.
   05C2 78 0D               876 	mov	r0,#_servoSetTarget_PARM_2
   05C4 74 E8               877 	mov	a,#0xE8
   05C6 F2                  878 	movx	@r0,a
   05C7 08                  879 	inc	r0
   05C8 74 03               880 	mov	a,#0x03
   05CA F2                  881 	movx	@r0,a
   05CB 75 82 00            882 	mov	dpl,#0x00
   05CE 12 0A 82            883 	lcall	_servoSetTarget
                    0041    884 	C$example_servo_sequence.c$89$1$1 ==.
                            885 ;	apps/example_servo_sequence/example_servo_sequence.c:89: servosWaitWhileMoving();   // Wait for it to get there.
   05D1 12 05 75            886 	lcall	_servosWaitWhileMoving
                    0044    887 	C$example_servo_sequence.c$91$2$2 ==.
                            888 ;	apps/example_servo_sequence/example_servo_sequence.c:91: LED_YELLOW(1);
   05D4 43 FF 04            889 	orl	_P2DIR,#0x04
                    0047    890 	C$example_servo_sequence.c$92$1$1 ==.
                            891 ;	apps/example_servo_sequence/example_servo_sequence.c:92: waitMs(2000);              // Wait 2 more seconds, with the yellow LED on.
   05D7 90 07 D0            892 	mov	dptr,#0x07D0
   05DA E4                  893 	clr	a
   05DB F5 F0               894 	mov	b,a
   05DD 12 04 FA            895 	lcall	_waitMs
                    0050    896 	C$example_servo_sequence.c$94$2$3 ==.
                            897 ;	apps/example_servo_sequence/example_servo_sequence.c:94: LED_YELLOW(0);
   05E0 AF FF               898 	mov	r7,_P2DIR
   05E2 53 07 FB            899 	anl	ar7,#0xFB
   05E5 8F FF               900 	mov	_P2DIR,r7
                    0057    901 	C$example_servo_sequence.c$95$1$1 ==.
                            902 ;	apps/example_servo_sequence/example_servo_sequence.c:95: servoSetTarget(0, 2000);
   05E7 78 0D               903 	mov	r0,#_servoSetTarget_PARM_2
   05E9 74 D0               904 	mov	a,#0xD0
   05EB F2                  905 	movx	@r0,a
   05EC 08                  906 	inc	r0
   05ED 74 07               907 	mov	a,#0x07
   05EF F2                  908 	movx	@r0,a
   05F0 75 82 00            909 	mov	dpl,#0x00
   05F3 12 0A 82            910 	lcall	_servoSetTarget
                    0066    911 	C$example_servo_sequence.c$96$1$1 ==.
                            912 ;	apps/example_servo_sequence/example_servo_sequence.c:96: servosWaitWhileMoving();
   05F6 12 05 75            913 	lcall	_servosWaitWhileMoving
                    0069    914 	C$example_servo_sequence.c$98$1$1 ==.
                            915 ;	apps/example_servo_sequence/example_servo_sequence.c:98: servoSetTarget(0, 1500);
   05F9 78 0D               916 	mov	r0,#_servoSetTarget_PARM_2
   05FB 74 DC               917 	mov	a,#0xDC
   05FD F2                  918 	movx	@r0,a
   05FE 08                  919 	inc	r0
   05FF 74 05               920 	mov	a,#0x05
   0601 F2                  921 	movx	@r0,a
   0602 75 82 00            922 	mov	dpl,#0x00
   0605 12 0A 82            923 	lcall	_servoSetTarget
                    0078    924 	C$example_servo_sequence.c$99$1$1 ==.
                            925 ;	apps/example_servo_sequence/example_servo_sequence.c:99: servosWaitWhileMoving();
   0608 12 05 75            926 	lcall	_servosWaitWhileMoving
                    007B    927 	C$example_servo_sequence.c$101$1$1 ==.
                            928 ;	apps/example_servo_sequence/example_servo_sequence.c:101: servoSetTarget(0, 2000);
   060B 78 0D               929 	mov	r0,#_servoSetTarget_PARM_2
   060D 74 D0               930 	mov	a,#0xD0
   060F F2                  931 	movx	@r0,a
   0610 08                  932 	inc	r0
   0611 74 07               933 	mov	a,#0x07
   0613 F2                  934 	movx	@r0,a
   0614 75 82 00            935 	mov	dpl,#0x00
   0617 12 0A 82            936 	lcall	_servoSetTarget
                    008A    937 	C$example_servo_sequence.c$102$1$1 ==.
                            938 ;	apps/example_servo_sequence/example_servo_sequence.c:102: servosWaitWhileMoving();
   061A 12 05 75            939 	lcall	_servosWaitWhileMoving
                    008D    940 	C$example_servo_sequence.c$103$1$1 ==.
                    008D    941 	XG$loop$0$0 ==.
   061D 22                  942 	ret
                            943 ;------------------------------------------------------------
                            944 ;Allocation info for local variables in function 'loop_sequence_triggered_by_usb'
                            945 ;------------------------------------------------------------
                    008E    946 	G$loop_sequence_triggered_by_usb$0$0 ==.
                    008E    947 	C$example_servo_sequence.c$114$1$1 ==.
                            948 ;	apps/example_servo_sequence/example_servo_sequence.c:114: void loop_sequence_triggered_by_usb()
                            949 ;	-----------------------------------------
                            950 ;	 function loop_sequence_triggered_by_usb
                            951 ;	-----------------------------------------
   061E                     952 _loop_sequence_triggered_by_usb:
                    008E    953 	C$example_servo_sequence.c$116$1$1 ==.
                            954 ;	apps/example_servo_sequence/example_servo_sequence.c:116: servoSetSpeed(0, 458);
   061E 78 13               955 	mov	r0,#_servoSetSpeed_PARM_2
   0620 74 CA               956 	mov	a,#0xCA
   0622 F2                  957 	movx	@r0,a
   0623 08                  958 	inc	r0
   0624 74 01               959 	mov	a,#0x01
   0626 F2                  960 	movx	@r0,a
   0627 75 82 00            961 	mov	dpl,#0x00
   062A 12 0B DA            962 	lcall	_servoSetSpeed
                    009D    963 	C$example_servo_sequence.c$117$1$1 ==.
                            964 ;	apps/example_servo_sequence/example_servo_sequence.c:117: servoSetTarget(0, 1500);
   062D 78 0D               965 	mov	r0,#_servoSetTarget_PARM_2
   062F 74 DC               966 	mov	a,#0xDC
   0631 F2                  967 	movx	@r0,a
   0632 08                  968 	inc	r0
   0633 74 05               969 	mov	a,#0x05
   0635 F2                  970 	movx	@r0,a
   0636 75 82 00            971 	mov	dpl,#0x00
   0639 12 0A 82            972 	lcall	_servoSetTarget
                    00AC    973 	C$example_servo_sequence.c$119$1$1 ==.
                            974 ;	apps/example_servo_sequence/example_servo_sequence.c:119: switch(usbComRxReceiveByteBlocking())
   063C 12 05 80            975 	lcall	_usbComRxReceiveByteBlocking
   063F AF 82               976 	mov	r7,dpl
   0641 BF 61 02            977 	cjne	r7,#0x61,00109$
   0644 80 05               978 	sjmp	00101$
   0646                     979 00109$:
                    00B6    980 	C$example_servo_sequence.c$121$2$2 ==.
                            981 ;	apps/example_servo_sequence/example_servo_sequence.c:121: case 'a':
   0646 BF 62 3C            982 	cjne	r7,#0x62,00103$
   0649 80 1D               983 	sjmp	00102$
   064B                     984 00101$:
                    00BB    985 	C$example_servo_sequence.c$123$2$2 ==.
                            986 ;	apps/example_servo_sequence/example_servo_sequence.c:123: servoSetTarget(0, 2000);
   064B 78 0D               987 	mov	r0,#_servoSetTarget_PARM_2
   064D 74 D0               988 	mov	a,#0xD0
   064F F2                  989 	movx	@r0,a
   0650 08                  990 	inc	r0
   0651 74 07               991 	mov	a,#0x07
   0653 F2                  992 	movx	@r0,a
   0654 75 82 00            993 	mov	dpl,#0x00
   0657 12 0A 82            994 	lcall	_servoSetTarget
                    00CA    995 	C$example_servo_sequence.c$124$2$2 ==.
                            996 ;	apps/example_servo_sequence/example_servo_sequence.c:124: servosWaitWhileMoving();
   065A 12 05 75            997 	lcall	_servosWaitWhileMoving
                    00CD    998 	C$example_servo_sequence.c$125$2$2 ==.
                            999 ;	apps/example_servo_sequence/example_servo_sequence.c:125: waitMs(1000);
   065D 90 03 E8           1000 	mov	dptr,#0x03E8
   0660 E4                 1001 	clr	a
   0661 F5 F0              1002 	mov	b,a
   0663 12 04 FA           1003 	lcall	_waitMs
                    00D6   1004 	C$example_servo_sequence.c$126$2$2 ==.
                           1005 ;	apps/example_servo_sequence/example_servo_sequence.c:126: break;
                    00D6   1006 	C$example_servo_sequence.c$128$2$2 ==.
                           1007 ;	apps/example_servo_sequence/example_servo_sequence.c:128: case 'b':
   0666 80 30              1008 	sjmp	00105$
   0668                    1009 00102$:
                    00D8   1010 	C$example_servo_sequence.c$130$2$2 ==.
                           1011 ;	apps/example_servo_sequence/example_servo_sequence.c:130: servoSetTarget(0, 1000);
   0668 78 0D              1012 	mov	r0,#_servoSetTarget_PARM_2
   066A 74 E8              1013 	mov	a,#0xE8
   066C F2                 1014 	movx	@r0,a
   066D 08                 1015 	inc	r0
   066E 74 03              1016 	mov	a,#0x03
   0670 F2                 1017 	movx	@r0,a
   0671 75 82 00           1018 	mov	dpl,#0x00
   0674 12 0A 82           1019 	lcall	_servoSetTarget
                    00E7   1020 	C$example_servo_sequence.c$131$2$2 ==.
                           1021 ;	apps/example_servo_sequence/example_servo_sequence.c:131: servosWaitWhileMoving();
   0677 12 05 75           1022 	lcall	_servosWaitWhileMoving
                    00EA   1023 	C$example_servo_sequence.c$132$2$2 ==.
                           1024 ;	apps/example_servo_sequence/example_servo_sequence.c:132: waitMs(1000);
   067A 90 03 E8           1025 	mov	dptr,#0x03E8
   067D E4                 1026 	clr	a
   067E F5 F0              1027 	mov	b,a
   0680 12 04 FA           1028 	lcall	_waitMs
                    00F3   1029 	C$example_servo_sequence.c$133$2$2 ==.
                           1030 ;	apps/example_servo_sequence/example_servo_sequence.c:133: break;
                    00F3   1031 	C$example_servo_sequence.c$135$2$2 ==.
                           1032 ;	apps/example_servo_sequence/example_servo_sequence.c:135: default:
   0683 80 13              1033 	sjmp	00105$
   0685                    1034 00103$:
                    00F5   1035 	C$example_servo_sequence.c$137$3$3 ==.
                           1036 ;	apps/example_servo_sequence/example_servo_sequence.c:137: LED_RED(1);
   0685 43 FF 02           1037 	orl	_P2DIR,#0x02
                    00F8   1038 	C$example_servo_sequence.c$138$2$2 ==.
                           1039 ;	apps/example_servo_sequence/example_servo_sequence.c:138: waitMs(20);
   0688 90 00 14           1040 	mov	dptr,#(0x14&0x00ff)
   068B E4                 1041 	clr	a
   068C F5 F0              1042 	mov	b,a
   068E 12 04 FA           1043 	lcall	_waitMs
                    0101   1044 	C$example_servo_sequence.c$139$3$4 ==.
                           1045 ;	apps/example_servo_sequence/example_servo_sequence.c:139: LED_RED(0);
   0691 AF FF              1046 	mov	r7,_P2DIR
   0693 53 07 FD           1047 	anl	ar7,#0xFD
   0696 8F FF              1048 	mov	_P2DIR,r7
                    0108   1049 	C$example_servo_sequence.c$141$1$1 ==.
                           1050 ;	apps/example_servo_sequence/example_servo_sequence.c:141: }
   0698                    1051 00105$:
                    0108   1052 	C$example_servo_sequence.c$142$1$1 ==.
                    0108   1053 	XG$loop_sequence_triggered_by_usb$0$0 ==.
   0698 22                 1054 	ret
                           1055 ;------------------------------------------------------------
                           1056 ;Allocation info for local variables in function 'loop_sequence_triggered_by_digital_input'
                           1057 ;------------------------------------------------------------
                    0109   1058 	G$loop_sequence_triggered_by_digital_input$0$0 ==.
                    0109   1059 	C$example_servo_sequence.c$150$1$1 ==.
                           1060 ;	apps/example_servo_sequence/example_servo_sequence.c:150: void loop_sequence_triggered_by_digital_input()
                           1061 ;	-----------------------------------------
                           1062 ;	 function loop_sequence_triggered_by_digital_input
                           1063 ;	-----------------------------------------
   0699                    1064 _loop_sequence_triggered_by_digital_input:
                    0109   1065 	C$example_servo_sequence.c$152$1$1 ==.
                           1066 ;	apps/example_servo_sequence/example_servo_sequence.c:152: servoSetSpeed(0, 458);
   0699 78 13              1067 	mov	r0,#_servoSetSpeed_PARM_2
   069B 74 CA              1068 	mov	a,#0xCA
   069D F2                 1069 	movx	@r0,a
   069E 08                 1070 	inc	r0
   069F 74 01              1071 	mov	a,#0x01
   06A1 F2                 1072 	movx	@r0,a
   06A2 75 82 00           1073 	mov	dpl,#0x00
   06A5 12 0B DA           1074 	lcall	_servoSetSpeed
                    0118   1075 	C$example_servo_sequence.c$153$1$1 ==.
                           1076 ;	apps/example_servo_sequence/example_servo_sequence.c:153: servoSetTarget(0, 1500);
   06A8 78 0D              1077 	mov	r0,#_servoSetTarget_PARM_2
   06AA 74 DC              1078 	mov	a,#0xDC
   06AC F2                 1079 	movx	@r0,a
   06AD 08                 1080 	inc	r0
   06AE 74 05              1081 	mov	a,#0x05
   06B0 F2                 1082 	movx	@r0,a
   06B1 75 82 00           1083 	mov	dpl,#0x00
   06B4 12 0A 82           1084 	lcall	_servoSetTarget
                    0127   1085 	C$example_servo_sequence.c$155$1$1 ==.
                           1086 ;	apps/example_servo_sequence/example_servo_sequence.c:155: if (!isPinHigh(0)) // Measure voltage on P0_0
   06B7 75 82 00           1087 	mov	dpl,#0x00
   06BA 12 1A 39           1088 	lcall	_isPinHigh
   06BD 40 37              1089 	jc	00103$
                    012F   1090 	C$example_servo_sequence.c$157$3$3 ==.
                           1091 ;	apps/example_servo_sequence/example_servo_sequence.c:157: LED_YELLOW(1);
   06BF 43 FF 04           1092 	orl	_P2DIR,#0x04
                    0132   1093 	C$example_servo_sequence.c$158$2$2 ==.
                           1094 ;	apps/example_servo_sequence/example_servo_sequence.c:158: servoSetTarget(0, 2000);
   06C2 78 0D              1095 	mov	r0,#_servoSetTarget_PARM_2
   06C4 74 D0              1096 	mov	a,#0xD0
   06C6 F2                 1097 	movx	@r0,a
   06C7 08                 1098 	inc	r0
   06C8 74 07              1099 	mov	a,#0x07
   06CA F2                 1100 	movx	@r0,a
   06CB 75 82 00           1101 	mov	dpl,#0x00
   06CE 12 0A 82           1102 	lcall	_servoSetTarget
                    0141   1103 	C$example_servo_sequence.c$159$2$2 ==.
                           1104 ;	apps/example_servo_sequence/example_servo_sequence.c:159: servosWaitWhileMoving();
   06D1 12 05 75           1105 	lcall	_servosWaitWhileMoving
                    0144   1106 	C$example_servo_sequence.c$161$2$2 ==.
                           1107 ;	apps/example_servo_sequence/example_servo_sequence.c:161: waitMs(1000);
   06D4 90 03 E8           1108 	mov	dptr,#0x03E8
   06D7 E4                 1109 	clr	a
   06D8 F5 F0              1110 	mov	b,a
   06DA 12 04 FA           1111 	lcall	_waitMs
                    014D   1112 	C$example_servo_sequence.c$163$2$2 ==.
                           1113 ;	apps/example_servo_sequence/example_servo_sequence.c:163: servoSetTarget(0, 1500);
   06DD 78 0D              1114 	mov	r0,#_servoSetTarget_PARM_2
   06DF 74 DC              1115 	mov	a,#0xDC
   06E1 F2                 1116 	movx	@r0,a
   06E2 08                 1117 	inc	r0
   06E3 74 05              1118 	mov	a,#0x05
   06E5 F2                 1119 	movx	@r0,a
   06E6 75 82 00           1120 	mov	dpl,#0x00
   06E9 12 0A 82           1121 	lcall	_servoSetTarget
                    015C   1122 	C$example_servo_sequence.c$164$2$2 ==.
                           1123 ;	apps/example_servo_sequence/example_servo_sequence.c:164: servosWaitWhileMoving();
   06EC 12 05 75           1124 	lcall	_servosWaitWhileMoving
                    015F   1125 	C$example_servo_sequence.c$166$3$4 ==.
                           1126 ;	apps/example_servo_sequence/example_servo_sequence.c:166: LED_YELLOW(0);
   06EF AF FF              1127 	mov	r7,_P2DIR
   06F1 53 07 FB           1128 	anl	ar7,#0xFB
   06F4 8F FF              1129 	mov	_P2DIR,r7
   06F6                    1130 00103$:
                    0166   1131 	C$example_servo_sequence.c$168$3$1 ==.
                    0166   1132 	XG$loop_sequence_triggered_by_digital_input$0$0 ==.
   06F6 22                 1133 	ret
                           1134 	.area CSEG    (CODE)
                           1135 	.area CONST   (CODE)
                    0000   1136 G$pins$0$0 == .
   1BB0                    1137 _pins:
   1BB0 02                 1138 	.db #0x02	; 2
                           1139 	.area XINIT   (CODE)
                           1140 	.area CABS    (ABS,CODE)
