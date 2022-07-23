#include "ReportCreator.h"

std::string ReportCreator::generateReport() const 
    {
        // change to unique ptr
        Report* report = this -> factoryMethod();
        std::string result = "Output report is: " + report -> returnReport();
        delete report;
        return result;
    }