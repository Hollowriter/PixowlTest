#include "HelloWorldScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include <string>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    imageXsize = visibleSize.width;
    imageYsize = visibleSize.height;
    background = Sprite::create("background.png");
    fish = new FishPlayer("fish.png");
    bubble = new Bubble("bubble.png");
    this->addChild(background);
    this->addChild(fish);
    for (int i=0;i<enemyNumber;i++)
    {
        this->addChild(evilFishes[i]);
    }
    this->addChild(bubble);
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    background->setScale(visibleSize.width, visibleSize.height);
    fish->SetEntityPositionX((visibleSize.width / 2) + 5);
    fish->SetEntityPositionY((visibleSize.height / 2) + 20);
    fish->SetAnchor(Vec2(origin.ANCHOR_MIDDLE));
    // fish->SetEntityScale(fish->GetSprite()->getScale() / 2);
    bubble->SetEntityPositionX(visibleSize.width * 2);
    bubble->SetEntityPositionY(visibleSize.height * 2);
    bubble->SetAnchor(Vec2(origin.ANCHOR_MIDDLE));
    //bubble->SetEntityScale(bubble->GetSprite()->getScale());
    // evilFishes.resize(enemyNumber);
    for (int i=0;i<enemyNumber;i++)
    {
        evilFishes[i]->SetEntityPositionX(200);
        evilFishes[i]->SetEntityPositionY(200);
        evilFishes[i]->SetAnchor(Vec2(origin.ANCHOR_MIDDLE));
        locateEnemy(evilFishes[i]);
        //evilFishes[i]->SetEntityScale(evilFishes[i]->GetSprite()->getScale() / 2);
    }
    listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
    for (int i = 0; i<enemyNumber;i++)
    {
        if (bubble->IntersectsEnemy(evilFishes[i], imageXsize * 2, imageYsize * 2))
        {
            locateEnemy(evilFishes[i]);
        }
        if (evilFishes[i]->IntersectsPlayer(fish))
        {
            returnToMenu();
        }
    }
    fish->PlayerAnimation(bubble->GetIsTraveling());
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    fish->RotateFish(touch->getLocationInView().x, touch->getLocationInView().y);
    for (int i = 0; i<enemyNumber;i++)
    {
        fish->Shoot(touch, evilFishes[i], bubble);
    }
    return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    fish->RotateFish(touch->getLocationInView().x, touch->getLocationInView().y);
    for (int i = 0; i<enemyNumber;i++)
    {
        fish->Shoot(touch, evilFishes[i], bubble);
    }
}

void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

}

void HelloWorld::locateEnemy(EvilFish *entity)
{
    bool randomGot = false;
    float newPositionX = 0;
    float newPositionY = 0;
    do {
        newPositionX = cocos2d::RandomHelper::random_int(1, spawningEnemyDistance);
        newPositionY = cocos2d::RandomHelper::random_int(1, spawningEnemyDistance);
        if (newPositionX != fish->getPosition().x || newPositionY != fish->getPosition().y)
        {
            if (newPositionX != fish->getPosition().x)
            {
                if (newPositionX - fish->getPosition().x > 0)
                {
                    if (newPositionX - fish->getPosition().x > playerLimitDistance)
                    {
                        randomGot = true;
                    }
                }
                if (newPositionX - fish->getPosition().x < 0)
                {
                    if (newPositionX - fish->getPosition().x < -playerLimitDistance)
                    {
                        randomGot = true;
                    }
                }
            }
            if (newPositionY != fish->getPosition().y)
            {
                if (newPositionY - fish->getPosition().y > 0)
                {
                    if (newPositionY - fish->getPosition().y > playerLimitDistance)
                    {
                        randomGot = true;
                    }
                }
                if (newPositionY - fish->getPosition().y < 0)
                {
                    if (newPositionY - fish->getPosition().y < -playerLimitDistance)
                    {
                        randomGot = true;
                    }
                }
            }
        }
    } while(!randomGot);
    entity->stopAllActions();
    entity->setPosition(newPositionX, newPositionY);
    entity->MovingTowardsPlayer(fish);
}

void HelloWorld::returnToMenu()
{
    auto scene = MenuScene::createScene();
    Director::getInstance()->pushScene(scene);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
