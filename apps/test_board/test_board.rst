                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Aug 17 17:32:28 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_board
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _updateLeds
                             14 	.globl _getMs
                             15 	.globl _vinPowerPresent
                             16 	.globl _usbPowerPresent
                             17 	.globl _boardService
                             18 	.globl _systemInit
                             19 ;--------------------------------------------------------
                             20 ; special function registers
                             21 ;--------------------------------------------------------
                             22 	.area RSEG    (ABS,DATA)
   0000                      23 	.org 0x0000
                    0080     24 Ftest_board$P0$0$0 == 0x0080
                    0080     25 _P0	=	0x0080
                    0081     26 Ftest_board$SP$0$0 == 0x0081
                    0081     27 _SP	=	0x0081
                    0082     28 Ftest_board$DPL0$0$0 == 0x0082
                    0082     29 _DPL0	=	0x0082
                    0083     30 Ftest_board$DPH0$0$0 == 0x0083
                    0083     31 _DPH0	=	0x0083
                    0084     32 Ftest_board$DPL1$0$0 == 0x0084
                    0084     33 _DPL1	=	0x0084
                    0085     34 Ftest_board$DPH1$0$0 == 0x0085
                    0085     35 _DPH1	=	0x0085
                    0086     36 Ftest_board$U0CSR$0$0 == 0x0086
                    0086     37 _U0CSR	=	0x0086
                    0087     38 Ftest_board$PCON$0$0 == 0x0087
                    0087     39 _PCON	=	0x0087
                    0088     40 Ftest_board$TCON$0$0 == 0x0088
                    0088     41 _TCON	=	0x0088
                    0089     42 Ftest_board$P0IFG$0$0 == 0x0089
                    0089     43 _P0IFG	=	0x0089
                    008A     44 Ftest_board$P1IFG$0$0 == 0x008a
                    008A     45 _P1IFG	=	0x008a
                    008B     46 Ftest_board$P2IFG$0$0 == 0x008b
                    008B     47 _P2IFG	=	0x008b
                    008C     48 Ftest_board$PICTL$0$0 == 0x008c
                    008C     49 _PICTL	=	0x008c
                    008D     50 Ftest_board$P1IEN$0$0 == 0x008d
                    008D     51 _P1IEN	=	0x008d
                    008F     52 Ftest_board$P0INP$0$0 == 0x008f
                    008F     53 _P0INP	=	0x008f
                    0090     54 Ftest_board$P1$0$0 == 0x0090
                    0090     55 _P1	=	0x0090
                    0091     56 Ftest_board$RFIM$0$0 == 0x0091
                    0091     57 _RFIM	=	0x0091
                    0092     58 Ftest_board$DPS$0$0 == 0x0092
                    0092     59 _DPS	=	0x0092
                    0093     60 Ftest_board$MPAGE$0$0 == 0x0093
                    0093     61 _MPAGE	=	0x0093
                    0095     62 Ftest_board$ENDIAN$0$0 == 0x0095
                    0095     63 _ENDIAN	=	0x0095
                    0098     64 Ftest_board$S0CON$0$0 == 0x0098
                    0098     65 _S0CON	=	0x0098
                    009A     66 Ftest_board$IEN2$0$0 == 0x009a
                    009A     67 _IEN2	=	0x009a
                    009B     68 Ftest_board$S1CON$0$0 == 0x009b
                    009B     69 _S1CON	=	0x009b
                    009C     70 Ftest_board$T2CT$0$0 == 0x009c
                    009C     71 _T2CT	=	0x009c
                    009D     72 Ftest_board$T2PR$0$0 == 0x009d
                    009D     73 _T2PR	=	0x009d
                    009E     74 Ftest_board$T2CTL$0$0 == 0x009e
                    009E     75 _T2CTL	=	0x009e
                    00A0     76 Ftest_board$P2$0$0 == 0x00a0
                    00A0     77 _P2	=	0x00a0
                    00A1     78 Ftest_board$WORIRQ$0$0 == 0x00a1
                    00A1     79 _WORIRQ	=	0x00a1
                    00A2     80 Ftest_board$WORCTRL$0$0 == 0x00a2
                    00A2     81 _WORCTRL	=	0x00a2
                    00A3     82 Ftest_board$WOREVT0$0$0 == 0x00a3
                    00A3     83 _WOREVT0	=	0x00a3
                    00A4     84 Ftest_board$WOREVT1$0$0 == 0x00a4
                    00A4     85 _WOREVT1	=	0x00a4
                    00A5     86 Ftest_board$WORTIME0$0$0 == 0x00a5
                    00A5     87 _WORTIME0	=	0x00a5
                    00A6     88 Ftest_board$WORTIME1$0$0 == 0x00a6
                    00A6     89 _WORTIME1	=	0x00a6
                    00A8     90 Ftest_board$IEN0$0$0 == 0x00a8
                    00A8     91 _IEN0	=	0x00a8
                    00A9     92 Ftest_board$IP0$0$0 == 0x00a9
                    00A9     93 _IP0	=	0x00a9
                    00AB     94 Ftest_board$FWT$0$0 == 0x00ab
                    00AB     95 _FWT	=	0x00ab
                    00AC     96 Ftest_board$FADDRL$0$0 == 0x00ac
                    00AC     97 _FADDRL	=	0x00ac
                    00AD     98 Ftest_board$FADDRH$0$0 == 0x00ad
                    00AD     99 _FADDRH	=	0x00ad
                    00AE    100 Ftest_board$FCTL$0$0 == 0x00ae
                    00AE    101 _FCTL	=	0x00ae
                    00AF    102 Ftest_board$FWDATA$0$0 == 0x00af
                    00AF    103 _FWDATA	=	0x00af
                    00B1    104 Ftest_board$ENCDI$0$0 == 0x00b1
                    00B1    105 _ENCDI	=	0x00b1
                    00B2    106 Ftest_board$ENCDO$0$0 == 0x00b2
                    00B2    107 _ENCDO	=	0x00b2
                    00B3    108 Ftest_board$ENCCS$0$0 == 0x00b3
                    00B3    109 _ENCCS	=	0x00b3
                    00B4    110 Ftest_board$ADCCON1$0$0 == 0x00b4
                    00B4    111 _ADCCON1	=	0x00b4
                    00B5    112 Ftest_board$ADCCON2$0$0 == 0x00b5
                    00B5    113 _ADCCON2	=	0x00b5
                    00B6    114 Ftest_board$ADCCON3$0$0 == 0x00b6
                    00B6    115 _ADCCON3	=	0x00b6
                    00B8    116 Ftest_board$IEN1$0$0 == 0x00b8
                    00B8    117 _IEN1	=	0x00b8
                    00B9    118 Ftest_board$IP1$0$0 == 0x00b9
                    00B9    119 _IP1	=	0x00b9
                    00BA    120 Ftest_board$ADCL$0$0 == 0x00ba
                    00BA    121 _ADCL	=	0x00ba
                    00BB    122 Ftest_board$ADCH$0$0 == 0x00bb
                    00BB    123 _ADCH	=	0x00bb
                    00BC    124 Ftest_board$RNDL$0$0 == 0x00bc
                    00BC    125 _RNDL	=	0x00bc
                    00BD    126 Ftest_board$RNDH$0$0 == 0x00bd
                    00BD    127 _RNDH	=	0x00bd
                    00BE    128 Ftest_board$SLEEP$0$0 == 0x00be
                    00BE    129 _SLEEP	=	0x00be
                    00C0    130 Ftest_board$IRCON$0$0 == 0x00c0
                    00C0    131 _IRCON	=	0x00c0
                    00C1    132 Ftest_board$U0DBUF$0$0 == 0x00c1
                    00C1    133 _U0DBUF	=	0x00c1
                    00C2    134 Ftest_board$U0BAUD$0$0 == 0x00c2
                    00C2    135 _U0BAUD	=	0x00c2
                    00C4    136 Ftest_board$U0UCR$0$0 == 0x00c4
                    00C4    137 _U0UCR	=	0x00c4
                    00C5    138 Ftest_board$U0GCR$0$0 == 0x00c5
                    00C5    139 _U0GCR	=	0x00c5
                    00C6    140 Ftest_board$CLKCON$0$0 == 0x00c6
                    00C6    141 _CLKCON	=	0x00c6
                    00C7    142 Ftest_board$MEMCTR$0$0 == 0x00c7
                    00C7    143 _MEMCTR	=	0x00c7
                    00C9    144 Ftest_board$WDCTL$0$0 == 0x00c9
                    00C9    145 _WDCTL	=	0x00c9
                    00CA    146 Ftest_board$T3CNT$0$0 == 0x00ca
                    00CA    147 _T3CNT	=	0x00ca
                    00CB    148 Ftest_board$T3CTL$0$0 == 0x00cb
                    00CB    149 _T3CTL	=	0x00cb
                    00CC    150 Ftest_board$T3CCTL0$0$0 == 0x00cc
                    00CC    151 _T3CCTL0	=	0x00cc
                    00CD    152 Ftest_board$T3CC0$0$0 == 0x00cd
                    00CD    153 _T3CC0	=	0x00cd
                    00CE    154 Ftest_board$T3CCTL1$0$0 == 0x00ce
                    00CE    155 _T3CCTL1	=	0x00ce
                    00CF    156 Ftest_board$T3CC1$0$0 == 0x00cf
                    00CF    157 _T3CC1	=	0x00cf
                    00D0    158 Ftest_board$PSW$0$0 == 0x00d0
                    00D0    159 _PSW	=	0x00d0
                    00D1    160 Ftest_board$DMAIRQ$0$0 == 0x00d1
                    00D1    161 _DMAIRQ	=	0x00d1
                    00D2    162 Ftest_board$DMA1CFGL$0$0 == 0x00d2
                    00D2    163 _DMA1CFGL	=	0x00d2
                    00D3    164 Ftest_board$DMA1CFGH$0$0 == 0x00d3
                    00D3    165 _DMA1CFGH	=	0x00d3
                    00D4    166 Ftest_board$DMA0CFGL$0$0 == 0x00d4
                    00D4    167 _DMA0CFGL	=	0x00d4
                    00D5    168 Ftest_board$DMA0CFGH$0$0 == 0x00d5
                    00D5    169 _DMA0CFGH	=	0x00d5
                    00D6    170 Ftest_board$DMAARM$0$0 == 0x00d6
                    00D6    171 _DMAARM	=	0x00d6
                    00D7    172 Ftest_board$DMAREQ$0$0 == 0x00d7
                    00D7    173 _DMAREQ	=	0x00d7
                    00D8    174 Ftest_board$TIMIF$0$0 == 0x00d8
                    00D8    175 _TIMIF	=	0x00d8
                    00D9    176 Ftest_board$RFD$0$0 == 0x00d9
                    00D9    177 _RFD	=	0x00d9
                    00DA    178 Ftest_board$T1CC0L$0$0 == 0x00da
                    00DA    179 _T1CC0L	=	0x00da
                    00DB    180 Ftest_board$T1CC0H$0$0 == 0x00db
                    00DB    181 _T1CC0H	=	0x00db
                    00DC    182 Ftest_board$T1CC1L$0$0 == 0x00dc
                    00DC    183 _T1CC1L	=	0x00dc
                    00DD    184 Ftest_board$T1CC1H$0$0 == 0x00dd
                    00DD    185 _T1CC1H	=	0x00dd
                    00DE    186 Ftest_board$T1CC2L$0$0 == 0x00de
                    00DE    187 _T1CC2L	=	0x00de
                    00DF    188 Ftest_board$T1CC2H$0$0 == 0x00df
                    00DF    189 _T1CC2H	=	0x00df
                    00E0    190 Ftest_board$ACC$0$0 == 0x00e0
                    00E0    191 _ACC	=	0x00e0
                    00E1    192 Ftest_board$RFST$0$0 == 0x00e1
                    00E1    193 _RFST	=	0x00e1
                    00E2    194 Ftest_board$T1CNTL$0$0 == 0x00e2
                    00E2    195 _T1CNTL	=	0x00e2
                    00E3    196 Ftest_board$T1CNTH$0$0 == 0x00e3
                    00E3    197 _T1CNTH	=	0x00e3
                    00E4    198 Ftest_board$T1CTL$0$0 == 0x00e4
                    00E4    199 _T1CTL	=	0x00e4
                    00E5    200 Ftest_board$T1CCTL0$0$0 == 0x00e5
                    00E5    201 _T1CCTL0	=	0x00e5
                    00E6    202 Ftest_board$T1CCTL1$0$0 == 0x00e6
                    00E6    203 _T1CCTL1	=	0x00e6
                    00E7    204 Ftest_board$T1CCTL2$0$0 == 0x00e7
                    00E7    205 _T1CCTL2	=	0x00e7
                    00E8    206 Ftest_board$IRCON2$0$0 == 0x00e8
                    00E8    207 _IRCON2	=	0x00e8
                    00E9    208 Ftest_board$RFIF$0$0 == 0x00e9
                    00E9    209 _RFIF	=	0x00e9
                    00EA    210 Ftest_board$T4CNT$0$0 == 0x00ea
                    00EA    211 _T4CNT	=	0x00ea
                    00EB    212 Ftest_board$T4CTL$0$0 == 0x00eb
                    00EB    213 _T4CTL	=	0x00eb
                    00EC    214 Ftest_board$T4CCTL0$0$0 == 0x00ec
                    00EC    215 _T4CCTL0	=	0x00ec
                    00ED    216 Ftest_board$T4CC0$0$0 == 0x00ed
                    00ED    217 _T4CC0	=	0x00ed
                    00EE    218 Ftest_board$T4CCTL1$0$0 == 0x00ee
                    00EE    219 _T4CCTL1	=	0x00ee
                    00EF    220 Ftest_board$T4CC1$0$0 == 0x00ef
                    00EF    221 _T4CC1	=	0x00ef
                    00F0    222 Ftest_board$B$0$0 == 0x00f0
                    00F0    223 _B	=	0x00f0
                    00F1    224 Ftest_board$PERCFG$0$0 == 0x00f1
                    00F1    225 _PERCFG	=	0x00f1
                    00F2    226 Ftest_board$ADCCFG$0$0 == 0x00f2
                    00F2    227 _ADCCFG	=	0x00f2
                    00F3    228 Ftest_board$P0SEL$0$0 == 0x00f3
                    00F3    229 _P0SEL	=	0x00f3
                    00F4    230 Ftest_board$P1SEL$0$0 == 0x00f4
                    00F4    231 _P1SEL	=	0x00f4
                    00F5    232 Ftest_board$P2SEL$0$0 == 0x00f5
                    00F5    233 _P2SEL	=	0x00f5
                    00F6    234 Ftest_board$P1INP$0$0 == 0x00f6
                    00F6    235 _P1INP	=	0x00f6
                    00F7    236 Ftest_board$P2INP$0$0 == 0x00f7
                    00F7    237 _P2INP	=	0x00f7
                    00F8    238 Ftest_board$U1CSR$0$0 == 0x00f8
                    00F8    239 _U1CSR	=	0x00f8
                    00F9    240 Ftest_board$U1DBUF$0$0 == 0x00f9
                    00F9    241 _U1DBUF	=	0x00f9
                    00FA    242 Ftest_board$U1BAUD$0$0 == 0x00fa
                    00FA    243 _U1BAUD	=	0x00fa
                    00FB    244 Ftest_board$U1UCR$0$0 == 0x00fb
                    00FB    245 _U1UCR	=	0x00fb
                    00FC    246 Ftest_board$U1GCR$0$0 == 0x00fc
                    00FC    247 _U1GCR	=	0x00fc
                    00FD    248 Ftest_board$P0DIR$0$0 == 0x00fd
                    00FD    249 _P0DIR	=	0x00fd
                    00FE    250 Ftest_board$P1DIR$0$0 == 0x00fe
                    00FE    251 _P1DIR	=	0x00fe
                    00FF    252 Ftest_board$P2DIR$0$0 == 0x00ff
                    00FF    253 _P2DIR	=	0x00ff
                    FFFFD5D4    254 Ftest_board$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    255 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    256 Ftest_board$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    257 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    258 Ftest_board$FADDR$0$0 == 0xffffadac
                    FFFFADAC    259 _FADDR	=	0xffffadac
                    FFFFBBBA    260 Ftest_board$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    261 _ADC	=	0xffffbbba
                    FFFFDBDA    262 Ftest_board$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    263 _T1CC0	=	0xffffdbda
                    FFFFDDDC    264 Ftest_board$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    265 _T1CC1	=	0xffffdddc
                    FFFFDFDE    266 Ftest_board$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    267 _T1CC2	=	0xffffdfde
                            268 ;--------------------------------------------------------
                            269 ; special function bits
                            270 ;--------------------------------------------------------
                            271 	.area RSEG    (ABS,DATA)
   0000                     272 	.org 0x0000
                    0080    273 Ftest_board$P0_0$0$0 == 0x0080
                    0080    274 _P0_0	=	0x0080
                    0081    275 Ftest_board$P0_1$0$0 == 0x0081
                    0081    276 _P0_1	=	0x0081
                    0082    277 Ftest_board$P0_2$0$0 == 0x0082
                    0082    278 _P0_2	=	0x0082
                    0083    279 Ftest_board$P0_3$0$0 == 0x0083
                    0083    280 _P0_3	=	0x0083
                    0084    281 Ftest_board$P0_4$0$0 == 0x0084
                    0084    282 _P0_4	=	0x0084
                    0085    283 Ftest_board$P0_5$0$0 == 0x0085
                    0085    284 _P0_5	=	0x0085
                    0086    285 Ftest_board$P0_6$0$0 == 0x0086
                    0086    286 _P0_6	=	0x0086
                    0087    287 Ftest_board$P0_7$0$0 == 0x0087
                    0087    288 _P0_7	=	0x0087
                    0088    289 Ftest_board$_TCON_0$0$0 == 0x0088
                    0088    290 __TCON_0	=	0x0088
                    0089    291 Ftest_board$RFTXRXIF$0$0 == 0x0089
                    0089    292 _RFTXRXIF	=	0x0089
                    008A    293 Ftest_board$_TCON_2$0$0 == 0x008a
                    008A    294 __TCON_2	=	0x008a
                    008B    295 Ftest_board$URX0IF$0$0 == 0x008b
                    008B    296 _URX0IF	=	0x008b
                    008C    297 Ftest_board$_TCON_4$0$0 == 0x008c
                    008C    298 __TCON_4	=	0x008c
                    008D    299 Ftest_board$ADCIF$0$0 == 0x008d
                    008D    300 _ADCIF	=	0x008d
                    008E    301 Ftest_board$_TCON_6$0$0 == 0x008e
                    008E    302 __TCON_6	=	0x008e
                    008F    303 Ftest_board$URX1IF$0$0 == 0x008f
                    008F    304 _URX1IF	=	0x008f
                    0090    305 Ftest_board$P1_0$0$0 == 0x0090
                    0090    306 _P1_0	=	0x0090
                    0091    307 Ftest_board$P1_1$0$0 == 0x0091
                    0091    308 _P1_1	=	0x0091
                    0092    309 Ftest_board$P1_2$0$0 == 0x0092
                    0092    310 _P1_2	=	0x0092
                    0093    311 Ftest_board$P1_3$0$0 == 0x0093
                    0093    312 _P1_3	=	0x0093
                    0094    313 Ftest_board$P1_4$0$0 == 0x0094
                    0094    314 _P1_4	=	0x0094
                    0095    315 Ftest_board$P1_5$0$0 == 0x0095
                    0095    316 _P1_5	=	0x0095
                    0096    317 Ftest_board$P1_6$0$0 == 0x0096
                    0096    318 _P1_6	=	0x0096
                    0097    319 Ftest_board$P1_7$0$0 == 0x0097
                    0097    320 _P1_7	=	0x0097
                    0098    321 Ftest_board$ENCIF_0$0$0 == 0x0098
                    0098    322 _ENCIF_0	=	0x0098
                    0099    323 Ftest_board$ENCIF_1$0$0 == 0x0099
                    0099    324 _ENCIF_1	=	0x0099
                    009A    325 Ftest_board$_SOCON2$0$0 == 0x009a
                    009A    326 __SOCON2	=	0x009a
                    009B    327 Ftest_board$_SOCON3$0$0 == 0x009b
                    009B    328 __SOCON3	=	0x009b
                    009C    329 Ftest_board$_SOCON4$0$0 == 0x009c
                    009C    330 __SOCON4	=	0x009c
                    009D    331 Ftest_board$_SOCON5$0$0 == 0x009d
                    009D    332 __SOCON5	=	0x009d
                    009E    333 Ftest_board$_SOCON6$0$0 == 0x009e
                    009E    334 __SOCON6	=	0x009e
                    009F    335 Ftest_board$_SOCON7$0$0 == 0x009f
                    009F    336 __SOCON7	=	0x009f
                    00A0    337 Ftest_board$P2_0$0$0 == 0x00a0
                    00A0    338 _P2_0	=	0x00a0
                    00A1    339 Ftest_board$P2_1$0$0 == 0x00a1
                    00A1    340 _P2_1	=	0x00a1
                    00A2    341 Ftest_board$P2_2$0$0 == 0x00a2
                    00A2    342 _P2_2	=	0x00a2
                    00A3    343 Ftest_board$P2_3$0$0 == 0x00a3
                    00A3    344 _P2_3	=	0x00a3
                    00A4    345 Ftest_board$P2_4$0$0 == 0x00a4
                    00A4    346 _P2_4	=	0x00a4
                    00A5    347 Ftest_board$P2_5$0$0 == 0x00a5
                    00A5    348 _P2_5	=	0x00a5
                    00A6    349 Ftest_board$P2_6$0$0 == 0x00a6
                    00A6    350 _P2_6	=	0x00a6
                    00A7    351 Ftest_board$P2_7$0$0 == 0x00a7
                    00A7    352 _P2_7	=	0x00a7
                    00A8    353 Ftest_board$RFTXRXIE$0$0 == 0x00a8
                    00A8    354 _RFTXRXIE	=	0x00a8
                    00A9    355 Ftest_board$ADCIE$0$0 == 0x00a9
                    00A9    356 _ADCIE	=	0x00a9
                    00AA    357 Ftest_board$URX0IE$0$0 == 0x00aa
                    00AA    358 _URX0IE	=	0x00aa
                    00AB    359 Ftest_board$URX1IE$0$0 == 0x00ab
                    00AB    360 _URX1IE	=	0x00ab
                    00AC    361 Ftest_board$ENCIE$0$0 == 0x00ac
                    00AC    362 _ENCIE	=	0x00ac
                    00AD    363 Ftest_board$STIE$0$0 == 0x00ad
                    00AD    364 _STIE	=	0x00ad
                    00AE    365 Ftest_board$_IEN06$0$0 == 0x00ae
                    00AE    366 __IEN06	=	0x00ae
                    00AF    367 Ftest_board$EA$0$0 == 0x00af
                    00AF    368 _EA	=	0x00af
                    00B8    369 Ftest_board$DMAIE$0$0 == 0x00b8
                    00B8    370 _DMAIE	=	0x00b8
                    00B9    371 Ftest_board$T1IE$0$0 == 0x00b9
                    00B9    372 _T1IE	=	0x00b9
                    00BA    373 Ftest_board$T2IE$0$0 == 0x00ba
                    00BA    374 _T2IE	=	0x00ba
                    00BB    375 Ftest_board$T3IE$0$0 == 0x00bb
                    00BB    376 _T3IE	=	0x00bb
                    00BC    377 Ftest_board$T4IE$0$0 == 0x00bc
                    00BC    378 _T4IE	=	0x00bc
                    00BD    379 Ftest_board$P0IE$0$0 == 0x00bd
                    00BD    380 _P0IE	=	0x00bd
                    00BE    381 Ftest_board$_IEN16$0$0 == 0x00be
                    00BE    382 __IEN16	=	0x00be
                    00BF    383 Ftest_board$_IEN17$0$0 == 0x00bf
                    00BF    384 __IEN17	=	0x00bf
                    00C0    385 Ftest_board$DMAIF$0$0 == 0x00c0
                    00C0    386 _DMAIF	=	0x00c0
                    00C1    387 Ftest_board$T1IF$0$0 == 0x00c1
                    00C1    388 _T1IF	=	0x00c1
                    00C2    389 Ftest_board$T2IF$0$0 == 0x00c2
                    00C2    390 _T2IF	=	0x00c2
                    00C3    391 Ftest_board$T3IF$0$0 == 0x00c3
                    00C3    392 _T3IF	=	0x00c3
                    00C4    393 Ftest_board$T4IF$0$0 == 0x00c4
                    00C4    394 _T4IF	=	0x00c4
                    00C5    395 Ftest_board$P0IF$0$0 == 0x00c5
                    00C5    396 _P0IF	=	0x00c5
                    00C6    397 Ftest_board$_IRCON6$0$0 == 0x00c6
                    00C6    398 __IRCON6	=	0x00c6
                    00C7    399 Ftest_board$STIF$0$0 == 0x00c7
                    00C7    400 _STIF	=	0x00c7
                    00D0    401 Ftest_board$P$0$0 == 0x00d0
                    00D0    402 _P	=	0x00d0
                    00D1    403 Ftest_board$F1$0$0 == 0x00d1
                    00D1    404 _F1	=	0x00d1
                    00D2    405 Ftest_board$OV$0$0 == 0x00d2
                    00D2    406 _OV	=	0x00d2
                    00D3    407 Ftest_board$RS0$0$0 == 0x00d3
                    00D3    408 _RS0	=	0x00d3
                    00D4    409 Ftest_board$RS1$0$0 == 0x00d4
                    00D4    410 _RS1	=	0x00d4
                    00D5    411 Ftest_board$F0$0$0 == 0x00d5
                    00D5    412 _F0	=	0x00d5
                    00D6    413 Ftest_board$AC$0$0 == 0x00d6
                    00D6    414 _AC	=	0x00d6
                    00D7    415 Ftest_board$CY$0$0 == 0x00d7
                    00D7    416 _CY	=	0x00d7
                    00D8    417 Ftest_board$T3OVFIF$0$0 == 0x00d8
                    00D8    418 _T3OVFIF	=	0x00d8
                    00D9    419 Ftest_board$T3CH0IF$0$0 == 0x00d9
                    00D9    420 _T3CH0IF	=	0x00d9
                    00DA    421 Ftest_board$T3CH1IF$0$0 == 0x00da
                    00DA    422 _T3CH1IF	=	0x00da
                    00DB    423 Ftest_board$T4OVFIF$0$0 == 0x00db
                    00DB    424 _T4OVFIF	=	0x00db
                    00DC    425 Ftest_board$T4CH0IF$0$0 == 0x00dc
                    00DC    426 _T4CH0IF	=	0x00dc
                    00DD    427 Ftest_board$T4CH1IF$0$0 == 0x00dd
                    00DD    428 _T4CH1IF	=	0x00dd
                    00DE    429 Ftest_board$OVFIM$0$0 == 0x00de
                    00DE    430 _OVFIM	=	0x00de
                    00DF    431 Ftest_board$_TIMIF7$0$0 == 0x00df
                    00DF    432 __TIMIF7	=	0x00df
                    00E0    433 Ftest_board$ACC_0$0$0 == 0x00e0
                    00E0    434 _ACC_0	=	0x00e0
                    00E1    435 Ftest_board$ACC_1$0$0 == 0x00e1
                    00E1    436 _ACC_1	=	0x00e1
                    00E2    437 Ftest_board$ACC_2$0$0 == 0x00e2
                    00E2    438 _ACC_2	=	0x00e2
                    00E3    439 Ftest_board$ACC_3$0$0 == 0x00e3
                    00E3    440 _ACC_3	=	0x00e3
                    00E4    441 Ftest_board$ACC_4$0$0 == 0x00e4
                    00E4    442 _ACC_4	=	0x00e4
                    00E5    443 Ftest_board$ACC_5$0$0 == 0x00e5
                    00E5    444 _ACC_5	=	0x00e5
                    00E6    445 Ftest_board$ACC_6$0$0 == 0x00e6
                    00E6    446 _ACC_6	=	0x00e6
                    00E7    447 Ftest_board$ACC_7$0$0 == 0x00e7
                    00E7    448 _ACC_7	=	0x00e7
                    00E8    449 Ftest_board$P2IF$0$0 == 0x00e8
                    00E8    450 _P2IF	=	0x00e8
                    00E9    451 Ftest_board$UTX0IF$0$0 == 0x00e9
                    00E9    452 _UTX0IF	=	0x00e9
                    00EA    453 Ftest_board$UTX1IF$0$0 == 0x00ea
                    00EA    454 _UTX1IF	=	0x00ea
                    00EB    455 Ftest_board$P1IF$0$0 == 0x00eb
                    00EB    456 _P1IF	=	0x00eb
                    00EC    457 Ftest_board$WDTIF$0$0 == 0x00ec
                    00EC    458 _WDTIF	=	0x00ec
                    00ED    459 Ftest_board$_IRCON25$0$0 == 0x00ed
                    00ED    460 __IRCON25	=	0x00ed
                    00EE    461 Ftest_board$_IRCON26$0$0 == 0x00ee
                    00EE    462 __IRCON26	=	0x00ee
                    00EF    463 Ftest_board$_IRCON27$0$0 == 0x00ef
                    00EF    464 __IRCON27	=	0x00ef
                    00F0    465 Ftest_board$B_0$0$0 == 0x00f0
                    00F0    466 _B_0	=	0x00f0
                    00F1    467 Ftest_board$B_1$0$0 == 0x00f1
                    00F1    468 _B_1	=	0x00f1
                    00F2    469 Ftest_board$B_2$0$0 == 0x00f2
                    00F2    470 _B_2	=	0x00f2
                    00F3    471 Ftest_board$B_3$0$0 == 0x00f3
                    00F3    472 _B_3	=	0x00f3
                    00F4    473 Ftest_board$B_4$0$0 == 0x00f4
                    00F4    474 _B_4	=	0x00f4
                    00F5    475 Ftest_board$B_5$0$0 == 0x00f5
                    00F5    476 _B_5	=	0x00f5
                    00F6    477 Ftest_board$B_6$0$0 == 0x00f6
                    00F6    478 _B_6	=	0x00f6
                    00F7    479 Ftest_board$B_7$0$0 == 0x00f7
                    00F7    480 _B_7	=	0x00f7
                    00F8    481 Ftest_board$U1ACTIVE$0$0 == 0x00f8
                    00F8    482 _U1ACTIVE	=	0x00f8
                    00F9    483 Ftest_board$U1TX_BYTE$0$0 == 0x00f9
                    00F9    484 _U1TX_BYTE	=	0x00f9
                    00FA    485 Ftest_board$U1RX_BYTE$0$0 == 0x00fa
                    00FA    486 _U1RX_BYTE	=	0x00fa
                    00FB    487 Ftest_board$U1ERR$0$0 == 0x00fb
                    00FB    488 _U1ERR	=	0x00fb
                    00FC    489 Ftest_board$U1FE$0$0 == 0x00fc
                    00FC    490 _U1FE	=	0x00fc
                    00FD    491 Ftest_board$U1SLAVE$0$0 == 0x00fd
                    00FD    492 _U1SLAVE	=	0x00fd
                    00FE    493 Ftest_board$U1RE$0$0 == 0x00fe
                    00FE    494 _U1RE	=	0x00fe
                    00FF    495 Ftest_board$U1MODE$0$0 == 0x00ff
                    00FF    496 _U1MODE	=	0x00ff
                            497 ;--------------------------------------------------------
                            498 ; overlayable register banks
                            499 ;--------------------------------------------------------
                            500 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     501 	.ds 8
                            502 ;--------------------------------------------------------
                            503 ; internal ram data
                            504 ;--------------------------------------------------------
                            505 	.area DSEG    (DATA)
                            506 ;--------------------------------------------------------
                            507 ; overlayable items in internal ram 
                            508 ;--------------------------------------------------------
                            509 	.area OSEG    (OVR,DATA)
                            510 ;--------------------------------------------------------
                            511 ; Stack segment in internal ram 
                            512 ;--------------------------------------------------------
                            513 	.area	SSEG	(DATA)
   0021                     514 __start__stack:
   0021                     515 	.ds	1
                            516 
                            517 ;--------------------------------------------------------
                            518 ; indirectly addressable internal ram data
                            519 ;--------------------------------------------------------
                            520 	.area ISEG    (DATA)
                            521 ;--------------------------------------------------------
                            522 ; absolute internal ram data
                            523 ;--------------------------------------------------------
                            524 	.area IABS    (ABS,DATA)
                            525 	.area IABS    (ABS,DATA)
                            526 ;--------------------------------------------------------
                            527 ; bit data
                            528 ;--------------------------------------------------------
                            529 	.area BSEG    (BIT)
                            530 ;--------------------------------------------------------
                            531 ; paged external ram data
                            532 ;--------------------------------------------------------
                            533 	.area PSEG    (PAG,XDATA)
                            534 ;--------------------------------------------------------
                            535 ; external ram data
                            536 ;--------------------------------------------------------
                            537 	.area XSEG    (XDATA)
                    DF00    538 Ftest_board$SYNC1$0$0 == 0xdf00
                    DF00    539 _SYNC1	=	0xdf00
                    DF01    540 Ftest_board$SYNC0$0$0 == 0xdf01
                    DF01    541 _SYNC0	=	0xdf01
                    DF02    542 Ftest_board$PKTLEN$0$0 == 0xdf02
                    DF02    543 _PKTLEN	=	0xdf02
                    DF03    544 Ftest_board$PKTCTRL1$0$0 == 0xdf03
                    DF03    545 _PKTCTRL1	=	0xdf03
                    DF04    546 Ftest_board$PKTCTRL0$0$0 == 0xdf04
                    DF04    547 _PKTCTRL0	=	0xdf04
                    DF05    548 Ftest_board$ADDR$0$0 == 0xdf05
                    DF05    549 _ADDR	=	0xdf05
                    DF06    550 Ftest_board$CHANNR$0$0 == 0xdf06
                    DF06    551 _CHANNR	=	0xdf06
                    DF07    552 Ftest_board$FSCTRL1$0$0 == 0xdf07
                    DF07    553 _FSCTRL1	=	0xdf07
                    DF08    554 Ftest_board$FSCTRL0$0$0 == 0xdf08
                    DF08    555 _FSCTRL0	=	0xdf08
                    DF09    556 Ftest_board$FREQ2$0$0 == 0xdf09
                    DF09    557 _FREQ2	=	0xdf09
                    DF0A    558 Ftest_board$FREQ1$0$0 == 0xdf0a
                    DF0A    559 _FREQ1	=	0xdf0a
                    DF0B    560 Ftest_board$FREQ0$0$0 == 0xdf0b
                    DF0B    561 _FREQ0	=	0xdf0b
                    DF0C    562 Ftest_board$MDMCFG4$0$0 == 0xdf0c
                    DF0C    563 _MDMCFG4	=	0xdf0c
                    DF0D    564 Ftest_board$MDMCFG3$0$0 == 0xdf0d
                    DF0D    565 _MDMCFG3	=	0xdf0d
                    DF0E    566 Ftest_board$MDMCFG2$0$0 == 0xdf0e
                    DF0E    567 _MDMCFG2	=	0xdf0e
                    DF0F    568 Ftest_board$MDMCFG1$0$0 == 0xdf0f
                    DF0F    569 _MDMCFG1	=	0xdf0f
                    DF10    570 Ftest_board$MDMCFG0$0$0 == 0xdf10
                    DF10    571 _MDMCFG0	=	0xdf10
                    DF11    572 Ftest_board$DEVIATN$0$0 == 0xdf11
                    DF11    573 _DEVIATN	=	0xdf11
                    DF12    574 Ftest_board$MCSM2$0$0 == 0xdf12
                    DF12    575 _MCSM2	=	0xdf12
                    DF13    576 Ftest_board$MCSM1$0$0 == 0xdf13
                    DF13    577 _MCSM1	=	0xdf13
                    DF14    578 Ftest_board$MCSM0$0$0 == 0xdf14
                    DF14    579 _MCSM0	=	0xdf14
                    DF15    580 Ftest_board$FOCCFG$0$0 == 0xdf15
                    DF15    581 _FOCCFG	=	0xdf15
                    DF16    582 Ftest_board$BSCFG$0$0 == 0xdf16
                    DF16    583 _BSCFG	=	0xdf16
                    DF17    584 Ftest_board$AGCCTRL2$0$0 == 0xdf17
                    DF17    585 _AGCCTRL2	=	0xdf17
                    DF18    586 Ftest_board$AGCCTRL1$0$0 == 0xdf18
                    DF18    587 _AGCCTRL1	=	0xdf18
                    DF19    588 Ftest_board$AGCCTRL0$0$0 == 0xdf19
                    DF19    589 _AGCCTRL0	=	0xdf19
                    DF1A    590 Ftest_board$FREND1$0$0 == 0xdf1a
                    DF1A    591 _FREND1	=	0xdf1a
                    DF1B    592 Ftest_board$FREND0$0$0 == 0xdf1b
                    DF1B    593 _FREND0	=	0xdf1b
                    DF1C    594 Ftest_board$FSCAL3$0$0 == 0xdf1c
                    DF1C    595 _FSCAL3	=	0xdf1c
                    DF1D    596 Ftest_board$FSCAL2$0$0 == 0xdf1d
                    DF1D    597 _FSCAL2	=	0xdf1d
                    DF1E    598 Ftest_board$FSCAL1$0$0 == 0xdf1e
                    DF1E    599 _FSCAL1	=	0xdf1e
                    DF1F    600 Ftest_board$FSCAL0$0$0 == 0xdf1f
                    DF1F    601 _FSCAL0	=	0xdf1f
                    DF23    602 Ftest_board$TEST2$0$0 == 0xdf23
                    DF23    603 _TEST2	=	0xdf23
                    DF24    604 Ftest_board$TEST1$0$0 == 0xdf24
                    DF24    605 _TEST1	=	0xdf24
                    DF25    606 Ftest_board$TEST0$0$0 == 0xdf25
                    DF25    607 _TEST0	=	0xdf25
                    DF2E    608 Ftest_board$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    609 _PA_TABLE0	=	0xdf2e
                    DF2F    610 Ftest_board$IOCFG2$0$0 == 0xdf2f
                    DF2F    611 _IOCFG2	=	0xdf2f
                    DF30    612 Ftest_board$IOCFG1$0$0 == 0xdf30
                    DF30    613 _IOCFG1	=	0xdf30
                    DF31    614 Ftest_board$IOCFG0$0$0 == 0xdf31
                    DF31    615 _IOCFG0	=	0xdf31
                    DF36    616 Ftest_board$PARTNUM$0$0 == 0xdf36
                    DF36    617 _PARTNUM	=	0xdf36
                    DF37    618 Ftest_board$VERSION$0$0 == 0xdf37
                    DF37    619 _VERSION	=	0xdf37
                    DF38    620 Ftest_board$FREQEST$0$0 == 0xdf38
                    DF38    621 _FREQEST	=	0xdf38
                    DF39    622 Ftest_board$LQI$0$0 == 0xdf39
                    DF39    623 _LQI	=	0xdf39
                    DF3A    624 Ftest_board$RSSI$0$0 == 0xdf3a
                    DF3A    625 _RSSI	=	0xdf3a
                    DF3B    626 Ftest_board$MARCSTATE$0$0 == 0xdf3b
                    DF3B    627 _MARCSTATE	=	0xdf3b
                    DF3C    628 Ftest_board$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    629 _PKTSTATUS	=	0xdf3c
                    DF3D    630 Ftest_board$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    631 _VCO_VC_DAC	=	0xdf3d
                    DF40    632 Ftest_board$I2SCFG0$0$0 == 0xdf40
                    DF40    633 _I2SCFG0	=	0xdf40
                    DF41    634 Ftest_board$I2SCFG1$0$0 == 0xdf41
                    DF41    635 _I2SCFG1	=	0xdf41
                    DF42    636 Ftest_board$I2SDATL$0$0 == 0xdf42
                    DF42    637 _I2SDATL	=	0xdf42
                    DF43    638 Ftest_board$I2SDATH$0$0 == 0xdf43
                    DF43    639 _I2SDATH	=	0xdf43
                    DF44    640 Ftest_board$I2SWCNT$0$0 == 0xdf44
                    DF44    641 _I2SWCNT	=	0xdf44
                    DF45    642 Ftest_board$I2SSTAT$0$0 == 0xdf45
                    DF45    643 _I2SSTAT	=	0xdf45
                    DF46    644 Ftest_board$I2SCLKF0$0$0 == 0xdf46
                    DF46    645 _I2SCLKF0	=	0xdf46
                    DF47    646 Ftest_board$I2SCLKF1$0$0 == 0xdf47
                    DF47    647 _I2SCLKF1	=	0xdf47
                    DF48    648 Ftest_board$I2SCLKF2$0$0 == 0xdf48
                    DF48    649 _I2SCLKF2	=	0xdf48
                    DE00    650 Ftest_board$USBADDR$0$0 == 0xde00
                    DE00    651 _USBADDR	=	0xde00
                    DE01    652 Ftest_board$USBPOW$0$0 == 0xde01
                    DE01    653 _USBPOW	=	0xde01
                    DE02    654 Ftest_board$USBIIF$0$0 == 0xde02
                    DE02    655 _USBIIF	=	0xde02
                    DE04    656 Ftest_board$USBOIF$0$0 == 0xde04
                    DE04    657 _USBOIF	=	0xde04
                    DE06    658 Ftest_board$USBCIF$0$0 == 0xde06
                    DE06    659 _USBCIF	=	0xde06
                    DE07    660 Ftest_board$USBIIE$0$0 == 0xde07
                    DE07    661 _USBIIE	=	0xde07
                    DE09    662 Ftest_board$USBOIE$0$0 == 0xde09
                    DE09    663 _USBOIE	=	0xde09
                    DE0B    664 Ftest_board$USBCIE$0$0 == 0xde0b
                    DE0B    665 _USBCIE	=	0xde0b
                    DE0C    666 Ftest_board$USBFRML$0$0 == 0xde0c
                    DE0C    667 _USBFRML	=	0xde0c
                    DE0D    668 Ftest_board$USBFRMH$0$0 == 0xde0d
                    DE0D    669 _USBFRMH	=	0xde0d
                    DE0E    670 Ftest_board$USBINDEX$0$0 == 0xde0e
                    DE0E    671 _USBINDEX	=	0xde0e
                    DE10    672 Ftest_board$USBMAXI$0$0 == 0xde10
                    DE10    673 _USBMAXI	=	0xde10
                    DE11    674 Ftest_board$USBCSIL$0$0 == 0xde11
                    DE11    675 _USBCSIL	=	0xde11
                    DE12    676 Ftest_board$USBCSIH$0$0 == 0xde12
                    DE12    677 _USBCSIH	=	0xde12
                    DE13    678 Ftest_board$USBMAXO$0$0 == 0xde13
                    DE13    679 _USBMAXO	=	0xde13
                    DE14    680 Ftest_board$USBCSOL$0$0 == 0xde14
                    DE14    681 _USBCSOL	=	0xde14
                    DE15    682 Ftest_board$USBCSOH$0$0 == 0xde15
                    DE15    683 _USBCSOH	=	0xde15
                    DE16    684 Ftest_board$USBCNTL$0$0 == 0xde16
                    DE16    685 _USBCNTL	=	0xde16
                    DE17    686 Ftest_board$USBCNTH$0$0 == 0xde17
                    DE17    687 _USBCNTH	=	0xde17
                    DE20    688 Ftest_board$USBF0$0$0 == 0xde20
                    DE20    689 _USBF0	=	0xde20
                    DE22    690 Ftest_board$USBF1$0$0 == 0xde22
                    DE22    691 _USBF1	=	0xde22
                    DE24    692 Ftest_board$USBF2$0$0 == 0xde24
                    DE24    693 _USBF2	=	0xde24
                    DE26    694 Ftest_board$USBF3$0$0 == 0xde26
                    DE26    695 _USBF3	=	0xde26
                    DE28    696 Ftest_board$USBF4$0$0 == 0xde28
                    DE28    697 _USBF4	=	0xde28
                    DE2A    698 Ftest_board$USBF5$0$0 == 0xde2a
                    DE2A    699 _USBF5	=	0xde2a
                            700 ;--------------------------------------------------------
                            701 ; absolute external ram data
                            702 ;--------------------------------------------------------
                            703 	.area XABS    (ABS,XDATA)
                            704 ;--------------------------------------------------------
                            705 ; external initialized ram data
                            706 ;--------------------------------------------------------
                            707 	.area XISEG   (XDATA)
                            708 	.area HOME    (CODE)
                            709 	.area GSINIT0 (CODE)
                            710 	.area GSINIT1 (CODE)
                            711 	.area GSINIT2 (CODE)
                            712 	.area GSINIT3 (CODE)
                            713 	.area GSINIT4 (CODE)
                            714 	.area GSINIT5 (CODE)
                            715 	.area GSINIT  (CODE)
                            716 	.area GSFINAL (CODE)
                            717 	.area CSEG    (CODE)
                            718 ;--------------------------------------------------------
                            719 ; interrupt vector 
                            720 ;--------------------------------------------------------
                            721 	.area HOME    (CODE)
   0400                     722 __interrupt_vect:
   0400 02 04 6B            723 	ljmp	__sdcc_gsinit_startup
   0403 32                  724 	reti
   0404                     725 	.ds	7
   040B 32                  726 	reti
   040C                     727 	.ds	7
   0413 32                  728 	reti
   0414                     729 	.ds	7
   041B 32                  730 	reti
   041C                     731 	.ds	7
   0423 32                  732 	reti
   0424                     733 	.ds	7
   042B 32                  734 	reti
   042C                     735 	.ds	7
   0433 32                  736 	reti
   0434                     737 	.ds	7
   043B 32                  738 	reti
   043C                     739 	.ds	7
   0443 32                  740 	reti
   0444                     741 	.ds	7
   044B 32                  742 	reti
   044C                     743 	.ds	7
   0453 32                  744 	reti
   0454                     745 	.ds	7
   045B 32                  746 	reti
   045C                     747 	.ds	7
   0463 02 05 F1            748 	ljmp	_ISR_T4
                            749 ;--------------------------------------------------------
                            750 ; global & static initialisations
                            751 ;--------------------------------------------------------
                            752 	.area HOME    (CODE)
                            753 	.area GSINIT  (CODE)
                            754 	.area GSFINAL (CODE)
                            755 	.area GSINIT  (CODE)
                            756 	.globl __sdcc_gsinit_startup
                            757 	.globl __sdcc_program_startup
                            758 	.globl __start__stack
                            759 	.globl __mcs51_genXINIT
                            760 	.globl __mcs51_genXRAMCLEAR
                            761 	.globl __mcs51_genRAMCLEAR
                            762 	.area GSFINAL (CODE)
   04C9 02 04 66            763 	ljmp	__sdcc_program_startup
                            764 ;--------------------------------------------------------
                            765 ; Home
                            766 ;--------------------------------------------------------
                            767 	.area HOME    (CODE)
                            768 	.area HOME    (CODE)
   0466                     769 __sdcc_program_startup:
   0466 12 05 0A            770 	lcall	_main
                            771 ;	return from main will lock up
   0469 80 FE               772 	sjmp .
                            773 ;--------------------------------------------------------
                            774 ; code
                            775 ;--------------------------------------------------------
                            776 	.area CSEG    (CODE)
                            777 ;------------------------------------------------------------
                            778 ;Allocation info for local variables in function 'updateLeds'
                            779 ;------------------------------------------------------------
                    0000    780 	G$updateLeds$0$0 ==.
                    0000    781 	C$test_board.c$23$0$0 ==.
                            782 ;	apps/test_board/test_board.c:23: void updateLeds()
                            783 ;	-----------------------------------------
                            784 ;	 function updateLeds
                            785 ;	-----------------------------------------
   04CC                     786 _updateLeds:
                    0007    787 	ar7 = 0x07
                    0006    788 	ar6 = 0x06
                    0005    789 	ar5 = 0x05
                    0004    790 	ar4 = 0x04
                    0003    791 	ar3 = 0x03
                    0002    792 	ar2 = 0x02
                    0001    793 	ar1 = 0x01
                    0000    794 	ar0 = 0x00
                    0000    795 	C$test_board.c$25$2$2 ==.
                            796 ;	apps/test_board/test_board.c:25: LED_GREEN(getMs() >> 9 & 1);    // Blink the Green LED (only visible w/ USB).
   04CC 12 06 16            797 	lcall	_getMs
   04CF AD 83               798 	mov	r5,dph
   04D1 AE F0               799 	mov	r6,b
   04D3 FF                  800 	mov	r7,a
   04D4 ED                  801 	mov	a,r5
   04D5 03                  802 	rr	a
   04D6 54 01               803 	anl	a,#0x01
   04D8 FC                  804 	mov	r4,a
   04D9 60 05               805 	jz	00103$
   04DB 43 FF 10            806 	orl	_P2DIR,#0x10
   04DE 80 07               807 	sjmp	00104$
   04E0                     808 00103$:
   04E0 AF FF               809 	mov	r7,_P2DIR
   04E2 53 07 EF            810 	anl	ar7,#0xEF
   04E5 8F FF               811 	mov	_P2DIR,r7
   04E7                     812 00104$:
                    001B    813 	C$test_board.c$26$2$3 ==.
                            814 ;	apps/test_board/test_board.c:26: LED_YELLOW(vinPowerPresent());  // Indicate VIN power with the yellow LED.
   04E7 12 05 E0            815 	lcall	_vinPowerPresent
   04EA 50 05               816 	jnc	00105$
   04EC 43 FF 04            817 	orl	_P2DIR,#0x04
   04EF 80 07               818 	sjmp	00106$
   04F1                     819 00105$:
   04F1 AF FF               820 	mov	r7,_P2DIR
   04F3 53 07 FB            821 	anl	ar7,#0xFB
   04F6 8F FF               822 	mov	_P2DIR,r7
   04F8                     823 00106$:
                    002C    824 	C$test_board.c$27$2$4 ==.
                            825 ;	apps/test_board/test_board.c:27: LED_RED(usbPowerPresent());     // Indicate USB power with the red LED.
   04F8 12 05 DA            826 	lcall	_usbPowerPresent
   04FB 50 05               827 	jnc	00107$
   04FD 43 FF 02            828 	orl	_P2DIR,#0x02
   0500 80 07               829 	sjmp	00101$
   0502                     830 00107$:
   0502 AF FF               831 	mov	r7,_P2DIR
   0504 53 07 FD            832 	anl	ar7,#0xFD
   0507 8F FF               833 	mov	_P2DIR,r7
   0509                     834 00101$:
                    003D    835 	C$test_board.c$28$2$4 ==.
                    003D    836 	XG$updateLeds$0$0 ==.
   0509 22                  837 	ret
                            838 ;------------------------------------------------------------
                            839 ;Allocation info for local variables in function 'main'
                            840 ;------------------------------------------------------------
                    003E    841 	G$main$0$0 ==.
                    003E    842 	C$test_board.c$30$2$4 ==.
                            843 ;	apps/test_board/test_board.c:30: void main()
                            844 ;	-----------------------------------------
                            845 ;	 function main
                            846 ;	-----------------------------------------
   050A                     847 _main:
                    003E    848 	C$test_board.c$32$1$1 ==.
                            849 ;	apps/test_board/test_board.c:32: systemInit();
   050A 12 05 16            850 	lcall	_systemInit
                    0041    851 	C$test_board.c$33$1$1 ==.
                            852 ;	apps/test_board/test_board.c:33: while(1)
   050D                     853 00102$:
                    0041    854 	C$test_board.c$35$2$2 ==.
                            855 ;	apps/test_board/test_board.c:35: boardService();
   050D 12 05 23            856 	lcall	_boardService
                    0044    857 	C$test_board.c$36$2$2 ==.
                            858 ;	apps/test_board/test_board.c:36: updateLeds();
   0510 12 04 CC            859 	lcall	_updateLeds
   0513 80 F8               860 	sjmp	00102$
                    0049    861 	C$test_board.c$38$1$1 ==.
                    0049    862 	XG$main$0$0 ==.
   0515 22                  863 	ret
                            864 	.area CSEG    (CODE)
                            865 	.area CONST   (CODE)
                            866 	.area XINIT   (CODE)
                            867 	.area CABS    (ABS,CODE)
