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

#ifndef DOT_STAR_H
    #define DOT_STAR_H
    
    #include "cytypes.h"

    #define HIGH_INTENSITY 0xFF000000; // 31
    #define MED_INTENSITY 0xF4000000;  // 20  
    #define LOW_INTENSITY 0xEA000000;  // 10  
    #define LED_RED 0x00FF0000    
    #define LED_GREEN 0x0000FF00
    #define LED_BLUE 0x000000FF
    #define LED_YELLOW (LED_RED | LED_GREEN)
    #define LED_CYAN (LED_GREEN | LED_BLUE)
    #define LED_MAGENTA (LED_RED | LED_BLUE)
    #define BUFFER_LOCKED = 1
    #define BUFFER_UNLOCKED = 2
        
    #pragma pack()
        struct OneLed {
            uint8_t Unused : 3;
            uint8_t Intensity : 5;
            uint8_t Red;
            uint8_t Green;
            uint8_t Blue;
        };
        
        union DotStarLed {
            uint32_t Color;
            struct OneLed LED;
        };    
        
        struct LedChain {
            uint8_t count;
            union DotStarLed *DotStar; 
        };     
      
        struct Livebuffer{
            volatile uint8_t Lock;
            struct LedChain *Buffer; 
        };
        
        struct LiveDisplay{
            volatile uint8_t ActiveBuffer;
            uint16_t rate;
            struct Livebuffer *Display[2]; 
            struct Livebuffer *SyncBuffer; 
        };         
    
#endif    

/* [] END OF FILE */
