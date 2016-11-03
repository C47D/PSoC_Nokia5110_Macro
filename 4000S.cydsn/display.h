#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "fonts.h"

#include "cytypes.h"
    
/* PSoC Component only */
#define SET_RST_PIN     0x01 /* RST pin is on the first bit of the Control Register */
#define CLEAR_RST_PIN   0x00
#define SET_DC_PIN      0x02 /* DC pin is in the second bit of the Control Register */
#define CLEAR_DC_PIN    0x00
    
#define CLEAR_RST_CLEAR_DC  (CLEAR_RST_PIN | CLEAR_DC_PIN)
#define SET_RST_CLEAR_DC    (SET_RST_PIN | CLEAR_DC_PIN)
#define SET_RST_SET_DC      (SET_RST_PIN | SET_DC_PIN)
#define CLEAR_RST_SET_DC    (CLEAR_RST_PIN | SET_DC_PIN)

/***************************************************************************
* DRAW_OVER_BACKGROUND: Compiler directive that allow using backgroung under
* painting, this feature is enabled by default, to disable it
* comment it //#define DRAW_OVER_BACKGROUND below
***************************************************************************/
#define DRAW_OVER_BACKGROUND


#ifdef DRAW_OVER_BACKGROUND

static const char *Background;

typedef enum{
    DRAW_OR = 0,
    DRAW_XOR = 1,
    DRAW_CLEAR = 2
}DRAW_TYPE_t;

#endif // DRAW_OVER_BACKGROUND

typedef enum{
    Small_Font = 0,
    Middle_Font = 1
}FONT_TYPE_t;

/***************************************************************************
* Function prototypes
***************************************************************************/

#ifdef DRAW_OVER_BACKGROUND
void NOKIA_Init(const char* dataPtr);
void NOKIA_SetBackground(const char* dataPtr);
void NOKIA_Chr(char ch, DRAW_TYPE_t dtype, FONT_TYPE_t ftype);
void NOKIA_Str(const char* dataPtr, DRAW_TYPE_t dtype, FONT_TYPE_t ftype);
void NOKIA_BigStr(char* dataPtr, DRAW_TYPE_t dtype);
void NOKIA_VBargraph(uint8_t x, uint8_t ystart, uint8_t yend, uint8_t yposition, DRAW_TYPE_t dtype);
void NOKIA_HBargraph(uint8_t y, uint8_t xstart, uint8_t xend, uint8_t xposition, DRAW_TYPE_t dtype);
void NOKIA_Line(uint8_t xb, uint8_t yb, uint8_t xe, uint8_t ye, DRAW_TYPE_t dtype);
#else /* DRAW_OVER_BACKGROUND */
void NOKIA_Init(void);
void NOKIA_Chr(char ch, FONT_TYPE_t ftype);
void NOKIA_Str(const char* dataPtr, FONT_TYPE_t ftype);
void NOKIA_VBargraph(uint8_t x, uint8_t ystart, uint8_t yend, uint8_t yposition);
void NOKIA_HBargraph(uint8_t y, uint8_t xstart, uint8_t xend, uint8_t xposition);
void NOKIA_Line (uint8_t xb, uint8_t yb, uint8_t xe, uint8_t ye);
#endif /* DRAW_OVER_BACKGROUND */

void NOKIA_Clear(void);
void NOKIA_Contrast(uint8_t contrast);
void NOKIA_Goto(uint8_t column, uint8_t row);
void NOKIA_Image(uint8_t x, uint8_t y, uint8_t xsize, uint8_t ysize, const char* dataPtr);
void NOKIA_SendData(uint8_t data);
void NOKIA_SendCommand(uint8_t command);

#endif // NOKIA_DISPLAY_H_