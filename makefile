prom = gobang.exe
headers = stack.h
obj = gobang.o draw.o game.o stack.o victory.o welcome.o file.o
$(prom): $(obj)
	g++ -fexec-charset=UTF-8 -o $(prom) $(obj)

gobang.o: gobang.cpp 
	g++ -fexec-charset=GBK -c gobang.cpp

draw.o: draw.cpp
	g++ -fexec-charset=UTF-8 -c draw.cpp

game.o: game.cpp $(deps) 
	g++ -fexec-charset=GBK -c game.cpp

stack.o: stack.cpp $(deps)
	g++ -fexec-charset=GBK -c stack.cpp

victory.o: victory.cpp
	g++ -fexec-charset=GBK -c victory.cpp

welcome.o: welcome.cpp stack.h
	g++ -fexec-charset=GBK -c welcome.cpp

file.o: file.cpp $(deps)
	g++ -fexec-charset=GBK -c file.cpp

