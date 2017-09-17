#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    locationIndex = 0;
    
//    streetview.setLatLon(40.75732,-73.985951);  // Time Sq
//    streetview.setLatLon(40.768153,-73.981473); // Columbus Circus
    // streetview.setLatLon(40.751511,-73.993953);  // Penn Station
    streetview.setLatLon(42.357242, -71.100806);
    streetview.setZoom(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    streetview.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    streetview.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	locationIndex++;
	locationIndex = locationIndex % 3;
	std::cout << locationIndex << std::endl;
	std::vector<double> loc0 = {42.357242, -71.100806};
	std::vector<double> loc1 = {42.357283, -71.100695};
	std::vector<double> loc2 = {42.357330, -71.100586};
	std::vector<std::vector<double>> locations = {loc0, loc1, loc2};
	streetview.setLatLon(locations[locationIndex][0], locations[locationIndex][1]);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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