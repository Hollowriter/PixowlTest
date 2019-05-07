//
// Created by Usuario on 07/05/2019.
//

#include "EvilFish.h"

EvilFish::EvilFish(std::string textureName) : Entity(textureName)
{
}

EvilFish::EvilFish(std::string textureName, float entityPositionX, float entityPositionY,
        float entityScale, cocos2d::Vec2 anchor) : Entity(textureName, entityPositionX, entityPositionY,
                entityScale, anchor)
{
}