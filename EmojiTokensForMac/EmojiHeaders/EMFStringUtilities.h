#import <Cocoa/Cocoa.h>

@interface EMFStringUtilities : NSObject
{
}

+ (id)_skinToneVariantsForString:(id)arg1;
+ (int)_skinToneForString:(id)arg1;
+ (BOOL)_hasSkinToneVariantsForString:(id)arg1;
+ (id)_baseStringForEmojiString:(id)arg1;
+ (id)professionSkinToneEmojiBaseKey:(id)arg1;
+ (BOOL)_genderEmojiBaseStringNeedVariantSelector:(id)arg1;
+ (BOOL)_emojiString:(id)arg1 containsSubstring:(id)arg2;
+ (id)_baseFirstCharacterString:(id)arg1;
+ (unsigned int)_firstLongCharacterOfString:(id)arg1;
+ (id)_preferenceIndexString:(id)arg1;
+ (id)_stringWithUnichar:(unsigned int)arg1;

@end

