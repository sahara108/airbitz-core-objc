//
// Created by Paul P on 1/30/16.
// Copyright (c) 2016 Airbitz. All rights reserved.
//

#import "AirbitzCore.h"

typedef NS_ENUM(NSUInteger, ABCDenominationMultiplier) {
    ABCDenominationMultiplierBTC = 100000000,
    ABCDenominationMultiplierMBTC = 100000,
    ABCDenominationMultiplierUBTC = 100,
};

@interface ABCDenomination : NSObject

/// Index of this denomination in the list of denominations.<br>
/// 0 = BTC, 1 = mBTC, 2 = bits
@property (nonatomic)       int             index;

/// Number of satoshis to equal one unit of this  denomination<br>
/// ie. 1 BTC -> multiplier = 100,000,000<br>
/// 1 mBTC -> multipliers = 100,000
@property (nonatomic)       int             multiplier;

/// Denomination symbol such as "Ƀ"
@property (nonatomic)       NSString        *symbol;

/// Denomination label such as "BTC" or "bits"
@property (nonatomic)       NSString        *label;

+ (ABCDenomination *) getDenominationForMultiplier:(ABCDenominationMultiplier)multiplier;
+ (ABCDenomination *) getDenominationForIndex:(int)index;
- (int) prettyBitcoinDecimalPlaces;
- (int) maxBitcoinDecimalPlaces;
- (NSString *)satoshiToBTCString:(int64_t) satoshi;
- (NSString *)satoshiToBTCString:(int64_t) satoshi withSymbol:(bool) symbol;
- (NSString *)satoshiToBTCString:(int64_t) satoshi withSymbol:(bool) symbol cropDecimals:(bool) cropDecimals;
- (int64_t) btcStringToSatoshi:(NSString *) amount;



@end