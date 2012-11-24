                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:43 2012
                              5 ;--------------------------------------------------------
                              6 	.module example_onewire
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _handleOneWire
                             14 	.globl _nibbleToAscii
                             15 	.globl _updateLeds
                             16 	.globl _read_DS1820
                             17 	.globl _setup_DS1820
                             18 	.globl _start_DS1820
                             19 	.globl _onewire_crc8
                             20 	.globl _onewire_search
                             21 	.globl _onewire_reset_search
                             22 	.globl _onewire_read
                             23 	.globl _onewire_write
                             24 	.globl _onewire_select
                             25 	.globl _onewire_reset
                             26 	.globl _onewire_start
                             27 	.globl _sprintf
                             28 	.globl _usbComTxSend
                             29 	.globl _usbComTxAvailable
                             30 	.globl _usbComService
                             31 	.globl _usbShowStatusWithGreenLed
                             32 	.globl _usbInit
                             33 	.globl _delayMs
                             34 	.globl _getMs
                             35 	.globl _boardService
                             36 	.globl _systemInit
                             37 	.globl _DS1820_addr
                             38 	.globl _ds1820_time
                             39 	.globl _is_DS18B20
                             40 	.globl _respondstr
                             41 ;--------------------------------------------------------
                             42 ; special function registers
                             43 ;--------------------------------------------------------
                             44 	.area RSEG    (ABS,DATA)
   0000                      45 	.org 0x0000
                    0080     46 Fexample_onewire$P0$0$0 == 0x0080
                    0080     47 _P0	=	0x0080
                    0081     48 Fexample_onewire$SP$0$0 == 0x0081
                    0081     49 _SP	=	0x0081
                    0082     50 Fexample_onewire$DPL0$0$0 == 0x0082
                    0082     51 _DPL0	=	0x0082
                    0083     52 Fexample_onewire$DPH0$0$0 == 0x0083
                    0083     53 _DPH0	=	0x0083
                    0084     54 Fexample_onewire$DPL1$0$0 == 0x0084
                    0084     55 _DPL1	=	0x0084
                    0085     56 Fexample_onewire$DPH1$0$0 == 0x0085
                    0085     57 _DPH1	=	0x0085
                    0086     58 Fexample_onewire$U0CSR$0$0 == 0x0086
                    0086     59 _U0CSR	=	0x0086
                    0087     60 Fexample_onewire$PCON$0$0 == 0x0087
                    0087     61 _PCON	=	0x0087
                    0088     62 Fexample_onewire$TCON$0$0 == 0x0088
                    0088     63 _TCON	=	0x0088
                    0089     64 Fexample_onewire$P0IFG$0$0 == 0x0089
                    0089     65 _P0IFG	=	0x0089
                    008A     66 Fexample_onewire$P1IFG$0$0 == 0x008a
                    008A     67 _P1IFG	=	0x008a
                    008B     68 Fexample_onewire$P2IFG$0$0 == 0x008b
                    008B     69 _P2IFG	=	0x008b
                    008C     70 Fexample_onewire$PICTL$0$0 == 0x008c
                    008C     71 _PICTL	=	0x008c
                    008D     72 Fexample_onewire$P1IEN$0$0 == 0x008d
                    008D     73 _P1IEN	=	0x008d
                    008F     74 Fexample_onewire$P0INP$0$0 == 0x008f
                    008F     75 _P0INP	=	0x008f
                    0090     76 Fexample_onewire$P1$0$0 == 0x0090
                    0090     77 _P1	=	0x0090
                    0091     78 Fexample_onewire$RFIM$0$0 == 0x0091
                    0091     79 _RFIM	=	0x0091
                    0092     80 Fexample_onewire$DPS$0$0 == 0x0092
                    0092     81 _DPS	=	0x0092
                    0093     82 Fexample_onewire$MPAGE$0$0 == 0x0093
                    0093     83 _MPAGE	=	0x0093
                    0095     84 Fexample_onewire$ENDIAN$0$0 == 0x0095
                    0095     85 _ENDIAN	=	0x0095
                    0098     86 Fexample_onewire$S0CON$0$0 == 0x0098
                    0098     87 _S0CON	=	0x0098
                    009A     88 Fexample_onewire$IEN2$0$0 == 0x009a
                    009A     89 _IEN2	=	0x009a
                    009B     90 Fexample_onewire$S1CON$0$0 == 0x009b
                    009B     91 _S1CON	=	0x009b
                    009C     92 Fexample_onewire$T2CT$0$0 == 0x009c
                    009C     93 _T2CT	=	0x009c
                    009D     94 Fexample_onewire$T2PR$0$0 == 0x009d
                    009D     95 _T2PR	=	0x009d
                    009E     96 Fexample_onewire$T2CTL$0$0 == 0x009e
                    009E     97 _T2CTL	=	0x009e
                    00A0     98 Fexample_onewire$P2$0$0 == 0x00a0
                    00A0     99 _P2	=	0x00a0
                    00A1    100 Fexample_onewire$WORIRQ$0$0 == 0x00a1
                    00A1    101 _WORIRQ	=	0x00a1
                    00A2    102 Fexample_onewire$WORCTRL$0$0 == 0x00a2
                    00A2    103 _WORCTRL	=	0x00a2
                    00A3    104 Fexample_onewire$WOREVT0$0$0 == 0x00a3
                    00A3    105 _WOREVT0	=	0x00a3
                    00A4    106 Fexample_onewire$WOREVT1$0$0 == 0x00a4
                    00A4    107 _WOREVT1	=	0x00a4
                    00A5    108 Fexample_onewire$WORTIME0$0$0 == 0x00a5
                    00A5    109 _WORTIME0	=	0x00a5
                    00A6    110 Fexample_onewire$WORTIME1$0$0 == 0x00a6
                    00A6    111 _WORTIME1	=	0x00a6
                    00A8    112 Fexample_onewire$IEN0$0$0 == 0x00a8
                    00A8    113 _IEN0	=	0x00a8
                    00A9    114 Fexample_onewire$IP0$0$0 == 0x00a9
                    00A9    115 _IP0	=	0x00a9
                    00AB    116 Fexample_onewire$FWT$0$0 == 0x00ab
                    00AB    117 _FWT	=	0x00ab
                    00AC    118 Fexample_onewire$FADDRL$0$0 == 0x00ac
                    00AC    119 _FADDRL	=	0x00ac
                    00AD    120 Fexample_onewire$FADDRH$0$0 == 0x00ad
                    00AD    121 _FADDRH	=	0x00ad
                    00AE    122 Fexample_onewire$FCTL$0$0 == 0x00ae
                    00AE    123 _FCTL	=	0x00ae
                    00AF    124 Fexample_onewire$FWDATA$0$0 == 0x00af
                    00AF    125 _FWDATA	=	0x00af
                    00B1    126 Fexample_onewire$ENCDI$0$0 == 0x00b1
                    00B1    127 _ENCDI	=	0x00b1
                    00B2    128 Fexample_onewire$ENCDO$0$0 == 0x00b2
                    00B2    129 _ENCDO	=	0x00b2
                    00B3    130 Fexample_onewire$ENCCS$0$0 == 0x00b3
                    00B3    131 _ENCCS	=	0x00b3
                    00B4    132 Fexample_onewire$ADCCON1$0$0 == 0x00b4
                    00B4    133 _ADCCON1	=	0x00b4
                    00B5    134 Fexample_onewire$ADCCON2$0$0 == 0x00b5
                    00B5    135 _ADCCON2	=	0x00b5
                    00B6    136 Fexample_onewire$ADCCON3$0$0 == 0x00b6
                    00B6    137 _ADCCON3	=	0x00b6
                    00B8    138 Fexample_onewire$IEN1$0$0 == 0x00b8
                    00B8    139 _IEN1	=	0x00b8
                    00B9    140 Fexample_onewire$IP1$0$0 == 0x00b9
                    00B9    141 _IP1	=	0x00b9
                    00BA    142 Fexample_onewire$ADCL$0$0 == 0x00ba
                    00BA    143 _ADCL	=	0x00ba
                    00BB    144 Fexample_onewire$ADCH$0$0 == 0x00bb
                    00BB    145 _ADCH	=	0x00bb
                    00BC    146 Fexample_onewire$RNDL$0$0 == 0x00bc
                    00BC    147 _RNDL	=	0x00bc
                    00BD    148 Fexample_onewire$RNDH$0$0 == 0x00bd
                    00BD    149 _RNDH	=	0x00bd
                    00BE    150 Fexample_onewire$SLEEP$0$0 == 0x00be
                    00BE    151 _SLEEP	=	0x00be
                    00C0    152 Fexample_onewire$IRCON$0$0 == 0x00c0
                    00C0    153 _IRCON	=	0x00c0
                    00C1    154 Fexample_onewire$U0DBUF$0$0 == 0x00c1
                    00C1    155 _U0DBUF	=	0x00c1
                    00C2    156 Fexample_onewire$U0BAUD$0$0 == 0x00c2
                    00C2    157 _U0BAUD	=	0x00c2
                    00C4    158 Fexample_onewire$U0UCR$0$0 == 0x00c4
                    00C4    159 _U0UCR	=	0x00c4
                    00C5    160 Fexample_onewire$U0GCR$0$0 == 0x00c5
                    00C5    161 _U0GCR	=	0x00c5
                    00C6    162 Fexample_onewire$CLKCON$0$0 == 0x00c6
                    00C6    163 _CLKCON	=	0x00c6
                    00C7    164 Fexample_onewire$MEMCTR$0$0 == 0x00c7
                    00C7    165 _MEMCTR	=	0x00c7
                    00C9    166 Fexample_onewire$WDCTL$0$0 == 0x00c9
                    00C9    167 _WDCTL	=	0x00c9
                    00CA    168 Fexample_onewire$T3CNT$0$0 == 0x00ca
                    00CA    169 _T3CNT	=	0x00ca
                    00CB    170 Fexample_onewire$T3CTL$0$0 == 0x00cb
                    00CB    171 _T3CTL	=	0x00cb
                    00CC    172 Fexample_onewire$T3CCTL0$0$0 == 0x00cc
                    00CC    173 _T3CCTL0	=	0x00cc
                    00CD    174 Fexample_onewire$T3CC0$0$0 == 0x00cd
                    00CD    175 _T3CC0	=	0x00cd
                    00CE    176 Fexample_onewire$T3CCTL1$0$0 == 0x00ce
                    00CE    177 _T3CCTL1	=	0x00ce
                    00CF    178 Fexample_onewire$T3CC1$0$0 == 0x00cf
                    00CF    179 _T3CC1	=	0x00cf
                    00D0    180 Fexample_onewire$PSW$0$0 == 0x00d0
                    00D0    181 _PSW	=	0x00d0
                    00D1    182 Fexample_onewire$DMAIRQ$0$0 == 0x00d1
                    00D1    183 _DMAIRQ	=	0x00d1
                    00D2    184 Fexample_onewire$DMA1CFGL$0$0 == 0x00d2
                    00D2    185 _DMA1CFGL	=	0x00d2
                    00D3    186 Fexample_onewire$DMA1CFGH$0$0 == 0x00d3
                    00D3    187 _DMA1CFGH	=	0x00d3
                    00D4    188 Fexample_onewire$DMA0CFGL$0$0 == 0x00d4
                    00D4    189 _DMA0CFGL	=	0x00d4
                    00D5    190 Fexample_onewire$DMA0CFGH$0$0 == 0x00d5
                    00D5    191 _DMA0CFGH	=	0x00d5
                    00D6    192 Fexample_onewire$DMAARM$0$0 == 0x00d6
                    00D6    193 _DMAARM	=	0x00d6
                    00D7    194 Fexample_onewire$DMAREQ$0$0 == 0x00d7
                    00D7    195 _DMAREQ	=	0x00d7
                    00D8    196 Fexample_onewire$TIMIF$0$0 == 0x00d8
                    00D8    197 _TIMIF	=	0x00d8
                    00D9    198 Fexample_onewire$RFD$0$0 == 0x00d9
                    00D9    199 _RFD	=	0x00d9
                    00DA    200 Fexample_onewire$T1CC0L$0$0 == 0x00da
                    00DA    201 _T1CC0L	=	0x00da
                    00DB    202 Fexample_onewire$T1CC0H$0$0 == 0x00db
                    00DB    203 _T1CC0H	=	0x00db
                    00DC    204 Fexample_onewire$T1CC1L$0$0 == 0x00dc
                    00DC    205 _T1CC1L	=	0x00dc
                    00DD    206 Fexample_onewire$T1CC1H$0$0 == 0x00dd
                    00DD    207 _T1CC1H	=	0x00dd
                    00DE    208 Fexample_onewire$T1CC2L$0$0 == 0x00de
                    00DE    209 _T1CC2L	=	0x00de
                    00DF    210 Fexample_onewire$T1CC2H$0$0 == 0x00df
                    00DF    211 _T1CC2H	=	0x00df
                    00E0    212 Fexample_onewire$ACC$0$0 == 0x00e0
                    00E0    213 _ACC	=	0x00e0
                    00E1    214 Fexample_onewire$RFST$0$0 == 0x00e1
                    00E1    215 _RFST	=	0x00e1
                    00E2    216 Fexample_onewire$T1CNTL$0$0 == 0x00e2
                    00E2    217 _T1CNTL	=	0x00e2
                    00E3    218 Fexample_onewire$T1CNTH$0$0 == 0x00e3
                    00E3    219 _T1CNTH	=	0x00e3
                    00E4    220 Fexample_onewire$T1CTL$0$0 == 0x00e4
                    00E4    221 _T1CTL	=	0x00e4
                    00E5    222 Fexample_onewire$T1CCTL0$0$0 == 0x00e5
                    00E5    223 _T1CCTL0	=	0x00e5
                    00E6    224 Fexample_onewire$T1CCTL1$0$0 == 0x00e6
                    00E6    225 _T1CCTL1	=	0x00e6
                    00E7    226 Fexample_onewire$T1CCTL2$0$0 == 0x00e7
                    00E7    227 _T1CCTL2	=	0x00e7
                    00E8    228 Fexample_onewire$IRCON2$0$0 == 0x00e8
                    00E8    229 _IRCON2	=	0x00e8
                    00E9    230 Fexample_onewire$RFIF$0$0 == 0x00e9
                    00E9    231 _RFIF	=	0x00e9
                    00EA    232 Fexample_onewire$T4CNT$0$0 == 0x00ea
                    00EA    233 _T4CNT	=	0x00ea
                    00EB    234 Fexample_onewire$T4CTL$0$0 == 0x00eb
                    00EB    235 _T4CTL	=	0x00eb
                    00EC    236 Fexample_onewire$T4CCTL0$0$0 == 0x00ec
                    00EC    237 _T4CCTL0	=	0x00ec
                    00ED    238 Fexample_onewire$T4CC0$0$0 == 0x00ed
                    00ED    239 _T4CC0	=	0x00ed
                    00EE    240 Fexample_onewire$T4CCTL1$0$0 == 0x00ee
                    00EE    241 _T4CCTL1	=	0x00ee
                    00EF    242 Fexample_onewire$T4CC1$0$0 == 0x00ef
                    00EF    243 _T4CC1	=	0x00ef
                    00F0    244 Fexample_onewire$B$0$0 == 0x00f0
                    00F0    245 _B	=	0x00f0
                    00F1    246 Fexample_onewire$PERCFG$0$0 == 0x00f1
                    00F1    247 _PERCFG	=	0x00f1
                    00F2    248 Fexample_onewire$ADCCFG$0$0 == 0x00f2
                    00F2    249 _ADCCFG	=	0x00f2
                    00F3    250 Fexample_onewire$P0SEL$0$0 == 0x00f3
                    00F3    251 _P0SEL	=	0x00f3
                    00F4    252 Fexample_onewire$P1SEL$0$0 == 0x00f4
                    00F4    253 _P1SEL	=	0x00f4
                    00F5    254 Fexample_onewire$P2SEL$0$0 == 0x00f5
                    00F5    255 _P2SEL	=	0x00f5
                    00F6    256 Fexample_onewire$P1INP$0$0 == 0x00f6
                    00F6    257 _P1INP	=	0x00f6
                    00F7    258 Fexample_onewire$P2INP$0$0 == 0x00f7
                    00F7    259 _P2INP	=	0x00f7
                    00F8    260 Fexample_onewire$U1CSR$0$0 == 0x00f8
                    00F8    261 _U1CSR	=	0x00f8
                    00F9    262 Fexample_onewire$U1DBUF$0$0 == 0x00f9
                    00F9    263 _U1DBUF	=	0x00f9
                    00FA    264 Fexample_onewire$U1BAUD$0$0 == 0x00fa
                    00FA    265 _U1BAUD	=	0x00fa
                    00FB    266 Fexample_onewire$U1UCR$0$0 == 0x00fb
                    00FB    267 _U1UCR	=	0x00fb
                    00FC    268 Fexample_onewire$U1GCR$0$0 == 0x00fc
                    00FC    269 _U1GCR	=	0x00fc
                    00FD    270 Fexample_onewire$P0DIR$0$0 == 0x00fd
                    00FD    271 _P0DIR	=	0x00fd
                    00FE    272 Fexample_onewire$P1DIR$0$0 == 0x00fe
                    00FE    273 _P1DIR	=	0x00fe
                    00FF    274 Fexample_onewire$P2DIR$0$0 == 0x00ff
                    00FF    275 _P2DIR	=	0x00ff
                    FFFFD5D4    276 Fexample_onewire$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    277 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    278 Fexample_onewire$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    279 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    280 Fexample_onewire$FADDR$0$0 == 0xffffadac
                    FFFFADAC    281 _FADDR	=	0xffffadac
                    FFFFBBBA    282 Fexample_onewire$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    283 _ADC	=	0xffffbbba
                    FFFFDBDA    284 Fexample_onewire$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    285 _T1CC0	=	0xffffdbda
                    FFFFDDDC    286 Fexample_onewire$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    287 _T1CC1	=	0xffffdddc
                    FFFFDFDE    288 Fexample_onewire$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    289 _T1CC2	=	0xffffdfde
                            290 ;--------------------------------------------------------
                            291 ; special function bits
                            292 ;--------------------------------------------------------
                            293 	.area RSEG    (ABS,DATA)
   0000                     294 	.org 0x0000
                    0080    295 Fexample_onewire$P0_0$0$0 == 0x0080
                    0080    296 _P0_0	=	0x0080
                    0081    297 Fexample_onewire$P0_1$0$0 == 0x0081
                    0081    298 _P0_1	=	0x0081
                    0082    299 Fexample_onewire$P0_2$0$0 == 0x0082
                    0082    300 _P0_2	=	0x0082
                    0083    301 Fexample_onewire$P0_3$0$0 == 0x0083
                    0083    302 _P0_3	=	0x0083
                    0084    303 Fexample_onewire$P0_4$0$0 == 0x0084
                    0084    304 _P0_4	=	0x0084
                    0085    305 Fexample_onewire$P0_5$0$0 == 0x0085
                    0085    306 _P0_5	=	0x0085
                    0086    307 Fexample_onewire$P0_6$0$0 == 0x0086
                    0086    308 _P0_6	=	0x0086
                    0087    309 Fexample_onewire$P0_7$0$0 == 0x0087
                    0087    310 _P0_7	=	0x0087
                    0088    311 Fexample_onewire$_TCON_0$0$0 == 0x0088
                    0088    312 __TCON_0	=	0x0088
                    0089    313 Fexample_onewire$RFTXRXIF$0$0 == 0x0089
                    0089    314 _RFTXRXIF	=	0x0089
                    008A    315 Fexample_onewire$_TCON_2$0$0 == 0x008a
                    008A    316 __TCON_2	=	0x008a
                    008B    317 Fexample_onewire$URX0IF$0$0 == 0x008b
                    008B    318 _URX0IF	=	0x008b
                    008C    319 Fexample_onewire$_TCON_4$0$0 == 0x008c
                    008C    320 __TCON_4	=	0x008c
                    008D    321 Fexample_onewire$ADCIF$0$0 == 0x008d
                    008D    322 _ADCIF	=	0x008d
                    008E    323 Fexample_onewire$_TCON_6$0$0 == 0x008e
                    008E    324 __TCON_6	=	0x008e
                    008F    325 Fexample_onewire$URX1IF$0$0 == 0x008f
                    008F    326 _URX1IF	=	0x008f
                    0090    327 Fexample_onewire$P1_0$0$0 == 0x0090
                    0090    328 _P1_0	=	0x0090
                    0091    329 Fexample_onewire$P1_1$0$0 == 0x0091
                    0091    330 _P1_1	=	0x0091
                    0092    331 Fexample_onewire$P1_2$0$0 == 0x0092
                    0092    332 _P1_2	=	0x0092
                    0093    333 Fexample_onewire$P1_3$0$0 == 0x0093
                    0093    334 _P1_3	=	0x0093
                    0094    335 Fexample_onewire$P1_4$0$0 == 0x0094
                    0094    336 _P1_4	=	0x0094
                    0095    337 Fexample_onewire$P1_5$0$0 == 0x0095
                    0095    338 _P1_5	=	0x0095
                    0096    339 Fexample_onewire$P1_6$0$0 == 0x0096
                    0096    340 _P1_6	=	0x0096
                    0097    341 Fexample_onewire$P1_7$0$0 == 0x0097
                    0097    342 _P1_7	=	0x0097
                    0098    343 Fexample_onewire$ENCIF_0$0$0 == 0x0098
                    0098    344 _ENCIF_0	=	0x0098
                    0099    345 Fexample_onewire$ENCIF_1$0$0 == 0x0099
                    0099    346 _ENCIF_1	=	0x0099
                    009A    347 Fexample_onewire$_SOCON2$0$0 == 0x009a
                    009A    348 __SOCON2	=	0x009a
                    009B    349 Fexample_onewire$_SOCON3$0$0 == 0x009b
                    009B    350 __SOCON3	=	0x009b
                    009C    351 Fexample_onewire$_SOCON4$0$0 == 0x009c
                    009C    352 __SOCON4	=	0x009c
                    009D    353 Fexample_onewire$_SOCON5$0$0 == 0x009d
                    009D    354 __SOCON5	=	0x009d
                    009E    355 Fexample_onewire$_SOCON6$0$0 == 0x009e
                    009E    356 __SOCON6	=	0x009e
                    009F    357 Fexample_onewire$_SOCON7$0$0 == 0x009f
                    009F    358 __SOCON7	=	0x009f
                    00A0    359 Fexample_onewire$P2_0$0$0 == 0x00a0
                    00A0    360 _P2_0	=	0x00a0
                    00A1    361 Fexample_onewire$P2_1$0$0 == 0x00a1
                    00A1    362 _P2_1	=	0x00a1
                    00A2    363 Fexample_onewire$P2_2$0$0 == 0x00a2
                    00A2    364 _P2_2	=	0x00a2
                    00A3    365 Fexample_onewire$P2_3$0$0 == 0x00a3
                    00A3    366 _P2_3	=	0x00a3
                    00A4    367 Fexample_onewire$P2_4$0$0 == 0x00a4
                    00A4    368 _P2_4	=	0x00a4
                    00A5    369 Fexample_onewire$P2_5$0$0 == 0x00a5
                    00A5    370 _P2_5	=	0x00a5
                    00A6    371 Fexample_onewire$P2_6$0$0 == 0x00a6
                    00A6    372 _P2_6	=	0x00a6
                    00A7    373 Fexample_onewire$P2_7$0$0 == 0x00a7
                    00A7    374 _P2_7	=	0x00a7
                    00A8    375 Fexample_onewire$RFTXRXIE$0$0 == 0x00a8
                    00A8    376 _RFTXRXIE	=	0x00a8
                    00A9    377 Fexample_onewire$ADCIE$0$0 == 0x00a9
                    00A9    378 _ADCIE	=	0x00a9
                    00AA    379 Fexample_onewire$URX0IE$0$0 == 0x00aa
                    00AA    380 _URX0IE	=	0x00aa
                    00AB    381 Fexample_onewire$URX1IE$0$0 == 0x00ab
                    00AB    382 _URX1IE	=	0x00ab
                    00AC    383 Fexample_onewire$ENCIE$0$0 == 0x00ac
                    00AC    384 _ENCIE	=	0x00ac
                    00AD    385 Fexample_onewire$STIE$0$0 == 0x00ad
                    00AD    386 _STIE	=	0x00ad
                    00AE    387 Fexample_onewire$_IEN06$0$0 == 0x00ae
                    00AE    388 __IEN06	=	0x00ae
                    00AF    389 Fexample_onewire$EA$0$0 == 0x00af
                    00AF    390 _EA	=	0x00af
                    00B8    391 Fexample_onewire$DMAIE$0$0 == 0x00b8
                    00B8    392 _DMAIE	=	0x00b8
                    00B9    393 Fexample_onewire$T1IE$0$0 == 0x00b9
                    00B9    394 _T1IE	=	0x00b9
                    00BA    395 Fexample_onewire$T2IE$0$0 == 0x00ba
                    00BA    396 _T2IE	=	0x00ba
                    00BB    397 Fexample_onewire$T3IE$0$0 == 0x00bb
                    00BB    398 _T3IE	=	0x00bb
                    00BC    399 Fexample_onewire$T4IE$0$0 == 0x00bc
                    00BC    400 _T4IE	=	0x00bc
                    00BD    401 Fexample_onewire$P0IE$0$0 == 0x00bd
                    00BD    402 _P0IE	=	0x00bd
                    00BE    403 Fexample_onewire$_IEN16$0$0 == 0x00be
                    00BE    404 __IEN16	=	0x00be
                    00BF    405 Fexample_onewire$_IEN17$0$0 == 0x00bf
                    00BF    406 __IEN17	=	0x00bf
                    00C0    407 Fexample_onewire$DMAIF$0$0 == 0x00c0
                    00C0    408 _DMAIF	=	0x00c0
                    00C1    409 Fexample_onewire$T1IF$0$0 == 0x00c1
                    00C1    410 _T1IF	=	0x00c1
                    00C2    411 Fexample_onewire$T2IF$0$0 == 0x00c2
                    00C2    412 _T2IF	=	0x00c2
                    00C3    413 Fexample_onewire$T3IF$0$0 == 0x00c3
                    00C3    414 _T3IF	=	0x00c3
                    00C4    415 Fexample_onewire$T4IF$0$0 == 0x00c4
                    00C4    416 _T4IF	=	0x00c4
                    00C5    417 Fexample_onewire$P0IF$0$0 == 0x00c5
                    00C5    418 _P0IF	=	0x00c5
                    00C6    419 Fexample_onewire$_IRCON6$0$0 == 0x00c6
                    00C6    420 __IRCON6	=	0x00c6
                    00C7    421 Fexample_onewire$STIF$0$0 == 0x00c7
                    00C7    422 _STIF	=	0x00c7
                    00D0    423 Fexample_onewire$P$0$0 == 0x00d0
                    00D0    424 _P	=	0x00d0
                    00D1    425 Fexample_onewire$F1$0$0 == 0x00d1
                    00D1    426 _F1	=	0x00d1
                    00D2    427 Fexample_onewire$OV$0$0 == 0x00d2
                    00D2    428 _OV	=	0x00d2
                    00D3    429 Fexample_onewire$RS0$0$0 == 0x00d3
                    00D3    430 _RS0	=	0x00d3
                    00D4    431 Fexample_onewire$RS1$0$0 == 0x00d4
                    00D4    432 _RS1	=	0x00d4
                    00D5    433 Fexample_onewire$F0$0$0 == 0x00d5
                    00D5    434 _F0	=	0x00d5
                    00D6    435 Fexample_onewire$AC$0$0 == 0x00d6
                    00D6    436 _AC	=	0x00d6
                    00D7    437 Fexample_onewire$CY$0$0 == 0x00d7
                    00D7    438 _CY	=	0x00d7
                    00D8    439 Fexample_onewire$T3OVFIF$0$0 == 0x00d8
                    00D8    440 _T3OVFIF	=	0x00d8
                    00D9    441 Fexample_onewire$T3CH0IF$0$0 == 0x00d9
                    00D9    442 _T3CH0IF	=	0x00d9
                    00DA    443 Fexample_onewire$T3CH1IF$0$0 == 0x00da
                    00DA    444 _T3CH1IF	=	0x00da
                    00DB    445 Fexample_onewire$T4OVFIF$0$0 == 0x00db
                    00DB    446 _T4OVFIF	=	0x00db
                    00DC    447 Fexample_onewire$T4CH0IF$0$0 == 0x00dc
                    00DC    448 _T4CH0IF	=	0x00dc
                    00DD    449 Fexample_onewire$T4CH1IF$0$0 == 0x00dd
                    00DD    450 _T4CH1IF	=	0x00dd
                    00DE    451 Fexample_onewire$OVFIM$0$0 == 0x00de
                    00DE    452 _OVFIM	=	0x00de
                    00DF    453 Fexample_onewire$_TIMIF7$0$0 == 0x00df
                    00DF    454 __TIMIF7	=	0x00df
                    00E0    455 Fexample_onewire$ACC_0$0$0 == 0x00e0
                    00E0    456 _ACC_0	=	0x00e0
                    00E1    457 Fexample_onewire$ACC_1$0$0 == 0x00e1
                    00E1    458 _ACC_1	=	0x00e1
                    00E2    459 Fexample_onewire$ACC_2$0$0 == 0x00e2
                    00E2    460 _ACC_2	=	0x00e2
                    00E3    461 Fexample_onewire$ACC_3$0$0 == 0x00e3
                    00E3    462 _ACC_3	=	0x00e3
                    00E4    463 Fexample_onewire$ACC_4$0$0 == 0x00e4
                    00E4    464 _ACC_4	=	0x00e4
                    00E5    465 Fexample_onewire$ACC_5$0$0 == 0x00e5
                    00E5    466 _ACC_5	=	0x00e5
                    00E6    467 Fexample_onewire$ACC_6$0$0 == 0x00e6
                    00E6    468 _ACC_6	=	0x00e6
                    00E7    469 Fexample_onewire$ACC_7$0$0 == 0x00e7
                    00E7    470 _ACC_7	=	0x00e7
                    00E8    471 Fexample_onewire$P2IF$0$0 == 0x00e8
                    00E8    472 _P2IF	=	0x00e8
                    00E9    473 Fexample_onewire$UTX0IF$0$0 == 0x00e9
                    00E9    474 _UTX0IF	=	0x00e9
                    00EA    475 Fexample_onewire$UTX1IF$0$0 == 0x00ea
                    00EA    476 _UTX1IF	=	0x00ea
                    00EB    477 Fexample_onewire$P1IF$0$0 == 0x00eb
                    00EB    478 _P1IF	=	0x00eb
                    00EC    479 Fexample_onewire$WDTIF$0$0 == 0x00ec
                    00EC    480 _WDTIF	=	0x00ec
                    00ED    481 Fexample_onewire$_IRCON25$0$0 == 0x00ed
                    00ED    482 __IRCON25	=	0x00ed
                    00EE    483 Fexample_onewire$_IRCON26$0$0 == 0x00ee
                    00EE    484 __IRCON26	=	0x00ee
                    00EF    485 Fexample_onewire$_IRCON27$0$0 == 0x00ef
                    00EF    486 __IRCON27	=	0x00ef
                    00F0    487 Fexample_onewire$B_0$0$0 == 0x00f0
                    00F0    488 _B_0	=	0x00f0
                    00F1    489 Fexample_onewire$B_1$0$0 == 0x00f1
                    00F1    490 _B_1	=	0x00f1
                    00F2    491 Fexample_onewire$B_2$0$0 == 0x00f2
                    00F2    492 _B_2	=	0x00f2
                    00F3    493 Fexample_onewire$B_3$0$0 == 0x00f3
                    00F3    494 _B_3	=	0x00f3
                    00F4    495 Fexample_onewire$B_4$0$0 == 0x00f4
                    00F4    496 _B_4	=	0x00f4
                    00F5    497 Fexample_onewire$B_5$0$0 == 0x00f5
                    00F5    498 _B_5	=	0x00f5
                    00F6    499 Fexample_onewire$B_6$0$0 == 0x00f6
                    00F6    500 _B_6	=	0x00f6
                    00F7    501 Fexample_onewire$B_7$0$0 == 0x00f7
                    00F7    502 _B_7	=	0x00f7
                    00F8    503 Fexample_onewire$U1ACTIVE$0$0 == 0x00f8
                    00F8    504 _U1ACTIVE	=	0x00f8
                    00F9    505 Fexample_onewire$U1TX_BYTE$0$0 == 0x00f9
                    00F9    506 _U1TX_BYTE	=	0x00f9
                    00FA    507 Fexample_onewire$U1RX_BYTE$0$0 == 0x00fa
                    00FA    508 _U1RX_BYTE	=	0x00fa
                    00FB    509 Fexample_onewire$U1ERR$0$0 == 0x00fb
                    00FB    510 _U1ERR	=	0x00fb
                    00FC    511 Fexample_onewire$U1FE$0$0 == 0x00fc
                    00FC    512 _U1FE	=	0x00fc
                    00FD    513 Fexample_onewire$U1SLAVE$0$0 == 0x00fd
                    00FD    514 _U1SLAVE	=	0x00fd
                    00FE    515 Fexample_onewire$U1RE$0$0 == 0x00fe
                    00FE    516 _U1RE	=	0x00fe
                    00FF    517 Fexample_onewire$U1MODE$0$0 == 0x00ff
                    00FF    518 _U1MODE	=	0x00ff
                            519 ;--------------------------------------------------------
                            520 ; overlayable register banks
                            521 ;--------------------------------------------------------
                            522 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     523 	.ds 8
                            524 ;--------------------------------------------------------
                            525 ; internal ram data
                            526 ;--------------------------------------------------------
                            527 	.area DSEG    (DATA)
                    0000    528 Lexample_onewire.handleOneWire$sloc0$1$0==.
   0008                     529 _handleOneWire_sloc0_1_0:
   0008                     530 	.ds 4
                    0004    531 Lexample_onewire.handleOneWire$sloc1$1$0==.
   000C                     532 _handleOneWire_sloc1_1_0:
   000C                     533 	.ds 3
                            534 ;--------------------------------------------------------
                            535 ; overlayable items in internal ram 
                            536 ;--------------------------------------------------------
                            537 	.area OSEG    (OVR,DATA)
                            538 ;--------------------------------------------------------
                            539 ; Stack segment in internal ram 
                            540 ;--------------------------------------------------------
                            541 	.area	SSEG	(DATA)
   0023                     542 __start__stack:
   0023                     543 	.ds	1
                            544 
                            545 ;--------------------------------------------------------
                            546 ; indirectly addressable internal ram data
                            547 ;--------------------------------------------------------
                            548 	.area ISEG    (DATA)
                            549 ;--------------------------------------------------------
                            550 ; absolute internal ram data
                            551 ;--------------------------------------------------------
                            552 	.area IABS    (ABS,DATA)
                            553 	.area IABS    (ABS,DATA)
                            554 ;--------------------------------------------------------
                            555 ; bit data
                            556 ;--------------------------------------------------------
                            557 	.area BSEG    (BIT)
                            558 ;--------------------------------------------------------
                            559 ; paged external ram data
                            560 ;--------------------------------------------------------
                            561 	.area PSEG    (PAG,XDATA)
                    0000    562 G$respondstr$0$0==.
   F000                     563 _respondstr::
   F000                     564 	.ds 3
                    0003    565 G$is_DS18B20$0$0==.
   F003                     566 _is_DS18B20::
   F003                     567 	.ds 1
                    0004    568 G$ds1820_time$0$0==.
   F004                     569 _ds1820_time::
   F004                     570 	.ds 4
                    0008    571 Lexample_onewire.read_DS1820$dataread$1$1==.
   F008                     572 _read_DS1820_dataread_1_1:
   F008                     573 	.ds 12
                    0014    574 Lexample_onewire.handleOneWire$air_temp_c$1$1==.
   F014                     575 _handleOneWire_air_temp_c_1_1:
   F014                     576 	.ds 2
                    0016    577 Lexample_onewire.handleOneWire$cp$2$3==.
   F016                     578 _handleOneWire_cp_2_3:
   F016                     579 	.ds 3
                            580 ;--------------------------------------------------------
                            581 ; external ram data
                            582 ;--------------------------------------------------------
                            583 	.area XSEG    (XDATA)
                    DF00    584 Fexample_onewire$SYNC1$0$0 == 0xdf00
                    DF00    585 _SYNC1	=	0xdf00
                    DF01    586 Fexample_onewire$SYNC0$0$0 == 0xdf01
                    DF01    587 _SYNC0	=	0xdf01
                    DF02    588 Fexample_onewire$PKTLEN$0$0 == 0xdf02
                    DF02    589 _PKTLEN	=	0xdf02
                    DF03    590 Fexample_onewire$PKTCTRL1$0$0 == 0xdf03
                    DF03    591 _PKTCTRL1	=	0xdf03
                    DF04    592 Fexample_onewire$PKTCTRL0$0$0 == 0xdf04
                    DF04    593 _PKTCTRL0	=	0xdf04
                    DF05    594 Fexample_onewire$ADDR$0$0 == 0xdf05
                    DF05    595 _ADDR	=	0xdf05
                    DF06    596 Fexample_onewire$CHANNR$0$0 == 0xdf06
                    DF06    597 _CHANNR	=	0xdf06
                    DF07    598 Fexample_onewire$FSCTRL1$0$0 == 0xdf07
                    DF07    599 _FSCTRL1	=	0xdf07
                    DF08    600 Fexample_onewire$FSCTRL0$0$0 == 0xdf08
                    DF08    601 _FSCTRL0	=	0xdf08
                    DF09    602 Fexample_onewire$FREQ2$0$0 == 0xdf09
                    DF09    603 _FREQ2	=	0xdf09
                    DF0A    604 Fexample_onewire$FREQ1$0$0 == 0xdf0a
                    DF0A    605 _FREQ1	=	0xdf0a
                    DF0B    606 Fexample_onewire$FREQ0$0$0 == 0xdf0b
                    DF0B    607 _FREQ0	=	0xdf0b
                    DF0C    608 Fexample_onewire$MDMCFG4$0$0 == 0xdf0c
                    DF0C    609 _MDMCFG4	=	0xdf0c
                    DF0D    610 Fexample_onewire$MDMCFG3$0$0 == 0xdf0d
                    DF0D    611 _MDMCFG3	=	0xdf0d
                    DF0E    612 Fexample_onewire$MDMCFG2$0$0 == 0xdf0e
                    DF0E    613 _MDMCFG2	=	0xdf0e
                    DF0F    614 Fexample_onewire$MDMCFG1$0$0 == 0xdf0f
                    DF0F    615 _MDMCFG1	=	0xdf0f
                    DF10    616 Fexample_onewire$MDMCFG0$0$0 == 0xdf10
                    DF10    617 _MDMCFG0	=	0xdf10
                    DF11    618 Fexample_onewire$DEVIATN$0$0 == 0xdf11
                    DF11    619 _DEVIATN	=	0xdf11
                    DF12    620 Fexample_onewire$MCSM2$0$0 == 0xdf12
                    DF12    621 _MCSM2	=	0xdf12
                    DF13    622 Fexample_onewire$MCSM1$0$0 == 0xdf13
                    DF13    623 _MCSM1	=	0xdf13
                    DF14    624 Fexample_onewire$MCSM0$0$0 == 0xdf14
                    DF14    625 _MCSM0	=	0xdf14
                    DF15    626 Fexample_onewire$FOCCFG$0$0 == 0xdf15
                    DF15    627 _FOCCFG	=	0xdf15
                    DF16    628 Fexample_onewire$BSCFG$0$0 == 0xdf16
                    DF16    629 _BSCFG	=	0xdf16
                    DF17    630 Fexample_onewire$AGCCTRL2$0$0 == 0xdf17
                    DF17    631 _AGCCTRL2	=	0xdf17
                    DF18    632 Fexample_onewire$AGCCTRL1$0$0 == 0xdf18
                    DF18    633 _AGCCTRL1	=	0xdf18
                    DF19    634 Fexample_onewire$AGCCTRL0$0$0 == 0xdf19
                    DF19    635 _AGCCTRL0	=	0xdf19
                    DF1A    636 Fexample_onewire$FREND1$0$0 == 0xdf1a
                    DF1A    637 _FREND1	=	0xdf1a
                    DF1B    638 Fexample_onewire$FREND0$0$0 == 0xdf1b
                    DF1B    639 _FREND0	=	0xdf1b
                    DF1C    640 Fexample_onewire$FSCAL3$0$0 == 0xdf1c
                    DF1C    641 _FSCAL3	=	0xdf1c
                    DF1D    642 Fexample_onewire$FSCAL2$0$0 == 0xdf1d
                    DF1D    643 _FSCAL2	=	0xdf1d
                    DF1E    644 Fexample_onewire$FSCAL1$0$0 == 0xdf1e
                    DF1E    645 _FSCAL1	=	0xdf1e
                    DF1F    646 Fexample_onewire$FSCAL0$0$0 == 0xdf1f
                    DF1F    647 _FSCAL0	=	0xdf1f
                    DF23    648 Fexample_onewire$TEST2$0$0 == 0xdf23
                    DF23    649 _TEST2	=	0xdf23
                    DF24    650 Fexample_onewire$TEST1$0$0 == 0xdf24
                    DF24    651 _TEST1	=	0xdf24
                    DF25    652 Fexample_onewire$TEST0$0$0 == 0xdf25
                    DF25    653 _TEST0	=	0xdf25
                    DF2E    654 Fexample_onewire$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    655 _PA_TABLE0	=	0xdf2e
                    DF2F    656 Fexample_onewire$IOCFG2$0$0 == 0xdf2f
                    DF2F    657 _IOCFG2	=	0xdf2f
                    DF30    658 Fexample_onewire$IOCFG1$0$0 == 0xdf30
                    DF30    659 _IOCFG1	=	0xdf30
                    DF31    660 Fexample_onewire$IOCFG0$0$0 == 0xdf31
                    DF31    661 _IOCFG0	=	0xdf31
                    DF36    662 Fexample_onewire$PARTNUM$0$0 == 0xdf36
                    DF36    663 _PARTNUM	=	0xdf36
                    DF37    664 Fexample_onewire$VERSION$0$0 == 0xdf37
                    DF37    665 _VERSION	=	0xdf37
                    DF38    666 Fexample_onewire$FREQEST$0$0 == 0xdf38
                    DF38    667 _FREQEST	=	0xdf38
                    DF39    668 Fexample_onewire$LQI$0$0 == 0xdf39
                    DF39    669 _LQI	=	0xdf39
                    DF3A    670 Fexample_onewire$RSSI$0$0 == 0xdf3a
                    DF3A    671 _RSSI	=	0xdf3a
                    DF3B    672 Fexample_onewire$MARCSTATE$0$0 == 0xdf3b
                    DF3B    673 _MARCSTATE	=	0xdf3b
                    DF3C    674 Fexample_onewire$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    675 _PKTSTATUS	=	0xdf3c
                    DF3D    676 Fexample_onewire$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    677 _VCO_VC_DAC	=	0xdf3d
                    DF40    678 Fexample_onewire$I2SCFG0$0$0 == 0xdf40
                    DF40    679 _I2SCFG0	=	0xdf40
                    DF41    680 Fexample_onewire$I2SCFG1$0$0 == 0xdf41
                    DF41    681 _I2SCFG1	=	0xdf41
                    DF42    682 Fexample_onewire$I2SDATL$0$0 == 0xdf42
                    DF42    683 _I2SDATL	=	0xdf42
                    DF43    684 Fexample_onewire$I2SDATH$0$0 == 0xdf43
                    DF43    685 _I2SDATH	=	0xdf43
                    DF44    686 Fexample_onewire$I2SWCNT$0$0 == 0xdf44
                    DF44    687 _I2SWCNT	=	0xdf44
                    DF45    688 Fexample_onewire$I2SSTAT$0$0 == 0xdf45
                    DF45    689 _I2SSTAT	=	0xdf45
                    DF46    690 Fexample_onewire$I2SCLKF0$0$0 == 0xdf46
                    DF46    691 _I2SCLKF0	=	0xdf46
                    DF47    692 Fexample_onewire$I2SCLKF1$0$0 == 0xdf47
                    DF47    693 _I2SCLKF1	=	0xdf47
                    DF48    694 Fexample_onewire$I2SCLKF2$0$0 == 0xdf48
                    DF48    695 _I2SCLKF2	=	0xdf48
                    DE00    696 Fexample_onewire$USBADDR$0$0 == 0xde00
                    DE00    697 _USBADDR	=	0xde00
                    DE01    698 Fexample_onewire$USBPOW$0$0 == 0xde01
                    DE01    699 _USBPOW	=	0xde01
                    DE02    700 Fexample_onewire$USBIIF$0$0 == 0xde02
                    DE02    701 _USBIIF	=	0xde02
                    DE04    702 Fexample_onewire$USBOIF$0$0 == 0xde04
                    DE04    703 _USBOIF	=	0xde04
                    DE06    704 Fexample_onewire$USBCIF$0$0 == 0xde06
                    DE06    705 _USBCIF	=	0xde06
                    DE07    706 Fexample_onewire$USBIIE$0$0 == 0xde07
                    DE07    707 _USBIIE	=	0xde07
                    DE09    708 Fexample_onewire$USBOIE$0$0 == 0xde09
                    DE09    709 _USBOIE	=	0xde09
                    DE0B    710 Fexample_onewire$USBCIE$0$0 == 0xde0b
                    DE0B    711 _USBCIE	=	0xde0b
                    DE0C    712 Fexample_onewire$USBFRML$0$0 == 0xde0c
                    DE0C    713 _USBFRML	=	0xde0c
                    DE0D    714 Fexample_onewire$USBFRMH$0$0 == 0xde0d
                    DE0D    715 _USBFRMH	=	0xde0d
                    DE0E    716 Fexample_onewire$USBINDEX$0$0 == 0xde0e
                    DE0E    717 _USBINDEX	=	0xde0e
                    DE10    718 Fexample_onewire$USBMAXI$0$0 == 0xde10
                    DE10    719 _USBMAXI	=	0xde10
                    DE11    720 Fexample_onewire$USBCSIL$0$0 == 0xde11
                    DE11    721 _USBCSIL	=	0xde11
                    DE12    722 Fexample_onewire$USBCSIH$0$0 == 0xde12
                    DE12    723 _USBCSIH	=	0xde12
                    DE13    724 Fexample_onewire$USBMAXO$0$0 == 0xde13
                    DE13    725 _USBMAXO	=	0xde13
                    DE14    726 Fexample_onewire$USBCSOL$0$0 == 0xde14
                    DE14    727 _USBCSOL	=	0xde14
                    DE15    728 Fexample_onewire$USBCSOH$0$0 == 0xde15
                    DE15    729 _USBCSOH	=	0xde15
                    DE16    730 Fexample_onewire$USBCNTL$0$0 == 0xde16
                    DE16    731 _USBCNTL	=	0xde16
                    DE17    732 Fexample_onewire$USBCNTH$0$0 == 0xde17
                    DE17    733 _USBCNTH	=	0xde17
                    DE20    734 Fexample_onewire$USBF0$0$0 == 0xde20
                    DE20    735 _USBF0	=	0xde20
                    DE22    736 Fexample_onewire$USBF1$0$0 == 0xde22
                    DE22    737 _USBF1	=	0xde22
                    DE24    738 Fexample_onewire$USBF2$0$0 == 0xde24
                    DE24    739 _USBF2	=	0xde24
                    DE26    740 Fexample_onewire$USBF3$0$0 == 0xde26
                    DE26    741 _USBF3	=	0xde26
                    DE28    742 Fexample_onewire$USBF4$0$0 == 0xde28
                    DE28    743 _USBF4	=	0xde28
                    DE2A    744 Fexample_onewire$USBF5$0$0 == 0xde2a
                    DE2A    745 _USBF5	=	0xde2a
                    0000    746 G$DS1820_addr$0$0==.
   F075                     747 _DS1820_addr::
   F075                     748 	.ds 8
                    0008    749 Lexample_onewire.handleOneWire$response$2$3==.
   F07D                     750 _handleOneWire_response_2_3:
   F07D                     751 	.ds 64
                            752 ;--------------------------------------------------------
                            753 ; absolute external ram data
                            754 ;--------------------------------------------------------
                            755 	.area XABS    (ABS,XDATA)
                            756 ;--------------------------------------------------------
                            757 ; external initialized ram data
                            758 ;--------------------------------------------------------
                            759 	.area XISEG   (XDATA)
                            760 	.area HOME    (CODE)
                            761 	.area GSINIT0 (CODE)
                            762 	.area GSINIT1 (CODE)
                            763 	.area GSINIT2 (CODE)
                            764 	.area GSINIT3 (CODE)
                            765 	.area GSINIT4 (CODE)
                            766 	.area GSINIT5 (CODE)
                            767 	.area GSINIT  (CODE)
                            768 	.area GSFINAL (CODE)
                            769 	.area CSEG    (CODE)
                            770 ;--------------------------------------------------------
                            771 ; interrupt vector 
                            772 ;--------------------------------------------------------
                            773 	.area HOME    (CODE)
   0400                     774 __interrupt_vect:
   0400 02 04 6D            775 	ljmp	__sdcc_gsinit_startup
   0403 32                  776 	reti
   0404                     777 	.ds	7
   040B 32                  778 	reti
   040C                     779 	.ds	7
   0413 32                  780 	reti
   0414                     781 	.ds	7
   041B 32                  782 	reti
   041C                     783 	.ds	7
   0423 32                  784 	reti
   0424                     785 	.ds	7
   042B 32                  786 	reti
   042C                     787 	.ds	7
   0433 32                  788 	reti
   0434                     789 	.ds	7
   043B 32                  790 	reti
   043C                     791 	.ds	7
   0443 32                  792 	reti
   0444                     793 	.ds	7
   044B 32                  794 	reti
   044C                     795 	.ds	7
   0453 32                  796 	reti
   0454                     797 	.ds	7
   045B 32                  798 	reti
   045C                     799 	.ds	7
   0463 02 17 91            800 	ljmp	_ISR_T4
                            801 ;--------------------------------------------------------
                            802 ; global & static initialisations
                            803 ;--------------------------------------------------------
                            804 	.area HOME    (CODE)
                            805 	.area GSINIT  (CODE)
                            806 	.area GSFINAL (CODE)
                            807 	.area GSINIT  (CODE)
                            808 	.globl __sdcc_gsinit_startup
                            809 	.globl __sdcc_program_startup
                            810 	.globl __start__stack
                            811 	.globl __mcs51_genXINIT
                            812 	.globl __mcs51_genXRAMCLEAR
                            813 	.globl __mcs51_genRAMCLEAR
                    0000    814 	G$main$0$0 ==.
                    0000    815 	C$example_onewire.c$30$1$1 ==.
                            816 ;	apps/example_onewire/example_onewire.c:30: const char *respondstr = NULL;
   04C6 78 00               817 	mov	r0,#_respondstr
   04C8 E4                  818 	clr	a
   04C9 F2                  819 	movx	@r0,a
   04CA 08                  820 	inc	r0
   04CB F2                  821 	movx	@r0,a
   04CC 08                  822 	inc	r0
   04CD F2                  823 	movx	@r0,a
                            824 	.area GSFINAL (CODE)
   04F8 02 04 66            825 	ljmp	__sdcc_program_startup
                            826 ;--------------------------------------------------------
                            827 ; Home
                            828 ;--------------------------------------------------------
                            829 	.area HOME    (CODE)
                            830 	.area HOME    (CODE)
   0466                     831 __sdcc_program_startup:
   0466 12 08 F8            832 	lcall	_main
                            833 ;	return from main will lock up
   0469 80 FE               834 	sjmp .
                            835 ;--------------------------------------------------------
                            836 ; code
                            837 ;--------------------------------------------------------
                            838 	.area CSEG    (CODE)
                            839 ;------------------------------------------------------------
                            840 ;Allocation info for local variables in function 'start_DS1820'
                            841 ;------------------------------------------------------------
                    0000    842 	G$start_DS1820$0$0 ==.
                    0000    843 	C$example_onewire.c$36$0$0 ==.
                            844 ;	apps/example_onewire/example_onewire.c:36: void start_DS1820()
                            845 ;	-----------------------------------------
                            846 ;	 function start_DS1820
                            847 ;	-----------------------------------------
   04FB                     848 _start_DS1820:
                    0007    849 	ar7 = 0x07
                    0006    850 	ar6 = 0x06
                    0005    851 	ar5 = 0x05
                    0004    852 	ar4 = 0x04
                    0003    853 	ar3 = 0x03
                    0002    854 	ar2 = 0x02
                    0001    855 	ar1 = 0x01
                    0000    856 	ar0 = 0x00
                    0000    857 	C$example_onewire.c$38$1$1 ==.
                            858 ;	apps/example_onewire/example_onewire.c:38: onewire_reset();
   04FB 12 09 14            859 	lcall	_onewire_reset
                    0003    860 	C$example_onewire.c$39$1$1 ==.
                            861 ;	apps/example_onewire/example_onewire.c:39: onewire_select(DS1820_addr);
   04FE 90 F0 75            862 	mov	dptr,#_DS1820_addr
   0501 75 F0 00            863 	mov	b,#0x00
   0504 12 0A 0D            864 	lcall	_onewire_select
                    000C    865 	C$example_onewire.c$40$1$1 ==.
                            866 ;	apps/example_onewire/example_onewire.c:40: onewire_write(0x44,0);         // start conversion, with parasite power off at the end
   0507 78 19               867 	mov	r0,#_onewire_write_PARM_2
   0509 E4                  868 	clr	a
   050A F2                  869 	movx	@r0,a
   050B 75 82 44            870 	mov	dpl,#0x44
   050E 12 09 BA            871 	lcall	_onewire_write
                    0016    872 	C$example_onewire.c$41$1$1 ==.
                    0016    873 	XG$start_DS1820$0$0 ==.
   0511 22                  874 	ret
                            875 ;------------------------------------------------------------
                            876 ;Allocation info for local variables in function 'setup_DS1820'
                            877 ;------------------------------------------------------------
                    0017    878 	G$setup_DS1820$0$0 ==.
                    0017    879 	C$example_onewire.c$43$1$1 ==.
                            880 ;	apps/example_onewire/example_onewire.c:43: void setup_DS1820(void) {
                            881 ;	-----------------------------------------
                            882 ;	 function setup_DS1820
                            883 ;	-----------------------------------------
   0512                     884 _setup_DS1820:
                    0017    885 	C$example_onewire.c$44$1$1 ==.
                            886 ;	apps/example_onewire/example_onewire.c:44: onewire_start();
   0512 12 09 10            887 	lcall	_onewire_start
                    001A    888 	C$example_onewire.c$45$1$1 ==.
                            889 ;	apps/example_onewire/example_onewire.c:45: if ( !onewire_search(DS1820_addr)) {
   0515 90 F0 75            890 	mov	dptr,#_DS1820_addr
   0518 75 F0 00            891 	mov	b,#0x00
   051B 12 0A 99            892 	lcall	_onewire_search
   051E E5 82               893 	mov	a,dpl
   0520 70 12               894 	jnz	00102$
                    0027    895 	C$example_onewire.c$46$2$2 ==.
                            896 ;	apps/example_onewire/example_onewire.c:46: onewire_reset_search();
   0522 12 0A 77            897 	lcall	_onewire_reset_search
                    002A    898 	C$example_onewire.c$47$2$2 ==.
                            899 ;	apps/example_onewire/example_onewire.c:47: delayMs(250);
   0525 90 00 FA            900 	mov	dptr,#0x00FA
   0528 12 17 E2            901 	lcall	_delayMs
                    0030    902 	C$example_onewire.c$48$2$2 ==.
                            903 ;	apps/example_onewire/example_onewire.c:48: onewire_search(DS1820_addr);
   052B 90 F0 75            904 	mov	dptr,#_DS1820_addr
   052E 75 F0 00            905 	mov	b,#0x00
   0531 12 0A 99            906 	lcall	_onewire_search
   0534                     907 00102$:
                    0039    908 	C$example_onewire.c$51$1$1 ==.
                            909 ;	apps/example_onewire/example_onewire.c:51: if ( onewire_crc8( DS1820_addr, 7) != DS1820_addr[7]) {
   0534 78 2C               910 	mov	r0,#_onewire_crc8_PARM_2
   0536 74 07               911 	mov	a,#0x07
   0538 F2                  912 	movx	@r0,a
   0539 90 F0 75            913 	mov	dptr,#_DS1820_addr
   053C 75 F0 00            914 	mov	b,#0x00
   053F 12 0C 05            915 	lcall	_onewire_crc8
   0542 AF 82               916 	mov	r7,dpl
   0544 90 F0 7C            917 	mov	dptr,#(_DS1820_addr + 0x0007)
   0547 E0                  918 	movx	a,@dptr
   0548 FE                  919 	mov	r6,a
   0549 EF                  920 	mov	a,r7
   054A B5 06 02            921 	cjne	a,ar6,00118$
   054D 80 0F               922 	sjmp	00104$
   054F                     923 00118$:
                    0054    924 	C$example_onewire.c$52$2$3 ==.
                            925 ;	apps/example_onewire/example_onewire.c:52: respondstr = "No OneWire devices found";
   054F 78 00               926 	mov	r0,#_respondstr
   0551 74 2C               927 	mov	a,#__str_0
   0553 F2                  928 	movx	@r0,a
   0554 08                  929 	inc	r0
   0555 74 23               930 	mov	a,#(__str_0 >> 8)
   0557 F2                  931 	movx	@r0,a
   0558 08                  932 	inc	r0
   0559 74 80               933 	mov	a,#0x80
   055B F2                  934 	movx	@r0,a
                    0061    935 	C$example_onewire.c$53$2$3 ==.
                            936 ;	apps/example_onewire/example_onewire.c:53: return;
   055C 80 41               937 	sjmp	00111$
   055E                     938 00104$:
                    0063    939 	C$example_onewire.c$56$1$1 ==.
                            940 ;	apps/example_onewire/example_onewire.c:56: if ( DS1820_addr[0] == 0x10) {
   055E 90 F0 75            941 	mov	dptr,#_DS1820_addr
   0561 E0                  942 	movx	a,@dptr
   0562 FF                  943 	mov	r7,a
   0563 BF 10 06            944 	cjne	r7,#0x10,00109$
                    006B    945 	C$example_onewire.c$57$2$4 ==.
                            946 ;	apps/example_onewire/example_onewire.c:57: is_DS18B20 = FALSE;
   0566 78 03               947 	mov	r0,#_is_DS18B20
   0568 E4                  948 	clr	a
   0569 F2                  949 	movx	@r0,a
   056A 80 19               950 	sjmp	00110$
   056C                     951 00109$:
                    0071    952 	C$example_onewire.c$58$1$1 ==.
                            953 ;	apps/example_onewire/example_onewire.c:58: } else if ( DS1820_addr[0] == 0x28) {
   056C BF 28 07            954 	cjne	r7,#0x28,00106$
                    0074    955 	C$example_onewire.c$59$2$5 ==.
                            956 ;	apps/example_onewire/example_onewire.c:59: is_DS18B20 = TRUE;
   056F 78 03               957 	mov	r0,#_is_DS18B20
   0571 74 01               958 	mov	a,#0x01
   0573 F2                  959 	movx	@r0,a
   0574 80 0F               960 	sjmp	00110$
   0576                     961 00106$:
                    007B    962 	C$example_onewire.c$61$2$6 ==.
                            963 ;	apps/example_onewire/example_onewire.c:61: respondstr = "No DS1820 found";
   0576 78 00               964 	mov	r0,#_respondstr
   0578 74 45               965 	mov	a,#__str_1
   057A F2                  966 	movx	@r0,a
   057B 08                  967 	inc	r0
   057C 74 23               968 	mov	a,#(__str_1 >> 8)
   057E F2                  969 	movx	@r0,a
   057F 08                  970 	inc	r0
   0580 74 80               971 	mov	a,#0x80
   0582 F2                  972 	movx	@r0,a
                    0088    973 	C$example_onewire.c$62$2$6 ==.
                            974 ;	apps/example_onewire/example_onewire.c:62: return;
   0583 80 1A               975 	sjmp	00111$
   0585                     976 00110$:
                    008A    977 	C$example_onewire.c$65$1$1 ==.
                            978 ;	apps/example_onewire/example_onewire.c:65: start_DS1820();
   0585 12 04 FB            979 	lcall	_start_DS1820
                    008D    980 	C$example_onewire.c$66$1$1 ==.
                            981 ;	apps/example_onewire/example_onewire.c:66: ds1820_time = getMs();
   0588 12 17 B6            982 	lcall	_getMs
   058B AC 82               983 	mov	r4,dpl
   058D AD 83               984 	mov	r5,dph
   058F AE F0               985 	mov	r6,b
   0591 FF                  986 	mov	r7,a
   0592 78 04               987 	mov	r0,#_ds1820_time
   0594 EC                  988 	mov	a,r4
   0595 F2                  989 	movx	@r0,a
   0596 08                  990 	inc	r0
   0597 ED                  991 	mov	a,r5
   0598 F2                  992 	movx	@r0,a
   0599 08                  993 	inc	r0
   059A EE                  994 	mov	a,r6
   059B F2                  995 	movx	@r0,a
   059C 08                  996 	inc	r0
   059D EF                  997 	mov	a,r7
   059E F2                  998 	movx	@r0,a
   059F                     999 00111$:
                    00A4   1000 	C$example_onewire.c$67$1$1 ==.
                    00A4   1001 	XG$setup_DS1820$0$0 ==.
   059F 22                 1002 	ret
                           1003 ;------------------------------------------------------------
                           1004 ;Allocation info for local variables in function 'read_DS1820'
                           1005 ;------------------------------------------------------------
                    00A5   1006 	G$read_DS1820$0$0 ==.
                    00A5   1007 	C$example_onewire.c$71$1$1 ==.
                           1008 ;	apps/example_onewire/example_onewire.c:71: int read_DS1820()
                           1009 ;	-----------------------------------------
                           1010 ;	 function read_DS1820
                           1011 ;	-----------------------------------------
   05A0                    1012 _read_DS1820:
                    00A5   1013 	C$example_onewire.c$80$1$1 ==.
                           1014 ;	apps/example_onewire/example_onewire.c:80: present = onewire_reset();
   05A0 12 09 14           1015 	lcall	_onewire_reset
                    00A8   1016 	C$example_onewire.c$81$1$1 ==.
                           1017 ;	apps/example_onewire/example_onewire.c:81: onewire_select(DS1820_addr);    
   05A3 90 F0 75           1018 	mov	dptr,#_DS1820_addr
   05A6 75 F0 00           1019 	mov	b,#0x00
   05A9 12 0A 0D           1020 	lcall	_onewire_select
                    00B1   1021 	C$example_onewire.c$82$1$1 ==.
                           1022 ;	apps/example_onewire/example_onewire.c:82: onewire_write(0xBE,0);         // Read Scratchpad
   05AC 78 19              1023 	mov	r0,#_onewire_write_PARM_2
   05AE E4                 1024 	clr	a
   05AF F2                 1025 	movx	@r0,a
   05B0 75 82 BE           1026 	mov	dpl,#0xBE
   05B3 12 09 BA           1027 	lcall	_onewire_write
                    00BB   1028 	C$example_onewire.c$83$2$2 ==.
                           1029 ;	apps/example_onewire/example_onewire.c:83: for ( i = 0; i < 9; i++) {           // we need 9 bytes
   05B6 7F 00              1030 	mov	r7,#0x00
   05B8                    1031 00103$:
   05B8 BF 09 00           1032 	cjne	r7,#0x09,00113$
   05BB                    1033 00113$:
   05BB 50 15              1034 	jnc	00106$
                    00C2   1035 	C$example_onewire.c$84$2$2 ==.
                           1036 ;	apps/example_onewire/example_onewire.c:84: dataread[i] = onewire_read();
   05BD EF                 1037 	mov	a,r7
   05BE 24 08              1038 	add	a,#_read_DS1820_dataread_1_1
   05C0 F9                 1039 	mov	r1,a
   05C1 C0 07              1040 	push	ar7
   05C3 C0 01              1041 	push	ar1
   05C5 12 09 EC           1042 	lcall	_onewire_read
   05C8 E5 82              1043 	mov	a,dpl
   05CA D0 01              1044 	pop	ar1
   05CC D0 07              1045 	pop	ar7
   05CE F3                 1046 	movx	@r1,a
                    00D4   1047 	C$example_onewire.c$83$1$1 ==.
                           1048 ;	apps/example_onewire/example_onewire.c:83: for ( i = 0; i < 9; i++) {           // we need 9 bytes
   05CF 0F                 1049 	inc	r7
   05D0 80 E6              1050 	sjmp	00103$
   05D2                    1051 00106$:
                    00D7   1052 	C$example_onewire.c$86$1$1 ==.
                           1053 ;	apps/example_onewire/example_onewire.c:86: temp_read = ((dataread[1] << 8) | dataread[0]);
   05D2 78 09              1054 	mov	r0,#(_read_DS1820_dataread_1_1 + 0x0001)
   05D4 E2                 1055 	movx	a,@r0
   05D5 FE                 1056 	mov	r6,a
   05D6 7F 00              1057 	mov	r7,#0x00
   05D8 78 08              1058 	mov	r0,#_read_DS1820_dataread_1_1
   05DA E2                 1059 	movx	a,@r0
   05DB FD                 1060 	mov	r5,a
   05DC 7C 00              1061 	mov	r4,#0x00
   05DE 42 07              1062 	orl	ar7,a
   05E0 EC                 1063 	mov	a,r4
   05E1 42 06              1064 	orl	ar6,a
                    00E8   1065 	C$example_onewire.c$87$1$1 ==.
                           1066 ;	apps/example_onewire/example_onewire.c:87: if (!is_DS18B20) {
   05E3 78 03              1067 	mov	r0,#_is_DS18B20
   05E5 E2                 1068 	movx	a,@r0
   05E6 60 03              1069 	jz	00115$
   05E8 02 06 6D           1070 	ljmp	00102$
   05EB                    1071 00115$:
                    00F0   1072 	C$example_onewire.c$89$1$1 ==.
                           1073 ;	apps/example_onewire/example_onewire.c:89: temp_read *= 8.0;
   05EB 8F 82              1074 	mov	dpl,r7
   05ED 8E 83              1075 	mov	dph,r6
   05EF 12 19 E8           1076 	lcall	___sint2fs
   05F2 AA 82              1077 	mov	r2,dpl
   05F4 AB 83              1078 	mov	r3,dph
   05F6 AC F0              1079 	mov	r4,b
   05F8 FD                 1080 	mov	r5,a
   05F9 C0 02              1081 	push	ar2
   05FB C0 03              1082 	push	ar3
   05FD C0 04              1083 	push	ar4
   05FF C0 05              1084 	push	ar5
   0601 90 00 00           1085 	mov	dptr,#(0x00&0x00ff)
   0604 E4                 1086 	clr	a
   0605 F5 F0              1087 	mov	b,a
   0607 74 41              1088 	mov	a,#0x41
   0609 12 0C 4E           1089 	lcall	___fsmul
   060C AA 82              1090 	mov	r2,dpl
   060E AB 83              1091 	mov	r3,dph
   0610 AC F0              1092 	mov	r4,b
   0612 FD                 1093 	mov	r5,a
   0613 E5 81              1094 	mov	a,sp
   0615 24 FC              1095 	add	a,#0xfc
   0617 F5 81              1096 	mov	sp,a
   0619 8A 82              1097 	mov	dpl,r2
   061B 8B 83              1098 	mov	dph,r3
   061D 8C F0              1099 	mov	b,r4
   061F ED                 1100 	mov	a,r5
   0620 12 19 F5           1101 	lcall	___fs2sint
   0623 AF 82              1102 	mov	r7,dpl
   0625 AE 83              1103 	mov	r6,dph
                    012C   1104 	C$example_onewire.c$91$2$3 ==.
                           1105 ;	apps/example_onewire/example_onewire.c:91: temp_read += - ( 8 * (dataread[7]- dataread[6]) )/dataread[7];
   0627 78 0F              1106 	mov	r0,#(_read_DS1820_dataread_1_1 + 0x0007)
   0629 E2                 1107 	movx	a,@r0
   062A FD                 1108 	mov	r5,a
   062B 7C 00              1109 	mov	r4,#0x00
   062D 78 0E              1110 	mov	r0,#(_read_DS1820_dataread_1_1 + 0x0006)
   062F E2                 1111 	movx	a,@r0
   0630 FB                 1112 	mov	r3,a
   0631 7A 00              1113 	mov	r2,#0x00
   0633 ED                 1114 	mov	a,r5
   0634 C3                 1115 	clr	c
   0635 9B                 1116 	subb	a,r3
   0636 FB                 1117 	mov	r3,a
   0637 EC                 1118 	mov	a,r4
   0638 9A                 1119 	subb	a,r2
   0639 C4                 1120 	swap	a
   063A 03                 1121 	rr	a
   063B 54 F8              1122 	anl	a,#0xF8
   063D CB                 1123 	xch	a,r3
   063E C4                 1124 	swap	a
   063F 03                 1125 	rr	a
   0640 CB                 1126 	xch	a,r3
   0641 6B                 1127 	xrl	a,r3
   0642 CB                 1128 	xch	a,r3
   0643 54 F8              1129 	anl	a,#0xF8
   0645 CB                 1130 	xch	a,r3
   0646 6B                 1131 	xrl	a,r3
   0647 FA                 1132 	mov	r2,a
   0648 C3                 1133 	clr	c
   0649 E4                 1134 	clr	a
   064A 9B                 1135 	subb	a,r3
   064B F5 82              1136 	mov	dpl,a
   064D E4                 1137 	clr	a
   064E 9A                 1138 	subb	a,r2
   064F F5 83              1139 	mov	dph,a
   0651 78 4C              1140 	mov	r0,#__divsint_PARM_2
   0653 ED                 1141 	mov	a,r5
   0654 F2                 1142 	movx	@r0,a
   0655 08                 1143 	inc	r0
   0656 EC                 1144 	mov	a,r4
   0657 F2                 1145 	movx	@r0,a
   0658 C0 07              1146 	push	ar7
   065A C0 06              1147 	push	ar6
   065C 12 18 16           1148 	lcall	__divsint
   065F AC 82              1149 	mov	r4,dpl
   0661 AD 83              1150 	mov	r5,dph
   0663 D0 06              1151 	pop	ar6
   0665 D0 07              1152 	pop	ar7
   0667 EC                 1153 	mov	a,r4
   0668 2F                 1154 	add	a,r7
   0669 FF                 1155 	mov	r7,a
   066A ED                 1156 	mov	a,r5
   066B 3E                 1157 	addc	a,r6
   066C FE                 1158 	mov	r6,a
   066D                    1159 00102$:
                    0172   1160 	C$example_onewire.c$93$1$1 ==.
                           1161 ;	apps/example_onewire/example_onewire.c:93: return temp_read;
   066D 8F 82              1162 	mov	dpl,r7
   066F 8E 83              1163 	mov	dph,r6
                    0176   1164 	C$example_onewire.c$94$1$1 ==.
                    0176   1165 	XG$read_DS1820$0$0 ==.
   0671 22                 1166 	ret
                           1167 ;------------------------------------------------------------
                           1168 ;Allocation info for local variables in function 'updateLeds'
                           1169 ;------------------------------------------------------------
                    0177   1170 	G$updateLeds$0$0 ==.
                    0177   1171 	C$example_onewire.c$97$1$1 ==.
                           1172 ;	apps/example_onewire/example_onewire.c:97: void updateLeds()
                           1173 ;	-----------------------------------------
                           1174 ;	 function updateLeds
                           1175 ;	-----------------------------------------
   0672                    1176 _updateLeds:
                    0177   1177 	C$example_onewire.c$99$1$1 ==.
                           1178 ;	apps/example_onewire/example_onewire.c:99: usbShowStatusWithGreenLed();
   0672 12 1A 29           1179 	lcall	_usbShowStatusWithGreenLed
                    017A   1180 	C$example_onewire.c$104$2$2 ==.
                           1181 ;	apps/example_onewire/example_onewire.c:104: LED_RED(0);
   0675 AF FF              1182 	mov	r7,_P2DIR
   0677 53 07 FD           1183 	anl	ar7,#0xFD
   067A 8F FF              1184 	mov	_P2DIR,r7
                    0181   1185 	C$example_onewire.c$105$2$2 ==.
                    0181   1186 	XG$updateLeds$0$0 ==.
   067C 22                 1187 	ret
                           1188 ;------------------------------------------------------------
                           1189 ;Allocation info for local variables in function 'nibbleToAscii'
                           1190 ;------------------------------------------------------------
                    0182   1191 	G$nibbleToAscii$0$0 ==.
                    0182   1192 	C$example_onewire.c$107$2$2 ==.
                           1193 ;	apps/example_onewire/example_onewire.c:107: uint8 nibbleToAscii(uint8 nibble)
                           1194 ;	-----------------------------------------
                           1195 ;	 function nibbleToAscii
                           1196 ;	-----------------------------------------
   067D                    1197 _nibbleToAscii:
                    0182   1198 	C$example_onewire.c$109$1$1 ==.
                           1199 ;	apps/example_onewire/example_onewire.c:109: nibble &= 0xF;
                    0182   1200 	C$example_onewire.c$110$1$1 ==.
                           1201 ;	apps/example_onewire/example_onewire.c:110: if (nibble <= 0x9){ return '0' + nibble; }
   067D E5 82              1202 	mov	a,dpl
   067F 54 0F              1203 	anl	a,#0x0F
   0681 FF                 1204 	mov	r7,a
   0682 24 F6              1205 	add	a,#0xff - 0x09
   0684 40 0A              1206 	jc	00102$
   0686 8F 06              1207 	mov	ar6,r7
   0688 74 30              1208 	mov	a,#0x30
   068A 2E                 1209 	add	a,r6
   068B FE                 1210 	mov	r6,a
   068C F5 82              1211 	mov	dpl,a
   068E 80 05              1212 	sjmp	00104$
   0690                    1213 00102$:
                    0195   1214 	C$example_onewire.c$111$2$3 ==.
                           1215 ;	apps/example_onewire/example_onewire.c:111: else{ return 'A' + (nibble - 0xA); }
   0690 74 37              1216 	mov	a,#0x37
   0692 2F                 1217 	add	a,r7
                    0198   1218 	C$example_onewire.c$112$1$1 ==.
                    0198   1219 	XG$nibbleToAscii$0$0 ==.
   0693 F5 82              1220 	mov	dpl,a
   0695                    1221 00104$:
   0695 22                 1222 	ret
                           1223 ;------------------------------------------------------------
                           1224 ;Allocation info for local variables in function 'handleOneWire'
                           1225 ;------------------------------------------------------------
                           1226 ;sloc0                     Allocated with name '_handleOneWire_sloc0_1_0'
                           1227 ;sloc1                     Allocated with name '_handleOneWire_sloc1_1_0'
                           1228 ;response                  Allocated with name '_handleOneWire_response_2_3'
                           1229 ;------------------------------------------------------------
                    019B   1230 	G$handleOneWire$0$0 ==.
                    019B   1231 	C$example_onewire.c$114$1$1 ==.
                           1232 ;	apps/example_onewire/example_onewire.c:114: void handleOneWire(void)
                           1233 ;	-----------------------------------------
                           1234 ;	 function handleOneWire
                           1235 ;	-----------------------------------------
   0696                    1236 _handleOneWire:
                    019B   1237 	C$example_onewire.c$117$1$1 ==.
                           1238 ;	apps/example_onewire/example_onewire.c:117: int newtemp = 0;
   0696 7B 00              1239 	mov	r3,#0x00
   0698 7A 00              1240 	mov	r2,#0x00
                    019F   1241 	C$example_onewire.c$118$1$1 ==.
                           1242 ;	apps/example_onewire/example_onewire.c:118: int air_temp_c = 0;
   069A 78 14              1243 	mov	r0,#_handleOneWire_air_temp_c_1_1
   069C E4                 1244 	clr	a
   069D F2                 1245 	movx	@r0,a
   069E 08                 1246 	inc	r0
   069F F2                 1247 	movx	@r0,a
                    01A5   1248 	C$example_onewire.c$121$1$1 ==.
                           1249 ;	apps/example_onewire/example_onewire.c:121: if (getMs() > ds1820_time + 1000) {
   06A0 C0 03              1250 	push	ar3
   06A2 C0 02              1251 	push	ar2
   06A4 12 17 B6           1252 	lcall	_getMs
   06A7 85 82 08           1253 	mov	_handleOneWire_sloc0_1_0,dpl
   06AA 85 83 09           1254 	mov	(_handleOneWire_sloc0_1_0 + 1),dph
   06AD 85 F0 0A           1255 	mov	(_handleOneWire_sloc0_1_0 + 2),b
   06B0 F5 0B              1256 	mov	(_handleOneWire_sloc0_1_0 + 3),a
   06B2 D0 02              1257 	pop	ar2
   06B4 D0 03              1258 	pop	ar3
   06B6 78 04              1259 	mov	r0,#_ds1820_time
   06B8 E2                 1260 	movx	a,@r0
   06B9 24 E8              1261 	add	a,#0xE8
   06BB FC                 1262 	mov	r4,a
   06BC 08                 1263 	inc	r0
   06BD E2                 1264 	movx	a,@r0
   06BE 34 03              1265 	addc	a,#0x03
   06C0 FD                 1266 	mov	r5,a
   06C1 08                 1267 	inc	r0
   06C2 E2                 1268 	movx	a,@r0
   06C3 34 00              1269 	addc	a,#0x00
   06C5 FE                 1270 	mov	r6,a
   06C6 08                 1271 	inc	r0
   06C7 E2                 1272 	movx	a,@r0
   06C8 34 00              1273 	addc	a,#0x00
   06CA FF                 1274 	mov	r7,a
   06CB C3                 1275 	clr	c
   06CC EC                 1276 	mov	a,r4
   06CD 95 08              1277 	subb	a,_handleOneWire_sloc0_1_0
   06CF ED                 1278 	mov	a,r5
   06D0 95 09              1279 	subb	a,(_handleOneWire_sloc0_1_0 + 1)
   06D2 EE                 1280 	mov	a,r6
   06D3 95 0A              1281 	subb	a,(_handleOneWire_sloc0_1_0 + 2)
   06D5 EF                 1282 	mov	a,r7
   06D6 95 0B              1283 	subb	a,(_handleOneWire_sloc0_1_0 + 3)
   06D8 50 32              1284 	jnc	00102$
                    01DF   1285 	C$example_onewire.c$122$2$2 ==.
                           1286 ;	apps/example_onewire/example_onewire.c:122: air_temp_c = read_DS1820();
   06DA 12 05 A0           1287 	lcall	_read_DS1820
   06DD 78 14              1288 	mov	r0,#_handleOneWire_air_temp_c_1_1
   06DF E5 82              1289 	mov	a,dpl
   06E1 F2                 1290 	movx	@r0,a
   06E2 08                 1291 	inc	r0
   06E3 E5 83              1292 	mov	a,dph
   06E5 F2                 1293 	movx	@r0,a
                    01EB   1294 	C$example_onewire.c$123$2$2 ==.
                           1295 ;	apps/example_onewire/example_onewire.c:123: newtemp++;
   06E6 7B 01              1296 	mov	r3,#0x01
   06E8 7A 00              1297 	mov	r2,#0x00
                    01EF   1298 	C$example_onewire.c$124$2$2 ==.
                           1299 ;	apps/example_onewire/example_onewire.c:124: start_DS1820();
   06EA C0 03              1300 	push	ar3
   06EC C0 02              1301 	push	ar2
   06EE 12 04 FB           1302 	lcall	_start_DS1820
                    01F6   1303 	C$example_onewire.c$125$2$2 ==.
                           1304 ;	apps/example_onewire/example_onewire.c:125: ds1820_time = getMs();
   06F1 12 17 B6           1305 	lcall	_getMs
   06F4 AC 82              1306 	mov	r4,dpl
   06F6 AD 83              1307 	mov	r5,dph
   06F8 AE F0              1308 	mov	r6,b
   06FA FF                 1309 	mov	r7,a
   06FB D0 02              1310 	pop	ar2
   06FD D0 03              1311 	pop	ar3
   06FF 78 04              1312 	mov	r0,#_ds1820_time
   0701 EC                 1313 	mov	a,r4
   0702 F2                 1314 	movx	@r0,a
   0703 08                 1315 	inc	r0
   0704 ED                 1316 	mov	a,r5
   0705 F2                 1317 	movx	@r0,a
   0706 08                 1318 	inc	r0
   0707 EE                 1319 	mov	a,r6
   0708 F2                 1320 	movx	@r0,a
   0709 08                 1321 	inc	r0
   070A EF                 1322 	mov	a,r7
   070B F2                 1323 	movx	@r0,a
   070C                    1324 00102$:
                    0211   1325 	C$example_onewire.c$128$1$1 ==.
                           1326 ;	apps/example_onewire/example_onewire.c:128: if ((newtemp || respondstr) && usbComTxAvailable() >= 64)
   070C EB                 1327 	mov	a,r3
   070D 4A                 1328 	orl	a,r2
   070E 70 0E              1329 	jnz	00108$
   0710 78 00              1330 	mov	r0,#_respondstr
   0712 E2                 1331 	movx	a,@r0
   0713 F5 F0              1332 	mov	b,a
   0715 08                 1333 	inc	r0
   0716 E2                 1334 	movx	a,@r0
   0717 45 F0              1335 	orl	a,b
   0719 70 03              1336 	jnz	00133$
   071B 02 08 F7           1337 	ljmp	00118$
   071E                    1338 00133$:
   071E                    1339 00108$:
   071E 12 0F 5C           1340 	lcall	_usbComTxAvailable
   0721 AF 82              1341 	mov	r7,dpl
   0723 BF 40 00           1342 	cjne	r7,#0x40,00134$
   0726                    1343 00134$:
   0726 50 03              1344 	jnc	00135$
   0728 02 08 F7           1345 	ljmp	00118$
   072B                    1346 00135$:
                    0230   1347 	C$example_onewire.c$134$2$3 ==.
                           1348 ;	apps/example_onewire/example_onewire.c:134: decimals = (air_temp_c & 0xf) * 100;
   072B 78 14              1349 	mov	r0,#_handleOneWire_air_temp_c_1_1
   072D 79 46              1350 	mov	r1,#__mulint_PARM_2
   072F E2                 1351 	movx	a,@r0
   0730 54 0F              1352 	anl	a,#0x0F
   0732 F3                 1353 	movx	@r1,a
   0733 08                 1354 	inc	r0
   0734 E2                 1355 	movx	a,@r0
   0735 54 00              1356 	anl	a,#0x00
   0737 09                 1357 	inc	r1
   0738 F3                 1358 	movx	@r1,a
   0739 90 00 64           1359 	mov	dptr,#0x0064
   073C 12 17 71           1360 	lcall	__mulint
   073F AE 82              1361 	mov	r6,dpl
                    0246   1362 	C$example_onewire.c$135$2$3 ==.
                           1363 ;	apps/example_onewire/example_onewire.c:135: responseLength = sprintf(response, "%d.%02d", air_temp_c / 16, decimals / 16);
   0741 E5 83              1364 	mov	a,dph
   0743 C4                 1365 	swap	a
   0744 CE                 1366 	xch	a,r6
   0745 C4                 1367 	swap	a
   0746 54 0F              1368 	anl	a,#0x0F
   0748 6E                 1369 	xrl	a,r6
   0749 CE                 1370 	xch	a,r6
   074A 54 0F              1371 	anl	a,#0x0F
   074C CE                 1372 	xch	a,r6
   074D 6E                 1373 	xrl	a,r6
   074E CE                 1374 	xch	a,r6
   074F FF                 1375 	mov	r7,a
   0750 78 4C              1376 	mov	r0,#__divsint_PARM_2
   0752 74 10              1377 	mov	a,#0x10
   0754 F2                 1378 	movx	@r0,a
   0755 08                 1379 	inc	r0
   0756 E4                 1380 	clr	a
   0757 F2                 1381 	movx	@r0,a
   0758 78 14              1382 	mov	r0,#_handleOneWire_air_temp_c_1_1
   075A E2                 1383 	movx	a,@r0
   075B F5 82              1384 	mov	dpl,a
   075D 08                 1385 	inc	r0
   075E E2                 1386 	movx	a,@r0
   075F F5 83              1387 	mov	dph,a
   0761 C0 07              1388 	push	ar7
   0763 C0 06              1389 	push	ar6
   0765 12 18 16           1390 	lcall	__divsint
   0768 AC 82              1391 	mov	r4,dpl
   076A AD 83              1392 	mov	r5,dph
   076C D0 06              1393 	pop	ar6
   076E D0 07              1394 	pop	ar7
   0770 C0 06              1395 	push	ar6
   0772 C0 07              1396 	push	ar7
   0774 C0 04              1397 	push	ar4
   0776 C0 05              1398 	push	ar5
   0778 74 55              1399 	mov	a,#__str_2
   077A C0 E0              1400 	push	acc
   077C 74 23              1401 	mov	a,#(__str_2 >> 8)
   077E C0 E0              1402 	push	acc
   0780 74 80              1403 	mov	a,#0x80
   0782 C0 E0              1404 	push	acc
   0784 74 7D              1405 	mov	a,#_handleOneWire_response_2_3
   0786 C0 E0              1406 	push	acc
   0788 74 F0              1407 	mov	a,#(_handleOneWire_response_2_3 >> 8)
   078A C0 E0              1408 	push	acc
   078C E4                 1409 	clr	a
   078D C0 E0              1410 	push	acc
   078F 12 19 95           1411 	lcall	_sprintf
   0792 AE 82              1412 	mov	r6,dpl
   0794 E5 81              1413 	mov	a,sp
   0796 24 F6              1414 	add	a,#0xf6
   0798 F5 81              1415 	mov	sp,a
                    029F   1416 	C$example_onewire.c$136$2$3 ==.
                           1417 ;	apps/example_onewire/example_onewire.c:136: response[responseLength++] = ',';
   079A 8E 07              1418 	mov	ar7,r6
   079C 0E                 1419 	inc	r6
   079D EF                 1420 	mov	a,r7
   079E 24 7D              1421 	add	a,#_handleOneWire_response_2_3
   07A0 F5 82              1422 	mov	dpl,a
   07A2 E4                 1423 	clr	a
   07A3 34 F0              1424 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   07A5 F5 83              1425 	mov	dph,a
   07A7 74 2C              1426 	mov	a,#0x2C
   07A9 F0                 1427 	movx	@dptr,a
                    02AF   1428 	C$example_onewire.c$137$2$1 ==.
                           1429 ;	apps/example_onewire/example_onewire.c:137: for (i = 0; i < 8; i++) {
   07AA 7D 00              1430 	mov	r5,#0x00
   07AC 7F 00              1431 	mov	r7,#0x00
   07AE                    1432 00109$:
   07AE C3                 1433 	clr	c
   07AF ED                 1434 	mov	a,r5
   07B0 94 08              1435 	subb	a,#0x08
   07B2 EF                 1436 	mov	a,r7
   07B3 64 80              1437 	xrl	a,#0x80
   07B5 94 80              1438 	subb	a,#0x80
   07B7 50 79              1439 	jnc	00112$
                    02BE   1440 	C$example_onewire.c$138$3$4 ==.
                           1441 ;	apps/example_onewire/example_onewire.c:138: response[responseLength++] = nibbleToAscii(DS1820_addr[i] >> 4);
   07B9 8E 04              1442 	mov	ar4,r6
   07BB 0E                 1443 	inc	r6
   07BC EC                 1444 	mov	a,r4
   07BD 24 7D              1445 	add	a,#_handleOneWire_response_2_3
   07BF FC                 1446 	mov	r4,a
   07C0 E4                 1447 	clr	a
   07C1 34 F0              1448 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   07C3 FB                 1449 	mov	r3,a
   07C4 ED                 1450 	mov	a,r5
   07C5 24 75              1451 	add	a,#_DS1820_addr
   07C7 F5 82              1452 	mov	dpl,a
   07C9 EF                 1453 	mov	a,r7
   07CA 34 F0              1454 	addc	a,#(_DS1820_addr >> 8)
   07CC F5 83              1455 	mov	dph,a
   07CE E0                 1456 	movx	a,@dptr
   07CF C4                 1457 	swap	a
   07D0 54 0F              1458 	anl	a,#0x0F
   07D2 F5 82              1459 	mov	dpl,a
   07D4 C0 07              1460 	push	ar7
   07D6 C0 06              1461 	push	ar6
   07D8 C0 05              1462 	push	ar5
   07DA C0 04              1463 	push	ar4
   07DC C0 03              1464 	push	ar3
   07DE 12 06 7D           1465 	lcall	_nibbleToAscii
   07E1 AA 82              1466 	mov	r2,dpl
   07E3 D0 03              1467 	pop	ar3
   07E5 D0 04              1468 	pop	ar4
   07E7 D0 05              1469 	pop	ar5
   07E9 D0 06              1470 	pop	ar6
   07EB D0 07              1471 	pop	ar7
   07ED 8C 82              1472 	mov	dpl,r4
   07EF 8B 83              1473 	mov	dph,r3
   07F1 EA                 1474 	mov	a,r2
   07F2 F0                 1475 	movx	@dptr,a
                    02F8   1476 	C$example_onewire.c$139$3$4 ==.
                           1477 ;	apps/example_onewire/example_onewire.c:139: response[responseLength++] = nibbleToAscii(DS1820_addr[i]);
   07F3 8E 04              1478 	mov	ar4,r6
   07F5 0E                 1479 	inc	r6
   07F6 EC                 1480 	mov	a,r4
   07F7 24 7D              1481 	add	a,#_handleOneWire_response_2_3
   07F9 FC                 1482 	mov	r4,a
   07FA E4                 1483 	clr	a
   07FB 34 F0              1484 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   07FD FB                 1485 	mov	r3,a
   07FE ED                 1486 	mov	a,r5
   07FF 24 75              1487 	add	a,#_DS1820_addr
   0801 F5 82              1488 	mov	dpl,a
   0803 EF                 1489 	mov	a,r7
   0804 34 F0              1490 	addc	a,#(_DS1820_addr >> 8)
   0806 F5 83              1491 	mov	dph,a
   0808 E0                 1492 	movx	a,@dptr
   0809 F5 82              1493 	mov	dpl,a
   080B C0 07              1494 	push	ar7
   080D C0 06              1495 	push	ar6
   080F C0 05              1496 	push	ar5
   0811 C0 04              1497 	push	ar4
   0813 C0 03              1498 	push	ar3
   0815 12 06 7D           1499 	lcall	_nibbleToAscii
   0818 AA 82              1500 	mov	r2,dpl
   081A D0 03              1501 	pop	ar3
   081C D0 04              1502 	pop	ar4
   081E D0 05              1503 	pop	ar5
   0820 D0 06              1504 	pop	ar6
   0822 D0 07              1505 	pop	ar7
   0824 8C 82              1506 	mov	dpl,r4
   0826 8B 83              1507 	mov	dph,r3
   0828 EA                 1508 	mov	a,r2
   0829 F0                 1509 	movx	@dptr,a
                    032F   1510 	C$example_onewire.c$137$2$3 ==.
                           1511 ;	apps/example_onewire/example_onewire.c:137: for (i = 0; i < 8; i++) {
   082A 0D                 1512 	inc	r5
   082B BD 00 01           1513 	cjne	r5,#0x00,00137$
   082E 0F                 1514 	inc	r7
   082F                    1515 00137$:
   082F 02 07 AE           1516 	ljmp	00109$
   0832                    1517 00112$:
                    0337   1518 	C$example_onewire.c$141$2$3 ==.
                           1519 ;	apps/example_onewire/example_onewire.c:141: response[responseLength++] = ',';
   0832 8E 07              1520 	mov	ar7,r6
   0834 0E                 1521 	inc	r6
   0835 EF                 1522 	mov	a,r7
   0836 24 7D              1523 	add	a,#_handleOneWire_response_2_3
   0838 F5 82              1524 	mov	dpl,a
   083A E4                 1525 	clr	a
   083B 34 F0              1526 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   083D F5 83              1527 	mov	dph,a
   083F 74 2C              1528 	mov	a,#0x2C
   0841 F0                 1529 	movx	@dptr,a
                    0347   1530 	C$example_onewire.c$142$2$3 ==.
                           1531 ;	apps/example_onewire/example_onewire.c:142: i = sizeof(response) - responseLength - 2;
   0842 8E 05              1532 	mov	ar5,r6
   0844 7F 00              1533 	mov	r7,#0x00
   0846 74 3E              1534 	mov	a,#0x3E
   0848 C3                 1535 	clr	c
   0849 9D                 1536 	subb	a,r5
   084A FD                 1537 	mov	r5,a
   084B E4                 1538 	clr	a
   084C 9F                 1539 	subb	a,r7
   084D FF                 1540 	mov	r7,a
                    0353   1541 	C$example_onewire.c$144$2$3 ==.
                           1542 ;	apps/example_onewire/example_onewire.c:144: if (respondstr) {
   084E 78 00              1543 	mov	r0,#_respondstr
   0850 E2                 1544 	movx	a,@r0
   0851 F5 F0              1545 	mov	b,a
   0853 08                 1546 	inc	r0
   0854 E2                 1547 	movx	a,@r0
   0855 45 F0              1548 	orl	a,b
   0857 60 6E              1549 	jz	00104$
                    035E   1550 	C$example_onewire.c$145$3$5 ==.
                           1551 ;	apps/example_onewire/example_onewire.c:145: for (cp = respondstr; *respondstr && i--; respondstr++) {
   0859 78 00              1552 	mov	r0,#_respondstr
   085B 79 16              1553 	mov	r1,#_handleOneWire_cp_2_3
   085D E2                 1554 	movx	a,@r0
   085E F3                 1555 	movx	@r1,a
   085F 08                 1556 	inc	r0
   0860 E2                 1557 	movx	a,@r0
   0861 09                 1558 	inc	r1
   0862 F3                 1559 	movx	@r1,a
   0863 08                 1560 	inc	r0
   0864 E2                 1561 	movx	a,@r0
   0865 09                 1562 	inc	r1
   0866 F3                 1563 	movx	@r1,a
   0867 8E 08              1564 	mov	_handleOneWire_sloc0_1_0,r6
   0869                    1565 00114$:
   0869 78 00              1566 	mov	r0,#_respondstr
   086B E2                 1567 	movx	a,@r0
   086C F5 0C              1568 	mov	_handleOneWire_sloc1_1_0,a
   086E 08                 1569 	inc	r0
   086F E2                 1570 	movx	a,@r0
   0870 F5 0D              1571 	mov	(_handleOneWire_sloc1_1_0 + 1),a
   0872 08                 1572 	inc	r0
   0873 E2                 1573 	movx	a,@r0
   0874 F5 0E              1574 	mov	(_handleOneWire_sloc1_1_0 + 2),a
   0876 85 0C 82           1575 	mov	dpl,_handleOneWire_sloc1_1_0
   0879 85 0D 83           1576 	mov	dph,(_handleOneWire_sloc1_1_0 + 1)
   087C 85 0E F0           1577 	mov	b,(_handleOneWire_sloc1_1_0 + 2)
   087F 12 22 2F           1578 	lcall	__gptrget
   0882 60 41              1579 	jz	00130$
   0884 8D 03              1580 	mov	ar3,r5
   0886 8F 04              1581 	mov	ar4,r7
   0888 1D                 1582 	dec	r5
   0889 BD FF 01           1583 	cjne	r5,#0xFF,00140$
   088C 1F                 1584 	dec	r7
   088D                    1585 00140$:
   088D EB                 1586 	mov	a,r3
   088E 4C                 1587 	orl	a,r4
   088F 60 34              1588 	jz	00130$
                    0396   1589 	C$example_onewire.c$146$4$6 ==.
                           1590 ;	apps/example_onewire/example_onewire.c:146: response[responseLength++] = *cp;
   0891 AC 08              1591 	mov	r4,_handleOneWire_sloc0_1_0
   0893 05 08              1592 	inc	_handleOneWire_sloc0_1_0
   0895 EC                 1593 	mov	a,r4
   0896 24 7D              1594 	add	a,#_handleOneWire_response_2_3
   0898 FC                 1595 	mov	r4,a
   0899 E4                 1596 	clr	a
   089A 34 F0              1597 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   089C FB                 1598 	mov	r3,a
   089D 78 16              1599 	mov	r0,#_handleOneWire_cp_2_3
   089F E2                 1600 	movx	a,@r0
   08A0 F5 82              1601 	mov	dpl,a
   08A2 08                 1602 	inc	r0
   08A3 E2                 1603 	movx	a,@r0
   08A4 F5 83              1604 	mov	dph,a
   08A6 08                 1605 	inc	r0
   08A7 E2                 1606 	movx	a,@r0
   08A8 F5 F0              1607 	mov	b,a
   08AA 12 22 2F           1608 	lcall	__gptrget
   08AD FA                 1609 	mov	r2,a
   08AE 8C 82              1610 	mov	dpl,r4
   08B0 8B 83              1611 	mov	dph,r3
   08B2 F0                 1612 	movx	@dptr,a
                    03B8   1613 	C$example_onewire.c$145$3$5 ==.
                           1614 ;	apps/example_onewire/example_onewire.c:145: for (cp = respondstr; *respondstr && i--; respondstr++) {
   08B3 78 00              1615 	mov	r0,#_respondstr
   08B5 74 01              1616 	mov	a,#0x01
   08B7 25 0C              1617 	add	a,_handleOneWire_sloc1_1_0
   08B9 F2                 1618 	movx	@r0,a
   08BA E4                 1619 	clr	a
   08BB 35 0D              1620 	addc	a,(_handleOneWire_sloc1_1_0 + 1)
   08BD 08                 1621 	inc	r0
   08BE F2                 1622 	movx	@r0,a
   08BF 08                 1623 	inc	r0
   08C0 E5 0E              1624 	mov	a,(_handleOneWire_sloc1_1_0 + 2)
   08C2 F2                 1625 	movx	@r0,a
   08C3 80 A4              1626 	sjmp	00114$
   08C5                    1627 00130$:
   08C5 AE 08              1628 	mov	r6,_handleOneWire_sloc0_1_0
   08C7                    1629 00104$:
                    03CC   1630 	C$example_onewire.c$149$2$3 ==.
                           1631 ;	apps/example_onewire/example_onewire.c:149: respondstr = NULL;
   08C7 78 00              1632 	mov	r0,#_respondstr
   08C9 E4                 1633 	clr	a
   08CA F2                 1634 	movx	@r0,a
   08CB 08                 1635 	inc	r0
   08CC F2                 1636 	movx	@r0,a
   08CD 08                 1637 	inc	r0
   08CE F2                 1638 	movx	@r0,a
                    03D4   1639 	C$example_onewire.c$150$2$3 ==.
                           1640 ;	apps/example_onewire/example_onewire.c:150: response[responseLength++] = '\r';
   08CF 8E 07              1641 	mov	ar7,r6
   08D1 0E                 1642 	inc	r6
   08D2 EF                 1643 	mov	a,r7
   08D3 24 7D              1644 	add	a,#_handleOneWire_response_2_3
   08D5 F5 82              1645 	mov	dpl,a
   08D7 E4                 1646 	clr	a
   08D8 34 F0              1647 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   08DA F5 83              1648 	mov	dph,a
   08DC 74 0D              1649 	mov	a,#0x0D
   08DE F0                 1650 	movx	@dptr,a
                    03E4   1651 	C$example_onewire.c$151$2$3 ==.
                           1652 ;	apps/example_onewire/example_onewire.c:151: response[responseLength++] = '\n';
   08DF 78 36              1653 	mov	r0,#_usbComTxSend_PARM_2
   08E1 EE                 1654 	mov	a,r6
   08E2 04                 1655 	inc	a
   08E3 F2                 1656 	movx	@r0,a
   08E4 EE                 1657 	mov	a,r6
   08E5 24 7D              1658 	add	a,#_handleOneWire_response_2_3
   08E7 F5 82              1659 	mov	dpl,a
   08E9 E4                 1660 	clr	a
   08EA 34 F0              1661 	addc	a,#(_handleOneWire_response_2_3 >> 8)
   08EC F5 83              1662 	mov	dph,a
   08EE 74 0A              1663 	mov	a,#0x0A
   08F0 F0                 1664 	movx	@dptr,a
                    03F6   1665 	C$example_onewire.c$152$2$3 ==.
                           1666 ;	apps/example_onewire/example_onewire.c:152: usbComTxSend(response, responseLength);
   08F1 90 F0 7D           1667 	mov	dptr,#_handleOneWire_response_2_3
   08F4 12 0F 93           1668 	lcall	_usbComTxSend
   08F7                    1669 00118$:
                    03FC   1670 	C$example_onewire.c$154$2$1 ==.
                    03FC   1671 	XG$handleOneWire$0$0 ==.
   08F7 22                 1672 	ret
                           1673 ;------------------------------------------------------------
                           1674 ;Allocation info for local variables in function 'main'
                           1675 ;------------------------------------------------------------
                    03FD   1676 	G$main$0$0 ==.
                    03FD   1677 	C$example_onewire.c$156$2$1 ==.
                           1678 ;	apps/example_onewire/example_onewire.c:156: void main()
                           1679 ;	-----------------------------------------
                           1680 ;	 function main
                           1681 ;	-----------------------------------------
   08F8                    1682 _main:
                    03FD   1683 	C$example_onewire.c$158$1$1 ==.
                           1684 ;	apps/example_onewire/example_onewire.c:158: systemInit();
   08F8 12 16 7F           1685 	lcall	_systemInit
                    0400   1686 	C$example_onewire.c$160$1$1 ==.
                           1687 ;	apps/example_onewire/example_onewire.c:160: usbInit();
   08FB 12 10 19           1688 	lcall	_usbInit
                    0403   1689 	C$example_onewire.c$161$1$1 ==.
                           1690 ;	apps/example_onewire/example_onewire.c:161: setup_DS1820();
   08FE 12 05 12           1691 	lcall	_setup_DS1820
                    0406   1692 	C$example_onewire.c$162$1$1 ==.
                           1693 ;	apps/example_onewire/example_onewire.c:162: while(1)
   0901                    1694 00102$:
                    0406   1695 	C$example_onewire.c$164$2$2 ==.
                           1696 ;	apps/example_onewire/example_onewire.c:164: boardService();
   0901 12 16 8C           1697 	lcall	_boardService
                    0409   1698 	C$example_onewire.c$165$2$2 ==.
                           1699 ;	apps/example_onewire/example_onewire.c:165: updateLeds();
   0904 12 06 72           1700 	lcall	_updateLeds
                    040C   1701 	C$example_onewire.c$166$2$2 ==.
                           1702 ;	apps/example_onewire/example_onewire.c:166: usbComService();
   0907 12 0E B7           1703 	lcall	_usbComService
                    040F   1704 	C$example_onewire.c$167$2$2 ==.
                           1705 ;	apps/example_onewire/example_onewire.c:167: handleOneWire();
   090A 12 06 96           1706 	lcall	_handleOneWire
   090D 80 F2              1707 	sjmp	00102$
                    0414   1708 	C$example_onewire.c$169$1$1 ==.
                    0414   1709 	XG$main$0$0 ==.
   090F 22                 1710 	ret
                           1711 	.area CSEG    (CODE)
                           1712 	.area CONST   (CODE)
                    0000   1713 Fexample_onewire$_str_0$0$0 == .
   232C                    1714 __str_0:
   232C 4E 6F 20 4F 6E 65  1715 	.ascii "No OneWire devices found"
        57 69 72 65 20 64
        65 76 69 63 65 73
        20 66 6F 75 6E 64
   2344 00                 1716 	.db 0x00
                    0019   1717 Fexample_onewire$_str_1$0$0 == .
   2345                    1718 __str_1:
   2345 4E 6F 20 44 53 31  1719 	.ascii "No DS1820 found"
        38 32 30 20 66 6F
        75 6E 64
   2354 00                 1720 	.db 0x00
                    0029   1721 Fexample_onewire$_str_2$0$0 == .
   2355                    1722 __str_2:
   2355 25 64 2E 25 30 32  1723 	.ascii "%d.%02d"
        64
   235C 00                 1724 	.db 0x00
                           1725 	.area XINIT   (CODE)
                           1726 	.area CABS    (ABS,CODE)
