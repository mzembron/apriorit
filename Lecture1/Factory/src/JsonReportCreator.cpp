#include "JsonReportCreator.h"


std::unique_ptr<Report> JsonReportCreator::factoryMethod(const std::vector<FileInfo>& files_parameters) const 
    {
        std::string report_content = prepareContent(files_parameters);
        return std::unique_ptr<Report>(new JsonReport());
    }
std::string JsonReportCreator::prepareContent(const std::vector<FileInfo>& files_parameters) const
    {
        std::string content = "";
        return content;
    }