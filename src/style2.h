#include <graphx.h>
#include <math.h>
#include <sys/rtc.h>

double _sAngle = 0;
double _mAngle = 0;
double _hAngle = 0;

void style2Loop() {
  double sAngle = M_PI_2 - (double)rtc_Seconds * M_PI / 30;
  double mAngle = M_PI_2 - (double)rtc_Minutes * M_PI / 30 -
                  (double)rtc_Seconds * M_PI / 1800;
  double hAngle =
      M_PI_2 - (double)rtc_Hours * M_PI / 6 - (double)rtc_Minutes * M_PI / 360;
  gfx_SetColor(0);
  if (hAngle != _hAngle) {
    gfx_Line(159, 119, cos(_hAngle) * 80 + 159, -sin(_hAngle) * 80 + 119);
  }
  gfx_Line(159, 119, cos(_mAngle) * 105 + 159, -sin(_mAngle) * 105 + 119);
  gfx_Line(159, 119, cos(_sAngle) * 108 + 159, -sin(_sAngle) * 108 + 119);
  gfx_SetColor(4);
  gfx_Line(159, 119, cos(sAngle) * 108 + 159, -sin(sAngle) * 108 + 119);
  gfx_SetColor(3);
  gfx_Line(159, 119, cos(mAngle) * 105 + 159, -sin(mAngle) * 105 + 119);
  gfx_SetColor(2);
  gfx_Line(159, 119, cos(hAngle) * 80 + 159, -sin(hAngle) * 80 + 119);
  _sAngle = sAngle;
  _mAngle = mAngle;
  _hAngle = hAngle;
}

void style2Init() {
  gfx_ZeroScreen();
  gfx_SetColor(1);
  gfx_Circle(159, 119, 120);
  gfx_SetColor(2);
  uint8_t i;
  for (i = 0; i < 60; i++) {
    double angle = i * M_PI / 30;
    double y = sin(angle);
    double x = cos(angle);
    if (i % 5) {
      gfx_Line(x * 118 + 159, y * 118 + 119, x * 120 + 159, y * 120 + 119);
    } else {
      gfx_Line(x * 112 + 159, y * 112 + 119, x * 120 + 159, y * 120 + 119);
    }
  }
  style2Loop();
}
