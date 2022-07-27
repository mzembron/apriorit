#ifndef TXTREPORT_H
#define TXTNREPORT_H


#include "Report.h"
#include <string>
#include <fstream>
#include <filesystem>

/**
* Concrete report - txt format 
*/


class TxtReport : public Report 
{
    public:
        // std::string returnReport() const override;
        std::string getType() const override;
    //     void setReport(std::string content);
    // private:
    //     std::string _report_content;
};

#endif // TXTREPORT_H