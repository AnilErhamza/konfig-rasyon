#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum Accrange{ 
	AR_2G,
	AR_4G,
	AR_8G,
	AR_16G	
};

enum AccBW{
	AB_7_81Hz,
	AB_15_63Hz,
	AB_31_25Hz,
	AB_62_5Hz,
	AB_125Hz,
	AB_250Hz,
	AB_500Hz,
	AB_1000Hz
};

enum AccOpMode{
	AOM_normal,
	AOM_suspend,
	AOM_LowPow1,
	AOM_standby,
	AOM_LowPow2,
	AOM_DeepSusp
};

enum Gyrorange{
	GR_2000dps,
	GR_1000dps,
	GR_500dps,
	GR_250dps,
	GR_125
};

enum GyroBW{
	GB_523Hz,
	GB_230Hz,
	GB_116Hz,
	GB_47Hz,
	GB_23Hz,
	GB_12Hz,
	GB_64Hz,
	GB_32Hz
};

enum GyroOpMode{
	GOM_normal,
	GOM_FastPowUp,
	GOM_DeepSusup,
	GOM_suspend,
	GOM_AdvPowSave
};

enum MagnetoDataOR{
	MDOR_2Hz,
	MDOR_6Hz,
	MDOR_8Hz,
	MDOR_10Hz,
	MDOR_15Hz,
	MDOR_20Hz,
	MDOR_25Hz,
	MDOR_30Hz
};

enum MagnetoOpMode{
	MOP_LowPow,
	MOP_reg,
	MOP_EnhReg,
	MOP_HighAcc
};

enum MagnetoPowMode{
	MPM_normal,
	MPM_sleep,
	MPM_suspend,
	MPM_ForceMode
};

typedef struct{
	int Grange;
	int BW;
	int OpMode;
}Accel;

typedef struct{
	int range;
	int BW;
	int OpMode;
}Gyro;

typedef struct{
	int DOR;
	int OpMode;
	int PowMode;
}Magneto;


int main()
{
	Accel accel1;
	Gyro gyro1;
	Magneto magneto1;
	
	accel1.Grange=AR_8G;
	accel1.BW=AB_500Hz;
	accel1.OpMode=AOM_normal;
	
	gyro1.range=GR_500dps;
	gyro1.BW=GB_47Hz;
	gyro1.OpMode=GOM_normal;
	
	magneto1.DOR=MDOR_25Hz;
	magneto1.OpMode=MOP_reg;
	magneto1.PowMode=MPM_normal;
	
	char acc1[10],gyro0[10],gyro2[10],magneto[10];
	
	if(accel1.OpMode==0) strcpy(acc1, "000");
	else if(accel1.OpMode==1) strcpy(acc1, "001");
	else if(accel1.OpMode==2) strcpy(acc1, "010");
	else if(accel1.OpMode==3) strcpy(acc1, "011");
	else if(accel1.OpMode==4) strcpy(acc1, "100");
	else if(accel1.OpMode==5) strcpy(acc1, "101");
	
	if(accel1.BW==0) strcat(acc1, "000");
	else if(accel1.BW==1) strcat(acc1, "001");
	else if(accel1.BW==2) strcat(acc1, "010");
	else if(accel1.BW==3) strcat(acc1, "011");
	else if(accel1.BW==4) strcat(acc1, "100");
	else if(accel1.BW==5) strcat(acc1, "101");
	else if(accel1.BW==6) strcat(acc1, "110");
	else if(accel1.BW==7) strcat(acc1, "111");
	
	if(accel1.Grange==0) strcat(acc1, "00");
	else if(accel1.Grange==1) strcat(acc1, "01");
	else if(accel1.Grange==2) strcat(acc1, "10");
	else if(accel1.Grange==3) strcat(acc1, "11");
	
	printf("[ACC_Config](binary)=");
	puts(acc1);
	
	int binary_num, decimal_num = 0, base = 1, rem, num=atoi(acc1);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[ACC_Config](decimal)= %d\n", decimal_num);    
    
    long int binaryval=atoi(acc1), hexadecimalval = 0, i = 1, remainder;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[ACC_Config](hexadecimal)= %lX\n", hexadecimalval);
    
    binary_num=0;
    
    if(gyro1.BW==0) strcpy(gyro0, "000");
	else if(gyro1.BW==1) strcpy(gyro0, "001");
	else if(gyro1.BW==2) strcpy(gyro0, "010");
	else if(gyro1.BW==3) strcpy(gyro0, "011");
	else if(gyro1.BW==4) strcpy(gyro0, "100");
	else if(gyro1.BW==5) strcpy(gyro0, "101");
	else if(gyro1.BW==6) strcpy(gyro0, "110");
	else if(gyro1.BW==7) strcpy(gyro0, "111");
    
    if(gyro1.range==0) strcat(gyro0, "000");
	else if(gyro1.range==1) strcat(gyro0, "001");
	else if(gyro1.range==2) strcat(gyro0, "010");
	else if(gyro1.range==3) strcat(gyro0, "011");
	else if(gyro1.range==4) strcat(gyro0, "100");
	
	printf("[GYR_Config_0](binary)=");
	puts(gyro0);
	
	decimal_num = 0;
	base = 1;
	rem=0;
	num=atoi(gyro0);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[GYR_Config_0](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(gyro0);
	 hexadecimalval = 0;
	  i = 1; 
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[GYR_Config_0](hexadecimal)= %lX\n", hexadecimalval);
    
    if(gyro1.OpMode==0) strcpy(gyro2, "000");
	else if(gyro1.OpMode==1) strcpy(gyro2, "001");
	else if(gyro1.OpMode==2) strcpy(gyro2, "010");
	else if(gyro1.OpMode==3) strcpy(gyro2, "011");
	else if(gyro1.OpMode==4) strcpy(gyro2, "100");
    
    printf("[GYR_Config_1](binary)=");
	puts(gyro2);
	
	decimal_num = 0;
	base = 1;
	num=atoi(gyro2);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[GYR_Config_1](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(gyro2);
	 hexadecimalval = 0;
	  i = 1;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[GYR_Config_1](hexadecimal)= %lX\n", hexadecimalval);
    
    
    if(magneto1.PowMode==0) strcpy(magneto, "00");
	else if(magneto1.PowMode==1) strcpy(magneto, "01");
	else if(magneto1.PowMode==2) strcpy(magneto, "10");
	else if(magneto1.PowMode==3) strcpy(magneto, "11");
    
    if(magneto1.OpMode==0) strcat(magneto, "00");
	else if(magneto1.OpMode==1) strcat(magneto, "01");
	else if(magneto1.OpMode==2) strcat(magneto, "10");
	else if(magneto1.OpMode==3) strcat(magneto, "11");
    
    
    if(magneto1.DOR==0) strcat(magneto, "000");
	else if(magneto1.DOR==1) strcat(magneto, "001");
	else if(magneto1.DOR==2) strcat(magneto, "010");
	else if(magneto1.DOR==3) strcat(magneto, "011");
	else if(magneto1.DOR==4) strcat(magneto, "100");
	else if(magneto1.DOR==5) strcat(magneto, "101");
	else if(magneto1.DOR==6) strcat(magneto, "110");
	else if(magneto1.DOR==7) strcat(magneto, "111");
    
    
    printf("[MAG_Config](binary)=");
	puts(magneto);
	
	decimal_num = 0;
	base = 1;
	num=atoi(magneto);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[MAG_Config](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(magneto);
	hexadecimalval = 0;
	i = 1;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[MAG_Config](hexadecimal)= %lX", hexadecimalval);
    
    
    
	return 0;
}
















































