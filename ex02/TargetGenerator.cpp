#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator() {
    std::map<std::string, ATarget *>::iterator bg = data.begin();
    while (bg != data.end())
    {
        delete bg->second;
        ++bg;
    }
    this->data.clear();
}


void TargetGenerator::learnTargetType(ATarget* ptr)
{
    if (ptr)
    {
        data.insert(std::pair<std::string, ATarget *>(ptr->getType(), ptr->clone()));
    }
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
    std::map<std::string, ATarget *>::iterator it = data.find(name);
    if (it != data.end())
    {
        delete it->second;
    }
    data.erase(name);
}

ATarget* TargetGenerator::createTarget(std::string const &name)
{
    std::map<std::string, ATarget *>::iterator it = data.find(name);

    if (it != data.end())
    {
        return data[name];
    }
    return NULL;
}