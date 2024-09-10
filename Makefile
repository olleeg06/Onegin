all : main_onegin.o
	g++ main_onegin.o -o result

main_onegin.o : main_onegin.cpp
	g++ -c main_onegin.cpp
clean:
	del main_onegin.o result.exe