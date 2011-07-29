#import <Cocoa/Cocoa.h>

@class ScalingScrollView;

@interface DocumentWindowController : NSWindowController <NSLayoutManagerDelegate, NSTextViewDelegate> {
    IBOutlet ScalingScrollView *scrollView;
    NSLayoutManager *layoutMgr;
    BOOL hasMultiplePages;
    BOOL rulerIsBeingDisplayed;
    BOOL isSettingSize;
}

// Convenience initializer. Loads the correct nib automatically.

@property (nonatomic, readonly) NSUInteger numberOfPages;
@property (nonatomic, readonly) NSView *documentView;

- (void)breakUndoCoalescing;

/* Layout orientation sections */
@property (nonatomic, readonly) NSArray *layoutOrientationSections;

- (IBAction)chooseAndAttachFiles:(id)sender;

@end
