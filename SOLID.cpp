#include <iostream>
#include <string>

class Invoice{
	private:
	    std::string customers;
	    std::string state;
	    int total;
	public:
	    Invoice(std::string customers, std::string state, int total): customers(customers), state(state), total(total){}

	    Invoice(): Invoice("NaN", "NaN", 0){}
	    void details(){
	    	std::cout << "Customer: " << customers
		    	  << "Total: " << total << std::endl; 
	    }
	    int sales_tax(){
	   	switch(state){
		    case "AZ": return 5.5;
		    case "TX": return 1.21;
	       	    case "CA": return 0.32;		       
		}
	   }
	    void email_invoice(){
		std::cout << "Emaling invoice: " << std::endl;
		details();
	    }
};

int main(int argc, char** argv){
	Invoice invoice("Seth", "ADL", 100);

	invoice.details();
	return 0;
}
