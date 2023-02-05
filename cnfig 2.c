#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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

char* toBinary(int n, int len)
{
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0,i;
    for (i = (1 << len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

int main()
{
	int a,b,c,d;
	Accel accel1;
	Gyro gyro1;
	Magneto magneto1;
	
	accel1.Grange=AR_8G;
	accel1.BW=AB_500Hz;
	accel1.OpMode=AOM_DeepSusp;
	
	gyro1.range=GR_500dps;
	gyro1.BW=GB_47Hz;
	gyro1.OpMode=GOM_AdvPowSave;
	
	magneto1.DOR=MDOR_25Hz;
	magneto1.OpMode=MOP_reg;
	magneto1.PowMode=MPM_normal;
	
	a=(accel1.OpMode<<5 | accel1.BW<<2 |accel1.Grange );
	
	b=(gyro1.BW<<3|gyro1.range);
	
	c=(magneto1.PowMode<<5|magneto1.OpMode<<3|magneto1.DOR);
	
	int n = a;
    int len = 8;
 
    char* binary1 = toBinary(n, len);
    printf("[ACC_Config](binary)= %s\n", binary1);
   
    int binary_num, decimal_num = 0, base = 1, rem, num=atoi(binary1);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[ACC_Config](decimal)= %d\n", decimal_num);    
    
    long int binaryval=atoi(binary1), hexadecimalval = 0, i = 1, remainder;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[ACC_Config](hexadecimal)= %lX\n\n", hexadecimalval);
    
    
	
	n=b;
    char* binary2 = toBinary(n, len);
    printf("[GYR_Config_0](binary)= %s\n", binary2);
    decimal_num = 0;
	base = 1;
	rem=0;
	num=atoi(binary2);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[GYR_Config_0](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(binary2);
	hexadecimalval = 0;
	i = 1; 
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[GYR_Config_0](hexadecimal)= %lX\n\n", hexadecimalval);


	n=gyro1.OpMode;
    char* binary3 = toBinary(n, len);
    printf("[GYR_Config_1](binary)= %s\n", binary3);
   
    decimal_num = 0;
	base = 1;
	num=atoi(binary3);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[GYR_Config_1](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(binary3);
	 hexadecimalval = 0;
	  i = 1;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("[GYR_Config_1](hexadecimal)= %lX\n\n", hexadecimalval);
   
   
   
    n=c;
    char* binary4 = toBinary(n, len);
    printf("[MAG_Config](binary)= %s\n", binary4);
    
    decimal_num = 0;
	base = 1;
	num=atoi(binary4);  
    binary_num = num;  
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
    printf ("[MAG_Config](decimal)= %d\n", decimal_num);    
    
    binaryval=atoi(binary4);
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





