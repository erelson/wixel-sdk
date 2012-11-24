                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 23:15:49 2012
                              5 ;--------------------------------------------------------
                              6 	.module wireless_adc_rx
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _radioToUsbService
                             14 	.globl _updateLeds
                             15 	.globl _printf
                             16 	.globl _radioQueueRxDoneWithPacket
                             17 	.globl _radioQueueRxCurrentPacket
                             18 	.globl _radioQueueInit
                             19 	.globl _usbComTxSendByte
                             20 	.globl _usbComTxAvailable
                             21 	.globl _usbComService
                             22 	.globl _usbShowStatusWithGreenLed
                             23 	.globl _usbInit
                             24 	.globl _getMs
                             25 	.globl _boardService
                             26 	.globl _systemInit
                             27 	.globl _putchar
                             28 ;--------------------------------------------------------
                             29 ; special function registers
                             30 ;--------------------------------------------------------
                             31 	.area RSEG    (ABS,DATA)
   0000                      32 	.org 0x0000
                    0080     33 Fwireless_adc_rx$P0$0$0 == 0x0080
                    0080     34 _P0	=	0x0080
                    0081     35 Fwireless_adc_rx$SP$0$0 == 0x0081
                    0081     36 _SP	=	0x0081
                    0082     37 Fwireless_adc_rx$DPL0$0$0 == 0x0082
                    0082     38 _DPL0	=	0x0082
                    0083     39 Fwireless_adc_rx$DPH0$0$0 == 0x0083
                    0083     40 _DPH0	=	0x0083
                    0084     41 Fwireless_adc_rx$DPL1$0$0 == 0x0084
                    0084     42 _DPL1	=	0x0084
                    0085     43 Fwireless_adc_rx$DPH1$0$0 == 0x0085
                    0085     44 _DPH1	=	0x0085
                    0086     45 Fwireless_adc_rx$U0CSR$0$0 == 0x0086
                    0086     46 _U0CSR	=	0x0086
                    0087     47 Fwireless_adc_rx$PCON$0$0 == 0x0087
                    0087     48 _PCON	=	0x0087
                    0088     49 Fwireless_adc_rx$TCON$0$0 == 0x0088
                    0088     50 _TCON	=	0x0088
                    0089     51 Fwireless_adc_rx$P0IFG$0$0 == 0x0089
                    0089     52 _P0IFG	=	0x0089
                    008A     53 Fwireless_adc_rx$P1IFG$0$0 == 0x008a
                    008A     54 _P1IFG	=	0x008a
                    008B     55 Fwireless_adc_rx$P2IFG$0$0 == 0x008b
                    008B     56 _P2IFG	=	0x008b
                    008C     57 Fwireless_adc_rx$PICTL$0$0 == 0x008c
                    008C     58 _PICTL	=	0x008c
                    008D     59 Fwireless_adc_rx$P1IEN$0$0 == 0x008d
                    008D     60 _P1IEN	=	0x008d
                    008F     61 Fwireless_adc_rx$P0INP$0$0 == 0x008f
                    008F     62 _P0INP	=	0x008f
                    0090     63 Fwireless_adc_rx$P1$0$0 == 0x0090
                    0090     64 _P1	=	0x0090
                    0091     65 Fwireless_adc_rx$RFIM$0$0 == 0x0091
                    0091     66 _RFIM	=	0x0091
                    0092     67 Fwireless_adc_rx$DPS$0$0 == 0x0092
                    0092     68 _DPS	=	0x0092
                    0093     69 Fwireless_adc_rx$MPAGE$0$0 == 0x0093
                    0093     70 _MPAGE	=	0x0093
                    0095     71 Fwireless_adc_rx$ENDIAN$0$0 == 0x0095
                    0095     72 _ENDIAN	=	0x0095
                    0098     73 Fwireless_adc_rx$S0CON$0$0 == 0x0098
                    0098     74 _S0CON	=	0x0098
                    009A     75 Fwireless_adc_rx$IEN2$0$0 == 0x009a
                    009A     76 _IEN2	=	0x009a
                    009B     77 Fwireless_adc_rx$S1CON$0$0 == 0x009b
                    009B     78 _S1CON	=	0x009b
                    009C     79 Fwireless_adc_rx$T2CT$0$0 == 0x009c
                    009C     80 _T2CT	=	0x009c
                    009D     81 Fwireless_adc_rx$T2PR$0$0 == 0x009d
                    009D     82 _T2PR	=	0x009d
                    009E     83 Fwireless_adc_rx$T2CTL$0$0 == 0x009e
                    009E     84 _T2CTL	=	0x009e
                    00A0     85 Fwireless_adc_rx$P2$0$0 == 0x00a0
                    00A0     86 _P2	=	0x00a0
                    00A1     87 Fwireless_adc_rx$WORIRQ$0$0 == 0x00a1
                    00A1     88 _WORIRQ	=	0x00a1
                    00A2     89 Fwireless_adc_rx$WORCTRL$0$0 == 0x00a2
                    00A2     90 _WORCTRL	=	0x00a2
                    00A3     91 Fwireless_adc_rx$WOREVT0$0$0 == 0x00a3
                    00A3     92 _WOREVT0	=	0x00a3
                    00A4     93 Fwireless_adc_rx$WOREVT1$0$0 == 0x00a4
                    00A4     94 _WOREVT1	=	0x00a4
                    00A5     95 Fwireless_adc_rx$WORTIME0$0$0 == 0x00a5
                    00A5     96 _WORTIME0	=	0x00a5
                    00A6     97 Fwireless_adc_rx$WORTIME1$0$0 == 0x00a6
                    00A6     98 _WORTIME1	=	0x00a6
                    00A8     99 Fwireless_adc_rx$IEN0$0$0 == 0x00a8
                    00A8    100 _IEN0	=	0x00a8
                    00A9    101 Fwireless_adc_rx$IP0$0$0 == 0x00a9
                    00A9    102 _IP0	=	0x00a9
                    00AB    103 Fwireless_adc_rx$FWT$0$0 == 0x00ab
                    00AB    104 _FWT	=	0x00ab
                    00AC    105 Fwireless_adc_rx$FADDRL$0$0 == 0x00ac
                    00AC    106 _FADDRL	=	0x00ac
                    00AD    107 Fwireless_adc_rx$FADDRH$0$0 == 0x00ad
                    00AD    108 _FADDRH	=	0x00ad
                    00AE    109 Fwireless_adc_rx$FCTL$0$0 == 0x00ae
                    00AE    110 _FCTL	=	0x00ae
                    00AF    111 Fwireless_adc_rx$FWDATA$0$0 == 0x00af
                    00AF    112 _FWDATA	=	0x00af
                    00B1    113 Fwireless_adc_rx$ENCDI$0$0 == 0x00b1
                    00B1    114 _ENCDI	=	0x00b1
                    00B2    115 Fwireless_adc_rx$ENCDO$0$0 == 0x00b2
                    00B2    116 _ENCDO	=	0x00b2
                    00B3    117 Fwireless_adc_rx$ENCCS$0$0 == 0x00b3
                    00B3    118 _ENCCS	=	0x00b3
                    00B4    119 Fwireless_adc_rx$ADCCON1$0$0 == 0x00b4
                    00B4    120 _ADCCON1	=	0x00b4
                    00B5    121 Fwireless_adc_rx$ADCCON2$0$0 == 0x00b5
                    00B5    122 _ADCCON2	=	0x00b5
                    00B6    123 Fwireless_adc_rx$ADCCON3$0$0 == 0x00b6
                    00B6    124 _ADCCON3	=	0x00b6
                    00B8    125 Fwireless_adc_rx$IEN1$0$0 == 0x00b8
                    00B8    126 _IEN1	=	0x00b8
                    00B9    127 Fwireless_adc_rx$IP1$0$0 == 0x00b9
                    00B9    128 _IP1	=	0x00b9
                    00BA    129 Fwireless_adc_rx$ADCL$0$0 == 0x00ba
                    00BA    130 _ADCL	=	0x00ba
                    00BB    131 Fwireless_adc_rx$ADCH$0$0 == 0x00bb
                    00BB    132 _ADCH	=	0x00bb
                    00BC    133 Fwireless_adc_rx$RNDL$0$0 == 0x00bc
                    00BC    134 _RNDL	=	0x00bc
                    00BD    135 Fwireless_adc_rx$RNDH$0$0 == 0x00bd
                    00BD    136 _RNDH	=	0x00bd
                    00BE    137 Fwireless_adc_rx$SLEEP$0$0 == 0x00be
                    00BE    138 _SLEEP	=	0x00be
                    00C0    139 Fwireless_adc_rx$IRCON$0$0 == 0x00c0
                    00C0    140 _IRCON	=	0x00c0
                    00C1    141 Fwireless_adc_rx$U0DBUF$0$0 == 0x00c1
                    00C1    142 _U0DBUF	=	0x00c1
                    00C2    143 Fwireless_adc_rx$U0BAUD$0$0 == 0x00c2
                    00C2    144 _U0BAUD	=	0x00c2
                    00C4    145 Fwireless_adc_rx$U0UCR$0$0 == 0x00c4
                    00C4    146 _U0UCR	=	0x00c4
                    00C5    147 Fwireless_adc_rx$U0GCR$0$0 == 0x00c5
                    00C5    148 _U0GCR	=	0x00c5
                    00C6    149 Fwireless_adc_rx$CLKCON$0$0 == 0x00c6
                    00C6    150 _CLKCON	=	0x00c6
                    00C7    151 Fwireless_adc_rx$MEMCTR$0$0 == 0x00c7
                    00C7    152 _MEMCTR	=	0x00c7
                    00C9    153 Fwireless_adc_rx$WDCTL$0$0 == 0x00c9
                    00C9    154 _WDCTL	=	0x00c9
                    00CA    155 Fwireless_adc_rx$T3CNT$0$0 == 0x00ca
                    00CA    156 _T3CNT	=	0x00ca
                    00CB    157 Fwireless_adc_rx$T3CTL$0$0 == 0x00cb
                    00CB    158 _T3CTL	=	0x00cb
                    00CC    159 Fwireless_adc_rx$T3CCTL0$0$0 == 0x00cc
                    00CC    160 _T3CCTL0	=	0x00cc
                    00CD    161 Fwireless_adc_rx$T3CC0$0$0 == 0x00cd
                    00CD    162 _T3CC0	=	0x00cd
                    00CE    163 Fwireless_adc_rx$T3CCTL1$0$0 == 0x00ce
                    00CE    164 _T3CCTL1	=	0x00ce
                    00CF    165 Fwireless_adc_rx$T3CC1$0$0 == 0x00cf
                    00CF    166 _T3CC1	=	0x00cf
                    00D0    167 Fwireless_adc_rx$PSW$0$0 == 0x00d0
                    00D0    168 _PSW	=	0x00d0
                    00D1    169 Fwireless_adc_rx$DMAIRQ$0$0 == 0x00d1
                    00D1    170 _DMAIRQ	=	0x00d1
                    00D2    171 Fwireless_adc_rx$DMA1CFGL$0$0 == 0x00d2
                    00D2    172 _DMA1CFGL	=	0x00d2
                    00D3    173 Fwireless_adc_rx$DMA1CFGH$0$0 == 0x00d3
                    00D3    174 _DMA1CFGH	=	0x00d3
                    00D4    175 Fwireless_adc_rx$DMA0CFGL$0$0 == 0x00d4
                    00D4    176 _DMA0CFGL	=	0x00d4
                    00D5    177 Fwireless_adc_rx$DMA0CFGH$0$0 == 0x00d5
                    00D5    178 _DMA0CFGH	=	0x00d5
                    00D6    179 Fwireless_adc_rx$DMAARM$0$0 == 0x00d6
                    00D6    180 _DMAARM	=	0x00d6
                    00D7    181 Fwireless_adc_rx$DMAREQ$0$0 == 0x00d7
                    00D7    182 _DMAREQ	=	0x00d7
                    00D8    183 Fwireless_adc_rx$TIMIF$0$0 == 0x00d8
                    00D8    184 _TIMIF	=	0x00d8
                    00D9    185 Fwireless_adc_rx$RFD$0$0 == 0x00d9
                    00D9    186 _RFD	=	0x00d9
                    00DA    187 Fwireless_adc_rx$T1CC0L$0$0 == 0x00da
                    00DA    188 _T1CC0L	=	0x00da
                    00DB    189 Fwireless_adc_rx$T1CC0H$0$0 == 0x00db
                    00DB    190 _T1CC0H	=	0x00db
                    00DC    191 Fwireless_adc_rx$T1CC1L$0$0 == 0x00dc
                    00DC    192 _T1CC1L	=	0x00dc
                    00DD    193 Fwireless_adc_rx$T1CC1H$0$0 == 0x00dd
                    00DD    194 _T1CC1H	=	0x00dd
                    00DE    195 Fwireless_adc_rx$T1CC2L$0$0 == 0x00de
                    00DE    196 _T1CC2L	=	0x00de
                    00DF    197 Fwireless_adc_rx$T1CC2H$0$0 == 0x00df
                    00DF    198 _T1CC2H	=	0x00df
                    00E0    199 Fwireless_adc_rx$ACC$0$0 == 0x00e0
                    00E0    200 _ACC	=	0x00e0
                    00E1    201 Fwireless_adc_rx$RFST$0$0 == 0x00e1
                    00E1    202 _RFST	=	0x00e1
                    00E2    203 Fwireless_adc_rx$T1CNTL$0$0 == 0x00e2
                    00E2    204 _T1CNTL	=	0x00e2
                    00E3    205 Fwireless_adc_rx$T1CNTH$0$0 == 0x00e3
                    00E3    206 _T1CNTH	=	0x00e3
                    00E4    207 Fwireless_adc_rx$T1CTL$0$0 == 0x00e4
                    00E4    208 _T1CTL	=	0x00e4
                    00E5    209 Fwireless_adc_rx$T1CCTL0$0$0 == 0x00e5
                    00E5    210 _T1CCTL0	=	0x00e5
                    00E6    211 Fwireless_adc_rx$T1CCTL1$0$0 == 0x00e6
                    00E6    212 _T1CCTL1	=	0x00e6
                    00E7    213 Fwireless_adc_rx$T1CCTL2$0$0 == 0x00e7
                    00E7    214 _T1CCTL2	=	0x00e7
                    00E8    215 Fwireless_adc_rx$IRCON2$0$0 == 0x00e8
                    00E8    216 _IRCON2	=	0x00e8
                    00E9    217 Fwireless_adc_rx$RFIF$0$0 == 0x00e9
                    00E9    218 _RFIF	=	0x00e9
                    00EA    219 Fwireless_adc_rx$T4CNT$0$0 == 0x00ea
                    00EA    220 _T4CNT	=	0x00ea
                    00EB    221 Fwireless_adc_rx$T4CTL$0$0 == 0x00eb
                    00EB    222 _T4CTL	=	0x00eb
                    00EC    223 Fwireless_adc_rx$T4CCTL0$0$0 == 0x00ec
                    00EC    224 _T4CCTL0	=	0x00ec
                    00ED    225 Fwireless_adc_rx$T4CC0$0$0 == 0x00ed
                    00ED    226 _T4CC0	=	0x00ed
                    00EE    227 Fwireless_adc_rx$T4CCTL1$0$0 == 0x00ee
                    00EE    228 _T4CCTL1	=	0x00ee
                    00EF    229 Fwireless_adc_rx$T4CC1$0$0 == 0x00ef
                    00EF    230 _T4CC1	=	0x00ef
                    00F0    231 Fwireless_adc_rx$B$0$0 == 0x00f0
                    00F0    232 _B	=	0x00f0
                    00F1    233 Fwireless_adc_rx$PERCFG$0$0 == 0x00f1
                    00F1    234 _PERCFG	=	0x00f1
                    00F2    235 Fwireless_adc_rx$ADCCFG$0$0 == 0x00f2
                    00F2    236 _ADCCFG	=	0x00f2
                    00F3    237 Fwireless_adc_rx$P0SEL$0$0 == 0x00f3
                    00F3    238 _P0SEL	=	0x00f3
                    00F4    239 Fwireless_adc_rx$P1SEL$0$0 == 0x00f4
                    00F4    240 _P1SEL	=	0x00f4
                    00F5    241 Fwireless_adc_rx$P2SEL$0$0 == 0x00f5
                    00F5    242 _P2SEL	=	0x00f5
                    00F6    243 Fwireless_adc_rx$P1INP$0$0 == 0x00f6
                    00F6    244 _P1INP	=	0x00f6
                    00F7    245 Fwireless_adc_rx$P2INP$0$0 == 0x00f7
                    00F7    246 _P2INP	=	0x00f7
                    00F8    247 Fwireless_adc_rx$U1CSR$0$0 == 0x00f8
                    00F8    248 _U1CSR	=	0x00f8
                    00F9    249 Fwireless_adc_rx$U1DBUF$0$0 == 0x00f9
                    00F9    250 _U1DBUF	=	0x00f9
                    00FA    251 Fwireless_adc_rx$U1BAUD$0$0 == 0x00fa
                    00FA    252 _U1BAUD	=	0x00fa
                    00FB    253 Fwireless_adc_rx$U1UCR$0$0 == 0x00fb
                    00FB    254 _U1UCR	=	0x00fb
                    00FC    255 Fwireless_adc_rx$U1GCR$0$0 == 0x00fc
                    00FC    256 _U1GCR	=	0x00fc
                    00FD    257 Fwireless_adc_rx$P0DIR$0$0 == 0x00fd
                    00FD    258 _P0DIR	=	0x00fd
                    00FE    259 Fwireless_adc_rx$P1DIR$0$0 == 0x00fe
                    00FE    260 _P1DIR	=	0x00fe
                    00FF    261 Fwireless_adc_rx$P2DIR$0$0 == 0x00ff
                    00FF    262 _P2DIR	=	0x00ff
                    FFFFD5D4    263 Fwireless_adc_rx$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    264 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    265 Fwireless_adc_rx$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    266 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    267 Fwireless_adc_rx$FADDR$0$0 == 0xffffadac
                    FFFFADAC    268 _FADDR	=	0xffffadac
                    FFFFBBBA    269 Fwireless_adc_rx$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    270 _ADC	=	0xffffbbba
                    FFFFDBDA    271 Fwireless_adc_rx$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    272 _T1CC0	=	0xffffdbda
                    FFFFDDDC    273 Fwireless_adc_rx$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    274 _T1CC1	=	0xffffdddc
                    FFFFDFDE    275 Fwireless_adc_rx$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    276 _T1CC2	=	0xffffdfde
                            277 ;--------------------------------------------------------
                            278 ; special function bits
                            279 ;--------------------------------------------------------
                            280 	.area RSEG    (ABS,DATA)
   0000                     281 	.org 0x0000
                    0080    282 Fwireless_adc_rx$P0_0$0$0 == 0x0080
                    0080    283 _P0_0	=	0x0080
                    0081    284 Fwireless_adc_rx$P0_1$0$0 == 0x0081
                    0081    285 _P0_1	=	0x0081
                    0082    286 Fwireless_adc_rx$P0_2$0$0 == 0x0082
                    0082    287 _P0_2	=	0x0082
                    0083    288 Fwireless_adc_rx$P0_3$0$0 == 0x0083
                    0083    289 _P0_3	=	0x0083
                    0084    290 Fwireless_adc_rx$P0_4$0$0 == 0x0084
                    0084    291 _P0_4	=	0x0084
                    0085    292 Fwireless_adc_rx$P0_5$0$0 == 0x0085
                    0085    293 _P0_5	=	0x0085
                    0086    294 Fwireless_adc_rx$P0_6$0$0 == 0x0086
                    0086    295 _P0_6	=	0x0086
                    0087    296 Fwireless_adc_rx$P0_7$0$0 == 0x0087
                    0087    297 _P0_7	=	0x0087
                    0088    298 Fwireless_adc_rx$_TCON_0$0$0 == 0x0088
                    0088    299 __TCON_0	=	0x0088
                    0089    300 Fwireless_adc_rx$RFTXRXIF$0$0 == 0x0089
                    0089    301 _RFTXRXIF	=	0x0089
                    008A    302 Fwireless_adc_rx$_TCON_2$0$0 == 0x008a
                    008A    303 __TCON_2	=	0x008a
                    008B    304 Fwireless_adc_rx$URX0IF$0$0 == 0x008b
                    008B    305 _URX0IF	=	0x008b
                    008C    306 Fwireless_adc_rx$_TCON_4$0$0 == 0x008c
                    008C    307 __TCON_4	=	0x008c
                    008D    308 Fwireless_adc_rx$ADCIF$0$0 == 0x008d
                    008D    309 _ADCIF	=	0x008d
                    008E    310 Fwireless_adc_rx$_TCON_6$0$0 == 0x008e
                    008E    311 __TCON_6	=	0x008e
                    008F    312 Fwireless_adc_rx$URX1IF$0$0 == 0x008f
                    008F    313 _URX1IF	=	0x008f
                    0090    314 Fwireless_adc_rx$P1_0$0$0 == 0x0090
                    0090    315 _P1_0	=	0x0090
                    0091    316 Fwireless_adc_rx$P1_1$0$0 == 0x0091
                    0091    317 _P1_1	=	0x0091
                    0092    318 Fwireless_adc_rx$P1_2$0$0 == 0x0092
                    0092    319 _P1_2	=	0x0092
                    0093    320 Fwireless_adc_rx$P1_3$0$0 == 0x0093
                    0093    321 _P1_3	=	0x0093
                    0094    322 Fwireless_adc_rx$P1_4$0$0 == 0x0094
                    0094    323 _P1_4	=	0x0094
                    0095    324 Fwireless_adc_rx$P1_5$0$0 == 0x0095
                    0095    325 _P1_5	=	0x0095
                    0096    326 Fwireless_adc_rx$P1_6$0$0 == 0x0096
                    0096    327 _P1_6	=	0x0096
                    0097    328 Fwireless_adc_rx$P1_7$0$0 == 0x0097
                    0097    329 _P1_7	=	0x0097
                    0098    330 Fwireless_adc_rx$ENCIF_0$0$0 == 0x0098
                    0098    331 _ENCIF_0	=	0x0098
                    0099    332 Fwireless_adc_rx$ENCIF_1$0$0 == 0x0099
                    0099    333 _ENCIF_1	=	0x0099
                    009A    334 Fwireless_adc_rx$_SOCON2$0$0 == 0x009a
                    009A    335 __SOCON2	=	0x009a
                    009B    336 Fwireless_adc_rx$_SOCON3$0$0 == 0x009b
                    009B    337 __SOCON3	=	0x009b
                    009C    338 Fwireless_adc_rx$_SOCON4$0$0 == 0x009c
                    009C    339 __SOCON4	=	0x009c
                    009D    340 Fwireless_adc_rx$_SOCON5$0$0 == 0x009d
                    009D    341 __SOCON5	=	0x009d
                    009E    342 Fwireless_adc_rx$_SOCON6$0$0 == 0x009e
                    009E    343 __SOCON6	=	0x009e
                    009F    344 Fwireless_adc_rx$_SOCON7$0$0 == 0x009f
                    009F    345 __SOCON7	=	0x009f
                    00A0    346 Fwireless_adc_rx$P2_0$0$0 == 0x00a0
                    00A0    347 _P2_0	=	0x00a0
                    00A1    348 Fwireless_adc_rx$P2_1$0$0 == 0x00a1
                    00A1    349 _P2_1	=	0x00a1
                    00A2    350 Fwireless_adc_rx$P2_2$0$0 == 0x00a2
                    00A2    351 _P2_2	=	0x00a2
                    00A3    352 Fwireless_adc_rx$P2_3$0$0 == 0x00a3
                    00A3    353 _P2_3	=	0x00a3
                    00A4    354 Fwireless_adc_rx$P2_4$0$0 == 0x00a4
                    00A4    355 _P2_4	=	0x00a4
                    00A5    356 Fwireless_adc_rx$P2_5$0$0 == 0x00a5
                    00A5    357 _P2_5	=	0x00a5
                    00A6    358 Fwireless_adc_rx$P2_6$0$0 == 0x00a6
                    00A6    359 _P2_6	=	0x00a6
                    00A7    360 Fwireless_adc_rx$P2_7$0$0 == 0x00a7
                    00A7    361 _P2_7	=	0x00a7
                    00A8    362 Fwireless_adc_rx$RFTXRXIE$0$0 == 0x00a8
                    00A8    363 _RFTXRXIE	=	0x00a8
                    00A9    364 Fwireless_adc_rx$ADCIE$0$0 == 0x00a9
                    00A9    365 _ADCIE	=	0x00a9
                    00AA    366 Fwireless_adc_rx$URX0IE$0$0 == 0x00aa
                    00AA    367 _URX0IE	=	0x00aa
                    00AB    368 Fwireless_adc_rx$URX1IE$0$0 == 0x00ab
                    00AB    369 _URX1IE	=	0x00ab
                    00AC    370 Fwireless_adc_rx$ENCIE$0$0 == 0x00ac
                    00AC    371 _ENCIE	=	0x00ac
                    00AD    372 Fwireless_adc_rx$STIE$0$0 == 0x00ad
                    00AD    373 _STIE	=	0x00ad
                    00AE    374 Fwireless_adc_rx$_IEN06$0$0 == 0x00ae
                    00AE    375 __IEN06	=	0x00ae
                    00AF    376 Fwireless_adc_rx$EA$0$0 == 0x00af
                    00AF    377 _EA	=	0x00af
                    00B8    378 Fwireless_adc_rx$DMAIE$0$0 == 0x00b8
                    00B8    379 _DMAIE	=	0x00b8
                    00B9    380 Fwireless_adc_rx$T1IE$0$0 == 0x00b9
                    00B9    381 _T1IE	=	0x00b9
                    00BA    382 Fwireless_adc_rx$T2IE$0$0 == 0x00ba
                    00BA    383 _T2IE	=	0x00ba
                    00BB    384 Fwireless_adc_rx$T3IE$0$0 == 0x00bb
                    00BB    385 _T3IE	=	0x00bb
                    00BC    386 Fwireless_adc_rx$T4IE$0$0 == 0x00bc
                    00BC    387 _T4IE	=	0x00bc
                    00BD    388 Fwireless_adc_rx$P0IE$0$0 == 0x00bd
                    00BD    389 _P0IE	=	0x00bd
                    00BE    390 Fwireless_adc_rx$_IEN16$0$0 == 0x00be
                    00BE    391 __IEN16	=	0x00be
                    00BF    392 Fwireless_adc_rx$_IEN17$0$0 == 0x00bf
                    00BF    393 __IEN17	=	0x00bf
                    00C0    394 Fwireless_adc_rx$DMAIF$0$0 == 0x00c0
                    00C0    395 _DMAIF	=	0x00c0
                    00C1    396 Fwireless_adc_rx$T1IF$0$0 == 0x00c1
                    00C1    397 _T1IF	=	0x00c1
                    00C2    398 Fwireless_adc_rx$T2IF$0$0 == 0x00c2
                    00C2    399 _T2IF	=	0x00c2
                    00C3    400 Fwireless_adc_rx$T3IF$0$0 == 0x00c3
                    00C3    401 _T3IF	=	0x00c3
                    00C4    402 Fwireless_adc_rx$T4IF$0$0 == 0x00c4
                    00C4    403 _T4IF	=	0x00c4
                    00C5    404 Fwireless_adc_rx$P0IF$0$0 == 0x00c5
                    00C5    405 _P0IF	=	0x00c5
                    00C6    406 Fwireless_adc_rx$_IRCON6$0$0 == 0x00c6
                    00C6    407 __IRCON6	=	0x00c6
                    00C7    408 Fwireless_adc_rx$STIF$0$0 == 0x00c7
                    00C7    409 _STIF	=	0x00c7
                    00D0    410 Fwireless_adc_rx$P$0$0 == 0x00d0
                    00D0    411 _P	=	0x00d0
                    00D1    412 Fwireless_adc_rx$F1$0$0 == 0x00d1
                    00D1    413 _F1	=	0x00d1
                    00D2    414 Fwireless_adc_rx$OV$0$0 == 0x00d2
                    00D2    415 _OV	=	0x00d2
                    00D3    416 Fwireless_adc_rx$RS0$0$0 == 0x00d3
                    00D3    417 _RS0	=	0x00d3
                    00D4    418 Fwireless_adc_rx$RS1$0$0 == 0x00d4
                    00D4    419 _RS1	=	0x00d4
                    00D5    420 Fwireless_adc_rx$F0$0$0 == 0x00d5
                    00D5    421 _F0	=	0x00d5
                    00D6    422 Fwireless_adc_rx$AC$0$0 == 0x00d6
                    00D6    423 _AC	=	0x00d6
                    00D7    424 Fwireless_adc_rx$CY$0$0 == 0x00d7
                    00D7    425 _CY	=	0x00d7
                    00D8    426 Fwireless_adc_rx$T3OVFIF$0$0 == 0x00d8
                    00D8    427 _T3OVFIF	=	0x00d8
                    00D9    428 Fwireless_adc_rx$T3CH0IF$0$0 == 0x00d9
                    00D9    429 _T3CH0IF	=	0x00d9
                    00DA    430 Fwireless_adc_rx$T3CH1IF$0$0 == 0x00da
                    00DA    431 _T3CH1IF	=	0x00da
                    00DB    432 Fwireless_adc_rx$T4OVFIF$0$0 == 0x00db
                    00DB    433 _T4OVFIF	=	0x00db
                    00DC    434 Fwireless_adc_rx$T4CH0IF$0$0 == 0x00dc
                    00DC    435 _T4CH0IF	=	0x00dc
                    00DD    436 Fwireless_adc_rx$T4CH1IF$0$0 == 0x00dd
                    00DD    437 _T4CH1IF	=	0x00dd
                    00DE    438 Fwireless_adc_rx$OVFIM$0$0 == 0x00de
                    00DE    439 _OVFIM	=	0x00de
                    00DF    440 Fwireless_adc_rx$_TIMIF7$0$0 == 0x00df
                    00DF    441 __TIMIF7	=	0x00df
                    00E0    442 Fwireless_adc_rx$ACC_0$0$0 == 0x00e0
                    00E0    443 _ACC_0	=	0x00e0
                    00E1    444 Fwireless_adc_rx$ACC_1$0$0 == 0x00e1
                    00E1    445 _ACC_1	=	0x00e1
                    00E2    446 Fwireless_adc_rx$ACC_2$0$0 == 0x00e2
                    00E2    447 _ACC_2	=	0x00e2
                    00E3    448 Fwireless_adc_rx$ACC_3$0$0 == 0x00e3
                    00E3    449 _ACC_3	=	0x00e3
                    00E4    450 Fwireless_adc_rx$ACC_4$0$0 == 0x00e4
                    00E4    451 _ACC_4	=	0x00e4
                    00E5    452 Fwireless_adc_rx$ACC_5$0$0 == 0x00e5
                    00E5    453 _ACC_5	=	0x00e5
                    00E6    454 Fwireless_adc_rx$ACC_6$0$0 == 0x00e6
                    00E6    455 _ACC_6	=	0x00e6
                    00E7    456 Fwireless_adc_rx$ACC_7$0$0 == 0x00e7
                    00E7    457 _ACC_7	=	0x00e7
                    00E8    458 Fwireless_adc_rx$P2IF$0$0 == 0x00e8
                    00E8    459 _P2IF	=	0x00e8
                    00E9    460 Fwireless_adc_rx$UTX0IF$0$0 == 0x00e9
                    00E9    461 _UTX0IF	=	0x00e9
                    00EA    462 Fwireless_adc_rx$UTX1IF$0$0 == 0x00ea
                    00EA    463 _UTX1IF	=	0x00ea
                    00EB    464 Fwireless_adc_rx$P1IF$0$0 == 0x00eb
                    00EB    465 _P1IF	=	0x00eb
                    00EC    466 Fwireless_adc_rx$WDTIF$0$0 == 0x00ec
                    00EC    467 _WDTIF	=	0x00ec
                    00ED    468 Fwireless_adc_rx$_IRCON25$0$0 == 0x00ed
                    00ED    469 __IRCON25	=	0x00ed
                    00EE    470 Fwireless_adc_rx$_IRCON26$0$0 == 0x00ee
                    00EE    471 __IRCON26	=	0x00ee
                    00EF    472 Fwireless_adc_rx$_IRCON27$0$0 == 0x00ef
                    00EF    473 __IRCON27	=	0x00ef
                    00F0    474 Fwireless_adc_rx$B_0$0$0 == 0x00f0
                    00F0    475 _B_0	=	0x00f0
                    00F1    476 Fwireless_adc_rx$B_1$0$0 == 0x00f1
                    00F1    477 _B_1	=	0x00f1
                    00F2    478 Fwireless_adc_rx$B_2$0$0 == 0x00f2
                    00F2    479 _B_2	=	0x00f2
                    00F3    480 Fwireless_adc_rx$B_3$0$0 == 0x00f3
                    00F3    481 _B_3	=	0x00f3
                    00F4    482 Fwireless_adc_rx$B_4$0$0 == 0x00f4
                    00F4    483 _B_4	=	0x00f4
                    00F5    484 Fwireless_adc_rx$B_5$0$0 == 0x00f5
                    00F5    485 _B_5	=	0x00f5
                    00F6    486 Fwireless_adc_rx$B_6$0$0 == 0x00f6
                    00F6    487 _B_6	=	0x00f6
                    00F7    488 Fwireless_adc_rx$B_7$0$0 == 0x00f7
                    00F7    489 _B_7	=	0x00f7
                    00F8    490 Fwireless_adc_rx$U1ACTIVE$0$0 == 0x00f8
                    00F8    491 _U1ACTIVE	=	0x00f8
                    00F9    492 Fwireless_adc_rx$U1TX_BYTE$0$0 == 0x00f9
                    00F9    493 _U1TX_BYTE	=	0x00f9
                    00FA    494 Fwireless_adc_rx$U1RX_BYTE$0$0 == 0x00fa
                    00FA    495 _U1RX_BYTE	=	0x00fa
                    00FB    496 Fwireless_adc_rx$U1ERR$0$0 == 0x00fb
                    00FB    497 _U1ERR	=	0x00fb
                    00FC    498 Fwireless_adc_rx$U1FE$0$0 == 0x00fc
                    00FC    499 _U1FE	=	0x00fc
                    00FD    500 Fwireless_adc_rx$U1SLAVE$0$0 == 0x00fd
                    00FD    501 _U1SLAVE	=	0x00fd
                    00FE    502 Fwireless_adc_rx$U1RE$0$0 == 0x00fe
                    00FE    503 _U1RE	=	0x00fe
                    00FF    504 Fwireless_adc_rx$U1MODE$0$0 == 0x00ff
                    00FF    505 _U1MODE	=	0x00ff
                            506 ;--------------------------------------------------------
                            507 ; overlayable register banks
                            508 ;--------------------------------------------------------
                            509 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     510 	.ds 8
                            511 ;--------------------------------------------------------
                            512 ; internal ram data
                            513 ;--------------------------------------------------------
                            514 	.area DSEG    (DATA)
                    0000    515 Lwireless_adc_rx.radioToUsbService$sloc0$1$0==.
   0008                     516 _radioToUsbService_sloc0_1_0:
   0008                     517 	.ds 1
                    0001    518 Lwireless_adc_rx.radioToUsbService$sloc1$1$0==.
   0009                     519 _radioToUsbService_sloc1_1_0:
   0009                     520 	.ds 2
                    0003    521 Lwireless_adc_rx.radioToUsbService$sloc2$1$0==.
   000B                     522 _radioToUsbService_sloc2_1_0:
   000B                     523 	.ds 2
                            524 ;--------------------------------------------------------
                            525 ; overlayable items in internal ram 
                            526 ;--------------------------------------------------------
                            527 	.area OSEG    (OVR,DATA)
                            528 ;--------------------------------------------------------
                            529 ; Stack segment in internal ram 
                            530 ;--------------------------------------------------------
                            531 	.area	SSEG	(DATA)
   0024                     532 __start__stack:
   0024                     533 	.ds	1
                            534 
                            535 ;--------------------------------------------------------
                            536 ; indirectly addressable internal ram data
                            537 ;--------------------------------------------------------
                            538 	.area ISEG    (DATA)
                            539 ;--------------------------------------------------------
                            540 ; absolute internal ram data
                            541 ;--------------------------------------------------------
                            542 	.area IABS    (ABS,DATA)
                            543 	.area IABS    (ABS,DATA)
                            544 ;--------------------------------------------------------
                            545 ; bit data
                            546 ;--------------------------------------------------------
                            547 	.area BSEG    (BIT)
                            548 ;--------------------------------------------------------
                            549 ; paged external ram data
                            550 ;--------------------------------------------------------
                            551 	.area PSEG    (PAG,XDATA)
                    0000    552 Lwireless_adc_rx.radioToUsbService$rxPacket$1$1==.
   F000                     553 _radioToUsbService_rxPacket_1_1:
   F000                     554 	.ds 2
                            555 ;--------------------------------------------------------
                            556 ; external ram data
                            557 ;--------------------------------------------------------
                            558 	.area XSEG    (XDATA)
                    DF00    559 Fwireless_adc_rx$SYNC1$0$0 == 0xdf00
                    DF00    560 _SYNC1	=	0xdf00
                    DF01    561 Fwireless_adc_rx$SYNC0$0$0 == 0xdf01
                    DF01    562 _SYNC0	=	0xdf01
                    DF02    563 Fwireless_adc_rx$PKTLEN$0$0 == 0xdf02
                    DF02    564 _PKTLEN	=	0xdf02
                    DF03    565 Fwireless_adc_rx$PKTCTRL1$0$0 == 0xdf03
                    DF03    566 _PKTCTRL1	=	0xdf03
                    DF04    567 Fwireless_adc_rx$PKTCTRL0$0$0 == 0xdf04
                    DF04    568 _PKTCTRL0	=	0xdf04
                    DF05    569 Fwireless_adc_rx$ADDR$0$0 == 0xdf05
                    DF05    570 _ADDR	=	0xdf05
                    DF06    571 Fwireless_adc_rx$CHANNR$0$0 == 0xdf06
                    DF06    572 _CHANNR	=	0xdf06
                    DF07    573 Fwireless_adc_rx$FSCTRL1$0$0 == 0xdf07
                    DF07    574 _FSCTRL1	=	0xdf07
                    DF08    575 Fwireless_adc_rx$FSCTRL0$0$0 == 0xdf08
                    DF08    576 _FSCTRL0	=	0xdf08
                    DF09    577 Fwireless_adc_rx$FREQ2$0$0 == 0xdf09
                    DF09    578 _FREQ2	=	0xdf09
                    DF0A    579 Fwireless_adc_rx$FREQ1$0$0 == 0xdf0a
                    DF0A    580 _FREQ1	=	0xdf0a
                    DF0B    581 Fwireless_adc_rx$FREQ0$0$0 == 0xdf0b
                    DF0B    582 _FREQ0	=	0xdf0b
                    DF0C    583 Fwireless_adc_rx$MDMCFG4$0$0 == 0xdf0c
                    DF0C    584 _MDMCFG4	=	0xdf0c
                    DF0D    585 Fwireless_adc_rx$MDMCFG3$0$0 == 0xdf0d
                    DF0D    586 _MDMCFG3	=	0xdf0d
                    DF0E    587 Fwireless_adc_rx$MDMCFG2$0$0 == 0xdf0e
                    DF0E    588 _MDMCFG2	=	0xdf0e
                    DF0F    589 Fwireless_adc_rx$MDMCFG1$0$0 == 0xdf0f
                    DF0F    590 _MDMCFG1	=	0xdf0f
                    DF10    591 Fwireless_adc_rx$MDMCFG0$0$0 == 0xdf10
                    DF10    592 _MDMCFG0	=	0xdf10
                    DF11    593 Fwireless_adc_rx$DEVIATN$0$0 == 0xdf11
                    DF11    594 _DEVIATN	=	0xdf11
                    DF12    595 Fwireless_adc_rx$MCSM2$0$0 == 0xdf12
                    DF12    596 _MCSM2	=	0xdf12
                    DF13    597 Fwireless_adc_rx$MCSM1$0$0 == 0xdf13
                    DF13    598 _MCSM1	=	0xdf13
                    DF14    599 Fwireless_adc_rx$MCSM0$0$0 == 0xdf14
                    DF14    600 _MCSM0	=	0xdf14
                    DF15    601 Fwireless_adc_rx$FOCCFG$0$0 == 0xdf15
                    DF15    602 _FOCCFG	=	0xdf15
                    DF16    603 Fwireless_adc_rx$BSCFG$0$0 == 0xdf16
                    DF16    604 _BSCFG	=	0xdf16
                    DF17    605 Fwireless_adc_rx$AGCCTRL2$0$0 == 0xdf17
                    DF17    606 _AGCCTRL2	=	0xdf17
                    DF18    607 Fwireless_adc_rx$AGCCTRL1$0$0 == 0xdf18
                    DF18    608 _AGCCTRL1	=	0xdf18
                    DF19    609 Fwireless_adc_rx$AGCCTRL0$0$0 == 0xdf19
                    DF19    610 _AGCCTRL0	=	0xdf19
                    DF1A    611 Fwireless_adc_rx$FREND1$0$0 == 0xdf1a
                    DF1A    612 _FREND1	=	0xdf1a
                    DF1B    613 Fwireless_adc_rx$FREND0$0$0 == 0xdf1b
                    DF1B    614 _FREND0	=	0xdf1b
                    DF1C    615 Fwireless_adc_rx$FSCAL3$0$0 == 0xdf1c
                    DF1C    616 _FSCAL3	=	0xdf1c
                    DF1D    617 Fwireless_adc_rx$FSCAL2$0$0 == 0xdf1d
                    DF1D    618 _FSCAL2	=	0xdf1d
                    DF1E    619 Fwireless_adc_rx$FSCAL1$0$0 == 0xdf1e
                    DF1E    620 _FSCAL1	=	0xdf1e
                    DF1F    621 Fwireless_adc_rx$FSCAL0$0$0 == 0xdf1f
                    DF1F    622 _FSCAL0	=	0xdf1f
                    DF23    623 Fwireless_adc_rx$TEST2$0$0 == 0xdf23
                    DF23    624 _TEST2	=	0xdf23
                    DF24    625 Fwireless_adc_rx$TEST1$0$0 == 0xdf24
                    DF24    626 _TEST1	=	0xdf24
                    DF25    627 Fwireless_adc_rx$TEST0$0$0 == 0xdf25
                    DF25    628 _TEST0	=	0xdf25
                    DF2E    629 Fwireless_adc_rx$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    630 _PA_TABLE0	=	0xdf2e
                    DF2F    631 Fwireless_adc_rx$IOCFG2$0$0 == 0xdf2f
                    DF2F    632 _IOCFG2	=	0xdf2f
                    DF30    633 Fwireless_adc_rx$IOCFG1$0$0 == 0xdf30
                    DF30    634 _IOCFG1	=	0xdf30
                    DF31    635 Fwireless_adc_rx$IOCFG0$0$0 == 0xdf31
                    DF31    636 _IOCFG0	=	0xdf31
                    DF36    637 Fwireless_adc_rx$PARTNUM$0$0 == 0xdf36
                    DF36    638 _PARTNUM	=	0xdf36
                    DF37    639 Fwireless_adc_rx$VERSION$0$0 == 0xdf37
                    DF37    640 _VERSION	=	0xdf37
                    DF38    641 Fwireless_adc_rx$FREQEST$0$0 == 0xdf38
                    DF38    642 _FREQEST	=	0xdf38
                    DF39    643 Fwireless_adc_rx$LQI$0$0 == 0xdf39
                    DF39    644 _LQI	=	0xdf39
                    DF3A    645 Fwireless_adc_rx$RSSI$0$0 == 0xdf3a
                    DF3A    646 _RSSI	=	0xdf3a
                    DF3B    647 Fwireless_adc_rx$MARCSTATE$0$0 == 0xdf3b
                    DF3B    648 _MARCSTATE	=	0xdf3b
                    DF3C    649 Fwireless_adc_rx$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    650 _PKTSTATUS	=	0xdf3c
                    DF3D    651 Fwireless_adc_rx$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    652 _VCO_VC_DAC	=	0xdf3d
                    DF40    653 Fwireless_adc_rx$I2SCFG0$0$0 == 0xdf40
                    DF40    654 _I2SCFG0	=	0xdf40
                    DF41    655 Fwireless_adc_rx$I2SCFG1$0$0 == 0xdf41
                    DF41    656 _I2SCFG1	=	0xdf41
                    DF42    657 Fwireless_adc_rx$I2SDATL$0$0 == 0xdf42
                    DF42    658 _I2SDATL	=	0xdf42
                    DF43    659 Fwireless_adc_rx$I2SDATH$0$0 == 0xdf43
                    DF43    660 _I2SDATH	=	0xdf43
                    DF44    661 Fwireless_adc_rx$I2SWCNT$0$0 == 0xdf44
                    DF44    662 _I2SWCNT	=	0xdf44
                    DF45    663 Fwireless_adc_rx$I2SSTAT$0$0 == 0xdf45
                    DF45    664 _I2SSTAT	=	0xdf45
                    DF46    665 Fwireless_adc_rx$I2SCLKF0$0$0 == 0xdf46
                    DF46    666 _I2SCLKF0	=	0xdf46
                    DF47    667 Fwireless_adc_rx$I2SCLKF1$0$0 == 0xdf47
                    DF47    668 _I2SCLKF1	=	0xdf47
                    DF48    669 Fwireless_adc_rx$I2SCLKF2$0$0 == 0xdf48
                    DF48    670 _I2SCLKF2	=	0xdf48
                    DE00    671 Fwireless_adc_rx$USBADDR$0$0 == 0xde00
                    DE00    672 _USBADDR	=	0xde00
                    DE01    673 Fwireless_adc_rx$USBPOW$0$0 == 0xde01
                    DE01    674 _USBPOW	=	0xde01
                    DE02    675 Fwireless_adc_rx$USBIIF$0$0 == 0xde02
                    DE02    676 _USBIIF	=	0xde02
                    DE04    677 Fwireless_adc_rx$USBOIF$0$0 == 0xde04
                    DE04    678 _USBOIF	=	0xde04
                    DE06    679 Fwireless_adc_rx$USBCIF$0$0 == 0xde06
                    DE06    680 _USBCIF	=	0xde06
                    DE07    681 Fwireless_adc_rx$USBIIE$0$0 == 0xde07
                    DE07    682 _USBIIE	=	0xde07
                    DE09    683 Fwireless_adc_rx$USBOIE$0$0 == 0xde09
                    DE09    684 _USBOIE	=	0xde09
                    DE0B    685 Fwireless_adc_rx$USBCIE$0$0 == 0xde0b
                    DE0B    686 _USBCIE	=	0xde0b
                    DE0C    687 Fwireless_adc_rx$USBFRML$0$0 == 0xde0c
                    DE0C    688 _USBFRML	=	0xde0c
                    DE0D    689 Fwireless_adc_rx$USBFRMH$0$0 == 0xde0d
                    DE0D    690 _USBFRMH	=	0xde0d
                    DE0E    691 Fwireless_adc_rx$USBINDEX$0$0 == 0xde0e
                    DE0E    692 _USBINDEX	=	0xde0e
                    DE10    693 Fwireless_adc_rx$USBMAXI$0$0 == 0xde10
                    DE10    694 _USBMAXI	=	0xde10
                    DE11    695 Fwireless_adc_rx$USBCSIL$0$0 == 0xde11
                    DE11    696 _USBCSIL	=	0xde11
                    DE12    697 Fwireless_adc_rx$USBCSIH$0$0 == 0xde12
                    DE12    698 _USBCSIH	=	0xde12
                    DE13    699 Fwireless_adc_rx$USBMAXO$0$0 == 0xde13
                    DE13    700 _USBMAXO	=	0xde13
                    DE14    701 Fwireless_adc_rx$USBCSOL$0$0 == 0xde14
                    DE14    702 _USBCSOL	=	0xde14
                    DE15    703 Fwireless_adc_rx$USBCSOH$0$0 == 0xde15
                    DE15    704 _USBCSOH	=	0xde15
                    DE16    705 Fwireless_adc_rx$USBCNTL$0$0 == 0xde16
                    DE16    706 _USBCNTL	=	0xde16
                    DE17    707 Fwireless_adc_rx$USBCNTH$0$0 == 0xde17
                    DE17    708 _USBCNTH	=	0xde17
                    DE20    709 Fwireless_adc_rx$USBF0$0$0 == 0xde20
                    DE20    710 _USBF0	=	0xde20
                    DE22    711 Fwireless_adc_rx$USBF1$0$0 == 0xde22
                    DE22    712 _USBF1	=	0xde22
                    DE24    713 Fwireless_adc_rx$USBF2$0$0 == 0xde24
                    DE24    714 _USBF2	=	0xde24
                    DE26    715 Fwireless_adc_rx$USBF3$0$0 == 0xde26
                    DE26    716 _USBF3	=	0xde26
                    DE28    717 Fwireless_adc_rx$USBF4$0$0 == 0xde28
                    DE28    718 _USBF4	=	0xde28
                    DE2A    719 Fwireless_adc_rx$USBF5$0$0 == 0xde2a
                    DE2A    720 _USBF5	=	0xde2a
                            721 ;--------------------------------------------------------
                            722 ; absolute external ram data
                            723 ;--------------------------------------------------------
                            724 	.area XABS    (ABS,XDATA)
                            725 ;--------------------------------------------------------
                            726 ; external initialized ram data
                            727 ;--------------------------------------------------------
                            728 	.area XISEG   (XDATA)
                            729 	.area HOME    (CODE)
                            730 	.area GSINIT0 (CODE)
                            731 	.area GSINIT1 (CODE)
                            732 	.area GSINIT2 (CODE)
                            733 	.area GSINIT3 (CODE)
                            734 	.area GSINIT4 (CODE)
                            735 	.area GSINIT5 (CODE)
                            736 	.area GSINIT  (CODE)
                            737 	.area GSFINAL (CODE)
                            738 	.area CSEG    (CODE)
                            739 ;--------------------------------------------------------
                            740 ; interrupt vector 
                            741 ;--------------------------------------------------------
                            742 	.area HOME    (CODE)
   0400                     743 __interrupt_vect:
   0400 02 04 8D            744 	ljmp	__sdcc_gsinit_startup
   0403 32                  745 	reti
   0404                     746 	.ds	7
   040B 32                  747 	reti
   040C                     748 	.ds	7
   0413 32                  749 	reti
   0414                     750 	.ds	7
   041B 32                  751 	reti
   041C                     752 	.ds	7
   0423 32                  753 	reti
   0424                     754 	.ds	7
   042B 32                  755 	reti
   042C                     756 	.ds	7
   0433 32                  757 	reti
   0434                     758 	.ds	7
   043B 32                  759 	reti
   043C                     760 	.ds	7
   0443 32                  761 	reti
   0444                     762 	.ds	7
   044B 32                  763 	reti
   044C                     764 	.ds	7
   0453 32                  765 	reti
   0454                     766 	.ds	7
   045B 32                  767 	reti
   045C                     768 	.ds	7
   0463 02 13 F0            769 	ljmp	_ISR_T4
   0466                     770 	.ds	5
   046B 32                  771 	reti
   046C                     772 	.ds	7
   0473 32                  773 	reti
   0474                     774 	.ds	7
   047B 32                  775 	reti
   047C                     776 	.ds	7
   0483 02 06 4E            777 	ljmp	_ISR_RF
                            778 ;--------------------------------------------------------
                            779 ; global & static initialisations
                            780 ;--------------------------------------------------------
                            781 	.area HOME    (CODE)
                            782 	.area GSINIT  (CODE)
                            783 	.area GSFINAL (CODE)
                            784 	.area GSINIT  (CODE)
                            785 	.globl __sdcc_gsinit_startup
                            786 	.globl __sdcc_program_startup
                            787 	.globl __start__stack
                            788 	.globl __mcs51_genXINIT
                            789 	.globl __mcs51_genXRAMCLEAR
                            790 	.globl __mcs51_genRAMCLEAR
                            791 	.area GSFINAL (CODE)
   0527 02 04 86            792 	ljmp	__sdcc_program_startup
                            793 ;--------------------------------------------------------
                            794 ; Home
                            795 ;--------------------------------------------------------
                            796 	.area HOME    (CODE)
                            797 	.area HOME    (CODE)
   0486                     798 __sdcc_program_startup:
   0486 12 06 36            799 	lcall	_main
                            800 ;	return from main will lock up
   0489 80 FE               801 	sjmp .
                            802 ;--------------------------------------------------------
                            803 ; code
                            804 ;--------------------------------------------------------
                            805 	.area CSEG    (CODE)
                            806 ;------------------------------------------------------------
                            807 ;Allocation info for local variables in function 'updateLeds'
                            808 ;------------------------------------------------------------
                    0000    809 	G$updateLeds$0$0 ==.
                    0000    810 	C$wireless_adc_rx.c$63$0$0 ==.
                            811 ;	apps/wireless_adc_rx/wireless_adc_rx.c:63: void updateLeds()
                            812 ;	-----------------------------------------
                            813 ;	 function updateLeds
                            814 ;	-----------------------------------------
   052A                     815 _updateLeds:
                    0007    816 	ar7 = 0x07
                    0006    817 	ar6 = 0x06
                    0005    818 	ar5 = 0x05
                    0004    819 	ar4 = 0x04
                    0003    820 	ar3 = 0x03
                    0002    821 	ar2 = 0x02
                    0001    822 	ar1 = 0x01
                    0000    823 	ar0 = 0x00
                    0000    824 	C$wireless_adc_rx.c$65$1$1 ==.
                            825 ;	apps/wireless_adc_rx/wireless_adc_rx.c:65: usbShowStatusWithGreenLed();
   052A 12 15 4D            826 	lcall	_usbShowStatusWithGreenLed
                    0003    827 	C$wireless_adc_rx.c$66$2$2 ==.
                            828 ;	apps/wireless_adc_rx/wireless_adc_rx.c:66: LED_YELLOW(0);
   052D AF FF               829 	mov	r7,_P2DIR
   052F 53 07 FB            830 	anl	ar7,#0xFB
   0532 8F FF               831 	mov	_P2DIR,r7
                    000A    832 	C$wireless_adc_rx.c$67$2$3 ==.
                            833 ;	apps/wireless_adc_rx/wireless_adc_rx.c:67: LED_RED(0);
   0534 AF FF               834 	mov	r7,_P2DIR
   0536 53 07 FD            835 	anl	ar7,#0xFD
   0539 8F FF               836 	mov	_P2DIR,r7
                    0011    837 	C$wireless_adc_rx.c$68$2$3 ==.
                    0011    838 	XG$updateLeds$0$0 ==.
   053B 22                  839 	ret
                            840 ;------------------------------------------------------------
                            841 ;Allocation info for local variables in function 'putchar'
                            842 ;------------------------------------------------------------
                    0012    843 	G$putchar$0$0 ==.
                    0012    844 	C$wireless_adc_rx.c$70$2$3 ==.
                            845 ;	apps/wireless_adc_rx/wireless_adc_rx.c:70: void putchar(char c)
                            846 ;	-----------------------------------------
                            847 ;	 function putchar
                            848 ;	-----------------------------------------
   053C                     849 _putchar:
                    0012    850 	C$wireless_adc_rx.c$72$1$1 ==.
                            851 ;	apps/wireless_adc_rx/wireless_adc_rx.c:72: usbComTxSendByte(c);
   053C 12 0C 84            852 	lcall	_usbComTxSendByte
                    0015    853 	C$wireless_adc_rx.c$73$1$1 ==.
                    0015    854 	XG$putchar$0$0 ==.
   053F 22                  855 	ret
                            856 ;------------------------------------------------------------
                            857 ;Allocation info for local variables in function 'radioToUsbService'
                            858 ;------------------------------------------------------------
                            859 ;sloc0                     Allocated with name '_radioToUsbService_sloc0_1_0'
                            860 ;sloc1                     Allocated with name '_radioToUsbService_sloc1_1_0'
                            861 ;sloc2                     Allocated with name '_radioToUsbService_sloc2_1_0'
                            862 ;------------------------------------------------------------
                    0016    863 	G$radioToUsbService$0$0 ==.
                    0016    864 	C$wireless_adc_rx.c$75$1$1 ==.
                            865 ;	apps/wireless_adc_rx/wireless_adc_rx.c:75: void radioToUsbService()
                            866 ;	-----------------------------------------
                            867 ;	 function radioToUsbService
                            868 ;	-----------------------------------------
   0540                     869 _radioToUsbService:
                    0016    870 	C$wireless_adc_rx.c$81$1$1 ==.
                            871 ;	apps/wireless_adc_rx/wireless_adc_rx.c:81: if ((rxPacket = (adcReport XDATA *)radioQueueRxCurrentPacket()) && usbComTxAvailable() >= 64)
   0540 12 08 A8            872 	lcall	_radioQueueRxCurrentPacket
   0543 AE 82               873 	mov	r6,dpl
   0545 AF 83               874 	mov	r7,dph
   0547 78 00               875 	mov	r0,#_radioToUsbService_rxPacket_1_1
   0549 EE                  876 	mov	a,r6
   054A F2                  877 	movx	@r0,a
   054B 08                  878 	inc	r0
   054C EF                  879 	mov	a,r7
   054D F2                  880 	movx	@r0,a
   054E EE                  881 	mov	a,r6
   054F 4F                  882 	orl	a,r7
   0550 70 03               883 	jnz	00115$
   0552 02 06 35            884 	ljmp	00108$
   0555                     885 00115$:
   0555 12 0B F2            886 	lcall	_usbComTxAvailable
   0558 AF 82               887 	mov	r7,dpl
   055A BF 40 00            888 	cjne	r7,#0x40,00116$
   055D                     889 00116$:
   055D 50 03               890 	jnc	00117$
   055F 02 06 35            891 	ljmp	00108$
   0562                     892 00117$:
                    0038    893 	C$wireless_adc_rx.c$94$2$2 ==.
                            894 ;	apps/wireless_adc_rx/wireless_adc_rx.c:94: (uint16)getMs()
   0562 12 14 15            895 	lcall	_getMs
   0565 AA 82               896 	mov	r2,dpl
   0567 AB 83               897 	mov	r3,dph
                    003F    898 	C$wireless_adc_rx.c$93$2$2 ==.
                            899 ;	apps/wireless_adc_rx/wireless_adc_rx.c:93: rxPacket->serialNumber[0],
   0569 78 00               900 	mov	r0,#_radioToUsbService_rxPacket_1_1
   056B E2                  901 	movx	a,@r0
   056C 24 01               902 	add	a,#0x01
   056E F5 82               903 	mov	dpl,a
   0570 08                  904 	inc	r0
   0571 E2                  905 	movx	a,@r0
   0572 34 00               906 	addc	a,#0x00
   0574 F5 83               907 	mov	dph,a
   0576 E0                  908 	movx	a,@dptr
   0577 FF                  909 	mov	r7,a
   0578 7E 00               910 	mov	r6,#0x00
                    0050    911 	C$wireless_adc_rx.c$92$2$2 ==.
                            912 ;	apps/wireless_adc_rx/wireless_adc_rx.c:92: rxPacket->serialNumber[1],
   057A 78 00               913 	mov	r0,#_radioToUsbService_rxPacket_1_1
   057C E2                  914 	movx	a,@r0
   057D 24 02               915 	add	a,#0x02
   057F F5 82               916 	mov	dpl,a
   0581 08                  917 	inc	r0
   0582 E2                  918 	movx	a,@r0
   0583 34 00               919 	addc	a,#0x00
   0585 F5 83               920 	mov	dph,a
   0587 E0                  921 	movx	a,@dptr
   0588 F5 08               922 	mov	_radioToUsbService_sloc0_1_0,a
   058A 85 08 09            923 	mov	_radioToUsbService_sloc1_1_0,_radioToUsbService_sloc0_1_0
   058D 75 0A 00            924 	mov	(_radioToUsbService_sloc1_1_0 + 1),#0x00
                    0066    925 	C$wireless_adc_rx.c$91$2$2 ==.
                            926 ;	apps/wireless_adc_rx/wireless_adc_rx.c:91: rxPacket->serialNumber[2],
   0590 78 00               927 	mov	r0,#_radioToUsbService_rxPacket_1_1
   0592 E2                  928 	movx	a,@r0
   0593 24 03               929 	add	a,#0x03
   0595 F5 82               930 	mov	dpl,a
   0597 08                  931 	inc	r0
   0598 E2                  932 	movx	a,@r0
   0599 34 00               933 	addc	a,#0x00
   059B F5 83               934 	mov	dph,a
   059D E0                  935 	movx	a,@dptr
   059E FD                  936 	mov	r5,a
   059F 8D 0B               937 	mov	_radioToUsbService_sloc2_1_0,r5
   05A1 75 0C 00            938 	mov	(_radioToUsbService_sloc2_1_0 + 1),#0x00
                    007A    939 	C$wireless_adc_rx.c$90$2$2 ==.
                            940 ;	apps/wireless_adc_rx/wireless_adc_rx.c:90: rxPacket->serialNumber[3],
   05A4 78 00               941 	mov	r0,#_radioToUsbService_rxPacket_1_1
   05A6 E2                  942 	movx	a,@r0
   05A7 24 04               943 	add	a,#0x04
   05A9 F5 82               944 	mov	dpl,a
   05AB 08                  945 	inc	r0
   05AC E2                  946 	movx	a,@r0
   05AD 34 00               947 	addc	a,#0x00
   05AF F5 83               948 	mov	dph,a
   05B1 E0                  949 	movx	a,@dptr
   05B2 FD                  950 	mov	r5,a
   05B3 7C 00               951 	mov	r4,#0x00
                    008B    952 	C$wireless_adc_rx.c$89$2$2 ==.
                            953 ;	apps/wireless_adc_rx/wireless_adc_rx.c:89: printf("%02X-%02X-%02X-%02X %5u",
   05B5 C0 02               954 	push	ar2
   05B7 C0 03               955 	push	ar3
   05B9 C0 07               956 	push	ar7
   05BB C0 06               957 	push	ar6
   05BD C0 09               958 	push	_radioToUsbService_sloc1_1_0
   05BF C0 0A               959 	push	(_radioToUsbService_sloc1_1_0 + 1)
   05C1 C0 0B               960 	push	_radioToUsbService_sloc2_1_0
   05C3 C0 0C               961 	push	(_radioToUsbService_sloc2_1_0 + 1)
   05C5 C0 05               962 	push	ar5
   05C7 C0 04               963 	push	ar4
   05C9 74 AC               964 	mov	a,#__str_0
   05CB C0 E0               965 	push	acc
   05CD 74 1D               966 	mov	a,#(__str_0 >> 8)
   05CF C0 E0               967 	push	acc
   05D1 74 80               968 	mov	a,#0x80
   05D3 C0 E0               969 	push	acc
   05D5 12 16 0A            970 	lcall	_printf
   05D8 E5 81               971 	mov	a,sp
   05DA 24 F3               972 	add	a,#0xf3
   05DC F5 81               973 	mov	sp,a
                    00B4    974 	C$wireless_adc_rx.c$97$3$3 ==.
                            975 ;	apps/wireless_adc_rx/wireless_adc_rx.c:97: for(i = 0; i < 6; i++)
   05DE 78 00               976 	mov	r0,#_radioToUsbService_rxPacket_1_1
   05E0 E2                  977 	movx	a,@r0
   05E1 24 05               978 	add	a,#0x05
   05E3 FE                  979 	mov	r6,a
   05E4 08                  980 	inc	r0
   05E5 E2                  981 	movx	a,@r0
   05E6 34 00               982 	addc	a,#0x00
   05E8 FF                  983 	mov	r7,a
   05E9 7D 00               984 	mov	r5,#0x00
   05EB                     985 00104$:
   05EB BD 06 00            986 	cjne	r5,#0x06,00118$
   05EE                     987 00118$:
   05EE 50 36               988 	jnc	00107$
                    00C6    989 	C$wireless_adc_rx.c$99$3$3 ==.
                            990 ;	apps/wireless_adc_rx/wireless_adc_rx.c:99: printf(" %5u", rxPacket->readings[i]);
   05F0 ED                  991 	mov	a,r5
   05F1 2D                  992 	add	a,r5
   05F2 2E                  993 	add	a,r6
   05F3 F5 82               994 	mov	dpl,a
   05F5 E4                  995 	clr	a
   05F6 3F                  996 	addc	a,r7
   05F7 F5 83               997 	mov	dph,a
   05F9 E0                  998 	movx	a,@dptr
   05FA FB                  999 	mov	r3,a
   05FB A3                 1000 	inc	dptr
   05FC E0                 1001 	movx	a,@dptr
   05FD FC                 1002 	mov	r4,a
   05FE C0 07              1003 	push	ar7
   0600 C0 06              1004 	push	ar6
   0602 C0 05              1005 	push	ar5
   0604 C0 03              1006 	push	ar3
   0606 C0 04              1007 	push	ar4
   0608 74 C4              1008 	mov	a,#__str_1
   060A C0 E0              1009 	push	acc
   060C 74 1D              1010 	mov	a,#(__str_1 >> 8)
   060E C0 E0              1011 	push	acc
   0610 74 80              1012 	mov	a,#0x80
   0612 C0 E0              1013 	push	acc
   0614 12 16 0A           1014 	lcall	_printf
   0617 E5 81              1015 	mov	a,sp
   0619 24 FB              1016 	add	a,#0xfb
   061B F5 81              1017 	mov	sp,a
   061D D0 05              1018 	pop	ar5
   061F D0 06              1019 	pop	ar6
   0621 D0 07              1020 	pop	ar7
                    00F9   1021 	C$wireless_adc_rx.c$97$2$2 ==.
                           1022 ;	apps/wireless_adc_rx/wireless_adc_rx.c:97: for(i = 0; i < 6; i++)
   0623 0D                 1023 	inc	r5
   0624 80 C5              1024 	sjmp	00104$
   0626                    1025 00107$:
                    00FC   1026 	C$wireless_adc_rx.c$102$2$2 ==.
                           1027 ;	apps/wireless_adc_rx/wireless_adc_rx.c:102: putchar('\r');
   0626 75 82 0D           1028 	mov	dpl,#0x0D
   0629 12 05 3C           1029 	lcall	_putchar
                    0102   1030 	C$wireless_adc_rx.c$103$2$2 ==.
                           1031 ;	apps/wireless_adc_rx/wireless_adc_rx.c:103: putchar('\n');
   062C 75 82 0A           1032 	mov	dpl,#0x0A
   062F 12 05 3C           1033 	lcall	_putchar
                    0108   1034 	C$wireless_adc_rx.c$105$2$2 ==.
                           1035 ;	apps/wireless_adc_rx/wireless_adc_rx.c:105: radioQueueRxDoneWithPacket();
   0632 12 08 C3           1036 	lcall	_radioQueueRxDoneWithPacket
   0635                    1037 00108$:
                    010B   1038 	C$wireless_adc_rx.c$107$2$1 ==.
                    010B   1039 	XG$radioToUsbService$0$0 ==.
   0635 22                 1040 	ret
                           1041 ;------------------------------------------------------------
                           1042 ;Allocation info for local variables in function 'main'
                           1043 ;------------------------------------------------------------
                    010C   1044 	G$main$0$0 ==.
                    010C   1045 	C$wireless_adc_rx.c$109$2$1 ==.
                           1046 ;	apps/wireless_adc_rx/wireless_adc_rx.c:109: void main(void)
                           1047 ;	-----------------------------------------
                           1048 ;	 function main
                           1049 ;	-----------------------------------------
   0636                    1050 _main:
                    010C   1051 	C$wireless_adc_rx.c$111$1$1 ==.
                           1052 ;	apps/wireless_adc_rx/wireless_adc_rx.c:111: systemInit();
   0636 12 13 15           1053 	lcall	_systemInit
                    010F   1054 	C$wireless_adc_rx.c$112$1$1 ==.
                           1055 ;	apps/wireless_adc_rx/wireless_adc_rx.c:112: usbInit();
   0639 12 0C AF           1056 	lcall	_usbInit
                    0112   1057 	C$wireless_adc_rx.c$113$1$1 ==.
                           1058 ;	apps/wireless_adc_rx/wireless_adc_rx.c:113: radioQueueInit();
   063C 12 08 36           1059 	lcall	_radioQueueInit
                    0115   1060 	C$wireless_adc_rx.c$115$1$1 ==.
                           1061 ;	apps/wireless_adc_rx/wireless_adc_rx.c:115: while(1)
   063F                    1062 00102$:
                    0115   1063 	C$wireless_adc_rx.c$117$2$2 ==.
                           1064 ;	apps/wireless_adc_rx/wireless_adc_rx.c:117: updateLeds();
   063F 12 05 2A           1065 	lcall	_updateLeds
                    0118   1066 	C$wireless_adc_rx.c$118$2$2 ==.
                           1067 ;	apps/wireless_adc_rx/wireless_adc_rx.c:118: boardService();
   0642 12 13 22           1068 	lcall	_boardService
                    011B   1069 	C$wireless_adc_rx.c$119$2$2 ==.
                           1070 ;	apps/wireless_adc_rx/wireless_adc_rx.c:119: usbComService();
   0645 12 0B 4D           1071 	lcall	_usbComService
                    011E   1072 	C$wireless_adc_rx.c$120$2$2 ==.
                           1073 ;	apps/wireless_adc_rx/wireless_adc_rx.c:120: radioToUsbService();
   0648 12 05 40           1074 	lcall	_radioToUsbService
   064B 80 F2              1075 	sjmp	00102$
                    0123   1076 	C$wireless_adc_rx.c$122$1$1 ==.
                    0123   1077 	XG$main$0$0 ==.
   064D 22                 1078 	ret
                           1079 	.area CSEG    (CODE)
                           1080 	.area CONST   (CODE)
                    0000   1081 Fwireless_adc_rx$_str_0$0$0 == .
   1DAC                    1082 __str_0:
   1DAC 25 30 32 58 2D 25  1083 	.ascii "%02X-%02X-%02X-%02X %5u"
        30 32 58 2D 25 30
        32 58 2D 25 30 32
        58 20 25 35 75
   1DC3 00                 1084 	.db 0x00
                    0018   1085 Fwireless_adc_rx$_str_1$0$0 == .
   1DC4                    1086 __str_1:
   1DC4 20 25 35 75        1087 	.ascii " %5u"
   1DC8 00                 1088 	.db 0x00
                           1089 	.area XINIT   (CODE)
                           1090 	.area CABS    (ABS,CODE)
