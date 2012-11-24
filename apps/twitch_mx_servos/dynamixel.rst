                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:48:18 2012
                              5 ;--------------------------------------------------------
                              6 	.module dynamixel
                              7 	.optsdcc -mmcs51 --model-medium
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _uart1TxSendByte
                             13 	.globl _malloc
                             14 	.globl _delayMicroseconds
                             15 	.globl _dynamixel_makeword_PARM_2
                             16 	.globl _dynamixel_syncwrite_PARM_4
                             17 	.globl _dynamixel_syncwrite_PARM_3
                             18 	.globl _dynamixel_syncwrite_PARM_2
                             19 	.globl _dynamixel_writebyte_PARM_3
                             20 	.globl _dynamixel_writebyte_PARM_2
                             21 	.globl _dynamixel_txrx_PARM_2
                             22 	.globl _dynamixel_readpacket_PARM_2
                             23 	.globl _dynamixel_writepacket_PARM_2
                             24 	.globl _dynamixel_rxindex
                             25 	.globl _dynamixel_rxpacket
                             26 	.globl _dynamixel_txpacket
                             27 	.globl _dynamixel_init
                             28 	.globl _dynamixel_settx
                             29 	.globl _dynamixel_setrx
                             30 	.globl _dynamixel_write
                             31 	.globl _dynamixel_calculatechecksum
                             32 	.globl _dynamixel_writepacket
                             33 	.globl _dynamixel_readpacket
                             34 	.globl _dynamixel_txrx
                             35 	.globl _dynamixel_writebyte
                             36 	.globl _dynamixel_syncwrite
                             37 	.globl _dynamixel_makeword
                             38 	.globl _dynamixel_getlowbyte
                             39 	.globl _dynamixel_gethighbyte
                             40 ;--------------------------------------------------------
                             41 ; special function registers
                             42 ;--------------------------------------------------------
                             43 	.area RSEG    (ABS,DATA)
   0000                      44 	.org 0x0000
                    0080     45 Fdynamixel$P0$0$0 == 0x0080
                    0080     46 _P0	=	0x0080
                    0081     47 Fdynamixel$SP$0$0 == 0x0081
                    0081     48 _SP	=	0x0081
                    0082     49 Fdynamixel$DPL0$0$0 == 0x0082
                    0082     50 _DPL0	=	0x0082
                    0083     51 Fdynamixel$DPH0$0$0 == 0x0083
                    0083     52 _DPH0	=	0x0083
                    0084     53 Fdynamixel$DPL1$0$0 == 0x0084
                    0084     54 _DPL1	=	0x0084
                    0085     55 Fdynamixel$DPH1$0$0 == 0x0085
                    0085     56 _DPH1	=	0x0085
                    0086     57 Fdynamixel$U0CSR$0$0 == 0x0086
                    0086     58 _U0CSR	=	0x0086
                    0087     59 Fdynamixel$PCON$0$0 == 0x0087
                    0087     60 _PCON	=	0x0087
                    0088     61 Fdynamixel$TCON$0$0 == 0x0088
                    0088     62 _TCON	=	0x0088
                    0089     63 Fdynamixel$P0IFG$0$0 == 0x0089
                    0089     64 _P0IFG	=	0x0089
                    008A     65 Fdynamixel$P1IFG$0$0 == 0x008a
                    008A     66 _P1IFG	=	0x008a
                    008B     67 Fdynamixel$P2IFG$0$0 == 0x008b
                    008B     68 _P2IFG	=	0x008b
                    008C     69 Fdynamixel$PICTL$0$0 == 0x008c
                    008C     70 _PICTL	=	0x008c
                    008D     71 Fdynamixel$P1IEN$0$0 == 0x008d
                    008D     72 _P1IEN	=	0x008d
                    008F     73 Fdynamixel$P0INP$0$0 == 0x008f
                    008F     74 _P0INP	=	0x008f
                    0090     75 Fdynamixel$P1$0$0 == 0x0090
                    0090     76 _P1	=	0x0090
                    0091     77 Fdynamixel$RFIM$0$0 == 0x0091
                    0091     78 _RFIM	=	0x0091
                    0092     79 Fdynamixel$DPS$0$0 == 0x0092
                    0092     80 _DPS	=	0x0092
                    0093     81 Fdynamixel$MPAGE$0$0 == 0x0093
                    0093     82 _MPAGE	=	0x0093
                    0095     83 Fdynamixel$ENDIAN$0$0 == 0x0095
                    0095     84 _ENDIAN	=	0x0095
                    0098     85 Fdynamixel$S0CON$0$0 == 0x0098
                    0098     86 _S0CON	=	0x0098
                    009A     87 Fdynamixel$IEN2$0$0 == 0x009a
                    009A     88 _IEN2	=	0x009a
                    009B     89 Fdynamixel$S1CON$0$0 == 0x009b
                    009B     90 _S1CON	=	0x009b
                    009C     91 Fdynamixel$T2CT$0$0 == 0x009c
                    009C     92 _T2CT	=	0x009c
                    009D     93 Fdynamixel$T2PR$0$0 == 0x009d
                    009D     94 _T2PR	=	0x009d
                    009E     95 Fdynamixel$T2CTL$0$0 == 0x009e
                    009E     96 _T2CTL	=	0x009e
                    00A0     97 Fdynamixel$P2$0$0 == 0x00a0
                    00A0     98 _P2	=	0x00a0
                    00A1     99 Fdynamixel$WORIRQ$0$0 == 0x00a1
                    00A1    100 _WORIRQ	=	0x00a1
                    00A2    101 Fdynamixel$WORCTRL$0$0 == 0x00a2
                    00A2    102 _WORCTRL	=	0x00a2
                    00A3    103 Fdynamixel$WOREVT0$0$0 == 0x00a3
                    00A3    104 _WOREVT0	=	0x00a3
                    00A4    105 Fdynamixel$WOREVT1$0$0 == 0x00a4
                    00A4    106 _WOREVT1	=	0x00a4
                    00A5    107 Fdynamixel$WORTIME0$0$0 == 0x00a5
                    00A5    108 _WORTIME0	=	0x00a5
                    00A6    109 Fdynamixel$WORTIME1$0$0 == 0x00a6
                    00A6    110 _WORTIME1	=	0x00a6
                    00A8    111 Fdynamixel$IEN0$0$0 == 0x00a8
                    00A8    112 _IEN0	=	0x00a8
                    00A9    113 Fdynamixel$IP0$0$0 == 0x00a9
                    00A9    114 _IP0	=	0x00a9
                    00AB    115 Fdynamixel$FWT$0$0 == 0x00ab
                    00AB    116 _FWT	=	0x00ab
                    00AC    117 Fdynamixel$FADDRL$0$0 == 0x00ac
                    00AC    118 _FADDRL	=	0x00ac
                    00AD    119 Fdynamixel$FADDRH$0$0 == 0x00ad
                    00AD    120 _FADDRH	=	0x00ad
                    00AE    121 Fdynamixel$FCTL$0$0 == 0x00ae
                    00AE    122 _FCTL	=	0x00ae
                    00AF    123 Fdynamixel$FWDATA$0$0 == 0x00af
                    00AF    124 _FWDATA	=	0x00af
                    00B1    125 Fdynamixel$ENCDI$0$0 == 0x00b1
                    00B1    126 _ENCDI	=	0x00b1
                    00B2    127 Fdynamixel$ENCDO$0$0 == 0x00b2
                    00B2    128 _ENCDO	=	0x00b2
                    00B3    129 Fdynamixel$ENCCS$0$0 == 0x00b3
                    00B3    130 _ENCCS	=	0x00b3
                    00B4    131 Fdynamixel$ADCCON1$0$0 == 0x00b4
                    00B4    132 _ADCCON1	=	0x00b4
                    00B5    133 Fdynamixel$ADCCON2$0$0 == 0x00b5
                    00B5    134 _ADCCON2	=	0x00b5
                    00B6    135 Fdynamixel$ADCCON3$0$0 == 0x00b6
                    00B6    136 _ADCCON3	=	0x00b6
                    00B8    137 Fdynamixel$IEN1$0$0 == 0x00b8
                    00B8    138 _IEN1	=	0x00b8
                    00B9    139 Fdynamixel$IP1$0$0 == 0x00b9
                    00B9    140 _IP1	=	0x00b9
                    00BA    141 Fdynamixel$ADCL$0$0 == 0x00ba
                    00BA    142 _ADCL	=	0x00ba
                    00BB    143 Fdynamixel$ADCH$0$0 == 0x00bb
                    00BB    144 _ADCH	=	0x00bb
                    00BC    145 Fdynamixel$RNDL$0$0 == 0x00bc
                    00BC    146 _RNDL	=	0x00bc
                    00BD    147 Fdynamixel$RNDH$0$0 == 0x00bd
                    00BD    148 _RNDH	=	0x00bd
                    00BE    149 Fdynamixel$SLEEP$0$0 == 0x00be
                    00BE    150 _SLEEP	=	0x00be
                    00C0    151 Fdynamixel$IRCON$0$0 == 0x00c0
                    00C0    152 _IRCON	=	0x00c0
                    00C1    153 Fdynamixel$U0DBUF$0$0 == 0x00c1
                    00C1    154 _U0DBUF	=	0x00c1
                    00C2    155 Fdynamixel$U0BAUD$0$0 == 0x00c2
                    00C2    156 _U0BAUD	=	0x00c2
                    00C4    157 Fdynamixel$U0UCR$0$0 == 0x00c4
                    00C4    158 _U0UCR	=	0x00c4
                    00C5    159 Fdynamixel$U0GCR$0$0 == 0x00c5
                    00C5    160 _U0GCR	=	0x00c5
                    00C6    161 Fdynamixel$CLKCON$0$0 == 0x00c6
                    00C6    162 _CLKCON	=	0x00c6
                    00C7    163 Fdynamixel$MEMCTR$0$0 == 0x00c7
                    00C7    164 _MEMCTR	=	0x00c7
                    00C9    165 Fdynamixel$WDCTL$0$0 == 0x00c9
                    00C9    166 _WDCTL	=	0x00c9
                    00CA    167 Fdynamixel$T3CNT$0$0 == 0x00ca
                    00CA    168 _T3CNT	=	0x00ca
                    00CB    169 Fdynamixel$T3CTL$0$0 == 0x00cb
                    00CB    170 _T3CTL	=	0x00cb
                    00CC    171 Fdynamixel$T3CCTL0$0$0 == 0x00cc
                    00CC    172 _T3CCTL0	=	0x00cc
                    00CD    173 Fdynamixel$T3CC0$0$0 == 0x00cd
                    00CD    174 _T3CC0	=	0x00cd
                    00CE    175 Fdynamixel$T3CCTL1$0$0 == 0x00ce
                    00CE    176 _T3CCTL1	=	0x00ce
                    00CF    177 Fdynamixel$T3CC1$0$0 == 0x00cf
                    00CF    178 _T3CC1	=	0x00cf
                    00D0    179 Fdynamixel$PSW$0$0 == 0x00d0
                    00D0    180 _PSW	=	0x00d0
                    00D1    181 Fdynamixel$DMAIRQ$0$0 == 0x00d1
                    00D1    182 _DMAIRQ	=	0x00d1
                    00D2    183 Fdynamixel$DMA1CFGL$0$0 == 0x00d2
                    00D2    184 _DMA1CFGL	=	0x00d2
                    00D3    185 Fdynamixel$DMA1CFGH$0$0 == 0x00d3
                    00D3    186 _DMA1CFGH	=	0x00d3
                    00D4    187 Fdynamixel$DMA0CFGL$0$0 == 0x00d4
                    00D4    188 _DMA0CFGL	=	0x00d4
                    00D5    189 Fdynamixel$DMA0CFGH$0$0 == 0x00d5
                    00D5    190 _DMA0CFGH	=	0x00d5
                    00D6    191 Fdynamixel$DMAARM$0$0 == 0x00d6
                    00D6    192 _DMAARM	=	0x00d6
                    00D7    193 Fdynamixel$DMAREQ$0$0 == 0x00d7
                    00D7    194 _DMAREQ	=	0x00d7
                    00D8    195 Fdynamixel$TIMIF$0$0 == 0x00d8
                    00D8    196 _TIMIF	=	0x00d8
                    00D9    197 Fdynamixel$RFD$0$0 == 0x00d9
                    00D9    198 _RFD	=	0x00d9
                    00DA    199 Fdynamixel$T1CC0L$0$0 == 0x00da
                    00DA    200 _T1CC0L	=	0x00da
                    00DB    201 Fdynamixel$T1CC0H$0$0 == 0x00db
                    00DB    202 _T1CC0H	=	0x00db
                    00DC    203 Fdynamixel$T1CC1L$0$0 == 0x00dc
                    00DC    204 _T1CC1L	=	0x00dc
                    00DD    205 Fdynamixel$T1CC1H$0$0 == 0x00dd
                    00DD    206 _T1CC1H	=	0x00dd
                    00DE    207 Fdynamixel$T1CC2L$0$0 == 0x00de
                    00DE    208 _T1CC2L	=	0x00de
                    00DF    209 Fdynamixel$T1CC2H$0$0 == 0x00df
                    00DF    210 _T1CC2H	=	0x00df
                    00E0    211 Fdynamixel$ACC$0$0 == 0x00e0
                    00E0    212 _ACC	=	0x00e0
                    00E1    213 Fdynamixel$RFST$0$0 == 0x00e1
                    00E1    214 _RFST	=	0x00e1
                    00E2    215 Fdynamixel$T1CNTL$0$0 == 0x00e2
                    00E2    216 _T1CNTL	=	0x00e2
                    00E3    217 Fdynamixel$T1CNTH$0$0 == 0x00e3
                    00E3    218 _T1CNTH	=	0x00e3
                    00E4    219 Fdynamixel$T1CTL$0$0 == 0x00e4
                    00E4    220 _T1CTL	=	0x00e4
                    00E5    221 Fdynamixel$T1CCTL0$0$0 == 0x00e5
                    00E5    222 _T1CCTL0	=	0x00e5
                    00E6    223 Fdynamixel$T1CCTL1$0$0 == 0x00e6
                    00E6    224 _T1CCTL1	=	0x00e6
                    00E7    225 Fdynamixel$T1CCTL2$0$0 == 0x00e7
                    00E7    226 _T1CCTL2	=	0x00e7
                    00E8    227 Fdynamixel$IRCON2$0$0 == 0x00e8
                    00E8    228 _IRCON2	=	0x00e8
                    00E9    229 Fdynamixel$RFIF$0$0 == 0x00e9
                    00E9    230 _RFIF	=	0x00e9
                    00EA    231 Fdynamixel$T4CNT$0$0 == 0x00ea
                    00EA    232 _T4CNT	=	0x00ea
                    00EB    233 Fdynamixel$T4CTL$0$0 == 0x00eb
                    00EB    234 _T4CTL	=	0x00eb
                    00EC    235 Fdynamixel$T4CCTL0$0$0 == 0x00ec
                    00EC    236 _T4CCTL0	=	0x00ec
                    00ED    237 Fdynamixel$T4CC0$0$0 == 0x00ed
                    00ED    238 _T4CC0	=	0x00ed
                    00EE    239 Fdynamixel$T4CCTL1$0$0 == 0x00ee
                    00EE    240 _T4CCTL1	=	0x00ee
                    00EF    241 Fdynamixel$T4CC1$0$0 == 0x00ef
                    00EF    242 _T4CC1	=	0x00ef
                    00F0    243 Fdynamixel$B$0$0 == 0x00f0
                    00F0    244 _B	=	0x00f0
                    00F1    245 Fdynamixel$PERCFG$0$0 == 0x00f1
                    00F1    246 _PERCFG	=	0x00f1
                    00F2    247 Fdynamixel$ADCCFG$0$0 == 0x00f2
                    00F2    248 _ADCCFG	=	0x00f2
                    00F3    249 Fdynamixel$P0SEL$0$0 == 0x00f3
                    00F3    250 _P0SEL	=	0x00f3
                    00F4    251 Fdynamixel$P1SEL$0$0 == 0x00f4
                    00F4    252 _P1SEL	=	0x00f4
                    00F5    253 Fdynamixel$P2SEL$0$0 == 0x00f5
                    00F5    254 _P2SEL	=	0x00f5
                    00F6    255 Fdynamixel$P1INP$0$0 == 0x00f6
                    00F6    256 _P1INP	=	0x00f6
                    00F7    257 Fdynamixel$P2INP$0$0 == 0x00f7
                    00F7    258 _P2INP	=	0x00f7
                    00F8    259 Fdynamixel$U1CSR$0$0 == 0x00f8
                    00F8    260 _U1CSR	=	0x00f8
                    00F9    261 Fdynamixel$U1DBUF$0$0 == 0x00f9
                    00F9    262 _U1DBUF	=	0x00f9
                    00FA    263 Fdynamixel$U1BAUD$0$0 == 0x00fa
                    00FA    264 _U1BAUD	=	0x00fa
                    00FB    265 Fdynamixel$U1UCR$0$0 == 0x00fb
                    00FB    266 _U1UCR	=	0x00fb
                    00FC    267 Fdynamixel$U1GCR$0$0 == 0x00fc
                    00FC    268 _U1GCR	=	0x00fc
                    00FD    269 Fdynamixel$P0DIR$0$0 == 0x00fd
                    00FD    270 _P0DIR	=	0x00fd
                    00FE    271 Fdynamixel$P1DIR$0$0 == 0x00fe
                    00FE    272 _P1DIR	=	0x00fe
                    00FF    273 Fdynamixel$P2DIR$0$0 == 0x00ff
                    00FF    274 _P2DIR	=	0x00ff
                    FFFFD5D4    275 Fdynamixel$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    276 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    277 Fdynamixel$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    278 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    279 Fdynamixel$FADDR$0$0 == 0xffffadac
                    FFFFADAC    280 _FADDR	=	0xffffadac
                    FFFFBBBA    281 Fdynamixel$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    282 _ADC	=	0xffffbbba
                    FFFFDBDA    283 Fdynamixel$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    284 _T1CC0	=	0xffffdbda
                    FFFFDDDC    285 Fdynamixel$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    286 _T1CC1	=	0xffffdddc
                    FFFFDFDE    287 Fdynamixel$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    288 _T1CC2	=	0xffffdfde
                            289 ;--------------------------------------------------------
                            290 ; special function bits
                            291 ;--------------------------------------------------------
                            292 	.area RSEG    (ABS,DATA)
   0000                     293 	.org 0x0000
                    0080    294 Fdynamixel$P0_0$0$0 == 0x0080
                    0080    295 _P0_0	=	0x0080
                    0081    296 Fdynamixel$P0_1$0$0 == 0x0081
                    0081    297 _P0_1	=	0x0081
                    0082    298 Fdynamixel$P0_2$0$0 == 0x0082
                    0082    299 _P0_2	=	0x0082
                    0083    300 Fdynamixel$P0_3$0$0 == 0x0083
                    0083    301 _P0_3	=	0x0083
                    0084    302 Fdynamixel$P0_4$0$0 == 0x0084
                    0084    303 _P0_4	=	0x0084
                    0085    304 Fdynamixel$P0_5$0$0 == 0x0085
                    0085    305 _P0_5	=	0x0085
                    0086    306 Fdynamixel$P0_6$0$0 == 0x0086
                    0086    307 _P0_6	=	0x0086
                    0087    308 Fdynamixel$P0_7$0$0 == 0x0087
                    0087    309 _P0_7	=	0x0087
                    0088    310 Fdynamixel$_TCON_0$0$0 == 0x0088
                    0088    311 __TCON_0	=	0x0088
                    0089    312 Fdynamixel$RFTXRXIF$0$0 == 0x0089
                    0089    313 _RFTXRXIF	=	0x0089
                    008A    314 Fdynamixel$_TCON_2$0$0 == 0x008a
                    008A    315 __TCON_2	=	0x008a
                    008B    316 Fdynamixel$URX0IF$0$0 == 0x008b
                    008B    317 _URX0IF	=	0x008b
                    008C    318 Fdynamixel$_TCON_4$0$0 == 0x008c
                    008C    319 __TCON_4	=	0x008c
                    008D    320 Fdynamixel$ADCIF$0$0 == 0x008d
                    008D    321 _ADCIF	=	0x008d
                    008E    322 Fdynamixel$_TCON_6$0$0 == 0x008e
                    008E    323 __TCON_6	=	0x008e
                    008F    324 Fdynamixel$URX1IF$0$0 == 0x008f
                    008F    325 _URX1IF	=	0x008f
                    0090    326 Fdynamixel$P1_0$0$0 == 0x0090
                    0090    327 _P1_0	=	0x0090
                    0091    328 Fdynamixel$P1_1$0$0 == 0x0091
                    0091    329 _P1_1	=	0x0091
                    0092    330 Fdynamixel$P1_2$0$0 == 0x0092
                    0092    331 _P1_2	=	0x0092
                    0093    332 Fdynamixel$P1_3$0$0 == 0x0093
                    0093    333 _P1_3	=	0x0093
                    0094    334 Fdynamixel$P1_4$0$0 == 0x0094
                    0094    335 _P1_4	=	0x0094
                    0095    336 Fdynamixel$P1_5$0$0 == 0x0095
                    0095    337 _P1_5	=	0x0095
                    0096    338 Fdynamixel$P1_6$0$0 == 0x0096
                    0096    339 _P1_6	=	0x0096
                    0097    340 Fdynamixel$P1_7$0$0 == 0x0097
                    0097    341 _P1_7	=	0x0097
                    0098    342 Fdynamixel$ENCIF_0$0$0 == 0x0098
                    0098    343 _ENCIF_0	=	0x0098
                    0099    344 Fdynamixel$ENCIF_1$0$0 == 0x0099
                    0099    345 _ENCIF_1	=	0x0099
                    009A    346 Fdynamixel$_SOCON2$0$0 == 0x009a
                    009A    347 __SOCON2	=	0x009a
                    009B    348 Fdynamixel$_SOCON3$0$0 == 0x009b
                    009B    349 __SOCON3	=	0x009b
                    009C    350 Fdynamixel$_SOCON4$0$0 == 0x009c
                    009C    351 __SOCON4	=	0x009c
                    009D    352 Fdynamixel$_SOCON5$0$0 == 0x009d
                    009D    353 __SOCON5	=	0x009d
                    009E    354 Fdynamixel$_SOCON6$0$0 == 0x009e
                    009E    355 __SOCON6	=	0x009e
                    009F    356 Fdynamixel$_SOCON7$0$0 == 0x009f
                    009F    357 __SOCON7	=	0x009f
                    00A0    358 Fdynamixel$P2_0$0$0 == 0x00a0
                    00A0    359 _P2_0	=	0x00a0
                    00A1    360 Fdynamixel$P2_1$0$0 == 0x00a1
                    00A1    361 _P2_1	=	0x00a1
                    00A2    362 Fdynamixel$P2_2$0$0 == 0x00a2
                    00A2    363 _P2_2	=	0x00a2
                    00A3    364 Fdynamixel$P2_3$0$0 == 0x00a3
                    00A3    365 _P2_3	=	0x00a3
                    00A4    366 Fdynamixel$P2_4$0$0 == 0x00a4
                    00A4    367 _P2_4	=	0x00a4
                    00A5    368 Fdynamixel$P2_5$0$0 == 0x00a5
                    00A5    369 _P2_5	=	0x00a5
                    00A6    370 Fdynamixel$P2_6$0$0 == 0x00a6
                    00A6    371 _P2_6	=	0x00a6
                    00A7    372 Fdynamixel$P2_7$0$0 == 0x00a7
                    00A7    373 _P2_7	=	0x00a7
                    00A8    374 Fdynamixel$RFTXRXIE$0$0 == 0x00a8
                    00A8    375 _RFTXRXIE	=	0x00a8
                    00A9    376 Fdynamixel$ADCIE$0$0 == 0x00a9
                    00A9    377 _ADCIE	=	0x00a9
                    00AA    378 Fdynamixel$URX0IE$0$0 == 0x00aa
                    00AA    379 _URX0IE	=	0x00aa
                    00AB    380 Fdynamixel$URX1IE$0$0 == 0x00ab
                    00AB    381 _URX1IE	=	0x00ab
                    00AC    382 Fdynamixel$ENCIE$0$0 == 0x00ac
                    00AC    383 _ENCIE	=	0x00ac
                    00AD    384 Fdynamixel$STIE$0$0 == 0x00ad
                    00AD    385 _STIE	=	0x00ad
                    00AE    386 Fdynamixel$_IEN06$0$0 == 0x00ae
                    00AE    387 __IEN06	=	0x00ae
                    00AF    388 Fdynamixel$EA$0$0 == 0x00af
                    00AF    389 _EA	=	0x00af
                    00B8    390 Fdynamixel$DMAIE$0$0 == 0x00b8
                    00B8    391 _DMAIE	=	0x00b8
                    00B9    392 Fdynamixel$T1IE$0$0 == 0x00b9
                    00B9    393 _T1IE	=	0x00b9
                    00BA    394 Fdynamixel$T2IE$0$0 == 0x00ba
                    00BA    395 _T2IE	=	0x00ba
                    00BB    396 Fdynamixel$T3IE$0$0 == 0x00bb
                    00BB    397 _T3IE	=	0x00bb
                    00BC    398 Fdynamixel$T4IE$0$0 == 0x00bc
                    00BC    399 _T4IE	=	0x00bc
                    00BD    400 Fdynamixel$P0IE$0$0 == 0x00bd
                    00BD    401 _P0IE	=	0x00bd
                    00BE    402 Fdynamixel$_IEN16$0$0 == 0x00be
                    00BE    403 __IEN16	=	0x00be
                    00BF    404 Fdynamixel$_IEN17$0$0 == 0x00bf
                    00BF    405 __IEN17	=	0x00bf
                    00C0    406 Fdynamixel$DMAIF$0$0 == 0x00c0
                    00C0    407 _DMAIF	=	0x00c0
                    00C1    408 Fdynamixel$T1IF$0$0 == 0x00c1
                    00C1    409 _T1IF	=	0x00c1
                    00C2    410 Fdynamixel$T2IF$0$0 == 0x00c2
                    00C2    411 _T2IF	=	0x00c2
                    00C3    412 Fdynamixel$T3IF$0$0 == 0x00c3
                    00C3    413 _T3IF	=	0x00c3
                    00C4    414 Fdynamixel$T4IF$0$0 == 0x00c4
                    00C4    415 _T4IF	=	0x00c4
                    00C5    416 Fdynamixel$P0IF$0$0 == 0x00c5
                    00C5    417 _P0IF	=	0x00c5
                    00C6    418 Fdynamixel$_IRCON6$0$0 == 0x00c6
                    00C6    419 __IRCON6	=	0x00c6
                    00C7    420 Fdynamixel$STIF$0$0 == 0x00c7
                    00C7    421 _STIF	=	0x00c7
                    00D0    422 Fdynamixel$P$0$0 == 0x00d0
                    00D0    423 _P	=	0x00d0
                    00D1    424 Fdynamixel$F1$0$0 == 0x00d1
                    00D1    425 _F1	=	0x00d1
                    00D2    426 Fdynamixel$OV$0$0 == 0x00d2
                    00D2    427 _OV	=	0x00d2
                    00D3    428 Fdynamixel$RS0$0$0 == 0x00d3
                    00D3    429 _RS0	=	0x00d3
                    00D4    430 Fdynamixel$RS1$0$0 == 0x00d4
                    00D4    431 _RS1	=	0x00d4
                    00D5    432 Fdynamixel$F0$0$0 == 0x00d5
                    00D5    433 _F0	=	0x00d5
                    00D6    434 Fdynamixel$AC$0$0 == 0x00d6
                    00D6    435 _AC	=	0x00d6
                    00D7    436 Fdynamixel$CY$0$0 == 0x00d7
                    00D7    437 _CY	=	0x00d7
                    00D8    438 Fdynamixel$T3OVFIF$0$0 == 0x00d8
                    00D8    439 _T3OVFIF	=	0x00d8
                    00D9    440 Fdynamixel$T3CH0IF$0$0 == 0x00d9
                    00D9    441 _T3CH0IF	=	0x00d9
                    00DA    442 Fdynamixel$T3CH1IF$0$0 == 0x00da
                    00DA    443 _T3CH1IF	=	0x00da
                    00DB    444 Fdynamixel$T4OVFIF$0$0 == 0x00db
                    00DB    445 _T4OVFIF	=	0x00db
                    00DC    446 Fdynamixel$T4CH0IF$0$0 == 0x00dc
                    00DC    447 _T4CH0IF	=	0x00dc
                    00DD    448 Fdynamixel$T4CH1IF$0$0 == 0x00dd
                    00DD    449 _T4CH1IF	=	0x00dd
                    00DE    450 Fdynamixel$OVFIM$0$0 == 0x00de
                    00DE    451 _OVFIM	=	0x00de
                    00DF    452 Fdynamixel$_TIMIF7$0$0 == 0x00df
                    00DF    453 __TIMIF7	=	0x00df
                    00E0    454 Fdynamixel$ACC_0$0$0 == 0x00e0
                    00E0    455 _ACC_0	=	0x00e0
                    00E1    456 Fdynamixel$ACC_1$0$0 == 0x00e1
                    00E1    457 _ACC_1	=	0x00e1
                    00E2    458 Fdynamixel$ACC_2$0$0 == 0x00e2
                    00E2    459 _ACC_2	=	0x00e2
                    00E3    460 Fdynamixel$ACC_3$0$0 == 0x00e3
                    00E3    461 _ACC_3	=	0x00e3
                    00E4    462 Fdynamixel$ACC_4$0$0 == 0x00e4
                    00E4    463 _ACC_4	=	0x00e4
                    00E5    464 Fdynamixel$ACC_5$0$0 == 0x00e5
                    00E5    465 _ACC_5	=	0x00e5
                    00E6    466 Fdynamixel$ACC_6$0$0 == 0x00e6
                    00E6    467 _ACC_6	=	0x00e6
                    00E7    468 Fdynamixel$ACC_7$0$0 == 0x00e7
                    00E7    469 _ACC_7	=	0x00e7
                    00E8    470 Fdynamixel$P2IF$0$0 == 0x00e8
                    00E8    471 _P2IF	=	0x00e8
                    00E9    472 Fdynamixel$UTX0IF$0$0 == 0x00e9
                    00E9    473 _UTX0IF	=	0x00e9
                    00EA    474 Fdynamixel$UTX1IF$0$0 == 0x00ea
                    00EA    475 _UTX1IF	=	0x00ea
                    00EB    476 Fdynamixel$P1IF$0$0 == 0x00eb
                    00EB    477 _P1IF	=	0x00eb
                    00EC    478 Fdynamixel$WDTIF$0$0 == 0x00ec
                    00EC    479 _WDTIF	=	0x00ec
                    00ED    480 Fdynamixel$_IRCON25$0$0 == 0x00ed
                    00ED    481 __IRCON25	=	0x00ed
                    00EE    482 Fdynamixel$_IRCON26$0$0 == 0x00ee
                    00EE    483 __IRCON26	=	0x00ee
                    00EF    484 Fdynamixel$_IRCON27$0$0 == 0x00ef
                    00EF    485 __IRCON27	=	0x00ef
                    00F0    486 Fdynamixel$B_0$0$0 == 0x00f0
                    00F0    487 _B_0	=	0x00f0
                    00F1    488 Fdynamixel$B_1$0$0 == 0x00f1
                    00F1    489 _B_1	=	0x00f1
                    00F2    490 Fdynamixel$B_2$0$0 == 0x00f2
                    00F2    491 _B_2	=	0x00f2
                    00F3    492 Fdynamixel$B_3$0$0 == 0x00f3
                    00F3    493 _B_3	=	0x00f3
                    00F4    494 Fdynamixel$B_4$0$0 == 0x00f4
                    00F4    495 _B_4	=	0x00f4
                    00F5    496 Fdynamixel$B_5$0$0 == 0x00f5
                    00F5    497 _B_5	=	0x00f5
                    00F6    498 Fdynamixel$B_6$0$0 == 0x00f6
                    00F6    499 _B_6	=	0x00f6
                    00F7    500 Fdynamixel$B_7$0$0 == 0x00f7
                    00F7    501 _B_7	=	0x00f7
                    00F8    502 Fdynamixel$U1ACTIVE$0$0 == 0x00f8
                    00F8    503 _U1ACTIVE	=	0x00f8
                    00F9    504 Fdynamixel$U1TX_BYTE$0$0 == 0x00f9
                    00F9    505 _U1TX_BYTE	=	0x00f9
                    00FA    506 Fdynamixel$U1RX_BYTE$0$0 == 0x00fa
                    00FA    507 _U1RX_BYTE	=	0x00fa
                    00FB    508 Fdynamixel$U1ERR$0$0 == 0x00fb
                    00FB    509 _U1ERR	=	0x00fb
                    00FC    510 Fdynamixel$U1FE$0$0 == 0x00fc
                    00FC    511 _U1FE	=	0x00fc
                    00FD    512 Fdynamixel$U1SLAVE$0$0 == 0x00fd
                    00FD    513 _U1SLAVE	=	0x00fd
                    00FE    514 Fdynamixel$U1RE$0$0 == 0x00fe
                    00FE    515 _U1RE	=	0x00fe
                    00FF    516 Fdynamixel$U1MODE$0$0 == 0x00ff
                    00FF    517 _U1MODE	=	0x00ff
                            518 ;--------------------------------------------------------
                            519 ; overlayable register banks
                            520 ;--------------------------------------------------------
                            521 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     522 	.ds 8
                            523 ;--------------------------------------------------------
                            524 ; internal ram data
                            525 ;--------------------------------------------------------
                            526 	.area DSEG    (DATA)
                    0000    527 Ldynamixel.dynamixel_txrx$sloc0$1$0==.
   0008                     528 _dynamixel_txrx_sloc0_1_0:
   0008                     529 	.ds 3
                            530 ;--------------------------------------------------------
                            531 ; overlayable items in internal ram 
                            532 ;--------------------------------------------------------
                            533 	.area	OSEG    (OVR,DATA)
                    0000    534 Ldynamixel.dynamixel_calculatechecksum$sloc0$1$0==.
   0074                     535 _dynamixel_calculatechecksum_sloc0_1_0:
   0074                     536 	.ds 2
                            537 ;--------------------------------------------------------
                            538 ; indirectly addressable internal ram data
                            539 ;--------------------------------------------------------
                            540 	.area ISEG    (DATA)
                            541 ;--------------------------------------------------------
                            542 ; absolute internal ram data
                            543 ;--------------------------------------------------------
                            544 	.area IABS    (ABS,DATA)
                            545 	.area IABS    (ABS,DATA)
                            546 ;--------------------------------------------------------
                            547 ; bit data
                            548 ;--------------------------------------------------------
                            549 	.area BSEG    (BIT)
                            550 ;--------------------------------------------------------
                            551 ; paged external ram data
                            552 ;--------------------------------------------------------
                            553 	.area PSEG    (PAG,XDATA)
                    0000    554 G$dynamixel_txpacket$0$0==.
   F000                     555 _dynamixel_txpacket::
   F000                     556 	.ds 3
                    0003    557 G$dynamixel_rxpacket$0$0==.
   F003                     558 _dynamixel_rxpacket::
   F003                     559 	.ds 3
                    0006    560 G$dynamixel_rxindex$0$0==.
   F006                     561 _dynamixel_rxindex::
   F006                     562 	.ds 1
                    0007    563 Ldynamixel.dynamixel_calculatechecksum$packet$1$1==.
   F007                     564 _dynamixel_calculatechecksum_packet_1_1:
   F007                     565 	.ds 3
                    000A    566 Ldynamixel.dynamixel_calculatechecksum$i$1$1==.
   F00A                     567 _dynamixel_calculatechecksum_i_1_1:
   F00A                     568 	.ds 1
                    000B    569 Ldynamixel.dynamixel_writepacket$packetlength$1$1==.
   F00B                     570 _dynamixel_writepacket_PARM_2:
   F00B                     571 	.ds 1
                    000C    572 Ldynamixel.dynamixel_writepacket$txpacket$1$1==.
   F00C                     573 _dynamixel_writepacket_txpacket_1_1:
   F00C                     574 	.ds 3
                    000F    575 Ldynamixel.dynamixel_readpacket$packetlength$1$1==.
   F00F                     576 _dynamixel_readpacket_PARM_2:
   F00F                     577 	.ds 1
                    0010    578 Ldynamixel.dynamixel_readpacket$rxpacket$1$1==.
   F010                     579 _dynamixel_readpacket_rxpacket_1_1:
   F010                     580 	.ds 3
                    0013    581 Ldynamixel.dynamixel_txrx$rxpacket$1$1==.
   F013                     582 _dynamixel_txrx_PARM_2:
   F013                     583 	.ds 3
                    0016    584 Ldynamixel.dynamixel_txrx$txpacket$1$1==.
   F016                     585 _dynamixel_txrx_txpacket_1_1:
   F016                     586 	.ds 3
                    0019    587 Ldynamixel.dynamixel_txrx$txlength$1$1==.
   F019                     588 _dynamixel_txrx_txlength_1_1:
   F019                     589 	.ds 1
                    001A    590 Ldynamixel.dynamixel_writebyte$address$1$1==.
   F01A                     591 _dynamixel_writebyte_PARM_2:
   F01A                     592 	.ds 1
                    001B    593 Ldynamixel.dynamixel_writebyte$value$1$1==.
   F01B                     594 _dynamixel_writebyte_PARM_3:
   F01B                     595 	.ds 1
                    001C    596 Ldynamixel.dynamixel_syncwrite$length$1$1==.
   F01C                     597 _dynamixel_syncwrite_PARM_2:
   F01C                     598 	.ds 1
                    001D    599 Ldynamixel.dynamixel_syncwrite$number$1$1==.
   F01D                     600 _dynamixel_syncwrite_PARM_3:
   F01D                     601 	.ds 1
                    001E    602 Ldynamixel.dynamixel_syncwrite$param$1$1==.
   F01E                     603 _dynamixel_syncwrite_PARM_4:
   F01E                     604 	.ds 3
                    0021    605 Ldynamixel.dynamixel_syncwrite$i$1$1==.
   F021                     606 _dynamixel_syncwrite_i_1_1:
   F021                     607 	.ds 1
                    0022    608 Ldynamixel.dynamixel_makeword$highbyte$1$1==.
   F022                     609 _dynamixel_makeword_PARM_2:
   F022                     610 	.ds 1
                            611 ;--------------------------------------------------------
                            612 ; external ram data
                            613 ;--------------------------------------------------------
                            614 	.area XSEG    (XDATA)
                    DF00    615 Fdynamixel$SYNC1$0$0 == 0xdf00
                    DF00    616 _SYNC1	=	0xdf00
                    DF01    617 Fdynamixel$SYNC0$0$0 == 0xdf01
                    DF01    618 _SYNC0	=	0xdf01
                    DF02    619 Fdynamixel$PKTLEN$0$0 == 0xdf02
                    DF02    620 _PKTLEN	=	0xdf02
                    DF03    621 Fdynamixel$PKTCTRL1$0$0 == 0xdf03
                    DF03    622 _PKTCTRL1	=	0xdf03
                    DF04    623 Fdynamixel$PKTCTRL0$0$0 == 0xdf04
                    DF04    624 _PKTCTRL0	=	0xdf04
                    DF05    625 Fdynamixel$ADDR$0$0 == 0xdf05
                    DF05    626 _ADDR	=	0xdf05
                    DF06    627 Fdynamixel$CHANNR$0$0 == 0xdf06
                    DF06    628 _CHANNR	=	0xdf06
                    DF07    629 Fdynamixel$FSCTRL1$0$0 == 0xdf07
                    DF07    630 _FSCTRL1	=	0xdf07
                    DF08    631 Fdynamixel$FSCTRL0$0$0 == 0xdf08
                    DF08    632 _FSCTRL0	=	0xdf08
                    DF09    633 Fdynamixel$FREQ2$0$0 == 0xdf09
                    DF09    634 _FREQ2	=	0xdf09
                    DF0A    635 Fdynamixel$FREQ1$0$0 == 0xdf0a
                    DF0A    636 _FREQ1	=	0xdf0a
                    DF0B    637 Fdynamixel$FREQ0$0$0 == 0xdf0b
                    DF0B    638 _FREQ0	=	0xdf0b
                    DF0C    639 Fdynamixel$MDMCFG4$0$0 == 0xdf0c
                    DF0C    640 _MDMCFG4	=	0xdf0c
                    DF0D    641 Fdynamixel$MDMCFG3$0$0 == 0xdf0d
                    DF0D    642 _MDMCFG3	=	0xdf0d
                    DF0E    643 Fdynamixel$MDMCFG2$0$0 == 0xdf0e
                    DF0E    644 _MDMCFG2	=	0xdf0e
                    DF0F    645 Fdynamixel$MDMCFG1$0$0 == 0xdf0f
                    DF0F    646 _MDMCFG1	=	0xdf0f
                    DF10    647 Fdynamixel$MDMCFG0$0$0 == 0xdf10
                    DF10    648 _MDMCFG0	=	0xdf10
                    DF11    649 Fdynamixel$DEVIATN$0$0 == 0xdf11
                    DF11    650 _DEVIATN	=	0xdf11
                    DF12    651 Fdynamixel$MCSM2$0$0 == 0xdf12
                    DF12    652 _MCSM2	=	0xdf12
                    DF13    653 Fdynamixel$MCSM1$0$0 == 0xdf13
                    DF13    654 _MCSM1	=	0xdf13
                    DF14    655 Fdynamixel$MCSM0$0$0 == 0xdf14
                    DF14    656 _MCSM0	=	0xdf14
                    DF15    657 Fdynamixel$FOCCFG$0$0 == 0xdf15
                    DF15    658 _FOCCFG	=	0xdf15
                    DF16    659 Fdynamixel$BSCFG$0$0 == 0xdf16
                    DF16    660 _BSCFG	=	0xdf16
                    DF17    661 Fdynamixel$AGCCTRL2$0$0 == 0xdf17
                    DF17    662 _AGCCTRL2	=	0xdf17
                    DF18    663 Fdynamixel$AGCCTRL1$0$0 == 0xdf18
                    DF18    664 _AGCCTRL1	=	0xdf18
                    DF19    665 Fdynamixel$AGCCTRL0$0$0 == 0xdf19
                    DF19    666 _AGCCTRL0	=	0xdf19
                    DF1A    667 Fdynamixel$FREND1$0$0 == 0xdf1a
                    DF1A    668 _FREND1	=	0xdf1a
                    DF1B    669 Fdynamixel$FREND0$0$0 == 0xdf1b
                    DF1B    670 _FREND0	=	0xdf1b
                    DF1C    671 Fdynamixel$FSCAL3$0$0 == 0xdf1c
                    DF1C    672 _FSCAL3	=	0xdf1c
                    DF1D    673 Fdynamixel$FSCAL2$0$0 == 0xdf1d
                    DF1D    674 _FSCAL2	=	0xdf1d
                    DF1E    675 Fdynamixel$FSCAL1$0$0 == 0xdf1e
                    DF1E    676 _FSCAL1	=	0xdf1e
                    DF1F    677 Fdynamixel$FSCAL0$0$0 == 0xdf1f
                    DF1F    678 _FSCAL0	=	0xdf1f
                    DF23    679 Fdynamixel$TEST2$0$0 == 0xdf23
                    DF23    680 _TEST2	=	0xdf23
                    DF24    681 Fdynamixel$TEST1$0$0 == 0xdf24
                    DF24    682 _TEST1	=	0xdf24
                    DF25    683 Fdynamixel$TEST0$0$0 == 0xdf25
                    DF25    684 _TEST0	=	0xdf25
                    DF2E    685 Fdynamixel$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    686 _PA_TABLE0	=	0xdf2e
                    DF2F    687 Fdynamixel$IOCFG2$0$0 == 0xdf2f
                    DF2F    688 _IOCFG2	=	0xdf2f
                    DF30    689 Fdynamixel$IOCFG1$0$0 == 0xdf30
                    DF30    690 _IOCFG1	=	0xdf30
                    DF31    691 Fdynamixel$IOCFG0$0$0 == 0xdf31
                    DF31    692 _IOCFG0	=	0xdf31
                    DF36    693 Fdynamixel$PARTNUM$0$0 == 0xdf36
                    DF36    694 _PARTNUM	=	0xdf36
                    DF37    695 Fdynamixel$VERSION$0$0 == 0xdf37
                    DF37    696 _VERSION	=	0xdf37
                    DF38    697 Fdynamixel$FREQEST$0$0 == 0xdf38
                    DF38    698 _FREQEST	=	0xdf38
                    DF39    699 Fdynamixel$LQI$0$0 == 0xdf39
                    DF39    700 _LQI	=	0xdf39
                    DF3A    701 Fdynamixel$RSSI$0$0 == 0xdf3a
                    DF3A    702 _RSSI	=	0xdf3a
                    DF3B    703 Fdynamixel$MARCSTATE$0$0 == 0xdf3b
                    DF3B    704 _MARCSTATE	=	0xdf3b
                    DF3C    705 Fdynamixel$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    706 _PKTSTATUS	=	0xdf3c
                    DF3D    707 Fdynamixel$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    708 _VCO_VC_DAC	=	0xdf3d
                    DF40    709 Fdynamixel$I2SCFG0$0$0 == 0xdf40
                    DF40    710 _I2SCFG0	=	0xdf40
                    DF41    711 Fdynamixel$I2SCFG1$0$0 == 0xdf41
                    DF41    712 _I2SCFG1	=	0xdf41
                    DF42    713 Fdynamixel$I2SDATL$0$0 == 0xdf42
                    DF42    714 _I2SDATL	=	0xdf42
                    DF43    715 Fdynamixel$I2SDATH$0$0 == 0xdf43
                    DF43    716 _I2SDATH	=	0xdf43
                    DF44    717 Fdynamixel$I2SWCNT$0$0 == 0xdf44
                    DF44    718 _I2SWCNT	=	0xdf44
                    DF45    719 Fdynamixel$I2SSTAT$0$0 == 0xdf45
                    DF45    720 _I2SSTAT	=	0xdf45
                    DF46    721 Fdynamixel$I2SCLKF0$0$0 == 0xdf46
                    DF46    722 _I2SCLKF0	=	0xdf46
                    DF47    723 Fdynamixel$I2SCLKF1$0$0 == 0xdf47
                    DF47    724 _I2SCLKF1	=	0xdf47
                    DF48    725 Fdynamixel$I2SCLKF2$0$0 == 0xdf48
                    DF48    726 _I2SCLKF2	=	0xdf48
                    DE00    727 Fdynamixel$USBADDR$0$0 == 0xde00
                    DE00    728 _USBADDR	=	0xde00
                    DE01    729 Fdynamixel$USBPOW$0$0 == 0xde01
                    DE01    730 _USBPOW	=	0xde01
                    DE02    731 Fdynamixel$USBIIF$0$0 == 0xde02
                    DE02    732 _USBIIF	=	0xde02
                    DE04    733 Fdynamixel$USBOIF$0$0 == 0xde04
                    DE04    734 _USBOIF	=	0xde04
                    DE06    735 Fdynamixel$USBCIF$0$0 == 0xde06
                    DE06    736 _USBCIF	=	0xde06
                    DE07    737 Fdynamixel$USBIIE$0$0 == 0xde07
                    DE07    738 _USBIIE	=	0xde07
                    DE09    739 Fdynamixel$USBOIE$0$0 == 0xde09
                    DE09    740 _USBOIE	=	0xde09
                    DE0B    741 Fdynamixel$USBCIE$0$0 == 0xde0b
                    DE0B    742 _USBCIE	=	0xde0b
                    DE0C    743 Fdynamixel$USBFRML$0$0 == 0xde0c
                    DE0C    744 _USBFRML	=	0xde0c
                    DE0D    745 Fdynamixel$USBFRMH$0$0 == 0xde0d
                    DE0D    746 _USBFRMH	=	0xde0d
                    DE0E    747 Fdynamixel$USBINDEX$0$0 == 0xde0e
                    DE0E    748 _USBINDEX	=	0xde0e
                    DE10    749 Fdynamixel$USBMAXI$0$0 == 0xde10
                    DE10    750 _USBMAXI	=	0xde10
                    DE11    751 Fdynamixel$USBCSIL$0$0 == 0xde11
                    DE11    752 _USBCSIL	=	0xde11
                    DE12    753 Fdynamixel$USBCSIH$0$0 == 0xde12
                    DE12    754 _USBCSIH	=	0xde12
                    DE13    755 Fdynamixel$USBMAXO$0$0 == 0xde13
                    DE13    756 _USBMAXO	=	0xde13
                    DE14    757 Fdynamixel$USBCSOL$0$0 == 0xde14
                    DE14    758 _USBCSOL	=	0xde14
                    DE15    759 Fdynamixel$USBCSOH$0$0 == 0xde15
                    DE15    760 _USBCSOH	=	0xde15
                    DE16    761 Fdynamixel$USBCNTL$0$0 == 0xde16
                    DE16    762 _USBCNTL	=	0xde16
                    DE17    763 Fdynamixel$USBCNTH$0$0 == 0xde17
                    DE17    764 _USBCNTH	=	0xde17
                    DE20    765 Fdynamixel$USBF0$0$0 == 0xde20
                    DE20    766 _USBF0	=	0xde20
                    DE22    767 Fdynamixel$USBF1$0$0 == 0xde22
                    DE22    768 _USBF1	=	0xde22
                    DE24    769 Fdynamixel$USBF2$0$0 == 0xde24
                    DE24    770 _USBF2	=	0xde24
                    DE26    771 Fdynamixel$USBF3$0$0 == 0xde26
                    DE26    772 _USBF3	=	0xde26
                    DE28    773 Fdynamixel$USBF4$0$0 == 0xde28
                    DE28    774 _USBF4	=	0xde28
                    DE2A    775 Fdynamixel$USBF5$0$0 == 0xde2a
                    DE2A    776 _USBF5	=	0xde2a
                            777 ;--------------------------------------------------------
                            778 ; absolute external ram data
                            779 ;--------------------------------------------------------
                            780 	.area XABS    (ABS,XDATA)
                            781 ;--------------------------------------------------------
                            782 ; external initialized ram data
                            783 ;--------------------------------------------------------
                            784 	.area XISEG   (XDATA)
                            785 	.area HOME    (CODE)
                            786 	.area GSINIT0 (CODE)
                            787 	.area GSINIT1 (CODE)
                            788 	.area GSINIT2 (CODE)
                            789 	.area GSINIT3 (CODE)
                            790 	.area GSINIT4 (CODE)
                            791 	.area GSINIT5 (CODE)
                            792 	.area GSINIT  (CODE)
                            793 	.area GSFINAL (CODE)
                            794 	.area CSEG    (CODE)
                            795 ;--------------------------------------------------------
                            796 ; global & static initialisations
                            797 ;--------------------------------------------------------
                            798 	.area HOME    (CODE)
                            799 	.area GSINIT  (CODE)
                            800 	.area GSFINAL (CODE)
                            801 	.area GSINIT  (CODE)
                    0000    802 	G$dynamixel_gethighbyte$0$0 ==.
                    0000    803 	C$dynamixel.c$14$1$1 ==.
                            804 ;	apps/twitch_mx_servos/dynamixel.c:14: volatile uint8 dynamixel_rxindex = 0;
   04E4 78 06               805 	mov	r0,#_dynamixel_rxindex
   04E6 E4                  806 	clr	a
   04E7 F2                  807 	movx	@r0,a
                            808 ;--------------------------------------------------------
                            809 ; Home
                            810 ;--------------------------------------------------------
                            811 	.area HOME    (CODE)
                            812 	.area HOME    (CODE)
                            813 ;--------------------------------------------------------
                            814 ; code
                            815 ;--------------------------------------------------------
                            816 	.area CSEG    (CODE)
                            817 ;------------------------------------------------------------
                            818 ;Allocation info for local variables in function 'dynamixel_init'
                            819 ;------------------------------------------------------------
                    0000    820 	G$dynamixel_init$0$0 ==.
                    0000    821 	C$dynamixel.c$30$0$0 ==.
                            822 ;	apps/twitch_mx_servos/dynamixel.c:30: void dynamixel_init(void)
                            823 ;	-----------------------------------------
                            824 ;	 function dynamixel_init
                            825 ;	-----------------------------------------
   0555                     826 _dynamixel_init:
                    0007    827 	ar7 = 0x07
                    0006    828 	ar6 = 0x06
                    0005    829 	ar5 = 0x05
                    0004    830 	ar4 = 0x04
                    0003    831 	ar3 = 0x03
                    0002    832 	ar2 = 0x02
                    0001    833 	ar1 = 0x01
                    0000    834 	ar0 = 0x00
                    0000    835 	C$dynamixel.c$48$1$1 ==.
                            836 ;	apps/twitch_mx_servos/dynamixel.c:48: dynamixel_rxindex = 0;
   0555 78 06               837 	mov	r0,#_dynamixel_rxindex
   0557 E4                  838 	clr	a
   0558 F2                  839 	movx	@r0,a
                    0004    840 	C$dynamixel.c$51$1$1 ==.
                            841 ;	apps/twitch_mx_servos/dynamixel.c:51: dynamixel_txpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   0559 90 00 80            842 	mov	dptr,#0x0080
   055C 12 36 D7            843 	lcall	_malloc
   055F AE 82               844 	mov	r6,dpl
   0561 AF 83               845 	mov	r7,dph
   0563 78 00               846 	mov	r0,#_dynamixel_txpacket
   0565 EE                  847 	mov	a,r6
   0566 F2                  848 	movx	@r0,a
   0567 08                  849 	inc	r0
   0568 EF                  850 	mov	a,r7
   0569 F2                  851 	movx	@r0,a
   056A 08                  852 	inc	r0
   056B E4                  853 	clr	a
   056C F2                  854 	movx	@r0,a
                    0018    855 	C$dynamixel.c$52$1$1 ==.
                            856 ;	apps/twitch_mx_servos/dynamixel.c:52: dynamixel_rxpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   056D 90 00 80            857 	mov	dptr,#0x0080
   0570 12 36 D7            858 	lcall	_malloc
   0573 AE 82               859 	mov	r6,dpl
   0575 AF 83               860 	mov	r7,dph
   0577 78 03               861 	mov	r0,#_dynamixel_rxpacket
   0579 EE                  862 	mov	a,r6
   057A F2                  863 	movx	@r0,a
   057B 08                  864 	inc	r0
   057C EF                  865 	mov	a,r7
   057D F2                  866 	movx	@r0,a
   057E 08                  867 	inc	r0
   057F E4                  868 	clr	a
   0580 F2                  869 	movx	@r0,a
                    002C    870 	C$dynamixel.c$54$1$1 ==.
                    002C    871 	XG$dynamixel_init$0$0 ==.
   0581 22                  872 	ret
                            873 ;------------------------------------------------------------
                            874 ;Allocation info for local variables in function 'dynamixel_settx'
                            875 ;------------------------------------------------------------
                    002D    876 	G$dynamixel_settx$0$0 ==.
                    002D    877 	C$dynamixel.c$56$1$1 ==.
                            878 ;	apps/twitch_mx_servos/dynamixel.c:56: void dynamixel_settx(void)
                            879 ;	-----------------------------------------
                            880 ;	 function dynamixel_settx
                            881 ;	-----------------------------------------
   0582                     882 _dynamixel_settx:
                    002D    883 	C$dynamixel.c$62$1$1 ==.
                            884 ;	apps/twitch_mx_servos/dynamixel.c:62: delayMicroseconds(10);
   0582 75 82 0A            885 	mov	dpl,#0x0A
   0585 12 36 7E            886 	lcall	_delayMicroseconds
                    0033    887 	C$dynamixel.c$63$1$1 ==.
                            888 ;	apps/twitch_mx_servos/dynamixel.c:63: P1DIR &= ~0x02; //Disable pin P1_1
   0588 AF FE               889 	mov	r7,_P1DIR
   058A 53 07 FD            890 	anl	ar7,#0xFD
   058D 8F FE               891 	mov	_P1DIR,r7
                    003A    892 	C$dynamixel.c$64$1$1 ==.
                            893 ;	apps/twitch_mx_servos/dynamixel.c:64: P1DIR |= 0x20; //Enable pin P1_5
   058F 43 FE 20            894 	orl	_P1DIR,#0x20
                    003D    895 	C$dynamixel.c$70$1$1 ==.
                    003D    896 	XG$dynamixel_settx$0$0 ==.
   0592 22                  897 	ret
                            898 ;------------------------------------------------------------
                            899 ;Allocation info for local variables in function 'dynamixel_setrx'
                            900 ;------------------------------------------------------------
                    003E    901 	G$dynamixel_setrx$0$0 ==.
                    003E    902 	C$dynamixel.c$72$1$1 ==.
                            903 ;	apps/twitch_mx_servos/dynamixel.c:72: void dynamixel_setrx(void)
                            904 ;	-----------------------------------------
                            905 ;	 function dynamixel_setrx
                            906 ;	-----------------------------------------
   0593                     907 _dynamixel_setrx:
                    003E    908 	C$dynamixel.c$80$1$1 ==.
                            909 ;	apps/twitch_mx_servos/dynamixel.c:80: delayMicroseconds(10);
   0593 75 82 0A            910 	mov	dpl,#0x0A
   0596 12 36 7E            911 	lcall	_delayMicroseconds
                    0044    912 	C$dynamixel.c$90$1$1 ==.
                            913 ;	apps/twitch_mx_servos/dynamixel.c:90: P1DIR &= ~0x20; //Disable pin P1_5
   0599 AF FE               914 	mov	r7,_P1DIR
   059B 53 07 DF            915 	anl	ar7,#0xDF
   059E 8F FE               916 	mov	_P1DIR,r7
                    004B    917 	C$dynamixel.c$91$1$1 ==.
                            918 ;	apps/twitch_mx_servos/dynamixel.c:91: P1DIR |= 0x02; //Enable pin P1_1
   05A0 43 FE 02            919 	orl	_P1DIR,#0x02
                    004E    920 	C$dynamixel.c$99$1$1 ==.
                            921 ;	apps/twitch_mx_servos/dynamixel.c:99: dynamixel_rxindex = 0;
   05A3 78 06               922 	mov	r0,#_dynamixel_rxindex
   05A5 E4                  923 	clr	a
   05A6 F2                  924 	movx	@r0,a
                    0052    925 	C$dynamixel.c$100$1$1 ==.
                    0052    926 	XG$dynamixel_setrx$0$0 ==.
   05A7 22                  927 	ret
                            928 ;------------------------------------------------------------
                            929 ;Allocation info for local variables in function 'dynamixel_write'
                            930 ;------------------------------------------------------------
                    0053    931 	G$dynamixel_write$0$0 ==.
                    0053    932 	C$dynamixel.c$102$1$1 ==.
                            933 ;	apps/twitch_mx_servos/dynamixel.c:102: void dynamixel_write(uint8 c)
                            934 ;	-----------------------------------------
                            935 ;	 function dynamixel_write
                            936 ;	-----------------------------------------
   05A8                     937 _dynamixel_write:
                    0053    938 	C$dynamixel.c$117$1$1 ==.
                            939 ;	apps/twitch_mx_servos/dynamixel.c:117: uart1TxSendByte(c);
   05A8 12 2C 24            940 	lcall	_uart1TxSendByte
                    0056    941 	C$dynamixel.c$118$1$1 ==.
                    0056    942 	XG$dynamixel_write$0$0 ==.
   05AB 22                  943 	ret
                            944 ;------------------------------------------------------------
                            945 ;Allocation info for local variables in function 'dynamixel_calculatechecksum'
                            946 ;------------------------------------------------------------
                            947 ;sloc0                     Allocated with name '_dynamixel_calculatechecksum_sloc0_1_0'
                            948 ;------------------------------------------------------------
                    0057    949 	G$dynamixel_calculatechecksum$0$0 ==.
                    0057    950 	C$dynamixel.c$120$1$1 ==.
                            951 ;	apps/twitch_mx_servos/dynamixel.c:120: uint8 dynamixel_calculatechecksum(volatile uint8* packet)
                            952 ;	-----------------------------------------
                            953 ;	 function dynamixel_calculatechecksum
                            954 ;	-----------------------------------------
   05AC                     955 _dynamixel_calculatechecksum:
   05AC AF F0               956 	mov	r7,b
   05AE AE 83               957 	mov	r6,dph
   05B0 E5 82               958 	mov	a,dpl
   05B2 78 07               959 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   05B4 F2                  960 	movx	@r0,a
   05B5 08                  961 	inc	r0
   05B6 EE                  962 	mov	a,r6
   05B7 F2                  963 	movx	@r0,a
   05B8 08                  964 	inc	r0
   05B9 EF                  965 	mov	a,r7
   05BA F2                  966 	movx	@r0,a
                    0066    967 	C$dynamixel.c$123$1$1 ==.
                            968 ;	apps/twitch_mx_servos/dynamixel.c:123: uint16 checksum = 0;
   05BB 7E 00               969 	mov	r6,#0x00
   05BD 7F 00               970 	mov	r7,#0x00
                    006A    971 	C$dynamixel.c$125$1$1 ==.
                            972 ;	apps/twitch_mx_servos/dynamixel.c:125: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   05BF 78 07               973 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   05C1 E2                  974 	movx	a,@r0
   05C2 24 03               975 	add	a,#0x03
   05C4 FB                  976 	mov	r3,a
   05C5 08                  977 	inc	r0
   05C6 E2                  978 	movx	a,@r0
   05C7 34 00               979 	addc	a,#0x00
   05C9 FC                  980 	mov	r4,a
   05CA 08                  981 	inc	r0
   05CB E2                  982 	movx	a,@r0
   05CC FD                  983 	mov	r5,a
   05CD 78 0A               984 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   05CF 74 02               985 	mov	a,#0x02
   05D1 F2                  986 	movx	@r0,a
   05D2                     987 00101$:
   05D2 C0 06               988 	push	ar6
   05D4 C0 07               989 	push	ar7
   05D6 8B 82               990 	mov	dpl,r3
   05D8 8C 83               991 	mov	dph,r4
   05DA 8D F0               992 	mov	b,r5
   05DC 12 42 C6            993 	lcall	__gptrget
   05DF FF                  994 	mov	r7,a
   05E0 7E 00               995 	mov	r6,#0x00
   05E2 74 02               996 	mov	a,#0x02
   05E4 2F                  997 	add	a,r7
   05E5 F5 74               998 	mov	_dynamixel_calculatechecksum_sloc0_1_0,a
   05E7 E4                  999 	clr	a
   05E8 3E                 1000 	addc	a,r6
   05E9 F5 75              1001 	mov	(_dynamixel_calculatechecksum_sloc0_1_0 + 1),a
   05EB 78 0A              1002 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   05ED E2                 1003 	movx	a,@r0
   05EE FA                 1004 	mov	r2,a
   05EF 7F 00              1005 	mov	r7,#0x00
   05F1 C3                 1006 	clr	c
   05F2 E5 74              1007 	mov	a,_dynamixel_calculatechecksum_sloc0_1_0
   05F4 9A                 1008 	subb	a,r2
   05F5 E5 75              1009 	mov	a,(_dynamixel_calculatechecksum_sloc0_1_0 + 1)
   05F7 64 80              1010 	xrl	a,#0x80
   05F9 8F F0              1011 	mov	b,r7
   05FB 63 F0 80           1012 	xrl	b,#0x80
   05FE 95 F0              1013 	subb	a,b
   0600 D0 07              1014 	pop	ar7
   0602 D0 06              1015 	pop	ar6
   0604 40 38              1016 	jc	00104$
                    00B1   1017 	C$dynamixel.c$126$1$1 ==.
                           1018 ;	apps/twitch_mx_servos/dynamixel.c:126: checksum += packet[i];
   0606 C0 03              1019 	push	ar3
   0608 C0 04              1020 	push	ar4
   060A C0 05              1021 	push	ar5
   060C 78 07              1022 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   060E 79 0A              1023 	mov	r1,#_dynamixel_calculatechecksum_i_1_1
   0610 E3                 1024 	movx	a,@r1
   0611 C5 F0              1025 	xch	a,b
   0613 E2                 1026 	movx	a,@r0
   0614 25 F0              1027 	add	a,b
   0616 FA                 1028 	mov	r2,a
   0617 08                 1029 	inc	r0
   0618 E2                 1030 	movx	a,@r0
   0619 34 00              1031 	addc	a,#0x00
   061B FC                 1032 	mov	r4,a
   061C 08                 1033 	inc	r0
   061D E2                 1034 	movx	a,@r0
   061E FD                 1035 	mov	r5,a
   061F 8A 82              1036 	mov	dpl,r2
   0621 8C 83              1037 	mov	dph,r4
   0623 8D F0              1038 	mov	b,r5
   0625 12 42 C6           1039 	lcall	__gptrget
   0628 FA                 1040 	mov	r2,a
   0629 7D 00              1041 	mov	r5,#0x00
   062B 2E                 1042 	add	a,r6
   062C FE                 1043 	mov	r6,a
   062D ED                 1044 	mov	a,r5
   062E 3F                 1045 	addc	a,r7
   062F FF                 1046 	mov	r7,a
                    00DB   1047 	C$dynamixel.c$125$1$1 ==.
                           1048 ;	apps/twitch_mx_servos/dynamixel.c:125: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   0630 78 0A              1049 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   0632 E2                 1050 	movx	a,@r0
   0633 24 01              1051 	add	a,#0x01
   0635 F2                 1052 	movx	@r0,a
   0636 D0 05              1053 	pop	ar5
   0638 D0 04              1054 	pop	ar4
   063A D0 03              1055 	pop	ar3
   063C 80 94              1056 	sjmp	00101$
   063E                    1057 00104$:
                    00E9   1058 	C$dynamixel.c$128$1$1 ==.
                           1059 ;	apps/twitch_mx_servos/dynamixel.c:128: return ~(checksum % 256);
   063E EE                 1060 	mov	a,r6
   063F F4                 1061 	cpl	a
   0640 F5 82              1062 	mov	dpl,a
                    00ED   1063 	C$dynamixel.c$129$1$1 ==.
                    00ED   1064 	XG$dynamixel_calculatechecksum$0$0 ==.
   0642 22                 1065 	ret
                           1066 ;------------------------------------------------------------
                           1067 ;Allocation info for local variables in function 'dynamixel_writepacket'
                           1068 ;------------------------------------------------------------
                    00EE   1069 	G$dynamixel_writepacket$0$0 ==.
                    00EE   1070 	C$dynamixel.c$131$1$1 ==.
                           1071 ;	apps/twitch_mx_servos/dynamixel.c:131: uint8 dynamixel_writepacket(volatile uint8* txpacket, uint8 packetlength)
                           1072 ;	-----------------------------------------
                           1073 ;	 function dynamixel_writepacket
                           1074 ;	-----------------------------------------
   0643                    1075 _dynamixel_writepacket:
   0643 AF F0              1076 	mov	r7,b
   0645 AE 83              1077 	mov	r6,dph
   0647 E5 82              1078 	mov	a,dpl
   0649 78 0C              1079 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   064B F2                 1080 	movx	@r0,a
   064C 08                 1081 	inc	r0
   064D EE                 1082 	mov	a,r6
   064E F2                 1083 	movx	@r0,a
   064F 08                 1084 	inc	r0
   0650 EF                 1085 	mov	a,r7
   0651 F2                 1086 	movx	@r0,a
                    00FD   1087 	C$dynamixel.c$134$1$1 ==.
                           1088 ;	apps/twitch_mx_servos/dynamixel.c:134: for(i = 0; i < packetlength; i++)
   0652 7F 00              1089 	mov	r7,#0x00
   0654                    1090 00101$:
   0654 78 0B              1091 	mov	r0,#_dynamixel_writepacket_PARM_2
   0656 C3                 1092 	clr	c
   0657 E2                 1093 	movx	a,@r0
   0658 F5 F0              1094 	mov	b,a
   065A EF                 1095 	mov	a,r7
   065B 95 F0              1096 	subb	a,b
   065D 50 22              1097 	jnc	00104$
                    010A   1098 	C$dynamixel.c$135$1$1 ==.
                           1099 ;	apps/twitch_mx_servos/dynamixel.c:135: dynamixel_write(txpacket[i]);
   065F 78 0C              1100 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   0661 E2                 1101 	movx	a,@r0
   0662 2F                 1102 	add	a,r7
   0663 FC                 1103 	mov	r4,a
   0664 08                 1104 	inc	r0
   0665 E2                 1105 	movx	a,@r0
   0666 34 00              1106 	addc	a,#0x00
   0668 FD                 1107 	mov	r5,a
   0669 08                 1108 	inc	r0
   066A E2                 1109 	movx	a,@r0
   066B FE                 1110 	mov	r6,a
   066C 8C 82              1111 	mov	dpl,r4
   066E 8D 83              1112 	mov	dph,r5
   0670 8E F0              1113 	mov	b,r6
   0672 12 42 C6           1114 	lcall	__gptrget
   0675 F5 82              1115 	mov	dpl,a
   0677 C0 07              1116 	push	ar7
   0679 12 05 A8           1117 	lcall	_dynamixel_write
   067C D0 07              1118 	pop	ar7
                    0129   1119 	C$dynamixel.c$134$1$1 ==.
                           1120 ;	apps/twitch_mx_servos/dynamixel.c:134: for(i = 0; i < packetlength; i++)
   067E 0F                 1121 	inc	r7
   067F 80 D3              1122 	sjmp	00101$
   0681                    1123 00104$:
                    012C   1124 	C$dynamixel.c$137$1$1 ==.
                           1125 ;	apps/twitch_mx_servos/dynamixel.c:137: return DYNAMIXEL_SUCCESS;
   0681 75 82 01           1126 	mov	dpl,#0x01
                    012F   1127 	C$dynamixel.c$138$1$1 ==.
                    012F   1128 	XG$dynamixel_writepacket$0$0 ==.
   0684 22                 1129 	ret
                           1130 ;------------------------------------------------------------
                           1131 ;Allocation info for local variables in function 'dynamixel_readpacket'
                           1132 ;------------------------------------------------------------
                    0130   1133 	G$dynamixel_readpacket$0$0 ==.
                    0130   1134 	C$dynamixel.c$140$1$1 ==.
                           1135 ;	apps/twitch_mx_servos/dynamixel.c:140: uint8 dynamixel_readpacket(volatile uint8* rxpacket, uint8 packetlength)
                           1136 ;	-----------------------------------------
                           1137 ;	 function dynamixel_readpacket
                           1138 ;	-----------------------------------------
   0685                    1139 _dynamixel_readpacket:
   0685 AF F0              1140 	mov	r7,b
   0687 AE 83              1141 	mov	r6,dph
   0689 E5 82              1142 	mov	a,dpl
   068B 78 10              1143 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   068D F2                 1144 	movx	@r0,a
   068E 08                 1145 	inc	r0
   068F EE                 1146 	mov	a,r6
   0690 F2                 1147 	movx	@r0,a
   0691 08                 1148 	inc	r0
   0692 EF                 1149 	mov	a,r7
   0693 F2                 1150 	movx	@r0,a
                    013F   1151 	C$dynamixel.c$144$1$1 ==.
                           1152 ;	apps/twitch_mx_servos/dynamixel.c:144: while(dynamixel_rxindex < packetlength) // wait for a full packet?
   0694 7E 00              1153 	mov	r6,#0x00
   0696 7F 00              1154 	mov	r7,#0x00
   0698                    1155 00103$:
   0698 78 06              1156 	mov	r0,#_dynamixel_rxindex
   069A 79 0F              1157 	mov	r1,#_dynamixel_readpacket_PARM_2
   069C C3                 1158 	clr	c
   069D E3                 1159 	movx	a,@r1
   069E F5 F0              1160 	mov	b,a
   06A0 E2                 1161 	movx	a,@r0
   06A1 95 F0              1162 	subb	a,b
   06A3 50 17              1163 	jnc	00105$
                    0150   1164 	C$dynamixel.c$147$2$2 ==.
                           1165 ;	apps/twitch_mx_servos/dynamixel.c:147: if(ulcounter++ > 10000)
   06A5 8E 04              1166 	mov	ar4,r6
   06A7 8F 05              1167 	mov	ar5,r7
   06A9 0E                 1168 	inc	r6
   06AA BE 00 01           1169 	cjne	r6,#0x00,00119$
   06AD 0F                 1170 	inc	r7
   06AE                    1171 00119$:
   06AE C3                 1172 	clr	c
   06AF 74 10              1173 	mov	a,#0x10
   06B1 9C                 1174 	subb	a,r4
   06B2 74 27              1175 	mov	a,#0x27
   06B4 9D                 1176 	subb	a,r5
   06B5 50 E1              1177 	jnc	00103$
                    0162   1178 	C$dynamixel.c$148$2$2 ==.
                           1179 ;	apps/twitch_mx_servos/dynamixel.c:148: return DYNAMIXEL_RX_TIMEOUT;
   06B7 75 82 03           1180 	mov	dpl,#0x03
   06BA 80 6E              1181 	sjmp	00111$
   06BC                    1182 00105$:
                    0167   1183 	C$dynamixel.c$153$1$1 ==.
                           1184 ;	apps/twitch_mx_servos/dynamixel.c:153: if((rxpacket[0] != 255) || (rxpacket[1] != 255))
   06BC 78 10              1185 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   06BE E2                 1186 	movx	a,@r0
   06BF FD                 1187 	mov	r5,a
   06C0 08                 1188 	inc	r0
   06C1 E2                 1189 	movx	a,@r0
   06C2 FE                 1190 	mov	r6,a
   06C3 08                 1191 	inc	r0
   06C4 E2                 1192 	movx	a,@r0
   06C5 FF                 1193 	mov	r7,a
   06C6 8D 82              1194 	mov	dpl,r5
   06C8 8E 83              1195 	mov	dph,r6
   06CA 8F F0              1196 	mov	b,r7
   06CC 12 42 C6           1197 	lcall	__gptrget
   06CF FC                 1198 	mov	r4,a
   06D0 BC FF 18           1199 	cjne	r4,#0xFF,00106$
   06D3 74 01              1200 	mov	a,#0x01
   06D5 2D                 1201 	add	a,r5
   06D6 FA                 1202 	mov	r2,a
   06D7 E4                 1203 	clr	a
   06D8 3E                 1204 	addc	a,r6
   06D9 FB                 1205 	mov	r3,a
   06DA 8F 04              1206 	mov	ar4,r7
   06DC 8A 82              1207 	mov	dpl,r2
   06DE 8B 83              1208 	mov	dph,r3
   06E0 8C F0              1209 	mov	b,r4
   06E2 12 42 C6           1210 	lcall	__gptrget
   06E5 FA                 1211 	mov	r2,a
   06E6 BA FF 02           1212 	cjne	r2,#0xFF,00123$
   06E9 80 05              1213 	sjmp	00107$
   06EB                    1214 00123$:
   06EB                    1215 00106$:
                    0196   1216 	C$dynamixel.c$154$1$1 ==.
                           1217 ;	apps/twitch_mx_servos/dynamixel.c:154: return DYNAMIXEL_RX_CORRUPT;
   06EB 75 82 02           1218 	mov	dpl,#0x02
   06EE 80 3A              1219 	sjmp	00111$
   06F0                    1220 00107$:
                    019B   1221 	C$dynamixel.c$156$1$1 ==.
                           1222 ;	apps/twitch_mx_servos/dynamixel.c:156: if(rxpacket[packetlength - 1] != dynamixel_calculatechecksum(rxpacket))
   06F0 78 0F              1223 	mov	r0,#_dynamixel_readpacket_PARM_2
   06F2 E2                 1224 	movx	a,@r0
   06F3 FB                 1225 	mov	r3,a
   06F4 7C 00              1226 	mov	r4,#0x00
   06F6 1B                 1227 	dec	r3
   06F7 BB FF 01           1228 	cjne	r3,#0xFF,00124$
   06FA 1C                 1229 	dec	r4
   06FB                    1230 00124$:
   06FB EB                 1231 	mov	a,r3
   06FC 2D                 1232 	add	a,r5
   06FD FB                 1233 	mov	r3,a
   06FE EC                 1234 	mov	a,r4
   06FF 3E                 1235 	addc	a,r6
   0700 FC                 1236 	mov	r4,a
   0701 8F 02              1237 	mov	ar2,r7
   0703 8B 82              1238 	mov	dpl,r3
   0705 8C 83              1239 	mov	dph,r4
   0707 8A F0              1240 	mov	b,r2
   0709 12 42 C6           1241 	lcall	__gptrget
   070C FB                 1242 	mov	r3,a
   070D 8D 82              1243 	mov	dpl,r5
   070F 8E 83              1244 	mov	dph,r6
   0711 8F F0              1245 	mov	b,r7
   0713 C0 03              1246 	push	ar3
   0715 12 05 AC           1247 	lcall	_dynamixel_calculatechecksum
   0718 AF 82              1248 	mov	r7,dpl
   071A D0 03              1249 	pop	ar3
   071C EB                 1250 	mov	a,r3
   071D B5 07 02           1251 	cjne	a,ar7,00125$
   0720 80 05              1252 	sjmp	00110$
   0722                    1253 00125$:
                    01CD   1254 	C$dynamixel.c$157$1$1 ==.
                           1255 ;	apps/twitch_mx_servos/dynamixel.c:157: return DYNAMIXEL_RX_CORRUPT;
   0722 75 82 02           1256 	mov	dpl,#0x02
   0725 80 03              1257 	sjmp	00111$
   0727                    1258 00110$:
                    01D2   1259 	C$dynamixel.c$159$1$1 ==.
                           1260 ;	apps/twitch_mx_servos/dynamixel.c:159: return DYNAMIXEL_SUCCESS;
   0727 75 82 01           1261 	mov	dpl,#0x01
   072A                    1262 00111$:
                    01D5   1263 	C$dynamixel.c$160$1$1 ==.
                    01D5   1264 	XG$dynamixel_readpacket$0$0 ==.
   072A 22                 1265 	ret
                           1266 ;------------------------------------------------------------
                           1267 ;Allocation info for local variables in function 'dynamixel_txrx'
                           1268 ;------------------------------------------------------------
                           1269 ;sloc0                     Allocated with name '_dynamixel_txrx_sloc0_1_0'
                           1270 ;------------------------------------------------------------
                    01D6   1271 	G$dynamixel_txrx$0$0 ==.
                    01D6   1272 	C$dynamixel.c$162$1$1 ==.
                           1273 ;	apps/twitch_mx_servos/dynamixel.c:162: uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket)
                           1274 ;	-----------------------------------------
                           1275 ;	 function dynamixel_txrx
                           1276 ;	-----------------------------------------
   072B                    1277 _dynamixel_txrx:
   072B AF F0              1278 	mov	r7,b
   072D AE 83              1279 	mov	r6,dph
   072F E5 82              1280 	mov	a,dpl
   0731 78 16              1281 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   0733 F2                 1282 	movx	@r0,a
   0734 08                 1283 	inc	r0
   0735 EE                 1284 	mov	a,r6
   0736 F2                 1285 	movx	@r0,a
   0737 08                 1286 	inc	r0
   0738 EF                 1287 	mov	a,r7
   0739 F2                 1288 	movx	@r0,a
                    01E5   1289 	C$dynamixel.c$175$1$1 ==.
                           1290 ;	apps/twitch_mx_servos/dynamixel.c:175: uint8 txlength = dynamixel_txpacket[DYNAMIXEL_LENGTH] + 4; // 0xff,0xff, ID, packet, checksum ?
   073A 78 00              1291 	mov	r0,#_dynamixel_txpacket
   073C E2                 1292 	movx	a,@r0
   073D 24 03              1293 	add	a,#0x03
   073F FD                 1294 	mov	r5,a
   0740 08                 1295 	inc	r0
   0741 E2                 1296 	movx	a,@r0
   0742 34 00              1297 	addc	a,#0x00
   0744 FE                 1298 	mov	r6,a
   0745 08                 1299 	inc	r0
   0746 E2                 1300 	movx	a,@r0
   0747 FF                 1301 	mov	r7,a
   0748 8D 82              1302 	mov	dpl,r5
   074A 8E 83              1303 	mov	dph,r6
   074C 8F F0              1304 	mov	b,r7
   074E 12 42 C6           1305 	lcall	__gptrget
   0751 FD                 1306 	mov	r5,a
   0752 78 19              1307 	mov	r0,#_dynamixel_txrx_txlength_1_1
   0754 74 04              1308 	mov	a,#0x04
   0756 2D                 1309 	add	a,r5
   0757 F2                 1310 	movx	@r0,a
                    0203   1311 	C$dynamixel.c$177$1$1 ==.
                           1312 ;	apps/twitch_mx_servos/dynamixel.c:177: txpacket[0] = (uint8) 0xff;
   0758 78 16              1313 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   075A E2                 1314 	movx	a,@r0
   075B FC                 1315 	mov	r4,a
   075C 08                 1316 	inc	r0
   075D E2                 1317 	movx	a,@r0
   075E FE                 1318 	mov	r6,a
   075F 08                 1319 	inc	r0
   0760 E2                 1320 	movx	a,@r0
   0761 FF                 1321 	mov	r7,a
   0762 8C 82              1322 	mov	dpl,r4
   0764 8E 83              1323 	mov	dph,r6
   0766 8F F0              1324 	mov	b,r7
   0768 74 FF              1325 	mov	a,#0xFF
   076A 12 36 56           1326 	lcall	__gptrput
                    0218   1327 	C$dynamixel.c$178$1$1 ==.
                           1328 ;	apps/twitch_mx_servos/dynamixel.c:178: txpacket[1] = (uint8) 0xff;
   076D 74 01              1329 	mov	a,#0x01
   076F 2C                 1330 	add	a,r4
   0770 FA                 1331 	mov	r2,a
   0771 E4                 1332 	clr	a
   0772 3E                 1333 	addc	a,r6
   0773 FB                 1334 	mov	r3,a
   0774 8F 05              1335 	mov	ar5,r7
   0776 8A 82              1336 	mov	dpl,r2
   0778 8B 83              1337 	mov	dph,r3
   077A 8D F0              1338 	mov	b,r5
   077C 74 FF              1339 	mov	a,#0xFF
   077E 12 36 56           1340 	lcall	__gptrput
                    022C   1341 	C$dynamixel.c$179$1$1 ==.
                           1342 ;	apps/twitch_mx_servos/dynamixel.c:179: txpacket[txlength - 1] = (uint8) dynamixel_calculatechecksum(txpacket);
   0781 78 19              1343 	mov	r0,#_dynamixel_txrx_txlength_1_1
   0783 E2                 1344 	movx	a,@r0
   0784 FB                 1345 	mov	r3,a
   0785 7D 00              1346 	mov	r5,#0x00
   0787 1B                 1347 	dec	r3
   0788 BB FF 01           1348 	cjne	r3,#0xFF,00110$
   078B 1D                 1349 	dec	r5
   078C                    1350 00110$:
   078C EB                 1351 	mov	a,r3
   078D 2C                 1352 	add	a,r4
   078E F5 08              1353 	mov	_dynamixel_txrx_sloc0_1_0,a
   0790 ED                 1354 	mov	a,r5
   0791 3E                 1355 	addc	a,r6
   0792 F5 09              1356 	mov	(_dynamixel_txrx_sloc0_1_0 + 1),a
   0794 8F 0A              1357 	mov	(_dynamixel_txrx_sloc0_1_0 + 2),r7
   0796 8C 82              1358 	mov	dpl,r4
   0798 8E 83              1359 	mov	dph,r6
   079A 8F F0              1360 	mov	b,r7
   079C C0 07              1361 	push	ar7
   079E C0 06              1362 	push	ar6
   07A0 C0 04              1363 	push	ar4
   07A2 12 05 AC           1364 	lcall	_dynamixel_calculatechecksum
   07A5 AD 82              1365 	mov	r5,dpl
   07A7 85 08 82           1366 	mov	dpl,_dynamixel_txrx_sloc0_1_0
   07AA 85 09 83           1367 	mov	dph,(_dynamixel_txrx_sloc0_1_0 + 1)
   07AD 85 0A F0           1368 	mov	b,(_dynamixel_txrx_sloc0_1_0 + 2)
   07B0 ED                 1369 	mov	a,r5
   07B1 12 36 56           1370 	lcall	__gptrput
                    025F   1371 	C$dynamixel.c$181$1$1 ==.
                           1372 ;	apps/twitch_mx_servos/dynamixel.c:181: dynamixel_settx();
   07B4 12 05 82           1373 	lcall	_dynamixel_settx
                    0262   1374 	C$dynamixel.c$182$1$1 ==.
                           1375 ;	apps/twitch_mx_servos/dynamixel.c:182: dynamixel_writepacket(txpacket, txlength);
   07B7 78 19              1376 	mov	r0,#_dynamixel_txrx_txlength_1_1
   07B9 79 0B              1377 	mov	r1,#_dynamixel_writepacket_PARM_2
   07BB E2                 1378 	movx	a,@r0
   07BC F3                 1379 	movx	@r1,a
   07BD 78 16              1380 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   07BF E2                 1381 	movx	a,@r0
   07C0 F5 82              1382 	mov	dpl,a
   07C2 08                 1383 	inc	r0
   07C3 E2                 1384 	movx	a,@r0
   07C4 F5 83              1385 	mov	dph,a
   07C6 08                 1386 	inc	r0
   07C7 E2                 1387 	movx	a,@r0
   07C8 F5 F0              1388 	mov	b,a
   07CA 12 06 43           1389 	lcall	_dynamixel_writepacket
                    0278   1390 	C$dynamixel.c$183$1$1 ==.
                           1391 ;	apps/twitch_mx_servos/dynamixel.c:183: dynamixel_setrx();
   07CD 12 05 93           1392 	lcall	_dynamixel_setrx
   07D0 D0 04              1393 	pop	ar4
   07D2 D0 06              1394 	pop	ar6
   07D4 D0 07              1395 	pop	ar7
                    0281   1396 	C$dynamixel.c$186$1$1 ==.
                           1397 ;	apps/twitch_mx_servos/dynamixel.c:186: if(txpacket[DYNAMIXEL_ID] != DYNAMIXEL_BROADCAST_ID)
   07D6 78 16              1398 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   07D8 E2                 1399 	movx	a,@r0
   07D9 24 02              1400 	add	a,#0x02
   07DB FA                 1401 	mov	r2,a
   07DC 08                 1402 	inc	r0
   07DD E2                 1403 	movx	a,@r0
   07DE 34 00              1404 	addc	a,#0x00
   07E0 FB                 1405 	mov	r3,a
   07E1 08                 1406 	inc	r0
   07E2 E2                 1407 	movx	a,@r0
   07E3 FD                 1408 	mov	r5,a
   07E4 8A 82              1409 	mov	dpl,r2
   07E6 8B 83              1410 	mov	dph,r3
   07E8 8D F0              1411 	mov	b,r5
   07EA 12 42 C6           1412 	lcall	__gptrget
   07ED FA                 1413 	mov	r2,a
   07EE BA FE 02           1414 	cjne	r2,#0xFE,00111$
   07F1 80 44              1415 	sjmp	00105$
   07F3                    1416 00111$:
                    029E   1417 	C$dynamixel.c$189$2$2 ==.
                           1418 ;	apps/twitch_mx_servos/dynamixel.c:189: if(txpacket[DYNAMIXEL_INSTRUCTION] == DYNAMIXEL_READ)
   07F3 74 04              1419 	mov	a,#0x04
   07F5 2C                 1420 	add	a,r4
   07F6 FA                 1421 	mov	r2,a
   07F7 E4                 1422 	clr	a
   07F8 3E                 1423 	addc	a,r6
   07F9 FB                 1424 	mov	r3,a
   07FA 8F 05              1425 	mov	ar5,r7
   07FC 8A 82              1426 	mov	dpl,r2
   07FE 8B 83              1427 	mov	dph,r3
   0800 8D F0              1428 	mov	b,r5
   0802 12 42 C6           1429 	lcall	__gptrget
   0805 FA                 1430 	mov	r2,a
   0806 BA 02 16           1431 	cjne	r2,#0x02,00102$
                    02B4   1432 	C$dynamixel.c$191$2$2 ==.
                           1433 ;	apps/twitch_mx_servos/dynamixel.c:191: rxlength = txpacket[DYNAMIXEL_PARAMETER + 1] + 6;
   0809 74 06              1434 	mov	a,#0x06
   080B 2C                 1435 	add	a,r4
   080C FC                 1436 	mov	r4,a
   080D E4                 1437 	clr	a
   080E 3E                 1438 	addc	a,r6
   080F FE                 1439 	mov	r6,a
   0810 8C 82              1440 	mov	dpl,r4
   0812 8E 83              1441 	mov	dph,r6
   0814 8F F0              1442 	mov	b,r7
   0816 12 42 C6           1443 	lcall	__gptrget
   0819 FC                 1444 	mov	r4,a
   081A 24 06              1445 	add	a,#0x06
   081C FF                 1446 	mov	r7,a
   081D 80 02              1447 	sjmp	00103$
   081F                    1448 00102$:
                    02CA   1449 	C$dynamixel.c$193$2$2 ==.
                           1450 ;	apps/twitch_mx_servos/dynamixel.c:193: rxlength = 6; // Default answer packet length? for DYNAMIXEL_WRITE?
   081F 7F 06              1451 	mov	r7,#0x06
   0821                    1452 00103$:
                    02CC   1453 	C$dynamixel.c$195$2$2 ==.
                           1454 ;	apps/twitch_mx_servos/dynamixel.c:195: return dynamixel_readpacket(rxpacket, rxlength);			
   0821 78 0F              1455 	mov	r0,#_dynamixel_readpacket_PARM_2
   0823 EF                 1456 	mov	a,r7
   0824 F2                 1457 	movx	@r0,a
   0825 78 13              1458 	mov	r0,#_dynamixel_txrx_PARM_2
   0827 E2                 1459 	movx	a,@r0
   0828 F5 82              1460 	mov	dpl,a
   082A 08                 1461 	inc	r0
   082B E2                 1462 	movx	a,@r0
   082C F5 83              1463 	mov	dph,a
   082E 08                 1464 	inc	r0
   082F E2                 1465 	movx	a,@r0
   0830 F5 F0              1466 	mov	b,a
   0832 12 06 85           1467 	lcall	_dynamixel_readpacket
   0835 80 06              1468 	sjmp	00106$
   0837                    1469 00105$:
                    02E2   1470 	C$dynamixel.c$198$1$1 ==.
                           1471 ;	apps/twitch_mx_servos/dynamixel.c:198: dynamixel_settx();
   0837 12 05 82           1472 	lcall	_dynamixel_settx
                    02E5   1473 	C$dynamixel.c$200$1$1 ==.
                           1474 ;	apps/twitch_mx_servos/dynamixel.c:200: return DYNAMIXEL_SUCCESS;
   083A 75 82 01           1475 	mov	dpl,#0x01
   083D                    1476 00106$:
                    02E8   1477 	C$dynamixel.c$201$1$1 ==.
                    02E8   1478 	XG$dynamixel_txrx$0$0 ==.
   083D 22                 1479 	ret
                           1480 ;------------------------------------------------------------
                           1481 ;Allocation info for local variables in function 'dynamixel_writebyte'
                           1482 ;------------------------------------------------------------
                    02E9   1483 	G$dynamixel_writebyte$0$0 ==.
                    02E9   1484 	C$dynamixel.c$274$1$1 ==.
                           1485 ;	apps/twitch_mx_servos/dynamixel.c:274: uint8 dynamixel_writebyte(uint8 id, uint8 address, uint8 value)
                           1486 ;	-----------------------------------------
                           1487 ;	 function dynamixel_writebyte
                           1488 ;	-----------------------------------------
   083E                    1489 _dynamixel_writebyte:
   083E AF 82              1490 	mov	r7,dpl
                    02EB   1491 	C$dynamixel.c$276$1$1 ==.
                           1492 ;	apps/twitch_mx_servos/dynamixel.c:276: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0840 78 00              1493 	mov	r0,#_dynamixel_txpacket
   0842 E2                 1494 	movx	a,@r0
   0843 24 02              1495 	add	a,#0x02
   0845 FC                 1496 	mov	r4,a
   0846 08                 1497 	inc	r0
   0847 E2                 1498 	movx	a,@r0
   0848 34 00              1499 	addc	a,#0x00
   084A FD                 1500 	mov	r5,a
   084B 08                 1501 	inc	r0
   084C E2                 1502 	movx	a,@r0
   084D FE                 1503 	mov	r6,a
   084E 8C 82              1504 	mov	dpl,r4
   0850 8D 83              1505 	mov	dph,r5
   0852 8E F0              1506 	mov	b,r6
   0854 EF                 1507 	mov	a,r7
   0855 12 36 56           1508 	lcall	__gptrput
                    0303   1509 	C$dynamixel.c$277$1$1 ==.
                           1510 ;	apps/twitch_mx_servos/dynamixel.c:277: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
   0858 78 00              1511 	mov	r0,#_dynamixel_txpacket
   085A E2                 1512 	movx	a,@r0
   085B 24 03              1513 	add	a,#0x03
   085D FD                 1514 	mov	r5,a
   085E 08                 1515 	inc	r0
   085F E2                 1516 	movx	a,@r0
   0860 34 00              1517 	addc	a,#0x00
   0862 FE                 1518 	mov	r6,a
   0863 08                 1519 	inc	r0
   0864 E2                 1520 	movx	a,@r0
   0865 FF                 1521 	mov	r7,a
   0866 8D 82              1522 	mov	dpl,r5
   0868 8E 83              1523 	mov	dph,r6
   086A 8F F0              1524 	mov	b,r7
   086C 74 04              1525 	mov	a,#0x04
   086E 12 36 56           1526 	lcall	__gptrput
                    031C   1527 	C$dynamixel.c$278$1$1 ==.
                           1528 ;	apps/twitch_mx_servos/dynamixel.c:278: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
   0871 78 00              1529 	mov	r0,#_dynamixel_txpacket
   0873 E2                 1530 	movx	a,@r0
   0874 24 04              1531 	add	a,#0x04
   0876 FD                 1532 	mov	r5,a
   0877 08                 1533 	inc	r0
   0878 E2                 1534 	movx	a,@r0
   0879 34 00              1535 	addc	a,#0x00
   087B FE                 1536 	mov	r6,a
   087C 08                 1537 	inc	r0
   087D E2                 1538 	movx	a,@r0
   087E FF                 1539 	mov	r7,a
   087F 8D 82              1540 	mov	dpl,r5
   0881 8E 83              1541 	mov	dph,r6
   0883 8F F0              1542 	mov	b,r7
   0885 74 03              1543 	mov	a,#0x03
   0887 12 36 56           1544 	lcall	__gptrput
                    0335   1545 	C$dynamixel.c$279$1$1 ==.
                           1546 ;	apps/twitch_mx_servos/dynamixel.c:279: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   088A 78 00              1547 	mov	r0,#_dynamixel_txpacket
   088C E2                 1548 	movx	a,@r0
   088D 24 05              1549 	add	a,#0x05
   088F FD                 1550 	mov	r5,a
   0890 08                 1551 	inc	r0
   0891 E2                 1552 	movx	a,@r0
   0892 34 00              1553 	addc	a,#0x00
   0894 FE                 1554 	mov	r6,a
   0895 08                 1555 	inc	r0
   0896 E2                 1556 	movx	a,@r0
   0897 FF                 1557 	mov	r7,a
   0898 8D 82              1558 	mov	dpl,r5
   089A 8E 83              1559 	mov	dph,r6
   089C 8F F0              1560 	mov	b,r7
   089E 78 1A              1561 	mov	r0,#_dynamixel_writebyte_PARM_2
   08A0 E2                 1562 	movx	a,@r0
   08A1 12 36 56           1563 	lcall	__gptrput
                    034F   1564 	C$dynamixel.c$280$1$1 ==.
                           1565 ;	apps/twitch_mx_servos/dynamixel.c:280: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) value;
   08A4 78 00              1566 	mov	r0,#_dynamixel_txpacket
   08A6 E2                 1567 	movx	a,@r0
   08A7 24 06              1568 	add	a,#0x06
   08A9 FD                 1569 	mov	r5,a
   08AA 08                 1570 	inc	r0
   08AB E2                 1571 	movx	a,@r0
   08AC 34 00              1572 	addc	a,#0x00
   08AE FE                 1573 	mov	r6,a
   08AF 08                 1574 	inc	r0
   08B0 E2                 1575 	movx	a,@r0
   08B1 FF                 1576 	mov	r7,a
   08B2 8D 82              1577 	mov	dpl,r5
   08B4 8E 83              1578 	mov	dph,r6
   08B6 8F F0              1579 	mov	b,r7
   08B8 78 1B              1580 	mov	r0,#_dynamixel_writebyte_PARM_3
   08BA E2                 1581 	movx	a,@r0
   08BB 12 36 56           1582 	lcall	__gptrput
                    0369   1583 	C$dynamixel.c$282$1$1 ==.
                           1584 ;	apps/twitch_mx_servos/dynamixel.c:282: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   08BE 78 03              1585 	mov	r0,#_dynamixel_rxpacket
   08C0 79 13              1586 	mov	r1,#_dynamixel_txrx_PARM_2
   08C2 E2                 1587 	movx	a,@r0
   08C3 F3                 1588 	movx	@r1,a
   08C4 08                 1589 	inc	r0
   08C5 E2                 1590 	movx	a,@r0
   08C6 09                 1591 	inc	r1
   08C7 F3                 1592 	movx	@r1,a
   08C8 08                 1593 	inc	r0
   08C9 E2                 1594 	movx	a,@r0
   08CA 09                 1595 	inc	r1
   08CB F3                 1596 	movx	@r1,a
   08CC 78 00              1597 	mov	r0,#_dynamixel_txpacket
   08CE E2                 1598 	movx	a,@r0
   08CF F5 82              1599 	mov	dpl,a
   08D1 08                 1600 	inc	r0
   08D2 E2                 1601 	movx	a,@r0
   08D3 F5 83              1602 	mov	dph,a
   08D5 08                 1603 	inc	r0
   08D6 E2                 1604 	movx	a,@r0
   08D7 F5 F0              1605 	mov	b,a
   08D9 12 07 2B           1606 	lcall	_dynamixel_txrx
                    0387   1607 	C$dynamixel.c$283$1$1 ==.
                    0387   1608 	XG$dynamixel_writebyte$0$0 ==.
   08DC 22                 1609 	ret
                           1610 ;------------------------------------------------------------
                           1611 ;Allocation info for local variables in function 'dynamixel_syncwrite'
                           1612 ;------------------------------------------------------------
                    0388   1613 	G$dynamixel_syncwrite$0$0 ==.
                    0388   1614 	C$dynamixel.c$297$1$1 ==.
                           1615 ;	apps/twitch_mx_servos/dynamixel.c:297: uint8 dynamixel_syncwrite(uint8 address, uint8 length, uint8 number, uint8* param)
                           1616 ;	-----------------------------------------
                           1617 ;	 function dynamixel_syncwrite
                           1618 ;	-----------------------------------------
   08DD                    1619 _dynamixel_syncwrite:
   08DD AF 82              1620 	mov	r7,dpl
                    038A   1621 	C$dynamixel.c$302$1$1 ==.
                           1622 ;	apps/twitch_mx_servos/dynamixel.c:302: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) DYNAMIXEL_BROADCAST_ID;
   08DF 78 00              1623 	mov	r0,#_dynamixel_txpacket
   08E1 E2                 1624 	movx	a,@r0
   08E2 24 02              1625 	add	a,#0x02
   08E4 FC                 1626 	mov	r4,a
   08E5 08                 1627 	inc	r0
   08E6 E2                 1628 	movx	a,@r0
   08E7 34 00              1629 	addc	a,#0x00
   08E9 FD                 1630 	mov	r5,a
   08EA 08                 1631 	inc	r0
   08EB E2                 1632 	movx	a,@r0
   08EC FE                 1633 	mov	r6,a
   08ED 8C 82              1634 	mov	dpl,r4
   08EF 8D 83              1635 	mov	dph,r5
   08F1 8E F0              1636 	mov	b,r6
   08F3 74 FE              1637 	mov	a,#0xFE
   08F5 12 36 56           1638 	lcall	__gptrput
                    03A3   1639 	C$dynamixel.c$303$1$1 ==.
                           1640 ;	apps/twitch_mx_servos/dynamixel.c:303: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) ((length + 1) * number + 4);
   08F8 78 00              1641 	mov	r0,#_dynamixel_txpacket
   08FA E2                 1642 	movx	a,@r0
   08FB 24 03              1643 	add	a,#0x03
   08FD FC                 1644 	mov	r4,a
   08FE 08                 1645 	inc	r0
   08FF E2                 1646 	movx	a,@r0
   0900 34 00              1647 	addc	a,#0x00
   0902 FD                 1648 	mov	r5,a
   0903 08                 1649 	inc	r0
   0904 E2                 1650 	movx	a,@r0
   0905 FE                 1651 	mov	r6,a
   0906 78 1C              1652 	mov	r0,#_dynamixel_syncwrite_PARM_2
   0908 E2                 1653 	movx	a,@r0
   0909 24 01              1654 	add	a,#0x01
   090B FB                 1655 	mov	r3,a
   090C 78 1D              1656 	mov	r0,#_dynamixel_syncwrite_PARM_3
   090E 8B F0              1657 	mov	b,r3
   0910 E2                 1658 	movx	a,@r0
   0911 A4                 1659 	mul	ab
   0912 24 04              1660 	add	a,#0x04
   0914 FB                 1661 	mov	r3,a
   0915 8C 82              1662 	mov	dpl,r4
   0917 8D 83              1663 	mov	dph,r5
   0919 8E F0              1664 	mov	b,r6
   091B 12 36 56           1665 	lcall	__gptrput
                    03C9   1666 	C$dynamixel.c$304$1$1 ==.
                           1667 ;	apps/twitch_mx_servos/dynamixel.c:304: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_SYNC_WRITE;
   091E 78 00              1668 	mov	r0,#_dynamixel_txpacket
   0920 E2                 1669 	movx	a,@r0
   0921 24 04              1670 	add	a,#0x04
   0923 FC                 1671 	mov	r4,a
   0924 08                 1672 	inc	r0
   0925 E2                 1673 	movx	a,@r0
   0926 34 00              1674 	addc	a,#0x00
   0928 FD                 1675 	mov	r5,a
   0929 08                 1676 	inc	r0
   092A E2                 1677 	movx	a,@r0
   092B FE                 1678 	mov	r6,a
   092C 8C 82              1679 	mov	dpl,r4
   092E 8D 83              1680 	mov	dph,r5
   0930 8E F0              1681 	mov	b,r6
   0932 74 83              1682 	mov	a,#0x83
   0934 12 36 56           1683 	lcall	__gptrput
                    03E2   1684 	C$dynamixel.c$305$1$1 ==.
                           1685 ;	apps/twitch_mx_servos/dynamixel.c:305: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   0937 78 00              1686 	mov	r0,#_dynamixel_txpacket
   0939 E2                 1687 	movx	a,@r0
   093A 24 05              1688 	add	a,#0x05
   093C FC                 1689 	mov	r4,a
   093D 08                 1690 	inc	r0
   093E E2                 1691 	movx	a,@r0
   093F 34 00              1692 	addc	a,#0x00
   0941 FD                 1693 	mov	r5,a
   0942 08                 1694 	inc	r0
   0943 E2                 1695 	movx	a,@r0
   0944 FE                 1696 	mov	r6,a
   0945 8C 82              1697 	mov	dpl,r4
   0947 8D 83              1698 	mov	dph,r5
   0949 8E F0              1699 	mov	b,r6
   094B EF                 1700 	mov	a,r7
   094C 12 36 56           1701 	lcall	__gptrput
                    03FA   1702 	C$dynamixel.c$306$1$1 ==.
                           1703 ;	apps/twitch_mx_servos/dynamixel.c:306: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length; // The length of the packet where its value is “Number of parameters (N) +2”
   094F 78 00              1704 	mov	r0,#_dynamixel_txpacket
   0951 E2                 1705 	movx	a,@r0
   0952 24 06              1706 	add	a,#0x06
   0954 FD                 1707 	mov	r5,a
   0955 08                 1708 	inc	r0
   0956 E2                 1709 	movx	a,@r0
   0957 34 00              1710 	addc	a,#0x00
   0959 FE                 1711 	mov	r6,a
   095A 08                 1712 	inc	r0
   095B E2                 1713 	movx	a,@r0
   095C FF                 1714 	mov	r7,a
   095D 8D 82              1715 	mov	dpl,r5
   095F 8E 83              1716 	mov	dph,r6
   0961 8F F0              1717 	mov	b,r7
   0963 78 1C              1718 	mov	r0,#_dynamixel_syncwrite_PARM_2
   0965 E2                 1719 	movx	a,@r0
   0966 12 36 56           1720 	lcall	__gptrput
                    0414   1721 	C$dynamixel.c$308$1$1 ==.
                           1722 ;	apps/twitch_mx_servos/dynamixel.c:308: for(i = 0; i < ((length + 1) * number); i++){
   0969 78 21              1723 	mov	r0,#_dynamixel_syncwrite_i_1_1
   096B E4                 1724 	clr	a
   096C F2                 1725 	movx	@r0,a
   096D                    1726 00101$:
   096D 78 1C              1727 	mov	r0,#_dynamixel_syncwrite_PARM_2
   096F E2                 1728 	movx	a,@r0
   0970 FD                 1729 	mov	r5,a
   0971 7E 00              1730 	mov	r6,#0x00
   0973 8D 82              1731 	mov	dpl,r5
   0975 8E 83              1732 	mov	dph,r6
   0977 A3                 1733 	inc	dptr
   0978 78 1D              1734 	mov	r0,#_dynamixel_syncwrite_PARM_3
   097A 79 E8              1735 	mov	r1,#__mulint_PARM_2
   097C E2                 1736 	movx	a,@r0
   097D F3                 1737 	movx	@r1,a
   097E 09                 1738 	inc	r1
   097F E4                 1739 	clr	a
   0980 F3                 1740 	movx	@r1,a
   0981 12 38 07           1741 	lcall	__mulint
   0984 AD 82              1742 	mov	r5,dpl
   0986 AE 83              1743 	mov	r6,dph
   0988 78 21              1744 	mov	r0,#_dynamixel_syncwrite_i_1_1
   098A E2                 1745 	movx	a,@r0
   098B FB                 1746 	mov	r3,a
   098C 7C 00              1747 	mov	r4,#0x00
   098E C3                 1748 	clr	c
   098F EB                 1749 	mov	a,r3
   0990 9D                 1750 	subb	a,r5
   0991 EC                 1751 	mov	a,r4
   0992 64 80              1752 	xrl	a,#0x80
   0994 8E F0              1753 	mov	b,r6
   0996 63 F0 80           1754 	xrl	b,#0x80
   0999 95 F0              1755 	subb	a,b
   099B 50 41              1756 	jnc	00104$
                    0448   1757 	C$dynamixel.c$309$2$2 ==.
                           1758 ;	apps/twitch_mx_servos/dynamixel.c:309: dynamixel_txpacket[DYNAMIXEL_PARAMETER + 2 + i] = (uint8) param[i];
   099D 74 07              1759 	mov	a,#0x07
   099F 2B                 1760 	add	a,r3
   09A0 FB                 1761 	mov	r3,a
   09A1 E4                 1762 	clr	a
   09A2 3C                 1763 	addc	a,r4
   09A3 FC                 1764 	mov	r4,a
   09A4 78 00              1765 	mov	r0,#_dynamixel_txpacket
   09A6 E2                 1766 	movx	a,@r0
   09A7 2B                 1767 	add	a,r3
   09A8 FB                 1768 	mov	r3,a
   09A9 08                 1769 	inc	r0
   09AA E2                 1770 	movx	a,@r0
   09AB 3C                 1771 	addc	a,r4
   09AC FC                 1772 	mov	r4,a
   09AD 08                 1773 	inc	r0
   09AE E2                 1774 	movx	a,@r0
   09AF FE                 1775 	mov	r6,a
   09B0 78 1E              1776 	mov	r0,#_dynamixel_syncwrite_PARM_4
   09B2 79 21              1777 	mov	r1,#_dynamixel_syncwrite_i_1_1
   09B4 E3                 1778 	movx	a,@r1
   09B5 C5 F0              1779 	xch	a,b
   09B7 E2                 1780 	movx	a,@r0
   09B8 25 F0              1781 	add	a,b
   09BA FA                 1782 	mov	r2,a
   09BB 08                 1783 	inc	r0
   09BC E2                 1784 	movx	a,@r0
   09BD 34 00              1785 	addc	a,#0x00
   09BF FD                 1786 	mov	r5,a
   09C0 08                 1787 	inc	r0
   09C1 E2                 1788 	movx	a,@r0
   09C2 FF                 1789 	mov	r7,a
   09C3 8A 82              1790 	mov	dpl,r2
   09C5 8D 83              1791 	mov	dph,r5
   09C7 8F F0              1792 	mov	b,r7
   09C9 12 42 C6           1793 	lcall	__gptrget
   09CC FA                 1794 	mov	r2,a
   09CD 8B 82              1795 	mov	dpl,r3
   09CF 8C 83              1796 	mov	dph,r4
   09D1 8E F0              1797 	mov	b,r6
   09D3 12 36 56           1798 	lcall	__gptrput
                    0481   1799 	C$dynamixel.c$308$1$1 ==.
                           1800 ;	apps/twitch_mx_servos/dynamixel.c:308: for(i = 0; i < ((length + 1) * number); i++){
   09D6 78 21              1801 	mov	r0,#_dynamixel_syncwrite_i_1_1
   09D8 E2                 1802 	movx	a,@r0
   09D9 24 01              1803 	add	a,#0x01
   09DB F2                 1804 	movx	@r0,a
   09DC 80 8F              1805 	sjmp	00101$
   09DE                    1806 00104$:
                    0489   1807 	C$dynamixel.c$311$1$1 ==.
                           1808 ;	apps/twitch_mx_servos/dynamixel.c:311: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   09DE 78 03              1809 	mov	r0,#_dynamixel_rxpacket
   09E0 79 13              1810 	mov	r1,#_dynamixel_txrx_PARM_2
   09E2 E2                 1811 	movx	a,@r0
   09E3 F3                 1812 	movx	@r1,a
   09E4 08                 1813 	inc	r0
   09E5 E2                 1814 	movx	a,@r0
   09E6 09                 1815 	inc	r1
   09E7 F3                 1816 	movx	@r1,a
   09E8 08                 1817 	inc	r0
   09E9 E2                 1818 	movx	a,@r0
   09EA 09                 1819 	inc	r1
   09EB F3                 1820 	movx	@r1,a
   09EC 78 00              1821 	mov	r0,#_dynamixel_txpacket
   09EE E2                 1822 	movx	a,@r0
   09EF F5 82              1823 	mov	dpl,a
   09F1 08                 1824 	inc	r0
   09F2 E2                 1825 	movx	a,@r0
   09F3 F5 83              1826 	mov	dph,a
   09F5 08                 1827 	inc	r0
   09F6 E2                 1828 	movx	a,@r0
   09F7 F5 F0              1829 	mov	b,a
   09F9 12 07 2B           1830 	lcall	_dynamixel_txrx
                    04A7   1831 	C$dynamixel.c$312$1$1 ==.
                    04A7   1832 	XG$dynamixel_syncwrite$0$0 ==.
   09FC 22                 1833 	ret
                           1834 ;------------------------------------------------------------
                           1835 ;Allocation info for local variables in function 'dynamixel_makeword'
                           1836 ;------------------------------------------------------------
                    04A8   1837 	G$dynamixel_makeword$0$0 ==.
                    04A8   1838 	C$dynamixel.c$340$1$1 ==.
                           1839 ;	apps/twitch_mx_servos/dynamixel.c:340: uint16 dynamixel_makeword(uint8 lowbyte, uint8 highbyte)
                           1840 ;	-----------------------------------------
                           1841 ;	 function dynamixel_makeword
                           1842 ;	-----------------------------------------
   09FD                    1843 _dynamixel_makeword:
   09FD AF 82              1844 	mov	r7,dpl
                    04AA   1845 	C$dynamixel.c$342$1$1 ==.
                           1846 ;	apps/twitch_mx_servos/dynamixel.c:342: return ((highbyte << 8) + lowbyte);
   09FF 78 22              1847 	mov	r0,#_dynamixel_makeword_PARM_2
   0A01 E2                 1848 	movx	a,@r0
   0A02 FE                 1849 	mov	r6,a
   0A03 E4                 1850 	clr	a
   0A04 FD                 1851 	mov	r5,a
   0A05 FC                 1852 	mov	r4,a
   0A06 EF                 1853 	mov	a,r7
   0A07 2D                 1854 	add	a,r5
   0A08 FD                 1855 	mov	r5,a
   0A09 EC                 1856 	mov	a,r4
   0A0A 3E                 1857 	addc	a,r6
                    04B6   1858 	C$dynamixel.c$343$1$1 ==.
                    04B6   1859 	XG$dynamixel_makeword$0$0 ==.
   0A0B 8D 82              1860 	mov	dpl,r5
   0A0D F5 83              1861 	mov	dph,a
   0A0F 22                 1862 	ret
                           1863 ;------------------------------------------------------------
                           1864 ;Allocation info for local variables in function 'dynamixel_getlowbyte'
                           1865 ;------------------------------------------------------------
                    04BB   1866 	G$dynamixel_getlowbyte$0$0 ==.
                    04BB   1867 	C$dynamixel.c$345$1$1 ==.
                           1868 ;	apps/twitch_mx_servos/dynamixel.c:345: uint8 dynamixel_getlowbyte(uint16 word)
                           1869 ;	-----------------------------------------
                           1870 ;	 function dynamixel_getlowbyte
                           1871 ;	-----------------------------------------
   0A10                    1872 _dynamixel_getlowbyte:
                    04BB   1873 	C$dynamixel.c$347$1$1 ==.
                           1874 ;	apps/twitch_mx_servos/dynamixel.c:347: return (word & 0xff);
                    04BB   1875 	C$dynamixel.c$348$1$1 ==.
                    04BB   1876 	XG$dynamixel_getlowbyte$0$0 ==.
   0A10 22                 1877 	ret
                           1878 ;------------------------------------------------------------
                           1879 ;Allocation info for local variables in function 'dynamixel_gethighbyte'
                           1880 ;------------------------------------------------------------
                    04BC   1881 	G$dynamixel_gethighbyte$0$0 ==.
                    04BC   1882 	C$dynamixel.c$350$1$1 ==.
                           1883 ;	apps/twitch_mx_servos/dynamixel.c:350: uint8 dynamixel_gethighbyte(uint16 word)
                           1884 ;	-----------------------------------------
                           1885 ;	 function dynamixel_gethighbyte
                           1886 ;	-----------------------------------------
   0A11                    1887 _dynamixel_gethighbyte:
   0A11 AF 83              1888 	mov	r7,dph
                    04BE   1889 	C$dynamixel.c$352$1$1 ==.
                           1890 ;	apps/twitch_mx_servos/dynamixel.c:352: return ((word & 0xff00) >> 8);
   0A13 8F 82              1891 	mov	dpl,r7
                    04C0   1892 	C$dynamixel.c$353$1$1 ==.
                    04C0   1893 	XG$dynamixel_gethighbyte$0$0 ==.
   0A15 22                 1894 	ret
                           1895 	.area CSEG    (CODE)
                           1896 	.area CONST   (CODE)
                           1897 	.area XINIT   (CODE)
                           1898 	.area CABS    (ABS,CODE)
