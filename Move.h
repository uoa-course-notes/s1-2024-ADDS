#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>
class Move{
	protected:
	    std::string name;
	    std::vector<std::string> winRelationship;
	    std::vector<std::string> loseRelationship;
	public:	
		// Returns the name of a Move instance, for example "Ninja"
	 std::string getName();
	 int compareMoves(Move* move);
};


#endif