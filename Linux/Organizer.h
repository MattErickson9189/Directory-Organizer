#include <string>
#include <dirent.h>

class Organizer{
    public:
        void sendFile(std::string path);
        bool isDir(const char *file);

};
