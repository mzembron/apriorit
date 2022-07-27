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
        virtual std::string getType() const = 0;
        std::string returnReport() const;
        void setReport(std::string content);
    private:
        std::string _report_content;
};

#endif // REPORT_H
