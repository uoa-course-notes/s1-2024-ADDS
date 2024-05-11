#include "PrefixMatcher.h"



int PrefixMatcher::selectRouter(std::string networkAddress){
    // Start algorithm over here
    std::string prefix = "";
    std::vector<std::string> parent;
    t.navigate(networkAddress, prefix, parent);

    if (parent.size() > 0){
        return router_map.find(parent.back()) -> second;
    }
    else return -1;

    return 1;
}



void PrefixMatcher::insert(std::string address, int routerNumber){
    t.insert(address);
    std::pair<std::string, int> t = {address, routerNumber};
    router_map.insert(t);
}


