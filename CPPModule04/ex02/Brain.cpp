#include "Brain.hpp"

Brain::Brain(){
	cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &a){
	std::copy(a.ideas, a.ideas + 100, ideas);
}

Brain &Brain::operator=(const Brain &a){
	std::copy(a.ideas, a.ideas + 100, ideas);
	return *this;
}

Brain::~Brain(){
	cout << "Brain destructor called" << std::endl;
}