//
//  AnalyticXAppController.h
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@end

