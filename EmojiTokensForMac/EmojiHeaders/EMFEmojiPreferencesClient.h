#import <Cocoa/Cocoa.h>
#import <EmojiFoundation/EMFEmojiPreferences.h>

@class NSString, NSXPCConnection;

@interface EMFEmojiPreferencesClient : EMFEmojiPreferences
{
    NSXPCConnection *_connection;
    BOOL _isValid;
    NSString *_machName;
}

+ (id)differentialPrivacyRecorderForEmoji:(id)arg1 usageMode:(id)arg2;
+ (id)serviceInterface;
@property(nonatomic) BOOL isValid; // @synthesize isValid=_isValid;
@property(retain, nonatomic) NSString *machName; // @synthesize machName=_machName;
- (void).cxx_destruct;
- (void)didDisplaySkinToneHelp;
- (void)didViewEmojiIndex:(long long)arg1 forCategory:(id)arg2;
- (void)didUseEmoji:(id)arg1 usageMode:(id)arg2 typingName:(id)arg3;
- (void)didUseEmoji:(id)arg1 usageMode:(id)arg2;
- (void)didUseEmoji:(id)arg1;
- (void)writeEmojiDefaults;
- (void)createConnectionIfNecessary;
- (void)dealloc;
- (void)_disconnect;
- (id)_initWithoutConnection;
- (id)initWithMachName:(id)arg1;

@end

