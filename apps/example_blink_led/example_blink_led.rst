                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:40 2012
                              5 ;--------------------------------------------------------
                              6 	.module example_blink_led
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_blink_period_ms
                             13 	.globl _main
                             14 	.globl _updateLeds
                             15 	.globl _usbComService
                             16 	.globl _usbShowStatusWithGreenLed
                             17 	.globl _usbInit
                             18 	.globl _getMs
                             19 	.globl _boardService
                             20 	.globl _systemInit
                             21 	.globl _lastToggle
                             22 ;--------------------------------------------------------
                             23 ; special function registers
                             24 ;--------------------------------------------------------
                             25 	.area RSEG    (ABS,DATA)
   0000                      26 	.org 0x0000
                    0080     27 Fexample_blink_led$P0$0$0 == 0x0080
                    0080     28 _P0	=	0x0080
                    0081     29 Fexample_blink_led$SP$0$0 == 0x0081
                    0081     30 _SP	=	0x0081
                    0082     31 Fexample_blink_led$DPL0$0$0 == 0x0082
                    0082     32 _DPL0	=	0x0082
                    0083     33 Fexample_blink_led$DPH0$0$0 == 0x0083
                    0083     34 _DPH0	=	0x0083
                    0084     35 Fexample_blink_led$DPL1$0$0 == 0x0084
                    0084     36 _DPL1	=	0x0084
                    0085     37 Fexample_blink_led$DPH1$0$0 == 0x0085
                    0085     38 _DPH1	=	0x0085
                    0086     39 Fexample_blink_led$U0CSR$0$0 == 0x0086
                    0086     40 _U0CSR	=	0x0086
                    0087     41 Fexample_blink_led$PCON$0$0 == 0x0087
                    0087     42 _PCON	=	0x0087
                    0088     43 Fexample_blink_led$TCON$0$0 == 0x0088
                    0088     44 _TCON	=	0x0088
                    0089     45 Fexample_blink_led$P0IFG$0$0 == 0x0089
                    0089     46 _P0IFG	=	0x0089
                    008A     47 Fexample_blink_led$P1IFG$0$0 == 0x008a
                    008A     48 _P1IFG	=	0x008a
                    008B     49 Fexample_blink_led$P2IFG$0$0 == 0x008b
                    008B     50 _P2IFG	=	0x008b
                    008C     51 Fexample_blink_led$PICTL$0$0 == 0x008c
                    008C     52 _PICTL	=	0x008c
                    008D     53 Fexample_blink_led$P1IEN$0$0 == 0x008d
                    008D     54 _P1IEN	=	0x008d
                    008F     55 Fexample_blink_led$P0INP$0$0 == 0x008f
                    008F     56 _P0INP	=	0x008f
                    0090     57 Fexample_blink_led$P1$0$0 == 0x0090
                    0090     58 _P1	=	0x0090
                    0091     59 Fexample_blink_led$RFIM$0$0 == 0x0091
                    0091     60 _RFIM	=	0x0091
                    0092     61 Fexample_blink_led$DPS$0$0 == 0x0092
                    0092     62 _DPS	=	0x0092
                    0093     63 Fexample_blink_led$MPAGE$0$0 == 0x0093
                    0093     64 _MPAGE	=	0x0093
                    0095     65 Fexample_blink_led$ENDIAN$0$0 == 0x0095
                    0095     66 _ENDIAN	=	0x0095
                    0098     67 Fexample_blink_led$S0CON$0$0 == 0x0098
                    0098     68 _S0CON	=	0x0098
                    009A     69 Fexample_blink_led$IEN2$0$0 == 0x009a
                    009A     70 _IEN2	=	0x009a
                    009B     71 Fexample_blink_led$S1CON$0$0 == 0x009b
                    009B     72 _S1CON	=	0x009b
                    009C     73 Fexample_blink_led$T2CT$0$0 == 0x009c
                    009C     74 _T2CT	=	0x009c
                    009D     75 Fexample_blink_led$T2PR$0$0 == 0x009d
                    009D     76 _T2PR	=	0x009d
                    009E     77 Fexample_blink_led$T2CTL$0$0 == 0x009e
                    009E     78 _T2CTL	=	0x009e
                    00A0     79 Fexample_blink_led$P2$0$0 == 0x00a0
                    00A0     80 _P2	=	0x00a0
                    00A1     81 Fexample_blink_led$WORIRQ$0$0 == 0x00a1
                    00A1     82 _WORIRQ	=	0x00a1
                    00A2     83 Fexample_blink_led$WORCTRL$0$0 == 0x00a2
                    00A2     84 _WORCTRL	=	0x00a2
                    00A3     85 Fexample_blink_led$WOREVT0$0$0 == 0x00a3
                    00A3     86 _WOREVT0	=	0x00a3
                    00A4     87 Fexample_blink_led$WOREVT1$0$0 == 0x00a4
                    00A4     88 _WOREVT1	=	0x00a4
                    00A5     89 Fexample_blink_led$WORTIME0$0$0 == 0x00a5
                    00A5     90 _WORTIME0	=	0x00a5
                    00A6     91 Fexample_blink_led$WORTIME1$0$0 == 0x00a6
                    00A6     92 _WORTIME1	=	0x00a6
                    00A8     93 Fexample_blink_led$IEN0$0$0 == 0x00a8
                    00A8     94 _IEN0	=	0x00a8
                    00A9     95 Fexample_blink_led$IP0$0$0 == 0x00a9
                    00A9     96 _IP0	=	0x00a9
                    00AB     97 Fexample_blink_led$FWT$0$0 == 0x00ab
                    00AB     98 _FWT	=	0x00ab
                    00AC     99 Fexample_blink_led$FADDRL$0$0 == 0x00ac
                    00AC    100 _FADDRL	=	0x00ac
                    00AD    101 Fexample_blink_led$FADDRH$0$0 == 0x00ad
                    00AD    102 _FADDRH	=	0x00ad
                    00AE    103 Fexample_blink_led$FCTL$0$0 == 0x00ae
                    00AE    104 _FCTL	=	0x00ae
                    00AF    105 Fexample_blink_led$FWDATA$0$0 == 0x00af
                    00AF    106 _FWDATA	=	0x00af
                    00B1    107 Fexample_blink_led$ENCDI$0$0 == 0x00b1
                    00B1    108 _ENCDI	=	0x00b1
                    00B2    109 Fexample_blink_led$ENCDO$0$0 == 0x00b2
                    00B2    110 _ENCDO	=	0x00b2
                    00B3    111 Fexample_blink_led$ENCCS$0$0 == 0x00b3
                    00B3    112 _ENCCS	=	0x00b3
                    00B4    113 Fexample_blink_led$ADCCON1$0$0 == 0x00b4
                    00B4    114 _ADCCON1	=	0x00b4
                    00B5    115 Fexample_blink_led$ADCCON2$0$0 == 0x00b5
                    00B5    116 _ADCCON2	=	0x00b5
                    00B6    117 Fexample_blink_led$ADCCON3$0$0 == 0x00b6
                    00B6    118 _ADCCON3	=	0x00b6
                    00B8    119 Fexample_blink_led$IEN1$0$0 == 0x00b8
                    00B8    120 _IEN1	=	0x00b8
                    00B9    121 Fexample_blink_led$IP1$0$0 == 0x00b9
                    00B9    122 _IP1	=	0x00b9
                    00BA    123 Fexample_blink_led$ADCL$0$0 == 0x00ba
                    00BA    124 _ADCL	=	0x00ba
                    00BB    125 Fexample_blink_led$ADCH$0$0 == 0x00bb
                    00BB    126 _ADCH	=	0x00bb
                    00BC    127 Fexample_blink_led$RNDL$0$0 == 0x00bc
                    00BC    128 _RNDL	=	0x00bc
                    00BD    129 Fexample_blink_led$RNDH$0$0 == 0x00bd
                    00BD    130 _RNDH	=	0x00bd
                    00BE    131 Fexample_blink_led$SLEEP$0$0 == 0x00be
                    00BE    132 _SLEEP	=	0x00be
                    00C0    133 Fexample_blink_led$IRCON$0$0 == 0x00c0
                    00C0    134 _IRCON	=	0x00c0
                    00C1    135 Fexample_blink_led$U0DBUF$0$0 == 0x00c1
                    00C1    136 _U0DBUF	=	0x00c1
                    00C2    137 Fexample_blink_led$U0BAUD$0$0 == 0x00c2
                    00C2    138 _U0BAUD	=	0x00c2
                    00C4    139 Fexample_blink_led$U0UCR$0$0 == 0x00c4
                    00C4    140 _U0UCR	=	0x00c4
                    00C5    141 Fexample_blink_led$U0GCR$0$0 == 0x00c5
                    00C5    142 _U0GCR	=	0x00c5
                    00C6    143 Fexample_blink_led$CLKCON$0$0 == 0x00c6
                    00C6    144 _CLKCON	=	0x00c6
                    00C7    145 Fexample_blink_led$MEMCTR$0$0 == 0x00c7
                    00C7    146 _MEMCTR	=	0x00c7
                    00C9    147 Fexample_blink_led$WDCTL$0$0 == 0x00c9
                    00C9    148 _WDCTL	=	0x00c9
                    00CA    149 Fexample_blink_led$T3CNT$0$0 == 0x00ca
                    00CA    150 _T3CNT	=	0x00ca
                    00CB    151 Fexample_blink_led$T3CTL$0$0 == 0x00cb
                    00CB    152 _T3CTL	=	0x00cb
                    00CC    153 Fexample_blink_led$T3CCTL0$0$0 == 0x00cc
                    00CC    154 _T3CCTL0	=	0x00cc
                    00CD    155 Fexample_blink_led$T3CC0$0$0 == 0x00cd
                    00CD    156 _T3CC0	=	0x00cd
                    00CE    157 Fexample_blink_led$T3CCTL1$0$0 == 0x00ce
                    00CE    158 _T3CCTL1	=	0x00ce
                    00CF    159 Fexample_blink_led$T3CC1$0$0 == 0x00cf
                    00CF    160 _T3CC1	=	0x00cf
                    00D0    161 Fexample_blink_led$PSW$0$0 == 0x00d0
                    00D0    162 _PSW	=	0x00d0
                    00D1    163 Fexample_blink_led$DMAIRQ$0$0 == 0x00d1
                    00D1    164 _DMAIRQ	=	0x00d1
                    00D2    165 Fexample_blink_led$DMA1CFGL$0$0 == 0x00d2
                    00D2    166 _DMA1CFGL	=	0x00d2
                    00D3    167 Fexample_blink_led$DMA1CFGH$0$0 == 0x00d3
                    00D3    168 _DMA1CFGH	=	0x00d3
                    00D4    169 Fexample_blink_led$DMA0CFGL$0$0 == 0x00d4
                    00D4    170 _DMA0CFGL	=	0x00d4
                    00D5    171 Fexample_blink_led$DMA0CFGH$0$0 == 0x00d5
                    00D5    172 _DMA0CFGH	=	0x00d5
                    00D6    173 Fexample_blink_led$DMAARM$0$0 == 0x00d6
                    00D6    174 _DMAARM	=	0x00d6
                    00D7    175 Fexample_blink_led$DMAREQ$0$0 == 0x00d7
                    00D7    176 _DMAREQ	=	0x00d7
                    00D8    177 Fexample_blink_led$TIMIF$0$0 == 0x00d8
                    00D8    178 _TIMIF	=	0x00d8
                    00D9    179 Fexample_blink_led$RFD$0$0 == 0x00d9
                    00D9    180 _RFD	=	0x00d9
                    00DA    181 Fexample_blink_led$T1CC0L$0$0 == 0x00da
                    00DA    182 _T1CC0L	=	0x00da
                    00DB    183 Fexample_blink_led$T1CC0H$0$0 == 0x00db
                    00DB    184 _T1CC0H	=	0x00db
                    00DC    185 Fexample_blink_led$T1CC1L$0$0 == 0x00dc
                    00DC    186 _T1CC1L	=	0x00dc
                    00DD    187 Fexample_blink_led$T1CC1H$0$0 == 0x00dd
                    00DD    188 _T1CC1H	=	0x00dd
                    00DE    189 Fexample_blink_led$T1CC2L$0$0 == 0x00de
                    00DE    190 _T1CC2L	=	0x00de
                    00DF    191 Fexample_blink_led$T1CC2H$0$0 == 0x00df
                    00DF    192 _T1CC2H	=	0x00df
                    00E0    193 Fexample_blink_led$ACC$0$0 == 0x00e0
                    00E0    194 _ACC	=	0x00e0
                    00E1    195 Fexample_blink_led$RFST$0$0 == 0x00e1
                    00E1    196 _RFST	=	0x00e1
                    00E2    197 Fexample_blink_led$T1CNTL$0$0 == 0x00e2
                    00E2    198 _T1CNTL	=	0x00e2
                    00E3    199 Fexample_blink_led$T1CNTH$0$0 == 0x00e3
                    00E3    200 _T1CNTH	=	0x00e3
                    00E4    201 Fexample_blink_led$T1CTL$0$0 == 0x00e4
                    00E4    202 _T1CTL	=	0x00e4
                    00E5    203 Fexample_blink_led$T1CCTL0$0$0 == 0x00e5
                    00E5    204 _T1CCTL0	=	0x00e5
                    00E6    205 Fexample_blink_led$T1CCTL1$0$0 == 0x00e6
                    00E6    206 _T1CCTL1	=	0x00e6
                    00E7    207 Fexample_blink_led$T1CCTL2$0$0 == 0x00e7
                    00E7    208 _T1CCTL2	=	0x00e7
                    00E8    209 Fexample_blink_led$IRCON2$0$0 == 0x00e8
                    00E8    210 _IRCON2	=	0x00e8
                    00E9    211 Fexample_blink_led$RFIF$0$0 == 0x00e9
                    00E9    212 _RFIF	=	0x00e9
                    00EA    213 Fexample_blink_led$T4CNT$0$0 == 0x00ea
                    00EA    214 _T4CNT	=	0x00ea
                    00EB    215 Fexample_blink_led$T4CTL$0$0 == 0x00eb
                    00EB    216 _T4CTL	=	0x00eb
                    00EC    217 Fexample_blink_led$T4CCTL0$0$0 == 0x00ec
                    00EC    218 _T4CCTL0	=	0x00ec
                    00ED    219 Fexample_blink_led$T4CC0$0$0 == 0x00ed
                    00ED    220 _T4CC0	=	0x00ed
                    00EE    221 Fexample_blink_led$T4CCTL1$0$0 == 0x00ee
                    00EE    222 _T4CCTL1	=	0x00ee
                    00EF    223 Fexample_blink_led$T4CC1$0$0 == 0x00ef
                    00EF    224 _T4CC1	=	0x00ef
                    00F0    225 Fexample_blink_led$B$0$0 == 0x00f0
                    00F0    226 _B	=	0x00f0
                    00F1    227 Fexample_blink_led$PERCFG$0$0 == 0x00f1
                    00F1    228 _PERCFG	=	0x00f1
                    00F2    229 Fexample_blink_led$ADCCFG$0$0 == 0x00f2
                    00F2    230 _ADCCFG	=	0x00f2
                    00F3    231 Fexample_blink_led$P0SEL$0$0 == 0x00f3
                    00F3    232 _P0SEL	=	0x00f3
                    00F4    233 Fexample_blink_led$P1SEL$0$0 == 0x00f4
                    00F4    234 _P1SEL	=	0x00f4
                    00F5    235 Fexample_blink_led$P2SEL$0$0 == 0x00f5
                    00F5    236 _P2SEL	=	0x00f5
                    00F6    237 Fexample_blink_led$P1INP$0$0 == 0x00f6
                    00F6    238 _P1INP	=	0x00f6
                    00F7    239 Fexample_blink_led$P2INP$0$0 == 0x00f7
                    00F7    240 _P2INP	=	0x00f7
                    00F8    241 Fexample_blink_led$U1CSR$0$0 == 0x00f8
                    00F8    242 _U1CSR	=	0x00f8
                    00F9    243 Fexample_blink_led$U1DBUF$0$0 == 0x00f9
                    00F9    244 _U1DBUF	=	0x00f9
                    00FA    245 Fexample_blink_led$U1BAUD$0$0 == 0x00fa
                    00FA    246 _U1BAUD	=	0x00fa
                    00FB    247 Fexample_blink_led$U1UCR$0$0 == 0x00fb
                    00FB    248 _U1UCR	=	0x00fb
                    00FC    249 Fexample_blink_led$U1GCR$0$0 == 0x00fc
                    00FC    250 _U1GCR	=	0x00fc
                    00FD    251 Fexample_blink_led$P0DIR$0$0 == 0x00fd
                    00FD    252 _P0DIR	=	0x00fd
                    00FE    253 Fexample_blink_led$P1DIR$0$0 == 0x00fe
                    00FE    254 _P1DIR	=	0x00fe
                    00FF    255 Fexample_blink_led$P2DIR$0$0 == 0x00ff
                    00FF    256 _P2DIR	=	0x00ff
                    FFFFD5D4    257 Fexample_blink_led$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    258 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    259 Fexample_blink_led$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    260 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    261 Fexample_blink_led$FADDR$0$0 == 0xffffadac
                    FFFFADAC    262 _FADDR	=	0xffffadac
                    FFFFBBBA    263 Fexample_blink_led$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    264 _ADC	=	0xffffbbba
                    FFFFDBDA    265 Fexample_blink_led$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    266 _T1CC0	=	0xffffdbda
                    FFFFDDDC    267 Fexample_blink_led$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    268 _T1CC1	=	0xffffdddc
                    FFFFDFDE    269 Fexample_blink_led$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    270 _T1CC2	=	0xffffdfde
                            271 ;--------------------------------------------------------
                            272 ; special function bits
                            273 ;--------------------------------------------------------
                            274 	.area RSEG    (ABS,DATA)
   0000                     275 	.org 0x0000
                    0080    276 Fexample_blink_led$P0_0$0$0 == 0x0080
                    0080    277 _P0_0	=	0x0080
                    0081    278 Fexample_blink_led$P0_1$0$0 == 0x0081
                    0081    279 _P0_1	=	0x0081
                    0082    280 Fexample_blink_led$P0_2$0$0 == 0x0082
                    0082    281 _P0_2	=	0x0082
                    0083    282 Fexample_blink_led$P0_3$0$0 == 0x0083
                    0083    283 _P0_3	=	0x0083
                    0084    284 Fexample_blink_led$P0_4$0$0 == 0x0084
                    0084    285 _P0_4	=	0x0084
                    0085    286 Fexample_blink_led$P0_5$0$0 == 0x0085
                    0085    287 _P0_5	=	0x0085
                    0086    288 Fexample_blink_led$P0_6$0$0 == 0x0086
                    0086    289 _P0_6	=	0x0086
                    0087    290 Fexample_blink_led$P0_7$0$0 == 0x0087
                    0087    291 _P0_7	=	0x0087
                    0088    292 Fexample_blink_led$_TCON_0$0$0 == 0x0088
                    0088    293 __TCON_0	=	0x0088
                    0089    294 Fexample_blink_led$RFTXRXIF$0$0 == 0x0089
                    0089    295 _RFTXRXIF	=	0x0089
                    008A    296 Fexample_blink_led$_TCON_2$0$0 == 0x008a
                    008A    297 __TCON_2	=	0x008a
                    008B    298 Fexample_blink_led$URX0IF$0$0 == 0x008b
                    008B    299 _URX0IF	=	0x008b
                    008C    300 Fexample_blink_led$_TCON_4$0$0 == 0x008c
                    008C    301 __TCON_4	=	0x008c
                    008D    302 Fexample_blink_led$ADCIF$0$0 == 0x008d
                    008D    303 _ADCIF	=	0x008d
                    008E    304 Fexample_blink_led$_TCON_6$0$0 == 0x008e
                    008E    305 __TCON_6	=	0x008e
                    008F    306 Fexample_blink_led$URX1IF$0$0 == 0x008f
                    008F    307 _URX1IF	=	0x008f
                    0090    308 Fexample_blink_led$P1_0$0$0 == 0x0090
                    0090    309 _P1_0	=	0x0090
                    0091    310 Fexample_blink_led$P1_1$0$0 == 0x0091
                    0091    311 _P1_1	=	0x0091
                    0092    312 Fexample_blink_led$P1_2$0$0 == 0x0092
                    0092    313 _P1_2	=	0x0092
                    0093    314 Fexample_blink_led$P1_3$0$0 == 0x0093
                    0093    315 _P1_3	=	0x0093
                    0094    316 Fexample_blink_led$P1_4$0$0 == 0x0094
                    0094    317 _P1_4	=	0x0094
                    0095    318 Fexample_blink_led$P1_5$0$0 == 0x0095
                    0095    319 _P1_5	=	0x0095
                    0096    320 Fexample_blink_led$P1_6$0$0 == 0x0096
                    0096    321 _P1_6	=	0x0096
                    0097    322 Fexample_blink_led$P1_7$0$0 == 0x0097
                    0097    323 _P1_7	=	0x0097
                    0098    324 Fexample_blink_led$ENCIF_0$0$0 == 0x0098
                    0098    325 _ENCIF_0	=	0x0098
                    0099    326 Fexample_blink_led$ENCIF_1$0$0 == 0x0099
                    0099    327 _ENCIF_1	=	0x0099
                    009A    328 Fexample_blink_led$_SOCON2$0$0 == 0x009a
                    009A    329 __SOCON2	=	0x009a
                    009B    330 Fexample_blink_led$_SOCON3$0$0 == 0x009b
                    009B    331 __SOCON3	=	0x009b
                    009C    332 Fexample_blink_led$_SOCON4$0$0 == 0x009c
                    009C    333 __SOCON4	=	0x009c
                    009D    334 Fexample_blink_led$_SOCON5$0$0 == 0x009d
                    009D    335 __SOCON5	=	0x009d
                    009E    336 Fexample_blink_led$_SOCON6$0$0 == 0x009e
                    009E    337 __SOCON6	=	0x009e
                    009F    338 Fexample_blink_led$_SOCON7$0$0 == 0x009f
                    009F    339 __SOCON7	=	0x009f
                    00A0    340 Fexample_blink_led$P2_0$0$0 == 0x00a0
                    00A0    341 _P2_0	=	0x00a0
                    00A1    342 Fexample_blink_led$P2_1$0$0 == 0x00a1
                    00A1    343 _P2_1	=	0x00a1
                    00A2    344 Fexample_blink_led$P2_2$0$0 == 0x00a2
                    00A2    345 _P2_2	=	0x00a2
                    00A3    346 Fexample_blink_led$P2_3$0$0 == 0x00a3
                    00A3    347 _P2_3	=	0x00a3
                    00A4    348 Fexample_blink_led$P2_4$0$0 == 0x00a4
                    00A4    349 _P2_4	=	0x00a4
                    00A5    350 Fexample_blink_led$P2_5$0$0 == 0x00a5
                    00A5    351 _P2_5	=	0x00a5
                    00A6    352 Fexample_blink_led$P2_6$0$0 == 0x00a6
                    00A6    353 _P2_6	=	0x00a6
                    00A7    354 Fexample_blink_led$P2_7$0$0 == 0x00a7
                    00A7    355 _P2_7	=	0x00a7
                    00A8    356 Fexample_blink_led$RFTXRXIE$0$0 == 0x00a8
                    00A8    357 _RFTXRXIE	=	0x00a8
                    00A9    358 Fexample_blink_led$ADCIE$0$0 == 0x00a9
                    00A9    359 _ADCIE	=	0x00a9
                    00AA    360 Fexample_blink_led$URX0IE$0$0 == 0x00aa
                    00AA    361 _URX0IE	=	0x00aa
                    00AB    362 Fexample_blink_led$URX1IE$0$0 == 0x00ab
                    00AB    363 _URX1IE	=	0x00ab
                    00AC    364 Fexample_blink_led$ENCIE$0$0 == 0x00ac
                    00AC    365 _ENCIE	=	0x00ac
                    00AD    366 Fexample_blink_led$STIE$0$0 == 0x00ad
                    00AD    367 _STIE	=	0x00ad
                    00AE    368 Fexample_blink_led$_IEN06$0$0 == 0x00ae
                    00AE    369 __IEN06	=	0x00ae
                    00AF    370 Fexample_blink_led$EA$0$0 == 0x00af
                    00AF    371 _EA	=	0x00af
                    00B8    372 Fexample_blink_led$DMAIE$0$0 == 0x00b8
                    00B8    373 _DMAIE	=	0x00b8
                    00B9    374 Fexample_blink_led$T1IE$0$0 == 0x00b9
                    00B9    375 _T1IE	=	0x00b9
                    00BA    376 Fexample_blink_led$T2IE$0$0 == 0x00ba
                    00BA    377 _T2IE	=	0x00ba
                    00BB    378 Fexample_blink_led$T3IE$0$0 == 0x00bb
                    00BB    379 _T3IE	=	0x00bb
                    00BC    380 Fexample_blink_led$T4IE$0$0 == 0x00bc
                    00BC    381 _T4IE	=	0x00bc
                    00BD    382 Fexample_blink_led$P0IE$0$0 == 0x00bd
                    00BD    383 _P0IE	=	0x00bd
                    00BE    384 Fexample_blink_led$_IEN16$0$0 == 0x00be
                    00BE    385 __IEN16	=	0x00be
                    00BF    386 Fexample_blink_led$_IEN17$0$0 == 0x00bf
                    00BF    387 __IEN17	=	0x00bf
                    00C0    388 Fexample_blink_led$DMAIF$0$0 == 0x00c0
                    00C0    389 _DMAIF	=	0x00c0
                    00C1    390 Fexample_blink_led$T1IF$0$0 == 0x00c1
                    00C1    391 _T1IF	=	0x00c1
                    00C2    392 Fexample_blink_led$T2IF$0$0 == 0x00c2
                    00C2    393 _T2IF	=	0x00c2
                    00C3    394 Fexample_blink_led$T3IF$0$0 == 0x00c3
                    00C3    395 _T3IF	=	0x00c3
                    00C4    396 Fexample_blink_led$T4IF$0$0 == 0x00c4
                    00C4    397 _T4IF	=	0x00c4
                    00C5    398 Fexample_blink_led$P0IF$0$0 == 0x00c5
                    00C5    399 _P0IF	=	0x00c5
                    00C6    400 Fexample_blink_led$_IRCON6$0$0 == 0x00c6
                    00C6    401 __IRCON6	=	0x00c6
                    00C7    402 Fexample_blink_led$STIF$0$0 == 0x00c7
                    00C7    403 _STIF	=	0x00c7
                    00D0    404 Fexample_blink_led$P$0$0 == 0x00d0
                    00D0    405 _P	=	0x00d0
                    00D1    406 Fexample_blink_led$F1$0$0 == 0x00d1
                    00D1    407 _F1	=	0x00d1
                    00D2    408 Fexample_blink_led$OV$0$0 == 0x00d2
                    00D2    409 _OV	=	0x00d2
                    00D3    410 Fexample_blink_led$RS0$0$0 == 0x00d3
                    00D3    411 _RS0	=	0x00d3
                    00D4    412 Fexample_blink_led$RS1$0$0 == 0x00d4
                    00D4    413 _RS1	=	0x00d4
                    00D5    414 Fexample_blink_led$F0$0$0 == 0x00d5
                    00D5    415 _F0	=	0x00d5
                    00D6    416 Fexample_blink_led$AC$0$0 == 0x00d6
                    00D6    417 _AC	=	0x00d6
                    00D7    418 Fexample_blink_led$CY$0$0 == 0x00d7
                    00D7    419 _CY	=	0x00d7
                    00D8    420 Fexample_blink_led$T3OVFIF$0$0 == 0x00d8
                    00D8    421 _T3OVFIF	=	0x00d8
                    00D9    422 Fexample_blink_led$T3CH0IF$0$0 == 0x00d9
                    00D9    423 _T3CH0IF	=	0x00d9
                    00DA    424 Fexample_blink_led$T3CH1IF$0$0 == 0x00da
                    00DA    425 _T3CH1IF	=	0x00da
                    00DB    426 Fexample_blink_led$T4OVFIF$0$0 == 0x00db
                    00DB    427 _T4OVFIF	=	0x00db
                    00DC    428 Fexample_blink_led$T4CH0IF$0$0 == 0x00dc
                    00DC    429 _T4CH0IF	=	0x00dc
                    00DD    430 Fexample_blink_led$T4CH1IF$0$0 == 0x00dd
                    00DD    431 _T4CH1IF	=	0x00dd
                    00DE    432 Fexample_blink_led$OVFIM$0$0 == 0x00de
                    00DE    433 _OVFIM	=	0x00de
                    00DF    434 Fexample_blink_led$_TIMIF7$0$0 == 0x00df
                    00DF    435 __TIMIF7	=	0x00df
                    00E0    436 Fexample_blink_led$ACC_0$0$0 == 0x00e0
                    00E0    437 _ACC_0	=	0x00e0
                    00E1    438 Fexample_blink_led$ACC_1$0$0 == 0x00e1
                    00E1    439 _ACC_1	=	0x00e1
                    00E2    440 Fexample_blink_led$ACC_2$0$0 == 0x00e2
                    00E2    441 _ACC_2	=	0x00e2
                    00E3    442 Fexample_blink_led$ACC_3$0$0 == 0x00e3
                    00E3    443 _ACC_3	=	0x00e3
                    00E4    444 Fexample_blink_led$ACC_4$0$0 == 0x00e4
                    00E4    445 _ACC_4	=	0x00e4
                    00E5    446 Fexample_blink_led$ACC_5$0$0 == 0x00e5
                    00E5    447 _ACC_5	=	0x00e5
                    00E6    448 Fexample_blink_led$ACC_6$0$0 == 0x00e6
                    00E6    449 _ACC_6	=	0x00e6
                    00E7    450 Fexample_blink_led$ACC_7$0$0 == 0x00e7
                    00E7    451 _ACC_7	=	0x00e7
                    00E8    452 Fexample_blink_led$P2IF$0$0 == 0x00e8
                    00E8    453 _P2IF	=	0x00e8
                    00E9    454 Fexample_blink_led$UTX0IF$0$0 == 0x00e9
                    00E9    455 _UTX0IF	=	0x00e9
                    00EA    456 Fexample_blink_led$UTX1IF$0$0 == 0x00ea
                    00EA    457 _UTX1IF	=	0x00ea
                    00EB    458 Fexample_blink_led$P1IF$0$0 == 0x00eb
                    00EB    459 _P1IF	=	0x00eb
                    00EC    460 Fexample_blink_led$WDTIF$0$0 == 0x00ec
                    00EC    461 _WDTIF	=	0x00ec
                    00ED    462 Fexample_blink_led$_IRCON25$0$0 == 0x00ed
                    00ED    463 __IRCON25	=	0x00ed
                    00EE    464 Fexample_blink_led$_IRCON26$0$0 == 0x00ee
                    00EE    465 __IRCON26	=	0x00ee
                    00EF    466 Fexample_blink_led$_IRCON27$0$0 == 0x00ef
                    00EF    467 __IRCON27	=	0x00ef
                    00F0    468 Fexample_blink_led$B_0$0$0 == 0x00f0
                    00F0    469 _B_0	=	0x00f0
                    00F1    470 Fexample_blink_led$B_1$0$0 == 0x00f1
                    00F1    471 _B_1	=	0x00f1
                    00F2    472 Fexample_blink_led$B_2$0$0 == 0x00f2
                    00F2    473 _B_2	=	0x00f2
                    00F3    474 Fexample_blink_led$B_3$0$0 == 0x00f3
                    00F3    475 _B_3	=	0x00f3
                    00F4    476 Fexample_blink_led$B_4$0$0 == 0x00f4
                    00F4    477 _B_4	=	0x00f4
                    00F5    478 Fexample_blink_led$B_5$0$0 == 0x00f5
                    00F5    479 _B_5	=	0x00f5
                    00F6    480 Fexample_blink_led$B_6$0$0 == 0x00f6
                    00F6    481 _B_6	=	0x00f6
                    00F7    482 Fexample_blink_led$B_7$0$0 == 0x00f7
                    00F7    483 _B_7	=	0x00f7
                    00F8    484 Fexample_blink_led$U1ACTIVE$0$0 == 0x00f8
                    00F8    485 _U1ACTIVE	=	0x00f8
                    00F9    486 Fexample_blink_led$U1TX_BYTE$0$0 == 0x00f9
                    00F9    487 _U1TX_BYTE	=	0x00f9
                    00FA    488 Fexample_blink_led$U1RX_BYTE$0$0 == 0x00fa
                    00FA    489 _U1RX_BYTE	=	0x00fa
                    00FB    490 Fexample_blink_led$U1ERR$0$0 == 0x00fb
                    00FB    491 _U1ERR	=	0x00fb
                    00FC    492 Fexample_blink_led$U1FE$0$0 == 0x00fc
                    00FC    493 _U1FE	=	0x00fc
                    00FD    494 Fexample_blink_led$U1SLAVE$0$0 == 0x00fd
                    00FD    495 _U1SLAVE	=	0x00fd
                    00FE    496 Fexample_blink_led$U1RE$0$0 == 0x00fe
                    00FE    497 _U1RE	=	0x00fe
                    00FF    498 Fexample_blink_led$U1MODE$0$0 == 0x00ff
                    00FF    499 _U1MODE	=	0x00ff
                            500 ;--------------------------------------------------------
                            501 ; overlayable register banks
                            502 ;--------------------------------------------------------
                            503 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     504 	.ds 8
                            505 ;--------------------------------------------------------
                            506 ; internal ram data
                            507 ;--------------------------------------------------------
                            508 	.area DSEG    (DATA)
                    0000    509 Lexample_blink_led.updateLeds$sloc0$1$0==.
   0008                     510 _updateLeds_sloc0_1_0:
   0008                     511 	.ds 4
                            512 ;--------------------------------------------------------
                            513 ; overlayable items in internal ram 
                            514 ;--------------------------------------------------------
                            515 	.area OSEG    (OVR,DATA)
                            516 ;--------------------------------------------------------
                            517 ; Stack segment in internal ram 
                            518 ;--------------------------------------------------------
                            519 	.area	SSEG	(DATA)
   0022                     520 __start__stack:
   0022                     521 	.ds	1
                            522 
                            523 ;--------------------------------------------------------
                            524 ; indirectly addressable internal ram data
                            525 ;--------------------------------------------------------
                            526 	.area ISEG    (DATA)
                            527 ;--------------------------------------------------------
                            528 ; absolute internal ram data
                            529 ;--------------------------------------------------------
                            530 	.area IABS    (ABS,DATA)
                            531 	.area IABS    (ABS,DATA)
                            532 ;--------------------------------------------------------
                            533 ; bit data
                            534 ;--------------------------------------------------------
                            535 	.area BSEG    (BIT)
                            536 ;--------------------------------------------------------
                            537 ; paged external ram data
                            538 ;--------------------------------------------------------
                            539 	.area PSEG    (PAG,XDATA)
                    0000    540 G$lastToggle$0$0==.
   F000                     541 _lastToggle::
   F000                     542 	.ds 4
                            543 ;--------------------------------------------------------
                            544 ; external ram data
                            545 ;--------------------------------------------------------
                            546 	.area XSEG    (XDATA)
                    DF00    547 Fexample_blink_led$SYNC1$0$0 == 0xdf00
                    DF00    548 _SYNC1	=	0xdf00
                    DF01    549 Fexample_blink_led$SYNC0$0$0 == 0xdf01
                    DF01    550 _SYNC0	=	0xdf01
                    DF02    551 Fexample_blink_led$PKTLEN$0$0 == 0xdf02
                    DF02    552 _PKTLEN	=	0xdf02
                    DF03    553 Fexample_blink_led$PKTCTRL1$0$0 == 0xdf03
                    DF03    554 _PKTCTRL1	=	0xdf03
                    DF04    555 Fexample_blink_led$PKTCTRL0$0$0 == 0xdf04
                    DF04    556 _PKTCTRL0	=	0xdf04
                    DF05    557 Fexample_blink_led$ADDR$0$0 == 0xdf05
                    DF05    558 _ADDR	=	0xdf05
                    DF06    559 Fexample_blink_led$CHANNR$0$0 == 0xdf06
                    DF06    560 _CHANNR	=	0xdf06
                    DF07    561 Fexample_blink_led$FSCTRL1$0$0 == 0xdf07
                    DF07    562 _FSCTRL1	=	0xdf07
                    DF08    563 Fexample_blink_led$FSCTRL0$0$0 == 0xdf08
                    DF08    564 _FSCTRL0	=	0xdf08
                    DF09    565 Fexample_blink_led$FREQ2$0$0 == 0xdf09
                    DF09    566 _FREQ2	=	0xdf09
                    DF0A    567 Fexample_blink_led$FREQ1$0$0 == 0xdf0a
                    DF0A    568 _FREQ1	=	0xdf0a
                    DF0B    569 Fexample_blink_led$FREQ0$0$0 == 0xdf0b
                    DF0B    570 _FREQ0	=	0xdf0b
                    DF0C    571 Fexample_blink_led$MDMCFG4$0$0 == 0xdf0c
                    DF0C    572 _MDMCFG4	=	0xdf0c
                    DF0D    573 Fexample_blink_led$MDMCFG3$0$0 == 0xdf0d
                    DF0D    574 _MDMCFG3	=	0xdf0d
                    DF0E    575 Fexample_blink_led$MDMCFG2$0$0 == 0xdf0e
                    DF0E    576 _MDMCFG2	=	0xdf0e
                    DF0F    577 Fexample_blink_led$MDMCFG1$0$0 == 0xdf0f
                    DF0F    578 _MDMCFG1	=	0xdf0f
                    DF10    579 Fexample_blink_led$MDMCFG0$0$0 == 0xdf10
                    DF10    580 _MDMCFG0	=	0xdf10
                    DF11    581 Fexample_blink_led$DEVIATN$0$0 == 0xdf11
                    DF11    582 _DEVIATN	=	0xdf11
                    DF12    583 Fexample_blink_led$MCSM2$0$0 == 0xdf12
                    DF12    584 _MCSM2	=	0xdf12
                    DF13    585 Fexample_blink_led$MCSM1$0$0 == 0xdf13
                    DF13    586 _MCSM1	=	0xdf13
                    DF14    587 Fexample_blink_led$MCSM0$0$0 == 0xdf14
                    DF14    588 _MCSM0	=	0xdf14
                    DF15    589 Fexample_blink_led$FOCCFG$0$0 == 0xdf15
                    DF15    590 _FOCCFG	=	0xdf15
                    DF16    591 Fexample_blink_led$BSCFG$0$0 == 0xdf16
                    DF16    592 _BSCFG	=	0xdf16
                    DF17    593 Fexample_blink_led$AGCCTRL2$0$0 == 0xdf17
                    DF17    594 _AGCCTRL2	=	0xdf17
                    DF18    595 Fexample_blink_led$AGCCTRL1$0$0 == 0xdf18
                    DF18    596 _AGCCTRL1	=	0xdf18
                    DF19    597 Fexample_blink_led$AGCCTRL0$0$0 == 0xdf19
                    DF19    598 _AGCCTRL0	=	0xdf19
                    DF1A    599 Fexample_blink_led$FREND1$0$0 == 0xdf1a
                    DF1A    600 _FREND1	=	0xdf1a
                    DF1B    601 Fexample_blink_led$FREND0$0$0 == 0xdf1b
                    DF1B    602 _FREND0	=	0xdf1b
                    DF1C    603 Fexample_blink_led$FSCAL3$0$0 == 0xdf1c
                    DF1C    604 _FSCAL3	=	0xdf1c
                    DF1D    605 Fexample_blink_led$FSCAL2$0$0 == 0xdf1d
                    DF1D    606 _FSCAL2	=	0xdf1d
                    DF1E    607 Fexample_blink_led$FSCAL1$0$0 == 0xdf1e
                    DF1E    608 _FSCAL1	=	0xdf1e
                    DF1F    609 Fexample_blink_led$FSCAL0$0$0 == 0xdf1f
                    DF1F    610 _FSCAL0	=	0xdf1f
                    DF23    611 Fexample_blink_led$TEST2$0$0 == 0xdf23
                    DF23    612 _TEST2	=	0xdf23
                    DF24    613 Fexample_blink_led$TEST1$0$0 == 0xdf24
                    DF24    614 _TEST1	=	0xdf24
                    DF25    615 Fexample_blink_led$TEST0$0$0 == 0xdf25
                    DF25    616 _TEST0	=	0xdf25
                    DF2E    617 Fexample_blink_led$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    618 _PA_TABLE0	=	0xdf2e
                    DF2F    619 Fexample_blink_led$IOCFG2$0$0 == 0xdf2f
                    DF2F    620 _IOCFG2	=	0xdf2f
                    DF30    621 Fexample_blink_led$IOCFG1$0$0 == 0xdf30
                    DF30    622 _IOCFG1	=	0xdf30
                    DF31    623 Fexample_blink_led$IOCFG0$0$0 == 0xdf31
                    DF31    624 _IOCFG0	=	0xdf31
                    DF36    625 Fexample_blink_led$PARTNUM$0$0 == 0xdf36
                    DF36    626 _PARTNUM	=	0xdf36
                    DF37    627 Fexample_blink_led$VERSION$0$0 == 0xdf37
                    DF37    628 _VERSION	=	0xdf37
                    DF38    629 Fexample_blink_led$FREQEST$0$0 == 0xdf38
                    DF38    630 _FREQEST	=	0xdf38
                    DF39    631 Fexample_blink_led$LQI$0$0 == 0xdf39
                    DF39    632 _LQI	=	0xdf39
                    DF3A    633 Fexample_blink_led$RSSI$0$0 == 0xdf3a
                    DF3A    634 _RSSI	=	0xdf3a
                    DF3B    635 Fexample_blink_led$MARCSTATE$0$0 == 0xdf3b
                    DF3B    636 _MARCSTATE	=	0xdf3b
                    DF3C    637 Fexample_blink_led$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    638 _PKTSTATUS	=	0xdf3c
                    DF3D    639 Fexample_blink_led$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    640 _VCO_VC_DAC	=	0xdf3d
                    DF40    641 Fexample_blink_led$I2SCFG0$0$0 == 0xdf40
                    DF40    642 _I2SCFG0	=	0xdf40
                    DF41    643 Fexample_blink_led$I2SCFG1$0$0 == 0xdf41
                    DF41    644 _I2SCFG1	=	0xdf41
                    DF42    645 Fexample_blink_led$I2SDATL$0$0 == 0xdf42
                    DF42    646 _I2SDATL	=	0xdf42
                    DF43    647 Fexample_blink_led$I2SDATH$0$0 == 0xdf43
                    DF43    648 _I2SDATH	=	0xdf43
                    DF44    649 Fexample_blink_led$I2SWCNT$0$0 == 0xdf44
                    DF44    650 _I2SWCNT	=	0xdf44
                    DF45    651 Fexample_blink_led$I2SSTAT$0$0 == 0xdf45
                    DF45    652 _I2SSTAT	=	0xdf45
                    DF46    653 Fexample_blink_led$I2SCLKF0$0$0 == 0xdf46
                    DF46    654 _I2SCLKF0	=	0xdf46
                    DF47    655 Fexample_blink_led$I2SCLKF1$0$0 == 0xdf47
                    DF47    656 _I2SCLKF1	=	0xdf47
                    DF48    657 Fexample_blink_led$I2SCLKF2$0$0 == 0xdf48
                    DF48    658 _I2SCLKF2	=	0xdf48
                    DE00    659 Fexample_blink_led$USBADDR$0$0 == 0xde00
                    DE00    660 _USBADDR	=	0xde00
                    DE01    661 Fexample_blink_led$USBPOW$0$0 == 0xde01
                    DE01    662 _USBPOW	=	0xde01
                    DE02    663 Fexample_blink_led$USBIIF$0$0 == 0xde02
                    DE02    664 _USBIIF	=	0xde02
                    DE04    665 Fexample_blink_led$USBOIF$0$0 == 0xde04
                    DE04    666 _USBOIF	=	0xde04
                    DE06    667 Fexample_blink_led$USBCIF$0$0 == 0xde06
                    DE06    668 _USBCIF	=	0xde06
                    DE07    669 Fexample_blink_led$USBIIE$0$0 == 0xde07
                    DE07    670 _USBIIE	=	0xde07
                    DE09    671 Fexample_blink_led$USBOIE$0$0 == 0xde09
                    DE09    672 _USBOIE	=	0xde09
                    DE0B    673 Fexample_blink_led$USBCIE$0$0 == 0xde0b
                    DE0B    674 _USBCIE	=	0xde0b
                    DE0C    675 Fexample_blink_led$USBFRML$0$0 == 0xde0c
                    DE0C    676 _USBFRML	=	0xde0c
                    DE0D    677 Fexample_blink_led$USBFRMH$0$0 == 0xde0d
                    DE0D    678 _USBFRMH	=	0xde0d
                    DE0E    679 Fexample_blink_led$USBINDEX$0$0 == 0xde0e
                    DE0E    680 _USBINDEX	=	0xde0e
                    DE10    681 Fexample_blink_led$USBMAXI$0$0 == 0xde10
                    DE10    682 _USBMAXI	=	0xde10
                    DE11    683 Fexample_blink_led$USBCSIL$0$0 == 0xde11
                    DE11    684 _USBCSIL	=	0xde11
                    DE12    685 Fexample_blink_led$USBCSIH$0$0 == 0xde12
                    DE12    686 _USBCSIH	=	0xde12
                    DE13    687 Fexample_blink_led$USBMAXO$0$0 == 0xde13
                    DE13    688 _USBMAXO	=	0xde13
                    DE14    689 Fexample_blink_led$USBCSOL$0$0 == 0xde14
                    DE14    690 _USBCSOL	=	0xde14
                    DE15    691 Fexample_blink_led$USBCSOH$0$0 == 0xde15
                    DE15    692 _USBCSOH	=	0xde15
                    DE16    693 Fexample_blink_led$USBCNTL$0$0 == 0xde16
                    DE16    694 _USBCNTL	=	0xde16
                    DE17    695 Fexample_blink_led$USBCNTH$0$0 == 0xde17
                    DE17    696 _USBCNTH	=	0xde17
                    DE20    697 Fexample_blink_led$USBF0$0$0 == 0xde20
                    DE20    698 _USBF0	=	0xde20
                    DE22    699 Fexample_blink_led$USBF1$0$0 == 0xde22
                    DE22    700 _USBF1	=	0xde22
                    DE24    701 Fexample_blink_led$USBF2$0$0 == 0xde24
                    DE24    702 _USBF2	=	0xde24
                    DE26    703 Fexample_blink_led$USBF3$0$0 == 0xde26
                    DE26    704 _USBF3	=	0xde26
                    DE28    705 Fexample_blink_led$USBF4$0$0 == 0xde28
                    DE28    706 _USBF4	=	0xde28
                    DE2A    707 Fexample_blink_led$USBF5$0$0 == 0xde2a
                    DE2A    708 _USBF5	=	0xde2a
                            709 ;--------------------------------------------------------
                            710 ; absolute external ram data
                            711 ;--------------------------------------------------------
                            712 	.area XABS    (ABS,XDATA)
                            713 ;--------------------------------------------------------
                            714 ; external initialized ram data
                            715 ;--------------------------------------------------------
                            716 	.area XISEG   (XDATA)
                            717 	.area HOME    (CODE)
                            718 	.area GSINIT0 (CODE)
                            719 	.area GSINIT1 (CODE)
                            720 	.area GSINIT2 (CODE)
                            721 	.area GSINIT3 (CODE)
                            722 	.area GSINIT4 (CODE)
                            723 	.area GSINIT5 (CODE)
                            724 	.area GSINIT  (CODE)
                            725 	.area GSFINAL (CODE)
                            726 	.area CSEG    (CODE)
                            727 ;--------------------------------------------------------
                            728 ; interrupt vector 
                            729 ;--------------------------------------------------------
                            730 	.area HOME    (CODE)
   0400                     731 __interrupt_vect:
   0400 02 04 6D            732 	ljmp	__sdcc_gsinit_startup
   0403 32                  733 	reti
   0404                     734 	.ds	7
   040B 32                  735 	reti
   040C                     736 	.ds	7
   0413 32                  737 	reti
   0414                     738 	.ds	7
   041B 32                  739 	reti
   041C                     740 	.ds	7
   0423 32                  741 	reti
   0424                     742 	.ds	7
   042B 32                  743 	reti
   042C                     744 	.ds	7
   0433 32                  745 	reti
   0434                     746 	.ds	7
   043B 32                  747 	reti
   043C                     748 	.ds	7
   0443 32                  749 	reti
   0444                     750 	.ds	7
   044B 32                  751 	reti
   044C                     752 	.ds	7
   0453 32                  753 	reti
   0454                     754 	.ds	7
   045B 32                  755 	reti
   045C                     756 	.ds	7
   0463 02 0A BC            757 	ljmp	_ISR_T4
                            758 ;--------------------------------------------------------
                            759 ; global & static initialisations
                            760 ;--------------------------------------------------------
                            761 	.area HOME    (CODE)
                            762 	.area GSINIT  (CODE)
                            763 	.area GSFINAL (CODE)
                            764 	.area GSINIT  (CODE)
                            765 	.globl __sdcc_gsinit_startup
                            766 	.globl __sdcc_program_startup
                            767 	.globl __start__stack
                            768 	.globl __mcs51_genXINIT
                            769 	.globl __mcs51_genXRAMCLEAR
                            770 	.globl __mcs51_genRAMCLEAR
                    0000    771 	G$main$0$0 ==.
                    0000    772 	C$example_blink_led.c$16$1$1 ==.
                            773 ;	apps/example_blink_led/example_blink_led.c:16: uint32 lastToggle = 0;
   04C6 78 00               774 	mov	r0,#_lastToggle
   04C8 E4                  775 	clr	a
   04C9 F2                  776 	movx	@r0,a
   04CA 08                  777 	inc	r0
   04CB F2                  778 	movx	@r0,a
   04CC 08                  779 	inc	r0
   04CD F2                  780 	movx	@r0,a
   04CE 08                  781 	inc	r0
   04CF F2                  782 	movx	@r0,a
                            783 	.area GSFINAL (CODE)
   04FA 02 04 66            784 	ljmp	__sdcc_program_startup
                            785 ;--------------------------------------------------------
                            786 ; Home
                            787 ;--------------------------------------------------------
                            788 	.area HOME    (CODE)
                            789 	.area HOME    (CODE)
   0466                     790 __sdcc_program_startup:
   0466 12 05 A1            791 	lcall	_main
                            792 ;	return from main will lock up
   0469 80 FE               793 	sjmp .
                            794 ;--------------------------------------------------------
                            795 ; code
                            796 ;--------------------------------------------------------
                            797 	.area CSEG    (CODE)
                            798 ;------------------------------------------------------------
                            799 ;Allocation info for local variables in function 'updateLeds'
                            800 ;------------------------------------------------------------
                            801 ;sloc0                     Allocated with name '_updateLeds_sloc0_1_0'
                            802 ;------------------------------------------------------------
                    0000    803 	G$updateLeds$0$0 ==.
                    0000    804 	C$example_blink_led.c$18$0$0 ==.
                            805 ;	apps/example_blink_led/example_blink_led.c:18: void updateLeds()
                            806 ;	-----------------------------------------
                            807 ;	 function updateLeds
                            808 ;	-----------------------------------------
   04FD                     809 _updateLeds:
                    0007    810 	ar7 = 0x07
                    0006    811 	ar6 = 0x06
                    0005    812 	ar5 = 0x05
                    0004    813 	ar4 = 0x04
                    0003    814 	ar3 = 0x03
                    0002    815 	ar2 = 0x02
                    0001    816 	ar1 = 0x01
                    0000    817 	ar0 = 0x00
                    0000    818 	C$example_blink_led.c$20$1$1 ==.
                            819 ;	apps/example_blink_led/example_blink_led.c:20: usbShowStatusWithGreenLed();
   04FD 12 11 AE            820 	lcall	_usbShowStatusWithGreenLed
                    0003    821 	C$example_blink_led.c$22$2$2 ==.
                            822 ;	apps/example_blink_led/example_blink_led.c:22: LED_YELLOW(0);
   0500 AF FF               823 	mov	r7,_P2DIR
   0502 53 07 FB            824 	anl	ar7,#0xFB
   0505 8F FF               825 	mov	_P2DIR,r7
                    000A    826 	C$example_blink_led.c$24$1$1 ==.
                            827 ;	apps/example_blink_led/example_blink_led.c:24: if (getMs() - lastToggle >= param_blink_period_ms/2)
   0507 12 0A E1            828 	lcall	_getMs
   050A AC 82               829 	mov	r4,dpl
   050C AD 83               830 	mov	r5,dph
   050E AE F0               831 	mov	r6,b
   0510 FF                  832 	mov	r7,a
   0511 78 00               833 	mov	r0,#_lastToggle
   0513 D3                  834 	setb	c
   0514 E2                  835 	movx	a,@r0
   0515 9C                  836 	subb	a,r4
   0516 F4                  837 	cpl	a
   0517 B3                  838 	cpl	c
   0518 F5 08               839 	mov	_updateLeds_sloc0_1_0,a
   051A B3                  840 	cpl	c
   051B 08                  841 	inc	r0
   051C E2                  842 	movx	a,@r0
   051D 9D                  843 	subb	a,r5
   051E F4                  844 	cpl	a
   051F B3                  845 	cpl	c
   0520 F5 09               846 	mov	(_updateLeds_sloc0_1_0 + 1),a
   0522 B3                  847 	cpl	c
   0523 08                  848 	inc	r0
   0524 E2                  849 	movx	a,@r0
   0525 9E                  850 	subb	a,r6
   0526 F4                  851 	cpl	a
   0527 B3                  852 	cpl	c
   0528 F5 0A               853 	mov	(_updateLeds_sloc0_1_0 + 2),a
   052A B3                  854 	cpl	c
   052B 08                  855 	inc	r0
   052C E2                  856 	movx	a,@r0
   052D 9F                  857 	subb	a,r7
   052E F4                  858 	cpl	a
   052F F5 0B               859 	mov	(_updateLeds_sloc0_1_0 + 3),a
   0531 90 12 57            860 	mov	dptr,#_param_blink_period_ms
   0534 E4                  861 	clr	a
   0535 93                  862 	movc	a,@a+dptr
   0536 FA                  863 	mov	r2,a
   0537 74 01               864 	mov	a,#0x01
   0539 93                  865 	movc	a,@a+dptr
   053A FB                  866 	mov	r3,a
   053B 74 02               867 	mov	a,#0x02
   053D 93                  868 	movc	a,@a+dptr
   053E FE                  869 	mov	r6,a
   053F 74 03               870 	mov	a,#0x03
   0541 93                  871 	movc	a,@a+dptr
   0542 FF                  872 	mov	r7,a
   0543 78 04               873 	mov	r0,#__divslong_PARM_2
   0545 74 02               874 	mov	a,#0x02
   0547 F2                  875 	movx	@r0,a
   0548 08                  876 	inc	r0
   0549 E4                  877 	clr	a
   054A F2                  878 	movx	@r0,a
   054B 08                  879 	inc	r0
   054C F2                  880 	movx	@r0,a
   054D 08                  881 	inc	r0
   054E F2                  882 	movx	@r0,a
   054F 8A 82               883 	mov	dpl,r2
   0551 8B 83               884 	mov	dph,r3
   0553 8E F0               885 	mov	b,r6
   0555 EF                  886 	mov	a,r7
   0556 12 05 B3            887 	lcall	__divslong
   0559 AC 82               888 	mov	r4,dpl
   055B AD 83               889 	mov	r5,dph
   055D AE F0               890 	mov	r6,b
   055F FF                  891 	mov	r7,a
   0560 C3                  892 	clr	c
   0561 E5 08               893 	mov	a,_updateLeds_sloc0_1_0
   0563 9C                  894 	subb	a,r4
   0564 E5 09               895 	mov	a,(_updateLeds_sloc0_1_0 + 1)
   0566 9D                  896 	subb	a,r5
   0567 E5 0A               897 	mov	a,(_updateLeds_sloc0_1_0 + 2)
   0569 9E                  898 	subb	a,r6
   056A E5 0B               899 	mov	a,(_updateLeds_sloc0_1_0 + 3)
   056C 9F                  900 	subb	a,r7
   056D 40 31               901 	jc	00103$
                    0072    902 	C$example_blink_led.c$26$3$4 ==.
                            903 ;	apps/example_blink_led/example_blink_led.c:26: LED_RED(!LED_RED_STATE);
   056F E5 FF               904 	mov	a,_P2DIR
   0571 03                  905 	rr	a
   0572 54 01               906 	anl	a,#0x01
   0574 FF                  907 	mov	r7,a
   0575 B4 01 00            908 	cjne	a,#0x01,00110$
   0578                     909 00110$:
   0578 E4                  910 	clr	a
   0579 33                  911 	rlc	a
   057A FF                  912 	mov	r7,a
   057B 60 05               913 	jz	00105$
   057D 43 FF 02            914 	orl	_P2DIR,#0x02
   0580 80 07               915 	sjmp	00106$
   0582                     916 00105$:
   0582 AF FF               917 	mov	r7,_P2DIR
   0584 53 07 FD            918 	anl	ar7,#0xFD
   0587 8F FF               919 	mov	_P2DIR,r7
   0589                     920 00106$:
                    008C    921 	C$example_blink_led.c$27$2$3 ==.
                            922 ;	apps/example_blink_led/example_blink_led.c:27: lastToggle = getMs();
   0589 12 0A E1            923 	lcall	_getMs
   058C AC 82               924 	mov	r4,dpl
   058E AD 83               925 	mov	r5,dph
   0590 AE F0               926 	mov	r6,b
   0592 FF                  927 	mov	r7,a
   0593 78 00               928 	mov	r0,#_lastToggle
   0595 EC                  929 	mov	a,r4
   0596 F2                  930 	movx	@r0,a
   0597 08                  931 	inc	r0
   0598 ED                  932 	mov	a,r5
   0599 F2                  933 	movx	@r0,a
   059A 08                  934 	inc	r0
   059B EE                  935 	mov	a,r6
   059C F2                  936 	movx	@r0,a
   059D 08                  937 	inc	r0
   059E EF                  938 	mov	a,r7
   059F F2                  939 	movx	@r0,a
   05A0                     940 00103$:
                    00A3    941 	C$example_blink_led.c$29$2$1 ==.
                    00A3    942 	XG$updateLeds$0$0 ==.
   05A0 22                  943 	ret
                            944 ;------------------------------------------------------------
                            945 ;Allocation info for local variables in function 'main'
                            946 ;------------------------------------------------------------
                    00A4    947 	G$main$0$0 ==.
                    00A4    948 	C$example_blink_led.c$31$2$1 ==.
                            949 ;	apps/example_blink_led/example_blink_led.c:31: void main()
                            950 ;	-----------------------------------------
                            951 ;	 function main
                            952 ;	-----------------------------------------
   05A1                     953 _main:
                    00A4    954 	C$example_blink_led.c$33$1$1 ==.
                            955 ;	apps/example_blink_led/example_blink_led.c:33: systemInit();
   05A1 12 07 29            956 	lcall	_systemInit
                    00A7    957 	C$example_blink_led.c$34$1$1 ==.
                            958 ;	apps/example_blink_led/example_blink_led.c:34: usbInit();
   05A4 12 0B 48            959 	lcall	_usbInit
                    00AA    960 	C$example_blink_led.c$36$1$1 ==.
                            961 ;	apps/example_blink_led/example_blink_led.c:36: while(1)
   05A7                     962 00102$:
                    00AA    963 	C$example_blink_led.c$38$2$2 ==.
                            964 ;	apps/example_blink_led/example_blink_led.c:38: boardService();
   05A7 12 07 36            965 	lcall	_boardService
                    00AD    966 	C$example_blink_led.c$39$2$2 ==.
                            967 ;	apps/example_blink_led/example_blink_led.c:39: updateLeds();
   05AA 12 04 FD            968 	lcall	_updateLeds
                    00B0    969 	C$example_blink_led.c$40$2$2 ==.
                            970 ;	apps/example_blink_led/example_blink_led.c:40: usbComService();
   05AD 12 09 5A            971 	lcall	_usbComService
   05B0 80 F5               972 	sjmp	00102$
                    00B5    973 	C$example_blink_led.c$42$1$1 ==.
                    00B5    974 	XG$main$0$0 ==.
   05B2 22                  975 	ret
                            976 	.area CSEG    (CODE)
                            977 	.area CONST   (CODE)
                    0000    978 G$param_blink_period_ms$0$0 == .
   1257                     979 _param_blink_period_ms:
   1257 F4 01 00 00         980 	.byte #0xF4,#0x01,#0x00,#0x00	;  500
                            981 	.area XINIT   (CODE)
                            982 	.area CABS    (ABS,CODE)
