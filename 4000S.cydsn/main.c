#include <project.h>
#include "display.h"
#include "bitmap.h"

int main()
{
    int i = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    NOKIA_Init(back1);
    NOKIA_Contrast(0x39);
    
    NOKIA_Goto(3, 0);
    NOKIA_BigStr("Cypress", DRAW_OR);
    NOKIA_Goto(3,2);
    NOKIA_Str("PSoC5LP & Nokia5110", DRAW_OR, Middle_Font);
    NOKIA_Goto(3,4);
    NOKIA_Str("Ejemplo0123456789", DRAW_OR, Small_Font);
    NOKIA_Goto(3,5);
    NOKIA_Str("EjemploConfig", DRAW_OR, Middle_Font);
    
    CyDelay(2000);
    
    NOKIA_SetBackground(back2);
    NOKIA_Clear();
    
    NOKIA_Goto(10,1);
    NOKIA_Str("OVER", DRAW_XOR, Middle_Font);
    NOKIA_Goto(10, 2);
    NOKIA_Str("BACKGROUND", DRAW_XOR, Middle_Font);
    CyDelay(2000);
    
    NOKIA_SetBackground(back1);
    NOKIA_Clear();
    
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
    NOKIA_Clear();
    
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
