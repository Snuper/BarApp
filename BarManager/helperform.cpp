#include "helperform.h"
#include "ui_helperform.h"

HelperForm::HelperForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelperForm)
{
    ui->setupUi(this);

    QFile *File = new QFile("C:\\Andrey\\barApp\\BarApp\\BarApp\\src\\main.html");
    File->open(QFile::ReadOnly | QFile::Text);
    QString html = File->readAll();
    QColor linkColor(Qt::blue);
    QString sheet = QString::fromLatin1("a { text-decoration: underline; color: %1 }").arg(linkColor.name());
    ui->textBrowser->document()->setDefaultStyleSheet(sheet);
    ui->textBrowser->setHtml(html);
    ui->textBrowser->setOpenLinks(false);
    ui->textBrowser->setOpenExternalLinks(false);
    File->close();

    connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(onAnchorClicked(QUrl)));
}

HelperForm::~HelperForm()
{
    delete ui;
}

void HelperForm::onAnchorClicked(const QUrl &link)
{
    QString str = link.toString();
    str.replace("%5C", "\\");
    QFile *File= new QFile(str);
    File->open(QFile::ReadOnly|QFile::Text);
    QString html = File->readAll();
    ui->textBrowser->setHtml(html);
    File->close();
}

