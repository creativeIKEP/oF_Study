#ifndef RandomWalker_hpp
#define RandomWalker_hpp

#pragma once
#include "ofMain.h"
#include <stdio.h>

class RandomWalker{
public:
    RandomWalker();
    void draw();
    
    glm::vec2 position;
};

#endif /* RandomWalker_hpp */
