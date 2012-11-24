                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:12 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_radio_signal_tx
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_radio_channel
                             13 	.globl _main
                             14 	.globl _sendRadioBursts
                             15 	.globl _perTestTxInit
                             16 	.globl _updateLeds
                             17 	.globl _usbComService
                             18 	.globl _usbShowStatusWithGreenLed
                             19 	.globl _usbInit
                             20 	.globl _radioRegistersInit
                             21 	.globl _getMs
                             22 	.globl _boardService
                             23 	.globl _systemInit
                             24 ;--------------------------------------------------------
                             25 ; special function registers
                             26 ;--------------------------------------------------------
                             27 	.area RSEG    (ABS,DATA)
   0000                      28 	.org 0x0000
                    0080     29 Ftest_radio_signal_tx$P0$0$0 == 0x0080
                    0080     30 _P0	=	0x0080
                    0081     31 Ftest_radio_signal_tx$SP$0$0 == 0x0081
                    0081     32 _SP	=	0x0081
                    0082     33 Ftest_radio_signal_tx$DPL0$0$0 == 0x0082
                    0082     34 _DPL0	=	0x0082
                    0083     35 Ftest_radio_signal_tx$DPH0$0$0 == 0x0083
                    0083     36 _DPH0	=	0x0083
                    0084     37 Ftest_radio_signal_tx$DPL1$0$0 == 0x0084
                    0084     38 _DPL1	=	0x0084
                    0085     39 Ftest_radio_signal_tx$DPH1$0$0 == 0x0085
                    0085     40 _DPH1	=	0x0085
                    0086     41 Ftest_radio_signal_tx$U0CSR$0$0 == 0x0086
                    0086     42 _U0CSR	=	0x0086
                    0087     43 Ftest_radio_signal_tx$PCON$0$0 == 0x0087
                    0087     44 _PCON	=	0x0087
                    0088     45 Ftest_radio_signal_tx$TCON$0$0 == 0x0088
                    0088     46 _TCON	=	0x0088
                    0089     47 Ftest_radio_signal_tx$P0IFG$0$0 == 0x0089
                    0089     48 _P0IFG	=	0x0089
                    008A     49 Ftest_radio_signal_tx$P1IFG$0$0 == 0x008a
                    008A     50 _P1IFG	=	0x008a
                    008B     51 Ftest_radio_signal_tx$P2IFG$0$0 == 0x008b
                    008B     52 _P2IFG	=	0x008b
                    008C     53 Ftest_radio_signal_tx$PICTL$0$0 == 0x008c
                    008C     54 _PICTL	=	0x008c
                    008D     55 Ftest_radio_signal_tx$P1IEN$0$0 == 0x008d
                    008D     56 _P1IEN	=	0x008d
                    008F     57 Ftest_radio_signal_tx$P0INP$0$0 == 0x008f
                    008F     58 _P0INP	=	0x008f
                    0090     59 Ftest_radio_signal_tx$P1$0$0 == 0x0090
                    0090     60 _P1	=	0x0090
                    0091     61 Ftest_radio_signal_tx$RFIM$0$0 == 0x0091
                    0091     62 _RFIM	=	0x0091
                    0092     63 Ftest_radio_signal_tx$DPS$0$0 == 0x0092
                    0092     64 _DPS	=	0x0092
                    0093     65 Ftest_radio_signal_tx$MPAGE$0$0 == 0x0093
                    0093     66 _MPAGE	=	0x0093
                    0095     67 Ftest_radio_signal_tx$ENDIAN$0$0 == 0x0095
                    0095     68 _ENDIAN	=	0x0095
                    0098     69 Ftest_radio_signal_tx$S0CON$0$0 == 0x0098
                    0098     70 _S0CON	=	0x0098
                    009A     71 Ftest_radio_signal_tx$IEN2$0$0 == 0x009a
                    009A     72 _IEN2	=	0x009a
                    009B     73 Ftest_radio_signal_tx$S1CON$0$0 == 0x009b
                    009B     74 _S1CON	=	0x009b
                    009C     75 Ftest_radio_signal_tx$T2CT$0$0 == 0x009c
                    009C     76 _T2CT	=	0x009c
                    009D     77 Ftest_radio_signal_tx$T2PR$0$0 == 0x009d
                    009D     78 _T2PR	=	0x009d
                    009E     79 Ftest_radio_signal_tx$T2CTL$0$0 == 0x009e
                    009E     80 _T2CTL	=	0x009e
                    00A0     81 Ftest_radio_signal_tx$P2$0$0 == 0x00a0
                    00A0     82 _P2	=	0x00a0
                    00A1     83 Ftest_radio_signal_tx$WORIRQ$0$0 == 0x00a1
                    00A1     84 _WORIRQ	=	0x00a1
                    00A2     85 Ftest_radio_signal_tx$WORCTRL$0$0 == 0x00a2
                    00A2     86 _WORCTRL	=	0x00a2
                    00A3     87 Ftest_radio_signal_tx$WOREVT0$0$0 == 0x00a3
                    00A3     88 _WOREVT0	=	0x00a3
                    00A4     89 Ftest_radio_signal_tx$WOREVT1$0$0 == 0x00a4
                    00A4     90 _WOREVT1	=	0x00a4
                    00A5     91 Ftest_radio_signal_tx$WORTIME0$0$0 == 0x00a5
                    00A5     92 _WORTIME0	=	0x00a5
                    00A6     93 Ftest_radio_signal_tx$WORTIME1$0$0 == 0x00a6
                    00A6     94 _WORTIME1	=	0x00a6
                    00A8     95 Ftest_radio_signal_tx$IEN0$0$0 == 0x00a8
                    00A8     96 _IEN0	=	0x00a8
                    00A9     97 Ftest_radio_signal_tx$IP0$0$0 == 0x00a9
                    00A9     98 _IP0	=	0x00a9
                    00AB     99 Ftest_radio_signal_tx$FWT$0$0 == 0x00ab
                    00AB    100 _FWT	=	0x00ab
                    00AC    101 Ftest_radio_signal_tx$FADDRL$0$0 == 0x00ac
                    00AC    102 _FADDRL	=	0x00ac
                    00AD    103 Ftest_radio_signal_tx$FADDRH$0$0 == 0x00ad
                    00AD    104 _FADDRH	=	0x00ad
                    00AE    105 Ftest_radio_signal_tx$FCTL$0$0 == 0x00ae
                    00AE    106 _FCTL	=	0x00ae
                    00AF    107 Ftest_radio_signal_tx$FWDATA$0$0 == 0x00af
                    00AF    108 _FWDATA	=	0x00af
                    00B1    109 Ftest_radio_signal_tx$ENCDI$0$0 == 0x00b1
                    00B1    110 _ENCDI	=	0x00b1
                    00B2    111 Ftest_radio_signal_tx$ENCDO$0$0 == 0x00b2
                    00B2    112 _ENCDO	=	0x00b2
                    00B3    113 Ftest_radio_signal_tx$ENCCS$0$0 == 0x00b3
                    00B3    114 _ENCCS	=	0x00b3
                    00B4    115 Ftest_radio_signal_tx$ADCCON1$0$0 == 0x00b4
                    00B4    116 _ADCCON1	=	0x00b4
                    00B5    117 Ftest_radio_signal_tx$ADCCON2$0$0 == 0x00b5
                    00B5    118 _ADCCON2	=	0x00b5
                    00B6    119 Ftest_radio_signal_tx$ADCCON3$0$0 == 0x00b6
                    00B6    120 _ADCCON3	=	0x00b6
                    00B8    121 Ftest_radio_signal_tx$IEN1$0$0 == 0x00b8
                    00B8    122 _IEN1	=	0x00b8
                    00B9    123 Ftest_radio_signal_tx$IP1$0$0 == 0x00b9
                    00B9    124 _IP1	=	0x00b9
                    00BA    125 Ftest_radio_signal_tx$ADCL$0$0 == 0x00ba
                    00BA    126 _ADCL	=	0x00ba
                    00BB    127 Ftest_radio_signal_tx$ADCH$0$0 == 0x00bb
                    00BB    128 _ADCH	=	0x00bb
                    00BC    129 Ftest_radio_signal_tx$RNDL$0$0 == 0x00bc
                    00BC    130 _RNDL	=	0x00bc
                    00BD    131 Ftest_radio_signal_tx$RNDH$0$0 == 0x00bd
                    00BD    132 _RNDH	=	0x00bd
                    00BE    133 Ftest_radio_signal_tx$SLEEP$0$0 == 0x00be
                    00BE    134 _SLEEP	=	0x00be
                    00C0    135 Ftest_radio_signal_tx$IRCON$0$0 == 0x00c0
                    00C0    136 _IRCON	=	0x00c0
                    00C1    137 Ftest_radio_signal_tx$U0DBUF$0$0 == 0x00c1
                    00C1    138 _U0DBUF	=	0x00c1
                    00C2    139 Ftest_radio_signal_tx$U0BAUD$0$0 == 0x00c2
                    00C2    140 _U0BAUD	=	0x00c2
                    00C4    141 Ftest_radio_signal_tx$U0UCR$0$0 == 0x00c4
                    00C4    142 _U0UCR	=	0x00c4
                    00C5    143 Ftest_radio_signal_tx$U0GCR$0$0 == 0x00c5
                    00C5    144 _U0GCR	=	0x00c5
                    00C6    145 Ftest_radio_signal_tx$CLKCON$0$0 == 0x00c6
                    00C6    146 _CLKCON	=	0x00c6
                    00C7    147 Ftest_radio_signal_tx$MEMCTR$0$0 == 0x00c7
                    00C7    148 _MEMCTR	=	0x00c7
                    00C9    149 Ftest_radio_signal_tx$WDCTL$0$0 == 0x00c9
                    00C9    150 _WDCTL	=	0x00c9
                    00CA    151 Ftest_radio_signal_tx$T3CNT$0$0 == 0x00ca
                    00CA    152 _T3CNT	=	0x00ca
                    00CB    153 Ftest_radio_signal_tx$T3CTL$0$0 == 0x00cb
                    00CB    154 _T3CTL	=	0x00cb
                    00CC    155 Ftest_radio_signal_tx$T3CCTL0$0$0 == 0x00cc
                    00CC    156 _T3CCTL0	=	0x00cc
                    00CD    157 Ftest_radio_signal_tx$T3CC0$0$0 == 0x00cd
                    00CD    158 _T3CC0	=	0x00cd
                    00CE    159 Ftest_radio_signal_tx$T3CCTL1$0$0 == 0x00ce
                    00CE    160 _T3CCTL1	=	0x00ce
                    00CF    161 Ftest_radio_signal_tx$T3CC1$0$0 == 0x00cf
                    00CF    162 _T3CC1	=	0x00cf
                    00D0    163 Ftest_radio_signal_tx$PSW$0$0 == 0x00d0
                    00D0    164 _PSW	=	0x00d0
                    00D1    165 Ftest_radio_signal_tx$DMAIRQ$0$0 == 0x00d1
                    00D1    166 _DMAIRQ	=	0x00d1
                    00D2    167 Ftest_radio_signal_tx$DMA1CFGL$0$0 == 0x00d2
                    00D2    168 _DMA1CFGL	=	0x00d2
                    00D3    169 Ftest_radio_signal_tx$DMA1CFGH$0$0 == 0x00d3
                    00D3    170 _DMA1CFGH	=	0x00d3
                    00D4    171 Ftest_radio_signal_tx$DMA0CFGL$0$0 == 0x00d4
                    00D4    172 _DMA0CFGL	=	0x00d4
                    00D5    173 Ftest_radio_signal_tx$DMA0CFGH$0$0 == 0x00d5
                    00D5    174 _DMA0CFGH	=	0x00d5
                    00D6    175 Ftest_radio_signal_tx$DMAARM$0$0 == 0x00d6
                    00D6    176 _DMAARM	=	0x00d6
                    00D7    177 Ftest_radio_signal_tx$DMAREQ$0$0 == 0x00d7
                    00D7    178 _DMAREQ	=	0x00d7
                    00D8    179 Ftest_radio_signal_tx$TIMIF$0$0 == 0x00d8
                    00D8    180 _TIMIF	=	0x00d8
                    00D9    181 Ftest_radio_signal_tx$RFD$0$0 == 0x00d9
                    00D9    182 _RFD	=	0x00d9
                    00DA    183 Ftest_radio_signal_tx$T1CC0L$0$0 == 0x00da
                    00DA    184 _T1CC0L	=	0x00da
                    00DB    185 Ftest_radio_signal_tx$T1CC0H$0$0 == 0x00db
                    00DB    186 _T1CC0H	=	0x00db
                    00DC    187 Ftest_radio_signal_tx$T1CC1L$0$0 == 0x00dc
                    00DC    188 _T1CC1L	=	0x00dc
                    00DD    189 Ftest_radio_signal_tx$T1CC1H$0$0 == 0x00dd
                    00DD    190 _T1CC1H	=	0x00dd
                    00DE    191 Ftest_radio_signal_tx$T1CC2L$0$0 == 0x00de
                    00DE    192 _T1CC2L	=	0x00de
                    00DF    193 Ftest_radio_signal_tx$T1CC2H$0$0 == 0x00df
                    00DF    194 _T1CC2H	=	0x00df
                    00E0    195 Ftest_radio_signal_tx$ACC$0$0 == 0x00e0
                    00E0    196 _ACC	=	0x00e0
                    00E1    197 Ftest_radio_signal_tx$RFST$0$0 == 0x00e1
                    00E1    198 _RFST	=	0x00e1
                    00E2    199 Ftest_radio_signal_tx$T1CNTL$0$0 == 0x00e2
                    00E2    200 _T1CNTL	=	0x00e2
                    00E3    201 Ftest_radio_signal_tx$T1CNTH$0$0 == 0x00e3
                    00E3    202 _T1CNTH	=	0x00e3
                    00E4    203 Ftest_radio_signal_tx$T1CTL$0$0 == 0x00e4
                    00E4    204 _T1CTL	=	0x00e4
                    00E5    205 Ftest_radio_signal_tx$T1CCTL0$0$0 == 0x00e5
                    00E5    206 _T1CCTL0	=	0x00e5
                    00E6    207 Ftest_radio_signal_tx$T1CCTL1$0$0 == 0x00e6
                    00E6    208 _T1CCTL1	=	0x00e6
                    00E7    209 Ftest_radio_signal_tx$T1CCTL2$0$0 == 0x00e7
                    00E7    210 _T1CCTL2	=	0x00e7
                    00E8    211 Ftest_radio_signal_tx$IRCON2$0$0 == 0x00e8
                    00E8    212 _IRCON2	=	0x00e8
                    00E9    213 Ftest_radio_signal_tx$RFIF$0$0 == 0x00e9
                    00E9    214 _RFIF	=	0x00e9
                    00EA    215 Ftest_radio_signal_tx$T4CNT$0$0 == 0x00ea
                    00EA    216 _T4CNT	=	0x00ea
                    00EB    217 Ftest_radio_signal_tx$T4CTL$0$0 == 0x00eb
                    00EB    218 _T4CTL	=	0x00eb
                    00EC    219 Ftest_radio_signal_tx$T4CCTL0$0$0 == 0x00ec
                    00EC    220 _T4CCTL0	=	0x00ec
                    00ED    221 Ftest_radio_signal_tx$T4CC0$0$0 == 0x00ed
                    00ED    222 _T4CC0	=	0x00ed
                    00EE    223 Ftest_radio_signal_tx$T4CCTL1$0$0 == 0x00ee
                    00EE    224 _T4CCTL1	=	0x00ee
                    00EF    225 Ftest_radio_signal_tx$T4CC1$0$0 == 0x00ef
                    00EF    226 _T4CC1	=	0x00ef
                    00F0    227 Ftest_radio_signal_tx$B$0$0 == 0x00f0
                    00F0    228 _B	=	0x00f0
                    00F1    229 Ftest_radio_signal_tx$PERCFG$0$0 == 0x00f1
                    00F1    230 _PERCFG	=	0x00f1
                    00F2    231 Ftest_radio_signal_tx$ADCCFG$0$0 == 0x00f2
                    00F2    232 _ADCCFG	=	0x00f2
                    00F3    233 Ftest_radio_signal_tx$P0SEL$0$0 == 0x00f3
                    00F3    234 _P0SEL	=	0x00f3
                    00F4    235 Ftest_radio_signal_tx$P1SEL$0$0 == 0x00f4
                    00F4    236 _P1SEL	=	0x00f4
                    00F5    237 Ftest_radio_signal_tx$P2SEL$0$0 == 0x00f5
                    00F5    238 _P2SEL	=	0x00f5
                    00F6    239 Ftest_radio_signal_tx$P1INP$0$0 == 0x00f6
                    00F6    240 _P1INP	=	0x00f6
                    00F7    241 Ftest_radio_signal_tx$P2INP$0$0 == 0x00f7
                    00F7    242 _P2INP	=	0x00f7
                    00F8    243 Ftest_radio_signal_tx$U1CSR$0$0 == 0x00f8
                    00F8    244 _U1CSR	=	0x00f8
                    00F9    245 Ftest_radio_signal_tx$U1DBUF$0$0 == 0x00f9
                    00F9    246 _U1DBUF	=	0x00f9
                    00FA    247 Ftest_radio_signal_tx$U1BAUD$0$0 == 0x00fa
                    00FA    248 _U1BAUD	=	0x00fa
                    00FB    249 Ftest_radio_signal_tx$U1UCR$0$0 == 0x00fb
                    00FB    250 _U1UCR	=	0x00fb
                    00FC    251 Ftest_radio_signal_tx$U1GCR$0$0 == 0x00fc
                    00FC    252 _U1GCR	=	0x00fc
                    00FD    253 Ftest_radio_signal_tx$P0DIR$0$0 == 0x00fd
                    00FD    254 _P0DIR	=	0x00fd
                    00FE    255 Ftest_radio_signal_tx$P1DIR$0$0 == 0x00fe
                    00FE    256 _P1DIR	=	0x00fe
                    00FF    257 Ftest_radio_signal_tx$P2DIR$0$0 == 0x00ff
                    00FF    258 _P2DIR	=	0x00ff
                    FFFFD5D4    259 Ftest_radio_signal_tx$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    260 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    261 Ftest_radio_signal_tx$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    262 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    263 Ftest_radio_signal_tx$FADDR$0$0 == 0xffffadac
                    FFFFADAC    264 _FADDR	=	0xffffadac
                    FFFFBBBA    265 Ftest_radio_signal_tx$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    266 _ADC	=	0xffffbbba
                    FFFFDBDA    267 Ftest_radio_signal_tx$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    268 _T1CC0	=	0xffffdbda
                    FFFFDDDC    269 Ftest_radio_signal_tx$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    270 _T1CC1	=	0xffffdddc
                    FFFFDFDE    271 Ftest_radio_signal_tx$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    272 _T1CC2	=	0xffffdfde
                            273 ;--------------------------------------------------------
                            274 ; special function bits
                            275 ;--------------------------------------------------------
                            276 	.area RSEG    (ABS,DATA)
   0000                     277 	.org 0x0000
                    0080    278 Ftest_radio_signal_tx$P0_0$0$0 == 0x0080
                    0080    279 _P0_0	=	0x0080
                    0081    280 Ftest_radio_signal_tx$P0_1$0$0 == 0x0081
                    0081    281 _P0_1	=	0x0081
                    0082    282 Ftest_radio_signal_tx$P0_2$0$0 == 0x0082
                    0082    283 _P0_2	=	0x0082
                    0083    284 Ftest_radio_signal_tx$P0_3$0$0 == 0x0083
                    0083    285 _P0_3	=	0x0083
                    0084    286 Ftest_radio_signal_tx$P0_4$0$0 == 0x0084
                    0084    287 _P0_4	=	0x0084
                    0085    288 Ftest_radio_signal_tx$P0_5$0$0 == 0x0085
                    0085    289 _P0_5	=	0x0085
                    0086    290 Ftest_radio_signal_tx$P0_6$0$0 == 0x0086
                    0086    291 _P0_6	=	0x0086
                    0087    292 Ftest_radio_signal_tx$P0_7$0$0 == 0x0087
                    0087    293 _P0_7	=	0x0087
                    0088    294 Ftest_radio_signal_tx$_TCON_0$0$0 == 0x0088
                    0088    295 __TCON_0	=	0x0088
                    0089    296 Ftest_radio_signal_tx$RFTXRXIF$0$0 == 0x0089
                    0089    297 _RFTXRXIF	=	0x0089
                    008A    298 Ftest_radio_signal_tx$_TCON_2$0$0 == 0x008a
                    008A    299 __TCON_2	=	0x008a
                    008B    300 Ftest_radio_signal_tx$URX0IF$0$0 == 0x008b
                    008B    301 _URX0IF	=	0x008b
                    008C    302 Ftest_radio_signal_tx$_TCON_4$0$0 == 0x008c
                    008C    303 __TCON_4	=	0x008c
                    008D    304 Ftest_radio_signal_tx$ADCIF$0$0 == 0x008d
                    008D    305 _ADCIF	=	0x008d
                    008E    306 Ftest_radio_signal_tx$_TCON_6$0$0 == 0x008e
                    008E    307 __TCON_6	=	0x008e
                    008F    308 Ftest_radio_signal_tx$URX1IF$0$0 == 0x008f
                    008F    309 _URX1IF	=	0x008f
                    0090    310 Ftest_radio_signal_tx$P1_0$0$0 == 0x0090
                    0090    311 _P1_0	=	0x0090
                    0091    312 Ftest_radio_signal_tx$P1_1$0$0 == 0x0091
                    0091    313 _P1_1	=	0x0091
                    0092    314 Ftest_radio_signal_tx$P1_2$0$0 == 0x0092
                    0092    315 _P1_2	=	0x0092
                    0093    316 Ftest_radio_signal_tx$P1_3$0$0 == 0x0093
                    0093    317 _P1_3	=	0x0093
                    0094    318 Ftest_radio_signal_tx$P1_4$0$0 == 0x0094
                    0094    319 _P1_4	=	0x0094
                    0095    320 Ftest_radio_signal_tx$P1_5$0$0 == 0x0095
                    0095    321 _P1_5	=	0x0095
                    0096    322 Ftest_radio_signal_tx$P1_6$0$0 == 0x0096
                    0096    323 _P1_6	=	0x0096
                    0097    324 Ftest_radio_signal_tx$P1_7$0$0 == 0x0097
                    0097    325 _P1_7	=	0x0097
                    0098    326 Ftest_radio_signal_tx$ENCIF_0$0$0 == 0x0098
                    0098    327 _ENCIF_0	=	0x0098
                    0099    328 Ftest_radio_signal_tx$ENCIF_1$0$0 == 0x0099
                    0099    329 _ENCIF_1	=	0x0099
                    009A    330 Ftest_radio_signal_tx$_SOCON2$0$0 == 0x009a
                    009A    331 __SOCON2	=	0x009a
                    009B    332 Ftest_radio_signal_tx$_SOCON3$0$0 == 0x009b
                    009B    333 __SOCON3	=	0x009b
                    009C    334 Ftest_radio_signal_tx$_SOCON4$0$0 == 0x009c
                    009C    335 __SOCON4	=	0x009c
                    009D    336 Ftest_radio_signal_tx$_SOCON5$0$0 == 0x009d
                    009D    337 __SOCON5	=	0x009d
                    009E    338 Ftest_radio_signal_tx$_SOCON6$0$0 == 0x009e
                    009E    339 __SOCON6	=	0x009e
                    009F    340 Ftest_radio_signal_tx$_SOCON7$0$0 == 0x009f
                    009F    341 __SOCON7	=	0x009f
                    00A0    342 Ftest_radio_signal_tx$P2_0$0$0 == 0x00a0
                    00A0    343 _P2_0	=	0x00a0
                    00A1    344 Ftest_radio_signal_tx$P2_1$0$0 == 0x00a1
                    00A1    345 _P2_1	=	0x00a1
                    00A2    346 Ftest_radio_signal_tx$P2_2$0$0 == 0x00a2
                    00A2    347 _P2_2	=	0x00a2
                    00A3    348 Ftest_radio_signal_tx$P2_3$0$0 == 0x00a3
                    00A3    349 _P2_3	=	0x00a3
                    00A4    350 Ftest_radio_signal_tx$P2_4$0$0 == 0x00a4
                    00A4    351 _P2_4	=	0x00a4
                    00A5    352 Ftest_radio_signal_tx$P2_5$0$0 == 0x00a5
                    00A5    353 _P2_5	=	0x00a5
                    00A6    354 Ftest_radio_signal_tx$P2_6$0$0 == 0x00a6
                    00A6    355 _P2_6	=	0x00a6
                    00A7    356 Ftest_radio_signal_tx$P2_7$0$0 == 0x00a7
                    00A7    357 _P2_7	=	0x00a7
                    00A8    358 Ftest_radio_signal_tx$RFTXRXIE$0$0 == 0x00a8
                    00A8    359 _RFTXRXIE	=	0x00a8
                    00A9    360 Ftest_radio_signal_tx$ADCIE$0$0 == 0x00a9
                    00A9    361 _ADCIE	=	0x00a9
                    00AA    362 Ftest_radio_signal_tx$URX0IE$0$0 == 0x00aa
                    00AA    363 _URX0IE	=	0x00aa
                    00AB    364 Ftest_radio_signal_tx$URX1IE$0$0 == 0x00ab
                    00AB    365 _URX1IE	=	0x00ab
                    00AC    366 Ftest_radio_signal_tx$ENCIE$0$0 == 0x00ac
                    00AC    367 _ENCIE	=	0x00ac
                    00AD    368 Ftest_radio_signal_tx$STIE$0$0 == 0x00ad
                    00AD    369 _STIE	=	0x00ad
                    00AE    370 Ftest_radio_signal_tx$_IEN06$0$0 == 0x00ae
                    00AE    371 __IEN06	=	0x00ae
                    00AF    372 Ftest_radio_signal_tx$EA$0$0 == 0x00af
                    00AF    373 _EA	=	0x00af
                    00B8    374 Ftest_radio_signal_tx$DMAIE$0$0 == 0x00b8
                    00B8    375 _DMAIE	=	0x00b8
                    00B9    376 Ftest_radio_signal_tx$T1IE$0$0 == 0x00b9
                    00B9    377 _T1IE	=	0x00b9
                    00BA    378 Ftest_radio_signal_tx$T2IE$0$0 == 0x00ba
                    00BA    379 _T2IE	=	0x00ba
                    00BB    380 Ftest_radio_signal_tx$T3IE$0$0 == 0x00bb
                    00BB    381 _T3IE	=	0x00bb
                    00BC    382 Ftest_radio_signal_tx$T4IE$0$0 == 0x00bc
                    00BC    383 _T4IE	=	0x00bc
                    00BD    384 Ftest_radio_signal_tx$P0IE$0$0 == 0x00bd
                    00BD    385 _P0IE	=	0x00bd
                    00BE    386 Ftest_radio_signal_tx$_IEN16$0$0 == 0x00be
                    00BE    387 __IEN16	=	0x00be
                    00BF    388 Ftest_radio_signal_tx$_IEN17$0$0 == 0x00bf
                    00BF    389 __IEN17	=	0x00bf
                    00C0    390 Ftest_radio_signal_tx$DMAIF$0$0 == 0x00c0
                    00C0    391 _DMAIF	=	0x00c0
                    00C1    392 Ftest_radio_signal_tx$T1IF$0$0 == 0x00c1
                    00C1    393 _T1IF	=	0x00c1
                    00C2    394 Ftest_radio_signal_tx$T2IF$0$0 == 0x00c2
                    00C2    395 _T2IF	=	0x00c2
                    00C3    396 Ftest_radio_signal_tx$T3IF$0$0 == 0x00c3
                    00C3    397 _T3IF	=	0x00c3
                    00C4    398 Ftest_radio_signal_tx$T4IF$0$0 == 0x00c4
                    00C4    399 _T4IF	=	0x00c4
                    00C5    400 Ftest_radio_signal_tx$P0IF$0$0 == 0x00c5
                    00C5    401 _P0IF	=	0x00c5
                    00C6    402 Ftest_radio_signal_tx$_IRCON6$0$0 == 0x00c6
                    00C6    403 __IRCON6	=	0x00c6
                    00C7    404 Ftest_radio_signal_tx$STIF$0$0 == 0x00c7
                    00C7    405 _STIF	=	0x00c7
                    00D0    406 Ftest_radio_signal_tx$P$0$0 == 0x00d0
                    00D0    407 _P	=	0x00d0
                    00D1    408 Ftest_radio_signal_tx$F1$0$0 == 0x00d1
                    00D1    409 _F1	=	0x00d1
                    00D2    410 Ftest_radio_signal_tx$OV$0$0 == 0x00d2
                    00D2    411 _OV	=	0x00d2
                    00D3    412 Ftest_radio_signal_tx$RS0$0$0 == 0x00d3
                    00D3    413 _RS0	=	0x00d3
                    00D4    414 Ftest_radio_signal_tx$RS1$0$0 == 0x00d4
                    00D4    415 _RS1	=	0x00d4
                    00D5    416 Ftest_radio_signal_tx$F0$0$0 == 0x00d5
                    00D5    417 _F0	=	0x00d5
                    00D6    418 Ftest_radio_signal_tx$AC$0$0 == 0x00d6
                    00D6    419 _AC	=	0x00d6
                    00D7    420 Ftest_radio_signal_tx$CY$0$0 == 0x00d7
                    00D7    421 _CY	=	0x00d7
                    00D8    422 Ftest_radio_signal_tx$T3OVFIF$0$0 == 0x00d8
                    00D8    423 _T3OVFIF	=	0x00d8
                    00D9    424 Ftest_radio_signal_tx$T3CH0IF$0$0 == 0x00d9
                    00D9    425 _T3CH0IF	=	0x00d9
                    00DA    426 Ftest_radio_signal_tx$T3CH1IF$0$0 == 0x00da
                    00DA    427 _T3CH1IF	=	0x00da
                    00DB    428 Ftest_radio_signal_tx$T4OVFIF$0$0 == 0x00db
                    00DB    429 _T4OVFIF	=	0x00db
                    00DC    430 Ftest_radio_signal_tx$T4CH0IF$0$0 == 0x00dc
                    00DC    431 _T4CH0IF	=	0x00dc
                    00DD    432 Ftest_radio_signal_tx$T4CH1IF$0$0 == 0x00dd
                    00DD    433 _T4CH1IF	=	0x00dd
                    00DE    434 Ftest_radio_signal_tx$OVFIM$0$0 == 0x00de
                    00DE    435 _OVFIM	=	0x00de
                    00DF    436 Ftest_radio_signal_tx$_TIMIF7$0$0 == 0x00df
                    00DF    437 __TIMIF7	=	0x00df
                    00E0    438 Ftest_radio_signal_tx$ACC_0$0$0 == 0x00e0
                    00E0    439 _ACC_0	=	0x00e0
                    00E1    440 Ftest_radio_signal_tx$ACC_1$0$0 == 0x00e1
                    00E1    441 _ACC_1	=	0x00e1
                    00E2    442 Ftest_radio_signal_tx$ACC_2$0$0 == 0x00e2
                    00E2    443 _ACC_2	=	0x00e2
                    00E3    444 Ftest_radio_signal_tx$ACC_3$0$0 == 0x00e3
                    00E3    445 _ACC_3	=	0x00e3
                    00E4    446 Ftest_radio_signal_tx$ACC_4$0$0 == 0x00e4
                    00E4    447 _ACC_4	=	0x00e4
                    00E5    448 Ftest_radio_signal_tx$ACC_5$0$0 == 0x00e5
                    00E5    449 _ACC_5	=	0x00e5
                    00E6    450 Ftest_radio_signal_tx$ACC_6$0$0 == 0x00e6
                    00E6    451 _ACC_6	=	0x00e6
                    00E7    452 Ftest_radio_signal_tx$ACC_7$0$0 == 0x00e7
                    00E7    453 _ACC_7	=	0x00e7
                    00E8    454 Ftest_radio_signal_tx$P2IF$0$0 == 0x00e8
                    00E8    455 _P2IF	=	0x00e8
                    00E9    456 Ftest_radio_signal_tx$UTX0IF$0$0 == 0x00e9
                    00E9    457 _UTX0IF	=	0x00e9
                    00EA    458 Ftest_radio_signal_tx$UTX1IF$0$0 == 0x00ea
                    00EA    459 _UTX1IF	=	0x00ea
                    00EB    460 Ftest_radio_signal_tx$P1IF$0$0 == 0x00eb
                    00EB    461 _P1IF	=	0x00eb
                    00EC    462 Ftest_radio_signal_tx$WDTIF$0$0 == 0x00ec
                    00EC    463 _WDTIF	=	0x00ec
                    00ED    464 Ftest_radio_signal_tx$_IRCON25$0$0 == 0x00ed
                    00ED    465 __IRCON25	=	0x00ed
                    00EE    466 Ftest_radio_signal_tx$_IRCON26$0$0 == 0x00ee
                    00EE    467 __IRCON26	=	0x00ee
                    00EF    468 Ftest_radio_signal_tx$_IRCON27$0$0 == 0x00ef
                    00EF    469 __IRCON27	=	0x00ef
                    00F0    470 Ftest_radio_signal_tx$B_0$0$0 == 0x00f0
                    00F0    471 _B_0	=	0x00f0
                    00F1    472 Ftest_radio_signal_tx$B_1$0$0 == 0x00f1
                    00F1    473 _B_1	=	0x00f1
                    00F2    474 Ftest_radio_signal_tx$B_2$0$0 == 0x00f2
                    00F2    475 _B_2	=	0x00f2
                    00F3    476 Ftest_radio_signal_tx$B_3$0$0 == 0x00f3
                    00F3    477 _B_3	=	0x00f3
                    00F4    478 Ftest_radio_signal_tx$B_4$0$0 == 0x00f4
                    00F4    479 _B_4	=	0x00f4
                    00F5    480 Ftest_radio_signal_tx$B_5$0$0 == 0x00f5
                    00F5    481 _B_5	=	0x00f5
                    00F6    482 Ftest_radio_signal_tx$B_6$0$0 == 0x00f6
                    00F6    483 _B_6	=	0x00f6
                    00F7    484 Ftest_radio_signal_tx$B_7$0$0 == 0x00f7
                    00F7    485 _B_7	=	0x00f7
                    00F8    486 Ftest_radio_signal_tx$U1ACTIVE$0$0 == 0x00f8
                    00F8    487 _U1ACTIVE	=	0x00f8
                    00F9    488 Ftest_radio_signal_tx$U1TX_BYTE$0$0 == 0x00f9
                    00F9    489 _U1TX_BYTE	=	0x00f9
                    00FA    490 Ftest_radio_signal_tx$U1RX_BYTE$0$0 == 0x00fa
                    00FA    491 _U1RX_BYTE	=	0x00fa
                    00FB    492 Ftest_radio_signal_tx$U1ERR$0$0 == 0x00fb
                    00FB    493 _U1ERR	=	0x00fb
                    00FC    494 Ftest_radio_signal_tx$U1FE$0$0 == 0x00fc
                    00FC    495 _U1FE	=	0x00fc
                    00FD    496 Ftest_radio_signal_tx$U1SLAVE$0$0 == 0x00fd
                    00FD    497 _U1SLAVE	=	0x00fd
                    00FE    498 Ftest_radio_signal_tx$U1RE$0$0 == 0x00fe
                    00FE    499 _U1RE	=	0x00fe
                    00FF    500 Ftest_radio_signal_tx$U1MODE$0$0 == 0x00ff
                    00FF    501 _U1MODE	=	0x00ff
                            502 ;--------------------------------------------------------
                            503 ; overlayable register banks
                            504 ;--------------------------------------------------------
                            505 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     506 	.ds 8
                            507 ;--------------------------------------------------------
                            508 ; internal ram data
                            509 ;--------------------------------------------------------
                            510 	.area DSEG    (DATA)
                            511 ;--------------------------------------------------------
                            512 ; overlayable items in internal ram 
                            513 ;--------------------------------------------------------
                            514 	.area OSEG    (OVR,DATA)
                            515 ;--------------------------------------------------------
                            516 ; Stack segment in internal ram 
                            517 ;--------------------------------------------------------
                            518 	.area	SSEG	(DATA)
   0022                     519 __start__stack:
   0022                     520 	.ds	1
                            521 
                            522 ;--------------------------------------------------------
                            523 ; indirectly addressable internal ram data
                            524 ;--------------------------------------------------------
                            525 	.area ISEG    (DATA)
                            526 ;--------------------------------------------------------
                            527 ; absolute internal ram data
                            528 ;--------------------------------------------------------
                            529 	.area IABS    (ABS,DATA)
                            530 	.area IABS    (ABS,DATA)
                            531 ;--------------------------------------------------------
                            532 ; bit data
                            533 ;--------------------------------------------------------
                            534 	.area BSEG    (BIT)
                            535 ;--------------------------------------------------------
                            536 ; paged external ram data
                            537 ;--------------------------------------------------------
                            538 	.area PSEG    (PAG,XDATA)
                    0000    539 Ftest_radio_signal_tx$currentBurstId$0$0==.
   F000                     540 _currentBurstId:
   F000                     541 	.ds 1
                    0001    542 Ftest_radio_signal_tx$packetsSent$0$0==.
   F001                     543 _packetsSent:
   F001                     544 	.ds 1
                    0002    545 Ftest_radio_signal_tx$lastBurst$0$0==.
   F002                     546 _lastBurst:
   F002                     547 	.ds 2
                            548 ;--------------------------------------------------------
                            549 ; external ram data
                            550 ;--------------------------------------------------------
                            551 	.area XSEG    (XDATA)
                    DF00    552 Ftest_radio_signal_tx$SYNC1$0$0 == 0xdf00
                    DF00    553 _SYNC1	=	0xdf00
                    DF01    554 Ftest_radio_signal_tx$SYNC0$0$0 == 0xdf01
                    DF01    555 _SYNC0	=	0xdf01
                    DF02    556 Ftest_radio_signal_tx$PKTLEN$0$0 == 0xdf02
                    DF02    557 _PKTLEN	=	0xdf02
                    DF03    558 Ftest_radio_signal_tx$PKTCTRL1$0$0 == 0xdf03
                    DF03    559 _PKTCTRL1	=	0xdf03
                    DF04    560 Ftest_radio_signal_tx$PKTCTRL0$0$0 == 0xdf04
                    DF04    561 _PKTCTRL0	=	0xdf04
                    DF05    562 Ftest_radio_signal_tx$ADDR$0$0 == 0xdf05
                    DF05    563 _ADDR	=	0xdf05
                    DF06    564 Ftest_radio_signal_tx$CHANNR$0$0 == 0xdf06
                    DF06    565 _CHANNR	=	0xdf06
                    DF07    566 Ftest_radio_signal_tx$FSCTRL1$0$0 == 0xdf07
                    DF07    567 _FSCTRL1	=	0xdf07
                    DF08    568 Ftest_radio_signal_tx$FSCTRL0$0$0 == 0xdf08
                    DF08    569 _FSCTRL0	=	0xdf08
                    DF09    570 Ftest_radio_signal_tx$FREQ2$0$0 == 0xdf09
                    DF09    571 _FREQ2	=	0xdf09
                    DF0A    572 Ftest_radio_signal_tx$FREQ1$0$0 == 0xdf0a
                    DF0A    573 _FREQ1	=	0xdf0a
                    DF0B    574 Ftest_radio_signal_tx$FREQ0$0$0 == 0xdf0b
                    DF0B    575 _FREQ0	=	0xdf0b
                    DF0C    576 Ftest_radio_signal_tx$MDMCFG4$0$0 == 0xdf0c
                    DF0C    577 _MDMCFG4	=	0xdf0c
                    DF0D    578 Ftest_radio_signal_tx$MDMCFG3$0$0 == 0xdf0d
                    DF0D    579 _MDMCFG3	=	0xdf0d
                    DF0E    580 Ftest_radio_signal_tx$MDMCFG2$0$0 == 0xdf0e
                    DF0E    581 _MDMCFG2	=	0xdf0e
                    DF0F    582 Ftest_radio_signal_tx$MDMCFG1$0$0 == 0xdf0f
                    DF0F    583 _MDMCFG1	=	0xdf0f
                    DF10    584 Ftest_radio_signal_tx$MDMCFG0$0$0 == 0xdf10
                    DF10    585 _MDMCFG0	=	0xdf10
                    DF11    586 Ftest_radio_signal_tx$DEVIATN$0$0 == 0xdf11
                    DF11    587 _DEVIATN	=	0xdf11
                    DF12    588 Ftest_radio_signal_tx$MCSM2$0$0 == 0xdf12
                    DF12    589 _MCSM2	=	0xdf12
                    DF13    590 Ftest_radio_signal_tx$MCSM1$0$0 == 0xdf13
                    DF13    591 _MCSM1	=	0xdf13
                    DF14    592 Ftest_radio_signal_tx$MCSM0$0$0 == 0xdf14
                    DF14    593 _MCSM0	=	0xdf14
                    DF15    594 Ftest_radio_signal_tx$FOCCFG$0$0 == 0xdf15
                    DF15    595 _FOCCFG	=	0xdf15
                    DF16    596 Ftest_radio_signal_tx$BSCFG$0$0 == 0xdf16
                    DF16    597 _BSCFG	=	0xdf16
                    DF17    598 Ftest_radio_signal_tx$AGCCTRL2$0$0 == 0xdf17
                    DF17    599 _AGCCTRL2	=	0xdf17
                    DF18    600 Ftest_radio_signal_tx$AGCCTRL1$0$0 == 0xdf18
                    DF18    601 _AGCCTRL1	=	0xdf18
                    DF19    602 Ftest_radio_signal_tx$AGCCTRL0$0$0 == 0xdf19
                    DF19    603 _AGCCTRL0	=	0xdf19
                    DF1A    604 Ftest_radio_signal_tx$FREND1$0$0 == 0xdf1a
                    DF1A    605 _FREND1	=	0xdf1a
                    DF1B    606 Ftest_radio_signal_tx$FREND0$0$0 == 0xdf1b
                    DF1B    607 _FREND0	=	0xdf1b
                    DF1C    608 Ftest_radio_signal_tx$FSCAL3$0$0 == 0xdf1c
                    DF1C    609 _FSCAL3	=	0xdf1c
                    DF1D    610 Ftest_radio_signal_tx$FSCAL2$0$0 == 0xdf1d
                    DF1D    611 _FSCAL2	=	0xdf1d
                    DF1E    612 Ftest_radio_signal_tx$FSCAL1$0$0 == 0xdf1e
                    DF1E    613 _FSCAL1	=	0xdf1e
                    DF1F    614 Ftest_radio_signal_tx$FSCAL0$0$0 == 0xdf1f
                    DF1F    615 _FSCAL0	=	0xdf1f
                    DF23    616 Ftest_radio_signal_tx$TEST2$0$0 == 0xdf23
                    DF23    617 _TEST2	=	0xdf23
                    DF24    618 Ftest_radio_signal_tx$TEST1$0$0 == 0xdf24
                    DF24    619 _TEST1	=	0xdf24
                    DF25    620 Ftest_radio_signal_tx$TEST0$0$0 == 0xdf25
                    DF25    621 _TEST0	=	0xdf25
                    DF2E    622 Ftest_radio_signal_tx$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    623 _PA_TABLE0	=	0xdf2e
                    DF2F    624 Ftest_radio_signal_tx$IOCFG2$0$0 == 0xdf2f
                    DF2F    625 _IOCFG2	=	0xdf2f
                    DF30    626 Ftest_radio_signal_tx$IOCFG1$0$0 == 0xdf30
                    DF30    627 _IOCFG1	=	0xdf30
                    DF31    628 Ftest_radio_signal_tx$IOCFG0$0$0 == 0xdf31
                    DF31    629 _IOCFG0	=	0xdf31
                    DF36    630 Ftest_radio_signal_tx$PARTNUM$0$0 == 0xdf36
                    DF36    631 _PARTNUM	=	0xdf36
                    DF37    632 Ftest_radio_signal_tx$VERSION$0$0 == 0xdf37
                    DF37    633 _VERSION	=	0xdf37
                    DF38    634 Ftest_radio_signal_tx$FREQEST$0$0 == 0xdf38
                    DF38    635 _FREQEST	=	0xdf38
                    DF39    636 Ftest_radio_signal_tx$LQI$0$0 == 0xdf39
                    DF39    637 _LQI	=	0xdf39
                    DF3A    638 Ftest_radio_signal_tx$RSSI$0$0 == 0xdf3a
                    DF3A    639 _RSSI	=	0xdf3a
                    DF3B    640 Ftest_radio_signal_tx$MARCSTATE$0$0 == 0xdf3b
                    DF3B    641 _MARCSTATE	=	0xdf3b
                    DF3C    642 Ftest_radio_signal_tx$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    643 _PKTSTATUS	=	0xdf3c
                    DF3D    644 Ftest_radio_signal_tx$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    645 _VCO_VC_DAC	=	0xdf3d
                    DF40    646 Ftest_radio_signal_tx$I2SCFG0$0$0 == 0xdf40
                    DF40    647 _I2SCFG0	=	0xdf40
                    DF41    648 Ftest_radio_signal_tx$I2SCFG1$0$0 == 0xdf41
                    DF41    649 _I2SCFG1	=	0xdf41
                    DF42    650 Ftest_radio_signal_tx$I2SDATL$0$0 == 0xdf42
                    DF42    651 _I2SDATL	=	0xdf42
                    DF43    652 Ftest_radio_signal_tx$I2SDATH$0$0 == 0xdf43
                    DF43    653 _I2SDATH	=	0xdf43
                    DF44    654 Ftest_radio_signal_tx$I2SWCNT$0$0 == 0xdf44
                    DF44    655 _I2SWCNT	=	0xdf44
                    DF45    656 Ftest_radio_signal_tx$I2SSTAT$0$0 == 0xdf45
                    DF45    657 _I2SSTAT	=	0xdf45
                    DF46    658 Ftest_radio_signal_tx$I2SCLKF0$0$0 == 0xdf46
                    DF46    659 _I2SCLKF0	=	0xdf46
                    DF47    660 Ftest_radio_signal_tx$I2SCLKF1$0$0 == 0xdf47
                    DF47    661 _I2SCLKF1	=	0xdf47
                    DF48    662 Ftest_radio_signal_tx$I2SCLKF2$0$0 == 0xdf48
                    DF48    663 _I2SCLKF2	=	0xdf48
                    DE00    664 Ftest_radio_signal_tx$USBADDR$0$0 == 0xde00
                    DE00    665 _USBADDR	=	0xde00
                    DE01    666 Ftest_radio_signal_tx$USBPOW$0$0 == 0xde01
                    DE01    667 _USBPOW	=	0xde01
                    DE02    668 Ftest_radio_signal_tx$USBIIF$0$0 == 0xde02
                    DE02    669 _USBIIF	=	0xde02
                    DE04    670 Ftest_radio_signal_tx$USBOIF$0$0 == 0xde04
                    DE04    671 _USBOIF	=	0xde04
                    DE06    672 Ftest_radio_signal_tx$USBCIF$0$0 == 0xde06
                    DE06    673 _USBCIF	=	0xde06
                    DE07    674 Ftest_radio_signal_tx$USBIIE$0$0 == 0xde07
                    DE07    675 _USBIIE	=	0xde07
                    DE09    676 Ftest_radio_signal_tx$USBOIE$0$0 == 0xde09
                    DE09    677 _USBOIE	=	0xde09
                    DE0B    678 Ftest_radio_signal_tx$USBCIE$0$0 == 0xde0b
                    DE0B    679 _USBCIE	=	0xde0b
                    DE0C    680 Ftest_radio_signal_tx$USBFRML$0$0 == 0xde0c
                    DE0C    681 _USBFRML	=	0xde0c
                    DE0D    682 Ftest_radio_signal_tx$USBFRMH$0$0 == 0xde0d
                    DE0D    683 _USBFRMH	=	0xde0d
                    DE0E    684 Ftest_radio_signal_tx$USBINDEX$0$0 == 0xde0e
                    DE0E    685 _USBINDEX	=	0xde0e
                    DE10    686 Ftest_radio_signal_tx$USBMAXI$0$0 == 0xde10
                    DE10    687 _USBMAXI	=	0xde10
                    DE11    688 Ftest_radio_signal_tx$USBCSIL$0$0 == 0xde11
                    DE11    689 _USBCSIL	=	0xde11
                    DE12    690 Ftest_radio_signal_tx$USBCSIH$0$0 == 0xde12
                    DE12    691 _USBCSIH	=	0xde12
                    DE13    692 Ftest_radio_signal_tx$USBMAXO$0$0 == 0xde13
                    DE13    693 _USBMAXO	=	0xde13
                    DE14    694 Ftest_radio_signal_tx$USBCSOL$0$0 == 0xde14
                    DE14    695 _USBCSOL	=	0xde14
                    DE15    696 Ftest_radio_signal_tx$USBCSOH$0$0 == 0xde15
                    DE15    697 _USBCSOH	=	0xde15
                    DE16    698 Ftest_radio_signal_tx$USBCNTL$0$0 == 0xde16
                    DE16    699 _USBCNTL	=	0xde16
                    DE17    700 Ftest_radio_signal_tx$USBCNTH$0$0 == 0xde17
                    DE17    701 _USBCNTH	=	0xde17
                    DE20    702 Ftest_radio_signal_tx$USBF0$0$0 == 0xde20
                    DE20    703 _USBF0	=	0xde20
                    DE22    704 Ftest_radio_signal_tx$USBF1$0$0 == 0xde22
                    DE22    705 _USBF1	=	0xde22
                    DE24    706 Ftest_radio_signal_tx$USBF2$0$0 == 0xde24
                    DE24    707 _USBF2	=	0xde24
                    DE26    708 Ftest_radio_signal_tx$USBF3$0$0 == 0xde26
                    DE26    709 _USBF3	=	0xde26
                    DE28    710 Ftest_radio_signal_tx$USBF4$0$0 == 0xde28
                    DE28    711 _USBF4	=	0xde28
                    DE2A    712 Ftest_radio_signal_tx$USBF5$0$0 == 0xde2a
                    DE2A    713 _USBF5	=	0xde2a
                    0000    714 Ftest_radio_signal_tx$packet$0$0==.
   F020                     715 _packet:
   F020                     716 	.ds 17
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
   0400 02 04 6D            740 	ljmp	__sdcc_gsinit_startup
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
   0463 02 09 D1            765 	ljmp	_ISR_T4
                            766 ;--------------------------------------------------------
                            767 ; global & static initialisations
                            768 ;--------------------------------------------------------
                            769 	.area HOME    (CODE)
                            770 	.area GSINIT  (CODE)
                            771 	.area GSFINAL (CODE)
                            772 	.area GSINIT  (CODE)
                            773 	.globl __sdcc_gsinit_startup
                            774 	.globl __sdcc_program_startup
                            775 	.globl __start__stack
                            776 	.globl __mcs51_genXINIT
                            777 	.globl __mcs51_genXRAMCLEAR
                            778 	.globl __mcs51_genRAMCLEAR
                    0000    779 	G$main$0$0 ==.
                    0000    780 	C$test_radio_signal_tx.c$20$1$1 ==.
                            781 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:20: static uint8 currentBurstId = 0;
   04C6 78 00               782 	mov	r0,#_currentBurstId
   04C8 E4                  783 	clr	a
   04C9 F2                  784 	movx	@r0,a
                    0004    785 	G$main$0$0 ==.
                    0004    786 	C$test_radio_signal_tx.c$21$1$1 ==.
                            787 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:21: static uint8 packetsSent = 0;
   04CA 78 01               788 	mov	r0,#_packetsSent
   04CC E4                  789 	clr	a
   04CD F2                  790 	movx	@r0,a
                    0008    791 	G$main$0$0 ==.
                    0008    792 	C$test_radio_signal_tx.c$22$1$1 ==.
                            793 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:22: static uint16 lastBurst = 0;
   04CE 78 02               794 	mov	r0,#_lastBurst
   04D0 E4                  795 	clr	a
   04D1 F2                  796 	movx	@r0,a
   04D2 08                  797 	inc	r0
   04D3 F2                  798 	movx	@r0,a
                            799 	.area GSFINAL (CODE)
   04FE 02 04 66            800 	ljmp	__sdcc_program_startup
                            801 ;--------------------------------------------------------
                            802 ; Home
                            803 ;--------------------------------------------------------
                            804 	.area HOME    (CODE)
                            805 	.area HOME    (CODE)
   0466                     806 __sdcc_program_startup:
   0466 12 06 26            807 	lcall	_main
                            808 ;	return from main will lock up
   0469 80 FE               809 	sjmp .
                            810 ;--------------------------------------------------------
                            811 ; code
                            812 ;--------------------------------------------------------
                            813 	.area CSEG    (CODE)
                            814 ;------------------------------------------------------------
                            815 ;Allocation info for local variables in function 'updateLeds'
                            816 ;------------------------------------------------------------
                    0000    817 	G$updateLeds$0$0 ==.
                    0000    818 	C$test_radio_signal_tx.c$24$0$0 ==.
                            819 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:24: void updateLeds()
                            820 ;	-----------------------------------------
                            821 ;	 function updateLeds
                            822 ;	-----------------------------------------
   0501                     823 _updateLeds:
                    0007    824 	ar7 = 0x07
                    0006    825 	ar6 = 0x06
                    0005    826 	ar5 = 0x05
                    0004    827 	ar4 = 0x04
                    0003    828 	ar3 = 0x03
                    0002    829 	ar2 = 0x02
                    0001    830 	ar1 = 0x01
                    0000    831 	ar0 = 0x00
                    0000    832 	C$test_radio_signal_tx.c$26$1$1 ==.
                            833 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:26: usbShowStatusWithGreenLed();
   0501 12 10 C3            834 	lcall	_usbShowStatusWithGreenLed
                    0003    835 	C$test_radio_signal_tx.c$28$2$2 ==.
                            836 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:28: LED_YELLOW(0);
   0504 AF FF               837 	mov	r7,_P2DIR
   0506 53 07 FB            838 	anl	ar7,#0xFB
   0509 8F FF               839 	mov	_P2DIR,r7
                    000A    840 	C$test_radio_signal_tx.c$31$2$3 ==.
                            841 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:31: LED_RED((uint16)(packetsSent < 100));
   050B 78 01               842 	mov	r0,#_packetsSent
   050D E2                  843 	movx	a,@r0
   050E B4 64 00            844 	cjne	a,#0x64,00106$
   0511                     845 00106$:
   0511 E4                  846 	clr	a
   0512 33                  847 	rlc	a
   0513 FF                  848 	mov	r7,a
   0514 33                  849 	rlc	a
   0515 95 E0               850 	subb	a,acc
   0517 FE                  851 	mov	r6,a
   0518 4F                  852 	orl	a,r7
   0519 60 05               853 	jz	00103$
   051B 43 FF 02            854 	orl	_P2DIR,#0x02
   051E 80 07               855 	sjmp	00101$
   0520                     856 00103$:
   0520 AF FF               857 	mov	r7,_P2DIR
   0522 53 07 FD            858 	anl	ar7,#0xFD
   0525 8F FF               859 	mov	_P2DIR,r7
   0527                     860 00101$:
                    0026    861 	C$test_radio_signal_tx.c$32$2$3 ==.
                    0026    862 	XG$updateLeds$0$0 ==.
   0527 22                  863 	ret
                            864 ;------------------------------------------------------------
                            865 ;Allocation info for local variables in function 'perTestTxInit'
                            866 ;------------------------------------------------------------
                    0027    867 	G$perTestTxInit$0$0 ==.
                    0027    868 	C$test_radio_signal_tx.c$34$2$3 ==.
                            869 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:34: void perTestTxInit()
                            870 ;	-----------------------------------------
                            871 ;	 function perTestTxInit
                            872 ;	-----------------------------------------
   0528                     873 _perTestTxInit:
                    0027    874 	C$test_radio_signal_tx.c$38$1$1 ==.
                            875 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:38: radioRegistersInit();
   0528 12 11 51            876 	lcall	_radioRegistersInit
                    002A    877 	C$test_radio_signal_tx.c$40$1$1 ==.
                            878 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:40: CHANNR = param_radio_channel;
   052B 90 12 3D            879 	mov	dptr,#_param_radio_channel
   052E E4                  880 	clr	a
   052F 93                  881 	movc	a,@a+dptr
   0530 FC                  882 	mov	r4,a
   0531 74 01               883 	mov	a,#0x01
   0533 93                  884 	movc	a,@a+dptr
   0534 FD                  885 	mov	r5,a
   0535 74 02               886 	mov	a,#0x02
   0537 93                  887 	movc	a,@a+dptr
   0538 74 03               888 	mov	a,#0x03
   053A 93                  889 	movc	a,@a+dptr
   053B 90 DF 06            890 	mov	dptr,#_CHANNR
   053E EC                  891 	mov	a,r4
   053F F0                  892 	movx	@dptr,a
                    003F    893 	C$test_radio_signal_tx.c$42$1$1 ==.
                            894 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:42: PKTLEN = RADIO_PACKET_SIZE;
   0540 90 DF 02            895 	mov	dptr,#_PKTLEN
   0543 74 10               896 	mov	a,#0x10
   0545 F0                  897 	movx	@dptr,a
                    0045    898 	C$test_radio_signal_tx.c$44$1$1 ==.
                            899 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:44: MCSM0 = 0x14;    // Auto-calibrate when going from idle to RX or TX.
   0546 90 DF 14            900 	mov	dptr,#_MCSM0
   0549 74 14               901 	mov	a,#0x14
   054B F0                  902 	movx	@dptr,a
                    004B    903 	C$test_radio_signal_tx.c$45$1$1 ==.
                            904 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:45: MCSM1 = 0x00;    // Disable CCA.  After RX, go to IDLE.  After TX, go to IDLE.
   054C 90 DF 13            905 	mov	dptr,#_MCSM1
   054F E4                  906 	clr	a
   0550 F0                  907 	movx	@dptr,a
                    0050    908 	C$test_radio_signal_tx.c$48$1$1 ==.
                            909 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:48: IOCFG2 = 0b011011; // put out a PA_PD signal on P1_7 (active low when the radio is in TX mode)
   0551 90 DF 2F            910 	mov	dptr,#_IOCFG2
   0554 74 1B               911 	mov	a,#0x1B
   0556 F0                  912 	movx	@dptr,a
                    0056    913 	C$test_radio_signal_tx.c$50$1$1 ==.
                            914 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:50: dmaConfig.radio.DC6 = 19; // WORDSIZE = 0, TMODE = 0, TRIG = 19
   0557 90 F0 38            915 	mov	dptr,#(_dmaConfig + 0x0006)
   055A 74 13               916 	mov	a,#0x13
   055C F0                  917 	movx	@dptr,a
                    005C    918 	C$test_radio_signal_tx.c$52$1$1 ==.
                            919 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:52: dmaConfig.radio.SRCADDRH = (unsigned int)packet >> 8;
   055D 7E 20               920 	mov	r6,#_packet
   055F 7F F0               921 	mov	r7,#(_packet >> 8)
   0561 8F 06               922 	mov	ar6,r7
   0563 90 F0 32            923 	mov	dptr,#_dmaConfig
   0566 EE                  924 	mov	a,r6
   0567 F0                  925 	movx	@dptr,a
                    0067    926 	C$test_radio_signal_tx.c$53$1$1 ==.
                            927 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:53: dmaConfig.radio.SRCADDRL = (unsigned int)packet;
   0568 7E 20               928 	mov	r6,#_packet
   056A 7F F0               929 	mov	r7,#(_packet >> 8)
   056C 90 F0 33            930 	mov	dptr,#(_dmaConfig + 0x0001)
   056F EE                  931 	mov	a,r6
   0570 F0                  932 	movx	@dptr,a
                    0070    933 	C$test_radio_signal_tx.c$54$1$1 ==.
                            934 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:54: dmaConfig.radio.DESTADDRH = XDATA_SFR_ADDRESS(RFD) >> 8;
   0571 7E D9               935 	mov	r6,#_RFD
   0573 7F 00               936 	mov	r7,#0x00
   0575 74 DF               937 	mov	a,#0xDF
   0577 2F                  938 	add	a,r7
   0578 FE                  939 	mov	r6,a
   0579 90 F0 34            940 	mov	dptr,#(_dmaConfig + 0x0002)
   057C EE                  941 	mov	a,r6
   057D F0                  942 	movx	@dptr,a
                    007D    943 	C$test_radio_signal_tx.c$55$1$1 ==.
                            944 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:55: dmaConfig.radio.DESTADDRL = XDATA_SFR_ADDRESS(RFD);
   057E 7E D9               945 	mov	r6,#_RFD
   0580 90 F0 35            946 	mov	dptr,#(_dmaConfig + 0x0003)
   0583 EE                  947 	mov	a,r6
   0584 F0                  948 	movx	@dptr,a
                    0084    949 	C$test_radio_signal_tx.c$56$1$1 ==.
                            950 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:56: dmaConfig.radio.LENL = 1 + RADIO_PACKET_SIZE;
   0585 90 F0 37            951 	mov	dptr,#(_dmaConfig + 0x0005)
   0588 74 11               952 	mov	a,#0x11
   058A F0                  953 	movx	@dptr,a
                    008A    954 	C$test_radio_signal_tx.c$57$1$1 ==.
                            955 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:57: dmaConfig.radio.VLEN_LENH = 0b00100000; // Transfer length is FirstByte+1
   058B 90 F0 36            956 	mov	dptr,#(_dmaConfig + 0x0004)
   058E 74 20               957 	mov	a,#0x20
   0590 F0                  958 	movx	@dptr,a
                    0090    959 	C$test_radio_signal_tx.c$58$1$1 ==.
                            960 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:58: dmaConfig.radio.DC7 = 0x40; // SRCINC = 1, DESTINC = 0, IRQMASK = 0, M8 = 0, PRIORITY = 0
   0591 90 F0 39            961 	mov	dptr,#(_dmaConfig + 0x0007)
   0594 74 40               962 	mov	a,#0x40
   0596 F0                  963 	movx	@dptr,a
                    0096    964 	C$test_radio_signal_tx.c$60$1$1 ==.
                            965 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:60: for(i = 1; i < sizeof(packet); i++)
   0597 7F 01               966 	mov	r7,#0x01
   0599                     967 00101$:
   0599 BF 11 00            968 	cjne	r7,#0x11,00110$
   059C                     969 00110$:
   059C 50 14               970 	jnc	00104$
                    009D    971 	C$test_radio_signal_tx.c$62$2$2 ==.
                            972 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:62: packet[i] = 'A' + i;
   059E EF                  973 	mov	a,r7
   059F 24 20               974 	add	a,#_packet
   05A1 F5 82               975 	mov	dpl,a
   05A3 E4                  976 	clr	a
   05A4 34 F0               977 	addc	a,#(_packet >> 8)
   05A6 F5 83               978 	mov	dph,a
   05A8 8F 06               979 	mov	ar6,r7
   05AA 74 41               980 	mov	a,#0x41
   05AC 2E                  981 	add	a,r6
   05AD FE                  982 	mov	r6,a
   05AE F0                  983 	movx	@dptr,a
                    00AE    984 	C$test_radio_signal_tx.c$60$1$1 ==.
                            985 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:60: for(i = 1; i < sizeof(packet); i++)
   05AF 0F                  986 	inc	r7
   05B0 80 E7               987 	sjmp	00101$
   05B2                     988 00104$:
                    00B1    989 	C$test_radio_signal_tx.c$64$1$1 ==.
                            990 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:64: packet[0] = RADIO_PACKET_SIZE;
   05B2 90 F0 20            991 	mov	dptr,#_packet
   05B5 74 10               992 	mov	a,#0x10
   05B7 F0                  993 	movx	@dptr,a
                    00B7    994 	C$test_radio_signal_tx.c$66$1$1 ==.
                            995 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:66: RFST = 4;  // Switch radio to Idle mode.
   05B8 75 E1 04            996 	mov	_RFST,#0x04
                    00BA    997 	C$test_radio_signal_tx.c$67$1$1 ==.
                    00BA    998 	XG$perTestTxInit$0$0 ==.
   05BB 22                  999 	ret
                           1000 ;------------------------------------------------------------
                           1001 ;Allocation info for local variables in function 'sendRadioBursts'
                           1002 ;------------------------------------------------------------
                    00BB   1003 	G$sendRadioBursts$0$0 ==.
                    00BB   1004 	C$test_radio_signal_tx.c$69$1$1 ==.
                           1005 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:69: void sendRadioBursts()
                           1006 ;	-----------------------------------------
                           1007 ;	 function sendRadioBursts
                           1008 ;	-----------------------------------------
   05BC                    1009 _sendRadioBursts:
                    00BB   1010 	C$test_radio_signal_tx.c$71$1$1 ==.
                           1011 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:71: uint16 time = (uint16)getMs();
   05BC 12 09 F6           1012 	lcall	_getMs
   05BF AC 82              1013 	mov	r4,dpl
   05C1 AD 83              1014 	mov	r5,dph
                    00C2   1015 	C$test_radio_signal_tx.c$73$1$1 ==.
                           1016 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:73: if ((uint16)(time - lastBurst) > 1000)
   05C3 78 02              1017 	mov	r0,#_lastBurst
   05C5 D3                 1018 	setb	c
   05C6 E2                 1019 	movx	a,@r0
   05C7 9C                 1020 	subb	a,r4
   05C8 F4                 1021 	cpl	a
   05C9 B3                 1022 	cpl	c
   05CA FE                 1023 	mov	r6,a
   05CB B3                 1024 	cpl	c
   05CC 08                 1025 	inc	r0
   05CD E2                 1026 	movx	a,@r0
   05CE 9D                 1027 	subb	a,r5
   05CF F4                 1028 	cpl	a
   05D0 FF                 1029 	mov	r7,a
   05D1 C3                 1030 	clr	c
   05D2 74 E8              1031 	mov	a,#0xE8
   05D4 9E                 1032 	subb	a,r6
   05D5 74 03              1033 	mov	a,#0x03
   05D7 9F                 1034 	subb	a,r7
   05D8 50 11              1035 	jnc	00102$
                    00D9   1036 	C$test_radio_signal_tx.c$75$2$2 ==.
                           1037 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:75: lastBurst = time;
   05DA 78 02              1038 	mov	r0,#_lastBurst
   05DC EC                 1039 	mov	a,r4
   05DD F2                 1040 	movx	@r0,a
   05DE 08                 1041 	inc	r0
   05DF ED                 1042 	mov	a,r5
   05E0 F2                 1043 	movx	@r0,a
                    00E0   1044 	C$test_radio_signal_tx.c$77$2$2 ==.
                           1045 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:77: currentBurstId++;
   05E1 78 00              1046 	mov	r0,#_currentBurstId
   05E3 E2                 1047 	movx	a,@r0
   05E4 24 01              1048 	add	a,#0x01
   05E6 F2                 1049 	movx	@r0,a
                    00E6   1050 	C$test_radio_signal_tx.c$78$2$2 ==.
                           1051 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:78: packetsSent = 0;
   05E7 78 01              1052 	mov	r0,#_packetsSent
   05E9 E4                 1053 	clr	a
   05EA F2                 1054 	movx	@r0,a
   05EB                    1055 00102$:
                    00EA   1056 	C$test_radio_signal_tx.c$81$1$1 ==.
                           1057 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:81: if (packetsSent < 100 && (MARCSTATE == 1))
   05EB 78 01              1058 	mov	r0,#_packetsSent
   05ED E2                 1059 	movx	a,@r0
   05EE B4 64 00           1060 	cjne	a,#0x64,00112$
   05F1                    1061 00112$:
   05F1 50 32              1062 	jnc	00106$
   05F3 90 DF 3B           1063 	mov	dptr,#_MARCSTATE
   05F6 E0                 1064 	movx	a,@dptr
   05F7 FF                 1065 	mov	r7,a
   05F8 BF 01 2A           1066 	cjne	r7,#0x01,00106$
                    00FA   1067 	C$test_radio_signal_tx.c$83$2$3 ==.
                           1068 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:83: packet[1] = packetsSent & 1;
   05FB 78 01              1069 	mov	r0,#_packetsSent
   05FD E2                 1070 	movx	a,@r0
   05FE 54 01              1071 	anl	a,#0x01
   0600 90 F0 21           1072 	mov	dptr,#(_packet + 0x0001)
   0603 F0                 1073 	movx	@dptr,a
                    0103   1074 	C$test_radio_signal_tx.c$84$2$3 ==.
                           1075 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:84: packet[2] = currentBurstId;
   0604 90 F0 22           1076 	mov	dptr,#(_packet + 0x0002)
   0607 78 00              1077 	mov	r0,#_currentBurstId
   0609 E2                 1078 	movx	a,@r0
   060A F0                 1079 	movx	@dptr,a
                    010A   1080 	C$test_radio_signal_tx.c$85$2$3 ==.
                           1081 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:85: packet[3] = packetsSent;
   060B 90 F0 23           1082 	mov	dptr,#(_packet + 0x0003)
   060E 78 01              1083 	mov	r0,#_packetsSent
   0610 E2                 1084 	movx	a,@r0
   0611 F0                 1085 	movx	@dptr,a
                    0111   1086 	C$test_radio_signal_tx.c$86$2$3 ==.
                           1087 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:86: packetsSent++;
   0612 78 01              1088 	mov	r0,#_packetsSent
   0614 E2                 1089 	movx	a,@r0
   0615 24 01              1090 	add	a,#0x01
   0617 F2                 1091 	movx	@r0,a
                    0117   1092 	C$test_radio_signal_tx.c$88$2$3 ==.
                           1093 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:88: RFIF &= ~(1<<4);                   // Clear IRQ_DONE
   0618 AF E9              1094 	mov	r7,_RFIF
   061A 53 07 EF           1095 	anl	ar7,#0xEF
   061D 8F E9              1096 	mov	_RFIF,r7
                    011E   1097 	C$test_radio_signal_tx.c$89$2$3 ==.
                           1098 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:89: DMAARM |= (1<<DMA_CHANNEL_RADIO);  // Arm DMA channel
   061F 43 D6 02           1099 	orl	_DMAARM,#0x02
                    0121   1100 	C$test_radio_signal_tx.c$90$2$3 ==.
                           1101 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:90: RFST = 3;                          // Switch radio to TX
   0622 75 E1 03           1102 	mov	_RFST,#0x03
   0625                    1103 00106$:
                    0124   1104 	C$test_radio_signal_tx.c$93$2$1 ==.
                    0124   1105 	XG$sendRadioBursts$0$0 ==.
   0625 22                 1106 	ret
                           1107 ;------------------------------------------------------------
                           1108 ;Allocation info for local variables in function 'main'
                           1109 ;------------------------------------------------------------
                    0125   1110 	G$main$0$0 ==.
                    0125   1111 	C$test_radio_signal_tx.c$95$2$1 ==.
                           1112 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:95: void main()
                           1113 ;	-----------------------------------------
                           1114 ;	 function main
                           1115 ;	-----------------------------------------
   0626                    1116 _main:
                    0125   1117 	C$test_radio_signal_tx.c$97$1$1 ==.
                           1118 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:97: systemInit();
   0626 12 06 3E           1119 	lcall	_systemInit
                    0128   1120 	C$test_radio_signal_tx.c$98$1$1 ==.
                           1121 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:98: usbInit();
   0629 12 0A 5D           1122 	lcall	_usbInit
                    012B   1123 	C$test_radio_signal_tx.c$99$1$1 ==.
                           1124 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:99: perTestTxInit();
   062C 12 05 28           1125 	lcall	_perTestTxInit
                    012E   1126 	C$test_radio_signal_tx.c$101$1$1 ==.
                           1127 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:101: while(1)
   062F                    1128 00102$:
                    012E   1129 	C$test_radio_signal_tx.c$103$2$2 ==.
                           1130 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:103: boardService();
   062F 12 06 4B           1131 	lcall	_boardService
                    0131   1132 	C$test_radio_signal_tx.c$104$2$2 ==.
                           1133 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:104: updateLeds();
   0632 12 05 01           1134 	lcall	_updateLeds
                    0134   1135 	C$test_radio_signal_tx.c$105$2$2 ==.
                           1136 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:105: usbComService();
   0635 12 08 6F           1137 	lcall	_usbComService
                    0137   1138 	C$test_radio_signal_tx.c$106$2$2 ==.
                           1139 ;	apps/test_radio_signal_tx/test_radio_signal_tx.c:106: sendRadioBursts();
   0638 12 05 BC           1140 	lcall	_sendRadioBursts
   063B 80 F2              1141 	sjmp	00102$
                    013C   1142 	C$test_radio_signal_tx.c$108$1$1 ==.
                    013C   1143 	XG$main$0$0 ==.
   063D 22                 1144 	ret
                           1145 	.area CSEG    (CODE)
                           1146 	.area CONST   (CODE)
                    0000   1147 G$param_radio_channel$0$0 == .
   123D                    1148 _param_radio_channel:
   123D 80 00 00 00        1149 	.byte #0x80,#0x00,#0x00,#0x00	;  128
                           1150 	.area XINIT   (CODE)
                           1151 	.area CABS    (ABS,CODE)
