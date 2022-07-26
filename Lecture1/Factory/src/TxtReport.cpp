#include "TxtReport.h" 

std::string TxtReport::returnReport() const
    {
        return _report_content;
    }

void TxtReport::setReport(std::string content) 
    {
        _report_content = content;
    }

