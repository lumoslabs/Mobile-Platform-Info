//
//  PlatformInfo.h
//
//  Created by Ian Grossberg on 1/2/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#pragma once

#include "ofxGenericApp.h"

#include "ofxGenericUtility.h"

#include "ofMain.h"
class PlatformInfo : public ofxGenericApp
{
public:
	void setup();

public:
    virtual ~PlatformInfo();
    static ofPtr< PlatformInfo > getInstance();

protected:
    PlatformInfo();
    static ofPtr< PlatformInfo > _this;
    void setPlatformInfoInstanceToThis();
};


