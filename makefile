GCC=gcc
#CFLAGS=-g -Wall -Wextra
CFLAGS=-g
LINKER_FLAGS=-lSDL2 -lSDL2_ttf

LDIR=libs
ODIR=objs
BLD=builds


#OBJS specifies which files to compile as part of the project 
_OBJS = main.o capp.o tmap.o menu.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

$(ODIR)/tmap.o: $(LDIR)/tmap.c $(LDIR)/tmap.h
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

$(ODIR)/menu.o: $(LDIR)/menu.c $(LDIR)/menu.h
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

$(ODIR)/capp.o: $(LDIR)/capp.c $(LDIR)/capp.h $(ODIR)/tmap.o $(ODIR)/menu.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

$(ODIR)/main.o: main.c $(ODIR)/menu.o $(ODIR)/capp.o $(ODIR)/tmap.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

app: $(OBJS)
	$(GCC) -o $(BLD)/$@ $^ -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BLD)/app
