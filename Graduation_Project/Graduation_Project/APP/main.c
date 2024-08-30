/*
 * Graduation_Project.c
 *
 * Created: 7/12/2024 7:38:28 PM
 * Author : Carnival Stores
 */ 

#include "main.h"


int main(void)
{
	uint8_t buttonState0=BTN0_NPRESSED;
	uint8_t buttonState1=BTN1_NPRESSED;
	uint8_t buttonState2=BTN2_NPRESSED;
	uint8_t data=60;
	uint8_t Mode_Counter=0;
	uint8_t flag_mode=0;
	uint8_t flag_sum=0;
	uint8_t flag_heating_element_led=0;
	
	uint16_t val;
	uint16_t act_val;
	
	uint32_t i=0;
	uint32_t j=0;
	uint32_t k=0;
	uint32_t m=0;
	uint32_t iter=0;
	uint32_t sum=0;
	uint32_t average=0;
	uint32_t arr[10];
	signed int Remainder=0;
	
	BTN0_Initialize();
	BTN1_Initialize();
	BTN2_Initialize();
	
	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	
	SEVENSEGMENT_Initialize();
	
	ADC_Initialize_WithoutInterrupt(ADC_Avcc,ADC_PRE64);
	
	EEPROM_Write_Byte(1,60);
	
	while(1)
	{
		i=0;
		j=0;
		k=0;
		m=0;
		Mode_Counter=0;
		iter=0;
		flag_sum=0;
		flag_heating_element_led=0;
		average=0;
		//Off mode
		if (flag_mode==0)
		{
			//Turn off all display
			LED0_OFF();
			LED1_OFF();
			LED2_OFF();
			SEVENSEGMENT_Disable();
			//If ON/OFF is pressed, turn ON display
			buttonState0=BTN0_Read();
			if (buttonState0==BTN0_PRESSED)
			{
				while(buttonState0==BTN0_PRESSED)
				{
					buttonState0=BTN0_Read();
				}
				flag_mode=1;
			}
		}
		//Current temperature display mode
		else if(flag_mode==1)
		{
			while(flag_mode==1)
			{
				if (m==20)
				{
					m=0;
				}
				//Read current temperature from ADC
				val=ADC_Read(ADC_channel_6);
				if (val<52)
				{
					act_val=val/2;
				}
				else if (val>=52 && val<=125)
				{
					act_val=(val/2)-1;
				}
				else
				{
					act_val=(val/2)-2;
				}
				//Display current temperature on Seven Segment
				SEVENSEGMENT_Enable();
				SEVENSEGMENT_DisplayNumber(act_val);
				arr[k]=act_val;
				if (k==9)
				{
					flag_sum=1;
					k=0;
				}
				if (flag_sum==1)
				{
					sum=0;
					for (iter=0;iter<10;iter++)
					{
						sum=sum+arr[iter];
					}
					//Get the average value every 100ms
					average=sum/10;
					Remainder=data-average;
					//If the actual temperature is less than the set temperature
					if (Remainder>=5)
					{
						//Turn ON the heating element and turn OFF the cooling element
						LED0_ON();
						LED1_OFF();
						flag_heating_element_led=1;
					}
					//If the actual temperature is higher than the set temperature
					else if (Remainder<=-5)
					{
						//Turn OFF the heating element and turn ON the cooling element
						LED0_OFF();
						LED1_ON();
						//Turn ON heating element LED when cooling element is ON
						LED2_ON();
						flag_heating_element_led=0;
					}
					else
					{
						//Turn OFF both the heating element and the cooling element if the temperature is within set temperature bounds
						LED0_OFF();
						LED1_OFF();
						LED2_OFF();
						flag_heating_element_led=0;
					}
				}
				//When heating element is ON, blink the heating element LED
				if (flag_heating_element_led==1)
				{
					if (m<10)
					{
						LED2_ON();
					}
					else
					{
						LED2_OFF();
					}
				}
				_delay_ms(100);
				//If ON/OFF button is pressed, turn all display OFF (go to OFF mode)
				buttonState0=BTN0_Read();
				if (buttonState0==BTN0_PRESSED)
				{
					while(buttonState0==BTN0_PRESSED)
					{
						buttonState0=BTN0_Read();
					}
					flag_mode=0;
				}
				//If Up OR Down button is pressed, go to temperature selection mode
				buttonState1=BTN1_Read();
				buttonState2=BTN2_Read();
				if (buttonState1==BTN1_PRESSED || buttonState2==BTN2_PRESSED)
				{
					while(buttonState1==BTN1_PRESSED || buttonState2==BTN2_PRESSED)
					{
						buttonState1=BTN1_Read();
						buttonState2=BTN2_Read();
					}
					flag_mode=2;
				}
				//Increment the counters
				k++;
				m++;
			}
		}
		//Temperature selection mode
		else if (flag_mode==2)
		{
			while(Mode_Counter<5 && flag_mode==2)
			{
				while(i<10)
				{
					//The ON part of the blinking
					//Read the set temperature from the EEPROM
					data=EEPROM_Read_Byte(1);
					//Display the set temperature on the Seven Segment
					SEVENSEGMENT_Enable();
					SEVENSEGMENT_DisplayNumber(data);
					_delay_ms(100);
					i++;
					//If ON/OFF is pressed, go to OFF mode
					buttonState0=BTN0_Read();
					if (buttonState0==BTN0_PRESSED)
					{
						while(buttonState0==BTN0_PRESSED)
						{
							buttonState0=BTN0_Read();
						}
						flag_mode=0;
						break;
					}
					//If UP button is pressed
					buttonState1=BTN1_Read();
					if (buttonState1==BTN1_PRESSED)
					{
						while(buttonState1==BTN1_PRESSED)
						{
							buttonState1=BTN1_Read();
						}
						//Increase the set temperature by 5, up until 75
						data=data+5;
						if (data>75)
						{
							data=75;
						}
						//Write the new set temperature to the EEPROM
						EEPROM_Write_Byte(1,data);
						Mode_Counter=0;
					}
					//If Down button is pressed
					buttonState2=BTN2_Read();
					if (buttonState2==BTN2_PRESSED)
					{
						while(buttonState2==BTN2_PRESSED)
						{
							buttonState2=BTN2_Read();
						}
						//Reduce the set temperature by 5, down until 35
						data=data-5;
						if (data<35)
						{
							data=35;
						}
						//Write the new set temperature to the EEPROM
						EEPROM_Write_Byte(1,data);
						Mode_Counter=0;
					}
				}
				i=0;
				Mode_Counter++;
				if (Mode_Counter>=5)
				{
					flag_mode=1;
					break;
				}
				while(j<10)
				{
					//The OFF part of the blinking
					SEVENSEGMENT_Disable();
					_delay_ms(100);
					j++;
					//If ON/OFF is pressed, go to OFF mode
					buttonState0=BTN0_Read();
					if (buttonState0==BTN0_PRESSED)
					{
						while(buttonState0==BTN0_PRESSED)
						{
							buttonState0=BTN0_Read();
						}
						flag_mode=0;
						break;
					}
					//If UP button is pressed
					buttonState1=BTN1_Read();
					if (buttonState1==BTN1_PRESSED)
					{
						while(buttonState1==BTN1_PRESSED)
						{
							buttonState1=BTN1_Read();
						}
						//Increase the set temperature by 5, up until 75
						data=data+5;
						if (data>75)
						{
							data=75;
						}
						//Write the new set temperature to the EEPROM
						EEPROM_Write_Byte(1,data);
						Mode_Counter=0;
					}
					//If Down button is pressed
					buttonState2=BTN2_Read();
					if (buttonState2==BTN2_PRESSED)
					{
						while(buttonState2==BTN2_PRESSED)
						{
							buttonState2=BTN2_Read();
						}
						//Reduce the set temperature by 5, down until 35
						data=data-5;
						if (data<35)
						{
							data=35;
						}
						//Write the new set temperature to the EEPROM
						EEPROM_Write_Byte(1,data);
						Mode_Counter=0;
					}
				}
				j=0;
				Mode_Counter++;
			}
			//If ON/OFF is pressed, go to Off Mode
			if (flag_mode==0)
			{
				
			}
			//If the timer runs out, return to current temperature display mode
			else
			{
				flag_mode=1;
			}
		}
	}
}