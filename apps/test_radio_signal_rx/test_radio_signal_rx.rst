                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:10 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_radio_signal_rx
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_radio_channel
                             13 	.globl _main
                             14 	.globl _reportResults
                             15 	.globl _receiveRadioBursts
                             16 	.globl _perTestRxInit
                             17 	.globl _updateLeds
                             18 	.globl _usbComTxSend
                             19 	.globl _usbComTxAvailable
                             20 	.globl _usbComService
                             21 	.globl _usbShowStatusWithGreenLed
                             22 	.globl _usbInit
                             23 	.globl _sprintf
                             24 	.globl _radioCrcPassed
                             25 	.globl _radioRssi
                             26 	.globl _radioLqi
                             27 	.globl _radioRegistersInit
                             28 	.globl _getMs
                             29 	.globl _boardService
                             30 	.globl _systemInit
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 	.area RSEG    (ABS,DATA)
   0000                      35 	.org 0x0000
                    0080     36 Ftest_radio_signal_rx$P0$0$0 == 0x0080
                    0080     37 _P0	=	0x0080
                    0081     38 Ftest_radio_signal_rx$SP$0$0 == 0x0081
                    0081     39 _SP	=	0x0081
                    0082     40 Ftest_radio_signal_rx$DPL0$0$0 == 0x0082
                    0082     41 _DPL0	=	0x0082
                    0083     42 Ftest_radio_signal_rx$DPH0$0$0 == 0x0083
                    0083     43 _DPH0	=	0x0083
                    0084     44 Ftest_radio_signal_rx$DPL1$0$0 == 0x0084
                    0084     45 _DPL1	=	0x0084
                    0085     46 Ftest_radio_signal_rx$DPH1$0$0 == 0x0085
                    0085     47 _DPH1	=	0x0085
                    0086     48 Ftest_radio_signal_rx$U0CSR$0$0 == 0x0086
                    0086     49 _U0CSR	=	0x0086
                    0087     50 Ftest_radio_signal_rx$PCON$0$0 == 0x0087
                    0087     51 _PCON	=	0x0087
                    0088     52 Ftest_radio_signal_rx$TCON$0$0 == 0x0088
                    0088     53 _TCON	=	0x0088
                    0089     54 Ftest_radio_signal_rx$P0IFG$0$0 == 0x0089
                    0089     55 _P0IFG	=	0x0089
                    008A     56 Ftest_radio_signal_rx$P1IFG$0$0 == 0x008a
                    008A     57 _P1IFG	=	0x008a
                    008B     58 Ftest_radio_signal_rx$P2IFG$0$0 == 0x008b
                    008B     59 _P2IFG	=	0x008b
                    008C     60 Ftest_radio_signal_rx$PICTL$0$0 == 0x008c
                    008C     61 _PICTL	=	0x008c
                    008D     62 Ftest_radio_signal_rx$P1IEN$0$0 == 0x008d
                    008D     63 _P1IEN	=	0x008d
                    008F     64 Ftest_radio_signal_rx$P0INP$0$0 == 0x008f
                    008F     65 _P0INP	=	0x008f
                    0090     66 Ftest_radio_signal_rx$P1$0$0 == 0x0090
                    0090     67 _P1	=	0x0090
                    0091     68 Ftest_radio_signal_rx$RFIM$0$0 == 0x0091
                    0091     69 _RFIM	=	0x0091
                    0092     70 Ftest_radio_signal_rx$DPS$0$0 == 0x0092
                    0092     71 _DPS	=	0x0092
                    0093     72 Ftest_radio_signal_rx$MPAGE$0$0 == 0x0093
                    0093     73 _MPAGE	=	0x0093
                    0095     74 Ftest_radio_signal_rx$ENDIAN$0$0 == 0x0095
                    0095     75 _ENDIAN	=	0x0095
                    0098     76 Ftest_radio_signal_rx$S0CON$0$0 == 0x0098
                    0098     77 _S0CON	=	0x0098
                    009A     78 Ftest_radio_signal_rx$IEN2$0$0 == 0x009a
                    009A     79 _IEN2	=	0x009a
                    009B     80 Ftest_radio_signal_rx$S1CON$0$0 == 0x009b
                    009B     81 _S1CON	=	0x009b
                    009C     82 Ftest_radio_signal_rx$T2CT$0$0 == 0x009c
                    009C     83 _T2CT	=	0x009c
                    009D     84 Ftest_radio_signal_rx$T2PR$0$0 == 0x009d
                    009D     85 _T2PR	=	0x009d
                    009E     86 Ftest_radio_signal_rx$T2CTL$0$0 == 0x009e
                    009E     87 _T2CTL	=	0x009e
                    00A0     88 Ftest_radio_signal_rx$P2$0$0 == 0x00a0
                    00A0     89 _P2	=	0x00a0
                    00A1     90 Ftest_radio_signal_rx$WORIRQ$0$0 == 0x00a1
                    00A1     91 _WORIRQ	=	0x00a1
                    00A2     92 Ftest_radio_signal_rx$WORCTRL$0$0 == 0x00a2
                    00A2     93 _WORCTRL	=	0x00a2
                    00A3     94 Ftest_radio_signal_rx$WOREVT0$0$0 == 0x00a3
                    00A3     95 _WOREVT0	=	0x00a3
                    00A4     96 Ftest_radio_signal_rx$WOREVT1$0$0 == 0x00a4
                    00A4     97 _WOREVT1	=	0x00a4
                    00A5     98 Ftest_radio_signal_rx$WORTIME0$0$0 == 0x00a5
                    00A5     99 _WORTIME0	=	0x00a5
                    00A6    100 Ftest_radio_signal_rx$WORTIME1$0$0 == 0x00a6
                    00A6    101 _WORTIME1	=	0x00a6
                    00A8    102 Ftest_radio_signal_rx$IEN0$0$0 == 0x00a8
                    00A8    103 _IEN0	=	0x00a8
                    00A9    104 Ftest_radio_signal_rx$IP0$0$0 == 0x00a9
                    00A9    105 _IP0	=	0x00a9
                    00AB    106 Ftest_radio_signal_rx$FWT$0$0 == 0x00ab
                    00AB    107 _FWT	=	0x00ab
                    00AC    108 Ftest_radio_signal_rx$FADDRL$0$0 == 0x00ac
                    00AC    109 _FADDRL	=	0x00ac
                    00AD    110 Ftest_radio_signal_rx$FADDRH$0$0 == 0x00ad
                    00AD    111 _FADDRH	=	0x00ad
                    00AE    112 Ftest_radio_signal_rx$FCTL$0$0 == 0x00ae
                    00AE    113 _FCTL	=	0x00ae
                    00AF    114 Ftest_radio_signal_rx$FWDATA$0$0 == 0x00af
                    00AF    115 _FWDATA	=	0x00af
                    00B1    116 Ftest_radio_signal_rx$ENCDI$0$0 == 0x00b1
                    00B1    117 _ENCDI	=	0x00b1
                    00B2    118 Ftest_radio_signal_rx$ENCDO$0$0 == 0x00b2
                    00B2    119 _ENCDO	=	0x00b2
                    00B3    120 Ftest_radio_signal_rx$ENCCS$0$0 == 0x00b3
                    00B3    121 _ENCCS	=	0x00b3
                    00B4    122 Ftest_radio_signal_rx$ADCCON1$0$0 == 0x00b4
                    00B4    123 _ADCCON1	=	0x00b4
                    00B5    124 Ftest_radio_signal_rx$ADCCON2$0$0 == 0x00b5
                    00B5    125 _ADCCON2	=	0x00b5
                    00B6    126 Ftest_radio_signal_rx$ADCCON3$0$0 == 0x00b6
                    00B6    127 _ADCCON3	=	0x00b6
                    00B8    128 Ftest_radio_signal_rx$IEN1$0$0 == 0x00b8
                    00B8    129 _IEN1	=	0x00b8
                    00B9    130 Ftest_radio_signal_rx$IP1$0$0 == 0x00b9
                    00B9    131 _IP1	=	0x00b9
                    00BA    132 Ftest_radio_signal_rx$ADCL$0$0 == 0x00ba
                    00BA    133 _ADCL	=	0x00ba
                    00BB    134 Ftest_radio_signal_rx$ADCH$0$0 == 0x00bb
                    00BB    135 _ADCH	=	0x00bb
                    00BC    136 Ftest_radio_signal_rx$RNDL$0$0 == 0x00bc
                    00BC    137 _RNDL	=	0x00bc
                    00BD    138 Ftest_radio_signal_rx$RNDH$0$0 == 0x00bd
                    00BD    139 _RNDH	=	0x00bd
                    00BE    140 Ftest_radio_signal_rx$SLEEP$0$0 == 0x00be
                    00BE    141 _SLEEP	=	0x00be
                    00C0    142 Ftest_radio_signal_rx$IRCON$0$0 == 0x00c0
                    00C0    143 _IRCON	=	0x00c0
                    00C1    144 Ftest_radio_signal_rx$U0DBUF$0$0 == 0x00c1
                    00C1    145 _U0DBUF	=	0x00c1
                    00C2    146 Ftest_radio_signal_rx$U0BAUD$0$0 == 0x00c2
                    00C2    147 _U0BAUD	=	0x00c2
                    00C4    148 Ftest_radio_signal_rx$U0UCR$0$0 == 0x00c4
                    00C4    149 _U0UCR	=	0x00c4
                    00C5    150 Ftest_radio_signal_rx$U0GCR$0$0 == 0x00c5
                    00C5    151 _U0GCR	=	0x00c5
                    00C6    152 Ftest_radio_signal_rx$CLKCON$0$0 == 0x00c6
                    00C6    153 _CLKCON	=	0x00c6
                    00C7    154 Ftest_radio_signal_rx$MEMCTR$0$0 == 0x00c7
                    00C7    155 _MEMCTR	=	0x00c7
                    00C9    156 Ftest_radio_signal_rx$WDCTL$0$0 == 0x00c9
                    00C9    157 _WDCTL	=	0x00c9
                    00CA    158 Ftest_radio_signal_rx$T3CNT$0$0 == 0x00ca
                    00CA    159 _T3CNT	=	0x00ca
                    00CB    160 Ftest_radio_signal_rx$T3CTL$0$0 == 0x00cb
                    00CB    161 _T3CTL	=	0x00cb
                    00CC    162 Ftest_radio_signal_rx$T3CCTL0$0$0 == 0x00cc
                    00CC    163 _T3CCTL0	=	0x00cc
                    00CD    164 Ftest_radio_signal_rx$T3CC0$0$0 == 0x00cd
                    00CD    165 _T3CC0	=	0x00cd
                    00CE    166 Ftest_radio_signal_rx$T3CCTL1$0$0 == 0x00ce
                    00CE    167 _T3CCTL1	=	0x00ce
                    00CF    168 Ftest_radio_signal_rx$T3CC1$0$0 == 0x00cf
                    00CF    169 _T3CC1	=	0x00cf
                    00D0    170 Ftest_radio_signal_rx$PSW$0$0 == 0x00d0
                    00D0    171 _PSW	=	0x00d0
                    00D1    172 Ftest_radio_signal_rx$DMAIRQ$0$0 == 0x00d1
                    00D1    173 _DMAIRQ	=	0x00d1
                    00D2    174 Ftest_radio_signal_rx$DMA1CFGL$0$0 == 0x00d2
                    00D2    175 _DMA1CFGL	=	0x00d2
                    00D3    176 Ftest_radio_signal_rx$DMA1CFGH$0$0 == 0x00d3
                    00D3    177 _DMA1CFGH	=	0x00d3
                    00D4    178 Ftest_radio_signal_rx$DMA0CFGL$0$0 == 0x00d4
                    00D4    179 _DMA0CFGL	=	0x00d4
                    00D5    180 Ftest_radio_signal_rx$DMA0CFGH$0$0 == 0x00d5
                    00D5    181 _DMA0CFGH	=	0x00d5
                    00D6    182 Ftest_radio_signal_rx$DMAARM$0$0 == 0x00d6
                    00D6    183 _DMAARM	=	0x00d6
                    00D7    184 Ftest_radio_signal_rx$DMAREQ$0$0 == 0x00d7
                    00D7    185 _DMAREQ	=	0x00d7
                    00D8    186 Ftest_radio_signal_rx$TIMIF$0$0 == 0x00d8
                    00D8    187 _TIMIF	=	0x00d8
                    00D9    188 Ftest_radio_signal_rx$RFD$0$0 == 0x00d9
                    00D9    189 _RFD	=	0x00d9
                    00DA    190 Ftest_radio_signal_rx$T1CC0L$0$0 == 0x00da
                    00DA    191 _T1CC0L	=	0x00da
                    00DB    192 Ftest_radio_signal_rx$T1CC0H$0$0 == 0x00db
                    00DB    193 _T1CC0H	=	0x00db
                    00DC    194 Ftest_radio_signal_rx$T1CC1L$0$0 == 0x00dc
                    00DC    195 _T1CC1L	=	0x00dc
                    00DD    196 Ftest_radio_signal_rx$T1CC1H$0$0 == 0x00dd
                    00DD    197 _T1CC1H	=	0x00dd
                    00DE    198 Ftest_radio_signal_rx$T1CC2L$0$0 == 0x00de
                    00DE    199 _T1CC2L	=	0x00de
                    00DF    200 Ftest_radio_signal_rx$T1CC2H$0$0 == 0x00df
                    00DF    201 _T1CC2H	=	0x00df
                    00E0    202 Ftest_radio_signal_rx$ACC$0$0 == 0x00e0
                    00E0    203 _ACC	=	0x00e0
                    00E1    204 Ftest_radio_signal_rx$RFST$0$0 == 0x00e1
                    00E1    205 _RFST	=	0x00e1
                    00E2    206 Ftest_radio_signal_rx$T1CNTL$0$0 == 0x00e2
                    00E2    207 _T1CNTL	=	0x00e2
                    00E3    208 Ftest_radio_signal_rx$T1CNTH$0$0 == 0x00e3
                    00E3    209 _T1CNTH	=	0x00e3
                    00E4    210 Ftest_radio_signal_rx$T1CTL$0$0 == 0x00e4
                    00E4    211 _T1CTL	=	0x00e4
                    00E5    212 Ftest_radio_signal_rx$T1CCTL0$0$0 == 0x00e5
                    00E5    213 _T1CCTL0	=	0x00e5
                    00E6    214 Ftest_radio_signal_rx$T1CCTL1$0$0 == 0x00e6
                    00E6    215 _T1CCTL1	=	0x00e6
                    00E7    216 Ftest_radio_signal_rx$T1CCTL2$0$0 == 0x00e7
                    00E7    217 _T1CCTL2	=	0x00e7
                    00E8    218 Ftest_radio_signal_rx$IRCON2$0$0 == 0x00e8
                    00E8    219 _IRCON2	=	0x00e8
                    00E9    220 Ftest_radio_signal_rx$RFIF$0$0 == 0x00e9
                    00E9    221 _RFIF	=	0x00e9
                    00EA    222 Ftest_radio_signal_rx$T4CNT$0$0 == 0x00ea
                    00EA    223 _T4CNT	=	0x00ea
                    00EB    224 Ftest_radio_signal_rx$T4CTL$0$0 == 0x00eb
                    00EB    225 _T4CTL	=	0x00eb
                    00EC    226 Ftest_radio_signal_rx$T4CCTL0$0$0 == 0x00ec
                    00EC    227 _T4CCTL0	=	0x00ec
                    00ED    228 Ftest_radio_signal_rx$T4CC0$0$0 == 0x00ed
                    00ED    229 _T4CC0	=	0x00ed
                    00EE    230 Ftest_radio_signal_rx$T4CCTL1$0$0 == 0x00ee
                    00EE    231 _T4CCTL1	=	0x00ee
                    00EF    232 Ftest_radio_signal_rx$T4CC1$0$0 == 0x00ef
                    00EF    233 _T4CC1	=	0x00ef
                    00F0    234 Ftest_radio_signal_rx$B$0$0 == 0x00f0
                    00F0    235 _B	=	0x00f0
                    00F1    236 Ftest_radio_signal_rx$PERCFG$0$0 == 0x00f1
                    00F1    237 _PERCFG	=	0x00f1
                    00F2    238 Ftest_radio_signal_rx$ADCCFG$0$0 == 0x00f2
                    00F2    239 _ADCCFG	=	0x00f2
                    00F3    240 Ftest_radio_signal_rx$P0SEL$0$0 == 0x00f3
                    00F3    241 _P0SEL	=	0x00f3
                    00F4    242 Ftest_radio_signal_rx$P1SEL$0$0 == 0x00f4
                    00F4    243 _P1SEL	=	0x00f4
                    00F5    244 Ftest_radio_signal_rx$P2SEL$0$0 == 0x00f5
                    00F5    245 _P2SEL	=	0x00f5
                    00F6    246 Ftest_radio_signal_rx$P1INP$0$0 == 0x00f6
                    00F6    247 _P1INP	=	0x00f6
                    00F7    248 Ftest_radio_signal_rx$P2INP$0$0 == 0x00f7
                    00F7    249 _P2INP	=	0x00f7
                    00F8    250 Ftest_radio_signal_rx$U1CSR$0$0 == 0x00f8
                    00F8    251 _U1CSR	=	0x00f8
                    00F9    252 Ftest_radio_signal_rx$U1DBUF$0$0 == 0x00f9
                    00F9    253 _U1DBUF	=	0x00f9
                    00FA    254 Ftest_radio_signal_rx$U1BAUD$0$0 == 0x00fa
                    00FA    255 _U1BAUD	=	0x00fa
                    00FB    256 Ftest_radio_signal_rx$U1UCR$0$0 == 0x00fb
                    00FB    257 _U1UCR	=	0x00fb
                    00FC    258 Ftest_radio_signal_rx$U1GCR$0$0 == 0x00fc
                    00FC    259 _U1GCR	=	0x00fc
                    00FD    260 Ftest_radio_signal_rx$P0DIR$0$0 == 0x00fd
                    00FD    261 _P0DIR	=	0x00fd
                    00FE    262 Ftest_radio_signal_rx$P1DIR$0$0 == 0x00fe
                    00FE    263 _P1DIR	=	0x00fe
                    00FF    264 Ftest_radio_signal_rx$P2DIR$0$0 == 0x00ff
                    00FF    265 _P2DIR	=	0x00ff
                    FFFFD5D4    266 Ftest_radio_signal_rx$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    267 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    268 Ftest_radio_signal_rx$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    269 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    270 Ftest_radio_signal_rx$FADDR$0$0 == 0xffffadac
                    FFFFADAC    271 _FADDR	=	0xffffadac
                    FFFFBBBA    272 Ftest_radio_signal_rx$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    273 _ADC	=	0xffffbbba
                    FFFFDBDA    274 Ftest_radio_signal_rx$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    275 _T1CC0	=	0xffffdbda
                    FFFFDDDC    276 Ftest_radio_signal_rx$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    277 _T1CC1	=	0xffffdddc
                    FFFFDFDE    278 Ftest_radio_signal_rx$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    279 _T1CC2	=	0xffffdfde
                            280 ;--------------------------------------------------------
                            281 ; special function bits
                            282 ;--------------------------------------------------------
                            283 	.area RSEG    (ABS,DATA)
   0000                     284 	.org 0x0000
                    0080    285 Ftest_radio_signal_rx$P0_0$0$0 == 0x0080
                    0080    286 _P0_0	=	0x0080
                    0081    287 Ftest_radio_signal_rx$P0_1$0$0 == 0x0081
                    0081    288 _P0_1	=	0x0081
                    0082    289 Ftest_radio_signal_rx$P0_2$0$0 == 0x0082
                    0082    290 _P0_2	=	0x0082
                    0083    291 Ftest_radio_signal_rx$P0_3$0$0 == 0x0083
                    0083    292 _P0_3	=	0x0083
                    0084    293 Ftest_radio_signal_rx$P0_4$0$0 == 0x0084
                    0084    294 _P0_4	=	0x0084
                    0085    295 Ftest_radio_signal_rx$P0_5$0$0 == 0x0085
                    0085    296 _P0_5	=	0x0085
                    0086    297 Ftest_radio_signal_rx$P0_6$0$0 == 0x0086
                    0086    298 _P0_6	=	0x0086
                    0087    299 Ftest_radio_signal_rx$P0_7$0$0 == 0x0087
                    0087    300 _P0_7	=	0x0087
                    0088    301 Ftest_radio_signal_rx$_TCON_0$0$0 == 0x0088
                    0088    302 __TCON_0	=	0x0088
                    0089    303 Ftest_radio_signal_rx$RFTXRXIF$0$0 == 0x0089
                    0089    304 _RFTXRXIF	=	0x0089
                    008A    305 Ftest_radio_signal_rx$_TCON_2$0$0 == 0x008a
                    008A    306 __TCON_2	=	0x008a
                    008B    307 Ftest_radio_signal_rx$URX0IF$0$0 == 0x008b
                    008B    308 _URX0IF	=	0x008b
                    008C    309 Ftest_radio_signal_rx$_TCON_4$0$0 == 0x008c
                    008C    310 __TCON_4	=	0x008c
                    008D    311 Ftest_radio_signal_rx$ADCIF$0$0 == 0x008d
                    008D    312 _ADCIF	=	0x008d
                    008E    313 Ftest_radio_signal_rx$_TCON_6$0$0 == 0x008e
                    008E    314 __TCON_6	=	0x008e
                    008F    315 Ftest_radio_signal_rx$URX1IF$0$0 == 0x008f
                    008F    316 _URX1IF	=	0x008f
                    0090    317 Ftest_radio_signal_rx$P1_0$0$0 == 0x0090
                    0090    318 _P1_0	=	0x0090
                    0091    319 Ftest_radio_signal_rx$P1_1$0$0 == 0x0091
                    0091    320 _P1_1	=	0x0091
                    0092    321 Ftest_radio_signal_rx$P1_2$0$0 == 0x0092
                    0092    322 _P1_2	=	0x0092
                    0093    323 Ftest_radio_signal_rx$P1_3$0$0 == 0x0093
                    0093    324 _P1_3	=	0x0093
                    0094    325 Ftest_radio_signal_rx$P1_4$0$0 == 0x0094
                    0094    326 _P1_4	=	0x0094
                    0095    327 Ftest_radio_signal_rx$P1_5$0$0 == 0x0095
                    0095    328 _P1_5	=	0x0095
                    0096    329 Ftest_radio_signal_rx$P1_6$0$0 == 0x0096
                    0096    330 _P1_6	=	0x0096
                    0097    331 Ftest_radio_signal_rx$P1_7$0$0 == 0x0097
                    0097    332 _P1_7	=	0x0097
                    0098    333 Ftest_radio_signal_rx$ENCIF_0$0$0 == 0x0098
                    0098    334 _ENCIF_0	=	0x0098
                    0099    335 Ftest_radio_signal_rx$ENCIF_1$0$0 == 0x0099
                    0099    336 _ENCIF_1	=	0x0099
                    009A    337 Ftest_radio_signal_rx$_SOCON2$0$0 == 0x009a
                    009A    338 __SOCON2	=	0x009a
                    009B    339 Ftest_radio_signal_rx$_SOCON3$0$0 == 0x009b
                    009B    340 __SOCON3	=	0x009b
                    009C    341 Ftest_radio_signal_rx$_SOCON4$0$0 == 0x009c
                    009C    342 __SOCON4	=	0x009c
                    009D    343 Ftest_radio_signal_rx$_SOCON5$0$0 == 0x009d
                    009D    344 __SOCON5	=	0x009d
                    009E    345 Ftest_radio_signal_rx$_SOCON6$0$0 == 0x009e
                    009E    346 __SOCON6	=	0x009e
                    009F    347 Ftest_radio_signal_rx$_SOCON7$0$0 == 0x009f
                    009F    348 __SOCON7	=	0x009f
                    00A0    349 Ftest_radio_signal_rx$P2_0$0$0 == 0x00a0
                    00A0    350 _P2_0	=	0x00a0
                    00A1    351 Ftest_radio_signal_rx$P2_1$0$0 == 0x00a1
                    00A1    352 _P2_1	=	0x00a1
                    00A2    353 Ftest_radio_signal_rx$P2_2$0$0 == 0x00a2
                    00A2    354 _P2_2	=	0x00a2
                    00A3    355 Ftest_radio_signal_rx$P2_3$0$0 == 0x00a3
                    00A3    356 _P2_3	=	0x00a3
                    00A4    357 Ftest_radio_signal_rx$P2_4$0$0 == 0x00a4
                    00A4    358 _P2_4	=	0x00a4
                    00A5    359 Ftest_radio_signal_rx$P2_5$0$0 == 0x00a5
                    00A5    360 _P2_5	=	0x00a5
                    00A6    361 Ftest_radio_signal_rx$P2_6$0$0 == 0x00a6
                    00A6    362 _P2_6	=	0x00a6
                    00A7    363 Ftest_radio_signal_rx$P2_7$0$0 == 0x00a7
                    00A7    364 _P2_7	=	0x00a7
                    00A8    365 Ftest_radio_signal_rx$RFTXRXIE$0$0 == 0x00a8
                    00A8    366 _RFTXRXIE	=	0x00a8
                    00A9    367 Ftest_radio_signal_rx$ADCIE$0$0 == 0x00a9
                    00A9    368 _ADCIE	=	0x00a9
                    00AA    369 Ftest_radio_signal_rx$URX0IE$0$0 == 0x00aa
                    00AA    370 _URX0IE	=	0x00aa
                    00AB    371 Ftest_radio_signal_rx$URX1IE$0$0 == 0x00ab
                    00AB    372 _URX1IE	=	0x00ab
                    00AC    373 Ftest_radio_signal_rx$ENCIE$0$0 == 0x00ac
                    00AC    374 _ENCIE	=	0x00ac
                    00AD    375 Ftest_radio_signal_rx$STIE$0$0 == 0x00ad
                    00AD    376 _STIE	=	0x00ad
                    00AE    377 Ftest_radio_signal_rx$_IEN06$0$0 == 0x00ae
                    00AE    378 __IEN06	=	0x00ae
                    00AF    379 Ftest_radio_signal_rx$EA$0$0 == 0x00af
                    00AF    380 _EA	=	0x00af
                    00B8    381 Ftest_radio_signal_rx$DMAIE$0$0 == 0x00b8
                    00B8    382 _DMAIE	=	0x00b8
                    00B9    383 Ftest_radio_signal_rx$T1IE$0$0 == 0x00b9
                    00B9    384 _T1IE	=	0x00b9
                    00BA    385 Ftest_radio_signal_rx$T2IE$0$0 == 0x00ba
                    00BA    386 _T2IE	=	0x00ba
                    00BB    387 Ftest_radio_signal_rx$T3IE$0$0 == 0x00bb
                    00BB    388 _T3IE	=	0x00bb
                    00BC    389 Ftest_radio_signal_rx$T4IE$0$0 == 0x00bc
                    00BC    390 _T4IE	=	0x00bc
                    00BD    391 Ftest_radio_signal_rx$P0IE$0$0 == 0x00bd
                    00BD    392 _P0IE	=	0x00bd
                    00BE    393 Ftest_radio_signal_rx$_IEN16$0$0 == 0x00be
                    00BE    394 __IEN16	=	0x00be
                    00BF    395 Ftest_radio_signal_rx$_IEN17$0$0 == 0x00bf
                    00BF    396 __IEN17	=	0x00bf
                    00C0    397 Ftest_radio_signal_rx$DMAIF$0$0 == 0x00c0
                    00C0    398 _DMAIF	=	0x00c0
                    00C1    399 Ftest_radio_signal_rx$T1IF$0$0 == 0x00c1
                    00C1    400 _T1IF	=	0x00c1
                    00C2    401 Ftest_radio_signal_rx$T2IF$0$0 == 0x00c2
                    00C2    402 _T2IF	=	0x00c2
                    00C3    403 Ftest_radio_signal_rx$T3IF$0$0 == 0x00c3
                    00C3    404 _T3IF	=	0x00c3
                    00C4    405 Ftest_radio_signal_rx$T4IF$0$0 == 0x00c4
                    00C4    406 _T4IF	=	0x00c4
                    00C5    407 Ftest_radio_signal_rx$P0IF$0$0 == 0x00c5
                    00C5    408 _P0IF	=	0x00c5
                    00C6    409 Ftest_radio_signal_rx$_IRCON6$0$0 == 0x00c6
                    00C6    410 __IRCON6	=	0x00c6
                    00C7    411 Ftest_radio_signal_rx$STIF$0$0 == 0x00c7
                    00C7    412 _STIF	=	0x00c7
                    00D0    413 Ftest_radio_signal_rx$P$0$0 == 0x00d0
                    00D0    414 _P	=	0x00d0
                    00D1    415 Ftest_radio_signal_rx$F1$0$0 == 0x00d1
                    00D1    416 _F1	=	0x00d1
                    00D2    417 Ftest_radio_signal_rx$OV$0$0 == 0x00d2
                    00D2    418 _OV	=	0x00d2
                    00D3    419 Ftest_radio_signal_rx$RS0$0$0 == 0x00d3
                    00D3    420 _RS0	=	0x00d3
                    00D4    421 Ftest_radio_signal_rx$RS1$0$0 == 0x00d4
                    00D4    422 _RS1	=	0x00d4
                    00D5    423 Ftest_radio_signal_rx$F0$0$0 == 0x00d5
                    00D5    424 _F0	=	0x00d5
                    00D6    425 Ftest_radio_signal_rx$AC$0$0 == 0x00d6
                    00D6    426 _AC	=	0x00d6
                    00D7    427 Ftest_radio_signal_rx$CY$0$0 == 0x00d7
                    00D7    428 _CY	=	0x00d7
                    00D8    429 Ftest_radio_signal_rx$T3OVFIF$0$0 == 0x00d8
                    00D8    430 _T3OVFIF	=	0x00d8
                    00D9    431 Ftest_radio_signal_rx$T3CH0IF$0$0 == 0x00d9
                    00D9    432 _T3CH0IF	=	0x00d9
                    00DA    433 Ftest_radio_signal_rx$T3CH1IF$0$0 == 0x00da
                    00DA    434 _T3CH1IF	=	0x00da
                    00DB    435 Ftest_radio_signal_rx$T4OVFIF$0$0 == 0x00db
                    00DB    436 _T4OVFIF	=	0x00db
                    00DC    437 Ftest_radio_signal_rx$T4CH0IF$0$0 == 0x00dc
                    00DC    438 _T4CH0IF	=	0x00dc
                    00DD    439 Ftest_radio_signal_rx$T4CH1IF$0$0 == 0x00dd
                    00DD    440 _T4CH1IF	=	0x00dd
                    00DE    441 Ftest_radio_signal_rx$OVFIM$0$0 == 0x00de
                    00DE    442 _OVFIM	=	0x00de
                    00DF    443 Ftest_radio_signal_rx$_TIMIF7$0$0 == 0x00df
                    00DF    444 __TIMIF7	=	0x00df
                    00E0    445 Ftest_radio_signal_rx$ACC_0$0$0 == 0x00e0
                    00E0    446 _ACC_0	=	0x00e0
                    00E1    447 Ftest_radio_signal_rx$ACC_1$0$0 == 0x00e1
                    00E1    448 _ACC_1	=	0x00e1
                    00E2    449 Ftest_radio_signal_rx$ACC_2$0$0 == 0x00e2
                    00E2    450 _ACC_2	=	0x00e2
                    00E3    451 Ftest_radio_signal_rx$ACC_3$0$0 == 0x00e3
                    00E3    452 _ACC_3	=	0x00e3
                    00E4    453 Ftest_radio_signal_rx$ACC_4$0$0 == 0x00e4
                    00E4    454 _ACC_4	=	0x00e4
                    00E5    455 Ftest_radio_signal_rx$ACC_5$0$0 == 0x00e5
                    00E5    456 _ACC_5	=	0x00e5
                    00E6    457 Ftest_radio_signal_rx$ACC_6$0$0 == 0x00e6
                    00E6    458 _ACC_6	=	0x00e6
                    00E7    459 Ftest_radio_signal_rx$ACC_7$0$0 == 0x00e7
                    00E7    460 _ACC_7	=	0x00e7
                    00E8    461 Ftest_radio_signal_rx$P2IF$0$0 == 0x00e8
                    00E8    462 _P2IF	=	0x00e8
                    00E9    463 Ftest_radio_signal_rx$UTX0IF$0$0 == 0x00e9
                    00E9    464 _UTX0IF	=	0x00e9
                    00EA    465 Ftest_radio_signal_rx$UTX1IF$0$0 == 0x00ea
                    00EA    466 _UTX1IF	=	0x00ea
                    00EB    467 Ftest_radio_signal_rx$P1IF$0$0 == 0x00eb
                    00EB    468 _P1IF	=	0x00eb
                    00EC    469 Ftest_radio_signal_rx$WDTIF$0$0 == 0x00ec
                    00EC    470 _WDTIF	=	0x00ec
                    00ED    471 Ftest_radio_signal_rx$_IRCON25$0$0 == 0x00ed
                    00ED    472 __IRCON25	=	0x00ed
                    00EE    473 Ftest_radio_signal_rx$_IRCON26$0$0 == 0x00ee
                    00EE    474 __IRCON26	=	0x00ee
                    00EF    475 Ftest_radio_signal_rx$_IRCON27$0$0 == 0x00ef
                    00EF    476 __IRCON27	=	0x00ef
                    00F0    477 Ftest_radio_signal_rx$B_0$0$0 == 0x00f0
                    00F0    478 _B_0	=	0x00f0
                    00F1    479 Ftest_radio_signal_rx$B_1$0$0 == 0x00f1
                    00F1    480 _B_1	=	0x00f1
                    00F2    481 Ftest_radio_signal_rx$B_2$0$0 == 0x00f2
                    00F2    482 _B_2	=	0x00f2
                    00F3    483 Ftest_radio_signal_rx$B_3$0$0 == 0x00f3
                    00F3    484 _B_3	=	0x00f3
                    00F4    485 Ftest_radio_signal_rx$B_4$0$0 == 0x00f4
                    00F4    486 _B_4	=	0x00f4
                    00F5    487 Ftest_radio_signal_rx$B_5$0$0 == 0x00f5
                    00F5    488 _B_5	=	0x00f5
                    00F6    489 Ftest_radio_signal_rx$B_6$0$0 == 0x00f6
                    00F6    490 _B_6	=	0x00f6
                    00F7    491 Ftest_radio_signal_rx$B_7$0$0 == 0x00f7
                    00F7    492 _B_7	=	0x00f7
                    00F8    493 Ftest_radio_signal_rx$U1ACTIVE$0$0 == 0x00f8
                    00F8    494 _U1ACTIVE	=	0x00f8
                    00F9    495 Ftest_radio_signal_rx$U1TX_BYTE$0$0 == 0x00f9
                    00F9    496 _U1TX_BYTE	=	0x00f9
                    00FA    497 Ftest_radio_signal_rx$U1RX_BYTE$0$0 == 0x00fa
                    00FA    498 _U1RX_BYTE	=	0x00fa
                    00FB    499 Ftest_radio_signal_rx$U1ERR$0$0 == 0x00fb
                    00FB    500 _U1ERR	=	0x00fb
                    00FC    501 Ftest_radio_signal_rx$U1FE$0$0 == 0x00fc
                    00FC    502 _U1FE	=	0x00fc
                    00FD    503 Ftest_radio_signal_rx$U1SLAVE$0$0 == 0x00fd
                    00FD    504 _U1SLAVE	=	0x00fd
                    00FE    505 Ftest_radio_signal_rx$U1RE$0$0 == 0x00fe
                    00FE    506 _U1RE	=	0x00fe
                    00FF    507 Ftest_radio_signal_rx$U1MODE$0$0 == 0x00ff
                    00FF    508 _U1MODE	=	0x00ff
                            509 ;--------------------------------------------------------
                            510 ; overlayable register banks
                            511 ;--------------------------------------------------------
                            512 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     513 	.ds 8
                            514 ;--------------------------------------------------------
                            515 ; internal ram data
                            516 ;--------------------------------------------------------
                            517 	.area DSEG    (DATA)
                    0000    518 Ftest_radio_signal_rx$currentBurstId$0$0==.
   0008                     519 _currentBurstId:
   0008                     520 	.ds 1
                    0001    521 Ftest_radio_signal_rx$packetsReceived$0$0==.
   0009                     522 _packetsReceived:
   0009                     523 	.ds 1
                    0002    524 Ftest_radio_signal_rx$rssiSum$0$0==.
   000A                     525 _rssiSum:
   000A                     526 	.ds 2
                    0004    527 Ftest_radio_signal_rx$lqiSum$0$0==.
   000C                     528 _lqiSum:
   000C                     529 	.ds 2
                    0006    530 Ftest_radio_signal_rx$crcErrors$0$0==.
   000E                     531 _crcErrors:
   000E                     532 	.ds 1
                    0007    533 Ltest_radio_signal_rx.reportResults$sloc0$1$0==.
   000F                     534 _reportResults_sloc0_1_0:
   000F                     535 	.ds 4
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
                            560 ;--------------------------------------------------------
                            561 ; paged external ram data
                            562 ;--------------------------------------------------------
                            563 	.area PSEG    (PAG,XDATA)
                    0000    564 Ftest_radio_signal_rx$lastPacketReceivedTime$0$0==.
   F000                     565 _lastPacketReceivedTime:
   F000                     566 	.ds 2
                    0002    567 Ltest_radio_signal_rx.reportResults$lastReportSentTime$1$1==.
   F002                     568 _reportResults_lastReportSentTime_1_1:
   F002                     569 	.ds 2
                            570 ;--------------------------------------------------------
                            571 ; external ram data
                            572 ;--------------------------------------------------------
                            573 	.area XSEG    (XDATA)
                    DF00    574 Ftest_radio_signal_rx$SYNC1$0$0 == 0xdf00
                    DF00    575 _SYNC1	=	0xdf00
                    DF01    576 Ftest_radio_signal_rx$SYNC0$0$0 == 0xdf01
                    DF01    577 _SYNC0	=	0xdf01
                    DF02    578 Ftest_radio_signal_rx$PKTLEN$0$0 == 0xdf02
                    DF02    579 _PKTLEN	=	0xdf02
                    DF03    580 Ftest_radio_signal_rx$PKTCTRL1$0$0 == 0xdf03
                    DF03    581 _PKTCTRL1	=	0xdf03
                    DF04    582 Ftest_radio_signal_rx$PKTCTRL0$0$0 == 0xdf04
                    DF04    583 _PKTCTRL0	=	0xdf04
                    DF05    584 Ftest_radio_signal_rx$ADDR$0$0 == 0xdf05
                    DF05    585 _ADDR	=	0xdf05
                    DF06    586 Ftest_radio_signal_rx$CHANNR$0$0 == 0xdf06
                    DF06    587 _CHANNR	=	0xdf06
                    DF07    588 Ftest_radio_signal_rx$FSCTRL1$0$0 == 0xdf07
                    DF07    589 _FSCTRL1	=	0xdf07
                    DF08    590 Ftest_radio_signal_rx$FSCTRL0$0$0 == 0xdf08
                    DF08    591 _FSCTRL0	=	0xdf08
                    DF09    592 Ftest_radio_signal_rx$FREQ2$0$0 == 0xdf09
                    DF09    593 _FREQ2	=	0xdf09
                    DF0A    594 Ftest_radio_signal_rx$FREQ1$0$0 == 0xdf0a
                    DF0A    595 _FREQ1	=	0xdf0a
                    DF0B    596 Ftest_radio_signal_rx$FREQ0$0$0 == 0xdf0b
                    DF0B    597 _FREQ0	=	0xdf0b
                    DF0C    598 Ftest_radio_signal_rx$MDMCFG4$0$0 == 0xdf0c
                    DF0C    599 _MDMCFG4	=	0xdf0c
                    DF0D    600 Ftest_radio_signal_rx$MDMCFG3$0$0 == 0xdf0d
                    DF0D    601 _MDMCFG3	=	0xdf0d
                    DF0E    602 Ftest_radio_signal_rx$MDMCFG2$0$0 == 0xdf0e
                    DF0E    603 _MDMCFG2	=	0xdf0e
                    DF0F    604 Ftest_radio_signal_rx$MDMCFG1$0$0 == 0xdf0f
                    DF0F    605 _MDMCFG1	=	0xdf0f
                    DF10    606 Ftest_radio_signal_rx$MDMCFG0$0$0 == 0xdf10
                    DF10    607 _MDMCFG0	=	0xdf10
                    DF11    608 Ftest_radio_signal_rx$DEVIATN$0$0 == 0xdf11
                    DF11    609 _DEVIATN	=	0xdf11
                    DF12    610 Ftest_radio_signal_rx$MCSM2$0$0 == 0xdf12
                    DF12    611 _MCSM2	=	0xdf12
                    DF13    612 Ftest_radio_signal_rx$MCSM1$0$0 == 0xdf13
                    DF13    613 _MCSM1	=	0xdf13
                    DF14    614 Ftest_radio_signal_rx$MCSM0$0$0 == 0xdf14
                    DF14    615 _MCSM0	=	0xdf14
                    DF15    616 Ftest_radio_signal_rx$FOCCFG$0$0 == 0xdf15
                    DF15    617 _FOCCFG	=	0xdf15
                    DF16    618 Ftest_radio_signal_rx$BSCFG$0$0 == 0xdf16
                    DF16    619 _BSCFG	=	0xdf16
                    DF17    620 Ftest_radio_signal_rx$AGCCTRL2$0$0 == 0xdf17
                    DF17    621 _AGCCTRL2	=	0xdf17
                    DF18    622 Ftest_radio_signal_rx$AGCCTRL1$0$0 == 0xdf18
                    DF18    623 _AGCCTRL1	=	0xdf18
                    DF19    624 Ftest_radio_signal_rx$AGCCTRL0$0$0 == 0xdf19
                    DF19    625 _AGCCTRL0	=	0xdf19
                    DF1A    626 Ftest_radio_signal_rx$FREND1$0$0 == 0xdf1a
                    DF1A    627 _FREND1	=	0xdf1a
                    DF1B    628 Ftest_radio_signal_rx$FREND0$0$0 == 0xdf1b
                    DF1B    629 _FREND0	=	0xdf1b
                    DF1C    630 Ftest_radio_signal_rx$FSCAL3$0$0 == 0xdf1c
                    DF1C    631 _FSCAL3	=	0xdf1c
                    DF1D    632 Ftest_radio_signal_rx$FSCAL2$0$0 == 0xdf1d
                    DF1D    633 _FSCAL2	=	0xdf1d
                    DF1E    634 Ftest_radio_signal_rx$FSCAL1$0$0 == 0xdf1e
                    DF1E    635 _FSCAL1	=	0xdf1e
                    DF1F    636 Ftest_radio_signal_rx$FSCAL0$0$0 == 0xdf1f
                    DF1F    637 _FSCAL0	=	0xdf1f
                    DF23    638 Ftest_radio_signal_rx$TEST2$0$0 == 0xdf23
                    DF23    639 _TEST2	=	0xdf23
                    DF24    640 Ftest_radio_signal_rx$TEST1$0$0 == 0xdf24
                    DF24    641 _TEST1	=	0xdf24
                    DF25    642 Ftest_radio_signal_rx$TEST0$0$0 == 0xdf25
                    DF25    643 _TEST0	=	0xdf25
                    DF2E    644 Ftest_radio_signal_rx$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    645 _PA_TABLE0	=	0xdf2e
                    DF2F    646 Ftest_radio_signal_rx$IOCFG2$0$0 == 0xdf2f
                    DF2F    647 _IOCFG2	=	0xdf2f
                    DF30    648 Ftest_radio_signal_rx$IOCFG1$0$0 == 0xdf30
                    DF30    649 _IOCFG1	=	0xdf30
                    DF31    650 Ftest_radio_signal_rx$IOCFG0$0$0 == 0xdf31
                    DF31    651 _IOCFG0	=	0xdf31
                    DF36    652 Ftest_radio_signal_rx$PARTNUM$0$0 == 0xdf36
                    DF36    653 _PARTNUM	=	0xdf36
                    DF37    654 Ftest_radio_signal_rx$VERSION$0$0 == 0xdf37
                    DF37    655 _VERSION	=	0xdf37
                    DF38    656 Ftest_radio_signal_rx$FREQEST$0$0 == 0xdf38
                    DF38    657 _FREQEST	=	0xdf38
                    DF39    658 Ftest_radio_signal_rx$LQI$0$0 == 0xdf39
                    DF39    659 _LQI	=	0xdf39
                    DF3A    660 Ftest_radio_signal_rx$RSSI$0$0 == 0xdf3a
                    DF3A    661 _RSSI	=	0xdf3a
                    DF3B    662 Ftest_radio_signal_rx$MARCSTATE$0$0 == 0xdf3b
                    DF3B    663 _MARCSTATE	=	0xdf3b
                    DF3C    664 Ftest_radio_signal_rx$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    665 _PKTSTATUS	=	0xdf3c
                    DF3D    666 Ftest_radio_signal_rx$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    667 _VCO_VC_DAC	=	0xdf3d
                    DF40    668 Ftest_radio_signal_rx$I2SCFG0$0$0 == 0xdf40
                    DF40    669 _I2SCFG0	=	0xdf40
                    DF41    670 Ftest_radio_signal_rx$I2SCFG1$0$0 == 0xdf41
                    DF41    671 _I2SCFG1	=	0xdf41
                    DF42    672 Ftest_radio_signal_rx$I2SDATL$0$0 == 0xdf42
                    DF42    673 _I2SDATL	=	0xdf42
                    DF43    674 Ftest_radio_signal_rx$I2SDATH$0$0 == 0xdf43
                    DF43    675 _I2SDATH	=	0xdf43
                    DF44    676 Ftest_radio_signal_rx$I2SWCNT$0$0 == 0xdf44
                    DF44    677 _I2SWCNT	=	0xdf44
                    DF45    678 Ftest_radio_signal_rx$I2SSTAT$0$0 == 0xdf45
                    DF45    679 _I2SSTAT	=	0xdf45
                    DF46    680 Ftest_radio_signal_rx$I2SCLKF0$0$0 == 0xdf46
                    DF46    681 _I2SCLKF0	=	0xdf46
                    DF47    682 Ftest_radio_signal_rx$I2SCLKF1$0$0 == 0xdf47
                    DF47    683 _I2SCLKF1	=	0xdf47
                    DF48    684 Ftest_radio_signal_rx$I2SCLKF2$0$0 == 0xdf48
                    DF48    685 _I2SCLKF2	=	0xdf48
                    DE00    686 Ftest_radio_signal_rx$USBADDR$0$0 == 0xde00
                    DE00    687 _USBADDR	=	0xde00
                    DE01    688 Ftest_radio_signal_rx$USBPOW$0$0 == 0xde01
                    DE01    689 _USBPOW	=	0xde01
                    DE02    690 Ftest_radio_signal_rx$USBIIF$0$0 == 0xde02
                    DE02    691 _USBIIF	=	0xde02
                    DE04    692 Ftest_radio_signal_rx$USBOIF$0$0 == 0xde04
                    DE04    693 _USBOIF	=	0xde04
                    DE06    694 Ftest_radio_signal_rx$USBCIF$0$0 == 0xde06
                    DE06    695 _USBCIF	=	0xde06
                    DE07    696 Ftest_radio_signal_rx$USBIIE$0$0 == 0xde07
                    DE07    697 _USBIIE	=	0xde07
                    DE09    698 Ftest_radio_signal_rx$USBOIE$0$0 == 0xde09
                    DE09    699 _USBOIE	=	0xde09
                    DE0B    700 Ftest_radio_signal_rx$USBCIE$0$0 == 0xde0b
                    DE0B    701 _USBCIE	=	0xde0b
                    DE0C    702 Ftest_radio_signal_rx$USBFRML$0$0 == 0xde0c
                    DE0C    703 _USBFRML	=	0xde0c
                    DE0D    704 Ftest_radio_signal_rx$USBFRMH$0$0 == 0xde0d
                    DE0D    705 _USBFRMH	=	0xde0d
                    DE0E    706 Ftest_radio_signal_rx$USBINDEX$0$0 == 0xde0e
                    DE0E    707 _USBINDEX	=	0xde0e
                    DE10    708 Ftest_radio_signal_rx$USBMAXI$0$0 == 0xde10
                    DE10    709 _USBMAXI	=	0xde10
                    DE11    710 Ftest_radio_signal_rx$USBCSIL$0$0 == 0xde11
                    DE11    711 _USBCSIL	=	0xde11
                    DE12    712 Ftest_radio_signal_rx$USBCSIH$0$0 == 0xde12
                    DE12    713 _USBCSIH	=	0xde12
                    DE13    714 Ftest_radio_signal_rx$USBMAXO$0$0 == 0xde13
                    DE13    715 _USBMAXO	=	0xde13
                    DE14    716 Ftest_radio_signal_rx$USBCSOL$0$0 == 0xde14
                    DE14    717 _USBCSOL	=	0xde14
                    DE15    718 Ftest_radio_signal_rx$USBCSOH$0$0 == 0xde15
                    DE15    719 _USBCSOH	=	0xde15
                    DE16    720 Ftest_radio_signal_rx$USBCNTL$0$0 == 0xde16
                    DE16    721 _USBCNTL	=	0xde16
                    DE17    722 Ftest_radio_signal_rx$USBCNTH$0$0 == 0xde17
                    DE17    723 _USBCNTH	=	0xde17
                    DE20    724 Ftest_radio_signal_rx$USBF0$0$0 == 0xde20
                    DE20    725 _USBF0	=	0xde20
                    DE22    726 Ftest_radio_signal_rx$USBF1$0$0 == 0xde22
                    DE22    727 _USBF1	=	0xde22
                    DE24    728 Ftest_radio_signal_rx$USBF2$0$0 == 0xde24
                    DE24    729 _USBF2	=	0xde24
                    DE26    730 Ftest_radio_signal_rx$USBF3$0$0 == 0xde26
                    DE26    731 _USBF3	=	0xde26
                    DE28    732 Ftest_radio_signal_rx$USBF4$0$0 == 0xde28
                    DE28    733 _USBF4	=	0xde28
                    DE2A    734 Ftest_radio_signal_rx$USBF5$0$0 == 0xde2a
                    DE2A    735 _USBF5	=	0xde2a
                    0000    736 Ftest_radio_signal_rx$packet$0$0==.
   F048                     737 _packet:
   F048                     738 	.ds 19
                    0013    739 Ltest_radio_signal_rx.reportResults$report$4$4==.
   F05B                     740 _reportResults_report_4_4:
   F05B                     741 	.ds 64
                            742 ;--------------------------------------------------------
                            743 ; absolute external ram data
                            744 ;--------------------------------------------------------
                            745 	.area XABS    (ABS,XDATA)
                            746 ;--------------------------------------------------------
                            747 ; external initialized ram data
                            748 ;--------------------------------------------------------
                            749 	.area XISEG   (XDATA)
                            750 	.area HOME    (CODE)
                            751 	.area GSINIT0 (CODE)
                            752 	.area GSINIT1 (CODE)
                            753 	.area GSINIT2 (CODE)
                            754 	.area GSINIT3 (CODE)
                            755 	.area GSINIT4 (CODE)
                            756 	.area GSINIT5 (CODE)
                            757 	.area GSINIT  (CODE)
                            758 	.area GSFINAL (CODE)
                            759 	.area CSEG    (CODE)
                            760 ;--------------------------------------------------------
                            761 ; interrupt vector 
                            762 ;--------------------------------------------------------
                            763 	.area HOME    (CODE)
   0400                     764 __interrupt_vect:
   0400 02 04 6D            765 	ljmp	__sdcc_gsinit_startup
   0403 32                  766 	reti
   0404                     767 	.ds	7
   040B 32                  768 	reti
   040C                     769 	.ds	7
   0413 32                  770 	reti
   0414                     771 	.ds	7
   041B 32                  772 	reti
   041C                     773 	.ds	7
   0423 32                  774 	reti
   0424                     775 	.ds	7
   042B 32                  776 	reti
   042C                     777 	.ds	7
   0433 32                  778 	reti
   0434                     779 	.ds	7
   043B 32                  780 	reti
   043C                     781 	.ds	7
   0443 32                  782 	reti
   0444                     783 	.ds	7
   044B 32                  784 	reti
   044C                     785 	.ds	7
   0453 32                  786 	reti
   0454                     787 	.ds	7
   045B 32                  788 	reti
   045C                     789 	.ds	7
   0463 02 12 67            790 	ljmp	_ISR_T4
                            791 ;--------------------------------------------------------
                            792 ; global & static initialisations
                            793 ;--------------------------------------------------------
                            794 	.area HOME    (CODE)
                            795 	.area GSINIT  (CODE)
                            796 	.area GSFINAL (CODE)
                            797 	.area GSINIT  (CODE)
                            798 	.globl __sdcc_gsinit_startup
                            799 	.globl __sdcc_program_startup
                            800 	.globl __start__stack
                            801 	.globl __mcs51_genXINIT
                            802 	.globl __mcs51_genXRAMCLEAR
                            803 	.globl __mcs51_genRAMCLEAR
                    0000    804 	G$main$0$0 ==.
                    0000    805 	C$test_radio_signal_rx.c$44$1$1 ==.
                            806 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:44: static uint8 DATA currentBurstId = 0;
   04C6 75 08 00            807 	mov	_currentBurstId,#0x00
                    0003    808 	G$main$0$0 ==.
                    0003    809 	C$test_radio_signal_rx.c$45$1$1 ==.
                            810 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:45: static uint8 DATA packetsReceived = 0;
   04C9 75 09 00            811 	mov	_packetsReceived,#0x00
                    0006    812 	G$main$0$0 ==.
                    0006    813 	C$test_radio_signal_rx.c$46$1$1 ==.
                            814 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:46: static int16 DATA rssiSum = 0;
   04CC E4                  815 	clr	a
   04CD F5 0A               816 	mov	_rssiSum,a
   04CF F5 0B               817 	mov	(_rssiSum + 1),a
                    000B    818 	G$main$0$0 ==.
                    000B    819 	C$test_radio_signal_rx.c$47$1$1 ==.
                            820 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:47: static uint16 DATA lqiSum = 0;
   04D1 E4                  821 	clr	a
   04D2 F5 0C               822 	mov	_lqiSum,a
   04D4 F5 0D               823 	mov	(_lqiSum + 1),a
                    0010    824 	G$main$0$0 ==.
                    0010    825 	C$test_radio_signal_rx.c$48$1$1 ==.
                            826 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:48: static uint8 DATA crcErrors = 0;
   04D6 75 0E 00            827 	mov	_crcErrors,#0x00
                    0013    828 	G$main$0$0 ==.
                    0013    829 	C$test_radio_signal_rx.c$50$1$1 ==.
                            830 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:50: static uint16 lastPacketReceivedTime = 0;
   04D9 78 00               831 	mov	r0,#_lastPacketReceivedTime
   04DB E4                  832 	clr	a
   04DC F2                  833 	movx	@r0,a
   04DD 08                  834 	inc	r0
   04DE F2                  835 	movx	@r0,a
                            836 	.area GSFINAL (CODE)
   0509 02 04 66            837 	ljmp	__sdcc_program_startup
                            838 ;--------------------------------------------------------
                            839 ; Home
                            840 ;--------------------------------------------------------
                            841 	.area HOME    (CODE)
                            842 	.area HOME    (CODE)
   0466                     843 __sdcc_program_startup:
   0466 12 07 2E            844 	lcall	_main
                            845 ;	return from main will lock up
   0469 80 FE               846 	sjmp .
                            847 ;--------------------------------------------------------
                            848 ; code
                            849 ;--------------------------------------------------------
                            850 	.area CSEG    (CODE)
                            851 ;------------------------------------------------------------
                            852 ;Allocation info for local variables in function 'updateLeds'
                            853 ;------------------------------------------------------------
                    0000    854 	G$updateLeds$0$0 ==.
                    0000    855 	C$test_radio_signal_rx.c$52$0$0 ==.
                            856 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:52: void updateLeds()
                            857 ;	-----------------------------------------
                            858 ;	 function updateLeds
                            859 ;	-----------------------------------------
   050C                     860 _updateLeds:
                    0007    861 	ar7 = 0x07
                    0006    862 	ar6 = 0x06
                    0005    863 	ar5 = 0x05
                    0004    864 	ar4 = 0x04
                    0003    865 	ar3 = 0x03
                    0002    866 	ar2 = 0x02
                    0001    867 	ar1 = 0x01
                    0000    868 	ar0 = 0x00
                    0000    869 	C$test_radio_signal_rx.c$54$1$1 ==.
                            870 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:54: usbShowStatusWithGreenLed();
   050C 12 14 6D            871 	lcall	_usbShowStatusWithGreenLed
                    0003    872 	C$test_radio_signal_rx.c$57$2$2 ==.
                            873 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:57: LED_YELLOW(packetsReceived > 0);
   050F E5 09               874 	mov	a,_packetsReceived
   0511 60 05               875 	jz	00103$
   0513 43 FF 04            876 	orl	_P2DIR,#0x04
   0516 80 07               877 	sjmp	00104$
   0518                     878 00103$:
   0518 AF FF               879 	mov	r7,_P2DIR
   051A 53 07 FB            880 	anl	ar7,#0xFB
   051D 8F FF               881 	mov	_P2DIR,r7
   051F                     882 00104$:
                    0013    883 	C$test_radio_signal_rx.c$59$2$3 ==.
                            884 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:59: LED_RED(0);
   051F AF FF               885 	mov	r7,_P2DIR
   0521 53 07 FD            886 	anl	ar7,#0xFD
   0524 8F FF               887 	mov	_P2DIR,r7
                    001A    888 	C$test_radio_signal_rx.c$60$2$3 ==.
                    001A    889 	XG$updateLeds$0$0 ==.
   0526 22                  890 	ret
                            891 ;------------------------------------------------------------
                            892 ;Allocation info for local variables in function 'perTestRxInit'
                            893 ;------------------------------------------------------------
                    001B    894 	G$perTestRxInit$0$0 ==.
                    001B    895 	C$test_radio_signal_rx.c$62$2$3 ==.
                            896 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:62: void perTestRxInit()
                            897 ;	-----------------------------------------
                            898 ;	 function perTestRxInit
                            899 ;	-----------------------------------------
   0527                     900 _perTestRxInit:
                    001B    901 	C$test_radio_signal_rx.c$64$1$1 ==.
                            902 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:64: radioRegistersInit();
   0527 12 07 9D            903 	lcall	_radioRegistersInit
                    001E    904 	C$test_radio_signal_rx.c$66$1$1 ==.
                            905 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:66: CHANNR = param_radio_channel;
   052A 90 1C 74            906 	mov	dptr,#_param_radio_channel
   052D E4                  907 	clr	a
   052E 93                  908 	movc	a,@a+dptr
   052F FC                  909 	mov	r4,a
   0530 74 01               910 	mov	a,#0x01
   0532 93                  911 	movc	a,@a+dptr
   0533 74 02               912 	mov	a,#0x02
   0535 93                  913 	movc	a,@a+dptr
   0536 74 03               914 	mov	a,#0x03
   0538 93                  915 	movc	a,@a+dptr
   0539 90 DF 06            916 	mov	dptr,#_CHANNR
   053C EC                  917 	mov	a,r4
   053D F0                  918 	movx	@dptr,a
                    0032    919 	C$test_radio_signal_rx.c$68$1$1 ==.
                            920 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:68: PKTLEN = RADIO_PACKET_SIZE;
   053E 90 DF 02            921 	mov	dptr,#_PKTLEN
   0541 74 10               922 	mov	a,#0x10
   0543 F0                  923 	movx	@dptr,a
                    0038    924 	C$test_radio_signal_rx.c$70$1$1 ==.
                            925 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:70: MCSM0 = 0x14;    // Auto-calibrate when going from idle to RX or TX.
   0544 90 DF 14            926 	mov	dptr,#_MCSM0
   0547 74 14               927 	mov	a,#0x14
   0549 F0                  928 	movx	@dptr,a
                    003E    929 	C$test_radio_signal_rx.c$71$1$1 ==.
                            930 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:71: MCSM1 = 0x00;    // Disable CCA.  After RX, go to IDLE.  After TX, go to IDLE.
   054A 90 DF 13            931 	mov	dptr,#_MCSM1
   054D E4                  932 	clr	a
   054E F0                  933 	movx	@dptr,a
                    0043    934 	C$test_radio_signal_rx.c$74$1$1 ==.
                            935 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:74: dmaConfig.radio.DC6 = 19; // WORDSIZE = 0, TMODE = 0, TRIG = 19
   054F 90 F0 AE            936 	mov	dptr,#(_dmaConfig + 0x0006)
   0552 74 13               937 	mov	a,#0x13
   0554 F0                  938 	movx	@dptr,a
                    0049    939 	C$test_radio_signal_rx.c$76$1$1 ==.
                            940 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:76: dmaConfig.radio.SRCADDRH = XDATA_SFR_ADDRESS(RFD) >> 8;
   0555 7E D9               941 	mov	r6,#_RFD
   0557 7F 00               942 	mov	r7,#0x00
   0559 74 DF               943 	mov	a,#0xDF
   055B 2F                  944 	add	a,r7
   055C FE                  945 	mov	r6,a
   055D 90 F0 A8            946 	mov	dptr,#_dmaConfig
   0560 EE                  947 	mov	a,r6
   0561 F0                  948 	movx	@dptr,a
                    0056    949 	C$test_radio_signal_rx.c$77$1$1 ==.
                            950 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:77: dmaConfig.radio.SRCADDRL = XDATA_SFR_ADDRESS(RFD);
   0562 7E D9               951 	mov	r6,#_RFD
   0564 90 F0 A9            952 	mov	dptr,#(_dmaConfig + 0x0001)
   0567 EE                  953 	mov	a,r6
   0568 F0                  954 	movx	@dptr,a
                    005D    955 	C$test_radio_signal_rx.c$78$1$1 ==.
                            956 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:78: dmaConfig.radio.DESTADDRH = (unsigned int)packet >> 8;
   0569 7E 48               957 	mov	r6,#_packet
   056B 7F F0               958 	mov	r7,#(_packet >> 8)
   056D 8F 06               959 	mov	ar6,r7
   056F 90 F0 AA            960 	mov	dptr,#(_dmaConfig + 0x0002)
   0572 EE                  961 	mov	a,r6
   0573 F0                  962 	movx	@dptr,a
                    0068    963 	C$test_radio_signal_rx.c$79$1$1 ==.
                            964 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:79: dmaConfig.radio.DESTADDRL = (unsigned int)packet;
   0574 7E 48               965 	mov	r6,#_packet
   0576 7F F0               966 	mov	r7,#(_packet >> 8)
   0578 90 F0 AB            967 	mov	dptr,#(_dmaConfig + 0x0003)
   057B EE                  968 	mov	a,r6
   057C F0                  969 	movx	@dptr,a
                    0071    970 	C$test_radio_signal_rx.c$80$1$1 ==.
                            971 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:80: dmaConfig.radio.LENL = 1 + PKTLEN + 2;
   057D 90 DF 02            972 	mov	dptr,#_PKTLEN
   0580 E0                  973 	movx	a,@dptr
   0581 FF                  974 	mov	r7,a
   0582 0F                  975 	inc	r7
   0583 0F                  976 	inc	r7
   0584 0F                  977 	inc	r7
   0585 90 F0 AD            978 	mov	dptr,#(_dmaConfig + 0x0005)
   0588 EF                  979 	mov	a,r7
   0589 F0                  980 	movx	@dptr,a
                    007E    981 	C$test_radio_signal_rx.c$81$1$1 ==.
                            982 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:81: dmaConfig.radio.VLEN_LENH = 0b10000000; // Transfer length is FirstByte+3
   058A 90 F0 AC            983 	mov	dptr,#(_dmaConfig + 0x0004)
   058D 74 80               984 	mov	a,#0x80
   058F F0                  985 	movx	@dptr,a
                    0084    986 	C$test_radio_signal_rx.c$82$1$1 ==.
                            987 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:82: dmaConfig.radio.DC7 = 0x10; // SRCINC = 0, DESTINC = 1, IRQMASK = 0, M8 = 0, PRIORITY = 0
   0590 90 F0 AF            988 	mov	dptr,#(_dmaConfig + 0x0007)
   0593 74 10               989 	mov	a,#0x10
   0595 F0                  990 	movx	@dptr,a
                    008A    991 	C$test_radio_signal_rx.c$84$1$1 ==.
                            992 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:84: DMAARM |= (1<<DMA_CHANNEL_RADIO);  // Arm DMA channel
   0596 43 D6 02            993 	orl	_DMAARM,#0x02
                    008D    994 	C$test_radio_signal_rx.c$85$1$1 ==.
                            995 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:85: RFST = 2;                          // Switch radio to RX mode.
   0599 75 E1 02            996 	mov	_RFST,#0x02
                    0090    997 	C$test_radio_signal_rx.c$86$1$1 ==.
                    0090    998 	XG$perTestRxInit$0$0 ==.
   059C 22                  999 	ret
                           1000 ;------------------------------------------------------------
                           1001 ;Allocation info for local variables in function 'receiveRadioBursts'
                           1002 ;------------------------------------------------------------
                    0091   1003 	G$receiveRadioBursts$0$0 ==.
                    0091   1004 	C$test_radio_signal_rx.c$89$1$1 ==.
                           1005 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:89: void receiveRadioBursts()
                           1006 ;	-----------------------------------------
                           1007 ;	 function receiveRadioBursts
                           1008 ;	-----------------------------------------
   059D                    1009 _receiveRadioBursts:
                    0091   1010 	C$test_radio_signal_rx.c$91$1$1 ==.
                           1011 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:91: if (RFIF & (1<<4))
   059D E5 E9              1012 	mov	a,_RFIF
   059F 30 E4 68           1013 	jnb	acc.4,00108$
                    0096   1014 	C$test_radio_signal_rx.c$93$2$2 ==.
                           1015 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:93: if (radioCrcPassed())
   05A2 12 08 3C           1016 	lcall	_radioCrcPassed
   05A5 50 54              1017 	jnc	00104$
                    009B   1018 	C$test_radio_signal_rx.c$95$3$3 ==.
                           1019 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:95: if (packet[2] != currentBurstId)
   05A7 90 F0 4A           1020 	mov	dptr,#(_packet + 0x0002)
   05AA E0                 1021 	movx	a,@dptr
   05AB FF                 1022 	mov	r7,a
   05AC B5 08 02           1023 	cjne	a,_currentBurstId,00115$
   05AF 80 13              1024 	sjmp	00102$
   05B1                    1025 00115$:
                    00A5   1026 	C$test_radio_signal_rx.c$97$4$4 ==.
                           1027 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:97: currentBurstId = packet[2];
   05B1 90 F0 4A           1028 	mov	dptr,#(_packet + 0x0002)
   05B4 E0                 1029 	movx	a,@dptr
   05B5 F5 08              1030 	mov	_currentBurstId,a
                    00AB   1031 	C$test_radio_signal_rx.c$99$4$4 ==.
                           1032 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:99: packetsReceived = 0;
                    00AB   1033 	C$test_radio_signal_rx.c$100$4$4 ==.
                           1034 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:100: rssiSum = 0;
                    00AB   1035 	C$test_radio_signal_rx.c$101$4$4 ==.
                           1036 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:101: lqiSum = 0;
                    00AB   1037 	C$test_radio_signal_rx.c$102$4$4 ==.
                           1038 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:102: crcErrors = 0;
   05B7 E4                 1039 	clr a
   05B8 F5 09              1040 	mov _packetsReceived,a
   05BA F5 0A              1041 	mov _rssiSum,a
   05BC F5 0B              1042 	mov (_rssiSum + 1),a
   05BE F5 0C              1043 	mov _lqiSum,a
   05C0 F5 0D              1044 	mov (_lqiSum + 1),a
   05C2 F5 0E              1045 	mov _crcErrors,a
   05C4                    1046 00102$:
                    00B8   1047 	C$test_radio_signal_rx.c$105$3$3 ==.
                           1048 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:105: lastPacketReceivedTime = (uint16)getMs();
   05C4 12 12 8C           1049 	lcall	_getMs
   05C7 AC 82              1050 	mov	r4,dpl
   05C9 AD 83              1051 	mov	r5,dph
   05CB 78 00              1052 	mov	r0,#_lastPacketReceivedTime
   05CD EC                 1053 	mov	a,r4
   05CE F2                 1054 	movx	@r0,a
   05CF 08                 1055 	inc	r0
   05D0 ED                 1056 	mov	a,r5
   05D1 F2                 1057 	movx	@r0,a
                    00C6   1058 	C$test_radio_signal_rx.c$106$3$3 ==.
                           1059 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:106: packetsReceived ++;
   05D2 05 09              1060 	inc	_packetsReceived
                    00C8   1061 	C$test_radio_signal_rx.c$107$3$3 ==.
                           1062 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:107: rssiSum += radioRssi();
   05D4 12 08 51           1063 	lcall	_radioRssi
   05D7 E5 82              1064 	mov	a,dpl
   05D9 FF                 1065 	mov	r7,a
   05DA 33                 1066 	rlc	a
   05DB 95 E0              1067 	subb	a,acc
   05DD FE                 1068 	mov	r6,a
   05DE EF                 1069 	mov	a,r7
   05DF 25 0A              1070 	add	a,_rssiSum
   05E1 F5 0A              1071 	mov	_rssiSum,a
   05E3 EE                 1072 	mov	a,r6
   05E4 35 0B              1073 	addc	a,(_rssiSum + 1)
   05E6 F5 0B              1074 	mov	(_rssiSum + 1),a
                    00DC   1075 	C$test_radio_signal_rx.c$108$3$3 ==.
                           1076 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:108: lqiSum += radioLqi();
   05E8 12 08 46           1077 	lcall	_radioLqi
   05EB AF 82              1078 	mov	r7,dpl
   05ED 7E 00              1079 	mov	r6,#0x00
   05EF EF                 1080 	mov	a,r7
   05F0 25 0C              1081 	add	a,_lqiSum
   05F2 F5 0C              1082 	mov	_lqiSum,a
   05F4 EE                 1083 	mov	a,r6
   05F5 35 0D              1084 	addc	a,(_lqiSum + 1)
   05F7 F5 0D              1085 	mov	(_lqiSum + 1),a
   05F9 80 02              1086 	sjmp	00105$
   05FB                    1087 00104$:
                    00EF   1088 	C$test_radio_signal_rx.c$112$3$5 ==.
                           1089 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:112: crcErrors ++;
   05FB 05 0E              1090 	inc	_crcErrors
   05FD                    1091 00105$:
                    00F1   1092 	C$test_radio_signal_rx.c$115$2$2 ==.
                           1093 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:115: RFIF &= ~(1<<4);                   // Clear IRQ_DONE
   05FD AF E9              1094 	mov	r7,_RFIF
   05FF 53 07 EF           1095 	anl	ar7,#0xEF
   0602 8F E9              1096 	mov	_RFIF,r7
                    00F8   1097 	C$test_radio_signal_rx.c$116$2$2 ==.
                           1098 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:116: DMAARM |= (1<<DMA_CHANNEL_RADIO);  // Arm DMA channel
   0604 43 D6 02           1099 	orl	_DMAARM,#0x02
                    00FB   1100 	C$test_radio_signal_rx.c$117$2$2 ==.
                           1101 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:117: RFST = 2;                          // Switch radio to RX mode.
   0607 75 E1 02           1102 	mov	_RFST,#0x02
   060A                    1103 00108$:
                    00FE   1104 	C$test_radio_signal_rx.c$119$2$1 ==.
                    00FE   1105 	XG$receiveRadioBursts$0$0 ==.
   060A 22                 1106 	ret
                           1107 ;------------------------------------------------------------
                           1108 ;Allocation info for local variables in function 'reportResults'
                           1109 ;------------------------------------------------------------
                           1110 ;sloc0                     Allocated with name '_reportResults_sloc0_1_0'
                           1111 ;report                    Allocated with name '_reportResults_report_4_4'
                           1112 ;------------------------------------------------------------
                    00FF   1113 	G$reportResults$0$0 ==.
                    00FF   1114 	C$test_radio_signal_rx.c$121$2$1 ==.
                           1115 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:121: void reportResults()
                           1116 ;	-----------------------------------------
                           1117 ;	 function reportResults
                           1118 ;	-----------------------------------------
   060B                    1119 _reportResults:
                    00FF   1120 	C$test_radio_signal_rx.c$125$1$1 ==.
                           1121 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:125: if (usbComTxAvailable() >= 64)
   060B 12 0A 69           1122 	lcall	_usbComTxAvailable
   060E AF 82              1123 	mov	r7,dpl
   0610 BF 40 00           1124 	cjne	r7,#0x40,00116$
   0613                    1125 00116$:
   0613 50 03              1126 	jnc	00117$
   0615 02 07 2D           1127 	ljmp	00110$
   0618                    1128 00117$:
                    010C   1129 	C$test_radio_signal_rx.c$127$2$2 ==.
                           1130 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:127: if (packetsReceived)
   0618 E5 09              1131 	mov	a,_packetsReceived
   061A 70 03              1132 	jnz	00118$
   061C 02 06 DF           1133 	ljmp	00106$
   061F                    1134 00118$:
                    0113   1135 	C$test_radio_signal_rx.c$129$3$3 ==.
                           1136 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:129: if ((uint16)(getMs() - lastPacketReceivedTime) >= 300)
   061F 12 12 8C           1137 	lcall	_getMs
   0622 85 82 0F           1138 	mov	_reportResults_sloc0_1_0,dpl
   0625 85 83 10           1139 	mov	(_reportResults_sloc0_1_0 + 1),dph
   0628 85 F0 11           1140 	mov	(_reportResults_sloc0_1_0 + 2),b
   062B F5 12              1141 	mov	(_reportResults_sloc0_1_0 + 3),a
   062D 78 00              1142 	mov	r0,#_lastPacketReceivedTime
   062F E2                 1143 	movx	a,@r0
   0630 FA                 1144 	mov	r2,a
   0631 08                 1145 	inc	r0
   0632 E2                 1146 	movx	a,@r0
   0633 FB                 1147 	mov	r3,a
   0634 E4                 1148 	clr	a
   0635 FE                 1149 	mov	r6,a
   0636 FF                 1150 	mov	r7,a
   0637 E5 0F              1151 	mov	a,_reportResults_sloc0_1_0
   0639 C3                 1152 	clr	c
   063A 9A                 1153 	subb	a,r2
   063B FA                 1154 	mov	r2,a
   063C E5 10              1155 	mov	a,(_reportResults_sloc0_1_0 + 1)
   063E 9B                 1156 	subb	a,r3
   063F FB                 1157 	mov	r3,a
   0640 E5 11              1158 	mov	a,(_reportResults_sloc0_1_0 + 2)
   0642 9E                 1159 	subb	a,r6
   0643 FE                 1160 	mov	r6,a
   0644 E5 12              1161 	mov	a,(_reportResults_sloc0_1_0 + 3)
   0646 9F                 1162 	subb	a,r7
   0647 FF                 1163 	mov	r7,a
   0648 C3                 1164 	clr	c
   0649 EA                 1165 	mov	a,r2
   064A 94 2C              1166 	subb	a,#0x2C
   064C EB                 1167 	mov	a,r3
   064D 94 01              1168 	subb	a,#0x01
   064F 50 03              1169 	jnc	00119$
   0651 02 07 2D           1170 	ljmp	00110$
   0654                    1171 00119$:
                    0148   1172 	C$test_radio_signal_rx.c$132$4$4 ==.
                           1173 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:132: uint8 reportLength = sprintf(report, "%3d, %5d, %5d\r\n", packetsReceived, rssiSum/packetsReceived, lqiSum/packetsReceived);
   0654 78 04              1174 	mov	r0,#__divuint_PARM_2
   0656 E5 09              1175 	mov	a,_packetsReceived
   0658 F2                 1176 	movx	@r0,a
   0659 08                 1177 	inc	r0
   065A E4                 1178 	clr	a
   065B F2                 1179 	movx	@r0,a
   065C 85 0C 82           1180 	mov	dpl,_lqiSum
   065F 85 0D 83           1181 	mov	dph,(_lqiSum + 1)
   0662 12 07 4C           1182 	lcall	__divuint
   0665 AE 82              1183 	mov	r6,dpl
   0667 AF 83              1184 	mov	r7,dph
   0669 AC 09              1185 	mov	r4,_packetsReceived
   066B 7D 00              1186 	mov	r5,#0x00
   066D 78 20              1187 	mov	r0,#__divsint_PARM_2
   066F EC                 1188 	mov	a,r4
   0670 F2                 1189 	movx	@r0,a
   0671 08                 1190 	inc	r0
   0672 ED                 1191 	mov	a,r5
   0673 F2                 1192 	movx	@r0,a
   0674 85 0A 82           1193 	mov	dpl,_rssiSum
   0677 85 0B 83           1194 	mov	dph,(_rssiSum + 1)
   067A C0 07              1195 	push	ar7
   067C C0 06              1196 	push	ar6
   067E C0 05              1197 	push	ar5
   0680 C0 04              1198 	push	ar4
   0682 12 12 EC           1199 	lcall	__divsint
   0685 AA 82              1200 	mov	r2,dpl
   0687 AB 83              1201 	mov	r3,dph
   0689 D0 04              1202 	pop	ar4
   068B D0 05              1203 	pop	ar5
   068D D0 06              1204 	pop	ar6
   068F D0 07              1205 	pop	ar7
   0691 C0 06              1206 	push	ar6
   0693 C0 07              1207 	push	ar7
   0695 C0 02              1208 	push	ar2
   0697 C0 03              1209 	push	ar3
   0699 C0 04              1210 	push	ar4
   069B C0 05              1211 	push	ar5
   069D 74 78              1212 	mov	a,#__str_0
   069F C0 E0              1213 	push	acc
   06A1 74 1C              1214 	mov	a,#(__str_0 >> 8)
   06A3 C0 E0              1215 	push	acc
   06A5 74 80              1216 	mov	a,#0x80
   06A7 C0 E0              1217 	push	acc
   06A9 74 5B              1218 	mov	a,#_reportResults_report_4_4
   06AB C0 E0              1219 	push	acc
   06AD 74 F0              1220 	mov	a,#(_reportResults_report_4_4 >> 8)
   06AF C0 E0              1221 	push	acc
   06B1 E4                 1222 	clr	a
   06B2 C0 E0              1223 	push	acc
   06B4 12 14 1A           1224 	lcall	_sprintf
   06B7 AE 82              1225 	mov	r6,dpl
   06B9 E5 81              1226 	mov	a,sp
   06BB 24 F4              1227 	add	a,#0xf4
   06BD F5 81              1228 	mov	sp,a
   06BF 78 0C              1229 	mov	r0,#_usbComTxSend_PARM_2
   06C1 EE                 1230 	mov	a,r6
   06C2 F2                 1231 	movx	@r0,a
                    01B7   1232 	C$test_radio_signal_rx.c$133$4$4 ==.
                           1233 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:133: usbComTxSend(report, reportLength);
   06C3 90 F0 5B           1234 	mov	dptr,#_reportResults_report_4_4
   06C6 12 0A A0           1235 	lcall	_usbComTxSend
                    01BD   1236 	C$test_radio_signal_rx.c$135$4$4 ==.
                           1237 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:135: lastReportSentTime = (uint16)getMs();
   06C9 12 12 8C           1238 	lcall	_getMs
   06CC AC 82              1239 	mov	r4,dpl
   06CE AD 83              1240 	mov	r5,dph
   06D0 AE F0              1241 	mov	r6,b
   06D2 FF                 1242 	mov	r7,a
   06D3 78 02              1243 	mov	r0,#_reportResults_lastReportSentTime_1_1
   06D5 EC                 1244 	mov	a,r4
   06D6 F2                 1245 	movx	@r0,a
   06D7 08                 1246 	inc	r0
   06D8 ED                 1247 	mov	a,r5
   06D9 F2                 1248 	movx	@r0,a
                    01CE   1249 	C$test_radio_signal_rx.c$136$4$4 ==.
                           1250 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:136: packetsReceived = 0;
   06DA 75 09 00           1251 	mov	_packetsReceived,#0x00
   06DD 80 4E              1252 	sjmp	00110$
   06DF                    1253 00106$:
                    01D3   1254 	C$test_radio_signal_rx.c$141$3$5 ==.
                           1255 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:141: if ((uint16)(getMs() - lastReportSentTime) >= 1100)
   06DF 12 12 8C           1256 	lcall	_getMs
   06E2 85 82 0F           1257 	mov	_reportResults_sloc0_1_0,dpl
   06E5 85 83 10           1258 	mov	(_reportResults_sloc0_1_0 + 1),dph
   06E8 85 F0 11           1259 	mov	(_reportResults_sloc0_1_0 + 2),b
   06EB F5 12              1260 	mov	(_reportResults_sloc0_1_0 + 3),a
   06ED 78 02              1261 	mov	r0,#_reportResults_lastReportSentTime_1_1
   06EF E2                 1262 	movx	a,@r0
   06F0 FA                 1263 	mov	r2,a
   06F1 08                 1264 	inc	r0
   06F2 E2                 1265 	movx	a,@r0
   06F3 FB                 1266 	mov	r3,a
   06F4 E4                 1267 	clr	a
   06F5 FE                 1268 	mov	r6,a
   06F6 FF                 1269 	mov	r7,a
   06F7 E5 0F              1270 	mov	a,_reportResults_sloc0_1_0
   06F9 C3                 1271 	clr	c
   06FA 9A                 1272 	subb	a,r2
   06FB FA                 1273 	mov	r2,a
   06FC E5 10              1274 	mov	a,(_reportResults_sloc0_1_0 + 1)
   06FE 9B                 1275 	subb	a,r3
   06FF FB                 1276 	mov	r3,a
   0700 E5 11              1277 	mov	a,(_reportResults_sloc0_1_0 + 2)
   0702 9E                 1278 	subb	a,r6
   0703 FE                 1279 	mov	r6,a
   0704 E5 12              1280 	mov	a,(_reportResults_sloc0_1_0 + 3)
   0706 9F                 1281 	subb	a,r7
   0707 FF                 1282 	mov	r7,a
   0708 C3                 1283 	clr	c
   0709 EA                 1284 	mov	a,r2
   070A 94 4C              1285 	subb	a,#0x4C
   070C EB                 1286 	mov	a,r3
   070D 94 04              1287 	subb	a,#0x04
   070F 40 1C              1288 	jc	00110$
                    0205   1289 	C$test_radio_signal_rx.c$144$4$6 ==.
                           1290 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:144: usbComTxSend((uint8 XDATA *)noSignal, sizeof(noSignal));
   0711 90 1C 88           1291 	mov	dptr,#_reportResults_noSignal_4_6
   0714 78 0C              1292 	mov	r0,#_usbComTxSend_PARM_2
   0716 74 14              1293 	mov	a,#0x14
   0718 F2                 1294 	movx	@r0,a
   0719 12 0A A0           1295 	lcall	_usbComTxSend
                    0210   1296 	C$test_radio_signal_rx.c$145$4$6 ==.
                           1297 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:145: lastReportSentTime = (uint16)getMs();
   071C 12 12 8C           1298 	lcall	_getMs
   071F AC 82              1299 	mov	r4,dpl
   0721 AD 83              1300 	mov	r5,dph
   0723 AE F0              1301 	mov	r6,b
   0725 FF                 1302 	mov	r7,a
   0726 78 02              1303 	mov	r0,#_reportResults_lastReportSentTime_1_1
   0728 EC                 1304 	mov	a,r4
   0729 F2                 1305 	movx	@r0,a
   072A 08                 1306 	inc	r0
   072B ED                 1307 	mov	a,r5
   072C F2                 1308 	movx	@r0,a
   072D                    1309 00110$:
                    0221   1310 	C$test_radio_signal_rx.c$149$2$1 ==.
                    0221   1311 	XG$reportResults$0$0 ==.
   072D 22                 1312 	ret
                           1313 ;------------------------------------------------------------
                           1314 ;Allocation info for local variables in function 'main'
                           1315 ;------------------------------------------------------------
                    0222   1316 	G$main$0$0 ==.
                    0222   1317 	C$test_radio_signal_rx.c$151$2$1 ==.
                           1318 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:151: void main()
                           1319 ;	-----------------------------------------
                           1320 ;	 function main
                           1321 ;	-----------------------------------------
   072E                    1322 _main:
                    0222   1323 	C$test_radio_signal_rx.c$153$1$1 ==.
                           1324 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:153: systemInit();
   072E 12 11 8C           1325 	lcall	_systemInit
                    0225   1326 	C$test_radio_signal_rx.c$154$1$1 ==.
                           1327 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:154: usbInit();
   0731 12 0B 26           1328 	lcall	_usbInit
                    0228   1329 	C$test_radio_signal_rx.c$155$1$1 ==.
                           1330 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:155: perTestRxInit();
   0734 12 05 27           1331 	lcall	_perTestRxInit
                    022B   1332 	C$test_radio_signal_rx.c$156$1$1 ==.
                           1333 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:156: usbInit();
   0737 12 0B 26           1334 	lcall	_usbInit
                    022E   1335 	C$test_radio_signal_rx.c$158$1$1 ==.
                           1336 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:158: while(1)
   073A                    1337 00102$:
                    022E   1338 	C$test_radio_signal_rx.c$160$2$2 ==.
                           1339 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:160: boardService();
   073A 12 11 99           1340 	lcall	_boardService
                    0231   1341 	C$test_radio_signal_rx.c$161$2$2 ==.
                           1342 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:161: usbComService();
   073D 12 09 C4           1343 	lcall	_usbComService
                    0234   1344 	C$test_radio_signal_rx.c$162$2$2 ==.
                           1345 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:162: updateLeds();
   0740 12 05 0C           1346 	lcall	_updateLeds
                    0237   1347 	C$test_radio_signal_rx.c$163$2$2 ==.
                           1348 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:163: receiveRadioBursts();
   0743 12 05 9D           1349 	lcall	_receiveRadioBursts
                    023A   1350 	C$test_radio_signal_rx.c$164$2$2 ==.
                           1351 ;	apps/test_radio_signal_rx/test_radio_signal_rx.c:164: reportResults();
   0746 12 06 0B           1352 	lcall	_reportResults
   0749 80 EF              1353 	sjmp	00102$
                    023F   1354 	C$test_radio_signal_rx.c$166$1$1 ==.
                    023F   1355 	XG$main$0$0 ==.
   074B 22                 1356 	ret
                           1357 	.area CSEG    (CODE)
                           1358 	.area CONST   (CODE)
                    0000   1359 G$param_radio_channel$0$0 == .
   1C74                    1360 _param_radio_channel:
   1C74 80 00 00 00        1361 	.byte #0x80,#0x00,#0x00,#0x00	;  128
                    0004   1362 Ftest_radio_signal_rx$_str_0$0$0 == .
   1C78                    1363 __str_0:
   1C78 25 33 64 2C 20 25  1364 	.ascii "%3d, %5d, %5d"
        35 64 2C 20 25 35
        64
   1C85 0D                 1365 	.db 0x0D
   1C86 0A                 1366 	.db 0x0A
   1C87 00                 1367 	.db 0x00
                    0014   1368 Ltest_radio_signal_rx.reportResults$noSignal$4$6 == .
   1C88                    1369 _reportResults_noSignal_4_6:
   1C88 20 20 30 2C 20 20  1370 	.ascii "  0,     0,     0"
        20 20 20 30 2C 20
        20 20 20 20 30
   1C99 0D                 1371 	.db 0x0D
   1C9A 0A                 1372 	.db 0x0A
   1C9B 00                 1373 	.db 0x00
                           1374 	.area XINIT   (CODE)
                           1375 	.area CABS    (ABS,CODE)
