#include "treatmentdata.h"

TreatmentData::TreatmentData(int l, Session* s, int i) {
    lengthInSecs = l;
    sessionType = s;
    intensity = i;
}

TreatmentData::~TreatmentData() {
    delete sessionType;
}

int TreatmentData::getLength() {
    return lengthInSecs;
}

Session* TreatmentData::getSessionType() {
    return sessionType;
}

int TreatmentData::getIntensity() {
    return intensity;
}

void TreatmentData::setLength(int l) {
    lengthInSecs = l;
}

void TreatmentData::setSessionType(Session* s) {
    delete sessionType;
    sessionType = s;
}

void TreatmentData::setIntensity(int i) {
    intensity = i;
}

//Returns a string representing this session
string TreatmentData::getSessionString() {
    return (sessionType->getName() + ": " + sessionType->getFrequencyRange());
}
