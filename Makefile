
all:
	g++ main.cpp polish.cpp -o rpn.out

clean:
	rm *.o *.out 2> /dev/null
