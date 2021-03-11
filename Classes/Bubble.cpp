//
// Created by Usuario on 06/05/2019.
//

#include "Bubble.h"

Bubble::Bubble(std::string textureName) : Entity(textureName)
{
}

Bubble::Bubble(std::string textureName, float entityPositionX, float entityPositionY,
               float entityScale, cocos2d::Vec2 anchor) : Entity(textureName, entityPositionX, entityPositionY, entityScale, anchor)
               {
               }