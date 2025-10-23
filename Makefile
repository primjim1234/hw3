CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# Default target
all: llrec-test

#-----------------------------------------------------
# Build rule for llrec-test
#-----------------------------------------------------
llrec-test: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o llrec-test

# Optional: run memory check
memcheck: llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.in

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean
