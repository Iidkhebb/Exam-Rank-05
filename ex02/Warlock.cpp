#include "Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title) : name(_name), title(_title)
{
    std::cout << this->name << ": This looks like another boring day."  << std::endl;
}



Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator bg = data.begin();
    std::map<std::string, ASpell *>::iterator end = data.end();

    while (bg != end)
    {
        delete bg->second;
        ++bg;
    }
    this->data.clear();
    
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
    mybook.learnSpell(ptr);
}

void Warlock::forgetSpell(std::string name)
{
    mybook.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const &object)
{
    ATarget const *test = 0;
    if (test == &object)
        return;
    ASpell *tmp = mybook.createSpell(name);
    if (tmp)
        tmp->launch(object);
}