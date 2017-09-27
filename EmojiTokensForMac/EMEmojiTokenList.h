#import <Foundation/Foundation.h>
#import "EMFEmojiToken.h"

@interface EMEmojiTokenList : NSObject {
    NSArray *_emojiTokenArray;
}

@property(readonly) NSUInteger count;
@property(readonly) NSArray *emojiTokenArray;

- (instancetype)initWithEmojiTokenArray:(NSArray <EMFEmojiToken *>*)tokenArray;
- (NSString *)description;
- (instancetype)copyWithZone:(NSZone *)zone;
- (EMFEmojiToken *)objectAtIndex:(NSUInteger)index;
- (EMFEmojiToken *)emojiTokenAtIndex:(NSUInteger)index;



@end
