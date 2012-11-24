                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:00 2012
                              5 ;--------------------------------------------------------
                              6 	.module shiftbrite
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_echo_on
                             13 	.globl _param_input_bits
                             14 	.globl _main
                             15 	.globl _updateLeds
                             16 	.globl _shiftbriteInit
                             17 	.globl _shiftbriteService
                             18 	.globl _shiftbriteProcessByte
                             19 	.globl _restrictRange
                             20 	.globl _sendRGB
                             21 	.globl _sendBit
                             22 	.globl _toggleLatch
                             23 	.globl _hex
                             24 	.globl _hexCharToByte
                             25 	.globl _usbComService
                             26 	.globl _usbShowStatusWithGreenLed
                             27 	.globl _usbInit
                             28 	.globl _radioComTxSendByte
                             29 	.globl _radioComTxAvailable
                             30 	.globl _radioComTxService
                             31 	.globl _radioComRxReceiveByte
                             32 	.globl _radioComRxAvailable
                             33 	.globl _radioComInit
                             34 	.globl _delayMicroseconds
                             35 	.globl _getMs
                             36 	.globl _boardService
                             37 	.globl _systemInit
                             38 	.globl _restrictRange_PARM_3
                             39 	.globl _restrictRange_PARM_2
                             40 	.globl _sendRGB_PARM_3
                             41 	.globl _sendRGB_PARM_2
                             42 	.globl _hex_PARM_2
                             43 	.globl _shift
                             44 	.globl _hex_chars_per_color
                             45 	.globl _input_bits
                             46 	.globl _radioBlinkStart
                             47 	.globl _radioLastActivity
                             48 	.globl _lastSend
                             49 	.globl _sendBit_PARM_1
                             50 	.globl _radioBlinkActive
                             51 ;--------------------------------------------------------
                             52 ; special function registers
                             53 ;--------------------------------------------------------
                             54 	.area RSEG    (ABS,DATA)
   0000                      55 	.org 0x0000
                    0080     56 Fshiftbrite$P0$0$0 == 0x0080
                    0080     57 _P0	=	0x0080
                    0081     58 Fshiftbrite$SP$0$0 == 0x0081
                    0081     59 _SP	=	0x0081
                    0082     60 Fshiftbrite$DPL0$0$0 == 0x0082
                    0082     61 _DPL0	=	0x0082
                    0083     62 Fshiftbrite$DPH0$0$0 == 0x0083
                    0083     63 _DPH0	=	0x0083
                    0084     64 Fshiftbrite$DPL1$0$0 == 0x0084
                    0084     65 _DPL1	=	0x0084
                    0085     66 Fshiftbrite$DPH1$0$0 == 0x0085
                    0085     67 _DPH1	=	0x0085
                    0086     68 Fshiftbrite$U0CSR$0$0 == 0x0086
                    0086     69 _U0CSR	=	0x0086
                    0087     70 Fshiftbrite$PCON$0$0 == 0x0087
                    0087     71 _PCON	=	0x0087
                    0088     72 Fshiftbrite$TCON$0$0 == 0x0088
                    0088     73 _TCON	=	0x0088
                    0089     74 Fshiftbrite$P0IFG$0$0 == 0x0089
                    0089     75 _P0IFG	=	0x0089
                    008A     76 Fshiftbrite$P1IFG$0$0 == 0x008a
                    008A     77 _P1IFG	=	0x008a
                    008B     78 Fshiftbrite$P2IFG$0$0 == 0x008b
                    008B     79 _P2IFG	=	0x008b
                    008C     80 Fshiftbrite$PICTL$0$0 == 0x008c
                    008C     81 _PICTL	=	0x008c
                    008D     82 Fshiftbrite$P1IEN$0$0 == 0x008d
                    008D     83 _P1IEN	=	0x008d
                    008F     84 Fshiftbrite$P0INP$0$0 == 0x008f
                    008F     85 _P0INP	=	0x008f
                    0090     86 Fshiftbrite$P1$0$0 == 0x0090
                    0090     87 _P1	=	0x0090
                    0091     88 Fshiftbrite$RFIM$0$0 == 0x0091
                    0091     89 _RFIM	=	0x0091
                    0092     90 Fshiftbrite$DPS$0$0 == 0x0092
                    0092     91 _DPS	=	0x0092
                    0093     92 Fshiftbrite$MPAGE$0$0 == 0x0093
                    0093     93 _MPAGE	=	0x0093
                    0095     94 Fshiftbrite$ENDIAN$0$0 == 0x0095
                    0095     95 _ENDIAN	=	0x0095
                    0098     96 Fshiftbrite$S0CON$0$0 == 0x0098
                    0098     97 _S0CON	=	0x0098
                    009A     98 Fshiftbrite$IEN2$0$0 == 0x009a
                    009A     99 _IEN2	=	0x009a
                    009B    100 Fshiftbrite$S1CON$0$0 == 0x009b
                    009B    101 _S1CON	=	0x009b
                    009C    102 Fshiftbrite$T2CT$0$0 == 0x009c
                    009C    103 _T2CT	=	0x009c
                    009D    104 Fshiftbrite$T2PR$0$0 == 0x009d
                    009D    105 _T2PR	=	0x009d
                    009E    106 Fshiftbrite$T2CTL$0$0 == 0x009e
                    009E    107 _T2CTL	=	0x009e
                    00A0    108 Fshiftbrite$P2$0$0 == 0x00a0
                    00A0    109 _P2	=	0x00a0
                    00A1    110 Fshiftbrite$WORIRQ$0$0 == 0x00a1
                    00A1    111 _WORIRQ	=	0x00a1
                    00A2    112 Fshiftbrite$WORCTRL$0$0 == 0x00a2
                    00A2    113 _WORCTRL	=	0x00a2
                    00A3    114 Fshiftbrite$WOREVT0$0$0 == 0x00a3
                    00A3    115 _WOREVT0	=	0x00a3
                    00A4    116 Fshiftbrite$WOREVT1$0$0 == 0x00a4
                    00A4    117 _WOREVT1	=	0x00a4
                    00A5    118 Fshiftbrite$WORTIME0$0$0 == 0x00a5
                    00A5    119 _WORTIME0	=	0x00a5
                    00A6    120 Fshiftbrite$WORTIME1$0$0 == 0x00a6
                    00A6    121 _WORTIME1	=	0x00a6
                    00A8    122 Fshiftbrite$IEN0$0$0 == 0x00a8
                    00A8    123 _IEN0	=	0x00a8
                    00A9    124 Fshiftbrite$IP0$0$0 == 0x00a9
                    00A9    125 _IP0	=	0x00a9
                    00AB    126 Fshiftbrite$FWT$0$0 == 0x00ab
                    00AB    127 _FWT	=	0x00ab
                    00AC    128 Fshiftbrite$FADDRL$0$0 == 0x00ac
                    00AC    129 _FADDRL	=	0x00ac
                    00AD    130 Fshiftbrite$FADDRH$0$0 == 0x00ad
                    00AD    131 _FADDRH	=	0x00ad
                    00AE    132 Fshiftbrite$FCTL$0$0 == 0x00ae
                    00AE    133 _FCTL	=	0x00ae
                    00AF    134 Fshiftbrite$FWDATA$0$0 == 0x00af
                    00AF    135 _FWDATA	=	0x00af
                    00B1    136 Fshiftbrite$ENCDI$0$0 == 0x00b1
                    00B1    137 _ENCDI	=	0x00b1
                    00B2    138 Fshiftbrite$ENCDO$0$0 == 0x00b2
                    00B2    139 _ENCDO	=	0x00b2
                    00B3    140 Fshiftbrite$ENCCS$0$0 == 0x00b3
                    00B3    141 _ENCCS	=	0x00b3
                    00B4    142 Fshiftbrite$ADCCON1$0$0 == 0x00b4
                    00B4    143 _ADCCON1	=	0x00b4
                    00B5    144 Fshiftbrite$ADCCON2$0$0 == 0x00b5
                    00B5    145 _ADCCON2	=	0x00b5
                    00B6    146 Fshiftbrite$ADCCON3$0$0 == 0x00b6
                    00B6    147 _ADCCON3	=	0x00b6
                    00B8    148 Fshiftbrite$IEN1$0$0 == 0x00b8
                    00B8    149 _IEN1	=	0x00b8
                    00B9    150 Fshiftbrite$IP1$0$0 == 0x00b9
                    00B9    151 _IP1	=	0x00b9
                    00BA    152 Fshiftbrite$ADCL$0$0 == 0x00ba
                    00BA    153 _ADCL	=	0x00ba
                    00BB    154 Fshiftbrite$ADCH$0$0 == 0x00bb
                    00BB    155 _ADCH	=	0x00bb
                    00BC    156 Fshiftbrite$RNDL$0$0 == 0x00bc
                    00BC    157 _RNDL	=	0x00bc
                    00BD    158 Fshiftbrite$RNDH$0$0 == 0x00bd
                    00BD    159 _RNDH	=	0x00bd
                    00BE    160 Fshiftbrite$SLEEP$0$0 == 0x00be
                    00BE    161 _SLEEP	=	0x00be
                    00C0    162 Fshiftbrite$IRCON$0$0 == 0x00c0
                    00C0    163 _IRCON	=	0x00c0
                    00C1    164 Fshiftbrite$U0DBUF$0$0 == 0x00c1
                    00C1    165 _U0DBUF	=	0x00c1
                    00C2    166 Fshiftbrite$U0BAUD$0$0 == 0x00c2
                    00C2    167 _U0BAUD	=	0x00c2
                    00C4    168 Fshiftbrite$U0UCR$0$0 == 0x00c4
                    00C4    169 _U0UCR	=	0x00c4
                    00C5    170 Fshiftbrite$U0GCR$0$0 == 0x00c5
                    00C5    171 _U0GCR	=	0x00c5
                    00C6    172 Fshiftbrite$CLKCON$0$0 == 0x00c6
                    00C6    173 _CLKCON	=	0x00c6
                    00C7    174 Fshiftbrite$MEMCTR$0$0 == 0x00c7
                    00C7    175 _MEMCTR	=	0x00c7
                    00C9    176 Fshiftbrite$WDCTL$0$0 == 0x00c9
                    00C9    177 _WDCTL	=	0x00c9
                    00CA    178 Fshiftbrite$T3CNT$0$0 == 0x00ca
                    00CA    179 _T3CNT	=	0x00ca
                    00CB    180 Fshiftbrite$T3CTL$0$0 == 0x00cb
                    00CB    181 _T3CTL	=	0x00cb
                    00CC    182 Fshiftbrite$T3CCTL0$0$0 == 0x00cc
                    00CC    183 _T3CCTL0	=	0x00cc
                    00CD    184 Fshiftbrite$T3CC0$0$0 == 0x00cd
                    00CD    185 _T3CC0	=	0x00cd
                    00CE    186 Fshiftbrite$T3CCTL1$0$0 == 0x00ce
                    00CE    187 _T3CCTL1	=	0x00ce
                    00CF    188 Fshiftbrite$T3CC1$0$0 == 0x00cf
                    00CF    189 _T3CC1	=	0x00cf
                    00D0    190 Fshiftbrite$PSW$0$0 == 0x00d0
                    00D0    191 _PSW	=	0x00d0
                    00D1    192 Fshiftbrite$DMAIRQ$0$0 == 0x00d1
                    00D1    193 _DMAIRQ	=	0x00d1
                    00D2    194 Fshiftbrite$DMA1CFGL$0$0 == 0x00d2
                    00D2    195 _DMA1CFGL	=	0x00d2
                    00D3    196 Fshiftbrite$DMA1CFGH$0$0 == 0x00d3
                    00D3    197 _DMA1CFGH	=	0x00d3
                    00D4    198 Fshiftbrite$DMA0CFGL$0$0 == 0x00d4
                    00D4    199 _DMA0CFGL	=	0x00d4
                    00D5    200 Fshiftbrite$DMA0CFGH$0$0 == 0x00d5
                    00D5    201 _DMA0CFGH	=	0x00d5
                    00D6    202 Fshiftbrite$DMAARM$0$0 == 0x00d6
                    00D6    203 _DMAARM	=	0x00d6
                    00D7    204 Fshiftbrite$DMAREQ$0$0 == 0x00d7
                    00D7    205 _DMAREQ	=	0x00d7
                    00D8    206 Fshiftbrite$TIMIF$0$0 == 0x00d8
                    00D8    207 _TIMIF	=	0x00d8
                    00D9    208 Fshiftbrite$RFD$0$0 == 0x00d9
                    00D9    209 _RFD	=	0x00d9
                    00DA    210 Fshiftbrite$T1CC0L$0$0 == 0x00da
                    00DA    211 _T1CC0L	=	0x00da
                    00DB    212 Fshiftbrite$T1CC0H$0$0 == 0x00db
                    00DB    213 _T1CC0H	=	0x00db
                    00DC    214 Fshiftbrite$T1CC1L$0$0 == 0x00dc
                    00DC    215 _T1CC1L	=	0x00dc
                    00DD    216 Fshiftbrite$T1CC1H$0$0 == 0x00dd
                    00DD    217 _T1CC1H	=	0x00dd
                    00DE    218 Fshiftbrite$T1CC2L$0$0 == 0x00de
                    00DE    219 _T1CC2L	=	0x00de
                    00DF    220 Fshiftbrite$T1CC2H$0$0 == 0x00df
                    00DF    221 _T1CC2H	=	0x00df
                    00E0    222 Fshiftbrite$ACC$0$0 == 0x00e0
                    00E0    223 _ACC	=	0x00e0
                    00E1    224 Fshiftbrite$RFST$0$0 == 0x00e1
                    00E1    225 _RFST	=	0x00e1
                    00E2    226 Fshiftbrite$T1CNTL$0$0 == 0x00e2
                    00E2    227 _T1CNTL	=	0x00e2
                    00E3    228 Fshiftbrite$T1CNTH$0$0 == 0x00e3
                    00E3    229 _T1CNTH	=	0x00e3
                    00E4    230 Fshiftbrite$T1CTL$0$0 == 0x00e4
                    00E4    231 _T1CTL	=	0x00e4
                    00E5    232 Fshiftbrite$T1CCTL0$0$0 == 0x00e5
                    00E5    233 _T1CCTL0	=	0x00e5
                    00E6    234 Fshiftbrite$T1CCTL1$0$0 == 0x00e6
                    00E6    235 _T1CCTL1	=	0x00e6
                    00E7    236 Fshiftbrite$T1CCTL2$0$0 == 0x00e7
                    00E7    237 _T1CCTL2	=	0x00e7
                    00E8    238 Fshiftbrite$IRCON2$0$0 == 0x00e8
                    00E8    239 _IRCON2	=	0x00e8
                    00E9    240 Fshiftbrite$RFIF$0$0 == 0x00e9
                    00E9    241 _RFIF	=	0x00e9
                    00EA    242 Fshiftbrite$T4CNT$0$0 == 0x00ea
                    00EA    243 _T4CNT	=	0x00ea
                    00EB    244 Fshiftbrite$T4CTL$0$0 == 0x00eb
                    00EB    245 _T4CTL	=	0x00eb
                    00EC    246 Fshiftbrite$T4CCTL0$0$0 == 0x00ec
                    00EC    247 _T4CCTL0	=	0x00ec
                    00ED    248 Fshiftbrite$T4CC0$0$0 == 0x00ed
                    00ED    249 _T4CC0	=	0x00ed
                    00EE    250 Fshiftbrite$T4CCTL1$0$0 == 0x00ee
                    00EE    251 _T4CCTL1	=	0x00ee
                    00EF    252 Fshiftbrite$T4CC1$0$0 == 0x00ef
                    00EF    253 _T4CC1	=	0x00ef
                    00F0    254 Fshiftbrite$B$0$0 == 0x00f0
                    00F0    255 _B	=	0x00f0
                    00F1    256 Fshiftbrite$PERCFG$0$0 == 0x00f1
                    00F1    257 _PERCFG	=	0x00f1
                    00F2    258 Fshiftbrite$ADCCFG$0$0 == 0x00f2
                    00F2    259 _ADCCFG	=	0x00f2
                    00F3    260 Fshiftbrite$P0SEL$0$0 == 0x00f3
                    00F3    261 _P0SEL	=	0x00f3
                    00F4    262 Fshiftbrite$P1SEL$0$0 == 0x00f4
                    00F4    263 _P1SEL	=	0x00f4
                    00F5    264 Fshiftbrite$P2SEL$0$0 == 0x00f5
                    00F5    265 _P2SEL	=	0x00f5
                    00F6    266 Fshiftbrite$P1INP$0$0 == 0x00f6
                    00F6    267 _P1INP	=	0x00f6
                    00F7    268 Fshiftbrite$P2INP$0$0 == 0x00f7
                    00F7    269 _P2INP	=	0x00f7
                    00F8    270 Fshiftbrite$U1CSR$0$0 == 0x00f8
                    00F8    271 _U1CSR	=	0x00f8
                    00F9    272 Fshiftbrite$U1DBUF$0$0 == 0x00f9
                    00F9    273 _U1DBUF	=	0x00f9
                    00FA    274 Fshiftbrite$U1BAUD$0$0 == 0x00fa
                    00FA    275 _U1BAUD	=	0x00fa
                    00FB    276 Fshiftbrite$U1UCR$0$0 == 0x00fb
                    00FB    277 _U1UCR	=	0x00fb
                    00FC    278 Fshiftbrite$U1GCR$0$0 == 0x00fc
                    00FC    279 _U1GCR	=	0x00fc
                    00FD    280 Fshiftbrite$P0DIR$0$0 == 0x00fd
                    00FD    281 _P0DIR	=	0x00fd
                    00FE    282 Fshiftbrite$P1DIR$0$0 == 0x00fe
                    00FE    283 _P1DIR	=	0x00fe
                    00FF    284 Fshiftbrite$P2DIR$0$0 == 0x00ff
                    00FF    285 _P2DIR	=	0x00ff
                    FFFFD5D4    286 Fshiftbrite$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    287 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    288 Fshiftbrite$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    289 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    290 Fshiftbrite$FADDR$0$0 == 0xffffadac
                    FFFFADAC    291 _FADDR	=	0xffffadac
                    FFFFBBBA    292 Fshiftbrite$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    293 _ADC	=	0xffffbbba
                    FFFFDBDA    294 Fshiftbrite$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    295 _T1CC0	=	0xffffdbda
                    FFFFDDDC    296 Fshiftbrite$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    297 _T1CC1	=	0xffffdddc
                    FFFFDFDE    298 Fshiftbrite$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    299 _T1CC2	=	0xffffdfde
                            300 ;--------------------------------------------------------
                            301 ; special function bits
                            302 ;--------------------------------------------------------
                            303 	.area RSEG    (ABS,DATA)
   0000                     304 	.org 0x0000
                    0080    305 Fshiftbrite$P0_0$0$0 == 0x0080
                    0080    306 _P0_0	=	0x0080
                    0081    307 Fshiftbrite$P0_1$0$0 == 0x0081
                    0081    308 _P0_1	=	0x0081
                    0082    309 Fshiftbrite$P0_2$0$0 == 0x0082
                    0082    310 _P0_2	=	0x0082
                    0083    311 Fshiftbrite$P0_3$0$0 == 0x0083
                    0083    312 _P0_3	=	0x0083
                    0084    313 Fshiftbrite$P0_4$0$0 == 0x0084
                    0084    314 _P0_4	=	0x0084
                    0085    315 Fshiftbrite$P0_5$0$0 == 0x0085
                    0085    316 _P0_5	=	0x0085
                    0086    317 Fshiftbrite$P0_6$0$0 == 0x0086
                    0086    318 _P0_6	=	0x0086
                    0087    319 Fshiftbrite$P0_7$0$0 == 0x0087
                    0087    320 _P0_7	=	0x0087
                    0088    321 Fshiftbrite$_TCON_0$0$0 == 0x0088
                    0088    322 __TCON_0	=	0x0088
                    0089    323 Fshiftbrite$RFTXRXIF$0$0 == 0x0089
                    0089    324 _RFTXRXIF	=	0x0089
                    008A    325 Fshiftbrite$_TCON_2$0$0 == 0x008a
                    008A    326 __TCON_2	=	0x008a
                    008B    327 Fshiftbrite$URX0IF$0$0 == 0x008b
                    008B    328 _URX0IF	=	0x008b
                    008C    329 Fshiftbrite$_TCON_4$0$0 == 0x008c
                    008C    330 __TCON_4	=	0x008c
                    008D    331 Fshiftbrite$ADCIF$0$0 == 0x008d
                    008D    332 _ADCIF	=	0x008d
                    008E    333 Fshiftbrite$_TCON_6$0$0 == 0x008e
                    008E    334 __TCON_6	=	0x008e
                    008F    335 Fshiftbrite$URX1IF$0$0 == 0x008f
                    008F    336 _URX1IF	=	0x008f
                    0090    337 Fshiftbrite$P1_0$0$0 == 0x0090
                    0090    338 _P1_0	=	0x0090
                    0091    339 Fshiftbrite$P1_1$0$0 == 0x0091
                    0091    340 _P1_1	=	0x0091
                    0092    341 Fshiftbrite$P1_2$0$0 == 0x0092
                    0092    342 _P1_2	=	0x0092
                    0093    343 Fshiftbrite$P1_3$0$0 == 0x0093
                    0093    344 _P1_3	=	0x0093
                    0094    345 Fshiftbrite$P1_4$0$0 == 0x0094
                    0094    346 _P1_4	=	0x0094
                    0095    347 Fshiftbrite$P1_5$0$0 == 0x0095
                    0095    348 _P1_5	=	0x0095
                    0096    349 Fshiftbrite$P1_6$0$0 == 0x0096
                    0096    350 _P1_6	=	0x0096
                    0097    351 Fshiftbrite$P1_7$0$0 == 0x0097
                    0097    352 _P1_7	=	0x0097
                    0098    353 Fshiftbrite$ENCIF_0$0$0 == 0x0098
                    0098    354 _ENCIF_0	=	0x0098
                    0099    355 Fshiftbrite$ENCIF_1$0$0 == 0x0099
                    0099    356 _ENCIF_1	=	0x0099
                    009A    357 Fshiftbrite$_SOCON2$0$0 == 0x009a
                    009A    358 __SOCON2	=	0x009a
                    009B    359 Fshiftbrite$_SOCON3$0$0 == 0x009b
                    009B    360 __SOCON3	=	0x009b
                    009C    361 Fshiftbrite$_SOCON4$0$0 == 0x009c
                    009C    362 __SOCON4	=	0x009c
                    009D    363 Fshiftbrite$_SOCON5$0$0 == 0x009d
                    009D    364 __SOCON5	=	0x009d
                    009E    365 Fshiftbrite$_SOCON6$0$0 == 0x009e
                    009E    366 __SOCON6	=	0x009e
                    009F    367 Fshiftbrite$_SOCON7$0$0 == 0x009f
                    009F    368 __SOCON7	=	0x009f
                    00A0    369 Fshiftbrite$P2_0$0$0 == 0x00a0
                    00A0    370 _P2_0	=	0x00a0
                    00A1    371 Fshiftbrite$P2_1$0$0 == 0x00a1
                    00A1    372 _P2_1	=	0x00a1
                    00A2    373 Fshiftbrite$P2_2$0$0 == 0x00a2
                    00A2    374 _P2_2	=	0x00a2
                    00A3    375 Fshiftbrite$P2_3$0$0 == 0x00a3
                    00A3    376 _P2_3	=	0x00a3
                    00A4    377 Fshiftbrite$P2_4$0$0 == 0x00a4
                    00A4    378 _P2_4	=	0x00a4
                    00A5    379 Fshiftbrite$P2_5$0$0 == 0x00a5
                    00A5    380 _P2_5	=	0x00a5
                    00A6    381 Fshiftbrite$P2_6$0$0 == 0x00a6
                    00A6    382 _P2_6	=	0x00a6
                    00A7    383 Fshiftbrite$P2_7$0$0 == 0x00a7
                    00A7    384 _P2_7	=	0x00a7
                    00A8    385 Fshiftbrite$RFTXRXIE$0$0 == 0x00a8
                    00A8    386 _RFTXRXIE	=	0x00a8
                    00A9    387 Fshiftbrite$ADCIE$0$0 == 0x00a9
                    00A9    388 _ADCIE	=	0x00a9
                    00AA    389 Fshiftbrite$URX0IE$0$0 == 0x00aa
                    00AA    390 _URX0IE	=	0x00aa
                    00AB    391 Fshiftbrite$URX1IE$0$0 == 0x00ab
                    00AB    392 _URX1IE	=	0x00ab
                    00AC    393 Fshiftbrite$ENCIE$0$0 == 0x00ac
                    00AC    394 _ENCIE	=	0x00ac
                    00AD    395 Fshiftbrite$STIE$0$0 == 0x00ad
                    00AD    396 _STIE	=	0x00ad
                    00AE    397 Fshiftbrite$_IEN06$0$0 == 0x00ae
                    00AE    398 __IEN06	=	0x00ae
                    00AF    399 Fshiftbrite$EA$0$0 == 0x00af
                    00AF    400 _EA	=	0x00af
                    00B8    401 Fshiftbrite$DMAIE$0$0 == 0x00b8
                    00B8    402 _DMAIE	=	0x00b8
                    00B9    403 Fshiftbrite$T1IE$0$0 == 0x00b9
                    00B9    404 _T1IE	=	0x00b9
                    00BA    405 Fshiftbrite$T2IE$0$0 == 0x00ba
                    00BA    406 _T2IE	=	0x00ba
                    00BB    407 Fshiftbrite$T3IE$0$0 == 0x00bb
                    00BB    408 _T3IE	=	0x00bb
                    00BC    409 Fshiftbrite$T4IE$0$0 == 0x00bc
                    00BC    410 _T4IE	=	0x00bc
                    00BD    411 Fshiftbrite$P0IE$0$0 == 0x00bd
                    00BD    412 _P0IE	=	0x00bd
                    00BE    413 Fshiftbrite$_IEN16$0$0 == 0x00be
                    00BE    414 __IEN16	=	0x00be
                    00BF    415 Fshiftbrite$_IEN17$0$0 == 0x00bf
                    00BF    416 __IEN17	=	0x00bf
                    00C0    417 Fshiftbrite$DMAIF$0$0 == 0x00c0
                    00C0    418 _DMAIF	=	0x00c0
                    00C1    419 Fshiftbrite$T1IF$0$0 == 0x00c1
                    00C1    420 _T1IF	=	0x00c1
                    00C2    421 Fshiftbrite$T2IF$0$0 == 0x00c2
                    00C2    422 _T2IF	=	0x00c2
                    00C3    423 Fshiftbrite$T3IF$0$0 == 0x00c3
                    00C3    424 _T3IF	=	0x00c3
                    00C4    425 Fshiftbrite$T4IF$0$0 == 0x00c4
                    00C4    426 _T4IF	=	0x00c4
                    00C5    427 Fshiftbrite$P0IF$0$0 == 0x00c5
                    00C5    428 _P0IF	=	0x00c5
                    00C6    429 Fshiftbrite$_IRCON6$0$0 == 0x00c6
                    00C6    430 __IRCON6	=	0x00c6
                    00C7    431 Fshiftbrite$STIF$0$0 == 0x00c7
                    00C7    432 _STIF	=	0x00c7
                    00D0    433 Fshiftbrite$P$0$0 == 0x00d0
                    00D0    434 _P	=	0x00d0
                    00D1    435 Fshiftbrite$F1$0$0 == 0x00d1
                    00D1    436 _F1	=	0x00d1
                    00D2    437 Fshiftbrite$OV$0$0 == 0x00d2
                    00D2    438 _OV	=	0x00d2
                    00D3    439 Fshiftbrite$RS0$0$0 == 0x00d3
                    00D3    440 _RS0	=	0x00d3
                    00D4    441 Fshiftbrite$RS1$0$0 == 0x00d4
                    00D4    442 _RS1	=	0x00d4
                    00D5    443 Fshiftbrite$F0$0$0 == 0x00d5
                    00D5    444 _F0	=	0x00d5
                    00D6    445 Fshiftbrite$AC$0$0 == 0x00d6
                    00D6    446 _AC	=	0x00d6
                    00D7    447 Fshiftbrite$CY$0$0 == 0x00d7
                    00D7    448 _CY	=	0x00d7
                    00D8    449 Fshiftbrite$T3OVFIF$0$0 == 0x00d8
                    00D8    450 _T3OVFIF	=	0x00d8
                    00D9    451 Fshiftbrite$T3CH0IF$0$0 == 0x00d9
                    00D9    452 _T3CH0IF	=	0x00d9
                    00DA    453 Fshiftbrite$T3CH1IF$0$0 == 0x00da
                    00DA    454 _T3CH1IF	=	0x00da
                    00DB    455 Fshiftbrite$T4OVFIF$0$0 == 0x00db
                    00DB    456 _T4OVFIF	=	0x00db
                    00DC    457 Fshiftbrite$T4CH0IF$0$0 == 0x00dc
                    00DC    458 _T4CH0IF	=	0x00dc
                    00DD    459 Fshiftbrite$T4CH1IF$0$0 == 0x00dd
                    00DD    460 _T4CH1IF	=	0x00dd
                    00DE    461 Fshiftbrite$OVFIM$0$0 == 0x00de
                    00DE    462 _OVFIM	=	0x00de
                    00DF    463 Fshiftbrite$_TIMIF7$0$0 == 0x00df
                    00DF    464 __TIMIF7	=	0x00df
                    00E0    465 Fshiftbrite$ACC_0$0$0 == 0x00e0
                    00E0    466 _ACC_0	=	0x00e0
                    00E1    467 Fshiftbrite$ACC_1$0$0 == 0x00e1
                    00E1    468 _ACC_1	=	0x00e1
                    00E2    469 Fshiftbrite$ACC_2$0$0 == 0x00e2
                    00E2    470 _ACC_2	=	0x00e2
                    00E3    471 Fshiftbrite$ACC_3$0$0 == 0x00e3
                    00E3    472 _ACC_3	=	0x00e3
                    00E4    473 Fshiftbrite$ACC_4$0$0 == 0x00e4
                    00E4    474 _ACC_4	=	0x00e4
                    00E5    475 Fshiftbrite$ACC_5$0$0 == 0x00e5
                    00E5    476 _ACC_5	=	0x00e5
                    00E6    477 Fshiftbrite$ACC_6$0$0 == 0x00e6
                    00E6    478 _ACC_6	=	0x00e6
                    00E7    479 Fshiftbrite$ACC_7$0$0 == 0x00e7
                    00E7    480 _ACC_7	=	0x00e7
                    00E8    481 Fshiftbrite$P2IF$0$0 == 0x00e8
                    00E8    482 _P2IF	=	0x00e8
                    00E9    483 Fshiftbrite$UTX0IF$0$0 == 0x00e9
                    00E9    484 _UTX0IF	=	0x00e9
                    00EA    485 Fshiftbrite$UTX1IF$0$0 == 0x00ea
                    00EA    486 _UTX1IF	=	0x00ea
                    00EB    487 Fshiftbrite$P1IF$0$0 == 0x00eb
                    00EB    488 _P1IF	=	0x00eb
                    00EC    489 Fshiftbrite$WDTIF$0$0 == 0x00ec
                    00EC    490 _WDTIF	=	0x00ec
                    00ED    491 Fshiftbrite$_IRCON25$0$0 == 0x00ed
                    00ED    492 __IRCON25	=	0x00ed
                    00EE    493 Fshiftbrite$_IRCON26$0$0 == 0x00ee
                    00EE    494 __IRCON26	=	0x00ee
                    00EF    495 Fshiftbrite$_IRCON27$0$0 == 0x00ef
                    00EF    496 __IRCON27	=	0x00ef
                    00F0    497 Fshiftbrite$B_0$0$0 == 0x00f0
                    00F0    498 _B_0	=	0x00f0
                    00F1    499 Fshiftbrite$B_1$0$0 == 0x00f1
                    00F1    500 _B_1	=	0x00f1
                    00F2    501 Fshiftbrite$B_2$0$0 == 0x00f2
                    00F2    502 _B_2	=	0x00f2
                    00F3    503 Fshiftbrite$B_3$0$0 == 0x00f3
                    00F3    504 _B_3	=	0x00f3
                    00F4    505 Fshiftbrite$B_4$0$0 == 0x00f4
                    00F4    506 _B_4	=	0x00f4
                    00F5    507 Fshiftbrite$B_5$0$0 == 0x00f5
                    00F5    508 _B_5	=	0x00f5
                    00F6    509 Fshiftbrite$B_6$0$0 == 0x00f6
                    00F6    510 _B_6	=	0x00f6
                    00F7    511 Fshiftbrite$B_7$0$0 == 0x00f7
                    00F7    512 _B_7	=	0x00f7
                    00F8    513 Fshiftbrite$U1ACTIVE$0$0 == 0x00f8
                    00F8    514 _U1ACTIVE	=	0x00f8
                    00F9    515 Fshiftbrite$U1TX_BYTE$0$0 == 0x00f9
                    00F9    516 _U1TX_BYTE	=	0x00f9
                    00FA    517 Fshiftbrite$U1RX_BYTE$0$0 == 0x00fa
                    00FA    518 _U1RX_BYTE	=	0x00fa
                    00FB    519 Fshiftbrite$U1ERR$0$0 == 0x00fb
                    00FB    520 _U1ERR	=	0x00fb
                    00FC    521 Fshiftbrite$U1FE$0$0 == 0x00fc
                    00FC    522 _U1FE	=	0x00fc
                    00FD    523 Fshiftbrite$U1SLAVE$0$0 == 0x00fd
                    00FD    524 _U1SLAVE	=	0x00fd
                    00FE    525 Fshiftbrite$U1RE$0$0 == 0x00fe
                    00FE    526 _U1RE	=	0x00fe
                    00FF    527 Fshiftbrite$U1MODE$0$0 == 0x00ff
                    00FF    528 _U1MODE	=	0x00ff
                            529 ;--------------------------------------------------------
                            530 ; overlayable register banks
                            531 ;--------------------------------------------------------
                            532 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     533 	.ds 8
                            534 ;--------------------------------------------------------
                            535 ; internal ram data
                            536 ;--------------------------------------------------------
                            537 	.area DSEG    (DATA)
                    0000    538 Lshiftbrite.shiftbriteProcessByte$sloc0$1$0==.
   0008                     539 _shiftbriteProcessByte_sloc0_1_0:
   0008                     540 	.ds 2
                            541 ;--------------------------------------------------------
                            542 ; overlayable items in internal ram 
                            543 ;--------------------------------------------------------
                            544 	.area OSEG    (OVR,DATA)
                            545 ;--------------------------------------------------------
                            546 ; Stack segment in internal ram 
                            547 ;--------------------------------------------------------
                            548 	.area	SSEG	(DATA)
   0024                     549 __start__stack:
   0024                     550 	.ds	1
                            551 
                            552 ;--------------------------------------------------------
                            553 ; indirectly addressable internal ram data
                            554 ;--------------------------------------------------------
                            555 	.area ISEG    (DATA)
                            556 ;--------------------------------------------------------
                            557 ; absolute internal ram data
                            558 ;--------------------------------------------------------
                            559 	.area IABS    (ABS,DATA)
                            560 	.area IABS    (ABS,DATA)
                            561 ;--------------------------------------------------------
                            562 ; bit data
                            563 ;--------------------------------------------------------
                            564 	.area BSEG    (BIT)
                    0000    565 G$radioBlinkActive$0$0==.
   0000                     566 _radioBlinkActive::
   0000                     567 	.ds 1
                    0001    568 Lshiftbrite.sendBit$value$1$1==.
   0001                     569 _sendBit_PARM_1:
   0001                     570 	.ds 1
                            571 ;--------------------------------------------------------
                            572 ; paged external ram data
                            573 ;--------------------------------------------------------
                            574 	.area PSEG    (PAG,XDATA)
                    0000    575 G$lastSend$0$0==.
   F000                     576 _lastSend::
   F000                     577 	.ds 4
                    0004    578 G$radioLastActivity$0$0==.
   F004                     579 _radioLastActivity::
   F004                     580 	.ds 1
                    0005    581 G$radioBlinkStart$0$0==.
   F005                     582 _radioBlinkStart::
   F005                     583 	.ds 1
                    0006    584 G$input_bits$0$0==.
   F006                     585 _input_bits::
   F006                     586 	.ds 1
                    0007    587 G$hex_chars_per_color$0$0==.
   F007                     588 _hex_chars_per_color::
   F007                     589 	.ds 1
                    0008    590 G$shift$0$0==.
   F008                     591 _shift::
   F008                     592 	.ds 1
                    0009    593 Lshiftbrite.hex$len$1$1==.
   F009                     594 _hex_PARM_2:
   F009                     595 	.ds 1
                    000A    596 Lshiftbrite.hex$s$1$1==.
   F00A                     597 _hex_s_1_1:
   F00A                     598 	.ds 3
                    000D    599 Lshiftbrite.sendRGB$g$1$1==.
   F00D                     600 _sendRGB_PARM_2:
   F00D                     601 	.ds 2
                    000F    602 Lshiftbrite.sendRGB$b$1$1==.
   F00F                     603 _sendRGB_PARM_3:
   F00F                     604 	.ds 2
                    0011    605 Lshiftbrite.restrictRange$min$1$1==.
   F011                     606 _restrictRange_PARM_2:
   F011                     607 	.ds 4
                    0015    608 Lshiftbrite.restrictRange$max$1$1==.
   F015                     609 _restrictRange_PARM_3:
   F015                     610 	.ds 4
                    0019    611 Lshiftbrite.shiftbriteProcessByte$rgb$1$1==.
   F019                     612 _shiftbriteProcessByte_rgb_1_1:
   F019                     613 	.ds 12
                    0025    614 Lshiftbrite.shiftbriteProcessByte$i$1$1==.
   F025                     615 _shiftbriteProcessByte_i_1_1:
   F025                     616 	.ds 1
                            617 ;--------------------------------------------------------
                            618 ; external ram data
                            619 ;--------------------------------------------------------
                            620 	.area XSEG    (XDATA)
                    DF00    621 Fshiftbrite$SYNC1$0$0 == 0xdf00
                    DF00    622 _SYNC1	=	0xdf00
                    DF01    623 Fshiftbrite$SYNC0$0$0 == 0xdf01
                    DF01    624 _SYNC0	=	0xdf01
                    DF02    625 Fshiftbrite$PKTLEN$0$0 == 0xdf02
                    DF02    626 _PKTLEN	=	0xdf02
                    DF03    627 Fshiftbrite$PKTCTRL1$0$0 == 0xdf03
                    DF03    628 _PKTCTRL1	=	0xdf03
                    DF04    629 Fshiftbrite$PKTCTRL0$0$0 == 0xdf04
                    DF04    630 _PKTCTRL0	=	0xdf04
                    DF05    631 Fshiftbrite$ADDR$0$0 == 0xdf05
                    DF05    632 _ADDR	=	0xdf05
                    DF06    633 Fshiftbrite$CHANNR$0$0 == 0xdf06
                    DF06    634 _CHANNR	=	0xdf06
                    DF07    635 Fshiftbrite$FSCTRL1$0$0 == 0xdf07
                    DF07    636 _FSCTRL1	=	0xdf07
                    DF08    637 Fshiftbrite$FSCTRL0$0$0 == 0xdf08
                    DF08    638 _FSCTRL0	=	0xdf08
                    DF09    639 Fshiftbrite$FREQ2$0$0 == 0xdf09
                    DF09    640 _FREQ2	=	0xdf09
                    DF0A    641 Fshiftbrite$FREQ1$0$0 == 0xdf0a
                    DF0A    642 _FREQ1	=	0xdf0a
                    DF0B    643 Fshiftbrite$FREQ0$0$0 == 0xdf0b
                    DF0B    644 _FREQ0	=	0xdf0b
                    DF0C    645 Fshiftbrite$MDMCFG4$0$0 == 0xdf0c
                    DF0C    646 _MDMCFG4	=	0xdf0c
                    DF0D    647 Fshiftbrite$MDMCFG3$0$0 == 0xdf0d
                    DF0D    648 _MDMCFG3	=	0xdf0d
                    DF0E    649 Fshiftbrite$MDMCFG2$0$0 == 0xdf0e
                    DF0E    650 _MDMCFG2	=	0xdf0e
                    DF0F    651 Fshiftbrite$MDMCFG1$0$0 == 0xdf0f
                    DF0F    652 _MDMCFG1	=	0xdf0f
                    DF10    653 Fshiftbrite$MDMCFG0$0$0 == 0xdf10
                    DF10    654 _MDMCFG0	=	0xdf10
                    DF11    655 Fshiftbrite$DEVIATN$0$0 == 0xdf11
                    DF11    656 _DEVIATN	=	0xdf11
                    DF12    657 Fshiftbrite$MCSM2$0$0 == 0xdf12
                    DF12    658 _MCSM2	=	0xdf12
                    DF13    659 Fshiftbrite$MCSM1$0$0 == 0xdf13
                    DF13    660 _MCSM1	=	0xdf13
                    DF14    661 Fshiftbrite$MCSM0$0$0 == 0xdf14
                    DF14    662 _MCSM0	=	0xdf14
                    DF15    663 Fshiftbrite$FOCCFG$0$0 == 0xdf15
                    DF15    664 _FOCCFG	=	0xdf15
                    DF16    665 Fshiftbrite$BSCFG$0$0 == 0xdf16
                    DF16    666 _BSCFG	=	0xdf16
                    DF17    667 Fshiftbrite$AGCCTRL2$0$0 == 0xdf17
                    DF17    668 _AGCCTRL2	=	0xdf17
                    DF18    669 Fshiftbrite$AGCCTRL1$0$0 == 0xdf18
                    DF18    670 _AGCCTRL1	=	0xdf18
                    DF19    671 Fshiftbrite$AGCCTRL0$0$0 == 0xdf19
                    DF19    672 _AGCCTRL0	=	0xdf19
                    DF1A    673 Fshiftbrite$FREND1$0$0 == 0xdf1a
                    DF1A    674 _FREND1	=	0xdf1a
                    DF1B    675 Fshiftbrite$FREND0$0$0 == 0xdf1b
                    DF1B    676 _FREND0	=	0xdf1b
                    DF1C    677 Fshiftbrite$FSCAL3$0$0 == 0xdf1c
                    DF1C    678 _FSCAL3	=	0xdf1c
                    DF1D    679 Fshiftbrite$FSCAL2$0$0 == 0xdf1d
                    DF1D    680 _FSCAL2	=	0xdf1d
                    DF1E    681 Fshiftbrite$FSCAL1$0$0 == 0xdf1e
                    DF1E    682 _FSCAL1	=	0xdf1e
                    DF1F    683 Fshiftbrite$FSCAL0$0$0 == 0xdf1f
                    DF1F    684 _FSCAL0	=	0xdf1f
                    DF23    685 Fshiftbrite$TEST2$0$0 == 0xdf23
                    DF23    686 _TEST2	=	0xdf23
                    DF24    687 Fshiftbrite$TEST1$0$0 == 0xdf24
                    DF24    688 _TEST1	=	0xdf24
                    DF25    689 Fshiftbrite$TEST0$0$0 == 0xdf25
                    DF25    690 _TEST0	=	0xdf25
                    DF2E    691 Fshiftbrite$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    692 _PA_TABLE0	=	0xdf2e
                    DF2F    693 Fshiftbrite$IOCFG2$0$0 == 0xdf2f
                    DF2F    694 _IOCFG2	=	0xdf2f
                    DF30    695 Fshiftbrite$IOCFG1$0$0 == 0xdf30
                    DF30    696 _IOCFG1	=	0xdf30
                    DF31    697 Fshiftbrite$IOCFG0$0$0 == 0xdf31
                    DF31    698 _IOCFG0	=	0xdf31
                    DF36    699 Fshiftbrite$PARTNUM$0$0 == 0xdf36
                    DF36    700 _PARTNUM	=	0xdf36
                    DF37    701 Fshiftbrite$VERSION$0$0 == 0xdf37
                    DF37    702 _VERSION	=	0xdf37
                    DF38    703 Fshiftbrite$FREQEST$0$0 == 0xdf38
                    DF38    704 _FREQEST	=	0xdf38
                    DF39    705 Fshiftbrite$LQI$0$0 == 0xdf39
                    DF39    706 _LQI	=	0xdf39
                    DF3A    707 Fshiftbrite$RSSI$0$0 == 0xdf3a
                    DF3A    708 _RSSI	=	0xdf3a
                    DF3B    709 Fshiftbrite$MARCSTATE$0$0 == 0xdf3b
                    DF3B    710 _MARCSTATE	=	0xdf3b
                    DF3C    711 Fshiftbrite$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    712 _PKTSTATUS	=	0xdf3c
                    DF3D    713 Fshiftbrite$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    714 _VCO_VC_DAC	=	0xdf3d
                    DF40    715 Fshiftbrite$I2SCFG0$0$0 == 0xdf40
                    DF40    716 _I2SCFG0	=	0xdf40
                    DF41    717 Fshiftbrite$I2SCFG1$0$0 == 0xdf41
                    DF41    718 _I2SCFG1	=	0xdf41
                    DF42    719 Fshiftbrite$I2SDATL$0$0 == 0xdf42
                    DF42    720 _I2SDATL	=	0xdf42
                    DF43    721 Fshiftbrite$I2SDATH$0$0 == 0xdf43
                    DF43    722 _I2SDATH	=	0xdf43
                    DF44    723 Fshiftbrite$I2SWCNT$0$0 == 0xdf44
                    DF44    724 _I2SWCNT	=	0xdf44
                    DF45    725 Fshiftbrite$I2SSTAT$0$0 == 0xdf45
                    DF45    726 _I2SSTAT	=	0xdf45
                    DF46    727 Fshiftbrite$I2SCLKF0$0$0 == 0xdf46
                    DF46    728 _I2SCLKF0	=	0xdf46
                    DF47    729 Fshiftbrite$I2SCLKF1$0$0 == 0xdf47
                    DF47    730 _I2SCLKF1	=	0xdf47
                    DF48    731 Fshiftbrite$I2SCLKF2$0$0 == 0xdf48
                    DF48    732 _I2SCLKF2	=	0xdf48
                    DE00    733 Fshiftbrite$USBADDR$0$0 == 0xde00
                    DE00    734 _USBADDR	=	0xde00
                    DE01    735 Fshiftbrite$USBPOW$0$0 == 0xde01
                    DE01    736 _USBPOW	=	0xde01
                    DE02    737 Fshiftbrite$USBIIF$0$0 == 0xde02
                    DE02    738 _USBIIF	=	0xde02
                    DE04    739 Fshiftbrite$USBOIF$0$0 == 0xde04
                    DE04    740 _USBOIF	=	0xde04
                    DE06    741 Fshiftbrite$USBCIF$0$0 == 0xde06
                    DE06    742 _USBCIF	=	0xde06
                    DE07    743 Fshiftbrite$USBIIE$0$0 == 0xde07
                    DE07    744 _USBIIE	=	0xde07
                    DE09    745 Fshiftbrite$USBOIE$0$0 == 0xde09
                    DE09    746 _USBOIE	=	0xde09
                    DE0B    747 Fshiftbrite$USBCIE$0$0 == 0xde0b
                    DE0B    748 _USBCIE	=	0xde0b
                    DE0C    749 Fshiftbrite$USBFRML$0$0 == 0xde0c
                    DE0C    750 _USBFRML	=	0xde0c
                    DE0D    751 Fshiftbrite$USBFRMH$0$0 == 0xde0d
                    DE0D    752 _USBFRMH	=	0xde0d
                    DE0E    753 Fshiftbrite$USBINDEX$0$0 == 0xde0e
                    DE0E    754 _USBINDEX	=	0xde0e
                    DE10    755 Fshiftbrite$USBMAXI$0$0 == 0xde10
                    DE10    756 _USBMAXI	=	0xde10
                    DE11    757 Fshiftbrite$USBCSIL$0$0 == 0xde11
                    DE11    758 _USBCSIL	=	0xde11
                    DE12    759 Fshiftbrite$USBCSIH$0$0 == 0xde12
                    DE12    760 _USBCSIH	=	0xde12
                    DE13    761 Fshiftbrite$USBMAXO$0$0 == 0xde13
                    DE13    762 _USBMAXO	=	0xde13
                    DE14    763 Fshiftbrite$USBCSOL$0$0 == 0xde14
                    DE14    764 _USBCSOL	=	0xde14
                    DE15    765 Fshiftbrite$USBCSOH$0$0 == 0xde15
                    DE15    766 _USBCSOH	=	0xde15
                    DE16    767 Fshiftbrite$USBCNTL$0$0 == 0xde16
                    DE16    768 _USBCNTL	=	0xde16
                    DE17    769 Fshiftbrite$USBCNTH$0$0 == 0xde17
                    DE17    770 _USBCNTH	=	0xde17
                    DE20    771 Fshiftbrite$USBF0$0$0 == 0xde20
                    DE20    772 _USBF0	=	0xde20
                    DE22    773 Fshiftbrite$USBF1$0$0 == 0xde22
                    DE22    774 _USBF1	=	0xde22
                    DE24    775 Fshiftbrite$USBF2$0$0 == 0xde24
                    DE24    776 _USBF2	=	0xde24
                    DE26    777 Fshiftbrite$USBF3$0$0 == 0xde26
                    DE26    778 _USBF3	=	0xde26
                    DE28    779 Fshiftbrite$USBF4$0$0 == 0xde28
                    DE28    780 _USBF4	=	0xde28
                    DE2A    781 Fshiftbrite$USBF5$0$0 == 0xde2a
                    DE2A    782 _USBF5	=	0xde2a
                            783 ;--------------------------------------------------------
                            784 ; absolute external ram data
                            785 ;--------------------------------------------------------
                            786 	.area XABS    (ABS,XDATA)
                            787 ;--------------------------------------------------------
                            788 ; external initialized ram data
                            789 ;--------------------------------------------------------
                            790 	.area XISEG   (XDATA)
                            791 	.area HOME    (CODE)
                            792 	.area GSINIT0 (CODE)
                            793 	.area GSINIT1 (CODE)
                            794 	.area GSINIT2 (CODE)
                            795 	.area GSINIT3 (CODE)
                            796 	.area GSINIT4 (CODE)
                            797 	.area GSINIT5 (CODE)
                            798 	.area GSINIT  (CODE)
                            799 	.area GSFINAL (CODE)
                            800 	.area CSEG    (CODE)
                            801 ;--------------------------------------------------------
                            802 ; interrupt vector 
                            803 ;--------------------------------------------------------
                            804 	.area HOME    (CODE)
   0400                     805 __interrupt_vect:
   0400 02 04 8D            806 	ljmp	__sdcc_gsinit_startup
   0403 32                  807 	reti
   0404                     808 	.ds	7
   040B 32                  809 	reti
   040C                     810 	.ds	7
   0413 32                  811 	reti
   0414                     812 	.ds	7
   041B 32                  813 	reti
   041C                     814 	.ds	7
   0423 32                  815 	reti
   0424                     816 	.ds	7
   042B 32                  817 	reti
   042C                     818 	.ds	7
   0433 32                  819 	reti
   0434                     820 	.ds	7
   043B 32                  821 	reti
   043C                     822 	.ds	7
   0443 32                  823 	reti
   0444                     824 	.ds	7
   044B 32                  825 	reti
   044C                     826 	.ds	7
   0453 32                  827 	reti
   0454                     828 	.ds	7
   045B 32                  829 	reti
   045C                     830 	.ds	7
   0463 02 11 65            831 	ljmp	_ISR_T4
   0466                     832 	.ds	5
   046B 32                  833 	reti
   046C                     834 	.ds	7
   0473 32                  835 	reti
   0474                     836 	.ds	7
   047B 32                  837 	reti
   047C                     838 	.ds	7
   0483 02 0A 7A            839 	ljmp	_ISR_RF
                            840 ;--------------------------------------------------------
                            841 ; global & static initialisations
                            842 ;--------------------------------------------------------
                            843 	.area HOME    (CODE)
                            844 	.area GSINIT  (CODE)
                            845 	.area GSFINAL (CODE)
                            846 	.area GSINIT  (CODE)
                            847 	.globl __sdcc_gsinit_startup
                            848 	.globl __sdcc_program_startup
                            849 	.globl __start__stack
                            850 	.globl __mcs51_genXINIT
                            851 	.globl __mcs51_genXRAMCLEAR
                            852 	.globl __mcs51_genRAMCLEAR
                            853 ;------------------------------------------------------------
                            854 ;Allocation info for local variables in function 'shiftbriteProcessByte'
                            855 ;------------------------------------------------------------
                            856 ;sloc0                     Allocated with name '_shiftbriteProcessByte_sloc0_1_0'
                            857 ;------------------------------------------------------------
                    0000    858 	G$shiftbriteProcessByte$0$0 ==.
                    0000    859 	C$shiftbrite.c$136$1$1 ==.
                            860 ;	apps/shiftbrite/shiftbrite.c:136: static uint8 i = 0;
   04E6 78 25               861 	mov	r0,#_shiftbriteProcessByte_i_1_1
   04E8 E4                  862 	clr	a
   04E9 F2                  863 	movx	@r0,a
                    0004    864 	G$main$0$0 ==.
                    0004    865 	C$shiftbrite.c$35$1$1 ==.
                            866 ;	apps/shiftbrite/shiftbrite.c:35: BIT radioBlinkActive = 0;
   04EA C2 00               867 	clr	_radioBlinkActive
                    0006    868 	G$main$0$0 ==.
                    0006    869 	C$shiftbrite.c$32$1$1 ==.
                            870 ;	apps/shiftbrite/shiftbrite.c:32: uint32 lastSend = 0;
   04EC 78 00               871 	mov	r0,#_lastSend
   04EE E4                  872 	clr	a
   04EF F2                  873 	movx	@r0,a
   04F0 08                  874 	inc	r0
   04F1 F2                  875 	movx	@r0,a
   04F2 08                  876 	inc	r0
   04F3 F2                  877 	movx	@r0,a
   04F4 08                  878 	inc	r0
   04F5 F2                  879 	movx	@r0,a
                            880 	.area GSFINAL (CODE)
   0561 02 04 86            881 	ljmp	__sdcc_program_startup
                            882 ;--------------------------------------------------------
                            883 ; Home
                            884 ;--------------------------------------------------------
                            885 	.area HOME    (CODE)
                            886 	.area HOME    (CODE)
   0486                     887 __sdcc_program_startup:
   0486 12 0A 5C            888 	lcall	_main
                            889 ;	return from main will lock up
   0489 80 FE               890 	sjmp .
                            891 ;--------------------------------------------------------
                            892 ; code
                            893 ;--------------------------------------------------------
                            894 	.area CSEG    (CODE)
                            895 ;------------------------------------------------------------
                            896 ;Allocation info for local variables in function 'hexCharToByte'
                            897 ;------------------------------------------------------------
                    0000    898 	G$hexCharToByte$0$0 ==.
                    0000    899 	C$shiftbrite.c$50$0$0 ==.
                            900 ;	apps/shiftbrite/shiftbrite.c:50: uint8 hexCharToByte(char c)
                            901 ;	-----------------------------------------
                            902 ;	 function hexCharToByte
                            903 ;	-----------------------------------------
   0564                     904 _hexCharToByte:
                    0007    905 	ar7 = 0x07
                    0006    906 	ar6 = 0x06
                    0005    907 	ar5 = 0x05
                    0004    908 	ar4 = 0x04
                    0003    909 	ar3 = 0x03
                    0002    910 	ar2 = 0x02
                    0001    911 	ar1 = 0x01
                    0000    912 	ar0 = 0x00
   0564 AF 82               913 	mov	r7,dpl
                    0002    914 	C$shiftbrite.c$52$1$1 ==.
                            915 ;	apps/shiftbrite/shiftbrite.c:52: if(c >= '0' && c <= '9')
   0566 C3                  916 	clr	c
   0567 EF                  917 	mov	a,r7
   0568 64 80               918 	xrl	a,#0x80
   056A 94 B0               919 	subb	a,#0xb0
   056C 40 13               920 	jc	00102$
   056E 74 B9               921 	mov	a,#(0x39 ^ 0x80)
   0570 8F F0               922 	mov	b,r7
   0572 63 F0 80            923 	xrl	b,#0x80
   0575 95 F0               924 	subb	a,b
   0577 40 08               925 	jc	00102$
                    0015    926 	C$shiftbrite.c$54$2$2 ==.
                            927 ;	apps/shiftbrite/shiftbrite.c:54: return c-'0';
   0579 EF                  928 	mov	a,r7
   057A 24 D0               929 	add	a,#0xD0
   057C FE                  930 	mov	r6,a
   057D F5 82               931 	mov	dpl,a
   057F 80 39               932 	sjmp	00110$
   0581                     933 00102$:
                    001D    934 	C$shiftbrite.c$56$1$1 ==.
                            935 ;	apps/shiftbrite/shiftbrite.c:56: if(c >= 'a' && c <= 'f')
   0581 C3                  936 	clr	c
   0582 EF                  937 	mov	a,r7
   0583 64 80               938 	xrl	a,#0x80
   0585 94 E1               939 	subb	a,#0xe1
   0587 40 13               940 	jc	00105$
   0589 74 E6               941 	mov	a,#(0x66 ^ 0x80)
   058B 8F F0               942 	mov	b,r7
   058D 63 F0 80            943 	xrl	b,#0x80
   0590 95 F0               944 	subb	a,b
   0592 40 08               945 	jc	00105$
                    0030    946 	C$shiftbrite.c$58$2$3 ==.
                            947 ;	apps/shiftbrite/shiftbrite.c:58: return c-'a'+10;
   0594 74 A9               948 	mov	a,#0xA9
   0596 2F                  949 	add	a,r7
   0597 FE                  950 	mov	r6,a
   0598 F5 82               951 	mov	dpl,a
   059A 80 1E               952 	sjmp	00110$
   059C                     953 00105$:
                    0038    954 	C$shiftbrite.c$60$1$1 ==.
                            955 ;	apps/shiftbrite/shiftbrite.c:60: if(c >= 'A' && c <= 'F')
   059C C3                  956 	clr	c
   059D EF                  957 	mov	a,r7
   059E 64 80               958 	xrl	a,#0x80
   05A0 94 C1               959 	subb	a,#0xc1
   05A2 40 13               960 	jc	00108$
   05A4 74 C6               961 	mov	a,#(0x46 ^ 0x80)
   05A6 8F F0               962 	mov	b,r7
   05A8 63 F0 80            963 	xrl	b,#0x80
   05AB 95 F0               964 	subb	a,b
   05AD 40 08               965 	jc	00108$
                    004B    966 	C$shiftbrite.c$62$2$4 ==.
                            967 ;	apps/shiftbrite/shiftbrite.c:62: return c-'A'+10;
   05AF 74 C9               968 	mov	a,#0xC9
   05B1 2F                  969 	add	a,r7
   05B2 FF                  970 	mov	r7,a
   05B3 F5 82               971 	mov	dpl,a
   05B5 80 03               972 	sjmp	00110$
   05B7                     973 00108$:
                    0053    974 	C$shiftbrite.c$64$1$1 ==.
                            975 ;	apps/shiftbrite/shiftbrite.c:64: return 0; // default
   05B7 75 82 00            976 	mov	dpl,#0x00
   05BA                     977 00110$:
                    0056    978 	C$shiftbrite.c$65$1$1 ==.
                    0056    979 	XG$hexCharToByte$0$0 ==.
   05BA 22                  980 	ret
                            981 ;------------------------------------------------------------
                            982 ;Allocation info for local variables in function 'hex'
                            983 ;------------------------------------------------------------
                    0057    984 	G$hex$0$0 ==.
                    0057    985 	C$shiftbrite.c$68$1$1 ==.
                            986 ;	apps/shiftbrite/shiftbrite.c:68: uint16 hex(char *s, uint8 len)
                            987 ;	-----------------------------------------
                            988 ;	 function hex
                            989 ;	-----------------------------------------
   05BB                     990 _hex:
   05BB AF F0               991 	mov	r7,b
   05BD AE 83               992 	mov	r6,dph
   05BF E5 82               993 	mov	a,dpl
   05C1 78 0A               994 	mov	r0,#_hex_s_1_1
   05C3 F2                  995 	movx	@r0,a
   05C4 08                  996 	inc	r0
   05C5 EE                  997 	mov	a,r6
   05C6 F2                  998 	movx	@r0,a
   05C7 08                  999 	inc	r0
   05C8 EF                 1000 	mov	a,r7
   05C9 F2                 1001 	movx	@r0,a
                    0066   1002 	C$shiftbrite.c$70$1$1 ==.
                           1003 ;	apps/shiftbrite/shiftbrite.c:70: uint16 ret = 0;
   05CA 7B 00              1004 	mov	r3,#0x00
   05CC 7C 00              1005 	mov	r4,#0x00
                    006A   1006 	C$shiftbrite.c$72$1$1 ==.
                           1007 ;	apps/shiftbrite/shiftbrite.c:72: for(i=0;i<len;i++)
   05CE 7A 00              1008 	mov	r2,#0x00
   05D0                    1009 00101$:
   05D0 78 09              1010 	mov	r0,#_hex_PARM_2
   05D2 C3                 1011 	clr	c
   05D3 E2                 1012 	movx	a,@r0
   05D4 F5 F0              1013 	mov	b,a
   05D6 EA                 1014 	mov	a,r2
   05D7 95 F0              1015 	subb	a,b
   05D9 50 42              1016 	jnc	00104$
                    0077   1017 	C$shiftbrite.c$74$2$2 ==.
                           1018 ;	apps/shiftbrite/shiftbrite.c:74: ret <<= 4;
   05DB EC                 1019 	mov	a,r4
   05DC C4                 1020 	swap	a
   05DD 54 F0              1021 	anl	a,#0xF0
   05DF CB                 1022 	xch	a,r3
   05E0 C4                 1023 	swap	a
   05E1 CB                 1024 	xch	a,r3
   05E2 6B                 1025 	xrl	a,r3
   05E3 CB                 1026 	xch	a,r3
   05E4 54 F0              1027 	anl	a,#0xF0
   05E6 CB                 1028 	xch	a,r3
   05E7 6B                 1029 	xrl	a,r3
   05E8 FC                 1030 	mov	r4,a
                    0085   1031 	C$shiftbrite.c$75$2$2 ==.
                           1032 ;	apps/shiftbrite/shiftbrite.c:75: ret += hexCharToByte(s[i]);
   05E9 78 0A              1033 	mov	r0,#_hex_s_1_1
   05EB E2                 1034 	movx	a,@r0
   05EC 2A                 1035 	add	a,r2
   05ED FD                 1036 	mov	r5,a
   05EE 08                 1037 	inc	r0
   05EF E2                 1038 	movx	a,@r0
   05F0 34 00              1039 	addc	a,#0x00
   05F2 FE                 1040 	mov	r6,a
   05F3 08                 1041 	inc	r0
   05F4 E2                 1042 	movx	a,@r0
   05F5 FF                 1043 	mov	r7,a
   05F6 8D 82              1044 	mov	dpl,r5
   05F8 8E 83              1045 	mov	dph,r6
   05FA 8F F0              1046 	mov	b,r7
   05FC 12 1D 0A           1047 	lcall	__gptrget
   05FF F5 82              1048 	mov	dpl,a
   0601 C0 04              1049 	push	ar4
   0603 C0 03              1050 	push	ar3
   0605 C0 02              1051 	push	ar2
   0607 12 05 64           1052 	lcall	_hexCharToByte
   060A AF 82              1053 	mov	r7,dpl
   060C D0 02              1054 	pop	ar2
   060E D0 03              1055 	pop	ar3
   0610 D0 04              1056 	pop	ar4
   0612 7E 00              1057 	mov	r6,#0x00
   0614 EF                 1058 	mov	a,r7
   0615 2B                 1059 	add	a,r3
   0616 FB                 1060 	mov	r3,a
   0617 EE                 1061 	mov	a,r6
   0618 3C                 1062 	addc	a,r4
   0619 FC                 1063 	mov	r4,a
                    00B6   1064 	C$shiftbrite.c$72$1$1 ==.
                           1065 ;	apps/shiftbrite/shiftbrite.c:72: for(i=0;i<len;i++)
   061A 0A                 1066 	inc	r2
   061B 80 B3              1067 	sjmp	00101$
   061D                    1068 00104$:
                    00B9   1069 	C$shiftbrite.c$77$1$1 ==.
                           1070 ;	apps/shiftbrite/shiftbrite.c:77: return ret;
   061D 8B 82              1071 	mov	dpl,r3
   061F 8C 83              1072 	mov	dph,r4
                    00BD   1073 	C$shiftbrite.c$78$1$1 ==.
                    00BD   1074 	XG$hex$0$0 ==.
   0621 22                 1075 	ret
                           1076 ;------------------------------------------------------------
                           1077 ;Allocation info for local variables in function 'toggleLatch'
                           1078 ;------------------------------------------------------------
                    00BE   1079 	G$toggleLatch$0$0 ==.
                    00BE   1080 	C$shiftbrite.c$80$1$1 ==.
                           1081 ;	apps/shiftbrite/shiftbrite.c:80: void toggleLatch()
                           1082 ;	-----------------------------------------
                           1083 ;	 function toggleLatch
                           1084 ;	-----------------------------------------
   0622                    1085 _toggleLatch:
                    00BE   1086 	C$shiftbrite.c$82$1$1 ==.
                           1087 ;	apps/shiftbrite/shiftbrite.c:82: SHIFTBRITE_LATCH = 1;
   0622 D2 97              1088 	setb	_P1_7
                    00C0   1089 	C$shiftbrite.c$83$1$1 ==.
                           1090 ;	apps/shiftbrite/shiftbrite.c:83: delayMicroseconds(1);
   0624 75 82 01           1091 	mov	dpl,#0x01
   0627 12 0C 71           1092 	lcall	_delayMicroseconds
                    00C6   1093 	C$shiftbrite.c$84$1$1 ==.
                           1094 ;	apps/shiftbrite/shiftbrite.c:84: SHIFTBRITE_LATCH = 0;
   062A C2 97              1095 	clr	_P1_7
                    00C8   1096 	C$shiftbrite.c$85$1$1 ==.
                           1097 ;	apps/shiftbrite/shiftbrite.c:85: delayMicroseconds(1);
   062C 75 82 01           1098 	mov	dpl,#0x01
   062F 12 0C 71           1099 	lcall	_delayMicroseconds
                    00CE   1100 	C$shiftbrite.c$86$1$1 ==.
                           1101 ;	apps/shiftbrite/shiftbrite.c:86: SHIFTBRITE_DISABLE = 0; // enable shiftbrites
   0632 C2 94              1102 	clr	_P1_4
                    00D0   1103 	C$shiftbrite.c$87$1$1 ==.
                    00D0   1104 	XG$toggleLatch$0$0 ==.
   0634 22                 1105 	ret
                           1106 ;------------------------------------------------------------
                           1107 ;Allocation info for local variables in function 'sendBit'
                           1108 ;------------------------------------------------------------
                    00D1   1109 	G$sendBit$0$0 ==.
                    00D1   1110 	C$shiftbrite.c$89$1$1 ==.
                           1111 ;	apps/shiftbrite/shiftbrite.c:89: void sendBit(BIT value)
                           1112 ;	-----------------------------------------
                           1113 ;	 function sendBit
                           1114 ;	-----------------------------------------
   0635                    1115 _sendBit:
                    00D1   1116 	C$shiftbrite.c$91$1$1 ==.
                           1117 ;	apps/shiftbrite/shiftbrite.c:91: SHIFTBRITE_DATA = value;
   0635 A2 01              1118 	mov	c,_sendBit_PARM_1
   0637 92 96              1119 	mov	_P1_6,c
                    00D5   1120 	C$shiftbrite.c$92$1$1 ==.
                           1121 ;	apps/shiftbrite/shiftbrite.c:92: delayMicroseconds(1);
   0639 75 82 01           1122 	mov	dpl,#0x01
   063C 12 0C 71           1123 	lcall	_delayMicroseconds
                    00DB   1124 	C$shiftbrite.c$93$1$1 ==.
                           1125 ;	apps/shiftbrite/shiftbrite.c:93: SHIFTBRITE_CLOCK = 1;
   063F D2 95              1126 	setb	_P1_5
                    00DD   1127 	C$shiftbrite.c$94$1$1 ==.
                           1128 ;	apps/shiftbrite/shiftbrite.c:94: delayMicroseconds(1);
   0641 75 82 01           1129 	mov	dpl,#0x01
   0644 12 0C 71           1130 	lcall	_delayMicroseconds
                    00E3   1131 	C$shiftbrite.c$95$1$1 ==.
                           1132 ;	apps/shiftbrite/shiftbrite.c:95: SHIFTBRITE_CLOCK = 0;
   0647 C2 95              1133 	clr	_P1_5
                    00E5   1134 	C$shiftbrite.c$96$1$1 ==.
                           1135 ;	apps/shiftbrite/shiftbrite.c:96: delayMicroseconds(1);
   0649 75 82 01           1136 	mov	dpl,#0x01
   064C 12 0C 71           1137 	lcall	_delayMicroseconds
                    00EB   1138 	C$shiftbrite.c$97$1$1 ==.
                    00EB   1139 	XG$sendBit$0$0 ==.
   064F 22                 1140 	ret
                           1141 ;------------------------------------------------------------
                           1142 ;Allocation info for local variables in function 'sendRGB'
                           1143 ;------------------------------------------------------------
                    00EC   1144 	G$sendRGB$0$0 ==.
                    00EC   1145 	C$shiftbrite.c$99$1$1 ==.
                           1146 ;	apps/shiftbrite/shiftbrite.c:99: void sendRGB(uint16 r, uint16 g, uint16 b)
                           1147 ;	-----------------------------------------
                           1148 ;	 function sendRGB
                           1149 ;	-----------------------------------------
   0650                    1150 _sendRGB:
   0650 AE 82              1151 	mov	r6,dpl
   0652 AF 83              1152 	mov	r7,dph
                    00F0   1153 	C$shiftbrite.c$101$1$1 ==.
                           1154 ;	apps/shiftbrite/shiftbrite.c:101: uint16 mask = 512;
   0654 7C 00              1155 	mov	r4,#0x00
   0656 7D 02              1156 	mov	r5,#0x02
                    00F4   1157 	C$shiftbrite.c$102$1$1 ==.
                           1158 ;	apps/shiftbrite/shiftbrite.c:102: sendBit(0);
   0658 C2 01              1159 	clr	_sendBit_PARM_1
   065A C0 07              1160 	push	ar7
   065C C0 06              1161 	push	ar6
   065E C0 05              1162 	push	ar5
   0660 C0 04              1163 	push	ar4
   0662 12 06 35           1164 	lcall	_sendBit
                    0101   1165 	C$shiftbrite.c$103$1$1 ==.
                           1166 ;	apps/shiftbrite/shiftbrite.c:103: sendBit(0);
   0665 C2 01              1167 	clr	_sendBit_PARM_1
   0667 12 06 35           1168 	lcall	_sendBit
   066A D0 04              1169 	pop	ar4
   066C D0 05              1170 	pop	ar5
   066E D0 06              1171 	pop	ar6
   0670 D0 07              1172 	pop	ar7
                    010E   1173 	C$shiftbrite.c$104$1$1 ==.
                           1174 ;	apps/shiftbrite/shiftbrite.c:104: while(mask)
   0672                    1175 00101$:
   0672 EC                 1176 	mov	a,r4
   0673 4D                 1177 	orl	a,r5
   0674 60 29              1178 	jz	00103$
                    0112   1179 	C$shiftbrite.c$106$2$2 ==.
                           1180 ;	apps/shiftbrite/shiftbrite.c:106: sendBit((mask & b) ? 1 : 0);
   0676 78 0F              1181 	mov	r0,#_sendRGB_PARM_3
   0678 E2                 1182 	movx	a,@r0
   0679 5C                 1183 	anl	a,r4
   067A FA                 1184 	mov	r2,a
   067B 08                 1185 	inc	r0
   067C E2                 1186 	movx	a,@r0
   067D 5D                 1187 	anl	a,r5
   067E 4A                 1188 	orl	a,r2
   067F 24 FF              1189 	add	a,#0xff
   0681 92 01              1190 	mov	_sendBit_PARM_1,c
   0683 C0 07              1191 	push	ar7
   0685 C0 06              1192 	push	ar6
   0687 C0 05              1193 	push	ar5
   0689 C0 04              1194 	push	ar4
   068B 12 06 35           1195 	lcall	_sendBit
   068E D0 04              1196 	pop	ar4
   0690 D0 05              1197 	pop	ar5
   0692 D0 06              1198 	pop	ar6
   0694 D0 07              1199 	pop	ar7
                    0132   1200 	C$shiftbrite.c$107$2$2 ==.
                           1201 ;	apps/shiftbrite/shiftbrite.c:107: mask >>= 1;
   0696 ED                 1202 	mov	a,r5
   0697 C3                 1203 	clr	c
   0698 13                 1204 	rrc	a
   0699 CC                 1205 	xch	a,r4
   069A 13                 1206 	rrc	a
   069B CC                 1207 	xch	a,r4
   069C FD                 1208 	mov	r5,a
   069D 80 D3              1209 	sjmp	00101$
   069F                    1210 00103$:
                    013B   1211 	C$shiftbrite.c$109$1$1 ==.
                           1212 ;	apps/shiftbrite/shiftbrite.c:109: mask = 512;
   069F 7C 00              1213 	mov	r4,#0x00
   06A1 7D 02              1214 	mov	r5,#0x02
                    013F   1215 	C$shiftbrite.c$110$1$1 ==.
                           1216 ;	apps/shiftbrite/shiftbrite.c:110: while(mask)
   06A3                    1217 00104$:
   06A3 EC                 1218 	mov	a,r4
   06A4 4D                 1219 	orl	a,r5
   06A5 60 26              1220 	jz	00106$
                    0143   1221 	C$shiftbrite.c$112$2$3 ==.
                           1222 ;	apps/shiftbrite/shiftbrite.c:112: sendBit((mask & r) ? 1 : 0);
   06A7 EE                 1223 	mov	a,r6
   06A8 5C                 1224 	anl	a,r4
   06A9 FA                 1225 	mov	r2,a
   06AA EF                 1226 	mov	a,r7
   06AB 5D                 1227 	anl	a,r5
   06AC 4A                 1228 	orl	a,r2
   06AD 24 FF              1229 	add	a,#0xff
   06AF 92 01              1230 	mov	_sendBit_PARM_1,c
   06B1 C0 07              1231 	push	ar7
   06B3 C0 06              1232 	push	ar6
   06B5 C0 05              1233 	push	ar5
   06B7 C0 04              1234 	push	ar4
   06B9 12 06 35           1235 	lcall	_sendBit
   06BC D0 04              1236 	pop	ar4
   06BE D0 05              1237 	pop	ar5
   06C0 D0 06              1238 	pop	ar6
   06C2 D0 07              1239 	pop	ar7
                    0160   1240 	C$shiftbrite.c$113$2$3 ==.
                           1241 ;	apps/shiftbrite/shiftbrite.c:113: mask >>= 1;
   06C4 ED                 1242 	mov	a,r5
   06C5 C3                 1243 	clr	c
   06C6 13                 1244 	rrc	a
   06C7 CC                 1245 	xch	a,r4
   06C8 13                 1246 	rrc	a
   06C9 CC                 1247 	xch	a,r4
   06CA FD                 1248 	mov	r5,a
   06CB 80 D6              1249 	sjmp	00104$
   06CD                    1250 00106$:
                    0169   1251 	C$shiftbrite.c$115$1$1 ==.
                           1252 ;	apps/shiftbrite/shiftbrite.c:115: mask = 512;
   06CD 7C 00              1253 	mov	r4,#0x00
   06CF 7D 02              1254 	mov	r5,#0x02
                    016D   1255 	C$shiftbrite.c$116$1$1 ==.
                           1256 ;	apps/shiftbrite/shiftbrite.c:116: while(mask)
   06D1                    1257 00107$:
   06D1 EC                 1258 	mov	a,r4
   06D2 4D                 1259 	orl	a,r5
   06D3 60 21              1260 	jz	00110$
                    0171   1261 	C$shiftbrite.c$118$2$4 ==.
                           1262 ;	apps/shiftbrite/shiftbrite.c:118: sendBit((mask & g) ? 1 : 0);
   06D5 78 0D              1263 	mov	r0,#_sendRGB_PARM_2
   06D7 E2                 1264 	movx	a,@r0
   06D8 5C                 1265 	anl	a,r4
   06D9 FE                 1266 	mov	r6,a
   06DA 08                 1267 	inc	r0
   06DB E2                 1268 	movx	a,@r0
   06DC 5D                 1269 	anl	a,r5
   06DD 4E                 1270 	orl	a,r6
   06DE 24 FF              1271 	add	a,#0xff
   06E0 92 01              1272 	mov	_sendBit_PARM_1,c
   06E2 C0 05              1273 	push	ar5
   06E4 C0 04              1274 	push	ar4
   06E6 12 06 35           1275 	lcall	_sendBit
   06E9 D0 04              1276 	pop	ar4
   06EB D0 05              1277 	pop	ar5
                    0189   1278 	C$shiftbrite.c$119$2$4 ==.
                           1279 ;	apps/shiftbrite/shiftbrite.c:119: mask >>= 1;
   06ED ED                 1280 	mov	a,r5
   06EE C3                 1281 	clr	c
   06EF 13                 1282 	rrc	a
   06F0 CC                 1283 	xch	a,r4
   06F1 13                 1284 	rrc	a
   06F2 CC                 1285 	xch	a,r4
   06F3 FD                 1286 	mov	r5,a
   06F4 80 DB              1287 	sjmp	00107$
   06F6                    1288 00110$:
                    0192   1289 	C$shiftbrite.c$121$1$1 ==.
                    0192   1290 	XG$sendRGB$0$0 ==.
   06F6 22                 1291 	ret
                           1292 ;------------------------------------------------------------
                           1293 ;Allocation info for local variables in function 'restrictRange'
                           1294 ;------------------------------------------------------------
                    0193   1295 	G$restrictRange$0$0 ==.
                    0193   1296 	C$shiftbrite.c$124$1$1 ==.
                           1297 ;	apps/shiftbrite/shiftbrite.c:124: int32 restrictRange(int32 value, int32 min, int32 max)
                           1298 ;	-----------------------------------------
                           1299 ;	 function restrictRange
                           1300 ;	-----------------------------------------
   06F7                    1301 _restrictRange:
   06F7 AC 82              1302 	mov	r4,dpl
   06F9 AD 83              1303 	mov	r5,dph
   06FB AE F0              1304 	mov	r6,b
   06FD FF                 1305 	mov	r7,a
                    019A   1306 	C$shiftbrite.c$126$1$1 ==.
                           1307 ;	apps/shiftbrite/shiftbrite.c:126: if(value < min)
   06FE 78 11              1308 	mov	r0,#_restrictRange_PARM_2
   0700 C3                 1309 	clr	c
   0701 E2                 1310 	movx	a,@r0
   0702 F5 F0              1311 	mov	b,a
   0704 EC                 1312 	mov	a,r4
   0705 95 F0              1313 	subb	a,b
   0707 08                 1314 	inc	r0
   0708 E2                 1315 	movx	a,@r0
   0709 F5 F0              1316 	mov	b,a
   070B ED                 1317 	mov	a,r5
   070C 95 F0              1318 	subb	a,b
   070E 08                 1319 	inc	r0
   070F E2                 1320 	movx	a,@r0
   0710 F5 F0              1321 	mov	b,a
   0712 EE                 1322 	mov	a,r6
   0713 95 F0              1323 	subb	a,b
   0715 08                 1324 	inc	r0
   0716 E2                 1325 	movx	a,@r0
   0717 F5 F0              1326 	mov	b,a
   0719 EF                 1327 	mov	a,r7
   071A 64 80              1328 	xrl	a,#0x80
   071C 63 F0 80           1329 	xrl	b,#0x80
   071F 95 F0              1330 	subb	a,b
   0721 50 11              1331 	jnc	00102$
                    01BF   1332 	C$shiftbrite.c$127$1$1 ==.
                           1333 ;	apps/shiftbrite/shiftbrite.c:127: return min;
   0723 78 11              1334 	mov	r0,#_restrictRange_PARM_2
   0725 E2                 1335 	movx	a,@r0
   0726 F5 82              1336 	mov	dpl,a
   0728 08                 1337 	inc	r0
   0729 E2                 1338 	movx	a,@r0
   072A F5 83              1339 	mov	dph,a
   072C 08                 1340 	inc	r0
   072D E2                 1341 	movx	a,@r0
   072E F5 F0              1342 	mov	b,a
   0730 08                 1343 	inc	r0
   0731 E2                 1344 	movx	a,@r0
   0732 80 30              1345 	sjmp	00105$
   0734                    1346 00102$:
                    01D0   1347 	C$shiftbrite.c$128$1$1 ==.
                           1348 ;	apps/shiftbrite/shiftbrite.c:128: if(value > max)
   0734 78 15              1349 	mov	r0,#_restrictRange_PARM_3
   0736 C3                 1350 	clr	c
   0737 E2                 1351 	movx	a,@r0
   0738 9C                 1352 	subb	a,r4
   0739 08                 1353 	inc	r0
   073A E2                 1354 	movx	a,@r0
   073B 9D                 1355 	subb	a,r5
   073C 08                 1356 	inc	r0
   073D E2                 1357 	movx	a,@r0
   073E 9E                 1358 	subb	a,r6
   073F 08                 1359 	inc	r0
   0740 E2                 1360 	movx	a,@r0
   0741 64 80              1361 	xrl	a,#0x80
   0743 8F F0              1362 	mov	b,r7
   0745 63 F0 80           1363 	xrl	b,#0x80
   0748 95 F0              1364 	subb	a,b
   074A 50 11              1365 	jnc	00104$
                    01E8   1366 	C$shiftbrite.c$129$1$1 ==.
                           1367 ;	apps/shiftbrite/shiftbrite.c:129: return max;
   074C 78 15              1368 	mov	r0,#_restrictRange_PARM_3
   074E E2                 1369 	movx	a,@r0
   074F F5 82              1370 	mov	dpl,a
   0751 08                 1371 	inc	r0
   0752 E2                 1372 	movx	a,@r0
   0753 F5 83              1373 	mov	dph,a
   0755 08                 1374 	inc	r0
   0756 E2                 1375 	movx	a,@r0
   0757 F5 F0              1376 	mov	b,a
   0759 08                 1377 	inc	r0
   075A E2                 1378 	movx	a,@r0
   075B 80 07              1379 	sjmp	00105$
   075D                    1380 00104$:
                    01F9   1381 	C$shiftbrite.c$130$1$1 ==.
                           1382 ;	apps/shiftbrite/shiftbrite.c:130: return value;
   075D 8C 82              1383 	mov	dpl,r4
   075F 8D 83              1384 	mov	dph,r5
   0761 8E F0              1385 	mov	b,r6
   0763 EF                 1386 	mov	a,r7
   0764                    1387 00105$:
                    0200   1388 	C$shiftbrite.c$131$1$1 ==.
                    0200   1389 	XG$restrictRange$0$0 ==.
   0764 22                 1390 	ret
                           1391 ;------------------------------------------------------------
                           1392 ;Allocation info for local variables in function 'shiftbriteProcessByte'
                           1393 ;------------------------------------------------------------
                           1394 ;sloc0                     Allocated with name '_shiftbriteProcessByte_sloc0_1_0'
                           1395 ;------------------------------------------------------------
                    0201   1396 	G$shiftbriteProcessByte$0$0 ==.
                    0201   1397 	C$shiftbrite.c$133$1$1 ==.
                           1398 ;	apps/shiftbrite/shiftbrite.c:133: void shiftbriteProcessByte(char c)
                           1399 ;	-----------------------------------------
                           1400 ;	 function shiftbriteProcessByte
                           1401 ;	-----------------------------------------
   0765                    1402 _shiftbriteProcessByte:
   0765 AF 82              1403 	mov	r7,dpl
                    0203   1404 	C$shiftbrite.c$138$1$1 ==.
                           1405 ;	apps/shiftbrite/shiftbrite.c:138: if(c == '\r' || c == '\n')
   0767 BF 0D 02           1406 	cjne	r7,#0x0D,00115$
   076A 80 03              1407 	sjmp	00106$
   076C                    1408 00115$:
   076C BF 0A 0A           1409 	cjne	r7,#0x0A,00107$
   076F                    1410 00106$:
                    020B   1411 	C$shiftbrite.c$140$2$2 ==.
                           1412 ;	apps/shiftbrite/shiftbrite.c:140: i = 0;
   076F 78 25              1413 	mov	r0,#_shiftbriteProcessByte_i_1_1
   0771 E4                 1414 	clr	a
   0772 F2                 1415 	movx	@r0,a
                    020F   1416 	C$shiftbrite.c$141$2$2 ==.
                           1417 ;	apps/shiftbrite/shiftbrite.c:141: toggleLatch();
   0773 12 06 22           1418 	lcall	_toggleLatch
   0776 02 09 54           1419 	ljmp	00110$
   0779                    1420 00107$:
                    0215   1421 	C$shiftbrite.c$146$2$3 ==.
                           1422 ;	apps/shiftbrite/shiftbrite.c:146: rgb[i] = c;
   0779 78 25              1423 	mov	r0,#_shiftbriteProcessByte_i_1_1
   077B E2                 1424 	movx	a,@r0
   077C 24 19              1425 	add	a,#_shiftbriteProcessByte_rgb_1_1
   077E F8                 1426 	mov	r0,a
   077F EF                 1427 	mov	a,r7
   0780 F2                 1428 	movx	@r0,a
                    021D   1429 	C$shiftbrite.c$147$2$3 ==.
                           1430 ;	apps/shiftbrite/shiftbrite.c:147: i++;
   0781 78 25              1431 	mov	r0,#_shiftbriteProcessByte_i_1_1
   0783 E2                 1432 	movx	a,@r0
   0784 24 01              1433 	add	a,#0x01
   0786 F2                 1434 	movx	@r0,a
                    0223   1435 	C$shiftbrite.c$149$2$3 ==.
                           1436 ;	apps/shiftbrite/shiftbrite.c:149: if(i == hex_chars_per_color*3)
   0787 78 07              1437 	mov	r0,#_hex_chars_per_color
   0789 E2                 1438 	movx	a,@r0
   078A 75 F0 03           1439 	mov	b,#0x03
   078D A4                 1440 	mul	ab
   078E FE                 1441 	mov	r6,a
   078F AF F0              1442 	mov	r7,b
   0791 78 25              1443 	mov	r0,#_shiftbriteProcessByte_i_1_1
   0793 E2                 1444 	movx	a,@r0
   0794 FC                 1445 	mov	r4,a
   0795 7D 00              1446 	mov	r5,#0x00
   0797 B5 06 06           1447 	cjne	a,ar6,00118$
   079A ED                 1448 	mov	a,r5
   079B B5 07 02           1449 	cjne	a,ar7,00118$
   079E 80 03              1450 	sjmp	00119$
   07A0                    1451 00118$:
   07A0 02 09 54           1452 	ljmp	00110$
   07A3                    1453 00119$:
                    023F   1454 	C$shiftbrite.c$152$3$4 ==.
                           1455 ;	apps/shiftbrite/shiftbrite.c:152: i = 0;
   07A3 78 25              1456 	mov	r0,#_shiftbriteProcessByte_i_1_1
   07A5 E4                 1457 	clr	a
   07A6 F2                 1458 	movx	@r0,a
                    0243   1459 	C$shiftbrite.c$154$3$4 ==.
                           1460 ;	apps/shiftbrite/shiftbrite.c:154: if(shift > 0)
   07A7 78 08              1461 	mov	r0,#_shift
   07A9 C3                 1462 	clr	c
   07AA E2                 1463 	movx	a,@r0
   07AB F5 F0              1464 	mov	b,a
   07AD E4                 1465 	clr	a
   07AE 64 80              1466 	xrl	a,#0x80
   07B0 63 F0 80           1467 	xrl	b,#0x80
   07B3 95 F0              1468 	subb	a,b
   07B5 40 03              1469 	jc	00120$
   07B7 02 08 74           1470 	ljmp	00102$
   07BA                    1471 00120$:
                    0256   1472 	C$shiftbrite.c$157$4$5 ==.
                           1473 ;	apps/shiftbrite/shiftbrite.c:157: hex(rgb,                      hex_chars_per_color) << shift,
   07BA 78 07              1474 	mov	r0,#_hex_chars_per_color
   07BC 79 09              1475 	mov	r1,#_hex_PARM_2
   07BE E2                 1476 	movx	a,@r0
   07BF F3                 1477 	movx	@r1,a
   07C0 90 F0 19           1478 	mov	dptr,#_shiftbriteProcessByte_rgb_1_1
   07C3 75 F0 60           1479 	mov	b,#0x60
   07C6 12 05 BB           1480 	lcall	_hex
   07C9 AE 82              1481 	mov	r6,dpl
   07CB AF 83              1482 	mov	r7,dph
   07CD 78 08              1483 	mov	r0,#_shift
   07CF E2                 1484 	movx	a,@r0
   07D0 F5 F0              1485 	mov	b,a
   07D2 05 F0              1486 	inc	b
   07D4 80 06              1487 	sjmp	00122$
   07D6                    1488 00121$:
   07D6 EE                 1489 	mov	a,r6
   07D7 2E                 1490 	add	a,r6
   07D8 FE                 1491 	mov	r6,a
   07D9 EF                 1492 	mov	a,r7
   07DA 33                 1493 	rlc	a
   07DB FF                 1494 	mov	r7,a
   07DC                    1495 00122$:
   07DC D5 F0 F7           1496 	djnz	b,00121$
                    027B   1497 	C$shiftbrite.c$158$4$5 ==.
                           1498 ;	apps/shiftbrite/shiftbrite.c:158: hex(rgb+hex_chars_per_color,  hex_chars_per_color) << shift,
   07DF 78 07              1499 	mov	r0,#_hex_chars_per_color
   07E1 E2                 1500 	movx	a,@r0
   07E2 24 19              1501 	add	a,#_shiftbriteProcessByte_rgb_1_1
   07E4 FD                 1502 	mov	r5,a
   07E5 7C 00              1503 	mov	r4,#0x00
   07E7 7B 60              1504 	mov	r3,#0x60
   07E9 78 07              1505 	mov	r0,#_hex_chars_per_color
   07EB 79 09              1506 	mov	r1,#_hex_PARM_2
   07ED E2                 1507 	movx	a,@r0
   07EE F3                 1508 	movx	@r1,a
   07EF 8D 82              1509 	mov	dpl,r5
   07F1 8C 83              1510 	mov	dph,r4
   07F3 8B F0              1511 	mov	b,r3
   07F5 C0 07              1512 	push	ar7
   07F7 C0 06              1513 	push	ar6
   07F9 12 05 BB           1514 	lcall	_hex
   07FC AC 82              1515 	mov	r4,dpl
   07FE AD 83              1516 	mov	r5,dph
   0800 D0 06              1517 	pop	ar6
   0802 D0 07              1518 	pop	ar7
   0804 78 08              1519 	mov	r0,#_shift
   0806 E2                 1520 	movx	a,@r0
   0807 F5 F0              1521 	mov	b,a
   0809 05 F0              1522 	inc	b
   080B 85 04 08           1523 	mov	_shiftbriteProcessByte_sloc0_1_0,ar4
   080E 85 05 09           1524 	mov	(_shiftbriteProcessByte_sloc0_1_0 + 1),ar5
   0811 80 0B              1525 	sjmp	00124$
   0813                    1526 00123$:
   0813 E5 08              1527 	mov	a,_shiftbriteProcessByte_sloc0_1_0
   0815 25 08              1528 	add	a,_shiftbriteProcessByte_sloc0_1_0
   0817 F5 08              1529 	mov	_shiftbriteProcessByte_sloc0_1_0,a
   0819 E5 09              1530 	mov	a,(_shiftbriteProcessByte_sloc0_1_0 + 1)
   081B 33                 1531 	rlc	a
   081C F5 09              1532 	mov	(_shiftbriteProcessByte_sloc0_1_0 + 1),a
   081E                    1533 00124$:
   081E D5 F0 F2           1534 	djnz	b,00123$
                    02BD   1535 	C$shiftbrite.c$159$4$5 ==.
                           1536 ;	apps/shiftbrite/shiftbrite.c:159: hex(rgb+hex_chars_per_color*2,hex_chars_per_color) << shift
   0821 78 07              1537 	mov	r0,#_hex_chars_per_color
   0823 E2                 1538 	movx	a,@r0
   0824 25 E0              1539 	add	a,acc
   0826 24 19              1540 	add	a,#_shiftbriteProcessByte_rgb_1_1
   0828 FA                 1541 	mov	r2,a
   0829 7B 00              1542 	mov	r3,#0x00
   082B 7D 60              1543 	mov	r5,#0x60
   082D 78 07              1544 	mov	r0,#_hex_chars_per_color
   082F 79 09              1545 	mov	r1,#_hex_PARM_2
   0831 E2                 1546 	movx	a,@r0
   0832 F3                 1547 	movx	@r1,a
   0833 8A 82              1548 	mov	dpl,r2
   0835 8B 83              1549 	mov	dph,r3
   0837 8D F0              1550 	mov	b,r5
   0839 C0 07              1551 	push	ar7
   083B C0 06              1552 	push	ar6
   083D 12 05 BB           1553 	lcall	_hex
   0840 AC 82              1554 	mov	r4,dpl
   0842 AD 83              1555 	mov	r5,dph
   0844 D0 06              1556 	pop	ar6
   0846 D0 07              1557 	pop	ar7
   0848 78 08              1558 	mov	r0,#_shift
   084A E2                 1559 	movx	a,@r0
   084B F5 F0              1560 	mov	b,a
   084D 05 F0              1561 	inc	b
   084F 80 06              1562 	sjmp	00126$
   0851                    1563 00125$:
   0851 EC                 1564 	mov	a,r4
   0852 2C                 1565 	add	a,r4
   0853 FC                 1566 	mov	r4,a
   0854 ED                 1567 	mov	a,r5
   0855 33                 1568 	rlc	a
   0856 FD                 1569 	mov	r5,a
   0857                    1570 00126$:
   0857 D5 F0 F7           1571 	djnz	b,00125$
   085A 78 0D              1572 	mov	r0,#_sendRGB_PARM_2
   085C E5 08              1573 	mov	a,_shiftbriteProcessByte_sloc0_1_0
   085E F2                 1574 	movx	@r0,a
   085F 08                 1575 	inc	r0
   0860 E5 09              1576 	mov	a,(_shiftbriteProcessByte_sloc0_1_0 + 1)
   0862 F2                 1577 	movx	@r0,a
   0863 78 0F              1578 	mov	r0,#_sendRGB_PARM_3
   0865 EC                 1579 	mov	a,r4
   0866 F2                 1580 	movx	@r0,a
   0867 08                 1581 	inc	r0
   0868 ED                 1582 	mov	a,r5
   0869 F2                 1583 	movx	@r0,a
   086A 8E 82              1584 	mov	dpl,r6
   086C 8F 83              1585 	mov	dph,r7
   086E 12 06 50           1586 	lcall	_sendRGB
   0871 02 09 54           1587 	ljmp	00110$
   0874                    1588 00102$:
                    0310   1589 	C$shiftbrite.c$165$4$6 ==.
                           1590 ;	apps/shiftbrite/shiftbrite.c:165: hex(rgb,                      hex_chars_per_color) >> -shift,
   0874 78 07              1591 	mov	r0,#_hex_chars_per_color
   0876 79 09              1592 	mov	r1,#_hex_PARM_2
   0878 E2                 1593 	movx	a,@r0
   0879 F3                 1594 	movx	@r1,a
   087A 90 F0 19           1595 	mov	dptr,#_shiftbriteProcessByte_rgb_1_1
   087D 75 F0 60           1596 	mov	b,#0x60
   0880 12 05 BB           1597 	lcall	_hex
   0883 AE 82              1598 	mov	r6,dpl
   0885 AF 83              1599 	mov	r7,dph
   0887 78 08              1600 	mov	r0,#_shift
   0889 E2                 1601 	movx	a,@r0
   088A FC                 1602 	mov	r4,a
   088B E2                 1603 	movx	a,@r0
   088C 33                 1604 	rlc	a
   088D 95 E0              1605 	subb	a,acc
   088F FD                 1606 	mov	r5,a
   0890 C3                 1607 	clr	c
   0891 E4                 1608 	clr	a
   0892 9C                 1609 	subb	a,r4
   0893 FC                 1610 	mov	r4,a
   0894 E4                 1611 	clr	a
   0895 9D                 1612 	subb	a,r5
   0896 FD                 1613 	mov	r5,a
   0897 8C F0              1614 	mov	b,r4
   0899 05 F0              1615 	inc	b
   089B 80 07              1616 	sjmp	00128$
   089D                    1617 00127$:
   089D C3                 1618 	clr	c
   089E EF                 1619 	mov	a,r7
   089F 13                 1620 	rrc	a
   08A0 FF                 1621 	mov	r7,a
   08A1 EE                 1622 	mov	a,r6
   08A2 13                 1623 	rrc	a
   08A3 FE                 1624 	mov	r6,a
   08A4                    1625 00128$:
   08A4 D5 F0 F6           1626 	djnz	b,00127$
                    0343   1627 	C$shiftbrite.c$166$4$6 ==.
                           1628 ;	apps/shiftbrite/shiftbrite.c:166: hex(rgb+hex_chars_per_color,  hex_chars_per_color) >> -shift,
   08A7 78 07              1629 	mov	r0,#_hex_chars_per_color
   08A9 E2                 1630 	movx	a,@r0
   08AA 24 19              1631 	add	a,#_shiftbriteProcessByte_rgb_1_1
   08AC FD                 1632 	mov	r5,a
   08AD 7C 00              1633 	mov	r4,#0x00
   08AF 7B 60              1634 	mov	r3,#0x60
   08B1 78 07              1635 	mov	r0,#_hex_chars_per_color
   08B3 79 09              1636 	mov	r1,#_hex_PARM_2
   08B5 E2                 1637 	movx	a,@r0
   08B6 F3                 1638 	movx	@r1,a
   08B7 8D 82              1639 	mov	dpl,r5
   08B9 8C 83              1640 	mov	dph,r4
   08BB 8B F0              1641 	mov	b,r3
   08BD C0 07              1642 	push	ar7
   08BF C0 06              1643 	push	ar6
   08C1 12 05 BB           1644 	lcall	_hex
   08C4 AC 82              1645 	mov	r4,dpl
   08C6 AD 83              1646 	mov	r5,dph
   08C8 D0 06              1647 	pop	ar6
   08CA D0 07              1648 	pop	ar7
   08CC 78 08              1649 	mov	r0,#_shift
   08CE E2                 1650 	movx	a,@r0
   08CF FA                 1651 	mov	r2,a
   08D0 E2                 1652 	movx	a,@r0
   08D1 33                 1653 	rlc	a
   08D2 95 E0              1654 	subb	a,acc
   08D4 FB                 1655 	mov	r3,a
   08D5 C3                 1656 	clr	c
   08D6 E4                 1657 	clr	a
   08D7 9A                 1658 	subb	a,r2
   08D8 FA                 1659 	mov	r2,a
   08D9 E4                 1660 	clr	a
   08DA 9B                 1661 	subb	a,r3
   08DB FB                 1662 	mov	r3,a
   08DC 8A F0              1663 	mov	b,r2
   08DE 05 F0              1664 	inc	b
   08E0 85 04 08           1665 	mov	_shiftbriteProcessByte_sloc0_1_0,ar4
   08E3 85 05 09           1666 	mov	(_shiftbriteProcessByte_sloc0_1_0 + 1),ar5
   08E6 80 0B              1667 	sjmp	00130$
   08E8                    1668 00129$:
   08E8 C3                 1669 	clr	c
   08E9 E5 09              1670 	mov	a,(_shiftbriteProcessByte_sloc0_1_0 + 1)
   08EB 13                 1671 	rrc	a
   08EC F5 09              1672 	mov	(_shiftbriteProcessByte_sloc0_1_0 + 1),a
   08EE E5 08              1673 	mov	a,_shiftbriteProcessByte_sloc0_1_0
   08F0 13                 1674 	rrc	a
   08F1 F5 08              1675 	mov	_shiftbriteProcessByte_sloc0_1_0,a
   08F3                    1676 00130$:
   08F3 D5 F0 F2           1677 	djnz	b,00129$
                    0392   1678 	C$shiftbrite.c$167$4$6 ==.
                           1679 ;	apps/shiftbrite/shiftbrite.c:167: hex(rgb+hex_chars_per_color*2,hex_chars_per_color) >> -shift
   08F6 78 07              1680 	mov	r0,#_hex_chars_per_color
   08F8 E2                 1681 	movx	a,@r0
   08F9 25 E0              1682 	add	a,acc
   08FB 24 19              1683 	add	a,#_shiftbriteProcessByte_rgb_1_1
   08FD FA                 1684 	mov	r2,a
   08FE 7B 00              1685 	mov	r3,#0x00
   0900 7D 60              1686 	mov	r5,#0x60
   0902 78 07              1687 	mov	r0,#_hex_chars_per_color
   0904 79 09              1688 	mov	r1,#_hex_PARM_2
   0906 E2                 1689 	movx	a,@r0
   0907 F3                 1690 	movx	@r1,a
   0908 8A 82              1691 	mov	dpl,r2
   090A 8B 83              1692 	mov	dph,r3
   090C 8D F0              1693 	mov	b,r5
   090E C0 07              1694 	push	ar7
   0910 C0 06              1695 	push	ar6
   0912 12 05 BB           1696 	lcall	_hex
   0915 AC 82              1697 	mov	r4,dpl
   0917 AD 83              1698 	mov	r5,dph
   0919 D0 06              1699 	pop	ar6
   091B D0 07              1700 	pop	ar7
   091D 78 08              1701 	mov	r0,#_shift
   091F E2                 1702 	movx	a,@r0
   0920 FA                 1703 	mov	r2,a
   0921 E2                 1704 	movx	a,@r0
   0922 33                 1705 	rlc	a
   0923 95 E0              1706 	subb	a,acc
   0925 FB                 1707 	mov	r3,a
   0926 C3                 1708 	clr	c
   0927 E4                 1709 	clr	a
   0928 9A                 1710 	subb	a,r2
   0929 FA                 1711 	mov	r2,a
   092A E4                 1712 	clr	a
   092B 9B                 1713 	subb	a,r3
   092C FB                 1714 	mov	r3,a
   092D 8A F0              1715 	mov	b,r2
   092F 05 F0              1716 	inc	b
   0931 80 07              1717 	sjmp	00132$
   0933                    1718 00131$:
   0933 C3                 1719 	clr	c
   0934 ED                 1720 	mov	a,r5
   0935 13                 1721 	rrc	a
   0936 FD                 1722 	mov	r5,a
   0937 EC                 1723 	mov	a,r4
   0938 13                 1724 	rrc	a
   0939 FC                 1725 	mov	r4,a
   093A                    1726 00132$:
   093A D5 F0 F6           1727 	djnz	b,00131$
   093D 78 0D              1728 	mov	r0,#_sendRGB_PARM_2
   093F E5 08              1729 	mov	a,_shiftbriteProcessByte_sloc0_1_0
   0941 F2                 1730 	movx	@r0,a
   0942 08                 1731 	inc	r0
   0943 E5 09              1732 	mov	a,(_shiftbriteProcessByte_sloc0_1_0 + 1)
   0945 F2                 1733 	movx	@r0,a
   0946 78 0F              1734 	mov	r0,#_sendRGB_PARM_3
   0948 EC                 1735 	mov	a,r4
   0949 F2                 1736 	movx	@r0,a
   094A 08                 1737 	inc	r0
   094B ED                 1738 	mov	a,r5
   094C F2                 1739 	movx	@r0,a
   094D 8E 82              1740 	mov	dpl,r6
   094F 8F 83              1741 	mov	dph,r7
   0951 12 06 50           1742 	lcall	_sendRGB
   0954                    1743 00110$:
                    03F0   1744 	C$shiftbrite.c$172$1$1 ==.
                    03F0   1745 	XG$shiftbriteProcessByte$0$0 ==.
   0954 22                 1746 	ret
                           1747 ;------------------------------------------------------------
                           1748 ;Allocation info for local variables in function 'shiftbriteService'
                           1749 ;------------------------------------------------------------
                    03F1   1750 	G$shiftbriteService$0$0 ==.
                    03F1   1751 	C$shiftbrite.c$174$1$1 ==.
                           1752 ;	apps/shiftbrite/shiftbrite.c:174: void shiftbriteService()
                           1753 ;	-----------------------------------------
                           1754 ;	 function shiftbriteService
                           1755 ;	-----------------------------------------
   0955                    1756 _shiftbriteService:
                    03F1   1757 	C$shiftbrite.c$176$1$1 ==.
                           1758 ;	apps/shiftbrite/shiftbrite.c:176: if (!radioComRxAvailable()){ return; }
   0955 12 0C E4           1759 	lcall	_radioComRxAvailable
   0958 E5 82              1760 	mov	a,dpl
   095A 70 02              1761 	jnz	00106$
                    03F8   1762 	C$shiftbrite.c$178$1$1 ==.
                           1763 ;	apps/shiftbrite/shiftbrite.c:178: do
   095C 80 54              1764 	sjmp	00111$
   095E                    1765 00106$:
                    03FA   1766 	C$shiftbrite.c$180$2$3 ==.
                           1767 ;	apps/shiftbrite/shiftbrite.c:180: char c = radioComRxReceiveByte();
   095E 12 0C EB           1768 	lcall	_radioComRxReceiveByte
   0961 AF 82              1769 	mov	r7,dpl
                    03FF   1770 	C$shiftbrite.c$181$2$3 ==.
                           1771 ;	apps/shiftbrite/shiftbrite.c:181: if(radioComTxAvailable() && param_echo_on)
   0963 C0 07              1772 	push	ar7
   0965 12 0D 73           1773 	lcall	_radioComTxAvailable
   0968 E5 82              1774 	mov	a,dpl
   096A D0 07              1775 	pop	ar7
   096C 60 21              1776 	jz	00104$
   096E 90 1D 7F           1777 	mov	dptr,#_param_echo_on
   0971 E4                 1778 	clr	a
   0972 93                 1779 	movc	a,@a+dptr
   0973 FB                 1780 	mov	r3,a
   0974 74 01              1781 	mov	a,#0x01
   0976 93                 1782 	movc	a,@a+dptr
   0977 FC                 1783 	mov	r4,a
   0978 74 02              1784 	mov	a,#0x02
   097A 93                 1785 	movc	a,@a+dptr
   097B FD                 1786 	mov	r5,a
   097C 74 03              1787 	mov	a,#0x03
   097E 93                 1788 	movc	a,@a+dptr
   097F FE                 1789 	mov	r6,a
   0980 EB                 1790 	mov	a,r3
   0981 4C                 1791 	orl	a,r4
   0982 4D                 1792 	orl	a,r5
   0983 4E                 1793 	orl	a,r6
   0984 60 09              1794 	jz	00104$
                    0422   1795 	C$shiftbrite.c$183$3$4 ==.
                           1796 ;	apps/shiftbrite/shiftbrite.c:183: radioComTxSendByte(c);
   0986 8F 82              1797 	mov	dpl,r7
   0988 C0 07              1798 	push	ar7
   098A 12 0D 8A           1799 	lcall	_radioComTxSendByte
   098D D0 07              1800 	pop	ar7
   098F                    1801 00104$:
                    042B   1802 	C$shiftbrite.c$185$2$3 ==.
                           1803 ;	apps/shiftbrite/shiftbrite.c:185: shiftbriteProcessByte(c);
   098F 8F 82              1804 	mov	dpl,r7
   0991 12 07 65           1805 	lcall	_shiftbriteProcessByte
                    0430   1806 	C$shiftbrite.c$187$1$1 ==.
                           1807 ;	apps/shiftbrite/shiftbrite.c:187: while(radioComRxAvailable());
   0994 12 0C E4           1808 	lcall	_radioComRxAvailable
   0997 E5 82              1809 	mov	a,dpl
   0999 70 C3              1810 	jnz	00106$
                    0437   1811 	C$shiftbrite.c$190$1$1 ==.
                           1812 ;	apps/shiftbrite/shiftbrite.c:190: radioLastActivity = (uint8)getMs();
   099B 12 11 8A           1813 	lcall	_getMs
   099E AC 82              1814 	mov	r4,dpl
   09A0 AD 83              1815 	mov	r5,dph
   09A2 AE F0              1816 	mov	r6,b
   09A4 FF                 1817 	mov	r7,a
   09A5 78 04              1818 	mov	r0,#_radioLastActivity
   09A7 EC                 1819 	mov	a,r4
   09A8 F2                 1820 	movx	@r0,a
                    0445   1821 	C$shiftbrite.c$194$1$1 ==.
                           1822 ;	apps/shiftbrite/shiftbrite.c:194: if (!radioBlinkActive)
   09A9 20 00 06           1823 	jb	_radioBlinkActive,00111$
                    0448   1824 	C$shiftbrite.c$196$2$5 ==.
                           1825 ;	apps/shiftbrite/shiftbrite.c:196: radioBlinkActive = 1;
   09AC D2 00              1826 	setb	_radioBlinkActive
                    044A   1827 	C$shiftbrite.c$197$2$5 ==.
                           1828 ;	apps/shiftbrite/shiftbrite.c:197: radioBlinkStart = radioLastActivity;
   09AE 78 05              1829 	mov	r0,#_radioBlinkStart
   09B0 EC                 1830 	mov	a,r4
   09B1 F2                 1831 	movx	@r0,a
   09B2                    1832 00111$:
                    044E   1833 	C$shiftbrite.c$199$2$1 ==.
                    044E   1834 	XG$shiftbriteService$0$0 ==.
   09B2 22                 1835 	ret
                           1836 ;------------------------------------------------------------
                           1837 ;Allocation info for local variables in function 'shiftbriteInit'
                           1838 ;------------------------------------------------------------
                    044F   1839 	G$shiftbriteInit$0$0 ==.
                    044F   1840 	C$shiftbrite.c$201$2$1 ==.
                           1841 ;	apps/shiftbrite/shiftbrite.c:201: void shiftbriteInit()
                           1842 ;	-----------------------------------------
                           1843 ;	 function shiftbriteInit
                           1844 ;	-----------------------------------------
   09B3                    1845 _shiftbriteInit:
                    044F   1846 	C$shiftbrite.c$203$1$1 ==.
                           1847 ;	apps/shiftbrite/shiftbrite.c:203: input_bits = restrictRange(param_input_bits,1,16); // allow up to 16 bits = 4 hex digits
   09B3 90 1D 7B           1848 	mov	dptr,#_param_input_bits
   09B6 E4                 1849 	clr	a
   09B7 93                 1850 	movc	a,@a+dptr
   09B8 FC                 1851 	mov	r4,a
   09B9 74 01              1852 	mov	a,#0x01
   09BB 93                 1853 	movc	a,@a+dptr
   09BC FD                 1854 	mov	r5,a
   09BD 74 02              1855 	mov	a,#0x02
   09BF 93                 1856 	movc	a,@a+dptr
   09C0 FE                 1857 	mov	r6,a
   09C1 74 03              1858 	mov	a,#0x03
   09C3 93                 1859 	movc	a,@a+dptr
   09C4 FF                 1860 	mov	r7,a
   09C5 78 11              1861 	mov	r0,#_restrictRange_PARM_2
   09C7 74 01              1862 	mov	a,#0x01
   09C9 F2                 1863 	movx	@r0,a
   09CA 08                 1864 	inc	r0
   09CB E4                 1865 	clr	a
   09CC F2                 1866 	movx	@r0,a
   09CD 08                 1867 	inc	r0
   09CE F2                 1868 	movx	@r0,a
   09CF 08                 1869 	inc	r0
   09D0 F2                 1870 	movx	@r0,a
   09D1 78 15              1871 	mov	r0,#_restrictRange_PARM_3
   09D3 74 10              1872 	mov	a,#0x10
   09D5 F2                 1873 	movx	@r0,a
   09D6 08                 1874 	inc	r0
   09D7 E4                 1875 	clr	a
   09D8 F2                 1876 	movx	@r0,a
   09D9 08                 1877 	inc	r0
   09DA F2                 1878 	movx	@r0,a
   09DB 08                 1879 	inc	r0
   09DC F2                 1880 	movx	@r0,a
   09DD 8C 82              1881 	mov	dpl,r4
   09DF 8D 83              1882 	mov	dph,r5
   09E1 8E F0              1883 	mov	b,r6
   09E3 EF                 1884 	mov	a,r7
   09E4 12 06 F7           1885 	lcall	_restrictRange
   09E7 AC 82              1886 	mov	r4,dpl
   09E9 AD 83              1887 	mov	r5,dph
   09EB 78 06              1888 	mov	r0,#_input_bits
   09ED EC                 1889 	mov	a,r4
   09EE F2                 1890 	movx	@r0,a
                    048B   1891 	C$shiftbrite.c$204$1$1 ==.
                           1892 ;	apps/shiftbrite/shiftbrite.c:204: hex_chars_per_color = ((input_bits-1) >> 2) + 1;
   09EF 8C 06              1893 	mov	ar6,r4
   09F1 7F 00              1894 	mov	r7,#0x00
   09F3 1E                 1895 	dec	r6
   09F4 BE FF 01           1896 	cjne	r6,#0xFF,00103$
   09F7 1F                 1897 	dec	r7
   09F8                    1898 00103$:
   09F8 EF                 1899 	mov	a,r7
   09F9 A2 E7              1900 	mov	c,acc.7
   09FB 13                 1901 	rrc	a
   09FC CE                 1902 	xch	a,r6
   09FD 13                 1903 	rrc	a
   09FE CE                 1904 	xch	a,r6
   09FF A2 E7              1905 	mov	c,acc.7
   0A01 13                 1906 	rrc	a
   0A02 CE                 1907 	xch	a,r6
   0A03 13                 1908 	rrc	a
   0A04 CE                 1909 	xch	a,r6
   0A05 0E                 1910 	inc	r6
   0A06 78 07              1911 	mov	r0,#_hex_chars_per_color
   0A08 EE                 1912 	mov	a,r6
   0A09 F2                 1913 	movx	@r0,a
                    04A6   1914 	C$shiftbrite.c$205$1$1 ==.
                           1915 ;	apps/shiftbrite/shiftbrite.c:205: shift = 10 - input_bits;
   0A0A 74 0A              1916 	mov	a,#0x0A
   0A0C C3                 1917 	clr	c
   0A0D 9C                 1918 	subb	a,r4
   0A0E 78 08              1919 	mov	r0,#_shift
   0A10 F2                 1920 	movx	@r0,a
                    04AD   1921 	C$shiftbrite.c$207$1$1 ==.
                           1922 ;	apps/shiftbrite/shiftbrite.c:207: SHIFTBRITE_DISABLE = 1; // disable shiftbrites until a valid color is sent
   0A11 D2 94              1923 	setb	_P1_4
                    04AF   1924 	C$shiftbrite.c$208$1$1 ==.
                           1925 ;	apps/shiftbrite/shiftbrite.c:208: SHIFTBRITE_CLOCK = 0; // clock low
   0A13 C2 95              1926 	clr	_P1_5
                    04B1   1927 	C$shiftbrite.c$209$1$1 ==.
                           1928 ;	apps/shiftbrite/shiftbrite.c:209: SHIFTBRITE_LATCH = 0; // prevent unintended latching
   0A15 C2 97              1929 	clr	_P1_7
                    04B3   1930 	C$shiftbrite.c$210$1$1 ==.
                           1931 ;	apps/shiftbrite/shiftbrite.c:210: P1DIR |= (1<<4); // P1_4 = Disable !Enable
   0A17 43 FE 10           1932 	orl	_P1DIR,#0x10
                    04B6   1933 	C$shiftbrite.c$211$1$1 ==.
                           1934 ;	apps/shiftbrite/shiftbrite.c:211: P1DIR |= (1<<5); // P1_5 = Clock
   0A1A 43 FE 20           1935 	orl	_P1DIR,#0x20
                    04B9   1936 	C$shiftbrite.c$212$1$1 ==.
                           1937 ;	apps/shiftbrite/shiftbrite.c:212: P1DIR |= (1<<6); // P1_6 = Data
   0A1D 43 FE 40           1938 	orl	_P1DIR,#0x40
                    04BC   1939 	C$shiftbrite.c$213$1$1 ==.
                           1940 ;	apps/shiftbrite/shiftbrite.c:213: P1DIR |= (1<<7); // P1_7 = Latch
   0A20 43 FE 80           1941 	orl	_P1DIR,#0x80
                    04BF   1942 	C$shiftbrite.c$214$1$1 ==.
                    04BF   1943 	XG$shiftbriteInit$0$0 ==.
   0A23 22                 1944 	ret
                           1945 ;------------------------------------------------------------
                           1946 ;Allocation info for local variables in function 'updateLeds'
                           1947 ;------------------------------------------------------------
                    04C0   1948 	G$updateLeds$0$0 ==.
                    04C0   1949 	C$shiftbrite.c$216$1$1 ==.
                           1950 ;	apps/shiftbrite/shiftbrite.c:216: void updateLeds()
                           1951 ;	-----------------------------------------
                           1952 ;	 function updateLeds
                           1953 ;	-----------------------------------------
   0A24                    1954 _updateLeds:
                    04C0   1955 	C$shiftbrite.c$218$1$1 ==.
                           1956 ;	apps/shiftbrite/shiftbrite.c:218: uint8 time = (uint8)getMs();
   0A24 12 11 8A           1957 	lcall	_getMs
   0A27 AC 82              1958 	mov	r4,dpl
   0A29 AD 83              1959 	mov	r5,dph
   0A2B AE F0              1960 	mov	r6,b
   0A2D FF                 1961 	mov	r7,a
                    04CA   1962 	C$shiftbrite.c$220$1$1 ==.
                           1963 ;	apps/shiftbrite/shiftbrite.c:220: if (radioBlinkActive)
   0A2E 30 00 24           1964 	jnb	_radioBlinkActive,00104$
                    04CD   1965 	C$shiftbrite.c$223$3$3 ==.
                           1966 ;	apps/shiftbrite/shiftbrite.c:223: LED_YELLOW((uint8)(time - radioBlinkStart) & 64);
   0A31 78 05              1967 	mov	r0,#_radioBlinkStart
   0A33 D3                 1968 	setb	c
   0A34 E2                 1969 	movx	a,@r0
   0A35 9C                 1970 	subb	a,r4
   0A36 F4                 1971 	cpl	a
   0A37 30 E6 05           1972 	jnb	acc.6,00108$
   0A3A 43 FF 04           1973 	orl	_P2DIR,#0x04
   0A3D 80 07              1974 	sjmp	00109$
   0A3F                    1975 00108$:
   0A3F AF FF              1976 	mov	r7,_P2DIR
   0A41 53 07 FB           1977 	anl	ar7,#0xFB
   0A44 8F FF              1978 	mov	_P2DIR,r7
   0A46                    1979 00109$:
                    04E2   1980 	C$shiftbrite.c$225$2$2 ==.
                           1981 ;	apps/shiftbrite/shiftbrite.c:225: if ((uint8)(time - radioLastActivity) > 96)
   0A46 78 04              1982 	mov	r0,#_radioLastActivity
   0A48 D3                 1983 	setb	c
   0A49 E2                 1984 	movx	a,@r0
   0A4A 9C                 1985 	subb	a,r4
   0A4B F4                 1986 	cpl	a
   0A4C FC                 1987 	mov  r4,a
   0A4D 24 9F              1988 	add	a,#0xff - 0x60
   0A4F 50 07              1989 	jnc	00105$
                    04ED   1990 	C$shiftbrite.c$228$3$4 ==.
                           1991 ;	apps/shiftbrite/shiftbrite.c:228: radioBlinkActive = 0;
   0A51 C2 00              1992 	clr	_radioBlinkActive
   0A53 80 03              1993 	sjmp	00105$
   0A55                    1994 00104$:
                    04F1   1995 	C$shiftbrite.c$234$3$6 ==.
                           1996 ;	apps/shiftbrite/shiftbrite.c:234: LED_YELLOW(1);
   0A55 43 FF 04           1997 	orl	_P2DIR,#0x04
   0A58                    1998 00105$:
                    04F4   1999 	C$shiftbrite.c$237$1$1 ==.
                           2000 ;	apps/shiftbrite/shiftbrite.c:237: usbShowStatusWithGreenLed();
   0A58 12 1B AB           2001 	lcall	_usbShowStatusWithGreenLed
                    04F7   2002 	C$shiftbrite.c$239$1$1 ==.
                    04F7   2003 	XG$updateLeds$0$0 ==.
   0A5B 22                 2004 	ret
                           2005 ;------------------------------------------------------------
                           2006 ;Allocation info for local variables in function 'main'
                           2007 ;------------------------------------------------------------
                    04F8   2008 	G$main$0$0 ==.
                    04F8   2009 	C$shiftbrite.c$241$1$1 ==.
                           2010 ;	apps/shiftbrite/shiftbrite.c:241: void main()
                           2011 ;	-----------------------------------------
                           2012 ;	 function main
                           2013 ;	-----------------------------------------
   0A5C                    2014 _main:
                    04F8   2015 	C$shiftbrite.c$243$1$1 ==.
                           2016 ;	apps/shiftbrite/shiftbrite.c:243: systemInit();
   0A5C 12 0D D2           2017 	lcall	_systemInit
                    04FB   2018 	C$shiftbrite.c$244$1$1 ==.
                           2019 ;	apps/shiftbrite/shiftbrite.c:244: usbInit();
   0A5F 12 11 F1           2020 	lcall	_usbInit
                    04FE   2021 	C$shiftbrite.c$245$1$1 ==.
                           2022 ;	apps/shiftbrite/shiftbrite.c:245: shiftbriteInit();
   0A62 12 09 B3           2023 	lcall	_shiftbriteInit
                    0501   2024 	C$shiftbrite.c$247$1$1 ==.
                           2025 ;	apps/shiftbrite/shiftbrite.c:247: radioComInit();
   0A65 12 0C 79           2026 	lcall	_radioComInit
                    0504   2027 	C$shiftbrite.c$249$1$1 ==.
                           2028 ;	apps/shiftbrite/shiftbrite.c:249: while(1)
   0A68                    2029 00102$:
                    0504   2030 	C$shiftbrite.c$251$2$2 ==.
                           2031 ;	apps/shiftbrite/shiftbrite.c:251: boardService();
   0A68 12 0D DF           2032 	lcall	_boardService
                    0507   2033 	C$shiftbrite.c$252$2$2 ==.
                           2034 ;	apps/shiftbrite/shiftbrite.c:252: updateLeds();
   0A6B 12 0A 24           2035 	lcall	_updateLeds
                    050A   2036 	C$shiftbrite.c$254$2$2 ==.
                           2037 ;	apps/shiftbrite/shiftbrite.c:254: radioComTxService();
   0A6E 12 0D 44           2038 	lcall	_radioComTxService
                    050D   2039 	C$shiftbrite.c$255$2$2 ==.
                           2040 ;	apps/shiftbrite/shiftbrite.c:255: usbComService();
   0A71 12 10 03           2041 	lcall	_usbComService
                    0510   2042 	C$shiftbrite.c$257$2$2 ==.
                           2043 ;	apps/shiftbrite/shiftbrite.c:257: shiftbriteService();
   0A74 12 09 55           2044 	lcall	_shiftbriteService
   0A77 80 EF              2045 	sjmp	00102$
                    0515   2046 	C$shiftbrite.c$259$1$1 ==.
                    0515   2047 	XG$main$0$0 ==.
   0A79 22                 2048 	ret
                           2049 	.area CSEG    (CODE)
                           2050 	.area CONST   (CODE)
                    0000   2051 G$param_input_bits$0$0 == .
   1D7B                    2052 _param_input_bits:
   1D7B 08 00 00 00        2053 	.byte #0x08,#0x00,#0x00,#0x00	;  8
                    0004   2054 G$param_echo_on$0$0 == .
   1D7F                    2055 _param_echo_on:
   1D7F 01 00 00 00        2056 	.byte #0x01,#0x00,#0x00,#0x00	;  1
                           2057 	.area XINIT   (CODE)
                           2058 	.area CABS    (ABS,CODE)
