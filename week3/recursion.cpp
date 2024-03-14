#include <iostream>
#include <time.h>


int* gen_array(int size){
	int* A = new int[size]();
	for (int i = 0; i < size; i++){
		A[i] = rand() % (size + 1); // generate an element from 0 to size - 1
	}
	return A;
}

int Rec_fact(int n){
	if (n == 0 | n == 1) return 1;
	else return n * Rec_fact(n-1);
}

int Int_fact(int n){
	int product = 1;
	for (int i = 1; i <= n; i++) {
		product = product * i;
		// product++;
	}
	return product;
}

void printArray(int *A, int n){
	for(int i=0; i<n; i++){
		if (i == n-1) std::cout << A[i] << std::endl;
		else std::cout << A[i] << ",";
	}
}


int main(int argc, char** argv){
	srand(time(nullptr));

	int n = 10;
	std::cout << Rec_fact(n) << std::endl;
	std::cout << Int_fact(n) << std::endl;

	int* C = gen_array(n);
	printArray(C, n);

	delete[] C;		
	return 0;
}