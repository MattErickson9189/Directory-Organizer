#include "Organizer.h"
#include <unistd.h>
#include <iostream>

class ExtensionMover: public Organizer{

    public:
        void sendFile(std::string path);

};
