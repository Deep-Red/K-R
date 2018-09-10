   1              		.file	"hello.c"
   2              		.intel_syntax noprefix
   3              	# GNU C11 (Debian 6.3.0-18+deb9u1) version 6.3.0 20170516 (x86_64-linux-gnu)
   4              	#	compiled by GNU C version 6.3.0 20170516, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.
   5              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   6              	# options passed:  -imultiarch x86_64-linux-gnu hello.c -masm=intel
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
  40 0000 68656C6C 		.string	"hello, "
  40      6F2C2000 
  41              	.LC1:
  42 0008 776F726C 		.string	"world"
  42      6400
  43              		.text
  44              		.globl	main
  46              	main:
  47              	.LFB0:
  48              		.file 1 "hello.c"
   1:hello.c       **** #include <stdio.h>
   2:hello.c       **** 
   3:hello.c       **** main()
   4:hello.c       **** {
  49              		.loc 1 4 0
  50              		.cfi_startproc
  51 0000 55       		push	rbp	#
  52              		.cfi_def_cfa_offset 16
  53              		.cfi_offset 6, -16
  54 0001 4889E5   		mov	rbp, rsp	#,
  55              		.cfi_def_cfa_register 6
   5:hello.c       ****   printf("hello, ");
  56              		.loc 1 5 0
  57 0004 488D3D00 		lea	rdi, .LC0[rip]	#,
  57      000000
  58 000b B8000000 		mov	eax, 0	#,
  58      00
  59 0010 E8000000 		call	printf@PLT	#
  59      00
   6:hello.c       ****   printf("world");
  60              		.loc 1 6 0
  61 0015 488D3D00 		lea	rdi, .LC1[rip]	#,
  61      000000
  62 001c B8000000 		mov	eax, 0	#,
  62      00
  63 0021 E8000000 		call	printf@PLT	#
  63      00
   7:hello.c       ****   printf("\n");
  64              		.loc 1 7 0
  65 0026 BF0A0000 		mov	edi, 10	#,
  65      00
  66 002b E8000000 		call	putchar@PLT	#
  66      00
  67 0030 B8000000 		mov	eax, 0	# _5,
  67      00
   8:hello.c       **** }
  68              		.loc 1 8 0
  69 0035 5D       		pop	rbp	#
  70              		.cfi_def_cfa 7, 8
  71 0036 C3       		ret
  72              		.cfi_endproc
  73              	.LFE0:
  75              	.Letext0:
  76              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
  77              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
  78              		.file 4 "/usr/include/libio.h"
  79              		.file 5 "/usr/include/stdio.h"
  80              		.file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
