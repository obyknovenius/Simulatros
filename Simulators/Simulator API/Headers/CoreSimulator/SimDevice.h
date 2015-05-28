//
//  SimDevice.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 28.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

#include "SimRuntime.h"

#include "SimDevcieType.h"

@interface SimDevice : NSObject <SimDeviceNotifier>

+ (id)createDeviceWithName:(id)arg1 setPath:(id)arg2 deviceType:(id)arg3 runtime:(id)arg4;
+ (id)simDevice:(id)arg1 UDID:(id)arg2 deviceTypeIdentifier:(id)arg3 runtimeIdentifier:(id)arg4 state:(unsigned long long)arg5 connectionManager:(id)arg6 setPath:(id)arg7;
+ (id)simDeviceAtPath:(NSString *)path;

+ (BOOL)isValidState:(unsigned long long)arg1;

@property(retain) NSMutableArray *darwinNotificationTokens; // @synthesize darwinNotificationTokens=_darwinNotificationTokens;
//@property(retain, nonatomic) NSDistantObject<SimBridge> *simBridgeDistantObject; // @synthesize simBridgeDistantObject=_simBridgeDistantObject;
@property(retain, nonatomic) NSMachPort *simBridgePort; // @synthesize simBridgePort=_simBridgePort;
@property(retain, nonatomic) NSMachPort *hostSupportPort; // @synthesize hostSupportPort=_hostSupportPort;
@property(retain) NSMachPort *deathTriggerPort; // @synthesize deathTriggerPort=_deathTriggerPort;
@property(retain) NSObject<OS_dispatch_queue> *stateVariableQueue; // @synthesize stateVariableQueue=_stateVariableQueue;
@property(retain) NSMutableDictionary *registeredServices; // @synthesize registeredServices=_registeredServices;
@property(retain) NSObject<OS_dispatch_queue> *bootstrapQueue; // @synthesize bootstrapQueue=_bootstrapQueue;
@property(retain) SimDeviceNotificationManager *notificationManager; // @synthesize notificationManager=_notificationManager;
@property(copy) NSString *setPath; // @synthesize setPath=_setPath;
@property(retain) SimServiceConnectionManager *connectionManager; // @synthesize connectionManager=_connectionManager;
@property(readonly) SimDeviceSet *deviceSet; // @synthesize deviceSet=_deviceSet;
@property(copy) NSUUID *UDID; // @synthesize UDID=_UDID;
@property(copy) NSString *runtimeIdentifier; // @synthesize runtimeIdentifier=_runtimeIdentifier;
@property(copy) NSString *deviceTypeIdentifier; // @synthesize deviceTypeIdentifier=_deviceTypeIdentifier;
- (BOOL)isAvailableWithError:(id *)arg1;
@property(readonly) BOOL available;
- (BOOL)triggerCloudSyncWithError:(id *)arg1;
- (void)triggerCloudSyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)darwinNotificationSetState:(unsigned long long)arg1 name:(id)arg2 error:(id *)arg3;
- (BOOL)darwinNotificationGetState:(unsigned long long *)arg1 name:(id)arg2 error:(id *)arg3;
- (BOOL)postDarwinNotification:(id)arg1 error:(id *)arg2;
- (int)launchApplicationWithID:(id)arg1 options:(id)arg2 error:(id *)arg3;
- (void)launchApplicationAsyncWithID:(id)arg1 options:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (id)installedAppsWithError:(id *)arg1;
- (BOOL)applicationIsInstalled:(id)arg1 type:(id *)arg2 error:(id *)arg3;
- (BOOL)uninstallApplication:(id)arg1 withOptions:(id)arg2 error:(id *)arg3;
- (BOOL)installApplication:(id)arg1 withOptions:(id)arg2 error:(id *)arg3;
- (BOOL)setKeyboardLanguage:(id)arg1 error:(id *)arg2;
- (BOOL)addPhoto:(id)arg1 error:(id *)arg2;
- (BOOL)openURL:(id)arg1 error:(id *)arg2;
- (void)simBridgeSync:(CDUnknownBlockType)arg1;
- (void)simBridgeAsync:(CDUnknownBlockType)arg1;
- (void)simBridgeCommon:(CDUnknownBlockType)arg1;
- (long long)compare:(id)arg1;
- (id)newDeviceNotification;
- (id)createXPCNotification:(const char *)arg1;
- (id)createXPCRequest:(const char *)arg1;
- (void)handleXPCRequestSpawn:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestGetenv:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestLookup:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRegister:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRestore:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUpdateUIWindow:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestErase:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUpgrade:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestShutdown:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestBoot:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRename:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequest:(id)arg1 peer:(id)arg2;
- (void)handleXPCNotificationDeviceUIWindowPropertiesChanged:(id)arg1;
- (void)handleXPCNotificationDeviceRenamed:(id)arg1;
- (void)handleXPCNotificationDeviceStateChanged:(id)arg1;
- (void)handleXPCNotification:(id)arg1;
@property(copy) NSDictionary *uiWindowProperties;
- (void)setName:(id)arg1;
@property(readonly, copy) NSString *name;
- (void)setState:(unsigned long long)arg1;
@property(readonly) unsigned long long state;
- (id)stateString;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (void)simulateMemoryWarning;
- (id)memoryWarningFilePath;
@property(readonly, copy) NSString *logPath;
- (id)dataPath;
- (id)devicePath;
- (id)environment;
- (int)_spawnFromSelfWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (int)_spawnFromLaunchdWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (int)spawnWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (void)spawnAsyncWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (BOOL)registerPort:(unsigned int)arg1 service:(id)arg2 error:(id *)arg3;
- (unsigned int)lookup:(id)arg1 error:(id *)arg2;
- (unsigned int)_lookup:(id)arg1 error:(id *)arg2;
- (id)getenv:(id)arg1 error:(id *)arg2;
- (BOOL)restoreContentsAndSettingsFromDevice:(id)arg1 error:(id *)arg2;
- (void)restoreContentsAndSettingsAsyncFromDevice:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)updateUIWindowProperties:(id)arg1 error:(id *)arg2;
- (void)updateAsyncUIWindowProperties:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)_sendUIWindowPropertiesToDevice;
- (BOOL)eraseContentsAndSettingsWithError:(id *)arg1;
- (BOOL)_bq_eraseContentsAndSettingsWithError:(id *)arg1;
- (void)eraseContentsAndSettingsAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)upgradeToRuntime:(id)arg1 error:(id *)arg2;
- (void)upgradeAsyncToRuntime:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)rename:(id)arg1 error:(id *)arg2;
- (void)renameAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)shutdownWithError:(id *)arg1;
- (BOOL)_shutdownWithError:(id *)arg1;
- (void)shutdownAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)bootWithOptions:(id)arg1 error:(id *)arg2;
- (void)bootAsyncWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)launchdDeathHandlerWithDeathPort:(id)arg1;
- (BOOL)startLaunchdWithDeathPort:(id)arg1 deathHandler:(CDUnknownBlockType)arg2 error:(id *)arg3;
- (void)registerPortsWithLaunchd;
@property(readonly) NSArray *launchDaemonsPaths;
- (BOOL)removeLaunchdJobWithError:(id *)arg1;
- (BOOL)createLaunchdJobWithError:(id *)arg1 extraEnvironment:(id)arg2 disabledJobs:(id)arg3;
- (BOOL)createDarwinNotificationProxiesWithError:(id *)arg1;
- (BOOL)createDarwinNotificationProxy:(id)arg1 toSimAs:(id)arg2 withState:(BOOL)arg3 error:(id *)arg4;
- (BOOL)clearTmpWithError:(id *)arg1;
- (BOOL)ensureLogPathsWithError:(id *)arg1;
- (BOOL)supportsFeature:(id)arg1;
@property(readonly, copy) NSString *launchdJobName;
- (void)saveToDisk;
- (id)saveStateDict;
- (void)validateAndFixState;
@property(readonly, retain) SimRuntime *runtime;
@property(readonly, retain) SimDeviceType *deviceType;
@property(readonly, copy) NSString *descriptiveName;
- (id)description;
- (id)initDevice:(id)arg1 UDID:(id)arg2 deviceTypeIdentifier:(id)arg3 runtimeIdentifier:(id)arg4 state:(unsigned long long)arg5 connectionManager:(id)arg6 setPath:(id)arg7;

@end