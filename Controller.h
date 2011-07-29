#import <Cocoa/Cocoa.h>

@class Preferences, DocumentPropertiesPanelController, LinePanelController;

@interface Controller : NSObject {
    IBOutlet Preferences *__weak preferencesController;
    IBOutlet DocumentPropertiesPanelController *__weak propertiesController;
    IBOutlet LinePanelController *__weak lineController;
}

@property (weak) Preferences *preferencesController;
@property (weak) DocumentPropertiesPanelController *propertiesController;
@property (weak) LinePanelController *lineController;

@end
