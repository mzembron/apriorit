#ifndef CSVREPORT_H
#define CSVNREPORT_H


#include "Report.h"
#include <string>


/**
* Concrete report- csv format 
*/


class CsvReport : public Report 
{
    public:
        std::string returnReport() const override;
        void setReport(std::string content);
    private:
        std::string _report_content;
};

#endif // CSVREPORT_H