# EmojiTokenMac
Emoji search is different on Mac & iOS. 
 ![](https://raw.githubusercontent.com/xhruso00/EmojiTokenMac/master/screenshot.png)
 EmojiFoundation private framework is same on both platforms but they use different calling parameters:
 On mac searchType is 0x2 and iOS 0x1. Reverse engineerign can't tell more...

Single string approach:
```objective-c
   NSString *text = @"Love";
   NSArray <EMFEmojiToken *>*iosEmojiTokens = [[self emojiLocaleData] emojiTokensForText:text
                                                                          phoneticReading:nil
                                                                                  options:0x11
                                                                               searchType:0x1
                                                                     includePrefixMatches:NO];
@end
```

Block based approach:
```objective-c
    NSString *text = @"Love Icecream Phone";
    NSRange range = NSMakeRange(0, text.length);
    [[self emojiLocaleData] enumerateSearchResultsInText:text range:range options:0x11 searchType:0x2 usingBlock:^(NSArray *tokens, NSRange range, BOOL *stop){
        NSString *string = [text substringWithRange:range];
        NSLog(@"String: %@ Range: %@ Emojis %@ ",string, NSStringFromRange(range), [self stringFromTokenEmojiArray:tokens]);
    }];
@end
```
