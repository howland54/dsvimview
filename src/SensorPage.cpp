#include "SensorPage.h"

SensorPage::SensorPage(QWidget *parent) : QWidget(parent)
{
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

}
