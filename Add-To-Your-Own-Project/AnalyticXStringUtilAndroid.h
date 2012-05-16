//
//  AnalyticXStringUtilAndroid.h
//  AnalyticX
//
//  Created by diwwu on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnalyticX_AnalyticXStringUtilAndroid_h
#define AnalyticX_AnalyticXStringUtilAndroid_h

#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

class AnalyticXStringUtilAndroid {
    
public:
    static jobjectArray jobjectArrayFromCCDictionary(cocos2d::JniMethodInfo minfo, cocos2d::CCDictionary * ccDictionary);
};

#endif
