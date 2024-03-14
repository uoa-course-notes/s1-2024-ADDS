#include "Truckloads.h"


int Truckloads::numTrucks(int numCrates, int numLoads){
    if (numCrates <= numLoads) 
        return 1;
    return numTrucks((numCrates/2), numLoads) + numTrucks((numCrates/2) + (numCrates % 2), numLoads);
}