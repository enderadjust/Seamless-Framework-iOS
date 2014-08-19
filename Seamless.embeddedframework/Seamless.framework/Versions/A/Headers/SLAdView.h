//
//  SLAdView.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 5.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MPAdView.h"
#import "SLManager.h"
@class SLAdView;
@protocol SLAdViewDelegate
-(void)adViewDidLoad:(SLAdView*)adView;
-(void)adViewDidFailToLoad:(SLAdView*)adView;
@end
@interface SLAdView : UIView <MPAdViewDelegate>
@property (nonatomic, weak) id delegate;
- (instancetype)initWithEntity:(NSString *)entity
                      category:(SLCategory)category
                        adSize:(CGSize)adSize
            rootViewController:(UIViewController *)viewController;

-(void)loadAd;
@end
