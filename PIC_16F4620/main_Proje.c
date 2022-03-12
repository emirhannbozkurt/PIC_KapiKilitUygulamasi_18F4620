#include <18F4620.h>
#device adc=8



#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES NOBROWNOUT               //No brownout reset
//#FUSES BORV20                   //Brownout reset at 2.0V
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOCPB                    //No Boot Block code protection
#FUSES NOEBTRB                  //Boot block not protected from table reads
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES NOPBADEN                 //PORTB pins are configured as digital I/O on RESET
#FUSES NOLPT1OSC                //Timer1 configured for higher power operation
#FUSES MCLR                   //Master Clear pin used for I/O



#use delay(clock=4000000)

#include <ozel_karakter_LCD.c>
#use fast_io(b)
#use fast_io(c)
#define bak pin_b0



int tt[]={  1, 2, 3, 10,//  0  1  2  3
            4, 5, 6, 11,//  4  5  6  7
            7, 8, 9, 12,//  8  9  10 11
            14,0, 15,13,};//12 13 14 15


         //***UYARILARI OKU*****\\

   int al[]={0,0,0,0};//al ve admin dizilerinin eleman sayýlarý eþit olmalýdýr.k deðiþkeninin deðeri, bu eleman sayýsý kadar olmalýdýr.
int admin[]={1,2,3,6};  int k=4;
int dns[100][4]={};
int tus=0;int daireno=1;int dairesifre[4];int sil=0x01;int daire[2];int16 i=0;int j=0;int16 ee=0;int d=0;
int tusal(char x){switch(x){
  case 0:return(1);break;
  case 1:return(2);break;
  case 2:return(3);break;
  case 3:return(10);break;
  case 4:return(4);break;
  case 5:return(5);break;
  case 6:return(6);break;
  case 7:return(11);break;
  case 8:return(7);break;
  case 9:return(8);break;
  case 10:return(9);break;
  case 11:return(12);break;
  case 12:return(14);break;
  case 13:return(0);break;
  case 14:return(15);break;
  case 15:return(13);break;  
}}

