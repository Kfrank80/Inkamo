#pragma once

#include <QStringList>

#include "libusbinterface.h"


#define GET_DEVICE_ID    0b10100001
#define GET_PORT_STATUS  0b10100001
#define SOFT_RESET       0b00100001



// typedefs
typedef enum TIPOS_MODO {
    NO_ESPECIFICADO = 0,
    NORMAL          = 1,
    SERVICIO        = 2
}*PTIPOS_MODO;

typedef struct NIVELES_TINTA {
    int Black;
    int Magenta;
    int Yellow;
    int Cian;
}*PNIVELES_TINTA;

// Defines
#define CONTADORES_MAX 3
#define CONTADORES_MIN 1

const QStringList qprinterState = {"Idle",
                                   "Active",
                                   "Aborted",
                                   "Error"};

const QStringList qprinterMode = {"NO_ESPECIFICADO",
                                  "NORMAL",
                                  "SERVICIO"};


class Printer
{

public:
    Printer(libusb_device *_devDev, libusb_device_descriptor _devDesc);
    ~Printer();

    libusb_device_handle *handle = NULL;
    libusb_device *devDev = NULL;
    libusb_device_descriptor devDesc;
    libusb_interface_descriptor intDesc;
    QString Modelo;
    QString Estado;
    QString Serial;
    QString MAC;
    QString ultimos_errores;
    TIPOS_MODO Modo = NO_ESPECIFICADO;
    NIVELES_TINTA NivelesTinta;
    int Contadores;
    bool esta_soportada;

    // Enviar comando a la impresora y responder
    bool enviar_comando(QString comando);

    // Inicializar impresora
    bool inicializar_impresora();

    // Lee los contadores de la impresora y actualiza la variable Contadores.
    bool leer_contadores();

    // Rsetea los contadores de almohadilla a cero y los verifica llamando a leer_contadores.
    bool resetear_contadores();

    // Lee los ultimos errores de la impresora.
    bool leer_ultimos_errores();

    // Envia orden de limpieza de cabezal.
    bool limpiar_cabezal();

    // Lee la memoria EEPROM y retorna un puntero a los bytes en memoria.
    char *leer_eeprom();

    // Escribe en la eeprom. La manera en que lo hace depende de la variable Modo
    bool restaurar_eeprom(char* nueva_eeprom);

    // Lee el modelo de la impresora y establece propiedad Modelo
    void leer_modelo();

    // Lee el estado y establece propiedad Estado
    void leer_estado();

    // Lee el serial y establece propiedad Serial.
    void leer_serial();

    // Lee el MAC y establece propiedad MAC.
    void leer_mac();

    // Lee el modo en que se encuentra la impresora y establece propiedad Modo.
    void leer_modo();

    // Lee los niveles de tinta de la impresora y establece propiedad Nivel de Tinta.
    bool leer_niveles_tinta();

    // Verifica si est? impresora est? soportada.
    bool verificar_si_esta_soportada();
};

