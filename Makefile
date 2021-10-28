knotty: knotty.cpp
	g++ knotty.cpp -o knotty -Wall -ggdb3
	./knotty <knot.pts >knot.pov
	povray -W1024 -H768 +A0.3 knot.pov
