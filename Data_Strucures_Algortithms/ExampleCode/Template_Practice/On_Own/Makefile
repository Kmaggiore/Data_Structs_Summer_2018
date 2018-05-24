a4: temp2App.o
	g++ temp2App.o -o a4

sequenceTest.o: temp2App.cpp temp2Imp.hpp temp2Int.h
	g++ -Wall -ansi -pedantic -c temp2App.cpp

test:
	./a4 auto < a4test.in > a4test.out
clean:
	@rm -rf sequenceTest.o
cleanall:
	@rm -rf sequenceTest.o a4
