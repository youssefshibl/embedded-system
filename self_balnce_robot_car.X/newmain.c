/**/


#include <xc.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include"config.h"
#include"pic18f8527.h"
//#include"lcd.h"
#define _XTAL_FREQ 8000000

/*
//Glcd module connections
sbit GLCD_D0 at RE0_bit;
sbit GLCD_D1 at RE1_bit;
sbit GLCD_D2 at RE2_bit;
sbit GLCD_D3 at RE3_bit;
sbit GLCD_D4 at RE4_bit;
sbit GLCD_D5 at RE5_bit;
sbit GLCD_D6 at RE6_bit;
sbit GLCD_D7 at RE7_bit;
sbit GLCD_D0_Direction at TRISE0_bit;
sbit GLCD_D1_Direction at TRISE1_bit;
sbit GLCD_D2_Direction at TRISE2_bit;
sbit GLCD_D3_Direction at TRISE3_bit;
sbit GLCD_D4_Direction at TRISE4_bit;
sbit GLCD_D5_Direction at TRISE5_bit;
sbit GLCD_D6_Direction at TRISE6_bit;
sbit GLCD_D7_Direction at TRISE7_bit;
sbit GLCD_CS1 at LATD8_bit;
sbit GLCD_CS2 at LATD9_bit;
sbit GLCD_RS  at LATD10_bit;
sbit GLCD_RW  at LATD1_bit;
sbit GLCD_EN  at LATD2_bit;
sbit GLCD_RST at LATD3_bit;
sbit GLCD_CS1_Direction at TRISD8_bit;
sbit GLCD_CS2_Direction at TRISD9_bit;
sbit GLCD_RS_Direction  at TRISD10_bit;
sbit GLCD_RW_Direction  at TRISD1_bit;
sbit GLCD_EN_Direction  at TRISD2_bit;
sbit GLCD_RST_Direction at TRISD3_bit;
// End Glcd module connections
*/

//LEDs connections
//#define STAT  RB6;
//#define STAT_Direction TRISB6;
//
//#define DATA RD6;
//#define DATA_Direction TRISD6;
//
////WIFI module reset connections
//#define wifi_reset RC1;
//#define wifi_reset_Direction TRISC1;



//----------[ MPU6050 Register Map ]-----------
#define XG_OFFS_TC         0x00
#define YG_OFFS_TC         0x01
#define ZG_OFFS_TC         0x02
#define X_FINE_GAIN        0x03
#define Y_FINE_GAIN        0x04
#define Z_FINE_GAIN        0x05
#define XA_OFFS_H          0x06
#define XA_OFFS_L_TC       0x07
#define YA_OFFS_H          0x08
#define YA_OFFS_L_TC       0x09
#define ZA_OFFS_H          0x0A
#define ZA_OFFS_L_TC       0x0B
#define XG_OFFS_USRH       0x13
#define XG_OFFS_USRL       0x14
#define YG_OFFS_USRH       0x15
#define YG_OFFS_USRL       0x16
#define ZG_OFFS_USRH       0x17
#define ZG_OFFS_USRL       0x18
#define SMPLRT_DIV         0x19
#define CONFIG             0x1A
#define GYRO_CONFIG        0x1B
#define ACCEL_CONFIG       0x1C
#define FF_THR             0x1D
#define FF_DUR             0x1E
#define MOT_THR            0x1F
#define MOT_DUR            0x20
#define ZRMOT_THR          0x21
#define ZRMOT_DUR          0x22
#define FIFO_EN            0x23
#define I2C_MST_CTRL       0x24
#define I2C_SLV0_ADDR      0x25
#define I2C_SLV0_REG       0x26
#define I2C_SLV0_CTRL      0x27
#define I2C_SLV1_ADDR      0x28
#define I2C_SLV1_REG       0x29
#define I2C_SLV1_CTRL      0x2A
#define I2C_SLV2_ADDR      0x2B
#define I2C_SLV2_REG       0x2C
#define I2C_SLV2_CTRL      0x2D
#define I2C_SLV3_ADDR      0x2E
#define I2C_SLV3_REG       0x2F
#define I2C_SLV3_CTRL      0x30
#define I2C_SLV4_ADDR      0x31
#define I2C_SLV4_REG       0x32
#define I2C_SLV4_DO        0x33
#define I2C_SLV4_CTRL      0x34
#define I2C_SLV4_DI        0x35
#define I2C_MST_STATUS     0x36
#define INT_PIN_CFG        0x37
#define INT_ENABLE         0x38
#define DMP_INT_STATUS     0x39
#define INT_STATUS         0x3A
#define ACCEL_XOUT_H       0x3B
#define ACCEL_XOUT_L       0x3C
#define ACCEL_YOUT_H       0x3D
#define ACCEL_YOUT_L       0x3E
#define ACCEL_ZOUT_H       0x3F
#define ACCEL_ZOUT_L       0x40
#define TEMP_OUT_H         0x41
#define TEMP_OUT_L         0x42
#define GYRO_XOUT_H        0x43
#define GYRO_XOUT_L        0x44
#define GYRO_YOUT_H        0x45
#define GYRO_YOUT_L        0x46
#define GYRO_ZOUT_H        0x47
#define GYRO_ZOUT_L        0x48
#define EXT_SENS_DATA_00   0x49
#define EXT_SENS_DATA_01   0x4A
#define EXT_SENS_DATA_02   0x4B
#define EXT_SENS_DATA_03   0x4C
#define EXT_SENS_DATA_04   0x4D
#define EXT_SENS_DATA_05   0x4E
#define EXT_SENS_DATA_06   0x4F
#define EXT_SENS_DATA_07   0x50
#define EXT_SENS_DATA_08   0x51
#define EXT_SENS_DATA_09   0x52
#define EXT_SENS_DATA_10   0x53
#define EXT_SENS_DATA_11   0x54
#define EXT_SENS_DATA_12   0x55
#define EXT_SENS_DATA_13   0x56
#define EXT_SENS_DATA_14   0x57
#define EXT_SENS_DATA_15   0x58
#define EXT_SENS_DATA_16   0x59
#define EXT_SENS_DATA_17   0x5A
#define EXT_SENS_DATA_18   0x5B
#define EXT_SENS_DATA_19   0x5C
#define EXT_SENS_DATA_20   0x5D
#define EXT_SENS_DATA_21   0x5E
#define EXT_SENS_DATA_22   0x5F
#define EXT_SENS_DATA_23   0x60
#define MOT_DETECT_STATUS  0x61
#define I2C_SLV0_DO        0x63 
#define I2C_SLV1_DO        0x64
#define I2C_SLV2_DO        0x65
#define I2C_SLV3_DO        0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET  0x68
#define MOT_DETECT_CTRL    0x69
#define USER_CTRL          0x6A
#define PWR_MGMT_1         0x6B
#define PWR_MGMT_2         0x6C
#define BANK_SEL           0x6D
#define MEM_START_ADDR     0x6E
#define MEM_R_W            0x6F
#define DMP_CFG_1          0x70
#define DMP_CFG_2          0x71
#define FIFO_COUNTH        0x72
#define FIFO_COUNTL        0x73
#define FIFO_R_W           0x74
#define WHO_AM_I           0x75


