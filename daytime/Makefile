.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG

DEBUG_FLAGS = -g -O0 -Wall

RELEASE_EXEC = daytime

DEBUG_EXEC = daytime-dbg

SOURCE = daytime.cpp



all: debug release



debug: $(DEBUG_EXEC)



$(DEBUG_EXEC): daytime.cpp

g++ $(DEBUG_FLAGS) daytime.cpp -o $(DEBUG_EXEC) 



release: $(RELEASE_EXEC)



$(RELEASE_EXEC): daytime.cpp

g++ $(RELEASE_FLAGS) daytime.cpp -o $(RELEASE_EXEC)



clean:

rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)

