CC=gcc
#
IDIR=include
CFLAGS=-I$(IDIR) -Wall -g

ODIR=obj
SRC=src

_DEPS =  file_mgmt.h algorithm.h base.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  main.o file_mgmt.o algorithm.o base.o
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