#define stat RF6
#define stat_direction TRISF6
#define data RF6
#define data_direction TRISF6
#define wifi_reset RC1
#define wifi_reset_direction TRISC1



#define Baud_Rate 9600
#define fosc 8*10^6
#define _XTAL_FREQ 8000000
#define I2C_BaudRate 100000 // I2C Baud Rate = 100 Kbps



//wifi connections settings
const char *SSID = "joo";
const char *password = "0123456789";
const char port[] = "80";
char code[]="<h1>Hello</h1><h2>SAMEER</h2>";

//some AT commands constants
const char AT_RST[] = "AT+RST";
const char AT_CWMODE[] = "AT+CWMODE=";
const char AT_CWJAP[] = "AT+CWJAP=";
const char AT_CWLAP[] = "AT+CWLAP";
const char AT_CWQAP[] = "AT+CWQAP";
const char AT_CWSAP[] = "AT+CWSAP=";
const char AT_CIPSTATUS[] = "AT+CIPSTATUS";
const char AT_CIPSTART[] = "AT+CIPSTART=";
const char AT_CIPCLOSE[] = "AT+CIPCLOSE=";
const char AT_CIFSR[] = "AT+CIFSR";
const char AT_CIPMUX[] = "AT+CIPMUX=";
const char AT_CIPSERVER[] = "AT+CIPSERVER=";


//responose variabales
const char OK = 1;
const char ready = 2;
const char no_change = 3;
const char send_ready = 4;


#define CR  0x0D  //CR carriage return
#define LF  0x0A  //LF line feed(new line)

char rx_buff[500]; //stores DATA read
char data_ready;  //will be set if DATA is ready in buffer
unsigned int data_len; //determines the length of buffer
char tmp;   //tmp will store temprory received DATA(byte)
char APIP[30]; //stores APIP
char APMAC[30]; //stores APMAC
char STAIP[30]; //stores STAIP
char STAMAC[30]; //stores STAMAC

char send_command[20];  //stores texts to be sent
char close_command[20];  //stores texts to be sent
char connection_id[6];  //stores connection id number

unsigned int adc_value; //stores adc value
char adc_value_text[6];  //stores adc value converted to string
unsigned int size_data;  //stores size of the DATA to be sent
char size_data_text[6];



char webpage_text1[]="<h1>";
char webpage_text2[]="</h1>";
char counter_text[]="1251";



void uart_init(void);
void check_webpage_request_2(void);
void get_sending_command(char *connection_id, unsigned int send_data_size, char *send_command);
void send_data_direct(char *data_1,int stat,char *id_str);


