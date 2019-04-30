#include "HelloWorldScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include <string>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
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
    fish = Sprite::create("fish.png");
    bubble = Sprite::create("bubble.png");
    this->addChild(background);
    this->addChild(fish);
    this->addChild(bubble);
    for (int i=0;i<enemyNumber;i++)
    {
        this->addChild(evilFishes[i]);
    }
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    background->setScale(visibleSize.width, visibleSize.height);
    fish->setPosition((visibleSize.width / 2) + 5, (visibleSize.height / 2) + 20);
    fish->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    fish->setTexture("fish.png");
    fish->setScale(fish->getScale() / 2);
    bubble->setPosition(visibleSize.width * 2, visibleSize.height * 2);
    bubble->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
    for (int i=0;i<enemyNumber;i++)
    {
        evilFishes[i]->setAnchorPoint(Vec2(origin.ANCHOR_MIDDLE));
        evilFishes[i]->setScale(evilFishes[i]->getScale() / 2);
        evilFishes[i]->setPosition(200, 200);
    }
    locateEnemies();
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
    relocateSprite(bubble);
    for (int i = 0; i<enemyNumber;i++)
    {
        enemyKillPlayer(evilFishes[i]);
    }
    playerAnimation();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    playerDirectionX = touch->getLocationInView().x;
    playerDirectionY = touch->getLocationInView().y;
    rotateCharacter(playerDirectionX, playerDirectionY);
    shotBubble(touch);
    return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    playerDirectionX = touch->getLocationInView().x;
    playerDirectionY = touch->getLocationInView().y;
    rotateCharacter(playerDirectionX, playerDirectionY);
    shotBubble(touch);
}

void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

}

void HelloWorld::rotateCharacter(float directionX, float directionY)
{
    fish->stopAllActions();
    float locationX = directionX - fish->getPosition().x;
    float locationY = directionY - fish->getPosition().y;
    cocos2d::Vec2 vectorLocation = cocos2d::Vec2(locationX, locationY);
    playerRotation = vectorLocation.getAngle();
    auto rotateChar = RotateTo::create(1.0, CC_RADIANS_TO_DEGREES(playerRotation));
    fish->runAction(rotateChar);
    //fish->setRotation(CC_RADIANS_TO_DEGREES(playerRotation));
}

void HelloWorld::locateEnemies()
{
    cocos2d::Rect enemies;
    cocos2d::Rect player = fish->getBoundingBox();
    float initialPositionX = 0;
    float initialPositionY = 0;
    bool randomGot = false;
    for (int i=0;i<enemyNumber;i++)
    {
        enemies = evilFishes[i]->getBoundingBox();
        do {
            initialPositionX = cocos2d::RandomHelper::random_int(1, spawningEnemyDistance);
            initialPositionY = cocos2d::RandomHelper::random_int(1, spawningEnemyDistance);
            if (initialPositionX != fish->getPosition().x || initialPositionY != fish->getPosition().y)
            {
                if (initialPositionX != fish->getPosition().x)
                {
                    if (initialPositionX - fish->getPosition().x > 0)
                    {
                        if (initialPositionX - fish->getPosition().x > playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                    if (initialPositionX - fish->getPosition().x < 0)
                    {
                        if (initialPositionX - fish->getPosition().x < -playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                }
                if (initialPositionY != fish->getPosition().y)
                {
                    if (initialPositionY - fish->getPosition().y > 0)
                    {
                        if (initialPositionY - fish->getPosition().y > playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                    if (initialPositionY - fish->getPosition().y < 0)
                    {
                        if (initialPositionY - fish->getPosition().y < -playerLimitDistance)
                        {
                            randomGot = true;
                        }
                    }
                }
            }
            if (enemies.intersectsRect(player))
            {
                randomGot = false;
            }
        } while(!randomGot);
        evilFishes[i]->stopAllActions();
        evilFishes[i]->setPosition(initialPositionX, initialPositionY);
        enemyBehaviourBeginning(evilFishes[i]);
    }
}

void HelloWorld::relocateSprite(cocos2d::Sprite *shot)
{
    cocos2d::Rect bullet = shot->getBoundingBox();
    bool randomGot = false;
    float newPositionX = 0;
    float newPositionY = 0;
    for (int i=0;i<enemyNumber;i++)
    {
        cocos2d::Rect target = evilFishes[i]->getBoundingBox();
        if (target.intersectsRect(bullet))
        {
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
            evilFishes[i]->stopAllActions();
            evilFishes[i]->setPosition(newPositionX, newPositionY);
            enemyBehaviourBeginning(evilFishes[i]);
            bubble->setPosition(imageXsize * 2, imageYsize * 2);
            bubble->stopAllActions();
            bubbleShot = false;
        }
    }
}

void HelloWorld::shotBubble(cocos2d::Touch *touch)
{
    auto location = touch->getLocation();
    for (int i=0;i<enemyNumber;i++)
    {
        if (evilFishes[i]->getBoundingBox().containsPoint(location) && !bubbleShot)
        {
            auto action = cocos2d::MoveTo::create(0.5f, location);
            bubble->setPosition(fish->getPosition());
            bubble->runAction(action);
            bubbleShot = true;
        }
    }
}

void HelloWorld::enemyBehaviourBeginning(cocos2d::Sprite * theEnemy)
{
    auto action = cocos2d::MoveTo::create(5.0, fish->getPosition());
    theEnemy->runAction(action);
}

void HelloWorld::enemyKillPlayer(cocos2d::Sprite * theEnemy)
{
    cocos2d::Rect enemyBox = theEnemy->getBoundingBox();
    cocos2d::Rect playerBox = fish->getBoundingBox();
    if (enemyBox.intersectsRect(playerBox))
    {
        auto scene = MenuScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
}

void HelloWorld::playerAnimation()
{
    if (bubbleShot)
    {
        fish->setTexture("fishBubble.png");
    }
    else {
        fish->setTexture("fish.png");
    }
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
