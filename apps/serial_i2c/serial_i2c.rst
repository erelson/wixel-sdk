                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Aug 17 17:32:19 2012
                              5 ;--------------------------------------------------------
                              6 	.module serial_i2c
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _param_cmd_timeout_ms
                             13 	.globl _param_I2C_timeout_ms
                             14 	.globl _param_I2C_freq_kHz
                             15 	.globl _param_I2C_SDA_pin
                             16 	.globl _param_I2C_SCL_pin
                             17 	.globl _param_baud_rate
                             18 	.globl _param_bridge_mode
                             19 	.globl _main
                             20 	.globl _uartCheckErrors
                             21 	.globl _i2cService
                             22 	.globl _i2cRead
                             23 	.globl _parseCmd
                             24 	.globl _updateLeds
                             25 	.globl _i2cReadByte
                             26 	.globl _i2cWriteByte
                             27 	.globl _i2cStop
                             28 	.globl _i2cStart
                             29 	.globl _i2cSetTimeout
                             30 	.globl _i2cSetFrequency
                             31 	.globl _uart1RxReceiveByte
                             32 	.globl _uart1RxAvailable
                             33 	.globl _uart1TxSendByte
                             34 	.globl _uart1TxAvailable
                             35 	.globl _uart1SetBaudRate
                             36 	.globl _uart1Init
                             37 	.globl _radioComTxSendByte
                             38 	.globl _radioComTxAvailable
                             39 	.globl _radioComTxService
                             40 	.globl _radioComRxReceiveByte
                             41 	.globl _radioComRxAvailable
                             42 	.globl _radioComInit
                             43 	.globl _usbComTxSendByte
                             44 	.globl _usbComTxAvailable
                             45 	.globl _usbComRxReceiveByte
                             46 	.globl _usbComRxAvailable
                             47 	.globl _usbComService
                             48 	.globl _usbShowStatusWithGreenLed
                             49 	.globl _usbInit
                             50 	.globl _getMs
                             51 	.globl _vinPowerPresent
                             52 	.globl _boardService
                             53 	.globl _systemInit
                             54 	.globl _txSendByteFunction
                             55 	.globl _txAvailableFunction
                             56 	.globl _rxReceiveByteFunction
                             57 	.globl _rxAvailableFunction
                             58 	.globl _state
                             59 	.globl _lastCmd
                             60 ;--------------------------------------------------------
                             61 ; special function registers
                             62 ;--------------------------------------------------------
                             63 	.area RSEG    (ABS,DATA)
   0000                      64 	.org 0x0000
                    0080     65 Fserial_i2c$P0$0$0 == 0x0080
                    0080     66 _P0	=	0x0080
                    0081     67 Fserial_i2c$SP$0$0 == 0x0081
                    0081     68 _SP	=	0x0081
                    0082     69 Fserial_i2c$DPL0$0$0 == 0x0082
                    0082     70 _DPL0	=	0x0082
                    0083     71 Fserial_i2c$DPH0$0$0 == 0x0083
                    0083     72 _DPH0	=	0x0083
                    0084     73 Fserial_i2c$DPL1$0$0 == 0x0084
                    0084     74 _DPL1	=	0x0084
                    0085     75 Fserial_i2c$DPH1$0$0 == 0x0085
                    0085     76 _DPH1	=	0x0085
                    0086     77 Fserial_i2c$U0CSR$0$0 == 0x0086
                    0086     78 _U0CSR	=	0x0086
                    0087     79 Fserial_i2c$PCON$0$0 == 0x0087
                    0087     80 _PCON	=	0x0087
                    0088     81 Fserial_i2c$TCON$0$0 == 0x0088
                    0088     82 _TCON	=	0x0088
                    0089     83 Fserial_i2c$P0IFG$0$0 == 0x0089
                    0089     84 _P0IFG	=	0x0089
                    008A     85 Fserial_i2c$P1IFG$0$0 == 0x008a
                    008A     86 _P1IFG	=	0x008a
                    008B     87 Fserial_i2c$P2IFG$0$0 == 0x008b
                    008B     88 _P2IFG	=	0x008b
                    008C     89 Fserial_i2c$PICTL$0$0 == 0x008c
                    008C     90 _PICTL	=	0x008c
                    008D     91 Fserial_i2c$P1IEN$0$0 == 0x008d
                    008D     92 _P1IEN	=	0x008d
                    008F     93 Fserial_i2c$P0INP$0$0 == 0x008f
                    008F     94 _P0INP	=	0x008f
                    0090     95 Fserial_i2c$P1$0$0 == 0x0090
                    0090     96 _P1	=	0x0090
                    0091     97 Fserial_i2c$RFIM$0$0 == 0x0091
                    0091     98 _RFIM	=	0x0091
                    0092     99 Fserial_i2c$DPS$0$0 == 0x0092
                    0092    100 _DPS	=	0x0092
                    0093    101 Fserial_i2c$MPAGE$0$0 == 0x0093
                    0093    102 _MPAGE	=	0x0093
                    0095    103 Fserial_i2c$ENDIAN$0$0 == 0x0095
                    0095    104 _ENDIAN	=	0x0095
                    0098    105 Fserial_i2c$S0CON$0$0 == 0x0098
                    0098    106 _S0CON	=	0x0098
                    009A    107 Fserial_i2c$IEN2$0$0 == 0x009a
                    009A    108 _IEN2	=	0x009a
                    009B    109 Fserial_i2c$S1CON$0$0 == 0x009b
                    009B    110 _S1CON	=	0x009b
                    009C    111 Fserial_i2c$T2CT$0$0 == 0x009c
                    009C    112 _T2CT	=	0x009c
                    009D    113 Fserial_i2c$T2PR$0$0 == 0x009d
                    009D    114 _T2PR	=	0x009d
                    009E    115 Fserial_i2c$T2CTL$0$0 == 0x009e
                    009E    116 _T2CTL	=	0x009e
                    00A0    117 Fserial_i2c$P2$0$0 == 0x00a0
                    00A0    118 _P2	=	0x00a0
                    00A1    119 Fserial_i2c$WORIRQ$0$0 == 0x00a1
                    00A1    120 _WORIRQ	=	0x00a1
                    00A2    121 Fserial_i2c$WORCTRL$0$0 == 0x00a2
                    00A2    122 _WORCTRL	=	0x00a2
                    00A3    123 Fserial_i2c$WOREVT0$0$0 == 0x00a3
                    00A3    124 _WOREVT0	=	0x00a3
                    00A4    125 Fserial_i2c$WOREVT1$0$0 == 0x00a4
                    00A4    126 _WOREVT1	=	0x00a4
                    00A5    127 Fserial_i2c$WORTIME0$0$0 == 0x00a5
                    00A5    128 _WORTIME0	=	0x00a5
                    00A6    129 Fserial_i2c$WORTIME1$0$0 == 0x00a6
                    00A6    130 _WORTIME1	=	0x00a6
                    00A8    131 Fserial_i2c$IEN0$0$0 == 0x00a8
                    00A8    132 _IEN0	=	0x00a8
                    00A9    133 Fserial_i2c$IP0$0$0 == 0x00a9
                    00A9    134 _IP0	=	0x00a9
                    00AB    135 Fserial_i2c$FWT$0$0 == 0x00ab
                    00AB    136 _FWT	=	0x00ab
                    00AC    137 Fserial_i2c$FADDRL$0$0 == 0x00ac
                    00AC    138 _FADDRL	=	0x00ac
                    00AD    139 Fserial_i2c$FADDRH$0$0 == 0x00ad
                    00AD    140 _FADDRH	=	0x00ad
                    00AE    141 Fserial_i2c$FCTL$0$0 == 0x00ae
                    00AE    142 _FCTL	=	0x00ae
                    00AF    143 Fserial_i2c$FWDATA$0$0 == 0x00af
                    00AF    144 _FWDATA	=	0x00af
                    00B1    145 Fserial_i2c$ENCDI$0$0 == 0x00b1
                    00B1    146 _ENCDI	=	0x00b1
                    00B2    147 Fserial_i2c$ENCDO$0$0 == 0x00b2
                    00B2    148 _ENCDO	=	0x00b2
                    00B3    149 Fserial_i2c$ENCCS$0$0 == 0x00b3
                    00B3    150 _ENCCS	=	0x00b3
                    00B4    151 Fserial_i2c$ADCCON1$0$0 == 0x00b4
                    00B4    152 _ADCCON1	=	0x00b4
                    00B5    153 Fserial_i2c$ADCCON2$0$0 == 0x00b5
                    00B5    154 _ADCCON2	=	0x00b5
                    00B6    155 Fserial_i2c$ADCCON3$0$0 == 0x00b6
                    00B6    156 _ADCCON3	=	0x00b6
                    00B8    157 Fserial_i2c$IEN1$0$0 == 0x00b8
                    00B8    158 _IEN1	=	0x00b8
                    00B9    159 Fserial_i2c$IP1$0$0 == 0x00b9
                    00B9    160 _IP1	=	0x00b9
                    00BA    161 Fserial_i2c$ADCL$0$0 == 0x00ba
                    00BA    162 _ADCL	=	0x00ba
                    00BB    163 Fserial_i2c$ADCH$0$0 == 0x00bb
                    00BB    164 _ADCH	=	0x00bb
                    00BC    165 Fserial_i2c$RNDL$0$0 == 0x00bc
                    00BC    166 _RNDL	=	0x00bc
                    00BD    167 Fserial_i2c$RNDH$0$0 == 0x00bd
                    00BD    168 _RNDH	=	0x00bd
                    00BE    169 Fserial_i2c$SLEEP$0$0 == 0x00be
                    00BE    170 _SLEEP	=	0x00be
                    00C0    171 Fserial_i2c$IRCON$0$0 == 0x00c0
                    00C0    172 _IRCON	=	0x00c0
                    00C1    173 Fserial_i2c$U0DBUF$0$0 == 0x00c1
                    00C1    174 _U0DBUF	=	0x00c1
                    00C2    175 Fserial_i2c$U0BAUD$0$0 == 0x00c2
                    00C2    176 _U0BAUD	=	0x00c2
                    00C4    177 Fserial_i2c$U0UCR$0$0 == 0x00c4
                    00C4    178 _U0UCR	=	0x00c4
                    00C5    179 Fserial_i2c$U0GCR$0$0 == 0x00c5
                    00C5    180 _U0GCR	=	0x00c5
                    00C6    181 Fserial_i2c$CLKCON$0$0 == 0x00c6
                    00C6    182 _CLKCON	=	0x00c6
                    00C7    183 Fserial_i2c$MEMCTR$0$0 == 0x00c7
                    00C7    184 _MEMCTR	=	0x00c7
                    00C9    185 Fserial_i2c$WDCTL$0$0 == 0x00c9
                    00C9    186 _WDCTL	=	0x00c9
                    00CA    187 Fserial_i2c$T3CNT$0$0 == 0x00ca
                    00CA    188 _T3CNT	=	0x00ca
                    00CB    189 Fserial_i2c$T3CTL$0$0 == 0x00cb
                    00CB    190 _T3CTL	=	0x00cb
                    00CC    191 Fserial_i2c$T3CCTL0$0$0 == 0x00cc
                    00CC    192 _T3CCTL0	=	0x00cc
                    00CD    193 Fserial_i2c$T3CC0$0$0 == 0x00cd
                    00CD    194 _T3CC0	=	0x00cd
                    00CE    195 Fserial_i2c$T3CCTL1$0$0 == 0x00ce
                    00CE    196 _T3CCTL1	=	0x00ce
                    00CF    197 Fserial_i2c$T3CC1$0$0 == 0x00cf
                    00CF    198 _T3CC1	=	0x00cf
                    00D0    199 Fserial_i2c$PSW$0$0 == 0x00d0
                    00D0    200 _PSW	=	0x00d0
                    00D1    201 Fserial_i2c$DMAIRQ$0$0 == 0x00d1
                    00D1    202 _DMAIRQ	=	0x00d1
                    00D2    203 Fserial_i2c$DMA1CFGL$0$0 == 0x00d2
                    00D2    204 _DMA1CFGL	=	0x00d2
                    00D3    205 Fserial_i2c$DMA1CFGH$0$0 == 0x00d3
                    00D3    206 _DMA1CFGH	=	0x00d3
                    00D4    207 Fserial_i2c$DMA0CFGL$0$0 == 0x00d4
                    00D4    208 _DMA0CFGL	=	0x00d4
                    00D5    209 Fserial_i2c$DMA0CFGH$0$0 == 0x00d5
                    00D5    210 _DMA0CFGH	=	0x00d5
                    00D6    211 Fserial_i2c$DMAARM$0$0 == 0x00d6
                    00D6    212 _DMAARM	=	0x00d6
                    00D7    213 Fserial_i2c$DMAREQ$0$0 == 0x00d7
                    00D7    214 _DMAREQ	=	0x00d7
                    00D8    215 Fserial_i2c$TIMIF$0$0 == 0x00d8
                    00D8    216 _TIMIF	=	0x00d8
                    00D9    217 Fserial_i2c$RFD$0$0 == 0x00d9
                    00D9    218 _RFD	=	0x00d9
                    00DA    219 Fserial_i2c$T1CC0L$0$0 == 0x00da
                    00DA    220 _T1CC0L	=	0x00da
                    00DB    221 Fserial_i2c$T1CC0H$0$0 == 0x00db
                    00DB    222 _T1CC0H	=	0x00db
                    00DC    223 Fserial_i2c$T1CC1L$0$0 == 0x00dc
                    00DC    224 _T1CC1L	=	0x00dc
                    00DD    225 Fserial_i2c$T1CC1H$0$0 == 0x00dd
                    00DD    226 _T1CC1H	=	0x00dd
                    00DE    227 Fserial_i2c$T1CC2L$0$0 == 0x00de
                    00DE    228 _T1CC2L	=	0x00de
                    00DF    229 Fserial_i2c$T1CC2H$0$0 == 0x00df
                    00DF    230 _T1CC2H	=	0x00df
                    00E0    231 Fserial_i2c$ACC$0$0 == 0x00e0
                    00E0    232 _ACC	=	0x00e0
                    00E1    233 Fserial_i2c$RFST$0$0 == 0x00e1
                    00E1    234 _RFST	=	0x00e1
                    00E2    235 Fserial_i2c$T1CNTL$0$0 == 0x00e2
                    00E2    236 _T1CNTL	=	0x00e2
                    00E3    237 Fserial_i2c$T1CNTH$0$0 == 0x00e3
                    00E3    238 _T1CNTH	=	0x00e3
                    00E4    239 Fserial_i2c$T1CTL$0$0 == 0x00e4
                    00E4    240 _T1CTL	=	0x00e4
                    00E5    241 Fserial_i2c$T1CCTL0$0$0 == 0x00e5
                    00E5    242 _T1CCTL0	=	0x00e5
                    00E6    243 Fserial_i2c$T1CCTL1$0$0 == 0x00e6
                    00E6    244 _T1CCTL1	=	0x00e6
                    00E7    245 Fserial_i2c$T1CCTL2$0$0 == 0x00e7
                    00E7    246 _T1CCTL2	=	0x00e7
                    00E8    247 Fserial_i2c$IRCON2$0$0 == 0x00e8
                    00E8    248 _IRCON2	=	0x00e8
                    00E9    249 Fserial_i2c$RFIF$0$0 == 0x00e9
                    00E9    250 _RFIF	=	0x00e9
                    00EA    251 Fserial_i2c$T4CNT$0$0 == 0x00ea
                    00EA    252 _T4CNT	=	0x00ea
                    00EB    253 Fserial_i2c$T4CTL$0$0 == 0x00eb
                    00EB    254 _T4CTL	=	0x00eb
                    00EC    255 Fserial_i2c$T4CCTL0$0$0 == 0x00ec
                    00EC    256 _T4CCTL0	=	0x00ec
                    00ED    257 Fserial_i2c$T4CC0$0$0 == 0x00ed
                    00ED    258 _T4CC0	=	0x00ed
                    00EE    259 Fserial_i2c$T4CCTL1$0$0 == 0x00ee
                    00EE    260 _T4CCTL1	=	0x00ee
                    00EF    261 Fserial_i2c$T4CC1$0$0 == 0x00ef
                    00EF    262 _T4CC1	=	0x00ef
                    00F0    263 Fserial_i2c$B$0$0 == 0x00f0
                    00F0    264 _B	=	0x00f0
                    00F1    265 Fserial_i2c$PERCFG$0$0 == 0x00f1
                    00F1    266 _PERCFG	=	0x00f1
                    00F2    267 Fserial_i2c$ADCCFG$0$0 == 0x00f2
                    00F2    268 _ADCCFG	=	0x00f2
                    00F3    269 Fserial_i2c$P0SEL$0$0 == 0x00f3
                    00F3    270 _P0SEL	=	0x00f3
                    00F4    271 Fserial_i2c$P1SEL$0$0 == 0x00f4
                    00F4    272 _P1SEL	=	0x00f4
                    00F5    273 Fserial_i2c$P2SEL$0$0 == 0x00f5
                    00F5    274 _P2SEL	=	0x00f5
                    00F6    275 Fserial_i2c$P1INP$0$0 == 0x00f6
                    00F6    276 _P1INP	=	0x00f6
                    00F7    277 Fserial_i2c$P2INP$0$0 == 0x00f7
                    00F7    278 _P2INP	=	0x00f7
                    00F8    279 Fserial_i2c$U1CSR$0$0 == 0x00f8
                    00F8    280 _U1CSR	=	0x00f8
                    00F9    281 Fserial_i2c$U1DBUF$0$0 == 0x00f9
                    00F9    282 _U1DBUF	=	0x00f9
                    00FA    283 Fserial_i2c$U1BAUD$0$0 == 0x00fa
                    00FA    284 _U1BAUD	=	0x00fa
                    00FB    285 Fserial_i2c$U1UCR$0$0 == 0x00fb
                    00FB    286 _U1UCR	=	0x00fb
                    00FC    287 Fserial_i2c$U1GCR$0$0 == 0x00fc
                    00FC    288 _U1GCR	=	0x00fc
                    00FD    289 Fserial_i2c$P0DIR$0$0 == 0x00fd
                    00FD    290 _P0DIR	=	0x00fd
                    00FE    291 Fserial_i2c$P1DIR$0$0 == 0x00fe
                    00FE    292 _P1DIR	=	0x00fe
                    00FF    293 Fserial_i2c$P2DIR$0$0 == 0x00ff
                    00FF    294 _P2DIR	=	0x00ff
                    FFFFD5D4    295 Fserial_i2c$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    296 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    297 Fserial_i2c$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    298 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    299 Fserial_i2c$FADDR$0$0 == 0xffffadac
                    FFFFADAC    300 _FADDR	=	0xffffadac
                    FFFFBBBA    301 Fserial_i2c$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    302 _ADC	=	0xffffbbba
                    FFFFDBDA    303 Fserial_i2c$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    304 _T1CC0	=	0xffffdbda
                    FFFFDDDC    305 Fserial_i2c$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    306 _T1CC1	=	0xffffdddc
                    FFFFDFDE    307 Fserial_i2c$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    308 _T1CC2	=	0xffffdfde
                            309 ;--------------------------------------------------------
                            310 ; special function bits
                            311 ;--------------------------------------------------------
                            312 	.area RSEG    (ABS,DATA)
   0000                     313 	.org 0x0000
                    0080    314 Fserial_i2c$P0_0$0$0 == 0x0080
                    0080    315 _P0_0	=	0x0080
                    0081    316 Fserial_i2c$P0_1$0$0 == 0x0081
                    0081    317 _P0_1	=	0x0081
                    0082    318 Fserial_i2c$P0_2$0$0 == 0x0082
                    0082    319 _P0_2	=	0x0082
                    0083    320 Fserial_i2c$P0_3$0$0 == 0x0083
                    0083    321 _P0_3	=	0x0083
                    0084    322 Fserial_i2c$P0_4$0$0 == 0x0084
                    0084    323 _P0_4	=	0x0084
                    0085    324 Fserial_i2c$P0_5$0$0 == 0x0085
                    0085    325 _P0_5	=	0x0085
                    0086    326 Fserial_i2c$P0_6$0$0 == 0x0086
                    0086    327 _P0_6	=	0x0086
                    0087    328 Fserial_i2c$P0_7$0$0 == 0x0087
                    0087    329 _P0_7	=	0x0087
                    0088    330 Fserial_i2c$_TCON_0$0$0 == 0x0088
                    0088    331 __TCON_0	=	0x0088
                    0089    332 Fserial_i2c$RFTXRXIF$0$0 == 0x0089
                    0089    333 _RFTXRXIF	=	0x0089
                    008A    334 Fserial_i2c$_TCON_2$0$0 == 0x008a
                    008A    335 __TCON_2	=	0x008a
                    008B    336 Fserial_i2c$URX0IF$0$0 == 0x008b
                    008B    337 _URX0IF	=	0x008b
                    008C    338 Fserial_i2c$_TCON_4$0$0 == 0x008c
                    008C    339 __TCON_4	=	0x008c
                    008D    340 Fserial_i2c$ADCIF$0$0 == 0x008d
                    008D    341 _ADCIF	=	0x008d
                    008E    342 Fserial_i2c$_TCON_6$0$0 == 0x008e
                    008E    343 __TCON_6	=	0x008e
                    008F    344 Fserial_i2c$URX1IF$0$0 == 0x008f
                    008F    345 _URX1IF	=	0x008f
                    0090    346 Fserial_i2c$P1_0$0$0 == 0x0090
                    0090    347 _P1_0	=	0x0090
                    0091    348 Fserial_i2c$P1_1$0$0 == 0x0091
                    0091    349 _P1_1	=	0x0091
                    0092    350 Fserial_i2c$P1_2$0$0 == 0x0092
                    0092    351 _P1_2	=	0x0092
                    0093    352 Fserial_i2c$P1_3$0$0 == 0x0093
                    0093    353 _P1_3	=	0x0093
                    0094    354 Fserial_i2c$P1_4$0$0 == 0x0094
                    0094    355 _P1_4	=	0x0094
                    0095    356 Fserial_i2c$P1_5$0$0 == 0x0095
                    0095    357 _P1_5	=	0x0095
                    0096    358 Fserial_i2c$P1_6$0$0 == 0x0096
                    0096    359 _P1_6	=	0x0096
                    0097    360 Fserial_i2c$P1_7$0$0 == 0x0097
                    0097    361 _P1_7	=	0x0097
                    0098    362 Fserial_i2c$ENCIF_0$0$0 == 0x0098
                    0098    363 _ENCIF_0	=	0x0098
                    0099    364 Fserial_i2c$ENCIF_1$0$0 == 0x0099
                    0099    365 _ENCIF_1	=	0x0099
                    009A    366 Fserial_i2c$_SOCON2$0$0 == 0x009a
                    009A    367 __SOCON2	=	0x009a
                    009B    368 Fserial_i2c$_SOCON3$0$0 == 0x009b
                    009B    369 __SOCON3	=	0x009b
                    009C    370 Fserial_i2c$_SOCON4$0$0 == 0x009c
                    009C    371 __SOCON4	=	0x009c
                    009D    372 Fserial_i2c$_SOCON5$0$0 == 0x009d
                    009D    373 __SOCON5	=	0x009d
                    009E    374 Fserial_i2c$_SOCON6$0$0 == 0x009e
                    009E    375 __SOCON6	=	0x009e
                    009F    376 Fserial_i2c$_SOCON7$0$0 == 0x009f
                    009F    377 __SOCON7	=	0x009f
                    00A0    378 Fserial_i2c$P2_0$0$0 == 0x00a0
                    00A0    379 _P2_0	=	0x00a0
                    00A1    380 Fserial_i2c$P2_1$0$0 == 0x00a1
                    00A1    381 _P2_1	=	0x00a1
                    00A2    382 Fserial_i2c$P2_2$0$0 == 0x00a2
                    00A2    383 _P2_2	=	0x00a2
                    00A3    384 Fserial_i2c$P2_3$0$0 == 0x00a3
                    00A3    385 _P2_3	=	0x00a3
                    00A4    386 Fserial_i2c$P2_4$0$0 == 0x00a4
                    00A4    387 _P2_4	=	0x00a4
                    00A5    388 Fserial_i2c$P2_5$0$0 == 0x00a5
                    00A5    389 _P2_5	=	0x00a5
                    00A6    390 Fserial_i2c$P2_6$0$0 == 0x00a6
                    00A6    391 _P2_6	=	0x00a6
                    00A7    392 Fserial_i2c$P2_7$0$0 == 0x00a7
                    00A7    393 _P2_7	=	0x00a7
                    00A8    394 Fserial_i2c$RFTXRXIE$0$0 == 0x00a8
                    00A8    395 _RFTXRXIE	=	0x00a8
                    00A9    396 Fserial_i2c$ADCIE$0$0 == 0x00a9
                    00A9    397 _ADCIE	=	0x00a9
                    00AA    398 Fserial_i2c$URX0IE$0$0 == 0x00aa
                    00AA    399 _URX0IE	=	0x00aa
                    00AB    400 Fserial_i2c$URX1IE$0$0 == 0x00ab
                    00AB    401 _URX1IE	=	0x00ab
                    00AC    402 Fserial_i2c$ENCIE$0$0 == 0x00ac
                    00AC    403 _ENCIE	=	0x00ac
                    00AD    404 Fserial_i2c$STIE$0$0 == 0x00ad
                    00AD    405 _STIE	=	0x00ad
                    00AE    406 Fserial_i2c$_IEN06$0$0 == 0x00ae
                    00AE    407 __IEN06	=	0x00ae
                    00AF    408 Fserial_i2c$EA$0$0 == 0x00af
                    00AF    409 _EA	=	0x00af
                    00B8    410 Fserial_i2c$DMAIE$0$0 == 0x00b8
                    00B8    411 _DMAIE	=	0x00b8
                    00B9    412 Fserial_i2c$T1IE$0$0 == 0x00b9
                    00B9    413 _T1IE	=	0x00b9
                    00BA    414 Fserial_i2c$T2IE$0$0 == 0x00ba
                    00BA    415 _T2IE	=	0x00ba
                    00BB    416 Fserial_i2c$T3IE$0$0 == 0x00bb
                    00BB    417 _T3IE	=	0x00bb
                    00BC    418 Fserial_i2c$T4IE$0$0 == 0x00bc
                    00BC    419 _T4IE	=	0x00bc
                    00BD    420 Fserial_i2c$P0IE$0$0 == 0x00bd
                    00BD    421 _P0IE	=	0x00bd
                    00BE    422 Fserial_i2c$_IEN16$0$0 == 0x00be
                    00BE    423 __IEN16	=	0x00be
                    00BF    424 Fserial_i2c$_IEN17$0$0 == 0x00bf
                    00BF    425 __IEN17	=	0x00bf
                    00C0    426 Fserial_i2c$DMAIF$0$0 == 0x00c0
                    00C0    427 _DMAIF	=	0x00c0
                    00C1    428 Fserial_i2c$T1IF$0$0 == 0x00c1
                    00C1    429 _T1IF	=	0x00c1
                    00C2    430 Fserial_i2c$T2IF$0$0 == 0x00c2
                    00C2    431 _T2IF	=	0x00c2
                    00C3    432 Fserial_i2c$T3IF$0$0 == 0x00c3
                    00C3    433 _T3IF	=	0x00c3
                    00C4    434 Fserial_i2c$T4IF$0$0 == 0x00c4
                    00C4    435 _T4IF	=	0x00c4
                    00C5    436 Fserial_i2c$P0IF$0$0 == 0x00c5
                    00C5    437 _P0IF	=	0x00c5
                    00C6    438 Fserial_i2c$_IRCON6$0$0 == 0x00c6
                    00C6    439 __IRCON6	=	0x00c6
                    00C7    440 Fserial_i2c$STIF$0$0 == 0x00c7
                    00C7    441 _STIF	=	0x00c7
                    00D0    442 Fserial_i2c$P$0$0 == 0x00d0
                    00D0    443 _P	=	0x00d0
                    00D1    444 Fserial_i2c$F1$0$0 == 0x00d1
                    00D1    445 _F1	=	0x00d1
                    00D2    446 Fserial_i2c$OV$0$0 == 0x00d2
                    00D2    447 _OV	=	0x00d2
                    00D3    448 Fserial_i2c$RS0$0$0 == 0x00d3
                    00D3    449 _RS0	=	0x00d3
                    00D4    450 Fserial_i2c$RS1$0$0 == 0x00d4
                    00D4    451 _RS1	=	0x00d4
                    00D5    452 Fserial_i2c$F0$0$0 == 0x00d5
                    00D5    453 _F0	=	0x00d5
                    00D6    454 Fserial_i2c$AC$0$0 == 0x00d6
                    00D6    455 _AC	=	0x00d6
                    00D7    456 Fserial_i2c$CY$0$0 == 0x00d7
                    00D7    457 _CY	=	0x00d7
                    00D8    458 Fserial_i2c$T3OVFIF$0$0 == 0x00d8
                    00D8    459 _T3OVFIF	=	0x00d8
                    00D9    460 Fserial_i2c$T3CH0IF$0$0 == 0x00d9
                    00D9    461 _T3CH0IF	=	0x00d9
                    00DA    462 Fserial_i2c$T3CH1IF$0$0 == 0x00da
                    00DA    463 _T3CH1IF	=	0x00da
                    00DB    464 Fserial_i2c$T4OVFIF$0$0 == 0x00db
                    00DB    465 _T4OVFIF	=	0x00db
                    00DC    466 Fserial_i2c$T4CH0IF$0$0 == 0x00dc
                    00DC    467 _T4CH0IF	=	0x00dc
                    00DD    468 Fserial_i2c$T4CH1IF$0$0 == 0x00dd
                    00DD    469 _T4CH1IF	=	0x00dd
                    00DE    470 Fserial_i2c$OVFIM$0$0 == 0x00de
                    00DE    471 _OVFIM	=	0x00de
                    00DF    472 Fserial_i2c$_TIMIF7$0$0 == 0x00df
                    00DF    473 __TIMIF7	=	0x00df
                    00E0    474 Fserial_i2c$ACC_0$0$0 == 0x00e0
                    00E0    475 _ACC_0	=	0x00e0
                    00E1    476 Fserial_i2c$ACC_1$0$0 == 0x00e1
                    00E1    477 _ACC_1	=	0x00e1
                    00E2    478 Fserial_i2c$ACC_2$0$0 == 0x00e2
                    00E2    479 _ACC_2	=	0x00e2
                    00E3    480 Fserial_i2c$ACC_3$0$0 == 0x00e3
                    00E3    481 _ACC_3	=	0x00e3
                    00E4    482 Fserial_i2c$ACC_4$0$0 == 0x00e4
                    00E4    483 _ACC_4	=	0x00e4
                    00E5    484 Fserial_i2c$ACC_5$0$0 == 0x00e5
                    00E5    485 _ACC_5	=	0x00e5
                    00E6    486 Fserial_i2c$ACC_6$0$0 == 0x00e6
                    00E6    487 _ACC_6	=	0x00e6
                    00E7    488 Fserial_i2c$ACC_7$0$0 == 0x00e7
                    00E7    489 _ACC_7	=	0x00e7
                    00E8    490 Fserial_i2c$P2IF$0$0 == 0x00e8
                    00E8    491 _P2IF	=	0x00e8
                    00E9    492 Fserial_i2c$UTX0IF$0$0 == 0x00e9
                    00E9    493 _UTX0IF	=	0x00e9
                    00EA    494 Fserial_i2c$UTX1IF$0$0 == 0x00ea
                    00EA    495 _UTX1IF	=	0x00ea
                    00EB    496 Fserial_i2c$P1IF$0$0 == 0x00eb
                    00EB    497 _P1IF	=	0x00eb
                    00EC    498 Fserial_i2c$WDTIF$0$0 == 0x00ec
                    00EC    499 _WDTIF	=	0x00ec
                    00ED    500 Fserial_i2c$_IRCON25$0$0 == 0x00ed
                    00ED    501 __IRCON25	=	0x00ed
                    00EE    502 Fserial_i2c$_IRCON26$0$0 == 0x00ee
                    00EE    503 __IRCON26	=	0x00ee
                    00EF    504 Fserial_i2c$_IRCON27$0$0 == 0x00ef
                    00EF    505 __IRCON27	=	0x00ef
                    00F0    506 Fserial_i2c$B_0$0$0 == 0x00f0
                    00F0    507 _B_0	=	0x00f0
                    00F1    508 Fserial_i2c$B_1$0$0 == 0x00f1
                    00F1    509 _B_1	=	0x00f1
                    00F2    510 Fserial_i2c$B_2$0$0 == 0x00f2
                    00F2    511 _B_2	=	0x00f2
                    00F3    512 Fserial_i2c$B_3$0$0 == 0x00f3
                    00F3    513 _B_3	=	0x00f3
                    00F4    514 Fserial_i2c$B_4$0$0 == 0x00f4
                    00F4    515 _B_4	=	0x00f4
                    00F5    516 Fserial_i2c$B_5$0$0 == 0x00f5
                    00F5    517 _B_5	=	0x00f5
                    00F6    518 Fserial_i2c$B_6$0$0 == 0x00f6
                    00F6    519 _B_6	=	0x00f6
                    00F7    520 Fserial_i2c$B_7$0$0 == 0x00f7
                    00F7    521 _B_7	=	0x00f7
                    00F8    522 Fserial_i2c$U1ACTIVE$0$0 == 0x00f8
                    00F8    523 _U1ACTIVE	=	0x00f8
                    00F9    524 Fserial_i2c$U1TX_BYTE$0$0 == 0x00f9
                    00F9    525 _U1TX_BYTE	=	0x00f9
                    00FA    526 Fserial_i2c$U1RX_BYTE$0$0 == 0x00fa
                    00FA    527 _U1RX_BYTE	=	0x00fa
                    00FB    528 Fserial_i2c$U1ERR$0$0 == 0x00fb
                    00FB    529 _U1ERR	=	0x00fb
                    00FC    530 Fserial_i2c$U1FE$0$0 == 0x00fc
                    00FC    531 _U1FE	=	0x00fc
                    00FD    532 Fserial_i2c$U1SLAVE$0$0 == 0x00fd
                    00FD    533 _U1SLAVE	=	0x00fd
                    00FE    534 Fserial_i2c$U1RE$0$0 == 0x00fe
                    00FE    535 _U1RE	=	0x00fe
                    00FF    536 Fserial_i2c$U1MODE$0$0 == 0x00ff
                    00FF    537 _U1MODE	=	0x00ff
                            538 ;--------------------------------------------------------
                            539 ; overlayable register banks
                            540 ;--------------------------------------------------------
                            541 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     542 	.ds 8
                            543 ;--------------------------------------------------------
                            544 ; internal ram data
                            545 ;--------------------------------------------------------
                            546 	.area DSEG    (DATA)
                    0000    547 Lserial_i2c.i2cService$sloc0$1$0==.
   0008                     548 _i2cService_sloc0_1_0:
   0008                     549 	.ds 4
                            550 ;--------------------------------------------------------
                            551 ; overlayable items in internal ram 
                            552 ;--------------------------------------------------------
                            553 	.area OSEG    (OVR,DATA)
                            554 ;--------------------------------------------------------
                            555 ; Stack segment in internal ram 
                            556 ;--------------------------------------------------------
                            557 	.area	SSEG	(DATA)
   0034                     558 __start__stack:
   0034                     559 	.ds	1
                            560 
                            561 ;--------------------------------------------------------
                            562 ; indirectly addressable internal ram data
                            563 ;--------------------------------------------------------
                            564 	.area ISEG    (DATA)
                            565 ;--------------------------------------------------------
                            566 ; absolute internal ram data
                            567 ;--------------------------------------------------------
                            568 	.area IABS    (ABS,DATA)
                            569 	.area IABS    (ABS,DATA)
                            570 ;--------------------------------------------------------
                            571 ; bit data
                            572 ;--------------------------------------------------------
                            573 	.area BSEG    (BIT)
                    0000    574 Fserial_i2c$returnResponse$0$0==.
   0000                     575 _returnResponse:
   0000                     576 	.ds 1
                    0001    577 Fserial_i2c$started$0$0==.
   0001                     578 _started:
   0001                     579 	.ds 1
                    0002    580 Fserial_i2c$dataDirIsRead$0$0==.
   0002                     581 _dataDirIsRead:
   0002                     582 	.ds 1
                    0003    583 Lserial_i2c.parseCmd$nack$1$1==.
   0003                     584 _parseCmd_nack_1_1:
   0003                     585 	.ds 1
                    0004    586 Lserial_i2c.i2cRead$sloc0$1$0==.
   0004                     587 _i2cRead_sloc0_1_0:
   0004                     588 	.ds 1
                            589 ;--------------------------------------------------------
                            590 ; paged external ram data
                            591 ;--------------------------------------------------------
                            592 	.area PSEG    (PAG,XDATA)
                    0000    593 G$lastCmd$0$0==.
   F000                     594 _lastCmd::
   F000                     595 	.ds 2
                    0002    596 Fserial_i2c$errors$0$0==.
   F002                     597 _errors:
   F002                     598 	.ds 1
                    0003    599 Fserial_i2c$response$0$0==.
   F003                     600 _response:
   F003                     601 	.ds 1
                    0004    602 G$state$0$0==.
   F004                     603 _state::
   F004                     604 	.ds 1
                    0005    605 Fserial_i2c$dataLength$0$0==.
   F005                     606 _dataLength:
   F005                     607 	.ds 1
                    0006    608 G$rxAvailableFunction$0$0==.
   F006                     609 _rxAvailableFunction::
   F006                     610 	.ds 2
                    0008    611 G$rxReceiveByteFunction$0$0==.
   F008                     612 _rxReceiveByteFunction::
   F008                     613 	.ds 2
                    000A    614 G$txAvailableFunction$0$0==.
   F00A                     615 _txAvailableFunction::
   F00A                     616 	.ds 2
                    000C    617 G$txSendByteFunction$0$0==.
   F00C                     618 _txSendByteFunction::
   F00C                     619 	.ds 2
                            620 ;--------------------------------------------------------
                            621 ; external ram data
                            622 ;--------------------------------------------------------
                            623 	.area XSEG    (XDATA)
                    DF00    624 Fserial_i2c$SYNC1$0$0 == 0xdf00
                    DF00    625 _SYNC1	=	0xdf00
                    DF01    626 Fserial_i2c$SYNC0$0$0 == 0xdf01
                    DF01    627 _SYNC0	=	0xdf01
                    DF02    628 Fserial_i2c$PKTLEN$0$0 == 0xdf02
                    DF02    629 _PKTLEN	=	0xdf02
                    DF03    630 Fserial_i2c$PKTCTRL1$0$0 == 0xdf03
                    DF03    631 _PKTCTRL1	=	0xdf03
                    DF04    632 Fserial_i2c$PKTCTRL0$0$0 == 0xdf04
                    DF04    633 _PKTCTRL0	=	0xdf04
                    DF05    634 Fserial_i2c$ADDR$0$0 == 0xdf05
                    DF05    635 _ADDR	=	0xdf05
                    DF06    636 Fserial_i2c$CHANNR$0$0 == 0xdf06
                    DF06    637 _CHANNR	=	0xdf06
                    DF07    638 Fserial_i2c$FSCTRL1$0$0 == 0xdf07
                    DF07    639 _FSCTRL1	=	0xdf07
                    DF08    640 Fserial_i2c$FSCTRL0$0$0 == 0xdf08
                    DF08    641 _FSCTRL0	=	0xdf08
                    DF09    642 Fserial_i2c$FREQ2$0$0 == 0xdf09
                    DF09    643 _FREQ2	=	0xdf09
                    DF0A    644 Fserial_i2c$FREQ1$0$0 == 0xdf0a
                    DF0A    645 _FREQ1	=	0xdf0a
                    DF0B    646 Fserial_i2c$FREQ0$0$0 == 0xdf0b
                    DF0B    647 _FREQ0	=	0xdf0b
                    DF0C    648 Fserial_i2c$MDMCFG4$0$0 == 0xdf0c
                    DF0C    649 _MDMCFG4	=	0xdf0c
                    DF0D    650 Fserial_i2c$MDMCFG3$0$0 == 0xdf0d
                    DF0D    651 _MDMCFG3	=	0xdf0d
                    DF0E    652 Fserial_i2c$MDMCFG2$0$0 == 0xdf0e
                    DF0E    653 _MDMCFG2	=	0xdf0e
                    DF0F    654 Fserial_i2c$MDMCFG1$0$0 == 0xdf0f
                    DF0F    655 _MDMCFG1	=	0xdf0f
                    DF10    656 Fserial_i2c$MDMCFG0$0$0 == 0xdf10
                    DF10    657 _MDMCFG0	=	0xdf10
                    DF11    658 Fserial_i2c$DEVIATN$0$0 == 0xdf11
                    DF11    659 _DEVIATN	=	0xdf11
                    DF12    660 Fserial_i2c$MCSM2$0$0 == 0xdf12
                    DF12    661 _MCSM2	=	0xdf12
                    DF13    662 Fserial_i2c$MCSM1$0$0 == 0xdf13
                    DF13    663 _MCSM1	=	0xdf13
                    DF14    664 Fserial_i2c$MCSM0$0$0 == 0xdf14
                    DF14    665 _MCSM0	=	0xdf14
                    DF15    666 Fserial_i2c$FOCCFG$0$0 == 0xdf15
                    DF15    667 _FOCCFG	=	0xdf15
                    DF16    668 Fserial_i2c$BSCFG$0$0 == 0xdf16
                    DF16    669 _BSCFG	=	0xdf16
                    DF17    670 Fserial_i2c$AGCCTRL2$0$0 == 0xdf17
                    DF17    671 _AGCCTRL2	=	0xdf17
                    DF18    672 Fserial_i2c$AGCCTRL1$0$0 == 0xdf18
                    DF18    673 _AGCCTRL1	=	0xdf18
                    DF19    674 Fserial_i2c$AGCCTRL0$0$0 == 0xdf19
                    DF19    675 _AGCCTRL0	=	0xdf19
                    DF1A    676 Fserial_i2c$FREND1$0$0 == 0xdf1a
                    DF1A    677 _FREND1	=	0xdf1a
                    DF1B    678 Fserial_i2c$FREND0$0$0 == 0xdf1b
                    DF1B    679 _FREND0	=	0xdf1b
                    DF1C    680 Fserial_i2c$FSCAL3$0$0 == 0xdf1c
                    DF1C    681 _FSCAL3	=	0xdf1c
                    DF1D    682 Fserial_i2c$FSCAL2$0$0 == 0xdf1d
                    DF1D    683 _FSCAL2	=	0xdf1d
                    DF1E    684 Fserial_i2c$FSCAL1$0$0 == 0xdf1e
                    DF1E    685 _FSCAL1	=	0xdf1e
                    DF1F    686 Fserial_i2c$FSCAL0$0$0 == 0xdf1f
                    DF1F    687 _FSCAL0	=	0xdf1f
                    DF23    688 Fserial_i2c$TEST2$0$0 == 0xdf23
                    DF23    689 _TEST2	=	0xdf23
                    DF24    690 Fserial_i2c$TEST1$0$0 == 0xdf24
                    DF24    691 _TEST1	=	0xdf24
                    DF25    692 Fserial_i2c$TEST0$0$0 == 0xdf25
                    DF25    693 _TEST0	=	0xdf25
                    DF2E    694 Fserial_i2c$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    695 _PA_TABLE0	=	0xdf2e
                    DF2F    696 Fserial_i2c$IOCFG2$0$0 == 0xdf2f
                    DF2F    697 _IOCFG2	=	0xdf2f
                    DF30    698 Fserial_i2c$IOCFG1$0$0 == 0xdf30
                    DF30    699 _IOCFG1	=	0xdf30
                    DF31    700 Fserial_i2c$IOCFG0$0$0 == 0xdf31
                    DF31    701 _IOCFG0	=	0xdf31
                    DF36    702 Fserial_i2c$PARTNUM$0$0 == 0xdf36
                    DF36    703 _PARTNUM	=	0xdf36
                    DF37    704 Fserial_i2c$VERSION$0$0 == 0xdf37
                    DF37    705 _VERSION	=	0xdf37
                    DF38    706 Fserial_i2c$FREQEST$0$0 == 0xdf38
                    DF38    707 _FREQEST	=	0xdf38
                    DF39    708 Fserial_i2c$LQI$0$0 == 0xdf39
                    DF39    709 _LQI	=	0xdf39
                    DF3A    710 Fserial_i2c$RSSI$0$0 == 0xdf3a
                    DF3A    711 _RSSI	=	0xdf3a
                    DF3B    712 Fserial_i2c$MARCSTATE$0$0 == 0xdf3b
                    DF3B    713 _MARCSTATE	=	0xdf3b
                    DF3C    714 Fserial_i2c$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    715 _PKTSTATUS	=	0xdf3c
                    DF3D    716 Fserial_i2c$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    717 _VCO_VC_DAC	=	0xdf3d
                    DF40    718 Fserial_i2c$I2SCFG0$0$0 == 0xdf40
                    DF40    719 _I2SCFG0	=	0xdf40
                    DF41    720 Fserial_i2c$I2SCFG1$0$0 == 0xdf41
                    DF41    721 _I2SCFG1	=	0xdf41
                    DF42    722 Fserial_i2c$I2SDATL$0$0 == 0xdf42
                    DF42    723 _I2SDATL	=	0xdf42
                    DF43    724 Fserial_i2c$I2SDATH$0$0 == 0xdf43
                    DF43    725 _I2SDATH	=	0xdf43
                    DF44    726 Fserial_i2c$I2SWCNT$0$0 == 0xdf44
                    DF44    727 _I2SWCNT	=	0xdf44
                    DF45    728 Fserial_i2c$I2SSTAT$0$0 == 0xdf45
                    DF45    729 _I2SSTAT	=	0xdf45
                    DF46    730 Fserial_i2c$I2SCLKF0$0$0 == 0xdf46
                    DF46    731 _I2SCLKF0	=	0xdf46
                    DF47    732 Fserial_i2c$I2SCLKF1$0$0 == 0xdf47
                    DF47    733 _I2SCLKF1	=	0xdf47
                    DF48    734 Fserial_i2c$I2SCLKF2$0$0 == 0xdf48
                    DF48    735 _I2SCLKF2	=	0xdf48
                    DE00    736 Fserial_i2c$USBADDR$0$0 == 0xde00
                    DE00    737 _USBADDR	=	0xde00
                    DE01    738 Fserial_i2c$USBPOW$0$0 == 0xde01
                    DE01    739 _USBPOW	=	0xde01
                    DE02    740 Fserial_i2c$USBIIF$0$0 == 0xde02
                    DE02    741 _USBIIF	=	0xde02
                    DE04    742 Fserial_i2c$USBOIF$0$0 == 0xde04
                    DE04    743 _USBOIF	=	0xde04
                    DE06    744 Fserial_i2c$USBCIF$0$0 == 0xde06
                    DE06    745 _USBCIF	=	0xde06
                    DE07    746 Fserial_i2c$USBIIE$0$0 == 0xde07
                    DE07    747 _USBIIE	=	0xde07
                    DE09    748 Fserial_i2c$USBOIE$0$0 == 0xde09
                    DE09    749 _USBOIE	=	0xde09
                    DE0B    750 Fserial_i2c$USBCIE$0$0 == 0xde0b
                    DE0B    751 _USBCIE	=	0xde0b
                    DE0C    752 Fserial_i2c$USBFRML$0$0 == 0xde0c
                    DE0C    753 _USBFRML	=	0xde0c
                    DE0D    754 Fserial_i2c$USBFRMH$0$0 == 0xde0d
                    DE0D    755 _USBFRMH	=	0xde0d
                    DE0E    756 Fserial_i2c$USBINDEX$0$0 == 0xde0e
                    DE0E    757 _USBINDEX	=	0xde0e
                    DE10    758 Fserial_i2c$USBMAXI$0$0 == 0xde10
                    DE10    759 _USBMAXI	=	0xde10
                    DE11    760 Fserial_i2c$USBCSIL$0$0 == 0xde11
                    DE11    761 _USBCSIL	=	0xde11
                    DE12    762 Fserial_i2c$USBCSIH$0$0 == 0xde12
                    DE12    763 _USBCSIH	=	0xde12
                    DE13    764 Fserial_i2c$USBMAXO$0$0 == 0xde13
                    DE13    765 _USBMAXO	=	0xde13
                    DE14    766 Fserial_i2c$USBCSOL$0$0 == 0xde14
                    DE14    767 _USBCSOL	=	0xde14
                    DE15    768 Fserial_i2c$USBCSOH$0$0 == 0xde15
                    DE15    769 _USBCSOH	=	0xde15
                    DE16    770 Fserial_i2c$USBCNTL$0$0 == 0xde16
                    DE16    771 _USBCNTL	=	0xde16
                    DE17    772 Fserial_i2c$USBCNTH$0$0 == 0xde17
                    DE17    773 _USBCNTH	=	0xde17
                    DE20    774 Fserial_i2c$USBF0$0$0 == 0xde20
                    DE20    775 _USBF0	=	0xde20
                    DE22    776 Fserial_i2c$USBF1$0$0 == 0xde22
                    DE22    777 _USBF1	=	0xde22
                    DE24    778 Fserial_i2c$USBF2$0$0 == 0xde24
                    DE24    779 _USBF2	=	0xde24
                    DE26    780 Fserial_i2c$USBF3$0$0 == 0xde26
                    DE26    781 _USBF3	=	0xde26
                    DE28    782 Fserial_i2c$USBF4$0$0 == 0xde28
                    DE28    783 _USBF4	=	0xde28
                    DE2A    784 Fserial_i2c$USBF5$0$0 == 0xde2a
                    DE2A    785 _USBF5	=	0xde2a
                            786 ;--------------------------------------------------------
                            787 ; absolute external ram data
                            788 ;--------------------------------------------------------
                            789 	.area XABS    (ABS,XDATA)
                            790 ;--------------------------------------------------------
                            791 ; external initialized ram data
                            792 ;--------------------------------------------------------
                            793 	.area XISEG   (XDATA)
                            794 	.area HOME    (CODE)
                            795 	.area GSINIT0 (CODE)
                            796 	.area GSINIT1 (CODE)
                            797 	.area GSINIT2 (CODE)
                            798 	.area GSINIT3 (CODE)
                            799 	.area GSINIT4 (CODE)
                            800 	.area GSINIT5 (CODE)
                            801 	.area GSINIT  (CODE)
                            802 	.area GSFINAL (CODE)
                            803 	.area CSEG    (CODE)
                            804 ;--------------------------------------------------------
                            805 ; interrupt vector 
                            806 ;--------------------------------------------------------
                            807 	.area HOME    (CODE)
   0400                     808 __interrupt_vect:
   0400 02 04 8D            809 	ljmp	__sdcc_gsinit_startup
   0403 32                  810 	reti
   0404                     811 	.ds	7
   040B 32                  812 	reti
   040C                     813 	.ds	7
   0413 32                  814 	reti
   0414                     815 	.ds	7
   041B 02 0B 7B            816 	ljmp	_ISR_URX1
   041E                     817 	.ds	5
   0423 32                  818 	reti
   0424                     819 	.ds	7
   042B 32                  820 	reti
   042C                     821 	.ds	7
   0433 32                  822 	reti
   0434                     823 	.ds	7
   043B 32                  824 	reti
   043C                     825 	.ds	7
   0443 32                  826 	reti
   0444                     827 	.ds	7
   044B 32                  828 	reti
   044C                     829 	.ds	7
   0453 32                  830 	reti
   0454                     831 	.ds	7
   045B 32                  832 	reti
   045C                     833 	.ds	7
   0463 02 1D DC            834 	ljmp	_ISR_T4
   0466                     835 	.ds	5
   046B 32                  836 	reti
   046C                     837 	.ds	7
   0473 02 0B 3D            838 	ljmp	_ISR_UTX1
   0476                     839 	.ds	5
   047B 32                  840 	reti
   047C                     841 	.ds	7
   0483 02 0E 6F            842 	ljmp	_ISR_RF
                            843 ;--------------------------------------------------------
                            844 ; global & static initialisations
                            845 ;--------------------------------------------------------
                            846 	.area HOME    (CODE)
                            847 	.area GSINIT  (CODE)
                            848 	.area GSFINAL (CODE)
                            849 	.area GSINIT  (CODE)
                            850 	.globl __sdcc_gsinit_startup
                            851 	.globl __sdcc_program_startup
                            852 	.globl __start__stack
                            853 	.globl __mcs51_genXINIT
                            854 	.globl __mcs51_genXRAMCLEAR
                            855 	.globl __mcs51_genRAMCLEAR
                    0000    856 	G$main$0$0 ==.
                    0000    857 	C$serial_i2c.c$73$1$1 ==.
                            858 ;	apps/serial_i2c/serial_i2c.c:73: static BIT returnResponse = 0;
   04E6 C2 00               859 	clr	_returnResponse
                    0002    860 	G$main$0$0 ==.
                    0002    861 	C$serial_i2c.c$78$1$1 ==.
                            862 ;	apps/serial_i2c/serial_i2c.c:78: static BIT started = 0;
   04E8 C2 01               863 	clr	_started
                    0004    864 	G$main$0$0 ==.
                    0004    865 	C$serial_i2c.c$79$1$1 ==.
                            866 ;	apps/serial_i2c/serial_i2c.c:79: static BIT dataDirIsRead = 0;
   04EA C2 02               867 	clr	_dataDirIsRead
                    0006    868 	G$main$0$0 ==.
                    0006    869 	C$serial_i2c.c$54$1$1 ==.
                            870 ;	apps/serial_i2c/serial_i2c.c:54: uint16 lastCmd = 0;
   04EC 78 00               871 	mov	r0,#_lastCmd
   04EE E4                  872 	clr	a
   04EF F2                  873 	movx	@r0,a
   04F0 08                  874 	inc	r0
   04F1 F2                  875 	movx	@r0,a
                    000C    876 	G$main$0$0 ==.
                    000C    877 	C$serial_i2c.c$70$1$1 ==.
                            878 ;	apps/serial_i2c/serial_i2c.c:70: static uint8 errors = 0;
   04F2 78 02               879 	mov	r0,#_errors
   04F4 E4                  880 	clr	a
   04F5 F2                  881 	movx	@r0,a
                    0010    882 	G$main$0$0 ==.
                    0010    883 	C$serial_i2c.c$72$1$1 ==.
                            884 ;	apps/serial_i2c/serial_i2c.c:72: static uint8 response = 0;
   04F6 78 03               885 	mov	r0,#_response
   04F8 E4                  886 	clr	a
   04F9 F2                  887 	movx	@r0,a
                    0014    888 	G$main$0$0 ==.
                    0014    889 	C$serial_i2c.c$76$1$1 ==.
                            890 ;	apps/serial_i2c/serial_i2c.c:76: enum i2cState state = IDLE;
   04FA 78 04               891 	mov	r0,#_state
   04FC E4                  892 	clr	a
   04FD F2                  893 	movx	@r0,a
                    0018    894 	G$main$0$0 ==.
                    0018    895 	C$serial_i2c.c$80$1$1 ==.
                            896 ;	apps/serial_i2c/serial_i2c.c:80: static uint8 dataLength = 0;
   04FE 78 05               897 	mov	r0,#_dataLength
   0500 E4                  898 	clr	a
   0501 F2                  899 	movx	@r0,a
                    001C    900 	G$main$0$0 ==.
                    001C    901 	C$serial_i2c.c$83$1$1 ==.
                            902 ;	apps/serial_i2c/serial_i2c.c:83: uint8 (*rxAvailableFunction)(void)   = NULL;
   0502 78 06               903 	mov	r0,#_rxAvailableFunction
   0504 E4                  904 	clr	a
   0505 F2                  905 	movx	@r0,a
   0506 08                  906 	inc	r0
   0507 F2                  907 	movx	@r0,a
                    0022    908 	G$main$0$0 ==.
                    0022    909 	C$serial_i2c.c$84$1$1 ==.
                            910 ;	apps/serial_i2c/serial_i2c.c:84: uint8 (*rxReceiveByteFunction)(void) = NULL;
   0508 78 08               911 	mov	r0,#_rxReceiveByteFunction
   050A E4                  912 	clr	a
   050B F2                  913 	movx	@r0,a
   050C 08                  914 	inc	r0
   050D F2                  915 	movx	@r0,a
                    0028    916 	G$main$0$0 ==.
                    0028    917 	C$serial_i2c.c$85$1$1 ==.
                            918 ;	apps/serial_i2c/serial_i2c.c:85: uint8 (*txAvailableFunction)(void)   = NULL;
   050E 78 0A               919 	mov	r0,#_txAvailableFunction
   0510 E4                  920 	clr	a
   0511 F2                  921 	movx	@r0,a
   0512 08                  922 	inc	r0
   0513 F2                  923 	movx	@r0,a
                    002E    924 	G$main$0$0 ==.
                    002E    925 	C$serial_i2c.c$86$1$1 ==.
                            926 ;	apps/serial_i2c/serial_i2c.c:86: void  (*txSendByteFunction)(uint8)   = NULL;
   0514 78 0C               927 	mov	r0,#_txSendByteFunction
   0516 E4                  928 	clr	a
   0517 F2                  929 	movx	@r0,a
   0518 08                  930 	inc	r0
   0519 F2                  931 	movx	@r0,a
                            932 	.area GSFINAL (CODE)
   0591 02 04 86            933 	ljmp	__sdcc_program_startup
                            934 ;--------------------------------------------------------
                            935 ; Home
                            936 ;--------------------------------------------------------
                            937 	.area HOME    (CODE)
                            938 	.area HOME    (CODE)
   0486                     939 __sdcc_program_startup:
   0486 12 07 E9            940 	lcall	_main
                            941 ;	return from main will lock up
   0489 80 FE               942 	sjmp .
                            943 ;--------------------------------------------------------
                            944 ; code
                            945 ;--------------------------------------------------------
                            946 	.area CSEG    (CODE)
                            947 ;------------------------------------------------------------
                            948 ;Allocation info for local variables in function 'updateLeds'
                            949 ;------------------------------------------------------------
                    0000    950 	G$updateLeds$0$0 ==.
                    0000    951 	C$serial_i2c.c$90$0$0 ==.
                            952 ;	apps/serial_i2c/serial_i2c.c:90: void updateLeds(void)
                            953 ;	-----------------------------------------
                            954 ;	 function updateLeds
                            955 ;	-----------------------------------------
   0594                     956 _updateLeds:
                    0007    957 	ar7 = 0x07
                    0006    958 	ar6 = 0x06
                    0005    959 	ar5 = 0x05
                    0004    960 	ar4 = 0x04
                    0003    961 	ar3 = 0x03
                    0002    962 	ar2 = 0x02
                    0001    963 	ar1 = 0x01
                    0000    964 	ar0 = 0x00
                    0000    965 	C$serial_i2c.c$92$1$1 ==.
                            966 ;	apps/serial_i2c/serial_i2c.c:92: usbShowStatusWithGreenLed();
   0594 12 25 EB            967 	lcall	_usbShowStatusWithGreenLed
                    0003    968 	C$serial_i2c.c$94$2$2 ==.
                            969 ;	apps/serial_i2c/serial_i2c.c:94: LED_YELLOW(vinPowerPresent());
   0597 12 1A E0            970 	lcall	_vinPowerPresent
   059A 50 05               971 	jnc	00103$
   059C 43 FF 04            972 	orl	_P2DIR,#0x04
   059F 80 07               973 	sjmp	00104$
   05A1                     974 00103$:
   05A1 AF FF               975 	mov	r7,_P2DIR
   05A3 53 07 FB            976 	anl	ar7,#0xFB
   05A6 8F FF               977 	mov	_P2DIR,r7
   05A8                     978 00104$:
                    0014    979 	C$serial_i2c.c$95$2$3 ==.
                            980 ;	apps/serial_i2c/serial_i2c.c:95: LED_RED(errors);
   05A8 78 02               981 	mov	r0,#_errors
   05AA E2                  982 	movx	a,@r0
   05AB 60 05               983 	jz	00105$
   05AD 43 FF 02            984 	orl	_P2DIR,#0x02
   05B0 80 07               985 	sjmp	00101$
   05B2                     986 00105$:
   05B2 AF FF               987 	mov	r7,_P2DIR
   05B4 53 07 FD            988 	anl	ar7,#0xFD
   05B7 8F FF               989 	mov	_P2DIR,r7
   05B9                     990 00101$:
                    0025    991 	C$serial_i2c.c$96$2$3 ==.
                    0025    992 	XG$updateLeds$0$0 ==.
   05B9 22                  993 	ret
                            994 ;------------------------------------------------------------
                            995 ;Allocation info for local variables in function 'parseCmd'
                            996 ;------------------------------------------------------------
                    0026    997 	G$parseCmd$0$0 ==.
                    0026    998 	C$serial_i2c.c$98$2$3 ==.
                            999 ;	apps/serial_i2c/serial_i2c.c:98: void parseCmd(uint8 byte)
                           1000 ;	-----------------------------------------
                           1001 ;	 function parseCmd
                           1002 ;	-----------------------------------------
   05BA                    1003 _parseCmd:
   05BA AF 82              1004 	mov	r7,dpl
                    0028   1005 	C$serial_i2c.c$102$1$1 ==.
                           1006 ;	apps/serial_i2c/serial_i2c.c:102: switch (state)
   05BC 78 04              1007 	mov	r0,#_state
   05BE C3                 1008 	clr	c
   05BF E2                 1009 	movx	a,@r0
   05C0 F5 F0              1010 	mov	b,a
   05C2 74 03              1011 	mov	a,#0x03
   05C4 95 F0              1012 	subb	a,b
   05C6 50 03              1013 	jnc	00144$
   05C8 02 06 93           1014 	ljmp	00128$
   05CB                    1015 00144$:
   05CB 78 04              1016 	mov	r0,#_state
   05CD E2                 1017 	movx	a,@r0
   05CE 75 F0 03           1018 	mov	b,#0x03
   05D1 A4                 1019 	mul	ab
   05D2 90 05 D6           1020 	mov	dptr,#00145$
   05D5 73                 1021 	jmp	@a+dptr
   05D6                    1022 00145$:
   05D6 02 05 E2           1023 	ljmp	00101$
   05D9 02 06 22           1024 	ljmp	00109$
   05DC 02 06 4D           1025 	ljmp	00115$
   05DF 02 06 5D           1026 	ljmp	00116$
                    004E   1027 	C$serial_i2c.c$104$2$2 ==.
                           1028 ;	apps/serial_i2c/serial_i2c.c:104: case IDLE:
   05E2                    1029 00101$:
                    004E   1030 	C$serial_i2c.c$105$2$2 ==.
                           1031 ;	apps/serial_i2c/serial_i2c.c:105: switch ((char)byte)
   05E2 8F 06              1032 	mov	ar6,r7
   05E4 BE 45 02           1033 	cjne	r6,#0x45,00146$
   05E7 80 0A              1034 	sjmp	00102$
   05E9                    1035 00146$:
   05E9 BE 50 02           1036 	cjne	r6,#0x50,00147$
   05EC 80 22              1037 	sjmp	00104$
   05EE                    1038 00147$:
                    005A   1039 	C$serial_i2c.c$107$3$3 ==.
                           1040 ;	apps/serial_i2c/serial_i2c.c:107: case CMD_GET_ERRORS:
   05EE BE 53 29           1041 	cjne	r6,#0x53,00107$
   05F1 80 10              1042 	sjmp	00103$
   05F3                    1043 00102$:
                    005F   1044 	C$serial_i2c.c$108$3$3 ==.
                           1045 ;	apps/serial_i2c/serial_i2c.c:108: response = errors;
   05F3 78 02              1046 	mov	r0,#_errors
   05F5 E2                 1047 	movx	a,@r0
   05F6 FE                 1048 	mov	r6,a
   05F7 78 03              1049 	mov	r0,#_response
   05F9 F2                 1050 	movx	@r0,a
                    0066   1051 	C$serial_i2c.c$109$3$3 ==.
                           1052 ;	apps/serial_i2c/serial_i2c.c:109: returnResponse = 1;
   05FA D2 00              1053 	setb	_returnResponse
                    0068   1054 	C$serial_i2c.c$110$3$3 ==.
                           1055 ;	apps/serial_i2c/serial_i2c.c:110: errors = 0;
   05FC 78 02              1056 	mov	r0,#_errors
   05FE E4                 1057 	clr	a
   05FF F2                 1058 	movx	@r0,a
                    006C   1059 	C$serial_i2c.c$111$3$3 ==.
                           1060 ;	apps/serial_i2c/serial_i2c.c:111: break;
   0600 02 06 93           1061 	ljmp	00128$
                    006F   1062 	C$serial_i2c.c$113$3$3 ==.
                           1063 ;	apps/serial_i2c/serial_i2c.c:113: case CMD_START:
   0603                    1064 00103$:
                    006F   1065 	C$serial_i2c.c$114$3$3 ==.
                           1066 ;	apps/serial_i2c/serial_i2c.c:114: i2cStart();
   0603 12 0D 22           1067 	lcall	_i2cStart
                    0072   1068 	C$serial_i2c.c$115$3$3 ==.
                           1069 ;	apps/serial_i2c/serial_i2c.c:115: started = 1;
   0606 D2 01              1070 	setb	_started
                    0074   1071 	C$serial_i2c.c$116$3$3 ==.
                           1072 ;	apps/serial_i2c/serial_i2c.c:116: state = GET_ADDR;
   0608 78 04              1073 	mov	r0,#_state
   060A 74 01              1074 	mov	a,#0x01
   060C F2                 1075 	movx	@r0,a
                    0079   1076 	C$serial_i2c.c$117$3$3 ==.
                           1077 ;	apps/serial_i2c/serial_i2c.c:117: break;
   060D 02 06 93           1078 	ljmp	00128$
                    007C   1079 	C$serial_i2c.c$119$3$3 ==.
                           1080 ;	apps/serial_i2c/serial_i2c.c:119: case CMD_STOP:
   0610                    1081 00104$:
                    007C   1082 	C$serial_i2c.c$120$3$3 ==.
                           1083 ;	apps/serial_i2c/serial_i2c.c:120: if (started)
   0610 30 01 07           1084 	jnb	_started,00107$
                    007F   1085 	C$serial_i2c.c$122$4$4 ==.
                           1086 ;	apps/serial_i2c/serial_i2c.c:122: i2cStop();
   0613 12 0C ED           1087 	lcall	_i2cStop
                    0082   1088 	C$serial_i2c.c$123$4$4 ==.
                           1089 ;	apps/serial_i2c/serial_i2c.c:123: started = 0;
   0616 C2 01              1090 	clr	_started
                    0084   1091 	C$serial_i2c.c$124$4$4 ==.
                           1092 ;	apps/serial_i2c/serial_i2c.c:124: break;
                    0084   1093 	C$serial_i2c.c$129$3$3 ==.
                           1094 ;	apps/serial_i2c/serial_i2c.c:129: default:
   0618 80 79              1095 	sjmp	00128$
   061A                    1096 00107$:
                    0086   1097 	C$serial_i2c.c$130$3$3 ==.
                           1098 ;	apps/serial_i2c/serial_i2c.c:130: errors |= ERR_CMD_INVALID;
   061A 78 02              1099 	mov	r0,#_errors
   061C E2                 1100 	movx	a,@r0
   061D 44 08              1101 	orl	a,#0x08
   061F F2                 1102 	movx	@r0,a
                    008C   1103 	C$serial_i2c.c$133$2$2 ==.
                           1104 ;	apps/serial_i2c/serial_i2c.c:133: break;
                    008C   1105 	C$serial_i2c.c$135$2$2 ==.
                           1106 ;	apps/serial_i2c/serial_i2c.c:135: case GET_ADDR:
   0620 80 71              1107 	sjmp	00128$
   0622                    1108 00109$:
                    008E   1109 	C$serial_i2c.c$137$2$2 ==.
                           1110 ;	apps/serial_i2c/serial_i2c.c:137: dataDirIsRead = byte & 1; // lowest bit of slave address determines direction (0 = write, 1 = read)
   0622 EF                 1111 	mov	a,r7
   0623 54 01              1112 	anl	a,#0x01
   0625 24 FF              1113 	add	a,#0xff
   0627 92 02              1114 	mov	_dataDirIsRead,c
                    0095   1115 	C$serial_i2c.c$138$2$2 ==.
                           1116 ;	apps/serial_i2c/serial_i2c.c:138: nack = i2cWriteByte(byte);
   0629 8F 82              1117 	mov	dpl,r7
   062B 12 0D D3           1118 	lcall	_i2cWriteByte
   062E 92 03              1119 	mov	_parseCmd_nack_1_1,c
                    009C   1120 	C$serial_i2c.c$140$2$2 ==.
                           1121 ;	apps/serial_i2c/serial_i2c.c:140: if (i2cTimeoutOccurred)
   0630 30 09 0A           1122 	jnb	_i2cTimeoutOccurred,00113$
                    009F   1123 	C$serial_i2c.c$142$3$5 ==.
                           1124 ;	apps/serial_i2c/serial_i2c.c:142: errors |= ERR_I2C_TIMEOUT;
   0633 78 02              1125 	mov	r0,#_errors
   0635 E2                 1126 	movx	a,@r0
   0636 44 04              1127 	orl	a,#0x04
   0638 F2                 1128 	movx	@r0,a
                    00A5   1129 	C$serial_i2c.c$143$3$5 ==.
                           1130 ;	apps/serial_i2c/serial_i2c.c:143: i2cTimeoutOccurred = 0;
   0639 C2 09              1131 	clr	_i2cTimeoutOccurred
   063B 80 09              1132 	sjmp	00114$
   063D                    1133 00113$:
                    00A9   1134 	C$serial_i2c.c$145$2$2 ==.
                           1135 ;	apps/serial_i2c/serial_i2c.c:145: else if (nack)
   063D 30 03 06           1136 	jnb	_parseCmd_nack_1_1,00114$
                    00AC   1137 	C$serial_i2c.c$147$3$6 ==.
                           1138 ;	apps/serial_i2c/serial_i2c.c:147: errors |= ERR_I2C_NACK_ADDRESS;
   0640 78 02              1139 	mov	r0,#_errors
   0642 E2                 1140 	movx	a,@r0
   0643 44 01              1141 	orl	a,#0x01
   0645 F2                 1142 	movx	@r0,a
   0646                    1143 00114$:
                    00B2   1144 	C$serial_i2c.c$149$2$2 ==.
                           1145 ;	apps/serial_i2c/serial_i2c.c:149: state = GET_LEN;
   0646 78 04              1146 	mov	r0,#_state
   0648 74 02              1147 	mov	a,#0x02
   064A F2                 1148 	movx	@r0,a
                    00B7   1149 	C$serial_i2c.c$150$2$2 ==.
                           1150 ;	apps/serial_i2c/serial_i2c.c:150: break;
                    00B7   1151 	C$serial_i2c.c$152$2$2 ==.
                           1152 ;	apps/serial_i2c/serial_i2c.c:152: case GET_LEN:
   064B 80 46              1153 	sjmp	00128$
   064D                    1154 00115$:
                    00B9   1155 	C$serial_i2c.c$154$2$2 ==.
                           1156 ;	apps/serial_i2c/serial_i2c.c:154: dataLength = byte;
   064D 78 05              1157 	mov	r0,#_dataLength
   064F EF                 1158 	mov	a,r7
   0650 F2                 1159 	movx	@r0,a
                    00BD   1160 	C$serial_i2c.c$155$2$2 ==.
                           1161 ;	apps/serial_i2c/serial_i2c.c:155: state = (dataLength > 0) ? GET_DATA : IDLE;
   0651 EF                 1162 	mov	a,r7
   0652 60 02              1163 	jz	00130$
   0654 74 03              1164 	mov	a,#0x03
   0656                    1165 00130$:
   0656 FE                 1166 	mov	r6,a
   0657 78 04              1167 	mov	r0,#_state
   0659 EE                 1168 	mov	a,r6
   065A F2                 1169 	movx	@r0,a
                    00C7   1170 	C$serial_i2c.c$156$2$2 ==.
                           1171 ;	apps/serial_i2c/serial_i2c.c:156: break;
                    00C7   1172 	C$serial_i2c.c$158$2$2 ==.
                           1173 ;	apps/serial_i2c/serial_i2c.c:158: case GET_DATA:
   065B 80 36              1174 	sjmp	00128$
   065D                    1175 00116$:
                    00C9   1176 	C$serial_i2c.c$159$2$2 ==.
                           1177 ;	apps/serial_i2c/serial_i2c.c:159: if (dataDirIsRead)
   065D 30 02 08           1178 	jnb	_dataDirIsRead,00125$
                    00CC   1179 	C$serial_i2c.c$162$3$7 ==.
                           1180 ;	apps/serial_i2c/serial_i2c.c:162: errors |= ERR_CMD_INVALID;
   0660 78 02              1181 	mov	r0,#_errors
   0662 E2                 1182 	movx	a,@r0
   0663 44 08              1183 	orl	a,#0x08
   0665 F2                 1184 	movx	@r0,a
   0666 80 2B              1185 	sjmp	00128$
   0668                    1186 00125$:
                    00D4   1187 	C$serial_i2c.c$167$3$8 ==.
                           1188 ;	apps/serial_i2c/serial_i2c.c:167: nack = i2cWriteByte(byte);
   0668 8F 82              1189 	mov	dpl,r7
   066A 12 0D D3           1190 	lcall	_i2cWriteByte
   066D 92 03              1191 	mov	_parseCmd_nack_1_1,c
                    00DB   1192 	C$serial_i2c.c$168$3$8 ==.
                           1193 ;	apps/serial_i2c/serial_i2c.c:168: if (i2cTimeoutOccurred)
   066F 30 09 0A           1194 	jnb	_i2cTimeoutOccurred,00120$
                    00DE   1195 	C$serial_i2c.c$170$4$9 ==.
                           1196 ;	apps/serial_i2c/serial_i2c.c:170: errors |= ERR_I2C_TIMEOUT;
   0672 78 02              1197 	mov	r0,#_errors
   0674 E2                 1198 	movx	a,@r0
   0675 44 04              1199 	orl	a,#0x04
   0677 F2                 1200 	movx	@r0,a
                    00E4   1201 	C$serial_i2c.c$171$4$9 ==.
                           1202 ;	apps/serial_i2c/serial_i2c.c:171: i2cTimeoutOccurred = 0;
   0678 C2 09              1203 	clr	_i2cTimeoutOccurred
   067A 80 09              1204 	sjmp	00121$
   067C                    1205 00120$:
                    00E8   1206 	C$serial_i2c.c$173$3$8 ==.
                           1207 ;	apps/serial_i2c/serial_i2c.c:173: else if (nack)
   067C 30 03 06           1208 	jnb	_parseCmd_nack_1_1,00121$
                    00EB   1209 	C$serial_i2c.c$175$4$10 ==.
                           1210 ;	apps/serial_i2c/serial_i2c.c:175: errors |= ERR_I2C_NACK_DATA;
   067F 78 02              1211 	mov	r0,#_errors
   0681 E2                 1212 	movx	a,@r0
   0682 44 02              1213 	orl	a,#0x02
   0684 F2                 1214 	movx	@r0,a
   0685                    1215 00121$:
                    00F1   1216 	C$serial_i2c.c$178$3$8 ==.
                           1217 ;	apps/serial_i2c/serial_i2c.c:178: if (--dataLength == 0)
   0685 78 05              1218 	mov	r0,#_dataLength
   0687 E2                 1219 	movx	a,@r0
   0688 14                 1220 	dec	a
   0689 F2                 1221 	movx	@r0,a
   068A 78 05              1222 	mov	r0,#_dataLength
   068C E2                 1223 	movx	a,@r0
   068D 70 04              1224 	jnz	00128$
                    00FB   1225 	C$serial_i2c.c$180$4$11 ==.
                           1226 ;	apps/serial_i2c/serial_i2c.c:180: state = IDLE;
   068F 78 04              1227 	mov	r0,#_state
   0691 E4                 1228 	clr	a
   0692 F2                 1229 	movx	@r0,a
                    00FF   1230 	C$serial_i2c.c$184$1$1 ==.
                           1231 ;	apps/serial_i2c/serial_i2c.c:184: }
   0693                    1232 00128$:
                    00FF   1233 	C$serial_i2c.c$185$1$1 ==.
                    00FF   1234 	XG$parseCmd$0$0 ==.
   0693 22                 1235 	ret
                           1236 ;------------------------------------------------------------
                           1237 ;Allocation info for local variables in function 'i2cRead'
                           1238 ;------------------------------------------------------------
                    0100   1239 	G$i2cRead$0$0 ==.
                    0100   1240 	C$serial_i2c.c$187$1$1 ==.
                           1241 ;	apps/serial_i2c/serial_i2c.c:187: void i2cRead(void)
                           1242 ;	-----------------------------------------
                           1243 ;	 function i2cRead
                           1244 ;	-----------------------------------------
   0694                    1245 _i2cRead:
                    0100   1246 	C$serial_i2c.c$192$1$1 ==.
                           1247 ;	apps/serial_i2c/serial_i2c.c:192: byte = i2cReadByte(dataLength == 1);
   0694 78 05              1248 	mov	r0,#_dataLength
   0696 E2                 1249 	movx	a,@r0
   0697 B4 01 03           1250 	cjne	a,#0x01,00110$
   069A D3                 1251 	setb	c
   069B 80 01              1252 	sjmp	00111$
   069D                    1253 00110$:
   069D C3                 1254 	clr	c
   069E                    1255 00111$:
   069E 92 04              1256 	mov  _i2cRead_sloc0_1_0,c
   06A0 92 0E              1257 	mov	_i2cReadByte_PARM_1,c
   06A2 12 0E 17           1258 	lcall	_i2cReadByte
   06A5 AF 82              1259 	mov	r7,dpl
                    0113   1260 	C$serial_i2c.c$193$1$1 ==.
                           1261 ;	apps/serial_i2c/serial_i2c.c:193: if (i2cTimeoutOccurred)
   06A7 30 09 0E           1262 	jnb	_i2cTimeoutOccurred,00102$
                    0116   1263 	C$serial_i2c.c$195$2$2 ==.
                           1264 ;	apps/serial_i2c/serial_i2c.c:195: errors |= ERR_I2C_TIMEOUT;
   06AA 78 02              1265 	mov	r0,#_errors
   06AC E2                 1266 	movx	a,@r0
   06AD 44 04              1267 	orl	a,#0x04
   06AF F2                 1268 	movx	@r0,a
                    011C   1269 	C$serial_i2c.c$196$2$2 ==.
                           1270 ;	apps/serial_i2c/serial_i2c.c:196: i2cTimeoutOccurred = 0;
   06B0 C2 09              1271 	clr	_i2cTimeoutOccurred
                    011E   1272 	C$serial_i2c.c$197$2$2 ==.
                           1273 ;	apps/serial_i2c/serial_i2c.c:197: response = 0;
   06B2 78 03              1274 	mov	r0,#_response
   06B4 E4                 1275 	clr	a
   06B5 F2                 1276 	movx	@r0,a
   06B6 80 04              1277 	sjmp	00103$
   06B8                    1278 00102$:
                    0124   1279 	C$serial_i2c.c$201$2$3 ==.
                           1280 ;	apps/serial_i2c/serial_i2c.c:201: response = byte;
   06B8 78 03              1281 	mov	r0,#_response
   06BA EF                 1282 	mov	a,r7
   06BB F2                 1283 	movx	@r0,a
   06BC                    1284 00103$:
                    0128   1285 	C$serial_i2c.c$204$1$1 ==.
                           1286 ;	apps/serial_i2c/serial_i2c.c:204: if (--dataLength == 0)
   06BC 78 05              1287 	mov	r0,#_dataLength
   06BE E2                 1288 	movx	a,@r0
   06BF 14                 1289 	dec	a
   06C0 F2                 1290 	movx	@r0,a
   06C1 78 05              1291 	mov	r0,#_dataLength
   06C3 E2                 1292 	movx	a,@r0
   06C4 70 04              1293 	jnz	00105$
                    0132   1294 	C$serial_i2c.c$206$2$4 ==.
                           1295 ;	apps/serial_i2c/serial_i2c.c:206: state = IDLE;
   06C6 78 04              1296 	mov	r0,#_state
   06C8 E4                 1297 	clr	a
   06C9 F2                 1298 	movx	@r0,a
   06CA                    1299 00105$:
                    0136   1300 	C$serial_i2c.c$208$1$1 ==.
                           1301 ;	apps/serial_i2c/serial_i2c.c:208: returnResponse = 1;
   06CA D2 00              1302 	setb	_returnResponse
                    0138   1303 	C$serial_i2c.c$209$1$1 ==.
                    0138   1304 	XG$i2cRead$0$0 ==.
   06CC 22                 1305 	ret
                           1306 ;------------------------------------------------------------
                           1307 ;Allocation info for local variables in function 'i2cService'
                           1308 ;------------------------------------------------------------
                           1309 ;sloc0                     Allocated with name '_i2cService_sloc0_1_0'
                           1310 ;------------------------------------------------------------
                    0139   1311 	G$i2cService$0$0 ==.
                    0139   1312 	C$serial_i2c.c$212$1$1 ==.
                           1313 ;	apps/serial_i2c/serial_i2c.c:212: void i2cService(void)
                           1314 ;	-----------------------------------------
                           1315 ;	 function i2cService
                           1316 ;	-----------------------------------------
   06CD                    1317 _i2cService:
                    0139   1318 	C$serial_i2c.c$215$1$1 ==.
                           1319 ;	apps/serial_i2c/serial_i2c.c:215: if (!returnResponse)
   06CD 30 00 03           1320 	jnb	_returnResponse,00128$
   06D0 02 07 A4           1321 	ljmp	00113$
   06D3                    1322 00128$:
                    013F   1323 	C$serial_i2c.c$217$2$2 ==.
                           1324 ;	apps/serial_i2c/serial_i2c.c:217: if (dataDirIsRead && state == GET_DATA)
   06D3 30 02 0C           1325 	jnb	_dataDirIsRead,00109$
   06D6 78 04              1326 	mov	r0,#_state
   06D8 E2                 1327 	movx	a,@r0
   06D9 B4 03 06           1328 	cjne	a,#0x03,00109$
                    0148   1329 	C$serial_i2c.c$220$3$3 ==.
                           1330 ;	apps/serial_i2c/serial_i2c.c:220: i2cRead();
   06DC 12 06 94           1331 	lcall	_i2cRead
   06DF 02 07 A4           1332 	ljmp	00113$
   06E2                    1333 00109$:
                    014E   1334 	C$serial_i2c.c$222$2$2 ==.
                           1335 ;	apps/serial_i2c/serial_i2c.c:222: else if (rxAvailableFunction())
   06E2 78 06              1336 	mov	r0,#_rxAvailableFunction
   06E4 E2                 1337 	movx	a,@r0
   06E5 F5 82              1338 	mov	dpl,a
   06E7 08                 1339 	inc	r0
   06E8 E2                 1340 	movx	a,@r0
   06E9 F5 83              1341 	mov	dph,a
   06EB 12 04 8B           1342 	lcall	__sdcc_call_dptr
   06EE E5 82              1343 	mov	a,dpl
   06F0 FF                 1344 	mov	r7,a
   06F1 60 23              1345 	jz	00106$
                    015F   1346 	C$serial_i2c.c$225$3$4 ==.
                           1347 ;	apps/serial_i2c/serial_i2c.c:225: parseCmd(rxReceiveByteFunction());
   06F3 78 08              1348 	mov	r0,#_rxReceiveByteFunction
   06F5 E2                 1349 	movx	a,@r0
   06F6 F5 82              1350 	mov	dpl,a
   06F8 08                 1351 	inc	r0
   06F9 E2                 1352 	movx	a,@r0
   06FA F5 83              1353 	mov	dph,a
   06FC 12 04 8B           1354 	lcall	__sdcc_call_dptr
   06FF 12 05 BA           1355 	lcall	_parseCmd
                    016E   1356 	C$serial_i2c.c$226$3$4 ==.
                           1357 ;	apps/serial_i2c/serial_i2c.c:226: lastCmd = getMs(); // store the time of the last byte received
   0702 12 1E 01           1358 	lcall	_getMs
   0705 AC 82              1359 	mov	r4,dpl
   0707 AD 83              1360 	mov	r5,dph
   0709 AE F0              1361 	mov	r6,b
   070B FF                 1362 	mov	r7,a
   070C 78 00              1363 	mov	r0,#_lastCmd
   070E EC                 1364 	mov	a,r4
   070F F2                 1365 	movx	@r0,a
   0710 08                 1366 	inc	r0
   0711 ED                 1367 	mov	a,r5
   0712 F2                 1368 	movx	@r0,a
   0713 02 07 A4           1369 	ljmp	00113$
   0716                    1370 00106$:
                    0182   1371 	C$serial_i2c.c$228$2$2 ==.
                           1372 ;	apps/serial_i2c/serial_i2c.c:228: else if (started && (param_cmd_timeout_ms > 0) && ((uint16)(getMs() - lastCmd) > param_cmd_timeout_ms))
   0716 20 01 03           1373 	jb	_started,00135$
   0719 02 07 A4           1374 	ljmp	00113$
   071C                    1375 00135$:
   071C 90 27 B7           1376 	mov	dptr,#_param_cmd_timeout_ms
   071F E4                 1377 	clr	a
   0720 93                 1378 	movc	a,@a+dptr
   0721 FC                 1379 	mov	r4,a
   0722 74 01              1380 	mov	a,#0x01
   0724 93                 1381 	movc	a,@a+dptr
   0725 FD                 1382 	mov	r5,a
   0726 74 02              1383 	mov	a,#0x02
   0728 93                 1384 	movc	a,@a+dptr
   0729 FE                 1385 	mov	r6,a
   072A 74 03              1386 	mov	a,#0x03
   072C 93                 1387 	movc	a,@a+dptr
   072D FF                 1388 	mov	r7,a
   072E C3                 1389 	clr	c
   072F E4                 1390 	clr	a
   0730 9C                 1391 	subb	a,r4
   0731 E4                 1392 	clr	a
   0732 9D                 1393 	subb	a,r5
   0733 E4                 1394 	clr	a
   0734 9E                 1395 	subb	a,r6
   0735 E4                 1396 	clr	a
   0736 64 80              1397 	xrl	a,#0x80
   0738 8F F0              1398 	mov	b,r7
   073A 63 F0 80           1399 	xrl	b,#0x80
   073D 95 F0              1400 	subb	a,b
   073F 50 63              1401 	jnc	00113$
   0741 12 1E 01           1402 	lcall	_getMs
   0744 85 82 08           1403 	mov	_i2cService_sloc0_1_0,dpl
   0747 85 83 09           1404 	mov	(_i2cService_sloc0_1_0 + 1),dph
   074A 85 F0 0A           1405 	mov	(_i2cService_sloc0_1_0 + 2),b
   074D F5 0B              1406 	mov	(_i2cService_sloc0_1_0 + 3),a
   074F 78 00              1407 	mov	r0,#_lastCmd
   0751 E2                 1408 	movx	a,@r0
   0752 FA                 1409 	mov	r2,a
   0753 08                 1410 	inc	r0
   0754 E2                 1411 	movx	a,@r0
   0755 FB                 1412 	mov	r3,a
   0756 E4                 1413 	clr	a
   0757 FE                 1414 	mov	r6,a
   0758 FF                 1415 	mov	r7,a
   0759 E5 08              1416 	mov	a,_i2cService_sloc0_1_0
   075B C3                 1417 	clr	c
   075C 9A                 1418 	subb	a,r2
   075D FA                 1419 	mov	r2,a
   075E E5 09              1420 	mov	a,(_i2cService_sloc0_1_0 + 1)
   0760 9B                 1421 	subb	a,r3
   0761 FB                 1422 	mov	r3,a
   0762 E5 0A              1423 	mov	a,(_i2cService_sloc0_1_0 + 2)
   0764 9E                 1424 	subb	a,r6
   0765 E5 0B              1425 	mov	a,(_i2cService_sloc0_1_0 + 3)
   0767 9F                 1426 	subb	a,r7
   0768 90 27 B7           1427 	mov	dptr,#_param_cmd_timeout_ms
   076B E4                 1428 	clr	a
   076C 93                 1429 	movc	a,@a+dptr
   076D F5 08              1430 	mov	_i2cService_sloc0_1_0,a
   076F 74 01              1431 	mov	a,#0x01
   0771 93                 1432 	movc	a,@a+dptr
   0772 F5 09              1433 	mov	(_i2cService_sloc0_1_0 + 1),a
   0774 74 02              1434 	mov	a,#0x02
   0776 93                 1435 	movc	a,@a+dptr
   0777 F5 0A              1436 	mov	(_i2cService_sloc0_1_0 + 2),a
   0779 74 03              1437 	mov	a,#0x03
   077B 93                 1438 	movc	a,@a+dptr
   077C F5 0B              1439 	mov	(_i2cService_sloc0_1_0 + 3),a
   077E 7E 00              1440 	mov	r6,#0x00
   0780 7F 00              1441 	mov	r7,#0x00
   0782 C3                 1442 	clr	c
   0783 E5 08              1443 	mov	a,_i2cService_sloc0_1_0
   0785 9A                 1444 	subb	a,r2
   0786 E5 09              1445 	mov	a,(_i2cService_sloc0_1_0 + 1)
   0788 9B                 1446 	subb	a,r3
   0789 E5 0A              1447 	mov	a,(_i2cService_sloc0_1_0 + 2)
   078B 9E                 1448 	subb	a,r6
   078C E5 0B              1449 	mov	a,(_i2cService_sloc0_1_0 + 3)
   078E 64 80              1450 	xrl	a,#0x80
   0790 8F F0              1451 	mov	b,r7
   0792 63 F0 80           1452 	xrl	b,#0x80
   0795 95 F0              1453 	subb	a,b
   0797 50 0B              1454 	jnc	00113$
                    0205   1455 	C$serial_i2c.c$231$3$5 ==.
                           1456 ;	apps/serial_i2c/serial_i2c.c:231: i2cStop();
   0799 12 0C ED           1457 	lcall	_i2cStop
                    0208   1458 	C$serial_i2c.c$232$3$5 ==.
                           1459 ;	apps/serial_i2c/serial_i2c.c:232: started = 0;
   079C C2 01              1460 	clr	_started
                    020A   1461 	C$serial_i2c.c$233$3$5 ==.
                           1462 ;	apps/serial_i2c/serial_i2c.c:233: errors |= ERR_CMD_TIMEOUT;
   079E 78 02              1463 	mov	r0,#_errors
   07A0 E2                 1464 	movx	a,@r0
   07A1 44 10              1465 	orl	a,#0x10
   07A3 F2                 1466 	movx	@r0,a
   07A4                    1467 00113$:
                    0210   1468 	C$serial_i2c.c$237$1$1 ==.
                           1469 ;	apps/serial_i2c/serial_i2c.c:237: if (returnResponse && txAvailableFunction())
   07A4 30 00 2A           1470 	jnb	_returnResponse,00117$
   07A7 78 0A              1471 	mov	r0,#_txAvailableFunction
   07A9 E2                 1472 	movx	a,@r0
   07AA F5 82              1473 	mov	dpl,a
   07AC 08                 1474 	inc	r0
   07AD E2                 1475 	movx	a,@r0
   07AE F5 83              1476 	mov	dph,a
   07B0 12 04 8B           1477 	lcall	__sdcc_call_dptr
   07B3 E5 82              1478 	mov	a,dpl
   07B5 FF                 1479 	mov	r7,a
   07B6 60 19              1480 	jz	00117$
                    0224   1481 	C$serial_i2c.c$239$2$6 ==.
                           1482 ;	apps/serial_i2c/serial_i2c.c:239: txSendByteFunction(response);
   07B8 74 CF              1483 	mov	a,#00141$
   07BA C0 E0              1484 	push	acc
   07BC 74 07              1485 	mov	a,#(00141$ >> 8)
   07BE C0 E0              1486 	push	acc
   07C0 78 0C              1487 	mov	r0,#_txSendByteFunction
   07C2 E2                 1488 	movx	a,@r0
   07C3 C0 E0              1489 	push	acc
   07C5 08                 1490 	inc	r0
   07C6 E2                 1491 	movx	a,@r0
   07C7 C0 E0              1492 	push	acc
   07C9 78 03              1493 	mov	r0,#_response
   07CB E2                 1494 	movx	a,@r0
   07CC F5 82              1495 	mov	dpl,a
   07CE 22                 1496 	ret
   07CF                    1497 00141$:
                    023B   1498 	C$serial_i2c.c$240$2$6 ==.
                           1499 ;	apps/serial_i2c/serial_i2c.c:240: returnResponse = 0;
   07CF C2 00              1500 	clr	_returnResponse
   07D1                    1501 00117$:
                    023D   1502 	C$serial_i2c.c$242$2$1 ==.
                    023D   1503 	XG$i2cService$0$0 ==.
   07D1 22                 1504 	ret
                           1505 ;------------------------------------------------------------
                           1506 ;Allocation info for local variables in function 'uartCheckErrors'
                           1507 ;------------------------------------------------------------
                    023E   1508 	G$uartCheckErrors$0$0 ==.
                    023E   1509 	C$serial_i2c.c$244$2$1 ==.
                           1510 ;	apps/serial_i2c/serial_i2c.c:244: void uartCheckErrors(void)
                           1511 ;	-----------------------------------------
                           1512 ;	 function uartCheckErrors
                           1513 ;	-----------------------------------------
   07D2                    1514 _uartCheckErrors:
                    023E   1515 	C$serial_i2c.c$246$1$1 ==.
                           1516 ;	apps/serial_i2c/serial_i2c.c:246: if (uart1RxBufferFullOccurred)
   07D2 30 07 08           1517 	jnb	_uart1RxBufferFullOccurred,00102$
                    0241   1518 	C$serial_i2c.c$248$2$2 ==.
                           1519 ;	apps/serial_i2c/serial_i2c.c:248: errors |= ERR_UART_OVERFLOW;
   07D5 78 02              1520 	mov	r0,#_errors
   07D7 E2                 1521 	movx	a,@r0
   07D8 44 20              1522 	orl	a,#0x20
   07DA F2                 1523 	movx	@r0,a
                    0247   1524 	C$serial_i2c.c$249$2$2 ==.
                           1525 ;	apps/serial_i2c/serial_i2c.c:249: uart1RxBufferFullOccurred = 0;
   07DB C2 07              1526 	clr	_uart1RxBufferFullOccurred
   07DD                    1527 00102$:
                    0249   1528 	C$serial_i2c.c$251$1$1 ==.
                           1529 ;	apps/serial_i2c/serial_i2c.c:251: if (uart1RxFramingErrorOccurred)
   07DD 30 06 08           1530 	jnb	_uart1RxFramingErrorOccurred,00105$
                    024C   1531 	C$serial_i2c.c$253$2$3 ==.
                           1532 ;	apps/serial_i2c/serial_i2c.c:253: errors |= ERR_UART_FRAMING;
   07E0 78 02              1533 	mov	r0,#_errors
   07E2 E2                 1534 	movx	a,@r0
   07E3 44 40              1535 	orl	a,#0x40
   07E5 F2                 1536 	movx	@r0,a
                    0252   1537 	C$serial_i2c.c$254$2$3 ==.
                           1538 ;	apps/serial_i2c/serial_i2c.c:254: uart1RxFramingErrorOccurred = 0;
   07E6 C2 06              1539 	clr	_uart1RxFramingErrorOccurred
   07E8                    1540 00105$:
                    0254   1541 	C$serial_i2c.c$256$2$1 ==.
                    0254   1542 	XG$uartCheckErrors$0$0 ==.
   07E8 22                 1543 	ret
                           1544 ;------------------------------------------------------------
                           1545 ;Allocation info for local variables in function 'main'
                           1546 ;------------------------------------------------------------
                    0255   1547 	G$main$0$0 ==.
                    0255   1548 	C$serial_i2c.c$258$2$1 ==.
                           1549 ;	apps/serial_i2c/serial_i2c.c:258: void main(void)
                           1550 ;	-----------------------------------------
                           1551 ;	 function main
                           1552 ;	-----------------------------------------
   07E9                    1553 _main:
                    0255   1554 	C$serial_i2c.c$260$1$1 ==.
                           1555 ;	apps/serial_i2c/serial_i2c.c:260: systemInit();
   07E9 12 1A 16           1556 	lcall	_systemInit
                    0258   1557 	C$serial_i2c.c$261$1$1 ==.
                           1558 ;	apps/serial_i2c/serial_i2c.c:261: usbInit();
   07EC 12 13 B0           1559 	lcall	_usbInit
                    025B   1560 	C$serial_i2c.c$263$1$1 ==.
                           1561 ;	apps/serial_i2c/serial_i2c.c:263: i2cPinScl = param_I2C_SCL_pin;
   07EF 90 27 A7           1562 	mov	dptr,#_param_I2C_SCL_pin
   07F2 E4                 1563 	clr	a
   07F3 93                 1564 	movc	a,@a+dptr
   07F4 FC                 1565 	mov	r4,a
   07F5 74 01              1566 	mov	a,#0x01
   07F7 93                 1567 	movc	a,@a+dptr
   07F8 74 02              1568 	mov	a,#0x02
   07FA 93                 1569 	movc	a,@a+dptr
   07FB 74 03              1570 	mov	a,#0x03
   07FD 93                 1571 	movc	a,@a+dptr
   07FE 8C 14              1572 	mov	_i2cPinScl,r4
                    026C   1573 	C$serial_i2c.c$264$1$1 ==.
                           1574 ;	apps/serial_i2c/serial_i2c.c:264: i2cPinSda = param_I2C_SDA_pin;
   0800 90 27 AB           1575 	mov	dptr,#_param_I2C_SDA_pin
   0803 E4                 1576 	clr	a
   0804 93                 1577 	movc	a,@a+dptr
   0805 FC                 1578 	mov	r4,a
   0806 74 01              1579 	mov	a,#0x01
   0808 93                 1580 	movc	a,@a+dptr
   0809 74 02              1581 	mov	a,#0x02
   080B 93                 1582 	movc	a,@a+dptr
   080C 74 03              1583 	mov	a,#0x03
   080E 93                 1584 	movc	a,@a+dptr
   080F 8C 15              1585 	mov	_i2cPinSda,r4
                    027D   1586 	C$serial_i2c.c$266$1$1 ==.
                           1587 ;	apps/serial_i2c/serial_i2c.c:266: i2cSetFrequency(param_I2C_freq_kHz);
   0811 90 27 AF           1588 	mov	dptr,#_param_I2C_freq_kHz
   0814 E4                 1589 	clr	a
   0815 93                 1590 	movc	a,@a+dptr
   0816 FC                 1591 	mov	r4,a
   0817 74 01              1592 	mov	a,#0x01
   0819 93                 1593 	movc	a,@a+dptr
   081A FD                 1594 	mov	r5,a
   081B 74 02              1595 	mov	a,#0x02
   081D 93                 1596 	movc	a,@a+dptr
   081E 74 03              1597 	mov	a,#0x03
   0820 93                 1598 	movc	a,@a+dptr
   0821 8C 82              1599 	mov	dpl,r4
   0823 8D 83              1600 	mov	dph,r5
   0825 12 0B EB           1601 	lcall	_i2cSetFrequency
                    0294   1602 	C$serial_i2c.c$267$1$1 ==.
                           1603 ;	apps/serial_i2c/serial_i2c.c:267: i2cSetTimeout(param_I2C_timeout_ms);
   0828 90 27 B3           1604 	mov	dptr,#_param_I2C_timeout_ms
   082B E4                 1605 	clr	a
   082C 93                 1606 	movc	a,@a+dptr
   082D FC                 1607 	mov	r4,a
   082E 74 01              1608 	mov	a,#0x01
   0830 93                 1609 	movc	a,@a+dptr
   0831 FD                 1610 	mov	r5,a
   0832 74 02              1611 	mov	a,#0x02
   0834 93                 1612 	movc	a,@a+dptr
   0835 74 03              1613 	mov	a,#0x03
   0837 93                 1614 	movc	a,@a+dptr
   0838 8C 82              1615 	mov	dpl,r4
   083A 8D 83              1616 	mov	dph,r5
   083C 12 0C 1E           1617 	lcall	_i2cSetTimeout
                    02AB   1618 	C$serial_i2c.c$269$1$1 ==.
                           1619 ;	apps/serial_i2c/serial_i2c.c:269: switch (param_bridge_mode)
   083F 90 27 9F           1620 	mov	dptr,#_param_bridge_mode
   0842 E4                 1621 	clr	a
   0843 93                 1622 	movc	a,@a+dptr
   0844 FC                 1623 	mov	r4,a
   0845 74 01              1624 	mov	a,#0x01
   0847 93                 1625 	movc	a,@a+dptr
   0848 FD                 1626 	mov	r5,a
   0849 74 02              1627 	mov	a,#0x02
   084B 93                 1628 	movc	a,@a+dptr
   084C FE                 1629 	mov	r6,a
   084D 74 03              1630 	mov	a,#0x03
   084F 93                 1631 	movc	a,@a+dptr
   0850 FF                 1632 	mov	r7,a
   0851 BC 00 0B           1633 	cjne	r4,#0x00,00119$
   0854 BD 00 08           1634 	cjne	r5,#0x00,00119$
   0857 BE 00 05           1635 	cjne	r6,#0x00,00119$
   085A BF 00 02           1636 	cjne	r7,#0x00,00119$
   085D 80 20              1637 	sjmp	00101$
   085F                    1638 00119$:
   085F BC 01 0B           1639 	cjne	r4,#0x01,00120$
   0862 BD 00 08           1640 	cjne	r5,#0x00,00120$
   0865 BE 00 05           1641 	cjne	r6,#0x00,00120$
   0868 BF 00 02           1642 	cjne	r7,#0x00,00120$
   086B 80 43              1643 	sjmp	00102$
   086D                    1644 00120$:
   086D BC 02 0C           1645 	cjne	r4,#0x02,00121$
   0870 BD 00 09           1646 	cjne	r5,#0x00,00121$
   0873 BE 00 06           1647 	cjne	r6,#0x00,00121$
   0876 BF 00 03           1648 	cjne	r7,#0x00,00121$
   0879 02 08 FB           1649 	ljmp	00103$
   087C                    1650 00121$:
   087C 02 09 27           1651 	ljmp	00109$
                    02EB   1652 	C$serial_i2c.c$271$2$2 ==.
                           1653 ;	apps/serial_i2c/serial_i2c.c:271: case BRIDGE_MODE_RADIO_I2C:
   087F                    1654 00101$:
                    02EB   1655 	C$serial_i2c.c$272$2$2 ==.
                           1656 ;	apps/serial_i2c/serial_i2c.c:272: radioComInit();
   087F 12 1B 08           1657 	lcall	_radioComInit
                    02EE   1658 	C$serial_i2c.c$273$2$2 ==.
                           1659 ;	apps/serial_i2c/serial_i2c.c:273: rxAvailableFunction   = radioComRxAvailable;
   0882 7E 73              1660 	mov	r6,#_radioComRxAvailable
   0884 7F 1B              1661 	mov	r7,#(_radioComRxAvailable >> 8)
   0886 78 06              1662 	mov	r0,#_rxAvailableFunction
   0888 EE                 1663 	mov	a,r6
   0889 F2                 1664 	movx	@r0,a
   088A 08                 1665 	inc	r0
   088B EF                 1666 	mov	a,r7
   088C F2                 1667 	movx	@r0,a
                    02F9   1668 	C$serial_i2c.c$274$2$2 ==.
                           1669 ;	apps/serial_i2c/serial_i2c.c:274: rxReceiveByteFunction = radioComRxReceiveByte;
   088D 7E 7A              1670 	mov	r6,#_radioComRxReceiveByte
   088F 7F 1B              1671 	mov	r7,#(_radioComRxReceiveByte >> 8)
   0891 78 08              1672 	mov	r0,#_rxReceiveByteFunction
   0893 EE                 1673 	mov	a,r6
   0894 F2                 1674 	movx	@r0,a
   0895 08                 1675 	inc	r0
   0896 EF                 1676 	mov	a,r7
   0897 F2                 1677 	movx	@r0,a
                    0304   1678 	C$serial_i2c.c$275$2$2 ==.
                           1679 ;	apps/serial_i2c/serial_i2c.c:275: txAvailableFunction   = radioComTxAvailable;
   0898 7E 02              1680 	mov	r6,#_radioComTxAvailable
   089A 7F 1C              1681 	mov	r7,#(_radioComTxAvailable >> 8)
   089C 78 0A              1682 	mov	r0,#_txAvailableFunction
   089E EE                 1683 	mov	a,r6
   089F F2                 1684 	movx	@r0,a
   08A0 08                 1685 	inc	r0
   08A1 EF                 1686 	mov	a,r7
   08A2 F2                 1687 	movx	@r0,a
                    030F   1688 	C$serial_i2c.c$276$2$2 ==.
                           1689 ;	apps/serial_i2c/serial_i2c.c:276: txSendByteFunction    = radioComTxSendByte;
   08A3 7E 19              1690 	mov	r6,#_radioComTxSendByte
   08A5 7F 1C              1691 	mov	r7,#(_radioComTxSendByte >> 8)
   08A7 78 0C              1692 	mov	r0,#_txSendByteFunction
   08A9 EE                 1693 	mov	a,r6
   08AA F2                 1694 	movx	@r0,a
   08AB 08                 1695 	inc	r0
   08AC EF                 1696 	mov	a,r7
   08AD F2                 1697 	movx	@r0,a
                    031A   1698 	C$serial_i2c.c$277$2$2 ==.
                           1699 ;	apps/serial_i2c/serial_i2c.c:277: break;
                    031A   1700 	C$serial_i2c.c$278$2$2 ==.
                           1701 ;	apps/serial_i2c/serial_i2c.c:278: case BRIDGE_MODE_UART_I2C:
   08AE 80 77              1702 	sjmp	00109$
   08B0                    1703 00102$:
                    031C   1704 	C$serial_i2c.c$279$2$2 ==.
                           1705 ;	apps/serial_i2c/serial_i2c.c:279: uart1Init();
   08B0 12 09 6C           1706 	lcall	_uart1Init
                    031F   1707 	C$serial_i2c.c$280$2$2 ==.
                           1708 ;	apps/serial_i2c/serial_i2c.c:280: uart1SetBaudRate(param_baud_rate);
   08B3 90 27 A3           1709 	mov	dptr,#_param_baud_rate
   08B6 E4                 1710 	clr	a
   08B7 93                 1711 	movc	a,@a+dptr
   08B8 FC                 1712 	mov	r4,a
   08B9 74 01              1713 	mov	a,#0x01
   08BB 93                 1714 	movc	a,@a+dptr
   08BC FD                 1715 	mov	r5,a
   08BD 74 02              1716 	mov	a,#0x02
   08BF 93                 1717 	movc	a,@a+dptr
   08C0 FE                 1718 	mov	r6,a
   08C1 74 03              1719 	mov	a,#0x03
   08C3 93                 1720 	movc	a,@a+dptr
   08C4 8C 82              1721 	mov	dpl,r4
   08C6 8D 83              1722 	mov	dph,r5
   08C8 8E F0              1723 	mov	b,r6
   08CA 12 09 A0           1724 	lcall	_uart1SetBaudRate
                    0339   1725 	C$serial_i2c.c$281$2$2 ==.
                           1726 ;	apps/serial_i2c/serial_i2c.c:281: rxAvailableFunction   = uart1RxAvailable;
   08CD 7E 1F              1727 	mov	r6,#_uart1RxAvailable
   08CF 7F 0B              1728 	mov	r7,#(_uart1RxAvailable >> 8)
   08D1 78 06              1729 	mov	r0,#_rxAvailableFunction
   08D3 EE                 1730 	mov	a,r6
   08D4 F2                 1731 	movx	@r0,a
   08D5 08                 1732 	inc	r0
   08D6 EF                 1733 	mov	a,r7
   08D7 F2                 1734 	movx	@r0,a
                    0344   1735 	C$serial_i2c.c$282$2$2 ==.
                           1736 ;	apps/serial_i2c/serial_i2c.c:282: rxReceiveByteFunction = uart1RxReceiveByte;
   08D8 7E 27              1737 	mov	r6,#_uart1RxReceiveByte
   08DA 7F 0B              1738 	mov	r7,#(_uart1RxReceiveByte >> 8)
   08DC 78 08              1739 	mov	r0,#_rxReceiveByteFunction
   08DE EE                 1740 	mov	a,r6
   08DF F2                 1741 	movx	@r0,a
   08E0 08                 1742 	inc	r0
   08E1 EF                 1743 	mov	a,r7
   08E2 F2                 1744 	movx	@r0,a
                    034F   1745 	C$serial_i2c.c$283$2$2 ==.
                           1746 ;	apps/serial_i2c/serial_i2c.c:283: txAvailableFunction   = uart1TxAvailable;
   08E3 7E CB              1747 	mov	r6,#_uart1TxAvailable
   08E5 7F 0A              1748 	mov	r7,#(_uart1TxAvailable >> 8)
   08E7 78 0A              1749 	mov	r0,#_txAvailableFunction
   08E9 EE                 1750 	mov	a,r6
   08EA F2                 1751 	movx	@r0,a
   08EB 08                 1752 	inc	r0
   08EC EF                 1753 	mov	a,r7
   08ED F2                 1754 	movx	@r0,a
                    035A   1755 	C$serial_i2c.c$284$2$2 ==.
                           1756 ;	apps/serial_i2c/serial_i2c.c:284: txSendByteFunction    = uart1TxSendByte;
   08EE 7E 06              1757 	mov	r6,#_uart1TxSendByte
   08F0 7F 0B              1758 	mov	r7,#(_uart1TxSendByte >> 8)
   08F2 78 0C              1759 	mov	r0,#_txSendByteFunction
   08F4 EE                 1760 	mov	a,r6
   08F5 F2                 1761 	movx	@r0,a
   08F6 08                 1762 	inc	r0
   08F7 EF                 1763 	mov	a,r7
   08F8 F2                 1764 	movx	@r0,a
                    0365   1765 	C$serial_i2c.c$285$2$2 ==.
                           1766 ;	apps/serial_i2c/serial_i2c.c:285: break;
                    0365   1767 	C$serial_i2c.c$286$2$2 ==.
                           1768 ;	apps/serial_i2c/serial_i2c.c:286: case BRIDGE_MODE_USB_I2C:
   08F9 80 2C              1769 	sjmp	00109$
   08FB                    1770 00103$:
                    0367   1771 	C$serial_i2c.c$287$2$2 ==.
                           1772 ;	apps/serial_i2c/serial_i2c.c:287: rxAvailableFunction   = usbComRxAvailable;
   08FB 7E BD              1773 	mov	r6,#_usbComRxAvailable
   08FD 7F 11              1774 	mov	r7,#(_usbComRxAvailable >> 8)
   08FF 78 06              1775 	mov	r0,#_rxAvailableFunction
   0901 EE                 1776 	mov	a,r6
   0902 F2                 1777 	movx	@r0,a
   0903 08                 1778 	inc	r0
   0904 EF                 1779 	mov	a,r7
   0905 F2                 1780 	movx	@r0,a
                    0372   1781 	C$serial_i2c.c$288$2$2 ==.
                           1782 ;	apps/serial_i2c/serial_i2c.c:288: rxReceiveByteFunction = usbComRxReceiveByte;
   0906 7E E7              1783 	mov	r6,#_usbComRxReceiveByte
   0908 7F 11              1784 	mov	r7,#(_usbComRxReceiveByte >> 8)
   090A 78 08              1785 	mov	r0,#_rxReceiveByteFunction
   090C EE                 1786 	mov	a,r6
   090D F2                 1787 	movx	@r0,a
   090E 08                 1788 	inc	r0
   090F EF                 1789 	mov	a,r7
   0910 F2                 1790 	movx	@r0,a
                    037D   1791 	C$serial_i2c.c$289$2$2 ==.
                           1792 ;	apps/serial_i2c/serial_i2c.c:289: txAvailableFunction   = usbComTxAvailable;
   0911 7E F3              1793 	mov	r6,#_usbComTxAvailable
   0913 7F 12              1794 	mov	r7,#(_usbComTxAvailable >> 8)
   0915 78 0A              1795 	mov	r0,#_txAvailableFunction
   0917 EE                 1796 	mov	a,r6
   0918 F2                 1797 	movx	@r0,a
   0919 08                 1798 	inc	r0
   091A EF                 1799 	mov	a,r7
   091B F2                 1800 	movx	@r0,a
                    0388   1801 	C$serial_i2c.c$290$2$2 ==.
                           1802 ;	apps/serial_i2c/serial_i2c.c:290: txSendByteFunction    = usbComTxSendByte;
   091C 7E 85              1803 	mov	r6,#_usbComTxSendByte
   091E 7F 13              1804 	mov	r7,#(_usbComTxSendByte >> 8)
   0920 78 0C              1805 	mov	r0,#_txSendByteFunction
   0922 EE                 1806 	mov	a,r6
   0923 F2                 1807 	movx	@r0,a
   0924 08                 1808 	inc	r0
   0925 EF                 1809 	mov	a,r7
   0926 F2                 1810 	movx	@r0,a
                    0393   1811 	C$serial_i2c.c$294$1$1 ==.
                           1812 ;	apps/serial_i2c/serial_i2c.c:294: while (1)
   0927                    1813 00109$:
                    0393   1814 	C$serial_i2c.c$296$2$3 ==.
                           1815 ;	apps/serial_i2c/serial_i2c.c:296: boardService();
   0927 12 1A 23           1816 	lcall	_boardService
                    0396   1817 	C$serial_i2c.c$297$2$3 ==.
                           1818 ;	apps/serial_i2c/serial_i2c.c:297: updateLeds();
   092A 12 05 94           1819 	lcall	_updateLeds
                    0399   1820 	C$serial_i2c.c$299$2$3 ==.
                           1821 ;	apps/serial_i2c/serial_i2c.c:299: switch (param_bridge_mode)
   092D 90 27 9F           1822 	mov	dptr,#_param_bridge_mode
   0930 E4                 1823 	clr	a
   0931 93                 1824 	movc	a,@a+dptr
   0932 FC                 1825 	mov	r4,a
   0933 74 01              1826 	mov	a,#0x01
   0935 93                 1827 	movc	a,@a+dptr
   0936 FD                 1828 	mov	r5,a
   0937 74 02              1829 	mov	a,#0x02
   0939 93                 1830 	movc	a,@a+dptr
   093A FE                 1831 	mov	r6,a
   093B 74 03              1832 	mov	a,#0x03
   093D 93                 1833 	movc	a,@a+dptr
   093E FF                 1834 	mov	r7,a
   093F BC 00 0B           1835 	cjne	r4,#0x00,00122$
   0942 BD 00 08           1836 	cjne	r5,#0x00,00122$
   0945 BE 00 05           1837 	cjne	r6,#0x00,00122$
   0948 BF 00 02           1838 	cjne	r7,#0x00,00122$
   094B 80 0E              1839 	sjmp	00105$
   094D                    1840 00122$:
                    03B9   1841 	C$serial_i2c.c$301$3$4 ==.
                           1842 ;	apps/serial_i2c/serial_i2c.c:301: case BRIDGE_MODE_RADIO_I2C:
   094D BC 01 13           1843 	cjne	r4,#0x01,00107$
   0950 BD 00 10           1844 	cjne	r5,#0x00,00107$
   0953 BE 00 0D           1845 	cjne	r6,#0x00,00107$
   0956 BF 00 0A           1846 	cjne	r7,#0x00,00107$
   0959 80 05              1847 	sjmp	00106$
   095B                    1848 00105$:
                    03C7   1849 	C$serial_i2c.c$302$3$4 ==.
                           1850 ;	apps/serial_i2c/serial_i2c.c:302: radioComTxService();
   095B 12 1B D3           1851 	lcall	_radioComTxService
                    03CA   1852 	C$serial_i2c.c$303$3$4 ==.
                           1853 ;	apps/serial_i2c/serial_i2c.c:303: break;
                    03CA   1854 	C$serial_i2c.c$305$3$4 ==.
                           1855 ;	apps/serial_i2c/serial_i2c.c:305: case BRIDGE_MODE_UART_I2C:
   095E 80 03              1856 	sjmp	00107$
   0960                    1857 00106$:
                    03CC   1858 	C$serial_i2c.c$306$3$4 ==.
                           1859 ;	apps/serial_i2c/serial_i2c.c:306: uartCheckErrors();
   0960 12 07 D2           1860 	lcall	_uartCheckErrors
                    03CF   1861 	C$serial_i2c.c$308$2$3 ==.
                           1862 ;	apps/serial_i2c/serial_i2c.c:308: }
   0963                    1863 00107$:
                    03CF   1864 	C$serial_i2c.c$310$2$3 ==.
                           1865 ;	apps/serial_i2c/serial_i2c.c:310: usbComService();
   0963 12 12 4E           1866 	lcall	_usbComService
                    03D2   1867 	C$serial_i2c.c$312$2$3 ==.
                           1868 ;	apps/serial_i2c/serial_i2c.c:312: i2cService();
   0966 12 06 CD           1869 	lcall	_i2cService
   0969 80 BC              1870 	sjmp	00109$
                    03D7   1871 	C$serial_i2c.c$314$1$1 ==.
                    03D7   1872 	XG$main$0$0 ==.
   096B 22                 1873 	ret
                           1874 	.area CSEG    (CODE)
                           1875 	.area CONST   (CODE)
                    0000   1876 G$param_bridge_mode$0$0 == .
   279F                    1877 _param_bridge_mode:
   279F 00 00 00 00        1878 	.byte #0x00,#0x00,#0x00,#0x00	;  0
                    0004   1879 G$param_baud_rate$0$0 == .
   27A3                    1880 _param_baud_rate:
   27A3 80 25 00 00        1881 	.byte #0x80,#0x25,#0x00,#0x00	;  9600
                    0008   1882 G$param_I2C_SCL_pin$0$0 == .
   27A7                    1883 _param_I2C_SCL_pin:
   27A7 0A 00 00 00        1884 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    000C   1885 G$param_I2C_SDA_pin$0$0 == .
   27AB                    1886 _param_I2C_SDA_pin:
   27AB 0B 00 00 00        1887 	.byte #0x0B,#0x00,#0x00,#0x00	;  11
                    0010   1888 G$param_I2C_freq_kHz$0$0 == .
   27AF                    1889 _param_I2C_freq_kHz:
   27AF 64 00 00 00        1890 	.byte #0x64,#0x00,#0x00,#0x00	;  100
                    0014   1891 G$param_I2C_timeout_ms$0$0 == .
   27B3                    1892 _param_I2C_timeout_ms:
   27B3 0A 00 00 00        1893 	.byte #0x0A,#0x00,#0x00,#0x00	;  10
                    0018   1894 G$param_cmd_timeout_ms$0$0 == .
   27B7                    1895 _param_cmd_timeout_ms:
   27B7 F4 01 00 00        1896 	.byte #0xF4,#0x01,#0x00,#0x00	;  500
                           1897 	.area XINIT   (CODE)
                           1898 	.area CABS    (ABS,CODE)
