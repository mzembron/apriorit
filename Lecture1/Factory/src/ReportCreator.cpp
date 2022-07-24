#include "ReportCreator.h"

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

std::string ReportCreator::generateReport() const 
    {
        // change to unique ptr
        std::string path = "..";
        std::vector<FileInfo> files_parameters= getFilesParameters(path);
        std::unique_ptr<Report> report(this -> factoryMethod(files_parameters));
        std::string result = "Output report is: " + report -> returnReport();
        // delete report;
        return result;
    }

std::vector<FileInfo> ReportCreator::getFilesParameters(std::string directory_path) const
    {
        std::vector<FileInfo> files_info = {};

        for (const auto &entry : std::filesystem::recursive_directory_iterator(directory_path))
        {
            if(entry.is_directory() == false) 
            {
                FileInfo file_info;
                std::cout << entry.path() << std::endl;
                file_info.path = entry.path();
                std::cout << entry.path().filename() << std::endl;
                file_info.name = entry.path().filename();
                auto ftime = entry.last_write_time();
                std::time_t cftime = to_time_t(ftime);
                std::cout << "File write time is " << std::asctime(std::localtime(&cftime)) << '\n';
                file_info.last_write_time = std::asctime(std::localtime(&cftime));
                std::cout << entry.file_size() << " B" << std::endl;
                file_info.size = entry.file_size();
                files_info.push_back(file_info);
            }        
        }
        return files_info;


    }