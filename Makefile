TARGET = passgen
PREFIX = /bin
CFLAGS = -Wall -Wextra
CC = gcc
OBJECTS = passgen.o common.o generate.o tools.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)	
	
passgen.o: passgen.c
	$(CC) $(CFLAGS) -c passgen.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c
	
generate.o: generate.c generate.h
	$(CC) $(CFLAGS) -c generate.c

tools.o: tools.c tools.h
	$(CC) $(CFLAGS) -c tools.c
	
clean:
	rm -rf *.o passgen
	
install: 
	install $(TARGET) $(PREFIX)
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
	
