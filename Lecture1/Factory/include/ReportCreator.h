#ifndef REPORTCREATOR_H
#define REPORTCREATOR_H

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <vector>
#include <memory>
#include <utility>
#include <stdexcept>
#include "FileInfo.h"
#include "Report.h"


/**
* The RaportCreator class is responsible for returning an
* object of a Report class.
*/

class ReportCreator
{
    public:
        virtual ~ReportCreator(){};
        std::string generateReport(std::string dir_path) const;
    private:
        std::vector<FileInfo> getFilesParameters(std::string directory_path) const;
        virtual std::unique_ptr<Report> createReport(const std::vector<FileInfo>& files_parameters) const = 0;
};

#endif // REPORTCREATOR_H