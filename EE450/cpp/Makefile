#start of the Makefile
main.cpp:main.cpp teacher.cpp
	g++ -o main.cpp teacher.cpp teacher.h
teacher.cpp:teacher.cpp teacher.h
	g++ -o teacher teacher.cpp teacher.h
clean:
	rm -rf *.o main
