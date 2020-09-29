all:
	g++ ./src/*.cpp -I./include/ -o ./bin/entrenador

run:
	./bin/entrenador

clean:
	clear
	rm -r ./bin/entrenador