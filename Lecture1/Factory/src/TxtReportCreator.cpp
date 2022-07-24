#include "TxtReportCreator.h"

Report* TxtReportCreator::factoryMethod(std::vector<FileInfo> files_parameters) const 
    {
        return new TxtReport();
    }