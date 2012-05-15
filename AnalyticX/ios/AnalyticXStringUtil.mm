//
//  AnalyticXStringUtil.cpp
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AnalyticXStringUtil.h"

@implementation AnalyticXStringUtil

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

        [nsDict setValue:[AnalyticXStringUtil nsstringFromCString:((cocos2d::CCString *)ccDictionary->objectForKey(((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString()))->getCString()] forKey:[AnalyticXStringUtil nsstringFromCString:((cocos2d::CCString *)ccDictionary->allKeys()->objectAtIndex(i))->getCString()]];
    }
    
    return nsDict;
}


@end