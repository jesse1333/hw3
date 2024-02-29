#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack
{
private:
    std::vector<T> *v;

public:
    Stack()
    {
        v = new std::vector<T>();
    }

    ~Stack()
    {
        delete v;
    }

    bool empty() const
    {
        if (v -> empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    size_t size() const
    {
        return v->size();
    }
    void push(const T &item)
    {
        v->push_back(item);
    }
    void pop()
    {
        if (v->empty())
        {
            throw std::underflow_error("No items to pop.");
        }
        else
        {
            v->pop_back();
        }
    }
    const T &top() const
    {
        if (v->empty())
        {
            throw std::underflow_error("No items to show.");
        }
        else
        {
            return v -> back();
        }
    }
    // Add other members only if necessary
};

#endif