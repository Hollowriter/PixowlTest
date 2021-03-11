#ifndef PROJ_ANDROID_STUDIO_FISHPLAYER_H
#define PROJ_ANDROID_STUDIO_FISHPLAYER_H

#include "cocos2d.h"
#include "Entity.h"

class FishPlayer : public Entity {
public:
    FishPlayer(std::string textureName);
    FishPlayer(std::string textureName, float fishPositionX, float fishPositionY, float fishScale, cocos2d::Vec2 anchor);
    void RotateFish(float fishRotationX, float fishRotationY);
    void PlayerAnimation(bool isThereABubble);
};


#endif
