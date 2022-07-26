#include <iostream>
#include <filesystem>
#include <string>
#include <typeinfo>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>


#include "CsvReportCreator.h"


namespace fs = std::filesystem;


void ClientCode(ReportCreator& report_creator)
{
    std::cout<< "costam raport: " << report_creator.generateReport("cost")
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


int main()
{
    std::unique_ptr<ReportCreator> creator(new CsvReportCreator());
    ClientCode(*creator);
    std::cout << std::endl;
}