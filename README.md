![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Thermo Click

---

- **CIC Prefix**  : THERMO
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Feb 2019.

---

### Software Support

We provide a library for the Thermo Click on our [LibStock](https://libstock.mikroe.com/projects/view/381/thermo-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Thermo Click board. 
Library performs the communication with the device via SPI driver by reading data from MAX31855 sensor.
Library have function for measuring thermocouple temperature and convert to degree Celsius and 
function for checking the error: short-circuited to Vcc, short-circuited to GND or no connections.

Key functions :

- ``` float thermo_getTemperature() ``` - Get thermocouple temperature function.
- ``` uint8_t thermo_checkFault() ``` - Check fault states function.
- ``` uint32_t thermo_readData() ``` - Read all data from sensor function.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, SPI and LOG structures,
     sets CS pins as output.
- Application Initialization - Initialization driver enable's - SPI start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Thermo Click board.
     Temperature measured by the thermocouple is converter by MAX31855 sensor on Thermo click board.
     Displayed temperature is in degree Celsius.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart changes for every 3 sec.


```.c

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

```

Additional Functions :

- ``` void displayErrorMsg() ``` - Check and displayed error messages.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/381/thermo-click) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversion

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
