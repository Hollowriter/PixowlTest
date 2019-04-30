#ifndef PROJ_ANDROID_STUDIO_FISHPLAYER_H
#define PROJ_ANDROID_STUDIO_FISHPLAYER_H

#include "cocos2d.h"
#include<string>

class FishPlayer {
    cocos2d::Sprite* _fishSprite;
    cocos2d::Vec2 _anchor;
    std::string _textureName;
    float _fishPositionX;
    float _fishPositionY;
    float _fishScale;
    FishPlayer(std::string textureName);
    FishPlayer(std::string textureName, cocos2d::Vec2 anchor, float fishPositionX, float fishPositionY, float fishScale);
    void SetSprite(cocos2d::Sprite* fishSprite);
    void SetAnchor(cocos2d::Vec2 anchor);
    void SetTexture(std::string textureName);
    void SetFishPositionX(float fishPositionX);
    void SetFishPositionY(float fishPositionY);
    void SetFishScale(float fishScale);
    cocos2d::Sprite* GetSprite();
    cocos2d::Vec2 GetAnchor();
    std::string GetTexture();
    float GetFishPositionX();
    float GetFishPositionY();
    float GetFishScale();
};


#endif
