
all: main.exe

main.exe: main.o libeduhistogram.a
	g++ main.o libeduhistogram.a -o ./main.exe

libeduhistogram.a: histogram1d.o histogram2d.o
	ar -crs libeduhistogram.a histogram1d.o histogram2d.o

main.o: main.cc
	g++ -Iinclude -c main.cc -o main.o

histogram1d.o: src/histogram1d.cc
	g++ -Iinclude -c src/histogram1d.cc -o histogram1d.o

histogram2d.o: src/histogram2d.cc
	g++ -Iinclude -c src/histogram2d.cc -o histogram2d.o

clean:
	rm -f *.o
	rm -f main.exe

