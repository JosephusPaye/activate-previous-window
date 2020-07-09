#include <Windows.h>

#pragma comment(lib, "user32.lib")

int currentIterationCount = 0;
const BOOL CONTINUE_ENUMERATION = true;
const BOOL STOP_ENUMERATION = false;

BOOL EnumWindowProc(HWND windowHandle, LPARAM lParam) {
  // Don't consider windows that are not visible
  if (!IsWindowVisible(windowHandle)) {
    return CONTINUE_ENUMERATION;
  }

  int windowTitleLength = GetWindowTextLengthA(windowHandle);

  // Consider only windows with a non-empty title
  if (windowTitleLength > 0) {
    currentIterationCount++;

    // EnumWindows() enumerates in z-order. As such, the
    // second visible window with a non-empty title is
    // the previously active top-level window.
    if (currentIterationCount == 2) {
      SetForegroundWindow(windowHandle);
      return STOP_ENUMERATION;
    }
  }

  return CONTINUE_ENUMERATION;
}

void ActivatePreviousWindow() {
  currentIterationCount = 0;
  EnumWindows(EnumWindowProc, 0);
}
