#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "FishPlayer.h"
#include "Bubble.h"
#include "EvilFish.h"
#include <vector>
#include "C:\cocos2d-x-3.16\Fish\cocos2d\cocos\2d\CCNode.h"

class MainScene : public cocos2d::Scene
{
public:
    float imageXsize = 0;
    float imageYsize = 0;
    const int enemyNumber = 4;
    cocos2d::EventListenerTouchOneByOne* listener;
    cocos2d::Sprite* background;
    FishPlayer* fish;
    std::vector<EvilFish*> evilFishes = {new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png")};
    Bubble* bubble;

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

    void update(float) override;

    // my own functions
    bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event);
    void returnToMenu();
};

#endif // __MAIN_SCENE_H__
