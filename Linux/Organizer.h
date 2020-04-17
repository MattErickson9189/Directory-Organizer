#include <string>
#include <dirent.h>

class Organizer{
    public:
        virtual void sendFile(std::string path) = 0;
        bool isDir(const char *file);

};
