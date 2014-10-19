#import "RK86Base.h"

@class Partner;

// -----------------------------------------------------------------------------
// Системнный регистр 1 - выбор станицы адресного простарнства
// -----------------------------------------------------------------------------

@interface PartnerSystem1 : NSObject <ReadWrite, NSCoding>

@property uint8_t page;

@property (weak) Partner *partner;

@end

// -----------------------------------------------------------------------------
// Системнный регистр 2 - выбор внешнего устройства
// -----------------------------------------------------------------------------

@interface PartnerSystem2 : NSObject <ReadWrite, NSCoding>

@property uint8_t slot;

@property (weak) Partner *partner;

@end

// -----------------------------------------------------------------------------
// Окно внешнего устройства
// -----------------------------------------------------------------------------

@interface PartnerExternal : NSObject <ReadWrite>
@property NSObject <ReadWrite> *object;
@end

// -----------------------------------------------------------------------------
// Вариант клавиатуры РК86 для Партнера
// -----------------------------------------------------------------------------

@interface PartnerKeyboard : RKKeyboard

@end

// -----------------------------------------------------------------------------
// ПЭВМ «Партнер 01.01»
// -----------------------------------------------------------------------------

@interface Partner : RK86Base

@property PartnerKeyboard *kbd;

@property PartnerExternal *ext1;
@property PartnerExternal *ext2;
@property PartnerExternal *win1;
@property PartnerExternal *win2;

@property PartnerSystem1 *sys1;
@property PartnerSystem2 *sys2;

@property Memory *basic;
@property Memory *ram2;

@end