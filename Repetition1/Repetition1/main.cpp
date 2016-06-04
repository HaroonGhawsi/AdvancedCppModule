#include <memory>
#include "person.h"


std::ostream &operator << (std::ostream &os, Person const &p){

    p.dump(os);
    return os;
}

class Room{

    public:
    Room(std::string const &name, std::string const &location)

        : m_name(name), m_location(location), m_responsiblePerson(){;}

void setResponsiblePerson(std::shared_ptr<Person> const &person){

    m_responsiblePerson = person;
}
void dump(std::ostream &os) const{

    std::shared_ptr<Person> ptr = m_responsiblePerson;


    if(ptr){

        os << "Room " << m_name << "at" << m_location << ". Responsible: " << *ptr;
    }
    else {
        os << "Room " << m_name << "at" << m_location << "." << std::endl;
    }
}

protected:
std::string m_name;
std::string m_location;
std::shared_ptr<Person> m_responsiblePerson;
};

int main(){

    Room smallhall("small hall", "Building 10");
    Room greathall("Great Hall", "Building 11");
    {
    std::shared_ptr<Person> foo{new Person("John Doe", "01234")};
    smallhall.setResponsiblePerson(foo);
    }
    smallhall.dump(std::cout);
    greathall.dump(std::cout);
    {
        std::shared_ptr<Person> bart;
        std::shared_ptr<Person> lisa;
    {
        std::unique_ptr<Person> hommer{new Person("Hommer", "999")};
        std::unique_ptr<Person> marge{new Person("Marge", "999")};
        bart = std::shared_ptr<Person>(new Person("Bart", "999"));
        lisa = std::shared_ptr<Person>(new Person("lisa", "999"));
    }
    smallhall.setResponsiblePerson(lisa);
    greathall.setResponsiblePerson(lisa);
    }
smallhall.dump(std::cout);
greathall.dump(std::cout);
}
