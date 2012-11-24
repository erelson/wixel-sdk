                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:02 2012
                              5 ;--------------------------------------------------------
                              6 	.module test_adc
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_report_period_ms
                             13 	.globl _param_bar_graph
                             14 	.globl _param_input_mode
                             15 	.globl _main
                             16 	.globl _analogInputsInit
                             17 	.globl _sendReportIfNeeded
                             18 	.globl _printBar
                             19 	.globl _updateLeds
                             20 	.globl _printf
                             21 	.globl _usbComTxSend
                             22 	.globl _usbComTxAvailable
                             23 	.globl _usbComService
                             24 	.globl _usbShowStatusWithGreenLed
                             25 	.globl _usbInit
                             26 	.globl _adcConvertToMillivolts
                             27 	.globl _adcSetMillivoltCalibration
                             28 	.globl _adcReadVddMillivolts
                             29 	.globl _adcRead
                             30 	.globl _getMs
                             31 	.globl _boardService
                             32 	.globl _systemInit
                             33 	.globl _report
                             34 	.globl _printBar_PARM_2
                             35 	.globl _reportBytesSent
                             36 	.globl _reportLength
                             37 	.globl _putchar
                             38 ;--------------------------------------------------------
                             39 ; special function registers
                             40 ;--------------------------------------------------------
                             41 	.area RSEG    (ABS,DATA)
   0000                      42 	.org 0x0000
                    0080     43 Ftest_adc$P0$0$0 == 0x0080
                    0080     44 _P0	=	0x0080
                    0081     45 Ftest_adc$SP$0$0 == 0x0081
                    0081     46 _SP	=	0x0081
                    0082     47 Ftest_adc$DPL0$0$0 == 0x0082
                    0082     48 _DPL0	=	0x0082
                    0083     49 Ftest_adc$DPH0$0$0 == 0x0083
                    0083     50 _DPH0	=	0x0083
                    0084     51 Ftest_adc$DPL1$0$0 == 0x0084
                    0084     52 _DPL1	=	0x0084
                    0085     53 Ftest_adc$DPH1$0$0 == 0x0085
                    0085     54 _DPH1	=	0x0085
                    0086     55 Ftest_adc$U0CSR$0$0 == 0x0086
                    0086     56 _U0CSR	=	0x0086
                    0087     57 Ftest_adc$PCON$0$0 == 0x0087
                    0087     58 _PCON	=	0x0087
                    0088     59 Ftest_adc$TCON$0$0 == 0x0088
                    0088     60 _TCON	=	0x0088
                    0089     61 Ftest_adc$P0IFG$0$0 == 0x0089
                    0089     62 _P0IFG	=	0x0089
                    008A     63 Ftest_adc$P1IFG$0$0 == 0x008a
                    008A     64 _P1IFG	=	0x008a
                    008B     65 Ftest_adc$P2IFG$0$0 == 0x008b
                    008B     66 _P2IFG	=	0x008b
                    008C     67 Ftest_adc$PICTL$0$0 == 0x008c
                    008C     68 _PICTL	=	0x008c
                    008D     69 Ftest_adc$P1IEN$0$0 == 0x008d
                    008D     70 _P1IEN	=	0x008d
                    008F     71 Ftest_adc$P0INP$0$0 == 0x008f
                    008F     72 _P0INP	=	0x008f
                    0090     73 Ftest_adc$P1$0$0 == 0x0090
                    0090     74 _P1	=	0x0090
                    0091     75 Ftest_adc$RFIM$0$0 == 0x0091
                    0091     76 _RFIM	=	0x0091
                    0092     77 Ftest_adc$DPS$0$0 == 0x0092
                    0092     78 _DPS	=	0x0092
                    0093     79 Ftest_adc$MPAGE$0$0 == 0x0093
                    0093     80 _MPAGE	=	0x0093
                    0095     81 Ftest_adc$ENDIAN$0$0 == 0x0095
                    0095     82 _ENDIAN	=	0x0095
                    0098     83 Ftest_adc$S0CON$0$0 == 0x0098
                    0098     84 _S0CON	=	0x0098
                    009A     85 Ftest_adc$IEN2$0$0 == 0x009a
                    009A     86 _IEN2	=	0x009a
                    009B     87 Ftest_adc$S1CON$0$0 == 0x009b
                    009B     88 _S1CON	=	0x009b
                    009C     89 Ftest_adc$T2CT$0$0 == 0x009c
                    009C     90 _T2CT	=	0x009c
                    009D     91 Ftest_adc$T2PR$0$0 == 0x009d
                    009D     92 _T2PR	=	0x009d
                    009E     93 Ftest_adc$T2CTL$0$0 == 0x009e
                    009E     94 _T2CTL	=	0x009e
                    00A0     95 Ftest_adc$P2$0$0 == 0x00a0
                    00A0     96 _P2	=	0x00a0
                    00A1     97 Ftest_adc$WORIRQ$0$0 == 0x00a1
                    00A1     98 _WORIRQ	=	0x00a1
                    00A2     99 Ftest_adc$WORCTRL$0$0 == 0x00a2
                    00A2    100 _WORCTRL	=	0x00a2
                    00A3    101 Ftest_adc$WOREVT0$0$0 == 0x00a3
                    00A3    102 _WOREVT0	=	0x00a3
                    00A4    103 Ftest_adc$WOREVT1$0$0 == 0x00a4
                    00A4    104 _WOREVT1	=	0x00a4
                    00A5    105 Ftest_adc$WORTIME0$0$0 == 0x00a5
                    00A5    106 _WORTIME0	=	0x00a5
                    00A6    107 Ftest_adc$WORTIME1$0$0 == 0x00a6
                    00A6    108 _WORTIME1	=	0x00a6
                    00A8    109 Ftest_adc$IEN0$0$0 == 0x00a8
                    00A8    110 _IEN0	=	0x00a8
                    00A9    111 Ftest_adc$IP0$0$0 == 0x00a9
                    00A9    112 _IP0	=	0x00a9
                    00AB    113 Ftest_adc$FWT$0$0 == 0x00ab
                    00AB    114 _FWT	=	0x00ab
                    00AC    115 Ftest_adc$FADDRL$0$0 == 0x00ac
                    00AC    116 _FADDRL	=	0x00ac
                    00AD    117 Ftest_adc$FADDRH$0$0 == 0x00ad
                    00AD    118 _FADDRH	=	0x00ad
                    00AE    119 Ftest_adc$FCTL$0$0 == 0x00ae
                    00AE    120 _FCTL	=	0x00ae
                    00AF    121 Ftest_adc$FWDATA$0$0 == 0x00af
                    00AF    122 _FWDATA	=	0x00af
                    00B1    123 Ftest_adc$ENCDI$0$0 == 0x00b1
                    00B1    124 _ENCDI	=	0x00b1
                    00B2    125 Ftest_adc$ENCDO$0$0 == 0x00b2
                    00B2    126 _ENCDO	=	0x00b2
                    00B3    127 Ftest_adc$ENCCS$0$0 == 0x00b3
                    00B3    128 _ENCCS	=	0x00b3
                    00B4    129 Ftest_adc$ADCCON1$0$0 == 0x00b4
                    00B4    130 _ADCCON1	=	0x00b4
                    00B5    131 Ftest_adc$ADCCON2$0$0 == 0x00b5
                    00B5    132 _ADCCON2	=	0x00b5
                    00B6    133 Ftest_adc$ADCCON3$0$0 == 0x00b6
                    00B6    134 _ADCCON3	=	0x00b6
                    00B8    135 Ftest_adc$IEN1$0$0 == 0x00b8
                    00B8    136 _IEN1	=	0x00b8
                    00B9    137 Ftest_adc$IP1$0$0 == 0x00b9
                    00B9    138 _IP1	=	0x00b9
                    00BA    139 Ftest_adc$ADCL$0$0 == 0x00ba
                    00BA    140 _ADCL	=	0x00ba
                    00BB    141 Ftest_adc$ADCH$0$0 == 0x00bb
                    00BB    142 _ADCH	=	0x00bb
                    00BC    143 Ftest_adc$RNDL$0$0 == 0x00bc
                    00BC    144 _RNDL	=	0x00bc
                    00BD    145 Ftest_adc$RNDH$0$0 == 0x00bd
                    00BD    146 _RNDH	=	0x00bd
                    00BE    147 Ftest_adc$SLEEP$0$0 == 0x00be
                    00BE    148 _SLEEP	=	0x00be
                    00C0    149 Ftest_adc$IRCON$0$0 == 0x00c0
                    00C0    150 _IRCON	=	0x00c0
                    00C1    151 Ftest_adc$U0DBUF$0$0 == 0x00c1
                    00C1    152 _U0DBUF	=	0x00c1
                    00C2    153 Ftest_adc$U0BAUD$0$0 == 0x00c2
                    00C2    154 _U0BAUD	=	0x00c2
                    00C4    155 Ftest_adc$U0UCR$0$0 == 0x00c4
                    00C4    156 _U0UCR	=	0x00c4
                    00C5    157 Ftest_adc$U0GCR$0$0 == 0x00c5
                    00C5    158 _U0GCR	=	0x00c5
                    00C6    159 Ftest_adc$CLKCON$0$0 == 0x00c6
                    00C6    160 _CLKCON	=	0x00c6
                    00C7    161 Ftest_adc$MEMCTR$0$0 == 0x00c7
                    00C7    162 _MEMCTR	=	0x00c7
                    00C9    163 Ftest_adc$WDCTL$0$0 == 0x00c9
                    00C9    164 _WDCTL	=	0x00c9
                    00CA    165 Ftest_adc$T3CNT$0$0 == 0x00ca
                    00CA    166 _T3CNT	=	0x00ca
                    00CB    167 Ftest_adc$T3CTL$0$0 == 0x00cb
                    00CB    168 _T3CTL	=	0x00cb
                    00CC    169 Ftest_adc$T3CCTL0$0$0 == 0x00cc
                    00CC    170 _T3CCTL0	=	0x00cc
                    00CD    171 Ftest_adc$T3CC0$0$0 == 0x00cd
                    00CD    172 _T3CC0	=	0x00cd
                    00CE    173 Ftest_adc$T3CCTL1$0$0 == 0x00ce
                    00CE    174 _T3CCTL1	=	0x00ce
                    00CF    175 Ftest_adc$T3CC1$0$0 == 0x00cf
                    00CF    176 _T3CC1	=	0x00cf
                    00D0    177 Ftest_adc$PSW$0$0 == 0x00d0
                    00D0    178 _PSW	=	0x00d0
                    00D1    179 Ftest_adc$DMAIRQ$0$0 == 0x00d1
                    00D1    180 _DMAIRQ	=	0x00d1
                    00D2    181 Ftest_adc$DMA1CFGL$0$0 == 0x00d2
                    00D2    182 _DMA1CFGL	=	0x00d2
                    00D3    183 Ftest_adc$DMA1CFGH$0$0 == 0x00d3
                    00D3    184 _DMA1CFGH	=	0x00d3
                    00D4    185 Ftest_adc$DMA0CFGL$0$0 == 0x00d4
                    00D4    186 _DMA0CFGL	=	0x00d4
                    00D5    187 Ftest_adc$DMA0CFGH$0$0 == 0x00d5
                    00D5    188 _DMA0CFGH	=	0x00d5
                    00D6    189 Ftest_adc$DMAARM$0$0 == 0x00d6
                    00D6    190 _DMAARM	=	0x00d6
                    00D7    191 Ftest_adc$DMAREQ$0$0 == 0x00d7
                    00D7    192 _DMAREQ	=	0x00d7
                    00D8    193 Ftest_adc$TIMIF$0$0 == 0x00d8
                    00D8    194 _TIMIF	=	0x00d8
                    00D9    195 Ftest_adc$RFD$0$0 == 0x00d9
                    00D9    196 _RFD	=	0x00d9
                    00DA    197 Ftest_adc$T1CC0L$0$0 == 0x00da
                    00DA    198 _T1CC0L	=	0x00da
                    00DB    199 Ftest_adc$T1CC0H$0$0 == 0x00db
                    00DB    200 _T1CC0H	=	0x00db
                    00DC    201 Ftest_adc$T1CC1L$0$0 == 0x00dc
                    00DC    202 _T1CC1L	=	0x00dc
                    00DD    203 Ftest_adc$T1CC1H$0$0 == 0x00dd
                    00DD    204 _T1CC1H	=	0x00dd
                    00DE    205 Ftest_adc$T1CC2L$0$0 == 0x00de
                    00DE    206 _T1CC2L	=	0x00de
                    00DF    207 Ftest_adc$T1CC2H$0$0 == 0x00df
                    00DF    208 _T1CC2H	=	0x00df
                    00E0    209 Ftest_adc$ACC$0$0 == 0x00e0
                    00E0    210 _ACC	=	0x00e0
                    00E1    211 Ftest_adc$RFST$0$0 == 0x00e1
                    00E1    212 _RFST	=	0x00e1
                    00E2    213 Ftest_adc$T1CNTL$0$0 == 0x00e2
                    00E2    214 _T1CNTL	=	0x00e2
                    00E3    215 Ftest_adc$T1CNTH$0$0 == 0x00e3
                    00E3    216 _T1CNTH	=	0x00e3
                    00E4    217 Ftest_adc$T1CTL$0$0 == 0x00e4
                    00E4    218 _T1CTL	=	0x00e4
                    00E5    219 Ftest_adc$T1CCTL0$0$0 == 0x00e5
                    00E5    220 _T1CCTL0	=	0x00e5
                    00E6    221 Ftest_adc$T1CCTL1$0$0 == 0x00e6
                    00E6    222 _T1CCTL1	=	0x00e6
                    00E7    223 Ftest_adc$T1CCTL2$0$0 == 0x00e7
                    00E7    224 _T1CCTL2	=	0x00e7
                    00E8    225 Ftest_adc$IRCON2$0$0 == 0x00e8
                    00E8    226 _IRCON2	=	0x00e8
                    00E9    227 Ftest_adc$RFIF$0$0 == 0x00e9
                    00E9    228 _RFIF	=	0x00e9
                    00EA    229 Ftest_adc$T4CNT$0$0 == 0x00ea
                    00EA    230 _T4CNT	=	0x00ea
                    00EB    231 Ftest_adc$T4CTL$0$0 == 0x00eb
                    00EB    232 _T4CTL	=	0x00eb
                    00EC    233 Ftest_adc$T4CCTL0$0$0 == 0x00ec
                    00EC    234 _T4CCTL0	=	0x00ec
                    00ED    235 Ftest_adc$T4CC0$0$0 == 0x00ed
                    00ED    236 _T4CC0	=	0x00ed
                    00EE    237 Ftest_adc$T4CCTL1$0$0 == 0x00ee
                    00EE    238 _T4CCTL1	=	0x00ee
                    00EF    239 Ftest_adc$T4CC1$0$0 == 0x00ef
                    00EF    240 _T4CC1	=	0x00ef
                    00F0    241 Ftest_adc$B$0$0 == 0x00f0
                    00F0    242 _B	=	0x00f0
                    00F1    243 Ftest_adc$PERCFG$0$0 == 0x00f1
                    00F1    244 _PERCFG	=	0x00f1
                    00F2    245 Ftest_adc$ADCCFG$0$0 == 0x00f2
                    00F2    246 _ADCCFG	=	0x00f2
                    00F3    247 Ftest_adc$P0SEL$0$0 == 0x00f3
                    00F3    248 _P0SEL	=	0x00f3
                    00F4    249 Ftest_adc$P1SEL$0$0 == 0x00f4
                    00F4    250 _P1SEL	=	0x00f4
                    00F5    251 Ftest_adc$P2SEL$0$0 == 0x00f5
                    00F5    252 _P2SEL	=	0x00f5
                    00F6    253 Ftest_adc$P1INP$0$0 == 0x00f6
                    00F6    254 _P1INP	=	0x00f6
                    00F7    255 Ftest_adc$P2INP$0$0 == 0x00f7
                    00F7    256 _P2INP	=	0x00f7
                    00F8    257 Ftest_adc$U1CSR$0$0 == 0x00f8
                    00F8    258 _U1CSR	=	0x00f8
                    00F9    259 Ftest_adc$U1DBUF$0$0 == 0x00f9
                    00F9    260 _U1DBUF	=	0x00f9
                    00FA    261 Ftest_adc$U1BAUD$0$0 == 0x00fa
                    00FA    262 _U1BAUD	=	0x00fa
                    00FB    263 Ftest_adc$U1UCR$0$0 == 0x00fb
                    00FB    264 _U1UCR	=	0x00fb
                    00FC    265 Ftest_adc$U1GCR$0$0 == 0x00fc
                    00FC    266 _U1GCR	=	0x00fc
                    00FD    267 Ftest_adc$P0DIR$0$0 == 0x00fd
                    00FD    268 _P0DIR	=	0x00fd
                    00FE    269 Ftest_adc$P1DIR$0$0 == 0x00fe
                    00FE    270 _P1DIR	=	0x00fe
                    00FF    271 Ftest_adc$P2DIR$0$0 == 0x00ff
                    00FF    272 _P2DIR	=	0x00ff
                    FFFFD5D4    273 Ftest_adc$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    274 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    275 Ftest_adc$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    276 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    277 Ftest_adc$FADDR$0$0 == 0xffffadac
                    FFFFADAC    278 _FADDR	=	0xffffadac
                    FFFFBBBA    279 Ftest_adc$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    280 _ADC	=	0xffffbbba
                    FFFFDBDA    281 Ftest_adc$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    282 _T1CC0	=	0xffffdbda
                    FFFFDDDC    283 Ftest_adc$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    284 _T1CC1	=	0xffffdddc
                    FFFFDFDE    285 Ftest_adc$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    286 _T1CC2	=	0xffffdfde
                            287 ;--------------------------------------------------------
                            288 ; special function bits
                            289 ;--------------------------------------------------------
                            290 	.area RSEG    (ABS,DATA)
   0000                     291 	.org 0x0000
                    0080    292 Ftest_adc$P0_0$0$0 == 0x0080
                    0080    293 _P0_0	=	0x0080
                    0081    294 Ftest_adc$P0_1$0$0 == 0x0081
                    0081    295 _P0_1	=	0x0081
                    0082    296 Ftest_adc$P0_2$0$0 == 0x0082
                    0082    297 _P0_2	=	0x0082
                    0083    298 Ftest_adc$P0_3$0$0 == 0x0083
                    0083    299 _P0_3	=	0x0083
                    0084    300 Ftest_adc$P0_4$0$0 == 0x0084
                    0084    301 _P0_4	=	0x0084
                    0085    302 Ftest_adc$P0_5$0$0 == 0x0085
                    0085    303 _P0_5	=	0x0085
                    0086    304 Ftest_adc$P0_6$0$0 == 0x0086
                    0086    305 _P0_6	=	0x0086
                    0087    306 Ftest_adc$P0_7$0$0 == 0x0087
                    0087    307 _P0_7	=	0x0087
                    0088    308 Ftest_adc$_TCON_0$0$0 == 0x0088
                    0088    309 __TCON_0	=	0x0088
                    0089    310 Ftest_adc$RFTXRXIF$0$0 == 0x0089
                    0089    311 _RFTXRXIF	=	0x0089
                    008A    312 Ftest_adc$_TCON_2$0$0 == 0x008a
                    008A    313 __TCON_2	=	0x008a
                    008B    314 Ftest_adc$URX0IF$0$0 == 0x008b
                    008B    315 _URX0IF	=	0x008b
                    008C    316 Ftest_adc$_TCON_4$0$0 == 0x008c
                    008C    317 __TCON_4	=	0x008c
                    008D    318 Ftest_adc$ADCIF$0$0 == 0x008d
                    008D    319 _ADCIF	=	0x008d
                    008E    320 Ftest_adc$_TCON_6$0$0 == 0x008e
                    008E    321 __TCON_6	=	0x008e
                    008F    322 Ftest_adc$URX1IF$0$0 == 0x008f
                    008F    323 _URX1IF	=	0x008f
                    0090    324 Ftest_adc$P1_0$0$0 == 0x0090
                    0090    325 _P1_0	=	0x0090
                    0091    326 Ftest_adc$P1_1$0$0 == 0x0091
                    0091    327 _P1_1	=	0x0091
                    0092    328 Ftest_adc$P1_2$0$0 == 0x0092
                    0092    329 _P1_2	=	0x0092
                    0093    330 Ftest_adc$P1_3$0$0 == 0x0093
                    0093    331 _P1_3	=	0x0093
                    0094    332 Ftest_adc$P1_4$0$0 == 0x0094
                    0094    333 _P1_4	=	0x0094
                    0095    334 Ftest_adc$P1_5$0$0 == 0x0095
                    0095    335 _P1_5	=	0x0095
                    0096    336 Ftest_adc$P1_6$0$0 == 0x0096
                    0096    337 _P1_6	=	0x0096
                    0097    338 Ftest_adc$P1_7$0$0 == 0x0097
                    0097    339 _P1_7	=	0x0097
                    0098    340 Ftest_adc$ENCIF_0$0$0 == 0x0098
                    0098    341 _ENCIF_0	=	0x0098
                    0099    342 Ftest_adc$ENCIF_1$0$0 == 0x0099
                    0099    343 _ENCIF_1	=	0x0099
                    009A    344 Ftest_adc$_SOCON2$0$0 == 0x009a
                    009A    345 __SOCON2	=	0x009a
                    009B    346 Ftest_adc$_SOCON3$0$0 == 0x009b
                    009B    347 __SOCON3	=	0x009b
                    009C    348 Ftest_adc$_SOCON4$0$0 == 0x009c
                    009C    349 __SOCON4	=	0x009c
                    009D    350 Ftest_adc$_SOCON5$0$0 == 0x009d
                    009D    351 __SOCON5	=	0x009d
                    009E    352 Ftest_adc$_SOCON6$0$0 == 0x009e
                    009E    353 __SOCON6	=	0x009e
                    009F    354 Ftest_adc$_SOCON7$0$0 == 0x009f
                    009F    355 __SOCON7	=	0x009f
                    00A0    356 Ftest_adc$P2_0$0$0 == 0x00a0
                    00A0    357 _P2_0	=	0x00a0
                    00A1    358 Ftest_adc$P2_1$0$0 == 0x00a1
                    00A1    359 _P2_1	=	0x00a1
                    00A2    360 Ftest_adc$P2_2$0$0 == 0x00a2
                    00A2    361 _P2_2	=	0x00a2
                    00A3    362 Ftest_adc$P2_3$0$0 == 0x00a3
                    00A3    363 _P2_3	=	0x00a3
                    00A4    364 Ftest_adc$P2_4$0$0 == 0x00a4
                    00A4    365 _P2_4	=	0x00a4
                    00A5    366 Ftest_adc$P2_5$0$0 == 0x00a5
                    00A5    367 _P2_5	=	0x00a5
                    00A6    368 Ftest_adc$P2_6$0$0 == 0x00a6
                    00A6    369 _P2_6	=	0x00a6
                    00A7    370 Ftest_adc$P2_7$0$0 == 0x00a7
                    00A7    371 _P2_7	=	0x00a7
                    00A8    372 Ftest_adc$RFTXRXIE$0$0 == 0x00a8
                    00A8    373 _RFTXRXIE	=	0x00a8
                    00A9    374 Ftest_adc$ADCIE$0$0 == 0x00a9
                    00A9    375 _ADCIE	=	0x00a9
                    00AA    376 Ftest_adc$URX0IE$0$0 == 0x00aa
                    00AA    377 _URX0IE	=	0x00aa
                    00AB    378 Ftest_adc$URX1IE$0$0 == 0x00ab
                    00AB    379 _URX1IE	=	0x00ab
                    00AC    380 Ftest_adc$ENCIE$0$0 == 0x00ac
                    00AC    381 _ENCIE	=	0x00ac
                    00AD    382 Ftest_adc$STIE$0$0 == 0x00ad
                    00AD    383 _STIE	=	0x00ad
                    00AE    384 Ftest_adc$_IEN06$0$0 == 0x00ae
                    00AE    385 __IEN06	=	0x00ae
                    00AF    386 Ftest_adc$EA$0$0 == 0x00af
                    00AF    387 _EA	=	0x00af
                    00B8    388 Ftest_adc$DMAIE$0$0 == 0x00b8
                    00B8    389 _DMAIE	=	0x00b8
                    00B9    390 Ftest_adc$T1IE$0$0 == 0x00b9
                    00B9    391 _T1IE	=	0x00b9
                    00BA    392 Ftest_adc$T2IE$0$0 == 0x00ba
                    00BA    393 _T2IE	=	0x00ba
                    00BB    394 Ftest_adc$T3IE$0$0 == 0x00bb
                    00BB    395 _T3IE	=	0x00bb
                    00BC    396 Ftest_adc$T4IE$0$0 == 0x00bc
                    00BC    397 _T4IE	=	0x00bc
                    00BD    398 Ftest_adc$P0IE$0$0 == 0x00bd
                    00BD    399 _P0IE	=	0x00bd
                    00BE    400 Ftest_adc$_IEN16$0$0 == 0x00be
                    00BE    401 __IEN16	=	0x00be
                    00BF    402 Ftest_adc$_IEN17$0$0 == 0x00bf
                    00BF    403 __IEN17	=	0x00bf
                    00C0    404 Ftest_adc$DMAIF$0$0 == 0x00c0
                    00C0    405 _DMAIF	=	0x00c0
                    00C1    406 Ftest_adc$T1IF$0$0 == 0x00c1
                    00C1    407 _T1IF	=	0x00c1
                    00C2    408 Ftest_adc$T2IF$0$0 == 0x00c2
                    00C2    409 _T2IF	=	0x00c2
                    00C3    410 Ftest_adc$T3IF$0$0 == 0x00c3
                    00C3    411 _T3IF	=	0x00c3
                    00C4    412 Ftest_adc$T4IF$0$0 == 0x00c4
                    00C4    413 _T4IF	=	0x00c4
                    00C5    414 Ftest_adc$P0IF$0$0 == 0x00c5
                    00C5    415 _P0IF	=	0x00c5
                    00C6    416 Ftest_adc$_IRCON6$0$0 == 0x00c6
                    00C6    417 __IRCON6	=	0x00c6
                    00C7    418 Ftest_adc$STIF$0$0 == 0x00c7
                    00C7    419 _STIF	=	0x00c7
                    00D0    420 Ftest_adc$P$0$0 == 0x00d0
                    00D0    421 _P	=	0x00d0
                    00D1    422 Ftest_adc$F1$0$0 == 0x00d1
                    00D1    423 _F1	=	0x00d1
                    00D2    424 Ftest_adc$OV$0$0 == 0x00d2
                    00D2    425 _OV	=	0x00d2
                    00D3    426 Ftest_adc$RS0$0$0 == 0x00d3
                    00D3    427 _RS0	=	0x00d3
                    00D4    428 Ftest_adc$RS1$0$0 == 0x00d4
                    00D4    429 _RS1	=	0x00d4
                    00D5    430 Ftest_adc$F0$0$0 == 0x00d5
                    00D5    431 _F0	=	0x00d5
                    00D6    432 Ftest_adc$AC$0$0 == 0x00d6
                    00D6    433 _AC	=	0x00d6
                    00D7    434 Ftest_adc$CY$0$0 == 0x00d7
                    00D7    435 _CY	=	0x00d7
                    00D8    436 Ftest_adc$T3OVFIF$0$0 == 0x00d8
                    00D8    437 _T3OVFIF	=	0x00d8
                    00D9    438 Ftest_adc$T3CH0IF$0$0 == 0x00d9
                    00D9    439 _T3CH0IF	=	0x00d9
                    00DA    440 Ftest_adc$T3CH1IF$0$0 == 0x00da
                    00DA    441 _T3CH1IF	=	0x00da
                    00DB    442 Ftest_adc$T4OVFIF$0$0 == 0x00db
                    00DB    443 _T4OVFIF	=	0x00db
                    00DC    444 Ftest_adc$T4CH0IF$0$0 == 0x00dc
                    00DC    445 _T4CH0IF	=	0x00dc
                    00DD    446 Ftest_adc$T4CH1IF$0$0 == 0x00dd
                    00DD    447 _T4CH1IF	=	0x00dd
                    00DE    448 Ftest_adc$OVFIM$0$0 == 0x00de
                    00DE    449 _OVFIM	=	0x00de
                    00DF    450 Ftest_adc$_TIMIF7$0$0 == 0x00df
                    00DF    451 __TIMIF7	=	0x00df
                    00E0    452 Ftest_adc$ACC_0$0$0 == 0x00e0
                    00E0    453 _ACC_0	=	0x00e0
                    00E1    454 Ftest_adc$ACC_1$0$0 == 0x00e1
                    00E1    455 _ACC_1	=	0x00e1
                    00E2    456 Ftest_adc$ACC_2$0$0 == 0x00e2
                    00E2    457 _ACC_2	=	0x00e2
                    00E3    458 Ftest_adc$ACC_3$0$0 == 0x00e3
                    00E3    459 _ACC_3	=	0x00e3
                    00E4    460 Ftest_adc$ACC_4$0$0 == 0x00e4
                    00E4    461 _ACC_4	=	0x00e4
                    00E5    462 Ftest_adc$ACC_5$0$0 == 0x00e5
                    00E5    463 _ACC_5	=	0x00e5
                    00E6    464 Ftest_adc$ACC_6$0$0 == 0x00e6
                    00E6    465 _ACC_6	=	0x00e6
                    00E7    466 Ftest_adc$ACC_7$0$0 == 0x00e7
                    00E7    467 _ACC_7	=	0x00e7
                    00E8    468 Ftest_adc$P2IF$0$0 == 0x00e8
                    00E8    469 _P2IF	=	0x00e8
                    00E9    470 Ftest_adc$UTX0IF$0$0 == 0x00e9
                    00E9    471 _UTX0IF	=	0x00e9
                    00EA    472 Ftest_adc$UTX1IF$0$0 == 0x00ea
                    00EA    473 _UTX1IF	=	0x00ea
                    00EB    474 Ftest_adc$P1IF$0$0 == 0x00eb
                    00EB    475 _P1IF	=	0x00eb
                    00EC    476 Ftest_adc$WDTIF$0$0 == 0x00ec
                    00EC    477 _WDTIF	=	0x00ec
                    00ED    478 Ftest_adc$_IRCON25$0$0 == 0x00ed
                    00ED    479 __IRCON25	=	0x00ed
                    00EE    480 Ftest_adc$_IRCON26$0$0 == 0x00ee
                    00EE    481 __IRCON26	=	0x00ee
                    00EF    482 Ftest_adc$_IRCON27$0$0 == 0x00ef
                    00EF    483 __IRCON27	=	0x00ef
                    00F0    484 Ftest_adc$B_0$0$0 == 0x00f0
                    00F0    485 _B_0	=	0x00f0
                    00F1    486 Ftest_adc$B_1$0$0 == 0x00f1
                    00F1    487 _B_1	=	0x00f1
                    00F2    488 Ftest_adc$B_2$0$0 == 0x00f2
                    00F2    489 _B_2	=	0x00f2
                    00F3    490 Ftest_adc$B_3$0$0 == 0x00f3
                    00F3    491 _B_3	=	0x00f3
                    00F4    492 Ftest_adc$B_4$0$0 == 0x00f4
                    00F4    493 _B_4	=	0x00f4
                    00F5    494 Ftest_adc$B_5$0$0 == 0x00f5
                    00F5    495 _B_5	=	0x00f5
                    00F6    496 Ftest_adc$B_6$0$0 == 0x00f6
                    00F6    497 _B_6	=	0x00f6
                    00F7    498 Ftest_adc$B_7$0$0 == 0x00f7
                    00F7    499 _B_7	=	0x00f7
                    00F8    500 Ftest_adc$U1ACTIVE$0$0 == 0x00f8
                    00F8    501 _U1ACTIVE	=	0x00f8
                    00F9    502 Ftest_adc$U1TX_BYTE$0$0 == 0x00f9
                    00F9    503 _U1TX_BYTE	=	0x00f9
                    00FA    504 Ftest_adc$U1RX_BYTE$0$0 == 0x00fa
                    00FA    505 _U1RX_BYTE	=	0x00fa
                    00FB    506 Ftest_adc$U1ERR$0$0 == 0x00fb
                    00FB    507 _U1ERR	=	0x00fb
                    00FC    508 Ftest_adc$U1FE$0$0 == 0x00fc
                    00FC    509 _U1FE	=	0x00fc
                    00FD    510 Ftest_adc$U1SLAVE$0$0 == 0x00fd
                    00FD    511 _U1SLAVE	=	0x00fd
                    00FE    512 Ftest_adc$U1RE$0$0 == 0x00fe
                    00FE    513 _U1RE	=	0x00fe
                    00FF    514 Ftest_adc$U1MODE$0$0 == 0x00ff
                    00FF    515 _U1MODE	=	0x00ff
                            516 ;--------------------------------------------------------
                            517 ; overlayable register banks
                            518 ;--------------------------------------------------------
                            519 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     520 	.ds 8
                            521 ;--------------------------------------------------------
                            522 ; internal ram data
                            523 ;--------------------------------------------------------
                            524 	.area DSEG    (DATA)
                    0000    525 G$reportLength$0$0==.
   0008                     526 _reportLength::
   0008                     527 	.ds 2
                    0002    528 G$reportBytesSent$0$0==.
   000A                     529 _reportBytesSent::
   000A                     530 	.ds 2
                    0004    531 Ltest_adc.sendReportIfNeeded$sloc0$1$0==.
   000C                     532 _sendReportIfNeeded_sloc0_1_0:
   000C                     533 	.ds 4
                    0008    534 Ltest_adc.sendReportIfNeeded$sloc1$1$0==.
   0010                     535 _sendReportIfNeeded_sloc1_1_0:
   0010                     536 	.ds 2
                    000A    537 Ltest_adc.sendReportIfNeeded$sloc2$1$0==.
   0012                     538 _sendReportIfNeeded_sloc2_1_0:
   0012                     539 	.ds 2
                            540 ;--------------------------------------------------------
                            541 ; overlayable items in internal ram 
                            542 ;--------------------------------------------------------
                            543 	.area OSEG    (OVR,DATA)
                            544 ;--------------------------------------------------------
                            545 ; Stack segment in internal ram 
                            546 ;--------------------------------------------------------
                            547 	.area	SSEG	(DATA)
   0027                     548 __start__stack:
   0027                     549 	.ds	1
                            550 
                            551 ;--------------------------------------------------------
                            552 ; indirectly addressable internal ram data
                            553 ;--------------------------------------------------------
                            554 	.area ISEG    (DATA)
                            555 ;--------------------------------------------------------
                            556 ; absolute internal ram data
                            557 ;--------------------------------------------------------
                            558 	.area IABS    (ABS,DATA)
                            559 	.area IABS    (ABS,DATA)
                            560 ;--------------------------------------------------------
                            561 ; bit data
                            562 ;--------------------------------------------------------
                            563 	.area BSEG    (BIT)
                            564 ;--------------------------------------------------------
                            565 ; paged external ram data
                            566 ;--------------------------------------------------------
                            567 	.area PSEG    (PAG,XDATA)
                    0000    568 Ltest_adc.printBar$adcResult$1$1==.
   F000                     569 _printBar_PARM_2:
   F000                     570 	.ds 2
                    0002    571 Ltest_adc.sendReportIfNeeded$lastReport$1$1==.
   F002                     572 _sendReportIfNeeded_lastReport_1_1:
   F002                     573 	.ds 4
                    0006    574 Ltest_adc.sendReportIfNeeded$result$1$1==.
   F006                     575 _sendReportIfNeeded_result_1_1:
   F006                     576 	.ds 12
                    0012    577 Ltest_adc.sendReportIfNeeded$vddMillivolts$1$1==.
   F012                     578 _sendReportIfNeeded_vddMillivolts_1_1:
   F012                     579 	.ds 2
                            580 ;--------------------------------------------------------
                            581 ; external ram data
                            582 ;--------------------------------------------------------
                            583 	.area XSEG    (XDATA)
                    DF00    584 Ftest_adc$SYNC1$0$0 == 0xdf00
                    DF00    585 _SYNC1	=	0xdf00
                    DF01    586 Ftest_adc$SYNC0$0$0 == 0xdf01
                    DF01    587 _SYNC0	=	0xdf01
                    DF02    588 Ftest_adc$PKTLEN$0$0 == 0xdf02
                    DF02    589 _PKTLEN	=	0xdf02
                    DF03    590 Ftest_adc$PKTCTRL1$0$0 == 0xdf03
                    DF03    591 _PKTCTRL1	=	0xdf03
                    DF04    592 Ftest_adc$PKTCTRL0$0$0 == 0xdf04
                    DF04    593 _PKTCTRL0	=	0xdf04
                    DF05    594 Ftest_adc$ADDR$0$0 == 0xdf05
                    DF05    595 _ADDR	=	0xdf05
                    DF06    596 Ftest_adc$CHANNR$0$0 == 0xdf06
                    DF06    597 _CHANNR	=	0xdf06
                    DF07    598 Ftest_adc$FSCTRL1$0$0 == 0xdf07
                    DF07    599 _FSCTRL1	=	0xdf07
                    DF08    600 Ftest_adc$FSCTRL0$0$0 == 0xdf08
                    DF08    601 _FSCTRL0	=	0xdf08
                    DF09    602 Ftest_adc$FREQ2$0$0 == 0xdf09
                    DF09    603 _FREQ2	=	0xdf09
                    DF0A    604 Ftest_adc$FREQ1$0$0 == 0xdf0a
                    DF0A    605 _FREQ1	=	0xdf0a
                    DF0B    606 Ftest_adc$FREQ0$0$0 == 0xdf0b
                    DF0B    607 _FREQ0	=	0xdf0b
                    DF0C    608 Ftest_adc$MDMCFG4$0$0 == 0xdf0c
                    DF0C    609 _MDMCFG4	=	0xdf0c
                    DF0D    610 Ftest_adc$MDMCFG3$0$0 == 0xdf0d
                    DF0D    611 _MDMCFG3	=	0xdf0d
                    DF0E    612 Ftest_adc$MDMCFG2$0$0 == 0xdf0e
                    DF0E    613 _MDMCFG2	=	0xdf0e
                    DF0F    614 Ftest_adc$MDMCFG1$0$0 == 0xdf0f
                    DF0F    615 _MDMCFG1	=	0xdf0f
                    DF10    616 Ftest_adc$MDMCFG0$0$0 == 0xdf10
                    DF10    617 _MDMCFG0	=	0xdf10
                    DF11    618 Ftest_adc$DEVIATN$0$0 == 0xdf11
                    DF11    619 _DEVIATN	=	0xdf11
                    DF12    620 Ftest_adc$MCSM2$0$0 == 0xdf12
                    DF12    621 _MCSM2	=	0xdf12
                    DF13    622 Ftest_adc$MCSM1$0$0 == 0xdf13
                    DF13    623 _MCSM1	=	0xdf13
                    DF14    624 Ftest_adc$MCSM0$0$0 == 0xdf14
                    DF14    625 _MCSM0	=	0xdf14
                    DF15    626 Ftest_adc$FOCCFG$0$0 == 0xdf15
                    DF15    627 _FOCCFG	=	0xdf15
                    DF16    628 Ftest_adc$BSCFG$0$0 == 0xdf16
                    DF16    629 _BSCFG	=	0xdf16
                    DF17    630 Ftest_adc$AGCCTRL2$0$0 == 0xdf17
                    DF17    631 _AGCCTRL2	=	0xdf17
                    DF18    632 Ftest_adc$AGCCTRL1$0$0 == 0xdf18
                    DF18    633 _AGCCTRL1	=	0xdf18
                    DF19    634 Ftest_adc$AGCCTRL0$0$0 == 0xdf19
                    DF19    635 _AGCCTRL0	=	0xdf19
                    DF1A    636 Ftest_adc$FREND1$0$0 == 0xdf1a
                    DF1A    637 _FREND1	=	0xdf1a
                    DF1B    638 Ftest_adc$FREND0$0$0 == 0xdf1b
                    DF1B    639 _FREND0	=	0xdf1b
                    DF1C    640 Ftest_adc$FSCAL3$0$0 == 0xdf1c
                    DF1C    641 _FSCAL3	=	0xdf1c
                    DF1D    642 Ftest_adc$FSCAL2$0$0 == 0xdf1d
                    DF1D    643 _FSCAL2	=	0xdf1d
                    DF1E    644 Ftest_adc$FSCAL1$0$0 == 0xdf1e
                    DF1E    645 _FSCAL1	=	0xdf1e
                    DF1F    646 Ftest_adc$FSCAL0$0$0 == 0xdf1f
                    DF1F    647 _FSCAL0	=	0xdf1f
                    DF23    648 Ftest_adc$TEST2$0$0 == 0xdf23
                    DF23    649 _TEST2	=	0xdf23
                    DF24    650 Ftest_adc$TEST1$0$0 == 0xdf24
                    DF24    651 _TEST1	=	0xdf24
                    DF25    652 Ftest_adc$TEST0$0$0 == 0xdf25
                    DF25    653 _TEST0	=	0xdf25
                    DF2E    654 Ftest_adc$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    655 _PA_TABLE0	=	0xdf2e
                    DF2F    656 Ftest_adc$IOCFG2$0$0 == 0xdf2f
                    DF2F    657 _IOCFG2	=	0xdf2f
                    DF30    658 Ftest_adc$IOCFG1$0$0 == 0xdf30
                    DF30    659 _IOCFG1	=	0xdf30
                    DF31    660 Ftest_adc$IOCFG0$0$0 == 0xdf31
                    DF31    661 _IOCFG0	=	0xdf31
                    DF36    662 Ftest_adc$PARTNUM$0$0 == 0xdf36
                    DF36    663 _PARTNUM	=	0xdf36
                    DF37    664 Ftest_adc$VERSION$0$0 == 0xdf37
                    DF37    665 _VERSION	=	0xdf37
                    DF38    666 Ftest_adc$FREQEST$0$0 == 0xdf38
                    DF38    667 _FREQEST	=	0xdf38
                    DF39    668 Ftest_adc$LQI$0$0 == 0xdf39
                    DF39    669 _LQI	=	0xdf39
                    DF3A    670 Ftest_adc$RSSI$0$0 == 0xdf3a
                    DF3A    671 _RSSI	=	0xdf3a
                    DF3B    672 Ftest_adc$MARCSTATE$0$0 == 0xdf3b
                    DF3B    673 _MARCSTATE	=	0xdf3b
                    DF3C    674 Ftest_adc$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    675 _PKTSTATUS	=	0xdf3c
                    DF3D    676 Ftest_adc$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    677 _VCO_VC_DAC	=	0xdf3d
                    DF40    678 Ftest_adc$I2SCFG0$0$0 == 0xdf40
                    DF40    679 _I2SCFG0	=	0xdf40
                    DF41    680 Ftest_adc$I2SCFG1$0$0 == 0xdf41
                    DF41    681 _I2SCFG1	=	0xdf41
                    DF42    682 Ftest_adc$I2SDATL$0$0 == 0xdf42
                    DF42    683 _I2SDATL	=	0xdf42
                    DF43    684 Ftest_adc$I2SDATH$0$0 == 0xdf43
                    DF43    685 _I2SDATH	=	0xdf43
                    DF44    686 Ftest_adc$I2SWCNT$0$0 == 0xdf44
                    DF44    687 _I2SWCNT	=	0xdf44
                    DF45    688 Ftest_adc$I2SSTAT$0$0 == 0xdf45
                    DF45    689 _I2SSTAT	=	0xdf45
                    DF46    690 Ftest_adc$I2SCLKF0$0$0 == 0xdf46
                    DF46    691 _I2SCLKF0	=	0xdf46
                    DF47    692 Ftest_adc$I2SCLKF1$0$0 == 0xdf47
                    DF47    693 _I2SCLKF1	=	0xdf47
                    DF48    694 Ftest_adc$I2SCLKF2$0$0 == 0xdf48
                    DF48    695 _I2SCLKF2	=	0xdf48
                    DE00    696 Ftest_adc$USBADDR$0$0 == 0xde00
                    DE00    697 _USBADDR	=	0xde00
                    DE01    698 Ftest_adc$USBPOW$0$0 == 0xde01
                    DE01    699 _USBPOW	=	0xde01
                    DE02    700 Ftest_adc$USBIIF$0$0 == 0xde02
                    DE02    701 _USBIIF	=	0xde02
                    DE04    702 Ftest_adc$USBOIF$0$0 == 0xde04
                    DE04    703 _USBOIF	=	0xde04
                    DE06    704 Ftest_adc$USBCIF$0$0 == 0xde06
                    DE06    705 _USBCIF	=	0xde06
                    DE07    706 Ftest_adc$USBIIE$0$0 == 0xde07
                    DE07    707 _USBIIE	=	0xde07
                    DE09    708 Ftest_adc$USBOIE$0$0 == 0xde09
                    DE09    709 _USBOIE	=	0xde09
                    DE0B    710 Ftest_adc$USBCIE$0$0 == 0xde0b
                    DE0B    711 _USBCIE	=	0xde0b
                    DE0C    712 Ftest_adc$USBFRML$0$0 == 0xde0c
                    DE0C    713 _USBFRML	=	0xde0c
                    DE0D    714 Ftest_adc$USBFRMH$0$0 == 0xde0d
                    DE0D    715 _USBFRMH	=	0xde0d
                    DE0E    716 Ftest_adc$USBINDEX$0$0 == 0xde0e
                    DE0E    717 _USBINDEX	=	0xde0e
                    DE10    718 Ftest_adc$USBMAXI$0$0 == 0xde10
                    DE10    719 _USBMAXI	=	0xde10
                    DE11    720 Ftest_adc$USBCSIL$0$0 == 0xde11
                    DE11    721 _USBCSIL	=	0xde11
                    DE12    722 Ftest_adc$USBCSIH$0$0 == 0xde12
                    DE12    723 _USBCSIH	=	0xde12
                    DE13    724 Ftest_adc$USBMAXO$0$0 == 0xde13
                    DE13    725 _USBMAXO	=	0xde13
                    DE14    726 Ftest_adc$USBCSOL$0$0 == 0xde14
                    DE14    727 _USBCSOL	=	0xde14
                    DE15    728 Ftest_adc$USBCSOH$0$0 == 0xde15
                    DE15    729 _USBCSOH	=	0xde15
                    DE16    730 Ftest_adc$USBCNTL$0$0 == 0xde16
                    DE16    731 _USBCNTL	=	0xde16
                    DE17    732 Ftest_adc$USBCNTH$0$0 == 0xde17
                    DE17    733 _USBCNTH	=	0xde17
                    DE20    734 Ftest_adc$USBF0$0$0 == 0xde20
                    DE20    735 _USBF0	=	0xde20
                    DE22    736 Ftest_adc$USBF1$0$0 == 0xde22
                    DE22    737 _USBF1	=	0xde22
                    DE24    738 Ftest_adc$USBF2$0$0 == 0xde24
                    DE24    739 _USBF2	=	0xde24
                    DE26    740 Ftest_adc$USBF3$0$0 == 0xde26
                    DE26    741 _USBF3	=	0xde26
                    DE28    742 Ftest_adc$USBF4$0$0 == 0xde28
                    DE28    743 _USBF4	=	0xde28
                    DE2A    744 Ftest_adc$USBF5$0$0 == 0xde2a
                    DE2A    745 _USBF5	=	0xde2a
                    0000    746 G$report$0$0==.
   F06B                     747 _report::
   F06B                     748 	.ds 1024
                            749 ;--------------------------------------------------------
                            750 ; absolute external ram data
                            751 ;--------------------------------------------------------
                            752 	.area XABS    (ABS,XDATA)
                            753 ;--------------------------------------------------------
                            754 ; external initialized ram data
                            755 ;--------------------------------------------------------
                            756 	.area XISEG   (XDATA)
                            757 	.area HOME    (CODE)
                            758 	.area GSINIT0 (CODE)
                            759 	.area GSINIT1 (CODE)
                            760 	.area GSINIT2 (CODE)
                            761 	.area GSINIT3 (CODE)
                            762 	.area GSINIT4 (CODE)
                            763 	.area GSINIT5 (CODE)
                            764 	.area GSINIT  (CODE)
                            765 	.area GSFINAL (CODE)
                            766 	.area CSEG    (CODE)
                            767 ;--------------------------------------------------------
                            768 ; interrupt vector 
                            769 ;--------------------------------------------------------
                            770 	.area HOME    (CODE)
   0400                     771 __interrupt_vect:
   0400 02 04 6D            772 	ljmp	__sdcc_gsinit_startup
   0403 32                  773 	reti
   0404                     774 	.ds	7
   040B 32                  775 	reti
   040C                     776 	.ds	7
   0413 32                  777 	reti
   0414                     778 	.ds	7
   041B 32                  779 	reti
   041C                     780 	.ds	7
   0423 32                  781 	reti
   0424                     782 	.ds	7
   042B 32                  783 	reti
   042C                     784 	.ds	7
   0433 32                  785 	reti
   0434                     786 	.ds	7
   043B 32                  787 	reti
   043C                     788 	.ds	7
   0443 32                  789 	reti
   0444                     790 	.ds	7
   044B 32                  791 	reti
   044C                     792 	.ds	7
   0453 32                  793 	reti
   0454                     794 	.ds	7
   045B 32                  795 	reti
   045C                     796 	.ds	7
   0463 02 15 46            797 	ljmp	_ISR_T4
                            798 ;--------------------------------------------------------
                            799 ; global & static initialisations
                            800 ;--------------------------------------------------------
                            801 	.area HOME    (CODE)
                            802 	.area GSINIT  (CODE)
                            803 	.area GSFINAL (CODE)
                            804 	.area GSINIT  (CODE)
                            805 	.globl __sdcc_gsinit_startup
                            806 	.globl __sdcc_program_startup
                            807 	.globl __start__stack
                            808 	.globl __mcs51_genXINIT
                            809 	.globl __mcs51_genXRAMCLEAR
                            810 	.globl __mcs51_genRAMCLEAR
                    0000    811 	G$main$0$0 ==.
                    0000    812 	C$test_adc.c$45$1$1 ==.
                            813 ;	apps/test_adc/test_adc.c:45: uint16 DATA reportLength = 0;
   04C6 E4                  814 	clr	a
   04C7 F5 08               815 	mov	_reportLength,a
   04C9 F5 09               816 	mov	(_reportLength + 1),a
                    0005    817 	G$main$0$0 ==.
                    0005    818 	C$test_adc.c$49$1$1 ==.
                            819 ;	apps/test_adc/test_adc.c:49: uint16 DATA reportBytesSent = 0;
   04CB E4                  820 	clr	a
   04CC F5 0A               821 	mov	_reportBytesSent,a
   04CE F5 0B               822 	mov	(_reportBytesSent + 1),a
                            823 	.area GSFINAL (CODE)
   0503 02 04 66            824 	ljmp	__sdcc_program_startup
                            825 ;--------------------------------------------------------
                            826 ; Home
                            827 ;--------------------------------------------------------
                            828 	.area HOME    (CODE)
                            829 	.area HOME    (CODE)
   0466                     830 __sdcc_program_startup:
   0466 12 08 B3            831 	lcall	_main
                            832 ;	return from main will lock up
   0469 80 FE               833 	sjmp .
                            834 ;--------------------------------------------------------
                            835 ; code
                            836 ;--------------------------------------------------------
                            837 	.area CSEG    (CODE)
                            838 ;------------------------------------------------------------
                            839 ;Allocation info for local variables in function 'updateLeds'
                            840 ;------------------------------------------------------------
                    0000    841 	G$updateLeds$0$0 ==.
                    0000    842 	C$test_adc.c$53$0$0 ==.
                            843 ;	apps/test_adc/test_adc.c:53: void updateLeds()
                            844 ;	-----------------------------------------
                            845 ;	 function updateLeds
                            846 ;	-----------------------------------------
   0506                     847 _updateLeds:
                    0007    848 	ar7 = 0x07
                    0006    849 	ar6 = 0x06
                    0005    850 	ar5 = 0x05
                    0004    851 	ar4 = 0x04
                    0003    852 	ar3 = 0x03
                    0002    853 	ar2 = 0x02
                    0001    854 	ar1 = 0x01
                    0000    855 	ar0 = 0x00
                    0000    856 	C$test_adc.c$55$1$1 ==.
                            857 ;	apps/test_adc/test_adc.c:55: usbShowStatusWithGreenLed();
   0506 12 17 48            858 	lcall	_usbShowStatusWithGreenLed
                    0003    859 	C$test_adc.c$56$2$2 ==.
                            860 ;	apps/test_adc/test_adc.c:56: LED_YELLOW(0);
   0509 AF FF               861 	mov	r7,_P2DIR
   050B 53 07 FB            862 	anl	ar7,#0xFB
   050E 8F FF               863 	mov	_P2DIR,r7
                    000A    864 	C$test_adc.c$57$2$3 ==.
                            865 ;	apps/test_adc/test_adc.c:57: LED_RED(0);
   0510 AF FF               866 	mov	r7,_P2DIR
   0512 53 07 FD            867 	anl	ar7,#0xFD
   0515 8F FF               868 	mov	_P2DIR,r7
                    0011    869 	C$test_adc.c$58$2$3 ==.
                    0011    870 	XG$updateLeds$0$0 ==.
   0517 22                  871 	ret
                            872 ;------------------------------------------------------------
                            873 ;Allocation info for local variables in function 'putchar'
                            874 ;------------------------------------------------------------
                    0012    875 	G$putchar$0$0 ==.
                    0012    876 	C$test_adc.c$62$2$3 ==.
                            877 ;	apps/test_adc/test_adc.c:62: void putchar(char c)
                            878 ;	-----------------------------------------
                            879 ;	 function putchar
                            880 ;	-----------------------------------------
   0518                     881 _putchar:
   0518 AF 82               882 	mov	r7,dpl
                    0014    883 	C$test_adc.c$64$1$1 ==.
                            884 ;	apps/test_adc/test_adc.c:64: report[reportLength] = c;
   051A E5 08               885 	mov	a,_reportLength
   051C 24 6B               886 	add	a,#_report
   051E F5 82               887 	mov	dpl,a
   0520 E5 09               888 	mov	a,(_reportLength + 1)
   0522 34 F0               889 	addc	a,#(_report >> 8)
   0524 F5 83               890 	mov	dph,a
   0526 EF                  891 	mov	a,r7
   0527 F0                  892 	movx	@dptr,a
                    0022    893 	C$test_adc.c$65$1$1 ==.
                            894 ;	apps/test_adc/test_adc.c:65: reportLength++;
   0528 05 08               895 	inc	_reportLength
   052A E4                  896 	clr	a
   052B B5 08 02            897 	cjne	a,_reportLength,00103$
   052E 05 09               898 	inc	(_reportLength + 1)
   0530                     899 00103$:
                    002A    900 	C$test_adc.c$66$1$1 ==.
                    002A    901 	XG$putchar$0$0 ==.
   0530 22                  902 	ret
                            903 ;------------------------------------------------------------
                            904 ;Allocation info for local variables in function 'printBar'
                            905 ;------------------------------------------------------------
                    002B    906 	G$printBar$0$0 ==.
                    002B    907 	C$test_adc.c$69$1$1 ==.
                            908 ;	apps/test_adc/test_adc.c:69: void printBar(const char * name, uint16 adcResult)
                            909 ;	-----------------------------------------
                            910 ;	 function printBar
                            911 ;	-----------------------------------------
   0531                     912 _printBar:
   0531 AD 82               913 	mov	r5,dpl
   0533 AE 83               914 	mov	r6,dph
   0535 AF F0               915 	mov	r7,b
                    0031    916 	C$test_adc.c$72$1$1 ==.
                            917 ;	apps/test_adc/test_adc.c:72: printf("%-4s %4d mV |", name, adcConvertToMillivolts(adcResult));
   0537 78 00               918 	mov	r0,#_printBar_PARM_2
   0539 E2                  919 	movx	a,@r0
   053A F5 82               920 	mov	dpl,a
   053C 08                  921 	inc	r0
   053D E2                  922 	movx	a,@r0
   053E F5 83               923 	mov	dph,a
   0540 C0 07               924 	push	ar7
   0542 C0 06               925 	push	ar6
   0544 C0 05               926 	push	ar5
   0546 12 09 81            927 	lcall	_adcConvertToMillivolts
   0549 AB 82               928 	mov	r3,dpl
   054B AC 83               929 	mov	r4,dph
   054D D0 05               930 	pop	ar5
   054F D0 06               931 	pop	ar6
   0551 D0 07               932 	pop	ar7
   0553 C0 03               933 	push	ar3
   0555 C0 04               934 	push	ar4
   0557 C0 05               935 	push	ar5
   0559 C0 06               936 	push	ar6
   055B C0 07               937 	push	ar7
   055D 74 9F               938 	mov	a,#__str_0
   055F C0 E0               939 	push	acc
   0561 74 1F               940 	mov	a,#(__str_0 >> 8)
   0563 C0 E0               941 	push	acc
   0565 74 80               942 	mov	a,#0x80
   0567 C0 E0               943 	push	acc
   0569 12 18 05            944 	lcall	_printf
   056C E5 81               945 	mov	a,sp
   056E 24 F8               946 	add	a,#0xf8
   0570 F5 81               947 	mov	sp,a
                    006C    948 	C$test_adc.c$73$1$1 ==.
                            949 ;	apps/test_adc/test_adc.c:73: width = adcResult >> 5;
   0572 78 00               950 	mov	r0,#_printBar_PARM_2
   0574 E2                  951 	movx	a,@r0
   0575 FE                  952 	mov	r6,a
   0576 08                  953 	inc	r0
   0577 E2                  954 	movx	a,@r0
   0578 C4                  955 	swap	a
   0579 03                  956 	rr	a
   057A CE                  957 	xch	a,r6
   057B C4                  958 	swap	a
   057C 03                  959 	rr	a
   057D 54 07               960 	anl	a,#0x07
   057F 6E                  961 	xrl	a,r6
   0580 CE                  962 	xch	a,r6
   0581 54 07               963 	anl	a,#0x07
   0583 CE                  964 	xch	a,r6
   0584 6E                  965 	xrl	a,r6
   0585 CE                  966 	xch	a,r6
                    0080    967 	C$test_adc.c$74$1$1 ==.
                            968 ;	apps/test_adc/test_adc.c:74: for(i = 0; i < width; i++){ putchar('#'); }
   0586 7F 00               969 	mov	r7,#0x00
   0588                     970 00101$:
   0588 C3                  971 	clr	c
   0589 EF                  972 	mov	a,r7
   058A 9E                  973 	subb	a,r6
   058B 50 11               974 	jnc	00114$
   058D 75 82 23            975 	mov	dpl,#0x23
   0590 C0 07               976 	push	ar7
   0592 C0 06               977 	push	ar6
   0594 12 05 18            978 	lcall	_putchar
   0597 D0 06               979 	pop	ar6
   0599 D0 07               980 	pop	ar7
   059B 0F                  981 	inc	r7
   059C 80 EA               982 	sjmp	00101$
   059E                     983 00114$:
   059E                     984 00105$:
                    0098    985 	C$test_adc.c$75$1$1 ==.
                            986 ;	apps/test_adc/test_adc.c:75: for(; i < 63; i++){ putchar(' '); }
   059E BF 3F 00            987 	cjne	r7,#0x3F,00118$
   05A1                     988 00118$:
   05A1 50 0D               989 	jnc	00108$
   05A3 75 82 20            990 	mov	dpl,#0x20
   05A6 C0 07               991 	push	ar7
   05A8 12 05 18            992 	lcall	_putchar
   05AB D0 07               993 	pop	ar7
   05AD 0F                  994 	inc	r7
   05AE 80 EE               995 	sjmp	00105$
   05B0                     996 00108$:
                    00AA    997 	C$test_adc.c$76$1$1 ==.
                            998 ;	apps/test_adc/test_adc.c:76: putchar('|');
   05B0 75 82 7C            999 	mov	dpl,#0x7C
   05B3 12 05 18           1000 	lcall	_putchar
                    00B0   1001 	C$test_adc.c$77$1$1 ==.
                           1002 ;	apps/test_adc/test_adc.c:77: putchar('\r');
   05B6 75 82 0D           1003 	mov	dpl,#0x0D
   05B9 12 05 18           1004 	lcall	_putchar
                    00B6   1005 	C$test_adc.c$78$1$1 ==.
                           1006 ;	apps/test_adc/test_adc.c:78: putchar('\n');
   05BC 75 82 0A           1007 	mov	dpl,#0x0A
   05BF 12 05 18           1008 	lcall	_putchar
                    00BC   1009 	C$test_adc.c$79$1$1 ==.
                    00BC   1010 	XG$printBar$0$0 ==.
   05C2 22                 1011 	ret
                           1012 ;------------------------------------------------------------
                           1013 ;Allocation info for local variables in function 'sendReportIfNeeded'
                           1014 ;------------------------------------------------------------
                           1015 ;sloc0                     Allocated with name '_sendReportIfNeeded_sloc0_1_0'
                           1016 ;sloc1                     Allocated with name '_sendReportIfNeeded_sloc1_1_0'
                           1017 ;sloc2                     Allocated with name '_sendReportIfNeeded_sloc2_1_0'
                           1018 ;------------------------------------------------------------
                    00BD   1019 	G$sendReportIfNeeded$0$0 ==.
                    00BD   1020 	C$test_adc.c$81$1$1 ==.
                           1021 ;	apps/test_adc/test_adc.c:81: void sendReportIfNeeded()
                           1022 ;	-----------------------------------------
                           1023 ;	 function sendReportIfNeeded
                           1024 ;	-----------------------------------------
   05C3                    1025 _sendReportIfNeeded:
                    00BD   1026 	C$test_adc.c$89$1$1 ==.
                           1027 ;	apps/test_adc/test_adc.c:89: if (getMs() - lastReport >= param_report_period_ms && reportLength == 0)
   05C3 12 15 6B           1028 	lcall	_getMs
   05C6 AC 82              1029 	mov	r4,dpl
   05C8 AD 83              1030 	mov	r5,dph
   05CA AE F0              1031 	mov	r6,b
   05CC FF                 1032 	mov	r7,a
   05CD 78 02              1033 	mov	r0,#_sendReportIfNeeded_lastReport_1_1
   05CF D3                 1034 	setb	c
   05D0 E2                 1035 	movx	a,@r0
   05D1 9C                 1036 	subb	a,r4
   05D2 F4                 1037 	cpl	a
   05D3 B3                 1038 	cpl	c
   05D4 F5 0C              1039 	mov	_sendReportIfNeeded_sloc0_1_0,a
   05D6 B3                 1040 	cpl	c
   05D7 08                 1041 	inc	r0
   05D8 E2                 1042 	movx	a,@r0
   05D9 9D                 1043 	subb	a,r5
   05DA F4                 1044 	cpl	a
   05DB B3                 1045 	cpl	c
   05DC F5 0D              1046 	mov	(_sendReportIfNeeded_sloc0_1_0 + 1),a
   05DE B3                 1047 	cpl	c
   05DF 08                 1048 	inc	r0
   05E0 E2                 1049 	movx	a,@r0
   05E1 9E                 1050 	subb	a,r6
   05E2 F4                 1051 	cpl	a
   05E3 B3                 1052 	cpl	c
   05E4 F5 0E              1053 	mov	(_sendReportIfNeeded_sloc0_1_0 + 2),a
   05E6 B3                 1054 	cpl	c
   05E7 08                 1055 	inc	r0
   05E8 E2                 1056 	movx	a,@r0
   05E9 9F                 1057 	subb	a,r7
   05EA F4                 1058 	cpl	a
   05EB F5 0F              1059 	mov	(_sendReportIfNeeded_sloc0_1_0 + 3),a
   05ED 90 1F 9B           1060 	mov	dptr,#_param_report_period_ms
   05F0 E4                 1061 	clr	a
   05F1 93                 1062 	movc	a,@a+dptr
   05F2 FA                 1063 	mov	r2,a
   05F3 74 01              1064 	mov	a,#0x01
   05F5 93                 1065 	movc	a,@a+dptr
   05F6 FB                 1066 	mov	r3,a
   05F7 74 02              1067 	mov	a,#0x02
   05F9 93                 1068 	movc	a,@a+dptr
   05FA FE                 1069 	mov	r6,a
   05FB 74 03              1070 	mov	a,#0x03
   05FD 93                 1071 	movc	a,@a+dptr
   05FE FF                 1072 	mov	r7,a
   05FF C3                 1073 	clr	c
   0600 E5 0C              1074 	mov	a,_sendReportIfNeeded_sloc0_1_0
   0602 9A                 1075 	subb	a,r2
   0603 E5 0D              1076 	mov	a,(_sendReportIfNeeded_sloc0_1_0 + 1)
   0605 9B                 1077 	subb	a,r3
   0606 E5 0E              1078 	mov	a,(_sendReportIfNeeded_sloc0_1_0 + 2)
   0608 9E                 1079 	subb	a,r6
   0609 E5 0F              1080 	mov	a,(_sendReportIfNeeded_sloc0_1_0 + 3)
   060B 9F                 1081 	subb	a,r7
   060C 50 03              1082 	jnc	00126$
   060E 02 08 08           1083 	ljmp	00105$
   0611                    1084 00126$:
   0611 E5 08              1085 	mov	a,_reportLength
   0613 45 09              1086 	orl	a,(_reportLength + 1)
   0615 60 03              1087 	jz	00127$
   0617 02 08 08           1088 	ljmp	00105$
   061A                    1089 00127$:
                    0114   1090 	C$test_adc.c$91$2$2 ==.
                           1091 ;	apps/test_adc/test_adc.c:91: lastReport = getMs();
   061A 12 15 6B           1092 	lcall	_getMs
   061D AC 82              1093 	mov	r4,dpl
   061F AD 83              1094 	mov	r5,dph
   0621 AE F0              1095 	mov	r6,b
   0623 FF                 1096 	mov	r7,a
   0624 78 02              1097 	mov	r0,#_sendReportIfNeeded_lastReport_1_1
   0626 EC                 1098 	mov	a,r4
   0627 F2                 1099 	movx	@r0,a
   0628 08                 1100 	inc	r0
   0629 ED                 1101 	mov	a,r5
   062A F2                 1102 	movx	@r0,a
   062B 08                 1103 	inc	r0
   062C EE                 1104 	mov	a,r6
   062D F2                 1105 	movx	@r0,a
   062E 08                 1106 	inc	r0
   062F EF                 1107 	mov	a,r7
   0630 F2                 1108 	movx	@r0,a
                    012B   1109 	C$test_adc.c$92$2$2 ==.
                           1110 ;	apps/test_adc/test_adc.c:92: reportBytesSent = 0;
   0631 E4                 1111 	clr	a
   0632 F5 0A              1112 	mov	_reportBytesSent,a
   0634 F5 0B              1113 	mov	(_reportBytesSent + 1),a
                    0130   1114 	C$test_adc.c$94$2$2 ==.
                           1115 ;	apps/test_adc/test_adc.c:94: vddMillivolts = adcReadVddMillivolts();
   0636 12 09 28           1116 	lcall	_adcReadVddMillivolts
   0639 78 12              1117 	mov	r0,#_sendReportIfNeeded_vddMillivolts_1_1
   063B E5 82              1118 	mov	a,dpl
   063D F2                 1119 	movx	@r0,a
   063E 08                 1120 	inc	r0
   063F E5 83              1121 	mov	a,dph
   0641 F2                 1122 	movx	@r0,a
                    013C   1123 	C$test_adc.c$95$2$2 ==.
                           1124 ;	apps/test_adc/test_adc.c:95: adcSetMillivoltCalibration(vddMillivolts);
   0642 78 12              1125 	mov	r0,#_sendReportIfNeeded_vddMillivolts_1_1
   0644 E2                 1126 	movx	a,@r0
   0645 F5 82              1127 	mov	dpl,a
   0647 08                 1128 	inc	r0
   0648 E2                 1129 	movx	a,@r0
   0649 F5 83              1130 	mov	dph,a
   064B 12 09 75           1131 	lcall	_adcSetMillivoltCalibration
                    0148   1132 	C$test_adc.c$97$3$3 ==.
                           1133 ;	apps/test_adc/test_adc.c:97: for(i = 0; i < 6; i++)
   064E 7D 00              1134 	mov	r5,#0x00
   0650                    1135 00112$:
   0650 BD 06 00           1136 	cjne	r5,#0x06,00128$
   0653                    1137 00128$:
   0653 50 20              1138 	jnc	00115$
                    014F   1139 	C$test_adc.c$99$3$3 ==.
                           1140 ;	apps/test_adc/test_adc.c:99: result[i] = adcRead(i);
   0655 ED                 1141 	mov	a,r5
   0656 2D                 1142 	add	a,r5
   0657 24 06              1143 	add	a,#_sendReportIfNeeded_result_1_1
   0659 F9                 1144 	mov	r1,a
   065A 8D 82              1145 	mov	dpl,r5
   065C C0 05              1146 	push	ar5
   065E C0 01              1147 	push	ar1
   0660 12 08 CB           1148 	lcall	_adcRead
   0663 E5 82              1149 	mov	a,dpl
   0665 85 83 F0           1150 	mov	b,dph
   0668 D0 01              1151 	pop	ar1
   066A D0 05              1152 	pop	ar5
   066C F3                 1153 	movx	@r1,a
   066D 09                 1154 	inc	r1
   066E E5 F0              1155 	mov	a,b
   0670 F3                 1156 	movx	@r1,a
   0671 19                 1157 	dec	r1
                    016C   1158 	C$test_adc.c$97$2$2 ==.
                           1159 ;	apps/test_adc/test_adc.c:97: for(i = 0; i < 6; i++)
   0672 0D                 1160 	inc	r5
   0673 80 DB              1161 	sjmp	00112$
   0675                    1162 00115$:
                    016F   1163 	C$test_adc.c$102$2$2 ==.
                           1164 ;	apps/test_adc/test_adc.c:102: if (param_bar_graph)
   0675 90 1F 97           1165 	mov	dptr,#_param_bar_graph
   0678 E4                 1166 	clr	a
   0679 93                 1167 	movc	a,@a+dptr
   067A FA                 1168 	mov	r2,a
   067B 74 01              1169 	mov	a,#0x01
   067D 93                 1170 	movc	a,@a+dptr
   067E FB                 1171 	mov	r3,a
   067F 74 02              1172 	mov	a,#0x02
   0681 93                 1173 	movc	a,@a+dptr
   0682 FC                 1174 	mov	r4,a
   0683 74 03              1175 	mov	a,#0x03
   0685 93                 1176 	movc	a,@a+dptr
   0686 FD                 1177 	mov	r5,a
   0687 EA                 1178 	mov	a,r2
   0688 4B                 1179 	orl	a,r3
   0689 4C                 1180 	orl	a,r4
   068A 4D                 1181 	orl	a,r5
   068B 70 03              1182 	jnz	00130$
   068D 02 07 50           1183 	ljmp	00102$
   0690                    1184 00130$:
                    018A   1185 	C$test_adc.c$104$3$4 ==.
                           1186 ;	apps/test_adc/test_adc.c:104: printf("\x1B[0;0H");  // VT100 command for "go to 0,0"
   0690 74 AD              1187 	mov	a,#__str_1
   0692 C0 E0              1188 	push	acc
   0694 74 1F              1189 	mov	a,#(__str_1 >> 8)
   0696 C0 E0              1190 	push	acc
   0698 74 80              1191 	mov	a,#0x80
   069A C0 E0              1192 	push	acc
   069C 12 18 05           1193 	lcall	_printf
   069F 15 81              1194 	dec	sp
   06A1 15 81              1195 	dec	sp
   06A3 15 81              1196 	dec	sp
                    019F   1197 	C$test_adc.c$105$3$4 ==.
                           1198 ;	apps/test_adc/test_adc.c:105: printBar("P0_0", result[0]);
   06A5 78 06              1199 	mov	r0,#_sendReportIfNeeded_result_1_1
   06A7 E2                 1200 	movx	a,@r0
   06A8 FC                 1201 	mov	r4,a
   06A9 08                 1202 	inc	r0
   06AA E2                 1203 	movx	a,@r0
   06AB FD                 1204 	mov	r5,a
   06AC 78 00              1205 	mov	r0,#_printBar_PARM_2
   06AE EC                 1206 	mov	a,r4
   06AF F2                 1207 	movx	@r0,a
   06B0 08                 1208 	inc	r0
   06B1 ED                 1209 	mov	a,r5
   06B2 F2                 1210 	movx	@r0,a
   06B3 90 1F B4           1211 	mov	dptr,#__str_2
   06B6 75 F0 80           1212 	mov	b,#0x80
   06B9 12 05 31           1213 	lcall	_printBar
                    01B6   1214 	C$test_adc.c$106$3$4 ==.
                           1215 ;	apps/test_adc/test_adc.c:106: printBar("P0_1", result[1]);
   06BC 78 08              1216 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0002)
   06BE E2                 1217 	movx	a,@r0
   06BF FC                 1218 	mov	r4,a
   06C0 08                 1219 	inc	r0
   06C1 E2                 1220 	movx	a,@r0
   06C2 FD                 1221 	mov	r5,a
   06C3 78 00              1222 	mov	r0,#_printBar_PARM_2
   06C5 EC                 1223 	mov	a,r4
   06C6 F2                 1224 	movx	@r0,a
   06C7 08                 1225 	inc	r0
   06C8 ED                 1226 	mov	a,r5
   06C9 F2                 1227 	movx	@r0,a
   06CA 90 1F B9           1228 	mov	dptr,#__str_3
   06CD 75 F0 80           1229 	mov	b,#0x80
   06D0 12 05 31           1230 	lcall	_printBar
                    01CD   1231 	C$test_adc.c$107$3$4 ==.
                           1232 ;	apps/test_adc/test_adc.c:107: printBar("P0_2", result[2]);
   06D3 78 0A              1233 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0004)
   06D5 E2                 1234 	movx	a,@r0
   06D6 FC                 1235 	mov	r4,a
   06D7 08                 1236 	inc	r0
   06D8 E2                 1237 	movx	a,@r0
   06D9 FD                 1238 	mov	r5,a
   06DA 78 00              1239 	mov	r0,#_printBar_PARM_2
   06DC EC                 1240 	mov	a,r4
   06DD F2                 1241 	movx	@r0,a
   06DE 08                 1242 	inc	r0
   06DF ED                 1243 	mov	a,r5
   06E0 F2                 1244 	movx	@r0,a
   06E1 90 1F BE           1245 	mov	dptr,#__str_4
   06E4 75 F0 80           1246 	mov	b,#0x80
   06E7 12 05 31           1247 	lcall	_printBar
                    01E4   1248 	C$test_adc.c$108$3$4 ==.
                           1249 ;	apps/test_adc/test_adc.c:108: printBar("P0_3", result[3]);
   06EA 78 0C              1250 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0006)
   06EC E2                 1251 	movx	a,@r0
   06ED FC                 1252 	mov	r4,a
   06EE 08                 1253 	inc	r0
   06EF E2                 1254 	movx	a,@r0
   06F0 FD                 1255 	mov	r5,a
   06F1 78 00              1256 	mov	r0,#_printBar_PARM_2
   06F3 EC                 1257 	mov	a,r4
   06F4 F2                 1258 	movx	@r0,a
   06F5 08                 1259 	inc	r0
   06F6 ED                 1260 	mov	a,r5
   06F7 F2                 1261 	movx	@r0,a
   06F8 90 1F C3           1262 	mov	dptr,#__str_5
   06FB 75 F0 80           1263 	mov	b,#0x80
   06FE 12 05 31           1264 	lcall	_printBar
                    01FB   1265 	C$test_adc.c$109$3$4 ==.
                           1266 ;	apps/test_adc/test_adc.c:109: printBar("P0_4", result[4]);
   0701 78 0E              1267 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0008)
   0703 E2                 1268 	movx	a,@r0
   0704 FC                 1269 	mov	r4,a
   0705 08                 1270 	inc	r0
   0706 E2                 1271 	movx	a,@r0
   0707 FD                 1272 	mov	r5,a
   0708 78 00              1273 	mov	r0,#_printBar_PARM_2
   070A EC                 1274 	mov	a,r4
   070B F2                 1275 	movx	@r0,a
   070C 08                 1276 	inc	r0
   070D ED                 1277 	mov	a,r5
   070E F2                 1278 	movx	@r0,a
   070F 90 1F C8           1279 	mov	dptr,#__str_6
   0712 75 F0 80           1280 	mov	b,#0x80
   0715 12 05 31           1281 	lcall	_printBar
                    0212   1282 	C$test_adc.c$110$3$4 ==.
                           1283 ;	apps/test_adc/test_adc.c:110: printBar("P0_5", result[5]);
   0718 78 10              1284 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x000a)
   071A E2                 1285 	movx	a,@r0
   071B FC                 1286 	mov	r4,a
   071C 08                 1287 	inc	r0
   071D E2                 1288 	movx	a,@r0
   071E FD                 1289 	mov	r5,a
   071F 78 00              1290 	mov	r0,#_printBar_PARM_2
   0721 EC                 1291 	mov	a,r4
   0722 F2                 1292 	movx	@r0,a
   0723 08                 1293 	inc	r0
   0724 ED                 1294 	mov	a,r5
   0725 F2                 1295 	movx	@r0,a
   0726 90 1F CD           1296 	mov	dptr,#__str_7
   0729 75 F0 80           1297 	mov	b,#0x80
   072C 12 05 31           1298 	lcall	_printBar
                    0229   1299 	C$test_adc.c$111$3$4 ==.
                           1300 ;	apps/test_adc/test_adc.c:111: printf("VDD  %4d mV", vddMillivolts);
   072F 78 12              1301 	mov	r0,#_sendReportIfNeeded_vddMillivolts_1_1
   0731 E2                 1302 	movx	a,@r0
   0732 C0 E0              1303 	push	acc
   0734 08                 1304 	inc	r0
   0735 E2                 1305 	movx	a,@r0
   0736 C0 E0              1306 	push	acc
   0738 74 D2              1307 	mov	a,#__str_8
   073A C0 E0              1308 	push	acc
   073C 74 1F              1309 	mov	a,#(__str_8 >> 8)
   073E C0 E0              1310 	push	acc
   0740 74 80              1311 	mov	a,#0x80
   0742 C0 E0              1312 	push	acc
   0744 12 18 05           1313 	lcall	_printf
   0747 E5 81              1314 	mov	a,sp
   0749 24 FB              1315 	add	a,#0xfb
   074B F5 81              1316 	mov	sp,a
   074D 02 08 08           1317 	ljmp	00105$
   0750                    1318 00102$:
                    024A   1319 	C$test_adc.c$121$3$5 ==.
                           1320 ;	apps/test_adc/test_adc.c:121: adcConvertToMillivolts(result[5]),
   0750 78 10              1321 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x000a)
   0752 E2                 1322 	movx	a,@r0
   0753 FC                 1323 	mov	r4,a
   0754 08                 1324 	inc	r0
   0755 E2                 1325 	movx	a,@r0
   0756 FD                 1326 	mov	r5,a
   0757 8C 82              1327 	mov	dpl,r4
   0759 8D 83              1328 	mov	dph,r5
   075B 12 09 81           1329 	lcall	_adcConvertToMillivolts
   075E AC 82              1330 	mov	r4,dpl
   0760 AD 83              1331 	mov	r5,dph
                    025C   1332 	C$test_adc.c$120$3$5 ==.
                           1333 ;	apps/test_adc/test_adc.c:120: adcConvertToMillivolts(result[4]),
   0762 78 0E              1334 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0008)
   0764 E2                 1335 	movx	a,@r0
   0765 FA                 1336 	mov	r2,a
   0766 08                 1337 	inc	r0
   0767 E2                 1338 	movx	a,@r0
   0768 FB                 1339 	mov	r3,a
   0769 8A 82              1340 	mov	dpl,r2
   076B 8B 83              1341 	mov	dph,r3
   076D C0 05              1342 	push	ar5
   076F C0 04              1343 	push	ar4
   0771 12 09 81           1344 	lcall	_adcConvertToMillivolts
   0774 AA 82              1345 	mov	r2,dpl
   0776 AB 83              1346 	mov	r3,dph
                    0272   1347 	C$test_adc.c$119$3$5 ==.
                           1348 ;	apps/test_adc/test_adc.c:119: adcConvertToMillivolts(result[3]),
   0778 78 0C              1349 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0006)
   077A E2                 1350 	movx	a,@r0
   077B FE                 1351 	mov	r6,a
   077C 08                 1352 	inc	r0
   077D E2                 1353 	movx	a,@r0
   077E FF                 1354 	mov	r7,a
   077F 8E 82              1355 	mov	dpl,r6
   0781 8F 83              1356 	mov	dph,r7
   0783 C0 03              1357 	push	ar3
   0785 C0 02              1358 	push	ar2
   0787 12 09 81           1359 	lcall	_adcConvertToMillivolts
   078A 85 82 0C           1360 	mov	_sendReportIfNeeded_sloc0_1_0,dpl
   078D 85 83 0D           1361 	mov	(_sendReportIfNeeded_sloc0_1_0 + 1),dph
                    028A   1362 	C$test_adc.c$118$3$5 ==.
                           1363 ;	apps/test_adc/test_adc.c:118: adcConvertToMillivolts(result[2]),
   0790 78 0A              1364 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0004)
   0792 E2                 1365 	movx	a,@r0
   0793 FE                 1366 	mov	r6,a
   0794 08                 1367 	inc	r0
   0795 E2                 1368 	movx	a,@r0
   0796 FF                 1369 	mov	r7,a
   0797 8E 82              1370 	mov	dpl,r6
   0799 8F 83              1371 	mov	dph,r7
   079B 12 09 81           1372 	lcall	_adcConvertToMillivolts
   079E 85 82 10           1373 	mov	_sendReportIfNeeded_sloc1_1_0,dpl
   07A1 85 83 11           1374 	mov	(_sendReportIfNeeded_sloc1_1_0 + 1),dph
                    029E   1375 	C$test_adc.c$117$3$5 ==.
                           1376 ;	apps/test_adc/test_adc.c:117: adcConvertToMillivolts(result[1]),
   07A4 78 08              1377 	mov	r0,#(_sendReportIfNeeded_result_1_1 + 0x0002)
   07A6 E2                 1378 	movx	a,@r0
   07A7 FE                 1379 	mov	r6,a
   07A8 08                 1380 	inc	r0
   07A9 E2                 1381 	movx	a,@r0
   07AA FF                 1382 	mov	r7,a
   07AB 8E 82              1383 	mov	dpl,r6
   07AD 8F 83              1384 	mov	dph,r7
   07AF 12 09 81           1385 	lcall	_adcConvertToMillivolts
   07B2 85 82 12           1386 	mov	_sendReportIfNeeded_sloc2_1_0,dpl
   07B5 85 83 13           1387 	mov	(_sendReportIfNeeded_sloc2_1_0 + 1),dph
                    02B2   1388 	C$test_adc.c$116$3$5 ==.
                           1389 ;	apps/test_adc/test_adc.c:116: adcConvertToMillivolts(result[0]),
   07B8 78 06              1390 	mov	r0,#_sendReportIfNeeded_result_1_1
   07BA E2                 1391 	movx	a,@r0
   07BB FE                 1392 	mov	r6,a
   07BC 08                 1393 	inc	r0
   07BD E2                 1394 	movx	a,@r0
   07BE FF                 1395 	mov	r7,a
   07BF 8E 82              1396 	mov	dpl,r6
   07C1 8F 83              1397 	mov	dph,r7
   07C3 12 09 81           1398 	lcall	_adcConvertToMillivolts
   07C6 AE 82              1399 	mov	r6,dpl
   07C8 AF 83              1400 	mov	r7,dph
   07CA D0 02              1401 	pop	ar2
   07CC D0 03              1402 	pop	ar3
   07CE D0 04              1403 	pop	ar4
   07D0 D0 05              1404 	pop	ar5
                    02CC   1405 	C$test_adc.c$115$3$5 ==.
                           1406 ;	apps/test_adc/test_adc.c:115: printf("%4d, %4d, %4d, %4d, %4d, %4d, %4d\r\n",
   07D2 78 12              1407 	mov	r0,#_sendReportIfNeeded_vddMillivolts_1_1
   07D4 E2                 1408 	movx	a,@r0
   07D5 C0 E0              1409 	push	acc
   07D7 08                 1410 	inc	r0
   07D8 E2                 1411 	movx	a,@r0
   07D9 C0 E0              1412 	push	acc
   07DB C0 04              1413 	push	ar4
   07DD C0 05              1414 	push	ar5
   07DF C0 02              1415 	push	ar2
   07E1 C0 03              1416 	push	ar3
   07E3 C0 0C              1417 	push	_sendReportIfNeeded_sloc0_1_0
   07E5 C0 0D              1418 	push	(_sendReportIfNeeded_sloc0_1_0 + 1)
   07E7 C0 10              1419 	push	_sendReportIfNeeded_sloc1_1_0
   07E9 C0 11              1420 	push	(_sendReportIfNeeded_sloc1_1_0 + 1)
   07EB C0 12              1421 	push	_sendReportIfNeeded_sloc2_1_0
   07ED C0 13              1422 	push	(_sendReportIfNeeded_sloc2_1_0 + 1)
   07EF C0 06              1423 	push	ar6
   07F1 C0 07              1424 	push	ar7
   07F3 74 DE              1425 	mov	a,#__str_9
   07F5 C0 E0              1426 	push	acc
   07F7 74 1F              1427 	mov	a,#(__str_9 >> 8)
   07F9 C0 E0              1428 	push	acc
   07FB 74 80              1429 	mov	a,#0x80
   07FD C0 E0              1430 	push	acc
   07FF 12 18 05           1431 	lcall	_printf
   0802 E5 81              1432 	mov	a,sp
   0804 24 EF              1433 	add	a,#0xef
   0806 F5 81              1434 	mov	sp,a
   0808                    1435 00105$:
                    0302   1436 	C$test_adc.c$127$1$1 ==.
                           1437 ;	apps/test_adc/test_adc.c:127: if (reportLength > 0)
   0808 E5 08              1438 	mov	a,_reportLength
   080A 45 09              1439 	orl	a,(_reportLength + 1)
   080C 60 60              1440 	jz	00116$
                    0308   1441 	C$test_adc.c$129$2$6 ==.
                           1442 ;	apps/test_adc/test_adc.c:129: bytesToSend = usbComTxAvailable();
   080E 12 0B CD           1443 	lcall	_usbComTxAvailable
   0811 AF 82              1444 	mov	r7,dpl
                    030D   1445 	C$test_adc.c$130$2$6 ==.
                           1446 ;	apps/test_adc/test_adc.c:130: if (bytesToSend > reportLength - reportBytesSent)
   0813 E5 08              1447 	mov	a,_reportLength
   0815 C3                 1448 	clr	c
   0816 95 0A              1449 	subb	a,_reportBytesSent
   0818 FD                 1450 	mov	r5,a
   0819 E5 09              1451 	mov	a,(_reportLength + 1)
   081B 95 0B              1452 	subb	a,(_reportBytesSent + 1)
   081D FE                 1453 	mov	r6,a
   081E 8F 03              1454 	mov	ar3,r7
   0820 7C 00              1455 	mov	r4,#0x00
   0822 C3                 1456 	clr	c
   0823 ED                 1457 	mov	a,r5
   0824 9B                 1458 	subb	a,r3
   0825 EE                 1459 	mov	a,r6
   0826 9C                 1460 	subb	a,r4
   0827 50 20              1461 	jnc	00108$
                    0323   1462 	C$test_adc.c$133$3$7 ==.
                           1463 ;	apps/test_adc/test_adc.c:133: usbComTxSend(report+reportBytesSent, reportLength - reportBytesSent);
   0829 E5 0A              1464 	mov	a,_reportBytesSent
   082B 24 6B              1465 	add	a,#_report
   082D F5 82              1466 	mov	dpl,a
   082F E5 0B              1467 	mov	a,(_reportBytesSent + 1)
   0831 34 F0              1468 	addc	a,#(_report >> 8)
   0833 F5 83              1469 	mov	dph,a
   0835 AE 08              1470 	mov	r6,_reportLength
   0837 AD 0A              1471 	mov	r5,_reportBytesSent
   0839 EE                 1472 	mov	a,r6
   083A C3                 1473 	clr	c
   083B 9D                 1474 	subb	a,r5
   083C 78 1C              1475 	mov	r0,#_usbComTxSend_PARM_2
   083E F2                 1476 	movx	@r0,a
   083F 12 0C 04           1477 	lcall	_usbComTxSend
                    033C   1478 	C$test_adc.c$134$3$7 ==.
                           1479 ;	apps/test_adc/test_adc.c:134: reportLength = 0;
   0842 E4                 1480 	clr	a
   0843 F5 08              1481 	mov	_reportLength,a
   0845 F5 09              1482 	mov	(_reportLength + 1),a
   0847 80 25              1483 	sjmp	00116$
   0849                    1484 00108$:
                    0343   1485 	C$test_adc.c$138$3$8 ==.
                           1486 ;	apps/test_adc/test_adc.c:138: usbComTxSend(report+reportBytesSent, bytesToSend);
   0849 E5 0A              1487 	mov	a,_reportBytesSent
   084B 24 6B              1488 	add	a,#_report
   084D F5 82              1489 	mov	dpl,a
   084F E5 0B              1490 	mov	a,(_reportBytesSent + 1)
   0851 34 F0              1491 	addc	a,#(_report >> 8)
   0853 F5 83              1492 	mov	dph,a
   0855 78 1C              1493 	mov	r0,#_usbComTxSend_PARM_2
   0857 EF                 1494 	mov	a,r7
   0858 F2                 1495 	movx	@r0,a
   0859 C0 04              1496 	push	ar4
   085B C0 03              1497 	push	ar3
   085D 12 0C 04           1498 	lcall	_usbComTxSend
   0860 D0 03              1499 	pop	ar3
   0862 D0 04              1500 	pop	ar4
                    035E   1501 	C$test_adc.c$139$3$8 ==.
                           1502 ;	apps/test_adc/test_adc.c:139: reportBytesSent += bytesToSend;
   0864 EB                 1503 	mov	a,r3
   0865 25 0A              1504 	add	a,_reportBytesSent
   0867 F5 0A              1505 	mov	_reportBytesSent,a
   0869 EC                 1506 	mov	a,r4
   086A 35 0B              1507 	addc	a,(_reportBytesSent + 1)
   086C F5 0B              1508 	mov	(_reportBytesSent + 1),a
   086E                    1509 00116$:
                    0368   1510 	C$test_adc.c$143$2$1 ==.
                    0368   1511 	XG$sendReportIfNeeded$0$0 ==.
   086E 22                 1512 	ret
                           1513 ;------------------------------------------------------------
                           1514 ;Allocation info for local variables in function 'analogInputsInit'
                           1515 ;------------------------------------------------------------
                    0369   1516 	G$analogInputsInit$0$0 ==.
                    0369   1517 	C$test_adc.c$145$2$1 ==.
                           1518 ;	apps/test_adc/test_adc.c:145: void analogInputsInit()
                           1519 ;	-----------------------------------------
                           1520 ;	 function analogInputsInit
                           1521 ;	-----------------------------------------
   086F                    1522 _analogInputsInit:
                    0369   1523 	C$test_adc.c$147$1$1 ==.
                           1524 ;	apps/test_adc/test_adc.c:147: switch(param_input_mode)
   086F 90 1F 93           1525 	mov	dptr,#_param_input_mode
   0872 E4                 1526 	clr	a
   0873 93                 1527 	movc	a,@a+dptr
   0874 FC                 1528 	mov	r4,a
   0875 74 01              1529 	mov	a,#0x01
   0877 93                 1530 	movc	a,@a+dptr
   0878 FD                 1531 	mov	r5,a
   0879 74 02              1532 	mov	a,#0x02
   087B 93                 1533 	movc	a,@a+dptr
   087C FE                 1534 	mov	r6,a
   087D 74 03              1535 	mov	a,#0x03
   087F 93                 1536 	movc	a,@a+dptr
   0880 FF                 1537 	mov	r7,a
   0881 BC FF 0B           1538 	cjne	r4,#0xFF,00109$
   0884 BD FF 08           1539 	cjne	r5,#0xFF,00109$
   0887 BE FF 05           1540 	cjne	r6,#0xFF,00109$
   088A BF FF 02           1541 	cjne	r7,#0xFF,00109$
   088D 80 18              1542 	sjmp	00102$
   088F                    1543 00109$:
   088F BC 01 1D           1544 	cjne	r4,#0x01,00103$
   0892 BD 00 1A           1545 	cjne	r5,#0x00,00103$
   0895 BE 00 17           1546 	cjne	r6,#0x00,00103$
   0898 BF 00 14           1547 	cjne	r7,#0x00,00103$
                    0395   1548 	C$test_adc.c$151$2$2 ==.
                           1549 ;	apps/test_adc/test_adc.c:151: P2INP &= ~(1<<5);  // PDUP0 = 0: Pull-ups on Port 0.
   089B AF F7              1550 	mov	r7,_P2INP
   089D 53 07 DF           1551 	anl	ar7,#0xDF
   08A0 8F F7              1552 	mov	_P2INP,r7
                    039C   1553 	C$test_adc.c$152$2$2 ==.
                           1554 ;	apps/test_adc/test_adc.c:152: P0INP = 0;
   08A2 75 8F 00           1555 	mov	_P0INP,#0x00
                    039F   1556 	C$test_adc.c$153$2$2 ==.
                           1557 ;	apps/test_adc/test_adc.c:153: break;
                    039F   1558 	C$test_adc.c$155$2$2 ==.
                           1559 ;	apps/test_adc/test_adc.c:155: case -1: // Enable pull-down resistors for all pins on Port 0.
   08A5 80 0B              1560 	sjmp	00105$
   08A7                    1561 00102$:
                    03A1   1562 	C$test_adc.c$156$2$2 ==.
                           1563 ;	apps/test_adc/test_adc.c:156: P2INP |= (1<<5);   // PDUP0 = 1: Pull-downs on Port 0.
   08A7 43 F7 20           1564 	orl	_P2INP,#0x20
                    03A4   1565 	C$test_adc.c$157$2$2 ==.
                           1566 ;	apps/test_adc/test_adc.c:157: P0INP = 0;         // This line should not be necessary because P0SEL is 0 on reset.
   08AA 75 8F 00           1567 	mov	_P0INP,#0x00
                    03A7   1568 	C$test_adc.c$158$2$2 ==.
                           1569 ;	apps/test_adc/test_adc.c:158: break;
                    03A7   1570 	C$test_adc.c$160$2$2 ==.
                           1571 ;	apps/test_adc/test_adc.c:160: default: // Disable pull-ups and pull-downs for all pins on Port 0.
   08AD 80 03              1572 	sjmp	00105$
   08AF                    1573 00103$:
                    03A9   1574 	C$test_adc.c$161$2$2 ==.
                           1575 ;	apps/test_adc/test_adc.c:161: P0INP = 0x3F;
   08AF 75 8F 3F           1576 	mov	_P0INP,#0x3F
                    03AC   1577 	C$test_adc.c$163$1$1 ==.
                           1578 ;	apps/test_adc/test_adc.c:163: }
   08B2                    1579 00105$:
                    03AC   1580 	C$test_adc.c$164$1$1 ==.
                    03AC   1581 	XG$analogInputsInit$0$0 ==.
   08B2 22                 1582 	ret
                           1583 ;------------------------------------------------------------
                           1584 ;Allocation info for local variables in function 'main'
                           1585 ;------------------------------------------------------------
                    03AD   1586 	G$main$0$0 ==.
                    03AD   1587 	C$test_adc.c$166$1$1 ==.
                           1588 ;	apps/test_adc/test_adc.c:166: void main()
                           1589 ;	-----------------------------------------
                           1590 ;	 function main
                           1591 ;	-----------------------------------------
   08B3                    1592 _main:
                    03AD   1593 	C$test_adc.c$168$1$1 ==.
                           1594 ;	apps/test_adc/test_adc.c:168: systemInit();
   08B3 12 12 F0           1595 	lcall	_systemInit
                    03B0   1596 	C$test_adc.c$169$1$1 ==.
                           1597 ;	apps/test_adc/test_adc.c:169: usbInit();
   08B6 12 0C 8A           1598 	lcall	_usbInit
                    03B3   1599 	C$test_adc.c$170$1$1 ==.
                           1600 ;	apps/test_adc/test_adc.c:170: analogInputsInit();
   08B9 12 08 6F           1601 	lcall	_analogInputsInit
                    03B6   1602 	C$test_adc.c$172$1$1 ==.
                           1603 ;	apps/test_adc/test_adc.c:172: while(1)
   08BC                    1604 00102$:
                    03B6   1605 	C$test_adc.c$174$2$2 ==.
                           1606 ;	apps/test_adc/test_adc.c:174: boardService();
   08BC 12 12 FD           1607 	lcall	_boardService
                    03B9   1608 	C$test_adc.c$175$2$2 ==.
                           1609 ;	apps/test_adc/test_adc.c:175: updateLeds();
   08BF 12 05 06           1610 	lcall	_updateLeds
                    03BC   1611 	C$test_adc.c$176$2$2 ==.
                           1612 ;	apps/test_adc/test_adc.c:176: usbComService();
   08C2 12 0B 28           1613 	lcall	_usbComService
                    03BF   1614 	C$test_adc.c$177$2$2 ==.
                           1615 ;	apps/test_adc/test_adc.c:177: sendReportIfNeeded();
   08C5 12 05 C3           1616 	lcall	_sendReportIfNeeded
   08C8 80 F2              1617 	sjmp	00102$
                    03C4   1618 	C$test_adc.c$179$1$1 ==.
                    03C4   1619 	XG$main$0$0 ==.
   08CA 22                 1620 	ret
                           1621 	.area CSEG    (CODE)
                           1622 	.area CONST   (CODE)
                    0000   1623 G$param_input_mode$0$0 == .
   1F93                    1624 _param_input_mode:
   1F93 00 00 00 00        1625 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   1626 G$param_bar_graph$0$0 == .
   1F97                    1627 _param_bar_graph:
   1F97 01 00 00 00        1628 	.byte #0x01,#0x00,#0x00,#0x00	;  1
                    0008   1629 G$param_report_period_ms$0$0 == .
   1F9B                    1630 _param_report_period_ms:
   1F9B 28 00 00 00        1631 	.byte #0x28,#0x00,#0x00,#0x00	;  40
                    000C   1632 Ftest_adc$_str_0$0$0 == .
   1F9F                    1633 __str_0:
   1F9F 25 2D 34 73 20 25  1634 	.ascii "%-4s %4d mV |"
        34 64 20 6D 56 20
        7C
   1FAC 00                 1635 	.db 0x00
                    001A   1636 Ftest_adc$_str_1$0$0 == .
   1FAD                    1637 __str_1:
   1FAD 1B                 1638 	.db 0x1B
   1FAE 5B 30 3B 30 48     1639 	.ascii "[0;0H"
   1FB3 00                 1640 	.db 0x00
                    0021   1641 Ftest_adc$_str_2$0$0 == .
   1FB4                    1642 __str_2:
   1FB4 50 30 5F 30        1643 	.ascii "P0_0"
   1FB8 00                 1644 	.db 0x00
                    0026   1645 Ftest_adc$_str_3$0$0 == .
   1FB9                    1646 __str_3:
   1FB9 50 30 5F 31        1647 	.ascii "P0_1"
   1FBD 00                 1648 	.db 0x00
                    002B   1649 Ftest_adc$_str_4$0$0 == .
   1FBE                    1650 __str_4:
   1FBE 50 30 5F 32        1651 	.ascii "P0_2"
   1FC2 00                 1652 	.db 0x00
                    0030   1653 Ftest_adc$_str_5$0$0 == .
   1FC3                    1654 __str_5:
   1FC3 50 30 5F 33        1655 	.ascii "P0_3"
   1FC7 00                 1656 	.db 0x00
                    0035   1657 Ftest_adc$_str_6$0$0 == .
   1FC8                    1658 __str_6:
   1FC8 50 30 5F 34        1659 	.ascii "P0_4"
   1FCC 00                 1660 	.db 0x00
                    003A   1661 Ftest_adc$_str_7$0$0 == .
   1FCD                    1662 __str_7:
   1FCD 50 30 5F 35        1663 	.ascii "P0_5"
   1FD1 00                 1664 	.db 0x00
                    003F   1665 Ftest_adc$_str_8$0$0 == .
   1FD2                    1666 __str_8:
   1FD2 56 44 44 20 20 25  1667 	.ascii "VDD  %4d mV"
        34 64 20 6D 56
   1FDD 00                 1668 	.db 0x00
                    004B   1669 Ftest_adc$_str_9$0$0 == .
   1FDE                    1670 __str_9:
   1FDE 25 34 64 2C 20 25  1671 	.ascii "%4d, %4d, %4d, %4d, %4d, %4d, %4d"
        34 64 2C 20 25 34
        64 2C 20 25 34 64
        2C 20 25 34 64 2C
        20 25 34 64 2C 20
        25 34 64
   1FFF 0D                 1672 	.db 0x0D
   2000 0A                 1673 	.db 0x0A
   2001 00                 1674 	.db 0x00
                           1675 	.area XINIT   (CODE)
                           1676 	.area CABS    (ABS,CODE)
