
#ifndef LCD_INTI_H
#define LCD_INTI_H

void LCD_vidSendCmd(u8 copy_u8Cmd);
void LCD_vidSendData(u8 copy_u8Data);
void LCD_vidInti();
void LCD_Clear();
void LCD_vidGotoXY(u8 copy_u8Xpos,u8 copy_u8Ypos);
void LCD_vidSendSpecialChar(u8*Pattern,u8 Copy_u8Loc,u8 copy_u8Xpos,u8 copy_u8Ypos);
void LCD_vidSendInt(u32 num);
void LCD_vidSendString(u8 *word,u8 copy_u8Xpos,u8 copy_u8Ypos);
#endif
