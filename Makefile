all: teststring
	
teststring: teststring.cpp cstring.o
	g++ -o teststring.o teststring.cpp cstring.o
cstring.o: cstring.h cstring.cpp
	g++ -c -o cstring.o cstring.cpp
clean:
	rm *.o
go:
	./teststring.o
