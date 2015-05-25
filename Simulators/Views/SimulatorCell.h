//
//  SimulatorCell.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 20.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface SimulatorCell : NSTableCellView

@property (weak) IBOutlet NSTextField *nameTextField;
@property (weak) IBOutlet NSTextField *versionTextField;

@end
