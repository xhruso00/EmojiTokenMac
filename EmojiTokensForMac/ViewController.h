#import <Cocoa/Cocoa.h>
#import "EMFEmojiLocaleData.h"

@interface ViewController : NSViewController

@property BOOL includePrefixMatches;
@property NSString *keywords;
@property NSArray <NSString *> *localeIdentifiers;
@property NSString *currentLocaleIdentifier;
@property NSNumber *options;
@property NSNumber *searchType;

@property EMFEmojiLocaleData *emojiLocaleData;


@property (weak) IBOutlet NSPopUpButton *localePopup;
@property (weak) IBOutlet NSButton *prefixMatchesButton;
@property (weak) IBOutlet NSTextField *keywordsTextField;

@property (weak) IBOutlet NSTextField *iosResults;
@property (weak) IBOutlet NSTextField *macResults;
@property (weak) IBOutlet NSTextField *customResults;

@property (weak) IBOutlet NSTextField *optionsTextField;
@property (weak) IBOutlet NSTextField *searchTypeTextField;

@end

