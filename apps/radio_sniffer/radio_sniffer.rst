                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Aug 17 17:32:16 2012
                              5 ;--------------------------------------------------------
                              6 	.module radio_sniffer
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _printPacketIfNeeded
                             14 	.globl _printPacket
                             15 	.globl _nibbleToAscii
                             16 	.globl _updateLeds
                             17 	.globl _isprint
                             18 	.globl _printf
                             19 	.globl _radioQueueRxDoneWithPacket
                             20 	.globl _radioQueueRxCurrentPacket
                             21 	.globl _radioQueueInit
                             22 	.globl _usbComTxSendByte
                             23 	.globl _usbComTxAvailable
                             24 	.globl _usbComService
                             25 	.globl _usbShowStatusWithGreenLed
                             26 	.globl _usbInit
                             27 	.globl _boardService
                             28 	.globl _systemInit
                             29 	.globl _putchar
                             30 ;--------------------------------------------------------
                             31 ; special function registers
                             32 ;--------------------------------------------------------
                             33 	.area RSEG    (ABS,DATA)
   0000                      34 	.org 0x0000
                    0080     35 Fradio_sniffer$P0$0$0 == 0x0080
                    0080     36 _P0	=	0x0080
                    0081     37 Fradio_sniffer$SP$0$0 == 0x0081
                    0081     38 _SP	=	0x0081
                    0082     39 Fradio_sniffer$DPL0$0$0 == 0x0082
                    0082     40 _DPL0	=	0x0082
                    0083     41 Fradio_sniffer$DPH0$0$0 == 0x0083
                    0083     42 _DPH0	=	0x0083
                    0084     43 Fradio_sniffer$DPL1$0$0 == 0x0084
                    0084     44 _DPL1	=	0x0084
                    0085     45 Fradio_sniffer$DPH1$0$0 == 0x0085
                    0085     46 _DPH1	=	0x0085
                    0086     47 Fradio_sniffer$U0CSR$0$0 == 0x0086
                    0086     48 _U0CSR	=	0x0086
                    0087     49 Fradio_sniffer$PCON$0$0 == 0x0087
                    0087     50 _PCON	=	0x0087
                    0088     51 Fradio_sniffer$TCON$0$0 == 0x0088
                    0088     52 _TCON	=	0x0088
                    0089     53 Fradio_sniffer$P0IFG$0$0 == 0x0089
                    0089     54 _P0IFG	=	0x0089
                    008A     55 Fradio_sniffer$P1IFG$0$0 == 0x008a
                    008A     56 _P1IFG	=	0x008a
                    008B     57 Fradio_sniffer$P2IFG$0$0 == 0x008b
                    008B     58 _P2IFG	=	0x008b
                    008C     59 Fradio_sniffer$PICTL$0$0 == 0x008c
                    008C     60 _PICTL	=	0x008c
                    008D     61 Fradio_sniffer$P1IEN$0$0 == 0x008d
                    008D     62 _P1IEN	=	0x008d
                    008F     63 Fradio_sniffer$P0INP$0$0 == 0x008f
                    008F     64 _P0INP	=	0x008f
                    0090     65 Fradio_sniffer$P1$0$0 == 0x0090
                    0090     66 _P1	=	0x0090
                    0091     67 Fradio_sniffer$RFIM$0$0 == 0x0091
                    0091     68 _RFIM	=	0x0091
                    0092     69 Fradio_sniffer$DPS$0$0 == 0x0092
                    0092     70 _DPS	=	0x0092
                    0093     71 Fradio_sniffer$MPAGE$0$0 == 0x0093
                    0093     72 _MPAGE	=	0x0093
                    0095     73 Fradio_sniffer$ENDIAN$0$0 == 0x0095
                    0095     74 _ENDIAN	=	0x0095
                    0098     75 Fradio_sniffer$S0CON$0$0 == 0x0098
                    0098     76 _S0CON	=	0x0098
                    009A     77 Fradio_sniffer$IEN2$0$0 == 0x009a
                    009A     78 _IEN2	=	0x009a
                    009B     79 Fradio_sniffer$S1CON$0$0 == 0x009b
                    009B     80 _S1CON	=	0x009b
                    009C     81 Fradio_sniffer$T2CT$0$0 == 0x009c
                    009C     82 _T2CT	=	0x009c
                    009D     83 Fradio_sniffer$T2PR$0$0 == 0x009d
                    009D     84 _T2PR	=	0x009d
                    009E     85 Fradio_sniffer$T2CTL$0$0 == 0x009e
                    009E     86 _T2CTL	=	0x009e
                    00A0     87 Fradio_sniffer$P2$0$0 == 0x00a0
                    00A0     88 _P2	=	0x00a0
                    00A1     89 Fradio_sniffer$WORIRQ$0$0 == 0x00a1
                    00A1     90 _WORIRQ	=	0x00a1
                    00A2     91 Fradio_sniffer$WORCTRL$0$0 == 0x00a2
                    00A2     92 _WORCTRL	=	0x00a2
                    00A3     93 Fradio_sniffer$WOREVT0$0$0 == 0x00a3
                    00A3     94 _WOREVT0	=	0x00a3
                    00A4     95 Fradio_sniffer$WOREVT1$0$0 == 0x00a4
                    00A4     96 _WOREVT1	=	0x00a4
                    00A5     97 Fradio_sniffer$WORTIME0$0$0 == 0x00a5
                    00A5     98 _WORTIME0	=	0x00a5
                    00A6     99 Fradio_sniffer$WORTIME1$0$0 == 0x00a6
                    00A6    100 _WORTIME1	=	0x00a6
                    00A8    101 Fradio_sniffer$IEN0$0$0 == 0x00a8
                    00A8    102 _IEN0	=	0x00a8
                    00A9    103 Fradio_sniffer$IP0$0$0 == 0x00a9
                    00A9    104 _IP0	=	0x00a9
                    00AB    105 Fradio_sniffer$FWT$0$0 == 0x00ab
                    00AB    106 _FWT	=	0x00ab
                    00AC    107 Fradio_sniffer$FADDRL$0$0 == 0x00ac
                    00AC    108 _FADDRL	=	0x00ac
                    00AD    109 Fradio_sniffer$FADDRH$0$0 == 0x00ad
                    00AD    110 _FADDRH	=	0x00ad
                    00AE    111 Fradio_sniffer$FCTL$0$0 == 0x00ae
                    00AE    112 _FCTL	=	0x00ae
                    00AF    113 Fradio_sniffer$FWDATA$0$0 == 0x00af
                    00AF    114 _FWDATA	=	0x00af
                    00B1    115 Fradio_sniffer$ENCDI$0$0 == 0x00b1
                    00B1    116 _ENCDI	=	0x00b1
                    00B2    117 Fradio_sniffer$ENCDO$0$0 == 0x00b2
                    00B2    118 _ENCDO	=	0x00b2
                    00B3    119 Fradio_sniffer$ENCCS$0$0 == 0x00b3
                    00B3    120 _ENCCS	=	0x00b3
                    00B4    121 Fradio_sniffer$ADCCON1$0$0 == 0x00b4
                    00B4    122 _ADCCON1	=	0x00b4
                    00B5    123 Fradio_sniffer$ADCCON2$0$0 == 0x00b5
                    00B5    124 _ADCCON2	=	0x00b5
                    00B6    125 Fradio_sniffer$ADCCON3$0$0 == 0x00b6
                    00B6    126 _ADCCON3	=	0x00b6
                    00B8    127 Fradio_sniffer$IEN1$0$0 == 0x00b8
                    00B8    128 _IEN1	=	0x00b8
                    00B9    129 Fradio_sniffer$IP1$0$0 == 0x00b9
                    00B9    130 _IP1	=	0x00b9
                    00BA    131 Fradio_sniffer$ADCL$0$0 == 0x00ba
                    00BA    132 _ADCL	=	0x00ba
                    00BB    133 Fradio_sniffer$ADCH$0$0 == 0x00bb
                    00BB    134 _ADCH	=	0x00bb
                    00BC    135 Fradio_sniffer$RNDL$0$0 == 0x00bc
                    00BC    136 _RNDL	=	0x00bc
                    00BD    137 Fradio_sniffer$RNDH$0$0 == 0x00bd
                    00BD    138 _RNDH	=	0x00bd
                    00BE    139 Fradio_sniffer$SLEEP$0$0 == 0x00be
                    00BE    140 _SLEEP	=	0x00be
                    00C0    141 Fradio_sniffer$IRCON$0$0 == 0x00c0
                    00C0    142 _IRCON	=	0x00c0
                    00C1    143 Fradio_sniffer$U0DBUF$0$0 == 0x00c1
                    00C1    144 _U0DBUF	=	0x00c1
                    00C2    145 Fradio_sniffer$U0BAUD$0$0 == 0x00c2
                    00C2    146 _U0BAUD	=	0x00c2
                    00C4    147 Fradio_sniffer$U0UCR$0$0 == 0x00c4
                    00C4    148 _U0UCR	=	0x00c4
                    00C5    149 Fradio_sniffer$U0GCR$0$0 == 0x00c5
                    00C5    150 _U0GCR	=	0x00c5
                    00C6    151 Fradio_sniffer$CLKCON$0$0 == 0x00c6
                    00C6    152 _CLKCON	=	0x00c6
                    00C7    153 Fradio_sniffer$MEMCTR$0$0 == 0x00c7
                    00C7    154 _MEMCTR	=	0x00c7
                    00C9    155 Fradio_sniffer$WDCTL$0$0 == 0x00c9
                    00C9    156 _WDCTL	=	0x00c9
                    00CA    157 Fradio_sniffer$T3CNT$0$0 == 0x00ca
                    00CA    158 _T3CNT	=	0x00ca
                    00CB    159 Fradio_sniffer$T3CTL$0$0 == 0x00cb
                    00CB    160 _T3CTL	=	0x00cb
                    00CC    161 Fradio_sniffer$T3CCTL0$0$0 == 0x00cc
                    00CC    162 _T3CCTL0	=	0x00cc
                    00CD    163 Fradio_sniffer$T3CC0$0$0 == 0x00cd
                    00CD    164 _T3CC0	=	0x00cd
                    00CE    165 Fradio_sniffer$T3CCTL1$0$0 == 0x00ce
                    00CE    166 _T3CCTL1	=	0x00ce
                    00CF    167 Fradio_sniffer$T3CC1$0$0 == 0x00cf
                    00CF    168 _T3CC1	=	0x00cf
                    00D0    169 Fradio_sniffer$PSW$0$0 == 0x00d0
                    00D0    170 _PSW	=	0x00d0
                    00D1    171 Fradio_sniffer$DMAIRQ$0$0 == 0x00d1
                    00D1    172 _DMAIRQ	=	0x00d1
                    00D2    173 Fradio_sniffer$DMA1CFGL$0$0 == 0x00d2
                    00D2    174 _DMA1CFGL	=	0x00d2
                    00D3    175 Fradio_sniffer$DMA1CFGH$0$0 == 0x00d3
                    00D3    176 _DMA1CFGH	=	0x00d3
                    00D4    177 Fradio_sniffer$DMA0CFGL$0$0 == 0x00d4
                    00D4    178 _DMA0CFGL	=	0x00d4
                    00D5    179 Fradio_sniffer$DMA0CFGH$0$0 == 0x00d5
                    00D5    180 _DMA0CFGH	=	0x00d5
                    00D6    181 Fradio_sniffer$DMAARM$0$0 == 0x00d6
                    00D6    182 _DMAARM	=	0x00d6
                    00D7    183 Fradio_sniffer$DMAREQ$0$0 == 0x00d7
                    00D7    184 _DMAREQ	=	0x00d7
                    00D8    185 Fradio_sniffer$TIMIF$0$0 == 0x00d8
                    00D8    186 _TIMIF	=	0x00d8
                    00D9    187 Fradio_sniffer$RFD$0$0 == 0x00d9
                    00D9    188 _RFD	=	0x00d9
                    00DA    189 Fradio_sniffer$T1CC0L$0$0 == 0x00da
                    00DA    190 _T1CC0L	=	0x00da
                    00DB    191 Fradio_sniffer$T1CC0H$0$0 == 0x00db
                    00DB    192 _T1CC0H	=	0x00db
                    00DC    193 Fradio_sniffer$T1CC1L$0$0 == 0x00dc
                    00DC    194 _T1CC1L	=	0x00dc
                    00DD    195 Fradio_sniffer$T1CC1H$0$0 == 0x00dd
                    00DD    196 _T1CC1H	=	0x00dd
                    00DE    197 Fradio_sniffer$T1CC2L$0$0 == 0x00de
                    00DE    198 _T1CC2L	=	0x00de
                    00DF    199 Fradio_sniffer$T1CC2H$0$0 == 0x00df
                    00DF    200 _T1CC2H	=	0x00df
                    00E0    201 Fradio_sniffer$ACC$0$0 == 0x00e0
                    00E0    202 _ACC	=	0x00e0
                    00E1    203 Fradio_sniffer$RFST$0$0 == 0x00e1
                    00E1    204 _RFST	=	0x00e1
                    00E2    205 Fradio_sniffer$T1CNTL$0$0 == 0x00e2
                    00E2    206 _T1CNTL	=	0x00e2
                    00E3    207 Fradio_sniffer$T1CNTH$0$0 == 0x00e3
                    00E3    208 _T1CNTH	=	0x00e3
                    00E4    209 Fradio_sniffer$T1CTL$0$0 == 0x00e4
                    00E4    210 _T1CTL	=	0x00e4
                    00E5    211 Fradio_sniffer$T1CCTL0$0$0 == 0x00e5
                    00E5    212 _T1CCTL0	=	0x00e5
                    00E6    213 Fradio_sniffer$T1CCTL1$0$0 == 0x00e6
                    00E6    214 _T1CCTL1	=	0x00e6
                    00E7    215 Fradio_sniffer$T1CCTL2$0$0 == 0x00e7
                    00E7    216 _T1CCTL2	=	0x00e7
                    00E8    217 Fradio_sniffer$IRCON2$0$0 == 0x00e8
                    00E8    218 _IRCON2	=	0x00e8
                    00E9    219 Fradio_sniffer$RFIF$0$0 == 0x00e9
                    00E9    220 _RFIF	=	0x00e9
                    00EA    221 Fradio_sniffer$T4CNT$0$0 == 0x00ea
                    00EA    222 _T4CNT	=	0x00ea
                    00EB    223 Fradio_sniffer$T4CTL$0$0 == 0x00eb
                    00EB    224 _T4CTL	=	0x00eb
                    00EC    225 Fradio_sniffer$T4CCTL0$0$0 == 0x00ec
                    00EC    226 _T4CCTL0	=	0x00ec
                    00ED    227 Fradio_sniffer$T4CC0$0$0 == 0x00ed
                    00ED    228 _T4CC0	=	0x00ed
                    00EE    229 Fradio_sniffer$T4CCTL1$0$0 == 0x00ee
                    00EE    230 _T4CCTL1	=	0x00ee
                    00EF    231 Fradio_sniffer$T4CC1$0$0 == 0x00ef
                    00EF    232 _T4CC1	=	0x00ef
                    00F0    233 Fradio_sniffer$B$0$0 == 0x00f0
                    00F0    234 _B	=	0x00f0
                    00F1    235 Fradio_sniffer$PERCFG$0$0 == 0x00f1
                    00F1    236 _PERCFG	=	0x00f1
                    00F2    237 Fradio_sniffer$ADCCFG$0$0 == 0x00f2
                    00F2    238 _ADCCFG	=	0x00f2
                    00F3    239 Fradio_sniffer$P0SEL$0$0 == 0x00f3
                    00F3    240 _P0SEL	=	0x00f3
                    00F4    241 Fradio_sniffer$P1SEL$0$0 == 0x00f4
                    00F4    242 _P1SEL	=	0x00f4
                    00F5    243 Fradio_sniffer$P2SEL$0$0 == 0x00f5
                    00F5    244 _P2SEL	=	0x00f5
                    00F6    245 Fradio_sniffer$P1INP$0$0 == 0x00f6
                    00F6    246 _P1INP	=	0x00f6
                    00F7    247 Fradio_sniffer$P2INP$0$0 == 0x00f7
                    00F7    248 _P2INP	=	0x00f7
                    00F8    249 Fradio_sniffer$U1CSR$0$0 == 0x00f8
                    00F8    250 _U1CSR	=	0x00f8
                    00F9    251 Fradio_sniffer$U1DBUF$0$0 == 0x00f9
                    00F9    252 _U1DBUF	=	0x00f9
                    00FA    253 Fradio_sniffer$U1BAUD$0$0 == 0x00fa
                    00FA    254 _U1BAUD	=	0x00fa
                    00FB    255 Fradio_sniffer$U1UCR$0$0 == 0x00fb
                    00FB    256 _U1UCR	=	0x00fb
                    00FC    257 Fradio_sniffer$U1GCR$0$0 == 0x00fc
                    00FC    258 _U1GCR	=	0x00fc
                    00FD    259 Fradio_sniffer$P0DIR$0$0 == 0x00fd
                    00FD    260 _P0DIR	=	0x00fd
                    00FE    261 Fradio_sniffer$P1DIR$0$0 == 0x00fe
                    00FE    262 _P1DIR	=	0x00fe
                    00FF    263 Fradio_sniffer$P2DIR$0$0 == 0x00ff
                    00FF    264 _P2DIR	=	0x00ff
                    FFFFD5D4    265 Fradio_sniffer$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    266 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    267 Fradio_sniffer$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    268 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    269 Fradio_sniffer$FADDR$0$0 == 0xffffadac
                    FFFFADAC    270 _FADDR	=	0xffffadac
                    FFFFBBBA    271 Fradio_sniffer$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    272 _ADC	=	0xffffbbba
                    FFFFDBDA    273 Fradio_sniffer$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    274 _T1CC0	=	0xffffdbda
                    FFFFDDDC    275 Fradio_sniffer$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    276 _T1CC1	=	0xffffdddc
                    FFFFDFDE    277 Fradio_sniffer$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    278 _T1CC2	=	0xffffdfde
                            279 ;--------------------------------------------------------
                            280 ; special function bits
                            281 ;--------------------------------------------------------
                            282 	.area RSEG    (ABS,DATA)
   0000                     283 	.org 0x0000
                    0080    284 Fradio_sniffer$P0_0$0$0 == 0x0080
                    0080    285 _P0_0	=	0x0080
                    0081    286 Fradio_sniffer$P0_1$0$0 == 0x0081
                    0081    287 _P0_1	=	0x0081
                    0082    288 Fradio_sniffer$P0_2$0$0 == 0x0082
                    0082    289 _P0_2	=	0x0082
                    0083    290 Fradio_sniffer$P0_3$0$0 == 0x0083
                    0083    291 _P0_3	=	0x0083
                    0084    292 Fradio_sniffer$P0_4$0$0 == 0x0084
                    0084    293 _P0_4	=	0x0084
                    0085    294 Fradio_sniffer$P0_5$0$0 == 0x0085
                    0085    295 _P0_5	=	0x0085
                    0086    296 Fradio_sniffer$P0_6$0$0 == 0x0086
                    0086    297 _P0_6	=	0x0086
                    0087    298 Fradio_sniffer$P0_7$0$0 == 0x0087
                    0087    299 _P0_7	=	0x0087
                    0088    300 Fradio_sniffer$_TCON_0$0$0 == 0x0088
                    0088    301 __TCON_0	=	0x0088
                    0089    302 Fradio_sniffer$RFTXRXIF$0$0 == 0x0089
                    0089    303 _RFTXRXIF	=	0x0089
                    008A    304 Fradio_sniffer$_TCON_2$0$0 == 0x008a
                    008A    305 __TCON_2	=	0x008a
                    008B    306 Fradio_sniffer$URX0IF$0$0 == 0x008b
                    008B    307 _URX0IF	=	0x008b
                    008C    308 Fradio_sniffer$_TCON_4$0$0 == 0x008c
                    008C    309 __TCON_4	=	0x008c
                    008D    310 Fradio_sniffer$ADCIF$0$0 == 0x008d
                    008D    311 _ADCIF	=	0x008d
                    008E    312 Fradio_sniffer$_TCON_6$0$0 == 0x008e
                    008E    313 __TCON_6	=	0x008e
                    008F    314 Fradio_sniffer$URX1IF$0$0 == 0x008f
                    008F    315 _URX1IF	=	0x008f
                    0090    316 Fradio_sniffer$P1_0$0$0 == 0x0090
                    0090    317 _P1_0	=	0x0090
                    0091    318 Fradio_sniffer$P1_1$0$0 == 0x0091
                    0091    319 _P1_1	=	0x0091
                    0092    320 Fradio_sniffer$P1_2$0$0 == 0x0092
                    0092    321 _P1_2	=	0x0092
                    0093    322 Fradio_sniffer$P1_3$0$0 == 0x0093
                    0093    323 _P1_3	=	0x0093
                    0094    324 Fradio_sniffer$P1_4$0$0 == 0x0094
                    0094    325 _P1_4	=	0x0094
                    0095    326 Fradio_sniffer$P1_5$0$0 == 0x0095
                    0095    327 _P1_5	=	0x0095
                    0096    328 Fradio_sniffer$P1_6$0$0 == 0x0096
                    0096    329 _P1_6	=	0x0096
                    0097    330 Fradio_sniffer$P1_7$0$0 == 0x0097
                    0097    331 _P1_7	=	0x0097
                    0098    332 Fradio_sniffer$ENCIF_0$0$0 == 0x0098
                    0098    333 _ENCIF_0	=	0x0098
                    0099    334 Fradio_sniffer$ENCIF_1$0$0 == 0x0099
                    0099    335 _ENCIF_1	=	0x0099
                    009A    336 Fradio_sniffer$_SOCON2$0$0 == 0x009a
                    009A    337 __SOCON2	=	0x009a
                    009B    338 Fradio_sniffer$_SOCON3$0$0 == 0x009b
                    009B    339 __SOCON3	=	0x009b
                    009C    340 Fradio_sniffer$_SOCON4$0$0 == 0x009c
                    009C    341 __SOCON4	=	0x009c
                    009D    342 Fradio_sniffer$_SOCON5$0$0 == 0x009d
                    009D    343 __SOCON5	=	0x009d
                    009E    344 Fradio_sniffer$_SOCON6$0$0 == 0x009e
                    009E    345 __SOCON6	=	0x009e
                    009F    346 Fradio_sniffer$_SOCON7$0$0 == 0x009f
                    009F    347 __SOCON7	=	0x009f
                    00A0    348 Fradio_sniffer$P2_0$0$0 == 0x00a0
                    00A0    349 _P2_0	=	0x00a0
                    00A1    350 Fradio_sniffer$P2_1$0$0 == 0x00a1
                    00A1    351 _P2_1	=	0x00a1
                    00A2    352 Fradio_sniffer$P2_2$0$0 == 0x00a2
                    00A2    353 _P2_2	=	0x00a2
                    00A3    354 Fradio_sniffer$P2_3$0$0 == 0x00a3
                    00A3    355 _P2_3	=	0x00a3
                    00A4    356 Fradio_sniffer$P2_4$0$0 == 0x00a4
                    00A4    357 _P2_4	=	0x00a4
                    00A5    358 Fradio_sniffer$P2_5$0$0 == 0x00a5
                    00A5    359 _P2_5	=	0x00a5
                    00A6    360 Fradio_sniffer$P2_6$0$0 == 0x00a6
                    00A6    361 _P2_6	=	0x00a6
                    00A7    362 Fradio_sniffer$P2_7$0$0 == 0x00a7
                    00A7    363 _P2_7	=	0x00a7
                    00A8    364 Fradio_sniffer$RFTXRXIE$0$0 == 0x00a8
                    00A8    365 _RFTXRXIE	=	0x00a8
                    00A9    366 Fradio_sniffer$ADCIE$0$0 == 0x00a9
                    00A9    367 _ADCIE	=	0x00a9
                    00AA    368 Fradio_sniffer$URX0IE$0$0 == 0x00aa
                    00AA    369 _URX0IE	=	0x00aa
                    00AB    370 Fradio_sniffer$URX1IE$0$0 == 0x00ab
                    00AB    371 _URX1IE	=	0x00ab
                    00AC    372 Fradio_sniffer$ENCIE$0$0 == 0x00ac
                    00AC    373 _ENCIE	=	0x00ac
                    00AD    374 Fradio_sniffer$STIE$0$0 == 0x00ad
                    00AD    375 _STIE	=	0x00ad
                    00AE    376 Fradio_sniffer$_IEN06$0$0 == 0x00ae
                    00AE    377 __IEN06	=	0x00ae
                    00AF    378 Fradio_sniffer$EA$0$0 == 0x00af
                    00AF    379 _EA	=	0x00af
                    00B8    380 Fradio_sniffer$DMAIE$0$0 == 0x00b8
                    00B8    381 _DMAIE	=	0x00b8
                    00B9    382 Fradio_sniffer$T1IE$0$0 == 0x00b9
                    00B9    383 _T1IE	=	0x00b9
                    00BA    384 Fradio_sniffer$T2IE$0$0 == 0x00ba
                    00BA    385 _T2IE	=	0x00ba
                    00BB    386 Fradio_sniffer$T3IE$0$0 == 0x00bb
                    00BB    387 _T3IE	=	0x00bb
                    00BC    388 Fradio_sniffer$T4IE$0$0 == 0x00bc
                    00BC    389 _T4IE	=	0x00bc
                    00BD    390 Fradio_sniffer$P0IE$0$0 == 0x00bd
                    00BD    391 _P0IE	=	0x00bd
                    00BE    392 Fradio_sniffer$_IEN16$0$0 == 0x00be
                    00BE    393 __IEN16	=	0x00be
                    00BF    394 Fradio_sniffer$_IEN17$0$0 == 0x00bf
                    00BF    395 __IEN17	=	0x00bf
                    00C0    396 Fradio_sniffer$DMAIF$0$0 == 0x00c0
                    00C0    397 _DMAIF	=	0x00c0
                    00C1    398 Fradio_sniffer$T1IF$0$0 == 0x00c1
                    00C1    399 _T1IF	=	0x00c1
                    00C2    400 Fradio_sniffer$T2IF$0$0 == 0x00c2
                    00C2    401 _T2IF	=	0x00c2
                    00C3    402 Fradio_sniffer$T3IF$0$0 == 0x00c3
                    00C3    403 _T3IF	=	0x00c3
                    00C4    404 Fradio_sniffer$T4IF$0$0 == 0x00c4
                    00C4    405 _T4IF	=	0x00c4
                    00C5    406 Fradio_sniffer$P0IF$0$0 == 0x00c5
                    00C5    407 _P0IF	=	0x00c5
                    00C6    408 Fradio_sniffer$_IRCON6$0$0 == 0x00c6
                    00C6    409 __IRCON6	=	0x00c6
                    00C7    410 Fradio_sniffer$STIF$0$0 == 0x00c7
                    00C7    411 _STIF	=	0x00c7
                    00D0    412 Fradio_sniffer$P$0$0 == 0x00d0
                    00D0    413 _P	=	0x00d0
                    00D1    414 Fradio_sniffer$F1$0$0 == 0x00d1
                    00D1    415 _F1	=	0x00d1
                    00D2    416 Fradio_sniffer$OV$0$0 == 0x00d2
                    00D2    417 _OV	=	0x00d2
                    00D3    418 Fradio_sniffer$RS0$0$0 == 0x00d3
                    00D3    419 _RS0	=	0x00d3
                    00D4    420 Fradio_sniffer$RS1$0$0 == 0x00d4
                    00D4    421 _RS1	=	0x00d4
                    00D5    422 Fradio_sniffer$F0$0$0 == 0x00d5
                    00D5    423 _F0	=	0x00d5
                    00D6    424 Fradio_sniffer$AC$0$0 == 0x00d6
                    00D6    425 _AC	=	0x00d6
                    00D7    426 Fradio_sniffer$CY$0$0 == 0x00d7
                    00D7    427 _CY	=	0x00d7
                    00D8    428 Fradio_sniffer$T3OVFIF$0$0 == 0x00d8
                    00D8    429 _T3OVFIF	=	0x00d8
                    00D9    430 Fradio_sniffer$T3CH0IF$0$0 == 0x00d9
                    00D9    431 _T3CH0IF	=	0x00d9
                    00DA    432 Fradio_sniffer$T3CH1IF$0$0 == 0x00da
                    00DA    433 _T3CH1IF	=	0x00da
                    00DB    434 Fradio_sniffer$T4OVFIF$0$0 == 0x00db
                    00DB    435 _T4OVFIF	=	0x00db
                    00DC    436 Fradio_sniffer$T4CH0IF$0$0 == 0x00dc
                    00DC    437 _T4CH0IF	=	0x00dc
                    00DD    438 Fradio_sniffer$T4CH1IF$0$0 == 0x00dd
                    00DD    439 _T4CH1IF	=	0x00dd
                    00DE    440 Fradio_sniffer$OVFIM$0$0 == 0x00de
                    00DE    441 _OVFIM	=	0x00de
                    00DF    442 Fradio_sniffer$_TIMIF7$0$0 == 0x00df
                    00DF    443 __TIMIF7	=	0x00df
                    00E0    444 Fradio_sniffer$ACC_0$0$0 == 0x00e0
                    00E0    445 _ACC_0	=	0x00e0
                    00E1    446 Fradio_sniffer$ACC_1$0$0 == 0x00e1
                    00E1    447 _ACC_1	=	0x00e1
                    00E2    448 Fradio_sniffer$ACC_2$0$0 == 0x00e2
                    00E2    449 _ACC_2	=	0x00e2
                    00E3    450 Fradio_sniffer$ACC_3$0$0 == 0x00e3
                    00E3    451 _ACC_3	=	0x00e3
                    00E4    452 Fradio_sniffer$ACC_4$0$0 == 0x00e4
                    00E4    453 _ACC_4	=	0x00e4
                    00E5    454 Fradio_sniffer$ACC_5$0$0 == 0x00e5
                    00E5    455 _ACC_5	=	0x00e5
                    00E6    456 Fradio_sniffer$ACC_6$0$0 == 0x00e6
                    00E6    457 _ACC_6	=	0x00e6
                    00E7    458 Fradio_sniffer$ACC_7$0$0 == 0x00e7
                    00E7    459 _ACC_7	=	0x00e7
                    00E8    460 Fradio_sniffer$P2IF$0$0 == 0x00e8
                    00E8    461 _P2IF	=	0x00e8
                    00E9    462 Fradio_sniffer$UTX0IF$0$0 == 0x00e9
                    00E9    463 _UTX0IF	=	0x00e9
                    00EA    464 Fradio_sniffer$UTX1IF$0$0 == 0x00ea
                    00EA    465 _UTX1IF	=	0x00ea
                    00EB    466 Fradio_sniffer$P1IF$0$0 == 0x00eb
                    00EB    467 _P1IF	=	0x00eb
                    00EC    468 Fradio_sniffer$WDTIF$0$0 == 0x00ec
                    00EC    469 _WDTIF	=	0x00ec
                    00ED    470 Fradio_sniffer$_IRCON25$0$0 == 0x00ed
                    00ED    471 __IRCON25	=	0x00ed
                    00EE    472 Fradio_sniffer$_IRCON26$0$0 == 0x00ee
                    00EE    473 __IRCON26	=	0x00ee
                    00EF    474 Fradio_sniffer$_IRCON27$0$0 == 0x00ef
                    00EF    475 __IRCON27	=	0x00ef
                    00F0    476 Fradio_sniffer$B_0$0$0 == 0x00f0
                    00F0    477 _B_0	=	0x00f0
                    00F1    478 Fradio_sniffer$B_1$0$0 == 0x00f1
                    00F1    479 _B_1	=	0x00f1
                    00F2    480 Fradio_sniffer$B_2$0$0 == 0x00f2
                    00F2    481 _B_2	=	0x00f2
                    00F3    482 Fradio_sniffer$B_3$0$0 == 0x00f3
                    00F3    483 _B_3	=	0x00f3
                    00F4    484 Fradio_sniffer$B_4$0$0 == 0x00f4
                    00F4    485 _B_4	=	0x00f4
                    00F5    486 Fradio_sniffer$B_5$0$0 == 0x00f5
                    00F5    487 _B_5	=	0x00f5
                    00F6    488 Fradio_sniffer$B_6$0$0 == 0x00f6
                    00F6    489 _B_6	=	0x00f6
                    00F7    490 Fradio_sniffer$B_7$0$0 == 0x00f7
                    00F7    491 _B_7	=	0x00f7
                    00F8    492 Fradio_sniffer$U1ACTIVE$0$0 == 0x00f8
                    00F8    493 _U1ACTIVE	=	0x00f8
                    00F9    494 Fradio_sniffer$U1TX_BYTE$0$0 == 0x00f9
                    00F9    495 _U1TX_BYTE	=	0x00f9
                    00FA    496 Fradio_sniffer$U1RX_BYTE$0$0 == 0x00fa
                    00FA    497 _U1RX_BYTE	=	0x00fa
                    00FB    498 Fradio_sniffer$U1ERR$0$0 == 0x00fb
                    00FB    499 _U1ERR	=	0x00fb
                    00FC    500 Fradio_sniffer$U1FE$0$0 == 0x00fc
                    00FC    501 _U1FE	=	0x00fc
                    00FD    502 Fradio_sniffer$U1SLAVE$0$0 == 0x00fd
                    00FD    503 _U1SLAVE	=	0x00fd
                    00FE    504 Fradio_sniffer$U1RE$0$0 == 0x00fe
                    00FE    505 _U1RE	=	0x00fe
                    00FF    506 Fradio_sniffer$U1MODE$0$0 == 0x00ff
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
                    0000    517 Lradio_sniffer.printPacket$sloc0$1$0==.
   0008                     518 _printPacket_sloc0_1_0:
   0008                     519 	.ds 1
                            520 ;--------------------------------------------------------
                            521 ; overlayable items in internal ram 
                            522 ;--------------------------------------------------------
                            523 	.area OSEG    (OVR,DATA)
                            524 ;--------------------------------------------------------
                            525 ; Stack segment in internal ram 
                            526 ;--------------------------------------------------------
                            527 	.area	SSEG	(DATA)
   0024                     528 __start__stack:
   0024                     529 	.ds	1
                            530 
                            531 ;--------------------------------------------------------
                            532 ; indirectly addressable internal ram data
                            533 ;--------------------------------------------------------
                            534 	.area ISEG    (DATA)
                            535 ;--------------------------------------------------------
                            536 ; absolute internal ram data
                            537 ;--------------------------------------------------------
                            538 	.area IABS    (ABS,DATA)
                            539 	.area IABS    (ABS,DATA)
                            540 ;--------------------------------------------------------
                            541 ; bit data
                            542 ;--------------------------------------------------------
                            543 	.area BSEG    (BIT)
                            544 ;--------------------------------------------------------
                            545 ; paged external ram data
                            546 ;--------------------------------------------------------
                            547 	.area PSEG    (PAG,XDATA)
                    0000    548 Lradio_sniffer.printPacket$pkt_count$1$1==.
   F000                     549 _printPacket_pkt_count_1_1:
   F000                     550 	.ds 2
                            551 ;--------------------------------------------------------
                            552 ; external ram data
                            553 ;--------------------------------------------------------
                            554 	.area XSEG    (XDATA)
                    DF00    555 Fradio_sniffer$SYNC1$0$0 == 0xdf00
                    DF00    556 _SYNC1	=	0xdf00
                    DF01    557 Fradio_sniffer$SYNC0$0$0 == 0xdf01
                    DF01    558 _SYNC0	=	0xdf01
                    DF02    559 Fradio_sniffer$PKTLEN$0$0 == 0xdf02
                    DF02    560 _PKTLEN	=	0xdf02
                    DF03    561 Fradio_sniffer$PKTCTRL1$0$0 == 0xdf03
                    DF03    562 _PKTCTRL1	=	0xdf03
                    DF04    563 Fradio_sniffer$PKTCTRL0$0$0 == 0xdf04
                    DF04    564 _PKTCTRL0	=	0xdf04
                    DF05    565 Fradio_sniffer$ADDR$0$0 == 0xdf05
                    DF05    566 _ADDR	=	0xdf05
                    DF06    567 Fradio_sniffer$CHANNR$0$0 == 0xdf06
                    DF06    568 _CHANNR	=	0xdf06
                    DF07    569 Fradio_sniffer$FSCTRL1$0$0 == 0xdf07
                    DF07    570 _FSCTRL1	=	0xdf07
                    DF08    571 Fradio_sniffer$FSCTRL0$0$0 == 0xdf08
                    DF08    572 _FSCTRL0	=	0xdf08
                    DF09    573 Fradio_sniffer$FREQ2$0$0 == 0xdf09
                    DF09    574 _FREQ2	=	0xdf09
                    DF0A    575 Fradio_sniffer$FREQ1$0$0 == 0xdf0a
                    DF0A    576 _FREQ1	=	0xdf0a
                    DF0B    577 Fradio_sniffer$FREQ0$0$0 == 0xdf0b
                    DF0B    578 _FREQ0	=	0xdf0b
                    DF0C    579 Fradio_sniffer$MDMCFG4$0$0 == 0xdf0c
                    DF0C    580 _MDMCFG4	=	0xdf0c
                    DF0D    581 Fradio_sniffer$MDMCFG3$0$0 == 0xdf0d
                    DF0D    582 _MDMCFG3	=	0xdf0d
                    DF0E    583 Fradio_sniffer$MDMCFG2$0$0 == 0xdf0e
                    DF0E    584 _MDMCFG2	=	0xdf0e
                    DF0F    585 Fradio_sniffer$MDMCFG1$0$0 == 0xdf0f
                    DF0F    586 _MDMCFG1	=	0xdf0f
                    DF10    587 Fradio_sniffer$MDMCFG0$0$0 == 0xdf10
                    DF10    588 _MDMCFG0	=	0xdf10
                    DF11    589 Fradio_sniffer$DEVIATN$0$0 == 0xdf11
                    DF11    590 _DEVIATN	=	0xdf11
                    DF12    591 Fradio_sniffer$MCSM2$0$0 == 0xdf12
                    DF12    592 _MCSM2	=	0xdf12
                    DF13    593 Fradio_sniffer$MCSM1$0$0 == 0xdf13
                    DF13    594 _MCSM1	=	0xdf13
                    DF14    595 Fradio_sniffer$MCSM0$0$0 == 0xdf14
                    DF14    596 _MCSM0	=	0xdf14
                    DF15    597 Fradio_sniffer$FOCCFG$0$0 == 0xdf15
                    DF15    598 _FOCCFG	=	0xdf15
                    DF16    599 Fradio_sniffer$BSCFG$0$0 == 0xdf16
                    DF16    600 _BSCFG	=	0xdf16
                    DF17    601 Fradio_sniffer$AGCCTRL2$0$0 == 0xdf17
                    DF17    602 _AGCCTRL2	=	0xdf17
                    DF18    603 Fradio_sniffer$AGCCTRL1$0$0 == 0xdf18
                    DF18    604 _AGCCTRL1	=	0xdf18
                    DF19    605 Fradio_sniffer$AGCCTRL0$0$0 == 0xdf19
                    DF19    606 _AGCCTRL0	=	0xdf19
                    DF1A    607 Fradio_sniffer$FREND1$0$0 == 0xdf1a
                    DF1A    608 _FREND1	=	0xdf1a
                    DF1B    609 Fradio_sniffer$FREND0$0$0 == 0xdf1b
                    DF1B    610 _FREND0	=	0xdf1b
                    DF1C    611 Fradio_sniffer$FSCAL3$0$0 == 0xdf1c
                    DF1C    612 _FSCAL3	=	0xdf1c
                    DF1D    613 Fradio_sniffer$FSCAL2$0$0 == 0xdf1d
                    DF1D    614 _FSCAL2	=	0xdf1d
                    DF1E    615 Fradio_sniffer$FSCAL1$0$0 == 0xdf1e
                    DF1E    616 _FSCAL1	=	0xdf1e
                    DF1F    617 Fradio_sniffer$FSCAL0$0$0 == 0xdf1f
                    DF1F    618 _FSCAL0	=	0xdf1f
                    DF23    619 Fradio_sniffer$TEST2$0$0 == 0xdf23
                    DF23    620 _TEST2	=	0xdf23
                    DF24    621 Fradio_sniffer$TEST1$0$0 == 0xdf24
                    DF24    622 _TEST1	=	0xdf24
                    DF25    623 Fradio_sniffer$TEST0$0$0 == 0xdf25
                    DF25    624 _TEST0	=	0xdf25
                    DF2E    625 Fradio_sniffer$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    626 _PA_TABLE0	=	0xdf2e
                    DF2F    627 Fradio_sniffer$IOCFG2$0$0 == 0xdf2f
                    DF2F    628 _IOCFG2	=	0xdf2f
                    DF30    629 Fradio_sniffer$IOCFG1$0$0 == 0xdf30
                    DF30    630 _IOCFG1	=	0xdf30
                    DF31    631 Fradio_sniffer$IOCFG0$0$0 == 0xdf31
                    DF31    632 _IOCFG0	=	0xdf31
                    DF36    633 Fradio_sniffer$PARTNUM$0$0 == 0xdf36
                    DF36    634 _PARTNUM	=	0xdf36
                    DF37    635 Fradio_sniffer$VERSION$0$0 == 0xdf37
                    DF37    636 _VERSION	=	0xdf37
                    DF38    637 Fradio_sniffer$FREQEST$0$0 == 0xdf38
                    DF38    638 _FREQEST	=	0xdf38
                    DF39    639 Fradio_sniffer$LQI$0$0 == 0xdf39
                    DF39    640 _LQI	=	0xdf39
                    DF3A    641 Fradio_sniffer$RSSI$0$0 == 0xdf3a
                    DF3A    642 _RSSI	=	0xdf3a
                    DF3B    643 Fradio_sniffer$MARCSTATE$0$0 == 0xdf3b
                    DF3B    644 _MARCSTATE	=	0xdf3b
                    DF3C    645 Fradio_sniffer$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    646 _PKTSTATUS	=	0xdf3c
                    DF3D    647 Fradio_sniffer$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    648 _VCO_VC_DAC	=	0xdf3d
                    DF40    649 Fradio_sniffer$I2SCFG0$0$0 == 0xdf40
                    DF40    650 _I2SCFG0	=	0xdf40
                    DF41    651 Fradio_sniffer$I2SCFG1$0$0 == 0xdf41
                    DF41    652 _I2SCFG1	=	0xdf41
                    DF42    653 Fradio_sniffer$I2SDATL$0$0 == 0xdf42
                    DF42    654 _I2SDATL	=	0xdf42
                    DF43    655 Fradio_sniffer$I2SDATH$0$0 == 0xdf43
                    DF43    656 _I2SDATH	=	0xdf43
                    DF44    657 Fradio_sniffer$I2SWCNT$0$0 == 0xdf44
                    DF44    658 _I2SWCNT	=	0xdf44
                    DF45    659 Fradio_sniffer$I2SSTAT$0$0 == 0xdf45
                    DF45    660 _I2SSTAT	=	0xdf45
                    DF46    661 Fradio_sniffer$I2SCLKF0$0$0 == 0xdf46
                    DF46    662 _I2SCLKF0	=	0xdf46
                    DF47    663 Fradio_sniffer$I2SCLKF1$0$0 == 0xdf47
                    DF47    664 _I2SCLKF1	=	0xdf47
                    DF48    665 Fradio_sniffer$I2SCLKF2$0$0 == 0xdf48
                    DF48    666 _I2SCLKF2	=	0xdf48
                    DE00    667 Fradio_sniffer$USBADDR$0$0 == 0xde00
                    DE00    668 _USBADDR	=	0xde00
                    DE01    669 Fradio_sniffer$USBPOW$0$0 == 0xde01
                    DE01    670 _USBPOW	=	0xde01
                    DE02    671 Fradio_sniffer$USBIIF$0$0 == 0xde02
                    DE02    672 _USBIIF	=	0xde02
                    DE04    673 Fradio_sniffer$USBOIF$0$0 == 0xde04
                    DE04    674 _USBOIF	=	0xde04
                    DE06    675 Fradio_sniffer$USBCIF$0$0 == 0xde06
                    DE06    676 _USBCIF	=	0xde06
                    DE07    677 Fradio_sniffer$USBIIE$0$0 == 0xde07
                    DE07    678 _USBIIE	=	0xde07
                    DE09    679 Fradio_sniffer$USBOIE$0$0 == 0xde09
                    DE09    680 _USBOIE	=	0xde09
                    DE0B    681 Fradio_sniffer$USBCIE$0$0 == 0xde0b
                    DE0B    682 _USBCIE	=	0xde0b
                    DE0C    683 Fradio_sniffer$USBFRML$0$0 == 0xde0c
                    DE0C    684 _USBFRML	=	0xde0c
                    DE0D    685 Fradio_sniffer$USBFRMH$0$0 == 0xde0d
                    DE0D    686 _USBFRMH	=	0xde0d
                    DE0E    687 Fradio_sniffer$USBINDEX$0$0 == 0xde0e
                    DE0E    688 _USBINDEX	=	0xde0e
                    DE10    689 Fradio_sniffer$USBMAXI$0$0 == 0xde10
                    DE10    690 _USBMAXI	=	0xde10
                    DE11    691 Fradio_sniffer$USBCSIL$0$0 == 0xde11
                    DE11    692 _USBCSIL	=	0xde11
                    DE12    693 Fradio_sniffer$USBCSIH$0$0 == 0xde12
                    DE12    694 _USBCSIH	=	0xde12
                    DE13    695 Fradio_sniffer$USBMAXO$0$0 == 0xde13
                    DE13    696 _USBMAXO	=	0xde13
                    DE14    697 Fradio_sniffer$USBCSOL$0$0 == 0xde14
                    DE14    698 _USBCSOL	=	0xde14
                    DE15    699 Fradio_sniffer$USBCSOH$0$0 == 0xde15
                    DE15    700 _USBCSOH	=	0xde15
                    DE16    701 Fradio_sniffer$USBCNTL$0$0 == 0xde16
                    DE16    702 _USBCNTL	=	0xde16
                    DE17    703 Fradio_sniffer$USBCNTH$0$0 == 0xde17
                    DE17    704 _USBCNTH	=	0xde17
                    DE20    705 Fradio_sniffer$USBF0$0$0 == 0xde20
                    DE20    706 _USBF0	=	0xde20
                    DE22    707 Fradio_sniffer$USBF1$0$0 == 0xde22
                    DE22    708 _USBF1	=	0xde22
                    DE24    709 Fradio_sniffer$USBF2$0$0 == 0xde24
                    DE24    710 _USBF2	=	0xde24
                    DE26    711 Fradio_sniffer$USBF3$0$0 == 0xde26
                    DE26    712 _USBF3	=	0xde26
                    DE28    713 Fradio_sniffer$USBF4$0$0 == 0xde28
                    DE28    714 _USBF4	=	0xde28
                    DE2A    715 Fradio_sniffer$USBF5$0$0 == 0xde2a
                    DE2A    716 _USBF5	=	0xde2a
                            717 ;--------------------------------------------------------
                            718 ; absolute external ram data
                            719 ;--------------------------------------------------------
                            720 	.area XABS    (ABS,XDATA)
                            721 ;--------------------------------------------------------
                            722 ; external initialized ram data
                            723 ;--------------------------------------------------------
                            724 	.area XISEG   (XDATA)
                            725 	.area HOME    (CODE)
                            726 	.area GSINIT0 (CODE)
                            727 	.area GSINIT1 (CODE)
                            728 	.area GSINIT2 (CODE)
                            729 	.area GSINIT3 (CODE)
                            730 	.area GSINIT4 (CODE)
                            731 	.area GSINIT5 (CODE)
                            732 	.area GSINIT  (CODE)
                            733 	.area GSFINAL (CODE)
                            734 	.area CSEG    (CODE)
                            735 ;--------------------------------------------------------
                            736 ; interrupt vector 
                            737 ;--------------------------------------------------------
                            738 	.area HOME    (CODE)
   0400                     739 __interrupt_vect:
   0400 02 04 8D            740 	ljmp	__sdcc_gsinit_startup
   0403 32                  741 	reti
   0404                     742 	.ds	7
   040B 32                  743 	reti
   040C                     744 	.ds	7
   0413 32                  745 	reti
   0414                     746 	.ds	7
   041B 32                  747 	reti
   041C                     748 	.ds	7
   0423 32                  749 	reti
   0424                     750 	.ds	7
   042B 32                  751 	reti
   042C                     752 	.ds	7
   0433 32                  753 	reti
   0434                     754 	.ds	7
   043B 32                  755 	reti
   043C                     756 	.ds	7
   0443 32                  757 	reti
   0444                     758 	.ds	7
   044B 32                  759 	reti
   044C                     760 	.ds	7
   0453 32                  761 	reti
   0454                     762 	.ds	7
   045B 32                  763 	reti
   045C                     764 	.ds	7
   0463 02 17 3D            765 	ljmp	_ISR_T4
   0466                     766 	.ds	5
   046B 32                  767 	reti
   046C                     768 	.ds	7
   0473 32                  769 	reti
   0474                     770 	.ds	7
   047B 32                  771 	reti
   047C                     772 	.ds	7
   0483 02 09 9B            773 	ljmp	_ISR_RF
                            774 ;--------------------------------------------------------
                            775 ; global & static initialisations
                            776 ;--------------------------------------------------------
                            777 	.area HOME    (CODE)
                            778 	.area GSINIT  (CODE)
                            779 	.area GSFINAL (CODE)
                            780 	.area GSINIT  (CODE)
                            781 	.globl __sdcc_gsinit_startup
                            782 	.globl __sdcc_program_startup
                            783 	.globl __start__stack
                            784 	.globl __mcs51_genXINIT
                            785 	.globl __mcs51_genXRAMCLEAR
                            786 	.globl __mcs51_genRAMCLEAR
                            787 ;------------------------------------------------------------
                            788 ;Allocation info for local variables in function 'printPacket'
                            789 ;------------------------------------------------------------
                            790 ;sloc0                     Allocated with name '_printPacket_sloc0_1_0'
                            791 ;------------------------------------------------------------
                    0000    792 	G$printPacket$0$0 ==.
                    0000    793 	C$radio_sniffer.c$83$1$1 ==.
                            794 ;	apps/radio_sniffer/radio_sniffer.c:83: static uint16 pkt_count = 0;
   04E6 78 00               795 	mov	r0,#_printPacket_pkt_count_1_1
   04E8 E4                  796 	clr	a
   04E9 F2                  797 	movx	@r0,a
   04EA 08                  798 	inc	r0
   04EB F2                  799 	movx	@r0,a
                            800 	.area GSFINAL (CODE)
   052D 02 04 86            801 	ljmp	__sdcc_program_startup
                            802 ;--------------------------------------------------------
                            803 ; Home
                            804 ;--------------------------------------------------------
                            805 	.area HOME    (CODE)
                            806 	.area HOME    (CODE)
   0486                     807 __sdcc_program_startup:
   0486 12 09 81            808 	lcall	_main
                            809 ;	return from main will lock up
   0489 80 FE               810 	sjmp .
                            811 ;--------------------------------------------------------
                            812 ; code
                            813 ;--------------------------------------------------------
                            814 	.area CSEG    (CODE)
                            815 ;------------------------------------------------------------
                            816 ;Allocation info for local variables in function 'updateLeds'
                            817 ;------------------------------------------------------------
                    0000    818 	G$updateLeds$0$0 ==.
                    0000    819 	C$radio_sniffer.c$59$0$0 ==.
                            820 ;	apps/radio_sniffer/radio_sniffer.c:59: void updateLeds()
                            821 ;	-----------------------------------------
                            822 ;	 function updateLeds
                            823 ;	-----------------------------------------
   0530                     824 _updateLeds:
                    0007    825 	ar7 = 0x07
                    0006    826 	ar6 = 0x06
                    0005    827 	ar5 = 0x05
                    0004    828 	ar4 = 0x04
                    0003    829 	ar3 = 0x03
                    0002    830 	ar2 = 0x02
                    0001    831 	ar1 = 0x01
                    0000    832 	ar0 = 0x00
                    0000    833 	C$radio_sniffer.c$61$1$1 ==.
                            834 ;	apps/radio_sniffer/radio_sniffer.c:61: usbShowStatusWithGreenLed();
   0530 12 18 AE            835 	lcall	_usbShowStatusWithGreenLed
                    0003    836 	C$radio_sniffer.c$63$2$2 ==.
                            837 ;	apps/radio_sniffer/radio_sniffer.c:63: LED_YELLOW(radioQueueRxCurrentPacket());
   0533 12 0B F5            838 	lcall	_radioQueueRxCurrentPacket
   0536 E5 82               839 	mov	a,dpl
   0538 85 83 F0            840 	mov	b,dph
   053B 45 F0               841 	orl	a,b
   053D 60 05               842 	jz	00103$
   053F 43 FF 04            843 	orl	_P2DIR,#0x04
   0542 80 07               844 	sjmp	00104$
   0544                     845 00103$:
   0544 AF FF               846 	mov	r7,_P2DIR
   0546 53 07 FB            847 	anl	ar7,#0xFB
   0549 8F FF               848 	mov	_P2DIR,r7
   054B                     849 00104$:
                    001B    850 	C$radio_sniffer.c$65$2$3 ==.
                            851 ;	apps/radio_sniffer/radio_sniffer.c:65: LED_RED(0);
   054B AF FF               852 	mov	r7,_P2DIR
   054D 53 07 FD            853 	anl	ar7,#0xFD
   0550 8F FF               854 	mov	_P2DIR,r7
                    0022    855 	C$radio_sniffer.c$66$2$3 ==.
                    0022    856 	XG$updateLeds$0$0 ==.
   0552 22                  857 	ret
                            858 ;------------------------------------------------------------
                            859 ;Allocation info for local variables in function 'putchar'
                            860 ;------------------------------------------------------------
                    0023    861 	G$putchar$0$0 ==.
                    0023    862 	C$radio_sniffer.c$69$2$3 ==.
                            863 ;	apps/radio_sniffer/radio_sniffer.c:69: void putchar(char c)
                            864 ;	-----------------------------------------
                            865 ;	 function putchar
                            866 ;	-----------------------------------------
   0553                     867 _putchar:
                    0023    868 	C$radio_sniffer.c$71$1$1 ==.
                            869 ;	apps/radio_sniffer/radio_sniffer.c:71: usbComTxSendByte(c);
   0553 12 0F D1            870 	lcall	_usbComTxSendByte
                    0026    871 	C$radio_sniffer.c$72$1$1 ==.
                    0026    872 	XG$putchar$0$0 ==.
   0556 22                  873 	ret
                            874 ;------------------------------------------------------------
                            875 ;Allocation info for local variables in function 'nibbleToAscii'
                            876 ;------------------------------------------------------------
                    0027    877 	G$nibbleToAscii$0$0 ==.
                    0027    878 	C$radio_sniffer.c$74$1$1 ==.
                            879 ;	apps/radio_sniffer/radio_sniffer.c:74: char nibbleToAscii(uint8 nibble)
                            880 ;	-----------------------------------------
                            881 ;	 function nibbleToAscii
                            882 ;	-----------------------------------------
   0557                     883 _nibbleToAscii:
                    0027    884 	C$radio_sniffer.c$76$1$1 ==.
                            885 ;	apps/radio_sniffer/radio_sniffer.c:76: nibble &= 0xF;
                    0027    886 	C$radio_sniffer.c$77$1$1 ==.
                            887 ;	apps/radio_sniffer/radio_sniffer.c:77: if (nibble <= 0x9){ return '0' + nibble; }
   0557 E5 82               888 	mov	a,dpl
   0559 54 0F               889 	anl	a,#0x0F
   055B FF                  890 	mov	r7,a
   055C 24 F6               891 	add	a,#0xff - 0x09
   055E 40 09               892 	jc	00102$
   0560 8F 06               893 	mov	ar6,r7
   0562 74 30               894 	mov	a,#0x30
   0564 2E                  895 	add	a,r6
   0565 F5 82               896 	mov	dpl,a
   0567 80 05               897 	sjmp	00104$
   0569                     898 00102$:
                    0039    899 	C$radio_sniffer.c$78$2$3 ==.
                            900 ;	apps/radio_sniffer/radio_sniffer.c:78: else{ return 'A' + (nibble - 0xA); }
   0569 74 37               901 	mov	a,#0x37
   056B 2F                  902 	add	a,r7
   056C F5 82               903 	mov	dpl,a
   056E                     904 00104$:
                    003E    905 	C$radio_sniffer.c$79$1$1 ==.
                    003E    906 	XG$nibbleToAscii$0$0 ==.
   056E 22                  907 	ret
                            908 ;------------------------------------------------------------
                            909 ;Allocation info for local variables in function 'printPacket'
                            910 ;------------------------------------------------------------
                            911 ;sloc0                     Allocated with name '_printPacket_sloc0_1_0'
                            912 ;------------------------------------------------------------
                    003F    913 	G$printPacket$0$0 ==.
                    003F    914 	C$radio_sniffer.c$81$1$1 ==.
                            915 ;	apps/radio_sniffer/radio_sniffer.c:81: void printPacket(uint8 XDATA * pkt)
                            916 ;	-----------------------------------------
                            917 ;	 function printPacket
                            918 ;	-----------------------------------------
   056F                     919 _printPacket:
   056F AE 82               920 	mov	r6,dpl
   0571 AF 83               921 	mov	r7,dph
                    0043    922 	C$radio_sniffer.c$87$1$1 ==.
                            923 ;	apps/radio_sniffer/radio_sniffer.c:87: printf("%3d> ", pkt_count++);
   0573 78 00               924 	mov	r0,#_printPacket_pkt_count_1_1
   0575 E2                  925 	movx	a,@r0
   0576 FC                  926 	mov	r4,a
   0577 08                  927 	inc	r0
   0578 E2                  928 	movx	a,@r0
   0579 FD                  929 	mov	r5,a
   057A 78 00               930 	mov	r0,#_printPacket_pkt_count_1_1
   057C 74 01               931 	mov	a,#0x01
   057E 2C                  932 	add	a,r4
   057F F2                  933 	movx	@r0,a
   0580 E4                  934 	clr	a
   0581 3D                  935 	addc	a,r5
   0582 08                  936 	inc	r0
   0583 F2                  937 	movx	@r0,a
   0584 C0 07               938 	push	ar7
   0586 C0 06               939 	push	ar6
   0588 C0 04               940 	push	ar4
   058A C0 05               941 	push	ar5
   058C 74 0D               942 	mov	a,#__str_0
   058E C0 E0               943 	push	acc
   0590 74 21               944 	mov	a,#(__str_0 >> 8)
   0592 C0 E0               945 	push	acc
   0594 74 80               946 	mov	a,#0x80
   0596 C0 E0               947 	push	acc
   0598 12 19 6B            948 	lcall	_printf
   059B E5 81               949 	mov	a,sp
   059D 24 FB               950 	add	a,#0xfb
   059F F5 81               951 	mov	sp,a
   05A1 D0 06               952 	pop	ar6
   05A3 D0 07               953 	pop	ar7
                    0075    954 	C$radio_sniffer.c$88$1$1 ==.
                            955 ;	apps/radio_sniffer/radio_sniffer.c:88: if (pkt_count > 999)
   05A5 78 00               956 	mov	r0,#_printPacket_pkt_count_1_1
   05A7 C3                  957 	clr	c
   05A8 E2                  958 	movx	a,@r0
   05A9 F5 F0               959 	mov	b,a
   05AB 74 E7               960 	mov	a,#0xE7
   05AD 95 F0               961 	subb	a,b
   05AF 08                  962 	inc	r0
   05B0 E2                  963 	movx	a,@r0
   05B1 F5 F0               964 	mov	b,a
   05B3 74 03               965 	mov	a,#0x03
   05B5 95 F0               966 	subb	a,b
   05B7 50 06               967 	jnc	00102$
                    0089    968 	C$radio_sniffer.c$89$1$1 ==.
                            969 ;	apps/radio_sniffer/radio_sniffer.c:89: pkt_count = 0;
   05B9 78 00               970 	mov	r0,#_printPacket_pkt_count_1_1
   05BB E4                  971 	clr	a
   05BC F2                  972 	movx	@r0,a
   05BD 08                  973 	inc	r0
   05BE F2                  974 	movx	@r0,a
   05BF                     975 00102$:
                    008F    976 	C$radio_sniffer.c$91$1$1 ==.
                            977 ;	apps/radio_sniffer/radio_sniffer.c:91: len = pkt[0];
   05BF 8E 82               978 	mov	dpl,r6
   05C1 8F 83               979 	mov	dph,r7
   05C3 E0                  980 	movx	a,@dptr
   05C4 FD                  981 	mov	r5,a
                    0095    982 	C$radio_sniffer.c$94$1$1 ==.
                            983 ;	apps/radio_sniffer/radio_sniffer.c:94: putchar('"');
   05C5 75 82 22            984 	mov	dpl,#0x22
   05C8 C0 07               985 	push	ar7
   05CA C0 06               986 	push	ar6
   05CC C0 05               987 	push	ar5
   05CE 12 05 53            988 	lcall	_putchar
   05D1 D0 05               989 	pop	ar5
   05D3 D0 06               990 	pop	ar6
   05D5 D0 07               991 	pop	ar7
                    00A7    992 	C$radio_sniffer.c$95$1$1 ==.
                            993 ;	apps/radio_sniffer/radio_sniffer.c:95: for (j = 1; j <= len; j++)
   05D7 7C 01               994 	mov	r4,#0x01
   05D9                     995 00111$:
   05D9 C3                  996 	clr	c
   05DA ED                  997 	mov	a,r5
   05DB 9C                  998 	subb	a,r4
   05DC 40 66               999 	jc	00114$
                    00AE   1000 	C$radio_sniffer.c$97$1$1 ==.
                           1001 ;	apps/radio_sniffer/radio_sniffer.c:97: if (isprint(pkt[j]))
   05DE C0 05              1002 	push	ar5
   05E0 EC                 1003 	mov	a,r4
   05E1 2E                 1004 	add	a,r6
   05E2 FA                 1005 	mov	r2,a
   05E3 E4                 1006 	clr	a
   05E4 3F                 1007 	addc	a,r7
   05E5 FB                 1008 	mov	r3,a
   05E6 8A 82              1009 	mov	dpl,r2
   05E8 8B 83              1010 	mov	dph,r3
   05EA E0                 1011 	movx	a,@dptr
   05EB FD                 1012 	mov	r5,a
   05EC F5 82              1013 	mov	dpl,a
   05EE C0 07              1014 	push	ar7
   05F0 C0 06              1015 	push	ar6
   05F2 C0 05              1016 	push	ar5
   05F4 C0 04              1017 	push	ar4
   05F6 C0 03              1018 	push	ar3
   05F8 C0 02              1019 	push	ar2
   05FA 12 18 9A           1020 	lcall	_isprint
   05FD E5 82              1021 	mov	a,dpl
   05FF D0 02              1022 	pop	ar2
   0601 D0 03              1023 	pop	ar3
   0603 D0 04              1024 	pop	ar4
   0605 D0 05              1025 	pop	ar5
   0607 D0 06              1026 	pop	ar6
   0609 D0 07              1027 	pop	ar7
   060B D0 05              1028 	pop	ar5
   060D 60 1C              1029 	jz	00104$
                    00DF   1030 	C$radio_sniffer.c$99$3$3 ==.
                           1031 ;	apps/radio_sniffer/radio_sniffer.c:99: putchar(pkt[j]);
   060F 8A 82              1032 	mov	dpl,r2
   0611 8B 83              1033 	mov	dph,r3
   0613 E0                 1034 	movx	a,@dptr
   0614 F5 82              1035 	mov	dpl,a
   0616 C0 07              1036 	push	ar7
   0618 C0 06              1037 	push	ar6
   061A C0 05              1038 	push	ar5
   061C C0 04              1039 	push	ar4
   061E 12 05 53           1040 	lcall	_putchar
   0621 D0 04              1041 	pop	ar4
   0623 D0 05              1042 	pop	ar5
   0625 D0 06              1043 	pop	ar6
   0627 D0 07              1044 	pop	ar7
   0629 80 16              1045 	sjmp	00113$
   062B                    1046 00104$:
                    00FB   1047 	C$radio_sniffer.c$103$3$4 ==.
                           1048 ;	apps/radio_sniffer/radio_sniffer.c:103: putchar('?');
   062B 75 82 3F           1049 	mov	dpl,#0x3F
   062E C0 07              1050 	push	ar7
   0630 C0 06              1051 	push	ar6
   0632 C0 05              1052 	push	ar5
   0634 C0 04              1053 	push	ar4
   0636 12 05 53           1054 	lcall	_putchar
   0639 D0 04              1055 	pop	ar4
   063B D0 05              1056 	pop	ar5
   063D D0 06              1057 	pop	ar6
   063F D0 07              1058 	pop	ar7
   0641                    1059 00113$:
                    0111   1060 	C$radio_sniffer.c$95$1$1 ==.
                           1061 ;	apps/radio_sniffer/radio_sniffer.c:95: for (j = 1; j <= len; j++)
   0641 0C                 1062 	inc	r4
   0642 80 95              1063 	sjmp	00111$
   0644                    1064 00114$:
                    0114   1065 	C$radio_sniffer.c$106$1$1 ==.
                           1066 ;	apps/radio_sniffer/radio_sniffer.c:106: putchar('"');
   0644 75 82 22           1067 	mov	dpl,#0x22
   0647 C0 07              1068 	push	ar7
   0649 C0 06              1069 	push	ar6
   064B C0 05              1070 	push	ar5
   064D C0 04              1071 	push	ar4
   064F 12 05 53           1072 	lcall	_putchar
   0652 D0 04              1073 	pop	ar4
   0654 D0 05              1074 	pop	ar5
   0656 D0 06              1075 	pop	ar6
   0658 D0 07              1076 	pop	ar7
   065A                    1077 00115$:
                    012A   1078 	C$radio_sniffer.c$109$1$1 ==.
                           1079 ;	apps/radio_sniffer/radio_sniffer.c:109: for (; j <= RADIO_QUEUE_PAYLOAD_SIZE; j++)
   065A EC                 1080 	mov	a,r4
   065B 24 EC              1081 	add	a,#0xff - 0x13
   065D 40 19              1082 	jc	00118$
                    012F   1083 	C$radio_sniffer.c$111$2$5 ==.
                           1084 ;	apps/radio_sniffer/radio_sniffer.c:111: putchar(' ');
   065F 75 82 20           1085 	mov	dpl,#0x20
   0662 C0 07              1086 	push	ar7
   0664 C0 06              1087 	push	ar6
   0666 C0 05              1088 	push	ar5
   0668 C0 04              1089 	push	ar4
   066A 12 05 53           1090 	lcall	_putchar
   066D D0 04              1091 	pop	ar4
   066F D0 05              1092 	pop	ar5
   0671 D0 06              1093 	pop	ar6
   0673 D0 07              1094 	pop	ar7
                    0145   1095 	C$radio_sniffer.c$109$1$1 ==.
                           1096 ;	apps/radio_sniffer/radio_sniffer.c:109: for (; j <= RADIO_QUEUE_PAYLOAD_SIZE; j++)
   0675 0C                 1097 	inc	r4
   0676 80 E2              1098 	sjmp	00115$
   0678                    1099 00118$:
                    0148   1100 	C$radio_sniffer.c$113$1$1 ==.
                           1101 ;	apps/radio_sniffer/radio_sniffer.c:113: putchar(' ');
   0678 75 82 20           1102 	mov	dpl,#0x20
   067B C0 07              1103 	push	ar7
   067D C0 06              1104 	push	ar6
   067F C0 05              1105 	push	ar5
   0681 12 05 53           1106 	lcall	_putchar
   0684 D0 05              1107 	pop	ar5
   0686 D0 06              1108 	pop	ar6
   0688 D0 07              1109 	pop	ar7
                    015A   1110 	C$radio_sniffer.c$116$1$1 ==.
                           1111 ;	apps/radio_sniffer/radio_sniffer.c:116: putchar((pkt[len + 2] & 0x80) ? ' ' : '!');
   068A 8D 04              1112 	mov	ar4,r5
   068C 7D 00              1113 	mov	r5,#0x00
   068E 74 02              1114 	mov	a,#0x02
   0690 2C                 1115 	add	a,r4
   0691 FA                 1116 	mov	r2,a
   0692 E4                 1117 	clr	a
   0693 3D                 1118 	addc	a,r5
   0694 FB                 1119 	mov	r3,a
   0695 EA                 1120 	mov	a,r2
   0696 2E                 1121 	add	a,r6
   0697 F5 82              1122 	mov	dpl,a
   0699 EB                 1123 	mov	a,r3
   069A 3F                 1124 	addc	a,r7
   069B F5 83              1125 	mov	dph,a
   069D E0                 1126 	movx	a,@dptr
   069E FB                 1127 	mov	r3,a
   069F 30 E7 04           1128 	jnb	acc.7,00125$
   06A2 7B 20              1129 	mov	r3,#0x20
   06A4 80 02              1130 	sjmp	00126$
   06A6                    1131 00125$:
   06A6 7B 21              1132 	mov	r3,#0x21
   06A8                    1133 00126$:
   06A8 8B 82              1134 	mov	dpl,r3
   06AA C0 07              1135 	push	ar7
   06AC C0 06              1136 	push	ar6
   06AE C0 05              1137 	push	ar5
   06B0 C0 04              1138 	push	ar4
   06B2 12 05 53           1139 	lcall	_putchar
                    0185   1140 	C$radio_sniffer.c$117$1$1 ==.
                           1141 ;	apps/radio_sniffer/radio_sniffer.c:117: putchar(' ');
   06B5 75 82 20           1142 	mov	dpl,#0x20
   06B8 12 05 53           1143 	lcall	_putchar
   06BB D0 04              1144 	pop	ar4
   06BD D0 05              1145 	pop	ar5
   06BF D0 06              1146 	pop	ar6
   06C1 D0 07              1147 	pop	ar7
                    0193   1148 	C$radio_sniffer.c$120$1$1 ==.
                           1149 ;	apps/radio_sniffer/radio_sniffer.c:120: printf("R:%4d ", (int8)(pkt[len + 1])/2 - 71);
   06C3 74 01              1150 	mov	a,#0x01
   06C5 2C                 1151 	add	a,r4
   06C6 FA                 1152 	mov	r2,a
   06C7 E4                 1153 	clr	a
   06C8 3D                 1154 	addc	a,r5
   06C9 FB                 1155 	mov	r3,a
   06CA EA                 1156 	mov	a,r2
   06CB 2E                 1157 	add	a,r6
   06CC F5 82              1158 	mov	dpl,a
   06CE EB                 1159 	mov	a,r3
   06CF 3F                 1160 	addc	a,r7
   06D0 F5 83              1161 	mov	dph,a
   06D2 E0                 1162 	movx	a,@dptr
   06D3 FB                 1163 	mov	r3,a
   06D4 C2 D5              1164 	clr	F0
   06D6 75 F0 02           1165 	mov	b,#0x02
   06D9 EB                 1166 	mov	a,r3
   06DA 30 E7 04           1167 	jnb	acc.7,00145$
   06DD B2 D5              1168 	cpl	F0
   06DF F4                 1169 	cpl	a
   06E0 04                 1170 	inc	a
   06E1                    1171 00145$:
   06E1 84                 1172 	div	ab
   06E2 30 D5 02           1173 	jnb	F0,00146$
   06E5 F4                 1174 	cpl	a
   06E6 04                 1175 	inc	a
   06E7                    1176 00146$:
   06E7 C0 E0              1177 	push	acc
   06E9 A2 D5              1178 	mov	c,F0
   06EB 95 E0              1179 	subb	a,acc
   06ED F5 F0              1180 	mov	b,a
   06EF D0 E0              1181 	pop	acc
   06F1 24 B9              1182 	add	a,#0xB9
   06F3 FA                 1183 	mov	r2,a
   06F4 E5 F0              1184 	mov	a,b
   06F6 34 FF              1185 	addc	a,#0xFF
   06F8 FB                 1186 	mov	r3,a
   06F9 C0 07              1187 	push	ar7
   06FB C0 06              1188 	push	ar6
   06FD C0 05              1189 	push	ar5
   06FF C0 04              1190 	push	ar4
   0701 C0 02              1191 	push	ar2
   0703 C0 03              1192 	push	ar3
   0705 74 13              1193 	mov	a,#__str_1
   0707 C0 E0              1194 	push	acc
   0709 74 21              1195 	mov	a,#(__str_1 >> 8)
   070B C0 E0              1196 	push	acc
   070D 74 80              1197 	mov	a,#0x80
   070F C0 E0              1198 	push	acc
   0711 12 19 6B           1199 	lcall	_printf
   0714 E5 81              1200 	mov	a,sp
   0716 24 FB              1201 	add	a,#0xfb
   0718 F5 81              1202 	mov	sp,a
   071A D0 04              1203 	pop	ar4
   071C D0 05              1204 	pop	ar5
   071E D0 06              1205 	pop	ar6
   0720 D0 07              1206 	pop	ar7
                    01F2   1207 	C$radio_sniffer.c$121$1$1 ==.
                           1208 ;	apps/radio_sniffer/radio_sniffer.c:121: printf("L:%4d ", pkt[len + 2] & 0x7F);
   0722 74 02              1209 	mov	a,#0x02
   0724 2C                 1210 	add	a,r4
   0725 FA                 1211 	mov	r2,a
   0726 E4                 1212 	clr	a
   0727 3D                 1213 	addc	a,r5
   0728 FB                 1214 	mov	r3,a
   0729 EA                 1215 	mov	a,r2
   072A 2E                 1216 	add	a,r6
   072B F5 82              1217 	mov	dpl,a
   072D EB                 1218 	mov	a,r3
   072E 3F                 1219 	addc	a,r7
   072F F5 83              1220 	mov	dph,a
   0731 E0                 1221 	movx	a,@dptr
   0732 FB                 1222 	mov	r3,a
   0733 53 03 7F           1223 	anl	ar3,#0x7F
   0736 7A 00              1224 	mov	r2,#0x00
   0738 C0 07              1225 	push	ar7
   073A C0 06              1226 	push	ar6
   073C C0 05              1227 	push	ar5
   073E C0 04              1228 	push	ar4
   0740 C0 03              1229 	push	ar3
   0742 C0 02              1230 	push	ar2
   0744 74 1A              1231 	mov	a,#__str_2
   0746 C0 E0              1232 	push	acc
   0748 74 21              1233 	mov	a,#(__str_2 >> 8)
   074A C0 E0              1234 	push	acc
   074C 74 80              1235 	mov	a,#0x80
   074E C0 E0              1236 	push	acc
   0750 12 19 6B           1237 	lcall	_printf
   0753 E5 81              1238 	mov	a,sp
   0755 24 FB              1239 	add	a,#0xfb
   0757 F5 81              1240 	mov	sp,a
   0759 D0 04              1241 	pop	ar4
   075B D0 05              1242 	pop	ar5
   075D D0 06              1243 	pop	ar6
   075F D0 07              1244 	pop	ar7
                    0231   1245 	C$radio_sniffer.c$124$1$1 ==.
                           1246 ;	apps/radio_sniffer/radio_sniffer.c:124: printf("s:%1d ", pkt[1] & 0x1);
   0761 74 01              1247 	mov	a,#0x01
   0763 2E                 1248 	add	a,r6
   0764 FA                 1249 	mov	r2,a
   0765 E4                 1250 	clr	a
   0766 3F                 1251 	addc	a,r7
   0767 FB                 1252 	mov	r3,a
   0768 C0 04              1253 	push	ar4
   076A C0 05              1254 	push	ar5
   076C 8A 82              1255 	mov	dpl,r2
   076E 8B 83              1256 	mov	dph,r3
   0770 E0                 1257 	movx	a,@dptr
   0771 FD                 1258 	mov	r5,a
   0772 53 05 01           1259 	anl	ar5,#0x01
   0775 7C 00              1260 	mov	r4,#0x00
   0777 C0 07              1261 	push	ar7
   0779 C0 06              1262 	push	ar6
   077B C0 05              1263 	push	ar5
   077D C0 04              1264 	push	ar4
   077F C0 03              1265 	push	ar3
   0781 C0 02              1266 	push	ar2
   0783 C0 05              1267 	push	ar5
   0785 C0 04              1268 	push	ar4
   0787 74 21              1269 	mov	a,#__str_3
   0789 C0 E0              1270 	push	acc
   078B 74 21              1271 	mov	a,#(__str_3 >> 8)
   078D C0 E0              1272 	push	acc
   078F 74 80              1273 	mov	a,#0x80
   0791 C0 E0              1274 	push	acc
   0793 12 19 6B           1275 	lcall	_printf
   0796 E5 81              1276 	mov	a,sp
   0798 24 FB              1277 	add	a,#0xfb
   079A F5 81              1278 	mov	sp,a
   079C D0 02              1279 	pop	ar2
   079E D0 03              1280 	pop	ar3
   07A0 D0 04              1281 	pop	ar4
   07A2 D0 05              1282 	pop	ar5
   07A4 D0 06              1283 	pop	ar6
   07A6 D0 07              1284 	pop	ar7
                    0278   1285 	C$radio_sniffer.c$127$1$1 ==.
                           1286 ;	apps/radio_sniffer/radio_sniffer.c:127: switch((pkt[1] >> 6) & 3)
   07A8 8A 82              1287 	mov	dpl,r2
   07AA 8B 83              1288 	mov	dph,r3
   07AC E0                 1289 	movx	a,@dptr
   07AD 23                 1290 	rl	a
   07AE 23                 1291 	rl	a
   07AF 54 03              1292 	anl	a,#0x03
   07B1 FD                 1293 	mov	r5,a
   07B2 74 03              1294 	mov	a,#0x03
   07B4 5D                 1295 	anl	a,r5
   07B5 F5 08              1296 	mov	_printPacket_sloc0_1_0,a
   07B7 C3                 1297 	clr	c
   07B8 74 03              1298 	mov	a,#0x03
   07BA 95 08              1299 	subb	a,_printPacket_sloc0_1_0
   07BC D0 05              1300 	pop	ar5
   07BE D0 04              1301 	pop	ar4
   07C0 50 03              1302 	jnc	00147$
   07C2 02 08 96           1303 	ljmp	00110$
   07C5                    1304 00147$:
   07C5 E5 08              1305 	mov	a,_printPacket_sloc0_1_0
   07C7 25 08              1306 	add	a,_printPacket_sloc0_1_0
   07C9 25 08              1307 	add	a,_printPacket_sloc0_1_0
   07CB 90 07 CF           1308 	mov	dptr,#00148$
   07CE 73                 1309 	jmp	@a+dptr
   07CF                    1310 00148$:
   07CF 02 07 DB           1311 	ljmp	00106$
   07D2 02 08 0B           1312 	ljmp	00107$
   07D5 02 08 3A           1313 	ljmp	00108$
   07D8 02 08 69           1314 	ljmp	00109$
                    02AB   1315 	C$radio_sniffer.c$129$2$6 ==.
                           1316 ;	apps/radio_sniffer/radio_sniffer.c:129: case 0: printf("PING  "); break;
   07DB                    1317 00106$:
   07DB C0 07              1318 	push	ar7
   07DD C0 06              1319 	push	ar6
   07DF C0 05              1320 	push	ar5
   07E1 C0 04              1321 	push	ar4
   07E3 C0 03              1322 	push	ar3
   07E5 C0 02              1323 	push	ar2
   07E7 74 28              1324 	mov	a,#__str_4
   07E9 C0 E0              1325 	push	acc
   07EB 74 21              1326 	mov	a,#(__str_4 >> 8)
   07ED C0 E0              1327 	push	acc
   07EF 74 80              1328 	mov	a,#0x80
   07F1 C0 E0              1329 	push	acc
   07F3 12 19 6B           1330 	lcall	_printf
   07F6 15 81              1331 	dec	sp
   07F8 15 81              1332 	dec	sp
   07FA 15 81              1333 	dec	sp
   07FC D0 02              1334 	pop	ar2
   07FE D0 03              1335 	pop	ar3
   0800 D0 04              1336 	pop	ar4
   0802 D0 05              1337 	pop	ar5
   0804 D0 06              1338 	pop	ar6
   0806 D0 07              1339 	pop	ar7
   0808 02 08 96           1340 	ljmp	00110$
                    02DB   1341 	C$radio_sniffer.c$130$2$6 ==.
                           1342 ;	apps/radio_sniffer/radio_sniffer.c:130: case 1: printf("NAK   "); break;
   080B                    1343 00107$:
   080B C0 07              1344 	push	ar7
   080D C0 06              1345 	push	ar6
   080F C0 05              1346 	push	ar5
   0811 C0 04              1347 	push	ar4
   0813 C0 03              1348 	push	ar3
   0815 C0 02              1349 	push	ar2
   0817 74 2F              1350 	mov	a,#__str_5
   0819 C0 E0              1351 	push	acc
   081B 74 21              1352 	mov	a,#(__str_5 >> 8)
   081D C0 E0              1353 	push	acc
   081F 74 80              1354 	mov	a,#0x80
   0821 C0 E0              1355 	push	acc
   0823 12 19 6B           1356 	lcall	_printf
   0826 15 81              1357 	dec	sp
   0828 15 81              1358 	dec	sp
   082A 15 81              1359 	dec	sp
   082C D0 02              1360 	pop	ar2
   082E D0 03              1361 	pop	ar3
   0830 D0 04              1362 	pop	ar4
   0832 D0 05              1363 	pop	ar5
   0834 D0 06              1364 	pop	ar6
   0836 D0 07              1365 	pop	ar7
                    0308   1366 	C$radio_sniffer.c$131$2$6 ==.
                           1367 ;	apps/radio_sniffer/radio_sniffer.c:131: case 2: printf("ACK   "); break;
   0838 80 5C              1368 	sjmp	00110$
   083A                    1369 00108$:
   083A C0 07              1370 	push	ar7
   083C C0 06              1371 	push	ar6
   083E C0 05              1372 	push	ar5
   0840 C0 04              1373 	push	ar4
   0842 C0 03              1374 	push	ar3
   0844 C0 02              1375 	push	ar2
   0846 74 36              1376 	mov	a,#__str_6
   0848 C0 E0              1377 	push	acc
   084A 74 21              1378 	mov	a,#(__str_6 >> 8)
   084C C0 E0              1379 	push	acc
   084E 74 80              1380 	mov	a,#0x80
   0850 C0 E0              1381 	push	acc
   0852 12 19 6B           1382 	lcall	_printf
   0855 15 81              1383 	dec	sp
   0857 15 81              1384 	dec	sp
   0859 15 81              1385 	dec	sp
   085B D0 02              1386 	pop	ar2
   085D D0 03              1387 	pop	ar3
   085F D0 04              1388 	pop	ar4
   0861 D0 05              1389 	pop	ar5
   0863 D0 06              1390 	pop	ar6
   0865 D0 07              1391 	pop	ar7
                    0337   1392 	C$radio_sniffer.c$132$2$6 ==.
                           1393 ;	apps/radio_sniffer/radio_sniffer.c:132: case 3: printf("RESET "); break;
   0867 80 2D              1394 	sjmp	00110$
   0869                    1395 00109$:
   0869 C0 07              1396 	push	ar7
   086B C0 06              1397 	push	ar6
   086D C0 05              1398 	push	ar5
   086F C0 04              1399 	push	ar4
   0871 C0 03              1400 	push	ar3
   0873 C0 02              1401 	push	ar2
   0875 74 3D              1402 	mov	a,#__str_7
   0877 C0 E0              1403 	push	acc
   0879 74 21              1404 	mov	a,#(__str_7 >> 8)
   087B C0 E0              1405 	push	acc
   087D 74 80              1406 	mov	a,#0x80
   087F C0 E0              1407 	push	acc
   0881 12 19 6B           1408 	lcall	_printf
   0884 15 81              1409 	dec	sp
   0886 15 81              1410 	dec	sp
   0888 15 81              1411 	dec	sp
   088A D0 02              1412 	pop	ar2
   088C D0 03              1413 	pop	ar3
   088E D0 04              1414 	pop	ar4
   0890 D0 05              1415 	pop	ar5
   0892 D0 06              1416 	pop	ar6
   0894 D0 07              1417 	pop	ar7
                    0366   1418 	C$radio_sniffer.c$133$1$1 ==.
                           1419 ;	apps/radio_sniffer/radio_sniffer.c:133: }
   0896                    1420 00110$:
                    0366   1421 	C$radio_sniffer.c$136$1$1 ==.
                           1422 ;	apps/radio_sniffer/radio_sniffer.c:136: putchar('p');
   0896 75 82 70           1423 	mov	dpl,#0x70
   0899 C0 07              1424 	push	ar7
   089B C0 06              1425 	push	ar6
   089D C0 05              1426 	push	ar5
   089F C0 04              1427 	push	ar4
   08A1 C0 03              1428 	push	ar3
   08A3 C0 02              1429 	push	ar2
   08A5 12 05 53           1430 	lcall	_putchar
                    0378   1431 	C$radio_sniffer.c$137$1$1 ==.
                           1432 ;	apps/radio_sniffer/radio_sniffer.c:137: putchar(':');
   08A8 75 82 3A           1433 	mov	dpl,#0x3A
   08AB 12 05 53           1434 	lcall	_putchar
   08AE D0 02              1435 	pop	ar2
   08B0 D0 03              1436 	pop	ar3
                    0382   1437 	C$radio_sniffer.c$138$1$1 ==.
                           1438 ;	apps/radio_sniffer/radio_sniffer.c:138: putchar(nibbleToAscii(pkt[1] >> 1 & 0xF));
   08B2 8A 82              1439 	mov	dpl,r2
   08B4 8B 83              1440 	mov	dph,r3
   08B6 E0                 1441 	movx	a,@dptr
   08B7 C3                 1442 	clr	c
   08B8 13                 1443 	rrc	a
   08B9 FA                 1444 	mov	r2,a
   08BA 74 0F              1445 	mov	a,#0x0F
   08BC 5A                 1446 	anl	a,r2
   08BD F5 82              1447 	mov	dpl,a
   08BF 12 05 57           1448 	lcall	_nibbleToAscii
   08C2 12 05 53           1449 	lcall	_putchar
                    0395   1450 	C$radio_sniffer.c$139$1$1 ==.
                           1451 ;	apps/radio_sniffer/radio_sniffer.c:139: putchar(' ');
   08C5 75 82 20           1452 	mov	dpl,#0x20
   08C8 12 05 53           1453 	lcall	_putchar
   08CB D0 04              1454 	pop	ar4
   08CD D0 05              1455 	pop	ar5
   08CF D0 06              1456 	pop	ar6
   08D1 D0 07              1457 	pop	ar7
                    03A3   1458 	C$radio_sniffer.c$142$1$1 ==.
                           1459 ;	apps/radio_sniffer/radio_sniffer.c:142: for(j = 0; j < len + 1; j++)  // add 1 for length byte
   08D3 0C                 1460 	inc	r4
   08D4 BC 00 01           1461 	cjne	r4,#0x00,00149$
   08D7 0D                 1462 	inc	r5
   08D8                    1463 00149$:
   08D8 7B 00              1464 	mov	r3,#0x00
   08DA                    1465 00119$:
   08DA C0 06              1466 	push	ar6
   08DC C0 07              1467 	push	ar7
   08DE 8B 02              1468 	mov	ar2,r3
   08E0 7F 00              1469 	mov	r7,#0x00
   08E2 C3                 1470 	clr	c
   08E3 EA                 1471 	mov	a,r2
   08E4 9C                 1472 	subb	a,r4
   08E5 EF                 1473 	mov	a,r7
   08E6 64 80              1474 	xrl	a,#0x80
   08E8 8D F0              1475 	mov	b,r5
   08EA 63 F0 80           1476 	xrl	b,#0x80
   08ED 95 F0              1477 	subb	a,b
   08EF D0 07              1478 	pop	ar7
   08F1 D0 06              1479 	pop	ar6
   08F3 50 53              1480 	jnc	00122$
                    03C5   1481 	C$radio_sniffer.c$144$1$1 ==.
                           1482 ;	apps/radio_sniffer/radio_sniffer.c:144: putchar(nibbleToAscii(pkt[j] >> 4));
   08F5 C0 04              1483 	push	ar4
   08F7 C0 05              1484 	push	ar5
   08F9 EB                 1485 	mov	a,r3
   08FA 2E                 1486 	add	a,r6
   08FB FA                 1487 	mov	r2,a
   08FC E4                 1488 	clr	a
   08FD 3F                 1489 	addc	a,r7
   08FE FD                 1490 	mov	r5,a
   08FF 8A 82              1491 	mov	dpl,r2
   0901 8D 83              1492 	mov	dph,r5
   0903 E0                 1493 	movx	a,@dptr
   0904 FC                 1494 	mov	r4,a
   0905 C4                 1495 	swap	a
   0906 54 0F              1496 	anl	a,#0x0F
   0908 F5 82              1497 	mov	dpl,a
   090A C0 07              1498 	push	ar7
   090C C0 06              1499 	push	ar6
   090E C0 05              1500 	push	ar5
   0910 C0 04              1501 	push	ar4
   0912 C0 03              1502 	push	ar3
   0914 C0 02              1503 	push	ar2
   0916 12 05 57           1504 	lcall	_nibbleToAscii
   0919 12 05 53           1505 	lcall	_putchar
   091C D0 02              1506 	pop	ar2
   091E D0 03              1507 	pop	ar3
   0920 D0 04              1508 	pop	ar4
   0922 D0 05              1509 	pop	ar5
                    03F4   1510 	C$radio_sniffer.c$145$2$7 ==.
                           1511 ;	apps/radio_sniffer/radio_sniffer.c:145: putchar(nibbleToAscii(pkt[j]));
   0924 8A 82              1512 	mov	dpl,r2
   0926 8D 83              1513 	mov	dph,r5
   0928 E0                 1514 	movx	a,@dptr
   0929 F5 82              1515 	mov	dpl,a
   092B C0 05              1516 	push	ar5
   092D C0 04              1517 	push	ar4
   092F C0 03              1518 	push	ar3
   0931 12 05 57           1519 	lcall	_nibbleToAscii
   0934 12 05 53           1520 	lcall	_putchar
   0937 D0 03              1521 	pop	ar3
   0939 D0 04              1522 	pop	ar4
   093B D0 05              1523 	pop	ar5
   093D D0 06              1524 	pop	ar6
   093F D0 07              1525 	pop	ar7
                    0411   1526 	C$radio_sniffer.c$142$1$1 ==.
                           1527 ;	apps/radio_sniffer/radio_sniffer.c:142: for(j = 0; j < len + 1; j++)  // add 1 for length byte
   0941 0B                 1528 	inc	r3
   0942 D0 05              1529 	pop	ar5
   0944 D0 04              1530 	pop	ar4
   0946 80 92              1531 	sjmp	00119$
   0948                    1532 00122$:
                    0418   1533 	C$radio_sniffer.c$147$1$1 ==.
                           1534 ;	apps/radio_sniffer/radio_sniffer.c:147: putchar('\r');
   0948 75 82 0D           1535 	mov	dpl,#0x0D
   094B 12 05 53           1536 	lcall	_putchar
                    041E   1537 	C$radio_sniffer.c$148$1$1 ==.
                           1538 ;	apps/radio_sniffer/radio_sniffer.c:148: putchar('\n');
   094E 75 82 0A           1539 	mov	dpl,#0x0A
   0951 12 05 53           1540 	lcall	_putchar
                    0424   1541 	C$radio_sniffer.c$149$1$1 ==.
                    0424   1542 	XG$printPacket$0$0 ==.
   0954 22                 1543 	ret
                           1544 ;------------------------------------------------------------
                           1545 ;Allocation info for local variables in function 'printPacketIfNeeded'
                           1546 ;------------------------------------------------------------
                    0425   1547 	G$printPacketIfNeeded$0$0 ==.
                    0425   1548 	C$radio_sniffer.c$151$1$1 ==.
                           1549 ;	apps/radio_sniffer/radio_sniffer.c:151: void printPacketIfNeeded()
                           1550 ;	-----------------------------------------
                           1551 ;	 function printPacketIfNeeded
                           1552 ;	-----------------------------------------
   0955                    1553 _printPacketIfNeeded:
                    0425   1554 	C$radio_sniffer.c$154$1$1 ==.
                           1555 ;	apps/radio_sniffer/radio_sniffer.c:154: if ((packet = radioQueueRxCurrentPacket()) && usbComTxAvailable() >= 128)
   0955 12 0B F5           1556 	lcall	_radioQueueRxCurrentPacket
   0958 AE 82              1557 	mov	r6,dpl
   095A AF 83              1558 	mov	r7,dph
   095C 8E 04              1559 	mov	ar4,r6
   095E 8F 05              1560 	mov	ar5,r7
   0960 EE                 1561 	mov	a,r6
   0961 4F                 1562 	orl	a,r7
   0962 60 1C              1563 	jz	00104$
   0964 C0 05              1564 	push	ar5
   0966 C0 04              1565 	push	ar4
   0968 12 0F 3F           1566 	lcall	_usbComTxAvailable
   096B AF 82              1567 	mov	r7,dpl
   096D D0 04              1568 	pop	ar4
   096F D0 05              1569 	pop	ar5
   0971 BF 80 00           1570 	cjne	r7,#0x80,00109$
   0974                    1571 00109$:
   0974 40 0A              1572 	jc	00104$
                    0446   1573 	C$radio_sniffer.c$156$2$2 ==.
                           1574 ;	apps/radio_sniffer/radio_sniffer.c:156: printPacket(packet);
   0976 8C 82              1575 	mov	dpl,r4
   0978 8D 83              1576 	mov	dph,r5
   097A 12 05 6F           1577 	lcall	_printPacket
                    044D   1578 	C$radio_sniffer.c$157$2$2 ==.
                           1579 ;	apps/radio_sniffer/radio_sniffer.c:157: radioQueueRxDoneWithPacket();
   097D 12 0C 10           1580 	lcall	_radioQueueRxDoneWithPacket
   0980                    1581 00104$:
                    0450   1582 	C$radio_sniffer.c$159$2$1 ==.
                    0450   1583 	XG$printPacketIfNeeded$0$0 ==.
   0980 22                 1584 	ret
                           1585 ;------------------------------------------------------------
                           1586 ;Allocation info for local variables in function 'main'
                           1587 ;------------------------------------------------------------
                    0451   1588 	G$main$0$0 ==.
                    0451   1589 	C$radio_sniffer.c$161$2$1 ==.
                           1590 ;	apps/radio_sniffer/radio_sniffer.c:161: void main()
                           1591 ;	-----------------------------------------
                           1592 ;	 function main
                           1593 ;	-----------------------------------------
   0981                    1594 _main:
                    0451   1595 	C$radio_sniffer.c$163$1$1 ==.
                           1596 ;	apps/radio_sniffer/radio_sniffer.c:163: systemInit();
   0981 12 16 62           1597 	lcall	_systemInit
                    0454   1598 	C$radio_sniffer.c$164$1$1 ==.
                           1599 ;	apps/radio_sniffer/radio_sniffer.c:164: usbInit();
   0984 12 0F FC           1600 	lcall	_usbInit
                    0457   1601 	C$radio_sniffer.c$166$1$1 ==.
                           1602 ;	apps/radio_sniffer/radio_sniffer.c:166: radioQueueInit();
   0987 12 0B 83           1603 	lcall	_radioQueueInit
                    045A   1604 	C$radio_sniffer.c$167$1$1 ==.
                           1605 ;	apps/radio_sniffer/radio_sniffer.c:167: radioQueueAllowCrcErrors = 1;
   098A D2 03              1606 	setb	_radioQueueAllowCrcErrors
                    045C   1607 	C$radio_sniffer.c$169$1$1 ==.
                           1608 ;	apps/radio_sniffer/radio_sniffer.c:169: while(1)
   098C                    1609 00102$:
                    045C   1610 	C$radio_sniffer.c$171$2$2 ==.
                           1611 ;	apps/radio_sniffer/radio_sniffer.c:171: boardService();
   098C 12 16 6F           1612 	lcall	_boardService
                    045F   1613 	C$radio_sniffer.c$172$2$2 ==.
                           1614 ;	apps/radio_sniffer/radio_sniffer.c:172: updateLeds();
   098F 12 05 30           1615 	lcall	_updateLeds
                    0462   1616 	C$radio_sniffer.c$173$2$2 ==.
                           1617 ;	apps/radio_sniffer/radio_sniffer.c:173: usbComService();
   0992 12 0E 9A           1618 	lcall	_usbComService
                    0465   1619 	C$radio_sniffer.c$174$2$2 ==.
                           1620 ;	apps/radio_sniffer/radio_sniffer.c:174: printPacketIfNeeded();
   0995 12 09 55           1621 	lcall	_printPacketIfNeeded
   0998 80 F2              1622 	sjmp	00102$
                    046A   1623 	C$radio_sniffer.c$176$1$1 ==.
                    046A   1624 	XG$main$0$0 ==.
   099A 22                 1625 	ret
                           1626 	.area CSEG    (CODE)
                           1627 	.area CONST   (CODE)
                    0000   1628 Fradio_sniffer$_str_0$0$0 == .
   210D                    1629 __str_0:
   210D 25 33 64 3E 20     1630 	.ascii "%3d> "
   2112 00                 1631 	.db 0x00
                    0006   1632 Fradio_sniffer$_str_1$0$0 == .
   2113                    1633 __str_1:
   2113 52 3A 25 34 64 20  1634 	.ascii "R:%4d "
   2119 00                 1635 	.db 0x00
                    000D   1636 Fradio_sniffer$_str_2$0$0 == .
   211A                    1637 __str_2:
   211A 4C 3A 25 34 64 20  1638 	.ascii "L:%4d "
   2120 00                 1639 	.db 0x00
                    0014   1640 Fradio_sniffer$_str_3$0$0 == .
   2121                    1641 __str_3:
   2121 73 3A 25 31 64 20  1642 	.ascii "s:%1d "
   2127 00                 1643 	.db 0x00
                    001B   1644 Fradio_sniffer$_str_4$0$0 == .
   2128                    1645 __str_4:
   2128 50 49 4E 47 20 20  1646 	.ascii "PING  "
   212E 00                 1647 	.db 0x00
                    0022   1648 Fradio_sniffer$_str_5$0$0 == .
   212F                    1649 __str_5:
   212F 4E 41 4B 20 20 20  1650 	.ascii "NAK   "
   2135 00                 1651 	.db 0x00
                    0029   1652 Fradio_sniffer$_str_6$0$0 == .
   2136                    1653 __str_6:
   2136 41 43 4B 20 20 20  1654 	.ascii "ACK   "
   213C 00                 1655 	.db 0x00
                    0030   1656 Fradio_sniffer$_str_7$0$0 == .
   213D                    1657 __str_7:
   213D 52 45 53 45 54 20  1658 	.ascii "RESET "
   2143 00                 1659 	.db 0x00
                           1660 	.area XINIT   (CODE)
                           1661 	.area CABS    (ABS,CODE)
