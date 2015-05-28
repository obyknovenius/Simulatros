//
//  SimDeviceSet.h
//  Simulators
//
//  Created by Vitaly Dyachkov on 28.05.15.
//  Copyright (c) 2015 Vitaly Dyachkov. All rights reserved.
//

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

@protocol SimDeviceNotifier
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(NSObject<OS_dispatch_queue> *)arg1 handler:(void (^)(NSDictionary *))arg2;
- (unsigned long long)registerNotificationHandler:(void (^)(NSDictionary *))arg1;
@end

@interface SimDeviceNotificationManager : NSObject <SimDeviceNotifier>
{
    NSObject<OS_dispatch_queue> *_handlersQueue;
    NSMutableDictionary *_handlers;
    unsigned long long _next_regID;
    NSObject<OS_dispatch_queue> *_sendQueue;
}

@property(retain) NSObject<OS_dispatch_queue> *sendQueue; // @synthesize sendQueue=_sendQueue;
@property unsigned long long next_regID; // @synthesize next_regID=_next_regID;
@property(retain) NSMutableDictionary *handlers; // @synthesize handlers=_handlers;
@property(retain) NSObject<OS_dispatch_queue> *handlersQueue; // @synthesize handlersQueue=_handlersQueue;
- (void)sendNotification:(id)arg1;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (id)init;

@end

@interface SimServiceConnectionManager : NSObject
{
    NSObject<OS_xpc_object> *_serviceConnection;
    NSObject<OS_dispatch_queue> *_serviceConnectionQueue;
    NSDate *_lastConnectionTime;
}

+ (void)useService:(BOOL)arg1;
+ (id)sharedConnectionManager;
@property(retain) NSDate *lastConnectionTime; // @synthesize lastConnectionTime=_lastConnectionTime;
@property(retain) NSObject<OS_dispatch_queue> *serviceConnectionQueue; // @synthesize serviceConnectionQueue=_serviceConnectionQueue;
@property(retain) NSObject<OS_xpc_object> *serviceConnection; // @synthesize serviceConnection=_serviceConnection;
- (void)handleXPCEvent:(id)arg1;
- (void)dealloc;
- (BOOL)connect;
- (id)init;

@end

@interface SimDeviceSet : NSObject <SimDeviceNotifier>
{
    NSString *_setPath;
    NSObject<OS_dispatch_queue> *_devicesQueue;
    NSMutableDictionary *__devicesByUDID;
    NSMutableDictionary *_devicesNotificationRegIDs;
    SimServiceConnectionManager *_connectionManager;
    SimDeviceNotificationManager *_notificationManager;
}

+ (void)resubscribeAllToNotifications;
+ (id)allSets;
+ (id)setForSetPath:(id)arg1;
+ (id)defaultSet;
+ (id)defaultSetPath;
@property(retain) SimDeviceNotificationManager *notificationManager; // @synthesize notificationManager=_notificationManager;
@property(retain) SimServiceConnectionManager *connectionManager; // @synthesize connectionManager=_connectionManager;
@property(retain) NSMutableDictionary *devicesNotificationRegIDs; // @synthesize devicesNotificationRegIDs=_devicesNotificationRegIDs;
@property(retain) NSMutableDictionary *_devicesByUDID; // @synthesize _devicesByUDID=__devicesByUDID;
@property(retain) NSObject<OS_dispatch_queue> *devicesQueue; // @synthesize devicesQueue=_devicesQueue;
@property(copy) NSString *setPath; // @synthesize setPath=_setPath;
- (void)handleXPCRequestDeleteDevice:(id)arg1 peer:(id)arg2 device:(id)arg3;
- (void)handleXPCRequestCreateDevice:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequest:(id)arg1 peer:(id)arg2;
- (void)handleXPCNotificationDeviceRemoved:(id)arg1;
- (void)handleXPCNotificationDeviceAdded:(id)arg1;
- (void)handleXPCNotification:(id)arg1;
- (BOOL)deleteDevice:(id)arg1 error:(id *)arg2;
- (void)deleteDeviceAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (id)createDeviceWithType:(id)arg1 runtime:(id)arg2 name:(id)arg3 error:(id *)arg4;
- (void)createDeviceAsyncWithType:(id)arg1 runtime:(id)arg2 name:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (void)sendNotification:(id)arg1;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (void)removeDeviceAsync:(id)arg1;
- (void)addDevice:(id)arg1;
- (void)addDeviceAsync:(id)arg1;
- (void)updateDefaultDevices;
- (id)defaultCreatedPlistPath;
@property(readonly, copy) NSArray *availableDevices;
@property(readonly, copy) NSArray *devices;
@property(readonly, copy) NSDictionary *devicesByUDID;
- (id)description;
- (id)initWithSetPath:(id)arg1;
- (BOOL)subscribeToNotificationsWithError:(id *)arg1;

@end