#include "ReportCreator.h"

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

std::string ReportCreator::generateReport(std::string dir_path) const 
    {

        std::vector<FileInfo> files_parameters= getFilesParameters(dir_path);
        std::unique_ptr<Report> report(std::move(this -> factoryMethod(files_parameters)));
        std::string result = "Output report is: \n" + report -> returnReport();
        return result;
    }

std::vector<FileInfo> ReportCreator::getFilesParameters(std::string directory_path) const
    {
        std::vector<FileInfo> files_info = {};
        try{
            for (const auto &entry : std::filesystem::recursive_directory_iterator(directory_path))
            {
                if(entry.is_directory() == false) 
                {
                    FileInfo file_info(entry);
                    files_info.push_back(file_info);
                }        
            }
            return files_info;
        }
        catch(const std::filesystem::filesystem_error& fs_error)
        {
            throw(std::runtime_error("Directory not found! Check provided directory."));
        }
    }