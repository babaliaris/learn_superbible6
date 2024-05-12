#pragma once
#include <sb6.h>
#include <core/lesson.h>

class Chapter3_FragmentShader : public Lesson
{
    public:
    Chapter3_FragmentShader();
    
    virtual ~Chapter3_FragmentShader() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
};