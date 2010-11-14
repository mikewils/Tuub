

pix_scanned.pd_linux: pix_scanned.cpp pix_scanned.h
	g++ pix_scanned.cpp -shared -I../gem-0.92-3/src -I /usr/include/pd -o $@  