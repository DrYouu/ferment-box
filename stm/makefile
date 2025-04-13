# Configuración para STM32F401CCU6
TARGET = ferment-box
MCU = cortex-m4
CFLAGS = -mthumb -mcpu=$(MCU) -DSTM32F4 -I./inc
LDFLAGS = -Tstm32f401ccu6.ld -nostartfiles

# Archivos fuente
SRCS = src/firmware.c

# Herramientas
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f *.o *.elf *.bin
