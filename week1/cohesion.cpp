#include <iostream>

// class IEngine{
//     public:
//         virtual void start() = 0;
//         virtual ~IEngine(){}
// };

// class DieselEngine: public IEngine{
//     public:
//         void start() override{
//             std::cout << "Diesel Engine starts.\n";
//         }

// };

// class PetrolEngine: public IEngine {
//     public:
//         void start() override {
//             std::cout << "Petrol Engine starts.\n";
                        
//         }
// };

// class Car{
//     private:
//         IEngine* engine; // dependency on interface
//     public:
//         Car(IEngine* e): engine(e){}
//         void start(){
//             engine -> start();
//             std::cout << "Car starts\n";
//         }
// };

class IEngine{
    public:
        virtual void start(){}
        ~IEngine(){}
};


class DieselEngine: public IEngine{
    public:
        void start(){
            std::cout << "Diesel Engine starts." << std::endl;   
        }
};


class PetrolEngine: public IEngine{
    public:
        // void start(){
        //     std::cout << "Petrol Engine starts." << std::endl;   
        // }
};

class ElectricEngine: public IEngine{
    public:
        // void start(){
        //     std::cout << "Electric Engine starts." << std::endl;           
        // }
};


class Car{
    private:
        IEngine* engine; // direct dependency
        // DieselEngine dEngine; // direct dependency
        // DieselEngine eEngine; // direct dependency
    public:
        void start(){
            engine -> start();
            std::cout << "Car starts." << std::endl;
        }
        Car(): Car(nullptr){}
        Car(IEngine* eng){
            if (this -> engine != nullptr) this -> engine = eng;
            else std::cout << "Please provide an engine." << std::endl;
        }
        // void start_diesel(){
        //     dEngine.start();
        //     std::cout << "Car starts." << std::endl;
        // }

        // void start_electric(){
        //     eEngine.start();
        //     std::cout << "Car starts." << std::endl;
            
        // }
};


class A{
    private:
        int x,y;
    public:
        A(){std::cout << "In A\n" << std::endl;}
        void mess(){std::cout << "Mess" << std::endl;
        }
        // ~A(){std::cout << "Destroy A" << std::endl;}
};

class B: public A{
    private: 
        float z;
    public:
        B(): A(){std::cout << "In B\n" << std::endl;
        A();}
        // ~B(){std::cout << "Destroy B" << std::endl;
        // }
};

int main(int argc, char** argv){
    // A* a = new A();
    B b;
    // A::A();
    // b.mess();
    // ==================== Tightly Coupled (Less Desirable) ====================
    // IEngine* engine = new DieselEngine();
    // Car car(engine);
    // car.start();
    // // car.start();
    // car.start_diesel();

    // car.start_petrol();
    // ==================== Loosely Coupled (More Desirable) ====================
    // Making a car with DieselEngine
    // DieselEngine* dieselEngine = new DieselEngine();
    // Car dieselCar(dieselEngine);
    // dieselCar.start();


    // // Making a car with petrol engine
    // PetrolEngine* petrolEngine = new PetrolEngine();
    // Car petrolCar(petrolEngine);
    // petrolCar.start();

    return 0;
}