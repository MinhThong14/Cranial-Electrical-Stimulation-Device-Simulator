#ifndef TREATMENTDATA_H
#define TREATMENTDATA_H

#include <sessiontypes.h>

class TreatmentData
{
public:
    TreatmentData(int l, Session* s, int i);
    ~TreatmentData();
    int getLength();
    Session* getSessionType();
    int getIntensity();
    void setLength(int l);
    void setSessionType(Session* s);
    void setIntensity(int i);
    string getSessionString();

private:
    int lengthInSecs;
    Session* sessionType;
    int intensity;
};

#endif // TREATMENTDATA_H
