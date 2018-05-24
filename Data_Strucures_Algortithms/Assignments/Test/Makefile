a4: sequenceTest.o
	g++ -o a4 sequenceTest.o

sequenceTest.o: sequenceTest.cpp sequence.hpp sequence.h
	g++ -Wall -ansi -pedantic -c sequenceTest.cpp

test:
	./a4 auto < a4test.in > a4test.out
clean:
	@rm -rf sequenceTest.o
cleanall:
	@rm -rf sequenceTest.o a4
