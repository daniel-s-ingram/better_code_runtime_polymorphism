#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

void draw(const int& x, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << x << '\n';
}

class object_t
{
public:
    object_t(const int& x) : self_(x) {}
    
    friend void draw(const object_t& x, std::ostream& out, size_t position)
    {
        draw(x.self_, out, position);
    }

private:
    int self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position)
{
    out << std::string(position,  ' ') << "<document>" << '\n';
    for (const auto& e: x)
        draw(e, out, position + 2);
    out << std::string(position, ' ') << "</document>" << '\n';
}

#endif