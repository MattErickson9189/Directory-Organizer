#pragma once
#include <string>
#include <dirent.h>

class Organizer{
    public:
        void virtual sendFile(std::string path) =0;
        bool isDir(const char *file);

};
