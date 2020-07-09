const { join } = require('path');
const { execFile } = require('child_process');
const { activatePreviousWindow } = require('bindings')('activatePreviousWindow');

module.exports = {
    activatePreviousWindow,
    activatePreviousWindowInChildProcess() {
        execFile(join(__dirname, 'bin', 'activate-previous-window.exe'), {
            windowsHide: true,
            timeout: 2000,
        });
    }
};
