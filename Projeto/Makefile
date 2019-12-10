IDIR = ./inc
CC=gcc
RM = rm -rf
TARGET = mathspeaker
ODIR = ./obj/x86_64
CFLAGS =  -I$(IDIR)  -D ARCH_ARM_CORTEX_AX -pg -g3
SRCTOPDIR = ./src

SRC += $(SRCTOPDIR)/num_recog.c
SRC += $(SRCTOPDIR)/calc_gen.c
SRC += $(SRCTOPDIR)/main.c
OBJS = $(patsubst $(SRCTOPDIR)/%,$(ODIR)/bin/%,$(SRC:.c=.o))
	
.PHONY: all
all: ${TARGET}

$(TARGET): 
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(SRC) -o $(ODIR)/$(TARGET) -lm -lpthread


.PHONY: clean
clean:
	-${RM} $(ODIR)/*
