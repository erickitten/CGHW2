CXX = g++

CXXFLAGS = -std=c++0x -g 
LIBS = $(shell pkg-config --libs glfw3) -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -L/usr/lib/x86_64-linux-gnu/ -lXinerama -lXcursor

OUT_EXE = HW2

all: $(OUT_EXE)

$(OUT_EXE): main.o hw2.o glwrapper.o
	$(CXX) $^ -pthread $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o $(OUT_EXE)
