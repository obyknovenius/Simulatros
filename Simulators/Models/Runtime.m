//
//  Runtime.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 11.12.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import "Runtime.h"

@interface Runtime ()

@property (strong) NSBundle *bundle;
@property (strong) NSString *identifier;

@property (strong) NSString *version;
@property (strong) NSString *buildVersion;

@end

@implementation Runtime

+ (NSArray *)supportedRuntimes {
    NSMutableArray *runtimes = [[NSMutableArray alloc] init];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSArray *searhPathes = [self runtimeSearchPathes];
    for (NSString *searchPath in searhPathes) {
        NSArray *contentPathes = [fileManager contentsOfDirectoryAtPath:searchPath error:nil];
        NSArray *runtimesPathes = [contentPathes filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"self ENDSWITH '.simruntime'"]];
        
        for (NSString *runtimePath in runtimesPathes) {
            Runtime *runtime = [[Runtime alloc] initWithPath:[searchPath stringByAppendingPathComponent:runtimePath]];
            [runtimes addObject:runtime];
        }
    }
    
    return [runtimes copy];
}

+ (NSArray *)runtimeSearchPathes {
    return @[@"/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/Library/CoreSimulator/Profiles/Runtimes",
             @"/Library/Developer/CoreSimulator/Profiles/Runtimes"];
}

- (instancetype)initWithBundle:(NSBundle *)bundle {
    self = [super init];
    if (self) {
        self.bundle = bundle;
        self.identifier = [bundle bundleIdentifier];
        
        NSString *systemVersionPath = [bundle pathForResource:@"SystemVersion" ofType:@"plist" inDirectory:@"RuntimeRoot/System/Library/CoreServices"];
        NSDictionary *systemVersion = [[NSDictionary alloc] initWithContentsOfFile:systemVersionPath];
        
        self.version = systemVersion[@"ProductVersion"];
        self.buildVersion = systemVersion[@"ProductBuildVersion"];
    }
    return self;
}

- (instancetype)initWithPath:(NSString *)path {
    NSBundle *bundle = [[NSBundle alloc] initWithPath:path];
    if (bundle) {
        return [self initWithBundle:bundle];
    }
    return nil;
}

@end
