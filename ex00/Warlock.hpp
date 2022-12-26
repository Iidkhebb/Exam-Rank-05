#pragma once

#include <string>
#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;
        
        Warlock();
        Warlock &operator=(Warlock const &other);
        Warlock(Warlock const &other);
    
    public:
        Warlock(std::string const &_name, std::string const &_title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(const std::string &_title);

        void introduce() const;

};