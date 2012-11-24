                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:23 2012
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
                             25 	.globl _uartToRadioService
                             26 	.globl _usbToUartService
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
                             66 	.globl _walkDIR
                             67 	.globl _walkSPD
                             68 	.globl _lookH
                             69 	.globl _lookV
                             70 	.globl _walkH
                             71 	.globl _walkV
                             72 	.globl _southpaw
                             73 	.globl _checksum_cmdr
                             74 	.globl _index_cmdr
                             75 	.globl _vals
                             76 	.globl _tilt_add
                             77 	.globl _pan_add
                             78 	.globl _panic
                             79 	.globl _flopCnt
                             80 	.globl _kneeling
                             81 	.globl _light
                             82 	.globl _turn
                             83 	.globl _walk
                             84 	.globl _agitbutton
                             85 	.globl _infobutton
                             86 	.globl _panicbutton
                             87 	.globl _gunbutton
                             88 	.globl _turnleft
                             89 	.globl _turnright
                             90 	.globl _pan_pos
                             91 	.globl _tilt_pos
                             92 	.globl _d_pan
                             93 	.globl _d_tilt
                             94 	.globl _errorOccurredRecently
                             95 	.globl _framingErrorActive
                             96 	.globl _uartRxDisabled
                             97 	.globl _currentSerialMode
                             98 	.globl _CmdrReadMsgs
                             99 	.globl _UseSouthPaw
                            100 ;--------------------------------------------------------
                            101 ; special function registers
                            102 ;--------------------------------------------------------
                            103 	.area RSEG    (ABS,DATA)
   0000                     104 	.org 0x0000
                    0080    105 Fwireless_serial$P0$0$0 == 0x0080
                    0080    106 _P0	=	0x0080
                    0081    107 Fwireless_serial$SP$0$0 == 0x0081
                    0081    108 _SP	=	0x0081
                    0082    109 Fwireless_serial$DPL0$0$0 == 0x0082
                    0082    110 _DPL0	=	0x0082
                    0083    111 Fwireless_serial$DPH0$0$0 == 0x0083
                    0083    112 _DPH0	=	0x0083
                    0084    113 Fwireless_serial$DPL1$0$0 == 0x0084
                    0084    114 _DPL1	=	0x0084
                    0085    115 Fwireless_serial$DPH1$0$0 == 0x0085
                    0085    116 _DPH1	=	0x0085
                    0086    117 Fwireless_serial$U0CSR$0$0 == 0x0086
                    0086    118 _U0CSR	=	0x0086
                    0087    119 Fwireless_serial$PCON$0$0 == 0x0087
                    0087    120 _PCON	=	0x0087
                    0088    121 Fwireless_serial$TCON$0$0 == 0x0088
                    0088    122 _TCON	=	0x0088
                    0089    123 Fwireless_serial$P0IFG$0$0 == 0x0089
                    0089    124 _P0IFG	=	0x0089
                    008A    125 Fwireless_serial$P1IFG$0$0 == 0x008a
                    008A    126 _P1IFG	=	0x008a
                    008B    127 Fwireless_serial$P2IFG$0$0 == 0x008b
                    008B    128 _P2IFG	=	0x008b
                    008C    129 Fwireless_serial$PICTL$0$0 == 0x008c
                    008C    130 _PICTL	=	0x008c
                    008D    131 Fwireless_serial$P1IEN$0$0 == 0x008d
                    008D    132 _P1IEN	=	0x008d
                    008F    133 Fwireless_serial$P0INP$0$0 == 0x008f
                    008F    134 _P0INP	=	0x008f
                    0090    135 Fwireless_serial$P1$0$0 == 0x0090
                    0090    136 _P1	=	0x0090
                    0091    137 Fwireless_serial$RFIM$0$0 == 0x0091
                    0091    138 _RFIM	=	0x0091
                    0092    139 Fwireless_serial$DPS$0$0 == 0x0092
                    0092    140 _DPS	=	0x0092
                    0093    141 Fwireless_serial$MPAGE$0$0 == 0x0093
                    0093    142 _MPAGE	=	0x0093
                    0095    143 Fwireless_serial$ENDIAN$0$0 == 0x0095
                    0095    144 _ENDIAN	=	0x0095
                    0098    145 Fwireless_serial$S0CON$0$0 == 0x0098
                    0098    146 _S0CON	=	0x0098
                    009A    147 Fwireless_serial$IEN2$0$0 == 0x009a
                    009A    148 _IEN2	=	0x009a
                    009B    149 Fwireless_serial$S1CON$0$0 == 0x009b
                    009B    150 _S1CON	=	0x009b
                    009C    151 Fwireless_serial$T2CT$0$0 == 0x009c
                    009C    152 _T2CT	=	0x009c
                    009D    153 Fwireless_serial$T2PR$0$0 == 0x009d
                    009D    154 _T2PR	=	0x009d
                    009E    155 Fwireless_serial$T2CTL$0$0 == 0x009e
                    009E    156 _T2CTL	=	0x009e
                    00A0    157 Fwireless_serial$P2$0$0 == 0x00a0
                    00A0    158 _P2	=	0x00a0
                    00A1    159 Fwireless_serial$WORIRQ$0$0 == 0x00a1
                    00A1    160 _WORIRQ	=	0x00a1
                    00A2    161 Fwireless_serial$WORCTRL$0$0 == 0x00a2
                    00A2    162 _WORCTRL	=	0x00a2
                    00A3    163 Fwireless_serial$WOREVT0$0$0 == 0x00a3
                    00A3    164 _WOREVT0	=	0x00a3
                    00A4    165 Fwireless_serial$WOREVT1$0$0 == 0x00a4
                    00A4    166 _WOREVT1	=	0x00a4
                    00A5    167 Fwireless_serial$WORTIME0$0$0 == 0x00a5
                    00A5    168 _WORTIME0	=	0x00a5
                    00A6    169 Fwireless_serial$WORTIME1$0$0 == 0x00a6
                    00A6    170 _WORTIME1	=	0x00a6
                    00A8    171 Fwireless_serial$IEN0$0$0 == 0x00a8
                    00A8    172 _IEN0	=	0x00a8
                    00A9    173 Fwireless_serial$IP0$0$0 == 0x00a9
                    00A9    174 _IP0	=	0x00a9
                    00AB    175 Fwireless_serial$FWT$0$0 == 0x00ab
                    00AB    176 _FWT	=	0x00ab
                    00AC    177 Fwireless_serial$FADDRL$0$0 == 0x00ac
                    00AC    178 _FADDRL	=	0x00ac
                    00AD    179 Fwireless_serial$FADDRH$0$0 == 0x00ad
                    00AD    180 _FADDRH	=	0x00ad
                    00AE    181 Fwireless_serial$FCTL$0$0 == 0x00ae
                    00AE    182 _FCTL	=	0x00ae
                    00AF    183 Fwireless_serial$FWDATA$0$0 == 0x00af
                    00AF    184 _FWDATA	=	0x00af
                    00B1    185 Fwireless_serial$ENCDI$0$0 == 0x00b1
                    00B1    186 _ENCDI	=	0x00b1
                    00B2    187 Fwireless_serial$ENCDO$0$0 == 0x00b2
                    00B2    188 _ENCDO	=	0x00b2
                    00B3    189 Fwireless_serial$ENCCS$0$0 == 0x00b3
                    00B3    190 _ENCCS	=	0x00b3
                    00B4    191 Fwireless_serial$ADCCON1$0$0 == 0x00b4
                    00B4    192 _ADCCON1	=	0x00b4
                    00B5    193 Fwireless_serial$ADCCON2$0$0 == 0x00b5
                    00B5    194 _ADCCON2	=	0x00b5
                    00B6    195 Fwireless_serial$ADCCON3$0$0 == 0x00b6
                    00B6    196 _ADCCON3	=	0x00b6
                    00B8    197 Fwireless_serial$IEN1$0$0 == 0x00b8
                    00B8    198 _IEN1	=	0x00b8
                    00B9    199 Fwireless_serial$IP1$0$0 == 0x00b9
                    00B9    200 _IP1	=	0x00b9
                    00BA    201 Fwireless_serial$ADCL$0$0 == 0x00ba
                    00BA    202 _ADCL	=	0x00ba
                    00BB    203 Fwireless_serial$ADCH$0$0 == 0x00bb
                    00BB    204 _ADCH	=	0x00bb
                    00BC    205 Fwireless_serial$RNDL$0$0 == 0x00bc
                    00BC    206 _RNDL	=	0x00bc
                    00BD    207 Fwireless_serial$RNDH$0$0 == 0x00bd
                    00BD    208 _RNDH	=	0x00bd
                    00BE    209 Fwireless_serial$SLEEP$0$0 == 0x00be
                    00BE    210 _SLEEP	=	0x00be
                    00C0    211 Fwireless_serial$IRCON$0$0 == 0x00c0
                    00C0    212 _IRCON	=	0x00c0
                    00C1    213 Fwireless_serial$U0DBUF$0$0 == 0x00c1
                    00C1    214 _U0DBUF	=	0x00c1
                    00C2    215 Fwireless_serial$U0BAUD$0$0 == 0x00c2
                    00C2    216 _U0BAUD	=	0x00c2
                    00C4    217 Fwireless_serial$U0UCR$0$0 == 0x00c4
                    00C4    218 _U0UCR	=	0x00c4
                    00C5    219 Fwireless_serial$U0GCR$0$0 == 0x00c5
                    00C5    220 _U0GCR	=	0x00c5
                    00C6    221 Fwireless_serial$CLKCON$0$0 == 0x00c6
                    00C6    222 _CLKCON	=	0x00c6
                    00C7    223 Fwireless_serial$MEMCTR$0$0 == 0x00c7
                    00C7    224 _MEMCTR	=	0x00c7
                    00C9    225 Fwireless_serial$WDCTL$0$0 == 0x00c9
                    00C9    226 _WDCTL	=	0x00c9
                    00CA    227 Fwireless_serial$T3CNT$0$0 == 0x00ca
                    00CA    228 _T3CNT	=	0x00ca
                    00CB    229 Fwireless_serial$T3CTL$0$0 == 0x00cb
                    00CB    230 _T3CTL	=	0x00cb
                    00CC    231 Fwireless_serial$T3CCTL0$0$0 == 0x00cc
                    00CC    232 _T3CCTL0	=	0x00cc
                    00CD    233 Fwireless_serial$T3CC0$0$0 == 0x00cd
                    00CD    234 _T3CC0	=	0x00cd
                    00CE    235 Fwireless_serial$T3CCTL1$0$0 == 0x00ce
                    00CE    236 _T3CCTL1	=	0x00ce
                    00CF    237 Fwireless_serial$T3CC1$0$0 == 0x00cf
                    00CF    238 _T3CC1	=	0x00cf
                    00D0    239 Fwireless_serial$PSW$0$0 == 0x00d0
                    00D0    240 _PSW	=	0x00d0
                    00D1    241 Fwireless_serial$DMAIRQ$0$0 == 0x00d1
                    00D1    242 _DMAIRQ	=	0x00d1
                    00D2    243 Fwireless_serial$DMA1CFGL$0$0 == 0x00d2
                    00D2    244 _DMA1CFGL	=	0x00d2
                    00D3    245 Fwireless_serial$DMA1CFGH$0$0 == 0x00d3
                    00D3    246 _DMA1CFGH	=	0x00d3
                    00D4    247 Fwireless_serial$DMA0CFGL$0$0 == 0x00d4
                    00D4    248 _DMA0CFGL	=	0x00d4
                    00D5    249 Fwireless_serial$DMA0CFGH$0$0 == 0x00d5
                    00D5    250 _DMA0CFGH	=	0x00d5
                    00D6    251 Fwireless_serial$DMAARM$0$0 == 0x00d6
                    00D6    252 _DMAARM	=	0x00d6
                    00D7    253 Fwireless_serial$DMAREQ$0$0 == 0x00d7
                    00D7    254 _DMAREQ	=	0x00d7
                    00D8    255 Fwireless_serial$TIMIF$0$0 == 0x00d8
                    00D8    256 _TIMIF	=	0x00d8
                    00D9    257 Fwireless_serial$RFD$0$0 == 0x00d9
                    00D9    258 _RFD	=	0x00d9
                    00DA    259 Fwireless_serial$T1CC0L$0$0 == 0x00da
                    00DA    260 _T1CC0L	=	0x00da
                    00DB    261 Fwireless_serial$T1CC0H$0$0 == 0x00db
                    00DB    262 _T1CC0H	=	0x00db
                    00DC    263 Fwireless_serial$T1CC1L$0$0 == 0x00dc
                    00DC    264 _T1CC1L	=	0x00dc
                    00DD    265 Fwireless_serial$T1CC1H$0$0 == 0x00dd
                    00DD    266 _T1CC1H	=	0x00dd
                    00DE    267 Fwireless_serial$T1CC2L$0$0 == 0x00de
                    00DE    268 _T1CC2L	=	0x00de
                    00DF    269 Fwireless_serial$T1CC2H$0$0 == 0x00df
                    00DF    270 _T1CC2H	=	0x00df
                    00E0    271 Fwireless_serial$ACC$0$0 == 0x00e0
                    00E0    272 _ACC	=	0x00e0
                    00E1    273 Fwireless_serial$RFST$0$0 == 0x00e1
                    00E1    274 _RFST	=	0x00e1
                    00E2    275 Fwireless_serial$T1CNTL$0$0 == 0x00e2
                    00E2    276 _T1CNTL	=	0x00e2
                    00E3    277 Fwireless_serial$T1CNTH$0$0 == 0x00e3
                    00E3    278 _T1CNTH	=	0x00e3
                    00E4    279 Fwireless_serial$T1CTL$0$0 == 0x00e4
                    00E4    280 _T1CTL	=	0x00e4
                    00E5    281 Fwireless_serial$T1CCTL0$0$0 == 0x00e5
                    00E5    282 _T1CCTL0	=	0x00e5
                    00E6    283 Fwireless_serial$T1CCTL1$0$0 == 0x00e6
                    00E6    284 _T1CCTL1	=	0x00e6
                    00E7    285 Fwireless_serial$T1CCTL2$0$0 == 0x00e7
                    00E7    286 _T1CCTL2	=	0x00e7
                    00E8    287 Fwireless_serial$IRCON2$0$0 == 0x00e8
                    00E8    288 _IRCON2	=	0x00e8
                    00E9    289 Fwireless_serial$RFIF$0$0 == 0x00e9
                    00E9    290 _RFIF	=	0x00e9
                    00EA    291 Fwireless_serial$T4CNT$0$0 == 0x00ea
                    00EA    292 _T4CNT	=	0x00ea
                    00EB    293 Fwireless_serial$T4CTL$0$0 == 0x00eb
                    00EB    294 _T4CTL	=	0x00eb
                    00EC    295 Fwireless_serial$T4CCTL0$0$0 == 0x00ec
                    00EC    296 _T4CCTL0	=	0x00ec
                    00ED    297 Fwireless_serial$T4CC0$0$0 == 0x00ed
                    00ED    298 _T4CC0	=	0x00ed
                    00EE    299 Fwireless_serial$T4CCTL1$0$0 == 0x00ee
                    00EE    300 _T4CCTL1	=	0x00ee
                    00EF    301 Fwireless_serial$T4CC1$0$0 == 0x00ef
                    00EF    302 _T4CC1	=	0x00ef
                    00F0    303 Fwireless_serial$B$0$0 == 0x00f0
                    00F0    304 _B	=	0x00f0
                    00F1    305 Fwireless_serial$PERCFG$0$0 == 0x00f1
                    00F1    306 _PERCFG	=	0x00f1
                    00F2    307 Fwireless_serial$ADCCFG$0$0 == 0x00f2
                    00F2    308 _ADCCFG	=	0x00f2
                    00F3    309 Fwireless_serial$P0SEL$0$0 == 0x00f3
                    00F3    310 _P0SEL	=	0x00f3
                    00F4    311 Fwireless_serial$P1SEL$0$0 == 0x00f4
                    00F4    312 _P1SEL	=	0x00f4
                    00F5    313 Fwireless_serial$P2SEL$0$0 == 0x00f5
                    00F5    314 _P2SEL	=	0x00f5
                    00F6    315 Fwireless_serial$P1INP$0$0 == 0x00f6
                    00F6    316 _P1INP	=	0x00f6
                    00F7    317 Fwireless_serial$P2INP$0$0 == 0x00f7
                    00F7    318 _P2INP	=	0x00f7
                    00F8    319 Fwireless_serial$U1CSR$0$0 == 0x00f8
                    00F8    320 _U1CSR	=	0x00f8
                    00F9    321 Fwireless_serial$U1DBUF$0$0 == 0x00f9
                    00F9    322 _U1DBUF	=	0x00f9
                    00FA    323 Fwireless_serial$U1BAUD$0$0 == 0x00fa
                    00FA    324 _U1BAUD	=	0x00fa
                    00FB    325 Fwireless_serial$U1UCR$0$0 == 0x00fb
                    00FB    326 _U1UCR	=	0x00fb
                    00FC    327 Fwireless_serial$U1GCR$0$0 == 0x00fc
                    00FC    328 _U1GCR	=	0x00fc
                    00FD    329 Fwireless_serial$P0DIR$0$0 == 0x00fd
                    00FD    330 _P0DIR	=	0x00fd
                    00FE    331 Fwireless_serial$P1DIR$0$0 == 0x00fe
                    00FE    332 _P1DIR	=	0x00fe
                    00FF    333 Fwireless_serial$P2DIR$0$0 == 0x00ff
                    00FF    334 _P2DIR	=	0x00ff
                    FFFFD5D4    335 Fwireless_serial$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    336 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    337 Fwireless_serial$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    338 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    339 Fwireless_serial$FADDR$0$0 == 0xffffadac
                    FFFFADAC    340 _FADDR	=	0xffffadac
                    FFFFBBBA    341 Fwireless_serial$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    342 _ADC	=	0xffffbbba
                    FFFFDBDA    343 Fwireless_serial$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    344 _T1CC0	=	0xffffdbda
                    FFFFDDDC    345 Fwireless_serial$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    346 _T1CC1	=	0xffffdddc
                    FFFFDFDE    347 Fwireless_serial$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    348 _T1CC2	=	0xffffdfde
                            349 ;--------------------------------------------------------
                            350 ; special function bits
                            351 ;--------------------------------------------------------
                            352 	.area RSEG    (ABS,DATA)
   0000                     353 	.org 0x0000
                    0080    354 Fwireless_serial$P0_0$0$0 == 0x0080
                    0080    355 _P0_0	=	0x0080
                    0081    356 Fwireless_serial$P0_1$0$0 == 0x0081
                    0081    357 _P0_1	=	0x0081
                    0082    358 Fwireless_serial$P0_2$0$0 == 0x0082
                    0082    359 _P0_2	=	0x0082
                    0083    360 Fwireless_serial$P0_3$0$0 == 0x0083
                    0083    361 _P0_3	=	0x0083
                    0084    362 Fwireless_serial$P0_4$0$0 == 0x0084
                    0084    363 _P0_4	=	0x0084
                    0085    364 Fwireless_serial$P0_5$0$0 == 0x0085
                    0085    365 _P0_5	=	0x0085
                    0086    366 Fwireless_serial$P0_6$0$0 == 0x0086
                    0086    367 _P0_6	=	0x0086
                    0087    368 Fwireless_serial$P0_7$0$0 == 0x0087
                    0087    369 _P0_7	=	0x0087
                    0088    370 Fwireless_serial$_TCON_0$0$0 == 0x0088
                    0088    371 __TCON_0	=	0x0088
                    0089    372 Fwireless_serial$RFTXRXIF$0$0 == 0x0089
                    0089    373 _RFTXRXIF	=	0x0089
                    008A    374 Fwireless_serial$_TCON_2$0$0 == 0x008a
                    008A    375 __TCON_2	=	0x008a
                    008B    376 Fwireless_serial$URX0IF$0$0 == 0x008b
                    008B    377 _URX0IF	=	0x008b
                    008C    378 Fwireless_serial$_TCON_4$0$0 == 0x008c
                    008C    379 __TCON_4	=	0x008c
                    008D    380 Fwireless_serial$ADCIF$0$0 == 0x008d
                    008D    381 _ADCIF	=	0x008d
                    008E    382 Fwireless_serial$_TCON_6$0$0 == 0x008e
                    008E    383 __TCON_6	=	0x008e
                    008F    384 Fwireless_serial$URX1IF$0$0 == 0x008f
                    008F    385 _URX1IF	=	0x008f
                    0090    386 Fwireless_serial$P1_0$0$0 == 0x0090
                    0090    387 _P1_0	=	0x0090
                    0091    388 Fwireless_serial$P1_1$0$0 == 0x0091
                    0091    389 _P1_1	=	0x0091
                    0092    390 Fwireless_serial$P1_2$0$0 == 0x0092
                    0092    391 _P1_2	=	0x0092
                    0093    392 Fwireless_serial$P1_3$0$0 == 0x0093
                    0093    393 _P1_3	=	0x0093
                    0094    394 Fwireless_serial$P1_4$0$0 == 0x0094
                    0094    395 _P1_4	=	0x0094
                    0095    396 Fwireless_serial$P1_5$0$0 == 0x0095
                    0095    397 _P1_5	=	0x0095
                    0096    398 Fwireless_serial$P1_6$0$0 == 0x0096
                    0096    399 _P1_6	=	0x0096
                    0097    400 Fwireless_serial$P1_7$0$0 == 0x0097
                    0097    401 _P1_7	=	0x0097
                    0098    402 Fwireless_serial$ENCIF_0$0$0 == 0x0098
                    0098    403 _ENCIF_0	=	0x0098
                    0099    404 Fwireless_serial$ENCIF_1$0$0 == 0x0099
                    0099    405 _ENCIF_1	=	0x0099
                    009A    406 Fwireless_serial$_SOCON2$0$0 == 0x009a
                    009A    407 __SOCON2	=	0x009a
                    009B    408 Fwireless_serial$_SOCON3$0$0 == 0x009b
                    009B    409 __SOCON3	=	0x009b
                    009C    410 Fwireless_serial$_SOCON4$0$0 == 0x009c
                    009C    411 __SOCON4	=	0x009c
                    009D    412 Fwireless_serial$_SOCON5$0$0 == 0x009d
                    009D    413 __SOCON5	=	0x009d
                    009E    414 Fwireless_serial$_SOCON6$0$0 == 0x009e
                    009E    415 __SOCON6	=	0x009e
                    009F    416 Fwireless_serial$_SOCON7$0$0 == 0x009f
                    009F    417 __SOCON7	=	0x009f
                    00A0    418 Fwireless_serial$P2_0$0$0 == 0x00a0
                    00A0    419 _P2_0	=	0x00a0
                    00A1    420 Fwireless_serial$P2_1$0$0 == 0x00a1
                    00A1    421 _P2_1	=	0x00a1
                    00A2    422 Fwireless_serial$P2_2$0$0 == 0x00a2
                    00A2    423 _P2_2	=	0x00a2
                    00A3    424 Fwireless_serial$P2_3$0$0 == 0x00a3
                    00A3    425 _P2_3	=	0x00a3
                    00A4    426 Fwireless_serial$P2_4$0$0 == 0x00a4
                    00A4    427 _P2_4	=	0x00a4
                    00A5    428 Fwireless_serial$P2_5$0$0 == 0x00a5
                    00A5    429 _P2_5	=	0x00a5
                    00A6    430 Fwireless_serial$P2_6$0$0 == 0x00a6
                    00A6    431 _P2_6	=	0x00a6
                    00A7    432 Fwireless_serial$P2_7$0$0 == 0x00a7
                    00A7    433 _P2_7	=	0x00a7
                    00A8    434 Fwireless_serial$RFTXRXIE$0$0 == 0x00a8
                    00A8    435 _RFTXRXIE	=	0x00a8
                    00A9    436 Fwireless_serial$ADCIE$0$0 == 0x00a9
                    00A9    437 _ADCIE	=	0x00a9
                    00AA    438 Fwireless_serial$URX0IE$0$0 == 0x00aa
                    00AA    439 _URX0IE	=	0x00aa
                    00AB    440 Fwireless_serial$URX1IE$0$0 == 0x00ab
                    00AB    441 _URX1IE	=	0x00ab
                    00AC    442 Fwireless_serial$ENCIE$0$0 == 0x00ac
                    00AC    443 _ENCIE	=	0x00ac
                    00AD    444 Fwireless_serial$STIE$0$0 == 0x00ad
                    00AD    445 _STIE	=	0x00ad
                    00AE    446 Fwireless_serial$_IEN06$0$0 == 0x00ae
                    00AE    447 __IEN06	=	0x00ae
                    00AF    448 Fwireless_serial$EA$0$0 == 0x00af
                    00AF    449 _EA	=	0x00af
                    00B8    450 Fwireless_serial$DMAIE$0$0 == 0x00b8
                    00B8    451 _DMAIE	=	0x00b8
                    00B9    452 Fwireless_serial$T1IE$0$0 == 0x00b9
                    00B9    453 _T1IE	=	0x00b9
                    00BA    454 Fwireless_serial$T2IE$0$0 == 0x00ba
                    00BA    455 _T2IE	=	0x00ba
                    00BB    456 Fwireless_serial$T3IE$0$0 == 0x00bb
                    00BB    457 _T3IE	=	0x00bb
                    00BC    458 Fwireless_serial$T4IE$0$0 == 0x00bc
                    00BC    459 _T4IE	=	0x00bc
                    00BD    460 Fwireless_serial$P0IE$0$0 == 0x00bd
                    00BD    461 _P0IE	=	0x00bd
                    00BE    462 Fwireless_serial$_IEN16$0$0 == 0x00be
                    00BE    463 __IEN16	=	0x00be
                    00BF    464 Fwireless_serial$_IEN17$0$0 == 0x00bf
                    00BF    465 __IEN17	=	0x00bf
                    00C0    466 Fwireless_serial$DMAIF$0$0 == 0x00c0
                    00C0    467 _DMAIF	=	0x00c0
                    00C1    468 Fwireless_serial$T1IF$0$0 == 0x00c1
                    00C1    469 _T1IF	=	0x00c1
                    00C2    470 Fwireless_serial$T2IF$0$0 == 0x00c2
                    00C2    471 _T2IF	=	0x00c2
                    00C3    472 Fwireless_serial$T3IF$0$0 == 0x00c3
                    00C3    473 _T3IF	=	0x00c3
                    00C4    474 Fwireless_serial$T4IF$0$0 == 0x00c4
                    00C4    475 _T4IF	=	0x00c4
                    00C5    476 Fwireless_serial$P0IF$0$0 == 0x00c5
                    00C5    477 _P0IF	=	0x00c5
                    00C6    478 Fwireless_serial$_IRCON6$0$0 == 0x00c6
                    00C6    479 __IRCON6	=	0x00c6
                    00C7    480 Fwireless_serial$STIF$0$0 == 0x00c7
                    00C7    481 _STIF	=	0x00c7
                    00D0    482 Fwireless_serial$P$0$0 == 0x00d0
                    00D0    483 _P	=	0x00d0
                    00D1    484 Fwireless_serial$F1$0$0 == 0x00d1
                    00D1    485 _F1	=	0x00d1
                    00D2    486 Fwireless_serial$OV$0$0 == 0x00d2
                    00D2    487 _OV	=	0x00d2
                    00D3    488 Fwireless_serial$RS0$0$0 == 0x00d3
                    00D3    489 _RS0	=	0x00d3
                    00D4    490 Fwireless_serial$RS1$0$0 == 0x00d4
                    00D4    491 _RS1	=	0x00d4
                    00D5    492 Fwireless_serial$F0$0$0 == 0x00d5
                    00D5    493 _F0	=	0x00d5
                    00D6    494 Fwireless_serial$AC$0$0 == 0x00d6
                    00D6    495 _AC	=	0x00d6
                    00D7    496 Fwireless_serial$CY$0$0 == 0x00d7
                    00D7    497 _CY	=	0x00d7
                    00D8    498 Fwireless_serial$T3OVFIF$0$0 == 0x00d8
                    00D8    499 _T3OVFIF	=	0x00d8
                    00D9    500 Fwireless_serial$T3CH0IF$0$0 == 0x00d9
                    00D9    501 _T3CH0IF	=	0x00d9
                    00DA    502 Fwireless_serial$T3CH1IF$0$0 == 0x00da
                    00DA    503 _T3CH1IF	=	0x00da
                    00DB    504 Fwireless_serial$T4OVFIF$0$0 == 0x00db
                    00DB    505 _T4OVFIF	=	0x00db
                    00DC    506 Fwireless_serial$T4CH0IF$0$0 == 0x00dc
                    00DC    507 _T4CH0IF	=	0x00dc
                    00DD    508 Fwireless_serial$T4CH1IF$0$0 == 0x00dd
                    00DD    509 _T4CH1IF	=	0x00dd
                    00DE    510 Fwireless_serial$OVFIM$0$0 == 0x00de
                    00DE    511 _OVFIM	=	0x00de
                    00DF    512 Fwireless_serial$_TIMIF7$0$0 == 0x00df
                    00DF    513 __TIMIF7	=	0x00df
                    00E0    514 Fwireless_serial$ACC_0$0$0 == 0x00e0
                    00E0    515 _ACC_0	=	0x00e0
                    00E1    516 Fwireless_serial$ACC_1$0$0 == 0x00e1
                    00E1    517 _ACC_1	=	0x00e1
                    00E2    518 Fwireless_serial$ACC_2$0$0 == 0x00e2
                    00E2    519 _ACC_2	=	0x00e2
                    00E3    520 Fwireless_serial$ACC_3$0$0 == 0x00e3
                    00E3    521 _ACC_3	=	0x00e3
                    00E4    522 Fwireless_serial$ACC_4$0$0 == 0x00e4
                    00E4    523 _ACC_4	=	0x00e4
                    00E5    524 Fwireless_serial$ACC_5$0$0 == 0x00e5
                    00E5    525 _ACC_5	=	0x00e5
                    00E6    526 Fwireless_serial$ACC_6$0$0 == 0x00e6
                    00E6    527 _ACC_6	=	0x00e6
                    00E7    528 Fwireless_serial$ACC_7$0$0 == 0x00e7
                    00E7    529 _ACC_7	=	0x00e7
                    00E8    530 Fwireless_serial$P2IF$0$0 == 0x00e8
                    00E8    531 _P2IF	=	0x00e8
                    00E9    532 Fwireless_serial$UTX0IF$0$0 == 0x00e9
                    00E9    533 _UTX0IF	=	0x00e9
                    00EA    534 Fwireless_serial$UTX1IF$0$0 == 0x00ea
                    00EA    535 _UTX1IF	=	0x00ea
                    00EB    536 Fwireless_serial$P1IF$0$0 == 0x00eb
                    00EB    537 _P1IF	=	0x00eb
                    00EC    538 Fwireless_serial$WDTIF$0$0 == 0x00ec
                    00EC    539 _WDTIF	=	0x00ec
                    00ED    540 Fwireless_serial$_IRCON25$0$0 == 0x00ed
                    00ED    541 __IRCON25	=	0x00ed
                    00EE    542 Fwireless_serial$_IRCON26$0$0 == 0x00ee
                    00EE    543 __IRCON26	=	0x00ee
                    00EF    544 Fwireless_serial$_IRCON27$0$0 == 0x00ef
                    00EF    545 __IRCON27	=	0x00ef
                    00F0    546 Fwireless_serial$B_0$0$0 == 0x00f0
                    00F0    547 _B_0	=	0x00f0
                    00F1    548 Fwireless_serial$B_1$0$0 == 0x00f1
                    00F1    549 _B_1	=	0x00f1
                    00F2    550 Fwireless_serial$B_2$0$0 == 0x00f2
                    00F2    551 _B_2	=	0x00f2
                    00F3    552 Fwireless_serial$B_3$0$0 == 0x00f3
                    00F3    553 _B_3	=	0x00f3
                    00F4    554 Fwireless_serial$B_4$0$0 == 0x00f4
                    00F4    555 _B_4	=	0x00f4
                    00F5    556 Fwireless_serial$B_5$0$0 == 0x00f5
                    00F5    557 _B_5	=	0x00f5
                    00F6    558 Fwireless_serial$B_6$0$0 == 0x00f6
                    00F6    559 _B_6	=	0x00f6
                    00F7    560 Fwireless_serial$B_7$0$0 == 0x00f7
                    00F7    561 _B_7	=	0x00f7
                    00F8    562 Fwireless_serial$U1ACTIVE$0$0 == 0x00f8
                    00F8    563 _U1ACTIVE	=	0x00f8
                    00F9    564 Fwireless_serial$U1TX_BYTE$0$0 == 0x00f9
                    00F9    565 _U1TX_BYTE	=	0x00f9
                    00FA    566 Fwireless_serial$U1RX_BYTE$0$0 == 0x00fa
                    00FA    567 _U1RX_BYTE	=	0x00fa
                    00FB    568 Fwireless_serial$U1ERR$0$0 == 0x00fb
                    00FB    569 _U1ERR	=	0x00fb
                    00FC    570 Fwireless_serial$U1FE$0$0 == 0x00fc
                    00FC    571 _U1FE	=	0x00fc
                    00FD    572 Fwireless_serial$U1SLAVE$0$0 == 0x00fd
                    00FD    573 _U1SLAVE	=	0x00fd
                    00FE    574 Fwireless_serial$U1RE$0$0 == 0x00fe
                    00FE    575 _U1RE	=	0x00fe
                    00FF    576 Fwireless_serial$U1MODE$0$0 == 0x00ff
                    00FF    577 _U1MODE	=	0x00ff
                            578 ;--------------------------------------------------------
                            579 ; overlayable register banks
                            580 ;--------------------------------------------------------
                            581 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     582 	.ds 8
                            583 ;--------------------------------------------------------
                            584 ; overlayable bit register bank
                            585 ;--------------------------------------------------------
                            586 	.area BIT_BANK	(REL,OVR,DATA)
   0024                     587 bits:
   0024                     588 	.ds 1
                    8000    589 	b0 = bits[0]
                    8100    590 	b1 = bits[1]
                    8200    591 	b2 = bits[2]
                    8300    592 	b3 = bits[3]
                    8400    593 	b4 = bits[4]
                    8500    594 	b5 = bits[5]
                    8600    595 	b6 = bits[6]
                    8700    596 	b7 = bits[7]
                            597 ;--------------------------------------------------------
                            598 ; internal ram data
                            599 ;--------------------------------------------------------
                            600 	.area DSEG    (DATA)
                    0000    601 G$currentSerialMode$0$0==.
   0008                     602 _currentSerialMode::
   0008                     603 	.ds 1
                    0001    604 Lwireless_serial.updateLeds$count$3$9==.
   0009                     605 _updateLeds_count_3_9:
   0009                     606 	.ds 1
                    0002    607 Lwireless_serial.errorService$sloc0$1$0==.
   000A                     608 _errorService_sloc0_1_0:
   000A                     609 	.ds 4
                            610 ;--------------------------------------------------------
                            611 ; overlayable items in internal ram 
                            612 ;--------------------------------------------------------
                            613 	.area OSEG    (OVR,DATA)
                            614 ;--------------------------------------------------------
                            615 ; Stack segment in internal ram 
                            616 ;--------------------------------------------------------
                            617 	.area	SSEG	(DATA)
   0031                     618 __start__stack:
   0031                     619 	.ds	1
                            620 
                            621 ;--------------------------------------------------------
                            622 ; indirectly addressable internal ram data
                            623 ;--------------------------------------------------------
                            624 	.area ISEG    (DATA)
                            625 ;--------------------------------------------------------
                            626 ; absolute internal ram data
                            627 ;--------------------------------------------------------
                            628 	.area IABS    (ABS,DATA)
                            629 	.area IABS    (ABS,DATA)
                            630 ;--------------------------------------------------------
                            631 ; bit data
                            632 ;--------------------------------------------------------
                            633 	.area BSEG    (BIT)
                    0000    634 G$uartRxDisabled$0$0==.
   0000                     635 _uartRxDisabled::
   0000                     636 	.ds 1
                    0001    637 G$framingErrorActive$0$0==.
   0001                     638 _framingErrorActive::
   0001                     639 	.ds 1
                    0002    640 G$errorOccurredRecently$0$0==.
   0002                     641 _errorOccurredRecently::
   0002                     642 	.ds 1
                    0003    643 Lwireless_serial.updateLeds$dimYellowLed$1$1==.
   0003                     644 _updateLeds_dimYellowLed_1_1:
   0003                     645 	.ds 1
                    0004    646 Lwireless_serial.ioTxSignals$sloc0$1$0==.
   0004                     647 _ioTxSignals_sloc0_1_0:
   0004                     648 	.ds 1
                            649 ;--------------------------------------------------------
                            650 ; paged external ram data
                            651 ;--------------------------------------------------------
                            652 	.area PSEG    (PAG,XDATA)
                    0000    653 G$d_tilt$0$0==.
   F000                     654 _d_tilt::
   F000                     655 	.ds 2
                    0002    656 G$d_pan$0$0==.
   F002                     657 _d_pan::
   F002                     658 	.ds 2
                    0004    659 G$tilt_pos$0$0==.
   F004                     660 _tilt_pos::
   F004                     661 	.ds 2
                    0006    662 G$pan_pos$0$0==.
   F006                     663 _pan_pos::
   F006                     664 	.ds 2
                    0008    665 G$turnright$0$0==.
   F008                     666 _turnright::
   F008                     667 	.ds 2
                    000A    668 G$turnleft$0$0==.
   F00A                     669 _turnleft::
   F00A                     670 	.ds 2
                    000C    671 G$gunbutton$0$0==.
   F00C                     672 _gunbutton::
   F00C                     673 	.ds 2
                    000E    674 G$panicbutton$0$0==.
   F00E                     675 _panicbutton::
   F00E                     676 	.ds 2
                    0010    677 G$infobutton$0$0==.
   F010                     678 _infobutton::
   F010                     679 	.ds 2
                    0012    680 G$agitbutton$0$0==.
   F012                     681 _agitbutton::
   F012                     682 	.ds 2
                    0014    683 G$walk$0$0==.
   F014                     684 _walk::
   F014                     685 	.ds 2
                    0016    686 G$turn$0$0==.
   F016                     687 _turn::
   F016                     688 	.ds 2
                    0018    689 G$light$0$0==.
   F018                     690 _light::
   F018                     691 	.ds 2
                    001A    692 G$kneeling$0$0==.
   F01A                     693 _kneeling::
   F01A                     694 	.ds 2
                    001C    695 G$flopCnt$0$0==.
   F01C                     696 _flopCnt::
   F01C                     697 	.ds 2
                    001E    698 G$panic$0$0==.
   F01E                     699 _panic::
   F01E                     700 	.ds 2
                    0020    701 G$pan_add$0$0==.
   F020                     702 _pan_add::
   F020                     703 	.ds 2
                    0022    704 G$tilt_add$0$0==.
   F022                     705 _tilt_add::
   F022                     706 	.ds 2
                    0024    707 G$vals$0$0==.
   F024                     708 _vals::
   F024                     709 	.ds 7
                    002B    710 G$index_cmdr$0$0==.
   F02B                     711 _index_cmdr::
   F02B                     712 	.ds 2
                    002D    713 G$checksum_cmdr$0$0==.
   F02D                     714 _checksum_cmdr::
   F02D                     715 	.ds 2
                    002F    716 G$southpaw$0$0==.
   F02F                     717 _southpaw::
   F02F                     718 	.ds 1
                    0030    719 G$walkV$0$0==.
   F030                     720 _walkV::
   F030                     721 	.ds 2
                    0032    722 G$walkH$0$0==.
   F032                     723 _walkH::
   F032                     724 	.ds 2
                    0034    725 G$lookV$0$0==.
   F034                     726 _lookV::
   F034                     727 	.ds 2
                    0036    728 G$lookH$0$0==.
   F036                     729 _lookH::
   F036                     730 	.ds 2
                    0038    731 G$walkSPD$0$0==.
   F038                     732 _walkSPD::
   F038                     733 	.ds 2
                    003A    734 G$walkDIR$0$0==.
   F03A                     735 _walkDIR::
   F03A                     736 	.ds 4
                    003E    737 G$lastErrorTime$0$0==.
   F03E                     738 _lastErrorTime::
   F03E                     739 	.ds 1
                    003F    740 Lwireless_serial.updateLeds$lastRadioActivityTime$1$1==.
   F03F                     741 _updateLeds_lastRadioActivityTime_1_1:
   F03F                     742 	.ds 2
                    0041    743 Lwireless_serial.ioTxSignals$signals$1$1==.
   F041                     744 _ioTxSignals_signals_1_1:
   F041                     745 	.ds 1
                    0042    746 Lwireless_serial.ioTxSignals$nTrstPulseStartTime$1$1==.
   F042                     747 _ioTxSignals_nTrstPulseStartTime_1_1:
   F042                     748 	.ds 1
                    0043    749 Lwireless_serial.ioTxSignals$lastSignals$1$1==.
   F043                     750 _ioTxSignals_lastSignals_1_1:
   F043                     751 	.ds 1
                    0044    752 Lwireless_serial.errorService$lastRxLowTime$1$1==.
   F044                     753 _errorService_lastRxLowTime_1_1:
   F044                     754 	.ds 1
                            755 ;--------------------------------------------------------
                            756 ; external ram data
                            757 ;--------------------------------------------------------
                            758 	.area XSEG    (XDATA)
                    DF00    759 Fwireless_serial$SYNC1$0$0 == 0xdf00
                    DF00    760 _SYNC1	=	0xdf00
                    DF01    761 Fwireless_serial$SYNC0$0$0 == 0xdf01
                    DF01    762 _SYNC0	=	0xdf01
                    DF02    763 Fwireless_serial$PKTLEN$0$0 == 0xdf02
                    DF02    764 _PKTLEN	=	0xdf02
                    DF03    765 Fwireless_serial$PKTCTRL1$0$0 == 0xdf03
                    DF03    766 _PKTCTRL1	=	0xdf03
                    DF04    767 Fwireless_serial$PKTCTRL0$0$0 == 0xdf04
                    DF04    768 _PKTCTRL0	=	0xdf04
                    DF05    769 Fwireless_serial$ADDR$0$0 == 0xdf05
                    DF05    770 _ADDR	=	0xdf05
                    DF06    771 Fwireless_serial$CHANNR$0$0 == 0xdf06
                    DF06    772 _CHANNR	=	0xdf06
                    DF07    773 Fwireless_serial$FSCTRL1$0$0 == 0xdf07
                    DF07    774 _FSCTRL1	=	0xdf07
                    DF08    775 Fwireless_serial$FSCTRL0$0$0 == 0xdf08
                    DF08    776 _FSCTRL0	=	0xdf08
                    DF09    777 Fwireless_serial$FREQ2$0$0 == 0xdf09
                    DF09    778 _FREQ2	=	0xdf09
                    DF0A    779 Fwireless_serial$FREQ1$0$0 == 0xdf0a
                    DF0A    780 _FREQ1	=	0xdf0a
                    DF0B    781 Fwireless_serial$FREQ0$0$0 == 0xdf0b
                    DF0B    782 _FREQ0	=	0xdf0b
                    DF0C    783 Fwireless_serial$MDMCFG4$0$0 == 0xdf0c
                    DF0C    784 _MDMCFG4	=	0xdf0c
                    DF0D    785 Fwireless_serial$MDMCFG3$0$0 == 0xdf0d
                    DF0D    786 _MDMCFG3	=	0xdf0d
                    DF0E    787 Fwireless_serial$MDMCFG2$0$0 == 0xdf0e
                    DF0E    788 _MDMCFG2	=	0xdf0e
                    DF0F    789 Fwireless_serial$MDMCFG1$0$0 == 0xdf0f
                    DF0F    790 _MDMCFG1	=	0xdf0f
                    DF10    791 Fwireless_serial$MDMCFG0$0$0 == 0xdf10
                    DF10    792 _MDMCFG0	=	0xdf10
                    DF11    793 Fwireless_serial$DEVIATN$0$0 == 0xdf11
                    DF11    794 _DEVIATN	=	0xdf11
                    DF12    795 Fwireless_serial$MCSM2$0$0 == 0xdf12
                    DF12    796 _MCSM2	=	0xdf12
                    DF13    797 Fwireless_serial$MCSM1$0$0 == 0xdf13
                    DF13    798 _MCSM1	=	0xdf13
                    DF14    799 Fwireless_serial$MCSM0$0$0 == 0xdf14
                    DF14    800 _MCSM0	=	0xdf14
                    DF15    801 Fwireless_serial$FOCCFG$0$0 == 0xdf15
                    DF15    802 _FOCCFG	=	0xdf15
                    DF16    803 Fwireless_serial$BSCFG$0$0 == 0xdf16
                    DF16    804 _BSCFG	=	0xdf16
                    DF17    805 Fwireless_serial$AGCCTRL2$0$0 == 0xdf17
                    DF17    806 _AGCCTRL2	=	0xdf17
                    DF18    807 Fwireless_serial$AGCCTRL1$0$0 == 0xdf18
                    DF18    808 _AGCCTRL1	=	0xdf18
                    DF19    809 Fwireless_serial$AGCCTRL0$0$0 == 0xdf19
                    DF19    810 _AGCCTRL0	=	0xdf19
                    DF1A    811 Fwireless_serial$FREND1$0$0 == 0xdf1a
                    DF1A    812 _FREND1	=	0xdf1a
                    DF1B    813 Fwireless_serial$FREND0$0$0 == 0xdf1b
                    DF1B    814 _FREND0	=	0xdf1b
                    DF1C    815 Fwireless_serial$FSCAL3$0$0 == 0xdf1c
                    DF1C    816 _FSCAL3	=	0xdf1c
                    DF1D    817 Fwireless_serial$FSCAL2$0$0 == 0xdf1d
                    DF1D    818 _FSCAL2	=	0xdf1d
                    DF1E    819 Fwireless_serial$FSCAL1$0$0 == 0xdf1e
                    DF1E    820 _FSCAL1	=	0xdf1e
                    DF1F    821 Fwireless_serial$FSCAL0$0$0 == 0xdf1f
                    DF1F    822 _FSCAL0	=	0xdf1f
                    DF23    823 Fwireless_serial$TEST2$0$0 == 0xdf23
                    DF23    824 _TEST2	=	0xdf23
                    DF24    825 Fwireless_serial$TEST1$0$0 == 0xdf24
                    DF24    826 _TEST1	=	0xdf24
                    DF25    827 Fwireless_serial$TEST0$0$0 == 0xdf25
                    DF25    828 _TEST0	=	0xdf25
                    DF2E    829 Fwireless_serial$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    830 _PA_TABLE0	=	0xdf2e
                    DF2F    831 Fwireless_serial$IOCFG2$0$0 == 0xdf2f
                    DF2F    832 _IOCFG2	=	0xdf2f
                    DF30    833 Fwireless_serial$IOCFG1$0$0 == 0xdf30
                    DF30    834 _IOCFG1	=	0xdf30
                    DF31    835 Fwireless_serial$IOCFG0$0$0 == 0xdf31
                    DF31    836 _IOCFG0	=	0xdf31
                    DF36    837 Fwireless_serial$PARTNUM$0$0 == 0xdf36
                    DF36    838 _PARTNUM	=	0xdf36
                    DF37    839 Fwireless_serial$VERSION$0$0 == 0xdf37
                    DF37    840 _VERSION	=	0xdf37
                    DF38    841 Fwireless_serial$FREQEST$0$0 == 0xdf38
                    DF38    842 _FREQEST	=	0xdf38
                    DF39    843 Fwireless_serial$LQI$0$0 == 0xdf39
                    DF39    844 _LQI	=	0xdf39
                    DF3A    845 Fwireless_serial$RSSI$0$0 == 0xdf3a
                    DF3A    846 _RSSI	=	0xdf3a
                    DF3B    847 Fwireless_serial$MARCSTATE$0$0 == 0xdf3b
                    DF3B    848 _MARCSTATE	=	0xdf3b
                    DF3C    849 Fwireless_serial$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    850 _PKTSTATUS	=	0xdf3c
                    DF3D    851 Fwireless_serial$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    852 _VCO_VC_DAC	=	0xdf3d
                    DF40    853 Fwireless_serial$I2SCFG0$0$0 == 0xdf40
                    DF40    854 _I2SCFG0	=	0xdf40
                    DF41    855 Fwireless_serial$I2SCFG1$0$0 == 0xdf41
                    DF41    856 _I2SCFG1	=	0xdf41
                    DF42    857 Fwireless_serial$I2SDATL$0$0 == 0xdf42
                    DF42    858 _I2SDATL	=	0xdf42
                    DF43    859 Fwireless_serial$I2SDATH$0$0 == 0xdf43
                    DF43    860 _I2SDATH	=	0xdf43
                    DF44    861 Fwireless_serial$I2SWCNT$0$0 == 0xdf44
                    DF44    862 _I2SWCNT	=	0xdf44
                    DF45    863 Fwireless_serial$I2SSTAT$0$0 == 0xdf45
                    DF45    864 _I2SSTAT	=	0xdf45
                    DF46    865 Fwireless_serial$I2SCLKF0$0$0 == 0xdf46
                    DF46    866 _I2SCLKF0	=	0xdf46
                    DF47    867 Fwireless_serial$I2SCLKF1$0$0 == 0xdf47
                    DF47    868 _I2SCLKF1	=	0xdf47
                    DF48    869 Fwireless_serial$I2SCLKF2$0$0 == 0xdf48
                    DF48    870 _I2SCLKF2	=	0xdf48
                    DE00    871 Fwireless_serial$USBADDR$0$0 == 0xde00
                    DE00    872 _USBADDR	=	0xde00
                    DE01    873 Fwireless_serial$USBPOW$0$0 == 0xde01
                    DE01    874 _USBPOW	=	0xde01
                    DE02    875 Fwireless_serial$USBIIF$0$0 == 0xde02
                    DE02    876 _USBIIF	=	0xde02
                    DE04    877 Fwireless_serial$USBOIF$0$0 == 0xde04
                    DE04    878 _USBOIF	=	0xde04
                    DE06    879 Fwireless_serial$USBCIF$0$0 == 0xde06
                    DE06    880 _USBCIF	=	0xde06
                    DE07    881 Fwireless_serial$USBIIE$0$0 == 0xde07
                    DE07    882 _USBIIE	=	0xde07
                    DE09    883 Fwireless_serial$USBOIE$0$0 == 0xde09
                    DE09    884 _USBOIE	=	0xde09
                    DE0B    885 Fwireless_serial$USBCIE$0$0 == 0xde0b
                    DE0B    886 _USBCIE	=	0xde0b
                    DE0C    887 Fwireless_serial$USBFRML$0$0 == 0xde0c
                    DE0C    888 _USBFRML	=	0xde0c
                    DE0D    889 Fwireless_serial$USBFRMH$0$0 == 0xde0d
                    DE0D    890 _USBFRMH	=	0xde0d
                    DE0E    891 Fwireless_serial$USBINDEX$0$0 == 0xde0e
                    DE0E    892 _USBINDEX	=	0xde0e
                    DE10    893 Fwireless_serial$USBMAXI$0$0 == 0xde10
                    DE10    894 _USBMAXI	=	0xde10
                    DE11    895 Fwireless_serial$USBCSIL$0$0 == 0xde11
                    DE11    896 _USBCSIL	=	0xde11
                    DE12    897 Fwireless_serial$USBCSIH$0$0 == 0xde12
                    DE12    898 _USBCSIH	=	0xde12
                    DE13    899 Fwireless_serial$USBMAXO$0$0 == 0xde13
                    DE13    900 _USBMAXO	=	0xde13
                    DE14    901 Fwireless_serial$USBCSOL$0$0 == 0xde14
                    DE14    902 _USBCSOL	=	0xde14
                    DE15    903 Fwireless_serial$USBCSOH$0$0 == 0xde15
                    DE15    904 _USBCSOH	=	0xde15
                    DE16    905 Fwireless_serial$USBCNTL$0$0 == 0xde16
                    DE16    906 _USBCNTL	=	0xde16
                    DE17    907 Fwireless_serial$USBCNTH$0$0 == 0xde17
                    DE17    908 _USBCNTH	=	0xde17
                    DE20    909 Fwireless_serial$USBF0$0$0 == 0xde20
                    DE20    910 _USBF0	=	0xde20
                    DE22    911 Fwireless_serial$USBF1$0$0 == 0xde22
                    DE22    912 _USBF1	=	0xde22
                    DE24    913 Fwireless_serial$USBF2$0$0 == 0xde24
                    DE24    914 _USBF2	=	0xde24
                    DE26    915 Fwireless_serial$USBF3$0$0 == 0xde26
                    DE26    916 _USBF3	=	0xde26
                    DE28    917 Fwireless_serial$USBF4$0$0 == 0xde28
                    DE28    918 _USBF4	=	0xde28
                    DE2A    919 Fwireless_serial$USBF5$0$0 == 0xde2a
                    DE2A    920 _USBF5	=	0xde2a
                            921 ;--------------------------------------------------------
                            922 ; absolute external ram data
                            923 ;--------------------------------------------------------
                            924 	.area XABS    (ABS,XDATA)
                            925 ;--------------------------------------------------------
                            926 ; external initialized ram data
                            927 ;--------------------------------------------------------
                            928 	.area XISEG   (XDATA)
                            929 	.area HOME    (CODE)
                            930 	.area GSINIT0 (CODE)
                            931 	.area GSINIT1 (CODE)
                            932 	.area GSINIT2 (CODE)
                            933 	.area GSINIT3 (CODE)
                            934 	.area GSINIT4 (CODE)
                            935 	.area GSINIT5 (CODE)
                            936 	.area GSINIT  (CODE)
                            937 	.area GSFINAL (CODE)
                            938 	.area CSEG    (CODE)
                            939 ;--------------------------------------------------------
                            940 ; interrupt vector 
                            941 ;--------------------------------------------------------
                            942 	.area HOME    (CODE)
   0400                     943 __interrupt_vect:
   0400 02 04 8D            944 	ljmp	__sdcc_gsinit_startup
   0403 32                  945 	reti
   0404                     946 	.ds	7
   040B 32                  947 	reti
   040C                     948 	.ds	7
   0413 32                  949 	reti
   0414                     950 	.ds	7
   041B 02 0F 40            951 	ljmp	_ISR_URX1
   041E                     952 	.ds	5
   0423 32                  953 	reti
   0424                     954 	.ds	7
   042B 32                  955 	reti
   042C                     956 	.ds	7
   0433 32                  957 	reti
   0434                     958 	.ds	7
   043B 32                  959 	reti
   043C                     960 	.ds	7
   0443 32                  961 	reti
   0444                     962 	.ds	7
   044B 32                  963 	reti
   044C                     964 	.ds	7
   0453 32                  965 	reti
   0454                     966 	.ds	7
   045B 32                  967 	reti
   045C                     968 	.ds	7
   0463 02 23 80            969 	ljmp	_ISR_T4
   0466                     970 	.ds	5
   046B 32                  971 	reti
   046C                     972 	.ds	7
   0473 02 0F 02            973 	ljmp	_ISR_UTX1
   0476                     974 	.ds	5
   047B 32                  975 	reti
   047C                     976 	.ds	7
   0483 02 13 04            977 	ljmp	_ISR_RF
                            978 ;--------------------------------------------------------
                            979 ; global & static initialisations
                            980 ;--------------------------------------------------------
                            981 	.area HOME    (CODE)
                            982 	.area GSINIT  (CODE)
                            983 	.area GSFINAL (CODE)
                            984 	.area GSINIT  (CODE)
                            985 	.globl __sdcc_gsinit_startup
                            986 	.globl __sdcc_program_startup
                            987 	.globl __start__stack
                            988 	.globl __mcs51_genXINIT
                            989 	.globl __mcs51_genXRAMCLEAR
                            990 	.globl __mcs51_genRAMCLEAR
                            991 ;------------------------------------------------------------
                            992 ;Allocation info for local variables in function 'updateLeds'
                            993 ;------------------------------------------------------------
                            994 ;count                     Allocated with name '_updateLeds_count_3_9'
                            995 ;------------------------------------------------------------
                    0000    996 	G$updateLeds$0$0 ==.
                    0000    997 	C$wireless_serial.c$87$2$16 ==.
                            998 ;	apps/commander/wireless_serial.c:87: static BIT dimYellowLed = 0;
   04E6 C2 03               999 	clr	_updateLeds_dimYellowLed_1_1
                    0002   1000 	G$main$0$0 ==.
                    0002   1001 	C$wireless_serial.c$74$1$1 ==.
                           1002 ;	apps/commander/wireless_serial.c:74: BIT uartRxDisabled = 0;
   04E8 C2 00              1003 	clr	_uartRxDisabled
                    0004   1004 	G$main$0$0 ==.
                    0004   1005 	C$wireless_serial.c$78$1$1 ==.
                           1006 ;	apps/commander/wireless_serial.c:78: BIT framingErrorActive = 0;
   04EA C2 01              1007 	clr	_framingErrorActive
                    0006   1008 	G$main$0$0 ==.
                    0006   1009 	C$wireless_serial.c$80$1$1 ==.
                           1010 ;	apps/commander/wireless_serial.c:80: BIT errorOccurredRecently = 0;
   04EC C2 02              1011 	clr	_errorOccurredRecently
                           1012 	.area GSFINAL (CODE)
   0559 02 04 86           1013 	ljmp	__sdcc_program_startup
                           1014 ;--------------------------------------------------------
                           1015 ; Home
                           1016 ;--------------------------------------------------------
                           1017 	.area HOME    (CODE)
                           1018 	.area HOME    (CODE)
   0486                    1019 __sdcc_program_startup:
   0486 12 0C 6A           1020 	lcall	_main
                           1021 ;	return from main will lock up
   0489 80 FE              1022 	sjmp .
                           1023 ;--------------------------------------------------------
                           1024 ; code
                           1025 ;--------------------------------------------------------
                           1026 	.area CSEG    (CODE)
                           1027 ;------------------------------------------------------------
                           1028 ;Allocation info for local variables in function 'updateLeds'
                           1029 ;------------------------------------------------------------
                           1030 ;count                     Allocated with name '_updateLeds_count_3_9'
                           1031 ;------------------------------------------------------------
                    0000   1032 	G$updateLeds$0$0 ==.
                    0000   1033 	C$wireless_serial.c$85$0$0 ==.
                           1034 ;	apps/commander/wireless_serial.c:85: void updateLeds()
                           1035 ;	-----------------------------------------
                           1036 ;	 function updateLeds
                           1037 ;	-----------------------------------------
   055C                    1038 _updateLeds:
                    0007   1039 	ar7 = 0x07
                    0006   1040 	ar6 = 0x06
                    0005   1041 	ar5 = 0x05
                    0004   1042 	ar4 = 0x04
                    0003   1043 	ar3 = 0x03
                    0002   1044 	ar2 = 0x02
                    0001   1045 	ar1 = 0x01
                    0000   1046 	ar0 = 0x00
                    0000   1047 	C$wireless_serial.c$91$1$1 ==.
                           1048 ;	apps/commander/wireless_serial.c:91: usbShowStatusWithGreenLed();
   055C 12 28 FC           1049 	lcall	_usbShowStatusWithGreenLed
                    0003   1050 	C$wireless_serial.c$93$1$1 ==.
                           1051 ;	apps/commander/wireless_serial.c:93: now = (uint16)getMs();
   055F 12 23 A5           1052 	lcall	_getMs
   0562 AC 82              1053 	mov	r4,dpl
   0564 AD 83              1054 	mov	r5,dph
   0566 AE F0              1055 	mov	r6,b
   0568 FF                 1056 	mov	r7,a
                    000D   1057 	C$wireless_serial.c$95$1$1 ==.
                           1058 ;	apps/commander/wireless_serial.c:95: if (currentSerialMode == SERIAL_MODE_USB_UART)
   0569 74 03              1059 	mov	a,#0x03
   056B B5 08 09           1060 	cjne	a,_currentSerialMode,00111$
                    0012   1061 	C$wireless_serial.c$98$3$3 ==.
                           1062 ;	apps/commander/wireless_serial.c:98: LED_YELLOW(0);
   056E AF FF              1063 	mov	r7,_P2DIR
   0570 53 07 FB           1064 	anl	ar7,#0xFB
   0573 8F FF              1065 	mov	_P2DIR,r7
   0575 80 59              1066 	sjmp	00112$
   0577                    1067 00111$:
                    001B   1068 	C$wireless_serial.c$100$1$1 ==.
                           1069 ;	apps/commander/wireless_serial.c:100: else if (!radioLinkConnected())
   0577 C0 05              1070 	push	ar5
   0579 C0 04              1071 	push	ar4
   057B 12 0F F7           1072 	lcall	_radioLinkConnected
   057E D0 04              1073 	pop	ar4
   0580 D0 05              1074 	pop	ar5
   0582 40 12              1075 	jc	00108$
                    0028   1076 	C$wireless_serial.c$104$3$5 ==.
                           1077 ;	apps/commander/wireless_serial.c:104: LED_YELLOW(now & 0x200 ? 1 : 0);
   0584 ED                 1078 	mov	a,r5
   0585 30 E1 05           1079 	jnb	acc.1,00121$
   0588 43 FF 04           1080 	orl	_P2DIR,#0x04
   058B 80 43              1081 	sjmp	00112$
   058D                    1082 00121$:
   058D AF FF              1083 	mov	r7,_P2DIR
   058F 53 07 FB           1084 	anl	ar7,#0xFB
   0592 8F FF              1085 	mov	_P2DIR,r7
   0594 80 3A              1086 	sjmp	00112$
   0596                    1087 00108$:
                    003A   1088 	C$wireless_serial.c$110$2$6 ==.
                           1089 ;	apps/commander/wireless_serial.c:110: if ((now & 0x3FF) <= 20)
   0596 8C 06              1090 	mov	ar6,r4
   0598 74 03              1091 	mov	a,#0x03
   059A 5D                 1092 	anl	a,r5
   059B FF                 1093 	mov	r7,a
   059C C3                 1094 	clr	c
   059D 74 14              1095 	mov	a,#0x14
   059F 9E                 1096 	subb	a,r6
   05A0 E4                 1097 	clr	a
   05A1 9F                 1098 	subb	a,r7
   05A2 40 05              1099 	jc	00105$
                    0048   1100 	C$wireless_serial.c$113$4$8 ==.
                           1101 ;	apps/commander/wireless_serial.c:113: LED_YELLOW(1);
   05A4 43 FF 04           1102 	orl	_P2DIR,#0x04
   05A7 80 27              1103 	sjmp	00112$
   05A9                    1104 00105$:
                    004D   1105 	C$wireless_serial.c$115$2$6 ==.
                           1106 ;	apps/commander/wireless_serial.c:115: else if (dimYellowLed)
   05A9 30 03 1D           1107 	jnb	_updateLeds_dimYellowLed_1_1,00102$
                    0050   1108 	C$wireless_serial.c$118$3$9 ==.
                           1109 ;	apps/commander/wireless_serial.c:118: count++;
   05AC 05 09              1110 	inc	_updateLeds_count_3_9
                    0052   1111 	C$wireless_serial.c$119$4$10 ==.
                           1112 ;	apps/commander/wireless_serial.c:119: LED_YELLOW((count & 0x7)==0);
   05AE 74 07              1113 	mov	a,#0x07
   05B0 55 09              1114 	anl	a,_updateLeds_count_3_9
   05B2 FF                 1115 	mov	r7,a
   05B3 B4 01 00           1116 	cjne	a,#0x01,00148$
   05B6                    1117 00148$:
   05B6 E4                 1118 	clr	a
   05B7 33                 1119 	rlc	a
   05B8 FF                 1120 	mov	r7,a
   05B9 60 05              1121 	jz	00123$
   05BB 43 FF 04           1122 	orl	_P2DIR,#0x04
   05BE 80 10              1123 	sjmp	00112$
   05C0                    1124 00123$:
   05C0 AF FF              1125 	mov	r7,_P2DIR
   05C2 53 07 FB           1126 	anl	ar7,#0xFB
   05C5 8F FF              1127 	mov	_P2DIR,r7
   05C7 80 07              1128 	sjmp	00112$
   05C9                    1129 00102$:
                    006D   1130 	C$wireless_serial.c$123$4$12 ==.
                           1131 ;	apps/commander/wireless_serial.c:123: LED_YELLOW(0);
   05C9 AF FF              1132 	mov	r7,_P2DIR
   05CB 53 07 FB           1133 	anl	ar7,#0xFB
   05CE 8F FF              1134 	mov	_P2DIR,r7
   05D0                    1135 00112$:
                    0074   1136 	C$wireless_serial.c$127$1$1 ==.
                           1137 ;	apps/commander/wireless_serial.c:127: if (radioLinkActivityOccurred)
                    0074   1138 	C$wireless_serial.c$129$2$13 ==.
                           1139 ;	apps/commander/wireless_serial.c:129: radioLinkActivityOccurred = 0;
   05D0 10 0D 02           1140 	jbc	_radioLinkActivityOccurred,00150$
   05D3 80 12              1141 	sjmp	00114$
   05D5                    1142 00150$:
                    0079   1143 	C$wireless_serial.c$130$2$13 ==.
                           1144 ;	apps/commander/wireless_serial.c:130: dimYellowLed ^= 1;
   05D5 A2 03              1145 	mov	c,_updateLeds_dimYellowLed_1_1
   05D7 E4                 1146 	clr	a
   05D8 33                 1147 	rlc	a
   05D9 64 01              1148 	xrl	a,#0x01
   05DB FF                 1149 	mov	r7,a
   05DC 24 FF              1150 	add	a,#0xff
   05DE 92 03              1151 	mov	_updateLeds_dimYellowLed_1_1,c
                    0084   1152 	C$wireless_serial.c$132$2$13 ==.
                           1153 ;	apps/commander/wireless_serial.c:132: lastRadioActivityTime = now;
   05E0 78 3F              1154 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   05E2 EC                 1155 	mov	a,r4
   05E3 F2                 1156 	movx	@r0,a
   05E4 08                 1157 	inc	r0
   05E5 ED                 1158 	mov	a,r5
   05E6 F2                 1159 	movx	@r0,a
   05E7                    1160 00114$:
                    008B   1161 	C$wireless_serial.c$135$1$1 ==.
                           1162 ;	apps/commander/wireless_serial.c:135: if ((uint16)(now - lastRadioActivityTime) > 32)
   05E7 78 3F              1163 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   05E9 D3                 1164 	setb	c
   05EA E2                 1165 	movx	a,@r0
   05EB 9C                 1166 	subb	a,r4
   05EC F4                 1167 	cpl	a
   05ED B3                 1168 	cpl	c
   05EE FE                 1169 	mov	r6,a
   05EF B3                 1170 	cpl	c
   05F0 08                 1171 	inc	r0
   05F1 E2                 1172 	movx	a,@r0
   05F2 9D                 1173 	subb	a,r5
   05F3 F4                 1174 	cpl	a
   05F4 FF                 1175 	mov	r7,a
   05F5 C3                 1176 	clr	c
   05F6 74 20              1177 	mov	a,#0x20
   05F8 9E                 1178 	subb	a,r6
   05F9 E4                 1179 	clr	a
   05FA 9F                 1180 	subb	a,r7
   05FB 50 02              1181 	jnc	00116$
                    00A1   1182 	C$wireless_serial.c$137$2$14 ==.
                           1183 ;	apps/commander/wireless_serial.c:137: dimYellowLed = 0;
   05FD C2 03              1184 	clr	_updateLeds_dimYellowLed_1_1
   05FF                    1185 00116$:
                    00A3   1186 	C$wireless_serial.c$140$1$1 ==.
                           1187 ;	apps/commander/wireless_serial.c:140: if ((uint8)(now - lastErrorTime) > 100)
   05FF 78 3E              1188 	mov	r0,#_lastErrorTime
   0601 D3                 1189 	setb	c
   0602 E2                 1190 	movx	a,@r0
   0603 9C                 1191 	subb	a,r4
   0604 F4                 1192 	cpl	a
   0605 FC                 1193 	mov  r4,a
   0606 24 9B              1194 	add	a,#0xff - 0x64
   0608 50 02              1195 	jnc	00118$
                    00AE   1196 	C$wireless_serial.c$142$2$15 ==.
                           1197 ;	apps/commander/wireless_serial.c:142: errorOccurredRecently = 0;
   060A C2 02              1198 	clr	_errorOccurredRecently
   060C                    1199 00118$:
                    00B0   1200 	C$wireless_serial.c$145$2$16 ==.
                           1201 ;	apps/commander/wireless_serial.c:145: LED_RED(errorOccurredRecently || uartRxDisabled);
   060C 20 02 07           1202 	jb	_errorOccurredRecently,00128$
   060F 20 00 04           1203 	jb	_uartRxDisabled,00128$
   0612 7F 00              1204 	mov	r7,#0x00
   0614 80 02              1205 	sjmp	00129$
   0616                    1206 00128$:
   0616 7F 01              1207 	mov	r7,#0x01
   0618                    1208 00129$:
   0618 EF                 1209 	mov	a,r7
   0619 60 05              1210 	jz	00125$
   061B 43 FF 02           1211 	orl	_P2DIR,#0x02
   061E 80 07              1212 	sjmp	00119$
   0620                    1213 00125$:
   0620 AF FF              1214 	mov	r7,_P2DIR
   0622 53 07 FD           1215 	anl	ar7,#0xFD
   0625 8F FF              1216 	mov	_P2DIR,r7
   0627                    1217 00119$:
                    00CB   1218 	C$wireless_serial.c$146$2$16 ==.
                    00CB   1219 	XG$updateLeds$0$0 ==.
   0627 22                 1220 	ret
                           1221 ;------------------------------------------------------------
                           1222 ;Allocation info for local variables in function 'ioRxSignals'
                           1223 ;------------------------------------------------------------
                    00CC   1224 	G$ioRxSignals$0$0 ==.
                    00CC   1225 	C$wireless_serial.c$151$2$16 ==.
                           1226 ;	apps/commander/wireless_serial.c:151: uint8 ioRxSignals()
                           1227 ;	-----------------------------------------
                           1228 ;	 function ioRxSignals
                           1229 ;	-----------------------------------------
   0628                    1230 _ioRxSignals:
                    00CC   1231 	C$wireless_serial.c$153$1$16 ==.
                           1232 ;	apps/commander/wireless_serial.c:153: uint8 signals = 0;
   0628 7F 00              1233 	mov	r7,#0x00
                    00CE   1234 	C$wireless_serial.c$155$1$1 ==.
                           1235 ;	apps/commander/wireless_serial.c:155: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   062A 90 2C 23           1236 	mov	dptr,#_param_CD_pin
   062D E4                 1237 	clr	a
   062E 93                 1238 	movc	a,@a+dptr
   062F FB                 1239 	mov	r3,a
   0630 74 01              1240 	mov	a,#0x01
   0632 93                 1241 	movc	a,@a+dptr
   0633 FC                 1242 	mov	r4,a
   0634 74 02              1243 	mov	a,#0x02
   0636 93                 1244 	movc	a,@a+dptr
   0637 FD                 1245 	mov	r5,a
   0638 74 03              1246 	mov	a,#0x03
   063A 93                 1247 	movc	a,@a+dptr
   063B FE                 1248 	mov	r6,a
   063C 20 E7 0B           1249 	jb	acc.7,00105$
   063F 8B 82              1250 	mov	dpl,r3
   0641 C0 07              1251 	push	ar7
   0643 12 27 1C           1252 	lcall	_isPinHigh
   0646 D0 07              1253 	pop	ar7
   0648 40 20              1254 	jc	00101$
   064A                    1255 00105$:
                    00EE   1256 	C$wireless_serial.c$156$1$1 ==.
                           1257 ;	apps/commander/wireless_serial.c:156: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   064A 90 2C 13           1258 	mov	dptr,#_param_nCD_pin
   064D E4                 1259 	clr	a
   064E 93                 1260 	movc	a,@a+dptr
   064F FB                 1261 	mov	r3,a
   0650 74 01              1262 	mov	a,#0x01
   0652 93                 1263 	movc	a,@a+dptr
   0653 FC                 1264 	mov	r4,a
   0654 74 02              1265 	mov	a,#0x02
   0656 93                 1266 	movc	a,@a+dptr
   0657 FD                 1267 	mov	r5,a
   0658 74 03              1268 	mov	a,#0x03
   065A 93                 1269 	movc	a,@a+dptr
   065B FE                 1270 	mov	r6,a
   065C 20 E7 0D           1271 	jb	acc.7,00102$
   065F 8B 82              1272 	mov	dpl,r3
   0661 C0 07              1273 	push	ar7
   0663 12 27 1C           1274 	lcall	_isPinHigh
   0666 D0 07              1275 	pop	ar7
   0668 40 02              1276 	jc	00102$
   066A                    1277 00101$:
                    010E   1278 	C$wireless_serial.c$158$2$2 ==.
                           1279 ;	apps/commander/wireless_serial.c:158: signals |= 2;
   066A 7F 02              1280 	mov	r7,#0x02
   066C                    1281 00102$:
                    0110   1282 	C$wireless_serial.c$161$1$1 ==.
                           1283 ;	apps/commander/wireless_serial.c:161: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   066C 90 2C 1F           1284 	mov	dptr,#_param_DSR_pin
   066F E4                 1285 	clr	a
   0670 93                 1286 	movc	a,@a+dptr
   0671 FB                 1287 	mov	r3,a
   0672 74 01              1288 	mov	a,#0x01
   0674 93                 1289 	movc	a,@a+dptr
   0675 FC                 1290 	mov	r4,a
   0676 74 02              1291 	mov	a,#0x02
   0678 93                 1292 	movc	a,@a+dptr
   0679 FD                 1293 	mov	r5,a
   067A 74 03              1294 	mov	a,#0x03
   067C 93                 1295 	movc	a,@a+dptr
   067D FE                 1296 	mov	r6,a
   067E 20 E7 0B           1297 	jb	acc.7,00110$
   0681 8B 82              1298 	mov	dpl,r3
   0683 C0 07              1299 	push	ar7
   0685 12 27 1C           1300 	lcall	_isPinHigh
   0688 D0 07              1301 	pop	ar7
   068A 40 20              1302 	jc	00106$
   068C                    1303 00110$:
                    0130   1304 	C$wireless_serial.c$162$1$1 ==.
                           1305 ;	apps/commander/wireless_serial.c:162: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   068C 90 2C 0F           1306 	mov	dptr,#_param_nDSR_pin
   068F E4                 1307 	clr	a
   0690 93                 1308 	movc	a,@a+dptr
   0691 FB                 1309 	mov	r3,a
   0692 74 01              1310 	mov	a,#0x01
   0694 93                 1311 	movc	a,@a+dptr
   0695 FC                 1312 	mov	r4,a
   0696 74 02              1313 	mov	a,#0x02
   0698 93                 1314 	movc	a,@a+dptr
   0699 FD                 1315 	mov	r5,a
   069A 74 03              1316 	mov	a,#0x03
   069C 93                 1317 	movc	a,@a+dptr
   069D FE                 1318 	mov	r6,a
   069E 20 E7 0E           1319 	jb	acc.7,00107$
   06A1 8B 82              1320 	mov	dpl,r3
   06A3 C0 07              1321 	push	ar7
   06A5 12 27 1C           1322 	lcall	_isPinHigh
   06A8 D0 07              1323 	pop	ar7
   06AA 40 03              1324 	jc	00107$
   06AC                    1325 00106$:
                    0150   1326 	C$wireless_serial.c$164$2$3 ==.
                           1327 ;	apps/commander/wireless_serial.c:164: signals |= 1;
   06AC 43 07 01           1328 	orl	ar7,#0x01
   06AF                    1329 00107$:
                    0153   1330 	C$wireless_serial.c$167$1$1 ==.
                           1331 ;	apps/commander/wireless_serial.c:167: return signals;
   06AF 8F 82              1332 	mov	dpl,r7
                    0155   1333 	C$wireless_serial.c$168$1$1 ==.
                    0155   1334 	XG$ioRxSignals$0$0 ==.
   06B1 22                 1335 	ret
                           1336 ;------------------------------------------------------------
                           1337 ;Allocation info for local variables in function 'ioTxSignals'
                           1338 ;------------------------------------------------------------
                    0156   1339 	G$ioTxSignals$0$0 ==.
                    0156   1340 	C$wireless_serial.c$174$1$1 ==.
                           1341 ;	apps/commander/wireless_serial.c:174: void ioTxSignals(uint8 signals)
                           1342 ;	-----------------------------------------
                           1343 ;	 function ioTxSignals
                           1344 ;	-----------------------------------------
   06B2                    1345 _ioTxSignals:
   06B2 E5 82              1346 	mov	a,dpl
   06B4 78 41              1347 	mov	r0,#_ioTxSignals_signals_1_1
   06B6 F2                 1348 	movx	@r0,a
                    015B   1349 	C$wireless_serial.c$180$1$1 ==.
                           1350 ;	apps/commander/wireless_serial.c:180: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   06B7 78 41              1351 	mov	r0,#_ioTxSignals_signals_1_1
   06B9 E2                 1352 	movx	a,@r0
   06BA 54 01              1353 	anl	a,#0x01
   06BC FE                 1354 	mov	r6,a
   06BD B4 01 00           1355 	cjne	a,#0x01,00112$
   06C0                    1356 00112$:
   06C0 E4                 1357 	clr	a
   06C1 33                 1358 	rlc	a
   06C2 24 FF              1359 	add	a,#0xff
   06C4 92 04              1360 	mov	_ioTxSignals_sloc0_1_0,c
   06C6 90 2C 07           1361 	mov	dptr,#_param_nDTR_pin
   06C9 E4                 1362 	clr	a
   06CA 93                 1363 	movc	a,@a+dptr
   06CB FA                 1364 	mov	r2,a
   06CC 74 01              1365 	mov	a,#0x01
   06CE 93                 1366 	movc	a,@a+dptr
   06CF 74 02              1367 	mov	a,#0x02
   06D1 93                 1368 	movc	a,@a+dptr
   06D2 74 03              1369 	mov	a,#0x03
   06D4 93                 1370 	movc	a,@a+dptr
   06D5 8A 82              1371 	mov	dpl,r2
   06D7 A2 04              1372 	mov	c,_ioTxSignals_sloc0_1_0
   06D9 92 F0              1373 	mov	b[0],c
   06DB C0 06              1374 	push	ar6
   06DD 85 F0 24           1375 	mov	bits,b
   06E0 12 24 05           1376 	lcall	_setDigitalOutput
   06E3 D0 06              1377 	pop	ar6
                    0189   1378 	C$wireless_serial.c$181$1$1 ==.
                           1379 ;	apps/commander/wireless_serial.c:181: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   06E5 78 41              1380 	mov	r0,#_ioTxSignals_signals_1_1
   06E7 E2                 1381 	movx	a,@r0
   06E8 03                 1382 	rr	a
   06E9 54 01              1383 	anl	a,#0x01
   06EB FD                 1384 	mov	r5,a
   06EC B4 01 00           1385 	cjne	a,#0x01,00113$
   06EF                    1386 00113$:
   06EF E4                 1387 	clr	a
   06F0 33                 1388 	rlc	a
   06F1 24 FF              1389 	add	a,#0xff
   06F3 92 04              1390 	mov	_ioTxSignals_sloc0_1_0,c
   06F5 90 2C 0B           1391 	mov	dptr,#_param_nRTS_pin
   06F8 E4                 1392 	clr	a
   06F9 93                 1393 	movc	a,@a+dptr
   06FA FA                 1394 	mov	r2,a
   06FB 74 01              1395 	mov	a,#0x01
   06FD 93                 1396 	movc	a,@a+dptr
   06FE 74 02              1397 	mov	a,#0x02
   0700 93                 1398 	movc	a,@a+dptr
   0701 74 03              1399 	mov	a,#0x03
   0703 93                 1400 	movc	a,@a+dptr
   0704 8A 82              1401 	mov	dpl,r2
   0706 A2 04              1402 	mov	c,_ioTxSignals_sloc0_1_0
   0708 92 F0              1403 	mov	b[0],c
   070A C0 06              1404 	push	ar6
   070C C0 05              1405 	push	ar5
   070E 85 F0 24           1406 	mov	bits,b
   0711 12 24 05           1407 	lcall	_setDigitalOutput
   0714 D0 05              1408 	pop	ar5
   0716 D0 06              1409 	pop	ar6
                    01BC   1410 	C$wireless_serial.c$184$1$1 ==.
                           1411 ;	apps/commander/wireless_serial.c:184: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0718 EE                 1412 	mov	a,r6
   0719 24 FF              1413 	add	a,#0xff
   071B 92 04              1414 	mov	_ioTxSignals_sloc0_1_0,c
   071D 90 2C 17           1415 	mov	dptr,#_param_DTR_pin
   0720 E4                 1416 	clr	a
   0721 93                 1417 	movc	a,@a+dptr
   0722 FB                 1418 	mov	r3,a
   0723 74 01              1419 	mov	a,#0x01
   0725 93                 1420 	movc	a,@a+dptr
   0726 74 02              1421 	mov	a,#0x02
   0728 93                 1422 	movc	a,@a+dptr
   0729 74 03              1423 	mov	a,#0x03
   072B 93                 1424 	movc	a,@a+dptr
   072C 8B 82              1425 	mov	dpl,r3
   072E A2 04              1426 	mov	c,_ioTxSignals_sloc0_1_0
   0730 92 F0              1427 	mov	b[0],c
   0732 C0 05              1428 	push	ar5
   0734 85 F0 24           1429 	mov	bits,b
   0737 12 24 05           1430 	lcall	_setDigitalOutput
   073A D0 05              1431 	pop	ar5
                    01E0   1432 	C$wireless_serial.c$185$1$1 ==.
                           1433 ;	apps/commander/wireless_serial.c:185: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   073C ED                 1434 	mov	a,r5
   073D 24 FF              1435 	add	a,#0xff
   073F 92 04              1436 	mov	_ioTxSignals_sloc0_1_0,c
   0741 90 2C 1B           1437 	mov	dptr,#_param_RTS_pin
   0744 E4                 1438 	clr	a
   0745 93                 1439 	movc	a,@a+dptr
   0746 FC                 1440 	mov	r4,a
   0747 74 01              1441 	mov	a,#0x01
   0749 93                 1442 	movc	a,@a+dptr
   074A 74 02              1443 	mov	a,#0x02
   074C 93                 1444 	movc	a,@a+dptr
   074D 74 03              1445 	mov	a,#0x03
   074F 93                 1446 	movc	a,@a+dptr
   0750 8C 82              1447 	mov	dpl,r4
   0752 A2 04              1448 	mov	c,_ioTxSignals_sloc0_1_0
   0754 92 F0              1449 	mov	b[0],c
   0756 85 F0 24           1450 	mov	bits,b
   0759 12 24 05           1451 	lcall	_setDigitalOutput
                    0200   1452 	C$wireless_serial.c$188$1$1 ==.
                           1453 ;	apps/commander/wireless_serial.c:188: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   075C 78 43              1454 	mov	r0,#_ioTxSignals_lastSignals_1_1
   075E E2                 1455 	movx	a,@r0
   075F 54 01              1456 	anl	a,#0x01
   0761 60 02              1457 	jz	00115$
   0763 80 30              1458 	sjmp	00104$
   0765                    1459 00115$:
   0765 78 41              1460 	mov	r0,#_ioTxSignals_signals_1_1
   0767 E2                 1461 	movx	a,@r0
   0768 54 01              1462 	anl	a,#0x01
   076A 60 29              1463 	jz	00104$
                    0210   1464 	C$wireless_serial.c$192$2$2 ==.
                           1465 ;	apps/commander/wireless_serial.c:192: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   076C 90 2C 27           1466 	mov	dptr,#_param_arduino_DTR_pin
   076F E4                 1467 	clr	a
   0770 93                 1468 	movc	a,@a+dptr
   0771 FC                 1469 	mov	r4,a
   0772 74 01              1470 	mov	a,#0x01
   0774 93                 1471 	movc	a,@a+dptr
   0775 74 02              1472 	mov	a,#0x02
   0777 93                 1473 	movc	a,@a+dptr
   0778 74 03              1474 	mov	a,#0x03
   077A 93                 1475 	movc	a,@a+dptr
   077B 8C 82              1476 	mov	dpl,r4
   077D D2 F0              1477 	setb	b[0]
   077F 85 F0 24           1478 	mov	bits,b
   0782 12 24 05           1479 	lcall	_setDigitalOutput
                    0229   1480 	C$wireless_serial.c$193$2$2 ==.
                           1481 ;	apps/commander/wireless_serial.c:193: nTrstPulseStartTime = getMs();
   0785 12 23 A5           1482 	lcall	_getMs
   0788 AC 82              1483 	mov	r4,dpl
   078A AD 83              1484 	mov	r5,dph
   078C AE F0              1485 	mov	r6,b
   078E FF                 1486 	mov	r7,a
   078F 78 42              1487 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0791 EC                 1488 	mov	a,r4
   0792 F2                 1489 	movx	@r0,a
   0793 80 2F              1490 	sjmp	00105$
   0795                    1491 00104$:
                    0239   1492 	C$wireless_serial.c$195$1$1 ==.
                           1493 ;	apps/commander/wireless_serial.c:195: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   0795 12 23 A5           1494 	lcall	_getMs
   0798 AC 82              1495 	mov	r4,dpl
   079A AD 83              1496 	mov	r5,dph
   079C AE F0              1497 	mov	r6,b
   079E FF                 1498 	mov	r7,a
   079F 78 42              1499 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   07A1 D3                 1500 	setb	c
   07A2 E2                 1501 	movx	a,@r0
   07A3 9C                 1502 	subb	a,r4
   07A4 F4                 1503 	cpl	a
   07A5 FC                 1504 	mov	r4,a
   07A6 BC 02 00           1505 	cjne	r4,#0x02,00117$
   07A9                    1506 00117$:
   07A9 40 19              1507 	jc	00105$
                    024F   1508 	C$wireless_serial.c$197$2$3 ==.
                           1509 ;	apps/commander/wireless_serial.c:197: setDigitalOutput(param_arduino_DTR_pin, LOW);
   07AB 90 2C 27           1510 	mov	dptr,#_param_arduino_DTR_pin
   07AE E4                 1511 	clr	a
   07AF 93                 1512 	movc	a,@a+dptr
   07B0 FC                 1513 	mov	r4,a
   07B1 74 01              1514 	mov	a,#0x01
   07B3 93                 1515 	movc	a,@a+dptr
   07B4 74 02              1516 	mov	a,#0x02
   07B6 93                 1517 	movc	a,@a+dptr
   07B7 74 03              1518 	mov	a,#0x03
   07B9 93                 1519 	movc	a,@a+dptr
   07BA 8C 82              1520 	mov	dpl,r4
   07BC C2 F0              1521 	clr	b[0]
   07BE 85 F0 24           1522 	mov	bits,b
   07C1 12 24 05           1523 	lcall	_setDigitalOutput
   07C4                    1524 00105$:
                    0268   1525 	C$wireless_serial.c$200$1$1 ==.
                           1526 ;	apps/commander/wireless_serial.c:200: lastSignals = signals;
   07C4 78 41              1527 	mov	r0,#_ioTxSignals_signals_1_1
   07C6 79 43              1528 	mov	r1,#_ioTxSignals_lastSignals_1_1
   07C8 E2                 1529 	movx	a,@r0
   07C9 F3                 1530 	movx	@r1,a
                    026E   1531 	C$wireless_serial.c$201$1$1 ==.
                    026E   1532 	XG$ioTxSignals$0$0 ==.
   07CA 22                 1533 	ret
                           1534 ;------------------------------------------------------------
                           1535 ;Allocation info for local variables in function 'errorOccurred'
                           1536 ;------------------------------------------------------------
                    026F   1537 	G$errorOccurred$0$0 ==.
                    026F   1538 	C$wireless_serial.c$203$1$1 ==.
                           1539 ;	apps/commander/wireless_serial.c:203: void errorOccurred()
                           1540 ;	-----------------------------------------
                           1541 ;	 function errorOccurred
                           1542 ;	-----------------------------------------
   07CB                    1543 _errorOccurred:
                    026F   1544 	C$wireless_serial.c$205$1$1 ==.
                           1545 ;	apps/commander/wireless_serial.c:205: lastErrorTime = (uint8)getMs();
   07CB 12 23 A5           1546 	lcall	_getMs
   07CE AC 82              1547 	mov	r4,dpl
   07D0 78 3E              1548 	mov	r0,#_lastErrorTime
   07D2 EC                 1549 	mov	a,r4
   07D3 F2                 1550 	movx	@r0,a
                    0278   1551 	C$wireless_serial.c$206$1$1 ==.
                           1552 ;	apps/commander/wireless_serial.c:206: errorOccurredRecently = 1;
   07D4 D2 02              1553 	setb	_errorOccurredRecently
                    027A   1554 	C$wireless_serial.c$207$1$1 ==.
                    027A   1555 	XG$errorOccurred$0$0 ==.
   07D6 22                 1556 	ret
                           1557 ;------------------------------------------------------------
                           1558 ;Allocation info for local variables in function 'errorService'
                           1559 ;------------------------------------------------------------
                           1560 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1561 ;------------------------------------------------------------
                    027B   1562 	G$errorService$0$0 ==.
                    027B   1563 	C$wireless_serial.c$209$1$1 ==.
                           1564 ;	apps/commander/wireless_serial.c:209: void errorService()
                           1565 ;	-----------------------------------------
                           1566 ;	 function errorService
                           1567 ;	-----------------------------------------
   07D7                    1568 _errorService:
                    027B   1569 	C$wireless_serial.c$213$1$1 ==.
                           1570 ;	apps/commander/wireless_serial.c:213: if (uart1RxBufferFullOccurred)
                    027B   1571 	C$wireless_serial.c$215$2$2 ==.
                           1572 ;	apps/commander/wireless_serial.c:215: uart1RxBufferFullOccurred = 0;
   07D7 10 07 02           1573 	jbc	_uart1RxBufferFullOccurred,00129$
   07DA 80 03              1574 	sjmp	00102$
   07DC                    1575 00129$:
                    0280   1576 	C$wireless_serial.c$216$2$2 ==.
                           1577 ;	apps/commander/wireless_serial.c:216: errorOccurred();
   07DC 12 07 CB           1578 	lcall	_errorOccurred
   07DF                    1579 00102$:
                    0283   1580 	C$wireless_serial.c$219$1$1 ==.
                           1581 ;	apps/commander/wireless_serial.c:219: if (uart1RxFramingErrorOccurred)
                    0283   1582 	C$wireless_serial.c$221$2$3 ==.
                           1583 ;	apps/commander/wireless_serial.c:221: uart1RxFramingErrorOccurred = 0;
   07DF 10 06 02           1584 	jbc	_uart1RxFramingErrorOccurred,00130$
   07E2 80 41              1585 	sjmp	00106$
   07E4                    1586 00130$:
                    0288   1587 	C$wireless_serial.c$224$2$3 ==.
                           1588 ;	apps/commander/wireless_serial.c:224: framingErrorActive = 1;
   07E4 D2 01              1589 	setb	_framingErrorActive
                    028A   1590 	C$wireless_serial.c$225$2$3 ==.
                           1591 ;	apps/commander/wireless_serial.c:225: errorOccurred();
   07E6 12 07 CB           1592 	lcall	_errorOccurred
                    028D   1593 	C$wireless_serial.c$227$2$3 ==.
                           1594 ;	apps/commander/wireless_serial.c:227: if (param_framing_error_ms > 0)
   07E9 90 2C 2B           1595 	mov	dptr,#_param_framing_error_ms
   07EC E4                 1596 	clr	a
   07ED 93                 1597 	movc	a,@a+dptr
   07EE FC                 1598 	mov	r4,a
   07EF 74 01              1599 	mov	a,#0x01
   07F1 93                 1600 	movc	a,@a+dptr
   07F2 FD                 1601 	mov	r5,a
   07F3 74 02              1602 	mov	a,#0x02
   07F5 93                 1603 	movc	a,@a+dptr
   07F6 FE                 1604 	mov	r6,a
   07F7 74 03              1605 	mov	a,#0x03
   07F9 93                 1606 	movc	a,@a+dptr
   07FA FF                 1607 	mov	r7,a
   07FB C3                 1608 	clr	c
   07FC E4                 1609 	clr	a
   07FD 9C                 1610 	subb	a,r4
   07FE E4                 1611 	clr	a
   07FF 9D                 1612 	subb	a,r5
   0800 E4                 1613 	clr	a
   0801 9E                 1614 	subb	a,r6
   0802 E4                 1615 	clr	a
   0803 64 80              1616 	xrl	a,#0x80
   0805 8F F0              1617 	mov	b,r7
   0807 63 F0 80           1618 	xrl	b,#0x80
   080A 95 F0              1619 	subb	a,b
   080C 50 17              1620 	jnc	00106$
                    02B2   1621 	C$wireless_serial.c$230$3$4 ==.
                           1622 ;	apps/commander/wireless_serial.c:230: U1CSR &= ~0x40; // U1CSR.RE = 0. Disables reception of bytes on the UART.
   080E AF F8              1623 	mov	r7,_U1CSR
   0810 53 07 BF           1624 	anl	ar7,#0xBF
   0813 8F F8              1625 	mov	_U1CSR,r7
                    02B9   1626 	C$wireless_serial.c$231$3$4 ==.
                           1627 ;	apps/commander/wireless_serial.c:231: uartRxDisabled = 1;
   0815 D2 00              1628 	setb	_uartRxDisabled
                    02BB   1629 	C$wireless_serial.c$232$3$4 ==.
                           1630 ;	apps/commander/wireless_serial.c:232: lastRxLowTime = (uint8)getMs(); // Initialize lastRxLowTime even if the line isn't low right now.
   0817 12 23 A5           1631 	lcall	_getMs
   081A AC 82              1632 	mov	r4,dpl
   081C AD 83              1633 	mov	r5,dph
   081E AE F0              1634 	mov	r6,b
   0820 FF                 1635 	mov	r7,a
   0821 78 44              1636 	mov	r0,#_errorService_lastRxLowTime_1_1
   0823 EC                 1637 	mov	a,r4
   0824 F2                 1638 	movx	@r0,a
   0825                    1639 00106$:
                    02C9   1640 	C$wireless_serial.c$236$1$1 ==.
                           1641 ;	apps/commander/wireless_serial.c:236: if (framingErrorActive)
   0825 30 01 0F           1642 	jnb	_framingErrorActive,00111$
                    02CC   1643 	C$wireless_serial.c$238$2$5 ==.
                           1644 ;	apps/commander/wireless_serial.c:238: if (!isPinHigh(17))
   0828 75 82 11           1645 	mov	dpl,#0x11
   082B 12 27 1C           1646 	lcall	_isPinHigh
   082E 40 05              1647 	jc	00108$
                    02D4   1648 	C$wireless_serial.c$240$3$6 ==.
                           1649 ;	apps/commander/wireless_serial.c:240: errorOccurred();
   0830 12 07 CB           1650 	lcall	_errorOccurred
   0833 80 02              1651 	sjmp	00111$
   0835                    1652 00108$:
                    02D9   1653 	C$wireless_serial.c$244$3$7 ==.
                           1654 ;	apps/commander/wireless_serial.c:244: framingErrorActive = 0;
   0835 C2 01              1655 	clr	_framingErrorActive
   0837                    1656 00111$:
                    02DB   1657 	C$wireless_serial.c$248$1$1 ==.
                           1658 ;	apps/commander/wireless_serial.c:248: if (uartRxDisabled)
   0837 30 00 60           1659 	jnb	_uartRxDisabled,00119$
                    02DE   1660 	C$wireless_serial.c$250$2$8 ==.
                           1661 ;	apps/commander/wireless_serial.c:250: if (!isPinHigh(17))
   083A 75 82 11           1662 	mov	dpl,#0x11
   083D 12 27 1C           1663 	lcall	_isPinHigh
   0840 40 10              1664 	jc	00115$
                    02E6   1665 	C$wireless_serial.c$253$3$9 ==.
                           1666 ;	apps/commander/wireless_serial.c:253: lastRxLowTime = (uint8)getMs();
   0842 12 23 A5           1667 	lcall	_getMs
   0845 AC 82              1668 	mov	r4,dpl
   0847 AD 83              1669 	mov	r5,dph
   0849 AE F0              1670 	mov	r6,b
   084B FF                 1671 	mov	r7,a
   084C 78 44              1672 	mov	r0,#_errorService_lastRxLowTime_1_1
   084E EC                 1673 	mov	a,r4
   084F F2                 1674 	movx	@r0,a
   0850 80 48              1675 	sjmp	00119$
   0852                    1676 00115$:
                    02F6   1677 	C$wireless_serial.c$255$2$8 ==.
                           1678 ;	apps/commander/wireless_serial.c:255: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   0852 12 23 A5           1679 	lcall	_getMs
   0855 AC 82              1680 	mov	r4,dpl
   0857 AD 83              1681 	mov	r5,dph
   0859 78 44              1682 	mov	r0,#_errorService_lastRxLowTime_1_1
   085B D3                 1683 	setb	c
   085C E2                 1684 	movx	a,@r0
   085D 9C                 1685 	subb	a,r4
   085E F4                 1686 	cpl	a
   085F FC                 1687 	mov	r4,a
   0860 90 2C 2B           1688 	mov	dptr,#_param_framing_error_ms
   0863 E4                 1689 	clr	a
   0864 93                 1690 	movc	a,@a+dptr
   0865 F5 0A              1691 	mov	_errorService_sloc0_1_0,a
   0867 74 01              1692 	mov	a,#0x01
   0869 93                 1693 	movc	a,@a+dptr
   086A F5 0B              1694 	mov	(_errorService_sloc0_1_0 + 1),a
   086C 74 02              1695 	mov	a,#0x02
   086E 93                 1696 	movc	a,@a+dptr
   086F F5 0C              1697 	mov	(_errorService_sloc0_1_0 + 2),a
   0871 74 03              1698 	mov	a,#0x03
   0873 93                 1699 	movc	a,@a+dptr
   0874 F5 0D              1700 	mov	(_errorService_sloc0_1_0 + 3),a
   0876 8C 02              1701 	mov	ar2,r4
   0878 7C 00              1702 	mov	r4,#0x00
   087A 7E 00              1703 	mov	r6,#0x00
   087C 7F 00              1704 	mov	r7,#0x00
   087E C3                 1705 	clr	c
   087F E5 0A              1706 	mov	a,_errorService_sloc0_1_0
   0881 9A                 1707 	subb	a,r2
   0882 E5 0B              1708 	mov	a,(_errorService_sloc0_1_0 + 1)
   0884 9C                 1709 	subb	a,r4
   0885 E5 0C              1710 	mov	a,(_errorService_sloc0_1_0 + 2)
   0887 9E                 1711 	subb	a,r6
   0888 E5 0D              1712 	mov	a,(_errorService_sloc0_1_0 + 3)
   088A 64 80              1713 	xrl	a,#0x80
   088C 8F F0              1714 	mov	b,r7
   088E 63 F0 80           1715 	xrl	b,#0x80
   0891 95 F0              1716 	subb	a,b
   0893 50 05              1717 	jnc	00119$
                    0339   1718 	C$wireless_serial.c$258$3$10 ==.
                           1719 ;	apps/commander/wireless_serial.c:258: U1CSR |= 0x40;
   0895 43 F8 40           1720 	orl	_U1CSR,#0x40
                    033C   1721 	C$wireless_serial.c$259$3$10 ==.
                           1722 ;	apps/commander/wireless_serial.c:259: uartRxDisabled = 0;
   0898 C2 00              1723 	clr	_uartRxDisabled
   089A                    1724 00119$:
                    033E   1725 	C$wireless_serial.c$262$1$1 ==.
                    033E   1726 	XG$errorService$0$0 ==.
   089A 22                 1727 	ret
                           1728 ;------------------------------------------------------------
                           1729 ;Allocation info for local variables in function 'updateSerialMode'
                           1730 ;------------------------------------------------------------
                    033F   1731 	G$updateSerialMode$0$0 ==.
                    033F   1732 	C$wireless_serial.c$264$1$1 ==.
                           1733 ;	apps/commander/wireless_serial.c:264: void updateSerialMode()
                           1734 ;	-----------------------------------------
                           1735 ;	 function updateSerialMode
                           1736 ;	-----------------------------------------
   089B                    1737 _updateSerialMode:
                    033F   1738 	C$wireless_serial.c$266$1$1 ==.
                           1739 ;	apps/commander/wireless_serial.c:266: if ((uint8)param_serial_mode > 0 && (uint8)param_serial_mode <= 3)
   089B 90 2B FF           1740 	mov	dptr,#_param_serial_mode
   089E E4                 1741 	clr	a
   089F 93                 1742 	movc	a,@a+dptr
   08A0 FC                 1743 	mov	r4,a
   08A1 74 01              1744 	mov	a,#0x01
   08A3 93                 1745 	movc	a,@a+dptr
   08A4 FD                 1746 	mov	r5,a
   08A5 74 02              1747 	mov	a,#0x02
   08A7 93                 1748 	movc	a,@a+dptr
   08A8 FE                 1749 	mov	r6,a
   08A9 74 03              1750 	mov	a,#0x03
   08AB 93                 1751 	movc	a,@a+dptr
   08AC FF                 1752 	mov	r7,a
   08AD EC                 1753 	mov	a,r4
   08AE 60 09              1754 	jz	00102$
   08B0 EC                 1755 	mov	a,r4
   08B1 24 FC              1756 	add	a,#0xff - 0x03
   08B3 40 04              1757 	jc	00102$
                    0359   1758 	C$wireless_serial.c$268$2$2 ==.
                           1759 ;	apps/commander/wireless_serial.c:268: currentSerialMode = (uint8)param_serial_mode;
   08B5 8C 08              1760 	mov	_currentSerialMode,r4
                    035B   1761 	C$wireless_serial.c$269$2$2 ==.
                           1762 ;	apps/commander/wireless_serial.c:269: return;
   08B7 80 17              1763 	sjmp	00110$
   08B9                    1764 00102$:
                    035D   1765 	C$wireless_serial.c$272$1$1 ==.
                           1766 ;	apps/commander/wireless_serial.c:272: if (usbPowerPresent())
   08B9 12 21 05           1767 	lcall	_usbPowerPresent
   08BC 50 0F              1768 	jnc	00108$
                    0362   1769 	C$wireless_serial.c$274$2$3 ==.
                           1770 ;	apps/commander/wireless_serial.c:274: if (vinPowerPresent())
   08BE 12 21 0B           1771 	lcall	_vinPowerPresent
   08C1 50 05              1772 	jnc	00105$
                    0367   1773 	C$wireless_serial.c$276$3$4 ==.
                           1774 ;	apps/commander/wireless_serial.c:276: currentSerialMode = SERIAL_MODE_USB_UART;
   08C3 75 08 03           1775 	mov	_currentSerialMode,#0x03
   08C6 80 08              1776 	sjmp	00110$
   08C8                    1777 00105$:
                    036C   1778 	C$wireless_serial.c$280$3$5 ==.
                           1779 ;	apps/commander/wireless_serial.c:280: currentSerialMode = SERIAL_MODE_USB_RADIO;
   08C8 75 08 01           1780 	mov	_currentSerialMode,#0x01
   08CB 80 03              1781 	sjmp	00110$
   08CD                    1782 00108$:
                    0371   1783 	C$wireless_serial.c$285$2$6 ==.
                           1784 ;	apps/commander/wireless_serial.c:285: currentSerialMode = SERIAL_MODE_UART_RADIO;
   08CD 75 08 02           1785 	mov	_currentSerialMode,#0x02
   08D0                    1786 00110$:
                    0374   1787 	C$wireless_serial.c$287$1$1 ==.
                    0374   1788 	XG$updateSerialMode$0$0 ==.
   08D0 22                 1789 	ret
                           1790 ;------------------------------------------------------------
                           1791 ;Allocation info for local variables in function 'usbToRadioService'
                           1792 ;------------------------------------------------------------
                    0375   1793 	G$usbToRadioService$0$0 ==.
                    0375   1794 	C$wireless_serial.c$289$1$1 ==.
                           1795 ;	apps/commander/wireless_serial.c:289: void usbToRadioService()
                           1796 ;	-----------------------------------------
                           1797 ;	 function usbToRadioService
                           1798 ;	-----------------------------------------
   08D1                    1799 _usbToRadioService:
                    0375   1800 	C$wireless_serial.c$294$1$1 ==.
                           1801 ;	apps/commander/wireless_serial.c:294: while(usbComRxAvailable() && radioComTxAvailable())
   08D1                    1802 00102$:
   08D1 12 15 B1           1803 	lcall	_usbComRxAvailable
   08D4 E5 82              1804 	mov	a,dpl
   08D6 60 0F              1805 	jz	00106$
   08D8 12 1F E2           1806 	lcall	_radioComTxAvailable
   08DB E5 82              1807 	mov	a,dpl
   08DD 60 08              1808 	jz	00106$
                    0383   1809 	C$wireless_serial.c$296$2$2 ==.
                           1810 ;	apps/commander/wireless_serial.c:296: radioComTxSendByte(usbComRxReceiveByte());
   08DF 12 15 DB           1811 	lcall	_usbComRxReceiveByte
   08E2 12 1F F9           1812 	lcall	_radioComTxSendByte
                    0389   1813 	C$wireless_serial.c$299$1$1 ==.
                           1814 ;	apps/commander/wireless_serial.c:299: while(radioComRxAvailable() && usbComTxAvailable())
   08E5 80 EA              1815 	sjmp	00102$
   08E7                    1816 00106$:
   08E7 12 1F 53           1817 	lcall	_radioComRxAvailable
   08EA E5 82              1818 	mov	a,dpl
   08EC 60 0F              1819 	jz	00108$
   08EE 12 16 E7           1820 	lcall	_usbComTxAvailable
   08F1 E5 82              1821 	mov	a,dpl
   08F3 60 08              1822 	jz	00108$
                    0399   1823 	C$wireless_serial.c$302$2$3 ==.
                           1824 ;	apps/commander/wireless_serial.c:302: usbComTxSendByte(CmdrReadMsgs());
   08F5 12 09 B6           1825 	lcall	_CmdrReadMsgs
   08F8 12 17 79           1826 	lcall	_usbComTxSendByte
   08FB 80 EA              1827 	sjmp	00106$
   08FD                    1828 00108$:
                    03A1   1829 	C$wireless_serial.c$307$1$1 ==.
                           1830 ;	apps/commander/wireless_serial.c:307: radioComTxControlSignals(usbComRxControlSignals() & 3);
   08FD 12 17 8A           1831 	lcall	_usbComRxControlSignals
   0900 E5 82              1832 	mov	a,dpl
   0902 54 03              1833 	anl	a,#0x03
   0904 F5 82              1834 	mov	dpl,a
   0906 12 20 2D           1835 	lcall	_radioComTxControlSignals
                    03AD   1836 	C$wireless_serial.c$310$1$1 ==.
                           1837 ;	apps/commander/wireless_serial.c:310: signals = radioComRxControlSignals();
   0909 12 1F 77           1838 	lcall	_radioComRxControlSignals
                    03B0   1839 	C$wireless_serial.c$311$1$1 ==.
                           1840 ;	apps/commander/wireless_serial.c:311: usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
   090C E5 82              1841 	mov	a,dpl
   090E FF                 1842 	mov	r7,a
   090F 30 E0 04           1843 	jnb	acc.0,00111$
   0912 7E 02              1844 	mov	r6,#0x02
   0914 80 02              1845 	sjmp	00112$
   0916                    1846 00111$:
   0916 7E 00              1847 	mov	r6,#0x00
   0918                    1848 00112$:
   0918 EF                 1849 	mov	a,r7
   0919 30 E1 04           1850 	jnb	acc.1,00113$
   091C 7F 01              1851 	mov	r7,#0x01
   091E 80 02              1852 	sjmp	00114$
   0920                    1853 00113$:
   0920 7F 00              1854 	mov	r7,#0x00
   0922                    1855 00114$:
   0922 EF                 1856 	mov	a,r7
   0923 4E                 1857 	orl	a,r6
   0924 F5 82              1858 	mov	dpl,a
   0926 12 17 90           1859 	lcall	_usbComTxControlSignals
                    03CD   1860 	C$wireless_serial.c$312$1$1 ==.
                    03CD   1861 	XG$usbToRadioService$0$0 ==.
   0929 22                 1862 	ret
                           1863 ;------------------------------------------------------------
                           1864 ;Allocation info for local variables in function 'usbToUartService'
                           1865 ;------------------------------------------------------------
                    03CE   1866 	G$usbToUartService$0$0 ==.
                    03CE   1867 	C$wireless_serial.c$314$1$1 ==.
                           1868 ;	apps/commander/wireless_serial.c:314: void usbToUartService()
                           1869 ;	-----------------------------------------
                           1870 ;	 function usbToUartService
                           1871 ;	-----------------------------------------
   092A                    1872 _usbToUartService:
                    03CE   1873 	C$wireless_serial.c$319$1$1 ==.
                           1874 ;	apps/commander/wireless_serial.c:319: while(usbComRxAvailable() && uart1TxAvailable())
   092A                    1875 00102$:
   092A 12 15 B1           1876 	lcall	_usbComRxAvailable
   092D E5 82              1877 	mov	a,dpl
   092F 60 0F              1878 	jz	00106$
   0931 12 0E 90           1879 	lcall	_uart1TxAvailable
   0934 E5 82              1880 	mov	a,dpl
   0936 60 08              1881 	jz	00106$
                    03DC   1882 	C$wireless_serial.c$321$2$2 ==.
                           1883 ;	apps/commander/wireless_serial.c:321: uart1TxSendByte(usbComRxReceiveByte());
   0938 12 15 DB           1884 	lcall	_usbComRxReceiveByte
   093B 12 0E CB           1885 	lcall	_uart1TxSendByte
                    03E2   1886 	C$wireless_serial.c$324$1$1 ==.
                           1887 ;	apps/commander/wireless_serial.c:324: while(uart1RxAvailable() && usbComTxAvailable())
   093E 80 EA              1888 	sjmp	00102$
   0940                    1889 00106$:
   0940 12 0E E4           1890 	lcall	_uart1RxAvailable
   0943 E5 82              1891 	mov	a,dpl
   0945 60 0F              1892 	jz	00108$
   0947 12 16 E7           1893 	lcall	_usbComTxAvailable
   094A E5 82              1894 	mov	a,dpl
   094C 60 08              1895 	jz	00108$
                    03F2   1896 	C$wireless_serial.c$326$2$3 ==.
                           1897 ;	apps/commander/wireless_serial.c:326: usbComTxSendByte(uart1RxReceiveByte());
   094E 12 0E EC           1898 	lcall	_uart1RxReceiveByte
   0951 12 17 79           1899 	lcall	_usbComTxSendByte
   0954 80 EA              1900 	sjmp	00106$
   0956                    1901 00108$:
                    03FA   1902 	C$wireless_serial.c$329$1$1 ==.
                           1903 ;	apps/commander/wireless_serial.c:329: ioTxSignals(usbComRxControlSignals());
   0956 12 17 8A           1904 	lcall	_usbComRxControlSignals
   0959 12 06 B2           1905 	lcall	_ioTxSignals
                    0400   1906 	C$wireless_serial.c$332$1$1 ==.
                           1907 ;	apps/commander/wireless_serial.c:332: signals = ioRxSignals();
   095C 12 06 28           1908 	lcall	_ioRxSignals
                    0403   1909 	C$wireless_serial.c$333$1$1 ==.
                           1910 ;	apps/commander/wireless_serial.c:333: usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
   095F E5 82              1911 	mov	a,dpl
   0961 FF                 1912 	mov	r7,a
   0962 30 E0 04           1913 	jnb	acc.0,00111$
   0965 7E 02              1914 	mov	r6,#0x02
   0967 80 02              1915 	sjmp	00112$
   0969                    1916 00111$:
   0969 7E 00              1917 	mov	r6,#0x00
   096B                    1918 00112$:
   096B EF                 1919 	mov	a,r7
   096C 30 E1 04           1920 	jnb	acc.1,00113$
   096F 7F 01              1921 	mov	r7,#0x01
   0971 80 02              1922 	sjmp	00114$
   0973                    1923 00113$:
   0973 7F 00              1924 	mov	r7,#0x00
   0975                    1925 00114$:
   0975 EF                 1926 	mov	a,r7
   0976 4E                 1927 	orl	a,r6
   0977 F5 82              1928 	mov	dpl,a
   0979 12 17 90           1929 	lcall	_usbComTxControlSignals
                    0420   1930 	C$wireless_serial.c$336$1$1 ==.
                    0420   1931 	XG$usbToUartService$0$0 ==.
   097C 22                 1932 	ret
                           1933 ;------------------------------------------------------------
                           1934 ;Allocation info for local variables in function 'uartToRadioService'
                           1935 ;------------------------------------------------------------
                    0421   1936 	G$uartToRadioService$0$0 ==.
                    0421   1937 	C$wireless_serial.c$338$1$1 ==.
                           1938 ;	apps/commander/wireless_serial.c:338: void uartToRadioService()
                           1939 ;	-----------------------------------------
                           1940 ;	 function uartToRadioService
                           1941 ;	-----------------------------------------
   097D                    1942 _uartToRadioService:
                    0421   1943 	C$wireless_serial.c$341$1$1 ==.
                           1944 ;	apps/commander/wireless_serial.c:341: while(uart1RxAvailable() && radioComTxAvailable())
   097D                    1945 00102$:
   097D 12 0E E4           1946 	lcall	_uart1RxAvailable
   0980 E5 82              1947 	mov	a,dpl
   0982 60 0F              1948 	jz	00106$
   0984 12 1F E2           1949 	lcall	_radioComTxAvailable
   0987 E5 82              1950 	mov	a,dpl
   0989 60 08              1951 	jz	00106$
                    042F   1952 	C$wireless_serial.c$343$2$2 ==.
                           1953 ;	apps/commander/wireless_serial.c:343: radioComTxSendByte(uart1RxReceiveByte());
   098B 12 0E EC           1954 	lcall	_uart1RxReceiveByte
   098E 12 1F F9           1955 	lcall	_radioComTxSendByte
                    0435   1956 	C$wireless_serial.c$346$1$1 ==.
                           1957 ;	apps/commander/wireless_serial.c:346: while(radioComRxAvailable() && uart1TxAvailable())
   0991 80 EA              1958 	sjmp	00102$
   0993                    1959 00106$:
   0993 12 1F 53           1960 	lcall	_radioComRxAvailable
   0996 E5 82              1961 	mov	a,dpl
   0998 60 0F              1962 	jz	00108$
   099A 12 0E 90           1963 	lcall	_uart1TxAvailable
   099D E5 82              1964 	mov	a,dpl
   099F 60 08              1965 	jz	00108$
                    0445   1966 	C$wireless_serial.c$348$2$3 ==.
                           1967 ;	apps/commander/wireless_serial.c:348: uart1TxSendByte(radioComRxReceiveByte());
   09A1 12 1F 5A           1968 	lcall	_radioComRxReceiveByte
   09A4 12 0E CB           1969 	lcall	_uart1TxSendByte
   09A7 80 EA              1970 	sjmp	00106$
   09A9                    1971 00108$:
                    044D   1972 	C$wireless_serial.c$352$1$1 ==.
                           1973 ;	apps/commander/wireless_serial.c:352: ioTxSignals(radioComRxControlSignals());
   09A9 12 1F 77           1974 	lcall	_radioComRxControlSignals
   09AC 12 06 B2           1975 	lcall	_ioTxSignals
                    0453   1976 	C$wireless_serial.c$353$1$1 ==.
                           1977 ;	apps/commander/wireless_serial.c:353: radioComTxControlSignals(ioRxSignals());
   09AF 12 06 28           1978 	lcall	_ioRxSignals
   09B2 12 20 2D           1979 	lcall	_radioComTxControlSignals
                    0459   1980 	C$wireless_serial.c$354$1$1 ==.
                    0459   1981 	XG$uartToRadioService$0$0 ==.
   09B5 22                 1982 	ret
                           1983 ;------------------------------------------------------------
                           1984 ;Allocation info for local variables in function 'CmdrReadMsgs'
                           1985 ;------------------------------------------------------------
                    045A   1986 	G$CmdrReadMsgs$0$0 ==.
                    045A   1987 	C$wireless_serial.c$358$1$1 ==.
                           1988 ;	apps/commander/wireless_serial.c:358: int CmdrReadMsgs(){
                           1989 ;	-----------------------------------------
                           1990 ;	 function CmdrReadMsgs
                           1991 ;	-----------------------------------------
   09B6                    1992 _CmdrReadMsgs:
                    045A   1993 	C$wireless_serial.c$360$3$5 ==.
                           1994 ;	apps/commander/wireless_serial.c:360: while(radioComRxAvailable() == zTRUE){
   09B6                    1995 00141$:
   09B6 12 1F 53           1996 	lcall	_radioComRxAvailable
   09B9 AF 82              1997 	mov	r7,dpl
   09BB BF 01 02           1998 	cjne	r7,#0x01,00163$
   09BE 80 03              1999 	sjmp	00164$
   09C0                    2000 00163$:
   09C0 02 0C 5F           2001 	ljmp	00143$
   09C3                    2002 00164$:
                    0467   2003 	C$wireless_serial.c$361$2$2 ==.
                           2004 ;	apps/commander/wireless_serial.c:361: if(index_cmdr == -1){ // looking for new packet
   09C3 78 2B              2005 	mov	r0,#_index_cmdr
   09C5 E2                 2006 	movx	a,@r0
   09C6 B4 FF 07           2007 	cjne	a,#0xFF,00165$
   09C9 08                 2008 	inc	r0
   09CA E2                 2009 	movx	a,@r0
   09CB B4 FF 02           2010 	cjne	a,#0xFF,00165$
   09CE 80 02              2011 	sjmp	00166$
   09D0                    2012 00165$:
   09D0 80 16              2013 	sjmp	00139$
   09D2                    2014 00166$:
                    0476   2015 	C$wireless_serial.c$362$3$3 ==.
                           2016 ;	apps/commander/wireless_serial.c:362: if(uart1RxReceiveByte() == 0xff){ //read until packet start
   09D2 12 0E EC           2017 	lcall	_uart1RxReceiveByte
   09D5 AF 82              2018 	mov	r7,dpl
   09D7 BF FF DC           2019 	cjne	r7,#0xFF,00141$
                    047E   2020 	C$wireless_serial.c$363$4$4 ==.
                           2021 ;	apps/commander/wireless_serial.c:363: index_cmdr = 0;
   09DA 78 2B              2022 	mov	r0,#_index_cmdr
   09DC E4                 2023 	clr	a
   09DD F2                 2024 	movx	@r0,a
   09DE 08                 2025 	inc	r0
   09DF F2                 2026 	movx	@r0,a
                    0484   2027 	C$wireless_serial.c$364$4$4 ==.
                           2028 ;	apps/commander/wireless_serial.c:364: checksum_cmdr = 0;
   09E0 78 2D              2029 	mov	r0,#_checksum_cmdr
   09E2 E4                 2030 	clr	a
   09E3 F2                 2031 	movx	@r0,a
   09E4 08                 2032 	inc	r0
   09E5 F2                 2033 	movx	@r0,a
   09E6 80 CE              2034 	sjmp	00141$
   09E8                    2035 00139$:
                    048C   2036 	C$wireless_serial.c$366$2$2 ==.
                           2037 ;	apps/commander/wireless_serial.c:366: }else if(index_cmdr == 0){
   09E8 78 2B              2038 	mov	r0,#_index_cmdr
   09EA E2                 2039 	movx	a,@r0
   09EB F5 F0              2040 	mov	b,a
   09ED 08                 2041 	inc	r0
   09EE E2                 2042 	movx	a,@r0
   09EF 45 F0              2043 	orl	a,b
   09F1 70 35              2044 	jnz	00136$
                    0497   2045 	C$wireless_serial.c$367$3$5 ==.
                           2046 ;	apps/commander/wireless_serial.c:367: vals[index_cmdr] = (unsigned char) uart1RxReceiveByte();
   09F3 78 2B              2047 	mov	r0,#_index_cmdr
   09F5 E2                 2048 	movx	a,@r0
   09F6 24 24              2049 	add	a,#_vals
   09F8 F9                 2050 	mov	r1,a
   09F9 C0 01              2051 	push	ar1
   09FB 12 0E EC           2052 	lcall	_uart1RxReceiveByte
   09FE E5 82              2053 	mov	a,dpl
   0A00 D0 01              2054 	pop	ar1
   0A02 F3                 2055 	movx	@r1,a
                    04A7   2056 	C$wireless_serial.c$368$3$5 ==.
                           2057 ;	apps/commander/wireless_serial.c:368: if(vals[index_cmdr] != 0xff){
   0A03 78 2B              2058 	mov	r0,#_index_cmdr
   0A05 E2                 2059 	movx	a,@r0
   0A06 24 24              2060 	add	a,#_vals
   0A08 F9                 2061 	mov	r1,a
   0A09 E3                 2062 	movx	a,@r1
   0A0A FF                 2063 	mov	r7,a
   0A0B BF FF 02           2064 	cjne	r7,#0xFF,00170$
   0A0E 80 A6              2065 	sjmp	00141$
   0A10                    2066 00170$:
                    04B4   2067 	C$wireless_serial.c$369$4$6 ==.
                           2068 ;	apps/commander/wireless_serial.c:369: checksum_cmdr += (int) vals[index_cmdr];
   0A10 7E 00              2069 	mov	r6,#0x00
   0A12 78 2D              2070 	mov	r0,#_checksum_cmdr
   0A14 E2                 2071 	movx	a,@r0
   0A15 2F                 2072 	add	a,r7
   0A16 F2                 2073 	movx	@r0,a
   0A17 08                 2074 	inc	r0
   0A18 E2                 2075 	movx	a,@r0
   0A19 3E                 2076 	addc	a,r6
   0A1A F2                 2077 	movx	@r0,a
                    04BF   2078 	C$wireless_serial.c$370$4$6 ==.
                           2079 ;	apps/commander/wireless_serial.c:370: index_cmdr++;
   0A1B 78 2B              2080 	mov	r0,#_index_cmdr
   0A1D E2                 2081 	movx	a,@r0
   0A1E 24 01              2082 	add	a,#0x01
   0A20 F2                 2083 	movx	@r0,a
   0A21 08                 2084 	inc	r0
   0A22 E2                 2085 	movx	a,@r0
   0A23 34 00              2086 	addc	a,#0x00
   0A25 F2                 2087 	movx	@r0,a
   0A26 80 8E              2088 	sjmp	00141$
   0A28                    2089 00136$:
                    04CC   2090 	C$wireless_serial.c$373$3$7 ==.
                           2091 ;	apps/commander/wireless_serial.c:373: vals[index_cmdr] = (unsigned char) uart1RxReceiveByte(); //loops will sequentially read bytes and store them here
   0A28 78 2B              2092 	mov	r0,#_index_cmdr
   0A2A E2                 2093 	movx	a,@r0
   0A2B 24 24              2094 	add	a,#_vals
   0A2D F9                 2095 	mov	r1,a
   0A2E C0 01              2096 	push	ar1
   0A30 12 0E EC           2097 	lcall	_uart1RxReceiveByte
   0A33 E5 82              2098 	mov	a,dpl
   0A35 D0 01              2099 	pop	ar1
   0A37 F3                 2100 	movx	@r1,a
                    04DC   2101 	C$wireless_serial.c$374$3$7 ==.
                           2102 ;	apps/commander/wireless_serial.c:374: checksum_cmdr += (int) vals[index_cmdr];
   0A38 78 2B              2103 	mov	r0,#_index_cmdr
   0A3A E2                 2104 	movx	a,@r0
   0A3B 24 24              2105 	add	a,#_vals
   0A3D F9                 2106 	mov	r1,a
   0A3E E3                 2107 	movx	a,@r1
   0A3F FF                 2108 	mov	r7,a
   0A40 7E 00              2109 	mov	r6,#0x00
   0A42 78 2D              2110 	mov	r0,#_checksum_cmdr
   0A44 E2                 2111 	movx	a,@r0
   0A45 2F                 2112 	add	a,r7
   0A46 F2                 2113 	movx	@r0,a
   0A47 08                 2114 	inc	r0
   0A48 E2                 2115 	movx	a,@r0
   0A49 3E                 2116 	addc	a,r6
   0A4A F2                 2117 	movx	@r0,a
                    04EF   2118 	C$wireless_serial.c$375$3$7 ==.
                           2119 ;	apps/commander/wireless_serial.c:375: index_cmdr++;
   0A4B 78 2B              2120 	mov	r0,#_index_cmdr
   0A4D E2                 2121 	movx	a,@r0
   0A4E 24 01              2122 	add	a,#0x01
   0A50 F2                 2123 	movx	@r0,a
   0A51 08                 2124 	inc	r0
   0A52 E2                 2125 	movx	a,@r0
   0A53 34 00              2126 	addc	a,#0x00
   0A55 F2                 2127 	movx	@r0,a
                    04FA   2128 	C$wireless_serial.c$380$3$7 ==.
                           2129 ;	apps/commander/wireless_serial.c:380: if(index_cmdr == 7){ // packet complete
   0A56 78 2B              2130 	mov	r0,#_index_cmdr
   0A58 E2                 2131 	movx	a,@r0
   0A59 B4 07 04           2132 	cjne	a,#0x07,00171$
   0A5C 08                 2133 	inc	r0
   0A5D E2                 2134 	movx	a,@r0
   0A5E 60 03              2135 	jz	00172$
   0A60                    2136 00171$:
   0A60 02 09 B6           2137 	ljmp	00141$
   0A63                    2138 00172$:
                    0507   2139 	C$wireless_serial.c$381$1$1 ==.
                           2140 ;	apps/commander/wireless_serial.c:381: if(checksum_cmdr%256 != 255){
   0A63 78 77              2141 	mov	r0,#__modsint_PARM_2
   0A65 E4                 2142 	clr	a
   0A66 F2                 2143 	movx	@r0,a
   0A67 08                 2144 	inc	r0
   0A68 74 01              2145 	mov	a,#0x01
   0A6A F2                 2146 	movx	@r0,a
   0A6B 78 2D              2147 	mov	r0,#_checksum_cmdr
   0A6D E2                 2148 	movx	a,@r0
   0A6E F5 82              2149 	mov	dpl,a
   0A70 08                 2150 	inc	r0
   0A71 E2                 2151 	movx	a,@r0
   0A72 F5 83              2152 	mov	dph,a
   0A74 12 22 97           2153 	lcall	__modsint
   0A77 AE 82              2154 	mov	r6,dpl
   0A79 AF 83              2155 	mov	r7,dph
   0A7B BE FF 05           2156 	cjne	r6,#0xFF,00173$
   0A7E BF 00 02           2157 	cjne	r7,#0x00,00173$
   0A81 80 0F              2158 	sjmp	00131$
   0A83                    2159 00173$:
                    0527   2160 	C$wireless_serial.c$384$5$9 ==.
                           2161 ;	apps/commander/wireless_serial.c:384: index_cmdr = -1;
   0A83 78 2B              2162 	mov	r0,#_index_cmdr
   0A85 74 FF              2163 	mov	a,#0xFF
   0A87 F2                 2164 	movx	@r0,a
   0A88 08                 2165 	inc	r0
   0A89 74 FF              2166 	mov	a,#0xFF
   0A8B F2                 2167 	movx	@r0,a
                    0530   2168 	C$wireless_serial.c$385$5$9 ==.
                           2169 ;	apps/commander/wireless_serial.c:385: return 0;
   0A8C 90 00 00           2170 	mov	dptr,#0x0000
   0A8F 02 0C 62           2171 	ljmp	00144$
   0A92                    2172 00131$:
                    0536   2173 	C$wireless_serial.c$387$5$10 ==.
                           2174 ;	apps/commander/wireless_serial.c:387: char buttonval = vals[4];
   0A92 78 28              2175 	mov	r0,#(_vals + 0x0004)
   0A94 E2                 2176 	movx	a,@r0
   0A95 FF                 2177 	mov	r7,a
                    053A   2178 	C$wireless_serial.c$388$5$10 ==.
                           2179 ;	apps/commander/wireless_serial.c:388: short dowalking = zTRUE;
   0A96 7D 01              2180 	mov	r5,#0x01
   0A98 7E 00              2181 	mov	r6,#0x00
                    053E   2182 	C$wireless_serial.c$392$5$10 ==.
                           2183 ;	apps/commander/wireless_serial.c:392: if((buttonval&0x40) > 0){ //if(buttonval & BUT_LT){
   0A9A EF                 2184 	mov	a,r7
   0A9B 30 E6 14           2185 	jnb	acc.6,00109$
                    0542   2186 	C$wireless_serial.c$394$6$11 ==.
                           2187 ;	apps/commander/wireless_serial.c:394: turnleft = zTRUE;
   0A9E 78 0A              2188 	mov	r0,#_turnleft
   0AA0 74 01              2189 	mov	a,#0x01
   0AA2 F2                 2190 	movx	@r0,a
   0AA3 08                 2191 	inc	r0
   0AA4 E4                 2192 	clr	a
   0AA5 F2                 2193 	movx	@r0,a
                    054A   2194 	C$wireless_serial.c$395$6$11 ==.
                           2195 ;	apps/commander/wireless_serial.c:395: turnright = zFALSE;
   0AA6 78 08              2196 	mov	r0,#_turnright
   0AA8 E4                 2197 	clr	a
   0AA9 F2                 2198 	movx	@r0,a
   0AAA 08                 2199 	inc	r0
   0AAB F2                 2200 	movx	@r0,a
                    0550   2201 	C$wireless_serial.c$397$6$11 ==.
                           2202 ;	apps/commander/wireless_serial.c:397: dowalking = zFALSE;
   0AAC 7D 00              2203 	mov	r5,#0x00
   0AAE 7E 00              2204 	mov	r6,#0x00
   0AB0 80 2A              2205 	sjmp	00110$
   0AB2                    2206 00109$:
                    0556   2207 	C$wireless_serial.c$399$5$10 ==.
                           2208 ;	apps/commander/wireless_serial.c:399: else if((buttonval&0x80) > 0){ //if(buttonval & BUT_RT){
   0AB2 EF                 2209 	mov	a,r7
   0AB3 30 E7 14           2210 	jnb	acc.7,00106$
                    055A   2211 	C$wireless_serial.c$401$6$12 ==.
                           2212 ;	apps/commander/wireless_serial.c:401: turnright = zTRUE;
   0AB6 78 08              2213 	mov	r0,#_turnright
   0AB8 74 01              2214 	mov	a,#0x01
   0ABA F2                 2215 	movx	@r0,a
   0ABB 08                 2216 	inc	r0
   0ABC E4                 2217 	clr	a
   0ABD F2                 2218 	movx	@r0,a
                    0562   2219 	C$wireless_serial.c$402$6$12 ==.
                           2220 ;	apps/commander/wireless_serial.c:402: turnleft = zFALSE;
   0ABE 78 0A              2221 	mov	r0,#_turnleft
   0AC0 E4                 2222 	clr	a
   0AC1 F2                 2223 	movx	@r0,a
   0AC2 08                 2224 	inc	r0
   0AC3 F2                 2225 	movx	@r0,a
                    0568   2226 	C$wireless_serial.c$404$6$12 ==.
                           2227 ;	apps/commander/wireless_serial.c:404: dowalking = zFALSE;
   0AC4 7D 00              2228 	mov	r5,#0x00
   0AC6 7E 00              2229 	mov	r6,#0x00
   0AC8 80 12              2230 	sjmp	00110$
   0ACA                    2231 00106$:
                    056E   2232 	C$wireless_serial.c$407$6$13 ==.
                           2233 ;	apps/commander/wireless_serial.c:407: turnright = zFALSE;
   0ACA 78 08              2234 	mov	r0,#_turnright
   0ACC E4                 2235 	clr	a
   0ACD F2                 2236 	movx	@r0,a
   0ACE 08                 2237 	inc	r0
   0ACF F2                 2238 	movx	@r0,a
                    0574   2239 	C$wireless_serial.c$408$6$13 ==.
                           2240 ;	apps/commander/wireless_serial.c:408: turnleft = zFALSE;
   0AD0 78 0A              2241 	mov	r0,#_turnleft
   0AD2 E4                 2242 	clr	a
   0AD3 F2                 2243 	movx	@r0,a
   0AD4 08                 2244 	inc	r0
   0AD5 F2                 2245 	movx	@r0,a
                    057A   2246 	C$wireless_serial.c$409$6$13 ==.
                           2247 ;	apps/commander/wireless_serial.c:409: turn = zFALSE;
   0AD6 78 16              2248 	mov	r0,#_turn
   0AD8 E4                 2249 	clr	a
   0AD9 F2                 2250 	movx	@r0,a
   0ADA 08                 2251 	inc	r0
   0ADB F2                 2252 	movx	@r0,a
   0ADC                    2253 00110$:
                    0580   2254 	C$wireless_serial.c$411$5$10 ==.
                           2255 ;	apps/commander/wireless_serial.c:411: if((buttonval&BUT_L6) > 0){
   0ADC EF                 2256 	mov	a,r7
   0ADD 30 E5 0A           2257 	jnb	acc.5,00112$
                    0584   2258 	C$wireless_serial.c$412$6$14 ==.
                           2259 ;	apps/commander/wireless_serial.c:412: gunbutton = zTRUE;
   0AE0 78 0C              2260 	mov	r0,#_gunbutton
   0AE2 74 01              2261 	mov	a,#0x01
   0AE4 F2                 2262 	movx	@r0,a
   0AE5 08                 2263 	inc	r0
   0AE6 E4                 2264 	clr	a
   0AE7 F2                 2265 	movx	@r0,a
   0AE8 80 06              2266 	sjmp	00113$
   0AEA                    2267 00112$:
                    058E   2268 	C$wireless_serial.c$415$6$15 ==.
                           2269 ;	apps/commander/wireless_serial.c:415: else{gunbutton = zFALSE;}
   0AEA 78 0C              2270 	mov	r0,#_gunbutton
   0AEC E4                 2271 	clr	a
   0AED F2                 2272 	movx	@r0,a
   0AEE 08                 2273 	inc	r0
   0AEF F2                 2274 	movx	@r0,a
   0AF0                    2275 00113$:
                    0594   2276 	C$wireless_serial.c$417$5$10 ==.
                           2277 ;	apps/commander/wireless_serial.c:417: if((buttonval&BUT_R3) > 0){
   0AF0 EF                 2278 	mov	a,r7
   0AF1 30 E2 0A           2279 	jnb	acc.2,00115$
                    0598   2280 	C$wireless_serial.c$418$6$16 ==.
                           2281 ;	apps/commander/wireless_serial.c:418: panicbutton = zTRUE;
   0AF4 78 0E              2282 	mov	r0,#_panicbutton
   0AF6 74 01              2283 	mov	a,#0x01
   0AF8 F2                 2284 	movx	@r0,a
   0AF9 08                 2285 	inc	r0
   0AFA E4                 2286 	clr	a
   0AFB F2                 2287 	movx	@r0,a
   0AFC 80 06              2288 	sjmp	00116$
   0AFE                    2289 00115$:
                    05A2   2290 	C$wireless_serial.c$421$6$17 ==.
                           2291 ;	apps/commander/wireless_serial.c:421: else{panicbutton = zFALSE;}
   0AFE 78 0E              2292 	mov	r0,#_panicbutton
   0B00 E4                 2293 	clr	a
   0B01 F2                 2294 	movx	@r0,a
   0B02 08                 2295 	inc	r0
   0B03 F2                 2296 	movx	@r0,a
   0B04                    2297 00116$:
                    05A8   2298 	C$wireless_serial.c$423$5$10 ==.
                           2299 ;	apps/commander/wireless_serial.c:423: if((buttonval&BUT_L4) > 0){
   0B04 EF                 2300 	mov	a,r7
   0B05 30 E3 0A           2301 	jnb	acc.3,00118$
                    05AC   2302 	C$wireless_serial.c$424$6$18 ==.
                           2303 ;	apps/commander/wireless_serial.c:424: infobutton = zTRUE;
   0B08 78 10              2304 	mov	r0,#_infobutton
   0B0A 74 01              2305 	mov	a,#0x01
   0B0C F2                 2306 	movx	@r0,a
   0B0D 08                 2307 	inc	r0
   0B0E E4                 2308 	clr	a
   0B0F F2                 2309 	movx	@r0,a
   0B10 80 06              2310 	sjmp	00119$
   0B12                    2311 00118$:
                    05B6   2312 	C$wireless_serial.c$427$6$19 ==.
                           2313 ;	apps/commander/wireless_serial.c:427: else{infobutton = zFALSE;}
   0B12 78 10              2314 	mov	r0,#_infobutton
   0B14 E4                 2315 	clr	a
   0B15 F2                 2316 	movx	@r0,a
   0B16 08                 2317 	inc	r0
   0B17 F2                 2318 	movx	@r0,a
   0B18                    2319 00119$:
                    05BC   2320 	C$wireless_serial.c$429$5$10 ==.
                           2321 ;	apps/commander/wireless_serial.c:429: if((buttonval&BUT_R2) > 0){
   0B18 EF                 2322 	mov	a,r7
   0B19 30 E1 12           2323 	jnb	acc.1,00121$
                    05C0   2324 	C$wireless_serial.c$430$6$20 ==.
                           2325 ;	apps/commander/wireless_serial.c:430: pan_pos = PAN_CENTER;
   0B1C 78 06              2326 	mov	r0,#_pan_pos
   0B1E 74 98              2327 	mov	a,#0x98
   0B20 F2                 2328 	movx	@r0,a
   0B21 08                 2329 	inc	r0
   0B22 74 02              2330 	mov	a,#0x02
   0B24 F2                 2331 	movx	@r0,a
                    05C9   2332 	C$wireless_serial.c$431$6$20 ==.
                           2333 ;	apps/commander/wireless_serial.c:431: tilt_pos = TILT_CENTER;
   0B25 78 04              2334 	mov	r0,#_tilt_pos
   0B27 74 5E              2335 	mov	a,#0x5E
   0B29 F2                 2336 	movx	@r0,a
   0B2A 08                 2337 	inc	r0
   0B2B 74 02              2338 	mov	a,#0x02
   0B2D F2                 2339 	movx	@r0,a
   0B2E                    2340 00121$:
                    05D2   2341 	C$wireless_serial.c$436$5$10 ==.
                           2342 ;	apps/commander/wireless_serial.c:436: if((buttonval&BUT_R1) > 0){
   0B2E EF                 2343 	mov	a,r7
   0B2F 30 E0 0A           2344 	jnb	acc.0,00123$
                    05D6   2345 	C$wireless_serial.c$437$6$21 ==.
                           2346 ;	apps/commander/wireless_serial.c:437: agitbutton = zTRUE;
   0B32 78 12              2347 	mov	r0,#_agitbutton
   0B34 74 01              2348 	mov	a,#0x01
   0B36 F2                 2349 	movx	@r0,a
   0B37 08                 2350 	inc	r0
   0B38 E4                 2351 	clr	a
   0B39 F2                 2352 	movx	@r0,a
   0B3A 80 06              2353 	sjmp	00124$
   0B3C                    2354 00123$:
                    05E0   2355 	C$wireless_serial.c$440$6$22 ==.
                           2356 ;	apps/commander/wireless_serial.c:440: else{agitbutton = zFALSE;}
   0B3C 78 12              2357 	mov	r0,#_agitbutton
   0B3E E4                 2358 	clr	a
   0B3F F2                 2359 	movx	@r0,a
   0B40 08                 2360 	inc	r0
   0B41 F2                 2361 	movx	@r0,a
   0B42                    2362 00124$:
                    05E6   2363 	C$wireless_serial.c$442$5$10 ==.
                           2364 ;	apps/commander/wireless_serial.c:442: if((southpaw&0x01) > 0){ // SouthPaw
   0B42 78 2F              2365 	mov	r0,#_southpaw
   0B44 E2                 2366 	movx	a,@r0
   0B45 54 01              2367 	anl	a,#0x01
   0B47 60 23              2368 	jz	00128$
                    05ED   2369 	C$wireless_serial.c$443$6$23 ==.
                           2370 ;	apps/commander/wireless_serial.c:443: walkV = (signed char)( (int)vals[0]-128 );
   0B49 78 24              2371 	mov	r0,#_vals
   0B4B E2                 2372 	movx	a,@r0
   0B4C 24 80              2373 	add	a,#0x80
   0B4E FF                 2374 	mov	r7,a
   0B4F 78 30              2375 	mov	r0,#_walkV
   0B51 F2                 2376 	movx	@r0,a
   0B52 EF                 2377 	mov	a,r7
   0B53 33                 2378 	rlc	a
   0B54 95 E0              2379 	subb	a,acc
   0B56 08                 2380 	inc	r0
   0B57 F2                 2381 	movx	@r0,a
                    05FC   2382 	C$wireless_serial.c$444$6$23 ==.
                           2383 ;	apps/commander/wireless_serial.c:444: walkH = (signed char)( (int)vals[1]-128 );
   0B58 78 25              2384 	mov	r0,#(_vals + 0x0001)
   0B5A E2                 2385 	movx	a,@r0
   0B5B 7C 00              2386 	mov	r4,#0x00
   0B5D 24 80              2387 	add	a,#0x80
   0B5F FF                 2388 	mov	r7,a
   0B60 78 32              2389 	mov	r0,#_walkH
   0B62 F2                 2390 	movx	@r0,a
   0B63 EF                 2391 	mov	a,r7
   0B64 33                 2392 	rlc	a
   0B65 95 E0              2393 	subb	a,acc
   0B67 08                 2394 	inc	r0
   0B68 F2                 2395 	movx	@r0,a
   0B69 02 0C 51           2396 	ljmp	00132$
   0B6C                    2397 00128$:
                    0610   2398 	C$wireless_serial.c$447$5$10 ==.
                           2399 ;	apps/commander/wireless_serial.c:447: }else if (dowalking){
   0B6C ED                 2400 	mov	a,r5
   0B6D 4E                 2401 	orl	a,r6
   0B6E 70 03              2402 	jnz	00182$
   0B70 02 0C 51           2403 	ljmp	00132$
   0B73                    2404 00182$:
                    0617   2405 	C$wireless_serial.c$449$6$24 ==.
                           2406 ;	apps/commander/wireless_serial.c:449: lookV = (signed char)( (int)vals[0]-128 );
   0B73 78 24              2407 	mov	r0,#_vals
   0B75 E2                 2408 	movx	a,@r0
   0B76 24 80              2409 	add	a,#0x80
   0B78 FF                 2410 	mov	r7,a
   0B79 33                 2411 	rlc	a
   0B7A 95 E0              2412 	subb	a,acc
   0B7C FE                 2413 	mov	r6,a
   0B7D 78 34              2414 	mov	r0,#_lookV
   0B7F EF                 2415 	mov	a,r7
   0B80 F2                 2416 	movx	@r0,a
   0B81 08                 2417 	inc	r0
   0B82 EE                 2418 	mov	a,r6
   0B83 F2                 2419 	movx	@r0,a
                    0628   2420 	C$wireless_serial.c$450$6$24 ==.
                           2421 ;	apps/commander/wireless_serial.c:450: lookH = (signed char)( (int)vals[1]-128 );
   0B84 78 25              2422 	mov	r0,#(_vals + 0x0001)
   0B86 E2                 2423 	movx	a,@r0
   0B87 24 80              2424 	add	a,#0x80
   0B89 FD                 2425 	mov	r5,a
   0B8A 33                 2426 	rlc	a
   0B8B 95 E0              2427 	subb	a,acc
   0B8D FC                 2428 	mov	r4,a
   0B8E 78 36              2429 	mov	r0,#_lookH
   0B90 ED                 2430 	mov	a,r5
   0B91 F2                 2431 	movx	@r0,a
   0B92 08                 2432 	inc	r0
   0B93 EC                 2433 	mov	a,r4
   0B94 F2                 2434 	movx	@r0,a
                    0639   2435 	C$wireless_serial.c$460$1$1 ==.
                           2436 ;	apps/commander/wireless_serial.c:460: pan_add = (-(float)lookH)/17;
   0B95 8D 82              2437 	mov	dpl,r5
   0B97 8C 83              2438 	mov	dph,r4
   0B99 C0 07              2439 	push	ar7
   0B9B C0 06              2440 	push	ar6
   0B9D 12 28 BB           2441 	lcall	___sint2fs
   0BA0 AA 82              2442 	mov	r2,dpl
   0BA2 AB 83              2443 	mov	r3,dph
   0BA4 AC F0              2444 	mov	r4,b
   0BA6 B2 E7              2445 	cpl	acc.7
   0BA8 FD                 2446 	mov	r5,a
   0BA9 E4                 2447 	clr	a
   0BAA C0 E0              2448 	push	acc
   0BAC C0 E0              2449 	push	acc
   0BAE 74 88              2450 	mov	a,#0x88
   0BB0 C0 E0              2451 	push	acc
   0BB2 74 41              2452 	mov	a,#0x41
   0BB4 C0 E0              2453 	push	acc
   0BB6 8A 82              2454 	mov	dpl,r2
   0BB8 8B 83              2455 	mov	dph,r3
   0BBA 8C F0              2456 	mov	b,r4
   0BBC ED                 2457 	mov	a,r5
   0BBD 12 29 8A           2458 	lcall	___fsdiv
   0BC0 AA 82              2459 	mov	r2,dpl
   0BC2 AB 83              2460 	mov	r3,dph
   0BC4 AC F0              2461 	mov	r4,b
   0BC6 FD                 2462 	mov	r5,a
   0BC7 E5 81              2463 	mov	a,sp
   0BC9 24 FC              2464 	add	a,#0xfc
   0BCB F5 81              2465 	mov	sp,a
   0BCD 8A 82              2466 	mov	dpl,r2
   0BCF 8B 83              2467 	mov	dph,r3
   0BD1 8C F0              2468 	mov	b,r4
   0BD3 ED                 2469 	mov	a,r5
   0BD4 12 28 C8           2470 	lcall	___fs2sint
   0BD7 E5 82              2471 	mov	a,dpl
   0BD9 85 83 F0           2472 	mov	b,dph
   0BDC D0 06              2473 	pop	ar6
   0BDE D0 07              2474 	pop	ar7
   0BE0 78 20              2475 	mov	r0,#_pan_add
   0BE2 F2                 2476 	movx	@r0,a
   0BE3 08                 2477 	inc	r0
   0BE4 E5 F0              2478 	mov	a,b
   0BE6 F2                 2479 	movx	@r0,a
                    068B   2480 	C$wireless_serial.c$461$1$1 ==.
                           2481 ;	apps/commander/wireless_serial.c:461: tilt_add = (-(float)lookV)/25;
   0BE7 8F 82              2482 	mov	dpl,r7
   0BE9 8E 83              2483 	mov	dph,r6
   0BEB 12 28 BB           2484 	lcall	___sint2fs
   0BEE AC 82              2485 	mov	r4,dpl
   0BF0 AD 83              2486 	mov	r5,dph
   0BF2 AE F0              2487 	mov	r6,b
   0BF4 B2 E7              2488 	cpl	acc.7
   0BF6 FF                 2489 	mov	r7,a
   0BF7 E4                 2490 	clr	a
   0BF8 C0 E0              2491 	push	acc
   0BFA C0 E0              2492 	push	acc
   0BFC 74 C8              2493 	mov	a,#0xC8
   0BFE C0 E0              2494 	push	acc
   0C00 74 41              2495 	mov	a,#0x41
   0C02 C0 E0              2496 	push	acc
   0C04 8C 82              2497 	mov	dpl,r4
   0C06 8D 83              2498 	mov	dph,r5
   0C08 8E F0              2499 	mov	b,r6
   0C0A EF                 2500 	mov	a,r7
   0C0B 12 29 8A           2501 	lcall	___fsdiv
   0C0E AC 82              2502 	mov	r4,dpl
   0C10 AD 83              2503 	mov	r5,dph
   0C12 AE F0              2504 	mov	r6,b
   0C14 FF                 2505 	mov	r7,a
   0C15 E5 81              2506 	mov	a,sp
   0C17 24 FC              2507 	add	a,#0xfc
   0C19 F5 81              2508 	mov	sp,a
   0C1B 8C 82              2509 	mov	dpl,r4
   0C1D 8D 83              2510 	mov	dph,r5
   0C1F 8E F0              2511 	mov	b,r6
   0C21 EF                 2512 	mov	a,r7
   0C22 12 28 C8           2513 	lcall	___fs2sint
   0C25 E5 82              2514 	mov	a,dpl
   0C27 85 83 F0           2515 	mov	b,dph
   0C2A 78 22              2516 	mov	r0,#_tilt_add
   0C2C F2                 2517 	movx	@r0,a
   0C2D 08                 2518 	inc	r0
   0C2E E5 F0              2519 	mov	a,b
   0C30 F2                 2520 	movx	@r0,a
                    06D5   2521 	C$wireless_serial.c$470$6$24 ==.
                           2522 ;	apps/commander/wireless_serial.c:470: walkV = (signed char)( (int)vals[2]-128 );
   0C31 78 26              2523 	mov	r0,#(_vals + 0x0002)
   0C33 E2                 2524 	movx	a,@r0
   0C34 24 80              2525 	add	a,#0x80
   0C36 FF                 2526 	mov	r7,a
   0C37 78 30              2527 	mov	r0,#_walkV
   0C39 F2                 2528 	movx	@r0,a
   0C3A EF                 2529 	mov	a,r7
   0C3B 33                 2530 	rlc	a
   0C3C 95 E0              2531 	subb	a,acc
   0C3E 08                 2532 	inc	r0
   0C3F F2                 2533 	movx	@r0,a
                    06E4   2534 	C$wireless_serial.c$471$6$24 ==.
                           2535 ;	apps/commander/wireless_serial.c:471: walkH = (signed char)( (int)vals[3]-128 );
   0C40 78 27              2536 	mov	r0,#(_vals + 0x0003)
   0C42 E2                 2537 	movx	a,@r0
   0C43 7E 00              2538 	mov	r6,#0x00
   0C45 24 80              2539 	add	a,#0x80
   0C47 FF                 2540 	mov	r7,a
   0C48 78 32              2541 	mov	r0,#_walkH
   0C4A F2                 2542 	movx	@r0,a
   0C4B EF                 2543 	mov	a,r7
   0C4C 33                 2544 	rlc	a
   0C4D 95 E0              2545 	subb	a,acc
   0C4F 08                 2546 	inc	r0
   0C50 F2                 2547 	movx	@r0,a
   0C51                    2548 00132$:
                    06F5   2549 	C$wireless_serial.c$478$4$8 ==.
                           2550 ;	apps/commander/wireless_serial.c:478: index_cmdr = -1;
   0C51 78 2B              2551 	mov	r0,#_index_cmdr
   0C53 74 FF              2552 	mov	a,#0xFF
   0C55 F2                 2553 	movx	@r0,a
   0C56 08                 2554 	inc	r0
   0C57 74 FF              2555 	mov	a,#0xFF
   0C59 F2                 2556 	movx	@r0,a
                    06FE   2557 	C$wireless_serial.c$482$4$8 ==.
                           2558 ;	apps/commander/wireless_serial.c:482: return 1;
   0C5A 90 00 01           2559 	mov	dptr,#0x0001
   0C5D 80 03              2560 	sjmp	00144$
   0C5F                    2561 00143$:
                    0703   2562 	C$wireless_serial.c$486$1$1 ==.
                           2563 ;	apps/commander/wireless_serial.c:486: return 0;
   0C5F 90 00 00           2564 	mov	dptr,#0x0000
   0C62                    2565 00144$:
                    0706   2566 	C$wireless_serial.c$487$1$1 ==.
                    0706   2567 	XG$CmdrReadMsgs$0$0 ==.
   0C62 22                 2568 	ret
                           2569 ;------------------------------------------------------------
                           2570 ;Allocation info for local variables in function 'UseSouthPaw'
                           2571 ;------------------------------------------------------------
                    0707   2572 	G$UseSouthPaw$0$0 ==.
                    0707   2573 	C$wireless_serial.c$489$1$1 ==.
                           2574 ;	apps/commander/wireless_serial.c:489: void UseSouthPaw(){
                           2575 ;	-----------------------------------------
                           2576 ;	 function UseSouthPaw
                           2577 ;	-----------------------------------------
   0C63                    2578 _UseSouthPaw:
                    0707   2579 	C$wireless_serial.c$490$1$1 ==.
                           2580 ;	apps/commander/wireless_serial.c:490: southpaw |= 0x01;
   0C63 78 2F              2581 	mov	r0,#_southpaw
   0C65 E2                 2582 	movx	a,@r0
   0C66 44 01              2583 	orl	a,#0x01
   0C68 F2                 2584 	movx	@r0,a
                    070D   2585 	C$wireless_serial.c$491$1$1 ==.
                    070D   2586 	XG$UseSouthPaw$0$0 ==.
   0C69 22                 2587 	ret
                           2588 ;------------------------------------------------------------
                           2589 ;Allocation info for local variables in function 'main'
                           2590 ;------------------------------------------------------------
                    070E   2591 	G$main$0$0 ==.
                    070E   2592 	C$wireless_serial.c$493$1$1 ==.
                           2593 ;	apps/commander/wireless_serial.c:493: void main()
                           2594 ;	-----------------------------------------
                           2595 ;	 function main
                           2596 ;	-----------------------------------------
   0C6A                    2597 _main:
                    070E   2598 	C$wireless_serial.c$495$1$1 ==.
                           2599 ;	apps/commander/wireless_serial.c:495: systemInit();
   0C6A 12 20 41           2600 	lcall	_systemInit
                    0711   2601 	C$wireless_serial.c$497$1$1 ==.
                           2602 ;	apps/commander/wireless_serial.c:497: setDigitalOutput(param_arduino_DTR_pin, LOW);
   0C6D 90 2C 27           2603 	mov	dptr,#_param_arduino_DTR_pin
   0C70 E4                 2604 	clr	a
   0C71 93                 2605 	movc	a,@a+dptr
   0C72 FC                 2606 	mov	r4,a
   0C73 74 01              2607 	mov	a,#0x01
   0C75 93                 2608 	movc	a,@a+dptr
   0C76 74 02              2609 	mov	a,#0x02
   0C78 93                 2610 	movc	a,@a+dptr
   0C79 74 03              2611 	mov	a,#0x03
   0C7B 93                 2612 	movc	a,@a+dptr
   0C7C 8C 82              2613 	mov	dpl,r4
   0C7E C2 F0              2614 	clr	b[0]
   0C80 85 F0 24           2615 	mov	bits,b
   0C83 12 24 05           2616 	lcall	_setDigitalOutput
                    072A   2617 	C$wireless_serial.c$498$1$1 ==.
                           2618 ;	apps/commander/wireless_serial.c:498: ioTxSignals(0);
   0C86 75 82 00           2619 	mov	dpl,#0x00
   0C89 12 06 B2           2620 	lcall	_ioTxSignals
                    0730   2621 	C$wireless_serial.c$500$1$1 ==.
                           2622 ;	apps/commander/wireless_serial.c:500: usbInit();
   0C8C 12 17 A4           2623 	lcall	_usbInit
                    0733   2624 	C$wireless_serial.c$502$1$1 ==.
                           2625 ;	apps/commander/wireless_serial.c:502: uart1Init();
   0C8F 12 0D 31           2626 	lcall	_uart1Init
                    0736   2627 	C$wireless_serial.c$503$1$1 ==.
                           2628 ;	apps/commander/wireless_serial.c:503: uart1SetBaudRate(param_baud_rate);
   0C92 90 2C 03           2629 	mov	dptr,#_param_baud_rate
   0C95 E4                 2630 	clr	a
   0C96 93                 2631 	movc	a,@a+dptr
   0C97 FC                 2632 	mov	r4,a
   0C98 74 01              2633 	mov	a,#0x01
   0C9A 93                 2634 	movc	a,@a+dptr
   0C9B FD                 2635 	mov	r5,a
   0C9C 74 02              2636 	mov	a,#0x02
   0C9E 93                 2637 	movc	a,@a+dptr
   0C9F FE                 2638 	mov	r6,a
   0CA0 74 03              2639 	mov	a,#0x03
   0CA2 93                 2640 	movc	a,@a+dptr
   0CA3 8C 82              2641 	mov	dpl,r4
   0CA5 8D 83              2642 	mov	dph,r5
   0CA7 8E F0              2643 	mov	b,r6
   0CA9 12 0D 65           2644 	lcall	_uart1SetBaudRate
                    0750   2645 	C$wireless_serial.c$505$1$1 ==.
                           2646 ;	apps/commander/wireless_serial.c:505: if (param_serial_mode != SERIAL_MODE_USB_UART)
   0CAC 90 2B FF           2647 	mov	dptr,#_param_serial_mode
   0CAF E4                 2648 	clr	a
   0CB0 93                 2649 	movc	a,@a+dptr
   0CB1 FC                 2650 	mov	r4,a
   0CB2 74 01              2651 	mov	a,#0x01
   0CB4 93                 2652 	movc	a,@a+dptr
   0CB5 FD                 2653 	mov	r5,a
   0CB6 74 02              2654 	mov	a,#0x02
   0CB8 93                 2655 	movc	a,@a+dptr
   0CB9 FE                 2656 	mov	r6,a
   0CBA 74 03              2657 	mov	a,#0x03
   0CBC 93                 2658 	movc	a,@a+dptr
   0CBD FF                 2659 	mov	r7,a
   0CBE BC 03 0B           2660 	cjne	r4,#0x03,00120$
   0CC1 BD 00 08           2661 	cjne	r5,#0x00,00120$
   0CC4 BE 00 05           2662 	cjne	r6,#0x00,00120$
   0CC7 BF 00 02           2663 	cjne	r7,#0x00,00120$
   0CCA 80 05              2664 	sjmp	00102$
   0CCC                    2665 00120$:
                    0770   2666 	C$wireless_serial.c$507$2$2 ==.
                           2667 ;	apps/commander/wireless_serial.c:507: radioComRxEnforceOrdering = 1;
   0CCC D2 18              2668 	setb	_radioComRxEnforceOrdering
                    0772   2669 	C$wireless_serial.c$508$2$2 ==.
                           2670 ;	apps/commander/wireless_serial.c:508: radioComInit();
   0CCE 12 1E E8           2671 	lcall	_radioComInit
   0CD1                    2672 00102$:
                    0775   2673 	C$wireless_serial.c$512$1$1 ==.
                           2674 ;	apps/commander/wireless_serial.c:512: P1DIR |= (1<<5);
   0CD1 43 FE 20           2675 	orl	_P1DIR,#0x20
                    0778   2676 	C$wireless_serial.c$513$1$1 ==.
                           2677 ;	apps/commander/wireless_serial.c:513: IOCFG0 = 0b011011; // P1_5 = PA_PD (TX mode)
   0CD4 90 DF 31           2678 	mov	dptr,#_IOCFG0
   0CD7 74 1B              2679 	mov	a,#0x1B
   0CD9 F0                 2680 	movx	@dptr,a
                    077E   2681 	C$wireless_serial.c$515$1$1 ==.
                           2682 ;	apps/commander/wireless_serial.c:515: while(1)
   0CDA                    2683 00110$:
                    077E   2684 	C$wireless_serial.c$517$2$3 ==.
                           2685 ;	apps/commander/wireless_serial.c:517: updateSerialMode();
   0CDA 12 08 9B           2686 	lcall	_updateSerialMode
                    0781   2687 	C$wireless_serial.c$518$2$3 ==.
                           2688 ;	apps/commander/wireless_serial.c:518: boardService();
   0CDD 12 20 4E           2689 	lcall	_boardService
                    0784   2690 	C$wireless_serial.c$519$2$3 ==.
                           2691 ;	apps/commander/wireless_serial.c:519: updateLeds();
   0CE0 12 05 5C           2692 	lcall	_updateLeds
                    0787   2693 	C$wireless_serial.c$520$2$3 ==.
                           2694 ;	apps/commander/wireless_serial.c:520: errorService();
   0CE3 12 07 D7           2695 	lcall	_errorService
                    078A   2696 	C$wireless_serial.c$522$2$3 ==.
                           2697 ;	apps/commander/wireless_serial.c:522: if (param_serial_mode != SERIAL_MODE_USB_UART)
   0CE6 90 2B FF           2698 	mov	dptr,#_param_serial_mode
   0CE9 E4                 2699 	clr	a
   0CEA 93                 2700 	movc	a,@a+dptr
   0CEB FC                 2701 	mov	r4,a
   0CEC 74 01              2702 	mov	a,#0x01
   0CEE 93                 2703 	movc	a,@a+dptr
   0CEF FD                 2704 	mov	r5,a
   0CF0 74 02              2705 	mov	a,#0x02
   0CF2 93                 2706 	movc	a,@a+dptr
   0CF3 FE                 2707 	mov	r6,a
   0CF4 74 03              2708 	mov	a,#0x03
   0CF6 93                 2709 	movc	a,@a+dptr
   0CF7 FF                 2710 	mov	r7,a
   0CF8 BC 03 0B           2711 	cjne	r4,#0x03,00121$
   0CFB BD 00 08           2712 	cjne	r5,#0x00,00121$
   0CFE BE 00 05           2713 	cjne	r6,#0x00,00121$
   0D01 BF 00 02           2714 	cjne	r7,#0x00,00121$
   0D04 80 03              2715 	sjmp	00104$
   0D06                    2716 00121$:
                    07AA   2717 	C$wireless_serial.c$524$3$4 ==.
                           2718 ;	apps/commander/wireless_serial.c:524: radioComTxService();
   0D06 12 1F B3           2719 	lcall	_radioComTxService
   0D09                    2720 00104$:
                    07AD   2721 	C$wireless_serial.c$527$2$3 ==.
                           2722 ;	apps/commander/wireless_serial.c:527: usbComService();
   0D09 12 16 42           2723 	lcall	_usbComService
                    07B0   2724 	C$wireless_serial.c$529$2$3 ==.
                           2725 ;	apps/commander/wireless_serial.c:529: switch(currentSerialMode)
   0D0C 74 01              2726 	mov	a,#0x01
   0D0E B5 08 02           2727 	cjne	a,_currentSerialMode,00122$
   0D11 80 0E              2728 	sjmp	00105$
   0D13                    2729 00122$:
   0D13 74 02              2730 	mov	a,#0x02
   0D15 B5 08 02           2731 	cjne	a,_currentSerialMode,00123$
   0D18 80 0C              2732 	sjmp	00106$
   0D1A                    2733 00123$:
   0D1A 74 03              2734 	mov	a,#0x03
                    07C0   2735 	C$wireless_serial.c$531$3$5 ==.
                           2736 ;	apps/commander/wireless_serial.c:531: case SERIAL_MODE_USB_RADIO: usbToRadioService(); break;
   0D1C B5 08 BB           2737 	cjne	a,_currentSerialMode,00110$
   0D1F 80 0A              2738 	sjmp	00107$
   0D21                    2739 00105$:
   0D21 12 08 D1           2740 	lcall	_usbToRadioService
                    07C8   2741 	C$wireless_serial.c$532$3$5 ==.
                           2742 ;	apps/commander/wireless_serial.c:532: case SERIAL_MODE_UART_RADIO: uartToRadioService(); break;
   0D24 80 B4              2743 	sjmp	00110$
   0D26                    2744 00106$:
   0D26 12 09 7D           2745 	lcall	_uartToRadioService
                    07CD   2746 	C$wireless_serial.c$533$3$5 ==.
                           2747 ;	apps/commander/wireless_serial.c:533: case SERIAL_MODE_USB_UART: usbToUartService(); break;
   0D29 80 AF              2748 	sjmp	00110$
   0D2B                    2749 00107$:
   0D2B 12 09 2A           2750 	lcall	_usbToUartService
                    07D2   2751 	C$wireless_serial.c$534$1$1 ==.
                           2752 ;	apps/commander/wireless_serial.c:534: }
   0D2E 80 AA              2753 	sjmp	00110$
                    07D4   2754 	C$wireless_serial.c$536$1$1 ==.
                    07D4   2755 	XG$main$0$0 ==.
   0D30 22                 2756 	ret
                           2757 	.area CSEG    (CODE)
                           2758 	.area CONST   (CODE)
                    0000   2759 G$param_serial_mode$0$0 == .
   2BFF                    2760 _param_serial_mode:
   2BFF 00 00 00 00        2761 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   2762 G$param_baud_rate$0$0 == .
   2C03                    2763 _param_baud_rate:
   2C03 80 25 00 00        2764 	.byte #0x80,#0x25,#0x00,#0x00	;  9600
                    0008   2765 G$param_nDTR_pin$0$0 == .
   2C07                    2766 _param_nDTR_pin:
   2C07 0A 00 00 00        2767 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   2768 G$param_nRTS_pin$0$0 == .
   2C0B                    2769 _param_nRTS_pin:
   2C0B 0B 00 00 00        2770 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   2771 G$param_nDSR_pin$0$0 == .
   2C0F                    2772 _param_nDSR_pin:
   2C0F 0C 00 00 00        2773 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    0014   2774 G$param_nCD_pin$0$0 == .
   2C13                    2775 _param_nCD_pin:
   2C13 0D 00 00 00        2776 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0018   2777 G$param_DTR_pin$0$0 == .
   2C17                    2778 _param_DTR_pin:
   2C17 FF FF FF FF        2779 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    001C   2780 G$param_RTS_pin$0$0 == .
   2C1B                    2781 _param_RTS_pin:
   2C1B FF FF FF FF        2782 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0020   2783 G$param_DSR_pin$0$0 == .
   2C1F                    2784 _param_DSR_pin:
   2C1F FF FF FF FF        2785 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0024   2786 G$param_CD_pin$0$0 == .
   2C23                    2787 _param_CD_pin:
   2C23 FF FF FF FF        2788 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0028   2789 G$param_arduino_DTR_pin$0$0 == .
   2C27                    2790 _param_arduino_DTR_pin:
   2C27 00 00 00 00        2791 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002C   2792 G$param_framing_error_ms$0$0 == .
   2C2B                    2793 _param_framing_error_ms:
   2C2B 00 00 00 00        2794 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                           2795 	.area XINIT   (CODE)
                           2796 	.area CABS    (ABS,CODE)
