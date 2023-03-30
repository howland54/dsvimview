#include "SensorPage.h"

SensorPage::SensorPage(QWidget *parent) : QWidget(parent)
{
    ushort degree = 0x00b0;
    degreeSymbol = QString::fromUtf16(&degree,1);

    lastCTD = QDateTime::currentDateTimeUtc().addSecs(-3600);
    lastFathometer = lastCTD;
    lastGPS = lastCTD;
    lastAltimeter = lastCTD;
    lastAttitude = lastCTD;

    ageTimer = new QTimer();
    ageTimer->setInterval(250);
    connect(ageTimer, SIGNAL(timeout()), this, SLOT(ageTimeout()));

    ctdGroupBox = new QGroupBox("CTD");

    dLabel = new QLabel("Depth:");
    dValue = new QLabel("???");

    tLabel  = new QLabel("Temp:");
    tValue = new QLabel("???");

    ctdAgeLabel = new QLabel("Age:");
    ctdAgeValue = new QLabel("???");

    QGridLayout *ctdLayout = new QGridLayout(ctdGroupBox);
    ctdLayout->addWidget(dLabel,0,0);
    ctdLayout->addWidget(dValue,0,1);
    ctdLayout->addWidget(tLabel,1,0);
    ctdLayout->addWidget(tValue,1,1);
    ctdLayout->addWidget(ctdAgeLabel,2,0);
    ctdLayout->addWidget(ctdAgeValue,2,1);


    gpsGroupBox = new QGroupBox("GPS");
    latitudeLabel = new QLabel("Latitude:");
    latitudeValue = new QLabel("???");
    longitudeLabel = new QLabel("Longitude:");
    longitudeValue = new QLabel("???");
    gpsAgeLabel = new QLabel("Age:");
    gpsAgeValue = new QLabel("???");

    QGridLayout *gpsLayout = new QGridLayout(gpsGroupBox) ;

    gpsLayout->addWidget(latitudeLabel,0,0);
    gpsLayout->addWidget(latitudeValue,0,1);
    gpsLayout->addWidget(longitudeLabel,1,0);
    gpsLayout->addWidget(longitudeValue,1,1);
    gpsLayout->addWidget(gpsAgeLabel,2,0);
    gpsLayout->addWidget(gpsAgeValue,2,1);

    fathometerGroupBox = new QGroupBox("fathometer");
    fathometerLabel = new QLabel("fathometer");
    fathometerValue = new QLabel("???");
    fathometerAgeLabel = new QLabel("Age:");
    fathometerAgeValue = new QLabel("???");

    QGridLayout *fathometerLayout = new QGridLayout(fathometerGroupBox) ;

    fathometerLayout->addWidget(fathometerLabel,0,0);
    fathometerLayout->addWidget(fathometerValue,0,1);
    fathometerLayout->addWidget(fathometerAgeLabel,1,0);
    fathometerLayout->addWidget(fathometerAgeValue,1,1);

    altimeterGroupBox = new QGroupBox("altimeter");
    altimeterLabel = new QLabel("altimeter");
    altimeterValue = new QLabel("???");
    altimeterAgeLabel = new QLabel("Age:");
    altimeterAgeValue = new QLabel("???");

    QGridLayout *altimeterLayout = new QGridLayout(altimeterGroupBox) ;

    altimeterLayout->addWidget(altimeterLabel,0,0);
    altimeterLayout->addWidget(altimeterValue,0,1);
    altimeterLayout->addWidget(altimeterAgeLabel,1,0);
    altimeterLayout->addWidget(altimeterAgeValue,1,1);

    microstrainGroupBox = new QGroupBox("Microstrain");
    pitchLabel = new QLabel("pitch:");
    pitchValue = new QLabel("???");
    rollLabel = new QLabel("roll:");
    rollValue = new QLabel("???");
    headingLabel = new QLabel("heading:");
    headingValue = new QLabel("???");
    microstrainAgeLabel = new QLabel("Age:");
    microstrainAgeValue = new QLabel("???");

    QGridLayout *microstrainLayout = new QGridLayout(microstrainGroupBox) ;

    microstrainLayout->addWidget(pitchLabel,0,0);
    microstrainLayout->addWidget(pitchValue,0,1);
    microstrainLayout->addWidget(rollLabel,1,0);
    microstrainLayout->addWidget(rollValue,1,1);
    microstrainLayout->addWidget(headingLabel,2,0);
    microstrainLayout->addWidget(headingValue,2,1);
    microstrainLayout->addWidget(microstrainAgeLabel,3,0);
    microstrainLayout->addWidget(microstrainAgeValue,3,1);

    QGridLayout *masterLayout = new QGridLayout(this);
    masterLayout->addWidget(ctdGroupBox,0,0);
    masterLayout->addWidget(gpsGroupBox,0,1);
    masterLayout->addWidget(fathometerGroupBox,0,2);
    masterLayout->addWidget(altimeterGroupBox,1,0);
    masterLayout->addWidget(microstrainGroupBox,1,1);

    ageTimer->start();

}

