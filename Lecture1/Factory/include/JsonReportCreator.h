#ifndef JSONREPORTCREATOR_H
#define JSONREPORTCREATOR_H

#include "ReportCreator.h"
#include "JsonReport.h"

class JsonReportCreator : public ReportCreator
{
    public:
         Report* factoryMethod(const std::vector<FileInfo>& files_parameters) const override;

};

#endif // JSONREPORTCREATOR_H
