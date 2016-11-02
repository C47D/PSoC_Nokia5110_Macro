#include <project.h>
#include "display.h"
#include "bitmap.h"

#include "stdlib.h"

int main()
{
    int i = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    NOKIA_Init(back1);
    NOKIA_Contrast(0x39);
    
    NOKIA_Goto(3, 0);
    NOKIA_BigStr("Cypress", DRAW_OR);
    NOKIA_Goto(3, 3);
    NOKIA_Str("PSoC4S &", DRAW_OR, Middle_Font);
    NOKIA_Goto(6, 4);
    NOKIA_Str("Nokia5110", DRAW_OR, Middle_Font);
    
    CyDelay(1000);
    NOKIA_Clear();
    
    char dataPtr[10];
    uint8_t z = 90;
    itoa(z, dataPtr, 10);
    NOKIA_Goto(3, 0);
    NOKIA_Str(dataPtr, DRAW_XOR, Middle_Font);
    CyDelay(2500);
    NOKIA_Clear();
    
    NOKIA_SetBackground(back2);
    
    NOKIA_Goto(10,1);
    NOKIA_Str("OVER", DRAW_XOR, Middle_Font);
    NOKIA_Goto(10, 2);
    NOKIA_Str("BACKGROUND", DRAW_XOR, Middle_Font);
    CyDelay(2000);
    
    NOKIA_SetBackground(back1);
    
    for(i=0;i<45;i++)
    {
        NOKIA_HBargraph(1, 5, 50,i, DRAW_OR);
        CyDelay(10);
    }
    CyDelay(2000);
    
    NOKIA_Clear();
    
    for(i=0;i<25;i++)
    {
        NOKIA_VBargraph(10, 2, 4, i, DRAW_OR);
        CyDelay(10);
    }
    CyDelay(2000);
    
    NOKIA_SetBackground(back1);
    
    for(i=0;i<45;i++)
    {
        NOKIA_HBargraph(1, 5, 50, i, DRAW_OR);
        CyDelay(10);
    }

    for(;;)
    {
        
    }
}



/* [] END OF FILE */
