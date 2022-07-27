#ifndef CSVREPORTCREATOR_H
#define CSVREPORTCREATOR_H

#include <iostream>
#include <memory>
#include "ReportCreator.h"
#include "CsvReport.h"

/*
* Concrete csv report creator class  
*/

class CsvReportCreator : public ReportCreator
{
    public:
        std::unique_ptr<Report> factoryMethod(const std::vector<FileInfo>& files_parameters) const override;
        
    private:
        std::string prepareContent(const std::vector<FileInfo>& files_parameters) const;
        std::string extractPrefix(const std::vector<FileInfo>& files_parameters) const;
};

#endif // CSVREPORTCREATOR_H