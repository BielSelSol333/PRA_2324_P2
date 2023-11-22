bin/testDyV: testDyV.cpp
	mkdir -p bin
	g++ -o bin/testDyV testDyV.cpp

bin/testCambio: monedas.cpp testCambio.cpp
	mkdir -p bin
	g++ -o bin/testCambio monedas.cpp testCambio.cpp

bin/testMochila: mochila_I.cpp
	mkdir -p bin
	g++ -o bin/testMochila mochila_I.cpp

clear:
	rm -rf *.o bin
