#ifndef SENSORPAGE_H
#define SENSORPAGE_H

#include <QtWidgets>

class SensorPage : public QWidget
{
    Q_OBJECT
public:
    explicit    SensorPage(QWidget *parent = nullptr);
    void        setAttitude(double heading, double pitch, double roll);
    void        setCTD(double d, double t);
    void        setGPS(double lat, double lon);
    void        setFathometer(double depth);
    void        setAltimeter(double altitude);
private:
    QGroupBox   *ctdGroupBox;
    QLabel      *dLabel;
    QLabel      *dValue;
    QLabel      *tLabel;
    QLabel      *tValue;
    QLabel      *ctdAgeLabel;
    QLabel      *ctdAgeValue;
    QDateTime   lastCTD;

    QGroupBox   *gpsGroupBox;
    QLabel      *latitudeLabel;
    QLabel      *latitudeValue;
    QLabel      *longitudeLabel;
    QLabel      *longitudeValue;
    QLabel      *gpsAgeLabel;
    QLabel      *gpsAgeValue;
    QDateTime   lastGPS;

    QGroupBox   *fathometerGroupBox;
    QLabel      *fathometerLabel;
    QLabel      *fathometerValue;
    QLabel      *fathometerAgeLabel;
    QLabel      *fathometerAgeValue;
    QDateTime  lastFathometer;

    QGroupBox   *altimeterGroupBox;
    QLabel      *altimeterLabel;
    QLabel      *altimeterValue;
    QLabel      *altimeterAgeLabel;
    QLabel      *altimeterAgeValue;
    QDateTime   lastAltimeter;

    QGroupBox   *microstrainGroupBox;
    QLabel      *pitchLabel;
    QLabel      *pitchValue;
    QLabel      *rollLabel;
    QLabel      *rollValue;
    QLabel      *headingLabel;
    QLabel      *headingValue;
    QLabel      *microstrainAgeLabel;
    QLabel      *microstrainAgeValue;
    QDateTime   lastAttitude;


    QString     degreeSymbol;

    QTimer      *ageTimer;




signals:
private slots:
    void    ageTimeout();


};

#endif // SENSORPAGE_H
