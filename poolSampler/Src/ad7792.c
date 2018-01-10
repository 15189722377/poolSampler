#include "ad7792.h"


unsigned char DataRead[3];

/**
  * @brief  Delay
  * @param  time: Delay time
  * @retval None
  */
void Delay(unsigned int Time)
{
	while(Time)
	{
		Time--;
	}
}

/**
  * @brief  Delay
  * @param  time: Delay time
  * @retval None
  */
void delayLoop(unsigned int Time)
{
		Time*=3;
		while(Time--)
		{
			__nop();
		}
}

/**
  * @brief  write ByteData to the register
  * @param  ByteData: ByteData (send to reg)
  * @retval None
  */
void WriteToReg(unsigned char ByteData) 
{
	unsigned char temp=0x80;
	int i;	
	
	AD7792_CS_0;
	
	for(i=0;i<8;i++)
	{
 		if((temp & ByteData)==0)
		{		
       MOSI_0;
		}	
 		else
		{
			 MOSI_1;
    }
		CLK_0;
		Delay(10);
	  CLK_1;
		Delay(10);
 		temp=temp>>1;
	}
	AD7792_CS_1;
}
void Writebyte(uint8_t data)
{
	int i=0;

	AD7792_CS_0;
	for(i=0; i<8; i++)
	{
		if(data&0x80)
		{
			MOSI_1;
		}
		else
		{
			MOSI_0;
		}

		data<<=1;
		CLK_0;
		delayLoop(10);
		CLK_1;
		delayLoop(10);
	}
	AD7792_CS_0;
}

/**
  * @brief  write two ByteData to the register
  * @param  data: u16 data send to reg
  * @retval None
  */
void Write2bytes(uint16_t data)
{
	int i=0;

	AD7792_CS_0;
	for(i=0; i<16; i++)
	{
		if(data&0x8000)
		{
			MOSI_1;
		}
		else
		{
			MOSI_0;
		}

		data<<=1;
		CLK_0;
		delayLoop(10);
		CLK_1;
		delayLoop(10);
	}
	AD7792_CS_1;
}

/**
  * @brief  read data from reg
  * @param  nByte: the num of data
  * @retval None
  */
void ReadFromReg(unsigned char nByte) // nByte is the number of bytes which need to be read
{
	int i,j;
  unsigned char temp=0;
	
 	MOSI_1;
 	AD7792_CS_0;

	for(i=0; i<nByte; i++)
	{
		for(j=0; j<8; j++)
	  {
			CLK_0;
			if(HAL_GPIO_ReadPin(SPI_DOUT_GPIO_Port,SPI_DOUT_Pin)==0)
			{				
				temp=temp<<1;
			}
			else
			{
				temp=temp<<1;
				temp=temp+0x01;
			}
			Delay(10);
			CLK_1;
			Delay(10);
		}
			DataRead[i]=temp;
			temp=0;
	}
  AD7792_CS_1;
}

void AD7792_Init(void)
{
	int ResetTime;
	
	/* Set up UART */
	
	/* PRECONFIGURE...*/
	ResetTime=32;
	CLK_1;
 	AD7792_CS_0;		  //to keep DIN=1 for 32 sclock to reset the part
 	MOSI_1;
 	while(ResetTime--)
	{
		Delay(10);
		CLK_0;
		Delay(10);
 		CLK_1;
	}
 	AD7792_CS_1;	
	
	WriteToReg(0x00|(1<<3));// config R1
	Write2bytes(0x400a);	// idle mode, 120ms refresh rate

	WriteToReg(0x00|(2<<3));// config R2
	Write2bytes(0x1210);	// uni-polar, 4-times gain, enable input buffer

	WriteToReg(0x00|(5<<3));// config R5
	Writebyte(0x03);		// enable 1mA output
	
	WriteToReg(0x00|(1<<3));// config R1
	Write2bytes(0x800a);	// internal calibration
	HAL_Delay(40000);
	
	WriteToReg(0x00|(1<<3));// config R1
	Write2bytes(0xa00a);	// internal full scale calibration
	HAL_Delay(40000);

	WriteToReg(0x00|(1<<3));// config R1
	Write2bytes(0x000a);	// start contiguous conversion
	HAL_Delay(40);
}    

