                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:48 2012
                              5 ;--------------------------------------------------------
                              6 	.module example_usb_com
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _processBytesFromUsb
                             14 	.globl _processByte
                             15 	.globl _executeCommand
                             16 	.globl _updateLeds
                             17 	.globl _sprintf
                             18 	.globl _usbComTxSend
                             19 	.globl _usbComTxAvailable
                             20 	.globl _usbComRxReceiveByte
                             21 	.globl _usbComRxAvailable
                             22 	.globl _usbComService
                             23 	.globl _usbShowStatusWithGreenLed
                             24 	.globl _usbInit
                             25 	.globl _getMs
                             26 	.globl _boardService
                             27 	.globl _systemInit
                             28 	.globl _response
                             29 	.globl _dataBytesReceived
                             30 	.globl _dataBytesLeft
                             31 	.globl _dataBytes
                             32 	.globl _commandByte
                             33 	.globl _x
                             34 	.globl _serialProtocolError
                             35 	.globl _yellowLedOn
                             36 ;--------------------------------------------------------
                             37 ; special function registers
                             38 ;--------------------------------------------------------
                             39 	.area RSEG    (ABS,DATA)
   0000                      40 	.org 0x0000
                    0080     41 Fexample_usb_com$P0$0$0 == 0x0080
                    0080     42 _P0	=	0x0080
                    0081     43 Fexample_usb_com$SP$0$0 == 0x0081
                    0081     44 _SP	=	0x0081
                    0082     45 Fexample_usb_com$DPL0$0$0 == 0x0082
                    0082     46 _DPL0	=	0x0082
                    0083     47 Fexample_usb_com$DPH0$0$0 == 0x0083
                    0083     48 _DPH0	=	0x0083
                    0084     49 Fexample_usb_com$DPL1$0$0 == 0x0084
                    0084     50 _DPL1	=	0x0084
                    0085     51 Fexample_usb_com$DPH1$0$0 == 0x0085
                    0085     52 _DPH1	=	0x0085
                    0086     53 Fexample_usb_com$U0CSR$0$0 == 0x0086
                    0086     54 _U0CSR	=	0x0086
                    0087     55 Fexample_usb_com$PCON$0$0 == 0x0087
                    0087     56 _PCON	=	0x0087
                    0088     57 Fexample_usb_com$TCON$0$0 == 0x0088
                    0088     58 _TCON	=	0x0088
                    0089     59 Fexample_usb_com$P0IFG$0$0 == 0x0089
                    0089     60 _P0IFG	=	0x0089
                    008A     61 Fexample_usb_com$P1IFG$0$0 == 0x008a
                    008A     62 _P1IFG	=	0x008a
                    008B     63 Fexample_usb_com$P2IFG$0$0 == 0x008b
                    008B     64 _P2IFG	=	0x008b
                    008C     65 Fexample_usb_com$PICTL$0$0 == 0x008c
                    008C     66 _PICTL	=	0x008c
                    008D     67 Fexample_usb_com$P1IEN$0$0 == 0x008d
                    008D     68 _P1IEN	=	0x008d
                    008F     69 Fexample_usb_com$P0INP$0$0 == 0x008f
                    008F     70 _P0INP	=	0x008f
                    0090     71 Fexample_usb_com$P1$0$0 == 0x0090
                    0090     72 _P1	=	0x0090
                    0091     73 Fexample_usb_com$RFIM$0$0 == 0x0091
                    0091     74 _RFIM	=	0x0091
                    0092     75 Fexample_usb_com$DPS$0$0 == 0x0092
                    0092     76 _DPS	=	0x0092
                    0093     77 Fexample_usb_com$MPAGE$0$0 == 0x0093
                    0093     78 _MPAGE	=	0x0093
                    0095     79 Fexample_usb_com$ENDIAN$0$0 == 0x0095
                    0095     80 _ENDIAN	=	0x0095
                    0098     81 Fexample_usb_com$S0CON$0$0 == 0x0098
                    0098     82 _S0CON	=	0x0098
                    009A     83 Fexample_usb_com$IEN2$0$0 == 0x009a
                    009A     84 _IEN2	=	0x009a
                    009B     85 Fexample_usb_com$S1CON$0$0 == 0x009b
                    009B     86 _S1CON	=	0x009b
                    009C     87 Fexample_usb_com$T2CT$0$0 == 0x009c
                    009C     88 _T2CT	=	0x009c
                    009D     89 Fexample_usb_com$T2PR$0$0 == 0x009d
                    009D     90 _T2PR	=	0x009d
                    009E     91 Fexample_usb_com$T2CTL$0$0 == 0x009e
                    009E     92 _T2CTL	=	0x009e
                    00A0     93 Fexample_usb_com$P2$0$0 == 0x00a0
                    00A0     94 _P2	=	0x00a0
                    00A1     95 Fexample_usb_com$WORIRQ$0$0 == 0x00a1
                    00A1     96 _WORIRQ	=	0x00a1
                    00A2     97 Fexample_usb_com$WORCTRL$0$0 == 0x00a2
                    00A2     98 _WORCTRL	=	0x00a2
                    00A3     99 Fexample_usb_com$WOREVT0$0$0 == 0x00a3
                    00A3    100 _WOREVT0	=	0x00a3
                    00A4    101 Fexample_usb_com$WOREVT1$0$0 == 0x00a4
                    00A4    102 _WOREVT1	=	0x00a4
                    00A5    103 Fexample_usb_com$WORTIME0$0$0 == 0x00a5
                    00A5    104 _WORTIME0	=	0x00a5
                    00A6    105 Fexample_usb_com$WORTIME1$0$0 == 0x00a6
                    00A6    106 _WORTIME1	=	0x00a6
                    00A8    107 Fexample_usb_com$IEN0$0$0 == 0x00a8
                    00A8    108 _IEN0	=	0x00a8
                    00A9    109 Fexample_usb_com$IP0$0$0 == 0x00a9
                    00A9    110 _IP0	=	0x00a9
                    00AB    111 Fexample_usb_com$FWT$0$0 == 0x00ab
                    00AB    112 _FWT	=	0x00ab
                    00AC    113 Fexample_usb_com$FADDRL$0$0 == 0x00ac
                    00AC    114 _FADDRL	=	0x00ac
                    00AD    115 Fexample_usb_com$FADDRH$0$0 == 0x00ad
                    00AD    116 _FADDRH	=	0x00ad
                    00AE    117 Fexample_usb_com$FCTL$0$0 == 0x00ae
                    00AE    118 _FCTL	=	0x00ae
                    00AF    119 Fexample_usb_com$FWDATA$0$0 == 0x00af
                    00AF    120 _FWDATA	=	0x00af
                    00B1    121 Fexample_usb_com$ENCDI$0$0 == 0x00b1
                    00B1    122 _ENCDI	=	0x00b1
                    00B2    123 Fexample_usb_com$ENCDO$0$0 == 0x00b2
                    00B2    124 _ENCDO	=	0x00b2
                    00B3    125 Fexample_usb_com$ENCCS$0$0 == 0x00b3
                    00B3    126 _ENCCS	=	0x00b3
                    00B4    127 Fexample_usb_com$ADCCON1$0$0 == 0x00b4
                    00B4    128 _ADCCON1	=	0x00b4
                    00B5    129 Fexample_usb_com$ADCCON2$0$0 == 0x00b5
                    00B5    130 _ADCCON2	=	0x00b5
                    00B6    131 Fexample_usb_com$ADCCON3$0$0 == 0x00b6
                    00B6    132 _ADCCON3	=	0x00b6
                    00B8    133 Fexample_usb_com$IEN1$0$0 == 0x00b8
                    00B8    134 _IEN1	=	0x00b8
                    00B9    135 Fexample_usb_com$IP1$0$0 == 0x00b9
                    00B9    136 _IP1	=	0x00b9
                    00BA    137 Fexample_usb_com$ADCL$0$0 == 0x00ba
                    00BA    138 _ADCL	=	0x00ba
                    00BB    139 Fexample_usb_com$ADCH$0$0 == 0x00bb
                    00BB    140 _ADCH	=	0x00bb
                    00BC    141 Fexample_usb_com$RNDL$0$0 == 0x00bc
                    00BC    142 _RNDL	=	0x00bc
                    00BD    143 Fexample_usb_com$RNDH$0$0 == 0x00bd
                    00BD    144 _RNDH	=	0x00bd
                    00BE    145 Fexample_usb_com$SLEEP$0$0 == 0x00be
                    00BE    146 _SLEEP	=	0x00be
                    00C0    147 Fexample_usb_com$IRCON$0$0 == 0x00c0
                    00C0    148 _IRCON	=	0x00c0
                    00C1    149 Fexample_usb_com$U0DBUF$0$0 == 0x00c1
                    00C1    150 _U0DBUF	=	0x00c1
                    00C2    151 Fexample_usb_com$U0BAUD$0$0 == 0x00c2
                    00C2    152 _U0BAUD	=	0x00c2
                    00C4    153 Fexample_usb_com$U0UCR$0$0 == 0x00c4
                    00C4    154 _U0UCR	=	0x00c4
                    00C5    155 Fexample_usb_com$U0GCR$0$0 == 0x00c5
                    00C5    156 _U0GCR	=	0x00c5
                    00C6    157 Fexample_usb_com$CLKCON$0$0 == 0x00c6
                    00C6    158 _CLKCON	=	0x00c6
                    00C7    159 Fexample_usb_com$MEMCTR$0$0 == 0x00c7
                    00C7    160 _MEMCTR	=	0x00c7
                    00C9    161 Fexample_usb_com$WDCTL$0$0 == 0x00c9
                    00C9    162 _WDCTL	=	0x00c9
                    00CA    163 Fexample_usb_com$T3CNT$0$0 == 0x00ca
                    00CA    164 _T3CNT	=	0x00ca
                    00CB    165 Fexample_usb_com$T3CTL$0$0 == 0x00cb
                    00CB    166 _T3CTL	=	0x00cb
                    00CC    167 Fexample_usb_com$T3CCTL0$0$0 == 0x00cc
                    00CC    168 _T3CCTL0	=	0x00cc
                    00CD    169 Fexample_usb_com$T3CC0$0$0 == 0x00cd
                    00CD    170 _T3CC0	=	0x00cd
                    00CE    171 Fexample_usb_com$T3CCTL1$0$0 == 0x00ce
                    00CE    172 _T3CCTL1	=	0x00ce
                    00CF    173 Fexample_usb_com$T3CC1$0$0 == 0x00cf
                    00CF    174 _T3CC1	=	0x00cf
                    00D0    175 Fexample_usb_com$PSW$0$0 == 0x00d0
                    00D0    176 _PSW	=	0x00d0
                    00D1    177 Fexample_usb_com$DMAIRQ$0$0 == 0x00d1
                    00D1    178 _DMAIRQ	=	0x00d1
                    00D2    179 Fexample_usb_com$DMA1CFGL$0$0 == 0x00d2
                    00D2    180 _DMA1CFGL	=	0x00d2
                    00D3    181 Fexample_usb_com$DMA1CFGH$0$0 == 0x00d3
                    00D3    182 _DMA1CFGH	=	0x00d3
                    00D4    183 Fexample_usb_com$DMA0CFGL$0$0 == 0x00d4
                    00D4    184 _DMA0CFGL	=	0x00d4
                    00D5    185 Fexample_usb_com$DMA0CFGH$0$0 == 0x00d5
                    00D5    186 _DMA0CFGH	=	0x00d5
                    00D6    187 Fexample_usb_com$DMAARM$0$0 == 0x00d6
                    00D6    188 _DMAARM	=	0x00d6
                    00D7    189 Fexample_usb_com$DMAREQ$0$0 == 0x00d7
                    00D7    190 _DMAREQ	=	0x00d7
                    00D8    191 Fexample_usb_com$TIMIF$0$0 == 0x00d8
                    00D8    192 _TIMIF	=	0x00d8
                    00D9    193 Fexample_usb_com$RFD$0$0 == 0x00d9
                    00D9    194 _RFD	=	0x00d9
                    00DA    195 Fexample_usb_com$T1CC0L$0$0 == 0x00da
                    00DA    196 _T1CC0L	=	0x00da
                    00DB    197 Fexample_usb_com$T1CC0H$0$0 == 0x00db
                    00DB    198 _T1CC0H	=	0x00db
                    00DC    199 Fexample_usb_com$T1CC1L$0$0 == 0x00dc
                    00DC    200 _T1CC1L	=	0x00dc
                    00DD    201 Fexample_usb_com$T1CC1H$0$0 == 0x00dd
                    00DD    202 _T1CC1H	=	0x00dd
                    00DE    203 Fexample_usb_com$T1CC2L$0$0 == 0x00de
                    00DE    204 _T1CC2L	=	0x00de
                    00DF    205 Fexample_usb_com$T1CC2H$0$0 == 0x00df
                    00DF    206 _T1CC2H	=	0x00df
                    00E0    207 Fexample_usb_com$ACC$0$0 == 0x00e0
                    00E0    208 _ACC	=	0x00e0
                    00E1    209 Fexample_usb_com$RFST$0$0 == 0x00e1
                    00E1    210 _RFST	=	0x00e1
                    00E2    211 Fexample_usb_com$T1CNTL$0$0 == 0x00e2
                    00E2    212 _T1CNTL	=	0x00e2
                    00E3    213 Fexample_usb_com$T1CNTH$0$0 == 0x00e3
                    00E3    214 _T1CNTH	=	0x00e3
                    00E4    215 Fexample_usb_com$T1CTL$0$0 == 0x00e4
                    00E4    216 _T1CTL	=	0x00e4
                    00E5    217 Fexample_usb_com$T1CCTL0$0$0 == 0x00e5
                    00E5    218 _T1CCTL0	=	0x00e5
                    00E6    219 Fexample_usb_com$T1CCTL1$0$0 == 0x00e6
                    00E6    220 _T1CCTL1	=	0x00e6
                    00E7    221 Fexample_usb_com$T1CCTL2$0$0 == 0x00e7
                    00E7    222 _T1CCTL2	=	0x00e7
                    00E8    223 Fexample_usb_com$IRCON2$0$0 == 0x00e8
                    00E8    224 _IRCON2	=	0x00e8
                    00E9    225 Fexample_usb_com$RFIF$0$0 == 0x00e9
                    00E9    226 _RFIF	=	0x00e9
                    00EA    227 Fexample_usb_com$T4CNT$0$0 == 0x00ea
                    00EA    228 _T4CNT	=	0x00ea
                    00EB    229 Fexample_usb_com$T4CTL$0$0 == 0x00eb
                    00EB    230 _T4CTL	=	0x00eb
                    00EC    231 Fexample_usb_com$T4CCTL0$0$0 == 0x00ec
                    00EC    232 _T4CCTL0	=	0x00ec
                    00ED    233 Fexample_usb_com$T4CC0$0$0 == 0x00ed
                    00ED    234 _T4CC0	=	0x00ed
                    00EE    235 Fexample_usb_com$T4CCTL1$0$0 == 0x00ee
                    00EE    236 _T4CCTL1	=	0x00ee
                    00EF    237 Fexample_usb_com$T4CC1$0$0 == 0x00ef
                    00EF    238 _T4CC1	=	0x00ef
                    00F0    239 Fexample_usb_com$B$0$0 == 0x00f0
                    00F0    240 _B	=	0x00f0
                    00F1    241 Fexample_usb_com$PERCFG$0$0 == 0x00f1
                    00F1    242 _PERCFG	=	0x00f1
                    00F2    243 Fexample_usb_com$ADCCFG$0$0 == 0x00f2
                    00F2    244 _ADCCFG	=	0x00f2
                    00F3    245 Fexample_usb_com$P0SEL$0$0 == 0x00f3
                    00F3    246 _P0SEL	=	0x00f3
                    00F4    247 Fexample_usb_com$P1SEL$0$0 == 0x00f4
                    00F4    248 _P1SEL	=	0x00f4
                    00F5    249 Fexample_usb_com$P2SEL$0$0 == 0x00f5
                    00F5    250 _P2SEL	=	0x00f5
                    00F6    251 Fexample_usb_com$P1INP$0$0 == 0x00f6
                    00F6    252 _P1INP	=	0x00f6
                    00F7    253 Fexample_usb_com$P2INP$0$0 == 0x00f7
                    00F7    254 _P2INP	=	0x00f7
                    00F8    255 Fexample_usb_com$U1CSR$0$0 == 0x00f8
                    00F8    256 _U1CSR	=	0x00f8
                    00F9    257 Fexample_usb_com$U1DBUF$0$0 == 0x00f9
                    00F9    258 _U1DBUF	=	0x00f9
                    00FA    259 Fexample_usb_com$U1BAUD$0$0 == 0x00fa
                    00FA    260 _U1BAUD	=	0x00fa
                    00FB    261 Fexample_usb_com$U1UCR$0$0 == 0x00fb
                    00FB    262 _U1UCR	=	0x00fb
                    00FC    263 Fexample_usb_com$U1GCR$0$0 == 0x00fc
                    00FC    264 _U1GCR	=	0x00fc
                    00FD    265 Fexample_usb_com$P0DIR$0$0 == 0x00fd
                    00FD    266 _P0DIR	=	0x00fd
                    00FE    267 Fexample_usb_com$P1DIR$0$0 == 0x00fe
                    00FE    268 _P1DIR	=	0x00fe
                    00FF    269 Fexample_usb_com$P2DIR$0$0 == 0x00ff
                    00FF    270 _P2DIR	=	0x00ff
                    FFFFD5D4    271 Fexample_usb_com$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    272 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    273 Fexample_usb_com$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    274 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    275 Fexample_usb_com$FADDR$0$0 == 0xffffadac
                    FFFFADAC    276 _FADDR	=	0xffffadac
                    FFFFBBBA    277 Fexample_usb_com$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    278 _ADC	=	0xffffbbba
                    FFFFDBDA    279 Fexample_usb_com$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    280 _T1CC0	=	0xffffdbda
                    FFFFDDDC    281 Fexample_usb_com$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    282 _T1CC1	=	0xffffdddc
                    FFFFDFDE    283 Fexample_usb_com$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    284 _T1CC2	=	0xffffdfde
                            285 ;--------------------------------------------------------
                            286 ; special function bits
                            287 ;--------------------------------------------------------
                            288 	.area RSEG    (ABS,DATA)
   0000                     289 	.org 0x0000
                    0080    290 Fexample_usb_com$P0_0$0$0 == 0x0080
                    0080    291 _P0_0	=	0x0080
                    0081    292 Fexample_usb_com$P0_1$0$0 == 0x0081
                    0081    293 _P0_1	=	0x0081
                    0082    294 Fexample_usb_com$P0_2$0$0 == 0x0082
                    0082    295 _P0_2	=	0x0082
                    0083    296 Fexample_usb_com$P0_3$0$0 == 0x0083
                    0083    297 _P0_3	=	0x0083
                    0084    298 Fexample_usb_com$P0_4$0$0 == 0x0084
                    0084    299 _P0_4	=	0x0084
                    0085    300 Fexample_usb_com$P0_5$0$0 == 0x0085
                    0085    301 _P0_5	=	0x0085
                    0086    302 Fexample_usb_com$P0_6$0$0 == 0x0086
                    0086    303 _P0_6	=	0x0086
                    0087    304 Fexample_usb_com$P0_7$0$0 == 0x0087
                    0087    305 _P0_7	=	0x0087
                    0088    306 Fexample_usb_com$_TCON_0$0$0 == 0x0088
                    0088    307 __TCON_0	=	0x0088
                    0089    308 Fexample_usb_com$RFTXRXIF$0$0 == 0x0089
                    0089    309 _RFTXRXIF	=	0x0089
                    008A    310 Fexample_usb_com$_TCON_2$0$0 == 0x008a
                    008A    311 __TCON_2	=	0x008a
                    008B    312 Fexample_usb_com$URX0IF$0$0 == 0x008b
                    008B    313 _URX0IF	=	0x008b
                    008C    314 Fexample_usb_com$_TCON_4$0$0 == 0x008c
                    008C    315 __TCON_4	=	0x008c
                    008D    316 Fexample_usb_com$ADCIF$0$0 == 0x008d
                    008D    317 _ADCIF	=	0x008d
                    008E    318 Fexample_usb_com$_TCON_6$0$0 == 0x008e
                    008E    319 __TCON_6	=	0x008e
                    008F    320 Fexample_usb_com$URX1IF$0$0 == 0x008f
                    008F    321 _URX1IF	=	0x008f
                    0090    322 Fexample_usb_com$P1_0$0$0 == 0x0090
                    0090    323 _P1_0	=	0x0090
                    0091    324 Fexample_usb_com$P1_1$0$0 == 0x0091
                    0091    325 _P1_1	=	0x0091
                    0092    326 Fexample_usb_com$P1_2$0$0 == 0x0092
                    0092    327 _P1_2	=	0x0092
                    0093    328 Fexample_usb_com$P1_3$0$0 == 0x0093
                    0093    329 _P1_3	=	0x0093
                    0094    330 Fexample_usb_com$P1_4$0$0 == 0x0094
                    0094    331 _P1_4	=	0x0094
                    0095    332 Fexample_usb_com$P1_5$0$0 == 0x0095
                    0095    333 _P1_5	=	0x0095
                    0096    334 Fexample_usb_com$P1_6$0$0 == 0x0096
                    0096    335 _P1_6	=	0x0096
                    0097    336 Fexample_usb_com$P1_7$0$0 == 0x0097
                    0097    337 _P1_7	=	0x0097
                    0098    338 Fexample_usb_com$ENCIF_0$0$0 == 0x0098
                    0098    339 _ENCIF_0	=	0x0098
                    0099    340 Fexample_usb_com$ENCIF_1$0$0 == 0x0099
                    0099    341 _ENCIF_1	=	0x0099
                    009A    342 Fexample_usb_com$_SOCON2$0$0 == 0x009a
                    009A    343 __SOCON2	=	0x009a
                    009B    344 Fexample_usb_com$_SOCON3$0$0 == 0x009b
                    009B    345 __SOCON3	=	0x009b
                    009C    346 Fexample_usb_com$_SOCON4$0$0 == 0x009c
                    009C    347 __SOCON4	=	0x009c
                    009D    348 Fexample_usb_com$_SOCON5$0$0 == 0x009d
                    009D    349 __SOCON5	=	0x009d
                    009E    350 Fexample_usb_com$_SOCON6$0$0 == 0x009e
                    009E    351 __SOCON6	=	0x009e
                    009F    352 Fexample_usb_com$_SOCON7$0$0 == 0x009f
                    009F    353 __SOCON7	=	0x009f
                    00A0    354 Fexample_usb_com$P2_0$0$0 == 0x00a0
                    00A0    355 _P2_0	=	0x00a0
                    00A1    356 Fexample_usb_com$P2_1$0$0 == 0x00a1
                    00A1    357 _P2_1	=	0x00a1
                    00A2    358 Fexample_usb_com$P2_2$0$0 == 0x00a2
                    00A2    359 _P2_2	=	0x00a2
                    00A3    360 Fexample_usb_com$P2_3$0$0 == 0x00a3
                    00A3    361 _P2_3	=	0x00a3
                    00A4    362 Fexample_usb_com$P2_4$0$0 == 0x00a4
                    00A4    363 _P2_4	=	0x00a4
                    00A5    364 Fexample_usb_com$P2_5$0$0 == 0x00a5
                    00A5    365 _P2_5	=	0x00a5
                    00A6    366 Fexample_usb_com$P2_6$0$0 == 0x00a6
                    00A6    367 _P2_6	=	0x00a6
                    00A7    368 Fexample_usb_com$P2_7$0$0 == 0x00a7
                    00A7    369 _P2_7	=	0x00a7
                    00A8    370 Fexample_usb_com$RFTXRXIE$0$0 == 0x00a8
                    00A8    371 _RFTXRXIE	=	0x00a8
                    00A9    372 Fexample_usb_com$ADCIE$0$0 == 0x00a9
                    00A9    373 _ADCIE	=	0x00a9
                    00AA    374 Fexample_usb_com$URX0IE$0$0 == 0x00aa
                    00AA    375 _URX0IE	=	0x00aa
                    00AB    376 Fexample_usb_com$URX1IE$0$0 == 0x00ab
                    00AB    377 _URX1IE	=	0x00ab
                    00AC    378 Fexample_usb_com$ENCIE$0$0 == 0x00ac
                    00AC    379 _ENCIE	=	0x00ac
                    00AD    380 Fexample_usb_com$STIE$0$0 == 0x00ad
                    00AD    381 _STIE	=	0x00ad
                    00AE    382 Fexample_usb_com$_IEN06$0$0 == 0x00ae
                    00AE    383 __IEN06	=	0x00ae
                    00AF    384 Fexample_usb_com$EA$0$0 == 0x00af
                    00AF    385 _EA	=	0x00af
                    00B8    386 Fexample_usb_com$DMAIE$0$0 == 0x00b8
                    00B8    387 _DMAIE	=	0x00b8
                    00B9    388 Fexample_usb_com$T1IE$0$0 == 0x00b9
                    00B9    389 _T1IE	=	0x00b9
                    00BA    390 Fexample_usb_com$T2IE$0$0 == 0x00ba
                    00BA    391 _T2IE	=	0x00ba
                    00BB    392 Fexample_usb_com$T3IE$0$0 == 0x00bb
                    00BB    393 _T3IE	=	0x00bb
                    00BC    394 Fexample_usb_com$T4IE$0$0 == 0x00bc
                    00BC    395 _T4IE	=	0x00bc
                    00BD    396 Fexample_usb_com$P0IE$0$0 == 0x00bd
                    00BD    397 _P0IE	=	0x00bd
                    00BE    398 Fexample_usb_com$_IEN16$0$0 == 0x00be
                    00BE    399 __IEN16	=	0x00be
                    00BF    400 Fexample_usb_com$_IEN17$0$0 == 0x00bf
                    00BF    401 __IEN17	=	0x00bf
                    00C0    402 Fexample_usb_com$DMAIF$0$0 == 0x00c0
                    00C0    403 _DMAIF	=	0x00c0
                    00C1    404 Fexample_usb_com$T1IF$0$0 == 0x00c1
                    00C1    405 _T1IF	=	0x00c1
                    00C2    406 Fexample_usb_com$T2IF$0$0 == 0x00c2
                    00C2    407 _T2IF	=	0x00c2
                    00C3    408 Fexample_usb_com$T3IF$0$0 == 0x00c3
                    00C3    409 _T3IF	=	0x00c3
                    00C4    410 Fexample_usb_com$T4IF$0$0 == 0x00c4
                    00C4    411 _T4IF	=	0x00c4
                    00C5    412 Fexample_usb_com$P0IF$0$0 == 0x00c5
                    00C5    413 _P0IF	=	0x00c5
                    00C6    414 Fexample_usb_com$_IRCON6$0$0 == 0x00c6
                    00C6    415 __IRCON6	=	0x00c6
                    00C7    416 Fexample_usb_com$STIF$0$0 == 0x00c7
                    00C7    417 _STIF	=	0x00c7
                    00D0    418 Fexample_usb_com$P$0$0 == 0x00d0
                    00D0    419 _P	=	0x00d0
                    00D1    420 Fexample_usb_com$F1$0$0 == 0x00d1
                    00D1    421 _F1	=	0x00d1
                    00D2    422 Fexample_usb_com$OV$0$0 == 0x00d2
                    00D2    423 _OV	=	0x00d2
                    00D3    424 Fexample_usb_com$RS0$0$0 == 0x00d3
                    00D3    425 _RS0	=	0x00d3
                    00D4    426 Fexample_usb_com$RS1$0$0 == 0x00d4
                    00D4    427 _RS1	=	0x00d4
                    00D5    428 Fexample_usb_com$F0$0$0 == 0x00d5
                    00D5    429 _F0	=	0x00d5
                    00D6    430 Fexample_usb_com$AC$0$0 == 0x00d6
                    00D6    431 _AC	=	0x00d6
                    00D7    432 Fexample_usb_com$CY$0$0 == 0x00d7
                    00D7    433 _CY	=	0x00d7
                    00D8    434 Fexample_usb_com$T3OVFIF$0$0 == 0x00d8
                    00D8    435 _T3OVFIF	=	0x00d8
                    00D9    436 Fexample_usb_com$T3CH0IF$0$0 == 0x00d9
                    00D9    437 _T3CH0IF	=	0x00d9
                    00DA    438 Fexample_usb_com$T3CH1IF$0$0 == 0x00da
                    00DA    439 _T3CH1IF	=	0x00da
                    00DB    440 Fexample_usb_com$T4OVFIF$0$0 == 0x00db
                    00DB    441 _T4OVFIF	=	0x00db
                    00DC    442 Fexample_usb_com$T4CH0IF$0$0 == 0x00dc
                    00DC    443 _T4CH0IF	=	0x00dc
                    00DD    444 Fexample_usb_com$T4CH1IF$0$0 == 0x00dd
                    00DD    445 _T4CH1IF	=	0x00dd
                    00DE    446 Fexample_usb_com$OVFIM$0$0 == 0x00de
                    00DE    447 _OVFIM	=	0x00de
                    00DF    448 Fexample_usb_com$_TIMIF7$0$0 == 0x00df
                    00DF    449 __TIMIF7	=	0x00df
                    00E0    450 Fexample_usb_com$ACC_0$0$0 == 0x00e0
                    00E0    451 _ACC_0	=	0x00e0
                    00E1    452 Fexample_usb_com$ACC_1$0$0 == 0x00e1
                    00E1    453 _ACC_1	=	0x00e1
                    00E2    454 Fexample_usb_com$ACC_2$0$0 == 0x00e2
                    00E2    455 _ACC_2	=	0x00e2
                    00E3    456 Fexample_usb_com$ACC_3$0$0 == 0x00e3
                    00E3    457 _ACC_3	=	0x00e3
                    00E4    458 Fexample_usb_com$ACC_4$0$0 == 0x00e4
                    00E4    459 _ACC_4	=	0x00e4
                    00E5    460 Fexample_usb_com$ACC_5$0$0 == 0x00e5
                    00E5    461 _ACC_5	=	0x00e5
                    00E6    462 Fexample_usb_com$ACC_6$0$0 == 0x00e6
                    00E6    463 _ACC_6	=	0x00e6
                    00E7    464 Fexample_usb_com$ACC_7$0$0 == 0x00e7
                    00E7    465 _ACC_7	=	0x00e7
                    00E8    466 Fexample_usb_com$P2IF$0$0 == 0x00e8
                    00E8    467 _P2IF	=	0x00e8
                    00E9    468 Fexample_usb_com$UTX0IF$0$0 == 0x00e9
                    00E9    469 _UTX0IF	=	0x00e9
                    00EA    470 Fexample_usb_com$UTX1IF$0$0 == 0x00ea
                    00EA    471 _UTX1IF	=	0x00ea
                    00EB    472 Fexample_usb_com$P1IF$0$0 == 0x00eb
                    00EB    473 _P1IF	=	0x00eb
                    00EC    474 Fexample_usb_com$WDTIF$0$0 == 0x00ec
                    00EC    475 _WDTIF	=	0x00ec
                    00ED    476 Fexample_usb_com$_IRCON25$0$0 == 0x00ed
                    00ED    477 __IRCON25	=	0x00ed
                    00EE    478 Fexample_usb_com$_IRCON26$0$0 == 0x00ee
                    00EE    479 __IRCON26	=	0x00ee
                    00EF    480 Fexample_usb_com$_IRCON27$0$0 == 0x00ef
                    00EF    481 __IRCON27	=	0x00ef
                    00F0    482 Fexample_usb_com$B_0$0$0 == 0x00f0
                    00F0    483 _B_0	=	0x00f0
                    00F1    484 Fexample_usb_com$B_1$0$0 == 0x00f1
                    00F1    485 _B_1	=	0x00f1
                    00F2    486 Fexample_usb_com$B_2$0$0 == 0x00f2
                    00F2    487 _B_2	=	0x00f2
                    00F3    488 Fexample_usb_com$B_3$0$0 == 0x00f3
                    00F3    489 _B_3	=	0x00f3
                    00F4    490 Fexample_usb_com$B_4$0$0 == 0x00f4
                    00F4    491 _B_4	=	0x00f4
                    00F5    492 Fexample_usb_com$B_5$0$0 == 0x00f5
                    00F5    493 _B_5	=	0x00f5
                    00F6    494 Fexample_usb_com$B_6$0$0 == 0x00f6
                    00F6    495 _B_6	=	0x00f6
                    00F7    496 Fexample_usb_com$B_7$0$0 == 0x00f7
                    00F7    497 _B_7	=	0x00f7
                    00F8    498 Fexample_usb_com$U1ACTIVE$0$0 == 0x00f8
                    00F8    499 _U1ACTIVE	=	0x00f8
                    00F9    500 Fexample_usb_com$U1TX_BYTE$0$0 == 0x00f9
                    00F9    501 _U1TX_BYTE	=	0x00f9
                    00FA    502 Fexample_usb_com$U1RX_BYTE$0$0 == 0x00fa
                    00FA    503 _U1RX_BYTE	=	0x00fa
                    00FB    504 Fexample_usb_com$U1ERR$0$0 == 0x00fb
                    00FB    505 _U1ERR	=	0x00fb
                    00FC    506 Fexample_usb_com$U1FE$0$0 == 0x00fc
                    00FC    507 _U1FE	=	0x00fc
                    00FD    508 Fexample_usb_com$U1SLAVE$0$0 == 0x00fd
                    00FD    509 _U1SLAVE	=	0x00fd
                    00FE    510 Fexample_usb_com$U1RE$0$0 == 0x00fe
                    00FE    511 _U1RE	=	0x00fe
                    00FF    512 Fexample_usb_com$U1MODE$0$0 == 0x00ff
                    00FF    513 _U1MODE	=	0x00ff
                            514 ;--------------------------------------------------------
                            515 ; overlayable register banks
                            516 ;--------------------------------------------------------
                            517 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     518 	.ds 8
                            519 ;--------------------------------------------------------
                            520 ; internal ram data
                            521 ;--------------------------------------------------------
                            522 	.area DSEG    (DATA)
                            523 ;--------------------------------------------------------
                            524 ; overlayable items in internal ram 
                            525 ;--------------------------------------------------------
                            526 	.area OSEG    (OVR,DATA)
                            527 ;--------------------------------------------------------
                            528 ; Stack segment in internal ram 
                            529 ;--------------------------------------------------------
                            530 	.area	SSEG	(DATA)
   0023                     531 __start__stack:
   0023                     532 	.ds	1
                            533 
                            534 ;--------------------------------------------------------
                            535 ; indirectly addressable internal ram data
                            536 ;--------------------------------------------------------
                            537 	.area ISEG    (DATA)
                            538 ;--------------------------------------------------------
                            539 ; absolute internal ram data
                            540 ;--------------------------------------------------------
                            541 	.area IABS    (ABS,DATA)
                            542 	.area IABS    (ABS,DATA)
                            543 ;--------------------------------------------------------
                            544 ; bit data
                            545 ;--------------------------------------------------------
                            546 	.area BSEG    (BIT)
                    0000    547 G$yellowLedOn$0$0==.
   0000                     548 _yellowLedOn::
   0000                     549 	.ds 1
                    0001    550 G$serialProtocolError$0$0==.
   0001                     551 _serialProtocolError::
   0001                     552 	.ds 1
                            553 ;--------------------------------------------------------
                            554 ; paged external ram data
                            555 ;--------------------------------------------------------
                            556 	.area PSEG    (PAG,XDATA)
                    0000    557 G$x$0$0==.
   F000                     558 _x::
   F000                     559 	.ds 2
                    0002    560 G$commandByte$0$0==.
   F002                     561 _commandByte::
   F002                     562 	.ds 1
                    0003    563 G$dataBytes$0$0==.
   F003                     564 _dataBytes::
   F003                     565 	.ds 32
                    0023    566 G$dataBytesLeft$0$0==.
   F023                     567 _dataBytesLeft::
   F023                     568 	.ds 1
                    0024    569 G$dataBytesReceived$0$0==.
   F024                     570 _dataBytesReceived::
   F024                     571 	.ds 1
                            572 ;--------------------------------------------------------
                            573 ; external ram data
                            574 ;--------------------------------------------------------
                            575 	.area XSEG    (XDATA)
                    DF00    576 Fexample_usb_com$SYNC1$0$0 == 0xdf00
                    DF00    577 _SYNC1	=	0xdf00
                    DF01    578 Fexample_usb_com$SYNC0$0$0 == 0xdf01
                    DF01    579 _SYNC0	=	0xdf01
                    DF02    580 Fexample_usb_com$PKTLEN$0$0 == 0xdf02
                    DF02    581 _PKTLEN	=	0xdf02
                    DF03    582 Fexample_usb_com$PKTCTRL1$0$0 == 0xdf03
                    DF03    583 _PKTCTRL1	=	0xdf03
                    DF04    584 Fexample_usb_com$PKTCTRL0$0$0 == 0xdf04
                    DF04    585 _PKTCTRL0	=	0xdf04
                    DF05    586 Fexample_usb_com$ADDR$0$0 == 0xdf05
                    DF05    587 _ADDR	=	0xdf05
                    DF06    588 Fexample_usb_com$CHANNR$0$0 == 0xdf06
                    DF06    589 _CHANNR	=	0xdf06
                    DF07    590 Fexample_usb_com$FSCTRL1$0$0 == 0xdf07
                    DF07    591 _FSCTRL1	=	0xdf07
                    DF08    592 Fexample_usb_com$FSCTRL0$0$0 == 0xdf08
                    DF08    593 _FSCTRL0	=	0xdf08
                    DF09    594 Fexample_usb_com$FREQ2$0$0 == 0xdf09
                    DF09    595 _FREQ2	=	0xdf09
                    DF0A    596 Fexample_usb_com$FREQ1$0$0 == 0xdf0a
                    DF0A    597 _FREQ1	=	0xdf0a
                    DF0B    598 Fexample_usb_com$FREQ0$0$0 == 0xdf0b
                    DF0B    599 _FREQ0	=	0xdf0b
                    DF0C    600 Fexample_usb_com$MDMCFG4$0$0 == 0xdf0c
                    DF0C    601 _MDMCFG4	=	0xdf0c
                    DF0D    602 Fexample_usb_com$MDMCFG3$0$0 == 0xdf0d
                    DF0D    603 _MDMCFG3	=	0xdf0d
                    DF0E    604 Fexample_usb_com$MDMCFG2$0$0 == 0xdf0e
                    DF0E    605 _MDMCFG2	=	0xdf0e
                    DF0F    606 Fexample_usb_com$MDMCFG1$0$0 == 0xdf0f
                    DF0F    607 _MDMCFG1	=	0xdf0f
                    DF10    608 Fexample_usb_com$MDMCFG0$0$0 == 0xdf10
                    DF10    609 _MDMCFG0	=	0xdf10
                    DF11    610 Fexample_usb_com$DEVIATN$0$0 == 0xdf11
                    DF11    611 _DEVIATN	=	0xdf11
                    DF12    612 Fexample_usb_com$MCSM2$0$0 == 0xdf12
                    DF12    613 _MCSM2	=	0xdf12
                    DF13    614 Fexample_usb_com$MCSM1$0$0 == 0xdf13
                    DF13    615 _MCSM1	=	0xdf13
                    DF14    616 Fexample_usb_com$MCSM0$0$0 == 0xdf14
                    DF14    617 _MCSM0	=	0xdf14
                    DF15    618 Fexample_usb_com$FOCCFG$0$0 == 0xdf15
                    DF15    619 _FOCCFG	=	0xdf15
                    DF16    620 Fexample_usb_com$BSCFG$0$0 == 0xdf16
                    DF16    621 _BSCFG	=	0xdf16
                    DF17    622 Fexample_usb_com$AGCCTRL2$0$0 == 0xdf17
                    DF17    623 _AGCCTRL2	=	0xdf17
                    DF18    624 Fexample_usb_com$AGCCTRL1$0$0 == 0xdf18
                    DF18    625 _AGCCTRL1	=	0xdf18
                    DF19    626 Fexample_usb_com$AGCCTRL0$0$0 == 0xdf19
                    DF19    627 _AGCCTRL0	=	0xdf19
                    DF1A    628 Fexample_usb_com$FREND1$0$0 == 0xdf1a
                    DF1A    629 _FREND1	=	0xdf1a
                    DF1B    630 Fexample_usb_com$FREND0$0$0 == 0xdf1b
                    DF1B    631 _FREND0	=	0xdf1b
                    DF1C    632 Fexample_usb_com$FSCAL3$0$0 == 0xdf1c
                    DF1C    633 _FSCAL3	=	0xdf1c
                    DF1D    634 Fexample_usb_com$FSCAL2$0$0 == 0xdf1d
                    DF1D    635 _FSCAL2	=	0xdf1d
                    DF1E    636 Fexample_usb_com$FSCAL1$0$0 == 0xdf1e
                    DF1E    637 _FSCAL1	=	0xdf1e
                    DF1F    638 Fexample_usb_com$FSCAL0$0$0 == 0xdf1f
                    DF1F    639 _FSCAL0	=	0xdf1f
                    DF23    640 Fexample_usb_com$TEST2$0$0 == 0xdf23
                    DF23    641 _TEST2	=	0xdf23
                    DF24    642 Fexample_usb_com$TEST1$0$0 == 0xdf24
                    DF24    643 _TEST1	=	0xdf24
                    DF25    644 Fexample_usb_com$TEST0$0$0 == 0xdf25
                    DF25    645 _TEST0	=	0xdf25
                    DF2E    646 Fexample_usb_com$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    647 _PA_TABLE0	=	0xdf2e
                    DF2F    648 Fexample_usb_com$IOCFG2$0$0 == 0xdf2f
                    DF2F    649 _IOCFG2	=	0xdf2f
                    DF30    650 Fexample_usb_com$IOCFG1$0$0 == 0xdf30
                    DF30    651 _IOCFG1	=	0xdf30
                    DF31    652 Fexample_usb_com$IOCFG0$0$0 == 0xdf31
                    DF31    653 _IOCFG0	=	0xdf31
                    DF36    654 Fexample_usb_com$PARTNUM$0$0 == 0xdf36
                    DF36    655 _PARTNUM	=	0xdf36
                    DF37    656 Fexample_usb_com$VERSION$0$0 == 0xdf37
                    DF37    657 _VERSION	=	0xdf37
                    DF38    658 Fexample_usb_com$FREQEST$0$0 == 0xdf38
                    DF38    659 _FREQEST	=	0xdf38
                    DF39    660 Fexample_usb_com$LQI$0$0 == 0xdf39
                    DF39    661 _LQI	=	0xdf39
                    DF3A    662 Fexample_usb_com$RSSI$0$0 == 0xdf3a
                    DF3A    663 _RSSI	=	0xdf3a
                    DF3B    664 Fexample_usb_com$MARCSTATE$0$0 == 0xdf3b
                    DF3B    665 _MARCSTATE	=	0xdf3b
                    DF3C    666 Fexample_usb_com$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    667 _PKTSTATUS	=	0xdf3c
                    DF3D    668 Fexample_usb_com$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    669 _VCO_VC_DAC	=	0xdf3d
                    DF40    670 Fexample_usb_com$I2SCFG0$0$0 == 0xdf40
                    DF40    671 _I2SCFG0	=	0xdf40
                    DF41    672 Fexample_usb_com$I2SCFG1$0$0 == 0xdf41
                    DF41    673 _I2SCFG1	=	0xdf41
                    DF42    674 Fexample_usb_com$I2SDATL$0$0 == 0xdf42
                    DF42    675 _I2SDATL	=	0xdf42
                    DF43    676 Fexample_usb_com$I2SDATH$0$0 == 0xdf43
                    DF43    677 _I2SDATH	=	0xdf43
                    DF44    678 Fexample_usb_com$I2SWCNT$0$0 == 0xdf44
                    DF44    679 _I2SWCNT	=	0xdf44
                    DF45    680 Fexample_usb_com$I2SSTAT$0$0 == 0xdf45
                    DF45    681 _I2SSTAT	=	0xdf45
                    DF46    682 Fexample_usb_com$I2SCLKF0$0$0 == 0xdf46
                    DF46    683 _I2SCLKF0	=	0xdf46
                    DF47    684 Fexample_usb_com$I2SCLKF1$0$0 == 0xdf47
                    DF47    685 _I2SCLKF1	=	0xdf47
                    DF48    686 Fexample_usb_com$I2SCLKF2$0$0 == 0xdf48
                    DF48    687 _I2SCLKF2	=	0xdf48
                    DE00    688 Fexample_usb_com$USBADDR$0$0 == 0xde00
                    DE00    689 _USBADDR	=	0xde00
                    DE01    690 Fexample_usb_com$USBPOW$0$0 == 0xde01
                    DE01    691 _USBPOW	=	0xde01
                    DE02    692 Fexample_usb_com$USBIIF$0$0 == 0xde02
                    DE02    693 _USBIIF	=	0xde02
                    DE04    694 Fexample_usb_com$USBOIF$0$0 == 0xde04
                    DE04    695 _USBOIF	=	0xde04
                    DE06    696 Fexample_usb_com$USBCIF$0$0 == 0xde06
                    DE06    697 _USBCIF	=	0xde06
                    DE07    698 Fexample_usb_com$USBIIE$0$0 == 0xde07
                    DE07    699 _USBIIE	=	0xde07
                    DE09    700 Fexample_usb_com$USBOIE$0$0 == 0xde09
                    DE09    701 _USBOIE	=	0xde09
                    DE0B    702 Fexample_usb_com$USBCIE$0$0 == 0xde0b
                    DE0B    703 _USBCIE	=	0xde0b
                    DE0C    704 Fexample_usb_com$USBFRML$0$0 == 0xde0c
                    DE0C    705 _USBFRML	=	0xde0c
                    DE0D    706 Fexample_usb_com$USBFRMH$0$0 == 0xde0d
                    DE0D    707 _USBFRMH	=	0xde0d
                    DE0E    708 Fexample_usb_com$USBINDEX$0$0 == 0xde0e
                    DE0E    709 _USBINDEX	=	0xde0e
                    DE10    710 Fexample_usb_com$USBMAXI$0$0 == 0xde10
                    DE10    711 _USBMAXI	=	0xde10
                    DE11    712 Fexample_usb_com$USBCSIL$0$0 == 0xde11
                    DE11    713 _USBCSIL	=	0xde11
                    DE12    714 Fexample_usb_com$USBCSIH$0$0 == 0xde12
                    DE12    715 _USBCSIH	=	0xde12
                    DE13    716 Fexample_usb_com$USBMAXO$0$0 == 0xde13
                    DE13    717 _USBMAXO	=	0xde13
                    DE14    718 Fexample_usb_com$USBCSOL$0$0 == 0xde14
                    DE14    719 _USBCSOL	=	0xde14
                    DE15    720 Fexample_usb_com$USBCSOH$0$0 == 0xde15
                    DE15    721 _USBCSOH	=	0xde15
                    DE16    722 Fexample_usb_com$USBCNTL$0$0 == 0xde16
                    DE16    723 _USBCNTL	=	0xde16
                    DE17    724 Fexample_usb_com$USBCNTH$0$0 == 0xde17
                    DE17    725 _USBCNTH	=	0xde17
                    DE20    726 Fexample_usb_com$USBF0$0$0 == 0xde20
                    DE20    727 _USBF0	=	0xde20
                    DE22    728 Fexample_usb_com$USBF1$0$0 == 0xde22
                    DE22    729 _USBF1	=	0xde22
                    DE24    730 Fexample_usb_com$USBF2$0$0 == 0xde24
                    DE24    731 _USBF2	=	0xde24
                    DE26    732 Fexample_usb_com$USBF3$0$0 == 0xde26
                    DE26    733 _USBF3	=	0xde26
                    DE28    734 Fexample_usb_com$USBF4$0$0 == 0xde28
                    DE28    735 _USBF4	=	0xde28
                    DE2A    736 Fexample_usb_com$USBF5$0$0 == 0xde2a
                    DE2A    737 _USBF5	=	0xde2a
                    0000    738 G$response$0$0==.
   F065                     739 _response::
   F065                     740 	.ds 32
                            741 ;--------------------------------------------------------
                            742 ; absolute external ram data
                            743 ;--------------------------------------------------------
                            744 	.area XABS    (ABS,XDATA)
                            745 ;--------------------------------------------------------
                            746 ; external initialized ram data
                            747 ;--------------------------------------------------------
                            748 	.area XISEG   (XDATA)
                            749 	.area HOME    (CODE)
                            750 	.area GSINIT0 (CODE)
                            751 	.area GSINIT1 (CODE)
                            752 	.area GSINIT2 (CODE)
                            753 	.area GSINIT3 (CODE)
                            754 	.area GSINIT4 (CODE)
                            755 	.area GSINIT5 (CODE)
                            756 	.area GSINIT  (CODE)
                            757 	.area GSFINAL (CODE)
                            758 	.area CSEG    (CODE)
                            759 ;--------------------------------------------------------
                            760 ; interrupt vector 
                            761 ;--------------------------------------------------------
                            762 	.area HOME    (CODE)
   0400                     763 __interrupt_vect:
   0400 02 04 6D            764 	ljmp	__sdcc_gsinit_startup
   0403 32                  765 	reti
   0404                     766 	.ds	7
   040B 32                  767 	reti
   040C                     768 	.ds	7
   0413 32                  769 	reti
   0414                     770 	.ds	7
   041B 32                  771 	reti
   041C                     772 	.ds	7
   0423 32                  773 	reti
   0424                     774 	.ds	7
   042B 32                  775 	reti
   042C                     776 	.ds	7
   0433 32                  777 	reti
   0434                     778 	.ds	7
   043B 32                  779 	reti
   043C                     780 	.ds	7
   0443 32                  781 	reti
   0444                     782 	.ds	7
   044B 32                  783 	reti
   044C                     784 	.ds	7
   0453 32                  785 	reti
   0454                     786 	.ds	7
   045B 32                  787 	reti
   045C                     788 	.ds	7
   0463 02 10 9A            789 	ljmp	_ISR_T4
                            790 ;--------------------------------------------------------
                            791 ; global & static initialisations
                            792 ;--------------------------------------------------------
                            793 	.area HOME    (CODE)
                            794 	.area GSINIT  (CODE)
                            795 	.area GSFINAL (CODE)
                            796 	.area GSINIT  (CODE)
                            797 	.globl __sdcc_gsinit_startup
                            798 	.globl __sdcc_program_startup
                            799 	.globl __start__stack
                            800 	.globl __mcs51_genXINIT
                            801 	.globl __mcs51_genXRAMCLEAR
                            802 	.globl __mcs51_genRAMCLEAR
                    0000    803 	G$main$0$0 ==.
                    0000    804 	C$example_usb_com.c$50$1$1 ==.
                            805 ;	apps/example_usb_com/example_usb_com.c:50: BIT yellowLedOn = 0;
   04C6 C2 00               806 	clr	_yellowLedOn
                    0002    807 	G$main$0$0 ==.
                    0002    808 	C$example_usb_com.c$53$1$1 ==.
                            809 ;	apps/example_usb_com/example_usb_com.c:53: BIT serialProtocolError = 0;
   04C8 C2 01               810 	clr	_serialProtocolError
                    0004    811 	G$main$0$0 ==.
                    0004    812 	C$example_usb_com.c$47$1$1 ==.
                            813 ;	apps/example_usb_com/example_usb_com.c:47: uint16 x = 0x3FFF;
   04CA 78 00               814 	mov	r0,#_x
   04CC 74 FF               815 	mov	a,#0xFF
   04CE F2                  816 	movx	@r0,a
   04CF 08                  817 	inc	r0
   04D0 74 3F               818 	mov	a,#0x3F
   04D2 F2                  819 	movx	@r0,a
                    000D    820 	G$main$0$0 ==.
                    000D    821 	C$example_usb_com.c$64$1$1 ==.
                            822 ;	apps/example_usb_com/example_usb_com.c:64: uint8 dataBytesLeft = 0;
   04D3 78 23               823 	mov	r0,#_dataBytesLeft
   04D5 E4                  824 	clr	a
   04D6 F2                  825 	movx	@r0,a
                            826 	.area GSFINAL (CODE)
   0501 02 04 66            827 	ljmp	__sdcc_program_startup
                            828 ;--------------------------------------------------------
                            829 ; Home
                            830 ;--------------------------------------------------------
                            831 	.area HOME    (CODE)
                            832 	.area HOME    (CODE)
   0466                     833 __sdcc_program_startup:
   0466 12 06 8C            834 	lcall	_main
                            835 ;	return from main will lock up
   0469 80 FE               836 	sjmp .
                            837 ;--------------------------------------------------------
                            838 ; code
                            839 ;--------------------------------------------------------
                            840 	.area CSEG    (CODE)
                            841 ;------------------------------------------------------------
                            842 ;Allocation info for local variables in function 'updateLeds'
                            843 ;------------------------------------------------------------
                    0000    844 	G$updateLeds$0$0 ==.
                    0000    845 	C$example_usb_com.c$78$0$0 ==.
                            846 ;	apps/example_usb_com/example_usb_com.c:78: void updateLeds()
                            847 ;	-----------------------------------------
                            848 ;	 function updateLeds
                            849 ;	-----------------------------------------
   0504                     850 _updateLeds:
                    0007    851 	ar7 = 0x07
                    0006    852 	ar6 = 0x06
                    0005    853 	ar5 = 0x05
                    0004    854 	ar4 = 0x04
                    0003    855 	ar3 = 0x03
                    0002    856 	ar2 = 0x02
                    0001    857 	ar1 = 0x01
                    0000    858 	ar0 = 0x00
                    0000    859 	C$example_usb_com.c$80$1$1 ==.
                            860 ;	apps/example_usb_com/example_usb_com.c:80: usbShowStatusWithGreenLed();
   0504 12 12 3B            861 	lcall	_usbShowStatusWithGreenLed
                    0003    862 	C$example_usb_com.c$81$2$2 ==.
                            863 ;	apps/example_usb_com/example_usb_com.c:81: LED_YELLOW(yellowLedOn);
   0507 30 00 05            864 	jnb	_yellowLedOn,00103$
   050A 43 FF 04            865 	orl	_P2DIR,#0x04
   050D 80 07               866 	sjmp	00104$
   050F                     867 00103$:
   050F AF FF               868 	mov	r7,_P2DIR
   0511 53 07 FB            869 	anl	ar7,#0xFB
   0514 8F FF               870 	mov	_P2DIR,r7
   0516                     871 00104$:
                    0012    872 	C$example_usb_com.c$82$2$3 ==.
                            873 ;	apps/example_usb_com/example_usb_com.c:82: LED_RED(serialProtocolError);
   0516 30 01 05            874 	jnb	_serialProtocolError,00105$
   0519 43 FF 02            875 	orl	_P2DIR,#0x02
   051C 80 07               876 	sjmp	00101$
   051E                     877 00105$:
   051E AF FF               878 	mov	r7,_P2DIR
   0520 53 07 FD            879 	anl	ar7,#0xFD
   0523 8F FF               880 	mov	_P2DIR,r7
   0525                     881 00101$:
                    0021    882 	C$example_usb_com.c$83$2$3 ==.
                    0021    883 	XG$updateLeds$0$0 ==.
   0525 22                  884 	ret
                            885 ;------------------------------------------------------------
                            886 ;Allocation info for local variables in function 'executeCommand'
                            887 ;------------------------------------------------------------
                    0022    888 	G$executeCommand$0$0 ==.
                    0022    889 	C$example_usb_com.c$85$2$3 ==.
                            890 ;	apps/example_usb_com/example_usb_com.c:85: void executeCommand()
                            891 ;	-----------------------------------------
                            892 ;	 function executeCommand
                            893 ;	-----------------------------------------
   0526                     894 _executeCommand:
                    0022    895 	C$example_usb_com.c$87$1$1 ==.
                            896 ;	apps/example_usb_com/example_usb_com.c:87: switch(commandByte)
   0526 78 02               897 	mov	r0,#_commandByte
   0528 E2                  898 	movx	a,@r0
   0529 B4 81 02            899 	cjne	a,#0x81,00112$
   052C 80 18               900 	sjmp	00101$
   052E                     901 00112$:
   052E 78 02               902 	mov	r0,#_commandByte
   0530 E2                  903 	movx	a,@r0
   0531 B4 82 02            904 	cjne	a,#0x82,00113$
   0534 80 1D               905 	sjmp	00102$
   0536                     906 00113$:
   0536 78 02               907 	mov	r0,#_commandByte
   0538 E2                  908 	movx	a,@r0
   0539 B4 83 02            909 	cjne	a,#0x83,00114$
   053C 80 38               910 	sjmp	00103$
   053E                     911 00114$:
   053E 78 02               912 	mov	r0,#_commandByte
   0540 E2                  913 	movx	a,@r0
                    003D    914 	C$example_usb_com.c$89$2$2 ==.
                            915 ;	apps/example_usb_com/example_usb_com.c:89: case COMMAND_TOGGLE_YELLOW_LED:
   0541 B4 84 58            916 	cjne	a,#0x84,00106$
   0544 80 54               917 	sjmp	00104$
   0546                     918 00101$:
                    0042    919 	C$example_usb_com.c$90$2$2 ==.
                            920 ;	apps/example_usb_com/example_usb_com.c:90: yellowLedOn ^= 1;
   0546 A2 00               921 	mov	c,_yellowLedOn
   0548 E4                  922 	clr	a
   0549 33                  923 	rlc	a
   054A 64 01               924 	xrl	a,#0x01
   054C FF                  925 	mov	r7,a
   054D 24 FF               926 	add	a,#0xff
   054F 92 00               927 	mov	_yellowLedOn,c
                    004D    928 	C$example_usb_com.c$91$2$2 ==.
                            929 ;	apps/example_usb_com/example_usb_com.c:91: break;
                    004D    930 	C$example_usb_com.c$93$2$2 ==.
                            931 ;	apps/example_usb_com/example_usb_com.c:93: case COMMAND_GET_X:
   0551 80 49               932 	sjmp	00106$
   0553                     933 00102$:
                    004F    934 	C$example_usb_com.c$94$2$2 ==.
                            935 ;	apps/example_usb_com/example_usb_com.c:94: response[0] = x & 0xFF;
   0553 78 00               936 	mov	r0,#_x
   0555 E2                  937 	movx	a,@r0
   0556 54 FF               938 	anl	a,#0xFF
   0558 FE                  939 	mov	r6,a
   0559 08                  940 	inc	r0
   055A E2                  941 	movx	a,@r0
   055B 54 00               942 	anl	a,#0x00
   055D 90 F0 65            943 	mov	dptr,#_response
   0560 EE                  944 	mov	a,r6
   0561 F0                  945 	movx	@dptr,a
                    005E    946 	C$example_usb_com.c$95$2$2 ==.
                            947 ;	apps/example_usb_com/example_usb_com.c:95: response[1] = x >> 8 & 0xFF;
   0562 78 01               948 	mov	r0,#(_x + 1)
   0564 E2                  949 	movx	a,@r0
   0565 90 F0 66            950 	mov	dptr,#(_response + 0x0001)
   0568 F0                  951 	movx	@dptr,a
                    0065    952 	C$example_usb_com.c$96$2$2 ==.
                            953 ;	apps/example_usb_com/example_usb_com.c:96: usbComTxSend(response, 2);   // Assumption: usbComTxAvailable() returned >= 2 recently.
   0569 78 2B               954 	mov	r0,#_usbComTxSend_PARM_2
   056B 74 02               955 	mov	a,#0x02
   056D F2                  956 	movx	@r0,a
   056E 90 F0 65            957 	mov	dptr,#_response
   0571 12 08 D3            958 	lcall	_usbComTxSend
                    0070    959 	C$example_usb_com.c$97$2$2 ==.
                            960 ;	apps/example_usb_com/example_usb_com.c:97: break;
                    0070    961 	C$example_usb_com.c$99$2$2 ==.
                            962 ;	apps/example_usb_com/example_usb_com.c:99: case COMMAND_SET_X:
   0574 80 26               963 	sjmp	00106$
   0576                     964 00103$:
                    0072    965 	C$example_usb_com.c$100$2$2 ==.
                            966 ;	apps/example_usb_com/example_usb_com.c:100: x = dataBytes[0] + (dataBytes[1] << 7);
   0576 78 03               967 	mov	r0,#_dataBytes
   0578 E2                  968 	movx	a,@r0
   0579 FF                  969 	mov	r7,a
   057A 7E 00               970 	mov	r6,#0x00
   057C 78 04               971 	mov	r0,#(_dataBytes + 0x0001)
   057E E2                  972 	movx	a,@r0
   057F FD                  973 	mov	r5,a
   0580 E4                  974 	clr	a
   0581 54 01               975 	anl	a,#0x01
   0583 A2 E0               976 	mov	c,acc.0
   0585 CD                  977 	xch	a,r5
   0586 13                  978 	rrc	a
   0587 CD                  979 	xch	a,r5
   0588 13                  980 	rrc	a
   0589 CD                  981 	xch	a,r5
   058A FC                  982 	mov	r4,a
   058B ED                  983 	mov	a,r5
   058C 2F                  984 	add	a,r7
   058D FF                  985 	mov	r7,a
   058E EC                  986 	mov	a,r4
   058F 3E                  987 	addc	a,r6
   0590 FE                  988 	mov	r6,a
   0591 78 00               989 	mov	r0,#_x
   0593 EF                  990 	mov	a,r7
   0594 F2                  991 	movx	@r0,a
   0595 08                  992 	inc	r0
   0596 EE                  993 	mov	a,r6
   0597 F2                  994 	movx	@r0,a
                    0094    995 	C$example_usb_com.c$101$2$2 ==.
                            996 ;	apps/example_usb_com/example_usb_com.c:101: break;
                    0094    997 	C$example_usb_com.c$103$2$2 ==.
                            998 ;	apps/example_usb_com/example_usb_com.c:103: case COMMAND_CLEAR_ERROR:
   0598 80 02               999 	sjmp	00106$
   059A                    1000 00104$:
                    0096   1001 	C$example_usb_com.c$104$2$2 ==.
                           1002 ;	apps/example_usb_com/example_usb_com.c:104: serialProtocolError = 0;
   059A C2 01              1003 	clr	_serialProtocolError
                    0098   1004 	C$example_usb_com.c$106$1$1 ==.
                           1005 ;	apps/example_usb_com/example_usb_com.c:106: }
   059C                    1006 00106$:
                    0098   1007 	C$example_usb_com.c$107$1$1 ==.
                    0098   1008 	XG$executeCommand$0$0 ==.
   059C 22                 1009 	ret
                           1010 ;------------------------------------------------------------
                           1011 ;Allocation info for local variables in function 'processByte'
                           1012 ;------------------------------------------------------------
                    0099   1013 	G$processByte$0$0 ==.
                    0099   1014 	C$example_usb_com.c$122$1$1 ==.
                           1015 ;	apps/example_usb_com/example_usb_com.c:122: void processByte(uint8 byteReceived)
                           1016 ;	-----------------------------------------
                           1017 ;	 function processByte
                           1018 ;	-----------------------------------------
   059D                    1019 _processByte:
                    0099   1020 	C$example_usb_com.c$124$1$1 ==.
                           1021 ;	apps/example_usb_com/example_usb_com.c:124: if (byteReceived & 0x80)
   059D E5 82              1022 	mov	a,dpl
   059F FF                 1023 	mov	r7,a
   05A0 30 E7 45           1024 	jnb	acc.7,00120$
                    009F   1025 	C$example_usb_com.c$128$2$2 ==.
                           1026 ;	apps/example_usb_com/example_usb_com.c:128: if (dataBytesLeft > 0)
   05A3 78 23              1027 	mov	r0,#_dataBytesLeft
   05A5 E2                 1028 	movx	a,@r0
   05A6 60 02              1029 	jz	00102$
                    00A4   1030 	C$example_usb_com.c$130$3$3 ==.
                           1031 ;	apps/example_usb_com/example_usb_com.c:130: serialProtocolError = 1;
   05A8 D2 01              1032 	setb	_serialProtocolError
   05AA                    1033 00102$:
                    00A6   1034 	C$example_usb_com.c$133$2$2 ==.
                           1035 ;	apps/example_usb_com/example_usb_com.c:133: commandByte = byteReceived;
   05AA 78 02              1036 	mov	r0,#_commandByte
   05AC EF                 1037 	mov	a,r7
   05AD F2                 1038 	movx	@r0,a
                    00AA   1039 	C$example_usb_com.c$134$2$2 ==.
                           1040 ;	apps/example_usb_com/example_usb_com.c:134: dataBytesReceived = 0;
   05AE 78 24              1041 	mov	r0,#_dataBytesReceived
   05B0 E4                 1042 	clr	a
   05B1 F2                 1043 	movx	@r0,a
                    00AE   1044 	C$example_usb_com.c$135$2$2 ==.
                           1045 ;	apps/example_usb_com/example_usb_com.c:135: dataBytesLeft = 0;
   05B2 78 23              1046 	mov	r0,#_dataBytesLeft
   05B4 E4                 1047 	clr	a
   05B5 F2                 1048 	movx	@r0,a
                    00B2   1049 	C$example_usb_com.c$139$2$2 ==.
                           1050 ;	apps/example_usb_com/example_usb_com.c:139: switch(commandByte)
   05B6 BF 81 02           1051 	cjne	r7,#0x81,00136$
   05B9 80 0D              1052 	sjmp	00105$
   05BB                    1053 00136$:
   05BB BF 82 02           1054 	cjne	r7,#0x82,00137$
   05BE 80 08              1055 	sjmp	00105$
   05C0                    1056 00137$:
   05C0 BF 83 02           1057 	cjne	r7,#0x83,00138$
   05C3 80 09              1058 	sjmp	00106$
   05C5                    1059 00138$:
   05C5 BF 84 0D           1060 	cjne	r7,#0x84,00107$
                    00C4   1061 	C$example_usb_com.c$143$3$4 ==.
                           1062 ;	apps/example_usb_com/example_usb_com.c:143: case COMMAND_CLEAR_ERROR:
   05C8                    1063 00105$:
                    00C4   1064 	C$example_usb_com.c$144$3$4 ==.
                           1065 ;	apps/example_usb_com/example_usb_com.c:144: dataBytesLeft = 0;
   05C8 78 23              1066 	mov	r0,#_dataBytesLeft
   05CA E4                 1067 	clr	a
   05CB F2                 1068 	movx	@r0,a
                    00C8   1069 	C$example_usb_com.c$145$3$4 ==.
                           1070 ;	apps/example_usb_com/example_usb_com.c:145: break;
                    00C8   1071 	C$example_usb_com.c$147$3$4 ==.
                           1072 ;	apps/example_usb_com/example_usb_com.c:147: case COMMAND_SET_X:
   05CC 80 0C              1073 	sjmp	00108$
   05CE                    1074 00106$:
                    00CA   1075 	C$example_usb_com.c$148$3$4 ==.
                           1076 ;	apps/example_usb_com/example_usb_com.c:148: dataBytesLeft = 2;
   05CE 78 23              1077 	mov	r0,#_dataBytesLeft
   05D0 74 02              1078 	mov	a,#0x02
   05D2 F2                 1079 	movx	@r0,a
                    00CF   1080 	C$example_usb_com.c$149$3$4 ==.
                           1081 ;	apps/example_usb_com/example_usb_com.c:149: break;
                    00CF   1082 	C$example_usb_com.c$151$3$4 ==.
                           1083 ;	apps/example_usb_com/example_usb_com.c:151: default:
   05D3 80 05              1084 	sjmp	00108$
   05D5                    1085 00107$:
                    00D1   1086 	C$example_usb_com.c$153$3$4 ==.
                           1087 ;	apps/example_usb_com/example_usb_com.c:153: serialProtocolError = 1;
   05D5 D2 01              1088 	setb	_serialProtocolError
                    00D3   1089 	C$example_usb_com.c$154$3$4 ==.
                           1090 ;	apps/example_usb_com/example_usb_com.c:154: return;
   05D7 02 06 67           1091 	ljmp	00122$
                    00D6   1092 	C$example_usb_com.c$155$2$2 ==.
                           1093 ;	apps/example_usb_com/example_usb_com.c:155: }
   05DA                    1094 00108$:
                    00D6   1095 	C$example_usb_com.c$157$2$2 ==.
                           1096 ;	apps/example_usb_com/example_usb_com.c:157: if (dataBytesLeft==0)
   05DA 78 23              1097 	mov	r0,#_dataBytesLeft
   05DC E2                 1098 	movx	a,@r0
   05DD 60 03              1099 	jz	00141$
   05DF 02 06 67           1100 	ljmp	00122$
   05E2                    1101 00141$:
                    00DE   1102 	C$example_usb_com.c$160$3$5 ==.
                           1103 ;	apps/example_usb_com/example_usb_com.c:160: executeCommand();
   05E2 12 05 26           1104 	lcall	_executeCommand
   05E5 02 06 67           1105 	ljmp	00122$
   05E8                    1106 00120$:
                    00E4   1107 	C$example_usb_com.c$163$1$1 ==.
                           1108 ;	apps/example_usb_com/example_usb_com.c:163: else if (dataBytesLeft > 0)
   05E8 78 23              1109 	mov	r0,#_dataBytesLeft
   05EA E2                 1110 	movx	a,@r0
   05EB 60 1D              1111 	jz	00117$
                    00E9   1112 	C$example_usb_com.c$167$2$6 ==.
                           1113 ;	apps/example_usb_com/example_usb_com.c:167: dataBytes[dataBytesReceived] = byteReceived;
   05ED 78 24              1114 	mov	r0,#_dataBytesReceived
   05EF E2                 1115 	movx	a,@r0
   05F0 24 03              1116 	add	a,#_dataBytes
   05F2 F8                 1117 	mov	r0,a
   05F3 EF                 1118 	mov	a,r7
   05F4 F2                 1119 	movx	@r0,a
                    00F1   1120 	C$example_usb_com.c$168$2$6 ==.
                           1121 ;	apps/example_usb_com/example_usb_com.c:168: dataBytesLeft--;
   05F5 78 23              1122 	mov	r0,#_dataBytesLeft
   05F7 E2                 1123 	movx	a,@r0
   05F8 14                 1124 	dec	a
   05F9 F2                 1125 	movx	@r0,a
                    00F6   1126 	C$example_usb_com.c$169$2$6 ==.
                           1127 ;	apps/example_usb_com/example_usb_com.c:169: dataBytesReceived++;
   05FA 78 24              1128 	mov	r0,#_dataBytesReceived
   05FC E2                 1129 	movx	a,@r0
   05FD 24 01              1130 	add	a,#0x01
   05FF F2                 1131 	movx	@r0,a
                    00FC   1132 	C$example_usb_com.c$171$2$6 ==.
                           1133 ;	apps/example_usb_com/example_usb_com.c:171: if (dataBytesLeft==0)
   0600 78 23              1134 	mov	r0,#_dataBytesLeft
   0602 E2                 1135 	movx	a,@r0
   0603 70 62              1136 	jnz	00122$
                    0101   1137 	C$example_usb_com.c$174$3$7 ==.
                           1138 ;	apps/example_usb_com/example_usb_com.c:174: executeCommand();
   0605 12 05 26           1139 	lcall	_executeCommand
   0608 80 5D              1140 	sjmp	00122$
   060A                    1141 00117$:
                    0106   1142 	C$example_usb_com.c$184$2$8 ==.
                           1143 ;	apps/example_usb_com/example_usb_com.c:184: switch(byteReceived)
   060A BF 74 02           1144 	cjne	r7,#0x74,00144$
   060D 80 05              1145 	sjmp	00113$
   060F                    1146 00144$:
                    010B   1147 	C$example_usb_com.c$186$3$9 ==.
                           1148 ;	apps/example_usb_com/example_usb_com.c:186: case 't':
   060F BF 79 55           1149 	cjne	r7,#0x79,00122$
   0612 80 48              1150 	sjmp	00114$
   0614                    1151 00113$:
                    0110   1152 	C$example_usb_com.c$187$3$9 ==.
                           1153 ;	apps/example_usb_com/example_usb_com.c:187: time = getMs();
   0614 12 10 BF           1154 	lcall	_getMs
   0617 AC 82              1155 	mov	r4,dpl
   0619 AD 83              1156 	mov	r5,dph
   061B AE F0              1157 	mov	r6,b
   061D FF                 1158 	mov	r7,a
                    011A   1159 	C$example_usb_com.c$190$3$9 ==.
                           1160 ;	apps/example_usb_com/example_usb_com.c:190: responseLength = sprintf(response, "time=0x%04x%04x\r\n", (uint16)(time >> 16), (uint16)time);
   061E 8C 02              1161 	mov	ar2,r4
   0620 8D 03              1162 	mov	ar3,r5
   0622 8E 04              1163 	mov	ar4,r6
   0624 8F 05              1164 	mov	ar5,r7
   0626 C0 02              1165 	push	ar2
   0628 C0 03              1166 	push	ar3
   062A C0 04              1167 	push	ar4
   062C C0 05              1168 	push	ar5
   062E 74 42              1169 	mov	a,#__str_0
   0630 C0 E0              1170 	push	acc
   0632 74 1A              1171 	mov	a,#(__str_0 >> 8)
   0634 C0 E0              1172 	push	acc
   0636 74 80              1173 	mov	a,#0x80
   0638 C0 E0              1174 	push	acc
   063A 74 65              1175 	mov	a,#_response
   063C C0 E0              1176 	push	acc
   063E 74 F0              1177 	mov	a,#(_response >> 8)
   0640 C0 E0              1178 	push	acc
   0642 E4                 1179 	clr	a
   0643 C0 E0              1180 	push	acc
   0645 12 11 E8           1181 	lcall	_sprintf
   0648 AE 82              1182 	mov	r6,dpl
   064A E5 81              1183 	mov	a,sp
   064C 24 F6              1184 	add	a,#0xf6
   064E F5 81              1185 	mov	sp,a
   0650 78 2B              1186 	mov	r0,#_usbComTxSend_PARM_2
   0652 EE                 1187 	mov	a,r6
   0653 F2                 1188 	movx	@r0,a
                    0150   1189 	C$example_usb_com.c$191$3$9 ==.
                           1190 ;	apps/example_usb_com/example_usb_com.c:191: usbComTxSend(response, responseLength);
   0654 90 F0 65           1191 	mov	dptr,#_response
   0657 12 08 D3           1192 	lcall	_usbComTxSend
                    0156   1193 	C$example_usb_com.c$192$3$9 ==.
                           1194 ;	apps/example_usb_com/example_usb_com.c:192: break;
                    0156   1195 	C$example_usb_com.c$194$3$9 ==.
                           1196 ;	apps/example_usb_com/example_usb_com.c:194: case 'y':
   065A 80 0B              1197 	sjmp	00122$
   065C                    1198 00114$:
                    0158   1199 	C$example_usb_com.c$195$3$9 ==.
                           1200 ;	apps/example_usb_com/example_usb_com.c:195: yellowLedOn ^= 1;
   065C A2 00              1201 	mov	c,_yellowLedOn
   065E E4                 1202 	clr	a
   065F 33                 1203 	rlc	a
   0660 64 01              1204 	xrl	a,#0x01
   0662 FF                 1205 	mov	r7,a
   0663 24 FF              1206 	add	a,#0xff
   0665 92 00              1207 	mov	_yellowLedOn,c
                    0163   1208 	C$example_usb_com.c$197$1$1 ==.
                           1209 ;	apps/example_usb_com/example_usb_com.c:197: }
   0667                    1210 00122$:
                    0163   1211 	C$example_usb_com.c$199$1$1 ==.
                    0163   1212 	XG$processByte$0$0 ==.
   0667 22                 1213 	ret
                           1214 ;------------------------------------------------------------
                           1215 ;Allocation info for local variables in function 'processBytesFromUsb'
                           1216 ;------------------------------------------------------------
                    0164   1217 	G$processBytesFromUsb$0$0 ==.
                    0164   1218 	C$example_usb_com.c$203$1$1 ==.
                           1219 ;	apps/example_usb_com/example_usb_com.c:203: void processBytesFromUsb()
                           1220 ;	-----------------------------------------
                           1221 ;	 function processBytesFromUsb
                           1222 ;	-----------------------------------------
   0668                    1223 _processBytesFromUsb:
                    0164   1224 	C$example_usb_com.c$205$1$1 ==.
                           1225 ;	apps/example_usb_com/example_usb_com.c:205: uint8 bytesLeft = usbComRxAvailable();
   0668 12 07 66           1226 	lcall	_usbComRxAvailable
   066B AF 82              1227 	mov	r7,dpl
                    0169   1228 	C$example_usb_com.c$206$1$1 ==.
                           1229 ;	apps/example_usb_com/example_usb_com.c:206: while(bytesLeft && usbComTxAvailable() >= sizeof(response))
   066D                    1230 00102$:
   066D EF                 1231 	mov	a,r7
   066E 60 1B              1232 	jz	00105$
   0670 C0 07              1233 	push	ar7
   0672 12 08 9C           1234 	lcall	_usbComTxAvailable
   0675 AE 82              1235 	mov	r6,dpl
   0677 D0 07              1236 	pop	ar7
   0679 BE 20 00           1237 	cjne	r6,#0x20,00112$
   067C                    1238 00112$:
   067C 40 0D              1239 	jc	00105$
                    017A   1240 	C$example_usb_com.c$208$2$2 ==.
                           1241 ;	apps/example_usb_com/example_usb_com.c:208: processByte(usbComRxReceiveByte());
   067E C0 07              1242 	push	ar7
   0680 12 07 90           1243 	lcall	_usbComRxReceiveByte
   0683 12 05 9D           1244 	lcall	_processByte
   0686 D0 07              1245 	pop	ar7
                    0184   1246 	C$example_usb_com.c$209$2$2 ==.
                           1247 ;	apps/example_usb_com/example_usb_com.c:209: bytesLeft--;
   0688 1F                 1248 	dec	r7
   0689 80 E2              1249 	sjmp	00102$
   068B                    1250 00105$:
                    0187   1251 	C$example_usb_com.c$211$1$1 ==.
                    0187   1252 	XG$processBytesFromUsb$0$0 ==.
   068B 22                 1253 	ret
                           1254 ;------------------------------------------------------------
                           1255 ;Allocation info for local variables in function 'main'
                           1256 ;------------------------------------------------------------
                    0188   1257 	G$main$0$0 ==.
                    0188   1258 	C$example_usb_com.c$213$1$1 ==.
                           1259 ;	apps/example_usb_com/example_usb_com.c:213: void main()
                           1260 ;	-----------------------------------------
                           1261 ;	 function main
                           1262 ;	-----------------------------------------
   068C                    1263 _main:
                    0188   1264 	C$example_usb_com.c$215$1$1 ==.
                           1265 ;	apps/example_usb_com/example_usb_com.c:215: systemInit();
   068C 12 0F BF           1266 	lcall	_systemInit
                    018B   1267 	C$example_usb_com.c$216$1$1 ==.
                           1268 ;	apps/example_usb_com/example_usb_com.c:216: usbInit();
   068F 12 09 59           1269 	lcall	_usbInit
                    018E   1270 	C$example_usb_com.c$218$1$1 ==.
                           1271 ;	apps/example_usb_com/example_usb_com.c:218: while(1)
   0692                    1272 00102$:
                    018E   1273 	C$example_usb_com.c$220$2$2 ==.
                           1274 ;	apps/example_usb_com/example_usb_com.c:220: boardService();
   0692 12 0F CC           1275 	lcall	_boardService
                    0191   1276 	C$example_usb_com.c$221$2$2 ==.
                           1277 ;	apps/example_usb_com/example_usb_com.c:221: updateLeds();
   0695 12 05 04           1278 	lcall	_updateLeds
                    0194   1279 	C$example_usb_com.c$222$2$2 ==.
                           1280 ;	apps/example_usb_com/example_usb_com.c:222: usbComService();
   0698 12 07 F7           1281 	lcall	_usbComService
                    0197   1282 	C$example_usb_com.c$223$2$2 ==.
                           1283 ;	apps/example_usb_com/example_usb_com.c:223: processBytesFromUsb();
   069B 12 06 68           1284 	lcall	_processBytesFromUsb
   069E 80 F2              1285 	sjmp	00102$
                    019C   1286 	C$example_usb_com.c$225$1$1 ==.
                    019C   1287 	XG$main$0$0 ==.
   06A0 22                 1288 	ret
                           1289 	.area CSEG    (CODE)
                           1290 	.area CONST   (CODE)
                    0000   1291 Fexample_usb_com$_str_0$0$0 == .
   1A42                    1292 __str_0:
   1A42 74 69 6D 65 3D 30  1293 	.ascii "time=0x%04x%04x"
        78 25 30 34 78 25
        30 34 78
   1A51 0D                 1294 	.db 0x0D
   1A52 0A                 1295 	.db 0x0A
   1A53 00                 1296 	.db 0x00
                           1297 	.area XINIT   (CODE)
                           1298 	.area CABS    (ABS,CODE)
