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
    object_t(const int& x) : self_(std::make_unique<int_model_t>(x)) {}

    object_t(const object_t& x) : self_(std::make_unique<int_model_t>(*x.self_)) {}
    
    object_t& operator=(const object_t& x)
    {
        object_t tmp(x);
        self_ = std::move(tmp.self_);
        return *this;
    }

    friend void draw(const object_t& x, std::ostream& out, size_t position)
    {
        x.self_->draw_(out, position);
    }

private:
    struct int_model_t
    {
        int_model_t(const int& x) : data_(x) {}

        void draw_(std::ostream& out, size_t position) const
        {
            draw(data_, out, position);
        }

        int data_;
    };

    std::unique_ptr<int_model_t> self_;
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