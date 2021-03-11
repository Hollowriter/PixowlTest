#include "MainScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include <string>

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainScene::init()
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
    bubble->SetEntityPositionX(visibleSize.width * 2);
    bubble->SetEntityPositionY(visibleSize.height * 2);
    bubble->SetAnchor(Vec2(origin.ANCHOR_MIDDLE));
    for (int i=0;i<enemyNumber;i++)
    {
        evilFishes[i]->SetEntityPositionX(200);
        evilFishes[i]->SetEntityPositionY(200);
        evilFishes[i]->SetAnchor(Vec2(origin.ANCHOR_MIDDLE));
        evilFishes[i]->Relocate(fish, fish->GetPlayerLimitDistance());
    }
    listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    for (int i = 0; i<enemyNumber;i++)
    {
        if (bubble->IntersectsEnemy(evilFishes[i], imageXsize * 2, imageYsize * 2))
        {
            evilFishes[i]->Relocate(fish, fish->GetPlayerLimitDistance());
        }
        if (evilFishes[i]->IntersectsPlayer(fish))
        {
            returnToMenu();
        }
    }
    fish->PlayerAnimation(bubble->GetIsTraveling());
}

bool MainScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    fish->RotateFish(touch->getLocationInView().x, touch->getLocationInView().y);
    for (int i = 0; i<enemyNumber;i++)
    {
        fish->Shoot(touch, evilFishes[i], bubble);
    }
    return true;
}

void MainScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    fish->RotateFish(touch->getLocationInView().x, touch->getLocationInView().y);
    for (int i = 0; i<enemyNumber;i++)
    {
        fish->Shoot(touch, evilFishes[i], bubble);
    }
}

void MainScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

}

void MainScene::returnToMenu()
{
    auto scene = MenuScene::createScene();
    Director::getInstance()->pushScene(scene);
}

void MainScene::menuCloseCallback(Ref* pSender)
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
