#pragma once
#include <sb6.h>
#include <core/lesson.h>

class Chapter3_Interpolation : public Lesson
{
    public:
    Chapter3_Interpolation();
    
    virtual ~Chapter3_Interpolation() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
};