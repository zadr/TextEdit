#import <Cocoa/Cocoa.h>


@interface PrintPanelAccessoryController : NSViewController <NSPrintPanelAccessorizing> {
    BOOL showsWrappingToFit;
    BOOL wrappingToFit;
}

- (IBAction)changePageNumbering:(id)sender;
- (IBAction)changeWrappingToFit:(id)sender;

@property (atomic) BOOL pageNumbering;
@property (atomic) BOOL wrappingToFit;
@property (atomic) BOOL showsWrappingToFit;

@end
