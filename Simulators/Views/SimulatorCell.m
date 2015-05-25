//
//  SimulatorCell.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 20.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "SimulatorCell.h"

@implementation SimulatorCell

- (void)setBackgroundStyle:(NSBackgroundStyle)backgroundStyle {
    [super setBackgroundStyle:backgroundStyle];
    
    NSTableRowView *row = (NSTableRowView*)self.superview;
    if (row.isSelected) {
        self.versionTextField.textColor = [NSColor whiteColor];
    } else {
        self.versionTextField.textColor = [NSColor secondaryLabelColor];
    }
}

@end
