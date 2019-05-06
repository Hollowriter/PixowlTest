//
// Created by Usuario on 06/05/2019.
//

#ifndef PROJ_ANDROID_STUDIO_BUBBLE_H
#define PROJ_ANDROID_STUDIO_BUBBLE_H

#include "cocos2d.h"
#include "Entity.h"

class Bubble : public Entity{
public:
    Bubble(std::string textureName);
    Bubble(std::string textureName, float entityPositionX, float entityPositionY, float entityScale, cocos2d::Vec2 anchor);
/*private:
    cocos2d::Sprite* _bubbleSprite;
    cocos2d::Vec2 _anchor;
    std::string _textureName;
    float _bubblePositionX;
    float _bubblePositionY;
    float _bubbleScale;
public:
    Bubble(std::string textureName);
    Bubble(std::string textureName, float bubblePositionX, float bubblePositionY, float bubbleScale, cocos2d::Vec2 anchor);
    void SetSprite(cocos2d::Sprite* bubbleSprite);
    void SetAnchor(cocos2d::Vec2 anchor);
    void SetTexture(std::string textureName);
    void SetBubblePositionX(float bubblePositionX);
    void SetBubblePositionY(float bubblePositionY);
    void SetBubbleScale(float bubbleScale);
    cocos2d::Sprite* GetSprite();
    cocos2d::Vec2 GetAnchor();
    std::string GetTexture();
    float GetBubblePositionX();
    float GetBubblePositionY();
    float GetBubbleScale();*/
};


#endif //PROJ_ANDROID_STUDIO_BUBBLE_H