void uart_char_write(char data){
    uart_init();
    
    TXREG = data;
    while(!TRMT){
    
    
    }
    SPEN = 0;
}

void uart_text_write(char *data){
    int i;
    i=0;
    do{
    //uart_init();  
    TXREG = data[i];
    while(!TRMT){    
    }
    i++;
    
    
    }while(data[i]!='\0');
    
    SPEN = 0;

}

int uart_read_int(void){

BRGH = 1;  
SPBRG = 51;
SYNC = 0;
SPEN = 1;
TRISC6 = 1;  
TRISC7 = 1;
RCIE = 1;  
PEIE = 1;  
GIE = 1; 
CREN = 1;

}



//connect to phone using TCP----------------------------------------------------
//AT+CIPSTART="TCP","SERVER IP",PORT\r\n
//char tcp_command_config[] = "AT+CIPSTART=\"TCP\",\"192.168.1.7\",6000\r\n";
char tcp_web[]="AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n";

//------------------------------------------------------------------------------


//Timer2/3
//Prescaler 1:1; PR3 Preload = 2441; PR2 Preload = 29065; Actual Interrupt Time = 2s

/*
void InitTimer2_3(){
  T2CON        = 0x8008;
  T3CON        = 0x0;
  TMR2         = 0;
  TMR3         = 0;
  T3IE_bit     = 0;
  T3IF_bit     = 0;
  T3IP0_bit    = 1;
  T3IP1_bit    = 1;
  T3IP2_bit    = 1;
  PR2          = 26624;
  PR3          = 2441;
}

*/
/*
//this fucntion will enable the timer
void on_timer()
{
  T3IE_bit = 1;
}
*/


//initiallizations of uart interrupt
void uart_init(void){
    
  BRGH = 1; // Set For High-Speed Baud Rate
  SPBRG = 51; // Set The Baud Rate To Be 9600 bps
  //--[ Enable The Ascynchronous Serial Port ]--
  SYNC = 0;
  SPEN = 1;
  //--[ Set The RX-TX Pins to be in UART mode (not io) ]--
  TRISC6 = 1;  // As stated in the datasheet
  TRISC7 = 1;  // As stated in the datasheet
  TXEN = 1; // Enable UART Transmission
 
}



//initiallizations
void config()
{
  //AD1PCFG = 0xFFFE; //AN0 as analog
    PCFG0=0 ; PCFG1=1 ; PCFG2=1; PCFG3=0;
    
  TRISB0 = 1; //AN0 as input
  
  //Glcd_Init();   // Initialize GLCD
  //Glcd_Fill(0x00); // Clear GLCD
  //Glcd_Write_Text("WELCOME", 1, 0, 1);
  //Glcd_Write_Text("SAMEER", 1, 3, 1);
  //delay_ms(500);
  //Glcd_Fill(0x00); // Clear GLCD
  
  
  stat_direction=0; // set direction STAT PIN to be output
  stat=0;  // turn OFF STAT LED

  data_direction = 0; // set direction DATA PIN to be output
  data=0;  // turn OFF DATA LED PIN
  
  stat = 1; data =1;
  __delay_ms(500);
  stat = 0; data =0;
  
  //wifi reset pin as output
  wifi_reset_direction = 0; 
  wifi_reset = 0;
  
    
    __delay_ms(500);
   
  //configure uart and timer2_3 interrupts
  uart_init();
  //InitTimer2_3();
  //enableinterrupts();
}

//this function will send passed DATA using uart then send NL and CR
void UART_Write_AT(char *_data)
{
   uart_text_write(_data);
   uart_char_write(0x0D);
   uart_char_write(0x0A);
}

//this function will send passed constant DATA using uart
void uart_write_data_const(const char *_data)
{
  while(*_data)
  {
     uart_char_write(*_data++);
  }
}
//this function will send passed DATA using uart
void uart_write_data(char *_data)
{
  while(*_data)
  {
     uart_char_write(*_data++);
  }
}

//this function will send CR and LF
void new_line()
{
   uart_char_write(0x0D);
   uart_char_write(0x0A);
}

//this function resets buffer and variables used with buffer
void reset_buff() 
{
  memset(rx_buff,0,data_len); //reset buffer from first index to length used

  //reset variables used with buffer
  data_ready = 0;
  data_len=0;
}

//Reset WiFi module using Reset PIN
void reset_wifi()
{
    wifi_reset= 0;
  
  __delay_ms(500);
  
  wifi_reset = 0;
}


