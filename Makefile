CC	= g++
CFLAGS	= -Wall
INCLUDES = .

check-syntax:
	$(CC) -o nul $(CFLAGS) $(INCLUDES) -S ${CHK_SOURCES}
