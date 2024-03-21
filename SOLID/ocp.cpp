#include <iostream>
#include <string>

class Shape{
    public:
        // void area();
        virtual void getArea() = 0;
};

// Using this helper function once and for all
class areaGetter{
    public:
        void areaShape(Shape* s){
            s -> getArea();
        }
};

class Square: public Shape{
    private:
        int side;
    public:
        void getArea() override{
            std::cout << side*side << std::endl;
            
        }
};

class Rectangle: public Shape{
    private:
        int height, width;
    public:
        void getArea() override{
            std::cout << height*width << std::endl;       
        }
};


class Circle: public Shape{
    private:
        int radius;
    public:
        void getArea() override{
            std::cout << radius *radius * 3.14 << std::endl;       
        }
};




int main(int argc, char** argv){




    return 0;
}