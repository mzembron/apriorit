#ifndef TXTREPORTCREATOR_H
#define TXTREPORTCREATOR_H

#include "ReportCreator.h"
#include "TxtReport.h"

class TxtReportCreator : public ReportCreator
{
    public:
         Report* factoryMethod() const override;
};

#endif // TXTREPORTCREATOR_H