

CC = g++


CFLAGS = -g -std=c++17


LDFLAGS =  -lGL -lGLU -lglut -lGLEW -lglfw


EXEC = display


SRC = tests/ex14.cpp


OBJ = $(SRC:.cpp=.o)


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC)  $(OBJ) -o  $@ $(LDFLAGS) 

re: clean all

%.o: %.cpp
	$(CC) -I./ -c $(CFLAGS) $< -o $@


clean:
	rm -f $(OBJ) $(DEP) $(EXEC)
	rm tests/*.o









