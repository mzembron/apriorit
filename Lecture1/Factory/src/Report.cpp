#include "Report.h"

std::string Report::returnReport() const
    {
        return _report_content;
    }

void Report::setReport(std::string content) 
    {
        _report_content = content;
    }