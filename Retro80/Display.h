#import <OpenGL/gl.h>

@protocol DisplayController;
@protocol Keyboard;

@class Document;
@class Digit;

// -----------------------------------------------------------------------------
// Display - Экран компьютера
// -----------------------------------------------------------------------------

@interface Display : NSOpenGLView <NSWindowDelegate>

@property (weak) IBOutlet NSResponder *nextResponder;
@property (weak) IBOutlet Document* document;

@property IBOutlet Digit *digit1;
@property IBOutlet Digit *digit2;
@property IBOutlet Digit *digit3;
@property IBOutlet Digit *digit4;

@property IBOutlet Digit *digit5;
@property IBOutlet Digit *digit6;

@property (weak) NSObject <DisplayController> *crt;
@property (weak) NSObject <Keyboard> *kbd;

- (uint32_t *) setupGraphicsWidth:(NSUInteger)width
						   height:(NSUInteger)height;

- (uint32_t *) setupOverlayWidth:(NSUInteger)width
						  height:(NSUInteger)height;

- (uint32_t *) setupTextWidth:(NSUInteger)width
					   height:(NSUInteger)height
						   cx:(NSUInteger)cx
						   cy:(NSUInteger)cy;

@end

// -----------------------------------------------------------------------------
// LCD цифра
// -----------------------------------------------------------------------------

@interface Digit : NSView
@property uint8_t segments;
@end

// -----------------------------------------------------------------------------
// Протокол контролера дисплея
// -----------------------------------------------------------------------------

@protocol DisplayController

@property Display* display;

@optional

- (unichar) charAtX:(unsigned)x
				  Y:(unsigned)y;

- (void) draw;

@end

// -----------------------------------------------------------------------------
// Протокол клавиатуры
// -----------------------------------------------------------------------------

@protocol Keyboard

- (void) flagsChanged:(NSEvent *)theEvent;
- (void) keyDown:(NSEvent *)theEvent;
- (void) keyUp:(NSEvent *)theEvent;

- (void) paste:(NSString *)string;

@property BOOL qwerty;

@end

