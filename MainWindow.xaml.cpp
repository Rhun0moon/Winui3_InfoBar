#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml; 
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Winui_InfoBar::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}


void winrt::Winui_InfoBar::implementation::MainWindow::SeverityComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    if (Informational().IsSelected()) TestInfoBar1().Severity(InfoBarSeverity::Informational);
    else if (Success().IsSelected()) TestInfoBar1().Severity(InfoBarSeverity::Success);
    else if (Warning().IsSelected()) TestInfoBar1().Severity(InfoBarSeverity::Warning);
    else if (Error().IsSelected()) TestInfoBar1().Severity(InfoBarSeverity::Error);
}


void winrt::Winui_InfoBar::implementation::MainWindow::MessageComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    if (Short().IsSelected()) TestInfoBar1().Message(L"A short essential app message.");
    else if (Long().IsSelected()) TestInfoBar1().Message(L"대학본관이 2022. 12. 14.(수) ~ 12. 15.(목)까지 이사할 예정이오니, 이전 후 본부 부서 방문 시 [붙임]을 참고하여 주시기 바랍니다.");
}


void winrt::Winui_InfoBar::implementation::MainWindow::ActionButtonComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    if (None().IsSelected()) InfoBarButton().Visibility(Visibility::Collapsed);
    else if (Button().IsSelected()) InfoBarButton().Visibility(Visibility::Visible);
}


void winrt::Winui_InfoBar::implementation::MainWindow::toggleOpen_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (toggleOpen().IsOn()) TestInfoBar1().Visibility(Visibility::Collapsed);
    else TestInfoBar1().Visibility(Visibility::Visible);
}


void winrt::Winui_InfoBar::implementation::MainWindow::toggleIcon_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (toggleIcon().IsOn()) TestInfoBar1().IsIconVisible(FALSE);
    else TestInfoBar1().IsIconVisible(TRUE);
}


void winrt::Winui_InfoBar::implementation::MainWindow::toggleClosable_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (toggleClosable().IsOn()) TestInfoBar1().IsClosable(FALSE);
    else TestInfoBar1().IsClosable(TRUE);
}

