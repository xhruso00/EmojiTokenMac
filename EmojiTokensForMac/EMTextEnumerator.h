#import <Foundation/Foundation.h>
#import "EMFEmojiLocaleData.h"
#import "EMEmojiTokenList.h"

@interface EMTextEnumerator : NSObject
{
    NSMutableDictionary *_emojiDatasByLanguage;
}

- (void)enumerateEmojiSignifiersInString:(NSString *)string touchingRange:(NSRange)touchingRange language:(NSString *)language usingBlock:(void (^)(EMEmojiTokenList *, NSRange))block;
- (EMFEmojiLocaleData *)emojiDataForLanguage:(NSString *)language;

@end
