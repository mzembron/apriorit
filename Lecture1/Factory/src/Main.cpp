#include <iostream>
#include <filesystem>
#include <string>
#include <typeinfo>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "ReportCreator.h" 
#include "JsonReportCreator.h"

namespace fs = std::filesystem;


void ClientCode(ReportCreator& report_creator)
{
    std::cout<< "costam raport: " << report_creator.generateReport()
    <<std::endl;
}

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

// std::string to_string(std::filesystem::file_time_type const& ftime) {
//     std::time_t cftime = std::chrono::system_clock::to_time_t(
//         std::chrono::file_clock::to_sys(ftime));
//     std::string str = std::asctime(std::localtime(&cftime));
//     str.pop_back();  // rm the trailing '\n' put by `asctime`
//     return str;
// }

int main()
{
    ReportCreator* creator = new JsonReportCreator();
    ClientCode(*creator);
    std::cout << std::endl;
//     std::string path = "..";
    
//     for (const auto &entry : fs::recursive_directory_iterator(path))
//     {
//         std::cout << entry.path() << std::endl;
//         // std::filesystem::file_time_type ftime = std::filesystem::last_write_time(entry);
// //        std::cout << std::format("File write time is {}\n", ftime);
// //        long last_write_time = entry.last_write_time();
//         if(entry.is_directory() == false) 
//         {
//             std::cout << entry.file_size() << std::endl;
//         }
//         auto costam = std::filesystem::last_write_time(entry).time_since_epoch();
        
//         auto ftime = entry.last_write_time();
//         std::time_t cftime = to_time_t(ftime);
//         std::cout << "File write time is " << std::asctime(std::localtime(&cftime)) << '\n';

//         //cs
//         // std::cout<<"Last write time: " << 
//         // std::cout << to_string(entry.last_write_time());
//         std::cout << entry.path().filename() << std::endl;
//     }
}