;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (Linux)
;--------------------------------------------------------
	.module stm8s_tim3_TIM3_UpdateRequestConfig
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIM3_UpdateRequestConfig
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 39: void TIM3_UpdateRequestConfig(TIM3_UpdateSource_TypeDef TIM3_UpdateSource)
; genLabel
;	-----------------------------------------
;	 function TIM3_UpdateRequestConfig
;	-----------------------------------------
;	Register assignment is optimal.
;	Stack space usage: 1 bytes.
_TIM3_UpdateRequestConfig:
	push	a
; genReceive
	ld	(0x01, sp), a
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 47: TIM3->CR1 |= TIM3_CR1_URS;
; genPointerGet
	ld	a, 0x5320
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 45: if (TIM3_UpdateSource != TIM3_UPDATESOURCE_GLOBAL)
; genIfx
	tnz	(0x01, sp)
	jrne	00113$
	jp	00102$
00113$:
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 47: TIM3->CR1 |= TIM3_CR1_URS;
; genOr
	or	a, #0x04
; genPointerSet
	ld	0x5320, a
; genGoto
	jp	00104$
; genLabel
00102$:
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 51: TIM3->CR1 &= (uint8_t)(~TIM3_CR1_URS);
; genAnd
	and	a, #0xfb
; genPointerSet
	ld	0x5320, a
; genLabel
00104$:
;	../SPLSPL/src/stm8s_tim3_TIM3_UpdateRequestConfig.c: 53: }
; genEndFunction
	pop	a
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)
