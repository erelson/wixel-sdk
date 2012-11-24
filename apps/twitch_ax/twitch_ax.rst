                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Nov 23 22:10:21 2012
                              5 ;--------------------------------------------------------
                              6 	.module twitch_ax
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _g8loopSpeed
                             13 	.globl _param_framing_error_ms
                             14 	.globl _param_arduino_DTR_pin
                             15 	.globl _param_CD_pin
                             16 	.globl _param_DSR_pin
                             17 	.globl _param_RTS_pin
                             18 	.globl _param_DTR_pin
                             19 	.globl _param_nCD_pin
                             20 	.globl _param_nDSR_pin
                             21 	.globl _param_nRTS_pin
                             22 	.globl _param_nDTR_pin
                             23 	.globl _param_baud_rate
                             24 	.globl _param_serial_mode
                             25 	.globl _animations
                             26 	.globl _main
                             27 	.globl _uartToRadioService
                             28 	.globl _errorService
                             29 	.globl _errorOccurred
                             30 	.globl _ioTxSignals
                             31 	.globl _ioRxSignals
                             32 	.globl _updateLeds
                             33 	.globl _interpolateU
                             34 	.globl _dynamixel_gethighbyte
                             35 	.globl _dynamixel_getlowbyte
                             36 	.globl _dynamixel_syncwrite
                             37 	.globl _dynamixel_init
                             38 	.globl _malloc
                             39 	.globl _uart1RxReceiveByte
                             40 	.globl _uart1RxAvailable
                             41 	.globl _uart1SetBaudRate
                             42 	.globl _uart1Init
                             43 	.globl _radioComRxControlSignals
                             44 	.globl _radioComTxControlSignals
                             45 	.globl _radioComTxSendByte
                             46 	.globl _radioComTxAvailable
                             47 	.globl _radioComTxService
                             48 	.globl _radioComRxReceiveByte
                             49 	.globl _radioComRxAvailable
                             50 	.globl _radioComInit
                             51 	.globl _radioLinkConnected
                             52 	.globl _isPinHigh
                             53 	.globl _setDigitalOutput
                             54 	.globl _delayMs
                             55 	.globl _getMs
                             56 	.globl _boardService
                             57 	.globl _systemInit
                             58 	.globl _gaitRunnerPlay_PARM_5
                             59 	.globl _gaitRunnerPlay_PARM_4
                             60 	.globl _gaitRunnerPlay_PARM_3
                             61 	.globl _gaitRunnerPlay_PARM_2
                             62 	.globl _CmdrReadMsgs_PARM_3
                             63 	.globl _CmdrReadMsgs_PARM_2
                             64 	.globl _currentPos
                             65 	.globl _g8repeatCount
                             66 	.globl _g8playbackDir
                             67 	.globl _g8speed
                             68 	.globl _lastErrorTime
                             69 	.globl _lookH
                             70 	.globl _lookV
                             71 	.globl _walkH
                             72 	.globl _walkV
                             73 	.globl _checksum_cmdr
                             74 	.globl _index_cmdr
                             75 	.globl _vals
                             76 	.globl _errorOccurredRecently
                             77 	.globl _framingErrorActive
                             78 	.globl _uartRxDisabled
                             79 	.globl _CmdrReadMsgs
                             80 	.globl _gaitRunnerInit
                             81 	.globl _gaitRunnerPlay
                             82 	.globl _gaitRunnerProcess
                             83 ;--------------------------------------------------------
                             84 ; special function registers
                             85 ;--------------------------------------------------------
                             86 	.area RSEG    (ABS,DATA)
   0000                      87 	.org 0x0000
                    0080     88 Ftwitch_ax$P0$0$0 == 0x0080
                    0080     89 _P0	=	0x0080
                    0081     90 Ftwitch_ax$SP$0$0 == 0x0081
                    0081     91 _SP	=	0x0081
                    0082     92 Ftwitch_ax$DPL0$0$0 == 0x0082
                    0082     93 _DPL0	=	0x0082
                    0083     94 Ftwitch_ax$DPH0$0$0 == 0x0083
                    0083     95 _DPH0	=	0x0083
                    0084     96 Ftwitch_ax$DPL1$0$0 == 0x0084
                    0084     97 _DPL1	=	0x0084
                    0085     98 Ftwitch_ax$DPH1$0$0 == 0x0085
                    0085     99 _DPH1	=	0x0085
                    0086    100 Ftwitch_ax$U0CSR$0$0 == 0x0086
                    0086    101 _U0CSR	=	0x0086
                    0087    102 Ftwitch_ax$PCON$0$0 == 0x0087
                    0087    103 _PCON	=	0x0087
                    0088    104 Ftwitch_ax$TCON$0$0 == 0x0088
                    0088    105 _TCON	=	0x0088
                    0089    106 Ftwitch_ax$P0IFG$0$0 == 0x0089
                    0089    107 _P0IFG	=	0x0089
                    008A    108 Ftwitch_ax$P1IFG$0$0 == 0x008a
                    008A    109 _P1IFG	=	0x008a
                    008B    110 Ftwitch_ax$P2IFG$0$0 == 0x008b
                    008B    111 _P2IFG	=	0x008b
                    008C    112 Ftwitch_ax$PICTL$0$0 == 0x008c
                    008C    113 _PICTL	=	0x008c
                    008D    114 Ftwitch_ax$P1IEN$0$0 == 0x008d
                    008D    115 _P1IEN	=	0x008d
                    008F    116 Ftwitch_ax$P0INP$0$0 == 0x008f
                    008F    117 _P0INP	=	0x008f
                    0090    118 Ftwitch_ax$P1$0$0 == 0x0090
                    0090    119 _P1	=	0x0090
                    0091    120 Ftwitch_ax$RFIM$0$0 == 0x0091
                    0091    121 _RFIM	=	0x0091
                    0092    122 Ftwitch_ax$DPS$0$0 == 0x0092
                    0092    123 _DPS	=	0x0092
                    0093    124 Ftwitch_ax$MPAGE$0$0 == 0x0093
                    0093    125 _MPAGE	=	0x0093
                    0095    126 Ftwitch_ax$ENDIAN$0$0 == 0x0095
                    0095    127 _ENDIAN	=	0x0095
                    0098    128 Ftwitch_ax$S0CON$0$0 == 0x0098
                    0098    129 _S0CON	=	0x0098
                    009A    130 Ftwitch_ax$IEN2$0$0 == 0x009a
                    009A    131 _IEN2	=	0x009a
                    009B    132 Ftwitch_ax$S1CON$0$0 == 0x009b
                    009B    133 _S1CON	=	0x009b
                    009C    134 Ftwitch_ax$T2CT$0$0 == 0x009c
                    009C    135 _T2CT	=	0x009c
                    009D    136 Ftwitch_ax$T2PR$0$0 == 0x009d
                    009D    137 _T2PR	=	0x009d
                    009E    138 Ftwitch_ax$T2CTL$0$0 == 0x009e
                    009E    139 _T2CTL	=	0x009e
                    00A0    140 Ftwitch_ax$P2$0$0 == 0x00a0
                    00A0    141 _P2	=	0x00a0
                    00A1    142 Ftwitch_ax$WORIRQ$0$0 == 0x00a1
                    00A1    143 _WORIRQ	=	0x00a1
                    00A2    144 Ftwitch_ax$WORCTRL$0$0 == 0x00a2
                    00A2    145 _WORCTRL	=	0x00a2
                    00A3    146 Ftwitch_ax$WOREVT0$0$0 == 0x00a3
                    00A3    147 _WOREVT0	=	0x00a3
                    00A4    148 Ftwitch_ax$WOREVT1$0$0 == 0x00a4
                    00A4    149 _WOREVT1	=	0x00a4
                    00A5    150 Ftwitch_ax$WORTIME0$0$0 == 0x00a5
                    00A5    151 _WORTIME0	=	0x00a5
                    00A6    152 Ftwitch_ax$WORTIME1$0$0 == 0x00a6
                    00A6    153 _WORTIME1	=	0x00a6
                    00A8    154 Ftwitch_ax$IEN0$0$0 == 0x00a8
                    00A8    155 _IEN0	=	0x00a8
                    00A9    156 Ftwitch_ax$IP0$0$0 == 0x00a9
                    00A9    157 _IP0	=	0x00a9
                    00AB    158 Ftwitch_ax$FWT$0$0 == 0x00ab
                    00AB    159 _FWT	=	0x00ab
                    00AC    160 Ftwitch_ax$FADDRL$0$0 == 0x00ac
                    00AC    161 _FADDRL	=	0x00ac
                    00AD    162 Ftwitch_ax$FADDRH$0$0 == 0x00ad
                    00AD    163 _FADDRH	=	0x00ad
                    00AE    164 Ftwitch_ax$FCTL$0$0 == 0x00ae
                    00AE    165 _FCTL	=	0x00ae
                    00AF    166 Ftwitch_ax$FWDATA$0$0 == 0x00af
                    00AF    167 _FWDATA	=	0x00af
                    00B1    168 Ftwitch_ax$ENCDI$0$0 == 0x00b1
                    00B1    169 _ENCDI	=	0x00b1
                    00B2    170 Ftwitch_ax$ENCDO$0$0 == 0x00b2
                    00B2    171 _ENCDO	=	0x00b2
                    00B3    172 Ftwitch_ax$ENCCS$0$0 == 0x00b3
                    00B3    173 _ENCCS	=	0x00b3
                    00B4    174 Ftwitch_ax$ADCCON1$0$0 == 0x00b4
                    00B4    175 _ADCCON1	=	0x00b4
                    00B5    176 Ftwitch_ax$ADCCON2$0$0 == 0x00b5
                    00B5    177 _ADCCON2	=	0x00b5
                    00B6    178 Ftwitch_ax$ADCCON3$0$0 == 0x00b6
                    00B6    179 _ADCCON3	=	0x00b6
                    00B8    180 Ftwitch_ax$IEN1$0$0 == 0x00b8
                    00B8    181 _IEN1	=	0x00b8
                    00B9    182 Ftwitch_ax$IP1$0$0 == 0x00b9
                    00B9    183 _IP1	=	0x00b9
                    00BA    184 Ftwitch_ax$ADCL$0$0 == 0x00ba
                    00BA    185 _ADCL	=	0x00ba
                    00BB    186 Ftwitch_ax$ADCH$0$0 == 0x00bb
                    00BB    187 _ADCH	=	0x00bb
                    00BC    188 Ftwitch_ax$RNDL$0$0 == 0x00bc
                    00BC    189 _RNDL	=	0x00bc
                    00BD    190 Ftwitch_ax$RNDH$0$0 == 0x00bd
                    00BD    191 _RNDH	=	0x00bd
                    00BE    192 Ftwitch_ax$SLEEP$0$0 == 0x00be
                    00BE    193 _SLEEP	=	0x00be
                    00C0    194 Ftwitch_ax$IRCON$0$0 == 0x00c0
                    00C0    195 _IRCON	=	0x00c0
                    00C1    196 Ftwitch_ax$U0DBUF$0$0 == 0x00c1
                    00C1    197 _U0DBUF	=	0x00c1
                    00C2    198 Ftwitch_ax$U0BAUD$0$0 == 0x00c2
                    00C2    199 _U0BAUD	=	0x00c2
                    00C4    200 Ftwitch_ax$U0UCR$0$0 == 0x00c4
                    00C4    201 _U0UCR	=	0x00c4
                    00C5    202 Ftwitch_ax$U0GCR$0$0 == 0x00c5
                    00C5    203 _U0GCR	=	0x00c5
                    00C6    204 Ftwitch_ax$CLKCON$0$0 == 0x00c6
                    00C6    205 _CLKCON	=	0x00c6
                    00C7    206 Ftwitch_ax$MEMCTR$0$0 == 0x00c7
                    00C7    207 _MEMCTR	=	0x00c7
                    00C9    208 Ftwitch_ax$WDCTL$0$0 == 0x00c9
                    00C9    209 _WDCTL	=	0x00c9
                    00CA    210 Ftwitch_ax$T3CNT$0$0 == 0x00ca
                    00CA    211 _T3CNT	=	0x00ca
                    00CB    212 Ftwitch_ax$T3CTL$0$0 == 0x00cb
                    00CB    213 _T3CTL	=	0x00cb
                    00CC    214 Ftwitch_ax$T3CCTL0$0$0 == 0x00cc
                    00CC    215 _T3CCTL0	=	0x00cc
                    00CD    216 Ftwitch_ax$T3CC0$0$0 == 0x00cd
                    00CD    217 _T3CC0	=	0x00cd
                    00CE    218 Ftwitch_ax$T3CCTL1$0$0 == 0x00ce
                    00CE    219 _T3CCTL1	=	0x00ce
                    00CF    220 Ftwitch_ax$T3CC1$0$0 == 0x00cf
                    00CF    221 _T3CC1	=	0x00cf
                    00D0    222 Ftwitch_ax$PSW$0$0 == 0x00d0
                    00D0    223 _PSW	=	0x00d0
                    00D1    224 Ftwitch_ax$DMAIRQ$0$0 == 0x00d1
                    00D1    225 _DMAIRQ	=	0x00d1
                    00D2    226 Ftwitch_ax$DMA1CFGL$0$0 == 0x00d2
                    00D2    227 _DMA1CFGL	=	0x00d2
                    00D3    228 Ftwitch_ax$DMA1CFGH$0$0 == 0x00d3
                    00D3    229 _DMA1CFGH	=	0x00d3
                    00D4    230 Ftwitch_ax$DMA0CFGL$0$0 == 0x00d4
                    00D4    231 _DMA0CFGL	=	0x00d4
                    00D5    232 Ftwitch_ax$DMA0CFGH$0$0 == 0x00d5
                    00D5    233 _DMA0CFGH	=	0x00d5
                    00D6    234 Ftwitch_ax$DMAARM$0$0 == 0x00d6
                    00D6    235 _DMAARM	=	0x00d6
                    00D7    236 Ftwitch_ax$DMAREQ$0$0 == 0x00d7
                    00D7    237 _DMAREQ	=	0x00d7
                    00D8    238 Ftwitch_ax$TIMIF$0$0 == 0x00d8
                    00D8    239 _TIMIF	=	0x00d8
                    00D9    240 Ftwitch_ax$RFD$0$0 == 0x00d9
                    00D9    241 _RFD	=	0x00d9
                    00DA    242 Ftwitch_ax$T1CC0L$0$0 == 0x00da
                    00DA    243 _T1CC0L	=	0x00da
                    00DB    244 Ftwitch_ax$T1CC0H$0$0 == 0x00db
                    00DB    245 _T1CC0H	=	0x00db
                    00DC    246 Ftwitch_ax$T1CC1L$0$0 == 0x00dc
                    00DC    247 _T1CC1L	=	0x00dc
                    00DD    248 Ftwitch_ax$T1CC1H$0$0 == 0x00dd
                    00DD    249 _T1CC1H	=	0x00dd
                    00DE    250 Ftwitch_ax$T1CC2L$0$0 == 0x00de
                    00DE    251 _T1CC2L	=	0x00de
                    00DF    252 Ftwitch_ax$T1CC2H$0$0 == 0x00df
                    00DF    253 _T1CC2H	=	0x00df
                    00E0    254 Ftwitch_ax$ACC$0$0 == 0x00e0
                    00E0    255 _ACC	=	0x00e0
                    00E1    256 Ftwitch_ax$RFST$0$0 == 0x00e1
                    00E1    257 _RFST	=	0x00e1
                    00E2    258 Ftwitch_ax$T1CNTL$0$0 == 0x00e2
                    00E2    259 _T1CNTL	=	0x00e2
                    00E3    260 Ftwitch_ax$T1CNTH$0$0 == 0x00e3
                    00E3    261 _T1CNTH	=	0x00e3
                    00E4    262 Ftwitch_ax$T1CTL$0$0 == 0x00e4
                    00E4    263 _T1CTL	=	0x00e4
                    00E5    264 Ftwitch_ax$T1CCTL0$0$0 == 0x00e5
                    00E5    265 _T1CCTL0	=	0x00e5
                    00E6    266 Ftwitch_ax$T1CCTL1$0$0 == 0x00e6
                    00E6    267 _T1CCTL1	=	0x00e6
                    00E7    268 Ftwitch_ax$T1CCTL2$0$0 == 0x00e7
                    00E7    269 _T1CCTL2	=	0x00e7
                    00E8    270 Ftwitch_ax$IRCON2$0$0 == 0x00e8
                    00E8    271 _IRCON2	=	0x00e8
                    00E9    272 Ftwitch_ax$RFIF$0$0 == 0x00e9
                    00E9    273 _RFIF	=	0x00e9
                    00EA    274 Ftwitch_ax$T4CNT$0$0 == 0x00ea
                    00EA    275 _T4CNT	=	0x00ea
                    00EB    276 Ftwitch_ax$T4CTL$0$0 == 0x00eb
                    00EB    277 _T4CTL	=	0x00eb
                    00EC    278 Ftwitch_ax$T4CCTL0$0$0 == 0x00ec
                    00EC    279 _T4CCTL0	=	0x00ec
                    00ED    280 Ftwitch_ax$T4CC0$0$0 == 0x00ed
                    00ED    281 _T4CC0	=	0x00ed
                    00EE    282 Ftwitch_ax$T4CCTL1$0$0 == 0x00ee
                    00EE    283 _T4CCTL1	=	0x00ee
                    00EF    284 Ftwitch_ax$T4CC1$0$0 == 0x00ef
                    00EF    285 _T4CC1	=	0x00ef
                    00F0    286 Ftwitch_ax$B$0$0 == 0x00f0
                    00F0    287 _B	=	0x00f0
                    00F1    288 Ftwitch_ax$PERCFG$0$0 == 0x00f1
                    00F1    289 _PERCFG	=	0x00f1
                    00F2    290 Ftwitch_ax$ADCCFG$0$0 == 0x00f2
                    00F2    291 _ADCCFG	=	0x00f2
                    00F3    292 Ftwitch_ax$P0SEL$0$0 == 0x00f3
                    00F3    293 _P0SEL	=	0x00f3
                    00F4    294 Ftwitch_ax$P1SEL$0$0 == 0x00f4
                    00F4    295 _P1SEL	=	0x00f4
                    00F5    296 Ftwitch_ax$P2SEL$0$0 == 0x00f5
                    00F5    297 _P2SEL	=	0x00f5
                    00F6    298 Ftwitch_ax$P1INP$0$0 == 0x00f6
                    00F6    299 _P1INP	=	0x00f6
                    00F7    300 Ftwitch_ax$P2INP$0$0 == 0x00f7
                    00F7    301 _P2INP	=	0x00f7
                    00F8    302 Ftwitch_ax$U1CSR$0$0 == 0x00f8
                    00F8    303 _U1CSR	=	0x00f8
                    00F9    304 Ftwitch_ax$U1DBUF$0$0 == 0x00f9
                    00F9    305 _U1DBUF	=	0x00f9
                    00FA    306 Ftwitch_ax$U1BAUD$0$0 == 0x00fa
                    00FA    307 _U1BAUD	=	0x00fa
                    00FB    308 Ftwitch_ax$U1UCR$0$0 == 0x00fb
                    00FB    309 _U1UCR	=	0x00fb
                    00FC    310 Ftwitch_ax$U1GCR$0$0 == 0x00fc
                    00FC    311 _U1GCR	=	0x00fc
                    00FD    312 Ftwitch_ax$P0DIR$0$0 == 0x00fd
                    00FD    313 _P0DIR	=	0x00fd
                    00FE    314 Ftwitch_ax$P1DIR$0$0 == 0x00fe
                    00FE    315 _P1DIR	=	0x00fe
                    00FF    316 Ftwitch_ax$P2DIR$0$0 == 0x00ff
                    00FF    317 _P2DIR	=	0x00ff
                    FFFFD5D4    318 Ftwitch_ax$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    319 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    320 Ftwitch_ax$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    321 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    322 Ftwitch_ax$FADDR$0$0 == 0xffffadac
                    FFFFADAC    323 _FADDR	=	0xffffadac
                    FFFFBBBA    324 Ftwitch_ax$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    325 _ADC	=	0xffffbbba
                    FFFFDBDA    326 Ftwitch_ax$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    327 _T1CC0	=	0xffffdbda
                    FFFFDDDC    328 Ftwitch_ax$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    329 _T1CC1	=	0xffffdddc
                    FFFFDFDE    330 Ftwitch_ax$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    331 _T1CC2	=	0xffffdfde
                            332 ;--------------------------------------------------------
                            333 ; special function bits
                            334 ;--------------------------------------------------------
                            335 	.area RSEG    (ABS,DATA)
   0000                     336 	.org 0x0000
                    0080    337 Ftwitch_ax$P0_0$0$0 == 0x0080
                    0080    338 _P0_0	=	0x0080
                    0081    339 Ftwitch_ax$P0_1$0$0 == 0x0081
                    0081    340 _P0_1	=	0x0081
                    0082    341 Ftwitch_ax$P0_2$0$0 == 0x0082
                    0082    342 _P0_2	=	0x0082
                    0083    343 Ftwitch_ax$P0_3$0$0 == 0x0083
                    0083    344 _P0_3	=	0x0083
                    0084    345 Ftwitch_ax$P0_4$0$0 == 0x0084
                    0084    346 _P0_4	=	0x0084
                    0085    347 Ftwitch_ax$P0_5$0$0 == 0x0085
                    0085    348 _P0_5	=	0x0085
                    0086    349 Ftwitch_ax$P0_6$0$0 == 0x0086
                    0086    350 _P0_6	=	0x0086
                    0087    351 Ftwitch_ax$P0_7$0$0 == 0x0087
                    0087    352 _P0_7	=	0x0087
                    0088    353 Ftwitch_ax$_TCON_0$0$0 == 0x0088
                    0088    354 __TCON_0	=	0x0088
                    0089    355 Ftwitch_ax$RFTXRXIF$0$0 == 0x0089
                    0089    356 _RFTXRXIF	=	0x0089
                    008A    357 Ftwitch_ax$_TCON_2$0$0 == 0x008a
                    008A    358 __TCON_2	=	0x008a
                    008B    359 Ftwitch_ax$URX0IF$0$0 == 0x008b
                    008B    360 _URX0IF	=	0x008b
                    008C    361 Ftwitch_ax$_TCON_4$0$0 == 0x008c
                    008C    362 __TCON_4	=	0x008c
                    008D    363 Ftwitch_ax$ADCIF$0$0 == 0x008d
                    008D    364 _ADCIF	=	0x008d
                    008E    365 Ftwitch_ax$_TCON_6$0$0 == 0x008e
                    008E    366 __TCON_6	=	0x008e
                    008F    367 Ftwitch_ax$URX1IF$0$0 == 0x008f
                    008F    368 _URX1IF	=	0x008f
                    0090    369 Ftwitch_ax$P1_0$0$0 == 0x0090
                    0090    370 _P1_0	=	0x0090
                    0091    371 Ftwitch_ax$P1_1$0$0 == 0x0091
                    0091    372 _P1_1	=	0x0091
                    0092    373 Ftwitch_ax$P1_2$0$0 == 0x0092
                    0092    374 _P1_2	=	0x0092
                    0093    375 Ftwitch_ax$P1_3$0$0 == 0x0093
                    0093    376 _P1_3	=	0x0093
                    0094    377 Ftwitch_ax$P1_4$0$0 == 0x0094
                    0094    378 _P1_4	=	0x0094
                    0095    379 Ftwitch_ax$P1_5$0$0 == 0x0095
                    0095    380 _P1_5	=	0x0095
                    0096    381 Ftwitch_ax$P1_6$0$0 == 0x0096
                    0096    382 _P1_6	=	0x0096
                    0097    383 Ftwitch_ax$P1_7$0$0 == 0x0097
                    0097    384 _P1_7	=	0x0097
                    0098    385 Ftwitch_ax$ENCIF_0$0$0 == 0x0098
                    0098    386 _ENCIF_0	=	0x0098
                    0099    387 Ftwitch_ax$ENCIF_1$0$0 == 0x0099
                    0099    388 _ENCIF_1	=	0x0099
                    009A    389 Ftwitch_ax$_SOCON2$0$0 == 0x009a
                    009A    390 __SOCON2	=	0x009a
                    009B    391 Ftwitch_ax$_SOCON3$0$0 == 0x009b
                    009B    392 __SOCON3	=	0x009b
                    009C    393 Ftwitch_ax$_SOCON4$0$0 == 0x009c
                    009C    394 __SOCON4	=	0x009c
                    009D    395 Ftwitch_ax$_SOCON5$0$0 == 0x009d
                    009D    396 __SOCON5	=	0x009d
                    009E    397 Ftwitch_ax$_SOCON6$0$0 == 0x009e
                    009E    398 __SOCON6	=	0x009e
                    009F    399 Ftwitch_ax$_SOCON7$0$0 == 0x009f
                    009F    400 __SOCON7	=	0x009f
                    00A0    401 Ftwitch_ax$P2_0$0$0 == 0x00a0
                    00A0    402 _P2_0	=	0x00a0
                    00A1    403 Ftwitch_ax$P2_1$0$0 == 0x00a1
                    00A1    404 _P2_1	=	0x00a1
                    00A2    405 Ftwitch_ax$P2_2$0$0 == 0x00a2
                    00A2    406 _P2_2	=	0x00a2
                    00A3    407 Ftwitch_ax$P2_3$0$0 == 0x00a3
                    00A3    408 _P2_3	=	0x00a3
                    00A4    409 Ftwitch_ax$P2_4$0$0 == 0x00a4
                    00A4    410 _P2_4	=	0x00a4
                    00A5    411 Ftwitch_ax$P2_5$0$0 == 0x00a5
                    00A5    412 _P2_5	=	0x00a5
                    00A6    413 Ftwitch_ax$P2_6$0$0 == 0x00a6
                    00A6    414 _P2_6	=	0x00a6
                    00A7    415 Ftwitch_ax$P2_7$0$0 == 0x00a7
                    00A7    416 _P2_7	=	0x00a7
                    00A8    417 Ftwitch_ax$RFTXRXIE$0$0 == 0x00a8
                    00A8    418 _RFTXRXIE	=	0x00a8
                    00A9    419 Ftwitch_ax$ADCIE$0$0 == 0x00a9
                    00A9    420 _ADCIE	=	0x00a9
                    00AA    421 Ftwitch_ax$URX0IE$0$0 == 0x00aa
                    00AA    422 _URX0IE	=	0x00aa
                    00AB    423 Ftwitch_ax$URX1IE$0$0 == 0x00ab
                    00AB    424 _URX1IE	=	0x00ab
                    00AC    425 Ftwitch_ax$ENCIE$0$0 == 0x00ac
                    00AC    426 _ENCIE	=	0x00ac
                    00AD    427 Ftwitch_ax$STIE$0$0 == 0x00ad
                    00AD    428 _STIE	=	0x00ad
                    00AE    429 Ftwitch_ax$_IEN06$0$0 == 0x00ae
                    00AE    430 __IEN06	=	0x00ae
                    00AF    431 Ftwitch_ax$EA$0$0 == 0x00af
                    00AF    432 _EA	=	0x00af
                    00B8    433 Ftwitch_ax$DMAIE$0$0 == 0x00b8
                    00B8    434 _DMAIE	=	0x00b8
                    00B9    435 Ftwitch_ax$T1IE$0$0 == 0x00b9
                    00B9    436 _T1IE	=	0x00b9
                    00BA    437 Ftwitch_ax$T2IE$0$0 == 0x00ba
                    00BA    438 _T2IE	=	0x00ba
                    00BB    439 Ftwitch_ax$T3IE$0$0 == 0x00bb
                    00BB    440 _T3IE	=	0x00bb
                    00BC    441 Ftwitch_ax$T4IE$0$0 == 0x00bc
                    00BC    442 _T4IE	=	0x00bc
                    00BD    443 Ftwitch_ax$P0IE$0$0 == 0x00bd
                    00BD    444 _P0IE	=	0x00bd
                    00BE    445 Ftwitch_ax$_IEN16$0$0 == 0x00be
                    00BE    446 __IEN16	=	0x00be
                    00BF    447 Ftwitch_ax$_IEN17$0$0 == 0x00bf
                    00BF    448 __IEN17	=	0x00bf
                    00C0    449 Ftwitch_ax$DMAIF$0$0 == 0x00c0
                    00C0    450 _DMAIF	=	0x00c0
                    00C1    451 Ftwitch_ax$T1IF$0$0 == 0x00c1
                    00C1    452 _T1IF	=	0x00c1
                    00C2    453 Ftwitch_ax$T2IF$0$0 == 0x00c2
                    00C2    454 _T2IF	=	0x00c2
                    00C3    455 Ftwitch_ax$T3IF$0$0 == 0x00c3
                    00C3    456 _T3IF	=	0x00c3
                    00C4    457 Ftwitch_ax$T4IF$0$0 == 0x00c4
                    00C4    458 _T4IF	=	0x00c4
                    00C5    459 Ftwitch_ax$P0IF$0$0 == 0x00c5
                    00C5    460 _P0IF	=	0x00c5
                    00C6    461 Ftwitch_ax$_IRCON6$0$0 == 0x00c6
                    00C6    462 __IRCON6	=	0x00c6
                    00C7    463 Ftwitch_ax$STIF$0$0 == 0x00c7
                    00C7    464 _STIF	=	0x00c7
                    00D0    465 Ftwitch_ax$P$0$0 == 0x00d0
                    00D0    466 _P	=	0x00d0
                    00D1    467 Ftwitch_ax$F1$0$0 == 0x00d1
                    00D1    468 _F1	=	0x00d1
                    00D2    469 Ftwitch_ax$OV$0$0 == 0x00d2
                    00D2    470 _OV	=	0x00d2
                    00D3    471 Ftwitch_ax$RS0$0$0 == 0x00d3
                    00D3    472 _RS0	=	0x00d3
                    00D4    473 Ftwitch_ax$RS1$0$0 == 0x00d4
                    00D4    474 _RS1	=	0x00d4
                    00D5    475 Ftwitch_ax$F0$0$0 == 0x00d5
                    00D5    476 _F0	=	0x00d5
                    00D6    477 Ftwitch_ax$AC$0$0 == 0x00d6
                    00D6    478 _AC	=	0x00d6
                    00D7    479 Ftwitch_ax$CY$0$0 == 0x00d7
                    00D7    480 _CY	=	0x00d7
                    00D8    481 Ftwitch_ax$T3OVFIF$0$0 == 0x00d8
                    00D8    482 _T3OVFIF	=	0x00d8
                    00D9    483 Ftwitch_ax$T3CH0IF$0$0 == 0x00d9
                    00D9    484 _T3CH0IF	=	0x00d9
                    00DA    485 Ftwitch_ax$T3CH1IF$0$0 == 0x00da
                    00DA    486 _T3CH1IF	=	0x00da
                    00DB    487 Ftwitch_ax$T4OVFIF$0$0 == 0x00db
                    00DB    488 _T4OVFIF	=	0x00db
                    00DC    489 Ftwitch_ax$T4CH0IF$0$0 == 0x00dc
                    00DC    490 _T4CH0IF	=	0x00dc
                    00DD    491 Ftwitch_ax$T4CH1IF$0$0 == 0x00dd
                    00DD    492 _T4CH1IF	=	0x00dd
                    00DE    493 Ftwitch_ax$OVFIM$0$0 == 0x00de
                    00DE    494 _OVFIM	=	0x00de
                    00DF    495 Ftwitch_ax$_TIMIF7$0$0 == 0x00df
                    00DF    496 __TIMIF7	=	0x00df
                    00E0    497 Ftwitch_ax$ACC_0$0$0 == 0x00e0
                    00E0    498 _ACC_0	=	0x00e0
                    00E1    499 Ftwitch_ax$ACC_1$0$0 == 0x00e1
                    00E1    500 _ACC_1	=	0x00e1
                    00E2    501 Ftwitch_ax$ACC_2$0$0 == 0x00e2
                    00E2    502 _ACC_2	=	0x00e2
                    00E3    503 Ftwitch_ax$ACC_3$0$0 == 0x00e3
                    00E3    504 _ACC_3	=	0x00e3
                    00E4    505 Ftwitch_ax$ACC_4$0$0 == 0x00e4
                    00E4    506 _ACC_4	=	0x00e4
                    00E5    507 Ftwitch_ax$ACC_5$0$0 == 0x00e5
                    00E5    508 _ACC_5	=	0x00e5
                    00E6    509 Ftwitch_ax$ACC_6$0$0 == 0x00e6
                    00E6    510 _ACC_6	=	0x00e6
                    00E7    511 Ftwitch_ax$ACC_7$0$0 == 0x00e7
                    00E7    512 _ACC_7	=	0x00e7
                    00E8    513 Ftwitch_ax$P2IF$0$0 == 0x00e8
                    00E8    514 _P2IF	=	0x00e8
                    00E9    515 Ftwitch_ax$UTX0IF$0$0 == 0x00e9
                    00E9    516 _UTX0IF	=	0x00e9
                    00EA    517 Ftwitch_ax$UTX1IF$0$0 == 0x00ea
                    00EA    518 _UTX1IF	=	0x00ea
                    00EB    519 Ftwitch_ax$P1IF$0$0 == 0x00eb
                    00EB    520 _P1IF	=	0x00eb
                    00EC    521 Ftwitch_ax$WDTIF$0$0 == 0x00ec
                    00EC    522 _WDTIF	=	0x00ec
                    00ED    523 Ftwitch_ax$_IRCON25$0$0 == 0x00ed
                    00ED    524 __IRCON25	=	0x00ed
                    00EE    525 Ftwitch_ax$_IRCON26$0$0 == 0x00ee
                    00EE    526 __IRCON26	=	0x00ee
                    00EF    527 Ftwitch_ax$_IRCON27$0$0 == 0x00ef
                    00EF    528 __IRCON27	=	0x00ef
                    00F0    529 Ftwitch_ax$B_0$0$0 == 0x00f0
                    00F0    530 _B_0	=	0x00f0
                    00F1    531 Ftwitch_ax$B_1$0$0 == 0x00f1
                    00F1    532 _B_1	=	0x00f1
                    00F2    533 Ftwitch_ax$B_2$0$0 == 0x00f2
                    00F2    534 _B_2	=	0x00f2
                    00F3    535 Ftwitch_ax$B_3$0$0 == 0x00f3
                    00F3    536 _B_3	=	0x00f3
                    00F4    537 Ftwitch_ax$B_4$0$0 == 0x00f4
                    00F4    538 _B_4	=	0x00f4
                    00F5    539 Ftwitch_ax$B_5$0$0 == 0x00f5
                    00F5    540 _B_5	=	0x00f5
                    00F6    541 Ftwitch_ax$B_6$0$0 == 0x00f6
                    00F6    542 _B_6	=	0x00f6
                    00F7    543 Ftwitch_ax$B_7$0$0 == 0x00f7
                    00F7    544 _B_7	=	0x00f7
                    00F8    545 Ftwitch_ax$U1ACTIVE$0$0 == 0x00f8
                    00F8    546 _U1ACTIVE	=	0x00f8
                    00F9    547 Ftwitch_ax$U1TX_BYTE$0$0 == 0x00f9
                    00F9    548 _U1TX_BYTE	=	0x00f9
                    00FA    549 Ftwitch_ax$U1RX_BYTE$0$0 == 0x00fa
                    00FA    550 _U1RX_BYTE	=	0x00fa
                    00FB    551 Ftwitch_ax$U1ERR$0$0 == 0x00fb
                    00FB    552 _U1ERR	=	0x00fb
                    00FC    553 Ftwitch_ax$U1FE$0$0 == 0x00fc
                    00FC    554 _U1FE	=	0x00fc
                    00FD    555 Ftwitch_ax$U1SLAVE$0$0 == 0x00fd
                    00FD    556 _U1SLAVE	=	0x00fd
                    00FE    557 Ftwitch_ax$U1RE$0$0 == 0x00fe
                    00FE    558 _U1RE	=	0x00fe
                    00FF    559 Ftwitch_ax$U1MODE$0$0 == 0x00ff
                    00FF    560 _U1MODE	=	0x00ff
                            561 ;--------------------------------------------------------
                            562 ; overlayable register banks
                            563 ;--------------------------------------------------------
                            564 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     565 	.ds 8
                            566 ;--------------------------------------------------------
                            567 ; overlayable bit register bank
                            568 ;--------------------------------------------------------
                            569 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     570 bits:
   0023                     571 	.ds 1
                    8000    572 	b0 = bits[0]
                    8100    573 	b1 = bits[1]
                    8200    574 	b2 = bits[2]
                    8300    575 	b3 = bits[3]
                    8400    576 	b4 = bits[4]
                    8500    577 	b5 = bits[5]
                    8600    578 	b6 = bits[6]
                    8700    579 	b7 = bits[7]
                            580 ;--------------------------------------------------------
                            581 ; internal ram data
                            582 ;--------------------------------------------------------
                            583 	.area DSEG    (DATA)
                    0000    584 Ltwitch_ax.updateLeds$count$3$7==.
   003C                     585 _updateLeds_count_3_7:
   003C                     586 	.ds 1
                    0001    587 Ltwitch_ax.errorService$sloc0$1$0==.
   003D                     588 _errorService_sloc0_1_0:
   003D                     589 	.ds 4
                    0005    590 Ltwitch_ax.CmdrReadMsgs$sloc0$1$0==.
   0041                     591 _CmdrReadMsgs_sloc0_1_0:
   0041                     592 	.ds 3
                    0008    593 Ltwitch_ax.gaitRunnerPlay$sloc1$1$0==.
   0044                     594 _gaitRunnerPlay_sloc1_1_0:
   0044                     595 	.ds 2
                    000A    596 Ltwitch_ax.calcX$sloc0$1$0==.
   0046                     597 _calcX_sloc0_1_0:
   0046                     598 	.ds 4
                    000E    599 Ltwitch_ax.calcY$sloc0$1$0==.
   004A                     600 _calcY_sloc0_1_0:
   004A                     601 	.ds 4
                    0012    602 Ltwitch_ax.gaitRunnerProcess$sloc0$1$0==.
   004E                     603 _gaitRunnerProcess_sloc0_1_0:
   004E                     604 	.ds 3
                    0015    605 Ltwitch_ax.gaitRunnerProcess$sloc1$1$0==.
   0051                     606 _gaitRunnerProcess_sloc1_1_0:
   0051                     607 	.ds 1
                    0016    608 Ltwitch_ax.gaitRunnerProcess$sloc2$1$0==.
   0052                     609 _gaitRunnerProcess_sloc2_1_0:
   0052                     610 	.ds 3
                    0019    611 Ltwitch_ax.gaitRunnerProcess$sloc3$1$0==.
   0055                     612 _gaitRunnerProcess_sloc3_1_0:
   0055                     613 	.ds 3
                    001C    614 Ltwitch_ax.gaitRunnerProcess$sloc4$1$0==.
   0058                     615 _gaitRunnerProcess_sloc4_1_0:
   0058                     616 	.ds 2
                    001E    617 Ltwitch_ax.gaitRunnerProcess$sloc5$1$0==.
   005A                     618 _gaitRunnerProcess_sloc5_1_0:
   005A                     619 	.ds 3
                    0021    620 Ltwitch_ax.gaitRunnerProcess$sloc6$1$0==.
   005D                     621 _gaitRunnerProcess_sloc6_1_0:
   005D                     622 	.ds 1
                    0022    623 Ltwitch_ax.gaitRunnerProcess$sloc7$1$0==.
   005E                     624 _gaitRunnerProcess_sloc7_1_0:
   005E                     625 	.ds 3
                    0025    626 Ltwitch_ax.gaitRunnerProcess$sloc8$1$0==.
   0061                     627 _gaitRunnerProcess_sloc8_1_0:
   0061                     628 	.ds 3
                    0028    629 Ltwitch_ax.gaitRunnerProcess$sloc9$1$0==.
   0064                     630 _gaitRunnerProcess_sloc9_1_0:
   0064                     631 	.ds 4
                    002C    632 Ltwitch_ax.gaitRunnerProcess$sloc10$1$0==.
   0068                     633 _gaitRunnerProcess_sloc10_1_0:
   0068                     634 	.ds 4
                            635 ;--------------------------------------------------------
                            636 ; overlayable items in internal ram 
                            637 ;--------------------------------------------------------
                            638 	.area OSEG    (OVR,DATA)
                            639 ;--------------------------------------------------------
                            640 ; Stack segment in internal ram 
                            641 ;--------------------------------------------------------
                            642 	.area	SSEG	(DATA)
   0078                     643 __start__stack:
   0078                     644 	.ds	1
                            645 
                            646 ;--------------------------------------------------------
                            647 ; indirectly addressable internal ram data
                            648 ;--------------------------------------------------------
                            649 	.area ISEG    (DATA)
                            650 ;--------------------------------------------------------
                            651 ; absolute internal ram data
                            652 ;--------------------------------------------------------
                            653 	.area IABS    (ABS,DATA)
                            654 	.area IABS    (ABS,DATA)
                            655 ;--------------------------------------------------------
                            656 ; bit data
                            657 ;--------------------------------------------------------
                            658 	.area BSEG    (BIT)
                    0000    659 G$uartRxDisabled$0$0==.
   0000                     660 _uartRxDisabled::
   0000                     661 	.ds 1
                    0001    662 G$framingErrorActive$0$0==.
   0001                     663 _framingErrorActive::
   0001                     664 	.ds 1
                    0002    665 G$errorOccurredRecently$0$0==.
   0002                     666 _errorOccurredRecently::
   0002                     667 	.ds 1
                    0003    668 Ltwitch_ax.updateLeds$dimYellowLed$1$1==.
   0003                     669 _updateLeds_dimYellowLed_1_1:
   0003                     670 	.ds 1
                    0004    671 Ltwitch_ax.ioTxSignals$sloc0$1$0==.
   0004                     672 _ioTxSignals_sloc0_1_0:
   0004                     673 	.ds 1
                    0005    674 Ltwitch_ax.gaitRunnerPlay$sloc0$1$0==.
   0005                     675 _gaitRunnerPlay_sloc0_1_0:
   0005                     676 	.ds 1
                            677 ;--------------------------------------------------------
                            678 ; paged external ram data
                            679 ;--------------------------------------------------------
                            680 	.area PSEG    (PAG,XDATA)
                    0000    681 G$vals$0$0==.
   F033                     682 _vals::
   F033                     683 	.ds 7
                    0007    684 G$index_cmdr$0$0==.
   F03A                     685 _index_cmdr::
   F03A                     686 	.ds 1
                    0008    687 G$checksum_cmdr$0$0==.
   F03B                     688 _checksum_cmdr::
   F03B                     689 	.ds 1
                    0009    690 G$walkV$0$0==.
   F03C                     691 _walkV::
   F03C                     692 	.ds 1
                    000A    693 G$walkH$0$0==.
   F03D                     694 _walkH::
   F03D                     695 	.ds 1
                    000B    696 G$lookV$0$0==.
   F03E                     697 _lookV::
   F03E                     698 	.ds 1
                    000C    699 G$lookH$0$0==.
   F03F                     700 _lookH::
   F03F                     701 	.ds 1
                    000D    702 G$lastErrorTime$0$0==.
   F040                     703 _lastErrorTime::
   F040                     704 	.ds 1
                    000E    705 G$g8speed$0$0==.
   F041                     706 _g8speed::
   F041                     707 	.ds 2
                    0010    708 G$g8playbackDir$0$0==.
   F043                     709 _g8playbackDir::
   F043                     710 	.ds 1
                    0011    711 G$g8repeatCount$0$0==.
   F044                     712 _g8repeatCount::
   F044                     713 	.ds 1
                    0012    714 G$currentPos$0$0==.
   F045                     715 _currentPos::
   F045                     716 	.ds 1
                    0013    717 Ltwitch_ax.updateLeds$lastRadioActivityTime$1$1==.
   F046                     718 _updateLeds_lastRadioActivityTime_1_1:
   F046                     719 	.ds 2
                    0015    720 Ltwitch_ax.ioTxSignals$signals$1$1==.
   F048                     721 _ioTxSignals_signals_1_1:
   F048                     722 	.ds 1
                    0016    723 Ltwitch_ax.ioTxSignals$nTrstPulseStartTime$1$1==.
   F049                     724 _ioTxSignals_nTrstPulseStartTime_1_1:
   F049                     725 	.ds 1
                    0017    726 Ltwitch_ax.ioTxSignals$lastSignals$1$1==.
   F04A                     727 _ioTxSignals_lastSignals_1_1:
   F04A                     728 	.ds 1
                    0018    729 Ltwitch_ax.errorService$lastRxLowTime$1$1==.
   F04B                     730 _errorService_lastRxLowTime_1_1:
   F04B                     731 	.ds 1
                    0019    732 Ltwitch_ax.CmdrReadMsgs$desiredDir$1$1==.
   F04C                     733 _CmdrReadMsgs_PARM_2:
   F04C                     734 	.ds 3
                    001C    735 Ltwitch_ax.CmdrReadMsgs$desiredSpeed$1$1==.
   F04F                     736 _CmdrReadMsgs_PARM_3:
   F04F                     737 	.ds 3
                    001F    738 Ltwitch_ax.gaitRunnerPlay$animation$1$1==.
   F052                     739 _gaitRunnerPlay_PARM_2:
   F052                     740 	.ds 1
                    0020    741 Ltwitch_ax.gaitRunnerPlay$loopSpeed$1$1==.
   F053                     742 _gaitRunnerPlay_PARM_3:
   F053                     743 	.ds 2
                    0022    744 Ltwitch_ax.gaitRunnerPlay$speed$1$1==.
   F055                     745 _gaitRunnerPlay_PARM_4:
   F055                     746 	.ds 1
                    0023    747 Ltwitch_ax.gaitRunnerPlay$repeatCount$1$1==.
   F056                     748 _gaitRunnerPlay_PARM_5:
   F056                     749 	.ds 1
                    0024    750 Ltwitch_ax.gaitRunnerPlay$now$1$1==.
   F057                     751 _gaitRunnerPlay_now_1_1:
   F057                     752 	.ds 4
                    0028    753 Ltwitch_ax.calcX$t1$1$1==.
   F05B                     754 _calcX_PARM_2:
   F05B                     755 	.ds 4
                    002C    756 Ltwitch_ax.calcX$a$1$1==.
   F05F                     757 _calcX_a_1_1:
   F05F                     758 	.ds 2
                    002E    759 Ltwitch_ax.calcX$c$1$1==.
   F061                     760 _calcX_c_1_1:
   F061                     761 	.ds 2
                    0030    762 Ltwitch_ax.calcX$t2$1$1==.
   F063                     763 _calcX_t2_1_1:
   F063                     764 	.ds 4
                    0034    765 Ltwitch_ax.calcX$t3$1$1==.
   F067                     766 _calcX_t3_1_1:
   F067                     767 	.ds 4
                    0038    768 Ltwitch_ax.calcY$t1$1$1==.
   F06B                     769 _calcY_PARM_2:
   F06B                     770 	.ds 4
                    003C    771 Ltwitch_ax.calcY$a$1$1==.
   F06F                     772 _calcY_a_1_1:
   F06F                     773 	.ds 2
                    003E    774 Ltwitch_ax.calcY$b$1$1==.
   F071                     775 _calcY_b_1_1:
   F071                     776 	.ds 2
                    0040    777 Ltwitch_ax.calcY$c$1$1==.
   F073                     778 _calcY_c_1_1:
   F073                     779 	.ds 2
                    0042    780 Ltwitch_ax.calcY$d$1$1==.
   F075                     781 _calcY_d_1_1:
   F075                     782 	.ds 1
                    0043    783 Ltwitch_ax.calcY$t2$1$1==.
   F076                     784 _calcY_t2_1_1:
   F076                     785 	.ds 4
                    0047    786 Ltwitch_ax.calcY$t3$1$1==.
   F07A                     787 _calcY_t3_1_1:
   F07A                     788 	.ds 4
                    004B    789 Ltwitch_ax.gaitRunnerProcess$runner$1$1==.
   F07E                     790 _gaitRunnerProcess_runner_1_1:
   F07E                     791 	.ds 3
                    004E    792 Ltwitch_ax.gaitRunnerProcess$now$1$1==.
   F081                     793 _gaitRunnerProcess_now_1_1:
   F081                     794 	.ds 4
                    0052    795 Ltwitch_ax.gaitRunnerProcess$interval$1$1==.
   F085                     796 _gaitRunnerProcess_interval_1_1:
   F085                     797 	.ds 2
                    0054    798 Ltwitch_ax.gaitRunnerProcess$animation$1$1==.
   F087                     799 _gaitRunnerProcess_animation_1_1:
   F087                     800 	.ds 3
                    0057    801 Ltwitch_ax.gaitRunnerProcess$currentTime$1$1==.
   F08A                     802 _gaitRunnerProcess_currentTime_1_1:
   F08A                     803 	.ds 2
                    0059    804 Ltwitch_ax.gaitRunnerProcess$frameTime$1$1==.
   F08C                     805 _gaitRunnerProcess_frameTime_1_1:
   F08C                     806 	.ds 2
                    005B    807 Ltwitch_ax.gaitRunnerProcess$frameEndTime$1$1==.
   F08E                     808 _gaitRunnerProcess_frameEndTime_1_1:
   F08E                     809 	.ds 2
                    005D    810 Ltwitch_ax.gaitRunnerProcess$frame$1$1==.
   F090                     811 _gaitRunnerProcess_frame_1_1:
   F090                     812 	.ds 3
                    0060    813 Ltwitch_ax.gaitRunnerProcess$i$1$1==.
   F093                     814 _gaitRunnerProcess_i_1_1:
   F093                     815 	.ds 1
                    0061    816 Ltwitch_ax.gaitRunnerProcess$frameTimeOffset$1$1==.
   F094                     817 _gaitRunnerProcess_frameTimeOffset_1_1:
   F094                     818 	.ds 2
                    0063    819 Ltwitch_ax.gaitRunnerProcess$distanceGuess$1$1==.
   F096                     820 _gaitRunnerProcess_distanceGuess_1_1:
   F096                     821 	.ds 4
                    0067    822 Ltwitch_ax.gaitRunnerProcess$distanceMax$2$24==.
   F09A                     823 _gaitRunnerProcess_distanceMax_2_24:
   F09A                     824 	.ds 4
                    006B    825 Ltwitch_ax.gaitRunnerProcess$distance$2$24==.
   F09E                     826 _gaitRunnerProcess_distance_2_24:
   F09E                     827 	.ds 4
                    006F    828 Ltwitch_ax.gaitRunnerProcess$iterations$2$24==.
   F0A2                     829 _gaitRunnerProcess_iterations_2_24:
   F0A2                     830 	.ds 1
                    0070    831 Ltwitch_ax.gaitRunnerProcess$speeds$2$28==.
   F0A3                     832 _gaitRunnerProcess_speeds_2_28:
   F0A3                     833 	.ds 8
                    0078    834 Ltwitch_ax.gaitRunnerProcess$servo$3$29==.
   F0AB                     835 _gaitRunnerProcess_servo_3_29:
   F0AB                     836 	.ds 1
                    0079    837 Ltwitch_ax.gaitRunnerProcess$speed$3$29==.
   F0AC                     838 _gaitRunnerProcess_speed_3_29:
   F0AC                     839 	.ds 2
                    007B    840 Ltwitch_ax.gaitRunnerProcess$speedFactor$4$30==.
   F0AE                     841 _gaitRunnerProcess_speedFactor_4_30:
   F0AE                     842 	.ds 4
                    007F    843 Ltwitch_ax.main$desiredGait$1$1==.
   F0B2                     844 _main_desiredGait_1_1:
   F0B2                     845 	.ds 1
                    0080    846 Ltwitch_ax.main$desiredDir$1$1==.
   F0B3                     847 _main_desiredDir_1_1:
   F0B3                     848 	.ds 1
                    0081    849 Ltwitch_ax.main$desiredSpeed$1$1==.
   F0B4                     850 _main_desiredSpeed_1_1:
   F0B4                     851 	.ds 1
                    0082    852 Ltwitch_ax.main$gait$1$1==.
   F0B5                     853 _main_gait_1_1:
   F0B5                     854 	.ds 20
                            855 ;--------------------------------------------------------
                            856 ; external ram data
                            857 ;--------------------------------------------------------
                            858 	.area XSEG    (XDATA)
                    DF00    859 Ftwitch_ax$SYNC1$0$0 == 0xdf00
                    DF00    860 _SYNC1	=	0xdf00
                    DF01    861 Ftwitch_ax$SYNC0$0$0 == 0xdf01
                    DF01    862 _SYNC0	=	0xdf01
                    DF02    863 Ftwitch_ax$PKTLEN$0$0 == 0xdf02
                    DF02    864 _PKTLEN	=	0xdf02
                    DF03    865 Ftwitch_ax$PKTCTRL1$0$0 == 0xdf03
                    DF03    866 _PKTCTRL1	=	0xdf03
                    DF04    867 Ftwitch_ax$PKTCTRL0$0$0 == 0xdf04
                    DF04    868 _PKTCTRL0	=	0xdf04
                    DF05    869 Ftwitch_ax$ADDR$0$0 == 0xdf05
                    DF05    870 _ADDR	=	0xdf05
                    DF06    871 Ftwitch_ax$CHANNR$0$0 == 0xdf06
                    DF06    872 _CHANNR	=	0xdf06
                    DF07    873 Ftwitch_ax$FSCTRL1$0$0 == 0xdf07
                    DF07    874 _FSCTRL1	=	0xdf07
                    DF08    875 Ftwitch_ax$FSCTRL0$0$0 == 0xdf08
                    DF08    876 _FSCTRL0	=	0xdf08
                    DF09    877 Ftwitch_ax$FREQ2$0$0 == 0xdf09
                    DF09    878 _FREQ2	=	0xdf09
                    DF0A    879 Ftwitch_ax$FREQ1$0$0 == 0xdf0a
                    DF0A    880 _FREQ1	=	0xdf0a
                    DF0B    881 Ftwitch_ax$FREQ0$0$0 == 0xdf0b
                    DF0B    882 _FREQ0	=	0xdf0b
                    DF0C    883 Ftwitch_ax$MDMCFG4$0$0 == 0xdf0c
                    DF0C    884 _MDMCFG4	=	0xdf0c
                    DF0D    885 Ftwitch_ax$MDMCFG3$0$0 == 0xdf0d
                    DF0D    886 _MDMCFG3	=	0xdf0d
                    DF0E    887 Ftwitch_ax$MDMCFG2$0$0 == 0xdf0e
                    DF0E    888 _MDMCFG2	=	0xdf0e
                    DF0F    889 Ftwitch_ax$MDMCFG1$0$0 == 0xdf0f
                    DF0F    890 _MDMCFG1	=	0xdf0f
                    DF10    891 Ftwitch_ax$MDMCFG0$0$0 == 0xdf10
                    DF10    892 _MDMCFG0	=	0xdf10
                    DF11    893 Ftwitch_ax$DEVIATN$0$0 == 0xdf11
                    DF11    894 _DEVIATN	=	0xdf11
                    DF12    895 Ftwitch_ax$MCSM2$0$0 == 0xdf12
                    DF12    896 _MCSM2	=	0xdf12
                    DF13    897 Ftwitch_ax$MCSM1$0$0 == 0xdf13
                    DF13    898 _MCSM1	=	0xdf13
                    DF14    899 Ftwitch_ax$MCSM0$0$0 == 0xdf14
                    DF14    900 _MCSM0	=	0xdf14
                    DF15    901 Ftwitch_ax$FOCCFG$0$0 == 0xdf15
                    DF15    902 _FOCCFG	=	0xdf15
                    DF16    903 Ftwitch_ax$BSCFG$0$0 == 0xdf16
                    DF16    904 _BSCFG	=	0xdf16
                    DF17    905 Ftwitch_ax$AGCCTRL2$0$0 == 0xdf17
                    DF17    906 _AGCCTRL2	=	0xdf17
                    DF18    907 Ftwitch_ax$AGCCTRL1$0$0 == 0xdf18
                    DF18    908 _AGCCTRL1	=	0xdf18
                    DF19    909 Ftwitch_ax$AGCCTRL0$0$0 == 0xdf19
                    DF19    910 _AGCCTRL0	=	0xdf19
                    DF1A    911 Ftwitch_ax$FREND1$0$0 == 0xdf1a
                    DF1A    912 _FREND1	=	0xdf1a
                    DF1B    913 Ftwitch_ax$FREND0$0$0 == 0xdf1b
                    DF1B    914 _FREND0	=	0xdf1b
                    DF1C    915 Ftwitch_ax$FSCAL3$0$0 == 0xdf1c
                    DF1C    916 _FSCAL3	=	0xdf1c
                    DF1D    917 Ftwitch_ax$FSCAL2$0$0 == 0xdf1d
                    DF1D    918 _FSCAL2	=	0xdf1d
                    DF1E    919 Ftwitch_ax$FSCAL1$0$0 == 0xdf1e
                    DF1E    920 _FSCAL1	=	0xdf1e
                    DF1F    921 Ftwitch_ax$FSCAL0$0$0 == 0xdf1f
                    DF1F    922 _FSCAL0	=	0xdf1f
                    DF23    923 Ftwitch_ax$TEST2$0$0 == 0xdf23
                    DF23    924 _TEST2	=	0xdf23
                    DF24    925 Ftwitch_ax$TEST1$0$0 == 0xdf24
                    DF24    926 _TEST1	=	0xdf24
                    DF25    927 Ftwitch_ax$TEST0$0$0 == 0xdf25
                    DF25    928 _TEST0	=	0xdf25
                    DF2E    929 Ftwitch_ax$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    930 _PA_TABLE0	=	0xdf2e
                    DF2F    931 Ftwitch_ax$IOCFG2$0$0 == 0xdf2f
                    DF2F    932 _IOCFG2	=	0xdf2f
                    DF30    933 Ftwitch_ax$IOCFG1$0$0 == 0xdf30
                    DF30    934 _IOCFG1	=	0xdf30
                    DF31    935 Ftwitch_ax$IOCFG0$0$0 == 0xdf31
                    DF31    936 _IOCFG0	=	0xdf31
                    DF36    937 Ftwitch_ax$PARTNUM$0$0 == 0xdf36
                    DF36    938 _PARTNUM	=	0xdf36
                    DF37    939 Ftwitch_ax$VERSION$0$0 == 0xdf37
                    DF37    940 _VERSION	=	0xdf37
                    DF38    941 Ftwitch_ax$FREQEST$0$0 == 0xdf38
                    DF38    942 _FREQEST	=	0xdf38
                    DF39    943 Ftwitch_ax$LQI$0$0 == 0xdf39
                    DF39    944 _LQI	=	0xdf39
                    DF3A    945 Ftwitch_ax$RSSI$0$0 == 0xdf3a
                    DF3A    946 _RSSI	=	0xdf3a
                    DF3B    947 Ftwitch_ax$MARCSTATE$0$0 == 0xdf3b
                    DF3B    948 _MARCSTATE	=	0xdf3b
                    DF3C    949 Ftwitch_ax$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    950 _PKTSTATUS	=	0xdf3c
                    DF3D    951 Ftwitch_ax$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    952 _VCO_VC_DAC	=	0xdf3d
                    DF40    953 Ftwitch_ax$I2SCFG0$0$0 == 0xdf40
                    DF40    954 _I2SCFG0	=	0xdf40
                    DF41    955 Ftwitch_ax$I2SCFG1$0$0 == 0xdf41
                    DF41    956 _I2SCFG1	=	0xdf41
                    DF42    957 Ftwitch_ax$I2SDATL$0$0 == 0xdf42
                    DF42    958 _I2SDATL	=	0xdf42
                    DF43    959 Ftwitch_ax$I2SDATH$0$0 == 0xdf43
                    DF43    960 _I2SDATH	=	0xdf43
                    DF44    961 Ftwitch_ax$I2SWCNT$0$0 == 0xdf44
                    DF44    962 _I2SWCNT	=	0xdf44
                    DF45    963 Ftwitch_ax$I2SSTAT$0$0 == 0xdf45
                    DF45    964 _I2SSTAT	=	0xdf45
                    DF46    965 Ftwitch_ax$I2SCLKF0$0$0 == 0xdf46
                    DF46    966 _I2SCLKF0	=	0xdf46
                    DF47    967 Ftwitch_ax$I2SCLKF1$0$0 == 0xdf47
                    DF47    968 _I2SCLKF1	=	0xdf47
                    DF48    969 Ftwitch_ax$I2SCLKF2$0$0 == 0xdf48
                    DF48    970 _I2SCLKF2	=	0xdf48
                    DE00    971 Ftwitch_ax$USBADDR$0$0 == 0xde00
                    DE00    972 _USBADDR	=	0xde00
                    DE01    973 Ftwitch_ax$USBPOW$0$0 == 0xde01
                    DE01    974 _USBPOW	=	0xde01
                    DE02    975 Ftwitch_ax$USBIIF$0$0 == 0xde02
                    DE02    976 _USBIIF	=	0xde02
                    DE04    977 Ftwitch_ax$USBOIF$0$0 == 0xde04
                    DE04    978 _USBOIF	=	0xde04
                    DE06    979 Ftwitch_ax$USBCIF$0$0 == 0xde06
                    DE06    980 _USBCIF	=	0xde06
                    DE07    981 Ftwitch_ax$USBIIE$0$0 == 0xde07
                    DE07    982 _USBIIE	=	0xde07
                    DE09    983 Ftwitch_ax$USBOIE$0$0 == 0xde09
                    DE09    984 _USBOIE	=	0xde09
                    DE0B    985 Ftwitch_ax$USBCIE$0$0 == 0xde0b
                    DE0B    986 _USBCIE	=	0xde0b
                    DE0C    987 Ftwitch_ax$USBFRML$0$0 == 0xde0c
                    DE0C    988 _USBFRML	=	0xde0c
                    DE0D    989 Ftwitch_ax$USBFRMH$0$0 == 0xde0d
                    DE0D    990 _USBFRMH	=	0xde0d
                    DE0E    991 Ftwitch_ax$USBINDEX$0$0 == 0xde0e
                    DE0E    992 _USBINDEX	=	0xde0e
                    DE10    993 Ftwitch_ax$USBMAXI$0$0 == 0xde10
                    DE10    994 _USBMAXI	=	0xde10
                    DE11    995 Ftwitch_ax$USBCSIL$0$0 == 0xde11
                    DE11    996 _USBCSIL	=	0xde11
                    DE12    997 Ftwitch_ax$USBCSIH$0$0 == 0xde12
                    DE12    998 _USBCSIH	=	0xde12
                    DE13    999 Ftwitch_ax$USBMAXO$0$0 == 0xde13
                    DE13   1000 _USBMAXO	=	0xde13
                    DE14   1001 Ftwitch_ax$USBCSOL$0$0 == 0xde14
                    DE14   1002 _USBCSOL	=	0xde14
                    DE15   1003 Ftwitch_ax$USBCSOH$0$0 == 0xde15
                    DE15   1004 _USBCSOH	=	0xde15
                    DE16   1005 Ftwitch_ax$USBCNTL$0$0 == 0xde16
                    DE16   1006 _USBCNTL	=	0xde16
                    DE17   1007 Ftwitch_ax$USBCNTH$0$0 == 0xde17
                    DE17   1008 _USBCNTH	=	0xde17
                    DE20   1009 Ftwitch_ax$USBF0$0$0 == 0xde20
                    DE20   1010 _USBF0	=	0xde20
                    DE22   1011 Ftwitch_ax$USBF1$0$0 == 0xde22
                    DE22   1012 _USBF1	=	0xde22
                    DE24   1013 Ftwitch_ax$USBF2$0$0 == 0xde24
                    DE24   1014 _USBF2	=	0xde24
                    DE26   1015 Ftwitch_ax$USBF3$0$0 == 0xde26
                    DE26   1016 _USBF3	=	0xde26
                    DE28   1017 Ftwitch_ax$USBF4$0$0 == 0xde28
                    DE28   1018 _USBF4	=	0xde28
                    DE2A   1019 Ftwitch_ax$USBF5$0$0 == 0xde2a
                    DE2A   1020 _USBF5	=	0xde2a
                           1021 ;--------------------------------------------------------
                           1022 ; absolute external ram data
                           1023 ;--------------------------------------------------------
                           1024 	.area XABS    (ABS,XDATA)
                           1025 ;--------------------------------------------------------
                           1026 ; external initialized ram data
                           1027 ;--------------------------------------------------------
                           1028 	.area XISEG   (XDATA)
                           1029 	.area HOME    (CODE)
                           1030 	.area GSINIT0 (CODE)
                           1031 	.area GSINIT1 (CODE)
                           1032 	.area GSINIT2 (CODE)
                           1033 	.area GSINIT3 (CODE)
                           1034 	.area GSINIT4 (CODE)
                           1035 	.area GSINIT5 (CODE)
                           1036 	.area GSINIT  (CODE)
                           1037 	.area GSFINAL (CODE)
                           1038 	.area CSEG    (CODE)
                           1039 ;--------------------------------------------------------
                           1040 ; interrupt vector 
                           1041 ;--------------------------------------------------------
                           1042 	.area HOME    (CODE)
   0400                    1043 __interrupt_vect:
   0400 02 04 8B           1044 	ljmp	__sdcc_gsinit_startup
   0403 32                 1045 	reti
   0404                    1046 	.ds	7
   040B 32                 1047 	reti
   040C                    1048 	.ds	7
   0413 32                 1049 	reti
   0414                    1050 	.ds	7
   041B 02 2C 99           1051 	ljmp	_ISR_URX1
   041E                    1052 	.ds	5
   0423 32                 1053 	reti
   0424                    1054 	.ds	7
   042B 32                 1055 	reti
   042C                    1056 	.ds	7
   0433 32                 1057 	reti
   0434                    1058 	.ds	7
   043B 32                 1059 	reti
   043C                    1060 	.ds	7
   0443 32                 1061 	reti
   0444                    1062 	.ds	7
   044B 32                 1063 	reti
   044C                    1064 	.ds	7
   0453 32                 1065 	reti
   0454                    1066 	.ds	7
   045B 32                 1067 	reti
   045C                    1068 	.ds	7
   0463 02 3B 66           1069 	ljmp	_ISR_T4
   0466                    1070 	.ds	5
   046B 32                 1071 	reti
   046C                    1072 	.ds	7
   0473 02 2C 5B           1073 	ljmp	_ISR_UTX1
   0476                    1074 	.ds	5
   047B 32                 1075 	reti
   047C                    1076 	.ds	7
   0483 02 30 68           1077 	ljmp	_ISR_RF
                           1078 ;--------------------------------------------------------
                           1079 ; global & static initialisations
                           1080 ;--------------------------------------------------------
                           1081 	.area HOME    (CODE)
                           1082 	.area GSINIT  (CODE)
                           1083 	.area GSFINAL (CODE)
                           1084 	.area GSINIT  (CODE)
                           1085 	.globl __sdcc_gsinit_startup
                           1086 	.globl __sdcc_program_startup
                           1087 	.globl __start__stack
                           1088 	.globl __mcs51_genXINIT
                           1089 	.globl __mcs51_genXRAMCLEAR
                           1090 	.globl __mcs51_genRAMCLEAR
                           1091 ;------------------------------------------------------------
                           1092 ;Allocation info for local variables in function 'updateLeds'
                           1093 ;------------------------------------------------------------
                           1094 ;count                     Allocated with name '_updateLeds_count_3_7'
                           1095 ;------------------------------------------------------------
                    0000   1096 	G$updateLeds$0$0 ==.
                    0000   1097 	C$twitch_ax.c$131$2$14 ==.
                           1098 ;	apps/twitch_ax/twitch_ax.c:131: static BIT dimYellowLed = 0;
   04E8 C2 03              1099 	clr	_updateLeds_dimYellowLed_1_1
                    0002   1100 	G$main$0$0 ==.
                    0002   1101 	C$twitch_ax.c$98$1$1 ==.
                           1102 ;	apps/twitch_ax/twitch_ax.c:98: BIT uartRxDisabled = 0;
   04EA C2 00              1103 	clr	_uartRxDisabled
                    0004   1104 	G$main$0$0 ==.
                    0004   1105 	C$twitch_ax.c$102$1$1 ==.
                           1106 ;	apps/twitch_ax/twitch_ax.c:102: BIT framingErrorActive = 0;
   04EC C2 01              1107 	clr	_framingErrorActive
                    0006   1108 	G$main$0$0 ==.
                    0006   1109 	C$twitch_ax.c$104$1$1 ==.
                           1110 ;	apps/twitch_ax/twitch_ax.c:104: BIT errorOccurredRecently = 0;
   04EE C2 02              1111 	clr	_errorOccurredRecently
                    0008   1112 	G$main$0$0 ==.
                    0008   1113 	C$twitch_ax.c$118$1$1 ==.
                           1114 ;	apps/twitch_ax/twitch_ax.c:118: uint16 g8speed = 25;
   04F0 78 41              1115 	mov	r0,#_g8speed
   04F2 74 19              1116 	mov	a,#0x19
   04F4 F2                 1117 	movx	@r0,a
   04F5 08                 1118 	inc	r0
   04F6 E4                 1119 	clr	a
   04F7 F2                 1120 	movx	@r0,a
                    0010   1121 	G$main$0$0 ==.
                    0010   1122 	C$twitch_ax.c$119$1$1 ==.
                           1123 ;	apps/twitch_ax/twitch_ax.c:119: int8 g8playbackDir = 1; // value should only ever be -1 or 1.
   04F8 78 43              1124 	mov	r0,#_g8playbackDir
   04FA 74 01              1125 	mov	a,#0x01
   04FC F2                 1126 	movx	@r0,a
                    0015   1127 	G$main$0$0 ==.
                    0015   1128 	C$twitch_ax.c$120$1$1 ==.
                           1129 ;	apps/twitch_ax/twitch_ax.c:120: int8 g8repeatCount = 0;
   04FD 78 44              1130 	mov	r0,#_g8repeatCount
   04FF E4                 1131 	clr	a
   0500 F2                 1132 	movx	@r0,a
                    0019   1133 	G$main$0$0 ==.
                    0019   1134 	C$twitch_ax.c$122$1$1 ==.
                           1135 ;	apps/twitch_ax/twitch_ax.c:122: uint8 currentPos = SIT_POS;
   0501 78 45              1136 	mov	r0,#_currentPos
   0503 74 65              1137 	mov	a,#0x65
   0505 F2                 1138 	movx	@r0,a
                           1139 	.area GSFINAL (CODE)
   0552 02 04 86           1140 	ljmp	__sdcc_program_startup
                           1141 ;--------------------------------------------------------
                           1142 ; Home
                           1143 ;--------------------------------------------------------
                           1144 	.area HOME    (CODE)
                           1145 	.area HOME    (CODE)
   0486                    1146 __sdcc_program_startup:
   0486 12 27 DD           1147 	lcall	_main
                           1148 ;	return from main will lock up
   0489 80 FE              1149 	sjmp .
                           1150 ;--------------------------------------------------------
                           1151 ; code
                           1152 ;--------------------------------------------------------
                           1153 	.area CSEG    (CODE)
                           1154 ;------------------------------------------------------------
                           1155 ;Allocation info for local variables in function 'gaitRunnerStop'
                           1156 ;------------------------------------------------------------
                    0000   1157 	Ftwitch_ax$gaitRunnerStop$0$0 ==.
                    0000   1158 	C$GaitRunner.h$163$0$0 ==.
                           1159 ;	apps/twitch_ax/GaitRunner.h:163: static __inline__ void gaitRunnerStop(G8_RUNNER* runner){
                           1160 ;	-----------------------------------------
                           1161 ;	 function gaitRunnerStop
                           1162 ;	-----------------------------------------
   0BBB                    1163 _gaitRunnerStop:
                    0007   1164 	ar7 = 0x07
                    0006   1165 	ar6 = 0x06
                    0005   1166 	ar5 = 0x05
                    0004   1167 	ar4 = 0x04
                    0003   1168 	ar3 = 0x03
                    0002   1169 	ar2 = 0x02
                    0001   1170 	ar1 = 0x01
                    0000   1171 	ar0 = 0x00
   0BBB AD 82              1172 	mov	r5,dpl
   0BBD AE 83              1173 	mov	r6,dph
   0BBF AF F0              1174 	mov	r7,b
                    0006   1175 	C$GaitRunner.h$164$1$1 ==.
                           1176 ;	apps/twitch_ax/GaitRunner.h:164: runner->repeatCount = (runner->speed < 0) ? -1 : 1;
   0BC1 74 05              1177 	mov	a,#0x05
   0BC3 2D                 1178 	add	a,r5
   0BC4 FA                 1179 	mov	r2,a
   0BC5 E4                 1180 	clr	a
   0BC6 3E                 1181 	addc	a,r6
   0BC7 FB                 1182 	mov	r3,a
   0BC8 8F 04              1183 	mov	ar4,r7
   0BCA 74 10              1184 	mov	a,#0x10
   0BCC 2D                 1185 	add	a,r5
   0BCD FD                 1186 	mov	r5,a
   0BCE E4                 1187 	clr	a
   0BCF 3E                 1188 	addc	a,r6
   0BD0 FE                 1189 	mov	r6,a
   0BD1 8D 82              1190 	mov	dpl,r5
   0BD3 8E 83              1191 	mov	dph,r6
   0BD5 8F F0              1192 	mov	b,r7
   0BD7 12 42 C6           1193 	lcall	__gptrget
   0BDA FD                 1194 	mov	r5,a
   0BDB 30 E7 04           1195 	jnb	acc.7,00103$
   0BDE 7F FF              1196 	mov	r7,#0xFF
   0BE0 80 02              1197 	sjmp	00104$
   0BE2                    1198 00103$:
   0BE2 7F 01              1199 	mov	r7,#0x01
   0BE4                    1200 00104$:
   0BE4 8A 82              1201 	mov	dpl,r2
   0BE6 8B 83              1202 	mov	dph,r3
   0BE8 8C F0              1203 	mov	b,r4
   0BEA EF                 1204 	mov	a,r7
   0BEB 12 36 56           1205 	lcall	__gptrput
                    0033   1206 	C$GaitRunner.h$165$1$1 ==.
                    0033   1207 	XFtwitch_ax$gaitRunnerStop$0$0 ==.
   0BEE 22                 1208 	ret
                           1209 ;------------------------------------------------------------
                           1210 ;Allocation info for local variables in function 'gaitRunnerIsPlaying'
                           1211 ;------------------------------------------------------------
                    0034   1212 	Ftwitch_ax$gaitRunnerIsPlaying$0$0 ==.
                    0034   1213 	C$GaitRunner.h$174$1$1 ==.
                           1214 ;	apps/twitch_ax/GaitRunner.h:174: static __inline__ boolean gaitRunnerIsPlaying(const G8_RUNNER* runner){
                           1215 ;	-----------------------------------------
                           1216 ;	 function gaitRunnerIsPlaying
                           1217 ;	-----------------------------------------
   0BEF                    1218 _gaitRunnerIsPlaying:
   0BEF AD 82              1219 	mov	r5,dpl
   0BF1 AE 83              1220 	mov	r6,dph
   0BF3 AF F0              1221 	mov	r7,b
                    003A   1222 	C$GaitRunner.h$175$1$1 ==.
                           1223 ;	apps/twitch_ax/GaitRunner.h:175: return runner->playing;
   0BF5 74 06              1224 	mov	a,#0x06
   0BF7 2D                 1225 	add	a,r5
   0BF8 FD                 1226 	mov	r5,a
   0BF9 E4                 1227 	clr	a
   0BFA 3E                 1228 	addc	a,r6
   0BFB FE                 1229 	mov	r6,a
   0BFC 8D 82              1230 	mov	dpl,r5
   0BFE 8E 83              1231 	mov	dph,r6
   0C00 8F F0              1232 	mov	b,r7
   0C02 12 42 C6           1233 	lcall	__gptrget
                    004A   1234 	C$GaitRunner.h$176$1$1 ==.
                    004A   1235 	XFtwitch_ax$gaitRunnerIsPlaying$0$0 ==.
   0C05 F5 82              1236 	mov	dpl,a
   0C07 22                 1237 	ret
                           1238 ;------------------------------------------------------------
                           1239 ;Allocation info for local variables in function 'updateLeds'
                           1240 ;------------------------------------------------------------
                           1241 ;count                     Allocated with name '_updateLeds_count_3_7'
                           1242 ;------------------------------------------------------------
                    004D   1243 	G$updateLeds$0$0 ==.
                    004D   1244 	C$twitch_ax.c$129$1$1 ==.
                           1245 ;	apps/twitch_ax/twitch_ax.c:129: void updateLeds()
                           1246 ;	-----------------------------------------
                           1247 ;	 function updateLeds
                           1248 ;	-----------------------------------------
   0C08                    1249 _updateLeds:
                    004D   1250 	C$twitch_ax.c$139$1$1 ==.
                           1251 ;	apps/twitch_ax/twitch_ax.c:139: now = (uint16)getMs();
   0C08 12 3B 8B           1252 	lcall	_getMs
   0C0B AC 82              1253 	mov	r4,dpl
   0C0D AD 83              1254 	mov	r5,dph
                    0054   1255 	C$twitch_ax.c$146$1$1 ==.
                           1256 ;	apps/twitch_ax/twitch_ax.c:146: if (!radioLinkConnected())
   0C0F C0 05              1257 	push	ar5
   0C11 C0 04              1258 	push	ar4
   0C13 12 2D 50           1259 	lcall	_radioLinkConnected
   0C16 D0 04              1260 	pop	ar4
   0C18 D0 05              1261 	pop	ar5
   0C1A 40 12              1262 	jc	00108$
                    0061   1263 	C$twitch_ax.c$150$3$3 ==.
                           1264 ;	apps/twitch_ax/twitch_ax.c:150: LED_YELLOW(now & 0x200 ? 1 : 0);
   0C1C ED                 1265 	mov	a,r5
   0C1D 30 E1 05           1266 	jnb	acc.1,00118$
   0C20 43 FF 04           1267 	orl	_P2DIR,#0x04
   0C23 80 43              1268 	sjmp	00109$
   0C25                    1269 00118$:
   0C25 AF FF              1270 	mov	r7,_P2DIR
   0C27 53 07 FB           1271 	anl	ar7,#0xFB
   0C2A 8F FF              1272 	mov	_P2DIR,r7
   0C2C 80 3A              1273 	sjmp	00109$
   0C2E                    1274 00108$:
                    0073   1275 	C$twitch_ax.c$156$2$4 ==.
                           1276 ;	apps/twitch_ax/twitch_ax.c:156: if ((now & 0x3FF) <= 20)
   0C2E 8C 06              1277 	mov	ar6,r4
   0C30 74 03              1278 	mov	a,#0x03
   0C32 5D                 1279 	anl	a,r5
   0C33 FF                 1280 	mov	r7,a
   0C34 C3                 1281 	clr	c
   0C35 74 14              1282 	mov	a,#0x14
   0C37 9E                 1283 	subb	a,r6
   0C38 E4                 1284 	clr	a
   0C39 9F                 1285 	subb	a,r7
   0C3A 40 05              1286 	jc	00105$
                    0081   1287 	C$twitch_ax.c$159$4$6 ==.
                           1288 ;	apps/twitch_ax/twitch_ax.c:159: LED_YELLOW(1);
   0C3C 43 FF 04           1289 	orl	_P2DIR,#0x04
   0C3F 80 27              1290 	sjmp	00109$
   0C41                    1291 00105$:
                    0086   1292 	C$twitch_ax.c$161$2$4 ==.
                           1293 ;	apps/twitch_ax/twitch_ax.c:161: else if (dimYellowLed)
   0C41 30 03 1D           1294 	jnb	_updateLeds_dimYellowLed_1_1,00102$
                    0089   1295 	C$twitch_ax.c$164$3$7 ==.
                           1296 ;	apps/twitch_ax/twitch_ax.c:164: count++;
   0C44 05 3C              1297 	inc	_updateLeds_count_3_7
                    008B   1298 	C$twitch_ax.c$165$4$8 ==.
                           1299 ;	apps/twitch_ax/twitch_ax.c:165: LED_YELLOW((count & 0x7)==0);
   0C46 74 07              1300 	mov	a,#0x07
   0C48 55 3C              1301 	anl	a,_updateLeds_count_3_7
   0C4A FF                 1302 	mov	r7,a
   0C4B B4 01 00           1303 	cjne	a,#0x01,00142$
   0C4E                    1304 00142$:
   0C4E E4                 1305 	clr	a
   0C4F 33                 1306 	rlc	a
   0C50 FF                 1307 	mov	r7,a
   0C51 60 05              1308 	jz	00120$
   0C53 43 FF 04           1309 	orl	_P2DIR,#0x04
   0C56 80 10              1310 	sjmp	00109$
   0C58                    1311 00120$:
   0C58 AF FF              1312 	mov	r7,_P2DIR
   0C5A 53 07 FB           1313 	anl	ar7,#0xFB
   0C5D 8F FF              1314 	mov	_P2DIR,r7
   0C5F 80 07              1315 	sjmp	00109$
   0C61                    1316 00102$:
                    00A6   1317 	C$twitch_ax.c$169$4$10 ==.
                           1318 ;	apps/twitch_ax/twitch_ax.c:169: LED_YELLOW(0);
   0C61 AF FF              1319 	mov	r7,_P2DIR
   0C63 53 07 FB           1320 	anl	ar7,#0xFB
   0C66 8F FF              1321 	mov	_P2DIR,r7
   0C68                    1322 00109$:
                    00AD   1323 	C$twitch_ax.c$173$1$1 ==.
                           1324 ;	apps/twitch_ax/twitch_ax.c:173: if (radioLinkActivityOccurred)
                    00AD   1325 	C$twitch_ax.c$175$2$11 ==.
                           1326 ;	apps/twitch_ax/twitch_ax.c:175: radioLinkActivityOccurred = 0;
   0C68 10 0E 02           1327 	jbc	_radioLinkActivityOccurred,00144$
   0C6B 80 12              1328 	sjmp	00111$
   0C6D                    1329 00144$:
                    00B2   1330 	C$twitch_ax.c$176$2$11 ==.
                           1331 ;	apps/twitch_ax/twitch_ax.c:176: dimYellowLed ^= 1;
   0C6D A2 03              1332 	mov	c,_updateLeds_dimYellowLed_1_1
   0C6F E4                 1333 	clr	a
   0C70 33                 1334 	rlc	a
   0C71 64 01              1335 	xrl	a,#0x01
   0C73 FF                 1336 	mov	r7,a
   0C74 24 FF              1337 	add	a,#0xff
   0C76 92 03              1338 	mov	_updateLeds_dimYellowLed_1_1,c
                    00BD   1339 	C$twitch_ax.c$178$2$11 ==.
                           1340 ;	apps/twitch_ax/twitch_ax.c:178: lastRadioActivityTime = now;
   0C78 78 46              1341 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   0C7A EC                 1342 	mov	a,r4
   0C7B F2                 1343 	movx	@r0,a
   0C7C 08                 1344 	inc	r0
   0C7D ED                 1345 	mov	a,r5
   0C7E F2                 1346 	movx	@r0,a
   0C7F                    1347 00111$:
                    00C4   1348 	C$twitch_ax.c$181$1$1 ==.
                           1349 ;	apps/twitch_ax/twitch_ax.c:181: if ((uint16)(now - lastRadioActivityTime) > 32)
   0C7F 78 46              1350 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   0C81 D3                 1351 	setb	c
   0C82 E2                 1352 	movx	a,@r0
   0C83 9C                 1353 	subb	a,r4
   0C84 F4                 1354 	cpl	a
   0C85 B3                 1355 	cpl	c
   0C86 FE                 1356 	mov	r6,a
   0C87 B3                 1357 	cpl	c
   0C88 08                 1358 	inc	r0
   0C89 E2                 1359 	movx	a,@r0
   0C8A 9D                 1360 	subb	a,r5
   0C8B F4                 1361 	cpl	a
   0C8C FF                 1362 	mov	r7,a
   0C8D C3                 1363 	clr	c
   0C8E 74 20              1364 	mov	a,#0x20
   0C90 9E                 1365 	subb	a,r6
   0C91 E4                 1366 	clr	a
   0C92 9F                 1367 	subb	a,r7
   0C93 50 02              1368 	jnc	00113$
                    00DA   1369 	C$twitch_ax.c$183$2$12 ==.
                           1370 ;	apps/twitch_ax/twitch_ax.c:183: dimYellowLed = 0;
   0C95 C2 03              1371 	clr	_updateLeds_dimYellowLed_1_1
   0C97                    1372 00113$:
                    00DC   1373 	C$twitch_ax.c$186$1$1 ==.
                           1374 ;	apps/twitch_ax/twitch_ax.c:186: if ((uint8)(now - lastErrorTime) > 100)
   0C97 78 40              1375 	mov	r0,#_lastErrorTime
   0C99 D3                 1376 	setb	c
   0C9A E2                 1377 	movx	a,@r0
   0C9B 9C                 1378 	subb	a,r4
   0C9C F4                 1379 	cpl	a
   0C9D FC                 1380 	mov  r4,a
   0C9E 24 9B              1381 	add	a,#0xff - 0x64
   0CA0 50 02              1382 	jnc	00115$
                    00E7   1383 	C$twitch_ax.c$188$2$13 ==.
                           1384 ;	apps/twitch_ax/twitch_ax.c:188: errorOccurredRecently = 0;
   0CA2 C2 02              1385 	clr	_errorOccurredRecently
   0CA4                    1386 00115$:
                    00E9   1387 	C$twitch_ax.c$191$2$14 ==.
                           1388 ;	apps/twitch_ax/twitch_ax.c:191: LED_RED(errorOccurredRecently || uartRxDisabled);
   0CA4 20 02 07           1389 	jb	_errorOccurredRecently,00125$
   0CA7 20 00 04           1390 	jb	_uartRxDisabled,00125$
   0CAA 7F 00              1391 	mov	r7,#0x00
   0CAC 80 02              1392 	sjmp	00126$
   0CAE                    1393 00125$:
   0CAE 7F 01              1394 	mov	r7,#0x01
   0CB0                    1395 00126$:
   0CB0 EF                 1396 	mov	a,r7
   0CB1 60 05              1397 	jz	00122$
   0CB3 43 FF 02           1398 	orl	_P2DIR,#0x02
   0CB6 80 07              1399 	sjmp	00116$
   0CB8                    1400 00122$:
   0CB8 AF FF              1401 	mov	r7,_P2DIR
   0CBA 53 07 FD           1402 	anl	ar7,#0xFD
   0CBD 8F FF              1403 	mov	_P2DIR,r7
   0CBF                    1404 00116$:
                    0104   1405 	C$twitch_ax.c$192$2$14 ==.
                    0104   1406 	XG$updateLeds$0$0 ==.
   0CBF 22                 1407 	ret
                           1408 ;------------------------------------------------------------
                           1409 ;Allocation info for local variables in function 'ioRxSignals'
                           1410 ;------------------------------------------------------------
                    0105   1411 	G$ioRxSignals$0$0 ==.
                    0105   1412 	C$twitch_ax.c$197$2$14 ==.
                           1413 ;	apps/twitch_ax/twitch_ax.c:197: uint8 ioRxSignals()
                           1414 ;	-----------------------------------------
                           1415 ;	 function ioRxSignals
                           1416 ;	-----------------------------------------
   0CC0                    1417 _ioRxSignals:
                    0105   1418 	C$twitch_ax.c$199$1$14 ==.
                           1419 ;	apps/twitch_ax/twitch_ax.c:199: uint8 signals = 0;
   0CC0 7F 00              1420 	mov	r7,#0x00
                    0107   1421 	C$twitch_ax.c$201$1$1 ==.
                           1422 ;	apps/twitch_ax/twitch_ax.c:201: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   0CC2 90 4C 40           1423 	mov	dptr,#_param_CD_pin
   0CC5 E4                 1424 	clr	a
   0CC6 93                 1425 	movc	a,@a+dptr
   0CC7 FB                 1426 	mov	r3,a
   0CC8 74 01              1427 	mov	a,#0x01
   0CCA 93                 1428 	movc	a,@a+dptr
   0CCB FC                 1429 	mov	r4,a
   0CCC 74 02              1430 	mov	a,#0x02
   0CCE 93                 1431 	movc	a,@a+dptr
   0CCF FD                 1432 	mov	r5,a
   0CD0 74 03              1433 	mov	a,#0x03
   0CD2 93                 1434 	movc	a,@a+dptr
   0CD3 FE                 1435 	mov	r6,a
   0CD4 20 E7 0B           1436 	jb	acc.7,00105$
   0CD7 8B 82              1437 	mov	dpl,r3
   0CD9 C0 07              1438 	push	ar7
   0CDB 12 3F 5B           1439 	lcall	_isPinHigh
   0CDE D0 07              1440 	pop	ar7
   0CE0 40 20              1441 	jc	00101$
   0CE2                    1442 00105$:
                    0127   1443 	C$twitch_ax.c$202$1$1 ==.
                           1444 ;	apps/twitch_ax/twitch_ax.c:202: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   0CE2 90 4C 30           1445 	mov	dptr,#_param_nCD_pin
   0CE5 E4                 1446 	clr	a
   0CE6 93                 1447 	movc	a,@a+dptr
   0CE7 FB                 1448 	mov	r3,a
   0CE8 74 01              1449 	mov	a,#0x01
   0CEA 93                 1450 	movc	a,@a+dptr
   0CEB FC                 1451 	mov	r4,a
   0CEC 74 02              1452 	mov	a,#0x02
   0CEE 93                 1453 	movc	a,@a+dptr
   0CEF FD                 1454 	mov	r5,a
   0CF0 74 03              1455 	mov	a,#0x03
   0CF2 93                 1456 	movc	a,@a+dptr
   0CF3 FE                 1457 	mov	r6,a
   0CF4 20 E7 0D           1458 	jb	acc.7,00102$
   0CF7 8B 82              1459 	mov	dpl,r3
   0CF9 C0 07              1460 	push	ar7
   0CFB 12 3F 5B           1461 	lcall	_isPinHigh
   0CFE D0 07              1462 	pop	ar7
   0D00 40 02              1463 	jc	00102$
   0D02                    1464 00101$:
                    0147   1465 	C$twitch_ax.c$204$2$2 ==.
                           1466 ;	apps/twitch_ax/twitch_ax.c:204: signals |= 2;
   0D02 7F 02              1467 	mov	r7,#0x02
   0D04                    1468 00102$:
                    0149   1469 	C$twitch_ax.c$207$1$1 ==.
                           1470 ;	apps/twitch_ax/twitch_ax.c:207: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   0D04 90 4C 3C           1471 	mov	dptr,#_param_DSR_pin
   0D07 E4                 1472 	clr	a
   0D08 93                 1473 	movc	a,@a+dptr
   0D09 FB                 1474 	mov	r3,a
   0D0A 74 01              1475 	mov	a,#0x01
   0D0C 93                 1476 	movc	a,@a+dptr
   0D0D FC                 1477 	mov	r4,a
   0D0E 74 02              1478 	mov	a,#0x02
   0D10 93                 1479 	movc	a,@a+dptr
   0D11 FD                 1480 	mov	r5,a
   0D12 74 03              1481 	mov	a,#0x03
   0D14 93                 1482 	movc	a,@a+dptr
   0D15 FE                 1483 	mov	r6,a
   0D16 20 E7 0B           1484 	jb	acc.7,00110$
   0D19 8B 82              1485 	mov	dpl,r3
   0D1B C0 07              1486 	push	ar7
   0D1D 12 3F 5B           1487 	lcall	_isPinHigh
   0D20 D0 07              1488 	pop	ar7
   0D22 40 20              1489 	jc	00106$
   0D24                    1490 00110$:
                    0169   1491 	C$twitch_ax.c$208$1$1 ==.
                           1492 ;	apps/twitch_ax/twitch_ax.c:208: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   0D24 90 4C 2C           1493 	mov	dptr,#_param_nDSR_pin
   0D27 E4                 1494 	clr	a
   0D28 93                 1495 	movc	a,@a+dptr
   0D29 FB                 1496 	mov	r3,a
   0D2A 74 01              1497 	mov	a,#0x01
   0D2C 93                 1498 	movc	a,@a+dptr
   0D2D FC                 1499 	mov	r4,a
   0D2E 74 02              1500 	mov	a,#0x02
   0D30 93                 1501 	movc	a,@a+dptr
   0D31 FD                 1502 	mov	r5,a
   0D32 74 03              1503 	mov	a,#0x03
   0D34 93                 1504 	movc	a,@a+dptr
   0D35 FE                 1505 	mov	r6,a
   0D36 20 E7 0E           1506 	jb	acc.7,00107$
   0D39 8B 82              1507 	mov	dpl,r3
   0D3B C0 07              1508 	push	ar7
   0D3D 12 3F 5B           1509 	lcall	_isPinHigh
   0D40 D0 07              1510 	pop	ar7
   0D42 40 03              1511 	jc	00107$
   0D44                    1512 00106$:
                    0189   1513 	C$twitch_ax.c$210$2$3 ==.
                           1514 ;	apps/twitch_ax/twitch_ax.c:210: signals |= 1;
   0D44 43 07 01           1515 	orl	ar7,#0x01
   0D47                    1516 00107$:
                    018C   1517 	C$twitch_ax.c$213$1$1 ==.
                           1518 ;	apps/twitch_ax/twitch_ax.c:213: return signals;
   0D47 8F 82              1519 	mov	dpl,r7
                    018E   1520 	C$twitch_ax.c$214$1$1 ==.
                    018E   1521 	XG$ioRxSignals$0$0 ==.
   0D49 22                 1522 	ret
                           1523 ;------------------------------------------------------------
                           1524 ;Allocation info for local variables in function 'ioTxSignals'
                           1525 ;------------------------------------------------------------
                    018F   1526 	G$ioTxSignals$0$0 ==.
                    018F   1527 	C$twitch_ax.c$220$1$1 ==.
                           1528 ;	apps/twitch_ax/twitch_ax.c:220: void ioTxSignals(uint8 signals)
                           1529 ;	-----------------------------------------
                           1530 ;	 function ioTxSignals
                           1531 ;	-----------------------------------------
   0D4A                    1532 _ioTxSignals:
   0D4A E5 82              1533 	mov	a,dpl
   0D4C 78 48              1534 	mov	r0,#_ioTxSignals_signals_1_1
   0D4E F2                 1535 	movx	@r0,a
                    0194   1536 	C$twitch_ax.c$226$1$1 ==.
                           1537 ;	apps/twitch_ax/twitch_ax.c:226: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   0D4F 78 48              1538 	mov	r0,#_ioTxSignals_signals_1_1
   0D51 E2                 1539 	movx	a,@r0
   0D52 54 01              1540 	anl	a,#0x01
   0D54 FE                 1541 	mov	r6,a
   0D55 B4 01 00           1542 	cjne	a,#0x01,00112$
   0D58                    1543 00112$:
   0D58 E4                 1544 	clr	a
   0D59 33                 1545 	rlc	a
   0D5A 24 FF              1546 	add	a,#0xff
   0D5C 92 04              1547 	mov	_ioTxSignals_sloc0_1_0,c
   0D5E 90 4C 24           1548 	mov	dptr,#_param_nDTR_pin
   0D61 E4                 1549 	clr	a
   0D62 93                 1550 	movc	a,@a+dptr
   0D63 FA                 1551 	mov	r2,a
   0D64 74 01              1552 	mov	a,#0x01
   0D66 93                 1553 	movc	a,@a+dptr
   0D67 74 02              1554 	mov	a,#0x02
   0D69 93                 1555 	movc	a,@a+dptr
   0D6A 74 03              1556 	mov	a,#0x03
   0D6C 93                 1557 	movc	a,@a+dptr
   0D6D 8A 82              1558 	mov	dpl,r2
   0D6F A2 04              1559 	mov	c,_ioTxSignals_sloc0_1_0
   0D71 92 F0              1560 	mov	b[0],c
   0D73 C0 06              1561 	push	ar6
   0D75 85 F0 23           1562 	mov	bits,b
   0D78 12 3C 44           1563 	lcall	_setDigitalOutput
   0D7B D0 06              1564 	pop	ar6
                    01C2   1565 	C$twitch_ax.c$227$1$1 ==.
                           1566 ;	apps/twitch_ax/twitch_ax.c:227: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   0D7D 78 48              1567 	mov	r0,#_ioTxSignals_signals_1_1
   0D7F E2                 1568 	movx	a,@r0
   0D80 03                 1569 	rr	a
   0D81 54 01              1570 	anl	a,#0x01
   0D83 FD                 1571 	mov	r5,a
   0D84 B4 01 00           1572 	cjne	a,#0x01,00113$
   0D87                    1573 00113$:
   0D87 E4                 1574 	clr	a
   0D88 33                 1575 	rlc	a
   0D89 24 FF              1576 	add	a,#0xff
   0D8B 92 04              1577 	mov	_ioTxSignals_sloc0_1_0,c
   0D8D 90 4C 28           1578 	mov	dptr,#_param_nRTS_pin
   0D90 E4                 1579 	clr	a
   0D91 93                 1580 	movc	a,@a+dptr
   0D92 FA                 1581 	mov	r2,a
   0D93 74 01              1582 	mov	a,#0x01
   0D95 93                 1583 	movc	a,@a+dptr
   0D96 74 02              1584 	mov	a,#0x02
   0D98 93                 1585 	movc	a,@a+dptr
   0D99 74 03              1586 	mov	a,#0x03
   0D9B 93                 1587 	movc	a,@a+dptr
   0D9C 8A 82              1588 	mov	dpl,r2
   0D9E A2 04              1589 	mov	c,_ioTxSignals_sloc0_1_0
   0DA0 92 F0              1590 	mov	b[0],c
   0DA2 C0 06              1591 	push	ar6
   0DA4 C0 05              1592 	push	ar5
   0DA6 85 F0 23           1593 	mov	bits,b
   0DA9 12 3C 44           1594 	lcall	_setDigitalOutput
   0DAC D0 05              1595 	pop	ar5
   0DAE D0 06              1596 	pop	ar6
                    01F5   1597 	C$twitch_ax.c$230$1$1 ==.
                           1598 ;	apps/twitch_ax/twitch_ax.c:230: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0DB0 EE                 1599 	mov	a,r6
   0DB1 24 FF              1600 	add	a,#0xff
   0DB3 92 04              1601 	mov	_ioTxSignals_sloc0_1_0,c
   0DB5 90 4C 34           1602 	mov	dptr,#_param_DTR_pin
   0DB8 E4                 1603 	clr	a
   0DB9 93                 1604 	movc	a,@a+dptr
   0DBA FB                 1605 	mov	r3,a
   0DBB 74 01              1606 	mov	a,#0x01
   0DBD 93                 1607 	movc	a,@a+dptr
   0DBE 74 02              1608 	mov	a,#0x02
   0DC0 93                 1609 	movc	a,@a+dptr
   0DC1 74 03              1610 	mov	a,#0x03
   0DC3 93                 1611 	movc	a,@a+dptr
   0DC4 8B 82              1612 	mov	dpl,r3
   0DC6 A2 04              1613 	mov	c,_ioTxSignals_sloc0_1_0
   0DC8 92 F0              1614 	mov	b[0],c
   0DCA C0 05              1615 	push	ar5
   0DCC 85 F0 23           1616 	mov	bits,b
   0DCF 12 3C 44           1617 	lcall	_setDigitalOutput
   0DD2 D0 05              1618 	pop	ar5
                    0219   1619 	C$twitch_ax.c$231$1$1 ==.
                           1620 ;	apps/twitch_ax/twitch_ax.c:231: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   0DD4 ED                 1621 	mov	a,r5
   0DD5 24 FF              1622 	add	a,#0xff
   0DD7 92 04              1623 	mov	_ioTxSignals_sloc0_1_0,c
   0DD9 90 4C 38           1624 	mov	dptr,#_param_RTS_pin
   0DDC E4                 1625 	clr	a
   0DDD 93                 1626 	movc	a,@a+dptr
   0DDE FC                 1627 	mov	r4,a
   0DDF 74 01              1628 	mov	a,#0x01
   0DE1 93                 1629 	movc	a,@a+dptr
   0DE2 74 02              1630 	mov	a,#0x02
   0DE4 93                 1631 	movc	a,@a+dptr
   0DE5 74 03              1632 	mov	a,#0x03
   0DE7 93                 1633 	movc	a,@a+dptr
   0DE8 8C 82              1634 	mov	dpl,r4
   0DEA A2 04              1635 	mov	c,_ioTxSignals_sloc0_1_0
   0DEC 92 F0              1636 	mov	b[0],c
   0DEE 85 F0 23           1637 	mov	bits,b
   0DF1 12 3C 44           1638 	lcall	_setDigitalOutput
                    0239   1639 	C$twitch_ax.c$234$1$1 ==.
                           1640 ;	apps/twitch_ax/twitch_ax.c:234: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   0DF4 78 4A              1641 	mov	r0,#_ioTxSignals_lastSignals_1_1
   0DF6 E2                 1642 	movx	a,@r0
   0DF7 54 01              1643 	anl	a,#0x01
   0DF9 60 02              1644 	jz	00115$
   0DFB 80 30              1645 	sjmp	00104$
   0DFD                    1646 00115$:
   0DFD 78 48              1647 	mov	r0,#_ioTxSignals_signals_1_1
   0DFF E2                 1648 	movx	a,@r0
   0E00 54 01              1649 	anl	a,#0x01
   0E02 60 29              1650 	jz	00104$
                    0249   1651 	C$twitch_ax.c$238$2$2 ==.
                           1652 ;	apps/twitch_ax/twitch_ax.c:238: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   0E04 90 4C 44           1653 	mov	dptr,#_param_arduino_DTR_pin
   0E07 E4                 1654 	clr	a
   0E08 93                 1655 	movc	a,@a+dptr
   0E09 FC                 1656 	mov	r4,a
   0E0A 74 01              1657 	mov	a,#0x01
   0E0C 93                 1658 	movc	a,@a+dptr
   0E0D 74 02              1659 	mov	a,#0x02
   0E0F 93                 1660 	movc	a,@a+dptr
   0E10 74 03              1661 	mov	a,#0x03
   0E12 93                 1662 	movc	a,@a+dptr
   0E13 8C 82              1663 	mov	dpl,r4
   0E15 D2 F0              1664 	setb	b[0]
   0E17 85 F0 23           1665 	mov	bits,b
   0E1A 12 3C 44           1666 	lcall	_setDigitalOutput
                    0262   1667 	C$twitch_ax.c$239$2$2 ==.
                           1668 ;	apps/twitch_ax/twitch_ax.c:239: nTrstPulseStartTime = getMs();
   0E1D 12 3B 8B           1669 	lcall	_getMs
   0E20 AC 82              1670 	mov	r4,dpl
   0E22 AD 83              1671 	mov	r5,dph
   0E24 AE F0              1672 	mov	r6,b
   0E26 FF                 1673 	mov	r7,a
   0E27 78 49              1674 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0E29 EC                 1675 	mov	a,r4
   0E2A F2                 1676 	movx	@r0,a
   0E2B 80 2F              1677 	sjmp	00105$
   0E2D                    1678 00104$:
                    0272   1679 	C$twitch_ax.c$241$1$1 ==.
                           1680 ;	apps/twitch_ax/twitch_ax.c:241: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   0E2D 12 3B 8B           1681 	lcall	_getMs
   0E30 AC 82              1682 	mov	r4,dpl
   0E32 AD 83              1683 	mov	r5,dph
   0E34 AE F0              1684 	mov	r6,b
   0E36 FF                 1685 	mov	r7,a
   0E37 78 49              1686 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0E39 D3                 1687 	setb	c
   0E3A E2                 1688 	movx	a,@r0
   0E3B 9C                 1689 	subb	a,r4
   0E3C F4                 1690 	cpl	a
   0E3D FC                 1691 	mov	r4,a
   0E3E BC 02 00           1692 	cjne	r4,#0x02,00117$
   0E41                    1693 00117$:
   0E41 40 19              1694 	jc	00105$
                    0288   1695 	C$twitch_ax.c$243$2$3 ==.
                           1696 ;	apps/twitch_ax/twitch_ax.c:243: setDigitalOutput(param_arduino_DTR_pin, LOW);
   0E43 90 4C 44           1697 	mov	dptr,#_param_arduino_DTR_pin
   0E46 E4                 1698 	clr	a
   0E47 93                 1699 	movc	a,@a+dptr
   0E48 FC                 1700 	mov	r4,a
   0E49 74 01              1701 	mov	a,#0x01
   0E4B 93                 1702 	movc	a,@a+dptr
   0E4C 74 02              1703 	mov	a,#0x02
   0E4E 93                 1704 	movc	a,@a+dptr
   0E4F 74 03              1705 	mov	a,#0x03
   0E51 93                 1706 	movc	a,@a+dptr
   0E52 8C 82              1707 	mov	dpl,r4
   0E54 C2 F0              1708 	clr	b[0]
   0E56 85 F0 23           1709 	mov	bits,b
   0E59 12 3C 44           1710 	lcall	_setDigitalOutput
   0E5C                    1711 00105$:
                    02A1   1712 	C$twitch_ax.c$246$1$1 ==.
                           1713 ;	apps/twitch_ax/twitch_ax.c:246: lastSignals = signals;
   0E5C 78 48              1714 	mov	r0,#_ioTxSignals_signals_1_1
   0E5E 79 4A              1715 	mov	r1,#_ioTxSignals_lastSignals_1_1
   0E60 E2                 1716 	movx	a,@r0
   0E61 F3                 1717 	movx	@r1,a
                    02A7   1718 	C$twitch_ax.c$247$1$1 ==.
                    02A7   1719 	XG$ioTxSignals$0$0 ==.
   0E62 22                 1720 	ret
                           1721 ;------------------------------------------------------------
                           1722 ;Allocation info for local variables in function 'errorOccurred'
                           1723 ;------------------------------------------------------------
                    02A8   1724 	G$errorOccurred$0$0 ==.
                    02A8   1725 	C$twitch_ax.c$249$1$1 ==.
                           1726 ;	apps/twitch_ax/twitch_ax.c:249: void errorOccurred()
                           1727 ;	-----------------------------------------
                           1728 ;	 function errorOccurred
                           1729 ;	-----------------------------------------
   0E63                    1730 _errorOccurred:
                    02A8   1731 	C$twitch_ax.c$251$1$1 ==.
                           1732 ;	apps/twitch_ax/twitch_ax.c:251: lastErrorTime = (uint8)getMs();
   0E63 12 3B 8B           1733 	lcall	_getMs
   0E66 AC 82              1734 	mov	r4,dpl
   0E68 78 40              1735 	mov	r0,#_lastErrorTime
   0E6A EC                 1736 	mov	a,r4
   0E6B F2                 1737 	movx	@r0,a
                    02B1   1738 	C$twitch_ax.c$252$1$1 ==.
                           1739 ;	apps/twitch_ax/twitch_ax.c:252: errorOccurredRecently = 1;
   0E6C D2 02              1740 	setb	_errorOccurredRecently
                    02B3   1741 	C$twitch_ax.c$253$1$1 ==.
                    02B3   1742 	XG$errorOccurred$0$0 ==.
   0E6E 22                 1743 	ret
                           1744 ;------------------------------------------------------------
                           1745 ;Allocation info for local variables in function 'errorService'
                           1746 ;------------------------------------------------------------
                           1747 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1748 ;------------------------------------------------------------
                    02B4   1749 	G$errorService$0$0 ==.
                    02B4   1750 	C$twitch_ax.c$255$1$1 ==.
                           1751 ;	apps/twitch_ax/twitch_ax.c:255: void errorService()
                           1752 ;	-----------------------------------------
                           1753 ;	 function errorService
                           1754 ;	-----------------------------------------
   0E6F                    1755 _errorService:
                    02B4   1756 	C$twitch_ax.c$259$1$1 ==.
                           1757 ;	apps/twitch_ax/twitch_ax.c:259: if (uart1RxBufferFullOccurred)
                    02B4   1758 	C$twitch_ax.c$261$2$2 ==.
                           1759 ;	apps/twitch_ax/twitch_ax.c:261: uart1RxBufferFullOccurred = 0;
   0E6F 10 08 02           1760 	jbc	_uart1RxBufferFullOccurred,00129$
   0E72 80 03              1761 	sjmp	00102$
   0E74                    1762 00129$:
                    02B9   1763 	C$twitch_ax.c$262$2$2 ==.
                           1764 ;	apps/twitch_ax/twitch_ax.c:262: errorOccurred();
   0E74 12 0E 63           1765 	lcall	_errorOccurred
   0E77                    1766 00102$:
                    02BC   1767 	C$twitch_ax.c$265$1$1 ==.
                           1768 ;	apps/twitch_ax/twitch_ax.c:265: if (uart1RxFramingErrorOccurred)
                    02BC   1769 	C$twitch_ax.c$267$2$3 ==.
                           1770 ;	apps/twitch_ax/twitch_ax.c:267: uart1RxFramingErrorOccurred = 0;
   0E77 10 07 02           1771 	jbc	_uart1RxFramingErrorOccurred,00130$
   0E7A 80 41              1772 	sjmp	00106$
   0E7C                    1773 00130$:
                    02C1   1774 	C$twitch_ax.c$270$2$3 ==.
                           1775 ;	apps/twitch_ax/twitch_ax.c:270: framingErrorActive = 1;
   0E7C D2 01              1776 	setb	_framingErrorActive
                    02C3   1777 	C$twitch_ax.c$271$2$3 ==.
                           1778 ;	apps/twitch_ax/twitch_ax.c:271: errorOccurred();
   0E7E 12 0E 63           1779 	lcall	_errorOccurred
                    02C6   1780 	C$twitch_ax.c$273$2$3 ==.
                           1781 ;	apps/twitch_ax/twitch_ax.c:273: if (param_framing_error_ms > 0)
   0E81 90 4C 48           1782 	mov	dptr,#_param_framing_error_ms
   0E84 E4                 1783 	clr	a
   0E85 93                 1784 	movc	a,@a+dptr
   0E86 FC                 1785 	mov	r4,a
   0E87 74 01              1786 	mov	a,#0x01
   0E89 93                 1787 	movc	a,@a+dptr
   0E8A FD                 1788 	mov	r5,a
   0E8B 74 02              1789 	mov	a,#0x02
   0E8D 93                 1790 	movc	a,@a+dptr
   0E8E FE                 1791 	mov	r6,a
   0E8F 74 03              1792 	mov	a,#0x03
   0E91 93                 1793 	movc	a,@a+dptr
   0E92 FF                 1794 	mov	r7,a
   0E93 C3                 1795 	clr	c
   0E94 E4                 1796 	clr	a
   0E95 9C                 1797 	subb	a,r4
   0E96 E4                 1798 	clr	a
   0E97 9D                 1799 	subb	a,r5
   0E98 E4                 1800 	clr	a
   0E99 9E                 1801 	subb	a,r6
   0E9A E4                 1802 	clr	a
   0E9B 64 80              1803 	xrl	a,#0x80
   0E9D 8F F0              1804 	mov	b,r7
   0E9F 63 F0 80           1805 	xrl	b,#0x80
   0EA2 95 F0              1806 	subb	a,b
   0EA4 50 17              1807 	jnc	00106$
                    02EB   1808 	C$twitch_ax.c$276$3$4 ==.
                           1809 ;	apps/twitch_ax/twitch_ax.c:276: U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
   0EA6 AF F8              1810 	mov	r7,_U1CSR
   0EA8 53 07 BF           1811 	anl	ar7,#0xBF
   0EAB 8F F8              1812 	mov	_U1CSR,r7
                    02F2   1813 	C$twitch_ax.c$277$3$4 ==.
                           1814 ;	apps/twitch_ax/twitch_ax.c:277: uartRxDisabled = 1;
   0EAD D2 00              1815 	setb	_uartRxDisabled
                    02F4   1816 	C$twitch_ax.c$278$3$4 ==.
                           1817 ;	apps/twitch_ax/twitch_ax.c:278: lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
   0EAF 12 3B 8B           1818 	lcall	_getMs
   0EB2 AC 82              1819 	mov	r4,dpl
   0EB4 AD 83              1820 	mov	r5,dph
   0EB6 AE F0              1821 	mov	r6,b
   0EB8 FF                 1822 	mov	r7,a
   0EB9 78 4B              1823 	mov	r0,#_errorService_lastRxLowTime_1_1
   0EBB EC                 1824 	mov	a,r4
   0EBC F2                 1825 	movx	@r0,a
   0EBD                    1826 00106$:
                    0302   1827 	C$twitch_ax.c$282$1$1 ==.
                           1828 ;	apps/twitch_ax/twitch_ax.c:282: if (framingErrorActive)
   0EBD 30 01 0F           1829 	jnb	_framingErrorActive,00111$
                    0305   1830 	C$twitch_ax.c$284$2$5 ==.
                           1831 ;	apps/twitch_ax/twitch_ax.c:284: if (!isPinHigh(17))
   0EC0 75 82 11           1832 	mov	dpl,#0x11
   0EC3 12 3F 5B           1833 	lcall	_isPinHigh
   0EC6 40 05              1834 	jc	00108$
                    030D   1835 	C$twitch_ax.c$286$3$6 ==.
                           1836 ;	apps/twitch_ax/twitch_ax.c:286: errorOccurred();
   0EC8 12 0E 63           1837 	lcall	_errorOccurred
   0ECB 80 02              1838 	sjmp	00111$
   0ECD                    1839 00108$:
                    0312   1840 	C$twitch_ax.c$290$3$7 ==.
                           1841 ;	apps/twitch_ax/twitch_ax.c:290: framingErrorActive = 0;
   0ECD C2 01              1842 	clr	_framingErrorActive
   0ECF                    1843 00111$:
                    0314   1844 	C$twitch_ax.c$294$1$1 ==.
                           1845 ;	apps/twitch_ax/twitch_ax.c:294: if (uartRxDisabled)
   0ECF 30 00 60           1846 	jnb	_uartRxDisabled,00119$
                    0317   1847 	C$twitch_ax.c$296$2$8 ==.
                           1848 ;	apps/twitch_ax/twitch_ax.c:296: if (!isPinHigh(17))
   0ED2 75 82 11           1849 	mov	dpl,#0x11
   0ED5 12 3F 5B           1850 	lcall	_isPinHigh
   0ED8 40 10              1851 	jc	00115$
                    031F   1852 	C$twitch_ax.c$299$3$9 ==.
                           1853 ;	apps/twitch_ax/twitch_ax.c:299: lastRxLowTime = (uint8)getMs();
   0EDA 12 3B 8B           1854 	lcall	_getMs
   0EDD AC 82              1855 	mov	r4,dpl
   0EDF AD 83              1856 	mov	r5,dph
   0EE1 AE F0              1857 	mov	r6,b
   0EE3 FF                 1858 	mov	r7,a
   0EE4 78 4B              1859 	mov	r0,#_errorService_lastRxLowTime_1_1
   0EE6 EC                 1860 	mov	a,r4
   0EE7 F2                 1861 	movx	@r0,a
   0EE8 80 48              1862 	sjmp	00119$
   0EEA                    1863 00115$:
                    032F   1864 	C$twitch_ax.c$301$2$8 ==.
                           1865 ;	apps/twitch_ax/twitch_ax.c:301: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   0EEA 12 3B 8B           1866 	lcall	_getMs
   0EED AC 82              1867 	mov	r4,dpl
   0EEF AD 83              1868 	mov	r5,dph
   0EF1 78 4B              1869 	mov	r0,#_errorService_lastRxLowTime_1_1
   0EF3 D3                 1870 	setb	c
   0EF4 E2                 1871 	movx	a,@r0
   0EF5 9C                 1872 	subb	a,r4
   0EF6 F4                 1873 	cpl	a
   0EF7 FC                 1874 	mov	r4,a
   0EF8 90 4C 48           1875 	mov	dptr,#_param_framing_error_ms
   0EFB E4                 1876 	clr	a
   0EFC 93                 1877 	movc	a,@a+dptr
   0EFD F5 3D              1878 	mov	_errorService_sloc0_1_0,a
   0EFF 74 01              1879 	mov	a,#0x01
   0F01 93                 1880 	movc	a,@a+dptr
   0F02 F5 3E              1881 	mov	(_errorService_sloc0_1_0 + 1),a
   0F04 74 02              1882 	mov	a,#0x02
   0F06 93                 1883 	movc	a,@a+dptr
   0F07 F5 3F              1884 	mov	(_errorService_sloc0_1_0 + 2),a
   0F09 74 03              1885 	mov	a,#0x03
   0F0B 93                 1886 	movc	a,@a+dptr
   0F0C F5 40              1887 	mov	(_errorService_sloc0_1_0 + 3),a
   0F0E 8C 02              1888 	mov	ar2,r4
   0F10 7C 00              1889 	mov	r4,#0x00
   0F12 7E 00              1890 	mov	r6,#0x00
   0F14 7F 00              1891 	mov	r7,#0x00
   0F16 C3                 1892 	clr	c
   0F17 E5 3D              1893 	mov	a,_errorService_sloc0_1_0
   0F19 9A                 1894 	subb	a,r2
   0F1A E5 3E              1895 	mov	a,(_errorService_sloc0_1_0 + 1)
   0F1C 9C                 1896 	subb	a,r4
   0F1D E5 3F              1897 	mov	a,(_errorService_sloc0_1_0 + 2)
   0F1F 9E                 1898 	subb	a,r6
   0F20 E5 40              1899 	mov	a,(_errorService_sloc0_1_0 + 3)
   0F22 64 80              1900 	xrl	a,#0x80
   0F24 8F F0              1901 	mov	b,r7
   0F26 63 F0 80           1902 	xrl	b,#0x80
   0F29 95 F0              1903 	subb	a,b
   0F2B 50 05              1904 	jnc	00119$
                    0372   1905 	C$twitch_ax.c$304$3$10 ==.
                           1906 ;	apps/twitch_ax/twitch_ax.c:304: U1CSR |= 0x40;
   0F2D 43 F8 40           1907 	orl	_U1CSR,#0x40
                    0375   1908 	C$twitch_ax.c$305$3$10 ==.
                           1909 ;	apps/twitch_ax/twitch_ax.c:305: uartRxDisabled = 0;
   0F30 C2 00              1910 	clr	_uartRxDisabled
   0F32                    1911 00119$:
                    0377   1912 	C$twitch_ax.c$308$1$1 ==.
                    0377   1913 	XG$errorService$0$0 ==.
   0F32 22                 1914 	ret
                           1915 ;------------------------------------------------------------
                           1916 ;Allocation info for local variables in function 'uartToRadioService'
                           1917 ;------------------------------------------------------------
                    0378   1918 	G$uartToRadioService$0$0 ==.
                    0378   1919 	C$twitch_ax.c$311$1$1 ==.
                           1920 ;	apps/twitch_ax/twitch_ax.c:311: void uartToRadioService()
                           1921 ;	-----------------------------------------
                           1922 ;	 function uartToRadioService
                           1923 ;	-----------------------------------------
   0F33                    1924 _uartToRadioService:
                    0378   1925 	C$twitch_ax.c$314$1$1 ==.
                           1926 ;	apps/twitch_ax/twitch_ax.c:314: while(uart1RxAvailable() && radioComTxAvailable())
   0F33                    1927 00102$:
   0F33 12 2C 3D           1928 	lcall	_uart1RxAvailable
   0F36 E5 82              1929 	mov	a,dpl
   0F38 60 0F              1930 	jz	00104$
   0F3A 12 35 F7           1931 	lcall	_radioComTxAvailable
   0F3D E5 82              1932 	mov	a,dpl
   0F3F 60 08              1933 	jz	00104$
                    0386   1934 	C$twitch_ax.c$316$2$2 ==.
                           1935 ;	apps/twitch_ax/twitch_ax.c:316: radioComTxSendByte(uart1RxReceiveByte());
   0F41 12 2C 45           1936 	lcall	_uart1RxReceiveByte
   0F44 12 36 0E           1937 	lcall	_radioComTxSendByte
   0F47 80 EA              1938 	sjmp	00102$
   0F49                    1939 00104$:
                    038E   1940 	C$twitch_ax.c$329$1$1 ==.
                           1941 ;	apps/twitch_ax/twitch_ax.c:329: ioTxSignals(radioComRxControlSignals());
   0F49 12 35 8C           1942 	lcall	_radioComRxControlSignals
   0F4C 12 0D 4A           1943 	lcall	_ioTxSignals
                    0394   1944 	C$twitch_ax.c$330$1$1 ==.
                           1945 ;	apps/twitch_ax/twitch_ax.c:330: radioComTxControlSignals(ioRxSignals());
   0F4F 12 0C C0           1946 	lcall	_ioRxSignals
   0F52 12 36 42           1947 	lcall	_radioComTxControlSignals
                    039A   1948 	C$twitch_ax.c$331$1$1 ==.
                    039A   1949 	XG$uartToRadioService$0$0 ==.
   0F55 22                 1950 	ret
                           1951 ;------------------------------------------------------------
                           1952 ;Allocation info for local variables in function 'CmdrReadMsgs'
                           1953 ;------------------------------------------------------------
                           1954 ;sloc0                     Allocated with name '_CmdrReadMsgs_sloc0_1_0'
                           1955 ;------------------------------------------------------------
                    039B   1956 	G$CmdrReadMsgs$0$0 ==.
                    039B   1957 	C$twitch_ax.c$361$1$1 ==.
                           1958 ;	apps/twitch_ax/twitch_ax.c:361: uint8 CmdrReadMsgs(int8 *desiredGait, int8 *desiredDir, int8 *desiredSpeed){
                           1959 ;	-----------------------------------------
                           1960 ;	 function CmdrReadMsgs
                           1961 ;	-----------------------------------------
   0F56                    1962 _CmdrReadMsgs:
   0F56 AD 82              1963 	mov	r5,dpl
   0F58 AE 83              1964 	mov	r6,dph
   0F5A AF F0              1965 	mov	r7,b
                    03A1   1966 	C$twitch_ax.c$363$3$5 ==.
                           1967 ;	apps/twitch_ax/twitch_ax.c:363: while(radioComRxAvailable() > 0){
   0F5C                    1968 00153$:
   0F5C C0 07              1969 	push	ar7
   0F5E C0 06              1970 	push	ar6
   0F60 C0 05              1971 	push	ar5
   0F62 12 35 68           1972 	lcall	_radioComRxAvailable
   0F65 E5 82              1973 	mov	a,dpl
   0F67 D0 05              1974 	pop	ar5
   0F69 D0 06              1975 	pop	ar6
   0F6B D0 07              1976 	pop	ar7
   0F6D 70 03              1977 	jnz	00178$
   0F6F 02 13 1C           1978 	ljmp	00155$
   0F72                    1979 00178$:
                    03B7   1980 	C$twitch_ax.c$364$2$2 ==.
                           1981 ;	apps/twitch_ax/twitch_ax.c:364: if(index_cmdr == -1){         // looking for new packet
   0F72 78 3A              1982 	mov	r0,#_index_cmdr
   0F74 E2                 1983 	movx	a,@r0
   0F75 B4 FF 1E           1984 	cjne	a,#0xFF,00151$
                    03BD   1985 	C$twitch_ax.c$365$3$3 ==.
                           1986 ;	apps/twitch_ax/twitch_ax.c:365: if(radioComRxReceiveByte() == 0xff){ //read until packet start
   0F78 C0 07              1987 	push	ar7
   0F7A C0 06              1988 	push	ar6
   0F7C C0 05              1989 	push	ar5
   0F7E 12 35 6F           1990 	lcall	_radioComRxReceiveByte
   0F81 AC 82              1991 	mov	r4,dpl
   0F83 D0 05              1992 	pop	ar5
   0F85 D0 06              1993 	pop	ar6
   0F87 D0 07              1994 	pop	ar7
   0F89 BC FF D0           1995 	cjne	r4,#0xFF,00153$
                    03D1   1996 	C$twitch_ax.c$366$4$4 ==.
                           1997 ;	apps/twitch_ax/twitch_ax.c:366: index_cmdr = 0;
   0F8C 78 3A              1998 	mov	r0,#_index_cmdr
   0F8E E4                 1999 	clr	a
   0F8F F2                 2000 	movx	@r0,a
                    03D5   2001 	C$twitch_ax.c$367$4$4 ==.
                           2002 ;	apps/twitch_ax/twitch_ax.c:367: checksum_cmdr = 0;
   0F90 78 3B              2003 	mov	r0,#_checksum_cmdr
   0F92 E4                 2004 	clr	a
   0F93 F2                 2005 	movx	@r0,a
   0F94 80 C6              2006 	sjmp	00153$
   0F96                    2007 00151$:
                    03DB   2008 	C$twitch_ax.c$369$2$2 ==.
                           2009 ;	apps/twitch_ax/twitch_ax.c:369: }else if(index_cmdr == 0){
   0F96 78 3A              2010 	mov	r0,#_index_cmdr
   0F98 E2                 2011 	movx	a,@r0
   0F99 70 36              2012 	jnz	00148$
                    03E0   2013 	C$twitch_ax.c$371$3$5 ==.
                           2014 ;	apps/twitch_ax/twitch_ax.c:371: vals[index_cmdr] = (unsigned char) radioComRxReceiveByte();
   0F9B 78 3A              2015 	mov	r0,#_index_cmdr
   0F9D E2                 2016 	movx	a,@r0
   0F9E 24 33              2017 	add	a,#_vals
   0FA0 F9                 2018 	mov	r1,a
   0FA1 C0 07              2019 	push	ar7
   0FA3 C0 06              2020 	push	ar6
   0FA5 C0 05              2021 	push	ar5
   0FA7 C0 01              2022 	push	ar1
   0FA9 12 35 6F           2023 	lcall	_radioComRxReceiveByte
   0FAC E5 82              2024 	mov	a,dpl
   0FAE D0 01              2025 	pop	ar1
   0FB0 D0 05              2026 	pop	ar5
   0FB2 D0 06              2027 	pop	ar6
   0FB4 D0 07              2028 	pop	ar7
   0FB6 F3                 2029 	movx	@r1,a
                    03FC   2030 	C$twitch_ax.c$374$3$5 ==.
                           2031 ;	apps/twitch_ax/twitch_ax.c:374: if(vals[index_cmdr] != 0xff){
   0FB7 78 3A              2032 	mov	r0,#_index_cmdr
   0FB9 E2                 2033 	movx	a,@r0
   0FBA 24 33              2034 	add	a,#_vals
   0FBC F9                 2035 	mov	r1,a
   0FBD E3                 2036 	movx	a,@r1
   0FBE FC                 2037 	mov	r4,a
   0FBF BC FF 02           2038 	cjne	r4,#0xFF,00184$
   0FC2 80 98              2039 	sjmp	00153$
   0FC4                    2040 00184$:
                    0409   2041 	C$twitch_ax.c$375$4$6 ==.
                           2042 ;	apps/twitch_ax/twitch_ax.c:375: checksum_cmdr += (uint8) vals[index_cmdr];
   0FC4 78 3B              2043 	mov	r0,#_checksum_cmdr
   0FC6 E2                 2044 	movx	a,@r0
   0FC7 2C                 2045 	add	a,r4
   0FC8 F2                 2046 	movx	@r0,a
                    040E   2047 	C$twitch_ax.c$376$4$6 ==.
                           2048 ;	apps/twitch_ax/twitch_ax.c:376: index_cmdr++;
   0FC9 78 3A              2049 	mov	r0,#_index_cmdr
   0FCB E2                 2050 	movx	a,@r0
   0FCC 24 01              2051 	add	a,#0x01
   0FCE F2                 2052 	movx	@r0,a
   0FCF 80 8B              2053 	sjmp	00153$
   0FD1                    2054 00148$:
                    0416   2055 	C$twitch_ax.c$379$3$7 ==.
                           2056 ;	apps/twitch_ax/twitch_ax.c:379: vals[index_cmdr] = (unsigned char) radioComRxReceiveByte(); 
   0FD1 78 3A              2057 	mov	r0,#_index_cmdr
   0FD3 E2                 2058 	movx	a,@r0
   0FD4 24 33              2059 	add	a,#_vals
   0FD6 F9                 2060 	mov	r1,a
   0FD7 C0 07              2061 	push	ar7
   0FD9 C0 06              2062 	push	ar6
   0FDB C0 05              2063 	push	ar5
   0FDD C0 01              2064 	push	ar1
   0FDF 12 35 6F           2065 	lcall	_radioComRxReceiveByte
   0FE2 E5 82              2066 	mov	a,dpl
   0FE4 D0 01              2067 	pop	ar1
   0FE6 D0 05              2068 	pop	ar5
   0FE8 D0 06              2069 	pop	ar6
   0FEA D0 07              2070 	pop	ar7
   0FEC F3                 2071 	movx	@r1,a
                    0432   2072 	C$twitch_ax.c$382$3$7 ==.
                           2073 ;	apps/twitch_ax/twitch_ax.c:382: checksum_cmdr += (uint8) vals[index_cmdr];
   0FED 78 3A              2074 	mov	r0,#_index_cmdr
   0FEF E2                 2075 	movx	a,@r0
   0FF0 24 33              2076 	add	a,#_vals
   0FF2 F9                 2077 	mov	r1,a
   0FF3 E3                 2078 	movx	a,@r1
   0FF4 FC                 2079 	mov	r4,a
   0FF5 78 3B              2080 	mov	r0,#_checksum_cmdr
   0FF7 E2                 2081 	movx	a,@r0
   0FF8 2C                 2082 	add	a,r4
   0FF9 F2                 2083 	movx	@r0,a
                    043F   2084 	C$twitch_ax.c$383$3$7 ==.
                           2085 ;	apps/twitch_ax/twitch_ax.c:383: index_cmdr++;
   0FFA 78 3A              2086 	mov	r0,#_index_cmdr
   0FFC E2                 2087 	movx	a,@r0
   0FFD 24 01              2088 	add	a,#0x01
   0FFF F2                 2089 	movx	@r0,a
                    0445   2090 	C$twitch_ax.c$389$3$7 ==.
                           2091 ;	apps/twitch_ax/twitch_ax.c:389: if(index_cmdr == 7){ // packet complete
   1000 78 3A              2092 	mov	r0,#_index_cmdr
   1002 E2                 2093 	movx	a,@r0
   1003 B4 07 02           2094 	cjne	a,#0x07,00185$
   1006 80 03              2095 	sjmp	00186$
   1008                    2096 00185$:
   1008 02 0F 5C           2097 	ljmp	00153$
   100B                    2098 00186$:
                    0450   2099 	C$twitch_ax.c$393$4$8 ==.
                           2100 ;	apps/twitch_ax/twitch_ax.c:393: if(checksum_cmdr%256 != 255){
   100B 78 3B              2101 	mov	r0,#_checksum_cmdr
   100D E2                 2102 	movx	a,@r0
   100E FB                 2103 	mov	r3,a
   100F 7C 00              2104 	mov	r4,#0x00
   1011 78 EB              2105 	mov	r0,#__modsint_PARM_2
   1013 E4                 2106 	clr	a
   1014 F2                 2107 	movx	@r0,a
   1015 08                 2108 	inc	r0
   1016 74 01              2109 	mov	a,#0x01
   1018 F2                 2110 	movx	@r0,a
   1019 8B 82              2111 	mov	dpl,r3
   101B 8C 83              2112 	mov	dph,r4
   101D C0 07              2113 	push	ar7
   101F C0 06              2114 	push	ar6
   1021 C0 05              2115 	push	ar5
   1023 12 39 02           2116 	lcall	__modsint
   1026 AB 82              2117 	mov	r3,dpl
   1028 AC 83              2118 	mov	r4,dph
   102A D0 05              2119 	pop	ar5
   102C D0 06              2120 	pop	ar6
   102E D0 07              2121 	pop	ar7
   1030 BB FF 05           2122 	cjne	r3,#0xFF,00187$
   1033 BC 00 02           2123 	cjne	r4,#0x00,00187$
   1036 80 0B              2124 	sjmp	00106$
   1038                    2125 00187$:
                    047D   2126 	C$twitch_ax.c$396$5$9 ==.
                           2127 ;	apps/twitch_ax/twitch_ax.c:396: index_cmdr = -1;
   1038 78 3A              2128 	mov	r0,#_index_cmdr
   103A 74 FF              2129 	mov	a,#0xFF
   103C F2                 2130 	movx	@r0,a
                    0482   2131 	C$twitch_ax.c$397$5$9 ==.
                           2132 ;	apps/twitch_ax/twitch_ax.c:397: return 0;
   103D 75 82 00           2133 	mov	dpl,#0x00
   1040 02 13 1F           2134 	ljmp	00156$
   1043                    2135 00106$:
                    0488   2136 	C$twitch_ax.c$400$5$10 ==.
                           2137 ;	apps/twitch_ax/twitch_ax.c:400: buttonval = vals[4];
   1043 78 37              2138 	mov	r0,#(_vals + 0x0004)
   1045 E2                 2139 	movx	a,@r0
   1046 FC                 2140 	mov	r4,a
                    048C   2141 	C$twitch_ax.c$464$5$10 ==.
                           2142 ;	apps/twitch_ax/twitch_ax.c:464: lookV = (signed char)( (int8)vals[0]-128 );
   1047 78 33              2143 	mov	r0,#_vals
   1049 E2                 2144 	movx	a,@r0
   104A 78 3E              2145 	mov	r0,#_lookV
   104C 24 80              2146 	add	a,#0x80
   104E F2                 2147 	movx	@r0,a
                    0494   2148 	C$twitch_ax.c$465$5$10 ==.
                           2149 ;	apps/twitch_ax/twitch_ax.c:465: lookH = (signed char)( (int8)vals[1]-128 );
   104F 78 34              2150 	mov	r0,#(_vals + 0x0001)
   1051 E2                 2151 	movx	a,@r0
   1052 78 3F              2152 	mov	r0,#_lookH
   1054 24 80              2153 	add	a,#0x80
   1056 F2                 2154 	movx	@r0,a
                    049C   2155 	C$twitch_ax.c$485$5$10 ==.
                           2156 ;	apps/twitch_ax/twitch_ax.c:485: walkV = (signed char)( (int8)vals[2]-128 );
   1057 78 35              2157 	mov	r0,#(_vals + 0x0002)
   1059 E2                 2158 	movx	a,@r0
   105A 78 3C              2159 	mov	r0,#_walkV
   105C 24 80              2160 	add	a,#0x80
   105E F2                 2161 	movx	@r0,a
                    04A4   2162 	C$twitch_ax.c$486$5$10 ==.
                           2163 ;	apps/twitch_ax/twitch_ax.c:486: walkH = (signed char)( (int8)vals[3]-128 );
   105F 78 36              2164 	mov	r0,#(_vals + 0x0003)
   1061 E2                 2165 	movx	a,@r0
   1062 FB                 2166 	mov	r3,a
   1063 78 3D              2167 	mov	r0,#_walkH
   1065 24 80              2168 	add	a,#0x80
   1067 F2                 2169 	movx	@r0,a
                    04AD   2170 	C$twitch_ax.c$493$4$8 ==.
                           2171 ;	apps/twitch_ax/twitch_ax.c:493: index_cmdr = -1;
   1068 78 3A              2172 	mov	r0,#_index_cmdr
   106A 74 FF              2173 	mov	a,#0xFF
   106C F2                 2174 	movx	@r0,a
                    04B2   2175 	C$twitch_ax.c$499$4$8 ==.
                           2176 ;	apps/twitch_ax/twitch_ax.c:499: while (radioComRxAvailable() > 0) { radioComRxReceiveByte(); }
   106D                    2177 00108$:
   106D C0 07              2178 	push	ar7
   106F C0 06              2179 	push	ar6
   1071 C0 05              2180 	push	ar5
   1073 C0 04              2181 	push	ar4
   1075 12 35 68           2182 	lcall	_radioComRxAvailable
   1078 E5 82              2183 	mov	a,dpl
   107A D0 04              2184 	pop	ar4
   107C D0 05              2185 	pop	ar5
   107E D0 06              2186 	pop	ar6
   1080 D0 07              2187 	pop	ar7
   1082 60 15              2188 	jz	00110$
   1084 C0 07              2189 	push	ar7
   1086 C0 06              2190 	push	ar6
   1088 C0 05              2191 	push	ar5
   108A C0 04              2192 	push	ar4
   108C 12 35 6F           2193 	lcall	_radioComRxReceiveByte
   108F D0 04              2194 	pop	ar4
   1091 D0 05              2195 	pop	ar5
   1093 D0 06              2196 	pop	ar6
   1095 D0 07              2197 	pop	ar7
   1097 80 D4              2198 	sjmp	00108$
   1099                    2199 00110$:
                    04DE   2200 	C$twitch_ax.c$502$4$8 ==.
                           2201 ;	apps/twitch_ax/twitch_ax.c:502: if ( (lookV > 20 && walkV < -20) || (walkV > 20 && lookV < -20) ) {	///Conflicting directions -> STOP
   1099 78 3E              2202 	mov	r0,#_lookV
   109B C3                 2203 	clr	c
   109C E2                 2204 	movx	a,@r0
   109D F5 F0              2205 	mov	b,a
   109F 74 94              2206 	mov	a,#(0x14 ^ 0x80)
   10A1 63 F0 80           2207 	xrl	b,#0x80
   10A4 95 F0              2208 	subb	a,b
   10A6 E4                 2209 	clr	a
   10A7 33                 2210 	rlc	a
   10A8 FB                 2211 	mov	r3,a
   10A9 60 0A              2212 	jz	00144$
   10AB 78 3C              2213 	mov	r0,#_walkV
   10AD C3                 2214 	clr	c
   10AE E2                 2215 	movx	a,@r0
   10AF 64 80              2216 	xrl	a,#0x80
   10B1 94 6C              2217 	subb	a,#0x6c
   10B3 40 1C              2218 	jc	00139$
   10B5                    2219 00144$:
   10B5 78 3C              2220 	mov	r0,#_walkV
   10B7 C3                 2221 	clr	c
   10B8 E2                 2222 	movx	a,@r0
   10B9 F5 F0              2223 	mov	b,a
   10BB 74 94              2224 	mov	a,#(0x14 ^ 0x80)
   10BD 63 F0 80           2225 	xrl	b,#0x80
   10C0 95 F0              2226 	subb	a,b
   10C2 E4                 2227 	clr	a
   10C3 33                 2228 	rlc	a
   10C4 FA                 2229 	mov	r2,a
   10C5 60 4D              2230 	jz	00140$
   10C7 78 3E              2231 	mov	r0,#_lookV
   10C9 C3                 2232 	clr	c
   10CA E2                 2233 	movx	a,@r0
   10CB 64 80              2234 	xrl	a,#0x80
   10CD 94 6C              2235 	subb	a,#0x6c
   10CF 50 43              2236 	jnc	00140$
   10D1                    2237 00139$:
                    0516   2238 	C$twitch_ax.c$503$5$12 ==.
                           2239 ;	apps/twitch_ax/twitch_ax.c:503: *desiredGait = NO_GAIT;
   10D1 8D 82              2240 	mov	dpl,r5
   10D3 8E 83              2241 	mov	dph,r6
   10D5 8F F0              2242 	mov	b,r7
   10D7 74 64              2243 	mov	a,#0x64
   10D9 12 36 56           2244 	lcall	__gptrput
                    0521   2245 	C$twitch_ax.c$504$5$12 ==.
                           2246 ;	apps/twitch_ax/twitch_ax.c:504: *desiredDir = -1;	// Pointless; Logic chain shouldn't use desiredDir with NO_GAIT...
   10DC 78 4C              2247 	mov	r0,#_CmdrReadMsgs_PARM_2
   10DE E2                 2248 	movx	a,@r0
   10DF F5 41              2249 	mov	_CmdrReadMsgs_sloc0_1_0,a
   10E1 08                 2250 	inc	r0
   10E2 E2                 2251 	movx	a,@r0
   10E3 F5 42              2252 	mov	(_CmdrReadMsgs_sloc0_1_0 + 1),a
   10E5 08                 2253 	inc	r0
   10E6 E2                 2254 	movx	a,@r0
   10E7 F5 43              2255 	mov	(_CmdrReadMsgs_sloc0_1_0 + 2),a
   10E9 85 41 82           2256 	mov	dpl,_CmdrReadMsgs_sloc0_1_0
   10EC 85 42 83           2257 	mov	dph,(_CmdrReadMsgs_sloc0_1_0 + 1)
   10EF 85 43 F0           2258 	mov	b,(_CmdrReadMsgs_sloc0_1_0 + 2)
   10F2 74 FF              2259 	mov	a,#0xFF
   10F4 12 36 56           2260 	lcall	__gptrput
                    053C   2261 	C$twitch_ax.c$505$5$12 ==.
                           2262 ;	apps/twitch_ax/twitch_ax.c:505: *desiredSpeed = 0;
   10F7 78 4F              2263 	mov	r0,#_CmdrReadMsgs_PARM_3
   10F9 E2                 2264 	movx	a,@r0
   10FA F5 41              2265 	mov	_CmdrReadMsgs_sloc0_1_0,a
   10FC 08                 2266 	inc	r0
   10FD E2                 2267 	movx	a,@r0
   10FE F5 42              2268 	mov	(_CmdrReadMsgs_sloc0_1_0 + 1),a
   1100 08                 2269 	inc	r0
   1101 E2                 2270 	movx	a,@r0
   1102 F5 43              2271 	mov	(_CmdrReadMsgs_sloc0_1_0 + 2),a
   1104 85 41 82           2272 	mov	dpl,_CmdrReadMsgs_sloc0_1_0
   1107 85 42 83           2273 	mov	dph,(_CmdrReadMsgs_sloc0_1_0 + 1)
   110A 85 43 F0           2274 	mov	b,(_CmdrReadMsgs_sloc0_1_0 + 2)
   110D E4                 2275 	clr	a
   110E 12 36 56           2276 	lcall	__gptrput
   1111 02 13 17           2277 	ljmp	00141$
   1114                    2278 00140$:
                    0559   2279 	C$twitch_ax.c$507$4$8 ==.
                           2280 ;	apps/twitch_ax/twitch_ax.c:507: } else if (lookV > 20 || walkV > 20 ) {	///walk 
   1114 EB                 2281 	mov	a,r3
   1115 70 03              2282 	jnz	00135$
   1117 EA                 2283 	mov	a,r2
   1118 60 58              2284 	jz	00136$
   111A                    2285 00135$:
                    055F   2286 	C$twitch_ax.c$508$5$13 ==.
                           2287 ;	apps/twitch_ax/twitch_ax.c:508: if(buttonval&BUT_LT || buttonval&BUT_RT){
   111A EC                 2288 	mov	a,r4
   111B 20 E7 04           2289 	jb	acc.7,00111$
   111E EC                 2290 	mov	a,r4
   111F 30 E6 0D           2291 	jnb	acc.6,00112$
   1122                    2292 00111$:
                    0567   2293 	C$twitch_ax.c$509$6$14 ==.
                           2294 ;	apps/twitch_ax/twitch_ax.c:509: *desiredGait = G8_ANIM_WALK_STRAIGHT;
   1122 8D 82              2295 	mov	dpl,r5
   1124 8E 83              2296 	mov	dph,r6
   1126 8F F0              2297 	mov	b,r7
   1128 74 04              2298 	mov	a,#0x04
   112A 12 36 56           2299 	lcall	__gptrput
   112D 80 0A              2300 	sjmp	00113$
   112F                    2301 00112$:
                    0574   2302 	C$twitch_ax.c$511$6$15 ==.
                           2303 ;	apps/twitch_ax/twitch_ax.c:511: *desiredGait = G8_ANIM_WALK_STRAIGHT_SLOW;
   112F 8D 82              2304 	mov	dpl,r5
   1131 8E 83              2305 	mov	dph,r6
   1133 8F F0              2306 	mov	b,r7
   1135 E4                 2307 	clr	a
   1136 12 36 56           2308 	lcall	__gptrput
   1139                    2309 00113$:
                    057E   2310 	C$twitch_ax.c$513$5$13 ==.
                           2311 ;	apps/twitch_ax/twitch_ax.c:513: *desiredDir = 1;
   1139 78 4C              2312 	mov	r0,#_CmdrReadMsgs_PARM_2
   113B E2                 2313 	movx	a,@r0
   113C F5 41              2314 	mov	_CmdrReadMsgs_sloc0_1_0,a
   113E 08                 2315 	inc	r0
   113F E2                 2316 	movx	a,@r0
   1140 F5 42              2317 	mov	(_CmdrReadMsgs_sloc0_1_0 + 1),a
   1142 08                 2318 	inc	r0
   1143 E2                 2319 	movx	a,@r0
   1144 F5 43              2320 	mov	(_CmdrReadMsgs_sloc0_1_0 + 2),a
   1146 85 41 82           2321 	mov	dpl,_CmdrReadMsgs_sloc0_1_0
   1149 85 42 83           2322 	mov	dph,(_CmdrReadMsgs_sloc0_1_0 + 1)
   114C 85 43 F0           2323 	mov	b,(_CmdrReadMsgs_sloc0_1_0 + 2)
   114F 74 01              2324 	mov	a,#0x01
   1151 12 36 56           2325 	lcall	__gptrput
                    0599   2326 	C$twitch_ax.c$514$5$13 ==.
                           2327 ;	apps/twitch_ax/twitch_ax.c:514: *desiredSpeed = 50;
   1154 78 4F              2328 	mov	r0,#_CmdrReadMsgs_PARM_3
   1156 E2                 2329 	movx	a,@r0
   1157 F5 41              2330 	mov	_CmdrReadMsgs_sloc0_1_0,a
   1159 08                 2331 	inc	r0
   115A E2                 2332 	movx	a,@r0
   115B F5 42              2333 	mov	(_CmdrReadMsgs_sloc0_1_0 + 1),a
   115D 08                 2334 	inc	r0
   115E E2                 2335 	movx	a,@r0
   115F F5 43              2336 	mov	(_CmdrReadMsgs_sloc0_1_0 + 2),a
   1161 85 41 82           2337 	mov	dpl,_CmdrReadMsgs_sloc0_1_0
   1164 85 42 83           2338 	mov	dph,(_CmdrReadMsgs_sloc0_1_0 + 1)
   1167 85 43 F0           2339 	mov	b,(_CmdrReadMsgs_sloc0_1_0 + 2)
   116A 74 32              2340 	mov	a,#0x32
   116C 12 36 56           2341 	lcall	__gptrput
   116F 02 13 17           2342 	ljmp	00141$
   1172                    2343 00136$:
                    05B7   2344 	C$twitch_ax.c$516$4$8 ==.
                           2345 ;	apps/twitch_ax/twitch_ax.c:516: } else if (lookV < -20 || walkV < -20) {	///walk 
   1172 78 3E              2346 	mov	r0,#_lookV
   1174 C3                 2347 	clr	c
   1175 E2                 2348 	movx	a,@r0
   1176 64 80              2349 	xrl	a,#0x80
   1178 94 6C              2350 	subb	a,#0x6c
   117A 40 0A              2351 	jc	00131$
   117C 78 3C              2352 	mov	r0,#_walkV
   117E C3                 2353 	clr	c
   117F E2                 2354 	movx	a,@r0
   1180 64 80              2355 	xrl	a,#0x80
   1182 94 6C              2356 	subb	a,#0x6c
   1184 50 4D              2357 	jnc	00132$
   1186                    2358 00131$:
                    05CB   2359 	C$twitch_ax.c$517$5$16 ==.
                           2360 ;	apps/twitch_ax/twitch_ax.c:517: if(buttonval&BUT_LT || buttonval&BUT_RT){
   1186 EC                 2361 	mov	a,r4
   1187 20 E7 04           2362 	jb	acc.7,00115$
   118A EC                 2363 	mov	a,r4
   118B 30 E6 0D           2364 	jnb	acc.6,00116$
   118E                    2365 00115$:
                    05D3   2366 	C$twitch_ax.c$518$6$17 ==.
                           2367 ;	apps/twitch_ax/twitch_ax.c:518: *desiredGait = G8_ANIM_WALK_STRAIGHT_BACK;
   118E 8D 82              2368 	mov	dpl,r5
   1190 8E 83              2369 	mov	dph,r6
   1192 8F F0              2370 	mov	b,r7
   1194 74 06              2371 	mov	a,#0x06
   1196 12 36 56           2372 	lcall	__gptrput
   1199 80 0B              2373 	sjmp	00117$
   119B                    2374 00116$:
                    05E0   2375 	C$twitch_ax.c$520$6$18 ==.
                           2376 ;	apps/twitch_ax/twitch_ax.c:520: *desiredGait = G8_ANIM_WALK_STRAIGHT_BACK_SLOW;
   119B 8D 82              2377 	mov	dpl,r5
   119D 8E 83              2378 	mov	dph,r6
   119F 8F F0              2379 	mov	b,r7
   11A1 74 03              2380 	mov	a,#0x03
   11A3 12 36 56           2381 	lcall	__gptrput
   11A6                    2382 00117$:
                    05EB   2383 	C$twitch_ax.c$522$5$16 ==.
                           2384 ;	apps/twitch_ax/twitch_ax.c:522: *desiredDir = 1;
   11A6 78 4C              2385 	mov	r0,#_CmdrReadMsgs_PARM_2
   11A8 E2                 2386 	movx	a,@r0
   11A9 FA                 2387 	mov	r2,a
   11AA 08                 2388 	inc	r0
   11AB E2                 2389 	movx	a,@r0
   11AC FB                 2390 	mov	r3,a
   11AD 08                 2391 	inc	r0
   11AE E2                 2392 	movx	a,@r0
   11AF FC                 2393 	mov	r4,a
   11B0 8A 82              2394 	mov	dpl,r2
   11B2 8B 83              2395 	mov	dph,r3
   11B4 8C F0              2396 	mov	b,r4
   11B6 74 01              2397 	mov	a,#0x01
   11B8 12 36 56           2398 	lcall	__gptrput
                    0600   2399 	C$twitch_ax.c$523$5$16 ==.
                           2400 ;	apps/twitch_ax/twitch_ax.c:523: *desiredSpeed = 50;
   11BB 78 4F              2401 	mov	r0,#_CmdrReadMsgs_PARM_3
   11BD E2                 2402 	movx	a,@r0
   11BE FA                 2403 	mov	r2,a
   11BF 08                 2404 	inc	r0
   11C0 E2                 2405 	movx	a,@r0
   11C1 FB                 2406 	mov	r3,a
   11C2 08                 2407 	inc	r0
   11C3 E2                 2408 	movx	a,@r0
   11C4 FC                 2409 	mov	r4,a
   11C5 8A 82              2410 	mov	dpl,r2
   11C7 8B 83              2411 	mov	dph,r3
   11C9 8C F0              2412 	mov	b,r4
   11CB 74 32              2413 	mov	a,#0x32
   11CD 12 36 56           2414 	lcall	__gptrput
   11D0 02 13 17           2415 	ljmp	00141$
   11D3                    2416 00132$:
                    0618   2417 	C$twitch_ax.c$553$4$8 ==.
                           2418 ;	apps/twitch_ax/twitch_ax.c:553: } else if (walkH > 20) {	///Turn right fast
   11D3 78 3D              2419 	mov	r0,#_walkH
   11D5 C3                 2420 	clr	c
   11D6 E2                 2421 	movx	a,@r0
   11D7 F5 F0              2422 	mov	b,a
   11D9 74 94              2423 	mov	a,#(0x14 ^ 0x80)
   11DB 63 F0 80           2424 	xrl	b,#0x80
   11DE 95 F0              2425 	subb	a,b
   11E0 50 38              2426 	jnc	00129$
                    0627   2427 	C$twitch_ax.c$555$5$19 ==.
                           2428 ;	apps/twitch_ax/twitch_ax.c:555: *desiredGait = G8_ANIM_TURN_RIGHT;
   11E2 8D 82              2429 	mov	dpl,r5
   11E4 8E 83              2430 	mov	dph,r6
   11E6 8F F0              2431 	mov	b,r7
   11E8 74 02              2432 	mov	a,#0x02
   11EA 12 36 56           2433 	lcall	__gptrput
                    0632   2434 	C$twitch_ax.c$556$5$19 ==.
                           2435 ;	apps/twitch_ax/twitch_ax.c:556: *desiredDir = 1;
   11ED 78 4C              2436 	mov	r0,#_CmdrReadMsgs_PARM_2
   11EF E2                 2437 	movx	a,@r0
   11F0 FA                 2438 	mov	r2,a
   11F1 08                 2439 	inc	r0
   11F2 E2                 2440 	movx	a,@r0
   11F3 FB                 2441 	mov	r3,a
   11F4 08                 2442 	inc	r0
   11F5 E2                 2443 	movx	a,@r0
   11F6 FC                 2444 	mov	r4,a
   11F7 8A 82              2445 	mov	dpl,r2
   11F9 8B 83              2446 	mov	dph,r3
   11FB 8C F0              2447 	mov	b,r4
   11FD 74 01              2448 	mov	a,#0x01
   11FF 12 36 56           2449 	lcall	__gptrput
                    0647   2450 	C$twitch_ax.c$557$5$19 ==.
                           2451 ;	apps/twitch_ax/twitch_ax.c:557: *desiredSpeed = 70;
   1202 78 4F              2452 	mov	r0,#_CmdrReadMsgs_PARM_3
   1204 E2                 2453 	movx	a,@r0
   1205 FA                 2454 	mov	r2,a
   1206 08                 2455 	inc	r0
   1207 E2                 2456 	movx	a,@r0
   1208 FB                 2457 	mov	r3,a
   1209 08                 2458 	inc	r0
   120A E2                 2459 	movx	a,@r0
   120B FC                 2460 	mov	r4,a
   120C 8A 82              2461 	mov	dpl,r2
   120E 8B 83              2462 	mov	dph,r3
   1210 8C F0              2463 	mov	b,r4
   1212 74 46              2464 	mov	a,#0x46
   1214 12 36 56           2465 	lcall	__gptrput
   1217 02 13 17           2466 	ljmp	00141$
   121A                    2467 00129$:
                    065F   2468 	C$twitch_ax.c$558$4$8 ==.
                           2469 ;	apps/twitch_ax/twitch_ax.c:558: } else if (walkH < -20) {	///Turn left
   121A 78 3D              2470 	mov	r0,#_walkH
   121C C3                 2471 	clr	c
   121D E2                 2472 	movx	a,@r0
   121E 64 80              2473 	xrl	a,#0x80
   1220 94 6C              2474 	subb	a,#0x6c
   1222 50 38              2475 	jnc	00126$
                    0669   2476 	C$twitch_ax.c$560$5$20 ==.
                           2477 ;	apps/twitch_ax/twitch_ax.c:560: *desiredGait = G8_ANIM_TURN_RIGHT;
   1224 8D 82              2478 	mov	dpl,r5
   1226 8E 83              2479 	mov	dph,r6
   1228 8F F0              2480 	mov	b,r7
   122A 74 02              2481 	mov	a,#0x02
   122C 12 36 56           2482 	lcall	__gptrput
                    0674   2483 	C$twitch_ax.c$561$5$20 ==.
                           2484 ;	apps/twitch_ax/twitch_ax.c:561: *desiredDir = -1;
   122F 78 4C              2485 	mov	r0,#_CmdrReadMsgs_PARM_2
   1231 E2                 2486 	movx	a,@r0
   1232 FA                 2487 	mov	r2,a
   1233 08                 2488 	inc	r0
   1234 E2                 2489 	movx	a,@r0
   1235 FB                 2490 	mov	r3,a
   1236 08                 2491 	inc	r0
   1237 E2                 2492 	movx	a,@r0
   1238 FC                 2493 	mov	r4,a
   1239 8A 82              2494 	mov	dpl,r2
   123B 8B 83              2495 	mov	dph,r3
   123D 8C F0              2496 	mov	b,r4
   123F 74 FF              2497 	mov	a,#0xFF
   1241 12 36 56           2498 	lcall	__gptrput
                    0689   2499 	C$twitch_ax.c$562$5$20 ==.
                           2500 ;	apps/twitch_ax/twitch_ax.c:562: *desiredSpeed = -70;
   1244 78 4F              2501 	mov	r0,#_CmdrReadMsgs_PARM_3
   1246 E2                 2502 	movx	a,@r0
   1247 FA                 2503 	mov	r2,a
   1248 08                 2504 	inc	r0
   1249 E2                 2505 	movx	a,@r0
   124A FB                 2506 	mov	r3,a
   124B 08                 2507 	inc	r0
   124C E2                 2508 	movx	a,@r0
   124D FC                 2509 	mov	r4,a
   124E 8A 82              2510 	mov	dpl,r2
   1250 8B 83              2511 	mov	dph,r3
   1252 8C F0              2512 	mov	b,r4
   1254 74 BA              2513 	mov	a,#0xBA
   1256 12 36 56           2514 	lcall	__gptrput
   1259 02 13 17           2515 	ljmp	00141$
   125C                    2516 00126$:
                    06A1   2517 	C$twitch_ax.c$563$4$8 ==.
                           2518 ;	apps/twitch_ax/twitch_ax.c:563: } else if (lookH > 20) {	///Turn right fast
   125C 78 3F              2519 	mov	r0,#_lookH
   125E C3                 2520 	clr	c
   125F E2                 2521 	movx	a,@r0
   1260 F5 F0              2522 	mov	b,a
   1262 74 94              2523 	mov	a,#(0x14 ^ 0x80)
   1264 63 F0 80           2524 	xrl	b,#0x80
   1267 95 F0              2525 	subb	a,b
   1269 50 37              2526 	jnc	00123$
                    06B0   2527 	C$twitch_ax.c$565$5$21 ==.
                           2528 ;	apps/twitch_ax/twitch_ax.c:565: *desiredGait = G8_ANIM_TURN_SLOW;
   126B 8D 82              2529 	mov	dpl,r5
   126D 8E 83              2530 	mov	dph,r6
   126F 8F F0              2531 	mov	b,r7
   1271 74 05              2532 	mov	a,#0x05
   1273 12 36 56           2533 	lcall	__gptrput
                    06BB   2534 	C$twitch_ax.c$566$5$21 ==.
                           2535 ;	apps/twitch_ax/twitch_ax.c:566: *desiredDir = 1;
   1276 78 4C              2536 	mov	r0,#_CmdrReadMsgs_PARM_2
   1278 E2                 2537 	movx	a,@r0
   1279 FA                 2538 	mov	r2,a
   127A 08                 2539 	inc	r0
   127B E2                 2540 	movx	a,@r0
   127C FB                 2541 	mov	r3,a
   127D 08                 2542 	inc	r0
   127E E2                 2543 	movx	a,@r0
   127F FC                 2544 	mov	r4,a
   1280 8A 82              2545 	mov	dpl,r2
   1282 8B 83              2546 	mov	dph,r3
   1284 8C F0              2547 	mov	b,r4
   1286 74 01              2548 	mov	a,#0x01
   1288 12 36 56           2549 	lcall	__gptrput
                    06D0   2550 	C$twitch_ax.c$567$5$21 ==.
                           2551 ;	apps/twitch_ax/twitch_ax.c:567: *desiredSpeed = 70;
   128B 78 4F              2552 	mov	r0,#_CmdrReadMsgs_PARM_3
   128D E2                 2553 	movx	a,@r0
   128E FA                 2554 	mov	r2,a
   128F 08                 2555 	inc	r0
   1290 E2                 2556 	movx	a,@r0
   1291 FB                 2557 	mov	r3,a
   1292 08                 2558 	inc	r0
   1293 E2                 2559 	movx	a,@r0
   1294 FC                 2560 	mov	r4,a
   1295 8A 82              2561 	mov	dpl,r2
   1297 8B 83              2562 	mov	dph,r3
   1299 8C F0              2563 	mov	b,r4
   129B 74 46              2564 	mov	a,#0x46
   129D 12 36 56           2565 	lcall	__gptrput
   12A0 80 75              2566 	sjmp	00141$
   12A2                    2567 00123$:
                    06E7   2568 	C$twitch_ax.c$568$4$8 ==.
                           2569 ;	apps/twitch_ax/twitch_ax.c:568: } else if (lookH < -20) {	///Turn left
   12A2 78 3F              2570 	mov	r0,#_lookH
   12A4 C3                 2571 	clr	c
   12A5 E2                 2572 	movx	a,@r0
   12A6 64 80              2573 	xrl	a,#0x80
   12A8 94 6C              2574 	subb	a,#0x6c
   12AA 50 37              2575 	jnc	00120$
                    06F1   2576 	C$twitch_ax.c$570$5$22 ==.
                           2577 ;	apps/twitch_ax/twitch_ax.c:570: *desiredGait = G8_ANIM_TURN_SLOW;
   12AC 8D 82              2578 	mov	dpl,r5
   12AE 8E 83              2579 	mov	dph,r6
   12B0 8F F0              2580 	mov	b,r7
   12B2 74 05              2581 	mov	a,#0x05
   12B4 12 36 56           2582 	lcall	__gptrput
                    06FC   2583 	C$twitch_ax.c$571$5$22 ==.
                           2584 ;	apps/twitch_ax/twitch_ax.c:571: *desiredDir = -1;
   12B7 78 4C              2585 	mov	r0,#_CmdrReadMsgs_PARM_2
   12B9 E2                 2586 	movx	a,@r0
   12BA FA                 2587 	mov	r2,a
   12BB 08                 2588 	inc	r0
   12BC E2                 2589 	movx	a,@r0
   12BD FB                 2590 	mov	r3,a
   12BE 08                 2591 	inc	r0
   12BF E2                 2592 	movx	a,@r0
   12C0 FC                 2593 	mov	r4,a
   12C1 8A 82              2594 	mov	dpl,r2
   12C3 8B 83              2595 	mov	dph,r3
   12C5 8C F0              2596 	mov	b,r4
   12C7 74 FF              2597 	mov	a,#0xFF
   12C9 12 36 56           2598 	lcall	__gptrput
                    0711   2599 	C$twitch_ax.c$572$5$22 ==.
                           2600 ;	apps/twitch_ax/twitch_ax.c:572: *desiredSpeed = -70;
   12CC 78 4F              2601 	mov	r0,#_CmdrReadMsgs_PARM_3
   12CE E2                 2602 	movx	a,@r0
   12CF FA                 2603 	mov	r2,a
   12D0 08                 2604 	inc	r0
   12D1 E2                 2605 	movx	a,@r0
   12D2 FB                 2606 	mov	r3,a
   12D3 08                 2607 	inc	r0
   12D4 E2                 2608 	movx	a,@r0
   12D5 FC                 2609 	mov	r4,a
   12D6 8A 82              2610 	mov	dpl,r2
   12D8 8B 83              2611 	mov	dph,r3
   12DA 8C F0              2612 	mov	b,r4
   12DC 74 BA              2613 	mov	a,#0xBA
   12DE 12 36 56           2614 	lcall	__gptrput
   12E1 80 34              2615 	sjmp	00141$
   12E3                    2616 00120$:
                    0728   2617 	C$twitch_ax.c$583$5$23 ==.
                           2618 ;	apps/twitch_ax/twitch_ax.c:583: *desiredGait = NO_GAIT;
   12E3 8D 82              2619 	mov	dpl,r5
   12E5 8E 83              2620 	mov	dph,r6
   12E7 8F F0              2621 	mov	b,r7
   12E9 74 64              2622 	mov	a,#0x64
   12EB 12 36 56           2623 	lcall	__gptrput
                    0733   2624 	C$twitch_ax.c$584$5$23 ==.
                           2625 ;	apps/twitch_ax/twitch_ax.c:584: *desiredDir = -1;	// Pointless; Logic chain shouldn't use desiredDir with NO_GAIT...
   12EE 78 4C              2626 	mov	r0,#_CmdrReadMsgs_PARM_2
   12F0 E2                 2627 	movx	a,@r0
   12F1 FD                 2628 	mov	r5,a
   12F2 08                 2629 	inc	r0
   12F3 E2                 2630 	movx	a,@r0
   12F4 FE                 2631 	mov	r6,a
   12F5 08                 2632 	inc	r0
   12F6 E2                 2633 	movx	a,@r0
   12F7 FF                 2634 	mov	r7,a
   12F8 8D 82              2635 	mov	dpl,r5
   12FA 8E 83              2636 	mov	dph,r6
   12FC 8F F0              2637 	mov	b,r7
   12FE 74 FF              2638 	mov	a,#0xFF
   1300 12 36 56           2639 	lcall	__gptrput
                    0748   2640 	C$twitch_ax.c$585$5$23 ==.
                           2641 ;	apps/twitch_ax/twitch_ax.c:585: *desiredSpeed = 0;
   1303 78 4F              2642 	mov	r0,#_CmdrReadMsgs_PARM_3
   1305 E2                 2643 	movx	a,@r0
   1306 FD                 2644 	mov	r5,a
   1307 08                 2645 	inc	r0
   1308 E2                 2646 	movx	a,@r0
   1309 FE                 2647 	mov	r6,a
   130A 08                 2648 	inc	r0
   130B E2                 2649 	movx	a,@r0
   130C FF                 2650 	mov	r7,a
   130D 8D 82              2651 	mov	dpl,r5
   130F 8E 83              2652 	mov	dph,r6
   1311 8F F0              2653 	mov	b,r7
   1313 E4                 2654 	clr	a
   1314 12 36 56           2655 	lcall	__gptrput
   1317                    2656 00141$:
                    075C   2657 	C$twitch_ax.c$587$4$8 ==.
                           2658 ;	apps/twitch_ax/twitch_ax.c:587: return 1;
   1317 75 82 01           2659 	mov	dpl,#0x01
   131A 80 03              2660 	sjmp	00156$
   131C                    2661 00155$:
                    0761   2662 	C$twitch_ax.c$591$1$1 ==.
                           2663 ;	apps/twitch_ax/twitch_ax.c:591: return 0;
   131C 75 82 00           2664 	mov	dpl,#0x00
   131F                    2665 00156$:
                    0764   2666 	C$twitch_ax.c$592$1$1 ==.
                    0764   2667 	XG$CmdrReadMsgs$0$0 ==.
   131F 22                 2668 	ret
                           2669 ;------------------------------------------------------------
                           2670 ;Allocation info for local variables in function 'gaitRunnerInit'
                           2671 ;------------------------------------------------------------
                    0765   2672 	G$gaitRunnerInit$0$0 ==.
                    0765   2673 	C$twitch_ax.c$597$1$1 ==.
                           2674 ;	apps/twitch_ax/twitch_ax.c:597: void gaitRunnerInit(G8_RUNNER* runner){
                           2675 ;	-----------------------------------------
                           2676 ;	 function gaitRunnerInit
                           2677 ;	-----------------------------------------
   1320                    2678 _gaitRunnerInit:
   1320 AD 82              2679 	mov	r5,dpl
   1322 AE 83              2680 	mov	r6,dph
   1324 AF F0              2681 	mov	r7,b
                    076B   2682 	C$twitch_ax.c$598$1$1 ==.
                           2683 ;	apps/twitch_ax/twitch_ax.c:598: if(runner->speeds == null){
   1326 74 11              2684 	mov	a,#0x11
   1328 2D                 2685 	add	a,r5
   1329 FD                 2686 	mov	r5,a
   132A E4                 2687 	clr	a
   132B 3E                 2688 	addc	a,r6
   132C FE                 2689 	mov	r6,a
   132D 8D 82              2690 	mov	dpl,r5
   132F 8E 83              2691 	mov	dph,r6
   1331 8F F0              2692 	mov	b,r7
   1333 12 42 C6           2693 	lcall	__gptrget
   1336 FA                 2694 	mov	r2,a
   1337 A3                 2695 	inc	dptr
   1338 12 42 C6           2696 	lcall	__gptrget
   133B FB                 2697 	mov	r3,a
   133C A3                 2698 	inc	dptr
   133D 12 42 C6           2699 	lcall	__gptrget
   1340 FC                 2700 	mov	r4,a
   1341 EA                 2701 	mov	a,r2
   1342 4B                 2702 	orl	a,r3
   1343 70 5A              2703 	jnz	00107$
                    078A   2704 	C$twitch_ax.c$600$2$2 ==.
                           2705 ;	apps/twitch_ax/twitch_ax.c:600: runner->speeds = malloc(NUM_ACTUATORS * sizeof(int8));
   1345 90 00 03           2706 	mov	dptr,#0x0003
   1348 C0 07              2707 	push	ar7
   134A C0 06              2708 	push	ar6
   134C C0 05              2709 	push	ar5
   134E 12 36 D7           2710 	lcall	_malloc
   1351 AB 82              2711 	mov	r3,dpl
   1353 AC 83              2712 	mov	r4,dph
   1355 D0 05              2713 	pop	ar5
   1357 D0 06              2714 	pop	ar6
   1359 D0 07              2715 	pop	ar7
   135B 7A 00              2716 	mov	r2,#0x00
   135D 8D 82              2717 	mov	dpl,r5
   135F 8E 83              2718 	mov	dph,r6
   1361 8F F0              2719 	mov	b,r7
   1363 EB                 2720 	mov	a,r3
   1364 12 36 56           2721 	lcall	__gptrput
   1367 A3                 2722 	inc	dptr
   1368 EC                 2723 	mov	a,r4
   1369 12 36 56           2724 	lcall	__gptrput
   136C A3                 2725 	inc	dptr
   136D EA                 2726 	mov	a,r2
   136E 12 36 56           2727 	lcall	__gptrput
                    07B6   2728 	C$twitch_ax.c$602$2$1 ==.
                           2729 ;	apps/twitch_ax/twitch_ax.c:602: for(i=0; i < NUM_ACTUATORS; i++){
   1371 7C 00              2730 	mov	r4,#0x00
   1373                    2731 00103$:
   1373 BC 03 00           2732 	cjne	r4,#0x03,00114$
   1376                    2733 00114$:
   1376 50 27              2734 	jnc	00107$
                    07BD   2735 	C$twitch_ax.c$604$3$3 ==.
                           2736 ;	apps/twitch_ax/twitch_ax.c:604: runner->speeds[i] = 0;
   1378 8D 82              2737 	mov	dpl,r5
   137A 8E 83              2738 	mov	dph,r6
   137C 8F F0              2739 	mov	b,r7
   137E 12 42 C6           2740 	lcall	__gptrget
   1381 F9                 2741 	mov	r1,a
   1382 A3                 2742 	inc	dptr
   1383 12 42 C6           2743 	lcall	__gptrget
   1386 FA                 2744 	mov	r2,a
   1387 A3                 2745 	inc	dptr
   1388 12 42 C6           2746 	lcall	__gptrget
   138B FB                 2747 	mov	r3,a
   138C EC                 2748 	mov	a,r4
   138D 29                 2749 	add	a,r1
   138E F9                 2750 	mov	r1,a
   138F E4                 2751 	clr	a
   1390 3A                 2752 	addc	a,r2
   1391 FA                 2753 	mov	r2,a
   1392 89 82              2754 	mov	dpl,r1
   1394 8A 83              2755 	mov	dph,r2
   1396 8B F0              2756 	mov	b,r3
   1398 E4                 2757 	clr	a
   1399 12 36 56           2758 	lcall	__gptrput
                    07E1   2759 	C$twitch_ax.c$602$2$2 ==.
                           2760 ;	apps/twitch_ax/twitch_ax.c:602: for(i=0; i < NUM_ACTUATORS; i++){
   139C 0C                 2761 	inc	r4
   139D 80 D4              2762 	sjmp	00103$
   139F                    2763 00107$:
                    07E4   2764 	C$twitch_ax.c$607$2$1 ==.
                    07E4   2765 	XG$gaitRunnerInit$0$0 ==.
   139F 22                 2766 	ret
                           2767 ;------------------------------------------------------------
                           2768 ;Allocation info for local variables in function 'gaitRunnerPlay'
                           2769 ;------------------------------------------------------------
                           2770 ;sloc1                     Allocated with name '_gaitRunnerPlay_sloc1_1_0'
                           2771 ;------------------------------------------------------------
                    07E5   2772 	G$gaitRunnerPlay$0$0 ==.
                    07E5   2773 	C$twitch_ax.c$610$2$1 ==.
                           2774 ;	apps/twitch_ax/twitch_ax.c:610: void gaitRunnerPlay(G8_RUNNER* runner, uint8 animation, int16 loopSpeed, int8 speed, int8 repeatCount){
                           2775 ;	-----------------------------------------
                           2776 ;	 function gaitRunnerPlay
                           2777 ;	-----------------------------------------
   13A0                    2778 _gaitRunnerPlay:
   13A0 AD 82              2779 	mov	r5,dpl
   13A2 AE 83              2780 	mov	r6,dph
   13A4 AF F0              2781 	mov	r7,b
                    07EB   2782 	C$twitch_ax.c$613$1$1 ==.
                           2783 ;	apps/twitch_ax/twitch_ax.c:613: uint32 now = getMs();
   13A6 C0 07              2784 	push	ar7
   13A8 C0 06              2785 	push	ar6
   13AA C0 05              2786 	push	ar5
   13AC 12 3B 8B           2787 	lcall	_getMs
   13AF 78 57              2788 	mov	r0,#_gaitRunnerPlay_now_1_1
   13B1 C0 E0              2789 	push	acc
   13B3 E5 82              2790 	mov	a,dpl
   13B5 F2                 2791 	movx	@r0,a
   13B6 08                 2792 	inc	r0
   13B7 E5 83              2793 	mov	a,dph
   13B9 F2                 2794 	movx	@r0,a
   13BA 08                 2795 	inc	r0
   13BB E5 F0              2796 	mov	a,b
   13BD F2                 2797 	movx	@r0,a
   13BE D0 E0              2798 	pop	acc
   13C0 08                 2799 	inc	r0
   13C1 F2                 2800 	movx	@r0,a
   13C2 D0 05              2801 	pop	ar5
   13C4 D0 06              2802 	pop	ar6
   13C6 D0 07              2803 	pop	ar7
                    080D   2804 	C$twitch_ax.c$629$1$1 ==.
                           2805 ;	apps/twitch_ax/twitch_ax.c:629: }
   13C8 D2 05              2806 	setb	_gaitRunnerPlay_sloc0_1_0
   13CA 10 AF 02           2807 	jbc	ea,00106$
   13CD C2 05              2808 	clr	_gaitRunnerPlay_sloc0_1_0
   13CF                    2809 00106$:
                    0814   2810 	C$twitch_ax.c$619$2$2 ==.
                           2811 ;	apps/twitch_ax/twitch_ax.c:619: runner->animation = animation;
   13CF 74 03              2812 	mov	a,#0x03
   13D1 2D                 2813 	add	a,r5
   13D2 FA                 2814 	mov	r2,a
   13D3 E4                 2815 	clr	a
   13D4 3E                 2816 	addc	a,r6
   13D5 FB                 2817 	mov	r3,a
   13D6 8F 04              2818 	mov	ar4,r7
   13D8 8A 82              2819 	mov	dpl,r2
   13DA 8B 83              2820 	mov	dph,r3
   13DC 8C F0              2821 	mov	b,r4
   13DE 78 52              2822 	mov	r0,#_gaitRunnerPlay_PARM_2
   13E0 E2                 2823 	movx	a,@r0
   13E1 12 36 56           2824 	lcall	__gptrput
                    0829   2825 	C$twitch_ax.c$620$2$2 ==.
                           2826 ;	apps/twitch_ax/twitch_ax.c:620: runner->repeatCount = repeatCount;
   13E4 74 05              2827 	mov	a,#0x05
   13E6 2D                 2828 	add	a,r5
   13E7 FA                 2829 	mov	r2,a
   13E8 E4                 2830 	clr	a
   13E9 3E                 2831 	addc	a,r6
   13EA FB                 2832 	mov	r3,a
   13EB 8F 04              2833 	mov	ar4,r7
   13ED 8A 82              2834 	mov	dpl,r2
   13EF 8B 83              2835 	mov	dph,r3
   13F1 8C F0              2836 	mov	b,r4
   13F3 78 56              2837 	mov	r0,#_gaitRunnerPlay_PARM_5
   13F5 E2                 2838 	movx	a,@r0
   13F6 12 36 56           2839 	lcall	__gptrput
                    083E   2840 	C$twitch_ax.c$621$2$2 ==.
                           2841 ;	apps/twitch_ax/twitch_ax.c:621: runner->frame = 0;
   13F9 74 04              2842 	mov	a,#0x04
   13FB 2D                 2843 	add	a,r5
   13FC FA                 2844 	mov	r2,a
   13FD E4                 2845 	clr	a
   13FE 3E                 2846 	addc	a,r6
   13FF FB                 2847 	mov	r3,a
   1400 8F 04              2848 	mov	ar4,r7
   1402 8A 82              2849 	mov	dpl,r2
   1404 8B 83              2850 	mov	dph,r3
   1406 8C F0              2851 	mov	b,r4
   1408 E4                 2852 	clr	a
   1409 12 36 56           2853 	lcall	__gptrput
                    0851   2854 	C$twitch_ax.c$622$2$2 ==.
                           2855 ;	apps/twitch_ax/twitch_ax.c:622: runner->playing = TRUE;
   140C 74 06              2856 	mov	a,#0x06
   140E 2D                 2857 	add	a,r5
   140F FA                 2858 	mov	r2,a
   1410 E4                 2859 	clr	a
   1411 3E                 2860 	addc	a,r6
   1412 FB                 2861 	mov	r3,a
   1413 8F 04              2862 	mov	ar4,r7
   1415 8A 82              2863 	mov	dpl,r2
   1417 8B 83              2864 	mov	dph,r3
   1419 8C F0              2865 	mov	b,r4
   141B 74 01              2866 	mov	a,#0x01
   141D 12 36 56           2867 	lcall	__gptrput
                    0865   2868 	C$twitch_ax.c$623$2$2 ==.
                           2869 ;	apps/twitch_ax/twitch_ax.c:623: runner->startTime =  now;
   1420 74 07              2870 	mov	a,#0x07
   1422 2D                 2871 	add	a,r5
   1423 FA                 2872 	mov	r2,a
   1424 E4                 2873 	clr	a
   1425 3E                 2874 	addc	a,r6
   1426 FB                 2875 	mov	r3,a
   1427 8F 04              2876 	mov	ar4,r7
   1429 8A 82              2877 	mov	dpl,r2
   142B 8B 83              2878 	mov	dph,r3
   142D 8C F0              2879 	mov	b,r4
   142F 78 57              2880 	mov	r0,#_gaitRunnerPlay_now_1_1
   1431 E2                 2881 	movx	a,@r0
   1432 12 36 56           2882 	lcall	__gptrput
   1435 A3                 2883 	inc	dptr
   1436 08                 2884 	inc	r0
   1437 E2                 2885 	movx	a,@r0
   1438 12 36 56           2886 	lcall	__gptrput
   143B A3                 2887 	inc	dptr
   143C 08                 2888 	inc	r0
   143D E2                 2889 	movx	a,@r0
   143E 12 36 56           2890 	lcall	__gptrput
   1441 A3                 2891 	inc	dptr
   1442 08                 2892 	inc	r0
   1443 E2                 2893 	movx	a,@r0
   1444 12 36 56           2894 	lcall	__gptrput
                    088C   2895 	C$twitch_ax.c$624$2$2 ==.
                           2896 ;	apps/twitch_ax/twitch_ax.c:624: runner->currentTime = (speed<0) ? loopSpeed : 0;
   1447 74 0B              2897 	mov	a,#0x0B
   1449 2D                 2898 	add	a,r5
   144A FA                 2899 	mov	r2,a
   144B E4                 2900 	clr	a
   144C 3E                 2901 	addc	a,r6
   144D FB                 2902 	mov	r3,a
   144E 8F 04              2903 	mov	ar4,r7
   1450 78 55              2904 	mov	r0,#_gaitRunnerPlay_PARM_4
   1452 E2                 2905 	movx	a,@r0
   1453 30 E7 0B           2906 	jnb	acc.7,00103$
   1456 78 53              2907 	mov	r0,#_gaitRunnerPlay_PARM_3
   1458 E2                 2908 	movx	a,@r0
   1459 F5 44              2909 	mov	_gaitRunnerPlay_sloc1_1_0,a
   145B 08                 2910 	inc	r0
   145C E2                 2911 	movx	a,@r0
   145D F5 45              2912 	mov	(_gaitRunnerPlay_sloc1_1_0 + 1),a
   145F 80 05              2913 	sjmp	00104$
   1461                    2914 00103$:
   1461 E4                 2915 	clr	a
   1462 F5 44              2916 	mov	_gaitRunnerPlay_sloc1_1_0,a
   1464 F5 45              2917 	mov	(_gaitRunnerPlay_sloc1_1_0 + 1),a
   1466                    2918 00104$:
   1466 8A 82              2919 	mov	dpl,r2
   1468 8B 83              2920 	mov	dph,r3
   146A 8C F0              2921 	mov	b,r4
   146C E5 44              2922 	mov	a,_gaitRunnerPlay_sloc1_1_0
   146E 12 36 56           2923 	lcall	__gptrput
   1471 A3                 2924 	inc	dptr
   1472 E5 45              2925 	mov	a,(_gaitRunnerPlay_sloc1_1_0 + 1)
   1474 12 36 56           2926 	lcall	__gptrput
                    08BC   2927 	C$twitch_ax.c$625$2$2 ==.
                           2928 ;	apps/twitch_ax/twitch_ax.c:625: runner->totalTime = loopSpeed;	///Always positive?
   1477 74 0D              2929 	mov	a,#0x0D
   1479 2D                 2930 	add	a,r5
   147A FA                 2931 	mov	r2,a
   147B E4                 2932 	clr	a
   147C 3E                 2933 	addc	a,r6
   147D FB                 2934 	mov	r3,a
   147E 8F 04              2935 	mov	ar4,r7
   1480 8A 82              2936 	mov	dpl,r2
   1482 8B 83              2937 	mov	dph,r3
   1484 8C F0              2938 	mov	b,r4
   1486 78 53              2939 	mov	r0,#_gaitRunnerPlay_PARM_3
   1488 E2                 2940 	movx	a,@r0
   1489 12 36 56           2941 	lcall	__gptrput
   148C A3                 2942 	inc	dptr
   148D 08                 2943 	inc	r0
   148E E2                 2944 	movx	a,@r0
   148F 12 36 56           2945 	lcall	__gptrput
                    08D7   2946 	C$twitch_ax.c$626$2$2 ==.
                           2947 ;	apps/twitch_ax/twitch_ax.c:626: runner->speed = speed;
   1492 74 10              2948 	mov	a,#0x10
   1494 2D                 2949 	add	a,r5
   1495 FA                 2950 	mov	r2,a
   1496 E4                 2951 	clr	a
   1497 3E                 2952 	addc	a,r6
   1498 FB                 2953 	mov	r3,a
   1499 8F 04              2954 	mov	ar4,r7
   149B 8A 82              2955 	mov	dpl,r2
   149D 8B 83              2956 	mov	dph,r3
   149F 8C F0              2957 	mov	b,r4
   14A1 78 55              2958 	mov	r0,#_gaitRunnerPlay_PARM_4
   14A3 E2                 2959 	movx	a,@r0
   14A4 12 36 56           2960 	lcall	__gptrput
                    08EC   2961 	C$twitch_ax.c$627$2$2 ==.
                           2962 ;	apps/twitch_ax/twitch_ax.c:627: runner->backwards = FALSE;
   14A7 74 0F              2963 	mov	a,#0x0F
   14A9 2D                 2964 	add	a,r5
   14AA FA                 2965 	mov	r2,a
   14AB E4                 2966 	clr	a
   14AC 3E                 2967 	addc	a,r6
   14AD FB                 2968 	mov	r3,a
   14AE 8F 04              2969 	mov	ar4,r7
   14B0 8A 82              2970 	mov	dpl,r2
   14B2 8B 83              2971 	mov	dph,r3
   14B4 8C F0              2972 	mov	b,r4
   14B6 E4                 2973 	clr	a
   14B7 12 36 56           2974 	lcall	__gptrput
   14BA A2 05              2975 	mov	c,_gaitRunnerPlay_sloc0_1_0
   14BC 92 AF              2976 	mov	ea,c
                    0903   2977 	C$twitch_ax.c$631$1$1 ==.
                           2978 ;	apps/twitch_ax/twitch_ax.c:631: gaitRunnerProcess(runner);
   14BE 8D 82              2979 	mov	dpl,r5
   14C0 8E 83              2980 	mov	dph,r6
   14C2 8F F0              2981 	mov	b,r7
   14C4 12 18 AC           2982 	lcall	_gaitRunnerProcess
                    090C   2983 	C$twitch_ax.c$632$1$1 ==.
                    090C   2984 	XG$gaitRunnerPlay$0$0 ==.
   14C7 22                 2985 	ret
                           2986 ;------------------------------------------------------------
                           2987 ;Allocation info for local variables in function 'calcX'
                           2988 ;------------------------------------------------------------
                           2989 ;sloc0                     Allocated with name '_calcX_sloc0_1_0'
                           2990 ;------------------------------------------------------------
                    090D   2991 	Ftwitch_ax$calcX$0$0 ==.
                    090D   2992 	C$twitch_ax.c$642$1$1 ==.
                           2993 ;	apps/twitch_ax/twitch_ax.c:642: static uint16 calcX(const G8_LIMB_POSITION* limb, float t1){
                           2994 ;	-----------------------------------------
                           2995 ;	 function calcX
                           2996 ;	-----------------------------------------
   14C8                    2997 _calcX:
                    090D   2998 	C$twitch_ax.c$643$1$1 ==.
                           2999 ;	apps/twitch_ax/twitch_ax.c:643: int16 a = (int16)pgm_read_word(&limb->cubeX);
   14C8 AD 82              3000 	mov	r5,dpl
   14CA AE 83              3001 	mov	r6,dph
   14CC AF F0              3002 	mov	r7,b
   14CE 78 5F              3003 	mov	r0,#_calcX_a_1_1
   14D0 12 42 C6           3004 	lcall	__gptrget
   14D3 F2                 3005 	movx	@r0,a
   14D4 A3                 3006 	inc	dptr
   14D5 12 42 C6           3007 	lcall	__gptrget
   14D8 08                 3008 	inc	r0
   14D9 F2                 3009 	movx	@r0,a
                    091F   3010 	C$twitch_ax.c$644$1$1 ==.
                           3011 ;	apps/twitch_ax/twitch_ax.c:644: int16 b = (int16)pgm_read_word(&limb->squareX);
   14DA 74 04              3012 	mov	a,#0x04
   14DC 2D                 3013 	add	a,r5
   14DD FA                 3014 	mov	r2,a
   14DE E4                 3015 	clr	a
   14DF 3E                 3016 	addc	a,r6
   14E0 FB                 3017 	mov	r3,a
   14E1 8F 04              3018 	mov	ar4,r7
   14E3 8A 82              3019 	mov	dpl,r2
   14E5 8B 83              3020 	mov	dph,r3
   14E7 8C F0              3021 	mov	b,r4
   14E9 12 42 C6           3022 	lcall	__gptrget
   14EC FA                 3023 	mov	r2,a
   14ED A3                 3024 	inc	dptr
   14EE 12 42 C6           3025 	lcall	__gptrget
   14F1 FB                 3026 	mov	r3,a
                    0937   3027 	C$twitch_ax.c$645$1$1 ==.
                           3028 ;	apps/twitch_ax/twitch_ax.c:645: int16 c = (int16)pgm_read_word(&limb->timeX);
   14F2 74 08              3029 	mov	a,#0x08
   14F4 2D                 3030 	add	a,r5
   14F5 FD                 3031 	mov	r5,a
   14F6 E4                 3032 	clr	a
   14F7 3E                 3033 	addc	a,r6
   14F8 FE                 3034 	mov	r6,a
   14F9 8D 82              3035 	mov	dpl,r5
   14FB 8E 83              3036 	mov	dph,r6
   14FD 8F F0              3037 	mov	b,r7
   14FF 78 61              3038 	mov	r0,#_calcX_c_1_1
   1501 12 42 C6           3039 	lcall	__gptrget
   1504 F2                 3040 	movx	@r0,a
   1505 A3                 3041 	inc	dptr
   1506 12 42 C6           3042 	lcall	__gptrget
   1509 08                 3043 	inc	r0
   150A F2                 3044 	movx	@r0,a
                    0950   3045 	C$twitch_ax.c$646$1$1 ==.
                           3046 ;	apps/twitch_ax/twitch_ax.c:646: float t2 = t1 * t1;
   150B C0 03              3047 	push	ar3
   150D C0 02              3048 	push	ar2
   150F 78 5B              3049 	mov	r0,#_calcX_PARM_2
   1511 E2                 3050 	movx	a,@r0
   1512 C0 E0              3051 	push	acc
   1514 08                 3052 	inc	r0
   1515 E2                 3053 	movx	a,@r0
   1516 C0 E0              3054 	push	acc
   1518 08                 3055 	inc	r0
   1519 E2                 3056 	movx	a,@r0
   151A C0 E0              3057 	push	acc
   151C 08                 3058 	inc	r0
   151D E2                 3059 	movx	a,@r0
   151E C0 E0              3060 	push	acc
   1520 78 5B              3061 	mov	r0,#_calcX_PARM_2
   1522 E2                 3062 	movx	a,@r0
   1523 F5 82              3063 	mov	dpl,a
   1525 08                 3064 	inc	r0
   1526 E2                 3065 	movx	a,@r0
   1527 F5 83              3066 	mov	dph,a
   1529 08                 3067 	inc	r0
   152A E2                 3068 	movx	a,@r0
   152B F5 F0              3069 	mov	b,a
   152D 08                 3070 	inc	r0
   152E E2                 3071 	movx	a,@r0
   152F 12 32 50           3072 	lcall	___fsmul
   1532 78 63              3073 	mov	r0,#_calcX_t2_1_1
   1534 C0 E0              3074 	push	acc
   1536 E5 82              3075 	mov	a,dpl
   1538 F2                 3076 	movx	@r0,a
   1539 08                 3077 	inc	r0
   153A E5 83              3078 	mov	a,dph
   153C F2                 3079 	movx	@r0,a
   153D 08                 3080 	inc	r0
   153E E5 F0              3081 	mov	a,b
   1540 F2                 3082 	movx	@r0,a
   1541 D0 E0              3083 	pop	acc
   1543 08                 3084 	inc	r0
   1544 F2                 3085 	movx	@r0,a
   1545 E5 81              3086 	mov	a,sp
   1547 24 FC              3087 	add	a,#0xfc
   1549 F5 81              3088 	mov	sp,a
                    0990   3089 	C$twitch_ax.c$647$1$1 ==.
                           3090 ;	apps/twitch_ax/twitch_ax.c:647: float t3 = t2 * t1;
   154B 78 5B              3091 	mov	r0,#_calcX_PARM_2
   154D E2                 3092 	movx	a,@r0
   154E C0 E0              3093 	push	acc
   1550 08                 3094 	inc	r0
   1551 E2                 3095 	movx	a,@r0
   1552 C0 E0              3096 	push	acc
   1554 08                 3097 	inc	r0
   1555 E2                 3098 	movx	a,@r0
   1556 C0 E0              3099 	push	acc
   1558 08                 3100 	inc	r0
   1559 E2                 3101 	movx	a,@r0
   155A C0 E0              3102 	push	acc
   155C 78 63              3103 	mov	r0,#_calcX_t2_1_1
   155E E2                 3104 	movx	a,@r0
   155F F5 82              3105 	mov	dpl,a
   1561 08                 3106 	inc	r0
   1562 E2                 3107 	movx	a,@r0
   1563 F5 83              3108 	mov	dph,a
   1565 08                 3109 	inc	r0
   1566 E2                 3110 	movx	a,@r0
   1567 F5 F0              3111 	mov	b,a
   1569 08                 3112 	inc	r0
   156A E2                 3113 	movx	a,@r0
   156B 12 32 50           3114 	lcall	___fsmul
   156E 78 67              3115 	mov	r0,#_calcX_t3_1_1
   1570 C0 E0              3116 	push	acc
   1572 E5 82              3117 	mov	a,dpl
   1574 F2                 3118 	movx	@r0,a
   1575 08                 3119 	inc	r0
   1576 E5 83              3120 	mov	a,dph
   1578 F2                 3121 	movx	@r0,a
   1579 08                 3122 	inc	r0
   157A E5 F0              3123 	mov	a,b
   157C F2                 3124 	movx	@r0,a
   157D D0 E0              3125 	pop	acc
   157F 08                 3126 	inc	r0
   1580 F2                 3127 	movx	@r0,a
   1581 E5 81              3128 	mov	a,sp
   1583 24 FC              3129 	add	a,#0xfc
   1585 F5 81              3130 	mov	sp,a
                    09CC   3131 	C$twitch_ax.c$648$1$1 ==.
                           3132 ;	apps/twitch_ax/twitch_ax.c:648: uint16 nx = (uint16) ( (t3 * a) + (t2 * b) + (t1 * c) );
   1587 78 5F              3133 	mov	r0,#_calcX_a_1_1
   1589 E2                 3134 	movx	a,@r0
   158A F5 82              3135 	mov	dpl,a
   158C 08                 3136 	inc	r0
   158D E2                 3137 	movx	a,@r0
   158E F5 83              3138 	mov	dph,a
   1590 12 40 FA           3139 	lcall	___sint2fs
   1593 AC 82              3140 	mov	r4,dpl
   1595 AD 83              3141 	mov	r5,dph
   1597 AE F0              3142 	mov	r6,b
   1599 FF                 3143 	mov	r7,a
   159A C0 04              3144 	push	ar4
   159C C0 05              3145 	push	ar5
   159E C0 06              3146 	push	ar6
   15A0 C0 07              3147 	push	ar7
   15A2 78 67              3148 	mov	r0,#_calcX_t3_1_1
   15A4 E2                 3149 	movx	a,@r0
   15A5 F5 82              3150 	mov	dpl,a
   15A7 08                 3151 	inc	r0
   15A8 E2                 3152 	movx	a,@r0
   15A9 F5 83              3153 	mov	dph,a
   15AB 08                 3154 	inc	r0
   15AC E2                 3155 	movx	a,@r0
   15AD F5 F0              3156 	mov	b,a
   15AF 08                 3157 	inc	r0
   15B0 E2                 3158 	movx	a,@r0
   15B1 12 32 50           3159 	lcall	___fsmul
   15B4 85 82 46           3160 	mov	_calcX_sloc0_1_0,dpl
   15B7 85 83 47           3161 	mov	(_calcX_sloc0_1_0 + 1),dph
   15BA 85 F0 48           3162 	mov	(_calcX_sloc0_1_0 + 2),b
   15BD F5 49              3163 	mov	(_calcX_sloc0_1_0 + 3),a
   15BF E5 81              3164 	mov	a,sp
   15C1 24 FC              3165 	add	a,#0xfc
   15C3 F5 81              3166 	mov	sp,a
   15C5 D0 02              3167 	pop	ar2
   15C7 D0 03              3168 	pop	ar3
   15C9 8A 82              3169 	mov	dpl,r2
   15CB 8B 83              3170 	mov	dph,r3
   15CD 12 40 FA           3171 	lcall	___sint2fs
   15D0 AA 82              3172 	mov	r2,dpl
   15D2 AB 83              3173 	mov	r3,dph
   15D4 AE F0              3174 	mov	r6,b
   15D6 FF                 3175 	mov	r7,a
   15D7 C0 02              3176 	push	ar2
   15D9 C0 03              3177 	push	ar3
   15DB C0 06              3178 	push	ar6
   15DD C0 07              3179 	push	ar7
   15DF 78 63              3180 	mov	r0,#_calcX_t2_1_1
   15E1 E2                 3181 	movx	a,@r0
   15E2 F5 82              3182 	mov	dpl,a
   15E4 08                 3183 	inc	r0
   15E5 E2                 3184 	movx	a,@r0
   15E6 F5 83              3185 	mov	dph,a
   15E8 08                 3186 	inc	r0
   15E9 E2                 3187 	movx	a,@r0
   15EA F5 F0              3188 	mov	b,a
   15EC 08                 3189 	inc	r0
   15ED E2                 3190 	movx	a,@r0
   15EE 12 32 50           3191 	lcall	___fsmul
   15F1 AC 82              3192 	mov	r4,dpl
   15F3 AD 83              3193 	mov	r5,dph
   15F5 AE F0              3194 	mov	r6,b
   15F7 FF                 3195 	mov	r7,a
   15F8 E5 81              3196 	mov	a,sp
   15FA 24 FC              3197 	add	a,#0xfc
   15FC F5 81              3198 	mov	sp,a
   15FE C0 04              3199 	push	ar4
   1600 C0 05              3200 	push	ar5
   1602 C0 06              3201 	push	ar6
   1604 C0 07              3202 	push	ar7
   1606 85 46 82           3203 	mov	dpl,_calcX_sloc0_1_0
   1609 85 47 83           3204 	mov	dph,(_calcX_sloc0_1_0 + 1)
   160C 85 48 F0           3205 	mov	b,(_calcX_sloc0_1_0 + 2)
   160F E5 49              3206 	mov	a,(_calcX_sloc0_1_0 + 3)
   1611 12 3B EB           3207 	lcall	___fsadd
   1614 85 82 46           3208 	mov	_calcX_sloc0_1_0,dpl
   1617 85 83 47           3209 	mov	(_calcX_sloc0_1_0 + 1),dph
   161A 85 F0 48           3210 	mov	(_calcX_sloc0_1_0 + 2),b
   161D F5 49              3211 	mov	(_calcX_sloc0_1_0 + 3),a
   161F E5 81              3212 	mov	a,sp
   1621 24 FC              3213 	add	a,#0xfc
   1623 F5 81              3214 	mov	sp,a
   1625 78 61              3215 	mov	r0,#_calcX_c_1_1
   1627 E2                 3216 	movx	a,@r0
   1628 F5 82              3217 	mov	dpl,a
   162A 08                 3218 	inc	r0
   162B E2                 3219 	movx	a,@r0
   162C F5 83              3220 	mov	dph,a
   162E 12 40 FA           3221 	lcall	___sint2fs
   1631 AA 82              3222 	mov	r2,dpl
   1633 AB 83              3223 	mov	r3,dph
   1635 AE F0              3224 	mov	r6,b
   1637 FF                 3225 	mov	r7,a
   1638 C0 02              3226 	push	ar2
   163A C0 03              3227 	push	ar3
   163C C0 06              3228 	push	ar6
   163E C0 07              3229 	push	ar7
   1640 78 5B              3230 	mov	r0,#_calcX_PARM_2
   1642 E2                 3231 	movx	a,@r0
   1643 F5 82              3232 	mov	dpl,a
   1645 08                 3233 	inc	r0
   1646 E2                 3234 	movx	a,@r0
   1647 F5 83              3235 	mov	dph,a
   1649 08                 3236 	inc	r0
   164A E2                 3237 	movx	a,@r0
   164B F5 F0              3238 	mov	b,a
   164D 08                 3239 	inc	r0
   164E E2                 3240 	movx	a,@r0
   164F 12 32 50           3241 	lcall	___fsmul
   1652 AC 82              3242 	mov	r4,dpl
   1654 AD 83              3243 	mov	r5,dph
   1656 AE F0              3244 	mov	r6,b
   1658 FF                 3245 	mov	r7,a
   1659 E5 81              3246 	mov	a,sp
   165B 24 FC              3247 	add	a,#0xfc
   165D F5 81              3248 	mov	sp,a
   165F C0 04              3249 	push	ar4
   1661 C0 05              3250 	push	ar5
   1663 C0 06              3251 	push	ar6
   1665 C0 07              3252 	push	ar7
   1667 85 46 82           3253 	mov	dpl,_calcX_sloc0_1_0
   166A 85 47 83           3254 	mov	dph,(_calcX_sloc0_1_0 + 1)
   166D 85 48 F0           3255 	mov	b,(_calcX_sloc0_1_0 + 2)
   1670 E5 49              3256 	mov	a,(_calcX_sloc0_1_0 + 3)
   1672 12 3B EB           3257 	lcall	___fsadd
   1675 AC 82              3258 	mov	r4,dpl
   1677 AD 83              3259 	mov	r5,dph
   1679 AE F0              3260 	mov	r6,b
   167B FF                 3261 	mov	r7,a
   167C E5 81              3262 	mov	a,sp
   167E 24 FC              3263 	add	a,#0xfc
   1680 F5 81              3264 	mov	sp,a
   1682 8C 82              3265 	mov	dpl,r4
   1684 8D 83              3266 	mov	dph,r5
   1686 8E F0              3267 	mov	b,r6
   1688 EF                 3268 	mov	a,r7
   1689 12 41 3B           3269 	lcall	___fs2uint
                    0AD1   3270 	C$twitch_ax.c$649$1$1 ==.
                           3271 ;	apps/twitch_ax/twitch_ax.c:649: return nx;
                    0AD1   3272 	C$twitch_ax.c$650$1$1 ==.
                    0AD1   3273 	XFtwitch_ax$calcX$0$0 ==.
   168C 22                 3274 	ret
                           3275 ;------------------------------------------------------------
                           3276 ;Allocation info for local variables in function 'calcY'
                           3277 ;------------------------------------------------------------
                           3278 ;sloc0                     Allocated with name '_calcY_sloc0_1_0'
                           3279 ;------------------------------------------------------------
                    0AD2   3280 	Ftwitch_ax$calcY$0$0 ==.
                    0AD2   3281 	C$twitch_ax.c$652$1$1 ==.
                           3282 ;	apps/twitch_ax/twitch_ax.c:652: static int8 calcY(const G8_LIMB_POSITION* limb, float t1){
                           3283 ;	-----------------------------------------
                           3284 ;	 function calcY
                           3285 ;	-----------------------------------------
   168D                    3286 _calcY:
   168D AD 82              3287 	mov	r5,dpl
   168F AE 83              3288 	mov	r6,dph
   1691 AF F0              3289 	mov	r7,b
                    0AD8   3290 	C$twitch_ax.c$653$1$1 ==.
                           3291 ;	apps/twitch_ax/twitch_ax.c:653: int16 a = (int16)pgm_read_word(&limb->cubeY);
   1693 74 02              3292 	mov	a,#0x02
   1695 2D                 3293 	add	a,r5
   1696 FA                 3294 	mov	r2,a
   1697 E4                 3295 	clr	a
   1698 3E                 3296 	addc	a,r6
   1699 FB                 3297 	mov	r3,a
   169A 8F 04              3298 	mov	ar4,r7
   169C 8A 82              3299 	mov	dpl,r2
   169E 8B 83              3300 	mov	dph,r3
   16A0 8C F0              3301 	mov	b,r4
   16A2 78 6F              3302 	mov	r0,#_calcY_a_1_1
   16A4 12 42 C6           3303 	lcall	__gptrget
   16A7 F2                 3304 	movx	@r0,a
   16A8 A3                 3305 	inc	dptr
   16A9 12 42 C6           3306 	lcall	__gptrget
   16AC 08                 3307 	inc	r0
   16AD F2                 3308 	movx	@r0,a
                    0AF3   3309 	C$twitch_ax.c$654$1$1 ==.
                           3310 ;	apps/twitch_ax/twitch_ax.c:654: int16 b = (int16)pgm_read_word(&limb->squareY);
   16AE 74 06              3311 	mov	a,#0x06
   16B0 2D                 3312 	add	a,r5
   16B1 FA                 3313 	mov	r2,a
   16B2 E4                 3314 	clr	a
   16B3 3E                 3315 	addc	a,r6
   16B4 FB                 3316 	mov	r3,a
   16B5 8F 04              3317 	mov	ar4,r7
   16B7 8A 82              3318 	mov	dpl,r2
   16B9 8B 83              3319 	mov	dph,r3
   16BB 8C F0              3320 	mov	b,r4
   16BD 78 71              3321 	mov	r0,#_calcY_b_1_1
   16BF 12 42 C6           3322 	lcall	__gptrget
   16C2 F2                 3323 	movx	@r0,a
   16C3 A3                 3324 	inc	dptr
   16C4 12 42 C6           3325 	lcall	__gptrget
   16C7 08                 3326 	inc	r0
   16C8 F2                 3327 	movx	@r0,a
                    0B0E   3328 	C$twitch_ax.c$655$1$1 ==.
                           3329 ;	apps/twitch_ax/twitch_ax.c:655: int16 c = (int16)pgm_read_word(&limb->timeY);
   16C9 74 0A              3330 	mov	a,#0x0A
   16CB 2D                 3331 	add	a,r5
   16CC FA                 3332 	mov	r2,a
   16CD E4                 3333 	clr	a
   16CE 3E                 3334 	addc	a,r6
   16CF FB                 3335 	mov	r3,a
   16D0 8F 04              3336 	mov	ar4,r7
   16D2 8A 82              3337 	mov	dpl,r2
   16D4 8B 83              3338 	mov	dph,r3
   16D6 8C F0              3339 	mov	b,r4
   16D8 78 73              3340 	mov	r0,#_calcY_c_1_1
   16DA 12 42 C6           3341 	lcall	__gptrget
   16DD F2                 3342 	movx	@r0,a
   16DE A3                 3343 	inc	dptr
   16DF 12 42 C6           3344 	lcall	__gptrget
   16E2 08                 3345 	inc	r0
   16E3 F2                 3346 	movx	@r0,a
                    0B29   3347 	C$twitch_ax.c$656$1$1 ==.
                           3348 ;	apps/twitch_ax/twitch_ax.c:656: int8 d = (int8)pgm_read_byte(&limb->startY);
   16E4 74 0C              3349 	mov	a,#0x0C
   16E6 2D                 3350 	add	a,r5
   16E7 FD                 3351 	mov	r5,a
   16E8 E4                 3352 	clr	a
   16E9 3E                 3353 	addc	a,r6
   16EA FE                 3354 	mov	r6,a
   16EB 8D 82              3355 	mov	dpl,r5
   16ED 8E 83              3356 	mov	dph,r6
   16EF 8F F0              3357 	mov	b,r7
   16F1 78 75              3358 	mov	r0,#_calcY_d_1_1
   16F3 12 42 C6           3359 	lcall	__gptrget
   16F6 F2                 3360 	movx	@r0,a
                    0B3C   3361 	C$twitch_ax.c$657$1$1 ==.
                           3362 ;	apps/twitch_ax/twitch_ax.c:657: float t2 = t1 * t1;
   16F7 78 6B              3363 	mov	r0,#_calcY_PARM_2
   16F9 E2                 3364 	movx	a,@r0
   16FA C0 E0              3365 	push	acc
   16FC 08                 3366 	inc	r0
   16FD E2                 3367 	movx	a,@r0
   16FE C0 E0              3368 	push	acc
   1700 08                 3369 	inc	r0
   1701 E2                 3370 	movx	a,@r0
   1702 C0 E0              3371 	push	acc
   1704 08                 3372 	inc	r0
   1705 E2                 3373 	movx	a,@r0
   1706 C0 E0              3374 	push	acc
   1708 78 6B              3375 	mov	r0,#_calcY_PARM_2
   170A E2                 3376 	movx	a,@r0
   170B F5 82              3377 	mov	dpl,a
   170D 08                 3378 	inc	r0
   170E E2                 3379 	movx	a,@r0
   170F F5 83              3380 	mov	dph,a
   1711 08                 3381 	inc	r0
   1712 E2                 3382 	movx	a,@r0
   1713 F5 F0              3383 	mov	b,a
   1715 08                 3384 	inc	r0
   1716 E2                 3385 	movx	a,@r0
   1717 12 32 50           3386 	lcall	___fsmul
   171A 78 76              3387 	mov	r0,#_calcY_t2_1_1
   171C C0 E0              3388 	push	acc
   171E E5 82              3389 	mov	a,dpl
   1720 F2                 3390 	movx	@r0,a
   1721 08                 3391 	inc	r0
   1722 E5 83              3392 	mov	a,dph
   1724 F2                 3393 	movx	@r0,a
   1725 08                 3394 	inc	r0
   1726 E5 F0              3395 	mov	a,b
   1728 F2                 3396 	movx	@r0,a
   1729 D0 E0              3397 	pop	acc
   172B 08                 3398 	inc	r0
   172C F2                 3399 	movx	@r0,a
   172D E5 81              3400 	mov	a,sp
   172F 24 FC              3401 	add	a,#0xfc
   1731 F5 81              3402 	mov	sp,a
                    0B78   3403 	C$twitch_ax.c$658$1$1 ==.
                           3404 ;	apps/twitch_ax/twitch_ax.c:658: float t3 = t2 * t1;
   1733 78 6B              3405 	mov	r0,#_calcY_PARM_2
   1735 E2                 3406 	movx	a,@r0
   1736 C0 E0              3407 	push	acc
   1738 08                 3408 	inc	r0
   1739 E2                 3409 	movx	a,@r0
   173A C0 E0              3410 	push	acc
   173C 08                 3411 	inc	r0
   173D E2                 3412 	movx	a,@r0
   173E C0 E0              3413 	push	acc
   1740 08                 3414 	inc	r0
   1741 E2                 3415 	movx	a,@r0
   1742 C0 E0              3416 	push	acc
   1744 78 76              3417 	mov	r0,#_calcY_t2_1_1
   1746 E2                 3418 	movx	a,@r0
   1747 F5 82              3419 	mov	dpl,a
   1749 08                 3420 	inc	r0
   174A E2                 3421 	movx	a,@r0
   174B F5 83              3422 	mov	dph,a
   174D 08                 3423 	inc	r0
   174E E2                 3424 	movx	a,@r0
   174F F5 F0              3425 	mov	b,a
   1751 08                 3426 	inc	r0
   1752 E2                 3427 	movx	a,@r0
   1753 12 32 50           3428 	lcall	___fsmul
   1756 78 7A              3429 	mov	r0,#_calcY_t3_1_1
   1758 C0 E0              3430 	push	acc
   175A E5 82              3431 	mov	a,dpl
   175C F2                 3432 	movx	@r0,a
   175D 08                 3433 	inc	r0
   175E E5 83              3434 	mov	a,dph
   1760 F2                 3435 	movx	@r0,a
   1761 08                 3436 	inc	r0
   1762 E5 F0              3437 	mov	a,b
   1764 F2                 3438 	movx	@r0,a
   1765 D0 E0              3439 	pop	acc
   1767 08                 3440 	inc	r0
   1768 F2                 3441 	movx	@r0,a
   1769 E5 81              3442 	mov	a,sp
   176B 24 FC              3443 	add	a,#0xfc
   176D F5 81              3444 	mov	sp,a
                    0BB4   3445 	C$twitch_ax.c$659$1$1 ==.
                           3446 ;	apps/twitch_ax/twitch_ax.c:659: int8 ny = (int8) ( (t3 * a) + (t2 * b) + (t1 * c) + d );
   176F 78 6F              3447 	mov	r0,#_calcY_a_1_1
   1771 E2                 3448 	movx	a,@r0
   1772 F5 82              3449 	mov	dpl,a
   1774 08                 3450 	inc	r0
   1775 E2                 3451 	movx	a,@r0
   1776 F5 83              3452 	mov	dph,a
   1778 12 40 FA           3453 	lcall	___sint2fs
   177B AC 82              3454 	mov	r4,dpl
   177D AD 83              3455 	mov	r5,dph
   177F AE F0              3456 	mov	r6,b
   1781 FF                 3457 	mov	r7,a
   1782 C0 04              3458 	push	ar4
   1784 C0 05              3459 	push	ar5
   1786 C0 06              3460 	push	ar6
   1788 C0 07              3461 	push	ar7
   178A 78 7A              3462 	mov	r0,#_calcY_t3_1_1
   178C E2                 3463 	movx	a,@r0
   178D F5 82              3464 	mov	dpl,a
   178F 08                 3465 	inc	r0
   1790 E2                 3466 	movx	a,@r0
   1791 F5 83              3467 	mov	dph,a
   1793 08                 3468 	inc	r0
   1794 E2                 3469 	movx	a,@r0
   1795 F5 F0              3470 	mov	b,a
   1797 08                 3471 	inc	r0
   1798 E2                 3472 	movx	a,@r0
   1799 12 32 50           3473 	lcall	___fsmul
   179C 85 82 4A           3474 	mov	_calcY_sloc0_1_0,dpl
   179F 85 83 4B           3475 	mov	(_calcY_sloc0_1_0 + 1),dph
   17A2 85 F0 4C           3476 	mov	(_calcY_sloc0_1_0 + 2),b
   17A5 F5 4D              3477 	mov	(_calcY_sloc0_1_0 + 3),a
   17A7 E5 81              3478 	mov	a,sp
   17A9 24 FC              3479 	add	a,#0xfc
   17AB F5 81              3480 	mov	sp,a
   17AD 78 71              3481 	mov	r0,#_calcY_b_1_1
   17AF E2                 3482 	movx	a,@r0
   17B0 F5 82              3483 	mov	dpl,a
   17B2 08                 3484 	inc	r0
   17B3 E2                 3485 	movx	a,@r0
   17B4 F5 83              3486 	mov	dph,a
   17B6 12 40 FA           3487 	lcall	___sint2fs
   17B9 AA 82              3488 	mov	r2,dpl
   17BB AB 83              3489 	mov	r3,dph
   17BD AE F0              3490 	mov	r6,b
   17BF FF                 3491 	mov	r7,a
   17C0 C0 02              3492 	push	ar2
   17C2 C0 03              3493 	push	ar3
   17C4 C0 06              3494 	push	ar6
   17C6 C0 07              3495 	push	ar7
   17C8 78 76              3496 	mov	r0,#_calcY_t2_1_1
   17CA E2                 3497 	movx	a,@r0
   17CB F5 82              3498 	mov	dpl,a
   17CD 08                 3499 	inc	r0
   17CE E2                 3500 	movx	a,@r0
   17CF F5 83              3501 	mov	dph,a
   17D1 08                 3502 	inc	r0
   17D2 E2                 3503 	movx	a,@r0
   17D3 F5 F0              3504 	mov	b,a
   17D5 08                 3505 	inc	r0
   17D6 E2                 3506 	movx	a,@r0
   17D7 12 32 50           3507 	lcall	___fsmul
   17DA AC 82              3508 	mov	r4,dpl
   17DC AD 83              3509 	mov	r5,dph
   17DE AE F0              3510 	mov	r6,b
   17E0 FF                 3511 	mov	r7,a
   17E1 E5 81              3512 	mov	a,sp
   17E3 24 FC              3513 	add	a,#0xfc
   17E5 F5 81              3514 	mov	sp,a
   17E7 C0 04              3515 	push	ar4
   17E9 C0 05              3516 	push	ar5
   17EB C0 06              3517 	push	ar6
   17ED C0 07              3518 	push	ar7
   17EF 85 4A 82           3519 	mov	dpl,_calcY_sloc0_1_0
   17F2 85 4B 83           3520 	mov	dph,(_calcY_sloc0_1_0 + 1)
   17F5 85 4C F0           3521 	mov	b,(_calcY_sloc0_1_0 + 2)
   17F8 E5 4D              3522 	mov	a,(_calcY_sloc0_1_0 + 3)
   17FA 12 3B EB           3523 	lcall	___fsadd
   17FD 85 82 4A           3524 	mov	_calcY_sloc0_1_0,dpl
   1800 85 83 4B           3525 	mov	(_calcY_sloc0_1_0 + 1),dph
   1803 85 F0 4C           3526 	mov	(_calcY_sloc0_1_0 + 2),b
   1806 F5 4D              3527 	mov	(_calcY_sloc0_1_0 + 3),a
   1808 E5 81              3528 	mov	a,sp
   180A 24 FC              3529 	add	a,#0xfc
   180C F5 81              3530 	mov	sp,a
   180E 78 73              3531 	mov	r0,#_calcY_c_1_1
   1810 E2                 3532 	movx	a,@r0
   1811 F5 82              3533 	mov	dpl,a
   1813 08                 3534 	inc	r0
   1814 E2                 3535 	movx	a,@r0
   1815 F5 83              3536 	mov	dph,a
   1817 12 40 FA           3537 	lcall	___sint2fs
   181A AA 82              3538 	mov	r2,dpl
   181C AB 83              3539 	mov	r3,dph
   181E AE F0              3540 	mov	r6,b
   1820 FF                 3541 	mov	r7,a
   1821 C0 02              3542 	push	ar2
   1823 C0 03              3543 	push	ar3
   1825 C0 06              3544 	push	ar6
   1827 C0 07              3545 	push	ar7
   1829 78 6B              3546 	mov	r0,#_calcY_PARM_2
   182B E2                 3547 	movx	a,@r0
   182C F5 82              3548 	mov	dpl,a
   182E 08                 3549 	inc	r0
   182F E2                 3550 	movx	a,@r0
   1830 F5 83              3551 	mov	dph,a
   1832 08                 3552 	inc	r0
   1833 E2                 3553 	movx	a,@r0
   1834 F5 F0              3554 	mov	b,a
   1836 08                 3555 	inc	r0
   1837 E2                 3556 	movx	a,@r0
   1838 12 32 50           3557 	lcall	___fsmul
   183B AC 82              3558 	mov	r4,dpl
   183D AD 83              3559 	mov	r5,dph
   183F AE F0              3560 	mov	r6,b
   1841 FF                 3561 	mov	r7,a
   1842 E5 81              3562 	mov	a,sp
   1844 24 FC              3563 	add	a,#0xfc
   1846 F5 81              3564 	mov	sp,a
   1848 C0 04              3565 	push	ar4
   184A C0 05              3566 	push	ar5
   184C C0 06              3567 	push	ar6
   184E C0 07              3568 	push	ar7
   1850 85 4A 82           3569 	mov	dpl,_calcY_sloc0_1_0
   1853 85 4B 83           3570 	mov	dph,(_calcY_sloc0_1_0 + 1)
   1856 85 4C F0           3571 	mov	b,(_calcY_sloc0_1_0 + 2)
   1859 E5 4D              3572 	mov	a,(_calcY_sloc0_1_0 + 3)
   185B 12 3B EB           3573 	lcall	___fsadd
   185E 85 82 4A           3574 	mov	_calcY_sloc0_1_0,dpl
   1861 85 83 4B           3575 	mov	(_calcY_sloc0_1_0 + 1),dph
   1864 85 F0 4C           3576 	mov	(_calcY_sloc0_1_0 + 2),b
   1867 F5 4D              3577 	mov	(_calcY_sloc0_1_0 + 3),a
   1869 E5 81              3578 	mov	a,sp
   186B 24 FC              3579 	add	a,#0xfc
   186D F5 81              3580 	mov	sp,a
   186F 78 75              3581 	mov	r0,#_calcY_d_1_1
   1871 E2                 3582 	movx	a,@r0
   1872 F5 82              3583 	mov	dpl,a
   1874 12 41 BB           3584 	lcall	___schar2fs
   1877 AA 82              3585 	mov	r2,dpl
   1879 AB 83              3586 	mov	r3,dph
   187B AE F0              3587 	mov	r6,b
   187D FF                 3588 	mov	r7,a
   187E C0 02              3589 	push	ar2
   1880 C0 03              3590 	push	ar3
   1882 C0 06              3591 	push	ar6
   1884 C0 07              3592 	push	ar7
   1886 85 4A 82           3593 	mov	dpl,_calcY_sloc0_1_0
   1889 85 4B 83           3594 	mov	dph,(_calcY_sloc0_1_0 + 1)
   188C 85 4C F0           3595 	mov	b,(_calcY_sloc0_1_0 + 2)
   188F E5 4D              3596 	mov	a,(_calcY_sloc0_1_0 + 3)
   1891 12 3B EB           3597 	lcall	___fsadd
   1894 AC 82              3598 	mov	r4,dpl
   1896 AD 83              3599 	mov	r5,dph
   1898 AE F0              3600 	mov	r6,b
   189A FF                 3601 	mov	r7,a
   189B E5 81              3602 	mov	a,sp
   189D 24 FC              3603 	add	a,#0xfc
   189F F5 81              3604 	mov	sp,a
   18A1 8C 82              3605 	mov	dpl,r4
   18A3 8D 83              3606 	mov	dph,r5
   18A5 8E F0              3607 	mov	b,r6
   18A7 EF                 3608 	mov	a,r7
   18A8 12 41 C6           3609 	lcall	___fs2schar
                    0CF0   3610 	C$twitch_ax.c$660$1$1 ==.
                           3611 ;	apps/twitch_ax/twitch_ax.c:660: return ny;
                    0CF0   3612 	C$twitch_ax.c$661$1$1 ==.
                    0CF0   3613 	XFtwitch_ax$calcY$0$0 ==.
   18AB 22                 3614 	ret
                           3615 ;------------------------------------------------------------
                           3616 ;Allocation info for local variables in function 'gaitRunnerProcess'
                           3617 ;------------------------------------------------------------
                           3618 ;sloc0                     Allocated with name '_gaitRunnerProcess_sloc0_1_0'
                           3619 ;sloc1                     Allocated with name '_gaitRunnerProcess_sloc1_1_0'
                           3620 ;sloc2                     Allocated with name '_gaitRunnerProcess_sloc2_1_0'
                           3621 ;sloc3                     Allocated with name '_gaitRunnerProcess_sloc3_1_0'
                           3622 ;sloc4                     Allocated with name '_gaitRunnerProcess_sloc4_1_0'
                           3623 ;sloc5                     Allocated with name '_gaitRunnerProcess_sloc5_1_0'
                           3624 ;sloc6                     Allocated with name '_gaitRunnerProcess_sloc6_1_0'
                           3625 ;sloc7                     Allocated with name '_gaitRunnerProcess_sloc7_1_0'
                           3626 ;sloc8                     Allocated with name '_gaitRunnerProcess_sloc8_1_0'
                           3627 ;sloc9                     Allocated with name '_gaitRunnerProcess_sloc9_1_0'
                           3628 ;sloc10                    Allocated with name '_gaitRunnerProcess_sloc10_1_0'
                           3629 ;------------------------------------------------------------
                    0CF1   3630 	G$gaitRunnerProcess$0$0 ==.
                    0CF1   3631 	C$twitch_ax.c$668$1$1 ==.
                           3632 ;	apps/twitch_ax/twitch_ax.c:668: boolean gaitRunnerProcess(G8_RUNNER* runner){
                           3633 ;	-----------------------------------------
                           3634 ;	 function gaitRunnerProcess
                           3635 ;	-----------------------------------------
   18AC                    3636 _gaitRunnerProcess:
   18AC AF F0              3637 	mov	r7,b
   18AE AE 83              3638 	mov	r6,dph
   18B0 E5 82              3639 	mov	a,dpl
   18B2 78 7E              3640 	mov	r0,#_gaitRunnerProcess_runner_1_1
   18B4 F2                 3641 	movx	@r0,a
   18B5 08                 3642 	inc	r0
   18B6 EE                 3643 	mov	a,r6
   18B7 F2                 3644 	movx	@r0,a
   18B8 08                 3645 	inc	r0
   18B9 EF                 3646 	mov	a,r7
   18BA F2                 3647 	movx	@r0,a
                    0D00   3648 	C$twitch_ax.c$690$1$1 ==.
                           3649 ;	apps/twitch_ax/twitch_ax.c:690: now = getMs();
   18BB 12 3B 8B           3650 	lcall	_getMs
   18BE 78 81              3651 	mov	r0,#_gaitRunnerProcess_now_1_1
   18C0 C0 E0              3652 	push	acc
   18C2 E5 82              3653 	mov	a,dpl
   18C4 F2                 3654 	movx	@r0,a
   18C5 08                 3655 	inc	r0
   18C6 E5 83              3656 	mov	a,dph
   18C8 F2                 3657 	movx	@r0,a
   18C9 08                 3658 	inc	r0
   18CA E5 F0              3659 	mov	a,b
   18CC F2                 3660 	movx	@r0,a
   18CD D0 E0              3661 	pop	acc
   18CF 08                 3662 	inc	r0
   18D0 F2                 3663 	movx	@r0,a
                    0D16   3664 	C$twitch_ax.c$691$1$1 ==.
                           3665 ;	apps/twitch_ax/twitch_ax.c:691: interval = (int16)((now) - (runner->startTime))>>16;	//subtract previous 'startTime'
   18D1 78 7E              3666 	mov	r0,#_gaitRunnerProcess_runner_1_1
   18D3 E2                 3667 	movx	a,@r0
   18D4 24 07              3668 	add	a,#0x07
   18D6 F5 4E              3669 	mov	_gaitRunnerProcess_sloc0_1_0,a
   18D8 08                 3670 	inc	r0
   18D9 E2                 3671 	movx	a,@r0
   18DA 34 00              3672 	addc	a,#0x00
   18DC F5 4F              3673 	mov	(_gaitRunnerProcess_sloc0_1_0 + 1),a
   18DE 08                 3674 	inc	r0
   18DF E2                 3675 	movx	a,@r0
   18E0 F5 50              3676 	mov	(_gaitRunnerProcess_sloc0_1_0 + 2),a
   18E2 85 4E 82           3677 	mov	dpl,_gaitRunnerProcess_sloc0_1_0
   18E5 85 4F 83           3678 	mov	dph,(_gaitRunnerProcess_sloc0_1_0 + 1)
   18E8 85 50 F0           3679 	mov	b,(_gaitRunnerProcess_sloc0_1_0 + 2)
   18EB 12 42 C6           3680 	lcall	__gptrget
   18EE FC                 3681 	mov	r4,a
   18EF A3                 3682 	inc	dptr
   18F0 12 42 C6           3683 	lcall	__gptrget
   18F3 FD                 3684 	mov	r5,a
   18F4 A3                 3685 	inc	dptr
   18F5 12 42 C6           3686 	lcall	__gptrget
   18F8 FE                 3687 	mov	r6,a
   18F9 A3                 3688 	inc	dptr
   18FA 12 42 C6           3689 	lcall	__gptrget
   18FD FF                 3690 	mov	r7,a
   18FE 78 81              3691 	mov	r0,#_gaitRunnerProcess_now_1_1
   1900 E2                 3692 	movx	a,@r0
   1901 C3                 3693 	clr	c
   1902 9C                 3694 	subb	a,r4
   1903 08                 3695 	inc	r0
   1904 E2                 3696 	movx	a,@r0
   1905 9D                 3697 	subb	a,r5
   1906 FD                 3698 	mov	r5,a
   1907 08                 3699 	inc	r0
   1908 E2                 3700 	movx	a,@r0
   1909 9E                 3701 	subb	a,r6
   190A 08                 3702 	inc	r0
   190B E2                 3703 	movx	a,@r0
   190C 9F                 3704 	subb	a,r7
   190D 78 85              3705 	mov	r0,#_gaitRunnerProcess_interval_1_1
   190F ED                 3706 	mov	a,r5
   1910 33                 3707 	rlc	a
   1911 95 E0              3708 	subb	a,acc
   1913 F2                 3709 	movx	@r0,a
   1914 08                 3710 	inc	r0
   1915 F2                 3711 	movx	@r0,a
                    0D5B   3712 	C$twitch_ax.c$693$1$1 ==.
                           3713 ;	apps/twitch_ax/twitch_ax.c:693: if(!gaitRunnerIsPlaying(runner) || (runner->speeds)==null){
   1916 78 7E              3714 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1918 E2                 3715 	movx	a,@r0
   1919 F5 82              3716 	mov	dpl,a
   191B 08                 3717 	inc	r0
   191C E2                 3718 	movx	a,@r0
   191D F5 83              3719 	mov	dph,a
   191F 08                 3720 	inc	r0
   1920 E2                 3721 	movx	a,@r0
   1921 F5 F0              3722 	mov	b,a
   1923 12 0B EF           3723 	lcall	_gaitRunnerIsPlaying
   1926 E5 82              3724 	mov	a,dpl
   1928 60 2C              3725 	jz	00101$
   192A 78 7E              3726 	mov	r0,#_gaitRunnerProcess_runner_1_1
   192C E2                 3727 	movx	a,@r0
   192D 24 11              3728 	add	a,#0x11
   192F F5 5E              3729 	mov	_gaitRunnerProcess_sloc7_1_0,a
   1931 08                 3730 	inc	r0
   1932 E2                 3731 	movx	a,@r0
   1933 34 00              3732 	addc	a,#0x00
   1935 F5 5F              3733 	mov	(_gaitRunnerProcess_sloc7_1_0 + 1),a
   1937 08                 3734 	inc	r0
   1938 E2                 3735 	movx	a,@r0
   1939 F5 60              3736 	mov	(_gaitRunnerProcess_sloc7_1_0 + 2),a
   193B 85 5E 82           3737 	mov	dpl,_gaitRunnerProcess_sloc7_1_0
   193E 85 5F 83           3738 	mov	dph,(_gaitRunnerProcess_sloc7_1_0 + 1)
   1941 85 60 F0           3739 	mov	b,(_gaitRunnerProcess_sloc7_1_0 + 2)
   1944 12 42 C6           3740 	lcall	__gptrget
   1947 FA                 3741 	mov	r2,a
   1948 A3                 3742 	inc	dptr
   1949 12 42 C6           3743 	lcall	__gptrget
   194C FE                 3744 	mov	r6,a
   194D A3                 3745 	inc	dptr
   194E 12 42 C6           3746 	lcall	__gptrget
   1951 FF                 3747 	mov	r7,a
   1952 EA                 3748 	mov	a,r2
   1953 4E                 3749 	orl	a,r6
   1954 70 06              3750 	jnz	00102$
   1956                    3751 00101$:
                    0D9B   3752 	C$twitch_ax.c$697$2$2 ==.
                           3753 ;	apps/twitch_ax/twitch_ax.c:697: return FALSE;
   1956 75 82 00           3754 	mov	dpl,#0x00
   1959 02 27 DC           3755 	ljmp	00205$
   195C                    3756 00102$:
                    0DA1   3757 	C$twitch_ax.c$700$1$1 ==.
                           3758 ;	apps/twitch_ax/twitch_ax.c:700: if(runner->animation == NO_GAIT){
   195C 78 7E              3759 	mov	r0,#_gaitRunnerProcess_runner_1_1
   195E E2                 3760 	movx	a,@r0
   195F 24 03              3761 	add	a,#0x03
   1961 F5 61              3762 	mov	_gaitRunnerProcess_sloc8_1_0,a
   1963 08                 3763 	inc	r0
   1964 E2                 3764 	movx	a,@r0
   1965 34 00              3765 	addc	a,#0x00
   1967 F5 62              3766 	mov	(_gaitRunnerProcess_sloc8_1_0 + 1),a
   1969 08                 3767 	inc	r0
   196A E2                 3768 	movx	a,@r0
   196B F5 63              3769 	mov	(_gaitRunnerProcess_sloc8_1_0 + 2),a
   196D 85 61 82           3770 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   1970 85 62 83           3771 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   1973 85 63 F0           3772 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   1976 12 42 C6           3773 	lcall	__gptrget
   1979 F5 51              3774 	mov	_gaitRunnerProcess_sloc1_1_0,a
   197B 74 64              3775 	mov	a,#0x64
   197D B5 51 06           3776 	cjne	a,_gaitRunnerProcess_sloc1_1_0,00105$
                    0DC5   3777 	C$twitch_ax.c$704$2$3 ==.
                           3778 ;	apps/twitch_ax/twitch_ax.c:704: return FALSE;
   1980 75 82 00           3779 	mov	dpl,#0x00
   1983 02 27 DC           3780 	ljmp	00205$
   1986                    3781 00105$:
                    0DCB   3782 	C$twitch_ax.c$707$1$1 ==.
                           3783 ;	apps/twitch_ax/twitch_ax.c:707: if(interval == 0){		//Happens if ....
   1986 78 85              3784 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1988 E2                 3785 	movx	a,@r0
   1989 F5 F0              3786 	mov	b,a
   198B 08                 3787 	inc	r0
   198C E2                 3788 	movx	a,@r0
   198D 45 F0              3789 	orl	a,b
   198F 70 08              3790 	jnz	00107$
                    0DD6   3791 	C$twitch_ax.c$709$2$4 ==.
                           3792 ;	apps/twitch_ax/twitch_ax.c:709: interval = 1;
   1991 78 85              3793 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1993 74 01              3794 	mov	a,#0x01
   1995 F2                 3795 	movx	@r0,a
   1996 08                 3796 	inc	r0
   1997 E4                 3797 	clr	a
   1998 F2                 3798 	movx	@r0,a
   1999                    3799 00107$:
                    0DDE   3800 	C$twitch_ax.c$713$1$1 ==.
                           3801 ;	apps/twitch_ax/twitch_ax.c:713: runner->startTime = now;
   1999 85 4E 82           3802 	mov	dpl,_gaitRunnerProcess_sloc0_1_0
   199C 85 4F 83           3803 	mov	dph,(_gaitRunnerProcess_sloc0_1_0 + 1)
   199F 85 50 F0           3804 	mov	b,(_gaitRunnerProcess_sloc0_1_0 + 2)
   19A2 78 81              3805 	mov	r0,#_gaitRunnerProcess_now_1_1
   19A4 E2                 3806 	movx	a,@r0
   19A5 12 36 56           3807 	lcall	__gptrput
   19A8 A3                 3808 	inc	dptr
   19A9 08                 3809 	inc	r0
   19AA E2                 3810 	movx	a,@r0
   19AB 12 36 56           3811 	lcall	__gptrput
   19AE A3                 3812 	inc	dptr
   19AF 08                 3813 	inc	r0
   19B0 E2                 3814 	movx	a,@r0
   19B1 12 36 56           3815 	lcall	__gptrput
   19B4 A3                 3816 	inc	dptr
   19B5 08                 3817 	inc	r0
   19B6 E2                 3818 	movx	a,@r0
   19B7 12 36 56           3819 	lcall	__gptrput
                    0DFF   3820 	C$twitch_ax.c$714$1$1 ==.
                           3821 ;	apps/twitch_ax/twitch_ax.c:714: if(runner->backwards){
   19BA 78 7E              3822 	mov	r0,#_gaitRunnerProcess_runner_1_1
   19BC E2                 3823 	movx	a,@r0
   19BD 24 0F              3824 	add	a,#0x0F
   19BF F5 4E              3825 	mov	_gaitRunnerProcess_sloc0_1_0,a
   19C1 08                 3826 	inc	r0
   19C2 E2                 3827 	movx	a,@r0
   19C3 34 00              3828 	addc	a,#0x00
   19C5 F5 4F              3829 	mov	(_gaitRunnerProcess_sloc0_1_0 + 1),a
   19C7 08                 3830 	inc	r0
   19C8 E2                 3831 	movx	a,@r0
   19C9 F5 50              3832 	mov	(_gaitRunnerProcess_sloc0_1_0 + 2),a
   19CB 85 4E 82           3833 	mov	dpl,_gaitRunnerProcess_sloc0_1_0
   19CE 85 4F 83           3834 	mov	dph,(_gaitRunnerProcess_sloc0_1_0 + 1)
   19D1 85 50 F0           3835 	mov	b,(_gaitRunnerProcess_sloc0_1_0 + 2)
   19D4 12 42 C6           3836 	lcall	__gptrget
   19D7 60 0E              3837 	jz	00109$
                    0E1E   3838 	C$twitch_ax.c$715$2$5 ==.
                           3839 ;	apps/twitch_ax/twitch_ax.c:715: interval *= -1;
   19D9 78 85              3840 	mov	r0,#_gaitRunnerProcess_interval_1_1
   19DB E2                 3841 	movx	a,@r0
   19DC D3                 3842 	setb	c
   19DD F4                 3843 	cpl	a
   19DE 34 00              3844 	addc	a,#0x00
   19E0 F2                 3845 	movx	@r0,a
   19E1 08                 3846 	inc	r0
   19E2 E2                 3847 	movx	a,@r0
   19E3 F4                 3848 	cpl	a
   19E4 34 00              3849 	addc	a,#0x00
   19E6 F2                 3850 	movx	@r0,a
   19E7                    3851 00109$:
                    0E2C   3852 	C$twitch_ax.c$717$1$1 ==.
                           3853 ;	apps/twitch_ax/twitch_ax.c:717: interval *= runner->speed;
   19E7 78 7E              3854 	mov	r0,#_gaitRunnerProcess_runner_1_1
   19E9 E2                 3855 	movx	a,@r0
   19EA 24 10              3856 	add	a,#0x10
   19EC FB                 3857 	mov	r3,a
   19ED 08                 3858 	inc	r0
   19EE E2                 3859 	movx	a,@r0
   19EF 34 00              3860 	addc	a,#0x00
   19F1 FC                 3861 	mov	r4,a
   19F2 08                 3862 	inc	r0
   19F3 E2                 3863 	movx	a,@r0
   19F4 FD                 3864 	mov	r5,a
   19F5 8B 82              3865 	mov	dpl,r3
   19F7 8C 83              3866 	mov	dph,r4
   19F9 8D F0              3867 	mov	b,r5
   19FB 12 42 C6           3868 	lcall	__gptrget
   19FE FB                 3869 	mov	r3,a
   19FF 78 E8              3870 	mov	r0,#__mulint_PARM_2
   1A01 F2                 3871 	movx	@r0,a
   1A02 EB                 3872 	mov	a,r3
   1A03 33                 3873 	rlc	a
   1A04 95 E0              3874 	subb	a,acc
   1A06 08                 3875 	inc	r0
   1A07 F2                 3876 	movx	@r0,a
   1A08 78 85              3877 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1A0A E2                 3878 	movx	a,@r0
   1A0B F5 82              3879 	mov	dpl,a
   1A0D 08                 3880 	inc	r0
   1A0E E2                 3881 	movx	a,@r0
   1A0F F5 83              3882 	mov	dph,a
   1A11 12 38 07           3883 	lcall	__mulint
   1A14 78 85              3884 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1A16 E5 82              3885 	mov	a,dpl
   1A18 F2                 3886 	movx	@r0,a
   1A19 08                 3887 	inc	r0
   1A1A E5 83              3888 	mov	a,dph
   1A1C F2                 3889 	movx	@r0,a
                    0E62   3890 	C$twitch_ax.c$725$1$1 ==.
                           3891 ;	apps/twitch_ax/twitch_ax.c:725: if(interval == 0){
   1A1D 78 85              3892 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1A1F E2                 3893 	movx	a,@r0
   1A20 F5 F0              3894 	mov	b,a
   1A22 08                 3895 	inc	r0
   1A23 E2                 3896 	movx	a,@r0
   1A24 45 F0              3897 	orl	a,b
   1A26 70 06              3898 	jnz	00111$
                    0E6D   3899 	C$twitch_ax.c$729$2$7 ==.
                           3900 ;	apps/twitch_ax/twitch_ax.c:729: return TRUE;
   1A28 75 82 01           3901 	mov	dpl,#0x01
   1A2B 02 27 DC           3902 	ljmp	00205$
   1A2E                    3903 00111$:
                    0E73   3904 	C$twitch_ax.c$735$1$1 ==.
                           3905 ;	apps/twitch_ax/twitch_ax.c:735: animation = &runner->animations[runner->animation];
   1A2E 78 7E              3906 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1A30 E2                 3907 	movx	a,@r0
   1A31 F5 82              3908 	mov	dpl,a
   1A33 08                 3909 	inc	r0
   1A34 E2                 3910 	movx	a,@r0
   1A35 F5 83              3911 	mov	dph,a
   1A37 08                 3912 	inc	r0
   1A38 E2                 3913 	movx	a,@r0
   1A39 F5 F0              3914 	mov	b,a
   1A3B 12 42 C6           3915 	lcall	__gptrget
   1A3E FB                 3916 	mov	r3,a
   1A3F A3                 3917 	inc	dptr
   1A40 12 42 C6           3918 	lcall	__gptrget
   1A43 FC                 3919 	mov	r4,a
   1A44 A3                 3920 	inc	dptr
   1A45 12 42 C6           3921 	lcall	__gptrget
   1A48 FD                 3922 	mov	r5,a
   1A49 E5 51              3923 	mov	a,_gaitRunnerProcess_sloc1_1_0
   1A4B 75 F0 05           3924 	mov	b,#0x05
   1A4E A4                 3925 	mul	ab
   1A4F 78 87              3926 	mov	r0,#_gaitRunnerProcess_animation_1_1
   1A51 2B                 3927 	add	a,r3
   1A52 F2                 3928 	movx	@r0,a
   1A53 EC                 3929 	mov	a,r4
   1A54 35 F0              3930 	addc	a,b
   1A56 08                 3931 	inc	r0
   1A57 F2                 3932 	movx	@r0,a
   1A58 08                 3933 	inc	r0
   1A59 ED                 3934 	mov	a,r5
   1A5A F2                 3935 	movx	@r0,a
                    0EA0   3936 	C$twitch_ax.c$738$1$1 ==.
                           3937 ;	apps/twitch_ax/twitch_ax.c:738: currentTime = runner->currentTime + interval;
   1A5B 78 7E              3938 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1A5D E2                 3939 	movx	a,@r0
   1A5E 24 0B              3940 	add	a,#0x0B
   1A60 F5 52              3941 	mov	_gaitRunnerProcess_sloc2_1_0,a
   1A62 08                 3942 	inc	r0
   1A63 E2                 3943 	movx	a,@r0
   1A64 34 00              3944 	addc	a,#0x00
   1A66 F5 53              3945 	mov	(_gaitRunnerProcess_sloc2_1_0 + 1),a
   1A68 08                 3946 	inc	r0
   1A69 E2                 3947 	movx	a,@r0
   1A6A F5 54              3948 	mov	(_gaitRunnerProcess_sloc2_1_0 + 2),a
   1A6C 85 52 82           3949 	mov	dpl,_gaitRunnerProcess_sloc2_1_0
   1A6F 85 53 83           3950 	mov	dph,(_gaitRunnerProcess_sloc2_1_0 + 1)
   1A72 85 54 F0           3951 	mov	b,(_gaitRunnerProcess_sloc2_1_0 + 2)
   1A75 12 42 C6           3952 	lcall	__gptrget
   1A78 FC                 3953 	mov	r4,a
   1A79 A3                 3954 	inc	dptr
   1A7A 12 42 C6           3955 	lcall	__gptrget
   1A7D FD                 3956 	mov	r5,a
   1A7E 78 85              3957 	mov	r0,#_gaitRunnerProcess_interval_1_1
   1A80 79 8A              3958 	mov	r1,#_gaitRunnerProcess_currentTime_1_1
   1A82 E2                 3959 	movx	a,@r0
   1A83 2C                 3960 	add	a,r4
   1A84 F3                 3961 	movx	@r1,a
   1A85 08                 3962 	inc	r0
   1A86 E2                 3963 	movx	a,@r0
   1A87 3D                 3964 	addc	a,r5
   1A88 09                 3965 	inc	r1
   1A89 F3                 3966 	movx	@r1,a
                    0ECF   3967 	C$twitch_ax.c$739$1$1 ==.
                           3968 ;	apps/twitch_ax/twitch_ax.c:739: if(currentTime >= runner->totalTime){
   1A8A 78 7E              3969 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1A8C E2                 3970 	movx	a,@r0
   1A8D 24 0D              3971 	add	a,#0x0D
   1A8F F5 55              3972 	mov	_gaitRunnerProcess_sloc3_1_0,a
   1A91 08                 3973 	inc	r0
   1A92 E2                 3974 	movx	a,@r0
   1A93 34 00              3975 	addc	a,#0x00
   1A95 F5 56              3976 	mov	(_gaitRunnerProcess_sloc3_1_0 + 1),a
   1A97 08                 3977 	inc	r0
   1A98 E2                 3978 	movx	a,@r0
   1A99 F5 57              3979 	mov	(_gaitRunnerProcess_sloc3_1_0 + 2),a
   1A9B 85 55 82           3980 	mov	dpl,_gaitRunnerProcess_sloc3_1_0
   1A9E 85 56 83           3981 	mov	dph,(_gaitRunnerProcess_sloc3_1_0 + 1)
   1AA1 85 57 F0           3982 	mov	b,(_gaitRunnerProcess_sloc3_1_0 + 2)
   1AA4 12 42 C6           3983 	lcall	__gptrget
   1AA7 F5 58              3984 	mov	_gaitRunnerProcess_sloc4_1_0,a
   1AA9 A3                 3985 	inc	dptr
   1AAA 12 42 C6           3986 	lcall	__gptrget
   1AAD F5 59              3987 	mov	(_gaitRunnerProcess_sloc4_1_0 + 1),a
   1AAF 78 8A              3988 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1AB1 C3                 3989 	clr	c
   1AB2 E2                 3990 	movx	a,@r0
   1AB3 95 58              3991 	subb	a,_gaitRunnerProcess_sloc4_1_0
   1AB5 08                 3992 	inc	r0
   1AB6 E2                 3993 	movx	a,@r0
   1AB7 64 80              3994 	xrl	a,#0x80
   1AB9 85 59 F0           3995 	mov	b,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1ABC 63 F0 80           3996 	xrl	b,#0x80
   1ABF 95 F0              3997 	subb	a,b
   1AC1 50 03              3998 	jnc	00274$
   1AC3 02 1B B1           3999 	ljmp	00139$
   1AC6                    4000 00274$:
                    0F0B   4001 	C$twitch_ax.c$741$1$1 ==.
                           4002 ;	apps/twitch_ax/twitch_ax.c:741: if(pgm_read_byte(&animation->sweep)==FALSE){
   1AC6 78 87              4003 	mov	r0,#_gaitRunnerProcess_animation_1_1
   1AC8 E2                 4004 	movx	a,@r0
   1AC9 24 04              4005 	add	a,#0x04
   1ACB FB                 4006 	mov	r3,a
   1ACC 08                 4007 	inc	r0
   1ACD E2                 4008 	movx	a,@r0
   1ACE 34 00              4009 	addc	a,#0x00
   1AD0 FC                 4010 	mov	r4,a
   1AD1 08                 4011 	inc	r0
   1AD2 E2                 4012 	movx	a,@r0
   1AD3 FD                 4013 	mov	r5,a
   1AD4 8B 82              4014 	mov	dpl,r3
   1AD6 8C 83              4015 	mov	dph,r4
   1AD8 8D F0              4016 	mov	b,r5
   1ADA 12 42 C6           4017 	lcall	__gptrget
   1ADD F5 51              4018 	mov	_gaitRunnerProcess_sloc1_1_0,a
   1ADF 60 03              4019 	jz	00275$
   1AE1 02 1B 77           4020 	ljmp	00120$
   1AE4                    4021 00275$:
                    0F29   4022 	C$twitch_ax.c$742$1$1 ==.
                           4023 ;	apps/twitch_ax/twitch_ax.c:742: currentTime %= runner->totalTime;			// Set back to start of loop
   1AE4 78 EB              4024 	mov	r0,#__modsint_PARM_2
   1AE6 E5 58              4025 	mov	a,_gaitRunnerProcess_sloc4_1_0
   1AE8 F2                 4026 	movx	@r0,a
   1AE9 08                 4027 	inc	r0
   1AEA E5 59              4028 	mov	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1AEC F2                 4029 	movx	@r0,a
   1AED 78 8A              4030 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1AEF E2                 4031 	movx	a,@r0
   1AF0 F5 82              4032 	mov	dpl,a
   1AF2 08                 4033 	inc	r0
   1AF3 E2                 4034 	movx	a,@r0
   1AF4 F5 83              4035 	mov	dph,a
   1AF6 12 39 02           4036 	lcall	__modsint
   1AF9 78 8A              4037 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1AFB E5 82              4038 	mov	a,dpl
   1AFD F2                 4039 	movx	@r0,a
   1AFE 08                 4040 	inc	r0
   1AFF E5 83              4041 	mov	a,dph
   1B01 F2                 4042 	movx	@r0,a
                    0F47   4043 	C$twitch_ax.c$743$3$9 ==.
                           4044 ;	apps/twitch_ax/twitch_ax.c:743: if(runner->repeatCount){
   1B02 78 7E              4045 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1B04 E2                 4046 	movx	a,@r0
   1B05 24 05              4047 	add	a,#0x05
   1B07 F5 5A              4048 	mov	_gaitRunnerProcess_sloc5_1_0,a
   1B09 08                 4049 	inc	r0
   1B0A E2                 4050 	movx	a,@r0
   1B0B 34 00              4051 	addc	a,#0x00
   1B0D F5 5B              4052 	mov	(_gaitRunnerProcess_sloc5_1_0 + 1),a
   1B0F 08                 4053 	inc	r0
   1B10 E2                 4054 	movx	a,@r0
   1B11 F5 5C              4055 	mov	(_gaitRunnerProcess_sloc5_1_0 + 2),a
   1B13 85 5A 82           4056 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1B16 85 5B 83           4057 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1B19 85 5C F0           4058 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1B1C 12 42 C6           4059 	lcall	__gptrget
   1B1F F5 5D              4060 	mov	_gaitRunnerProcess_sloc6_1_0,a
   1B21 70 03              4061 	jnz	00276$
   1B23 02 1C D7           4062 	ljmp	00140$
   1B26                    4063 00276$:
                    0F6B   4064 	C$twitch_ax.c$744$4$10 ==.
                           4065 ;	apps/twitch_ax/twitch_ax.c:744: runner->repeatCount -= 1;				// One less frame to go{
   1B26 E5 5D              4066 	mov	a,_gaitRunnerProcess_sloc6_1_0
   1B28 14                 4067 	dec	a
   1B29 FD                 4068 	mov	r5,a
   1B2A 85 5A 82           4069 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1B2D 85 5B 83           4070 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1B30 85 5C F0           4071 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1B33 12 36 56           4072 	lcall	__gptrput
                    0F7B   4073 	C$twitch_ax.c$746$4$10 ==.
                           4074 ;	apps/twitch_ax/twitch_ax.c:746: if(runner->repeatCount==0){				/// Reached zero from a non-zero repeatCount
   1B36 85 5A 82           4075 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1B39 85 5B 83           4076 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1B3C 85 5C F0           4077 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1B3F 12 42 C6           4078 	lcall	__gptrget
   1B42 ED                 4079 	mov	a,r5
   1B43 60 03              4080 	jz	00277$
   1B45 02 1C D7           4081 	ljmp	00140$
   1B48                    4082 00277$:
                    0F8D   4083 	C$twitch_ax.c$747$5$11 ==.
                           4084 ;	apps/twitch_ax/twitch_ax.c:747: runner->playing = FALSE;			// we have reached the end (of a repeating gait played forward?)
   1B48 78 7E              4085 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1B4A E2                 4086 	movx	a,@r0
   1B4B 24 06              4087 	add	a,#0x06
   1B4D FB                 4088 	mov	r3,a
   1B4E 08                 4089 	inc	r0
   1B4F E2                 4090 	movx	a,@r0
   1B50 34 00              4091 	addc	a,#0x00
   1B52 FC                 4092 	mov	r4,a
   1B53 08                 4093 	inc	r0
   1B54 E2                 4094 	movx	a,@r0
   1B55 FD                 4095 	mov	r5,a
   1B56 8B 82              4096 	mov	dpl,r3
   1B58 8C 83              4097 	mov	dph,r4
   1B5A 8D F0              4098 	mov	b,r5
   1B5C E4                 4099 	clr	a
   1B5D 12 36 56           4100 	lcall	__gptrput
                    0FA5   4101 	C$twitch_ax.c$748$5$11 ==.
                           4102 ;	apps/twitch_ax/twitch_ax.c:748: currentTime = 0;					// set servos to final position
   1B60 78 8A              4103 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1B62 E4                 4104 	clr	a
   1B63 F2                 4105 	movx	@r0,a
   1B64 08                 4106 	inc	r0
   1B65 F2                 4107 	movx	@r0,a
                    0FAB   4108 	C$twitch_ax.c$749$5$11 ==.
                           4109 ;	apps/twitch_ax/twitch_ax.c:749: runner->animation = NO_GAIT;
   1B66 85 61 82           4110 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   1B69 85 62 83           4111 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   1B6C 85 63 F0           4112 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   1B6F 74 64              4113 	mov	a,#0x64
   1B71 12 36 56           4114 	lcall	__gptrput
   1B74 02 1C D7           4115 	ljmp	00140$
   1B77                    4116 00120$:
                    0FBC   4117 	C$twitch_ax.c$752$2$8 ==.
                           4118 ;	apps/twitch_ax/twitch_ax.c:752: }else if(pgm_read_byte(&animation->sweep)==2){
   1B77 74 02              4119 	mov	a,#0x02
   1B79 B5 51 0C           4120 	cjne	a,_gaitRunnerProcess_sloc1_1_0,00117$
                    0FC1   4121 	C$twitch_ax.c$753$3$12 ==.
                           4122 ;	apps/twitch_ax/twitch_ax.c:753: currentTime = runner->totalTime;		//Triggers block at end of this function
   1B7C 78 8A              4123 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1B7E E5 58              4124 	mov	a,_gaitRunnerProcess_sloc4_1_0
   1B80 F2                 4125 	movx	@r0,a
   1B81 08                 4126 	inc	r0
   1B82 E5 59              4127 	mov	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1B84 F2                 4128 	movx	@r0,a
   1B85 02 1C D7           4129 	ljmp	00140$
   1B88                    4130 00117$:
                    0FCD   4131 	C$twitch_ax.c$758$3$13 ==.
                           4132 ;	apps/twitch_ax/twitch_ax.c:758: currentTime = runner->totalTime - (currentTime - runner->totalTime);
   1B88 78 8A              4133 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1B8A E2                 4134 	movx	a,@r0
   1B8B C3                 4135 	clr	c
   1B8C 95 58              4136 	subb	a,_gaitRunnerProcess_sloc4_1_0
   1B8E FC                 4137 	mov	r4,a
   1B8F 08                 4138 	inc	r0
   1B90 E2                 4139 	movx	a,@r0
   1B91 95 59              4140 	subb	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1B93 FD                 4141 	mov	r5,a
   1B94 78 8A              4142 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1B96 E5 58              4143 	mov	a,_gaitRunnerProcess_sloc4_1_0
   1B98 C3                 4144 	clr	c
   1B99 9C                 4145 	subb	a,r4
   1B9A F2                 4146 	movx	@r0,a
   1B9B E5 59              4147 	mov	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1B9D 9D                 4148 	subb	a,r5
   1B9E 08                 4149 	inc	r0
   1B9F F2                 4150 	movx	@r0,a
                    0FE5   4151 	C$twitch_ax.c$759$3$13 ==.
                           4152 ;	apps/twitch_ax/twitch_ax.c:759: runner->backwards = TRUE;
   1BA0 85 4E 82           4153 	mov	dpl,_gaitRunnerProcess_sloc0_1_0
   1BA3 85 4F 83           4154 	mov	dph,(_gaitRunnerProcess_sloc0_1_0 + 1)
   1BA6 85 50 F0           4155 	mov	b,(_gaitRunnerProcess_sloc0_1_0 + 2)
   1BA9 74 01              4156 	mov	a,#0x01
   1BAB 12 36 56           4157 	lcall	__gptrput
   1BAE 02 1C D7           4158 	ljmp	00140$
   1BB1                    4159 00139$:
                    0FF6   4160 	C$twitch_ax.c$762$1$1 ==.
                           4161 ;	apps/twitch_ax/twitch_ax.c:762: }else if(currentTime < 0){
   1BB1 78 8B              4162 	mov	r0,#(_gaitRunnerProcess_currentTime_1_1 + 1)
   1BB3 E2                 4163 	movx	a,@r0
   1BB4 20 E7 03           4164 	jb	acc.7,00280$
   1BB7 02 1C D7           4165 	ljmp	00140$
   1BBA                    4166 00280$:
                    0FFF   4167 	C$twitch_ax.c$765$2$14 ==.
                           4168 ;	apps/twitch_ax/twitch_ax.c:765: if(pgm_read_byte(&animation->sweep)==FALSE){
   1BBA 78 87              4169 	mov	r0,#_gaitRunnerProcess_animation_1_1
   1BBC E2                 4170 	movx	a,@r0
   1BBD 24 04              4171 	add	a,#0x04
   1BBF FB                 4172 	mov	r3,a
   1BC0 08                 4173 	inc	r0
   1BC1 E2                 4174 	movx	a,@r0
   1BC2 34 00              4175 	addc	a,#0x00
   1BC4 FC                 4176 	mov	r4,a
   1BC5 08                 4177 	inc	r0
   1BC6 E2                 4178 	movx	a,@r0
   1BC7 FD                 4179 	mov	r5,a
   1BC8 8B 82              4180 	mov	dpl,r3
   1BCA 8C 83              4181 	mov	dph,r4
   1BCC 8D F0              4182 	mov	b,r5
   1BCE 12 42 C6           4183 	lcall	__gptrget
   1BD1 FD                 4184 	mov	r5,a
   1BD2 60 03              4185 	jz	00281$
   1BD4 02 1C 54           4186 	ljmp	00134$
   1BD7                    4187 00281$:
                    101C   4188 	C$twitch_ax.c$766$3$15 ==.
                           4189 ;	apps/twitch_ax/twitch_ax.c:766: currentTime = runner->totalTime + currentTime;	///wrap around
   1BD7 78 8A              4190 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1BD9 E2                 4191 	movx	a,@r0
   1BDA 25 58              4192 	add	a,_gaitRunnerProcess_sloc4_1_0
   1BDC F2                 4193 	movx	@r0,a
   1BDD 08                 4194 	inc	r0
   1BDE E2                 4195 	movx	a,@r0
   1BDF 35 59              4196 	addc	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1BE1 F2                 4197 	movx	@r0,a
                    1027   4198 	C$twitch_ax.c$767$3$15 ==.
                           4199 ;	apps/twitch_ax/twitch_ax.c:767: if(runner->repeatCount){
   1BE2 78 7E              4200 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1BE4 E2                 4201 	movx	a,@r0
   1BE5 24 05              4202 	add	a,#0x05
   1BE7 F5 5A              4203 	mov	_gaitRunnerProcess_sloc5_1_0,a
   1BE9 08                 4204 	inc	r0
   1BEA E2                 4205 	movx	a,@r0
   1BEB 34 00              4206 	addc	a,#0x00
   1BED F5 5B              4207 	mov	(_gaitRunnerProcess_sloc5_1_0 + 1),a
   1BEF 08                 4208 	inc	r0
   1BF0 E2                 4209 	movx	a,@r0
   1BF1 F5 5C              4210 	mov	(_gaitRunnerProcess_sloc5_1_0 + 2),a
   1BF3 85 5A 82           4211 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1BF6 85 5B 83           4212 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1BF9 85 5C F0           4213 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1BFC 12 42 C6           4214 	lcall	__gptrget
   1BFF FC                 4215 	mov	r4,a
   1C00 70 03              4216 	jnz	00282$
   1C02 02 1C D7           4217 	ljmp	00140$
   1C05                    4218 00282$:
                    104A   4219 	C$twitch_ax.c$768$4$16 ==.
                           4220 ;	apps/twitch_ax/twitch_ax.c:768: runner->repeatCount += 1;				// One more frame to go ///(??? One less frame to go, really...){
   1C05 0C                 4221 	inc	r4
   1C06 85 5A 82           4222 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1C09 85 5B 83           4223 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1C0C 85 5C F0           4224 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1C0F EC                 4225 	mov	a,r4
   1C10 12 36 56           4226 	lcall	__gptrput
                    1058   4227 	C$twitch_ax.c$770$4$16 ==.
                           4228 ;	apps/twitch_ax/twitch_ax.c:770: if(runner->repeatCount==0){				/// Reached zero from a non-zero repeatCount
   1C13 85 5A 82           4229 	mov	dpl,_gaitRunnerProcess_sloc5_1_0
   1C16 85 5B 83           4230 	mov	dph,(_gaitRunnerProcess_sloc5_1_0 + 1)
   1C19 85 5C F0           4231 	mov	b,(_gaitRunnerProcess_sloc5_1_0 + 2)
   1C1C 12 42 C6           4232 	lcall	__gptrget
   1C1F EC                 4233 	mov	a,r4
   1C20 60 03              4234 	jz	00283$
   1C22 02 1C D7           4235 	ljmp	00140$
   1C25                    4236 00283$:
                    106A   4237 	C$twitch_ax.c$771$5$17 ==.
                           4238 ;	apps/twitch_ax/twitch_ax.c:771: runner->playing = FALSE;			// we have reached the end (of a gait played backwards?)
   1C25 78 7E              4239 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1C27 E2                 4240 	movx	a,@r0
   1C28 24 06              4241 	add	a,#0x06
   1C2A FB                 4242 	mov	r3,a
   1C2B 08                 4243 	inc	r0
   1C2C E2                 4244 	movx	a,@r0
   1C2D 34 00              4245 	addc	a,#0x00
   1C2F FC                 4246 	mov	r4,a
   1C30 08                 4247 	inc	r0
   1C31 E2                 4248 	movx	a,@r0
   1C32 FF                 4249 	mov	r7,a
   1C33 8B 82              4250 	mov	dpl,r3
   1C35 8C 83              4251 	mov	dph,r4
   1C37 8F F0              4252 	mov	b,r7
   1C39 E4                 4253 	clr	a
   1C3A 12 36 56           4254 	lcall	__gptrput
                    1082   4255 	C$twitch_ax.c$772$5$17 ==.
                           4256 ;	apps/twitch_ax/twitch_ax.c:772: currentTime = 0;					// set servos to start position
   1C3D 78 8A              4257 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1C3F E4                 4258 	clr	a
   1C40 F2                 4259 	movx	@r0,a
   1C41 08                 4260 	inc	r0
   1C42 F2                 4261 	movx	@r0,a
                    1088   4262 	C$twitch_ax.c$773$5$17 ==.
                           4263 ;	apps/twitch_ax/twitch_ax.c:773: runner->animation = NO_GAIT;
   1C43 85 61 82           4264 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   1C46 85 62 83           4265 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   1C49 85 63 F0           4266 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   1C4C 74 64              4267 	mov	a,#0x64
   1C4E 12 36 56           4268 	lcall	__gptrput
   1C51 02 1C D7           4269 	ljmp	00140$
   1C54                    4270 00134$:
                    1099   4271 	C$twitch_ax.c$779$2$14 ==.
                           4272 ;	apps/twitch_ax/twitch_ax.c:779: }else if(pgm_read_byte(&animation->sweep)==2){
   1C54 BD 02 08           4273 	cjne	r5,#0x02,00131$
                    109C   4274 	C$twitch_ax.c$780$3$18 ==.
                           4275 ;	apps/twitch_ax/twitch_ax.c:780: currentTime = 0;		//Triggers block at end of this function
   1C57 78 8A              4276 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1C59 E4                 4277 	clr	a
   1C5A F2                 4278 	movx	@r0,a
   1C5B 08                 4279 	inc	r0
   1C5C F2                 4280 	movx	@r0,a
   1C5D 80 78              4281 	sjmp	00140$
   1C5F                    4282 00131$:
                    10A4   4283 	C$twitch_ax.c$784$3$19 ==.
                           4284 ;	apps/twitch_ax/twitch_ax.c:784: runner->backwards = FALSE;
   1C5F 85 4E 82           4285 	mov	dpl,_gaitRunnerProcess_sloc0_1_0
   1C62 85 4F 83           4286 	mov	dph,(_gaitRunnerProcess_sloc0_1_0 + 1)
   1C65 85 50 F0           4287 	mov	b,(_gaitRunnerProcess_sloc0_1_0 + 2)
   1C68 E4                 4288 	clr	a
   1C69 12 36 56           4289 	lcall	__gptrput
                    10B1   4290 	C$twitch_ax.c$785$3$19 ==.
                           4291 ;	apps/twitch_ax/twitch_ax.c:785: currentTime = -currentTime;
   1C6C 78 8A              4292 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1C6E E2                 4293 	movx	a,@r0
   1C6F D3                 4294 	setb	c
   1C70 F4                 4295 	cpl	a
   1C71 34 00              4296 	addc	a,#0x00
   1C73 F2                 4297 	movx	@r0,a
   1C74 08                 4298 	inc	r0
   1C75 E2                 4299 	movx	a,@r0
   1C76 F4                 4300 	cpl	a
   1C77 34 00              4301 	addc	a,#0x00
   1C79 F2                 4302 	movx	@r0,a
                    10BF   4303 	C$twitch_ax.c$787$3$19 ==.
                           4304 ;	apps/twitch_ax/twitch_ax.c:787: if(runner->repeatCount){
   1C7A 78 7E              4305 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1C7C E2                 4306 	movx	a,@r0
   1C7D 24 05              4307 	add	a,#0x05
   1C7F FD                 4308 	mov	r5,a
   1C80 08                 4309 	inc	r0
   1C81 E2                 4310 	movx	a,@r0
   1C82 34 00              4311 	addc	a,#0x00
   1C84 FE                 4312 	mov	r6,a
   1C85 08                 4313 	inc	r0
   1C86 E2                 4314 	movx	a,@r0
   1C87 FF                 4315 	mov	r7,a
   1C88 8D 82              4316 	mov	dpl,r5
   1C8A 8E 83              4317 	mov	dph,r6
   1C8C 8F F0              4318 	mov	b,r7
   1C8E 12 42 C6           4319 	lcall	__gptrget
   1C91 FC                 4320 	mov	r4,a
   1C92 60 43              4321 	jz	00140$
                    10D9   4322 	C$twitch_ax.c$788$4$20 ==.
                           4323 ;	apps/twitch_ax/twitch_ax.c:788: runner->repeatCount -= 1;			// One less frame to go (this is the end of a sweep with negative speed){
   1C94 1C                 4324 	dec	r4
   1C95 8D 82              4325 	mov	dpl,r5
   1C97 8E 83              4326 	mov	dph,r6
   1C99 8F F0              4327 	mov	b,r7
   1C9B EC                 4328 	mov	a,r4
   1C9C 12 36 56           4329 	lcall	__gptrput
                    10E4   4330 	C$twitch_ax.c$790$4$20 ==.
                           4331 ;	apps/twitch_ax/twitch_ax.c:790: if(runner->repeatCount==0){
   1C9F 8D 82              4332 	mov	dpl,r5
   1CA1 8E 83              4333 	mov	dph,r6
   1CA3 8F F0              4334 	mov	b,r7
   1CA5 12 42 C6           4335 	lcall	__gptrget
   1CA8 EC                 4336 	mov	a,r4
   1CA9 70 2C              4337 	jnz	00140$
                    10F0   4338 	C$twitch_ax.c$791$5$21 ==.
                           4339 ;	apps/twitch_ax/twitch_ax.c:791: runner->playing = FALSE;		// we have reached the end (of a regular sweep)
   1CAB 78 7E              4340 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1CAD E2                 4341 	movx	a,@r0
   1CAE 24 06              4342 	add	a,#0x06
   1CB0 FD                 4343 	mov	r5,a
   1CB1 08                 4344 	inc	r0
   1CB2 E2                 4345 	movx	a,@r0
   1CB3 34 00              4346 	addc	a,#0x00
   1CB5 FE                 4347 	mov	r6,a
   1CB6 08                 4348 	inc	r0
   1CB7 E2                 4349 	movx	a,@r0
   1CB8 FF                 4350 	mov	r7,a
   1CB9 8D 82              4351 	mov	dpl,r5
   1CBB 8E 83              4352 	mov	dph,r6
   1CBD 8F F0              4353 	mov	b,r7
   1CBF E4                 4354 	clr	a
   1CC0 12 36 56           4355 	lcall	__gptrput
                    1108   4356 	C$twitch_ax.c$792$5$21 ==.
                           4357 ;	apps/twitch_ax/twitch_ax.c:792: currentTime = 0;				// set servos to initial position
   1CC3 78 8A              4358 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1CC5 E4                 4359 	clr	a
   1CC6 F2                 4360 	movx	@r0,a
   1CC7 08                 4361 	inc	r0
   1CC8 F2                 4362 	movx	@r0,a
                    110E   4363 	C$twitch_ax.c$793$5$21 ==.
                           4364 ;	apps/twitch_ax/twitch_ax.c:793: runner->animation = NO_GAIT;
   1CC9 85 61 82           4365 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   1CCC 85 62 83           4366 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   1CCF 85 63 F0           4367 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   1CD2 74 64              4368 	mov	a,#0x64
   1CD4 12 36 56           4369 	lcall	__gptrput
   1CD7                    4370 00140$:
                    111C   4371 	C$twitch_ax.c$801$1$1 ==.
                           4372 ;	apps/twitch_ax/twitch_ax.c:801: runner->currentTime = currentTime; // range is 0....totalTime
   1CD7 85 52 82           4373 	mov	dpl,_gaitRunnerProcess_sloc2_1_0
   1CDA 85 53 83           4374 	mov	dph,(_gaitRunnerProcess_sloc2_1_0 + 1)
   1CDD 85 54 F0           4375 	mov	b,(_gaitRunnerProcess_sloc2_1_0 + 2)
   1CE0 78 8A              4376 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1CE2 E2                 4377 	movx	a,@r0
   1CE3 12 36 56           4378 	lcall	__gptrput
   1CE6 A3                 4379 	inc	dptr
   1CE7 08                 4380 	inc	r0
   1CE8 E2                 4381 	movx	a,@r0
   1CE9 12 36 56           4382 	lcall	__gptrput
                    1131   4383 	C$twitch_ax.c$804$1$1 ==.
                           4384 ;	apps/twitch_ax/twitch_ax.c:804: frameTime = interpolateU(currentTime, 0,runner->totalTime, 0, SCALE_X);
   1CEC 78 2B              4385 	mov	r0,#_interpolateU_PARM_2
   1CEE E4                 4386 	clr	a
   1CEF F2                 4387 	movx	@r0,a
   1CF0 08                 4388 	inc	r0
   1CF1 F2                 4389 	movx	@r0,a
   1CF2 78 2D              4390 	mov	r0,#_interpolateU_PARM_3
   1CF4 E5 58              4391 	mov	a,_gaitRunnerProcess_sloc4_1_0
   1CF6 F2                 4392 	movx	@r0,a
   1CF7 08                 4393 	inc	r0
   1CF8 E5 59              4394 	mov	a,(_gaitRunnerProcess_sloc4_1_0 + 1)
   1CFA F2                 4395 	movx	@r0,a
   1CFB 78 2F              4396 	mov	r0,#_interpolateU_PARM_4
   1CFD E4                 4397 	clr	a
   1CFE F2                 4398 	movx	@r0,a
   1CFF 08                 4399 	inc	r0
   1D00 F2                 4400 	movx	@r0,a
   1D01 78 31              4401 	mov	r0,#_interpolateU_PARM_5
   1D03 74 E8              4402 	mov	a,#0xE8
   1D05 F2                 4403 	movx	@r0,a
   1D06 08                 4404 	inc	r0
   1D07 74 03              4405 	mov	a,#0x03
   1D09 F2                 4406 	movx	@r0,a
   1D0A 78 8A              4407 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   1D0C E2                 4408 	movx	a,@r0
   1D0D F5 82              4409 	mov	dpl,a
   1D0F 08                 4410 	inc	r0
   1D10 E2                 4411 	movx	a,@r0
   1D11 F5 83              4412 	mov	dph,a
   1D13 12 0A DC           4413 	lcall	_interpolateU
   1D16 78 8C              4414 	mov	r0,#_gaitRunnerProcess_frameTime_1_1
   1D18 E5 82              4415 	mov	a,dpl
   1D1A F2                 4416 	movx	@r0,a
   1D1B 08                 4417 	inc	r0
   1D1C E5 83              4418 	mov	a,dph
   1D1E F2                 4419 	movx	@r0,a
                    1164   4420 	C$twitch_ax.c$805$1$1 ==.
                           4421 ;	apps/twitch_ax/twitch_ax.c:805: frameStartTime = 0;
   1D1F 7C 00              4422 	mov	r4,#0x00
   1D21 7D 00              4423 	mov	r5,#0x00
                    1168   4424 	C$twitch_ax.c$806$1$1 ==.
                           4425 ;	apps/twitch_ax/twitch_ax.c:806: frameEndTime = SCALE_X;
   1D23 78 8E              4426 	mov	r0,#_gaitRunnerProcess_frameEndTime_1_1
   1D25 74 E8              4427 	mov	a,#0xE8
   1D27 F2                 4428 	movx	@r0,a
   1D28 08                 4429 	inc	r0
   1D29 74 03              4430 	mov	a,#0x03
   1D2B F2                 4431 	movx	@r0,a
                    1171   4432 	C$twitch_ax.c$809$1$1 ==.
                           4433 ;	apps/twitch_ax/twitch_ax.c:809: frame = (const G8_FRAME*)pgm_read_word(&animation->frames);
   1D2C 78 87              4434 	mov	r0,#_gaitRunnerProcess_animation_1_1
   1D2E E2                 4435 	movx	a,@r0
   1D2F 24 01              4436 	add	a,#0x01
   1D31 FA                 4437 	mov	r2,a
   1D32 08                 4438 	inc	r0
   1D33 E2                 4439 	movx	a,@r0
   1D34 34 00              4440 	addc	a,#0x00
   1D36 FB                 4441 	mov	r3,a
   1D37 08                 4442 	inc	r0
   1D38 E2                 4443 	movx	a,@r0
   1D39 FF                 4444 	mov	r7,a
   1D3A 8A 82              4445 	mov	dpl,r2
   1D3C 8B 83              4446 	mov	dph,r3
   1D3E 8F F0              4447 	mov	b,r7
   1D40 12 42 C6           4448 	lcall	__gptrget
   1D43 FA                 4449 	mov	r2,a
   1D44 A3                 4450 	inc	dptr
   1D45 12 42 C6           4451 	lcall	__gptrget
   1D48 FB                 4452 	mov	r3,a
   1D49 A3                 4453 	inc	dptr
   1D4A 12 42 C6           4454 	lcall	__gptrget
   1D4D FF                 4455 	mov	r7,a
   1D4E 78 90              4456 	mov	r0,#_gaitRunnerProcess_frame_1_1
   1D50 EA                 4457 	mov	a,r2
   1D51 F2                 4458 	movx	@r0,a
   1D52 08                 4459 	inc	r0
   1D53 EB                 4460 	mov	a,r3
   1D54 F2                 4461 	movx	@r0,a
   1D55 08                 4462 	inc	r0
   1D56 EF                 4463 	mov	a,r7
   1D57 F2                 4464 	movx	@r0,a
                    119D   4465 	C$twitch_ax.c$810$1$1 ==.
                           4466 ;	apps/twitch_ax/twitch_ax.c:810: for(i = pgm_read_byte(&animation->numFrames)-1; i>0; i--){
   1D58 78 87              4467 	mov	r0,#_gaitRunnerProcess_animation_1_1
   1D5A E2                 4468 	movx	a,@r0
   1D5B F5 82              4469 	mov	dpl,a
   1D5D 08                 4470 	inc	r0
   1D5E E2                 4471 	movx	a,@r0
   1D5F F5 83              4472 	mov	dph,a
   1D61 08                 4473 	inc	r0
   1D62 E2                 4474 	movx	a,@r0
   1D63 F5 F0              4475 	mov	b,a
   1D65 12 42 C6           4476 	lcall	__gptrget
   1D68 78 93              4477 	mov	r0,#_gaitRunnerProcess_i_1_1
   1D6A 14                 4478 	dec	a
   1D6B F2                 4479 	movx	@r0,a
   1D6C 78 93              4480 	mov	r0,#_gaitRunnerProcess_i_1_1
   1D6E E2                 4481 	movx	a,@r0
   1D6F FE                 4482 	mov	r6,a
   1D70                    4483 00143$:
   1D70 EE                 4484 	mov	a,r6
   1D71 60 4B              4485 	jz	00146$
                    11B8   4486 	C$twitch_ax.c$811$2$22 ==.
                           4487 ;	apps/twitch_ax/twitch_ax.c:811: const G8_FRAME* f = &frame[i];
   1D73 EE                 4488 	mov	a,r6
   1D74 75 F0 05           4489 	mov	b,#0x05
   1D77 A4                 4490 	mul	ab
   1D78 FB                 4491 	mov	r3,a
   1D79 AF F0              4492 	mov	r7,b
   1D7B 78 90              4493 	mov	r0,#_gaitRunnerProcess_frame_1_1
   1D7D E2                 4494 	movx	a,@r0
   1D7E 2B                 4495 	add	a,r3
   1D7F FB                 4496 	mov	r3,a
   1D80 08                 4497 	inc	r0
   1D81 E2                 4498 	movx	a,@r0
   1D82 3F                 4499 	addc	a,r7
   1D83 FA                 4500 	mov	r2,a
   1D84 08                 4501 	inc	r0
   1D85 E2                 4502 	movx	a,@r0
   1D86 FF                 4503 	mov	r7,a
                    11CC   4504 	C$twitch_ax.c$812$2$22 ==.
                           4505 ;	apps/twitch_ax/twitch_ax.c:812: frameStartTime = pgm_read_word(&f->time);
   1D87 8B 82              4506 	mov	dpl,r3
   1D89 8A 83              4507 	mov	dph,r2
   1D8B 8F F0              4508 	mov	b,r7
   1D8D 12 42 C6           4509 	lcall	__gptrget
   1D90 FC                 4510 	mov	r4,a
   1D91 A3                 4511 	inc	dptr
   1D92 12 42 C6           4512 	lcall	__gptrget
   1D95 FD                 4513 	mov	r5,a
                    11DB   4514 	C$twitch_ax.c$813$2$22 ==.
                           4515 ;	apps/twitch_ax/twitch_ax.c:813: if(frameStartTime <= frameTime){
   1D96 78 8C              4516 	mov	r0,#_gaitRunnerProcess_frameTime_1_1
   1D98 C3                 4517 	clr	c
   1D99 E2                 4518 	movx	a,@r0
   1D9A 9C                 4519 	subb	a,r4
   1D9B 08                 4520 	inc	r0
   1D9C E2                 4521 	movx	a,@r0
   1D9D 9D                 4522 	subb	a,r5
   1D9E 40 0C              4523 	jc	00142$
                    11E5   4524 	C$twitch_ax.c$814$3$23 ==.
                           4525 ;	apps/twitch_ax/twitch_ax.c:814: frame = f;
   1DA0 78 90              4526 	mov	r0,#_gaitRunnerProcess_frame_1_1
   1DA2 EB                 4527 	mov	a,r3
   1DA3 F2                 4528 	movx	@r0,a
   1DA4 08                 4529 	inc	r0
   1DA5 EA                 4530 	mov	a,r2
   1DA6 F2                 4531 	movx	@r0,a
   1DA7 08                 4532 	inc	r0
   1DA8 EF                 4533 	mov	a,r7
   1DA9 F2                 4534 	movx	@r0,a
                    11EF   4535 	C$twitch_ax.c$815$3$23 ==.
                           4536 ;	apps/twitch_ax/twitch_ax.c:815: break;
   1DAA 80 12              4537 	sjmp	00146$
   1DAC                    4538 00142$:
                    11F1   4539 	C$twitch_ax.c$817$2$22 ==.
                           4540 ;	apps/twitch_ax/twitch_ax.c:817: frameEndTime = frameStartTime;
   1DAC 78 8E              4541 	mov	r0,#_gaitRunnerProcess_frameEndTime_1_1
   1DAE EC                 4542 	mov	a,r4
   1DAF F2                 4543 	movx	@r0,a
   1DB0 08                 4544 	inc	r0
   1DB1 ED                 4545 	mov	a,r5
   1DB2 F2                 4546 	movx	@r0,a
                    11F8   4547 	C$twitch_ax.c$818$2$22 ==.
                           4548 ;	apps/twitch_ax/twitch_ax.c:818: frameStartTime = 0;
   1DB3 7C 00              4549 	mov	r4,#0x00
   1DB5 7D 00              4550 	mov	r5,#0x00
                    11FC   4551 	C$twitch_ax.c$810$1$1 ==.
                           4552 ;	apps/twitch_ax/twitch_ax.c:810: for(i = pgm_read_byte(&animation->numFrames)-1; i>0; i--){
   1DB7 1E                 4553 	dec	r6
   1DB8 78 93              4554 	mov	r0,#_gaitRunnerProcess_i_1_1
   1DBA EE                 4555 	mov	a,r6
   1DBB F2                 4556 	movx	@r0,a
   1DBC 80 B2              4557 	sjmp	00143$
   1DBE                    4558 00146$:
                    1203   4559 	C$twitch_ax.c$820$1$1 ==.
                           4560 ;	apps/twitch_ax/twitch_ax.c:820: runner->frame = i;
   1DBE 78 7E              4561 	mov	r0,#_gaitRunnerProcess_runner_1_1
   1DC0 E2                 4562 	movx	a,@r0
   1DC1 24 04              4563 	add	a,#0x04
   1DC3 FB                 4564 	mov	r3,a
   1DC4 08                 4565 	inc	r0
   1DC5 E2                 4566 	movx	a,@r0
   1DC6 34 00              4567 	addc	a,#0x00
   1DC8 FE                 4568 	mov	r6,a
   1DC9 08                 4569 	inc	r0
   1DCA E2                 4570 	movx	a,@r0
   1DCB FF                 4571 	mov	r7,a
   1DCC 8B 82              4572 	mov	dpl,r3
   1DCE 8E 83              4573 	mov	dph,r6
   1DD0 8F F0              4574 	mov	b,r7
   1DD2 78 93              4575 	mov	r0,#_gaitRunnerProcess_i_1_1
   1DD4 E2                 4576 	movx	a,@r0
   1DD5 12 36 56           4577 	lcall	__gptrput
                    121D   4578 	C$twitch_ax.c$828$1$1 ==.
                           4579 ;	apps/twitch_ax/twitch_ax.c:828: frameTimeOffset = frameTime-frameStartTime;
   1DD8 78 8C              4580 	mov	r0,#_gaitRunnerProcess_frameTime_1_1
   1DDA 79 94              4581 	mov	r1,#_gaitRunnerProcess_frameTimeOffset_1_1
   1DDC E2                 4582 	movx	a,@r0
   1DDD C3                 4583 	clr	c
   1DDE 9C                 4584 	subb	a,r4
   1DDF F3                 4585 	movx	@r1,a
   1DE0 08                 4586 	inc	r0
   1DE1 E2                 4587 	movx	a,@r0
   1DE2 9D                 4588 	subb	a,r5
   1DE3 09                 4589 	inc	r1
   1DE4 F3                 4590 	movx	@r1,a
                    122A   4591 	C$twitch_ax.c$830$1$1 ==.
                           4592 ;	apps/twitch_ax/twitch_ax.c:830: distanceGuess = ((float)(frameTimeOffset)) / ((float)(frameEndTime-frameStartTime));
   1DE5 78 94              4593 	mov	r0,#_gaitRunnerProcess_frameTimeOffset_1_1
   1DE7 E2                 4594 	movx	a,@r0
   1DE8 F5 82              4595 	mov	dpl,a
   1DEA 08                 4596 	inc	r0
   1DEB E2                 4597 	movx	a,@r0
   1DEC F5 83              4598 	mov	dph,a
   1DEE C0 05              4599 	push	ar5
   1DF0 C0 04              4600 	push	ar4
   1DF2 12 41 46           4601 	lcall	___uint2fs
   1DF5 85 82 64           4602 	mov	_gaitRunnerProcess_sloc9_1_0,dpl
   1DF8 85 83 65           4603 	mov	(_gaitRunnerProcess_sloc9_1_0 + 1),dph
   1DFB 85 F0 66           4604 	mov	(_gaitRunnerProcess_sloc9_1_0 + 2),b
   1DFE F5 67              4605 	mov	(_gaitRunnerProcess_sloc9_1_0 + 3),a
   1E00 D0 04              4606 	pop	ar4
   1E02 D0 05              4607 	pop	ar5
   1E04 78 8E              4608 	mov	r0,#_gaitRunnerProcess_frameEndTime_1_1
   1E06 E2                 4609 	movx	a,@r0
   1E07 C3                 4610 	clr	c
   1E08 9C                 4611 	subb	a,r4
   1E09 F5 82              4612 	mov	dpl,a
   1E0B 08                 4613 	inc	r0
   1E0C E2                 4614 	movx	a,@r0
   1E0D 9D                 4615 	subb	a,r5
   1E0E F5 83              4616 	mov	dph,a
   1E10 12 41 46           4617 	lcall	___uint2fs
   1E13 AC 82              4618 	mov	r4,dpl
   1E15 AD 83              4619 	mov	r5,dph
   1E17 AE F0              4620 	mov	r6,b
   1E19 FF                 4621 	mov	r7,a
   1E1A C0 04              4622 	push	ar4
   1E1C C0 05              4623 	push	ar5
   1E1E C0 06              4624 	push	ar6
   1E20 C0 07              4625 	push	ar7
   1E22 85 64 82           4626 	mov	dpl,_gaitRunnerProcess_sloc9_1_0
   1E25 85 65 83           4627 	mov	dph,(_gaitRunnerProcess_sloc9_1_0 + 1)
   1E28 85 66 F0           4628 	mov	b,(_gaitRunnerProcess_sloc9_1_0 + 2)
   1E2B E5 67              4629 	mov	a,(_gaitRunnerProcess_sloc9_1_0 + 3)
   1E2D 12 42 03           4630 	lcall	___fsdiv
   1E30 78 96              4631 	mov	r0,#_gaitRunnerProcess_distanceGuess_1_1
   1E32 C0 E0              4632 	push	acc
   1E34 E5 82              4633 	mov	a,dpl
   1E36 F2                 4634 	movx	@r0,a
   1E37 08                 4635 	inc	r0
   1E38 E5 83              4636 	mov	a,dph
   1E3A F2                 4637 	movx	@r0,a
   1E3B 08                 4638 	inc	r0
   1E3C E5 F0              4639 	mov	a,b
   1E3E F2                 4640 	movx	@r0,a
   1E3F D0 E0              4641 	pop	acc
   1E41 08                 4642 	inc	r0
   1E42 F2                 4643 	movx	@r0,a
   1E43 E5 81              4644 	mov	a,sp
   1E45 24 FC              4645 	add	a,#0xfc
   1E47 F5 81              4646 	mov	sp,a
                    128E   4647 	C$twitch_ax.c$832$1$1 ==.
                           4648 ;	apps/twitch_ax/twitch_ax.c:832: limb = (const G8_LIMB_POSITION*)pgm_read_word(&frame->limbs);
   1E49 78 90              4649 	mov	r0,#_gaitRunnerProcess_frame_1_1
   1E4B E2                 4650 	movx	a,@r0
   1E4C 24 02              4651 	add	a,#0x02
   1E4E FA                 4652 	mov	r2,a
   1E4F 08                 4653 	inc	r0
   1E50 E2                 4654 	movx	a,@r0
   1E51 34 00              4655 	addc	a,#0x00
   1E53 FB                 4656 	mov	r3,a
   1E54 08                 4657 	inc	r0
   1E55 E2                 4658 	movx	a,@r0
   1E56 FF                 4659 	mov	r7,a
   1E57 8A 82              4660 	mov	dpl,r2
   1E59 8B 83              4661 	mov	dph,r3
   1E5B 8F F0              4662 	mov	b,r7
   1E5D 12 42 C6           4663 	lcall	__gptrget
   1E60 FA                 4664 	mov	r2,a
   1E61 A3                 4665 	inc	dptr
   1E62 12 42 C6           4666 	lcall	__gptrget
   1E65 FB                 4667 	mov	r3,a
   1E66 A3                 4668 	inc	dptr
   1E67 12 42 C6           4669 	lcall	__gptrget
   1E6A FF                 4670 	mov	r7,a
                    12B0   4671 	C$twitch_ax.c$834$1$1 ==.
                           4672 ;	apps/twitch_ax/twitch_ax.c:834: for(i = 0; i < NUM_ACTUATORS; i++, limb++){
   1E6B 78 93              4673 	mov	r0,#_gaitRunnerProcess_i_1_1
   1E6D E4                 4674 	clr	a
   1E6E F2                 4675 	movx	@r0,a
   1E6F 8A 64              4676 	mov	_gaitRunnerProcess_sloc9_1_0,r2
   1E71 8B 65              4677 	mov	(_gaitRunnerProcess_sloc9_1_0 + 1),r3
   1E73 8F 66              4678 	mov	(_gaitRunnerProcess_sloc9_1_0 + 2),r7
   1E75                    4679 00197$:
   1E75 78 93              4680 	mov	r0,#_gaitRunnerProcess_i_1_1
   1E77 E2                 4681 	movx	a,@r0
   1E78 B4 03 00           4682 	cjne	a,#0x03,00290$
   1E7B                    4683 00290$:
   1E7B 40 03              4684 	jc	00291$
   1E7D 02 20 3C           4685 	ljmp	00200$
   1E80                    4686 00291$:
                    12C5   4687 	C$twitch_ax.c$835$2$1 ==.
                           4688 ;	apps/twitch_ax/twitch_ax.c:835: float distanceMin = 0.0;
   1E80 7F 00              4689 	mov	r7,#0x00
   1E82 7E 00              4690 	mov	r6,#0x00
   1E84 7D 00              4691 	mov	r5,#0x00
   1E86 7C 00              4692 	mov	r4,#0x00
                    12CD   4693 	C$twitch_ax.c$836$2$1 ==.
                           4694 ;	apps/twitch_ax/twitch_ax.c:836: float distanceMax = 1.0;
   1E88 78 9A              4695 	mov	r0,#_gaitRunnerProcess_distanceMax_2_24
   1E8A E4                 4696 	clr	a
   1E8B F2                 4697 	movx	@r0,a
   1E8C 08                 4698 	inc	r0
   1E8D F2                 4699 	movx	@r0,a
   1E8E 08                 4700 	inc	r0
   1E8F 74 80              4701 	mov	a,#0x80
   1E91 F2                 4702 	movx	@r0,a
   1E92 08                 4703 	inc	r0
   1E93 74 3F              4704 	mov	a,#0x3F
   1E95 F2                 4705 	movx	@r0,a
                    12DB   4706 	C$twitch_ax.c$837$2$1 ==.
                           4707 ;	apps/twitch_ax/twitch_ax.c:837: float distance = distanceGuess;
   1E96 78 96              4708 	mov	r0,#_gaitRunnerProcess_distanceGuess_1_1
   1E98 79 9E              4709 	mov	r1,#_gaitRunnerProcess_distance_2_24
   1E9A E2                 4710 	movx	a,@r0
   1E9B F3                 4711 	movx	@r1,a
   1E9C 08                 4712 	inc	r0
   1E9D E2                 4713 	movx	a,@r0
   1E9E 09                 4714 	inc	r1
   1E9F F3                 4715 	movx	@r1,a
   1EA0 08                 4716 	inc	r0
   1EA1 E2                 4717 	movx	a,@r0
   1EA2 09                 4718 	inc	r1
   1EA3 F3                 4719 	movx	@r1,a
   1EA4 08                 4720 	inc	r0
   1EA5 E2                 4721 	movx	a,@r0
   1EA6 09                 4722 	inc	r1
   1EA7 F3                 4723 	movx	@r1,a
                    12ED   4724 	C$twitch_ax.c$840$1$1 ==.
                           4725 ;	apps/twitch_ax/twitch_ax.c:840: for(iterations=0; iterations<20; iterations++){
   1EA8 78 A2              4726 	mov	r0,#_gaitRunnerProcess_iterations_2_24
   1EAA E4                 4727 	clr	a
   1EAB F2                 4728 	movx	@r0,a
   1EAC                    4729 00152$:
   1EAC 78 A2              4730 	mov	r0,#_gaitRunnerProcess_iterations_2_24
   1EAE E2                 4731 	movx	a,@r0
   1EAF B4 14 00           4732 	cjne	a,#0x14,00292$
   1EB2                    4733 00292$:
   1EB2 40 03              4734 	jc	00293$
   1EB4 02 1F D3           4735 	ljmp	00155$
   1EB7                    4736 00293$:
                    12FC   4737 	C$twitch_ax.c$841$3$25 ==.
                           4738 ;	apps/twitch_ax/twitch_ax.c:841: uint16 actualX = calcX(limb, distance);
   1EB7 78 9E              4739 	mov	r0,#_gaitRunnerProcess_distance_2_24
   1EB9 79 5B              4740 	mov	r1,#_calcX_PARM_2
   1EBB E2                 4741 	movx	a,@r0
   1EBC F3                 4742 	movx	@r1,a
   1EBD 08                 4743 	inc	r0
   1EBE E2                 4744 	movx	a,@r0
   1EBF 09                 4745 	inc	r1
   1EC0 F3                 4746 	movx	@r1,a
   1EC1 08                 4747 	inc	r0
   1EC2 E2                 4748 	movx	a,@r0
   1EC3 09                 4749 	inc	r1
   1EC4 F3                 4750 	movx	@r1,a
   1EC5 08                 4751 	inc	r0
   1EC6 E2                 4752 	movx	a,@r0
   1EC7 09                 4753 	inc	r1
   1EC8 F3                 4754 	movx	@r1,a
   1EC9 85 64 82           4755 	mov	dpl,_gaitRunnerProcess_sloc9_1_0
   1ECC 85 65 83           4756 	mov	dph,(_gaitRunnerProcess_sloc9_1_0 + 1)
   1ECF 85 66 F0           4757 	mov	b,(_gaitRunnerProcess_sloc9_1_0 + 2)
   1ED2 C0 07              4758 	push	ar7
   1ED4 C0 06              4759 	push	ar6
   1ED6 C0 05              4760 	push	ar5
   1ED8 C0 04              4761 	push	ar4
   1EDA 12 14 C8           4762 	lcall	_calcX
   1EDD AA 82              4763 	mov	r2,dpl
   1EDF AB 83              4764 	mov	r3,dph
   1EE1 D0 04              4765 	pop	ar4
   1EE3 D0 05              4766 	pop	ar5
   1EE5 D0 06              4767 	pop	ar6
   1EE7 D0 07              4768 	pop	ar7
                    132E   4769 	C$twitch_ax.c$842$3$25 ==.
                           4770 ;	apps/twitch_ax/twitch_ax.c:842: if(actualX == frameTimeOffset) break;	// Found it
   1EE9 78 94              4771 	mov	r0,#_gaitRunnerProcess_frameTimeOffset_1_1
   1EEB E2                 4772 	movx	a,@r0
   1EEC B5 02 08           4773 	cjne	a,ar2,00294$
   1EEF 08                 4774 	inc	r0
   1EF0 E2                 4775 	movx	a,@r0
   1EF1 B5 03 03           4776 	cjne	a,ar3,00294$
   1EF4 02 1F D3           4777 	ljmp	00155$
   1EF7                    4778 00294$:
                    133C   4779 	C$twitch_ax.c$844$3$25 ==.
                           4780 ;	apps/twitch_ax/twitch_ax.c:844: if( actualX < frameTimeOffset){
   1EF7 78 94              4781 	mov	r0,#_gaitRunnerProcess_frameTimeOffset_1_1
   1EF9 C3                 4782 	clr	c
   1EFA E2                 4783 	movx	a,@r0
   1EFB F5 F0              4784 	mov	b,a
   1EFD EA                 4785 	mov	a,r2
   1EFE 95 F0              4786 	subb	a,b
   1F00 08                 4787 	inc	r0
   1F01 E2                 4788 	movx	a,@r0
   1F02 F5 F0              4789 	mov	b,a
   1F04 EB                 4790 	mov	a,r3
   1F05 95 F0              4791 	subb	a,b
   1F07 50 0F              4792 	jnc	00150$
                    134E   4793 	C$twitch_ax.c$846$4$26 ==.
                           4794 ;	apps/twitch_ax/twitch_ax.c:846: distanceMin = distance;
   1F09 78 9E              4795 	mov	r0,#_gaitRunnerProcess_distance_2_24
   1F0B E2                 4796 	movx	a,@r0
   1F0C FF                 4797 	mov	r7,a
   1F0D 08                 4798 	inc	r0
   1F0E E2                 4799 	movx	a,@r0
   1F0F FE                 4800 	mov	r6,a
   1F10 08                 4801 	inc	r0
   1F11 E2                 4802 	movx	a,@r0
   1F12 FD                 4803 	mov	r5,a
   1F13 08                 4804 	inc	r0
   1F14 E2                 4805 	movx	a,@r0
   1F15 FC                 4806 	mov	r4,a
   1F16 80 12              4807 	sjmp	00151$
   1F18                    4808 00150$:
                    135D   4809 	C$twitch_ax.c$848$4$27 ==.
                           4810 ;	apps/twitch_ax/twitch_ax.c:848: distanceMax = distance;
   1F18 78 9E              4811 	mov	r0,#_gaitRunnerProcess_distance_2_24
   1F1A 79 9A              4812 	mov	r1,#_gaitRunnerProcess_distanceMax_2_24
   1F1C E2                 4813 	movx	a,@r0
   1F1D F3                 4814 	movx	@r1,a
   1F1E 08                 4815 	inc	r0
   1F1F E2                 4816 	movx	a,@r0
   1F20 09                 4817 	inc	r1
   1F21 F3                 4818 	movx	@r1,a
   1F22 08                 4819 	inc	r0
   1F23 E2                 4820 	movx	a,@r0
   1F24 09                 4821 	inc	r1
   1F25 F3                 4822 	movx	@r1,a
   1F26 08                 4823 	inc	r0
   1F27 E2                 4824 	movx	a,@r0
   1F28 09                 4825 	inc	r1
   1F29 F3                 4826 	movx	@r1,a
   1F2A                    4827 00151$:
                    136F   4828 	C$twitch_ax.c$852$1$1 ==.
                           4829 ;	apps/twitch_ax/twitch_ax.c:852: distance = distanceMin + ((distanceMax - distanceMin) / 2);
   1F2A C0 07              4830 	push	ar7
   1F2C C0 06              4831 	push	ar6
   1F2E C0 05              4832 	push	ar5
   1F30 C0 04              4833 	push	ar4
   1F32 C0 07              4834 	push	ar7
   1F34 C0 06              4835 	push	ar6
   1F36 C0 05              4836 	push	ar5
   1F38 C0 04              4837 	push	ar4
   1F3A 78 9A              4838 	mov	r0,#_gaitRunnerProcess_distanceMax_2_24
   1F3C E2                 4839 	movx	a,@r0
   1F3D F5 82              4840 	mov	dpl,a
   1F3F 08                 4841 	inc	r0
   1F40 E2                 4842 	movx	a,@r0
   1F41 F5 83              4843 	mov	dph,a
   1F43 08                 4844 	inc	r0
   1F44 E2                 4845 	movx	a,@r0
   1F45 F5 F0              4846 	mov	b,a
   1F47 08                 4847 	inc	r0
   1F48 E2                 4848 	movx	a,@r0
   1F49 12 30 5D           4849 	lcall	___fssub
   1F4C 85 82 68           4850 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   1F4F 85 83 69           4851 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   1F52 85 F0 6A           4852 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   1F55 F5 6B              4853 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   1F57 E5 81              4854 	mov	a,sp
   1F59 24 FC              4855 	add	a,#0xfc
   1F5B F5 81              4856 	mov	sp,a
   1F5D E4                 4857 	clr	a
   1F5E C0 E0              4858 	push	acc
   1F60 C0 E0              4859 	push	acc
   1F62 C0 E0              4860 	push	acc
   1F64 74 40              4861 	mov	a,#0x40
   1F66 C0 E0              4862 	push	acc
   1F68 85 68 82           4863 	mov	dpl,_gaitRunnerProcess_sloc10_1_0
   1F6B 85 69 83           4864 	mov	dph,(_gaitRunnerProcess_sloc10_1_0 + 1)
   1F6E 85 6A F0           4865 	mov	b,(_gaitRunnerProcess_sloc10_1_0 + 2)
   1F71 E5 6B              4866 	mov	a,(_gaitRunnerProcess_sloc10_1_0 + 3)
   1F73 12 42 03           4867 	lcall	___fsdiv
   1F76 85 82 68           4868 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   1F79 85 83 69           4869 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   1F7C 85 F0 6A           4870 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   1F7F F5 6B              4871 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   1F81 E5 81              4872 	mov	a,sp
   1F83 24 FC              4873 	add	a,#0xfc
   1F85 F5 81              4874 	mov	sp,a
   1F87 D0 04              4875 	pop	ar4
   1F89 D0 05              4876 	pop	ar5
   1F8B D0 06              4877 	pop	ar6
   1F8D D0 07              4878 	pop	ar7
   1F8F C0 07              4879 	push	ar7
   1F91 C0 06              4880 	push	ar6
   1F93 C0 05              4881 	push	ar5
   1F95 C0 04              4882 	push	ar4
   1F97 C0 68              4883 	push	_gaitRunnerProcess_sloc10_1_0
   1F99 C0 69              4884 	push	(_gaitRunnerProcess_sloc10_1_0 + 1)
   1F9B C0 6A              4885 	push	(_gaitRunnerProcess_sloc10_1_0 + 2)
   1F9D C0 6B              4886 	push	(_gaitRunnerProcess_sloc10_1_0 + 3)
   1F9F 8F 82              4887 	mov	dpl,r7
   1FA1 8E 83              4888 	mov	dph,r6
   1FA3 8D F0              4889 	mov	b,r5
   1FA5 EC                 4890 	mov	a,r4
   1FA6 12 3B EB           4891 	lcall	___fsadd
   1FA9 78 9E              4892 	mov	r0,#_gaitRunnerProcess_distance_2_24
   1FAB C0 E0              4893 	push	acc
   1FAD E5 82              4894 	mov	a,dpl
   1FAF F2                 4895 	movx	@r0,a
   1FB0 08                 4896 	inc	r0
   1FB1 E5 83              4897 	mov	a,dph
   1FB3 F2                 4898 	movx	@r0,a
   1FB4 08                 4899 	inc	r0
   1FB5 E5 F0              4900 	mov	a,b
   1FB7 F2                 4901 	movx	@r0,a
   1FB8 D0 E0              4902 	pop	acc
   1FBA 08                 4903 	inc	r0
   1FBB F2                 4904 	movx	@r0,a
   1FBC E5 81              4905 	mov	a,sp
   1FBE 24 FC              4906 	add	a,#0xfc
   1FC0 F5 81              4907 	mov	sp,a
   1FC2 D0 04              4908 	pop	ar4
   1FC4 D0 05              4909 	pop	ar5
   1FC6 D0 06              4910 	pop	ar6
   1FC8 D0 07              4911 	pop	ar7
                    140F   4912 	C$twitch_ax.c$840$2$24 ==.
                           4913 ;	apps/twitch_ax/twitch_ax.c:840: for(iterations=0; iterations<20; iterations++){
   1FCA 78 A2              4914 	mov	r0,#_gaitRunnerProcess_iterations_2_24
   1FCC E2                 4915 	movx	a,@r0
   1FCD 24 01              4916 	add	a,#0x01
   1FCF F2                 4917 	movx	@r0,a
   1FD0 02 1E AC           4918 	ljmp	00152$
   1FD3                    4919 00155$:
                    1418   4920 	C$twitch_ax.c$856$2$24 ==.
                           4921 ;	apps/twitch_ax/twitch_ax.c:856: runner->speeds[i] = calcY(limb,distance);
   1FD3 85 5E 82           4922 	mov	dpl,_gaitRunnerProcess_sloc7_1_0
   1FD6 85 5F 83           4923 	mov	dph,(_gaitRunnerProcess_sloc7_1_0 + 1)
   1FD9 85 60 F0           4924 	mov	b,(_gaitRunnerProcess_sloc7_1_0 + 2)
   1FDC 12 42 C6           4925 	lcall	__gptrget
   1FDF FA                 4926 	mov	r2,a
   1FE0 A3                 4927 	inc	dptr
   1FE1 12 42 C6           4928 	lcall	__gptrget
   1FE4 FB                 4929 	mov	r3,a
   1FE5 A3                 4930 	inc	dptr
   1FE6 12 42 C6           4931 	lcall	__gptrget
   1FE9 FF                 4932 	mov	r7,a
   1FEA 78 93              4933 	mov	r0,#_gaitRunnerProcess_i_1_1
   1FEC E2                 4934 	movx	a,@r0
   1FED 2A                 4935 	add	a,r2
   1FEE FA                 4936 	mov	r2,a
   1FEF E4                 4937 	clr	a
   1FF0 3B                 4938 	addc	a,r3
   1FF1 FB                 4939 	mov	r3,a
   1FF2 78 9E              4940 	mov	r0,#_gaitRunnerProcess_distance_2_24
   1FF4 79 6B              4941 	mov	r1,#_calcY_PARM_2
   1FF6 E2                 4942 	movx	a,@r0
   1FF7 F3                 4943 	movx	@r1,a
   1FF8 08                 4944 	inc	r0
   1FF9 E2                 4945 	movx	a,@r0
   1FFA 09                 4946 	inc	r1
   1FFB F3                 4947 	movx	@r1,a
   1FFC 08                 4948 	inc	r0
   1FFD E2                 4949 	movx	a,@r0
   1FFE 09                 4950 	inc	r1
   1FFF F3                 4951 	movx	@r1,a
   2000 08                 4952 	inc	r0
   2001 E2                 4953 	movx	a,@r0
   2002 09                 4954 	inc	r1
   2003 F3                 4955 	movx	@r1,a
   2004 85 64 82           4956 	mov	dpl,_gaitRunnerProcess_sloc9_1_0
   2007 85 65 83           4957 	mov	dph,(_gaitRunnerProcess_sloc9_1_0 + 1)
   200A 85 66 F0           4958 	mov	b,(_gaitRunnerProcess_sloc9_1_0 + 2)
   200D C0 07              4959 	push	ar7
   200F C0 03              4960 	push	ar3
   2011 C0 02              4961 	push	ar2
   2013 12 16 8D           4962 	lcall	_calcY
   2016 AE 82              4963 	mov	r6,dpl
   2018 D0 02              4964 	pop	ar2
   201A D0 03              4965 	pop	ar3
   201C D0 07              4966 	pop	ar7
   201E 8A 82              4967 	mov	dpl,r2
   2020 8B 83              4968 	mov	dph,r3
   2022 8F F0              4969 	mov	b,r7
   2024 EE                 4970 	mov	a,r6
   2025 12 36 56           4971 	lcall	__gptrput
                    146D   4972 	C$twitch_ax.c$834$1$1 ==.
                           4973 ;	apps/twitch_ax/twitch_ax.c:834: for(i = 0; i < NUM_ACTUATORS; i++, limb++){
   2028 78 93              4974 	mov	r0,#_gaitRunnerProcess_i_1_1
   202A E2                 4975 	movx	a,@r0
   202B 24 01              4976 	add	a,#0x01
   202D F2                 4977 	movx	@r0,a
   202E 74 0D              4978 	mov	a,#0x0D
   2030 25 64              4979 	add	a,_gaitRunnerProcess_sloc9_1_0
   2032 F5 64              4980 	mov	_gaitRunnerProcess_sloc9_1_0,a
   2034 E4                 4981 	clr	a
   2035 35 65              4982 	addc	a,(_gaitRunnerProcess_sloc9_1_0 + 1)
   2037 F5 65              4983 	mov	(_gaitRunnerProcess_sloc9_1_0 + 1),a
   2039 02 1E 75           4984 	ljmp	00197$
   203C                    4985 00200$:
                    1481   4986 	C$twitch_ax.c$865$3$29 ==.
                           4987 ;	apps/twitch_ax/twitch_ax.c:865: for(limbNumber = 0; limbNumber < NUM_ACTUATORS; limbNumber++){
   203C 7E 00              4988 	mov	r6,#0x00
   203E 7F 00              4989 	mov	r7,#0x00
   2040                    4990 00201$:
   2040 C3                 4991 	clr	c
   2041 EE                 4992 	mov	a,r6
   2042 94 03              4993 	subb	a,#0x03
   2044 EF                 4994 	mov	a,r7
   2045 94 00              4995 	subb	a,#0x00
   2047 40 03              4996 	jc	00296$
   2049 02 27 45           4997 	ljmp	00204$
   204C                    4998 00296$:
                    1491   4999 	C$twitch_ax.c$869$3$29 ==.
                           5000 ;	apps/twitch_ax/twitch_ax.c:869: uint8 servo = (uint8)(61+limbNumber); // Using IDs 61, 62, 63
   204C 8E 05              5001 	mov	ar5,r6
   204E 78 AB              5002 	mov	r0,#_gaitRunnerProcess_servo_3_29
   2050 74 3D              5003 	mov	a,#0x3D
   2052 2D                 5004 	add	a,r5
   2053 F2                 5005 	movx	@r0,a
                    1499   5006 	C$twitch_ax.c$870$3$29 ==.
                           5007 ;	apps/twitch_ax/twitch_ax.c:870: int16 speed = (int16)(runner->speeds[limbNumber]);// + (int16)(runner->delta[limbNumber]);
   2054 85 5E 82           5008 	mov	dpl,_gaitRunnerProcess_sloc7_1_0
   2057 85 5F 83           5009 	mov	dph,(_gaitRunnerProcess_sloc7_1_0 + 1)
   205A 85 60 F0           5010 	mov	b,(_gaitRunnerProcess_sloc7_1_0 + 2)
   205D 12 42 C6           5011 	lcall	__gptrget
   2060 FA                 5012 	mov	r2,a
   2061 A3                 5013 	inc	dptr
   2062 12 42 C6           5014 	lcall	__gptrget
   2065 FB                 5015 	mov	r3,a
   2066 A3                 5016 	inc	dptr
   2067 12 42 C6           5017 	lcall	__gptrget
   206A FC                 5018 	mov	r4,a
   206B EE                 5019 	mov	a,r6
   206C 2A                 5020 	add	a,r2
   206D FA                 5021 	mov	r2,a
   206E EF                 5022 	mov	a,r7
   206F 3B                 5023 	addc	a,r3
   2070 FB                 5024 	mov	r3,a
   2071 8A 82              5025 	mov	dpl,r2
   2073 8B 83              5026 	mov	dph,r3
   2075 8C F0              5027 	mov	b,r4
   2077 12 42 C6           5028 	lcall	__gptrget
   207A FA                 5029 	mov	r2,a
   207B 78 AC              5030 	mov	r0,#_gaitRunnerProcess_speed_3_29
   207D F2                 5031 	movx	@r0,a
   207E EA                 5032 	mov	a,r2
   207F 33                 5033 	rlc	a
   2080 95 E0              5034 	subb	a,acc
   2082 08                 5035 	inc	r0
   2083 F2                 5036 	movx	@r0,a
                    14C9   5037 	C$twitch_ax.c$871$3$29 ==.
                           5038 ;	apps/twitch_ax/twitch_ax.c:871: speed = CLAMP(speed,DRIVE_SPEED_MIN,DRIVE_SPEED_MAX);
   2084 78 AC              5039 	mov	r0,#_gaitRunnerProcess_speed_3_29
   2086 C3                 5040 	clr	c
   2087 E2                 5041 	movx	a,@r0
   2088 94 7F              5042 	subb	a,#0x7F
   208A 08                 5043 	inc	r0
   208B E2                 5044 	movx	a,@r0
   208C 64 80              5045 	xrl	a,#0x80
   208E 94 80              5046 	subb	a,#0x80
   2090 50 09              5047 	jnc	00209$
   2092 78 AC              5048 	mov	r0,#_gaitRunnerProcess_speed_3_29
   2094 E2                 5049 	movx	a,@r0
   2095 FB                 5050 	mov	r3,a
   2096 08                 5051 	inc	r0
   2097 E2                 5052 	movx	a,@r0
   2098 FD                 5053 	mov	r5,a
   2099 80 04              5054 	sjmp	00210$
   209B                    5055 00209$:
   209B 7B 7F              5056 	mov	r3,#0x7F
   209D 7D 00              5057 	mov	r5,#0x00
   209F                    5058 00210$:
   209F C3                 5059 	clr	c
   20A0 74 81              5060 	mov	a,#0x81
   20A2 9B                 5061 	subb	a,r3
   20A3 74 7F              5062 	mov	a,#(0xFF ^ 0x80)
   20A5 8D F0              5063 	mov	b,r5
   20A7 63 F0 80           5064 	xrl	b,#0x80
   20AA 95 F0              5065 	subb	a,b
   20AC 50 1D              5066 	jnc	00207$
   20AE 78 AC              5067 	mov	r0,#_gaitRunnerProcess_speed_3_29
   20B0 C3                 5068 	clr	c
   20B1 E2                 5069 	movx	a,@r0
   20B2 94 7F              5070 	subb	a,#0x7F
   20B4 08                 5071 	inc	r0
   20B5 E2                 5072 	movx	a,@r0
   20B6 64 80              5073 	xrl	a,#0x80
   20B8 94 80              5074 	subb	a,#0x80
   20BA 50 09              5075 	jnc	00211$
   20BC 78 AC              5076 	mov	r0,#_gaitRunnerProcess_speed_3_29
   20BE E2                 5077 	movx	a,@r0
   20BF FB                 5078 	mov	r3,a
   20C0 08                 5079 	inc	r0
   20C1 E2                 5080 	movx	a,@r0
   20C2 FD                 5081 	mov	r5,a
   20C3 80 04              5082 	sjmp	00212$
   20C5                    5083 00211$:
   20C5 7B 7F              5084 	mov	r3,#0x7F
   20C7 7D 00              5085 	mov	r5,#0x00
   20C9                    5086 00212$:
   20C9 80 04              5087 	sjmp	00208$
   20CB                    5088 00207$:
   20CB 7B 81              5089 	mov	r3,#0x81
   20CD 7D FF              5090 	mov	r5,#0xFF
   20CF                    5091 00208$:
   20CF 78 AC              5092 	mov	r0,#_gaitRunnerProcess_speed_3_29
   20D1 EB                 5093 	mov	a,r3
   20D2 F2                 5094 	movx	@r0,a
   20D3 08                 5095 	inc	r0
   20D4 ED                 5096 	mov	a,r5
   20D5 F2                 5097 	movx	@r0,a
                    151B   5098 	C$twitch_ax.c$876$3$29 ==.
                           5099 ;	apps/twitch_ax/twitch_ax.c:876: speed = interpolateU(speed, DRIVE_SPEED_MIN, DRIVE_SPEED_MAX, 374, 650);
   20D6 78 2B              5100 	mov	r0,#_interpolateU_PARM_2
   20D8 74 81              5101 	mov	a,#0x81
   20DA F2                 5102 	movx	@r0,a
   20DB 08                 5103 	inc	r0
   20DC 74 FF              5104 	mov	a,#0xFF
   20DE F2                 5105 	movx	@r0,a
   20DF 78 2D              5106 	mov	r0,#_interpolateU_PARM_3
   20E1 74 7F              5107 	mov	a,#0x7F
   20E3 F2                 5108 	movx	@r0,a
   20E4 08                 5109 	inc	r0
   20E5 E4                 5110 	clr	a
   20E6 F2                 5111 	movx	@r0,a
   20E7 78 2F              5112 	mov	r0,#_interpolateU_PARM_4
   20E9 74 76              5113 	mov	a,#0x76
   20EB F2                 5114 	movx	@r0,a
   20EC 08                 5115 	inc	r0
   20ED 74 01              5116 	mov	a,#0x01
   20EF F2                 5117 	movx	@r0,a
   20F0 78 31              5118 	mov	r0,#_interpolateU_PARM_5
   20F2 74 8A              5119 	mov	a,#0x8A
   20F4 F2                 5120 	movx	@r0,a
   20F5 08                 5121 	inc	r0
   20F6 74 02              5122 	mov	a,#0x02
   20F8 F2                 5123 	movx	@r0,a
   20F9 78 AC              5124 	mov	r0,#_gaitRunnerProcess_speed_3_29
   20FB E2                 5125 	movx	a,@r0
   20FC F5 82              5126 	mov	dpl,a
   20FE 08                 5127 	inc	r0
   20FF E2                 5128 	movx	a,@r0
   2100 F5 83              5129 	mov	dph,a
   2102 C0 07              5130 	push	ar7
   2104 C0 06              5131 	push	ar6
   2106 12 0A DC           5132 	lcall	_interpolateU
   2109 AB 82              5133 	mov	r3,dpl
   210B AD 83              5134 	mov	r5,dph
   210D D0 06              5135 	pop	ar6
   210F D0 07              5136 	pop	ar7
   2111 78 AC              5137 	mov	r0,#_gaitRunnerProcess_speed_3_29
   2113 EB                 5138 	mov	a,r3
   2114 F2                 5139 	movx	@r0,a
   2115 08                 5140 	inc	r0
   2116 ED                 5141 	mov	a,r5
   2117 F2                 5142 	movx	@r0,a
                    155D   5143 	C$twitch_ax.c$879$3$29 ==.
                           5144 ;	apps/twitch_ax/twitch_ax.c:879: if( ( (limbNumber == 1) || (limbNumber == 2) ) && \
   2118 BE 01 05           5145 	cjne	r6,#0x01,00300$
   211B BF 00 02           5146 	cjne	r7,#0x00,00300$
   211E 80 0B              5147 	sjmp	00191$
   2120                    5148 00300$:
   2120 BE 02 05           5149 	cjne	r6,#0x02,00301$
   2123 BF 00 02           5150 	cjne	r7,#0x00,00301$
   2126 80 03              5151 	sjmp	00302$
   2128                    5152 00301$:
   2128 02 26 E4           5153 	ljmp	00186$
   212B                    5154 00302$:
   212B                    5155 00191$:
   212B 85 61 82           5156 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   212E 85 62 83           5157 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   2131 85 63 F0           5158 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   2134 12 42 C6           5159 	lcall	__gptrget
   2137 FD                 5160 	mov	r5,a
   2138 BD 04 02           5161 	cjne	r5,#0x04,00303$
   213B 80 10              5162 	sjmp	00185$
   213D                    5163 00303$:
   213D ED                 5164 	mov	a,r5
   213E 60 0D              5165 	jz	00185$
   2140 BD 06 02           5166 	cjne	r5,#0x06,00305$
   2143 80 08              5167 	sjmp	00185$
   2145                    5168 00305$:
   2145 BD 03 02           5169 	cjne	r5,#0x03,00306$
   2148 80 03              5170 	sjmp	00307$
   214A                    5171 00306$:
   214A 02 26 E4           5172 	ljmp	00186$
   214D                    5173 00307$:
   214D                    5174 00185$:
                    1592   5175 	C$twitch_ax.c$888$4$30 ==.
                           5176 ;	apps/twitch_ax/twitch_ax.c:888: if(walkV > 20 || lookV > 20) {
   214D 78 3C              5177 	mov	r0,#_walkV
   214F C3                 5178 	clr	c
   2150 E2                 5179 	movx	a,@r0
   2151 F5 F0              5180 	mov	b,a
   2153 74 94              5181 	mov	a,#(0x14 ^ 0x80)
   2155 63 F0 80           5182 	xrl	b,#0x80
   2158 95 F0              5183 	subb	a,b
   215A 40 12              5184 	jc	00181$
   215C 78 3E              5185 	mov	r0,#_lookV
   215E C3                 5186 	clr	c
   215F E2                 5187 	movx	a,@r0
   2160 F5 F0              5188 	mov	b,a
   2162 74 94              5189 	mov	a,#(0x14 ^ 0x80)
   2164 63 F0 80           5190 	xrl	b,#0x80
   2167 95 F0              5191 	subb	a,b
   2169 40 03              5192 	jc	00309$
   216B 02 24 1C           5193 	ljmp	00182$
   216E                    5194 00309$:
   216E                    5195 00181$:
                    15B3   5196 	C$twitch_ax.c$889$5$31 ==.
                           5197 ;	apps/twitch_ax/twitch_ax.c:889: if (servo == RIGHT_SERVO && walkV > lookV){
   216E 78 AB              5198 	mov	r0,#_gaitRunnerProcess_servo_3_29
   2170 E2                 5199 	movx	a,@r0
   2171 B4 3E 02           5200 	cjne	a,#0x3E,00310$
   2174 80 03              5201 	sjmp	00311$
   2176                    5202 00310$:
   2176 02 22 C5           5203 	ljmp	00164$
   2179                    5204 00311$:
   2179 78 3C              5205 	mov	r0,#_walkV
   217B 79 3E              5206 	mov	r1,#_lookV
   217D C3                 5207 	clr	c
   217E E2                 5208 	movx	a,@r0
   217F F5 F0              5209 	mov	b,a
   2181 E3                 5210 	movx	a,@r1
   2182 64 80              5211 	xrl	a,#0x80
   2184 63 F0 80           5212 	xrl	b,#0x80
   2187 95 F0              5213 	subb	a,b
   2189 40 03              5214 	jc	00312$
   218B 02 22 C5           5215 	ljmp	00164$
   218E                    5216 00312$:
                    15D3   5217 	C$twitch_ax.c$890$6$32 ==.
                           5218 ;	apps/twitch_ax/twitch_ax.c:890: if (lookV < 20) { lookV = 20; }
   218E 78 3E              5219 	mov	r0,#_lookV
   2190 C3                 5220 	clr	c
   2191 E2                 5221 	movx	a,@r0
   2192 64 80              5222 	xrl	a,#0x80
   2194 94 94              5223 	subb	a,#0x94
   2196 50 05              5224 	jnc	00157$
   2198 78 3E              5225 	mov	r0,#_lookV
   219A 74 14              5226 	mov	a,#0x14
   219C F2                 5227 	movx	@r0,a
   219D                    5228 00157$:
                    15E2   5229 	C$twitch_ax.c$892$1$1 ==.
                           5230 ;	apps/twitch_ax/twitch_ax.c:892: speedFactor = (1.0 + (lookV - 20) / ((float) (walkV - 20)) ) / 2.0;
   219D C0 06              5231 	push	ar6
   219F C0 07              5232 	push	ar7
   21A1 78 3E              5233 	mov	r0,#_lookV
   21A3 E2                 5234 	movx	a,@r0
   21A4 FB                 5235 	mov	r3,a
   21A5 E2                 5236 	movx	a,@r0
   21A6 33                 5237 	rlc	a
   21A7 95 E0              5238 	subb	a,acc
   21A9 FD                 5239 	mov	r5,a
   21AA EB                 5240 	mov	a,r3
   21AB 24 EC              5241 	add	a,#0xEC
   21AD FB                 5242 	mov	r3,a
   21AE ED                 5243 	mov	a,r5
   21AF 34 FF              5244 	addc	a,#0xFF
   21B1 FD                 5245 	mov	r5,a
   21B2 78 3C              5246 	mov	r0,#_walkV
   21B4 E2                 5247 	movx	a,@r0
   21B5 FE                 5248 	mov	r6,a
   21B6 E2                 5249 	movx	a,@r0
   21B7 33                 5250 	rlc	a
   21B8 95 E0              5251 	subb	a,acc
   21BA FF                 5252 	mov	r7,a
   21BB EE                 5253 	mov	a,r6
   21BC 24 EC              5254 	add	a,#0xEC
   21BE F5 82              5255 	mov	dpl,a
   21C0 EF                 5256 	mov	a,r7
   21C1 34 FF              5257 	addc	a,#0xFF
   21C3 F5 83              5258 	mov	dph,a
   21C5 C0 07              5259 	push	ar7
   21C7 C0 06              5260 	push	ar6
   21C9 C0 05              5261 	push	ar5
   21CB C0 03              5262 	push	ar3
   21CD 12 40 FA           5263 	lcall	___sint2fs
   21D0 85 82 68           5264 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   21D3 85 83 69           5265 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   21D6 85 F0 6A           5266 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   21D9 F5 6B              5267 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   21DB D0 03              5268 	pop	ar3
   21DD D0 05              5269 	pop	ar5
   21DF D0 06              5270 	pop	ar6
   21E1 D0 07              5271 	pop	ar7
   21E3 8B 82              5272 	mov	dpl,r3
   21E5 8D 83              5273 	mov	dph,r5
   21E7 12 40 FA           5274 	lcall	___sint2fs
   21EA AB 82              5275 	mov	r3,dpl
   21EC AD 83              5276 	mov	r5,dph
   21EE AE F0              5277 	mov	r6,b
   21F0 FF                 5278 	mov	r7,a
   21F1 C0 68              5279 	push	_gaitRunnerProcess_sloc10_1_0
   21F3 C0 69              5280 	push	(_gaitRunnerProcess_sloc10_1_0 + 1)
   21F5 C0 6A              5281 	push	(_gaitRunnerProcess_sloc10_1_0 + 2)
   21F7 C0 6B              5282 	push	(_gaitRunnerProcess_sloc10_1_0 + 3)
   21F9 8B 82              5283 	mov	dpl,r3
   21FB 8D 83              5284 	mov	dph,r5
   21FD 8E F0              5285 	mov	b,r6
   21FF EF                 5286 	mov	a,r7
   2200 12 42 03           5287 	lcall	___fsdiv
   2203 AC 82              5288 	mov	r4,dpl
   2205 AD 83              5289 	mov	r5,dph
   2207 AE F0              5290 	mov	r6,b
   2209 FF                 5291 	mov	r7,a
   220A E5 81              5292 	mov	a,sp
   220C 24 FC              5293 	add	a,#0xfc
   220E F5 81              5294 	mov	sp,a
   2210 E4                 5295 	clr	a
   2211 C0 E0              5296 	push	acc
   2213 C0 E0              5297 	push	acc
   2215 74 80              5298 	mov	a,#0x80
   2217 C0 E0              5299 	push	acc
   2219 74 3F              5300 	mov	a,#0x3F
   221B C0 E0              5301 	push	acc
   221D 8C 82              5302 	mov	dpl,r4
   221F 8D 83              5303 	mov	dph,r5
   2221 8E F0              5304 	mov	b,r6
   2223 EF                 5305 	mov	a,r7
   2224 12 3B EB           5306 	lcall	___fsadd
   2227 AC 82              5307 	mov	r4,dpl
   2229 AD 83              5308 	mov	r5,dph
   222B AE F0              5309 	mov	r6,b
   222D FF                 5310 	mov	r7,a
   222E E5 81              5311 	mov	a,sp
   2230 24 FC              5312 	add	a,#0xfc
   2232 F5 81              5313 	mov	sp,a
   2234 C0 07              5314 	push	ar7
   2236 C0 06              5315 	push	ar6
   2238 E4                 5316 	clr	a
   2239 C0 E0              5317 	push	acc
   223B C0 E0              5318 	push	acc
   223D C0 E0              5319 	push	acc
   223F 74 40              5320 	mov	a,#0x40
   2241 C0 E0              5321 	push	acc
   2243 8C 82              5322 	mov	dpl,r4
   2245 8D 83              5323 	mov	dph,r5
   2247 8E F0              5324 	mov	b,r6
   2249 EF                 5325 	mov	a,r7
   224A 12 42 03           5326 	lcall	___fsdiv
   224D 78 AE              5327 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   224F C0 E0              5328 	push	acc
   2251 E5 82              5329 	mov	a,dpl
   2253 F2                 5330 	movx	@r0,a
   2254 08                 5331 	inc	r0
   2255 E5 83              5332 	mov	a,dph
   2257 F2                 5333 	movx	@r0,a
   2258 08                 5334 	inc	r0
   2259 E5 F0              5335 	mov	a,b
   225B F2                 5336 	movx	@r0,a
   225C D0 E0              5337 	pop	acc
   225E 08                 5338 	inc	r0
   225F F2                 5339 	movx	@r0,a
   2260 E5 81              5340 	mov	a,sp
   2262 24 FC              5341 	add	a,#0xfc
   2264 F5 81              5342 	mov	sp,a
   2266 D0 06              5343 	pop	ar6
   2268 D0 07              5344 	pop	ar7
                    16AF   5345 	C$twitch_ax.c$894$6$32 ==.
                           5346 ;	apps/twitch_ax/twitch_ax.c:894: speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
   226A 78 AC              5347 	mov	r0,#_gaitRunnerProcess_speed_3_29
   226C E2                 5348 	movx	a,@r0
   226D F5 82              5349 	mov	dpl,a
   226F 08                 5350 	inc	r0
   2270 E2                 5351 	movx	a,@r0
   2271 24 FE              5352 	add	a,#0xFE
   2273 F5 83              5353 	mov	dph,a
   2275 12 40 FA           5354 	lcall	___sint2fs
   2278 AC 82              5355 	mov	r4,dpl
   227A AD 83              5356 	mov	r5,dph
   227C AE F0              5357 	mov	r6,b
   227E FF                 5358 	mov	r7,a
   227F 78 AE              5359 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   2281 E2                 5360 	movx	a,@r0
   2282 C0 E0              5361 	push	acc
   2284 08                 5362 	inc	r0
   2285 E2                 5363 	movx	a,@r0
   2286 C0 E0              5364 	push	acc
   2288 08                 5365 	inc	r0
   2289 E2                 5366 	movx	a,@r0
   228A C0 E0              5367 	push	acc
   228C 08                 5368 	inc	r0
   228D E2                 5369 	movx	a,@r0
   228E C0 E0              5370 	push	acc
   2290 8C 82              5371 	mov	dpl,r4
   2292 8D 83              5372 	mov	dph,r5
   2294 8E F0              5373 	mov	b,r6
   2296 EF                 5374 	mov	a,r7
   2297 12 32 50           5375 	lcall	___fsmul
   229A AC 82              5376 	mov	r4,dpl
   229C AD 83              5377 	mov	r5,dph
   229E AE F0              5378 	mov	r6,b
   22A0 FF                 5379 	mov	r7,a
   22A1 E5 81              5380 	mov	a,sp
   22A3 24 FC              5381 	add	a,#0xfc
   22A5 F5 81              5382 	mov	sp,a
   22A7 8C 82              5383 	mov	dpl,r4
   22A9 8D 83              5384 	mov	dph,r5
   22AB 8E F0              5385 	mov	b,r6
   22AD EF                 5386 	mov	a,r7
   22AE 12 41 07           5387 	lcall	___fs2sint
   22B1 AE 82              5388 	mov	r6,dpl
   22B3 AF 83              5389 	mov	r7,dph
   22B5 78 AC              5390 	mov	r0,#_gaitRunnerProcess_speed_3_29
   22B7 E2                 5391 	movx	a,@r0
   22B8 2E                 5392 	add	a,r6
   22B9 F2                 5393 	movx	@r0,a
   22BA 08                 5394 	inc	r0
   22BB E2                 5395 	movx	a,@r0
   22BC 3F                 5396 	addc	a,r7
   22BD F2                 5397 	movx	@r0,a
   22BE D0 07              5398 	pop	ar7
   22C0 D0 06              5399 	pop	ar6
   22C2 02 26 E4           5400 	ljmp	00186$
   22C5                    5401 00164$:
                    170A   5402 	C$twitch_ax.c$895$5$31 ==.
                           5403 ;	apps/twitch_ax/twitch_ax.c:895: } else if (servo == LEFT_SERVO && walkV < lookV){
   22C5 78 AB              5404 	mov	r0,#_gaitRunnerProcess_servo_3_29
   22C7 E2                 5405 	movx	a,@r0
   22C8 B4 3F 02           5406 	cjne	a,#0x3F,00314$
   22CB 80 03              5407 	sjmp	00315$
   22CD                    5408 00314$:
   22CD 02 26 E4           5409 	ljmp	00186$
   22D0                    5410 00315$:
   22D0 78 3C              5411 	mov	r0,#_walkV
   22D2 79 3E              5412 	mov	r1,#_lookV
   22D4 C3                 5413 	clr	c
   22D5 E3                 5414 	movx	a,@r1
   22D6 F5 F0              5415 	mov	b,a
   22D8 E2                 5416 	movx	a,@r0
   22D9 64 80              5417 	xrl	a,#0x80
   22DB 63 F0 80           5418 	xrl	b,#0x80
   22DE 95 F0              5419 	subb	a,b
   22E0 40 03              5420 	jc	00316$
   22E2 02 26 E4           5421 	ljmp	00186$
   22E5                    5422 00316$:
                    172A   5423 	C$twitch_ax.c$896$6$34 ==.
                           5424 ;	apps/twitch_ax/twitch_ax.c:896: if (walkV < 20) { walkV = 20; }
   22E5 78 3C              5425 	mov	r0,#_walkV
   22E7 C3                 5426 	clr	c
   22E8 E2                 5427 	movx	a,@r0
   22E9 64 80              5428 	xrl	a,#0x80
   22EB 94 94              5429 	subb	a,#0x94
   22ED 50 05              5430 	jnc	00159$
   22EF 78 3C              5431 	mov	r0,#_walkV
   22F1 74 14              5432 	mov	a,#0x14
   22F3 F2                 5433 	movx	@r0,a
   22F4                    5434 00159$:
                    1739   5435 	C$twitch_ax.c$898$1$1 ==.
                           5436 ;	apps/twitch_ax/twitch_ax.c:898: speedFactor = (1.0 + (walkV - 20) / ((float) (lookV - 20)) ) / 2.0;
   22F4 C0 06              5437 	push	ar6
   22F6 C0 07              5438 	push	ar7
   22F8 78 3C              5439 	mov	r0,#_walkV
   22FA E2                 5440 	movx	a,@r0
   22FB FC                 5441 	mov	r4,a
   22FC E2                 5442 	movx	a,@r0
   22FD 33                 5443 	rlc	a
   22FE 95 E0              5444 	subb	a,acc
   2300 FD                 5445 	mov	r5,a
   2301 EC                 5446 	mov	a,r4
   2302 24 EC              5447 	add	a,#0xEC
   2304 FC                 5448 	mov	r4,a
   2305 ED                 5449 	mov	a,r5
   2306 34 FF              5450 	addc	a,#0xFF
   2308 FD                 5451 	mov	r5,a
   2309 78 3E              5452 	mov	r0,#_lookV
   230B E2                 5453 	movx	a,@r0
   230C FA                 5454 	mov	r2,a
   230D E2                 5455 	movx	a,@r0
   230E 33                 5456 	rlc	a
   230F 95 E0              5457 	subb	a,acc
   2311 FB                 5458 	mov	r3,a
   2312 EA                 5459 	mov	a,r2
   2313 24 EC              5460 	add	a,#0xEC
   2315 F5 82              5461 	mov	dpl,a
   2317 EB                 5462 	mov	a,r3
   2318 34 FF              5463 	addc	a,#0xFF
   231A F5 83              5464 	mov	dph,a
   231C C0 07              5465 	push	ar7
   231E C0 06              5466 	push	ar6
   2320 C0 05              5467 	push	ar5
   2322 C0 04              5468 	push	ar4
   2324 12 40 FA           5469 	lcall	___sint2fs
   2327 85 82 68           5470 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   232A 85 83 69           5471 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   232D 85 F0 6A           5472 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   2330 F5 6B              5473 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   2332 D0 04              5474 	pop	ar4
   2334 D0 05              5475 	pop	ar5
   2336 D0 06              5476 	pop	ar6
   2338 D0 07              5477 	pop	ar7
   233A 8C 82              5478 	mov	dpl,r4
   233C 8D 83              5479 	mov	dph,r5
   233E 12 40 FA           5480 	lcall	___sint2fs
   2341 AC 82              5481 	mov	r4,dpl
   2343 AD 83              5482 	mov	r5,dph
   2345 AE F0              5483 	mov	r6,b
   2347 FF                 5484 	mov	r7,a
   2348 C0 68              5485 	push	_gaitRunnerProcess_sloc10_1_0
   234A C0 69              5486 	push	(_gaitRunnerProcess_sloc10_1_0 + 1)
   234C C0 6A              5487 	push	(_gaitRunnerProcess_sloc10_1_0 + 2)
   234E C0 6B              5488 	push	(_gaitRunnerProcess_sloc10_1_0 + 3)
   2350 8C 82              5489 	mov	dpl,r4
   2352 8D 83              5490 	mov	dph,r5
   2354 8E F0              5491 	mov	b,r6
   2356 EF                 5492 	mov	a,r7
   2357 12 42 03           5493 	lcall	___fsdiv
   235A AC 82              5494 	mov	r4,dpl
   235C AD 83              5495 	mov	r5,dph
   235E AE F0              5496 	mov	r6,b
   2360 FF                 5497 	mov	r7,a
   2361 E5 81              5498 	mov	a,sp
   2363 24 FC              5499 	add	a,#0xfc
   2365 F5 81              5500 	mov	sp,a
   2367 E4                 5501 	clr	a
   2368 C0 E0              5502 	push	acc
   236A C0 E0              5503 	push	acc
   236C 74 80              5504 	mov	a,#0x80
   236E C0 E0              5505 	push	acc
   2370 74 3F              5506 	mov	a,#0x3F
   2372 C0 E0              5507 	push	acc
   2374 8C 82              5508 	mov	dpl,r4
   2376 8D 83              5509 	mov	dph,r5
   2378 8E F0              5510 	mov	b,r6
   237A EF                 5511 	mov	a,r7
   237B 12 3B EB           5512 	lcall	___fsadd
   237E AC 82              5513 	mov	r4,dpl
   2380 AD 83              5514 	mov	r5,dph
   2382 AE F0              5515 	mov	r6,b
   2384 FF                 5516 	mov	r7,a
   2385 E5 81              5517 	mov	a,sp
   2387 24 FC              5518 	add	a,#0xfc
   2389 F5 81              5519 	mov	sp,a
   238B C0 07              5520 	push	ar7
   238D C0 06              5521 	push	ar6
   238F E4                 5522 	clr	a
   2390 C0 E0              5523 	push	acc
   2392 C0 E0              5524 	push	acc
   2394 C0 E0              5525 	push	acc
   2396 74 40              5526 	mov	a,#0x40
   2398 C0 E0              5527 	push	acc
   239A 8C 82              5528 	mov	dpl,r4
   239C 8D 83              5529 	mov	dph,r5
   239E 8E F0              5530 	mov	b,r6
   23A0 EF                 5531 	mov	a,r7
   23A1 12 42 03           5532 	lcall	___fsdiv
   23A4 78 AE              5533 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   23A6 C0 E0              5534 	push	acc
   23A8 E5 82              5535 	mov	a,dpl
   23AA F2                 5536 	movx	@r0,a
   23AB 08                 5537 	inc	r0
   23AC E5 83              5538 	mov	a,dph
   23AE F2                 5539 	movx	@r0,a
   23AF 08                 5540 	inc	r0
   23B0 E5 F0              5541 	mov	a,b
   23B2 F2                 5542 	movx	@r0,a
   23B3 D0 E0              5543 	pop	acc
   23B5 08                 5544 	inc	r0
   23B6 F2                 5545 	movx	@r0,a
   23B7 E5 81              5546 	mov	a,sp
   23B9 24 FC              5547 	add	a,#0xfc
   23BB F5 81              5548 	mov	sp,a
   23BD D0 06              5549 	pop	ar6
   23BF D0 07              5550 	pop	ar7
                    1806   5551 	C$twitch_ax.c$900$6$34 ==.
                           5552 ;	apps/twitch_ax/twitch_ax.c:900: speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
   23C1 78 AC              5553 	mov	r0,#_gaitRunnerProcess_speed_3_29
   23C3 E2                 5554 	movx	a,@r0
   23C4 F5 82              5555 	mov	dpl,a
   23C6 08                 5556 	inc	r0
   23C7 E2                 5557 	movx	a,@r0
   23C8 24 FE              5558 	add	a,#0xFE
   23CA F5 83              5559 	mov	dph,a
   23CC 12 40 FA           5560 	lcall	___sint2fs
   23CF AC 82              5561 	mov	r4,dpl
   23D1 AD 83              5562 	mov	r5,dph
   23D3 AE F0              5563 	mov	r6,b
   23D5 FF                 5564 	mov	r7,a
   23D6 78 AE              5565 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   23D8 E2                 5566 	movx	a,@r0
   23D9 C0 E0              5567 	push	acc
   23DB 08                 5568 	inc	r0
   23DC E2                 5569 	movx	a,@r0
   23DD C0 E0              5570 	push	acc
   23DF 08                 5571 	inc	r0
   23E0 E2                 5572 	movx	a,@r0
   23E1 C0 E0              5573 	push	acc
   23E3 08                 5574 	inc	r0
   23E4 E2                 5575 	movx	a,@r0
   23E5 C0 E0              5576 	push	acc
   23E7 8C 82              5577 	mov	dpl,r4
   23E9 8D 83              5578 	mov	dph,r5
   23EB 8E F0              5579 	mov	b,r6
   23ED EF                 5580 	mov	a,r7
   23EE 12 32 50           5581 	lcall	___fsmul
   23F1 AC 82              5582 	mov	r4,dpl
   23F3 AD 83              5583 	mov	r5,dph
   23F5 AE F0              5584 	mov	r6,b
   23F7 FF                 5585 	mov	r7,a
   23F8 E5 81              5586 	mov	a,sp
   23FA 24 FC              5587 	add	a,#0xfc
   23FC F5 81              5588 	mov	sp,a
   23FE 8C 82              5589 	mov	dpl,r4
   2400 8D 83              5590 	mov	dph,r5
   2402 8E F0              5591 	mov	b,r6
   2404 EF                 5592 	mov	a,r7
   2405 12 41 07           5593 	lcall	___fs2sint
   2408 AE 82              5594 	mov	r6,dpl
   240A AF 83              5595 	mov	r7,dph
   240C 78 AC              5596 	mov	r0,#_gaitRunnerProcess_speed_3_29
   240E E2                 5597 	movx	a,@r0
   240F 2E                 5598 	add	a,r6
   2410 F2                 5599 	movx	@r0,a
   2411 08                 5600 	inc	r0
   2412 E2                 5601 	movx	a,@r0
   2413 3F                 5602 	addc	a,r7
   2414 F2                 5603 	movx	@r0,a
   2415 D0 07              5604 	pop	ar7
   2417 D0 06              5605 	pop	ar6
   2419 02 26 E4           5606 	ljmp	00186$
   241C                    5607 00182$:
                    1861   5608 	C$twitch_ax.c$902$4$30 ==.
                           5609 ;	apps/twitch_ax/twitch_ax.c:902: } else if(walkV < -20 || lookV < -20){
   241C 78 3C              5610 	mov	r0,#_walkV
   241E C3                 5611 	clr	c
   241F E2                 5612 	movx	a,@r0
   2420 64 80              5613 	xrl	a,#0x80
   2422 94 6C              5614 	subb	a,#0x6c
   2424 40 0D              5615 	jc	00178$
   2426 78 3E              5616 	mov	r0,#_lookV
   2428 C3                 5617 	clr	c
   2429 E2                 5618 	movx	a,@r0
   242A 64 80              5619 	xrl	a,#0x80
   242C 94 6C              5620 	subb	a,#0x6c
   242E 40 03              5621 	jc	00319$
   2430 02 26 E4           5622 	ljmp	00186$
   2433                    5623 00319$:
   2433                    5624 00178$:
                    1878   5625 	C$twitch_ax.c$903$5$36 ==.
                           5626 ;	apps/twitch_ax/twitch_ax.c:903: if (servo == RIGHT_SERVO && walkV < lookV){
   2433 78 AB              5627 	mov	r0,#_gaitRunnerProcess_servo_3_29
   2435 E2                 5628 	movx	a,@r0
   2436 B4 3E 02           5629 	cjne	a,#0x3E,00320$
   2439 80 03              5630 	sjmp	00321$
   243B                    5631 00320$:
   243B 02 25 8D           5632 	ljmp	00175$
   243E                    5633 00321$:
   243E 78 3C              5634 	mov	r0,#_walkV
   2440 79 3E              5635 	mov	r1,#_lookV
   2442 C3                 5636 	clr	c
   2443 E3                 5637 	movx	a,@r1
   2444 F5 F0              5638 	mov	b,a
   2446 E2                 5639 	movx	a,@r0
   2447 64 80              5640 	xrl	a,#0x80
   2449 63 F0 80           5641 	xrl	b,#0x80
   244C 95 F0              5642 	subb	a,b
   244E 40 03              5643 	jc	00322$
   2450 02 25 8D           5644 	ljmp	00175$
   2453                    5645 00322$:
                    1898   5646 	C$twitch_ax.c$904$6$37 ==.
                           5647 ;	apps/twitch_ax/twitch_ax.c:904: if (lookV > -20) { lookV = -20; }
   2453 78 3E              5648 	mov	r0,#_lookV
   2455 C3                 5649 	clr	c
   2456 E2                 5650 	movx	a,@r0
   2457 F5 F0              5651 	mov	b,a
   2459 74 6C              5652 	mov	a,#(0xEC ^ 0x80)
   245B 63 F0 80           5653 	xrl	b,#0x80
   245E 95 F0              5654 	subb	a,b
   2460 50 05              5655 	jnc	00168$
   2462 78 3E              5656 	mov	r0,#_lookV
   2464 74 EC              5657 	mov	a,#0xEC
   2466 F2                 5658 	movx	@r0,a
   2467                    5659 00168$:
                    18AC   5660 	C$twitch_ax.c$906$1$1 ==.
                           5661 ;	apps/twitch_ax/twitch_ax.c:906: speedFactor = (1.0 + (lookV + 20) / ((float) (walkV + 20)) ) / 2.0;
   2467 C0 06              5662 	push	ar6
   2469 C0 07              5663 	push	ar7
   246B 78 3E              5664 	mov	r0,#_lookV
   246D E2                 5665 	movx	a,@r0
   246E FC                 5666 	mov	r4,a
   246F E2                 5667 	movx	a,@r0
   2470 33                 5668 	rlc	a
   2471 95 E0              5669 	subb	a,acc
   2473 FD                 5670 	mov	r5,a
   2474 74 14              5671 	mov	a,#0x14
   2476 2C                 5672 	add	a,r4
   2477 FC                 5673 	mov	r4,a
   2478 E4                 5674 	clr	a
   2479 3D                 5675 	addc	a,r5
   247A FD                 5676 	mov	r5,a
   247B 78 3C              5677 	mov	r0,#_walkV
   247D E2                 5678 	movx	a,@r0
   247E FA                 5679 	mov	r2,a
   247F E2                 5680 	movx	a,@r0
   2480 33                 5681 	rlc	a
   2481 95 E0              5682 	subb	a,acc
   2483 FB                 5683 	mov	r3,a
   2484 74 14              5684 	mov	a,#0x14
   2486 2A                 5685 	add	a,r2
   2487 F5 82              5686 	mov	dpl,a
   2489 E4                 5687 	clr	a
   248A 3B                 5688 	addc	a,r3
   248B F5 83              5689 	mov	dph,a
   248D C0 07              5690 	push	ar7
   248F C0 06              5691 	push	ar6
   2491 C0 05              5692 	push	ar5
   2493 C0 04              5693 	push	ar4
   2495 12 40 FA           5694 	lcall	___sint2fs
   2498 85 82 68           5695 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   249B 85 83 69           5696 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   249E 85 F0 6A           5697 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   24A1 F5 6B              5698 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   24A3 D0 04              5699 	pop	ar4
   24A5 D0 05              5700 	pop	ar5
   24A7 D0 06              5701 	pop	ar6
   24A9 D0 07              5702 	pop	ar7
   24AB 8C 82              5703 	mov	dpl,r4
   24AD 8D 83              5704 	mov	dph,r5
   24AF 12 40 FA           5705 	lcall	___sint2fs
   24B2 AC 82              5706 	mov	r4,dpl
   24B4 AD 83              5707 	mov	r5,dph
   24B6 AE F0              5708 	mov	r6,b
   24B8 FF                 5709 	mov	r7,a
   24B9 C0 68              5710 	push	_gaitRunnerProcess_sloc10_1_0
   24BB C0 69              5711 	push	(_gaitRunnerProcess_sloc10_1_0 + 1)
   24BD C0 6A              5712 	push	(_gaitRunnerProcess_sloc10_1_0 + 2)
   24BF C0 6B              5713 	push	(_gaitRunnerProcess_sloc10_1_0 + 3)
   24C1 8C 82              5714 	mov	dpl,r4
   24C3 8D 83              5715 	mov	dph,r5
   24C5 8E F0              5716 	mov	b,r6
   24C7 EF                 5717 	mov	a,r7
   24C8 12 42 03           5718 	lcall	___fsdiv
   24CB AC 82              5719 	mov	r4,dpl
   24CD AD 83              5720 	mov	r5,dph
   24CF AE F0              5721 	mov	r6,b
   24D1 FF                 5722 	mov	r7,a
   24D2 E5 81              5723 	mov	a,sp
   24D4 24 FC              5724 	add	a,#0xfc
   24D6 F5 81              5725 	mov	sp,a
   24D8 E4                 5726 	clr	a
   24D9 C0 E0              5727 	push	acc
   24DB C0 E0              5728 	push	acc
   24DD 74 80              5729 	mov	a,#0x80
   24DF C0 E0              5730 	push	acc
   24E1 74 3F              5731 	mov	a,#0x3F
   24E3 C0 E0              5732 	push	acc
   24E5 8C 82              5733 	mov	dpl,r4
   24E7 8D 83              5734 	mov	dph,r5
   24E9 8E F0              5735 	mov	b,r6
   24EB EF                 5736 	mov	a,r7
   24EC 12 3B EB           5737 	lcall	___fsadd
   24EF AC 82              5738 	mov	r4,dpl
   24F1 AD 83              5739 	mov	r5,dph
   24F3 AE F0              5740 	mov	r6,b
   24F5 FF                 5741 	mov	r7,a
   24F6 E5 81              5742 	mov	a,sp
   24F8 24 FC              5743 	add	a,#0xfc
   24FA F5 81              5744 	mov	sp,a
   24FC C0 07              5745 	push	ar7
   24FE C0 06              5746 	push	ar6
   2500 E4                 5747 	clr	a
   2501 C0 E0              5748 	push	acc
   2503 C0 E0              5749 	push	acc
   2505 C0 E0              5750 	push	acc
   2507 74 40              5751 	mov	a,#0x40
   2509 C0 E0              5752 	push	acc
   250B 8C 82              5753 	mov	dpl,r4
   250D 8D 83              5754 	mov	dph,r5
   250F 8E F0              5755 	mov	b,r6
   2511 EF                 5756 	mov	a,r7
   2512 12 42 03           5757 	lcall	___fsdiv
   2515 78 AE              5758 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   2517 C0 E0              5759 	push	acc
   2519 E5 82              5760 	mov	a,dpl
   251B F2                 5761 	movx	@r0,a
   251C 08                 5762 	inc	r0
   251D E5 83              5763 	mov	a,dph
   251F F2                 5764 	movx	@r0,a
   2520 08                 5765 	inc	r0
   2521 E5 F0              5766 	mov	a,b
   2523 F2                 5767 	movx	@r0,a
   2524 D0 E0              5768 	pop	acc
   2526 08                 5769 	inc	r0
   2527 F2                 5770 	movx	@r0,a
   2528 E5 81              5771 	mov	a,sp
   252A 24 FC              5772 	add	a,#0xfc
   252C F5 81              5773 	mov	sp,a
   252E D0 06              5774 	pop	ar6
   2530 D0 07              5775 	pop	ar7
                    1977   5776 	C$twitch_ax.c$908$6$37 ==.
                           5777 ;	apps/twitch_ax/twitch_ax.c:908: speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
   2532 78 AC              5778 	mov	r0,#_gaitRunnerProcess_speed_3_29
   2534 E2                 5779 	movx	a,@r0
   2535 F5 82              5780 	mov	dpl,a
   2537 08                 5781 	inc	r0
   2538 E2                 5782 	movx	a,@r0
   2539 24 FE              5783 	add	a,#0xFE
   253B F5 83              5784 	mov	dph,a
   253D 12 40 FA           5785 	lcall	___sint2fs
   2540 AC 82              5786 	mov	r4,dpl
   2542 AD 83              5787 	mov	r5,dph
   2544 AE F0              5788 	mov	r6,b
   2546 FF                 5789 	mov	r7,a
   2547 78 AE              5790 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   2549 E2                 5791 	movx	a,@r0
   254A C0 E0              5792 	push	acc
   254C 08                 5793 	inc	r0
   254D E2                 5794 	movx	a,@r0
   254E C0 E0              5795 	push	acc
   2550 08                 5796 	inc	r0
   2551 E2                 5797 	movx	a,@r0
   2552 C0 E0              5798 	push	acc
   2554 08                 5799 	inc	r0
   2555 E2                 5800 	movx	a,@r0
   2556 C0 E0              5801 	push	acc
   2558 8C 82              5802 	mov	dpl,r4
   255A 8D 83              5803 	mov	dph,r5
   255C 8E F0              5804 	mov	b,r6
   255E EF                 5805 	mov	a,r7
   255F 12 32 50           5806 	lcall	___fsmul
   2562 AC 82              5807 	mov	r4,dpl
   2564 AD 83              5808 	mov	r5,dph
   2566 AE F0              5809 	mov	r6,b
   2568 FF                 5810 	mov	r7,a
   2569 E5 81              5811 	mov	a,sp
   256B 24 FC              5812 	add	a,#0xfc
   256D F5 81              5813 	mov	sp,a
   256F 8C 82              5814 	mov	dpl,r4
   2571 8D 83              5815 	mov	dph,r5
   2573 8E F0              5816 	mov	b,r6
   2575 EF                 5817 	mov	a,r7
   2576 12 41 07           5818 	lcall	___fs2sint
   2579 AE 82              5819 	mov	r6,dpl
   257B AF 83              5820 	mov	r7,dph
   257D 78 AC              5821 	mov	r0,#_gaitRunnerProcess_speed_3_29
   257F E2                 5822 	movx	a,@r0
   2580 2E                 5823 	add	a,r6
   2581 F2                 5824 	movx	@r0,a
   2582 08                 5825 	inc	r0
   2583 E2                 5826 	movx	a,@r0
   2584 3F                 5827 	addc	a,r7
   2585 F2                 5828 	movx	@r0,a
   2586 D0 07              5829 	pop	ar7
   2588 D0 06              5830 	pop	ar6
   258A 02 26 E4           5831 	ljmp	00186$
   258D                    5832 00175$:
                    19D2   5833 	C$twitch_ax.c$909$5$36 ==.
                           5834 ;	apps/twitch_ax/twitch_ax.c:909: } else if (servo == LEFT_SERVO && walkV > lookV){
   258D 78 AB              5835 	mov	r0,#_gaitRunnerProcess_servo_3_29
   258F E2                 5836 	movx	a,@r0
   2590 B4 3F 02           5837 	cjne	a,#0x3F,00324$
   2593 80 03              5838 	sjmp	00325$
   2595                    5839 00324$:
   2595 02 26 E4           5840 	ljmp	00186$
   2598                    5841 00325$:
   2598 78 3C              5842 	mov	r0,#_walkV
   259A 79 3E              5843 	mov	r1,#_lookV
   259C C3                 5844 	clr	c
   259D E2                 5845 	movx	a,@r0
   259E F5 F0              5846 	mov	b,a
   25A0 E3                 5847 	movx	a,@r1
   25A1 64 80              5848 	xrl	a,#0x80
   25A3 63 F0 80           5849 	xrl	b,#0x80
   25A6 95 F0              5850 	subb	a,b
   25A8 40 03              5851 	jc	00326$
   25AA 02 26 E4           5852 	ljmp	00186$
   25AD                    5853 00326$:
                    19F2   5854 	C$twitch_ax.c$910$6$39 ==.
                           5855 ;	apps/twitch_ax/twitch_ax.c:910: if (walkV > -20) { walkV = -20; }
   25AD 78 3C              5856 	mov	r0,#_walkV
   25AF C3                 5857 	clr	c
   25B0 E2                 5858 	movx	a,@r0
   25B1 F5 F0              5859 	mov	b,a
   25B3 74 6C              5860 	mov	a,#(0xEC ^ 0x80)
   25B5 63 F0 80           5861 	xrl	b,#0x80
   25B8 95 F0              5862 	subb	a,b
   25BA 50 05              5863 	jnc	00170$
   25BC 78 3C              5864 	mov	r0,#_walkV
   25BE 74 EC              5865 	mov	a,#0xEC
   25C0 F2                 5866 	movx	@r0,a
   25C1                    5867 00170$:
                    1A06   5868 	C$twitch_ax.c$912$1$1 ==.
                           5869 ;	apps/twitch_ax/twitch_ax.c:912: speedFactor = (1.0 + (walkV + 20) / ((float) (lookV + 20)) ) / 2.0;
   25C1 C0 06              5870 	push	ar6
   25C3 C0 07              5871 	push	ar7
   25C5 78 3C              5872 	mov	r0,#_walkV
   25C7 E2                 5873 	movx	a,@r0
   25C8 FC                 5874 	mov	r4,a
   25C9 E2                 5875 	movx	a,@r0
   25CA 33                 5876 	rlc	a
   25CB 95 E0              5877 	subb	a,acc
   25CD FD                 5878 	mov	r5,a
   25CE 74 14              5879 	mov	a,#0x14
   25D0 2C                 5880 	add	a,r4
   25D1 FC                 5881 	mov	r4,a
   25D2 E4                 5882 	clr	a
   25D3 3D                 5883 	addc	a,r5
   25D4 FD                 5884 	mov	r5,a
   25D5 78 3E              5885 	mov	r0,#_lookV
   25D7 E2                 5886 	movx	a,@r0
   25D8 FA                 5887 	mov	r2,a
   25D9 E2                 5888 	movx	a,@r0
   25DA 33                 5889 	rlc	a
   25DB 95 E0              5890 	subb	a,acc
   25DD FB                 5891 	mov	r3,a
   25DE 74 14              5892 	mov	a,#0x14
   25E0 2A                 5893 	add	a,r2
   25E1 F5 82              5894 	mov	dpl,a
   25E3 E4                 5895 	clr	a
   25E4 3B                 5896 	addc	a,r3
   25E5 F5 83              5897 	mov	dph,a
   25E7 C0 07              5898 	push	ar7
   25E9 C0 06              5899 	push	ar6
   25EB C0 05              5900 	push	ar5
   25ED C0 04              5901 	push	ar4
   25EF 12 40 FA           5902 	lcall	___sint2fs
   25F2 85 82 68           5903 	mov	_gaitRunnerProcess_sloc10_1_0,dpl
   25F5 85 83 69           5904 	mov	(_gaitRunnerProcess_sloc10_1_0 + 1),dph
   25F8 85 F0 6A           5905 	mov	(_gaitRunnerProcess_sloc10_1_0 + 2),b
   25FB F5 6B              5906 	mov	(_gaitRunnerProcess_sloc10_1_0 + 3),a
   25FD D0 04              5907 	pop	ar4
   25FF D0 05              5908 	pop	ar5
   2601 D0 06              5909 	pop	ar6
   2603 D0 07              5910 	pop	ar7
   2605 8C 82              5911 	mov	dpl,r4
   2607 8D 83              5912 	mov	dph,r5
   2609 12 40 FA           5913 	lcall	___sint2fs
   260C AC 82              5914 	mov	r4,dpl
   260E AD 83              5915 	mov	r5,dph
   2610 AE F0              5916 	mov	r6,b
   2612 FF                 5917 	mov	r7,a
   2613 C0 68              5918 	push	_gaitRunnerProcess_sloc10_1_0
   2615 C0 69              5919 	push	(_gaitRunnerProcess_sloc10_1_0 + 1)
   2617 C0 6A              5920 	push	(_gaitRunnerProcess_sloc10_1_0 + 2)
   2619 C0 6B              5921 	push	(_gaitRunnerProcess_sloc10_1_0 + 3)
   261B 8C 82              5922 	mov	dpl,r4
   261D 8D 83              5923 	mov	dph,r5
   261F 8E F0              5924 	mov	b,r6
   2621 EF                 5925 	mov	a,r7
   2622 12 42 03           5926 	lcall	___fsdiv
   2625 AC 82              5927 	mov	r4,dpl
   2627 AD 83              5928 	mov	r5,dph
   2629 AE F0              5929 	mov	r6,b
   262B FF                 5930 	mov	r7,a
   262C E5 81              5931 	mov	a,sp
   262E 24 FC              5932 	add	a,#0xfc
   2630 F5 81              5933 	mov	sp,a
   2632 E4                 5934 	clr	a
   2633 C0 E0              5935 	push	acc
   2635 C0 E0              5936 	push	acc
   2637 74 80              5937 	mov	a,#0x80
   2639 C0 E0              5938 	push	acc
   263B 74 3F              5939 	mov	a,#0x3F
   263D C0 E0              5940 	push	acc
   263F 8C 82              5941 	mov	dpl,r4
   2641 8D 83              5942 	mov	dph,r5
   2643 8E F0              5943 	mov	b,r6
   2645 EF                 5944 	mov	a,r7
   2646 12 3B EB           5945 	lcall	___fsadd
   2649 AC 82              5946 	mov	r4,dpl
   264B AD 83              5947 	mov	r5,dph
   264D AE F0              5948 	mov	r6,b
   264F FF                 5949 	mov	r7,a
   2650 E5 81              5950 	mov	a,sp
   2652 24 FC              5951 	add	a,#0xfc
   2654 F5 81              5952 	mov	sp,a
   2656 C0 07              5953 	push	ar7
   2658 C0 06              5954 	push	ar6
   265A E4                 5955 	clr	a
   265B C0 E0              5956 	push	acc
   265D C0 E0              5957 	push	acc
   265F C0 E0              5958 	push	acc
   2661 74 40              5959 	mov	a,#0x40
   2663 C0 E0              5960 	push	acc
   2665 8C 82              5961 	mov	dpl,r4
   2667 8D 83              5962 	mov	dph,r5
   2669 8E F0              5963 	mov	b,r6
   266B EF                 5964 	mov	a,r7
   266C 12 42 03           5965 	lcall	___fsdiv
   266F 78 AE              5966 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   2671 C0 E0              5967 	push	acc
   2673 E5 82              5968 	mov	a,dpl
   2675 F2                 5969 	movx	@r0,a
   2676 08                 5970 	inc	r0
   2677 E5 83              5971 	mov	a,dph
   2679 F2                 5972 	movx	@r0,a
   267A 08                 5973 	inc	r0
   267B E5 F0              5974 	mov	a,b
   267D F2                 5975 	movx	@r0,a
   267E D0 E0              5976 	pop	acc
   2680 08                 5977 	inc	r0
   2681 F2                 5978 	movx	@r0,a
   2682 E5 81              5979 	mov	a,sp
   2684 24 FC              5980 	add	a,#0xfc
   2686 F5 81              5981 	mov	sp,a
   2688 D0 06              5982 	pop	ar6
   268A D0 07              5983 	pop	ar7
                    1AD1   5984 	C$twitch_ax.c$914$6$39 ==.
                           5985 ;	apps/twitch_ax/twitch_ax.c:914: speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
   268C 78 AC              5986 	mov	r0,#_gaitRunnerProcess_speed_3_29
   268E E2                 5987 	movx	a,@r0
   268F F5 82              5988 	mov	dpl,a
   2691 08                 5989 	inc	r0
   2692 E2                 5990 	movx	a,@r0
   2693 24 FE              5991 	add	a,#0xFE
   2695 F5 83              5992 	mov	dph,a
   2697 12 40 FA           5993 	lcall	___sint2fs
   269A AC 82              5994 	mov	r4,dpl
   269C AD 83              5995 	mov	r5,dph
   269E AE F0              5996 	mov	r6,b
   26A0 FF                 5997 	mov	r7,a
   26A1 78 AE              5998 	mov	r0,#_gaitRunnerProcess_speedFactor_4_30
   26A3 E2                 5999 	movx	a,@r0
   26A4 C0 E0              6000 	push	acc
   26A6 08                 6001 	inc	r0
   26A7 E2                 6002 	movx	a,@r0
   26A8 C0 E0              6003 	push	acc
   26AA 08                 6004 	inc	r0
   26AB E2                 6005 	movx	a,@r0
   26AC C0 E0              6006 	push	acc
   26AE 08                 6007 	inc	r0
   26AF E2                 6008 	movx	a,@r0
   26B0 C0 E0              6009 	push	acc
   26B2 8C 82              6010 	mov	dpl,r4
   26B4 8D 83              6011 	mov	dph,r5
   26B6 8E F0              6012 	mov	b,r6
   26B8 EF                 6013 	mov	a,r7
   26B9 12 32 50           6014 	lcall	___fsmul
   26BC AC 82              6015 	mov	r4,dpl
   26BE AD 83              6016 	mov	r5,dph
   26C0 AE F0              6017 	mov	r6,b
   26C2 FF                 6018 	mov	r7,a
   26C3 E5 81              6019 	mov	a,sp
   26C5 24 FC              6020 	add	a,#0xfc
   26C7 F5 81              6021 	mov	sp,a
   26C9 8C 82              6022 	mov	dpl,r4
   26CB 8D 83              6023 	mov	dph,r5
   26CD 8E F0              6024 	mov	b,r6
   26CF EF                 6025 	mov	a,r7
   26D0 12 41 07           6026 	lcall	___fs2sint
   26D3 AE 82              6027 	mov	r6,dpl
   26D5 AF 83              6028 	mov	r7,dph
   26D7 78 AC              6029 	mov	r0,#_gaitRunnerProcess_speed_3_29
   26D9 E2                 6030 	movx	a,@r0
   26DA 2E                 6031 	add	a,r6
   26DB F2                 6032 	movx	@r0,a
   26DC 08                 6033 	inc	r0
   26DD E2                 6034 	movx	a,@r0
   26DE 3F                 6035 	addc	a,r7
   26DF F2                 6036 	movx	@r0,a
                    1B25   6037 	C$twitch_ax.c$951$1$1 ==.
                           6038 ;	apps/twitch_ax/twitch_ax.c:951: return gaitRunnerIsPlaying(runner);
   26E0 D0 07              6039 	pop	ar7
   26E2 D0 06              6040 	pop	ar6
                    1B29   6041 	C$twitch_ax.c$914$3$29 ==.
                           6042 ;	apps/twitch_ax/twitch_ax.c:914: speed = speed + (int16)( ((int16)speed - 512) * speedFactor );
   26E4                    6043 00186$:
                    1B29   6044 	C$twitch_ax.c$920$3$29 ==.
                           6045 ;	apps/twitch_ax/twitch_ax.c:920: speeds[3*limbNumber] = servo;
   26E4 8E 05              6046 	mov	ar5,r6
   26E6 ED                 6047 	mov	a,r5
   26E7 75 F0 03           6048 	mov	b,#0x03
   26EA A4                 6049 	mul	ab
   26EB FD                 6050 	mov	r5,a
   26EC 24 A3              6051 	add	a,#_gaitRunnerProcess_speeds_2_28
   26EE F8                 6052 	mov	r0,a
   26EF 79 AB              6053 	mov	r1,#_gaitRunnerProcess_servo_3_29
   26F1 E3                 6054 	movx	a,@r1
   26F2 F2                 6055 	movx	@r0,a
                    1B38   6056 	C$twitch_ax.c$921$3$29 ==.
                           6057 ;	apps/twitch_ax/twitch_ax.c:921: speeds[3*limbNumber+1] = (uint8) dynamixel_getlowbyte(speed);
   26F3 ED                 6058 	mov	a,r5
   26F4 04                 6059 	inc	a
   26F5 24 A3              6060 	add	a,#_gaitRunnerProcess_speeds_2_28
   26F7 F9                 6061 	mov	r1,a
   26F8 78 AC              6062 	mov	r0,#_gaitRunnerProcess_speed_3_29
   26FA E2                 6063 	movx	a,@r0
   26FB FA                 6064 	mov	r2,a
   26FC 08                 6065 	inc	r0
   26FD E2                 6066 	movx	a,@r0
   26FE FC                 6067 	mov	r4,a
   26FF 8A 82              6068 	mov	dpl,r2
   2701 8C 83              6069 	mov	dph,r4
   2703 C0 07              6070 	push	ar7
   2705 C0 06              6071 	push	ar6
   2707 C0 05              6072 	push	ar5
   2709 C0 04              6073 	push	ar4
   270B C0 02              6074 	push	ar2
   270D C0 01              6075 	push	ar1
   270F 12 0A 10           6076 	lcall	_dynamixel_getlowbyte
   2712 E5 82              6077 	mov	a,dpl
   2714 D0 01              6078 	pop	ar1
   2716 D0 02              6079 	pop	ar2
   2718 D0 04              6080 	pop	ar4
   271A D0 05              6081 	pop	ar5
   271C D0 06              6082 	pop	ar6
   271E D0 07              6083 	pop	ar7
   2720 F3                 6084 	movx	@r1,a
                    1B66   6085 	C$twitch_ax.c$922$3$29 ==.
                           6086 ;	apps/twitch_ax/twitch_ax.c:922: speeds[3*limbNumber+2] = (uint8) dynamixel_gethighbyte(speed);
   2721 74 02              6087 	mov	a,#0x02
   2723 2D                 6088 	add	a,r5
   2724 24 A3              6089 	add	a,#_gaitRunnerProcess_speeds_2_28
   2726 F9                 6090 	mov	r1,a
   2727 8A 82              6091 	mov	dpl,r2
   2729 8C 83              6092 	mov	dph,r4
   272B C0 07              6093 	push	ar7
   272D C0 06              6094 	push	ar6
   272F C0 01              6095 	push	ar1
   2731 12 0A 11           6096 	lcall	_dynamixel_gethighbyte
   2734 E5 82              6097 	mov	a,dpl
   2736 D0 01              6098 	pop	ar1
   2738 D0 06              6099 	pop	ar6
   273A D0 07              6100 	pop	ar7
   273C F3                 6101 	movx	@r1,a
                    1B82   6102 	C$twitch_ax.c$865$2$28 ==.
                           6103 ;	apps/twitch_ax/twitch_ax.c:865: for(limbNumber = 0; limbNumber < NUM_ACTUATORS; limbNumber++){
   273D 0E                 6104 	inc	r6
   273E BE 00 01           6105 	cjne	r6,#0x00,00328$
   2741 0F                 6106 	inc	r7
   2742                    6107 00328$:
   2742 02 20 40           6108 	ljmp	00201$
   2745                    6109 00204$:
                    1B8A   6110 	C$twitch_ax.c$925$2$28 ==.
                           6111 ;	apps/twitch_ax/twitch_ax.c:925: dynamixel_syncwrite(AX_GOAL_POSITION_L, 2, 3, speeds);
   2745 78 1E              6112 	mov	r0,#_dynamixel_syncwrite_PARM_4
   2747 74 A3              6113 	mov	a,#_gaitRunnerProcess_speeds_2_28
   2749 F2                 6114 	movx	@r0,a
   274A 08                 6115 	inc	r0
   274B E4                 6116 	clr	a
   274C F2                 6117 	movx	@r0,a
   274D 08                 6118 	inc	r0
   274E 74 60              6119 	mov	a,#0x60
   2750 F2                 6120 	movx	@r0,a
   2751 78 1C              6121 	mov	r0,#_dynamixel_syncwrite_PARM_2
   2753 74 02              6122 	mov	a,#0x02
   2755 F2                 6123 	movx	@r0,a
   2756 78 1D              6124 	mov	r0,#_dynamixel_syncwrite_PARM_3
   2758 74 03              6125 	mov	a,#0x03
   275A F2                 6126 	movx	@r0,a
   275B 75 82 1E           6127 	mov	dpl,#0x1E
   275E 12 08 DD           6128 	lcall	_dynamixel_syncwrite
                    1BA6   6129 	C$twitch_ax.c$931$1$1 ==.
                           6130 ;	apps/twitch_ax/twitch_ax.c:931: if( pgm_read_byte(&animation->sweep) == 2) {
   2761 78 87              6131 	mov	r0,#_gaitRunnerProcess_animation_1_1
   2763 E2                 6132 	movx	a,@r0
   2764 24 04              6133 	add	a,#0x04
   2766 FD                 6134 	mov	r5,a
   2767 08                 6135 	inc	r0
   2768 E2                 6136 	movx	a,@r0
   2769 34 00              6137 	addc	a,#0x00
   276B FE                 6138 	mov	r6,a
   276C 08                 6139 	inc	r0
   276D E2                 6140 	movx	a,@r0
   276E FF                 6141 	mov	r7,a
   276F 8D 82              6142 	mov	dpl,r5
   2771 8E 83              6143 	mov	dph,r6
   2773 8F F0              6144 	mov	b,r7
   2775 12 42 C6           6145 	lcall	__gptrget
   2778 FD                 6146 	mov	r5,a
   2779 BD 02 50           6147 	cjne	r5,#0x02,00196$
                    1BC1   6148 	C$twitch_ax.c$932$2$41 ==.
                           6149 ;	apps/twitch_ax/twitch_ax.c:932: if( currentTime == runner->totalTime || currentTime == 0) {
   277C 85 55 82           6150 	mov	dpl,_gaitRunnerProcess_sloc3_1_0
   277F 85 56 83           6151 	mov	dph,(_gaitRunnerProcess_sloc3_1_0 + 1)
   2782 85 57 F0           6152 	mov	b,(_gaitRunnerProcess_sloc3_1_0 + 2)
   2785 12 42 C6           6153 	lcall	__gptrget
   2788 FE                 6154 	mov	r6,a
   2789 A3                 6155 	inc	dptr
   278A 12 42 C6           6156 	lcall	__gptrget
   278D FF                 6157 	mov	r7,a
   278E 78 8A              6158 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   2790 E2                 6159 	movx	a,@r0
   2791 B5 06 07           6160 	cjne	a,ar6,00331$
   2794 08                 6161 	inc	r0
   2795 E2                 6162 	movx	a,@r0
   2796 B5 07 02           6163 	cjne	a,ar7,00331$
   2799 80 0B              6164 	sjmp	00192$
   279B                    6165 00331$:
   279B 78 8A              6166 	mov	r0,#_gaitRunnerProcess_currentTime_1_1
   279D E2                 6167 	movx	a,@r0
   279E F5 F0              6168 	mov	b,a
   27A0 08                 6169 	inc	r0
   27A1 E2                 6170 	movx	a,@r0
   27A2 45 F0              6171 	orl	a,b
   27A4 70 26              6172 	jnz	00196$
   27A6                    6173 00192$:
                    1BEB   6174 	C$twitch_ax.c$937$3$42 ==.
                           6175 ;	apps/twitch_ax/twitch_ax.c:937: runner->playing = FALSE;			// we have reached the end
   27A6 78 7E              6176 	mov	r0,#_gaitRunnerProcess_runner_1_1
   27A8 E2                 6177 	movx	a,@r0
   27A9 24 06              6178 	add	a,#0x06
   27AB FD                 6179 	mov	r5,a
   27AC 08                 6180 	inc	r0
   27AD E2                 6181 	movx	a,@r0
   27AE 34 00              6182 	addc	a,#0x00
   27B0 FE                 6183 	mov	r6,a
   27B1 08                 6184 	inc	r0
   27B2 E2                 6185 	movx	a,@r0
   27B3 FF                 6186 	mov	r7,a
   27B4 8D 82              6187 	mov	dpl,r5
   27B6 8E 83              6188 	mov	dph,r6
   27B8 8F F0              6189 	mov	b,r7
   27BA E4                 6190 	clr	a
   27BB 12 36 56           6191 	lcall	__gptrput
                    1C03   6192 	C$twitch_ax.c$938$3$42 ==.
                           6193 ;	apps/twitch_ax/twitch_ax.c:938: runner->animation = NO_GAIT;
   27BE 85 61 82           6194 	mov	dpl,_gaitRunnerProcess_sloc8_1_0
   27C1 85 62 83           6195 	mov	dph,(_gaitRunnerProcess_sloc8_1_0 + 1)
   27C4 85 63 F0           6196 	mov	b,(_gaitRunnerProcess_sloc8_1_0 + 2)
   27C7 74 64              6197 	mov	a,#0x64
   27C9 12 36 56           6198 	lcall	__gptrput
   27CC                    6199 00196$:
                    1C11   6200 	C$twitch_ax.c$951$1$1 ==.
                           6201 ;	apps/twitch_ax/twitch_ax.c:951: return gaitRunnerIsPlaying(runner);
   27CC 78 7E              6202 	mov	r0,#_gaitRunnerProcess_runner_1_1
   27CE E2                 6203 	movx	a,@r0
   27CF F5 82              6204 	mov	dpl,a
   27D1 08                 6205 	inc	r0
   27D2 E2                 6206 	movx	a,@r0
   27D3 F5 83              6207 	mov	dph,a
   27D5 08                 6208 	inc	r0
   27D6 E2                 6209 	movx	a,@r0
   27D7 F5 F0              6210 	mov	b,a
   27D9 12 0B EF           6211 	lcall	_gaitRunnerIsPlaying
   27DC                    6212 00205$:
                    1C21   6213 	C$twitch_ax.c$952$1$1 ==.
                    1C21   6214 	XG$gaitRunnerProcess$0$0 ==.
   27DC 22                 6215 	ret
                           6216 ;------------------------------------------------------------
                           6217 ;Allocation info for local variables in function 'main'
                           6218 ;------------------------------------------------------------
                    1C22   6219 	G$main$0$0 ==.
                    1C22   6220 	C$twitch_ax.c$982$1$1 ==.
                           6221 ;	apps/twitch_ax/twitch_ax.c:982: void main()
                           6222 ;	-----------------------------------------
                           6223 ;	 function main
                           6224 ;	-----------------------------------------
   27DD                    6225 _main:
                    1C22   6226 	C$twitch_ax.c$988$1$1 ==.
                           6227 ;	apps/twitch_ax/twitch_ax.c:988: int8 desiredGait = NO_GAIT;
   27DD 78 B2              6228 	mov	r0,#_main_desiredGait_1_1
   27DF 74 64              6229 	mov	a,#0x64
   27E1 F2                 6230 	movx	@r0,a
                    1C27   6231 	C$twitch_ax.c$1013$1$1 ==.
                           6232 ;	apps/twitch_ax/twitch_ax.c:1013: G8_RUNNER gait = MAKE_G8_RUNNER(animations);
   27E2 78 B5              6233 	mov	r0,#_main_gait_1_1
   27E4 74 F9              6234 	mov	a,#_animations
   27E6 F2                 6235 	movx	@r0,a
   27E7 08                 6236 	inc	r0
   27E8 74 4B              6237 	mov	a,#(_animations >> 8)
   27EA F2                 6238 	movx	@r0,a
   27EB 08                 6239 	inc	r0
   27EC 74 80              6240 	mov	a,#0x80
   27EE F2                 6241 	movx	@r0,a
   27EF 78 B8              6242 	mov	r0,#(_main_gait_1_1 + 0x0003)
   27F1 E4                 6243 	clr	a
   27F2 F2                 6244 	movx	@r0,a
   27F3 78 B9              6245 	mov	r0,#(_main_gait_1_1 + 0x0004)
   27F5 E4                 6246 	clr	a
   27F6 F2                 6247 	movx	@r0,a
   27F7 78 BA              6248 	mov	r0,#(_main_gait_1_1 + 0x0005)
   27F9 E4                 6249 	clr	a
   27FA F2                 6250 	movx	@r0,a
   27FB 78 BB              6251 	mov	r0,#(_main_gait_1_1 + 0x0006)
   27FD E4                 6252 	clr	a
   27FE F2                 6253 	movx	@r0,a
   27FF 78 BC              6254 	mov	r0,#(_main_gait_1_1 + 0x0007)
   2801 E4                 6255 	clr	a
   2802 F2                 6256 	movx	@r0,a
   2803 08                 6257 	inc	r0
   2804 F2                 6258 	movx	@r0,a
   2805 08                 6259 	inc	r0
   2806 F2                 6260 	movx	@r0,a
   2807 08                 6261 	inc	r0
   2808 F2                 6262 	movx	@r0,a
   2809 78 C0              6263 	mov	r0,#(_main_gait_1_1 + 0x000b)
   280B E4                 6264 	clr	a
   280C F2                 6265 	movx	@r0,a
   280D 08                 6266 	inc	r0
   280E F2                 6267 	movx	@r0,a
   280F 78 C2              6268 	mov	r0,#(_main_gait_1_1 + 0x000d)
   2811 E4                 6269 	clr	a
   2812 F2                 6270 	movx	@r0,a
   2813 08                 6271 	inc	r0
   2814 F2                 6272 	movx	@r0,a
   2815 78 C4              6273 	mov	r0,#(_main_gait_1_1 + 0x000f)
   2817 E4                 6274 	clr	a
   2818 F2                 6275 	movx	@r0,a
   2819 78 C5              6276 	mov	r0,#(_main_gait_1_1 + 0x0010)
   281B E4                 6277 	clr	a
   281C F2                 6278 	movx	@r0,a
   281D 78 C6              6279 	mov	r0,#(_main_gait_1_1 + 0x0011)
   281F E4                 6280 	clr	a
   2820 F2                 6281 	movx	@r0,a
   2821 08                 6282 	inc	r0
   2822 F2                 6283 	movx	@r0,a
   2823 08                 6284 	inc	r0
   2824 F2                 6285 	movx	@r0,a
                    1C6A   6286 	C$twitch_ax.c$1017$1$1 ==.
                           6287 ;	apps/twitch_ax/twitch_ax.c:1017: systemInit();
   2825 12 38 27           6288 	lcall	_systemInit
                    1C6D   6289 	C$twitch_ax.c$1020$1$1 ==.
                           6290 ;	apps/twitch_ax/twitch_ax.c:1020: dynamixel_init();
   2828 12 05 55           6291 	lcall	_dynamixel_init
                    1C70   6292 	C$twitch_ax.c$1022$1$1 ==.
                           6293 ;	apps/twitch_ax/twitch_ax.c:1022: setDigitalOutput(param_arduino_DTR_pin, LOW);
   282B 90 4C 44           6294 	mov	dptr,#_param_arduino_DTR_pin
   282E E4                 6295 	clr	a
   282F 93                 6296 	movc	a,@a+dptr
   2830 FC                 6297 	mov	r4,a
   2831 74 01              6298 	mov	a,#0x01
   2833 93                 6299 	movc	a,@a+dptr
   2834 74 02              6300 	mov	a,#0x02
   2836 93                 6301 	movc	a,@a+dptr
   2837 74 03              6302 	mov	a,#0x03
   2839 93                 6303 	movc	a,@a+dptr
   283A 8C 82              6304 	mov	dpl,r4
   283C C2 F0              6305 	clr	b[0]
   283E 85 F0 23           6306 	mov	bits,b
   2841 12 3C 44           6307 	lcall	_setDigitalOutput
                    1C89   6308 	C$twitch_ax.c$1023$1$1 ==.
                           6309 ;	apps/twitch_ax/twitch_ax.c:1023: ioTxSignals(0);
   2844 75 82 00           6310 	mov	dpl,#0x00
   2847 12 0D 4A           6311 	lcall	_ioTxSignals
                    1C8F   6312 	C$twitch_ax.c$1026$1$1 ==.
                           6313 ;	apps/twitch_ax/twitch_ax.c:1026: uart1Init();
   284A 12 2A 8A           6314 	lcall	_uart1Init
                    1C92   6315 	C$twitch_ax.c$1027$1$1 ==.
                           6316 ;	apps/twitch_ax/twitch_ax.c:1027: uart1SetBaudRate(param_baud_rate);
   284D 90 4C 20           6317 	mov	dptr,#_param_baud_rate
   2850 E4                 6318 	clr	a
   2851 93                 6319 	movc	a,@a+dptr
   2852 FC                 6320 	mov	r4,a
   2853 74 01              6321 	mov	a,#0x01
   2855 93                 6322 	movc	a,@a+dptr
   2856 FD                 6323 	mov	r5,a
   2857 74 02              6324 	mov	a,#0x02
   2859 93                 6325 	movc	a,@a+dptr
   285A FE                 6326 	mov	r6,a
   285B 74 03              6327 	mov	a,#0x03
   285D 93                 6328 	movc	a,@a+dptr
   285E 8C 82              6329 	mov	dpl,r4
   2860 8D 83              6330 	mov	dph,r5
   2862 8E F0              6331 	mov	b,r6
   2864 12 2A BE           6332 	lcall	_uart1SetBaudRate
                    1CAC   6333 	C$twitch_ax.c$1028$1$1 ==.
                           6334 ;	apps/twitch_ax/twitch_ax.c:1028: index_cmdr = -1;
   2867 78 3A              6335 	mov	r0,#_index_cmdr
   2869 74 FF              6336 	mov	a,#0xFF
   286B F2                 6337 	movx	@r0,a
                    1CB1   6338 	C$twitch_ax.c$1030$1$1 ==.
                           6339 ;	apps/twitch_ax/twitch_ax.c:1030: if (param_serial_mode != SERIAL_MODE_USB_UART)
   286C 90 4C 1C           6340 	mov	dptr,#_param_serial_mode
   286F E4                 6341 	clr	a
   2870 93                 6342 	movc	a,@a+dptr
   2871 FC                 6343 	mov	r4,a
   2872 74 01              6344 	mov	a,#0x01
   2874 93                 6345 	movc	a,@a+dptr
   2875 FD                 6346 	mov	r5,a
   2876 74 02              6347 	mov	a,#0x02
   2878 93                 6348 	movc	a,@a+dptr
   2879 FE                 6349 	mov	r6,a
   287A 74 03              6350 	mov	a,#0x03
   287C 93                 6351 	movc	a,@a+dptr
   287D FF                 6352 	mov	r7,a
   287E BC 03 0B           6353 	cjne	r4,#0x03,00158$
   2881 BD 00 08           6354 	cjne	r5,#0x00,00158$
   2884 BE 00 05           6355 	cjne	r6,#0x00,00158$
   2887 BF 00 02           6356 	cjne	r7,#0x00,00158$
   288A 80 05              6357 	sjmp	00102$
   288C                    6358 00158$:
                    1CD1   6359 	C$twitch_ax.c$1032$2$2 ==.
                           6360 ;	apps/twitch_ax/twitch_ax.c:1032: radioComRxEnforceOrdering = 1;
   288C D2 13              6361 	setb	_radioComRxEnforceOrdering
                    1CD3   6362 	C$twitch_ax.c$1033$2$2 ==.
                           6363 ;	apps/twitch_ax/twitch_ax.c:1033: radioComInit();
   288E 12 34 FD           6364 	lcall	_radioComInit
   2891                    6365 00102$:
                    1CD6   6366 	C$twitch_ax.c$1037$1$1 ==.
                           6367 ;	apps/twitch_ax/twitch_ax.c:1037: gaitRunnerInit(&gait);
   2891 90 F0 B5           6368 	mov	dptr,#_main_gait_1_1
   2894 75 F0 60           6369 	mov	b,#0x60
   2897 12 13 20           6370 	lcall	_gaitRunnerInit
                    1CDF   6371 	C$twitch_ax.c$1039$1$1 ==.
                           6372 ;	apps/twitch_ax/twitch_ax.c:1039: gait.animation = NO_GAIT;
   289A 78 B8              6373 	mov	r0,#(_main_gait_1_1 + 0x0003)
   289C 74 64              6374 	mov	a,#0x64
   289E F2                 6375 	movx	@r0,a
                    1CE4   6376 	C$twitch_ax.c$1063$1$1 ==.
                           6377 ;	apps/twitch_ax/twitch_ax.c:1063: gaitRunnerPlay(&gait,    G8_ANIM_START,       g8loopSpeed, START_SPEED, 1);
   289F 90 4C 4C           6378 	mov	dptr,#_g8loopSpeed
   28A2 E4                 6379 	clr	a
   28A3 93                 6380 	movc	a,@a+dptr
   28A4 FE                 6381 	mov	r6,a
   28A5 74 01              6382 	mov	a,#0x01
   28A7 93                 6383 	movc	a,@a+dptr
   28A8 FF                 6384 	mov	r7,a
   28A9 78 53              6385 	mov	r0,#_gaitRunnerPlay_PARM_3
   28AB EE                 6386 	mov	a,r6
   28AC F2                 6387 	movx	@r0,a
   28AD 08                 6388 	inc	r0
   28AE EF                 6389 	mov	a,r7
   28AF F2                 6390 	movx	@r0,a
   28B0 78 52              6391 	mov	r0,#_gaitRunnerPlay_PARM_2
   28B2 74 01              6392 	mov	a,#0x01
   28B4 F2                 6393 	movx	@r0,a
   28B5 78 55              6394 	mov	r0,#_gaitRunnerPlay_PARM_4
   28B7 74 4B              6395 	mov	a,#0x4B
   28B9 F2                 6396 	movx	@r0,a
   28BA 78 56              6397 	mov	r0,#_gaitRunnerPlay_PARM_5
   28BC 74 01              6398 	mov	a,#0x01
   28BE F2                 6399 	movx	@r0,a
   28BF 90 F0 B5           6400 	mov	dptr,#_main_gait_1_1
   28C2 75 F0 60           6401 	mov	b,#0x60
   28C5 12 13 A0           6402 	lcall	_gaitRunnerPlay
                    1D0D   6403 	C$twitch_ax.c$1067$1$1 ==.
                           6404 ;	apps/twitch_ax/twitch_ax.c:1067: while(1)
   28C8                    6405 00139$:
                    1D0D   6406 	C$twitch_ax.c$1071$2$3 ==.
                           6407 ;	apps/twitch_ax/twitch_ax.c:1071: boardService();
   28C8 12 38 34           6408 	lcall	_boardService
                    1D10   6409 	C$twitch_ax.c$1072$2$3 ==.
                           6410 ;	apps/twitch_ax/twitch_ax.c:1072: updateLeds();
   28CB 12 0C 08           6411 	lcall	_updateLeds
                    1D13   6412 	C$twitch_ax.c$1073$2$3 ==.
                           6413 ;	apps/twitch_ax/twitch_ax.c:1073: errorService();
   28CE 12 0E 6F           6414 	lcall	_errorService
                    1D16   6415 	C$twitch_ax.c$1075$2$3 ==.
                           6416 ;	apps/twitch_ax/twitch_ax.c:1075: if (param_serial_mode != SERIAL_MODE_USB_UART)
   28D1 90 4C 1C           6417 	mov	dptr,#_param_serial_mode
   28D4 E4                 6418 	clr	a
   28D5 93                 6419 	movc	a,@a+dptr
   28D6 FC                 6420 	mov	r4,a
   28D7 74 01              6421 	mov	a,#0x01
   28D9 93                 6422 	movc	a,@a+dptr
   28DA FD                 6423 	mov	r5,a
   28DB 74 02              6424 	mov	a,#0x02
   28DD 93                 6425 	movc	a,@a+dptr
   28DE FE                 6426 	mov	r6,a
   28DF 74 03              6427 	mov	a,#0x03
   28E1 93                 6428 	movc	a,@a+dptr
   28E2 FF                 6429 	mov	r7,a
   28E3 BC 03 0B           6430 	cjne	r4,#0x03,00159$
   28E6 BD 00 08           6431 	cjne	r5,#0x00,00159$
   28E9 BE 00 05           6432 	cjne	r6,#0x00,00159$
   28EC BF 00 02           6433 	cjne	r7,#0x00,00159$
   28EF 80 03              6434 	sjmp	00104$
   28F1                    6435 00159$:
                    1D36   6436 	C$twitch_ax.c$1077$3$4 ==.
                           6437 ;	apps/twitch_ax/twitch_ax.c:1077: radioComTxService();
   28F1 12 35 C8           6438 	lcall	_radioComTxService
   28F4                    6439 00104$:
                    1D39   6440 	C$twitch_ax.c$1088$3$5 ==.
                           6441 ;	apps/twitch_ax/twitch_ax.c:1088: CmdrReadMsgs(&desiredGait, &desiredDir, &desiredSpeed);
   28F4 78 4C              6442 	mov	r0,#_CmdrReadMsgs_PARM_2
   28F6 74 B3              6443 	mov	a,#_main_desiredDir_1_1
   28F8 F2                 6444 	movx	@r0,a
   28F9 08                 6445 	inc	r0
   28FA E4                 6446 	clr	a
   28FB F2                 6447 	movx	@r0,a
   28FC 08                 6448 	inc	r0
   28FD 74 60              6449 	mov	a,#0x60
   28FF F2                 6450 	movx	@r0,a
   2900 78 4F              6451 	mov	r0,#_CmdrReadMsgs_PARM_3
   2902 74 B4              6452 	mov	a,#_main_desiredSpeed_1_1
   2904 F2                 6453 	movx	@r0,a
   2905 08                 6454 	inc	r0
   2906 E4                 6455 	clr	a
   2907 F2                 6456 	movx	@r0,a
   2908 08                 6457 	inc	r0
   2909 74 60              6458 	mov	a,#0x60
   290B F2                 6459 	movx	@r0,a
   290C 90 F0 B2           6460 	mov	dptr,#_main_desiredGait_1_1
   290F 75 F0 60           6461 	mov	b,#0x60
   2912 12 0F 56           6462 	lcall	_CmdrReadMsgs
                    1D5A   6463 	C$twitch_ax.c$1096$3$5 ==.
                           6464 ;	apps/twitch_ax/twitch_ax.c:1096: currentGait = gait.animation;
   2915 78 B8              6465 	mov	r0,#(_main_gait_1_1 + 0x0003)
   2917 E2                 6466 	movx	a,@r0
   2918 FF                 6467 	mov	r7,a
                    1D5E   6468 	C$twitch_ax.c$1098$3$5 ==.
                           6469 ;	apps/twitch_ax/twitch_ax.c:1098: currentSpeed = gait.speed;
   2919 78 C5              6470 	mov	r0,#(_main_gait_1_1 + 0x0010)
   291B E2                 6471 	movx	a,@r0
   291C FE                 6472 	mov	r6,a
                    1D62   6473 	C$twitch_ax.c$1112$3$5 ==.
                           6474 ;	apps/twitch_ax/twitch_ax.c:1112: if (desiredGait != NO_GAIT) {
   291D 78 B2              6475 	mov	r0,#_main_desiredGait_1_1
   291F E2                 6476 	movx	a,@r0
   2920 B4 64 03           6477 	cjne	a,#0x64,00160$
   2923 02 2A 08           6478 	ljmp	00136$
   2926                    6479 00160$:
                    1D6B   6480 	C$twitch_ax.c$1114$4$6 ==.
                           6481 ;	apps/twitch_ax/twitch_ax.c:1114: if ( currentGait == desiredGait) {
   2926 78 B2              6482 	mov	r0,#_main_desiredGait_1_1
   2928 E2                 6483 	movx	a,@r0
   2929 B5 07 12           6484 	cjne	a,ar7,00123$
                    1D71   6485 	C$twitch_ax.c$1115$5$7 ==.
                           6486 ;	apps/twitch_ax/twitch_ax.c:1115: if (currentSpeed == desiredSpeed) {
   292C 78 B4              6487 	mov	r0,#_main_desiredSpeed_1_1
   292E E2                 6488 	movx	a,@r0
   292F B5 06 03           6489 	cjne	a,ar6,00163$
   2932 02 2A 77           6490 	ljmp	00137$
   2935                    6491 00163$:
                    1D7A   6492 	C$twitch_ax.c$1119$6$9 ==.
                           6493 ;	apps/twitch_ax/twitch_ax.c:1119: gait.speed = desiredSpeed;
   2935 78 C5              6494 	mov	r0,#(_main_gait_1_1 + 0x0010)
   2937 79 B4              6495 	mov	r1,#_main_desiredSpeed_1_1
   2939 E3                 6496 	movx	a,@r1
   293A F2                 6497 	movx	@r0,a
   293B 02 2A 77           6498 	ljmp	00137$
   293E                    6499 00123$:
                    1D83   6500 	C$twitch_ax.c$1121$4$6 ==.
                           6501 ;	apps/twitch_ax/twitch_ax.c:1121: } else if (currentGait == G8_ANIM_START) {
   293E BF 01 24           6502 	cjne	r7,#0x01,00120$
                    1D86   6503 	C$twitch_ax.c$1123$5$10 ==.
                           6504 ;	apps/twitch_ax/twitch_ax.c:1123: if (currentSpeed > 0) {
   2941 C3                 6505 	clr	c
   2942 E4                 6506 	clr	a
   2943 64 80              6507 	xrl	a,#0x80
   2945 8E F0              6508 	mov	b,r6
   2947 63 F0 80           6509 	xrl	b,#0x80
   294A 95 F0              6510 	subb	a,b
   294C 50 03              6511 	jnc	00166$
   294E 02 2A 77           6512 	ljmp	00137$
   2951                    6513 00166$:
                    1D96   6514 	C$twitch_ax.c$1127$5$10 ==.
                           6515 ;	apps/twitch_ax/twitch_ax.c:1127: } else if (currentSpeed < 0) {
   2951 EE                 6516 	mov	a,r6
   2952 20 E7 03           6517 	jb	acc.7,00167$
   2955 02 2A 77           6518 	ljmp	00137$
   2958                    6519 00167$:
                    1D9D   6520 	C$twitch_ax.c$1131$6$12 ==.
                           6521 ;	apps/twitch_ax/twitch_ax.c:1131: gait.speed = START_SPEED;
   2958 78 C5              6522 	mov	r0,#(_main_gait_1_1 + 0x0010)
   295A 74 4B              6523 	mov	a,#0x4B
   295C F2                 6524 	movx	@r0,a
                    1DA2   6525 	C$twitch_ax.c$1132$6$12 ==.
                           6526 ;	apps/twitch_ax/twitch_ax.c:1132: currentPos = START_POS;
   295D 78 45              6527 	mov	r0,#_currentPos
   295F 74 64              6528 	mov	a,#0x64
   2961 F2                 6529 	movx	@r0,a
   2962 02 2A 77           6530 	ljmp	00137$
   2965                    6531 00120$:
                    1DAA   6532 	C$twitch_ax.c$1136$4$6 ==.
                           6533 ;	apps/twitch_ax/twitch_ax.c:1136: } else if (currentGait != NO_GAIT /* & != G8_ANIM_START*/) { //Some other gait is running. Wait til it ends.
   2965 BF 64 02           6534 	cjne	r7,#0x64,00168$
   2968 80 11              6535 	sjmp	00117$
   296A                    6536 00168$:
                    1DAF   6537 	C$twitch_ax.c$1138$5$13 ==.
                           6538 ;	apps/twitch_ax/twitch_ax.c:1138: gaitRunnerStop(&gait);				//4
   296A 90 F0 B5           6539 	mov	dptr,#_main_gait_1_1
   296D 75 F0 60           6540 	mov	b,#0x60
   2970 12 0B BB           6541 	lcall	_gaitRunnerStop
                    1DB8   6542 	C$twitch_ax.c$1139$5$13 ==.
                           6543 ;	apps/twitch_ax/twitch_ax.c:1139: currentPos = START_POS;
   2973 78 45              6544 	mov	r0,#_currentPos
   2975 74 64              6545 	mov	a,#0x64
   2977 F2                 6546 	movx	@r0,a
   2978 02 2A 77           6547 	ljmp	00137$
   297B                    6548 00117$:
                    1DC0   6549 	C$twitch_ax.c$1141$4$6 ==.
                           6550 ;	apps/twitch_ax/twitch_ax.c:1141: } else if (currentPos == SIT_POS) { //No other gait is running, and currently in sit pos. Run START animation.
   297B 78 45              6551 	mov	r0,#_currentPos
   297D E2                 6552 	movx	a,@r0
   297E B4 65 3E           6553 	cjne	a,#0x65,00114$
                    1DC6   6554 	C$twitch_ax.c$1143$5$14 ==.
                           6555 ;	apps/twitch_ax/twitch_ax.c:1143: g8playbackDir = 1;				//6
   2981 78 43              6556 	mov	r0,#_g8playbackDir
   2983 74 01              6557 	mov	a,#0x01
   2985 F2                 6558 	movx	@r0,a
                    1DCB   6559 	C$twitch_ax.c$1144$5$14 ==.
                           6560 ;	apps/twitch_ax/twitch_ax.c:1144: g8speed = START_SPEED; //unnecessary?
   2986 78 41              6561 	mov	r0,#_g8speed
   2988 74 4B              6562 	mov	a,#0x4B
   298A F2                 6563 	movx	@r0,a
   298B 08                 6564 	inc	r0
   298C E4                 6565 	clr	a
   298D F2                 6566 	movx	@r0,a
                    1DD3   6567 	C$twitch_ax.c$1145$5$14 ==.
                           6568 ;	apps/twitch_ax/twitch_ax.c:1145: gaitRunnerPlay(&gait, G8_ANIM_START, g8loopSpeed, g8playbackDir*g8speed, g8playbackDir * 1);
   298E 90 4C 4C           6569 	mov	dptr,#_g8loopSpeed
   2991 E4                 6570 	clr	a
   2992 93                 6571 	movc	a,@a+dptr
   2993 FC                 6572 	mov	r4,a
   2994 74 01              6573 	mov	a,#0x01
   2996 93                 6574 	movc	a,@a+dptr
   2997 FD                 6575 	mov	r5,a
   2998 78 53              6576 	mov	r0,#_gaitRunnerPlay_PARM_3
   299A EC                 6577 	mov	a,r4
   299B F2                 6578 	movx	@r0,a
   299C 08                 6579 	inc	r0
   299D ED                 6580 	mov	a,r5
   299E F2                 6581 	movx	@r0,a
   299F 78 52              6582 	mov	r0,#_gaitRunnerPlay_PARM_2
   29A1 74 01              6583 	mov	a,#0x01
   29A3 F2                 6584 	movx	@r0,a
   29A4 78 55              6585 	mov	r0,#_gaitRunnerPlay_PARM_4
   29A6 74 4B              6586 	mov	a,#0x4B
   29A8 F2                 6587 	movx	@r0,a
   29A9 78 56              6588 	mov	r0,#_gaitRunnerPlay_PARM_5
   29AB 74 01              6589 	mov	a,#0x01
   29AD F2                 6590 	movx	@r0,a
   29AE 90 F0 B5           6591 	mov	dptr,#_main_gait_1_1
   29B1 75 F0 60           6592 	mov	b,#0x60
   29B4 12 13 A0           6593 	lcall	_gaitRunnerPlay
                    1DFC   6594 	C$twitch_ax.c$1146$5$14 ==.
                           6595 ;	apps/twitch_ax/twitch_ax.c:1146: currentPos = START_POS;
   29B7 78 45              6596 	mov	r0,#_currentPos
   29B9 74 64              6597 	mov	a,#0x64
   29BB F2                 6598 	movx	@r0,a
   29BC 02 2A 77           6599 	ljmp	00137$
   29BF                    6600 00114$:
                    1E04   6601 	C$twitch_ax.c$1149$5$15 ==.
                           6602 ;	apps/twitch_ax/twitch_ax.c:1149: g8speed = desiredSpeed;			//5
   29BF 78 B4              6603 	mov	r0,#_main_desiredSpeed_1_1
   29C1 E2                 6604 	movx	a,@r0
   29C2 FC                 6605 	mov	r4,a
   29C3 E2                 6606 	movx	a,@r0
   29C4 33                 6607 	rlc	a
   29C5 95 E0              6608 	subb	a,acc
   29C7 FD                 6609 	mov	r5,a
   29C8 78 41              6610 	mov	r0,#_g8speed
   29CA EC                 6611 	mov	a,r4
   29CB F2                 6612 	movx	@r0,a
   29CC 08                 6613 	inc	r0
   29CD ED                 6614 	mov	a,r5
   29CE F2                 6615 	movx	@r0,a
                    1E14   6616 	C$twitch_ax.c$1150$5$15 ==.
                           6617 ;	apps/twitch_ax/twitch_ax.c:1150: g8playbackDir = desiredDir;
   29CF 78 B3              6618 	mov	r0,#_main_desiredDir_1_1
   29D1 E2                 6619 	movx	a,@r0
   29D2 FF                 6620 	mov	r7,a
   29D3 78 43              6621 	mov	r0,#_g8playbackDir
   29D5 F2                 6622 	movx	@r0,a
                    1E1B   6623 	C$twitch_ax.c$1152$5$15 ==.
                           6624 ;	apps/twitch_ax/twitch_ax.c:1152: gaitRunnerPlay(&gait, desiredGait, g8loopSpeed, g8playbackDir*g8speed, 0);
   29D6 78 B2              6625 	mov	r0,#_main_desiredGait_1_1
   29D8 79 52              6626 	mov	r1,#_gaitRunnerPlay_PARM_2
   29DA E2                 6627 	movx	a,@r0
   29DB F3                 6628 	movx	@r1,a
   29DC 90 4C 4C           6629 	mov	dptr,#_g8loopSpeed
   29DF E4                 6630 	clr	a
   29E0 93                 6631 	movc	a,@a+dptr
   29E1 FA                 6632 	mov	r2,a
   29E2 74 01              6633 	mov	a,#0x01
   29E4 93                 6634 	movc	a,@a+dptr
   29E5 FB                 6635 	mov	r3,a
   29E6 78 53              6636 	mov	r0,#_gaitRunnerPlay_PARM_3
   29E8 EA                 6637 	mov	a,r2
   29E9 F2                 6638 	movx	@r0,a
   29EA 08                 6639 	inc	r0
   29EB EB                 6640 	mov	a,r3
   29EC F2                 6641 	movx	@r0,a
   29ED 8C F0              6642 	mov	b,r4
   29EF EF                 6643 	mov	a,r7
   29F0 A4                 6644 	mul	ab
   29F1 78 55              6645 	mov	r0,#_gaitRunnerPlay_PARM_4
   29F3 F2                 6646 	movx	@r0,a
   29F4 78 56              6647 	mov	r0,#_gaitRunnerPlay_PARM_5
   29F6 E4                 6648 	clr	a
   29F7 F2                 6649 	movx	@r0,a
   29F8 90 F0 B5           6650 	mov	dptr,#_main_gait_1_1
   29FB 75 F0 60           6651 	mov	b,#0x60
   29FE 12 13 A0           6652 	lcall	_gaitRunnerPlay
                    1E46   6653 	C$twitch_ax.c$1153$5$15 ==.
                           6654 ;	apps/twitch_ax/twitch_ax.c:1153: currentPos = MOVING_POS;	// This should be the only way a moving gait gets started...
   2A01 78 45              6655 	mov	r0,#_currentPos
   2A03 74 66              6656 	mov	a,#0x66
   2A05 F2                 6657 	movx	@r0,a
   2A06 80 6F              6658 	sjmp	00137$
   2A08                    6659 00136$:
                    1E4D   6660 	C$twitch_ax.c$1159$4$16 ==.
                           6661 ;	apps/twitch_ax/twitch_ax.c:1159: if (currentGait != NO_GAIT) {// If moving...
   2A08 BF 64 02           6662 	cjne	r7,#0x64,00171$
   2A0B 80 2E              6663 	sjmp	00133$
   2A0D                    6664 00171$:
                    1E52   6665 	C$twitch_ax.c$1160$5$17 ==.
                           6666 ;	apps/twitch_ax/twitch_ax.c:1160: if (currentGait == G8_ANIM_START) { //If doing start gait...
   2A0D BF 01 1B           6667 	cjne	r7,#0x01,00128$
                    1E55   6668 	C$twitch_ax.c$1162$6$18 ==.
                           6669 ;	apps/twitch_ax/twitch_ax.c:1162: if (currentSpeed > 0) { //And going to start position
   2A10 C3                 6670 	clr	c
   2A11 E4                 6671 	clr	a
   2A12 64 80              6672 	xrl	a,#0x80
   2A14 8E F0              6673 	mov	b,r6
   2A16 63 F0 80           6674 	xrl	b,#0x80
   2A19 95 F0              6675 	subb	a,b
   2A1B 50 5A              6676 	jnc	00137$
                    1E62   6677 	C$twitch_ax.c$1164$7$19 ==.
                           6678 ;	apps/twitch_ax/twitch_ax.c:1164: gait.speed = -1 * currentSpeed;
   2A1D C3                 6679 	clr	c
   2A1E E4                 6680 	clr	a
   2A1F 9E                 6681 	subb	a,r6
   2A20 FE                 6682 	mov	r6,a
   2A21 78 C5              6683 	mov	r0,#(_main_gait_1_1 + 0x0010)
   2A23 F2                 6684 	movx	@r0,a
                    1E69   6685 	C$twitch_ax.c$1165$7$19 ==.
                           6686 ;	apps/twitch_ax/twitch_ax.c:1165: currentPos = SIT_POS;
   2A24 78 45              6687 	mov	r0,#_currentPos
   2A26 74 65              6688 	mov	a,#0x65
   2A28 F2                 6689 	movx	@r0,a
   2A29 80 4C              6690 	sjmp	00137$
   2A2B                    6691 00128$:
                    1E70   6692 	C$twitch_ax.c$1173$6$21 ==.
                           6693 ;	apps/twitch_ax/twitch_ax.c:1173: gaitRunnerStop(&gait);			//7
   2A2B 90 F0 B5           6694 	mov	dptr,#_main_gait_1_1
   2A2E 75 F0 60           6695 	mov	b,#0x60
   2A31 12 0B BB           6696 	lcall	_gaitRunnerStop
                    1E79   6697 	C$twitch_ax.c$1174$6$21 ==.
                           6698 ;	apps/twitch_ax/twitch_ax.c:1174: currentPos = START_POS;
   2A34 78 45              6699 	mov	r0,#_currentPos
   2A36 74 64              6700 	mov	a,#0x64
   2A38 F2                 6701 	movx	@r0,a
   2A39 80 3C              6702 	sjmp	00137$
   2A3B                    6703 00133$:
                    1E80   6704 	C$twitch_ax.c$1180$4$16 ==.
                           6705 ;	apps/twitch_ax/twitch_ax.c:1180: else if (currentPos == START_POS) { //in START_POS
   2A3B 78 45              6706 	mov	r0,#_currentPos
   2A3D E2                 6707 	movx	a,@r0
   2A3E B4 64 36           6708 	cjne	a,#0x64,00137$
                    1E86   6709 	C$twitch_ax.c$1182$5$22 ==.
                           6710 ;	apps/twitch_ax/twitch_ax.c:1182: g8speed = START_SPEED; //unnecessary?
   2A41 78 41              6711 	mov	r0,#_g8speed
   2A43 74 4B              6712 	mov	a,#0x4B
   2A45 F2                 6713 	movx	@r0,a
   2A46 08                 6714 	inc	r0
   2A47 E4                 6715 	clr	a
   2A48 F2                 6716 	movx	@r0,a
                    1E8E   6717 	C$twitch_ax.c$1183$5$22 ==.
                           6718 ;	apps/twitch_ax/twitch_ax.c:1183: gaitRunnerPlay(&gait, G8_ANIM_START, g8loopSpeed, -1*g8speed, -1);
   2A49 90 4C 4C           6719 	mov	dptr,#_g8loopSpeed
   2A4C E4                 6720 	clr	a
   2A4D 93                 6721 	movc	a,@a+dptr
   2A4E FE                 6722 	mov	r6,a
   2A4F 74 01              6723 	mov	a,#0x01
   2A51 93                 6724 	movc	a,@a+dptr
   2A52 FF                 6725 	mov	r7,a
   2A53 78 53              6726 	mov	r0,#_gaitRunnerPlay_PARM_3
   2A55 EE                 6727 	mov	a,r6
   2A56 F2                 6728 	movx	@r0,a
   2A57 08                 6729 	inc	r0
   2A58 EF                 6730 	mov	a,r7
   2A59 F2                 6731 	movx	@r0,a
   2A5A 78 52              6732 	mov	r0,#_gaitRunnerPlay_PARM_2
   2A5C 74 01              6733 	mov	a,#0x01
   2A5E F2                 6734 	movx	@r0,a
   2A5F 78 55              6735 	mov	r0,#_gaitRunnerPlay_PARM_4
   2A61 74 B5              6736 	mov	a,#0xB5
   2A63 F2                 6737 	movx	@r0,a
   2A64 78 56              6738 	mov	r0,#_gaitRunnerPlay_PARM_5
   2A66 74 FF              6739 	mov	a,#0xFF
   2A68 F2                 6740 	movx	@r0,a
   2A69 90 F0 B5           6741 	mov	dptr,#_main_gait_1_1
   2A6C 75 F0 60           6742 	mov	b,#0x60
   2A6F 12 13 A0           6743 	lcall	_gaitRunnerPlay
                    1EB7   6744 	C$twitch_ax.c$1184$5$22 ==.
                           6745 ;	apps/twitch_ax/twitch_ax.c:1184: currentPos = SIT_POS;
   2A72 78 45              6746 	mov	r0,#_currentPos
   2A74 74 65              6747 	mov	a,#0x65
   2A76 F2                 6748 	movx	@r0,a
   2A77                    6749 00137$:
                    1EBC   6750 	C$twitch_ax.c$1215$2$3 ==.
                           6751 ;	apps/twitch_ax/twitch_ax.c:1215: delayMs(10);
   2A77 90 00 0A           6752 	mov	dptr,#0x000A
   2A7A 12 3B B7           6753 	lcall	_delayMs
                    1EC2   6754 	C$twitch_ax.c$1217$2$3 ==.
                           6755 ;	apps/twitch_ax/twitch_ax.c:1217: gaitRunnerProcess(&gait);
   2A7D 90 F0 B5           6756 	mov	dptr,#_main_gait_1_1
   2A80 75 F0 60           6757 	mov	b,#0x60
   2A83 12 18 AC           6758 	lcall	_gaitRunnerProcess
   2A86 02 28 C8           6759 	ljmp	00139$
                    1ECE   6760 	C$twitch_ax.c$1219$1$1 ==.
                    1ECE   6761 	XG$main$0$0 ==.
   2A89 22                 6762 	ret
                           6763 	.area CSEG    (CODE)
                           6764 	.area CONST   (CODE)
                    0000   6765 Ftwitch_ax$limbs_0_0$0$0 == .
   4411                    6766 _limbs_0_0:
   4411 C7 FF              6767 	.byte #0xC7,#0xFF	; -57
   4413 00 00              6768 	.byte #0x00,#0x00	;  0
   4415 54 00              6769 	.byte #0x54,#0x00	;  84
   4417 00 00              6770 	.byte #0x00,#0x00	;  0
   4419 7B 00              6771 	.byte #0x7B,#0x00	;  123
   441B 00 00              6772 	.byte #0x00,#0x00	;  0
   441D C7                 6773 	.db #0xC7	; -57	'Ç'
   441E CA FF              6774 	.byte #0xCA,#0xFF	; -54
   4420 E5 FF              6775 	.byte #0xE5,#0xFF	; -27
   4422 51 00              6776 	.byte #0x51,#0x00	;  81
   4424 24 00              6777 	.byte #0x24,#0x00	;  36
   4426 7B 00              6778 	.byte #0x7B,#0x00	;  123
   4428 2A 00              6779 	.byte #0x2A,#0x00	;  42
   442A 00                 6780 	.db #0x00	;  0
   442B CA FF              6781 	.byte #0xCA,#0xFF	; -54
   442D E8 FF              6782 	.byte #0xE8,#0xFF	; -24
   442F 51 00              6783 	.byte #0x51,#0x00	;  81
   4431 21 00              6784 	.byte #0x21,#0x00	;  33
   4433 7B 00              6785 	.byte #0x7B,#0x00	;  123
   4435 2A 00              6786 	.byte #0x2A,#0x00	;  42
   4437 00                 6787 	.db #0x00	;  0
                    0027   6788 Ftwitch_ax$limbs_0_1$0$0 == .
   4438                    6789 _limbs_0_1:
   4438 95 FF              6790 	.byte #0x95,#0xFF	; -107
   443A 8E FF              6791 	.byte #0x8E,#0xFF	; -114
   443C 72 00              6792 	.byte #0x72,#0x00	;  114
   443E AB 00              6793 	.byte #0xAB,#0x00	;  171
   4440 5D 00              6794 	.byte #0x5D,#0x00	;  93
   4442 00 00              6795 	.byte #0x00,#0x00	;  0
   4444 C7                 6796 	.db #0xC7	; -57	'Ç'
   4445 DA FF              6797 	.byte #0xDA,#0xFF	; -38
   4447 EF FF              6798 	.byte #0xEF,#0xFF	; -17
   4449 39 00              6799 	.byte #0x39,#0x00	;  57
   444B 0F 00              6800 	.byte #0x0F,#0x00	;  15
   444D 51 00              6801 	.byte #0x51,#0x00	;  81
   444F 15 00              6802 	.byte #0x15,#0x00	;  21
   4451 33                 6803 	.db #0x33	;  51	'3'
   4452 DD FF              6804 	.byte #0xDD,#0xFF	; -35
   4454 E6 FF              6805 	.byte #0xE6,#0xFF	; -26
   4456 36 00              6806 	.byte #0x36,#0x00	;  54
   4458 1B 00              6807 	.byte #0x1B,#0x00	;  27
   445A 51 00              6808 	.byte #0x51,#0x00	;  81
   445C 18 00              6809 	.byte #0x18,#0x00	;  24
   445E 33                 6810 	.db #0x33	;  51	'3'
                    004E   6811 Ftwitch_ax$limbs_0_2$0$0 == .
   445F                    6812 _limbs_0_2:
   445F 95 FF              6813 	.byte #0x95,#0xFF	; -107
   4461 8E FF              6814 	.byte #0x8E,#0xFF	; -114
   4463 CF 00              6815 	.byte #0xCF,#0x00	;  207
   4465 AB 00              6816 	.byte #0xAB,#0x00	;  171
   4467 00 00              6817 	.byte #0x00,#0x00	;  0
   4469 00 00              6818 	.byte #0x00,#0x00	;  0
   446B 00                 6819 	.db #0x00	;  0
   446C DA FF              6820 	.byte #0xDA,#0xFF	; -38
   446E 11 00              6821 	.byte #0x11,#0x00	;  17
   4470 39 00              6822 	.byte #0x39,#0x00	;  57
   4472 DC FF              6823 	.byte #0xDC,#0xFF	; -36
   4474 51 00              6824 	.byte #0x51,#0x00	;  81
   4476 00 00              6825 	.byte #0x00,#0x00	;  0
   4478 46                 6826 	.db #0x46	;  70	'F'
   4479 DD FF              6827 	.byte #0xDD,#0xFF	; -35
   447B 1A 00              6828 	.byte #0x1A,#0x00	;  26
   447D 33 00              6829 	.byte #0x33,#0x00	;  51
   447F CD FF              6830 	.byte #0xCD,#0xFF	; -51
   4481 54 00              6831 	.byte #0x54,#0x00	;  84
   4483 00 00              6832 	.byte #0x00,#0x00	;  0
   4485 4C                 6833 	.db #0x4C	;  76	'L'
                    0075   6834 Ftwitch_ax$limbs_0_3$0$0 == .
   4486                    6835 _limbs_0_3:
   4486 C7 FF              6836 	.byte #0xC7,#0xFF	; -57
   4488 00 00              6837 	.byte #0x00,#0x00	;  0
   448A 54 00              6838 	.byte #0x54,#0x00	;  84
   448C 00 00              6839 	.byte #0x00,#0x00	;  0
   448E 7B 00              6840 	.byte #0x7B,#0x00	;  123
   4490 00 00              6841 	.byte #0x00,#0x00	;  0
   4492 39                 6842 	.db #0x39	;  57	'9'
   4493 C7 FF              6843 	.byte #0xC7,#0xFF	; -57
   4495 1B 00              6844 	.byte #0x1B,#0x00	;  27
   4497 54 00              6845 	.byte #0x54,#0x00	;  84
   4499 D3 FF              6846 	.byte #0xD3,#0xFF	; -45
   449B 7B 00              6847 	.byte #0x7B,#0x00	;  123
   449D DF FF              6848 	.byte #0xDF,#0xFF	; -33
   449F 33                 6849 	.db #0x33	;  51	'3'
   44A0 C7 FF              6850 	.byte #0xC7,#0xFF	; -57
   44A2 18 00              6851 	.byte #0x18,#0x00	;  24
   44A4 54 00              6852 	.byte #0x54,#0x00	;  84
   44A6 D9 FF              6853 	.byte #0xD9,#0xFF	; -39
   44A8 7B 00              6854 	.byte #0x7B,#0x00	;  123
   44AA DC FF              6855 	.byte #0xDC,#0xFF	; -36
   44AC 33                 6856 	.db #0x33	;  51	'3'
                    009C   6857 Ftwitch_ax$limbs_0_4$0$0 == .
   44AD                    6858 _limbs_0_4:
   44AD C7 FF              6859 	.byte #0xC7,#0xFF	; -57
   44AF 00 00              6860 	.byte #0x00,#0x00	;  0
   44B1 54 00              6861 	.byte #0x54,#0x00	;  84
   44B3 00 00              6862 	.byte #0x00,#0x00	;  0
   44B5 7B 00              6863 	.byte #0x7B,#0x00	;  123
   44B7 00 00              6864 	.byte #0x00,#0x00	;  0
   44B9 39                 6865 	.db #0x39	;  57	'9'
   44BA CA FF              6866 	.byte #0xCA,#0xFF	; -54
   44BC 1B 00              6867 	.byte #0x1B,#0x00	;  27
   44BE 51 00              6868 	.byte #0x51,#0x00	;  81
   44C0 DC FF              6869 	.byte #0xDC,#0xFF	; -36
   44C2 7B 00              6870 	.byte #0x7B,#0x00	;  123
   44C4 D6 FF              6871 	.byte #0xD6,#0xFF	; -42
   44C6 00                 6872 	.db #0x00	;  0
   44C7 CA FF              6873 	.byte #0xCA,#0xFF	; -54
   44C9 18 00              6874 	.byte #0x18,#0x00	;  24
   44CB 51 00              6875 	.byte #0x51,#0x00	;  81
   44CD DF FF              6876 	.byte #0xDF,#0xFF	; -33
   44CF 7B 00              6877 	.byte #0x7B,#0x00	;  123
   44D1 D6 FF              6878 	.byte #0xD6,#0xFF	; -42
   44D3 00                 6879 	.db #0x00	;  0
                    00C3   6880 Ftwitch_ax$limbs_0_5$0$0 == .
   44D4                    6881 _limbs_0_5:
   44D4 95 FF              6882 	.byte #0x95,#0xFF	; -107
   44D6 72 00              6883 	.byte #0x72,#0x00	;  114
   44D8 72 00              6884 	.byte #0x72,#0x00	;  114
   44DA 55 FF              6885 	.byte #0x55,#0xFF	; -171
   44DC 5D 00              6886 	.byte #0x5D,#0x00	;  93
   44DE 00 00              6887 	.byte #0x00,#0x00	;  0
   44E0 39                 6888 	.db #0x39	;  57	'9'
   44E1 DA FF              6889 	.byte #0xDA,#0xFF	; -38
   44E3 11 00              6890 	.byte #0x11,#0x00	;  17
   44E5 39 00              6891 	.byte #0x39,#0x00	;  57
   44E7 F1 FF              6892 	.byte #0xF1,#0xFF	; -15
   44E9 51 00              6893 	.byte #0x51,#0x00	;  81
   44EB EB FF              6894 	.byte #0xEB,#0xFF	; -21
   44ED CD                 6895 	.db #0xCD	; -51	'Í'
   44EE DD FF              6896 	.byte #0xDD,#0xFF	; -35
   44F0 1A 00              6897 	.byte #0x1A,#0x00	;  26
   44F2 36 00              6898 	.byte #0x36,#0x00	;  54
   44F4 E5 FF              6899 	.byte #0xE5,#0xFF	; -27
   44F6 51 00              6900 	.byte #0x51,#0x00	;  81
   44F8 E8 FF              6901 	.byte #0xE8,#0xFF	; -24
   44FA CD                 6902 	.db #0xCD	; -51	'Í'
                    00EA   6903 Ftwitch_ax$limbs_0_6$0$0 == .
   44FB                    6904 _limbs_0_6:
   44FB 95 FF              6905 	.byte #0x95,#0xFF	; -107
   44FD 72 00              6906 	.byte #0x72,#0x00	;  114
   44FF CF 00              6907 	.byte #0xCF,#0x00	;  207
   4501 55 FF              6908 	.byte #0x55,#0xFF	; -171
   4503 00 00              6909 	.byte #0x00,#0x00	;  0
   4505 00 00              6910 	.byte #0x00,#0x00	;  0
   4507 00                 6911 	.db #0x00	;  0
   4508 DA FF              6912 	.byte #0xDA,#0xFF	; -38
   450A EF FF              6913 	.byte #0xEF,#0xFF	; -17
   450C 39 00              6914 	.byte #0x39,#0x00	;  57
   450E 24 00              6915 	.byte #0x24,#0x00	;  36
   4510 51 00              6916 	.byte #0x51,#0x00	;  81
   4512 00 00              6917 	.byte #0x00,#0x00	;  0
   4514 BA                 6918 	.db #0xBA	; -70	'º'
   4515 DD FF              6919 	.byte #0xDD,#0xFF	; -35
   4517 E6 FF              6920 	.byte #0xE6,#0xFF	; -26
   4519 33 00              6921 	.byte #0x33,#0x00	;  51
   451B 33 00              6922 	.byte #0x33,#0x00	;  51
   451D 54 00              6923 	.byte #0x54,#0x00	;  84
   451F 00 00              6924 	.byte #0x00,#0x00	;  0
   4521 B4                 6925 	.db #0xB4	; -76	'´'
                    0111   6926 Ftwitch_ax$limbs_0_7$0$0 == .
   4522                    6927 _limbs_0_7:
   4522 CA FF              6928 	.byte #0xCA,#0xFF	; -54
   4524 00 00              6929 	.byte #0x00,#0x00	;  0
   4526 51 00              6930 	.byte #0x51,#0x00	;  81
   4528 00 00              6931 	.byte #0x00,#0x00	;  0
   452A 7B 00              6932 	.byte #0x7B,#0x00	;  123
   452C 00 00              6933 	.byte #0x00,#0x00	;  0
   452E C7                 6934 	.db #0xC7	; -57	'Ç'
   452F CA FF              6935 	.byte #0xCA,#0xFF	; -54
   4531 E5 FF              6936 	.byte #0xE5,#0xFF	; -27
   4533 51 00              6937 	.byte #0x51,#0x00	;  81
   4535 2D 00              6938 	.byte #0x2D,#0x00	;  45
   4537 7B 00              6939 	.byte #0x7B,#0x00	;  123
   4539 21 00              6940 	.byte #0x21,#0x00	;  33
   453B CD                 6941 	.db #0xCD	; -51	'Í'
   453C CA FF              6942 	.byte #0xCA,#0xFF	; -54
   453E E8 FF              6943 	.byte #0xE8,#0xFF	; -24
   4540 51 00              6944 	.byte #0x51,#0x00	;  81
   4542 27 00              6945 	.byte #0x27,#0x00	;  39
   4544 7B 00              6946 	.byte #0x7B,#0x00	;  123
   4546 24 00              6947 	.byte #0x24,#0x00	;  36
   4548 CD                 6948 	.db #0xCD	; -51	'Í'
                    0138   6949 Ftwitch_ax$limbs_1_0$0$0 == .
   4549                    6950 _limbs_1_0:
   4549 0C FE              6951 	.byte #0x0C,#0xFE	; -500
   454B 72 00              6952 	.byte #0x72,#0x00	;  114
   454D EE 02              6953 	.byte #0xEE,#0x02	;  750
   454F 55 FF              6954 	.byte #0x55,#0xFF	; -171
   4551 EE 02              6955 	.byte #0xEE,#0x02	;  750
   4553 00 00              6956 	.byte #0x00,#0x00	;  0
   4555 00                 6957 	.db #0x00	;  0
   4556 0C FE              6958 	.byte #0x0C,#0xFE	; -500
   4558 00 00              6959 	.byte #0x00,#0x00	;  0
   455A EE 02              6960 	.byte #0xEE,#0x02	;  750
   455C 00 00              6961 	.byte #0x00,#0x00	;  0
   455E EE 02              6962 	.byte #0xEE,#0x02	;  750
   4560 00 00              6963 	.byte #0x00,#0x00	;  0
   4562 00                 6964 	.db #0x00	;  0
   4563 0C FE              6965 	.byte #0x0C,#0xFE	; -500
   4565 00 00              6966 	.byte #0x00,#0x00	;  0
   4567 EE 02              6967 	.byte #0xEE,#0x02	;  750
   4569 00 00              6968 	.byte #0x00,#0x00	;  0
   456B EE 02              6969 	.byte #0xEE,#0x02	;  750
   456D 00 00              6970 	.byte #0x00,#0x00	;  0
   456F 00                 6971 	.db #0x00	;  0
                    015F   6972 Ftwitch_ax$limbs_1_1$0$0 == .
   4570                    6973 _limbs_1_1:
   4570 00 00              6974 	.byte #0x00,#0x00	;  0
   4572 8E FF              6975 	.byte #0x8E,#0xFF	; -114
   4574 00 00              6976 	.byte #0x00,#0x00	;  0
   4576 AB 00              6977 	.byte #0xAB,#0x00	;  171
   4578 00 00              6978 	.byte #0x00,#0x00	;  0
   457A 00 00              6979 	.byte #0x00,#0x00	;  0
   457C C7                 6980 	.db #0xC7	; -57	'Ç'
   457D 00 00              6981 	.byte #0x00,#0x00	;  0
   457F 00 00              6982 	.byte #0x00,#0x00	;  0
   4581 00 00              6983 	.byte #0x00,#0x00	;  0
   4583 00 00              6984 	.byte #0x00,#0x00	;  0
   4585 00 00              6985 	.byte #0x00,#0x00	;  0
   4587 00 00              6986 	.byte #0x00,#0x00	;  0
   4589 00                 6987 	.db #0x00	;  0
   458A 00 00              6988 	.byte #0x00,#0x00	;  0
   458C 00 00              6989 	.byte #0x00,#0x00	;  0
   458E 00 00              6990 	.byte #0x00,#0x00	;  0
   4590 00 00              6991 	.byte #0x00,#0x00	;  0
   4592 00 00              6992 	.byte #0x00,#0x00	;  0
   4594 00 00              6993 	.byte #0x00,#0x00	;  0
   4596 00                 6994 	.db #0x00	;  0
                    0186   6995 Ftwitch_ax$limbs_2_0$0$0 == .
   4597                    6996 _limbs_2_0:
   4597 B5 FF              6997 	.byte #0xB5,#0xFF	; -75
   4599 00 00              6998 	.byte #0x00,#0x00	;  0
   459B 6F 00              6999 	.byte #0x6F,#0x00	;  111
   459D 00 00              7000 	.byte #0x00,#0x00	;  0
   459F 72 00              7001 	.byte #0x72,#0x00	;  114
   45A1 00 00              7002 	.byte #0x00,#0x00	;  0
   45A3 C7                 7003 	.db #0xC7	; -57	'Ç'
   45A4 BB FF              7004 	.byte #0xBB,#0xFF	; -69
   45A6 D2 FF              7005 	.byte #0xD2,#0xFF	; -46
   45A8 69 00              7006 	.byte #0x69,#0x00	;  105
   45AA 36 00              7007 	.byte #0x36,#0x00	;  54
   45AC 72 00              7008 	.byte #0x72,#0x00	;  114
   45AE 1E 00              7009 	.byte #0x1E,#0x00	;  30
   45B0 00                 7010 	.db #0x00	;  0
   45B1 BB FF              7011 	.byte #0xBB,#0xFF	; -69
   45B3 2E 00              7012 	.byte #0x2E,#0x00	;  46
   45B5 69 00              7013 	.byte #0x69,#0x00	;  105
   45B7 CA FF              7014 	.byte #0xCA,#0xFF	; -54
   45B9 72 00              7015 	.byte #0x72,#0x00	;  114
   45BB E2 FF              7016 	.byte #0xE2,#0xFF	; -30
   45BD 00                 7017 	.db #0x00	;  0
                    01AD   7018 Ftwitch_ax$limbs_2_1$0$0 == .
   45BE                    7019 _limbs_2_1:
   45BE CC FF              7020 	.byte #0xCC,#0xFF	; -52
   45C0 1C FF              7021 	.byte #0x1C,#0xFF	; -228
   45C2 4E 00              7022 	.byte #0x4E,#0x00	;  78
   45C4 56 01              7023 	.byte #0x56,#0x01	;  342
   45C6 AE 00              7024 	.byte #0xAE,#0x00	;  174
   45C8 00 00              7025 	.byte #0x00,#0x00	;  0
   45CA C7                 7026 	.db #0xC7	; -57	'Ç'
   45CB 9C FF              7027 	.byte #0x9C,#0xFF	; -100
   45CD 00 00              7028 	.byte #0x00,#0x00	;  0
   45CF 96 00              7029 	.byte #0x96,#0x00	;  150
   45D1 00 00              7030 	.byte #0x00,#0x00	;  0
   45D3 96 00              7031 	.byte #0x96,#0x00	;  150
   45D5 00 00              7032 	.byte #0x00,#0x00	;  0
   45D7 26                 7033 	.db #0x26	;  38
   45D8 9C FF              7034 	.byte #0x9C,#0xFF	; -100
   45DA 00 00              7035 	.byte #0x00,#0x00	;  0
   45DC 96 00              7036 	.byte #0x96,#0x00	;  150
   45DE 00 00              7037 	.byte #0x00,#0x00	;  0
   45E0 96 00              7038 	.byte #0x96,#0x00	;  150
   45E2 00 00              7039 	.byte #0x00,#0x00	;  0
   45E4 DA                 7040 	.db #0xDA	; -38
                    01D4   7041 Ftwitch_ax$limbs_2_2$0$0 == .
   45E5                    7042 _limbs_2_2:
   45E5 B5 FF              7043 	.byte #0xB5,#0xFF	; -75
   45E7 00 00              7044 	.byte #0x00,#0x00	;  0
   45E9 6F 00              7045 	.byte #0x6F,#0x00	;  111
   45EB 00 00              7046 	.byte #0x00,#0x00	;  0
   45ED 72 00              7047 	.byte #0x72,#0x00	;  114
   45EF 00 00              7048 	.byte #0x00,#0x00	;  0
   45F1 39                 7049 	.db #0x39	;  57	'9'
   45F2 B8 FF              7050 	.byte #0xB8,#0xFF	; -72
   45F4 2E 00              7051 	.byte #0x2E,#0x00	;  46
   45F6 69 00              7052 	.byte #0x69,#0x00	;  105
   45F8 AC FF              7053 	.byte #0xAC,#0xFF	; -84
   45FA 75 00              7054 	.byte #0x75,#0x00	;  117
   45FC 00 00              7055 	.byte #0x00,#0x00	;  0
   45FE 26                 7056 	.db #0x26	;  38
   45FF B8 FF              7057 	.byte #0xB8,#0xFF	; -72
   4601 D2 FF              7058 	.byte #0xD2,#0xFF	; -46
   4603 69 00              7059 	.byte #0x69,#0x00	;  105
   4605 54 00              7060 	.byte #0x54,#0x00	;  84
   4607 75 00              7061 	.byte #0x75,#0x00	;  117
   4609 00 00              7062 	.byte #0x00,#0x00	;  0
   460B DA                 7063 	.db #0xDA	; -38
                    01FB   7064 Ftwitch_ax$limbs_2_3$0$0 == .
   460C                    7065 _limbs_2_3:
   460C B5 FF              7066 	.byte #0xB5,#0xFF	; -75
   460E 00 00              7067 	.byte #0x00,#0x00	;  0
   4610 6F 00              7068 	.byte #0x6F,#0x00	;  111
   4612 00 00              7069 	.byte #0x00,#0x00	;  0
   4614 72 00              7070 	.byte #0x72,#0x00	;  114
   4616 00 00              7071 	.byte #0x00,#0x00	;  0
   4618 39                 7072 	.db #0x39	;  57	'9'
   4619 BB FF              7073 	.byte #0xBB,#0xFF	; -69
   461B 2E 00              7074 	.byte #0x2E,#0x00	;  46
   461D 69 00              7075 	.byte #0x69,#0x00	;  105
   461F CA FF              7076 	.byte #0xCA,#0xFF	; -54
   4621 72 00              7077 	.byte #0x72,#0x00	;  114
   4623 E2 FF              7078 	.byte #0xE2,#0xFF	; -30
   4625 00                 7079 	.db #0x00	;  0
   4626 BB FF              7080 	.byte #0xBB,#0xFF	; -69
   4628 D2 FF              7081 	.byte #0xD2,#0xFF	; -46
   462A 69 00              7082 	.byte #0x69,#0x00	;  105
   462C 36 00              7083 	.byte #0x36,#0x00	;  54
   462E 72 00              7084 	.byte #0x72,#0x00	;  114
   4630 1E 00              7085 	.byte #0x1E,#0x00	;  30
   4632 00                 7086 	.db #0x00	;  0
                    0222   7087 Ftwitch_ax$limbs_2_4$0$0 == .
   4633                    7088 _limbs_2_4:
   4633 CC FF              7089 	.byte #0xCC,#0xFF	; -52
   4635 E4 00              7090 	.byte #0xE4,#0x00	;  228
   4637 4E 00              7091 	.byte #0x4E,#0x00	;  78
   4639 AA FE              7092 	.byte #0xAA,#0xFE	; -342
   463B AE 00              7093 	.byte #0xAE,#0x00	;  174
   463D 00 00              7094 	.byte #0x00,#0x00	;  0
   463F 39                 7095 	.db #0x39	;  57	'9'
   4640 9C FF              7096 	.byte #0x9C,#0xFF	; -100
   4642 00 00              7097 	.byte #0x00,#0x00	;  0
   4644 96 00              7098 	.byte #0x96,#0x00	;  150
   4646 00 00              7099 	.byte #0x00,#0x00	;  0
   4648 96 00              7100 	.byte #0x96,#0x00	;  150
   464A 00 00              7101 	.byte #0x00,#0x00	;  0
   464C DA                 7102 	.db #0xDA	; -38
   464D 9C FF              7103 	.byte #0x9C,#0xFF	; -100
   464F 00 00              7104 	.byte #0x00,#0x00	;  0
   4651 96 00              7105 	.byte #0x96,#0x00	;  150
   4653 00 00              7106 	.byte #0x00,#0x00	;  0
   4655 96 00              7107 	.byte #0x96,#0x00	;  150
   4657 00 00              7108 	.byte #0x00,#0x00	;  0
   4659 26                 7109 	.db #0x26	;  38
                    0249   7110 Ftwitch_ax$limbs_2_5$0$0 == .
   465A                    7111 _limbs_2_5:
   465A B8 FF              7112 	.byte #0xB8,#0xFF	; -72
   465C 00 00              7113 	.byte #0x00,#0x00	;  0
   465E 6C 00              7114 	.byte #0x6C,#0x00	;  108
   4660 00 00              7115 	.byte #0x00,#0x00	;  0
   4662 72 00              7116 	.byte #0x72,#0x00	;  114
   4664 00 00              7117 	.byte #0x00,#0x00	;  0
   4666 C7                 7118 	.db #0xC7	; -57	'Ç'
   4667 BB FF              7119 	.byte #0xBB,#0xFF	; -69
   4669 D2 FF              7120 	.byte #0xD2,#0xFF	; -46
   466B 66 00              7121 	.byte #0x66,#0x00	;  102
   466D 54 00              7122 	.byte #0x54,#0x00	;  84
   466F 75 00              7123 	.byte #0x75,#0x00	;  117
   4671 00 00              7124 	.byte #0x00,#0x00	;  0
   4673 DA                 7125 	.db #0xDA	; -38
   4674 BB FF              7126 	.byte #0xBB,#0xFF	; -69
   4676 2E 00              7127 	.byte #0x2E,#0x00	;  46
   4678 66 00              7128 	.byte #0x66,#0x00	;  102
   467A AC FF              7129 	.byte #0xAC,#0xFF	; -84
   467C 75 00              7130 	.byte #0x75,#0x00	;  117
   467E 00 00              7131 	.byte #0x00,#0x00	;  0
   4680 26                 7132 	.db #0x26	;  38
                    0270   7133 Ftwitch_ax$limbs_3_0$0$0 == .
   4681                    7134 _limbs_3_0:
   4681 C7 FF              7135 	.byte #0xC7,#0xFF	; -57
   4683 00 00              7136 	.byte #0x00,#0x00	;  0
   4685 54 00              7137 	.byte #0x54,#0x00	;  84
   4687 00 00              7138 	.byte #0x00,#0x00	;  0
   4689 7B 00              7139 	.byte #0x7B,#0x00	;  123
   468B 00 00              7140 	.byte #0x00,#0x00	;  0
   468D C7                 7141 	.db #0xC7	; -57	'Ç'
   468E CA FF              7142 	.byte #0xCA,#0xFF	; -54
   4690 1B 00              7143 	.byte #0x1B,#0x00	;  27
   4692 51 00              7144 	.byte #0x51,#0x00	;  81
   4694 DC FF              7145 	.byte #0xDC,#0xFF	; -36
   4696 7B 00              7146 	.byte #0x7B,#0x00	;  123
   4698 D6 FF              7147 	.byte #0xD6,#0xFF	; -42
   469A 00                 7148 	.db #0x00	;  0
   469B CA FF              7149 	.byte #0xCA,#0xFF	; -54
   469D 18 00              7150 	.byte #0x18,#0x00	;  24
   469F 51 00              7151 	.byte #0x51,#0x00	;  81
   46A1 DF FF              7152 	.byte #0xDF,#0xFF	; -33
   46A3 7B 00              7153 	.byte #0x7B,#0x00	;  123
   46A5 D6 FF              7154 	.byte #0xD6,#0xFF	; -42
   46A7 00                 7155 	.db #0x00	;  0
                    0297   7156 Ftwitch_ax$limbs_3_1$0$0 == .
   46A8                    7157 _limbs_3_1:
   46A8 95 FF              7158 	.byte #0x95,#0xFF	; -107
   46AA 8E FF              7159 	.byte #0x8E,#0xFF	; -114
   46AC 72 00              7160 	.byte #0x72,#0x00	;  114
   46AE AB 00              7161 	.byte #0xAB,#0x00	;  171
   46B0 5D 00              7162 	.byte #0x5D,#0x00	;  93
   46B2 00 00              7163 	.byte #0x00,#0x00	;  0
   46B4 C7                 7164 	.db #0xC7	; -57	'Ç'
   46B5 DA FF              7165 	.byte #0xDA,#0xFF	; -38
   46B7 11 00              7166 	.byte #0x11,#0x00	;  17
   46B9 39 00              7167 	.byte #0x39,#0x00	;  57
   46BB F1 FF              7168 	.byte #0xF1,#0xFF	; -15
   46BD 51 00              7169 	.byte #0x51,#0x00	;  81
   46BF EB FF              7170 	.byte #0xEB,#0xFF	; -21
   46C1 CD                 7171 	.db #0xCD	; -51	'Í'
   46C2 DD FF              7172 	.byte #0xDD,#0xFF	; -35
   46C4 1A 00              7173 	.byte #0x1A,#0x00	;  26
   46C6 36 00              7174 	.byte #0x36,#0x00	;  54
   46C8 E5 FF              7175 	.byte #0xE5,#0xFF	; -27
   46CA 51 00              7176 	.byte #0x51,#0x00	;  81
   46CC E8 FF              7177 	.byte #0xE8,#0xFF	; -24
   46CE CD                 7178 	.db #0xCD	; -51	'Í'
                    02BE   7179 Ftwitch_ax$limbs_3_2$0$0 == .
   46CF                    7180 _limbs_3_2:
   46CF 95 FF              7181 	.byte #0x95,#0xFF	; -107
   46D1 8E FF              7182 	.byte #0x8E,#0xFF	; -114
   46D3 CF 00              7183 	.byte #0xCF,#0x00	;  207
   46D5 AB 00              7184 	.byte #0xAB,#0x00	;  171
   46D7 00 00              7185 	.byte #0x00,#0x00	;  0
   46D9 00 00              7186 	.byte #0x00,#0x00	;  0
   46DB 00                 7187 	.db #0x00	;  0
   46DC DA FF              7188 	.byte #0xDA,#0xFF	; -38
   46DE EF FF              7189 	.byte #0xEF,#0xFF	; -17
   46E0 39 00              7190 	.byte #0x39,#0x00	;  57
   46E2 24 00              7191 	.byte #0x24,#0x00	;  36
   46E4 51 00              7192 	.byte #0x51,#0x00	;  81
   46E6 00 00              7193 	.byte #0x00,#0x00	;  0
   46E8 BA                 7194 	.db #0xBA	; -70	'º'
   46E9 DD FF              7195 	.byte #0xDD,#0xFF	; -35
   46EB E6 FF              7196 	.byte #0xE6,#0xFF	; -26
   46ED 33 00              7197 	.byte #0x33,#0x00	;  51
   46EF 33 00              7198 	.byte #0x33,#0x00	;  51
   46F1 54 00              7199 	.byte #0x54,#0x00	;  84
   46F3 00 00              7200 	.byte #0x00,#0x00	;  0
   46F5 B4                 7201 	.db #0xB4	; -76	'´'
                    02E5   7202 Ftwitch_ax$limbs_3_3$0$0 == .
   46F6                    7203 _limbs_3_3:
   46F6 C7 FF              7204 	.byte #0xC7,#0xFF	; -57
   46F8 00 00              7205 	.byte #0x00,#0x00	;  0
   46FA 54 00              7206 	.byte #0x54,#0x00	;  84
   46FC 00 00              7207 	.byte #0x00,#0x00	;  0
   46FE 7B 00              7208 	.byte #0x7B,#0x00	;  123
   4700 00 00              7209 	.byte #0x00,#0x00	;  0
   4702 39                 7210 	.db #0x39	;  57	'9'
   4703 C7 FF              7211 	.byte #0xC7,#0xFF	; -57
   4705 E5 FF              7212 	.byte #0xE5,#0xFF	; -27
   4707 54 00              7213 	.byte #0x54,#0x00	;  84
   4709 2D 00              7214 	.byte #0x2D,#0x00	;  45
   470B 7B 00              7215 	.byte #0x7B,#0x00	;  123
   470D 21 00              7216 	.byte #0x21,#0x00	;  33
   470F CD                 7217 	.db #0xCD	; -51	'Í'
   4710 C7 FF              7218 	.byte #0xC7,#0xFF	; -57
   4712 E8 FF              7219 	.byte #0xE8,#0xFF	; -24
   4714 54 00              7220 	.byte #0x54,#0x00	;  84
   4716 27 00              7221 	.byte #0x27,#0x00	;  39
   4718 7B 00              7222 	.byte #0x7B,#0x00	;  123
   471A 24 00              7223 	.byte #0x24,#0x00	;  36
   471C CD                 7224 	.db #0xCD	; -51	'Í'
                    030C   7225 Ftwitch_ax$limbs_3_4$0$0 == .
   471D                    7226 _limbs_3_4:
   471D C7 FF              7227 	.byte #0xC7,#0xFF	; -57
   471F 00 00              7228 	.byte #0x00,#0x00	;  0
   4721 54 00              7229 	.byte #0x54,#0x00	;  84
   4723 00 00              7230 	.byte #0x00,#0x00	;  0
   4725 7B 00              7231 	.byte #0x7B,#0x00	;  123
   4727 00 00              7232 	.byte #0x00,#0x00	;  0
   4729 39                 7233 	.db #0x39	;  57	'9'
   472A CA FF              7234 	.byte #0xCA,#0xFF	; -54
   472C E5 FF              7235 	.byte #0xE5,#0xFF	; -27
   472E 51 00              7236 	.byte #0x51,#0x00	;  81
   4730 24 00              7237 	.byte #0x24,#0x00	;  36
   4732 7B 00              7238 	.byte #0x7B,#0x00	;  123
   4734 2A 00              7239 	.byte #0x2A,#0x00	;  42
   4736 00                 7240 	.db #0x00	;  0
   4737 CA FF              7241 	.byte #0xCA,#0xFF	; -54
   4739 E8 FF              7242 	.byte #0xE8,#0xFF	; -24
   473B 51 00              7243 	.byte #0x51,#0x00	;  81
   473D 21 00              7244 	.byte #0x21,#0x00	;  33
   473F 7B 00              7245 	.byte #0x7B,#0x00	;  123
   4741 2A 00              7246 	.byte #0x2A,#0x00	;  42
   4743 00                 7247 	.db #0x00	;  0
                    0333   7248 Ftwitch_ax$limbs_3_5$0$0 == .
   4744                    7249 _limbs_3_5:
   4744 95 FF              7250 	.byte #0x95,#0xFF	; -107
   4746 72 00              7251 	.byte #0x72,#0x00	;  114
   4748 72 00              7252 	.byte #0x72,#0x00	;  114
   474A 55 FF              7253 	.byte #0x55,#0xFF	; -171
   474C 5D 00              7254 	.byte #0x5D,#0x00	;  93
   474E 00 00              7255 	.byte #0x00,#0x00	;  0
   4750 39                 7256 	.db #0x39	;  57	'9'
   4751 DA FF              7257 	.byte #0xDA,#0xFF	; -38
   4753 EF FF              7258 	.byte #0xEF,#0xFF	; -17
   4755 39 00              7259 	.byte #0x39,#0x00	;  57
   4757 0F 00              7260 	.byte #0x0F,#0x00	;  15
   4759 51 00              7261 	.byte #0x51,#0x00	;  81
   475B 15 00              7262 	.byte #0x15,#0x00	;  21
   475D 33                 7263 	.db #0x33	;  51	'3'
   475E DD FF              7264 	.byte #0xDD,#0xFF	; -35
   4760 E6 FF              7265 	.byte #0xE6,#0xFF	; -26
   4762 36 00              7266 	.byte #0x36,#0x00	;  54
   4764 1B 00              7267 	.byte #0x1B,#0x00	;  27
   4766 51 00              7268 	.byte #0x51,#0x00	;  81
   4768 18 00              7269 	.byte #0x18,#0x00	;  24
   476A 33                 7270 	.db #0x33	;  51	'3'
                    035A   7271 Ftwitch_ax$limbs_3_6$0$0 == .
   476B                    7272 _limbs_3_6:
   476B 95 FF              7273 	.byte #0x95,#0xFF	; -107
   476D 72 00              7274 	.byte #0x72,#0x00	;  114
   476F CF 00              7275 	.byte #0xCF,#0x00	;  207
   4771 55 FF              7276 	.byte #0x55,#0xFF	; -171
   4773 00 00              7277 	.byte #0x00,#0x00	;  0
   4775 00 00              7278 	.byte #0x00,#0x00	;  0
   4777 00                 7279 	.db #0x00	;  0
   4778 DA FF              7280 	.byte #0xDA,#0xFF	; -38
   477A 11 00              7281 	.byte #0x11,#0x00	;  17
   477C 39 00              7282 	.byte #0x39,#0x00	;  57
   477E DC FF              7283 	.byte #0xDC,#0xFF	; -36
   4780 51 00              7284 	.byte #0x51,#0x00	;  81
   4782 00 00              7285 	.byte #0x00,#0x00	;  0
   4784 46                 7286 	.db #0x46	;  70	'F'
   4785 DD FF              7287 	.byte #0xDD,#0xFF	; -35
   4787 1A 00              7288 	.byte #0x1A,#0x00	;  26
   4789 33 00              7289 	.byte #0x33,#0x00	;  51
   478B CD FF              7290 	.byte #0xCD,#0xFF	; -51
   478D 54 00              7291 	.byte #0x54,#0x00	;  84
   478F 00 00              7292 	.byte #0x00,#0x00	;  0
   4791 4C                 7293 	.db #0x4C	;  76	'L'
                    0381   7294 Ftwitch_ax$limbs_3_7$0$0 == .
   4792                    7295 _limbs_3_7:
   4792 CA FF              7296 	.byte #0xCA,#0xFF	; -54
   4794 00 00              7297 	.byte #0x00,#0x00	;  0
   4796 51 00              7298 	.byte #0x51,#0x00	;  81
   4798 00 00              7299 	.byte #0x00,#0x00	;  0
   479A 7B 00              7300 	.byte #0x7B,#0x00	;  123
   479C 00 00              7301 	.byte #0x00,#0x00	;  0
   479E C7                 7302 	.db #0xC7	; -57	'Ç'
   479F CA FF              7303 	.byte #0xCA,#0xFF	; -54
   47A1 1B 00              7304 	.byte #0x1B,#0x00	;  27
   47A3 51 00              7305 	.byte #0x51,#0x00	;  81
   47A5 D3 FF              7306 	.byte #0xD3,#0xFF	; -45
   47A7 7B 00              7307 	.byte #0x7B,#0x00	;  123
   47A9 DF FF              7308 	.byte #0xDF,#0xFF	; -33
   47AB 33                 7309 	.db #0x33	;  51	'3'
   47AC CA FF              7310 	.byte #0xCA,#0xFF	; -54
   47AE 18 00              7311 	.byte #0x18,#0x00	;  24
   47B0 51 00              7312 	.byte #0x51,#0x00	;  81
   47B2 D9 FF              7313 	.byte #0xD9,#0xFF	; -39
   47B4 7B 00              7314 	.byte #0x7B,#0x00	;  123
   47B6 DC FF              7315 	.byte #0xDC,#0xFF	; -36
   47B8 33                 7316 	.db #0x33	;  51	'3'
                    03A8   7317 Ftwitch_ax$limbs_4_0$0$0 == .
   47B9                    7318 _limbs_4_0:
   47B9 C7 FF              7319 	.byte #0xC7,#0xFF	; -57
   47BB 00 00              7320 	.byte #0x00,#0x00	;  0
   47BD 54 00              7321 	.byte #0x54,#0x00	;  84
   47BF 00 00              7322 	.byte #0x00,#0x00	;  0
   47C1 7B 00              7323 	.byte #0x7B,#0x00	;  123
   47C3 00 00              7324 	.byte #0x00,#0x00	;  0
   47C5 C7                 7325 	.db #0xC7	; -57	'Ç'
   47C6 CA FF              7326 	.byte #0xCA,#0xFF	; -54
   47C8 EA FF              7327 	.byte #0xEA,#0xFF	; -22
   47CA 51 00              7328 	.byte #0x51,#0x00	;  81
   47CC 1E 00              7329 	.byte #0x1E,#0x00	;  30
   47CE 7B 00              7330 	.byte #0x7B,#0x00	;  123
   47D0 24 00              7331 	.byte #0x24,#0x00	;  36
   47D2 00                 7332 	.db #0x00	;  0
   47D3 CA FF              7333 	.byte #0xCA,#0xFF	; -54
   47D5 E8 FF              7334 	.byte #0xE8,#0xFF	; -24
   47D7 51 00              7335 	.byte #0x51,#0x00	;  81
   47D9 21 00              7336 	.byte #0x21,#0x00	;  33
   47DB 7B 00              7337 	.byte #0x7B,#0x00	;  123
   47DD 2A 00              7338 	.byte #0x2A,#0x00	;  42
   47DF 00                 7339 	.db #0x00	;  0
                    03CF   7340 Ftwitch_ax$limbs_4_1$0$0 == .
   47E0                    7341 _limbs_4_1:
   47E0 95 FF              7342 	.byte #0x95,#0xFF	; -107
   47E2 8E FF              7343 	.byte #0x8E,#0xFF	; -114
   47E4 72 00              7344 	.byte #0x72,#0x00	;  114
   47E6 AB 00              7345 	.byte #0xAB,#0x00	;  171
   47E8 5D 00              7346 	.byte #0x5D,#0x00	;  93
   47EA 00 00              7347 	.byte #0x00,#0x00	;  0
   47EC C7                 7348 	.db #0xC7	; -57	'Ç'
   47ED DD FF              7349 	.byte #0xDD,#0xFF	; -35
   47EF E9 FF              7350 	.byte #0xE9,#0xFF	; -23
   47F1 36 00              7351 	.byte #0x36,#0x00	;  54
   47F3 18 00              7352 	.byte #0x18,#0x00	;  24
   47F5 51 00              7353 	.byte #0x51,#0x00	;  81
   47F7 15 00              7354 	.byte #0x15,#0x00	;  21
   47F9 2C                 7355 	.db #0x2C	;  44
   47FA DD FF              7356 	.byte #0xDD,#0xFF	; -35
   47FC E6 FF              7357 	.byte #0xE6,#0xFF	; -26
   47FE 36 00              7358 	.byte #0x36,#0x00	;  54
   4800 1B 00              7359 	.byte #0x1B,#0x00	;  27
   4802 51 00              7360 	.byte #0x51,#0x00	;  81
   4804 18 00              7361 	.byte #0x18,#0x00	;  24
   4806 33                 7362 	.db #0x33	;  51	'3'
                    03F6   7363 Ftwitch_ax$limbs_4_2$0$0 == .
   4807                    7364 _limbs_4_2:
   4807 95 FF              7365 	.byte #0x95,#0xFF	; -107
   4809 8E FF              7366 	.byte #0x8E,#0xFF	; -114
   480B CF 00              7367 	.byte #0xCF,#0x00	;  207
   480D AB 00              7368 	.byte #0xAB,#0x00	;  171
   480F 00 00              7369 	.byte #0x00,#0x00	;  0
   4811 00 00              7370 	.byte #0x00,#0x00	;  0
   4813 00                 7371 	.db #0x00	;  0
   4814 DD FF              7372 	.byte #0xDD,#0xFF	; -35
   4816 17 00              7373 	.byte #0x17,#0x00	;  23
   4818 33 00              7374 	.byte #0x33,#0x00	;  51
   481A D3 FF              7375 	.byte #0xD3,#0xFF	; -45
   481C 54 00              7376 	.byte #0x54,#0x00	;  84
   481E 00 00              7377 	.byte #0x00,#0x00	;  0
   4820 42                 7378 	.db #0x42	;  66	'B'
   4821 DD FF              7379 	.byte #0xDD,#0xFF	; -35
   4823 1A 00              7380 	.byte #0x1A,#0x00	;  26
   4825 33 00              7381 	.byte #0x33,#0x00	;  51
   4827 CD FF              7382 	.byte #0xCD,#0xFF	; -51
   4829 54 00              7383 	.byte #0x54,#0x00	;  84
   482B 00 00              7384 	.byte #0x00,#0x00	;  0
   482D 4C                 7385 	.db #0x4C	;  76	'L'
                    041D   7386 Ftwitch_ax$limbs_4_3$0$0 == .
   482E                    7387 _limbs_4_3:
   482E C7 FF              7388 	.byte #0xC7,#0xFF	; -57
   4830 00 00              7389 	.byte #0x00,#0x00	;  0
   4832 54 00              7390 	.byte #0x54,#0x00	;  84
   4834 00 00              7391 	.byte #0x00,#0x00	;  0
   4836 7B 00              7392 	.byte #0x7B,#0x00	;  123
   4838 00 00              7393 	.byte #0x00,#0x00	;  0
   483A 39                 7394 	.db #0x39	;  57	'9'
   483B C7 FF              7395 	.byte #0xC7,#0xFF	; -57
   483D 16 00              7396 	.byte #0x16,#0x00	;  22
   483F 54 00              7397 	.byte #0x54,#0x00	;  84
   4841 DC FF              7398 	.byte #0xDC,#0xFF	; -36
   4843 7B 00              7399 	.byte #0x7B,#0x00	;  123
   4845 E2 FF              7400 	.byte #0xE2,#0xFF	; -30
   4847 2C                 7401 	.db #0x2C	;  44
   4848 C7 FF              7402 	.byte #0xC7,#0xFF	; -57
   484A 18 00              7403 	.byte #0x18,#0x00	;  24
   484C 54 00              7404 	.byte #0x54,#0x00	;  84
   484E D9 FF              7405 	.byte #0xD9,#0xFF	; -39
   4850 7B 00              7406 	.byte #0x7B,#0x00	;  123
   4852 DC FF              7407 	.byte #0xDC,#0xFF	; -36
   4854 33                 7408 	.db #0x33	;  51	'3'
                    0444   7409 Ftwitch_ax$limbs_4_4$0$0 == .
   4855                    7410 _limbs_4_4:
   4855 C7 FF              7411 	.byte #0xC7,#0xFF	; -57
   4857 00 00              7412 	.byte #0x00,#0x00	;  0
   4859 54 00              7413 	.byte #0x54,#0x00	;  84
   485B 00 00              7414 	.byte #0x00,#0x00	;  0
   485D 7B 00              7415 	.byte #0x7B,#0x00	;  123
   485F 00 00              7416 	.byte #0x00,#0x00	;  0
   4861 39                 7417 	.db #0x39	;  57	'9'
   4862 CA FF              7418 	.byte #0xCA,#0xFF	; -54
   4864 16 00              7419 	.byte #0x16,#0x00	;  22
   4866 51 00              7420 	.byte #0x51,#0x00	;  81
   4868 E2 FF              7421 	.byte #0xE2,#0xFF	; -30
   486A 7B 00              7422 	.byte #0x7B,#0x00	;  123
   486C DC FF              7423 	.byte #0xDC,#0xFF	; -36
   486E 00                 7424 	.db #0x00	;  0
   486F CA FF              7425 	.byte #0xCA,#0xFF	; -54
   4871 18 00              7426 	.byte #0x18,#0x00	;  24
   4873 51 00              7427 	.byte #0x51,#0x00	;  81
   4875 DF FF              7428 	.byte #0xDF,#0xFF	; -33
   4877 7B 00              7429 	.byte #0x7B,#0x00	;  123
   4879 D6 FF              7430 	.byte #0xD6,#0xFF	; -42
   487B 00                 7431 	.db #0x00	;  0
                    046B   7432 Ftwitch_ax$limbs_4_5$0$0 == .
   487C                    7433 _limbs_4_5:
   487C 95 FF              7434 	.byte #0x95,#0xFF	; -107
   487E 72 00              7435 	.byte #0x72,#0x00	;  114
   4880 72 00              7436 	.byte #0x72,#0x00	;  114
   4882 55 FF              7437 	.byte #0x55,#0xFF	; -171
   4884 5D 00              7438 	.byte #0x5D,#0x00	;  93
   4886 00 00              7439 	.byte #0x00,#0x00	;  0
   4888 39                 7440 	.db #0x39	;  57	'9'
   4889 DD FF              7441 	.byte #0xDD,#0xFF	; -35
   488B 17 00              7442 	.byte #0x17,#0x00	;  23
   488D 36 00              7443 	.byte #0x36,#0x00	;  54
   488F E8 FF              7444 	.byte #0xE8,#0xFF	; -24
   4891 51 00              7445 	.byte #0x51,#0x00	;  81
   4893 EB FF              7446 	.byte #0xEB,#0xFF	; -21
   4895 D4                 7447 	.db #0xD4	; -44	'Ô'
   4896 DD FF              7448 	.byte #0xDD,#0xFF	; -35
   4898 1A 00              7449 	.byte #0x1A,#0x00	;  26
   489A 36 00              7450 	.byte #0x36,#0x00	;  54
   489C E5 FF              7451 	.byte #0xE5,#0xFF	; -27
   489E 51 00              7452 	.byte #0x51,#0x00	;  81
   48A0 E8 FF              7453 	.byte #0xE8,#0xFF	; -24
   48A2 CD                 7454 	.db #0xCD	; -51	'Í'
                    0492   7455 Ftwitch_ax$limbs_4_6$0$0 == .
   48A3                    7456 _limbs_4_6:
   48A3 95 FF              7457 	.byte #0x95,#0xFF	; -107
   48A5 72 00              7458 	.byte #0x72,#0x00	;  114
   48A7 CF 00              7459 	.byte #0xCF,#0x00	;  207
   48A9 55 FF              7460 	.byte #0x55,#0xFF	; -171
   48AB 00 00              7461 	.byte #0x00,#0x00	;  0
   48AD 00 00              7462 	.byte #0x00,#0x00	;  0
   48AF 00                 7463 	.db #0x00	;  0
   48B0 DD FF              7464 	.byte #0xDD,#0xFF	; -35
   48B2 E9 FF              7465 	.byte #0xE9,#0xFF	; -23
   48B4 33 00              7466 	.byte #0x33,#0x00	;  51
   48B6 2D 00              7467 	.byte #0x2D,#0x00	;  45
   48B8 54 00              7468 	.byte #0x54,#0x00	;  84
   48BA 00 00              7469 	.byte #0x00,#0x00	;  0
   48BC BE                 7470 	.db #0xBE	; -66	'¾'
   48BD DD FF              7471 	.byte #0xDD,#0xFF	; -35
   48BF E6 FF              7472 	.byte #0xE6,#0xFF	; -26
   48C1 33 00              7473 	.byte #0x33,#0x00	;  51
   48C3 33 00              7474 	.byte #0x33,#0x00	;  51
   48C5 54 00              7475 	.byte #0x54,#0x00	;  84
   48C7 00 00              7476 	.byte #0x00,#0x00	;  0
   48C9 B4                 7477 	.db #0xB4	; -76	'´'
                    04B9   7478 Ftwitch_ax$limbs_4_7$0$0 == .
   48CA                    7479 _limbs_4_7:
   48CA CA FF              7480 	.byte #0xCA,#0xFF	; -54
   48CC 00 00              7481 	.byte #0x00,#0x00	;  0
   48CE 51 00              7482 	.byte #0x51,#0x00	;  81
   48D0 00 00              7483 	.byte #0x00,#0x00	;  0
   48D2 7B 00              7484 	.byte #0x7B,#0x00	;  123
   48D4 00 00              7485 	.byte #0x00,#0x00	;  0
   48D6 C7                 7486 	.db #0xC7	; -57	'Ç'
   48D7 CA FF              7487 	.byte #0xCA,#0xFF	; -54
   48D9 EA FF              7488 	.byte #0xEA,#0xFF	; -22
   48DB 51 00              7489 	.byte #0x51,#0x00	;  81
   48DD 24 00              7490 	.byte #0x24,#0x00	;  36
   48DF 7B 00              7491 	.byte #0x7B,#0x00	;  123
   48E1 1E 00              7492 	.byte #0x1E,#0x00	;  30
   48E3 D4                 7493 	.db #0xD4	; -44	'Ô'
   48E4 CA FF              7494 	.byte #0xCA,#0xFF	; -54
   48E6 E8 FF              7495 	.byte #0xE8,#0xFF	; -24
   48E8 51 00              7496 	.byte #0x51,#0x00	;  81
   48EA 27 00              7497 	.byte #0x27,#0x00	;  39
   48EC 7B 00              7498 	.byte #0x7B,#0x00	;  123
   48EE 24 00              7499 	.byte #0x24,#0x00	;  36
   48F0 CD                 7500 	.db #0xCD	; -51	'Í'
                    04E0   7501 Ftwitch_ax$limbs_5_0$0$0 == .
   48F1                    7502 _limbs_5_0:
   48F1 B5 FF              7503 	.byte #0xB5,#0xFF	; -75
   48F3 00 00              7504 	.byte #0x00,#0x00	;  0
   48F5 6F 00              7505 	.byte #0x6F,#0x00	;  111
   48F7 00 00              7506 	.byte #0x00,#0x00	;  0
   48F9 72 00              7507 	.byte #0x72,#0x00	;  114
   48FB 00 00              7508 	.byte #0x00,#0x00	;  0
   48FD C7                 7509 	.db #0xC7	; -57	'Ç'
   48FE B8 FF              7510 	.byte #0xB8,#0xFF	; -72
   4900 EF FF              7511 	.byte #0xEF,#0xFF	; -17
   4902 6C 00              7512 	.byte #0x6C,#0x00	;  108
   4904 15 00              7513 	.byte #0x15,#0x00	;  21
   4906 72 00              7514 	.byte #0x72,#0x00	;  114
   4908 09 00              7515 	.byte #0x09,#0x00	;  9
   490A 00                 7516 	.db #0x00	;  0
   490B B8 FF              7517 	.byte #0xB8,#0xFF	; -72
   490D 11 00              7518 	.byte #0x11,#0x00	;  17
   490F 6C 00              7519 	.byte #0x6C,#0x00	;  108
   4911 EB FF              7520 	.byte #0xEB,#0xFF	; -21
   4913 72 00              7521 	.byte #0x72,#0x00	;  114
   4915 F7 FF              7522 	.byte #0xF7,#0xFF	; -9
   4917 00                 7523 	.db #0x00	;  0
                    0507   7524 Ftwitch_ax$limbs_5_1$0$0 == .
   4918                    7525 _limbs_5_1:
   4918 CC FF              7526 	.byte #0xCC,#0xFF	; -52
   491A 1C FF              7527 	.byte #0x1C,#0xFF	; -228
   491C 4E 00              7528 	.byte #0x4E,#0x00	;  78
   491E 56 01              7529 	.byte #0x56,#0x01	;  342
   4920 AE 00              7530 	.byte #0xAE,#0x00	;  174
   4922 00 00              7531 	.byte #0x00,#0x00	;  0
   4924 C7                 7532 	.db #0xC7	; -57	'Ç'
   4925 9C FF              7533 	.byte #0x9C,#0xFF	; -100
   4927 00 00              7534 	.byte #0x00,#0x00	;  0
   4929 96 00              7535 	.byte #0x96,#0x00	;  150
   492B 00 00              7536 	.byte #0x00,#0x00	;  0
   492D 96 00              7537 	.byte #0x96,#0x00	;  150
   492F 00 00              7538 	.byte #0x00,#0x00	;  0
   4931 0D                 7539 	.db #0x0D	;  13
   4932 9C FF              7540 	.byte #0x9C,#0xFF	; -100
   4934 00 00              7541 	.byte #0x00,#0x00	;  0
   4936 96 00              7542 	.byte #0x96,#0x00	;  150
   4938 00 00              7543 	.byte #0x00,#0x00	;  0
   493A 96 00              7544 	.byte #0x96,#0x00	;  150
   493C 00 00              7545 	.byte #0x00,#0x00	;  0
   493E F3                 7546 	.db #0xF3	; -13	'ó'
                    052E   7547 Ftwitch_ax$limbs_5_2$0$0 == .
   493F                    7548 _limbs_5_2:
   493F B5 FF              7549 	.byte #0xB5,#0xFF	; -75
   4941 00 00              7550 	.byte #0x00,#0x00	;  0
   4943 6F 00              7551 	.byte #0x6F,#0x00	;  111
   4945 00 00              7552 	.byte #0x00,#0x00	;  0
   4947 72 00              7553 	.byte #0x72,#0x00	;  114
   4949 00 00              7554 	.byte #0x00,#0x00	;  0
   494B 39                 7555 	.db #0x39	;  57	'9'
   494C B5 FF              7556 	.byte #0xB5,#0xFF	; -75
   494E 11 00              7557 	.byte #0x11,#0x00	;  17
   4950 6F 00              7558 	.byte #0x6F,#0x00	;  111
   4952 E2 FF              7559 	.byte #0xE2,#0xFF	; -30
   4954 72 00              7560 	.byte #0x72,#0x00	;  114
   4956 00 00              7561 	.byte #0x00,#0x00	;  0
   4958 0D                 7562 	.db #0x0D	;  13
   4959 B5 FF              7563 	.byte #0xB5,#0xFF	; -75
   495B EF FF              7564 	.byte #0xEF,#0xFF	; -17
   495D 6F 00              7565 	.byte #0x6F,#0x00	;  111
   495F 1E 00              7566 	.byte #0x1E,#0x00	;  30
   4961 72 00              7567 	.byte #0x72,#0x00	;  114
   4963 00 00              7568 	.byte #0x00,#0x00	;  0
   4965 F3                 7569 	.db #0xF3	; -13	'ó'
                    0555   7570 Ftwitch_ax$limbs_5_3$0$0 == .
   4966                    7571 _limbs_5_3:
   4966 B5 FF              7572 	.byte #0xB5,#0xFF	; -75
   4968 00 00              7573 	.byte #0x00,#0x00	;  0
   496A 6F 00              7574 	.byte #0x6F,#0x00	;  111
   496C 00 00              7575 	.byte #0x00,#0x00	;  0
   496E 72 00              7576 	.byte #0x72,#0x00	;  114
   4970 00 00              7577 	.byte #0x00,#0x00	;  0
   4972 39                 7578 	.db #0x39	;  57	'9'
   4973 B8 FF              7579 	.byte #0xB8,#0xFF	; -72
   4975 11 00              7580 	.byte #0x11,#0x00	;  17
   4977 6C 00              7581 	.byte #0x6C,#0x00	;  108
   4979 EB FF              7582 	.byte #0xEB,#0xFF	; -21
   497B 72 00              7583 	.byte #0x72,#0x00	;  114
   497D F7 FF              7584 	.byte #0xF7,#0xFF	; -9
   497F 00                 7585 	.db #0x00	;  0
   4980 B8 FF              7586 	.byte #0xB8,#0xFF	; -72
   4982 EF FF              7587 	.byte #0xEF,#0xFF	; -17
   4984 6C 00              7588 	.byte #0x6C,#0x00	;  108
   4986 15 00              7589 	.byte #0x15,#0x00	;  21
   4988 72 00              7590 	.byte #0x72,#0x00	;  114
   498A 09 00              7591 	.byte #0x09,#0x00	;  9
   498C 00                 7592 	.db #0x00	;  0
                    057C   7593 Ftwitch_ax$limbs_5_4$0$0 == .
   498D                    7594 _limbs_5_4:
   498D CC FF              7595 	.byte #0xCC,#0xFF	; -52
   498F E4 00              7596 	.byte #0xE4,#0x00	;  228
   4991 4E 00              7597 	.byte #0x4E,#0x00	;  78
   4993 AA FE              7598 	.byte #0xAA,#0xFE	; -342
   4995 AE 00              7599 	.byte #0xAE,#0x00	;  174
   4997 00 00              7600 	.byte #0x00,#0x00	;  0
   4999 39                 7601 	.db #0x39	;  57	'9'
   499A 9C FF              7602 	.byte #0x9C,#0xFF	; -100
   499C 00 00              7603 	.byte #0x00,#0x00	;  0
   499E 96 00              7604 	.byte #0x96,#0x00	;  150
   49A0 00 00              7605 	.byte #0x00,#0x00	;  0
   49A2 96 00              7606 	.byte #0x96,#0x00	;  150
   49A4 00 00              7607 	.byte #0x00,#0x00	;  0
   49A6 F3                 7608 	.db #0xF3	; -13	'ó'
   49A7 9C FF              7609 	.byte #0x9C,#0xFF	; -100
   49A9 00 00              7610 	.byte #0x00,#0x00	;  0
   49AB 96 00              7611 	.byte #0x96,#0x00	;  150
   49AD 00 00              7612 	.byte #0x00,#0x00	;  0
   49AF 96 00              7613 	.byte #0x96,#0x00	;  150
   49B1 00 00              7614 	.byte #0x00,#0x00	;  0
   49B3 0D                 7615 	.db #0x0D	;  13
                    05A3   7616 Ftwitch_ax$limbs_5_5$0$0 == .
   49B4                    7617 _limbs_5_5:
   49B4 B8 FF              7618 	.byte #0xB8,#0xFF	; -72
   49B6 00 00              7619 	.byte #0x00,#0x00	;  0
   49B8 6C 00              7620 	.byte #0x6C,#0x00	;  108
   49BA 00 00              7621 	.byte #0x00,#0x00	;  0
   49BC 72 00              7622 	.byte #0x72,#0x00	;  114
   49BE 00 00              7623 	.byte #0x00,#0x00	;  0
   49C0 C7                 7624 	.db #0xC7	; -57	'Ç'
   49C1 B8 FF              7625 	.byte #0xB8,#0xFF	; -72
   49C3 EF FF              7626 	.byte #0xEF,#0xFF	; -17
   49C5 6C 00              7627 	.byte #0x6C,#0x00	;  108
   49C7 1E 00              7628 	.byte #0x1E,#0x00	;  30
   49C9 72 00              7629 	.byte #0x72,#0x00	;  114
   49CB 00 00              7630 	.byte #0x00,#0x00	;  0
   49CD F3                 7631 	.db #0xF3	; -13	'ó'
   49CE B8 FF              7632 	.byte #0xB8,#0xFF	; -72
   49D0 11 00              7633 	.byte #0x11,#0x00	;  17
   49D2 6C 00              7634 	.byte #0x6C,#0x00	;  108
   49D4 E2 FF              7635 	.byte #0xE2,#0xFF	; -30
   49D6 72 00              7636 	.byte #0x72,#0x00	;  114
   49D8 00 00              7637 	.byte #0x00,#0x00	;  0
   49DA 0D                 7638 	.db #0x0D	;  13
                    05CA   7639 Ftwitch_ax$limbs_6_0$0$0 == .
   49DB                    7640 _limbs_6_0:
   49DB C7 FF              7641 	.byte #0xC7,#0xFF	; -57
   49DD 00 00              7642 	.byte #0x00,#0x00	;  0
   49DF 54 00              7643 	.byte #0x54,#0x00	;  84
   49E1 00 00              7644 	.byte #0x00,#0x00	;  0
   49E3 7B 00              7645 	.byte #0x7B,#0x00	;  123
   49E5 00 00              7646 	.byte #0x00,#0x00	;  0
   49E7 C7                 7647 	.db #0xC7	; -57	'Ç'
   49E8 CA FF              7648 	.byte #0xCA,#0xFF	; -54
   49EA 16 00              7649 	.byte #0x16,#0x00	;  22
   49EC 51 00              7650 	.byte #0x51,#0x00	;  81
   49EE E2 FF              7651 	.byte #0xE2,#0xFF	; -30
   49F0 7B 00              7652 	.byte #0x7B,#0x00	;  123
   49F2 DC FF              7653 	.byte #0xDC,#0xFF	; -36
   49F4 00                 7654 	.db #0x00	;  0
   49F5 CA FF              7655 	.byte #0xCA,#0xFF	; -54
   49F7 18 00              7656 	.byte #0x18,#0x00	;  24
   49F9 51 00              7657 	.byte #0x51,#0x00	;  81
   49FB DF FF              7658 	.byte #0xDF,#0xFF	; -33
   49FD 7B 00              7659 	.byte #0x7B,#0x00	;  123
   49FF D6 FF              7660 	.byte #0xD6,#0xFF	; -42
   4A01 00                 7661 	.db #0x00	;  0
                    05F1   7662 Ftwitch_ax$limbs_6_1$0$0 == .
   4A02                    7663 _limbs_6_1:
   4A02 95 FF              7664 	.byte #0x95,#0xFF	; -107
   4A04 8E FF              7665 	.byte #0x8E,#0xFF	; -114
   4A06 72 00              7666 	.byte #0x72,#0x00	;  114
   4A08 AB 00              7667 	.byte #0xAB,#0x00	;  171
   4A0A 5D 00              7668 	.byte #0x5D,#0x00	;  93
   4A0C 00 00              7669 	.byte #0x00,#0x00	;  0
   4A0E C7                 7670 	.db #0xC7	; -57	'Ç'
   4A0F DD FF              7671 	.byte #0xDD,#0xFF	; -35
   4A11 17 00              7672 	.byte #0x17,#0x00	;  23
   4A13 36 00              7673 	.byte #0x36,#0x00	;  54
   4A15 E8 FF              7674 	.byte #0xE8,#0xFF	; -24
   4A17 51 00              7675 	.byte #0x51,#0x00	;  81
   4A19 EB FF              7676 	.byte #0xEB,#0xFF	; -21
   4A1B D4                 7677 	.db #0xD4	; -44	'Ô'
   4A1C DD FF              7678 	.byte #0xDD,#0xFF	; -35
   4A1E 1A 00              7679 	.byte #0x1A,#0x00	;  26
   4A20 36 00              7680 	.byte #0x36,#0x00	;  54
   4A22 E5 FF              7681 	.byte #0xE5,#0xFF	; -27
   4A24 51 00              7682 	.byte #0x51,#0x00	;  81
   4A26 E8 FF              7683 	.byte #0xE8,#0xFF	; -24
   4A28 CD                 7684 	.db #0xCD	; -51	'Í'
                    0618   7685 Ftwitch_ax$limbs_6_2$0$0 == .
   4A29                    7686 _limbs_6_2:
   4A29 95 FF              7687 	.byte #0x95,#0xFF	; -107
   4A2B 8E FF              7688 	.byte #0x8E,#0xFF	; -114
   4A2D CF 00              7689 	.byte #0xCF,#0x00	;  207
   4A2F AB 00              7690 	.byte #0xAB,#0x00	;  171
   4A31 00 00              7691 	.byte #0x00,#0x00	;  0
   4A33 00 00              7692 	.byte #0x00,#0x00	;  0
   4A35 00                 7693 	.db #0x00	;  0
   4A36 DD FF              7694 	.byte #0xDD,#0xFF	; -35
   4A38 E9 FF              7695 	.byte #0xE9,#0xFF	; -23
   4A3A 33 00              7696 	.byte #0x33,#0x00	;  51
   4A3C 2D 00              7697 	.byte #0x2D,#0x00	;  45
   4A3E 54 00              7698 	.byte #0x54,#0x00	;  84
   4A40 00 00              7699 	.byte #0x00,#0x00	;  0
   4A42 BE                 7700 	.db #0xBE	; -66	'¾'
   4A43 DD FF              7701 	.byte #0xDD,#0xFF	; -35
   4A45 E6 FF              7702 	.byte #0xE6,#0xFF	; -26
   4A47 33 00              7703 	.byte #0x33,#0x00	;  51
   4A49 33 00              7704 	.byte #0x33,#0x00	;  51
   4A4B 54 00              7705 	.byte #0x54,#0x00	;  84
   4A4D 00 00              7706 	.byte #0x00,#0x00	;  0
   4A4F B4                 7707 	.db #0xB4	; -76	'´'
                    063F   7708 Ftwitch_ax$limbs_6_3$0$0 == .
   4A50                    7709 _limbs_6_3:
   4A50 C7 FF              7710 	.byte #0xC7,#0xFF	; -57
   4A52 00 00              7711 	.byte #0x00,#0x00	;  0
   4A54 54 00              7712 	.byte #0x54,#0x00	;  84
   4A56 00 00              7713 	.byte #0x00,#0x00	;  0
   4A58 7B 00              7714 	.byte #0x7B,#0x00	;  123
   4A5A 00 00              7715 	.byte #0x00,#0x00	;  0
   4A5C 39                 7716 	.db #0x39	;  57	'9'
   4A5D C7 FF              7717 	.byte #0xC7,#0xFF	; -57
   4A5F EA FF              7718 	.byte #0xEA,#0xFF	; -22
   4A61 54 00              7719 	.byte #0x54,#0x00	;  84
   4A63 24 00              7720 	.byte #0x24,#0x00	;  36
   4A65 7B 00              7721 	.byte #0x7B,#0x00	;  123
   4A67 1E 00              7722 	.byte #0x1E,#0x00	;  30
   4A69 D4                 7723 	.db #0xD4	; -44	'Ô'
   4A6A C7 FF              7724 	.byte #0xC7,#0xFF	; -57
   4A6C E8 FF              7725 	.byte #0xE8,#0xFF	; -24
   4A6E 54 00              7726 	.byte #0x54,#0x00	;  84
   4A70 27 00              7727 	.byte #0x27,#0x00	;  39
   4A72 7B 00              7728 	.byte #0x7B,#0x00	;  123
   4A74 24 00              7729 	.byte #0x24,#0x00	;  36
   4A76 CD                 7730 	.db #0xCD	; -51	'Í'
                    0666   7731 Ftwitch_ax$limbs_6_4$0$0 == .
   4A77                    7732 _limbs_6_4:
   4A77 C7 FF              7733 	.byte #0xC7,#0xFF	; -57
   4A79 00 00              7734 	.byte #0x00,#0x00	;  0
   4A7B 54 00              7735 	.byte #0x54,#0x00	;  84
   4A7D 00 00              7736 	.byte #0x00,#0x00	;  0
   4A7F 7B 00              7737 	.byte #0x7B,#0x00	;  123
   4A81 00 00              7738 	.byte #0x00,#0x00	;  0
   4A83 39                 7739 	.db #0x39	;  57	'9'
   4A84 CA FF              7740 	.byte #0xCA,#0xFF	; -54
   4A86 EA FF              7741 	.byte #0xEA,#0xFF	; -22
   4A88 51 00              7742 	.byte #0x51,#0x00	;  81
   4A8A 1E 00              7743 	.byte #0x1E,#0x00	;  30
   4A8C 7B 00              7744 	.byte #0x7B,#0x00	;  123
   4A8E 24 00              7745 	.byte #0x24,#0x00	;  36
   4A90 00                 7746 	.db #0x00	;  0
   4A91 CA FF              7747 	.byte #0xCA,#0xFF	; -54
   4A93 E8 FF              7748 	.byte #0xE8,#0xFF	; -24
   4A95 51 00              7749 	.byte #0x51,#0x00	;  81
   4A97 21 00              7750 	.byte #0x21,#0x00	;  33
   4A99 7B 00              7751 	.byte #0x7B,#0x00	;  123
   4A9B 2A 00              7752 	.byte #0x2A,#0x00	;  42
   4A9D 00                 7753 	.db #0x00	;  0
                    068D   7754 Ftwitch_ax$limbs_6_5$0$0 == .
   4A9E                    7755 _limbs_6_5:
   4A9E 95 FF              7756 	.byte #0x95,#0xFF	; -107
   4AA0 72 00              7757 	.byte #0x72,#0x00	;  114
   4AA2 72 00              7758 	.byte #0x72,#0x00	;  114
   4AA4 55 FF              7759 	.byte #0x55,#0xFF	; -171
   4AA6 5D 00              7760 	.byte #0x5D,#0x00	;  93
   4AA8 00 00              7761 	.byte #0x00,#0x00	;  0
   4AAA 39                 7762 	.db #0x39	;  57	'9'
   4AAB DD FF              7763 	.byte #0xDD,#0xFF	; -35
   4AAD E9 FF              7764 	.byte #0xE9,#0xFF	; -23
   4AAF 36 00              7765 	.byte #0x36,#0x00	;  54
   4AB1 18 00              7766 	.byte #0x18,#0x00	;  24
   4AB3 51 00              7767 	.byte #0x51,#0x00	;  81
   4AB5 15 00              7768 	.byte #0x15,#0x00	;  21
   4AB7 2C                 7769 	.db #0x2C	;  44
   4AB8 DD FF              7770 	.byte #0xDD,#0xFF	; -35
   4ABA E6 FF              7771 	.byte #0xE6,#0xFF	; -26
   4ABC 36 00              7772 	.byte #0x36,#0x00	;  54
   4ABE 1B 00              7773 	.byte #0x1B,#0x00	;  27
   4AC0 51 00              7774 	.byte #0x51,#0x00	;  81
   4AC2 18 00              7775 	.byte #0x18,#0x00	;  24
   4AC4 33                 7776 	.db #0x33	;  51	'3'
                    06B4   7777 Ftwitch_ax$limbs_6_6$0$0 == .
   4AC5                    7778 _limbs_6_6:
   4AC5 95 FF              7779 	.byte #0x95,#0xFF	; -107
   4AC7 72 00              7780 	.byte #0x72,#0x00	;  114
   4AC9 CF 00              7781 	.byte #0xCF,#0x00	;  207
   4ACB 55 FF              7782 	.byte #0x55,#0xFF	; -171
   4ACD 00 00              7783 	.byte #0x00,#0x00	;  0
   4ACF 00 00              7784 	.byte #0x00,#0x00	;  0
   4AD1 00                 7785 	.db #0x00	;  0
   4AD2 DD FF              7786 	.byte #0xDD,#0xFF	; -35
   4AD4 17 00              7787 	.byte #0x17,#0x00	;  23
   4AD6 33 00              7788 	.byte #0x33,#0x00	;  51
   4AD8 D3 FF              7789 	.byte #0xD3,#0xFF	; -45
   4ADA 54 00              7790 	.byte #0x54,#0x00	;  84
   4ADC 00 00              7791 	.byte #0x00,#0x00	;  0
   4ADE 42                 7792 	.db #0x42	;  66	'B'
   4ADF DD FF              7793 	.byte #0xDD,#0xFF	; -35
   4AE1 1A 00              7794 	.byte #0x1A,#0x00	;  26
   4AE3 33 00              7795 	.byte #0x33,#0x00	;  51
   4AE5 CD FF              7796 	.byte #0xCD,#0xFF	; -51
   4AE7 54 00              7797 	.byte #0x54,#0x00	;  84
   4AE9 00 00              7798 	.byte #0x00,#0x00	;  0
   4AEB 4C                 7799 	.db #0x4C	;  76	'L'
                    06DB   7800 Ftwitch_ax$limbs_6_7$0$0 == .
   4AEC                    7801 _limbs_6_7:
   4AEC CA FF              7802 	.byte #0xCA,#0xFF	; -54
   4AEE 00 00              7803 	.byte #0x00,#0x00	;  0
   4AF0 51 00              7804 	.byte #0x51,#0x00	;  81
   4AF2 00 00              7805 	.byte #0x00,#0x00	;  0
   4AF4 7B 00              7806 	.byte #0x7B,#0x00	;  123
   4AF6 00 00              7807 	.byte #0x00,#0x00	;  0
   4AF8 C7                 7808 	.db #0xC7	; -57	'Ç'
   4AF9 CA FF              7809 	.byte #0xCA,#0xFF	; -54
   4AFB 16 00              7810 	.byte #0x16,#0x00	;  22
   4AFD 51 00              7811 	.byte #0x51,#0x00	;  81
   4AFF DC FF              7812 	.byte #0xDC,#0xFF	; -36
   4B01 7B 00              7813 	.byte #0x7B,#0x00	;  123
   4B03 E2 FF              7814 	.byte #0xE2,#0xFF	; -30
   4B05 2C                 7815 	.db #0x2C	;  44
   4B06 CA FF              7816 	.byte #0xCA,#0xFF	; -54
   4B08 18 00              7817 	.byte #0x18,#0x00	;  24
   4B0A 51 00              7818 	.byte #0x51,#0x00	;  81
   4B0C D9 FF              7819 	.byte #0xD9,#0xFF	; -39
   4B0E 7B 00              7820 	.byte #0x7B,#0x00	;  123
   4B10 DC FF              7821 	.byte #0xDC,#0xFF	; -36
   4B12 33                 7822 	.db #0x33	;  51	'3'
                    0702   7823 Ftwitch_ax$frames_0$0$0 == .
   4B13                    7824 _frames_0:
   4B13 00 00              7825 	.byte #0x00,#0x00	; 0
   4B15 11 44 80           7826 	.byte _limbs_0_0,(_limbs_0_0 >> 8),#0x80
   4B18 96 00              7827 	.byte #0x96,#0x00	; 150
   4B1A 38 44 80           7828 	.byte _limbs_0_1,(_limbs_0_1 >> 8),#0x80
   4B1D FA 00              7829 	.byte #0xFA,#0x00	; 250
   4B1F 5F 44 80           7830 	.byte _limbs_0_2,(_limbs_0_2 >> 8),#0x80
   4B22 5E 01              7831 	.byte #0x5E,#0x01	; 350
   4B24 86 44 80           7832 	.byte _limbs_0_3,(_limbs_0_3 >> 8),#0x80
   4B27 F4 01              7833 	.byte #0xF4,#0x01	; 500
   4B29 AD 44 80           7834 	.byte _limbs_0_4,(_limbs_0_4 >> 8),#0x80
   4B2C 8A 02              7835 	.byte #0x8A,#0x02	; 650
   4B2E D4 44 80           7836 	.byte _limbs_0_5,(_limbs_0_5 >> 8),#0x80
   4B31 EE 02              7837 	.byte #0xEE,#0x02	; 750
   4B33 FB 44 80           7838 	.byte _limbs_0_6,(_limbs_0_6 >> 8),#0x80
   4B36 52 03              7839 	.byte #0x52,#0x03	; 850
   4B38 22 45 80           7840 	.byte _limbs_0_7,(_limbs_0_7 >> 8),#0x80
                    072A   7841 Ftwitch_ax$frames_1$0$0 == .
   4B3B                    7842 _frames_1:
   4B3B 00 00              7843 	.byte #0x00,#0x00	; 0
   4B3D 49 45 80           7844 	.byte _limbs_1_0,(_limbs_1_0 >> 8),#0x80
   4B40 E8 03              7845 	.byte #0xE8,#0x03	; 1000
   4B42 70 45 80           7846 	.byte _limbs_1_1,(_limbs_1_1 >> 8),#0x80
                    0734   7847 Ftwitch_ax$frames_2$0$0 == .
   4B45                    7848 _frames_2:
   4B45 00 00              7849 	.byte #0x00,#0x00	; 0
   4B47 97 45 80           7850 	.byte _limbs_2_0,(_limbs_2_0 >> 8),#0x80
   4B4A 96 00              7851 	.byte #0x96,#0x00	; 150
   4B4C BE 45 80           7852 	.byte _limbs_2_1,(_limbs_2_1 >> 8),#0x80
   4B4F 5E 01              7853 	.byte #0x5E,#0x01	; 350
   4B51 E5 45 80           7854 	.byte _limbs_2_2,(_limbs_2_2 >> 8),#0x80
   4B54 F4 01              7855 	.byte #0xF4,#0x01	; 500
   4B56 0C 46 80           7856 	.byte _limbs_2_3,(_limbs_2_3 >> 8),#0x80
   4B59 8A 02              7857 	.byte #0x8A,#0x02	; 650
   4B5B 33 46 80           7858 	.byte _limbs_2_4,(_limbs_2_4 >> 8),#0x80
   4B5E 52 03              7859 	.byte #0x52,#0x03	; 850
   4B60 5A 46 80           7860 	.byte _limbs_2_5,(_limbs_2_5 >> 8),#0x80
                    0752   7861 Ftwitch_ax$frames_3$0$0 == .
   4B63                    7862 _frames_3:
   4B63 00 00              7863 	.byte #0x00,#0x00	; 0
   4B65 81 46 80           7864 	.byte _limbs_3_0,(_limbs_3_0 >> 8),#0x80
   4B68 96 00              7865 	.byte #0x96,#0x00	; 150
   4B6A A8 46 80           7866 	.byte _limbs_3_1,(_limbs_3_1 >> 8),#0x80
   4B6D FA 00              7867 	.byte #0xFA,#0x00	; 250
   4B6F CF 46 80           7868 	.byte _limbs_3_2,(_limbs_3_2 >> 8),#0x80
   4B72 5E 01              7869 	.byte #0x5E,#0x01	; 350
   4B74 F6 46 80           7870 	.byte _limbs_3_3,(_limbs_3_3 >> 8),#0x80
   4B77 F4 01              7871 	.byte #0xF4,#0x01	; 500
   4B79 1D 47 80           7872 	.byte _limbs_3_4,(_limbs_3_4 >> 8),#0x80
   4B7C 8A 02              7873 	.byte #0x8A,#0x02	; 650
   4B7E 44 47 80           7874 	.byte _limbs_3_5,(_limbs_3_5 >> 8),#0x80
   4B81 EE 02              7875 	.byte #0xEE,#0x02	; 750
   4B83 6B 47 80           7876 	.byte _limbs_3_6,(_limbs_3_6 >> 8),#0x80
   4B86 52 03              7877 	.byte #0x52,#0x03	; 850
   4B88 92 47 80           7878 	.byte _limbs_3_7,(_limbs_3_7 >> 8),#0x80
                    077A   7879 Ftwitch_ax$frames_4$0$0 == .
   4B8B                    7880 _frames_4:
   4B8B 00 00              7881 	.byte #0x00,#0x00	; 0
   4B8D B9 47 80           7882 	.byte _limbs_4_0,(_limbs_4_0 >> 8),#0x80
   4B90 96 00              7883 	.byte #0x96,#0x00	; 150
   4B92 E0 47 80           7884 	.byte _limbs_4_1,(_limbs_4_1 >> 8),#0x80
   4B95 FA 00              7885 	.byte #0xFA,#0x00	; 250
   4B97 07 48 80           7886 	.byte _limbs_4_2,(_limbs_4_2 >> 8),#0x80
   4B9A 5E 01              7887 	.byte #0x5E,#0x01	; 350
   4B9C 2E 48 80           7888 	.byte _limbs_4_3,(_limbs_4_3 >> 8),#0x80
   4B9F F4 01              7889 	.byte #0xF4,#0x01	; 500
   4BA1 55 48 80           7890 	.byte _limbs_4_4,(_limbs_4_4 >> 8),#0x80
   4BA4 8A 02              7891 	.byte #0x8A,#0x02	; 650
   4BA6 7C 48 80           7892 	.byte _limbs_4_5,(_limbs_4_5 >> 8),#0x80
   4BA9 EE 02              7893 	.byte #0xEE,#0x02	; 750
   4BAB A3 48 80           7894 	.byte _limbs_4_6,(_limbs_4_6 >> 8),#0x80
   4BAE 52 03              7895 	.byte #0x52,#0x03	; 850
   4BB0 CA 48 80           7896 	.byte _limbs_4_7,(_limbs_4_7 >> 8),#0x80
                    07A2   7897 Ftwitch_ax$frames_5$0$0 == .
   4BB3                    7898 _frames_5:
   4BB3 00 00              7899 	.byte #0x00,#0x00	; 0
   4BB5 F1 48 80           7900 	.byte _limbs_5_0,(_limbs_5_0 >> 8),#0x80
   4BB8 96 00              7901 	.byte #0x96,#0x00	; 150
   4BBA 18 49 80           7902 	.byte _limbs_5_1,(_limbs_5_1 >> 8),#0x80
   4BBD 5E 01              7903 	.byte #0x5E,#0x01	; 350
   4BBF 3F 49 80           7904 	.byte _limbs_5_2,(_limbs_5_2 >> 8),#0x80
   4BC2 F4 01              7905 	.byte #0xF4,#0x01	; 500
   4BC4 66 49 80           7906 	.byte _limbs_5_3,(_limbs_5_3 >> 8),#0x80
   4BC7 8A 02              7907 	.byte #0x8A,#0x02	; 650
   4BC9 8D 49 80           7908 	.byte _limbs_5_4,(_limbs_5_4 >> 8),#0x80
   4BCC 52 03              7909 	.byte #0x52,#0x03	; 850
   4BCE B4 49 80           7910 	.byte _limbs_5_5,(_limbs_5_5 >> 8),#0x80
                    07C0   7911 Ftwitch_ax$frames_6$0$0 == .
   4BD1                    7912 _frames_6:
   4BD1 00 00              7913 	.byte #0x00,#0x00	; 0
   4BD3 DB 49 80           7914 	.byte _limbs_6_0,(_limbs_6_0 >> 8),#0x80
   4BD6 96 00              7915 	.byte #0x96,#0x00	; 150
   4BD8 02 4A 80           7916 	.byte _limbs_6_1,(_limbs_6_1 >> 8),#0x80
   4BDB FA 00              7917 	.byte #0xFA,#0x00	; 250
   4BDD 29 4A 80           7918 	.byte _limbs_6_2,(_limbs_6_2 >> 8),#0x80
   4BE0 5E 01              7919 	.byte #0x5E,#0x01	; 350
   4BE2 50 4A 80           7920 	.byte _limbs_6_3,(_limbs_6_3 >> 8),#0x80
   4BE5 F4 01              7921 	.byte #0xF4,#0x01	; 500
   4BE7 77 4A 80           7922 	.byte _limbs_6_4,(_limbs_6_4 >> 8),#0x80
   4BEA 8A 02              7923 	.byte #0x8A,#0x02	; 650
   4BEC 9E 4A 80           7924 	.byte _limbs_6_5,(_limbs_6_5 >> 8),#0x80
   4BEF EE 02              7925 	.byte #0xEE,#0x02	; 750
   4BF1 C5 4A 80           7926 	.byte _limbs_6_6,(_limbs_6_6 >> 8),#0x80
   4BF4 52 03              7927 	.byte #0x52,#0x03	; 850
   4BF6 EC 4A 80           7928 	.byte _limbs_6_7,(_limbs_6_7 >> 8),#0x80
                    07E8   7929 G$animations$0$0 == .
   4BF9                    7930 _animations:
   4BF9 08                 7931 	.db #0x08	; 8
   4BFA 13 4B 80           7932 	.byte _frames_0,(_frames_0 >> 8),#0x80
   4BFD 00                 7933 	.db #0x00	; 0
   4BFE 02                 7934 	.db #0x02	; 2
   4BFF 3B 4B 80           7935 	.byte _frames_1,(_frames_1 >> 8),#0x80
   4C02 02                 7936 	.db #0x02	; 2
   4C03 06                 7937 	.db #0x06	; 6
   4C04 45 4B 80           7938 	.byte _frames_2,(_frames_2 >> 8),#0x80
   4C07 00                 7939 	.db #0x00	; 0
   4C08 08                 7940 	.db #0x08	; 8
   4C09 63 4B 80           7941 	.byte _frames_3,(_frames_3 >> 8),#0x80
   4C0C 00                 7942 	.db #0x00	; 0
   4C0D 08                 7943 	.db #0x08	; 8
   4C0E 8B 4B 80           7944 	.byte _frames_4,(_frames_4 >> 8),#0x80
   4C11 00                 7945 	.db #0x00	; 0
   4C12 06                 7946 	.db #0x06	; 6
   4C13 B3 4B 80           7947 	.byte _frames_5,(_frames_5 >> 8),#0x80
   4C16 00                 7948 	.db #0x00	; 0
   4C17 08                 7949 	.db #0x08	; 8
   4C18 D1 4B 80           7950 	.byte _frames_6,(_frames_6 >> 8),#0x80
   4C1B 00                 7951 	.db #0x00	; 0
                    080B   7952 G$param_serial_mode$0$0 == .
   4C1C                    7953 _param_serial_mode:
   4C1C 02 00 00 00        7954 	.byte #0x02,#0x00,#0x00,#0x00	;  2
                    080F   7955 G$param_baud_rate$0$0 == .
   4C20                    7956 _param_baud_rate:
   4C20 40 42 0F 00        7957 	.byte #0x40,#0x42,#0x0F,#0x00	;  1000000
                    0813   7958 G$param_nDTR_pin$0$0 == .
   4C24                    7959 _param_nDTR_pin:
   4C24 0A 00 00 00        7960 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    0817   7961 G$param_nRTS_pin$0$0 == .
   4C28                    7962 _param_nRTS_pin:
   4C28 0B 00 00 00        7963 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    081B   7964 G$param_nDSR_pin$0$0 == .
   4C2C                    7965 _param_nDSR_pin:
   4C2C 0C 00 00 00        7966 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    081F   7967 G$param_nCD_pin$0$0 == .
   4C30                    7968 _param_nCD_pin:
   4C30 0D 00 00 00        7969 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0823   7970 G$param_DTR_pin$0$0 == .
   4C34                    7971 _param_DTR_pin:
   4C34 FF FF FF FF        7972 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0827   7973 G$param_RTS_pin$0$0 == .
   4C38                    7974 _param_RTS_pin:
   4C38 FF FF FF FF        7975 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    082B   7976 G$param_DSR_pin$0$0 == .
   4C3C                    7977 _param_DSR_pin:
   4C3C FF FF FF FF        7978 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    082F   7979 G$param_CD_pin$0$0 == .
   4C40                    7980 _param_CD_pin:
   4C40 FF FF FF FF        7981 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0833   7982 G$param_arduino_DTR_pin$0$0 == .
   4C44                    7983 _param_arduino_DTR_pin:
   4C44 00 00 00 00        7984 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0837   7985 G$param_framing_error_ms$0$0 == .
   4C48                    7986 _param_framing_error_ms:
   4C48 00 00 00 00        7987 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    083B   7988 G$g8loopSpeed$0$0 == .
   4C4C                    7989 _g8loopSpeed:
   4C4C E8 03              7990 	.byte #0xE8,#0x03	; 1000
                           7991 	.area XINIT   (CODE)
                           7992 	.area CABS    (ABS,CODE)
