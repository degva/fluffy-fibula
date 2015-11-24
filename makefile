GCC=gcc
#CFLAGS=-g -Wall -Wextra
CFLAGS=-g
LINKER_FLAGS=-lSDL2 -lSDL2_ttf -lSDL2_image

LDIR=libs
ODIR=objs
BLD=builds


#OBJS specifies which files to compile as part of the project
_OBJS = main.o capp.o menu.o tmap.o ttile.o tspace.o tbutton.o tentstr.o sidemenu.o mano.o action.o discard.o carta.o tlist.o theroe.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: app

# Heroe
$(ODIR)/theroe.o: $(LDIR)/theroe.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# General stuff
$(ODIR)/tbutton.o: $(LDIR)/tbutton.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Baraja...
$(ODIR)/tlist.o: $(LDIR)/tlist.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/carta.o: $(LDIR)/carta.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/discard.o: $(LDIR)/discard.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/action.o: $(LDIR)/action.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)
$(ODIR)/mano.o: $(LDIR)/mano.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

# Side Menu
$(ODIR)/sidemenu.o: $(LDIR)/sidemenu.c
	$(GCC) -o $@ -c $< -I$(LDIR) $(CFLAGS) $(LINKER_FLAGS)

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
