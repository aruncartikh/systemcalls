all: system learning

system: src/systemcall.c src/fileoperations.c src/menu.c
	gcc -o out/system src/systemcall.c src/fileoperations.c src/menu.c

learning: src/learn.c
	gcc -o out/learn src/learn.c
clean:
	rm -rf *.o out/*
