                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:38 2012
                              5 ;--------------------------------------------------------
                              6 	.module dynamixel_test
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
                             25 	.globl _updateSerialMode
                             26 	.globl _errorService
                             27 	.globl _errorOccurred
                             28 	.globl _ioTxSignals
                             29 	.globl _ioRxSignals
                             30 	.globl _updateLeds
                             31 	.globl _dynamixel_writeword
                             32 	.globl _dynamixel_init
                             33 	.globl _uart1SetBaudRate
                             34 	.globl _uart1Init
                             35 	.globl _isPinHigh
                             36 	.globl _setDigitalOutput
                             37 	.globl _delayMs
                             38 	.globl _getMs
                             39 	.globl _boardService
                             40 	.globl _systemInit
                             41 	.globl _interpolate_PARM_5
                             42 	.globl _interpolate_PARM_4
                             43 	.globl _interpolate_PARM_3
                             44 	.globl _interpolate_PARM_2
                             45 	.globl _lastErrorTime
                             46 	.globl _walkDIR
                             47 	.globl _walkSPD
                             48 	.globl _lookH
                             49 	.globl _lookV
                             50 	.globl _walkH
                             51 	.globl _walkV
                             52 	.globl _southpaw
                             53 	.globl _checksum_cmdr
                             54 	.globl _index_cmdr
                             55 	.globl _vals
                             56 	.globl _tilt_add
                             57 	.globl _pan_add
                             58 	.globl _panic
                             59 	.globl _flopCnt
                             60 	.globl _kneeling
                             61 	.globl _light
                             62 	.globl _turn
                             63 	.globl _walk
                             64 	.globl _agitbutton
                             65 	.globl _infobutton
                             66 	.globl _panicbutton
                             67 	.globl _gunbutton
                             68 	.globl _turnleft
                             69 	.globl _turnright
                             70 	.globl _pan_pos
                             71 	.globl _tilt_pos
                             72 	.globl _d_pan
                             73 	.globl _d_tilt
                             74 	.globl _errorOccurredRecently
                             75 	.globl _framingErrorActive
                             76 	.globl _uartRxDisabled
                             77 	.globl _currentSerialMode
                             78 	.globl _interpolate
                             79 ;--------------------------------------------------------
                             80 ; special function registers
                             81 ;--------------------------------------------------------
                             82 	.area RSEG    (ABS,DATA)
   0000                      83 	.org 0x0000
                    0080     84 Fdynamixel_test$P0$0$0 == 0x0080
                    0080     85 _P0	=	0x0080
                    0081     86 Fdynamixel_test$SP$0$0 == 0x0081
                    0081     87 _SP	=	0x0081
                    0082     88 Fdynamixel_test$DPL0$0$0 == 0x0082
                    0082     89 _DPL0	=	0x0082
                    0083     90 Fdynamixel_test$DPH0$0$0 == 0x0083
                    0083     91 _DPH0	=	0x0083
                    0084     92 Fdynamixel_test$DPL1$0$0 == 0x0084
                    0084     93 _DPL1	=	0x0084
                    0085     94 Fdynamixel_test$DPH1$0$0 == 0x0085
                    0085     95 _DPH1	=	0x0085
                    0086     96 Fdynamixel_test$U0CSR$0$0 == 0x0086
                    0086     97 _U0CSR	=	0x0086
                    0087     98 Fdynamixel_test$PCON$0$0 == 0x0087
                    0087     99 _PCON	=	0x0087
                    0088    100 Fdynamixel_test$TCON$0$0 == 0x0088
                    0088    101 _TCON	=	0x0088
                    0089    102 Fdynamixel_test$P0IFG$0$0 == 0x0089
                    0089    103 _P0IFG	=	0x0089
                    008A    104 Fdynamixel_test$P1IFG$0$0 == 0x008a
                    008A    105 _P1IFG	=	0x008a
                    008B    106 Fdynamixel_test$P2IFG$0$0 == 0x008b
                    008B    107 _P2IFG	=	0x008b
                    008C    108 Fdynamixel_test$PICTL$0$0 == 0x008c
                    008C    109 _PICTL	=	0x008c
                    008D    110 Fdynamixel_test$P1IEN$0$0 == 0x008d
                    008D    111 _P1IEN	=	0x008d
                    008F    112 Fdynamixel_test$P0INP$0$0 == 0x008f
                    008F    113 _P0INP	=	0x008f
                    0090    114 Fdynamixel_test$P1$0$0 == 0x0090
                    0090    115 _P1	=	0x0090
                    0091    116 Fdynamixel_test$RFIM$0$0 == 0x0091
                    0091    117 _RFIM	=	0x0091
                    0092    118 Fdynamixel_test$DPS$0$0 == 0x0092
                    0092    119 _DPS	=	0x0092
                    0093    120 Fdynamixel_test$MPAGE$0$0 == 0x0093
                    0093    121 _MPAGE	=	0x0093
                    0095    122 Fdynamixel_test$ENDIAN$0$0 == 0x0095
                    0095    123 _ENDIAN	=	0x0095
                    0098    124 Fdynamixel_test$S0CON$0$0 == 0x0098
                    0098    125 _S0CON	=	0x0098
                    009A    126 Fdynamixel_test$IEN2$0$0 == 0x009a
                    009A    127 _IEN2	=	0x009a
                    009B    128 Fdynamixel_test$S1CON$0$0 == 0x009b
                    009B    129 _S1CON	=	0x009b
                    009C    130 Fdynamixel_test$T2CT$0$0 == 0x009c
                    009C    131 _T2CT	=	0x009c
                    009D    132 Fdynamixel_test$T2PR$0$0 == 0x009d
                    009D    133 _T2PR	=	0x009d
                    009E    134 Fdynamixel_test$T2CTL$0$0 == 0x009e
                    009E    135 _T2CTL	=	0x009e
                    00A0    136 Fdynamixel_test$P2$0$0 == 0x00a0
                    00A0    137 _P2	=	0x00a0
                    00A1    138 Fdynamixel_test$WORIRQ$0$0 == 0x00a1
                    00A1    139 _WORIRQ	=	0x00a1
                    00A2    140 Fdynamixel_test$WORCTRL$0$0 == 0x00a2
                    00A2    141 _WORCTRL	=	0x00a2
                    00A3    142 Fdynamixel_test$WOREVT0$0$0 == 0x00a3
                    00A3    143 _WOREVT0	=	0x00a3
                    00A4    144 Fdynamixel_test$WOREVT1$0$0 == 0x00a4
                    00A4    145 _WOREVT1	=	0x00a4
                    00A5    146 Fdynamixel_test$WORTIME0$0$0 == 0x00a5
                    00A5    147 _WORTIME0	=	0x00a5
                    00A6    148 Fdynamixel_test$WORTIME1$0$0 == 0x00a6
                    00A6    149 _WORTIME1	=	0x00a6
                    00A8    150 Fdynamixel_test$IEN0$0$0 == 0x00a8
                    00A8    151 _IEN0	=	0x00a8
                    00A9    152 Fdynamixel_test$IP0$0$0 == 0x00a9
                    00A9    153 _IP0	=	0x00a9
                    00AB    154 Fdynamixel_test$FWT$0$0 == 0x00ab
                    00AB    155 _FWT	=	0x00ab
                    00AC    156 Fdynamixel_test$FADDRL$0$0 == 0x00ac
                    00AC    157 _FADDRL	=	0x00ac
                    00AD    158 Fdynamixel_test$FADDRH$0$0 == 0x00ad
                    00AD    159 _FADDRH	=	0x00ad
                    00AE    160 Fdynamixel_test$FCTL$0$0 == 0x00ae
                    00AE    161 _FCTL	=	0x00ae
                    00AF    162 Fdynamixel_test$FWDATA$0$0 == 0x00af
                    00AF    163 _FWDATA	=	0x00af
                    00B1    164 Fdynamixel_test$ENCDI$0$0 == 0x00b1
                    00B1    165 _ENCDI	=	0x00b1
                    00B2    166 Fdynamixel_test$ENCDO$0$0 == 0x00b2
                    00B2    167 _ENCDO	=	0x00b2
                    00B3    168 Fdynamixel_test$ENCCS$0$0 == 0x00b3
                    00B3    169 _ENCCS	=	0x00b3
                    00B4    170 Fdynamixel_test$ADCCON1$0$0 == 0x00b4
                    00B4    171 _ADCCON1	=	0x00b4
                    00B5    172 Fdynamixel_test$ADCCON2$0$0 == 0x00b5
                    00B5    173 _ADCCON2	=	0x00b5
                    00B6    174 Fdynamixel_test$ADCCON3$0$0 == 0x00b6
                    00B6    175 _ADCCON3	=	0x00b6
                    00B8    176 Fdynamixel_test$IEN1$0$0 == 0x00b8
                    00B8    177 _IEN1	=	0x00b8
                    00B9    178 Fdynamixel_test$IP1$0$0 == 0x00b9
                    00B9    179 _IP1	=	0x00b9
                    00BA    180 Fdynamixel_test$ADCL$0$0 == 0x00ba
                    00BA    181 _ADCL	=	0x00ba
                    00BB    182 Fdynamixel_test$ADCH$0$0 == 0x00bb
                    00BB    183 _ADCH	=	0x00bb
                    00BC    184 Fdynamixel_test$RNDL$0$0 == 0x00bc
                    00BC    185 _RNDL	=	0x00bc
                    00BD    186 Fdynamixel_test$RNDH$0$0 == 0x00bd
                    00BD    187 _RNDH	=	0x00bd
                    00BE    188 Fdynamixel_test$SLEEP$0$0 == 0x00be
                    00BE    189 _SLEEP	=	0x00be
                    00C0    190 Fdynamixel_test$IRCON$0$0 == 0x00c0
                    00C0    191 _IRCON	=	0x00c0
                    00C1    192 Fdynamixel_test$U0DBUF$0$0 == 0x00c1
                    00C1    193 _U0DBUF	=	0x00c1
                    00C2    194 Fdynamixel_test$U0BAUD$0$0 == 0x00c2
                    00C2    195 _U0BAUD	=	0x00c2
                    00C4    196 Fdynamixel_test$U0UCR$0$0 == 0x00c4
                    00C4    197 _U0UCR	=	0x00c4
                    00C5    198 Fdynamixel_test$U0GCR$0$0 == 0x00c5
                    00C5    199 _U0GCR	=	0x00c5
                    00C6    200 Fdynamixel_test$CLKCON$0$0 == 0x00c6
                    00C6    201 _CLKCON	=	0x00c6
                    00C7    202 Fdynamixel_test$MEMCTR$0$0 == 0x00c7
                    00C7    203 _MEMCTR	=	0x00c7
                    00C9    204 Fdynamixel_test$WDCTL$0$0 == 0x00c9
                    00C9    205 _WDCTL	=	0x00c9
                    00CA    206 Fdynamixel_test$T3CNT$0$0 == 0x00ca
                    00CA    207 _T3CNT	=	0x00ca
                    00CB    208 Fdynamixel_test$T3CTL$0$0 == 0x00cb
                    00CB    209 _T3CTL	=	0x00cb
                    00CC    210 Fdynamixel_test$T3CCTL0$0$0 == 0x00cc
                    00CC    211 _T3CCTL0	=	0x00cc
                    00CD    212 Fdynamixel_test$T3CC0$0$0 == 0x00cd
                    00CD    213 _T3CC0	=	0x00cd
                    00CE    214 Fdynamixel_test$T3CCTL1$0$0 == 0x00ce
                    00CE    215 _T3CCTL1	=	0x00ce
                    00CF    216 Fdynamixel_test$T3CC1$0$0 == 0x00cf
                    00CF    217 _T3CC1	=	0x00cf
                    00D0    218 Fdynamixel_test$PSW$0$0 == 0x00d0
                    00D0    219 _PSW	=	0x00d0
                    00D1    220 Fdynamixel_test$DMAIRQ$0$0 == 0x00d1
                    00D1    221 _DMAIRQ	=	0x00d1
                    00D2    222 Fdynamixel_test$DMA1CFGL$0$0 == 0x00d2
                    00D2    223 _DMA1CFGL	=	0x00d2
                    00D3    224 Fdynamixel_test$DMA1CFGH$0$0 == 0x00d3
                    00D3    225 _DMA1CFGH	=	0x00d3
                    00D4    226 Fdynamixel_test$DMA0CFGL$0$0 == 0x00d4
                    00D4    227 _DMA0CFGL	=	0x00d4
                    00D5    228 Fdynamixel_test$DMA0CFGH$0$0 == 0x00d5
                    00D5    229 _DMA0CFGH	=	0x00d5
                    00D6    230 Fdynamixel_test$DMAARM$0$0 == 0x00d6
                    00D6    231 _DMAARM	=	0x00d6
                    00D7    232 Fdynamixel_test$DMAREQ$0$0 == 0x00d7
                    00D7    233 _DMAREQ	=	0x00d7
                    00D8    234 Fdynamixel_test$TIMIF$0$0 == 0x00d8
                    00D8    235 _TIMIF	=	0x00d8
                    00D9    236 Fdynamixel_test$RFD$0$0 == 0x00d9
                    00D9    237 _RFD	=	0x00d9
                    00DA    238 Fdynamixel_test$T1CC0L$0$0 == 0x00da
                    00DA    239 _T1CC0L	=	0x00da
                    00DB    240 Fdynamixel_test$T1CC0H$0$0 == 0x00db
                    00DB    241 _T1CC0H	=	0x00db
                    00DC    242 Fdynamixel_test$T1CC1L$0$0 == 0x00dc
                    00DC    243 _T1CC1L	=	0x00dc
                    00DD    244 Fdynamixel_test$T1CC1H$0$0 == 0x00dd
                    00DD    245 _T1CC1H	=	0x00dd
                    00DE    246 Fdynamixel_test$T1CC2L$0$0 == 0x00de
                    00DE    247 _T1CC2L	=	0x00de
                    00DF    248 Fdynamixel_test$T1CC2H$0$0 == 0x00df
                    00DF    249 _T1CC2H	=	0x00df
                    00E0    250 Fdynamixel_test$ACC$0$0 == 0x00e0
                    00E0    251 _ACC	=	0x00e0
                    00E1    252 Fdynamixel_test$RFST$0$0 == 0x00e1
                    00E1    253 _RFST	=	0x00e1
                    00E2    254 Fdynamixel_test$T1CNTL$0$0 == 0x00e2
                    00E2    255 _T1CNTL	=	0x00e2
                    00E3    256 Fdynamixel_test$T1CNTH$0$0 == 0x00e3
                    00E3    257 _T1CNTH	=	0x00e3
                    00E4    258 Fdynamixel_test$T1CTL$0$0 == 0x00e4
                    00E4    259 _T1CTL	=	0x00e4
                    00E5    260 Fdynamixel_test$T1CCTL0$0$0 == 0x00e5
                    00E5    261 _T1CCTL0	=	0x00e5
                    00E6    262 Fdynamixel_test$T1CCTL1$0$0 == 0x00e6
                    00E6    263 _T1CCTL1	=	0x00e6
                    00E7    264 Fdynamixel_test$T1CCTL2$0$0 == 0x00e7
                    00E7    265 _T1CCTL2	=	0x00e7
                    00E8    266 Fdynamixel_test$IRCON2$0$0 == 0x00e8
                    00E8    267 _IRCON2	=	0x00e8
                    00E9    268 Fdynamixel_test$RFIF$0$0 == 0x00e9
                    00E9    269 _RFIF	=	0x00e9
                    00EA    270 Fdynamixel_test$T4CNT$0$0 == 0x00ea
                    00EA    271 _T4CNT	=	0x00ea
                    00EB    272 Fdynamixel_test$T4CTL$0$0 == 0x00eb
                    00EB    273 _T4CTL	=	0x00eb
                    00EC    274 Fdynamixel_test$T4CCTL0$0$0 == 0x00ec
                    00EC    275 _T4CCTL0	=	0x00ec
                    00ED    276 Fdynamixel_test$T4CC0$0$0 == 0x00ed
                    00ED    277 _T4CC0	=	0x00ed
                    00EE    278 Fdynamixel_test$T4CCTL1$0$0 == 0x00ee
                    00EE    279 _T4CCTL1	=	0x00ee
                    00EF    280 Fdynamixel_test$T4CC1$0$0 == 0x00ef
                    00EF    281 _T4CC1	=	0x00ef
                    00F0    282 Fdynamixel_test$B$0$0 == 0x00f0
                    00F0    283 _B	=	0x00f0
                    00F1    284 Fdynamixel_test$PERCFG$0$0 == 0x00f1
                    00F1    285 _PERCFG	=	0x00f1
                    00F2    286 Fdynamixel_test$ADCCFG$0$0 == 0x00f2
                    00F2    287 _ADCCFG	=	0x00f2
                    00F3    288 Fdynamixel_test$P0SEL$0$0 == 0x00f3
                    00F3    289 _P0SEL	=	0x00f3
                    00F4    290 Fdynamixel_test$P1SEL$0$0 == 0x00f4
                    00F4    291 _P1SEL	=	0x00f4
                    00F5    292 Fdynamixel_test$P2SEL$0$0 == 0x00f5
                    00F5    293 _P2SEL	=	0x00f5
                    00F6    294 Fdynamixel_test$P1INP$0$0 == 0x00f6
                    00F6    295 _P1INP	=	0x00f6
                    00F7    296 Fdynamixel_test$P2INP$0$0 == 0x00f7
                    00F7    297 _P2INP	=	0x00f7
                    00F8    298 Fdynamixel_test$U1CSR$0$0 == 0x00f8
                    00F8    299 _U1CSR	=	0x00f8
                    00F9    300 Fdynamixel_test$U1DBUF$0$0 == 0x00f9
                    00F9    301 _U1DBUF	=	0x00f9
                    00FA    302 Fdynamixel_test$U1BAUD$0$0 == 0x00fa
                    00FA    303 _U1BAUD	=	0x00fa
                    00FB    304 Fdynamixel_test$U1UCR$0$0 == 0x00fb
                    00FB    305 _U1UCR	=	0x00fb
                    00FC    306 Fdynamixel_test$U1GCR$0$0 == 0x00fc
                    00FC    307 _U1GCR	=	0x00fc
                    00FD    308 Fdynamixel_test$P0DIR$0$0 == 0x00fd
                    00FD    309 _P0DIR	=	0x00fd
                    00FE    310 Fdynamixel_test$P1DIR$0$0 == 0x00fe
                    00FE    311 _P1DIR	=	0x00fe
                    00FF    312 Fdynamixel_test$P2DIR$0$0 == 0x00ff
                    00FF    313 _P2DIR	=	0x00ff
                    FFFFD5D4    314 Fdynamixel_test$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    315 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    316 Fdynamixel_test$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    317 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    318 Fdynamixel_test$FADDR$0$0 == 0xffffadac
                    FFFFADAC    319 _FADDR	=	0xffffadac
                    FFFFBBBA    320 Fdynamixel_test$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    321 _ADC	=	0xffffbbba
                    FFFFDBDA    322 Fdynamixel_test$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    323 _T1CC0	=	0xffffdbda
                    FFFFDDDC    324 Fdynamixel_test$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    325 _T1CC1	=	0xffffdddc
                    FFFFDFDE    326 Fdynamixel_test$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    327 _T1CC2	=	0xffffdfde
                            328 ;--------------------------------------------------------
                            329 ; special function bits
                            330 ;--------------------------------------------------------
                            331 	.area RSEG    (ABS,DATA)
   0000                     332 	.org 0x0000
                    0080    333 Fdynamixel_test$P0_0$0$0 == 0x0080
                    0080    334 _P0_0	=	0x0080
                    0081    335 Fdynamixel_test$P0_1$0$0 == 0x0081
                    0081    336 _P0_1	=	0x0081
                    0082    337 Fdynamixel_test$P0_2$0$0 == 0x0082
                    0082    338 _P0_2	=	0x0082
                    0083    339 Fdynamixel_test$P0_3$0$0 == 0x0083
                    0083    340 _P0_3	=	0x0083
                    0084    341 Fdynamixel_test$P0_4$0$0 == 0x0084
                    0084    342 _P0_4	=	0x0084
                    0085    343 Fdynamixel_test$P0_5$0$0 == 0x0085
                    0085    344 _P0_5	=	0x0085
                    0086    345 Fdynamixel_test$P0_6$0$0 == 0x0086
                    0086    346 _P0_6	=	0x0086
                    0087    347 Fdynamixel_test$P0_7$0$0 == 0x0087
                    0087    348 _P0_7	=	0x0087
                    0088    349 Fdynamixel_test$_TCON_0$0$0 == 0x0088
                    0088    350 __TCON_0	=	0x0088
                    0089    351 Fdynamixel_test$RFTXRXIF$0$0 == 0x0089
                    0089    352 _RFTXRXIF	=	0x0089
                    008A    353 Fdynamixel_test$_TCON_2$0$0 == 0x008a
                    008A    354 __TCON_2	=	0x008a
                    008B    355 Fdynamixel_test$URX0IF$0$0 == 0x008b
                    008B    356 _URX0IF	=	0x008b
                    008C    357 Fdynamixel_test$_TCON_4$0$0 == 0x008c
                    008C    358 __TCON_4	=	0x008c
                    008D    359 Fdynamixel_test$ADCIF$0$0 == 0x008d
                    008D    360 _ADCIF	=	0x008d
                    008E    361 Fdynamixel_test$_TCON_6$0$0 == 0x008e
                    008E    362 __TCON_6	=	0x008e
                    008F    363 Fdynamixel_test$URX1IF$0$0 == 0x008f
                    008F    364 _URX1IF	=	0x008f
                    0090    365 Fdynamixel_test$P1_0$0$0 == 0x0090
                    0090    366 _P1_0	=	0x0090
                    0091    367 Fdynamixel_test$P1_1$0$0 == 0x0091
                    0091    368 _P1_1	=	0x0091
                    0092    369 Fdynamixel_test$P1_2$0$0 == 0x0092
                    0092    370 _P1_2	=	0x0092
                    0093    371 Fdynamixel_test$P1_3$0$0 == 0x0093
                    0093    372 _P1_3	=	0x0093
                    0094    373 Fdynamixel_test$P1_4$0$0 == 0x0094
                    0094    374 _P1_4	=	0x0094
                    0095    375 Fdynamixel_test$P1_5$0$0 == 0x0095
                    0095    376 _P1_5	=	0x0095
                    0096    377 Fdynamixel_test$P1_6$0$0 == 0x0096
                    0096    378 _P1_6	=	0x0096
                    0097    379 Fdynamixel_test$P1_7$0$0 == 0x0097
                    0097    380 _P1_7	=	0x0097
                    0098    381 Fdynamixel_test$ENCIF_0$0$0 == 0x0098
                    0098    382 _ENCIF_0	=	0x0098
                    0099    383 Fdynamixel_test$ENCIF_1$0$0 == 0x0099
                    0099    384 _ENCIF_1	=	0x0099
                    009A    385 Fdynamixel_test$_SOCON2$0$0 == 0x009a
                    009A    386 __SOCON2	=	0x009a
                    009B    387 Fdynamixel_test$_SOCON3$0$0 == 0x009b
                    009B    388 __SOCON3	=	0x009b
                    009C    389 Fdynamixel_test$_SOCON4$0$0 == 0x009c
                    009C    390 __SOCON4	=	0x009c
                    009D    391 Fdynamixel_test$_SOCON5$0$0 == 0x009d
                    009D    392 __SOCON5	=	0x009d
                    009E    393 Fdynamixel_test$_SOCON6$0$0 == 0x009e
                    009E    394 __SOCON6	=	0x009e
                    009F    395 Fdynamixel_test$_SOCON7$0$0 == 0x009f
                    009F    396 __SOCON7	=	0x009f
                    00A0    397 Fdynamixel_test$P2_0$0$0 == 0x00a0
                    00A0    398 _P2_0	=	0x00a0
                    00A1    399 Fdynamixel_test$P2_1$0$0 == 0x00a1
                    00A1    400 _P2_1	=	0x00a1
                    00A2    401 Fdynamixel_test$P2_2$0$0 == 0x00a2
                    00A2    402 _P2_2	=	0x00a2
                    00A3    403 Fdynamixel_test$P2_3$0$0 == 0x00a3
                    00A3    404 _P2_3	=	0x00a3
                    00A4    405 Fdynamixel_test$P2_4$0$0 == 0x00a4
                    00A4    406 _P2_4	=	0x00a4
                    00A5    407 Fdynamixel_test$P2_5$0$0 == 0x00a5
                    00A5    408 _P2_5	=	0x00a5
                    00A6    409 Fdynamixel_test$P2_6$0$0 == 0x00a6
                    00A6    410 _P2_6	=	0x00a6
                    00A7    411 Fdynamixel_test$P2_7$0$0 == 0x00a7
                    00A7    412 _P2_7	=	0x00a7
                    00A8    413 Fdynamixel_test$RFTXRXIE$0$0 == 0x00a8
                    00A8    414 _RFTXRXIE	=	0x00a8
                    00A9    415 Fdynamixel_test$ADCIE$0$0 == 0x00a9
                    00A9    416 _ADCIE	=	0x00a9
                    00AA    417 Fdynamixel_test$URX0IE$0$0 == 0x00aa
                    00AA    418 _URX0IE	=	0x00aa
                    00AB    419 Fdynamixel_test$URX1IE$0$0 == 0x00ab
                    00AB    420 _URX1IE	=	0x00ab
                    00AC    421 Fdynamixel_test$ENCIE$0$0 == 0x00ac
                    00AC    422 _ENCIE	=	0x00ac
                    00AD    423 Fdynamixel_test$STIE$0$0 == 0x00ad
                    00AD    424 _STIE	=	0x00ad
                    00AE    425 Fdynamixel_test$_IEN06$0$0 == 0x00ae
                    00AE    426 __IEN06	=	0x00ae
                    00AF    427 Fdynamixel_test$EA$0$0 == 0x00af
                    00AF    428 _EA	=	0x00af
                    00B8    429 Fdynamixel_test$DMAIE$0$0 == 0x00b8
                    00B8    430 _DMAIE	=	0x00b8
                    00B9    431 Fdynamixel_test$T1IE$0$0 == 0x00b9
                    00B9    432 _T1IE	=	0x00b9
                    00BA    433 Fdynamixel_test$T2IE$0$0 == 0x00ba
                    00BA    434 _T2IE	=	0x00ba
                    00BB    435 Fdynamixel_test$T3IE$0$0 == 0x00bb
                    00BB    436 _T3IE	=	0x00bb
                    00BC    437 Fdynamixel_test$T4IE$0$0 == 0x00bc
                    00BC    438 _T4IE	=	0x00bc
                    00BD    439 Fdynamixel_test$P0IE$0$0 == 0x00bd
                    00BD    440 _P0IE	=	0x00bd
                    00BE    441 Fdynamixel_test$_IEN16$0$0 == 0x00be
                    00BE    442 __IEN16	=	0x00be
                    00BF    443 Fdynamixel_test$_IEN17$0$0 == 0x00bf
                    00BF    444 __IEN17	=	0x00bf
                    00C0    445 Fdynamixel_test$DMAIF$0$0 == 0x00c0
                    00C0    446 _DMAIF	=	0x00c0
                    00C1    447 Fdynamixel_test$T1IF$0$0 == 0x00c1
                    00C1    448 _T1IF	=	0x00c1
                    00C2    449 Fdynamixel_test$T2IF$0$0 == 0x00c2
                    00C2    450 _T2IF	=	0x00c2
                    00C3    451 Fdynamixel_test$T3IF$0$0 == 0x00c3
                    00C3    452 _T3IF	=	0x00c3
                    00C4    453 Fdynamixel_test$T4IF$0$0 == 0x00c4
                    00C4    454 _T4IF	=	0x00c4
                    00C5    455 Fdynamixel_test$P0IF$0$0 == 0x00c5
                    00C5    456 _P0IF	=	0x00c5
                    00C6    457 Fdynamixel_test$_IRCON6$0$0 == 0x00c6
                    00C6    458 __IRCON6	=	0x00c6
                    00C7    459 Fdynamixel_test$STIF$0$0 == 0x00c7
                    00C7    460 _STIF	=	0x00c7
                    00D0    461 Fdynamixel_test$P$0$0 == 0x00d0
                    00D0    462 _P	=	0x00d0
                    00D1    463 Fdynamixel_test$F1$0$0 == 0x00d1
                    00D1    464 _F1	=	0x00d1
                    00D2    465 Fdynamixel_test$OV$0$0 == 0x00d2
                    00D2    466 _OV	=	0x00d2
                    00D3    467 Fdynamixel_test$RS0$0$0 == 0x00d3
                    00D3    468 _RS0	=	0x00d3
                    00D4    469 Fdynamixel_test$RS1$0$0 == 0x00d4
                    00D4    470 _RS1	=	0x00d4
                    00D5    471 Fdynamixel_test$F0$0$0 == 0x00d5
                    00D5    472 _F0	=	0x00d5
                    00D6    473 Fdynamixel_test$AC$0$0 == 0x00d6
                    00D6    474 _AC	=	0x00d6
                    00D7    475 Fdynamixel_test$CY$0$0 == 0x00d7
                    00D7    476 _CY	=	0x00d7
                    00D8    477 Fdynamixel_test$T3OVFIF$0$0 == 0x00d8
                    00D8    478 _T3OVFIF	=	0x00d8
                    00D9    479 Fdynamixel_test$T3CH0IF$0$0 == 0x00d9
                    00D9    480 _T3CH0IF	=	0x00d9
                    00DA    481 Fdynamixel_test$T3CH1IF$0$0 == 0x00da
                    00DA    482 _T3CH1IF	=	0x00da
                    00DB    483 Fdynamixel_test$T4OVFIF$0$0 == 0x00db
                    00DB    484 _T4OVFIF	=	0x00db
                    00DC    485 Fdynamixel_test$T4CH0IF$0$0 == 0x00dc
                    00DC    486 _T4CH0IF	=	0x00dc
                    00DD    487 Fdynamixel_test$T4CH1IF$0$0 == 0x00dd
                    00DD    488 _T4CH1IF	=	0x00dd
                    00DE    489 Fdynamixel_test$OVFIM$0$0 == 0x00de
                    00DE    490 _OVFIM	=	0x00de
                    00DF    491 Fdynamixel_test$_TIMIF7$0$0 == 0x00df
                    00DF    492 __TIMIF7	=	0x00df
                    00E0    493 Fdynamixel_test$ACC_0$0$0 == 0x00e0
                    00E0    494 _ACC_0	=	0x00e0
                    00E1    495 Fdynamixel_test$ACC_1$0$0 == 0x00e1
                    00E1    496 _ACC_1	=	0x00e1
                    00E2    497 Fdynamixel_test$ACC_2$0$0 == 0x00e2
                    00E2    498 _ACC_2	=	0x00e2
                    00E3    499 Fdynamixel_test$ACC_3$0$0 == 0x00e3
                    00E3    500 _ACC_3	=	0x00e3
                    00E4    501 Fdynamixel_test$ACC_4$0$0 == 0x00e4
                    00E4    502 _ACC_4	=	0x00e4
                    00E5    503 Fdynamixel_test$ACC_5$0$0 == 0x00e5
                    00E5    504 _ACC_5	=	0x00e5
                    00E6    505 Fdynamixel_test$ACC_6$0$0 == 0x00e6
                    00E6    506 _ACC_6	=	0x00e6
                    00E7    507 Fdynamixel_test$ACC_7$0$0 == 0x00e7
                    00E7    508 _ACC_7	=	0x00e7
                    00E8    509 Fdynamixel_test$P2IF$0$0 == 0x00e8
                    00E8    510 _P2IF	=	0x00e8
                    00E9    511 Fdynamixel_test$UTX0IF$0$0 == 0x00e9
                    00E9    512 _UTX0IF	=	0x00e9
                    00EA    513 Fdynamixel_test$UTX1IF$0$0 == 0x00ea
                    00EA    514 _UTX1IF	=	0x00ea
                    00EB    515 Fdynamixel_test$P1IF$0$0 == 0x00eb
                    00EB    516 _P1IF	=	0x00eb
                    00EC    517 Fdynamixel_test$WDTIF$0$0 == 0x00ec
                    00EC    518 _WDTIF	=	0x00ec
                    00ED    519 Fdynamixel_test$_IRCON25$0$0 == 0x00ed
                    00ED    520 __IRCON25	=	0x00ed
                    00EE    521 Fdynamixel_test$_IRCON26$0$0 == 0x00ee
                    00EE    522 __IRCON26	=	0x00ee
                    00EF    523 Fdynamixel_test$_IRCON27$0$0 == 0x00ef
                    00EF    524 __IRCON27	=	0x00ef
                    00F0    525 Fdynamixel_test$B_0$0$0 == 0x00f0
                    00F0    526 _B_0	=	0x00f0
                    00F1    527 Fdynamixel_test$B_1$0$0 == 0x00f1
                    00F1    528 _B_1	=	0x00f1
                    00F2    529 Fdynamixel_test$B_2$0$0 == 0x00f2
                    00F2    530 _B_2	=	0x00f2
                    00F3    531 Fdynamixel_test$B_3$0$0 == 0x00f3
                    00F3    532 _B_3	=	0x00f3
                    00F4    533 Fdynamixel_test$B_4$0$0 == 0x00f4
                    00F4    534 _B_4	=	0x00f4
                    00F5    535 Fdynamixel_test$B_5$0$0 == 0x00f5
                    00F5    536 _B_5	=	0x00f5
                    00F6    537 Fdynamixel_test$B_6$0$0 == 0x00f6
                    00F6    538 _B_6	=	0x00f6
                    00F7    539 Fdynamixel_test$B_7$0$0 == 0x00f7
                    00F7    540 _B_7	=	0x00f7
                    00F8    541 Fdynamixel_test$U1ACTIVE$0$0 == 0x00f8
                    00F8    542 _U1ACTIVE	=	0x00f8
                    00F9    543 Fdynamixel_test$U1TX_BYTE$0$0 == 0x00f9
                    00F9    544 _U1TX_BYTE	=	0x00f9
                    00FA    545 Fdynamixel_test$U1RX_BYTE$0$0 == 0x00fa
                    00FA    546 _U1RX_BYTE	=	0x00fa
                    00FB    547 Fdynamixel_test$U1ERR$0$0 == 0x00fb
                    00FB    548 _U1ERR	=	0x00fb
                    00FC    549 Fdynamixel_test$U1FE$0$0 == 0x00fc
                    00FC    550 _U1FE	=	0x00fc
                    00FD    551 Fdynamixel_test$U1SLAVE$0$0 == 0x00fd
                    00FD    552 _U1SLAVE	=	0x00fd
                    00FE    553 Fdynamixel_test$U1RE$0$0 == 0x00fe
                    00FE    554 _U1RE	=	0x00fe
                    00FF    555 Fdynamixel_test$U1MODE$0$0 == 0x00ff
                    00FF    556 _U1MODE	=	0x00ff
                            557 ;--------------------------------------------------------
                            558 ; overlayable register banks
                            559 ;--------------------------------------------------------
                            560 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     561 	.ds 8
                            562 ;--------------------------------------------------------
                            563 ; overlayable bit register bank
                            564 ;--------------------------------------------------------
                            565 	.area BIT_BANK	(REL,OVR,DATA)
   0022                     566 bits:
   0022                     567 	.ds 1
                    8000    568 	b0 = bits[0]
                    8100    569 	b1 = bits[1]
                    8200    570 	b2 = bits[2]
                    8300    571 	b3 = bits[3]
                    8400    572 	b4 = bits[4]
                    8500    573 	b5 = bits[5]
                    8600    574 	b6 = bits[6]
                    8700    575 	b7 = bits[7]
                            576 ;--------------------------------------------------------
                            577 ; internal ram data
                            578 ;--------------------------------------------------------
                            579 	.area DSEG    (DATA)
                    0000    580 G$currentSerialMode$0$0==.
   000C                     581 _currentSerialMode::
   000C                     582 	.ds 1
                    0001    583 Ldynamixel_test.errorService$sloc0$1$0==.
   000D                     584 _errorService_sloc0_1_0:
   000D                     585 	.ds 4
                    0005    586 Ldynamixel_test.interpolate$lRtnRange$1$1==.
   0011                     587 _interpolate_lRtnRange_1_1:
   0011                     588 	.ds 4
                    0009    589 Ldynamixel_test.interpolate$lValRange$1$1==.
   0015                     590 _interpolate_lValRange_1_1:
   0015                     591 	.ds 4
                    000D    592 Ldynamixel_test.interpolate$sloc0$1$0==.
   0019                     593 _interpolate_sloc0_1_0:
   0019                     594 	.ds 4
                            595 ;--------------------------------------------------------
                            596 ; overlayable items in internal ram 
                            597 ;--------------------------------------------------------
                            598 	.area OSEG    (OVR,DATA)
                            599 ;--------------------------------------------------------
                            600 ; Stack segment in internal ram 
                            601 ;--------------------------------------------------------
                            602 	.area	SSEG	(DATA)
   0033                     603 __start__stack:
   0033                     604 	.ds	1
                            605 
                            606 ;--------------------------------------------------------
                            607 ; indirectly addressable internal ram data
                            608 ;--------------------------------------------------------
                            609 	.area ISEG    (DATA)
                            610 ;--------------------------------------------------------
                            611 ; absolute internal ram data
                            612 ;--------------------------------------------------------
                            613 	.area IABS    (ABS,DATA)
                            614 	.area IABS    (ABS,DATA)
                            615 ;--------------------------------------------------------
                            616 ; bit data
                            617 ;--------------------------------------------------------
                            618 	.area BSEG    (BIT)
                    0000    619 G$uartRxDisabled$0$0==.
   0000                     620 _uartRxDisabled::
   0000                     621 	.ds 1
                    0001    622 G$framingErrorActive$0$0==.
   0001                     623 _framingErrorActive::
   0001                     624 	.ds 1
                    0002    625 G$errorOccurredRecently$0$0==.
   0002                     626 _errorOccurredRecently::
   0002                     627 	.ds 1
                    0003    628 Ldynamixel_test.updateLeds$dimYellowLed$1$1==.
   0003                     629 _updateLeds_dimYellowLed_1_1:
   0003                     630 	.ds 1
                    0004    631 Ldynamixel_test.ioTxSignals$sloc0$1$0==.
   0004                     632 _ioTxSignals_sloc0_1_0:
   0004                     633 	.ds 1
                            634 ;--------------------------------------------------------
                            635 ; paged external ram data
                            636 ;--------------------------------------------------------
                            637 	.area PSEG    (PAG,XDATA)
                    0000    638 G$d_tilt$0$0==.
   F035                     639 _d_tilt::
   F035                     640 	.ds 1
                    0001    641 G$d_pan$0$0==.
   F036                     642 _d_pan::
   F036                     643 	.ds 1
                    0002    644 G$tilt_pos$0$0==.
   F037                     645 _tilt_pos::
   F037                     646 	.ds 1
                    0003    647 G$pan_pos$0$0==.
   F038                     648 _pan_pos::
   F038                     649 	.ds 1
                    0004    650 G$turnright$0$0==.
   F039                     651 _turnright::
   F039                     652 	.ds 2
                    0006    653 G$turnleft$0$0==.
   F03B                     654 _turnleft::
   F03B                     655 	.ds 2
                    0008    656 G$gunbutton$0$0==.
   F03D                     657 _gunbutton::
   F03D                     658 	.ds 2
                    000A    659 G$panicbutton$0$0==.
   F03F                     660 _panicbutton::
   F03F                     661 	.ds 2
                    000C    662 G$infobutton$0$0==.
   F041                     663 _infobutton::
   F041                     664 	.ds 2
                    000E    665 G$agitbutton$0$0==.
   F043                     666 _agitbutton::
   F043                     667 	.ds 2
                    0010    668 G$walk$0$0==.
   F045                     669 _walk::
   F045                     670 	.ds 2
                    0012    671 G$turn$0$0==.
   F047                     672 _turn::
   F047                     673 	.ds 2
                    0014    674 G$light$0$0==.
   F049                     675 _light::
   F049                     676 	.ds 2
                    0016    677 G$kneeling$0$0==.
   F04B                     678 _kneeling::
   F04B                     679 	.ds 2
                    0018    680 G$flopCnt$0$0==.
   F04D                     681 _flopCnt::
   F04D                     682 	.ds 2
                    001A    683 G$panic$0$0==.
   F04F                     684 _panic::
   F04F                     685 	.ds 2
                    001C    686 G$pan_add$0$0==.
   F051                     687 _pan_add::
   F051                     688 	.ds 1
                    001D    689 G$tilt_add$0$0==.
   F052                     690 _tilt_add::
   F052                     691 	.ds 1
                    001E    692 G$vals$0$0==.
   F053                     693 _vals::
   F053                     694 	.ds 7
                    0025    695 G$index_cmdr$0$0==.
   F05A                     696 _index_cmdr::
   F05A                     697 	.ds 2
                    0027    698 G$checksum_cmdr$0$0==.
   F05C                     699 _checksum_cmdr::
   F05C                     700 	.ds 2
                    0029    701 G$southpaw$0$0==.
   F05E                     702 _southpaw::
   F05E                     703 	.ds 1
                    002A    704 G$walkV$0$0==.
   F05F                     705 _walkV::
   F05F                     706 	.ds 2
                    002C    707 G$walkH$0$0==.
   F061                     708 _walkH::
   F061                     709 	.ds 2
                    002E    710 G$lookV$0$0==.
   F063                     711 _lookV::
   F063                     712 	.ds 2
                    0030    713 G$lookH$0$0==.
   F065                     714 _lookH::
   F065                     715 	.ds 2
                    0032    716 G$walkSPD$0$0==.
   F067                     717 _walkSPD::
   F067                     718 	.ds 2
                    0034    719 G$walkDIR$0$0==.
   F069                     720 _walkDIR::
   F069                     721 	.ds 4
                    0038    722 G$lastErrorTime$0$0==.
   F06D                     723 _lastErrorTime::
   F06D                     724 	.ds 1
                    0039    725 Ldynamixel_test.updateLeds$lastRadioActivityTime$1$1==.
   F06E                     726 _updateLeds_lastRadioActivityTime_1_1:
   F06E                     727 	.ds 2
                    003B    728 Ldynamixel_test.ioTxSignals$signals$1$1==.
   F070                     729 _ioTxSignals_signals_1_1:
   F070                     730 	.ds 1
                    003C    731 Ldynamixel_test.ioTxSignals$nTrstPulseStartTime$1$1==.
   F071                     732 _ioTxSignals_nTrstPulseStartTime_1_1:
   F071                     733 	.ds 1
                    003D    734 Ldynamixel_test.ioTxSignals$lastSignals$1$1==.
   F072                     735 _ioTxSignals_lastSignals_1_1:
   F072                     736 	.ds 1
                    003E    737 Ldynamixel_test.errorService$lastRxLowTime$1$1==.
   F073                     738 _errorService_lastRxLowTime_1_1:
   F073                     739 	.ds 1
                    003F    740 Ldynamixel_test.interpolate$minVal$1$1==.
   F074                     741 _interpolate_PARM_2:
   F074                     742 	.ds 2
                    0041    743 Ldynamixel_test.interpolate$maxVal$1$1==.
   F076                     744 _interpolate_PARM_3:
   F076                     745 	.ds 2
                    0043    746 Ldynamixel_test.interpolate$minRtn$1$1==.
   F078                     747 _interpolate_PARM_4:
   F078                     748 	.ds 2
                    0045    749 Ldynamixel_test.interpolate$maxRtn$1$1==.
   F07A                     750 _interpolate_PARM_5:
   F07A                     751 	.ds 2
                            752 ;--------------------------------------------------------
                            753 ; external ram data
                            754 ;--------------------------------------------------------
                            755 	.area XSEG    (XDATA)
                    DF00    756 Fdynamixel_test$SYNC1$0$0 == 0xdf00
                    DF00    757 _SYNC1	=	0xdf00
                    DF01    758 Fdynamixel_test$SYNC0$0$0 == 0xdf01
                    DF01    759 _SYNC0	=	0xdf01
                    DF02    760 Fdynamixel_test$PKTLEN$0$0 == 0xdf02
                    DF02    761 _PKTLEN	=	0xdf02
                    DF03    762 Fdynamixel_test$PKTCTRL1$0$0 == 0xdf03
                    DF03    763 _PKTCTRL1	=	0xdf03
                    DF04    764 Fdynamixel_test$PKTCTRL0$0$0 == 0xdf04
                    DF04    765 _PKTCTRL0	=	0xdf04
                    DF05    766 Fdynamixel_test$ADDR$0$0 == 0xdf05
                    DF05    767 _ADDR	=	0xdf05
                    DF06    768 Fdynamixel_test$CHANNR$0$0 == 0xdf06
                    DF06    769 _CHANNR	=	0xdf06
                    DF07    770 Fdynamixel_test$FSCTRL1$0$0 == 0xdf07
                    DF07    771 _FSCTRL1	=	0xdf07
                    DF08    772 Fdynamixel_test$FSCTRL0$0$0 == 0xdf08
                    DF08    773 _FSCTRL0	=	0xdf08
                    DF09    774 Fdynamixel_test$FREQ2$0$0 == 0xdf09
                    DF09    775 _FREQ2	=	0xdf09
                    DF0A    776 Fdynamixel_test$FREQ1$0$0 == 0xdf0a
                    DF0A    777 _FREQ1	=	0xdf0a
                    DF0B    778 Fdynamixel_test$FREQ0$0$0 == 0xdf0b
                    DF0B    779 _FREQ0	=	0xdf0b
                    DF0C    780 Fdynamixel_test$MDMCFG4$0$0 == 0xdf0c
                    DF0C    781 _MDMCFG4	=	0xdf0c
                    DF0D    782 Fdynamixel_test$MDMCFG3$0$0 == 0xdf0d
                    DF0D    783 _MDMCFG3	=	0xdf0d
                    DF0E    784 Fdynamixel_test$MDMCFG2$0$0 == 0xdf0e
                    DF0E    785 _MDMCFG2	=	0xdf0e
                    DF0F    786 Fdynamixel_test$MDMCFG1$0$0 == 0xdf0f
                    DF0F    787 _MDMCFG1	=	0xdf0f
                    DF10    788 Fdynamixel_test$MDMCFG0$0$0 == 0xdf10
                    DF10    789 _MDMCFG0	=	0xdf10
                    DF11    790 Fdynamixel_test$DEVIATN$0$0 == 0xdf11
                    DF11    791 _DEVIATN	=	0xdf11
                    DF12    792 Fdynamixel_test$MCSM2$0$0 == 0xdf12
                    DF12    793 _MCSM2	=	0xdf12
                    DF13    794 Fdynamixel_test$MCSM1$0$0 == 0xdf13
                    DF13    795 _MCSM1	=	0xdf13
                    DF14    796 Fdynamixel_test$MCSM0$0$0 == 0xdf14
                    DF14    797 _MCSM0	=	0xdf14
                    DF15    798 Fdynamixel_test$FOCCFG$0$0 == 0xdf15
                    DF15    799 _FOCCFG	=	0xdf15
                    DF16    800 Fdynamixel_test$BSCFG$0$0 == 0xdf16
                    DF16    801 _BSCFG	=	0xdf16
                    DF17    802 Fdynamixel_test$AGCCTRL2$0$0 == 0xdf17
                    DF17    803 _AGCCTRL2	=	0xdf17
                    DF18    804 Fdynamixel_test$AGCCTRL1$0$0 == 0xdf18
                    DF18    805 _AGCCTRL1	=	0xdf18
                    DF19    806 Fdynamixel_test$AGCCTRL0$0$0 == 0xdf19
                    DF19    807 _AGCCTRL0	=	0xdf19
                    DF1A    808 Fdynamixel_test$FREND1$0$0 == 0xdf1a
                    DF1A    809 _FREND1	=	0xdf1a
                    DF1B    810 Fdynamixel_test$FREND0$0$0 == 0xdf1b
                    DF1B    811 _FREND0	=	0xdf1b
                    DF1C    812 Fdynamixel_test$FSCAL3$0$0 == 0xdf1c
                    DF1C    813 _FSCAL3	=	0xdf1c
                    DF1D    814 Fdynamixel_test$FSCAL2$0$0 == 0xdf1d
                    DF1D    815 _FSCAL2	=	0xdf1d
                    DF1E    816 Fdynamixel_test$FSCAL1$0$0 == 0xdf1e
                    DF1E    817 _FSCAL1	=	0xdf1e
                    DF1F    818 Fdynamixel_test$FSCAL0$0$0 == 0xdf1f
                    DF1F    819 _FSCAL0	=	0xdf1f
                    DF23    820 Fdynamixel_test$TEST2$0$0 == 0xdf23
                    DF23    821 _TEST2	=	0xdf23
                    DF24    822 Fdynamixel_test$TEST1$0$0 == 0xdf24
                    DF24    823 _TEST1	=	0xdf24
                    DF25    824 Fdynamixel_test$TEST0$0$0 == 0xdf25
                    DF25    825 _TEST0	=	0xdf25
                    DF2E    826 Fdynamixel_test$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    827 _PA_TABLE0	=	0xdf2e
                    DF2F    828 Fdynamixel_test$IOCFG2$0$0 == 0xdf2f
                    DF2F    829 _IOCFG2	=	0xdf2f
                    DF30    830 Fdynamixel_test$IOCFG1$0$0 == 0xdf30
                    DF30    831 _IOCFG1	=	0xdf30
                    DF31    832 Fdynamixel_test$IOCFG0$0$0 == 0xdf31
                    DF31    833 _IOCFG0	=	0xdf31
                    DF36    834 Fdynamixel_test$PARTNUM$0$0 == 0xdf36
                    DF36    835 _PARTNUM	=	0xdf36
                    DF37    836 Fdynamixel_test$VERSION$0$0 == 0xdf37
                    DF37    837 _VERSION	=	0xdf37
                    DF38    838 Fdynamixel_test$FREQEST$0$0 == 0xdf38
                    DF38    839 _FREQEST	=	0xdf38
                    DF39    840 Fdynamixel_test$LQI$0$0 == 0xdf39
                    DF39    841 _LQI	=	0xdf39
                    DF3A    842 Fdynamixel_test$RSSI$0$0 == 0xdf3a
                    DF3A    843 _RSSI	=	0xdf3a
                    DF3B    844 Fdynamixel_test$MARCSTATE$0$0 == 0xdf3b
                    DF3B    845 _MARCSTATE	=	0xdf3b
                    DF3C    846 Fdynamixel_test$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    847 _PKTSTATUS	=	0xdf3c
                    DF3D    848 Fdynamixel_test$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    849 _VCO_VC_DAC	=	0xdf3d
                    DF40    850 Fdynamixel_test$I2SCFG0$0$0 == 0xdf40
                    DF40    851 _I2SCFG0	=	0xdf40
                    DF41    852 Fdynamixel_test$I2SCFG1$0$0 == 0xdf41
                    DF41    853 _I2SCFG1	=	0xdf41
                    DF42    854 Fdynamixel_test$I2SDATL$0$0 == 0xdf42
                    DF42    855 _I2SDATL	=	0xdf42
                    DF43    856 Fdynamixel_test$I2SDATH$0$0 == 0xdf43
                    DF43    857 _I2SDATH	=	0xdf43
                    DF44    858 Fdynamixel_test$I2SWCNT$0$0 == 0xdf44
                    DF44    859 _I2SWCNT	=	0xdf44
                    DF45    860 Fdynamixel_test$I2SSTAT$0$0 == 0xdf45
                    DF45    861 _I2SSTAT	=	0xdf45
                    DF46    862 Fdynamixel_test$I2SCLKF0$0$0 == 0xdf46
                    DF46    863 _I2SCLKF0	=	0xdf46
                    DF47    864 Fdynamixel_test$I2SCLKF1$0$0 == 0xdf47
                    DF47    865 _I2SCLKF1	=	0xdf47
                    DF48    866 Fdynamixel_test$I2SCLKF2$0$0 == 0xdf48
                    DF48    867 _I2SCLKF2	=	0xdf48
                    DE00    868 Fdynamixel_test$USBADDR$0$0 == 0xde00
                    DE00    869 _USBADDR	=	0xde00
                    DE01    870 Fdynamixel_test$USBPOW$0$0 == 0xde01
                    DE01    871 _USBPOW	=	0xde01
                    DE02    872 Fdynamixel_test$USBIIF$0$0 == 0xde02
                    DE02    873 _USBIIF	=	0xde02
                    DE04    874 Fdynamixel_test$USBOIF$0$0 == 0xde04
                    DE04    875 _USBOIF	=	0xde04
                    DE06    876 Fdynamixel_test$USBCIF$0$0 == 0xde06
                    DE06    877 _USBCIF	=	0xde06
                    DE07    878 Fdynamixel_test$USBIIE$0$0 == 0xde07
                    DE07    879 _USBIIE	=	0xde07
                    DE09    880 Fdynamixel_test$USBOIE$0$0 == 0xde09
                    DE09    881 _USBOIE	=	0xde09
                    DE0B    882 Fdynamixel_test$USBCIE$0$0 == 0xde0b
                    DE0B    883 _USBCIE	=	0xde0b
                    DE0C    884 Fdynamixel_test$USBFRML$0$0 == 0xde0c
                    DE0C    885 _USBFRML	=	0xde0c
                    DE0D    886 Fdynamixel_test$USBFRMH$0$0 == 0xde0d
                    DE0D    887 _USBFRMH	=	0xde0d
                    DE0E    888 Fdynamixel_test$USBINDEX$0$0 == 0xde0e
                    DE0E    889 _USBINDEX	=	0xde0e
                    DE10    890 Fdynamixel_test$USBMAXI$0$0 == 0xde10
                    DE10    891 _USBMAXI	=	0xde10
                    DE11    892 Fdynamixel_test$USBCSIL$0$0 == 0xde11
                    DE11    893 _USBCSIL	=	0xde11
                    DE12    894 Fdynamixel_test$USBCSIH$0$0 == 0xde12
                    DE12    895 _USBCSIH	=	0xde12
                    DE13    896 Fdynamixel_test$USBMAXO$0$0 == 0xde13
                    DE13    897 _USBMAXO	=	0xde13
                    DE14    898 Fdynamixel_test$USBCSOL$0$0 == 0xde14
                    DE14    899 _USBCSOL	=	0xde14
                    DE15    900 Fdynamixel_test$USBCSOH$0$0 == 0xde15
                    DE15    901 _USBCSOH	=	0xde15
                    DE16    902 Fdynamixel_test$USBCNTL$0$0 == 0xde16
                    DE16    903 _USBCNTL	=	0xde16
                    DE17    904 Fdynamixel_test$USBCNTH$0$0 == 0xde17
                    DE17    905 _USBCNTH	=	0xde17
                    DE20    906 Fdynamixel_test$USBF0$0$0 == 0xde20
                    DE20    907 _USBF0	=	0xde20
                    DE22    908 Fdynamixel_test$USBF1$0$0 == 0xde22
                    DE22    909 _USBF1	=	0xde22
                    DE24    910 Fdynamixel_test$USBF2$0$0 == 0xde24
                    DE24    911 _USBF2	=	0xde24
                    DE26    912 Fdynamixel_test$USBF3$0$0 == 0xde26
                    DE26    913 _USBF3	=	0xde26
                    DE28    914 Fdynamixel_test$USBF4$0$0 == 0xde28
                    DE28    915 _USBF4	=	0xde28
                    DE2A    916 Fdynamixel_test$USBF5$0$0 == 0xde2a
                    DE2A    917 _USBF5	=	0xde2a
                            918 ;--------------------------------------------------------
                            919 ; absolute external ram data
                            920 ;--------------------------------------------------------
                            921 	.area XABS    (ABS,XDATA)
                            922 ;--------------------------------------------------------
                            923 ; external initialized ram data
                            924 ;--------------------------------------------------------
                            925 	.area XISEG   (XDATA)
                            926 	.area HOME    (CODE)
                            927 	.area GSINIT0 (CODE)
                            928 	.area GSINIT1 (CODE)
                            929 	.area GSINIT2 (CODE)
                            930 	.area GSINIT3 (CODE)
                            931 	.area GSINIT4 (CODE)
                            932 	.area GSINIT5 (CODE)
                            933 	.area GSINIT  (CODE)
                            934 	.area GSFINAL (CODE)
                            935 	.area CSEG    (CODE)
                            936 ;--------------------------------------------------------
                            937 ; interrupt vector 
                            938 ;--------------------------------------------------------
                            939 	.area HOME    (CODE)
   0400                     940 __interrupt_vect:
   0400 02 04 7B            941 	ljmp	__sdcc_gsinit_startup
   0403 32                  942 	reti
   0404                     943 	.ds	7
   040B 32                  944 	reti
   040C                     945 	.ds	7
   0413 32                  946 	reti
   0414                     947 	.ds	7
   041B 02 14 D7            948 	ljmp	_ISR_URX1
   041E                     949 	.ds	5
   0423 32                  950 	reti
   0424                     951 	.ds	7
   042B 32                  952 	reti
   042C                     953 	.ds	7
   0433 32                  954 	reti
   0434                     955 	.ds	7
   043B 32                  956 	reti
   043C                     957 	.ds	7
   0443 32                  958 	reti
   0444                     959 	.ds	7
   044B 32                  960 	reti
   044C                     961 	.ds	7
   0453 32                  962 	reti
   0454                     963 	.ds	7
   045B 32                  964 	reti
   045C                     965 	.ds	7
   0463 02 1B A8            966 	ljmp	_ISR_T4
   0466                     967 	.ds	5
   046B 32                  968 	reti
   046C                     969 	.ds	7
   0473 02 14 99            970 	ljmp	_ISR_UTX1
                            971 ;--------------------------------------------------------
                            972 ; global & static initialisations
                            973 ;--------------------------------------------------------
                            974 	.area HOME    (CODE)
                            975 	.area GSINIT  (CODE)
                            976 	.area GSFINAL (CODE)
                            977 	.area GSINIT  (CODE)
                            978 	.globl __sdcc_gsinit_startup
                            979 	.globl __sdcc_program_startup
                            980 	.globl __start__stack
                            981 	.globl __mcs51_genXINIT
                            982 	.globl __mcs51_genXRAMCLEAR
                            983 	.globl __mcs51_genRAMCLEAR
                            984 ;------------------------------------------------------------
                            985 ;Allocation info for local variables in function 'updateLeds'
                            986 ;------------------------------------------------------------
                    0000    987 	G$updateLeds$0$0 ==.
                    0000    988 	C$dynamixel_test.c$87$2$3 ==.
                            989 ;	apps/dynamixel_test/dynamixel_test.c:87: static BIT dimYellowLed = 0;
   04D8 C2 03               990 	clr	_updateLeds_dimYellowLed_1_1
                    0002    991 	G$main$0$0 ==.
                    0002    992 	C$dynamixel_test.c$74$1$1 ==.
                            993 ;	apps/dynamixel_test/dynamixel_test.c:74: BIT uartRxDisabled = 0;
   04DA C2 00               994 	clr	_uartRxDisabled
                    0004    995 	G$main$0$0 ==.
                    0004    996 	C$dynamixel_test.c$78$1$1 ==.
                            997 ;	apps/dynamixel_test/dynamixel_test.c:78: BIT framingErrorActive = 0;
   04DC C2 01               998 	clr	_framingErrorActive
                    0006    999 	G$main$0$0 ==.
                    0006   1000 	C$dynamixel_test.c$80$1$1 ==.
                           1001 ;	apps/dynamixel_test/dynamixel_test.c:80: BIT errorOccurredRecently = 0;
   04DE C2 02              1002 	clr	_errorOccurredRecently
                           1003 	.area GSFINAL (CODE)
   04EB 02 04 76           1004 	ljmp	__sdcc_program_startup
                           1005 ;--------------------------------------------------------
                           1006 ; Home
                           1007 ;--------------------------------------------------------
                           1008 	.area HOME    (CODE)
                           1009 	.area HOME    (CODE)
   0476                    1010 __sdcc_program_startup:
   0476 12 11 CC           1011 	lcall	_main
                           1012 ;	return from main will lock up
   0479 80 FE              1013 	sjmp .
                           1014 ;--------------------------------------------------------
                           1015 ; code
                           1016 ;--------------------------------------------------------
                           1017 	.area CSEG    (CODE)
                           1018 ;------------------------------------------------------------
                           1019 ;Allocation info for local variables in function 'updateLeds'
                           1020 ;------------------------------------------------------------
                    0000   1021 	G$updateLeds$0$0 ==.
                    0000   1022 	C$dynamixel_test.c$85$0$0 ==.
                           1023 ;	apps/dynamixel_test/dynamixel_test.c:85: void updateLeds()
                           1024 ;	-----------------------------------------
                           1025 ;	 function updateLeds
                           1026 ;	-----------------------------------------
   0E5C                    1027 _updateLeds:
                    0007   1028 	ar7 = 0x07
                    0006   1029 	ar6 = 0x06
                    0005   1030 	ar5 = 0x05
                    0004   1031 	ar4 = 0x04
                    0003   1032 	ar3 = 0x03
                    0002   1033 	ar2 = 0x02
                    0001   1034 	ar1 = 0x01
                    0000   1035 	ar0 = 0x00
                    0000   1036 	C$dynamixel_test.c$93$1$1 ==.
                           1037 ;	apps/dynamixel_test/dynamixel_test.c:93: now = (uint16)getMs();
   0E5C 12 1B CD           1038 	lcall	_getMs
   0E5F AC 82              1039 	mov	r4,dpl
   0E61 AD 83              1040 	mov	r5,dph
   0E63 AE F0              1041 	mov	r6,b
   0E65 FF                 1042 	mov	r7,a
                    000A   1043 	C$dynamixel_test.c$95$1$1 ==.
                           1044 ;	apps/dynamixel_test/dynamixel_test.c:95: if ((uint8)(now - lastErrorTime) > 100)
   0E66 78 6D              1045 	mov	r0,#_lastErrorTime
   0E68 D3                 1046 	setb	c
   0E69 E2                 1047 	movx	a,@r0
   0E6A 9C                 1048 	subb	a,r4
   0E6B F4                 1049 	cpl	a
   0E6C FC                 1050 	mov  r4,a
   0E6D 24 9B              1051 	add	a,#0xff - 0x64
   0E6F 50 02              1052 	jnc	00102$
                    0015   1053 	C$dynamixel_test.c$97$2$2 ==.
                           1054 ;	apps/dynamixel_test/dynamixel_test.c:97: errorOccurredRecently = 0;
   0E71 C2 02              1055 	clr	_errorOccurredRecently
   0E73                    1056 00102$:
                    0017   1057 	C$dynamixel_test.c$100$2$3 ==.
                           1058 ;	apps/dynamixel_test/dynamixel_test.c:100: LED_YELLOW(errorOccurredRecently || uartRxDisabled);
   0E73 20 02 07           1059 	jb	_errorOccurredRecently,00108$
   0E76 20 00 04           1060 	jb	_uartRxDisabled,00108$
   0E79 7F 00              1061 	mov	r7,#0x00
   0E7B 80 02              1062 	sjmp	00109$
   0E7D                    1063 00108$:
   0E7D 7F 01              1064 	mov	r7,#0x01
   0E7F                    1065 00109$:
   0E7F EF                 1066 	mov	a,r7
   0E80 60 05              1067 	jz	00105$
   0E82 43 FF 04           1068 	orl	_P2DIR,#0x04
   0E85 80 07              1069 	sjmp	00103$
   0E87                    1070 00105$:
   0E87 AF FF              1071 	mov	r7,_P2DIR
   0E89 53 07 FB           1072 	anl	ar7,#0xFB
   0E8C 8F FF              1073 	mov	_P2DIR,r7
   0E8E                    1074 00103$:
                    0032   1075 	C$dynamixel_test.c$101$2$3 ==.
                    0032   1076 	XG$updateLeds$0$0 ==.
   0E8E 22                 1077 	ret
                           1078 ;------------------------------------------------------------
                           1079 ;Allocation info for local variables in function 'ioRxSignals'
                           1080 ;------------------------------------------------------------
                    0033   1081 	G$ioRxSignals$0$0 ==.
                    0033   1082 	C$dynamixel_test.c$106$2$3 ==.
                           1083 ;	apps/dynamixel_test/dynamixel_test.c:106: uint8 ioRxSignals()
                           1084 ;	-----------------------------------------
                           1085 ;	 function ioRxSignals
                           1086 ;	-----------------------------------------
   0E8F                    1087 _ioRxSignals:
                    0033   1088 	C$dynamixel_test.c$108$1$3 ==.
                           1089 ;	apps/dynamixel_test/dynamixel_test.c:108: uint8 signals = 0;
   0E8F 7F 00              1090 	mov	r7,#0x00
                    0035   1091 	C$dynamixel_test.c$110$1$1 ==.
                           1092 ;	apps/dynamixel_test/dynamixel_test.c:110: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   0E91 90 20 56           1093 	mov	dptr,#_param_CD_pin
   0E94 E4                 1094 	clr	a
   0E95 93                 1095 	movc	a,@a+dptr
   0E96 FB                 1096 	mov	r3,a
   0E97 74 01              1097 	mov	a,#0x01
   0E99 93                 1098 	movc	a,@a+dptr
   0E9A FC                 1099 	mov	r4,a
   0E9B 74 02              1100 	mov	a,#0x02
   0E9D 93                 1101 	movc	a,@a+dptr
   0E9E FD                 1102 	mov	r5,a
   0E9F 74 03              1103 	mov	a,#0x03
   0EA1 93                 1104 	movc	a,@a+dptr
   0EA2 FE                 1105 	mov	r6,a
   0EA3 20 E7 0B           1106 	jb	acc.7,00105$
   0EA6 8B 82              1107 	mov	dpl,r3
   0EA8 C0 07              1108 	push	ar7
   0EAA 12 1F 44           1109 	lcall	_isPinHigh
   0EAD D0 07              1110 	pop	ar7
   0EAF 40 20              1111 	jc	00101$
   0EB1                    1112 00105$:
                    0055   1113 	C$dynamixel_test.c$111$1$1 ==.
                           1114 ;	apps/dynamixel_test/dynamixel_test.c:111: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   0EB1 90 20 46           1115 	mov	dptr,#_param_nCD_pin
   0EB4 E4                 1116 	clr	a
   0EB5 93                 1117 	movc	a,@a+dptr
   0EB6 FB                 1118 	mov	r3,a
   0EB7 74 01              1119 	mov	a,#0x01
   0EB9 93                 1120 	movc	a,@a+dptr
   0EBA FC                 1121 	mov	r4,a
   0EBB 74 02              1122 	mov	a,#0x02
   0EBD 93                 1123 	movc	a,@a+dptr
   0EBE FD                 1124 	mov	r5,a
   0EBF 74 03              1125 	mov	a,#0x03
   0EC1 93                 1126 	movc	a,@a+dptr
   0EC2 FE                 1127 	mov	r6,a
   0EC3 20 E7 0D           1128 	jb	acc.7,00102$
   0EC6 8B 82              1129 	mov	dpl,r3
   0EC8 C0 07              1130 	push	ar7
   0ECA 12 1F 44           1131 	lcall	_isPinHigh
   0ECD D0 07              1132 	pop	ar7
   0ECF 40 02              1133 	jc	00102$
   0ED1                    1134 00101$:
                    0075   1135 	C$dynamixel_test.c$113$2$2 ==.
                           1136 ;	apps/dynamixel_test/dynamixel_test.c:113: signals |= 2;
   0ED1 7F 02              1137 	mov	r7,#0x02
   0ED3                    1138 00102$:
                    0077   1139 	C$dynamixel_test.c$116$1$1 ==.
                           1140 ;	apps/dynamixel_test/dynamixel_test.c:116: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   0ED3 90 20 52           1141 	mov	dptr,#_param_DSR_pin
   0ED6 E4                 1142 	clr	a
   0ED7 93                 1143 	movc	a,@a+dptr
   0ED8 FB                 1144 	mov	r3,a
   0ED9 74 01              1145 	mov	a,#0x01
   0EDB 93                 1146 	movc	a,@a+dptr
   0EDC FC                 1147 	mov	r4,a
   0EDD 74 02              1148 	mov	a,#0x02
   0EDF 93                 1149 	movc	a,@a+dptr
   0EE0 FD                 1150 	mov	r5,a
   0EE1 74 03              1151 	mov	a,#0x03
   0EE3 93                 1152 	movc	a,@a+dptr
   0EE4 FE                 1153 	mov	r6,a
   0EE5 20 E7 0B           1154 	jb	acc.7,00110$
   0EE8 8B 82              1155 	mov	dpl,r3
   0EEA C0 07              1156 	push	ar7
   0EEC 12 1F 44           1157 	lcall	_isPinHigh
   0EEF D0 07              1158 	pop	ar7
   0EF1 40 20              1159 	jc	00106$
   0EF3                    1160 00110$:
                    0097   1161 	C$dynamixel_test.c$117$1$1 ==.
                           1162 ;	apps/dynamixel_test/dynamixel_test.c:117: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   0EF3 90 20 42           1163 	mov	dptr,#_param_nDSR_pin
   0EF6 E4                 1164 	clr	a
   0EF7 93                 1165 	movc	a,@a+dptr
   0EF8 FB                 1166 	mov	r3,a
   0EF9 74 01              1167 	mov	a,#0x01
   0EFB 93                 1168 	movc	a,@a+dptr
   0EFC FC                 1169 	mov	r4,a
   0EFD 74 02              1170 	mov	a,#0x02
   0EFF 93                 1171 	movc	a,@a+dptr
   0F00 FD                 1172 	mov	r5,a
   0F01 74 03              1173 	mov	a,#0x03
   0F03 93                 1174 	movc	a,@a+dptr
   0F04 FE                 1175 	mov	r6,a
   0F05 20 E7 0E           1176 	jb	acc.7,00107$
   0F08 8B 82              1177 	mov	dpl,r3
   0F0A C0 07              1178 	push	ar7
   0F0C 12 1F 44           1179 	lcall	_isPinHigh
   0F0F D0 07              1180 	pop	ar7
   0F11 40 03              1181 	jc	00107$
   0F13                    1182 00106$:
                    00B7   1183 	C$dynamixel_test.c$119$2$3 ==.
                           1184 ;	apps/dynamixel_test/dynamixel_test.c:119: signals |= 1;
   0F13 43 07 01           1185 	orl	ar7,#0x01
   0F16                    1186 00107$:
                    00BA   1187 	C$dynamixel_test.c$122$1$1 ==.
                           1188 ;	apps/dynamixel_test/dynamixel_test.c:122: return signals;
   0F16 8F 82              1189 	mov	dpl,r7
                    00BC   1190 	C$dynamixel_test.c$123$1$1 ==.
                    00BC   1191 	XG$ioRxSignals$0$0 ==.
   0F18 22                 1192 	ret
                           1193 ;------------------------------------------------------------
                           1194 ;Allocation info for local variables in function 'ioTxSignals'
                           1195 ;------------------------------------------------------------
                    00BD   1196 	G$ioTxSignals$0$0 ==.
                    00BD   1197 	C$dynamixel_test.c$129$1$1 ==.
                           1198 ;	apps/dynamixel_test/dynamixel_test.c:129: void ioTxSignals(uint8 signals)
                           1199 ;	-----------------------------------------
                           1200 ;	 function ioTxSignals
                           1201 ;	-----------------------------------------
   0F19                    1202 _ioTxSignals:
   0F19 E5 82              1203 	mov	a,dpl
   0F1B 78 70              1204 	mov	r0,#_ioTxSignals_signals_1_1
   0F1D F2                 1205 	movx	@r0,a
                    00C2   1206 	C$dynamixel_test.c$135$1$1 ==.
                           1207 ;	apps/dynamixel_test/dynamixel_test.c:135: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   0F1E 78 70              1208 	mov	r0,#_ioTxSignals_signals_1_1
   0F20 E2                 1209 	movx	a,@r0
   0F21 54 01              1210 	anl	a,#0x01
   0F23 FE                 1211 	mov	r6,a
   0F24 B4 01 00           1212 	cjne	a,#0x01,00112$
   0F27                    1213 00112$:
   0F27 E4                 1214 	clr	a
   0F28 33                 1215 	rlc	a
   0F29 24 FF              1216 	add	a,#0xff
   0F2B 92 04              1217 	mov	_ioTxSignals_sloc0_1_0,c
   0F2D 90 20 3A           1218 	mov	dptr,#_param_nDTR_pin
   0F30 E4                 1219 	clr	a
   0F31 93                 1220 	movc	a,@a+dptr
   0F32 FA                 1221 	mov	r2,a
   0F33 74 01              1222 	mov	a,#0x01
   0F35 93                 1223 	movc	a,@a+dptr
   0F36 74 02              1224 	mov	a,#0x02
   0F38 93                 1225 	movc	a,@a+dptr
   0F39 74 03              1226 	mov	a,#0x03
   0F3B 93                 1227 	movc	a,@a+dptr
   0F3C 8A 82              1228 	mov	dpl,r2
   0F3E A2 04              1229 	mov	c,_ioTxSignals_sloc0_1_0
   0F40 92 F0              1230 	mov	b[0],c
   0F42 C0 06              1231 	push	ar6
   0F44 85 F0 22           1232 	mov	bits,b
   0F47 12 1C 2D           1233 	lcall	_setDigitalOutput
   0F4A D0 06              1234 	pop	ar6
                    00F0   1235 	C$dynamixel_test.c$136$1$1 ==.
                           1236 ;	apps/dynamixel_test/dynamixel_test.c:136: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   0F4C 78 70              1237 	mov	r0,#_ioTxSignals_signals_1_1
   0F4E E2                 1238 	movx	a,@r0
   0F4F 03                 1239 	rr	a
   0F50 54 01              1240 	anl	a,#0x01
   0F52 FD                 1241 	mov	r5,a
   0F53 B4 01 00           1242 	cjne	a,#0x01,00113$
   0F56                    1243 00113$:
   0F56 E4                 1244 	clr	a
   0F57 33                 1245 	rlc	a
   0F58 24 FF              1246 	add	a,#0xff
   0F5A 92 04              1247 	mov	_ioTxSignals_sloc0_1_0,c
   0F5C 90 20 3E           1248 	mov	dptr,#_param_nRTS_pin
   0F5F E4                 1249 	clr	a
   0F60 93                 1250 	movc	a,@a+dptr
   0F61 FA                 1251 	mov	r2,a
   0F62 74 01              1252 	mov	a,#0x01
   0F64 93                 1253 	movc	a,@a+dptr
   0F65 74 02              1254 	mov	a,#0x02
   0F67 93                 1255 	movc	a,@a+dptr
   0F68 74 03              1256 	mov	a,#0x03
   0F6A 93                 1257 	movc	a,@a+dptr
   0F6B 8A 82              1258 	mov	dpl,r2
   0F6D A2 04              1259 	mov	c,_ioTxSignals_sloc0_1_0
   0F6F 92 F0              1260 	mov	b[0],c
   0F71 C0 06              1261 	push	ar6
   0F73 C0 05              1262 	push	ar5
   0F75 85 F0 22           1263 	mov	bits,b
   0F78 12 1C 2D           1264 	lcall	_setDigitalOutput
   0F7B D0 05              1265 	pop	ar5
   0F7D D0 06              1266 	pop	ar6
                    0123   1267 	C$dynamixel_test.c$139$1$1 ==.
                           1268 ;	apps/dynamixel_test/dynamixel_test.c:139: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0F7F EE                 1269 	mov	a,r6
   0F80 24 FF              1270 	add	a,#0xff
   0F82 92 04              1271 	mov	_ioTxSignals_sloc0_1_0,c
   0F84 90 20 4A           1272 	mov	dptr,#_param_DTR_pin
   0F87 E4                 1273 	clr	a
   0F88 93                 1274 	movc	a,@a+dptr
   0F89 FB                 1275 	mov	r3,a
   0F8A 74 01              1276 	mov	a,#0x01
   0F8C 93                 1277 	movc	a,@a+dptr
   0F8D 74 02              1278 	mov	a,#0x02
   0F8F 93                 1279 	movc	a,@a+dptr
   0F90 74 03              1280 	mov	a,#0x03
   0F92 93                 1281 	movc	a,@a+dptr
   0F93 8B 82              1282 	mov	dpl,r3
   0F95 A2 04              1283 	mov	c,_ioTxSignals_sloc0_1_0
   0F97 92 F0              1284 	mov	b[0],c
   0F99 C0 05              1285 	push	ar5
   0F9B 85 F0 22           1286 	mov	bits,b
   0F9E 12 1C 2D           1287 	lcall	_setDigitalOutput
   0FA1 D0 05              1288 	pop	ar5
                    0147   1289 	C$dynamixel_test.c$140$1$1 ==.
                           1290 ;	apps/dynamixel_test/dynamixel_test.c:140: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   0FA3 ED                 1291 	mov	a,r5
   0FA4 24 FF              1292 	add	a,#0xff
   0FA6 92 04              1293 	mov	_ioTxSignals_sloc0_1_0,c
   0FA8 90 20 4E           1294 	mov	dptr,#_param_RTS_pin
   0FAB E4                 1295 	clr	a
   0FAC 93                 1296 	movc	a,@a+dptr
   0FAD FC                 1297 	mov	r4,a
   0FAE 74 01              1298 	mov	a,#0x01
   0FB0 93                 1299 	movc	a,@a+dptr
   0FB1 74 02              1300 	mov	a,#0x02
   0FB3 93                 1301 	movc	a,@a+dptr
   0FB4 74 03              1302 	mov	a,#0x03
   0FB6 93                 1303 	movc	a,@a+dptr
   0FB7 8C 82              1304 	mov	dpl,r4
   0FB9 A2 04              1305 	mov	c,_ioTxSignals_sloc0_1_0
   0FBB 92 F0              1306 	mov	b[0],c
   0FBD 85 F0 22           1307 	mov	bits,b
   0FC0 12 1C 2D           1308 	lcall	_setDigitalOutput
                    0167   1309 	C$dynamixel_test.c$143$1$1 ==.
                           1310 ;	apps/dynamixel_test/dynamixel_test.c:143: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   0FC3 78 72              1311 	mov	r0,#_ioTxSignals_lastSignals_1_1
   0FC5 E2                 1312 	movx	a,@r0
   0FC6 54 01              1313 	anl	a,#0x01
   0FC8 60 02              1314 	jz	00115$
   0FCA 80 30              1315 	sjmp	00104$
   0FCC                    1316 00115$:
   0FCC 78 70              1317 	mov	r0,#_ioTxSignals_signals_1_1
   0FCE E2                 1318 	movx	a,@r0
   0FCF 54 01              1319 	anl	a,#0x01
   0FD1 60 29              1320 	jz	00104$
                    0177   1321 	C$dynamixel_test.c$147$2$2 ==.
                           1322 ;	apps/dynamixel_test/dynamixel_test.c:147: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   0FD3 90 20 5A           1323 	mov	dptr,#_param_arduino_DTR_pin
   0FD6 E4                 1324 	clr	a
   0FD7 93                 1325 	movc	a,@a+dptr
   0FD8 FC                 1326 	mov	r4,a
   0FD9 74 01              1327 	mov	a,#0x01
   0FDB 93                 1328 	movc	a,@a+dptr
   0FDC 74 02              1329 	mov	a,#0x02
   0FDE 93                 1330 	movc	a,@a+dptr
   0FDF 74 03              1331 	mov	a,#0x03
   0FE1 93                 1332 	movc	a,@a+dptr
   0FE2 8C 82              1333 	mov	dpl,r4
   0FE4 D2 F0              1334 	setb	b[0]
   0FE6 85 F0 22           1335 	mov	bits,b
   0FE9 12 1C 2D           1336 	lcall	_setDigitalOutput
                    0190   1337 	C$dynamixel_test.c$148$2$2 ==.
                           1338 ;	apps/dynamixel_test/dynamixel_test.c:148: nTrstPulseStartTime = getMs();
   0FEC 12 1B CD           1339 	lcall	_getMs
   0FEF AC 82              1340 	mov	r4,dpl
   0FF1 AD 83              1341 	mov	r5,dph
   0FF3 AE F0              1342 	mov	r6,b
   0FF5 FF                 1343 	mov	r7,a
   0FF6 78 71              1344 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0FF8 EC                 1345 	mov	a,r4
   0FF9 F2                 1346 	movx	@r0,a
   0FFA 80 2F              1347 	sjmp	00105$
   0FFC                    1348 00104$:
                    01A0   1349 	C$dynamixel_test.c$150$1$1 ==.
                           1350 ;	apps/dynamixel_test/dynamixel_test.c:150: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   0FFC 12 1B CD           1351 	lcall	_getMs
   0FFF AC 82              1352 	mov	r4,dpl
   1001 AD 83              1353 	mov	r5,dph
   1003 AE F0              1354 	mov	r6,b
   1005 FF                 1355 	mov	r7,a
   1006 78 71              1356 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   1008 D3                 1357 	setb	c
   1009 E2                 1358 	movx	a,@r0
   100A 9C                 1359 	subb	a,r4
   100B F4                 1360 	cpl	a
   100C FC                 1361 	mov	r4,a
   100D BC 02 00           1362 	cjne	r4,#0x02,00117$
   1010                    1363 00117$:
   1010 40 19              1364 	jc	00105$
                    01B6   1365 	C$dynamixel_test.c$152$2$3 ==.
                           1366 ;	apps/dynamixel_test/dynamixel_test.c:152: setDigitalOutput(param_arduino_DTR_pin, LOW);
   1012 90 20 5A           1367 	mov	dptr,#_param_arduino_DTR_pin
   1015 E4                 1368 	clr	a
   1016 93                 1369 	movc	a,@a+dptr
   1017 FC                 1370 	mov	r4,a
   1018 74 01              1371 	mov	a,#0x01
   101A 93                 1372 	movc	a,@a+dptr
   101B 74 02              1373 	mov	a,#0x02
   101D 93                 1374 	movc	a,@a+dptr
   101E 74 03              1375 	mov	a,#0x03
   1020 93                 1376 	movc	a,@a+dptr
   1021 8C 82              1377 	mov	dpl,r4
   1023 C2 F0              1378 	clr	b[0]
   1025 85 F0 22           1379 	mov	bits,b
   1028 12 1C 2D           1380 	lcall	_setDigitalOutput
   102B                    1381 00105$:
                    01CF   1382 	C$dynamixel_test.c$155$1$1 ==.
                           1383 ;	apps/dynamixel_test/dynamixel_test.c:155: lastSignals = signals;
   102B 78 70              1384 	mov	r0,#_ioTxSignals_signals_1_1
   102D 79 72              1385 	mov	r1,#_ioTxSignals_lastSignals_1_1
   102F E2                 1386 	movx	a,@r0
   1030 F3                 1387 	movx	@r1,a
                    01D5   1388 	C$dynamixel_test.c$156$1$1 ==.
                    01D5   1389 	XG$ioTxSignals$0$0 ==.
   1031 22                 1390 	ret
                           1391 ;------------------------------------------------------------
                           1392 ;Allocation info for local variables in function 'errorOccurred'
                           1393 ;------------------------------------------------------------
                    01D6   1394 	G$errorOccurred$0$0 ==.
                    01D6   1395 	C$dynamixel_test.c$158$1$1 ==.
                           1396 ;	apps/dynamixel_test/dynamixel_test.c:158: void errorOccurred()
                           1397 ;	-----------------------------------------
                           1398 ;	 function errorOccurred
                           1399 ;	-----------------------------------------
   1032                    1400 _errorOccurred:
                    01D6   1401 	C$dynamixel_test.c$160$1$1 ==.
                           1402 ;	apps/dynamixel_test/dynamixel_test.c:160: lastErrorTime = (uint8)getMs();
   1032 12 1B CD           1403 	lcall	_getMs
   1035 AC 82              1404 	mov	r4,dpl
   1037 78 6D              1405 	mov	r0,#_lastErrorTime
   1039 EC                 1406 	mov	a,r4
   103A F2                 1407 	movx	@r0,a
                    01DF   1408 	C$dynamixel_test.c$161$1$1 ==.
                           1409 ;	apps/dynamixel_test/dynamixel_test.c:161: errorOccurredRecently = 1;
   103B D2 02              1410 	setb	_errorOccurredRecently
                    01E1   1411 	C$dynamixel_test.c$162$1$1 ==.
                    01E1   1412 	XG$errorOccurred$0$0 ==.
   103D 22                 1413 	ret
                           1414 ;------------------------------------------------------------
                           1415 ;Allocation info for local variables in function 'errorService'
                           1416 ;------------------------------------------------------------
                           1417 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1418 ;------------------------------------------------------------
                    01E2   1419 	G$errorService$0$0 ==.
                    01E2   1420 	C$dynamixel_test.c$164$1$1 ==.
                           1421 ;	apps/dynamixel_test/dynamixel_test.c:164: void errorService()
                           1422 ;	-----------------------------------------
                           1423 ;	 function errorService
                           1424 ;	-----------------------------------------
   103E                    1425 _errorService:
                    01E2   1426 	C$dynamixel_test.c$168$1$1 ==.
                           1427 ;	apps/dynamixel_test/dynamixel_test.c:168: if (uart1RxBufferFullOccurred)
                    01E2   1428 	C$dynamixel_test.c$170$2$2 ==.
                           1429 ;	apps/dynamixel_test/dynamixel_test.c:170: uart1RxBufferFullOccurred = 0;
   103E 10 07 02           1430 	jbc	_uart1RxBufferFullOccurred,00129$
   1041 80 03              1431 	sjmp	00102$
   1043                    1432 00129$:
                    01E7   1433 	C$dynamixel_test.c$171$2$2 ==.
                           1434 ;	apps/dynamixel_test/dynamixel_test.c:171: errorOccurred();
   1043 12 10 32           1435 	lcall	_errorOccurred
   1046                    1436 00102$:
                    01EA   1437 	C$dynamixel_test.c$174$1$1 ==.
                           1438 ;	apps/dynamixel_test/dynamixel_test.c:174: if (uart1RxFramingErrorOccurred)
                    01EA   1439 	C$dynamixel_test.c$176$2$3 ==.
                           1440 ;	apps/dynamixel_test/dynamixel_test.c:176: uart1RxFramingErrorOccurred = 0;
   1046 10 06 02           1441 	jbc	_uart1RxFramingErrorOccurred,00130$
   1049 80 41              1442 	sjmp	00106$
   104B                    1443 00130$:
                    01EF   1444 	C$dynamixel_test.c$179$2$3 ==.
                           1445 ;	apps/dynamixel_test/dynamixel_test.c:179: framingErrorActive = 1;
   104B D2 01              1446 	setb	_framingErrorActive
                    01F1   1447 	C$dynamixel_test.c$180$2$3 ==.
                           1448 ;	apps/dynamixel_test/dynamixel_test.c:180: errorOccurred();
   104D 12 10 32           1449 	lcall	_errorOccurred
                    01F4   1450 	C$dynamixel_test.c$182$2$3 ==.
                           1451 ;	apps/dynamixel_test/dynamixel_test.c:182: if (param_framing_error_ms > 0)
   1050 90 20 5E           1452 	mov	dptr,#_param_framing_error_ms
   1053 E4                 1453 	clr	a
   1054 93                 1454 	movc	a,@a+dptr
   1055 FC                 1455 	mov	r4,a
   1056 74 01              1456 	mov	a,#0x01
   1058 93                 1457 	movc	a,@a+dptr
   1059 FD                 1458 	mov	r5,a
   105A 74 02              1459 	mov	a,#0x02
   105C 93                 1460 	movc	a,@a+dptr
   105D FE                 1461 	mov	r6,a
   105E 74 03              1462 	mov	a,#0x03
   1060 93                 1463 	movc	a,@a+dptr
   1061 FF                 1464 	mov	r7,a
   1062 C3                 1465 	clr	c
   1063 E4                 1466 	clr	a
   1064 9C                 1467 	subb	a,r4
   1065 E4                 1468 	clr	a
   1066 9D                 1469 	subb	a,r5
   1067 E4                 1470 	clr	a
   1068 9E                 1471 	subb	a,r6
   1069 E4                 1472 	clr	a
   106A 64 80              1473 	xrl	a,#0x80
   106C 8F F0              1474 	mov	b,r7
   106E 63 F0 80           1475 	xrl	b,#0x80
   1071 95 F0              1476 	subb	a,b
   1073 50 17              1477 	jnc	00106$
                    0219   1478 	C$dynamixel_test.c$185$3$4 ==.
                           1479 ;	apps/dynamixel_test/dynamixel_test.c:185: U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
   1075 AF F8              1480 	mov	r7,_U1CSR
   1077 53 07 BF           1481 	anl	ar7,#0xBF
   107A 8F F8              1482 	mov	_U1CSR,r7
                    0220   1483 	C$dynamixel_test.c$186$3$4 ==.
                           1484 ;	apps/dynamixel_test/dynamixel_test.c:186: uartRxDisabled = 1;
   107C D2 00              1485 	setb	_uartRxDisabled
                    0222   1486 	C$dynamixel_test.c$187$3$4 ==.
                           1487 ;	apps/dynamixel_test/dynamixel_test.c:187: lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
   107E 12 1B CD           1488 	lcall	_getMs
   1081 AC 82              1489 	mov	r4,dpl
   1083 AD 83              1490 	mov	r5,dph
   1085 AE F0              1491 	mov	r6,b
   1087 FF                 1492 	mov	r7,a
   1088 78 73              1493 	mov	r0,#_errorService_lastRxLowTime_1_1
   108A EC                 1494 	mov	a,r4
   108B F2                 1495 	movx	@r0,a
   108C                    1496 00106$:
                    0230   1497 	C$dynamixel_test.c$191$1$1 ==.
                           1498 ;	apps/dynamixel_test/dynamixel_test.c:191: if (framingErrorActive)
   108C 30 01 0F           1499 	jnb	_framingErrorActive,00111$
                    0233   1500 	C$dynamixel_test.c$193$2$5 ==.
                           1501 ;	apps/dynamixel_test/dynamixel_test.c:193: if (!isPinHigh(17))
   108F 75 82 11           1502 	mov	dpl,#0x11
   1092 12 1F 44           1503 	lcall	_isPinHigh
   1095 40 05              1504 	jc	00108$
                    023B   1505 	C$dynamixel_test.c$195$3$6 ==.
                           1506 ;	apps/dynamixel_test/dynamixel_test.c:195: errorOccurred();
   1097 12 10 32           1507 	lcall	_errorOccurred
   109A 80 02              1508 	sjmp	00111$
   109C                    1509 00108$:
                    0240   1510 	C$dynamixel_test.c$199$3$7 ==.
                           1511 ;	apps/dynamixel_test/dynamixel_test.c:199: framingErrorActive = 0;
   109C C2 01              1512 	clr	_framingErrorActive
   109E                    1513 00111$:
                    0242   1514 	C$dynamixel_test.c$203$1$1 ==.
                           1515 ;	apps/dynamixel_test/dynamixel_test.c:203: if (uartRxDisabled)
   109E 30 00 60           1516 	jnb	_uartRxDisabled,00119$
                    0245   1517 	C$dynamixel_test.c$205$2$8 ==.
                           1518 ;	apps/dynamixel_test/dynamixel_test.c:205: if (!isPinHigh(17))
   10A1 75 82 11           1519 	mov	dpl,#0x11
   10A4 12 1F 44           1520 	lcall	_isPinHigh
   10A7 40 10              1521 	jc	00115$
                    024D   1522 	C$dynamixel_test.c$208$3$9 ==.
                           1523 ;	apps/dynamixel_test/dynamixel_test.c:208: lastRxLowTime = (uint8)getMs();
   10A9 12 1B CD           1524 	lcall	_getMs
   10AC AC 82              1525 	mov	r4,dpl
   10AE AD 83              1526 	mov	r5,dph
   10B0 AE F0              1527 	mov	r6,b
   10B2 FF                 1528 	mov	r7,a
   10B3 78 73              1529 	mov	r0,#_errorService_lastRxLowTime_1_1
   10B5 EC                 1530 	mov	a,r4
   10B6 F2                 1531 	movx	@r0,a
   10B7 80 48              1532 	sjmp	00119$
   10B9                    1533 00115$:
                    025D   1534 	C$dynamixel_test.c$210$2$8 ==.
                           1535 ;	apps/dynamixel_test/dynamixel_test.c:210: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   10B9 12 1B CD           1536 	lcall	_getMs
   10BC AC 82              1537 	mov	r4,dpl
   10BE AD 83              1538 	mov	r5,dph
   10C0 78 73              1539 	mov	r0,#_errorService_lastRxLowTime_1_1
   10C2 D3                 1540 	setb	c
   10C3 E2                 1541 	movx	a,@r0
   10C4 9C                 1542 	subb	a,r4
   10C5 F4                 1543 	cpl	a
   10C6 FC                 1544 	mov	r4,a
   10C7 90 20 5E           1545 	mov	dptr,#_param_framing_error_ms
   10CA E4                 1546 	clr	a
   10CB 93                 1547 	movc	a,@a+dptr
   10CC F5 0D              1548 	mov	_errorService_sloc0_1_0,a
   10CE 74 01              1549 	mov	a,#0x01
   10D0 93                 1550 	movc	a,@a+dptr
   10D1 F5 0E              1551 	mov	(_errorService_sloc0_1_0 + 1),a
   10D3 74 02              1552 	mov	a,#0x02
   10D5 93                 1553 	movc	a,@a+dptr
   10D6 F5 0F              1554 	mov	(_errorService_sloc0_1_0 + 2),a
   10D8 74 03              1555 	mov	a,#0x03
   10DA 93                 1556 	movc	a,@a+dptr
   10DB F5 10              1557 	mov	(_errorService_sloc0_1_0 + 3),a
   10DD 8C 02              1558 	mov	ar2,r4
   10DF 7C 00              1559 	mov	r4,#0x00
   10E1 7E 00              1560 	mov	r6,#0x00
   10E3 7F 00              1561 	mov	r7,#0x00
   10E5 C3                 1562 	clr	c
   10E6 E5 0D              1563 	mov	a,_errorService_sloc0_1_0
   10E8 9A                 1564 	subb	a,r2
   10E9 E5 0E              1565 	mov	a,(_errorService_sloc0_1_0 + 1)
   10EB 9C                 1566 	subb	a,r4
   10EC E5 0F              1567 	mov	a,(_errorService_sloc0_1_0 + 2)
   10EE 9E                 1568 	subb	a,r6
   10EF E5 10              1569 	mov	a,(_errorService_sloc0_1_0 + 3)
   10F1 64 80              1570 	xrl	a,#0x80
   10F3 8F F0              1571 	mov	b,r7
   10F5 63 F0 80           1572 	xrl	b,#0x80
   10F8 95 F0              1573 	subb	a,b
   10FA 50 05              1574 	jnc	00119$
                    02A0   1575 	C$dynamixel_test.c$213$3$10 ==.
                           1576 ;	apps/dynamixel_test/dynamixel_test.c:213: U1CSR |= 0x40;
   10FC 43 F8 40           1577 	orl	_U1CSR,#0x40
                    02A3   1578 	C$dynamixel_test.c$214$3$10 ==.
                           1579 ;	apps/dynamixel_test/dynamixel_test.c:214: uartRxDisabled = 0;
   10FF C2 00              1580 	clr	_uartRxDisabled
   1101                    1581 00119$:
                    02A5   1582 	C$dynamixel_test.c$217$1$1 ==.
                    02A5   1583 	XG$errorService$0$0 ==.
   1101 22                 1584 	ret
                           1585 ;------------------------------------------------------------
                           1586 ;Allocation info for local variables in function 'updateSerialMode'
                           1587 ;------------------------------------------------------------
                    02A6   1588 	G$updateSerialMode$0$0 ==.
                    02A6   1589 	C$dynamixel_test.c$219$1$1 ==.
                           1590 ;	apps/dynamixel_test/dynamixel_test.c:219: void updateSerialMode()
                           1591 ;	-----------------------------------------
                           1592 ;	 function updateSerialMode
                           1593 ;	-----------------------------------------
   1102                    1594 _updateSerialMode:
                    02A6   1595 	C$dynamixel_test.c$222$1$1 ==.
                           1596 ;	apps/dynamixel_test/dynamixel_test.c:222: currentSerialMode = SERIAL_MODE_UART_RADIO;
   1102 75 0C 02           1597 	mov	_currentSerialMode,#0x02
                    02A9   1598 	C$dynamixel_test.c$223$1$1 ==.
                    02A9   1599 	XG$updateSerialMode$0$0 ==.
   1105 22                 1600 	ret
                           1601 ;------------------------------------------------------------
                           1602 ;Allocation info for local variables in function 'interpolate'
                           1603 ;------------------------------------------------------------
                           1604 ;lRtnRange                 Allocated with name '_interpolate_lRtnRange_1_1'
                           1605 ;lValRange                 Allocated with name '_interpolate_lValRange_1_1'
                           1606 ;lRelVal                   Allocated to registers 
                           1607 ;sloc0                     Allocated with name '_interpolate_sloc0_1_0'
                           1608 ;------------------------------------------------------------
                    02AA   1609 	G$interpolate$0$0 ==.
                    02AA   1610 	C$dynamixel_test.c$235$1$1 ==.
                           1611 ;	apps/dynamixel_test/dynamixel_test.c:235: int16 interpolate(int16 value, int16 minVal, int16 maxVal, int16 minRtn, int16 maxRtn){
                           1612 ;	-----------------------------------------
                           1613 ;	 function interpolate
                           1614 ;	-----------------------------------------
   1106                    1615 _interpolate:
   1106 AE 82              1616 	mov	r6,dpl
   1108 AF 83              1617 	mov	r7,dph
                    02AE   1618 	C$dynamixel_test.c$240$1$1 ==.
                           1619 ;	apps/dynamixel_test/dynamixel_test.c:240: lRtnRange = maxRtn - minRtn;
   110A 78 7A              1620 	mov	r0,#_interpolate_PARM_5
   110C 79 78              1621 	mov	r1,#_interpolate_PARM_4
   110E E3                 1622 	movx	a,@r1
   110F F5 F0              1623 	mov	b,a
   1111 C3                 1624 	clr	c
   1112 E2                 1625 	movx	a,@r0
   1113 95 F0              1626 	subb	a,b
   1115 FC                 1627 	mov	r4,a
   1116 09                 1628 	inc	r1
   1117 E3                 1629 	movx	a,@r1
   1118 F5 F0              1630 	mov	b,a
   111A 08                 1631 	inc	r0
   111B E2                 1632 	movx	a,@r0
   111C 95 F0              1633 	subb	a,b
   111E FD                 1634 	mov	r5,a
   111F 8C 11              1635 	mov	_interpolate_lRtnRange_1_1,r4
   1121 ED                 1636 	mov	a,r5
   1122 F5 12              1637 	mov	(_interpolate_lRtnRange_1_1 + 1),a
   1124 33                 1638 	rlc	a
   1125 95 E0              1639 	subb	a,acc
   1127 F5 13              1640 	mov	(_interpolate_lRtnRange_1_1 + 2),a
   1129 F5 14              1641 	mov	(_interpolate_lRtnRange_1_1 + 3),a
                    02CF   1642 	C$dynamixel_test.c$241$1$1 ==.
                           1643 ;	apps/dynamixel_test/dynamixel_test.c:241: lValRange = maxVal - minVal;
   112B 78 76              1644 	mov	r0,#_interpolate_PARM_3
   112D 79 74              1645 	mov	r1,#_interpolate_PARM_2
   112F E3                 1646 	movx	a,@r1
   1130 F5 F0              1647 	mov	b,a
   1132 C3                 1648 	clr	c
   1133 E2                 1649 	movx	a,@r0
   1134 95 F0              1650 	subb	a,b
   1136 FC                 1651 	mov	r4,a
   1137 09                 1652 	inc	r1
   1138 E3                 1653 	movx	a,@r1
   1139 F5 F0              1654 	mov	b,a
   113B 08                 1655 	inc	r0
   113C E2                 1656 	movx	a,@r0
   113D 95 F0              1657 	subb	a,b
   113F FD                 1658 	mov	r5,a
   1140 8C 15              1659 	mov	_interpolate_lValRange_1_1,r4
   1142 ED                 1660 	mov	a,r5
   1143 F5 16              1661 	mov	(_interpolate_lValRange_1_1 + 1),a
   1145 33                 1662 	rlc	a
   1146 95 E0              1663 	subb	a,acc
   1148 F5 17              1664 	mov	(_interpolate_lValRange_1_1 + 2),a
   114A F5 18              1665 	mov	(_interpolate_lValRange_1_1 + 3),a
                    02F0   1666 	C$dynamixel_test.c$242$1$1 ==.
                           1667 ;	apps/dynamixel_test/dynamixel_test.c:242: lRelVal = value - minVal;
   114C 78 74              1668 	mov	r0,#_interpolate_PARM_2
   114E D3                 1669 	setb	c
   114F E2                 1670 	movx	a,@r0
   1150 9E                 1671 	subb	a,r6
   1151 F4                 1672 	cpl	a
   1152 B3                 1673 	cpl	c
   1153 FE                 1674 	mov	r6,a
   1154 B3                 1675 	cpl	c
   1155 08                 1676 	inc	r0
   1156 E2                 1677 	movx	a,@r0
   1157 9F                 1678 	subb	a,r7
   1158 F4                 1679 	cpl	a
   1159 FF                 1680 	mov	r7,a
   115A 78 9C              1681 	mov	r0,#__mullong_PARM_2
   115C EE                 1682 	mov	a,r6
   115D F2                 1683 	movx	@r0,a
   115E 08                 1684 	inc	r0
   115F EF                 1685 	mov	a,r7
   1160 F2                 1686 	movx	@r0,a
   1161 EF                 1687 	mov	a,r7
   1162 33                 1688 	rlc	a
   1163 95 E0              1689 	subb	a,acc
   1165 08                 1690 	inc	r0
   1166 F2                 1691 	movx	@r0,a
   1167 08                 1692 	inc	r0
   1168 F2                 1693 	movx	@r0,a
                    030D   1694 	C$dynamixel_test.c$243$1$1 ==.
                           1695 ;	apps/dynamixel_test/dynamixel_test.c:243: lRtnRange =  minRtn + ( lRtnRange * lRelVal / lValRange );
   1169 85 11 82           1696 	mov	dpl,_interpolate_lRtnRange_1_1
   116C 85 12 83           1697 	mov	dph,(_interpolate_lRtnRange_1_1 + 1)
   116F 85 13 F0           1698 	mov	b,(_interpolate_lRtnRange_1_1 + 2)
   1172 E5 14              1699 	mov	a,(_interpolate_lRtnRange_1_1 + 3)
   1174 12 1A 2D           1700 	lcall	__mullong
   1177 AC 82              1701 	mov	r4,dpl
   1179 AD 83              1702 	mov	r5,dph
   117B AE F0              1703 	mov	r6,b
   117D FF                 1704 	mov	r7,a
   117E 78 82              1705 	mov	r0,#__divslong_PARM_2
   1180 E5 15              1706 	mov	a,_interpolate_lValRange_1_1
   1182 F2                 1707 	movx	@r0,a
   1183 08                 1708 	inc	r0
   1184 E5 16              1709 	mov	a,(_interpolate_lValRange_1_1 + 1)
   1186 F2                 1710 	movx	@r0,a
   1187 08                 1711 	inc	r0
   1188 E5 17              1712 	mov	a,(_interpolate_lValRange_1_1 + 2)
   118A F2                 1713 	movx	@r0,a
   118B 08                 1714 	inc	r0
   118C E5 18              1715 	mov	a,(_interpolate_lValRange_1_1 + 3)
   118E F2                 1716 	movx	@r0,a
   118F 8C 82              1717 	mov	dpl,r4
   1191 8D 83              1718 	mov	dph,r5
   1193 8E F0              1719 	mov	b,r6
   1195 EF                 1720 	mov	a,r7
   1196 12 16 0B           1721 	lcall	__divslong
   1199 85 82 19           1722 	mov	_interpolate_sloc0_1_0,dpl
   119C 85 83 1A           1723 	mov	(_interpolate_sloc0_1_0 + 1),dph
   119F 85 F0 1B           1724 	mov	(_interpolate_sloc0_1_0 + 2),b
   11A2 F5 1C              1725 	mov	(_interpolate_sloc0_1_0 + 3),a
   11A4 78 78              1726 	mov	r0,#_interpolate_PARM_4
   11A6 E2                 1727 	movx	a,@r0
   11A7 FA                 1728 	mov	r2,a
   11A8 08                 1729 	inc	r0
   11A9 E2                 1730 	movx	a,@r0
   11AA FB                 1731 	mov	r3,a
   11AB E2                 1732 	movx	a,@r0
   11AC 33                 1733 	rlc	a
   11AD 95 E0              1734 	subb	a,acc
   11AF FE                 1735 	mov	r6,a
   11B0 FF                 1736 	mov	r7,a
   11B1 E5 19              1737 	mov	a,_interpolate_sloc0_1_0
   11B3 2A                 1738 	add	a,r2
   11B4 F5 11              1739 	mov	_interpolate_lRtnRange_1_1,a
   11B6 E5 1A              1740 	mov	a,(_interpolate_sloc0_1_0 + 1)
   11B8 3B                 1741 	addc	a,r3
   11B9 F5 12              1742 	mov	(_interpolate_lRtnRange_1_1 + 1),a
   11BB E5 1B              1743 	mov	a,(_interpolate_sloc0_1_0 + 2)
   11BD 3E                 1744 	addc	a,r6
   11BE F5 13              1745 	mov	(_interpolate_lRtnRange_1_1 + 2),a
   11C0 E5 1C              1746 	mov	a,(_interpolate_sloc0_1_0 + 3)
   11C2 3F                 1747 	addc	a,r7
   11C3 F5 14              1748 	mov	(_interpolate_lRtnRange_1_1 + 3),a
                    0369   1749 	C$dynamixel_test.c$244$1$1 ==.
                           1750 ;	apps/dynamixel_test/dynamixel_test.c:244: return (int16)lRtnRange;
   11C5 85 11 82           1751 	mov	dpl,_interpolate_lRtnRange_1_1
   11C8 85 12 83           1752 	mov	dph,(_interpolate_lRtnRange_1_1 + 1)
                    036F   1753 	C$dynamixel_test.c$245$1$1 ==.
                    036F   1754 	XG$interpolate$0$0 ==.
   11CB 22                 1755 	ret
                           1756 ;------------------------------------------------------------
                           1757 ;Allocation info for local variables in function 'main'
                           1758 ;------------------------------------------------------------
                    0370   1759 	G$main$0$0 ==.
                    0370   1760 	C$dynamixel_test.c$247$1$1 ==.
                           1761 ;	apps/dynamixel_test/dynamixel_test.c:247: void main()
                           1762 ;	-----------------------------------------
                           1763 ;	 function main
                           1764 ;	-----------------------------------------
   11CC                    1765 _main:
                    0370   1766 	C$dynamixel_test.c$249$1$1 ==.
                           1767 ;	apps/dynamixel_test/dynamixel_test.c:249: systemInit();
   11CC 12 19 52           1768 	lcall	_systemInit
                    0373   1769 	C$dynamixel_test.c$252$1$1 ==.
                           1770 ;	apps/dynamixel_test/dynamixel_test.c:252: dynamixel_init();
   11CF 12 04 EE           1771 	lcall	_dynamixel_init
                    0376   1772 	C$dynamixel_test.c$255$1$1 ==.
                           1773 ;	apps/dynamixel_test/dynamixel_test.c:255: setDigitalOutput(param_arduino_DTR_pin, LOW);
   11D2 90 20 5A           1774 	mov	dptr,#_param_arduino_DTR_pin
   11D5 E4                 1775 	clr	a
   11D6 93                 1776 	movc	a,@a+dptr
   11D7 FC                 1777 	mov	r4,a
   11D8 74 01              1778 	mov	a,#0x01
   11DA 93                 1779 	movc	a,@a+dptr
   11DB 74 02              1780 	mov	a,#0x02
   11DD 93                 1781 	movc	a,@a+dptr
   11DE 74 03              1782 	mov	a,#0x03
   11E0 93                 1783 	movc	a,@a+dptr
   11E1 8C 82              1784 	mov	dpl,r4
   11E3 C2 F0              1785 	clr	b[0]
   11E5 85 F0 22           1786 	mov	bits,b
   11E8 12 1C 2D           1787 	lcall	_setDigitalOutput
                    038F   1788 	C$dynamixel_test.c$256$1$1 ==.
                           1789 ;	apps/dynamixel_test/dynamixel_test.c:256: ioTxSignals(0);
   11EB 75 82 00           1790 	mov	dpl,#0x00
   11EE 12 0F 19           1791 	lcall	_ioTxSignals
                    0395   1792 	C$dynamixel_test.c$259$1$1 ==.
                           1793 ;	apps/dynamixel_test/dynamixel_test.c:259: uart1Init();
   11F1 12 12 C8           1794 	lcall	_uart1Init
                    0398   1795 	C$dynamixel_test.c$260$1$1 ==.
                           1796 ;	apps/dynamixel_test/dynamixel_test.c:260: uart1SetBaudRate(param_baud_rate);
   11F4 90 20 36           1797 	mov	dptr,#_param_baud_rate
   11F7 E4                 1798 	clr	a
   11F8 93                 1799 	movc	a,@a+dptr
   11F9 FC                 1800 	mov	r4,a
   11FA 74 01              1801 	mov	a,#0x01
   11FC 93                 1802 	movc	a,@a+dptr
   11FD FD                 1803 	mov	r5,a
   11FE 74 02              1804 	mov	a,#0x02
   1200 93                 1805 	movc	a,@a+dptr
   1201 FE                 1806 	mov	r6,a
   1202 74 03              1807 	mov	a,#0x03
   1204 93                 1808 	movc	a,@a+dptr
   1205 8C 82              1809 	mov	dpl,r4
   1207 8D 83              1810 	mov	dph,r5
   1209 8E F0              1811 	mov	b,r6
   120B 12 12 FC           1812 	lcall	_uart1SetBaudRate
                    03B2   1813 	C$dynamixel_test.c$265$1$1 ==.
                           1814 ;	apps/dynamixel_test/dynamixel_test.c:265: updateSerialMode();
   120E 12 11 02           1815 	lcall	_updateSerialMode
                    03B5   1816 	C$dynamixel_test.c$273$1$1 ==.
                           1817 ;	apps/dynamixel_test/dynamixel_test.c:273: while(1)
   1211                    1818 00104$:
                    03B5   1819 	C$dynamixel_test.c$279$2$2 ==.
                           1820 ;	apps/dynamixel_test/dynamixel_test.c:279: updateSerialMode();
   1211 12 11 02           1821 	lcall	_updateSerialMode
                    03B8   1822 	C$dynamixel_test.c$280$2$2 ==.
                           1823 ;	apps/dynamixel_test/dynamixel_test.c:280: boardService();
   1214 12 19 5F           1824 	lcall	_boardService
                    03BB   1825 	C$dynamixel_test.c$281$2$2 ==.
                           1826 ;	apps/dynamixel_test/dynamixel_test.c:281: updateLeds();
   1217 12 0E 5C           1827 	lcall	_updateLeds
                    03BE   1828 	C$dynamixel_test.c$282$2$2 ==.
                           1829 ;	apps/dynamixel_test/dynamixel_test.c:282: errorService();
   121A 12 10 3E           1830 	lcall	_errorService
                    03C1   1831 	C$dynamixel_test.c$285$2$2 ==.
                           1832 ;	apps/dynamixel_test/dynamixel_test.c:285: ms = getMs();		// Get current time in ms
   121D 12 1B CD           1833 	lcall	_getMs
   1220 AC 82              1834 	mov	r4,dpl
   1222 AD 83              1835 	mov	r5,dph
   1224 AE F0              1836 	mov	r6,b
   1226 FF                 1837 	mov	r7,a
                    03CB   1838 	C$dynamixel_test.c$286$1$1 ==.
                           1839 ;	apps/dynamixel_test/dynamixel_test.c:286: now = ms % (uint32)10000; 	// 10 sec for a full swing
   1227 78 7D              1840 	mov	r0,#__modulong_PARM_2
   1229 74 10              1841 	mov	a,#0x10
   122B F2                 1842 	movx	@r0,a
   122C 08                 1843 	inc	r0
   122D 74 27              1844 	mov	a,#0x27
   122F F2                 1845 	movx	@r0,a
   1230 08                 1846 	inc	r0
   1231 E4                 1847 	clr	a
   1232 F2                 1848 	movx	@r0,a
   1233 08                 1849 	inc	r0
   1234 F2                 1850 	movx	@r0,a
   1235 8C 82              1851 	mov	dpl,r4
   1237 8D 83              1852 	mov	dph,r5
   1239 8E F0              1853 	mov	b,r6
   123B EF                 1854 	mov	a,r7
   123C 12 15 47           1855 	lcall	__modulong
   123F AC 82              1856 	mov	r4,dpl
   1241 AD 83              1857 	mov	r5,dph
   1243 AE F0              1858 	mov	r6,b
   1245 FF                 1859 	mov	r7,a
                    03EA   1860 	C$dynamixel_test.c$287$2$2 ==.
                           1861 ;	apps/dynamixel_test/dynamixel_test.c:287: if(now >= (uint16)5000){				// Goes from 0ms...5000ms
   1246 C3                 1862 	clr	c
   1247 EC                 1863 	mov	a,r4
   1248 94 88              1864 	subb	a,#0x88
   124A ED                 1865 	mov	a,r5
   124B 94 13              1866 	subb	a,#0x13
   124D 40 09              1867 	jc	00102$
                    03F3   1868 	C$dynamixel_test.c$288$3$3 ==.
                           1869 ;	apps/dynamixel_test/dynamixel_test.c:288: now = (uint16)10000 - now;			// then 5000ms...0ms
   124F 74 10              1870 	mov	a,#0x10
   1251 C3                 1871 	clr	c
   1252 9C                 1872 	subb	a,r4
   1253 FC                 1873 	mov	r4,a
   1254 74 27              1874 	mov	a,#0x27
   1256 9D                 1875 	subb	a,r5
   1257 FD                 1876 	mov	r5,a
   1258                    1877 00102$:
                    03FC   1878 	C$dynamixel_test.c$290$2$2 ==.
                           1879 ;	apps/dynamixel_test/dynamixel_test.c:290: speed = interpolate(now, 0, 5000, 100, 900); // speed is really the position.
   1258 8C 82              1880 	mov	dpl,r4
   125A 8D 83              1881 	mov	dph,r5
   125C 78 74              1882 	mov	r0,#_interpolate_PARM_2
   125E E4                 1883 	clr	a
   125F F2                 1884 	movx	@r0,a
   1260 08                 1885 	inc	r0
   1261 F2                 1886 	movx	@r0,a
   1262 78 76              1887 	mov	r0,#_interpolate_PARM_3
   1264 74 88              1888 	mov	a,#0x88
   1266 F2                 1889 	movx	@r0,a
   1267 08                 1890 	inc	r0
   1268 74 13              1891 	mov	a,#0x13
   126A F2                 1892 	movx	@r0,a
   126B 78 78              1893 	mov	r0,#_interpolate_PARM_4
   126D 74 64              1894 	mov	a,#0x64
   126F F2                 1895 	movx	@r0,a
   1270 08                 1896 	inc	r0
   1271 E4                 1897 	clr	a
   1272 F2                 1898 	movx	@r0,a
   1273 78 7A              1899 	mov	r0,#_interpolate_PARM_5
   1275 74 84              1900 	mov	a,#0x84
   1277 F2                 1901 	movx	@r0,a
   1278 08                 1902 	inc	r0
   1279 74 03              1903 	mov	a,#0x03
   127B F2                 1904 	movx	@r0,a
   127C 12 11 06           1905 	lcall	_interpolate
   127F AE 82              1906 	mov	r6,dpl
   1281 AF 83              1907 	mov	r7,dph
                    0427   1908 	C$dynamixel_test.c$292$2$2 ==.
                           1909 ;	apps/dynamixel_test/dynamixel_test.c:292: ax12SetGOAL_POSITION(32, speed);
   1283 C3                 1910 	clr	c
   1284 EE                 1911 	mov	a,r6
   1285 94 FF              1912 	subb	a,#0xFF
   1287 EF                 1913 	mov	a,r7
   1288 94 03              1914 	subb	a,#0x03
   128A E4                 1915 	clr	a
   128B 33                 1916 	rlc	a
   128C FD                 1917 	mov	r5,a
   128D 60 06              1918 	jz	00110$
   128F 8E 03              1919 	mov	ar3,r6
   1291 8F 04              1920 	mov	ar4,r7
   1293 80 04              1921 	sjmp	00111$
   1295                    1922 00110$:
   1295 7B FF              1923 	mov	r3,#0xFF
   1297 7C 03              1924 	mov	r4,#0x03
   1299                    1925 00111$:
   1299 EB                 1926 	mov	a,r3
   129A 4C                 1927 	orl	a,r4
   129B 60 0B              1928 	jz	00108$
   129D ED                 1929 	mov	a,r5
   129E 60 02              1930 	jz	00112$
   12A0 80 04              1931 	sjmp	00113$
   12A2                    1932 00112$:
   12A2 7E FF              1933 	mov	r6,#0xFF
   12A4 7F 03              1934 	mov	r7,#0x03
   12A6                    1935 00113$:
   12A6 80 04              1936 	sjmp	00109$
   12A8                    1937 00108$:
   12A8 7E 00              1938 	mov	r6,#0x00
   12AA 7F 00              1939 	mov	r7,#0x00
   12AC                    1940 00109$:
   12AC 78 2B              1941 	mov	r0,#_dynamixel_writeword_PARM_2
   12AE 74 20              1942 	mov	a,#0x20
   12B0 F2                 1943 	movx	@r0,a
   12B1 78 2C              1944 	mov	r0,#_dynamixel_writeword_PARM_3
   12B3 EE                 1945 	mov	a,r6
   12B4 F2                 1946 	movx	@r0,a
   12B5 08                 1947 	inc	r0
   12B6 EF                 1948 	mov	a,r7
   12B7 F2                 1949 	movx	@r0,a
   12B8 75 82 20           1950 	mov	dpl,#0x20
   12BB 12 0B CF           1951 	lcall	_dynamixel_writeword
                    0462   1952 	C$dynamixel_test.c$294$2$2 ==.
                           1953 ;	apps/dynamixel_test/dynamixel_test.c:294: delayMs(30);
   12BE 90 00 1E           1954 	mov	dptr,#0x001E
   12C1 12 1B F9           1955 	lcall	_delayMs
   12C4 02 12 11           1956 	ljmp	00104$
                    046B   1957 	C$dynamixel_test.c$296$1$1 ==.
                    046B   1958 	XG$main$0$0 ==.
   12C7 22                 1959 	ret
                           1960 	.area CSEG    (CODE)
                           1961 	.area CONST   (CODE)
                    0000   1962 G$param_serial_mode$0$0 == .
   2032                    1963 _param_serial_mode:
   2032 02 00 00 00        1964 	.byte #0x02,#0x00,#0x00,#0x00	;  2
                    0004   1965 G$param_baud_rate$0$0 == .
   2036                    1966 _param_baud_rate:
   2036 40 42 0F 00        1967 	.byte #0x40,#0x42,#0x0F,#0x00	;  1000000
                    0008   1968 G$param_nDTR_pin$0$0 == .
   203A                    1969 _param_nDTR_pin:
   203A 0A 00 00 00        1970 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   1971 G$param_nRTS_pin$0$0 == .
   203E                    1972 _param_nRTS_pin:
   203E 0B 00 00 00        1973 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   1974 G$param_nDSR_pin$0$0 == .
   2042                    1975 _param_nDSR_pin:
   2042 0C 00 00 00        1976 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    0014   1977 G$param_nCD_pin$0$0 == .
   2046                    1978 _param_nCD_pin:
   2046 0D 00 00 00        1979 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0018   1980 G$param_DTR_pin$0$0 == .
   204A                    1981 _param_DTR_pin:
   204A FF FF FF FF        1982 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    001C   1983 G$param_RTS_pin$0$0 == .
   204E                    1984 _param_RTS_pin:
   204E FF FF FF FF        1985 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0020   1986 G$param_DSR_pin$0$0 == .
   2052                    1987 _param_DSR_pin:
   2052 FF FF FF FF        1988 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0024   1989 G$param_CD_pin$0$0 == .
   2056                    1990 _param_CD_pin:
   2056 FF FF FF FF        1991 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0028   1992 G$param_arduino_DTR_pin$0$0 == .
   205A                    1993 _param_arduino_DTR_pin:
   205A 00 00 00 00        1994 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002C   1995 G$param_framing_error_ms$0$0 == .
   205E                    1996 _param_framing_error_ms:
   205E 00 00 00 00        1997 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                           1998 	.area XINIT   (CODE)
                           1999 	.area CABS    (ABS,CODE)
