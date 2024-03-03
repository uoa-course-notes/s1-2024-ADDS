#include <iostream>


// 1.
// class A{
//     private: 
//         static int x;
//         int y;
//     public:
//         A(int x): y(x){}
//         int getX(){return x;}
//         void setX(int x) const {this -> x = x;}
        

// };


// int A::x = 2;

// 2.
// class A{
//     protected:
//         int x;
//     public:
//         A(){x = 5;}
//         void setX(int i){ x = i;}
//         int getX(){return x;}
// };

// class B: private A{
//     private:
//         int y;
//     public:
//         B(){y = 10;}
//         void setY(int i){y = i;}
//         int getY(){return y;}
//         int sum(){return x+y;}
// };
// class C: public B{
//     public: 
//         int getSum(){return sum();}
// };


// 3.
// class D{
//     int x;
//     public:
//         D(int x): x(x){}
//         D(): D(0){} 
//         D(const D& other): x(other.x + 1){}
//         void setX(int x){this -> x = x;}
//         int getX(){return x;}
// };

// 4.
// template <typename T>
// class F{
//     T x;
//     public:
//         F(T x): x(x){}
//         T getX(){return x;}
// };


// 5.
// class B{
//     int x;
//     public:
//         B(int x): x(x){}
//         virtual int getX(){return x;}
//         virtual int getX(std::string name){return int(name[0]);}    
// };

// class C: public B
// {
//     int y;
//     public:
//         C(int x, int y): B(x), y(y){}
//         int getX(){return y;}
//         int getX(std::string name){return int(name[0]);}

// };

// 6.
// class A{
//     public:
//         int x;
//         A(){x = 5;}
//         A(int i){x = i;}      
// };

// class B: public A{
//     public:
//         int y;
//         B(){y = 10;}
//         B(int i, int j): A(i){y = j;}

// };

// 7.
class G{
    private:
        int x;
    public:
        G(int x): x(x){}
        int getX() {return x;}
};


class Shape{
    public:
        Shape(int x){std::cout << "In shape\n";}
        Shape(){}
        virtual void draw(){};
        virtual void X(){std::cout << "In X" << std::endl;
        }

        ~Shape(){}
};

class Rectangle: public Shape{
    public:
        void draw(){std::cout << "Drawing a rectangle..." << std::endl;}

};

class Circle: public Shape{
    public:
        void draw(){std::cout << "Drawing a circle..." << std::endl;}
};

class Square: public Shape{
    public:
        void draw(){std::cout << "Drawing a square..." << std::endl;}
};

void draw_shapes(Shape* shape) {
    std::cout << "=================LET'S DRAW==============" << std::endl;
    shape -> draw();
}

int main(int argc, char** argv){
    // 1.
    // A a(5);
    // const A& b = a;
    // b.setX(10);


    // 2.
    // C c;
    // c.setX(3);
    // c.setY(10);
    // std::cout << c.getSum() << std::endl;

    // 3.
    // D d1(5);
    // // D d2 = d1; // == D d2(d1)
    // D d2(d1);
    // // D d2;
    // // d2 = d1;
    // d2.setX(10);
    // // D d3(d2);
    // // std::cout << d3.getX() << std::endl;
    // std::cout << d2.getX() << std::endl;
    // std::cout << d1.getX() << std::endl;

    //4.   
    // F<int> f1(5);
    // F<double> f2(10.5);
    // std::cout << f1.getX() + f2.getX() << "\n";
 
    // 5.
    // B* b = new C(5,10);  
    // std::cout << b -> getX() << std::endl;
    // // std::cout << b -> getX("Hello, World.") << std::endl; // error as getX(std::string name) with an argument of type string is not originally within the parent class 
    // // B, so implementing it in our child class, in this case, signifies that we want to overload the method within the confine of the child class and the parent class's 
    // // getX() method isn't concerned with what happens in the child class. 
    // // To remedy the situation, we either define a getX() with a string argument in our parent's class or leave the class
    // // definitions as are and create a new object of type C.
    // C c1(1,2);
    // std::cout << c1.getX("Hello, World\n") << std::endl;


    // 6.
    // B b1;
    // std::cout << b1.x << ", " << b1.y << std::endl;

    // 7.
    // G g1(5);
    // std::cout << g1.getX() << std::endl;
    

    // 8.
    // Shape s;
    // s1.draw();
    // Shape *s = new Shape[3](10) 
    // The above expression is ambiguous to the compiler.
    // It doesn't know whether you want to create an array of three pointers to Shape
    // or create an array of 10 instances of Shape. 

    // Correct way: create an array of three instances, each with a specific value (1,2 or 3)
    // Shape* s = new Shape[3]{1,2,3};

    // s -> draw();
    // Shape** s = new Shape*[3]; // three pointers to objects of type Shape
    // for(int i=0;i <3; i++){
    //     s[i] = new Shape(10*(i+1));
    // }

    // for (int i=0; i<3; i++) {
    //     draw_shapes(s[i]);
    // }
    Shape* s = new Circle();
    draw_shapes(s);
    // 9. Same as 8

    return 0;
}