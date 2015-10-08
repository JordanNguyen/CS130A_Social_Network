main.o: main.cpp Node.h LinkedList.h
	g++ main.cpp

clean:
	rm main.o