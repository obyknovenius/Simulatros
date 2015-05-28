//
//  SimulatorListViewController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 19.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "SimulatorListViewController.h"

#import "SimulatorCell.h"

#import "SimDeviceSet.h"
#import "SimDevice.h"
#import "SimRuntime.h"

@interface SimulatorListViewController () <NSOutlineViewDataSource, NSOutlineViewDelegate>

@property (nonatomic, strong) NSArray *devices;

@property (weak) IBOutlet NSOutlineView *outletView;

@end

@implementation SimulatorListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    SimDeviceSet *deviceSet = [SimDeviceSet defaultSet];
    self.devices = [deviceSet devices];
    
    self.outletView.floatsGroupRows = NO;
    self.outletView.indentationPerLevel = 0.0f;
    [self.outletView expandItem:self.devices];
}

#pragma mark - Outline data source

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item {
    if (!item) {
        return 1;
    }
    
    return [self.devices count];
}

- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item {
    if (!item) {
        return self.devices;
    }
    
    return self.devices[index];
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
    if (item == self.devices) {
        return YES;
    }
    
    return NO;
}

- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)tableColumn item:(id)item {
    if (item == self.devices) {
        NSTableCellView *cell = [outlineView makeViewWithIdentifier:@"HeaderCell" owner:self];
        cell.textField.stringValue = @"SIMULATORS";
        return cell;
    } else {
        SimDevice *device = (SimDevice *)item;
        SimRuntime *runtime = device.runtime;
        
        SimulatorCell *cell = [outlineView makeViewWithIdentifier:@"SimulatorCell" owner:self];
        cell.nameTextField.stringValue = device.name;
        if (runtime) {
            cell.versionTextField.stringValue = [NSString stringWithFormat:@"%@ (%@)", runtime.versionString, runtime.buildVersionString];
        } else {
            cell.versionTextField.stringValue = @"No runtime";
        }
        return cell;
    }
    
    return nil;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item {
    if (item == self.devices) {
        return YES;
    }
    
    return NO;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldShowOutlineCellForItem:(id)item {
    return NO;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectItem:(id)item {
    if (item == self.devices) {
        return NO;
    }
    
    return YES;
}

- (CGFloat)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item {
    if (item == self.devices) {
        return 17.0f;
    }
    
    return 34.0f;
}

@end
