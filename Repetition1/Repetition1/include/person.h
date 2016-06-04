#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person
{
    public:
        Person(std::string const &name, std::string const &phone)

            : m_name(name), m_phone(phone){

                std::cout << "Constructed Person " << m_name << ", " << m_phone << std::endl;
            }
        virtual ~Person(){

                std::cout << "Destructed Person " << m_name << ", " << m_phone << std::endl;
        };

        void dump(std::ostream &os) const{

            os << "Person: " << std::endl;
            os << " Name: " << std::endl;
            os << " Phone: " << std::endl;
        }
    protected:
    private:

    std::string m_name;
    std::string m_phone;
};

#endif // PERSON_H
