//
//  AnalyticXStringUtilAndroid.cpp
//  AnalyticX
//
//  Created by diwwu on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticXStringUtilAndroid.h"
#define isKindOfClass(obj,class) (dynamic_cast<class*>(obj) != NULL)
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
        
    jStringCls = pEnv->FindClass("java/lang/String");
        
    jobjectArray result;
        
    result = pEnv->NewObjectArray( 2 * ccDictionary->allKeys()->count(), jStringCls, NULL);
        
    if (result == NULL) {
        cocos2d::CCLog("failed to create a new jobjectArray");
        return NULL;
    }
    
    for (int i = 0; i < ccDictionary->allKeys()->count(); i++) {
        
        cocos2d::CCObject* obj = ccDictionary->objectForKey(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString());
        cocos2d::CCString* value;
        if(isKindOfClass(obj, cocos2d::CCDictionary))
        {
            value = cocos2d::CCString::create("Dictionary");
        }
        else if(isKindOfClass(obj, cocos2d::CCArray))
        {
            value = cocos2d::CCString::create("Array");
        }
        else if (isKindOfClass(obj, cocos2d::CCString))
        {
            value = (cocos2d::CCString*)obj;
        }
        else if (isKindOfClass(obj, cocos2d::CCInteger))
        {
            value = cocos2d::CCString::createWithFormat("%d", ((cocos2d::CCInteger*)obj)->getValue());
        }
        else
        {
            value = cocos2d::CCString::create("Unknown Object");
        }
        
        jstring keyString = minfo.env->NewStringUTF(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString());
        
        jstring objectString = minfo.env->NewStringUTF(value->getCString());
        
        pEnv->SetObjectArrayElement(result, i * 2, keyString);
        
        pEnv->SetObjectArrayElement(result, i * 2 + 1, objectString);
        
    }
    
    return result;
}
