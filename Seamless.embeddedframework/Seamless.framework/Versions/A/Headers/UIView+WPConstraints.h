//
//  UIView+Constraints.h
//  Woodo Project iOS
//
//  Created by Gokhan Baris Aker on 14/01/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (WPConstraints)

- (NSArray *) matchParentVisualFormats;
- (NSArray *) matchParentConstraints;
- (NSArray *) matchParentConstraintsWithMargin:(CGFloat) margin;
- (NSArray *) matchParentConstraintsWithTopMargin:(CGFloat) topMargin
                                       leftMargin:(CGFloat) leftMargin
                                      rightMargin:(CGFloat) rightMargin
                                     bottomMargin:(CGFloat) bottomMargin;

- (NSArray *) centerParentConstraints;

@end
