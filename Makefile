all: system

system: src/systemcall.c src/fileoperations.c
	gcc -o out/system src/systemcall.c src/fileoperations.c

clean:
	rm -rf *.o out/*
