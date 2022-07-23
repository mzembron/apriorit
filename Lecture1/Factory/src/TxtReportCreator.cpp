#include "TxtReportCreator.h"

Report* TxtReportCreator::factoryMethod() const 
    {
        return new TxtReport();
    }