//
//  Simulator.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 10.09.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import "Simulator.h"

@implementation Simulator

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    self = [super init];
    if (self) {
        self.UDID = [[NSUUID alloc] initWithUUIDString:dictionary[@"UDID"]];
        self.deviceType = dictionary[@"deviceType"];
        self.name = dictionary[@"name"];
        self.runtime = dictionary[@"runtime"];
        self.state = dictionary[@"state"];
    }
    return self;
}

@end
