#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    locationIndex = 0;

    boundaries.push_back({42.356278, -71.102695});
    boundaries.push_back({42.358054, -71.099114});


    int total = 5;
    for (int i=0; i<total; i++) {
        double latit = i * (boundaries[1][0] - boundaries[0][0]) / total + boundaries[0][0];
        double longit = i * (boundaries[1][1] - boundaries[0][1]) / total + boundaries[0][1];
        locations.push_back({latit, longit});
    }
    
//    streetview.setLatLon(40.75732,-73.985951);  // Time Sq
//    streetview.setLatLon(40.768153,-73.981473); // Columbus Circus
    // streetview.setLatLon(40.751511,-73.993953);  // Penn Station
    // streetview.setLatLon(42.357242, -71.100806);
    // streetview.setLatLon(42.357062, -71.098768);
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
	locationIndex = locationIndex % locations.size();
	std::cout << locationIndex << std::endl;
	// std::vector<double> loc0 = {42.357242, -71.100806};
	// std::vector<double> loc1 = {42.357283, -71.100695};
	// std::vector<double> loc2 = {42.357330, -71.100586};
	// std::vector<std::vector<double>> locations = {loc0, loc1, loc2};
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