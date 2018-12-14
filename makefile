top_dir = .

GCCOBJ = gcc -c
GCCLNK = gcc

fich_hadamard = hadamard.o canal.o prog_central.o

hadamard : $(fich_hadamard)
	$(GCCLNK) $(fich_hadamard) $(opt) -o hadamard -I ./

HDBn : HDBn.o
	$(GCCLNK) HDBn.o $(opt) -o HDBn -I ./




hadamard.o : hadamard.c
	$(GCCOBJ) $(opt) hadamard.c -o hadamard.o -I ./
canal.o : canal.c
	$(GCCOBJ) $(opt) canal.c -o canal.o -I ./
prog_central.o : prog_central.c
	$(GCCOBJ) $(opt) prog_central.c -o prog_central.o -I ./

HDBn.o : HDBn.c
	$(GCCOBJ) $(opt) HDBn.c -o HDBn.o -I ./


clean :
	rm -f *.o

all :   hadamard

tags :
	etags *.c
