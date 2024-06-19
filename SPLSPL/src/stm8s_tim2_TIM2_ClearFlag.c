/**
  ******************************************************************************
  * @file    stm8s_tim2.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the TIM2 peripheral.
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
#include "stm8s_tim2.h"



/**
  * @brief  Clears the TIM2s pending flags.
  * @param   TIM2_FLAG specifies the flag to clear.
  * This parameter can be one of the following values:
  *                       - TIM2_FLAG_UPDATE: TIM2 update Flag
  *                       - TIM2_FLAG_CC1: TIM2 Capture Compare 1 Flag
  *                       - TIM2_FLAG_CC2: TIM2 Capture Compare 2 Flag
  *                       - TIM2_FLAG_CC3: TIM2 Capture Compare 3 Flag
  *                       - TIM2_FLAG_CC1OF: TIM2 Capture Compare 1 over capture Flag
  *                       - TIM2_FLAG_CC2OF: TIM2 Capture Compare 2 over capture Flag
  *                       - TIM2_FLAG_CC3OF: TIM2 Capture Compare 3 over capture Flag
  * @retval None.
  */
void TIM2_ClearFlag(TIM2_FLAG_TypeDef TIM2_FLAG)
{
  /* Check the parameters */
  assert_param(IS_TIM2_CLEAR_FLAG_OK(TIM2_FLAG));
  
  /* Clear the flags (rc_w0) clear this bit by writing 0. Writing 1 has no effect*/
  TIM2->SR1 = (uint8_t)(~((uint8_t)(TIM2_FLAG)));
  TIM2->SR2 = (uint8_t)(~((uint8_t)((uint8_t)TIM2_FLAG >> 8)));
}