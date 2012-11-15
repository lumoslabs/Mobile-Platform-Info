//
//  InfoView.cpp
//  iOS
//
//  Created by Ian Grossberg on 3/7/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#include "InfoView.h"

#include "ofxGenericPlatform.h"

#define INFO_VIEW_HEIGHT 40

ofPtr< InfoView > InfoView::create( const ofRectangle& setFrame )
{
    ofPtr< InfoView > view( new InfoView() );
    view->init( view, setFrame );
    return view;
}

void InfoView::didLoad()
{
    ofxGenericView::didLoad();
  
    setBackgroundColor( ofColor( 191, 229, 248 ) );
    
    float yLocation = 0.0f;
    _multitaskingSupported = InfoView::createTextView( yLocation );
    string isSupported;
    if ( ofxGenericPlatform::multitaskingSupported() )
        isSupported = "Yes";
    else 
        isSupported = "No";
    _multitaskingSupported->setText( "Multitasking Supported: " + isSupported );
    
    _deviceName = InfoView::createTextView( yLocation );
    _deviceName->setText( "Device Name: " + ofxGenericPlatform::deviceName() );
    
    _deviceModel = InfoView::createTextView( yLocation );
    _deviceModel->setText( "Device Model: " + ofxGenericPlatform::deviceModel() );
    
    _deviceModelVersion = InfoView::createTextView( yLocation );
    _deviceModelVersion->setText( "Device Model Version: " + ofxGenericPlatform::deviceModelVersion  () );
    
    _operatingSystemName = InfoView::createTextView( yLocation );
    _operatingSystemName->setText( "Operating System Name: " + ofxGenericPlatform::operatingSystemName() );
    
    _operatingSystemGroupName = InfoView::createTextView( yLocation );
    _operatingSystemGroupName->setText( "Operating System Group Name: " + ofxGenericPlatform::operatingSystemGroupName() );
    
    _operatingSystemVersion = InfoView::createTextView( yLocation );
    _operatingSystemVersion->setText( "Operating System Version: " + ofxGenericPlatform::operatingSystemVersion() );
    
    _uniqueIdentifier = InfoView::createTextView( yLocation );
    _uniqueIdentifier->setText( "UUID: " + ofxGenericPlatform::uniqueIdentifier() );
    
    
    //    _orientation = InfoView::createTextView( yLocation += 40 );
    //    _orientation->setText( "Orientation: " + ofxGenericPlatform::getInstance()->orientation() );
    
//    _batteryLevel = InfoView::createTextView( yLocation += 40 );
//    _batteryLevel->setText( "Battery Level: " + ofxGenericPlatform::getInstance()->batteryLevel() );
    
    _isRetinaDisplay = InfoView::createTextView( yLocation );
    _isRetinaDisplay->setText( "Is Retina Display: " + ofxGToString( ofxGenericPlatform::isRetinaDisplay() ) );
    
    _is4InchDisplay = InfoView::createTextView( yLocation );
    _is4InchDisplay->setText( "Is 4 Inch Display: " + ofxGToString( ofxGenericPlatform::is4InchDisplay() ) );
}

ofPtr< ofxGenericTextView > InfoView::createTextView( float& yLocation )
{
    ofPtr< ofxGenericTextView > view  = ofxGenericTextView::create( ofRectangle( 20, yLocation, 300, INFO_VIEW_HEIGHT ) );
    view->setTextAlignment(ofxGenericTextHorizontalAlignmentCenter );
    view->setAutosizeFontToFitText( ofxGenericViewAutoresizingFull );
    addChildView( view );
    yLocation += INFO_VIEW_HEIGHT;
    return view;
}
