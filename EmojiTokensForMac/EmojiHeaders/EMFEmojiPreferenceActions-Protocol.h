#import <Cocoa/Cocoa.h>

@class EMFEmojiToken, NSString;

@protocol EMFEmojiPreferenceActions <NSObject>
- (void)didDisplaySkinToneHelp;
- (void)didViewEmojiIndex:(long long)arg1 forCategory:(NSString *)arg2;
- (void)didUseEmoji:(EMFEmojiToken *)arg1 usageMode:(NSString *)arg2 typingName:(NSString *)arg3;
- (void)didUseEmoji:(EMFEmojiToken *)arg1 usageMode:(NSString *)arg2;
- (void)didUseEmoji:(EMFEmojiToken *)arg1;
@end

