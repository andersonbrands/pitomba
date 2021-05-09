
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "BaseWindow.h"
#include "../EventManager/EventManager.h"
#include <string>


namespace pitomba {
    class MainWindow : public BaseWindow<MainWindow> {
    public:
        explicit MainWindow(std::wstring const& windowTitle) : windowTitle_(windowTitle) {};
        PCWSTR  ClassName() const final { return L"Main Window Class"; }
        PCWSTR  WindowTitle() const final { return windowTitle_.c_str(); }
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) final;

    private:
        std::wstring windowTitle_;
    };

    LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                EventManager::getInstancePtr()->sendEvent(ev::id::APPLICATION_QUIT);
                return 0;
            case WM_SHOWWINDOW:
                return 0;
            default:
                return DefWindowProc(Window(), uMsg, wParam, lParam);
        }
        return TRUE;
    }
}

#endif // MAIN_WINDOW_H_
