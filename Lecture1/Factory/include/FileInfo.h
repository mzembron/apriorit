#ifndef FILEINFO_H
#define FILEINFO_H
#include <filesystem>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <system_error>
#include <exception>


typedef std::pair<std::string, std::string> file_descripion_param_pair;
typedef std::vector<file_descripion_param_pair> file_parameters;

/*
* FileInfo class - contains and manages specific file parameters
*/

class FileInfo
{
    public:
        FileInfo(std::filesystem::directory_entry entry);
        file_parameters getFileParameters() const;
    private:
        std::uintmax_t _size;
        std::string _path;
        std::string _name;
        std::string _last_write_time;
        bool _is_block_file;
};

#endif // FILEINFO_H

