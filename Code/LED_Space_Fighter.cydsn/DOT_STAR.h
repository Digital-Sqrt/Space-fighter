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

#ifndef DOT_STAR_H
    #define DOT_STAR_H

    #define HIGH_INTENSITY (uint8_t)0x1F
    #define MED_INTENSITY (uint8_t)0x14
    #define LOW_INTENSITY (uint8_t)0x0A
    #define UNUSED_111 (uint8_t)0x07;
    #define UNUSED_000 (uint8_t)0x00;
    #define LED_RED 0x00FF0000    
    #define LED_GREEN 0x0000FF00
    #define LED_BLUE 0x000000FF
    #define LED_YELLOW (LED_RED | LED_GREEN)
    #define LED_CYAN (LED_GREEN | LED_BLUE)
    #define LED_MAGENTA (LED_RED | LED_BLUE)
    #define LED_WHITE (LED_RED | LED_GREEN | LED_BLUE)    
    #define START_LED_CHAIN_COLOR  0xFFFFFFFF   
    #define END_LED_CHAIN_COLOR  0x00000000 
    #define START_OF_CHAIN_COUNT  (uint8_t)1
    #define END_OF_CHAIN_COUNT  (uint8_t)1
    #define START_OF_CHAIN_INDEX (uint8_t)0    
    
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
            uint8_t Count;
            union DotStarLed *DotStar; 
        }; 
        
        struct DisplayBuffer{
            uint16_t Count;
            uint16_t Index;            
            volatile uint8_t *Buffer; 
        };         
              
    extern struct LedChain BuildLedChain( uint8_t LedCount );
    extern void SetLedColor( struct LedChain *Chain, uint8_t Index, uint32_t Color, uint8_t Intensity);
    extern void SetLedHue( struct LedChain *Chain, uint8_t Index, uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Intensity);
#endif    

/* [] END OF FILE */
