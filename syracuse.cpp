#include <iostream>



class syracuseLength{
    private:
        int length = 0;
    public:
        int calculateLength(int n){
                // length++;
            if (n == 1) return 1;
            else{   
                length++;
                if (n % 2 == 0) return calculateLength(n/2);
                else return calculateLength(3*n + 1);
            }
        }

        int getLength() const {return length;}


};



int main(){
    syracuseLength s;
    int q = 22;
    int n = s.calculateLength(q);
    std::cout << s.getLength() << std::endl;
    

    return 0;
}