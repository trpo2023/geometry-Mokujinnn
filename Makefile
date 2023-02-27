all:
	g++ -Wall -o geometry main.cpp
clean:
	rm geometry
run:
	./geometry input.txt
