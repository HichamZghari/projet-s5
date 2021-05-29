CFLAGS = -Wall -Wextra -std=c99  -ggdb -lm

all: project

project: good.o  stockex.o queue.o initialisation.o project-0.o
	gcc $^ -o project $(CFLAGS)

good.o: src/good.c src/good.h
	gcc -c $(CFLAGS) src/good.c

stockex.o: src/stockex.c src/stockex.h src/transac.h
	gcc -c $(CFLAGS) src/stockex.c

queue.o: src/queue.c src/queue.h
	gcc -c $(CFLAGS) src/queue.c

initialisation.o:src/initialisation.h src/transac.h src/stockex.c src/stockex.h src/good.h src/queue.h 
	gcc -c $(CFLAGS) src/initialisation.c

project-0.o: src/project-0.c src/initialisation.h src/queue.h src/stockex.h src/good.h 
	gcc -c $(CFLAGS) src/project-0.c

test: test-ach0

test-ach0:good.o queue.o stockex.o test-0.o initialisation.o
	gcc $^ -o test $(CFLAGS) && ./test

test-0.o: tst/test-0.c src/queue.h src/stockex.h src/good.h src/initialisation.h 
	gcc -c $(CFLAGS) tst/test-0.c 


clean:
	rm -f project test good stockex stockex.o good.o project-0.o queue.o initialisation.o test-0.o
