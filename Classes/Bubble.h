//
// Created by Usuario on 06/05/2019.
//

#ifndef PROJ_ANDROID_STUDIO_BUBBLE_H
#define PROJ_ANDROID_STUDIO_BUBBLE_H

#include "cocos2d.h"
#include "Entity.h"

class Bubble : public Entity{
private:
    bool isTraveling;
public:
    Bubble(std::string textureName);
    Bubble(std::string textureName, float entityPositionX, float entityPositionY, float entityScale, cocos2d::Vec2 anchor);
    void BubbleMovement(cocos2d::Point location);
    void SetIsTraveling(bool _isTraveling);
    bool GetIsTraveling();
};


#endif //PROJ_ANDROID_STUDIO_BUBBLE_H
