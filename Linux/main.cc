#include "DirectoryOrganizer.h"
#include "ExtensionMover.h"

int main(){


    Traverser traverser;
    ExtensionMover mover;

    DirectoryOrganizer directoryOrganizer(traverser,mover);
    directoryOrganizer.organize("/home/matt/Downloads/");

}
