#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "FishPlayer.h"
#include "Bubble.h"
#include "EvilFish.h"
#include <vector>
#include "C:\cocos2d-x-3.16\Fish\cocos2d\cocos\2d\CCNode.h"

class HelloWorld : public cocos2d::Scene
{
public:
    bool bubbleShot = false;
    float imageXsize = 0;
    float imageYsize = 0;
    const float playerLimitDistance = 200;
    const int spawningEnemyDistance = 600;
    const int enemyNumber = 4;
    cocos2d::EventListenerTouchOneByOne* listener;
    cocos2d::Sprite* background;
    // cocos2d::Sprite* fish;
    FishPlayer* fish;
    // Hacer que el enemigo se mueva hacia el player y lo devuelva al menu
    // EvilFish* evilFishes[] = {new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png")};
    std::vector<EvilFish*> evilFishes = {new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png"), new EvilFish("badFish.png")};
    // cocos2d::Sprite* evilFish;
    Bubble* bubble;

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void update(float) override;

    // my own functions
    bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event);
    void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event);
    // void rotateCharacter(float directionX, float directionY); // Part of player
    void locateEnemies();
    void relocateSprite(Entity * shot); // Modify this function to collide with the bubble
    void shotBubble(cocos2d::Touch * touch);
    void enemyBehaviourBeginning(EvilFish * theEnemy);
    void enemyKillPlayer(EvilFish * theEnemy);
    // void playerAnimation(); // Part of player
    // void setEnemySprites(); // Para setear varios enemigos
};

#endif // __HELLOWORLD_SCENE_H__
