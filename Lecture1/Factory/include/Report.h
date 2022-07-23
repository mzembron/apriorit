#ifndef REPORT_H
#define REPORT_H

#include <string>

/**
* Trhe report interface declares the operations that all concrete reports
* must implement
*/

class Report
{
    public:
        virtual ~Report() {};
        virtual std::string returnReport() const = 0;
};

#endif // REPORT_H
