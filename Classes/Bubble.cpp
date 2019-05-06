//
// Created by Usuario on 06/05/2019.
//

#include "Bubble.h"

Bubble::Bubble(std::string textureName) : Entity(textureName)
{
}

Bubble::Bubble(std::string textureName, float entityPositionX, float entityPositionY,
               float entityScale, cocos2d::Vec2 anchor) : Entity(textureName, entityPositionX, entityPositionY, entityScale, anchor)
               {
               }

/*Bubble::Bubble(std::string textureName)
{
    _textureName = textureName;
    _bubbleSprite = cocos2d::Sprite::create(_textureName);
    addChild(_bubbleSprite);
    _anchor = cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM;
    _bubblePositionX = 0;
    _bubblePositionY = 0;
    _bubbleScale = 0;
    setPosition(_bubblePositionX, _bubblePositionY);
    setScale(_bubbleScale);
    _bubbleSprite->setTexture(_textureName);
    setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
}

Bubble::Bubble(std::string textureName, float bubblePositionX, float bubblePositionY,
        float bubbleScale, cocos2d::Vec2 anchor)
{
    _textureName = textureName;
    _bubbleSprite = cocos2d::Sprite::create(_textureName);
    addChild(_bubbleSprite);
    _anchor = anchor;
    _bubblePositionX = bubblePositionX;
    _bubblePositionY = bubblePositionY;
    _bubbleScale = bubbleScale;
    setPosition(_bubblePositionX, _bubblePositionY);
    setScale(_bubbleScale);
    _bubbleSprite->setTexture(_textureName);
    setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
}

void Bubble::SetSprite(cocos2d::Sprite *bubbleSprite)
{
    _bubbleSprite = bubbleSprite;
    if (getChildren().size() == 0)
    {
        addChild(_bubbleSprite);
    }
}

void Bubble::SetAnchor(cocos2d::Vec2 anchor)
{
    _anchor = anchor;
    setAnchorPoint(_anchor);
}

void Bubble::SetTexture(std::string textureName)
{
    _textureName = textureName;
    _bubbleSprite->setTexture(_textureName);
}

void Bubble::SetBubblePositionX(float bubblePositionX)
{
    _bubblePositionX = bubblePositionX;
    setPosition(_bubblePositionX, _bubblePositionY);
}

void Bubble::SetBubblePositionY(float bubblePositionY)
{
    _bubblePositionY = bubblePositionY;
    setPosition(_bubblePositionX, _bubblePositionY);
}

void Bubble::SetBubbleScale(float bubbleScale)
{
    _bubbleScale = bubbleScale;
    setScale(_bubbleScale);
}

cocos2d::Sprite* Bubble::GetSprite()
{
    return _bubbleSprite;
}

cocos2d::Vec2 Bubble::GetAnchor()
{
    return _anchor;
}

std::string Bubble::GetTexture()
{
    return _textureName;
}

float Bubble::GetBubblePositionX()
{
    return _bubblePositionX;
}

float Bubble::GetBubblePositionY()
{
    return _bubblePositionY;
}

float Bubble::GetBubbleScale()
{
    return _bubbleScale;
}*/