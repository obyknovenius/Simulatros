//
//  Runtime.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 11.12.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Runtime : NSObject

- (instancetype)initWithBundle:(NSBundle *)bundle;

@property (copy) NSString *bundleIdentifier;
@property (copy) NSString *bundleName;

@end
