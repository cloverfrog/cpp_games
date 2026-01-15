ifeq ($(OS),Windows_NT)
    RM = del /q
else
    RM = rm -f
endif

tictactoe: main.cpp
	g++ main.cpp -I../easyx/include -L../easyx/lib64 -leasyx -o tictactoe.exe

clean:
	$(RM) tictactoe.exe