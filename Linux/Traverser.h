#include <string>
#include "Organizer.h"
#include <vector>
#include <iostream>
#include <iterator>

class Traverser{

    public:

        void traverse(std::string);
        Traverser(Organizer &method);

    private:
        Organizer method;
};
