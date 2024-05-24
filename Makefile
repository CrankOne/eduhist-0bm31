# Shortcuts:
# 	$@ -- target name
# 	$^ -- list of dependencies

CXXFLAGS=$(shell geant4-config --cflags) -Iinclude

all: main.exe geant4-app

main.exe: main.o libeduhistogram.a
	g++ $^ -o $@

libeduhistogram.a: histogram1d.o histogram2d.o accept-reject-1d.o sphere-uniform.o
	ar -crs $@ $^

main.o: main.cc
	g++ -Iinclude -c main.cc -o $@

%.o: src/%.cc
	g++ -Iinclude -c $^ -o $@

#
# Geant4-specific

# Generic rule:
# 	- makes .o files in obj/ dir from eponymous .cc files from src/edu-g4
# 	- uses CXXFLAGS variable defined before in this Makefile
obj/%.o: src/edu-g4/%.cc
	g++ $(CXXFLAGS) -c -o $@ $^

# obj/main-g4.o doesn't match aforementioned naming rule, so we make it with
# a dedicated rule
obj/main-g4.o: main-g4.cc
	g++ $(CXXFLAGS) -c -o $@ $^

# App. linking recipe
# 	- calls g++, but provides a list of object files (instead of C++ sources)
# 	- has couple of shell commands embedded to substitute output for
# 	  compile options
# 	- has special option to specify runtime library search path
geant4-app: obj/ActionInitialization.o obj/DetectorConstruction.o obj/PrimaryGeneratorAction.o obj/main-g4.o
	g++ $^ $(shell geant4-config --libs) -o $@ -Wl,--disable-new-dtags,-rpath=$(shell geant4-config --prefix)/lib

# Virtual target to clean directories
clean:
	rm -f *.o
	rm -f libeduhistogram.a
	rm -f main.exe
	rm -f obj/*.o
	rm -f geant4-app

