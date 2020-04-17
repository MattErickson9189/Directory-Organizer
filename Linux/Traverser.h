#include <string>
#include "Organizer.h"
#include <vector>
#include <iostream>
#include <iterator>

class Traverser{

    public:

        Traverser();
        Traverser(Organizer &method);
        void traverse(std::string);
        void setMethod(Organizer &method);

    private:
        Organizer method;
};
