/**
  ******************************************************************************
  * @file    stm8s_rst.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the RST peripheral.
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
#include "stm8s_rst.h"



/**
  * @brief  Clears the specified RST flag.
  * @param  RST_Flag : specify the reset flag to clear.
  *         This parameter can be a value of @ref RST_Flag_TypeDef.
  * @retval None
  */
void RST_ClearFlag(RST_Flag_TypeDef RST_Flag)
{
  /* Check the parameters */
  assert_param(IS_RST_FLAG_OK(RST_Flag));
  
  RST->SR = (uint8_t)RST_Flag;
}