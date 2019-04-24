all: filtro run

filtro: filtro.cpp Image.cpp image.h
	g++ -o filtro filtro.cpp Image.cpp
run:
	./filtro

.PHONY: clean
clean:	
	clean rm -rf filtro
