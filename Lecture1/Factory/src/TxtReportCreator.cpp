#include "TxtReportCreator.h"

std::unique_ptr<Report> TxtReportCreator::factoryMethod(const std::vector<FileInfo>& files_parameters) const 
    {   
        std::string report_content = prepareContent(files_parameters);
        std::unique_ptr<TxtReport> txt_report(new TxtReport());
        txt_report -> setReport(report_content);
        return txt_report;
    }


std::string TxtReportCreator::prepareContent(const std::vector<FileInfo>& files_parameters) const
    {
        std::string report_content = "";
        for (const FileInfo& file_info : files_parameters)
        {
            for (const file_descripion_param_pair& param_pair : file_info.getFileParameters() )
            {
                report_content = report_content + param_pair.first + ": "+ param_pair.second + "  ";
            }
            report_content = report_content + "\n"; 
        }

        return report_content;
    }