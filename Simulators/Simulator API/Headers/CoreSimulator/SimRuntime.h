//
//  SimRuntime.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 27.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

typedef void (^CDUnknownFunctionPointerType)(void);

@interface SimRuntime : NSObject
{
    unsigned int _version;
    unsigned int _minHostVersion;
    unsigned int _maxHostVersion;
    unsigned int _minCoreSimulatorFrameworkVersion;
    unsigned int _maxCoreSimulatorFrameworkVersion;
    NSString *_name;
    NSString *_identifier;
    NSBundle *_bundle;
    NSString *_root;
    NSString *_versionString;
    NSString *_buildVersionString;
    NSDictionary *_supportedFeatures;
    NSDictionary *_supportedFeaturesConditionalOnDeviceType;
    NSDictionary *_requiredHostServices;
    NSDictionary *_forwardHostNotifications;
    NSDictionary *_forwardHostNotificationsWithState;
    NSString *_platformPath;
    NSArray *_supportedProductFamilyIDs;
    NSDictionary *_environment_extra;
    void *_libLaunchHostHandle;
}

+ (id)supportedRuntimes;
+ (id)supportedRuntimesByAlias;
+ (id)supportedRuntimesByIdentifier;

+ (void)supportedRuntimesAddProfilesAtPath:(NSString *)path;

- (id)initWithBundle:(NSBundle *)bundle;
- (id)initWithPath:(NSString *)path;
- (id)init;

@property (retain) NSBundle *bundle;

@property (copy) NSDictionary *aliases;

@property unsigned int maxCoreSimulatorFrameworkVersion; // @synthesize maxCoreSimulatorFrameworkVersion=_maxCoreSimulatorFrameworkVersion;
@property unsigned int minCoreSimulatorFrameworkVersion; // @synthesize minCoreSimulatorFrameworkVersion=_minCoreSimulatorFrameworkVersion;
@property unsigned int maxHostVersion; // @synthesize maxHostVersion=_maxHostVersion;
@property unsigned int minHostVersion; // @synthesize minHostVersion=_minHostVersion;

@property(nonatomic) void *libLaunchHostHandle; // @synthesize libLaunchHostHandle=_libLaunchHostHandle;
@property(copy) NSDictionary *environment_extra; // @synthesize environment_extra=_environment_extra;
@property(copy) NSArray *supportedProductFamilyIDs; // @synthesize supportedProductFamilyIDs=_supportedProductFamilyIDs;
@property(copy) NSString *platformPath; // @synthesize platformPath=_platformPath;
@property(copy) NSDictionary *forwardHostNotificationsWithState; // @synthesize forwardHostNotificationsWithState=_forwardHostNotificationsWithState;
@property(copy) NSDictionary *forwardHostNotifications; // @synthesize forwardHostNotifications=_forwardHostNotifications;
@property(copy) NSDictionary *requiredHostServices; // @synthesize requiredHostServices=_requiredHostServices;
@property(copy) NSDictionary *supportedFeaturesConditionalOnDeviceType; // @synthesize supportedFeaturesConditionalOnDeviceType=_supportedFeaturesConditionalOnDeviceType;

@property(copy) NSDictionary *supportedFeatures; // @synthesize supportedFeatures=_supportedFeatures;
@property unsigned int version; // @synthesize version=_version;
@property(copy) NSString *buildVersionString; // @synthesize buildVersionString=_buildVersionString;
@property(copy) NSString *versionString; // @synthesize versionString=_versionString;
@property(copy) NSString *root; // @synthesize root=_root;

@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *name; // @synthesize name=_name;

- (id)platformRuntimeOverlay;
- (CDUnknownFunctionPointerType)launch_sim_set_death_handler;
- (CDUnknownFunctionPointerType)launch_sim_waitpid;
- (CDUnknownFunctionPointerType)launch_sim_spawn;
- (CDUnknownFunctionPointerType)launch_sim_getenv;
- (CDUnknownFunctionPointerType)launch_sim_bind_session_to_port;
- (CDUnknownFunctionPointerType)launch_sim_find_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_register_endpoint;
- (BOOL)isAvailableWithError:(id *)arg1;
@property(readonly) BOOL available;
- (id)dyld_simPath;
- (BOOL)createInitialContentPath:(id)arg1 error:(id *)arg2;
- (void)createInitialContentPath:(id)arg1;
- (id)sampleContentPath;
- (long long)compare:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (BOOL)supportsDeviceType:(id)arg1;
- (BOOL)supportsDevice:(id)arg1;
- (id)environment;
- (id)description;


@end

