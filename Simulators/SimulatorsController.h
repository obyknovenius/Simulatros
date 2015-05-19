//
//  SimulatorsController.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 16.09.14.
//  Copyright (c) 2014 Vitaly Dyachkov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SimulatorsController : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate>

@property (weak) IBOutlet NSOutlineView *outineView;

@end
