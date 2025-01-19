all: CLOCKFNT.8xv

fonts = default.convfont menu.convfont momentum.convfont
temp.bin: $(fonts)
	convfont -o fontpack -N "MOMEMTUM" -P "ASCII" -V "1" -A "Melon" \
	-D "Fonts for a clock app" \
	-t momentum.convfont \
	-t default.convfont \
	-t menu.convfont \
	temp.bin

CLOCKFNT.8xv: temp.bin
	convbin -i temp.bin -o CLOCKFNT.8xv -n CLOCKFNT -j bin -k 8xv && mkdir -p bin && mv CLOCKFNT.8xv temp.bin ./bin
