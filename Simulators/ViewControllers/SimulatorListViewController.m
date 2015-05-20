//
//  SimulatorListViewController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 19.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "SimulatorListViewController.h"

#import "SimulatorCell.h"

#import "Simulator.h"

@interface SimulatorListViewController () <NSOutlineViewDataSource, NSOutlineViewDelegate>

@property (nonatomic, strong) NSArray *simulators;
@property (nonatomic, strong) NSDictionary *runtimes;

@property (weak) IBOutlet NSOutlineView *outletView;

@end

@implementation SimulatorListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    // Getting simulators
    NSString *userLibraryPath = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject];
    NSString *devicesPath = [userLibraryPath stringByAppendingPathComponent:@"Developer/CoreSimulator/Devices"];
    
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
    
//    // Getting runtimes
//    NSString *runtimesPath = @"/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/Library/CoreSimulator/Profiles/Runtimes";
//    
//    NSArray *runtimePathes = [fileManager contentsOfDirectoryAtPath:runtimesPath error:nil];
//    
//    NSMutableArray *runtimes = [[NSMutableArray alloc] init];
//    
//    for (NSString *subpath in runtimePathes) {
//        NSString *runtimePath = [runtimesPath stringByAppendingPathComponent:subpath];
//        
//        NSBundle *bundle = [NSBundle bundleWithPath:runtimePath];
//        NSDictionary *bundleInfo = [bundle infoDictionary];
//        
//        Runtime *runtime = [[Runtime alloc] init];
//        runtime.bundleIdentifier = bundleInfo[@"CFBundleIdentifier"];
//        runtime.bundleName = bundleInfo[@"CFBundleName"];
//        
//        [runtimes addObject:runtime];
//    }
//    
//    _runtimes = runtimes;
    
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
        return self.simulators;
    }
    
    return self.simulators[index];
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
    if (item == self.simulators) {
        return YES;
    }
    
    return NO;
}

- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)tableColumn item:(id)item {
    if (item == self.simulators) {
        NSTableCellView *cell = [outlineView makeViewWithIdentifier:@"HeaderCell" owner:self];
        cell.textField.stringValue = @"SIMULATORS";
        return cell;
    } else {
        SimulatorCell *cell = [outlineView makeViewWithIdentifier:@"SimulatorCell" owner:self];
        Simulator *simulator = (Simulator *)item;
        cell.nameTextField.stringValue = simulator.name;
//        cell.nameTextField.stringValue = [NSString stringWithFormat:@"%@ (%@)", simulator.name, simulator.runtime.bundleName];
        return cell;
    }
    
    return nil;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item {
    if (item == self.simulators) {
        return YES;
    }
    
    return NO;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectItem:(id)item {
    if (item == self.simulators) {
        return NO;
    }
    
    return YES;
}

- (CGFloat)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item {
    if (item == self.simulators) {
        return 17.0f;
    }
    
    return 34.0f;
}

@end