//this function will search for a text in string, return 1 if found and 0 if not found
char find_string(char *string, char *string_find)
{
    unsigned int mathced = 0; //will be incremented in each matching char
    unsigned int index_string = 0; //index of string source
    unsigned int length_of_string=0; //length of string source
    unsigned int length_of_string_find=0; //length of the text to be found

    length_of_string = strlen(string); //get length of string source
    length_of_string_find = strlen(string_find); //get length of the text to be found

    //return 0 if string find size is greater than string source
    if(length_of_string_find > length_of_string)
    {
        return 0;
    }

    for(index_string=0; index_string < length_of_string; index_string++) //iterate until length of string source
    {
        if(string[index_string] == string_find[mathced]) //if current char is mathcing
        {
            mathced++; //increment mathced in each matching char
            if(length_of_string_find == mathced) //if found equals the size of string find
            {
              return 1; //return 1 because string is found
            }
        }
        else //otherwise reset mathced
        {
            mathced = 0;
        }
    }

    return 0;  //return 0 if string is not found in string source
}

//this fucntion will copy text between two strings
void find_get_string(char *string, char *from, char _from, char *to, char _to, char *get_text)
{
     char *p1; //pointer to string elements
     char *p2; //pointer to string find(from) elements in string
     char length=0; //gets the length between the two strings

    /*
      get the location of the first occurance of string 1 in memory
      so the location of the first value is returned.
      add a number(_from) to point p1 next to any value from the first occurance location
      value. so p1 is a pointer in memory to the location of first occurance of
      string 1.
    */
    p1 = strstr(string, from) + _from;


    /*
       get the location of the first occurance of string 2 in memory
       when sending the value of p1 the search will start from the value of
       p1 until it finds the location of the first occurance of the string 2
       in memory. so the location of the first value + _to is returned.
    */
    p2 = strstr(p1, to) + _to;

    /*
      get how many characters in between
    */
    length = p2 - p1;

    /*
       copy the found characters, from p1 to number of char found in between
       last char in found char as null
    */
    strncpy(get_text, p1, length);
    get_text[length] = '\0';
}

//this function gets the response from the module and return its value
char response_success()
{
    
   // clear_lcd();
  char result; //will store 1 if success response is found other wise 0
  uart_read_int();
  while(!data_ready){
  }; //waite until DATA buffer is ready
  
  if(find_string(rx_buff,"ok") == 1){result = OK;} //if "OK" is found in buffer
  else if(find_string(rx_buff,"no change") == 1){result = no_change;}//if "no change" is found
  else if(find_string(rx_buff,"ready") == 1){result = ready;}//if "ready" is found
  else if(find_string(rx_buff,">") == 1){result = send_ready;}  //ready to receive DATA ">"
  else result = 0; //else if other is found maybe "ERROR" or "FAIL" etc, result will be no success

  reset_buff(); //reset buffer

  return result;  //return the result of the response
}

//this function will get the IP and MAC address of the module
void Get_IP_MAC()
{
   //glcd_fill(0x00);
   //Glcd_Write_Text("Getting IP Address", 1, 1, 1);
   //Glcd_Write_Text("And MAC Address", 1, 2, 1);
   //Glcd_Write_Text("Please wait...", 1, 3, 1);
   UART_Write_AT("AT+CIFSR"); //send get IP and MAC address command
   uart_read_int();
   while(!data_ready){}; //if DATA is not ready(line feed not found) stay here
   reset_buff(); //reset first read buffer
   while(!data_ready){}; //again if DATA is not ready(line feed not found) stay here

   __delay_ms(500);  //wait for the buffer to fill up

   //glcd_fill(0x00);//clear screen

   //get APIP from buffer read
   //Glcd_Write_text("APIP=", 1, 1, 1);
   //this will get  APIP, APMAC, STAIP and STAMAC from request_string_2
   find_get_string(rx_buff, "APIP,\"", 6, "\"", 0, APIP);
   //Glcd_Write_text(APIP, 35, 1, 1); //display APIP

   //get APMAC from buffer read
   //Glcd_Write_text("APMAC=", 1, 2, 1);
   find_get_string(rx_buff, "APMAC,\"", 7, "\"", 0, APMAC);
   //Glcd_Write_text(APMAC, 1, 3, 1); //display APMAC

   //get STAIP from buffer read
   //Glcd_Write_text("STAIP=", 1, 4, 1);
   find_get_string(rx_buff, "STAIP,\"", 7, "\"", 0, STAIP);
   //Glcd_Write_text(STAIP, 35, 4, 1); //display STAIP

   //get STAMAC from buffer read
   //Glcd_Write_text("STAMAC=", 1, 5, 1);
   find_get_string(rx_buff, "STAMAC,\"", 8, "\"", 0, STAMAC);
   //Glcd_Write_text(STAMAC, 1, 6, 1); //display STAMAC

   //reset buffer
   reset_buff();
}


void disconnect_ap(void){
//Disconnect from any AP at the beginning
   //glcd_fill(0x00);
   //Glcd_Write_Text("Disconnecting WIFI", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   UART_Write_AT("AT+CWQAP");   //Disconnect from any AP at the beginning
   while(response_success() != OK){ }; //wait until response success is found
   __delay_ms(1000);

}

void ap_and_station_mode(void){
//change the working mode to both station mode and Ap
   //glcd_fill(0x00);
   //Glcd_Write_Text("Setting mode", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   UART_Write_AT("AT+CWMODE=3");   //select both station and access point mode
   while(response_success() != OK);   //wait until response success is found
   __delay_ms(1000);
   
}


