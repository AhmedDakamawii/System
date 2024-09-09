/*
 * MPU6050.c
 *
 *  Created on: Dec 2, 2023
 *      Author: M.yahya
 */



#include "MPU6050.h"
                /* Include I2C Master header file */


#define MPU6050_ADDR     0x68

sint16 Accel_X_RAW;
sint16 Accel_Y_RAW;
sint16 Accel_Z_RAW;
sint16 Gyro_X_RAW;
sint16 Gyro_Y_RAW;
sint16 Gyro_Z_RAW;

float Ax=0, Ay=0, Az=0, Gx=0, Gy=0, Gz=0;

int check;
int Data;

/* Gyro initialization function */
void MPU6050_Init()
{
	delaySeconds(TIMER3_DEF,0.17); /* Power up time >100ms */

//	Data = 0x00;
//	I2C_MasterSendData(I2C1, WHO_AM_I , 1 , MPU6050_ADDR , 0 , I2C_ENABLE_SR , I2C_NOT_SEND_DATA);
//	I2C_MasterReceiveData(I2C1, &check, 1, MPU6050_ADDR , I2C_DISABLE_SR);

//	if (check == 104)  // 0x68 will be returned by the sensor if everything goes well
//	{
		// power management register 0X6B we should write all 0's to wake the sensor up
	  Data = 0x00;
	  I2C_MasterSendData(I2C1, PWR_MGMT_1 , 1 , MPU6050_ADDR, Data ,I2C_DISABLE_SR , I2C_SEND_DATA);

	  delaySeconds(TIMER3_DEF,1);
		// Set DATA RATE of 1KHz by writing SMPLRT_DIV register
     Data = 0x07;
     I2C_MasterSendData(I2C1, SMPLRT_DIV , 1 , MPU6050_ADDR, Data, I2C_DISABLE_SR, I2C_SEND_DATA);
     delaySeconds(TIMER3_DEF,1);
        // Configure The DLPF
 	  Data = 0x00;
      I2C_MasterSendData(I2C1, CONFIG , 1 , MPU6050_ADDR, Data, I2C_DISABLE_SR, I2C_SEND_DATA);
      delaySeconds(TIMER3_DEF,1);


		// Set accelerometer configuration in ACCEL_CONFIG Register
		// XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> ± 2g
	  Data = 0x00;
	  I2C_MasterSendData(I2C1, ACCEL_CONFIG , 1 , MPU6050_ADDR, Data , I2C_DISABLE_SR, I2C_SEND_DATA);
	  delaySeconds(TIMER3_DEF,1);

		// Set Gyroscopic configuration in GYRO_CONFIG Register
		// XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> ± 250 °/s
	  Data = 0x00;
	  I2C_MasterSendData(I2C1, GYRO_CONFIG , 1 , MPU6050_ADDR , Data , I2C_DISABLE_SR, I2C_SEND_DATA);
	  delaySeconds(TIMER3_DEF,1);
	  // Set DATA READY interrupt
	  Data = 0x01;
	  I2C_MasterSendData(I2C1, INT_ENABLE , 1 , MPU6050_ADDR , Data , I2C_DISABLE_SR, I2C_SEND_DATA);

//	}


}

uint8 MPU6050_Read_Accel (void)
{
	int Rec_Data[6];

	// Read 6 BYTES of data starting from ACCEL_XOUT_H register
	 I2C_MasterSendData(I2C1, ACCEL_XOUT_H , 1 , MPU6050_ADDR , 0 , I2C_ENABLE_SR , I2C_NOT_SEND_DATA);
	 I2C_MasterReceiveData(I2C1, Rec_Data , 6 ,  MPU6050_ADDR , I2C_DISABLE_SR);


	Accel_X_RAW = (((int)Rec_Data[0])<<8 | (int)Rec_Data[1]);
	Accel_Y_RAW = (((int)Rec_Data[2])<<8 | (int)Rec_Data[3]);
	Accel_Z_RAW = (((int)Rec_Data[4])<<8 | (int)Rec_Data[5]);

	/*** convert the RAW values into acceleration in 'g'
	     we have to divide according to the Full scale value set in FS_SEL
	     I have configured FS_SEL = 0. So I am dividing by 16384.0
	     for more details check ACCEL_CONFIG Register              ****/
    if( (Accel_X_RAW > 15000 || Accel_X_RAW < -15000) ||  (Accel_Y_RAW > 15000 || Accel_Y_RAW < -15000) || (Accel_Z_RAW < -15000) )
    {
    	return 1;
    }

    else
    	return 0;

	//Ax = (float)Accel_X_RAW/16384.0;
	//Ay = (float)Accel_Y_RAW/16384.0;
	//Az = (float)Accel_Z_RAW/16384.0;
}


/*void MPU6050_Read_Gyro (void)
{
	int Rec_Data[6];

	// Read 6 BYTES of data starting from GYRO_XOUT_H register
	  I2C_MasterSendData(I2C1, GYRO_XOUT_H , 1 , MPU6050_ADDR , 0 , I2C_ENABLE_SR , I2C_NOT_SEND_DATA);
	  I2C_MasterReceiveData(I2C1, Rec_Data , 6 , MPU6050_ADDR , I2C_DISABLE_SR);


	Gyro_X_RAW = (((int)Rec_Data[0])<<8 | (int)Rec_Data[1]);
	Gyro_Y_RAW = (((int)Rec_Data[2])<<8 | (int)Rec_Data[3]);
	Gyro_Z_RAW = (((int)Rec_Data[4])<<8 | (int)Rec_Data[5]);

	** convert the RAW values into dps (°/s)
	     we have to divide according to the Full scale value set in FS_SEL
	     I have configured FS_SEL = 0. So I am dividing by 131.0
	     for more details check GYRO_CONFIG Register              ***

	Gx = (float)Gyro_X_RAW/131;
	Gy = (float)Gyro_Y_RAW/131;
	Gz = (float)Gyro_Z_RAW/131;
}*/

