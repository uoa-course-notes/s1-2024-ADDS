#ifndef BROKEN_PLAYER
#define BROKEN_PLAYER
#include <string>



class Player{
	public:
		Player(std::string name){_name = name;} 
	 	virtual Move* makeMove() const = 0; 
		// I assume Move is a class 
 	  	std::string getName(){return _name;}
		std::string _name;


};




#endif
