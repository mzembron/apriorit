#include "JsonReportCreator.h"

Report* JsonReportCreator::factoryMethod(const std::vector<FileInfo>& files_parameters) const 
    {
        return new JsonReport();
    }