void single_conection(void){
//Enable multiple or single connections
   //glcd_fill(0x00);
   //Glcd_Write_Text("Setting connection", 1, 0, 1);
   //Glcd_Write_Text("mode", 1, 1, 1);
   //Glcd_Write_Text("Please wait...", 1, 2, 1);
   UART_Write_AT("AT+CIPMUX=0");  //Enable single connection
   while(response_success() != OK); //wait until response success is found
   __delay_ms(1000);
}

void mult_connection(void){
//Enable multiple or single connections
   //glcd_fill(0x00);
   //Glcd_Write_Text("Setting connection", 1, 0, 1);
   //Glcd_Write_Text("mode", 1, 1, 1);
   //Glcd_Write_Text("Please wait...", 1, 2, 1);
   UART_Write_AT("AT+CIPMUX=1");  //Enable single connection
   while(response_success() != OK); //wait until response success is found
   __delay_ms(1000);

}

void connected_to_ap(void){
    
    
    
while(1)
   {
     //glcd_fill(0x00);
     //Glcd_Write_Text("Connecting to AP", 1, 0, 1);
     //Glcd_Write_Text("Please wait...", 1, 1, 1);
     //uart_text_write("AT+CWJAP=");
      UART_Write_AT("AT+CWJAP=");
     uart_char_write('"');
     uart_text_write(SSID);
     uart_char_write('"');
     uart_char_write(',');
     uart_char_write('"');
     uart_text_write(password);
     uart_char_write('"');
     new_line();
     if(response_success() == OK) //if response success is found
     {
       //Glcd_Write_Text("Success", 1, 2, 1);
       break;
     }
     else //if response success is not found
     {
       //Glcd_Write_Text("Try again...", 1, 2, 1);
       __delay_ms(500);
     }
   }

}

void check_connected_ap(void){

//test if wifi module was connected to an access point
   //glcd_fill(0x00);
   //Glcd_Write_Text("Check connection", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   UART_Write_AT("AT+CWJAP=?");   //check if module is connected to AP
   while(response_success() != OK){};  //wait until response success is found
   //Glcd_Write_Text("WiFi Module Connected", 1, 2, 1);
   
   
}

void config_server(void){
   //glcd_fill(0x00);
   //Glcd_Write_Text("Configure TCP server", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   uart_text_write("AT+CIPSERVER=1"); //Configure TCP server command
   uart_char_write(',');
   uart_text_write(port);
   uart_char_write(CR);
   uart_char_write(LF);
   while(response_success() != OK){}; //wait until response success is found
   reset_buff();
}


void check_webpage_request()
{
    //lcd_write_text(0,0,"web");
    __delay_ms(1000);
  if(data_ready) //if there is DATA to be read
  {
     if(find_string(rx_buff, "ok") == 1) //if wepage request is found
     {
         //send the channel and length of DATA to be sent
         UART_Write_AT("AT+CIPSEND=0,29");
          while(response_success() != OK){};
         __delay_ms(1000);
         //reset_buff();

         //send the webpage
         
         
         UART_Write_AT(code);
         __delay_ms(1000);
         //reset_buff();

         //close connection with the channel
         UART_Write_AT("AT+CIPCLOSE=0");
         __delay_ms(1000);
         reset_buff();
     }
  }
}


//this fucntion configures the wifi module
void WiFi_Config()
{
   //reset variables
   data_ready = 0;
   data_len = 0;
   memset(rx_buff,0,500); //reset buffer, put 0 to all element of buffer
  
   //Resetting WIFI module
   //glcd_fill(0x00);
   //Glcd_Write_Text("Resetting WIFI", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   //UART_Write_AT("AT+RST");   //Reset WiFi module using uart
   reset_wifi(); //Reset WiFi module using PIN
   while(response_success() != ready){}; //wait until response success is found
   __delay_ms(1000);
   
   
   //send AT
   //glcd_fill(0x00);
   //Glcd_Write_Text("Sending AT", 1, 0, 1);
   //Glcd_Write_Text("Please wait...", 1, 1, 1);
   UART_Write_AT("AT");   //send AT
   while(response_success() != OK){}; //wait until response success is found
   
   
   //Disconnect from any AP at the beginning
  disconnect_ap();
  __delay_ms(500);
  ap_and_station_mode();
  __delay_ms(500);
   mult_connection();
  
   //infinit loop to join access point
   __delay_ms(500);
   connected_to_ap();
   __delay_ms(500);

   //test if wifi module was connected to an access point
   check_connected_ap();
   
   
   

__delay_ms(500);
   
    



    
   reset_buff(); //reset first read buffer
     //Get IP and MAC address
}

//uart interrup handler when data received

