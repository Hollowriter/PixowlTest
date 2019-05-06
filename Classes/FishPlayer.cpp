//
// Created by Usuario on 30/04/2019.
//

#include "FishPlayer.h"

FishPlayer::FishPlayer(std::string textureName) : Entity(textureName)
{
    /*_textureName = textureName;
    _fishSprite = cocos2d::Sprite::create(_textureName);
    addChild(_fishSprite);
    _anchor = cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM;
    _fishPositionX = 0;
    _fishPositionY = 0;
    _fishScale = 0;
    setPosition(_fishPositionX, _fishPositionY);
    setScale(_fishScale);
    _fishSprite->setTexture(_textureName);
    setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);*/
}

FishPlayer::FishPlayer(std::string textureName, float fishPositionX, float fishPositionY,
        float fishScale, cocos2d::Vec2 anchor) : Entity(textureName, fishPositionX, fishPositionY, fishScale, anchor)
{
    /*_textureName = textureName;
    _fishSprite = cocos2d::Sprite::create(textureName);
    addChild(_fishSprite);
    _anchor = anchor;
    _fishPositionX = fishPositionX;
    _fishPositionY = fishPositionY;
    _fishScale = fishScale;
    setPosition(_fishPositionX, _fishPositionY);
    setScale(_fishScale);
    _fishSprite->setTexture(_textureName);
    setAnchorPoint(_anchor);*/
}

void FishPlayer::RotateFish(float fishRotationX, float fishRotationY)
{
    stopAllActions();
    cocos2d::Vec2 vectorLocation = cocos2d::Vec2(getPosition().x - fishRotationX, getPosition().y - fishRotationY);
    float fishTotalRotation = vectorLocation.getAngle();
    auto rotateAction = cocos2d::RotateTo::create(1.0, CC_RADIANS_TO_DEGREES(fishTotalRotation));
    runAction(rotateAction);
}

/*void FishPlayer::SetSprite(cocos2d::Sprite *fishSprite)
{
    _fishSprite = fishSprite;
    if (getChildren().size() == 0)
    {
        addChild(_fishSprite);
    }
}

void FishPlayer::SetAnchor(cocos2d::Vec2 anchor)
{
    _anchor = anchor;
    setAnchorPoint(_anchor);
    // _fishSprite->setAnchorPoint(_anchor);
}

void FishPlayer::SetTexture(std::string textureName)
{
    _textureName = textureName;
    _fishSprite->setTexture(textureName);
}

void FishPlayer::SetFishPositionX(float fishPositionX)
{
    _fishPositionX = fishPositionX;
    setPosition(_fishPositionX, _fishPositionY);
    // _fishSprite->setPosition(_fishPositionX, _fishPositionY);
}

void FishPlayer::SetFishPositionY(float fishPositionY)
{
    _fishPositionY = fishPositionY;
    setPosition(_fishPositionX, _fishPositionY);
    // _fishSprite->setPosition(_fishPositionX, _fishPositionY);
}

void FishPlayer::SetFishScale(float fishScale)
{
    _fishScale = fishScale;
    setScale(_fishScale);
    // _fishSprite->setScale(_fishScale);
}

cocos2d::Sprite* FishPlayer::GetSprite()
{
    return _fishSprite;
}

cocos2d::Vec2 FishPlayer::GetAnchor()
{
    return _anchor;
}

std::string FishPlayer::GetTexture()
{
    return _textureName;
}

float FishPlayer::GetFishPositionX()
{
    return _fishPositionX;
}
float FishPlayer::GetFishPositionY()
{
    return _fishPositionY;
}

float FishPlayer::GetFishScale()
{
    return _fishScale;
}*/