float tempreadRt(void)
{
    int i;
	uint16_t temp;
	uint16_t tempMax=0;
	uint16_t tempMin=65535;
	uint32_t tempAverage=0;

	for (i=0; i<10; i++)
	{
		temp = 0;

	//	__disable_irq();
		WriteToReg(0x00|(1<<3));//config R1
		Write2bytes(0x200a);

		WriteToReg(0x40);//write to Communication register.The next step is to read from Status register.
		ReadFromReg(1);
		while((DataRead[0]&0x80)==0x80)//wait for the end of conversion by polling the status register RDY bit
		{
			WriteToReg(0x40);
			ReadFromReg(1);
		}

		WriteToReg(0x58);//write to Communication register.The next step is to read from Data register.
		ReadFromReg(2);
		//__enable_irq();

		temp=DataRead[0];
		temp<<=8;
		temp+=DataRead[1];

		if (temp > tempMax)
			tempMax = temp;
		if (temp < tempMin)
			tempMin = temp;

		tempAverage += temp;
	}

	tempAverage -= (tempMax+tempMin);
	tempAverage /= 8;
	temp = (uint16_t)tempAverage;
	return temp*1000/65535;
}

float temp_R0=0;
float temp_RTDA=0;

 float temperatureRead(void)
{
	/************************************************************************
	 Now after delaying 1000 mS in the tskCond.c, we measure temperature
	 once a second. Instead of averaging a low data rate of both temperature
	 and conductivity, we average the "raw" readings. For each display
	 update in every second, we measure 40 conductivity readings and 10
	 temperature readings. We could take more temperature readings.
	*********************************************************************/
	int i;
	uint32_t temp;	
	float tempF,Rtemp=0;
	uint16_t tempMax=0;
	uint16_t tempMin=65535;
	uint32_t tempAverage=0;

	
// 	gRSample = gSysParam.temp_Rx;//????,???gSysParam???-zb

	// for backward compatibility
// 	if ( (*ptr==0x00) && (*(ptr+1)==0x00) && (*(ptr+2)==0x00) && (*(ptr+3)==0x00) )
// 	{
// 		gRSample = gRSampleDefault;
// 	}

	for (i=0; i<10; i++)
	{
		temp = 0;

		__disable_irq();


		WriteToReg(0x40);//write to Communication register.The next step is to read from Status register.
		ReadFromReg(1);//???????

		WriteToReg(0x58);//write to Communication register.The next step is to read from Data register.
		ReadFromReg(2);//???????
		__enable_irq();

		temp=DataRead[0];
		temp<<=8;
		temp+=DataRead[1];
            
		if (temp > tempMax)
			tempMax = temp;
		if (temp < tempMin)
			tempMin = temp;

		tempAverage += temp;
	}

	tempAverage -= (tempMax+tempMin);
	tempAverage /= 8;
	temp = (uint16_t)tempAverage;
      
	Rtemp=((float)temp/4.0)*(float)1000/(float)65535;

	/***************************************************
	 * A cubic fit over the range of -100? to +600?
	 * provides an RMS error of only 0.038? over the
	 * entire range, and 0.026? in the range of
	 * 0? to 400?
	 **************************************************/
	//TemperC = -247.29 + 2.3992*Rtemp + (6.3962E-4)*Rtemp*Rtemp + (1.0241E-6)*Rtemp*Rtemp*Rtemp;

	/*******************************************************************
	 * reference http://sensing.honeywell.com/index.php?ci_id=50025
	 ******************************************************************/
      
	if(temp_R0==0||temp_RTDA==0)	// if temp_R0 and temp_RTDA don't exist
	{
		TemperC = ( (-R0*RTD_A) + sqrt(R0*R0*RTD_A*RTD_A-4*R0*RTD_B*(R0-Rtemp)) )/(2*R0*RTD_B);
	}
	else
	{
		TemperC = ( (-temp_R0*temp_RTDA) + sqrt(temp_R0*temp_R0*temp_RTDA*temp_RTDA-4*temp_R0*RTD_B*(temp_R0-Rtemp)) )/(2*temp_R0*RTD_B);
	}

	//TemperC = TemperC*gTempK + gTempB;
	tempF = TemperC*1.8+32;  //???-zb
	tempF=tempF;
	/************************************************************************
	 CX copy this portion of the code from temperatureRead()
	*********************************************************************/
//#ifndef TEMP_DEBUG
//	if ( (tempF < 150.0) && (tempF > -4.0) )
//    {
//		if (gFirstTemp == true)
//		{
//			gTempF = tempF;
//			gFirstTemp = false;
//		}
//		else
//		{
//			if (gTempF > tempF)
//			{
//				tempDiff = gTempF - tempF;
//			}
//			else
//			{
//				tempDiff = tempF - gTempF;
//			}

//			if ( (tempDiff > TEMP_JITTER_MIN_THRESHOLD) && (tempDiff < TEMP_JITTER_MAX_THRESHOLD) )
//			{
//				gTempF = tempF;
//			}
//		}
//    }
//#else
//	gTempF = tempF;
//#endif

    //return gTempF;
	return TemperC;
}