void SensorPage::setAttitude(double heading, double pitch, double roll)
{
    pitchValue->setText(QString::number(pitch, 'f', 1)+ degreeSymbol);
    rollValue->setText(QString::number(roll, 'f', 1)+ degreeSymbol);
    headingValue->setText(QString::number(heading, 'f', 1)+ degreeSymbol);
    lastAttitude = QDateTime::currentDateTimeUtc();
}

void SensorPage::setCTD(double d, double t)
{
    dValue->setText(QString::number(d,'f',2) + "m");
    tValue->setText(QString::number(t,'f',2) + degreeSymbol);
    lastCTD = QDateTime::currentDateTimeUtc();
}

void SensorPage::setAltimeter(double theAltitude)
{
    altimeterValue->setText(QString::number(theAltitude,'f',1) + "m");
    lastAltimeter = QDateTime::currentDateTimeUtc();
}

void SensorPage::setFathometer(double theDepth)
{
    fathometerValue->setText(QString::number(theDepth,'f',1)+ "m");
    lastFathometer = QDateTime::currentDateTimeUtc();
}
void SensorPage::setGPS(double inLat, double inLon)
{
    int degrees = int(trunc(inLat));      //was int(qRound(coord)) removed-mjs-11/24/2014 to fix error in displayed value cause by round up.
    double minutes = (inLat - degrees) * 60;
    latitudeValue->setText(QString::number(degrees) + degreeSymbol + " " + QString::number(minutes,'f',2)  + "'");

    degrees = int(trunc(inLon));
    minutes = (inLon - degrees) * 60.0;
    longitudeValue->setText(QString::number(degrees) + degreeSymbol + " " + QString::number(minutes,'f',2)  + "'");
    lastGPS = QDateTime::currentDateTimeUtc();
}

void SensorPage::ageTimeout()
{
    QDateTime  now = QDateTime::currentDateTimeUtc();

    qint64 delta = lastCTD.msecsTo(now);
    double dt = delta/1000.0;
    ctdAgeValue->setText(QString::number(dt,'f',1) + "s");

    delta = lastFathometer.msecsTo(now);
    dt = delta/1000.0;
    fathometerAgeValue->setText(QString::number(dt, 'f', 1) + "s");

    delta = lastAltimeter.msecsTo(now);
    dt = delta/1000.0;
    altimeterAgeValue->setText(QString::number(dt, 'f', 1) + "s");

    delta = lastGPS.msecsTo(now);
    dt = delta/1000.0;
    gpsAgeValue->setText(QString::number(dt, 'f', 1) + "s");

    delta = lastAttitude.msecsTo(now);
    dt = delta/1000.0;
    microstrainAgeValue->setText(QString::number(dt, 'f', 1) + "s");


}
