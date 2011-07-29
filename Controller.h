#import <Cocoa/Cocoa.h>

@class Preferences;
@class DocumentPropertiesPanelController;
@class LinePanelController;

@interface Controller : NSObject {
    IBOutlet Preferences *__unsafe_unretained preferencesController;
    IBOutlet DocumentPropertiesPanelController *__unsafe_unretained propertiesController;
    IBOutlet LinePanelController *__unsafe_unretained lineController;
}

@property (unsafe_unretained) Preferences *preferencesController;
@property (unsafe_unretained) DocumentPropertiesPanelController *propertiesController;
@property (unsafe_unretained) LinePanelController *lineController;

@end
