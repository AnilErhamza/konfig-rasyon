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
	
	int a,b;
	if(accel1.OpMode==1||accel1.OpMode==2||accel1.OpMode==3||accel1.OpMode==4||accel1.OpMode==5)
	{
		a=1;
		if(accel1.OpMode==2 || accel1.OpMode==4 || accel1.OpMode==5)
		{
			a<<=1;
			if(accel1.OpMode==4) a<<=1;
			else if(accel1.OpMode==5)a=(a<<1)+1;
		}
		else if(accel1.OpMode==3) a=(a<<1)+1;
	}
	else a=0;
    
    if(accel1.BW==0||accel1.BW==1||accel1.BW==2||accel1.BW==3)
    {
    	a<<=1;
    	if(accel1.BW==0||accel1.BW==1)
		{
			a<<=1;
			if(accel1.BW==0) a<<=1;
			else a=(a<<1)+1;
		}
    	else if(accel1.BW==2||accel1.BW==3)
    	{
    		a=(a<<1)+1;
    		if (accel1.BW==2) a<<=1;
    		else a=(a<<1)+1;
		}
	}
    else if(accel1.BW==4||accel1.BW==5||accel1.BW==6||accel1.BW==7)
	{
    	a=(a<<1)+1;
    	if(accel1.BW==4||accel1.BW==5) 
    	{
    		a<<=1;
    		if(accel1.BW==4) a<<=1;
    		else a=(a<<1)+1;
		}
		else if(accel1.BW==6||accel1.BW==7)
		{
			a=(a<<1)+1;
			if(accel1.BW==6) a<<=1;
			else a=(a<<1)+1;
		}
	}
    
    if(accel1.Grange==0||accel1.Grange==1)
    {
    	a<<=1;
    	if(accel1.Grange==0) a<<=1;
    	else a=(a<<1)+1;
	}
    else if(accel1.Grange==2||accel1.Grange==3)
    {
    	a=(a<<1)+1;
    	if(accel1.Grange==2) a<<=1;
    	else a=(a<<1)+1;
	}
    
    
    int n = a;
    int len = 8;
 
    char* binary = toBinary(n, len);
    printf("The binary representation of %d is %s", n, binary);
    free(binary);
    
    printf("\n[ACC_Config](binary)=%d",a);
    
	return 0;
}





