#ifndef REPORTCREATOR_H
#define REPORTCREATOR_H

#include "Report.h"
#include <string>

/**
* The RaportCreator class is responsible for returning an
* object of a Report class.
*/

class ReportCreator
{
    public:
        virtual ~ReportCreator(){};
        virtual Report* factoryMethod() const = 0;
        std::string generateReport() const;
};

#endif // REPORTCREATOR_H