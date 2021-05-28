
#include "MainWindow.h"


namespace pitomba {

    LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                pEventManagerLocator_->get()->sendEvent(ev::id::APPLICATION_QUIT);
                PostQuitMessage(0);
                return 0;
            case WM_SHOWWINDOW:
                return 0;
            default:
                return DefWindowProc(Window(), uMsg, wParam, lParam);
        }
        return TRUE;
    }

    bool MainWindow::initialize() {
        if (!Create(WS_OVERLAPPEDWINDOW)) {
            return false;
        }

        return true;
    }

    void MainWindow::start() {
        // Show the window
        ShowWindow(Window(), SW_SHOWDEFAULT);
        UpdateWindow(Window());
    }

    bool MainWindow::update() {
        // Run the message loop.
        MSG msg = { };
        ZeroMemory(&msg, sizeof(msg));

        if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return true;
    }

    HWND MainWindow::getWindow() const {
        return Window();
    }

}
