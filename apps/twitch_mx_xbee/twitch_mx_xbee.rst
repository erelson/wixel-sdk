                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Nov 23 22:08:33 2012
                              5 ;--------------------------------------------------------
                              6 	.module twitch_mx_xbee
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_framing_error_ms
                             13 	.globl _param_arduino_DTR_pin
                             14 	.globl _param_CD_pin
                             15 	.globl _param_DSR_pin
                             16 	.globl _param_RTS_pin
                             17 	.globl _param_DTR_pin
                             18 	.globl _param_nCD_pin
                             19 	.globl _param_nDSR_pin
                             20 	.globl _param_nRTS_pin
                             21 	.globl _param_nDTR_pin
                             22 	.globl _param_baud_rate
                             23 	.globl _param_serial_mode
                             24 	.globl _main
                             25 	.globl _uartToRadioService
                             26 	.globl _errorService
                             27 	.globl _errorOccurred
                             28 	.globl _ioTxSignals
                             29 	.globl _ioRxSignals
                             30 	.globl _updateLeds
                             31 	.globl _uart1RxReceiveByte
                             32 	.globl _uart1RxAvailable
                             33 	.globl _uart1SetBaudRate
                             34 	.globl _uart1Init
                             35 	.globl _radioComRxControlSignals
                             36 	.globl _radioComTxControlSignals
                             37 	.globl _radioComTxSendByte
                             38 	.globl _radioComTxAvailable
                             39 	.globl _radioComTxService
                             40 	.globl _radioComRxReceiveByte
                             41 	.globl _radioComRxAvailable
                             42 	.globl _radioComInit
                             43 	.globl _radioLinkConnected
                             44 	.globl _isPinHigh
                             45 	.globl _setDigitalOutput
                             46 	.globl _delayMs
                             47 	.globl _getMs
                             48 	.globl _boardService
                             49 	.globl _systemInit
                             50 	.globl _lastErrorTime
                             51 	.globl _lookH
                             52 	.globl _lookV
                             53 	.globl _walkH
                             54 	.globl _walkV
                             55 	.globl _checksum_cmdr
                             56 	.globl _index_cmdr
                             57 	.globl _vals
                             58 	.globl _errorOccurredRecently
                             59 	.globl _framingErrorActive
                             60 	.globl _uartRxDisabled
                             61 	.globl _CmdrReadMsgs
                             62 ;--------------------------------------------------------
                             63 ; special function registers
                             64 ;--------------------------------------------------------
                             65 	.area RSEG    (ABS,DATA)
   0000                      66 	.org 0x0000
                    0080     67 Ftwitch_mx_xbee$P0$0$0 == 0x0080
                    0080     68 _P0	=	0x0080
                    0081     69 Ftwitch_mx_xbee$SP$0$0 == 0x0081
                    0081     70 _SP	=	0x0081
                    0082     71 Ftwitch_mx_xbee$DPL0$0$0 == 0x0082
                    0082     72 _DPL0	=	0x0082
                    0083     73 Ftwitch_mx_xbee$DPH0$0$0 == 0x0083
                    0083     74 _DPH0	=	0x0083
                    0084     75 Ftwitch_mx_xbee$DPL1$0$0 == 0x0084
                    0084     76 _DPL1	=	0x0084
                    0085     77 Ftwitch_mx_xbee$DPH1$0$0 == 0x0085
                    0085     78 _DPH1	=	0x0085
                    0086     79 Ftwitch_mx_xbee$U0CSR$0$0 == 0x0086
                    0086     80 _U0CSR	=	0x0086
                    0087     81 Ftwitch_mx_xbee$PCON$0$0 == 0x0087
                    0087     82 _PCON	=	0x0087
                    0088     83 Ftwitch_mx_xbee$TCON$0$0 == 0x0088
                    0088     84 _TCON	=	0x0088
                    0089     85 Ftwitch_mx_xbee$P0IFG$0$0 == 0x0089
                    0089     86 _P0IFG	=	0x0089
                    008A     87 Ftwitch_mx_xbee$P1IFG$0$0 == 0x008a
                    008A     88 _P1IFG	=	0x008a
                    008B     89 Ftwitch_mx_xbee$P2IFG$0$0 == 0x008b
                    008B     90 _P2IFG	=	0x008b
                    008C     91 Ftwitch_mx_xbee$PICTL$0$0 == 0x008c
                    008C     92 _PICTL	=	0x008c
                    008D     93 Ftwitch_mx_xbee$P1IEN$0$0 == 0x008d
                    008D     94 _P1IEN	=	0x008d
                    008F     95 Ftwitch_mx_xbee$P0INP$0$0 == 0x008f
                    008F     96 _P0INP	=	0x008f
                    0090     97 Ftwitch_mx_xbee$P1$0$0 == 0x0090
                    0090     98 _P1	=	0x0090
                    0091     99 Ftwitch_mx_xbee$RFIM$0$0 == 0x0091
                    0091    100 _RFIM	=	0x0091
                    0092    101 Ftwitch_mx_xbee$DPS$0$0 == 0x0092
                    0092    102 _DPS	=	0x0092
                    0093    103 Ftwitch_mx_xbee$MPAGE$0$0 == 0x0093
                    0093    104 _MPAGE	=	0x0093
                    0095    105 Ftwitch_mx_xbee$ENDIAN$0$0 == 0x0095
                    0095    106 _ENDIAN	=	0x0095
                    0098    107 Ftwitch_mx_xbee$S0CON$0$0 == 0x0098
                    0098    108 _S0CON	=	0x0098
                    009A    109 Ftwitch_mx_xbee$IEN2$0$0 == 0x009a
                    009A    110 _IEN2	=	0x009a
                    009B    111 Ftwitch_mx_xbee$S1CON$0$0 == 0x009b
                    009B    112 _S1CON	=	0x009b
                    009C    113 Ftwitch_mx_xbee$T2CT$0$0 == 0x009c
                    009C    114 _T2CT	=	0x009c
                    009D    115 Ftwitch_mx_xbee$T2PR$0$0 == 0x009d
                    009D    116 _T2PR	=	0x009d
                    009E    117 Ftwitch_mx_xbee$T2CTL$0$0 == 0x009e
                    009E    118 _T2CTL	=	0x009e
                    00A0    119 Ftwitch_mx_xbee$P2$0$0 == 0x00a0
                    00A0    120 _P2	=	0x00a0
                    00A1    121 Ftwitch_mx_xbee$WORIRQ$0$0 == 0x00a1
                    00A1    122 _WORIRQ	=	0x00a1
                    00A2    123 Ftwitch_mx_xbee$WORCTRL$0$0 == 0x00a2
                    00A2    124 _WORCTRL	=	0x00a2
                    00A3    125 Ftwitch_mx_xbee$WOREVT0$0$0 == 0x00a3
                    00A3    126 _WOREVT0	=	0x00a3
                    00A4    127 Ftwitch_mx_xbee$WOREVT1$0$0 == 0x00a4
                    00A4    128 _WOREVT1	=	0x00a4
                    00A5    129 Ftwitch_mx_xbee$WORTIME0$0$0 == 0x00a5
                    00A5    130 _WORTIME0	=	0x00a5
                    00A6    131 Ftwitch_mx_xbee$WORTIME1$0$0 == 0x00a6
                    00A6    132 _WORTIME1	=	0x00a6
                    00A8    133 Ftwitch_mx_xbee$IEN0$0$0 == 0x00a8
                    00A8    134 _IEN0	=	0x00a8
                    00A9    135 Ftwitch_mx_xbee$IP0$0$0 == 0x00a9
                    00A9    136 _IP0	=	0x00a9
                    00AB    137 Ftwitch_mx_xbee$FWT$0$0 == 0x00ab
                    00AB    138 _FWT	=	0x00ab
                    00AC    139 Ftwitch_mx_xbee$FADDRL$0$0 == 0x00ac
                    00AC    140 _FADDRL	=	0x00ac
                    00AD    141 Ftwitch_mx_xbee$FADDRH$0$0 == 0x00ad
                    00AD    142 _FADDRH	=	0x00ad
                    00AE    143 Ftwitch_mx_xbee$FCTL$0$0 == 0x00ae
                    00AE    144 _FCTL	=	0x00ae
                    00AF    145 Ftwitch_mx_xbee$FWDATA$0$0 == 0x00af
                    00AF    146 _FWDATA	=	0x00af
                    00B1    147 Ftwitch_mx_xbee$ENCDI$0$0 == 0x00b1
                    00B1    148 _ENCDI	=	0x00b1
                    00B2    149 Ftwitch_mx_xbee$ENCDO$0$0 == 0x00b2
                    00B2    150 _ENCDO	=	0x00b2
                    00B3    151 Ftwitch_mx_xbee$ENCCS$0$0 == 0x00b3
                    00B3    152 _ENCCS	=	0x00b3
                    00B4    153 Ftwitch_mx_xbee$ADCCON1$0$0 == 0x00b4
                    00B4    154 _ADCCON1	=	0x00b4
                    00B5    155 Ftwitch_mx_xbee$ADCCON2$0$0 == 0x00b5
                    00B5    156 _ADCCON2	=	0x00b5
                    00B6    157 Ftwitch_mx_xbee$ADCCON3$0$0 == 0x00b6
                    00B6    158 _ADCCON3	=	0x00b6
                    00B8    159 Ftwitch_mx_xbee$IEN1$0$0 == 0x00b8
                    00B8    160 _IEN1	=	0x00b8
                    00B9    161 Ftwitch_mx_xbee$IP1$0$0 == 0x00b9
                    00B9    162 _IP1	=	0x00b9
                    00BA    163 Ftwitch_mx_xbee$ADCL$0$0 == 0x00ba
                    00BA    164 _ADCL	=	0x00ba
                    00BB    165 Ftwitch_mx_xbee$ADCH$0$0 == 0x00bb
                    00BB    166 _ADCH	=	0x00bb
                    00BC    167 Ftwitch_mx_xbee$RNDL$0$0 == 0x00bc
                    00BC    168 _RNDL	=	0x00bc
                    00BD    169 Ftwitch_mx_xbee$RNDH$0$0 == 0x00bd
                    00BD    170 _RNDH	=	0x00bd
                    00BE    171 Ftwitch_mx_xbee$SLEEP$0$0 == 0x00be
                    00BE    172 _SLEEP	=	0x00be
                    00C0    173 Ftwitch_mx_xbee$IRCON$0$0 == 0x00c0
                    00C0    174 _IRCON	=	0x00c0
                    00C1    175 Ftwitch_mx_xbee$U0DBUF$0$0 == 0x00c1
                    00C1    176 _U0DBUF	=	0x00c1
                    00C2    177 Ftwitch_mx_xbee$U0BAUD$0$0 == 0x00c2
                    00C2    178 _U0BAUD	=	0x00c2
                    00C4    179 Ftwitch_mx_xbee$U0UCR$0$0 == 0x00c4
                    00C4    180 _U0UCR	=	0x00c4
                    00C5    181 Ftwitch_mx_xbee$U0GCR$0$0 == 0x00c5
                    00C5    182 _U0GCR	=	0x00c5
                    00C6    183 Ftwitch_mx_xbee$CLKCON$0$0 == 0x00c6
                    00C6    184 _CLKCON	=	0x00c6
                    00C7    185 Ftwitch_mx_xbee$MEMCTR$0$0 == 0x00c7
                    00C7    186 _MEMCTR	=	0x00c7
                    00C9    187 Ftwitch_mx_xbee$WDCTL$0$0 == 0x00c9
                    00C9    188 _WDCTL	=	0x00c9
                    00CA    189 Ftwitch_mx_xbee$T3CNT$0$0 == 0x00ca
                    00CA    190 _T3CNT	=	0x00ca
                    00CB    191 Ftwitch_mx_xbee$T3CTL$0$0 == 0x00cb
                    00CB    192 _T3CTL	=	0x00cb
                    00CC    193 Ftwitch_mx_xbee$T3CCTL0$0$0 == 0x00cc
                    00CC    194 _T3CCTL0	=	0x00cc
                    00CD    195 Ftwitch_mx_xbee$T3CC0$0$0 == 0x00cd
                    00CD    196 _T3CC0	=	0x00cd
                    00CE    197 Ftwitch_mx_xbee$T3CCTL1$0$0 == 0x00ce
                    00CE    198 _T3CCTL1	=	0x00ce
                    00CF    199 Ftwitch_mx_xbee$T3CC1$0$0 == 0x00cf
                    00CF    200 _T3CC1	=	0x00cf
                    00D0    201 Ftwitch_mx_xbee$PSW$0$0 == 0x00d0
                    00D0    202 _PSW	=	0x00d0
                    00D1    203 Ftwitch_mx_xbee$DMAIRQ$0$0 == 0x00d1
                    00D1    204 _DMAIRQ	=	0x00d1
                    00D2    205 Ftwitch_mx_xbee$DMA1CFGL$0$0 == 0x00d2
                    00D2    206 _DMA1CFGL	=	0x00d2
                    00D3    207 Ftwitch_mx_xbee$DMA1CFGH$0$0 == 0x00d3
                    00D3    208 _DMA1CFGH	=	0x00d3
                    00D4    209 Ftwitch_mx_xbee$DMA0CFGL$0$0 == 0x00d4
                    00D4    210 _DMA0CFGL	=	0x00d4
                    00D5    211 Ftwitch_mx_xbee$DMA0CFGH$0$0 == 0x00d5
                    00D5    212 _DMA0CFGH	=	0x00d5
                    00D6    213 Ftwitch_mx_xbee$DMAARM$0$0 == 0x00d6
                    00D6    214 _DMAARM	=	0x00d6
                    00D7    215 Ftwitch_mx_xbee$DMAREQ$0$0 == 0x00d7
                    00D7    216 _DMAREQ	=	0x00d7
                    00D8    217 Ftwitch_mx_xbee$TIMIF$0$0 == 0x00d8
                    00D8    218 _TIMIF	=	0x00d8
                    00D9    219 Ftwitch_mx_xbee$RFD$0$0 == 0x00d9
                    00D9    220 _RFD	=	0x00d9
                    00DA    221 Ftwitch_mx_xbee$T1CC0L$0$0 == 0x00da
                    00DA    222 _T1CC0L	=	0x00da
                    00DB    223 Ftwitch_mx_xbee$T1CC0H$0$0 == 0x00db
                    00DB    224 _T1CC0H	=	0x00db
                    00DC    225 Ftwitch_mx_xbee$T1CC1L$0$0 == 0x00dc
                    00DC    226 _T1CC1L	=	0x00dc
                    00DD    227 Ftwitch_mx_xbee$T1CC1H$0$0 == 0x00dd
                    00DD    228 _T1CC1H	=	0x00dd
                    00DE    229 Ftwitch_mx_xbee$T1CC2L$0$0 == 0x00de
                    00DE    230 _T1CC2L	=	0x00de
                    00DF    231 Ftwitch_mx_xbee$T1CC2H$0$0 == 0x00df
                    00DF    232 _T1CC2H	=	0x00df
                    00E0    233 Ftwitch_mx_xbee$ACC$0$0 == 0x00e0
                    00E0    234 _ACC	=	0x00e0
                    00E1    235 Ftwitch_mx_xbee$RFST$0$0 == 0x00e1
                    00E1    236 _RFST	=	0x00e1
                    00E2    237 Ftwitch_mx_xbee$T1CNTL$0$0 == 0x00e2
                    00E2    238 _T1CNTL	=	0x00e2
                    00E3    239 Ftwitch_mx_xbee$T1CNTH$0$0 == 0x00e3
                    00E3    240 _T1CNTH	=	0x00e3
                    00E4    241 Ftwitch_mx_xbee$T1CTL$0$0 == 0x00e4
                    00E4    242 _T1CTL	=	0x00e4
                    00E5    243 Ftwitch_mx_xbee$T1CCTL0$0$0 == 0x00e5
                    00E5    244 _T1CCTL0	=	0x00e5
                    00E6    245 Ftwitch_mx_xbee$T1CCTL1$0$0 == 0x00e6
                    00E6    246 _T1CCTL1	=	0x00e6
                    00E7    247 Ftwitch_mx_xbee$T1CCTL2$0$0 == 0x00e7
                    00E7    248 _T1CCTL2	=	0x00e7
                    00E8    249 Ftwitch_mx_xbee$IRCON2$0$0 == 0x00e8
                    00E8    250 _IRCON2	=	0x00e8
                    00E9    251 Ftwitch_mx_xbee$RFIF$0$0 == 0x00e9
                    00E9    252 _RFIF	=	0x00e9
                    00EA    253 Ftwitch_mx_xbee$T4CNT$0$0 == 0x00ea
                    00EA    254 _T4CNT	=	0x00ea
                    00EB    255 Ftwitch_mx_xbee$T4CTL$0$0 == 0x00eb
                    00EB    256 _T4CTL	=	0x00eb
                    00EC    257 Ftwitch_mx_xbee$T4CCTL0$0$0 == 0x00ec
                    00EC    258 _T4CCTL0	=	0x00ec
                    00ED    259 Ftwitch_mx_xbee$T4CC0$0$0 == 0x00ed
                    00ED    260 _T4CC0	=	0x00ed
                    00EE    261 Ftwitch_mx_xbee$T4CCTL1$0$0 == 0x00ee
                    00EE    262 _T4CCTL1	=	0x00ee
                    00EF    263 Ftwitch_mx_xbee$T4CC1$0$0 == 0x00ef
                    00EF    264 _T4CC1	=	0x00ef
                    00F0    265 Ftwitch_mx_xbee$B$0$0 == 0x00f0
                    00F0    266 _B	=	0x00f0
                    00F1    267 Ftwitch_mx_xbee$PERCFG$0$0 == 0x00f1
                    00F1    268 _PERCFG	=	0x00f1
                    00F2    269 Ftwitch_mx_xbee$ADCCFG$0$0 == 0x00f2
                    00F2    270 _ADCCFG	=	0x00f2
                    00F3    271 Ftwitch_mx_xbee$P0SEL$0$0 == 0x00f3
                    00F3    272 _P0SEL	=	0x00f3
                    00F4    273 Ftwitch_mx_xbee$P1SEL$0$0 == 0x00f4
                    00F4    274 _P1SEL	=	0x00f4
                    00F5    275 Ftwitch_mx_xbee$P2SEL$0$0 == 0x00f5
                    00F5    276 _P2SEL	=	0x00f5
                    00F6    277 Ftwitch_mx_xbee$P1INP$0$0 == 0x00f6
                    00F6    278 _P1INP	=	0x00f6
                    00F7    279 Ftwitch_mx_xbee$P2INP$0$0 == 0x00f7
                    00F7    280 _P2INP	=	0x00f7
                    00F8    281 Ftwitch_mx_xbee$U1CSR$0$0 == 0x00f8
                    00F8    282 _U1CSR	=	0x00f8
                    00F9    283 Ftwitch_mx_xbee$U1DBUF$0$0 == 0x00f9
                    00F9    284 _U1DBUF	=	0x00f9
                    00FA    285 Ftwitch_mx_xbee$U1BAUD$0$0 == 0x00fa
                    00FA    286 _U1BAUD	=	0x00fa
                    00FB    287 Ftwitch_mx_xbee$U1UCR$0$0 == 0x00fb
                    00FB    288 _U1UCR	=	0x00fb
                    00FC    289 Ftwitch_mx_xbee$U1GCR$0$0 == 0x00fc
                    00FC    290 _U1GCR	=	0x00fc
                    00FD    291 Ftwitch_mx_xbee$P0DIR$0$0 == 0x00fd
                    00FD    292 _P0DIR	=	0x00fd
                    00FE    293 Ftwitch_mx_xbee$P1DIR$0$0 == 0x00fe
                    00FE    294 _P1DIR	=	0x00fe
                    00FF    295 Ftwitch_mx_xbee$P2DIR$0$0 == 0x00ff
                    00FF    296 _P2DIR	=	0x00ff
                    FFFFD5D4    297 Ftwitch_mx_xbee$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    298 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    299 Ftwitch_mx_xbee$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    300 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    301 Ftwitch_mx_xbee$FADDR$0$0 == 0xffffadac
                    FFFFADAC    302 _FADDR	=	0xffffadac
                    FFFFBBBA    303 Ftwitch_mx_xbee$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    304 _ADC	=	0xffffbbba
                    FFFFDBDA    305 Ftwitch_mx_xbee$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    306 _T1CC0	=	0xffffdbda
                    FFFFDDDC    307 Ftwitch_mx_xbee$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    308 _T1CC1	=	0xffffdddc
                    FFFFDFDE    309 Ftwitch_mx_xbee$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    310 _T1CC2	=	0xffffdfde
                            311 ;--------------------------------------------------------
                            312 ; special function bits
                            313 ;--------------------------------------------------------
                            314 	.area RSEG    (ABS,DATA)
   0000                     315 	.org 0x0000
                    0080    316 Ftwitch_mx_xbee$P0_0$0$0 == 0x0080
                    0080    317 _P0_0	=	0x0080
                    0081    318 Ftwitch_mx_xbee$P0_1$0$0 == 0x0081
                    0081    319 _P0_1	=	0x0081
                    0082    320 Ftwitch_mx_xbee$P0_2$0$0 == 0x0082
                    0082    321 _P0_2	=	0x0082
                    0083    322 Ftwitch_mx_xbee$P0_3$0$0 == 0x0083
                    0083    323 _P0_3	=	0x0083
                    0084    324 Ftwitch_mx_xbee$P0_4$0$0 == 0x0084
                    0084    325 _P0_4	=	0x0084
                    0085    326 Ftwitch_mx_xbee$P0_5$0$0 == 0x0085
                    0085    327 _P0_5	=	0x0085
                    0086    328 Ftwitch_mx_xbee$P0_6$0$0 == 0x0086
                    0086    329 _P0_6	=	0x0086
                    0087    330 Ftwitch_mx_xbee$P0_7$0$0 == 0x0087
                    0087    331 _P0_7	=	0x0087
                    0088    332 Ftwitch_mx_xbee$_TCON_0$0$0 == 0x0088
                    0088    333 __TCON_0	=	0x0088
                    0089    334 Ftwitch_mx_xbee$RFTXRXIF$0$0 == 0x0089
                    0089    335 _RFTXRXIF	=	0x0089
                    008A    336 Ftwitch_mx_xbee$_TCON_2$0$0 == 0x008a
                    008A    337 __TCON_2	=	0x008a
                    008B    338 Ftwitch_mx_xbee$URX0IF$0$0 == 0x008b
                    008B    339 _URX0IF	=	0x008b
                    008C    340 Ftwitch_mx_xbee$_TCON_4$0$0 == 0x008c
                    008C    341 __TCON_4	=	0x008c
                    008D    342 Ftwitch_mx_xbee$ADCIF$0$0 == 0x008d
                    008D    343 _ADCIF	=	0x008d
                    008E    344 Ftwitch_mx_xbee$_TCON_6$0$0 == 0x008e
                    008E    345 __TCON_6	=	0x008e
                    008F    346 Ftwitch_mx_xbee$URX1IF$0$0 == 0x008f
                    008F    347 _URX1IF	=	0x008f
                    0090    348 Ftwitch_mx_xbee$P1_0$0$0 == 0x0090
                    0090    349 _P1_0	=	0x0090
                    0091    350 Ftwitch_mx_xbee$P1_1$0$0 == 0x0091
                    0091    351 _P1_1	=	0x0091
                    0092    352 Ftwitch_mx_xbee$P1_2$0$0 == 0x0092
                    0092    353 _P1_2	=	0x0092
                    0093    354 Ftwitch_mx_xbee$P1_3$0$0 == 0x0093
                    0093    355 _P1_3	=	0x0093
                    0094    356 Ftwitch_mx_xbee$P1_4$0$0 == 0x0094
                    0094    357 _P1_4	=	0x0094
                    0095    358 Ftwitch_mx_xbee$P1_5$0$0 == 0x0095
                    0095    359 _P1_5	=	0x0095
                    0096    360 Ftwitch_mx_xbee$P1_6$0$0 == 0x0096
                    0096    361 _P1_6	=	0x0096
                    0097    362 Ftwitch_mx_xbee$P1_7$0$0 == 0x0097
                    0097    363 _P1_7	=	0x0097
                    0098    364 Ftwitch_mx_xbee$ENCIF_0$0$0 == 0x0098
                    0098    365 _ENCIF_0	=	0x0098
                    0099    366 Ftwitch_mx_xbee$ENCIF_1$0$0 == 0x0099
                    0099    367 _ENCIF_1	=	0x0099
                    009A    368 Ftwitch_mx_xbee$_SOCON2$0$0 == 0x009a
                    009A    369 __SOCON2	=	0x009a
                    009B    370 Ftwitch_mx_xbee$_SOCON3$0$0 == 0x009b
                    009B    371 __SOCON3	=	0x009b
                    009C    372 Ftwitch_mx_xbee$_SOCON4$0$0 == 0x009c
                    009C    373 __SOCON4	=	0x009c
                    009D    374 Ftwitch_mx_xbee$_SOCON5$0$0 == 0x009d
                    009D    375 __SOCON5	=	0x009d
                    009E    376 Ftwitch_mx_xbee$_SOCON6$0$0 == 0x009e
                    009E    377 __SOCON6	=	0x009e
                    009F    378 Ftwitch_mx_xbee$_SOCON7$0$0 == 0x009f
                    009F    379 __SOCON7	=	0x009f
                    00A0    380 Ftwitch_mx_xbee$P2_0$0$0 == 0x00a0
                    00A0    381 _P2_0	=	0x00a0
                    00A1    382 Ftwitch_mx_xbee$P2_1$0$0 == 0x00a1
                    00A1    383 _P2_1	=	0x00a1
                    00A2    384 Ftwitch_mx_xbee$P2_2$0$0 == 0x00a2
                    00A2    385 _P2_2	=	0x00a2
                    00A3    386 Ftwitch_mx_xbee$P2_3$0$0 == 0x00a3
                    00A3    387 _P2_3	=	0x00a3
                    00A4    388 Ftwitch_mx_xbee$P2_4$0$0 == 0x00a4
                    00A4    389 _P2_4	=	0x00a4
                    00A5    390 Ftwitch_mx_xbee$P2_5$0$0 == 0x00a5
                    00A5    391 _P2_5	=	0x00a5
                    00A6    392 Ftwitch_mx_xbee$P2_6$0$0 == 0x00a6
                    00A6    393 _P2_6	=	0x00a6
                    00A7    394 Ftwitch_mx_xbee$P2_7$0$0 == 0x00a7
                    00A7    395 _P2_7	=	0x00a7
                    00A8    396 Ftwitch_mx_xbee$RFTXRXIE$0$0 == 0x00a8
                    00A8    397 _RFTXRXIE	=	0x00a8
                    00A9    398 Ftwitch_mx_xbee$ADCIE$0$0 == 0x00a9
                    00A9    399 _ADCIE	=	0x00a9
                    00AA    400 Ftwitch_mx_xbee$URX0IE$0$0 == 0x00aa
                    00AA    401 _URX0IE	=	0x00aa
                    00AB    402 Ftwitch_mx_xbee$URX1IE$0$0 == 0x00ab
                    00AB    403 _URX1IE	=	0x00ab
                    00AC    404 Ftwitch_mx_xbee$ENCIE$0$0 == 0x00ac
                    00AC    405 _ENCIE	=	0x00ac
                    00AD    406 Ftwitch_mx_xbee$STIE$0$0 == 0x00ad
                    00AD    407 _STIE	=	0x00ad
                    00AE    408 Ftwitch_mx_xbee$_IEN06$0$0 == 0x00ae
                    00AE    409 __IEN06	=	0x00ae
                    00AF    410 Ftwitch_mx_xbee$EA$0$0 == 0x00af
                    00AF    411 _EA	=	0x00af
                    00B8    412 Ftwitch_mx_xbee$DMAIE$0$0 == 0x00b8
                    00B8    413 _DMAIE	=	0x00b8
                    00B9    414 Ftwitch_mx_xbee$T1IE$0$0 == 0x00b9
                    00B9    415 _T1IE	=	0x00b9
                    00BA    416 Ftwitch_mx_xbee$T2IE$0$0 == 0x00ba
                    00BA    417 _T2IE	=	0x00ba
                    00BB    418 Ftwitch_mx_xbee$T3IE$0$0 == 0x00bb
                    00BB    419 _T3IE	=	0x00bb
                    00BC    420 Ftwitch_mx_xbee$T4IE$0$0 == 0x00bc
                    00BC    421 _T4IE	=	0x00bc
                    00BD    422 Ftwitch_mx_xbee$P0IE$0$0 == 0x00bd
                    00BD    423 _P0IE	=	0x00bd
                    00BE    424 Ftwitch_mx_xbee$_IEN16$0$0 == 0x00be
                    00BE    425 __IEN16	=	0x00be
                    00BF    426 Ftwitch_mx_xbee$_IEN17$0$0 == 0x00bf
                    00BF    427 __IEN17	=	0x00bf
                    00C0    428 Ftwitch_mx_xbee$DMAIF$0$0 == 0x00c0
                    00C0    429 _DMAIF	=	0x00c0
                    00C1    430 Ftwitch_mx_xbee$T1IF$0$0 == 0x00c1
                    00C1    431 _T1IF	=	0x00c1
                    00C2    432 Ftwitch_mx_xbee$T2IF$0$0 == 0x00c2
                    00C2    433 _T2IF	=	0x00c2
                    00C3    434 Ftwitch_mx_xbee$T3IF$0$0 == 0x00c3
                    00C3    435 _T3IF	=	0x00c3
                    00C4    436 Ftwitch_mx_xbee$T4IF$0$0 == 0x00c4
                    00C4    437 _T4IF	=	0x00c4
                    00C5    438 Ftwitch_mx_xbee$P0IF$0$0 == 0x00c5
                    00C5    439 _P0IF	=	0x00c5
                    00C6    440 Ftwitch_mx_xbee$_IRCON6$0$0 == 0x00c6
                    00C6    441 __IRCON6	=	0x00c6
                    00C7    442 Ftwitch_mx_xbee$STIF$0$0 == 0x00c7
                    00C7    443 _STIF	=	0x00c7
                    00D0    444 Ftwitch_mx_xbee$P$0$0 == 0x00d0
                    00D0    445 _P	=	0x00d0
                    00D1    446 Ftwitch_mx_xbee$F1$0$0 == 0x00d1
                    00D1    447 _F1	=	0x00d1
                    00D2    448 Ftwitch_mx_xbee$OV$0$0 == 0x00d2
                    00D2    449 _OV	=	0x00d2
                    00D3    450 Ftwitch_mx_xbee$RS0$0$0 == 0x00d3
                    00D3    451 _RS0	=	0x00d3
                    00D4    452 Ftwitch_mx_xbee$RS1$0$0 == 0x00d4
                    00D4    453 _RS1	=	0x00d4
                    00D5    454 Ftwitch_mx_xbee$F0$0$0 == 0x00d5
                    00D5    455 _F0	=	0x00d5
                    00D6    456 Ftwitch_mx_xbee$AC$0$0 == 0x00d6
                    00D6    457 _AC	=	0x00d6
                    00D7    458 Ftwitch_mx_xbee$CY$0$0 == 0x00d7
                    00D7    459 _CY	=	0x00d7
                    00D8    460 Ftwitch_mx_xbee$T3OVFIF$0$0 == 0x00d8
                    00D8    461 _T3OVFIF	=	0x00d8
                    00D9    462 Ftwitch_mx_xbee$T3CH0IF$0$0 == 0x00d9
                    00D9    463 _T3CH0IF	=	0x00d9
                    00DA    464 Ftwitch_mx_xbee$T3CH1IF$0$0 == 0x00da
                    00DA    465 _T3CH1IF	=	0x00da
                    00DB    466 Ftwitch_mx_xbee$T4OVFIF$0$0 == 0x00db
                    00DB    467 _T4OVFIF	=	0x00db
                    00DC    468 Ftwitch_mx_xbee$T4CH0IF$0$0 == 0x00dc
                    00DC    469 _T4CH0IF	=	0x00dc
                    00DD    470 Ftwitch_mx_xbee$T4CH1IF$0$0 == 0x00dd
                    00DD    471 _T4CH1IF	=	0x00dd
                    00DE    472 Ftwitch_mx_xbee$OVFIM$0$0 == 0x00de
                    00DE    473 _OVFIM	=	0x00de
                    00DF    474 Ftwitch_mx_xbee$_TIMIF7$0$0 == 0x00df
                    00DF    475 __TIMIF7	=	0x00df
                    00E0    476 Ftwitch_mx_xbee$ACC_0$0$0 == 0x00e0
                    00E0    477 _ACC_0	=	0x00e0
                    00E1    478 Ftwitch_mx_xbee$ACC_1$0$0 == 0x00e1
                    00E1    479 _ACC_1	=	0x00e1
                    00E2    480 Ftwitch_mx_xbee$ACC_2$0$0 == 0x00e2
                    00E2    481 _ACC_2	=	0x00e2
                    00E3    482 Ftwitch_mx_xbee$ACC_3$0$0 == 0x00e3
                    00E3    483 _ACC_3	=	0x00e3
                    00E4    484 Ftwitch_mx_xbee$ACC_4$0$0 == 0x00e4
                    00E4    485 _ACC_4	=	0x00e4
                    00E5    486 Ftwitch_mx_xbee$ACC_5$0$0 == 0x00e5
                    00E5    487 _ACC_5	=	0x00e5
                    00E6    488 Ftwitch_mx_xbee$ACC_6$0$0 == 0x00e6
                    00E6    489 _ACC_6	=	0x00e6
                    00E7    490 Ftwitch_mx_xbee$ACC_7$0$0 == 0x00e7
                    00E7    491 _ACC_7	=	0x00e7
                    00E8    492 Ftwitch_mx_xbee$P2IF$0$0 == 0x00e8
                    00E8    493 _P2IF	=	0x00e8
                    00E9    494 Ftwitch_mx_xbee$UTX0IF$0$0 == 0x00e9
                    00E9    495 _UTX0IF	=	0x00e9
                    00EA    496 Ftwitch_mx_xbee$UTX1IF$0$0 == 0x00ea
                    00EA    497 _UTX1IF	=	0x00ea
                    00EB    498 Ftwitch_mx_xbee$P1IF$0$0 == 0x00eb
                    00EB    499 _P1IF	=	0x00eb
                    00EC    500 Ftwitch_mx_xbee$WDTIF$0$0 == 0x00ec
                    00EC    501 _WDTIF	=	0x00ec
                    00ED    502 Ftwitch_mx_xbee$_IRCON25$0$0 == 0x00ed
                    00ED    503 __IRCON25	=	0x00ed
                    00EE    504 Ftwitch_mx_xbee$_IRCON26$0$0 == 0x00ee
                    00EE    505 __IRCON26	=	0x00ee
                    00EF    506 Ftwitch_mx_xbee$_IRCON27$0$0 == 0x00ef
                    00EF    507 __IRCON27	=	0x00ef
                    00F0    508 Ftwitch_mx_xbee$B_0$0$0 == 0x00f0
                    00F0    509 _B_0	=	0x00f0
                    00F1    510 Ftwitch_mx_xbee$B_1$0$0 == 0x00f1
                    00F1    511 _B_1	=	0x00f1
                    00F2    512 Ftwitch_mx_xbee$B_2$0$0 == 0x00f2
                    00F2    513 _B_2	=	0x00f2
                    00F3    514 Ftwitch_mx_xbee$B_3$0$0 == 0x00f3
                    00F3    515 _B_3	=	0x00f3
                    00F4    516 Ftwitch_mx_xbee$B_4$0$0 == 0x00f4
                    00F4    517 _B_4	=	0x00f4
                    00F5    518 Ftwitch_mx_xbee$B_5$0$0 == 0x00f5
                    00F5    519 _B_5	=	0x00f5
                    00F6    520 Ftwitch_mx_xbee$B_6$0$0 == 0x00f6
                    00F6    521 _B_6	=	0x00f6
                    00F7    522 Ftwitch_mx_xbee$B_7$0$0 == 0x00f7
                    00F7    523 _B_7	=	0x00f7
                    00F8    524 Ftwitch_mx_xbee$U1ACTIVE$0$0 == 0x00f8
                    00F8    525 _U1ACTIVE	=	0x00f8
                    00F9    526 Ftwitch_mx_xbee$U1TX_BYTE$0$0 == 0x00f9
                    00F9    527 _U1TX_BYTE	=	0x00f9
                    00FA    528 Ftwitch_mx_xbee$U1RX_BYTE$0$0 == 0x00fa
                    00FA    529 _U1RX_BYTE	=	0x00fa
                    00FB    530 Ftwitch_mx_xbee$U1ERR$0$0 == 0x00fb
                    00FB    531 _U1ERR	=	0x00fb
                    00FC    532 Ftwitch_mx_xbee$U1FE$0$0 == 0x00fc
                    00FC    533 _U1FE	=	0x00fc
                    00FD    534 Ftwitch_mx_xbee$U1SLAVE$0$0 == 0x00fd
                    00FD    535 _U1SLAVE	=	0x00fd
                    00FE    536 Ftwitch_mx_xbee$U1RE$0$0 == 0x00fe
                    00FE    537 _U1RE	=	0x00fe
                    00FF    538 Ftwitch_mx_xbee$U1MODE$0$0 == 0x00ff
                    00FF    539 _U1MODE	=	0x00ff
                            540 ;--------------------------------------------------------
                            541 ; overlayable register banks
                            542 ;--------------------------------------------------------
                            543 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     544 	.ds 8
                            545 ;--------------------------------------------------------
                            546 ; overlayable bit register bank
                            547 ;--------------------------------------------------------
                            548 	.area BIT_BANK	(REL,OVR,DATA)
   0024                     549 bits:
   0024                     550 	.ds 1
                    8000    551 	b0 = bits[0]
                    8100    552 	b1 = bits[1]
                    8200    553 	b2 = bits[2]
                    8300    554 	b3 = bits[3]
                    8400    555 	b4 = bits[4]
                    8500    556 	b5 = bits[5]
                    8600    557 	b6 = bits[6]
                    8700    558 	b7 = bits[7]
                            559 ;--------------------------------------------------------
                            560 ; internal ram data
                            561 ;--------------------------------------------------------
                            562 	.area DSEG    (DATA)
                    0000    563 Ltwitch_mx_xbee.updateLeds$count$3$7==.
   0025                     564 _updateLeds_count_3_7:
   0025                     565 	.ds 1
                    0001    566 Ltwitch_mx_xbee.errorService$sloc0$1$0==.
   0026                     567 _errorService_sloc0_1_0:
   0026                     568 	.ds 4
                            569 ;--------------------------------------------------------
                            570 ; overlayable items in internal ram 
                            571 ;--------------------------------------------------------
                            572 	.area OSEG    (OVR,DATA)
                            573 ;--------------------------------------------------------
                            574 ; Stack segment in internal ram 
                            575 ;--------------------------------------------------------
                            576 	.area	SSEG	(DATA)
   0051                     577 __start__stack:
   0051                     578 	.ds	1
                            579 
                            580 ;--------------------------------------------------------
                            581 ; indirectly addressable internal ram data
                            582 ;--------------------------------------------------------
                            583 	.area ISEG    (DATA)
                            584 ;--------------------------------------------------------
                            585 ; absolute internal ram data
                            586 ;--------------------------------------------------------
                            587 	.area IABS    (ABS,DATA)
                            588 	.area IABS    (ABS,DATA)
                            589 ;--------------------------------------------------------
                            590 ; bit data
                            591 ;--------------------------------------------------------
                            592 	.area BSEG    (BIT)
                    0000    593 G$uartRxDisabled$0$0==.
   0000                     594 _uartRxDisabled::
   0000                     595 	.ds 1
                    0001    596 G$framingErrorActive$0$0==.
   0001                     597 _framingErrorActive::
   0001                     598 	.ds 1
                    0002    599 G$errorOccurredRecently$0$0==.
   0002                     600 _errorOccurredRecently::
   0002                     601 	.ds 1
                    0003    602 Ltwitch_mx_xbee.updateLeds$dimYellowLed$1$1==.
   0003                     603 _updateLeds_dimYellowLed_1_1:
   0003                     604 	.ds 1
                    0004    605 Ltwitch_mx_xbee.ioTxSignals$sloc0$1$0==.
   0004                     606 _ioTxSignals_sloc0_1_0:
   0004                     607 	.ds 1
                            608 ;--------------------------------------------------------
                            609 ; paged external ram data
                            610 ;--------------------------------------------------------
                            611 	.area PSEG    (PAG,XDATA)
                    0000    612 G$vals$0$0==.
   F010                     613 _vals::
   F010                     614 	.ds 7
                    0007    615 G$index_cmdr$0$0==.
   F017                     616 _index_cmdr::
   F017                     617 	.ds 1
                    0008    618 G$checksum_cmdr$0$0==.
   F018                     619 _checksum_cmdr::
   F018                     620 	.ds 1
                    0009    621 G$walkV$0$0==.
   F019                     622 _walkV::
   F019                     623 	.ds 1
                    000A    624 G$walkH$0$0==.
   F01A                     625 _walkH::
   F01A                     626 	.ds 1
                    000B    627 G$lookV$0$0==.
   F01B                     628 _lookV::
   F01B                     629 	.ds 1
                    000C    630 G$lookH$0$0==.
   F01C                     631 _lookH::
   F01C                     632 	.ds 1
                    000D    633 G$lastErrorTime$0$0==.
   F01D                     634 _lastErrorTime::
   F01D                     635 	.ds 1
                    000E    636 Ltwitch_mx_xbee.updateLeds$lastRadioActivityTime$1$1==.
   F01E                     637 _updateLeds_lastRadioActivityTime_1_1:
   F01E                     638 	.ds 2
                    0010    639 Ltwitch_mx_xbee.ioTxSignals$signals$1$1==.
   F020                     640 _ioTxSignals_signals_1_1:
   F020                     641 	.ds 1
                    0011    642 Ltwitch_mx_xbee.ioTxSignals$nTrstPulseStartTime$1$1==.
   F021                     643 _ioTxSignals_nTrstPulseStartTime_1_1:
   F021                     644 	.ds 1
                    0012    645 Ltwitch_mx_xbee.ioTxSignals$lastSignals$1$1==.
   F022                     646 _ioTxSignals_lastSignals_1_1:
   F022                     647 	.ds 1
                    0013    648 Ltwitch_mx_xbee.errorService$lastRxLowTime$1$1==.
   F023                     649 _errorService_lastRxLowTime_1_1:
   F023                     650 	.ds 1
                            651 ;--------------------------------------------------------
                            652 ; external ram data
                            653 ;--------------------------------------------------------
                            654 	.area XSEG    (XDATA)
                    DF00    655 Ftwitch_mx_xbee$SYNC1$0$0 == 0xdf00
                    DF00    656 _SYNC1	=	0xdf00
                    DF01    657 Ftwitch_mx_xbee$SYNC0$0$0 == 0xdf01
                    DF01    658 _SYNC0	=	0xdf01
                    DF02    659 Ftwitch_mx_xbee$PKTLEN$0$0 == 0xdf02
                    DF02    660 _PKTLEN	=	0xdf02
                    DF03    661 Ftwitch_mx_xbee$PKTCTRL1$0$0 == 0xdf03
                    DF03    662 _PKTCTRL1	=	0xdf03
                    DF04    663 Ftwitch_mx_xbee$PKTCTRL0$0$0 == 0xdf04
                    DF04    664 _PKTCTRL0	=	0xdf04
                    DF05    665 Ftwitch_mx_xbee$ADDR$0$0 == 0xdf05
                    DF05    666 _ADDR	=	0xdf05
                    DF06    667 Ftwitch_mx_xbee$CHANNR$0$0 == 0xdf06
                    DF06    668 _CHANNR	=	0xdf06
                    DF07    669 Ftwitch_mx_xbee$FSCTRL1$0$0 == 0xdf07
                    DF07    670 _FSCTRL1	=	0xdf07
                    DF08    671 Ftwitch_mx_xbee$FSCTRL0$0$0 == 0xdf08
                    DF08    672 _FSCTRL0	=	0xdf08
                    DF09    673 Ftwitch_mx_xbee$FREQ2$0$0 == 0xdf09
                    DF09    674 _FREQ2	=	0xdf09
                    DF0A    675 Ftwitch_mx_xbee$FREQ1$0$0 == 0xdf0a
                    DF0A    676 _FREQ1	=	0xdf0a
                    DF0B    677 Ftwitch_mx_xbee$FREQ0$0$0 == 0xdf0b
                    DF0B    678 _FREQ0	=	0xdf0b
                    DF0C    679 Ftwitch_mx_xbee$MDMCFG4$0$0 == 0xdf0c
                    DF0C    680 _MDMCFG4	=	0xdf0c
                    DF0D    681 Ftwitch_mx_xbee$MDMCFG3$0$0 == 0xdf0d
                    DF0D    682 _MDMCFG3	=	0xdf0d
                    DF0E    683 Ftwitch_mx_xbee$MDMCFG2$0$0 == 0xdf0e
                    DF0E    684 _MDMCFG2	=	0xdf0e
                    DF0F    685 Ftwitch_mx_xbee$MDMCFG1$0$0 == 0xdf0f
                    DF0F    686 _MDMCFG1	=	0xdf0f
                    DF10    687 Ftwitch_mx_xbee$MDMCFG0$0$0 == 0xdf10
                    DF10    688 _MDMCFG0	=	0xdf10
                    DF11    689 Ftwitch_mx_xbee$DEVIATN$0$0 == 0xdf11
                    DF11    690 _DEVIATN	=	0xdf11
                    DF12    691 Ftwitch_mx_xbee$MCSM2$0$0 == 0xdf12
                    DF12    692 _MCSM2	=	0xdf12
                    DF13    693 Ftwitch_mx_xbee$MCSM1$0$0 == 0xdf13
                    DF13    694 _MCSM1	=	0xdf13
                    DF14    695 Ftwitch_mx_xbee$MCSM0$0$0 == 0xdf14
                    DF14    696 _MCSM0	=	0xdf14
                    DF15    697 Ftwitch_mx_xbee$FOCCFG$0$0 == 0xdf15
                    DF15    698 _FOCCFG	=	0xdf15
                    DF16    699 Ftwitch_mx_xbee$BSCFG$0$0 == 0xdf16
                    DF16    700 _BSCFG	=	0xdf16
                    DF17    701 Ftwitch_mx_xbee$AGCCTRL2$0$0 == 0xdf17
                    DF17    702 _AGCCTRL2	=	0xdf17
                    DF18    703 Ftwitch_mx_xbee$AGCCTRL1$0$0 == 0xdf18
                    DF18    704 _AGCCTRL1	=	0xdf18
                    DF19    705 Ftwitch_mx_xbee$AGCCTRL0$0$0 == 0xdf19
                    DF19    706 _AGCCTRL0	=	0xdf19
                    DF1A    707 Ftwitch_mx_xbee$FREND1$0$0 == 0xdf1a
                    DF1A    708 _FREND1	=	0xdf1a
                    DF1B    709 Ftwitch_mx_xbee$FREND0$0$0 == 0xdf1b
                    DF1B    710 _FREND0	=	0xdf1b
                    DF1C    711 Ftwitch_mx_xbee$FSCAL3$0$0 == 0xdf1c
                    DF1C    712 _FSCAL3	=	0xdf1c
                    DF1D    713 Ftwitch_mx_xbee$FSCAL2$0$0 == 0xdf1d
                    DF1D    714 _FSCAL2	=	0xdf1d
                    DF1E    715 Ftwitch_mx_xbee$FSCAL1$0$0 == 0xdf1e
                    DF1E    716 _FSCAL1	=	0xdf1e
                    DF1F    717 Ftwitch_mx_xbee$FSCAL0$0$0 == 0xdf1f
                    DF1F    718 _FSCAL0	=	0xdf1f
                    DF23    719 Ftwitch_mx_xbee$TEST2$0$0 == 0xdf23
                    DF23    720 _TEST2	=	0xdf23
                    DF24    721 Ftwitch_mx_xbee$TEST1$0$0 == 0xdf24
                    DF24    722 _TEST1	=	0xdf24
                    DF25    723 Ftwitch_mx_xbee$TEST0$0$0 == 0xdf25
                    DF25    724 _TEST0	=	0xdf25
                    DF2E    725 Ftwitch_mx_xbee$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    726 _PA_TABLE0	=	0xdf2e
                    DF2F    727 Ftwitch_mx_xbee$IOCFG2$0$0 == 0xdf2f
                    DF2F    728 _IOCFG2	=	0xdf2f
                    DF30    729 Ftwitch_mx_xbee$IOCFG1$0$0 == 0xdf30
                    DF30    730 _IOCFG1	=	0xdf30
                    DF31    731 Ftwitch_mx_xbee$IOCFG0$0$0 == 0xdf31
                    DF31    732 _IOCFG0	=	0xdf31
                    DF36    733 Ftwitch_mx_xbee$PARTNUM$0$0 == 0xdf36
                    DF36    734 _PARTNUM	=	0xdf36
                    DF37    735 Ftwitch_mx_xbee$VERSION$0$0 == 0xdf37
                    DF37    736 _VERSION	=	0xdf37
                    DF38    737 Ftwitch_mx_xbee$FREQEST$0$0 == 0xdf38
                    DF38    738 _FREQEST	=	0xdf38
                    DF39    739 Ftwitch_mx_xbee$LQI$0$0 == 0xdf39
                    DF39    740 _LQI	=	0xdf39
                    DF3A    741 Ftwitch_mx_xbee$RSSI$0$0 == 0xdf3a
                    DF3A    742 _RSSI	=	0xdf3a
                    DF3B    743 Ftwitch_mx_xbee$MARCSTATE$0$0 == 0xdf3b
                    DF3B    744 _MARCSTATE	=	0xdf3b
                    DF3C    745 Ftwitch_mx_xbee$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    746 _PKTSTATUS	=	0xdf3c
                    DF3D    747 Ftwitch_mx_xbee$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    748 _VCO_VC_DAC	=	0xdf3d
                    DF40    749 Ftwitch_mx_xbee$I2SCFG0$0$0 == 0xdf40
                    DF40    750 _I2SCFG0	=	0xdf40
                    DF41    751 Ftwitch_mx_xbee$I2SCFG1$0$0 == 0xdf41
                    DF41    752 _I2SCFG1	=	0xdf41
                    DF42    753 Ftwitch_mx_xbee$I2SDATL$0$0 == 0xdf42
                    DF42    754 _I2SDATL	=	0xdf42
                    DF43    755 Ftwitch_mx_xbee$I2SDATH$0$0 == 0xdf43
                    DF43    756 _I2SDATH	=	0xdf43
                    DF44    757 Ftwitch_mx_xbee$I2SWCNT$0$0 == 0xdf44
                    DF44    758 _I2SWCNT	=	0xdf44
                    DF45    759 Ftwitch_mx_xbee$I2SSTAT$0$0 == 0xdf45
                    DF45    760 _I2SSTAT	=	0xdf45
                    DF46    761 Ftwitch_mx_xbee$I2SCLKF0$0$0 == 0xdf46
                    DF46    762 _I2SCLKF0	=	0xdf46
                    DF47    763 Ftwitch_mx_xbee$I2SCLKF1$0$0 == 0xdf47
                    DF47    764 _I2SCLKF1	=	0xdf47
                    DF48    765 Ftwitch_mx_xbee$I2SCLKF2$0$0 == 0xdf48
                    DF48    766 _I2SCLKF2	=	0xdf48
                    DE00    767 Ftwitch_mx_xbee$USBADDR$0$0 == 0xde00
                    DE00    768 _USBADDR	=	0xde00
                    DE01    769 Ftwitch_mx_xbee$USBPOW$0$0 == 0xde01
                    DE01    770 _USBPOW	=	0xde01
                    DE02    771 Ftwitch_mx_xbee$USBIIF$0$0 == 0xde02
                    DE02    772 _USBIIF	=	0xde02
                    DE04    773 Ftwitch_mx_xbee$USBOIF$0$0 == 0xde04
                    DE04    774 _USBOIF	=	0xde04
                    DE06    775 Ftwitch_mx_xbee$USBCIF$0$0 == 0xde06
                    DE06    776 _USBCIF	=	0xde06
                    DE07    777 Ftwitch_mx_xbee$USBIIE$0$0 == 0xde07
                    DE07    778 _USBIIE	=	0xde07
                    DE09    779 Ftwitch_mx_xbee$USBOIE$0$0 == 0xde09
                    DE09    780 _USBOIE	=	0xde09
                    DE0B    781 Ftwitch_mx_xbee$USBCIE$0$0 == 0xde0b
                    DE0B    782 _USBCIE	=	0xde0b
                    DE0C    783 Ftwitch_mx_xbee$USBFRML$0$0 == 0xde0c
                    DE0C    784 _USBFRML	=	0xde0c
                    DE0D    785 Ftwitch_mx_xbee$USBFRMH$0$0 == 0xde0d
                    DE0D    786 _USBFRMH	=	0xde0d
                    DE0E    787 Ftwitch_mx_xbee$USBINDEX$0$0 == 0xde0e
                    DE0E    788 _USBINDEX	=	0xde0e
                    DE10    789 Ftwitch_mx_xbee$USBMAXI$0$0 == 0xde10
                    DE10    790 _USBMAXI	=	0xde10
                    DE11    791 Ftwitch_mx_xbee$USBCSIL$0$0 == 0xde11
                    DE11    792 _USBCSIL	=	0xde11
                    DE12    793 Ftwitch_mx_xbee$USBCSIH$0$0 == 0xde12
                    DE12    794 _USBCSIH	=	0xde12
                    DE13    795 Ftwitch_mx_xbee$USBMAXO$0$0 == 0xde13
                    DE13    796 _USBMAXO	=	0xde13
                    DE14    797 Ftwitch_mx_xbee$USBCSOL$0$0 == 0xde14
                    DE14    798 _USBCSOL	=	0xde14
                    DE15    799 Ftwitch_mx_xbee$USBCSOH$0$0 == 0xde15
                    DE15    800 _USBCSOH	=	0xde15
                    DE16    801 Ftwitch_mx_xbee$USBCNTL$0$0 == 0xde16
                    DE16    802 _USBCNTL	=	0xde16
                    DE17    803 Ftwitch_mx_xbee$USBCNTH$0$0 == 0xde17
                    DE17    804 _USBCNTH	=	0xde17
                    DE20    805 Ftwitch_mx_xbee$USBF0$0$0 == 0xde20
                    DE20    806 _USBF0	=	0xde20
                    DE22    807 Ftwitch_mx_xbee$USBF1$0$0 == 0xde22
                    DE22    808 _USBF1	=	0xde22
                    DE24    809 Ftwitch_mx_xbee$USBF2$0$0 == 0xde24
                    DE24    810 _USBF2	=	0xde24
                    DE26    811 Ftwitch_mx_xbee$USBF3$0$0 == 0xde26
                    DE26    812 _USBF3	=	0xde26
                    DE28    813 Ftwitch_mx_xbee$USBF4$0$0 == 0xde28
                    DE28    814 _USBF4	=	0xde28
                    DE2A    815 Ftwitch_mx_xbee$USBF5$0$0 == 0xde2a
                    DE2A    816 _USBF5	=	0xde2a
                            817 ;--------------------------------------------------------
                            818 ; absolute external ram data
                            819 ;--------------------------------------------------------
                            820 	.area XABS    (ABS,XDATA)
                            821 ;--------------------------------------------------------
                            822 ; external initialized ram data
                            823 ;--------------------------------------------------------
                            824 	.area XISEG   (XDATA)
                            825 	.area HOME    (CODE)
                            826 	.area GSINIT0 (CODE)
                            827 	.area GSINIT1 (CODE)
                            828 	.area GSINIT2 (CODE)
                            829 	.area GSINIT3 (CODE)
                            830 	.area GSINIT4 (CODE)
                            831 	.area GSINIT5 (CODE)
                            832 	.area GSINIT  (CODE)
                            833 	.area GSFINAL (CODE)
                            834 	.area CSEG    (CODE)
                            835 ;--------------------------------------------------------
                            836 ; interrupt vector 
                            837 ;--------------------------------------------------------
                            838 	.area HOME    (CODE)
   0400                     839 __interrupt_vect:
   0400 02 04 8B            840 	ljmp	__sdcc_gsinit_startup
   0403 32                  841 	reti
   0404                     842 	.ds	7
   040B 32                  843 	reti
   040C                     844 	.ds	7
   0413 02 19 62            845 	ljmp	_ISR_URX0
   0416                     846 	.ds	5
   041B 02 0D B8            847 	ljmp	_ISR_URX1
   041E                     848 	.ds	5
   0423 32                  849 	reti
   0424                     850 	.ds	7
   042B 32                  851 	reti
   042C                     852 	.ds	7
   0433 32                  853 	reti
   0434                     854 	.ds	7
   043B 02 19 24            855 	ljmp	_ISR_UTX0
   043E                     856 	.ds	5
   0443 32                  857 	reti
   0444                     858 	.ds	7
   044B 32                  859 	reti
   044C                     860 	.ds	7
   0453 32                  861 	reti
   0454                     862 	.ds	7
   045B 32                  863 	reti
   045C                     864 	.ds	7
   0463 02 1C 36            865 	ljmp	_ISR_T4
   0466                     866 	.ds	5
   046B 32                  867 	reti
   046C                     868 	.ds	7
   0473 02 0D 7A            869 	ljmp	_ISR_UTX1
   0476                     870 	.ds	5
   047B 32                  871 	reti
   047C                     872 	.ds	7
   0483 02 11 7C            873 	ljmp	_ISR_RF
                            874 ;--------------------------------------------------------
                            875 ; global & static initialisations
                            876 ;--------------------------------------------------------
                            877 	.area HOME    (CODE)
                            878 	.area GSINIT  (CODE)
                            879 	.area GSFINAL (CODE)
                            880 	.area GSINIT  (CODE)
                            881 	.globl __sdcc_gsinit_startup
                            882 	.globl __sdcc_program_startup
                            883 	.globl __start__stack
                            884 	.globl __mcs51_genXINIT
                            885 	.globl __mcs51_genXRAMCLEAR
                            886 	.globl __mcs51_genRAMCLEAR
                            887 ;------------------------------------------------------------
                            888 ;Allocation info for local variables in function 'updateLeds'
                            889 ;------------------------------------------------------------
                            890 ;count                     Allocated with name '_updateLeds_count_3_7'
                            891 ;------------------------------------------------------------
                    0000    892 	G$updateLeds$0$0 ==.
                    0000    893 	C$twitch_mx_xbee.c$120$2$14 ==.
                            894 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:120: static BIT dimYellowLed = 0;
   04E4 C2 03               895 	clr	_updateLeds_dimYellowLed_1_1
                    0002    896 	G$main$0$0 ==.
                    0002    897 	C$twitch_mx_xbee.c$93$1$1 ==.
                            898 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:93: BIT uartRxDisabled = 0;
   04E6 C2 00               899 	clr	_uartRxDisabled
                    0004    900 	G$main$0$0 ==.
                    0004    901 	C$twitch_mx_xbee.c$97$1$1 ==.
                            902 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:97: BIT framingErrorActive = 0;
   04E8 C2 01               903 	clr	_framingErrorActive
                    0006    904 	G$main$0$0 ==.
                    0006    905 	C$twitch_mx_xbee.c$99$1$1 ==.
                            906 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:99: BIT errorOccurredRecently = 0;
   04EA C2 02               907 	clr	_errorOccurredRecently
                            908 	.area GSFINAL (CODE)
   0532 02 04 86            909 	ljmp	__sdcc_program_startup
                            910 ;--------------------------------------------------------
                            911 ; Home
                            912 ;--------------------------------------------------------
                            913 	.area HOME    (CODE)
                            914 	.area HOME    (CODE)
   0486                     915 __sdcc_program_startup:
   0486 12 0B 08            916 	lcall	_main
                            917 ;	return from main will lock up
   0489 80 FE               918 	sjmp .
                            919 ;--------------------------------------------------------
                            920 ; code
                            921 ;--------------------------------------------------------
                            922 	.area CSEG    (CODE)
                            923 ;------------------------------------------------------------
                            924 ;Allocation info for local variables in function 'updateLeds'
                            925 ;------------------------------------------------------------
                            926 ;count                     Allocated with name '_updateLeds_count_3_7'
                            927 ;------------------------------------------------------------
                    0000    928 	G$updateLeds$0$0 ==.
                    0000    929 	C$twitch_mx_xbee.c$118$0$0 ==.
                            930 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:118: void updateLeds()
                            931 ;	-----------------------------------------
                            932 ;	 function updateLeds
                            933 ;	-----------------------------------------
   06DA                     934 _updateLeds:
                    0007    935 	ar7 = 0x07
                    0006    936 	ar6 = 0x06
                    0005    937 	ar5 = 0x05
                    0004    938 	ar4 = 0x04
                    0003    939 	ar3 = 0x03
                    0002    940 	ar2 = 0x02
                    0001    941 	ar1 = 0x01
                    0000    942 	ar0 = 0x00
                    0000    943 	C$twitch_mx_xbee.c$128$1$1 ==.
                            944 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:128: now = (uint16)getMs();
   06DA 12 1C 5B            945 	lcall	_getMs
   06DD AC 82               946 	mov	r4,dpl
   06DF AD 83               947 	mov	r5,dph
                    0007    948 	C$twitch_mx_xbee.c$135$1$1 ==.
                            949 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:135: if (!radioLinkConnected())
   06E1 C0 05               950 	push	ar5
   06E3 C0 04               951 	push	ar4
   06E5 12 0E 6F            952 	lcall	_radioLinkConnected
   06E8 D0 04               953 	pop	ar4
   06EA D0 05               954 	pop	ar5
   06EC 40 12               955 	jc	00108$
                    0014    956 	C$twitch_mx_xbee.c$139$3$3 ==.
                            957 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:139: LED_YELLOW(now & 0x200 ? 1 : 0);
   06EE ED                  958 	mov	a,r5
   06EF 30 E1 05            959 	jnb	acc.1,00118$
   06F2 43 FF 04            960 	orl	_P2DIR,#0x04
   06F5 80 43               961 	sjmp	00109$
   06F7                     962 00118$:
   06F7 AF FF               963 	mov	r7,_P2DIR
   06F9 53 07 FB            964 	anl	ar7,#0xFB
   06FC 8F FF               965 	mov	_P2DIR,r7
   06FE 80 3A               966 	sjmp	00109$
   0700                     967 00108$:
                    0026    968 	C$twitch_mx_xbee.c$145$2$4 ==.
                            969 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:145: if ((now & 0x3FF) <= 20)
   0700 8C 06               970 	mov	ar6,r4
   0702 74 03               971 	mov	a,#0x03
   0704 5D                  972 	anl	a,r5
   0705 FF                  973 	mov	r7,a
   0706 C3                  974 	clr	c
   0707 74 14               975 	mov	a,#0x14
   0709 9E                  976 	subb	a,r6
   070A E4                  977 	clr	a
   070B 9F                  978 	subb	a,r7
   070C 40 05               979 	jc	00105$
                    0034    980 	C$twitch_mx_xbee.c$148$4$6 ==.
                            981 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:148: LED_YELLOW(1);
   070E 43 FF 04            982 	orl	_P2DIR,#0x04
   0711 80 27               983 	sjmp	00109$
   0713                     984 00105$:
                    0039    985 	C$twitch_mx_xbee.c$150$2$4 ==.
                            986 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:150: else if (dimYellowLed)
   0713 30 03 1D            987 	jnb	_updateLeds_dimYellowLed_1_1,00102$
                    003C    988 	C$twitch_mx_xbee.c$153$3$7 ==.
                            989 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:153: count++;
   0716 05 25               990 	inc	_updateLeds_count_3_7
                    003E    991 	C$twitch_mx_xbee.c$154$4$8 ==.
                            992 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:154: LED_YELLOW((count & 0x7)==0);
   0718 74 07               993 	mov	a,#0x07
   071A 55 25               994 	anl	a,_updateLeds_count_3_7
   071C FF                  995 	mov	r7,a
   071D B4 01 00            996 	cjne	a,#0x01,00142$
   0720                     997 00142$:
   0720 E4                  998 	clr	a
   0721 33                  999 	rlc	a
   0722 FF                 1000 	mov	r7,a
   0723 60 05              1001 	jz	00120$
   0725 43 FF 04           1002 	orl	_P2DIR,#0x04
   0728 80 10              1003 	sjmp	00109$
   072A                    1004 00120$:
   072A AF FF              1005 	mov	r7,_P2DIR
   072C 53 07 FB           1006 	anl	ar7,#0xFB
   072F 8F FF              1007 	mov	_P2DIR,r7
   0731 80 07              1008 	sjmp	00109$
   0733                    1009 00102$:
                    0059   1010 	C$twitch_mx_xbee.c$158$4$10 ==.
                           1011 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:158: LED_YELLOW(0);
   0733 AF FF              1012 	mov	r7,_P2DIR
   0735 53 07 FB           1013 	anl	ar7,#0xFB
   0738 8F FF              1014 	mov	_P2DIR,r7
   073A                    1015 00109$:
                    0060   1016 	C$twitch_mx_xbee.c$162$1$1 ==.
                           1017 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:162: if (radioLinkActivityOccurred)
                    0060   1018 	C$twitch_mx_xbee.c$164$2$11 ==.
                           1019 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:164: radioLinkActivityOccurred = 0;
   073A 10 0D 02           1020 	jbc	_radioLinkActivityOccurred,00144$
   073D 80 12              1021 	sjmp	00111$
   073F                    1022 00144$:
                    0065   1023 	C$twitch_mx_xbee.c$165$2$11 ==.
                           1024 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:165: dimYellowLed ^= 1;
   073F A2 03              1025 	mov	c,_updateLeds_dimYellowLed_1_1
   0741 E4                 1026 	clr	a
   0742 33                 1027 	rlc	a
   0743 64 01              1028 	xrl	a,#0x01
   0745 FF                 1029 	mov	r7,a
   0746 24 FF              1030 	add	a,#0xff
   0748 92 03              1031 	mov	_updateLeds_dimYellowLed_1_1,c
                    0070   1032 	C$twitch_mx_xbee.c$167$2$11 ==.
                           1033 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:167: lastRadioActivityTime = now;
   074A 78 1E              1034 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   074C EC                 1035 	mov	a,r4
   074D F2                 1036 	movx	@r0,a
   074E 08                 1037 	inc	r0
   074F ED                 1038 	mov	a,r5
   0750 F2                 1039 	movx	@r0,a
   0751                    1040 00111$:
                    0077   1041 	C$twitch_mx_xbee.c$170$1$1 ==.
                           1042 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:170: if ((uint16)(now - lastRadioActivityTime) > 32)
   0751 78 1E              1043 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   0753 D3                 1044 	setb	c
   0754 E2                 1045 	movx	a,@r0
   0755 9C                 1046 	subb	a,r4
   0756 F4                 1047 	cpl	a
   0757 B3                 1048 	cpl	c
   0758 FE                 1049 	mov	r6,a
   0759 B3                 1050 	cpl	c
   075A 08                 1051 	inc	r0
   075B E2                 1052 	movx	a,@r0
   075C 9D                 1053 	subb	a,r5
   075D F4                 1054 	cpl	a
   075E FF                 1055 	mov	r7,a
   075F C3                 1056 	clr	c
   0760 74 20              1057 	mov	a,#0x20
   0762 9E                 1058 	subb	a,r6
   0763 E4                 1059 	clr	a
   0764 9F                 1060 	subb	a,r7
   0765 50 02              1061 	jnc	00113$
                    008D   1062 	C$twitch_mx_xbee.c$172$2$12 ==.
                           1063 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:172: dimYellowLed = 0;
   0767 C2 03              1064 	clr	_updateLeds_dimYellowLed_1_1
   0769                    1065 00113$:
                    008F   1066 	C$twitch_mx_xbee.c$175$1$1 ==.
                           1067 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:175: if ((uint8)(now - lastErrorTime) > 100)
   0769 78 1D              1068 	mov	r0,#_lastErrorTime
   076B D3                 1069 	setb	c
   076C E2                 1070 	movx	a,@r0
   076D 9C                 1071 	subb	a,r4
   076E F4                 1072 	cpl	a
   076F FC                 1073 	mov  r4,a
   0770 24 9B              1074 	add	a,#0xff - 0x64
   0772 50 02              1075 	jnc	00115$
                    009A   1076 	C$twitch_mx_xbee.c$177$2$13 ==.
                           1077 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:177: errorOccurredRecently = 0;
   0774 C2 02              1078 	clr	_errorOccurredRecently
   0776                    1079 00115$:
                    009C   1080 	C$twitch_mx_xbee.c$180$2$14 ==.
                           1081 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:180: LED_RED(errorOccurredRecently || uartRxDisabled);
   0776 20 02 07           1082 	jb	_errorOccurredRecently,00125$
   0779 20 00 04           1083 	jb	_uartRxDisabled,00125$
   077C 7F 00              1084 	mov	r7,#0x00
   077E 80 02              1085 	sjmp	00126$
   0780                    1086 00125$:
   0780 7F 01              1087 	mov	r7,#0x01
   0782                    1088 00126$:
   0782 EF                 1089 	mov	a,r7
   0783 60 05              1090 	jz	00122$
   0785 43 FF 02           1091 	orl	_P2DIR,#0x02
   0788 80 07              1092 	sjmp	00116$
   078A                    1093 00122$:
   078A AF FF              1094 	mov	r7,_P2DIR
   078C 53 07 FD           1095 	anl	ar7,#0xFD
   078F 8F FF              1096 	mov	_P2DIR,r7
   0791                    1097 00116$:
                    00B7   1098 	C$twitch_mx_xbee.c$181$2$14 ==.
                    00B7   1099 	XG$updateLeds$0$0 ==.
   0791 22                 1100 	ret
                           1101 ;------------------------------------------------------------
                           1102 ;Allocation info for local variables in function 'ioRxSignals'
                           1103 ;------------------------------------------------------------
                    00B8   1104 	G$ioRxSignals$0$0 ==.
                    00B8   1105 	C$twitch_mx_xbee.c$186$2$14 ==.
                           1106 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:186: uint8 ioRxSignals()
                           1107 ;	-----------------------------------------
                           1108 ;	 function ioRxSignals
                           1109 ;	-----------------------------------------
   0792                    1110 _ioRxSignals:
                    00B8   1111 	C$twitch_mx_xbee.c$188$1$14 ==.
                           1112 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:188: uint8 signals = 0;
   0792 7F 00              1113 	mov	r7,#0x00
                    00BA   1114 	C$twitch_mx_xbee.c$190$1$1 ==.
                           1115 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:190: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   0794 90 21 C4           1116 	mov	dptr,#_param_CD_pin
   0797 E4                 1117 	clr	a
   0798 93                 1118 	movc	a,@a+dptr
   0799 FB                 1119 	mov	r3,a
   079A 74 01              1120 	mov	a,#0x01
   079C 93                 1121 	movc	a,@a+dptr
   079D FC                 1122 	mov	r4,a
   079E 74 02              1123 	mov	a,#0x02
   07A0 93                 1124 	movc	a,@a+dptr
   07A1 FD                 1125 	mov	r5,a
   07A2 74 03              1126 	mov	a,#0x03
   07A4 93                 1127 	movc	a,@a+dptr
   07A5 FE                 1128 	mov	r6,a
   07A6 20 E7 0B           1129 	jb	acc.7,00105$
   07A9 8B 82              1130 	mov	dpl,r3
   07AB C0 07              1131 	push	ar7
   07AD 12 1F D2           1132 	lcall	_isPinHigh
   07B0 D0 07              1133 	pop	ar7
   07B2 40 20              1134 	jc	00101$
   07B4                    1135 00105$:
                    00DA   1136 	C$twitch_mx_xbee.c$191$1$1 ==.
                           1137 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:191: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   07B4 90 21 B4           1138 	mov	dptr,#_param_nCD_pin
   07B7 E4                 1139 	clr	a
   07B8 93                 1140 	movc	a,@a+dptr
   07B9 FB                 1141 	mov	r3,a
   07BA 74 01              1142 	mov	a,#0x01
   07BC 93                 1143 	movc	a,@a+dptr
   07BD FC                 1144 	mov	r4,a
   07BE 74 02              1145 	mov	a,#0x02
   07C0 93                 1146 	movc	a,@a+dptr
   07C1 FD                 1147 	mov	r5,a
   07C2 74 03              1148 	mov	a,#0x03
   07C4 93                 1149 	movc	a,@a+dptr
   07C5 FE                 1150 	mov	r6,a
   07C6 20 E7 0D           1151 	jb	acc.7,00102$
   07C9 8B 82              1152 	mov	dpl,r3
   07CB C0 07              1153 	push	ar7
   07CD 12 1F D2           1154 	lcall	_isPinHigh
   07D0 D0 07              1155 	pop	ar7
   07D2 40 02              1156 	jc	00102$
   07D4                    1157 00101$:
                    00FA   1158 	C$twitch_mx_xbee.c$193$2$2 ==.
                           1159 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:193: signals |= 2;
   07D4 7F 02              1160 	mov	r7,#0x02
   07D6                    1161 00102$:
                    00FC   1162 	C$twitch_mx_xbee.c$196$1$1 ==.
                           1163 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:196: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   07D6 90 21 C0           1164 	mov	dptr,#_param_DSR_pin
   07D9 E4                 1165 	clr	a
   07DA 93                 1166 	movc	a,@a+dptr
   07DB FB                 1167 	mov	r3,a
   07DC 74 01              1168 	mov	a,#0x01
   07DE 93                 1169 	movc	a,@a+dptr
   07DF FC                 1170 	mov	r4,a
   07E0 74 02              1171 	mov	a,#0x02
   07E2 93                 1172 	movc	a,@a+dptr
   07E3 FD                 1173 	mov	r5,a
   07E4 74 03              1174 	mov	a,#0x03
   07E6 93                 1175 	movc	a,@a+dptr
   07E7 FE                 1176 	mov	r6,a
   07E8 20 E7 0B           1177 	jb	acc.7,00110$
   07EB 8B 82              1178 	mov	dpl,r3
   07ED C0 07              1179 	push	ar7
   07EF 12 1F D2           1180 	lcall	_isPinHigh
   07F2 D0 07              1181 	pop	ar7
   07F4 40 20              1182 	jc	00106$
   07F6                    1183 00110$:
                    011C   1184 	C$twitch_mx_xbee.c$197$1$1 ==.
                           1185 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:197: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   07F6 90 21 B0           1186 	mov	dptr,#_param_nDSR_pin
   07F9 E4                 1187 	clr	a
   07FA 93                 1188 	movc	a,@a+dptr
   07FB FB                 1189 	mov	r3,a
   07FC 74 01              1190 	mov	a,#0x01
   07FE 93                 1191 	movc	a,@a+dptr
   07FF FC                 1192 	mov	r4,a
   0800 74 02              1193 	mov	a,#0x02
   0802 93                 1194 	movc	a,@a+dptr
   0803 FD                 1195 	mov	r5,a
   0804 74 03              1196 	mov	a,#0x03
   0806 93                 1197 	movc	a,@a+dptr
   0807 FE                 1198 	mov	r6,a
   0808 20 E7 0E           1199 	jb	acc.7,00107$
   080B 8B 82              1200 	mov	dpl,r3
   080D C0 07              1201 	push	ar7
   080F 12 1F D2           1202 	lcall	_isPinHigh
   0812 D0 07              1203 	pop	ar7
   0814 40 03              1204 	jc	00107$
   0816                    1205 00106$:
                    013C   1206 	C$twitch_mx_xbee.c$199$2$3 ==.
                           1207 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:199: signals |= 1;
   0816 43 07 01           1208 	orl	ar7,#0x01
   0819                    1209 00107$:
                    013F   1210 	C$twitch_mx_xbee.c$202$1$1 ==.
                           1211 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:202: return signals;
   0819 8F 82              1212 	mov	dpl,r7
                    0141   1213 	C$twitch_mx_xbee.c$203$1$1 ==.
                    0141   1214 	XG$ioRxSignals$0$0 ==.
   081B 22                 1215 	ret
                           1216 ;------------------------------------------------------------
                           1217 ;Allocation info for local variables in function 'ioTxSignals'
                           1218 ;------------------------------------------------------------
                    0142   1219 	G$ioTxSignals$0$0 ==.
                    0142   1220 	C$twitch_mx_xbee.c$209$1$1 ==.
                           1221 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:209: void ioTxSignals(uint8 signals)
                           1222 ;	-----------------------------------------
                           1223 ;	 function ioTxSignals
                           1224 ;	-----------------------------------------
   081C                    1225 _ioTxSignals:
   081C E5 82              1226 	mov	a,dpl
   081E 78 20              1227 	mov	r0,#_ioTxSignals_signals_1_1
   0820 F2                 1228 	movx	@r0,a
                    0147   1229 	C$twitch_mx_xbee.c$215$1$1 ==.
                           1230 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:215: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   0821 78 20              1231 	mov	r0,#_ioTxSignals_signals_1_1
   0823 E2                 1232 	movx	a,@r0
   0824 54 01              1233 	anl	a,#0x01
   0826 FE                 1234 	mov	r6,a
   0827 B4 01 00           1235 	cjne	a,#0x01,00112$
   082A                    1236 00112$:
   082A E4                 1237 	clr	a
   082B 33                 1238 	rlc	a
   082C 24 FF              1239 	add	a,#0xff
   082E 92 04              1240 	mov	_ioTxSignals_sloc0_1_0,c
   0830 90 21 A8           1241 	mov	dptr,#_param_nDTR_pin
   0833 E4                 1242 	clr	a
   0834 93                 1243 	movc	a,@a+dptr
   0835 FA                 1244 	mov	r2,a
   0836 74 01              1245 	mov	a,#0x01
   0838 93                 1246 	movc	a,@a+dptr
   0839 74 02              1247 	mov	a,#0x02
   083B 93                 1248 	movc	a,@a+dptr
   083C 74 03              1249 	mov	a,#0x03
   083E 93                 1250 	movc	a,@a+dptr
   083F 8A 82              1251 	mov	dpl,r2
   0841 A2 04              1252 	mov	c,_ioTxSignals_sloc0_1_0
   0843 92 F0              1253 	mov	b[0],c
   0845 C0 06              1254 	push	ar6
   0847 85 F0 24           1255 	mov	bits,b
   084A 12 1C BB           1256 	lcall	_setDigitalOutput
   084D D0 06              1257 	pop	ar6
                    0175   1258 	C$twitch_mx_xbee.c$216$1$1 ==.
                           1259 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:216: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   084F 78 20              1260 	mov	r0,#_ioTxSignals_signals_1_1
   0851 E2                 1261 	movx	a,@r0
   0852 03                 1262 	rr	a
   0853 54 01              1263 	anl	a,#0x01
   0855 FD                 1264 	mov	r5,a
   0856 B4 01 00           1265 	cjne	a,#0x01,00113$
   0859                    1266 00113$:
   0859 E4                 1267 	clr	a
   085A 33                 1268 	rlc	a
   085B 24 FF              1269 	add	a,#0xff
   085D 92 04              1270 	mov	_ioTxSignals_sloc0_1_0,c
   085F 90 21 AC           1271 	mov	dptr,#_param_nRTS_pin
   0862 E4                 1272 	clr	a
   0863 93                 1273 	movc	a,@a+dptr
   0864 FA                 1274 	mov	r2,a
   0865 74 01              1275 	mov	a,#0x01
   0867 93                 1276 	movc	a,@a+dptr
   0868 74 02              1277 	mov	a,#0x02
   086A 93                 1278 	movc	a,@a+dptr
   086B 74 03              1279 	mov	a,#0x03
   086D 93                 1280 	movc	a,@a+dptr
   086E 8A 82              1281 	mov	dpl,r2
   0870 A2 04              1282 	mov	c,_ioTxSignals_sloc0_1_0
   0872 92 F0              1283 	mov	b[0],c
   0874 C0 06              1284 	push	ar6
   0876 C0 05              1285 	push	ar5
   0878 85 F0 24           1286 	mov	bits,b
   087B 12 1C BB           1287 	lcall	_setDigitalOutput
   087E D0 05              1288 	pop	ar5
   0880 D0 06              1289 	pop	ar6
                    01A8   1290 	C$twitch_mx_xbee.c$219$1$1 ==.
                           1291 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:219: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0882 EE                 1292 	mov	a,r6
   0883 24 FF              1293 	add	a,#0xff
   0885 92 04              1294 	mov	_ioTxSignals_sloc0_1_0,c
   0887 90 21 B8           1295 	mov	dptr,#_param_DTR_pin
   088A E4                 1296 	clr	a
   088B 93                 1297 	movc	a,@a+dptr
   088C FB                 1298 	mov	r3,a
   088D 74 01              1299 	mov	a,#0x01
   088F 93                 1300 	movc	a,@a+dptr
   0890 74 02              1301 	mov	a,#0x02
   0892 93                 1302 	movc	a,@a+dptr
   0893 74 03              1303 	mov	a,#0x03
   0895 93                 1304 	movc	a,@a+dptr
   0896 8B 82              1305 	mov	dpl,r3
   0898 A2 04              1306 	mov	c,_ioTxSignals_sloc0_1_0
   089A 92 F0              1307 	mov	b[0],c
   089C C0 05              1308 	push	ar5
   089E 85 F0 24           1309 	mov	bits,b
   08A1 12 1C BB           1310 	lcall	_setDigitalOutput
   08A4 D0 05              1311 	pop	ar5
                    01CC   1312 	C$twitch_mx_xbee.c$220$1$1 ==.
                           1313 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:220: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   08A6 ED                 1314 	mov	a,r5
   08A7 24 FF              1315 	add	a,#0xff
   08A9 92 04              1316 	mov	_ioTxSignals_sloc0_1_0,c
   08AB 90 21 BC           1317 	mov	dptr,#_param_RTS_pin
   08AE E4                 1318 	clr	a
   08AF 93                 1319 	movc	a,@a+dptr
   08B0 FC                 1320 	mov	r4,a
   08B1 74 01              1321 	mov	a,#0x01
   08B3 93                 1322 	movc	a,@a+dptr
   08B4 74 02              1323 	mov	a,#0x02
   08B6 93                 1324 	movc	a,@a+dptr
   08B7 74 03              1325 	mov	a,#0x03
   08B9 93                 1326 	movc	a,@a+dptr
   08BA 8C 82              1327 	mov	dpl,r4
   08BC A2 04              1328 	mov	c,_ioTxSignals_sloc0_1_0
   08BE 92 F0              1329 	mov	b[0],c
   08C0 85 F0 24           1330 	mov	bits,b
   08C3 12 1C BB           1331 	lcall	_setDigitalOutput
                    01EC   1332 	C$twitch_mx_xbee.c$223$1$1 ==.
                           1333 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:223: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   08C6 78 22              1334 	mov	r0,#_ioTxSignals_lastSignals_1_1
   08C8 E2                 1335 	movx	a,@r0
   08C9 54 01              1336 	anl	a,#0x01
   08CB 60 02              1337 	jz	00115$
   08CD 80 30              1338 	sjmp	00104$
   08CF                    1339 00115$:
   08CF 78 20              1340 	mov	r0,#_ioTxSignals_signals_1_1
   08D1 E2                 1341 	movx	a,@r0
   08D2 54 01              1342 	anl	a,#0x01
   08D4 60 29              1343 	jz	00104$
                    01FC   1344 	C$twitch_mx_xbee.c$227$2$2 ==.
                           1345 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:227: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   08D6 90 21 C8           1346 	mov	dptr,#_param_arduino_DTR_pin
   08D9 E4                 1347 	clr	a
   08DA 93                 1348 	movc	a,@a+dptr
   08DB FC                 1349 	mov	r4,a
   08DC 74 01              1350 	mov	a,#0x01
   08DE 93                 1351 	movc	a,@a+dptr
   08DF 74 02              1352 	mov	a,#0x02
   08E1 93                 1353 	movc	a,@a+dptr
   08E2 74 03              1354 	mov	a,#0x03
   08E4 93                 1355 	movc	a,@a+dptr
   08E5 8C 82              1356 	mov	dpl,r4
   08E7 D2 F0              1357 	setb	b[0]
   08E9 85 F0 24           1358 	mov	bits,b
   08EC 12 1C BB           1359 	lcall	_setDigitalOutput
                    0215   1360 	C$twitch_mx_xbee.c$228$2$2 ==.
                           1361 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:228: nTrstPulseStartTime = getMs();
   08EF 12 1C 5B           1362 	lcall	_getMs
   08F2 AC 82              1363 	mov	r4,dpl
   08F4 AD 83              1364 	mov	r5,dph
   08F6 AE F0              1365 	mov	r6,b
   08F8 FF                 1366 	mov	r7,a
   08F9 78 21              1367 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   08FB EC                 1368 	mov	a,r4
   08FC F2                 1369 	movx	@r0,a
   08FD 80 2F              1370 	sjmp	00105$
   08FF                    1371 00104$:
                    0225   1372 	C$twitch_mx_xbee.c$230$1$1 ==.
                           1373 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:230: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   08FF 12 1C 5B           1374 	lcall	_getMs
   0902 AC 82              1375 	mov	r4,dpl
   0904 AD 83              1376 	mov	r5,dph
   0906 AE F0              1377 	mov	r6,b
   0908 FF                 1378 	mov	r7,a
   0909 78 21              1379 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   090B D3                 1380 	setb	c
   090C E2                 1381 	movx	a,@r0
   090D 9C                 1382 	subb	a,r4
   090E F4                 1383 	cpl	a
   090F FC                 1384 	mov	r4,a
   0910 BC 02 00           1385 	cjne	r4,#0x02,00117$
   0913                    1386 00117$:
   0913 40 19              1387 	jc	00105$
                    023B   1388 	C$twitch_mx_xbee.c$232$2$3 ==.
                           1389 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:232: setDigitalOutput(param_arduino_DTR_pin, LOW);
   0915 90 21 C8           1390 	mov	dptr,#_param_arduino_DTR_pin
   0918 E4                 1391 	clr	a
   0919 93                 1392 	movc	a,@a+dptr
   091A FC                 1393 	mov	r4,a
   091B 74 01              1394 	mov	a,#0x01
   091D 93                 1395 	movc	a,@a+dptr
   091E 74 02              1396 	mov	a,#0x02
   0920 93                 1397 	movc	a,@a+dptr
   0921 74 03              1398 	mov	a,#0x03
   0923 93                 1399 	movc	a,@a+dptr
   0924 8C 82              1400 	mov	dpl,r4
   0926 C2 F0              1401 	clr	b[0]
   0928 85 F0 24           1402 	mov	bits,b
   092B 12 1C BB           1403 	lcall	_setDigitalOutput
   092E                    1404 00105$:
                    0254   1405 	C$twitch_mx_xbee.c$235$1$1 ==.
                           1406 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:235: lastSignals = signals;
   092E 78 20              1407 	mov	r0,#_ioTxSignals_signals_1_1
   0930 79 22              1408 	mov	r1,#_ioTxSignals_lastSignals_1_1
   0932 E2                 1409 	movx	a,@r0
   0933 F3                 1410 	movx	@r1,a
                    025A   1411 	C$twitch_mx_xbee.c$236$1$1 ==.
                    025A   1412 	XG$ioTxSignals$0$0 ==.
   0934 22                 1413 	ret
                           1414 ;------------------------------------------------------------
                           1415 ;Allocation info for local variables in function 'errorOccurred'
                           1416 ;------------------------------------------------------------
                    025B   1417 	G$errorOccurred$0$0 ==.
                    025B   1418 	C$twitch_mx_xbee.c$238$1$1 ==.
                           1419 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:238: void errorOccurred()
                           1420 ;	-----------------------------------------
                           1421 ;	 function errorOccurred
                           1422 ;	-----------------------------------------
   0935                    1423 _errorOccurred:
                    025B   1424 	C$twitch_mx_xbee.c$240$1$1 ==.
                           1425 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:240: lastErrorTime = (uint8)getMs();
   0935 12 1C 5B           1426 	lcall	_getMs
   0938 AC 82              1427 	mov	r4,dpl
   093A 78 1D              1428 	mov	r0,#_lastErrorTime
   093C EC                 1429 	mov	a,r4
   093D F2                 1430 	movx	@r0,a
                    0264   1431 	C$twitch_mx_xbee.c$241$1$1 ==.
                           1432 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:241: errorOccurredRecently = 1;
   093E D2 02              1433 	setb	_errorOccurredRecently
                    0266   1434 	C$twitch_mx_xbee.c$242$1$1 ==.
                    0266   1435 	XG$errorOccurred$0$0 ==.
   0940 22                 1436 	ret
                           1437 ;------------------------------------------------------------
                           1438 ;Allocation info for local variables in function 'errorService'
                           1439 ;------------------------------------------------------------
                           1440 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1441 ;------------------------------------------------------------
                    0267   1442 	G$errorService$0$0 ==.
                    0267   1443 	C$twitch_mx_xbee.c$244$1$1 ==.
                           1444 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:244: void errorService()
                           1445 ;	-----------------------------------------
                           1446 ;	 function errorService
                           1447 ;	-----------------------------------------
   0941                    1448 _errorService:
                    0267   1449 	C$twitch_mx_xbee.c$248$1$1 ==.
                           1450 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:248: if (uart1RxBufferFullOccurred)
                    0267   1451 	C$twitch_mx_xbee.c$250$2$2 ==.
                           1452 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:250: uart1RxBufferFullOccurred = 0;
   0941 10 07 02           1453 	jbc	_uart1RxBufferFullOccurred,00129$
   0944 80 03              1454 	sjmp	00102$
   0946                    1455 00129$:
                    026C   1456 	C$twitch_mx_xbee.c$251$2$2 ==.
                           1457 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:251: errorOccurred();
   0946 12 09 35           1458 	lcall	_errorOccurred
   0949                    1459 00102$:
                    026F   1460 	C$twitch_mx_xbee.c$254$1$1 ==.
                           1461 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:254: if (uart1RxFramingErrorOccurred)
                    026F   1462 	C$twitch_mx_xbee.c$256$2$3 ==.
                           1463 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:256: uart1RxFramingErrorOccurred = 0;
   0949 10 06 02           1464 	jbc	_uart1RxFramingErrorOccurred,00130$
   094C 80 41              1465 	sjmp	00106$
   094E                    1466 00130$:
                    0274   1467 	C$twitch_mx_xbee.c$259$2$3 ==.
                           1468 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:259: framingErrorActive = 1;
   094E D2 01              1469 	setb	_framingErrorActive
                    0276   1470 	C$twitch_mx_xbee.c$260$2$3 ==.
                           1471 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:260: errorOccurred();
   0950 12 09 35           1472 	lcall	_errorOccurred
                    0279   1473 	C$twitch_mx_xbee.c$262$2$3 ==.
                           1474 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:262: if (param_framing_error_ms > 0)
   0953 90 21 CC           1475 	mov	dptr,#_param_framing_error_ms
   0956 E4                 1476 	clr	a
   0957 93                 1477 	movc	a,@a+dptr
   0958 FC                 1478 	mov	r4,a
   0959 74 01              1479 	mov	a,#0x01
   095B 93                 1480 	movc	a,@a+dptr
   095C FD                 1481 	mov	r5,a
   095D 74 02              1482 	mov	a,#0x02
   095F 93                 1483 	movc	a,@a+dptr
   0960 FE                 1484 	mov	r6,a
   0961 74 03              1485 	mov	a,#0x03
   0963 93                 1486 	movc	a,@a+dptr
   0964 FF                 1487 	mov	r7,a
   0965 C3                 1488 	clr	c
   0966 E4                 1489 	clr	a
   0967 9C                 1490 	subb	a,r4
   0968 E4                 1491 	clr	a
   0969 9D                 1492 	subb	a,r5
   096A E4                 1493 	clr	a
   096B 9E                 1494 	subb	a,r6
   096C E4                 1495 	clr	a
   096D 64 80              1496 	xrl	a,#0x80
   096F 8F F0              1497 	mov	b,r7
   0971 63 F0 80           1498 	xrl	b,#0x80
   0974 95 F0              1499 	subb	a,b
   0976 50 17              1500 	jnc	00106$
                    029E   1501 	C$twitch_mx_xbee.c$265$3$4 ==.
                           1502 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:265: U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
   0978 AF F8              1503 	mov	r7,_U1CSR
   097A 53 07 BF           1504 	anl	ar7,#0xBF
   097D 8F F8              1505 	mov	_U1CSR,r7
                    02A5   1506 	C$twitch_mx_xbee.c$266$3$4 ==.
                           1507 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:266: uartRxDisabled = 1;
   097F D2 00              1508 	setb	_uartRxDisabled
                    02A7   1509 	C$twitch_mx_xbee.c$267$3$4 ==.
                           1510 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:267: lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
   0981 12 1C 5B           1511 	lcall	_getMs
   0984 AC 82              1512 	mov	r4,dpl
   0986 AD 83              1513 	mov	r5,dph
   0988 AE F0              1514 	mov	r6,b
   098A FF                 1515 	mov	r7,a
   098B 78 23              1516 	mov	r0,#_errorService_lastRxLowTime_1_1
   098D EC                 1517 	mov	a,r4
   098E F2                 1518 	movx	@r0,a
   098F                    1519 00106$:
                    02B5   1520 	C$twitch_mx_xbee.c$271$1$1 ==.
                           1521 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:271: if (framingErrorActive)
   098F 30 01 0F           1522 	jnb	_framingErrorActive,00111$
                    02B8   1523 	C$twitch_mx_xbee.c$273$2$5 ==.
                           1524 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:273: if (!isPinHigh(17))
   0992 75 82 11           1525 	mov	dpl,#0x11
   0995 12 1F D2           1526 	lcall	_isPinHigh
   0998 40 05              1527 	jc	00108$
                    02C0   1528 	C$twitch_mx_xbee.c$275$3$6 ==.
                           1529 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:275: errorOccurred();
   099A 12 09 35           1530 	lcall	_errorOccurred
   099D 80 02              1531 	sjmp	00111$
   099F                    1532 00108$:
                    02C5   1533 	C$twitch_mx_xbee.c$279$3$7 ==.
                           1534 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:279: framingErrorActive = 0;
   099F C2 01              1535 	clr	_framingErrorActive
   09A1                    1536 00111$:
                    02C7   1537 	C$twitch_mx_xbee.c$283$1$1 ==.
                           1538 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:283: if (uartRxDisabled)
   09A1 30 00 60           1539 	jnb	_uartRxDisabled,00119$
                    02CA   1540 	C$twitch_mx_xbee.c$285$2$8 ==.
                           1541 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:285: if (!isPinHigh(17))
   09A4 75 82 11           1542 	mov	dpl,#0x11
   09A7 12 1F D2           1543 	lcall	_isPinHigh
   09AA 40 10              1544 	jc	00115$
                    02D2   1545 	C$twitch_mx_xbee.c$288$3$9 ==.
                           1546 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:288: lastRxLowTime = (uint8)getMs();
   09AC 12 1C 5B           1547 	lcall	_getMs
   09AF AC 82              1548 	mov	r4,dpl
   09B1 AD 83              1549 	mov	r5,dph
   09B3 AE F0              1550 	mov	r6,b
   09B5 FF                 1551 	mov	r7,a
   09B6 78 23              1552 	mov	r0,#_errorService_lastRxLowTime_1_1
   09B8 EC                 1553 	mov	a,r4
   09B9 F2                 1554 	movx	@r0,a
   09BA 80 48              1555 	sjmp	00119$
   09BC                    1556 00115$:
                    02E2   1557 	C$twitch_mx_xbee.c$290$2$8 ==.
                           1558 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:290: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   09BC 12 1C 5B           1559 	lcall	_getMs
   09BF AC 82              1560 	mov	r4,dpl
   09C1 AD 83              1561 	mov	r5,dph
   09C3 78 23              1562 	mov	r0,#_errorService_lastRxLowTime_1_1
   09C5 D3                 1563 	setb	c
   09C6 E2                 1564 	movx	a,@r0
   09C7 9C                 1565 	subb	a,r4
   09C8 F4                 1566 	cpl	a
   09C9 FC                 1567 	mov	r4,a
   09CA 90 21 CC           1568 	mov	dptr,#_param_framing_error_ms
   09CD E4                 1569 	clr	a
   09CE 93                 1570 	movc	a,@a+dptr
   09CF F5 26              1571 	mov	_errorService_sloc0_1_0,a
   09D1 74 01              1572 	mov	a,#0x01
   09D3 93                 1573 	movc	a,@a+dptr
   09D4 F5 27              1574 	mov	(_errorService_sloc0_1_0 + 1),a
   09D6 74 02              1575 	mov	a,#0x02
   09D8 93                 1576 	movc	a,@a+dptr
   09D9 F5 28              1577 	mov	(_errorService_sloc0_1_0 + 2),a
   09DB 74 03              1578 	mov	a,#0x03
   09DD 93                 1579 	movc	a,@a+dptr
   09DE F5 29              1580 	mov	(_errorService_sloc0_1_0 + 3),a
   09E0 8C 02              1581 	mov	ar2,r4
   09E2 7C 00              1582 	mov	r4,#0x00
   09E4 7E 00              1583 	mov	r6,#0x00
   09E6 7F 00              1584 	mov	r7,#0x00
   09E8 C3                 1585 	clr	c
   09E9 E5 26              1586 	mov	a,_errorService_sloc0_1_0
   09EB 9A                 1587 	subb	a,r2
   09EC E5 27              1588 	mov	a,(_errorService_sloc0_1_0 + 1)
   09EE 9C                 1589 	subb	a,r4
   09EF E5 28              1590 	mov	a,(_errorService_sloc0_1_0 + 2)
   09F1 9E                 1591 	subb	a,r6
   09F2 E5 29              1592 	mov	a,(_errorService_sloc0_1_0 + 3)
   09F4 64 80              1593 	xrl	a,#0x80
   09F6 8F F0              1594 	mov	b,r7
   09F8 63 F0 80           1595 	xrl	b,#0x80
   09FB 95 F0              1596 	subb	a,b
   09FD 50 05              1597 	jnc	00119$
                    0325   1598 	C$twitch_mx_xbee.c$293$3$10 ==.
                           1599 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:293: U1CSR |= 0x40;
   09FF 43 F8 40           1600 	orl	_U1CSR,#0x40
                    0328   1601 	C$twitch_mx_xbee.c$294$3$10 ==.
                           1602 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:294: uartRxDisabled = 0;
   0A02 C2 00              1603 	clr	_uartRxDisabled
   0A04                    1604 00119$:
                    032A   1605 	C$twitch_mx_xbee.c$297$1$1 ==.
                    032A   1606 	XG$errorService$0$0 ==.
   0A04 22                 1607 	ret
                           1608 ;------------------------------------------------------------
                           1609 ;Allocation info for local variables in function 'uartToRadioService'
                           1610 ;------------------------------------------------------------
                    032B   1611 	G$uartToRadioService$0$0 ==.
                    032B   1612 	C$twitch_mx_xbee.c$300$1$1 ==.
                           1613 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:300: void uartToRadioService()
                           1614 ;	-----------------------------------------
                           1615 ;	 function uartToRadioService
                           1616 ;	-----------------------------------------
   0A05                    1617 _uartToRadioService:
                    032B   1618 	C$twitch_mx_xbee.c$303$1$1 ==.
                           1619 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:303: while(uart1RxAvailable() && radioComTxAvailable())
   0A05                    1620 00102$:
   0A05 12 0D 5C           1621 	lcall	_uart1RxAvailable
   0A08 E5 82              1622 	mov	a,dpl
   0A0A 60 0F              1623 	jz	00104$
   0A0C 12 16 11           1624 	lcall	_radioComTxAvailable
   0A0F E5 82              1625 	mov	a,dpl
   0A11 60 08              1626 	jz	00104$
                    0339   1627 	C$twitch_mx_xbee.c$305$2$2 ==.
                           1628 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:305: radioComTxSendByte(uart1RxReceiveByte());
   0A13 12 0D 64           1629 	lcall	_uart1RxReceiveByte
   0A16 12 16 28           1630 	lcall	_radioComTxSendByte
   0A19 80 EA              1631 	sjmp	00102$
   0A1B                    1632 00104$:
                    0341   1633 	C$twitch_mx_xbee.c$318$1$1 ==.
                           1634 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:318: ioTxSignals(radioComRxControlSignals());
   0A1B 12 15 A6           1635 	lcall	_radioComRxControlSignals
   0A1E 12 08 1C           1636 	lcall	_ioTxSignals
                    0347   1637 	C$twitch_mx_xbee.c$319$1$1 ==.
                           1638 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:319: radioComTxControlSignals(ioRxSignals());
   0A21 12 07 92           1639 	lcall	_ioRxSignals
   0A24 12 16 5C           1640 	lcall	_radioComTxControlSignals
                    034D   1641 	C$twitch_mx_xbee.c$320$1$1 ==.
                    034D   1642 	XG$uartToRadioService$0$0 ==.
   0A27 22                 1643 	ret
                           1644 ;------------------------------------------------------------
                           1645 ;Allocation info for local variables in function 'CmdrReadMsgs'
                           1646 ;------------------------------------------------------------
                    034E   1647 	G$CmdrReadMsgs$0$0 ==.
                    034E   1648 	C$twitch_mx_xbee.c$350$1$1 ==.
                           1649 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:350: uint8 CmdrReadMsgs(){
                           1650 ;	-----------------------------------------
                           1651 ;	 function CmdrReadMsgs
                           1652 ;	-----------------------------------------
   0A28                    1653 _CmdrReadMsgs:
                    034E   1654 	C$twitch_mx_xbee.c$352$3$5 ==.
                           1655 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:352: while(radioComRxAvailable() > 0){
   0A28                    1656 00119$:
   0A28 12 15 82           1657 	lcall	_radioComRxAvailable
   0A2B E5 82              1658 	mov	a,dpl
   0A2D 70 03              1659 	jnz	00134$
   0A2F 02 0B 04           1660 	ljmp	00121$
   0A32                    1661 00134$:
                    0358   1662 	C$twitch_mx_xbee.c$353$2$2 ==.
                           1663 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:353: if(index_cmdr == -1){         // looking for new packet
   0A32 78 17              1664 	mov	r0,#_index_cmdr
   0A34 E2                 1665 	movx	a,@r0
   0A35 B4 FF 12           1666 	cjne	a,#0xFF,00117$
                    035E   1667 	C$twitch_mx_xbee.c$354$3$3 ==.
                           1668 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:354: if(radioComRxReceiveByte() == 0xff){ //read until packet start
   0A38 12 15 89           1669 	lcall	_radioComRxReceiveByte
   0A3B AF 82              1670 	mov	r7,dpl
   0A3D BF FF E8           1671 	cjne	r7,#0xFF,00119$
                    0366   1672 	C$twitch_mx_xbee.c$355$4$4 ==.
                           1673 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:355: index_cmdr = 0;
   0A40 78 17              1674 	mov	r0,#_index_cmdr
   0A42 E4                 1675 	clr	a
   0A43 F2                 1676 	movx	@r0,a
                    036A   1677 	C$twitch_mx_xbee.c$356$4$4 ==.
                           1678 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:356: checksum_cmdr = 0;
   0A44 78 18              1679 	mov	r0,#_checksum_cmdr
   0A46 E4                 1680 	clr	a
   0A47 F2                 1681 	movx	@r0,a
   0A48 80 DE              1682 	sjmp	00119$
   0A4A                    1683 00117$:
                    0370   1684 	C$twitch_mx_xbee.c$358$2$2 ==.
                           1685 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:358: }else if(index_cmdr == 0){
   0A4A 78 17              1686 	mov	r0,#_index_cmdr
   0A4C E2                 1687 	movx	a,@r0
   0A4D 70 2A              1688 	jnz	00114$
                    0375   1689 	C$twitch_mx_xbee.c$360$3$5 ==.
                           1690 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:360: vals[index_cmdr] = (unsigned char) radioComRxReceiveByte();
   0A4F 78 17              1691 	mov	r0,#_index_cmdr
   0A51 E2                 1692 	movx	a,@r0
   0A52 24 10              1693 	add	a,#_vals
   0A54 F9                 1694 	mov	r1,a
   0A55 C0 01              1695 	push	ar1
   0A57 12 15 89           1696 	lcall	_radioComRxReceiveByte
   0A5A E5 82              1697 	mov	a,dpl
   0A5C D0 01              1698 	pop	ar1
   0A5E F3                 1699 	movx	@r1,a
                    0385   1700 	C$twitch_mx_xbee.c$363$3$5 ==.
                           1701 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:363: if(vals[index_cmdr] != 0xff){
   0A5F 78 17              1702 	mov	r0,#_index_cmdr
   0A61 E2                 1703 	movx	a,@r0
   0A62 24 10              1704 	add	a,#_vals
   0A64 F9                 1705 	mov	r1,a
   0A65 E3                 1706 	movx	a,@r1
   0A66 FF                 1707 	mov	r7,a
   0A67 BF FF 02           1708 	cjne	r7,#0xFF,00140$
   0A6A 80 BC              1709 	sjmp	00119$
   0A6C                    1710 00140$:
                    0392   1711 	C$twitch_mx_xbee.c$364$4$6 ==.
                           1712 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:364: checksum_cmdr += (uint8) vals[index_cmdr];
   0A6C 78 18              1713 	mov	r0,#_checksum_cmdr
   0A6E E2                 1714 	movx	a,@r0
   0A6F 2F                 1715 	add	a,r7
   0A70 F2                 1716 	movx	@r0,a
                    0397   1717 	C$twitch_mx_xbee.c$365$4$6 ==.
                           1718 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:365: index_cmdr++;
   0A71 78 17              1719 	mov	r0,#_index_cmdr
   0A73 E2                 1720 	movx	a,@r0
   0A74 24 01              1721 	add	a,#0x01
   0A76 F2                 1722 	movx	@r0,a
   0A77 80 AF              1723 	sjmp	00119$
   0A79                    1724 00114$:
                    039F   1725 	C$twitch_mx_xbee.c$368$3$7 ==.
                           1726 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:368: vals[index_cmdr] = (unsigned char) radioComRxReceiveByte(); 
   0A79 78 17              1727 	mov	r0,#_index_cmdr
   0A7B E2                 1728 	movx	a,@r0
   0A7C 24 10              1729 	add	a,#_vals
   0A7E F9                 1730 	mov	r1,a
   0A7F C0 01              1731 	push	ar1
   0A81 12 15 89           1732 	lcall	_radioComRxReceiveByte
   0A84 E5 82              1733 	mov	a,dpl
   0A86 D0 01              1734 	pop	ar1
   0A88 F3                 1735 	movx	@r1,a
                    03AF   1736 	C$twitch_mx_xbee.c$371$3$7 ==.
                           1737 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:371: checksum_cmdr += (uint8) vals[index_cmdr];
   0A89 78 17              1738 	mov	r0,#_index_cmdr
   0A8B E2                 1739 	movx	a,@r0
   0A8C 24 10              1740 	add	a,#_vals
   0A8E F9                 1741 	mov	r1,a
   0A8F E3                 1742 	movx	a,@r1
   0A90 FF                 1743 	mov	r7,a
   0A91 78 18              1744 	mov	r0,#_checksum_cmdr
   0A93 E2                 1745 	movx	a,@r0
   0A94 2F                 1746 	add	a,r7
   0A95 F2                 1747 	movx	@r0,a
                    03BC   1748 	C$twitch_mx_xbee.c$372$3$7 ==.
                           1749 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:372: index_cmdr++;
   0A96 78 17              1750 	mov	r0,#_index_cmdr
   0A98 E2                 1751 	movx	a,@r0
   0A99 24 01              1752 	add	a,#0x01
   0A9B F2                 1753 	movx	@r0,a
                    03C2   1754 	C$twitch_mx_xbee.c$378$3$7 ==.
                           1755 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:378: if(index_cmdr == 7){ // packet complete
   0A9C 78 17              1756 	mov	r0,#_index_cmdr
   0A9E E2                 1757 	movx	a,@r0
   0A9F B4 07 86           1758 	cjne	a,#0x07,00119$
                    03C8   1759 	C$twitch_mx_xbee.c$382$4$8 ==.
                           1760 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:382: if(checksum_cmdr%256 != 255){
   0AA2 78 18              1761 	mov	r0,#_checksum_cmdr
   0AA4 E2                 1762 	movx	a,@r0
   0AA5 FE                 1763 	mov	r6,a
   0AA6 7F 00              1764 	mov	r7,#0x00
   0AA8 78 3E              1765 	mov	r0,#__modsint_PARM_2
   0AAA E4                 1766 	clr	a
   0AAB F2                 1767 	movx	@r0,a
   0AAC 08                 1768 	inc	r0
   0AAD 74 01              1769 	mov	a,#0x01
   0AAF F2                 1770 	movx	@r0,a
   0AB0 8E 82              1771 	mov	dpl,r6
   0AB2 8F 83              1772 	mov	dph,r7
   0AB4 12 19 D2           1773 	lcall	__modsint
   0AB7 AE 82              1774 	mov	r6,dpl
   0AB9 AF 83              1775 	mov	r7,dph
   0ABB BE FF 05           1776 	cjne	r6,#0xFF,00143$
   0ABE BF 00 02           1777 	cjne	r7,#0x00,00143$
   0AC1 80 0A              1778 	sjmp	00106$
   0AC3                    1779 00143$:
                    03E9   1780 	C$twitch_mx_xbee.c$385$5$9 ==.
                           1781 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:385: index_cmdr = -1;
   0AC3 78 17              1782 	mov	r0,#_index_cmdr
   0AC5 74 FF              1783 	mov	a,#0xFF
   0AC7 F2                 1784 	movx	@r0,a
                    03EE   1785 	C$twitch_mx_xbee.c$386$5$9 ==.
                           1786 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:386: return 0;
   0AC8 75 82 00           1787 	mov	dpl,#0x00
   0ACB 80 3A              1788 	sjmp	00122$
   0ACD                    1789 00106$:
                    03F3   1790 	C$twitch_mx_xbee.c$453$5$10 ==.
                           1791 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:453: lookV = (signed char)( (int8)vals[0]-128 );
   0ACD 78 10              1792 	mov	r0,#_vals
   0ACF E2                 1793 	movx	a,@r0
   0AD0 78 1B              1794 	mov	r0,#_lookV
   0AD2 24 80              1795 	add	a,#0x80
   0AD4 F2                 1796 	movx	@r0,a
                    03FB   1797 	C$twitch_mx_xbee.c$454$5$10 ==.
                           1798 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:454: lookH = (signed char)( (int8)vals[1]-128 );
   0AD5 78 11              1799 	mov	r0,#(_vals + 0x0001)
   0AD7 E2                 1800 	movx	a,@r0
   0AD8 78 1C              1801 	mov	r0,#_lookH
   0ADA 24 80              1802 	add	a,#0x80
   0ADC F2                 1803 	movx	@r0,a
                    0403   1804 	C$twitch_mx_xbee.c$474$5$10 ==.
                           1805 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:474: walkV = (signed char)( (int8)vals[2]-128 );
   0ADD 78 12              1806 	mov	r0,#(_vals + 0x0002)
   0ADF E2                 1807 	movx	a,@r0
   0AE0 78 19              1808 	mov	r0,#_walkV
   0AE2 24 80              1809 	add	a,#0x80
   0AE4 F2                 1810 	movx	@r0,a
                    040B   1811 	C$twitch_mx_xbee.c$475$5$10 ==.
                           1812 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:475: walkH = (signed char)( (int8)vals[3]-128 );
   0AE5 78 13              1813 	mov	r0,#(_vals + 0x0003)
   0AE7 E2                 1814 	movx	a,@r0
   0AE8 FF                 1815 	mov	r7,a
   0AE9 78 1A              1816 	mov	r0,#_walkH
   0AEB 24 80              1817 	add	a,#0x80
   0AED F2                 1818 	movx	@r0,a
                    0414   1819 	C$twitch_mx_xbee.c$482$4$8 ==.
                           1820 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:482: index_cmdr = -1;
   0AEE 78 17              1821 	mov	r0,#_index_cmdr
   0AF0 74 FF              1822 	mov	a,#0xFF
   0AF2 F2                 1823 	movx	@r0,a
                    0419   1824 	C$twitch_mx_xbee.c$488$4$8 ==.
                           1825 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:488: while (radioComRxAvailable() > 0) { radioComRxReceiveByte(); }
   0AF3                    1826 00108$:
   0AF3 12 15 82           1827 	lcall	_radioComRxAvailable
   0AF6 E5 82              1828 	mov	a,dpl
   0AF8 60 05              1829 	jz	00110$
   0AFA 12 15 89           1830 	lcall	_radioComRxReceiveByte
   0AFD 80 F4              1831 	sjmp	00108$
   0AFF                    1832 00110$:
                    0425   1833 	C$twitch_mx_xbee.c$490$4$8 ==.
                           1834 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:490: return 1;
   0AFF 75 82 01           1835 	mov	dpl,#0x01
   0B02 80 03              1836 	sjmp	00122$
   0B04                    1837 00121$:
                    042A   1838 	C$twitch_mx_xbee.c$494$1$1 ==.
                           1839 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:494: return 0;
   0B04 75 82 00           1840 	mov	dpl,#0x00
   0B07                    1841 00122$:
                    042D   1842 	C$twitch_mx_xbee.c$495$1$1 ==.
                    042D   1843 	XG$CmdrReadMsgs$0$0 ==.
   0B07 22                 1844 	ret
                           1845 ;------------------------------------------------------------
                           1846 ;Allocation info for local variables in function 'main'
                           1847 ;------------------------------------------------------------
                    042E   1848 	G$main$0$0 ==.
                    042E   1849 	C$twitch_mx_xbee.c$502$1$1 ==.
                           1850 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:502: void main()
                           1851 ;	-----------------------------------------
                           1852 ;	 function main
                           1853 ;	-----------------------------------------
   0B08                    1854 _main:
                    042E   1855 	C$twitch_mx_xbee.c$514$1$1 ==.
                           1856 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:514: systemInit();
   0B08 12 16 70           1857 	lcall	_systemInit
                    0431   1858 	C$twitch_mx_xbee.c$516$1$1 ==.
                           1859 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:516: setDigitalOutput(param_arduino_DTR_pin, LOW);
   0B0B 90 21 C8           1860 	mov	dptr,#_param_arduino_DTR_pin
   0B0E E4                 1861 	clr	a
   0B0F 93                 1862 	movc	a,@a+dptr
   0B10 FC                 1863 	mov	r4,a
   0B11 74 01              1864 	mov	a,#0x01
   0B13 93                 1865 	movc	a,@a+dptr
   0B14 74 02              1866 	mov	a,#0x02
   0B16 93                 1867 	movc	a,@a+dptr
   0B17 74 03              1868 	mov	a,#0x03
   0B19 93                 1869 	movc	a,@a+dptr
   0B1A 8C 82              1870 	mov	dpl,r4
   0B1C C2 F0              1871 	clr	b[0]
   0B1E 85 F0 24           1872 	mov	bits,b
   0B21 12 1C BB           1873 	lcall	_setDigitalOutput
                    044A   1874 	C$twitch_mx_xbee.c$517$1$1 ==.
                           1875 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:517: ioTxSignals(0);
   0B24 75 82 00           1876 	mov	dpl,#0x00
   0B27 12 08 1C           1877 	lcall	_ioTxSignals
                    0450   1878 	C$twitch_mx_xbee.c$520$1$1 ==.
                           1879 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:520: uart1Init();
   0B2A 12 0B A9           1880 	lcall	_uart1Init
                    0453   1881 	C$twitch_mx_xbee.c$521$1$1 ==.
                           1882 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:521: uart1SetBaudRate(param_baud_rate);
   0B2D 90 21 A4           1883 	mov	dptr,#_param_baud_rate
   0B30 E4                 1884 	clr	a
   0B31 93                 1885 	movc	a,@a+dptr
   0B32 FC                 1886 	mov	r4,a
   0B33 74 01              1887 	mov	a,#0x01
   0B35 93                 1888 	movc	a,@a+dptr
   0B36 FD                 1889 	mov	r5,a
   0B37 74 02              1890 	mov	a,#0x02
   0B39 93                 1891 	movc	a,@a+dptr
   0B3A FE                 1892 	mov	r6,a
   0B3B 74 03              1893 	mov	a,#0x03
   0B3D 93                 1894 	movc	a,@a+dptr
   0B3E 8C 82              1895 	mov	dpl,r4
   0B40 8D 83              1896 	mov	dph,r5
   0B42 8E F0              1897 	mov	b,r6
   0B44 12 0B DD           1898 	lcall	_uart1SetBaudRate
                    046D   1899 	C$twitch_mx_xbee.c$522$1$1 ==.
                           1900 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:522: index_cmdr = -1;
   0B47 78 17              1901 	mov	r0,#_index_cmdr
   0B49 74 FF              1902 	mov	a,#0xFF
   0B4B F2                 1903 	movx	@r0,a
                    0472   1904 	C$twitch_mx_xbee.c$524$1$1 ==.
                           1905 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:524: if (param_serial_mode != SERIAL_MODE_USB_UART)
   0B4C 90 21 A0           1906 	mov	dptr,#_param_serial_mode
   0B4F E4                 1907 	clr	a
   0B50 93                 1908 	movc	a,@a+dptr
   0B51 FC                 1909 	mov	r4,a
   0B52 74 01              1910 	mov	a,#0x01
   0B54 93                 1911 	movc	a,@a+dptr
   0B55 FD                 1912 	mov	r5,a
   0B56 74 02              1913 	mov	a,#0x02
   0B58 93                 1914 	movc	a,@a+dptr
   0B59 FE                 1915 	mov	r6,a
   0B5A 74 03              1916 	mov	a,#0x03
   0B5C 93                 1917 	movc	a,@a+dptr
   0B5D FF                 1918 	mov	r7,a
   0B5E BC 03 0B           1919 	cjne	r4,#0x03,00113$
   0B61 BD 00 08           1920 	cjne	r5,#0x00,00113$
   0B64 BE 00 05           1921 	cjne	r6,#0x00,00113$
   0B67 BF 00 02           1922 	cjne	r7,#0x00,00113$
   0B6A 80 05              1923 	sjmp	00106$
   0B6C                    1924 00113$:
                    0492   1925 	C$twitch_mx_xbee.c$526$2$2 ==.
                           1926 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:526: radioComRxEnforceOrdering = 1;
   0B6C D2 12              1927 	setb	_radioComRxEnforceOrdering
                    0494   1928 	C$twitch_mx_xbee.c$527$2$2 ==.
                           1929 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:527: radioComInit();
   0B6E 12 15 17           1930 	lcall	_radioComInit
                    0497   1931 	C$twitch_mx_xbee.c$550$1$1 ==.
                           1932 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:550: while(1)
   0B71                    1933 00106$:
                    0497   1934 	C$twitch_mx_xbee.c$554$2$3 ==.
                           1935 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:554: boardService();
   0B71 12 16 7D           1936 	lcall	_boardService
                    049A   1937 	C$twitch_mx_xbee.c$555$2$3 ==.
                           1938 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:555: updateLeds();
   0B74 12 06 DA           1939 	lcall	_updateLeds
                    049D   1940 	C$twitch_mx_xbee.c$556$2$3 ==.
                           1941 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:556: errorService();
   0B77 12 09 41           1942 	lcall	_errorService
                    04A0   1943 	C$twitch_mx_xbee.c$558$2$3 ==.
                           1944 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:558: if (param_serial_mode != SERIAL_MODE_USB_UART)
   0B7A 90 21 A0           1945 	mov	dptr,#_param_serial_mode
   0B7D E4                 1946 	clr	a
   0B7E 93                 1947 	movc	a,@a+dptr
   0B7F FC                 1948 	mov	r4,a
   0B80 74 01              1949 	mov	a,#0x01
   0B82 93                 1950 	movc	a,@a+dptr
   0B83 FD                 1951 	mov	r5,a
   0B84 74 02              1952 	mov	a,#0x02
   0B86 93                 1953 	movc	a,@a+dptr
   0B87 FE                 1954 	mov	r6,a
   0B88 74 03              1955 	mov	a,#0x03
   0B8A 93                 1956 	movc	a,@a+dptr
   0B8B FF                 1957 	mov	r7,a
   0B8C BC 03 0B           1958 	cjne	r4,#0x03,00114$
   0B8F BD 00 08           1959 	cjne	r5,#0x00,00114$
   0B92 BE 00 05           1960 	cjne	r6,#0x00,00114$
   0B95 BF 00 02           1961 	cjne	r7,#0x00,00114$
   0B98 80 03              1962 	sjmp	00104$
   0B9A                    1963 00114$:
                    04C0   1964 	C$twitch_mx_xbee.c$560$3$4 ==.
                           1965 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:560: radioComTxService();
   0B9A 12 15 E2           1966 	lcall	_radioComTxService
   0B9D                    1967 00104$:
                    04C3   1968 	C$twitch_mx_xbee.c$567$3$5 ==.
                           1969 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:567: CmdrReadMsgs();
   0B9D 12 0A 28           1970 	lcall	_CmdrReadMsgs
                    04C6   1971 	C$twitch_mx_xbee.c$587$2$3 ==.
                           1972 ;	apps/twitch_mx_xbee/twitch_mx_xbee.c:587: delayMs(10);
   0BA0 90 00 0A           1973 	mov	dptr,#0x000A
   0BA3 12 1C 87           1974 	lcall	_delayMs
   0BA6 80 C9              1975 	sjmp	00106$
                    04CE   1976 	C$twitch_mx_xbee.c$589$1$1 ==.
                    04CE   1977 	XG$main$0$0 ==.
   0BA8 22                 1978 	ret
                           1979 	.area CSEG    (CODE)
                           1980 	.area CONST   (CODE)
                    0000   1981 G$param_serial_mode$0$0 == .
   21A0                    1982 _param_serial_mode:
   21A0 02 00 00 00        1983 	.byte #0x02,#0x00,#0x00,#0x00	;  2
                    0004   1984 G$param_baud_rate$0$0 == .
   21A4                    1985 _param_baud_rate:
   21A4 00 C2 01 00        1986 	.byte #0x00,#0xC2,#0x01,#0x00	;  115200
                    0008   1987 G$param_nDTR_pin$0$0 == .
   21A8                    1988 _param_nDTR_pin:
   21A8 0A 00 00 00        1989 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   1990 G$param_nRTS_pin$0$0 == .
   21AC                    1991 _param_nRTS_pin:
   21AC 0B 00 00 00        1992 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   1993 G$param_nDSR_pin$0$0 == .
   21B0                    1994 _param_nDSR_pin:
   21B0 0C 00 00 00        1995 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    0014   1996 G$param_nCD_pin$0$0 == .
   21B4                    1997 _param_nCD_pin:
   21B4 0D 00 00 00        1998 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0018   1999 G$param_DTR_pin$0$0 == .
   21B8                    2000 _param_DTR_pin:
   21B8 FF FF FF FF        2001 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    001C   2002 G$param_RTS_pin$0$0 == .
   21BC                    2003 _param_RTS_pin:
   21BC FF FF FF FF        2004 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0020   2005 G$param_DSR_pin$0$0 == .
   21C0                    2006 _param_DSR_pin:
   21C0 FF FF FF FF        2007 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0024   2008 G$param_CD_pin$0$0 == .
   21C4                    2009 _param_CD_pin:
   21C4 FF FF FF FF        2010 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0028   2011 G$param_arduino_DTR_pin$0$0 == .
   21C8                    2012 _param_arduino_DTR_pin:
   21C8 00 00 00 00        2013 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002C   2014 G$param_framing_error_ms$0$0 == .
   21CC                    2015 _param_framing_error_ms:
   21CC 00 00 00 00        2016 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                           2017 	.area XINIT   (CODE)
                           2018 	.area CABS    (ABS,CODE)
