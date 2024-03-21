#include <iostream>
#include <vector>


#include <map>
#include <unordered_map>


struct CityRecords{
    std::string Name;
    uint64_t Population;
    double Latitude, Longitude;


};


int main(int argc, char** argv){
	std::map<int, int> Maps; // Ordered map = Sorted map = Map
				 // Self-balancing RBT
				 // 
	// Unordered Map - hash table
	// Usually - faster than map
	// Referred in most cases
	std::vector<CityRecords> cities;
	cities.emplace_back("Melbourne", 500000, 2.6, 92.12);
	cities.emplace_back("Berlin", 500000, 2.6, 92.12);
	cities.emplace_back("Darwin", 500000, 2.6, 92.12);
	cities.emplace_back("Lankashier", 500000, 2.6, 92.12);
	cities.emplace_back("Phnom Penh", 500000, 2.6, 92.12);
	
	for (const auto& city: cities){
		// string comparisons are not cheap
		if(city.Name == "Berlin"){std::cout << "Found it" << std::endl;}
		
	}
	std::map<std::string , CityRecords> cityMap;
	cityMap["Melbourne"] = CityRecords {"Melbourne", 500000, 2.6, 92.12};
	cityMap["Berlin"] = CityRecords {"Berlin", 500000, 2.6, 92.12};
	cityMap["Lankashier"] = CityRecords {"Lankashier", 500000, 2.6, 92.12};
	
	CityRecords& berlinData = cityMap["Berlin"];
	std::cout << berlinData.Population << std::endl;
	return 0;
}
