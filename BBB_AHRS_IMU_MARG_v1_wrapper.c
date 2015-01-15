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
  *   Created: Sun Dec 14 04:46:51 2014
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


// Initialize Error
// eError_No iError_No = Error_None;

// Define Error Severity Levels
typedef enum
{
    Error_Level_OK=0,
    Error_Level_Critical, // (Stop Simulation)
    Error_Level_Warning
}eError_Level;

// Declare Flux in Earth Frame - Global Variables
double dCompass_b_x;
double dCompass_b_z;

// Declare Gyro Bias Error - Global Variables
double dGyro_w_x_Bias;
double dGyro_w_y_Bias;
double dGyro_w_z_Bias;
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
void BBB_AHRS_IMU_MARG_v1_Outputs_wrapper(const real_T *inGyro_w_x,
                          const real_T *inGyro_w_y,
                          const real_T *inGyro_w_z,
                          const real_T *inAccel_a_x,
                          const real_T *inAccel_a_y,
                          const real_T *inAccel_a_z,
                          const real_T *inCompass_m_x,
                          const real_T *inCompass_m_y,
                          const real_T *inCompass_m_z,
                          real_T *outQuat_q_1,
                          real_T *outQuat_q_2,
                          real_T *outQuat_q_3,
                          real_T *outQuat_q_4,
                          boolean_T *outStopSim,
                          const real_T  *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE

// Initialize Estimated Quaternions
double dEst_q_1=0.0f;
double dEst_q_2=0.0f;
double dEst_q_3=0.0f;        
double dEst_q_4=0.0f;
double dEst_q_Norm=0.0f;

double dEst_S_E_q_1_dot=0;
double dEst_S_E_q_2_dot=0;
double dEst_S_E_q_3_dot=0;
double dEst_S_E_q_4_dot=0;

double dEst_S_E_q_1_hat_dot=0;
double dEst_S_E_q_2_hat_dot=0;
double dEst_S_E_q_3_hat_dot=0;
double dEst_S_E_q_4_hat_dot=0;

// Declare and Initialize Gyro and Accel Data Temp Variables
double dGyro_w_x=0.0f,dGyro_w_y=0.0f,dGyro_w_z=0.0f;
double dGyro_w_x_Error=0.0f,dGyro_w_y_Error=0.0f,dGyro_w_z_Error=0.0f;
// double dGyro_w_x_Bias=0.0f,dGyro_w_y_Bias=0.0f,dGyro_w_z_Bias=0.0f;
double dAccel_a_x=0.0f,dAccel_a_y=0.0f,dAccel_a_z=0.0f;
double dAccel_Norm=0.0f,dAccel_a_Norm_x=0.0f,dAccel_a_Norm_y=0.0f,dAccel_a_Norm_z=0.0f;
double dCompass_m_x=0.0f,dCompass_m_y=0.0f,dCompass_m_z=0.0f;
double dCompass_h_x=0.0f, dCompass_h_y=0.0f, dCompass_h_z=0.0f; // Earths Magnetic Field in Current Orientation
double dCompass_Norm=0.0f, dCompass_m_Norm_x=0.0f, dCompass_m_Norm_y=0.0f, dCompass_m_Norm_z=0.0f;
//double dCompass_b_x=1.0f, dCompass_b_z=0.0f; // Flux in Earth Frame - Global

// Declare and Initialize Quaternion Angular Rate Variables
double dS_E_q_w_1_dot=0;
double dS_E_q_w_2_dot=0;
double dS_E_q_w_3_dot=0;
double dS_E_q_w_4_dot=0;


// Declare Objective Function Data
double dObjective_f_11=0,dObjective_f_21=0,dObjective_f_31=0;
double dObjective_f_41=0,dObjective_f_51=0,dObjective_f_61=0;
double dObjective_J_11=0,dObjective_J_12=0,dObjective_J_13=0,dObjective_J_14=0;
double dObjective_J_21=0,dObjective_J_22=0,dObjective_J_23=0,dObjective_J_24=0;
double dObjective_J_31=0,dObjective_J_32=0,dObjective_J_33=0,dObjective_J_34=0;
double dObjective_J_41=0,dObjective_J_42=0,dObjective_J_43=0,dObjective_J_44=0;
double dObjective_J_51=0,dObjective_J_52=0,dObjective_J_53=0,dObjective_J_54=0;
double dObjective_J_61=0,dObjective_J_62=0,dObjective_J_63=0,dObjective_J_64=0;
double dObjective_Grad_f_11=0.0f,dObjective_Grad_f_21=0.0f,dObjective_Grad_f_31=0.0f,dObjective_Grad_f_41=0.0f;
double dObjective_Grad_f_Norm=0.0f;

// Define Constants
#define M_pi 3.141592653589793l
#define dGyro_Measurement_Error M_pi*(5.0f/180.0f)
#define dGyro_Measurement_Drift M_pi*(0.2f/180.0f)
#define dSample_Period_Delta_t 0.02f
#define dGain_Beta 0.1f //sqrt(3.0f/4.0f)*dGyro_Measurement_Error // Filter Gain Divergence Rate of S_E_q_w
#define dGain_Zeta 0.001f //sqrt(3.0f/4.0f)*dGyro_Measurement_Drift // Filter Gain Convergence Rate of Gyro Bias Error S_E_q_wdot 
#define dGain_Alpha 0.1f // Convergence Reate of S_E_q_w_Grad

//#define dGain_Beta 0.1f //sqrt(3.0f/4.0f)*dGyro_Measurement_Error // Filter Gain Divergence Rate of S_E_q_w
//#define dGain_Zeta 0.001f //sqrt(3.0f/4.0f)*dGyro_Measurement_Drift // Filter Gain Convergence Rate of Gyro Bias Error S_E_q_wdot 
//#define dGain_Alpha 0.1f // Convergence Reate of S_E_q_w_Grad

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
eError_No iError_No = Error_None;

// Initialize Debug Level
eDebugLevel iDebug_Level = Debug_Level_5;


/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
// Main Program Start 
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

// Read Input Data To Local Variables
dGyro_w_x=inGyro_w_x[0];
dGyro_w_y=inGyro_w_y[0];
dGyro_w_z=inGyro_w_z[0];
dAccel_a_x=inAccel_a_x[0];
dAccel_a_y=inAccel_a_y[0];
dAccel_a_z=inAccel_a_z[0];
dCompass_m_x=inCompass_m_x[0];
dCompass_m_y=inCompass_m_y[0];
dCompass_m_z=inCompass_m_z[0];

// Initialize Quaternion Data During First Scan
if (xD[0]==0)
{
   // Set Initial Quaternion Values - Senor Frame Aligned with Earth Frame
    dEst_q_1=1.0f; 
    dEst_q_2=0.0f;     
    dEst_q_3=0.0f; 
    dEst_q_4=0.0f;
    
    // Set Initial Values For Normalized Flux Vector
    dCompass_b_x=1.0f;
    dCompass_b_z=0.0f;
    
    // Populate Gyro Bias Error
    dGyro_w_x_Bias=0.0f;
    dGyro_w_y_Bias=0.0f;  
    dGyro_w_z_Bias=0.0f;
    
    // Output Estimated Quaternion Data
   if (iDebug_Level >=Debug_Level_3) { printf("Quaternion Data Init: Q1: %.2f Q2: %.2f Q3: %.2f Q4: %.2f\n",dEst_q_1,dEst_q_2,dEst_q_3,dEst_q_4);}
}
else if (xD[0]==1)
{
    // Populate Quaternion Local Variables With Saved Persistent Data From 
    // Previous Timestep (t-1)
    dEst_q_1=xD[1];
    dEst_q_2=xD[2];
    dEst_q_3=xD[3];
    dEst_q_4=xD[4];
    //Populate Normalized Flux Vector in Earth Frame
    dCompass_b_x=xD[5];
    dCompass_b_z=xD[6];
    // Populate Gyro Bias Error
    dGyro_w_x_Bias=xD[7];
    dGyro_w_y_Bias=xD[8];  
    dGyro_w_z_Bias=xD[9];
    // Output Estimated Quaternion Data 
    if (iDebug_Level >=Debug_Level_3) { printf("Quaternion Data Update> Q1: %.2f Q2: %.2f Q3: %.2f Q4: %.2f\n",dEst_q_1,dEst_q_2,dEst_q_3,dEst_q_4);}

}

// Output Estimated Quaternion Data 
//if (iDebug_Level >=Debug_Level_3) { printf("Quaternion Data Update> Q1: %.2f Q2: %.2f Q3: %.2f Q4: %.2f %s\n",dEst_q_1,dEst_q_2,dEst_q_3,dEst_q_4);}

   
/*************************************************************************/
// Step 1: Calculate Gradient of the Objective Function "f"
// Which Descibes The Optimization Problem. 
// Note: The optimization problem aims to minimize the difference between
// a given reference direction of the field (gravity) in the earth field 
// and the measured direction of the field in sensor frame via a rotational 
// transform operation.
/*************************************************************************/

// Step 1.1 > Normalize Accelerometer Measurements
dAccel_Norm = sqrt(dAccel_a_x*dAccel_a_x+dAccel_a_y*dAccel_a_y+dAccel_a_z*dAccel_a_z);
dAccel_a_Norm_x=dAccel_a_x/dAccel_Norm;
dAccel_a_Norm_y=dAccel_a_y/dAccel_Norm;
dAccel_a_Norm_z=dAccel_a_z/dAccel_Norm;

// Step 1.2 > Normalize Compass Measurements
dCompass_Norm = sqrt(dCompass_m_x*dCompass_m_x+dCompass_m_y*dCompass_m_y+dCompass_m_z*dCompass_m_z);
dCompass_m_Norm_x=dCompass_m_x/dCompass_Norm;
dCompass_m_Norm_y=dCompass_m_y/dCompass_Norm;
dCompass_m_Norm_z=dCompass_m_z/dCompass_Norm;

// Step 1.3 > Calculate Objective Function Array "f"
dObjective_f_11=(2.0f*(dEst_q_2*dEst_q_4-dEst_q_1*dEst_q_3)-dAccel_a_Norm_x);
dObjective_f_21=(2.0f*(dEst_q_1*dEst_q_2+dEst_q_3*dEst_q_4)-dAccel_a_Norm_y);
dObjective_f_31=(2.0f*(0.5f-dEst_q_2*dEst_q_2-dEst_q_3*dEst_q_3)-dAccel_a_Norm_z);
dObjective_f_41=(2.0f*dCompass_b_x*(0.5f - dEst_q_3*dEst_q_3 - dEst_q_4*dEst_q_4)+2.0f*dCompass_b_x*(dEst_q_2*dEst_q_4-dEst_q_1*dEst_q_3)-dCompass_m_Norm_x);
dObjective_f_51=(2.0f*dCompass_b_x*(dEst_q_2*dEst_q_3 - dEst_q_1*dEst_q_4)+2.0f*dCompass_b_z*(dEst_q_1*dEst_q_2+dEst_q_3*dEst_q_4)-dCompass_m_Norm_y);
dObjective_f_61=(2.0f*dCompass_b_x*(dEst_q_1*dEst_q_3 - dEst_q_2*dEst_q_4)+2.0f*dCompass_b_z*(0.5-dEst_q_2*dEst_q_2-dEst_q_3*dEst_q_3)-dCompass_m_Norm_z);

// Step 1.4 > Calculate Jacobian Matrix of Objective Function
dObjective_J_11=-2.0f*dEst_q_3;
dObjective_J_12= 2.0f*dEst_q_4;
dObjective_J_13=-2.0f*dEst_q_1;
dObjective_J_14= 2.0f*dEst_q_2;
dObjective_J_21= 2.0f*dEst_q_2;
dObjective_J_22= 2.0f*dEst_q_1;
dObjective_J_23= 2.0f*dEst_q_4;
dObjective_J_24= 2.0f*dEst_q_3;
dObjective_J_31= 0.0f;
dObjective_J_32=-4.0f*dEst_q_2;
dObjective_J_33=-4.0f*dEst_q_3;
dObjective_J_34= 0.0f;
dObjective_J_41=-2*dCompass_b_z*dEst_q_3;
dObjective_J_42=2*dCompass_b_z*dEst_q_4;
dObjective_J_43=-4*dCompass_b_x*dEst_q_3-2*dCompass_b_z*dEst_q_1;
dObjective_J_44=-4*dCompass_b_x*dEst_q_4+2*dCompass_b_z*dEst_q_2;
dObjective_J_51=-2*dCompass_b_x*dEst_q_4+2*dCompass_b_z*dEst_q_2;
dObjective_J_52=2*dCompass_b_x*dEst_q_3+2*dCompass_b_z*dEst_q_1;
dObjective_J_53=2*dCompass_b_x*dEst_q_2+2*dCompass_b_z*dEst_q_4;
dObjective_J_54=-2*dCompass_b_x*dEst_q_1+2*dCompass_b_z*dEst_q_3;
dObjective_J_61=2*dCompass_b_x*dEst_q_3;
dObjective_J_62=2*dCompass_b_x*dEst_q_4-4*dCompass_b_z*dEst_q_2;
dObjective_J_63=2*dCompass_b_x*dEst_q_1-4*dCompass_b_z*dEst_q_3;
dObjective_J_64=2*dCompass_b_x*dEst_q_2;

// Step 1.5 > Calculate Gradient of Objective Function
//dObjective_Grad_f_11=dObjective_J_11*dObjective_f_11 + dObjective_J_21*dObjective_f_21 + dObjective_J_31*dObjective_f_31 + dObjective_J_41*dObjective_f_41 + dObjective_J_51*dObjective_f_51 + dObjective_J_61*dObjective_f_61;
//dObjective_Grad_f_21=dObjective_J_12*dObjective_f_11 + dObjective_J_22*dObjective_f_21 + dObjective_J_32*dObjective_f_31 + dObjective_J_42*dObjective_f_41 + dObjective_J_52*dObjective_f_51 + dObjective_J_62*dObjective_f_61;
//dObjective_Grad_f_31=dObjective_J_13*dObjective_f_11 + dObjective_J_23*dObjective_f_21 + dObjective_J_33*dObjective_f_31 + dObjective_J_43*dObjective_f_41 + dObjective_J_53*dObjective_f_51 + dObjective_J_63*dObjective_f_61;
//dObjective_Grad_f_41=dObjective_J_14*dObjective_f_11 + dObjective_J_24*dObjective_f_21 + dObjective_J_34*dObjective_f_31 + dObjective_J_44*dObjective_f_41 + dObjective_J_54*dObjective_f_51 + dObjective_J_64*dObjective_f_61;

// Step 1.5 > Calculate Gradient of Objective Function
dObjective_Grad_f_11=dObjective_J_14*dObjective_f_21 + dObjective_J_11*dObjective_f_11 + dObjective_J_41*dObjective_f_41 + dObjective_J_51*dObjective_f_51 + dObjective_J_61*dObjective_f_61;
dObjective_Grad_f_21=dObjective_J_12*dObjective_f_11 + dObjective_J_22*dObjective_f_21 + dObjective_J_32*dObjective_f_31 + dObjective_J_42*dObjective_f_41 + dObjective_J_52*dObjective_f_51 + dObjective_J_62*dObjective_f_61;
dObjective_Grad_f_31=dObjective_J_12*dObjective_f_21 + dObjective_J_33*dObjective_f_31 + dObjective_J_13*dObjective_f_11 + dObjective_J_43*dObjective_f_41 + dObjective_J_53*dObjective_f_51 + dObjective_J_63*dObjective_f_61;
dObjective_Grad_f_41=dObjective_J_14*dObjective_f_11 + dObjective_J_24*dObjective_f_21 + dObjective_J_44*dObjective_f_41 + dObjective_J_54*dObjective_f_51 + dObjective_J_64*dObjective_f_61;



// Step 1.6 > Calculate Gradient Norm
dObjective_Grad_f_Norm=sqrt(dObjective_Grad_f_11*dObjective_Grad_f_11+dObjective_Grad_f_21*dObjective_Grad_f_21+dObjective_Grad_f_31*dObjective_Grad_f_31+dObjective_Grad_f_41*dObjective_Grad_f_41);

// Step 1.7 > Calculate Direction of Error for Estimated Rate of Change of Orientation
dEst_S_E_q_1_hat_dot=(dObjective_Grad_f_11/dObjective_Grad_f_Norm);
dEst_S_E_q_2_hat_dot=(dObjective_Grad_f_21/dObjective_Grad_f_Norm);
dEst_S_E_q_3_hat_dot=(dObjective_Grad_f_31/dObjective_Grad_f_Norm);
dEst_S_E_q_4_hat_dot=(dObjective_Grad_f_41/dObjective_Grad_f_Norm);

/*************************************************************************/
// Step 2: Gyroscope Bias Drift Compensation 
/*************************************************************************/

// Step 2.1 > Compute Angular Error of Each Gyroscope Axis
// Note Only Orientation Considered, Hence 2*dEst_q_1*dEst_S_E_q_1_hat_dot-2*dEst_q_2*dEst_S_E_q_2_hat_dot-2*dEst_q_3*dEst_S_E_q_3_hat_dot-2*dEst_q_4*dEst_S_E_q_4_hat_dot = 0
dGyro_w_x_Error=2*dEst_q_1*dEst_S_E_q_2_hat_dot-2*dEst_q_2*dEst_S_E_q_1_hat_dot-2*dEst_q_3*dEst_S_E_q_4_hat_dot+2*dEst_q_4*dEst_S_E_q_3_hat_dot;
dGyro_w_y_Error=2*dEst_q_1*dEst_S_E_q_3_hat_dot+2*dEst_q_2*dEst_S_E_q_4_hat_dot-2*dEst_q_3*dEst_S_E_q_1_hat_dot-2*dEst_q_4*dEst_S_E_q_2_hat_dot;
dGyro_w_x_Error=2*dEst_q_1*dEst_S_E_q_4_hat_dot-2*dEst_q_2*dEst_S_E_q_3_hat_dot+2*dEst_q_3*dEst_S_E_q_2_hat_dot+2*dEst_q_4*dEst_S_E_q_1_hat_dot;        

// Step 2.2 > Compute Gyroscope Bias
dGyro_w_x_Bias=dGyro_w_x_Bias+dGain_Zeta*dGyro_w_x_Error*dSample_Period_Delta_t;
dGyro_w_y_Bias=dGyro_w_y_Bias+dGain_Zeta*dGyro_w_y_Error*dSample_Period_Delta_t;
dGyro_w_z_Bias=dGyro_w_z_Bias+dGain_Zeta*dGyro_w_z_Error*dSample_Period_Delta_t;

// Step 2.3 > Calculate Compensated Gyroscope Measurements
dGyro_w_x=dGyro_w_x - dGyro_w_x_Bias;  
dGyro_w_y=dGyro_w_y - dGyro_w_y_Bias;
dGyro_w_z=dGyro_w_z - dGyro_w_z_Bias;

/*************************************************************************/
// Step 3: Compute Real Time Rate Quaternion from Gyro
/*************************************************************************/

// Step 3.1: > Calculate Quaternion Derivative for Rate of Change of 
// Orientation of Earth Frame Relative To Sensor Frame
dS_E_q_w_1_dot=0.5f*(-dEst_q_2*dGyro_w_x - dEst_q_3*dGyro_w_y - dEst_q_4*dGyro_w_z);
dS_E_q_w_2_dot=0.5f*( dEst_q_1*dGyro_w_x + dEst_q_3*dGyro_w_z - dEst_q_4*dGyro_w_y);
dS_E_q_w_3_dot=0.5f*( dEst_q_1*dGyro_w_y - dEst_q_2*dGyro_w_z + dEst_q_4*dGyro_w_x);
dS_E_q_w_4_dot=0.5f*(-dEst_q_1*dGyro_w_z + dEst_q_2*dGyro_w_y - dEst_q_3*dGyro_w_x);

// Step 3.2: > Carry out Numerical Integration of Quaternion Derivative
// Note: Step 4.2 Not required as "alpha" constant - Constant used to
// augment "mu" (stepsize) - is assumed >>> 0. 

/*************************************************************************/
// Step 4: Fusion of Accel / Gyro / Compass Sensor Data To Generate Increment Estimate
/*************************************************************************/
dEst_S_E_q_1_dot=(dS_E_q_w_1_dot - dGain_Beta*dObjective_Grad_f_11/dObjective_Grad_f_Norm);
dEst_S_E_q_2_dot=(dS_E_q_w_2_dot - dGain_Beta*dObjective_Grad_f_21/dObjective_Grad_f_Norm);
dEst_S_E_q_3_dot=(dS_E_q_w_3_dot - dGain_Beta*dObjective_Grad_f_31/dObjective_Grad_f_Norm);
dEst_S_E_q_4_dot=(dS_E_q_w_4_dot - dGain_Beta*dObjective_Grad_f_41/dObjective_Grad_f_Norm);

/*************************************************************************/
// Step 5: Numerical Integration of Quaternion Rate Data
/*************************************************************************/

// Step 5.1 > Carry Out Numerical Integration 
dEst_q_1=dEst_q_1+dEst_S_E_q_1_dot*dSample_Period_Delta_t;
dEst_q_2=dEst_q_2+dEst_S_E_q_2_dot*dSample_Period_Delta_t;
dEst_q_3=dEst_q_3+dEst_S_E_q_3_dot*dSample_Period_Delta_t;
dEst_q_4=dEst_q_4+dEst_S_E_q_4_dot*dSample_Period_Delta_t;

// Step 5.2 > Calculate Quaternion Norm
dEst_q_Norm = sqrt(dEst_q_1*dEst_q_1 + dEst_q_2*dEst_q_2 +dEst_q_3*dEst_q_3 +dEst_q_4*dEst_q_4);

/*************************************************************************/
// Step 6: Normalize and Output Quaternion Data
/*************************************************************************/
dEst_q_1 = dEst_q_1/dEst_q_Norm;
dEst_q_2 = dEst_q_2/dEst_q_Norm;
dEst_q_3 = dEst_q_3/dEst_q_Norm;
dEst_q_4 = dEst_q_4/dEst_q_Norm;

/*************************************************************************/
// Step 7: Switch Base Reference Frame If Needed
// Note: Represent quarternions as sensor attitude relative to fixed earth
// i.e d_Est_E_S_q_X where X = 1,2,3,4
/*************************************************************************/
/*
outQuat_q_1[0]=dEst_q_1;
outQuat_q_2[0]=-dEst_q_2;
outQuat_q_3[0]=-dEst_q_3;
outQuat_q_4[0]=-dEst_q_4;
*/
outQuat_q_1[0]=dEst_q_1;
outQuat_q_2[0]=dEst_q_2;
outQuat_q_3[0]=dEst_q_3;
outQuat_q_4[0]=dEst_q_4;

/*************************************************************************/
// Step 8: Compute Normalized Flux in Earth Frame 
/*************************************************************************/
// Step 8.1 Compute Flux in Earth Frame 
dCompass_h_x = 2*dCompass_m_Norm_x*(0.5f - dEst_q_3*dEst_q_3-dEst_q_4*dEst_q_4)+2*dCompass_m_Norm_y*(dEst_q_2*dEst_q_3-dEst_q_1*dEst_q_4)+2*dCompass_m_Norm_z*(dEst_q_2*dEst_q_4+dEst_q_1*dEst_q_3);
dCompass_h_y = 2*dCompass_m_Norm_x*(dEst_q_2*dEst_q_3+dEst_q_1*dEst_q_4)+2*dCompass_m_Norm_y*(0.5f-dEst_q_2*dEst_q_2-dEst_q_4*dEst_q_4)+2*dCompass_m_Norm_z*(dEst_q_3*dEst_q_4-dEst_q_1*dEst_q_2);
dCompass_h_z = 2*dCompass_m_Norm_x*(dEst_q_2*dEst_q_4-dEst_q_1*dEst_q_3)+2*dCompass_m_Norm_y*(dEst_q_3*dEst_q_4+dEst_q_1*dEst_q_2)+2*dCompass_m_Norm_z*(0.5f-dEst_q_2*dEst_q_2-dEst_q_3*dEst_q_3);

// Step 8.2 Normalize Flux in Earth Frame along X and Z axes.
dCompass_b_x = sqrt((dCompass_h_x*dCompass_h_x)+(dCompass_h_y*dCompass_h_y));
dCompass_b_z = dCompass_h_z;

// Output Quaternion Data
if (iDebug_Level >=Debug_Level_1) { printf("Quaternion Data> Q1: %.2f Q2: %.2f Q3: %.2f Q4: %.2f\n",outQuat_q_1[0],outQuat_q_2[0],outQuat_q_3[0],outQuat_q_4[0]);}


# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void BBB_AHRS_IMU_MARG_v1_Update_wrapper(const real_T *inGyro_w_x,
                          const real_T *inGyro_w_y,
                          const real_T *inGyro_w_z,
                          const real_T *inAccel_a_x,
                          const real_T *inAccel_a_y,
                          const real_T *inAccel_a_z,
                          const real_T *inCompass_m_x,
                          const real_T *inCompass_m_y,
                          const real_T *inCompass_m_z,
                          const real_T *outQuat_q_1,
                          const real_T *outQuat_q_2,
                          const real_T *outQuat_q_3,
                          const real_T *outQuat_q_4,
                          const boolean_T *outStopSim,
                          real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* Only Execute On Target*/
# ifndef MATLAB_MEX_FILE

// Recall Discrete State Data
// xD[0] = First Scan
// xD[1] = Estimated Quaternion dEst_q_1
// xD[2] = Estimated Quaternion dEst_q_2
// xD[3] = Estimated Quaternion dEst_q_3
// xD[4] = Estimated Quaternion dEst_q_4

if (xD[0]==0)
{
    // Initialize Quaternions
    
    // Set First Scan Bit
    xD[0]=1;
}

// Update Persistent Quaternion Data
xD[1]=outQuat_q_1[0];
xD[2]=outQuat_q_2[0];
xD[3]=outQuat_q_3[0];
xD[4]=outQuat_q_4[0];

xD[5]=dCompass_b_x;
xD[6]=dCompass_b_z;

// Update Gyro Bias Error
xD[7]=dGyro_w_x_Bias;
xD[8]=dGyro_w_y_Bias;  
xD[9]=dGyro_w_z_Bias;


# endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
