//
//  SLMopubKeywordGenerator.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 26.05.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIApplication;
@class UIDevice;

@interface SLMopubKeywordGenerator : NSObject

+(NSString*)generateKeyword:(NSArray*)targetings;
+(NSString*)generateKeywordWithTargetings:(NSArray*)targetings
                              application:(UIApplication *) application
                                   device:(UIDevice *) device;

@end
