#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QRegularExpression>

#include "StaticMorseDictionary.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_morseDecoder(std::make_unique<StaticMorseDictionary>())
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPlainTextEdit *inputEdit = new QPlainTextEdit(this);
    mainLayout->addWidget(inputEdit);

    m_outputTextEdit = new QPlainTextEdit(this);
    m_outputTextEdit->setReadOnly(true);
    mainLayout->addWidget(m_outputTextEdit);

    setLayout(mainLayout);

    connect(inputEdit, &QPlainTextEdit::textChanged, this, [this, inputEdit](){ onInputChanged(inputEdit->toPlainText()); });
}

void MainWindow::onInputChanged(const QString& inputText)
{

    QRegularExpression alphaRegExp("[a-zA-Z]");
    if (alphaRegExp.match(inputText).hasMatch())
    {
        auto result = m_morseDecoder.encode(inputText.toStdString());
        m_outputTextEdit->setPlainText(QString::fromStdString(result.status == Status::Ok ? result.value : result.errorMsg));
    }
}
