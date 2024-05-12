#pragma once
#include <sb6.h>
#include <core/lesson.h>

class Chapter3_PassingDataFromStageToStage : public Lesson
{
    public:
    Chapter3_PassingDataFromStageToStage();
    
    virtual ~Chapter3_PassingDataFromStageToStage() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
};