#include "CsvReportCreator.h"

std::unique_ptr<Report> CsvReportCreator::factoryMethod(const std::vector<FileInfo>& files_parameters) const 
    {   
        std::string report_content = prepareContent(files_parameters);
        std::unique_ptr<TxtReport> txt_report(new TxtReport());
        txt_report -> setReport(report_content);
        return txt_report;
    }


std::string CsvReportCreator::prepareContent(const std::vector<FileInfo>& files_parameters) const
    {
        std::string report_content = extractPrefix(files_parameters);
        
        for (FileInfo file_info : files_parameters)
        {
            for (const file_descripion_param_pair& param_pair : file_info.getFileParameters() )
            {   
                report_content = report_content + param_pair.second + "; ";
            }
            report_content = report_content + " \n"; 
        }

        return report_content;
    }

std::string CsvReportCreator::extractPrefix(const std::vector<FileInfo>& files_parameters) const
{
    std::string prefix = "";
    if(files_parameters.size()>0)
    {
        for ( file_descripion_param_pair& param_pair : files_parameters[0].getFileParameters() )
        {   
            prefix = prefix + param_pair.first + "; ";
        }
    }
    return prefix;
}