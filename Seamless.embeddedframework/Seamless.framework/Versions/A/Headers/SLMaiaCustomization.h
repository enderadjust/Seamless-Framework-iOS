//
//  SLMaiaCustomization.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 12.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SLMaiaCustomization : NSObject
@property (nonatomic, strong) UIFont * titleFont;
@property (nonatomic, strong) UIFont * descriptionFont;
@property (nonatomic, strong) UIFont * sponsorTextFont;
@property (nonatomic, strong) UIFont * ctaButtonFont;
@property (nonatomic, strong) UIFont * downloadTextFont;
@property (nonatomic, strong) UIColor * backgroundColor;
@property (nonatomic, strong) UIColor * maiaTextColor;
@property (nonatomic, strong) UIFont * maiaTextFont;
@property (nonatomic) UIEdgeInsets maiaContentInset;
@end
