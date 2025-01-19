#include <fontlibc.h>
#include <graphx.h>

extern fontlib_font_t *glyph, *system;

void drawMenu(uint8_t style) {
  fontlib_SetTransparency(false);
  fontlib_SetFont(glyph, 0);
  fontlib_SetColors(148, 0);
  fontlib_SetCursorPosition(2, 222);
  // Text is weird to bypass required characters in fontlibc
  fontlib_DrawString("01120112");
  fontlib_SetFont(system, 0);
  if (style == 1) {
    fontlib_SetColors(0, 148);
  }
  fontlib_SetCursorPosition(10, 225);
  // DIGI
  fontlib_DrawString("0121");
  if (style == 2) {
    fontlib_SetColors(0, 148);
  } else {
    fontlib_SetColors(148, 0);
  }
  fontlib_SetCursorPosition(73, 225);
  // ANLG
  fontlib_DrawString("3452");
  gfx_BlitBuffer();
}
