#include "DirectoryOrganizer.h"
#include "ExtensionMover.h"

int main(){


    Traverser traverser;
    ExtensionMover mover;
    Organizer *organizer = &mover;

    DirectoryOrganizer directoryOrganizer(traverser,organizer);
    directoryOrganizer.organize("/home/matt/Downloads/");

}
