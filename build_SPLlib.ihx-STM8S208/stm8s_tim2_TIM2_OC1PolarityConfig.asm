;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (Linux)
;--------------------------------------------------------
	.module stm8s_tim2_TIM2_OC1PolarityConfig
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIM2_OC1PolarityConfig
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
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 39: void TIM2_OC1PolarityConfig(TIM2_OCPolarity_TypeDef TIM2_OCPolarity)
; genLabel
;	-----------------------------------------
;	 function TIM2_OC1PolarityConfig
;	-----------------------------------------
;	Register assignment is optimal.
;	Stack space usage: 1 bytes.
_TIM2_OC1PolarityConfig:
	push	a
; genReceive
	ld	(0x01, sp), a
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 47: TIM2->CCER1 |= (uint8_t)TIM2_CCER1_CC1P;
; genPointerGet
	ld	a, 0x5308
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 45: if (TIM2_OCPolarity != TIM2_OCPOLARITY_HIGH)
; genIfx
	tnz	(0x01, sp)
	jrne	00113$
	jp	00102$
00113$:
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 47: TIM2->CCER1 |= (uint8_t)TIM2_CCER1_CC1P;
; genOr
	or	a, #0x02
; genPointerSet
	ld	0x5308, a
; genGoto
	jp	00104$
; genLabel
00102$:
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 51: TIM2->CCER1 &= (uint8_t)(~TIM2_CCER1_CC1P);
; genAnd
	and	a, #0xfd
; genPointerSet
	ld	0x5308, a
; genLabel
00104$:
;	../SPLSPL/src/stm8s_tim2_TIM2_OC1PolarityConfig.c: 53: }
; genEndFunction
	pop	a
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)
