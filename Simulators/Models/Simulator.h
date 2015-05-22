//
//  Simulator.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 10.09.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Runtime;

@interface Simulator : NSObject

@property (strong) NSUUID *UDID;
@property (copy) NSString *deviceType;
@property (copy) NSString *name;
@property (strong) NSNumber *state;
@property (copy) NSString *path;
@property (copy) NSString *runtime;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
