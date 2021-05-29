
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "BaseWindow.h"

#include "iWindowProvider.h"
#include "../EventManager/iEventManager.h"
#include "../Utils/iLocator.h"

#include <string>


namespace pitomba {
    class MainWindow : public BaseWindow<MainWindow>, public iWindowProvider {
    public:
        explicit MainWindow(std::wstring const& windowTitle, iLocator<iEventManager>* pEventManagerLocator) :
            windowTitle_(windowTitle),
            pEventManagerLocator_(pEventManagerLocator) {};
        PCWSTR  ClassName() const final { return L"Main Window Class"; }
        PCWSTR  WindowTitle() const final { return windowTitle_.c_str(); }
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) final;

        bool initialize();
        void start();
        bool update();

    private:
        std::wstring windowTitle_;
        iLocator<iEventManager>* pEventManagerLocator_;

        // Inherited via iWindowProvider
        HWND getWindow() const override;
    };
}

#endif // MAIN_WINDOW_H_
