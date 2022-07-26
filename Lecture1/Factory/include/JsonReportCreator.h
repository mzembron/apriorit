#ifndef JSONREPORTCREATOR_H
#define JSONREPORTCREATOR_H

#include <map>

#include <boost/json/src.hpp>
#include "ReportCreator.h"
#include "JsonReport.h"

class JsonReportCreator : public ReportCreator
{
    public:
        std::unique_ptr<Report> factoryMethod(const std::vector<FileInfo>& files_parameters) const override;
    private:
        boost::json::array prepareContent(const std::vector<FileInfo>& files_parameters) const;

};

#endif // JSONREPORTCREATOR_H
