#ifndef PROJ_ANDROID_STUDIO_FISHPLAYER_H
#define PROJ_ANDROID_STUDIO_FISHPLAYER_H

#include "cocos2d.h"
#include "Entity.h"

class FishPlayer : public Entity {
/*private:
    cocos2d::Sprite* _fishSprite;
    cocos2d::Vec2 _anchor;
    std::string _textureName;
    float _fishPositionX;
    float _fishPositionY;
    float _fishScale;*/
public:
    FishPlayer(std::string textureName);
    FishPlayer(std::string textureName, float fishPositionX, float fishPositionY, float fishScale, cocos2d::Vec2 anchor);
    /*void SetSprite(cocos2d::Sprite* fishSprite);
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
    float GetFishScale();*/
    void RotateFish(float fishRotationX, float fishRotationY);
};


#endif
