#import "ViewController.h"
#import <dlfcn.h>
#import "EMFEmojiLocaleData.h"
#import "EMFEmojiToken.h"
#import "EMTextEnumerator.h"
#import "EMEmojiTokenList.h"

static void *libEmojiHandle;
static void *libPickerHandle;

@implementation ViewController

+ (void)load
{
    libEmojiHandle = dlopen("/System/Library/PrivateFrameworks/EmojiFoundation.framework/EmojiFoundation", RTLD_NOW);
    libPickerHandle = dlopen("/System/Library/PrivateFrameworks/CharacterPicker.framework/Versions/A/CharacterPicker", RTLD_NOW);
}

- (void)commonInit
{
    [self setCurrentLocaleIdentifier:@"en"];
    NSArray <NSString *>*availableLocaleIdentifiers = [NSLocale availableLocaleIdentifiers];
    NSArray *sortedLocaleIdentifiers = [availableLocaleIdentifiers sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
    [self setLocaleIdentifiers:sortedLocaleIdentifiers];
    EMFEmojiLocaleData *emojiLocaleData = [[EMFEmojiLocaleData alloc] initWithLocaleIdentifier:[self currentLocaleIdentifier]];
    [self setEmojiLocaleData:emojiLocaleData];
    [self setIncludePrefixMatches:NO];
    [self setKeywords:@"Love"];
    [self setOptions:@(0x11)];
    [self setSearchType:@(0x1)];

}

- (instancetype)initWithNibName:(NSNibName)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        [self commonInit];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    if (self) {
        [self commonInit];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self didChange:self];
}

- (void)updateMacResults
{
    NSString *text = [self keywords];
    if (!text) {
        text = @"";
    }
    NSArray <EMFEmojiToken *>*macEmojiTokens = [[self emojiLocaleData] emojiTokensForText:text
                                                                          phoneticReading:nil
                                                                                  options:0x11
                                                                               searchType:0x2
                                                                     includePrefixMatches:NO];
    
    [[self macResults] setStringValue:[self stringFromTokenEmojiArray:macEmojiTokens]];
}

- (void)updateiOSResults
{
    NSString *text = [self keywords];
    if (!text) {
        text = @"";
    }
    
    NSArray <EMFEmojiToken *>*iosEmojiTokens = [[self emojiLocaleData] emojiTokensForText:text
                                                                          phoneticReading:nil
                                                                                  options:0x11
                                                                               searchType:0x1
                                                                     includePrefixMatches:NO];

    
    [[self iosResults] setStringValue:[self stringFromTokenEmojiArray:iosEmojiTokens]];
}

- (void)updateCustomResults
{
    NSString *text = [self keywords];
    if (!text) {
        text = @"";
    }
    NSUInteger options = [[self options] integerValue];
    NSInteger searchType = [[self searchType] integerValue];
    BOOL includePrefixMatches = [self includePrefixMatches];
    NSArray <EMFEmojiToken *>*customEmojiTokens = [[self emojiLocaleData] emojiTokensForText:text
                                                                          phoneticReading:nil
                                                                                  options:options
                                                                               searchType:searchType
                                                                     includePrefixMatches:includePrefixMatches];
    
    
    [[self customResults] setStringValue:[self stringFromTokenEmojiArray:customEmojiTokens]];
}

- (NSString *)stringFromTokenEmojiArray:(NSArray <EMFEmojiToken *>*)tokenArray
{
    NSMutableString *mutString = [NSMutableString string];
    for (EMFEmojiToken *token in tokenArray) {
        [mutString appendString:[token string]];
    }
    return [mutString copy];
}

- (void)test
{
    EMTextEnumerator *enumerator = [[EMTextEnumerator alloc] init];
    NSString *string = @"Love Icecream";
    NSRange range = NSMakeRange(0, string.length);
    [enumerator enumerateEmojiSignifiersInString:string touchingRange:range language:@"en-US" usingBlock:^(EMEmojiTokenList *list, NSRange range){
        NSLog(@" %@ %@",NSStringFromRange(range), list);
    }];
}

- (IBAction)didChange:(id)sender
{
    [self updateiOSResults];
    [self updateMacResults];
    [self updateCustomResults];
    [self test];
}

- (IBAction)didChangeLocale:(id)sender
{
    EMFEmojiLocaleData *emojiLocaleData = [[EMFEmojiLocaleData alloc] initWithLocaleIdentifier:[self currentLocaleIdentifier]];
    [self setEmojiLocaleData:emojiLocaleData];
    [self didChange:self];
}

- (void)controlTextDidChange:(NSNotification *)notification
{
    [self didChange:self];
}

- (BOOL)control:(NSControl *)control textView:(NSTextView *)textView doCommandBySelector:(SEL)commandSelector
{
    
    if ([control isEqualTo:[self optionsTextField]] || [control isEqualTo:[self searchTypeTextField]]) {
        if (commandSelector == @selector(moveUp:) || commandSelector == @selector(moveDown:)) {
            NSDictionary *options = [control infoForBinding:NSValueBinding];
            NSString *observedkeyPath = options[NSObservedKeyPathKey];
            id observedObject = options[NSObservedObjectKey];
            NSNumber *number = [observedObject valueForKeyPath:observedkeyPath];
            if (commandSelector == @selector(moveUp:)) {
                number = @(MAX(MIN(100, number.intValue + 1),0));
            } else {
                number = @(MAX(MIN(100, number.intValue - 1),0));
            }
            [observedObject setValue:number forKeyPath:observedkeyPath];
            [self didChangeCustomParameter:self];
        }
    }
    [textView performSelector:commandSelector];
    return YES;
}

- (IBAction)didChangeCustomParameter:(id)sender
{
    [self updateCustomResults];
}

- (void)dealloc
{
    if (libPickerHandle) dlclose(libPickerHandle);
    if (libEmojiHandle) dlclose(libEmojiHandle);
}


@end
