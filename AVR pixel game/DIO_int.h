#include"STD_Types.h"
#include "BIT_MATH.h"
//interface
/********************************************************************/
/*******************SWC:  DIO_int.h**********************************/
/*******************AUTHER:  YOUSSEF KHALED**************************/
/*******************VERSION:  v1.0***********************************/
/*******************DATE: 27-8-2022******************************* **/
/********************************************************************/
#ifndef DIO_INT_H
#define DIO_INT_H
typedef enum{
	PinHigh,
	PinLow
	
}et_PinValue;
typedef enum {
	Port_A,
	Port_B,
	Port_C,
	Port_D
	
}et_Ports;

typedef enum {
	Pin_0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7
	
}et_Pins;

typedef enum{
	Input,
	Output
}et_Dirction;

//********************************************************************
//this is to control single pins
/*set dio pin direction*/

void DIO_VidSetPinDir(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);
/*set dio pin value for output*/
void DIO_VidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value);
/*toggel bit*/
void DIO_VidSetPinValueToggel(u8 copy_u8Port,u8 copy_u8Pin);
/*get pin value*/
void DIO_VidGetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8* pu8Value);
//*****************************************************************




//********************************************************************
//this is to control sa whole port
/*set dio Port direction*/
void DIO_VidSetPortDir(u8 copy_u8Port,u8 copy_u8Direction);
/*set dio port value for output*/
void DIO_VidSetPortValue(u8 copy_u8Port,u8 copy_u8Value);
/*toggel port*/
void DIO_VidSetPortValueToggel(u8 copy_u8Port);
/*get port value*/
void DIO_VidGetPortValue(u8 copy_u8Port,u8* pu8Value);
//*****************************************************************

void NumberSSD(u8 copy_u8Port,u8 Num);

#endif
