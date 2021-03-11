//
// Created by Usuario on 06/05/2019.
//

#ifndef PROJ_ANDROID_STUDIO_BUBBLE_H
#define PROJ_ANDROID_STUDIO_BUBBLE_H

#include "cocos2d.h"
#include "Entity.h"

class Bubble : public Entity{
public:
    Bubble(std::string textureName);
    Bubble(std::string textureName, float entityPositionX, float entityPositionY, float entityScale, cocos2d::Vec2 anchor);
};


#endif //PROJ_ANDROID_STUDIO_BUBBLE_H
