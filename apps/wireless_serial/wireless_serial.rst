                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 23:15:54 2012
                              5 ;--------------------------------------------------------
                              6 	.module wireless_serial
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
                             25 	.globl _usbToUartService
                             26 	.globl _uartToRadioService
                             27 	.globl _usbToRadioService
                             28 	.globl _updateSerialMode
                             29 	.globl _errorService
                             30 	.globl _errorOccurred
                             31 	.globl _ioTxSignals
                             32 	.globl _ioRxSignals
                             33 	.globl _updateLeds
                             34 	.globl _uart1RxReceiveByte
                             35 	.globl _uart1RxAvailable
                             36 	.globl _uart1TxSendByte
                             37 	.globl _uart1TxAvailable
                             38 	.globl _uart1SetBaudRate
                             39 	.globl _uart1Init
                             40 	.globl _radioComRxControlSignals
                             41 	.globl _radioComTxControlSignals
                             42 	.globl _radioComTxSendByte
                             43 	.globl _radioComTxAvailable
                             44 	.globl _radioComTxService
                             45 	.globl _radioComRxReceiveByte
                             46 	.globl _radioComRxAvailable
                             47 	.globl _radioComInit
                             48 	.globl _radioLinkConnected
                             49 	.globl _usbComTxSendByte
                             50 	.globl _usbComTxAvailable
                             51 	.globl _usbComRxReceiveByte
                             52 	.globl _usbComRxAvailable
                             53 	.globl _usbComService
                             54 	.globl _usbComTxControlSignals
                             55 	.globl _usbComRxControlSignals
                             56 	.globl _usbShowStatusWithGreenLed
                             57 	.globl _usbInit
                             58 	.globl _isPinHigh
                             59 	.globl _setDigitalOutput
                             60 	.globl _getMs
                             61 	.globl _vinPowerPresent
                             62 	.globl _usbPowerPresent
                             63 	.globl _boardService
                             64 	.globl _systemInit
                             65 	.globl _lastErrorTime
                             66 	.globl _errorOccurredRecently
                             67 	.globl _framingErrorActive
                             68 	.globl _uartRxDisabled
                             69 	.globl _currentSerialMode
                             70 ;--------------------------------------------------------
                             71 ; special function registers
                             72 ;--------------------------------------------------------
                             73 	.area RSEG    (ABS,DATA)
   0000                      74 	.org 0x0000
                    0080     75 Fwireless_serial$P0$0$0 == 0x0080
                    0080     76 _P0	=	0x0080
                    0081     77 Fwireless_serial$SP$0$0 == 0x0081
                    0081     78 _SP	=	0x0081
                    0082     79 Fwireless_serial$DPL0$0$0 == 0x0082
                    0082     80 _DPL0	=	0x0082
                    0083     81 Fwireless_serial$DPH0$0$0 == 0x0083
                    0083     82 _DPH0	=	0x0083
                    0084     83 Fwireless_serial$DPL1$0$0 == 0x0084
                    0084     84 _DPL1	=	0x0084
                    0085     85 Fwireless_serial$DPH1$0$0 == 0x0085
                    0085     86 _DPH1	=	0x0085
                    0086     87 Fwireless_serial$U0CSR$0$0 == 0x0086
                    0086     88 _U0CSR	=	0x0086
                    0087     89 Fwireless_serial$PCON$0$0 == 0x0087
                    0087     90 _PCON	=	0x0087
                    0088     91 Fwireless_serial$TCON$0$0 == 0x0088
                    0088     92 _TCON	=	0x0088
                    0089     93 Fwireless_serial$P0IFG$0$0 == 0x0089
                    0089     94 _P0IFG	=	0x0089
                    008A     95 Fwireless_serial$P1IFG$0$0 == 0x008a
                    008A     96 _P1IFG	=	0x008a
                    008B     97 Fwireless_serial$P2IFG$0$0 == 0x008b
                    008B     98 _P2IFG	=	0x008b
                    008C     99 Fwireless_serial$PICTL$0$0 == 0x008c
                    008C    100 _PICTL	=	0x008c
                    008D    101 Fwireless_serial$P1IEN$0$0 == 0x008d
                    008D    102 _P1IEN	=	0x008d
                    008F    103 Fwireless_serial$P0INP$0$0 == 0x008f
                    008F    104 _P0INP	=	0x008f
                    0090    105 Fwireless_serial$P1$0$0 == 0x0090
                    0090    106 _P1	=	0x0090
                    0091    107 Fwireless_serial$RFIM$0$0 == 0x0091
                    0091    108 _RFIM	=	0x0091
                    0092    109 Fwireless_serial$DPS$0$0 == 0x0092
                    0092    110 _DPS	=	0x0092
                    0093    111 Fwireless_serial$MPAGE$0$0 == 0x0093
                    0093    112 _MPAGE	=	0x0093
                    0095    113 Fwireless_serial$ENDIAN$0$0 == 0x0095
                    0095    114 _ENDIAN	=	0x0095
                    0098    115 Fwireless_serial$S0CON$0$0 == 0x0098
                    0098    116 _S0CON	=	0x0098
                    009A    117 Fwireless_serial$IEN2$0$0 == 0x009a
                    009A    118 _IEN2	=	0x009a
                    009B    119 Fwireless_serial$S1CON$0$0 == 0x009b
                    009B    120 _S1CON	=	0x009b
                    009C    121 Fwireless_serial$T2CT$0$0 == 0x009c
                    009C    122 _T2CT	=	0x009c
                    009D    123 Fwireless_serial$T2PR$0$0 == 0x009d
                    009D    124 _T2PR	=	0x009d
                    009E    125 Fwireless_serial$T2CTL$0$0 == 0x009e
                    009E    126 _T2CTL	=	0x009e
                    00A0    127 Fwireless_serial$P2$0$0 == 0x00a0
                    00A0    128 _P2	=	0x00a0
                    00A1    129 Fwireless_serial$WORIRQ$0$0 == 0x00a1
                    00A1    130 _WORIRQ	=	0x00a1
                    00A2    131 Fwireless_serial$WORCTRL$0$0 == 0x00a2
                    00A2    132 _WORCTRL	=	0x00a2
                    00A3    133 Fwireless_serial$WOREVT0$0$0 == 0x00a3
                    00A3    134 _WOREVT0	=	0x00a3
                    00A4    135 Fwireless_serial$WOREVT1$0$0 == 0x00a4
                    00A4    136 _WOREVT1	=	0x00a4
                    00A5    137 Fwireless_serial$WORTIME0$0$0 == 0x00a5
                    00A5    138 _WORTIME0	=	0x00a5
                    00A6    139 Fwireless_serial$WORTIME1$0$0 == 0x00a6
                    00A6    140 _WORTIME1	=	0x00a6
                    00A8    141 Fwireless_serial$IEN0$0$0 == 0x00a8
                    00A8    142 _IEN0	=	0x00a8
                    00A9    143 Fwireless_serial$IP0$0$0 == 0x00a9
                    00A9    144 _IP0	=	0x00a9
                    00AB    145 Fwireless_serial$FWT$0$0 == 0x00ab
                    00AB    146 _FWT	=	0x00ab
                    00AC    147 Fwireless_serial$FADDRL$0$0 == 0x00ac
                    00AC    148 _FADDRL	=	0x00ac
                    00AD    149 Fwireless_serial$FADDRH$0$0 == 0x00ad
                    00AD    150 _FADDRH	=	0x00ad
                    00AE    151 Fwireless_serial$FCTL$0$0 == 0x00ae
                    00AE    152 _FCTL	=	0x00ae
                    00AF    153 Fwireless_serial$FWDATA$0$0 == 0x00af
                    00AF    154 _FWDATA	=	0x00af
                    00B1    155 Fwireless_serial$ENCDI$0$0 == 0x00b1
                    00B1    156 _ENCDI	=	0x00b1
                    00B2    157 Fwireless_serial$ENCDO$0$0 == 0x00b2
                    00B2    158 _ENCDO	=	0x00b2
                    00B3    159 Fwireless_serial$ENCCS$0$0 == 0x00b3
                    00B3    160 _ENCCS	=	0x00b3
                    00B4    161 Fwireless_serial$ADCCON1$0$0 == 0x00b4
                    00B4    162 _ADCCON1	=	0x00b4
                    00B5    163 Fwireless_serial$ADCCON2$0$0 == 0x00b5
                    00B5    164 _ADCCON2	=	0x00b5
                    00B6    165 Fwireless_serial$ADCCON3$0$0 == 0x00b6
                    00B6    166 _ADCCON3	=	0x00b6
                    00B8    167 Fwireless_serial$IEN1$0$0 == 0x00b8
                    00B8    168 _IEN1	=	0x00b8
                    00B9    169 Fwireless_serial$IP1$0$0 == 0x00b9
                    00B9    170 _IP1	=	0x00b9
                    00BA    171 Fwireless_serial$ADCL$0$0 == 0x00ba
                    00BA    172 _ADCL	=	0x00ba
                    00BB    173 Fwireless_serial$ADCH$0$0 == 0x00bb
                    00BB    174 _ADCH	=	0x00bb
                    00BC    175 Fwireless_serial$RNDL$0$0 == 0x00bc
                    00BC    176 _RNDL	=	0x00bc
                    00BD    177 Fwireless_serial$RNDH$0$0 == 0x00bd
                    00BD    178 _RNDH	=	0x00bd
                    00BE    179 Fwireless_serial$SLEEP$0$0 == 0x00be
                    00BE    180 _SLEEP	=	0x00be
                    00C0    181 Fwireless_serial$IRCON$0$0 == 0x00c0
                    00C0    182 _IRCON	=	0x00c0
                    00C1    183 Fwireless_serial$U0DBUF$0$0 == 0x00c1
                    00C1    184 _U0DBUF	=	0x00c1
                    00C2    185 Fwireless_serial$U0BAUD$0$0 == 0x00c2
                    00C2    186 _U0BAUD	=	0x00c2
                    00C4    187 Fwireless_serial$U0UCR$0$0 == 0x00c4
                    00C4    188 _U0UCR	=	0x00c4
                    00C5    189 Fwireless_serial$U0GCR$0$0 == 0x00c5
                    00C5    190 _U0GCR	=	0x00c5
                    00C6    191 Fwireless_serial$CLKCON$0$0 == 0x00c6
                    00C6    192 _CLKCON	=	0x00c6
                    00C7    193 Fwireless_serial$MEMCTR$0$0 == 0x00c7
                    00C7    194 _MEMCTR	=	0x00c7
                    00C9    195 Fwireless_serial$WDCTL$0$0 == 0x00c9
                    00C9    196 _WDCTL	=	0x00c9
                    00CA    197 Fwireless_serial$T3CNT$0$0 == 0x00ca
                    00CA    198 _T3CNT	=	0x00ca
                    00CB    199 Fwireless_serial$T3CTL$0$0 == 0x00cb
                    00CB    200 _T3CTL	=	0x00cb
                    00CC    201 Fwireless_serial$T3CCTL0$0$0 == 0x00cc
                    00CC    202 _T3CCTL0	=	0x00cc
                    00CD    203 Fwireless_serial$T3CC0$0$0 == 0x00cd
                    00CD    204 _T3CC0	=	0x00cd
                    00CE    205 Fwireless_serial$T3CCTL1$0$0 == 0x00ce
                    00CE    206 _T3CCTL1	=	0x00ce
                    00CF    207 Fwireless_serial$T3CC1$0$0 == 0x00cf
                    00CF    208 _T3CC1	=	0x00cf
                    00D0    209 Fwireless_serial$PSW$0$0 == 0x00d0
                    00D0    210 _PSW	=	0x00d0
                    00D1    211 Fwireless_serial$DMAIRQ$0$0 == 0x00d1
                    00D1    212 _DMAIRQ	=	0x00d1
                    00D2    213 Fwireless_serial$DMA1CFGL$0$0 == 0x00d2
                    00D2    214 _DMA1CFGL	=	0x00d2
                    00D3    215 Fwireless_serial$DMA1CFGH$0$0 == 0x00d3
                    00D3    216 _DMA1CFGH	=	0x00d3
                    00D4    217 Fwireless_serial$DMA0CFGL$0$0 == 0x00d4
                    00D4    218 _DMA0CFGL	=	0x00d4
                    00D5    219 Fwireless_serial$DMA0CFGH$0$0 == 0x00d5
                    00D5    220 _DMA0CFGH	=	0x00d5
                    00D6    221 Fwireless_serial$DMAARM$0$0 == 0x00d6
                    00D6    222 _DMAARM	=	0x00d6
                    00D7    223 Fwireless_serial$DMAREQ$0$0 == 0x00d7
                    00D7    224 _DMAREQ	=	0x00d7
                    00D8    225 Fwireless_serial$TIMIF$0$0 == 0x00d8
                    00D8    226 _TIMIF	=	0x00d8
                    00D9    227 Fwireless_serial$RFD$0$0 == 0x00d9
                    00D9    228 _RFD	=	0x00d9
                    00DA    229 Fwireless_serial$T1CC0L$0$0 == 0x00da
                    00DA    230 _T1CC0L	=	0x00da
                    00DB    231 Fwireless_serial$T1CC0H$0$0 == 0x00db
                    00DB    232 _T1CC0H	=	0x00db
                    00DC    233 Fwireless_serial$T1CC1L$0$0 == 0x00dc
                    00DC    234 _T1CC1L	=	0x00dc
                    00DD    235 Fwireless_serial$T1CC1H$0$0 == 0x00dd
                    00DD    236 _T1CC1H	=	0x00dd
                    00DE    237 Fwireless_serial$T1CC2L$0$0 == 0x00de
                    00DE    238 _T1CC2L	=	0x00de
                    00DF    239 Fwireless_serial$T1CC2H$0$0 == 0x00df
                    00DF    240 _T1CC2H	=	0x00df
                    00E0    241 Fwireless_serial$ACC$0$0 == 0x00e0
                    00E0    242 _ACC	=	0x00e0
                    00E1    243 Fwireless_serial$RFST$0$0 == 0x00e1
                    00E1    244 _RFST	=	0x00e1
                    00E2    245 Fwireless_serial$T1CNTL$0$0 == 0x00e2
                    00E2    246 _T1CNTL	=	0x00e2
                    00E3    247 Fwireless_serial$T1CNTH$0$0 == 0x00e3
                    00E3    248 _T1CNTH	=	0x00e3
                    00E4    249 Fwireless_serial$T1CTL$0$0 == 0x00e4
                    00E4    250 _T1CTL	=	0x00e4
                    00E5    251 Fwireless_serial$T1CCTL0$0$0 == 0x00e5
                    00E5    252 _T1CCTL0	=	0x00e5
                    00E6    253 Fwireless_serial$T1CCTL1$0$0 == 0x00e6
                    00E6    254 _T1CCTL1	=	0x00e6
                    00E7    255 Fwireless_serial$T1CCTL2$0$0 == 0x00e7
                    00E7    256 _T1CCTL2	=	0x00e7
                    00E8    257 Fwireless_serial$IRCON2$0$0 == 0x00e8
                    00E8    258 _IRCON2	=	0x00e8
                    00E9    259 Fwireless_serial$RFIF$0$0 == 0x00e9
                    00E9    260 _RFIF	=	0x00e9
                    00EA    261 Fwireless_serial$T4CNT$0$0 == 0x00ea
                    00EA    262 _T4CNT	=	0x00ea
                    00EB    263 Fwireless_serial$T4CTL$0$0 == 0x00eb
                    00EB    264 _T4CTL	=	0x00eb
                    00EC    265 Fwireless_serial$T4CCTL0$0$0 == 0x00ec
                    00EC    266 _T4CCTL0	=	0x00ec
                    00ED    267 Fwireless_serial$T4CC0$0$0 == 0x00ed
                    00ED    268 _T4CC0	=	0x00ed
                    00EE    269 Fwireless_serial$T4CCTL1$0$0 == 0x00ee
                    00EE    270 _T4CCTL1	=	0x00ee
                    00EF    271 Fwireless_serial$T4CC1$0$0 == 0x00ef
                    00EF    272 _T4CC1	=	0x00ef
                    00F0    273 Fwireless_serial$B$0$0 == 0x00f0
                    00F0    274 _B	=	0x00f0
                    00F1    275 Fwireless_serial$PERCFG$0$0 == 0x00f1
                    00F1    276 _PERCFG	=	0x00f1
                    00F2    277 Fwireless_serial$ADCCFG$0$0 == 0x00f2
                    00F2    278 _ADCCFG	=	0x00f2
                    00F3    279 Fwireless_serial$P0SEL$0$0 == 0x00f3
                    00F3    280 _P0SEL	=	0x00f3
                    00F4    281 Fwireless_serial$P1SEL$0$0 == 0x00f4
                    00F4    282 _P1SEL	=	0x00f4
                    00F5    283 Fwireless_serial$P2SEL$0$0 == 0x00f5
                    00F5    284 _P2SEL	=	0x00f5
                    00F6    285 Fwireless_serial$P1INP$0$0 == 0x00f6
                    00F6    286 _P1INP	=	0x00f6
                    00F7    287 Fwireless_serial$P2INP$0$0 == 0x00f7
                    00F7    288 _P2INP	=	0x00f7
                    00F8    289 Fwireless_serial$U1CSR$0$0 == 0x00f8
                    00F8    290 _U1CSR	=	0x00f8
                    00F9    291 Fwireless_serial$U1DBUF$0$0 == 0x00f9
                    00F9    292 _U1DBUF	=	0x00f9
                    00FA    293 Fwireless_serial$U1BAUD$0$0 == 0x00fa
                    00FA    294 _U1BAUD	=	0x00fa
                    00FB    295 Fwireless_serial$U1UCR$0$0 == 0x00fb
                    00FB    296 _U1UCR	=	0x00fb
                    00FC    297 Fwireless_serial$U1GCR$0$0 == 0x00fc
                    00FC    298 _U1GCR	=	0x00fc
                    00FD    299 Fwireless_serial$P0DIR$0$0 == 0x00fd
                    00FD    300 _P0DIR	=	0x00fd
                    00FE    301 Fwireless_serial$P1DIR$0$0 == 0x00fe
                    00FE    302 _P1DIR	=	0x00fe
                    00FF    303 Fwireless_serial$P2DIR$0$0 == 0x00ff
                    00FF    304 _P2DIR	=	0x00ff
                    FFFFD5D4    305 Fwireless_serial$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    306 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    307 Fwireless_serial$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    308 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    309 Fwireless_serial$FADDR$0$0 == 0xffffadac
                    FFFFADAC    310 _FADDR	=	0xffffadac
                    FFFFBBBA    311 Fwireless_serial$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    312 _ADC	=	0xffffbbba
                    FFFFDBDA    313 Fwireless_serial$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    314 _T1CC0	=	0xffffdbda
                    FFFFDDDC    315 Fwireless_serial$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    316 _T1CC1	=	0xffffdddc
                    FFFFDFDE    317 Fwireless_serial$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    318 _T1CC2	=	0xffffdfde
                            319 ;--------------------------------------------------------
                            320 ; special function bits
                            321 ;--------------------------------------------------------
                            322 	.area RSEG    (ABS,DATA)
   0000                     323 	.org 0x0000
                    0080    324 Fwireless_serial$P0_0$0$0 == 0x0080
                    0080    325 _P0_0	=	0x0080
                    0081    326 Fwireless_serial$P0_1$0$0 == 0x0081
                    0081    327 _P0_1	=	0x0081
                    0082    328 Fwireless_serial$P0_2$0$0 == 0x0082
                    0082    329 _P0_2	=	0x0082
                    0083    330 Fwireless_serial$P0_3$0$0 == 0x0083
                    0083    331 _P0_3	=	0x0083
                    0084    332 Fwireless_serial$P0_4$0$0 == 0x0084
                    0084    333 _P0_4	=	0x0084
                    0085    334 Fwireless_serial$P0_5$0$0 == 0x0085
                    0085    335 _P0_5	=	0x0085
                    0086    336 Fwireless_serial$P0_6$0$0 == 0x0086
                    0086    337 _P0_6	=	0x0086
                    0087    338 Fwireless_serial$P0_7$0$0 == 0x0087
                    0087    339 _P0_7	=	0x0087
                    0088    340 Fwireless_serial$_TCON_0$0$0 == 0x0088
                    0088    341 __TCON_0	=	0x0088
                    0089    342 Fwireless_serial$RFTXRXIF$0$0 == 0x0089
                    0089    343 _RFTXRXIF	=	0x0089
                    008A    344 Fwireless_serial$_TCON_2$0$0 == 0x008a
                    008A    345 __TCON_2	=	0x008a
                    008B    346 Fwireless_serial$URX0IF$0$0 == 0x008b
                    008B    347 _URX0IF	=	0x008b
                    008C    348 Fwireless_serial$_TCON_4$0$0 == 0x008c
                    008C    349 __TCON_4	=	0x008c
                    008D    350 Fwireless_serial$ADCIF$0$0 == 0x008d
                    008D    351 _ADCIF	=	0x008d
                    008E    352 Fwireless_serial$_TCON_6$0$0 == 0x008e
                    008E    353 __TCON_6	=	0x008e
                    008F    354 Fwireless_serial$URX1IF$0$0 == 0x008f
                    008F    355 _URX1IF	=	0x008f
                    0090    356 Fwireless_serial$P1_0$0$0 == 0x0090
                    0090    357 _P1_0	=	0x0090
                    0091    358 Fwireless_serial$P1_1$0$0 == 0x0091
                    0091    359 _P1_1	=	0x0091
                    0092    360 Fwireless_serial$P1_2$0$0 == 0x0092
                    0092    361 _P1_2	=	0x0092
                    0093    362 Fwireless_serial$P1_3$0$0 == 0x0093
                    0093    363 _P1_3	=	0x0093
                    0094    364 Fwireless_serial$P1_4$0$0 == 0x0094
                    0094    365 _P1_4	=	0x0094
                    0095    366 Fwireless_serial$P1_5$0$0 == 0x0095
                    0095    367 _P1_5	=	0x0095
                    0096    368 Fwireless_serial$P1_6$0$0 == 0x0096
                    0096    369 _P1_6	=	0x0096
                    0097    370 Fwireless_serial$P1_7$0$0 == 0x0097
                    0097    371 _P1_7	=	0x0097
                    0098    372 Fwireless_serial$ENCIF_0$0$0 == 0x0098
                    0098    373 _ENCIF_0	=	0x0098
                    0099    374 Fwireless_serial$ENCIF_1$0$0 == 0x0099
                    0099    375 _ENCIF_1	=	0x0099
                    009A    376 Fwireless_serial$_SOCON2$0$0 == 0x009a
                    009A    377 __SOCON2	=	0x009a
                    009B    378 Fwireless_serial$_SOCON3$0$0 == 0x009b
                    009B    379 __SOCON3	=	0x009b
                    009C    380 Fwireless_serial$_SOCON4$0$0 == 0x009c
                    009C    381 __SOCON4	=	0x009c
                    009D    382 Fwireless_serial$_SOCON5$0$0 == 0x009d
                    009D    383 __SOCON5	=	0x009d
                    009E    384 Fwireless_serial$_SOCON6$0$0 == 0x009e
                    009E    385 __SOCON6	=	0x009e
                    009F    386 Fwireless_serial$_SOCON7$0$0 == 0x009f
                    009F    387 __SOCON7	=	0x009f
                    00A0    388 Fwireless_serial$P2_0$0$0 == 0x00a0
                    00A0    389 _P2_0	=	0x00a0
                    00A1    390 Fwireless_serial$P2_1$0$0 == 0x00a1
                    00A1    391 _P2_1	=	0x00a1
                    00A2    392 Fwireless_serial$P2_2$0$0 == 0x00a2
                    00A2    393 _P2_2	=	0x00a2
                    00A3    394 Fwireless_serial$P2_3$0$0 == 0x00a3
                    00A3    395 _P2_3	=	0x00a3
                    00A4    396 Fwireless_serial$P2_4$0$0 == 0x00a4
                    00A4    397 _P2_4	=	0x00a4
                    00A5    398 Fwireless_serial$P2_5$0$0 == 0x00a5
                    00A5    399 _P2_5	=	0x00a5
                    00A6    400 Fwireless_serial$P2_6$0$0 == 0x00a6
                    00A6    401 _P2_6	=	0x00a6
                    00A7    402 Fwireless_serial$P2_7$0$0 == 0x00a7
                    00A7    403 _P2_7	=	0x00a7
                    00A8    404 Fwireless_serial$RFTXRXIE$0$0 == 0x00a8
                    00A8    405 _RFTXRXIE	=	0x00a8
                    00A9    406 Fwireless_serial$ADCIE$0$0 == 0x00a9
                    00A9    407 _ADCIE	=	0x00a9
                    00AA    408 Fwireless_serial$URX0IE$0$0 == 0x00aa
                    00AA    409 _URX0IE	=	0x00aa
                    00AB    410 Fwireless_serial$URX1IE$0$0 == 0x00ab
                    00AB    411 _URX1IE	=	0x00ab
                    00AC    412 Fwireless_serial$ENCIE$0$0 == 0x00ac
                    00AC    413 _ENCIE	=	0x00ac
                    00AD    414 Fwireless_serial$STIE$0$0 == 0x00ad
                    00AD    415 _STIE	=	0x00ad
                    00AE    416 Fwireless_serial$_IEN06$0$0 == 0x00ae
                    00AE    417 __IEN06	=	0x00ae
                    00AF    418 Fwireless_serial$EA$0$0 == 0x00af
                    00AF    419 _EA	=	0x00af
                    00B8    420 Fwireless_serial$DMAIE$0$0 == 0x00b8
                    00B8    421 _DMAIE	=	0x00b8
                    00B9    422 Fwireless_serial$T1IE$0$0 == 0x00b9
                    00B9    423 _T1IE	=	0x00b9
                    00BA    424 Fwireless_serial$T2IE$0$0 == 0x00ba
                    00BA    425 _T2IE	=	0x00ba
                    00BB    426 Fwireless_serial$T3IE$0$0 == 0x00bb
                    00BB    427 _T3IE	=	0x00bb
                    00BC    428 Fwireless_serial$T4IE$0$0 == 0x00bc
                    00BC    429 _T4IE	=	0x00bc
                    00BD    430 Fwireless_serial$P0IE$0$0 == 0x00bd
                    00BD    431 _P0IE	=	0x00bd
                    00BE    432 Fwireless_serial$_IEN16$0$0 == 0x00be
                    00BE    433 __IEN16	=	0x00be
                    00BF    434 Fwireless_serial$_IEN17$0$0 == 0x00bf
                    00BF    435 __IEN17	=	0x00bf
                    00C0    436 Fwireless_serial$DMAIF$0$0 == 0x00c0
                    00C0    437 _DMAIF	=	0x00c0
                    00C1    438 Fwireless_serial$T1IF$0$0 == 0x00c1
                    00C1    439 _T1IF	=	0x00c1
                    00C2    440 Fwireless_serial$T2IF$0$0 == 0x00c2
                    00C2    441 _T2IF	=	0x00c2
                    00C3    442 Fwireless_serial$T3IF$0$0 == 0x00c3
                    00C3    443 _T3IF	=	0x00c3
                    00C4    444 Fwireless_serial$T4IF$0$0 == 0x00c4
                    00C4    445 _T4IF	=	0x00c4
                    00C5    446 Fwireless_serial$P0IF$0$0 == 0x00c5
                    00C5    447 _P0IF	=	0x00c5
                    00C6    448 Fwireless_serial$_IRCON6$0$0 == 0x00c6
                    00C6    449 __IRCON6	=	0x00c6
                    00C7    450 Fwireless_serial$STIF$0$0 == 0x00c7
                    00C7    451 _STIF	=	0x00c7
                    00D0    452 Fwireless_serial$P$0$0 == 0x00d0
                    00D0    453 _P	=	0x00d0
                    00D1    454 Fwireless_serial$F1$0$0 == 0x00d1
                    00D1    455 _F1	=	0x00d1
                    00D2    456 Fwireless_serial$OV$0$0 == 0x00d2
                    00D2    457 _OV	=	0x00d2
                    00D3    458 Fwireless_serial$RS0$0$0 == 0x00d3
                    00D3    459 _RS0	=	0x00d3
                    00D4    460 Fwireless_serial$RS1$0$0 == 0x00d4
                    00D4    461 _RS1	=	0x00d4
                    00D5    462 Fwireless_serial$F0$0$0 == 0x00d5
                    00D5    463 _F0	=	0x00d5
                    00D6    464 Fwireless_serial$AC$0$0 == 0x00d6
                    00D6    465 _AC	=	0x00d6
                    00D7    466 Fwireless_serial$CY$0$0 == 0x00d7
                    00D7    467 _CY	=	0x00d7
                    00D8    468 Fwireless_serial$T3OVFIF$0$0 == 0x00d8
                    00D8    469 _T3OVFIF	=	0x00d8
                    00D9    470 Fwireless_serial$T3CH0IF$0$0 == 0x00d9
                    00D9    471 _T3CH0IF	=	0x00d9
                    00DA    472 Fwireless_serial$T3CH1IF$0$0 == 0x00da
                    00DA    473 _T3CH1IF	=	0x00da
                    00DB    474 Fwireless_serial$T4OVFIF$0$0 == 0x00db
                    00DB    475 _T4OVFIF	=	0x00db
                    00DC    476 Fwireless_serial$T4CH0IF$0$0 == 0x00dc
                    00DC    477 _T4CH0IF	=	0x00dc
                    00DD    478 Fwireless_serial$T4CH1IF$0$0 == 0x00dd
                    00DD    479 _T4CH1IF	=	0x00dd
                    00DE    480 Fwireless_serial$OVFIM$0$0 == 0x00de
                    00DE    481 _OVFIM	=	0x00de
                    00DF    482 Fwireless_serial$_TIMIF7$0$0 == 0x00df
                    00DF    483 __TIMIF7	=	0x00df
                    00E0    484 Fwireless_serial$ACC_0$0$0 == 0x00e0
                    00E0    485 _ACC_0	=	0x00e0
                    00E1    486 Fwireless_serial$ACC_1$0$0 == 0x00e1
                    00E1    487 _ACC_1	=	0x00e1
                    00E2    488 Fwireless_serial$ACC_2$0$0 == 0x00e2
                    00E2    489 _ACC_2	=	0x00e2
                    00E3    490 Fwireless_serial$ACC_3$0$0 == 0x00e3
                    00E3    491 _ACC_3	=	0x00e3
                    00E4    492 Fwireless_serial$ACC_4$0$0 == 0x00e4
                    00E4    493 _ACC_4	=	0x00e4
                    00E5    494 Fwireless_serial$ACC_5$0$0 == 0x00e5
                    00E5    495 _ACC_5	=	0x00e5
                    00E6    496 Fwireless_serial$ACC_6$0$0 == 0x00e6
                    00E6    497 _ACC_6	=	0x00e6
                    00E7    498 Fwireless_serial$ACC_7$0$0 == 0x00e7
                    00E7    499 _ACC_7	=	0x00e7
                    00E8    500 Fwireless_serial$P2IF$0$0 == 0x00e8
                    00E8    501 _P2IF	=	0x00e8
                    00E9    502 Fwireless_serial$UTX0IF$0$0 == 0x00e9
                    00E9    503 _UTX0IF	=	0x00e9
                    00EA    504 Fwireless_serial$UTX1IF$0$0 == 0x00ea
                    00EA    505 _UTX1IF	=	0x00ea
                    00EB    506 Fwireless_serial$P1IF$0$0 == 0x00eb
                    00EB    507 _P1IF	=	0x00eb
                    00EC    508 Fwireless_serial$WDTIF$0$0 == 0x00ec
                    00EC    509 _WDTIF	=	0x00ec
                    00ED    510 Fwireless_serial$_IRCON25$0$0 == 0x00ed
                    00ED    511 __IRCON25	=	0x00ed
                    00EE    512 Fwireless_serial$_IRCON26$0$0 == 0x00ee
                    00EE    513 __IRCON26	=	0x00ee
                    00EF    514 Fwireless_serial$_IRCON27$0$0 == 0x00ef
                    00EF    515 __IRCON27	=	0x00ef
                    00F0    516 Fwireless_serial$B_0$0$0 == 0x00f0
                    00F0    517 _B_0	=	0x00f0
                    00F1    518 Fwireless_serial$B_1$0$0 == 0x00f1
                    00F1    519 _B_1	=	0x00f1
                    00F2    520 Fwireless_serial$B_2$0$0 == 0x00f2
                    00F2    521 _B_2	=	0x00f2
                    00F3    522 Fwireless_serial$B_3$0$0 == 0x00f3
                    00F3    523 _B_3	=	0x00f3
                    00F4    524 Fwireless_serial$B_4$0$0 == 0x00f4
                    00F4    525 _B_4	=	0x00f4
                    00F5    526 Fwireless_serial$B_5$0$0 == 0x00f5
                    00F5    527 _B_5	=	0x00f5
                    00F6    528 Fwireless_serial$B_6$0$0 == 0x00f6
                    00F6    529 _B_6	=	0x00f6
                    00F7    530 Fwireless_serial$B_7$0$0 == 0x00f7
                    00F7    531 _B_7	=	0x00f7
                    00F8    532 Fwireless_serial$U1ACTIVE$0$0 == 0x00f8
                    00F8    533 _U1ACTIVE	=	0x00f8
                    00F9    534 Fwireless_serial$U1TX_BYTE$0$0 == 0x00f9
                    00F9    535 _U1TX_BYTE	=	0x00f9
                    00FA    536 Fwireless_serial$U1RX_BYTE$0$0 == 0x00fa
                    00FA    537 _U1RX_BYTE	=	0x00fa
                    00FB    538 Fwireless_serial$U1ERR$0$0 == 0x00fb
                    00FB    539 _U1ERR	=	0x00fb
                    00FC    540 Fwireless_serial$U1FE$0$0 == 0x00fc
                    00FC    541 _U1FE	=	0x00fc
                    00FD    542 Fwireless_serial$U1SLAVE$0$0 == 0x00fd
                    00FD    543 _U1SLAVE	=	0x00fd
                    00FE    544 Fwireless_serial$U1RE$0$0 == 0x00fe
                    00FE    545 _U1RE	=	0x00fe
                    00FF    546 Fwireless_serial$U1MODE$0$0 == 0x00ff
                    00FF    547 _U1MODE	=	0x00ff
                            548 ;--------------------------------------------------------
                            549 ; overlayable register banks
                            550 ;--------------------------------------------------------
                            551 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     552 	.ds 8
                            553 ;--------------------------------------------------------
                            554 ; overlayable bit register bank
                            555 ;--------------------------------------------------------
                            556 	.area BIT_BANK	(REL,OVR,DATA)
   0024                     557 bits:
   0024                     558 	.ds 1
                    8000    559 	b0 = bits[0]
                    8100    560 	b1 = bits[1]
                    8200    561 	b2 = bits[2]
                    8300    562 	b3 = bits[3]
                    8400    563 	b4 = bits[4]
                    8500    564 	b5 = bits[5]
                    8600    565 	b6 = bits[6]
                    8700    566 	b7 = bits[7]
                            567 ;--------------------------------------------------------
                            568 ; internal ram data
                            569 ;--------------------------------------------------------
                            570 	.area DSEG    (DATA)
                    0000    571 G$currentSerialMode$0$0==.
   0008                     572 _currentSerialMode::
   0008                     573 	.ds 1
                    0001    574 Lwireless_serial.updateLeds$count$3$9==.
   0009                     575 _updateLeds_count_3_9:
   0009                     576 	.ds 1
                    0002    577 Lwireless_serial.errorService$sloc0$1$0==.
   000A                     578 _errorService_sloc0_1_0:
   000A                     579 	.ds 4
                            580 ;--------------------------------------------------------
                            581 ; overlayable items in internal ram 
                            582 ;--------------------------------------------------------
                            583 	.area OSEG    (OVR,DATA)
                            584 ;--------------------------------------------------------
                            585 ; Stack segment in internal ram 
                            586 ;--------------------------------------------------------
                            587 	.area	SSEG	(DATA)
   0031                     588 __start__stack:
   0031                     589 	.ds	1
                            590 
                            591 ;--------------------------------------------------------
                            592 ; indirectly addressable internal ram data
                            593 ;--------------------------------------------------------
                            594 	.area ISEG    (DATA)
                            595 ;--------------------------------------------------------
                            596 ; absolute internal ram data
                            597 ;--------------------------------------------------------
                            598 	.area IABS    (ABS,DATA)
                            599 	.area IABS    (ABS,DATA)
                            600 ;--------------------------------------------------------
                            601 ; bit data
                            602 ;--------------------------------------------------------
                            603 	.area BSEG    (BIT)
                    0000    604 G$uartRxDisabled$0$0==.
   0000                     605 _uartRxDisabled::
   0000                     606 	.ds 1
                    0001    607 G$framingErrorActive$0$0==.
   0001                     608 _framingErrorActive::
   0001                     609 	.ds 1
                    0002    610 G$errorOccurredRecently$0$0==.
   0002                     611 _errorOccurredRecently::
   0002                     612 	.ds 1
                    0003    613 Lwireless_serial.updateLeds$dimYellowLed$1$1==.
   0003                     614 _updateLeds_dimYellowLed_1_1:
   0003                     615 	.ds 1
                    0004    616 Lwireless_serial.ioTxSignals$sloc0$1$0==.
   0004                     617 _ioTxSignals_sloc0_1_0:
   0004                     618 	.ds 1
                            619 ;--------------------------------------------------------
                            620 ; paged external ram data
                            621 ;--------------------------------------------------------
                            622 	.area PSEG    (PAG,XDATA)
                    0000    623 G$lastErrorTime$0$0==.
   F000                     624 _lastErrorTime::
   F000                     625 	.ds 1
                    0001    626 Lwireless_serial.updateLeds$lastRadioActivityTime$1$1==.
   F001                     627 _updateLeds_lastRadioActivityTime_1_1:
   F001                     628 	.ds 2
                    0003    629 Lwireless_serial.ioTxSignals$signals$1$1==.
   F003                     630 _ioTxSignals_signals_1_1:
   F003                     631 	.ds 1
                    0004    632 Lwireless_serial.ioTxSignals$nTrstPulseStartTime$1$1==.
   F004                     633 _ioTxSignals_nTrstPulseStartTime_1_1:
   F004                     634 	.ds 1
                    0005    635 Lwireless_serial.ioTxSignals$lastSignals$1$1==.
   F005                     636 _ioTxSignals_lastSignals_1_1:
   F005                     637 	.ds 1
                    0006    638 Lwireless_serial.errorService$lastRxLowTime$1$1==.
   F006                     639 _errorService_lastRxLowTime_1_1:
   F006                     640 	.ds 1
                            641 ;--------------------------------------------------------
                            642 ; external ram data
                            643 ;--------------------------------------------------------
                            644 	.area XSEG    (XDATA)
                    DF00    645 Fwireless_serial$SYNC1$0$0 == 0xdf00
                    DF00    646 _SYNC1	=	0xdf00
                    DF01    647 Fwireless_serial$SYNC0$0$0 == 0xdf01
                    DF01    648 _SYNC0	=	0xdf01
                    DF02    649 Fwireless_serial$PKTLEN$0$0 == 0xdf02
                    DF02    650 _PKTLEN	=	0xdf02
                    DF03    651 Fwireless_serial$PKTCTRL1$0$0 == 0xdf03
                    DF03    652 _PKTCTRL1	=	0xdf03
                    DF04    653 Fwireless_serial$PKTCTRL0$0$0 == 0xdf04
                    DF04    654 _PKTCTRL0	=	0xdf04
                    DF05    655 Fwireless_serial$ADDR$0$0 == 0xdf05
                    DF05    656 _ADDR	=	0xdf05
                    DF06    657 Fwireless_serial$CHANNR$0$0 == 0xdf06
                    DF06    658 _CHANNR	=	0xdf06
                    DF07    659 Fwireless_serial$FSCTRL1$0$0 == 0xdf07
                    DF07    660 _FSCTRL1	=	0xdf07
                    DF08    661 Fwireless_serial$FSCTRL0$0$0 == 0xdf08
                    DF08    662 _FSCTRL0	=	0xdf08
                    DF09    663 Fwireless_serial$FREQ2$0$0 == 0xdf09
                    DF09    664 _FREQ2	=	0xdf09
                    DF0A    665 Fwireless_serial$FREQ1$0$0 == 0xdf0a
                    DF0A    666 _FREQ1	=	0xdf0a
                    DF0B    667 Fwireless_serial$FREQ0$0$0 == 0xdf0b
                    DF0B    668 _FREQ0	=	0xdf0b
                    DF0C    669 Fwireless_serial$MDMCFG4$0$0 == 0xdf0c
                    DF0C    670 _MDMCFG4	=	0xdf0c
                    DF0D    671 Fwireless_serial$MDMCFG3$0$0 == 0xdf0d
                    DF0D    672 _MDMCFG3	=	0xdf0d
                    DF0E    673 Fwireless_serial$MDMCFG2$0$0 == 0xdf0e
                    DF0E    674 _MDMCFG2	=	0xdf0e
                    DF0F    675 Fwireless_serial$MDMCFG1$0$0 == 0xdf0f
                    DF0F    676 _MDMCFG1	=	0xdf0f
                    DF10    677 Fwireless_serial$MDMCFG0$0$0 == 0xdf10
                    DF10    678 _MDMCFG0	=	0xdf10
                    DF11    679 Fwireless_serial$DEVIATN$0$0 == 0xdf11
                    DF11    680 _DEVIATN	=	0xdf11
                    DF12    681 Fwireless_serial$MCSM2$0$0 == 0xdf12
                    DF12    682 _MCSM2	=	0xdf12
                    DF13    683 Fwireless_serial$MCSM1$0$0 == 0xdf13
                    DF13    684 _MCSM1	=	0xdf13
                    DF14    685 Fwireless_serial$MCSM0$0$0 == 0xdf14
                    DF14    686 _MCSM0	=	0xdf14
                    DF15    687 Fwireless_serial$FOCCFG$0$0 == 0xdf15
                    DF15    688 _FOCCFG	=	0xdf15
                    DF16    689 Fwireless_serial$BSCFG$0$0 == 0xdf16
                    DF16    690 _BSCFG	=	0xdf16
                    DF17    691 Fwireless_serial$AGCCTRL2$0$0 == 0xdf17
                    DF17    692 _AGCCTRL2	=	0xdf17
                    DF18    693 Fwireless_serial$AGCCTRL1$0$0 == 0xdf18
                    DF18    694 _AGCCTRL1	=	0xdf18
                    DF19    695 Fwireless_serial$AGCCTRL0$0$0 == 0xdf19
                    DF19    696 _AGCCTRL0	=	0xdf19
                    DF1A    697 Fwireless_serial$FREND1$0$0 == 0xdf1a
                    DF1A    698 _FREND1	=	0xdf1a
                    DF1B    699 Fwireless_serial$FREND0$0$0 == 0xdf1b
                    DF1B    700 _FREND0	=	0xdf1b
                    DF1C    701 Fwireless_serial$FSCAL3$0$0 == 0xdf1c
                    DF1C    702 _FSCAL3	=	0xdf1c
                    DF1D    703 Fwireless_serial$FSCAL2$0$0 == 0xdf1d
                    DF1D    704 _FSCAL2	=	0xdf1d
                    DF1E    705 Fwireless_serial$FSCAL1$0$0 == 0xdf1e
                    DF1E    706 _FSCAL1	=	0xdf1e
                    DF1F    707 Fwireless_serial$FSCAL0$0$0 == 0xdf1f
                    DF1F    708 _FSCAL0	=	0xdf1f
                    DF23    709 Fwireless_serial$TEST2$0$0 == 0xdf23
                    DF23    710 _TEST2	=	0xdf23
                    DF24    711 Fwireless_serial$TEST1$0$0 == 0xdf24
                    DF24    712 _TEST1	=	0xdf24
                    DF25    713 Fwireless_serial$TEST0$0$0 == 0xdf25
                    DF25    714 _TEST0	=	0xdf25
                    DF2E    715 Fwireless_serial$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    716 _PA_TABLE0	=	0xdf2e
                    DF2F    717 Fwireless_serial$IOCFG2$0$0 == 0xdf2f
                    DF2F    718 _IOCFG2	=	0xdf2f
                    DF30    719 Fwireless_serial$IOCFG1$0$0 == 0xdf30
                    DF30    720 _IOCFG1	=	0xdf30
                    DF31    721 Fwireless_serial$IOCFG0$0$0 == 0xdf31
                    DF31    722 _IOCFG0	=	0xdf31
                    DF36    723 Fwireless_serial$PARTNUM$0$0 == 0xdf36
                    DF36    724 _PARTNUM	=	0xdf36
                    DF37    725 Fwireless_serial$VERSION$0$0 == 0xdf37
                    DF37    726 _VERSION	=	0xdf37
                    DF38    727 Fwireless_serial$FREQEST$0$0 == 0xdf38
                    DF38    728 _FREQEST	=	0xdf38
                    DF39    729 Fwireless_serial$LQI$0$0 == 0xdf39
                    DF39    730 _LQI	=	0xdf39
                    DF3A    731 Fwireless_serial$RSSI$0$0 == 0xdf3a
                    DF3A    732 _RSSI	=	0xdf3a
                    DF3B    733 Fwireless_serial$MARCSTATE$0$0 == 0xdf3b
                    DF3B    734 _MARCSTATE	=	0xdf3b
                    DF3C    735 Fwireless_serial$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    736 _PKTSTATUS	=	0xdf3c
                    DF3D    737 Fwireless_serial$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    738 _VCO_VC_DAC	=	0xdf3d
                    DF40    739 Fwireless_serial$I2SCFG0$0$0 == 0xdf40
                    DF40    740 _I2SCFG0	=	0xdf40
                    DF41    741 Fwireless_serial$I2SCFG1$0$0 == 0xdf41
                    DF41    742 _I2SCFG1	=	0xdf41
                    DF42    743 Fwireless_serial$I2SDATL$0$0 == 0xdf42
                    DF42    744 _I2SDATL	=	0xdf42
                    DF43    745 Fwireless_serial$I2SDATH$0$0 == 0xdf43
                    DF43    746 _I2SDATH	=	0xdf43
                    DF44    747 Fwireless_serial$I2SWCNT$0$0 == 0xdf44
                    DF44    748 _I2SWCNT	=	0xdf44
                    DF45    749 Fwireless_serial$I2SSTAT$0$0 == 0xdf45
                    DF45    750 _I2SSTAT	=	0xdf45
                    DF46    751 Fwireless_serial$I2SCLKF0$0$0 == 0xdf46
                    DF46    752 _I2SCLKF0	=	0xdf46
                    DF47    753 Fwireless_serial$I2SCLKF1$0$0 == 0xdf47
                    DF47    754 _I2SCLKF1	=	0xdf47
                    DF48    755 Fwireless_serial$I2SCLKF2$0$0 == 0xdf48
                    DF48    756 _I2SCLKF2	=	0xdf48
                    DE00    757 Fwireless_serial$USBADDR$0$0 == 0xde00
                    DE00    758 _USBADDR	=	0xde00
                    DE01    759 Fwireless_serial$USBPOW$0$0 == 0xde01
                    DE01    760 _USBPOW	=	0xde01
                    DE02    761 Fwireless_serial$USBIIF$0$0 == 0xde02
                    DE02    762 _USBIIF	=	0xde02
                    DE04    763 Fwireless_serial$USBOIF$0$0 == 0xde04
                    DE04    764 _USBOIF	=	0xde04
                    DE06    765 Fwireless_serial$USBCIF$0$0 == 0xde06
                    DE06    766 _USBCIF	=	0xde06
                    DE07    767 Fwireless_serial$USBIIE$0$0 == 0xde07
                    DE07    768 _USBIIE	=	0xde07
                    DE09    769 Fwireless_serial$USBOIE$0$0 == 0xde09
                    DE09    770 _USBOIE	=	0xde09
                    DE0B    771 Fwireless_serial$USBCIE$0$0 == 0xde0b
                    DE0B    772 _USBCIE	=	0xde0b
                    DE0C    773 Fwireless_serial$USBFRML$0$0 == 0xde0c
                    DE0C    774 _USBFRML	=	0xde0c
                    DE0D    775 Fwireless_serial$USBFRMH$0$0 == 0xde0d
                    DE0D    776 _USBFRMH	=	0xde0d
                    DE0E    777 Fwireless_serial$USBINDEX$0$0 == 0xde0e
                    DE0E    778 _USBINDEX	=	0xde0e
                    DE10    779 Fwireless_serial$USBMAXI$0$0 == 0xde10
                    DE10    780 _USBMAXI	=	0xde10
                    DE11    781 Fwireless_serial$USBCSIL$0$0 == 0xde11
                    DE11    782 _USBCSIL	=	0xde11
                    DE12    783 Fwireless_serial$USBCSIH$0$0 == 0xde12
                    DE12    784 _USBCSIH	=	0xde12
                    DE13    785 Fwireless_serial$USBMAXO$0$0 == 0xde13
                    DE13    786 _USBMAXO	=	0xde13
                    DE14    787 Fwireless_serial$USBCSOL$0$0 == 0xde14
                    DE14    788 _USBCSOL	=	0xde14
                    DE15    789 Fwireless_serial$USBCSOH$0$0 == 0xde15
                    DE15    790 _USBCSOH	=	0xde15
                    DE16    791 Fwireless_serial$USBCNTL$0$0 == 0xde16
                    DE16    792 _USBCNTL	=	0xde16
                    DE17    793 Fwireless_serial$USBCNTH$0$0 == 0xde17
                    DE17    794 _USBCNTH	=	0xde17
                    DE20    795 Fwireless_serial$USBF0$0$0 == 0xde20
                    DE20    796 _USBF0	=	0xde20
                    DE22    797 Fwireless_serial$USBF1$0$0 == 0xde22
                    DE22    798 _USBF1	=	0xde22
                    DE24    799 Fwireless_serial$USBF2$0$0 == 0xde24
                    DE24    800 _USBF2	=	0xde24
                    DE26    801 Fwireless_serial$USBF3$0$0 == 0xde26
                    DE26    802 _USBF3	=	0xde26
                    DE28    803 Fwireless_serial$USBF4$0$0 == 0xde28
                    DE28    804 _USBF4	=	0xde28
                    DE2A    805 Fwireless_serial$USBF5$0$0 == 0xde2a
                    DE2A    806 _USBF5	=	0xde2a
                            807 ;--------------------------------------------------------
                            808 ; absolute external ram data
                            809 ;--------------------------------------------------------
                            810 	.area XABS    (ABS,XDATA)
                            811 ;--------------------------------------------------------
                            812 ; external initialized ram data
                            813 ;--------------------------------------------------------
                            814 	.area XISEG   (XDATA)
                            815 	.area HOME    (CODE)
                            816 	.area GSINIT0 (CODE)
                            817 	.area GSINIT1 (CODE)
                            818 	.area GSINIT2 (CODE)
                            819 	.area GSINIT3 (CODE)
                            820 	.area GSINIT4 (CODE)
                            821 	.area GSINIT5 (CODE)
                            822 	.area GSINIT  (CODE)
                            823 	.area GSFINAL (CODE)
                            824 	.area CSEG    (CODE)
                            825 ;--------------------------------------------------------
                            826 ; interrupt vector 
                            827 ;--------------------------------------------------------
                            828 	.area HOME    (CODE)
   0400                     829 __interrupt_vect:
   0400 02 04 8D            830 	ljmp	__sdcc_gsinit_startup
   0403 32                  831 	reti
   0404                     832 	.ds	7
   040B 32                  833 	reti
   040C                     834 	.ds	7
   0413 32                  835 	reti
   0414                     836 	.ds	7
   041B 02 0C 8C            837 	ljmp	_ISR_URX1
   041E                     838 	.ds	5
   0423 32                  839 	reti
   0424                     840 	.ds	7
   042B 32                  841 	reti
   042C                     842 	.ds	7
   0433 32                  843 	reti
   0434                     844 	.ds	7
   043B 32                  845 	reti
   043C                     846 	.ds	7
   0443 32                  847 	reti
   0444                     848 	.ds	7
   044B 32                  849 	reti
   044C                     850 	.ds	7
   0453 32                  851 	reti
   0454                     852 	.ds	7
   045B 32                  853 	reti
   045C                     854 	.ds	7
   0463 02 1F E3            855 	ljmp	_ISR_T4
   0466                     856 	.ds	5
   046B 32                  857 	reti
   046C                     858 	.ds	7
   0473 02 0C 4E            859 	ljmp	_ISR_UTX1
   0476                     860 	.ds	5
   047B 32                  861 	reti
   047C                     862 	.ds	7
   0483 02 10 50            863 	ljmp	_ISR_RF
                            864 ;--------------------------------------------------------
                            865 ; global & static initialisations
                            866 ;--------------------------------------------------------
                            867 	.area HOME    (CODE)
                            868 	.area GSINIT  (CODE)
                            869 	.area GSFINAL (CODE)
                            870 	.area GSINIT  (CODE)
                            871 	.globl __sdcc_gsinit_startup
                            872 	.globl __sdcc_program_startup
                            873 	.globl __start__stack
                            874 	.globl __mcs51_genXINIT
                            875 	.globl __mcs51_genXRAMCLEAR
                            876 	.globl __mcs51_genRAMCLEAR
                            877 ;------------------------------------------------------------
                            878 ;Allocation info for local variables in function 'updateLeds'
                            879 ;------------------------------------------------------------
                            880 ;count                     Allocated with name '_updateLeds_count_3_9'
                            881 ;------------------------------------------------------------
                    0000    882 	G$updateLeds$0$0 ==.
                    0000    883 	C$wireless_serial.c$82$2$16 ==.
                            884 ;	apps/wireless_serial/wireless_serial.c:82: static BIT dimYellowLed = 0;
   04E6 C2 03               885 	clr	_updateLeds_dimYellowLed_1_1
                    0002    886 	G$main$0$0 ==.
                    0002    887 	C$wireless_serial.c$69$1$1 ==.
                            888 ;	apps/wireless_serial/wireless_serial.c:69: BIT uartRxDisabled = 0;
   04E8 C2 00               889 	clr	_uartRxDisabled
                    0004    890 	G$main$0$0 ==.
                    0004    891 	C$wireless_serial.c$73$1$1 ==.
                            892 ;	apps/wireless_serial/wireless_serial.c:73: BIT framingErrorActive = 0;
   04EA C2 01               893 	clr	_framingErrorActive
                    0006    894 	G$main$0$0 ==.
                    0006    895 	C$wireless_serial.c$75$1$1 ==.
                            896 ;	apps/wireless_serial/wireless_serial.c:75: BIT errorOccurredRecently = 0;
   04EC C2 02               897 	clr	_errorOccurredRecently
                            898 	.area GSFINAL (CODE)
   0559 02 04 86            899 	ljmp	__sdcc_program_startup
                            900 ;--------------------------------------------------------
                            901 ; Home
                            902 ;--------------------------------------------------------
                            903 	.area HOME    (CODE)
                            904 	.area HOME    (CODE)
   0486                     905 __sdcc_program_startup:
   0486 12 09 B6            906 	lcall	_main
                            907 ;	return from main will lock up
   0489 80 FE               908 	sjmp .
                            909 ;--------------------------------------------------------
                            910 ; code
                            911 ;--------------------------------------------------------
                            912 	.area CSEG    (CODE)
                            913 ;------------------------------------------------------------
                            914 ;Allocation info for local variables in function 'updateLeds'
                            915 ;------------------------------------------------------------
                            916 ;count                     Allocated with name '_updateLeds_count_3_9'
                            917 ;------------------------------------------------------------
                    0000    918 	G$updateLeds$0$0 ==.
                    0000    919 	C$wireless_serial.c$80$0$0 ==.
                            920 ;	apps/wireless_serial/wireless_serial.c:80: void updateLeds()
                            921 ;	-----------------------------------------
                            922 ;	 function updateLeds
                            923 ;	-----------------------------------------
   055C                     924 _updateLeds:
                    0007    925 	ar7 = 0x07
                    0006    926 	ar6 = 0x06
                    0005    927 	ar5 = 0x05
                    0004    928 	ar4 = 0x04
                    0003    929 	ar3 = 0x03
                    0002    930 	ar2 = 0x02
                    0001    931 	ar1 = 0x01
                    0000    932 	ar0 = 0x00
                    0000    933 	C$wireless_serial.c$86$1$1 ==.
                            934 ;	apps/wireless_serial/wireless_serial.c:86: usbShowStatusWithGreenLed();
   055C 12 25 1E            935 	lcall	_usbShowStatusWithGreenLed
                    0003    936 	C$wireless_serial.c$88$1$1 ==.
                            937 ;	apps/wireless_serial/wireless_serial.c:88: now = (uint16)getMs();
   055F 12 20 08            938 	lcall	_getMs
   0562 AC 82               939 	mov	r4,dpl
   0564 AD 83               940 	mov	r5,dph
   0566 AE F0               941 	mov	r6,b
   0568 FF                  942 	mov	r7,a
                    000D    943 	C$wireless_serial.c$90$1$1 ==.
                            944 ;	apps/wireless_serial/wireless_serial.c:90: if (currentSerialMode == SERIAL_MODE_USB_UART)
   0569 74 03               945 	mov	a,#0x03
   056B B5 08 09            946 	cjne	a,_currentSerialMode,00111$
                    0012    947 	C$wireless_serial.c$93$3$3 ==.
                            948 ;	apps/wireless_serial/wireless_serial.c:93: LED_YELLOW(0);
   056E AF FF               949 	mov	r7,_P2DIR
   0570 53 07 FB            950 	anl	ar7,#0xFB
   0573 8F FF               951 	mov	_P2DIR,r7
   0575 80 59               952 	sjmp	00112$
   0577                     953 00111$:
                    001B    954 	C$wireless_serial.c$95$1$1 ==.
                            955 ;	apps/wireless_serial/wireless_serial.c:95: else if (!radioLinkConnected())
   0577 C0 05               956 	push	ar5
   0579 C0 04               957 	push	ar4
   057B 12 0D 43            958 	lcall	_radioLinkConnected
   057E D0 04               959 	pop	ar4
   0580 D0 05               960 	pop	ar5
   0582 40 12               961 	jc	00108$
                    0028    962 	C$wireless_serial.c$99$3$5 ==.
                            963 ;	apps/wireless_serial/wireless_serial.c:99: LED_YELLOW(now & 0x200 ? 1 : 0);
   0584 ED                  964 	mov	a,r5
   0585 30 E1 05            965 	jnb	acc.1,00121$
   0588 43 FF 04            966 	orl	_P2DIR,#0x04
   058B 80 43               967 	sjmp	00112$
   058D                     968 00121$:
   058D AF FF               969 	mov	r7,_P2DIR
   058F 53 07 FB            970 	anl	ar7,#0xFB
   0592 8F FF               971 	mov	_P2DIR,r7
   0594 80 3A               972 	sjmp	00112$
   0596                     973 00108$:
                    003A    974 	C$wireless_serial.c$105$2$6 ==.
                            975 ;	apps/wireless_serial/wireless_serial.c:105: if ((now & 0x3FF) <= 20)
   0596 8C 06               976 	mov	ar6,r4
   0598 74 03               977 	mov	a,#0x03
   059A 5D                  978 	anl	a,r5
   059B FF                  979 	mov	r7,a
   059C C3                  980 	clr	c
   059D 74 14               981 	mov	a,#0x14
   059F 9E                  982 	subb	a,r6
   05A0 E4                  983 	clr	a
   05A1 9F                  984 	subb	a,r7
   05A2 40 05               985 	jc	00105$
                    0048    986 	C$wireless_serial.c$108$4$8 ==.
                            987 ;	apps/wireless_serial/wireless_serial.c:108: LED_YELLOW(1);
   05A4 43 FF 04            988 	orl	_P2DIR,#0x04
   05A7 80 27               989 	sjmp	00112$
   05A9                     990 00105$:
                    004D    991 	C$wireless_serial.c$110$2$6 ==.
                            992 ;	apps/wireless_serial/wireless_serial.c:110: else if (dimYellowLed)
   05A9 30 03 1D            993 	jnb	_updateLeds_dimYellowLed_1_1,00102$
                    0050    994 	C$wireless_serial.c$113$3$9 ==.
                            995 ;	apps/wireless_serial/wireless_serial.c:113: count++;
   05AC 05 09               996 	inc	_updateLeds_count_3_9
                    0052    997 	C$wireless_serial.c$114$4$10 ==.
                            998 ;	apps/wireless_serial/wireless_serial.c:114: LED_YELLOW((count & 0x7)==0);
   05AE 74 07               999 	mov	a,#0x07
   05B0 55 09              1000 	anl	a,_updateLeds_count_3_9
   05B2 FF                 1001 	mov	r7,a
   05B3 B4 01 00           1002 	cjne	a,#0x01,00148$
   05B6                    1003 00148$:
   05B6 E4                 1004 	clr	a
   05B7 33                 1005 	rlc	a
   05B8 FF                 1006 	mov	r7,a
   05B9 60 05              1007 	jz	00123$
   05BB 43 FF 04           1008 	orl	_P2DIR,#0x04
   05BE 80 10              1009 	sjmp	00112$
   05C0                    1010 00123$:
   05C0 AF FF              1011 	mov	r7,_P2DIR
   05C2 53 07 FB           1012 	anl	ar7,#0xFB
   05C5 8F FF              1013 	mov	_P2DIR,r7
   05C7 80 07              1014 	sjmp	00112$
   05C9                    1015 00102$:
                    006D   1016 	C$wireless_serial.c$118$4$12 ==.
                           1017 ;	apps/wireless_serial/wireless_serial.c:118: LED_YELLOW(0);
   05C9 AF FF              1018 	mov	r7,_P2DIR
   05CB 53 07 FB           1019 	anl	ar7,#0xFB
   05CE 8F FF              1020 	mov	_P2DIR,r7
   05D0                    1021 00112$:
                    0074   1022 	C$wireless_serial.c$122$1$1 ==.
                           1023 ;	apps/wireless_serial/wireless_serial.c:122: if (radioLinkActivityOccurred)
                    0074   1024 	C$wireless_serial.c$124$2$13 ==.
                           1025 ;	apps/wireless_serial/wireless_serial.c:124: radioLinkActivityOccurred = 0;
   05D0 10 0D 02           1026 	jbc	_radioLinkActivityOccurred,00150$
   05D3 80 12              1027 	sjmp	00114$
   05D5                    1028 00150$:
                    0079   1029 	C$wireless_serial.c$125$2$13 ==.
                           1030 ;	apps/wireless_serial/wireless_serial.c:125: dimYellowLed ^= 1;
   05D5 A2 03              1031 	mov	c,_updateLeds_dimYellowLed_1_1
   05D7 E4                 1032 	clr	a
   05D8 33                 1033 	rlc	a
   05D9 64 01              1034 	xrl	a,#0x01
   05DB FF                 1035 	mov	r7,a
   05DC 24 FF              1036 	add	a,#0xff
   05DE 92 03              1037 	mov	_updateLeds_dimYellowLed_1_1,c
                    0084   1038 	C$wireless_serial.c$127$2$13 ==.
                           1039 ;	apps/wireless_serial/wireless_serial.c:127: lastRadioActivityTime = now;
   05E0 78 01              1040 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   05E2 EC                 1041 	mov	a,r4
   05E3 F2                 1042 	movx	@r0,a
   05E4 08                 1043 	inc	r0
   05E5 ED                 1044 	mov	a,r5
   05E6 F2                 1045 	movx	@r0,a
   05E7                    1046 00114$:
                    008B   1047 	C$wireless_serial.c$130$1$1 ==.
                           1048 ;	apps/wireless_serial/wireless_serial.c:130: if ((uint16)(now - lastRadioActivityTime) > 32)
   05E7 78 01              1049 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   05E9 D3                 1050 	setb	c
   05EA E2                 1051 	movx	a,@r0
   05EB 9C                 1052 	subb	a,r4
   05EC F4                 1053 	cpl	a
   05ED B3                 1054 	cpl	c
   05EE FE                 1055 	mov	r6,a
   05EF B3                 1056 	cpl	c
   05F0 08                 1057 	inc	r0
   05F1 E2                 1058 	movx	a,@r0
   05F2 9D                 1059 	subb	a,r5
   05F3 F4                 1060 	cpl	a
   05F4 FF                 1061 	mov	r7,a
   05F5 C3                 1062 	clr	c
   05F6 74 20              1063 	mov	a,#0x20
   05F8 9E                 1064 	subb	a,r6
   05F9 E4                 1065 	clr	a
   05FA 9F                 1066 	subb	a,r7
   05FB 50 02              1067 	jnc	00116$
                    00A1   1068 	C$wireless_serial.c$132$2$14 ==.
                           1069 ;	apps/wireless_serial/wireless_serial.c:132: dimYellowLed = 0;
   05FD C2 03              1070 	clr	_updateLeds_dimYellowLed_1_1
   05FF                    1071 00116$:
                    00A3   1072 	C$wireless_serial.c$135$1$1 ==.
                           1073 ;	apps/wireless_serial/wireless_serial.c:135: if ((uint8)(now - lastErrorTime) > 100)
   05FF 78 00              1074 	mov	r0,#_lastErrorTime
   0601 D3                 1075 	setb	c
   0602 E2                 1076 	movx	a,@r0
   0603 9C                 1077 	subb	a,r4
   0604 F4                 1078 	cpl	a
   0605 FC                 1079 	mov  r4,a
   0606 24 9B              1080 	add	a,#0xff - 0x64
   0608 50 02              1081 	jnc	00118$
                    00AE   1082 	C$wireless_serial.c$137$2$15 ==.
                           1083 ;	apps/wireless_serial/wireless_serial.c:137: errorOccurredRecently = 0;
   060A C2 02              1084 	clr	_errorOccurredRecently
   060C                    1085 00118$:
                    00B0   1086 	C$wireless_serial.c$140$2$16 ==.
                           1087 ;	apps/wireless_serial/wireless_serial.c:140: LED_RED(errorOccurredRecently || uartRxDisabled);
   060C 20 02 07           1088 	jb	_errorOccurredRecently,00128$
   060F 20 00 04           1089 	jb	_uartRxDisabled,00128$
   0612 7F 00              1090 	mov	r7,#0x00
   0614 80 02              1091 	sjmp	00129$
   0616                    1092 00128$:
   0616 7F 01              1093 	mov	r7,#0x01
   0618                    1094 00129$:
   0618 EF                 1095 	mov	a,r7
   0619 60 05              1096 	jz	00125$
   061B 43 FF 02           1097 	orl	_P2DIR,#0x02
   061E 80 07              1098 	sjmp	00119$
   0620                    1099 00125$:
   0620 AF FF              1100 	mov	r7,_P2DIR
   0622 53 07 FD           1101 	anl	ar7,#0xFD
   0625 8F FF              1102 	mov	_P2DIR,r7
   0627                    1103 00119$:
                    00CB   1104 	C$wireless_serial.c$141$2$16 ==.
                    00CB   1105 	XG$updateLeds$0$0 ==.
   0627 22                 1106 	ret
                           1107 ;------------------------------------------------------------
                           1108 ;Allocation info for local variables in function 'ioRxSignals'
                           1109 ;------------------------------------------------------------
                    00CC   1110 	G$ioRxSignals$0$0 ==.
                    00CC   1111 	C$wireless_serial.c$146$2$16 ==.
                           1112 ;	apps/wireless_serial/wireless_serial.c:146: uint8 ioRxSignals()
                           1113 ;	-----------------------------------------
                           1114 ;	 function ioRxSignals
                           1115 ;	-----------------------------------------
   0628                    1116 _ioRxSignals:
                    00CC   1117 	C$wireless_serial.c$148$1$16 ==.
                           1118 ;	apps/wireless_serial/wireless_serial.c:148: uint8 signals = 0;
   0628 7F 00              1119 	mov	r7,#0x00
                    00CE   1120 	C$wireless_serial.c$150$1$1 ==.
                           1121 ;	apps/wireless_serial/wireless_serial.c:150: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   062A 90 25 FF           1122 	mov	dptr,#_param_CD_pin
   062D E4                 1123 	clr	a
   062E 93                 1124 	movc	a,@a+dptr
   062F FB                 1125 	mov	r3,a
   0630 74 01              1126 	mov	a,#0x01
   0632 93                 1127 	movc	a,@a+dptr
   0633 FC                 1128 	mov	r4,a
   0634 74 02              1129 	mov	a,#0x02
   0636 93                 1130 	movc	a,@a+dptr
   0637 FD                 1131 	mov	r5,a
   0638 74 03              1132 	mov	a,#0x03
   063A 93                 1133 	movc	a,@a+dptr
   063B FE                 1134 	mov	r6,a
   063C 20 E7 0B           1135 	jb	acc.7,00105$
   063F 8B 82              1136 	mov	dpl,r3
   0641 C0 07              1137 	push	ar7
   0643 12 23 7F           1138 	lcall	_isPinHigh
   0646 D0 07              1139 	pop	ar7
   0648 40 20              1140 	jc	00101$
   064A                    1141 00105$:
                    00EE   1142 	C$wireless_serial.c$151$1$1 ==.
                           1143 ;	apps/wireless_serial/wireless_serial.c:151: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   064A 90 25 EF           1144 	mov	dptr,#_param_nCD_pin
   064D E4                 1145 	clr	a
   064E 93                 1146 	movc	a,@a+dptr
   064F FB                 1147 	mov	r3,a
   0650 74 01              1148 	mov	a,#0x01
   0652 93                 1149 	movc	a,@a+dptr
   0653 FC                 1150 	mov	r4,a
   0654 74 02              1151 	mov	a,#0x02
   0656 93                 1152 	movc	a,@a+dptr
   0657 FD                 1153 	mov	r5,a
   0658 74 03              1154 	mov	a,#0x03
   065A 93                 1155 	movc	a,@a+dptr
   065B FE                 1156 	mov	r6,a
   065C 20 E7 0D           1157 	jb	acc.7,00102$
   065F 8B 82              1158 	mov	dpl,r3
   0661 C0 07              1159 	push	ar7
   0663 12 23 7F           1160 	lcall	_isPinHigh
   0666 D0 07              1161 	pop	ar7
   0668 40 02              1162 	jc	00102$
   066A                    1163 00101$:
                    010E   1164 	C$wireless_serial.c$153$2$2 ==.
                           1165 ;	apps/wireless_serial/wireless_serial.c:153: signals |= 2;
   066A 7F 02              1166 	mov	r7,#0x02
   066C                    1167 00102$:
                    0110   1168 	C$wireless_serial.c$156$1$1 ==.
                           1169 ;	apps/wireless_serial/wireless_serial.c:156: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   066C 90 25 FB           1170 	mov	dptr,#_param_DSR_pin
   066F E4                 1171 	clr	a
   0670 93                 1172 	movc	a,@a+dptr
   0671 FB                 1173 	mov	r3,a
   0672 74 01              1174 	mov	a,#0x01
   0674 93                 1175 	movc	a,@a+dptr
   0675 FC                 1176 	mov	r4,a
   0676 74 02              1177 	mov	a,#0x02
   0678 93                 1178 	movc	a,@a+dptr
   0679 FD                 1179 	mov	r5,a
   067A 74 03              1180 	mov	a,#0x03
   067C 93                 1181 	movc	a,@a+dptr
   067D FE                 1182 	mov	r6,a
   067E 20 E7 0B           1183 	jb	acc.7,00110$
   0681 8B 82              1184 	mov	dpl,r3
   0683 C0 07              1185 	push	ar7
   0685 12 23 7F           1186 	lcall	_isPinHigh
   0688 D0 07              1187 	pop	ar7
   068A 40 20              1188 	jc	00106$
   068C                    1189 00110$:
                    0130   1190 	C$wireless_serial.c$157$1$1 ==.
                           1191 ;	apps/wireless_serial/wireless_serial.c:157: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   068C 90 25 EB           1192 	mov	dptr,#_param_nDSR_pin
   068F E4                 1193 	clr	a
   0690 93                 1194 	movc	a,@a+dptr
   0691 FB                 1195 	mov	r3,a
   0692 74 01              1196 	mov	a,#0x01
   0694 93                 1197 	movc	a,@a+dptr
   0695 FC                 1198 	mov	r4,a
   0696 74 02              1199 	mov	a,#0x02
   0698 93                 1200 	movc	a,@a+dptr
   0699 FD                 1201 	mov	r5,a
   069A 74 03              1202 	mov	a,#0x03
   069C 93                 1203 	movc	a,@a+dptr
   069D FE                 1204 	mov	r6,a
   069E 20 E7 0E           1205 	jb	acc.7,00107$
   06A1 8B 82              1206 	mov	dpl,r3
   06A3 C0 07              1207 	push	ar7
   06A5 12 23 7F           1208 	lcall	_isPinHigh
   06A8 D0 07              1209 	pop	ar7
   06AA 40 03              1210 	jc	00107$
   06AC                    1211 00106$:
                    0150   1212 	C$wireless_serial.c$159$2$3 ==.
                           1213 ;	apps/wireless_serial/wireless_serial.c:159: signals |= 1;
   06AC 43 07 01           1214 	orl	ar7,#0x01
   06AF                    1215 00107$:
                    0153   1216 	C$wireless_serial.c$162$1$1 ==.
                           1217 ;	apps/wireless_serial/wireless_serial.c:162: return signals;
   06AF 8F 82              1218 	mov	dpl,r7
                    0155   1219 	C$wireless_serial.c$163$1$1 ==.
                    0155   1220 	XG$ioRxSignals$0$0 ==.
   06B1 22                 1221 	ret
                           1222 ;------------------------------------------------------------
                           1223 ;Allocation info for local variables in function 'ioTxSignals'
                           1224 ;------------------------------------------------------------
                    0156   1225 	G$ioTxSignals$0$0 ==.
                    0156   1226 	C$wireless_serial.c$169$1$1 ==.
                           1227 ;	apps/wireless_serial/wireless_serial.c:169: void ioTxSignals(uint8 signals)
                           1228 ;	-----------------------------------------
                           1229 ;	 function ioTxSignals
                           1230 ;	-----------------------------------------
   06B2                    1231 _ioTxSignals:
   06B2 E5 82              1232 	mov	a,dpl
   06B4 78 03              1233 	mov	r0,#_ioTxSignals_signals_1_1
   06B6 F2                 1234 	movx	@r0,a
                    015B   1235 	C$wireless_serial.c$175$1$1 ==.
                           1236 ;	apps/wireless_serial/wireless_serial.c:175: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   06B7 78 03              1237 	mov	r0,#_ioTxSignals_signals_1_1
   06B9 E2                 1238 	movx	a,@r0
   06BA 54 01              1239 	anl	a,#0x01
   06BC FE                 1240 	mov	r6,a
   06BD B4 01 00           1241 	cjne	a,#0x01,00112$
   06C0                    1242 00112$:
   06C0 E4                 1243 	clr	a
   06C1 33                 1244 	rlc	a
   06C2 24 FF              1245 	add	a,#0xff
   06C4 92 04              1246 	mov	_ioTxSignals_sloc0_1_0,c
   06C6 90 25 E3           1247 	mov	dptr,#_param_nDTR_pin
   06C9 E4                 1248 	clr	a
   06CA 93                 1249 	movc	a,@a+dptr
   06CB FA                 1250 	mov	r2,a
   06CC 74 01              1251 	mov	a,#0x01
   06CE 93                 1252 	movc	a,@a+dptr
   06CF 74 02              1253 	mov	a,#0x02
   06D1 93                 1254 	movc	a,@a+dptr
   06D2 74 03              1255 	mov	a,#0x03
   06D4 93                 1256 	movc	a,@a+dptr
   06D5 8A 82              1257 	mov	dpl,r2
   06D7 A2 04              1258 	mov	c,_ioTxSignals_sloc0_1_0
   06D9 92 F0              1259 	mov	b[0],c
   06DB C0 06              1260 	push	ar6
   06DD 85 F0 24           1261 	mov	bits,b
   06E0 12 20 68           1262 	lcall	_setDigitalOutput
   06E3 D0 06              1263 	pop	ar6
                    0189   1264 	C$wireless_serial.c$176$1$1 ==.
                           1265 ;	apps/wireless_serial/wireless_serial.c:176: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   06E5 78 03              1266 	mov	r0,#_ioTxSignals_signals_1_1
   06E7 E2                 1267 	movx	a,@r0
   06E8 03                 1268 	rr	a
   06E9 54 01              1269 	anl	a,#0x01
   06EB FD                 1270 	mov	r5,a
   06EC B4 01 00           1271 	cjne	a,#0x01,00113$
   06EF                    1272 00113$:
   06EF E4                 1273 	clr	a
   06F0 33                 1274 	rlc	a
   06F1 24 FF              1275 	add	a,#0xff
   06F3 92 04              1276 	mov	_ioTxSignals_sloc0_1_0,c
   06F5 90 25 E7           1277 	mov	dptr,#_param_nRTS_pin
   06F8 E4                 1278 	clr	a
   06F9 93                 1279 	movc	a,@a+dptr
   06FA FA                 1280 	mov	r2,a
   06FB 74 01              1281 	mov	a,#0x01
   06FD 93                 1282 	movc	a,@a+dptr
   06FE 74 02              1283 	mov	a,#0x02
   0700 93                 1284 	movc	a,@a+dptr
   0701 74 03              1285 	mov	a,#0x03
   0703 93                 1286 	movc	a,@a+dptr
   0704 8A 82              1287 	mov	dpl,r2
   0706 A2 04              1288 	mov	c,_ioTxSignals_sloc0_1_0
   0708 92 F0              1289 	mov	b[0],c
   070A C0 06              1290 	push	ar6
   070C C0 05              1291 	push	ar5
   070E 85 F0 24           1292 	mov	bits,b
   0711 12 20 68           1293 	lcall	_setDigitalOutput
   0714 D0 05              1294 	pop	ar5
   0716 D0 06              1295 	pop	ar6
                    01BC   1296 	C$wireless_serial.c$179$1$1 ==.
                           1297 ;	apps/wireless_serial/wireless_serial.c:179: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0718 EE                 1298 	mov	a,r6
   0719 24 FF              1299 	add	a,#0xff
   071B 92 04              1300 	mov	_ioTxSignals_sloc0_1_0,c
   071D 90 25 F3           1301 	mov	dptr,#_param_DTR_pin
   0720 E4                 1302 	clr	a
   0721 93                 1303 	movc	a,@a+dptr
   0722 FB                 1304 	mov	r3,a
   0723 74 01              1305 	mov	a,#0x01
   0725 93                 1306 	movc	a,@a+dptr
   0726 74 02              1307 	mov	a,#0x02
   0728 93                 1308 	movc	a,@a+dptr
   0729 74 03              1309 	mov	a,#0x03
   072B 93                 1310 	movc	a,@a+dptr
   072C 8B 82              1311 	mov	dpl,r3
   072E A2 04              1312 	mov	c,_ioTxSignals_sloc0_1_0
   0730 92 F0              1313 	mov	b[0],c
   0732 C0 05              1314 	push	ar5
   0734 85 F0 24           1315 	mov	bits,b
   0737 12 20 68           1316 	lcall	_setDigitalOutput
   073A D0 05              1317 	pop	ar5
                    01E0   1318 	C$wireless_serial.c$180$1$1 ==.
                           1319 ;	apps/wireless_serial/wireless_serial.c:180: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   073C ED                 1320 	mov	a,r5
   073D 24 FF              1321 	add	a,#0xff
   073F 92 04              1322 	mov	_ioTxSignals_sloc0_1_0,c
   0741 90 25 F7           1323 	mov	dptr,#_param_RTS_pin
   0744 E4                 1324 	clr	a
   0745 93                 1325 	movc	a,@a+dptr
   0746 FC                 1326 	mov	r4,a
   0747 74 01              1327 	mov	a,#0x01
   0749 93                 1328 	movc	a,@a+dptr
   074A 74 02              1329 	mov	a,#0x02
   074C 93                 1330 	movc	a,@a+dptr
   074D 74 03              1331 	mov	a,#0x03
   074F 93                 1332 	movc	a,@a+dptr
   0750 8C 82              1333 	mov	dpl,r4
   0752 A2 04              1334 	mov	c,_ioTxSignals_sloc0_1_0
   0754 92 F0              1335 	mov	b[0],c
   0756 85 F0 24           1336 	mov	bits,b
   0759 12 20 68           1337 	lcall	_setDigitalOutput
                    0200   1338 	C$wireless_serial.c$183$1$1 ==.
                           1339 ;	apps/wireless_serial/wireless_serial.c:183: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   075C 78 05              1340 	mov	r0,#_ioTxSignals_lastSignals_1_1
   075E E2                 1341 	movx	a,@r0
   075F 54 01              1342 	anl	a,#0x01
   0761 60 02              1343 	jz	00115$
   0763 80 30              1344 	sjmp	00104$
   0765                    1345 00115$:
   0765 78 03              1346 	mov	r0,#_ioTxSignals_signals_1_1
   0767 E2                 1347 	movx	a,@r0
   0768 54 01              1348 	anl	a,#0x01
   076A 60 29              1349 	jz	00104$
                    0210   1350 	C$wireless_serial.c$187$2$2 ==.
                           1351 ;	apps/wireless_serial/wireless_serial.c:187: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   076C 90 26 03           1352 	mov	dptr,#_param_arduino_DTR_pin
   076F E4                 1353 	clr	a
   0770 93                 1354 	movc	a,@a+dptr
   0771 FC                 1355 	mov	r4,a
   0772 74 01              1356 	mov	a,#0x01
   0774 93                 1357 	movc	a,@a+dptr
   0775 74 02              1358 	mov	a,#0x02
   0777 93                 1359 	movc	a,@a+dptr
   0778 74 03              1360 	mov	a,#0x03
   077A 93                 1361 	movc	a,@a+dptr
   077B 8C 82              1362 	mov	dpl,r4
   077D D2 F0              1363 	setb	b[0]
   077F 85 F0 24           1364 	mov	bits,b
   0782 12 20 68           1365 	lcall	_setDigitalOutput
                    0229   1366 	C$wireless_serial.c$188$2$2 ==.
                           1367 ;	apps/wireless_serial/wireless_serial.c:188: nTrstPulseStartTime = getMs();
   0785 12 20 08           1368 	lcall	_getMs
   0788 AC 82              1369 	mov	r4,dpl
   078A AD 83              1370 	mov	r5,dph
   078C AE F0              1371 	mov	r6,b
   078E FF                 1372 	mov	r7,a
   078F 78 04              1373 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0791 EC                 1374 	mov	a,r4
   0792 F2                 1375 	movx	@r0,a
   0793 80 2F              1376 	sjmp	00105$
   0795                    1377 00104$:
                    0239   1378 	C$wireless_serial.c$190$1$1 ==.
                           1379 ;	apps/wireless_serial/wireless_serial.c:190: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   0795 12 20 08           1380 	lcall	_getMs
   0798 AC 82              1381 	mov	r4,dpl
   079A AD 83              1382 	mov	r5,dph
   079C AE F0              1383 	mov	r6,b
   079E FF                 1384 	mov	r7,a
   079F 78 04              1385 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   07A1 D3                 1386 	setb	c
   07A2 E2                 1387 	movx	a,@r0
   07A3 9C                 1388 	subb	a,r4
   07A4 F4                 1389 	cpl	a
   07A5 FC                 1390 	mov	r4,a
   07A6 BC 02 00           1391 	cjne	r4,#0x02,00117$
   07A9                    1392 00117$:
   07A9 40 19              1393 	jc	00105$
                    024F   1394 	C$wireless_serial.c$192$2$3 ==.
                           1395 ;	apps/wireless_serial/wireless_serial.c:192: setDigitalOutput(param_arduino_DTR_pin, LOW);
   07AB 90 26 03           1396 	mov	dptr,#_param_arduino_DTR_pin
   07AE E4                 1397 	clr	a
   07AF 93                 1398 	movc	a,@a+dptr
   07B0 FC                 1399 	mov	r4,a
   07B1 74 01              1400 	mov	a,#0x01
   07B3 93                 1401 	movc	a,@a+dptr
   07B4 74 02              1402 	mov	a,#0x02
   07B6 93                 1403 	movc	a,@a+dptr
   07B7 74 03              1404 	mov	a,#0x03
   07B9 93                 1405 	movc	a,@a+dptr
   07BA 8C 82              1406 	mov	dpl,r4
   07BC C2 F0              1407 	clr	b[0]
   07BE 85 F0 24           1408 	mov	bits,b
   07C1 12 20 68           1409 	lcall	_setDigitalOutput
   07C4                    1410 00105$:
                    0268   1411 	C$wireless_serial.c$195$1$1 ==.
                           1412 ;	apps/wireless_serial/wireless_serial.c:195: lastSignals = signals;
   07C4 78 03              1413 	mov	r0,#_ioTxSignals_signals_1_1
   07C6 79 05              1414 	mov	r1,#_ioTxSignals_lastSignals_1_1
   07C8 E2                 1415 	movx	a,@r0
   07C9 F3                 1416 	movx	@r1,a
                    026E   1417 	C$wireless_serial.c$196$1$1 ==.
                    026E   1418 	XG$ioTxSignals$0$0 ==.
   07CA 22                 1419 	ret
                           1420 ;------------------------------------------------------------
                           1421 ;Allocation info for local variables in function 'errorOccurred'
                           1422 ;------------------------------------------------------------
                    026F   1423 	G$errorOccurred$0$0 ==.
                    026F   1424 	C$wireless_serial.c$198$1$1 ==.
                           1425 ;	apps/wireless_serial/wireless_serial.c:198: void errorOccurred()
                           1426 ;	-----------------------------------------
                           1427 ;	 function errorOccurred
                           1428 ;	-----------------------------------------
   07CB                    1429 _errorOccurred:
                    026F   1430 	C$wireless_serial.c$200$1$1 ==.
                           1431 ;	apps/wireless_serial/wireless_serial.c:200: lastErrorTime = (uint8)getMs();
   07CB 12 20 08           1432 	lcall	_getMs
   07CE AC 82              1433 	mov	r4,dpl
   07D0 78 00              1434 	mov	r0,#_lastErrorTime
   07D2 EC                 1435 	mov	a,r4
   07D3 F2                 1436 	movx	@r0,a
                    0278   1437 	C$wireless_serial.c$201$1$1 ==.
                           1438 ;	apps/wireless_serial/wireless_serial.c:201: errorOccurredRecently = 1;
   07D4 D2 02              1439 	setb	_errorOccurredRecently
                    027A   1440 	C$wireless_serial.c$202$1$1 ==.
                    027A   1441 	XG$errorOccurred$0$0 ==.
   07D6 22                 1442 	ret
                           1443 ;------------------------------------------------------------
                           1444 ;Allocation info for local variables in function 'errorService'
                           1445 ;------------------------------------------------------------
                           1446 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1447 ;------------------------------------------------------------
                    027B   1448 	G$errorService$0$0 ==.
                    027B   1449 	C$wireless_serial.c$204$1$1 ==.
                           1450 ;	apps/wireless_serial/wireless_serial.c:204: void errorService()
                           1451 ;	-----------------------------------------
                           1452 ;	 function errorService
                           1453 ;	-----------------------------------------
   07D7                    1454 _errorService:
                    027B   1455 	C$wireless_serial.c$208$1$1 ==.
                           1456 ;	apps/wireless_serial/wireless_serial.c:208: if (uart1RxBufferFullOccurred)
                    027B   1457 	C$wireless_serial.c$210$2$2 ==.
                           1458 ;	apps/wireless_serial/wireless_serial.c:210: uart1RxBufferFullOccurred = 0;
   07D7 10 07 02           1459 	jbc	_uart1RxBufferFullOccurred,00129$
   07DA 80 03              1460 	sjmp	00102$
   07DC                    1461 00129$:
                    0280   1462 	C$wireless_serial.c$211$2$2 ==.
                           1463 ;	apps/wireless_serial/wireless_serial.c:211: errorOccurred();
   07DC 12 07 CB           1464 	lcall	_errorOccurred
   07DF                    1465 00102$:
                    0283   1466 	C$wireless_serial.c$214$1$1 ==.
                           1467 ;	apps/wireless_serial/wireless_serial.c:214: if (uart1RxFramingErrorOccurred)
                    0283   1468 	C$wireless_serial.c$216$2$3 ==.
                           1469 ;	apps/wireless_serial/wireless_serial.c:216: uart1RxFramingErrorOccurred = 0;
   07DF 10 06 02           1470 	jbc	_uart1RxFramingErrorOccurred,00130$
   07E2 80 41              1471 	sjmp	00106$
   07E4                    1472 00130$:
                    0288   1473 	C$wireless_serial.c$219$2$3 ==.
                           1474 ;	apps/wireless_serial/wireless_serial.c:219: framingErrorActive = 1;
   07E4 D2 01              1475 	setb	_framingErrorActive
                    028A   1476 	C$wireless_serial.c$220$2$3 ==.
                           1477 ;	apps/wireless_serial/wireless_serial.c:220: errorOccurred();
   07E6 12 07 CB           1478 	lcall	_errorOccurred
                    028D   1479 	C$wireless_serial.c$222$2$3 ==.
                           1480 ;	apps/wireless_serial/wireless_serial.c:222: if (param_framing_error_ms > 0)
   07E9 90 26 07           1481 	mov	dptr,#_param_framing_error_ms
   07EC E4                 1482 	clr	a
   07ED 93                 1483 	movc	a,@a+dptr
   07EE FC                 1484 	mov	r4,a
   07EF 74 01              1485 	mov	a,#0x01
   07F1 93                 1486 	movc	a,@a+dptr
   07F2 FD                 1487 	mov	r5,a
   07F3 74 02              1488 	mov	a,#0x02
   07F5 93                 1489 	movc	a,@a+dptr
   07F6 FE                 1490 	mov	r6,a
   07F7 74 03              1491 	mov	a,#0x03
   07F9 93                 1492 	movc	a,@a+dptr
   07FA FF                 1493 	mov	r7,a
   07FB C3                 1494 	clr	c
   07FC E4                 1495 	clr	a
   07FD 9C                 1496 	subb	a,r4
   07FE E4                 1497 	clr	a
   07FF 9D                 1498 	subb	a,r5
   0800 E4                 1499 	clr	a
   0801 9E                 1500 	subb	a,r6
   0802 E4                 1501 	clr	a
   0803 64 80              1502 	xrl	a,#0x80
   0805 8F F0              1503 	mov	b,r7
   0807 63 F0 80           1504 	xrl	b,#0x80
   080A 95 F0              1505 	subb	a,b
   080C 50 17              1506 	jnc	00106$
                    02B2   1507 	C$wireless_serial.c$225$3$4 ==.
                           1508 ;	apps/wireless_serial/wireless_serial.c:225: U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
   080E AF F8              1509 	mov	r7,_U1CSR
   0810 53 07 BF           1510 	anl	ar7,#0xBF
   0813 8F F8              1511 	mov	_U1CSR,r7
                    02B9   1512 	C$wireless_serial.c$226$3$4 ==.
                           1513 ;	apps/wireless_serial/wireless_serial.c:226: uartRxDisabled = 1;
   0815 D2 00              1514 	setb	_uartRxDisabled
                    02BB   1515 	C$wireless_serial.c$227$3$4 ==.
                           1516 ;	apps/wireless_serial/wireless_serial.c:227: lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
   0817 12 20 08           1517 	lcall	_getMs
   081A AC 82              1518 	mov	r4,dpl
   081C AD 83              1519 	mov	r5,dph
   081E AE F0              1520 	mov	r6,b
   0820 FF                 1521 	mov	r7,a
   0821 78 06              1522 	mov	r0,#_errorService_lastRxLowTime_1_1
   0823 EC                 1523 	mov	a,r4
   0824 F2                 1524 	movx	@r0,a
   0825                    1525 00106$:
                    02C9   1526 	C$wireless_serial.c$231$1$1 ==.
                           1527 ;	apps/wireless_serial/wireless_serial.c:231: if (framingErrorActive)
   0825 30 01 0F           1528 	jnb	_framingErrorActive,00111$
                    02CC   1529 	C$wireless_serial.c$233$2$5 ==.
                           1530 ;	apps/wireless_serial/wireless_serial.c:233: if (!isPinHigh(17))
   0828 75 82 11           1531 	mov	dpl,#0x11
   082B 12 23 7F           1532 	lcall	_isPinHigh
   082E 40 05              1533 	jc	00108$
                    02D4   1534 	C$wireless_serial.c$235$3$6 ==.
                           1535 ;	apps/wireless_serial/wireless_serial.c:235: errorOccurred();
   0830 12 07 CB           1536 	lcall	_errorOccurred
   0833 80 02              1537 	sjmp	00111$
   0835                    1538 00108$:
                    02D9   1539 	C$wireless_serial.c$239$3$7 ==.
                           1540 ;	apps/wireless_serial/wireless_serial.c:239: framingErrorActive = 0;
   0835 C2 01              1541 	clr	_framingErrorActive
   0837                    1542 00111$:
                    02DB   1543 	C$wireless_serial.c$243$1$1 ==.
                           1544 ;	apps/wireless_serial/wireless_serial.c:243: if (uartRxDisabled)
   0837 30 00 60           1545 	jnb	_uartRxDisabled,00119$
                    02DE   1546 	C$wireless_serial.c$245$2$8 ==.
                           1547 ;	apps/wireless_serial/wireless_serial.c:245: if (!isPinHigh(17))
   083A 75 82 11           1548 	mov	dpl,#0x11
   083D 12 23 7F           1549 	lcall	_isPinHigh
   0840 40 10              1550 	jc	00115$
                    02E6   1551 	C$wireless_serial.c$248$3$9 ==.
                           1552 ;	apps/wireless_serial/wireless_serial.c:248: lastRxLowTime = (uint8)getMs();
   0842 12 20 08           1553 	lcall	_getMs
   0845 AC 82              1554 	mov	r4,dpl
   0847 AD 83              1555 	mov	r5,dph
   0849 AE F0              1556 	mov	r6,b
   084B FF                 1557 	mov	r7,a
   084C 78 06              1558 	mov	r0,#_errorService_lastRxLowTime_1_1
   084E EC                 1559 	mov	a,r4
   084F F2                 1560 	movx	@r0,a
   0850 80 48              1561 	sjmp	00119$
   0852                    1562 00115$:
                    02F6   1563 	C$wireless_serial.c$250$2$8 ==.
                           1564 ;	apps/wireless_serial/wireless_serial.c:250: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   0852 12 20 08           1565 	lcall	_getMs
   0855 AC 82              1566 	mov	r4,dpl
   0857 AD 83              1567 	mov	r5,dph
   0859 78 06              1568 	mov	r0,#_errorService_lastRxLowTime_1_1
   085B D3                 1569 	setb	c
   085C E2                 1570 	movx	a,@r0
   085D 9C                 1571 	subb	a,r4
   085E F4                 1572 	cpl	a
   085F FC                 1573 	mov	r4,a
   0860 90 26 07           1574 	mov	dptr,#_param_framing_error_ms
   0863 E4                 1575 	clr	a
   0864 93                 1576 	movc	a,@a+dptr
   0865 F5 0A              1577 	mov	_errorService_sloc0_1_0,a
   0867 74 01              1578 	mov	a,#0x01
   0869 93                 1579 	movc	a,@a+dptr
   086A F5 0B              1580 	mov	(_errorService_sloc0_1_0 + 1),a
   086C 74 02              1581 	mov	a,#0x02
   086E 93                 1582 	movc	a,@a+dptr
   086F F5 0C              1583 	mov	(_errorService_sloc0_1_0 + 2),a
   0871 74 03              1584 	mov	a,#0x03
   0873 93                 1585 	movc	a,@a+dptr
   0874 F5 0D              1586 	mov	(_errorService_sloc0_1_0 + 3),a
   0876 8C 02              1587 	mov	ar2,r4
   0878 7C 00              1588 	mov	r4,#0x00
   087A 7E 00              1589 	mov	r6,#0x00
   087C 7F 00              1590 	mov	r7,#0x00
   087E C3                 1591 	clr	c
   087F E5 0A              1592 	mov	a,_errorService_sloc0_1_0
   0881 9A                 1593 	subb	a,r2
   0882 E5 0B              1594 	mov	a,(_errorService_sloc0_1_0 + 1)
   0884 9C                 1595 	subb	a,r4
   0885 E5 0C              1596 	mov	a,(_errorService_sloc0_1_0 + 2)
   0887 9E                 1597 	subb	a,r6
   0888 E5 0D              1598 	mov	a,(_errorService_sloc0_1_0 + 3)
   088A 64 80              1599 	xrl	a,#0x80
   088C 8F F0              1600 	mov	b,r7
   088E 63 F0 80           1601 	xrl	b,#0x80
   0891 95 F0              1602 	subb	a,b
   0893 50 05              1603 	jnc	00119$
                    0339   1604 	C$wireless_serial.c$253$3$10 ==.
                           1605 ;	apps/wireless_serial/wireless_serial.c:253: U1CSR |= 0x40;
   0895 43 F8 40           1606 	orl	_U1CSR,#0x40
                    033C   1607 	C$wireless_serial.c$254$3$10 ==.
                           1608 ;	apps/wireless_serial/wireless_serial.c:254: uartRxDisabled = 0;
   0898 C2 00              1609 	clr	_uartRxDisabled
   089A                    1610 00119$:
                    033E   1611 	C$wireless_serial.c$257$1$1 ==.
                    033E   1612 	XG$errorService$0$0 ==.
   089A 22                 1613 	ret
                           1614 ;------------------------------------------------------------
                           1615 ;Allocation info for local variables in function 'updateSerialMode'
                           1616 ;------------------------------------------------------------
                    033F   1617 	G$updateSerialMode$0$0 ==.
                    033F   1618 	C$wireless_serial.c$259$1$1 ==.
                           1619 ;	apps/wireless_serial/wireless_serial.c:259: void updateSerialMode()
                           1620 ;	-----------------------------------------
                           1621 ;	 function updateSerialMode
                           1622 ;	-----------------------------------------
   089B                    1623 _updateSerialMode:
                    033F   1624 	C$wireless_serial.c$261$1$1 ==.
                           1625 ;	apps/wireless_serial/wireless_serial.c:261: if ((uint8)param_serial_mode > 0 && (uint8)param_serial_mode <= 3)
   089B 90 25 DB           1626 	mov	dptr,#_param_serial_mode
   089E E4                 1627 	clr	a
   089F 93                 1628 	movc	a,@a+dptr
   08A0 FC                 1629 	mov	r4,a
   08A1 74 01              1630 	mov	a,#0x01
   08A3 93                 1631 	movc	a,@a+dptr
   08A4 FD                 1632 	mov	r5,a
   08A5 74 02              1633 	mov	a,#0x02
   08A7 93                 1634 	movc	a,@a+dptr
   08A8 FE                 1635 	mov	r6,a
   08A9 74 03              1636 	mov	a,#0x03
   08AB 93                 1637 	movc	a,@a+dptr
   08AC FF                 1638 	mov	r7,a
   08AD EC                 1639 	mov	a,r4
   08AE 60 09              1640 	jz	00102$
   08B0 EC                 1641 	mov	a,r4
   08B1 24 FC              1642 	add	a,#0xff - 0x03
   08B3 40 04              1643 	jc	00102$
                    0359   1644 	C$wireless_serial.c$263$2$2 ==.
                           1645 ;	apps/wireless_serial/wireless_serial.c:263: currentSerialMode = (uint8)param_serial_mode;
   08B5 8C 08              1646 	mov	_currentSerialMode,r4
                    035B   1647 	C$wireless_serial.c$264$2$2 ==.
                           1648 ;	apps/wireless_serial/wireless_serial.c:264: return;
   08B7 80 17              1649 	sjmp	00110$
   08B9                    1650 00102$:
                    035D   1651 	C$wireless_serial.c$267$1$1 ==.
                           1652 ;	apps/wireless_serial/wireless_serial.c:267: if (usbPowerPresent())
   08B9 12 1E 51           1653 	lcall	_usbPowerPresent
   08BC 50 0F              1654 	jnc	00108$
                    0362   1655 	C$wireless_serial.c$269$2$3 ==.
                           1656 ;	apps/wireless_serial/wireless_serial.c:269: if (vinPowerPresent())
   08BE 12 1E 57           1657 	lcall	_vinPowerPresent
   08C1 50 05              1658 	jnc	00105$
                    0367   1659 	C$wireless_serial.c$271$3$4 ==.
                           1660 ;	apps/wireless_serial/wireless_serial.c:271: currentSerialMode = SERIAL_MODE_USB_UART;
   08C3 75 08 03           1661 	mov	_currentSerialMode,#0x03
   08C6 80 08              1662 	sjmp	00110$
   08C8                    1663 00105$:
                    036C   1664 	C$wireless_serial.c$275$3$5 ==.
                           1665 ;	apps/wireless_serial/wireless_serial.c:275: currentSerialMode = SERIAL_MODE_USB_RADIO;
   08C8 75 08 01           1666 	mov	_currentSerialMode,#0x01
   08CB 80 03              1667 	sjmp	00110$
   08CD                    1668 00108$:
                    0371   1669 	C$wireless_serial.c$280$2$6 ==.
                           1670 ;	apps/wireless_serial/wireless_serial.c:280: currentSerialMode = SERIAL_MODE_UART_RADIO;
   08CD 75 08 02           1671 	mov	_currentSerialMode,#0x02
   08D0                    1672 00110$:
                    0374   1673 	C$wireless_serial.c$282$1$1 ==.
                    0374   1674 	XG$updateSerialMode$0$0 ==.
   08D0 22                 1675 	ret
                           1676 ;------------------------------------------------------------
                           1677 ;Allocation info for local variables in function 'usbToRadioService'
                           1678 ;------------------------------------------------------------
                    0375   1679 	G$usbToRadioService$0$0 ==.
                    0375   1680 	C$wireless_serial.c$284$1$1 ==.
                           1681 ;	apps/wireless_serial/wireless_serial.c:284: void usbToRadioService()
                           1682 ;	-----------------------------------------
                           1683 ;	 function usbToRadioService
                           1684 ;	-----------------------------------------
   08D1                    1685 _usbToRadioService:
                    0375   1686 	C$wireless_serial.c$289$1$1 ==.
                           1687 ;	apps/wireless_serial/wireless_serial.c:289: while(usbComRxAvailable() && radioComTxAvailable())
   08D1                    1688 00102$:
   08D1 12 12 FD           1689 	lcall	_usbComRxAvailable
   08D4 E5 82              1690 	mov	a,dpl
   08D6 60 0F              1691 	jz	00106$
   08D8 12 1D 2E           1692 	lcall	_radioComTxAvailable
   08DB E5 82              1693 	mov	a,dpl
   08DD 60 08              1694 	jz	00106$
                    0383   1695 	C$wireless_serial.c$291$2$2 ==.
                           1696 ;	apps/wireless_serial/wireless_serial.c:291: radioComTxSendByte(usbComRxReceiveByte());
   08DF 12 13 27           1697 	lcall	_usbComRxReceiveByte
   08E2 12 1D 45           1698 	lcall	_radioComTxSendByte
                    0389   1699 	C$wireless_serial.c$294$1$1 ==.
                           1700 ;	apps/wireless_serial/wireless_serial.c:294: while(radioComRxAvailable() && usbComTxAvailable())
   08E5 80 EA              1701 	sjmp	00102$
   08E7                    1702 00106$:
   08E7 12 1C 9F           1703 	lcall	_radioComRxAvailable
   08EA E5 82              1704 	mov	a,dpl
   08EC 60 0F              1705 	jz	00108$
   08EE 12 14 33           1706 	lcall	_usbComTxAvailable
   08F1 E5 82              1707 	mov	a,dpl
   08F3 60 08              1708 	jz	00108$
                    0399   1709 	C$wireless_serial.c$296$2$3 ==.
                           1710 ;	apps/wireless_serial/wireless_serial.c:296: usbComTxSendByte(radioComRxReceiveByte());
   08F5 12 1C A6           1711 	lcall	_radioComRxReceiveByte
   08F8 12 14 C5           1712 	lcall	_usbComTxSendByte
   08FB 80 EA              1713 	sjmp	00106$
   08FD                    1714 00108$:
                    03A1   1715 	C$wireless_serial.c$301$1$1 ==.
                           1716 ;	apps/wireless_serial/wireless_serial.c:301: radioComTxControlSignals(usbComRxControlSignals() & 3);
   08FD 12 14 D6           1717 	lcall	_usbComRxControlSignals
   0900 E5 82              1718 	mov	a,dpl
   0902 54 03              1719 	anl	a,#0x03
   0904 F5 82              1720 	mov	dpl,a
   0906 12 1D 79           1721 	lcall	_radioComTxControlSignals
                    03AD   1722 	C$wireless_serial.c$304$1$1 ==.
                           1723 ;	apps/wireless_serial/wireless_serial.c:304: signals = radioComRxControlSignals();
   0909 12 1C C3           1724 	lcall	_radioComRxControlSignals
                    03B0   1725 	C$wireless_serial.c$305$1$1 ==.
                           1726 ;	apps/wireless_serial/wireless_serial.c:305: usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
   090C E5 82              1727 	mov	a,dpl
   090E FF                 1728 	mov	r7,a
   090F 30 E0 04           1729 	jnb	acc.0,00111$
   0912 7E 02              1730 	mov	r6,#0x02
   0914 80 02              1731 	sjmp	00112$
   0916                    1732 00111$:
   0916 7E 00              1733 	mov	r6,#0x00
   0918                    1734 00112$:
   0918 EF                 1735 	mov	a,r7
   0919 30 E1 04           1736 	jnb	acc.1,00113$
   091C 7F 01              1737 	mov	r7,#0x01
   091E 80 02              1738 	sjmp	00114$
   0920                    1739 00113$:
   0920 7F 00              1740 	mov	r7,#0x00
   0922                    1741 00114$:
   0922 EF                 1742 	mov	a,r7
   0923 4E                 1743 	orl	a,r6
   0924 F5 82              1744 	mov	dpl,a
   0926 12 14 DC           1745 	lcall	_usbComTxControlSignals
                    03CD   1746 	C$wireless_serial.c$306$1$1 ==.
                    03CD   1747 	XG$usbToRadioService$0$0 ==.
   0929 22                 1748 	ret
                           1749 ;------------------------------------------------------------
                           1750 ;Allocation info for local variables in function 'uartToRadioService'
                           1751 ;------------------------------------------------------------
                    03CE   1752 	G$uartToRadioService$0$0 ==.
                    03CE   1753 	C$wireless_serial.c$308$1$1 ==.
                           1754 ;	apps/wireless_serial/wireless_serial.c:308: void uartToRadioService()
                           1755 ;	-----------------------------------------
                           1756 ;	 function uartToRadioService
                           1757 ;	-----------------------------------------
   092A                    1758 _uartToRadioService:
                    03CE   1759 	C$wireless_serial.c$311$1$1 ==.
                           1760 ;	apps/wireless_serial/wireless_serial.c:311: while(uart1RxAvailable() && radioComTxAvailable())
   092A                    1761 00102$:
   092A 12 0C 30           1762 	lcall	_uart1RxAvailable
   092D E5 82              1763 	mov	a,dpl
   092F 60 0F              1764 	jz	00106$
   0931 12 1D 2E           1765 	lcall	_radioComTxAvailable
   0934 E5 82              1766 	mov	a,dpl
   0936 60 08              1767 	jz	00106$
                    03DC   1768 	C$wireless_serial.c$313$2$2 ==.
                           1769 ;	apps/wireless_serial/wireless_serial.c:313: radioComTxSendByte(uart1RxReceiveByte());
   0938 12 0C 38           1770 	lcall	_uart1RxReceiveByte
   093B 12 1D 45           1771 	lcall	_radioComTxSendByte
                    03E2   1772 	C$wireless_serial.c$316$1$1 ==.
                           1773 ;	apps/wireless_serial/wireless_serial.c:316: while(radioComRxAvailable() && uart1TxAvailable())
   093E 80 EA              1774 	sjmp	00102$
   0940                    1775 00106$:
   0940 12 1C 9F           1776 	lcall	_radioComRxAvailable
   0943 E5 82              1777 	mov	a,dpl
   0945 60 0F              1778 	jz	00108$
   0947 12 0B DC           1779 	lcall	_uart1TxAvailable
   094A E5 82              1780 	mov	a,dpl
   094C 60 08              1781 	jz	00108$
                    03F2   1782 	C$wireless_serial.c$318$2$3 ==.
                           1783 ;	apps/wireless_serial/wireless_serial.c:318: uart1TxSendByte(radioComRxReceiveByte());
   094E 12 1C A6           1784 	lcall	_radioComRxReceiveByte
   0951 12 0C 17           1785 	lcall	_uart1TxSendByte
   0954 80 EA              1786 	sjmp	00106$
   0956                    1787 00108$:
                    03FA   1788 	C$wireless_serial.c$322$1$1 ==.
                           1789 ;	apps/wireless_serial/wireless_serial.c:322: ioTxSignals(radioComRxControlSignals());
   0956 12 1C C3           1790 	lcall	_radioComRxControlSignals
   0959 12 06 B2           1791 	lcall	_ioTxSignals
                    0400   1792 	C$wireless_serial.c$323$1$1 ==.
                           1793 ;	apps/wireless_serial/wireless_serial.c:323: radioComTxControlSignals(ioRxSignals());
   095C 12 06 28           1794 	lcall	_ioRxSignals
   095F 12 1D 79           1795 	lcall	_radioComTxControlSignals
                    0406   1796 	C$wireless_serial.c$324$1$1 ==.
                    0406   1797 	XG$uartToRadioService$0$0 ==.
   0962 22                 1798 	ret
                           1799 ;------------------------------------------------------------
                           1800 ;Allocation info for local variables in function 'usbToUartService'
                           1801 ;------------------------------------------------------------
                    0407   1802 	G$usbToUartService$0$0 ==.
                    0407   1803 	C$wireless_serial.c$326$1$1 ==.
                           1804 ;	apps/wireless_serial/wireless_serial.c:326: void usbToUartService()
                           1805 ;	-----------------------------------------
                           1806 ;	 function usbToUartService
                           1807 ;	-----------------------------------------
   0963                    1808 _usbToUartService:
                    0407   1809 	C$wireless_serial.c$331$1$1 ==.
                           1810 ;	apps/wireless_serial/wireless_serial.c:331: while(usbComRxAvailable() && uart1TxAvailable())
   0963                    1811 00102$:
   0963 12 12 FD           1812 	lcall	_usbComRxAvailable
   0966 E5 82              1813 	mov	a,dpl
   0968 60 0F              1814 	jz	00106$
   096A 12 0B DC           1815 	lcall	_uart1TxAvailable
   096D E5 82              1816 	mov	a,dpl
   096F 60 08              1817 	jz	00106$
                    0415   1818 	C$wireless_serial.c$333$2$2 ==.
                           1819 ;	apps/wireless_serial/wireless_serial.c:333: uart1TxSendByte(usbComRxReceiveByte());
   0971 12 13 27           1820 	lcall	_usbComRxReceiveByte
   0974 12 0C 17           1821 	lcall	_uart1TxSendByte
                    041B   1822 	C$wireless_serial.c$336$1$1 ==.
                           1823 ;	apps/wireless_serial/wireless_serial.c:336: while(uart1RxAvailable() && usbComTxAvailable())
   0977 80 EA              1824 	sjmp	00102$
   0979                    1825 00106$:
   0979 12 0C 30           1826 	lcall	_uart1RxAvailable
   097C E5 82              1827 	mov	a,dpl
   097E 60 0F              1828 	jz	00108$
   0980 12 14 33           1829 	lcall	_usbComTxAvailable
   0983 E5 82              1830 	mov	a,dpl
   0985 60 08              1831 	jz	00108$
                    042B   1832 	C$wireless_serial.c$338$2$3 ==.
                           1833 ;	apps/wireless_serial/wireless_serial.c:338: usbComTxSendByte(uart1RxReceiveByte());
   0987 12 0C 38           1834 	lcall	_uart1RxReceiveByte
   098A 12 14 C5           1835 	lcall	_usbComTxSendByte
   098D 80 EA              1836 	sjmp	00106$
   098F                    1837 00108$:
                    0433   1838 	C$wireless_serial.c$341$1$1 ==.
                           1839 ;	apps/wireless_serial/wireless_serial.c:341: ioTxSignals(usbComRxControlSignals());
   098F 12 14 D6           1840 	lcall	_usbComRxControlSignals
   0992 12 06 B2           1841 	lcall	_ioTxSignals
                    0439   1842 	C$wireless_serial.c$344$1$1 ==.
                           1843 ;	apps/wireless_serial/wireless_serial.c:344: signals = ioRxSignals();
   0995 12 06 28           1844 	lcall	_ioRxSignals
                    043C   1845 	C$wireless_serial.c$345$1$1 ==.
                           1846 ;	apps/wireless_serial/wireless_serial.c:345: usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
   0998 E5 82              1847 	mov	a,dpl
   099A FF                 1848 	mov	r7,a
   099B 30 E0 04           1849 	jnb	acc.0,00111$
   099E 7E 02              1850 	mov	r6,#0x02
   09A0 80 02              1851 	sjmp	00112$
   09A2                    1852 00111$:
   09A2 7E 00              1853 	mov	r6,#0x00
   09A4                    1854 00112$:
   09A4 EF                 1855 	mov	a,r7
   09A5 30 E1 04           1856 	jnb	acc.1,00113$
   09A8 7F 01              1857 	mov	r7,#0x01
   09AA 80 02              1858 	sjmp	00114$
   09AC                    1859 00113$:
   09AC 7F 00              1860 	mov	r7,#0x00
   09AE                    1861 00114$:
   09AE EF                 1862 	mov	a,r7
   09AF 4E                 1863 	orl	a,r6
   09B0 F5 82              1864 	mov	dpl,a
   09B2 12 14 DC           1865 	lcall	_usbComTxControlSignals
                    0459   1866 	C$wireless_serial.c$348$1$1 ==.
                    0459   1867 	XG$usbToUartService$0$0 ==.
   09B5 22                 1868 	ret
                           1869 ;------------------------------------------------------------
                           1870 ;Allocation info for local variables in function 'main'
                           1871 ;------------------------------------------------------------
                    045A   1872 	G$main$0$0 ==.
                    045A   1873 	C$wireless_serial.c$350$1$1 ==.
                           1874 ;	apps/wireless_serial/wireless_serial.c:350: void main()
                           1875 ;	-----------------------------------------
                           1876 ;	 function main
                           1877 ;	-----------------------------------------
   09B6                    1878 _main:
                    045A   1879 	C$wireless_serial.c$352$1$1 ==.
                           1880 ;	apps/wireless_serial/wireless_serial.c:352: systemInit();
   09B6 12 1D 8D           1881 	lcall	_systemInit
                    045D   1882 	C$wireless_serial.c$354$1$1 ==.
                           1883 ;	apps/wireless_serial/wireless_serial.c:354: setDigitalOutput(param_arduino_DTR_pin, LOW);
   09B9 90 26 03           1884 	mov	dptr,#_param_arduino_DTR_pin
   09BC E4                 1885 	clr	a
   09BD 93                 1886 	movc	a,@a+dptr
   09BE FC                 1887 	mov	r4,a
   09BF 74 01              1888 	mov	a,#0x01
   09C1 93                 1889 	movc	a,@a+dptr
   09C2 74 02              1890 	mov	a,#0x02
   09C4 93                 1891 	movc	a,@a+dptr
   09C5 74 03              1892 	mov	a,#0x03
   09C7 93                 1893 	movc	a,@a+dptr
   09C8 8C 82              1894 	mov	dpl,r4
   09CA C2 F0              1895 	clr	b[0]
   09CC 85 F0 24           1896 	mov	bits,b
   09CF 12 20 68           1897 	lcall	_setDigitalOutput
                    0476   1898 	C$wireless_serial.c$355$1$1 ==.
                           1899 ;	apps/wireless_serial/wireless_serial.c:355: ioTxSignals(0);
   09D2 75 82 00           1900 	mov	dpl,#0x00
   09D5 12 06 B2           1901 	lcall	_ioTxSignals
                    047C   1902 	C$wireless_serial.c$357$1$1 ==.
                           1903 ;	apps/wireless_serial/wireless_serial.c:357: usbInit();
   09D8 12 14 F0           1904 	lcall	_usbInit
                    047F   1905 	C$wireless_serial.c$359$1$1 ==.
                           1906 ;	apps/wireless_serial/wireless_serial.c:359: uart1Init();
   09DB 12 0A 7D           1907 	lcall	_uart1Init
                    0482   1908 	C$wireless_serial.c$360$1$1 ==.
                           1909 ;	apps/wireless_serial/wireless_serial.c:360: uart1SetBaudRate(param_baud_rate);
   09DE 90 25 DF           1910 	mov	dptr,#_param_baud_rate
   09E1 E4                 1911 	clr	a
   09E2 93                 1912 	movc	a,@a+dptr
   09E3 FC                 1913 	mov	r4,a
   09E4 74 01              1914 	mov	a,#0x01
   09E6 93                 1915 	movc	a,@a+dptr
   09E7 FD                 1916 	mov	r5,a
   09E8 74 02              1917 	mov	a,#0x02
   09EA 93                 1918 	movc	a,@a+dptr
   09EB FE                 1919 	mov	r6,a
   09EC 74 03              1920 	mov	a,#0x03
   09EE 93                 1921 	movc	a,@a+dptr
   09EF 8C 82              1922 	mov	dpl,r4
   09F1 8D 83              1923 	mov	dph,r5
   09F3 8E F0              1924 	mov	b,r6
   09F5 12 0A B1           1925 	lcall	_uart1SetBaudRate
                    049C   1926 	C$wireless_serial.c$362$1$1 ==.
                           1927 ;	apps/wireless_serial/wireless_serial.c:362: if (param_serial_mode != SERIAL_MODE_USB_UART)
   09F8 90 25 DB           1928 	mov	dptr,#_param_serial_mode
   09FB E4                 1929 	clr	a
   09FC 93                 1930 	movc	a,@a+dptr
   09FD FC                 1931 	mov	r4,a
   09FE 74 01              1932 	mov	a,#0x01
   0A00 93                 1933 	movc	a,@a+dptr
   0A01 FD                 1934 	mov	r5,a
   0A02 74 02              1935 	mov	a,#0x02
   0A04 93                 1936 	movc	a,@a+dptr
   0A05 FE                 1937 	mov	r6,a
   0A06 74 03              1938 	mov	a,#0x03
   0A08 93                 1939 	movc	a,@a+dptr
   0A09 FF                 1940 	mov	r7,a
   0A0A BC 03 0B           1941 	cjne	r4,#0x03,00120$
   0A0D BD 00 08           1942 	cjne	r5,#0x00,00120$
   0A10 BE 00 05           1943 	cjne	r6,#0x00,00120$
   0A13 BF 00 02           1944 	cjne	r7,#0x00,00120$
   0A16 80 05              1945 	sjmp	00102$
   0A18                    1946 00120$:
                    04BC   1947 	C$wireless_serial.c$364$2$2 ==.
                           1948 ;	apps/wireless_serial/wireless_serial.c:364: radioComRxEnforceOrdering = 1;
   0A18 D2 18              1949 	setb	_radioComRxEnforceOrdering
                    04BE   1950 	C$wireless_serial.c$365$2$2 ==.
                           1951 ;	apps/wireless_serial/wireless_serial.c:365: radioComInit();
   0A1A 12 1C 34           1952 	lcall	_radioComInit
   0A1D                    1953 00102$:
                    04C1   1954 	C$wireless_serial.c$369$1$1 ==.
                           1955 ;	apps/wireless_serial/wireless_serial.c:369: P1DIR |= (1<<5);
   0A1D 43 FE 20           1956 	orl	_P1DIR,#0x20
                    04C4   1957 	C$wireless_serial.c$370$1$1 ==.
                           1958 ;	apps/wireless_serial/wireless_serial.c:370: IOCFG0 = 0b011011; // P1_5 = PA_PD (TX mode)
   0A20 90 DF 31           1959 	mov	dptr,#_IOCFG0
   0A23 74 1B              1960 	mov	a,#0x1B
   0A25 F0                 1961 	movx	@dptr,a
                    04CA   1962 	C$wireless_serial.c$372$1$1 ==.
                           1963 ;	apps/wireless_serial/wireless_serial.c:372: while(1)
   0A26                    1964 00110$:
                    04CA   1965 	C$wireless_serial.c$374$2$3 ==.
                           1966 ;	apps/wireless_serial/wireless_serial.c:374: updateSerialMode();
   0A26 12 08 9B           1967 	lcall	_updateSerialMode
                    04CD   1968 	C$wireless_serial.c$375$2$3 ==.
                           1969 ;	apps/wireless_serial/wireless_serial.c:375: boardService();
   0A29 12 1D 9A           1970 	lcall	_boardService
                    04D0   1971 	C$wireless_serial.c$376$2$3 ==.
                           1972 ;	apps/wireless_serial/wireless_serial.c:376: updateLeds();
   0A2C 12 05 5C           1973 	lcall	_updateLeds
                    04D3   1974 	C$wireless_serial.c$377$2$3 ==.
                           1975 ;	apps/wireless_serial/wireless_serial.c:377: errorService();
   0A2F 12 07 D7           1976 	lcall	_errorService
                    04D6   1977 	C$wireless_serial.c$379$2$3 ==.
                           1978 ;	apps/wireless_serial/wireless_serial.c:379: if (param_serial_mode != SERIAL_MODE_USB_UART)
   0A32 90 25 DB           1979 	mov	dptr,#_param_serial_mode
   0A35 E4                 1980 	clr	a
   0A36 93                 1981 	movc	a,@a+dptr
   0A37 FC                 1982 	mov	r4,a
   0A38 74 01              1983 	mov	a,#0x01
   0A3A 93                 1984 	movc	a,@a+dptr
   0A3B FD                 1985 	mov	r5,a
   0A3C 74 02              1986 	mov	a,#0x02
   0A3E 93                 1987 	movc	a,@a+dptr
   0A3F FE                 1988 	mov	r6,a
   0A40 74 03              1989 	mov	a,#0x03
   0A42 93                 1990 	movc	a,@a+dptr
   0A43 FF                 1991 	mov	r7,a
   0A44 BC 03 0B           1992 	cjne	r4,#0x03,00121$
   0A47 BD 00 08           1993 	cjne	r5,#0x00,00121$
   0A4A BE 00 05           1994 	cjne	r6,#0x00,00121$
   0A4D BF 00 02           1995 	cjne	r7,#0x00,00121$
   0A50 80 03              1996 	sjmp	00104$
   0A52                    1997 00121$:
                    04F6   1998 	C$wireless_serial.c$381$3$4 ==.
                           1999 ;	apps/wireless_serial/wireless_serial.c:381: radioComTxService();
   0A52 12 1C FF           2000 	lcall	_radioComTxService
   0A55                    2001 00104$:
                    04F9   2002 	C$wireless_serial.c$384$2$3 ==.
                           2003 ;	apps/wireless_serial/wireless_serial.c:384: usbComService();
   0A55 12 13 8E           2004 	lcall	_usbComService
                    04FC   2005 	C$wireless_serial.c$386$2$3 ==.
                           2006 ;	apps/wireless_serial/wireless_serial.c:386: switch(currentSerialMode)
   0A58 74 01              2007 	mov	a,#0x01
   0A5A B5 08 02           2008 	cjne	a,_currentSerialMode,00122$
   0A5D 80 0E              2009 	sjmp	00105$
   0A5F                    2010 00122$:
   0A5F 74 02              2011 	mov	a,#0x02
   0A61 B5 08 02           2012 	cjne	a,_currentSerialMode,00123$
   0A64 80 0C              2013 	sjmp	00106$
   0A66                    2014 00123$:
   0A66 74 03              2015 	mov	a,#0x03
                    050C   2016 	C$wireless_serial.c$388$3$5 ==.
                           2017 ;	apps/wireless_serial/wireless_serial.c:388: case SERIAL_MODE_USB_RADIO:  usbToRadioService();  break;
   0A68 B5 08 BB           2018 	cjne	a,_currentSerialMode,00110$
   0A6B 80 0A              2019 	sjmp	00107$
   0A6D                    2020 00105$:
   0A6D 12 08 D1           2021 	lcall	_usbToRadioService
                    0514   2022 	C$wireless_serial.c$389$3$5 ==.
                           2023 ;	apps/wireless_serial/wireless_serial.c:389: case SERIAL_MODE_UART_RADIO: uartToRadioService(); break;
   0A70 80 B4              2024 	sjmp	00110$
   0A72                    2025 00106$:
   0A72 12 09 2A           2026 	lcall	_uartToRadioService
                    0519   2027 	C$wireless_serial.c$390$3$5 ==.
                           2028 ;	apps/wireless_serial/wireless_serial.c:390: case SERIAL_MODE_USB_UART:   usbToUartService();   break;
   0A75 80 AF              2029 	sjmp	00110$
   0A77                    2030 00107$:
   0A77 12 09 63           2031 	lcall	_usbToUartService
                    051E   2032 	C$wireless_serial.c$391$1$1 ==.
                           2033 ;	apps/wireless_serial/wireless_serial.c:391: }
   0A7A 80 AA              2034 	sjmp	00110$
                    0520   2035 	C$wireless_serial.c$393$1$1 ==.
                    0520   2036 	XG$main$0$0 ==.
   0A7C 22                 2037 	ret
                           2038 	.area CSEG    (CODE)
                           2039 	.area CONST   (CODE)
                    0000   2040 G$param_serial_mode$0$0 == .
   25DB                    2041 _param_serial_mode:
   25DB 00 00 00 00        2042 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   2043 G$param_baud_rate$0$0 == .
   25DF                    2044 _param_baud_rate:
   25DF 80 25 00 00        2045 	.byte #0x80,#0x25,#0x00,#0x00	;  9600
                    0008   2046 G$param_nDTR_pin$0$0 == .
   25E3                    2047 _param_nDTR_pin:
   25E3 0A 00 00 00        2048 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   2049 G$param_nRTS_pin$0$0 == .
   25E7                    2050 _param_nRTS_pin:
   25E7 0B 00 00 00        2051 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   2052 G$param_nDSR_pin$0$0 == .
   25EB                    2053 _param_nDSR_pin:
   25EB 0C 00 00 00        2054 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    0014   2055 G$param_nCD_pin$0$0 == .
   25EF                    2056 _param_nCD_pin:
   25EF 0D 00 00 00        2057 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0018   2058 G$param_DTR_pin$0$0 == .
   25F3                    2059 _param_DTR_pin:
   25F3 FF FF FF FF        2060 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    001C   2061 G$param_RTS_pin$0$0 == .
   25F7                    2062 _param_RTS_pin:
   25F7 FF FF FF FF        2063 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0020   2064 G$param_DSR_pin$0$0 == .
   25FB                    2065 _param_DSR_pin:
   25FB FF FF FF FF        2066 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0024   2067 G$param_CD_pin$0$0 == .
   25FF                    2068 _param_CD_pin:
   25FF FF FF FF FF        2069 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0028   2070 G$param_arduino_DTR_pin$0$0 == .
   2603                    2071 _param_arduino_DTR_pin:
   2603 00 00 00 00        2072 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002C   2073 G$param_framing_error_ms$0$0 == .
   2607                    2074 _param_framing_error_ms:
   2607 00 00 00 00        2075 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                           2076 	.area XINIT   (CODE)
                           2077 	.area CABS    (ABS,CODE)
