/**
  ******************************************************************************
  * @file    stm8s_flash.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the FLASH peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
#include "stm8s_flash.h"
#include "stm8s_flash_private.h"



#if defined (_SDCC_BIGMEM_)
/**
  * @brief  Reads any byte from flash memory
  * @note   is required for >64kB memory space and SDCC, which doesn't yet support far pointers
  * @param  Address : address to read
  * @retval value read
  */
uint8_t read_byte_address(uint32_t Address)
{
#if defined (_SDCC_GAS_)
    return(*(PointerAttr uint8_t *) (MemoryAddressCast)Address); 
#else
  /* store address globally for assember */
  asm_addr = Address;

  /* use inline assembler to read from 16b/24b address */
__asm
  ldf	a,[_asm_addr+1].e
  ld	_asm_val,a
__endasm;

  /* return read byte */
  return(asm_val);
#endif
  
}

#endif // _SDCC_BIGMEM_
