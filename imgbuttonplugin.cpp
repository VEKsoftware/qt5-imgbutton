#include "imgbutton.h"
#include "imgbuttonplugin.h"

#include <QtPlugin>

ImgButtonPlugin::ImgButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ImgButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ImgButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ImgButtonPlugin::createWidget(QWidget *parent)
{
    return new ImgButton(parent);
}

QString ImgButtonPlugin::name() const
{
    return QLatin1String("ImgButton");
}

QString ImgButtonPlugin::group() const
{
    return QLatin1String("Custom");
}

QIcon ImgButtonPlugin::icon() const
{
    return QIcon();
}

QString ImgButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ImgButtonPlugin::whatsThis() const
{
    return QLatin1String("Vek Image Button");
}

bool ImgButtonPlugin::isContainer() const
{
    return true;
}

QString ImgButtonPlugin::domXml() const
{
    //return QLatin1String("<widget class=\"ImgButton\" name=\"imgButton\">\n</widget>\n");

    return QLatin1String("<widget class=\"ImgButton\" name=\"imgButton\">"
                         "<property name=\"sizePolicy\">"
                          "<sizepolicy hsizetype=\"Ignored\" vsizetype=\"Ignored\">"
                           "<horstretch>0</horstretch>"
                           "<verstretch>0</verstretch>"
                          "</sizepolicy>"
                         "</property>"
                         "<layout class=\"QVBoxLayout\" name=\"verticalLayout_18\">"
                          "<item>"
                           "<widget class=\"QLabel\" name=\"img\">"
                            "<property name=\"text\">"
                             "<string/>"
                            "</property>"
                           "</widget>"
                          "</item>"
                          "<item>"
                           "<widget class=\"QLabel\" name=\"text\">"
                            "<property name=\"text\">"
                             "<string>Профиль</string>"
                            "</property>"
                           "</widget>"
                          "</item>"
                         "</layout>"
                        "</widget>");
}

QString ImgButtonPlugin::includeFile() const
{
    return QLatin1String("imgbutton.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(imgbuttonplugin, ImgButtonPlugin)
#endif // QT_VERSION < 0x050000
