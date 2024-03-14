#ifndef LIBUSBINTERFACE_H
#define LIBUSBINTERFACE_H

#include <QObject>

#include "libusb/libusb.h"


class libusbInterface : QObject
{
    Q_OBJECT
public:
    libusbInterface();
    ~libusbInterface();

    bool init();
    bool listDevs();

    libusb_context **ctx = NULL;
    libusb_device **devs = NULL;

};

#endif // LIBUSBINTERFACE_H
