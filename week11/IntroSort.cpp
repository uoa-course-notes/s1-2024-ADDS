#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <ctime>
/*

*/
class Person{
    private:
        unsigned int age;
        std::string name;
    public:
        Person(unsigned int age, std::string name){
            this -> age = age;
            this -> name = name;
        }
        Person(){

        }

        unsigned int getAge(){return age;}
        std::string getName(){return name;}

        void setAge(unsigned int age){this -> age = age;}
        void setName(std::string name){this -> name = name;}

        static bool sortAge(Person& p1, Person& p2){
            return p1.getAge() < p2.getAge();
        }
        // Using std::sort to sort a vector of Persons in descending order in terms of age attribute 
        std::vector<Person> generatePeople(unsigned int size){
            std::vector<Person> People;
            unsigned int Age = 0;
            std::string name = "";
            for (int i=0; i < size; i++){
                Age = unsigned(rand() % 50) + 1;
                name = "SethMarvelously";
                name.append(std::to_string(rand()%name.size() - 2));
                Person p{Age, name};
                People.push_back(p);
                name.erase(rand() % name.size() - 1);
            }
            return People;
        }
        std::vector<Person> sort_persons(std::vector<Person> P){
            std::sort(P.begin(), P.end(), sortAge);
            return P;
        }

        void printDetail(std::vector<Person> People){
            for (auto p: People){
                std::cout << p.getName() << ": " << p.getAge() << std::endl;
            }
        }
};



bool comp(int a, int b){
    return a > b;
}

int main(int argc, char** argv){
    Person p;
    std::vector<Person> People = p.generatePeople(10);
    std::cout << "Before sorting by age: " << std::endl;
    p.printDetail(People);
    std::cout << "After sorting by age: " << std::endl;
    People = p.sort_persons(People);
    p.printDetail(People);
    // std::vector<int> V{13, 32, 23, 45, 12, 452,3};

    // std::cout << "Original:";
    // for (auto n: V){
    //     std::cout << n << ",";
    // }

    // std::cout << std::endl;
    // std::sort(V.begin(), V.end());
    // std::cout << "--------------Unstable sorting--------------" << std::endl;
    
    // std::cout << "Sorted (Ascending):";
    
    // // Sort in ascending order 
    // for (auto n: V){
    //     std::cout << n << ",";
    // }
    // std::cout << std::endl;


    // std::cout << "Sorted (Descending):";
    // // Sort in descending order 
    // std::sort(V.begin(), V.end(), comp);
    // for (auto n: V){
    //     std::cout << n << ", ";        
    // }
    // std::cout << std::endl;

    // std::cout << "--------------Stable sorting--------------" << std::endl;
    // std::stable_sort(V.begin(), V.end(), comp);
    // for (auto n: V){
    //     std::cout << n << ", ";        
    // }
    // std::cout  << std::endl;


    
    

    return 0;
}