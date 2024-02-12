#ifndef UIINKAMO_H
#define UIINKAMO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtPrintSupport/QPrinterInfo>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "Printer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UiInkamo; }
QT_END_NAMESPACE

class UiInkamo : public QMainWindow
{
    Q_OBJECT

public:
    UiInkamo(QWidget *parent = nullptr);
    ~UiInkamo();

private slots:
    void on_printersTreeView_collapsed(const QModelIndex &index);

    void on_printersTreeView_expanded(const QModelIndex &index);

    void on_printersTreeView_doubleClicked(const QModelIndex &index);

    void on_printersTreeView_customContextMenuRequested(const QPoint &pos);

    void on_actionRefresh_Printers_triggered();

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_actionBuy_Key_triggered();

    void on_actionCheck_Keys_triggered();

    void on_actionBuy_Firmware_Key_triggered();

    void on_actionSupported_Printers_triggered();

    void on_actionPrinter_Info_triggered();

    void on_actionRead_Counters_triggered();

    void on_actionReset_Counters_triggered();

    void on_actionHead_Clean_triggered();

    void on_actionRead_EEPROM_triggered();

    void on_actionRestore_EEPROM_triggered();

    void on_actionHelp_triggered();

    void on_actionSupport_triggered();

    void on_actionAbout_triggered();

private:
    Ui::UiInkamo *ui;
    QList<Printer> Impresoras;
    QStandardItemModel printerModel;
    QItemSelectionModel *selections;

public:
    // Comprueba si hay actualizaciones.
    bool actualizar();

    // Detecta impresoras, construye e inicializa cada cobjeto Printer llamando a las funciones correspondientes. Y luego agrega cada impresora al vector Impresoras.
    bool detectar_impresoras();

    // Valida el serial dado en el servidor para la operación requerida.
    bool validar_serial(QString serial, QString usuario, QString modelo_impresora, QString hardwareID);

    // Refrescar printersTreeView
    void refrescar_vista_arbol();

    // Refrescar textEdit
    void refrescar_vista_info(QString text);

};


#endif // UIINKAMO_H
