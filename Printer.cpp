#include "Printer.h"
#include <windows.h>


// Constructor. Inicializa el objeto Printer usando su handler: hPrinter
Printer::Printer(HANDLE hImpresora)
{

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
std::string Printer::leer_ultimos_errores()
{
    // TODO: Agregar aquí el código de implementación.
    return std::string();
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
bool Printer::leer_modelo()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee el estado y establece propiedad Estado
bool Printer::leer_estado()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee el serial y establece propiedad Serial.
bool Printer::leer_serial()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee el MAC y establece propiedad MAC.
bool Printer::leer_mac()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee el modo en que se encuentra la impresora y establece propiedad Modo.
bool Printer::leer_modo()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Lee los niveles de tinta de la impresora y establece propiedad Nivel de Tinta.
bool Printer::leer_niveles_tinta()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// Verifica si está impresora está soportada.
bool Printer::verificar_si_esta_soportada()
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}
