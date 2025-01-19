# ----------------------------
# Makefile Options
# ----------------------------

NAME = CLOCK
ICON = icon.png
DESCRIPTION = "Clock Using RTC"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
