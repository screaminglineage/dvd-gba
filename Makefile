BUILD_DIR := build

CC := arm-none-eabi-gcc
LD := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
GBAFIX := gbafix
GBAEMU := mgba-qt

ARCH := -mthumb-interwork -mthumb
SPECS := -specs=gba.specs
CFLAGS := $(ARCH) -Wall -O2 -fno-strict-aliasing
LDFLAGS := $(ARCH) $(SPECS)

$(BUILD_DIR)/main.gba: main.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $(BUILD_DIR)/main.o
	$(LD) $(LDFLAGS) $(BUILD_DIR)/main.o -o $(BUILD_DIR)/main.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.gba
	$(GBAFIX) $(BUILD_DIR)/main.gba

.PHONY : clean run

clean:
	rm $(BUILD_DIR)/*

run: $(BUILD_DIR)/main.gba
	$(GBAEMU) $^
