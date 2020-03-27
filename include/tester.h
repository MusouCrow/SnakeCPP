// A test component.

#ifndef TESTER_H
#define TESTER_H

#include "component.h"

class Tester : public Component {
public:
    void Init(int value);
    virtual void Update();
    void Fuck();
};

#endif