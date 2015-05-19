//
//  SimulatorsController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 16.09.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import "SimulatorsController.h"

#import "Simulator.h"
#import "Runtime.h"

@interface SimulatorsController ()

@property (strong) NSArray *simulators;
@property (strong) NSArray *runtimes;

@end

@implementation SimulatorsController

- (id)init
{
    self = [super init];
    if (self) {
       [self fillRuntimes];
       [self fillSimulators];
    }
    return self;
}

- (void)fillRuntimes
{
   NSString *runtimesPath = @"/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/Library/CoreSimulator/Profiles/Runtimes";
   
   NSFileManager *fileManager = [NSFileManager defaultManager];
   NSArray *runtimePathes = [fileManager contentsOfDirectoryAtPath:runtimesPath error:nil];
   
   NSMutableArray *runtimes = [[NSMutableArray alloc] init];
   
   for (NSString *subpath in runtimePathes) {
      NSString *runtimePath = [runtimesPath stringByAppendingPathComponent:subpath];
      
      NSBundle *bundle = [NSBundle bundleWithPath:runtimePath];
      NSDictionary *bundleInfo = [bundle infoDictionary];
      
      Runtime *runtime = [[Runtime alloc] init];
      runtime.bundleIdentifier = bundleInfo[@"CFBundleIdentifier"];
      runtime.bundleName = bundleInfo[@"CFBundleName"];
      
      [runtimes addObject:runtime];
   }
   
   _runtimes = runtimes;
}

- (void)fillSimulators
{
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
            Simulator *simulator = [[Simulator alloc] init];
            
            simulator.path = simulatorPath;
            
            NSDictionary *simulatorDict = [NSDictionary dictionaryWithContentsOfFile:plistPath];
            simulator.UDID = simulatorDict[@"UDID"];
            simulator.deviceType = simulatorDict[@"deviceType"];
            simulator.name = simulatorDict[@"name"];
            simulator.state = simulatorDict[@"state"];
            
            for (Runtime *runtime in self.runtimes) {
               if ([runtime.bundleIdentifier isEqualToString:simulatorDict[@"runtime"]]) {
                  simulator.runtime = runtime;
               }
            }
            
            [simulators addObject:simulator];
         }
      }
   }
   
   NSSortDescriptor *sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES];
   _simulators = [simulators sortedArrayUsingDescriptors:@[sortDescriptor]];
}

- (void)awakeFromNib
{
    [super awakeFromNib];
   
    [self.outineView setTarget:self];
    [self.outineView setDoubleAction:@selector(doubleClickAction:)];
   
    [self.outineView expandItem:nil expandChildren:YES];
}

#pragma mark - Actions

- (void)doubleClickAction:(id)sender
{
    NSInteger clickedRow = [self.outineView clickedRow];
    Simulator *selectedSimulator = self.simulators[clickedRow - 1];
        
    [[NSWorkspace sharedWorkspace] openFile:selectedSimulator.path];
}

#pragma mark - Outline View

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item
{
    if (!item) {
        return 1;
    }
    
    return [self.simulators count];
}

- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item
{
    if (!item) {
        return @"iOS 7";
    }
    
    return self.simulators[index];
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item
{
    if ([item isKindOfClass:[NSString class]]) {
        return YES;
    }
    
    return NO;
}

- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)tableColumn item:(id)item
{
    NSTableCellView *cell = nil;
    
    if ([item isKindOfClass:[NSString class]]) {
        cell = [outlineView makeViewWithIdentifier:@"HeaderCell" owner:self];
        cell.textField.stringValue = item;
    } else {
        cell = [outlineView makeViewWithIdentifier:@"DataCell" owner:self];
        Simulator *simulator = (Simulator *)item;
        cell.textField.stringValue = [NSString stringWithFormat:@"%@ (%@)", simulator.name, simulator.runtime.bundleName];
    }
    
    return cell;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item
{
    if ([item isKindOfClass:[NSString class]]) {
        return YES;
    }
    
    return NO;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectItem:(id)item{
    if ([item isKindOfClass:[NSString class]]) {
        return NO;
    }
    
    return YES;
}

- (CGFloat)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item
{
    if ([item isKindOfClass:[NSString class]]) {
        return 17.0f;
    }
    
    return 34.0f;
}

@end
