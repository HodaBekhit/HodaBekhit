/*
 * DIO.c
 *
 * Created: 11/26/2023 9:13:18 PM
 *  Author: Dell
 */ 

#include "../LIB/std_types.h"
#include "../LIB/std_math.h"
#include "DIO.h"

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{ 
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enuErrors_Status=DIO_enumWrongPin;
	}
	else if (Copy_enumConfig>DIO_enumInputExternalPD)
	{
		Ret_enuErrors_Status=DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			 switch(Copy_enumConfig)
			 {
				 case(DIO_enumOutput):
				 SET_BIT(DDRA,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputInternalPU):
				 CLR_BIT(DDRA,Copy_enumPinNum);
				 SET_BIT(PORTA,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputExternalPD):
				 CLR_BIT(DDRA,Copy_enumPinNum);
				 SET_BIT(PORTA,Copy_enumPinNum);
				 break;
			 } 
			break;
			case DIO_enumPortB:
			 switch(Copy_enumConfig)
			 {
				 case(DIO_enumOutput):
				 SET_BIT(DDRB,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputInternalPU):
				 CLR_BIT(DDRB,Copy_enumPinNum);
				 SET_BIT(PORTB,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputExternalPD):
				 CLR_BIT(DDRB,Copy_enumPinNum);
				 SET_BIT(PORTB,Copy_enumPinNum);
				 break;
			 }
			break;
			case DIO_enumPortC:
			 switch(Copy_enumConfig)
			 {
				 case(DIO_enumOutput):
				 SET_BIT(DDRC,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputInternalPU):
				 CLR_BIT(DDRC,Copy_enumPinNum);
				 SET_BIT(PORTC,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputExternalPD):
				 CLR_BIT(DDRC,Copy_enumPinNum);
				 SET_BIT(PORTC,Copy_enumPinNum);
				 break;
			 }
			break;
			default:
			 switch(Copy_enumConfig)
			 {
				 case(DIO_enumOutput):
				 SET_BIT(DDRD,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputInternalPU):
				 CLR_BIT(DDRD,Copy_enumPinNum);
				 SET_BIT(PORTD,Copy_enumPinNum);
				 break;
				 case(DIO_enumInputExternalPD):
				 CLR_BIT(DDRD,Copy_enumPinNum);
				 SET_BIT(PORTD,Copy_enumPinNum);
				 break;
			 }		
		}
		Ret_enuErrors_Status=DIO_enumOk;	
	}
	return Ret_enuErrors_Status ;  
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumConfig>DIO_enumInputExternalPD)
	{
		Ret_enuErrors_Status=DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			 switch(Copy_enumConfig)
			 {
				 case(DIO_enumOutput):
				 DDRA=0xFF;
				 break;
				 case(DIO_enumInputInternalPU):
				 DDRA=0x00;
				 PORTA=0xFF;
				 break;
				 case(DIO_enumInputExternalPD):
				 DDRA=0x00;
				 PORTA=0xFF;
				 break;
			 }
			break;
			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case(DIO_enumOutput):
				DDRB=0xFF;
				break;
				case(DIO_enumInputInternalPU):
				DDRB=0x00;
				PORTB=0xFF;
				break;
				case(DIO_enumInputExternalPD):
				DDRB=0x00;
				PORTB=0xFF;
				break;
			}
			break;
			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case(DIO_enumOutput):
				DDRC=0xFF;
				break;
				case(DIO_enumInputInternalPU):
				DDRC=0x00;
				PORTC=0xFF;
				break;
				case(DIO_enumInputExternalPD):
				DDRC=0x00;
				PORTC=0xFF;
				break;
			}
			break;
			default:
			switch(Copy_enumConfig)
			{
				case(DIO_enumOutput):
				DDRD=0xFF;
				break;
				case(DIO_enumInputInternalPU):
				DDRD=0x00;
				PORTD=0xFF;
				break;
				case(DIO_enumInputExternalPD):
				DDRD=0x00;
				PORTD=0xFF;
				break;
			}	
		}	
		Ret_enuErrors_Status=DIO_enumOk;	
	}
	return Ret_enuErrors_Status;
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enuErrors_Status=DIO_enumWrongPin;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTA,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTB,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTC,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTD,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTD,Copy_enumPinNum);
			break;	
		}
		Ret_enuErrors_Status=DIO_enumOk;
	}
	return Ret_enuErrors_Status;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTA=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTA=0xFF;
			break;
			case DIO_enumPortB:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTB=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTB=0xFF;
			break;
			case DIO_enumPortC:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTC=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTC=0xFF;
			break;
			case DIO_enumPortD:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTD=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTD=0xFF;
			break;
		}
		Ret_enuErrors_Status=DIO_enumOk;
	}
	return Ret_enuErrors_Status;
}
	
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enuErrors_Status=DIO_enumWrongPin;
	}
	else if (Add_Pu8PinValue==NULLPTR)
	{
		Ret_enuErrors_Status=DIO_enumNullPointer;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue=GET_BIT(PINA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			*Add_Pu8PinValue=GET_BIT(PINB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			*Add_Pu8PinValue=GET_BIT(PINC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			*Add_Pu8PinValue=GET_BIT(PIND,Copy_enumPinNum);
			break;	
		}
		Ret_enuErrors_Status=DIO_enumOk;	
	}
	return Ret_enuErrors_Status;
}


