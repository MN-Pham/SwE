#include <string>

/// The class Device is an abstract base class containing all
/// basic device interface functions.
/// This abstract class cannot be instantiated, because this type of
/// classes contains a least one abstract member function.
class Device {
    public:
        //Make Device not copy-able
        Device &operator=(const Device &other) = delete;
        Device (const Device &other) = delete;
        Device(const std::string &id);
        virtual ~Device() = default;
        const std::string &getID() const;
        /// Abstract functions, must be implemented in the derived classes.
        virtual void initialise() = 0;
        virtual void reset() = 0;
        virtual void shutdown() = 0;
    private:
        const std::string ID_;
};

///The class Motor is_a Device
class Motor: public Device {
    public:
        Motor(const std::string &id);
        virtual ~Motor();

        void initialise() override; //C++11 override specifier
        void reset() override;
        void shutdown() override;

        void setSpeed(double speed);
        double getSpeed() const;

    private:
        double speed_;
};