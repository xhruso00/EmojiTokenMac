#import <Cocoa/Cocoa.h>

@class EMFEmojiLocaleData, NSArray, NSString;

@interface EMFEmojiToken : NSObject <NSCopying, NSSecureCoding>
{
    struct __EmojiTokenWrapper *_emojiTokenRef;
    BOOL _didFailCEM;
    NSString *_localeIdentifier;
    NSString *_string;
}

+ (id)emojiTokenWithLongCharacter:(unsigned int)arg1 localeData:(id)arg2;
+ (id)emojiTokenWithString:(id)arg1 localeData:(id)arg2;
+ (id)emojiTokensForCEMEmojiTokens:(struct __CFArray *)arg1;
+ (id)emojiTokenWithCEMEmojiToken:(struct __EmojiTokenWrapper *)arg1;
+ (BOOL)supportsSecureCoding;
@property(copy, nonatomic) NSString *string; // @synthesize string=_string;
@property(retain, nonatomic) NSString *localeIdentifier; // @synthesize localeIdentifier=_localeIdentifier;
- (id)nameForType:(int)arg1;
- (id)relatedEmojiTokens:(unsigned long long)arg1;
@property(readonly, nonatomic) BOOL isCommon;
- (BOOL)isEqual:(id)arg1;
- (BOOL)isEqualIgnoringModifiers:(id)arg1;
- (id)copyWithoutModifiers;
- (id)copyWithPresentationStyle:(int)arg1;
- (BOOL)supportsPresentationStyle:(int)arg1;
@property(readonly, nonatomic) int presentationStyle;
- (id)copyWithSkinToneVariant:(int)arg1;
@property(readonly, copy, nonatomic) NSArray *_skinToneVariantStrings;
@property(readonly, copy, nonatomic) NSArray *skinToneVariants;
@property(readonly, nonatomic) int skinTone;
@property(readonly, nonatomic) BOOL supportsSkinToneVariants;
@property(readonly, nonatomic) EMFEmojiLocaleData *localeData;
@property(readonly, nonatomic) const struct __EmojiTokenWrapper *emojiTokenRef; // @synthesize emojiTokenRef=_emojiTokenRef;
- (void)_createEmojiTokenRefIfNecessary;
@property(readonly, nonatomic) NSString *_baseString;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initWithString:(id)arg1 localeIdentifier:(id)arg2;
- (id)initWithCEMEmojiToken:(struct __EmojiTokenWrapper *)arg1;

@end

