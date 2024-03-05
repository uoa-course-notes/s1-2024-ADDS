#ifndef SET
#define SET
// When the extension is set to .tpp, the compiler said "Unable to handle compilation, expected exactly only one compiler job in '' "


#include <vector>

template <class T>
class Set{
	private:
		std::vector<T> members;
		bool isMember(T member);
		void remove(T member);
};

template <class T>
void Set<T>::add(T newMember){
	// check if newMember is already in the vector
	if (!isMember(newMember)){
		// if not add it
		members.push_back(newMember);
	}
}

template <class T>
bool Set<T>::isMember(T checkMember){
	// see if it is in the members vector
	for (size_t i=0; i<members.size(); i++){
		if (members.at(i) == checkMember) return true;
	}
}

template <class T>
void Set<T>::remove(T deleteMember){
	// does vector already have this? 
}



#endif 
