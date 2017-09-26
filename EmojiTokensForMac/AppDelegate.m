#import "AppDelegate.h"




@interface AppDelegate ()

@end

@implementation AppDelegate



- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{

    //EMFEmojiLocaleData *localeData = [[EMFEmojiLocaleData alloc] initWithLocaleIdentifier:@""];
    
//    // Insert code here to initialize your application
//    NSMethodSignature * mySignature = [EMFEmojiLocaleData
//                                       instanceMethodSignatureForSelector:@selector(emojiTokensForText:phoneticReading:options:searchType:includePrefixMatches:)];
//    NSInvocation * myInvocation = [NSInvocation
//                                   invocationWithMethodSignature:mySignature];
//
//    [myInvocation setTarget:eobj];
//    [myInvocation setSelector:NSSelectorFromString(@"emojiTokensForText:phoneticReading:options:searchType:includePrefixMatches:")];
//    [myInvocation setArgument:&love atIndex:2];
//
//    NSNumber *options = @(0x11);
//    [myInvocation setArgument:&options atIndex:4];
//    NSNumber *searchType = @(0x1);
//    [myInvocation setArgument:&searchType atIndex:5];
//    NSNumber *includePrefixMatches = @(0x1);
//    [myInvocation setArgument:&includePrefixMatches atIndex:6];
//    __block CFTypeRef eobj10;
//    void (^extractSomething)(CFTypeRef *obj10, NSRange range, BOOL *stop) = ^(CFTypeRef *eobj10, NSRange range, BOOL *stop){
//        NSLog(@"Hello %@", eobj10);
//
//    };
//    NSMutableArray *resultSet = [[NSMutableArray alloc] init];
//    [myInvocation setArgument:&extractSomething atIndex:6];
//    [myInvocation invoke];
//    [myInvocation getReturnValue:&resultSet];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
