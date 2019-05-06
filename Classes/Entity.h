//
// Created by Usuario on 06/05/2019.
//

#ifndef PROJ_ANDROID_STUDIO_ENTITY_H
#define PROJ_ANDROID_STUDIO_ENTITY_H

#include "cocos2d.h"
#include "C:\cocos2d-x-3.16\Fish\cocos2d\cocos\2d\CCNode.h"
#include<string>

class Entity : public cocos2d::Node{
private:
    cocos2d::Sprite* _entitySprite;
    cocos2d::Vec2 _anchor;
    std::string _textureName;
    float _entityPositionX;
    float _entityPositionY;
    float _entityScale;
public:
    Entity(std::string textureName);
    Entity(std::string textureName, float entityPositionX, float entityPositionY, float entityScale, cocos2d::Vec2 anchor);
    void SetSprite(cocos2d::Sprite* entitySprite);
    void SetAnchor(cocos2d::Vec2 anchor);
    void SetTexture(std::string textureName);
    void SetEntityPositionX(float entityPositionX);
    void SetEntityPositionY(float entityPositionY);
    void SetEntityScale(float entityScale);
    cocos2d::Sprite* GetSprite();
    cocos2d::Vec2 GetAnchor();
    std::string GetTexture();
    float GetEntityPositionX();
    float GetEntityPositionY();
    float GetEntityScale();
};


#endif //PROJ_ANDROID_STUDIO_ENTITY_H
