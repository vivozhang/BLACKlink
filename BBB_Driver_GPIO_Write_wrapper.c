/*
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is a wrapper S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_wrapper_XXXXX_Changes_BEGIN 
  *            Your Changes go here
  *        %%%-SFUNWIZ_wrapper_XXXXXX_Changes_END
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder User's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *   Created: Sun Dec 14 04:55:04 2014
  */


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <fcntl.h>
//#include <poll.h>

#define sSYSFS_GPIO_Dir "/sys/class/gpio"

#define MAX_BUF 100

// Declare Pin Value Enum
typedef enum 
{
       	iPin_Low=0,
	iPin_High=1 
}eGPIO_PinValue;

// Declare Pin Direction Enum
typedef enum 
{
       	iPin_Input,
	iPin_Output 
}eGPIO_PinDirection;


// Declare Pin Number Enum
typedef enum 
{
       	iPin_GPIO_49=49,
	iPin_GPIO_51=51,
	iPin_GPIO_60=60 
}eGPIO_PinNo;


// Declare Error Handling
// extern int errno; 

// Define Debug Levels
typedef enum 
{
       	Debug_None,
	Debug_Level_0, // Basic Debug Info Output
        Debug_Level_1, // + Critical Info Only
	Debug_Level_2, // + Diagnostics Info
	Debug_Level_3, // + Program Flow Info
	Debug_Level_4, // + Registry Data
	Debug_Level_5  // + TBD 
}eDebugLevel;


// Define Error Number
typedef enum 
{
    Error_None=0,
    Error_No_SYSFSOpen,
    Error_No_SYSFSRead,
    Error_No_SYSFSWrite,
    Error_No_ParamOutofRange
}eError_No;

// Initialize Error
// eError_No iError_No = Error_None;

// Define Error Severity Levels
typedef enum
{
    Error_Level_OK=0,
    Error_Level_Critical, // (Stop Simulation)
    Error_Level_Warning
}eError_Level;

