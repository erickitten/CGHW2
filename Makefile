CXX = g++

CXXFLAGS = -std=c++0x -g 
LIBS = $(shell pkg-config --libs glfw3) -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -L/usr/lib/x86_64-linux-gnu/ -lXinerama -lXcursor
OBJS = glwrapper.o main.o objmash.o

OUT_EXE = HW2

all: $(OUT_EXE)

$(OUT_EXE): $(OBJS)
	$(CXX) $^ -pthread $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o $(OUT_EXE)
