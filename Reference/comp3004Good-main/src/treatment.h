#ifndef TREATMENT_H
#define TREATMENT_H

#include <QObject>
#include <QString>

enum Waveform { ALPHA, BETA, GAMMA };

/***
 * Purpose: Treatment class to store a treatment's data
 * */

class Treatment : public QObject
{
    Q_OBJECT
public:
    explicit Treatment(float frequency = 0.5, Waveform waveForm = ALPHA, int time = 20, int current = 300, bool isAdministering = false, QObject *parent = nullptr);
    explicit Treatment(Treatment*);
    ~Treatment();

    float getFrequency();
    Waveform getWaveform();
    int getTime();
    int getRemainingTime();
    int getCurrent();
    bool getIsAdministering();

    void setFrequency(float frequency);
    void setWaveform(Waveform waveform);
    void setRemainingTime(int time);
    void setCurrent(int current);
    void setTime(int time);
    void setIsAdministering(bool administer);

signals:

private:
    float frequency;
    Waveform waveForm;
    int time;
    int remainingTime;
    int current;
    bool isAdministering;

};

#endif // TREATMENT_H
