//
//  AnalyticXStringUtilAndroid.cpp
//  AnalyticX
//
//  Created by diwwu on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticXStringUtilAndroid.h"

jobjectArray AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(cocos2d::JniMethodInfo minfo, cocos2d::CCDictionary * ccDictionary) {
    
    if (ccDictionary == NULL) {
        return NULL;
    } else if (ccDictionary->allKeys() == NULL) {
        return NULL;
    } else if (ccDictionary->allKeys()->count() <= 0) {
        return NULL;
    }
            
    JNIEnv *pEnv = minfo.env;
    jclass jStringCls = 0;
        
    jStringCls = pEnv->FindClass("[Ljava/lang/String;");
        
    jobjectArray result;
        
    result = pEnv->NewObjectArray( 2 * ccDictionary->allKeys()->count(), jStringCls, NULL);
        
    if (result == NULL) {
        cocos2d::CCLog("failed to create a new jobjectArray");
        return NULL;
    }
    
    for (int i = 0; i < ccDictionary->allKeys()->count(); i++) {

        jstring keyString = minfo.env->NewStringUTF(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString());

        jstring objectString = minfo.env->NewStringUTF(((cocos2d::CCString *)ccDictionary->objectForKey(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString()))->getCString());

        pEnv->SetObjectArrayElement(result, i * 2, keyString);

        pEnv->SetObjectArrayElement(result, i * 2 + 1, objectString);

    }
    
    return result;
}
