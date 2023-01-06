
//we are useing this as an if condtion which says that if we find that this file hasnot been included before in the
//main file we will includ it


#ifndef BIT_MATH_h
#define BIT_MATH_h

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define Toggel_Bit(reg,bit) reg^=(1<<bit)
#define GET_BIT(reg,bit)    (reg>>bit)&(1)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))

#endif
