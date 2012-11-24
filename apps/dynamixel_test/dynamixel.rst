                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:37 2012
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
                             19 	.globl _dynamixel_writeword_PARM_3
                             20 	.globl _dynamixel_writeword_PARM_2
                             21 	.globl _dynamixel_writebyte_PARM_3
                             22 	.globl _dynamixel_writebyte_PARM_2
                             23 	.globl _dynamixel_readtable_PARM_4
                             24 	.globl _dynamixel_readtable_PARM_3
                             25 	.globl _dynamixel_readtable_PARM_2
                             26 	.globl _dynamixel_readword_PARM_3
                             27 	.globl _dynamixel_readword_PARM_2
                             28 	.globl _dynamixel_readbyte_PARM_3
                             29 	.globl _dynamixel_readbyte_PARM_2
                             30 	.globl _dynamixel_txrx_PARM_2
                             31 	.globl _dynamixel_readpacket_PARM_2
                             32 	.globl _dynamixel_writepacket_PARM_2
                             33 	.globl _dynamixel_rxindex
                             34 	.globl _dynamixel_rxpacket
                             35 	.globl _dynamixel_txpacket
                             36 	.globl _dynamixel_init
                             37 	.globl _dynamixel_settx
                             38 	.globl _dynamixel_setrx
                             39 	.globl _dynamixel_write
                             40 	.globl _dynamixel_calculatechecksum
                             41 	.globl _dynamixel_writepacket
                             42 	.globl _dynamixel_readpacket
                             43 	.globl _dynamixel_txrx
                             44 	.globl _dynamixel_ping
                             45 	.globl _dynamixel_readbyte
                             46 	.globl _dynamixel_readword
                             47 	.globl _dynamixel_readtable
                             48 	.globl _dynamixel_writebyte
                             49 	.globl _dynamixel_writeword
                             50 	.globl _dynamixel_syncwrite
                             51 	.globl _dynamixel_reset
                             52 	.globl _dynamixel_makeword
                             53 	.globl _dynamixel_getlowbyte
                             54 	.globl _dynamixel_gethighbyte
                             55 ;--------------------------------------------------------
                             56 ; special function registers
                             57 ;--------------------------------------------------------
                             58 	.area RSEG    (ABS,DATA)
   0000                      59 	.org 0x0000
                    0080     60 Fdynamixel$P0$0$0 == 0x0080
                    0080     61 _P0	=	0x0080
                    0081     62 Fdynamixel$SP$0$0 == 0x0081
                    0081     63 _SP	=	0x0081
                    0082     64 Fdynamixel$DPL0$0$0 == 0x0082
                    0082     65 _DPL0	=	0x0082
                    0083     66 Fdynamixel$DPH0$0$0 == 0x0083
                    0083     67 _DPH0	=	0x0083
                    0084     68 Fdynamixel$DPL1$0$0 == 0x0084
                    0084     69 _DPL1	=	0x0084
                    0085     70 Fdynamixel$DPH1$0$0 == 0x0085
                    0085     71 _DPH1	=	0x0085
                    0086     72 Fdynamixel$U0CSR$0$0 == 0x0086
                    0086     73 _U0CSR	=	0x0086
                    0087     74 Fdynamixel$PCON$0$0 == 0x0087
                    0087     75 _PCON	=	0x0087
                    0088     76 Fdynamixel$TCON$0$0 == 0x0088
                    0088     77 _TCON	=	0x0088
                    0089     78 Fdynamixel$P0IFG$0$0 == 0x0089
                    0089     79 _P0IFG	=	0x0089
                    008A     80 Fdynamixel$P1IFG$0$0 == 0x008a
                    008A     81 _P1IFG	=	0x008a
                    008B     82 Fdynamixel$P2IFG$0$0 == 0x008b
                    008B     83 _P2IFG	=	0x008b
                    008C     84 Fdynamixel$PICTL$0$0 == 0x008c
                    008C     85 _PICTL	=	0x008c
                    008D     86 Fdynamixel$P1IEN$0$0 == 0x008d
                    008D     87 _P1IEN	=	0x008d
                    008F     88 Fdynamixel$P0INP$0$0 == 0x008f
                    008F     89 _P0INP	=	0x008f
                    0090     90 Fdynamixel$P1$0$0 == 0x0090
                    0090     91 _P1	=	0x0090
                    0091     92 Fdynamixel$RFIM$0$0 == 0x0091
                    0091     93 _RFIM	=	0x0091
                    0092     94 Fdynamixel$DPS$0$0 == 0x0092
                    0092     95 _DPS	=	0x0092
                    0093     96 Fdynamixel$MPAGE$0$0 == 0x0093
                    0093     97 _MPAGE	=	0x0093
                    0095     98 Fdynamixel$ENDIAN$0$0 == 0x0095
                    0095     99 _ENDIAN	=	0x0095
                    0098    100 Fdynamixel$S0CON$0$0 == 0x0098
                    0098    101 _S0CON	=	0x0098
                    009A    102 Fdynamixel$IEN2$0$0 == 0x009a
                    009A    103 _IEN2	=	0x009a
                    009B    104 Fdynamixel$S1CON$0$0 == 0x009b
                    009B    105 _S1CON	=	0x009b
                    009C    106 Fdynamixel$T2CT$0$0 == 0x009c
                    009C    107 _T2CT	=	0x009c
                    009D    108 Fdynamixel$T2PR$0$0 == 0x009d
                    009D    109 _T2PR	=	0x009d
                    009E    110 Fdynamixel$T2CTL$0$0 == 0x009e
                    009E    111 _T2CTL	=	0x009e
                    00A0    112 Fdynamixel$P2$0$0 == 0x00a0
                    00A0    113 _P2	=	0x00a0
                    00A1    114 Fdynamixel$WORIRQ$0$0 == 0x00a1
                    00A1    115 _WORIRQ	=	0x00a1
                    00A2    116 Fdynamixel$WORCTRL$0$0 == 0x00a2
                    00A2    117 _WORCTRL	=	0x00a2
                    00A3    118 Fdynamixel$WOREVT0$0$0 == 0x00a3
                    00A3    119 _WOREVT0	=	0x00a3
                    00A4    120 Fdynamixel$WOREVT1$0$0 == 0x00a4
                    00A4    121 _WOREVT1	=	0x00a4
                    00A5    122 Fdynamixel$WORTIME0$0$0 == 0x00a5
                    00A5    123 _WORTIME0	=	0x00a5
                    00A6    124 Fdynamixel$WORTIME1$0$0 == 0x00a6
                    00A6    125 _WORTIME1	=	0x00a6
                    00A8    126 Fdynamixel$IEN0$0$0 == 0x00a8
                    00A8    127 _IEN0	=	0x00a8
                    00A9    128 Fdynamixel$IP0$0$0 == 0x00a9
                    00A9    129 _IP0	=	0x00a9
                    00AB    130 Fdynamixel$FWT$0$0 == 0x00ab
                    00AB    131 _FWT	=	0x00ab
                    00AC    132 Fdynamixel$FADDRL$0$0 == 0x00ac
                    00AC    133 _FADDRL	=	0x00ac
                    00AD    134 Fdynamixel$FADDRH$0$0 == 0x00ad
                    00AD    135 _FADDRH	=	0x00ad
                    00AE    136 Fdynamixel$FCTL$0$0 == 0x00ae
                    00AE    137 _FCTL	=	0x00ae
                    00AF    138 Fdynamixel$FWDATA$0$0 == 0x00af
                    00AF    139 _FWDATA	=	0x00af
                    00B1    140 Fdynamixel$ENCDI$0$0 == 0x00b1
                    00B1    141 _ENCDI	=	0x00b1
                    00B2    142 Fdynamixel$ENCDO$0$0 == 0x00b2
                    00B2    143 _ENCDO	=	0x00b2
                    00B3    144 Fdynamixel$ENCCS$0$0 == 0x00b3
                    00B3    145 _ENCCS	=	0x00b3
                    00B4    146 Fdynamixel$ADCCON1$0$0 == 0x00b4
                    00B4    147 _ADCCON1	=	0x00b4
                    00B5    148 Fdynamixel$ADCCON2$0$0 == 0x00b5
                    00B5    149 _ADCCON2	=	0x00b5
                    00B6    150 Fdynamixel$ADCCON3$0$0 == 0x00b6
                    00B6    151 _ADCCON3	=	0x00b6
                    00B8    152 Fdynamixel$IEN1$0$0 == 0x00b8
                    00B8    153 _IEN1	=	0x00b8
                    00B9    154 Fdynamixel$IP1$0$0 == 0x00b9
                    00B9    155 _IP1	=	0x00b9
                    00BA    156 Fdynamixel$ADCL$0$0 == 0x00ba
                    00BA    157 _ADCL	=	0x00ba
                    00BB    158 Fdynamixel$ADCH$0$0 == 0x00bb
                    00BB    159 _ADCH	=	0x00bb
                    00BC    160 Fdynamixel$RNDL$0$0 == 0x00bc
                    00BC    161 _RNDL	=	0x00bc
                    00BD    162 Fdynamixel$RNDH$0$0 == 0x00bd
                    00BD    163 _RNDH	=	0x00bd
                    00BE    164 Fdynamixel$SLEEP$0$0 == 0x00be
                    00BE    165 _SLEEP	=	0x00be
                    00C0    166 Fdynamixel$IRCON$0$0 == 0x00c0
                    00C0    167 _IRCON	=	0x00c0
                    00C1    168 Fdynamixel$U0DBUF$0$0 == 0x00c1
                    00C1    169 _U0DBUF	=	0x00c1
                    00C2    170 Fdynamixel$U0BAUD$0$0 == 0x00c2
                    00C2    171 _U0BAUD	=	0x00c2
                    00C4    172 Fdynamixel$U0UCR$0$0 == 0x00c4
                    00C4    173 _U0UCR	=	0x00c4
                    00C5    174 Fdynamixel$U0GCR$0$0 == 0x00c5
                    00C5    175 _U0GCR	=	0x00c5
                    00C6    176 Fdynamixel$CLKCON$0$0 == 0x00c6
                    00C6    177 _CLKCON	=	0x00c6
                    00C7    178 Fdynamixel$MEMCTR$0$0 == 0x00c7
                    00C7    179 _MEMCTR	=	0x00c7
                    00C9    180 Fdynamixel$WDCTL$0$0 == 0x00c9
                    00C9    181 _WDCTL	=	0x00c9
                    00CA    182 Fdynamixel$T3CNT$0$0 == 0x00ca
                    00CA    183 _T3CNT	=	0x00ca
                    00CB    184 Fdynamixel$T3CTL$0$0 == 0x00cb
                    00CB    185 _T3CTL	=	0x00cb
                    00CC    186 Fdynamixel$T3CCTL0$0$0 == 0x00cc
                    00CC    187 _T3CCTL0	=	0x00cc
                    00CD    188 Fdynamixel$T3CC0$0$0 == 0x00cd
                    00CD    189 _T3CC0	=	0x00cd
                    00CE    190 Fdynamixel$T3CCTL1$0$0 == 0x00ce
                    00CE    191 _T3CCTL1	=	0x00ce
                    00CF    192 Fdynamixel$T3CC1$0$0 == 0x00cf
                    00CF    193 _T3CC1	=	0x00cf
                    00D0    194 Fdynamixel$PSW$0$0 == 0x00d0
                    00D0    195 _PSW	=	0x00d0
                    00D1    196 Fdynamixel$DMAIRQ$0$0 == 0x00d1
                    00D1    197 _DMAIRQ	=	0x00d1
                    00D2    198 Fdynamixel$DMA1CFGL$0$0 == 0x00d2
                    00D2    199 _DMA1CFGL	=	0x00d2
                    00D3    200 Fdynamixel$DMA1CFGH$0$0 == 0x00d3
                    00D3    201 _DMA1CFGH	=	0x00d3
                    00D4    202 Fdynamixel$DMA0CFGL$0$0 == 0x00d4
                    00D4    203 _DMA0CFGL	=	0x00d4
                    00D5    204 Fdynamixel$DMA0CFGH$0$0 == 0x00d5
                    00D5    205 _DMA0CFGH	=	0x00d5
                    00D6    206 Fdynamixel$DMAARM$0$0 == 0x00d6
                    00D6    207 _DMAARM	=	0x00d6
                    00D7    208 Fdynamixel$DMAREQ$0$0 == 0x00d7
                    00D7    209 _DMAREQ	=	0x00d7
                    00D8    210 Fdynamixel$TIMIF$0$0 == 0x00d8
                    00D8    211 _TIMIF	=	0x00d8
                    00D9    212 Fdynamixel$RFD$0$0 == 0x00d9
                    00D9    213 _RFD	=	0x00d9
                    00DA    214 Fdynamixel$T1CC0L$0$0 == 0x00da
                    00DA    215 _T1CC0L	=	0x00da
                    00DB    216 Fdynamixel$T1CC0H$0$0 == 0x00db
                    00DB    217 _T1CC0H	=	0x00db
                    00DC    218 Fdynamixel$T1CC1L$0$0 == 0x00dc
                    00DC    219 _T1CC1L	=	0x00dc
                    00DD    220 Fdynamixel$T1CC1H$0$0 == 0x00dd
                    00DD    221 _T1CC1H	=	0x00dd
                    00DE    222 Fdynamixel$T1CC2L$0$0 == 0x00de
                    00DE    223 _T1CC2L	=	0x00de
                    00DF    224 Fdynamixel$T1CC2H$0$0 == 0x00df
                    00DF    225 _T1CC2H	=	0x00df
                    00E0    226 Fdynamixel$ACC$0$0 == 0x00e0
                    00E0    227 _ACC	=	0x00e0
                    00E1    228 Fdynamixel$RFST$0$0 == 0x00e1
                    00E1    229 _RFST	=	0x00e1
                    00E2    230 Fdynamixel$T1CNTL$0$0 == 0x00e2
                    00E2    231 _T1CNTL	=	0x00e2
                    00E3    232 Fdynamixel$T1CNTH$0$0 == 0x00e3
                    00E3    233 _T1CNTH	=	0x00e3
                    00E4    234 Fdynamixel$T1CTL$0$0 == 0x00e4
                    00E4    235 _T1CTL	=	0x00e4
                    00E5    236 Fdynamixel$T1CCTL0$0$0 == 0x00e5
                    00E5    237 _T1CCTL0	=	0x00e5
                    00E6    238 Fdynamixel$T1CCTL1$0$0 == 0x00e6
                    00E6    239 _T1CCTL1	=	0x00e6
                    00E7    240 Fdynamixel$T1CCTL2$0$0 == 0x00e7
                    00E7    241 _T1CCTL2	=	0x00e7
                    00E8    242 Fdynamixel$IRCON2$0$0 == 0x00e8
                    00E8    243 _IRCON2	=	0x00e8
                    00E9    244 Fdynamixel$RFIF$0$0 == 0x00e9
                    00E9    245 _RFIF	=	0x00e9
                    00EA    246 Fdynamixel$T4CNT$0$0 == 0x00ea
                    00EA    247 _T4CNT	=	0x00ea
                    00EB    248 Fdynamixel$T4CTL$0$0 == 0x00eb
                    00EB    249 _T4CTL	=	0x00eb
                    00EC    250 Fdynamixel$T4CCTL0$0$0 == 0x00ec
                    00EC    251 _T4CCTL0	=	0x00ec
                    00ED    252 Fdynamixel$T4CC0$0$0 == 0x00ed
                    00ED    253 _T4CC0	=	0x00ed
                    00EE    254 Fdynamixel$T4CCTL1$0$0 == 0x00ee
                    00EE    255 _T4CCTL1	=	0x00ee
                    00EF    256 Fdynamixel$T4CC1$0$0 == 0x00ef
                    00EF    257 _T4CC1	=	0x00ef
                    00F0    258 Fdynamixel$B$0$0 == 0x00f0
                    00F0    259 _B	=	0x00f0
                    00F1    260 Fdynamixel$PERCFG$0$0 == 0x00f1
                    00F1    261 _PERCFG	=	0x00f1
                    00F2    262 Fdynamixel$ADCCFG$0$0 == 0x00f2
                    00F2    263 _ADCCFG	=	0x00f2
                    00F3    264 Fdynamixel$P0SEL$0$0 == 0x00f3
                    00F3    265 _P0SEL	=	0x00f3
                    00F4    266 Fdynamixel$P1SEL$0$0 == 0x00f4
                    00F4    267 _P1SEL	=	0x00f4
                    00F5    268 Fdynamixel$P2SEL$0$0 == 0x00f5
                    00F5    269 _P2SEL	=	0x00f5
                    00F6    270 Fdynamixel$P1INP$0$0 == 0x00f6
                    00F6    271 _P1INP	=	0x00f6
                    00F7    272 Fdynamixel$P2INP$0$0 == 0x00f7
                    00F7    273 _P2INP	=	0x00f7
                    00F8    274 Fdynamixel$U1CSR$0$0 == 0x00f8
                    00F8    275 _U1CSR	=	0x00f8
                    00F9    276 Fdynamixel$U1DBUF$0$0 == 0x00f9
                    00F9    277 _U1DBUF	=	0x00f9
                    00FA    278 Fdynamixel$U1BAUD$0$0 == 0x00fa
                    00FA    279 _U1BAUD	=	0x00fa
                    00FB    280 Fdynamixel$U1UCR$0$0 == 0x00fb
                    00FB    281 _U1UCR	=	0x00fb
                    00FC    282 Fdynamixel$U1GCR$0$0 == 0x00fc
                    00FC    283 _U1GCR	=	0x00fc
                    00FD    284 Fdynamixel$P0DIR$0$0 == 0x00fd
                    00FD    285 _P0DIR	=	0x00fd
                    00FE    286 Fdynamixel$P1DIR$0$0 == 0x00fe
                    00FE    287 _P1DIR	=	0x00fe
                    00FF    288 Fdynamixel$P2DIR$0$0 == 0x00ff
                    00FF    289 _P2DIR	=	0x00ff
                    FFFFD5D4    290 Fdynamixel$DMA0CFG$0$0 == 0xffffd5d4
                    FFFFD5D4    291 _DMA0CFG	=	0xffffd5d4
                    FFFFD3D2    292 Fdynamixel$DMA1CFG$0$0 == 0xffffd3d2
                    FFFFD3D2    293 _DMA1CFG	=	0xffffd3d2
                    FFFFADAC    294 Fdynamixel$FADDR$0$0 == 0xffffadac
                    FFFFADAC    295 _FADDR	=	0xffffadac
                    FFFFBBBA    296 Fdynamixel$ADC$0$0 == 0xffffbbba
                    FFFFBBBA    297 _ADC	=	0xffffbbba
                    FFFFDBDA    298 Fdynamixel$T1CC0$0$0 == 0xffffdbda
                    FFFFDBDA    299 _T1CC0	=	0xffffdbda
                    FFFFDDDC    300 Fdynamixel$T1CC1$0$0 == 0xffffdddc
                    FFFFDDDC    301 _T1CC1	=	0xffffdddc
                    FFFFDFDE    302 Fdynamixel$T1CC2$0$0 == 0xffffdfde
                    FFFFDFDE    303 _T1CC2	=	0xffffdfde
                            304 ;--------------------------------------------------------
                            305 ; special function bits
                            306 ;--------------------------------------------------------
                            307 	.area RSEG    (ABS,DATA)
   0000                     308 	.org 0x0000
                    0080    309 Fdynamixel$P0_0$0$0 == 0x0080
                    0080    310 _P0_0	=	0x0080
                    0081    311 Fdynamixel$P0_1$0$0 == 0x0081
                    0081    312 _P0_1	=	0x0081
                    0082    313 Fdynamixel$P0_2$0$0 == 0x0082
                    0082    314 _P0_2	=	0x0082
                    0083    315 Fdynamixel$P0_3$0$0 == 0x0083
                    0083    316 _P0_3	=	0x0083
                    0084    317 Fdynamixel$P0_4$0$0 == 0x0084
                    0084    318 _P0_4	=	0x0084
                    0085    319 Fdynamixel$P0_5$0$0 == 0x0085
                    0085    320 _P0_5	=	0x0085
                    0086    321 Fdynamixel$P0_6$0$0 == 0x0086
                    0086    322 _P0_6	=	0x0086
                    0087    323 Fdynamixel$P0_7$0$0 == 0x0087
                    0087    324 _P0_7	=	0x0087
                    0088    325 Fdynamixel$_TCON_0$0$0 == 0x0088
                    0088    326 __TCON_0	=	0x0088
                    0089    327 Fdynamixel$RFTXRXIF$0$0 == 0x0089
                    0089    328 _RFTXRXIF	=	0x0089
                    008A    329 Fdynamixel$_TCON_2$0$0 == 0x008a
                    008A    330 __TCON_2	=	0x008a
                    008B    331 Fdynamixel$URX0IF$0$0 == 0x008b
                    008B    332 _URX0IF	=	0x008b
                    008C    333 Fdynamixel$_TCON_4$0$0 == 0x008c
                    008C    334 __TCON_4	=	0x008c
                    008D    335 Fdynamixel$ADCIF$0$0 == 0x008d
                    008D    336 _ADCIF	=	0x008d
                    008E    337 Fdynamixel$_TCON_6$0$0 == 0x008e
                    008E    338 __TCON_6	=	0x008e
                    008F    339 Fdynamixel$URX1IF$0$0 == 0x008f
                    008F    340 _URX1IF	=	0x008f
                    0090    341 Fdynamixel$P1_0$0$0 == 0x0090
                    0090    342 _P1_0	=	0x0090
                    0091    343 Fdynamixel$P1_1$0$0 == 0x0091
                    0091    344 _P1_1	=	0x0091
                    0092    345 Fdynamixel$P1_2$0$0 == 0x0092
                    0092    346 _P1_2	=	0x0092
                    0093    347 Fdynamixel$P1_3$0$0 == 0x0093
                    0093    348 _P1_3	=	0x0093
                    0094    349 Fdynamixel$P1_4$0$0 == 0x0094
                    0094    350 _P1_4	=	0x0094
                    0095    351 Fdynamixel$P1_5$0$0 == 0x0095
                    0095    352 _P1_5	=	0x0095
                    0096    353 Fdynamixel$P1_6$0$0 == 0x0096
                    0096    354 _P1_6	=	0x0096
                    0097    355 Fdynamixel$P1_7$0$0 == 0x0097
                    0097    356 _P1_7	=	0x0097
                    0098    357 Fdynamixel$ENCIF_0$0$0 == 0x0098
                    0098    358 _ENCIF_0	=	0x0098
                    0099    359 Fdynamixel$ENCIF_1$0$0 == 0x0099
                    0099    360 _ENCIF_1	=	0x0099
                    009A    361 Fdynamixel$_SOCON2$0$0 == 0x009a
                    009A    362 __SOCON2	=	0x009a
                    009B    363 Fdynamixel$_SOCON3$0$0 == 0x009b
                    009B    364 __SOCON3	=	0x009b
                    009C    365 Fdynamixel$_SOCON4$0$0 == 0x009c
                    009C    366 __SOCON4	=	0x009c
                    009D    367 Fdynamixel$_SOCON5$0$0 == 0x009d
                    009D    368 __SOCON5	=	0x009d
                    009E    369 Fdynamixel$_SOCON6$0$0 == 0x009e
                    009E    370 __SOCON6	=	0x009e
                    009F    371 Fdynamixel$_SOCON7$0$0 == 0x009f
                    009F    372 __SOCON7	=	0x009f
                    00A0    373 Fdynamixel$P2_0$0$0 == 0x00a0
                    00A0    374 _P2_0	=	0x00a0
                    00A1    375 Fdynamixel$P2_1$0$0 == 0x00a1
                    00A1    376 _P2_1	=	0x00a1
                    00A2    377 Fdynamixel$P2_2$0$0 == 0x00a2
                    00A2    378 _P2_2	=	0x00a2
                    00A3    379 Fdynamixel$P2_3$0$0 == 0x00a3
                    00A3    380 _P2_3	=	0x00a3
                    00A4    381 Fdynamixel$P2_4$0$0 == 0x00a4
                    00A4    382 _P2_4	=	0x00a4
                    00A5    383 Fdynamixel$P2_5$0$0 == 0x00a5
                    00A5    384 _P2_5	=	0x00a5
                    00A6    385 Fdynamixel$P2_6$0$0 == 0x00a6
                    00A6    386 _P2_6	=	0x00a6
                    00A7    387 Fdynamixel$P2_7$0$0 == 0x00a7
                    00A7    388 _P2_7	=	0x00a7
                    00A8    389 Fdynamixel$RFTXRXIE$0$0 == 0x00a8
                    00A8    390 _RFTXRXIE	=	0x00a8
                    00A9    391 Fdynamixel$ADCIE$0$0 == 0x00a9
                    00A9    392 _ADCIE	=	0x00a9
                    00AA    393 Fdynamixel$URX0IE$0$0 == 0x00aa
                    00AA    394 _URX0IE	=	0x00aa
                    00AB    395 Fdynamixel$URX1IE$0$0 == 0x00ab
                    00AB    396 _URX1IE	=	0x00ab
                    00AC    397 Fdynamixel$ENCIE$0$0 == 0x00ac
                    00AC    398 _ENCIE	=	0x00ac
                    00AD    399 Fdynamixel$STIE$0$0 == 0x00ad
                    00AD    400 _STIE	=	0x00ad
                    00AE    401 Fdynamixel$_IEN06$0$0 == 0x00ae
                    00AE    402 __IEN06	=	0x00ae
                    00AF    403 Fdynamixel$EA$0$0 == 0x00af
                    00AF    404 _EA	=	0x00af
                    00B8    405 Fdynamixel$DMAIE$0$0 == 0x00b8
                    00B8    406 _DMAIE	=	0x00b8
                    00B9    407 Fdynamixel$T1IE$0$0 == 0x00b9
                    00B9    408 _T1IE	=	0x00b9
                    00BA    409 Fdynamixel$T2IE$0$0 == 0x00ba
                    00BA    410 _T2IE	=	0x00ba
                    00BB    411 Fdynamixel$T3IE$0$0 == 0x00bb
                    00BB    412 _T3IE	=	0x00bb
                    00BC    413 Fdynamixel$T4IE$0$0 == 0x00bc
                    00BC    414 _T4IE	=	0x00bc
                    00BD    415 Fdynamixel$P0IE$0$0 == 0x00bd
                    00BD    416 _P0IE	=	0x00bd
                    00BE    417 Fdynamixel$_IEN16$0$0 == 0x00be
                    00BE    418 __IEN16	=	0x00be
                    00BF    419 Fdynamixel$_IEN17$0$0 == 0x00bf
                    00BF    420 __IEN17	=	0x00bf
                    00C0    421 Fdynamixel$DMAIF$0$0 == 0x00c0
                    00C0    422 _DMAIF	=	0x00c0
                    00C1    423 Fdynamixel$T1IF$0$0 == 0x00c1
                    00C1    424 _T1IF	=	0x00c1
                    00C2    425 Fdynamixel$T2IF$0$0 == 0x00c2
                    00C2    426 _T2IF	=	0x00c2
                    00C3    427 Fdynamixel$T3IF$0$0 == 0x00c3
                    00C3    428 _T3IF	=	0x00c3
                    00C4    429 Fdynamixel$T4IF$0$0 == 0x00c4
                    00C4    430 _T4IF	=	0x00c4
                    00C5    431 Fdynamixel$P0IF$0$0 == 0x00c5
                    00C5    432 _P0IF	=	0x00c5
                    00C6    433 Fdynamixel$_IRCON6$0$0 == 0x00c6
                    00C6    434 __IRCON6	=	0x00c6
                    00C7    435 Fdynamixel$STIF$0$0 == 0x00c7
                    00C7    436 _STIF	=	0x00c7
                    00D0    437 Fdynamixel$P$0$0 == 0x00d0
                    00D0    438 _P	=	0x00d0
                    00D1    439 Fdynamixel$F1$0$0 == 0x00d1
                    00D1    440 _F1	=	0x00d1
                    00D2    441 Fdynamixel$OV$0$0 == 0x00d2
                    00D2    442 _OV	=	0x00d2
                    00D3    443 Fdynamixel$RS0$0$0 == 0x00d3
                    00D3    444 _RS0	=	0x00d3
                    00D4    445 Fdynamixel$RS1$0$0 == 0x00d4
                    00D4    446 _RS1	=	0x00d4
                    00D5    447 Fdynamixel$F0$0$0 == 0x00d5
                    00D5    448 _F0	=	0x00d5
                    00D6    449 Fdynamixel$AC$0$0 == 0x00d6
                    00D6    450 _AC	=	0x00d6
                    00D7    451 Fdynamixel$CY$0$0 == 0x00d7
                    00D7    452 _CY	=	0x00d7
                    00D8    453 Fdynamixel$T3OVFIF$0$0 == 0x00d8
                    00D8    454 _T3OVFIF	=	0x00d8
                    00D9    455 Fdynamixel$T3CH0IF$0$0 == 0x00d9
                    00D9    456 _T3CH0IF	=	0x00d9
                    00DA    457 Fdynamixel$T3CH1IF$0$0 == 0x00da
                    00DA    458 _T3CH1IF	=	0x00da
                    00DB    459 Fdynamixel$T4OVFIF$0$0 == 0x00db
                    00DB    460 _T4OVFIF	=	0x00db
                    00DC    461 Fdynamixel$T4CH0IF$0$0 == 0x00dc
                    00DC    462 _T4CH0IF	=	0x00dc
                    00DD    463 Fdynamixel$T4CH1IF$0$0 == 0x00dd
                    00DD    464 _T4CH1IF	=	0x00dd
                    00DE    465 Fdynamixel$OVFIM$0$0 == 0x00de
                    00DE    466 _OVFIM	=	0x00de
                    00DF    467 Fdynamixel$_TIMIF7$0$0 == 0x00df
                    00DF    468 __TIMIF7	=	0x00df
                    00E0    469 Fdynamixel$ACC_0$0$0 == 0x00e0
                    00E0    470 _ACC_0	=	0x00e0
                    00E1    471 Fdynamixel$ACC_1$0$0 == 0x00e1
                    00E1    472 _ACC_1	=	0x00e1
                    00E2    473 Fdynamixel$ACC_2$0$0 == 0x00e2
                    00E2    474 _ACC_2	=	0x00e2
                    00E3    475 Fdynamixel$ACC_3$0$0 == 0x00e3
                    00E3    476 _ACC_3	=	0x00e3
                    00E4    477 Fdynamixel$ACC_4$0$0 == 0x00e4
                    00E4    478 _ACC_4	=	0x00e4
                    00E5    479 Fdynamixel$ACC_5$0$0 == 0x00e5
                    00E5    480 _ACC_5	=	0x00e5
                    00E6    481 Fdynamixel$ACC_6$0$0 == 0x00e6
                    00E6    482 _ACC_6	=	0x00e6
                    00E7    483 Fdynamixel$ACC_7$0$0 == 0x00e7
                    00E7    484 _ACC_7	=	0x00e7
                    00E8    485 Fdynamixel$P2IF$0$0 == 0x00e8
                    00E8    486 _P2IF	=	0x00e8
                    00E9    487 Fdynamixel$UTX0IF$0$0 == 0x00e9
                    00E9    488 _UTX0IF	=	0x00e9
                    00EA    489 Fdynamixel$UTX1IF$0$0 == 0x00ea
                    00EA    490 _UTX1IF	=	0x00ea
                    00EB    491 Fdynamixel$P1IF$0$0 == 0x00eb
                    00EB    492 _P1IF	=	0x00eb
                    00EC    493 Fdynamixel$WDTIF$0$0 == 0x00ec
                    00EC    494 _WDTIF	=	0x00ec
                    00ED    495 Fdynamixel$_IRCON25$0$0 == 0x00ed
                    00ED    496 __IRCON25	=	0x00ed
                    00EE    497 Fdynamixel$_IRCON26$0$0 == 0x00ee
                    00EE    498 __IRCON26	=	0x00ee
                    00EF    499 Fdynamixel$_IRCON27$0$0 == 0x00ef
                    00EF    500 __IRCON27	=	0x00ef
                    00F0    501 Fdynamixel$B_0$0$0 == 0x00f0
                    00F0    502 _B_0	=	0x00f0
                    00F1    503 Fdynamixel$B_1$0$0 == 0x00f1
                    00F1    504 _B_1	=	0x00f1
                    00F2    505 Fdynamixel$B_2$0$0 == 0x00f2
                    00F2    506 _B_2	=	0x00f2
                    00F3    507 Fdynamixel$B_3$0$0 == 0x00f3
                    00F3    508 _B_3	=	0x00f3
                    00F4    509 Fdynamixel$B_4$0$0 == 0x00f4
                    00F4    510 _B_4	=	0x00f4
                    00F5    511 Fdynamixel$B_5$0$0 == 0x00f5
                    00F5    512 _B_5	=	0x00f5
                    00F6    513 Fdynamixel$B_6$0$0 == 0x00f6
                    00F6    514 _B_6	=	0x00f6
                    00F7    515 Fdynamixel$B_7$0$0 == 0x00f7
                    00F7    516 _B_7	=	0x00f7
                    00F8    517 Fdynamixel$U1ACTIVE$0$0 == 0x00f8
                    00F8    518 _U1ACTIVE	=	0x00f8
                    00F9    519 Fdynamixel$U1TX_BYTE$0$0 == 0x00f9
                    00F9    520 _U1TX_BYTE	=	0x00f9
                    00FA    521 Fdynamixel$U1RX_BYTE$0$0 == 0x00fa
                    00FA    522 _U1RX_BYTE	=	0x00fa
                    00FB    523 Fdynamixel$U1ERR$0$0 == 0x00fb
                    00FB    524 _U1ERR	=	0x00fb
                    00FC    525 Fdynamixel$U1FE$0$0 == 0x00fc
                    00FC    526 _U1FE	=	0x00fc
                    00FD    527 Fdynamixel$U1SLAVE$0$0 == 0x00fd
                    00FD    528 _U1SLAVE	=	0x00fd
                    00FE    529 Fdynamixel$U1RE$0$0 == 0x00fe
                    00FE    530 _U1RE	=	0x00fe
                    00FF    531 Fdynamixel$U1MODE$0$0 == 0x00ff
                    00FF    532 _U1MODE	=	0x00ff
                            533 ;--------------------------------------------------------
                            534 ; overlayable register banks
                            535 ;--------------------------------------------------------
                            536 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     537 	.ds 8
                            538 ;--------------------------------------------------------
                            539 ; internal ram data
                            540 ;--------------------------------------------------------
                            541 	.area DSEG    (DATA)
                    0000    542 Ldynamixel.dynamixel_txrx$sloc0$1$0==.
   0008                     543 _dynamixel_txrx_sloc0_1_0:
   0008                     544 	.ds 3
                    0003    545 Ldynamixel.dynamixel_readword$sloc0$1$0==.
   000B                     546 _dynamixel_readword_sloc0_1_0:
   000B                     547 	.ds 1
                            548 ;--------------------------------------------------------
                            549 ; overlayable items in internal ram 
                            550 ;--------------------------------------------------------
                            551 	.area	OSEG    (OVR,DATA)
                    0000    552 Ldynamixel.dynamixel_calculatechecksum$sloc0$1$0==.
   002F                     553 _dynamixel_calculatechecksum_sloc0_1_0:
   002F                     554 	.ds 2
                            555 ;--------------------------------------------------------
                            556 ; indirectly addressable internal ram data
                            557 ;--------------------------------------------------------
                            558 	.area ISEG    (DATA)
                            559 ;--------------------------------------------------------
                            560 ; absolute internal ram data
                            561 ;--------------------------------------------------------
                            562 	.area IABS    (ABS,DATA)
                            563 	.area IABS    (ABS,DATA)
                            564 ;--------------------------------------------------------
                            565 ; bit data
                            566 ;--------------------------------------------------------
                            567 	.area BSEG    (BIT)
                            568 ;--------------------------------------------------------
                            569 ; paged external ram data
                            570 ;--------------------------------------------------------
                            571 	.area PSEG    (PAG,XDATA)
                    0000    572 G$dynamixel_txpacket$0$0==.
   F000                     573 _dynamixel_txpacket::
   F000                     574 	.ds 3
                    0003    575 G$dynamixel_rxpacket$0$0==.
   F003                     576 _dynamixel_rxpacket::
   F003                     577 	.ds 3
                    0006    578 G$dynamixel_rxindex$0$0==.
   F006                     579 _dynamixel_rxindex::
   F006                     580 	.ds 1
                    0007    581 Ldynamixel.dynamixel_calculatechecksum$packet$1$1==.
   F007                     582 _dynamixel_calculatechecksum_packet_1_1:
   F007                     583 	.ds 3
                    000A    584 Ldynamixel.dynamixel_calculatechecksum$i$1$1==.
   F00A                     585 _dynamixel_calculatechecksum_i_1_1:
   F00A                     586 	.ds 1
                    000B    587 Ldynamixel.dynamixel_writepacket$packetlength$1$1==.
   F00B                     588 _dynamixel_writepacket_PARM_2:
   F00B                     589 	.ds 1
                    000C    590 Ldynamixel.dynamixel_writepacket$txpacket$1$1==.
   F00C                     591 _dynamixel_writepacket_txpacket_1_1:
   F00C                     592 	.ds 3
                    000F    593 Ldynamixel.dynamixel_readpacket$packetlength$1$1==.
   F00F                     594 _dynamixel_readpacket_PARM_2:
   F00F                     595 	.ds 1
                    0010    596 Ldynamixel.dynamixel_readpacket$rxpacket$1$1==.
   F010                     597 _dynamixel_readpacket_rxpacket_1_1:
   F010                     598 	.ds 3
                    0013    599 Ldynamixel.dynamixel_txrx$rxpacket$1$1==.
   F013                     600 _dynamixel_txrx_PARM_2:
   F013                     601 	.ds 3
                    0016    602 Ldynamixel.dynamixel_txrx$txpacket$1$1==.
   F016                     603 _dynamixel_txrx_txpacket_1_1:
   F016                     604 	.ds 3
                    0019    605 Ldynamixel.dynamixel_txrx$txlength$1$1==.
   F019                     606 _dynamixel_txrx_txlength_1_1:
   F019                     607 	.ds 1
                    001A    608 Ldynamixel.dynamixel_readbyte$address$1$1==.
   F01A                     609 _dynamixel_readbyte_PARM_2:
   F01A                     610 	.ds 1
                    001B    611 Ldynamixel.dynamixel_readbyte$value$1$1==.
   F01B                     612 _dynamixel_readbyte_PARM_3:
   F01B                     613 	.ds 3
                    001E    614 Ldynamixel.dynamixel_readword$address$1$1==.
   F01E                     615 _dynamixel_readword_PARM_2:
   F01E                     616 	.ds 1
                    001F    617 Ldynamixel.dynamixel_readword$value$1$1==.
   F01F                     618 _dynamixel_readword_PARM_3:
   F01F                     619 	.ds 3
                    0022    620 Ldynamixel.dynamixel_readtable$start_address$1$1==.
   F022                     621 _dynamixel_readtable_PARM_2:
   F022                     622 	.ds 1
                    0023    623 Ldynamixel.dynamixel_readtable$end_address$1$1==.
   F023                     624 _dynamixel_readtable_PARM_3:
   F023                     625 	.ds 1
                    0024    626 Ldynamixel.dynamixel_readtable$table$1$1==.
   F024                     627 _dynamixel_readtable_PARM_4:
   F024                     628 	.ds 3
                    0027    629 Ldynamixel.dynamixel_readtable$length$1$1==.
   F027                     630 _dynamixel_readtable_length_1_1:
   F027                     631 	.ds 1
                    0028    632 Ldynamixel.dynamixel_readtable$i$2$2==.
   F028                     633 _dynamixel_readtable_i_2_2:
   F028                     634 	.ds 1
                    0029    635 Ldynamixel.dynamixel_writebyte$address$1$1==.
   F029                     636 _dynamixel_writebyte_PARM_2:
   F029                     637 	.ds 1
                    002A    638 Ldynamixel.dynamixel_writebyte$value$1$1==.
   F02A                     639 _dynamixel_writebyte_PARM_3:
   F02A                     640 	.ds 1
                    002B    641 Ldynamixel.dynamixel_writeword$address$1$1==.
   F02B                     642 _dynamixel_writeword_PARM_2:
   F02B                     643 	.ds 1
                    002C    644 Ldynamixel.dynamixel_writeword$value$1$1==.
   F02C                     645 _dynamixel_writeword_PARM_3:
   F02C                     646 	.ds 2
                    002E    647 Ldynamixel.dynamixel_syncwrite$length$1$1==.
   F02E                     648 _dynamixel_syncwrite_PARM_2:
   F02E                     649 	.ds 1
                    002F    650 Ldynamixel.dynamixel_syncwrite$number$1$1==.
   F02F                     651 _dynamixel_syncwrite_PARM_3:
   F02F                     652 	.ds 1
                    0030    653 Ldynamixel.dynamixel_syncwrite$param$1$1==.
   F030                     654 _dynamixel_syncwrite_PARM_4:
   F030                     655 	.ds 3
                    0033    656 Ldynamixel.dynamixel_syncwrite$i$1$1==.
   F033                     657 _dynamixel_syncwrite_i_1_1:
   F033                     658 	.ds 1
                    0034    659 Ldynamixel.dynamixel_makeword$highbyte$1$1==.
   F034                     660 _dynamixel_makeword_PARM_2:
   F034                     661 	.ds 1
                            662 ;--------------------------------------------------------
                            663 ; external ram data
                            664 ;--------------------------------------------------------
                            665 	.area XSEG    (XDATA)
                    DF00    666 Fdynamixel$SYNC1$0$0 == 0xdf00
                    DF00    667 _SYNC1	=	0xdf00
                    DF01    668 Fdynamixel$SYNC0$0$0 == 0xdf01
                    DF01    669 _SYNC0	=	0xdf01
                    DF02    670 Fdynamixel$PKTLEN$0$0 == 0xdf02
                    DF02    671 _PKTLEN	=	0xdf02
                    DF03    672 Fdynamixel$PKTCTRL1$0$0 == 0xdf03
                    DF03    673 _PKTCTRL1	=	0xdf03
                    DF04    674 Fdynamixel$PKTCTRL0$0$0 == 0xdf04
                    DF04    675 _PKTCTRL0	=	0xdf04
                    DF05    676 Fdynamixel$ADDR$0$0 == 0xdf05
                    DF05    677 _ADDR	=	0xdf05
                    DF06    678 Fdynamixel$CHANNR$0$0 == 0xdf06
                    DF06    679 _CHANNR	=	0xdf06
                    DF07    680 Fdynamixel$FSCTRL1$0$0 == 0xdf07
                    DF07    681 _FSCTRL1	=	0xdf07
                    DF08    682 Fdynamixel$FSCTRL0$0$0 == 0xdf08
                    DF08    683 _FSCTRL0	=	0xdf08
                    DF09    684 Fdynamixel$FREQ2$0$0 == 0xdf09
                    DF09    685 _FREQ2	=	0xdf09
                    DF0A    686 Fdynamixel$FREQ1$0$0 == 0xdf0a
                    DF0A    687 _FREQ1	=	0xdf0a
                    DF0B    688 Fdynamixel$FREQ0$0$0 == 0xdf0b
                    DF0B    689 _FREQ0	=	0xdf0b
                    DF0C    690 Fdynamixel$MDMCFG4$0$0 == 0xdf0c
                    DF0C    691 _MDMCFG4	=	0xdf0c
                    DF0D    692 Fdynamixel$MDMCFG3$0$0 == 0xdf0d
                    DF0D    693 _MDMCFG3	=	0xdf0d
                    DF0E    694 Fdynamixel$MDMCFG2$0$0 == 0xdf0e
                    DF0E    695 _MDMCFG2	=	0xdf0e
                    DF0F    696 Fdynamixel$MDMCFG1$0$0 == 0xdf0f
                    DF0F    697 _MDMCFG1	=	0xdf0f
                    DF10    698 Fdynamixel$MDMCFG0$0$0 == 0xdf10
                    DF10    699 _MDMCFG0	=	0xdf10
                    DF11    700 Fdynamixel$DEVIATN$0$0 == 0xdf11
                    DF11    701 _DEVIATN	=	0xdf11
                    DF12    702 Fdynamixel$MCSM2$0$0 == 0xdf12
                    DF12    703 _MCSM2	=	0xdf12
                    DF13    704 Fdynamixel$MCSM1$0$0 == 0xdf13
                    DF13    705 _MCSM1	=	0xdf13
                    DF14    706 Fdynamixel$MCSM0$0$0 == 0xdf14
                    DF14    707 _MCSM0	=	0xdf14
                    DF15    708 Fdynamixel$FOCCFG$0$0 == 0xdf15
                    DF15    709 _FOCCFG	=	0xdf15
                    DF16    710 Fdynamixel$BSCFG$0$0 == 0xdf16
                    DF16    711 _BSCFG	=	0xdf16
                    DF17    712 Fdynamixel$AGCCTRL2$0$0 == 0xdf17
                    DF17    713 _AGCCTRL2	=	0xdf17
                    DF18    714 Fdynamixel$AGCCTRL1$0$0 == 0xdf18
                    DF18    715 _AGCCTRL1	=	0xdf18
                    DF19    716 Fdynamixel$AGCCTRL0$0$0 == 0xdf19
                    DF19    717 _AGCCTRL0	=	0xdf19
                    DF1A    718 Fdynamixel$FREND1$0$0 == 0xdf1a
                    DF1A    719 _FREND1	=	0xdf1a
                    DF1B    720 Fdynamixel$FREND0$0$0 == 0xdf1b
                    DF1B    721 _FREND0	=	0xdf1b
                    DF1C    722 Fdynamixel$FSCAL3$0$0 == 0xdf1c
                    DF1C    723 _FSCAL3	=	0xdf1c
                    DF1D    724 Fdynamixel$FSCAL2$0$0 == 0xdf1d
                    DF1D    725 _FSCAL2	=	0xdf1d
                    DF1E    726 Fdynamixel$FSCAL1$0$0 == 0xdf1e
                    DF1E    727 _FSCAL1	=	0xdf1e
                    DF1F    728 Fdynamixel$FSCAL0$0$0 == 0xdf1f
                    DF1F    729 _FSCAL0	=	0xdf1f
                    DF23    730 Fdynamixel$TEST2$0$0 == 0xdf23
                    DF23    731 _TEST2	=	0xdf23
                    DF24    732 Fdynamixel$TEST1$0$0 == 0xdf24
                    DF24    733 _TEST1	=	0xdf24
                    DF25    734 Fdynamixel$TEST0$0$0 == 0xdf25
                    DF25    735 _TEST0	=	0xdf25
                    DF2E    736 Fdynamixel$PA_TABLE0$0$0 == 0xdf2e
                    DF2E    737 _PA_TABLE0	=	0xdf2e
                    DF2F    738 Fdynamixel$IOCFG2$0$0 == 0xdf2f
                    DF2F    739 _IOCFG2	=	0xdf2f
                    DF30    740 Fdynamixel$IOCFG1$0$0 == 0xdf30
                    DF30    741 _IOCFG1	=	0xdf30
                    DF31    742 Fdynamixel$IOCFG0$0$0 == 0xdf31
                    DF31    743 _IOCFG0	=	0xdf31
                    DF36    744 Fdynamixel$PARTNUM$0$0 == 0xdf36
                    DF36    745 _PARTNUM	=	0xdf36
                    DF37    746 Fdynamixel$VERSION$0$0 == 0xdf37
                    DF37    747 _VERSION	=	0xdf37
                    DF38    748 Fdynamixel$FREQEST$0$0 == 0xdf38
                    DF38    749 _FREQEST	=	0xdf38
                    DF39    750 Fdynamixel$LQI$0$0 == 0xdf39
                    DF39    751 _LQI	=	0xdf39
                    DF3A    752 Fdynamixel$RSSI$0$0 == 0xdf3a
                    DF3A    753 _RSSI	=	0xdf3a
                    DF3B    754 Fdynamixel$MARCSTATE$0$0 == 0xdf3b
                    DF3B    755 _MARCSTATE	=	0xdf3b
                    DF3C    756 Fdynamixel$PKTSTATUS$0$0 == 0xdf3c
                    DF3C    757 _PKTSTATUS	=	0xdf3c
                    DF3D    758 Fdynamixel$VCO_VC_DAC$0$0 == 0xdf3d
                    DF3D    759 _VCO_VC_DAC	=	0xdf3d
                    DF40    760 Fdynamixel$I2SCFG0$0$0 == 0xdf40
                    DF40    761 _I2SCFG0	=	0xdf40
                    DF41    762 Fdynamixel$I2SCFG1$0$0 == 0xdf41
                    DF41    763 _I2SCFG1	=	0xdf41
                    DF42    764 Fdynamixel$I2SDATL$0$0 == 0xdf42
                    DF42    765 _I2SDATL	=	0xdf42
                    DF43    766 Fdynamixel$I2SDATH$0$0 == 0xdf43
                    DF43    767 _I2SDATH	=	0xdf43
                    DF44    768 Fdynamixel$I2SWCNT$0$0 == 0xdf44
                    DF44    769 _I2SWCNT	=	0xdf44
                    DF45    770 Fdynamixel$I2SSTAT$0$0 == 0xdf45
                    DF45    771 _I2SSTAT	=	0xdf45
                    DF46    772 Fdynamixel$I2SCLKF0$0$0 == 0xdf46
                    DF46    773 _I2SCLKF0	=	0xdf46
                    DF47    774 Fdynamixel$I2SCLKF1$0$0 == 0xdf47
                    DF47    775 _I2SCLKF1	=	0xdf47
                    DF48    776 Fdynamixel$I2SCLKF2$0$0 == 0xdf48
                    DF48    777 _I2SCLKF2	=	0xdf48
                    DE00    778 Fdynamixel$USBADDR$0$0 == 0xde00
                    DE00    779 _USBADDR	=	0xde00
                    DE01    780 Fdynamixel$USBPOW$0$0 == 0xde01
                    DE01    781 _USBPOW	=	0xde01
                    DE02    782 Fdynamixel$USBIIF$0$0 == 0xde02
                    DE02    783 _USBIIF	=	0xde02
                    DE04    784 Fdynamixel$USBOIF$0$0 == 0xde04
                    DE04    785 _USBOIF	=	0xde04
                    DE06    786 Fdynamixel$USBCIF$0$0 == 0xde06
                    DE06    787 _USBCIF	=	0xde06
                    DE07    788 Fdynamixel$USBIIE$0$0 == 0xde07
                    DE07    789 _USBIIE	=	0xde07
                    DE09    790 Fdynamixel$USBOIE$0$0 == 0xde09
                    DE09    791 _USBOIE	=	0xde09
                    DE0B    792 Fdynamixel$USBCIE$0$0 == 0xde0b
                    DE0B    793 _USBCIE	=	0xde0b
                    DE0C    794 Fdynamixel$USBFRML$0$0 == 0xde0c
                    DE0C    795 _USBFRML	=	0xde0c
                    DE0D    796 Fdynamixel$USBFRMH$0$0 == 0xde0d
                    DE0D    797 _USBFRMH	=	0xde0d
                    DE0E    798 Fdynamixel$USBINDEX$0$0 == 0xde0e
                    DE0E    799 _USBINDEX	=	0xde0e
                    DE10    800 Fdynamixel$USBMAXI$0$0 == 0xde10
                    DE10    801 _USBMAXI	=	0xde10
                    DE11    802 Fdynamixel$USBCSIL$0$0 == 0xde11
                    DE11    803 _USBCSIL	=	0xde11
                    DE12    804 Fdynamixel$USBCSIH$0$0 == 0xde12
                    DE12    805 _USBCSIH	=	0xde12
                    DE13    806 Fdynamixel$USBMAXO$0$0 == 0xde13
                    DE13    807 _USBMAXO	=	0xde13
                    DE14    808 Fdynamixel$USBCSOL$0$0 == 0xde14
                    DE14    809 _USBCSOL	=	0xde14
                    DE15    810 Fdynamixel$USBCSOH$0$0 == 0xde15
                    DE15    811 _USBCSOH	=	0xde15
                    DE16    812 Fdynamixel$USBCNTL$0$0 == 0xde16
                    DE16    813 _USBCNTL	=	0xde16
                    DE17    814 Fdynamixel$USBCNTH$0$0 == 0xde17
                    DE17    815 _USBCNTH	=	0xde17
                    DE20    816 Fdynamixel$USBF0$0$0 == 0xde20
                    DE20    817 _USBF0	=	0xde20
                    DE22    818 Fdynamixel$USBF1$0$0 == 0xde22
                    DE22    819 _USBF1	=	0xde22
                    DE24    820 Fdynamixel$USBF2$0$0 == 0xde24
                    DE24    821 _USBF2	=	0xde24
                    DE26    822 Fdynamixel$USBF3$0$0 == 0xde26
                    DE26    823 _USBF3	=	0xde26
                    DE28    824 Fdynamixel$USBF4$0$0 == 0xde28
                    DE28    825 _USBF4	=	0xde28
                    DE2A    826 Fdynamixel$USBF5$0$0 == 0xde2a
                    DE2A    827 _USBF5	=	0xde2a
                            828 ;--------------------------------------------------------
                            829 ; absolute external ram data
                            830 ;--------------------------------------------------------
                            831 	.area XABS    (ABS,XDATA)
                            832 ;--------------------------------------------------------
                            833 ; external initialized ram data
                            834 ;--------------------------------------------------------
                            835 	.area XISEG   (XDATA)
                            836 	.area HOME    (CODE)
                            837 	.area GSINIT0 (CODE)
                            838 	.area GSINIT1 (CODE)
                            839 	.area GSINIT2 (CODE)
                            840 	.area GSINIT3 (CODE)
                            841 	.area GSINIT4 (CODE)
                            842 	.area GSINIT5 (CODE)
                            843 	.area GSINIT  (CODE)
                            844 	.area GSFINAL (CODE)
                            845 	.area CSEG    (CODE)
                            846 ;--------------------------------------------------------
                            847 ; global & static initialisations
                            848 ;--------------------------------------------------------
                            849 	.area HOME    (CODE)
                            850 	.area GSINIT  (CODE)
                            851 	.area GSFINAL (CODE)
                            852 	.area GSINIT  (CODE)
                    0000    853 	G$dynamixel_gethighbyte$0$0 ==.
                    0000    854 	C$dynamixel.c$14$1$1 ==.
                            855 ;	apps/dynamixel_test/dynamixel.c:14: volatile uint8 dynamixel_rxindex = 0;
   04D4 78 06               856 	mov	r0,#_dynamixel_rxindex
   04D6 E4                  857 	clr	a
   04D7 F2                  858 	movx	@r0,a
                            859 ;--------------------------------------------------------
                            860 ; Home
                            861 ;--------------------------------------------------------
                            862 	.area HOME    (CODE)
                            863 	.area HOME    (CODE)
                            864 ;--------------------------------------------------------
                            865 ; code
                            866 ;--------------------------------------------------------
                            867 	.area CSEG    (CODE)
                            868 ;------------------------------------------------------------
                            869 ;Allocation info for local variables in function 'dynamixel_init'
                            870 ;------------------------------------------------------------
                    0000    871 	G$dynamixel_init$0$0 ==.
                    0000    872 	C$dynamixel.c$30$0$0 ==.
                            873 ;	apps/dynamixel_test/dynamixel.c:30: void dynamixel_init(void)
                            874 ;	-----------------------------------------
                            875 ;	 function dynamixel_init
                            876 ;	-----------------------------------------
   04EE                     877 _dynamixel_init:
                    0007    878 	ar7 = 0x07
                    0006    879 	ar6 = 0x06
                    0005    880 	ar5 = 0x05
                    0004    881 	ar4 = 0x04
                    0003    882 	ar3 = 0x03
                    0002    883 	ar2 = 0x02
                    0001    884 	ar1 = 0x01
                    0000    885 	ar0 = 0x00
                    0000    886 	C$dynamixel.c$48$1$1 ==.
                            887 ;	apps/dynamixel_test/dynamixel.c:48: dynamixel_rxindex = 0;
   04EE 78 06               888 	mov	r0,#_dynamixel_rxindex
   04F0 E4                  889 	clr	a
   04F1 F2                  890 	movx	@r0,a
                    0004    891 	C$dynamixel.c$51$1$1 ==.
                            892 ;	apps/dynamixel_test/dynamixel.c:51: dynamixel_txpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   04F2 90 00 80            893 	mov	dptr,#0x0080
   04F5 12 18 02            894 	lcall	_malloc
   04F8 AE 82               895 	mov	r6,dpl
   04FA AF 83               896 	mov	r7,dph
   04FC 78 00               897 	mov	r0,#_dynamixel_txpacket
   04FE EE                  898 	mov	a,r6
   04FF F2                  899 	movx	@r0,a
   0500 08                  900 	inc	r0
   0501 EF                  901 	mov	a,r7
   0502 F2                  902 	movx	@r0,a
   0503 08                  903 	inc	r0
   0504 E4                  904 	clr	a
   0505 F2                  905 	movx	@r0,a
                    0018    906 	C$dynamixel.c$52$1$1 ==.
                            907 ;	apps/dynamixel_test/dynamixel.c:52: dynamixel_rxpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   0506 90 00 80            908 	mov	dptr,#0x0080
   0509 12 18 02            909 	lcall	_malloc
   050C AE 82               910 	mov	r6,dpl
   050E AF 83               911 	mov	r7,dph
   0510 78 03               912 	mov	r0,#_dynamixel_rxpacket
   0512 EE                  913 	mov	a,r6
   0513 F2                  914 	movx	@r0,a
   0514 08                  915 	inc	r0
   0515 EF                  916 	mov	a,r7
   0516 F2                  917 	movx	@r0,a
   0517 08                  918 	inc	r0
   0518 E4                  919 	clr	a
   0519 F2                  920 	movx	@r0,a
                    002C    921 	C$dynamixel.c$54$1$1 ==.
                    002C    922 	XG$dynamixel_init$0$0 ==.
   051A 22                  923 	ret
                            924 ;------------------------------------------------------------
                            925 ;Allocation info for local variables in function 'dynamixel_settx'
                            926 ;------------------------------------------------------------
                    002D    927 	G$dynamixel_settx$0$0 ==.
                    002D    928 	C$dynamixel.c$56$1$1 ==.
                            929 ;	apps/dynamixel_test/dynamixel.c:56: void dynamixel_settx(void)
                            930 ;	-----------------------------------------
                            931 ;	 function dynamixel_settx
                            932 ;	-----------------------------------------
   051B                     933 _dynamixel_settx:
                    002D    934 	C$dynamixel.c$61$1$1 ==.
                            935 ;	apps/dynamixel_test/dynamixel.c:61: P1DIR &= ~0x02; //Disable pin P1_1
   051B AF FE               936 	mov	r7,_P1DIR
   051D 53 07 FD            937 	anl	ar7,#0xFD
   0520 8F FE               938 	mov	_P1DIR,r7
                    0034    939 	C$dynamixel.c$62$1$1 ==.
                            940 ;	apps/dynamixel_test/dynamixel.c:62: P1DIR |= 0x20; //Enable pin P1_5
   0522 43 FE 20            941 	orl	_P1DIR,#0x20
                    0037    942 	C$dynamixel.c$68$1$1 ==.
                    0037    943 	XG$dynamixel_settx$0$0 ==.
   0525 22                  944 	ret
                            945 ;------------------------------------------------------------
                            946 ;Allocation info for local variables in function 'dynamixel_setrx'
                            947 ;------------------------------------------------------------
                    0038    948 	G$dynamixel_setrx$0$0 ==.
                    0038    949 	C$dynamixel.c$70$1$1 ==.
                            950 ;	apps/dynamixel_test/dynamixel.c:70: void dynamixel_setrx(void)
                            951 ;	-----------------------------------------
                            952 ;	 function dynamixel_setrx
                            953 ;	-----------------------------------------
   0526                     954 _dynamixel_setrx:
                    0038    955 	C$dynamixel.c$78$1$1 ==.
                            956 ;	apps/dynamixel_test/dynamixel.c:78: delayMicroseconds(1);
   0526 75 82 01            957 	mov	dpl,#0x01
   0529 12 17 A9            958 	lcall	_delayMicroseconds
                    003E    959 	C$dynamixel.c$88$1$1 ==.
                            960 ;	apps/dynamixel_test/dynamixel.c:88: P1DIR &= ~0x20; //Disable pin P1_5
   052C AF FE               961 	mov	r7,_P1DIR
   052E 53 07 DF            962 	anl	ar7,#0xDF
   0531 8F FE               963 	mov	_P1DIR,r7
                    0045    964 	C$dynamixel.c$89$1$1 ==.
                            965 ;	apps/dynamixel_test/dynamixel.c:89: P1DIR |= 0x02; //Enable pin P1_1
   0533 43 FE 02            966 	orl	_P1DIR,#0x02
                    0048    967 	C$dynamixel.c$97$1$1 ==.
                            968 ;	apps/dynamixel_test/dynamixel.c:97: dynamixel_rxindex = 0;
   0536 78 06               969 	mov	r0,#_dynamixel_rxindex
   0538 E4                  970 	clr	a
   0539 F2                  971 	movx	@r0,a
                    004C    972 	C$dynamixel.c$98$1$1 ==.
                    004C    973 	XG$dynamixel_setrx$0$0 ==.
   053A 22                  974 	ret
                            975 ;------------------------------------------------------------
                            976 ;Allocation info for local variables in function 'dynamixel_write'
                            977 ;------------------------------------------------------------
                    004D    978 	G$dynamixel_write$0$0 ==.
                    004D    979 	C$dynamixel.c$100$1$1 ==.
                            980 ;	apps/dynamixel_test/dynamixel.c:100: void dynamixel_write(uint8 c)
                            981 ;	-----------------------------------------
                            982 ;	 function dynamixel_write
                            983 ;	-----------------------------------------
   053B                     984 _dynamixel_write:
                    004D    985 	C$dynamixel.c$115$1$1 ==.
                            986 ;	apps/dynamixel_test/dynamixel.c:115: uart1TxSendByte(c);
   053B 12 14 62            987 	lcall	_uart1TxSendByte
                    0050    988 	C$dynamixel.c$116$1$1 ==.
                    0050    989 	XG$dynamixel_write$0$0 ==.
   053E 22                  990 	ret
                            991 ;------------------------------------------------------------
                            992 ;Allocation info for local variables in function 'dynamixel_calculatechecksum'
                            993 ;------------------------------------------------------------
                            994 ;sloc0                     Allocated with name '_dynamixel_calculatechecksum_sloc0_1_0'
                            995 ;------------------------------------------------------------
                    0051    996 	G$dynamixel_calculatechecksum$0$0 ==.
                    0051    997 	C$dynamixel.c$118$1$1 ==.
                            998 ;	apps/dynamixel_test/dynamixel.c:118: uint8 dynamixel_calculatechecksum(volatile uint8* packet)
                            999 ;	-----------------------------------------
                           1000 ;	 function dynamixel_calculatechecksum
                           1001 ;	-----------------------------------------
   053F                    1002 _dynamixel_calculatechecksum:
   053F AF F0              1003 	mov	r7,b
   0541 AE 83              1004 	mov	r6,dph
   0543 E5 82              1005 	mov	a,dpl
   0545 78 07              1006 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   0547 F2                 1007 	movx	@r0,a
   0548 08                 1008 	inc	r0
   0549 EE                 1009 	mov	a,r6
   054A F2                 1010 	movx	@r0,a
   054B 08                 1011 	inc	r0
   054C EF                 1012 	mov	a,r7
   054D F2                 1013 	movx	@r0,a
                    0060   1014 	C$dynamixel.c$121$1$1 ==.
                           1015 ;	apps/dynamixel_test/dynamixel.c:121: uint16 checksum = 0;
   054E 7E 00              1016 	mov	r6,#0x00
   0550 7F 00              1017 	mov	r7,#0x00
                    0064   1018 	C$dynamixel.c$123$1$1 ==.
                           1019 ;	apps/dynamixel_test/dynamixel.c:123: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   0552 78 07              1020 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   0554 E2                 1021 	movx	a,@r0
   0555 24 03              1022 	add	a,#0x03
   0557 FB                 1023 	mov	r3,a
   0558 08                 1024 	inc	r0
   0559 E2                 1025 	movx	a,@r0
   055A 34 00              1026 	addc	a,#0x00
   055C FC                 1027 	mov	r4,a
   055D 08                 1028 	inc	r0
   055E E2                 1029 	movx	a,@r0
   055F FD                 1030 	mov	r5,a
   0560 78 0A              1031 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   0562 74 02              1032 	mov	a,#0x02
   0564 F2                 1033 	movx	@r0,a
   0565                    1034 00101$:
   0565 C0 06              1035 	push	ar6
   0567 C0 07              1036 	push	ar7
   0569 8B 82              1037 	mov	dpl,r3
   056B 8C 83              1038 	mov	dph,r4
   056D 8D F0              1039 	mov	b,r5
   056F 12 20 12           1040 	lcall	__gptrget
   0572 FF                 1041 	mov	r7,a
   0573 7E 00              1042 	mov	r6,#0x00
   0575 74 02              1043 	mov	a,#0x02
   0577 2F                 1044 	add	a,r7
   0578 F5 2F              1045 	mov	_dynamixel_calculatechecksum_sloc0_1_0,a
   057A E4                 1046 	clr	a
   057B 3E                 1047 	addc	a,r6
   057C F5 30              1048 	mov	(_dynamixel_calculatechecksum_sloc0_1_0 + 1),a
   057E 78 0A              1049 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   0580 E2                 1050 	movx	a,@r0
   0581 FA                 1051 	mov	r2,a
   0582 7F 00              1052 	mov	r7,#0x00
   0584 C3                 1053 	clr	c
   0585 E5 2F              1054 	mov	a,_dynamixel_calculatechecksum_sloc0_1_0
   0587 9A                 1055 	subb	a,r2
   0588 E5 30              1056 	mov	a,(_dynamixel_calculatechecksum_sloc0_1_0 + 1)
   058A 64 80              1057 	xrl	a,#0x80
   058C 8F F0              1058 	mov	b,r7
   058E 63 F0 80           1059 	xrl	b,#0x80
   0591 95 F0              1060 	subb	a,b
   0593 D0 07              1061 	pop	ar7
   0595 D0 06              1062 	pop	ar6
   0597 40 38              1063 	jc	00104$
                    00AB   1064 	C$dynamixel.c$124$1$1 ==.
                           1065 ;	apps/dynamixel_test/dynamixel.c:124: checksum += packet[i];
   0599 C0 03              1066 	push	ar3
   059B C0 04              1067 	push	ar4
   059D C0 05              1068 	push	ar5
   059F 78 07              1069 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   05A1 79 0A              1070 	mov	r1,#_dynamixel_calculatechecksum_i_1_1
   05A3 E3                 1071 	movx	a,@r1
   05A4 C5 F0              1072 	xch	a,b
   05A6 E2                 1073 	movx	a,@r0
   05A7 25 F0              1074 	add	a,b
   05A9 FA                 1075 	mov	r2,a
   05AA 08                 1076 	inc	r0
   05AB E2                 1077 	movx	a,@r0
   05AC 34 00              1078 	addc	a,#0x00
   05AE FC                 1079 	mov	r4,a
   05AF 08                 1080 	inc	r0
   05B0 E2                 1081 	movx	a,@r0
   05B1 FD                 1082 	mov	r5,a
   05B2 8A 82              1083 	mov	dpl,r2
   05B4 8C 83              1084 	mov	dph,r4
   05B6 8D F0              1085 	mov	b,r5
   05B8 12 20 12           1086 	lcall	__gptrget
   05BB FA                 1087 	mov	r2,a
   05BC 7D 00              1088 	mov	r5,#0x00
   05BE 2E                 1089 	add	a,r6
   05BF FE                 1090 	mov	r6,a
   05C0 ED                 1091 	mov	a,r5
   05C1 3F                 1092 	addc	a,r7
   05C2 FF                 1093 	mov	r7,a
                    00D5   1094 	C$dynamixel.c$123$1$1 ==.
                           1095 ;	apps/dynamixel_test/dynamixel.c:123: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   05C3 78 0A              1096 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   05C5 E2                 1097 	movx	a,@r0
   05C6 24 01              1098 	add	a,#0x01
   05C8 F2                 1099 	movx	@r0,a
   05C9 D0 05              1100 	pop	ar5
   05CB D0 04              1101 	pop	ar4
   05CD D0 03              1102 	pop	ar3
   05CF 80 94              1103 	sjmp	00101$
   05D1                    1104 00104$:
                    00E3   1105 	C$dynamixel.c$126$1$1 ==.
                           1106 ;	apps/dynamixel_test/dynamixel.c:126: return ~(checksum % 256);
   05D1 EE                 1107 	mov	a,r6
   05D2 F4                 1108 	cpl	a
   05D3 F5 82              1109 	mov	dpl,a
                    00E7   1110 	C$dynamixel.c$127$1$1 ==.
                    00E7   1111 	XG$dynamixel_calculatechecksum$0$0 ==.
   05D5 22                 1112 	ret
                           1113 ;------------------------------------------------------------
                           1114 ;Allocation info for local variables in function 'dynamixel_writepacket'
                           1115 ;------------------------------------------------------------
                    00E8   1116 	G$dynamixel_writepacket$0$0 ==.
                    00E8   1117 	C$dynamixel.c$129$1$1 ==.
                           1118 ;	apps/dynamixel_test/dynamixel.c:129: uint8 dynamixel_writepacket(volatile uint8* txpacket, uint8 packetlength)
                           1119 ;	-----------------------------------------
                           1120 ;	 function dynamixel_writepacket
                           1121 ;	-----------------------------------------
   05D6                    1122 _dynamixel_writepacket:
   05D6 AF F0              1123 	mov	r7,b
   05D8 AE 83              1124 	mov	r6,dph
   05DA E5 82              1125 	mov	a,dpl
   05DC 78 0C              1126 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   05DE F2                 1127 	movx	@r0,a
   05DF 08                 1128 	inc	r0
   05E0 EE                 1129 	mov	a,r6
   05E1 F2                 1130 	movx	@r0,a
   05E2 08                 1131 	inc	r0
   05E3 EF                 1132 	mov	a,r7
   05E4 F2                 1133 	movx	@r0,a
                    00F7   1134 	C$dynamixel.c$132$1$1 ==.
                           1135 ;	apps/dynamixel_test/dynamixel.c:132: for(i = 0; i < packetlength; i++)
   05E5 7F 00              1136 	mov	r7,#0x00
   05E7                    1137 00101$:
   05E7 78 0B              1138 	mov	r0,#_dynamixel_writepacket_PARM_2
   05E9 C3                 1139 	clr	c
   05EA E2                 1140 	movx	a,@r0
   05EB F5 F0              1141 	mov	b,a
   05ED EF                 1142 	mov	a,r7
   05EE 95 F0              1143 	subb	a,b
   05F0 50 22              1144 	jnc	00104$
                    0104   1145 	C$dynamixel.c$133$1$1 ==.
                           1146 ;	apps/dynamixel_test/dynamixel.c:133: dynamixel_write(txpacket[i]);
   05F2 78 0C              1147 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   05F4 E2                 1148 	movx	a,@r0
   05F5 2F                 1149 	add	a,r7
   05F6 FC                 1150 	mov	r4,a
   05F7 08                 1151 	inc	r0
   05F8 E2                 1152 	movx	a,@r0
   05F9 34 00              1153 	addc	a,#0x00
   05FB FD                 1154 	mov	r5,a
   05FC 08                 1155 	inc	r0
   05FD E2                 1156 	movx	a,@r0
   05FE FE                 1157 	mov	r6,a
   05FF 8C 82              1158 	mov	dpl,r4
   0601 8D 83              1159 	mov	dph,r5
   0603 8E F0              1160 	mov	b,r6
   0605 12 20 12           1161 	lcall	__gptrget
   0608 F5 82              1162 	mov	dpl,a
   060A C0 07              1163 	push	ar7
   060C 12 05 3B           1164 	lcall	_dynamixel_write
   060F D0 07              1165 	pop	ar7
                    0123   1166 	C$dynamixel.c$132$1$1 ==.
                           1167 ;	apps/dynamixel_test/dynamixel.c:132: for(i = 0; i < packetlength; i++)
   0611 0F                 1168 	inc	r7
   0612 80 D3              1169 	sjmp	00101$
   0614                    1170 00104$:
                    0126   1171 	C$dynamixel.c$135$1$1 ==.
                           1172 ;	apps/dynamixel_test/dynamixel.c:135: return DYNAMIXEL_SUCCESS;
   0614 75 82 01           1173 	mov	dpl,#0x01
                    0129   1174 	C$dynamixel.c$136$1$1 ==.
                    0129   1175 	XG$dynamixel_writepacket$0$0 ==.
   0617 22                 1176 	ret
                           1177 ;------------------------------------------------------------
                           1178 ;Allocation info for local variables in function 'dynamixel_readpacket'
                           1179 ;------------------------------------------------------------
                    012A   1180 	G$dynamixel_readpacket$0$0 ==.
                    012A   1181 	C$dynamixel.c$138$1$1 ==.
                           1182 ;	apps/dynamixel_test/dynamixel.c:138: uint8 dynamixel_readpacket(volatile uint8* rxpacket, uint8 packetlength)
                           1183 ;	-----------------------------------------
                           1184 ;	 function dynamixel_readpacket
                           1185 ;	-----------------------------------------
   0618                    1186 _dynamixel_readpacket:
   0618 AF F0              1187 	mov	r7,b
   061A AE 83              1188 	mov	r6,dph
   061C E5 82              1189 	mov	a,dpl
   061E 78 10              1190 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   0620 F2                 1191 	movx	@r0,a
   0621 08                 1192 	inc	r0
   0622 EE                 1193 	mov	a,r6
   0623 F2                 1194 	movx	@r0,a
   0624 08                 1195 	inc	r0
   0625 EF                 1196 	mov	a,r7
   0626 F2                 1197 	movx	@r0,a
                    0139   1198 	C$dynamixel.c$142$1$1 ==.
                           1199 ;	apps/dynamixel_test/dynamixel.c:142: while(dynamixel_rxindex < packetlength) // wait for a full packet?
   0627 7E 00              1200 	mov	r6,#0x00
   0629 7F 00              1201 	mov	r7,#0x00
   062B                    1202 00103$:
   062B 78 06              1203 	mov	r0,#_dynamixel_rxindex
   062D 79 0F              1204 	mov	r1,#_dynamixel_readpacket_PARM_2
   062F C3                 1205 	clr	c
   0630 E3                 1206 	movx	a,@r1
   0631 F5 F0              1207 	mov	b,a
   0633 E2                 1208 	movx	a,@r0
   0634 95 F0              1209 	subb	a,b
   0636 50 17              1210 	jnc	00105$
                    014A   1211 	C$dynamixel.c$145$2$2 ==.
                           1212 ;	apps/dynamixel_test/dynamixel.c:145: if(ulcounter++ > 10000)
   0638 8E 04              1213 	mov	ar4,r6
   063A 8F 05              1214 	mov	ar5,r7
   063C 0E                 1215 	inc	r6
   063D BE 00 01           1216 	cjne	r6,#0x00,00119$
   0640 0F                 1217 	inc	r7
   0641                    1218 00119$:
   0641 C3                 1219 	clr	c
   0642 74 10              1220 	mov	a,#0x10
   0644 9C                 1221 	subb	a,r4
   0645 74 27              1222 	mov	a,#0x27
   0647 9D                 1223 	subb	a,r5
   0648 50 E1              1224 	jnc	00103$
                    015C   1225 	C$dynamixel.c$146$2$2 ==.
                           1226 ;	apps/dynamixel_test/dynamixel.c:146: return DYNAMIXEL_RX_TIMEOUT;
   064A 75 82 03           1227 	mov	dpl,#0x03
   064D 80 6E              1228 	sjmp	00111$
   064F                    1229 00105$:
                    0161   1230 	C$dynamixel.c$151$1$1 ==.
                           1231 ;	apps/dynamixel_test/dynamixel.c:151: if((rxpacket[0] != 255) || (rxpacket[1] != 255))
   064F 78 10              1232 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   0651 E2                 1233 	movx	a,@r0
   0652 FD                 1234 	mov	r5,a
   0653 08                 1235 	inc	r0
   0654 E2                 1236 	movx	a,@r0
   0655 FE                 1237 	mov	r6,a
   0656 08                 1238 	inc	r0
   0657 E2                 1239 	movx	a,@r0
   0658 FF                 1240 	mov	r7,a
   0659 8D 82              1241 	mov	dpl,r5
   065B 8E 83              1242 	mov	dph,r6
   065D 8F F0              1243 	mov	b,r7
   065F 12 20 12           1244 	lcall	__gptrget
   0662 FC                 1245 	mov	r4,a
   0663 BC FF 18           1246 	cjne	r4,#0xFF,00106$
   0666 74 01              1247 	mov	a,#0x01
   0668 2D                 1248 	add	a,r5
   0669 FA                 1249 	mov	r2,a
   066A E4                 1250 	clr	a
   066B 3E                 1251 	addc	a,r6
   066C FB                 1252 	mov	r3,a
   066D 8F 04              1253 	mov	ar4,r7
   066F 8A 82              1254 	mov	dpl,r2
   0671 8B 83              1255 	mov	dph,r3
   0673 8C F0              1256 	mov	b,r4
   0675 12 20 12           1257 	lcall	__gptrget
   0678 FA                 1258 	mov	r2,a
   0679 BA FF 02           1259 	cjne	r2,#0xFF,00123$
   067C 80 05              1260 	sjmp	00107$
   067E                    1261 00123$:
   067E                    1262 00106$:
                    0190   1263 	C$dynamixel.c$152$1$1 ==.
                           1264 ;	apps/dynamixel_test/dynamixel.c:152: return DYNAMIXEL_RX_CORRUPT;
   067E 75 82 02           1265 	mov	dpl,#0x02
   0681 80 3A              1266 	sjmp	00111$
   0683                    1267 00107$:
                    0195   1268 	C$dynamixel.c$154$1$1 ==.
                           1269 ;	apps/dynamixel_test/dynamixel.c:154: if(rxpacket[packetlength - 1] != dynamixel_calculatechecksum(rxpacket))
   0683 78 0F              1270 	mov	r0,#_dynamixel_readpacket_PARM_2
   0685 E2                 1271 	movx	a,@r0
   0686 FB                 1272 	mov	r3,a
   0687 7C 00              1273 	mov	r4,#0x00
   0689 1B                 1274 	dec	r3
   068A BB FF 01           1275 	cjne	r3,#0xFF,00124$
   068D 1C                 1276 	dec	r4
   068E                    1277 00124$:
   068E EB                 1278 	mov	a,r3
   068F 2D                 1279 	add	a,r5
   0690 FB                 1280 	mov	r3,a
   0691 EC                 1281 	mov	a,r4
   0692 3E                 1282 	addc	a,r6
   0693 FC                 1283 	mov	r4,a
   0694 8F 02              1284 	mov	ar2,r7
   0696 8B 82              1285 	mov	dpl,r3
   0698 8C 83              1286 	mov	dph,r4
   069A 8A F0              1287 	mov	b,r2
   069C 12 20 12           1288 	lcall	__gptrget
   069F FB                 1289 	mov	r3,a
   06A0 8D 82              1290 	mov	dpl,r5
   06A2 8E 83              1291 	mov	dph,r6
   06A4 8F F0              1292 	mov	b,r7
   06A6 C0 03              1293 	push	ar3
   06A8 12 05 3F           1294 	lcall	_dynamixel_calculatechecksum
   06AB AF 82              1295 	mov	r7,dpl
   06AD D0 03              1296 	pop	ar3
   06AF EB                 1297 	mov	a,r3
   06B0 B5 07 02           1298 	cjne	a,ar7,00125$
   06B3 80 05              1299 	sjmp	00110$
   06B5                    1300 00125$:
                    01C7   1301 	C$dynamixel.c$155$1$1 ==.
                           1302 ;	apps/dynamixel_test/dynamixel.c:155: return DYNAMIXEL_RX_CORRUPT;
   06B5 75 82 02           1303 	mov	dpl,#0x02
   06B8 80 03              1304 	sjmp	00111$
   06BA                    1305 00110$:
                    01CC   1306 	C$dynamixel.c$157$1$1 ==.
                           1307 ;	apps/dynamixel_test/dynamixel.c:157: return DYNAMIXEL_SUCCESS;
   06BA 75 82 01           1308 	mov	dpl,#0x01
   06BD                    1309 00111$:
                    01CF   1310 	C$dynamixel.c$158$1$1 ==.
                    01CF   1311 	XG$dynamixel_readpacket$0$0 ==.
   06BD 22                 1312 	ret
                           1313 ;------------------------------------------------------------
                           1314 ;Allocation info for local variables in function 'dynamixel_txrx'
                           1315 ;------------------------------------------------------------
                           1316 ;sloc0                     Allocated with name '_dynamixel_txrx_sloc0_1_0'
                           1317 ;------------------------------------------------------------
                    01D0   1318 	G$dynamixel_txrx$0$0 ==.
                    01D0   1319 	C$dynamixel.c$160$1$1 ==.
                           1320 ;	apps/dynamixel_test/dynamixel.c:160: uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket)
                           1321 ;	-----------------------------------------
                           1322 ;	 function dynamixel_txrx
                           1323 ;	-----------------------------------------
   06BE                    1324 _dynamixel_txrx:
   06BE AF F0              1325 	mov	r7,b
   06C0 AE 83              1326 	mov	r6,dph
   06C2 E5 82              1327 	mov	a,dpl
   06C4 78 16              1328 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   06C6 F2                 1329 	movx	@r0,a
   06C7 08                 1330 	inc	r0
   06C8 EE                 1331 	mov	a,r6
   06C9 F2                 1332 	movx	@r0,a
   06CA 08                 1333 	inc	r0
   06CB EF                 1334 	mov	a,r7
   06CC F2                 1335 	movx	@r0,a
                    01DF   1336 	C$dynamixel.c$173$1$1 ==.
                           1337 ;	apps/dynamixel_test/dynamixel.c:173: uint8 txlength = dynamixel_txpacket[DYNAMIXEL_LENGTH] + 4; // 0xff,0xff, ID, packet, checksum ?
   06CD 78 00              1338 	mov	r0,#_dynamixel_txpacket
   06CF E2                 1339 	movx	a,@r0
   06D0 24 03              1340 	add	a,#0x03
   06D2 FD                 1341 	mov	r5,a
   06D3 08                 1342 	inc	r0
   06D4 E2                 1343 	movx	a,@r0
   06D5 34 00              1344 	addc	a,#0x00
   06D7 FE                 1345 	mov	r6,a
   06D8 08                 1346 	inc	r0
   06D9 E2                 1347 	movx	a,@r0
   06DA FF                 1348 	mov	r7,a
   06DB 8D 82              1349 	mov	dpl,r5
   06DD 8E 83              1350 	mov	dph,r6
   06DF 8F F0              1351 	mov	b,r7
   06E1 12 20 12           1352 	lcall	__gptrget
   06E4 FD                 1353 	mov	r5,a
   06E5 78 19              1354 	mov	r0,#_dynamixel_txrx_txlength_1_1
   06E7 74 04              1355 	mov	a,#0x04
   06E9 2D                 1356 	add	a,r5
   06EA F2                 1357 	movx	@r0,a
                    01FD   1358 	C$dynamixel.c$175$1$1 ==.
                           1359 ;	apps/dynamixel_test/dynamixel.c:175: txpacket[0] = (uint8) 0xff;
   06EB 78 16              1360 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   06ED E2                 1361 	movx	a,@r0
   06EE FC                 1362 	mov	r4,a
   06EF 08                 1363 	inc	r0
   06F0 E2                 1364 	movx	a,@r0
   06F1 FE                 1365 	mov	r6,a
   06F2 08                 1366 	inc	r0
   06F3 E2                 1367 	movx	a,@r0
   06F4 FF                 1368 	mov	r7,a
   06F5 8C 82              1369 	mov	dpl,r4
   06F7 8E 83              1370 	mov	dph,r6
   06F9 8F F0              1371 	mov	b,r7
   06FB 74 FF              1372 	mov	a,#0xFF
   06FD 12 17 81           1373 	lcall	__gptrput
                    0212   1374 	C$dynamixel.c$176$1$1 ==.
                           1375 ;	apps/dynamixel_test/dynamixel.c:176: txpacket[1] = (uint8) 0xff;
   0700 74 01              1376 	mov	a,#0x01
   0702 2C                 1377 	add	a,r4
   0703 FA                 1378 	mov	r2,a
   0704 E4                 1379 	clr	a
   0705 3E                 1380 	addc	a,r6
   0706 FB                 1381 	mov	r3,a
   0707 8F 05              1382 	mov	ar5,r7
   0709 8A 82              1383 	mov	dpl,r2
   070B 8B 83              1384 	mov	dph,r3
   070D 8D F0              1385 	mov	b,r5
   070F 74 FF              1386 	mov	a,#0xFF
   0711 12 17 81           1387 	lcall	__gptrput
                    0226   1388 	C$dynamixel.c$177$1$1 ==.
                           1389 ;	apps/dynamixel_test/dynamixel.c:177: txpacket[txlength - 1] = (uint8) dynamixel_calculatechecksum(txpacket);
   0714 78 19              1390 	mov	r0,#_dynamixel_txrx_txlength_1_1
   0716 E2                 1391 	movx	a,@r0
   0717 FB                 1392 	mov	r3,a
   0718 7D 00              1393 	mov	r5,#0x00
   071A 1B                 1394 	dec	r3
   071B BB FF 01           1395 	cjne	r3,#0xFF,00110$
   071E 1D                 1396 	dec	r5
   071F                    1397 00110$:
   071F EB                 1398 	mov	a,r3
   0720 2C                 1399 	add	a,r4
   0721 F5 08              1400 	mov	_dynamixel_txrx_sloc0_1_0,a
   0723 ED                 1401 	mov	a,r5
   0724 3E                 1402 	addc	a,r6
   0725 F5 09              1403 	mov	(_dynamixel_txrx_sloc0_1_0 + 1),a
   0727 8F 0A              1404 	mov	(_dynamixel_txrx_sloc0_1_0 + 2),r7
   0729 8C 82              1405 	mov	dpl,r4
   072B 8E 83              1406 	mov	dph,r6
   072D 8F F0              1407 	mov	b,r7
   072F C0 07              1408 	push	ar7
   0731 C0 06              1409 	push	ar6
   0733 C0 04              1410 	push	ar4
   0735 12 05 3F           1411 	lcall	_dynamixel_calculatechecksum
   0738 AD 82              1412 	mov	r5,dpl
   073A 85 08 82           1413 	mov	dpl,_dynamixel_txrx_sloc0_1_0
   073D 85 09 83           1414 	mov	dph,(_dynamixel_txrx_sloc0_1_0 + 1)
   0740 85 0A F0           1415 	mov	b,(_dynamixel_txrx_sloc0_1_0 + 2)
   0743 ED                 1416 	mov	a,r5
   0744 12 17 81           1417 	lcall	__gptrput
                    0259   1418 	C$dynamixel.c$179$1$1 ==.
                           1419 ;	apps/dynamixel_test/dynamixel.c:179: dynamixel_settx();
   0747 12 05 1B           1420 	lcall	_dynamixel_settx
                    025C   1421 	C$dynamixel.c$180$1$1 ==.
                           1422 ;	apps/dynamixel_test/dynamixel.c:180: dynamixel_writepacket(txpacket, txlength);
   074A 78 19              1423 	mov	r0,#_dynamixel_txrx_txlength_1_1
   074C 79 0B              1424 	mov	r1,#_dynamixel_writepacket_PARM_2
   074E E2                 1425 	movx	a,@r0
   074F F3                 1426 	movx	@r1,a
   0750 78 16              1427 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   0752 E2                 1428 	movx	a,@r0
   0753 F5 82              1429 	mov	dpl,a
   0755 08                 1430 	inc	r0
   0756 E2                 1431 	movx	a,@r0
   0757 F5 83              1432 	mov	dph,a
   0759 08                 1433 	inc	r0
   075A E2                 1434 	movx	a,@r0
   075B F5 F0              1435 	mov	b,a
   075D 12 05 D6           1436 	lcall	_dynamixel_writepacket
                    0272   1437 	C$dynamixel.c$181$1$1 ==.
                           1438 ;	apps/dynamixel_test/dynamixel.c:181: dynamixel_setrx();
   0760 12 05 26           1439 	lcall	_dynamixel_setrx
   0763 D0 04              1440 	pop	ar4
   0765 D0 06              1441 	pop	ar6
   0767 D0 07              1442 	pop	ar7
                    027B   1443 	C$dynamixel.c$184$1$1 ==.
                           1444 ;	apps/dynamixel_test/dynamixel.c:184: if(txpacket[DYNAMIXEL_ID] != DYNAMIXEL_BROADCAST_ID)
   0769 78 16              1445 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   076B E2                 1446 	movx	a,@r0
   076C 24 02              1447 	add	a,#0x02
   076E FA                 1448 	mov	r2,a
   076F 08                 1449 	inc	r0
   0770 E2                 1450 	movx	a,@r0
   0771 34 00              1451 	addc	a,#0x00
   0773 FB                 1452 	mov	r3,a
   0774 08                 1453 	inc	r0
   0775 E2                 1454 	movx	a,@r0
   0776 FD                 1455 	mov	r5,a
   0777 8A 82              1456 	mov	dpl,r2
   0779 8B 83              1457 	mov	dph,r3
   077B 8D F0              1458 	mov	b,r5
   077D 12 20 12           1459 	lcall	__gptrget
   0780 FA                 1460 	mov	r2,a
   0781 BA FE 02           1461 	cjne	r2,#0xFE,00111$
   0784 80 44              1462 	sjmp	00105$
   0786                    1463 00111$:
                    0298   1464 	C$dynamixel.c$187$2$2 ==.
                           1465 ;	apps/dynamixel_test/dynamixel.c:187: if(txpacket[DYNAMIXEL_INSTRUCTION] == DYNAMIXEL_READ)
   0786 74 04              1466 	mov	a,#0x04
   0788 2C                 1467 	add	a,r4
   0789 FA                 1468 	mov	r2,a
   078A E4                 1469 	clr	a
   078B 3E                 1470 	addc	a,r6
   078C FB                 1471 	mov	r3,a
   078D 8F 05              1472 	mov	ar5,r7
   078F 8A 82              1473 	mov	dpl,r2
   0791 8B 83              1474 	mov	dph,r3
   0793 8D F0              1475 	mov	b,r5
   0795 12 20 12           1476 	lcall	__gptrget
   0798 FA                 1477 	mov	r2,a
   0799 BA 02 16           1478 	cjne	r2,#0x02,00102$
                    02AE   1479 	C$dynamixel.c$189$2$2 ==.
                           1480 ;	apps/dynamixel_test/dynamixel.c:189: rxlength = txpacket[DYNAMIXEL_PARAMETER + 1] + 6;
   079C 74 06              1481 	mov	a,#0x06
   079E 2C                 1482 	add	a,r4
   079F FC                 1483 	mov	r4,a
   07A0 E4                 1484 	clr	a
   07A1 3E                 1485 	addc	a,r6
   07A2 FE                 1486 	mov	r6,a
   07A3 8C 82              1487 	mov	dpl,r4
   07A5 8E 83              1488 	mov	dph,r6
   07A7 8F F0              1489 	mov	b,r7
   07A9 12 20 12           1490 	lcall	__gptrget
   07AC FC                 1491 	mov	r4,a
   07AD 24 06              1492 	add	a,#0x06
   07AF FF                 1493 	mov	r7,a
   07B0 80 02              1494 	sjmp	00103$
   07B2                    1495 00102$:
                    02C4   1496 	C$dynamixel.c$191$2$2 ==.
                           1497 ;	apps/dynamixel_test/dynamixel.c:191: rxlength = 6; // Default answer packet length? for DYNAMIXEL_WRITE?
   07B2 7F 06              1498 	mov	r7,#0x06
   07B4                    1499 00103$:
                    02C6   1500 	C$dynamixel.c$193$2$2 ==.
                           1501 ;	apps/dynamixel_test/dynamixel.c:193: return dynamixel_readpacket(rxpacket, rxlength);			
   07B4 78 0F              1502 	mov	r0,#_dynamixel_readpacket_PARM_2
   07B6 EF                 1503 	mov	a,r7
   07B7 F2                 1504 	movx	@r0,a
   07B8 78 13              1505 	mov	r0,#_dynamixel_txrx_PARM_2
   07BA E2                 1506 	movx	a,@r0
   07BB F5 82              1507 	mov	dpl,a
   07BD 08                 1508 	inc	r0
   07BE E2                 1509 	movx	a,@r0
   07BF F5 83              1510 	mov	dph,a
   07C1 08                 1511 	inc	r0
   07C2 E2                 1512 	movx	a,@r0
   07C3 F5 F0              1513 	mov	b,a
   07C5 12 06 18           1514 	lcall	_dynamixel_readpacket
   07C8 80 06              1515 	sjmp	00106$
   07CA                    1516 00105$:
                    02DC   1517 	C$dynamixel.c$196$1$1 ==.
                           1518 ;	apps/dynamixel_test/dynamixel.c:196: dynamixel_settx();
   07CA 12 05 1B           1519 	lcall	_dynamixel_settx
                    02DF   1520 	C$dynamixel.c$198$1$1 ==.
                           1521 ;	apps/dynamixel_test/dynamixel.c:198: return DYNAMIXEL_SUCCESS;
   07CD 75 82 01           1522 	mov	dpl,#0x01
   07D0                    1523 00106$:
                    02E2   1524 	C$dynamixel.c$199$1$1 ==.
                    02E2   1525 	XG$dynamixel_txrx$0$0 ==.
   07D0 22                 1526 	ret
                           1527 ;------------------------------------------------------------
                           1528 ;Allocation info for local variables in function 'dynamixel_ping'
                           1529 ;------------------------------------------------------------
                    02E3   1530 	G$dynamixel_ping$0$0 ==.
                    02E3   1531 	C$dynamixel.c$203$1$1 ==.
                           1532 ;	apps/dynamixel_test/dynamixel.c:203: uint8 dynamixel_ping(uint8 id)
                           1533 ;	-----------------------------------------
                           1534 ;	 function dynamixel_ping
                           1535 ;	-----------------------------------------
   07D1                    1536 _dynamixel_ping:
   07D1 AF 82              1537 	mov	r7,dpl
                    02E5   1538 	C$dynamixel.c$205$1$1 ==.
                           1539 ;	apps/dynamixel_test/dynamixel.c:205: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   07D3 78 00              1540 	mov	r0,#_dynamixel_txpacket
   07D5 E2                 1541 	movx	a,@r0
   07D6 24 02              1542 	add	a,#0x02
   07D8 FC                 1543 	mov	r4,a
   07D9 08                 1544 	inc	r0
   07DA E2                 1545 	movx	a,@r0
   07DB 34 00              1546 	addc	a,#0x00
   07DD FD                 1547 	mov	r5,a
   07DE 08                 1548 	inc	r0
   07DF E2                 1549 	movx	a,@r0
   07E0 FE                 1550 	mov	r6,a
   07E1 8C 82              1551 	mov	dpl,r4
   07E3 8D 83              1552 	mov	dph,r5
   07E5 8E F0              1553 	mov	b,r6
   07E7 EF                 1554 	mov	a,r7
   07E8 12 17 81           1555 	lcall	__gptrput
                    02FD   1556 	C$dynamixel.c$206$1$1 ==.
                           1557 ;	apps/dynamixel_test/dynamixel.c:206: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
   07EB 78 00              1558 	mov	r0,#_dynamixel_txpacket
   07ED E2                 1559 	movx	a,@r0
   07EE 24 03              1560 	add	a,#0x03
   07F0 FD                 1561 	mov	r5,a
   07F1 08                 1562 	inc	r0
   07F2 E2                 1563 	movx	a,@r0
   07F3 34 00              1564 	addc	a,#0x00
   07F5 FE                 1565 	mov	r6,a
   07F6 08                 1566 	inc	r0
   07F7 E2                 1567 	movx	a,@r0
   07F8 FF                 1568 	mov	r7,a
   07F9 8D 82              1569 	mov	dpl,r5
   07FB 8E 83              1570 	mov	dph,r6
   07FD 8F F0              1571 	mov	b,r7
   07FF 74 02              1572 	mov	a,#0x02
   0801 12 17 81           1573 	lcall	__gptrput
                    0316   1574 	C$dynamixel.c$207$1$1 ==.
                           1575 ;	apps/dynamixel_test/dynamixel.c:207: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_PING;
   0804 78 00              1576 	mov	r0,#_dynamixel_txpacket
   0806 E2                 1577 	movx	a,@r0
   0807 24 04              1578 	add	a,#0x04
   0809 FD                 1579 	mov	r5,a
   080A 08                 1580 	inc	r0
   080B E2                 1581 	movx	a,@r0
   080C 34 00              1582 	addc	a,#0x00
   080E FE                 1583 	mov	r6,a
   080F 08                 1584 	inc	r0
   0810 E2                 1585 	movx	a,@r0
   0811 FF                 1586 	mov	r7,a
   0812 8D 82              1587 	mov	dpl,r5
   0814 8E 83              1588 	mov	dph,r6
   0816 8F F0              1589 	mov	b,r7
   0818 74 01              1590 	mov	a,#0x01
   081A 12 17 81           1591 	lcall	__gptrput
                    032F   1592 	C$dynamixel.c$209$1$1 ==.
                           1593 ;	apps/dynamixel_test/dynamixel.c:209: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   081D 78 03              1594 	mov	r0,#_dynamixel_rxpacket
   081F 79 13              1595 	mov	r1,#_dynamixel_txrx_PARM_2
   0821 E2                 1596 	movx	a,@r0
   0822 F3                 1597 	movx	@r1,a
   0823 08                 1598 	inc	r0
   0824 E2                 1599 	movx	a,@r0
   0825 09                 1600 	inc	r1
   0826 F3                 1601 	movx	@r1,a
   0827 08                 1602 	inc	r0
   0828 E2                 1603 	movx	a,@r0
   0829 09                 1604 	inc	r1
   082A F3                 1605 	movx	@r1,a
   082B 78 00              1606 	mov	r0,#_dynamixel_txpacket
   082D E2                 1607 	movx	a,@r0
   082E F5 82              1608 	mov	dpl,a
   0830 08                 1609 	inc	r0
   0831 E2                 1610 	movx	a,@r0
   0832 F5 83              1611 	mov	dph,a
   0834 08                 1612 	inc	r0
   0835 E2                 1613 	movx	a,@r0
   0836 F5 F0              1614 	mov	b,a
   0838 12 06 BE           1615 	lcall	_dynamixel_txrx
                    034D   1616 	C$dynamixel.c$210$1$1 ==.
                    034D   1617 	XG$dynamixel_ping$0$0 ==.
   083B 22                 1618 	ret
                           1619 ;------------------------------------------------------------
                           1620 ;Allocation info for local variables in function 'dynamixel_readbyte'
                           1621 ;------------------------------------------------------------
                    034E   1622 	G$dynamixel_readbyte$0$0 ==.
                    034E   1623 	C$dynamixel.c$212$1$1 ==.
                           1624 ;	apps/dynamixel_test/dynamixel.c:212: uint8 dynamixel_readbyte(uint8 id, uint8 address, uint8* value)
                           1625 ;	-----------------------------------------
                           1626 ;	 function dynamixel_readbyte
                           1627 ;	-----------------------------------------
   083C                    1628 _dynamixel_readbyte:
   083C AF 82              1629 	mov	r7,dpl
                    0350   1630 	C$dynamixel.c$216$1$1 ==.
                           1631 ;	apps/dynamixel_test/dynamixel.c:216: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   083E 78 00              1632 	mov	r0,#_dynamixel_txpacket
   0840 E2                 1633 	movx	a,@r0
   0841 24 02              1634 	add	a,#0x02
   0843 FC                 1635 	mov	r4,a
   0844 08                 1636 	inc	r0
   0845 E2                 1637 	movx	a,@r0
   0846 34 00              1638 	addc	a,#0x00
   0848 FD                 1639 	mov	r5,a
   0849 08                 1640 	inc	r0
   084A E2                 1641 	movx	a,@r0
   084B FE                 1642 	mov	r6,a
   084C 8C 82              1643 	mov	dpl,r4
   084E 8D 83              1644 	mov	dph,r5
   0850 8E F0              1645 	mov	b,r6
   0852 EF                 1646 	mov	a,r7
   0853 12 17 81           1647 	lcall	__gptrput
                    0368   1648 	C$dynamixel.c$217$1$1 ==.
                           1649 ;	apps/dynamixel_test/dynamixel.c:217: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
   0856 78 00              1650 	mov	r0,#_dynamixel_txpacket
   0858 E2                 1651 	movx	a,@r0
   0859 24 03              1652 	add	a,#0x03
   085B FD                 1653 	mov	r5,a
   085C 08                 1654 	inc	r0
   085D E2                 1655 	movx	a,@r0
   085E 34 00              1656 	addc	a,#0x00
   0860 FE                 1657 	mov	r6,a
   0861 08                 1658 	inc	r0
   0862 E2                 1659 	movx	a,@r0
   0863 FF                 1660 	mov	r7,a
   0864 8D 82              1661 	mov	dpl,r5
   0866 8E 83              1662 	mov	dph,r6
   0868 8F F0              1663 	mov	b,r7
   086A 74 04              1664 	mov	a,#0x04
   086C 12 17 81           1665 	lcall	__gptrput
                    0381   1666 	C$dynamixel.c$218$1$1 ==.
                           1667 ;	apps/dynamixel_test/dynamixel.c:218: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
   086F 78 00              1668 	mov	r0,#_dynamixel_txpacket
   0871 E2                 1669 	movx	a,@r0
   0872 24 04              1670 	add	a,#0x04
   0874 FD                 1671 	mov	r5,a
   0875 08                 1672 	inc	r0
   0876 E2                 1673 	movx	a,@r0
   0877 34 00              1674 	addc	a,#0x00
   0879 FE                 1675 	mov	r6,a
   087A 08                 1676 	inc	r0
   087B E2                 1677 	movx	a,@r0
   087C FF                 1678 	mov	r7,a
   087D 8D 82              1679 	mov	dpl,r5
   087F 8E 83              1680 	mov	dph,r6
   0881 8F F0              1681 	mov	b,r7
   0883 74 02              1682 	mov	a,#0x02
   0885 12 17 81           1683 	lcall	__gptrput
                    039A   1684 	C$dynamixel.c$219$1$1 ==.
                           1685 ;	apps/dynamixel_test/dynamixel.c:219: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   0888 78 00              1686 	mov	r0,#_dynamixel_txpacket
   088A E2                 1687 	movx	a,@r0
   088B 24 05              1688 	add	a,#0x05
   088D FD                 1689 	mov	r5,a
   088E 08                 1690 	inc	r0
   088F E2                 1691 	movx	a,@r0
   0890 34 00              1692 	addc	a,#0x00
   0892 FE                 1693 	mov	r6,a
   0893 08                 1694 	inc	r0
   0894 E2                 1695 	movx	a,@r0
   0895 FF                 1696 	mov	r7,a
   0896 8D 82              1697 	mov	dpl,r5
   0898 8E 83              1698 	mov	dph,r6
   089A 8F F0              1699 	mov	b,r7
   089C 78 1A              1700 	mov	r0,#_dynamixel_readbyte_PARM_2
   089E E2                 1701 	movx	a,@r0
   089F 12 17 81           1702 	lcall	__gptrput
                    03B4   1703 	C$dynamixel.c$220$1$1 ==.
                           1704 ;	apps/dynamixel_test/dynamixel.c:220: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 1;
   08A2 78 00              1705 	mov	r0,#_dynamixel_txpacket
   08A4 E2                 1706 	movx	a,@r0
   08A5 24 06              1707 	add	a,#0x06
   08A7 FD                 1708 	mov	r5,a
   08A8 08                 1709 	inc	r0
   08A9 E2                 1710 	movx	a,@r0
   08AA 34 00              1711 	addc	a,#0x00
   08AC FE                 1712 	mov	r6,a
   08AD 08                 1713 	inc	r0
   08AE E2                 1714 	movx	a,@r0
   08AF FF                 1715 	mov	r7,a
   08B0 8D 82              1716 	mov	dpl,r5
   08B2 8E 83              1717 	mov	dph,r6
   08B4 8F F0              1718 	mov	b,r7
   08B6 74 01              1719 	mov	a,#0x01
   08B8 12 17 81           1720 	lcall	__gptrput
                    03CD   1721 	C$dynamixel.c$222$1$1 ==.
                           1722 ;	apps/dynamixel_test/dynamixel.c:222: result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   08BB 78 03              1723 	mov	r0,#_dynamixel_rxpacket
   08BD 79 13              1724 	mov	r1,#_dynamixel_txrx_PARM_2
   08BF E2                 1725 	movx	a,@r0
   08C0 F3                 1726 	movx	@r1,a
   08C1 08                 1727 	inc	r0
   08C2 E2                 1728 	movx	a,@r0
   08C3 09                 1729 	inc	r1
   08C4 F3                 1730 	movx	@r1,a
   08C5 08                 1731 	inc	r0
   08C6 E2                 1732 	movx	a,@r0
   08C7 09                 1733 	inc	r1
   08C8 F3                 1734 	movx	@r1,a
   08C9 78 00              1735 	mov	r0,#_dynamixel_txpacket
   08CB E2                 1736 	movx	a,@r0
   08CC F5 82              1737 	mov	dpl,a
   08CE 08                 1738 	inc	r0
   08CF E2                 1739 	movx	a,@r0
   08D0 F5 83              1740 	mov	dph,a
   08D2 08                 1741 	inc	r0
   08D3 E2                 1742 	movx	a,@r0
   08D4 F5 F0              1743 	mov	b,a
   08D6 12 06 BE           1744 	lcall	_dynamixel_txrx
   08D9 AF 82              1745 	mov	r7,dpl
                    03ED   1746 	C$dynamixel.c$224$1$1 ==.
                           1747 ;	apps/dynamixel_test/dynamixel.c:224: if(result == DYNAMIXEL_SUCCESS)
   08DB BF 01 2F           1748 	cjne	r7,#0x01,00102$
                    03F0   1749 	C$dynamixel.c$225$1$1 ==.
                           1750 ;	apps/dynamixel_test/dynamixel.c:225: *value = dynamixel_rxpacket[DYNAMIXEL_PARAMETER];
   08DE C0 07              1751 	push	ar7
   08E0 78 1B              1752 	mov	r0,#_dynamixel_readbyte_PARM_3
   08E2 E2                 1753 	movx	a,@r0
   08E3 FC                 1754 	mov	r4,a
   08E4 08                 1755 	inc	r0
   08E5 E2                 1756 	movx	a,@r0
   08E6 FD                 1757 	mov	r5,a
   08E7 08                 1758 	inc	r0
   08E8 E2                 1759 	movx	a,@r0
   08E9 FE                 1760 	mov	r6,a
   08EA 78 03              1761 	mov	r0,#_dynamixel_rxpacket
   08EC E2                 1762 	movx	a,@r0
   08ED 24 05              1763 	add	a,#0x05
   08EF FA                 1764 	mov	r2,a
   08F0 08                 1765 	inc	r0
   08F1 E2                 1766 	movx	a,@r0
   08F2 34 00              1767 	addc	a,#0x00
   08F4 FB                 1768 	mov	r3,a
   08F5 08                 1769 	inc	r0
   08F6 E2                 1770 	movx	a,@r0
   08F7 FF                 1771 	mov	r7,a
   08F8 8A 82              1772 	mov	dpl,r2
   08FA 8B 83              1773 	mov	dph,r3
   08FC 8F F0              1774 	mov	b,r7
   08FE 12 20 12           1775 	lcall	__gptrget
   0901 FA                 1776 	mov	r2,a
   0902 8C 82              1777 	mov	dpl,r4
   0904 8D 83              1778 	mov	dph,r5
   0906 8E F0              1779 	mov	b,r6
   0908 12 17 81           1780 	lcall	__gptrput
                    041D   1781 	C$dynamixel.c$227$1$1 ==.
                           1782 ;	apps/dynamixel_test/dynamixel.c:227: return result;
   090B D0 07              1783 	pop	ar7
                    041F   1784 	C$dynamixel.c$225$1$1 ==.
                           1785 ;	apps/dynamixel_test/dynamixel.c:225: *value = dynamixel_rxpacket[DYNAMIXEL_PARAMETER];
   090D                    1786 00102$:
                    041F   1787 	C$dynamixel.c$227$1$1 ==.
                           1788 ;	apps/dynamixel_test/dynamixel.c:227: return result;
   090D 8F 82              1789 	mov	dpl,r7
                    0421   1790 	C$dynamixel.c$228$1$1 ==.
                    0421   1791 	XG$dynamixel_readbyte$0$0 ==.
   090F 22                 1792 	ret
                           1793 ;------------------------------------------------------------
                           1794 ;Allocation info for local variables in function 'dynamixel_readword'
                           1795 ;------------------------------------------------------------
                           1796 ;sloc0                     Allocated with name '_dynamixel_readword_sloc0_1_0'
                           1797 ;------------------------------------------------------------
                    0422   1798 	G$dynamixel_readword$0$0 ==.
                    0422   1799 	C$dynamixel.c$230$1$1 ==.
                           1800 ;	apps/dynamixel_test/dynamixel.c:230: uint8 dynamixel_readword(uint8 id, uint8 address, uint16* value)
                           1801 ;	-----------------------------------------
                           1802 ;	 function dynamixel_readword
                           1803 ;	-----------------------------------------
   0910                    1804 _dynamixel_readword:
   0910 AF 82              1805 	mov	r7,dpl
                    0424   1806 	C$dynamixel.c$234$1$1 ==.
                           1807 ;	apps/dynamixel_test/dynamixel.c:234: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0912 78 00              1808 	mov	r0,#_dynamixel_txpacket
   0914 E2                 1809 	movx	a,@r0
   0915 24 02              1810 	add	a,#0x02
   0917 FC                 1811 	mov	r4,a
   0918 08                 1812 	inc	r0
   0919 E2                 1813 	movx	a,@r0
   091A 34 00              1814 	addc	a,#0x00
   091C FD                 1815 	mov	r5,a
   091D 08                 1816 	inc	r0
   091E E2                 1817 	movx	a,@r0
   091F FE                 1818 	mov	r6,a
   0920 8C 82              1819 	mov	dpl,r4
   0922 8D 83              1820 	mov	dph,r5
   0924 8E F0              1821 	mov	b,r6
   0926 EF                 1822 	mov	a,r7
   0927 12 17 81           1823 	lcall	__gptrput
                    043C   1824 	C$dynamixel.c$235$1$1 ==.
                           1825 ;	apps/dynamixel_test/dynamixel.c:235: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
   092A 78 00              1826 	mov	r0,#_dynamixel_txpacket
   092C E2                 1827 	movx	a,@r0
   092D 24 03              1828 	add	a,#0x03
   092F FD                 1829 	mov	r5,a
   0930 08                 1830 	inc	r0
   0931 E2                 1831 	movx	a,@r0
   0932 34 00              1832 	addc	a,#0x00
   0934 FE                 1833 	mov	r6,a
   0935 08                 1834 	inc	r0
   0936 E2                 1835 	movx	a,@r0
   0937 FF                 1836 	mov	r7,a
   0938 8D 82              1837 	mov	dpl,r5
   093A 8E 83              1838 	mov	dph,r6
   093C 8F F0              1839 	mov	b,r7
   093E 74 04              1840 	mov	a,#0x04
   0940 12 17 81           1841 	lcall	__gptrput
                    0455   1842 	C$dynamixel.c$236$1$1 ==.
                           1843 ;	apps/dynamixel_test/dynamixel.c:236: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
   0943 78 00              1844 	mov	r0,#_dynamixel_txpacket
   0945 E2                 1845 	movx	a,@r0
   0946 24 04              1846 	add	a,#0x04
   0948 FD                 1847 	mov	r5,a
   0949 08                 1848 	inc	r0
   094A E2                 1849 	movx	a,@r0
   094B 34 00              1850 	addc	a,#0x00
   094D FE                 1851 	mov	r6,a
   094E 08                 1852 	inc	r0
   094F E2                 1853 	movx	a,@r0
   0950 FF                 1854 	mov	r7,a
   0951 8D 82              1855 	mov	dpl,r5
   0953 8E 83              1856 	mov	dph,r6
   0955 8F F0              1857 	mov	b,r7
   0957 74 02              1858 	mov	a,#0x02
   0959 12 17 81           1859 	lcall	__gptrput
                    046E   1860 	C$dynamixel.c$237$1$1 ==.
                           1861 ;	apps/dynamixel_test/dynamixel.c:237: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   095C 78 00              1862 	mov	r0,#_dynamixel_txpacket
   095E E2                 1863 	movx	a,@r0
   095F 24 05              1864 	add	a,#0x05
   0961 FD                 1865 	mov	r5,a
   0962 08                 1866 	inc	r0
   0963 E2                 1867 	movx	a,@r0
   0964 34 00              1868 	addc	a,#0x00
   0966 FE                 1869 	mov	r6,a
   0967 08                 1870 	inc	r0
   0968 E2                 1871 	movx	a,@r0
   0969 FF                 1872 	mov	r7,a
   096A 8D 82              1873 	mov	dpl,r5
   096C 8E 83              1874 	mov	dph,r6
   096E 8F F0              1875 	mov	b,r7
   0970 78 1E              1876 	mov	r0,#_dynamixel_readword_PARM_2
   0972 E2                 1877 	movx	a,@r0
   0973 12 17 81           1878 	lcall	__gptrput
                    0488   1879 	C$dynamixel.c$238$1$1 ==.
                           1880 ;	apps/dynamixel_test/dynamixel.c:238: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) 2;
   0976 78 00              1881 	mov	r0,#_dynamixel_txpacket
   0978 E2                 1882 	movx	a,@r0
   0979 24 06              1883 	add	a,#0x06
   097B FD                 1884 	mov	r5,a
   097C 08                 1885 	inc	r0
   097D E2                 1886 	movx	a,@r0
   097E 34 00              1887 	addc	a,#0x00
   0980 FE                 1888 	mov	r6,a
   0981 08                 1889 	inc	r0
   0982 E2                 1890 	movx	a,@r0
   0983 FF                 1891 	mov	r7,a
   0984 8D 82              1892 	mov	dpl,r5
   0986 8E 83              1893 	mov	dph,r6
   0988 8F F0              1894 	mov	b,r7
   098A 74 02              1895 	mov	a,#0x02
   098C 12 17 81           1896 	lcall	__gptrput
                    04A1   1897 	C$dynamixel.c$240$1$1 ==.
                           1898 ;	apps/dynamixel_test/dynamixel.c:240: result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   098F 78 03              1899 	mov	r0,#_dynamixel_rxpacket
   0991 79 13              1900 	mov	r1,#_dynamixel_txrx_PARM_2
   0993 E2                 1901 	movx	a,@r0
   0994 F3                 1902 	movx	@r1,a
   0995 08                 1903 	inc	r0
   0996 E2                 1904 	movx	a,@r0
   0997 09                 1905 	inc	r1
   0998 F3                 1906 	movx	@r1,a
   0999 08                 1907 	inc	r0
   099A E2                 1908 	movx	a,@r0
   099B 09                 1909 	inc	r1
   099C F3                 1910 	movx	@r1,a
   099D 78 00              1911 	mov	r0,#_dynamixel_txpacket
   099F E2                 1912 	movx	a,@r0
   09A0 F5 82              1913 	mov	dpl,a
   09A2 08                 1914 	inc	r0
   09A3 E2                 1915 	movx	a,@r0
   09A4 F5 83              1916 	mov	dph,a
   09A6 08                 1917 	inc	r0
   09A7 E2                 1918 	movx	a,@r0
   09A8 F5 F0              1919 	mov	b,a
   09AA 12 06 BE           1920 	lcall	_dynamixel_txrx
   09AD AF 82              1921 	mov	r7,dpl
                    04C1   1922 	C$dynamixel.c$242$1$1 ==.
                           1923 ;	apps/dynamixel_test/dynamixel.c:242: if(result == DYNAMIXEL_SUCCESS)
   09AF BF 01 66           1924 	cjne	r7,#0x01,00102$
                    04C4   1925 	C$dynamixel.c$243$1$1 ==.
                           1926 ;	apps/dynamixel_test/dynamixel.c:243: *value = (uint16) dynamixel_makeword(dynamixel_rxpacket[DYNAMIXEL_PARAMETER], dynamixel_rxpacket[DYNAMIXEL_PARAMETER+1]);
   09B2 C0 07              1927 	push	ar7
   09B4 78 1F              1928 	mov	r0,#_dynamixel_readword_PARM_3
   09B6 E2                 1929 	movx	a,@r0
   09B7 FC                 1930 	mov	r4,a
   09B8 08                 1931 	inc	r0
   09B9 E2                 1932 	movx	a,@r0
   09BA FD                 1933 	mov	r5,a
   09BB 08                 1934 	inc	r0
   09BC E2                 1935 	movx	a,@r0
   09BD FE                 1936 	mov	r6,a
   09BE 78 03              1937 	mov	r0,#_dynamixel_rxpacket
   09C0 E2                 1938 	movx	a,@r0
   09C1 24 05              1939 	add	a,#0x05
   09C3 FA                 1940 	mov	r2,a
   09C4 08                 1941 	inc	r0
   09C5 E2                 1942 	movx	a,@r0
   09C6 34 00              1943 	addc	a,#0x00
   09C8 FB                 1944 	mov	r3,a
   09C9 08                 1945 	inc	r0
   09CA E2                 1946 	movx	a,@r0
   09CB FF                 1947 	mov	r7,a
   09CC 8A 82              1948 	mov	dpl,r2
   09CE 8B 83              1949 	mov	dph,r3
   09D0 8F F0              1950 	mov	b,r7
   09D2 12 20 12           1951 	lcall	__gptrget
   09D5 F5 0B              1952 	mov	_dynamixel_readword_sloc0_1_0,a
   09D7 78 03              1953 	mov	r0,#_dynamixel_rxpacket
   09D9 E2                 1954 	movx	a,@r0
   09DA 24 06              1955 	add	a,#0x06
   09DC FA                 1956 	mov	r2,a
   09DD 08                 1957 	inc	r0
   09DE E2                 1958 	movx	a,@r0
   09DF 34 00              1959 	addc	a,#0x00
   09E1 FB                 1960 	mov	r3,a
   09E2 08                 1961 	inc	r0
   09E3 E2                 1962 	movx	a,@r0
   09E4 FF                 1963 	mov	r7,a
   09E5 8A 82              1964 	mov	dpl,r2
   09E7 8B 83              1965 	mov	dph,r3
   09E9 8F F0              1966 	mov	b,r7
   09EB 12 20 12           1967 	lcall	__gptrget
   09EE 78 34              1968 	mov	r0,#_dynamixel_makeword_PARM_2
   09F0 F2                 1969 	movx	@r0,a
   09F1 85 0B 82           1970 	mov	dpl,_dynamixel_readword_sloc0_1_0
   09F4 C0 06              1971 	push	ar6
   09F6 C0 05              1972 	push	ar5
   09F8 C0 04              1973 	push	ar4
   09FA 12 0E 43           1974 	lcall	_dynamixel_makeword
   09FD AB 82              1975 	mov	r3,dpl
   09FF AF 83              1976 	mov	r7,dph
   0A01 D0 04              1977 	pop	ar4
   0A03 D0 05              1978 	pop	ar5
   0A05 D0 06              1979 	pop	ar6
   0A07 8C 82              1980 	mov	dpl,r4
   0A09 8D 83              1981 	mov	dph,r5
   0A0B 8E F0              1982 	mov	b,r6
   0A0D EB                 1983 	mov	a,r3
   0A0E 12 17 81           1984 	lcall	__gptrput
   0A11 A3                 1985 	inc	dptr
   0A12 EF                 1986 	mov	a,r7
   0A13 12 17 81           1987 	lcall	__gptrput
                    0528   1988 	C$dynamixel.c$245$1$1 ==.
                           1989 ;	apps/dynamixel_test/dynamixel.c:245: return result;
   0A16 D0 07              1990 	pop	ar7
                    052A   1991 	C$dynamixel.c$243$1$1 ==.
                           1992 ;	apps/dynamixel_test/dynamixel.c:243: *value = (uint16) dynamixel_makeword(dynamixel_rxpacket[DYNAMIXEL_PARAMETER], dynamixel_rxpacket[DYNAMIXEL_PARAMETER+1]);
   0A18                    1993 00102$:
                    052A   1994 	C$dynamixel.c$245$1$1 ==.
                           1995 ;	apps/dynamixel_test/dynamixel.c:245: return result;
   0A18 8F 82              1996 	mov	dpl,r7
                    052C   1997 	C$dynamixel.c$246$1$1 ==.
                    052C   1998 	XG$dynamixel_readword$0$0 ==.
   0A1A 22                 1999 	ret
                           2000 ;------------------------------------------------------------
                           2001 ;Allocation info for local variables in function 'dynamixel_readtable'
                           2002 ;------------------------------------------------------------
                    052D   2003 	G$dynamixel_readtable$0$0 ==.
                    052D   2004 	C$dynamixel.c$248$1$1 ==.
                           2005 ;	apps/dynamixel_test/dynamixel.c:248: uint8 dynamixel_readtable(uint8 id, uint8 start_address, uint8 end_address, uint8* table)
                           2006 ;	-----------------------------------------
                           2007 ;	 function dynamixel_readtable
                           2008 ;	-----------------------------------------
   0A1B                    2009 _dynamixel_readtable:
   0A1B AF 82              2010 	mov	r7,dpl
                    052F   2011 	C$dynamixel.c$251$1$1 ==.
                           2012 ;	apps/dynamixel_test/dynamixel.c:251: uint8 length = end_address - start_address + 1;
   0A1D 78 23              2013 	mov	r0,#_dynamixel_readtable_PARM_3
   0A1F 79 22              2014 	mov	r1,#_dynamixel_readtable_PARM_2
   0A21 E3                 2015 	movx	a,@r1
   0A22 F5 F0              2016 	mov	b,a
   0A24 C3                 2017 	clr	c
   0A25 E2                 2018 	movx	a,@r0
   0A26 95 F0              2019 	subb	a,b
   0A28 78 27              2020 	mov	r0,#_dynamixel_readtable_length_1_1
   0A2A 04                 2021 	inc	a
   0A2B F2                 2022 	movx	@r0,a
                    053E   2023 	C$dynamixel.c$253$1$1 ==.
                           2024 ;	apps/dynamixel_test/dynamixel.c:253: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0A2C 78 00              2025 	mov	r0,#_dynamixel_txpacket
   0A2E E2                 2026 	movx	a,@r0
   0A2F 24 02              2027 	add	a,#0x02
   0A31 FB                 2028 	mov	r3,a
   0A32 08                 2029 	inc	r0
   0A33 E2                 2030 	movx	a,@r0
   0A34 34 00              2031 	addc	a,#0x00
   0A36 FC                 2032 	mov	r4,a
   0A37 08                 2033 	inc	r0
   0A38 E2                 2034 	movx	a,@r0
   0A39 FD                 2035 	mov	r5,a
   0A3A 8B 82              2036 	mov	dpl,r3
   0A3C 8C 83              2037 	mov	dph,r4
   0A3E 8D F0              2038 	mov	b,r5
   0A40 EF                 2039 	mov	a,r7
   0A41 12 17 81           2040 	lcall	__gptrput
                    0556   2041 	C$dynamixel.c$254$1$1 ==.
                           2042 ;	apps/dynamixel_test/dynamixel.c:254: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
   0A44 78 00              2043 	mov	r0,#_dynamixel_txpacket
   0A46 E2                 2044 	movx	a,@r0
   0A47 24 03              2045 	add	a,#0x03
   0A49 FC                 2046 	mov	r4,a
   0A4A 08                 2047 	inc	r0
   0A4B E2                 2048 	movx	a,@r0
   0A4C 34 00              2049 	addc	a,#0x00
   0A4E FD                 2050 	mov	r5,a
   0A4F 08                 2051 	inc	r0
   0A50 E2                 2052 	movx	a,@r0
   0A51 FF                 2053 	mov	r7,a
   0A52 8C 82              2054 	mov	dpl,r4
   0A54 8D 83              2055 	mov	dph,r5
   0A56 8F F0              2056 	mov	b,r7
   0A58 74 04              2057 	mov	a,#0x04
   0A5A 12 17 81           2058 	lcall	__gptrput
                    056F   2059 	C$dynamixel.c$255$1$1 ==.
                           2060 ;	apps/dynamixel_test/dynamixel.c:255: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_READ;
   0A5D 78 00              2061 	mov	r0,#_dynamixel_txpacket
   0A5F E2                 2062 	movx	a,@r0
   0A60 24 04              2063 	add	a,#0x04
   0A62 FC                 2064 	mov	r4,a
   0A63 08                 2065 	inc	r0
   0A64 E2                 2066 	movx	a,@r0
   0A65 34 00              2067 	addc	a,#0x00
   0A67 FD                 2068 	mov	r5,a
   0A68 08                 2069 	inc	r0
   0A69 E2                 2070 	movx	a,@r0
   0A6A FF                 2071 	mov	r7,a
   0A6B 8C 82              2072 	mov	dpl,r4
   0A6D 8D 83              2073 	mov	dph,r5
   0A6F 8F F0              2074 	mov	b,r7
   0A71 74 02              2075 	mov	a,#0x02
   0A73 12 17 81           2076 	lcall	__gptrput
                    0588   2077 	C$dynamixel.c$256$1$1 ==.
                           2078 ;	apps/dynamixel_test/dynamixel.c:256: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) start_address;
   0A76 78 00              2079 	mov	r0,#_dynamixel_txpacket
   0A78 E2                 2080 	movx	a,@r0
   0A79 24 05              2081 	add	a,#0x05
   0A7B FC                 2082 	mov	r4,a
   0A7C 08                 2083 	inc	r0
   0A7D E2                 2084 	movx	a,@r0
   0A7E 34 00              2085 	addc	a,#0x00
   0A80 FD                 2086 	mov	r5,a
   0A81 08                 2087 	inc	r0
   0A82 E2                 2088 	movx	a,@r0
   0A83 FF                 2089 	mov	r7,a
   0A84 8C 82              2090 	mov	dpl,r4
   0A86 8D 83              2091 	mov	dph,r5
   0A88 8F F0              2092 	mov	b,r7
   0A8A 78 22              2093 	mov	r0,#_dynamixel_readtable_PARM_2
   0A8C E2                 2094 	movx	a,@r0
   0A8D 12 17 81           2095 	lcall	__gptrput
                    05A2   2096 	C$dynamixel.c$257$1$1 ==.
                           2097 ;	apps/dynamixel_test/dynamixel.c:257: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length;
   0A90 78 00              2098 	mov	r0,#_dynamixel_txpacket
   0A92 E2                 2099 	movx	a,@r0
   0A93 24 06              2100 	add	a,#0x06
   0A95 FC                 2101 	mov	r4,a
   0A96 08                 2102 	inc	r0
   0A97 E2                 2103 	movx	a,@r0
   0A98 34 00              2104 	addc	a,#0x00
   0A9A FD                 2105 	mov	r5,a
   0A9B 08                 2106 	inc	r0
   0A9C E2                 2107 	movx	a,@r0
   0A9D FF                 2108 	mov	r7,a
   0A9E 8C 82              2109 	mov	dpl,r4
   0AA0 8D 83              2110 	mov	dph,r5
   0AA2 8F F0              2111 	mov	b,r7
   0AA4 78 27              2112 	mov	r0,#_dynamixel_readtable_length_1_1
   0AA6 E2                 2113 	movx	a,@r0
   0AA7 12 17 81           2114 	lcall	__gptrput
                    05BC   2115 	C$dynamixel.c$259$1$1 ==.
                           2116 ;	apps/dynamixel_test/dynamixel.c:259: result = dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0AAA 78 03              2117 	mov	r0,#_dynamixel_rxpacket
   0AAC 79 13              2118 	mov	r1,#_dynamixel_txrx_PARM_2
   0AAE E2                 2119 	movx	a,@r0
   0AAF F3                 2120 	movx	@r1,a
   0AB0 08                 2121 	inc	r0
   0AB1 E2                 2122 	movx	a,@r0
   0AB2 09                 2123 	inc	r1
   0AB3 F3                 2124 	movx	@r1,a
   0AB4 08                 2125 	inc	r0
   0AB5 E2                 2126 	movx	a,@r0
   0AB6 09                 2127 	inc	r1
   0AB7 F3                 2128 	movx	@r1,a
   0AB8 78 00              2129 	mov	r0,#_dynamixel_txpacket
   0ABA E2                 2130 	movx	a,@r0
   0ABB F5 82              2131 	mov	dpl,a
   0ABD 08                 2132 	inc	r0
   0ABE E2                 2133 	movx	a,@r0
   0ABF F5 83              2134 	mov	dph,a
   0AC1 08                 2135 	inc	r0
   0AC2 E2                 2136 	movx	a,@r0
   0AC3 F5 F0              2137 	mov	b,a
   0AC5 12 06 BE           2138 	lcall	_dynamixel_txrx
   0AC8 AF 82              2139 	mov	r7,dpl
                    05DC   2140 	C$dynamixel.c$261$1$1 ==.
                           2141 ;	apps/dynamixel_test/dynamixel.c:261: if(result == DYNAMIXEL_SUCCESS)
   0ACA BF 01 60           2142 	cjne	r7,#0x01,00102$
                    05DF   2143 	C$dynamixel.c$264$1$1 ==.
                           2144 ;	apps/dynamixel_test/dynamixel.c:264: for(i = 0; i < length; i++)
   0ACD 78 28              2145 	mov	r0,#_dynamixel_readtable_i_2_2
   0ACF E4                 2146 	clr	a
   0AD0 F2                 2147 	movx	@r0,a
   0AD1                    2148 00103$:
   0AD1 78 28              2149 	mov	r0,#_dynamixel_readtable_i_2_2
   0AD3 79 27              2150 	mov	r1,#_dynamixel_readtable_length_1_1
   0AD5 C3                 2151 	clr	c
   0AD6 E3                 2152 	movx	a,@r1
   0AD7 F5 F0              2153 	mov	b,a
   0AD9 E2                 2154 	movx	a,@r0
   0ADA 95 F0              2155 	subb	a,b
   0ADC 50 4F              2156 	jnc	00102$
                    05F0   2157 	C$dynamixel.c$265$1$1 ==.
                           2158 ;	apps/dynamixel_test/dynamixel.c:265: table[start_address + i] = dynamixel_rxpacket[DYNAMIXEL_PARAMETER + i];
   0ADE C0 07              2159 	push	ar7
   0AE0 78 22              2160 	mov	r0,#_dynamixel_readtable_PARM_2
   0AE2 E2                 2161 	movx	a,@r0
   0AE3 FB                 2162 	mov	r3,a
   0AE4 7C 00              2163 	mov	r4,#0x00
   0AE6 78 28              2164 	mov	r0,#_dynamixel_readtable_i_2_2
   0AE8 E2                 2165 	movx	a,@r0
   0AE9 FA                 2166 	mov	r2,a
   0AEA 7F 00              2167 	mov	r7,#0x00
   0AEC 2B                 2168 	add	a,r3
   0AED FB                 2169 	mov	r3,a
   0AEE EF                 2170 	mov	a,r7
   0AEF 3C                 2171 	addc	a,r4
   0AF0 FC                 2172 	mov	r4,a
   0AF1 78 24              2173 	mov	r0,#_dynamixel_readtable_PARM_4
   0AF3 E2                 2174 	movx	a,@r0
   0AF4 2B                 2175 	add	a,r3
   0AF5 FB                 2176 	mov	r3,a
   0AF6 08                 2177 	inc	r0
   0AF7 E2                 2178 	movx	a,@r0
   0AF8 3C                 2179 	addc	a,r4
   0AF9 FC                 2180 	mov	r4,a
   0AFA 08                 2181 	inc	r0
   0AFB E2                 2182 	movx	a,@r0
   0AFC FE                 2183 	mov	r6,a
   0AFD 74 05              2184 	mov	a,#0x05
   0AFF 2A                 2185 	add	a,r2
   0B00 FA                 2186 	mov	r2,a
   0B01 E4                 2187 	clr	a
   0B02 3F                 2188 	addc	a,r7
   0B03 FF                 2189 	mov	r7,a
   0B04 78 03              2190 	mov	r0,#_dynamixel_rxpacket
   0B06 E2                 2191 	movx	a,@r0
   0B07 2A                 2192 	add	a,r2
   0B08 FA                 2193 	mov	r2,a
   0B09 08                 2194 	inc	r0
   0B0A E2                 2195 	movx	a,@r0
   0B0B 3F                 2196 	addc	a,r7
   0B0C FD                 2197 	mov	r5,a
   0B0D 08                 2198 	inc	r0
   0B0E E2                 2199 	movx	a,@r0
   0B0F FF                 2200 	mov	r7,a
   0B10 8A 82              2201 	mov	dpl,r2
   0B12 8D 83              2202 	mov	dph,r5
   0B14 8F F0              2203 	mov	b,r7
   0B16 12 20 12           2204 	lcall	__gptrget
   0B19 FA                 2205 	mov	r2,a
   0B1A 8B 82              2206 	mov	dpl,r3
   0B1C 8C 83              2207 	mov	dph,r4
   0B1E 8E F0              2208 	mov	b,r6
   0B20 12 17 81           2209 	lcall	__gptrput
                    0635   2210 	C$dynamixel.c$264$2$2 ==.
                           2211 ;	apps/dynamixel_test/dynamixel.c:264: for(i = 0; i < length; i++)
   0B23 78 28              2212 	mov	r0,#_dynamixel_readtable_i_2_2
   0B25 E2                 2213 	movx	a,@r0
   0B26 24 01              2214 	add	a,#0x01
   0B28 F2                 2215 	movx	@r0,a
   0B29 D0 07              2216 	pop	ar7
   0B2B 80 A4              2217 	sjmp	00103$
   0B2D                    2218 00102$:
                    063F   2219 	C$dynamixel.c$268$1$1 ==.
                           2220 ;	apps/dynamixel_test/dynamixel.c:268: return result;
   0B2D 8F 82              2221 	mov	dpl,r7
                    0641   2222 	C$dynamixel.c$269$1$1 ==.
                    0641   2223 	XG$dynamixel_readtable$0$0 ==.
   0B2F 22                 2224 	ret
                           2225 ;------------------------------------------------------------
                           2226 ;Allocation info for local variables in function 'dynamixel_writebyte'
                           2227 ;------------------------------------------------------------
                    0642   2228 	G$dynamixel_writebyte$0$0 ==.
                    0642   2229 	C$dynamixel.c$272$1$1 ==.
                           2230 ;	apps/dynamixel_test/dynamixel.c:272: uint8 dynamixel_writebyte(uint8 id, uint8 address, uint8 value)
                           2231 ;	-----------------------------------------
                           2232 ;	 function dynamixel_writebyte
                           2233 ;	-----------------------------------------
   0B30                    2234 _dynamixel_writebyte:
   0B30 AF 82              2235 	mov	r7,dpl
                    0644   2236 	C$dynamixel.c$274$1$1 ==.
                           2237 ;	apps/dynamixel_test/dynamixel.c:274: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0B32 78 00              2238 	mov	r0,#_dynamixel_txpacket
   0B34 E2                 2239 	movx	a,@r0
   0B35 24 02              2240 	add	a,#0x02
   0B37 FC                 2241 	mov	r4,a
   0B38 08                 2242 	inc	r0
   0B39 E2                 2243 	movx	a,@r0
   0B3A 34 00              2244 	addc	a,#0x00
   0B3C FD                 2245 	mov	r5,a
   0B3D 08                 2246 	inc	r0
   0B3E E2                 2247 	movx	a,@r0
   0B3F FE                 2248 	mov	r6,a
   0B40 8C 82              2249 	mov	dpl,r4
   0B42 8D 83              2250 	mov	dph,r5
   0B44 8E F0              2251 	mov	b,r6
   0B46 EF                 2252 	mov	a,r7
   0B47 12 17 81           2253 	lcall	__gptrput
                    065C   2254 	C$dynamixel.c$275$1$1 ==.
                           2255 ;	apps/dynamixel_test/dynamixel.c:275: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 4;
   0B4A 78 00              2256 	mov	r0,#_dynamixel_txpacket
   0B4C E2                 2257 	movx	a,@r0
   0B4D 24 03              2258 	add	a,#0x03
   0B4F FD                 2259 	mov	r5,a
   0B50 08                 2260 	inc	r0
   0B51 E2                 2261 	movx	a,@r0
   0B52 34 00              2262 	addc	a,#0x00
   0B54 FE                 2263 	mov	r6,a
   0B55 08                 2264 	inc	r0
   0B56 E2                 2265 	movx	a,@r0
   0B57 FF                 2266 	mov	r7,a
   0B58 8D 82              2267 	mov	dpl,r5
   0B5A 8E 83              2268 	mov	dph,r6
   0B5C 8F F0              2269 	mov	b,r7
   0B5E 74 04              2270 	mov	a,#0x04
   0B60 12 17 81           2271 	lcall	__gptrput
                    0675   2272 	C$dynamixel.c$276$1$1 ==.
                           2273 ;	apps/dynamixel_test/dynamixel.c:276: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
   0B63 78 00              2274 	mov	r0,#_dynamixel_txpacket
   0B65 E2                 2275 	movx	a,@r0
   0B66 24 04              2276 	add	a,#0x04
   0B68 FD                 2277 	mov	r5,a
   0B69 08                 2278 	inc	r0
   0B6A E2                 2279 	movx	a,@r0
   0B6B 34 00              2280 	addc	a,#0x00
   0B6D FE                 2281 	mov	r6,a
   0B6E 08                 2282 	inc	r0
   0B6F E2                 2283 	movx	a,@r0
   0B70 FF                 2284 	mov	r7,a
   0B71 8D 82              2285 	mov	dpl,r5
   0B73 8E 83              2286 	mov	dph,r6
   0B75 8F F0              2287 	mov	b,r7
   0B77 74 03              2288 	mov	a,#0x03
   0B79 12 17 81           2289 	lcall	__gptrput
                    068E   2290 	C$dynamixel.c$277$1$1 ==.
                           2291 ;	apps/dynamixel_test/dynamixel.c:277: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   0B7C 78 00              2292 	mov	r0,#_dynamixel_txpacket
   0B7E E2                 2293 	movx	a,@r0
   0B7F 24 05              2294 	add	a,#0x05
   0B81 FD                 2295 	mov	r5,a
   0B82 08                 2296 	inc	r0
   0B83 E2                 2297 	movx	a,@r0
   0B84 34 00              2298 	addc	a,#0x00
   0B86 FE                 2299 	mov	r6,a
   0B87 08                 2300 	inc	r0
   0B88 E2                 2301 	movx	a,@r0
   0B89 FF                 2302 	mov	r7,a
   0B8A 8D 82              2303 	mov	dpl,r5
   0B8C 8E 83              2304 	mov	dph,r6
   0B8E 8F F0              2305 	mov	b,r7
   0B90 78 29              2306 	mov	r0,#_dynamixel_writebyte_PARM_2
   0B92 E2                 2307 	movx	a,@r0
   0B93 12 17 81           2308 	lcall	__gptrput
                    06A8   2309 	C$dynamixel.c$278$1$1 ==.
                           2310 ;	apps/dynamixel_test/dynamixel.c:278: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) value;
   0B96 78 00              2311 	mov	r0,#_dynamixel_txpacket
   0B98 E2                 2312 	movx	a,@r0
   0B99 24 06              2313 	add	a,#0x06
   0B9B FD                 2314 	mov	r5,a
   0B9C 08                 2315 	inc	r0
   0B9D E2                 2316 	movx	a,@r0
   0B9E 34 00              2317 	addc	a,#0x00
   0BA0 FE                 2318 	mov	r6,a
   0BA1 08                 2319 	inc	r0
   0BA2 E2                 2320 	movx	a,@r0
   0BA3 FF                 2321 	mov	r7,a
   0BA4 8D 82              2322 	mov	dpl,r5
   0BA6 8E 83              2323 	mov	dph,r6
   0BA8 8F F0              2324 	mov	b,r7
   0BAA 78 2A              2325 	mov	r0,#_dynamixel_writebyte_PARM_3
   0BAC E2                 2326 	movx	a,@r0
   0BAD 12 17 81           2327 	lcall	__gptrput
                    06C2   2328 	C$dynamixel.c$280$1$1 ==.
                           2329 ;	apps/dynamixel_test/dynamixel.c:280: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0BB0 78 03              2330 	mov	r0,#_dynamixel_rxpacket
   0BB2 79 13              2331 	mov	r1,#_dynamixel_txrx_PARM_2
   0BB4 E2                 2332 	movx	a,@r0
   0BB5 F3                 2333 	movx	@r1,a
   0BB6 08                 2334 	inc	r0
   0BB7 E2                 2335 	movx	a,@r0
   0BB8 09                 2336 	inc	r1
   0BB9 F3                 2337 	movx	@r1,a
   0BBA 08                 2338 	inc	r0
   0BBB E2                 2339 	movx	a,@r0
   0BBC 09                 2340 	inc	r1
   0BBD F3                 2341 	movx	@r1,a
   0BBE 78 00              2342 	mov	r0,#_dynamixel_txpacket
   0BC0 E2                 2343 	movx	a,@r0
   0BC1 F5 82              2344 	mov	dpl,a
   0BC3 08                 2345 	inc	r0
   0BC4 E2                 2346 	movx	a,@r0
   0BC5 F5 83              2347 	mov	dph,a
   0BC7 08                 2348 	inc	r0
   0BC8 E2                 2349 	movx	a,@r0
   0BC9 F5 F0              2350 	mov	b,a
   0BCB 12 06 BE           2351 	lcall	_dynamixel_txrx
                    06E0   2352 	C$dynamixel.c$281$1$1 ==.
                    06E0   2353 	XG$dynamixel_writebyte$0$0 ==.
   0BCE 22                 2354 	ret
                           2355 ;------------------------------------------------------------
                           2356 ;Allocation info for local variables in function 'dynamixel_writeword'
                           2357 ;------------------------------------------------------------
                    06E1   2358 	G$dynamixel_writeword$0$0 ==.
                    06E1   2359 	C$dynamixel.c$283$1$1 ==.
                           2360 ;	apps/dynamixel_test/dynamixel.c:283: uint8 dynamixel_writeword(uint8 id, uint8 address, uint16 value)
                           2361 ;	-----------------------------------------
                           2362 ;	 function dynamixel_writeword
                           2363 ;	-----------------------------------------
   0BCF                    2364 _dynamixel_writeword:
   0BCF AF 82              2365 	mov	r7,dpl
                    06E3   2366 	C$dynamixel.c$285$1$1 ==.
                           2367 ;	apps/dynamixel_test/dynamixel.c:285: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0BD1 78 00              2368 	mov	r0,#_dynamixel_txpacket
   0BD3 E2                 2369 	movx	a,@r0
   0BD4 24 02              2370 	add	a,#0x02
   0BD6 FC                 2371 	mov	r4,a
   0BD7 08                 2372 	inc	r0
   0BD8 E2                 2373 	movx	a,@r0
   0BD9 34 00              2374 	addc	a,#0x00
   0BDB FD                 2375 	mov	r5,a
   0BDC 08                 2376 	inc	r0
   0BDD E2                 2377 	movx	a,@r0
   0BDE FE                 2378 	mov	r6,a
   0BDF 8C 82              2379 	mov	dpl,r4
   0BE1 8D 83              2380 	mov	dph,r5
   0BE3 8E F0              2381 	mov	b,r6
   0BE5 EF                 2382 	mov	a,r7
   0BE6 12 17 81           2383 	lcall	__gptrput
                    06FB   2384 	C$dynamixel.c$286$1$1 ==.
                           2385 ;	apps/dynamixel_test/dynamixel.c:286: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 5;
   0BE9 78 00              2386 	mov	r0,#_dynamixel_txpacket
   0BEB E2                 2387 	movx	a,@r0
   0BEC 24 03              2388 	add	a,#0x03
   0BEE FD                 2389 	mov	r5,a
   0BEF 08                 2390 	inc	r0
   0BF0 E2                 2391 	movx	a,@r0
   0BF1 34 00              2392 	addc	a,#0x00
   0BF3 FE                 2393 	mov	r6,a
   0BF4 08                 2394 	inc	r0
   0BF5 E2                 2395 	movx	a,@r0
   0BF6 FF                 2396 	mov	r7,a
   0BF7 8D 82              2397 	mov	dpl,r5
   0BF9 8E 83              2398 	mov	dph,r6
   0BFB 8F F0              2399 	mov	b,r7
   0BFD 74 05              2400 	mov	a,#0x05
   0BFF 12 17 81           2401 	lcall	__gptrput
                    0714   2402 	C$dynamixel.c$287$1$1 ==.
                           2403 ;	apps/dynamixel_test/dynamixel.c:287: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
   0C02 78 00              2404 	mov	r0,#_dynamixel_txpacket
   0C04 E2                 2405 	movx	a,@r0
   0C05 24 04              2406 	add	a,#0x04
   0C07 FD                 2407 	mov	r5,a
   0C08 08                 2408 	inc	r0
   0C09 E2                 2409 	movx	a,@r0
   0C0A 34 00              2410 	addc	a,#0x00
   0C0C FE                 2411 	mov	r6,a
   0C0D 08                 2412 	inc	r0
   0C0E E2                 2413 	movx	a,@r0
   0C0F FF                 2414 	mov	r7,a
   0C10 8D 82              2415 	mov	dpl,r5
   0C12 8E 83              2416 	mov	dph,r6
   0C14 8F F0              2417 	mov	b,r7
   0C16 74 03              2418 	mov	a,#0x03
   0C18 12 17 81           2419 	lcall	__gptrput
                    072D   2420 	C$dynamixel.c$288$1$1 ==.
                           2421 ;	apps/dynamixel_test/dynamixel.c:288: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   0C1B 78 00              2422 	mov	r0,#_dynamixel_txpacket
   0C1D E2                 2423 	movx	a,@r0
   0C1E 24 05              2424 	add	a,#0x05
   0C20 FD                 2425 	mov	r5,a
   0C21 08                 2426 	inc	r0
   0C22 E2                 2427 	movx	a,@r0
   0C23 34 00              2428 	addc	a,#0x00
   0C25 FE                 2429 	mov	r6,a
   0C26 08                 2430 	inc	r0
   0C27 E2                 2431 	movx	a,@r0
   0C28 FF                 2432 	mov	r7,a
   0C29 8D 82              2433 	mov	dpl,r5
   0C2B 8E 83              2434 	mov	dph,r6
   0C2D 8F F0              2435 	mov	b,r7
   0C2F 78 2B              2436 	mov	r0,#_dynamixel_writeword_PARM_2
   0C31 E2                 2437 	movx	a,@r0
   0C32 12 17 81           2438 	lcall	__gptrput
                    0747   2439 	C$dynamixel.c$289$1$1 ==.
                           2440 ;	apps/dynamixel_test/dynamixel.c:289: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) dynamixel_getlowbyte(value);
   0C35 78 00              2441 	mov	r0,#_dynamixel_txpacket
   0C37 E2                 2442 	movx	a,@r0
   0C38 24 06              2443 	add	a,#0x06
   0C3A FD                 2444 	mov	r5,a
   0C3B 08                 2445 	inc	r0
   0C3C E2                 2446 	movx	a,@r0
   0C3D 34 00              2447 	addc	a,#0x00
   0C3F FE                 2448 	mov	r6,a
   0C40 08                 2449 	inc	r0
   0C41 E2                 2450 	movx	a,@r0
   0C42 FF                 2451 	mov	r7,a
   0C43 78 2C              2452 	mov	r0,#_dynamixel_writeword_PARM_3
   0C45 E2                 2453 	movx	a,@r0
   0C46 F5 82              2454 	mov	dpl,a
   0C48 08                 2455 	inc	r0
   0C49 E2                 2456 	movx	a,@r0
   0C4A F5 83              2457 	mov	dph,a
   0C4C C0 07              2458 	push	ar7
   0C4E C0 06              2459 	push	ar6
   0C50 C0 05              2460 	push	ar5
   0C52 12 0E 56           2461 	lcall	_dynamixel_getlowbyte
   0C55 AC 82              2462 	mov	r4,dpl
   0C57 D0 05              2463 	pop	ar5
   0C59 D0 06              2464 	pop	ar6
   0C5B D0 07              2465 	pop	ar7
   0C5D 8D 82              2466 	mov	dpl,r5
   0C5F 8E 83              2467 	mov	dph,r6
   0C61 8F F0              2468 	mov	b,r7
   0C63 EC                 2469 	mov	a,r4
   0C64 12 17 81           2470 	lcall	__gptrput
                    0779   2471 	C$dynamixel.c$290$1$1 ==.
                           2472 ;	apps/dynamixel_test/dynamixel.c:290: dynamixel_txpacket[DYNAMIXEL_PARAMETER+2] = (uint8) dynamixel_gethighbyte(value);
   0C67 78 00              2473 	mov	r0,#_dynamixel_txpacket
   0C69 E2                 2474 	movx	a,@r0
   0C6A 24 07              2475 	add	a,#0x07
   0C6C FD                 2476 	mov	r5,a
   0C6D 08                 2477 	inc	r0
   0C6E E2                 2478 	movx	a,@r0
   0C6F 34 00              2479 	addc	a,#0x00
   0C71 FE                 2480 	mov	r6,a
   0C72 08                 2481 	inc	r0
   0C73 E2                 2482 	movx	a,@r0
   0C74 FF                 2483 	mov	r7,a
   0C75 78 2C              2484 	mov	r0,#_dynamixel_writeword_PARM_3
   0C77 E2                 2485 	movx	a,@r0
   0C78 F5 82              2486 	mov	dpl,a
   0C7A 08                 2487 	inc	r0
   0C7B E2                 2488 	movx	a,@r0
   0C7C F5 83              2489 	mov	dph,a
   0C7E C0 07              2490 	push	ar7
   0C80 C0 06              2491 	push	ar6
   0C82 C0 05              2492 	push	ar5
   0C84 12 0E 57           2493 	lcall	_dynamixel_gethighbyte
   0C87 AC 82              2494 	mov	r4,dpl
   0C89 D0 05              2495 	pop	ar5
   0C8B D0 06              2496 	pop	ar6
   0C8D D0 07              2497 	pop	ar7
   0C8F 8D 82              2498 	mov	dpl,r5
   0C91 8E 83              2499 	mov	dph,r6
   0C93 8F F0              2500 	mov	b,r7
   0C95 EC                 2501 	mov	a,r4
   0C96 12 17 81           2502 	lcall	__gptrput
                    07AB   2503 	C$dynamixel.c$292$1$1 ==.
                           2504 ;	apps/dynamixel_test/dynamixel.c:292: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0C99 78 03              2505 	mov	r0,#_dynamixel_rxpacket
   0C9B 79 13              2506 	mov	r1,#_dynamixel_txrx_PARM_2
   0C9D E2                 2507 	movx	a,@r0
   0C9E F3                 2508 	movx	@r1,a
   0C9F 08                 2509 	inc	r0
   0CA0 E2                 2510 	movx	a,@r0
   0CA1 09                 2511 	inc	r1
   0CA2 F3                 2512 	movx	@r1,a
   0CA3 08                 2513 	inc	r0
   0CA4 E2                 2514 	movx	a,@r0
   0CA5 09                 2515 	inc	r1
   0CA6 F3                 2516 	movx	@r1,a
   0CA7 78 00              2517 	mov	r0,#_dynamixel_txpacket
   0CA9 E2                 2518 	movx	a,@r0
   0CAA F5 82              2519 	mov	dpl,a
   0CAC 08                 2520 	inc	r0
   0CAD E2                 2521 	movx	a,@r0
   0CAE F5 83              2522 	mov	dph,a
   0CB0 08                 2523 	inc	r0
   0CB1 E2                 2524 	movx	a,@r0
   0CB2 F5 F0              2525 	mov	b,a
   0CB4 12 06 BE           2526 	lcall	_dynamixel_txrx
                    07C9   2527 	C$dynamixel.c$293$1$1 ==.
                    07C9   2528 	XG$dynamixel_writeword$0$0 ==.
   0CB7 22                 2529 	ret
                           2530 ;------------------------------------------------------------
                           2531 ;Allocation info for local variables in function 'dynamixel_syncwrite'
                           2532 ;------------------------------------------------------------
                    07CA   2533 	G$dynamixel_syncwrite$0$0 ==.
                    07CA   2534 	C$dynamixel.c$295$1$1 ==.
                           2535 ;	apps/dynamixel_test/dynamixel.c:295: uint8 dynamixel_syncwrite(uint8 address, uint8 length, uint8 number, uint8* param)
                           2536 ;	-----------------------------------------
                           2537 ;	 function dynamixel_syncwrite
                           2538 ;	-----------------------------------------
   0CB8                    2539 _dynamixel_syncwrite:
   0CB8 AF 82              2540 	mov	r7,dpl
                    07CC   2541 	C$dynamixel.c$299$1$1 ==.
                           2542 ;	apps/dynamixel_test/dynamixel.c:299: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) DYNAMIXEL_BROADCAST_ID;
   0CBA 78 00              2543 	mov	r0,#_dynamixel_txpacket
   0CBC E2                 2544 	movx	a,@r0
   0CBD 24 02              2545 	add	a,#0x02
   0CBF FC                 2546 	mov	r4,a
   0CC0 08                 2547 	inc	r0
   0CC1 E2                 2548 	movx	a,@r0
   0CC2 34 00              2549 	addc	a,#0x00
   0CC4 FD                 2550 	mov	r5,a
   0CC5 08                 2551 	inc	r0
   0CC6 E2                 2552 	movx	a,@r0
   0CC7 FE                 2553 	mov	r6,a
   0CC8 8C 82              2554 	mov	dpl,r4
   0CCA 8D 83              2555 	mov	dph,r5
   0CCC 8E F0              2556 	mov	b,r6
   0CCE 74 FE              2557 	mov	a,#0xFE
   0CD0 12 17 81           2558 	lcall	__gptrput
                    07E5   2559 	C$dynamixel.c$300$1$1 ==.
                           2560 ;	apps/dynamixel_test/dynamixel.c:300: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_SYNC_WRITE;
   0CD3 78 00              2561 	mov	r0,#_dynamixel_txpacket
   0CD5 E2                 2562 	movx	a,@r0
   0CD6 24 04              2563 	add	a,#0x04
   0CD8 FC                 2564 	mov	r4,a
   0CD9 08                 2565 	inc	r0
   0CDA E2                 2566 	movx	a,@r0
   0CDB 34 00              2567 	addc	a,#0x00
   0CDD FD                 2568 	mov	r5,a
   0CDE 08                 2569 	inc	r0
   0CDF E2                 2570 	movx	a,@r0
   0CE0 FE                 2571 	mov	r6,a
   0CE1 8C 82              2572 	mov	dpl,r4
   0CE3 8D 83              2573 	mov	dph,r5
   0CE5 8E F0              2574 	mov	b,r6
   0CE7 74 83              2575 	mov	a,#0x83
   0CE9 12 17 81           2576 	lcall	__gptrput
                    07FE   2577 	C$dynamixel.c$301$1$1 ==.
                           2578 ;	apps/dynamixel_test/dynamixel.c:301: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   0CEC 78 00              2579 	mov	r0,#_dynamixel_txpacket
   0CEE E2                 2580 	movx	a,@r0
   0CEF 24 05              2581 	add	a,#0x05
   0CF1 FC                 2582 	mov	r4,a
   0CF2 08                 2583 	inc	r0
   0CF3 E2                 2584 	movx	a,@r0
   0CF4 34 00              2585 	addc	a,#0x00
   0CF6 FD                 2586 	mov	r5,a
   0CF7 08                 2587 	inc	r0
   0CF8 E2                 2588 	movx	a,@r0
   0CF9 FE                 2589 	mov	r6,a
   0CFA 8C 82              2590 	mov	dpl,r4
   0CFC 8D 83              2591 	mov	dph,r5
   0CFE 8E F0              2592 	mov	b,r6
   0D00 EF                 2593 	mov	a,r7
   0D01 12 17 81           2594 	lcall	__gptrput
                    0816   2595 	C$dynamixel.c$302$1$1 ==.
                           2596 ;	apps/dynamixel_test/dynamixel.c:302: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length; // The length of the packet where its value is “Number of parameters (N) +2”
   0D04 78 00              2597 	mov	r0,#_dynamixel_txpacket
   0D06 E2                 2598 	movx	a,@r0
   0D07 24 06              2599 	add	a,#0x06
   0D09 FD                 2600 	mov	r5,a
   0D0A 08                 2601 	inc	r0
   0D0B E2                 2602 	movx	a,@r0
   0D0C 34 00              2603 	addc	a,#0x00
   0D0E FE                 2604 	mov	r6,a
   0D0F 08                 2605 	inc	r0
   0D10 E2                 2606 	movx	a,@r0
   0D11 FF                 2607 	mov	r7,a
   0D12 8D 82              2608 	mov	dpl,r5
   0D14 8E 83              2609 	mov	dph,r6
   0D16 8F F0              2610 	mov	b,r7
   0D18 78 2E              2611 	mov	r0,#_dynamixel_syncwrite_PARM_2
   0D1A E2                 2612 	movx	a,@r0
   0D1B 12 17 81           2613 	lcall	__gptrput
                    0830   2614 	C$dynamixel.c$303$1$1 ==.
                           2615 ;	apps/dynamixel_test/dynamixel.c:303: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) ((length + 1) * number + 4);
   0D1E 78 00              2616 	mov	r0,#_dynamixel_txpacket
   0D20 E2                 2617 	movx	a,@r0
   0D21 24 03              2618 	add	a,#0x03
   0D23 FD                 2619 	mov	r5,a
   0D24 08                 2620 	inc	r0
   0D25 E2                 2621 	movx	a,@r0
   0D26 34 00              2622 	addc	a,#0x00
   0D28 FE                 2623 	mov	r6,a
   0D29 08                 2624 	inc	r0
   0D2A E2                 2625 	movx	a,@r0
   0D2B FF                 2626 	mov	r7,a
   0D2C 78 2E              2627 	mov	r0,#_dynamixel_syncwrite_PARM_2
   0D2E E2                 2628 	movx	a,@r0
   0D2F 24 01              2629 	add	a,#0x01
   0D31 FC                 2630 	mov	r4,a
   0D32 78 2F              2631 	mov	r0,#_dynamixel_syncwrite_PARM_3
   0D34 8C F0              2632 	mov	b,r4
   0D36 E2                 2633 	movx	a,@r0
   0D37 A4                 2634 	mul	ab
   0D38 24 04              2635 	add	a,#0x04
   0D3A FC                 2636 	mov	r4,a
   0D3B 8D 82              2637 	mov	dpl,r5
   0D3D 8E 83              2638 	mov	dph,r6
   0D3F 8F F0              2639 	mov	b,r7
   0D41 12 17 81           2640 	lcall	__gptrput
                    0856   2641 	C$dynamixel.c$305$1$1 ==.
                           2642 ;	apps/dynamixel_test/dynamixel.c:305: for(i = 0; i < ((length + 1) * number); i++){
   0D44 78 33              2643 	mov	r0,#_dynamixel_syncwrite_i_1_1
   0D46 E4                 2644 	clr	a
   0D47 F2                 2645 	movx	@r0,a
   0D48                    2646 00101$:
   0D48 78 2E              2647 	mov	r0,#_dynamixel_syncwrite_PARM_2
   0D4A E2                 2648 	movx	a,@r0
   0D4B FD                 2649 	mov	r5,a
   0D4C 7E 00              2650 	mov	r6,#0x00
   0D4E 8D 82              2651 	mov	dpl,r5
   0D50 8E 83              2652 	mov	dph,r6
   0D52 A3                 2653 	inc	dptr
   0D53 78 2F              2654 	mov	r0,#_dynamixel_syncwrite_PARM_3
   0D55 79 99              2655 	mov	r1,#__mulint_PARM_2
   0D57 E2                 2656 	movx	a,@r0
   0D58 F3                 2657 	movx	@r1,a
   0D59 09                 2658 	inc	r1
   0D5A E4                 2659 	clr	a
   0D5B F3                 2660 	movx	@r1,a
   0D5C 12 19 32           2661 	lcall	__mulint
   0D5F AD 82              2662 	mov	r5,dpl
   0D61 AE 83              2663 	mov	r6,dph
   0D63 78 33              2664 	mov	r0,#_dynamixel_syncwrite_i_1_1
   0D65 E2                 2665 	movx	a,@r0
   0D66 FB                 2666 	mov	r3,a
   0D67 7C 00              2667 	mov	r4,#0x00
   0D69 C3                 2668 	clr	c
   0D6A EB                 2669 	mov	a,r3
   0D6B 9D                 2670 	subb	a,r5
   0D6C EC                 2671 	mov	a,r4
   0D6D 64 80              2672 	xrl	a,#0x80
   0D6F 8E F0              2673 	mov	b,r6
   0D71 63 F0 80           2674 	xrl	b,#0x80
   0D74 95 F0              2675 	subb	a,b
   0D76 50 41              2676 	jnc	00104$
                    088A   2677 	C$dynamixel.c$306$2$2 ==.
                           2678 ;	apps/dynamixel_test/dynamixel.c:306: dynamixel_txpacket[DYNAMIXEL_PARAMETER + 2 + i] = (uint8) param[i];
   0D78 74 07              2679 	mov	a,#0x07
   0D7A 2B                 2680 	add	a,r3
   0D7B FB                 2681 	mov	r3,a
   0D7C E4                 2682 	clr	a
   0D7D 3C                 2683 	addc	a,r4
   0D7E FC                 2684 	mov	r4,a
   0D7F 78 00              2685 	mov	r0,#_dynamixel_txpacket
   0D81 E2                 2686 	movx	a,@r0
   0D82 2B                 2687 	add	a,r3
   0D83 FB                 2688 	mov	r3,a
   0D84 08                 2689 	inc	r0
   0D85 E2                 2690 	movx	a,@r0
   0D86 3C                 2691 	addc	a,r4
   0D87 FC                 2692 	mov	r4,a
   0D88 08                 2693 	inc	r0
   0D89 E2                 2694 	movx	a,@r0
   0D8A FE                 2695 	mov	r6,a
   0D8B 78 30              2696 	mov	r0,#_dynamixel_syncwrite_PARM_4
   0D8D 79 33              2697 	mov	r1,#_dynamixel_syncwrite_i_1_1
   0D8F E3                 2698 	movx	a,@r1
   0D90 C5 F0              2699 	xch	a,b
   0D92 E2                 2700 	movx	a,@r0
   0D93 25 F0              2701 	add	a,b
   0D95 FA                 2702 	mov	r2,a
   0D96 08                 2703 	inc	r0
   0D97 E2                 2704 	movx	a,@r0
   0D98 34 00              2705 	addc	a,#0x00
   0D9A FD                 2706 	mov	r5,a
   0D9B 08                 2707 	inc	r0
   0D9C E2                 2708 	movx	a,@r0
   0D9D FF                 2709 	mov	r7,a
   0D9E 8A 82              2710 	mov	dpl,r2
   0DA0 8D 83              2711 	mov	dph,r5
   0DA2 8F F0              2712 	mov	b,r7
   0DA4 12 20 12           2713 	lcall	__gptrget
   0DA7 FA                 2714 	mov	r2,a
   0DA8 8B 82              2715 	mov	dpl,r3
   0DAA 8C 83              2716 	mov	dph,r4
   0DAC 8E F0              2717 	mov	b,r6
   0DAE 12 17 81           2718 	lcall	__gptrput
                    08C3   2719 	C$dynamixel.c$305$1$1 ==.
                           2720 ;	apps/dynamixel_test/dynamixel.c:305: for(i = 0; i < ((length + 1) * number); i++){
   0DB1 78 33              2721 	mov	r0,#_dynamixel_syncwrite_i_1_1
   0DB3 E2                 2722 	movx	a,@r0
   0DB4 24 01              2723 	add	a,#0x01
   0DB6 F2                 2724 	movx	@r0,a
   0DB7 80 8F              2725 	sjmp	00101$
   0DB9                    2726 00104$:
                    08CB   2727 	C$dynamixel.c$308$1$1 ==.
                           2728 ;	apps/dynamixel_test/dynamixel.c:308: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0DB9 78 03              2729 	mov	r0,#_dynamixel_rxpacket
   0DBB 79 13              2730 	mov	r1,#_dynamixel_txrx_PARM_2
   0DBD E2                 2731 	movx	a,@r0
   0DBE F3                 2732 	movx	@r1,a
   0DBF 08                 2733 	inc	r0
   0DC0 E2                 2734 	movx	a,@r0
   0DC1 09                 2735 	inc	r1
   0DC2 F3                 2736 	movx	@r1,a
   0DC3 08                 2737 	inc	r0
   0DC4 E2                 2738 	movx	a,@r0
   0DC5 09                 2739 	inc	r1
   0DC6 F3                 2740 	movx	@r1,a
   0DC7 78 00              2741 	mov	r0,#_dynamixel_txpacket
   0DC9 E2                 2742 	movx	a,@r0
   0DCA F5 82              2743 	mov	dpl,a
   0DCC 08                 2744 	inc	r0
   0DCD E2                 2745 	movx	a,@r0
   0DCE F5 83              2746 	mov	dph,a
   0DD0 08                 2747 	inc	r0
   0DD1 E2                 2748 	movx	a,@r0
   0DD2 F5 F0              2749 	mov	b,a
   0DD4 12 06 BE           2750 	lcall	_dynamixel_txrx
                    08E9   2751 	C$dynamixel.c$309$1$1 ==.
                    08E9   2752 	XG$dynamixel_syncwrite$0$0 ==.
   0DD7 22                 2753 	ret
                           2754 ;------------------------------------------------------------
                           2755 ;Allocation info for local variables in function 'dynamixel_reset'
                           2756 ;------------------------------------------------------------
                    08EA   2757 	G$dynamixel_reset$0$0 ==.
                    08EA   2758 	C$dynamixel.c$311$1$1 ==.
                           2759 ;	apps/dynamixel_test/dynamixel.c:311: uint8 dynamixel_reset(uint8 id)
                           2760 ;	-----------------------------------------
                           2761 ;	 function dynamixel_reset
                           2762 ;	-----------------------------------------
   0DD8                    2763 _dynamixel_reset:
   0DD8 AF 82              2764 	mov	r7,dpl
                    08EC   2765 	C$dynamixel.c$313$1$1 ==.
                           2766 ;	apps/dynamixel_test/dynamixel.c:313: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0DDA 78 00              2767 	mov	r0,#_dynamixel_txpacket
   0DDC E2                 2768 	movx	a,@r0
   0DDD 24 02              2769 	add	a,#0x02
   0DDF FC                 2770 	mov	r4,a
   0DE0 08                 2771 	inc	r0
   0DE1 E2                 2772 	movx	a,@r0
   0DE2 34 00              2773 	addc	a,#0x00
   0DE4 FD                 2774 	mov	r5,a
   0DE5 08                 2775 	inc	r0
   0DE6 E2                 2776 	movx	a,@r0
   0DE7 FE                 2777 	mov	r6,a
   0DE8 8C 82              2778 	mov	dpl,r4
   0DEA 8D 83              2779 	mov	dph,r5
   0DEC 8E F0              2780 	mov	b,r6
   0DEE EF                 2781 	mov	a,r7
   0DEF 12 17 81           2782 	lcall	__gptrput
                    0904   2783 	C$dynamixel.c$314$1$1 ==.
                           2784 ;	apps/dynamixel_test/dynamixel.c:314: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 2;
   0DF2 78 00              2785 	mov	r0,#_dynamixel_txpacket
   0DF4 E2                 2786 	movx	a,@r0
   0DF5 24 03              2787 	add	a,#0x03
   0DF7 FD                 2788 	mov	r5,a
   0DF8 08                 2789 	inc	r0
   0DF9 E2                 2790 	movx	a,@r0
   0DFA 34 00              2791 	addc	a,#0x00
   0DFC FE                 2792 	mov	r6,a
   0DFD 08                 2793 	inc	r0
   0DFE E2                 2794 	movx	a,@r0
   0DFF FF                 2795 	mov	r7,a
   0E00 8D 82              2796 	mov	dpl,r5
   0E02 8E 83              2797 	mov	dph,r6
   0E04 8F F0              2798 	mov	b,r7
   0E06 74 02              2799 	mov	a,#0x02
   0E08 12 17 81           2800 	lcall	__gptrput
                    091D   2801 	C$dynamixel.c$315$1$1 ==.
                           2802 ;	apps/dynamixel_test/dynamixel.c:315: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_RESET;
   0E0B 78 00              2803 	mov	r0,#_dynamixel_txpacket
   0E0D E2                 2804 	movx	a,@r0
   0E0E 24 04              2805 	add	a,#0x04
   0E10 FD                 2806 	mov	r5,a
   0E11 08                 2807 	inc	r0
   0E12 E2                 2808 	movx	a,@r0
   0E13 34 00              2809 	addc	a,#0x00
   0E15 FE                 2810 	mov	r6,a
   0E16 08                 2811 	inc	r0
   0E17 E2                 2812 	movx	a,@r0
   0E18 FF                 2813 	mov	r7,a
   0E19 8D 82              2814 	mov	dpl,r5
   0E1B 8E 83              2815 	mov	dph,r6
   0E1D 8F F0              2816 	mov	b,r7
   0E1F 74 06              2817 	mov	a,#0x06
   0E21 12 17 81           2818 	lcall	__gptrput
                    0936   2819 	C$dynamixel.c$317$1$1 ==.
                           2820 ;	apps/dynamixel_test/dynamixel.c:317: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0E24 78 03              2821 	mov	r0,#_dynamixel_rxpacket
   0E26 79 13              2822 	mov	r1,#_dynamixel_txrx_PARM_2
   0E28 E2                 2823 	movx	a,@r0
   0E29 F3                 2824 	movx	@r1,a
   0E2A 08                 2825 	inc	r0
   0E2B E2                 2826 	movx	a,@r0
   0E2C 09                 2827 	inc	r1
   0E2D F3                 2828 	movx	@r1,a
   0E2E 08                 2829 	inc	r0
   0E2F E2                 2830 	movx	a,@r0
   0E30 09                 2831 	inc	r1
   0E31 F3                 2832 	movx	@r1,a
   0E32 78 00              2833 	mov	r0,#_dynamixel_txpacket
   0E34 E2                 2834 	movx	a,@r0
   0E35 F5 82              2835 	mov	dpl,a
   0E37 08                 2836 	inc	r0
   0E38 E2                 2837 	movx	a,@r0
   0E39 F5 83              2838 	mov	dph,a
   0E3B 08                 2839 	inc	r0
   0E3C E2                 2840 	movx	a,@r0
   0E3D F5 F0              2841 	mov	b,a
   0E3F 12 06 BE           2842 	lcall	_dynamixel_txrx
                    0954   2843 	C$dynamixel.c$318$1$1 ==.
                    0954   2844 	XG$dynamixel_reset$0$0 ==.
   0E42 22                 2845 	ret
                           2846 ;------------------------------------------------------------
                           2847 ;Allocation info for local variables in function 'dynamixel_makeword'
                           2848 ;------------------------------------------------------------
                    0955   2849 	G$dynamixel_makeword$0$0 ==.
                    0955   2850 	C$dynamixel.c$320$1$1 ==.
                           2851 ;	apps/dynamixel_test/dynamixel.c:320: uint16 dynamixel_makeword(uint8 lowbyte, uint8 highbyte)
                           2852 ;	-----------------------------------------
                           2853 ;	 function dynamixel_makeword
                           2854 ;	-----------------------------------------
   0E43                    2855 _dynamixel_makeword:
   0E43 AF 82              2856 	mov	r7,dpl
                    0957   2857 	C$dynamixel.c$322$1$1 ==.
                           2858 ;	apps/dynamixel_test/dynamixel.c:322: return ((highbyte << 8) + lowbyte);
   0E45 78 34              2859 	mov	r0,#_dynamixel_makeword_PARM_2
   0E47 E2                 2860 	movx	a,@r0
   0E48 FE                 2861 	mov	r6,a
   0E49 E4                 2862 	clr	a
   0E4A FD                 2863 	mov	r5,a
   0E4B FC                 2864 	mov	r4,a
   0E4C EF                 2865 	mov	a,r7
   0E4D 2D                 2866 	add	a,r5
   0E4E FD                 2867 	mov	r5,a
   0E4F EC                 2868 	mov	a,r4
   0E50 3E                 2869 	addc	a,r6
                    0963   2870 	C$dynamixel.c$323$1$1 ==.
                    0963   2871 	XG$dynamixel_makeword$0$0 ==.
   0E51 8D 82              2872 	mov	dpl,r5
   0E53 F5 83              2873 	mov	dph,a
   0E55 22                 2874 	ret
                           2875 ;------------------------------------------------------------
                           2876 ;Allocation info for local variables in function 'dynamixel_getlowbyte'
                           2877 ;------------------------------------------------------------
                    0968   2878 	G$dynamixel_getlowbyte$0$0 ==.
                    0968   2879 	C$dynamixel.c$325$1$1 ==.
                           2880 ;	apps/dynamixel_test/dynamixel.c:325: uint8 dynamixel_getlowbyte(uint16 word)
                           2881 ;	-----------------------------------------
                           2882 ;	 function dynamixel_getlowbyte
                           2883 ;	-----------------------------------------
   0E56                    2884 _dynamixel_getlowbyte:
                    0968   2885 	C$dynamixel.c$327$1$1 ==.
                           2886 ;	apps/dynamixel_test/dynamixel.c:327: return (word & 0xff);
                    0968   2887 	C$dynamixel.c$328$1$1 ==.
                    0968   2888 	XG$dynamixel_getlowbyte$0$0 ==.
   0E56 22                 2889 	ret
                           2890 ;------------------------------------------------------------
                           2891 ;Allocation info for local variables in function 'dynamixel_gethighbyte'
                           2892 ;------------------------------------------------------------
                    0969   2893 	G$dynamixel_gethighbyte$0$0 ==.
                    0969   2894 	C$dynamixel.c$330$1$1 ==.
                           2895 ;	apps/dynamixel_test/dynamixel.c:330: uint8 dynamixel_gethighbyte(uint16 word)
                           2896 ;	-----------------------------------------
                           2897 ;	 function dynamixel_gethighbyte
                           2898 ;	-----------------------------------------
   0E57                    2899 _dynamixel_gethighbyte:
   0E57 AF 83              2900 	mov	r7,dph
                    096B   2901 	C$dynamixel.c$332$1$1 ==.
                           2902 ;	apps/dynamixel_test/dynamixel.c:332: return ((word & 0xff00) >> 8);
   0E59 8F 82              2903 	mov	dpl,r7
                    096D   2904 	C$dynamixel.c$333$1$1 ==.
                    096D   2905 	XG$dynamixel_gethighbyte$0$0 ==.
   0E5B 22                 2906 	ret
                           2907 	.area CSEG    (CODE)
                           2908 	.area CONST   (CODE)
                           2909 	.area XINIT   (CODE)
                           2910 	.area CABS    (ABS,CODE)
