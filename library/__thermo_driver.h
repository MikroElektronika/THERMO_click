/*
    __thermo_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __thermo_driver.h
@brief    Thermo Driver
@mainpage Thermo Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   THERMO
@brief      Thermo Click Driver
@{

| Global Library Prefix | **THERMO** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _THERMO_H_
#define _THERMO_H_

/** 
 * @macro T_THERMO_P
 * @brief Driver Abstract type 
 */
#define T_THERMO_P    const uint8_t*

/** @defgroup THERMO_COMPILE Compilation Config */              /** @{ */

   #define   __THERMO_DRV_SPI__                            /**<     @macro __THERMO_DRV_SPI__  @brief SPI driver selector */
//  #define   __THERMO_DRV_I2C__                            /**<     @macro __THERMO_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __THERMO_DRV_UART__                           /**<     @macro __THERMO_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup THERMO_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup THERMO_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup THERMO_INIT Driver Initialization */              /** @{ */

#ifdef   __THERMO_DRV_SPI__
void thermo_spiDriverInit(T_THERMO_P gpioObj, T_THERMO_P spiObj);
#endif
#ifdef   __THERMO_DRV_I2C__
void thermo_i2cDriverInit(T_THERMO_P gpioObj, T_THERMO_P i2cObj, uint8_t slave);
#endif
#ifdef   __THERMO_DRV_UART__
void thermo_uartDriverInit(T_THERMO_P gpioObj, T_THERMO_P uartObj);
#endif


/** @defgroup THERMO_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Read data from sensor function
 *
 * @return
 * 32-bit read sensor data
 *
 * Function read the 32-bit of data from the
 * MAX31855 sensor on Thermo click board.
 */
uint32_t thermo_readData();

/**
 * @brief Get thermocouple temperature function
 *
 * @return
 * float thermocouple temperature in degree Celsius [ ºC ]
 *
 * Function get thermocouple temperature data from MAX31855 sensor on Thermo click board 
 * and convert to float value of thermocouple temperature in degree Celsius [ ºC ].
 */
float thermo_getTemperature();

/**
 * @brief Get reference junction temperature function
 *
 * @return
 * float reference junction temperature in degree Celsius [ ºC ]
 *
 * Function get reference junction temperature data from MAX31855 sensor on Thermo click board
 * and convert to float value of reference junction temperature in degree Celsius [ ºC ].
 */
float thermo_getJunctionTemperature();

/**
 * @brief Check fault states function
 *
 * @return
 * - 0 : OK
 * - 1 : ERROR ( when any of the SCV, SCG, or OC faults are active );
 *
 * Function check fault states of MAX31855 sensor on Thermo click board.
 */
uint8_t thermo_checkFault();

/**
 * @brief Check short-circuited to Vcc function
 *
 * @return
 * - 0 : OK
 * - 1 : ERROR ( when the thermocouple is short-circuited to VCC );
 *
 * Function check fault states of short-circuited to Vcc 
 * of MAX31855 sensor on Thermo click board.
 */
uint8_t thermo_shortCircuitedVcc();

/**
 * @brief Check short-circuited to GND function
 *
 * @return
 * - 0 : OK
 * - 1 : ERROR ( when the thermocouple is short-circuited to GND );
 *
 * Function check fault states of short-circuited to GND
 * of MAX31855 sensor on Thermo click board.
 */
uint8_t thermo_shortCircuitedGND();

/**
 * @brief Check connections fault function
 *
 * @return
 * - 0 : OK
 * - 1 : ERROR (  when the thermocouple is open (no connections) );
 *
 * Function check connections fault
 * of MAX31855 sensor on Thermo click board.
 */
uint8_t thermo_checkConnections();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Thermo_STM.c
    @example Click_Thermo_TIVA.c
    @example Click_Thermo_CEC.c
    @example Click_Thermo_KINETIS.c
    @example Click_Thermo_MSP.c
    @example Click_Thermo_PIC.c
    @example Click_Thermo_PIC32.c
    @example Click_Thermo_DSPIC.c
    @example Click_Thermo_AVR.c
    @example Click_Thermo_FT90x.c
    @example Click_Thermo_STM.mbas
    @example Click_Thermo_TIVA.mbas
    @example Click_Thermo_CEC.mbas
    @example Click_Thermo_KINETIS.mbas
    @example Click_Thermo_MSP.mbas
    @example Click_Thermo_PIC.mbas
    @example Click_Thermo_PIC32.mbas
    @example Click_Thermo_DSPIC.mbas
    @example Click_Thermo_AVR.mbas
    @example Click_Thermo_FT90x.mbas
    @example Click_Thermo_STM.mpas
    @example Click_Thermo_TIVA.mpas
    @example Click_Thermo_CEC.mpas
    @example Click_Thermo_KINETIS.mpas
    @example Click_Thermo_MSP.mpas
    @example Click_Thermo_PIC.mpas
    @example Click_Thermo_PIC32.mpas
    @example Click_Thermo_DSPIC.mpas
    @example Click_Thermo_AVR.mpas
    @example Click_Thermo_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __thermo_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */