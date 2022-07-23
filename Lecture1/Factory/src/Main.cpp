#include <iostream>
#include "ReportCreator.h" 
#include "JsonReportCreator.h"



void ClientCode(ReportCreator& report_creator)
{
    std::cout<< "costam raport: " << report_creator.generateReport()
    <<std::endl;
}

int main()
{
    ReportCreator* creator = new JsonReportCreator();
    ClientCode(*creator);
    std::cout << std::endl;
}