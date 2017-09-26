#import <Cocoa/Cocoa.h>

@class EMFEmojiPreferences, NSObject<OS_dispatch_queue>, NSString, NSXPCListener;

@interface EMFEmojiPreferencesService : NSObject <NSXPCListenerDelegate>
{
    NSXPCListener *_listener;
    EMFEmojiPreferences *_preferences;
    NSObject<OS_dispatch_queue> *_dispatchQueue;
}

+ (id)sharedServiceWithMachName:(id)arg1;
@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *dispatchQueue; // @synthesize dispatchQueue=_dispatchQueue;
@property(retain, nonatomic) EMFEmojiPreferences *preferences; // @synthesize preferences=_preferences;
- (void).cxx_destruct;
- (BOOL)listener:(id)arg1 shouldAcceptNewConnection:(id)arg2;
- (void)dealloc;
- (id)initWithMachName:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