void interrupt ISR(void){
    if(RCIF == 1){
        tmp=RCREG;
        switch(tmp){
            case LF:
                if(data_len>1){
                    data_ready=1;
                }
                break;
            case CR:
                rx_buff[data_len]=0;
                break;
            default:
                rx_buff[data_len]=tmp;
                data_len++;
        
        }
        RCIF=0;
        
    
    }

}

//timer  Timer2_3 ISR
/*
void Timer2_3Interrupt() iv IVT_TIMER_3 ilevel 7 ics ICS_SRS{
  
  disableinterrupts();
  adc_value = ADC1_Read(0);  //read analog value from channel 0
  wordtostr(adc_value,adc_value_text);  //convert adc value to string
  ltrim(adc_value_text); //remove leading space of adc value

  //display adc value
  glcd_write_text("          ", 100,0,1);
  glcd_write_text(adc_value_text, 100,0,1);

  STAT = ~STAT; //toggle LED

  T3IF_bit = 0; //reset timer flag
  enableinterrupts();
}


//this function creates the sending command for multiple connection mode
void get_sending_command(char *connection_id, unsigned int send_data_size, char *send_command)
{
   char _send_data_size[10];  //stores number converted to string

   wordtostr(send_data_size,_send_data_size);
   ltrim(_send_data_size);
   
   //get sending command : "AT+CIPSEND = connection_id , _size_send_data
   strcpy(send_command, "AT+CIPSEND=");
   strcat(send_command,connection_id);
   strcat(send_command,",");
   strcat(send_command,_send_data_size);
}

*/
//get size of DATA to be sent(HTML code + adc value)
     
    
unsigned int get_size_data(void)
{
   unsigned int size_data;

   //get size of DATA to be sent
   size_data  =  strlen(webpage_text1);
   size_data +=  strlen(adc_value_text);
   size_data +=  strlen(webpage_text2);

   return size_data;
}


//this funtion checks for webpage request to serve it
/*
void check_webpage_request()
{
  if(data_ready) //if there is DATA to be read
  {
     if(find_string(rx_buff, "+IPD") == 1) //if wepage request is found
     {

     }
  }
}
*/



//this function sends adc value

void send_adc_value(void)
{
   //connect to phone using TCP
   //uart_text_write(tcp_command_config);
   __delay_ms(2000);
   reset_buff(); //reset first read buffer

   //get the size of the get request
   size_data = strlen(adc_value_text);
   //wordtostr(size_data,size_data_text);
   sprintf(size_data_text, "%u", size_data);
   //ltrim(size_data_text);


   //create the sending command
   strcpy(send_command, "AT+CIPSEND=");
   strcat(send_command, size_data_text);
   strcat(send_command, "\r\n");

   //send the sending command
   uart_text_write(send_command);
   __delay_ms(2000);
   reset_buff(); //reset first read buffer
   
   //send the adc value
   uart_text_write(adc_value_text);
   __delay_ms(2000);
   reset_buff(); //reset first read buffer


   //close the connection
   uart_text_write("AT+CIPCLOSE\r\n");
   __delay_ms(2000);
   reset_buff(); //reset first read buffer
}


 //this when you want send variable text to website
 

void check_webpage_request_2(void)
{
  if(data_ready) //if there is DATA to be read
  {
     if(find_string(rx_buff, "+IPD") == 1) //if wepage request is found
     {
        __delay_ms(500); //wait before getting connection id.

        //get connection id from request string
        find_get_string(rx_buff, "+IPD,", 5, ",", 0, connection_id);

        size_data = get_size_data(); //get size of DATA to be sent
        
        //sending command
        get_sending_command(connection_id, size_data, send_command);
        UART_Write_AT(send_command);
        __delay_ms(1000);
        while(response_success() != OK){}; //wait for response
        reset_buff();

        //send the webpage counter VALUE
        uart_write_data_const(webpage_text1); //send first part
        uart_text_write(counter_text); //send second part
        uart_write_data_const(webpage_text2); //send last part
        new_line();
        __delay_ms(1000);
        while(response_success() != OK){}; //wait for response
        reset_buff();

        //close connected channel
        strcpy(close_command, "AT+CIPCLOSE=");
        strcat(close_command,connection_id);
        UART_Write_AT(close_command);  //close the connection
        __delay_ms(1000);
        while(response_success() != OK);{} //wait for response
        memset(connection_id,0,6);
        reset_buff();
     }
  }
}

void get_sending_command(char *connection_id, unsigned int send_data_size, char *send_command)
{
   char _send_data_size[10];  //stores number converted to string

   //wordtostr(send_data_size,_send_data_size);
   sprintf(_send_data_size, "%u", send_data_size);
   //ltrim(_send_data_size);

   //get sending command : "AT+CIPSEND = connection_id , _size_send_data
   strcpy(send_command, "AT+CIPSEND=");
   strcat(send_command,connection_id);
   strcat(send_command,",");
   strcat(send_command,_send_data_size);
}

void check_ok(void){
while(response_success() != OK){

};
}

