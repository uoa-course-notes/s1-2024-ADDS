test: main.cpp 
	@g++ main.cpp Node.cpp LinkedList.cpp -o main 
	@./main 


big: test.cpp 
	@g++ -std=c++11 -o test.out -O2 -Wall BigNumCalc.cpp test.cpp 
	@./test.out