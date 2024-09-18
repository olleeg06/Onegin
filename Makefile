all : main_onegin.o work_files.o sort_compare.o
	g++ main_onegin.o work_files.o sort_compare.o -o result

main_onegin.o : main_onegin.cpp
	g++ -c main_onegin.cpp

work_files.o : work_files.cpp work_files.h
	g++ -c work_files.cpp

sort_compare.o : sort_compare.cpp sort_compare.h
	g++ -c sort_compare.cpp

clean:
	del main_onegin.o work_files.o sort_compare.o result.exe