// Initialize Error Level
// eError_Level iError_Level = Error_Level_OK;
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void BBB_Driver_GPIO_Write_Outputs_wrapper(const boolean_T *inGPIO_Write_Enable,
                          const boolean_T *inGPIO_Write,
                          boolean_T *outGPIO_WriteValue,
                          boolean_T *outSimStop ,
			      const real_T  *xD,
                          const uint16_T  *prmGPIO_No, const int_T  p_width0, 
                          const uint16_T  *prmDebug_InfoLevel, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE


// Declare and Initialize Error
eError_No iError_No = Error_None;

// Declare and Initialize Error Level
eError_Level iError_Level = Error_Level_OK;

// Declare and Initialize SYSFS Strings
char sBBB_GPIO_FILE[MAX_BUF]="";
char sBBB_GPIO_No[3]="";
char sSYSFS_GPIO_UnExp[MAX_BUF]="";
char sSYSFS_GPIO_Exp[MAX_BUF]="";
char sSYSFS_GPIO_Direction[MAX_BUF]="";
char sSYSFS_GPIO_Value[MAX_BUF]="";
char cSYSFS_GPIO_ReadVal="";

// Declare and Initialize File Handles
int iFILE_BBB_GPIO_Open_Handle=0;
int iFILE_BBB_GPIO_Read_Handle=0;
int iFILE_BBB_GPIO_Write_Handle=0;

// Declare and Initialize Ints
unsigned int iGPIO_No_Req=0;
unsigned int iGPIO_ReadValue=iPin_Low;

// Initialize Debug Output Level
eDebugLevel iDebug_Level = Debug_None;

/****************************************/
// Export (Enable) GPIO File For Read
/****************************************/
int iBBB_GPIOExport(eGPIO_PinNo iGPIONo)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sSYSFS_GPIO_Exp,"%s/export",sSYSFS_GPIO_Dir);
    
    // Check GPIO Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO Export SYSFS Path: %s\n",sSYSFS_GPIO_Exp); }
        
    // Open Data IO Stream
    iFILE_BBB_GPIO_Open_Handle = open(sSYSFS_GPIO_Exp, O_WRONLY);
    
    // Confirm SYSFS IOStream Open
    if (iFILE_BBB_GPIO_Open_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("GPIOWrite Error: Failed Find/Open GPIO SYSFS Export File - Check GPIO Number/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("GPIOWrite Msg: Program Flow State 2: Open GPIO SYSFS File\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Write GPIO For Export Command
    if (iError_No == Error_None)
    {
        
        // Create Handle to SYSFS File Stream
        sprintf(sBBB_GPIO_No,"%d",iGPIONo); 
        
        // Check GPIO Bus Concatenation
        if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO No: %s\n",sBBB_GPIO_No); }

        
        // Write GPIO SYSFS Data     
        iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,sBBB_GPIO_No,sizeof(sBBB_GPIO_No));
        
        // Error Handling
        if (iFILE_BBB_GPIO_Write_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("GPIOWrite Error: Failed to Export GPIO Number To User Space\n");}
            // Set Error Number
            iError_No = Error_No_SYSFSWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
    // Close File Handle
    close(iFILE_BBB_GPIO_Open_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}

}

/****************************************/
// Unexport (Disable) GPIO For Read
/****************************************/
int iBBB_GPIOUnExport(eGPIO_PinNo iGPIONo)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sSYSFS_GPIO_UnExp,"%s/unexport",sSYSFS_GPIO_Dir);
    
    // Check GPIO Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO UnExport SYSFS Path: %s\n",sSYSFS_GPIO_UnExp); }
        
    // Open Data IO Stream
    iFILE_BBB_GPIO_Open_Handle = open(sSYSFS_GPIO_UnExp, O_WRONLY);
    
    // Confirm SYSFS IOStream Open
    if (iFILE_BBB_GPIO_Open_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("GPIOWrite Error: Failed Find/Open GPIO UnExport SYSFS File - Check GPIO Number/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Output Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("GPIOWrite Msg: Program Flow State 2: Open GPIO SYSFS File\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Write GPIO For Export Command
    if (iError_No == Error_None)
    {
        
        // Create Handle to SYSFS File Stream
        sprintf(sBBB_GPIO_No,"%d",iGPIONo); 
        
        // Write GPIO SYSFS Data     
        iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,sBBB_GPIO_No,sizeof(sBBB_GPIO_No));
        
        // Error Handling
        if (iFILE_BBB_GPIO_Write_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("GPIOWrite Error: Failed to UnExport GPIO Number To User Space\n");}
            // Set Error Number
            iError_No = Error_No_SYSFSWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
    // Close File Handle
    close(iFILE_BBB_GPIO_Open_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}
}

/****************************************/
// Set GPIO Direction (Read/Write)
/****************************************/
int iBBB_GPIOSetDirection(eGPIO_PinNo iGPIONo, eGPIO_PinDirection iGPIODirection)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sSYSFS_GPIO_Direction,"%s/gpio%d/direction",sSYSFS_GPIO_Dir,iGPIONo);
    
    // Check GPIO Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO Direction SYSFS Path: %s\n",sSYSFS_GPIO_Direction); }
        
    // Open Data IO Stream
    iFILE_BBB_GPIO_Open_Handle = open(sSYSFS_GPIO_Direction, O_WRONLY);
    
    // Confirm SYSFS IOStream Open
    if (iFILE_BBB_GPIO_Open_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("GPIOWrite Error: Failed Find/Open GPIO Direction SYSFS File - Check GPIO Number/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("GPIOWrite Msg: Program Flow State 2: Open GPIO SYSFS File\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Write GPIO For Export Command
    if (iError_No == Error_None)
    {
        
        // Create Handle to SYSFS File Stream
        // sprintf(sBBB_GPIO_No,"%d",iGPIONo); 
        
        if (iGPIODirection==iPin_Input)
        {
        
            // Write GPIO SYSFS Data     
            iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,"in",sizeof("in"));
        }
        else
        {
            // Write GPIO SYSFS Data     
            iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,"out",sizeof("out"));
        }
                
        // Error Handling
        if (iFILE_BBB_GPIO_Write_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("GPIOWrite Error: Failed to Set GPIO In/Out Direction In User Space\n");}
            // Set Error Number
            iError_No = Error_No_SYSFSWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
    // Close File Handle
    close(iFILE_BBB_GPIO_Open_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}

}

