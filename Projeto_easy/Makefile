OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++14 ${OBJFILES} -o main `pkg-config --cflags --libs opencv`