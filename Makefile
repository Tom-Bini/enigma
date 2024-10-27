SRCS = main.c mapper.c rotor.c enigma.c crack_enigma.c
OBJS = $(SRCS:%.c=%.o)
TARGET = enigma
CC = gcc
CFLAGS = -std=c99 --pedantic -Wall -Wextra -Wmissing-prototypes
LDFLAGS = -lm

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

run : $(TARGET)
	./$(TARGET) -e helloworld 0 10 1 11 2 12 0

crack : $(TARGET)
	./$(TARGET) -c encrypted.txt bigrams.txt "emdzyucbzjpris"

clean:
	rm -f $(OBJS) $(TARGET)

main.o: main.c enigma.h crack_enigma.h mappings.h
mapper.o: mapper.c mapper.h
rotor.o: rotor.c rotor.h mapper.h
enigma.o: enigma.c enigma.h rotor.h mapper.h
crack_enigma.o: crack_enigma.c crack_enigma.h enigma.h mappings.h
