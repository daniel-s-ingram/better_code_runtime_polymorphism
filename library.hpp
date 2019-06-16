#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

void draw(const std::string& x, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << x << '\n';
}

void draw(const int& x, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << x << '\n';
}

class object_t
{
public:
    object_t(int x) : self_(std::make_unique<int_model_t>(std::move(x)))
    { }

    object_t(std::string x) : self_(std::make_unique<string_model_t>(std::move(x)))
    { }

    object_t(const object_t& x) : self_(x.self_->copy_())
    { }

    object_t(object_t&&) noexcept = default;
    
    object_t& operator=(const object_t& x)
    {
        return *this = object_t(x);
    }

    object_t& operator=(object_t&&) noexcept = default;

    friend void draw(const object_t& x, std::ostream& out, size_t position)
    {
        x.self_->draw_(out, position);
    }

private:
    struct concept_t
    {
        virtual ~concept_t() = default;
        virtual std::unique_ptr<concept_t> copy_() const = 0;
        virtual void draw_(std::ostream&, size_t) const = 0;
    };

    struct int_model_t final : concept_t
    {
        int_model_t(int x) : data_(std::move(x))
        { }

        std::unique_ptr<concept_t> copy_() const override
        {
            return std::make_unique<int_model_t>(*this);
        }

        void draw_(std::ostream& out, size_t position) const override
        {
            draw(data_, out, position);
        }

        int data_;
    };

    struct string_model_t final : concept_t
    {
        string_model_t(std::string x) : data_(std::move(x))
        { }

        std::unique_ptr<concept_t> copy_() const override
        {
            return std::make_unique<string_model_t>(*this);
        }

        void draw_(std::ostream& out, size_t position) const override
        {
            draw(data_, out, position);
        }

        std::string data_;
    };

    std::unique_ptr<concept_t> self_;
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