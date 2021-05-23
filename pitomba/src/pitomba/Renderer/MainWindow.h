
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "BaseWindow.h"
#include "../EventManager/iEventManager.h"
#include <string>
#include <memory>
#include "../Utils/ServiceLocator.h"


namespace pitomba {
    class MainWindow : public BaseWindow<MainWindow> {
    public:
        explicit MainWindow(std::wstring const& windowTitle) : windowTitle_(windowTitle) {};
        PCWSTR  ClassName() const final { return L"Main Window Class"; }
        PCWSTR  WindowTitle() const final { return windowTitle_.c_str(); }
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) final;

    private:
        std::wstring windowTitle_;
        std::shared_ptr<iEventManager> pEventManager_ = ServiceLocator::getEventManager();
    };
}

#endif // MAIN_WINDOW_H_
