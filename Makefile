all: system

system: src/systemcall.c src/fileoperations.c src/menu.c
	gcc -o out/system src/systemcall.c src/fileoperations.c src/menu.c

clean:
	rm -rf *.o out/*
