/*
    __thermo_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__thermo_driver.h"
#include "__thermo_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __THERMO_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static void _delayTime();

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static void _delayTime()
{
    Delay_100ms();
    Delay_100ms();
    Delay_100ms();
    Delay_10ms();
    Delay_10ms();
    Delay_10ms();
    Delay_10ms();
    Delay_10ms();
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __THERMO_DRV_SPI__

void thermo_spiDriverInit(T_THERMO_P gpioObj, T_THERMO_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
    hal_gpio_csSet( 0 );
}

#endif
#ifdef   __THERMO_DRV_I2C__

void thermo_i2cDriverInit(T_THERMO_P gpioObj, T_THERMO_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __THERMO_DRV_UART__

void thermo_uartDriverInit(T_THERMO_P gpioObj, T_THERMO_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */


/* Read data from sensor function */
uint32_t thermo_readData()
{
    uint8_t buffer[ 4 ];
    uint32_t result;
    
    hal_gpio_csSet( 0 );
    _delayTime();
    hal_spiRead( buffer, 4 );
    hal_gpio_csSet( 1 );
    
    result = buffer[ 0 ];
    result <<= 8;
    result |=  buffer[ 1 ];
    result <<= 8;
    result |=  buffer[ 2 ];
    result <<= 8;
    result |=  buffer[ 3 ];
    
    return result;
}

/* Get thermocouple temperature function */
float thermo_getTemperature()
{
    uint8_t buffer[ 4 ];
    uint16_t tempData;
    float temperature;

    hal_gpio_csSet( 0 );
    _delayTime();
    hal_spiRead( buffer, 4 );
    hal_gpio_csSet( 1 );

    tempData = buffer[ 0 ];
    tempData <<= 8;
    tempData |=  buffer[ 1 ];
    
    if ( buffer[ 0 ] > 128 )
    {
        tempData = ~tempData;
        
        temperature = ( float ) ( ( tempData >> 2 ) & 0x03 );
        temperature *= -0.25;
        temperature -= ( float ) ( tempData >> 4 );
        temperature += 1.0;
    }
    else
    {
        temperature = ( float ) ( ( tempData >> 2 ) & 0x03 );
        temperature *= 0.25;
        temperature += ( float ) ( tempData >> 4 );
    }
    
    
    return temperature;
}

/* Get reference junction temperature function */
float thermo_getJunctionTemperature()
{
    uint8_t buffer[ 4 ];
    uint32_t tempAllData;
    uint16_t tempData;
    float temperature;

    tempAllData = thermo_readData();

    tempData = ( uint16_t ) tempAllData;

    if ( tempData > 32768 )
    {
        tempData = ~tempData;

        temperature = ( float ) ( ( tempData >> 4 ) & 0x0F );
        temperature *= -0.0625;
        temperature -= ( float ) ( tempData >> 8 );
        temperature += 1.0;
    }
    else
    {
        temperature = ( float ) ( ( tempData >> 4 ) & 0x0F );
        temperature *= 0.0625;
        temperature += ( float ) ( tempData >> 8 );
        temperature -= 1.0;
    }

    return temperature;
}

/* Check fault states function */
uint8_t thermo_checkFault()
{
    uint32_t tmp;

    tmp = thermo_readData();
    
    tmp >>= 16;
    tmp &= 0x01;

    return tmp;
}

/* Check short-circuited to Vcc function */
uint8_t thermo_shortCircuitedVcc()
{
    uint32_t tmp;

    tmp = thermo_readData();

    tmp >>= 2;
    tmp &= 0x01;

    return tmp;
}

/* Check short-circuited to GND function */
uint8_t thermo_shortCircuitedGND()
{
    uint32_t tmp;

    tmp = thermo_readData();

    tmp >>= 1;
    tmp &= 0x01;

    return tmp;
}

/* Check connections fault function */
uint8_t thermo_checkConnections()
{
    uint32_t tmp;

    tmp = thermo_readData();

    tmp &= 0x01;

    return tmp;
}



/* -------------------------------------------------------------------------- */
/*
  __thermo_driver.c

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