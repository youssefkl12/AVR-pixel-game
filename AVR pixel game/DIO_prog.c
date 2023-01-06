#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_private.h"
#include"DIO_int.h"

/********************************************************************
//this is to control single pins
//set dio pin direction*/
void DIO_VidSetPinDir(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction){
	if(copy_u8Direction==Output){
		switch(copy_u8Port){
			case Port_A:
			SET_BIT(DDRA,copy_u8Pin);
			break;
			case Port_B:
			SET_BIT(DDRB,copy_u8Pin);
			break;
			
			case Port_C:
			SET_BIT(DDRC,copy_u8Pin);
			break;
			
			case Port_D:
			SET_BIT(DDRD,copy_u8Pin);
			break;
			
			
		}
		
	}else if(copy_u8Direction==Input){
		
		switch(copy_u8Port){
			case Port_A:
			CLR_BIT(DDRA,copy_u8Pin);
			break;
			case Port_B:
			CLR_BIT(DDRB,copy_u8Pin);
			break;
			
			case Port_C:
			CLR_BIT(DDRC,copy_u8Pin);
			break;
			
			case Port_D:
			CLR_BIT(DDRD,copy_u8Pin);
			break;
			
			
		}
		
		
		
	}
	
}
/*set dio pin value for output*/
void DIO_VidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value){
	
		if(copy_u8Value==PinHigh){
		switch(copy_u8Port){
			case Port_A:
			SET_BIT(PORTA,copy_u8Pin);
			break;
			case Port_B:
			SET_BIT(PORTB,copy_u8Pin);
			break;
			
			case Port_C:
			SET_BIT(PORTC,copy_u8Pin);
			break;
			
			case Port_D:
			SET_BIT(PORTD,copy_u8Pin);
			break;
			
			
		}
		
	}else if(copy_u8Value==PinLow){
		
		switch(copy_u8Port){
			case Port_A:
			CLR_BIT(PORTA,copy_u8Pin);
			break;
			case Port_B:
			CLR_BIT(PORTB,copy_u8Pin);
			break;
			
			case Port_C:
			CLR_BIT(PORTC,copy_u8Pin);
			break;
			
			case Port_D:
			CLR_BIT(PORTD,copy_u8Pin);
			break;
			
			
		}
		
		
		
	}
	
}
/*toggel bit*/
void DIO_VidSetPinValueToggel(u8 copy_u8Port,u8 copy_u8Pin){

	switch(copy_u8Port){
				case Port_A:
				Toggel_Bit(PORTA,copy_u8Pin);
				break;
				case Port_B:
				Toggel_Bit(PORTB,copy_u8Pin);
				break;

				case Port_C:
				Toggel_Bit(PORTC,copy_u8Pin);
				break;

				case Port_D:
				Toggel_Bit(PORTD,copy_u8Pin);
				break;


			}
}
/*get pin value*/
void DIO_VidGetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8* pu8Value){
	
	switch(copy_u8Port){
			case Port_A:
		*pu8Value=GET_BIT(PINA,copy_u8Pin);
			break;
			case Port_B:
			*pu8Value=GET_BIT(PINB,copy_u8Pin);
			break;
			
			case Port_C:
			*pu8Value=GET_BIT(PINC,copy_u8Pin);
			break;
			
			case Port_D:
			*pu8Value=GET_BIT(PIND,copy_u8Pin);
			break;
			
			
		}
	
}
//*****************************************************************




