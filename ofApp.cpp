#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(1.5);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetColor(239);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int len_span = 60;
	int line_count_max = 50;
	for (int len = 60; len < 360; len += len_span) {

		for (int line_count = 0; line_count < line_count_max; line_count++) {

			//ofColor line_color;
			//line_color.setHsb(ofMap(line_count, 0, line_count_max, 0, 239), 255, 255);
			//ofSetColor(line_color);

			int deg = ofNoise(line_count * 0.05,len * 0.005, ofGetFrameNum() * 0.002) * 720;

			ofPoint start = this->make_rect_point(len, deg);
			ofPoint end = this->make_rect_point(len + len_span, deg);

			ofDrawLine(start, end);
		}
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg) {

	int param = (deg + 45) / 90;
	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(len, ofMap((deg + 45) % 90, 0, 89, -len, len));
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, len, -len), len);
	case 2:

		return ofPoint(-len, ofMap((deg + 45) % 90, 0, 89, len, -len));
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -len, len), -len);
	default:

		return ofPoint(0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}