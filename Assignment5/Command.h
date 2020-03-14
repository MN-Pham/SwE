#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>
#include <functional>

class CommandProcessor {
    public:
        using commandfunction_t = std::function<void()>;
        CommandProcessor () = default;
        void addCommand (const std::string &command,
                         commandfunction_t cf);
        void executeCommand (const std::string &command);
    private:
        std::map<std::string, commandfunction_t> commands_{};
};

#endif