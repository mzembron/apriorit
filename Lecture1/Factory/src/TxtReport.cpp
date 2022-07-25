#include "TxtReport.h" 

std::string TxtReport::returnReport() const 
    {
        return "{Txt report here}";
    }

void TxtReport::setReport(std::string content) 
    {
        _report_content = content;
    }