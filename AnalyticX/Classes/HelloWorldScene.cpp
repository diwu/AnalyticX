#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AnalyticX.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::node();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::node();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::itemWithNormalImage(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    AnalyticX::flurrySetAppVersion("v_1_97");
    cocos2d::CCLog("--->>>get flurry version = %s", AnalyticX::flurryGetFlurryAgentVersion());
    AnalyticX::flurrySetDebugLogEnabled(false);
    AnalyticX::flurrySetSessionContinueSeconds(143);
    AnalyticX::flurrySetSecureTransportEnabled(false);

    AnalyticX::flurrySetUserID("fake_user_id");
    AnalyticX::flurrySetAge(34);
    AnalyticX::flurrySetGender("f");
    AnalyticX::flurrySetReportLocation(false);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    AnalyticX::flurryStartSession("QFNXVFK2XX4P56GS76EA");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AnalyticX::flurryStartSession("W7IBK43RJCHPT4IRP4HI");
#endif
    
    AnalyticX::flurryLogEvent(" #2 log event test...");
    AnalyticX::flurryLogEventTimed(" log event timed test...", false);

    CCDictionary *testDict = new CCDictionary();

    CCString *testCCString;

    testCCString = CCString::stringWithCString("obj 0");

    testDict->setObject(testCCString, "key 0");

    testCCString = CCString::stringWithCString("obj 1");

    testDict->setObject(testCCString, "key 1");

    AnalyticX::flurryLogEventWithParameters(" - test flurryLogEventWithParameters", testDict);

    AnalyticX::flurryLogEventWithParametersTimed("test flurryLogEventWithParameters + timed", testDict, true);
    AnalyticX::flurryEndTimedEventWithParameters("test end event...", NULL);
    
    AnalyticX::flurryLogPageView();
    
    //AnalyticX::flurryEndSession();
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
