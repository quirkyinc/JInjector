//
//  JInjector.h
//  JInjector
//
//  Created by Jeremy Tregunna on 2013-03-08.
//  Copyright (c) 2013 Jeremy Tregunna. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol JInjectable;

/**
 * Returns the default injector
 */
#define JDEFAULT_INJECTOR [JInjector defaultInjector]

/**
 * Return an instance of a class from a specific injector.
 *
 * @param injector The injector to pull the instance from.
 * @param cls The class to create an instance of.
 * @return An instance of the class.
 */
#define JInject(injector, cls) [((injector) ?: JDEFAULT_INJECTOR) objectForClass:[cls class]]

@interface JInjector : NSObject

/**
 * Returns the default injector.
 *
 * @return The default injector.
 */
+ (instancetype)defaultInjector;

/**
 * Ask the injector for the instance representing the class.
 *
 * This method will optionally invoke an instance method awakeFromInitialization on your object, exactly once per instance after it has been allocated.
 *
 * @param aClass The class to use as the lookup key
 * @return An instance of the class aClass.
 */
- (id)objectForClass:(Class)aClass;

/**
 * Caches an object into the injector for a given class.
 *
 * This method will overwrite any previous cached object.
 * @param anObject The object to cache.
 * @param aClass The class to associate the object with.
 */
- (void)setObject:(id<JInjectable>)anObject forClass:(Class)aClass;

/**
 * Remove a specific instance from the injector.
 *
 * This method is useful if you have modified the state of some object and wish to get a fresh instance. First remove the object, and then ask for a new one.
 *
 * @param anObject The object to remove
 */
- (void)invalidateObject:(id<JInjectable>)anObject;

/**
 * Remove all instances of all classes from the injector.
 */
- (void)invalidateAllObjects;

@end

@protocol JInjectable <NSObject>
@optional
/**
 * Perform any initialization that an instance may require.
 *
 * 
 */
- (void)awakeFromInitialization;
@end
