//
//  LoginView.h
//  iOS
//
//  Created by Ian Grossberg on 3/7/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#pragma once

#include "ofxGenericView.h"

class ofxGenericScrollView;
class ofxGenericTextView;

class InfoView : public ofxGenericView
{
public:
    static ofPtr< InfoView > create( const ofRectangle& setFrame = ofRectangle( 0, 0, 0, 0 ) );

    virtual void didLoad();
    
protected:
    ofPtr< ofxGenericScrollView > _contents;
    
    ofPtr< ofxGenericTextView > _multitaskingSupported;
    
    ofPtr< ofxGenericTextView > _deviceName;
    ofPtr< ofxGenericTextView > _deviceModel;
    ofPtr< ofxGenericTextView > _deviceModelVersion;
    
    ofPtr< ofxGenericTextView > _cpuFrequency;
    ofPtr< ofxGenericTextView > _cpuCount;
    ofPtr< ofxGenericTextView > _totalMemory;
    
    ofPtr< ofxGenericTextView > _macAddress;
    
    ofPtr< ofxGenericTextView > _operatingSystemName;
    ofPtr< ofxGenericTextView > _operatingSystemGroupName;
    ofPtr< ofxGenericTextView > _operatingSystemVersion;
    
    ofPtr< ofxGenericTextView > _uniqueIdentifier;
//    ofPtr< ofxGenericTextView > _orientation;
    ofPtr< ofxGenericTextView > _batteryLevel;
    
#if TARGET_OS_IPHONE
    ofPtr< ofxGenericTextView > _isRetinaDisplay;
    ofPtr< ofxGenericTextView > _is4InchDisplay;
#endif
    
    ofPtr< ofxGenericTextView > createTextView( float& yLocation, string text );
};