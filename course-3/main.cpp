#include <iostream>

template <typename TImpl>
class Notifier {
public:
    void AlertSMS(string_view msg) {
        impl().SendAlertSMS(msg);
    }

    void AlertEmail(string_view msg) {
        impl().SendAlertEmail(msg);
    }

private:
    TImpl& impl() { return static_cast<TImpl&>(*this); }
    friend TImpl;
};

template <template TImpl>
void AlertAllChannels(Notifier<TImpl>& notifier, string_view msg) {
    notifier.AlertSMS(msg);
    notifier.AlertEmail(msg);
}

struct TestNotifier : public Notifier<TestNotifier> {
    void SendAlertSMS(string_view msg) {}
    void SendAlertEmail(string_view msg) {}
};

TestNotifier tn;
AlertAllChannels(tn, "testing!");

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
