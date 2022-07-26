#include "JsonReportCreator.h"


std::unique_ptr<Report> JsonReportCreator::factoryMethod(const std::vector<FileInfo>& files_parameters) const 
    {
        boost::json::array arr = prepareContent(files_parameters);
        std::cout<< boost::json::serialize(arr);
        return std::unique_ptr<Report>(new JsonReport());
    }

boost::json::array JsonReportCreator::prepareContent(const std::vector<FileInfo>& files_parameters) const
    {

        boost::json::monotonic_resource mr;                          // memory resource optimized for insertion
        boost::json::array arr( &mr );                               // construct using the memory resource
        int mem_size = files_parameters.size();
        arr.resize( mem_size);
    // for (int i = 1; i < mem_size; ++i )
    // {
    //     arr[ i ] = jv;
    // }
                                    // make space for one element
        // std::string report_content = "";
        int index = 0;
        for (FileInfo file_info : files_parameters)
        {   
            std::map<std::string, std::string>  parameter_map;
            for (const file_descripion_param_pair& param_pair : file_info.getFileParameters() )
            {
                parameter_map.insert({param_pair.first, param_pair.second});
            }
            boost::json::value jv = boost::json::value_from(parameter_map);
            arr[ index ] = jv;
            ++index;
        }

        return arr;   
    }