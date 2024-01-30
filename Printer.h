#pragma once

#include <string>
#include <Windows.h>
#include <QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <winspool.h>


// typedefs
typedef enum TIPOS_MODO {
	NO_ESPECIFICADO = 0,
	NORMAL          = 1,
	SERVICIO        = 2
}*PTIPOS_MODO;

typedef struct NIVELES_TINTA {
	int Black;
	int Magenta;
	int Amarillo;
	int Cian;
}*PNIVELES_TINTA;

// Defines
#define CONTADORES_MAX 3
#define CONTADORES_MIN 1


class Printer : public QPrinter
{
    Q_GADGET

public:
    Printer(const Printer& printer);
    Printer(HANDLE hImpresora, QPrinterInfo printerInfo);
    ~Printer();

	HANDLE hPrinter;
	std::string Modelo;
	std::string Estado;
	std::string Serial;
	std::string MAC;
    std::string ultimos_errores;
	TIPOS_MODO Modo;
	NIVELES_TINTA NivelesTinta;
	int Contadores;
    bool esta_soportada;

    const Printer& operator=(const Printer &other);

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
	bool leer_modelo();

	// Lee el estado y establece propiedad Estado
	bool leer_estado();

	// Lee el serial y establece propiedad Serial.
	bool leer_serial();

	// Lee el MAC y establece propiedad MAC.
	bool leer_mac();

	// Lee el modo en que se encuentra la impresora y establece propiedad Modo.
	bool leer_modo();

	// Lee los niveles de tinta de la impresora y establece propiedad Nivel de Tinta.
	bool leer_niveles_tinta();

    // Verifica si está impresora está soportada.
	bool verificar_si_esta_soportada();
};

