all: build run_fib

clear:
	rm *.txt
	rm run

build:
	g++ -std=c++11 main.cpp -o run -lgmpxx -lgmp -fopenmp

run_fib:
	clear
	./run
	python3 graphics.py

install_lib:
	sudo apt update
	sudo apt install libgmp3-dev
	sudo apt install python3-numpy
	sudo apt install python3-matplotlib
