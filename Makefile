test:main.o
	g++ -o $@ $^
main.o:main.cpp
	g++ -c $< -g
.PHONY:clean
clean:
	rm -f *.o test
