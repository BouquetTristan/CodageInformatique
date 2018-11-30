top_dir = .

GCCOBJ = gcc -c
GCCLNK = gcc

canal : canal.o
	$(GCCLNK) canal.o $(opt) -o canal -I ./

canal.o : canal.c
	$(GCCOBJ) $(opt) canal.c -o canal.o -I ./


clean :
	rm -f *.o

all :   canal

tags :
	etags *.c
