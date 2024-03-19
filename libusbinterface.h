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
    void libusb_log_all(libusb_context *ctx, enum libusb_log_level level, const char *str);


    libusb_context **ctx = NULL;
    libusb_device **devs = NULL;

};

#endif // LIBUSBINTERFACE_H
