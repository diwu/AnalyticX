//
//  AnalyticXStringUtilAndroid.cpp
//  AnalyticX
//
//  Created by diwwu on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticXStringUtilAndroid.h"

#define isKindOfClass(obj,class) (dynamic_cast<class*>(obj) != NULL)
jobjectArray AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(cocos2d::JniMethodInfo minfo, cocos2d::__Dictionary * ccDictionary) {
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
    result = pEnv->NewObjectArray(2 * ccDictionary->allKeys()->count(), jStringCls, NULL);

    if (result == NULL) {
        cocos2d::log("failed to create a new jobjectArray");
        return NULL;
    }

    for (int i = 0; i < ccDictionary->allKeys()->count(); i++) {
        cocos2d::Ref* obj = ccDictionary->objectForKey(((cocos2d::__String *)ccDictionary->allKeys()->getObjectAtIndex(i))->getCString());
        cocos2d::__String* value;
        if(isKindOfClass(obj, cocos2d::__Dictionary))
        {
            value = cocos2d::__String::create("Dictionary");
        }
        else if(isKindOfClass(obj, cocos2d::__Array))
        {
            value = cocos2d::__String::create("Array");
        }
        else if (isKindOfClass(obj, cocos2d::__String))
        {
            value = (cocos2d::__String*) obj;
        }
        else if (isKindOfClass(obj, cocos2d::__Integer))
        {
            value = cocos2d::__String::createWithFormat("%d", ((cocos2d::__Integer*)obj)->getValue());
        }
        else
        {
            value = cocos2d::__String::create("Unknown Object");
        }

        jstring keyString = minfo.env->NewStringUTF(((cocos2d::__String *)ccDictionary->allKeys()->getObjectAtIndex(i))->getCString());
        jstring objectString = minfo.env->NewStringUTF(value->getCString());
        pEnv->SetObjectArrayElement(result, i * 2, keyString);
        pEnv->SetObjectArrayElement(result, i * 2 + 1, objectString);
    }

    return result;
}
