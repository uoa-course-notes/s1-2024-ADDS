#include "MoveFactory.h"
#include "Scissor.h"


Move* moveFactory::createMove(const std::string& moveName){
    if (moveName == "Rock") return new Rock();
    else if (moveName == "Scissor") return new Scissor();
    else if (moveName == "Paper") return new Paper();
    else if (moveName == "Monkey") return new Monkey();
    else if (moveName == "Robot") return new Robot();
    else if (moveName == "Ninja") return new Ninja();
    else if (moveName == "Zombie") return new Zombie();
    else if (moveName == "Pirate") return new Pirate();
    // Once new moves are added, we can use another else if to include them
    // Spell-check has not been implemented. So case-sensitivity is absolute.
    else return nullptr; // the else keyword is not needed in this case
    // since the same effect will be realized. 
}