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
  *   Created: Sun Dec 14 05:00:00 2014
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
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//#include <inttypes.h>
//#include <errno.h>


# ifndef MATLAB_MEX_FILE

	#include <linux/i2c.h>
	#include <linux/i2c-dev.h>
	#include <sys/ioctl.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	//#include <simstruc.h>
# else

	#include <mex.h>
	#include <simstruc.h>

# endif


//#define S_FUNCTION_NAME BBB_Driver_Gyroscope_L3G4200D 
//#define S_FUNCTION_LEVEL 2

#define I2CMode_Read 1
#define I2CMode_Write 2


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
    Error_No_I2CComm,
    Error_No_I2CInit,
    Error_No_I2CBuffSet,
    Error_No_I2CBuffRead,
    Error_No_I2CBuffSync,
    Error_No_I2CBuffWrite,
    Error_No_I2CBuffValidate,
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
const char *sI2CReadWrite_ErrMessage(eError_No iErrNo)
{
    //Set Error Message Based on Error Number
    switch(iErrNo)
    {     
       case  Error_None:
            return("No Error Active. System A-OK!\n");
            break;
        case  Error_No_I2CComm: 
            return("Failed to Open I2C Bus\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device\n - Check Device Tree on BBB\n");
            break;
        case Error_No_I2CInit:
            return("Failed to Communicate With Slave Device\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");        
            break;            
        case Error_No_I2CBuffSet:
            return("Failed to Set Buffer Read Range\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");            
            break;
        case Error_No_I2CBuffRead:
            return("Failed to Read Data in Registry Buffer\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");
            break;
        case Error_No_I2CBuffSync:
            return("Failed to Validate Registry Data - Inconsistent Data Stream\n"
                    " - Check For Multiple Master Access to Slave Device on I2C Bus Number\n"
                    " - Check SCL/SCA Lines\n - Check Device Address\n - Check Device Tree on BBB\n");
            break;            
        case Error_No_I2CBuffWrite:
            return("Failed to Write Data to Device Registry\n - Check Bus Traffic/Interference\n"
                   " - Check Bus Number\n - Check SCL/SCA Lines\n - Check Device Address\n - Check Device Tree on BBB\n"); 
            break;
 	case Error_No_I2CBuffValidate:
            return("Failed to Validate Data Written To Registry\n - Check Bus Traffic/Interference\n"
                   " - Check Bus Number\n - Check SCL/SCA Lines\n - Check Device Address\n - Check Device Tree on BBB\n"); 
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
// Set Debug Level
int iSet_Debug_Level(eDebugLevel iDebug_Level_X)
{

    switch(iDebug_Level_X)
    {
        case  1:
            return (Debug_None);
            break;
        case  2:
            return (Debug_Level_0);
            break;
        case  3:
            return (Debug_Level_1);
            break;
        case  4:
            return (Debug_Level_2);
            break;
        case  5:
            return (Debug_Level_3);
            break;
        case  6:
            return (Debug_Level_4);
            break;
        case  7:
            return (Debug_Level_5);
            break;
        default:
            return (Debug_None);
            break;
    }
}
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void BBB_Driver_I2C_Write_Outputs_wrapper(const boolean_T *inI2C_W_Enable,
                          const uint8_T *inI2C_W_Value,
                          const boolean_T *inI2C_W_Trigger,
                          uint8_T *outI2C_W_Data,
                          boolean_T *outSimStop ,
			      const real_T  *xD,
                          const uint8_T  *prmI2C_BusNo, const int_T  p_width0, 
                          const uint8_T  *prmI2C_DeviceAddress, const int_T  p_width1, 
                          const uint8_T  *prmI2C_RegisterNo, const int_T  p_width2, 
                          const uint8_T  *prmDebug_InfoLevel, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Define Output Data - Simulink

// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Define File Sys Pointer - For I2C Bus#1 -> Make Parameter
int iFILE_BBB_I2C_Handle=0;
int iIOCTL_BBB_I2C_Handle=0;
int iSYNC_BBB_I2C_Handle=0;
int iWrite_BBB_I2C_Handle=0;
// Function Outputs
int iI2C_Read=0;
int iI2C_Write=0;

//Define Device Driver sysfs Location
// const char *sBBB_I2C_BUS1_FILE ="/dev/i2c-1";
// char *sBBB_I2C_BUS1_FILE ="/dev/i2c-";
char sBBB_I2C_BUS1_FILE[100]="";

// Define I2C Parameters
int iI2C_BytesRead=0;
// Define I2C Buffer Size
const int iI2C_BufferSize=1;
// Define I2C Buffer Dump Variable
char cI2C_Buffer[1]={0x00}; //unsigned
// Define I2C Buffer Dump Start Position. Note: Value = Start Address w/ MSB Set To "1"
char cI2C_Buffer_Sync[1]={0x00}; // Start at reg 0x00
// Define Write Buffer
char cI2C_Buffer_Write[2]={0x00};
// Define I2C Buffer Status
char cI2C_Buffer_Status=0;//unsigned


// Define Loop Counters
int iLoop=0;
int iLoop_Counter;
// Define Device Address
char cDevice_I2C_Addr_Para=0x00;
char cDevice_I2C_Addr=0X00;
char cDevice_I2C_RegAddr[1]={0x00};
char cDevice_I2C_WriteValue=0x00;

// Initialize Error
eError_No iError_No = Error_None;
// Initialize Error Level
eError_Level iError_Level = Error_Level_OK;
// Initialize Debug Output Level
eDebugLevel iDebug_Level = Debug_None;

// Define Function iI2C_Read_Register
int iI2C_Read_Register(char *cRegister_Address, char *cRegister_Value)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sBBB_I2C_BUS1_FILE,"/dev/i2c-%u",prmI2C_BusNo[0]);
    
    // Check I2C Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("I2C_Write Msg: I2C Bus File Location: %s\n",sBBB_I2C_BUS1_FILE); }
    
    // Open Data IO Stream
    iFILE_BBB_I2C_Handle = open(sBBB_I2C_BUS1_FILE, O_RDWR);
    
    // Confirm I2C Bus Open
    if (iFILE_BBB_I2C_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("I2C_Write Error: Failed to Open I2C Bus - Check Device/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_I2CComm;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 2: Connect To I2C Bus\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Initiate I2C Communicaton
    if (iError_No == Error_None)
    {
        // Initiate Communicaiton
        iIOCTL_BBB_I2C_Handle=ioctl(iFILE_BBB_I2C_Handle,I2C_SLAVE,cDevice_I2C_Addr);
        
        // Error Handling
        if (iIOCTL_BBB_I2C_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("I2C_Write Error: Failed to Communicate With Slave Device: %#04x\n",cDevice_I2C_Addr);}
            // Set Error Number
            iError_No = Error_No_I2CInit;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 3: Connect to I2C Device\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Set Buffer Read Range
    if (iError_No == Error_None)
    {
        iWrite_BBB_I2C_Handle = write(iFILE_BBB_I2C_Handle,cRegister_Address,1); //cI2C_Buffer_Sync
        // Error Handling
        if (iWrite_BBB_I2C_Handle !=1)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1) { printf("I2C_Write Error: Failed to Write/Communicate With Device and/or Set Buffer Read Range\n");}
            // Set Error Number
            iError_No = Error_No_I2CBuffSet;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            if (iDebug_Level >=Debug_Level_1) { printf("I2C_Write Msg: Buffer Range Set\n");}
        }
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 4: Write to Device Registry\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Read Buffer Data
    if (iError_No == Error_None)
    {
        // Read and Store Registry Data in Buffer
        iI2C_BytesRead = read(iFILE_BBB_I2C_Handle,cRegister_Value,1);//cI2C_Buffer sizeof(cRegister_Value));
        // Close File
        close(iFILE_BBB_I2C_Handle);
        
        // Error Handling - Confirm Buffer Size
        if (iI2C_BytesRead<0)
        {
            // Error on Buffer Read!
            if (iDebug_Level >=Debug_Level_1) { printf("I2C_Write Error: Failed to Read Device Register: %#04x Bytes Read: %i\n",cRegister_Address[0],iI2C_BytesRead );}
            // Set Error Number
            iError_No = Error_No_I2CBuffRead;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            // Registry Data Read!
            if (iDebug_Level >=Debug_Level_1) { printf("I2C_Write Msg: Device Register Read. Bytes Read: %i\n",iI2C_BytesRead );}
            
        }
    }
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}
    
    
}

// Define Function iGryro_I2CWriteBuff
int iI2C_Write_Register(char cRegister_Address, char cRegister_Value)
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sBBB_I2C_BUS1_FILE,"/dev/i2c-%u",prmI2C_BusNo[0]);
    
    // Check I2C Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("I2C_Write Msg: I2C Bus File Location: %s\n",sBBB_I2C_BUS1_FILE); }
    
    // Open Data IO Stream
    iFILE_BBB_I2C_Handle = open(sBBB_I2C_BUS1_FILE, O_RDWR);
    
    // Confirm I2C Bus Open
    if (iFILE_BBB_I2C_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("I2C_Write Error: Failed to Open I2C Bus - Check Device/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_I2CComm;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 2: Connect To I2C Bus\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    
    // Initiate I2C Communicaton
    if (iError_No == Error_None)
    {
        // Initiate Communicaiton
        iIOCTL_BBB_I2C_Handle=ioctl(iFILE_BBB_I2C_Handle,I2C_SLAVE,cDevice_I2C_Addr);
        
        // Error Handling
        if (iIOCTL_BBB_I2C_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("I2C_Write Error: Failed to Communicate With Slave Device\n");}
            // Set Error Number
            iError_No = Error_No_I2CInit;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2CReadWrite Msg: Program Flow State 3: Connect to I2C Device\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Write Data to Register
    if (iError_No == Error_None)
    {
        
        // Set Gyro To Register Address!
        // Set Gyro Register Value
        cI2C_Buffer_Write[0]= cRegister_Address;//Address
        cI2C_Buffer_Write[1]= cRegister_Value;//Value
        iWrite_BBB_I2C_Handle = write(iFILE_BBB_I2C_Handle, cI2C_Buffer_Write, 2);
        
        // Ouput Program Flow
        if (iDebug_Level >=Debug_Level_3) {printf("I2CReadWrite Msg: Data Value : %#04x Written to Registry %#04x\n",cI2C_Buffer_Write[1], cI2C_Buffer_Write[0]);}
        
        
        if (iWrite_BBB_I2C_Handle!=2)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1) { printf("I2C_Write Error: Failed to Communicate With Device and/or Write To Device Register\n");}
            // Set Error Number
            iError_No = Error_No_I2CBuffWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            // Power Mode Set
            if (iDebug_Level >=Debug_Level_1){printf("I2C_Write Msg: Data Written to Device Register!\n");}
        }
    }
    // Close File
    close(iFILE_BBB_I2C_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}
}

//*****************************//
//*****************************//
////// MAIN PROGRAM START ///////
//*****************************//
//*****************************//

// Check For Block Enable
if (inI2C_W_Enable[0]==true)
{
    
    // Check Debug Level - Read Parameter Data -Debug Level
    iDebug_Level = iSet_Debug_Level(prmDebug_InfoLevel[0]);
       
    // Start Line
    if (iDebug_Level >=Debug_Level_0){printf("**** Start of I2C Write S-Function Block Execution **** \n");}
    
    // Check Parameters
    if (iDebug_Level >=Debug_Level_1){printf("I2C_Write Msg: Input Parameter Data: I2CBus: %#04x I2CAddress: %#04x\n",prmI2C_BusNo[0],prmI2C_DeviceAddress[0]);}
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 1: Parameters Initialized \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Record Device Address
    cDevice_I2C_Addr = prmI2C_DeviceAddress[0]; //0x68
    cDevice_I2C_RegAddr[0] = prmI2C_RegisterNo[0];
    cDevice_I2C_WriteValue=inI2C_W_Value[0];
    
    if (inI2C_W_Trigger[0]==true)
    {
        
        // Write To Device Register
        iI2C_Write_Register(cDevice_I2C_RegAddr[0],cDevice_I2C_WriteValue);// cDevice_I2C_WriteValue);
        
        // Check For Error
        if (iI2C_Write<0)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1){printf("I2CWrite Error: Failed to Write Value: %#04x to Device Register: %#04x\n",inI2C_W_Value[0],prmI2C_RegisterNo[0]);}
        }
        else
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1){printf("I2CWrite Error: Sucessfully Wrote Value: %#04x to Device Register: %#04x\n",inI2C_W_Value[0],prmI2C_RegisterNo[0]);}
        }
        
        // Read Back Data To Validate Write Functionality
        iI2C_Read=iI2C_Read_Register(cDevice_I2C_RegAddr,cI2C_Buffer);
        
        // Check For Error
        if (iI2C_Read<0)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1){printf("I2CRead Error: Validation Failure! Failed to Read Registery %#04x From Device\n",prmI2C_RegisterNo[0]);}
        }
        else
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1){printf("I2CRead Msg: Successfully Read Device Register %#04x. Value Read: %#04x For Validation\n",prmI2C_RegisterNo[0],cI2C_Buffer[0]);}
        }
        
        // Validate Data
        if (cI2C_Buffer[0]!=inI2C_W_Value[0])
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1) { printf("I2CWrite Error: Failed to Validate Data Written to Registery: %#04x != %#04x\n",inI2C_W_Value[0],cI2C_Buffer[0]);}
            // Set Error Number
            iError_No = Error_No_I2CBuffValidate;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        
    }
    else
    {
               
        // Ouput Program Flow
        if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 2-4: Read Trigger Disabled \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
        
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("I2C_Write Msg: Program Flow State 6: Loop Step Complete\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Check For Critical Errors and Stop Simulation
    if ((iError_No!=0)&&(iError_Level==Error_Level_Critical))
    {
        
        // Stop Simulation If Critical Error
        if (iDebug_Level >=Debug_Level_0) {printf("I2C_Write Msg: Critical Error Detected; Simulation Stopping! \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
        
        // Output Error Message:
        if (iDebug_Level >=Debug_Level_0) {printf("I2C_Write Error Details: %s",sI2CReadWrite_ErrMessage(iError_No));}
        
        
        // Stop Simulation
        outSimStop[0]=true;
    }
    else
    {
        // Output Registry Data
        outI2C_W_Data[0]=cI2C_Buffer[0];
        
        
        // Carry on
        outSimStop[0]=false;
    }
    
}

# else
# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void BBB_Driver_I2C_Write_Update_wrapper(const boolean_T *inI2C_W_Enable,
                          const uint8_T *inI2C_W_Value,
                          const boolean_T *inI2C_W_Trigger,
                          const uint8_T *outI2C_W_Data,
                          const boolean_T *outSimStop ,
                          real_T *xD, 
                          const uint8_T  *prmI2C_BusNo,  const int_T  p_width0,
                          const uint8_T  *prmI2C_DeviceAddress,  const int_T  p_width1,
                          const uint8_T  *prmI2C_RegisterNo,  const int_T  p_width2,
                           const uint8_T *prmDebug_InfoLevel, const int_T  p_width3)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Initialize Debug Output Level
eDebugLevel iDebug_Level = Debug_None; 

// Check Debug Level - Read Parameter Data -Debug Level
iDebug_Level = iSet_Debug_Level(prmDebug_InfoLevel[0]);
    
    
// Update Init Bit
if (xD[0]==0)
{
    // Set Init Complete 
    xD[0]=1; 
    
    // Output Update Compete
    if (iDebug_Level >=Debug_Level_1){printf("I2C_Write Msg: Program Flow State: Init First Scan Complete\n");}
}

// Print Gap
if (iDebug_Level >=Debug_Level_0){printf("\n");}
 

# else

// Do Nothing


#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
