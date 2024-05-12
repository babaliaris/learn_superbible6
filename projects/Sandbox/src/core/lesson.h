#pragma once

class Lesson
{
    public:
    Lesson(const char *name);
    virtual ~Lesson();

    virtual void render(double currentTime);
    
    virtual void startup();

    virtual void shutdown();

    inline const char *getName() const {return m_name;}

    private:
    const char *m_name;
};
