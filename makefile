GCC=gcc
#CFLAGS=-g -Wall -Wextra
CFLAGS=-g
LINKER_FLAGS=-lSDL2 -lSDL2_ttf -lSDL2_image

LDIR=libs
ODIR=objs
BLD=builds


#OBJS specifies which files to compile as part of the project 
_OBJS = main.o capp.o menu.o tmap.o ttile.o tspace.o tbutton.o tentstr.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

# General stuff
$(ODIR)/tbutton.o: $(LDIR)/tbutton.c $(LDIR)/tbutton.h
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Baraja...
# Enemigos y estructuras amigas
$(ODIR)/tentstr.o: $(LDIR)/tentstr.c $(LDIR)/tentstr.h
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# TMap things...
$(ODIR)/tspace.o: $(LDIR)/tspace.c $(LDIR)/tspace.h $(ODIR)/tentstr.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/ttile.o: $(LDIR)/ttiles.c $(LDIR)/ttiles.h $(ODIR)/tspace.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/tmap.o: $(LDIR)/tmap.c $(LDIR)/tmap.h $(ODIR)/ttile.o
	$(GCC) -c -o $@ $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Menu things...
$(ODIR)/menu.o: $(LDIR)/menu.c $(LDIR)/menu.h $(ODIR)/tbutton.o
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
