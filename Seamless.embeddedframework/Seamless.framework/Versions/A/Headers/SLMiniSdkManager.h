//
//  WPMiniSdkManager.h
//  Woodo Project iOS
//
//  Created by Gokhan Baris Aker on 17/02/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SLMiniSdkManager : NSObject

+ (int)getBatteryStatus;
+ (NSString *)getDeviceName;
+ (long)getFreeDiskspace;
+ (long)getTotalDiskspace;
+ (NSString *)getAdvertorialIdentifier;
+ (void)openTorchlight;
+ (void)closeTorchlight;
+ (void)vibrate;

@end
