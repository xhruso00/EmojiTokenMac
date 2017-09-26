#import <Cocoa/Cocoa.h>

@class NSString;

@interface EMFEmojiCategory : NSObject
{
    NSString *_identifier;
}

+ (id)localizedSkinToneEmojiDescriptionForLocale:(id)arg1;
+ (id)localizedSkinToneEmojiDescription;
+ (id)localizedRecentsDescriptionForLocale:(id)arg1;
+ (id)localizedRecentsDescription;
+ (id)computeEmojiFlagsSortedByLanguage;
+ (id)stringToRegionalIndicatorString:(id)arg1;
+ (id)_emojiSetForIdentifier:(id)arg1;
+ (id)_baseLocalizationKeyForIdentifier:(id)arg1;
+ (id)categoryWithIdentifier:(id)arg1;
+ (id)categoryIdentifierList;
+ (id)flagEmojiCountryCodesCommon;
+ (id)SymbolsEmoji;
+ (id)ObjectsEmoji;
+ (id)TravelAndPlacesEmoji;
+ (id)ActivityEmoji;
+ (id)CelebrationEmoji;
+ (id)FoodAndDrinkEmoji;
+ (id)NatureEmoji;
+ (id)PeopleEmoji;
+ (id)PrepopulatedEmoji;
+ (id)ProfessionEmoji;
+ (id)GenderEmoji;
+ (id)SkinToneEmoji;
+ (id)NoneVariantEmoji;
+ (id)DingbatsVariantEmoji;
@property(readonly, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (id)emojiTokensForLocaleData:(id)arg1;
- (id)shortLocalizedNameForLocale:(id)arg1;
- (id)localizedNameForLocale:(id)arg1;
@property(readonly, nonatomic) NSString *shortLocalizedName;
@property(readonly, nonatomic) NSString *localizedName;
- (void)dealloc;
- (id)initWithIdentifier:(id)arg1;

@end

