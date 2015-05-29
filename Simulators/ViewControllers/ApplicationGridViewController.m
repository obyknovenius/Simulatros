//
//  ApplicationGridViewController.m
//  Simulators
//
//  Created by Vitaly Dyachkov on 29.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#import "ApplicationGridViewController.h"

@interface ApplicationGridViewController ()

@property (weak) IBOutlet NSVisualEffectView *visualEffectView;
@property (weak) IBOutlet NSCollectionView *collectionView;

@end

@implementation ApplicationGridViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.visualEffectView.wantsLayer = YES;
    
    NSCollectionViewItem *collectionViewItem = [[NSStoryboard storyboardWithName:@"Main" bundle:nil] instantiateControllerWithIdentifier:@"CollectionViewItemID"];
    [self.collectionView setItemPrototype:collectionViewItem];
    
    self.collectionView.maxNumberOfColumns = 100;
    self.collectionView.maxNumberOfRows = 200;
    
    self.collectionView.minItemSize = CGSizeMake(218, 100);

    NSArray *array = @[@"wadwa", @"wadwa", @"wadwa", @"wadwa", @"wadwa"];
    self.collectionView.content = array;

}

@end
