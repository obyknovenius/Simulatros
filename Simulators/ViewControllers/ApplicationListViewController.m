//
//  ApplicationListViewController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 29.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "ApplicationListViewController.h"

@interface ApplicationListViewController () <NSTableViewDataSource, NSTableViewDelegate>

@end

@implementation ApplicationListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

#pragma mark - Table view data source

- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView {
    return 10;
}

#pragma mark - Table view delegate

- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    NSTableCellView *cell = [tableView makeViewWithIdentifier:@"ApplicationInfoCell" owner:self];
    return cell;
}

- (CGFloat)tableView:(NSTableView *)tableView heightOfRow:(NSInteger)row {
    return 68.0f;
}

@end
