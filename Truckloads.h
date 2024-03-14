#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H

class Truckloads{
    private:
        int numCrates; // the number of crates at the warehouse. Between 2 and 10000
        int loadSize; // the maximum number of crates that will fit in ta truck. Between 1 and numcrates - 1
    
    public:
        int numTrucks(int numCrates, int loadSize);          
};




#endif