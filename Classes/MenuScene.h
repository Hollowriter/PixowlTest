#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    cocos2d::Sprite* background;
    cocos2d::Sprite* menuButton;
	cocos2d::EventListenerTouchOneByOne* listener;
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

    void update(float) override;

    // my own functions
    bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event);
    void startGame(cocos2d::Touch * touch);
};

#endif // __MENU_SCENE_H__
