// A function collection similar C#.

#ifndef EVENT_H
#define EVENT_H

#include <list>
#include <algorithm>
#include <functional>
#include "common.h"

template <class T, class ... Args> class Event {
public:
    void operator+=(function<T(Args...)> *func) {
        if (find(this->funcs.begin(), this->funcs.end(), func) != this->funcs.end()) {
            return;
        }
        
        this->funcs.push_back(func);
    };
    void operator-=(function<T(Args...)> *func) {
        auto iter = find(this->funcs.begin(), this->funcs.end(), func);

        if (iter == this->funcs.end()) {
            return;
        }
        
        this->funcs.erase(iter);
    };
    void operator()(Args... args) {
        for (auto f : this->funcs) {
            (*f)(args ...);
        }
    };
private:
    list<function<T(Args...)>*> funcs;
};

#endif