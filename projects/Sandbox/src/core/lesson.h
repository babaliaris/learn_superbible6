#pragma once

class Lesson
{
    public:
    Lesson();
    virtual ~Lesson();

    virtual void render(double currentTime);
    
    virtual void startup();

    virtual void shutdown();

    private:
};
