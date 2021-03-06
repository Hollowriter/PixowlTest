//
// Created by Usuario on 07/05/2019.
//

#ifndef PROJ_ANDROID_STUDIO_EVILFISH_H
#define PROJ_ANDROID_STUDIO_EVILFISH_H

#include"cocos2d.h"
#include"Entity.h"


class EvilFish : public Entity {
private:
    const int spawningDistance = 600;
public:
    EvilFish(std::string textureName);
    EvilFish(std::string textureName, float entityPositionX, float entityPositionY, float entityScale, cocos2d::Vec2 anchor);
    void MovingTowardsPlayer(Entity * entity);
    void Relocate(Entity * entity, float playerLimitDistance);
    bool IntersectsPlayer(Entity * entity);
    int GetSpawningDistance();
};


#endif //PROJ_ANDROID_STUDIO_EVILFISH_H
