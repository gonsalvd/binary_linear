all: search

search: linear.o binary.o input-gen.o
	g++ -std=c++0x -o search linear.o input-gen.o binary.o

linear.o: linear.cpp linear.h
	g++ -c linear.cpp

input-gen.o: input-gen.cpp linear.h binary.h
	g++ -c input-gen.cpp

binary.o: binary.cpp binary.h
	g++ -c binary.cpp

clean:
	rm -rf *.o
	rm -rf search

    
    