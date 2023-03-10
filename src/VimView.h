#ifndef FLYVIEW_H
#define FLYVIEW_H

#include <QtWidgets>

#include <lcm/lcm.h>
#include <lcm/lcm-cpp.hpp>

#include "../../dsvimlib/include/IniFile.h"
#include "ImageAcquisitionThread.h"
#include "VimCameraControl.h"
#include "LightControlWidget.h"
#include "SystemParameterControl.h"
#include "cameradefines.h"
#include "Stwinch.h"

#define GARDA_SOCKET_NUMBER 30313

#define DEFAULT_GARDA_IP_ADDRESS "192.168.135.91"



#define MAX_N_OF_CAMERAS  2
#define NO_SERIAL_NUMBER "NO_SERIAL_NUMBER"
#define PROGRAM_VERSION 1.1
#define MAX_N_OF_LIGHTS 8
#define NO_LIGHT_POSITION       "UNKNOWN_POSITION"

#define IMG_RECEIPT_TIMEOUT   3500


class VimView : public QWidget
{
   Q_OBJECT

public:
   VimView(char *FileName);
   ~VimView();
   void                   makeActive(bool activeState);
   void                   setExposureActual(double theExposure, int theCamera);
   void                   setGainActual(double theGain, int theCamera);
   void                   setTriggerSource(int theSource, int theCamera);
   void                   setDisplaySize(int cameraNumber, int width, int height);
   void                   shutDown();
   QRect                  getMyGeometry();
   void                   updateLight(int lightNumber, double humidity, double temperature, int lightLevel, int lightMode,double secsSince, int nackCount);
   void                   setRecordingActallyPaused(bool isIt);
   void                   setWriteSuccess(bool isItSuccessful);
   void                   setAltitude(double theAltitude);
   void                   setFathometer(double theFathometerValue);
   void                   setFishDepth(double theDepth);
   void                   setCalcDepth(double theCalcDepth);
private:
   QLabel                 *imageArea[MAX_N_OF_CAMERAS];
   bool                    equalizeDisplay[MAX_N_OF_CAMERAS];
   bool                    stretchDisplay[MAX_N_OF_CAMERAS];
   bool                    histogramDisplay[MAX_N_OF_CAMERAS];
   QGroupBox               *lightGroupBox;

   QTimer                  *imgReceiveTimer;

   unsigned char           *imageForDisplay;
   SystemParameterControl  *systemParameterControl;
   VimCameraControl        *vimCameraControl[MAX_N_OF_CAMERAS];
   LightControlWidget      *lightControlWidgets[MAX_N_OF_LIGHTS];
   int                     nOfDSPLLights;

   int                     nOfCameras;
   int                    imageDisplayWidth[MAX_N_OF_CAMERAS];
   int                    imageDisplayHeight[MAX_N_OF_CAMERAS];
   StWinch                *stWinch;

   QUdpSocket              *netSocket;
   QHostAddress            gardaAddress;
   unsigned short          gardaSocketNumber;

   bool                    recordingPaused;
   bool                    actualRecordingPauseState;
   bool                    isActive;

   int                     imageSkipvalue;
   QDateTime               lastImageDateTime;


public slots:



private slots:
   void                   updateImage(int theImage);
   void                   changeExposureValue(double newExposure, int theCamera);
   void                   changeGainValue(double newGain, int theCamera);
   void                   changeLightLevel(int newLevel);
   void                   changeLightMode(int newMode);
   void                   changeAutoGain(bool isAuto, double theMin, double theMax, int theCamera);
   void                   toggleBinning(bool bin, int theCamera);
   void                   changeAutoExposure(bool isAuto, double theMin, double theMax, int theCamera);
   void                   changeThisEqualization(bool equalize, int theCamera);
   void                   changeThisStretch(bool stretch, int theCamera);
   void                   changeHistogramDisplay(bool doIt, int theCamera);
   void                   takeAPicture(int theCamera);
   void                   startTimedStills(double theInterval, int theCameraNumber);
   void                   stopTimedStills(int theCameraNumber);
   void                   changeDecimationFactor(int theFactor);
   void                   showLightControl(bool showMe);
   void                   sendGardaRateChange(int theInterval);
   void                   pauseRecording(bool pauseIt);
   void                   showWinchFly(bool showIt);
   void                   setSkipValue(int theValue);
   void                   imageHide(int whichImage, bool hideOrNot);
   void                   checkImgReceipt();

signals:
  void                    closing();
};

#endif // FLYVIEW_H
