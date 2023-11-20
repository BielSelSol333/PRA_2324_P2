bin/testCambio: monedas.cpp testCambio.cpp
	mkdir bin
	g++ -o bin/testCambio monedas.cpp testCambio.cpp

clear:
	rm -rf *.o bin
