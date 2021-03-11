#ifndef PROJ_ANDROID_STUDIO_FISHPLAYER_H
#define PROJ_ANDROID_STUDIO_FISHPLAYER_H

#include "cocos2d.h"
#include "Entity.h"
#include "Bubble.h"

class FishPlayer : public Entity {
private:
    const float playerLimitDistance = 200;
public:
    FishPlayer(std::string textureName);
    FishPlayer(std::string textureName, float fishPositionX, float fishPositionY, float fishScale, cocos2d::Vec2 anchor);
    void RotateFish(float fishRotationX, float fishRotationY);
    void Shoot(cocos2d::Touch * touch, Entity * entity, Bubble * bubble);
    void PlayerAnimation(bool isThereABubble);
    float GetPlayerLimitDistance();
};


#endif
