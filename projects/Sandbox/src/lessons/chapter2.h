#pragma once
#include <sb6.h>
#include <core/lesson.h>

enum class RenderOptionE
{
    POINT,
    TRIANGLE
};

class Chapter2 : public Lesson
{
    public:
    virtual ~Chapter2() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
    RenderOptionE m_option;
};