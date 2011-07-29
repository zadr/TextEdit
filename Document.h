#import <Cocoa/Cocoa.h>

@interface Document : NSDocument {
    // Book-keeping
    BOOL uniqueZone;			/* YES if the zone was created specially for this document */
    BOOL setUpPrintInfoDefaults;	/* YES the first time -printInfo is called */
    
    // Document data
    BOOL openedIgnoringRichText;       /* Setting at the the time the doc was open (so revert does the same thing) */
    NSTextStorage *textStorage;		/* The (styled) text content of the document */
    CGFloat scaleFactor;		/* The scale factor retreived from file */
    BOOL isReadOnly;			/* The document is locked and should not be modified */
    NSColor *backgroundColor;		/* The color of the document's background */
    float hyphenationFactor;		/* Hyphenation factor in range 0.0-1.0 */
    NSSize viewSize;			/* The view size, as stored in an RTF document. Can be NSZeroSize */
    BOOL hasMultiplePages;		/* Whether the document prefers a paged display */
    
    // The next seven are document properties (applicable only to rich text documents)
    NSString *author;			/* Corresponds to NSAuthorDocumentAttribute */
    NSString *copyright;		/* Corresponds to NSCopyrightDocumentAttribute */
    NSString *company;			/* Corresponds to NSCompanyDocumentAttribute */
    NSString *title;			/* Corresponds to NSTitleDocumentAttribute */
    NSString *subject;			/* Corresponds to NSSubjectDocumentAttribute */
    NSString *comment;			/* Corresponds to NSCommentDocumentAttribute */
    NSArray *keywords;			/* Corresponds to NSKeywordsDocumentAttribute */
    
    // Information about how the document was created
    NSStringEncoding documentEncoding;	/* NSStringEncoding used to interpret / save the document */
    BOOL convertedDocument;		/* Converted (or filtered) from some other format (and hence not writable) */
    BOOL lossy;			/* Loaded lossily, so might not be a good idea to overwrite */
    BOOL transient;			/* Untitled document automatically opened and never modified */
    NSURL *defaultDestination;		/* A hint as to where save dialog should default, used if -fileURL is nil */
    NSArray *originalOrientationSections; /* An array of dictionaries. Each describing the text layout orientation for a page */

    // Temporary information about how to save the document
    NSStringEncoding documentEncodingForSaving;	    /* NSStringEncoding for saving the document */
    
    // Temporary information about document's desired file type
    NSString *fileTypeToSet;		/* Actual file type determined during a read, and set after the read (which includes revert) is complete. */ 
}

- (BOOL)readFromURL:(NSURL *)absoluteURL ofType:(NSString *)typeName encoding:(NSStringEncoding)encoding ignoreRTF:(BOOL)ignoreRTF ignoreHTML:(BOOL)ignoreHTML error:(NSError **)outError;

/* Is the document rich? */
@property (nonatomic, getter=isRichText) BOOL richText;

/* Is the document read-only? */
@property (nonatomic, getter=isReadOnly) BOOL readOnly;

/* Document background color */
@property (nonatomic, copy) NSColor *backgroundColor;

/* The encoding of the document... */
@property (nonatomic) NSStringEncoding encoding;

/* Encoding of the document chosen when saving */
@property (nonatomic) NSStringEncoding encodingForSaving;

/* Whether document was converted from some other format (filter services) */
@property (nonatomic) BOOL converted;

/* Whether document was opened ignoring rich text */
/* Setting at the the time the doc was open (so revert does the same thing) */
@property (nonatomic, getter=isOpenedIgnoringRichText) BOOL openedIgnoringRichText; 

/* Whether document was loaded lossily */
@property (nonatomic, getter=isLossy) BOOL lossy;

/* Hyphenation factor (0.0-1.0, 0.0 == disabled) */
@property (nonatomic) float hyphenationFactor;

/* View size (as it should be saved in a RTF file) */
@property (nonatomic) NSSize viewSize;

/* Scale factor; 1.0 is 100% */
@property (nonatomic) CGFloat scaleFactor;

/* Attributes */
@property (nonatomic, copy) NSTextStorage *textStorage; // This will _copy_ the contents of the NS[Attributed]String ts into the document's textStorage.

/* Page-oriented methods */
@property (nonatomic) BOOL hasMultiplePages;
@property (nonatomic) NSSize paperSize;

/* Action methods */
- (IBAction)toggleReadOnly:(id)sender;
- (IBAction)togglePageBreaks:(id)sender;
- (IBAction)saveDocumentAsPDFTo:(id)sender;

/* Whether conversion to rich/plain be done without loss of information */
- (BOOL)toggleRichWillLoseInformation;

/* Default text attributes for plain or rich text formats */
- (NSDictionary *)defaultTextAttributes:(BOOL)forRichText;
- (void)applyDefaultTextAttributes:(BOOL)forRichText;

/* Document properties */
@property (nonatomic, getter=hasDocumentProperties, readonly) BOOL documentProperties;
@property (nonatomic, readonly) NSDictionary *documentPropertyToAttributeNameMappings;
@property (nonatomic, readonly) NSArray *knownDocumentProperties;
- (void)setDocumentPropertiesToDefaults;
- (void)clearDocumentProperties;

/* Transient documents */
@property (nonatomic) BOOL transient;
@property (nonatomic, getter=isTransientAndCanBeReplaced, readonly) BOOL transientAndCanBeReplaced;

/* Layout orientation sections */
@property (nonatomic, copy) NSArray *originalOrientationSections;
@end
