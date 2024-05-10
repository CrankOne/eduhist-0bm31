
# $@ -- target name
# $^ -- list of dependencies

all: main.exe

main.exe: main.o libeduhistogram.a
	g++ $^ -o $@

libeduhistogram.a: histogram1d.o histogram2d.o accept-reject-1d.o sphere-uniform.o
	ar -crs $@ $^

main.o: main.cc
	g++ -Iinclude -c main.cc -o $@

histogram1d.o: src/histogram1d.cc
	g++ -Iinclude -c $^ -o $@

histogram2d.o: src/histogram2d.cc
	g++ -Iinclude -c $^ -o $@

accept-reject-1d.o: src/accept-reject-1d.cc
	g++ -Iinclude -c $^ -o $@

sphere-uniform.o: src/sphere-uniform.cc
	g++ -Iinclude -c $^ -o $@

clean:
	rm -f *.o
	rm -f libeduhistogram.a
	rm -f main.exe

