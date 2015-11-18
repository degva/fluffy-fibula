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
$(ODIR)/tbutton.o: $(LDIR)/tbutton.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Baraja...
# Enemigos y estructuras amigas
$(ODIR)/tentstr.o: $(LDIR)/tentstr.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# TMap things...
$(ODIR)/tspace.o: $(LDIR)/tspace.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/ttile.o: $(LDIR)/ttiles.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/tmap.o: $(LDIR)/tmap.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Menu things...
$(ODIR)/menu.o: $(LDIR)/menu.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Game program
$(ODIR)/capp.o: $(LDIR)/capp.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Main program
$(ODIR)/main.o: main.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

app: $(OBJS)
	$(GCC) -o $(BLD)/$@ $^ -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BLD)/app
