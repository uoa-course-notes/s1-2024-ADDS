#include <iostream>
#include <string>


// class Friend{};
// class Floor{};

// class Human{
//     private:
//         int age;
//         std::string name;

//     public:
//         void drive(int speed);
//         void sendMessageToFriend(Friend f1);
//         void readMessageFromFriend(Friend f2);

//         void VaccuumFloor();
// };


class Human{
    public:
        Human(){}
        virtual void func(int n) = 0;
        virtual ~Human();   
             
};

class Aussie: public Human{
    public:
        void func() {};
        void func(int x) override {
            std::cout << "I am an Aussie" << std::endl;
        }

        ~Aussie(){std::cout << "Good bye" << std::endl;
        }
};

class British: public Human{
    public:
        void func() {};
        void func(int x) override {
            std::cout << "I am an Anglo-Saxon" << std::endl;
            
        }

        ~British(){std::cout << "Bye" << std::endl;
        }
};



/*
@fun
@param
*/
int main(int argc, char** argv){
    Aussie aussieNumber1;
    British britishNumber1;

    aussieNumber1.func();
    britishNumber1.func();

    return 0;
}