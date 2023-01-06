/*
 * KPD_prog.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Youssef Khaled
 */
#include<util/delay.h>
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"KPD_Config.h"

u8 KPD_ARR[4][4]={
		{'0','1','2','3'},
		{'4','5','6','7'},
		{'8','9','10','11'},
		{'12','13','14','15'}
};


u8 KPD_u8GetPressedKey(){
	u8 pressedKey;
volatile u8 x=5;
u8 Column_Arr[]={Pin_4,Pin_5,Pin_6,Pin_7};
u8 Row_Arr[]={Pin_0,Pin_1,Pin_2,Pin_3};
for(u8 i=0;i<4;i++){
	DIO_VidSetPinValue(KPD_COLUMN_PORT,Column_Arr[i],PinLow);
	for(u8 j=0;j<4;j++){
    DIO_VidGetPinValue(KPD_ROW_PORT,Row_Arr[j],&x);
    if(x==0){
    pressedKey=KPD_ARR[j][i];
//while(x==0){
	//DIO_VidGetPinValue(KPD_ROW_PORT,Row_Arr[j],&x);
//}
_delay_ms(200);

return pressedKey;


    }
	}
	DIO_VidSetPinValue(KPD_COLUMN_PORT,Column_Arr[i],PinHigh);


}
return 101;
}
