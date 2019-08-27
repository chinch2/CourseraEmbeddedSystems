#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This is the makefile for the Assessment m2 of the course. makefile for two target
# platforms with their compilers: Host machine and the microcontroller MSP432. 
# Host machine compiler command: gcc
# Target embedded system will be compiled through cross compilation, arm-none-eabi-gcc.
#
# @author Jose Arguello
# @date August 27 2019
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
# 
# This makefile features the following Build Targets: 
#		<FILE>.i - Generate the preprocessed output <FILE>.i
#		<FILE>.asm - Generate the assembly output <FILE>.asm
#		<FILE>.o - Builds the object file <FILE>.o
#		-----Using .PHONY protection-----
#		compile-all - Compile all the object (.o) files, but DO NOT link
#		build - Build and links all the source (.c) files
#		clean - Removes all recently generated files (.o, .map, .d, etc)
#
#
# Platform Overrides:
#      PLATFORM=HOST - Compile for the HOST machine, using gcc compiler command
#	   PLATFORM=MSP432 - Compile for the MSP432 microcontroller using arm-none-none-eabi-gcc
#						 compiler command
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides (Specific Flags)
PLATFORM = HOST
LINKER_FILE = ../msp432p401r.lds

GENFLAGS = -Wall -Werror -g -O0 -std=c99

# Compile Directive define
TARGET = c1m2

ifeq ($(PLATFORM), HOST)
	CC = gcc $(GENFLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -DHOST
	CPPFLAGs = 
	SIZE = size 
	# etc
endif

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc $(GENFLAGS)
	LDFLAGS = -T $(LINKER_FILE) -Wl,-Map=$(TARGET).map
	CFLAGS = -DMSP432 -mcpu=cortex-m4 -mthumb -march=armv7e-m \
	-mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
	CPPFLAGs = 
	SIZE = arm-none-eabi-size
	# etc
endif

OBJS = $(SOURCES:.c=.o)
MAPS = $(SOURCES:.c=.map)
OUTS = $(SOURCES:.c=.out)
ASSEMBLYS = $(SOURCES:.c=.s)
DEPENDENCIES = $(SOURCES:.c=.d)
CLEANS = $(TARGET).o $(TARGET).out $(TARGET).map

%.o : %.c
		$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
		$(CC) -E $< $(INCLUDES) $(CFLAGS)

%.d : %.c
		@set -e; rm -f $@; \
		$(CC) $(INCLUDES) -MM $(CFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$

%.asm : %.c
		$(CC) -S $< $(INCLUDES) $(CFLAGS)


.PHONY: build
build: all 

.PHONY: all
all: $(TARGET).out $(DEPENDENCIES)

$(TARGET).out: $(OBJS)
		$(CC) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
		$(SIZE) -Atd $(OBJS) $(TARGET).out

$(DEPENDENCIES): $(SOURCES)
		@set -e; rm -f $@; \
		$(CC) $(INCLUDES) -MM $(CFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$


.PHONY: compile-all
compile-all: 
		$(CC) $(INCLUDES) -c $(SOURCES) $(CFLAGS)



.PHONY: clean
clean:
		rm -f *.asm *.o *.d *.map *.out *.i *.size *.s