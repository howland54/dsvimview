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



    QGridLayout *masterLayout = new QGridLayout(this);
    masterLayout->addWidget(ctdGroupBox,0,0);
    masterLayout->addWidget(gpsGroupBox,0,1);

}
