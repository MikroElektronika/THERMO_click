/*
Example for Thermo Click

    Date          : Feb 2019.
    Author        : Nenad Filipovic

Test configuration STM32 :

    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, SPI and LOG structures,
     sets CS pins as output.
- Application Initialization - Initialization driver enable's - SPI start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Thermo Click board.
     Temperature measured by the thermocouple is converter by MAX31855 sensor on Thermo click board.
     Displayed temperature is in degree Celsius.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart changes for every 3 sec.

Additional Functions :

- void displayErrorMsg() - Check and displayed error messages.


*/

#include "Click_Thermo_types.h"
#include "Click_Thermo_config.h"


float temperature;
char logText[ 50 ];
char degCel[ 4 ];

void displayErrorMsg()
{
    mikrobus_logWrite( "         ERROR         ", _LOG_LINE );
    
    if ( thermo_shortCircuitedVcc() )
        mikrobus_logWrite( " Short-circuited to Vcc ", _LOG_LINE );
        
    if ( thermo_shortCircuitedGND() )
        mikrobus_logWrite( " Short-circuited to GND ", _LOG_LINE );
        
    if ( thermo_checkConnections() )
        mikrobus_logWrite( "     No Connections     ", _LOG_LINE );
        
    mikrobus_logWrite( "------------------------", _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_THERMO_SPI_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    mikrobus_logWrite( "------------------------", _LOG_LINE );
    mikrobus_logWrite( "      Thermo Click      ", _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    thermo_spiDriverInit( (T_THERMO_P)&_MIKROBUS1_GPIO, (T_THERMO_P)&_MIKROBUS1_SPI );
    Delay_ms( 100 );
    
    mikrobus_logWrite( "   Driver Initialized   ", _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );
     
    degCel[ 0 ] = 32;
    degCel[ 1 ] = 176;
    degCel[ 2 ] = 67;
    degCel[ 3 ] = 0;

    if ( thermo_checkFault() )
        displayErrorMsg();
    else
        mikrobus_logWrite( "       STATUS OK        ", _LOG_LINE );
        
    mikrobus_logWrite( "------------------------", _LOG_LINE );
}

void applicationTask()
{
    temperature = thermo_getTemperature();
    
    FloatToStr( temperature, logText );
    mikrobus_logWrite( " Temperature : ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( degCel, _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_ms( 3000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}