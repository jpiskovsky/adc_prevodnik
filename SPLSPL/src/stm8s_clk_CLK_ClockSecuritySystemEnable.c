/**
  ******************************************************************************
  * @file    stm8s_clk.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the CLK peripheral.
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
#include "stm8s_clk.h"



/**
  * @brief  Enables the Clock Security System.
  * @par Full description:
  * once CSS is enabled it cannot be disabled until the next reset.
  * @param  None
  * @retval None
  */
void CLK_ClockSecuritySystemEnable(void)
{
  /* Set CSSEN bit */
  CLK->CSSR |= CLK_CSSR_CSSEN;
}