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
  *   Created: Sun Dec 14 04:58:47 2014
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

# ifdef MATLAB_MEX_FILE
	#include <mex.h>
	#include <simstruc.h>
# endif

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
    Error_No_SYSFSSeek,
    Error_No_SYSFSScan, 
    Error_No_SYSFSClose,
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
void BBB_Driver_ADC_Read_Outputs_wrapper(const boolean_T *inADC_Read_Enable,
                          const boolean_T *inADC_Read_Trigger,
                          uint32_T *outADC_Voltage,
                          boolean_T *outSimStop ,
			      const real_T  *xD,
                          const uint8_T  *prmAINPin, const int_T  p_width0, 
                          const boolean_T  *prmRunCalibration, const int_T  p_width1, 
                          const uint16_T  *prmDebug_InfoLevel, const int_T p_width2)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Define Output Data - Simulink

// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Declare and Initialize Error
eError_No iError_No = Error_None;

// Declare and Initialize Error Level
eError_Level iError_Level = Error_Level_OK;

// Define File Sys Pointer - Note Code Will Use fopen vs. open
static FILE *fBBB_Handle = NULL;
char sBBB_ADC_AINX[64]="";
char cBBB_ADC_Pin="";

// Define Internal Variable Data
float dBBB_ADC_Volt_Val=0;
float dBBB_ACC_Val=0;
float const dBBB_ACC_Val_Nominal=1666+(-0.06006*333);
float dBBB_ADC_Volt_CalibOffset=0;

// Initialize Debug Output Level
eDebugLevel iDebug_Level = Debug_None;

