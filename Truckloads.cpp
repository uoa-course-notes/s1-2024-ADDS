#include "Truckloads.h"


int TruckLoads::numTrucks(int numCrates, int numLoads){
    if (numCrates <= numLoads) return 1;
    else {
        if (numCrates % 2 == 0){
            // if the number of crates is even
            return numTrucks(numCrates/2, numLoads) + numTrucks(numCrates/2, numLoads);
        }
        else{
            // number of crates is odd, pass in the post-division results, one is even 
            // and the other one is odd number of crates
            return numTrucks(numCrates/2, numLoads) + numTrucks(numCrates/2 + 1, numLoads);
        }
    }



}