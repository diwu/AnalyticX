//
//  AnalyticXStringUtil.cpp
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AnalyticXStringUtil.h"
#include "cocos2d.h"

@implementation AnalyticXStringUtil

#define isKindOfClass(obj,class) (dynamic_cast<class*>(obj) != NULL)

+ (NSString *)nsstringFromCString:(const char *)cstring {
    if (cstring == NULL) {
        return NULL;
    }
    
    NSString * nsstring = [[NSString alloc] initWithBytes:cstring length:strlen(cstring) encoding:NSUTF8StringEncoding];
    return [nsstring autorelease];
}
+ (const char *)cstringFromNSString:(NSString *)nsstring {
    
    if (nsstring == NULL) {
        return NULL;
    }
    
    return [nsstring UTF8String];
}
+ (NSDictionary *)nsDictionaryFromCCDictionary:(cocos2d::CCDictionary *)ccDictionary {
    if (ccDictionary == NULL) {
        return NULL;
    } else if (ccDictionary->allKeys() == NULL) {
        return NULL;
    } else if (ccDictionary->allKeys()->count() <= 0) {
        return NULL;
    }
    
    cocos2d::CCLog("1");
    
    NSMutableDictionary *nsDict = [NSMutableDictionary dictionaryWithCapacity:ccDictionary->allKeys()->count()];
    
    cocos2d::CCLog("2");

    for (int i = 0; i < ccDictionary->allKeys()->count(); i++) {
        cocos2d::CCLog("3");
        
        cocos2d::CCObject* obj = ccDictionary->objectForKey(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString());
        NSObject* nsObject;
        if(isKindOfClass(obj, cocos2d::CCDictionary))
        {
            nsObject = @"Dictionary";
        }
        else if(isKindOfClass(obj, cocos2d::CCArray))
        {
            nsObject = @"Array";
        }
        else if (isKindOfClass(obj, cocos2d::CCString))
        {
            const char* cstring = ((cocos2d::CCString*)obj)->getCString();
            nsObject = [[[NSString alloc] initWithBytes:cstring length:strlen(cstring) encoding:NSUTF8StringEncoding] autorelease];
        }
        else if (isKindOfClass(obj, cocos2d::CCInteger))
        {
            nsObject = [NSString stringWithFormat:@"%d", ((cocos2d::CCInteger*)obj)->getValue()];
        }
        else
        {
            nsObject = @"Unknown Object";
        }
        [nsDict setValue:nsObject forKey:[AnalyticXStringUtil nsstringFromCString:((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString()]];
    }
    
    return nsDict;
}


@end