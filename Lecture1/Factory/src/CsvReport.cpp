#include "CsvReport.h" 

std::string CsvReport::returnReport() const
    {
        return _report_content;
    }

void CsvReport::setReport(std::string content) 
    {
        _report_content = content;
    }

