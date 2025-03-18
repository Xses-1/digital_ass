# Build a NXP LPC1343 C program with the GCC cross compiler
# - Runs the checksum program (lpc1343_checksum)
# - Supports flashing the MCU

#
# Start of user-editable lines
#

# TARGETS contains the final target, the .bin file. e.g. testprogram.bin
TARGETS		:= main.bin
# SOURCES contains the sources (C files, header files). e.g. testprogram.c testprogram.h
SOURCES		:= main.c

#
# End of user-editable lines
#

# This line adds the CMSIS files, startup code, and the linker-script to the SOURCES
SOURCES		+= LPC13xx.h		\
		   core_cm3.h		\
		   core_cmFunc.h	\
		   core_cmInstr.h	\
		   system_LPC13xx.c	\
		   system_LPC13xx.h	\
		   startup.c lpc1343.ld

#
# Sanity check TARGETS:
#
ifneq ($(words $(TARGETS)), 1)
 $(error Invalid number of targets ($(words $(TARGETS)) instead of 1)!)
endif

#
# Derived files:
#
C_SOURCES	:= $(filter %.c, $(SOURCES))
OBJECTS		:= $(C_SOURCES:%.c=%.o)
ELFFILE		:= $(TARGETS:%.bin=%.elf)
DEPFILES	:= $(C_SOURCES:%.c=%.d)

LDFILE		:= $(filter %.ld, $(SOURCES))

#
# Sanity check linker script:
#
ifneq ($(words $(LDFILE)), 1)
 $(error Invalid number of linker-scripts ($(words $(LDFILE)) instead of 1)!)
endif

CLEANABLE_FILES	+= $(OBJECTS) $(ELFFILE) $(DEPFILES) $(TARGETS)

#
# Programs:
#
CROSS_COMPILE	?= arm-none-eabi-

CC		:= $(CROSS_COMPILE)gcc
LD		:= $(CROSS_COMPILE)gcc
OBJCOPY		:= $(CROSS_COMPILE)objcopy
CRC		:= lpc1343_checksum
DD		:= dd
LPC1343_DEVICE	:= /dev/disk/by-id/usb-NXP_LPC134X_IFLASH_ISP000000000-0:0
RM		:= rm

CFLAGS		:= -mcpu=cortex-m3 -mthumb -Os -Wall -std=gnu99 -I.
LDFLAGS		:= -nostartfiles -T$(LDFILE)
DEPFLAGS	:= -MM
OBJCOPYFLAGS	:= -O binary
DDFLAGS		:= seek=4
RMFLAGS		:= -f

#
# Rules:
#
all:		$(TARGETS)

%.bin:		%.elf
		$(OBJCOPY) $(OBJCOPYFLAGS) $< $@ && \
		$(CRC) $@

%.elf:		$(OBJECTS)
		$(LD) $(LDFLAGS) $^ -o $@

%.d:		%.c
		$(CC) $(DEPFLAGS) $(CPPFLAGS) $< | sed 's/\($*\).o[ :]*/\1.o $@: /g' > $@

%.o:		%.c
		$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.s:		%.c
		$(CC) $(CPPFLAGS) $(CFLAGS) -S -c -o $@ $<

flash:		$(TARGETS)
		$(DD) if=$< of=$(LPC1343_DEVICE) $(DDFLAGS)

clean:
		$(RM) $(RMFLAGS) $(CLEANABLE_FILES)

.PHONY:		flash clean

ifeq ($(filter clean,$(MAKECMDGOALS)),)
-include	$(DEPFILES)
endif
