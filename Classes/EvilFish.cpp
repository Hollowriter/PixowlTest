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

/*void EvilFish::IntersectBubbleAndRelocate(Entity *bubble, Entity *player, float spawningDistance, float playerLimitDistance)
{
    if (bubble->getBoundingBox().intersectsRect(getBoundingBox()))
    {
        bool randomGot = false;
        float newPositionX = 0;
        float newPositionY = 0;
        do {
            newPositionX = cocos2d::RandomHelper::random_int(1, spawningDistance);
            newPositionY = cocos2d::RandomHelper::random_int(1, spawningDistance);
            if (newPositionX != player->getPosition().x || newPositionY != player->getPosition().y)
            {
                if (newPositionX != player->getPosition().x)
                {
                    if (newPositionX - player->getPosition().x > 0)
                    {
                        if (newPositionX - player->getPosition().x > playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                    if (newPositionX - player->getPosition().x < 0)
                    {
                        if (newPositionX - player->getPosition().x < -playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                }
                if (newPositionY != player->getPosition().y)
                {
                    if (newPositionY - player->getPosition().y > 0)
                    {
                        if (newPositionY - player->getPosition().y > playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                    if (newPositionY - player->getPosition().y < 0)
                    {
                        if (newPositionY - player->getPosition().y < -playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                }
            }
        } while(!randomGot);
        stopAllActions();
        setPosition(newPositionX, newPositionY);
        MovingTowardsPlayer(player);
    }
}*/

bool EvilFish::IntersectsPlayer(Entity *entity)
{
    if (getBoundingBox().intersectsRect(entity->getBoundingBox()))
    {
        return true;
    }
    return false;
}
