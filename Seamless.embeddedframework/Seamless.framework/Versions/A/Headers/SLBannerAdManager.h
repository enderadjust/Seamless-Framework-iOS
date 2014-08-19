//
//  SLBannerAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 4.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SLBaseAdManager.h"
#import "MPAdView.h"

#define SLAdSizeMMA             CGSizeMake(320, 50)
#define SLAdSizeMRect           CGSizeMake(300, 250)
#define SLAdSizeLeaderboard     CGSizeMake(728, 90)

@interface SLBannerAdManager : SLBaseAdManager

-(id)initWithDelegate:(id)delegate;

-(void)getAdWithEntity:(NSString*)entity
                  size:(CGSize)size
          successBlock:(void(^)(MPAdView * adView))successBlock
          failureBlock:(void(^)(NSError * error))failureBlock;
@end
