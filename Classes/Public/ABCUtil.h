//
// Created by Paul P on 1/30/16.
// Copyright (c) 2016 Airbitz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCParsedURI.h"

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define IS_IPHONE4 (([[UIScreen mainScreen] bounds].size.height < 568) ? YES : NO)
#define IS_IPHONE5 (([[UIScreen mainScreen] bounds].size.height > 567 && [[UIScreen mainScreen] bounds].size.height < 569) ? YES : NO)
#define IS_IPHONE6 (([[UIScreen mainScreen] bounds].size.height > 666 && [[UIScreen mainScreen] bounds].size.height < 668) ? YES : NO)
#define IS_IPHONE6_PLUS (([[UIScreen mainScreen] bounds].size.height > 735 && [[UIScreen mainScreen] bounds].size.height < 737) ? YES : NO)
#define IS_IPAD_MINI (([[UIScreen mainScreen] bounds].size.height > 737) ? YES : NO)

#define IS_MIN_IPHONE5 ([[UIScreen mainScreen] bounds].size.height >= 568)
#define IS_MIN_IPHONE6 ([[UIScreen mainScreen] bounds].size.height >= 667)
#define IS_MIN_IPHONE6_PLUS ([[UIScreen mainScreen] bounds].size.height >= 736)
#define IS_MIN_IPAD_MINI ([[UIScreen mainScreen] bounds].size.height > 737)

@class UIImage;

@interface ABCUtil : NSObject

/**
 * Encodes a string into a QR code returned as UIImage *
 * @param string NSString* string to encode
 * @param error NSError** May be set to nil
 * @return UIImage* returned image
 */
+ (UIImage *)encodeStringToQRImage:(NSString *)string error:(ABCError **)error;


/**
 * Parses a bitcoin BIP21 URI, Wif private key, or Airbitz hbits private key
 * @param uri NSString to parse
 * @param error ABCError Pointer to ABCError object. (Optional. May be set to nil)
 * @return ABCParsedURI ABCParsedURI Object with various parameters parsed out
 */
+ (ABCParsedURI *)parseURI:(NSString *)uri error:(ABCError **)error;

/**
 * Encodes a BIP21 compatible payment request URI using various paramters
 * @param address NSString Bitcoin public address
 * @param amount uint64_t Amount of request in satoshis
 * @param label NSString Name of requestor
 * @param message NSString Misc notes of transaction request
 * @param category NSString Airbitz formatted category in the form "[Category]:[Subcategory]"<br>
 *  ie.<br>
 *  Income:Salary<br>
 *  Expense:Rent<br>
 *  Transfer:Airbitz Wallet<br>
 *  Exchange:Buy Bitcoin<br>
 * @param ret NSString Return URI to send user to after payment is made
 * @return NSString Complete BIP21 URI
 */
+ (NSString *)encodeURI:(NSString *)address
                 amount:(uint64_t)amount
                  label:(NSString *)label
                message:(NSString *)message
               category:(NSString *)category
                    ret:(NSString *)ret;


+ (NSString *)platform;
+ (NSString *)platformString;


+ (NSString *)safeStringWithUTF8String:(const char *)bytes;
+ (void)replaceString:(char **)ppszValue withString:(const char *)szNewValue;
+ (void)freeStringArray:(char **)aszStrings count:(unsigned int)count;

#if TARGET_OS_IPHONE
+ (UIImage *)dataToImage:(const unsigned char *)data withWidth:(int)width andHeight:(int)height;
#else
+ (NSImage *)dataToImage:(const unsigned char *)data withWidth:(int)width andHeight:(int)height;
#endif
@end