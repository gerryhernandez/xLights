#ifndef SCHEDULEOPTIONS_H
#define SCHEDULEOPTIONS_H
#include <list>
#include <string>
#include <map>

class wxXmlNode;

class ScheduleOptions
{
	bool _sync;
    bool _dirty;
    bool _sendOffWhenNotRunning;
    bool _runOnMachineStartup;
    int _port;
    std::string _wwwRoot;
    std::map<std::string, std::string> _projectorIPs;
    std::map<std::string, std::string> _projectorPasswords;
    std::map<std::string, std::string> _buttonCommands;
    std::map<std::string, std::string> _buttonParameters;

    public:

        bool IsDirty() const { return _dirty; };
        void ClearDirty() { _dirty = false; };
        ScheduleOptions(wxXmlNode* node);
        ScheduleOptions();
        virtual ~ScheduleOptions();
        wxXmlNode* Save();
		bool IsSync() const { return _sync; }
        void SetSync(bool sync) { _sync = sync; _dirty = true; }
        void SetSendOffWhenNotRunning(bool send) { _sendOffWhenNotRunning = send; _dirty = true; }
        bool IsSendOffWhenNotRunning() const { return _sendOffWhenNotRunning; }
        bool IsRunOnMachineStartup() const { return _runOnMachineStartup; }
        void SetRunOnMachineStartup(bool run) { _runOnMachineStartup = run; _dirty = true; }
        std::list<std::string> GetProjectors() const;
        std::list<std::string> GetButtons() const;
        std::string GetProjectorIpAddress(const std::string& projector);
        std::string GetProjectorPassword(const std::string& projector);
        void ClearProjectors();
        void ClearButtons();
        void SetProjectorIPAddress(const std::string& projector, const std::string& ip);
        void SetProjectorPassword(const std::string& projector, const std::string& ip);
        void SetButtonCommand(const std::string& button, const std::string& command);
        void SetButtonParameter(const std::string& button, const std::string& parameter);
        std::string GetButtonCommand(const std::string& button);
        std::string GetButtonParameter(const std::string& button);
        std::string GetButtonsJSON() const;
        int GetWebServerPort() const { return _port; }
        void SetWebServerPort(int port) { _port = port; _dirty = true; }
        std::string GetWWWRoot() const { return _wwwRoot; }
        void SetWWWRoot(const std::string& wwwRoot) { _wwwRoot = wwwRoot; _dirty = true; }
};

#endif