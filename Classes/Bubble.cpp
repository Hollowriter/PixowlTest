//
// Created by Usuario on 06/05/2019.
//

#include "Bubble.h"

Bubble::Bubble(std::string textureName) : Entity(textureName)
{
    isTraveling = false;
}

Bubble::Bubble(std::string textureName, float entityPositionX, float entityPositionY,
               float entityScale, cocos2d::Vec2 anchor) : Entity(textureName, entityPositionX, entityPositionY, entityScale, anchor)
               {
    isTraveling = false;
               }

void Bubble::BubbleMovement(cocos2d::Point location)
{
    auto action = cocos2d::MoveTo::create(0.5f, location);
    runAction(action);
}

void Bubble::SetIsTraveling(bool _isTraveling)
{
    isTraveling = _isTraveling;
}

bool Bubble::GetIsTraveling()
{
    return isTraveling;
}