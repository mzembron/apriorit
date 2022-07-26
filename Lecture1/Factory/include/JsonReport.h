#ifndef JSONREPORT_H
#define JSONREPORT_H

#include "Report.h"
#include <string>

/**
* Concrete - json format, report 
*/

class JsonReport : public Report
{
    public:
        std::string returnReport() const override;
    private:
        std::string _report_content;
};

#endif // JSONREPORT_H