//
//  AppDelegate.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 08.09.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    
}

- (BOOL)applicationShouldHandleReopen:(NSApplication *)theApplication hasVisibleWindows:(BOOL)flag
{
    if (flag == NO){
        [self.window makeKeyAndOrderFront:self];
    }
    return YES;
}

@end
