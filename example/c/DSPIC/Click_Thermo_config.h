#include "Click_Thermo_types.h"


const uint32_t _THERMO_SPI_CFG[ 8 ] = 
{ 
	_SPI_MASTER,
	_SPI_8_BIT, 
	_SPI_PRESCALE_SEC_4, 
	_SPI_PRESCALE_PRI_4, 
	_SPI_SS_DISABLE, 
	_SPI_DATA_SAMPLE_MIDDLE, 
	_SPI_CLK_IDLE_LOW, 
	_SPI_IDLE_2_ACTIVE 
};

