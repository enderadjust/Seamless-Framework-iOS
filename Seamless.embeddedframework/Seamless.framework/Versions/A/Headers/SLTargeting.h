//
//  SLTargeting.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 26.05.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    SLTargetingTypeAppExists,
    SLTargetingTypeFreeStorageGreater,
    SLTargetingTypeFreeStoragePercentGreater,
    SLTargetingTypeBatteryPercentGreater,
    SLTargetingTypeOperator
}SLTargetingType;

@interface SLTargeting : NSObject

@property (nonatomic) SLTargetingType targetingType;
@property (nonatomic, strong) NSString * value;
@property (nonatomic, strong) NSString * type;

-(id)initWithDictionary:(NSDictionary*)dictionary;

@end
