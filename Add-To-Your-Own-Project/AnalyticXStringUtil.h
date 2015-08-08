//
//  AnalyticXStringUtil.h
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnalyticX_AnalyticXStringUtil_h
#define AnalyticX_AnalyticXStringUtil_h

#include "cocos2d.h"

@interface AnalyticXStringUtil:NSObject 

+ (NSString *)nsstringFromCString:(const char *)cstring;
+ (const char *)cstringFromNSString:(NSString *)nsstring;
+ (NSDictionary *)nsDictionaryFromCCDictionary:(cocos2d::CCDictionary *)ccDictionary;

@end

#endif
