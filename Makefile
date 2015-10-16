main.o: main.cpp Node.h LinkedList.h wall.h wallPost.h user.h userNetwork.h
	g++ main.cpp wallPost.cpp wall.cpp user.cpp userNetwork.cpp

clean:
	rm main.o
