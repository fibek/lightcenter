EXEC := lightcenter

PKG := `pkg-config gtkmm-3.0 --cflags --libs`
RM := rm 
CP := cp


CC := g++

OPT := -I./inc

SDIR := ./src
COREDIR := ./core
INSDIR := ~/bin

SRC := $(wildcard $(SDIR)/*.cpp)
CORE := $(wildcard $(COREDIR)/*.cpp)

all: $(EXEC)

$(EXEC): 
	@$(CC) $(SRC) $(CORE) $(OPT) -o $@ $(PKG) 



clean:
	@$(RM) $(EXEC)

install: 
	@$(CP) $(EXEC) $(INSDIR)
