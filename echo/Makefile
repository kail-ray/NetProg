
.PHONY: all debug release clean




RELEASE_FLAGS = -O2 -Wall -DNDEBUG

DEBUG_FLAGS = -g -O0 -Wall

RELEASE_EXEC = echo

DEBUG_EXEC = echo-dbg

SOURCE = echo.cpp



all: debug release



debug: $(DEBUG_EXEC)



$(DEBUG_EXEC): echo.cpp

g++ $(DEBUG_FLAGS) echo.cpp -o $(DEBUG_EXEC) 



release: $(RELEASE_EXEC)



$(RELEASE_EXEC): echo.cpp

g++ $(RELEASE_FLAGS) echo.cpp -o $(RELEASE_EXEC)



clean:

rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)

