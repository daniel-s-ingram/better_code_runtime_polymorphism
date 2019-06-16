#include "library.hpp"

class my_class_t
{
    friend std::ostream& operator<<(std::ostream& os, const my_class_t& class_t);
};

std::ostream& operator<<(std::ostream& os, const my_class_t& class_t)
{
    os << "my_class_t";
}

int main()
{
    document_t document;

    document.emplace_back(0);
    document.emplace_back(std::string("Hello"));
    document.emplace_back(document);
    document.emplace_back(my_class_t());

    draw(document, std::cout, 0);
}