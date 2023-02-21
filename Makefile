all: main
	g++ -Wall -o main main.cpp
clean:
	rm main
run:
	./main
