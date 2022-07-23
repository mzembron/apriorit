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
};

#endif // JSONREPORT_H