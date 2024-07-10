#include <iostream>

template <IsANotifier TImpl>
concept ISANotifier = requires(TImpl impl)
{
    impl.AlertSMS(string_view{});
    impl.AlertEmail(string_view{});
};

template <IsANotifier TImpl>
void AlertAllChannels(TImpl& impl, string_view msg)
{
    impl.AlertSMS(msg);
    impl.AlertEmail(msg);
}

struct TestNotifier
{
        void AlertSMS(string_view msg);
        void AlertEmail(string_view msg);
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
