main.o: main.cpp Node.h LinkedList.h wall.h wallPost.h
	g++ main.cpp wallPost.cpp wall.cpp

clean:
	rm main.o
