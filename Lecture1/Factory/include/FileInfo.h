#ifndef FILEINFO_H
#define FILEINFO_H
#include <filesystem>
#include <string>
#include <vector>
#include <any>
#include <variant>
#include <chrono>
#include <ctime>

typedef std::pair<std::string, std::string> file_descripion_param_pair;
// typedef std::vector<std::pair<std::string, std::any>> file_parameters;
typedef std::vector<file_descripion_param_pair> file_parameters;

class FileInfo
{
    public:
        FileInfo(std::filesystem::directory_entry entry);
        file_parameters getFileParameters();
    private:
        std::uintmax_t _size;
        std::string _path;
        std::string _name;
        std::string _last_write_time;
};

#endif // FILEINFO_H

