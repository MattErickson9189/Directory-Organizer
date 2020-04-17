#include "Traverser.h"


class DirectoryOrganizer{

    public:
        DirectoryOrganizer(Traverser &traverser, Organizer &organizeMethod);
        void organize(std::string path);

    private:
        Traverser traverser;
        Organizer organizeMethod;
};
