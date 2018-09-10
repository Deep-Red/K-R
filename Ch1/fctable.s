   1              		.file	"fctable.c"
   2              		.intel_syntax noprefix
   3              	# GNU C11 (Debian 6.3.0-18+deb9u1) version 6.3.0 20170516 (x86_64-linux-gnu)
   4              	#	compiled by GNU C version 6.3.0 20170516, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.
   5              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   6              	# options passed:  -imultiarch x86_64-linux-gnu fctable.c -masm=intel
   7              	# -mtune=generic -march=x86-64 -g -fverbose-asm
   8              	# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
   9              	# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
  10              	# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
  11              	# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
  12              	# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
  13              	# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
  14              	# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
  15              	# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
  16              	# -finline-atomics -fira-hoist-pressure -fira-share-save-slots
  17              	# -fira-share-spill-slots -fivopts -fkeep-static-consts
  18              	# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
  19              	# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
  20              	# -freg-struct-return -fsched-critical-path-heuristic
  21              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  22              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  23              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
  24              	# -fsemantic-interposition -fshow-column -fsigned-zeros
  25              	# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
  26              	# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
  27              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  28              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  29              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  30              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  31              	# -malign-stringops -mavx256-split-unaligned-load
  32              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  33              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  34              	# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper
  35              	
  36              		.text
  37              	.Ltext0:
  38              		.section	.rodata
  39              	.LC0:
  40 0000 20C2B046 		.string	" \302\260F     \302\260C"
  40      20202020 
  40      20C2B043 
  40      00
  41              	.LC3:
  42 000d 25332E30 		.string	"%3.0f %6.1f\n"
  42      66202536 
  42      2E31660A 
  42      00
  43              		.text
  44              		.globl	main
  46              	main:
  47              	.LFB0:
  48              		.file 1 "fctable.c"
   1:fctable.c     **** #include <stdio.h>
   2:fctable.c     **** 
   3:fctable.c     **** /* print Fahrenheit-Celsious table for fahr = 0, 20, ..., 300; floating-point version */
   4:fctable.c     **** main()
   5:fctable.c     **** {
  49              		.loc 1 5 0
  50              		.cfi_startproc
  51 0000 55       		push	rbp	#
  52              		.cfi_def_cfa_offset 16
  53              		.cfi_offset 6, -16
  54 0001 4889E5   		mov	rbp, rsp	#,
  55              		.cfi_def_cfa_register 6
  56 0004 4883EC20 		sub	rsp, 32	#,
   6:fctable.c     ****   float fahr, celsius;
   7:fctable.c     ****   int lower, upper, step;
   8:fctable.c     **** 
   9:fctable.c     ****   lower = 0; /* lower limit of temperature table */
  57              		.loc 1 9 0
  58 0008 C745F800 		mov	DWORD PTR -8[rbp], 0	# lower,
  58      000000
  10:fctable.c     ****   upper = 300; /* upper limit */
  59              		.loc 1 10 0
  60 000f C745F42C 		mov	DWORD PTR -12[rbp], 300	# upper,
  60      010000
  11:fctable.c     ****   step = 20; /* step size */
  61              		.loc 1 11 0
  62 0016 C745F014 		mov	DWORD PTR -16[rbp], 20	# step,
  62      000000
  12:fctable.c     **** 
  13:fctable.c     ****   fahr = lower;
  63              		.loc 1 13 0
  64 001d 660FEFC0 		pxor	xmm0, xmm0	# tmp96
  65 0021 F30F2A45 		cvtsi2ss	xmm0, DWORD PTR -8[rbp]	# tmp96, lower
  65      F8
  66 0026 F30F1145 		movss	DWORD PTR -4[rbp], xmm0	# fahr, tmp96
  66      FC
  14:fctable.c     **** 
  15:fctable.c     ****   printf(" °F     °C\n");
  67              		.loc 1 15 0
  68 002b 488D3D00 		lea	rdi, .LC0[rip]	#,
  68      000000
  69 0032 E8000000 		call	puts@PLT	#
  69      00
  16:fctable.c     ****   while (fahr <= upper) {
  70              		.loc 1 16 0
  71 0037 EB58     		jmp	.L2	#
  72              	.L3:
  17:fctable.c     ****     celsius = (5.0/9.0) * (fahr-32.0);
  73              		.loc 1 17 0
  74 0039 F30F5A45 		cvtss2sd	xmm0, DWORD PTR -4[rbp]	# _10, fahr
  74      FC
  75 003e F20F100D 		movsd	xmm1, QWORD PTR .LC1[rip]	# tmp97,
  75      00000000 
  76 0046 F20F5CC1 		subsd	xmm0, xmm1	# _11, tmp97
  77 004a F20F100D 		movsd	xmm1, QWORD PTR .LC2[rip]	# tmp98,
  77      00000000 
  78 0052 F20F59C1 		mulsd	xmm0, xmm1	# _12, tmp98
  79 0056 F20F5AD0 		cvtsd2ss	xmm2, xmm0	# tmp102, _12
  80 005a F30F1155 		movss	DWORD PTR -20[rbp], xmm2	# celsius, tmp102
  80      EC
  18:fctable.c     ****     printf("%3.0f %6.1f\n", fahr, celsius);
  81              		.loc 1 18 0
  82 005f F30F5A4D 		cvtss2sd	xmm1, DWORD PTR -20[rbp]	# _14, celsius
  82      EC
  83 0064 F30F5A45 		cvtss2sd	xmm0, DWORD PTR -4[rbp]	# _15, fahr
  83      FC
  84 0069 488D3D00 		lea	rdi, .LC3[rip]	#,
  84      000000
  85 0070 B8020000 		mov	eax, 2	#,
  85      00
  86 0075 E8000000 		call	printf@PLT	#
  86      00
  19:fctable.c     ****     fahr = fahr + step;
  87              		.loc 1 19 0
  88 007a 660FEFC0 		pxor	xmm0, xmm0	# _17
  89 007e F30F2A45 		cvtsi2ss	xmm0, DWORD PTR -16[rbp]	# _17, step
  89      F0
  90 0083 F30F104D 		movss	xmm1, DWORD PTR -4[rbp]	# tmp100, fahr
  90      FC
  91 0088 F30F58C1 		addss	xmm0, xmm1	# tmp99, tmp100
  92 008c F30F1145 		movss	DWORD PTR -4[rbp], xmm0	# fahr, tmp99
  92      FC
  93              	.L2:
  16:fctable.c     ****     celsius = (5.0/9.0) * (fahr-32.0);
  94              		.loc 1 16 0
  95 0091 660FEFC0 		pxor	xmm0, xmm0	# _9
  96 0095 F30F2A45 		cvtsi2ss	xmm0, DWORD PTR -12[rbp]	# _9, upper
  96      F4
  97 009a 0F2E45FC 		ucomiss	xmm0, DWORD PTR -4[rbp]	# _9, fahr
  98 009e 7399     		jnb	.L3	#,
  99 00a0 B8000000 		mov	eax, 0	# _19,
  99      00
  20:fctable.c     ****   }
  21:fctable.c     **** }
 100              		.loc 1 21 0
 101 00a5 C9       		leave
 102              		.cfi_def_cfa 7, 8
 103 00a6 C3       		ret
 104              		.cfi_endproc
 105              	.LFE0:
 107              		.section	.rodata
 108 001a 00000000 		.align 8
 108      0000
 109              	.LC1:
 110 0020 00000000 		.long	0
 111 0024 00004040 		.long	1077936128
 112              		.align 8
 113              	.LC2:
 114 0028 721CC771 		.long	1908874354
 115 002c 1CC7E13F 		.long	1071761180
 116              		.text
 117              	.Letext0:
 118              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
 119              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
 120              		.file 4 "/usr/include/libio.h"
 121              		.file 5 "/usr/include/stdio.h"
 122              		.file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
