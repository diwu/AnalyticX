#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

// Uncomment the following line to define FLURRY, or define it as per project-based (see Build Setting->Apple LLVM 6.0 - Preprocessing in XCode)
//#define FLURRY
#ifdef FLURRY
#include "AnalyticX.h"
#endif

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    virtual void menuCloseCallback(CCObject* pSender);
    
    // add action to begin crashing the app
    void beginProcessToCrashApp(CCObject* pSender);
    // actually crash the app
    void makeItCrash();

    // implement the "static node()" method manually
    LAYER_NODE_FUNC(HelloWorld);

private:
    void printFlurryEventStatus(const char* name, AXFlurryEventRecordStatus status);
};

#endif // __HELLOWORLD_SCENE_H__
