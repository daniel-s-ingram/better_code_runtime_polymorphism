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
    history_t h(1);

    current(h).emplace_back(0);
    current(h).emplace_back(std::string("Hello!"));

    draw(current(h), std::cout, 0);
    std::cout << "-----------------------------------\n";

    commit(h);

    current(h)[0] = 42.5;
    current(h)[1] = std::string("World");
    current(h).emplace_back(current(h));
    current(h).emplace_back(my_class_t());

    draw(current(h), std::cout, 0);
    std::cout << "-----------------------------------\n";

    undo(h);   

    draw(current(h), std::cout, 0);
}