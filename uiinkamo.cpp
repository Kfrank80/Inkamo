#include "uiinkamo.h"
#include "ui_uiinkamo.h"




UiInkamo::UiInkamo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UiInkamo)
{
    ui->setupUi(this);
    detectar_impresoras();
    printerModel.setHorizontalHeaderLabels(QStringList("Printers Detected"));
    selections = new QItemSelectionModel(&printerModel);
    ui->printersTreeView->setModel(&printerModel);
    ui->printersTreeView->setSelectionModel(selections);
    ui->printersTreeView->setUniformRowHeights(true);
    ui->printersTreeView->header()->setStretchLastSection(true);
    ui->printersTreeView->viewport()->setAttribute(Qt::WA_StaticContents);
    // Disable the focus rect to get minimal repaints when scrolling on Mac.
    ui->printersTreeView->setAttribute(Qt::WA_MacShowFocusRect, false);
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
    if(detectar_impresoras())
    {
        ui->printersTreeView->selectAll();
        ui->printersTreeView->clearSelection();
        refrescar_vista_arbol();
        refrescar_vista_info("Some printers detected on the systems.\n"
                             "Please see the choices availables in the Tree view.");
    }
}

// Comprueba si hay actualizaciones. En caso de que las haya,
// la descarga a la carpeta actual sobreescribiendose a si mismo.
// Entonces, retorna true. Si no hay actualizaciones retorna false.
bool UiInkamo::actualizar()
{
    bool hayNuevaVersion;

    // TODO: Agregar aquí el código para comprobar que hay una
    // nueva version disponible del programa en el servidor.
    // Y actualizar variable hayNuevaVersion
    hayNuevaVersion = false;

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
    DWORD tamano = 0, numero = 0;
    PRINTER_INFO_2 *info = NULL;

    EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,
        NULL,
        2,
        NULL,
        0,
        &tamano,
        &numero);

    info = (PRINTER_INFO_2*)malloc(tamano);
    EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,
        NULL,
        2,
        (BYTE*)info,
        tamano,
        &tamano,
        &numero);

    if(numero)
    {
        LPWSTR tempStr = (LPWSTR)malloc(4*2);
        PRINTER_INFO_2 *pinfo = info;

        for (DWORD i=0;i<numero;i++)
        {
            lstrcpynW((LPWSTR)tempStr, (LPCWSTR)pinfo->pPortName, 4);
            if(lstrcmpW(tempStr, (LPCWSTR)L"USB") == 0)
            {
                Printer *tempPrinter = new Printer(*pinfo);
                Impresoras.append(*tempPrinter);
            }
            pinfo++;
        }
        free(tempStr);
        free(info);
        return (bool)Impresoras.size();
    }
    free(info);

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
    QDialog *about = new QDialog(this);
    Ui_aboutDialog *aboutUi = new Ui_aboutDialog();
    aboutUi->setupUi(about);
    about->exec();
    delete aboutUi;
    delete about;
}

void UiInkamo::refrescar_vista_arbol()
{
    printerModel.clear();
    QStandardItem *parentItem = printerModel.invisibleRootItem();
    for (int it=0; it<Impresoras.size(); it++)
    {
        QStandardItem *item = new QStandardItem(*Impresoras[it].printerInfo.pPrinterName);
        parentItem->appendRow(item);
        parentItem = item;
        item = new QStandardItem("Model: " + Impresoras[it].Modelo);
        parentItem->appendRow(item);
        item = new QStandardItem("Status: " + Impresoras[it].Estado);
        parentItem->appendRow(item);
        item = new QStandardItem("Serial: " + Impresoras[it].Serial);
        parentItem->appendRow(item);
        item = new QStandardItem("MAC: " + Impresoras[it].MAC);
        parentItem->appendRow(item);
        item = new QStandardItem("Mode: " + qprinterMode.at(Impresoras[it].Modo));
        parentItem->appendRow(item);
        item = new QStandardItem(QString("Black: " + QString(Impresoras[it].NivelesTinta.Black) +
                                         " Magenta: " + QString(Impresoras[it].NivelesTinta.Magenta) +
                                         " Yellow: " + QString(Impresoras[it].NivelesTinta.Yellow) +
                                         " Cian: " + QString(Impresoras[it].NivelesTinta.Cian)));
        parentItem->appendRow(item);
        item = new QStandardItem("Counters: " + QString(Impresoras[it].Contadores));
        parentItem->appendRow(item);
        parentItem = printerModel.invisibleRootItem();
    }
}

void UiInkamo::refrescar_vista_info(QString text)
{
    ui->textEdit->setText(text);
}

