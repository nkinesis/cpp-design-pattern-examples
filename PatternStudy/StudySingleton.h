#pragma once

// Pattern studies: singleton

class Engine
{
protected:

    // a static attribute to hold the single instance to be created
    static Engine* singleton_;

    // a name attribute, which is here just for us to check if the singleton is working
    // we can call "getInstance" using different names, if it's working only the first name informed will "stay"
    std::string name_;

    // constructor is private to prevent direct construction calls
    Engine(const std::string name)
    {
        name_ = name;
    }

public:

    /**
     * Singletons should not be cloneable.
     */
    Engine(Engine& other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const Engine&) = delete;

    /**
     * This method will create an instance of this class or reuse an existing one
     */
    static Engine* getInstance(const std::string& value);

    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    void runGameLoop()
    {
        std::cout << "Run game logic \n";
    }

    std::string getName() const {
        return name_;
    }
};

Engine* Engine::singleton_ = nullptr;;

/**
 * Static methods should be defined outside the class.
 * If you try to do it inside the class, there will be compiler/linker errors
 */
Engine* Engine::getInstance(const std::string& name)
{
    // create new instance if there is none, otherwise reuse existing one
    if (singleton_ == nullptr) {
        singleton_ = new Engine(name);
    }
    return singleton_;
}

