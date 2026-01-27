CXX = g++
CXXFLAGS = -Wall -O2 -std=c++23 -Wno-unknown-pragmas
TARGET = TivatSurvivor.exe

CXXFLAGS += -I../easyx/include
LDFLAGS = -L../easyx/lib64
LDLIBS = -leasyx -lmsimg32

all: $(TARGET)

$(TARGET): main.o manager.o player.o enemy.o animation.o utils.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /q *.o $(TARGET)