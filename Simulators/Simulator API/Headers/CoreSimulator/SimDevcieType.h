//
//  SimDevcieType.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 28.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

@interface SimDeviceType : NSObject

+ (void)supportedDevicesAddProfilesAtPath:(NSString *)path;
+ (id)supportedDeviceTypesByName;
+ (id)supportedDeviceTypesByAlias;
+ (id)supportedDeviceTypesByIdentifier;
+ (id)supportedDeviceTypes;
+ (id)supportedDevices;

- (instancetype)init;
- (instancetype)initWithBundle:(NSBundle *)bundle;
- (instancetype)initWithPath:(NSString *)path;

@property(retain) NSBundle *bundle;

@property(copy) NSString *name;
@property(copy) NSString *identifier;
@property(copy) NSString *modelIdentifier;

@property(copy) NSDictionary *supportedFeaturesConditionalOnRuntime;
@property(copy) NSDictionary *supportedFeatures;
@property(copy) NSDictionary *aliases;
@property(copy) NSDictionary *environment_extra;
@property(copy) NSString *productClass;
@property(copy) NSString *springBoardConfigName;
@property unsigned int maxCoreSimulatorFrameworkVersion;
@property unsigned int minCoreSimulatorFrameworkVersion;
@property unsigned int maxRuntimeVersion;
@property unsigned int minRuntimeVersion;
@property struct CGSize mainScreenDPI;
@property struct CGSize mainScreenSize;
@property(copy) NSDictionary *capabilities;
@property float mainScreenScale;
@property(copy) NSArray *supportedProductFamilyIDs;
@property(copy) NSArray *supportedArchs;


- (Class)deviceClass;
- (long long)compare:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (id)environmentForRuntime:(id)arg1;
- (id)environment;

@property(readonly, copy) NSString *productFamily;
@property(readonly) int productFamilyID;

@end
