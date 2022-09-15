//
// Created by Sam on 15/09/2022.
//

#ifndef SPOOK_WINDOW_H
#define SPOOK_WINDOW_H

class Window {

public:
    static Window &get();

    [[nodiscard]] void* getNativeWindow() const;

private:
    Window();
    ~Window();
    bool initialiseWindow();

    void *window;

    static Window *instance;
    friend int main();
};


#endif //SPOOK_WINDOW_H
