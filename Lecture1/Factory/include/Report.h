#ifndef REPORT_H
#define REPORT_H

#include <string>

/**
* The report inteface
*/

class Report
{
    public:
        virtual ~Report() {};
        virtual std::string returnReport() const = 0;
};

#endif // REPORT_H
