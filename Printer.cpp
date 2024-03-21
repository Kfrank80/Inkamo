#include "Printer.h"




// default constructor
Printer::Printer(libusb_device *_devDev, libusb_device_descriptor _devDesc)
{
    devDev = _devDev;
    devDesc = _devDesc;
    esta_soportada = verificar_si_esta_soportada();
    if(esta_soportada && libusb_open(devDev, &handle) == 0)
    {
        if(libusb_claim_interface(handle, 0) == 0)
        {
            if(libusb_get_descriptor(handle,
                                     LIBUSB_DT_ENDPOINT,
                                     0,
                                     (unsigned char*)&BULK_OUT,
                                     sizeof (BULK_OUT)) == sizeof (BULK_OUT) &&
               libusb_get_descriptor(handle,
                                     LIBUSB_DT_ENDPOINT,
                                     1,
                                     (unsigned char*)&BULK_IN,
                                     sizeof (BULK_IN)) == sizeof (BULK_IN))
            {
                leer_modelo();  // Leer el modelo de la impresora
                leer_modo();
                leer_estado();  // Leer el estado de la impresora
                leer_mac();     // Leer la dirección MAC de la impresora (si es WIFI)
                leer_serial();  // Leer el serial
            }
            else
            {
                libusbInterface::libusb_log_all(NULL, LIBUSB_LOG_LEVEL_DEBUG, "Failed to get BULKs descriptors");
            }
        }
        else
        {
            libusbInterface::libusb_log_all(NULL, LIBUSB_LOG_LEVEL_DEBUG, "Failed to claim interface");
        }
    }
}

Printer::~Printer()
{
    if(handle != NULL)
        libusb_close(handle);
}

bool Printer::enviar_comando(QString comando)
{
    int transferred = 0;

    if(!libusb_bulk_transfer(handle,
                         BULK_OUT.bEndpointAddress,  // <----------- Falta obtener la dirección del BULK OUT endpoint
                         (unsigned char*)comando.data(),
                         sizeof(comando.data()),
                         &transferred,
                         3000))
        return true;
    else
        return false;
}

bool Printer::inicializar_impresora()
{    
    if(libusb_control_transfer(handle,
                               SOFT_RESET,
                               2,
                               0,
                               0,
                               NULL,
                               0,
                               3000) != 0)
        libusbInterface::libusb_log_all(NULL, LIBUSB_LOG_LEVEL_DEBUG, "Failed to make a printer SOFT_RESET.");
    enviar_comando("ESC @");
}

// Lee los contadores de la impresora y actualiza la variable Contadores.
bool Printer::leer_contadores()
{
    // TODO: Agregar aquí el código de implementación.    
    return false;
}


// Resetea los contadores de almohadilla a cero y los verifica llamando a leer_contadores.
bool Printer::resetear_contadores()
{
    // TODO: Agregar aquí el código de implementación.

    // Verificar la operacion de reseteo
    leer_contadores();
    if (Contadores == 0)
        return true;
    else
        return false;
}


// Lee los ultimos errores de la impresora.
// Y actualizar variable ultimos_errores.
bool Printer::leer_ultimos_errores()
{
    // TODO: Agregar aquí el código de implementación.
    ultimos_errores = "";
    return false;
}


// Envía orden de limpieza de cabezal.
bool Printer::limpiar_cabezal()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee la memoria EEPROM y retorna un puntero a los bytes en memoria.
char* Printer::leer_eeprom()
{
    // TODO: Agregar aquí el código de implementación.
    return nullptr;
}

// Escribe en la eeprom. La manera en que lo hace depende de la variable Modo
bool Printer::restaurar_eeprom(char* nueva_eeprom)
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee el modelo de la impresora y establece propiedad Modelo
void Printer::leer_modelo()
{
    unsigned char string[100] = {0};

    if(handle != NULL)
    {
        libusb_get_string_descriptor_ascii(handle, devDesc.iManufacturer, string, sizeof(string));
        Modelo = QString((const char*)string);
        libusb_get_string_descriptor_ascii(handle, devDesc.iProduct, string, sizeof(string));
        Modelo += QString((const char*)string);
    }
}


// Lee el estado y establece propiedad Estado
void Printer::leer_estado()
{
    // TODO: Agregar aquí el código de implementación.
    unsigned char data;

    if(libusb_control_transfer(handle,
                            GET_PORT_STATUS,
                            1,
                            0,
                            0,
                            &data,
                            1,
                            3000) == 1)
    {

    }
    else
        libusbInterface::libusb_log_all(NULL, LIBUSB_LOG_LEVEL_DEBUG, "Failed obtaining printers status.");
}


// Lee el serial y establece propiedad Serial.
void Printer::leer_serial()
{
    // TODO: Agregar aquí el código de implementación.
    unsigned char string[100] = {0};

    if(handle != NULL)
    {
        libusb_get_string_descriptor_ascii(handle, devDesc.iSerialNumber, string, sizeof(string));
        Serial = QString((const char*)string);
    }
}


// Lee el MAC y establece propiedad MAC.
void Printer::leer_mac()
{
    // TODO: Agregar aquí el código de implementación.
    MAC = "";
}


// Lee el modo en que se encuentra la impresora y establece propiedad Modo.
void Printer::leer_modo()
{
    // TODO: Agregar aquí el código de implementación.
    Modo = NO_ESPECIFICADO;
}


// Lee los niveles de tinta de la impresora y establece propiedad Nivel de Tinta.
bool Printer::leer_niveles_tinta()
{
    // TODO: Agregar aquí el código de implementación.
    NivelesTinta.Black = 0;
    NivelesTinta.Cian = 0;
    NivelesTinta.Magenta = 0;
    NivelesTinta.Yellow = 0;
    return false;
}


// Verifica si está impresora está soportada.
bool Printer::verificar_si_esta_soportada()
{
    // TODO: Agregar aquí el código de implementación.
    return true;
}
