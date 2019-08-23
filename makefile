#--------------------------------------------------------------------------------------------
# Simple makefile for statistics program build system
#
# use: make [targets] [overrides]
#
# Targets:
#		<FILE>.o - Builds <FILE>.o object file
#		build - Builds and links all source files
#		all -  Same as build
#		clean - Removes all generated files
#
include sources.mk 

# Overrides

#Compile Defines
BASENAME = stats
TARGET = $(BASENAME).out

OBJS = $(SRCS:.c=.o)

%.o : %.c
		gcc -c $< -o $@

.PHONY: all
build: all

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
		gcc $(OBJS) -o $@

.PHONY: clean
clean: 
		rm -f $(OBJS) $(TARGET) $(BASENAME).map

#Stats Target Executable
#stats.out: stats.o
#	gcc -o stats.out stats.o
#
#stats.o target binary
#stats.o: stats.h stats.c
#	gcc -c -o stats.o stats.c