#ifndef TXTREPORT_H
#define TXTNREPORT_H


#include "Report.h"
#include <string>


/**
* Concrete - txt format, report 
*/


class TxtReport : public Report 
{
    public:
        std::string returnReport() const override;
};

#endif // TXTREPORT_H