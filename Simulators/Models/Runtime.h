//
//  Runtime.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 11.12.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Runtime : NSObject

+ (NSArray *)supportedRuntimes;

- (instancetype)initWithBundle:(NSBundle *)bundle;
- (instancetype)initWithPath:(NSString *)path;

@property (readonly) NSBundle *bundle;
@property (readonly) NSString *identifier;

@property (readonly) NSString *version;
@property (readonly) NSString *buildVersion;

@end
