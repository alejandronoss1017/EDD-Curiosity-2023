#include "Analysis.hpp"

Analysis::Analysis(analysisTypes type, string objectName, string annotation)
{
    this->type = type;
    this->objectName = objectName;
    this->annotation = annotation;
}

Analysis::Analysis(analysisTypes type, string objectName)
{
    this->type = type;
    this->objectName = objectName;
    this->annotation = "";
}

Analysis::~Analysis()
{
}

analysisTypes Analysis::getType() const
{
    return type;
}

void Analysis::setType(analysisTypes type)
{
    this->type = type;
}

string Analysis::getObjectName() const
{
    return objectName;
}

void Analysis::setObjectName(string objectName)
{
    this->objectName = objectName;
}

string Analysis::getAnnotation() const
{
    return annotation;
}

void Analysis::setAnnotation(string annotation)
{
    this->annotation = annotation;
}