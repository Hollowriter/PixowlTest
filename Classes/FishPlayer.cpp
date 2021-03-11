//
// Created by Usuario on 30/04/2019.
//

#include "FishPlayer.h"

FishPlayer::FishPlayer(std::string textureName) : Entity(textureName)
{
}

FishPlayer::FishPlayer(std::string textureName, float fishPositionX, float fishPositionY,
        float fishScale, cocos2d::Vec2 anchor) : Entity(textureName, fishPositionX, fishPositionY, fishScale, anchor)
{
}

void FishPlayer::RotateFish(float fishRotationX, float fishRotationY)
{
    stopAllActions();
    cocos2d::Vec2 vectorLocation = cocos2d::Vec2(getPosition().x - fishRotationX, getPosition().y - fishRotationY);
    float fishTotalRotation = vectorLocation.getAngle();
    auto rotateAction = cocos2d::RotateTo::create(1.0, CC_RADIANS_TO_DEGREES(fishTotalRotation));
    runAction(rotateAction);
}

void FishPlayer::PlayerAnimation(bool isThereABubble)
{
    if (isThereABubble)
    {
        SetTexture("fishBubble.png");
    }
    else {
        SetTexture("fish.png");
    }
}