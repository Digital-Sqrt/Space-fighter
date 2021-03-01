/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cytypes.h"
#include <stdbool.h>
#include <Frame_Timer.h>


uint16_t DelayTime;

void TimerSet(uint16_t TimeInmSec){
    DelayTime = TimeInmSec;
};

void WaitForFrameDone(void){
    uint16_t StartTime;
    
    StartTime = Frame_Timer_ReadCounter();
    
    do {} while(DelayTime > (StartTime - Frame_Timer_ReadCounter()) );    
};



/* [] END OF FILE */