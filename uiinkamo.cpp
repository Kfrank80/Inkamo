#include "uiinkamo.h"
#include "ui_uiinkamo.h"




UiInkamo::UiInkamo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UiInkamo)
{
    ui->setupUi(this);
    detectar_impresoras();
    ui->printersTreeView->setModel(&printerModel);
}

UiInkamo::~UiInkamo()
{
    delete ui;
}

void UiInkamo::on_printersTreeView_collapsed(const QModelIndex &index)
{

}


void UiInkamo::on_printersTreeView_expanded(const QModelIndex &index)
{

}


void UiInkamo::on_printersTreeView_doubleClicked(const QModelIndex &index)
{

}


void UiInkamo::on_printersTreeView_customContextMenuRequested(const QPoint &pos)
{

}


void UiInkamo::on_actionRefresh_Printers_triggered()
{
    detectar_impresoras();
}

// Comprueba si hay actualizaciones. En caso de que las haya,
// la descarga a la carpeta actual sobreescribiendose a si mismo.
// Entonces, retorna true. Si no hay actualizaciones retorna false.
bool UiInkamo::actualizar()
{
    // TODO: Agregar aquí el código para comprobar que hay una
    // nueva version disponible del programa en el servidor.
    // Y actualizar variable hayNuevaVersion
    bool hayNuevaVersion = true;

    // Si hay una nueva version disponible, informar al usuario
    // y permitirle elegir si desea actualizar el software.
    if(hayNuevaVersion)
    {
        QMessageBox msgBox;
        msgBox.setText("There is availables updates. Do you want to update the software?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok)
        {
            // TODO: Código para descargar la nueva version del servidor
            // y sobreescribir el archivo descargado con el actual.
            return true;
        }
    }

    return false;
}


// Detecta impresoras, construye e inicializa cada cobjeto Printer
// llamando a las funciones correspondientes.
// Y luego agrega cada impresora al vector Impresoras.
bool UiInkamo::detectar_impresoras()
{
    // TODO: Agregar aquí el código de implementación.
    QList<QPrinterInfo> impresorasDisponibles = QPrinterInfo::availablePrinters();
    if(!impresorasDisponibles.isEmpty())
    {
        // TODO: Código para inicializar cada impresora encontrada
        foreach (QPrinterInfo actualPrinter, impresorasDisponibles)
        {
            Printer tempPrinter(actualPrinter);
            Impresoras.append(tempPrinter);
        }
        printerModel.clear();
        QStandardItem *parentItem = printerModel.invisibleRootItem();
        for (int it=0; it<Impresoras.size(); it++)
        {
            QStandardItem *item = new QStandardItem(Impresoras[it].printerName());
            parentItem->appendRow(item);
            parentItem = item;
            item = new QStandardItem(Impresoras[it].Modelo);
            parentItem->appendRow(item);
            item = new QStandardItem(qprinterState.at(Impresoras[it].Estado));
            parentItem->appendRow(item);
            item = new QStandardItem(Impresoras[it].Serial);
            parentItem->appendRow(item);
            item = new QStandardItem(Impresoras[it].MAC);
            parentItem->appendRow(item);
            item = new QStandardItem(qprinterMode.at(Impresoras[it].Modo));
            parentItem->appendRow(item);
            item = new QStandardItem(QString("Black: " + QString(Impresoras[it].NivelesTinta.Black) +
                                             " Magenta: " + QString(Impresoras[it].NivelesTinta.Magenta) +
                                             " Yellow: " + QString(Impresoras[it].NivelesTinta.Yellow) +
                                             " Cian: " + QString(Impresoras[it].NivelesTinta.Cian)));
            parentItem->appendRow(item);
            item = new QStandardItem(QString(Impresoras[it].Contadores));
            parentItem->appendRow(item);
        }
        printerModel.setHorizontalHeaderLabels(QStringList("Printers Detected"));

        return true;
    }

    return false;
}


// Valida el serial dado en el servidor para la operación requerida.
bool UiInkamo::validar_serial(QString serial, QString usuario,
                              QString modelo_impresora, QString hardwareID)
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


void UiInkamo::on_actionSettings_triggered()
{

}


void UiInkamo::on_actionExit_triggered()
{
    close();
    exit(0);
}



void UiInkamo::on_actionBuy_Key_triggered()
{

}


void UiInkamo::on_actionCheck_Keys_triggered()
{

}


void UiInkamo::on_actionBuy_Firmware_Key_triggered()
{

}


void UiInkamo::on_actionSupported_Printers_triggered()
{

}


void UiInkamo::on_actionPrinter_Info_triggered()
{

}


void UiInkamo::on_actionRead_Counters_triggered()
{

}


void UiInkamo::on_actionReset_Counters_triggered()
{

}


void UiInkamo::on_actionHead_Clean_triggered()
{

}


void UiInkamo::on_actionRead_EEPROM_triggered()
{

}


void UiInkamo::on_actionRestore_EEPROM_triggered()
{

}


void UiInkamo::on_actionHelp_triggered()
{

}


void UiInkamo::on_actionSupport_triggered()
{

}


void UiInkamo::on_actionAbout_triggered()
{

}

