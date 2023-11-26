# Компилятор
CC = g++

# Флаги компиляции
CFLAGS = -Wall -Wextra -std=c++14

# Имя исполняемого файла
EXEC = calculator

# Исходные файлы
SRCS = calculator.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
