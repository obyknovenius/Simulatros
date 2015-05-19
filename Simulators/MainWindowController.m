//
//  MainWindowController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 18.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "MainWindowController.h"

@interface MainWindowController ()

@end

@implementation MainWindowController

- (void)windowDidLoad {
    [super windowDidLoad];
    
    self.window.titleVisibility = NSWindowTitleHidden;
    self.window.titlebarAppearsTransparent = YES;
}

@end
