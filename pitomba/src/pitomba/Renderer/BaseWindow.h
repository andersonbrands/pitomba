
#ifndef BASE_WINDOW_H_
#define BASE_WINDOW_H_

#include <Windows.h>

namespace pitomba {

    template <class DERIVED_TYPE>
    class BaseWindow {
    public:
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
            DERIVED_TYPE* pThis = NULL;

            if (uMsg == WM_NCCREATE) {
                CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
                pThis = (DERIVED_TYPE*)pCreate->lpCreateParams;
                SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

                pThis->m_hwnd = hwnd;
            } else {
                pThis = (DERIVED_TYPE*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
            }
            if (pThis) {
                return pThis->HandleMessage(uMsg, wParam, lParam);
            } else {
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
            }
        }

        BaseWindow() = default;
        virtual ~BaseWindow() = default;

        BOOL Create(
            DWORD dwStyle,
            DWORD dwExStyle = 0,
            int x = CW_USEDEFAULT,
            int y = CW_USEDEFAULT,
            int nWidth = CW_USEDEFAULT,
            int nHeight = CW_USEDEFAULT,
            HWND hWndParent = nullptr,
            HMENU hMenu = nullptr
        ) {
            wc.lpfnWndProc = DERIVED_TYPE::WindowProc;
            wc.hInstance = GetModuleHandle(NULL);
            wc.lpszClassName = ClassName();

            RegisterClass(&wc);

            m_hwnd = CreateWindowEx(
                dwExStyle, ClassName(), WindowTitle(), dwStyle, x, y,
                nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
            );

            return (m_hwnd ? TRUE : FALSE);
        }

        HWND Window() const { return m_hwnd; }

        HINSTANCE getHInst() const {
            return wc.hInstance;
        }

    protected:

        virtual PCWSTR  ClassName() const = 0;
        virtual PCWSTR  WindowTitle() const = 0;
        virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

    private:
        HWND m_hwnd = nullptr;
        WNDCLASS wc = { 0 };
    };
}

#endif // BASE_WINDOW_H_
