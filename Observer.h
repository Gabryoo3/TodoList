//
// Created by gabry on 1/15/25.
//

#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include "Activity.h"


class Observer {

public:
    virtual void updateAdd(const Activity& act) = 0;
    virtual void updateComplete(const Activity& act) = 0;
    virtual void updateRemove(const Activity& act) = 0;
    virtual ~Observer() = default;
};

#endif //OBSERVER_H
