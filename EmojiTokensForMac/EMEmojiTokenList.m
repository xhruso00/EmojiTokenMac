#import "EMEmojiTokenList.h"

@implementation EMEmojiTokenList

- (instancetype)initWithEmojiTokenArray:(NSArray <EMFEmojiToken *>*)tokenArray
{
    self = [super init];
    if (self) {
        _emojiTokenArray = [tokenArray copy];
    }
    return self;
}

- (NSString *)description
{
    NSMutableString *mutString = [[super description] mutableCopy];
    for (NSUInteger i = 0; i < [_emojiTokenArray count]; i++) {
        EMFEmojiToken *token = [_emojiTokenArray objectAtIndex:i];
        [mutString appendString:[token string]];
        if (i < [_emojiTokenArray count] - 1) {
                [mutString appendString:@"/"];
        }
    }
    return mutString;
}

- (instancetype)copyWithZone:(NSZone *)zone
{
    return self;
}
- (EMFEmojiToken *)objectAtIndex:(NSUInteger)index
{
    return [_emojiTokenArray objectAtIndex:index];
}

- (EMFEmojiToken *)emojiTokenAtIndex:(NSUInteger)index
{
    return [_emojiTokenArray objectAtIndex:index];
}

- (NSUInteger)count
{
    return [_emojiTokenArray count];
}

- (NSArray *)emojiTokenArray
{
    return _emojiTokenArray;
}

@end
