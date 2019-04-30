//
// Created by Usuario on 30/04/2019.
//

#include "FishPlayer.h"

FishPlayer::FishPlayer(std::string textureName)
{
    _textureName = textureName;
    _fishSprite = cocos2d::Sprite::create(textureName);
    _anchor = cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM;
    _fishPositionX = 0;
    _fishPositionY = 0;
    _fishScale = 0;
    _fishSprite->setPosition(_fishPositionX, _fishPositionY);
    _fishSprite->setScale(_fishScale);
    _fishSprite->setTexture(_textureName);
}

FishPlayer::FishPlayer(std::string textureName, cocos2d::Vec2 anchor, float fishPositionX, float fishPositionY, float fishScale)
{
    _textureName = textureName;
    _fishSprite = cocos2d::Sprite::create(textureName);
    _anchor = anchor;
    _fishPositionX = fishPositionX;
    _fishPositionY = fishPositionY;
    _fishScale = fishScale;
    _fishSprite->setPosition(_fishPositionX, _fishPositionY);
    _fishSprite->setScale(_fishScale);
    _fishSprite->setTexture(_textureName);
}

void FishPlayer::SetSprite(cocos2d::Sprite *fishSprite)
{
    _fishSprite = fishSprite;
}

void FishPlayer::SetAnchor(cocos2d::Vec2 anchor)
{
    _anchor = anchor;
}

void FishPlayer::SetTexture(std::string textureName)
{
    _textureName = textureName;
    _fishSprite->setTexture(textureName);
}

void FishPlayer::SetFishPositionX(float fishPositionX)
{
    _fishPositionX = fishPositionX;
    _fishSprite->setPosition(_fishPositionX, _fishPositionY);
}

void FishPlayer::SetFishPositionY(float fishPositionY)
{
    _fishPositionY = fishPositionY;
    _fishSprite->setPosition(_fishPositionX, _fishPositionY);
}

void FishPlayer::SetFishScale(float fishScale)
{
    _fishScale = fishScale;
    _fishSprite->setScale(_fishScale);
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
}