void eepromyaz(int x){switch(x){
  case 0:  for(i=1,j=0;j<4;i++,j++){write_eeprom(i,dns[0][j]);}break;
  case 1:  for(i=5,j=0;j<4;i++,j++){write_eeprom(i,dns[1][j]);}break;
  case 2:  for(i=9,j=0;j<4;i++,j++){write_eeprom(i,dns[2][j]);}break;
  case 3:  for(i=13,j=0;j<4;i++,j++){write_eeprom(i,dns[3][j]);}break;
  case 4:  for(i=17,j=0;j<4;i++,j++){write_eeprom(i,dns[4][j]);}break;
  case 5:  for(i=21,j=0;j<4;i++,j++){write_eeprom(i,dns[5][j]);}break;
  case 6:  for(i=25,j=0;j<4;i++,j++){write_eeprom(i,dns[6][j]);}break;
  case 7:  for(i=29,j=0;j<4;i++,j++){write_eeprom(i,dns[7][j]);}break;
  case 8:  for(i=33,j=0;j<4;i++,j++){write_eeprom(i,dns[8][j]);}break;
  case 9:  for(i=37,j=0;j<4;i++,j++){write_eeprom(i,dns[9][j]);}break;
  case 10: for(i=41,j=0;j<4;i++,j++){write_eeprom(i,dns[10][j]);}break;
  case 11: for(i=45,j=0;j<4;i++,j++){write_eeprom(i,dns[11][j]);}break;
  case 12: for(i=49,j=0;j<4;i++,j++){write_eeprom(i,dns[12][j]);}break;
  case 13: for(i=53,j=0;j<4;i++,j++){write_eeprom(i,dns[13][j]);}break;
  case 14: for(i=57,j=0;j<4;i++,j++){write_eeprom(i,dns[14][j]);}break;
  case 15: for(i=61,j=0;j<4;i++,j++){write_eeprom(i,dns[15][j]);}break;
  case 16: for(i=65,j=0;j<4;i++,j++){write_eeprom(i,dns[16][j]);}break;
  case 17: for(i=69,j=0;j<4;i++,j++){write_eeprom(i,dns[17][j]);}break;
  case 18: for(i=73,j=0;j<4;i++,j++){write_eeprom(i,dns[18][j]);}break;
  case 19: for(i=77,j=0;j<4;i++,j++){write_eeprom(i,dns[19][j]);}break;
  case 20: for(i=81,j=0;j<4;i++,j++){write_eeprom(i,dns[20][j]);}break;
  case 21: for(i=85,j=0;j<4;i++,j++){write_eeprom(i,dns[21][j]);}break;
  case 22: for(i=89,j=0;j<4;i++,j++){write_eeprom(i,dns[22][j]);}break;
  case 23: for(i=93,j=0;j<4;i++,j++){write_eeprom(i,dns[23][j]);}break;
  case 24: for(i=97,j=0;j<4;i++,j++){write_eeprom(i,dns[24][j]);}break;
  case 25: for(i=101,j=0;j<4;i++,j++){write_eeprom(i,dns[25][j]);}break;
  case 26: for(i=105,j=0;j<4;i++,j++){write_eeprom(i,dns[26][j]);}break;
  case 27: for(i=109,j=0;j<4;i++,j++){write_eeprom(i,dns[27][j]);}break;
  case 28: for(i=113,j=0;j<4;i++,j++){write_eeprom(i,dns[28][j]);}break;
  case 29: for(i=117,j=0;j<4;i++,j++){write_eeprom(i,dns[29][j]);}break;
  case 30: for(i=121,j=0;j<4;i++,j++){write_eeprom(i,dns[30][j]);}break;
  case 31: for(i=125,j=0;j<4;i++,j++){write_eeprom(i,dns[31][j]);}break;
  case 32: for(i=129,j=0;j<4;i++,j++){write_eeprom(i,dns[32][j]);}break;
  case 33: for(i=133,j=0;j<4;i++,j++){write_eeprom(i,dns[33][j]);}break;
  case 34: for(i=137,j=0;j<4;i++,j++){write_eeprom(i,dns[34][j]);}break;
  case 35: for(i=141,j=0;j<4;i++,j++){write_eeprom(i,dns[35][j]);}break;
  case 36: for(i=145,j=0;j<4;i++,j++){write_eeprom(i,dns[36][j]);}break;
  case 37: for(i=149,j=0;j<4;i++,j++){write_eeprom(i,dns[37][j]);}break;
  case 38: for(i=153,j=0;j<4;i++,j++){write_eeprom(i,dns[38][j]);}break;
  case 39: for(i=157,j=0;j<4;i++,j++){write_eeprom(i,dns[39][j]);}break;
  case 40: for(i=161,j=0;j<4;i++,j++){write_eeprom(i,dns[40][j]);}break;
  case 41: for(i=165,j=0;j<4;i++,j++){write_eeprom(i,dns[41][j]);}break;
  case 42: for(i=169,j=0;j<4;i++,j++){write_eeprom(i,dns[42][j]);}break;
  case 43: for(i=173,j=0;j<4;i++,j++){write_eeprom(i,dns[43][j]);}break;
  case 44: for(i=177,j=0;j<4;i++,j++){write_eeprom(i,dns[44][j]);}break;
  case 45: for(i=181,j=0;j<4;i++,j++){write_eeprom(i,dns[45][j]);}break;
  case 46: for(i=185,j=0;j<4;i++,j++){write_eeprom(i,dns[46][j]);}break;
  case 47: for(i=189,j=0;j<4;i++,j++){write_eeprom(i,dns[47][j]);}break;
  case 48: for(i=193,j=0;j<4;i++,j++){write_eeprom(i,dns[48][j]);}break;
  case 49: for(i=197,j=0;j<4;i++,j++){write_eeprom(i,dns[49][j]);}break;
  case 50: for(i=201,j=0;j<4;i++,j++){write_eeprom(i,dns[50][j]);}break;
  case 51: for(i=205,j=0;j<4;i++,j++){write_eeprom(i,dns[51][j]);}break;
  case 52: for(i=209,j=0;j<4;i++,j++){write_eeprom(i,dns[52][j]);}break;
  case 53: for(i=213,j=0;j<4;i++,j++){write_eeprom(i,dns[53][j]);}break;
  case 54: for(i=217,j=0;j<4;i++,j++){write_eeprom(i,dns[54][j]);}break;
  case 55: for(i=221,j=0;j<4;i++,j++){write_eeprom(i,dns[55][j]);}break;
  case 56: for(i=225,j=0;j<4;i++,j++){write_eeprom(i,dns[56][j]);}break;
  case 57: for(i=229,j=0;j<4;i++,j++){write_eeprom(i,dns[57][j]);}break;
  case 58: for(i=233,j=0;j<4;i++,j++){write_eeprom(i,dns[58][j]);}break;
  case 59: for(i=237,j=0;j<4;i++,j++){write_eeprom(i,dns[59][j]);}break;
  case 60: for(i=241,j=0;j<4;i++,j++){write_eeprom(i,dns[60][j]);}break;
  case 61: for(i=245,j=0;j<4;i++,j++){write_eeprom(i,dns[61][j]);}break;
  case 62: for(i=249,j=0;j<4;i++,j++){write_eeprom(i,dns[62][j]);}break;
  case 63: for(i=253,j=0;j<4;i++,j++){write_eeprom(i,dns[63][j]);}break;
  case 64: for(i=257,j=0;j<4;i++,j++){write_eeprom(i,dns[64][j]);}break;
  case 65: for(i=261,j=0;j<4;i++,j++){write_eeprom(i,dns[65][j]);}break;
  case 66: for(i=265,j=0;j<4;i++,j++){write_eeprom(i,dns[66][j]);}break;
  case 67: for(i=269,j=0;j<4;i++,j++){write_eeprom(i,dns[67][j]);}break;
  case 68: for(i=273,j=0;j<4;i++,j++){write_eeprom(i,dns[68][j]);}break;
  case 69: for(i=277,j=0;j<4;i++,j++){write_eeprom(i,dns[69][j]);}break;
  case 70: for(i=281,j=0;j<4;i++,j++){write_eeprom(i,dns[70][j]);}break;
  case 71: for(i=285,j=0;j<4;i++,j++){write_eeprom(i,dns[71][j]);}break;
  case 72: for(i=289,j=0;j<4;i++,j++){write_eeprom(i,dns[72][j]);}break;
  case 73: for(i=293,j=0;j<4;i++,j++){write_eeprom(i,dns[73][j]);}break;
  case 74: for(i=297,j=0;j<4;i++,j++){write_eeprom(i,dns[74][j]);}break;
  case 75: for(i=301,j=0;j<4;i++,j++){write_eeprom(i,dns[75][j]);}break;
  case 76: for(i=305,j=0;j<4;i++,j++){write_eeprom(i,dns[76][j]);}break;
  case 77: for(i=309,j=0;j<4;i++,j++){write_eeprom(i,dns[77][j]);}break;
  case 78: for(i=313,j=0;j<4;i++,j++){write_eeprom(i,dns[78][j]);}break;
  case 79: for(i=317,j=0;j<4;i++,j++){write_eeprom(i,dns[79][j]);}break;
  case 80: for(i=321,j=0;j<4;i++,j++){write_eeprom(i,dns[80][j]);}break;
  case 81: for(i=325,j=0;j<4;i++,j++){write_eeprom(i,dns[81][j]);}break;
  case 82: for(i=329,j=0;j<4;i++,j++){write_eeprom(i,dns[82][j]);}break;
  case 83: for(i=333,j=0;j<4;i++,j++){write_eeprom(i,dns[83][j]);}break;
  case 84: for(i=337,j=0;j<4;i++,j++){write_eeprom(i,dns[84][j]);}break;
  case 85: for(i=341,j=0;j<4;i++,j++){write_eeprom(i,dns[85][j]);}break;
  case 86: for(i=345,j=0;j<4;i++,j++){write_eeprom(i,dns[86][j]);}break;
  case 87: for(i=349,j=0;j<4;i++,j++){write_eeprom(i,dns[87][j]);}break;
  case 88: for(i=353,j=0;j<4;i++,j++){write_eeprom(i,dns[88][j]);}break;
  case 89: for(i=357,j=0;j<4;i++,j++){write_eeprom(i,dns[89][j]);}break;
  case 90: for(i=361,j=0;j<4;i++,j++){write_eeprom(i,dns[90][j]);}break;
  case 91: for(i=365,j=0;j<4;i++,j++){write_eeprom(i,dns[91][j]);}break;
  case 92: for(i=369,j=0;j<4;i++,j++){write_eeprom(i,dns[92][j]);}break;
  case 93: for(i=373,j=0;j<4;i++,j++){write_eeprom(i,dns[93][j]);}break;
  case 94: for(i=377,j=0;j<4;i++,j++){write_eeprom(i,dns[94][j]);}break;
  case 95: for(i=381,j=0;j<4;i++,j++){write_eeprom(i,dns[95][j]);}break;
  case 96: for(i=385,j=0;j<4;i++,j++){write_eeprom(i,dns[96][j]);}break;
  case 97: for(i=389,j=0;j<4;i++,j++){write_eeprom(i,dns[97][j]);}break;
  case 98: for(i=393,j=0;j<4;i++,j++){write_eeprom(i,dns[98][j]);}break;
  case 99: for(i=397,j=0;j<4;i++,j++){write_eeprom(i,dns[99][j]);}break;
  }}