//********************************************************************
//this is to control sa whole port
/*set dio Port direction*/
void DIO_VidSetPortDir(u8 copy_u8Port,u8 copy_u8Direction){
	
		if(copy_u8Direction==Output){
		switch(copy_u8Port){
			case Port_A:
			SET_BIT(DDRA,0);
			SET_BIT(DDRA,1);
			SET_BIT(DDRA,2);
			SET_BIT(DDRA,3);
			SET_BIT(DDRA,4);
			SET_BIT(DDRA,5);
			SET_BIT(DDRA,6);
			SET_BIT(DDRA,7);
			break;
			case Port_B:
			SET_BIT(DDRB,0);
			SET_BIT(DDRB,1);
			SET_BIT(DDRB,2);
			SET_BIT(DDRB,3);
			SET_BIT(DDRB,4);
			SET_BIT(DDRB,5);
			SET_BIT(DDRB,6);
			SET_BIT(DDRB,7);
			break;
			
			case Port_C:
			SET_BIT(DDRC,0);
			SET_BIT(DDRC,1);
			SET_BIT(DDRC,2);
			SET_BIT(DDRC,3);
			SET_BIT(DDRC,4);
			SET_BIT(DDRC,5);
			SET_BIT(DDRC,6);
			SET_BIT(DDRC,7);
			break;
			
			case Port_D:
			SET_BIT(DDRD,0);
			SET_BIT(DDRD,1);
			SET_BIT(DDRD,2);
			SET_BIT(DDRD,3);
			SET_BIT(DDRD,4);
			SET_BIT(DDRD,5);
			SET_BIT(DDRD,6);
			SET_BIT(DDRD,7);
			
			break;
			
			
		}
		
	}else if(copy_u8Direction==Input){
		
		switch(copy_u8Port){
			case Port_A:
			CLR_BIT(DDRA,0);
			CLR_BIT(DDRA,1);
			CLR_BIT(DDRA,2);
			CLR_BIT(DDRA,3);
			CLR_BIT(DDRA,4);
			CLR_BIT(DDRA,5);
			CLR_BIT(DDRA,6);
			CLR_BIT(DDRA,7);
			break;
			case Port_B:
            CLR_BIT(DDRB,0);
			CLR_BIT(DDRB,1);
			CLR_BIT(DDRB,2);
			CLR_BIT(DDRB,3);
			CLR_BIT(DDRB,4);
			CLR_BIT(DDRB,5);
			CLR_BIT(DDRB,6);
			CLR_BIT(DDRB,7);
			break;
			
			case Port_C:
            CLR_BIT(DDRC,0);
			CLR_BIT(DDRC,1);
			CLR_BIT(DDRC,2);
			CLR_BIT(DDRC,3);
			CLR_BIT(DDRC,4);
			CLR_BIT(DDRC,5);
			CLR_BIT(DDRC,6);
			CLR_BIT(DDRC,7);			
			break;
			
			case Port_D:
			CLR_BIT(DDRD,0);
			CLR_BIT(DDRD,1);
			CLR_BIT(DDRD,2);
			CLR_BIT(DDRD,3);
			CLR_BIT(DDRD,4);
			CLR_BIT(DDRD,5);
			CLR_BIT(DDRD,6);
			CLR_BIT(DDRD,7);	
			break;
			
			
		}
		
		
		
	}
	
	
	
}
/*set dio port value for output*/
void DIO_VidSetPortValue(u8 copy_u8Port,u8 copy_u8Value){
	switch(copy_u8Port){
	case Port_A:
		PORTA=copy_u8Value;
		break;
	case Port_B:
		PORTB=copy_u8Value;
			break;
	case Port_C:
		PORTC=copy_u8Value;
			break;
	case Port_D:
		PORTD=copy_u8Value;
			break;
	}
	
	
}
/*toggel port*/
void DIO_VidSetPortValueToggel(u8 copy_u8Port){
	switch(copy_u8Port){
				case Port_A:
				Toggel_Bit(PORTA,0);
				Toggel_Bit(PORTA,1);
				Toggel_Bit(PORTA,2);
				Toggel_Bit(PORTA,3);
				Toggel_Bit(PORTA,4);
				Toggel_Bit(PORTA,5);
				Toggel_Bit(PORTA,6);
				Toggel_Bit(PORTA,7);
				break;

				case Port_B:
			    Toggel_Bit(PORTB,0);
				Toggel_Bit(PORTB,1);
				Toggel_Bit(PORTB,2);
				Toggel_Bit(PORTB,3);
				Toggel_Bit(PORTB,4);
				Toggel_Bit(PORTB,5);
				Toggel_Bit(PORTB,6);
				Toggel_Bit(PORTB,7);
				break;

				case Port_C:
				Toggel_Bit(PORTC,0);
				Toggel_Bit(PORTC,1);
				Toggel_Bit(PORTC,2);
				Toggel_Bit(PORTC,3);
				Toggel_Bit(PORTC,4);
				Toggel_Bit(PORTC,5);
				Toggel_Bit(PORTC,6);
				Toggel_Bit(PORTC,7);
				break;

				case Port_D:
				Toggel_Bit(PORTD,0);
				Toggel_Bit(PORTD,1);
				Toggel_Bit(PORTD,2);
				Toggel_Bit(PORTD,3);
				Toggel_Bit(PORTD,4);
				Toggel_Bit(PORTD,5);
				Toggel_Bit(PORTD,6);
				Toggel_Bit(PORTD,7);



			}


}
/*get port value*/
void DIO_VidGetPortValue(u8 copy_u8Port,u8* pu8Value){
	switch(copy_u8Port){
		
			case Port_A:
		pu8Value[0]=GET_BIT(PINA,0);
		pu8Value[1]=GET_BIT(PINA,1);
		pu8Value[2]=GET_BIT(PINA,2);
		pu8Value[3]=GET_BIT(PINA,3);
		pu8Value[4]=GET_BIT(PINA,4);
		pu8Value[5]=GET_BIT(PINA,5);
		pu8Value[6]=GET_BIT(PINA,6);
		pu8Value[7]=GET_BIT(PINA,7);
			break;
			case Port_B:
		pu8Value[0]=GET_BIT(PINB,0);
		pu8Value[1]=GET_BIT(PINB,1);
		pu8Value[2]=GET_BIT(PINB,2);
		pu8Value[3]=GET_BIT(PINB,3);
		pu8Value[4]=GET_BIT(PINB,4);
		pu8Value[5]=GET_BIT(PINB,5);
		pu8Value[6]=GET_BIT(PINB,6);
		pu8Value[7]=GET_BIT(PINB,7);
			break;
			
			case Port_C:
		pu8Value[0]=GET_BIT(PINC,0);
		pu8Value[1]=GET_BIT(PINC,1);
		pu8Value[2]=GET_BIT(PINC,2);
		pu8Value[3]=GET_BIT(PINC,3);
		pu8Value[4]=GET_BIT(PINC,4);
		pu8Value[5]=GET_BIT(PINC,5);
		pu8Value[6]=GET_BIT(PINC,6);
		pu8Value[7]=GET_BIT(PINC,7);
			break;
			
			case Port_D:
		pu8Value[0]=GET_BIT(PIND,0);
		pu8Value[1]=GET_BIT(PIND,1);
		pu8Value[2]=GET_BIT(PIND,2);
		pu8Value[3]=GET_BIT(PIND,3);
		pu8Value[4]=GET_BIT(PIND,4);
		pu8Value[5]=GET_BIT(PIND,5);
		pu8Value[6]=GET_BIT(PIND,6);
		pu8Value[7]=GET_BIT(PIND,7);
			break;
			
			
		}
	
	
	
}
//*****************************************************************

void NumberSSD(u8 copy_u8Port,u8 Num){
	u8 SSD[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
    switch(copy_u8Port){
    case Port_A:
    	for(u8 i=0;i<8;i++){
    		DIO_VidSetPinValue(Port_A,i,~GET_BIT(SSD[Num],i));
    	}
    	break;
    case Port_B:
    	for(u8 i=0;i<8;i++){
    	    		DIO_VidSetPinValue(Port_B,i,~GET_BIT(SSD[Num],i));

    	    	}
     break;
    case Port_C:
    	for(u8 i=0;i<8;i++){
    		DIO_VidSetPinValue(Port_C,i,~GET_BIT(SSD[Num],i));
    	}
       	break;
    case Port_D:
    	for(u8 i=0;i<8;i++){
    		DIO_VidSetPinValue(Port_D,i,~GET_BIT(SSD[Num],i));
    	}
       	break;




    };

}

