// A function collection similar C#.

#ifndef EVENT_H
#define EVENT_H

#include <set>
#include <functional>
#include "common.h"

template <class T, class ... Args> class Event {
public:
    void operator+=(function<T(Args...)> *func) {
        if (this->func_set.find(func) != this->func_set.end()) {
            return;
        }
        
        this->func_set.insert(func);
    };
    void operator-=(function<T(Args...)> *func) {
        if (this->func_set.find(func) == this->func_set.end()) {
            return;
        }
        
        this->func_set.erase(func);
    };
    void operator()(Args... args) {
        for (auto f : this->func_set) {
            (*f)(args ...);
        }
    };
private:
    set<function<T(Args...)>*> func_set;
};

#endif