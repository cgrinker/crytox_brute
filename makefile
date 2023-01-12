


all:
	mkdir -p bin
	gcc -Isrc -c -lcrypto cli/brute.c src/crytox.h src/crytox.c
	gcc -o bin/crytox_brute brute.o crytox.o
	
	gcc -Isrc -c -lcrypto cli/keygen.c src/crytox.h src/crytox.c
	gcc -o bin/crytox_keygen keygen.o crytox.o

	rm *.o

clean:
	rm -rf bin