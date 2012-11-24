                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:52 2012
                              5 ;--------------------------------------------------------
                              6 	.module gait_designer
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
                             25 	.globl _main
                             26 	.globl _usbToUartService
                             27 	.globl _errorService
                             28 	.globl _errorOccurred
                             29 	.globl _ioTxSignals
                             30 	.globl _ioRxSignals
                             31 	.globl _updateLeds
                             32 	.globl _dynamixel_writeword
                             33 	.globl _dynamixel_init
                             34 	.globl _interpolate
                             35 	.globl _malloc
                             36 	.globl _uart1RxReceiveByte
                             37 	.globl _uart1SetBaudRate
                             38 	.globl _uart1Init
                             39 	.globl _radioComTxService
                             40 	.globl _radioComInit
                             41 	.globl _radioLinkConnected
                             42 	.globl _usbComRxReceiveByte
                             43 	.globl _usbComRxAvailable
                             44 	.globl _usbComService
                             45 	.globl _usbComTxControlSignals
                             46 	.globl _usbComRxControlSignals
                             47 	.globl _usbShowStatusWithGreenLed
                             48 	.globl _usbInit
                             49 	.globl _isPinHigh
                             50 	.globl _setDigitalOutput
                             51 	.globl _delayMs
                             52 	.globl _getMs
                             53 	.globl _boardService
                             54 	.globl _systemInit
                             55 	.globl _g8repeatCount
                             56 	.globl _g8playbackDir
                             57 	.globl _g8speed
                             58 	.globl _lastErrorTime
                             59 	.globl _walkDIR
                             60 	.globl _walkSPD
                             61 	.globl _lookH
                             62 	.globl _lookV
                             63 	.globl _walkH
                             64 	.globl _walkV
                             65 	.globl _checksum_cmdr
                             66 	.globl _index_cmdr
                             67 	.globl _vals
                             68 	.globl _errorOccurredRecently
                             69 	.globl _framingErrorActive
                             70 	.globl _uartRxDisabled
                             71 	.globl _gaitDesignerInit
                             72 	.globl _gaitDesignerProcess
                             73 ;--------------------------------------------------------
                             74 ; special function registers
                             75 ;--------------------------------------------------------
                             76 	.area RSEG    (ABS,DATA)
   0000                      77 	.org 0x0000
                    0080     78 Fgait_designer$P0$0$0 == 0x0080
                    0080     79 _P0	=	0x0080
                    0081     80 Fgait_designer$SP$0$0 == 0x0081
                    0081     81 _SP	=	0x0081
                    0082     82 Fgait_designer$DPL0$0$0 == 0x0082
                    0082     83 _DPL0	=	0x0082
                    0083     84 Fgait_designer$DPH0$0$0 == 0x0083
                    0083     85 _DPH0	=	0x0083
                    0084     86 Fgait_designer$DPL1$0$0 == 0x0084
                    0084     87 _DPL1	=	0x0084
                    0085     88 Fgait_designer$DPH1$0$0 == 0x0085
                    0085     89 _DPH1	=	0x0085
                    0086     90 Fgait_designer$U0CSR$0$0 == 0x0086
                    0086     91 _U0CSR	=	0x0086
                    0087     92 Fgait_designer$PCON$0$0 == 0x0087
                    0087     93 _PCON	=	0x0087
                    0088     94 Fgait_designer$TCON$0$0 == 0x0088
                    0088     95 _TCON	=	0x0088
                    0089     96 Fgait_designer$P0IFG$0$0 == 0x0089
                    0089     97 _P0IFG	=	0x0089
                    008A     98 Fgait_designer$P1IFG$0$0 == 0x008a
                    008A     99 _P1IFG	=	0x008a
                    008B    100 Fgait_designer$P2IFG$0$0 == 0x008b
                    008B    101 _P2IFG	=	0x008b
                    008C    102 Fgait_designer$PICTL$0$0 == 0x008c
                    008C    103 _PICTL	=	0x008c
                    008D    104 Fgait_designer$P1IEN$0$0 == 0x008d
                    008D    105 _P1IEN	=	0x008d
                    008F    106 Fgait_designer$P0INP$0$0 == 0x008f
                    008F    107 _P0INP	=	0x008f
                    0090    108 Fgait_designer$P1$0$0 == 0x0090
                    0090    109 _P1	=	0x0090
                    0091    110 Fgait_designer$RFIM$0$0 == 0x0091
                    0091    111 _RFIM	=	0x0091
                    0092    112 Fgait_designer$DPS$0$0 == 0x0092
                    0092    113 _DPS	=	0x0092
                    0093    114 Fgait_designer$MPAGE$0$0 == 0x0093
                    0093    115 _MPAGE	=	0x0093
                    0095    116 Fgait_designer$ENDIAN$0$0 == 0x0095
                    0095    117 _ENDIAN	=	0x0095
                    0098    118 Fgait_designer$S0CON$0$0 == 0x0098
                    0098    119 _S0CON	=	0x0098
                    009A    120 Fgait_designer$IEN2$0$0 == 0x009a
                    009A    121 _IEN2	=	0x009a
                    009B    122 Fgait_designer$S1CON$0$0 == 0x009b
                    009B    123 _S1CON	=	0x009b
                    009C    124 Fgait_designer$T2CT$0$0 == 0x009c
                    009C    125 _T2CT	=	0x009c
                    009D    126 Fgait_designer$T2PR$0$0 == 0x009d
                    009D    127 _T2PR	=	0x009d
                    009E    128 Fgait_designer$T2CTL$0$0 == 0x009e
                    009E    129 _T2CTL	=	0x009e
                    00A0    130 Fgait_designer$P2$0$0 == 0x00a0
                    00A0    131 _P2	=	0x00a0
                    00A1    132 Fgait_designer$WORIRQ$0$0 == 0x00a1
                    00A1    133 _WORIRQ	=	0x00a1
                    00A2    134 Fgait_designer$WORCTRL$0$0 == 0x00a2
                    00A2    135 _WORCTRL	=	0x00a2
                    00A3    136 Fgait_designer$WOREVT0$0$0 == 0x00a3
                    00A3    137 _WOREVT0	=	0x00a3
                    00A4    138 Fgait_designer$WOREVT1$0$0 == 0x00a4
                    00A4    139 _WOREVT1	=	0x00a4
                    00A5    140 Fgait_designer$WORTIME0$0$0 == 0x00a5
                    00A5    141 _WORTIME0	=	0x00a5
                    00A6    142 Fgait_designer$WORTIME1$0$0 == 0x00a6
                    00A6    143 _WORTIME1	=	0x00a6
                    00A8    144 Fgait_designer$IEN0$0$0 == 0x00a8
                    00A8    145 _IEN0	=	0x00a8
                    00A9    146 Fgait_designer$IP0$0$0 == 0x00a9
                    00A9    147 _IP0	=	0x00a9
                    00AB    148 Fgait_designer$FWT$0$0 == 0x00ab
                    00AB    149 _FWT	=	0x00ab
                    00AC    150 Fgait_designer$FADDRL$0$0 == 0x00ac
                    00AC    151 _FADDRL	=	0x00ac
                    00AD    152 Fgait_designer$FADDRH$0$0 == 0x00ad
                    00AD    153 _FADDRH	=	0x00ad
                    00AE    154 Fgait_designer$FCTL$0$0 == 0x00ae
                    00AE    155 _FCTL	=	0x00ae
                    00AF    156 Fgait_designer$FWDATA$0$0 == 0x00af
                    00AF    157 _FWDATA	=	0x00af
                    00B1    158 Fgait_designer$ENCDI$0$0 == 0x00b1
                    00B1    159 _ENCDI	=	0x00b1
                    00B2    160 Fgait_designer$ENCDO$0$0 == 0x00b2
                    00B2    161 _ENCDO	=	0x00b2
                    00B3    162 Fgait_designer$ENCCS$0$0 == 0x00b3
                    00B3    163 _ENCCS	=	0x00b3
                    00B4    164 Fgait_designer$ADCCON1$0$0 == 0x00b4
                    00B4    165 _ADCCON1	=	0x00b4
                    00B5    166 Fgait_designer$ADCCON2$0$0 == 0x00b5
                    00B5    167 _ADCCON2	=	0x00b5
                    00B6    168 Fgait_designer$ADCCON3$0$0 == 0x00b6
                    00B6    169 _ADCCON3	=	0x00b6
                    00B8    170 Fgait_designer$IEN1$0$0 == 0x00b8
                    00B8    171 _IEN1	=	0x00b8
                    00B9    172 Fgait_designer$IP1$0$0 == 0x00b9
                    00B9    173 _IP1	=	0x00b9
                    00BA    174 Fgait_designer$ADCL$0$0 == 0x00ba
                    00BA    175 _ADCL	=	0x00ba
                    00BB    176 Fgait_designer$ADCH$0$0 == 0x00bb
                    00BB    177 _ADCH	=	0x00bb
                    00BC    178 Fgait_designer$RNDL$0$0 == 0x00bc
                    00BC    179 _RNDL	=	0x00bc
                    00BD    180 Fgait_designer$RNDH$0$0 == 0x00bd
                    00BD    181 _RNDH	=	0x00bd
                    00BE    182 Fgait_designer$SLEEP$0$0 == 0x00be
                    00BE    183 _SLEEP	=	0x00be
                    00C0    184 Fgait_designer$IRCON$0$0 == 0x00c0
                    00C0    185 _IRCON	=	0x00c0
                    00C1    186 Fgait_designer$U0DBUF$0$0 == 0x00c1
                    00C1    187 _U0DBUF	=	0x00c1
                    00C2    188 Fgait_designer$U0BAUD$0$0 == 0x00c2
                    00C2    189 _U0BAUD	=	0x00c2
                    00C4    190 Fgait_designer$U0UCR$0$0 == 0x00c4
                    00C4    191 _U0UCR	=	0x00c4
                    00C5    192 Fgait_designer$U0GCR$0$0 == 0x00c5
                    00C5    193 _U0GCR	=	0x00c5
                    00C6    194 Fgait_designer$CLKCON$0$0 == 0x00c6
                    00C6    195 _CLKCON	=	0x00c6
                    00C7    196 Fgait_designer$MEMCTR$0$0 == 0x00c7
                    00C7    197 _MEMCTR	=	0x00c7
                    00C9    198 Fgait_designer$WDCTL$0$0 == 0x00c9
                    00C9    199 _WDCTL	=	0x00c9
                    00CA    200 Fgait_designer$T3CNT$0$0 == 0x00ca
                    00CA    201 _T3CNT	=	0x00ca
                    00CB    202 Fgait_designer$T3CTL$0$0 == 0x00cb
                    00CB    203 _T3CTL	=	0x00cb
                    00CC    204 Fgait_designer$T3CCTL0$0$0 == 0x00cc
                    00CC    205 _T3CCTL0	=	0x00cc
                    00CD    206 Fgait_designer$T3CC0$0$0 == 0x00cd
                    00CD    207 _T3CC0	=	0x00cd
                    00CE    208 Fgait_designer$T3CCTL1$0$0 == 0x00ce
                    00CE    209 _T3CCTL1	=	0x00ce
                    00CF    210 Fgait_designer$T3CC1$0$0 == 0x00cf
                    00CF    211 _T3CC1	=	0x00cf
                    00D0    212 Fgait_designer$PSW$0$0 == 0x00d0
                    00D0    213 _PSW	=	0x00d0
                    00D1    214 Fgait_designer$DMAIRQ$0$0 == 0x00d1
                    00D1    215 _DMAIRQ	=	0x00d1
                    00D2    216 Fgait_designer$DMA1CFGL$0$0 == 0x00d2
                    00D2    217 _DMA1CFGL	=	0x00d2
                    00D3    218 Fgait_designer$DMA1CFGH$0$0 == 0x00d3
                    00D3    219 _DMA1CFGH	=	0x00d3
                    00D4    220 Fgait_designer$DMA0CFGL$0$0 == 0x00d4
                    00D4    221 _DMA0CFGL	=	0x00d4
                    00D5    222 Fgait_designer$DMA0CFGH$0$0 == 0x00d5
                    00D5    223 _DMA0CFGH	=	0x00d5
                    00D6    224 Fgait_designer$DMAARM$0$0 == 0x00d6
                    00D6    225 _DMAARM	=	0x00d6
                    00D7    226 Fgait_designer$DMAREQ$0$0 == 0x00d7
                    00D7    227 _DMAREQ	=	0x00d7
                    00D8    228 Fgait_designer$TIMIF$0$0 == 0x00d8
                    00D8    229 _TIMIF	=	0x00d8
                    00D9    230 Fgait_designer$RFD$0$0 == 0x00d9
                    00D9    231 _RFD	=	0x00d9
                    00DA    232 Fgait_designer$T1CC0L$0$0 == 0x00da
                    00DA    233 _T1CC0L	=	0x00da
                    00DB    234 Fgait_designer$T1CC0H$0$0 == 0x00db
                    00DB    235 _T1CC0H	=	0x00db
                    00DC    236 Fgait_designer$T1CC1L$0$0 == 0x00dc
                    00DC    237 _T1CC1L	=	0x00dc
                    00DD    238 Fgait_designer$T1CC1H$0$0 == 0x00dd
                    00DD    239 _T1CC1H	=	0x00dd
                    00DE    240 Fgait_designer$T1CC2L$0$0 == 0x00de
                    00DE    241 _T1CC2L	=	0x00de
                    00DF    242 Fgait_designer$T1CC2H$0$0 == 0x00df
                    00DF    243 _T1CC2H	=	0x00df
                    00E0    244 Fgait_designer$ACC$0$0 == 0x00e0
                    00E0    245 _ACC	=	0x00e0
                    00E1    246 Fgait_designer$RFST$0$0 == 0x00e1
                    00E1    247 _RFST	=	0x00e1
                    00E2    248 Fgait_designer$T1CNTL$0$0 == 0x00e2
                    00E2    249 _T1CNTL	=	0x00e2
                    00E3    250 Fgait_designer$T1CNTH$0$0 == 0x00e3
                    00E3    251 _T1CNTH	=	0x00e3
                    00E4    252 Fgait_designer$T1CTL$0$0 == 0x00e4
                    00E4    253 _T1CTL	=	0x00e4
                    00E5    254 Fgait_designer$T1CCTL0$0$0 == 0x00e5
                    00E5    255 _T1CCTL0	=	0x00e5
                    00E6    256 Fgait_designer$T1CCTL1$0$0 == 0x00e6
                    00E6    257 _T1CCTL1	=	0x00e6
                    00E7    258 Fgait_designer$T1CCTL2$0$0 == 0x00e7
                    00E7    259 _T1CCTL2	=	0x00e7
                    00E8    260 Fgait_designer$IRCON2$0$0 == 0x00e8
                    00E8    261 _IRCON2	=	0x00e8
                    00E9    262 Fgait_designer$RFIF$0$0 == 0x00e9
                    00E9    263 _RFIF	=	0x00e9
                    00EA    264 Fgait_designer$T4CNT$0$0 == 0x00ea
                    00EA    265 _T4CNT	=	0x00ea
                    00EB    266 Fgait_designer$T4CTL$0$0 == 0x00eb
                    00EB    267 _T4CTL	=	0x00eb
                    00EC    268 Fgait_designer$T4CCTL0$0$0 == 0x00ec
                    00EC    269 _T4CCTL0	=	0x00ec
                    00ED    270 Fgait_designer$T4CC0$0$0 == 0x00ed
                    00ED    271 _T4CC0	=	0x00ed
                    00EE    272 Fgait_designer$T4CCTL1$0$0 == 0x00ee
                    00EE    273 _T4CCTL1	=	0x00ee
                    00EF    274 Fgait_designer$T4CC1$0$0 == 0x00ef
                    00EF    275 _T4CC1	=	0x00ef
                    00F0    276 Fgait_designer$B$0$0 == 0x00f0
                    00F0    277 _B	=	0x00f0
                    00F1    278 Fgait_designer$PERCFG$0$0 == 0x00f1
                    00F1    279 _PERCFG	=	0x00f1
                    00F2    280 Fgait_designer$ADCCFG$0$0 == 0x00f2
                    00F2    281 _ADCCFG	=	0x00f2
                    00F3    282 Fgait_designer$P0SEL$0$0 == 0x00f3
                    00F3    283 _P0SEL	=	0x00f3
                    00F4    284 Fgait_designer$P1SEL$0$0 == 0x00f4
                    00F4    285 _P1SEL	=	0x00f4
                    00F5    286 Fgait_designer$P2SEL$0$0 == 0x00f5
                    00F5    287 _P2SEL	=	0x00f5
                    00F6    288 Fgait_designer$P1INP$0$0 == 0x00f6
                    00F6    289 _P1INP	=	0x00f6
                    00F7    290 Fgait_designer$P2INP$0$0 == 0x00f7
                    00F7    291 _P2INP	=	0x00f7
                    00F8    292 Fgait_designer$U1CSR$0$0 == 0x00f8
                    00F8    293 _U1CSR	=	0x00f8
                    00F9    294 Fgait_designer$U1DBUF$0$0 == 0x00f9
                    00F9    295 _U1DBUF	=	0x00f9
                    00FA    296 Fgait_designer$U1BAUD$0$0 == 0x00fa
                    00FA    297 _U1BAUD	=	0x00fa
                    00FB    298 Fgait_designer$U1UCR$0$0 == 0x00fb
                    00FB    299 _U1UCR	=	0x00fb
                    00FC    300 Fgait_designer$U1GCR$0$0 == 0x00fc
                    00FC    301 _U1GCR	=	0x00fc
                    00FD    302 Fgait_designer$P0DIR$0$0 == 0x00fd
                    00FD    303 _P0DIR	=	0x00fd
                    00FE    304 Fgait_designer$P1DIR$0$0 == 0x00fe
                    00FE    305 _P1DIR	=	0x00fe
                    00FF    306 Fgait_designer$P2DIR$0$0 == 0x00ff
                    00FF    307 _P2DIR	=	0x00ff
                    FFFFD5D4    308 Fgait_designer$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    309 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    310 Fgait_designer$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    311 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    312 Fgait_designer$FADDR$0$0 == 0xffffadac
                    FFFFADAC    313 _FADDR	=	0xffffadac
                    FFFFBBBA    314 Fgait_designer$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    315 _ADC	=	0xffffbbba
                    FFFFDBDA    316 Fgait_designer$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    317 _T1CC0	=	0xffffdbda
                    FFFFDDDC    318 Fgait_designer$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    319 _T1CC1	=	0xffffdddc
                    FFFFDFDE    320 Fgait_designer$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    321 _T1CC2	=	0xffffdfde
                            322 ;--------------------------------------------------------
                            323 ; special function bits
                            324 ;--------------------------------------------------------
                            325 	.area RSEG    (ABS,DATA)
   0000                     326 	.org 0x0000
                    0080    327 Fgait_designer$P0_0$0$0 == 0x0080
                    0080    328 _P0_0	=	0x0080
                    0081    329 Fgait_designer$P0_1$0$0 == 0x0081
                    0081    330 _P0_1	=	0x0081
                    0082    331 Fgait_designer$P0_2$0$0 == 0x0082
                    0082    332 _P0_2	=	0x0082
                    0083    333 Fgait_designer$P0_3$0$0 == 0x0083
                    0083    334 _P0_3	=	0x0083
                    0084    335 Fgait_designer$P0_4$0$0 == 0x0084
                    0084    336 _P0_4	=	0x0084
                    0085    337 Fgait_designer$P0_5$0$0 == 0x0085
                    0085    338 _P0_5	=	0x0085
                    0086    339 Fgait_designer$P0_6$0$0 == 0x0086
                    0086    340 _P0_6	=	0x0086
                    0087    341 Fgait_designer$P0_7$0$0 == 0x0087
                    0087    342 _P0_7	=	0x0087
                    0088    343 Fgait_designer$_TCON_0$0$0 == 0x0088
                    0088    344 __TCON_0	=	0x0088
                    0089    345 Fgait_designer$RFTXRXIF$0$0 == 0x0089
                    0089    346 _RFTXRXIF	=	0x0089
                    008A    347 Fgait_designer$_TCON_2$0$0 == 0x008a
                    008A    348 __TCON_2	=	0x008a
                    008B    349 Fgait_designer$URX0IF$0$0 == 0x008b
                    008B    350 _URX0IF	=	0x008b
                    008C    351 Fgait_designer$_TCON_4$0$0 == 0x008c
                    008C    352 __TCON_4	=	0x008c
                    008D    353 Fgait_designer$ADCIF$0$0 == 0x008d
                    008D    354 _ADCIF	=	0x008d
                    008E    355 Fgait_designer$_TCON_6$0$0 == 0x008e
                    008E    356 __TCON_6	=	0x008e
                    008F    357 Fgait_designer$URX1IF$0$0 == 0x008f
                    008F    358 _URX1IF	=	0x008f
                    0090    359 Fgait_designer$P1_0$0$0 == 0x0090
                    0090    360 _P1_0	=	0x0090
                    0091    361 Fgait_designer$P1_1$0$0 == 0x0091
                    0091    362 _P1_1	=	0x0091
                    0092    363 Fgait_designer$P1_2$0$0 == 0x0092
                    0092    364 _P1_2	=	0x0092
                    0093    365 Fgait_designer$P1_3$0$0 == 0x0093
                    0093    366 _P1_3	=	0x0093
                    0094    367 Fgait_designer$P1_4$0$0 == 0x0094
                    0094    368 _P1_4	=	0x0094
                    0095    369 Fgait_designer$P1_5$0$0 == 0x0095
                    0095    370 _P1_5	=	0x0095
                    0096    371 Fgait_designer$P1_6$0$0 == 0x0096
                    0096    372 _P1_6	=	0x0096
                    0097    373 Fgait_designer$P1_7$0$0 == 0x0097
                    0097    374 _P1_7	=	0x0097
                    0098    375 Fgait_designer$ENCIF_0$0$0 == 0x0098
                    0098    376 _ENCIF_0	=	0x0098
                    0099    377 Fgait_designer$ENCIF_1$0$0 == 0x0099
                    0099    378 _ENCIF_1	=	0x0099
                    009A    379 Fgait_designer$_SOCON2$0$0 == 0x009a
                    009A    380 __SOCON2	=	0x009a
                    009B    381 Fgait_designer$_SOCON3$0$0 == 0x009b
                    009B    382 __SOCON3	=	0x009b
                    009C    383 Fgait_designer$_SOCON4$0$0 == 0x009c
                    009C    384 __SOCON4	=	0x009c
                    009D    385 Fgait_designer$_SOCON5$0$0 == 0x009d
                    009D    386 __SOCON5	=	0x009d
                    009E    387 Fgait_designer$_SOCON6$0$0 == 0x009e
                    009E    388 __SOCON6	=	0x009e
                    009F    389 Fgait_designer$_SOCON7$0$0 == 0x009f
                    009F    390 __SOCON7	=	0x009f
                    00A0    391 Fgait_designer$P2_0$0$0 == 0x00a0
                    00A0    392 _P2_0	=	0x00a0
                    00A1    393 Fgait_designer$P2_1$0$0 == 0x00a1
                    00A1    394 _P2_1	=	0x00a1
                    00A2    395 Fgait_designer$P2_2$0$0 == 0x00a2
                    00A2    396 _P2_2	=	0x00a2
                    00A3    397 Fgait_designer$P2_3$0$0 == 0x00a3
                    00A3    398 _P2_3	=	0x00a3
                    00A4    399 Fgait_designer$P2_4$0$0 == 0x00a4
                    00A4    400 _P2_4	=	0x00a4
                    00A5    401 Fgait_designer$P2_5$0$0 == 0x00a5
                    00A5    402 _P2_5	=	0x00a5
                    00A6    403 Fgait_designer$P2_6$0$0 == 0x00a6
                    00A6    404 _P2_6	=	0x00a6
                    00A7    405 Fgait_designer$P2_7$0$0 == 0x00a7
                    00A7    406 _P2_7	=	0x00a7
                    00A8    407 Fgait_designer$RFTXRXIE$0$0 == 0x00a8
                    00A8    408 _RFTXRXIE	=	0x00a8
                    00A9    409 Fgait_designer$ADCIE$0$0 == 0x00a9
                    00A9    410 _ADCIE	=	0x00a9
                    00AA    411 Fgait_designer$URX0IE$0$0 == 0x00aa
                    00AA    412 _URX0IE	=	0x00aa
                    00AB    413 Fgait_designer$URX1IE$0$0 == 0x00ab
                    00AB    414 _URX1IE	=	0x00ab
                    00AC    415 Fgait_designer$ENCIE$0$0 == 0x00ac
                    00AC    416 _ENCIE	=	0x00ac
                    00AD    417 Fgait_designer$STIE$0$0 == 0x00ad
                    00AD    418 _STIE	=	0x00ad
                    00AE    419 Fgait_designer$_IEN06$0$0 == 0x00ae
                    00AE    420 __IEN06	=	0x00ae
                    00AF    421 Fgait_designer$EA$0$0 == 0x00af
                    00AF    422 _EA	=	0x00af
                    00B8    423 Fgait_designer$DMAIE$0$0 == 0x00b8
                    00B8    424 _DMAIE	=	0x00b8
                    00B9    425 Fgait_designer$T1IE$0$0 == 0x00b9
                    00B9    426 _T1IE	=	0x00b9
                    00BA    427 Fgait_designer$T2IE$0$0 == 0x00ba
                    00BA    428 _T2IE	=	0x00ba
                    00BB    429 Fgait_designer$T3IE$0$0 == 0x00bb
                    00BB    430 _T3IE	=	0x00bb
                    00BC    431 Fgait_designer$T4IE$0$0 == 0x00bc
                    00BC    432 _T4IE	=	0x00bc
                    00BD    433 Fgait_designer$P0IE$0$0 == 0x00bd
                    00BD    434 _P0IE	=	0x00bd
                    00BE    435 Fgait_designer$_IEN16$0$0 == 0x00be
                    00BE    436 __IEN16	=	0x00be
                    00BF    437 Fgait_designer$_IEN17$0$0 == 0x00bf
                    00BF    438 __IEN17	=	0x00bf
                    00C0    439 Fgait_designer$DMAIF$0$0 == 0x00c0
                    00C0    440 _DMAIF	=	0x00c0
                    00C1    441 Fgait_designer$T1IF$0$0 == 0x00c1
                    00C1    442 _T1IF	=	0x00c1
                    00C2    443 Fgait_designer$T2IF$0$0 == 0x00c2
                    00C2    444 _T2IF	=	0x00c2
                    00C3    445 Fgait_designer$T3IF$0$0 == 0x00c3
                    00C3    446 _T3IF	=	0x00c3
                    00C4    447 Fgait_designer$T4IF$0$0 == 0x00c4
                    00C4    448 _T4IF	=	0x00c4
                    00C5    449 Fgait_designer$P0IF$0$0 == 0x00c5
                    00C5    450 _P0IF	=	0x00c5
                    00C6    451 Fgait_designer$_IRCON6$0$0 == 0x00c6
                    00C6    452 __IRCON6	=	0x00c6
                    00C7    453 Fgait_designer$STIF$0$0 == 0x00c7
                    00C7    454 _STIF	=	0x00c7
                    00D0    455 Fgait_designer$P$0$0 == 0x00d0
                    00D0    456 _P	=	0x00d0
                    00D1    457 Fgait_designer$F1$0$0 == 0x00d1
                    00D1    458 _F1	=	0x00d1
                    00D2    459 Fgait_designer$OV$0$0 == 0x00d2
                    00D2    460 _OV	=	0x00d2
                    00D3    461 Fgait_designer$RS0$0$0 == 0x00d3
                    00D3    462 _RS0	=	0x00d3
                    00D4    463 Fgait_designer$RS1$0$0 == 0x00d4
                    00D4    464 _RS1	=	0x00d4
                    00D5    465 Fgait_designer$F0$0$0 == 0x00d5
                    00D5    466 _F0	=	0x00d5
                    00D6    467 Fgait_designer$AC$0$0 == 0x00d6
                    00D6    468 _AC	=	0x00d6
                    00D7    469 Fgait_designer$CY$0$0 == 0x00d7
                    00D7    470 _CY	=	0x00d7
                    00D8    471 Fgait_designer$T3OVFIF$0$0 == 0x00d8
                    00D8    472 _T3OVFIF	=	0x00d8
                    00D9    473 Fgait_designer$T3CH0IF$0$0 == 0x00d9
                    00D9    474 _T3CH0IF	=	0x00d9
                    00DA    475 Fgait_designer$T3CH1IF$0$0 == 0x00da
                    00DA    476 _T3CH1IF	=	0x00da
                    00DB    477 Fgait_designer$T4OVFIF$0$0 == 0x00db
                    00DB    478 _T4OVFIF	=	0x00db
                    00DC    479 Fgait_designer$T4CH0IF$0$0 == 0x00dc
                    00DC    480 _T4CH0IF	=	0x00dc
                    00DD    481 Fgait_designer$T4CH1IF$0$0 == 0x00dd
                    00DD    482 _T4CH1IF	=	0x00dd
                    00DE    483 Fgait_designer$OVFIM$0$0 == 0x00de
                    00DE    484 _OVFIM	=	0x00de
                    00DF    485 Fgait_designer$_TIMIF7$0$0 == 0x00df
                    00DF    486 __TIMIF7	=	0x00df
                    00E0    487 Fgait_designer$ACC_0$0$0 == 0x00e0
                    00E0    488 _ACC_0	=	0x00e0
                    00E1    489 Fgait_designer$ACC_1$0$0 == 0x00e1
                    00E1    490 _ACC_1	=	0x00e1
                    00E2    491 Fgait_designer$ACC_2$0$0 == 0x00e2
                    00E2    492 _ACC_2	=	0x00e2
                    00E3    493 Fgait_designer$ACC_3$0$0 == 0x00e3
                    00E3    494 _ACC_3	=	0x00e3
                    00E4    495 Fgait_designer$ACC_4$0$0 == 0x00e4
                    00E4    496 _ACC_4	=	0x00e4
                    00E5    497 Fgait_designer$ACC_5$0$0 == 0x00e5
                    00E5    498 _ACC_5	=	0x00e5
                    00E6    499 Fgait_designer$ACC_6$0$0 == 0x00e6
                    00E6    500 _ACC_6	=	0x00e6
                    00E7    501 Fgait_designer$ACC_7$0$0 == 0x00e7
                    00E7    502 _ACC_7	=	0x00e7
                    00E8    503 Fgait_designer$P2IF$0$0 == 0x00e8
                    00E8    504 _P2IF	=	0x00e8
                    00E9    505 Fgait_designer$UTX0IF$0$0 == 0x00e9
                    00E9    506 _UTX0IF	=	0x00e9
                    00EA    507 Fgait_designer$UTX1IF$0$0 == 0x00ea
                    00EA    508 _UTX1IF	=	0x00ea
                    00EB    509 Fgait_designer$P1IF$0$0 == 0x00eb
                    00EB    510 _P1IF	=	0x00eb
                    00EC    511 Fgait_designer$WDTIF$0$0 == 0x00ec
                    00EC    512 _WDTIF	=	0x00ec
                    00ED    513 Fgait_designer$_IRCON25$0$0 == 0x00ed
                    00ED    514 __IRCON25	=	0x00ed
                    00EE    515 Fgait_designer$_IRCON26$0$0 == 0x00ee
                    00EE    516 __IRCON26	=	0x00ee
                    00EF    517 Fgait_designer$_IRCON27$0$0 == 0x00ef
                    00EF    518 __IRCON27	=	0x00ef
                    00F0    519 Fgait_designer$B_0$0$0 == 0x00f0
                    00F0    520 _B_0	=	0x00f0
                    00F1    521 Fgait_designer$B_1$0$0 == 0x00f1
                    00F1    522 _B_1	=	0x00f1
                    00F2    523 Fgait_designer$B_2$0$0 == 0x00f2
                    00F2    524 _B_2	=	0x00f2
                    00F3    525 Fgait_designer$B_3$0$0 == 0x00f3
                    00F3    526 _B_3	=	0x00f3
                    00F4    527 Fgait_designer$B_4$0$0 == 0x00f4
                    00F4    528 _B_4	=	0x00f4
                    00F5    529 Fgait_designer$B_5$0$0 == 0x00f5
                    00F5    530 _B_5	=	0x00f5
                    00F6    531 Fgait_designer$B_6$0$0 == 0x00f6
                    00F6    532 _B_6	=	0x00f6
                    00F7    533 Fgait_designer$B_7$0$0 == 0x00f7
                    00F7    534 _B_7	=	0x00f7
                    00F8    535 Fgait_designer$U1ACTIVE$0$0 == 0x00f8
                    00F8    536 _U1ACTIVE	=	0x00f8
                    00F9    537 Fgait_designer$U1TX_BYTE$0$0 == 0x00f9
                    00F9    538 _U1TX_BYTE	=	0x00f9
                    00FA    539 Fgait_designer$U1RX_BYTE$0$0 == 0x00fa
                    00FA    540 _U1RX_BYTE	=	0x00fa
                    00FB    541 Fgait_designer$U1ERR$0$0 == 0x00fb
                    00FB    542 _U1ERR	=	0x00fb
                    00FC    543 Fgait_designer$U1FE$0$0 == 0x00fc
                    00FC    544 _U1FE	=	0x00fc
                    00FD    545 Fgait_designer$U1SLAVE$0$0 == 0x00fd
                    00FD    546 _U1SLAVE	=	0x00fd
                    00FE    547 Fgait_designer$U1RE$0$0 == 0x00fe
                    00FE    548 _U1RE	=	0x00fe
                    00FF    549 Fgait_designer$U1MODE$0$0 == 0x00ff
                    00FF    550 _U1MODE	=	0x00ff
                            551 ;--------------------------------------------------------
                            552 ; overlayable register banks
                            553 ;--------------------------------------------------------
                            554 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     555 	.ds 8
                            556 ;--------------------------------------------------------
                            557 ; overlayable bit register bank
                            558 ;--------------------------------------------------------
                            559 	.area BIT_BANK	(REL,OVR,DATA)
   0024                     560 bits:
   0024                     561 	.ds 1
                    8000    562 	b0 = bits[0]
                    8100    563 	b1 = bits[1]
                    8200    564 	b2 = bits[2]
                    8300    565 	b3 = bits[3]
                    8400    566 	b4 = bits[4]
                    8500    567 	b5 = bits[5]
                    8600    568 	b6 = bits[6]
                    8700    569 	b7 = bits[7]
                            570 ;--------------------------------------------------------
                            571 ; internal ram data
                            572 ;--------------------------------------------------------
                            573 	.area DSEG    (DATA)
                    0000    574 Lgait_designer.updateLeds$count$3$7==.
   000B                     575 _updateLeds_count_3_7:
   000B                     576 	.ds 1
                    0001    577 Lgait_designer.errorService$sloc0$1$0==.
   000C                     578 _errorService_sloc0_1_0:
   000C                     579 	.ds 4
                    0005    580 Lgait_designer.gaitDesignerInit$sloc0$1$0==.
   0010                     581 _gaitDesignerInit_sloc0_1_0:
   0010                     582 	.ds 3
                    0008    583 Lgait_designer.gaitDesignerInit$sloc1$1$0==.
   0013                     584 _gaitDesignerInit_sloc1_1_0:
   0013                     585 	.ds 3
                    000B    586 Lgait_designer.gaitDesignerProcess$sloc0$1$0==.
   0016                     587 _gaitDesignerProcess_sloc0_1_0:
   0016                     588 	.ds 1
                    000C    589 Lgait_designer.gaitDesignerProcess$sloc1$1$0==.
   0017                     590 _gaitDesignerProcess_sloc1_1_0:
   0017                     591 	.ds 3
                            592 ;--------------------------------------------------------
                            593 ; overlayable items in internal ram 
                            594 ;--------------------------------------------------------
                            595 	.area OSEG    (OVR,DATA)
                            596 ;--------------------------------------------------------
                            597 ; Stack segment in internal ram 
                            598 ;--------------------------------------------------------
                            599 	.area	SSEG	(DATA)
   0057                     600 __start__stack:
   0057                     601 	.ds	1
                            602 
                            603 ;--------------------------------------------------------
                            604 ; indirectly addressable internal ram data
                            605 ;--------------------------------------------------------
                            606 	.area ISEG    (DATA)
                            607 ;--------------------------------------------------------
                            608 ; absolute internal ram data
                            609 ;--------------------------------------------------------
                            610 	.area IABS    (ABS,DATA)
                            611 	.area IABS    (ABS,DATA)
                            612 ;--------------------------------------------------------
                            613 ; bit data
                            614 ;--------------------------------------------------------
                            615 	.area BSEG    (BIT)
                    0000    616 G$uartRxDisabled$0$0==.
   0000                     617 _uartRxDisabled::
   0000                     618 	.ds 1
                    0001    619 G$framingErrorActive$0$0==.
   0001                     620 _framingErrorActive::
   0001                     621 	.ds 1
                    0002    622 G$errorOccurredRecently$0$0==.
   0002                     623 _errorOccurredRecently::
   0002                     624 	.ds 1
                    0003    625 Lgait_designer.updateLeds$dimYellowLed$1$1==.
   0003                     626 _updateLeds_dimYellowLed_1_1:
   0003                     627 	.ds 1
                    0004    628 Lgait_designer.ioTxSignals$sloc0$1$0==.
   0004                     629 _ioTxSignals_sloc0_1_0:
   0004                     630 	.ds 1
                            631 ;--------------------------------------------------------
                            632 ; paged external ram data
                            633 ;--------------------------------------------------------
                            634 	.area PSEG    (PAG,XDATA)
                    0000    635 G$vals$0$0==.
   F024                     636 _vals::
   F024                     637 	.ds 7
                    0007    638 G$index_cmdr$0$0==.
   F02B                     639 _index_cmdr::
   F02B                     640 	.ds 2
                    0009    641 G$checksum_cmdr$0$0==.
   F02D                     642 _checksum_cmdr::
   F02D                     643 	.ds 2
                    000B    644 G$walkV$0$0==.
   F02F                     645 _walkV::
   F02F                     646 	.ds 2
                    000D    647 G$walkH$0$0==.
   F031                     648 _walkH::
   F031                     649 	.ds 2
                    000F    650 G$lookV$0$0==.
   F033                     651 _lookV::
   F033                     652 	.ds 2
                    0011    653 G$lookH$0$0==.
   F035                     654 _lookH::
   F035                     655 	.ds 2
                    0013    656 G$walkSPD$0$0==.
   F037                     657 _walkSPD::
   F037                     658 	.ds 2
                    0015    659 G$walkDIR$0$0==.
   F039                     660 _walkDIR::
   F039                     661 	.ds 4
                    0019    662 G$lastErrorTime$0$0==.
   F03D                     663 _lastErrorTime::
   F03D                     664 	.ds 1
                    001A    665 G$g8speed$0$0==.
   F03E                     666 _g8speed::
   F03E                     667 	.ds 2
                    001C    668 G$g8playbackDir$0$0==.
   F040                     669 _g8playbackDir::
   F040                     670 	.ds 1
                    001D    671 G$g8repeatCount$0$0==.
   F041                     672 _g8repeatCount::
   F041                     673 	.ds 1
                    001E    674 Lgait_designer.updateLeds$lastRadioActivityTime$1$1==.
   F042                     675 _updateLeds_lastRadioActivityTime_1_1:
   F042                     676 	.ds 2
                    0020    677 Lgait_designer.ioTxSignals$signals$1$1==.
   F044                     678 _ioTxSignals_signals_1_1:
   F044                     679 	.ds 1
                    0021    680 Lgait_designer.ioTxSignals$nTrstPulseStartTime$1$1==.
   F045                     681 _ioTxSignals_nTrstPulseStartTime_1_1:
   F045                     682 	.ds 1
                    0022    683 Lgait_designer.ioTxSignals$lastSignals$1$1==.
   F046                     684 _ioTxSignals_lastSignals_1_1:
   F046                     685 	.ds 1
                    0023    686 Lgait_designer.errorService$lastRxLowTime$1$1==.
   F047                     687 _errorService_lastRxLowTime_1_1:
   F047                     688 	.ds 1
                    0024    689 Lgait_designer.hexDigit$inx$1$1==.
   F048                     690 _hexDigit_PARM_2:
   F048                     691 	.ds 1
                    0025    692 Lgait_designer.setSpeed$servo$1$1==.
   F049                     693 _setSpeed_PARM_2:
   F049                     694 	.ds 1
                    0026    695 Lgait_designer.setSpeed$percent$1$1==.
   F04A                     696 _setSpeed_PARM_3:
   F04A                     697 	.ds 1
                    0027    698 Lgait_designer.gaitDesignerProcess$gait$1$1==.
   F04B                     699 _gaitDesignerProcess_gait_1_1:
   F04B                     700 	.ds 3
                    002A    701 Lgait_designer.gaitDesignerProcess$inx$1$1==.
   F04E                     702 _gaitDesignerProcess_inx_1_1:
   F04E                     703 	.ds 1
                    002B    704 Lgait_designer.gaitDesignerProcess$buffer$1$1==.
   F04F                     705 _gaitDesignerProcess_buffer_1_1:
   F04F                     706 	.ds 3
                    002E    707 Lgait_designer.gaitDesignerProcess$b$1$1==.
   F052                     708 _gaitDesignerProcess_b_1_1:
   F052                     709 	.ds 2
                    0030    710 Lgait_designer.gaitDesignerProcess$percent$5$6==.
   F054                     711 _gaitDesignerProcess_percent_5_6:
   F054                     712 	.ds 1
                            713 ;--------------------------------------------------------
                            714 ; external ram data
                            715 ;--------------------------------------------------------
                            716 	.area XSEG    (XDATA)
                    DF00    717 Fgait_designer$SYNC1$0$0 == 0xdf00
                    DF00    718 _SYNC1	=	0xdf00
                    DF01    719 Fgait_designer$SYNC0$0$0 == 0xdf01
                    DF01    720 _SYNC0	=	0xdf01
                    DF02    721 Fgait_designer$PKTLEN$0$0 == 0xdf02
                    DF02    722 _PKTLEN	=	0xdf02
                    DF03    723 Fgait_designer$PKTCTRL1$0$0 == 0xdf03
                    DF03    724 _PKTCTRL1	=	0xdf03
                    DF04    725 Fgait_designer$PKTCTRL0$0$0 == 0xdf04
                    DF04    726 _PKTCTRL0	=	0xdf04
                    DF05    727 Fgait_designer$ADDR$0$0 == 0xdf05
                    DF05    728 _ADDR	=	0xdf05
                    DF06    729 Fgait_designer$CHANNR$0$0 == 0xdf06
                    DF06    730 _CHANNR	=	0xdf06
                    DF07    731 Fgait_designer$FSCTRL1$0$0 == 0xdf07
                    DF07    732 _FSCTRL1	=	0xdf07
                    DF08    733 Fgait_designer$FSCTRL0$0$0 == 0xdf08
                    DF08    734 _FSCTRL0	=	0xdf08
                    DF09    735 Fgait_designer$FREQ2$0$0 == 0xdf09
                    DF09    736 _FREQ2	=	0xdf09
                    DF0A    737 Fgait_designer$FREQ1$0$0 == 0xdf0a
                    DF0A    738 _FREQ1	=	0xdf0a
                    DF0B    739 Fgait_designer$FREQ0$0$0 == 0xdf0b
                    DF0B    740 _FREQ0	=	0xdf0b
                    DF0C    741 Fgait_designer$MDMCFG4$0$0 == 0xdf0c
                    DF0C    742 _MDMCFG4	=	0xdf0c
                    DF0D    743 Fgait_designer$MDMCFG3$0$0 == 0xdf0d
                    DF0D    744 _MDMCFG3	=	0xdf0d
                    DF0E    745 Fgait_designer$MDMCFG2$0$0 == 0xdf0e
                    DF0E    746 _MDMCFG2	=	0xdf0e
                    DF0F    747 Fgait_designer$MDMCFG1$0$0 == 0xdf0f
                    DF0F    748 _MDMCFG1	=	0xdf0f
                    DF10    749 Fgait_designer$MDMCFG0$0$0 == 0xdf10
                    DF10    750 _MDMCFG0	=	0xdf10
                    DF11    751 Fgait_designer$DEVIATN$0$0 == 0xdf11
                    DF11    752 _DEVIATN	=	0xdf11
                    DF12    753 Fgait_designer$MCSM2$0$0 == 0xdf12
                    DF12    754 _MCSM2	=	0xdf12
                    DF13    755 Fgait_designer$MCSM1$0$0 == 0xdf13
                    DF13    756 _MCSM1	=	0xdf13
                    DF14    757 Fgait_designer$MCSM0$0$0 == 0xdf14
                    DF14    758 _MCSM0	=	0xdf14
                    DF15    759 Fgait_designer$FOCCFG$0$0 == 0xdf15
                    DF15    760 _FOCCFG	=	0xdf15
                    DF16    761 Fgait_designer$BSCFG$0$0 == 0xdf16
                    DF16    762 _BSCFG	=	0xdf16
                    DF17    763 Fgait_designer$AGCCTRL2$0$0 == 0xdf17
                    DF17    764 _AGCCTRL2	=	0xdf17
                    DF18    765 Fgait_designer$AGCCTRL1$0$0 == 0xdf18
                    DF18    766 _AGCCTRL1	=	0xdf18
                    DF19    767 Fgait_designer$AGCCTRL0$0$0 == 0xdf19
                    DF19    768 _AGCCTRL0	=	0xdf19
                    DF1A    769 Fgait_designer$FREND1$0$0 == 0xdf1a
                    DF1A    770 _FREND1	=	0xdf1a
                    DF1B    771 Fgait_designer$FREND0$0$0 == 0xdf1b
                    DF1B    772 _FREND0	=	0xdf1b
                    DF1C    773 Fgait_designer$FSCAL3$0$0 == 0xdf1c
                    DF1C    774 _FSCAL3	=	0xdf1c
                    DF1D    775 Fgait_designer$FSCAL2$0$0 == 0xdf1d
                    DF1D    776 _FSCAL2	=	0xdf1d
                    DF1E    777 Fgait_designer$FSCAL1$0$0 == 0xdf1e
                    DF1E    778 _FSCAL1	=	0xdf1e
                    DF1F    779 Fgait_designer$FSCAL0$0$0 == 0xdf1f
                    DF1F    780 _FSCAL0	=	0xdf1f
                    DF23    781 Fgait_designer$TEST2$0$0 == 0xdf23
                    DF23    782 _TEST2	=	0xdf23
                    DF24    783 Fgait_designer$TEST1$0$0 == 0xdf24
                    DF24    784 _TEST1	=	0xdf24
                    DF25    785 Fgait_designer$TEST0$0$0 == 0xdf25
                    DF25    786 _TEST0	=	0xdf25
                    DF2E    787 Fgait_designer$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    788 _PA_TABLE0	=	0xdf2e
                    DF2F    789 Fgait_designer$IOCFG2$0$0 == 0xdf2f
                    DF2F    790 _IOCFG2	=	0xdf2f
                    DF30    791 Fgait_designer$IOCFG1$0$0 == 0xdf30
                    DF30    792 _IOCFG1	=	0xdf30
                    DF31    793 Fgait_designer$IOCFG0$0$0 == 0xdf31
                    DF31    794 _IOCFG0	=	0xdf31
                    DF36    795 Fgait_designer$PARTNUM$0$0 == 0xdf36
                    DF36    796 _PARTNUM	=	0xdf36
                    DF37    797 Fgait_designer$VERSION$0$0 == 0xdf37
                    DF37    798 _VERSION	=	0xdf37
                    DF38    799 Fgait_designer$FREQEST$0$0 == 0xdf38
                    DF38    800 _FREQEST	=	0xdf38
                    DF39    801 Fgait_designer$LQI$0$0 == 0xdf39
                    DF39    802 _LQI	=	0xdf39
                    DF3A    803 Fgait_designer$RSSI$0$0 == 0xdf3a
                    DF3A    804 _RSSI	=	0xdf3a
                    DF3B    805 Fgait_designer$MARCSTATE$0$0 == 0xdf3b
                    DF3B    806 _MARCSTATE	=	0xdf3b
                    DF3C    807 Fgait_designer$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    808 _PKTSTATUS	=	0xdf3c
                    DF3D    809 Fgait_designer$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    810 _VCO_VC_DAC	=	0xdf3d
                    DF40    811 Fgait_designer$I2SCFG0$0$0 == 0xdf40
                    DF40    812 _I2SCFG0	=	0xdf40
                    DF41    813 Fgait_designer$I2SCFG1$0$0 == 0xdf41
                    DF41    814 _I2SCFG1	=	0xdf41
                    DF42    815 Fgait_designer$I2SDATL$0$0 == 0xdf42
                    DF42    816 _I2SDATL	=	0xdf42
                    DF43    817 Fgait_designer$I2SDATH$0$0 == 0xdf43
                    DF43    818 _I2SDATH	=	0xdf43
                    DF44    819 Fgait_designer$I2SWCNT$0$0 == 0xdf44
                    DF44    820 _I2SWCNT	=	0xdf44
                    DF45    821 Fgait_designer$I2SSTAT$0$0 == 0xdf45
                    DF45    822 _I2SSTAT	=	0xdf45
                    DF46    823 Fgait_designer$I2SCLKF0$0$0 == 0xdf46
                    DF46    824 _I2SCLKF0	=	0xdf46
                    DF47    825 Fgait_designer$I2SCLKF1$0$0 == 0xdf47
                    DF47    826 _I2SCLKF1	=	0xdf47
                    DF48    827 Fgait_designer$I2SCLKF2$0$0 == 0xdf48
                    DF48    828 _I2SCLKF2	=	0xdf48
                    DE00    829 Fgait_designer$USBADDR$0$0 == 0xde00
                    DE00    830 _USBADDR	=	0xde00
                    DE01    831 Fgait_designer$USBPOW$0$0 == 0xde01
                    DE01    832 _USBPOW	=	0xde01
                    DE02    833 Fgait_designer$USBIIF$0$0 == 0xde02
                    DE02    834 _USBIIF	=	0xde02
                    DE04    835 Fgait_designer$USBOIF$0$0 == 0xde04
                    DE04    836 _USBOIF	=	0xde04
                    DE06    837 Fgait_designer$USBCIF$0$0 == 0xde06
                    DE06    838 _USBCIF	=	0xde06
                    DE07    839 Fgait_designer$USBIIE$0$0 == 0xde07
                    DE07    840 _USBIIE	=	0xde07
                    DE09    841 Fgait_designer$USBOIE$0$0 == 0xde09
                    DE09    842 _USBOIE	=	0xde09
                    DE0B    843 Fgait_designer$USBCIE$0$0 == 0xde0b
                    DE0B    844 _USBCIE	=	0xde0b
                    DE0C    845 Fgait_designer$USBFRML$0$0 == 0xde0c
                    DE0C    846 _USBFRML	=	0xde0c
                    DE0D    847 Fgait_designer$USBFRMH$0$0 == 0xde0d
                    DE0D    848 _USBFRMH	=	0xde0d
                    DE0E    849 Fgait_designer$USBINDEX$0$0 == 0xde0e
                    DE0E    850 _USBINDEX	=	0xde0e
                    DE10    851 Fgait_designer$USBMAXI$0$0 == 0xde10
                    DE10    852 _USBMAXI	=	0xde10
                    DE11    853 Fgait_designer$USBCSIL$0$0 == 0xde11
                    DE11    854 _USBCSIL	=	0xde11
                    DE12    855 Fgait_designer$USBCSIH$0$0 == 0xde12
                    DE12    856 _USBCSIH	=	0xde12
                    DE13    857 Fgait_designer$USBMAXO$0$0 == 0xde13
                    DE13    858 _USBMAXO	=	0xde13
                    DE14    859 Fgait_designer$USBCSOL$0$0 == 0xde14
                    DE14    860 _USBCSOL	=	0xde14
                    DE15    861 Fgait_designer$USBCSOH$0$0 == 0xde15
                    DE15    862 _USBCSOH	=	0xde15
                    DE16    863 Fgait_designer$USBCNTL$0$0 == 0xde16
                    DE16    864 _USBCNTL	=	0xde16
                    DE17    865 Fgait_designer$USBCNTH$0$0 == 0xde17
                    DE17    866 _USBCNTH	=	0xde17
                    DE20    867 Fgait_designer$USBF0$0$0 == 0xde20
                    DE20    868 _USBF0	=	0xde20
                    DE22    869 Fgait_designer$USBF1$0$0 == 0xde22
                    DE22    870 _USBF1	=	0xde22
                    DE24    871 Fgait_designer$USBF2$0$0 == 0xde24
                    DE24    872 _USBF2	=	0xde24
                    DE26    873 Fgait_designer$USBF3$0$0 == 0xde26
                    DE26    874 _USBF3	=	0xde26
                    DE28    875 Fgait_designer$USBF4$0$0 == 0xde28
                    DE28    876 _USBF4	=	0xde28
                    DE2A    877 Fgait_designer$USBF5$0$0 == 0xde2a
                    DE2A    878 _USBF5	=	0xde2a
                            879 ;--------------------------------------------------------
                            880 ; absolute external ram data
                            881 ;--------------------------------------------------------
                            882 	.area XABS    (ABS,XDATA)
                            883 ;--------------------------------------------------------
                            884 ; external initialized ram data
                            885 ;--------------------------------------------------------
                            886 	.area XISEG   (XDATA)
                            887 	.area HOME    (CODE)
                            888 	.area GSINIT0 (CODE)
                            889 	.area GSINIT1 (CODE)
                            890 	.area GSINIT2 (CODE)
                            891 	.area GSINIT3 (CODE)
                            892 	.area GSINIT4 (CODE)
                            893 	.area GSINIT5 (CODE)
                            894 	.area GSINIT  (CODE)
                            895 	.area GSFINAL (CODE)
                            896 	.area CSEG    (CODE)
                            897 ;--------------------------------------------------------
                            898 ; interrupt vector 
                            899 ;--------------------------------------------------------
                            900 	.area HOME    (CODE)
   0400                     901 __interrupt_vect:
   0400 02 04 8D            902 	ljmp	__sdcc_gsinit_startup
   0403 32                  903 	reti
   0404                     904 	.ds	7
   040B 32                  905 	reti
   040C                     906 	.ds	7
   0413 32                  907 	reti
   0414                     908 	.ds	7
   041B 02 16 AB            909 	ljmp	_ISR_URX1
   041E                     910 	.ds	5
   0423 32                  911 	reti
   0424                     912 	.ds	7
   042B 32                  913 	reti
   042C                     914 	.ds	7
   0433 32                  915 	reti
   0434                     916 	.ds	7
   043B 32                  917 	reti
   043C                     918 	.ds	7
   0443 32                  919 	reti
   0444                     920 	.ds	7
   044B 32                  921 	reti
   044C                     922 	.ds	7
   0453 32                  923 	reti
   0454                     924 	.ds	7
   045B 32                  925 	reti
   045C                     926 	.ds	7
   0463 02 2D 6C            927 	ljmp	_ISR_T4
   0466                     928 	.ds	5
   046B 32                  929 	reti
   046C                     930 	.ds	7
   0473 02 16 6D            931 	ljmp	_ISR_UTX1
   0476                     932 	.ds	5
   047B 32                  933 	reti
   047C                     934 	.ds	7
   0483 02 1C 08            935 	ljmp	_ISR_RF
                            936 ;--------------------------------------------------------
                            937 ; global & static initialisations
                            938 ;--------------------------------------------------------
                            939 	.area HOME    (CODE)
                            940 	.area GSINIT  (CODE)
                            941 	.area GSFINAL (CODE)
                            942 	.area GSINIT  (CODE)
                            943 	.globl __sdcc_gsinit_startup
                            944 	.globl __sdcc_program_startup
                            945 	.globl __start__stack
                            946 	.globl __mcs51_genXINIT
                            947 	.globl __mcs51_genXRAMCLEAR
                            948 	.globl __mcs51_genRAMCLEAR
                            949 ;------------------------------------------------------------
                            950 ;Allocation info for local variables in function 'updateLeds'
                            951 ;------------------------------------------------------------
                            952 ;count                     Allocated with name '_updateLeds_count_3_7'
                            953 ;------------------------------------------------------------
                    0000    954 	G$updateLeds$0$0 ==.
                    0000    955 	C$gait_designer.c$117$2$14 ==.
                            956 ;	apps/gait_designer/gait_designer.c:117: static BIT dimYellowLed = 0;
   04EA C2 03               957 	clr	_updateLeds_dimYellowLed_1_1
                    0002    958 	G$main$0$0 ==.
                    0002    959 	C$gait_designer.c$92$1$1 ==.
                            960 ;	apps/gait_designer/gait_designer.c:92: BIT uartRxDisabled = 0;
   04EC C2 00               961 	clr	_uartRxDisabled
                    0004    962 	G$main$0$0 ==.
                    0004    963 	C$gait_designer.c$96$1$1 ==.
                            964 ;	apps/gait_designer/gait_designer.c:96: BIT framingErrorActive = 0;
   04EE C2 01               965 	clr	_framingErrorActive
                    0006    966 	G$main$0$0 ==.
                    0006    967 	C$gait_designer.c$98$1$1 ==.
                            968 ;	apps/gait_designer/gait_designer.c:98: BIT errorOccurredRecently = 0;
   04F0 C2 02               969 	clr	_errorOccurredRecently
                    0008    970 	G$main$0$0 ==.
                    0008    971 	C$gait_designer.c$107$1$1 ==.
                            972 ;	apps/gait_designer/gait_designer.c:107: uint16 g8speed = 25;
   04F2 78 3E               973 	mov	r0,#_g8speed
   04F4 74 19               974 	mov	a,#0x19
   04F6 F2                  975 	movx	@r0,a
   04F7 08                  976 	inc	r0
   04F8 E4                  977 	clr	a
   04F9 F2                  978 	movx	@r0,a
                    0010    979 	G$main$0$0 ==.
                    0010    980 	C$gait_designer.c$108$1$1 ==.
                            981 ;	apps/gait_designer/gait_designer.c:108: int8 g8playbackDir = 1; // value should only ever be -1 or 1.
   04FA 78 40               982 	mov	r0,#_g8playbackDir
   04FC 74 01               983 	mov	a,#0x01
   04FE F2                  984 	movx	@r0,a
                    0015    985 	G$main$0$0 ==.
                    0015    986 	C$gait_designer.c$109$1$1 ==.
                            987 ;	apps/gait_designer/gait_designer.c:109: int8 g8repeatCount = 0;
   04FF 78 41               988 	mov	r0,#_g8repeatCount
   0501 E4                  989 	clr	a
   0502 F2                  990 	movx	@r0,a
                            991 	.area GSFINAL (CODE)
   0574 02 04 86            992 	ljmp	__sdcc_program_startup
                            993 ;--------------------------------------------------------
                            994 ; Home
                            995 ;--------------------------------------------------------
                            996 	.area HOME    (CODE)
                            997 	.area HOME    (CODE)
   0486                     998 __sdcc_program_startup:
   0486 12 11 B6            999 	lcall	_main
                           1000 ;	return from main will lock up
   0489 80 FE              1001 	sjmp .
                           1002 ;--------------------------------------------------------
                           1003 ; code
                           1004 ;--------------------------------------------------------
                           1005 	.area CSEG    (CODE)
                           1006 ;------------------------------------------------------------
                           1007 ;Allocation info for local variables in function 'updateLeds'
                           1008 ;------------------------------------------------------------
                           1009 ;count                     Allocated with name '_updateLeds_count_3_7'
                           1010 ;------------------------------------------------------------
                    0000   1011 	G$updateLeds$0$0 ==.
                    0000   1012 	C$gait_designer.c$115$0$0 ==.
                           1013 ;	apps/gait_designer/gait_designer.c:115: void updateLeds()
                           1014 ;	-----------------------------------------
                           1015 ;	 function updateLeds
                           1016 ;	-----------------------------------------
   0A82                    1017 _updateLeds:
                    0007   1018 	ar7 = 0x07
                    0006   1019 	ar6 = 0x06
                    0005   1020 	ar5 = 0x05
                    0004   1021 	ar4 = 0x04
                    0003   1022 	ar3 = 0x03
                    0002   1023 	ar2 = 0x02
                    0001   1024 	ar1 = 0x01
                    0000   1025 	ar0 = 0x00
                    0000   1026 	C$gait_designer.c$122$1$1 ==.
                           1027 ;	apps/gait_designer/gait_designer.c:122: usbShowStatusWithGreenLed();
   0A82 12 32 A7           1028 	lcall	_usbShowStatusWithGreenLed
                    0003   1029 	C$gait_designer.c$125$1$1 ==.
                           1030 ;	apps/gait_designer/gait_designer.c:125: now = (uint16)getMs();
   0A85 12 2D 91           1031 	lcall	_getMs
   0A88 AC 82              1032 	mov	r4,dpl
   0A8A AD 83              1033 	mov	r5,dph
                    000A   1034 	C$gait_designer.c$132$1$1 ==.
                           1035 ;	apps/gait_designer/gait_designer.c:132: if (!radioLinkConnected())
   0A8C C0 05              1036 	push	ar5
   0A8E C0 04              1037 	push	ar4
   0A90 12 17 62           1038 	lcall	_radioLinkConnected
   0A93 D0 04              1039 	pop	ar4
   0A95 D0 05              1040 	pop	ar5
   0A97 40 12              1041 	jc	00108$
                    0017   1042 	C$gait_designer.c$136$3$3 ==.
                           1043 ;	apps/gait_designer/gait_designer.c:136: LED_YELLOW(now & 0x200 ? 1 : 0);
   0A99 ED                 1044 	mov	a,r5
   0A9A 30 E1 05           1045 	jnb	acc.1,00118$
   0A9D 43 FF 04           1046 	orl	_P2DIR,#0x04
   0AA0 80 43              1047 	sjmp	00109$
   0AA2                    1048 00118$:
   0AA2 AF FF              1049 	mov	r7,_P2DIR
   0AA4 53 07 FB           1050 	anl	ar7,#0xFB
   0AA7 8F FF              1051 	mov	_P2DIR,r7
   0AA9 80 3A              1052 	sjmp	00109$
   0AAB                    1053 00108$:
                    0029   1054 	C$gait_designer.c$142$2$4 ==.
                           1055 ;	apps/gait_designer/gait_designer.c:142: if ((now & 0x3FF) <= 20)
   0AAB 8C 06              1056 	mov	ar6,r4
   0AAD 74 03              1057 	mov	a,#0x03
   0AAF 5D                 1058 	anl	a,r5
   0AB0 FF                 1059 	mov	r7,a
   0AB1 C3                 1060 	clr	c
   0AB2 74 14              1061 	mov	a,#0x14
   0AB4 9E                 1062 	subb	a,r6
   0AB5 E4                 1063 	clr	a
   0AB6 9F                 1064 	subb	a,r7
   0AB7 40 05              1065 	jc	00105$
                    0037   1066 	C$gait_designer.c$145$4$6 ==.
                           1067 ;	apps/gait_designer/gait_designer.c:145: LED_YELLOW(1);
   0AB9 43 FF 04           1068 	orl	_P2DIR,#0x04
   0ABC 80 27              1069 	sjmp	00109$
   0ABE                    1070 00105$:
                    003C   1071 	C$gait_designer.c$147$2$4 ==.
                           1072 ;	apps/gait_designer/gait_designer.c:147: else if (dimYellowLed)
   0ABE 30 03 1D           1073 	jnb	_updateLeds_dimYellowLed_1_1,00102$
                    003F   1074 	C$gait_designer.c$150$3$7 ==.
                           1075 ;	apps/gait_designer/gait_designer.c:150: count++;
   0AC1 05 0B              1076 	inc	_updateLeds_count_3_7
                    0041   1077 	C$gait_designer.c$151$4$8 ==.
                           1078 ;	apps/gait_designer/gait_designer.c:151: LED_YELLOW((count & 0x7)==0);
   0AC3 74 07              1079 	mov	a,#0x07
   0AC5 55 0B              1080 	anl	a,_updateLeds_count_3_7
   0AC7 FF                 1081 	mov	r7,a
   0AC8 B4 01 00           1082 	cjne	a,#0x01,00142$
   0ACB                    1083 00142$:
   0ACB E4                 1084 	clr	a
   0ACC 33                 1085 	rlc	a
   0ACD FF                 1086 	mov	r7,a
   0ACE 60 05              1087 	jz	00120$
   0AD0 43 FF 04           1088 	orl	_P2DIR,#0x04
   0AD3 80 10              1089 	sjmp	00109$
   0AD5                    1090 00120$:
   0AD5 AF FF              1091 	mov	r7,_P2DIR
   0AD7 53 07 FB           1092 	anl	ar7,#0xFB
   0ADA 8F FF              1093 	mov	_P2DIR,r7
   0ADC 80 07              1094 	sjmp	00109$
   0ADE                    1095 00102$:
                    005C   1096 	C$gait_designer.c$155$4$10 ==.
                           1097 ;	apps/gait_designer/gait_designer.c:155: LED_YELLOW(0);
   0ADE AF FF              1098 	mov	r7,_P2DIR
   0AE0 53 07 FB           1099 	anl	ar7,#0xFB
   0AE3 8F FF              1100 	mov	_P2DIR,r7
   0AE5                    1101 00109$:
                    0063   1102 	C$gait_designer.c$159$1$1 ==.
                           1103 ;	apps/gait_designer/gait_designer.c:159: if (radioLinkActivityOccurred)
                    0063   1104 	C$gait_designer.c$161$2$11 ==.
                           1105 ;	apps/gait_designer/gait_designer.c:161: radioLinkActivityOccurred = 0;
   0AE5 10 0D 02           1106 	jbc	_radioLinkActivityOccurred,00144$
   0AE8 80 12              1107 	sjmp	00111$
   0AEA                    1108 00144$:
                    0068   1109 	C$gait_designer.c$162$2$11 ==.
                           1110 ;	apps/gait_designer/gait_designer.c:162: dimYellowLed ^= 1;
   0AEA A2 03              1111 	mov	c,_updateLeds_dimYellowLed_1_1
   0AEC E4                 1112 	clr	a
   0AED 33                 1113 	rlc	a
   0AEE 64 01              1114 	xrl	a,#0x01
   0AF0 FF                 1115 	mov	r7,a
   0AF1 24 FF              1116 	add	a,#0xff
   0AF3 92 03              1117 	mov	_updateLeds_dimYellowLed_1_1,c
                    0073   1118 	C$gait_designer.c$164$2$11 ==.
                           1119 ;	apps/gait_designer/gait_designer.c:164: lastRadioActivityTime = now;
   0AF5 78 42              1120 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   0AF7 EC                 1121 	mov	a,r4
   0AF8 F2                 1122 	movx	@r0,a
   0AF9 08                 1123 	inc	r0
   0AFA ED                 1124 	mov	a,r5
   0AFB F2                 1125 	movx	@r0,a
   0AFC                    1126 00111$:
                    007A   1127 	C$gait_designer.c$167$1$1 ==.
                           1128 ;	apps/gait_designer/gait_designer.c:167: if ((uint16)(now - lastRadioActivityTime) > 32)
   0AFC 78 42              1129 	mov	r0,#_updateLeds_lastRadioActivityTime_1_1
   0AFE D3                 1130 	setb	c
   0AFF E2                 1131 	movx	a,@r0
   0B00 9C                 1132 	subb	a,r4
   0B01 F4                 1133 	cpl	a
   0B02 B3                 1134 	cpl	c
   0B03 FE                 1135 	mov	r6,a
   0B04 B3                 1136 	cpl	c
   0B05 08                 1137 	inc	r0
   0B06 E2                 1138 	movx	a,@r0
   0B07 9D                 1139 	subb	a,r5
   0B08 F4                 1140 	cpl	a
   0B09 FF                 1141 	mov	r7,a
   0B0A C3                 1142 	clr	c
   0B0B 74 20              1143 	mov	a,#0x20
   0B0D 9E                 1144 	subb	a,r6
   0B0E E4                 1145 	clr	a
   0B0F 9F                 1146 	subb	a,r7
   0B10 50 02              1147 	jnc	00113$
                    0090   1148 	C$gait_designer.c$169$2$12 ==.
                           1149 ;	apps/gait_designer/gait_designer.c:169: dimYellowLed = 0;
   0B12 C2 03              1150 	clr	_updateLeds_dimYellowLed_1_1
   0B14                    1151 00113$:
                    0092   1152 	C$gait_designer.c$172$1$1 ==.
                           1153 ;	apps/gait_designer/gait_designer.c:172: if ((uint8)(now - lastErrorTime) > 100)
   0B14 78 3D              1154 	mov	r0,#_lastErrorTime
   0B16 D3                 1155 	setb	c
   0B17 E2                 1156 	movx	a,@r0
   0B18 9C                 1157 	subb	a,r4
   0B19 F4                 1158 	cpl	a
   0B1A FC                 1159 	mov  r4,a
   0B1B 24 9B              1160 	add	a,#0xff - 0x64
   0B1D 50 02              1161 	jnc	00115$
                    009D   1162 	C$gait_designer.c$174$2$13 ==.
                           1163 ;	apps/gait_designer/gait_designer.c:174: errorOccurredRecently = 0;
   0B1F C2 02              1164 	clr	_errorOccurredRecently
   0B21                    1165 00115$:
                    009F   1166 	C$gait_designer.c$177$2$14 ==.
                           1167 ;	apps/gait_designer/gait_designer.c:177: LED_RED(errorOccurredRecently || uartRxDisabled);
   0B21 20 02 07           1168 	jb	_errorOccurredRecently,00125$
   0B24 20 00 04           1169 	jb	_uartRxDisabled,00125$
   0B27 7F 00              1170 	mov	r7,#0x00
   0B29 80 02              1171 	sjmp	00126$
   0B2B                    1172 00125$:
   0B2B 7F 01              1173 	mov	r7,#0x01
   0B2D                    1174 00126$:
   0B2D EF                 1175 	mov	a,r7
   0B2E 60 05              1176 	jz	00122$
   0B30 43 FF 02           1177 	orl	_P2DIR,#0x02
   0B33 80 07              1178 	sjmp	00116$
   0B35                    1179 00122$:
   0B35 AF FF              1180 	mov	r7,_P2DIR
   0B37 53 07 FD           1181 	anl	ar7,#0xFD
   0B3A 8F FF              1182 	mov	_P2DIR,r7
   0B3C                    1183 00116$:
                    00BA   1184 	C$gait_designer.c$178$2$14 ==.
                    00BA   1185 	XG$updateLeds$0$0 ==.
   0B3C 22                 1186 	ret
                           1187 ;------------------------------------------------------------
                           1188 ;Allocation info for local variables in function 'ioRxSignals'
                           1189 ;------------------------------------------------------------
                    00BB   1190 	G$ioRxSignals$0$0 ==.
                    00BB   1191 	C$gait_designer.c$183$2$14 ==.
                           1192 ;	apps/gait_designer/gait_designer.c:183: uint8 ioRxSignals()
                           1193 ;	-----------------------------------------
                           1194 ;	 function ioRxSignals
                           1195 ;	-----------------------------------------
   0B3D                    1196 _ioRxSignals:
                    00BB   1197 	C$gait_designer.c$185$1$14 ==.
                           1198 ;	apps/gait_designer/gait_designer.c:185: uint8 signals = 0;
   0B3D 7F 00              1199 	mov	r7,#0x00
                    00BD   1200 	C$gait_designer.c$187$1$1 ==.
                           1201 ;	apps/gait_designer/gait_designer.c:187: if ((param_CD_pin >= 0 && isPinHigh(param_CD_pin)) ||
   0B3F 90 33 8D           1202 	mov	dptr,#_param_CD_pin
   0B42 E4                 1203 	clr	a
   0B43 93                 1204 	movc	a,@a+dptr
   0B44 FB                 1205 	mov	r3,a
   0B45 74 01              1206 	mov	a,#0x01
   0B47 93                 1207 	movc	a,@a+dptr
   0B48 FC                 1208 	mov	r4,a
   0B49 74 02              1209 	mov	a,#0x02
   0B4B 93                 1210 	movc	a,@a+dptr
   0B4C FD                 1211 	mov	r5,a
   0B4D 74 03              1212 	mov	a,#0x03
   0B4F 93                 1213 	movc	a,@a+dptr
   0B50 FE                 1214 	mov	r6,a
   0B51 20 E7 0B           1215 	jb	acc.7,00105$
   0B54 8B 82              1216 	mov	dpl,r3
   0B56 C0 07              1217 	push	ar7
   0B58 12 31 08           1218 	lcall	_isPinHigh
   0B5B D0 07              1219 	pop	ar7
   0B5D 40 20              1220 	jc	00101$
   0B5F                    1221 00105$:
                    00DD   1222 	C$gait_designer.c$188$1$1 ==.
                           1223 ;	apps/gait_designer/gait_designer.c:188: (param_nCD_pin >= 0 && !isPinHigh(param_nCD_pin)))
   0B5F 90 33 7D           1224 	mov	dptr,#_param_nCD_pin
   0B62 E4                 1225 	clr	a
   0B63 93                 1226 	movc	a,@a+dptr
   0B64 FB                 1227 	mov	r3,a
   0B65 74 01              1228 	mov	a,#0x01
   0B67 93                 1229 	movc	a,@a+dptr
   0B68 FC                 1230 	mov	r4,a
   0B69 74 02              1231 	mov	a,#0x02
   0B6B 93                 1232 	movc	a,@a+dptr
   0B6C FD                 1233 	mov	r5,a
   0B6D 74 03              1234 	mov	a,#0x03
   0B6F 93                 1235 	movc	a,@a+dptr
   0B70 FE                 1236 	mov	r6,a
   0B71 20 E7 0D           1237 	jb	acc.7,00102$
   0B74 8B 82              1238 	mov	dpl,r3
   0B76 C0 07              1239 	push	ar7
   0B78 12 31 08           1240 	lcall	_isPinHigh
   0B7B D0 07              1241 	pop	ar7
   0B7D 40 02              1242 	jc	00102$
   0B7F                    1243 00101$:
                    00FD   1244 	C$gait_designer.c$190$2$2 ==.
                           1245 ;	apps/gait_designer/gait_designer.c:190: signals |= 2;
   0B7F 7F 02              1246 	mov	r7,#0x02
   0B81                    1247 00102$:
                    00FF   1248 	C$gait_designer.c$193$1$1 ==.
                           1249 ;	apps/gait_designer/gait_designer.c:193: if ((param_DSR_pin >= 0 && isPinHigh(param_DSR_pin)) ||
   0B81 90 33 89           1250 	mov	dptr,#_param_DSR_pin
   0B84 E4                 1251 	clr	a
   0B85 93                 1252 	movc	a,@a+dptr
   0B86 FB                 1253 	mov	r3,a
   0B87 74 01              1254 	mov	a,#0x01
   0B89 93                 1255 	movc	a,@a+dptr
   0B8A FC                 1256 	mov	r4,a
   0B8B 74 02              1257 	mov	a,#0x02
   0B8D 93                 1258 	movc	a,@a+dptr
   0B8E FD                 1259 	mov	r5,a
   0B8F 74 03              1260 	mov	a,#0x03
   0B91 93                 1261 	movc	a,@a+dptr
   0B92 FE                 1262 	mov	r6,a
   0B93 20 E7 0B           1263 	jb	acc.7,00110$
   0B96 8B 82              1264 	mov	dpl,r3
   0B98 C0 07              1265 	push	ar7
   0B9A 12 31 08           1266 	lcall	_isPinHigh
   0B9D D0 07              1267 	pop	ar7
   0B9F 40 20              1268 	jc	00106$
   0BA1                    1269 00110$:
                    011F   1270 	C$gait_designer.c$194$1$1 ==.
                           1271 ;	apps/gait_designer/gait_designer.c:194: (param_nDSR_pin >= 0 && !isPinHigh(param_nDSR_pin)))
   0BA1 90 33 79           1272 	mov	dptr,#_param_nDSR_pin
   0BA4 E4                 1273 	clr	a
   0BA5 93                 1274 	movc	a,@a+dptr
   0BA6 FB                 1275 	mov	r3,a
   0BA7 74 01              1276 	mov	a,#0x01
   0BA9 93                 1277 	movc	a,@a+dptr
   0BAA FC                 1278 	mov	r4,a
   0BAB 74 02              1279 	mov	a,#0x02
   0BAD 93                 1280 	movc	a,@a+dptr
   0BAE FD                 1281 	mov	r5,a
   0BAF 74 03              1282 	mov	a,#0x03
   0BB1 93                 1283 	movc	a,@a+dptr
   0BB2 FE                 1284 	mov	r6,a
   0BB3 20 E7 0E           1285 	jb	acc.7,00107$
   0BB6 8B 82              1286 	mov	dpl,r3
   0BB8 C0 07              1287 	push	ar7
   0BBA 12 31 08           1288 	lcall	_isPinHigh
   0BBD D0 07              1289 	pop	ar7
   0BBF 40 03              1290 	jc	00107$
   0BC1                    1291 00106$:
                    013F   1292 	C$gait_designer.c$196$2$3 ==.
                           1293 ;	apps/gait_designer/gait_designer.c:196: signals |= 1;
   0BC1 43 07 01           1294 	orl	ar7,#0x01
   0BC4                    1295 00107$:
                    0142   1296 	C$gait_designer.c$199$1$1 ==.
                           1297 ;	apps/gait_designer/gait_designer.c:199: return signals;
   0BC4 8F 82              1298 	mov	dpl,r7
                    0144   1299 	C$gait_designer.c$200$1$1 ==.
                    0144   1300 	XG$ioRxSignals$0$0 ==.
   0BC6 22                 1301 	ret
                           1302 ;------------------------------------------------------------
                           1303 ;Allocation info for local variables in function 'ioTxSignals'
                           1304 ;------------------------------------------------------------
                    0145   1305 	G$ioTxSignals$0$0 ==.
                    0145   1306 	C$gait_designer.c$206$1$1 ==.
                           1307 ;	apps/gait_designer/gait_designer.c:206: void ioTxSignals(uint8 signals)
                           1308 ;	-----------------------------------------
                           1309 ;	 function ioTxSignals
                           1310 ;	-----------------------------------------
   0BC7                    1311 _ioTxSignals:
   0BC7 E5 82              1312 	mov	a,dpl
   0BC9 78 44              1313 	mov	r0,#_ioTxSignals_signals_1_1
   0BCB F2                 1314 	movx	@r0,a
                    014A   1315 	C$gait_designer.c$212$1$1 ==.
                           1316 ;	apps/gait_designer/gait_designer.c:212: setDigitalOutput(param_nDTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 0 : 1);
   0BCC 78 44              1317 	mov	r0,#_ioTxSignals_signals_1_1
   0BCE E2                 1318 	movx	a,@r0
   0BCF 54 01              1319 	anl	a,#0x01
   0BD1 FE                 1320 	mov	r6,a
   0BD2 B4 01 00           1321 	cjne	a,#0x01,00112$
   0BD5                    1322 00112$:
   0BD5 E4                 1323 	clr	a
   0BD6 33                 1324 	rlc	a
   0BD7 24 FF              1325 	add	a,#0xff
   0BD9 92 04              1326 	mov	_ioTxSignals_sloc0_1_0,c
   0BDB 90 33 71           1327 	mov	dptr,#_param_nDTR_pin
   0BDE E4                 1328 	clr	a
   0BDF 93                 1329 	movc	a,@a+dptr
   0BE0 FA                 1330 	mov	r2,a
   0BE1 74 01              1331 	mov	a,#0x01
   0BE3 93                 1332 	movc	a,@a+dptr
   0BE4 74 02              1333 	mov	a,#0x02
   0BE6 93                 1334 	movc	a,@a+dptr
   0BE7 74 03              1335 	mov	a,#0x03
   0BE9 93                 1336 	movc	a,@a+dptr
   0BEA 8A 82              1337 	mov	dpl,r2
   0BEC A2 04              1338 	mov	c,_ioTxSignals_sloc0_1_0
   0BEE 92 F0              1339 	mov	b[0],c
   0BF0 C0 06              1340 	push	ar6
   0BF2 85 F0 24           1341 	mov	bits,b
   0BF5 12 2D F1           1342 	lcall	_setDigitalOutput
   0BF8 D0 06              1343 	pop	ar6
                    0178   1344 	C$gait_designer.c$213$1$1 ==.
                           1345 ;	apps/gait_designer/gait_designer.c:213: setDigitalOutput(param_nRTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 0 : 1);
   0BFA 78 44              1346 	mov	r0,#_ioTxSignals_signals_1_1
   0BFC E2                 1347 	movx	a,@r0
   0BFD 03                 1348 	rr	a
   0BFE 54 01              1349 	anl	a,#0x01
   0C00 FD                 1350 	mov	r5,a
   0C01 B4 01 00           1351 	cjne	a,#0x01,00113$
   0C04                    1352 00113$:
   0C04 E4                 1353 	clr	a
   0C05 33                 1354 	rlc	a
   0C06 24 FF              1355 	add	a,#0xff
   0C08 92 04              1356 	mov	_ioTxSignals_sloc0_1_0,c
   0C0A 90 33 75           1357 	mov	dptr,#_param_nRTS_pin
   0C0D E4                 1358 	clr	a
   0C0E 93                 1359 	movc	a,@a+dptr
   0C0F FA                 1360 	mov	r2,a
   0C10 74 01              1361 	mov	a,#0x01
   0C12 93                 1362 	movc	a,@a+dptr
   0C13 74 02              1363 	mov	a,#0x02
   0C15 93                 1364 	movc	a,@a+dptr
   0C16 74 03              1365 	mov	a,#0x03
   0C18 93                 1366 	movc	a,@a+dptr
   0C19 8A 82              1367 	mov	dpl,r2
   0C1B A2 04              1368 	mov	c,_ioTxSignals_sloc0_1_0
   0C1D 92 F0              1369 	mov	b[0],c
   0C1F C0 06              1370 	push	ar6
   0C21 C0 05              1371 	push	ar5
   0C23 85 F0 24           1372 	mov	bits,b
   0C26 12 2D F1           1373 	lcall	_setDigitalOutput
   0C29 D0 05              1374 	pop	ar5
   0C2B D0 06              1375 	pop	ar6
                    01AB   1376 	C$gait_designer.c$216$1$1 ==.
                           1377 ;	apps/gait_designer/gait_designer.c:216: setDigitalOutput(param_DTR_pin, (signals & ACM_CONTROL_LINE_DTR) ? 1 : 0);
   0C2D EE                 1378 	mov	a,r6
   0C2E 24 FF              1379 	add	a,#0xff
   0C30 92 04              1380 	mov	_ioTxSignals_sloc0_1_0,c
   0C32 90 33 81           1381 	mov	dptr,#_param_DTR_pin
   0C35 E4                 1382 	clr	a
   0C36 93                 1383 	movc	a,@a+dptr
   0C37 FB                 1384 	mov	r3,a
   0C38 74 01              1385 	mov	a,#0x01
   0C3A 93                 1386 	movc	a,@a+dptr
   0C3B 74 02              1387 	mov	a,#0x02
   0C3D 93                 1388 	movc	a,@a+dptr
   0C3E 74 03              1389 	mov	a,#0x03
   0C40 93                 1390 	movc	a,@a+dptr
   0C41 8B 82              1391 	mov	dpl,r3
   0C43 A2 04              1392 	mov	c,_ioTxSignals_sloc0_1_0
   0C45 92 F0              1393 	mov	b[0],c
   0C47 C0 05              1394 	push	ar5
   0C49 85 F0 24           1395 	mov	bits,b
   0C4C 12 2D F1           1396 	lcall	_setDigitalOutput
   0C4F D0 05              1397 	pop	ar5
                    01CF   1398 	C$gait_designer.c$217$1$1 ==.
                           1399 ;	apps/gait_designer/gait_designer.c:217: setDigitalOutput(param_RTS_pin, (signals & ACM_CONTROL_LINE_RTS) ? 1 : 0);
   0C51 ED                 1400 	mov	a,r5
   0C52 24 FF              1401 	add	a,#0xff
   0C54 92 04              1402 	mov	_ioTxSignals_sloc0_1_0,c
   0C56 90 33 85           1403 	mov	dptr,#_param_RTS_pin
   0C59 E4                 1404 	clr	a
   0C5A 93                 1405 	movc	a,@a+dptr
   0C5B FC                 1406 	mov	r4,a
   0C5C 74 01              1407 	mov	a,#0x01
   0C5E 93                 1408 	movc	a,@a+dptr
   0C5F 74 02              1409 	mov	a,#0x02
   0C61 93                 1410 	movc	a,@a+dptr
   0C62 74 03              1411 	mov	a,#0x03
   0C64 93                 1412 	movc	a,@a+dptr
   0C65 8C 82              1413 	mov	dpl,r4
   0C67 A2 04              1414 	mov	c,_ioTxSignals_sloc0_1_0
   0C69 92 F0              1415 	mov	b[0],c
   0C6B 85 F0 24           1416 	mov	bits,b
   0C6E 12 2D F1           1417 	lcall	_setDigitalOutput
                    01EF   1418 	C$gait_designer.c$220$1$1 ==.
                           1419 ;	apps/gait_designer/gait_designer.c:220: if (!(lastSignals & ACM_CONTROL_LINE_DTR) && (signals & ACM_CONTROL_LINE_DTR))
   0C71 78 46              1420 	mov	r0,#_ioTxSignals_lastSignals_1_1
   0C73 E2                 1421 	movx	a,@r0
   0C74 54 01              1422 	anl	a,#0x01
   0C76 60 02              1423 	jz	00115$
   0C78 80 30              1424 	sjmp	00104$
   0C7A                    1425 00115$:
   0C7A 78 44              1426 	mov	r0,#_ioTxSignals_signals_1_1
   0C7C E2                 1427 	movx	a,@r0
   0C7D 54 01              1428 	anl	a,#0x01
   0C7F 60 29              1429 	jz	00104$
                    01FF   1430 	C$gait_designer.c$224$2$2 ==.
                           1431 ;	apps/gait_designer/gait_designer.c:224: setDigitalOutput(param_arduino_DTR_pin, HIGH);
   0C81 90 33 91           1432 	mov	dptr,#_param_arduino_DTR_pin
   0C84 E4                 1433 	clr	a
   0C85 93                 1434 	movc	a,@a+dptr
   0C86 FC                 1435 	mov	r4,a
   0C87 74 01              1436 	mov	a,#0x01
   0C89 93                 1437 	movc	a,@a+dptr
   0C8A 74 02              1438 	mov	a,#0x02
   0C8C 93                 1439 	movc	a,@a+dptr
   0C8D 74 03              1440 	mov	a,#0x03
   0C8F 93                 1441 	movc	a,@a+dptr
   0C90 8C 82              1442 	mov	dpl,r4
   0C92 D2 F0              1443 	setb	b[0]
   0C94 85 F0 24           1444 	mov	bits,b
   0C97 12 2D F1           1445 	lcall	_setDigitalOutput
                    0218   1446 	C$gait_designer.c$225$2$2 ==.
                           1447 ;	apps/gait_designer/gait_designer.c:225: nTrstPulseStartTime = getMs();
   0C9A 12 2D 91           1448 	lcall	_getMs
   0C9D AC 82              1449 	mov	r4,dpl
   0C9F AD 83              1450 	mov	r5,dph
   0CA1 AE F0              1451 	mov	r6,b
   0CA3 FF                 1452 	mov	r7,a
   0CA4 78 45              1453 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0CA6 EC                 1454 	mov	a,r4
   0CA7 F2                 1455 	movx	@r0,a
   0CA8 80 2F              1456 	sjmp	00105$
   0CAA                    1457 00104$:
                    0228   1458 	C$gait_designer.c$227$1$1 ==.
                           1459 ;	apps/gait_designer/gait_designer.c:227: else if ((uint8)(getMs() - nTrstPulseStartTime) >= 2)
   0CAA 12 2D 91           1460 	lcall	_getMs
   0CAD AC 82              1461 	mov	r4,dpl
   0CAF AD 83              1462 	mov	r5,dph
   0CB1 AE F0              1463 	mov	r6,b
   0CB3 FF                 1464 	mov	r7,a
   0CB4 78 45              1465 	mov	r0,#_ioTxSignals_nTrstPulseStartTime_1_1
   0CB6 D3                 1466 	setb	c
   0CB7 E2                 1467 	movx	a,@r0
   0CB8 9C                 1468 	subb	a,r4
   0CB9 F4                 1469 	cpl	a
   0CBA FC                 1470 	mov	r4,a
   0CBB BC 02 00           1471 	cjne	r4,#0x02,00117$
   0CBE                    1472 00117$:
   0CBE 40 19              1473 	jc	00105$
                    023E   1474 	C$gait_designer.c$229$2$3 ==.
                           1475 ;	apps/gait_designer/gait_designer.c:229: setDigitalOutput(param_arduino_DTR_pin, LOW);
   0CC0 90 33 91           1476 	mov	dptr,#_param_arduino_DTR_pin
   0CC3 E4                 1477 	clr	a
   0CC4 93                 1478 	movc	a,@a+dptr
   0CC5 FC                 1479 	mov	r4,a
   0CC6 74 01              1480 	mov	a,#0x01
   0CC8 93                 1481 	movc	a,@a+dptr
   0CC9 74 02              1482 	mov	a,#0x02
   0CCB 93                 1483 	movc	a,@a+dptr
   0CCC 74 03              1484 	mov	a,#0x03
   0CCE 93                 1485 	movc	a,@a+dptr
   0CCF 8C 82              1486 	mov	dpl,r4
   0CD1 C2 F0              1487 	clr	b[0]
   0CD3 85 F0 24           1488 	mov	bits,b
   0CD6 12 2D F1           1489 	lcall	_setDigitalOutput
   0CD9                    1490 00105$:
                    0257   1491 	C$gait_designer.c$232$1$1 ==.
                           1492 ;	apps/gait_designer/gait_designer.c:232: lastSignals = signals;
   0CD9 78 44              1493 	mov	r0,#_ioTxSignals_signals_1_1
   0CDB 79 46              1494 	mov	r1,#_ioTxSignals_lastSignals_1_1
   0CDD E2                 1495 	movx	a,@r0
   0CDE F3                 1496 	movx	@r1,a
                    025D   1497 	C$gait_designer.c$233$1$1 ==.
                    025D   1498 	XG$ioTxSignals$0$0 ==.
   0CDF 22                 1499 	ret
                           1500 ;------------------------------------------------------------
                           1501 ;Allocation info for local variables in function 'errorOccurred'
                           1502 ;------------------------------------------------------------
                    025E   1503 	G$errorOccurred$0$0 ==.
                    025E   1504 	C$gait_designer.c$235$1$1 ==.
                           1505 ;	apps/gait_designer/gait_designer.c:235: void errorOccurred()
                           1506 ;	-----------------------------------------
                           1507 ;	 function errorOccurred
                           1508 ;	-----------------------------------------
   0CE0                    1509 _errorOccurred:
                    025E   1510 	C$gait_designer.c$237$1$1 ==.
                           1511 ;	apps/gait_designer/gait_designer.c:237: lastErrorTime = (uint8)getMs();
   0CE0 12 2D 91           1512 	lcall	_getMs
   0CE3 AC 82              1513 	mov	r4,dpl
   0CE5 78 3D              1514 	mov	r0,#_lastErrorTime
   0CE7 EC                 1515 	mov	a,r4
   0CE8 F2                 1516 	movx	@r0,a
                    0267   1517 	C$gait_designer.c$238$1$1 ==.
                           1518 ;	apps/gait_designer/gait_designer.c:238: errorOccurredRecently = 1;
   0CE9 D2 02              1519 	setb	_errorOccurredRecently
                    0269   1520 	C$gait_designer.c$239$1$1 ==.
                    0269   1521 	XG$errorOccurred$0$0 ==.
   0CEB 22                 1522 	ret
                           1523 ;------------------------------------------------------------
                           1524 ;Allocation info for local variables in function 'errorService'
                           1525 ;------------------------------------------------------------
                           1526 ;sloc0                     Allocated with name '_errorService_sloc0_1_0'
                           1527 ;------------------------------------------------------------
                    026A   1528 	G$errorService$0$0 ==.
                    026A   1529 	C$gait_designer.c$241$1$1 ==.
                           1530 ;	apps/gait_designer/gait_designer.c:241: void errorService()
                           1531 ;	-----------------------------------------
                           1532 ;	 function errorService
                           1533 ;	-----------------------------------------
   0CEC                    1534 _errorService:
                    026A   1535 	C$gait_designer.c$245$1$1 ==.
                           1536 ;	apps/gait_designer/gait_designer.c:245: if (uart1RxBufferFullOccurred)
                    026A   1537 	C$gait_designer.c$247$2$2 ==.
                           1538 ;	apps/gait_designer/gait_designer.c:247: uart1RxBufferFullOccurred = 0;
   0CEC 10 07 02           1539 	jbc	_uart1RxBufferFullOccurred,00129$
   0CEF 80 03              1540 	sjmp	00102$
   0CF1                    1541 00129$:
                    026F   1542 	C$gait_designer.c$248$2$2 ==.
                           1543 ;	apps/gait_designer/gait_designer.c:248: errorOccurred();
   0CF1 12 0C E0           1544 	lcall	_errorOccurred
   0CF4                    1545 00102$:
                    0272   1546 	C$gait_designer.c$251$1$1 ==.
                           1547 ;	apps/gait_designer/gait_designer.c:251: if (uart1RxFramingErrorOccurred)
                    0272   1548 	C$gait_designer.c$253$2$3 ==.
                           1549 ;	apps/gait_designer/gait_designer.c:253: uart1RxFramingErrorOccurred = 0;
   0CF4 10 06 02           1550 	jbc	_uart1RxFramingErrorOccurred,00130$
   0CF7 80 41              1551 	sjmp	00106$
   0CF9                    1552 00130$:
                    0277   1553 	C$gait_designer.c$256$2$3 ==.
                           1554 ;	apps/gait_designer/gait_designer.c:256: framingErrorActive = 1;
   0CF9 D2 01              1555 	setb	_framingErrorActive
                    0279   1556 	C$gait_designer.c$257$2$3 ==.
                           1557 ;	apps/gait_designer/gait_designer.c:257: errorOccurred();
   0CFB 12 0C E0           1558 	lcall	_errorOccurred
                    027C   1559 	C$gait_designer.c$259$2$3 ==.
                           1560 ;	apps/gait_designer/gait_designer.c:259: if (param_framing_error_ms > 0)
   0CFE 90 33 95           1561 	mov	dptr,#_param_framing_error_ms
   0D01 E4                 1562 	clr	a
   0D02 93                 1563 	movc	a,@a+dptr
   0D03 FC                 1564 	mov	r4,a
   0D04 74 01              1565 	mov	a,#0x01
   0D06 93                 1566 	movc	a,@a+dptr
   0D07 FD                 1567 	mov	r5,a
   0D08 74 02              1568 	mov	a,#0x02
   0D0A 93                 1569 	movc	a,@a+dptr
   0D0B FE                 1570 	mov	r6,a
   0D0C 74 03              1571 	mov	a,#0x03
   0D0E 93                 1572 	movc	a,@a+dptr
   0D0F FF                 1573 	mov	r7,a
   0D10 C3                 1574 	clr	c
   0D11 E4                 1575 	clr	a
   0D12 9C                 1576 	subb	a,r4
   0D13 E4                 1577 	clr	a
   0D14 9D                 1578 	subb	a,r5
   0D15 E4                 1579 	clr	a
   0D16 9E                 1580 	subb	a,r6
   0D17 E4                 1581 	clr	a
   0D18 64 80              1582 	xrl	a,#0x80
   0D1A 8F F0              1583 	mov	b,r7
   0D1C 63 F0 80           1584 	xrl	b,#0x80
   0D1F 95 F0              1585 	subb	a,b
   0D21 50 17              1586 	jnc	00106$
                    02A1   1587 	C$gait_designer.c$262$3$4 ==.
                           1588 ;	apps/gait_designer/gait_designer.c:262: U1CSR &= ~0x40;    // U1CSR.RE = 0.  Disables reception of bytes on the UART.
   0D23 AF F8              1589 	mov	r7,_U1CSR
   0D25 53 07 BF           1590 	anl	ar7,#0xBF
   0D28 8F F8              1591 	mov	_U1CSR,r7
                    02A8   1592 	C$gait_designer.c$263$3$4 ==.
                           1593 ;	apps/gait_designer/gait_designer.c:263: uartRxDisabled = 1;
   0D2A D2 00              1594 	setb	_uartRxDisabled
                    02AA   1595 	C$gait_designer.c$264$3$4 ==.
                           1596 ;	apps/gait_designer/gait_designer.c:264: lastRxLowTime = (uint8)getMs();  // Initialize lastRxLowTime even if the line isn't low right now.
   0D2C 12 2D 91           1597 	lcall	_getMs
   0D2F AC 82              1598 	mov	r4,dpl
   0D31 AD 83              1599 	mov	r5,dph
   0D33 AE F0              1600 	mov	r6,b
   0D35 FF                 1601 	mov	r7,a
   0D36 78 47              1602 	mov	r0,#_errorService_lastRxLowTime_1_1
   0D38 EC                 1603 	mov	a,r4
   0D39 F2                 1604 	movx	@r0,a
   0D3A                    1605 00106$:
                    02B8   1606 	C$gait_designer.c$268$1$1 ==.
                           1607 ;	apps/gait_designer/gait_designer.c:268: if (framingErrorActive)
   0D3A 30 01 0F           1608 	jnb	_framingErrorActive,00111$
                    02BB   1609 	C$gait_designer.c$270$2$5 ==.
                           1610 ;	apps/gait_designer/gait_designer.c:270: if (!isPinHigh(17))
   0D3D 75 82 11           1611 	mov	dpl,#0x11
   0D40 12 31 08           1612 	lcall	_isPinHigh
   0D43 40 05              1613 	jc	00108$
                    02C3   1614 	C$gait_designer.c$272$3$6 ==.
                           1615 ;	apps/gait_designer/gait_designer.c:272: errorOccurred();
   0D45 12 0C E0           1616 	lcall	_errorOccurred
   0D48 80 02              1617 	sjmp	00111$
   0D4A                    1618 00108$:
                    02C8   1619 	C$gait_designer.c$276$3$7 ==.
                           1620 ;	apps/gait_designer/gait_designer.c:276: framingErrorActive = 0;
   0D4A C2 01              1621 	clr	_framingErrorActive
   0D4C                    1622 00111$:
                    02CA   1623 	C$gait_designer.c$280$1$1 ==.
                           1624 ;	apps/gait_designer/gait_designer.c:280: if (uartRxDisabled)
   0D4C 30 00 60           1625 	jnb	_uartRxDisabled,00119$
                    02CD   1626 	C$gait_designer.c$282$2$8 ==.
                           1627 ;	apps/gait_designer/gait_designer.c:282: if (!isPinHigh(17))
   0D4F 75 82 11           1628 	mov	dpl,#0x11
   0D52 12 31 08           1629 	lcall	_isPinHigh
   0D55 40 10              1630 	jc	00115$
                    02D5   1631 	C$gait_designer.c$285$3$9 ==.
                           1632 ;	apps/gait_designer/gait_designer.c:285: lastRxLowTime = (uint8)getMs();
   0D57 12 2D 91           1633 	lcall	_getMs
   0D5A AC 82              1634 	mov	r4,dpl
   0D5C AD 83              1635 	mov	r5,dph
   0D5E AE F0              1636 	mov	r6,b
   0D60 FF                 1637 	mov	r7,a
   0D61 78 47              1638 	mov	r0,#_errorService_lastRxLowTime_1_1
   0D63 EC                 1639 	mov	a,r4
   0D64 F2                 1640 	movx	@r0,a
   0D65 80 48              1641 	sjmp	00119$
   0D67                    1642 00115$:
                    02E5   1643 	C$gait_designer.c$287$2$8 ==.
                           1644 ;	apps/gait_designer/gait_designer.c:287: else if ((uint8)(getMs() - lastRxLowTime) > param_framing_error_ms)
   0D67 12 2D 91           1645 	lcall	_getMs
   0D6A AC 82              1646 	mov	r4,dpl
   0D6C AD 83              1647 	mov	r5,dph
   0D6E 78 47              1648 	mov	r0,#_errorService_lastRxLowTime_1_1
   0D70 D3                 1649 	setb	c
   0D71 E2                 1650 	movx	a,@r0
   0D72 9C                 1651 	subb	a,r4
   0D73 F4                 1652 	cpl	a
   0D74 FC                 1653 	mov	r4,a
   0D75 90 33 95           1654 	mov	dptr,#_param_framing_error_ms
   0D78 E4                 1655 	clr	a
   0D79 93                 1656 	movc	a,@a+dptr
   0D7A F5 0C              1657 	mov	_errorService_sloc0_1_0,a
   0D7C 74 01              1658 	mov	a,#0x01
   0D7E 93                 1659 	movc	a,@a+dptr
   0D7F F5 0D              1660 	mov	(_errorService_sloc0_1_0 + 1),a
   0D81 74 02              1661 	mov	a,#0x02
   0D83 93                 1662 	movc	a,@a+dptr
   0D84 F5 0E              1663 	mov	(_errorService_sloc0_1_0 + 2),a
   0D86 74 03              1664 	mov	a,#0x03
   0D88 93                 1665 	movc	a,@a+dptr
   0D89 F5 0F              1666 	mov	(_errorService_sloc0_1_0 + 3),a
   0D8B 8C 02              1667 	mov	ar2,r4
   0D8D 7C 00              1668 	mov	r4,#0x00
   0D8F 7E 00              1669 	mov	r6,#0x00
   0D91 7F 00              1670 	mov	r7,#0x00
   0D93 C3                 1671 	clr	c
   0D94 E5 0C              1672 	mov	a,_errorService_sloc0_1_0
   0D96 9A                 1673 	subb	a,r2
   0D97 E5 0D              1674 	mov	a,(_errorService_sloc0_1_0 + 1)
   0D99 9C                 1675 	subb	a,r4
   0D9A E5 0E              1676 	mov	a,(_errorService_sloc0_1_0 + 2)
   0D9C 9E                 1677 	subb	a,r6
   0D9D E5 0F              1678 	mov	a,(_errorService_sloc0_1_0 + 3)
   0D9F 64 80              1679 	xrl	a,#0x80
   0DA1 8F F0              1680 	mov	b,r7
   0DA3 63 F0 80           1681 	xrl	b,#0x80
   0DA6 95 F0              1682 	subb	a,b
   0DA8 50 05              1683 	jnc	00119$
                    0328   1684 	C$gait_designer.c$290$3$10 ==.
                           1685 ;	apps/gait_designer/gait_designer.c:290: U1CSR |= 0x40;
   0DAA 43 F8 40           1686 	orl	_U1CSR,#0x40
                    032B   1687 	C$gait_designer.c$291$3$10 ==.
                           1688 ;	apps/gait_designer/gait_designer.c:291: uartRxDisabled = 0;
   0DAD C2 00              1689 	clr	_uartRxDisabled
   0DAF                    1690 00119$:
                    032D   1691 	C$gait_designer.c$294$1$1 ==.
                    032D   1692 	XG$errorService$0$0 ==.
   0DAF 22                 1693 	ret
                           1694 ;------------------------------------------------------------
                           1695 ;Allocation info for local variables in function 'usbToUartService'
                           1696 ;------------------------------------------------------------
                    032E   1697 	G$usbToUartService$0$0 ==.
                    032E   1698 	C$gait_designer.c$323$1$1 ==.
                           1699 ;	apps/gait_designer/gait_designer.c:323: void usbToUartService()
                           1700 ;	-----------------------------------------
                           1701 ;	 function usbToUartService
                           1702 ;	-----------------------------------------
   0DB0                    1703 _usbToUartService:
                    032E   1704 	C$gait_designer.c$328$1$1 ==.
                           1705 ;	apps/gait_designer/gait_designer.c:328: while(usbComRxAvailable())// && uart1TxAvailable())
   0DB0                    1706 00101$:
   0DB0 12 1E B5           1707 	lcall	_usbComRxAvailable
   0DB3 E5 82              1708 	mov	a,dpl
   0DB5 60 05              1709 	jz	00103$
                    0335   1710 	C$gait_designer.c$330$2$2 ==.
                           1711 ;	apps/gait_designer/gait_designer.c:330: usbComRxReceiveByte();
   0DB7 12 1E DF           1712 	lcall	_usbComRxReceiveByte
   0DBA 80 F4              1713 	sjmp	00101$
   0DBC                    1714 00103$:
                    033A   1715 	C$gait_designer.c$338$1$1 ==.
                           1716 ;	apps/gait_designer/gait_designer.c:338: ioTxSignals(usbComRxControlSignals());
   0DBC 12 20 8E           1717 	lcall	_usbComRxControlSignals
   0DBF 12 0B C7           1718 	lcall	_ioTxSignals
                    0340   1719 	C$gait_designer.c$341$1$1 ==.
                           1720 ;	apps/gait_designer/gait_designer.c:341: signals = ioRxSignals();
   0DC2 12 0B 3D           1721 	lcall	_ioRxSignals
                    0343   1722 	C$gait_designer.c$342$1$1 ==.
                           1723 ;	apps/gait_designer/gait_designer.c:342: usbComTxControlSignals( ((signals & 1) ? 2 : 0) | ((signals & 2) ? 1 : 0));
   0DC5 E5 82              1724 	mov	a,dpl
   0DC7 FF                 1725 	mov	r7,a
   0DC8 30 E0 04           1726 	jnb	acc.0,00106$
   0DCB 7E 02              1727 	mov	r6,#0x02
   0DCD 80 02              1728 	sjmp	00107$
   0DCF                    1729 00106$:
   0DCF 7E 00              1730 	mov	r6,#0x00
   0DD1                    1731 00107$:
   0DD1 EF                 1732 	mov	a,r7
   0DD2 30 E1 04           1733 	jnb	acc.1,00108$
   0DD5 7F 01              1734 	mov	r7,#0x01
   0DD7 80 02              1735 	sjmp	00109$
   0DD9                    1736 00108$:
   0DD9 7F 00              1737 	mov	r7,#0x00
   0DDB                    1738 00109$:
   0DDB EF                 1739 	mov	a,r7
   0DDC 4E                 1740 	orl	a,r6
   0DDD F5 82              1741 	mov	dpl,a
   0DDF 12 20 94           1742 	lcall	_usbComTxControlSignals
                    0360   1743 	C$gait_designer.c$345$1$1 ==.
                    0360   1744 	XG$usbToUartService$0$0 ==.
   0DE2 22                 1745 	ret
                           1746 ;------------------------------------------------------------
                           1747 ;Allocation info for local variables in function 'gaitDesignerInit'
                           1748 ;------------------------------------------------------------
                           1749 ;sloc0                     Allocated with name '_gaitDesignerInit_sloc0_1_0'
                           1750 ;sloc1                     Allocated with name '_gaitDesignerInit_sloc1_1_0'
                           1751 ;------------------------------------------------------------
                    0361   1752 	G$gaitDesignerInit$0$0 ==.
                    0361   1753 	C$gait_designer.c$354$1$1 ==.
                           1754 ;	apps/gait_designer/gait_designer.c:354: void gaitDesignerInit(GAIT_DESIGNER* gait){
                           1755 ;	-----------------------------------------
                           1756 ;	 function gaitDesignerInit
                           1757 ;	-----------------------------------------
   0DE3                    1758 _gaitDesignerInit:
   0DE3 AF 82              1759 	mov	r7,dpl
   0DE5 AB 83              1760 	mov	r3,dph
   0DE7 AA F0              1761 	mov	r2,b
                    0367   1762 	C$gait_designer.c$357$1$1 ==.
                           1763 ;	apps/gait_designer/gait_designer.c:357: usbInit();
   0DE9 C0 07              1764 	push	ar7
   0DEB C0 03              1765 	push	ar3
   0DED C0 02              1766 	push	ar2
   0DEF 12 20 A8           1767 	lcall	_usbInit
   0DF2 D0 02              1768 	pop	ar2
   0DF4 D0 03              1769 	pop	ar3
   0DF6 D0 07              1770 	pop	ar7
                    0376   1771 	C$gait_designer.c$359$1$1 ==.
                           1772 ;	apps/gait_designer/gait_designer.c:359: if(gait->buffer == null){
   0DF8 74 05              1773 	mov	a,#0x05
   0DFA 2F                 1774 	add	a,r7
   0DFB F5 13              1775 	mov	_gaitDesignerInit_sloc1_1_0,a
   0DFD E4                 1776 	clr	a
   0DFE 3B                 1777 	addc	a,r3
   0DFF F5 14              1778 	mov	(_gaitDesignerInit_sloc1_1_0 + 1),a
   0E01 8A 15              1779 	mov	(_gaitDesignerInit_sloc1_1_0 + 2),r2
   0E03 85 13 82           1780 	mov	dpl,_gaitDesignerInit_sloc1_1_0
   0E06 85 14 83           1781 	mov	dph,(_gaitDesignerInit_sloc1_1_0 + 1)
   0E09 85 15 F0           1782 	mov	b,(_gaitDesignerInit_sloc1_1_0 + 2)
   0E0C 12 33 35           1783 	lcall	__gptrget
   0E0F F5 10              1784 	mov	_gaitDesignerInit_sloc0_1_0,a
   0E11 A3                 1785 	inc	dptr
   0E12 12 33 35           1786 	lcall	__gptrget
   0E15 F5 11              1787 	mov	(_gaitDesignerInit_sloc0_1_0 + 1),a
   0E17 A3                 1788 	inc	dptr
   0E18 12 33 35           1789 	lcall	__gptrget
   0E1B F5 12              1790 	mov	(_gaitDesignerInit_sloc0_1_0 + 2),a
   0E1D E5 10              1791 	mov	a,_gaitDesignerInit_sloc0_1_0
   0E1F 45 11              1792 	orl	a,(_gaitDesignerInit_sloc0_1_0 + 1)
   0E21 70 46              1793 	jnz	00102$
                    03A1   1794 	C$gait_designer.c$360$2$2 ==.
                           1795 ;	apps/gait_designer/gait_designer.c:360: gait->buffer = malloc(gait->num_actuators * 2 + 6); // Max is 2 bytes per actuator + some header/trailer
   0E23 8F 82              1796 	mov	dpl,r7
   0E25 8B 83              1797 	mov	dph,r3
   0E27 8A F0              1798 	mov	b,r2
   0E29 12 33 35           1799 	lcall	__gptrget
   0E2C 75 F0 02           1800 	mov	b,#0x02
   0E2F A4                 1801 	mul	ab
   0E30 24 06              1802 	add	a,#0x06
   0E32 FD                 1803 	mov	r5,a
   0E33 E4                 1804 	clr	a
   0E34 35 F0              1805 	addc	a,b
   0E36 FE                 1806 	mov	r6,a
   0E37 8D 82              1807 	mov	dpl,r5
   0E39 8E 83              1808 	mov	dph,r6
   0E3B C0 07              1809 	push	ar7
   0E3D C0 03              1810 	push	ar3
   0E3F C0 02              1811 	push	ar2
   0E41 12 2A A1           1812 	lcall	_malloc
   0E44 AD 82              1813 	mov	r5,dpl
   0E46 AE 83              1814 	mov	r6,dph
   0E48 D0 02              1815 	pop	ar2
   0E4A D0 03              1816 	pop	ar3
   0E4C D0 07              1817 	pop	ar7
   0E4E 8E 04              1818 	mov	ar4,r6
   0E50 7E 00              1819 	mov	r6,#0x00
   0E52 85 13 82           1820 	mov	dpl,_gaitDesignerInit_sloc1_1_0
   0E55 85 14 83           1821 	mov	dph,(_gaitDesignerInit_sloc1_1_0 + 1)
   0E58 85 15 F0           1822 	mov	b,(_gaitDesignerInit_sloc1_1_0 + 2)
   0E5B ED                 1823 	mov	a,r5
   0E5C 12 29 45           1824 	lcall	__gptrput
   0E5F A3                 1825 	inc	dptr
   0E60 EC                 1826 	mov	a,r4
   0E61 12 29 45           1827 	lcall	__gptrput
   0E64 A3                 1828 	inc	dptr
   0E65 EE                 1829 	mov	a,r6
   0E66 12 29 45           1830 	lcall	__gptrput
   0E69                    1831 00102$:
                    03E7   1832 	C$gait_designer.c$362$1$1 ==.
                           1833 ;	apps/gait_designer/gait_designer.c:362: gait->msgInx = 0;
   0E69 74 08              1834 	mov	a,#0x08
   0E6B 2F                 1835 	add	a,r7
   0E6C FC                 1836 	mov	r4,a
   0E6D E4                 1837 	clr	a
   0E6E 3B                 1838 	addc	a,r3
   0E6F FD                 1839 	mov	r5,a
   0E70 8A 06              1840 	mov	ar6,r2
   0E72 8C 82              1841 	mov	dpl,r4
   0E74 8D 83              1842 	mov	dph,r5
   0E76 8E F0              1843 	mov	b,r6
   0E78 E4                 1844 	clr	a
   0E79 12 29 45           1845 	lcall	__gptrput
                    03FA   1846 	C$gait_designer.c$363$1$1 ==.
                    03FA   1847 	XG$gaitDesignerInit$0$0 ==.
   0E7C 22                 1848 	ret
                           1849 ;------------------------------------------------------------
                           1850 ;Allocation info for local variables in function 'hexDigit'
                           1851 ;------------------------------------------------------------
                    03FB   1852 	Fgait_designer$hexDigit$0$0 ==.
                    03FB   1853 	C$gait_designer.c$365$1$1 ==.
                           1854 ;	apps/gait_designer/gait_designer.c:365: static int8 hexDigit(const uint8* buf, uint8 inx){
                           1855 ;	-----------------------------------------
                           1856 ;	 function hexDigit
                           1857 ;	-----------------------------------------
   0E7D                    1858 _hexDigit:
   0E7D AD 82              1859 	mov	r5,dpl
   0E7F AE 83              1860 	mov	r6,dph
   0E81 AF F0              1861 	mov	r7,b
                    0401   1862 	C$gait_designer.c$366$1$1 ==.
                           1863 ;	apps/gait_designer/gait_designer.c:366: uint8 rtn = buf[inx];
   0E83 78 48              1864 	mov	r0,#_hexDigit_PARM_2
   0E85 E2                 1865 	movx	a,@r0
   0E86 2D                 1866 	add	a,r5
   0E87 FD                 1867 	mov	r5,a
   0E88 E4                 1868 	clr	a
   0E89 3E                 1869 	addc	a,r6
   0E8A FE                 1870 	mov	r6,a
   0E8B 8D 82              1871 	mov	dpl,r5
   0E8D 8E 83              1872 	mov	dph,r6
   0E8F 8F F0              1873 	mov	b,r7
   0E91 12 33 35           1874 	lcall	__gptrget
   0E94 FF                 1875 	mov	r7,a
                    0413   1876 	C$gait_designer.c$367$1$1 ==.
                           1877 ;	apps/gait_designer/gait_designer.c:367: if(rtn>='A'){
   0E95 BF 41 00           1878 	cjne	r7,#0x41,00107$
   0E98                    1879 00107$:
   0E98 40 09              1880 	jc	00102$
                    0418   1881 	C$gait_designer.c$368$2$2 ==.
                           1882 ;	apps/gait_designer/gait_designer.c:368: rtn = rtn - 'A' + 10;
   0E9A 8F 06              1883 	mov	ar6,r7
   0E9C 74 C9              1884 	mov	a,#0xC9
   0E9E 2E                 1885 	add	a,r6
   0E9F FE                 1886 	mov	r6,a
   0EA0 FF                 1887 	mov	r7,a
   0EA1 80 03              1888 	sjmp	00103$
   0EA3                    1889 00102$:
                    0421   1890 	C$gait_designer.c$370$2$3 ==.
                           1891 ;	apps/gait_designer/gait_designer.c:370: rtn &= 15;
   0EA3 53 07 0F           1892 	anl	ar7,#0x0F
   0EA6                    1893 00103$:
                    0424   1894 	C$gait_designer.c$372$1$1 ==.
                           1895 ;	apps/gait_designer/gait_designer.c:372: return rtn;
   0EA6 8F 82              1896 	mov	dpl,r7
                    0426   1897 	C$gait_designer.c$373$1$1 ==.
                    0426   1898 	XFgait_designer$hexDigit$0$0 ==.
   0EA8 22                 1899 	ret
                           1900 ;------------------------------------------------------------
                           1901 ;Allocation info for local variables in function 'setSpeed'
                           1902 ;------------------------------------------------------------
                    0427   1903 	Fgait_designer$setSpeed$0$0 ==.
                    0427   1904 	C$gait_designer.c$375$1$1 ==.
                           1905 ;	apps/gait_designer/gait_designer.c:375: static void setSpeed(const GAIT_DESIGNER* gait, uint8 servo, int8 percent){
                           1906 ;	-----------------------------------------
                           1907 ;	 function setSpeed
                           1908 ;	-----------------------------------------
   0EA9                    1909 _setSpeed:
                    0427   1910 	C$gait_designer.c$378$1$1 ==.
                           1911 ;	apps/gait_designer/gait_designer.c:378: int8 speed = temp / 100;
                    0427   1912 	C$gait_designer.c$381$1$1 ==.
                    0427   1913 	XFgait_designer$setSpeed$0$0 ==.
   0EA9 22                 1914 	ret
                           1915 ;------------------------------------------------------------
                           1916 ;Allocation info for local variables in function 'gaitDesignerProcess'
                           1917 ;------------------------------------------------------------
                           1918 ;sloc0                     Allocated with name '_gaitDesignerProcess_sloc0_1_0'
                           1919 ;sloc1                     Allocated with name '_gaitDesignerProcess_sloc1_1_0'
                           1920 ;------------------------------------------------------------
                    0428   1921 	G$gaitDesignerProcess$0$0 ==.
                    0428   1922 	C$gait_designer.c$384$1$1 ==.
                           1923 ;	apps/gait_designer/gait_designer.c:384: void gaitDesignerProcess(GAIT_DESIGNER* gait){
                           1924 ;	-----------------------------------------
                           1925 ;	 function gaitDesignerProcess
                           1926 ;	-----------------------------------------
   0EAA                    1927 _gaitDesignerProcess:
   0EAA AF F0              1928 	mov	r7,b
   0EAC AE 83              1929 	mov	r6,dph
   0EAE E5 82              1930 	mov	a,dpl
   0EB0 78 4B              1931 	mov	r0,#_gaitDesignerProcess_gait_1_1
   0EB2 F2                 1932 	movx	@r0,a
   0EB3 08                 1933 	inc	r0
   0EB4 EE                 1934 	mov	a,r6
   0EB5 F2                 1935 	movx	@r0,a
   0EB6 08                 1936 	inc	r0
   0EB7 EF                 1937 	mov	a,r7
   0EB8 F2                 1938 	movx	@r0,a
                    0437   1939 	C$gait_designer.c$389$1$1 ==.
                           1940 ;	apps/gait_designer/gait_designer.c:389: int b = uart1RxReceiveByte();
   0EB9 12 16 57           1941 	lcall	_uart1RxReceiveByte
   0EBC AC 82              1942 	mov	r4,dpl
   0EBE 78 52              1943 	mov	r0,#_gaitDesignerProcess_b_1_1
   0EC0 EC                 1944 	mov	a,r4
   0EC1 F2                 1945 	movx	@r0,a
   0EC2 08                 1946 	inc	r0
   0EC3 E4                 1947 	clr	a
   0EC4 F2                 1948 	movx	@r0,a
                    0443   1949 	C$gait_designer.c$390$1$1 ==.
                           1950 ;	apps/gait_designer/gait_designer.c:390: if(b==-1) return;	// No characters at all
   0EC5 78 52              1951 	mov	r0,#_gaitDesignerProcess_b_1_1
   0EC7 E2                 1952 	movx	a,@r0
   0EC8 B4 FF 07           1953 	cjne	a,#0xFF,00166$
   0ECB 08                 1954 	inc	r0
   0ECC E2                 1955 	movx	a,@r0
   0ECD B4 FF 02           1956 	cjne	a,#0xFF,00166$
   0ED0 80 02              1957 	sjmp	00167$
   0ED2                    1958 00166$:
   0ED2 80 03              1959 	sjmp	00102$
   0ED4                    1960 00167$:
   0ED4 02 11 B5           1961 	ljmp	00140$
   0ED7                    1962 00102$:
                    0455   1963 	C$gait_designer.c$392$1$1 ==.
                           1964 ;	apps/gait_designer/gait_designer.c:392: inx = gait->msgInx;
   0ED7 78 4B              1965 	mov	r0,#_gaitDesignerProcess_gait_1_1
   0ED9 E2                 1966 	movx	a,@r0
   0EDA 24 08              1967 	add	a,#0x08
   0EDC F5 17              1968 	mov	_gaitDesignerProcess_sloc1_1_0,a
   0EDE 08                 1969 	inc	r0
   0EDF E2                 1970 	movx	a,@r0
   0EE0 34 00              1971 	addc	a,#0x00
   0EE2 F5 18              1972 	mov	(_gaitDesignerProcess_sloc1_1_0 + 1),a
   0EE4 08                 1973 	inc	r0
   0EE5 E2                 1974 	movx	a,@r0
   0EE6 F5 19              1975 	mov	(_gaitDesignerProcess_sloc1_1_0 + 2),a
   0EE8 85 17 82           1976 	mov	dpl,_gaitDesignerProcess_sloc1_1_0
   0EEB 85 18 83           1977 	mov	dph,(_gaitDesignerProcess_sloc1_1_0 + 1)
   0EEE 85 19 F0           1978 	mov	b,(_gaitDesignerProcess_sloc1_1_0 + 2)
   0EF1 78 4E              1979 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0EF3 12 33 35           1980 	lcall	__gptrget
   0EF6 F2                 1981 	movx	@r0,a
                    0475   1982 	C$gait_designer.c$393$1$1 ==.
                           1983 ;	apps/gait_designer/gait_designer.c:393: buffer = gait->buffer;
   0EF7 78 4B              1984 	mov	r0,#_gaitDesignerProcess_gait_1_1
   0EF9 E2                 1985 	movx	a,@r0
   0EFA 24 05              1986 	add	a,#0x05
   0EFC FD                 1987 	mov	r5,a
   0EFD 08                 1988 	inc	r0
   0EFE E2                 1989 	movx	a,@r0
   0EFF 34 00              1990 	addc	a,#0x00
   0F01 FE                 1991 	mov	r6,a
   0F02 08                 1992 	inc	r0
   0F03 E2                 1993 	movx	a,@r0
   0F04 FF                 1994 	mov	r7,a
   0F05 8D 82              1995 	mov	dpl,r5
   0F07 8E 83              1996 	mov	dph,r6
   0F09 8F F0              1997 	mov	b,r7
   0F0B 78 4F              1998 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   0F0D 12 33 35           1999 	lcall	__gptrget
   0F10 F2                 2000 	movx	@r0,a
   0F11 A3                 2001 	inc	dptr
   0F12 12 33 35           2002 	lcall	__gptrget
   0F15 08                 2003 	inc	r0
   0F16 F2                 2004 	movx	@r0,a
   0F17 A3                 2005 	inc	dptr
   0F18 12 33 35           2006 	lcall	__gptrget
   0F1B 08                 2007 	inc	r0
   0F1C F2                 2008 	movx	@r0,a
                    049B   2009 	C$gait_designer.c$399$1$1 ==.
                           2010 ;	apps/gait_designer/gait_designer.c:399: while(b!=-1){
   0F1D                    2011 00132$:
   0F1D 78 52              2012 	mov	r0,#_gaitDesignerProcess_b_1_1
   0F1F E2                 2013 	movx	a,@r0
   0F20 B4 FF 08           2014 	cjne	a,#0xFF,00168$
   0F23 08                 2015 	inc	r0
   0F24 E2                 2016 	movx	a,@r0
   0F25 B4 FF 03           2017 	cjne	a,#0xFF,00168$
   0F28 02 11 A6           2018 	ljmp	00134$
   0F2B                    2019 00168$:
                    04A9   2020 	C$gait_designer.c$403$1$1 ==.
                           2021 ;	apps/gait_designer/gait_designer.c:403: uint8 c = b & 0xff;;
   0F2B 78 52              2022 	mov	r0,#_gaitDesignerProcess_b_1_1
   0F2D E2                 2023 	movx	a,@r0
   0F2E 54 FF              2024 	anl	a,#0xFF
   0F30 FB                 2025 	mov	r3,a
   0F31 08                 2026 	inc	r0
   0F32 E2                 2027 	movx	a,@r0
   0F33 54 00              2028 	anl	a,#0x00
   0F35 FC                 2029 	mov	r4,a
                    04B4   2030 	C$gait_designer.c$405$2$2 ==.
                           2031 ;	apps/gait_designer/gait_designer.c:405: if(c == '\r'){
   0F36 BB 0D 03           2032 	cjne	r3,#0x0D,00169$
   0F39 02 11 97           2033 	ljmp	00131$
   0F3C                    2034 00169$:
                    04BA   2035 	C$gait_designer.c$407$2$2 ==.
                           2036 ;	apps/gait_designer/gait_designer.c:407: }else if(c=='\n'){
   0F3C BB 0A 02           2037 	cjne	r3,#0x0A,00170$
   0F3F 80 03              2038 	sjmp	00171$
   0F41                    2039 00170$:
   0F41 02 11 6A           2040 	ljmp	00127$
   0F44                    2041 00171$:
                    04C2   2042 	C$gait_designer.c$408$1$1 ==.
                           2043 ;	apps/gait_designer/gait_designer.c:408: buffer[inx] = '\0';
   0F44 78 4F              2044 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   0F46 79 4E              2045 	mov	r1,#_gaitDesignerProcess_inx_1_1
   0F48 E3                 2046 	movx	a,@r1
   0F49 C5 F0              2047 	xch	a,b
   0F4B E2                 2048 	movx	a,@r0
   0F4C 25 F0              2049 	add	a,b
   0F4E FA                 2050 	mov	r2,a
   0F4F 08                 2051 	inc	r0
   0F50 E2                 2052 	movx	a,@r0
   0F51 34 00              2053 	addc	a,#0x00
   0F53 FB                 2054 	mov	r3,a
   0F54 08                 2055 	inc	r0
   0F55 E2                 2056 	movx	a,@r0
   0F56 FC                 2057 	mov	r4,a
   0F57 8A 82              2058 	mov	dpl,r2
   0F59 8B 83              2059 	mov	dph,r3
   0F5B 8C F0              2060 	mov	b,r4
   0F5D E4                 2061 	clr	a
   0F5E 12 29 45           2062 	lcall	__gptrput
                    04DF   2063 	C$gait_designer.c$410$3$4 ==.
                           2064 ;	apps/gait_designer/gait_designer.c:410: if(buffer[0]=='G' && inx>=3 && inx%2 ==1){
   0F61 78 4F              2065 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   0F63 E2                 2066 	movx	a,@r0
   0F64 F5 82              2067 	mov	dpl,a
   0F66 08                 2068 	inc	r0
   0F67 E2                 2069 	movx	a,@r0
   0F68 F5 83              2070 	mov	dph,a
   0F6A 08                 2071 	inc	r0
   0F6B E2                 2072 	movx	a,@r0
   0F6C F5 F0              2073 	mov	b,a
   0F6E 12 33 35           2074 	lcall	__gptrget
   0F71 FC                 2075 	mov	r4,a
   0F72 BC 47 02           2076 	cjne	r4,#0x47,00172$
   0F75 80 03              2077 	sjmp	00173$
   0F77                    2078 00172$:
   0F77 02 10 45           2079 	ljmp	00119$
   0F7A                    2080 00173$:
   0F7A 78 4E              2081 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0F7C E2                 2082 	movx	a,@r0
   0F7D B4 03 00           2083 	cjne	a,#0x03,00174$
   0F80                    2084 00174$:
   0F80 50 03              2085 	jnc	00175$
   0F82 02 10 45           2086 	ljmp	00119$
   0F85                    2087 00175$:
   0F85 78 4E              2088 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0F87 E2                 2089 	movx	a,@r0
   0F88 54 01              2090 	anl	a,#0x01
   0F8A FC                 2091 	mov	r4,a
   0F8B BC 01 02           2092 	cjne	r4,#0x01,00176$
   0F8E 80 03              2093 	sjmp	00177$
   0F90                    2094 00176$:
   0F90 02 10 45           2095 	ljmp	00119$
   0F93                    2096 00177$:
                    0511   2097 	C$gait_designer.c$412$4$5 ==.
                           2098 ;	apps/gait_designer/gait_designer.c:412: inx=0;
   0F93 78 4E              2099 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0F95 E4                 2100 	clr	a
   0F96 F2                 2101 	movx	@r0,a
                    0515   2102 	C$gait_designer.c$413$1$1 ==.
                           2103 ;	apps/gait_designer/gait_designer.c:413: for(servo=0; servo < gait->num_actuators && buffer[inx+1];servo++){
   0F97 7F 00              2104 	mov	r7,#0x00
   0F99                    2105 00136$:
   0F99 78 4B              2106 	mov	r0,#_gaitDesignerProcess_gait_1_1
   0F9B E2                 2107 	movx	a,@r0
   0F9C F5 82              2108 	mov	dpl,a
   0F9E 08                 2109 	inc	r0
   0F9F E2                 2110 	movx	a,@r0
   0FA0 F5 83              2111 	mov	dph,a
   0FA2 08                 2112 	inc	r0
   0FA3 E2                 2113 	movx	a,@r0
   0FA4 F5 F0              2114 	mov	b,a
   0FA6 12 33 35           2115 	lcall	__gptrget
   0FA9 FE                 2116 	mov	r6,a
   0FAA C3                 2117 	clr	c
   0FAB EF                 2118 	mov	a,r7
   0FAC 9E                 2119 	subb	a,r6
   0FAD 40 03              2120 	jc	00178$
   0FAF 02 11 64           2121 	ljmp	00120$
   0FB2                    2122 00178$:
   0FB2 78 4E              2123 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0FB4 E2                 2124 	movx	a,@r0
   0FB5 FD                 2125 	mov	r5,a
   0FB6 7E 00              2126 	mov	r6,#0x00
   0FB8 0D                 2127 	inc	r5
   0FB9 BD 00 01           2128 	cjne	r5,#0x00,00179$
   0FBC 0E                 2129 	inc	r6
   0FBD                    2130 00179$:
   0FBD 78 4F              2131 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   0FBF E2                 2132 	movx	a,@r0
   0FC0 2D                 2133 	add	a,r5
   0FC1 FD                 2134 	mov	r5,a
   0FC2 08                 2135 	inc	r0
   0FC3 E2                 2136 	movx	a,@r0
   0FC4 3E                 2137 	addc	a,r6
   0FC5 FC                 2138 	mov	r4,a
   0FC6 08                 2139 	inc	r0
   0FC7 E2                 2140 	movx	a,@r0
   0FC8 FE                 2141 	mov	r6,a
   0FC9 8D 82              2142 	mov	dpl,r5
   0FCB 8C 83              2143 	mov	dph,r4
   0FCD 8E F0              2144 	mov	b,r6
   0FCF 12 33 35           2145 	lcall	__gptrget
   0FD2 70 03              2146 	jnz	00180$
   0FD4 02 11 64           2147 	ljmp	00120$
   0FD7                    2148 00180$:
                    0555   2149 	C$gait_designer.c$415$5$6 ==.
                           2150 ;	apps/gait_designer/gait_designer.c:415: inx++;
   0FD7 78 4E              2151 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0FD9 E2                 2152 	movx	a,@r0
   0FDA 24 01              2153 	add	a,#0x01
   0FDC F2                 2154 	movx	@r0,a
                    055B   2155 	C$gait_designer.c$416$5$6 ==.
                           2156 ;	apps/gait_designer/gait_designer.c:416: percent = (hexDigit(buffer,inx) << 4);
   0FDD 78 4E              2157 	mov	r0,#_gaitDesignerProcess_inx_1_1
   0FDF 79 48              2158 	mov	r1,#_hexDigit_PARM_2
   0FE1 E2                 2159 	movx	a,@r0
   0FE2 F3                 2160 	movx	@r1,a
   0FE3 78 4F              2161 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   0FE5 E2                 2162 	movx	a,@r0
   0FE6 F5 82              2163 	mov	dpl,a
   0FE8 08                 2164 	inc	r0
   0FE9 E2                 2165 	movx	a,@r0
   0FEA F5 83              2166 	mov	dph,a
   0FEC 08                 2167 	inc	r0
   0FED E2                 2168 	movx	a,@r0
   0FEE F5 F0              2169 	mov	b,a
   0FF0 C0 07              2170 	push	ar7
   0FF2 12 0E 7D           2171 	lcall	_hexDigit
   0FF5 AE 82              2172 	mov	r6,dpl
   0FF7 78 54              2173 	mov	r0,#_gaitDesignerProcess_percent_5_6
   0FF9 EE                 2174 	mov	a,r6
   0FFA C4                 2175 	swap	a
   0FFB 54 F0              2176 	anl	a,#0xF0
   0FFD F2                 2177 	movx	@r0,a
                    057C   2178 	C$gait_designer.c$417$5$6 ==.
                           2179 ;	apps/gait_designer/gait_designer.c:417: inx++;
   0FFE 78 4E              2180 	mov	r0,#_gaitDesignerProcess_inx_1_1
   1000 E2                 2181 	movx	a,@r0
   1001 24 01              2182 	add	a,#0x01
   1003 F2                 2183 	movx	@r0,a
                    0582   2184 	C$gait_designer.c$418$5$6 ==.
                           2185 ;	apps/gait_designer/gait_designer.c:418: percent |= hexDigit(buffer,inx);
   1004 78 4E              2186 	mov	r0,#_gaitDesignerProcess_inx_1_1
   1006 79 48              2187 	mov	r1,#_hexDigit_PARM_2
   1008 E2                 2188 	movx	a,@r0
   1009 F3                 2189 	movx	@r1,a
   100A 78 4F              2190 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   100C E2                 2191 	movx	a,@r0
   100D F5 82              2192 	mov	dpl,a
   100F 08                 2193 	inc	r0
   1010 E2                 2194 	movx	a,@r0
   1011 F5 83              2195 	mov	dph,a
   1013 08                 2196 	inc	r0
   1014 E2                 2197 	movx	a,@r0
   1015 F5 F0              2198 	mov	b,a
   1017 12 0E 7D           2199 	lcall	_hexDigit
   101A AE 82              2200 	mov	r6,dpl
   101C D0 07              2201 	pop	ar7
   101E 78 54              2202 	mov	r0,#_gaitDesignerProcess_percent_5_6
   1020 E2                 2203 	movx	a,@r0
   1021 4E                 2204 	orl	a,r6
   1022 F2                 2205 	movx	@r0,a
                    05A1   2206 	C$gait_designer.c$419$5$6 ==.
                           2207 ;	apps/gait_designer/gait_designer.c:419: setSpeed(gait,servo,percent);
   1023 78 49              2208 	mov	r0,#_setSpeed_PARM_2
   1025 EF                 2209 	mov	a,r7
   1026 F2                 2210 	movx	@r0,a
   1027 78 54              2211 	mov	r0,#_gaitDesignerProcess_percent_5_6
   1029 79 4A              2212 	mov	r1,#_setSpeed_PARM_3
   102B E2                 2213 	movx	a,@r0
   102C F3                 2214 	movx	@r1,a
   102D 78 4B              2215 	mov	r0,#_gaitDesignerProcess_gait_1_1
   102F E2                 2216 	movx	a,@r0
   1030 F5 82              2217 	mov	dpl,a
   1032 08                 2218 	inc	r0
   1033 E2                 2219 	movx	a,@r0
   1034 F5 83              2220 	mov	dph,a
   1036 08                 2221 	inc	r0
   1037 E2                 2222 	movx	a,@r0
   1038 F5 F0              2223 	mov	b,a
   103A C0 07              2224 	push	ar7
   103C 12 0E A9           2225 	lcall	_setSpeed
   103F D0 07              2226 	pop	ar7
                    05BF   2227 	C$gait_designer.c$413$4$5 ==.
                           2228 ;	apps/gait_designer/gait_designer.c:413: for(servo=0; servo < gait->num_actuators && buffer[inx+1];servo++){
   1041 0F                 2229 	inc	r7
   1042 02 0F 99           2230 	ljmp	00136$
   1045                    2231 00119$:
                    05C3   2232 	C$gait_designer.c$436$3$4 ==.
                           2233 ;	apps/gait_designer/gait_designer.c:436: }else if(buffer[0]=='S'){
   1045 78 4F              2234 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   1047 E2                 2235 	movx	a,@r0
   1048 F5 82              2236 	mov	dpl,a
   104A 08                 2237 	inc	r0
   104B E2                 2238 	movx	a,@r0
   104C F5 83              2239 	mov	dph,a
   104E 08                 2240 	inc	r0
   104F E2                 2241 	movx	a,@r0
   1050 F5 F0              2242 	mov	b,a
   1052 12 33 35           2243 	lcall	__gptrget
   1055 FF                 2244 	mov	r7,a
   1056 BF 53 02           2245 	cjne	r7,#0x53,00181$
   1059 80 03              2246 	sjmp	00182$
   105B                    2247 00181$:
   105B 02 11 64           2248 	ljmp	00120$
   105E                    2249 00182$:
                    05DC   2250 	C$gait_designer.c$438$4$4 ==.
                           2251 ;	apps/gait_designer/gait_designer.c:438: boolean neg = FALSE;
   105E 7F 00              2252 	mov	r7,#0x00
                    05DE   2253 	C$gait_designer.c$439$4$7 ==.
                           2254 ;	apps/gait_designer/gait_designer.c:439: servo=0;
   1060 7E 00              2255 	mov	r6,#0x00
                    05E0   2256 	C$gait_designer.c$442$1$1 ==.
                           2257 ;	apps/gait_designer/gait_designer.c:442: while(buffer[inx]>='0' && buffer[inx]<='9'){
   1062 7D 01              2258 	mov	r5,#0x01
   1064                    2259 00104$:
   1064 78 4F              2260 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   1066 E2                 2261 	movx	a,@r0
   1067 2D                 2262 	add	a,r5
   1068 FA                 2263 	mov	r2,a
   1069 08                 2264 	inc	r0
   106A E2                 2265 	movx	a,@r0
   106B 34 00              2266 	addc	a,#0x00
   106D FB                 2267 	mov	r3,a
   106E 08                 2268 	inc	r0
   106F E2                 2269 	movx	a,@r0
   1070 FC                 2270 	mov	r4,a
   1071 8A 82              2271 	mov	dpl,r2
   1073 8B 83              2272 	mov	dph,r3
   1075 8C F0              2273 	mov	b,r4
   1077 12 33 35           2274 	lcall	__gptrget
   107A F5 16              2275 	mov	_gaitDesignerProcess_sloc0_1_0,a
   107C C3                 2276 	clr	c
   107D 94 30              2277 	subb	a,#0x30
   107F 40 2C              2278 	jc	00106$
   1081 E5 16              2279 	mov	a,_gaitDesignerProcess_sloc0_1_0
   1083 24 C6              2280 	add	a,#0xff - 0x39
   1085 40 26              2281 	jc	00106$
                    0605   2282 	C$gait_designer.c$443$1$1 ==.
                           2283 ;	apps/gait_designer/gait_designer.c:443: servo*=10;
   1087 EE                 2284 	mov	a,r6
   1088 75 F0 0A           2285 	mov	b,#0x0A
   108B A4                 2286 	mul	ab
   108C FE                 2287 	mov	r6,a
                    060B   2288 	C$gait_designer.c$444$5$8 ==.
                           2289 ;	apps/gait_designer/gait_designer.c:444: servo+= (buffer[inx++] & 15);
   108D 8D 04              2290 	mov	ar4,r5
   108F 0D                 2291 	inc	r5
   1090 78 4F              2292 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   1092 E2                 2293 	movx	a,@r0
   1093 2C                 2294 	add	a,r4
   1094 FC                 2295 	mov	r4,a
   1095 08                 2296 	inc	r0
   1096 E2                 2297 	movx	a,@r0
   1097 34 00              2298 	addc	a,#0x00
   1099 FB                 2299 	mov	r3,a
   109A 08                 2300 	inc	r0
   109B E2                 2301 	movx	a,@r0
   109C FA                 2302 	mov	r2,a
   109D 8C 82              2303 	mov	dpl,r4
   109F 8B 83              2304 	mov	dph,r3
   10A1 8A F0              2305 	mov	b,r2
   10A3 12 33 35           2306 	lcall	__gptrget
   10A6 54 0F              2307 	anl	a,#0x0F
   10A8 FC                 2308 	mov	r4,a
   10A9 2E                 2309 	add	a,r6
   10AA FE                 2310 	mov	r6,a
   10AB 80 B7              2311 	sjmp	00104$
   10AD                    2312 00106$:
                    062B   2313 	C$gait_designer.c$446$1$1 ==.
                           2314 ;	apps/gait_designer/gait_designer.c:446: if(buffer[inx++]==','){
   10AD 78 4E              2315 	mov	r0,#_gaitDesignerProcess_inx_1_1
   10AF ED                 2316 	mov	a,r5
   10B0 04                 2317 	inc	a
   10B1 F2                 2318 	movx	@r0,a
   10B2 78 4F              2319 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   10B4 E2                 2320 	movx	a,@r0
   10B5 2D                 2321 	add	a,r5
   10B6 FB                 2322 	mov	r3,a
   10B7 08                 2323 	inc	r0
   10B8 E2                 2324 	movx	a,@r0
   10B9 34 00              2325 	addc	a,#0x00
   10BB FC                 2326 	mov	r4,a
   10BC 08                 2327 	inc	r0
   10BD E2                 2328 	movx	a,@r0
   10BE FD                 2329 	mov	r5,a
   10BF 8B 82              2330 	mov	dpl,r3
   10C1 8C 83              2331 	mov	dph,r4
   10C3 8D F0              2332 	mov	b,r5
   10C5 12 33 35           2333 	lcall	__gptrget
   10C8 FB                 2334 	mov	r3,a
   10C9 BB 2C 02           2335 	cjne	r3,#0x2C,00185$
   10CC 80 03              2336 	sjmp	00186$
   10CE                    2337 00185$:
   10CE 02 11 64           2338 	ljmp	00120$
   10D1                    2339 00186$:
                    064F   2340 	C$gait_designer.c$447$1$1 ==.
                           2341 ;	apps/gait_designer/gait_designer.c:447: if(buffer[inx]=='-'){
   10D1 78 4F              2342 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   10D3 79 4E              2343 	mov	r1,#_gaitDesignerProcess_inx_1_1
   10D5 E3                 2344 	movx	a,@r1
   10D6 C5 F0              2345 	xch	a,b
   10D8 E2                 2346 	movx	a,@r0
   10D9 25 F0              2347 	add	a,b
   10DB FB                 2348 	mov	r3,a
   10DC 08                 2349 	inc	r0
   10DD E2                 2350 	movx	a,@r0
   10DE 34 00              2351 	addc	a,#0x00
   10E0 FC                 2352 	mov	r4,a
   10E1 08                 2353 	inc	r0
   10E2 E2                 2354 	movx	a,@r0
   10E3 FD                 2355 	mov	r5,a
   10E4 8B 82              2356 	mov	dpl,r3
   10E6 8C 83              2357 	mov	dph,r4
   10E8 8D F0              2358 	mov	b,r5
   10EA 12 33 35           2359 	lcall	__gptrget
   10ED FB                 2360 	mov	r3,a
   10EE BB 2D 08           2361 	cjne	r3,#0x2D,00159$
                    066F   2362 	C$gait_designer.c$448$6$10 ==.
                           2363 ;	apps/gait_designer/gait_designer.c:448: inx++;
   10F1 78 4E              2364 	mov	r0,#_gaitDesignerProcess_inx_1_1
   10F3 E2                 2365 	movx	a,@r0
   10F4 24 01              2366 	add	a,#0x01
   10F6 F2                 2367 	movx	@r0,a
                    0675   2368 	C$gait_designer.c$449$6$10 ==.
                           2369 ;	apps/gait_designer/gait_designer.c:449: neg=TRUE;
   10F7 7F 01              2370 	mov	r7,#0x01
                    0677   2371 	C$gait_designer.c$451$1$1 ==.
                           2372 ;	apps/gait_designer/gait_designer.c:451: while(buffer[inx]){
   10F9                    2373 00159$:
   10F9 78 4E              2374 	mov	r0,#_gaitDesignerProcess_inx_1_1
   10FB E2                 2375 	movx	a,@r0
   10FC FD                 2376 	mov	r5,a
   10FD                    2377 00109$:
   10FD 78 4F              2378 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   10FF E2                 2379 	movx	a,@r0
   1100 2D                 2380 	add	a,r5
   1101 FA                 2381 	mov	r2,a
   1102 08                 2382 	inc	r0
   1103 E2                 2383 	movx	a,@r0
   1104 34 00              2384 	addc	a,#0x00
   1106 FB                 2385 	mov	r3,a
   1107 08                 2386 	inc	r0
   1108 E2                 2387 	movx	a,@r0
   1109 FC                 2388 	mov	r4,a
   110A 8A 82              2389 	mov	dpl,r2
   110C 8B 83              2390 	mov	dph,r3
   110E 8C F0              2391 	mov	b,r4
   1110 12 33 35           2392 	lcall	__gptrget
   1113 60 2C              2393 	jz	00111$
                    0693   2394 	C$gait_designer.c$452$1$1 ==.
                           2395 ;	apps/gait_designer/gait_designer.c:452: percent*=10;
   1115 78 54              2396 	mov	r0,#_gaitDesignerProcess_percent_5_6
   1117 E2                 2397 	movx	a,@r0
   1118 75 F0 0A           2398 	mov	b,#0x0A
   111B A4                 2399 	mul	ab
   111C F2                 2400 	movx	@r0,a
                    069B   2401 	C$gait_designer.c$453$6$11 ==.
                           2402 ;	apps/gait_designer/gait_designer.c:453: percent += (buffer[inx++] & 15);
   111D 8D 04              2403 	mov	ar4,r5
   111F 0D                 2404 	inc	r5
   1120 78 4F              2405 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   1122 E2                 2406 	movx	a,@r0
   1123 2C                 2407 	add	a,r4
   1124 FC                 2408 	mov	r4,a
   1125 08                 2409 	inc	r0
   1126 E2                 2410 	movx	a,@r0
   1127 34 00              2411 	addc	a,#0x00
   1129 FB                 2412 	mov	r3,a
   112A 08                 2413 	inc	r0
   112B E2                 2414 	movx	a,@r0
   112C FA                 2415 	mov	r2,a
   112D 8C 82              2416 	mov	dpl,r4
   112F 8B 83              2417 	mov	dph,r3
   1131 8A F0              2418 	mov	b,r2
   1133 12 33 35           2419 	lcall	__gptrget
   1136 FC                 2420 	mov	r4,a
   1137 53 04 0F           2421 	anl	ar4,#0x0F
   113A 78 54              2422 	mov	r0,#_gaitDesignerProcess_percent_5_6
   113C E2                 2423 	movx	a,@r0
   113D 2C                 2424 	add	a,r4
   113E F2                 2425 	movx	@r0,a
   113F 80 BC              2426 	sjmp	00109$
   1141                    2427 00111$:
                    06BF   2428 	C$gait_designer.c$455$5$9 ==.
                           2429 ;	apps/gait_designer/gait_designer.c:455: if(neg){
   1141 EF                 2430 	mov	a,r7
   1142 60 08              2431 	jz	00113$
                    06C2   2432 	C$gait_designer.c$456$6$12 ==.
                           2433 ;	apps/gait_designer/gait_designer.c:456: percent *= -1;
   1144 78 54              2434 	mov	r0,#_gaitDesignerProcess_percent_5_6
   1146 E2                 2435 	movx	a,@r0
   1147 D3                 2436 	setb	c
   1148 F4                 2437 	cpl	a
   1149 34 00              2438 	addc	a,#0x00
   114B F2                 2439 	movx	@r0,a
   114C                    2440 00113$:
                    06CA   2441 	C$gait_designer.c$458$5$9 ==.
                           2442 ;	apps/gait_designer/gait_designer.c:458: setSpeed(gait,servo,percent);
   114C 78 49              2443 	mov	r0,#_setSpeed_PARM_2
   114E EE                 2444 	mov	a,r6
   114F F2                 2445 	movx	@r0,a
   1150 78 4A              2446 	mov	r0,#_setSpeed_PARM_3
   1152 E4                 2447 	clr	a
   1153 F2                 2448 	movx	@r0,a
   1154 78 4B              2449 	mov	r0,#_gaitDesignerProcess_gait_1_1
   1156 E2                 2450 	movx	a,@r0
   1157 F5 82              2451 	mov	dpl,a
   1159 08                 2452 	inc	r0
   115A E2                 2453 	movx	a,@r0
   115B F5 83              2454 	mov	dph,a
   115D 08                 2455 	inc	r0
   115E E2                 2456 	movx	a,@r0
   115F F5 F0              2457 	mov	b,a
   1161 12 0E A9           2458 	lcall	_setSpeed
   1164                    2459 00120$:
                    06E2   2460 	C$gait_designer.c$461$3$4 ==.
                           2461 ;	apps/gait_designer/gait_designer.c:461: inx=0;
   1164 78 4E              2462 	mov	r0,#_gaitDesignerProcess_inx_1_1
   1166 E4                 2463 	clr	a
   1167 F2                 2464 	movx	@r0,a
   1168 80 2D              2465 	sjmp	00131$
   116A                    2466 00127$:
                    06E8   2467 	C$gait_designer.c$462$2$2 ==.
                           2468 ;	apps/gait_designer/gait_designer.c:462: }else if (c=='#'){
   116A BB 23 06           2469 	cjne	r3,#0x23,00124$
                    06EB   2470 	C$gait_designer.c$463$3$13 ==.
                           2471 ;	apps/gait_designer/gait_designer.c:463: inx = 0;
   116D 78 4E              2472 	mov	r0,#_gaitDesignerProcess_inx_1_1
   116F E4                 2473 	clr	a
   1170 F2                 2474 	movx	@r0,a
   1171 80 24              2475 	sjmp	00131$
   1173                    2476 00124$:
                    06F1   2477 	C$gait_designer.c$465$3$14 ==.
                           2478 ;	apps/gait_designer/gait_designer.c:465: buffer[inx++] = b;
   1173 78 4E              2479 	mov	r0,#_gaitDesignerProcess_inx_1_1
   1175 E2                 2480 	movx	a,@r0
   1176 FF                 2481 	mov	r7,a
   1177 78 4E              2482 	mov	r0,#_gaitDesignerProcess_inx_1_1
   1179 E2                 2483 	movx	a,@r0
   117A 24 01              2484 	add	a,#0x01
   117C F2                 2485 	movx	@r0,a
   117D 78 4F              2486 	mov	r0,#_gaitDesignerProcess_buffer_1_1
   117F E2                 2487 	movx	a,@r0
   1180 2F                 2488 	add	a,r7
   1181 FF                 2489 	mov	r7,a
   1182 08                 2490 	inc	r0
   1183 E2                 2491 	movx	a,@r0
   1184 34 00              2492 	addc	a,#0x00
   1186 FE                 2493 	mov	r6,a
   1187 08                 2494 	inc	r0
   1188 E2                 2495 	movx	a,@r0
   1189 FD                 2496 	mov	r5,a
   118A 78 52              2497 	mov	r0,#_gaitDesignerProcess_b_1_1
   118C E2                 2498 	movx	a,@r0
   118D FC                 2499 	mov	r4,a
   118E 8F 82              2500 	mov	dpl,r7
   1190 8E 83              2501 	mov	dph,r6
   1192 8D F0              2502 	mov	b,r5
   1194 12 29 45           2503 	lcall	__gptrput
   1197                    2504 00131$:
                    0715   2505 	C$gait_designer.c$467$2$2 ==.
                           2506 ;	apps/gait_designer/gait_designer.c:467: b = usbComRxReceiveByte();
   1197 12 1E DF           2507 	lcall	_usbComRxReceiveByte
   119A AF 82              2508 	mov	r7,dpl
   119C 78 52              2509 	mov	r0,#_gaitDesignerProcess_b_1_1
   119E EF                 2510 	mov	a,r7
   119F F2                 2511 	movx	@r0,a
   11A0 08                 2512 	inc	r0
   11A1 E4                 2513 	clr	a
   11A2 F2                 2514 	movx	@r0,a
   11A3 02 0F 1D           2515 	ljmp	00132$
   11A6                    2516 00134$:
                    0724   2517 	C$gait_designer.c$470$1$1 ==.
                           2518 ;	apps/gait_designer/gait_designer.c:470: gait->msgInx = inx;
   11A6 85 17 82           2519 	mov	dpl,_gaitDesignerProcess_sloc1_1_0
   11A9 85 18 83           2520 	mov	dph,(_gaitDesignerProcess_sloc1_1_0 + 1)
   11AC 85 19 F0           2521 	mov	b,(_gaitDesignerProcess_sloc1_1_0 + 2)
   11AF 78 4E              2522 	mov	r0,#_gaitDesignerProcess_inx_1_1
   11B1 E2                 2523 	movx	a,@r0
   11B2 12 29 45           2524 	lcall	__gptrput
   11B5                    2525 00140$:
                    0733   2526 	C$gait_designer.c$472$1$1 ==.
                    0733   2527 	XG$gaitDesignerProcess$0$0 ==.
   11B5 22                 2528 	ret
                           2529 ;------------------------------------------------------------
                           2530 ;Allocation info for local variables in function 'main'
                           2531 ;------------------------------------------------------------
                    0734   2532 	G$main$0$0 ==.
                    0734   2533 	C$gait_designer.c$477$1$1 ==.
                           2534 ;	apps/gait_designer/gait_designer.c:477: void main()
                           2535 ;	-----------------------------------------
                           2536 ;	 function main
                           2537 ;	-----------------------------------------
   11B6                    2538 _main:
                    0734   2539 	C$gait_designer.c$507$1$1 ==.
                           2540 ;	apps/gait_designer/gait_designer.c:507: systemInit();
   11B6 12 29 5E           2541 	lcall	_systemInit
                    0737   2542 	C$gait_designer.c$510$1$1 ==.
                           2543 ;	apps/gait_designer/gait_designer.c:510: dynamixel_init();
   11B9 12 05 77           2544 	lcall	_dynamixel_init
                    073A   2545 	C$gait_designer.c$512$1$1 ==.
                           2546 ;	apps/gait_designer/gait_designer.c:512: setDigitalOutput(param_arduino_DTR_pin, LOW);
   11BC 90 33 91           2547 	mov	dptr,#_param_arduino_DTR_pin
   11BF E4                 2548 	clr	a
   11C0 93                 2549 	movc	a,@a+dptr
   11C1 FC                 2550 	mov	r4,a
   11C2 74 01              2551 	mov	a,#0x01
   11C4 93                 2552 	movc	a,@a+dptr
   11C5 74 02              2553 	mov	a,#0x02
   11C7 93                 2554 	movc	a,@a+dptr
   11C8 74 03              2555 	mov	a,#0x03
   11CA 93                 2556 	movc	a,@a+dptr
   11CB 8C 82              2557 	mov	dpl,r4
   11CD C2 F0              2558 	clr	b[0]
   11CF 85 F0 24           2559 	mov	bits,b
   11D2 12 2D F1           2560 	lcall	_setDigitalOutput
                    0753   2561 	C$gait_designer.c$513$1$1 ==.
                           2562 ;	apps/gait_designer/gait_designer.c:513: ioTxSignals(0);
   11D5 75 82 00           2563 	mov	dpl,#0x00
   11D8 12 0B C7           2564 	lcall	_ioTxSignals
                    0759   2565 	C$gait_designer.c$516$1$1 ==.
                           2566 ;	apps/gait_designer/gait_designer.c:516: uart1Init();
   11DB 12 14 9C           2567 	lcall	_uart1Init
                    075C   2568 	C$gait_designer.c$517$1$1 ==.
                           2569 ;	apps/gait_designer/gait_designer.c:517: uart1SetBaudRate(param_baud_rate);
   11DE 90 33 6D           2570 	mov	dptr,#_param_baud_rate
   11E1 E4                 2571 	clr	a
   11E2 93                 2572 	movc	a,@a+dptr
   11E3 FC                 2573 	mov	r4,a
   11E4 74 01              2574 	mov	a,#0x01
   11E6 93                 2575 	movc	a,@a+dptr
   11E7 FD                 2576 	mov	r5,a
   11E8 74 02              2577 	mov	a,#0x02
   11EA 93                 2578 	movc	a,@a+dptr
   11EB FE                 2579 	mov	r6,a
   11EC 74 03              2580 	mov	a,#0x03
   11EE 93                 2581 	movc	a,@a+dptr
   11EF 8C 82              2582 	mov	dpl,r4
   11F1 8D 83              2583 	mov	dph,r5
   11F3 8E F0              2584 	mov	b,r6
   11F5 12 14 D0           2585 	lcall	_uart1SetBaudRate
                    0776   2586 	C$gait_designer.c$519$1$1 ==.
                           2587 ;	apps/gait_designer/gait_designer.c:519: if (param_serial_mode != SERIAL_MODE_USB_UART)
   11F8 90 33 69           2588 	mov	dptr,#_param_serial_mode
   11FB E4                 2589 	clr	a
   11FC 93                 2590 	movc	a,@a+dptr
   11FD FC                 2591 	mov	r4,a
   11FE 74 01              2592 	mov	a,#0x01
   1200 93                 2593 	movc	a,@a+dptr
   1201 FD                 2594 	mov	r5,a
   1202 74 02              2595 	mov	a,#0x02
   1204 93                 2596 	movc	a,@a+dptr
   1205 FE                 2597 	mov	r6,a
   1206 74 03              2598 	mov	a,#0x03
   1208 93                 2599 	movc	a,@a+dptr
   1209 FF                 2600 	mov	r7,a
   120A BC 03 0B           2601 	cjne	r4,#0x03,00125$
   120D BD 00 08           2602 	cjne	r5,#0x00,00125$
   1210 BE 00 05           2603 	cjne	r6,#0x00,00125$
   1213 BF 00 02           2604 	cjne	r7,#0x00,00125$
   1216 80 05              2605 	sjmp	00108$
   1218                    2606 00125$:
                    0796   2607 	C$gait_designer.c$521$2$2 ==.
                           2608 ;	apps/gait_designer/gait_designer.c:521: radioComRxEnforceOrdering = 1;
   1218 D2 18              2609 	setb	_radioComRxEnforceOrdering
                    0798   2610 	C$gait_designer.c$522$2$2 ==.
                           2611 ;	apps/gait_designer/gait_designer.c:522: radioComInit();
   121A 12 27 EC           2612 	lcall	_radioComInit
                    079B   2613 	C$gait_designer.c$544$1$1 ==.
                           2614 ;	apps/gait_designer/gait_designer.c:544: while(1)
   121D                    2615 00108$:
                    079B   2616 	C$gait_designer.c$548$2$3 ==.
                           2617 ;	apps/gait_designer/gait_designer.c:548: boardService();
   121D 12 29 6B           2618 	lcall	_boardService
                    079E   2619 	C$gait_designer.c$549$2$3 ==.
                           2620 ;	apps/gait_designer/gait_designer.c:549: updateLeds();
   1220 12 0A 82           2621 	lcall	_updateLeds
                    07A1   2622 	C$gait_designer.c$550$2$3 ==.
                           2623 ;	apps/gait_designer/gait_designer.c:550: errorService();
   1223 12 0C EC           2624 	lcall	_errorService
                    07A4   2625 	C$gait_designer.c$552$2$3 ==.
                           2626 ;	apps/gait_designer/gait_designer.c:552: if (param_serial_mode != SERIAL_MODE_USB_UART)
   1226 90 33 69           2627 	mov	dptr,#_param_serial_mode
   1229 E4                 2628 	clr	a
   122A 93                 2629 	movc	a,@a+dptr
   122B FC                 2630 	mov	r4,a
   122C 74 01              2631 	mov	a,#0x01
   122E 93                 2632 	movc	a,@a+dptr
   122F FD                 2633 	mov	r5,a
   1230 74 02              2634 	mov	a,#0x02
   1232 93                 2635 	movc	a,@a+dptr
   1233 FE                 2636 	mov	r6,a
   1234 74 03              2637 	mov	a,#0x03
   1236 93                 2638 	movc	a,@a+dptr
   1237 FF                 2639 	mov	r7,a
   1238 BC 03 0B           2640 	cjne	r4,#0x03,00126$
   123B BD 00 08           2641 	cjne	r5,#0x00,00126$
   123E BE 00 05           2642 	cjne	r6,#0x00,00126$
   1241 BF 00 02           2643 	cjne	r7,#0x00,00126$
   1244 80 03              2644 	sjmp	00104$
   1246                    2645 00126$:
                    07C4   2646 	C$gait_designer.c$554$3$4 ==.
                           2647 ;	apps/gait_designer/gait_designer.c:554: radioComTxService();
   1246 12 28 B7           2648 	lcall	_radioComTxService
   1249                    2649 00104$:
                    07C7   2650 	C$gait_designer.c$559$2$3 ==.
                           2651 ;	apps/gait_designer/gait_designer.c:559: usbComService();
   1249 12 1F 46           2652 	lcall	_usbComService
                    07CA   2653 	C$gait_designer.c$568$2$3 ==.
                           2654 ;	apps/gait_designer/gait_designer.c:568: ms = getMs();		// Get current time in ms
   124C 12 2D 91           2655 	lcall	_getMs
   124F AC 82              2656 	mov	r4,dpl
   1251 AD 83              2657 	mov	r5,dph
   1253 AE F0              2658 	mov	r6,b
   1255 FF                 2659 	mov	r7,a
                    07D4   2660 	C$gait_designer.c$569$1$1 ==.
                           2661 ;	apps/gait_designer/gait_designer.c:569: now = ms % (uint32)10000; 	// 10 sec for a full swing
   1256 78 68              2662 	mov	r0,#__modulong_PARM_2
   1258 74 10              2663 	mov	a,#0x10
   125A F2                 2664 	movx	@r0,a
   125B 08                 2665 	inc	r0
   125C 74 27              2666 	mov	a,#0x27
   125E F2                 2667 	movx	@r0,a
   125F 08                 2668 	inc	r0
   1260 E4                 2669 	clr	a
   1261 F2                 2670 	movx	@r0,a
   1262 08                 2671 	inc	r0
   1263 F2                 2672 	movx	@r0,a
   1264 8C 82              2673 	mov	dpl,r4
   1266 8D 83              2674 	mov	dph,r5
   1268 8E F0              2675 	mov	b,r6
   126A EF                 2676 	mov	a,r7
   126B 12 1A 6F           2677 	lcall	__modulong
   126E AC 82              2678 	mov	r4,dpl
   1270 AD 83              2679 	mov	r5,dph
   1272 AE F0              2680 	mov	r6,b
   1274 FF                 2681 	mov	r7,a
                    07F3   2682 	C$gait_designer.c$570$2$3 ==.
                           2683 ;	apps/gait_designer/gait_designer.c:570: if(now >= (uint16)5000){				// Goes from 0ms...5000ms
   1275 C3                 2684 	clr	c
   1276 EC                 2685 	mov	a,r4
   1277 94 88              2686 	subb	a,#0x88
   1279 ED                 2687 	mov	a,r5
   127A 94 13              2688 	subb	a,#0x13
   127C 40 09              2689 	jc	00106$
                    07FC   2690 	C$gait_designer.c$571$3$5 ==.
                           2691 ;	apps/gait_designer/gait_designer.c:571: now = (uint16)10000 - now;			// then 5000ms...0ms
   127E 74 10              2692 	mov	a,#0x10
   1280 C3                 2693 	clr	c
   1281 9C                 2694 	subb	a,r4
   1282 FC                 2695 	mov	r4,a
   1283 74 27              2696 	mov	a,#0x27
   1285 9D                 2697 	subb	a,r5
   1286 FD                 2698 	mov	r5,a
   1287                    2699 00106$:
                    0805   2700 	C$gait_designer.c$573$2$3 ==.
                           2701 ;	apps/gait_designer/gait_designer.c:573: speed = interpolate(now, 0, 5000, 100, 900);
   1287 8C 82              2702 	mov	dpl,r4
   1289 8D 83              2703 	mov	dph,r5
   128B 78 55              2704 	mov	r0,#_interpolate_PARM_2
   128D E4                 2705 	clr	a
   128E F2                 2706 	movx	@r0,a
   128F 08                 2707 	inc	r0
   1290 F2                 2708 	movx	@r0,a
   1291 78 57              2709 	mov	r0,#_interpolate_PARM_3
   1293 74 88              2710 	mov	a,#0x88
   1295 F2                 2711 	movx	@r0,a
   1296 08                 2712 	inc	r0
   1297 74 13              2713 	mov	a,#0x13
   1299 F2                 2714 	movx	@r0,a
   129A 78 59              2715 	mov	r0,#_interpolate_PARM_4
   129C 74 64              2716 	mov	a,#0x64
   129E F2                 2717 	movx	@r0,a
   129F 08                 2718 	inc	r0
   12A0 E4                 2719 	clr	a
   12A1 F2                 2720 	movx	@r0,a
   12A2 78 5B              2721 	mov	r0,#_interpolate_PARM_5
   12A4 74 84              2722 	mov	a,#0x84
   12A6 F2                 2723 	movx	@r0,a
   12A7 08                 2724 	inc	r0
   12A8 74 03              2725 	mov	a,#0x03
   12AA F2                 2726 	movx	@r0,a
   12AB 12 12 F7           2727 	lcall	_interpolate
   12AE AE 82              2728 	mov	r6,dpl
   12B0 AF 83              2729 	mov	r7,dph
                    0830   2730 	C$gait_designer.c$575$2$3 ==.
                           2731 ;	apps/gait_designer/gait_designer.c:575: ax12SetGOAL_POSITION(32, speed);
   12B2 C3                 2732 	clr	c
   12B3 EE                 2733 	mov	a,r6
   12B4 94 FF              2734 	subb	a,#0xFF
   12B6 EF                 2735 	mov	a,r7
   12B7 94 03              2736 	subb	a,#0x03
   12B9 E4                 2737 	clr	a
   12BA 33                 2738 	rlc	a
   12BB FD                 2739 	mov	r5,a
   12BC 60 06              2740 	jz	00114$
   12BE 8E 03              2741 	mov	ar3,r6
   12C0 8F 04              2742 	mov	ar4,r7
   12C2 80 04              2743 	sjmp	00115$
   12C4                    2744 00114$:
   12C4 7B FF              2745 	mov	r3,#0xFF
   12C6 7C 03              2746 	mov	r4,#0x03
   12C8                    2747 00115$:
   12C8 EB                 2748 	mov	a,r3
   12C9 4C                 2749 	orl	a,r4
   12CA 60 0B              2750 	jz	00112$
   12CC ED                 2751 	mov	a,r5
   12CD 60 02              2752 	jz	00116$
   12CF 80 04              2753 	sjmp	00117$
   12D1                    2754 00116$:
   12D1 7E FF              2755 	mov	r6,#0xFF
   12D3 7F 03              2756 	mov	r7,#0x03
   12D5                    2757 00117$:
   12D5 80 04              2758 	sjmp	00113$
   12D7                    2759 00112$:
   12D7 7E 00              2760 	mov	r6,#0x00
   12D9 7F 00              2761 	mov	r7,#0x00
   12DB                    2762 00113$:
   12DB 78 1A              2763 	mov	r0,#_dynamixel_writeword_PARM_2
   12DD 74 1E              2764 	mov	a,#0x1E
   12DF F2                 2765 	movx	@r0,a
   12E0 78 1B              2766 	mov	r0,#_dynamixel_writeword_PARM_3
   12E2 EE                 2767 	mov	a,r6
   12E3 F2                 2768 	movx	@r0,a
   12E4 08                 2769 	inc	r0
   12E5 EF                 2770 	mov	a,r7
   12E6 F2                 2771 	movx	@r0,a
   12E7 75 82 20           2772 	mov	dpl,#0x20
   12EA 12 08 60           2773 	lcall	_dynamixel_writeword
                    086B   2774 	C$gait_designer.c$577$2$3 ==.
                           2775 ;	apps/gait_designer/gait_designer.c:577: delayMs(20);
   12ED 90 00 14           2776 	mov	dptr,#0x0014
   12F0 12 2D BD           2777 	lcall	_delayMs
   12F3 02 12 1D           2778 	ljmp	00108$
                    0874   2779 	C$gait_designer.c$581$1$1 ==.
                    0874   2780 	XG$main$0$0 ==.
   12F6 22                 2781 	ret
                           2782 	.area CSEG    (CODE)
                           2783 	.area CONST   (CODE)
                    0000   2784 G$param_serial_mode$0$0 == .
   3369                    2785 _param_serial_mode:
   3369 02 00 00 00        2786 	.byte #0x02,#0x00,#0x00,#0x00	;  2
                    0004   2787 G$param_baud_rate$0$0 == .
   336D                    2788 _param_baud_rate:
   336D 03 D9 00 00        2789 	.byte #0x03,#0xD9,#0x00,#0x00	;  55555
                    0008   2790 G$param_nDTR_pin$0$0 == .
   3371                    2791 _param_nDTR_pin:
   3371 0A 00 00 00        2792 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   2793 G$param_nRTS_pin$0$0 == .
   3375                    2794 _param_nRTS_pin:
   3375 0B 00 00 00        2795 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   2796 G$param_nDSR_pin$0$0 == .
   3379                    2797 _param_nDSR_pin:
   3379 0C 00 00 00        2798 	.byte #0x0C,#0x00,#0x00,#0x00	;  12
                    0014   2799 G$param_nCD_pin$0$0 == .
   337D                    2800 _param_nCD_pin:
   337D 0D 00 00 00        2801 	.byte #0x0D,#0x00,#0x00,#0x00	;  13
                    0018   2802 G$param_DTR_pin$0$0 == .
   3381                    2803 _param_DTR_pin:
   3381 FF FF FF FF        2804 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    001C   2805 G$param_RTS_pin$0$0 == .
   3385                    2806 _param_RTS_pin:
   3385 FF FF FF FF        2807 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0020   2808 G$param_DSR_pin$0$0 == .
   3389                    2809 _param_DSR_pin:
   3389 FF FF FF FF        2810 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0024   2811 G$param_CD_pin$0$0 == .
   338D                    2812 _param_CD_pin:
   338D FF FF FF FF        2813 	.byte #0xFF,#0xFF,#0xFF,#0xFF	; -1
                    0028   2814 G$param_arduino_DTR_pin$0$0 == .
   3391                    2815 _param_arduino_DTR_pin:
   3391 00 00 00 00        2816 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    002C   2817 G$param_framing_error_ms$0$0 == .
   3395                    2818 _param_framing_error_ms:
   3395 00 00 00 00        2819 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0030   2820 G$g8loopSpeed$0$0 == .
   3399                    2821 _g8loopSpeed:
   3399 E8 03              2822 	.byte #0xE8,#0x03	; 1000
                           2823 	.area XINIT   (CODE)
                           2824 	.area CABS    (ABS,CODE)
