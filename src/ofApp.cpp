#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout<<"LOADING TWIRL SHADER" <<endl;
    twirlShader.load("shaders/twirl_GLSL");
    
    camWidth=640;
    camHeight = 480;
    
    vidGrabber.initGrabber(camWidth, camHeight);
    
    tex1.setTextureWrap(GL_REPEAT, GL_REPEAT);
    tex1.allocate(400,400,GL_RGB,GL_RGBA);
    
    centerOff = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()) {
        tex1=vidGrabber.getTextureReference();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black);
    
    ofEnableNormalizedTexCoords(); //This lets you do 0-1 range instead of 0-640 (in pixels)
    tex1.bind();
    twirlShader.begin();
    twirlShader.setUniformTexture("tex0", tex1, 0);
    twirlShader.setUniform1f("amp", 5*sin(0.1*ofGetElapsedTimef()));
    twirlShader.setUniform1f("phase", 20*sin(0.25*ofGetElapsedTimef()));
    twirlShader.setUniform2f("center", 0.5, 0.5); //this is the center of the texture, not the center of the twirl
    
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex3f(0,0,0);
    glTexCoord2f(1,0); glVertex3f(ofGetWidth(),0,0);
    glTexCoord2f(1,1); glVertex3f(ofGetWidth(),ofGetHeight(),0);
    glTexCoord2f(0,1); glVertex3f(0,ofGetHeight(),0);
    
    glEnd();
    twirlShader.end();
    tex1.unbind();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='p'){
        centerOff += 0.1;
    }
    if(key=='o'){
        centerOff -= 0.1;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
