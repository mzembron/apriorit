#ifndef FILEINFO_H
#define FILEINFO_H

#include <string>

struct FileInfo
{
    std::uintmax_t size;
    std::string path;
    std::string name;
    std::string last_write_time;
};

#endif // FILEINFO_H

