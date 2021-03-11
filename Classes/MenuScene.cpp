#include "MenuScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    background = cocos2d::Sprite::create("menuBackground.png");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    background->setScale(visibleSize.width, visibleSize.height);
    menuButton = cocos2d::Sprite::create("buttonRed.png");
    menuButton->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    menuButton->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    menuButton->setScale(20.0);
    // playText->enableGlow(Color4B::BLUE);
    this->addChild(background);
    this->addChild(menuButton);
    listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MenuScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MenuScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MenuScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    this->scheduleUpdate();
    return true;
}

void MenuScene::update(float delta)
{
}

bool MenuScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    startGame(touch);
    return true;
}

void MenuScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    startGame(touch);
}

void MenuScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

}

void MenuScene::startGame(cocos2d::Touch *touch)
{
    auto location = touch->getLocation();
    if (menuButton->getBoundingBox().containsPoint(location))
    {
        auto scene = MainScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
}

void MenuScene::menuCloseCallback(Ref* pSender)
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
