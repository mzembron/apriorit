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
    private:
        std::unique_ptr<Report> createReport(const std::vector<FileInfo>& files_parameters) const override;
        std::string prepareContent(const std::vector<FileInfo>& files_parameters) const;
        std::string extractPrefix(const std::vector<FileInfo>& files_parameters) const;
};

#endif // CSVREPORTCREATOR_H