                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Thu Nov 22 22:47:51 2012
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
                             35 	.globl _dynamixel_writeword
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
   0053                     535 _dynamixel_calculatechecksum_sloc0_1_0:
   0053                     536 	.ds 2
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
                    001A    590 Ldynamixel.dynamixel_writeword$address$1$1==.
   F01A                     591 _dynamixel_writeword_PARM_2:
   F01A                     592 	.ds 1
                    001B    593 Ldynamixel.dynamixel_writeword$value$1$1==.
   F01B                     594 _dynamixel_writeword_PARM_3:
   F01B                     595 	.ds 2
                    001D    596 Ldynamixel.dynamixel_syncwrite$length$1$1==.
   F01D                     597 _dynamixel_syncwrite_PARM_2:
   F01D                     598 	.ds 1
                    001E    599 Ldynamixel.dynamixel_syncwrite$number$1$1==.
   F01E                     600 _dynamixel_syncwrite_PARM_3:
   F01E                     601 	.ds 1
                    001F    602 Ldynamixel.dynamixel_syncwrite$param$1$1==.
   F01F                     603 _dynamixel_syncwrite_PARM_4:
   F01F                     604 	.ds 3
                    0022    605 Ldynamixel.dynamixel_syncwrite$i$1$1==.
   F022                     606 _dynamixel_syncwrite_i_1_1:
   F022                     607 	.ds 1
                    0023    608 Ldynamixel.dynamixel_makeword$highbyte$1$1==.
   F023                     609 _dynamixel_makeword_PARM_2:
   F023                     610 	.ds 1
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
                            804 ;	apps/gait_designer/dynamixel.c:14: volatile uint8 dynamixel_rxindex = 0;
   04E6 78 06               805 	mov	r0,#_dynamixel_rxindex
   04E8 E4                  806 	clr	a
   04E9 F2                  807 	movx	@r0,a
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
                            822 ;	apps/gait_designer/dynamixel.c:30: void dynamixel_init(void)
                            823 ;	-----------------------------------------
                            824 ;	 function dynamixel_init
                            825 ;	-----------------------------------------
   0577                     826 _dynamixel_init:
                    0007    827 	ar7 = 0x07
                    0006    828 	ar6 = 0x06
                    0005    829 	ar5 = 0x05
                    0004    830 	ar4 = 0x04
                    0003    831 	ar3 = 0x03
                    0002    832 	ar2 = 0x02
                    0001    833 	ar1 = 0x01
                    0000    834 	ar0 = 0x00
                    0000    835 	C$dynamixel.c$48$1$1 ==.
                            836 ;	apps/gait_designer/dynamixel.c:48: dynamixel_rxindex = 0;
   0577 78 06               837 	mov	r0,#_dynamixel_rxindex
   0579 E4                  838 	clr	a
   057A F2                  839 	movx	@r0,a
                    0004    840 	C$dynamixel.c$51$1$1 ==.
                            841 ;	apps/gait_designer/dynamixel.c:51: dynamixel_txpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   057B 90 00 80            842 	mov	dptr,#0x0080
   057E 12 2A A1            843 	lcall	_malloc
   0581 AE 82               844 	mov	r6,dpl
   0583 AF 83               845 	mov	r7,dph
   0585 78 00               846 	mov	r0,#_dynamixel_txpacket
   0587 EE                  847 	mov	a,r6
   0588 F2                  848 	movx	@r0,a
   0589 08                  849 	inc	r0
   058A EF                  850 	mov	a,r7
   058B F2                  851 	movx	@r0,a
   058C 08                  852 	inc	r0
   058D E4                  853 	clr	a
   058E F2                  854 	movx	@r0,a
                    0018    855 	C$dynamixel.c$52$1$1 ==.
                            856 ;	apps/gait_designer/dynamixel.c:52: dynamixel_rxpacket = malloc(sizeof(uint8)*DYNAMIXEL_PACKET_SIZE);
   058F 90 00 80            857 	mov	dptr,#0x0080
   0592 12 2A A1            858 	lcall	_malloc
   0595 AE 82               859 	mov	r6,dpl
   0597 AF 83               860 	mov	r7,dph
   0599 78 03               861 	mov	r0,#_dynamixel_rxpacket
   059B EE                  862 	mov	a,r6
   059C F2                  863 	movx	@r0,a
   059D 08                  864 	inc	r0
   059E EF                  865 	mov	a,r7
   059F F2                  866 	movx	@r0,a
   05A0 08                  867 	inc	r0
   05A1 E4                  868 	clr	a
   05A2 F2                  869 	movx	@r0,a
                    002C    870 	C$dynamixel.c$54$1$1 ==.
                    002C    871 	XG$dynamixel_init$0$0 ==.
   05A3 22                  872 	ret
                            873 ;------------------------------------------------------------
                            874 ;Allocation info for local variables in function 'dynamixel_settx'
                            875 ;------------------------------------------------------------
                    002D    876 	G$dynamixel_settx$0$0 ==.
                    002D    877 	C$dynamixel.c$56$1$1 ==.
                            878 ;	apps/gait_designer/dynamixel.c:56: void dynamixel_settx(void)
                            879 ;	-----------------------------------------
                            880 ;	 function dynamixel_settx
                            881 ;	-----------------------------------------
   05A4                     882 _dynamixel_settx:
                    002D    883 	C$dynamixel.c$62$1$1 ==.
                            884 ;	apps/gait_designer/dynamixel.c:62: delayMicroseconds(10);
   05A4 75 82 0A            885 	mov	dpl,#0x0A
   05A7 12 2A 48            886 	lcall	_delayMicroseconds
                    0033    887 	C$dynamixel.c$63$1$1 ==.
                            888 ;	apps/gait_designer/dynamixel.c:63: P1DIR &= ~0x02; //Disable pin P1_1
   05AA AF FE               889 	mov	r7,_P1DIR
   05AC 53 07 FD            890 	anl	ar7,#0xFD
   05AF 8F FE               891 	mov	_P1DIR,r7
                    003A    892 	C$dynamixel.c$64$1$1 ==.
                            893 ;	apps/gait_designer/dynamixel.c:64: P1DIR |= 0x20; //Enable pin P1_5
   05B1 43 FE 20            894 	orl	_P1DIR,#0x20
                    003D    895 	C$dynamixel.c$70$1$1 ==.
                    003D    896 	XG$dynamixel_settx$0$0 ==.
   05B4 22                  897 	ret
                            898 ;------------------------------------------------------------
                            899 ;Allocation info for local variables in function 'dynamixel_setrx'
                            900 ;------------------------------------------------------------
                    003E    901 	G$dynamixel_setrx$0$0 ==.
                    003E    902 	C$dynamixel.c$72$1$1 ==.
                            903 ;	apps/gait_designer/dynamixel.c:72: void dynamixel_setrx(void)
                            904 ;	-----------------------------------------
                            905 ;	 function dynamixel_setrx
                            906 ;	-----------------------------------------
   05B5                     907 _dynamixel_setrx:
                    003E    908 	C$dynamixel.c$80$1$1 ==.
                            909 ;	apps/gait_designer/dynamixel.c:80: delayMicroseconds(10);
   05B5 75 82 0A            910 	mov	dpl,#0x0A
   05B8 12 2A 48            911 	lcall	_delayMicroseconds
                    0044    912 	C$dynamixel.c$90$1$1 ==.
                            913 ;	apps/gait_designer/dynamixel.c:90: P1DIR &= ~0x20; //Disable pin P1_5
   05BB AF FE               914 	mov	r7,_P1DIR
   05BD 53 07 DF            915 	anl	ar7,#0xDF
   05C0 8F FE               916 	mov	_P1DIR,r7
                    004B    917 	C$dynamixel.c$91$1$1 ==.
                            918 ;	apps/gait_designer/dynamixel.c:91: P1DIR |= 0x02; //Enable pin P1_1
   05C2 43 FE 02            919 	orl	_P1DIR,#0x02
                    004E    920 	C$dynamixel.c$99$1$1 ==.
                            921 ;	apps/gait_designer/dynamixel.c:99: dynamixel_rxindex = 0;
   05C5 78 06               922 	mov	r0,#_dynamixel_rxindex
   05C7 E4                  923 	clr	a
   05C8 F2                  924 	movx	@r0,a
                    0052    925 	C$dynamixel.c$100$1$1 ==.
                    0052    926 	XG$dynamixel_setrx$0$0 ==.
   05C9 22                  927 	ret
                            928 ;------------------------------------------------------------
                            929 ;Allocation info for local variables in function 'dynamixel_write'
                            930 ;------------------------------------------------------------
                    0053    931 	G$dynamixel_write$0$0 ==.
                    0053    932 	C$dynamixel.c$102$1$1 ==.
                            933 ;	apps/gait_designer/dynamixel.c:102: void dynamixel_write(uint8 c)
                            934 ;	-----------------------------------------
                            935 ;	 function dynamixel_write
                            936 ;	-----------------------------------------
   05CA                     937 _dynamixel_write:
                    0053    938 	C$dynamixel.c$117$1$1 ==.
                            939 ;	apps/gait_designer/dynamixel.c:117: uart1TxSendByte(c);
   05CA 12 16 36            940 	lcall	_uart1TxSendByte
                    0056    941 	C$dynamixel.c$118$1$1 ==.
                    0056    942 	XG$dynamixel_write$0$0 ==.
   05CD 22                  943 	ret
                            944 ;------------------------------------------------------------
                            945 ;Allocation info for local variables in function 'dynamixel_calculatechecksum'
                            946 ;------------------------------------------------------------
                            947 ;sloc0                     Allocated with name '_dynamixel_calculatechecksum_sloc0_1_0'
                            948 ;------------------------------------------------------------
                    0057    949 	G$dynamixel_calculatechecksum$0$0 ==.
                    0057    950 	C$dynamixel.c$120$1$1 ==.
                            951 ;	apps/gait_designer/dynamixel.c:120: uint8 dynamixel_calculatechecksum(volatile uint8* packet)
                            952 ;	-----------------------------------------
                            953 ;	 function dynamixel_calculatechecksum
                            954 ;	-----------------------------------------
   05CE                     955 _dynamixel_calculatechecksum:
   05CE AF F0               956 	mov	r7,b
   05D0 AE 83               957 	mov	r6,dph
   05D2 E5 82               958 	mov	a,dpl
   05D4 78 07               959 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   05D6 F2                  960 	movx	@r0,a
   05D7 08                  961 	inc	r0
   05D8 EE                  962 	mov	a,r6
   05D9 F2                  963 	movx	@r0,a
   05DA 08                  964 	inc	r0
   05DB EF                  965 	mov	a,r7
   05DC F2                  966 	movx	@r0,a
                    0066    967 	C$dynamixel.c$123$1$1 ==.
                            968 ;	apps/gait_designer/dynamixel.c:123: uint16 checksum = 0;
   05DD 7E 00               969 	mov	r6,#0x00
   05DF 7F 00               970 	mov	r7,#0x00
                    006A    971 	C$dynamixel.c$125$1$1 ==.
                            972 ;	apps/gait_designer/dynamixel.c:125: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   05E1 78 07               973 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   05E3 E2                  974 	movx	a,@r0
   05E4 24 03               975 	add	a,#0x03
   05E6 FB                  976 	mov	r3,a
   05E7 08                  977 	inc	r0
   05E8 E2                  978 	movx	a,@r0
   05E9 34 00               979 	addc	a,#0x00
   05EB FC                  980 	mov	r4,a
   05EC 08                  981 	inc	r0
   05ED E2                  982 	movx	a,@r0
   05EE FD                  983 	mov	r5,a
   05EF 78 0A               984 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   05F1 74 02               985 	mov	a,#0x02
   05F3 F2                  986 	movx	@r0,a
   05F4                     987 00101$:
   05F4 C0 06               988 	push	ar6
   05F6 C0 07               989 	push	ar7
   05F8 8B 82               990 	mov	dpl,r3
   05FA 8C 83               991 	mov	dph,r4
   05FC 8D F0               992 	mov	b,r5
   05FE 12 33 35            993 	lcall	__gptrget
   0601 FF                  994 	mov	r7,a
   0602 7E 00               995 	mov	r6,#0x00
   0604 74 02               996 	mov	a,#0x02
   0606 2F                  997 	add	a,r7
   0607 F5 53               998 	mov	_dynamixel_calculatechecksum_sloc0_1_0,a
   0609 E4                  999 	clr	a
   060A 3E                 1000 	addc	a,r6
   060B F5 54              1001 	mov	(_dynamixel_calculatechecksum_sloc0_1_0 + 1),a
   060D 78 0A              1002 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   060F E2                 1003 	movx	a,@r0
   0610 FA                 1004 	mov	r2,a
   0611 7F 00              1005 	mov	r7,#0x00
   0613 C3                 1006 	clr	c
   0614 E5 53              1007 	mov	a,_dynamixel_calculatechecksum_sloc0_1_0
   0616 9A                 1008 	subb	a,r2
   0617 E5 54              1009 	mov	a,(_dynamixel_calculatechecksum_sloc0_1_0 + 1)
   0619 64 80              1010 	xrl	a,#0x80
   061B 8F F0              1011 	mov	b,r7
   061D 63 F0 80           1012 	xrl	b,#0x80
   0620 95 F0              1013 	subb	a,b
   0622 D0 07              1014 	pop	ar7
   0624 D0 06              1015 	pop	ar6
   0626 40 38              1016 	jc	00104$
                    00B1   1017 	C$dynamixel.c$126$1$1 ==.
                           1018 ;	apps/gait_designer/dynamixel.c:126: checksum += packet[i];
   0628 C0 03              1019 	push	ar3
   062A C0 04              1020 	push	ar4
   062C C0 05              1021 	push	ar5
   062E 78 07              1022 	mov	r0,#_dynamixel_calculatechecksum_packet_1_1
   0630 79 0A              1023 	mov	r1,#_dynamixel_calculatechecksum_i_1_1
   0632 E3                 1024 	movx	a,@r1
   0633 C5 F0              1025 	xch	a,b
   0635 E2                 1026 	movx	a,@r0
   0636 25 F0              1027 	add	a,b
   0638 FA                 1028 	mov	r2,a
   0639 08                 1029 	inc	r0
   063A E2                 1030 	movx	a,@r0
   063B 34 00              1031 	addc	a,#0x00
   063D FC                 1032 	mov	r4,a
   063E 08                 1033 	inc	r0
   063F E2                 1034 	movx	a,@r0
   0640 FD                 1035 	mov	r5,a
   0641 8A 82              1036 	mov	dpl,r2
   0643 8C 83              1037 	mov	dph,r4
   0645 8D F0              1038 	mov	b,r5
   0647 12 33 35           1039 	lcall	__gptrget
   064A FA                 1040 	mov	r2,a
   064B 7D 00              1041 	mov	r5,#0x00
   064D 2E                 1042 	add	a,r6
   064E FE                 1043 	mov	r6,a
   064F ED                 1044 	mov	a,r5
   0650 3F                 1045 	addc	a,r7
   0651 FF                 1046 	mov	r7,a
                    00DB   1047 	C$dynamixel.c$125$1$1 ==.
                           1048 ;	apps/gait_designer/dynamixel.c:125: for(i = DYNAMIXEL_ID; i <= (packet[DYNAMIXEL_LENGTH] + 2); i++)
   0652 78 0A              1049 	mov	r0,#_dynamixel_calculatechecksum_i_1_1
   0654 E2                 1050 	movx	a,@r0
   0655 24 01              1051 	add	a,#0x01
   0657 F2                 1052 	movx	@r0,a
   0658 D0 05              1053 	pop	ar5
   065A D0 04              1054 	pop	ar4
   065C D0 03              1055 	pop	ar3
   065E 80 94              1056 	sjmp	00101$
   0660                    1057 00104$:
                    00E9   1058 	C$dynamixel.c$128$1$1 ==.
                           1059 ;	apps/gait_designer/dynamixel.c:128: return ~(checksum % 256);
   0660 EE                 1060 	mov	a,r6
   0661 F4                 1061 	cpl	a
   0662 F5 82              1062 	mov	dpl,a
                    00ED   1063 	C$dynamixel.c$129$1$1 ==.
                    00ED   1064 	XG$dynamixel_calculatechecksum$0$0 ==.
   0664 22                 1065 	ret
                           1066 ;------------------------------------------------------------
                           1067 ;Allocation info for local variables in function 'dynamixel_writepacket'
                           1068 ;------------------------------------------------------------
                    00EE   1069 	G$dynamixel_writepacket$0$0 ==.
                    00EE   1070 	C$dynamixel.c$131$1$1 ==.
                           1071 ;	apps/gait_designer/dynamixel.c:131: uint8 dynamixel_writepacket(volatile uint8* txpacket, uint8 packetlength)
                           1072 ;	-----------------------------------------
                           1073 ;	 function dynamixel_writepacket
                           1074 ;	-----------------------------------------
   0665                    1075 _dynamixel_writepacket:
   0665 AF F0              1076 	mov	r7,b
   0667 AE 83              1077 	mov	r6,dph
   0669 E5 82              1078 	mov	a,dpl
   066B 78 0C              1079 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   066D F2                 1080 	movx	@r0,a
   066E 08                 1081 	inc	r0
   066F EE                 1082 	mov	a,r6
   0670 F2                 1083 	movx	@r0,a
   0671 08                 1084 	inc	r0
   0672 EF                 1085 	mov	a,r7
   0673 F2                 1086 	movx	@r0,a
                    00FD   1087 	C$dynamixel.c$134$1$1 ==.
                           1088 ;	apps/gait_designer/dynamixel.c:134: for(i = 0; i < packetlength; i++)
   0674 7F 00              1089 	mov	r7,#0x00
   0676                    1090 00101$:
   0676 78 0B              1091 	mov	r0,#_dynamixel_writepacket_PARM_2
   0678 C3                 1092 	clr	c
   0679 E2                 1093 	movx	a,@r0
   067A F5 F0              1094 	mov	b,a
   067C EF                 1095 	mov	a,r7
   067D 95 F0              1096 	subb	a,b
   067F 50 22              1097 	jnc	00104$
                    010A   1098 	C$dynamixel.c$135$1$1 ==.
                           1099 ;	apps/gait_designer/dynamixel.c:135: dynamixel_write(txpacket[i]);
   0681 78 0C              1100 	mov	r0,#_dynamixel_writepacket_txpacket_1_1
   0683 E2                 1101 	movx	a,@r0
   0684 2F                 1102 	add	a,r7
   0685 FC                 1103 	mov	r4,a
   0686 08                 1104 	inc	r0
   0687 E2                 1105 	movx	a,@r0
   0688 34 00              1106 	addc	a,#0x00
   068A FD                 1107 	mov	r5,a
   068B 08                 1108 	inc	r0
   068C E2                 1109 	movx	a,@r0
   068D FE                 1110 	mov	r6,a
   068E 8C 82              1111 	mov	dpl,r4
   0690 8D 83              1112 	mov	dph,r5
   0692 8E F0              1113 	mov	b,r6
   0694 12 33 35           1114 	lcall	__gptrget
   0697 F5 82              1115 	mov	dpl,a
   0699 C0 07              1116 	push	ar7
   069B 12 05 CA           1117 	lcall	_dynamixel_write
   069E D0 07              1118 	pop	ar7
                    0129   1119 	C$dynamixel.c$134$1$1 ==.
                           1120 ;	apps/gait_designer/dynamixel.c:134: for(i = 0; i < packetlength; i++)
   06A0 0F                 1121 	inc	r7
   06A1 80 D3              1122 	sjmp	00101$
   06A3                    1123 00104$:
                    012C   1124 	C$dynamixel.c$137$1$1 ==.
                           1125 ;	apps/gait_designer/dynamixel.c:137: return DYNAMIXEL_SUCCESS;
   06A3 75 82 01           1126 	mov	dpl,#0x01
                    012F   1127 	C$dynamixel.c$138$1$1 ==.
                    012F   1128 	XG$dynamixel_writepacket$0$0 ==.
   06A6 22                 1129 	ret
                           1130 ;------------------------------------------------------------
                           1131 ;Allocation info for local variables in function 'dynamixel_readpacket'
                           1132 ;------------------------------------------------------------
                    0130   1133 	G$dynamixel_readpacket$0$0 ==.
                    0130   1134 	C$dynamixel.c$140$1$1 ==.
                           1135 ;	apps/gait_designer/dynamixel.c:140: uint8 dynamixel_readpacket(volatile uint8* rxpacket, uint8 packetlength)
                           1136 ;	-----------------------------------------
                           1137 ;	 function dynamixel_readpacket
                           1138 ;	-----------------------------------------
   06A7                    1139 _dynamixel_readpacket:
   06A7 AF F0              1140 	mov	r7,b
   06A9 AE 83              1141 	mov	r6,dph
   06AB E5 82              1142 	mov	a,dpl
   06AD 78 10              1143 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   06AF F2                 1144 	movx	@r0,a
   06B0 08                 1145 	inc	r0
   06B1 EE                 1146 	mov	a,r6
   06B2 F2                 1147 	movx	@r0,a
   06B3 08                 1148 	inc	r0
   06B4 EF                 1149 	mov	a,r7
   06B5 F2                 1150 	movx	@r0,a
                    013F   1151 	C$dynamixel.c$144$1$1 ==.
                           1152 ;	apps/gait_designer/dynamixel.c:144: while(dynamixel_rxindex < packetlength) // wait for a full packet?
   06B6 7E 00              1153 	mov	r6,#0x00
   06B8 7F 00              1154 	mov	r7,#0x00
   06BA                    1155 00103$:
   06BA 78 06              1156 	mov	r0,#_dynamixel_rxindex
   06BC 79 0F              1157 	mov	r1,#_dynamixel_readpacket_PARM_2
   06BE C3                 1158 	clr	c
   06BF E3                 1159 	movx	a,@r1
   06C0 F5 F0              1160 	mov	b,a
   06C2 E2                 1161 	movx	a,@r0
   06C3 95 F0              1162 	subb	a,b
   06C5 50 17              1163 	jnc	00105$
                    0150   1164 	C$dynamixel.c$147$2$2 ==.
                           1165 ;	apps/gait_designer/dynamixel.c:147: if(ulcounter++ > 10000)
   06C7 8E 04              1166 	mov	ar4,r6
   06C9 8F 05              1167 	mov	ar5,r7
   06CB 0E                 1168 	inc	r6
   06CC BE 00 01           1169 	cjne	r6,#0x00,00119$
   06CF 0F                 1170 	inc	r7
   06D0                    1171 00119$:
   06D0 C3                 1172 	clr	c
   06D1 74 10              1173 	mov	a,#0x10
   06D3 9C                 1174 	subb	a,r4
   06D4 74 27              1175 	mov	a,#0x27
   06D6 9D                 1176 	subb	a,r5
   06D7 50 E1              1177 	jnc	00103$
                    0162   1178 	C$dynamixel.c$148$2$2 ==.
                           1179 ;	apps/gait_designer/dynamixel.c:148: return DYNAMIXEL_RX_TIMEOUT;
   06D9 75 82 03           1180 	mov	dpl,#0x03
   06DC 80 6E              1181 	sjmp	00111$
   06DE                    1182 00105$:
                    0167   1183 	C$dynamixel.c$153$1$1 ==.
                           1184 ;	apps/gait_designer/dynamixel.c:153: if((rxpacket[0] != 255) || (rxpacket[1] != 255))
   06DE 78 10              1185 	mov	r0,#_dynamixel_readpacket_rxpacket_1_1
   06E0 E2                 1186 	movx	a,@r0
   06E1 FD                 1187 	mov	r5,a
   06E2 08                 1188 	inc	r0
   06E3 E2                 1189 	movx	a,@r0
   06E4 FE                 1190 	mov	r6,a
   06E5 08                 1191 	inc	r0
   06E6 E2                 1192 	movx	a,@r0
   06E7 FF                 1193 	mov	r7,a
   06E8 8D 82              1194 	mov	dpl,r5
   06EA 8E 83              1195 	mov	dph,r6
   06EC 8F F0              1196 	mov	b,r7
   06EE 12 33 35           1197 	lcall	__gptrget
   06F1 FC                 1198 	mov	r4,a
   06F2 BC FF 18           1199 	cjne	r4,#0xFF,00106$
   06F5 74 01              1200 	mov	a,#0x01
   06F7 2D                 1201 	add	a,r5
   06F8 FA                 1202 	mov	r2,a
   06F9 E4                 1203 	clr	a
   06FA 3E                 1204 	addc	a,r6
   06FB FB                 1205 	mov	r3,a
   06FC 8F 04              1206 	mov	ar4,r7
   06FE 8A 82              1207 	mov	dpl,r2
   0700 8B 83              1208 	mov	dph,r3
   0702 8C F0              1209 	mov	b,r4
   0704 12 33 35           1210 	lcall	__gptrget
   0707 FA                 1211 	mov	r2,a
   0708 BA FF 02           1212 	cjne	r2,#0xFF,00123$
   070B 80 05              1213 	sjmp	00107$
   070D                    1214 00123$:
   070D                    1215 00106$:
                    0196   1216 	C$dynamixel.c$154$1$1 ==.
                           1217 ;	apps/gait_designer/dynamixel.c:154: return DYNAMIXEL_RX_CORRUPT;
   070D 75 82 02           1218 	mov	dpl,#0x02
   0710 80 3A              1219 	sjmp	00111$
   0712                    1220 00107$:
                    019B   1221 	C$dynamixel.c$156$1$1 ==.
                           1222 ;	apps/gait_designer/dynamixel.c:156: if(rxpacket[packetlength - 1] != dynamixel_calculatechecksum(rxpacket))
   0712 78 0F              1223 	mov	r0,#_dynamixel_readpacket_PARM_2
   0714 E2                 1224 	movx	a,@r0
   0715 FB                 1225 	mov	r3,a
   0716 7C 00              1226 	mov	r4,#0x00
   0718 1B                 1227 	dec	r3
   0719 BB FF 01           1228 	cjne	r3,#0xFF,00124$
   071C 1C                 1229 	dec	r4
   071D                    1230 00124$:
   071D EB                 1231 	mov	a,r3
   071E 2D                 1232 	add	a,r5
   071F FB                 1233 	mov	r3,a
   0720 EC                 1234 	mov	a,r4
   0721 3E                 1235 	addc	a,r6
   0722 FC                 1236 	mov	r4,a
   0723 8F 02              1237 	mov	ar2,r7
   0725 8B 82              1238 	mov	dpl,r3
   0727 8C 83              1239 	mov	dph,r4
   0729 8A F0              1240 	mov	b,r2
   072B 12 33 35           1241 	lcall	__gptrget
   072E FB                 1242 	mov	r3,a
   072F 8D 82              1243 	mov	dpl,r5
   0731 8E 83              1244 	mov	dph,r6
   0733 8F F0              1245 	mov	b,r7
   0735 C0 03              1246 	push	ar3
   0737 12 05 CE           1247 	lcall	_dynamixel_calculatechecksum
   073A AF 82              1248 	mov	r7,dpl
   073C D0 03              1249 	pop	ar3
   073E EB                 1250 	mov	a,r3
   073F B5 07 02           1251 	cjne	a,ar7,00125$
   0742 80 05              1252 	sjmp	00110$
   0744                    1253 00125$:
                    01CD   1254 	C$dynamixel.c$157$1$1 ==.
                           1255 ;	apps/gait_designer/dynamixel.c:157: return DYNAMIXEL_RX_CORRUPT;
   0744 75 82 02           1256 	mov	dpl,#0x02
   0747 80 03              1257 	sjmp	00111$
   0749                    1258 00110$:
                    01D2   1259 	C$dynamixel.c$159$1$1 ==.
                           1260 ;	apps/gait_designer/dynamixel.c:159: return DYNAMIXEL_SUCCESS;
   0749 75 82 01           1261 	mov	dpl,#0x01
   074C                    1262 00111$:
                    01D5   1263 	C$dynamixel.c$160$1$1 ==.
                    01D5   1264 	XG$dynamixel_readpacket$0$0 ==.
   074C 22                 1265 	ret
                           1266 ;------------------------------------------------------------
                           1267 ;Allocation info for local variables in function 'dynamixel_txrx'
                           1268 ;------------------------------------------------------------
                           1269 ;sloc0                     Allocated with name '_dynamixel_txrx_sloc0_1_0'
                           1270 ;------------------------------------------------------------
                    01D6   1271 	G$dynamixel_txrx$0$0 ==.
                    01D6   1272 	C$dynamixel.c$162$1$1 ==.
                           1273 ;	apps/gait_designer/dynamixel.c:162: uint8 dynamixel_txrx(volatile uint8* txpacket, volatile uint8* rxpacket)
                           1274 ;	-----------------------------------------
                           1275 ;	 function dynamixel_txrx
                           1276 ;	-----------------------------------------
   074D                    1277 _dynamixel_txrx:
   074D AF F0              1278 	mov	r7,b
   074F AE 83              1279 	mov	r6,dph
   0751 E5 82              1280 	mov	a,dpl
   0753 78 16              1281 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   0755 F2                 1282 	movx	@r0,a
   0756 08                 1283 	inc	r0
   0757 EE                 1284 	mov	a,r6
   0758 F2                 1285 	movx	@r0,a
   0759 08                 1286 	inc	r0
   075A EF                 1287 	mov	a,r7
   075B F2                 1288 	movx	@r0,a
                    01E5   1289 	C$dynamixel.c$175$1$1 ==.
                           1290 ;	apps/gait_designer/dynamixel.c:175: uint8 txlength = dynamixel_txpacket[DYNAMIXEL_LENGTH] + 4; // 0xff,0xff, ID, packet, checksum ?
   075C 78 00              1291 	mov	r0,#_dynamixel_txpacket
   075E E2                 1292 	movx	a,@r0
   075F 24 03              1293 	add	a,#0x03
   0761 FD                 1294 	mov	r5,a
   0762 08                 1295 	inc	r0
   0763 E2                 1296 	movx	a,@r0
   0764 34 00              1297 	addc	a,#0x00
   0766 FE                 1298 	mov	r6,a
   0767 08                 1299 	inc	r0
   0768 E2                 1300 	movx	a,@r0
   0769 FF                 1301 	mov	r7,a
   076A 8D 82              1302 	mov	dpl,r5
   076C 8E 83              1303 	mov	dph,r6
   076E 8F F0              1304 	mov	b,r7
   0770 12 33 35           1305 	lcall	__gptrget
   0773 FD                 1306 	mov	r5,a
   0774 78 19              1307 	mov	r0,#_dynamixel_txrx_txlength_1_1
   0776 74 04              1308 	mov	a,#0x04
   0778 2D                 1309 	add	a,r5
   0779 F2                 1310 	movx	@r0,a
                    0203   1311 	C$dynamixel.c$177$1$1 ==.
                           1312 ;	apps/gait_designer/dynamixel.c:177: txpacket[0] = (uint8) 0xff;
   077A 78 16              1313 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   077C E2                 1314 	movx	a,@r0
   077D FC                 1315 	mov	r4,a
   077E 08                 1316 	inc	r0
   077F E2                 1317 	movx	a,@r0
   0780 FE                 1318 	mov	r6,a
   0781 08                 1319 	inc	r0
   0782 E2                 1320 	movx	a,@r0
   0783 FF                 1321 	mov	r7,a
   0784 8C 82              1322 	mov	dpl,r4
   0786 8E 83              1323 	mov	dph,r6
   0788 8F F0              1324 	mov	b,r7
   078A 74 FF              1325 	mov	a,#0xFF
   078C 12 29 45           1326 	lcall	__gptrput
                    0218   1327 	C$dynamixel.c$178$1$1 ==.
                           1328 ;	apps/gait_designer/dynamixel.c:178: txpacket[1] = (uint8) 0xff;
   078F 74 01              1329 	mov	a,#0x01
   0791 2C                 1330 	add	a,r4
   0792 FA                 1331 	mov	r2,a
   0793 E4                 1332 	clr	a
   0794 3E                 1333 	addc	a,r6
   0795 FB                 1334 	mov	r3,a
   0796 8F 05              1335 	mov	ar5,r7
   0798 8A 82              1336 	mov	dpl,r2
   079A 8B 83              1337 	mov	dph,r3
   079C 8D F0              1338 	mov	b,r5
   079E 74 FF              1339 	mov	a,#0xFF
   07A0 12 29 45           1340 	lcall	__gptrput
                    022C   1341 	C$dynamixel.c$179$1$1 ==.
                           1342 ;	apps/gait_designer/dynamixel.c:179: txpacket[txlength - 1] = (uint8) dynamixel_calculatechecksum(txpacket);
   07A3 78 19              1343 	mov	r0,#_dynamixel_txrx_txlength_1_1
   07A5 E2                 1344 	movx	a,@r0
   07A6 FB                 1345 	mov	r3,a
   07A7 7D 00              1346 	mov	r5,#0x00
   07A9 1B                 1347 	dec	r3
   07AA BB FF 01           1348 	cjne	r3,#0xFF,00110$
   07AD 1D                 1349 	dec	r5
   07AE                    1350 00110$:
   07AE EB                 1351 	mov	a,r3
   07AF 2C                 1352 	add	a,r4
   07B0 F5 08              1353 	mov	_dynamixel_txrx_sloc0_1_0,a
   07B2 ED                 1354 	mov	a,r5
   07B3 3E                 1355 	addc	a,r6
   07B4 F5 09              1356 	mov	(_dynamixel_txrx_sloc0_1_0 + 1),a
   07B6 8F 0A              1357 	mov	(_dynamixel_txrx_sloc0_1_0 + 2),r7
   07B8 8C 82              1358 	mov	dpl,r4
   07BA 8E 83              1359 	mov	dph,r6
   07BC 8F F0              1360 	mov	b,r7
   07BE C0 07              1361 	push	ar7
   07C0 C0 06              1362 	push	ar6
   07C2 C0 04              1363 	push	ar4
   07C4 12 05 CE           1364 	lcall	_dynamixel_calculatechecksum
   07C7 AD 82              1365 	mov	r5,dpl
   07C9 85 08 82           1366 	mov	dpl,_dynamixel_txrx_sloc0_1_0
   07CC 85 09 83           1367 	mov	dph,(_dynamixel_txrx_sloc0_1_0 + 1)
   07CF 85 0A F0           1368 	mov	b,(_dynamixel_txrx_sloc0_1_0 + 2)
   07D2 ED                 1369 	mov	a,r5
   07D3 12 29 45           1370 	lcall	__gptrput
                    025F   1371 	C$dynamixel.c$181$1$1 ==.
                           1372 ;	apps/gait_designer/dynamixel.c:181: dynamixel_settx();
   07D6 12 05 A4           1373 	lcall	_dynamixel_settx
                    0262   1374 	C$dynamixel.c$182$1$1 ==.
                           1375 ;	apps/gait_designer/dynamixel.c:182: dynamixel_writepacket(txpacket, txlength);
   07D9 78 19              1376 	mov	r0,#_dynamixel_txrx_txlength_1_1
   07DB 79 0B              1377 	mov	r1,#_dynamixel_writepacket_PARM_2
   07DD E2                 1378 	movx	a,@r0
   07DE F3                 1379 	movx	@r1,a
   07DF 78 16              1380 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   07E1 E2                 1381 	movx	a,@r0
   07E2 F5 82              1382 	mov	dpl,a
   07E4 08                 1383 	inc	r0
   07E5 E2                 1384 	movx	a,@r0
   07E6 F5 83              1385 	mov	dph,a
   07E8 08                 1386 	inc	r0
   07E9 E2                 1387 	movx	a,@r0
   07EA F5 F0              1388 	mov	b,a
   07EC 12 06 65           1389 	lcall	_dynamixel_writepacket
                    0278   1390 	C$dynamixel.c$183$1$1 ==.
                           1391 ;	apps/gait_designer/dynamixel.c:183: dynamixel_setrx();
   07EF 12 05 B5           1392 	lcall	_dynamixel_setrx
   07F2 D0 04              1393 	pop	ar4
   07F4 D0 06              1394 	pop	ar6
   07F6 D0 07              1395 	pop	ar7
                    0281   1396 	C$dynamixel.c$186$1$1 ==.
                           1397 ;	apps/gait_designer/dynamixel.c:186: if(txpacket[DYNAMIXEL_ID] != DYNAMIXEL_BROADCAST_ID)
   07F8 78 16              1398 	mov	r0,#_dynamixel_txrx_txpacket_1_1
   07FA E2                 1399 	movx	a,@r0
   07FB 24 02              1400 	add	a,#0x02
   07FD FA                 1401 	mov	r2,a
   07FE 08                 1402 	inc	r0
   07FF E2                 1403 	movx	a,@r0
   0800 34 00              1404 	addc	a,#0x00
   0802 FB                 1405 	mov	r3,a
   0803 08                 1406 	inc	r0
   0804 E2                 1407 	movx	a,@r0
   0805 FD                 1408 	mov	r5,a
   0806 8A 82              1409 	mov	dpl,r2
   0808 8B 83              1410 	mov	dph,r3
   080A 8D F0              1411 	mov	b,r5
   080C 12 33 35           1412 	lcall	__gptrget
   080F FA                 1413 	mov	r2,a
   0810 BA FE 02           1414 	cjne	r2,#0xFE,00111$
   0813 80 44              1415 	sjmp	00105$
   0815                    1416 00111$:
                    029E   1417 	C$dynamixel.c$189$2$2 ==.
                           1418 ;	apps/gait_designer/dynamixel.c:189: if(txpacket[DYNAMIXEL_INSTRUCTION] == DYNAMIXEL_READ)
   0815 74 04              1419 	mov	a,#0x04
   0817 2C                 1420 	add	a,r4
   0818 FA                 1421 	mov	r2,a
   0819 E4                 1422 	clr	a
   081A 3E                 1423 	addc	a,r6
   081B FB                 1424 	mov	r3,a
   081C 8F 05              1425 	mov	ar5,r7
   081E 8A 82              1426 	mov	dpl,r2
   0820 8B 83              1427 	mov	dph,r3
   0822 8D F0              1428 	mov	b,r5
   0824 12 33 35           1429 	lcall	__gptrget
   0827 FA                 1430 	mov	r2,a
   0828 BA 02 16           1431 	cjne	r2,#0x02,00102$
                    02B4   1432 	C$dynamixel.c$191$2$2 ==.
                           1433 ;	apps/gait_designer/dynamixel.c:191: rxlength = txpacket[DYNAMIXEL_PARAMETER + 1] + 6;
   082B 74 06              1434 	mov	a,#0x06
   082D 2C                 1435 	add	a,r4
   082E FC                 1436 	mov	r4,a
   082F E4                 1437 	clr	a
   0830 3E                 1438 	addc	a,r6
   0831 FE                 1439 	mov	r6,a
   0832 8C 82              1440 	mov	dpl,r4
   0834 8E 83              1441 	mov	dph,r6
   0836 8F F0              1442 	mov	b,r7
   0838 12 33 35           1443 	lcall	__gptrget
   083B FC                 1444 	mov	r4,a
   083C 24 06              1445 	add	a,#0x06
   083E FF                 1446 	mov	r7,a
   083F 80 02              1447 	sjmp	00103$
   0841                    1448 00102$:
                    02CA   1449 	C$dynamixel.c$193$2$2 ==.
                           1450 ;	apps/gait_designer/dynamixel.c:193: rxlength = 6; // Default answer packet length? for DYNAMIXEL_WRITE?
   0841 7F 06              1451 	mov	r7,#0x06
   0843                    1452 00103$:
                    02CC   1453 	C$dynamixel.c$195$2$2 ==.
                           1454 ;	apps/gait_designer/dynamixel.c:195: return dynamixel_readpacket(rxpacket, rxlength);			
   0843 78 0F              1455 	mov	r0,#_dynamixel_readpacket_PARM_2
   0845 EF                 1456 	mov	a,r7
   0846 F2                 1457 	movx	@r0,a
   0847 78 13              1458 	mov	r0,#_dynamixel_txrx_PARM_2
   0849 E2                 1459 	movx	a,@r0
   084A F5 82              1460 	mov	dpl,a
   084C 08                 1461 	inc	r0
   084D E2                 1462 	movx	a,@r0
   084E F5 83              1463 	mov	dph,a
   0850 08                 1464 	inc	r0
   0851 E2                 1465 	movx	a,@r0
   0852 F5 F0              1466 	mov	b,a
   0854 12 06 A7           1467 	lcall	_dynamixel_readpacket
   0857 80 06              1468 	sjmp	00106$
   0859                    1469 00105$:
                    02E2   1470 	C$dynamixel.c$198$1$1 ==.
                           1471 ;	apps/gait_designer/dynamixel.c:198: dynamixel_settx();
   0859 12 05 A4           1472 	lcall	_dynamixel_settx
                    02E5   1473 	C$dynamixel.c$200$1$1 ==.
                           1474 ;	apps/gait_designer/dynamixel.c:200: return DYNAMIXEL_SUCCESS;
   085C 75 82 01           1475 	mov	dpl,#0x01
   085F                    1476 00106$:
                    02E8   1477 	C$dynamixel.c$201$1$1 ==.
                    02E8   1478 	XG$dynamixel_txrx$0$0 ==.
   085F 22                 1479 	ret
                           1480 ;------------------------------------------------------------
                           1481 ;Allocation info for local variables in function 'dynamixel_writeword'
                           1482 ;------------------------------------------------------------
                    02E9   1483 	G$dynamixel_writeword$0$0 ==.
                    02E9   1484 	C$dynamixel.c$285$1$1 ==.
                           1485 ;	apps/gait_designer/dynamixel.c:285: uint8 dynamixel_writeword(uint8 id, uint8 address, uint16 value)
                           1486 ;	-----------------------------------------
                           1487 ;	 function dynamixel_writeword
                           1488 ;	-----------------------------------------
   0860                    1489 _dynamixel_writeword:
   0860 AF 82              1490 	mov	r7,dpl
                    02EB   1491 	C$dynamixel.c$287$1$1 ==.
                           1492 ;	apps/gait_designer/dynamixel.c:287: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) id;
   0862 78 00              1493 	mov	r0,#_dynamixel_txpacket
   0864 E2                 1494 	movx	a,@r0
   0865 24 02              1495 	add	a,#0x02
   0867 FC                 1496 	mov	r4,a
   0868 08                 1497 	inc	r0
   0869 E2                 1498 	movx	a,@r0
   086A 34 00              1499 	addc	a,#0x00
   086C FD                 1500 	mov	r5,a
   086D 08                 1501 	inc	r0
   086E E2                 1502 	movx	a,@r0
   086F FE                 1503 	mov	r6,a
   0870 8C 82              1504 	mov	dpl,r4
   0872 8D 83              1505 	mov	dph,r5
   0874 8E F0              1506 	mov	b,r6
   0876 EF                 1507 	mov	a,r7
   0877 12 29 45           1508 	lcall	__gptrput
                    0303   1509 	C$dynamixel.c$288$1$1 ==.
                           1510 ;	apps/gait_designer/dynamixel.c:288: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) 5;
   087A 78 00              1511 	mov	r0,#_dynamixel_txpacket
   087C E2                 1512 	movx	a,@r0
   087D 24 03              1513 	add	a,#0x03
   087F FD                 1514 	mov	r5,a
   0880 08                 1515 	inc	r0
   0881 E2                 1516 	movx	a,@r0
   0882 34 00              1517 	addc	a,#0x00
   0884 FE                 1518 	mov	r6,a
   0885 08                 1519 	inc	r0
   0886 E2                 1520 	movx	a,@r0
   0887 FF                 1521 	mov	r7,a
   0888 8D 82              1522 	mov	dpl,r5
   088A 8E 83              1523 	mov	dph,r6
   088C 8F F0              1524 	mov	b,r7
   088E 74 05              1525 	mov	a,#0x05
   0890 12 29 45           1526 	lcall	__gptrput
                    031C   1527 	C$dynamixel.c$289$1$1 ==.
                           1528 ;	apps/gait_designer/dynamixel.c:289: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_WRITE;
   0893 78 00              1529 	mov	r0,#_dynamixel_txpacket
   0895 E2                 1530 	movx	a,@r0
   0896 24 04              1531 	add	a,#0x04
   0898 FD                 1532 	mov	r5,a
   0899 08                 1533 	inc	r0
   089A E2                 1534 	movx	a,@r0
   089B 34 00              1535 	addc	a,#0x00
   089D FE                 1536 	mov	r6,a
   089E 08                 1537 	inc	r0
   089F E2                 1538 	movx	a,@r0
   08A0 FF                 1539 	mov	r7,a
   08A1 8D 82              1540 	mov	dpl,r5
   08A3 8E 83              1541 	mov	dph,r6
   08A5 8F F0              1542 	mov	b,r7
   08A7 74 03              1543 	mov	a,#0x03
   08A9 12 29 45           1544 	lcall	__gptrput
                    0335   1545 	C$dynamixel.c$290$1$1 ==.
                           1546 ;	apps/gait_designer/dynamixel.c:290: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   08AC 78 00              1547 	mov	r0,#_dynamixel_txpacket
   08AE E2                 1548 	movx	a,@r0
   08AF 24 05              1549 	add	a,#0x05
   08B1 FD                 1550 	mov	r5,a
   08B2 08                 1551 	inc	r0
   08B3 E2                 1552 	movx	a,@r0
   08B4 34 00              1553 	addc	a,#0x00
   08B6 FE                 1554 	mov	r6,a
   08B7 08                 1555 	inc	r0
   08B8 E2                 1556 	movx	a,@r0
   08B9 FF                 1557 	mov	r7,a
   08BA 8D 82              1558 	mov	dpl,r5
   08BC 8E 83              1559 	mov	dph,r6
   08BE 8F F0              1560 	mov	b,r7
   08C0 78 1A              1561 	mov	r0,#_dynamixel_writeword_PARM_2
   08C2 E2                 1562 	movx	a,@r0
   08C3 12 29 45           1563 	lcall	__gptrput
                    034F   1564 	C$dynamixel.c$291$1$1 ==.
                           1565 ;	apps/gait_designer/dynamixel.c:291: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) dynamixel_getlowbyte(value);
   08C6 78 00              1566 	mov	r0,#_dynamixel_txpacket
   08C8 E2                 1567 	movx	a,@r0
   08C9 24 06              1568 	add	a,#0x06
   08CB FD                 1569 	mov	r5,a
   08CC 08                 1570 	inc	r0
   08CD E2                 1571 	movx	a,@r0
   08CE 34 00              1572 	addc	a,#0x00
   08D0 FE                 1573 	mov	r6,a
   08D1 08                 1574 	inc	r0
   08D2 E2                 1575 	movx	a,@r0
   08D3 FF                 1576 	mov	r7,a
   08D4 78 1B              1577 	mov	r0,#_dynamixel_writeword_PARM_3
   08D6 E2                 1578 	movx	a,@r0
   08D7 F5 82              1579 	mov	dpl,a
   08D9 08                 1580 	inc	r0
   08DA E2                 1581 	movx	a,@r0
   08DB F5 83              1582 	mov	dph,a
   08DD C0 07              1583 	push	ar7
   08DF C0 06              1584 	push	ar6
   08E1 C0 05              1585 	push	ar5
   08E3 12 0A 7C           1586 	lcall	_dynamixel_getlowbyte
   08E6 AC 82              1587 	mov	r4,dpl
   08E8 D0 05              1588 	pop	ar5
   08EA D0 06              1589 	pop	ar6
   08EC D0 07              1590 	pop	ar7
   08EE 8D 82              1591 	mov	dpl,r5
   08F0 8E 83              1592 	mov	dph,r6
   08F2 8F F0              1593 	mov	b,r7
   08F4 EC                 1594 	mov	a,r4
   08F5 12 29 45           1595 	lcall	__gptrput
                    0381   1596 	C$dynamixel.c$292$1$1 ==.
                           1597 ;	apps/gait_designer/dynamixel.c:292: dynamixel_txpacket[DYNAMIXEL_PARAMETER+2] = (uint8) dynamixel_gethighbyte(value);
   08F8 78 00              1598 	mov	r0,#_dynamixel_txpacket
   08FA E2                 1599 	movx	a,@r0
   08FB 24 07              1600 	add	a,#0x07
   08FD FD                 1601 	mov	r5,a
   08FE 08                 1602 	inc	r0
   08FF E2                 1603 	movx	a,@r0
   0900 34 00              1604 	addc	a,#0x00
   0902 FE                 1605 	mov	r6,a
   0903 08                 1606 	inc	r0
   0904 E2                 1607 	movx	a,@r0
   0905 FF                 1608 	mov	r7,a
   0906 78 1B              1609 	mov	r0,#_dynamixel_writeword_PARM_3
   0908 E2                 1610 	movx	a,@r0
   0909 F5 82              1611 	mov	dpl,a
   090B 08                 1612 	inc	r0
   090C E2                 1613 	movx	a,@r0
   090D F5 83              1614 	mov	dph,a
   090F C0 07              1615 	push	ar7
   0911 C0 06              1616 	push	ar6
   0913 C0 05              1617 	push	ar5
   0915 12 0A 7D           1618 	lcall	_dynamixel_gethighbyte
   0918 AC 82              1619 	mov	r4,dpl
   091A D0 05              1620 	pop	ar5
   091C D0 06              1621 	pop	ar6
   091E D0 07              1622 	pop	ar7
   0920 8D 82              1623 	mov	dpl,r5
   0922 8E 83              1624 	mov	dph,r6
   0924 8F F0              1625 	mov	b,r7
   0926 EC                 1626 	mov	a,r4
   0927 12 29 45           1627 	lcall	__gptrput
                    03B3   1628 	C$dynamixel.c$294$1$1 ==.
                           1629 ;	apps/gait_designer/dynamixel.c:294: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   092A 78 03              1630 	mov	r0,#_dynamixel_rxpacket
   092C 79 13              1631 	mov	r1,#_dynamixel_txrx_PARM_2
   092E E2                 1632 	movx	a,@r0
   092F F3                 1633 	movx	@r1,a
   0930 08                 1634 	inc	r0
   0931 E2                 1635 	movx	a,@r0
   0932 09                 1636 	inc	r1
   0933 F3                 1637 	movx	@r1,a
   0934 08                 1638 	inc	r0
   0935 E2                 1639 	movx	a,@r0
   0936 09                 1640 	inc	r1
   0937 F3                 1641 	movx	@r1,a
   0938 78 00              1642 	mov	r0,#_dynamixel_txpacket
   093A E2                 1643 	movx	a,@r0
   093B F5 82              1644 	mov	dpl,a
   093D 08                 1645 	inc	r0
   093E E2                 1646 	movx	a,@r0
   093F F5 83              1647 	mov	dph,a
   0941 08                 1648 	inc	r0
   0942 E2                 1649 	movx	a,@r0
   0943 F5 F0              1650 	mov	b,a
   0945 12 07 4D           1651 	lcall	_dynamixel_txrx
                    03D1   1652 	C$dynamixel.c$295$1$1 ==.
                    03D1   1653 	XG$dynamixel_writeword$0$0 ==.
   0948 22                 1654 	ret
                           1655 ;------------------------------------------------------------
                           1656 ;Allocation info for local variables in function 'dynamixel_syncwrite'
                           1657 ;------------------------------------------------------------
                    03D2   1658 	G$dynamixel_syncwrite$0$0 ==.
                    03D2   1659 	C$dynamixel.c$297$1$1 ==.
                           1660 ;	apps/gait_designer/dynamixel.c:297: uint8 dynamixel_syncwrite(uint8 address, uint8 length, uint8 number, uint8* param)
                           1661 ;	-----------------------------------------
                           1662 ;	 function dynamixel_syncwrite
                           1663 ;	-----------------------------------------
   0949                    1664 _dynamixel_syncwrite:
   0949 AF 82              1665 	mov	r7,dpl
                    03D4   1666 	C$dynamixel.c$301$1$1 ==.
                           1667 ;	apps/gait_designer/dynamixel.c:301: dynamixel_txpacket[DYNAMIXEL_ID]          = (uint8) DYNAMIXEL_BROADCAST_ID;
   094B 78 00              1668 	mov	r0,#_dynamixel_txpacket
   094D E2                 1669 	movx	a,@r0
   094E 24 02              1670 	add	a,#0x02
   0950 FC                 1671 	mov	r4,a
   0951 08                 1672 	inc	r0
   0952 E2                 1673 	movx	a,@r0
   0953 34 00              1674 	addc	a,#0x00
   0955 FD                 1675 	mov	r5,a
   0956 08                 1676 	inc	r0
   0957 E2                 1677 	movx	a,@r0
   0958 FE                 1678 	mov	r6,a
   0959 8C 82              1679 	mov	dpl,r4
   095B 8D 83              1680 	mov	dph,r5
   095D 8E F0              1681 	mov	b,r6
   095F 74 FE              1682 	mov	a,#0xFE
   0961 12 29 45           1683 	lcall	__gptrput
                    03ED   1684 	C$dynamixel.c$302$1$1 ==.
                           1685 ;	apps/gait_designer/dynamixel.c:302: dynamixel_txpacket[DYNAMIXEL_INSTRUCTION] = (uint8) DYNAMIXEL_SYNC_WRITE;
   0964 78 00              1686 	mov	r0,#_dynamixel_txpacket
   0966 E2                 1687 	movx	a,@r0
   0967 24 04              1688 	add	a,#0x04
   0969 FC                 1689 	mov	r4,a
   096A 08                 1690 	inc	r0
   096B E2                 1691 	movx	a,@r0
   096C 34 00              1692 	addc	a,#0x00
   096E FD                 1693 	mov	r5,a
   096F 08                 1694 	inc	r0
   0970 E2                 1695 	movx	a,@r0
   0971 FE                 1696 	mov	r6,a
   0972 8C 82              1697 	mov	dpl,r4
   0974 8D 83              1698 	mov	dph,r5
   0976 8E F0              1699 	mov	b,r6
   0978 74 83              1700 	mov	a,#0x83
   097A 12 29 45           1701 	lcall	__gptrput
                    0406   1702 	C$dynamixel.c$303$1$1 ==.
                           1703 ;	apps/gait_designer/dynamixel.c:303: dynamixel_txpacket[DYNAMIXEL_PARAMETER]   = (uint8) address;
   097D 78 00              1704 	mov	r0,#_dynamixel_txpacket
   097F E2                 1705 	movx	a,@r0
   0980 24 05              1706 	add	a,#0x05
   0982 FC                 1707 	mov	r4,a
   0983 08                 1708 	inc	r0
   0984 E2                 1709 	movx	a,@r0
   0985 34 00              1710 	addc	a,#0x00
   0987 FD                 1711 	mov	r5,a
   0988 08                 1712 	inc	r0
   0989 E2                 1713 	movx	a,@r0
   098A FE                 1714 	mov	r6,a
   098B 8C 82              1715 	mov	dpl,r4
   098D 8D 83              1716 	mov	dph,r5
   098F 8E F0              1717 	mov	b,r6
   0991 EF                 1718 	mov	a,r7
   0992 12 29 45           1719 	lcall	__gptrput
                    041E   1720 	C$dynamixel.c$304$1$1 ==.
                           1721 ;	apps/gait_designer/dynamixel.c:304: dynamixel_txpacket[DYNAMIXEL_PARAMETER+1] = (uint8) length; // The length of the packet where its value is “Number of parameters (N) +2”
   0995 78 00              1722 	mov	r0,#_dynamixel_txpacket
   0997 E2                 1723 	movx	a,@r0
   0998 24 06              1724 	add	a,#0x06
   099A FD                 1725 	mov	r5,a
   099B 08                 1726 	inc	r0
   099C E2                 1727 	movx	a,@r0
   099D 34 00              1728 	addc	a,#0x00
   099F FE                 1729 	mov	r6,a
   09A0 08                 1730 	inc	r0
   09A1 E2                 1731 	movx	a,@r0
   09A2 FF                 1732 	mov	r7,a
   09A3 8D 82              1733 	mov	dpl,r5
   09A5 8E 83              1734 	mov	dph,r6
   09A7 8F F0              1735 	mov	b,r7
   09A9 78 1D              1736 	mov	r0,#_dynamixel_syncwrite_PARM_2
   09AB E2                 1737 	movx	a,@r0
   09AC 12 29 45           1738 	lcall	__gptrput
                    0438   1739 	C$dynamixel.c$305$1$1 ==.
                           1740 ;	apps/gait_designer/dynamixel.c:305: dynamixel_txpacket[DYNAMIXEL_LENGTH]      = (uint8) ((length + 1) * number + 4);
   09AF 78 00              1741 	mov	r0,#_dynamixel_txpacket
   09B1 E2                 1742 	movx	a,@r0
   09B2 24 03              1743 	add	a,#0x03
   09B4 FD                 1744 	mov	r5,a
   09B5 08                 1745 	inc	r0
   09B6 E2                 1746 	movx	a,@r0
   09B7 34 00              1747 	addc	a,#0x00
   09B9 FE                 1748 	mov	r6,a
   09BA 08                 1749 	inc	r0
   09BB E2                 1750 	movx	a,@r0
   09BC FF                 1751 	mov	r7,a
   09BD 78 1D              1752 	mov	r0,#_dynamixel_syncwrite_PARM_2
   09BF E2                 1753 	movx	a,@r0
   09C0 24 01              1754 	add	a,#0x01
   09C2 FC                 1755 	mov	r4,a
   09C3 78 1E              1756 	mov	r0,#_dynamixel_syncwrite_PARM_3
   09C5 8C F0              1757 	mov	b,r4
   09C7 E2                 1758 	movx	a,@r0
   09C8 A4                 1759 	mul	ab
   09C9 24 04              1760 	add	a,#0x04
   09CB FC                 1761 	mov	r4,a
   09CC 8D 82              1762 	mov	dpl,r5
   09CE 8E 83              1763 	mov	dph,r6
   09D0 8F F0              1764 	mov	b,r7
   09D2 12 29 45           1765 	lcall	__gptrput
                    045E   1766 	C$dynamixel.c$307$1$1 ==.
                           1767 ;	apps/gait_designer/dynamixel.c:307: for(i = 0; i < ((length + 1) * number); i++){
   09D5 78 22              1768 	mov	r0,#_dynamixel_syncwrite_i_1_1
   09D7 E4                 1769 	clr	a
   09D8 F2                 1770 	movx	@r0,a
   09D9                    1771 00101$:
   09D9 78 1D              1772 	mov	r0,#_dynamixel_syncwrite_PARM_2
   09DB E2                 1773 	movx	a,@r0
   09DC FD                 1774 	mov	r5,a
   09DD 7E 00              1775 	mov	r6,#0x00
   09DF 8D 82              1776 	mov	dpl,r5
   09E1 8E 83              1777 	mov	dph,r6
   09E3 A3                 1778 	inc	dptr
   09E4 78 1E              1779 	mov	r0,#_dynamixel_syncwrite_PARM_3
   09E6 79 9F              1780 	mov	r1,#__mulint_PARM_2
   09E8 E2                 1781 	movx	a,@r0
   09E9 F3                 1782 	movx	@r1,a
   09EA 09                 1783 	inc	r1
   09EB E4                 1784 	clr	a
   09EC F3                 1785 	movx	@r1,a
   09ED 12 2B D1           1786 	lcall	__mulint
   09F0 AD 82              1787 	mov	r5,dpl
   09F2 AE 83              1788 	mov	r6,dph
   09F4 78 22              1789 	mov	r0,#_dynamixel_syncwrite_i_1_1
   09F6 E2                 1790 	movx	a,@r0
   09F7 FB                 1791 	mov	r3,a
   09F8 7C 00              1792 	mov	r4,#0x00
   09FA C3                 1793 	clr	c
   09FB EB                 1794 	mov	a,r3
   09FC 9D                 1795 	subb	a,r5
   09FD EC                 1796 	mov	a,r4
   09FE 64 80              1797 	xrl	a,#0x80
   0A00 8E F0              1798 	mov	b,r6
   0A02 63 F0 80           1799 	xrl	b,#0x80
   0A05 95 F0              1800 	subb	a,b
   0A07 50 41              1801 	jnc	00104$
                    0492   1802 	C$dynamixel.c$308$2$2 ==.
                           1803 ;	apps/gait_designer/dynamixel.c:308: dynamixel_txpacket[DYNAMIXEL_PARAMETER + 2 + i] = (uint8) param[i];
   0A09 74 07              1804 	mov	a,#0x07
   0A0B 2B                 1805 	add	a,r3
   0A0C FB                 1806 	mov	r3,a
   0A0D E4                 1807 	clr	a
   0A0E 3C                 1808 	addc	a,r4
   0A0F FC                 1809 	mov	r4,a
   0A10 78 00              1810 	mov	r0,#_dynamixel_txpacket
   0A12 E2                 1811 	movx	a,@r0
   0A13 2B                 1812 	add	a,r3
   0A14 FB                 1813 	mov	r3,a
   0A15 08                 1814 	inc	r0
   0A16 E2                 1815 	movx	a,@r0
   0A17 3C                 1816 	addc	a,r4
   0A18 FC                 1817 	mov	r4,a
   0A19 08                 1818 	inc	r0
   0A1A E2                 1819 	movx	a,@r0
   0A1B FE                 1820 	mov	r6,a
   0A1C 78 1F              1821 	mov	r0,#_dynamixel_syncwrite_PARM_4
   0A1E 79 22              1822 	mov	r1,#_dynamixel_syncwrite_i_1_1
   0A20 E3                 1823 	movx	a,@r1
   0A21 C5 F0              1824 	xch	a,b
   0A23 E2                 1825 	movx	a,@r0
   0A24 25 F0              1826 	add	a,b
   0A26 FA                 1827 	mov	r2,a
   0A27 08                 1828 	inc	r0
   0A28 E2                 1829 	movx	a,@r0
   0A29 34 00              1830 	addc	a,#0x00
   0A2B FD                 1831 	mov	r5,a
   0A2C 08                 1832 	inc	r0
   0A2D E2                 1833 	movx	a,@r0
   0A2E FF                 1834 	mov	r7,a
   0A2F 8A 82              1835 	mov	dpl,r2
   0A31 8D 83              1836 	mov	dph,r5
   0A33 8F F0              1837 	mov	b,r7
   0A35 12 33 35           1838 	lcall	__gptrget
   0A38 FA                 1839 	mov	r2,a
   0A39 8B 82              1840 	mov	dpl,r3
   0A3B 8C 83              1841 	mov	dph,r4
   0A3D 8E F0              1842 	mov	b,r6
   0A3F 12 29 45           1843 	lcall	__gptrput
                    04CB   1844 	C$dynamixel.c$307$1$1 ==.
                           1845 ;	apps/gait_designer/dynamixel.c:307: for(i = 0; i < ((length + 1) * number); i++){
   0A42 78 22              1846 	mov	r0,#_dynamixel_syncwrite_i_1_1
   0A44 E2                 1847 	movx	a,@r0
   0A45 24 01              1848 	add	a,#0x01
   0A47 F2                 1849 	movx	@r0,a
   0A48 80 8F              1850 	sjmp	00101$
   0A4A                    1851 00104$:
                    04D3   1852 	C$dynamixel.c$310$1$1 ==.
                           1853 ;	apps/gait_designer/dynamixel.c:310: return dynamixel_txrx(dynamixel_txpacket, dynamixel_rxpacket);
   0A4A 78 03              1854 	mov	r0,#_dynamixel_rxpacket
   0A4C 79 13              1855 	mov	r1,#_dynamixel_txrx_PARM_2
   0A4E E2                 1856 	movx	a,@r0
   0A4F F3                 1857 	movx	@r1,a
   0A50 08                 1858 	inc	r0
   0A51 E2                 1859 	movx	a,@r0
   0A52 09                 1860 	inc	r1
   0A53 F3                 1861 	movx	@r1,a
   0A54 08                 1862 	inc	r0
   0A55 E2                 1863 	movx	a,@r0
   0A56 09                 1864 	inc	r1
   0A57 F3                 1865 	movx	@r1,a
   0A58 78 00              1866 	mov	r0,#_dynamixel_txpacket
   0A5A E2                 1867 	movx	a,@r0
   0A5B F5 82              1868 	mov	dpl,a
   0A5D 08                 1869 	inc	r0
   0A5E E2                 1870 	movx	a,@r0
   0A5F F5 83              1871 	mov	dph,a
   0A61 08                 1872 	inc	r0
   0A62 E2                 1873 	movx	a,@r0
   0A63 F5 F0              1874 	mov	b,a
   0A65 12 07 4D           1875 	lcall	_dynamixel_txrx
                    04F1   1876 	C$dynamixel.c$311$1$1 ==.
                    04F1   1877 	XG$dynamixel_syncwrite$0$0 ==.
   0A68 22                 1878 	ret
                           1879 ;------------------------------------------------------------
                           1880 ;Allocation info for local variables in function 'dynamixel_makeword'
                           1881 ;------------------------------------------------------------
                    04F2   1882 	G$dynamixel_makeword$0$0 ==.
                    04F2   1883 	C$dynamixel.c$322$1$1 ==.
                           1884 ;	apps/gait_designer/dynamixel.c:322: uint16 dynamixel_makeword(uint8 lowbyte, uint8 highbyte)
                           1885 ;	-----------------------------------------
                           1886 ;	 function dynamixel_makeword
                           1887 ;	-----------------------------------------
   0A69                    1888 _dynamixel_makeword:
   0A69 AF 82              1889 	mov	r7,dpl
                    04F4   1890 	C$dynamixel.c$324$1$1 ==.
                           1891 ;	apps/gait_designer/dynamixel.c:324: return ((highbyte << 8) + lowbyte);
   0A6B 78 23              1892 	mov	r0,#_dynamixel_makeword_PARM_2
   0A6D E2                 1893 	movx	a,@r0
   0A6E FE                 1894 	mov	r6,a
   0A6F E4                 1895 	clr	a
   0A70 FD                 1896 	mov	r5,a
   0A71 FC                 1897 	mov	r4,a
   0A72 EF                 1898 	mov	a,r7
   0A73 2D                 1899 	add	a,r5
   0A74 FD                 1900 	mov	r5,a
   0A75 EC                 1901 	mov	a,r4
   0A76 3E                 1902 	addc	a,r6
                    0500   1903 	C$dynamixel.c$325$1$1 ==.
                    0500   1904 	XG$dynamixel_makeword$0$0 ==.
   0A77 8D 82              1905 	mov	dpl,r5
   0A79 F5 83              1906 	mov	dph,a
   0A7B 22                 1907 	ret
                           1908 ;------------------------------------------------------------
                           1909 ;Allocation info for local variables in function 'dynamixel_getlowbyte'
                           1910 ;------------------------------------------------------------
                    0505   1911 	G$dynamixel_getlowbyte$0$0 ==.
                    0505   1912 	C$dynamixel.c$327$1$1 ==.
                           1913 ;	apps/gait_designer/dynamixel.c:327: uint8 dynamixel_getlowbyte(uint16 word)
                           1914 ;	-----------------------------------------
                           1915 ;	 function dynamixel_getlowbyte
                           1916 ;	-----------------------------------------
   0A7C                    1917 _dynamixel_getlowbyte:
                    0505   1918 	C$dynamixel.c$329$1$1 ==.
                           1919 ;	apps/gait_designer/dynamixel.c:329: return (word & 0xff);
                    0505   1920 	C$dynamixel.c$330$1$1 ==.
                    0505   1921 	XG$dynamixel_getlowbyte$0$0 ==.
   0A7C 22                 1922 	ret
                           1923 ;------------------------------------------------------------
                           1924 ;Allocation info for local variables in function 'dynamixel_gethighbyte'
                           1925 ;------------------------------------------------------------
                    0506   1926 	G$dynamixel_gethighbyte$0$0 ==.
                    0506   1927 	C$dynamixel.c$332$1$1 ==.
                           1928 ;	apps/gait_designer/dynamixel.c:332: uint8 dynamixel_gethighbyte(uint16 word)
                           1929 ;	-----------------------------------------
                           1930 ;	 function dynamixel_gethighbyte
                           1931 ;	-----------------------------------------
   0A7D                    1932 _dynamixel_gethighbyte:
   0A7D AF 83              1933 	mov	r7,dph
                    0508   1934 	C$dynamixel.c$334$1$1 ==.
                           1935 ;	apps/gait_designer/dynamixel.c:334: return ((word & 0xff00) >> 8);
   0A7F 8F 82              1936 	mov	dpl,r7
                    050A   1937 	C$dynamixel.c$335$1$1 ==.
                    050A   1938 	XG$dynamixel_gethighbyte$0$0 ==.
   0A81 22                 1939 	ret
                           1940 	.area CSEG    (CODE)
                           1941 	.area CONST   (CODE)
                           1942 	.area XINIT   (CODE)
                           1943 	.area CABS    (ABS,CODE)
