#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <string>
#include <vector>

using object_t = int;

void draw(const object_t& x, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << x << '\n';
}

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position)
{
    out << std::string(position,  ' ') << "<document>" << '\n';
    for (const auto& e: x)
        draw(e, out, position + 2);
    out << std::string(position, ' ') << "</document>" << '\n';
}

#endif