/****************************************/
// Read GPIO Input Value
/****************************************/
int iBBB_GPIORead(eGPIO_PinNo iGPIONo, unsigned int *iGPIOVal)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sSYSFS_GPIO_Value,"%s/gpio%d/value",sSYSFS_GPIO_Dir,iGPIONo);
    
    // Check GPIO Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO Value SYSFS Path: %s\n",sSYSFS_GPIO_Value); }
        
    // Open Data IO Stream
    iFILE_BBB_GPIO_Open_Handle = open(sSYSFS_GPIO_Value, O_RDONLY);
    
    // Confirm SYSFS IOStream Open
    if (iFILE_BBB_GPIO_Open_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("GPIOWrite Error: Failed Find/Open GPIO Value SYSFS File - Check GPIO Number/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("GPIOWrite Msg: Program Flow State 2: Open GPIO SYSFS File\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Write GPIO For Export Command
    if (iError_No == Error_None)
    {
        
        // Create Handle to SYSFS File Stream
        // sprintf(sBBB_GPIO_No,"%d",iGPIONo); 
        
        // Write GPIO SYSFS Data     
        iFILE_BBB_GPIO_Read_Handle=read(iFILE_BBB_GPIO_Open_Handle,&cSYSFS_GPIO_ReadVal,sizeof(&cSYSFS_GPIO_ReadVal));

         // Check GPIO Bus Concatenation
        if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO Value Read: %s\n",&cSYSFS_GPIO_ReadVal); }

        
        // Check Value
        if (cSYSFS_GPIO_ReadVal=='1')
        {
            // Transfer Out Read Value
            *iGPIOVal=iPin_High;
        }
        else
        {
            // Transfer Out Read Value
            *iGPIOVal=iPin_Low;
        }
      
        // Error Handling
        if (iFILE_BBB_GPIO_Read_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("GPIOWrite Error: Failed to Read GPIO Value In User Space\n");}
            // Set Error Number
            iError_No = Error_No_SYSFSRead;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
    // Close File Handle
    close(iFILE_BBB_GPIO_Open_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}

}

/****************************************/
// Write GPIO Output Value
/****************************************/
int iBBB_GPIOWrite(eGPIO_PinNo iGPIONo, eGPIO_PinValue iGPIOVal)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sSYSFS_GPIO_Value,"%s/gpio%d/value",sSYSFS_GPIO_Dir,iGPIONo);
    
    // Check GPIO Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("GPIOWrite Msg: GPIO Write SYSFS Path: %s\n",sSYSFS_GPIO_Value); }
        
    // Open Data IO Stream
    iFILE_BBB_GPIO_Open_Handle = open(sSYSFS_GPIO_Value, O_WRONLY);
    
    // Confirm SYSFS IOStream Open
    if (iFILE_BBB_GPIO_Open_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("GPIOWrite Error: Failed Find/Open GPIO Value SYSFS File - Check GPIO Number/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("GPIOWrite Msg: Program Flow State 2: Open GPIO SYSFS File\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Write GPIO For Export Command
    if (iError_No == Error_None)
    {
      
        // Check Requested Write Value
        if (iGPIOVal==iPin_High)
        {
            // Write GPIO SYSFS Data     
            iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,"1",2);//sizeof("1"));
        }
        else
        {
            // Write GPIO SYSFS Data     
            iFILE_BBB_GPIO_Write_Handle=write(iFILE_BBB_GPIO_Open_Handle,"0",2);//sizeof("0"));
        }
        
         
      
        // Error Handling
        if (iFILE_BBB_GPIO_Write_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("GPIOWrite Error: Failed to Write GPIO Value In User Space\n");}
            // Set Error Number
            iError_No = Error_No_SYSFSWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
    // Close File Handle
    close(iFILE_BBB_GPIO_Open_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}

}


/****************************************/
// GPIO Error Message Output 
/****************************************/
const char *sGPIORead_ErrMessage(eError_No iGPIORead_ErrNo)
{
    //Set Error Message Based on Error Number
    switch(iGPIORead_ErrNo)
    {     
       case  Error_None:
            return("No Error Active. System A-OK!\n");
            break;
        case  Error_No_SYSFSOpen: 
            return("Failed to Open I2C Bus\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device\n - Check Device Tree on BBB\n");
            break;
        case Error_No_SYSFSRead:
            return("Failed to Communicate With Slave Device\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");        
            break;            
        case Error_No_SYSFSWrite:
            return("Failed to Set Buffer Read Range\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");            
            break;      
        case Error_No_ParamOutofRange:
            return("Parameter Out Of Range\n - Check Block Parameter Input Options\n");
            break;        
        default:
            // Error -Return Default 
            return("Error Code Not Recognized\n");
            break;
    }          
}


/****************************************/
/****************************************/
// Main Program Start
/****************************************/
/****************************************/

// Run Through Program Only If Block Enabled
if (inGPIO_Write_Enable[0]==true)
{

// Read Parameter Data -Device Number
    switch(prmGPIO_No[0])
    {
        case  1: //GPIO to Control
            iGPIO_No_Req=iPin_GPIO_49;
            break;
        case  2:
            iGPIO_No_Req=iPin_GPIO_51;
            break;
        case  3:
            iGPIO_No_Req=iPin_GPIO_60;
            break;
        default:
            iGPIO_No_Req=iPin_GPIO_49;
            break;
    }
    
    // Read Parameter Data -Debug Level
    switch(prmDebug_InfoLevel[0])
    {
        case  1:
            iDebug_Level=Debug_None;
            break;
        case  2:
            iDebug_Level=Debug_Level_0;
            break;
        case  3:
            iDebug_Level=Debug_Level_1;
            break;
        case  4:
            iDebug_Level=Debug_Level_2;
            break;
        case  5:
            iDebug_Level=Debug_Level_3;
            break;
        case  6:
            iDebug_Level=Debug_Level_4;
            break;
        case  7:
            iDebug_Level=Debug_Level_5;
            break;
        default:
            iDebug_Level=Debug_None;
            break;
    }

    // Start Line
    if (iDebug_Level >=Debug_Level_0){printf("**** Start of GPIO Write S-Function Block Execution **** \n");}
    
    // Export GPIO Pin Only On First Scan
    if (xD[0]==0)
    {
        
        // Export GPIO Pin Only On First Scan
        if (iBBB_GPIOExport(iGPIO_No_Req)<0)
        {
            // GPIO Already Exported. Reset Error
            iError_No = Error_None;
            // Reset Error Level
            iError_Level = Error_Level_OK;
        }
        else
        {
            // Do Nothing - GPIO Properly Exported
        }
    }
    
// Set Direction - Move Inside First Scan?
    if (iError_No == Error_None)
    {
        // Set GPIO Direction
        iBBB_GPIOSetDirection(iGPIO_No_Req, iPin_Output);
    }
    
// Write Data Depending on Input
    if (iError_No == Error_None)
    {
        
        // Check Input Command
        if (inGPIO_Write[0]==true)
        {
            // Set GPIO On
            iBBB_GPIOWrite(iGPIO_No_Req,iPin_High);
        }
        else
        {            
            // Set GPIO On
            iBBB_GPIOWrite(iGPIO_No_Req,iPin_Low);
        }
    }
    
// UnExport GPIO sysfs 
    if (iError_No == Error_None)
    {
        // UnExport GPIO Pin
        // iBBB_GPIOUnExport(iGPIO_No_Req);
    }
    
// Check For Critical Errors and Stop Simulation
    if ((iError_No!=0)&&(iError_Level==Error_Level_Critical))
    {
        
        // Stop Simulation If Critical Error
        if (iDebug_Level >=Debug_Level_0) {printf("GPIORead Msg: Critical Error Detected; Simulation Stopping! \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
        
        // Output Error Message:
        if (iDebug_Level >=Debug_Level_0) {printf("GPIO Error Details: %s",sGPIORead_ErrMessage(iError_No));}
        
        
        // Stop Simulation
        outSimStop[0]=true;
    }
    else
    {
        // Carry on
        outSimStop[0]=false;
        
        // Set Output Data
        
        // Get Feedback From GPIO Pin
        iBBB_GPIORead(iGPIO_No_Req, &iGPIO_ReadValue);
        
        if (iGPIO_ReadValue==true)
        {
            outGPIO_WriteValue[0]=true;
        }
        else
        {
            outGPIO_WriteValue[0]=false;
        }
    }

    // Print Output
    if (iDebug_Level >=Debug_Level_0){printf("Data To GPIO Output: %d\n",outGPIO_WriteValue[0]);}
        
    
// Print Gap
if (iDebug_Level >=Debug_Level_0){printf("\n");}
    
}

# else
# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void BBB_Driver_GPIO_Write_Update_wrapper(const boolean_T *inGPIO_Write_Enable,
                          const boolean_T *inGPIO_Write,
                          const boolean_T *outGPIO_WriteValue,
                          const boolean_T *outSimStop ,
                          real_T *xD, 
                          const uint16_T  *prmGPIO_No,  const int_T  p_width0,
                           const uint16_T *prmDebug_InfoLevel, const int_T  p_width1)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Execute on First Scan
if (xD[0]==0)
{
    // Set First Scan Bit
    xD[0]=1;
}




# endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
