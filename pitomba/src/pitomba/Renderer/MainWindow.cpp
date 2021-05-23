
#include "MainWindow.h"


namespace pitomba {

    LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                pEventManager_->sendEvent(ev::id::APPLICATION_QUIT);
                PostQuitMessage(0);
                return 0;
            case WM_SHOWWINDOW:
                return 0;
            default:
                return DefWindowProc(Window(), uMsg, wParam, lParam);
        }
        return TRUE;
    }

}
