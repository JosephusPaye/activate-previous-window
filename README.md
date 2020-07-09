# Activate Previous Window

A native Node.js module for switching to the previously active window on Windows. It programatically replicates what happens when you quickly press and release <kbd>Alt</kbd>+<kbd>Tab</kbd>.

## Installation

```
npm install JosephusPaye/activate-previous-window --save
```

## How it works

The module follows the [approach taken here](https://stackoverflow.com/a/13660585). That means it:

- Enumerates top-level windows in z-order using [EnumWindows()](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-enumwindows).
- Chooses the second window that is visible and has a non-empty title. This is assumes that the topmost (first) window in z-order is the currently active window, and the second window below that is the previously active window.
- Switches to the chosen window using [SetForegroundWindow()](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setforegroundwindow).

## Alternative approaches

I tried a few other approaches that didn't work:

- Simulating <kdb>Alt+Tab</kbd> using [SendInput()](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendinput). This led to a flicker where the Alt Tab switcher was visible briefly before the active window was switched.
- Using [GetWindow()](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindow) to get the previous window in Z-order, instead of `EnumWindows()`. This required getting the handle of the current active window, and had problems redirecting focus when switching. Using `SetForegroundWindow()`, the window switched to would come to the top, but won't have keyboard focus.
