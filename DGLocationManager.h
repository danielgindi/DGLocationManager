//
//  DGLocationManager.h
//  DGLocationManager
//
//  Created by Daniel Cohen Gindi on 11/23/12.
//  Copyright (c) 2012 danielgindi@gmail.com. All rights reserved.
//
//  https://github.com/danielgindi/DGLocationManager
//
//  General Location Manager Class.
//  Thread safe.
//  No instances required.
//  Delegates are called on main queue.
//  Starts updating location automatically when first delegate is added.
//  Stops updating location automatically when last delegate is removed.
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2014 Daniel Cohen Gindi (danielgindi@gmail.com)
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE. 
//  

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class DGLocationManager;
@protocol DGLocationManagerDelegate <NSObject>

@optional
- (void)locationManagerDidUpdateToLocation:(CLLocation * _Nonnull)newLocation fromLocation:(CLLocation * _Nullable)oldLocation;
- (void)locationManagerDidFailWithError:(NSError * _Nonnull)error;
- (void)locationManagerDidUpdateHeading:(CLHeading * _Nonnull)newHeading;
- (void)locationManagerDidChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end

@interface DGLocationManager : NSObject <CLLocationManagerDelegate>

+ (void)startUpdatingLocation;
+ (void)startUpdatingLocationForDelegates;
+ (void)stopUpdatingLocation;

+ (void)startUpdatingHeading;
+ (void)startUpdatingHeadingForDelegates;
+ (void)stopUpdatingHeading;

+ (void)requestWhenInUseAuthorization;
+ (void)requestAlwaysAuthorization;

+ (void)addAuthorizationDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeAuthorizationDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeAllAuthorizationDelegates;

+ (void)addLocationDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeLocationDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeAllLocationDelegates;

+ (void)addLocationPassiveDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeLocationPassiveDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeAllLocationPassiveDelegates;

+ (void)addHeadingDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeHeadingDelegate:(__unsafe_unretained id<DGLocationManagerDelegate> _Nonnull)delegate;
+ (void)removeAllHeadingDelegates;

+ (void)setLocationActivityType:(CLActivityType)activityType;

+ (CLLocation * _Nullable) location;
+ (CLLocation * _Nullable) previousLocation;

+ (double)magneticHeading;
+ (double)trueHeading;
+ (double)headingAccuracy;

+ (CLAuthorizationStatus)authorizationStatus;

/**
 *  @return YES if the device supports significant location change monitoring, otherwise NO.
 */
+ (BOOL)significantLocationChangeMonitoringAvailable;

/**
 *  @brief
 *      Start monitoring significant location changes.  The behavior of this service is not affected by the desiredAccuracy
 *      or distanceFilter properties.  Locations will be delivered through the same delegate callback as the standard
 *      location service.
 */
+ (void)startMonitoringSignificantLocationChanges;

/**
 *  @brief Stop monitoring significant location changes.
 */
+ (void)stopMonitoringSignificantLocationChanges;

@end
