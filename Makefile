flags = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

test.txt: test.c
	echo z

testtarget:
	echo target

main: utils.o quadraticsolver.o quadraticinput.o quadraticoutput.o main.o
	g++ utils.o quadraticinput.o quadraticoutput.o quadraticsolver.o main.o -o main.exe
	./main.exe


test: quadraticsolver.o quadraticinput.o quadraticoutput.o utils.o
	g++ -c $(flags) test.c
	g++ utils.o quadraticinput.o quadraticoutput.o quadraticsolver.o test.o -o test.exe
	./test.exe

test_file: quadraticsolver.o quadraticinput.o quadraticoutput.o utils.o
	g++ -c $(flags) test_file.c
	g++ utils.o quadraticinput.o quadraticoutput.o quadraticsolver.o test_file.o -o test_file.exe
	./test_file.exe

main.o: main.c
	g++ -c $(flags) main.c

test.o: test.c
	g++ -c $(flags) test.c

test_file.o: test_file.c
	g++ -c $(flags) test_file.c

utils.o: utils.c
	g++ -c $(flags) utils.c

quadraticinput:
	g++ -c $(flags) quadraticinput.c

quadraticoutput:
	g++ -c $(flags) quadraticoutput.c

quadraticsolver:
	g++ -c $(flags) quadraticsolver.c
