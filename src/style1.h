#include <fontlibc.h>
#include <graphx.h>
#include <sys/rtc.h>

extern fontlib_font_t *momentum;

void style1Loop() {
  fontlib_SetTransparency(true);
  fontlib_SetColors(255, 0);
  uint8_t border = (60 - rtc_Seconds) * 4;
  fontlib_SetCursorPosition(63, 99);
  fontlib_SetFont(momentum, 0);
  if (rtc_Seconds) {
    gfx_SetColor(1);
    gfx_FillRectangle_NoClip(0, border, GFX_LCD_WIDTH, 4);
  } else {
    gfx_ZeroScreen();
  }
  if (rtc_Seconds >= 26 && rtc_Seconds < 36) {
    gfx_SetColor(1);
    gfx_FillRectangle_NoClip(63, border, 24 * 8, 139 - border);
    gfx_SetColor(0);
    gfx_FillRectangle_NoClip(63, 99, 24 * 8, border - 99);
  } else if (rtc_Seconds < 26) {
    gfx_SetColor(0);
    gfx_FillRectangle_NoClip(63, 99, 24 * 8, 40);
  } else {
    gfx_SetColor(1);
    gfx_FillRectangle_NoClip(63, 99, 24 * 8, 40);
  }

  fontlib_DrawInt(rtc_Hours, 2);
  fontlib_DrawString(":");
  fontlib_DrawInt(rtc_Minutes, 2);
  fontlib_DrawString(":");
  fontlib_DrawInt(rtc_Seconds, 2);
}

void style1Init() {
  gfx_ZeroScreen();
  gfx_SetColor(1);
  uint8_t border = (60 - rtc_Seconds) * 4;
  gfx_FillRectangle_NoClip(0, border, GFX_LCD_WIDTH, GFX_LCD_HEIGHT - border);
  style1Loop();
}
