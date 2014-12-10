all: teststring
	
teststring: teststring.cpp cstring.o
	g++ -g -o teststring teststring.cpp cstring.o
cstring.o: cstring.h cstring.cpp
	g++ -g -c -o cstring.o cstring.cpp
clean:
	rm *.o
mrproper:clean
	rm teststring

