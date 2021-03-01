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
#include <stdio.h>
#include <stdlib.h>
#include "DOT_STAR.h"
#include "cytypes.h"

extern struct LedChain BuildLedChain( uint8_t LedCount ){
    struct LedChain *ChainPtr;
    union DotStarLed *LedPtr;

    ChainPtr = (struct LedChain *)malloc(sizeof(struct LedChain));
    ChainPtr->Count = LedCount + START_OF_CHAIN_COUNT + END_OF_CHAIN_COUNT;
    ChainPtr->DotStar = (union DotStarLed *) malloc(ChainPtr->Count * sizeof(union DotStarLed));

    (ChainPtr+START_OF_CHAIN_INDEX)->DotStar->Color = START_LED_CHAIN_COLOR;
    
    (ChainPtr->DotStar)->Color = START_LED_CHAIN_COLOR;
    for (uint8_t Index=1; Index < ChainPtr->Count-1; Index++){
      (ChainPtr->DotStar+Index)->Color = LED_WHITE;
      (ChainPtr->DotStar+Index)->LED.Intensity = (0x1F & MED_INTENSITY);
      (ChainPtr->DotStar+Index)->LED.Unused = UNUSED_111; 
    }
    (ChainPtr->DotStar+(ChainPtr->Count-1))->Color = END_LED_CHAIN_COLOR;
    
    return *ChainPtr;
};

extern void LedSetColor( struct LedChain *Chain, uint8_t Index, uint32_t Color, uint8_t Intensity){
    if( Index >= Chain->Count ){/*Throw an error*/}
    
    (Chain->DotStar+Index)->Color = Color;
    (Chain->DotStar+Index)->LED.Intensity = (0x1F & Intensity);
};

extern void SetLedHue( struct LedChain *Chain, uint8_t Index, uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Intensity){
    if( Index >= Chain->Count ){/*Throw an error*/}
    
    (Chain->DotStar+Index)->LED.Red = Red;
    (Chain->DotStar+Index)->LED.Green = Green;
    (Chain->DotStar+Index)->LED.Blue = Blue;
    (Chain->DotStar+Index)->LED.Intensity = (0x1F & Intensity);
};
  
/* [] END OF FILE */
