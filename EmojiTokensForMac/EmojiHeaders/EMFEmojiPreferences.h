#import <Cocoa/Cocoa.h>
#import "EMFEmojiPreferenceActions.h"

@class NSArray, NSMutableArray, NSMutableDictionary, NSObject<OS_dispatch_queue>, NSString;

@interface EMFEmojiPreferences : NSObject <EMFEmojiPreferenceActions>
{
    NSMutableDictionary *_defaults;
    BOOL _isDefaultDirty;
    NSMutableDictionary *_usageHistory;
    NSMutableArray *_recents;
    NSMutableDictionary *_typingNames;
    NSMutableDictionary *_skinToneBaseKeyPreferences;
    NSMutableDictionary *_categoryIndexes;
    long long _currentSequence;
    NSObject<OS_dispatch_queue> *_differentialPrivacyQueue;
    unsigned long long _maximumRecentsCount;
}

+ (id)_cachedFlagCategoryEmoji:(CDUnknownBlockType)arg1;
+ (id)_recentEmojiStrings;
+ (id)differentialPrivacyRecorderForEmoji:(id)arg1 usageMode:(id)arg2;
+ (id)differentialPrivacyDomain;
+ (id)_cacheDomain;
+ (id)defaultsDomain;
@property(nonatomic) unsigned long long maximumRecentsCount; // @synthesize maximumRecentsCount=_maximumRecentsCount;
- (void).cxx_destruct;
- (id)typingNameForEmoji:(id)arg1;
- (unsigned long long)previouslyUsedIndexInCategory:(id)arg1;
- (id)lastUsedVariantEmojiForEmoji:(id)arg1;
- (id)recentVariantEmojiForEmoji:(id)arg1;
- (BOOL)hasLastUsedVariantForEmoji:(id)arg1;
- (void)didDisplaySkinToneHelp;
- (void)didViewEmojiIndex:(long long)arg1 forCategory:(id)arg2;
- (void)didUseEmoji:(id)arg1 usageMode:(id)arg2 typingName:(id)arg3;
- (void)didUseEmoji:(id)arg1 usageMode:(id)arg2;
- (void)didUseEmoji:(id)arg1;
- (double)scoreForEmojiString:(id)arg1;
- (double)scoreForSequence:(long long)arg1;
- (void)migrateInDidDisplaySkinToneHelp:(BOOL)arg1;
- (void)migrateInPreviouslyUsedCategoryIndexes:(id)arg1;
- (void)migrateInPreviouslyUsedCategory:(id)arg1;
- (void)migrateInSkinTonePreferences:(id)arg1;
- (void)migrateInRecentEmoji:(id)arg1 usages:(id)arg2 typingNames:(id)arg3;
- (void)_cleanUpOldFlagsCaches;
- (void)_checkForDingbatDuplicates;
- (void)migrateFromMajorOSVersion:(long long)arg1;
- (void)loadDefaultsIfNecessary;
- (void)resetEmojiDefaults;
- (void)writeEmojiDefaults;
- (void)_readPreferencesFromDefaults;
- (void)readEmojiDefaults;
@property(readonly, nonatomic) BOOL hasDisplayedSkinToneHelp;
@property(readonly, nonatomic) NSString *previouslyUsedCategory;
@property(readonly, nonatomic) NSArray *recentEmojis;
- (id)init;
- (void)_setRecentStrings:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

