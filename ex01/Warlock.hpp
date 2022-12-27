#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"
#include <map>
#include <utility>

class Warlock
{
    private:
        std::string name;
        std::string title;
        
        Warlock();
        Warlock &operator=(Warlock const &other);
        Warlock(Warlock const &other);
        std::map<std::string, ASpell *> data;
    
    public:
        Warlock(std::string const &_name, std::string const &_title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(const std::string &_title);

        void introduce() const;

        void learnSpell(ASpell *ptr);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const &object);

};