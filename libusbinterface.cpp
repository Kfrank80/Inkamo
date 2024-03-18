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
    const struct libusb_init_option options = {{.option = LIBUSB_OPTION_LOG_LEVEL, .value = {.ival = LIBUSB_LOG_LEVEL_DEBUG}},
                                               {.option = LIBUSB_OPTION_LOG_CB, .value = {.log_cbval = libusb_log_all}}};

    result = libusb_init_context(ctx, options, 2);
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


