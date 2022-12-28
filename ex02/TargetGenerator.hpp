#pragma once

#include <string>
#include <iostream>

#include "ATarget.hpp"
#include <map>
#include <utility>

class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator & operator=(TargetGenerator const &other);
        std::map<std::string, ATarget *> data;
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* ptr);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &name);
};