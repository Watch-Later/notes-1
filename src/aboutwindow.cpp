#include "aboutwindow.h"
#include "ui_aboutwindow.h"

#include <QDebug>

/**
 * Initializes the window components and configures the AboutWindow
 */
AboutWindow::AboutWindow(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::AboutWindow)
{
    m_ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("About") + " " + qApp->applicationName());

    m_ui->aboutText->setText("<p>Notes started as a side project by <a href='https://rubymamistvalove.com'>Ruby Mamistvalove</a>, to create an elegant yet powerful cross-platform and open-source note-taking app.</p><a href='https://github.com/nuttyartist/notes'>Source code on Github</a>.<br/><br/><strong>Acknowledgments</strong><br/>This project couldn't come this far without the help of these amazing people:<br/><br/><strong>Programmers:</strong><br/>Alexey Kudryashov<br/>Ali Diouri<br/>Thorbjørn Lindeijer<br/>Waqar Ahmed<br/>Alex Spataru<br/>David Planella<br/><br/><strong>Designers:</strong><br/>Kevin Doyle<br/><br/>And to the many of our beloved users who keep sending us feedback, you are an essential force in helping us improve, thank you!<br/><br/><strong>Notes makes use of the following third-party libraries:</strong><br/><br/>QMarkdownTextEdit<br/>QSimpleUpdater<br/>QAutostart<br/>QXT<br/><br/><strong>Notes makes use of the following open source fonts:</strong><br/><br/>Roboto<br/>Source Sans Pro<br/>Jost<br/>Josefin Sans<br/>Trykker<br/>Mate<br/>iA Writer Mono<br/>iA Writer Duo<br/>iA Writer Quattro<br/>");
    m_ui->aboutText->setTextColor(QColor(26, 26, 26));

#ifdef __APPLE__
    QFont fontToUse = QFont(QStringLiteral("SF Pro Text")).exactMatch() ? QStringLiteral("SF Pro Text") : QStringLiteral("Roboto");
    m_ui->aboutText->setFont(fontToUse);
#else
    m_ui->aboutText->setFont(QFont(QStringLiteral("Roboto")));
#endif
}

AboutWindow::~AboutWindow()
{
    /* Delete UI controls */
    delete m_ui;
}

void AboutWindow::setTheme(QColor backgroundColor, QColor textColor)
{
    QString ss = "QTextBrowser { "
        "background-color: %1;"
        "color: %2;"
        "}";

    ss = ss.arg(backgroundColor.name(), textColor.name());
    m_ui->aboutText->setStyleSheet(ss);
}
