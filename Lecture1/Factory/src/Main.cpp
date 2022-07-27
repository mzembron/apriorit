#include <iostream>
#include <string>
#include <vector>
#include "CsvReportCreator.h"
#include "TxtReportCreator.h"


namespace fs = std::filesystem;


const std::string DIRECTORY_PATH = "/home/mateusz/apriorit/Lecture1/Factory";


void getReports()
{   
    std::vector<std::unique_ptr<ReportCreator>> report_creators;
    std::unique_ptr<ReportCreator> csv_creator(new CsvReportCreator());
    report_creators.push_back(std::move(csv_creator));
    std::unique_ptr<ReportCreator> txt_creator(new TxtReportCreator());
    report_creators.push_back(std::move(txt_creator));
    
    for(auto const &element : report_creators)
    {
        std::cout << element ->generateReport(DIRECTORY_PATH)<< "\n \n";
    }
}

int main()
{
    getReports();
    std::cout << std::endl;
}