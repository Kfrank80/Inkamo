#pragma once

#include <vector>
#include "Printer.h"

class Inkamo
{
public:
	std::vector<Printer> Impresoras;

	// Comprueba si hay actualizaciones. 
	bool actualizar();
	// Detecta impresoras, construye e inicializa cada cobjeto Printer llamando a las funciones correspondientes. Y luego agrega cada impresora al vector Impresoras.
	bool detectar_impresoras();
	// Valida el serial dado en el servidor para la operación requerida.
	bool validar_serial(std::string serial, std::string usuario, std::string modelo_impresora, std::string hardwareID);
};

