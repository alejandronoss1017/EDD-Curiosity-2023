#if !defined(ANALYSIS_HPP)
#define ANALYSIS_HPP

#include "../enums/analysisTypes.hpp"

#include <string>

using namespace std;

class Analysis
{
private:
    analysisTypes type;
    string objectName;
    string annotation;

public:
    Analysis(analysisTypes type, string objectName, string annotation);
    Analysis(analysisTypes type, string objectName);

    ~Analysis();

    /* Getters and Setters */
    analysisTypes getType() const;
    void setType(analysisTypes type);
    string getObjectName() const;
    void setObjectName(string objectName);
    string getAnnotation() const;
    void setAnnotation(string annotation);
};

#include "Analysis.cxx"

#endif // ANALYSIS_HPP
