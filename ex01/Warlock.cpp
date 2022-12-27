#include "Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title) : name(_name), title(_title)
{
    std::cout << this->name << ": This looks like another boring day."  << std::endl;
}



Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}

//setter & getters
 
std::string const & Warlock::getName() const
{
    return this->name;
}

std::string const & Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string &_title)
{
    this->title = _title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *ptr)
{
    if (ptr)
    {
        data.insert(std::pair<std::string, ASpell *>(ptr->getName(), ptr->clone()));
    }
}

void Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell *>::iterator it = data.find(name);
    if (it != data.end())
    {
        delete it->second;
    }
    data.erase(name);
}

void Warlock::launchSpell(std::string name, ATarget const &object)
{
    ASpell *ptr = data[name];
    if (ptr)
    {
        ptr->launch(object);
    }
}