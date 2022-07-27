#ifndef JSONREPORTCREATOR_H
#define JSONREPORTCREATOR_H


#include "ReportCreator.h"
#include "JsonReport.h"


/*
* Concrete json report creator class  
*/

class JsonReportCreator : public ReportCreator
{
    public:
        std::unique_ptr<Report> factoryMethod(const std::vector<FileInfo>& files_parameters) const override;
    private:
        std::string prepareContent(const std::vector<FileInfo>& files_parameters) const;

};

#endif // JSONREPORTCREATOR_H
