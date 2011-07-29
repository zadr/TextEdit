#import <Cocoa/Cocoa.h>

@interface MultiplePageView : NSView {
    NSPrintInfo *printInfo;
    NSColor *lineColor;
    NSColor *marginColor;
    NSUInteger numPages;
    NSTextLayoutOrientation layoutOrientation;
}
@property (nonatomic, copy) NSPrintInfo *printInfo;
@property (nonatomic, readonly) CGFloat pageSeparatorHeight;
@property (nonatomic, readonly) NSSize documentSizeInPage;	/* Returns the area where the document can draw */

- (NSRect)documentRectForPageNumber:(NSUInteger)pageNumber;	/* First page is page 0 */
- (NSRect)pageRectForPageNumber:(NSUInteger)pageNumber;	/* First page is page 0 */

@property (nonatomic) NSUInteger numberOfPages;
@property (nonatomic, copy) NSColor *lineColor;
@property (nonatomic, copy) NSColor *marginColor;
@property (nonatomic) NSTextLayoutOrientation layoutOrientation;
@end
