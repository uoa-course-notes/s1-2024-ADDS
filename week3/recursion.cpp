#include <iostream>


int f(int n){
	if (n < 0) return -1;
	else{
		if (n == 1) return 1;
		else return n*f(n-1);
	}
}

std::string rec_reverse_string(){
	//if 
	return "std";
}

template <class T>
void swap(T *a, T* b){
	// a = 10, b = 5
	T temp = *a; // temp = 10
	*a = *b; // a = 5
	*b = temp; // b = 10
}

template <class T>
void swap(T& a, T& b){
	// a = 10, b = 5
	T temp = a; // temp = 10
	a = b; // a = 5
	b = temp; // b = 10
}

void it_reverse_string(std::string &input){ // for string of odd length
	int mid = int(input.size()/2);
	std::cout << input << ", length = " << input.size() << " and mid = " << mid << std::endl;	
    for (int i = 0; i<=mid; i++){
		swap(input[mid-i], input[mid + i]);
		std::cout << "Swapped ("<< mid-i << "," << mid+i << ") --> " << input << std::endl;	
	}
}

void it_even_reverse_string(std::string &input){ // for string of odd length
	int mid = int(input.size()/2);
	std::cout << input << ", length = " << input.size() << " and mid = " << mid << std::endl;	
    // // for (int i = 0; i<mid; i++){
	// 	int i = mid;
	// 	while (i > 0){
	// 		i = mid - i;
	// 		swap(input[mid-i-1], input[mid + i-1]);
	// 		std::cout << "Swapped ("<< mid-i << "," << mid+i << ") --> " << input << std::endl;	
	// 		i++;
	// 	}
	


	// }
}


bool checkPalindrome(std::string& input){
	int mid = int(input.size()/2);
	if (mid < 0) return false; // input can't be of length smaller than 0
	for (int i = 0; i< mid; i++){
		if (input[mid-1-i] != input[mid+1+i]) return false;
	}
	return true; // either the input is of length 1 or greater than 1
}


int F(int n){
	if (n == 1) return 0;
	else{
	    std::cout <<"Current n = " << n << std::endl;
	    return (n*(n-1) + F(n-1));
	}
}


int main(int argc, char** argv){
	// std::cout << F(n) << std::endl;
	std::string a = "abcd";
	std::string b = "abcde";
	it_even_reverse_string(a);
	std::cout << "After: " << a << std::endl;
	
	
	return 0;	
}
