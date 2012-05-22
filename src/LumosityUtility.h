#include "ofLog.h"

void ofLLog( ofLogLevel level, const string & message );
void ofLLogError( const string & message );
void ofLLogFatalError( const string & message );
void ofLLogNotice( const string & message );
void ofLLogVerbose( const string & message );
void ofLLogWarning( const string & message );
void ofLLog( ofLogLevel level, const char* format, ... );
