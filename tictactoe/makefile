ifeq ($(OS),Windows_NT)
    RM = del /q
else
    RM = rm -f
endif

ball: main.cpp
	g++ main.cpp -I../easyx/include -L../easyx/lib64 -leasyx -o ball.exe

clean:
	$(RM) ball.exe