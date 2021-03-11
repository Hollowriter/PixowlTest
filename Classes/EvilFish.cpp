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

void EvilFish::MovingTowardsPlayer(Entity *entity)
{
    auto action = cocos2d::MoveTo::create(5.0, entity->getPosition());
    runAction(action);
}

bool EvilFish::IntersectsPlayer(Entity *entity)
{
    if (getBoundingBox().intersectsRect(entity->getBoundingBox()))
    {
        return true;
    }
    return false;
}
