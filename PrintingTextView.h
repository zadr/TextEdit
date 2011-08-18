#import <Cocoa/Cocoa.h>
@class PrintPanelAccessoryController;

@interface PrintingTextView : NSTextView {
    PrintPanelAccessoryController *__weak printPanelAccessoryController;	// Accessory controller which manages user's printing choices
    NSSize originalSize;			// The original size of the text view in the window (used for non-rewrapped printing)
    NSSize previousValueOfDocumentSizeInPage;	// As user fiddles with the print panel settings, stores the last document size for which the text was relaid out
    BOOL previousValueOfWrappingToFit;		// Stores the last setting of whether to rewrap to fit page or not
}
@property (atomic, weak) PrintPanelAccessoryController *printPanelAccessoryController;
@property (atomic, assign) NSSize originalSize;
@end
