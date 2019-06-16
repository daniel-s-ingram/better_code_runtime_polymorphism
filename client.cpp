#include "library.hpp"

class my_class_t
{ };

void draw(const my_class_t&, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << "my_class_t\n";
}

int main()
{
    document_t document;

    document.emplace_back(0);
    document.emplace_back(std::string("Hello"));
    document.emplace_back(2);
    document.emplace_back(my_class_t());

    draw(document, std::cout, 0);
}