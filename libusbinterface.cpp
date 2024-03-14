#include "libusbinterface.h"


// Constructor
libusbInterface::libusbInterface()
{

}

// Destructor
libusbInterface::~libusbInterface()
{
    if(devs != NULL)
        libusb_free_device_list(devs, 1);
    libusb_exit(*ctx);
}

// Inicializacion de libusb
bool libusbInterface::init()
{
    int result;

    result = libusb_init_context(ctx, /*options=*/NULL, /*num_options=*/0);
    if (result < 0)
        return false;
    return true;
}

bool libusbInterface::listDevs()
{
    ssize_t cnt;

    cnt = libusb_get_device_list(NULL, &devs);
    if (cnt < 0)
        return false;
    return true;
}


