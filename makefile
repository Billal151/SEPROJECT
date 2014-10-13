out : reAD.o Quick.o
	g++ -std=c++0x reAD.o Quick.o -o out -lgdbm

reAD.o : reAD.cpp head.h
	g++ -std=c++0x -c reAD.cpp -lgdbm

Quick.o : Quick.cpp head.h
	g++ -std=c++0x -c Quick.cpp -lgdbm

clean :
	rm -rf myDB *.o out lab3Output.txt
