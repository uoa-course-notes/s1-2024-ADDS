#ifndef MOVE_H
#define MOVE_H


#include <string>
#include <vector>



class Move{
	private:
	    std::string name;
	    std::vector<std::string> relationship;
	public:	
		// Returns the name of a Move instance, for example "Ninja"
		virtual std::string getName() = 0;

		


	    virtual ~Move() = 0;



};





#endif
