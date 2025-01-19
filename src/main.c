#include "menu.h"
#include "style1.h"
#include "style2.h"
#include <fileioc.h>
#include <fontlibc.h>
#include <graphx.h>
#include <keypadc.h>
#include <sys/rtc.h>
#include <sys/util.h>
#include <ti/screen.h>

uint8_t style = 1;
fontlib_font_t *momentum, *system, *glyph;

int main(void) {
  os_ClrHome();

  /* Load Fonts */
  uint8_t file = ti_Open("CLOCKFNT", "r");
  fontlib_font_pack_t *fontPack = ti_GetDataPtr(file);
  momentum = fontlib_GetFontByIndexRaw(fontPack, 0);
  system = fontlib_GetFontByIndexRaw(fontPack, 1);
  glyph = fontlib_GetFontByIndexRaw(fontPack, 2);
  if (!momentum) {
    gfx_PrintStringXY("CLOCKFNT appvar not found or invalid", 0, 0);
    gfx_End();
    return 1;
  }
  ti_Close(file);

  /* Start graphx */
  gfx_Begin();
  gfx_SetDrawBuffer();

  /* Setup Palette */
  gfx_palette[1] = gfx_RGBTo1555(47, 50, 47);
  gfx_palette[2] = gfx_RGBTo1555(95, 98, 95);
  gfx_palette[3] = gfx_RGBTo1555(255, 255, 255);
  gfx_palette[4] = gfx_RGBTo1555(197, 52, 0);

  /* Call default init and menu */
  style1Init();
  drawMenu(style);
  // Note: I am calling gfx_BlitBuffer() inside of the menu function because its
  // more code efficient

  /* Prepare rtc */
  rtc_Enable(RTC_SEC_INT);
  while (rtc_IsBusy())
    ;
  rtc_AckInterrupt(RTC_INT_MASK);

  /* Execute until Clear or Mode(quit) is pressed */
  while (!((kb_Data[6] & kb_Clear) || (kb_Data[1] & kb_Mode))) {

    /* Check if the style should be changed */
    if (kb_AnyKey()) {
      if (kb_Data[1] & kb_Yequ) {
        style = 1;
        style1Init();
      } else if (kb_Data[1] & kb_Window) {
        style = 2;
        style2Init();
      }
      drawMenu(style);
    }

    /* Run the loop of the current style */
    if (rtc_ChkInterrupt(RTC_SEC_INT)) {
      switch (style) {
      case 1:
        style1Loop();
        break;
      case 2:
        style2Loop();
        break;
      }
      drawMenu(style);
      rtc_AckInterrupt(RTC_SEC_INT);
    }
  }
  gfx_End();
  /* Return 0 for success */
  return 0;
}
