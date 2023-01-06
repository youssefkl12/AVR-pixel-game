#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"LCD_config.h"
#include<util/delay.h>
#include "LCD_inti.h"
#include"LCD_private.h"
void LCD_vidSendCmd(u8 copy_u8Cmd){
	DIO_VidSetPinValue(Control_port,RS_PIN,PinLow);//we will set the register select to zero to send command
	DIO_VidSetPinValue(Control_port,RW_PIN,PinLow);//send zero to read/write pin to write
    //DIO_VidSetPortDir(Data_port,Output); we will set the directions in the main
    DIO_VidSetPortValue(Data_port,copy_u8Cmd);//we will send the command on the D0-D7 pins


    //the following section is to send a pules on the enable pin
    DIO_VidSetPinValue(Control_port,EN_PIN,PinHigh);
    _delay_ms(3);
    DIO_VidSetPinValue(Control_port,EN_PIN,PinLow);
	//
	
};
void LCD_vidSendData(u8 copy_u8Data){
	DIO_VidSetPinValue(Control_port,RS_PIN,PinHigh);
	DIO_VidSetPinValue(Control_port,RW_PIN,PinLow);
    //DIO_VidSetPortDir(Data_port,Output); we will set the directions in the main
    DIO_VidSetPortValue(Data_port,copy_u8Data);



    DIO_VidSetPinValue(Control_port,EN_PIN,PinHigh);
    _delay_ms(3);
    DIO_VidSetPinValue(Control_port,EN_PIN,PinLow);


};


void LCD_Clear(){
	LCD_vidSendCmd(1);
}



void LCD_vidInti(){
	_delay_ms(40);
	LCD_vidSendCmd(0b00111111);
	//_delay_ms(1);
	LCD_vidSendCmd(0b00001100);
	//_delay_ms(2);
	LCD_vidSendCmd(1);
	 //_delay_ms(2);
	//LCD_vidSendCmd(0b00000011);
}
void LCD_vidGotoXY(u8 copy_u8Xpos,u8 copy_u8Ypos){
u8 loc_u8Address=copy_u8Ypos;
if(copy_u8Xpos==1){
	loc_u8Address=loc_u8Address+0x40;
}
/*  x=0 |  00x00  | 00x01    |       |-->
 *  x=1 |  00x40  | 00x41    |       |-->
 **/


LCD_vidSendCmd(loc_u8Address+DDRAM_ADDRESS);//this will make the DDRAM addresss change to the point we want to draw at in the lcd

}


void LCD_vidSendSpecialChar(u8*Pattern,u8 Copy_u8Loc,u8 copy_u8Xpos,u8 copy_u8Ypos){
u8 loc_CGRAM=Copy_u8Loc*8;
LCD_vidSendCmd(loc_CGRAM+64);//now we are in the CGRAM as we moved to its memory location
for(u8 i=0;i<8;i++){
LCD_vidSendData(Pattern[i]);
}
LCD_vidGotoXY(copy_u8Xpos,copy_u8Ypos);
LCD_vidSendData(Copy_u8Loc);
}

void LCD_vidSendInt(u32 num){
if(num!=0){
LCD_vidSendInt(num/10);
LCD_vidSendData((num%10)+48);
}




}

void LCD_vidSendString(u8 *word,u8 copy_u8Xpos,u8 copy_u8Ypos){
	LCD_vidGotoXY(copy_u8Xpos,copy_u8Ypos);
for(u8 i=0;word[i]!='\0';i++){
LCD_vidSendData(word[i]);
}




}


