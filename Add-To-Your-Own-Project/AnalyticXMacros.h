//
//  AnalyticXMacros.h
//  AnalyticX
//
//  Created by haxpor on 11/22/14.
//
//

#ifndef AnalyticX_AnalyticXMacros_h
#define AnalyticX_AnalyticXMacros_h

#ifdef FLURRY
#define FLURRYLogEvent(text, ...) AnalyticX::flurryLogEvent(text, ##__VA_ARGS__)
#else
#define FLURRYLogEvent(text, ...) do {} while (0)
#endif

#endif
