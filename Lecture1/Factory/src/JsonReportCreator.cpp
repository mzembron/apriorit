#include "JsonReportCreator.h"

Report* JsonReportCreator::factoryMethod() const 
    {
        return new JsonReport();
    }