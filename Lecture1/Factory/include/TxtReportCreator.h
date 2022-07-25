#ifndef TXTREPORTCREATOR_H
#define TXTREPORTCREATOR_H

#include <iostream>
#include "ReportCreator.h"
#include "TxtReport.h"

class TxtReportCreator : public ReportCreator
{
    public:
         Report* factoryMethod(const std::vector<FileInfo>& files_parameters) const override;
        
    private:
        std::string prepareContent(const std::vector<FileInfo>& files_parameters) const;
};

#endif // TXTREPORTCREATOR_H