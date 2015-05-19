//
//  SimulatorListViewController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 19.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "SimulatorListViewController.h"

#import "Simulator.h"

@interface SimulatorListViewController () <NSOutlineViewDataSource, NSOutlineViewDelegate>

@property (nonatomic, strong) NSArray *simulators;

@property (weak) IBOutlet NSOutlineView *outletView;

@end

@implementation SimulatorListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *userLibraryPath = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject];
    NSString *devicesPath = [userLibraryPath stringByAppendingPathComponent:@"Developer/CoreSimulator/Devices"];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSDirectoryEnumerator *enumerator = [fileManager enumeratorAtPath:devicesPath];
    
    NSMutableArray *simulators = [[NSMutableArray alloc] init];
    NSString *path;
    while (path = [enumerator nextObject]) {
        NSString *simulatorPath = [devicesPath stringByAppendingPathComponent:path];
        BOOL isDir;
        if ([fileManager fileExistsAtPath:simulatorPath isDirectory:&isDir] && isDir) {
            NSString *plistPath = [simulatorPath stringByAppendingPathComponent:@"device.plist"];
            if ([fileManager fileExistsAtPath:plistPath]) {
                Simulator *simulator = [[Simulator alloc] initWithDictionary:[NSDictionary dictionaryWithContentsOfFile:plistPath]];
                simulator.path = simulatorPath;
                [simulators addObject:simulator];
            }
        }
    }
    
    self.simulators = [simulators copy];
    
    self.outletView.floatsGroupRows = NO;
}

#pragma mark - Outline data source

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item {
    if (!item) {
        return 1;
    }
    
    return [self.simulators count];
}

- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item {
    if (!item) {
        return @"iOS 7";
    }
    
    return self.simulators[index];
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
    if ([item isKindOfClass:[NSString class]]) {
        return YES;
    }
    
    return NO;
}

- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)tableColumn item:(id)item {
    NSTableCellView *cell = nil;
    
    if ([item isKindOfClass:[NSString class]]) {
        cell = [outlineView makeViewWithIdentifier:@"HeaderCell" owner:self];
//        cell.textField.stringValue = item;
    } else {
        cell = [outlineView makeViewWithIdentifier:@"SimulatorCell" owner:self];
        Simulator *simulator = (Simulator *)item;
//        cell.textField.stringValue = [NSString stringWithFormat:@"%@ (%@)", simulator.name, simulator.runtime.bundleName];
    }
    
    return cell;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item {
    if ([item isKindOfClass:[NSString class]]) {
        return YES;
    }
    
    return NO;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectItem:(id)item {
    if ([item isKindOfClass:[NSString class]]) {
        return NO;
    }
    
    return YES;
}

- (CGFloat)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item {
    if ([item isKindOfClass:[NSString class]]) {
        return 17.0f;
    }
    
    return 34.0f;
}

@end
