                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 23:15:52 2012
                              5 ;--------------------------------------------------------
                              6 	.module wireless_adc_tx
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_report_period_ms
                             13 	.globl _param_input_mode
                             14 	.globl _main
                             15 	.globl _adcToRadioService
                             16 	.globl _updateLeds
                             17 	.globl _analogInputsInit
                             18 	.globl _radioQueueTxSendPacket
                             19 	.globl _radioQueueTxCurrentPacket
                             20 	.globl _radioQueueInit
                             21 	.globl _usbComService
                             22 	.globl _usbShowStatusWithGreenLed
                             23 	.globl _usbInit
                             24 	.globl _adcConvertToMillivolts
                             25 	.globl _adcSetMillivoltCalibration
                             26 	.globl _adcReadVddMillivolts
                             27 	.globl _adcRead
                             28 	.globl _getMs
                             29 	.globl _boardService
                             30 	.globl _systemInit
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 	.area RSEG    (ABS,DATA)
   0000                      35 	.org 0x0000
                    0080     36 Fwireless_adc_tx$P0$0$0 == 0x0080
                    0080     37 _P0	=	0x0080
                    0081     38 Fwireless_adc_tx$SP$0$0 == 0x0081
                    0081     39 _SP	=	0x0081
                    0082     40 Fwireless_adc_tx$DPL0$0$0 == 0x0082
                    0082     41 _DPL0	=	0x0082
                    0083     42 Fwireless_adc_tx$DPH0$0$0 == 0x0083
                    0083     43 _DPH0	=	0x0083
                    0084     44 Fwireless_adc_tx$DPL1$0$0 == 0x0084
                    0084     45 _DPL1	=	0x0084
                    0085     46 Fwireless_adc_tx$DPH1$0$0 == 0x0085
                    0085     47 _DPH1	=	0x0085
                    0086     48 Fwireless_adc_tx$U0CSR$0$0 == 0x0086
                    0086     49 _U0CSR	=	0x0086
                    0087     50 Fwireless_adc_tx$PCON$0$0 == 0x0087
                    0087     51 _PCON	=	0x0087
                    0088     52 Fwireless_adc_tx$TCON$0$0 == 0x0088
                    0088     53 _TCON	=	0x0088
                    0089     54 Fwireless_adc_tx$P0IFG$0$0 == 0x0089
                    0089     55 _P0IFG	=	0x0089
                    008A     56 Fwireless_adc_tx$P1IFG$0$0 == 0x008a
                    008A     57 _P1IFG	=	0x008a
                    008B     58 Fwireless_adc_tx$P2IFG$0$0 == 0x008b
                    008B     59 _P2IFG	=	0x008b
                    008C     60 Fwireless_adc_tx$PICTL$0$0 == 0x008c
                    008C     61 _PICTL	=	0x008c
                    008D     62 Fwireless_adc_tx$P1IEN$0$0 == 0x008d
                    008D     63 _P1IEN	=	0x008d
                    008F     64 Fwireless_adc_tx$P0INP$0$0 == 0x008f
                    008F     65 _P0INP	=	0x008f
                    0090     66 Fwireless_adc_tx$P1$0$0 == 0x0090
                    0090     67 _P1	=	0x0090
                    0091     68 Fwireless_adc_tx$RFIM$0$0 == 0x0091
                    0091     69 _RFIM	=	0x0091
                    0092     70 Fwireless_adc_tx$DPS$0$0 == 0x0092
                    0092     71 _DPS	=	0x0092
                    0093     72 Fwireless_adc_tx$MPAGE$0$0 == 0x0093
                    0093     73 _MPAGE	=	0x0093
                    0095     74 Fwireless_adc_tx$ENDIAN$0$0 == 0x0095
                    0095     75 _ENDIAN	=	0x0095
                    0098     76 Fwireless_adc_tx$S0CON$0$0 == 0x0098
                    0098     77 _S0CON	=	0x0098
                    009A     78 Fwireless_adc_tx$IEN2$0$0 == 0x009a
                    009A     79 _IEN2	=	0x009a
                    009B     80 Fwireless_adc_tx$S1CON$0$0 == 0x009b
                    009B     81 _S1CON	=	0x009b
                    009C     82 Fwireless_adc_tx$T2CT$0$0 == 0x009c
                    009C     83 _T2CT	=	0x009c
                    009D     84 Fwireless_adc_tx$T2PR$0$0 == 0x009d
                    009D     85 _T2PR	=	0x009d
                    009E     86 Fwireless_adc_tx$T2CTL$0$0 == 0x009e
                    009E     87 _T2CTL	=	0x009e
                    00A0     88 Fwireless_adc_tx$P2$0$0 == 0x00a0
                    00A0     89 _P2	=	0x00a0
                    00A1     90 Fwireless_adc_tx$WORIRQ$0$0 == 0x00a1
                    00A1     91 _WORIRQ	=	0x00a1
                    00A2     92 Fwireless_adc_tx$WORCTRL$0$0 == 0x00a2
                    00A2     93 _WORCTRL	=	0x00a2
                    00A3     94 Fwireless_adc_tx$WOREVT0$0$0 == 0x00a3
                    00A3     95 _WOREVT0	=	0x00a3
                    00A4     96 Fwireless_adc_tx$WOREVT1$0$0 == 0x00a4
                    00A4     97 _WOREVT1	=	0x00a4
                    00A5     98 Fwireless_adc_tx$WORTIME0$0$0 == 0x00a5
                    00A5     99 _WORTIME0	=	0x00a5
                    00A6    100 Fwireless_adc_tx$WORTIME1$0$0 == 0x00a6
                    00A6    101 _WORTIME1	=	0x00a6
                    00A8    102 Fwireless_adc_tx$IEN0$0$0 == 0x00a8
                    00A8    103 _IEN0	=	0x00a8
                    00A9    104 Fwireless_adc_tx$IP0$0$0 == 0x00a9
                    00A9    105 _IP0	=	0x00a9
                    00AB    106 Fwireless_adc_tx$FWT$0$0 == 0x00ab
                    00AB    107 _FWT	=	0x00ab
                    00AC    108 Fwireless_adc_tx$FADDRL$0$0 == 0x00ac
                    00AC    109 _FADDRL	=	0x00ac
                    00AD    110 Fwireless_adc_tx$FADDRH$0$0 == 0x00ad
                    00AD    111 _FADDRH	=	0x00ad
                    00AE    112 Fwireless_adc_tx$FCTL$0$0 == 0x00ae
                    00AE    113 _FCTL	=	0x00ae
                    00AF    114 Fwireless_adc_tx$FWDATA$0$0 == 0x00af
                    00AF    115 _FWDATA	=	0x00af
                    00B1    116 Fwireless_adc_tx$ENCDI$0$0 == 0x00b1
                    00B1    117 _ENCDI	=	0x00b1
                    00B2    118 Fwireless_adc_tx$ENCDO$0$0 == 0x00b2
                    00B2    119 _ENCDO	=	0x00b2
                    00B3    120 Fwireless_adc_tx$ENCCS$0$0 == 0x00b3
                    00B3    121 _ENCCS	=	0x00b3
                    00B4    122 Fwireless_adc_tx$ADCCON1$0$0 == 0x00b4
                    00B4    123 _ADCCON1	=	0x00b4
                    00B5    124 Fwireless_adc_tx$ADCCON2$0$0 == 0x00b5
                    00B5    125 _ADCCON2	=	0x00b5
                    00B6    126 Fwireless_adc_tx$ADCCON3$0$0 == 0x00b6
                    00B6    127 _ADCCON3	=	0x00b6
                    00B8    128 Fwireless_adc_tx$IEN1$0$0 == 0x00b8
                    00B8    129 _IEN1	=	0x00b8
                    00B9    130 Fwireless_adc_tx$IP1$0$0 == 0x00b9
                    00B9    131 _IP1	=	0x00b9
                    00BA    132 Fwireless_adc_tx$ADCL$0$0 == 0x00ba
                    00BA    133 _ADCL	=	0x00ba
                    00BB    134 Fwireless_adc_tx$ADCH$0$0 == 0x00bb
                    00BB    135 _ADCH	=	0x00bb
                    00BC    136 Fwireless_adc_tx$RNDL$0$0 == 0x00bc
                    00BC    137 _RNDL	=	0x00bc
                    00BD    138 Fwireless_adc_tx$RNDH$0$0 == 0x00bd
                    00BD    139 _RNDH	=	0x00bd
                    00BE    140 Fwireless_adc_tx$SLEEP$0$0 == 0x00be
                    00BE    141 _SLEEP	=	0x00be
                    00C0    142 Fwireless_adc_tx$IRCON$0$0 == 0x00c0
                    00C0    143 _IRCON	=	0x00c0
                    00C1    144 Fwireless_adc_tx$U0DBUF$0$0 == 0x00c1
                    00C1    145 _U0DBUF	=	0x00c1
                    00C2    146 Fwireless_adc_tx$U0BAUD$0$0 == 0x00c2
                    00C2    147 _U0BAUD	=	0x00c2
                    00C4    148 Fwireless_adc_tx$U0UCR$0$0 == 0x00c4
                    00C4    149 _U0UCR	=	0x00c4
                    00C5    150 Fwireless_adc_tx$U0GCR$0$0 == 0x00c5
                    00C5    151 _U0GCR	=	0x00c5
                    00C6    152 Fwireless_adc_tx$CLKCON$0$0 == 0x00c6
                    00C6    153 _CLKCON	=	0x00c6
                    00C7    154 Fwireless_adc_tx$MEMCTR$0$0 == 0x00c7
                    00C7    155 _MEMCTR	=	0x00c7
                    00C9    156 Fwireless_adc_tx$WDCTL$0$0 == 0x00c9
                    00C9    157 _WDCTL	=	0x00c9
                    00CA    158 Fwireless_adc_tx$T3CNT$0$0 == 0x00ca
                    00CA    159 _T3CNT	=	0x00ca
                    00CB    160 Fwireless_adc_tx$T3CTL$0$0 == 0x00cb
                    00CB    161 _T3CTL	=	0x00cb
                    00CC    162 Fwireless_adc_tx$T3CCTL0$0$0 == 0x00cc
                    00CC    163 _T3CCTL0	=	0x00cc
                    00CD    164 Fwireless_adc_tx$T3CC0$0$0 == 0x00cd
                    00CD    165 _T3CC0	=	0x00cd
                    00CE    166 Fwireless_adc_tx$T3CCTL1$0$0 == 0x00ce
                    00CE    167 _T3CCTL1	=	0x00ce
                    00CF    168 Fwireless_adc_tx$T3CC1$0$0 == 0x00cf
                    00CF    169 _T3CC1	=	0x00cf
                    00D0    170 Fwireless_adc_tx$PSW$0$0 == 0x00d0
                    00D0    171 _PSW	=	0x00d0
                    00D1    172 Fwireless_adc_tx$DMAIRQ$0$0 == 0x00d1
                    00D1    173 _DMAIRQ	=	0x00d1
                    00D2    174 Fwireless_adc_tx$DMA1CFGL$0$0 == 0x00d2
                    00D2    175 _DMA1CFGL	=	0x00d2
                    00D3    176 Fwireless_adc_tx$DMA1CFGH$0$0 == 0x00d3
                    00D3    177 _DMA1CFGH	=	0x00d3
                    00D4    178 Fwireless_adc_tx$DMA0CFGL$0$0 == 0x00d4
                    00D4    179 _DMA0CFGL	=	0x00d4
                    00D5    180 Fwireless_adc_tx$DMA0CFGH$0$0 == 0x00d5
                    00D5    181 _DMA0CFGH	=	0x00d5
                    00D6    182 Fwireless_adc_tx$DMAARM$0$0 == 0x00d6
                    00D6    183 _DMAARM	=	0x00d6
                    00D7    184 Fwireless_adc_tx$DMAREQ$0$0 == 0x00d7
                    00D7    185 _DMAREQ	=	0x00d7
                    00D8    186 Fwireless_adc_tx$TIMIF$0$0 == 0x00d8
                    00D8    187 _TIMIF	=	0x00d8
                    00D9    188 Fwireless_adc_tx$RFD$0$0 == 0x00d9
                    00D9    189 _RFD	=	0x00d9
                    00DA    190 Fwireless_adc_tx$T1CC0L$0$0 == 0x00da
                    00DA    191 _T1CC0L	=	0x00da
                    00DB    192 Fwireless_adc_tx$T1CC0H$0$0 == 0x00db
                    00DB    193 _T1CC0H	=	0x00db
                    00DC    194 Fwireless_adc_tx$T1CC1L$0$0 == 0x00dc
                    00DC    195 _T1CC1L	=	0x00dc
                    00DD    196 Fwireless_adc_tx$T1CC1H$0$0 == 0x00dd
                    00DD    197 _T1CC1H	=	0x00dd
                    00DE    198 Fwireless_adc_tx$T1CC2L$0$0 == 0x00de
                    00DE    199 _T1CC2L	=	0x00de
                    00DF    200 Fwireless_adc_tx$T1CC2H$0$0 == 0x00df
                    00DF    201 _T1CC2H	=	0x00df
                    00E0    202 Fwireless_adc_tx$ACC$0$0 == 0x00e0
                    00E0    203 _ACC	=	0x00e0
                    00E1    204 Fwireless_adc_tx$RFST$0$0 == 0x00e1
                    00E1    205 _RFST	=	0x00e1
                    00E2    206 Fwireless_adc_tx$T1CNTL$0$0 == 0x00e2
                    00E2    207 _T1CNTL	=	0x00e2
                    00E3    208 Fwireless_adc_tx$T1CNTH$0$0 == 0x00e3
                    00E3    209 _T1CNTH	=	0x00e3
                    00E4    210 Fwireless_adc_tx$T1CTL$0$0 == 0x00e4
                    00E4    211 _T1CTL	=	0x00e4
                    00E5    212 Fwireless_adc_tx$T1CCTL0$0$0 == 0x00e5
                    00E5    213 _T1CCTL0	=	0x00e5
                    00E6    214 Fwireless_adc_tx$T1CCTL1$0$0 == 0x00e6
                    00E6    215 _T1CCTL1	=	0x00e6
                    00E7    216 Fwireless_adc_tx$T1CCTL2$0$0 == 0x00e7
                    00E7    217 _T1CCTL2	=	0x00e7
                    00E8    218 Fwireless_adc_tx$IRCON2$0$0 == 0x00e8
                    00E8    219 _IRCON2	=	0x00e8
                    00E9    220 Fwireless_adc_tx$RFIF$0$0 == 0x00e9
                    00E9    221 _RFIF	=	0x00e9
                    00EA    222 Fwireless_adc_tx$T4CNT$0$0 == 0x00ea
                    00EA    223 _T4CNT	=	0x00ea
                    00EB    224 Fwireless_adc_tx$T4CTL$0$0 == 0x00eb
                    00EB    225 _T4CTL	=	0x00eb
                    00EC    226 Fwireless_adc_tx$T4CCTL0$0$0 == 0x00ec
                    00EC    227 _T4CCTL0	=	0x00ec
                    00ED    228 Fwireless_adc_tx$T4CC0$0$0 == 0x00ed
                    00ED    229 _T4CC0	=	0x00ed
                    00EE    230 Fwireless_adc_tx$T4CCTL1$0$0 == 0x00ee
                    00EE    231 _T4CCTL1	=	0x00ee
                    00EF    232 Fwireless_adc_tx$T4CC1$0$0 == 0x00ef
                    00EF    233 _T4CC1	=	0x00ef
                    00F0    234 Fwireless_adc_tx$B$0$0 == 0x00f0
                    00F0    235 _B	=	0x00f0
                    00F1    236 Fwireless_adc_tx$PERCFG$0$0 == 0x00f1
                    00F1    237 _PERCFG	=	0x00f1
                    00F2    238 Fwireless_adc_tx$ADCCFG$0$0 == 0x00f2
                    00F2    239 _ADCCFG	=	0x00f2
                    00F3    240 Fwireless_adc_tx$P0SEL$0$0 == 0x00f3
                    00F3    241 _P0SEL	=	0x00f3
                    00F4    242 Fwireless_adc_tx$P1SEL$0$0 == 0x00f4
                    00F4    243 _P1SEL	=	0x00f4
                    00F5    244 Fwireless_adc_tx$P2SEL$0$0 == 0x00f5
                    00F5    245 _P2SEL	=	0x00f5
                    00F6    246 Fwireless_adc_tx$P1INP$0$0 == 0x00f6
                    00F6    247 _P1INP	=	0x00f6
                    00F7    248 Fwireless_adc_tx$P2INP$0$0 == 0x00f7
                    00F7    249 _P2INP	=	0x00f7
                    00F8    250 Fwireless_adc_tx$U1CSR$0$0 == 0x00f8
                    00F8    251 _U1CSR	=	0x00f8
                    00F9    252 Fwireless_adc_tx$U1DBUF$0$0 == 0x00f9
                    00F9    253 _U1DBUF	=	0x00f9
                    00FA    254 Fwireless_adc_tx$U1BAUD$0$0 == 0x00fa
                    00FA    255 _U1BAUD	=	0x00fa
                    00FB    256 Fwireless_adc_tx$U1UCR$0$0 == 0x00fb
                    00FB    257 _U1UCR	=	0x00fb
                    00FC    258 Fwireless_adc_tx$U1GCR$0$0 == 0x00fc
                    00FC    259 _U1GCR	=	0x00fc
                    00FD    260 Fwireless_adc_tx$P0DIR$0$0 == 0x00fd
                    00FD    261 _P0DIR	=	0x00fd
                    00FE    262 Fwireless_adc_tx$P1DIR$0$0 == 0x00fe
                    00FE    263 _P1DIR	=	0x00fe
                    00FF    264 Fwireless_adc_tx$P2DIR$0$0 == 0x00ff
                    00FF    265 _P2DIR	=	0x00ff
                    FFFFD5D4    266 Fwireless_adc_tx$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    267 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    268 Fwireless_adc_tx$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    269 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    270 Fwireless_adc_tx$FADDR$0$0 == 0xffffadac
                    FFFFADAC    271 _FADDR	=	0xffffadac
                    FFFFBBBA    272 Fwireless_adc_tx$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    273 _ADC	=	0xffffbbba
                    FFFFDBDA    274 Fwireless_adc_tx$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    275 _T1CC0	=	0xffffdbda
                    FFFFDDDC    276 Fwireless_adc_tx$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    277 _T1CC1	=	0xffffdddc
                    FFFFDFDE    278 Fwireless_adc_tx$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    279 _T1CC2	=	0xffffdfde
                            280 ;--------------------------------------------------------
                            281 ; special function bits
                            282 ;--------------------------------------------------------
                            283 	.area RSEG    (ABS,DATA)
   0000                     284 	.org 0x0000
                    0080    285 Fwireless_adc_tx$P0_0$0$0 == 0x0080
                    0080    286 _P0_0	=	0x0080
                    0081    287 Fwireless_adc_tx$P0_1$0$0 == 0x0081
                    0081    288 _P0_1	=	0x0081
                    0082    289 Fwireless_adc_tx$P0_2$0$0 == 0x0082
                    0082    290 _P0_2	=	0x0082
                    0083    291 Fwireless_adc_tx$P0_3$0$0 == 0x0083
                    0083    292 _P0_3	=	0x0083
                    0084    293 Fwireless_adc_tx$P0_4$0$0 == 0x0084
                    0084    294 _P0_4	=	0x0084
                    0085    295 Fwireless_adc_tx$P0_5$0$0 == 0x0085
                    0085    296 _P0_5	=	0x0085
                    0086    297 Fwireless_adc_tx$P0_6$0$0 == 0x0086
                    0086    298 _P0_6	=	0x0086
                    0087    299 Fwireless_adc_tx$P0_7$0$0 == 0x0087
                    0087    300 _P0_7	=	0x0087
                    0088    301 Fwireless_adc_tx$_TCON_0$0$0 == 0x0088
                    0088    302 __TCON_0	=	0x0088
                    0089    303 Fwireless_adc_tx$RFTXRXIF$0$0 == 0x0089
                    0089    304 _RFTXRXIF	=	0x0089
                    008A    305 Fwireless_adc_tx$_TCON_2$0$0 == 0x008a
                    008A    306 __TCON_2	=	0x008a
                    008B    307 Fwireless_adc_tx$URX0IF$0$0 == 0x008b
                    008B    308 _URX0IF	=	0x008b
                    008C    309 Fwireless_adc_tx$_TCON_4$0$0 == 0x008c
                    008C    310 __TCON_4	=	0x008c
                    008D    311 Fwireless_adc_tx$ADCIF$0$0 == 0x008d
                    008D    312 _ADCIF	=	0x008d
                    008E    313 Fwireless_adc_tx$_TCON_6$0$0 == 0x008e
                    008E    314 __TCON_6	=	0x008e
                    008F    315 Fwireless_adc_tx$URX1IF$0$0 == 0x008f
                    008F    316 _URX1IF	=	0x008f
                    0090    317 Fwireless_adc_tx$P1_0$0$0 == 0x0090
                    0090    318 _P1_0	=	0x0090
                    0091    319 Fwireless_adc_tx$P1_1$0$0 == 0x0091
                    0091    320 _P1_1	=	0x0091
                    0092    321 Fwireless_adc_tx$P1_2$0$0 == 0x0092
                    0092    322 _P1_2	=	0x0092
                    0093    323 Fwireless_adc_tx$P1_3$0$0 == 0x0093
                    0093    324 _P1_3	=	0x0093
                    0094    325 Fwireless_adc_tx$P1_4$0$0 == 0x0094
                    0094    326 _P1_4	=	0x0094
                    0095    327 Fwireless_adc_tx$P1_5$0$0 == 0x0095
                    0095    328 _P1_5	=	0x0095
                    0096    329 Fwireless_adc_tx$P1_6$0$0 == 0x0096
                    0096    330 _P1_6	=	0x0096
                    0097    331 Fwireless_adc_tx$P1_7$0$0 == 0x0097
                    0097    332 _P1_7	=	0x0097
                    0098    333 Fwireless_adc_tx$ENCIF_0$0$0 == 0x0098
                    0098    334 _ENCIF_0	=	0x0098
                    0099    335 Fwireless_adc_tx$ENCIF_1$0$0 == 0x0099
                    0099    336 _ENCIF_1	=	0x0099
                    009A    337 Fwireless_adc_tx$_SOCON2$0$0 == 0x009a
                    009A    338 __SOCON2	=	0x009a
                    009B    339 Fwireless_adc_tx$_SOCON3$0$0 == 0x009b
                    009B    340 __SOCON3	=	0x009b
                    009C    341 Fwireless_adc_tx$_SOCON4$0$0 == 0x009c
                    009C    342 __SOCON4	=	0x009c
                    009D    343 Fwireless_adc_tx$_SOCON5$0$0 == 0x009d
                    009D    344 __SOCON5	=	0x009d
                    009E    345 Fwireless_adc_tx$_SOCON6$0$0 == 0x009e
                    009E    346 __SOCON6	=	0x009e
                    009F    347 Fwireless_adc_tx$_SOCON7$0$0 == 0x009f
                    009F    348 __SOCON7	=	0x009f
                    00A0    349 Fwireless_adc_tx$P2_0$0$0 == 0x00a0
                    00A0    350 _P2_0	=	0x00a0
                    00A1    351 Fwireless_adc_tx$P2_1$0$0 == 0x00a1
                    00A1    352 _P2_1	=	0x00a1
                    00A2    353 Fwireless_adc_tx$P2_2$0$0 == 0x00a2
                    00A2    354 _P2_2	=	0x00a2
                    00A3    355 Fwireless_adc_tx$P2_3$0$0 == 0x00a3
                    00A3    356 _P2_3	=	0x00a3
                    00A4    357 Fwireless_adc_tx$P2_4$0$0 == 0x00a4
                    00A4    358 _P2_4	=	0x00a4
                    00A5    359 Fwireless_adc_tx$P2_5$0$0 == 0x00a5
                    00A5    360 _P2_5	=	0x00a5
                    00A6    361 Fwireless_adc_tx$P2_6$0$0 == 0x00a6
                    00A6    362 _P2_6	=	0x00a6
                    00A7    363 Fwireless_adc_tx$P2_7$0$0 == 0x00a7
                    00A7    364 _P2_7	=	0x00a7
                    00A8    365 Fwireless_adc_tx$RFTXRXIE$0$0 == 0x00a8
                    00A8    366 _RFTXRXIE	=	0x00a8
                    00A9    367 Fwireless_adc_tx$ADCIE$0$0 == 0x00a9
                    00A9    368 _ADCIE	=	0x00a9
                    00AA    369 Fwireless_adc_tx$URX0IE$0$0 == 0x00aa
                    00AA    370 _URX0IE	=	0x00aa
                    00AB    371 Fwireless_adc_tx$URX1IE$0$0 == 0x00ab
                    00AB    372 _URX1IE	=	0x00ab
                    00AC    373 Fwireless_adc_tx$ENCIE$0$0 == 0x00ac
                    00AC    374 _ENCIE	=	0x00ac
                    00AD    375 Fwireless_adc_tx$STIE$0$0 == 0x00ad
                    00AD    376 _STIE	=	0x00ad
                    00AE    377 Fwireless_adc_tx$_IEN06$0$0 == 0x00ae
                    00AE    378 __IEN06	=	0x00ae
                    00AF    379 Fwireless_adc_tx$EA$0$0 == 0x00af
                    00AF    380 _EA	=	0x00af
                    00B8    381 Fwireless_adc_tx$DMAIE$0$0 == 0x00b8
                    00B8    382 _DMAIE	=	0x00b8
                    00B9    383 Fwireless_adc_tx$T1IE$0$0 == 0x00b9
                    00B9    384 _T1IE	=	0x00b9
                    00BA    385 Fwireless_adc_tx$T2IE$0$0 == 0x00ba
                    00BA    386 _T2IE	=	0x00ba
                    00BB    387 Fwireless_adc_tx$T3IE$0$0 == 0x00bb
                    00BB    388 _T3IE	=	0x00bb
                    00BC    389 Fwireless_adc_tx$T4IE$0$0 == 0x00bc
                    00BC    390 _T4IE	=	0x00bc
                    00BD    391 Fwireless_adc_tx$P0IE$0$0 == 0x00bd
                    00BD    392 _P0IE	=	0x00bd
                    00BE    393 Fwireless_adc_tx$_IEN16$0$0 == 0x00be
                    00BE    394 __IEN16	=	0x00be
                    00BF    395 Fwireless_adc_tx$_IEN17$0$0 == 0x00bf
                    00BF    396 __IEN17	=	0x00bf
                    00C0    397 Fwireless_adc_tx$DMAIF$0$0 == 0x00c0
                    00C0    398 _DMAIF	=	0x00c0
                    00C1    399 Fwireless_adc_tx$T1IF$0$0 == 0x00c1
                    00C1    400 _T1IF	=	0x00c1
                    00C2    401 Fwireless_adc_tx$T2IF$0$0 == 0x00c2
                    00C2    402 _T2IF	=	0x00c2
                    00C3    403 Fwireless_adc_tx$T3IF$0$0 == 0x00c3
                    00C3    404 _T3IF	=	0x00c3
                    00C4    405 Fwireless_adc_tx$T4IF$0$0 == 0x00c4
                    00C4    406 _T4IF	=	0x00c4
                    00C5    407 Fwireless_adc_tx$P0IF$0$0 == 0x00c5
                    00C5    408 _P0IF	=	0x00c5
                    00C6    409 Fwireless_adc_tx$_IRCON6$0$0 == 0x00c6
                    00C6    410 __IRCON6	=	0x00c6
                    00C7    411 Fwireless_adc_tx$STIF$0$0 == 0x00c7
                    00C7    412 _STIF	=	0x00c7
                    00D0    413 Fwireless_adc_tx$P$0$0 == 0x00d0
                    00D0    414 _P	=	0x00d0
                    00D1    415 Fwireless_adc_tx$F1$0$0 == 0x00d1
                    00D1    416 _F1	=	0x00d1
                    00D2    417 Fwireless_adc_tx$OV$0$0 == 0x00d2
                    00D2    418 _OV	=	0x00d2
                    00D3    419 Fwireless_adc_tx$RS0$0$0 == 0x00d3
                    00D3    420 _RS0	=	0x00d3
                    00D4    421 Fwireless_adc_tx$RS1$0$0 == 0x00d4
                    00D4    422 _RS1	=	0x00d4
                    00D5    423 Fwireless_adc_tx$F0$0$0 == 0x00d5
                    00D5    424 _F0	=	0x00d5
                    00D6    425 Fwireless_adc_tx$AC$0$0 == 0x00d6
                    00D6    426 _AC	=	0x00d6
                    00D7    427 Fwireless_adc_tx$CY$0$0 == 0x00d7
                    00D7    428 _CY	=	0x00d7
                    00D8    429 Fwireless_adc_tx$T3OVFIF$0$0 == 0x00d8
                    00D8    430 _T3OVFIF	=	0x00d8
                    00D9    431 Fwireless_adc_tx$T3CH0IF$0$0 == 0x00d9
                    00D9    432 _T3CH0IF	=	0x00d9
                    00DA    433 Fwireless_adc_tx$T3CH1IF$0$0 == 0x00da
                    00DA    434 _T3CH1IF	=	0x00da
                    00DB    435 Fwireless_adc_tx$T4OVFIF$0$0 == 0x00db
                    00DB    436 _T4OVFIF	=	0x00db
                    00DC    437 Fwireless_adc_tx$T4CH0IF$0$0 == 0x00dc
                    00DC    438 _T4CH0IF	=	0x00dc
                    00DD    439 Fwireless_adc_tx$T4CH1IF$0$0 == 0x00dd
                    00DD    440 _T4CH1IF	=	0x00dd
                    00DE    441 Fwireless_adc_tx$OVFIM$0$0 == 0x00de
                    00DE    442 _OVFIM	=	0x00de
                    00DF    443 Fwireless_adc_tx$_TIMIF7$0$0 == 0x00df
                    00DF    444 __TIMIF7	=	0x00df
                    00E0    445 Fwireless_adc_tx$ACC_0$0$0 == 0x00e0
                    00E0    446 _ACC_0	=	0x00e0
                    00E1    447 Fwireless_adc_tx$ACC_1$0$0 == 0x00e1
                    00E1    448 _ACC_1	=	0x00e1
                    00E2    449 Fwireless_adc_tx$ACC_2$0$0 == 0x00e2
                    00E2    450 _ACC_2	=	0x00e2
                    00E3    451 Fwireless_adc_tx$ACC_3$0$0 == 0x00e3
                    00E3    452 _ACC_3	=	0x00e3
                    00E4    453 Fwireless_adc_tx$ACC_4$0$0 == 0x00e4
                    00E4    454 _ACC_4	=	0x00e4
                    00E5    455 Fwireless_adc_tx$ACC_5$0$0 == 0x00e5
                    00E5    456 _ACC_5	=	0x00e5
                    00E6    457 Fwireless_adc_tx$ACC_6$0$0 == 0x00e6
                    00E6    458 _ACC_6	=	0x00e6
                    00E7    459 Fwireless_adc_tx$ACC_7$0$0 == 0x00e7
                    00E7    460 _ACC_7	=	0x00e7
                    00E8    461 Fwireless_adc_tx$P2IF$0$0 == 0x00e8
                    00E8    462 _P2IF	=	0x00e8
                    00E9    463 Fwireless_adc_tx$UTX0IF$0$0 == 0x00e9
                    00E9    464 _UTX0IF	=	0x00e9
                    00EA    465 Fwireless_adc_tx$UTX1IF$0$0 == 0x00ea
                    00EA    466 _UTX1IF	=	0x00ea
                    00EB    467 Fwireless_adc_tx$P1IF$0$0 == 0x00eb
                    00EB    468 _P1IF	=	0x00eb
                    00EC    469 Fwireless_adc_tx$WDTIF$0$0 == 0x00ec
                    00EC    470 _WDTIF	=	0x00ec
                    00ED    471 Fwireless_adc_tx$_IRCON25$0$0 == 0x00ed
                    00ED    472 __IRCON25	=	0x00ed
                    00EE    473 Fwireless_adc_tx$_IRCON26$0$0 == 0x00ee
                    00EE    474 __IRCON26	=	0x00ee
                    00EF    475 Fwireless_adc_tx$_IRCON27$0$0 == 0x00ef
                    00EF    476 __IRCON27	=	0x00ef
                    00F0    477 Fwireless_adc_tx$B_0$0$0 == 0x00f0
                    00F0    478 _B_0	=	0x00f0
                    00F1    479 Fwireless_adc_tx$B_1$0$0 == 0x00f1
                    00F1    480 _B_1	=	0x00f1
                    00F2    481 Fwireless_adc_tx$B_2$0$0 == 0x00f2
                    00F2    482 _B_2	=	0x00f2
                    00F3    483 Fwireless_adc_tx$B_3$0$0 == 0x00f3
                    00F3    484 _B_3	=	0x00f3
                    00F4    485 Fwireless_adc_tx$B_4$0$0 == 0x00f4
                    00F4    486 _B_4	=	0x00f4
                    00F5    487 Fwireless_adc_tx$B_5$0$0 == 0x00f5
                    00F5    488 _B_5	=	0x00f5
                    00F6    489 Fwireless_adc_tx$B_6$0$0 == 0x00f6
                    00F6    490 _B_6	=	0x00f6
                    00F7    491 Fwireless_adc_tx$B_7$0$0 == 0x00f7
                    00F7    492 _B_7	=	0x00f7
                    00F8    493 Fwireless_adc_tx$U1ACTIVE$0$0 == 0x00f8
                    00F8    494 _U1ACTIVE	=	0x00f8
                    00F9    495 Fwireless_adc_tx$U1TX_BYTE$0$0 == 0x00f9
                    00F9    496 _U1TX_BYTE	=	0x00f9
                    00FA    497 Fwireless_adc_tx$U1RX_BYTE$0$0 == 0x00fa
                    00FA    498 _U1RX_BYTE	=	0x00fa
                    00FB    499 Fwireless_adc_tx$U1ERR$0$0 == 0x00fb
                    00FB    500 _U1ERR	=	0x00fb
                    00FC    501 Fwireless_adc_tx$U1FE$0$0 == 0x00fc
                    00FC    502 _U1FE	=	0x00fc
                    00FD    503 Fwireless_adc_tx$U1SLAVE$0$0 == 0x00fd
                    00FD    504 _U1SLAVE	=	0x00fd
                    00FE    505 Fwireless_adc_tx$U1RE$0$0 == 0x00fe
                    00FE    506 _U1RE	=	0x00fe
                    00FF    507 Fwireless_adc_tx$U1MODE$0$0 == 0x00ff
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
                    0000    518 Lwireless_adc_tx.adcToRadioService$sloc0$1$0==.
   0008                     519 _adcToRadioService_sloc0_1_0:
   0008                     520 	.ds 4
                            521 ;--------------------------------------------------------
                            522 ; overlayable items in internal ram 
                            523 ;--------------------------------------------------------
                            524 	.area OSEG    (OVR,DATA)
                            525 ;--------------------------------------------------------
                            526 ; Stack segment in internal ram 
                            527 ;--------------------------------------------------------
                            528 	.area	SSEG	(DATA)
   0023                     529 __start__stack:
   0023                     530 	.ds	1
                            531 
                            532 ;--------------------------------------------------------
                            533 ; indirectly addressable internal ram data
                            534 ;--------------------------------------------------------
                            535 	.area ISEG    (DATA)
                            536 ;--------------------------------------------------------
                            537 ; absolute internal ram data
                            538 ;--------------------------------------------------------
                            539 	.area IABS    (ABS,DATA)
                            540 	.area IABS    (ABS,DATA)
                            541 ;--------------------------------------------------------
                            542 ; bit data
                            543 ;--------------------------------------------------------
                            544 	.area BSEG    (BIT)
                            545 ;--------------------------------------------------------
                            546 ; paged external ram data
                            547 ;--------------------------------------------------------
                            548 	.area PSEG    (PAG,XDATA)
                    0000    549 Lwireless_adc_tx.adcToRadioService$lastTx$1$1==.
   F000                     550 _adcToRadioService_lastTx_1_1:
   F000                     551 	.ds 2
                    0002    552 Lwireless_adc_tx.adcToRadioService$ptr$2$2==.
   F002                     553 _adcToRadioService_ptr_2_2:
   F002                     554 	.ds 2
                            555 ;--------------------------------------------------------
                            556 ; external ram data
                            557 ;--------------------------------------------------------
                            558 	.area XSEG    (XDATA)
                    DF00    559 Fwireless_adc_tx$SYNC1$0$0 == 0xdf00
                    DF00    560 _SYNC1	=	0xdf00
                    DF01    561 Fwireless_adc_tx$SYNC0$0$0 == 0xdf01
                    DF01    562 _SYNC0	=	0xdf01
                    DF02    563 Fwireless_adc_tx$PKTLEN$0$0 == 0xdf02
                    DF02    564 _PKTLEN	=	0xdf02
                    DF03    565 Fwireless_adc_tx$PKTCTRL1$0$0 == 0xdf03
                    DF03    566 _PKTCTRL1	=	0xdf03
                    DF04    567 Fwireless_adc_tx$PKTCTRL0$0$0 == 0xdf04
                    DF04    568 _PKTCTRL0	=	0xdf04
                    DF05    569 Fwireless_adc_tx$ADDR$0$0 == 0xdf05
                    DF05    570 _ADDR	=	0xdf05
                    DF06    571 Fwireless_adc_tx$CHANNR$0$0 == 0xdf06
                    DF06    572 _CHANNR	=	0xdf06
                    DF07    573 Fwireless_adc_tx$FSCTRL1$0$0 == 0xdf07
                    DF07    574 _FSCTRL1	=	0xdf07
                    DF08    575 Fwireless_adc_tx$FSCTRL0$0$0 == 0xdf08
                    DF08    576 _FSCTRL0	=	0xdf08
                    DF09    577 Fwireless_adc_tx$FREQ2$0$0 == 0xdf09
                    DF09    578 _FREQ2	=	0xdf09
                    DF0A    579 Fwireless_adc_tx$FREQ1$0$0 == 0xdf0a
                    DF0A    580 _FREQ1	=	0xdf0a
                    DF0B    581 Fwireless_adc_tx$FREQ0$0$0 == 0xdf0b
                    DF0B    582 _FREQ0	=	0xdf0b
                    DF0C    583 Fwireless_adc_tx$MDMCFG4$0$0 == 0xdf0c
                    DF0C    584 _MDMCFG4	=	0xdf0c
                    DF0D    585 Fwireless_adc_tx$MDMCFG3$0$0 == 0xdf0d
                    DF0D    586 _MDMCFG3	=	0xdf0d
                    DF0E    587 Fwireless_adc_tx$MDMCFG2$0$0 == 0xdf0e
                    DF0E    588 _MDMCFG2	=	0xdf0e
                    DF0F    589 Fwireless_adc_tx$MDMCFG1$0$0 == 0xdf0f
                    DF0F    590 _MDMCFG1	=	0xdf0f
                    DF10    591 Fwireless_adc_tx$MDMCFG0$0$0 == 0xdf10
                    DF10    592 _MDMCFG0	=	0xdf10
                    DF11    593 Fwireless_adc_tx$DEVIATN$0$0 == 0xdf11
                    DF11    594 _DEVIATN	=	0xdf11
                    DF12    595 Fwireless_adc_tx$MCSM2$0$0 == 0xdf12
                    DF12    596 _MCSM2	=	0xdf12
                    DF13    597 Fwireless_adc_tx$MCSM1$0$0 == 0xdf13
                    DF13    598 _MCSM1	=	0xdf13
                    DF14    599 Fwireless_adc_tx$MCSM0$0$0 == 0xdf14
                    DF14    600 _MCSM0	=	0xdf14
                    DF15    601 Fwireless_adc_tx$FOCCFG$0$0 == 0xdf15
                    DF15    602 _FOCCFG	=	0xdf15
                    DF16    603 Fwireless_adc_tx$BSCFG$0$0 == 0xdf16
                    DF16    604 _BSCFG	=	0xdf16
                    DF17    605 Fwireless_adc_tx$AGCCTRL2$0$0 == 0xdf17
                    DF17    606 _AGCCTRL2	=	0xdf17
                    DF18    607 Fwireless_adc_tx$AGCCTRL1$0$0 == 0xdf18
                    DF18    608 _AGCCTRL1	=	0xdf18
                    DF19    609 Fwireless_adc_tx$AGCCTRL0$0$0 == 0xdf19
                    DF19    610 _AGCCTRL0	=	0xdf19
                    DF1A    611 Fwireless_adc_tx$FREND1$0$0 == 0xdf1a
                    DF1A    612 _FREND1	=	0xdf1a
                    DF1B    613 Fwireless_adc_tx$FREND0$0$0 == 0xdf1b
                    DF1B    614 _FREND0	=	0xdf1b
                    DF1C    615 Fwireless_adc_tx$FSCAL3$0$0 == 0xdf1c
                    DF1C    616 _FSCAL3	=	0xdf1c
                    DF1D    617 Fwireless_adc_tx$FSCAL2$0$0 == 0xdf1d
                    DF1D    618 _FSCAL2	=	0xdf1d
                    DF1E    619 Fwireless_adc_tx$FSCAL1$0$0 == 0xdf1e
                    DF1E    620 _FSCAL1	=	0xdf1e
                    DF1F    621 Fwireless_adc_tx$FSCAL0$0$0 == 0xdf1f
                    DF1F    622 _FSCAL0	=	0xdf1f
                    DF23    623 Fwireless_adc_tx$TEST2$0$0 == 0xdf23
                    DF23    624 _TEST2	=	0xdf23
                    DF24    625 Fwireless_adc_tx$TEST1$0$0 == 0xdf24
                    DF24    626 _TEST1	=	0xdf24
                    DF25    627 Fwireless_adc_tx$TEST0$0$0 == 0xdf25
                    DF25    628 _TEST0	=	0xdf25
                    DF2E    629 Fwireless_adc_tx$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    630 _PA_TABLE0	=	0xdf2e
                    DF2F    631 Fwireless_adc_tx$IOCFG2$0$0 == 0xdf2f
                    DF2F    632 _IOCFG2	=	0xdf2f
                    DF30    633 Fwireless_adc_tx$IOCFG1$0$0 == 0xdf30
                    DF30    634 _IOCFG1	=	0xdf30
                    DF31    635 Fwireless_adc_tx$IOCFG0$0$0 == 0xdf31
                    DF31    636 _IOCFG0	=	0xdf31
                    DF36    637 Fwireless_adc_tx$PARTNUM$0$0 == 0xdf36
                    DF36    638 _PARTNUM	=	0xdf36
                    DF37    639 Fwireless_adc_tx$VERSION$0$0 == 0xdf37
                    DF37    640 _VERSION	=	0xdf37
                    DF38    641 Fwireless_adc_tx$FREQEST$0$0 == 0xdf38
                    DF38    642 _FREQEST	=	0xdf38
                    DF39    643 Fwireless_adc_tx$LQI$0$0 == 0xdf39
                    DF39    644 _LQI	=	0xdf39
                    DF3A    645 Fwireless_adc_tx$RSSI$0$0 == 0xdf3a
                    DF3A    646 _RSSI	=	0xdf3a
                    DF3B    647 Fwireless_adc_tx$MARCSTATE$0$0 == 0xdf3b
                    DF3B    648 _MARCSTATE	=	0xdf3b
                    DF3C    649 Fwireless_adc_tx$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    650 _PKTSTATUS	=	0xdf3c
                    DF3D    651 Fwireless_adc_tx$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    652 _VCO_VC_DAC	=	0xdf3d
                    DF40    653 Fwireless_adc_tx$I2SCFG0$0$0 == 0xdf40
                    DF40    654 _I2SCFG0	=	0xdf40
                    DF41    655 Fwireless_adc_tx$I2SCFG1$0$0 == 0xdf41
                    DF41    656 _I2SCFG1	=	0xdf41
                    DF42    657 Fwireless_adc_tx$I2SDATL$0$0 == 0xdf42
                    DF42    658 _I2SDATL	=	0xdf42
                    DF43    659 Fwireless_adc_tx$I2SDATH$0$0 == 0xdf43
                    DF43    660 _I2SDATH	=	0xdf43
                    DF44    661 Fwireless_adc_tx$I2SWCNT$0$0 == 0xdf44
                    DF44    662 _I2SWCNT	=	0xdf44
                    DF45    663 Fwireless_adc_tx$I2SSTAT$0$0 == 0xdf45
                    DF45    664 _I2SSTAT	=	0xdf45
                    DF46    665 Fwireless_adc_tx$I2SCLKF0$0$0 == 0xdf46
                    DF46    666 _I2SCLKF0	=	0xdf46
                    DF47    667 Fwireless_adc_tx$I2SCLKF1$0$0 == 0xdf47
                    DF47    668 _I2SCLKF1	=	0xdf47
                    DF48    669 Fwireless_adc_tx$I2SCLKF2$0$0 == 0xdf48
                    DF48    670 _I2SCLKF2	=	0xdf48
                    DE00    671 Fwireless_adc_tx$USBADDR$0$0 == 0xde00
                    DE00    672 _USBADDR	=	0xde00
                    DE01    673 Fwireless_adc_tx$USBPOW$0$0 == 0xde01
                    DE01    674 _USBPOW	=	0xde01
                    DE02    675 Fwireless_adc_tx$USBIIF$0$0 == 0xde02
                    DE02    676 _USBIIF	=	0xde02
                    DE04    677 Fwireless_adc_tx$USBOIF$0$0 == 0xde04
                    DE04    678 _USBOIF	=	0xde04
                    DE06    679 Fwireless_adc_tx$USBCIF$0$0 == 0xde06
                    DE06    680 _USBCIF	=	0xde06
                    DE07    681 Fwireless_adc_tx$USBIIE$0$0 == 0xde07
                    DE07    682 _USBIIE	=	0xde07
                    DE09    683 Fwireless_adc_tx$USBOIE$0$0 == 0xde09
                    DE09    684 _USBOIE	=	0xde09
                    DE0B    685 Fwireless_adc_tx$USBCIE$0$0 == 0xde0b
                    DE0B    686 _USBCIE	=	0xde0b
                    DE0C    687 Fwireless_adc_tx$USBFRML$0$0 == 0xde0c
                    DE0C    688 _USBFRML	=	0xde0c
                    DE0D    689 Fwireless_adc_tx$USBFRMH$0$0 == 0xde0d
                    DE0D    690 _USBFRMH	=	0xde0d
                    DE0E    691 Fwireless_adc_tx$USBINDEX$0$0 == 0xde0e
                    DE0E    692 _USBINDEX	=	0xde0e
                    DE10    693 Fwireless_adc_tx$USBMAXI$0$0 == 0xde10
                    DE10    694 _USBMAXI	=	0xde10
                    DE11    695 Fwireless_adc_tx$USBCSIL$0$0 == 0xde11
                    DE11    696 _USBCSIL	=	0xde11
                    DE12    697 Fwireless_adc_tx$USBCSIH$0$0 == 0xde12
                    DE12    698 _USBCSIH	=	0xde12
                    DE13    699 Fwireless_adc_tx$USBMAXO$0$0 == 0xde13
                    DE13    700 _USBMAXO	=	0xde13
                    DE14    701 Fwireless_adc_tx$USBCSOL$0$0 == 0xde14
                    DE14    702 _USBCSOL	=	0xde14
                    DE15    703 Fwireless_adc_tx$USBCSOH$0$0 == 0xde15
                    DE15    704 _USBCSOH	=	0xde15
                    DE16    705 Fwireless_adc_tx$USBCNTL$0$0 == 0xde16
                    DE16    706 _USBCNTL	=	0xde16
                    DE17    707 Fwireless_adc_tx$USBCNTH$0$0 == 0xde17
                    DE17    708 _USBCNTH	=	0xde17
                    DE20    709 Fwireless_adc_tx$USBF0$0$0 == 0xde20
                    DE20    710 _USBF0	=	0xde20
                    DE22    711 Fwireless_adc_tx$USBF1$0$0 == 0xde22
                    DE22    712 _USBF1	=	0xde22
                    DE24    713 Fwireless_adc_tx$USBF2$0$0 == 0xde24
                    DE24    714 _USBF2	=	0xde24
                    DE26    715 Fwireless_adc_tx$USBF3$0$0 == 0xde26
                    DE26    716 _USBF3	=	0xde26
                    DE28    717 Fwireless_adc_tx$USBF4$0$0 == 0xde28
                    DE28    718 _USBF4	=	0xde28
                    DE2A    719 Fwireless_adc_tx$USBF5$0$0 == 0xde2a
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
   0463 02 10 81            769 	ljmp	_ISR_T4
   0466                     770 	.ds	5
   046B 32                  771 	reti
   046C                     772 	.ds	7
   0473 32                  773 	reti
   0474                     774 	.ds	7
   047B 32                  775 	reti
   047C                     776 	.ds	7
   0483 02 07 20            777 	ljmp	_ISR_RF
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
                            791 ;------------------------------------------------------------
                            792 ;Allocation info for local variables in function 'adcToRadioService'
                            793 ;------------------------------------------------------------
                            794 ;sloc0                     Allocated with name '_adcToRadioService_sloc0_1_0'
                            795 ;------------------------------------------------------------
                    0000    796 	G$adcToRadioService$0$0 ==.
                    0000    797 	C$wireless_adc_tx.c$64$2$1 ==.
                            798 ;	apps/wireless_adc_tx/wireless_adc_tx.c:64: static uint16 lastTx = 0;
   04E6 78 00               799 	mov	r0,#_adcToRadioService_lastTx_1_1
   04E8 E4                  800 	clr	a
   04E9 F2                  801 	movx	@r0,a
   04EA 08                  802 	inc	r0
   04EB F2                  803 	movx	@r0,a
                            804 	.area GSFINAL (CODE)
   0536 02 04 86            805 	ljmp	__sdcc_program_startup
                            806 ;--------------------------------------------------------
                            807 ; Home
                            808 ;--------------------------------------------------------
                            809 	.area HOME    (CODE)
                            810 	.area HOME    (CODE)
   0486                     811 __sdcc_program_startup:
   0486 12 06 A8            812 	lcall	_main
                            813 ;	return from main will lock up
   0489 80 FE               814 	sjmp .
                            815 ;--------------------------------------------------------
                            816 ; code
                            817 ;--------------------------------------------------------
                            818 	.area CSEG    (CODE)
                            819 ;------------------------------------------------------------
                            820 ;Allocation info for local variables in function 'analogInputsInit'
                            821 ;------------------------------------------------------------
                    0000    822 	G$analogInputsInit$0$0 ==.
                    0000    823 	C$wireless_adc_tx.c$31$0$0 ==.
                            824 ;	apps/wireless_adc_tx/wireless_adc_tx.c:31: void analogInputsInit()
                            825 ;	-----------------------------------------
                            826 ;	 function analogInputsInit
                            827 ;	-----------------------------------------
   0539                     828 _analogInputsInit:
                    0007    829 	ar7 = 0x07
                    0006    830 	ar6 = 0x06
                    0005    831 	ar5 = 0x05
                    0004    832 	ar4 = 0x04
                    0003    833 	ar3 = 0x03
                    0002    834 	ar2 = 0x02
                    0001    835 	ar1 = 0x01
                    0000    836 	ar0 = 0x00
                    0000    837 	C$wireless_adc_tx.c$33$1$1 ==.
                            838 ;	apps/wireless_adc_tx/wireless_adc_tx.c:33: switch(param_input_mode)
   0539 90 1A 77            839 	mov	dptr,#_param_input_mode
   053C E4                  840 	clr	a
   053D 93                  841 	movc	a,@a+dptr
   053E FC                  842 	mov	r4,a
   053F 74 01               843 	mov	a,#0x01
   0541 93                  844 	movc	a,@a+dptr
   0542 FD                  845 	mov	r5,a
   0543 74 02               846 	mov	a,#0x02
   0545 93                  847 	movc	a,@a+dptr
   0546 FE                  848 	mov	r6,a
   0547 74 03               849 	mov	a,#0x03
   0549 93                  850 	movc	a,@a+dptr
   054A FF                  851 	mov	r7,a
   054B BC FF 0B            852 	cjne	r4,#0xFF,00109$
   054E BD FF 08            853 	cjne	r5,#0xFF,00109$
   0551 BE FF 05            854 	cjne	r6,#0xFF,00109$
   0554 BF FF 02            855 	cjne	r7,#0xFF,00109$
   0557 80 18               856 	sjmp	00102$
   0559                     857 00109$:
   0559 BC 01 1D            858 	cjne	r4,#0x01,00103$
   055C BD 00 1A            859 	cjne	r5,#0x00,00103$
   055F BE 00 17            860 	cjne	r6,#0x00,00103$
   0562 BF 00 14            861 	cjne	r7,#0x00,00103$
                    002C    862 	C$wireless_adc_tx.c$37$2$2 ==.
                            863 ;	apps/wireless_adc_tx/wireless_adc_tx.c:37: P2INP &= ~(1<<5);  // PDUP0 = 0: Pull-ups on Port 0.
   0565 AF F7               864 	mov	r7,_P2INP
   0567 53 07 DF            865 	anl	ar7,#0xDF
   056A 8F F7               866 	mov	_P2INP,r7
                    0033    867 	C$wireless_adc_tx.c$38$2$2 ==.
                            868 ;	apps/wireless_adc_tx/wireless_adc_tx.c:38: P0INP = 0;
   056C 75 8F 00            869 	mov	_P0INP,#0x00
                    0036    870 	C$wireless_adc_tx.c$39$2$2 ==.
                            871 ;	apps/wireless_adc_tx/wireless_adc_tx.c:39: break;
                    0036    872 	C$wireless_adc_tx.c$41$2$2 ==.
                            873 ;	apps/wireless_adc_tx/wireless_adc_tx.c:41: case -1: // Enable pull-down resistors for all pins on Port 0.
   056F 80 0B               874 	sjmp	00105$
   0571                     875 00102$:
                    0038    876 	C$wireless_adc_tx.c$42$2$2 ==.
                            877 ;	apps/wireless_adc_tx/wireless_adc_tx.c:42: P2INP |= (1<<5);   // PDUP0 = 1: Pull-downs on Port 0.
   0571 43 F7 20            878 	orl	_P2INP,#0x20
                    003B    879 	C$wireless_adc_tx.c$43$2$2 ==.
                            880 ;	apps/wireless_adc_tx/wireless_adc_tx.c:43: P0INP = 0;         // This line should not be necessary because P0SEL is 0 on reset.
   0574 75 8F 00            881 	mov	_P0INP,#0x00
                    003E    882 	C$wireless_adc_tx.c$44$2$2 ==.
                            883 ;	apps/wireless_adc_tx/wireless_adc_tx.c:44: break;
                    003E    884 	C$wireless_adc_tx.c$46$2$2 ==.
                            885 ;	apps/wireless_adc_tx/wireless_adc_tx.c:46: default: // Disable pull-ups and pull-downs for all pins on Port 0.
   0577 80 03               886 	sjmp	00105$
   0579                     887 00103$:
                    0040    888 	C$wireless_adc_tx.c$47$2$2 ==.
                            889 ;	apps/wireless_adc_tx/wireless_adc_tx.c:47: P0INP = 0x3F;
   0579 75 8F 3F            890 	mov	_P0INP,#0x3F
                    0043    891 	C$wireless_adc_tx.c$49$1$1 ==.
                            892 ;	apps/wireless_adc_tx/wireless_adc_tx.c:49: }
   057C                     893 00105$:
                    0043    894 	C$wireless_adc_tx.c$50$1$1 ==.
                    0043    895 	XG$analogInputsInit$0$0 ==.
   057C 22                  896 	ret
                            897 ;------------------------------------------------------------
                            898 ;Allocation info for local variables in function 'updateLeds'
                            899 ;------------------------------------------------------------
                    0044    900 	G$updateLeds$0$0 ==.
                    0044    901 	C$wireless_adc_tx.c$52$1$1 ==.
                            902 ;	apps/wireless_adc_tx/wireless_adc_tx.c:52: void updateLeds()
                            903 ;	-----------------------------------------
                            904 ;	 function updateLeds
                            905 ;	-----------------------------------------
   057D                     906 _updateLeds:
                    0044    907 	C$wireless_adc_tx.c$54$1$1 ==.
                            908 ;	apps/wireless_adc_tx/wireless_adc_tx.c:54: usbShowStatusWithGreenLed();
   057D 12 19 BA            909 	lcall	_usbShowStatusWithGreenLed
                    0047    910 	C$wireless_adc_tx.c$55$2$2 ==.
                            911 ;	apps/wireless_adc_tx/wireless_adc_tx.c:55: LED_YELLOW(1);
   0580 43 FF 04            912 	orl	_P2DIR,#0x04
                    004A    913 	C$wireless_adc_tx.c$56$2$3 ==.
                            914 ;	apps/wireless_adc_tx/wireless_adc_tx.c:56: LED_RED(0);
   0583 AF FF               915 	mov	r7,_P2DIR
   0585 53 07 FD            916 	anl	ar7,#0xFD
   0588 8F FF               917 	mov	_P2DIR,r7
                    0051    918 	C$wireless_adc_tx.c$57$2$3 ==.
                    0051    919 	XG$updateLeds$0$0 ==.
   058A 22                  920 	ret
                            921 ;------------------------------------------------------------
                            922 ;Allocation info for local variables in function 'adcToRadioService'
                            923 ;------------------------------------------------------------
                            924 ;sloc0                     Allocated with name '_adcToRadioService_sloc0_1_0'
                            925 ;------------------------------------------------------------
                    0052    926 	G$adcToRadioService$0$0 ==.
                    0052    927 	C$wireless_adc_tx.c$62$2$3 ==.
                            928 ;	apps/wireless_adc_tx/wireless_adc_tx.c:62: void adcToRadioService()
                            929 ;	-----------------------------------------
                            930 ;	 function adcToRadioService
                            931 ;	-----------------------------------------
   058B                     932 _adcToRadioService:
                    0052    933 	C$wireless_adc_tx.c$70$1$1 ==.
                            934 ;	apps/wireless_adc_tx/wireless_adc_tx.c:70: if ((uint16)(getMs() - lastTx) >= param_report_period_ms && (txPacket = radioQueueTxCurrentPacket()))
   058B 12 10 A6            935 	lcall	_getMs
   058E 85 82 08            936 	mov	_adcToRadioService_sloc0_1_0,dpl
   0591 85 83 09            937 	mov	(_adcToRadioService_sloc0_1_0 + 1),dph
   0594 85 F0 0A            938 	mov	(_adcToRadioService_sloc0_1_0 + 2),b
   0597 F5 0B               939 	mov	(_adcToRadioService_sloc0_1_0 + 3),a
   0599 78 00               940 	mov	r0,#_adcToRadioService_lastTx_1_1
   059B E2                  941 	movx	a,@r0
   059C FA                  942 	mov	r2,a
   059D 08                  943 	inc	r0
   059E E2                  944 	movx	a,@r0
   059F FB                  945 	mov	r3,a
   05A0 E4                  946 	clr	a
   05A1 FE                  947 	mov	r6,a
   05A2 FF                  948 	mov	r7,a
   05A3 E5 08               949 	mov	a,_adcToRadioService_sloc0_1_0
   05A5 C3                  950 	clr	c
   05A6 9A                  951 	subb	a,r2
   05A7 FA                  952 	mov	r2,a
   05A8 E5 09               953 	mov	a,(_adcToRadioService_sloc0_1_0 + 1)
   05AA 9B                  954 	subb	a,r3
   05AB FB                  955 	mov	r3,a
   05AC E5 0A               956 	mov	a,(_adcToRadioService_sloc0_1_0 + 2)
   05AE 9E                  957 	subb	a,r6
   05AF E5 0B               958 	mov	a,(_adcToRadioService_sloc0_1_0 + 3)
   05B1 9F                  959 	subb	a,r7
   05B2 90 1A 7B            960 	mov	dptr,#_param_report_period_ms
   05B5 E4                  961 	clr	a
   05B6 93                  962 	movc	a,@a+dptr
   05B7 F5 08               963 	mov	_adcToRadioService_sloc0_1_0,a
   05B9 74 01               964 	mov	a,#0x01
   05BB 93                  965 	movc	a,@a+dptr
   05BC F5 09               966 	mov	(_adcToRadioService_sloc0_1_0 + 1),a
   05BE 74 02               967 	mov	a,#0x02
   05C0 93                  968 	movc	a,@a+dptr
   05C1 F5 0A               969 	mov	(_adcToRadioService_sloc0_1_0 + 2),a
   05C3 74 03               970 	mov	a,#0x03
   05C5 93                  971 	movc	a,@a+dptr
   05C6 F5 0B               972 	mov	(_adcToRadioService_sloc0_1_0 + 3),a
   05C8 7E 00               973 	mov	r6,#0x00
   05CA 7F 00               974 	mov	r7,#0x00
   05CC C3                  975 	clr	c
   05CD EA                  976 	mov	a,r2
   05CE 95 08               977 	subb	a,_adcToRadioService_sloc0_1_0
   05D0 EB                  978 	mov	a,r3
   05D1 95 09               979 	subb	a,(_adcToRadioService_sloc0_1_0 + 1)
   05D3 EE                  980 	mov	a,r6
   05D4 95 0A               981 	subb	a,(_adcToRadioService_sloc0_1_0 + 2)
   05D6 EF                  982 	mov	a,r7
   05D7 64 80               983 	xrl	a,#0x80
   05D9 85 0B F0            984 	mov	b,(_adcToRadioService_sloc0_1_0 + 3)
   05DC 63 F0 80            985 	xrl	b,#0x80
   05DF 95 F0               986 	subb	a,b
   05E1 50 03               987 	jnc	00115$
   05E3 02 06 A7            988 	ljmp	00108$
   05E6                     989 00115$:
   05E6 12 09 4C            990 	lcall	_radioQueueTxCurrentPacket
   05E9 AE 82               991 	mov	r6,dpl
   05EB AF 83               992 	mov	r7,dph
   05ED 8E 04               993 	mov	ar4,r6
   05EF 8F 05               994 	mov	ar5,r7
   05F1 EE                  995 	mov	a,r6
   05F2 4F                  996 	orl	a,r7
   05F3 70 03               997 	jnz	00116$
   05F5 02 06 A7            998 	ljmp	00108$
   05F8                     999 00116$:
                    00BF   1000 	C$wireless_adc_tx.c$75$2$2 ==.
                           1001 ;	apps/wireless_adc_tx/wireless_adc_tx.c:75: uint16 XDATA * ptr = (uint16 XDATA *)&txPacket[5];
   05F8 74 05              1002 	mov	a,#0x05
   05FA 2C                 1003 	add	a,r4
   05FB FE                 1004 	mov	r6,a
   05FC E4                 1005 	clr	a
   05FD 3D                 1006 	addc	a,r5
   05FE FF                 1007 	mov	r7,a
   05FF 78 02              1008 	mov	r0,#_adcToRadioService_ptr_2_2
   0601 EE                 1009 	mov	a,r6
   0602 F2                 1010 	movx	@r0,a
   0603 08                 1011 	inc	r0
   0604 EF                 1012 	mov	a,r7
   0605 F2                 1013 	movx	@r0,a
                    00CD   1014 	C$wireless_adc_tx.c$78$2$2 ==.
                           1015 ;	apps/wireless_adc_tx/wireless_adc_tx.c:78: lastTx = getMs();
   0606 C0 05              1016 	push	ar5
   0608 C0 04              1017 	push	ar4
   060A 12 10 A6           1018 	lcall	_getMs
   060D AA 82              1019 	mov	r2,dpl
   060F AB 83              1020 	mov	r3,dph
   0611 D0 04              1021 	pop	ar4
   0613 D0 05              1022 	pop	ar5
   0615 78 00              1023 	mov	r0,#_adcToRadioService_lastTx_1_1
   0617 EA                 1024 	mov	a,r2
   0618 F2                 1025 	movx	@r0,a
   0619 08                 1026 	inc	r0
   061A EB                 1027 	mov	a,r3
   061B F2                 1028 	movx	@r0,a
                    00E3   1029 	C$wireless_adc_tx.c$81$2$2 ==.
                           1030 ;	apps/wireless_adc_tx/wireless_adc_tx.c:81: txPacket[0] = 16;
   061C 8C 82              1031 	mov	dpl,r4
   061E 8D 83              1032 	mov	dph,r5
   0620 74 10              1033 	mov	a,#0x10
   0622 F0                 1034 	movx	@dptr,a
                    00EA   1035 	C$wireless_adc_tx.c$84$2$2 ==.
                           1036 ;	apps/wireless_adc_tx/wireless_adc_tx.c:84: txPacket[1] = serialNumber[0];
   0623 74 01              1037 	mov	a,#0x01
   0625 2C                 1038 	add	a,r4
   0626 FE                 1039 	mov	r6,a
   0627 E4                 1040 	clr	a
   0628 3D                 1041 	addc	a,r5
   0629 FF                 1042 	mov	r7,a
   062A 90 03 E0           1043 	mov	dptr,#_serialNumber
   062D E4                 1044 	clr	a
   062E 93                 1045 	movc	a,@a+dptr
   062F 8E 82              1046 	mov	dpl,r6
   0631 8F 83              1047 	mov	dph,r7
   0633 F0                 1048 	movx	@dptr,a
                    00FB   1049 	C$wireless_adc_tx.c$85$2$2 ==.
                           1050 ;	apps/wireless_adc_tx/wireless_adc_tx.c:85: txPacket[2] = serialNumber[1];
   0634 74 02              1051 	mov	a,#0x02
   0636 2C                 1052 	add	a,r4
   0637 FE                 1053 	mov	r6,a
   0638 E4                 1054 	clr	a
   0639 3D                 1055 	addc	a,r5
   063A FF                 1056 	mov	r7,a
   063B 90 03 E1           1057 	mov	dptr,#(_serialNumber + 0x0001)
   063E E4                 1058 	clr	a
   063F 93                 1059 	movc	a,@a+dptr
   0640 8E 82              1060 	mov	dpl,r6
   0642 8F 83              1061 	mov	dph,r7
   0644 F0                 1062 	movx	@dptr,a
                    010C   1063 	C$wireless_adc_tx.c$86$2$2 ==.
                           1064 ;	apps/wireless_adc_tx/wireless_adc_tx.c:86: txPacket[3] = serialNumber[2];
   0645 74 03              1065 	mov	a,#0x03
   0647 2C                 1066 	add	a,r4
   0648 FE                 1067 	mov	r6,a
   0649 E4                 1068 	clr	a
   064A 3D                 1069 	addc	a,r5
   064B FF                 1070 	mov	r7,a
   064C 90 03 E2           1071 	mov	dptr,#(_serialNumber + 0x0002)
   064F E4                 1072 	clr	a
   0650 93                 1073 	movc	a,@a+dptr
   0651 8E 82              1074 	mov	dpl,r6
   0653 8F 83              1075 	mov	dph,r7
   0655 F0                 1076 	movx	@dptr,a
                    011D   1077 	C$wireless_adc_tx.c$87$2$2 ==.
                           1078 ;	apps/wireless_adc_tx/wireless_adc_tx.c:87: txPacket[4] = serialNumber[3];
   0656 74 04              1079 	mov	a,#0x04
   0658 2C                 1080 	add	a,r4
   0659 FC                 1081 	mov	r4,a
   065A E4                 1082 	clr	a
   065B 3D                 1083 	addc	a,r5
   065C FD                 1084 	mov	r5,a
   065D 90 03 E3           1085 	mov	dptr,#(_serialNumber + 0x0003)
   0660 E4                 1086 	clr	a
   0661 93                 1087 	movc	a,@a+dptr
   0662 8C 82              1088 	mov	dpl,r4
   0664 8D 83              1089 	mov	dph,r5
   0666 F0                 1090 	movx	@dptr,a
                    012E   1091 	C$wireless_adc_tx.c$89$2$2 ==.
                           1092 ;	apps/wireless_adc_tx/wireless_adc_tx.c:89: adcSetMillivoltCalibration(adcReadVddMillivolts());
   0667 12 0A C9           1093 	lcall	_adcReadVddMillivolts
   066A 12 0B 16           1094 	lcall	_adcSetMillivoltCalibration
                    0134   1095 	C$wireless_adc_tx.c$92$2$1 ==.
                           1096 ;	apps/wireless_adc_tx/wireless_adc_tx.c:92: for (i = 0; i < 6; i++)
   066D 78 02              1097 	mov	r0,#_adcToRadioService_ptr_2_2
   066F E2                 1098 	movx	a,@r0
   0670 FE                 1099 	mov	r6,a
   0671 08                 1100 	inc	r0
   0672 E2                 1101 	movx	a,@r0
   0673 FF                 1102 	mov	r7,a
   0674 7D 00              1103 	mov	r5,#0x00
   0676                    1104 00104$:
   0676 BD 06 00           1105 	cjne	r5,#0x06,00117$
   0679                    1106 00117$:
   0679 50 29              1107 	jnc	00107$
                    0142   1108 	C$wireless_adc_tx.c$94$3$3 ==.
                           1109 ;	apps/wireless_adc_tx/wireless_adc_tx.c:94: *(ptr++) = adcConvertToMillivolts(adcRead(i));
   067B 8D 82              1110 	mov	dpl,r5
   067D C0 07              1111 	push	ar7
   067F C0 06              1112 	push	ar6
   0681 C0 05              1113 	push	ar5
   0683 12 06 C3           1114 	lcall	_adcRead
   0686 12 0B 22           1115 	lcall	_adcConvertToMillivolts
   0689 AB 82              1116 	mov	r3,dpl
   068B AC 83              1117 	mov	r4,dph
   068D D0 05              1118 	pop	ar5
   068F D0 06              1119 	pop	ar6
   0691 D0 07              1120 	pop	ar7
   0693 8E 82              1121 	mov	dpl,r6
   0695 8F 83              1122 	mov	dph,r7
   0697 EB                 1123 	mov	a,r3
   0698 F0                 1124 	movx	@dptr,a
   0699 A3                 1125 	inc	dptr
   069A EC                 1126 	mov	a,r4
   069B F0                 1127 	movx	@dptr,a
   069C A3                 1128 	inc	dptr
   069D AE 82              1129 	mov	r6,dpl
   069F AF 83              1130 	mov	r7,dph
                    0168   1131 	C$wireless_adc_tx.c$92$2$2 ==.
                           1132 ;	apps/wireless_adc_tx/wireless_adc_tx.c:92: for (i = 0; i < 6; i++)
   06A1 0D                 1133 	inc	r5
   06A2 80 D2              1134 	sjmp	00104$
   06A4                    1135 00107$:
                    016B   1136 	C$wireless_adc_tx.c$97$2$2 ==.
                           1137 ;	apps/wireless_adc_tx/wireless_adc_tx.c:97: radioQueueTxSendPacket();
   06A4 12 09 6A           1138 	lcall	_radioQueueTxSendPacket
   06A7                    1139 00108$:
                    016E   1140 	C$wireless_adc_tx.c$99$2$1 ==.
                    016E   1141 	XG$adcToRadioService$0$0 ==.
   06A7 22                 1142 	ret
                           1143 ;------------------------------------------------------------
                           1144 ;Allocation info for local variables in function 'main'
                           1145 ;------------------------------------------------------------
                    016F   1146 	G$main$0$0 ==.
                    016F   1147 	C$wireless_adc_tx.c$101$2$1 ==.
                           1148 ;	apps/wireless_adc_tx/wireless_adc_tx.c:101: void main(void)
                           1149 ;	-----------------------------------------
                           1150 ;	 function main
                           1151 ;	-----------------------------------------
   06A8                    1152 _main:
                    016F   1153 	C$wireless_adc_tx.c$103$1$1 ==.
                           1154 ;	apps/wireless_adc_tx/wireless_adc_tx.c:103: systemInit();
   06A8 12 0B 73           1155 	lcall	_systemInit
                    0172   1156 	C$wireless_adc_tx.c$104$1$1 ==.
                           1157 ;	apps/wireless_adc_tx/wireless_adc_tx.c:104: analogInputsInit();
   06AB 12 05 39           1158 	lcall	_analogInputsInit
                    0175   1159 	C$wireless_adc_tx.c$105$1$1 ==.
                           1160 ;	apps/wireless_adc_tx/wireless_adc_tx.c:105: usbInit();
   06AE 12 11 E2           1161 	lcall	_usbInit
                    0178   1162 	C$wireless_adc_tx.c$106$1$1 ==.
                           1163 ;	apps/wireless_adc_tx/wireless_adc_tx.c:106: radioQueueInit();
   06B1 12 09 08           1164 	lcall	_radioQueueInit
                    017B   1165 	C$wireless_adc_tx.c$108$1$1 ==.
                           1166 ;	apps/wireless_adc_tx/wireless_adc_tx.c:108: while(1)
   06B4                    1167 00102$:
                    017B   1168 	C$wireless_adc_tx.c$110$2$2 ==.
                           1169 ;	apps/wireless_adc_tx/wireless_adc_tx.c:110: updateLeds();
   06B4 12 05 7D           1170 	lcall	_updateLeds
                    017E   1171 	C$wireless_adc_tx.c$111$2$2 ==.
                           1172 ;	apps/wireless_adc_tx/wireless_adc_tx.c:111: boardService();
   06B7 12 0B 80           1173 	lcall	_boardService
                    0181   1174 	C$wireless_adc_tx.c$112$2$2 ==.
                           1175 ;	apps/wireless_adc_tx/wireless_adc_tx.c:112: usbComService();
   06BA 12 0D A4           1176 	lcall	_usbComService
                    0184   1177 	C$wireless_adc_tx.c$113$2$2 ==.
                           1178 ;	apps/wireless_adc_tx/wireless_adc_tx.c:113: adcToRadioService();
   06BD 12 05 8B           1179 	lcall	_adcToRadioService
   06C0 80 F2              1180 	sjmp	00102$
                    0189   1181 	C$wireless_adc_tx.c$115$1$1 ==.
                    0189   1182 	XG$main$0$0 ==.
   06C2 22                 1183 	ret
                           1184 	.area CSEG    (CODE)
                           1185 	.area CONST   (CODE)
                    0000   1186 G$param_input_mode$0$0 == .
   1A77                    1187 _param_input_mode:
   1A77 00 00 00 00        1188 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   1189 G$param_report_period_ms$0$0 == .
   1A7B                    1190 _param_report_period_ms:
   1A7B 14 00 00 00        1191 	.byte #0x14,#0x00,#0x00,#0x00	;  20
                           1192 	.area XINIT   (CODE)
                           1193 	.area CABS    (ABS,CODE)
