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
        std::cout << "Raport: \n" << element ->generateReport(DIRECTORY_PATH);
    }
}

int main()
{
    
    // std::unique_ptr<ReportCreator> creator(new CsvReportCreator());
    // ClientCode(*creator);
    getReports();
    std::cout << std::endl;
}