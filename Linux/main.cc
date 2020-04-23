#include "DirectoryOrganizer.h"
#include "ExtensionMover.h"
#include <unistd.h>


int main(){

    //On a unix system the max length a username can be is 32 characters long, just to add some extra room the buffer max will be size 50
    int max = 50;

    char *name = (char*)malloc(sizeof(*name) * max);

    //getlogin_r returns the user name currently logged in, this is to navigate to the downloads folder    
    getlogin_r(name, max);

    std::string strName = name;
    std::string path = "/home/" + strName + "/Downloads/";

    Traverser traverser;
    ExtensionMover mover;
    Organizer *organizer = &mover;

    DirectoryOrganizer directoryOrganizer(traverser,organizer);
    directoryOrganizer.organize(path);

}
