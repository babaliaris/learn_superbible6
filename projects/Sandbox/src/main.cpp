#include <sb6.h>
#include <lessons.h>


class Sandbox : public sb6::application
{
    public:
    void render(double currentTime) override
    {
        m_lesson->render(currentTime);
    }
    
    void startup() override
    {
        m_lesson = GetLesson(LessonE::CHAPTER2);

        if (m_lesson != nullptr) m_lesson->startup();
    }

    void shutdown() override
    {
        m_lesson->shutdown();
        delete m_lesson;
    }

    private:
    Lesson *m_lesson;
};


DECLARE_MAIN(Sandbox);