void send_data_when_ordered(char *data_1){
char connection_id_[6];


   if(data_ready) //if there is DATA to be read
  {
     if(find_string(rx_buff, "+IPD") == 1) //if wepage request is found
     { 
         
         find_get_string(rx_buff, "+IPD,", 5, ",", 0, connection_id_);
         send_data_direct(data_1,1,connection_id_);
     }
     
   }

}

// if single connected state will be 0 if multi connected state will be 1 //
void send_data_direct(char *data_1,int stat,char *id_str){
unsigned int size_data_num;
char *size_data_text_num;
char send_command_1[];
char closed_data[];
reset_buff();
size_data_num = strlen(data_1);
sprintf(size_data_text_num, "%u", size_data_num);

if(stat==0){
   strcpy(send_command_1, "AT+CIPSEND=");
   strcat(send_command_1,size_data_text_num);
   strcat(send_command_1, "\r\n");
}
if(stat==1){
   strcpy(send_command_1, "AT+CIPSEND=");
   strcat(send_command_1,id_str);
   strcat(send_command_1,",");
   strcat(send_command_1,size_data_text_num);
   strcat(send_command_1, "\r\n");

}

uart_text_write(send_command_1);
check_ok();
reset_buff();
__delay_ms(500);
uart_text_write(data_1);
new_line();
__delay_ms(500);

//while(response_success() != OK){}; //wait for response
//reset_buff();
//if(stat==1){
//        strcpy(closed_data, "AT+CIPCLOSE=");
//        strcat(closed_data,id_str);
//        UART_Write_AT(closed_data);  //close the connection
//        __delay_ms(500);
//        while(response_success() != OK);{} //wait for response
//       // memset(connection_id,0,6);
//        reset_buff();
//
//}
//if(stat==0){
//
//        strcpy(closed_data, "AT+CIPCLOSE");
//       // strcat(closed_data,id_str);
//        UART_Write_AT(closed_data);  //close the connection
//        __delay_ms(500);
//        while(response_success() != OK);{} //wait for response
//       // memset(connection_id,0,6);
//        reset_buff();
//}



}

void connected_to_thingspeak(void){

uart_text_write(tcp_web);
__delay_ms(1000);


}


int send_req_data(void){
    char data_of_direction[10];
    char id_[]="1281214";
    int direction_;
    char link_req[]="https://api.thingspeak.com/channels/1281214/feeds.json?api_key=XLPIDXXIISTJS78Z&results=1";
    reset_buff();
    send_data_direct( link_req ,1 ,id_);
    __delay_ms(50);
    find_get_string(rx_buff, "dir8_", 5, "_", 0,data_of_direction);
    if(find_string(data_of_direction,"up")==1){
    
        direction_=1;    
    }
    else if(find_string(data_of_direction,"down")==1){
        direction_=2; 
    }
    else if(find_string(data_of_direction,"right")==1){
        direction_=3; 
    }
    else if(find_string(data_of_direction,"left")==1){
        direction_=4; 
    }else{
        direction_=0; 
    }
    reset_buff();
    return (direction_);
}

void do_move(int dir){
    
    int i;
    i=0;
    switch(dir){
        case 1:
            RE7=1;
            RH7=1;
           while(i>200){
               i++;
               RE5=1;
               RH5=1;
               __delay_us(500);
               RE5=0;
               RH5=0;
               __delay_us(500);
                         
           } 
            i=0;
        case 2:
            
            RE7=0;
            RH7=0;
            
           while(i>200){
               i++;
               RE5=1;
               RH5=1;
               __delay_us(500);
               RE5=0;
               RH5=0;
               __delay_us(500);
                         
           } 
            i=0;
        case 3:
            RE7=1;
            while(i>100){
                RE5=1;
                __delay_us(500);
                RE5=0;
                __delay_us(500);
                i++;
            
            }
            i=0;
        case 4:
            RH7=1;
            while(i>100){
                RH5=1;
                __delay_us(500);
                RH5=0;
                __delay_us(500);
                i++;
            
            }
            i=0;
        case 0:
            RH5=0;
            RE0=0;
    
    
    }

}

void I2C_Master_Init()
{
  SSPCON1 = 0x28;
  SSPCON2 = 0x00;
  SSPSTAT = 0x00;
  SSPADD = ((_XTAL_FREQ/4)/I2C_BaudRate) - 1;
  TRISC3 = 1;
  TRISC4 = 1;
}

void I2C_Wait(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)){};
}

void I2C_Start(void)
{
  //---[ Initiate I2C Start Condition Sequence ]---
  I2C_Wait();
  SEN = 1;
}




void I2C_Master_Stop(void)
{
  //---[ Initiate I2C Stop Condition Sequence ]---
  I2C_Wait();
  PEN = 1;
}

void I2C_Restart(void)
{
  //---[ Initiate I2C Restart Condition Sequence ]---
  I2C_Wait();
  RSEN = 1;
}