void eepromsil(int x){switch(x){
  case 0:  for(d=0,i=1,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 1:  for(d=1,i=5,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 2:  for(d=2,i=9,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 3:  for(d=3,i=13,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 4:  for(d=4,i=17,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 5:  for(d=5,i=21,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 6:  for(d=6,i=25,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 7:  for(d=7,i=29,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 8:  for(d=8,i=33,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 9:  for(d=9,i=37,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 10: for(d=10,i=41,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 11: for(d=11,i=45,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 12: for(d=12,i=49,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 13: for(d=13,i=53,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 14: for(d=14,i=57,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 15: for(d=15,i=61,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 16: for(d=16,i=65,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 17: for(d=17,i=69,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 18: for(d=18,i=73,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 19: for(d=19,i=77,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 20: for(d=20,i=81,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 21: for(d=21,i=85,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 22: for(d=22,i=89,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 23: for(d=23,i=93,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 24: for(d=24,i=97,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 25: for(d=25,i=101,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 26: for(d=26,i=105,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 27: for(d=27,i=109,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 28: for(d=28,i=113,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 29: for(d=29,i=117,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 30: for(d=30,i=121,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 31: for(d=31,i=125,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 32: for(d=32,i=129,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 33: for(d=33,i=133,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 34: for(d=34,i=137,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 35: for(d=35,i=141,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 36: for(d=36,i=145,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 37: for(d=37,i=149,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 38: for(d=38,i=153,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 39: for(d=39,i=157,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 40: for(d=40,i=161,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 41: for(d=41,i=165,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 42: for(d=42,i=169,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 43: for(d=43,i=173,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 44: for(d=44,i=177,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 45: for(d=45,i=181,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 46: for(d=46,i=185,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 47: for(d=47,i=189,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 48: for(d=48,i=193,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 49: for(d=49,i=197,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 50: for(d=50,i=201,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 51: for(d=51,i=205,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 52: for(d=52,i=209,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 53: for(d=53,i=213,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 54: for(d=54,i=217,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 55: for(d=55,i=221,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 56: for(d=56,i=225,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 57: for(d=57,i=229,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 58: for(d=58,i=233,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 59: for(d=59,i=237,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 60: for(d=60,i=241,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 61: for(d=61,i=245,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 62: for(d=62,i=249,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 63: for(d=63,i=253,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 64: for(d=64,i=257,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 65: for(d=65,i=261,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 66: for(d=66,i=265,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 67: for(d=67,i=269,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 68: for(d=68,i=273,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 69: for(d=69,i=277,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 70: for(d=70,i=281,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 71: for(d=71,i=285,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 72: for(d=72,i=289,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 73: for(d=73,i=293,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 74: for(d=74,i=297,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 75: for(d=75,i=301,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 76: for(d=76,i=305,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 77: for(d=77,i=309,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 78: for(d=78,i=313,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 79: for(d=79,i=317,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 80: for(d=80,i=321,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 81: for(d=81,i=325,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 82: for(d=82,i=329,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 83: for(d=83,i=333,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 84: for(d=84,i=337,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 85: for(d=85,i=341,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 86: for(d=86,i=345,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 87: for(d=87,i=349,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 88: for(d=88,i=353,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 89: for(d=89,i=357,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 90: for(d=90,i=361,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 91: for(d=91,i=365,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 92: for(d=92,i=369,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 93: for(d=93,i=373,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 94: for(d=94,i=377,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 95: for(d=95,i=381,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 96: for(d=96,i=385,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 97: for(d=97,i=389,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 98: for(d=98,i=393,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 99: for(d=99,i=397,j=0;j<4;i++,j++){write_eeprom(i,0);dns[d][j]=0;}break;
  case 100:write_eeprom(500,0);                          break;
}}
void eepromoku(int x){switch(x){
  case 0:  for(i=1,j=0;j<4;i++,j++){dns[0][j]=read_eeprom(i);}break;
  case 1:  for(i=5,j=0;j<4;i++,j++){dns[1][j]=read_eeprom(i);}break;
  case 2:  for(i=9,j=0;j<4;i++,j++){dns[2][j]=read_eeprom(i);}break;
  case 3:  for(i=13,j=0;j<4;i++,j++){dns[3][j]=read_eeprom(i);}break;
  case 4:  for(i=17,j=0;j<4;i++,j++){dns[4][j]=read_eeprom(i);}break;
  case 5:  for(i=21,j=0;j<4;i++,j++){dns[5][j]=read_eeprom(i);}break;
  case 6:  for(i=25,j=0;j<4;i++,j++){dns[6][j]=read_eeprom(i);}break;
  case 7:  for(i=29,j=0;j<4;i++,j++){dns[7][j]=read_eeprom(i);}break;
  case 8:  for(i=33,j=0;j<4;i++,j++){dns[8][j]=read_eeprom(i);}break;
  case 9:  for(i=37,j=0;j<4;i++,j++){dns[9][j]=read_eeprom(i);}break;
  case 10: for(i=41,j=0;j<4;i++,j++){dns[10][j]=read_eeprom(i);}break;
  case 11: for(i=45,j=0;j<4;i++,j++){dns[11][j]=read_eeprom(i);}break;
  case 12: for(i=49,j=0;j<4;i++,j++){dns[12][j]=read_eeprom(i);}break;
  case 13: for(i=53,j=0;j<4;i++,j++){dns[13][j]=read_eeprom(i);}break;
  case 14: for(i=57,j=0;j<4;i++,j++){dns[14][j]=read_eeprom(i);}break;
  case 15: for(i=61,j=0;j<4;i++,j++){dns[15][j]=read_eeprom(i);}break;
  case 16: for(i=65,j=0;j<4;i++,j++){dns[16][j]=read_eeprom(i);}break;
  case 17: for(i=69,j=0;j<4;i++,j++){dns[17][j]=read_eeprom(i);}break;
  case 18: for(i=73,j=0;j<4;i++,j++){dns[18][j]=read_eeprom(i);}break;
  case 19: for(i=77,j=0;j<4;i++,j++){dns[19][j]=read_eeprom(i);}break;
  case 20: for(i=81,j=0;j<4;i++,j++){dns[20][j]=read_eeprom(i);}break;
  case 21: for(i=85,j=0;j<4;i++,j++){dns[21][j]=read_eeprom(i);}break;
  case 22: for(i=89,j=0;j<4;i++,j++){dns[22][j]=read_eeprom(i);}break;
  case 23: for(i=93,j=0;j<4;i++,j++){dns[23][j]=read_eeprom(i);}break;
  case 24: for(i=97,j=0;j<4;i++,j++){dns[24][j]=read_eeprom(i);}break;
  case 25: for(i=101,j=0;j<4;i++,j++){dns[25][j]=read_eeprom(i);}break;
  case 26: for(i=105,j=0;j<4;i++,j++){dns[26][j]=read_eeprom(i);}break;
  case 27: for(i=109,j=0;j<4;i++,j++){dns[27][j]=read_eeprom(i);}break;
  case 28: for(i=113,j=0;j<4;i++,j++){dns[28][j]=read_eeprom(i);}break;
  case 29: for(i=117,j=0;j<4;i++,j++){dns[29][j]=read_eeprom(i);}break;
  case 30: for(i=121,j=0;j<4;i++,j++){dns[30][j]=read_eeprom(i);}break;
  case 31: for(i=125,j=0;j<4;i++,j++){dns[31][j]=read_eeprom(i);}break;
  case 32: for(i=129,j=0;j<4;i++,j++){dns[32][j]=read_eeprom(i);}break;
  case 33: for(i=133,j=0;j<4;i++,j++){dns[33][j]=read_eeprom(i);}break;
  case 34: for(i=137,j=0;j<4;i++,j++){dns[34][j]=read_eeprom(i);}break;
  case 35: for(i=141,j=0;j<4;i++,j++){dns[35][j]=read_eeprom(i);}break;
  case 36: for(i=145,j=0;j<4;i++,j++){dns[36][j]=read_eeprom(i);}break;
  case 37: for(i=149,j=0;j<4;i++,j++){dns[37][j]=read_eeprom(i);}break;
  case 38: for(i=153,j=0;j<4;i++,j++){dns[38][j]=read_eeprom(i);}break;
  case 39: for(i=157,j=0;j<4;i++,j++){dns[39][j]=read_eeprom(i);}break;
  case 40: for(i=161,j=0;j<4;i++,j++){dns[40][j]=read_eeprom(i);}break;
  case 41: for(i=165,j=0;j<4;i++,j++){dns[41][j]=read_eeprom(i);}break;
  case 42: for(i=169,j=0;j<4;i++,j++){dns[42][j]=read_eeprom(i);}break;
  case 43: for(i=173,j=0;j<4;i++,j++){dns[43][j]=read_eeprom(i);}break;
  case 44: for(i=177,j=0;j<4;i++,j++){dns[44][j]=read_eeprom(i);}break;
  case 45: for(i=181,j=0;j<4;i++,j++){dns[45][j]=read_eeprom(i);}break;
  case 46: for(i=185,j=0;j<4;i++,j++){dns[46][j]=read_eeprom(i);}break;
  case 47: for(i=189,j=0;j<4;i++,j++){dns[47][j]=read_eeprom(i);}break;
  case 48: for(i=193,j=0;j<4;i++,j++){dns[48][j]=read_eeprom(i);}break;
  case 49: for(i=197,j=0;j<4;i++,j++){dns[49][j]=read_eeprom(i);}break;
  case 50: for(i=201,j=0;j<4;i++,j++){dns[50][j]=read_eeprom(i);}break;
  case 51: for(i=205,j=0;j<4;i++,j++){dns[51][j]=read_eeprom(i);}break;
  case 52: for(i=209,j=0;j<4;i++,j++){dns[52][j]=read_eeprom(i);}break;
  case 53: for(i=213,j=0;j<4;i++,j++){dns[53][j]=read_eeprom(i);}break;
  case 54: for(i=217,j=0;j<4;i++,j++){dns[54][j]=read_eeprom(i);}break;
  case 55: for(i=221,j=0;j<4;i++,j++){dns[55][j]=read_eeprom(i);}break;
  case 56: for(i=225,j=0;j<4;i++,j++){dns[56][j]=read_eeprom(i);}break;
  case 57: for(i=229,j=0;j<4;i++,j++){dns[57][j]=read_eeprom(i);}break;
  case 58: for(i=233,j=0;j<4;i++,j++){dns[58][j]=read_eeprom(i);}break;
  case 59: for(i=237,j=0;j<4;i++,j++){dns[59][j]=read_eeprom(i);}break;
  case 60: for(i=241,j=0;j<4;i++,j++){dns[60][j]=read_eeprom(i);}break;
  case 61: for(i=245,j=0;j<4;i++,j++){dns[61][j]=read_eeprom(i);}break;
  case 62: for(i=249,j=0;j<4;i++,j++){dns[62][j]=read_eeprom(i);}break;
  case 63: for(i=253,j=0;j<4;i++,j++){dns[63][j]=read_eeprom(i);}break;
  case 64: for(i=257,j=0;j<4;i++,j++){dns[64][j]=read_eeprom(i);}break;
  case 65: for(i=261,j=0;j<4;i++,j++){dns[65][j]=read_eeprom(i);}break;
  case 66: for(i=265,j=0;j<4;i++,j++){dns[66][j]=read_eeprom(i);}break;
  case 67: for(i=269,j=0;j<4;i++,j++){dns[67][j]=read_eeprom(i);}break;
  case 68: for(i=273,j=0;j<4;i++,j++){dns[68][j]=read_eeprom(i);}break;
  case 69: for(i=277,j=0;j<4;i++,j++){dns[69][j]=read_eeprom(i);}break;
  case 70: for(i=281,j=0;j<4;i++,j++){dns[70][j]=read_eeprom(i);}break;
  case 71: for(i=285,j=0;j<4;i++,j++){dns[71][j]=read_eeprom(i);}break;
  case 72: for(i=289,j=0;j<4;i++,j++){dns[72][j]=read_eeprom(i);}break;
  case 73: for(i=293,j=0;j<4;i++,j++){dns[73][j]=read_eeprom(i);}break;
  case 74: for(i=297,j=0;j<4;i++,j++){dns[74][j]=read_eeprom(i);}break;
  case 75: for(i=301,j=0;j<4;i++,j++){dns[75][j]=read_eeprom(i);}break;
  case 76: for(i=305,j=0;j<4;i++,j++){dns[76][j]=read_eeprom(i);}break;
  case 77: for(i=309,j=0;j<4;i++,j++){dns[77][j]=read_eeprom(i);}break;
  case 78: for(i=313,j=0;j<4;i++,j++){dns[78][j]=read_eeprom(i);}break;
  case 79: for(i=317,j=0;j<4;i++,j++){dns[79][j]=read_eeprom(i);}break;
  case 80: for(i=321,j=0;j<4;i++,j++){dns[80][j]=read_eeprom(i);}break;
  case 81: for(i=325,j=0;j<4;i++,j++){dns[81][j]=read_eeprom(i);}break;
  case 82: for(i=329,j=0;j<4;i++,j++){dns[82][j]=read_eeprom(i);}break;
  case 83: for(i=333,j=0;j<4;i++,j++){dns[83][j]=read_eeprom(i);}break;
  case 84: for(i=337,j=0;j<4;i++,j++){dns[84][j]=read_eeprom(i);}break;
  case 85: for(i=341,j=0;j<4;i++,j++){dns[85][j]=read_eeprom(i);}break;
  case 86: for(i=345,j=0;j<4;i++,j++){dns[86][j]=read_eeprom(i);}break;
  case 87: for(i=349,j=0;j<4;i++,j++){dns[87][j]=read_eeprom(i);}break;
  case 88: for(i=353,j=0;j<4;i++,j++){dns[88][j]=read_eeprom(i);}break;
  case 89: for(i=357,j=0;j<4;i++,j++){dns[89][j]=read_eeprom(i);}break;
  case 90: for(i=361,j=0;j<4;i++,j++){dns[90][j]=read_eeprom(i);}break;
  case 91: for(i=365,j=0;j<4;i++,j++){dns[91][j]=read_eeprom(i);}break;
  case 92: for(i=369,j=0;j<4;i++,j++){dns[92][j]=read_eeprom(i);}break;
  case 93: for(i=373,j=0;j<4;i++,j++){dns[93][j]=read_eeprom(i);}break;
  case 94: for(i=377,j=0;j<4;i++,j++){dns[94][j]=read_eeprom(i);}break;
  case 95: for(i=381,j=0;j<4;i++,j++){dns[95][j]=read_eeprom(i);}break;
  case 96: for(i=385,j=0;j<4;i++,j++){dns[96][j]=read_eeprom(i);}break;
  case 97: for(i=389,j=0;j<4;i++,j++){dns[97][j]=read_eeprom(i);}break;
  case 98: for(i=393,j=0;j<4;i++,j++){dns[98][j]=read_eeprom(i);}break;
  case 99: for(i=397,j=0;j<4;i++,j++){dns[99][j]=read_eeprom(i);}break;
  }}
  

#int_EXT
void  EXT_isr(void) 
{

//while(true){ tus=tusal(input_c());lcd_komut(sil);printf(lcd_veri,"TUÞ DEÐERÝ=%d",tus);delay_ms(1000);}

      while(input(bak));
      lcd_komut(sil);
      tus=tusal(input_c());
      if(tus==10){goto adminn;}
      else if (tus==15){goto kullanici;}
      else goto bitir;

      
      adminn:
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"    YÖNETiCi        ");imlec(2,1);printf(lcd_veri" ÞiFRESiNi GiR   ");
      while(0==input(bak));while(input(bak));
      lcd_komut(sil);imlec(1,1);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"ÞiFRE:");
      for(i=0;i<k;i++)//admin þifre giriþi
      {tus=tusal(input_c());
      imlec(1,(i+7));printf(lcd_veri,"%d",tus);
      if(tus==10||tus==11||tus==12||tus==13||tus==14||tus==15){goto uyari;}
      al[i]=tus;
      if(i<=(k-2)){while(0==input(bak));while(input(bak));}
      }delay_ms(1000);
      
      if(al[0]==admin[0]&&al[1]==admin[1]&&al[2]==admin[2]&&al[3]==admin[3])//þifre kontrol      
      {
      lcd_komut(sil);imlec(1,1);printf(lcd_veri,"ÞiFRE ATA = B   ");imlec(2,1);printf(lcd_veri,"ÞiFRE SiL = D   ");
      }
      else{
      lcd_komut(sil);imlec(1,1);printf(lcd_veri," GiRiLEN ÞiFRE   ");imlec(2,1);printf(lcd_veri,"     HATALI          ");delay_ms(2000);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"     TEKRAR        ");imlec(2,1);printf(lcd_veri"   DENEYiNiZ     ");delay_ms(1000);goto bitir;
      }
      
      while(0==input(bak));while(input(bak));
      tus=tusal(input_c());
      if(tus==0||tus==1||tus==2||tus==3||tus==4||tus==5||tus==6||tus==7||tus==8||tus==9||tus==10||tus==12||tus==14||tus==15){goto uyari;}
      else if(tus==11){goto sifreata;}//þifre ata
      else goto sifresil;
      /////////////////////
      sifreata:
      daire[0]=daireno;
      
      lcd_komut(sil);imlec(2,1);printf(lcd_veri"ÞiFRE:");
      
      for(i=0;i<4;i++)
      {
      while(0==input(bak));while(input(bak));
      tus=tusal(input_c());
      dairesifre[i]=tus;
      imlec(2,(i+7));printf(lcd_veri,"%d",tus);
      }
      for(i=0;i<4;i++)//þifre doðruluk kontrolü
      {
      if(dairesifre[i]==10||dairesifre[i]==11||dairesifre[i]==12||dairesifre[i]==13||dairesifre[i]==14||dairesifre[i]==15)
      {lcd_komut(sil);imlec(1,1);printf(lcd_veri"ÞiFRE SADACE    ");imlec(2,1);printf(lcd_veri"SAYI OLMALIDIR  ");delay_ms(3000);
       lcd_komut(sil);imlec(1,1);printf(lcd_veri"    TEKRAR          ");imlec(2,1);printf(lcd_veri"   DENEYiNiZ       ");delay_ms(2000);goto bitir;
      }}     
      for(daireno,i=0;i<4;i++)
      {
      dns[daireno][i]=dairesifre[i];
      }
      delay_ms(1000);
      eepromyaz(daireno);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"   ÞiFRE VERME  ");imlec(2,1);printf(lcd_veri"    BAÞARILI    ");delay_ms(2000);
      
      
      goto bitir;
      ///////////////////////////
      sifresil:      
      lcd_komut(sil);imlec(1,1);printf(lcd_veri" ONAYLAMAK ÝÇÝN ");imlec(2,1);printf(lcd_veri"TEKRAR D BASINIZ    ");
      daire[0]=daireno;
      while(0==input(bak));while(input(bak));
      tus=tusal(input_c());
      if(tus==0||tus==1||tus==2||tus==3||tus==4||tus==5||tus==6||tus==7||tus==8||tus==9||tus==10||tus==11||tus==12||tus==14||tus==15){goto uyari;}
  
      eepromsil(daireno);
      lcd_komut(sil);imlec(2,1);printf(lcd_veri" ÞiFRE SiLiNDi  ");delay_ms(2000);
      
      goto bitir;
      ////////////////////////////////
      kullanici:
      if(dns[daireno][0]==0 && dns[daireno][1]==0 && dns[daireno][2]==0 && dns[daireno][3]==0)
      {
      lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"  ÞÝFRE   ");
      imlec(2,1);printf(lcd_veri"   BULUNAMADI    ");delay_ms(2000);
      lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"   YÖNETiCiYE   ");
      imlec(2,1);printf(lcd_veri"   BAÞVURUNUZ   ");delay_ms(2000);goto bitir;
      }
      
      imlec(2,1);printf(lcd_veri"ÞiFRE:");
      for(i=0;i<4;i++)
      {
      while(0==input(bak));while(input(bak));
      tus=tusal(input_c());
      dairesifre[i]=tus;
      imlec(2,(i+7));printf(lcd_veri"*");
      }
      for(i=0;i<4;i++)//þifre doðruluk kontrolü
      {
      if(dairesifre[i]==10||dairesifre[i]==11||dairesifre[i]==12||dairesifre[i]==13||dairesifre[i]==14||dairesifre[i]==15)
      {
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"ÞiFRE SADACE    ");imlec(2,1);printf(lcd_veri"SAYI OLMALIDIR  ");delay_ms(3000);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"     TEKRAR        ");imlec(2,1);printf(lcd_veri"   DENEYiNiZ     ");delay_ms(2000);goto bitir;}}
      
      if(dns[daireno][0]==dairesifre[0]&&dns[daireno][1]==dairesifre[1]&&dns[daireno][2]==dairesifre[2]&&dns[daireno][3]==dairesifre[3])
      {while(0==input(bak));while(input(bak));tus=tusal(input_c());}
      else {
      lcd_komut(sil);imlec(1,1);printf(lcd_veri" GiRiLEN ÞiFRE   ");imlec(2,1);printf(lcd_veri"    YANLIÞ        ");delay_ms(1000);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"     TEKRAR        ");imlec(2,1);printf(lcd_veri"   DENEYiNiZ     ");delay_ms(1000);
      
      goto bitir;
      }
      if(tus==0||tus==1||tus==2||tus==3||tus==4||tus==5||tus==6||tus==7||tus==8||tus==9||tus==10||tus==11||tus==12||tus==13||tus==14)
      {goto uyari;}
      else{
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"  KAPI ACILDI   ");
      output_high(pin_b1);
      output_high(pin_d6);
      for(i=0,j=3;i<4;i++,j--){imlec(2,1);printf(lcd_veri,"       %d        ",j);delay_ms(1000);}
      output_low(pin_b1);output_high(pin_d6);delay_ms(20);output_low(pin_d6);goto bitir;}
      
      //////////////////////////////////
      kapiac:
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"  KAPI ACILDI   ");
      output_high(pin_b1);
      output_high(pin_d6);
      for(i=0,j=3;i<4;i++,j--){imlec(2,1);printf(lcd_veri,"       %d        ",j);delay_ms(1000);}
      output_low(pin_b1);output_high(pin_d6);delay_ms(20);output_low(pin_d6);goto bitir;
      
      //////////////////////

      uyari:
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"  YANLIÞ TUÞA     ");imlec(2,1);printf(lcd_veri"   BASTINIZ        ");delay_ms(1000);
      lcd_komut(sil);imlec(1,1);printf(lcd_veri"    TEKRAR          ");imlec(2,1);printf(lcd_veri"   DENEYiNiZ       ");delay_ms(1000);
      
      
      bitir:
      lcd_komut(0x01); // LCD sýfýrlanýyor      
      
      //////////////////////
      
      
      }





void main()
{
   
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2|ADC_TAD_MUL_0);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_ccp1(CCP_OFF);
   setup_comparator(NC_NC_NC_NC);
   

   
   lcd_hazirla();  //lcd_komut(0x01);LCD sýfýrlanýyor    printf(lcd_veri,"YAZ"); imlec(1,1);
   ozel_karakterler();
   
   set_tris_b(0x01);   // RB0 pini giriþ,diðer uçlar çýkýþ olarak yönlendiriliyor
   output_b(0x00);     // B portu çýkýþý ilk anda sýfýrlanýyor
   set_tris_c(0xff);
   output_c(0x00);
   ext_int_edge(L_TO_H);   // INT_EXT kesmesinin düþen kenarda aktif olacaðýný belirtir
   

   
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   
   lcd_komut(0x01);
   
if(read_eeprom(500)==5){for(ee=0;ee<100;ee++){eepromoku(ee);}output_high(pin_b7);delay_ms(1000);output_low(pin_b7);}
else{for(ee=0;ee<101;ee++){eepromsil(ee);}write_eeprom(500,5);output_high(pin_b6);delay_ms(1000);output_low(pin_b6);}


 while(true)
   {  lcd_komut(0x01);
      imlec(2,1);printf(lcd_veri"     KAPIYI     ");delay_ms(1000);lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"     KAPIYI     ");            
      imlec(2,1);printf(lcd_veri"   ACMAK iCiN   ");delay_ms(1000);lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"   ACMAK iCiN   ");    
      imlec(2,1);printf(lcd_veri"   #  BASIP   ");delay_ms(1000);lcd_komut(sil);   
      imlec(1,1);printf(lcd_veri"   #  BASIP   ");       
      imlec(2,1);printf(lcd_veri"   ARDINDAN");delay_ms(1000);lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"   ARDINDAN   ");     
      imlec(2,1);printf(lcd_veri"ÞiFRENiZi GiRiP ");delay_ms(1000);lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"ÞiFRENiZi GiRiP ");  
      imlec(2,1);printf(lcd_veri"# TUÞUNA BASINIZ");delay_ms(1000);lcd_komut(sil);
      imlec(1,1);printf(lcd_veri"# TUÞUNA BASINIZ");delay_ms(1000);lcd_komut(sil);
   }

}
