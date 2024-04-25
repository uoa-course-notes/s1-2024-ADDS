#include <iostream>
#include <vector>


void printV(std::vector<int> V){
    int n = V.size();
    std::cout << "<";
    for (int i=0; i<n; i++){
        if (i == n-1) std::cout << V[i];
        else std::cout << V[i] << ",";
    }
    std::cout << ">" << std::endl;
}


void prettyPrint(int n){
    std::cout << "<";
    for (int i=0; i<n; i++) {
        if (i == n-1) std::cout << i;
        else std::cout << i << ",";
    }
    std::cout << ">" << std::endl;
}

std::vector<int> populate(int n){
    std::vector<int> V;
    for (int i=0; i<n; i++){
        V.push_back(i);
    }
    return V;
}






class Mod{
    private:
        int modulo;
    public:
        Mod(int n){
            this -> modulo = n;
        }
        int add_mod(int x, int y){
            return (x + y)%modulo;
        }
        int subtract_mod(int x, int y){
            return (x - y)%modulo;
        }
        ~Mod(){}

};

class Z_4{
    private:
        const int order = 4;
        std::vector<int> G = populate(order);
    public:
        void list_element(){            
            prettyPrint(order);
        }

        std::vector<int> get_G(){return G;}
        int get_order() const {return order;}

        void CayleyDiagram(){
            for(int i=0 ;i<order; i++){

            }
        }

        ~Z_4(){}


};



/*
Another radical idea is how to create the Cartesian coordinate in here...of course it's doable but it's going to take someime. 

*/



int main(int argc, char** argv){
    // mod_n(a,b) = 
    Z_4 IM4;
    // IM4.list_element();

    // printV(IM4.get_G());
    int a = 8;
    int b = 11;
    int n = 6;
    // std::cout << "Normal addition: \t\t" << a + b << std::endl;
    // std::cout << "Modulo arithmetic mod n = " << n << " ===>  " << (a + b)%n << std::endl;
    // Mod mod_op(n);
    // std::cout << mod_op.add_mod(a, b) << std::endl;
    
    for (int x=-1; x<=12; x++){
        // std::cout << a << "*" << x << " = " << a*x  << std::endl;
        for(int y=0; y<=12; y++){            
            if (x == -1){
                std::cout << "\t\t" << y;
                continue;
            } 
            // else std::cout << x << "\t\t";
            // std::cout << x;
            std::cout << "\t\t" << y;
        }

        
        
    }
    std::cout << std::endl;

    return 0;
}