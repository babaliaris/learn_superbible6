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
        m_lesson = GetLesson(LessonE::CHAPTER3_PASSING_DATA_FROM_STAGE_TO_STAGE);

        if (m_lesson != nullptr)
        {
            printf("Loading Lesson: \"%s\"\n", m_lesson->getName());
            m_lesson->startup();
        }
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