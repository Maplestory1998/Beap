
Test : test.o Binaryheap.o beap.o
	g++ -o main test.o beap.o Binaryheap.o -std=c++11

Binaryheap.o: Binaryheap.cpp Binaryheap.h
	g++ -c Binaryheap.cpp -std=c++11

beap.o: beap.cpp beap.h
	g++ -c beap.cpp -std=c++11
test.o: test.cpp beap.h Binaryheap.h
	g++ -c test.cpp -std=c++11

clean:
	rm main *o	