#ifndef SENSORPAGE_H
#define SENSORPAGE_H

#include <QtWidgets>

class SensorPage : public QWidget
{
    Q_OBJECT
public:
    explicit SensorPage(QWidget *parent = nullptr);
private:
    QGroupBox   *ctdGroupBox;
    QLabel      *dLabel;
    QLabel      *dValue;
    QLabel      *tLabel;
    QLabel      *tValue;
    QLabel      *ctdAgeLabel;
    QLabel      *ctdAgeValue;

    QGroupBox   *gpsGroupBox;
    QLabel      *latitudeLabel;
    QLabel      *latitudeValue;
    QLabel      *longitudeLabel;
    QLabel      *longitudeValue;
    QLabel      *gpsAgeLabel;
    QLabel      *gpsAgeValue;

    QGroupBox   *fathometerGroupBox;
    QLabel      *fathometerLabel;
    QLabel      *fathometerValue;
    QLabel      *fathometerAgeLabel;
    QLabel      *fathometerAgeValue;

    QGroupBox   *altimeterGroupBox;
    QLabel      *altimeterLabel;
    QLabel      *altimeterValue;
    QLabel      *altimeterAgeLabel;
    QLabel      *altimeterAgeValue;

    QGroupBox   *microstrainGroupBox;
    QLabel      *pitchLabel;
    QLabel      *pitchValue;
    QLabel      *rollLabel;
    QLabel      *rollValue;
    QLabel      *headingLabel;
    QLabel      *headingValue;





signals:

};

#endif // SENSORPAGE_H
