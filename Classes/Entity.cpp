//
// Created by Usuario on 06/05/2019.
//

#include "Entity.h"

Entity::Entity(std::string textureName)
{
    _textureName = textureName;
    _entitySprite = cocos2d::Sprite::create(_textureName);
     addChild(_entitySprite);
    _anchor = cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM;
    _entityPositionX = 0;
    _entityPositionY = 0;
    _entityScale = _entitySprite->getScale() / 2;
    setPosition(_entityPositionX, _entityPositionY);
    setScale(_entityScale);
    _entitySprite->setTexture(_textureName);
    setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
}

Entity::Entity(std::string textureName, float entityPositionX, float entityPositionY,
               float entityScale, cocos2d::Vec2 anchor)
{
    _textureName = textureName;
    _entitySprite = cocos2d::Sprite::create(_textureName);
    addChild(_entitySprite);
    _anchor = anchor;
    _entityPositionX = entityPositionX;
    _entityPositionY = entityPositionY;
    _entityScale = entityScale;
    setPosition(_entityPositionX, _entityPositionY);
    setScale(_entityScale);
    _entitySprite->setTexture(_textureName);
    setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
}

void Entity::SetSprite(cocos2d::Sprite *entitySprite)
{
    _entitySprite = entitySprite;
    if (getChildren().size() == 0)
    {
        addChild(_entitySprite);
    }
}

void Entity::SetAnchor(cocos2d::Vec2 anchor)
{
    _anchor = anchor;
    setAnchorPoint(_anchor);
}

void Entity::SetTexture(std::string textureName)
{
    _textureName = textureName;
    _entitySprite->setTexture(_textureName);
}

void Entity::SetEntityPositionX(float entityPositionX)
{
    _entityPositionX = entityPositionX;
    setPosition(_entityPositionX, _entityPositionY);
}

void Entity::SetEntityPositionY(float entityPositionY)
{
    _entityPositionY = entityPositionY;
    setPosition(_entityPositionX, _entityPositionY);
}

void Entity::SetEntityScale(float entityScale)
{
    _entityScale = entityScale;
    setScale(_entityScale);
}

cocos2d::Sprite* Entity::GetSprite()
{
    return _entitySprite;
}

cocos2d::Vec2 Entity::GetAnchor()
{
    return _anchor;
}

std::string Entity::GetTexture()
{
    return _textureName;
}

bool Entity::ContainsTouch(cocos2d::Point location)
{
    return getBoundingBox().containsPoint(location);
}

float Entity::GetEntityPositionX()
{
    return _entityPositionX;
}

float Entity::GetEntityPositionY()
{
    return _entityPositionY;
}

float Entity::GetEntityScale()
{
    return _entityScale;
}