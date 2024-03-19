#include "Printer.h"





// default constructor
Printer::Printer(libusb_device_descriptor *devDesc)
{
    Desc = devDesc;
    esta_soportada = verificar_si_esta_soportada();
    if(esta_soportada)
    {
        leer_modelo();
        leer_modo();
        leer_estado();
        leer_mac();
        leer_serial();
    }
}

Printer::~Printer()
{

}

QString Printer::enviar_comando(QString comando)
{
    return "True";
}

bool Printer::inicializar_impresora()
{    
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
    inicializar_impresora();
}


// Lee el estado y establece propiedad Estado
void Printer::leer_estado()
{
    // TODO: Agregar aquí el código de implementación.
}


// Lee el serial y establece propiedad Serial.
void Printer::leer_serial()
{
    // TODO: Agregar aquí el código de implementación.
    Serial = "";
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
