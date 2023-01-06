/*
   * main.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Youssef Khaled
 */
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_private.h"
#include"DIO_int.h"
#include"KPD_Config.h"
#include"KPD_init.h"
#include"LCD_config.h"
#include"LCD_inti.h"
#include"LCD_private.h"
#include<util/delay.h>


int main(){
u8 couter=0;
u8 x=1;
u8 y=2;
u8 obstucle_x=1;
u8 obstucle_y=15;
	//DIO_VidSetPortDir(Port_A,Input);
	//DIO_VidSetPortValue(Port_A,PinHigh);



	//DIO_VidSetPortDir(Port_B,Output);
	//DIO_VidSetPortValue(Port_A,PinHigh);
	u8 Hamoksha_run1[]={
		0b01110,
		0b01010,
		0b01110,
		0b10100,
		0b01110,
		0b00101,
		0b00100,
		0b01010
		};
u8 Obstcule_up[]={
0b00100,
0b01000,
0b00100,
0b01000,
0b00100,
0b01000,
0b00100,
0b01000
};

	//the first part of port A is the row
	DIO_VidSetPinDir(KPD_ROW_PORT,Pin_0,Input);
	DIO_VidSetPinDir(KPD_ROW_PORT,Pin_1,Input);
	DIO_VidSetPinDir(KPD_ROW_PORT,Pin_2,Input);
	DIO_VidSetPinDir(KPD_ROW_PORT,Pin_3,Input);

	DIO_VidSetPinValue(KPD_ROW_PORT,Pin_0,PinHigh);
	DIO_VidSetPinValue(KPD_ROW_PORT,Pin_1,PinHigh);
	DIO_VidSetPinValue(KPD_ROW_PORT,Pin_2,PinHigh);
	DIO_VidSetPinValue(KPD_ROW_PORT,Pin_3,PinHigh);

	//the second part of port A is the column

	DIO_VidSetPinDir(KPD_COLUMN_PORT,Pin_4,Output);
	DIO_VidSetPinDir(KPD_COLUMN_PORT,Pin_5,Output);
	DIO_VidSetPinDir(KPD_COLUMN_PORT,Pin_6,Output);
	DIO_VidSetPinDir(KPD_COLUMN_PORT,Pin_7,Output);

	DIO_VidSetPinValue(KPD_COLUMN_PORT,Pin_4,PinHigh);
	DIO_VidSetPinValue(KPD_COLUMN_PORT,Pin_5,PinHigh);
	DIO_VidSetPinValue(KPD_COLUMN_PORT,Pin_6,PinHigh);
	DIO_VidSetPinValue(KPD_COLUMN_PORT,Pin_7,PinHigh);

//intialize the LCD ports
	DIO_VidSetPortDir(Control_port,Output);
		DIO_VidSetPortDir(Data_port,Output);
		LCD_vidInti();
		volatile u8 z;
		LCD_vidSendSpecialChar(Hamoksha_run1,0,x,y);
		LCD_vidSendSpecialChar(Obstcule_up,1,obstucle_x,obstucle_y);
		while(1){
LCD_vidGotoXY(0,0);
LCD_vidSendData(couter+'0');
  z=KPD_u8GetPressedKey();
switch(z){
case '5':
	if(x==0){
     x=++x;
     LCD_Clear();
     LCD_vidGotoXY(x,y);
     LCD_vidSendData(0);

	}


	break;
case '6':
	if(y!=15){
		     y=++y;
			}
	LCD_Clear();
	LCD_vidGotoXY(x,y);
	LCD_vidSendData(0);

	break;
case '4':
	if(y!=2){
		     y=--y;
			}
	LCD_Clear();
	LCD_vidGotoXY(x,y);
	LCD_vidSendData(0);

	break;

case '1':
	if(x==1){
	     x=--x;

		}
	LCD_Clear();
	LCD_vidGotoXY(x,y);
	LCD_vidSendData(0);

	break;



}
LCD_vidGotoXY(obstucle_x,obstucle_y);
LCD_vidSendData(' ');
obstucle_y=--obstucle_y;
if(obstucle_y==1){
	couter=++couter;
obstucle_y=15;
if(obstucle_x==0){
	obstucle_x=1;
}else{
	obstucle_x=0;
}
}
LCD_vidGotoXY(obstucle_x,obstucle_y);
LCD_vidSendData(1);
if(couter==5){
break;
}
if(obstucle_x==x&&obstucle_y==y){
break;
}
_delay_ms(100);



		}
if(couter==5){
	LCD_Clear();
	LCD_vidSendString("YOU",0,7);
	LCD_vidSendString("WIN",1,7);
}else{
LCD_Clear();
LCD_vidSendString("GAME",0,6);
LCD_vidSendString("OVER",1,6);}
while(1){

}

}
