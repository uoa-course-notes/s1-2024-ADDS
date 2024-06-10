#include <iostream>

class Instrument{
    public:
        // virtual void makeSound(){ // if there are implementations of makeSound() in my derived class, execute them. Else, just execute this one. 
        //     std::cout << "Instrument is playing." << std::endl;
        // }

        virtual void makeSound() = 0; // this function has become a pure virtual function and now the Instrument class has become abstract.
        // That means any class that is dervied from this class will have to implement its own version of makeSound();
};

class Accordion: public Instrument{
    public:
        void makeSound(){
            std::cout << "Accordion is playing." << std::endl;
        }

};      


class Violin: public Instrument{
    public:
        void makeSound(){
            std::cout << "Violin is playing." << std::endl;
        }

};

class Piano: public Instrument{
    public:
        void makeSound(){
            std::cout << "Piano is playing." << std::endl;
        }



};





int main(int argc, char** argv)
{
    // Instrument* i1 = new Accordion();

    // Instrument* i2 = new Violin();
    // i1 -> makeSound();
    // i2 -> makeSound();
    Instrument* instruments[2] = {};
    instruments[0] = new Accordion();
    instruments[1] = new Violin();

    for (int i=0; i<2; i++){
        instruments[i] -> makeSound();   
    }

    Instrument* i3 = new Piano();
    i3 -> makeSound();





    return 0;    
}
