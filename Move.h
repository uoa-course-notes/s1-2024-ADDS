#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <vector>
class Move{
	protected:
	    std::string name; // name of move
	    std::vector<std::string> winRelationship; // given the move, which other moves will win against it? 
	    std::vector<std::string> loseRelationship; // given the move, which other moves will lose against it? 
	public:	
		// Returns the name of a Move instance, for example "Ninja"
	 	std::string getName();
	 	int compareMoves(Move* move); // self-referential pointer
};


#endif