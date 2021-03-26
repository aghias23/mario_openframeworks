#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	player.loadPlayerImage();
}

//--------------------------------------------------------------
void ofApp::update(){
	xPos = player.playerRun(left, right);
	yPos = player.playerJump(up);
}

//--------------------------------------------------------------
void ofApp::draw(){
	player.drawPlayer(xPos, yPos, left, right, up);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RIGHT) {
		right = 1;
	}

	if (key == OF_KEY_LEFT) {
		left = 1;
	}

	if (key == OF_KEY_UP) {
		up = 1;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_RIGHT) {
		right = 0;
	}

	if (key == OF_KEY_LEFT) {
		left = 0;
	}

	if (key == OF_KEY_UP) {
		up = 0;
	}
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
	cout << x << " " << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
