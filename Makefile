CC = gcc
TARGET = mtfuji
OBJS = mtfuji.o func.o optimize.o

$(TARGET): $(OBJS)
	$(CC) -Wall -o $@ $^ -lm

clean: 
	rm -f $(TARGET) $(OBJS)