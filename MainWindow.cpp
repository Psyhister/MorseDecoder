#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLabel>
#include <QRegularExpression>

#include "StaticMorseDictionary.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_morseDecoder(std::make_unique<StaticMorseDictionary>())
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->addWidget(new QLabel(tr("Enter your text or Morse code here:"), this));

    QPlainTextEdit *inputEdit = new QPlainTextEdit(this);
    inputLayout->addWidget(inputEdit);

    mainLayout->addLayout(inputLayout);

    QVBoxLayout *outputLayout = new QVBoxLayout;
    outputLayout->addWidget(new QLabel(tr("Result of conversion:"), this));

    m_outputTextEdit = new QPlainTextEdit(this);
    m_outputTextEdit->setReadOnly(true);
    outputLayout->addWidget(m_outputTextEdit);

    mainLayout->addLayout(outputLayout);

    setLayout(mainLayout);

    connect(inputEdit, &QPlainTextEdit::textChanged, this, [this, inputEdit](){ onInputChanged(inputEdit->toPlainText()); });
}

void MainWindow::onInputChanged(const QString& inputText)
{
    if (inputText.isEmpty())
    {
        m_outputTextEdit->clear();
        return;
    }

    QRegularExpression alphaRegExp("[a-zA-Z]");
    QRegularExpression morseRegExp("[\\.\\- ]");
    if (alphaRegExp.match(inputText).hasMatch())
    {
        auto result = m_morseDecoder.encode(inputText.toStdString());
        m_outputTextEdit->setPlainText(QString::fromStdString(result.status == Status::Ok ? result.value : result.errorMsg));
    }
    else if (morseRegExp.match(inputText).hasMatch())
    {
        auto result = m_morseDecoder.decode(inputText.toStdString());
        m_outputTextEdit->setPlainText(QString::fromStdString(result.status == Status::Ok ? result.value : result.errorMsg));
    }
}
