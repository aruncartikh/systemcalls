all: system

system: src/systemcall.c
	gcc -o out/system src/systemcall.c

clean:
	rm -rf *.o out/*
