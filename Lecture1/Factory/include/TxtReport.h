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
        void setReport(std::string content);
    
    private:
        std::string _report_content;
};

#endif // TXTREPORT_H