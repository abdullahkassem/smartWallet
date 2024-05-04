CXX = g++
CXXFLAGS =  -I/home/abdullah/repos/smartWallet/include # Adjust -std as needed

# Source code files
SRCS = $(wildcard *.cpp) $(wildcard database/*.cpp) 

# Object code files (automatically generated from source)
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = myprogram

# Target: Build the executable
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)
	touch $(SRCS)

# Target: Compile source files to object files
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

touch:
	touch $(SRCS)

# Target: Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
