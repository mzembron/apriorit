#ifndef REPORTCREATOR_H
#define REPORTCREATOR_H

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <vector>
#include <memory>
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
        virtual Report* factoryMethod(std::vector<FileInfo> files_parameters) const = 0;
        std::string generateReport() const;
    private:
        std::vector<FileInfo> getFilesParameters(std::string directory_path) const;
};

#endif // REPORTCREATOR_H