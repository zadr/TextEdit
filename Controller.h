#import <Cocoa/Cocoa.h>

@class Preferences;
@class DocumentPropertiesPanelController;
@class LinePanelController;

@interface Controller : NSObject {
    IBOutlet Preferences *__unsafe_unretained preferencesController;
    IBOutlet DocumentPropertiesPanelController *__unsafe_unretained propertiesController;
    IBOutlet LinePanelController *__unsafe_unretained lineController;
}

@property (atomic, unsafe_unretained) Preferences *preferencesController;
@property (atomic, unsafe_unretained) DocumentPropertiesPanelController *propertiesController;
@property (atomic, unsafe_unretained) LinePanelController *lineController;

@end
