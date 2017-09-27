#import "EMTextEnumerator.h"
#import "EMEmojiTokenList.h"

@implementation EMTextEnumerator

- (instancetype)init
{
    self = [super init];
    if (self) {
        _emojiDatasByLanguage = [[NSMutableDictionary alloc] init];
    }
    return self;
}

- (void)enumerateEmojiSignifiersInString:(NSString *)string touchingRange:(NSRange)touchingRange language:(NSString *)language usingBlock:(void (^)(EMEmojiTokenList *, NSRange))block
{
//    __block NSCharacterSet *someSet;
//    static dispatch_once_t onceToken;
//    dispatch_once(&onceToken, ^{
//        NSMutableCharacterSet *mutSet = [NSMutableCharacterSet controlCharacterSet];
//        NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
//        [mutSet formUnionWithCharacterSet:set];
//        [mutSet addCharactersInRange:NSMakeRange(4,0xfffc)];
//        [mutSet invert];
//        someSet = [mutSet copy];
//    });
//
//    NSRange range = [string paragraphRangeForRange:NSMakeRange(0, string.length)];
//    NSRange newRange = [string rangeOfCharacterFromSet:someSet options:0 range:range];
    
    EMFEmojiLocaleData *emojiLocaleData = [self emojiDataForLanguage:language];
    [emojiLocaleData enumerateSearchResultsInText:string range:touchingRange options:0x11 searchType:0x1 usingBlock:^(NSArray *tokens, NSRange range, BOOL *stop){
        if (block) {
            if ([tokens count]) {
                EMEmojiTokenList *list = [[EMEmojiTokenList alloc] initWithEmojiTokenArray:tokens];
                block(list, range);
            }
        
        }
    }];
    

    
}

- (EMFEmojiLocaleData *)emojiDataForLanguage:(NSString *)language
{
    id emojiLocaleData = [_emojiDatasByLanguage objectForKey:language];
    if (emojiLocaleData) {
        if ([emojiLocaleData isEqual:[NSNull null]]) {
            emojiLocaleData = nil;
        }
        
    } else {
        emojiLocaleData = [EMFEmojiLocaleData emojiLocaleDataWithLocaleIdentifier:language];
        if (emojiLocaleData) {
            [_emojiDatasByLanguage setObject:emojiLocaleData forKey:language];
        } else {
            [_emojiDatasByLanguage setObject:[NSNull null] forKey:language];
        }
        
    }
    return emojiLocaleData;
}

@end
