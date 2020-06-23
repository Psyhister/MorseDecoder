#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "MorseDecoder.h"

class QPlainTextEdit;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onInputChanged(const QString& inputText);

private:
    QPlainTextEdit *m_outputTextEdit = nullptr;

    MorseDecoder m_morseDecoder;

};

#endif // MAINWINDOW_H