void I2C_ACK(void)
{
  //---[ Send ACK - For Master Receiver Mode ]---
  I2C_Wait();
  ACKDT = 0; // 0 -> ACK, 1 -> NACK
  ACKEN = 1; // Send ACK Signal!
}

void I2C_NACK(void)
{
  //---[ Send NACK - For Master Receiver Mode ]---
  I2C_Wait();
  ACKDT = 1; // 1 -> NACK, 0 -> ACK
  ACKEN = 1; // Send NACK Signal!
}

void I2C_Master_Write(unsigned char Data)
{
  //---[ Send Byte, Return The ACK/NACK ]---
  I2C_Wait();
  SSPBUF = Data;
  I2C_Wait();
 // return (ACKSTAT);
}

unsigned char I2C_Read(void)
{
  //---[ Receive & Return A Byte ]---
  RCEN = 1;        // Enable & Start Reception
  while(!SSPIF){};   // Wait Until Completion
  SSPIF = 0;       // Clear The Interrupt Flag Bit
  I2C_ACK();
  return SSPBUF;   // Return The Received Byte
}

unsigned char I2C_Read_NACK(void)
{
  //---[ Receive & Return A Byte ]---
  RCEN = 1;        // Enable & Start Reception
  while(!SSPIF){};   // Wait Until Completion
  SSPIF = 0;       // Clear The Interrupt Flag Bit
  I2C_NACK();
  return SSPBUF;   // Return The Received Byte
}

void MPU6050_Init(void)
{
  // Power-Up Delay & I2C_Init
  __delay_ms(100);
  I2C_Master_Init();
  // Setting The Sample (Data) Rate
  I2C_Start();
  I2C_Master_Write(SMPLRT_DIV);
  I2C_Master_Write(0x07);
  I2C_Master_Stop();
  // Setting The Clock Source
  I2C_Start();
  I2C_Master_Write(PWR_MGMT_1);
  I2C_Master_Write(0x01);
  I2C_Master_Stop();
  // Configure The DLPF
  I2C_Start();
  I2C_Master_Write(CONFIG);
  I2C_Master_Write(0x00);
  I2C_Master_Stop();
  // Configure The ACCEL (FSR= +-2g)
  I2C_Start();
  I2C_Master_Write(ACCEL_CONFIG);
  I2C_Master_Write(0x00);
  I2C_Master_Stop();
  // Configure The GYRO (FSR= +-2000d/s)
  I2C_Start();
  I2C_Master_Write(GYRO_CONFIG);
  I2C_Master_Write(0x18);
  I2C_Master_Stop();
  // Enable Data Ready Interrupts
  I2C_Start();
  I2C_Master_Write(INT_ENABLE);
  I2C_Master_Write(0x01);
  I2C_Master_Stop();
}


 int  MPU6050_Read(void)
{
  char buffer[40];
  int Ax, Ay, Az, Gx, Gy, Gz, T;
  // Prepare For Reading, Starting From ACCEL_XOUT_H
  I2C_Start();
  I2C_Master_Write(ACCEL_XOUT_H);
  I2C_Master_Stop();
  I2C_Start();
  Ax = ((int)I2C_Read()<<8) | (int)I2C_Read();
  Ay = ((int)I2C_Read()<<8) | (int)I2C_Read();
  Az = ((int)I2C_Read()<<8) | (int)I2C_Read();
  T  = ((int)I2C_Read()<<8) | (int)I2C_Read();
  Gx = ((int)I2C_Read()<<8) | (int)I2C_Read();
  Gy = ((int)I2C_Read()<<8) | (int)I2C_Read();
  Gz = ((int)I2C_Read()<<8) | (int)I2C_Read_NACK();
  I2C_Master_Stop();

  return (Ax);
  
}

void main()
{
    TRISE=0;
    TRISH=0;
    int direction_data;
    int data_acc;
    int i;
    i=0;
   config(); //configurations
   __delay_ms(200);
   WiFi_Config();  //configurations for wifi module
   __delay_ms(200);
   connected_to_thingspeak();
   __delay_ms(200);
   //config_server();
   //Get_IP_MAC();
  // on_timer(); //switch on timer1
   
   //glcd_write_text("ADC VALUE AN0 = ",1,0,1);
   RE0=1;
   RH0=1;
   MPU6050_Init();
   while(1){
       
       direction_data=send_req_data();
       do_move(direction_data);
       data_acc=MPU6050_Read();
       if(data_acc>500){
            RE7=1;
            RH7=1;
           while(i>10){
               i++;
               RE5=1;
               RH5=1;
               __delay_us(500);
               RE5=0;
               RH5=0;
               __delay_us(500);
                         
           } 
            i=0;
       }
       if(data_acc < -500){
            RE7=0;
            RH7=0;
           while(i>10){
               i++;
               RE5=1;
               RH5=1;
               __delay_us(500);
               RE5=0;
               RH5=0;
               __delay_us(500);
                         
           } 
            i=0;
       }
       
       
       
   
   }
       
       
}