/****************************************/
// Accelerometer Error Message Output 
/****************************************/
const char *sAccel_ErrMessage(eError_No iAccel_ErrNo)
{
    //Set Error Message Based on Error Number
    switch(iAccel_ErrNo)
    {     
       case  Error_None:
            return("No Error Active. System A-OK!\n");
            break;
        case  Error_No_SYSFSOpen: 
            return("Failed to Open I2C Bus\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device\n - Check Device Tree on BBB\n");
            break;
        case  Error_No_SYSFSSeek: 
            return("Failed to Open I2C Bus\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device\n - Check Device Tree on BBB\n");
            break;
        case Error_No_SYSFSScan:
            return("Failed to Communicate With Slave Device\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");        
            break;            
        case Error_No_SYSFSClose:
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
if (iDebug_Level >=Debug_Level_0){printf("**** Start of ADC Read S-Function Block Execution **** \n");} 

// Write Read Raw Voltage Data
if (iError_No == Error_None)
{
    
    // Concatenate SYSFS File I/O Name
    sprintf(sBBB_ADC_AINX,"/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN%d",prmAINPin[0]-1);
    
    if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Msg: ADC SYSFS Path:\n %s\n",sBBB_ADC_AINX); }
        
    // Open Streams
    fBBB_Handle = fopen(sBBB_ADC_AINX, "r");
    
// Confirm SYSFS IOStream Open
    if (sBBB_ADC_AINX==NULL)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Error: Failed To Open I/O File Stream - Check ""cape-bone-iio"" Device Tree Active\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSOpen;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
}

// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("ADCRead Msg: Program Flow State 1: Open SYSFS File I/O Stream\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   

// Write Read Raw Voltage Data
if (iError_No == Error_None)
{
    // Read ADC Voltage
    if (fseek(fBBB_Handle, 0, SEEK_SET)!=0)
    {    
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Error: ""fseek()"" Failed To Set Position Indicator in I/O File Stream\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSSeek;
        // Set Error Level
        iError_Level = Error_Level_Critical;
    }    
    if (fscanf(fBBB_Handle, "%f", &dBBB_ADC_Volt_Val)!=1)
    {    
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Error: ""fscan()"" Failed To Read Data From I/O File Stream\n"); }
        // Set Error Number
        iError_No = Error_No_SYSFSScan;
        // Set Error Level
        iError_Level = Error_Level_Critical;
    } 


}

// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("ADCRead Msg: Program Flow State 2: Seek & Scan Data From File I/O Stream\nError No: %i Error Level: %i\n",iError_No, iError_Level);}


// Calibrate Voltage
if (iError_No == Error_None)
{
    // Calibrate Voltage
    
}

// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("ADCRead Msg: Program Flow State 3: Calibrate Voltage Data \nError No: %i Error Level: %i\n",iError_No, iError_Level);}

// Close File on Exit
if (fclose(fBBB_Handle)!=0)
{
    // Error Handling
    if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Error: ""fclose()"" Failed To Properly Close Data From I/O File Stream\n"); }
    // Set Error Number
    iError_No = Error_No_SYSFSClose;
    // Set Error Level
    iError_Level = Error_Level_Critical;
}

// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("ADCRead Msg: Program Flow State 4: Close SYSFS File I/O Stream\nError No: %i Error Level: %i\n",iError_No, iError_Level);}


// Print Voltage Data
if (iDebug_Level >=Debug_Level_0)  { printf("AIN%d Voltage (mV):%f\n",prmAINPin[0]-1,dBBB_ADC_Volt_Val);}

// Check For Critical Errors and Stop Simulation
if ((iError_No!=0)&&(iError_Level==Error_Level_Critical))
{
    
    // Stop Simulation If Critical Error
    if (iDebug_Level >=Debug_Level_0) {printf("ADCRead Msg: Critical Error Detected; Simulation Stopping! \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Output Error Message:
    if (iDebug_Level >=Debug_Level_0) {printf("ADCRead Error Details: %s",sAccel_ErrMessage(iError_No));}
    
    
    // Stop Simulation
    outSimStop[0]=true;
}
else
{
    // Carry on
    outSimStop[0]=false;

    // Transfer Data to Outputs!
    outADC_Voltage[0]=(unsigned long)dBBB_ADC_Volt_Val;
}

# else


# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void BBB_Driver_ADC_Read_Update_wrapper(const boolean_T *inADC_Read_Enable,
                          const boolean_T *inADC_Read_Trigger,
                          const uint32_T *outADC_Voltage,
                          const boolean_T *outSimStop ,
                          real_T *xD, 
                          const uint8_T  *prmAINPin,  const int_T  p_width0,
                          const boolean_T  *prmRunCalibration,  const int_T  p_width1,
                           const uint16_T *prmDebug_InfoLevel, const int_T  p_width2)
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

// Print Gap
if (prmDebug_InfoLevel[0]>=Debug_Level_0){printf("\n");} 


// Parameter Definition
// xD[0]= First Scan / Calibration Complete 
// xD[1]= Calibration Sample Quantity
// xD[2]= X Axis Voltage Total Sum
// xD[3]= Y Axis Voltage Total Sum
// xD[4]= Z Axis Voltage Total Sum

// // Execute on First Scan
// if (prmRunCalibration[0]==true)
// {
//     if (xD[0]<=xD[1])
//     {
//         // Sum Raw Voltage Data
//         xD[2]=xD[2]+dBBB_ADC_Volt_Val_X;
//         xD[3]=xD[3]+dBBB_ADC_Volt_Val_Y;
//         xD[4]=xD[4]+dBBB_ADC_Volt_Val_Z;
//     }
//     else
//     {
//        //Calculate Average OffSet Voltage
//        xD[2]=xD[2]/xD[1]
//        // NOTE - 0g Varies based on sensitiviy - 2V = 1V @ 0g         
//     }
// }   
// 
//     // Set Calibration Complete / First Scan Bit
//     xD[0]=1;


// Read Selected AIN Pin Data -Debug Level
// switch(prmAINPin[0])
// {
//     case  1:
//         cBBB_ADC_Pin="0";
//         break;
//     case  2:
//         cBBB_ADC_Pin="1";
//         break;
//     case  3:
//         cBBB_ADC_Pin="2";
//         break;
//     case  4:
//         cBBB_ADC_Pin="3";
//         break;
//     case  5:
//         cBBB_ADC_Pin="4";
//         break;
//     case  6:
//         cBBB_ADC_Pin="5";
//         break;
//     case  7:
//         cBBB_ADC_Pin="6";
//         break;
//     case  8:
//         cBBB_ADC_Pin="7";
//         break;
//     default:
//         cBBB_ADC_Pin="";
//         // Error Handling
//         if (iDebug_Level >=Debug_Level_1)  { printf("ADCRead Error: Requested AIN Pin Not Recognized\n"); }
//         // Set Error Number
//         iError_No = Error_No_ParamOutofRange;
//         // Set Error Level
//         iError_Level = Error_Level_Critical;
//         break;
// }





# endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
