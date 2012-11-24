                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Fri Aug 17 17:32:03 2012
                              5 ;--------------------------------------------------------
                              6 	.module onewire
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _delayMicroseconds
                             13 	.globl _onewire_crc8_PARM_2
                             14 	.globl _LastDeviceFlag
                             15 	.globl _LastFamilyDiscrepancy
                             16 	.globl _LastDiscrepancy
                             17 	.globl _ROM_NO
                             18 	.globl _onewire_write_PARM_2
                             19 	.globl _onewire_start
                             20 	.globl _onewire_reset
                             21 	.globl _onewire_write_bit
                             22 	.globl _onewire_read_bit
                             23 	.globl _onewire_write
                             24 	.globl _onewire_read
                             25 	.globl _onewire_select
                             26 	.globl _onewire_skip
                             27 	.globl _onewire_depower
                             28 	.globl _onewire_reset_search
                             29 	.globl _onewire_search
                             30 	.globl _onewire_crc8
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 	.area RSEG    (ABS,DATA)
   0000                      35 	.org 0x0000
                    0080     36 Fonewire$P0$0$0 == 0x0080
                    0080     37 _P0	=	0x0080
                    0081     38 Fonewire$SP$0$0 == 0x0081
                    0081     39 _SP	=	0x0081
                    0082     40 Fonewire$DPL0$0$0 == 0x0082
                    0082     41 _DPL0	=	0x0082
                    0083     42 Fonewire$DPH0$0$0 == 0x0083
                    0083     43 _DPH0	=	0x0083
                    0084     44 Fonewire$DPL1$0$0 == 0x0084
                    0084     45 _DPL1	=	0x0084
                    0085     46 Fonewire$DPH1$0$0 == 0x0085
                    0085     47 _DPH1	=	0x0085
                    0086     48 Fonewire$U0CSR$0$0 == 0x0086
                    0086     49 _U0CSR	=	0x0086
                    0087     50 Fonewire$PCON$0$0 == 0x0087
                    0087     51 _PCON	=	0x0087
                    0088     52 Fonewire$TCON$0$0 == 0x0088
                    0088     53 _TCON	=	0x0088
                    0089     54 Fonewire$P0IFG$0$0 == 0x0089
                    0089     55 _P0IFG	=	0x0089
                    008A     56 Fonewire$P1IFG$0$0 == 0x008a
                    008A     57 _P1IFG	=	0x008a
                    008B     58 Fonewire$P2IFG$0$0 == 0x008b
                    008B     59 _P2IFG	=	0x008b
                    008C     60 Fonewire$PICTL$0$0 == 0x008c
                    008C     61 _PICTL	=	0x008c
                    008D     62 Fonewire$P1IEN$0$0 == 0x008d
                    008D     63 _P1IEN	=	0x008d
                    008F     64 Fonewire$P0INP$0$0 == 0x008f
                    008F     65 _P0INP	=	0x008f
                    0090     66 Fonewire$P1$0$0 == 0x0090
                    0090     67 _P1	=	0x0090
                    0091     68 Fonewire$RFIM$0$0 == 0x0091
                    0091     69 _RFIM	=	0x0091
                    0092     70 Fonewire$DPS$0$0 == 0x0092
                    0092     71 _DPS	=	0x0092
                    0093     72 Fonewire$MPAGE$0$0 == 0x0093
                    0093     73 _MPAGE	=	0x0093
                    0095     74 Fonewire$ENDIAN$0$0 == 0x0095
                    0095     75 _ENDIAN	=	0x0095
                    0098     76 Fonewire$S0CON$0$0 == 0x0098
                    0098     77 _S0CON	=	0x0098
                    009A     78 Fonewire$IEN2$0$0 == 0x009a
                    009A     79 _IEN2	=	0x009a
                    009B     80 Fonewire$S1CON$0$0 == 0x009b
                    009B     81 _S1CON	=	0x009b
                    009C     82 Fonewire$T2CT$0$0 == 0x009c
                    009C     83 _T2CT	=	0x009c
                    009D     84 Fonewire$T2PR$0$0 == 0x009d
                    009D     85 _T2PR	=	0x009d
                    009E     86 Fonewire$T2CTL$0$0 == 0x009e
                    009E     87 _T2CTL	=	0x009e
                    00A0     88 Fonewire$P2$0$0 == 0x00a0
                    00A0     89 _P2	=	0x00a0
                    00A1     90 Fonewire$WORIRQ$0$0 == 0x00a1
                    00A1     91 _WORIRQ	=	0x00a1
                    00A2     92 Fonewire$WORCTRL$0$0 == 0x00a2
                    00A2     93 _WORCTRL	=	0x00a2
                    00A3     94 Fonewire$WOREVT0$0$0 == 0x00a3
                    00A3     95 _WOREVT0	=	0x00a3
                    00A4     96 Fonewire$WOREVT1$0$0 == 0x00a4
                    00A4     97 _WOREVT1	=	0x00a4
                    00A5     98 Fonewire$WORTIME0$0$0 == 0x00a5
                    00A5     99 _WORTIME0	=	0x00a5
                    00A6    100 Fonewire$WORTIME1$0$0 == 0x00a6
                    00A6    101 _WORTIME1	=	0x00a6
                    00A8    102 Fonewire$IEN0$0$0 == 0x00a8
                    00A8    103 _IEN0	=	0x00a8
                    00A9    104 Fonewire$IP0$0$0 == 0x00a9
                    00A9    105 _IP0	=	0x00a9
                    00AB    106 Fonewire$FWT$0$0 == 0x00ab
                    00AB    107 _FWT	=	0x00ab
                    00AC    108 Fonewire$FADDRL$0$0 == 0x00ac
                    00AC    109 _FADDRL	=	0x00ac
                    00AD    110 Fonewire$FADDRH$0$0 == 0x00ad
                    00AD    111 _FADDRH	=	0x00ad
                    00AE    112 Fonewire$FCTL$0$0 == 0x00ae
                    00AE    113 _FCTL	=	0x00ae
                    00AF    114 Fonewire$FWDATA$0$0 == 0x00af
                    00AF    115 _FWDATA	=	0x00af
                    00B1    116 Fonewire$ENCDI$0$0 == 0x00b1
                    00B1    117 _ENCDI	=	0x00b1
                    00B2    118 Fonewire$ENCDO$0$0 == 0x00b2
                    00B2    119 _ENCDO	=	0x00b2
                    00B3    120 Fonewire$ENCCS$0$0 == 0x00b3
                    00B3    121 _ENCCS	=	0x00b3
                    00B4    122 Fonewire$ADCCON1$0$0 == 0x00b4
                    00B4    123 _ADCCON1	=	0x00b4
                    00B5    124 Fonewire$ADCCON2$0$0 == 0x00b5
                    00B5    125 _ADCCON2	=	0x00b5
                    00B6    126 Fonewire$ADCCON3$0$0 == 0x00b6
                    00B6    127 _ADCCON3	=	0x00b6
                    00B8    128 Fonewire$IEN1$0$0 == 0x00b8
                    00B8    129 _IEN1	=	0x00b8
                    00B9    130 Fonewire$IP1$0$0 == 0x00b9
                    00B9    131 _IP1	=	0x00b9
                    00BA    132 Fonewire$ADCL$0$0 == 0x00ba
                    00BA    133 _ADCL	=	0x00ba
                    00BB    134 Fonewire$ADCH$0$0 == 0x00bb
                    00BB    135 _ADCH	=	0x00bb
                    00BC    136 Fonewire$RNDL$0$0 == 0x00bc
                    00BC    137 _RNDL	=	0x00bc
                    00BD    138 Fonewire$RNDH$0$0 == 0x00bd
                    00BD    139 _RNDH	=	0x00bd
                    00BE    140 Fonewire$SLEEP$0$0 == 0x00be
                    00BE    141 _SLEEP	=	0x00be
                    00C0    142 Fonewire$IRCON$0$0 == 0x00c0
                    00C0    143 _IRCON	=	0x00c0
                    00C1    144 Fonewire$U0DBUF$0$0 == 0x00c1
                    00C1    145 _U0DBUF	=	0x00c1
                    00C2    146 Fonewire$U0BAUD$0$0 == 0x00c2
                    00C2    147 _U0BAUD	=	0x00c2
                    00C4    148 Fonewire$U0UCR$0$0 == 0x00c4
                    00C4    149 _U0UCR	=	0x00c4
                    00C5    150 Fonewire$U0GCR$0$0 == 0x00c5
                    00C5    151 _U0GCR	=	0x00c5
                    00C6    152 Fonewire$CLKCON$0$0 == 0x00c6
                    00C6    153 _CLKCON	=	0x00c6
                    00C7    154 Fonewire$MEMCTR$0$0 == 0x00c7
                    00C7    155 _MEMCTR	=	0x00c7
                    00C9    156 Fonewire$WDCTL$0$0 == 0x00c9
                    00C9    157 _WDCTL	=	0x00c9
                    00CA    158 Fonewire$T3CNT$0$0 == 0x00ca
                    00CA    159 _T3CNT	=	0x00ca
                    00CB    160 Fonewire$T3CTL$0$0 == 0x00cb
                    00CB    161 _T3CTL	=	0x00cb
                    00CC    162 Fonewire$T3CCTL0$0$0 == 0x00cc
                    00CC    163 _T3CCTL0	=	0x00cc
                    00CD    164 Fonewire$T3CC0$0$0 == 0x00cd
                    00CD    165 _T3CC0	=	0x00cd
                    00CE    166 Fonewire$T3CCTL1$0$0 == 0x00ce
                    00CE    167 _T3CCTL1	=	0x00ce
                    00CF    168 Fonewire$T3CC1$0$0 == 0x00cf
                    00CF    169 _T3CC1	=	0x00cf
                    00D0    170 Fonewire$PSW$0$0 == 0x00d0
                    00D0    171 _PSW	=	0x00d0
                    00D1    172 Fonewire$DMAIRQ$0$0 == 0x00d1
                    00D1    173 _DMAIRQ	=	0x00d1
                    00D2    174 Fonewire$DMA1CFGL$0$0 == 0x00d2
                    00D2    175 _DMA1CFGL	=	0x00d2
                    00D3    176 Fonewire$DMA1CFGH$0$0 == 0x00d3
                    00D3    177 _DMA1CFGH	=	0x00d3
                    00D4    178 Fonewire$DMA0CFGL$0$0 == 0x00d4
                    00D4    179 _DMA0CFGL	=	0x00d4
                    00D5    180 Fonewire$DMA0CFGH$0$0 == 0x00d5
                    00D5    181 _DMA0CFGH	=	0x00d5
                    00D6    182 Fonewire$DMAARM$0$0 == 0x00d6
                    00D6    183 _DMAARM	=	0x00d6
                    00D7    184 Fonewire$DMAREQ$0$0 == 0x00d7
                    00D7    185 _DMAREQ	=	0x00d7
                    00D8    186 Fonewire$TIMIF$0$0 == 0x00d8
                    00D8    187 _TIMIF	=	0x00d8
                    00D9    188 Fonewire$RFD$0$0 == 0x00d9
                    00D9    189 _RFD	=	0x00d9
                    00DA    190 Fonewire$T1CC0L$0$0 == 0x00da
                    00DA    191 _T1CC0L	=	0x00da
                    00DB    192 Fonewire$T1CC0H$0$0 == 0x00db
                    00DB    193 _T1CC0H	=	0x00db
                    00DC    194 Fonewire$T1CC1L$0$0 == 0x00dc
                    00DC    195 _T1CC1L	=	0x00dc
                    00DD    196 Fonewire$T1CC1H$0$0 == 0x00dd
                    00DD    197 _T1CC1H	=	0x00dd
                    00DE    198 Fonewire$T1CC2L$0$0 == 0x00de
                    00DE    199 _T1CC2L	=	0x00de
                    00DF    200 Fonewire$T1CC2H$0$0 == 0x00df
                    00DF    201 _T1CC2H	=	0x00df
                    00E0    202 Fonewire$ACC$0$0 == 0x00e0
                    00E0    203 _ACC	=	0x00e0
                    00E1    204 Fonewire$RFST$0$0 == 0x00e1
                    00E1    205 _RFST	=	0x00e1
                    00E2    206 Fonewire$T1CNTL$0$0 == 0x00e2
                    00E2    207 _T1CNTL	=	0x00e2
                    00E3    208 Fonewire$T1CNTH$0$0 == 0x00e3
                    00E3    209 _T1CNTH	=	0x00e3
                    00E4    210 Fonewire$T1CTL$0$0 == 0x00e4
                    00E4    211 _T1CTL	=	0x00e4
                    00E5    212 Fonewire$T1CCTL0$0$0 == 0x00e5
                    00E5    213 _T1CCTL0	=	0x00e5
                    00E6    214 Fonewire$T1CCTL1$0$0 == 0x00e6
                    00E6    215 _T1CCTL1	=	0x00e6
                    00E7    216 Fonewire$T1CCTL2$0$0 == 0x00e7
                    00E7    217 _T1CCTL2	=	0x00e7
                    00E8    218 Fonewire$IRCON2$0$0 == 0x00e8
                    00E8    219 _IRCON2	=	0x00e8
                    00E9    220 Fonewire$RFIF$0$0 == 0x00e9
                    00E9    221 _RFIF	=	0x00e9
                    00EA    222 Fonewire$T4CNT$0$0 == 0x00ea
                    00EA    223 _T4CNT	=	0x00ea
                    00EB    224 Fonewire$T4CTL$0$0 == 0x00eb
                    00EB    225 _T4CTL	=	0x00eb
                    00EC    226 Fonewire$T4CCTL0$0$0 == 0x00ec
                    00EC    227 _T4CCTL0	=	0x00ec
                    00ED    228 Fonewire$T4CC0$0$0 == 0x00ed
                    00ED    229 _T4CC0	=	0x00ed
                    00EE    230 Fonewire$T4CCTL1$0$0 == 0x00ee
                    00EE    231 _T4CCTL1	=	0x00ee
                    00EF    232 Fonewire$T4CC1$0$0 == 0x00ef
                    00EF    233 _T4CC1	=	0x00ef
                    00F0    234 Fonewire$B$0$0 == 0x00f0
                    00F0    235 _B	=	0x00f0
                    00F1    236 Fonewire$PERCFG$0$0 == 0x00f1
                    00F1    237 _PERCFG	=	0x00f1
                    00F2    238 Fonewire$ADCCFG$0$0 == 0x00f2
                    00F2    239 _ADCCFG	=	0x00f2
                    00F3    240 Fonewire$P0SEL$0$0 == 0x00f3
                    00F3    241 _P0SEL	=	0x00f3
                    00F4    242 Fonewire$P1SEL$0$0 == 0x00f4
                    00F4    243 _P1SEL	=	0x00f4
                    00F5    244 Fonewire$P2SEL$0$0 == 0x00f5
                    00F5    245 _P2SEL	=	0x00f5
                    00F6    246 Fonewire$P1INP$0$0 == 0x00f6
                    00F6    247 _P1INP	=	0x00f6
                    00F7    248 Fonewire$P2INP$0$0 == 0x00f7
                    00F7    249 _P2INP	=	0x00f7
                    00F8    250 Fonewire$U1CSR$0$0 == 0x00f8
                    00F8    251 _U1CSR	=	0x00f8
                    00F9    252 Fonewire$U1DBUF$0$0 == 0x00f9
                    00F9    253 _U1DBUF	=	0x00f9
                    00FA    254 Fonewire$U1BAUD$0$0 == 0x00fa
                    00FA    255 _U1BAUD	=	0x00fa
                    00FB    256 Fonewire$U1UCR$0$0 == 0x00fb
                    00FB    257 _U1UCR	=	0x00fb
                    00FC    258 Fonewire$U1GCR$0$0 == 0x00fc
                    00FC    259 _U1GCR	=	0x00fc
                    00FD    260 Fonewire$P0DIR$0$0 == 0x00fd
                    00FD    261 _P0DIR	=	0x00fd
                    00FE    262 Fonewire$P1DIR$0$0 == 0x00fe
                    00FE    263 _P1DIR	=	0x00fe
                    00FF    264 Fonewire$P2DIR$0$0 == 0x00ff
                    00FF    265 _P2DIR	=	0x00ff
                    FFFFD5D4    266 Fonewire$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    267 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    268 Fonewire$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    269 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    270 Fonewire$FADDR$0$0 == 0xffffadac
                    FFFFADAC    271 _FADDR	=	0xffffadac
                    FFFFBBBA    272 Fonewire$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    273 _ADC	=	0xffffbbba
                    FFFFDBDA    274 Fonewire$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    275 _T1CC0	=	0xffffdbda
                    FFFFDDDC    276 Fonewire$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    277 _T1CC1	=	0xffffdddc
                    FFFFDFDE    278 Fonewire$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    279 _T1CC2	=	0xffffdfde
                            280 ;--------------------------------------------------------
                            281 ; special function bits
                            282 ;--------------------------------------------------------
                            283 	.area RSEG    (ABS,DATA)
   0000                     284 	.org 0x0000
                    0080    285 Fonewire$P0_0$0$0 == 0x0080
                    0080    286 _P0_0	=	0x0080
                    0081    287 Fonewire$P0_1$0$0 == 0x0081
                    0081    288 _P0_1	=	0x0081
                    0082    289 Fonewire$P0_2$0$0 == 0x0082
                    0082    290 _P0_2	=	0x0082
                    0083    291 Fonewire$P0_3$0$0 == 0x0083
                    0083    292 _P0_3	=	0x0083
                    0084    293 Fonewire$P0_4$0$0 == 0x0084
                    0084    294 _P0_4	=	0x0084
                    0085    295 Fonewire$P0_5$0$0 == 0x0085
                    0085    296 _P0_5	=	0x0085
                    0086    297 Fonewire$P0_6$0$0 == 0x0086
                    0086    298 _P0_6	=	0x0086
                    0087    299 Fonewire$P0_7$0$0 == 0x0087
                    0087    300 _P0_7	=	0x0087
                    0088    301 Fonewire$_TCON_0$0$0 == 0x0088
                    0088    302 __TCON_0	=	0x0088
                    0089    303 Fonewire$RFTXRXIF$0$0 == 0x0089
                    0089    304 _RFTXRXIF	=	0x0089
                    008A    305 Fonewire$_TCON_2$0$0 == 0x008a
                    008A    306 __TCON_2	=	0x008a
                    008B    307 Fonewire$URX0IF$0$0 == 0x008b
                    008B    308 _URX0IF	=	0x008b
                    008C    309 Fonewire$_TCON_4$0$0 == 0x008c
                    008C    310 __TCON_4	=	0x008c
                    008D    311 Fonewire$ADCIF$0$0 == 0x008d
                    008D    312 _ADCIF	=	0x008d
                    008E    313 Fonewire$_TCON_6$0$0 == 0x008e
                    008E    314 __TCON_6	=	0x008e
                    008F    315 Fonewire$URX1IF$0$0 == 0x008f
                    008F    316 _URX1IF	=	0x008f
                    0090    317 Fonewire$P1_0$0$0 == 0x0090
                    0090    318 _P1_0	=	0x0090
                    0091    319 Fonewire$P1_1$0$0 == 0x0091
                    0091    320 _P1_1	=	0x0091
                    0092    321 Fonewire$P1_2$0$0 == 0x0092
                    0092    322 _P1_2	=	0x0092
                    0093    323 Fonewire$P1_3$0$0 == 0x0093
                    0093    324 _P1_3	=	0x0093
                    0094    325 Fonewire$P1_4$0$0 == 0x0094
                    0094    326 _P1_4	=	0x0094
                    0095    327 Fonewire$P1_5$0$0 == 0x0095
                    0095    328 _P1_5	=	0x0095
                    0096    329 Fonewire$P1_6$0$0 == 0x0096
                    0096    330 _P1_6	=	0x0096
                    0097    331 Fonewire$P1_7$0$0 == 0x0097
                    0097    332 _P1_7	=	0x0097
                    0098    333 Fonewire$ENCIF_0$0$0 == 0x0098
                    0098    334 _ENCIF_0	=	0x0098
                    0099    335 Fonewire$ENCIF_1$0$0 == 0x0099
                    0099    336 _ENCIF_1	=	0x0099
                    009A    337 Fonewire$_SOCON2$0$0 == 0x009a
                    009A    338 __SOCON2	=	0x009a
                    009B    339 Fonewire$_SOCON3$0$0 == 0x009b
                    009B    340 __SOCON3	=	0x009b
                    009C    341 Fonewire$_SOCON4$0$0 == 0x009c
                    009C    342 __SOCON4	=	0x009c
                    009D    343 Fonewire$_SOCON5$0$0 == 0x009d
                    009D    344 __SOCON5	=	0x009d
                    009E    345 Fonewire$_SOCON6$0$0 == 0x009e
                    009E    346 __SOCON6	=	0x009e
                    009F    347 Fonewire$_SOCON7$0$0 == 0x009f
                    009F    348 __SOCON7	=	0x009f
                    00A0    349 Fonewire$P2_0$0$0 == 0x00a0
                    00A0    350 _P2_0	=	0x00a0
                    00A1    351 Fonewire$P2_1$0$0 == 0x00a1
                    00A1    352 _P2_1	=	0x00a1
                    00A2    353 Fonewire$P2_2$0$0 == 0x00a2
                    00A2    354 _P2_2	=	0x00a2
                    00A3    355 Fonewire$P2_3$0$0 == 0x00a3
                    00A3    356 _P2_3	=	0x00a3
                    00A4    357 Fonewire$P2_4$0$0 == 0x00a4
                    00A4    358 _P2_4	=	0x00a4
                    00A5    359 Fonewire$P2_5$0$0 == 0x00a5
                    00A5    360 _P2_5	=	0x00a5
                    00A6    361 Fonewire$P2_6$0$0 == 0x00a6
                    00A6    362 _P2_6	=	0x00a6
                    00A7    363 Fonewire$P2_7$0$0 == 0x00a7
                    00A7    364 _P2_7	=	0x00a7
                    00A8    365 Fonewire$RFTXRXIE$0$0 == 0x00a8
                    00A8    366 _RFTXRXIE	=	0x00a8
                    00A9    367 Fonewire$ADCIE$0$0 == 0x00a9
                    00A9    368 _ADCIE	=	0x00a9
                    00AA    369 Fonewire$URX0IE$0$0 == 0x00aa
                    00AA    370 _URX0IE	=	0x00aa
                    00AB    371 Fonewire$URX1IE$0$0 == 0x00ab
                    00AB    372 _URX1IE	=	0x00ab
                    00AC    373 Fonewire$ENCIE$0$0 == 0x00ac
                    00AC    374 _ENCIE	=	0x00ac
                    00AD    375 Fonewire$STIE$0$0 == 0x00ad
                    00AD    376 _STIE	=	0x00ad
                    00AE    377 Fonewire$_IEN06$0$0 == 0x00ae
                    00AE    378 __IEN06	=	0x00ae
                    00AF    379 Fonewire$EA$0$0 == 0x00af
                    00AF    380 _EA	=	0x00af
                    00B8    381 Fonewire$DMAIE$0$0 == 0x00b8
                    00B8    382 _DMAIE	=	0x00b8
                    00B9    383 Fonewire$T1IE$0$0 == 0x00b9
                    00B9    384 _T1IE	=	0x00b9
                    00BA    385 Fonewire$T2IE$0$0 == 0x00ba
                    00BA    386 _T2IE	=	0x00ba
                    00BB    387 Fonewire$T3IE$0$0 == 0x00bb
                    00BB    388 _T3IE	=	0x00bb
                    00BC    389 Fonewire$T4IE$0$0 == 0x00bc
                    00BC    390 _T4IE	=	0x00bc
                    00BD    391 Fonewire$P0IE$0$0 == 0x00bd
                    00BD    392 _P0IE	=	0x00bd
                    00BE    393 Fonewire$_IEN16$0$0 == 0x00be
                    00BE    394 __IEN16	=	0x00be
                    00BF    395 Fonewire$_IEN17$0$0 == 0x00bf
                    00BF    396 __IEN17	=	0x00bf
                    00C0    397 Fonewire$DMAIF$0$0 == 0x00c0
                    00C0    398 _DMAIF	=	0x00c0
                    00C1    399 Fonewire$T1IF$0$0 == 0x00c1
                    00C1    400 _T1IF	=	0x00c1
                    00C2    401 Fonewire$T2IF$0$0 == 0x00c2
                    00C2    402 _T2IF	=	0x00c2
                    00C3    403 Fonewire$T3IF$0$0 == 0x00c3
                    00C3    404 _T3IF	=	0x00c3
                    00C4    405 Fonewire$T4IF$0$0 == 0x00c4
                    00C4    406 _T4IF	=	0x00c4
                    00C5    407 Fonewire$P0IF$0$0 == 0x00c5
                    00C5    408 _P0IF	=	0x00c5
                    00C6    409 Fonewire$_IRCON6$0$0 == 0x00c6
                    00C6    410 __IRCON6	=	0x00c6
                    00C7    411 Fonewire$STIF$0$0 == 0x00c7
                    00C7    412 _STIF	=	0x00c7
                    00D0    413 Fonewire$P$0$0 == 0x00d0
                    00D0    414 _P	=	0x00d0
                    00D1    415 Fonewire$F1$0$0 == 0x00d1
                    00D1    416 _F1	=	0x00d1
                    00D2    417 Fonewire$OV$0$0 == 0x00d2
                    00D2    418 _OV	=	0x00d2
                    00D3    419 Fonewire$RS0$0$0 == 0x00d3
                    00D3    420 _RS0	=	0x00d3
                    00D4    421 Fonewire$RS1$0$0 == 0x00d4
                    00D4    422 _RS1	=	0x00d4
                    00D5    423 Fonewire$F0$0$0 == 0x00d5
                    00D5    424 _F0	=	0x00d5
                    00D6    425 Fonewire$AC$0$0 == 0x00d6
                    00D6    426 _AC	=	0x00d6
                    00D7    427 Fonewire$CY$0$0 == 0x00d7
                    00D7    428 _CY	=	0x00d7
                    00D8    429 Fonewire$T3OVFIF$0$0 == 0x00d8
                    00D8    430 _T3OVFIF	=	0x00d8
                    00D9    431 Fonewire$T3CH0IF$0$0 == 0x00d9
                    00D9    432 _T3CH0IF	=	0x00d9
                    00DA    433 Fonewire$T3CH1IF$0$0 == 0x00da
                    00DA    434 _T3CH1IF	=	0x00da
                    00DB    435 Fonewire$T4OVFIF$0$0 == 0x00db
                    00DB    436 _T4OVFIF	=	0x00db
                    00DC    437 Fonewire$T4CH0IF$0$0 == 0x00dc
                    00DC    438 _T4CH0IF	=	0x00dc
                    00DD    439 Fonewire$T4CH1IF$0$0 == 0x00dd
                    00DD    440 _T4CH1IF	=	0x00dd
                    00DE    441 Fonewire$OVFIM$0$0 == 0x00de
                    00DE    442 _OVFIM	=	0x00de
                    00DF    443 Fonewire$_TIMIF7$0$0 == 0x00df
                    00DF    444 __TIMIF7	=	0x00df
                    00E0    445 Fonewire$ACC_0$0$0 == 0x00e0
                    00E0    446 _ACC_0	=	0x00e0
                    00E1    447 Fonewire$ACC_1$0$0 == 0x00e1
                    00E1    448 _ACC_1	=	0x00e1
                    00E2    449 Fonewire$ACC_2$0$0 == 0x00e2
                    00E2    450 _ACC_2	=	0x00e2
                    00E3    451 Fonewire$ACC_3$0$0 == 0x00e3
                    00E3    452 _ACC_3	=	0x00e3
                    00E4    453 Fonewire$ACC_4$0$0 == 0x00e4
                    00E4    454 _ACC_4	=	0x00e4
                    00E5    455 Fonewire$ACC_5$0$0 == 0x00e5
                    00E5    456 _ACC_5	=	0x00e5
                    00E6    457 Fonewire$ACC_6$0$0 == 0x00e6
                    00E6    458 _ACC_6	=	0x00e6
                    00E7    459 Fonewire$ACC_7$0$0 == 0x00e7
                    00E7    460 _ACC_7	=	0x00e7
                    00E8    461 Fonewire$P2IF$0$0 == 0x00e8
                    00E8    462 _P2IF	=	0x00e8
                    00E9    463 Fonewire$UTX0IF$0$0 == 0x00e9
                    00E9    464 _UTX0IF	=	0x00e9
                    00EA    465 Fonewire$UTX1IF$0$0 == 0x00ea
                    00EA    466 _UTX1IF	=	0x00ea
                    00EB    467 Fonewire$P1IF$0$0 == 0x00eb
                    00EB    468 _P1IF	=	0x00eb
                    00EC    469 Fonewire$WDTIF$0$0 == 0x00ec
                    00EC    470 _WDTIF	=	0x00ec
                    00ED    471 Fonewire$_IRCON25$0$0 == 0x00ed
                    00ED    472 __IRCON25	=	0x00ed
                    00EE    473 Fonewire$_IRCON26$0$0 == 0x00ee
                    00EE    474 __IRCON26	=	0x00ee
                    00EF    475 Fonewire$_IRCON27$0$0 == 0x00ef
                    00EF    476 __IRCON27	=	0x00ef
                    00F0    477 Fonewire$B_0$0$0 == 0x00f0
                    00F0    478 _B_0	=	0x00f0
                    00F1    479 Fonewire$B_1$0$0 == 0x00f1
                    00F1    480 _B_1	=	0x00f1
                    00F2    481 Fonewire$B_2$0$0 == 0x00f2
                    00F2    482 _B_2	=	0x00f2
                    00F3    483 Fonewire$B_3$0$0 == 0x00f3
                    00F3    484 _B_3	=	0x00f3
                    00F4    485 Fonewire$B_4$0$0 == 0x00f4
                    00F4    486 _B_4	=	0x00f4
                    00F5    487 Fonewire$B_5$0$0 == 0x00f5
                    00F5    488 _B_5	=	0x00f5
                    00F6    489 Fonewire$B_6$0$0 == 0x00f6
                    00F6    490 _B_6	=	0x00f6
                    00F7    491 Fonewire$B_7$0$0 == 0x00f7
                    00F7    492 _B_7	=	0x00f7
                    00F8    493 Fonewire$U1ACTIVE$0$0 == 0x00f8
                    00F8    494 _U1ACTIVE	=	0x00f8
                    00F9    495 Fonewire$U1TX_BYTE$0$0 == 0x00f9
                    00F9    496 _U1TX_BYTE	=	0x00f9
                    00FA    497 Fonewire$U1RX_BYTE$0$0 == 0x00fa
                    00FA    498 _U1RX_BYTE	=	0x00fa
                    00FB    499 Fonewire$U1ERR$0$0 == 0x00fb
                    00FB    500 _U1ERR	=	0x00fb
                    00FC    501 Fonewire$U1FE$0$0 == 0x00fc
                    00FC    502 _U1FE	=	0x00fc
                    00FD    503 Fonewire$U1SLAVE$0$0 == 0x00fd
                    00FD    504 _U1SLAVE	=	0x00fd
                    00FE    505 Fonewire$U1RE$0$0 == 0x00fe
                    00FE    506 _U1RE	=	0x00fe
                    00FF    507 Fonewire$U1MODE$0$0 == 0x00ff
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
                            518 ;--------------------------------------------------------
                            519 ; overlayable items in internal ram 
                            520 ;--------------------------------------------------------
                            521 	.area OSEG    (OVR,DATA)
                            522 ;--------------------------------------------------------
                            523 ; indirectly addressable internal ram data
                            524 ;--------------------------------------------------------
                            525 	.area ISEG    (DATA)
                            526 ;--------------------------------------------------------
                            527 ; absolute internal ram data
                            528 ;--------------------------------------------------------
                            529 	.area IABS    (ABS,DATA)
                            530 	.area IABS    (ABS,DATA)
                            531 ;--------------------------------------------------------
                            532 ; bit data
                            533 ;--------------------------------------------------------
                            534 	.area BSEG    (BIT)
                    0000    535 Lonewire.onewire_reset$sloc0$1$0==.
   0000                     536 _onewire_reset_sloc0_1_0:
   0000                     537 	.ds 1
                            538 ;--------------------------------------------------------
                            539 ; paged external ram data
                            540 ;--------------------------------------------------------
                            541 	.area PSEG    (PAG,XDATA)
                    0000    542 Lonewire.onewire_write$power$1$1==.
   F019                     543 _onewire_write_PARM_2:
   F019                     544 	.ds 1
                    0001    545 Lonewire.onewire_select$rom$1$1==.
   F01A                     546 _onewire_select_rom_1_1:
   F01A                     547 	.ds 3
                    0004    548 G$ROM_NO$0$0==.
   F01D                     549 _ROM_NO::
   F01D                     550 	.ds 8
                    000C    551 G$LastDiscrepancy$0$0==.
   F025                     552 _LastDiscrepancy::
   F025                     553 	.ds 1
                    000D    554 G$LastFamilyDiscrepancy$0$0==.
   F026                     555 _LastFamilyDiscrepancy::
   F026                     556 	.ds 1
                    000E    557 G$LastDeviceFlag$0$0==.
   F027                     558 _LastDeviceFlag::
   F027                     559 	.ds 1
                    000F    560 Lonewire.onewire_search$newAddr$1$1==.
   F028                     561 _onewire_search_newAddr_1_1:
   F028                     562 	.ds 3
                    0012    563 Lonewire.onewire_search$search_result$1$1==.
   F02B                     564 _onewire_search_search_result_1_1:
   F02B                     565 	.ds 1
                    0013    566 Lonewire.onewire_crc8$len$1$1==.
   F02C                     567 _onewire_crc8_PARM_2:
   F02C                     568 	.ds 1
                    0014    569 Lonewire.onewire_crc8$inbyte$2$2==.
   F02D                     570 _onewire_crc8_inbyte_2_2:
   F02D                     571 	.ds 1
                    0015    572 Lonewire.onewire_crc8$mix$3$3==.
   F02E                     573 _onewire_crc8_mix_3_3:
   F02E                     574 	.ds 1
                            575 ;--------------------------------------------------------
                            576 ; external ram data
                            577 ;--------------------------------------------------------
                            578 	.area XSEG    (XDATA)
                    DF00    579 Fonewire$SYNC1$0$0 == 0xdf00
                    DF00    580 _SYNC1	=	0xdf00
                    DF01    581 Fonewire$SYNC0$0$0 == 0xdf01
                    DF01    582 _SYNC0	=	0xdf01
                    DF02    583 Fonewire$PKTLEN$0$0 == 0xdf02
                    DF02    584 _PKTLEN	=	0xdf02
                    DF03    585 Fonewire$PKTCTRL1$0$0 == 0xdf03
                    DF03    586 _PKTCTRL1	=	0xdf03
                    DF04    587 Fonewire$PKTCTRL0$0$0 == 0xdf04
                    DF04    588 _PKTCTRL0	=	0xdf04
                    DF05    589 Fonewire$ADDR$0$0 == 0xdf05
                    DF05    590 _ADDR	=	0xdf05
                    DF06    591 Fonewire$CHANNR$0$0 == 0xdf06
                    DF06    592 _CHANNR	=	0xdf06
                    DF07    593 Fonewire$FSCTRL1$0$0 == 0xdf07
                    DF07    594 _FSCTRL1	=	0xdf07
                    DF08    595 Fonewire$FSCTRL0$0$0 == 0xdf08
                    DF08    596 _FSCTRL0	=	0xdf08
                    DF09    597 Fonewire$FREQ2$0$0 == 0xdf09
                    DF09    598 _FREQ2	=	0xdf09
                    DF0A    599 Fonewire$FREQ1$0$0 == 0xdf0a
                    DF0A    600 _FREQ1	=	0xdf0a
                    DF0B    601 Fonewire$FREQ0$0$0 == 0xdf0b
                    DF0B    602 _FREQ0	=	0xdf0b
                    DF0C    603 Fonewire$MDMCFG4$0$0 == 0xdf0c
                    DF0C    604 _MDMCFG4	=	0xdf0c
                    DF0D    605 Fonewire$MDMCFG3$0$0 == 0xdf0d
                    DF0D    606 _MDMCFG3	=	0xdf0d
                    DF0E    607 Fonewire$MDMCFG2$0$0 == 0xdf0e
                    DF0E    608 _MDMCFG2	=	0xdf0e
                    DF0F    609 Fonewire$MDMCFG1$0$0 == 0xdf0f
                    DF0F    610 _MDMCFG1	=	0xdf0f
                    DF10    611 Fonewire$MDMCFG0$0$0 == 0xdf10
                    DF10    612 _MDMCFG0	=	0xdf10
                    DF11    613 Fonewire$DEVIATN$0$0 == 0xdf11
                    DF11    614 _DEVIATN	=	0xdf11
                    DF12    615 Fonewire$MCSM2$0$0 == 0xdf12
                    DF12    616 _MCSM2	=	0xdf12
                    DF13    617 Fonewire$MCSM1$0$0 == 0xdf13
                    DF13    618 _MCSM1	=	0xdf13
                    DF14    619 Fonewire$MCSM0$0$0 == 0xdf14
                    DF14    620 _MCSM0	=	0xdf14
                    DF15    621 Fonewire$FOCCFG$0$0 == 0xdf15
                    DF15    622 _FOCCFG	=	0xdf15
                    DF16    623 Fonewire$BSCFG$0$0 == 0xdf16
                    DF16    624 _BSCFG	=	0xdf16
                    DF17    625 Fonewire$AGCCTRL2$0$0 == 0xdf17
                    DF17    626 _AGCCTRL2	=	0xdf17
                    DF18    627 Fonewire$AGCCTRL1$0$0 == 0xdf18
                    DF18    628 _AGCCTRL1	=	0xdf18
                    DF19    629 Fonewire$AGCCTRL0$0$0 == 0xdf19
                    DF19    630 _AGCCTRL0	=	0xdf19
                    DF1A    631 Fonewire$FREND1$0$0 == 0xdf1a
                    DF1A    632 _FREND1	=	0xdf1a
                    DF1B    633 Fonewire$FREND0$0$0 == 0xdf1b
                    DF1B    634 _FREND0	=	0xdf1b
                    DF1C    635 Fonewire$FSCAL3$0$0 == 0xdf1c
                    DF1C    636 _FSCAL3	=	0xdf1c
                    DF1D    637 Fonewire$FSCAL2$0$0 == 0xdf1d
                    DF1D    638 _FSCAL2	=	0xdf1d
                    DF1E    639 Fonewire$FSCAL1$0$0 == 0xdf1e
                    DF1E    640 _FSCAL1	=	0xdf1e
                    DF1F    641 Fonewire$FSCAL0$0$0 == 0xdf1f
                    DF1F    642 _FSCAL0	=	0xdf1f
                    DF23    643 Fonewire$TEST2$0$0 == 0xdf23
                    DF23    644 _TEST2	=	0xdf23
                    DF24    645 Fonewire$TEST1$0$0 == 0xdf24
                    DF24    646 _TEST1	=	0xdf24
                    DF25    647 Fonewire$TEST0$0$0 == 0xdf25
                    DF25    648 _TEST0	=	0xdf25
                    DF2E    649 Fonewire$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    650 _PA_TABLE0	=	0xdf2e
                    DF2F    651 Fonewire$IOCFG2$0$0 == 0xdf2f
                    DF2F    652 _IOCFG2	=	0xdf2f
                    DF30    653 Fonewire$IOCFG1$0$0 == 0xdf30
                    DF30    654 _IOCFG1	=	0xdf30
                    DF31    655 Fonewire$IOCFG0$0$0 == 0xdf31
                    DF31    656 _IOCFG0	=	0xdf31
                    DF36    657 Fonewire$PARTNUM$0$0 == 0xdf36
                    DF36    658 _PARTNUM	=	0xdf36
                    DF37    659 Fonewire$VERSION$0$0 == 0xdf37
                    DF37    660 _VERSION	=	0xdf37
                    DF38    661 Fonewire$FREQEST$0$0 == 0xdf38
                    DF38    662 _FREQEST	=	0xdf38
                    DF39    663 Fonewire$LQI$0$0 == 0xdf39
                    DF39    664 _LQI	=	0xdf39
                    DF3A    665 Fonewire$RSSI$0$0 == 0xdf3a
                    DF3A    666 _RSSI	=	0xdf3a
                    DF3B    667 Fonewire$MARCSTATE$0$0 == 0xdf3b
                    DF3B    668 _MARCSTATE	=	0xdf3b
                    DF3C    669 Fonewire$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    670 _PKTSTATUS	=	0xdf3c
                    DF3D    671 Fonewire$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    672 _VCO_VC_DAC	=	0xdf3d
                    DF40    673 Fonewire$I2SCFG0$0$0 == 0xdf40
                    DF40    674 _I2SCFG0	=	0xdf40
                    DF41    675 Fonewire$I2SCFG1$0$0 == 0xdf41
                    DF41    676 _I2SCFG1	=	0xdf41
                    DF42    677 Fonewire$I2SDATL$0$0 == 0xdf42
                    DF42    678 _I2SDATL	=	0xdf42
                    DF43    679 Fonewire$I2SDATH$0$0 == 0xdf43
                    DF43    680 _I2SDATH	=	0xdf43
                    DF44    681 Fonewire$I2SWCNT$0$0 == 0xdf44
                    DF44    682 _I2SWCNT	=	0xdf44
                    DF45    683 Fonewire$I2SSTAT$0$0 == 0xdf45
                    DF45    684 _I2SSTAT	=	0xdf45
                    DF46    685 Fonewire$I2SCLKF0$0$0 == 0xdf46
                    DF46    686 _I2SCLKF0	=	0xdf46
                    DF47    687 Fonewire$I2SCLKF1$0$0 == 0xdf47
                    DF47    688 _I2SCLKF1	=	0xdf47
                    DF48    689 Fonewire$I2SCLKF2$0$0 == 0xdf48
                    DF48    690 _I2SCLKF2	=	0xdf48
                    DE00    691 Fonewire$USBADDR$0$0 == 0xde00
                    DE00    692 _USBADDR	=	0xde00
                    DE01    693 Fonewire$USBPOW$0$0 == 0xde01
                    DE01    694 _USBPOW	=	0xde01
                    DE02    695 Fonewire$USBIIF$0$0 == 0xde02
                    DE02    696 _USBIIF	=	0xde02
                    DE04    697 Fonewire$USBOIF$0$0 == 0xde04
                    DE04    698 _USBOIF	=	0xde04
                    DE06    699 Fonewire$USBCIF$0$0 == 0xde06
                    DE06    700 _USBCIF	=	0xde06
                    DE07    701 Fonewire$USBIIE$0$0 == 0xde07
                    DE07    702 _USBIIE	=	0xde07
                    DE09    703 Fonewire$USBOIE$0$0 == 0xde09
                    DE09    704 _USBOIE	=	0xde09
                    DE0B    705 Fonewire$USBCIE$0$0 == 0xde0b
                    DE0B    706 _USBCIE	=	0xde0b
                    DE0C    707 Fonewire$USBFRML$0$0 == 0xde0c
                    DE0C    708 _USBFRML	=	0xde0c
                    DE0D    709 Fonewire$USBFRMH$0$0 == 0xde0d
                    DE0D    710 _USBFRMH	=	0xde0d
                    DE0E    711 Fonewire$USBINDEX$0$0 == 0xde0e
                    DE0E    712 _USBINDEX	=	0xde0e
                    DE10    713 Fonewire$USBMAXI$0$0 == 0xde10
                    DE10    714 _USBMAXI	=	0xde10
                    DE11    715 Fonewire$USBCSIL$0$0 == 0xde11
                    DE11    716 _USBCSIL	=	0xde11
                    DE12    717 Fonewire$USBCSIH$0$0 == 0xde12
                    DE12    718 _USBCSIH	=	0xde12
                    DE13    719 Fonewire$USBMAXO$0$0 == 0xde13
                    DE13    720 _USBMAXO	=	0xde13
                    DE14    721 Fonewire$USBCSOL$0$0 == 0xde14
                    DE14    722 _USBCSOL	=	0xde14
                    DE15    723 Fonewire$USBCSOH$0$0 == 0xde15
                    DE15    724 _USBCSOH	=	0xde15
                    DE16    725 Fonewire$USBCNTL$0$0 == 0xde16
                    DE16    726 _USBCNTL	=	0xde16
                    DE17    727 Fonewire$USBCNTH$0$0 == 0xde17
                    DE17    728 _USBCNTH	=	0xde17
                    DE20    729 Fonewire$USBF0$0$0 == 0xde20
                    DE20    730 _USBF0	=	0xde20
                    DE22    731 Fonewire$USBF1$0$0 == 0xde22
                    DE22    732 _USBF1	=	0xde22
                    DE24    733 Fonewire$USBF2$0$0 == 0xde24
                    DE24    734 _USBF2	=	0xde24
                    DE26    735 Fonewire$USBF3$0$0 == 0xde26
                    DE26    736 _USBF3	=	0xde26
                    DE28    737 Fonewire$USBF4$0$0 == 0xde28
                    DE28    738 _USBF4	=	0xde28
                    DE2A    739 Fonewire$USBF5$0$0 == 0xde2a
                    DE2A    740 _USBF5	=	0xde2a
                            741 ;--------------------------------------------------------
                            742 ; absolute external ram data
                            743 ;--------------------------------------------------------
                            744 	.area XABS    (ABS,XDATA)
                            745 ;--------------------------------------------------------
                            746 ; external initialized ram data
                            747 ;--------------------------------------------------------
                            748 	.area XISEG   (XDATA)
                            749 	.area HOME    (CODE)
                            750 	.area GSINIT0 (CODE)
                            751 	.area GSINIT1 (CODE)
                            752 	.area GSINIT2 (CODE)
                            753 	.area GSINIT3 (CODE)
                            754 	.area GSINIT4 (CODE)
                            755 	.area GSINIT5 (CODE)
                            756 	.area GSINIT  (CODE)
                            757 	.area GSFINAL (CODE)
                            758 	.area CSEG    (CODE)
                            759 ;--------------------------------------------------------
                            760 ; global & static initialisations
                            761 ;--------------------------------------------------------
                            762 	.area HOME    (CODE)
                            763 	.area GSINIT  (CODE)
                            764 	.area GSFINAL (CODE)
                            765 	.area GSINIT  (CODE)
                            766 ;--------------------------------------------------------
                            767 ; Home
                            768 ;--------------------------------------------------------
                            769 	.area HOME    (CODE)
                            770 	.area HOME    (CODE)
                            771 ;--------------------------------------------------------
                            772 ; code
                            773 ;--------------------------------------------------------
                            774 	.area CSEG    (CODE)
                            775 ;------------------------------------------------------------
                            776 ;Allocation info for local variables in function 'onewire_start'
                            777 ;------------------------------------------------------------
                    0000    778 	G$onewire_start$0$0 ==.
                    0000    779 	C$onewire.c$102$0$0 ==.
                            780 ;	apps/example_onewire/onewire.c:102: void onewire_start(void)
                            781 ;	-----------------------------------------
                            782 ;	 function onewire_start
                            783 ;	-----------------------------------------
   0910                     784 _onewire_start:
                    0007    785 	ar7 = 0x07
                    0006    786 	ar6 = 0x06
                    0005    787 	ar5 = 0x05
                    0004    788 	ar4 = 0x04
                    0003    789 	ar3 = 0x03
                    0002    790 	ar2 = 0x02
                    0001    791 	ar1 = 0x01
                    0000    792 	ar0 = 0x00
                    0000    793 	C$onewire.c$105$1$1 ==.
                            794 ;	apps/example_onewire/onewire.c:105: onewire_reset_search();
   0910 12 0A 77            795 	lcall	_onewire_reset_search
                    0003    796 	C$onewire.c$107$1$1 ==.
                    0003    797 	XG$onewire_start$0$0 ==.
   0913 22                  798 	ret
                            799 ;------------------------------------------------------------
                            800 ;Allocation info for local variables in function 'onewire_reset'
                            801 ;------------------------------------------------------------
                    0004    802 	G$onewire_reset$0$0 ==.
                    0004    803 	C$onewire.c$136$1$1 ==.
                            804 ;	apps/example_onewire/onewire.c:136: uint8_t onewire_reset(void)
                            805 ;	-----------------------------------------
                            806 ;	 function onewire_reset
                            807 ;	-----------------------------------------
   0914                     808 _onewire_reset:
                    0004    809 	C$onewire.c$142$1$1 ==.
                            810 ;	apps/example_onewire/onewire.c:142: DIRECT_MODE_INPUT(reg, mask);
   0914 AF FD               811 	mov	r7,_P0DIR
   0916 53 07 FE            812 	anl	ar7,#0xFE
   0919 8F FD               813 	mov	_P0DIR,r7
                    000B    814 	C$onewire.c$145$1$1 ==.
                            815 ;	apps/example_onewire/onewire.c:145: do {
   091B 7F 7D               816 	mov	r7,#0x7D
   091D                     817 00103$:
                    000D    818 	C$onewire.c$146$2$2 ==.
                            819 ;	apps/example_onewire/onewire.c:146: if (--retries == 0) return 0;
   091D DF 05               820 	djnz	r7,00102$
   091F 75 82 00            821 	mov	dpl,#0x00
   0922 80 3C               822 	sjmp	00106$
   0924                     823 00102$:
                    0014    824 	C$onewire.c$147$2$2 ==.
                            825 ;	apps/example_onewire/onewire.c:147: delayMicroseconds(2);
   0924 75 82 02            826 	mov	dpl,#0x02
   0927 C0 07               827 	push	ar7
   0929 12 17 69            828 	lcall	_delayMicroseconds
   092C D0 07               829 	pop	ar7
                    001E    830 	C$onewire.c$148$1$1 ==.
                            831 ;	apps/example_onewire/onewire.c:148: } while ( !DIRECT_READ(reg, mask));
   092E 30 80 EC            832 	jnb	_P0_0,00103$
                    0021    833 	C$onewire.c$151$1$1 ==.
                            834 ;	apps/example_onewire/onewire.c:151: DIRECT_MODE_OUTPUT(reg, mask);  // drive output low
   0931 43 FD 01            835 	orl	_P0DIR,#0x01
                    0024    836 	C$onewire.c$154$1$1 ==.
                            837 ;	apps/example_onewire/onewire.c:154: DIRECT_WRITE_LOW(reg, mask);
   0934 C2 80               838 	clr	_P0_0
                    0026    839 	C$onewire.c$156$1$1 ==.
                            840 ;	apps/example_onewire/onewire.c:156: delayMicroseconds(500);
   0936 75 82 F4            841 	mov	dpl,#0xF4
   0939 12 17 69            842 	lcall	_delayMicroseconds
                    002C    843 	C$onewire.c$158$1$1 ==.
                            844 ;	apps/example_onewire/onewire.c:158: DIRECT_MODE_INPUT(reg, mask);   // allow it to float
   093C AF FD               845 	mov	r7,_P0DIR
   093E 53 07 FE            846 	anl	ar7,#0xFE
   0941 8F FD               847 	mov	_P0DIR,r7
                    0033    848 	C$onewire.c$159$1$1 ==.
                            849 ;	apps/example_onewire/onewire.c:159: delayMicroseconds(80);
   0943 75 82 50            850 	mov	dpl,#0x50
   0946 12 17 69            851 	lcall	_delayMicroseconds
                    0039    852 	C$onewire.c$160$1$1 ==.
                            853 ;	apps/example_onewire/onewire.c:160: r = !DIRECT_READ(reg, mask);
   0949 A2 80               854 	mov	c,_P0_0
   094B B3                  855 	cpl	c
   094C 92 00               856 	mov  _onewire_reset_sloc0_1_0,c
   094E E4                  857 	clr	a
   094F 33                  858 	rlc	a
   0950 FF                  859 	mov	r7,a
                    0041    860 	C$onewire.c$161$2$3 ==.
                            861 ;	apps/example_onewire/onewire.c:161: LED_YELLOW_TOGGLE();
   0951 63 FF 04            862 	xrl	_P2DIR,#0x04
                    0044    863 	C$onewire.c$163$1$1 ==.
                            864 ;	apps/example_onewire/onewire.c:163: delayMicroseconds(420);
   0954 75 82 A4            865 	mov	dpl,#0xA4
   0957 C0 07               866 	push	ar7
   0959 12 17 69            867 	lcall	_delayMicroseconds
   095C D0 07               868 	pop	ar7
                    004E    869 	C$onewire.c$164$1$1 ==.
                            870 ;	apps/example_onewire/onewire.c:164: return r;
   095E 8F 82               871 	mov	dpl,r7
   0960                     872 00106$:
                    0050    873 	C$onewire.c$165$1$1 ==.
                    0050    874 	XG$onewire_reset$0$0 ==.
   0960 22                  875 	ret
                            876 ;------------------------------------------------------------
                            877 ;Allocation info for local variables in function 'onewire_write_bit'
                            878 ;------------------------------------------------------------
                    0051    879 	G$onewire_write_bit$0$0 ==.
                    0051    880 	C$onewire.c$171$1$1 ==.
                            881 ;	apps/example_onewire/onewire.c:171: void onewire_write_bit(uint8_t v)
                            882 ;	-----------------------------------------
                            883 ;	 function onewire_write_bit
                            884 ;	-----------------------------------------
   0961                     885 _onewire_write_bit:
                    0051    886 	C$onewire.c$173$1$1 ==.
                            887 ;	apps/example_onewire/onewire.c:173: if (v & 1) {
   0961 E5 82               888 	mov	a,dpl
   0963 FF                  889 	mov	r7,a
   0964 30 E0 15            890 	jnb	acc.0,00102$
                    0057    891 	C$onewire.c$175$2$2 ==.
                            892 ;	apps/example_onewire/onewire.c:175: DIRECT_WRITE_LOW(reg, mask);
   0967 C2 80               893 	clr	_P0_0
                    0059    894 	C$onewire.c$176$2$2 ==.
                            895 ;	apps/example_onewire/onewire.c:176: DIRECT_MODE_OUTPUT(reg, mask);  // drive output low
   0969 43 FD 01            896 	orl	_P0DIR,#0x01
                    005C    897 	C$onewire.c$177$2$2 ==.
                            898 ;	apps/example_onewire/onewire.c:177: delayMicroseconds(10);
   096C 75 82 0A            899 	mov	dpl,#0x0A
   096F 12 17 69            900 	lcall	_delayMicroseconds
                    0062    901 	C$onewire.c$178$2$2 ==.
                            902 ;	apps/example_onewire/onewire.c:178: DIRECT_WRITE_HIGH(reg, mask);   // drive output high
   0972 D2 80               903 	setb	_P0_0
                    0064    904 	C$onewire.c$180$2$2 ==.
                            905 ;	apps/example_onewire/onewire.c:180: delayMicroseconds(55);
   0974 75 82 37            906 	mov	dpl,#0x37
   0977 12 17 69            907 	lcall	_delayMicroseconds
   097A 80 13               908 	sjmp	00104$
   097C                     909 00102$:
                    006C    910 	C$onewire.c$183$2$3 ==.
                            911 ;	apps/example_onewire/onewire.c:183: DIRECT_WRITE_LOW(reg, mask);
   097C C2 80               912 	clr	_P0_0
                    006E    913 	C$onewire.c$184$2$3 ==.
                            914 ;	apps/example_onewire/onewire.c:184: DIRECT_MODE_OUTPUT(reg, mask);  // drive output low
   097E 43 FD 01            915 	orl	_P0DIR,#0x01
                    0071    916 	C$onewire.c$185$2$3 ==.
                            917 ;	apps/example_onewire/onewire.c:185: delayMicroseconds(65);
   0981 75 82 41            918 	mov	dpl,#0x41
   0984 12 17 69            919 	lcall	_delayMicroseconds
                    0077    920 	C$onewire.c$186$2$3 ==.
                            921 ;	apps/example_onewire/onewire.c:186: DIRECT_WRITE_HIGH(reg, mask);   // drive output high
   0987 D2 80               922 	setb	_P0_0
                    0079    923 	C$onewire.c$188$2$3 ==.
                            924 ;	apps/example_onewire/onewire.c:188: delayMicroseconds(5);
   0989 75 82 05            925 	mov	dpl,#0x05
   098C 12 17 69            926 	lcall	_delayMicroseconds
   098F                     927 00104$:
                    007F    928 	C$onewire.c$190$1$1 ==.
                    007F    929 	XG$onewire_write_bit$0$0 ==.
   098F 22                  930 	ret
                            931 ;------------------------------------------------------------
                            932 ;Allocation info for local variables in function 'onewire_read_bit'
                            933 ;------------------------------------------------------------
                    0080    934 	G$onewire_read_bit$0$0 ==.
                    0080    935 	C$onewire.c$196$1$1 ==.
                            936 ;	apps/example_onewire/onewire.c:196: uint8_t onewire_read_bit(void)
                            937 ;	-----------------------------------------
                            938 ;	 function onewire_read_bit
                            939 ;	-----------------------------------------
   0990                     940 _onewire_read_bit:
                    0080    941 	C$onewire.c$201$1$1 ==.
                            942 ;	apps/example_onewire/onewire.c:201: DIRECT_MODE_OUTPUT(reg, mask);
   0990 43 FD 01            943 	orl	_P0DIR,#0x01
                    0083    944 	C$onewire.c$202$1$1 ==.
                            945 ;	apps/example_onewire/onewire.c:202: DIRECT_WRITE_LOW(reg, mask);
   0993 C2 80               946 	clr	_P0_0
                    0085    947 	C$onewire.c$203$1$1 ==.
                            948 ;	apps/example_onewire/onewire.c:203: delayMicroseconds(3);
   0995 75 82 03            949 	mov	dpl,#0x03
   0998 12 17 69            950 	lcall	_delayMicroseconds
                    008B    951 	C$onewire.c$204$1$1 ==.
                            952 ;	apps/example_onewire/onewire.c:204: DIRECT_MODE_INPUT(reg, mask);   // let pin float, pull up will raise
   099B AF FD               953 	mov	r7,_P0DIR
   099D 53 07 FE            954 	anl	ar7,#0xFE
   09A0 8F FD               955 	mov	_P0DIR,r7
                    0092    956 	C$onewire.c$205$1$1 ==.
                            957 ;	apps/example_onewire/onewire.c:205: delayMicroseconds(9);
   09A2 75 82 09            958 	mov	dpl,#0x09
   09A5 12 17 69            959 	lcall	_delayMicroseconds
                    0098    960 	C$onewire.c$206$1$1 ==.
                            961 ;	apps/example_onewire/onewire.c:206: r = DIRECT_READ(reg, mask);
   09A8 A2 80               962 	mov	c,_P0_0
   09AA E4                  963 	clr	a
   09AB 33                  964 	rlc	a
   09AC FF                  965 	mov	r7,a
                    009D    966 	C$onewire.c$208$1$1 ==.
                            967 ;	apps/example_onewire/onewire.c:208: delayMicroseconds(53);
   09AD 75 82 35            968 	mov	dpl,#0x35
   09B0 C0 07               969 	push	ar7
   09B2 12 17 69            970 	lcall	_delayMicroseconds
   09B5 D0 07               971 	pop	ar7
                    00A7    972 	C$onewire.c$209$1$1 ==.
                            973 ;	apps/example_onewire/onewire.c:209: return r;
   09B7 8F 82               974 	mov	dpl,r7
                    00A9    975 	C$onewire.c$210$1$1 ==.
                    00A9    976 	XG$onewire_read_bit$0$0 ==.
   09B9 22                  977 	ret
                            978 ;------------------------------------------------------------
                            979 ;Allocation info for local variables in function 'onewire_write'
                            980 ;------------------------------------------------------------
                    00AA    981 	G$onewire_write$0$0 ==.
                    00AA    982 	C$onewire.c$219$1$1 ==.
                            983 ;	apps/example_onewire/onewire.c:219: void onewire_write(uint8_t v, uint8_t power) {
                            984 ;	-----------------------------------------
                            985 ;	 function onewire_write
                            986 ;	-----------------------------------------
   09BA                     987 _onewire_write:
   09BA AF 82               988 	mov	r7,dpl
                    00AC    989 	C$onewire.c$222$1$1 ==.
                            990 ;	apps/example_onewire/onewire.c:222: for (bitMask = 0x01; bitMask; bitMask <<= 1) {
   09BC 7E 01               991 	mov	r6,#0x01
   09BE                     992 00103$:
   09BE EE                  993 	mov	a,r6
   09BF 60 1C               994 	jz	00106$
                    00B1    995 	C$onewire.c$223$2$2 ==.
                            996 ;	apps/example_onewire/onewire.c:223: onewire_write_bit( (bitMask & v)?1:0);
   09C1 EF                  997 	mov	a,r7
   09C2 5E                  998 	anl	a,r6
   09C3 60 04               999 	jz	00109$
   09C5 7D 01              1000 	mov	r5,#0x01
   09C7 80 02              1001 	sjmp	00110$
   09C9                    1002 00109$:
   09C9 7D 00              1003 	mov	r5,#0x00
   09CB                    1004 00110$:
   09CB 8D 82              1005 	mov	dpl,r5
   09CD C0 07              1006 	push	ar7
   09CF C0 06              1007 	push	ar6
   09D1 12 09 61           1008 	lcall	_onewire_write_bit
   09D4 D0 06              1009 	pop	ar6
   09D6 D0 07              1010 	pop	ar7
                    00C8   1011 	C$onewire.c$222$1$1 ==.
                           1012 ;	apps/example_onewire/onewire.c:222: for (bitMask = 0x01; bitMask; bitMask <<= 1) {
   09D8 EE                 1013 	mov	a,r6
   09D9 2E                 1014 	add	a,r6
   09DA FE                 1015 	mov	r6,a
   09DB 80 E1              1016 	sjmp	00103$
   09DD                    1017 00106$:
                    00CD   1018 	C$onewire.c$225$1$1 ==.
                           1019 ;	apps/example_onewire/onewire.c:225: if ( !power) {
   09DD 78 19              1020 	mov	r0,#_onewire_write_PARM_2
   09DF E2                 1021 	movx	a,@r0
   09E0 70 09              1022 	jnz	00107$
                    00D2   1023 	C$onewire.c$227$2$3 ==.
                           1024 ;	apps/example_onewire/onewire.c:227: DIRECT_MODE_INPUT(reg, mask);
   09E2 AF FD              1025 	mov	r7,_P0DIR
   09E4 53 07 FE           1026 	anl	ar7,#0xFE
   09E7 8F FD              1027 	mov	_P0DIR,r7
                    00D9   1028 	C$onewire.c$228$2$3 ==.
                           1029 ;	apps/example_onewire/onewire.c:228: DIRECT_WRITE_LOW(reg, mask);
   09E9 C2 80              1030 	clr	_P0_0
   09EB                    1031 00107$:
                    00DB   1032 	C$onewire.c$231$2$1 ==.
                    00DB   1033 	XG$onewire_write$0$0 ==.
   09EB 22                 1034 	ret
                           1035 ;------------------------------------------------------------
                           1036 ;Allocation info for local variables in function 'onewire_read'
                           1037 ;------------------------------------------------------------
                    00DC   1038 	G$onewire_read$0$0 ==.
                    00DC   1039 	C$onewire.c$236$2$1 ==.
                           1040 ;	apps/example_onewire/onewire.c:236: uint8_t onewire_read() {
                           1041 ;	-----------------------------------------
                           1042 ;	 function onewire_read
                           1043 ;	-----------------------------------------
   09EC                    1044 _onewire_read:
                    00DC   1045 	C$onewire.c$238$1$1 ==.
                           1046 ;	apps/example_onewire/onewire.c:238: uint8_t r = 0;
   09EC 7F 00              1047 	mov	r7,#0x00
                    00DE   1048 	C$onewire.c$240$1$1 ==.
                           1049 ;	apps/example_onewire/onewire.c:240: for (bitMask = 0x01; bitMask; bitMask <<= 1) {
   09EE 7E 01              1050 	mov	r6,#0x01
   09F0                    1051 00103$:
   09F0 EE                 1052 	mov	a,r6
   09F1 60 17              1053 	jz	00106$
                    00E3   1054 	C$onewire.c$241$2$2 ==.
                           1055 ;	apps/example_onewire/onewire.c:241: if ( onewire_read_bit()) r |= bitMask;
   09F3 C0 07              1056 	push	ar7
   09F5 C0 06              1057 	push	ar6
   09F7 12 09 90           1058 	lcall	_onewire_read_bit
   09FA E5 82              1059 	mov	a,dpl
   09FC D0 06              1060 	pop	ar6
   09FE D0 07              1061 	pop	ar7
   0A00 60 03              1062 	jz	00105$
   0A02 EE                 1063 	mov	a,r6
   0A03 42 07              1064 	orl	ar7,a
   0A05                    1065 00105$:
                    00F5   1066 	C$onewire.c$240$1$1 ==.
                           1067 ;	apps/example_onewire/onewire.c:240: for (bitMask = 0x01; bitMask; bitMask <<= 1) {
   0A05 EE                 1068 	mov	a,r6
   0A06 2E                 1069 	add	a,r6
   0A07 FE                 1070 	mov	r6,a
   0A08 80 E6              1071 	sjmp	00103$
   0A0A                    1072 00106$:
                    00FA   1073 	C$onewire.c$243$1$1 ==.
                           1074 ;	apps/example_onewire/onewire.c:243: return r;
   0A0A 8F 82              1075 	mov	dpl,r7
                    00FC   1076 	C$onewire.c$244$1$1 ==.
                    00FC   1077 	XG$onewire_read$0$0 ==.
   0A0C 22                 1078 	ret
                           1079 ;------------------------------------------------------------
                           1080 ;Allocation info for local variables in function 'onewire_select'
                           1081 ;------------------------------------------------------------
                    00FD   1082 	G$onewire_select$0$0 ==.
                    00FD   1083 	C$onewire.c$249$1$1 ==.
                           1084 ;	apps/example_onewire/onewire.c:249: void onewire_select( uint8_t rom[8])
                           1085 ;	-----------------------------------------
                           1086 ;	 function onewire_select
                           1087 ;	-----------------------------------------
   0A0D                    1088 _onewire_select:
   0A0D AF F0              1089 	mov	r7,b
   0A0F AE 83              1090 	mov	r6,dph
   0A11 E5 82              1091 	mov	a,dpl
   0A13 78 1A              1092 	mov	r0,#_onewire_select_rom_1_1
   0A15 F2                 1093 	movx	@r0,a
   0A16 08                 1094 	inc	r0
   0A17 EE                 1095 	mov	a,r6
   0A18 F2                 1096 	movx	@r0,a
   0A19 08                 1097 	inc	r0
   0A1A EF                 1098 	mov	a,r7
   0A1B F2                 1099 	movx	@r0,a
                    010C   1100 	C$onewire.c$253$1$1 ==.
                           1101 ;	apps/example_onewire/onewire.c:253: onewire_write(0x55,0);           // Choose ROM
   0A1C 78 19              1102 	mov	r0,#_onewire_write_PARM_2
   0A1E E4                 1103 	clr	a
   0A1F F2                 1104 	movx	@r0,a
   0A20 75 82 55           1105 	mov	dpl,#0x55
   0A23 12 09 BA           1106 	lcall	_onewire_write
                    0116   1107 	C$onewire.c$255$1$1 ==.
                           1108 ;	apps/example_onewire/onewire.c:255: for( i = 0; i < 8; i++) onewire_write(rom[i],0);
   0A26 7B 00              1109 	mov	r3,#0x00
   0A28 7C 00              1110 	mov	r4,#0x00
   0A2A                    1111 00101$:
   0A2A C3                 1112 	clr	c
   0A2B EB                 1113 	mov	a,r3
   0A2C 94 08              1114 	subb	a,#0x08
   0A2E EC                 1115 	mov	a,r4
   0A2F 64 80              1116 	xrl	a,#0x80
   0A31 94 80              1117 	subb	a,#0x80
   0A33 50 2E              1118 	jnc	00105$
   0A35 78 1A              1119 	mov	r0,#_onewire_select_rom_1_1
   0A37 E2                 1120 	movx	a,@r0
   0A38 2B                 1121 	add	a,r3
   0A39 FA                 1122 	mov	r2,a
   0A3A 08                 1123 	inc	r0
   0A3B E2                 1124 	movx	a,@r0
   0A3C 3C                 1125 	addc	a,r4
   0A3D FE                 1126 	mov	r6,a
   0A3E 08                 1127 	inc	r0
   0A3F E2                 1128 	movx	a,@r0
   0A40 FF                 1129 	mov	r7,a
   0A41 8A 82              1130 	mov	dpl,r2
   0A43 8E 83              1131 	mov	dph,r6
   0A45 8F F0              1132 	mov	b,r7
   0A47 12 22 2F           1133 	lcall	__gptrget
   0A4A FA                 1134 	mov	r2,a
   0A4B 78 19              1135 	mov	r0,#_onewire_write_PARM_2
   0A4D E4                 1136 	clr	a
   0A4E F2                 1137 	movx	@r0,a
   0A4F 8A 82              1138 	mov	dpl,r2
   0A51 C0 04              1139 	push	ar4
   0A53 C0 03              1140 	push	ar3
   0A55 12 09 BA           1141 	lcall	_onewire_write
   0A58 D0 03              1142 	pop	ar3
   0A5A D0 04              1143 	pop	ar4
   0A5C 0B                 1144 	inc	r3
   0A5D BB 00 CA           1145 	cjne	r3,#0x00,00101$
   0A60 0C                 1146 	inc	r4
   0A61 80 C7              1147 	sjmp	00101$
   0A63                    1148 00105$:
                    0153   1149 	C$onewire.c$256$1$1 ==.
                    0153   1150 	XG$onewire_select$0$0 ==.
   0A63 22                 1151 	ret
                           1152 ;------------------------------------------------------------
                           1153 ;Allocation info for local variables in function 'onewire_skip'
                           1154 ;------------------------------------------------------------
                    0154   1155 	G$onewire_skip$0$0 ==.
                    0154   1156 	C$onewire.c$261$1$1 ==.
                           1157 ;	apps/example_onewire/onewire.c:261: void onewire_skip()
                           1158 ;	-----------------------------------------
                           1159 ;	 function onewire_skip
                           1160 ;	-----------------------------------------
   0A64                    1161 _onewire_skip:
                    0154   1162 	C$onewire.c$263$1$1 ==.
                           1163 ;	apps/example_onewire/onewire.c:263: onewire_write(0xCC,0);           // Skip ROM
   0A64 78 19              1164 	mov	r0,#_onewire_write_PARM_2
   0A66 E4                 1165 	clr	a
   0A67 F2                 1166 	movx	@r0,a
   0A68 75 82 CC           1167 	mov	dpl,#0xCC
   0A6B 12 09 BA           1168 	lcall	_onewire_write
                    015E   1169 	C$onewire.c$264$1$1 ==.
                    015E   1170 	XG$onewire_skip$0$0 ==.
   0A6E 22                 1171 	ret
                           1172 ;------------------------------------------------------------
                           1173 ;Allocation info for local variables in function 'onewire_depower'
                           1174 ;------------------------------------------------------------
                    015F   1175 	G$onewire_depower$0$0 ==.
                    015F   1176 	C$onewire.c$266$1$1 ==.
                           1177 ;	apps/example_onewire/onewire.c:266: void onewire_depower()
                           1178 ;	-----------------------------------------
                           1179 ;	 function onewire_depower
                           1180 ;	-----------------------------------------
   0A6F                    1181 _onewire_depower:
                    015F   1182 	C$onewire.c$269$1$1 ==.
                           1183 ;	apps/example_onewire/onewire.c:269: DIRECT_MODE_INPUT(reg, mask);
   0A6F AF FD              1184 	mov	r7,_P0DIR
   0A71 53 07 FE           1185 	anl	ar7,#0xFE
   0A74 8F FD              1186 	mov	_P0DIR,r7
                    0166   1187 	C$onewire.c$271$1$1 ==.
                    0166   1188 	XG$onewire_depower$0$0 ==.
   0A76 22                 1189 	ret
                           1190 ;------------------------------------------------------------
                           1191 ;Allocation info for local variables in function 'onewire_reset_search'
                           1192 ;------------------------------------------------------------
                    0167   1193 	G$onewire_reset_search$0$0 ==.
                    0167   1194 	C$onewire.c$285$1$1 ==.
                           1195 ;	apps/example_onewire/onewire.c:285: void onewire_reset_search()
                           1196 ;	-----------------------------------------
                           1197 ;	 function onewire_reset_search
                           1198 ;	-----------------------------------------
   0A77                    1199 _onewire_reset_search:
                    0167   1200 	C$onewire.c$289$1$1 ==.
                           1201 ;	apps/example_onewire/onewire.c:289: LastDiscrepancy = 0;
   0A77 78 25              1202 	mov	r0,#_LastDiscrepancy
   0A79 E4                 1203 	clr	a
   0A7A F2                 1204 	movx	@r0,a
                    016B   1205 	C$onewire.c$290$1$1 ==.
                           1206 ;	apps/example_onewire/onewire.c:290: LastDeviceFlag = FALSE;
   0A7B 78 27              1207 	mov	r0,#_LastDeviceFlag
   0A7D E4                 1208 	clr	a
   0A7E F2                 1209 	movx	@r0,a
                    016F   1210 	C$onewire.c$291$1$1 ==.
                           1211 ;	apps/example_onewire/onewire.c:291: LastFamilyDiscrepancy = 0;
   0A7F 78 26              1212 	mov	r0,#_LastFamilyDiscrepancy
   0A81 E4                 1213 	clr	a
   0A82 F2                 1214 	movx	@r0,a
                    0173   1215 	C$onewire.c$292$2$2 ==.
                           1216 ;	apps/example_onewire/onewire.c:292: for(i = 7; ; i--)
   0A83 7E 07              1217 	mov	r6,#0x07
   0A85 7F 00              1218 	mov	r7,#0x00
   0A87                    1219 00104$:
                    0177   1220 	C$onewire.c$294$2$2 ==.
                           1221 ;	apps/example_onewire/onewire.c:294: ROM_NO[i] = 0;
   0A87 EE                 1222 	mov	a,r6
   0A88 24 1D              1223 	add	a,#_ROM_NO
   0A8A F8                 1224 	mov	r0,a
   0A8B E4                 1225 	clr	a
   0A8C F2                 1226 	movx	@r0,a
                    017D   1227 	C$onewire.c$295$2$2 ==.
                           1228 ;	apps/example_onewire/onewire.c:295: if ( i == 0) break;
   0A8D EE                 1229 	mov	a,r6
   0A8E 4F                 1230 	orl	a,r7
   0A8F 60 07              1231 	jz	00107$
                    0181   1232 	C$onewire.c$292$1$1 ==.
                           1233 ;	apps/example_onewire/onewire.c:292: for(i = 7; ; i--)
   0A91 1E                 1234 	dec	r6
   0A92 BE FF 01           1235 	cjne	r6,#0xFF,00113$
   0A95 1F                 1236 	dec	r7
   0A96                    1237 00113$:
   0A96 80 EF              1238 	sjmp	00104$
   0A98                    1239 00107$:
                    0188   1240 	C$onewire.c$297$1$1 ==.
                    0188   1241 	XG$onewire_reset_search$0$0 ==.
   0A98 22                 1242 	ret
                           1243 ;------------------------------------------------------------
                           1244 ;Allocation info for local variables in function 'onewire_search'
                           1245 ;------------------------------------------------------------
                    0189   1246 	G$onewire_search$0$0 ==.
                    0189   1247 	C$onewire.c$315$1$1 ==.
                           1248 ;	apps/example_onewire/onewire.c:315: uint8_t onewire_search(uint8_t *newAddr)
                           1249 ;	-----------------------------------------
                           1250 ;	 function onewire_search
                           1251 ;	-----------------------------------------
   0A99                    1252 _onewire_search:
   0A99 AF F0              1253 	mov	r7,b
   0A9B AE 83              1254 	mov	r6,dph
   0A9D E5 82              1255 	mov	a,dpl
   0A9F 78 28              1256 	mov	r0,#_onewire_search_newAddr_1_1
   0AA1 F2                 1257 	movx	@r0,a
   0AA2 08                 1258 	inc	r0
   0AA3 EE                 1259 	mov	a,r6
   0AA4 F2                 1260 	movx	@r0,a
   0AA5 08                 1261 	inc	r0
   0AA6 EF                 1262 	mov	a,r7
   0AA7 F2                 1263 	movx	@r0,a
                    0198   1264 	C$onewire.c$326$1$1 ==.
                           1265 ;	apps/example_onewire/onewire.c:326: last_zero = 0;
   0AA8 7C 00              1266 	mov	r4,#0x00
                    019A   1267 	C$onewire.c$328$1$1 ==.
                           1268 ;	apps/example_onewire/onewire.c:328: rom_byte_mask = 1;
   0AAA 7B 01              1269 	mov	r3,#0x01
                    019C   1270 	C$onewire.c$329$1$1 ==.
                           1271 ;	apps/example_onewire/onewire.c:329: search_result = 0;
   0AAC 78 2B              1272 	mov	r0,#_onewire_search_search_result_1_1
   0AAE E4                 1273 	clr	a
   0AAF F2                 1274 	movx	@r0,a
                    01A0   1275 	C$onewire.c$332$1$1 ==.
                           1276 ;	apps/example_onewire/onewire.c:332: if (!LastDeviceFlag)
   0AB0 78 27              1277 	mov	r0,#_LastDeviceFlag
   0AB2 E2                 1278 	movx	a,@r0
   0AB3 60 03              1279 	jz	00160$
   0AB5 02 0B B4           1280 	ljmp	00130$
   0AB8                    1281 00160$:
                    01A8   1282 	C$onewire.c$335$2$2 ==.
                           1283 ;	apps/example_onewire/onewire.c:335: if (!onewire_reset())
   0AB8 C0 04              1284 	push	ar4
   0ABA C0 03              1285 	push	ar3
   0ABC 12 09 14           1286 	lcall	_onewire_reset
   0ABF E5 82              1287 	mov	a,dpl
   0AC1 D0 03              1288 	pop	ar3
   0AC3 D0 04              1289 	pop	ar4
   0AC5 70 12              1290 	jnz	00102$
                    01B7   1291 	C$onewire.c$338$3$3 ==.
                           1292 ;	apps/example_onewire/onewire.c:338: LastDiscrepancy = 0;
   0AC7 78 25              1293 	mov	r0,#_LastDiscrepancy
   0AC9 E4                 1294 	clr	a
   0ACA F2                 1295 	movx	@r0,a
                    01BB   1296 	C$onewire.c$339$3$3 ==.
                           1297 ;	apps/example_onewire/onewire.c:339: LastDeviceFlag = FALSE;
   0ACB 78 27              1298 	mov	r0,#_LastDeviceFlag
   0ACD E4                 1299 	clr	a
   0ACE F2                 1300 	movx	@r0,a
                    01BF   1301 	C$onewire.c$340$3$3 ==.
                           1302 ;	apps/example_onewire/onewire.c:340: LastFamilyDiscrepancy = 0;
   0ACF 78 26              1303 	mov	r0,#_LastFamilyDiscrepancy
   0AD1 E4                 1304 	clr	a
   0AD2 F2                 1305 	movx	@r0,a
                    01C3   1306 	C$onewire.c$341$3$3 ==.
                           1307 ;	apps/example_onewire/onewire.c:341: return FALSE;
   0AD3 75 82 00           1308 	mov	dpl,#0x00
   0AD6 02 0C 04           1309 	ljmp	00138$
   0AD9                    1310 00102$:
                    01C9   1311 	C$onewire.c$345$2$2 ==.
                           1312 ;	apps/example_onewire/onewire.c:345: onewire_write(0xF0,0);
   0AD9 78 19              1313 	mov	r0,#_onewire_write_PARM_2
   0ADB E4                 1314 	clr	a
   0ADC F2                 1315 	movx	@r0,a
   0ADD 75 82 F0           1316 	mov	dpl,#0xF0
   0AE0 C0 04              1317 	push	ar4
   0AE2 C0 03              1318 	push	ar3
   0AE4 12 09 BA           1319 	lcall	_onewire_write
   0AE7 D0 03              1320 	pop	ar3
   0AE9 D0 04              1321 	pop	ar4
                    01DB   1322 	C$onewire.c$348$5$6 ==.
                           1323 ;	apps/example_onewire/onewire.c:348: do
   0AEB 7A 00              1324 	mov	r2,#0x00
   0AED 7F 01              1325 	mov	r7,#0x01
   0AEF                    1326 00122$:
                    01DF   1327 	C$onewire.c$351$3$4 ==.
                           1328 ;	apps/example_onewire/onewire.c:351: id_bit = onewire_read_bit();
   0AEF C0 07              1329 	push	ar7
   0AF1 C0 04              1330 	push	ar4
   0AF3 C0 03              1331 	push	ar3
   0AF5 C0 02              1332 	push	ar2
   0AF7 12 09 90           1333 	lcall	_onewire_read_bit
   0AFA AE 82              1334 	mov	r6,dpl
   0AFC D0 02              1335 	pop	ar2
   0AFE D0 03              1336 	pop	ar3
   0B00 D0 04              1337 	pop	ar4
                    01F2   1338 	C$onewire.c$352$3$4 ==.
                           1339 ;	apps/example_onewire/onewire.c:352: cmp_id_bit = onewire_read_bit();
   0B02 C0 06              1340 	push	ar6
   0B04 C0 04              1341 	push	ar4
   0B06 C0 03              1342 	push	ar3
   0B08 C0 02              1343 	push	ar2
   0B0A 12 09 90           1344 	lcall	_onewire_read_bit
   0B0D AD 82              1345 	mov	r5,dpl
   0B0F D0 02              1346 	pop	ar2
   0B11 D0 03              1347 	pop	ar3
   0B13 D0 04              1348 	pop	ar4
   0B15 D0 06              1349 	pop	ar6
   0B17 D0 07              1350 	pop	ar7
                    0209   1351 	C$onewire.c$355$3$4 ==.
                           1352 ;	apps/example_onewire/onewire.c:355: if ((id_bit == 1) && (cmp_id_bit == 1))
   0B19 BE 01 06           1353 	cjne	r6,#0x01,00119$
   0B1C BD 01 03           1354 	cjne	r5,#0x01,00164$
   0B1F 02 0B 9E           1355 	ljmp	00124$
   0B22                    1356 00164$:
                    0212   1357 	C$onewire.c$356$3$4 ==.
                           1358 ;	apps/example_onewire/onewire.c:356: break;
   0B22                    1359 00119$:
                    0212   1360 	C$onewire.c$360$4$5 ==.
                           1361 ;	apps/example_onewire/onewire.c:360: if (id_bit != cmp_id_bit)
   0B22 EE                 1362 	mov	a,r6
                    0213   1363 	C$onewire.c$361$4$5 ==.
                           1364 ;	apps/example_onewire/onewire.c:361: search_direction = id_bit;  // bit write value for search
   0B23 B5 05 37           1365 	cjne	a,ar5,00112$
                    0216   1366 	C$onewire.c$366$5$6 ==.
                           1367 ;	apps/example_onewire/onewire.c:366: if (id_bit_number < LastDiscrepancy)
   0B26 78 25              1368 	mov	r0,#_LastDiscrepancy
   0B28 C3                 1369 	clr	c
   0B29 E2                 1370 	movx	a,@r0
   0B2A F5 F0              1371 	mov	b,a
   0B2C EF                 1372 	mov	a,r7
   0B2D 95 F0              1373 	subb	a,b
   0B2F 50 11              1374 	jnc	00104$
                    0221   1375 	C$onewire.c$367$5$6 ==.
                           1376 ;	apps/example_onewire/onewire.c:367: search_direction = ((ROM_NO[rom_byte_number] & rom_byte_mask) > 0);
   0B31 EA                 1377 	mov	a,r2
   0B32 24 1D              1378 	add	a,#_ROM_NO
   0B34 F9                 1379 	mov	r1,a
   0B35 E3                 1380 	movx	a,@r1
   0B36 FD                 1381 	mov	r5,a
   0B37 EB                 1382 	mov	a,r3
   0B38 5D                 1383 	anl	a,r5
   0B39 60 02              1384 	jz	00140$
   0B3B 74 01              1385 	mov	a,#0x01
   0B3D                    1386 00140$:
   0B3D FD                 1387 	mov	r5,a
   0B3E 8D 06              1388 	mov	ar6,r5
   0B40 80 0D              1389 	sjmp	00105$
   0B42                    1390 00104$:
                    0232   1391 	C$onewire.c$370$5$6 ==.
                           1392 ;	apps/example_onewire/onewire.c:370: search_direction = (id_bit_number == LastDiscrepancy);
   0B42 78 25              1393 	mov	r0,#_LastDiscrepancy
   0B44 E2                 1394 	movx	a,@r0
   0B45 B5 07 04           1395 	cjne	a,ar7,00168$
   0B48 74 01              1396 	mov	a,#0x01
   0B4A 80 01              1397 	sjmp	00169$
   0B4C                    1398 00168$:
   0B4C E4                 1399 	clr	a
   0B4D                    1400 00169$:
   0B4D FD                 1401 	mov	r5,a
   0B4E FE                 1402 	mov	r6,a
   0B4F                    1403 00105$:
                    023F   1404 	C$onewire.c$373$5$6 ==.
                           1405 ;	apps/example_onewire/onewire.c:373: if (search_direction == 0)
   0B4F EE                 1406 	mov	a,r6
   0B50 70 0B              1407 	jnz	00112$
                    0242   1408 	C$onewire.c$375$6$7 ==.
                           1409 ;	apps/example_onewire/onewire.c:375: last_zero = id_bit_number;
   0B52 8F 04              1410 	mov	ar4,r7
                    0244   1411 	C$onewire.c$378$6$7 ==.
                           1412 ;	apps/example_onewire/onewire.c:378: if (last_zero < 9)
   0B54 BF 09 00           1413 	cjne	r7,#0x09,00171$
   0B57                    1414 00171$:
   0B57 50 04              1415 	jnc	00112$
                    0249   1416 	C$onewire.c$379$6$7 ==.
                           1417 ;	apps/example_onewire/onewire.c:379: LastFamilyDiscrepancy = last_zero;
   0B59 78 26              1418 	mov	r0,#_LastFamilyDiscrepancy
   0B5B EF                 1419 	mov	a,r7
   0B5C F2                 1420 	movx	@r0,a
   0B5D                    1421 00112$:
                    024D   1422 	C$onewire.c$385$4$5 ==.
                           1423 ;	apps/example_onewire/onewire.c:385: if (search_direction == 1)
   0B5D BE 01 0A           1424 	cjne	r6,#0x01,00114$
                    0250   1425 	C$onewire.c$386$4$5 ==.
                           1426 ;	apps/example_onewire/onewire.c:386: ROM_NO[rom_byte_number] |= rom_byte_mask;
   0B60 EA                 1427 	mov	a,r2
   0B61 24 1D              1428 	add	a,#_ROM_NO
   0B63 F9                 1429 	mov	r1,a
   0B64 E3                 1430 	movx	a,@r1
   0B65 FD                 1431 	mov	r5,a
   0B66 4B                 1432 	orl	a,r3
   0B67 F3                 1433 	movx	@r1,a
   0B68 80 0E              1434 	sjmp	00115$
   0B6A                    1435 00114$:
                    025A   1436 	C$onewire.c$388$1$1 ==.
                           1437 ;	apps/example_onewire/onewire.c:388: ROM_NO[rom_byte_number] &= ~rom_byte_mask;
   0B6A C0 04              1438 	push	ar4
   0B6C EA                 1439 	mov	a,r2
   0B6D 24 1D              1440 	add	a,#_ROM_NO
   0B6F F9                 1441 	mov	r1,a
   0B70 E3                 1442 	movx	a,@r1
   0B71 FD                 1443 	mov	r5,a
   0B72 EB                 1444 	mov	a,r3
   0B73 F4                 1445 	cpl	a
   0B74 5D                 1446 	anl	a,r5
   0B75 F3                 1447 	movx	@r1,a
                    0266   1448 	C$onewire.c$431$1$1 ==.
                           1449 ;	apps/example_onewire/onewire.c:431: return search_result;
   0B76 D0 04              1450 	pop	ar4
                    0268   1451 	C$onewire.c$388$4$5 ==.
                           1452 ;	apps/example_onewire/onewire.c:388: ROM_NO[rom_byte_number] &= ~rom_byte_mask;
   0B78                    1453 00115$:
                    0268   1454 	C$onewire.c$391$4$5 ==.
                           1455 ;	apps/example_onewire/onewire.c:391: onewire_write_bit(search_direction);
   0B78 8E 82              1456 	mov	dpl,r6
   0B7A C0 07              1457 	push	ar7
   0B7C C0 04              1458 	push	ar4
   0B7E C0 03              1459 	push	ar3
   0B80 C0 02              1460 	push	ar2
   0B82 12 09 61           1461 	lcall	_onewire_write_bit
   0B85 D0 02              1462 	pop	ar2
   0B87 D0 03              1463 	pop	ar3
   0B89 D0 04              1464 	pop	ar4
   0B8B D0 07              1465 	pop	ar7
                    027D   1466 	C$onewire.c$395$4$5 ==.
                           1467 ;	apps/example_onewire/onewire.c:395: id_bit_number++;
   0B8D 0F                 1468 	inc	r7
                    027E   1469 	C$onewire.c$396$4$5 ==.
                           1470 ;	apps/example_onewire/onewire.c:396: rom_byte_mask <<= 1;
   0B8E EB                 1471 	mov	a,r3
   0B8F 2B                 1472 	add	a,r3
                    0280   1473 	C$onewire.c$399$4$5 ==.
                           1474 ;	apps/example_onewire/onewire.c:399: if (rom_byte_mask == 0)
   0B90 FB                 1475 	mov	r3,a
   0B91 70 03              1476 	jnz	00123$
                    0283   1477 	C$onewire.c$401$5$8 ==.
                           1478 ;	apps/example_onewire/onewire.c:401: rom_byte_number++;
   0B93 0A                 1479 	inc	r2
                    0284   1480 	C$onewire.c$402$5$8 ==.
                           1481 ;	apps/example_onewire/onewire.c:402: rom_byte_mask = 1;
   0B94 7B 01              1482 	mov	r3,#0x01
   0B96                    1483 00123$:
                    0286   1484 	C$onewire.c$406$2$2 ==.
                           1485 ;	apps/example_onewire/onewire.c:406: while(rom_byte_number < 8);  // loop until through all ROM bytes 0-7
   0B96 BA 08 00           1486 	cjne	r2,#0x08,00176$
   0B99                    1487 00176$:
   0B99 50 03              1488 	jnc	00177$
   0B9B 02 0A EF           1489 	ljmp	00122$
   0B9E                    1490 00177$:
   0B9E                    1491 00124$:
                    028E   1492 	C$onewire.c$409$2$2 ==.
                           1493 ;	apps/example_onewire/onewire.c:409: if (!(id_bit_number < 65))
   0B9E BF 41 00           1494 	cjne	r7,#0x41,00178$
   0BA1                    1495 00178$:
   0BA1 40 11              1496 	jc	00130$
                    0293   1497 	C$onewire.c$412$3$9 ==.
                           1498 ;	apps/example_onewire/onewire.c:412: LastDiscrepancy = last_zero;
   0BA3 78 25              1499 	mov	r0,#_LastDiscrepancy
   0BA5 EC                 1500 	mov	a,r4
   0BA6 F2                 1501 	movx	@r0,a
                    0297   1502 	C$onewire.c$415$3$9 ==.
                           1503 ;	apps/example_onewire/onewire.c:415: if (LastDiscrepancy == 0)
   0BA7 EC                 1504 	mov	a,r4
   0BA8 70 05              1505 	jnz	00126$
                    029A   1506 	C$onewire.c$416$3$9 ==.
                           1507 ;	apps/example_onewire/onewire.c:416: LastDeviceFlag = TRUE;
   0BAA 78 27              1508 	mov	r0,#_LastDeviceFlag
   0BAC 74 01              1509 	mov	a,#0x01
   0BAE F2                 1510 	movx	@r0,a
   0BAF                    1511 00126$:
                    029F   1512 	C$onewire.c$418$3$9 ==.
                           1513 ;	apps/example_onewire/onewire.c:418: search_result = TRUE;
   0BAF 78 2B              1514 	mov	r0,#_onewire_search_search_result_1_1
   0BB1 74 01              1515 	mov	a,#0x01
   0BB3 F2                 1516 	movx	@r0,a
   0BB4                    1517 00130$:
                    02A4   1518 	C$onewire.c$423$1$1 ==.
                           1519 ;	apps/example_onewire/onewire.c:423: if (!search_result || !ROM_NO[0])
   0BB4 78 2B              1520 	mov	r0,#_onewire_search_search_result_1_1
   0BB6 E2                 1521 	movx	a,@r0
   0BB7 60 05              1522 	jz	00131$
   0BB9 78 1D              1523 	mov	r0,#_ROM_NO
   0BBB E2                 1524 	movx	a,@r0
   0BBC 70 10              1525 	jnz	00157$
   0BBE                    1526 00131$:
                    02AE   1527 	C$onewire.c$425$2$10 ==.
                           1528 ;	apps/example_onewire/onewire.c:425: LastDiscrepancy = 0;
   0BBE 78 25              1529 	mov	r0,#_LastDiscrepancy
   0BC0 E4                 1530 	clr	a
   0BC1 F2                 1531 	movx	@r0,a
                    02B2   1532 	C$onewire.c$426$2$10 ==.
                           1533 ;	apps/example_onewire/onewire.c:426: LastDeviceFlag = FALSE;
   0BC2 78 27              1534 	mov	r0,#_LastDeviceFlag
   0BC4 E4                 1535 	clr	a
   0BC5 F2                 1536 	movx	@r0,a
                    02B6   1537 	C$onewire.c$427$2$10 ==.
                           1538 ;	apps/example_onewire/onewire.c:427: LastFamilyDiscrepancy = 0;
   0BC6 78 26              1539 	mov	r0,#_LastFamilyDiscrepancy
   0BC8 E4                 1540 	clr	a
   0BC9 F2                 1541 	movx	@r0,a
                    02BA   1542 	C$onewire.c$428$2$10 ==.
                           1543 ;	apps/example_onewire/onewire.c:428: search_result = FALSE;
   0BCA 78 2B              1544 	mov	r0,#_onewire_search_search_result_1_1
   0BCC E4                 1545 	clr	a
   0BCD F2                 1546 	movx	@r0,a
                    02BE   1547 	C$onewire.c$430$1$1 ==.
                           1548 ;	apps/example_onewire/onewire.c:430: for (i = 0; i < 8; i++) newAddr[i] = ROM_NO[i];
   0BCE                    1549 00157$:
   0BCE 7E 00              1550 	mov	r6,#0x00
   0BD0 7F 00              1551 	mov	r7,#0x00
   0BD2                    1552 00134$:
   0BD2 C3                 1553 	clr	c
   0BD3 EE                 1554 	mov	a,r6
   0BD4 94 08              1555 	subb	a,#0x08
   0BD6 EF                 1556 	mov	a,r7
   0BD7 64 80              1557 	xrl	a,#0x80
   0BD9 94 80              1558 	subb	a,#0x80
   0BDB 50 22              1559 	jnc	00137$
   0BDD 78 28              1560 	mov	r0,#_onewire_search_newAddr_1_1
   0BDF E2                 1561 	movx	a,@r0
   0BE0 2E                 1562 	add	a,r6
   0BE1 FB                 1563 	mov	r3,a
   0BE2 08                 1564 	inc	r0
   0BE3 E2                 1565 	movx	a,@r0
   0BE4 3F                 1566 	addc	a,r7
   0BE5 FC                 1567 	mov	r4,a
   0BE6 08                 1568 	inc	r0
   0BE7 E2                 1569 	movx	a,@r0
   0BE8 FD                 1570 	mov	r5,a
   0BE9 EE                 1571 	mov	a,r6
   0BEA 24 1D              1572 	add	a,#_ROM_NO
   0BEC F9                 1573 	mov	r1,a
   0BED E3                 1574 	movx	a,@r1
   0BEE FA                 1575 	mov	r2,a
   0BEF 8B 82              1576 	mov	dpl,r3
   0BF1 8C 83              1577 	mov	dph,r4
   0BF3 8D F0              1578 	mov	b,r5
   0BF5 12 0D 48           1579 	lcall	__gptrput
   0BF8 0E                 1580 	inc	r6
   0BF9 BE 00 D6           1581 	cjne	r6,#0x00,00134$
   0BFC 0F                 1582 	inc	r7
   0BFD 80 D3              1583 	sjmp	00134$
   0BFF                    1584 00137$:
                    02EF   1585 	C$onewire.c$431$1$1 ==.
                           1586 ;	apps/example_onewire/onewire.c:431: return search_result;
   0BFF 78 2B              1587 	mov	r0,#_onewire_search_search_result_1_1
   0C01 E2                 1588 	movx	a,@r0
   0C02 F5 82              1589 	mov	dpl,a
   0C04                    1590 00138$:
                    02F4   1591 	C$onewire.c$432$1$1 ==.
                    02F4   1592 	XG$onewire_search$0$0 ==.
   0C04 22                 1593 	ret
                           1594 ;------------------------------------------------------------
                           1595 ;Allocation info for local variables in function 'onewire_crc8'
                           1596 ;------------------------------------------------------------
                    02F5   1597 	G$onewire_crc8$0$0 ==.
                    02F5   1598 	C$onewire.c$482$1$1 ==.
                           1599 ;	apps/example_onewire/onewire.c:482: uint8_t onewire_crc8( uint8_t *addr, uint8_t len)
                           1600 ;	-----------------------------------------
                           1601 ;	 function onewire_crc8
                           1602 ;	-----------------------------------------
   0C05                    1603 _onewire_crc8:
   0C05 AD 82              1604 	mov	r5,dpl
   0C07 AE 83              1605 	mov	r6,dph
   0C09 AF F0              1606 	mov	r7,b
                    02FB   1607 	C$onewire.c$484$1$1 ==.
                           1608 ;	apps/example_onewire/onewire.c:484: uint8_t crc = 0;
   0C0B 7C 00              1609 	mov	r4,#0x00
                    02FD   1610 	C$onewire.c$487$1$1 ==.
                           1611 ;	apps/example_onewire/onewire.c:487: while (len--) {
   0C0D 78 2C              1612 	mov	r0,#_onewire_crc8_PARM_2
   0C0F E2                 1613 	movx	a,@r0
   0C10 FB                 1614 	mov	r3,a
   0C11                    1615 00103$:
   0C11 8B 02              1616 	mov	ar2,r3
   0C13 1B                 1617 	dec	r3
   0C14 EA                 1618 	mov	a,r2
   0C15 60 34              1619 	jz	00105$
                    0307   1620 	C$onewire.c$488$2$2 ==.
                           1621 ;	apps/example_onewire/onewire.c:488: uint8_t inbyte = *addr++;
   0C17 8D 82              1622 	mov	dpl,r5
   0C19 8E 83              1623 	mov	dph,r6
   0C1B 8F F0              1624 	mov	b,r7
   0C1D 78 2D              1625 	mov	r0,#_onewire_crc8_inbyte_2_2
   0C1F 12 22 2F           1626 	lcall	__gptrget
   0C22 F2                 1627 	movx	@r0,a
   0C23 A3                 1628 	inc	dptr
   0C24 AD 82              1629 	mov	r5,dpl
   0C26 AE 83              1630 	mov	r6,dph
                    0318   1631 	C$onewire.c$489$1$1 ==.
                           1632 ;	apps/example_onewire/onewire.c:489: for (i = 8; i; i--) {
   0C28 7A 08              1633 	mov	r2,#0x08
   0C2A                    1634 00106$:
   0C2A EA                 1635 	mov	a,r2
   0C2B 60 E4              1636 	jz	00103$
                    031D   1637 	C$onewire.c$490$3$3 ==.
                           1638 ;	apps/example_onewire/onewire.c:490: uint8_t mix = (crc ^ inbyte) & 0x01;
   0C2D 78 2D              1639 	mov	r0,#_onewire_crc8_inbyte_2_2
   0C2F E2                 1640 	movx	a,@r0
   0C30 6C                 1641 	xrl	a,r4
   0C31 78 2E              1642 	mov	r0,#_onewire_crc8_mix_3_3
   0C33 54 01              1643 	anl	a,#0x01
   0C35 F2                 1644 	movx	@r0,a
                    0326   1645 	C$onewire.c$491$3$3 ==.
                           1646 ;	apps/example_onewire/onewire.c:491: crc >>= 1;
   0C36 EC                 1647 	mov	a,r4
   0C37 C3                 1648 	clr	c
   0C38 13                 1649 	rrc	a
   0C39 FC                 1650 	mov	r4,a
                    032A   1651 	C$onewire.c$492$3$3 ==.
                           1652 ;	apps/example_onewire/onewire.c:492: if (mix) crc ^= 0x8C;
   0C3A 78 2E              1653 	mov	r0,#_onewire_crc8_mix_3_3
   0C3C E2                 1654 	movx	a,@r0
   0C3D 60 03              1655 	jz	00102$
   0C3F 63 04 8C           1656 	xrl	ar4,#0x8C
   0C42                    1657 00102$:
                    0332   1658 	C$onewire.c$493$3$3 ==.
                           1659 ;	apps/example_onewire/onewire.c:493: inbyte >>= 1;
   0C42 78 2D              1660 	mov	r0,#_onewire_crc8_inbyte_2_2
   0C44 E2                 1661 	movx	a,@r0
   0C45 C3                 1662 	clr	c
   0C46 13                 1663 	rrc	a
   0C47 F2                 1664 	movx	@r0,a
                    0338   1665 	C$onewire.c$489$2$2 ==.
                           1666 ;	apps/example_onewire/onewire.c:489: for (i = 8; i; i--) {
   0C48 1A                 1667 	dec	r2
   0C49 80 DF              1668 	sjmp	00106$
   0C4B                    1669 00105$:
                    033B   1670 	C$onewire.c$496$1$1 ==.
                           1671 ;	apps/example_onewire/onewire.c:496: return crc;
   0C4B 8C 82              1672 	mov	dpl,r4
                    033D   1673 	C$onewire.c$497$1$1 ==.
                    033D   1674 	XG$onewire_crc8$0$0 ==.
   0C4D 22                 1675 	ret
                           1676 	.area CSEG    (CODE)
                           1677 	.area CONST   (CODE)
                           1678 	.area XINIT   (CODE)
                           1679 	.area CABS    (ABS,CODE)
