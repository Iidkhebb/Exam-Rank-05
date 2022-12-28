#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell * ptr) {
    if (ptr)
    {
        book.insert(std::pair<std::string, ASpell *>(ptr->getName(), ptr->clone()));
    }
}
void SpellBook::forgetSpell(std::string const &name) {
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
    {
        delete it->second;
    }
    book.erase(name);
}
ASpell* SpellBook::createSpell(std::string const &name) {
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if(it != book.end())
    {
        return book[name];
    }
    return NULL;
}
