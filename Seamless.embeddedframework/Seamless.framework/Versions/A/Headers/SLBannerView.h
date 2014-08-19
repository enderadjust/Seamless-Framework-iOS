//
//  SLBannerView.h
//  Seamless
//
//  Created by Gokhan Aker on 11/08/14.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SLBanner;
@class SLViewImpressionObserver;

@interface SLBannerView : UIView

/**
 * Loads given banner advertisement.
 * Method should run on UI thread.
 */
- (void) loadBanner:(SLBanner *) banner withImpressionObserver:(SLViewImpressionObserver *) observer;

@end
