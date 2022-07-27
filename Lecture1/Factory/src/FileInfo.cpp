#include "FileInfo.h"

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

FileInfo::FileInfo(std::filesystem::directory_entry entry) :  _path(entry.path()),
                                                    _name(entry.path().filename())
{

    try{
        auto ftime = entry.last_write_time();
        std::time_t cftime = to_time_t(ftime);
        _last_write_time = std::asctime(std::localtime(&cftime));
        _last_write_time.pop_back(); //deleteing new line char
    }
    catch(std::exception& exception)
    {
        std::cout << "Cannot read last write time from: " << _name << std::endl;
        _last_write_time = "Wed Jul 00 00:00:00 0000";
    }

    try{
        _size = entry.file_size();
    }
    catch(std::exception& exception)
    {
        std::cout << "Cannot read size of: " << _name << std::endl;
         _size = 0;
    }

}

file_parameters FileInfo::getFileParameters() const
{
    file_parameters file_info = {};
    file_info.push_back(file_descripion_param_pair("Name", _name));
    file_info.push_back(file_descripion_param_pair("Path", _path));
    file_info.push_back(file_descripion_param_pair("Size", 
        static_cast<std::stringstream>(std::stringstream() << _size).str() + " B"));
    file_info.push_back(file_descripion_param_pair("Last write time", _last_write_time));
    return file_info;
}