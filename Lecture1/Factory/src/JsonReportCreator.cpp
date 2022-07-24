#include "JsonReportCreator.h"

Report* JsonReportCreator::factoryMethod(std::vector<FileInfo> files_parameters) const 
    {
        return new JsonReport();
    }